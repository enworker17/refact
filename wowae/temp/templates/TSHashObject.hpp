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
    TSHashObject<T, U>();
    ~TSHashObject<T, U>();

    TSHashObject<T, U>(TSHashObject<T, U>&);
    TSHashObject<T, U>& operator=(TSHashObject<T, U>&);

    U GetKey();
    void* GetData();
    char* GetString();
    unsigned int  GetHashValue();

};
