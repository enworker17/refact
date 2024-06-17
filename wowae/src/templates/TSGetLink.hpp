//
// TSGetLink.hpp - template TSGetLink
//

#pragma once

#include "TSLinkedNode.hpp"

template<typename T>
class TSGetLink
{
public:
    static TSLink<T>* /*__fastcall */ Link(TSLinkedNode<T>* nodeptr, int linkoffset) 
    {
        return nullptr;
    }

};
