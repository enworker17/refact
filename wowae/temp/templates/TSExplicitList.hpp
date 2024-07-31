//
// TSExplicitList.hpp - template TSExplicitList
//

#pragma once

#include "TSList.hpp"

template<typename T, int iP>
class TSExplicitList : public TSList<T, TSGetExplicitLink<T> >
{
public:
    TSExplicitList<T, iP>();
    ~TSExplicitList<T, iP>();

    TSExplicitList<T, iP>(const TSExplicitList<T, iP>& source);
    TSExplicitList<T, iP>& operator=(const TSExplicitList<T, iP>& source);

};

