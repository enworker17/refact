//
// TSGetExplicitLink.hpp - temlate TSGetExplicitLink
//

#pragma once

#include "TSLink.hpp"

template<typename T>
class TSGetExplicitLink
{
public:
    inline static TSLink<T>* __fastcall Link(void const* nodePtr, iPtr linkOffset)
    {
        return static_cast<TSLink<T>*>((iPtr)nodePtr + linkOffset);
    }
};

