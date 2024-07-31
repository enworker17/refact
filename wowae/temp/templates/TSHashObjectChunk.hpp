//
// TSHashObjectChunk.hpp - template TSHashObjectChunk
//

#pragma once

#include "TSLink.hpp"
#include "TSGrowableArray.hpp"

template<typename T, typename U>
class TSHashObjectChunk
{
private:
    TSGrowableArray<T>               m_array;
    TSLink<TSHashObjectChunk<T, U> >  m_link;

public:
    TSHashObjectChunk<T, U>();
    ~TSHashObjectChunk<T, U>();

    TSHashObjectChunk<T, U>(const TSHashObjectChunk<T, U>& source);
    TSHashObjectChunk<T, U>& operator=(const TSHashObjectChunk<T, U>& source);

};

