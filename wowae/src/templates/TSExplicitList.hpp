//
// TSExplicitList.hpp - template TSExplicitList
//

#pragma once

#include "TSList.hpp"

template<typename T, int iP>
class TSExplicitList : public TSList<T, TSGetExplicitLink<T> >  
{
public:
    TSExplicitList<T, iP>() 
    {
        return;
    }

    ~TSExplicitList<T, iP>() 
    {
        return;
    }
    

    TSExplicitList<T,iP>(const TSExplicitList<T, iP>& source) 
    {
        return;
    }

    TSExplicitList<T,iP>& operator=(const TSExplicitList<T, iP>& source) 
    { 
        return this; 
    }

};

