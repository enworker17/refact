//
// TSGetExplicitLink.hpp - temlate TSGetExplicitLink
//

#pragma once

#include "TSLink.hpp"

template<typename T>
class TSGetExplicitLink
{
public:
    static TSLink<T>* /*__fastcall */ Link(void* nodeptr, int linkoffset) 
    {
        return nullptr;
    }

};
