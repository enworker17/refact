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
    T*           m_data;


    void FatalArrayBounds() 
    {
        return;
    }
  

  
public:
    TSStackArray<T>(void* ptr, unsigned int maxCount, int count) 
    {
        return;
    }

    ~TSStackArray<T>() 
    {
        return;
    }
    

    TSStackArray<T>& operator=(const TSStackArray<T>& source) 
    {
        return this; 
    }

    T& operator[](const unsigned int index) 
    {
        return m_data[index]; 
    }

    //const T& operator[](const unsigned int index) { return m_data[index]; }
    

    T* New(const T& source) 
    {
        return nullptr; 
    }

    T* New() 
    {
        return nullptr; 
    }

    T* Ptr() 
    { 
        return nullptr; 
    }

    //const T* Ptr() { return nullptr; }
    

    void Zero() 
    {
        return;
    }

    void SetCount(unsigned int count) 
    {
        return;
    }

    unsigned int Count() 
    {
        return m_count;
    }

    unsigned int Bytes() 
    {
        return (m_maxCount * sizeof(T));
    }

    unsigned int SizeOfElement() 
    {
        return sizeof(T);
    }

    
    void Set(unsigned int count, int index, T* source) 
    {
        return;
    }

    void Set(unsigned int count, T* source) 
    {
        return;
    }

    void Add(unsigned int count, int index, T* source) 
    {
        return;
    }

    void Add(unsigned int count, T* source) 
    {
        return;
    }

};

