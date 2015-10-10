#ifndef CACHEBLOCK_H
#define CACHEBLOCK_H

class CacheBlock
{
public:

    CacheBlock();
    
    CacheBlock(int data,int tag,bool valid);
    
    //properties
    bool Valid();
    
    int Tag();
    
    int Data();
    
private:
    
    int tag;
    int data;
    bool valid;
};

#endif // CACHEBLOCK_H
