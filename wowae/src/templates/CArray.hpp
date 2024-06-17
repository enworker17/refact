//
// CArray.hpp - template CArray
//

#pragma once

#include "TSGrowableArray.hpp"

template<typename T>
class CArray
{
private:
    T*           m_data;
    unsigned int m_count;

public:
    CArray<T>() 
    {
        return;
    }

    ~CArray<T>() 
    {
        return;
    }

    
    CArray<T>(const CArray<T>& source) 
    {
        return;
    }

    CArray<T>& operator=(const TSFixedArray<T>& source) 
    {
        return this;
    }

    CArray<T>& operator=(const CArray<T>& source) 
    {
        return this;
    }

    T& operator[](unsigned int index) 
    {
        return m_data[index];
    }

    // const T& operator[](unsigned int index) { return m_data[index]; }
    

    T* New() 
    {
        return nullptr;
    }

    T* Ptr() 
    {
        return m_data;
    }
    
    // const T* Ptr() { return m_data; }


    void Exchange(TSGrowableArray<T>* pArray) 
    {
        return;
    }

    void ReserveSpace(unsigned int elements) 
    {
        return;
    }

    void Zero() 
    {
        return;
    }

    unsigned int Count() 
    {
        return m_count;
    }

    unsigned int Bytes() 
    {
        return (m_count * sizeof(T));
    }
    
    void Clear() 
    {
        return;
    }

    void SetCount(unsigned int count) 
    {
        return;
    }

    void Set(unsigned int index, T* source) 
    {
        return;
    }


};

