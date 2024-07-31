//
// TSBaseArray.hpp - template TSBaseArray
//

#pragma once

template<typename T>
class TSBaseArray
{
protected:
    unsigned int m_alloc;
    unsigned int m_count;
    T* m_data;


    void Constructor();
    void CheckArrayBounds(unsigned int index);


public:
    TSBaseArray<T>();
    TSBaseArray<T>(const TSBaseArray<T>& source);
    TSBaseArray<T>& operator=(const TSBaseArray<T>& source);
    T& operator[](const unsigned int index);
    const T& operator[](const unsigned int index) const;


    T* Ptr();
    T* Top();
    const T* Ptr() const;
    const T* Top() const;


    unsigned int Count();
    unsigned int Bytes();
    unsigned int SizeOfElement();
    unsigned int NumElements();

    // virtual functions ------------- for wowae only -----------------
    virtual char* MemFileName();
    virtual int  MemLineNo();

};
