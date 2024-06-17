//
// TSListWinHeap.hpp - template TSListWinHeap
//

#pragma once

#include "TSGetLink.hpp"
#include "TSList.hpp"

template<typename T, typename GetLink = TSGetLink<T> >
class TSListWinHeap : public TSList<T, GetLink> 
{
public:
    TSListWinHeap<T, GetLink>() 
    {
        return;
    }

    ~TSListWinHeap<T, GetLink>() 
    {
        return;
    }

    
    TSListWinHeap<T, GetLink>(const TSListWinHeap<T, GetLink>& source) 
    {
        return;
    }

    TSListWinHeap<T, GetLink>& operator=(const TSListWinHeap<T, GetLink>& source) 
    { 
        return this; 
    }

    
    T* NewNode(unsigned long location, unsigned long extrabytes, unsigned long flags) 
    { 
        return nullptr; 
    }

    T* DeleteNode(T* ptr) 
    { 
        return nullptr; 
    }

};

