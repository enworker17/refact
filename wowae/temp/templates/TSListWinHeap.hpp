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
    TSListWinHeap<T, GetLink>();
    ~TSListWinHeap<T, GetLink>();

    TSListWinHeap<T, GetLink>(const TSListWinHeap<T, GetLink>& source);
    TSListWinHeap<T, GetLink>& operator=(const TSListWinHeap<T, GetLink>& source);

    T* NewNode(unsigned long location, unsigned long extrabytes, unsigned long flags);
    T* DeleteNode(T* ptr);

};

