//
// TSHashObject.hpp - template TSHashObject
//

#pragma once

#include "TSLink.hpp"

template<typename T, typename U>
class TSHashObject
{
private:
    unsigned int m_hashval;
    TSLink<T>    m_linktoslot;
    TSLink<T>    m_linktofull;
    U            m_key;

public:
    TSHashObject<T,U>() 
    {
        return;
    }

    ~TSHashObject<T,U>() 
    {
        return;
    }

    
    TSHashObject<T,U>(TSHashObject<T,U>&) 
    {
        return;
    }

    TSHashObject<T,U>& operator=(TSHashObject<T,U>&) 
    {
        return this;
    }

    
    U GetKey() 
    {
        return m_key;
    }

    void* GetData() 
    {
        return nullptr;
    }

    char* GetString() 
    {
        return nullptr;
    }

    unsigned int  GetHashValue() 
    {
        return m_hashval;
    }

};
