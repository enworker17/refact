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
    T*           m_data;


    void Constructor() 
    {
        return;
    }

    void CheckArrayBounds(unsigned int index) 
    {
        return;
    }



public:  
    TSBaseArray<T>() 
    {
        return;
    }
    

    TSBaseArray<T>(const TSBaseArray<T>& source) 
    {
        return;
    }

    TSBaseArray<T>& operator=(const TSBaseArray<T>& source) 
    {
        return this;
    }

    T& operator[](const unsigned int index) 
    {
        return m_data[index];
    }

    // const T& operator[](const unsigned int index) { return m_data[index]; }
    

    T* Ptr() 
    {
        return nullptr;
    }

    T* Top() 
    {
        return nullptr;
    }

    // const T* Ptr() { return nullptr; }
    // const T* Top() { return nullptr; }
    

    unsigned int Count() 
    {
        return m_count;
    }

    unsigned int Bytes() 
    {
        return (m_alloc * sizeof(T));
    }

    unsigned int SizeOfElement() 
    {
        return sizeof(T);
    }

    unsigned int NumElements() 
    {
        return m_alloc;
    }


    // virtual functions ------------- for wowae only -----------------
    // virtual char*  MemFileName() { return nullptr; }
    // virtual int  MemLineNo() { return 0; }
};

