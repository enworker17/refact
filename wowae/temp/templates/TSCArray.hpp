//
// TSCArray - template TSCArray
//

#pragma once

template<typename T, size_t Size>
class TSCArray
{
protected:
    unsigned int m_count;
    T            m_data[Size];


    void FatalArrayBounds();


public:
    TSCArray<T, Size>();
    ~TSCArray<T, Size>();


    TSCArray<T, Size>(const TSCArray<T, Size>& source);
    TSCArray<T, Size>& operator=(const TSCArray<T, Size>& source);
    T& operator[](const unsigned int index);
    const T& operator[](const unsigned int index) const;

    T* Ptr();
    const T* Ptr() const;

    void Set(unsigned int count, int index, T* source);
    void Set(unsigned int count, T* source);
    void SetCount(unsigned int count);
    void Zero();
    unsigned int MaxCount();
    unsigned int Count();
    unsigned int Bytes();
    unsigned int SizeOfElement();


    // virtual functions ------------- for wowae only debug -----------------
    char* MemFileName();
    int MemLineNo();

};

