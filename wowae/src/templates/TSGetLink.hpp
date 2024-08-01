//
// TSGetLink.hpp - template TSGetLink
//

#pragma once

#include "TSLinkedNode.hpp"

template<typename T>
class TSGetLink
{
public:
    inline static TSLink<T>* __fastcall Link(TSLinkedNode<T> const* nodePtr, iPtr linkOffset)
    {
        return static_cast<TSLink<T>*>(nodePtr);
    }
};
