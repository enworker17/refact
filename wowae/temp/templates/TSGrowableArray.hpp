//
// TSGrowableArray.hpp - template TSGrowableArray
//

#pragma once

#include "TSFixedArray.hpp"

template<typename T>
class TSGrowableArray : public TSFixedArray<T>   // TODO: разобраться
{
private:
    unsigned int m_chunk;


public:
    TSGrowableArray<T>();
    ~TSGrowableArray<T>();

    TSGrowableArray<T>(TSGrowableArray<T>& source);
    TSGrowableArray<T>& operator=(TSGrowableArray<T>& source);

    T* New(T& data);
    T* New();
    T* NewElement();
    unsigned int Add(T* data);
    unsigned int Add(unsigned int count, int index, T* data);
    unsigned int Add(unsigned int count, T* data);
    unsigned int AddElement(T* data);
    unsigned int AddElements(unsigned int count, T* data);
    unsigned int Reserved();
    unsigned int CalcChunkSize(unsigned int count);
    unsigned int RoundToChunk(unsigned int count, unsigned int chunk);
    void Reserve(unsigned int count, int round);
    void GrowToFit(unsigned int count, int size);
    void ReserveSpace(unsigned int size);
    void SetChunkSize(unsigned int size);
    void SetCount(unsigned int count);
    void TrimUnusedSpace();
    void SetNumElements(unsigned int size);

    // virtual functions ------------- for wowae only -----------------
    virtual char* MemFileName();
    virtual int  MemLineNo();

};

