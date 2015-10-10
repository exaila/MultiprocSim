#include "cacheblock.h"

CacheBlock::CacheBlock()
{
}

CacheBlock::CacheBlock(int data, int tag, bool valid)
{
    this->data = data;
    this->tag = tag;
    this->valid = valid;
}

bool CacheBlock::Valid()
{
    return valid;
}

int CacheBlock::Tag()
{
    return tag;
}

int CacheBlock::Data()
{
    return data;
}

