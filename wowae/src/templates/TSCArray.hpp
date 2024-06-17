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


    void FatalArrayBounds() 
    {
        return;
    }
  

  
public:  
    TSCArray<T, Size>() 
    {
        return;
    }

    ~TSCArray<T, Size>() 
    {
        return;
    }

    
    TSCArray<T, Size>(const TSCArray<T, Size>& source) 
    {
        return;
    }

    TSCArray<T, Size>& operator=(const TSCArray<T, Size>& source) 
    {
        return this;
    }

    T& operator[](const unsigned int index) 
    {
        return m_data[index];
    }

    //const T& operator[](const unsigned int index);
    

    T* Ptr() 
    {
        return nullptr;
    }

    // const T* Ptr();
    

    void Set(unsigned int count, int index, T* source) 
    {
        return;
    }

    void Set(unsigned int count, T* source) 
    {
        return;
    }

    void SetCount(unsigned int count) 
    {
        return;
    }

    void Zero() 
    {
        return;
    }

    
    unsigned int MaxCount() 
    {
        return Size;
    }

    unsigned int Count() 
    {
        return m_count;
    }

    unsigned int Bytes() 
    {
        return sizeof(m_data);
    }

    unsigned int SizeOfElement() 
    {
        return sizeof(T);
    }

    
    // virtual functions ------------- for wowae only debug -----------------
    // char* MemFileName() { }	??
    // int MemLineNo() { }		??

};

