//
// TSStackArray.hpp - template TSStackArray
//

#pragma once

#include "../defines.hpp"

template<typename T>
class TSStackArray
{
    // function
public:
    TSStackArray<T>(void* ptr, u32 maxCount, i32 count);
    ~TSStackArray<T>();

    TSStackArray<T>& operator=(const TSStackArray<T>& source);
    T& operator[](const u32 index);
    const T& operator[](const u32 index) const;

    T* New(const T& source);
    T* New();
    T* Ptr();
    const T* Ptr() const;

    void Zero();
    void SetCount(u32 count);
    u32 Count();
    u32 Bytes();
    u32 SizeOfElement();
    void Set(u32 count, i32 index, T* source);
    void Set(u32 count, T* source);
    void Add(u32 count, i32 index, T* source);
    void Add(u32 count, T* source);

private:
    void FatalArrayBounds();


    // members
private:
    u32 m_maxCount;
    u32 m_count;
    T*  m_data;

};

// Implementation
/////////////////////////////////////////////////

template <typename T>
inline TSStackArray<T>::TSStackArray(void *ptr, u32 maxCount, i32 count) :
    m_maxCount(maxCount),
    m_count(count),
    m_data(ptr)
{
    return;
}

template <typename T>
inline TSStackArray<T>::~TSStackArray()
{
    return;
}
