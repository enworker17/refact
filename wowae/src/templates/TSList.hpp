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


    void Constructor() 
    {
        return;
    }

    void CopyConstructor(TSList<T, GetLink>& source) 
    {
        return;
    }

    void InitializeTerminator() 
    {
        return;
    }
  

public:
    TSList<T, GetLink>() 
    {
        Constructor(); 
    }

    ~TSList<T, GetLink>() 
    {
        return;
    }
    

    TSList<T, GetLink>(int linkoffset) 
    {
        return;
    } // ????

    TSList<T, GetLink>(const TSList<T, GetLink>& source) 
    {
        CopyConstructor(source);
    }

    TSList<T, GetLink>& operator=(const TSList<T, GetLink>& source) 
    { 
        CopyConstructor(source); 
        return this; 
    }
    

    void SetLinkOffset(int linkoffset) 
    {
        return;
    }

    void ChangeLinkOffset(int linkoffset) 
    {
        return;
    }

    void Clear() 
    {
        return;
    }

    void Combine(TSList<T, GetLink>* list, unsigned long linktype, T* existingptr) 
    {
        return;
    }

    bool IsEmpty() 
    {
        return false; 
    }

    bool IsLinked(T* ptr) 
    {
        return false; 
    }
    

    TSLink<T>* Link(T* ptr) 
    { 
        return nullptr; 
    }

    void LinkNode(T* ptr, unsigned long linktype, T* existingptr) 
    {
        return;
    }

    void UnlinkNode(T* ptr) 
    {
        return;
    }

    void UnlinkAll() 
    {
        return;
    }

    T* NewNode(unsigned long location, unsigned long extrabytes, unsigned long flags) 
    { 
        return nullptr; 
    }

    T* DeleteNode(T* ptr) 
    { 
        return nullptr; 
    }
    

    T* Next(T* ptr) 
    { 
        return nullptr; 
    }

    T* Prev(T* ptr) 
    { 
        return nullptr; 
    }

    T* RawNext(T* ptr) 
    { 
        return nullptr; 
    }

    T* Head() 
    { 
        return nullptr; 
    }

    T* Tail() 
    { 
        return nullptr; 
    }


    // const T* Next(T* ptr) { return nullptr; }
    // const T* Prev(T* ptr) { return nullptr; }
    // const T* RawNext(T* ptr) { return nullptr; }
    // const T* Head() { return nullptr; }
    // const T* Tail() { return nullptr; }

};
