//
// TSGrowableArray_.hpp - template TSGrowableArray_
//

#pragma once

#include "TSGrowableArray.hpp"

template<typename T, typename U, typename W>       // TODO: разобраться с U и W
class TSGrowableArray_ : public TSGrowableArray<T>  
{
private:
    static char s_name[5];

public:
    TSGrowableArray_<T, U, W>() 
    {
        return;
    }

    ~TSGrowableArray_<T, U, W>() 
    {
        return;
    }

    
    TSGrowableArray_<T, U, W>(const TSGrowableArray_<T, U, W>& source) 
    {
        return;
    }

    TSGrowableArray_<T, U, W>& operator=(const TSGrowableArray_<T, U, W>& source) 
    {
        return this;
    }
    
    TSGrowableArray_<T, U, W>& operator=(const TSGrowableArray<T>& source) 
    {
        return this;
    }
    

    // virtual functions ------------- for wowae only -----------------
    // virtual char*  MemFileName();
    // virtual int  MemLineNo();

};

