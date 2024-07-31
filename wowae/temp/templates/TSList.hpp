//
// TSList.hpp - template TSList
//

#pragma once

#include "TSGetExplicitLink.hpp"

template<typename T, typename GetLink = TSGetExplicitLink<T> >
class TSList
{
private:
    int       m_linkoffset;
    TSLink<T> m_terminator;


    void Constructor();
    void CopyConstructor(TSList<T, GetLink>& source);
    void InitializeTerminator();

public:
    TSList<T, GetLink>();
    ~TSList<T, GetLink>();

    TSList<T, GetLink>(int linkoffset);
    TSList<T, GetLink>(const TSList<T, GetLink>& source);
    TSList<T, GetLink>& operator=(const TSList<T, GetLink>& source);

    void SetLinkOffset(int linkoffset);
    void ChangeLinkOffset(int linkoffset);
    void Clear();
    void Combine(TSList<T, GetLink>* list, unsigned long linktype, T* existingptr);
    bool IsEmpty();
    bool IsLinked(T* ptr);

    TSLink<T>* Link(T* ptr);
    void LinkNode(T* ptr, unsigned long linktype, T* existingptr);
    void UnlinkNode(T* ptr);
    void UnlinkAll();
    T* NewNode(unsigned long location, unsigned long extrabytes, unsigned long flags);
    T* DeleteNode(T* ptr);

    T* Next(T* ptr);
    T* Prev(T* ptr);
    T* RawNext(T* ptr);
    T* Head();
    T* Tail();

    const T* Next(T* ptr) const;
    const T* Prev(T* ptr) const;
    const T* RawNext(T* ptr) const;
    const T* Head() const;
    const T* Tail() const;

};
