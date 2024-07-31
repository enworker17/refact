//
// TSStackArray.hpp - template TSStackArray
//

#pragma once

template<typename T>
class TSStackArray
{
private:
    unsigned int m_maxCount;
    unsigned int m_count;
    T* m_data;

    void FatalArrayBounds();

public:
    TSStackArray<T>(void* ptr, unsigned int maxCount, int count);
    ~TSStackArray<T>();

    TSStackArray<T>& operator=(const TSStackArray<T>& source);
    T& operator[](const unsigned int index);
    const T& operator[](const unsigned int index) const;

    T* New(const T& source);
    T* New();
    T* Ptr();
    const T* Ptr() const;

    void Zero();
    void SetCount(unsigned int count);
    unsigned int Count();
    unsigned int Bytes();
    unsigned int SizeOfElement();
    void Set(unsigned int count, int index, T* source);
    void Set(unsigned int count, T* source);
    void Add(unsigned int count, int index, T* source);
    void Add(unsigned int count, T* source);

};

