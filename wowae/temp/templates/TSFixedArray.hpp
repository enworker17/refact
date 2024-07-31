//
// TSFixedArray.hpp - template TSFixedArray
//

#pragma once

#include "TSBaseArray.hpp"

template<typename T>
class TSFixedArray : public TSBaseArray<T>
{
public:
    TSFixedArray<T>() 
    {
        return;
    }

    ~TSFixedArray<T>() 
    {
        return;
    }

    
    TSFixedArray<T>(const TSBaseArray<T>& source) 
    {
        return;
    }

    TSFixedArray<T>(const TSFixedArray<T>& source) 
    {
        return;
    }

    TSFixedArray<T>& operator=(const TSBaseArray<T>& source) 
    {
        return this;
    }

    TSFixedArray<T>& operator=(const TSFixedArray<T>& source) 
    {
        return this;
    }

    
    void ReallocAndClearData(unsigned int maxCount) 
    {
        return;
    }
    
    void ReallocData(unsigned int maxCount) 
    {
        return;
    }
    
    void Clear() 
    {
        return;
    }
    
    void Detach(T**, unsigned int*, unsigned int*) 
    {
        return;
    }
    
    void Exchange(TSFixedArray<T>* source) 
    {
        return;
    }
    
    void Set(unsigned int count, int index, T* data) 
    {
        return;
    }
    
    void Set(unsigned int count, T* data) 
    {
        return;
    }
    
    void SetCount(unsigned int count) 
    {
        return;
    }
    
    void SetOptional(unsigned int index, T* data) 
    {
        return;
    }
    
    void Zero() 
    {
        return;
    }
    

    // virtual functions ------------- for wowae only -----------------
    // virtual char*  MemFileName();
    // virtual int  MemLineNo();
};

