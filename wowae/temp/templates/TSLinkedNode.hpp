//
// TSLinkedNode.hpp - template TSLinkedNode
//

#pragma once

#include "TSLink.hpp"

template<typename T>
class TSLinkedNode
{
public:
    TSLinkedNode<T>();
    ~TSLinkedNode<T>();

    TSLinkedNode<T>(TSLinkedNode<T>& source);
    TSLinkedNode<T>& operator=(TSLinkedNode<T>& source);

    bool IsLinked();
    void Unlink();

    T* Next();
    T* Prev();
    T* RawNext();

    const T* Next() const;
    const T* Prev() const;
    const T* RawNext() const;

private:
    TSLink<T> m_link;

};
