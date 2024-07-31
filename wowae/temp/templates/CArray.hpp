//
// CArray.hpp - template CArray
//

#pragma once

#include "TSGrowableArray.hpp"

template<typename T>
class CArray
{
private:
    T* m_data;
    unsigned int m_count;

public:
    CArray<T>();
    ~CArray<T>();

    CArray<T>(const CArray<T>& obj);
    CArray<T>& operator=(const TSFixedArray<T>& obj);
    CArray<T>& operator=(const CArray<T>& obj);
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;


    T* New();
    T* Ptr();
    const T* Ptr() const;


    void Exchange(TSGrowableArray<T>* pArray);
    void ReserveSpace(unsigned int elements);
    void Zero();
    unsigned int Count();
    unsigned int Bytes();
    void Clear();
    void SetCount(unsigned int count);
    void Set(unsigned int index, T* source);

};

