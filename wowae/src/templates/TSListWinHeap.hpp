//
// TSListWinHeap.hpp - template TSListWinHeap
//

#pragma once

#include <memory.h>

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

    T* NewNode(u32 location, u32 extrabytes, u32 flags);
    T* DeleteNode(T* ptr);

};

// Implementation
/////////////////////////////////////////////////

template <typename T, typename GetLink>
inline TSListWinHeap<T, GetLink>::TSListWinHeap()
{
    return;
}

template <typename T, typename GetLink>
inline TSListWinHeap<T, GetLink>::~TSListWinHeap()
{
    return;
}

template <typename T, typename GetLink>
inline TSListWinHeap<T, GetLink>::TSListWinHeap(const TSListWinHeap<T, GetLink> &source)
{
    this->m_linkoffset = source.m_linkoffset;
    this->m_terminator = source.m_terminator;
}

template <typename T, typename GetLink>
inline TSListWinHeap<T, GetLink> &TSListWinHeap<T, GetLink>::operator=(const TSListWinHeap<T, GetLink> &source)
{
    this->m_linkoffset = source.m_linkoffset;
    this->m_terminator = source.m_terminator;
    return this;
}

template <typename T, typename GetLink>
inline T* TSListWinHeap<T, GetLink>::NewNode(u32 location, u32 extrabytes, u32 flags)
{
    /*
    {
        HANDLE ProcessHeap; // eax
        void *v6; // eax
        T *v7; // eax
        T *v8; // eax
        T *v9; // esi

        ProcessHeap = GetProcessHeap();
        v6 = HeapAlloc(ProcessHeap, 4u, extrabytes + 12);
        v7 = (T *)operator new(0xCu, v6);
        if ( v7 )
        {
            T::T(v7);
            v9 = v8;
        }
        else
        {
            v9 = 0;
        }
        memset(v9, 0, extrabytes + 12);
        if ( location )
            TSList<T,TSGetLink<T>>::LinkNode(this, v9, location, 0);
        return v9;
    }
    */

    // TODO: переписать под выделение памяти на куче
    T* obj = new T;
    memset(obj, 0, (extrabytes + sizeof(T)));
    if (location) 
    {
        LinkNode(obj, location, 0);
    }
    return obj;
}

template <typename T, typename GetLink>
inline T* TSListWinHeap<T, GetLink>::DeleteNode(T* ptr)
{
    T* obj = Next(ptr);

    // TODO: соглосовать освобождение памяти с NewNode() после перезаписи
    delete ptr;

    return obj;
}