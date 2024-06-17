//
// TSLinkedNode.hpp - template TSLinkedNode
//

#pragma once

#include "TSLink.hpp"

template<typename T>
class TSLinkedNode
{
private:
    TSLink<T> m_link;

public:
    TSLinkedNode<T>() 
    {
        return;
    }

    ~TSLinkedNode<T>() 
    {
        return;
    }
    

    TSLinkedNode<T>(TSLinkedNode<T>& source) 
    {
        return;
    }

    TSLinkedNode<T>& operator=(TSLinkedNode<T>& source) 
    { 
        return this; 
    }
    
    bool IsLinked() 
    { 
        return false; 
    }

    void Unlink() 
    {
        return;
    }
    

    T* Next() 
    { 
        return nullptr; 
    }

    T* Prev() 
    { 
        return nullptr; 
    }

    T* RawNext() 
    { 
        return nullptr; 
    }
    

    // const T* Next() { return nullptr; }
    // const T* Prev() { return nullptr; }
    // const T* RawNext() { return nullptr; }

};

