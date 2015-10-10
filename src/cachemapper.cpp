#include <QVariant>
#include "helper.h"

#include "cachemapper.h"
#include "Cache.h"
#include "ram.h"

CacheMapper::CacheMapper(Cache* cache,Ram *ram, int cacheCost, int ramCost,int fetchBlocks)
{
    this->cache = cache;
    this->ram = ram;
    this->cacheCost = cacheCost;
    this->ramCost = ramCost;
    this->fetchBlocks = fetchBlocks;
    this->cacheSize = cache->GetModel()->rowCount();
}

int CacheMapper::GetData(int address,bool transferToCache)
{
    if(transferToCache)
    {
        TransferBlocks(address);
    }

    bool ok;
    QStandardItem* item = ram->GetModel()->item(address, 1);
    return item->data(Qt::DisplayRole).toString().toInt(&ok,2);
}

void CacheMapper::SetRamData(int address,int data)
{
    ram->GetModel()->setItem(address, 1,new QStandardItem(ToBinary(data,8)));
}

void CacheMapper::SetCacheData(int address,int data)
{
    int start,end;
    GetTransferBlocksIndices(address,start,end);

    cache->GetModel()->setItem(start, 3,new QStandardItem(ToBinary(data,8)));
    cache->GetModel()->item(start, 3)->setEnabled(false);
}

bool CacheMapper::IsCacheValid(int address)
{
    int cacheIndex = GetCacheBlock(address);

    if(cache->GetModel()->item( cacheIndex, 1 )->data(Qt::DisplayRole ) == QString("true"))
    {
        bool ok;
        int tag = cache->GetModel()->item( cacheIndex, 2 )->data(Qt::DisplayRole).toString().toInt(&ok,2);
        int shouldBe = address/cacheSize;
        return tag == shouldBe;
    }
    else
    {
        return false;
    }
}

void CacheMapper::InvalidateCache()
{
    //set validity
    QVariant invalidFlag( QString("false"));

    for(int i = 0; i < cache->GetModel()->rowCount(); i++)
    {
        cache->GetModel()->item(i,1)->setData( invalidFlag,Qt::DisplayRole );        
    }
}

int CacheMapper::GetCacheBlock(int address)
{
    return address % cacheSize;
}

void CacheMapper::GetTransferBlocksIndices(int startAddress,int &start, int &end)
{
    start = GetCacheBlock(startAddress);
    int possibleEnd = (start + fetchBlocks);
    end = possibleEnd <= cacheSize ? possibleEnd : cacheSize;
}

void CacheMapper::TransferBlocks(int startAddress)
{
    int start = 0;
    int end = 0;
    
    GetTransferBlocksIndices(startAddress,start,end);

    int j = 0;
    for(int i = start; i < end  ; i++,j++)
    {
        TransferToCache(startAddress + j,i);
    }
}

void CacheMapper::PrepareCacheTransfer(int startAddress,bool highlightRam,bool single)
{
    int start = 0;
    int end = 0;
    
    GetTransferBlocksIndices(startAddress,start,end);

    if(single)
    {
        end = start + 1;
    }

    if(highlightRam)
    {
        HighlightRows(cache->GetModel(),start,end,QColor(200,120,120));
        HighlightRows(ram->GetModel(),startAddress,startAddress + end - start,QColor(120,200,120));
    }
    else
    {
        HighlightRows(cache->GetModel(),start,start +1,QColor(120,200,120));
    }
}

void CacheMapper::EndCacheTransfer(int startAddress,bool highlightRam,bool single)
{
    int start = 0;
    int end = 0;
    
    GetTransferBlocksIndices(startAddress,start,end);

    if(single)
    {
        end = start + 1;
    }

    if(highlightRam)
    {
        HighlightRows(cache->GetModel(),start,end,QColor(255,255,255));
        HighlightRows(ram->GetModel(),startAddress,startAddress + end- start,QColor(255,255,255));
    }
    else
    {
        HighlightRows(cache->GetModel(),start,start + 1,QColor(255,255,255));
    }
}

void CacheMapper::TransferToCache(int address,int cacheIndex)
{
    const int ramIndex = address;
    QStandardItem* item = ram->GetModel()->item( ramIndex,1 );
    QVariant dataHolder = item->data(Qt::DisplayRole);

    bool ok;
    dataHolder.toInt(&ok);

    //set validity
    QVariant variant3( QString("true"));
    cache->GetModel()->item(cacheIndex,1)->setData( variant3,Qt::DisplayRole );

    //set tag
    QVariant variant2( GetTag(address));
    cache->GetModel()->item( cacheIndex, 2 )->setData( variant2,Qt::DisplayRole );

    if(ok)
    {
        //set data
        QVariant variant1( dataHolder.toString() );
        cache->GetModel()->item(cacheIndex,3)->setData( variant1,Qt::DisplayRole );
    }
    else
    {
        //set data
        QVariant variant1("Invalid Data" );
        cache->GetModel()->item(cacheIndex,3)->setData( variant1,Qt::DisplayRole );
    }

}

int CacheMapper::GetCacheCost() const
{
    return cacheCost;
}

void CacheMapper::SetCacheCost(int value)
{
    cacheCost = value;
}

int CacheMapper::GetRamCost() const
{
    return ramCost;
}

void CacheMapper::SetRamCost(int value)
{
    ramCost = value;
}

QString CacheMapper::GetTag(int address)
{
    return ToBinary(address / cacheSize,6 - log2(cacheSize));
}
