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
    TSGrowableArray<T>() 
    {
        return;
    }

    ~TSGrowableArray<T>() 
    {
        return;
    }

    
    TSGrowableArray<T>(TSGrowableArray<T>& source) 
    {
        return;
    }

    TSGrowableArray<T>& operator=(TSGrowableArray<T>& source) 
    {
        return this;
    }

    
    T* New(T& data) 
    {
        return nullptr;
    }

    T* New() 
    {
        return nullptr;
    }

    T* NewElement() 
    {
        return nullptr;
    }

    
    unsigned int Add(T* data) 
    {
        return 0;
    }

    unsigned int Add(unsigned int count, int index, T* data) 
    {
        return 0;
    }

    unsigned int Add(unsigned int count, T* data) 
    {
        return 0;
    }

    unsigned int AddElement(T* data) 
    {
        return 0;
    }

    unsigned int AddElements(unsigned int count, T* data) 
    {
        return 0;
    }

    unsigned int Reserved() 
    {
        return 0;
    }

    unsigned int CalcChunkSize(unsigned int count) 
    {
        return 0;
    }

    unsigned int RoundToChunk(unsigned int count, unsigned int chunk) 
    {
        return 0;
    }


    void Reserve(unsigned int count, int round) 
    {
        return;
    }

    void GrowToFit(unsigned int count, int size) 
    {
        return;
    }

    void ReserveSpace(unsigned int size) 
    {
        return;
    }

    void SetChunkSize(unsigned int size) 
    {
        return;
    }

    void SetCount(unsigned int count) 
    {
        return;
    }

    void TrimUnusedSpace() 
    {
        return;
    }

    void SetNumElements(unsigned int size) 
    {
        return;
    }


    // virtual functions ------------- for wowae only -----------------
    // virtual char*  MemFileName();
    // virtual int  MemLineNo();

};

