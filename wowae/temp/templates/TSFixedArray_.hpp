//
// TSFixedArray_.hpp - template TSFixedArray_
//

#pragma once

#include "TSFixedArray.hpp"


template<typename T, typename U, typename W> // TODO: разобраться с числами U и W. Возможно не typename, а size_t или uint.
class TSFixedArray_ : public TSFixedArray<T>
{
private:
    static char s_name[5];

public:
    TSFixedArray_<T, U, W>();
    ~TSFixedArray_<T, U, W>();

    TSFixedArray_<T, U, W>(TSFixedArray_<T, U, W>& source);
    TSFixedArray_<T, U, W>& operator=(const TSFixedArray_<T, U, W>& source);
    TSFixedArray_<T, U, W>& operator=(const TSFixedArray<T>& source);

    // virtual functions ------------- for wowae only -----------------
    virtual char* MemFileName();
    virtual int  MemLineNo();
};

