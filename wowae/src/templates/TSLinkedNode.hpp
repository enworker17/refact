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

    TSLinkedNode<T>(TSLinkedNode<T>& obj);
    TSLinkedNode<T>& operator=(TSLinkedNode<T>& obj);

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


// Implementation
/////////////////////////////////////////////////

template<typename T>
inline TSLinkedNode<T>::TSLinkedNode()
{
    return;
}

template<typename T>
inline TSLinkedNode<T>::~TSLinkedNode()
{
    return;
}

template<typename T>
inline TSLinkedNode<T>::TSLinkedNode(TSLinkedNode<T>& obj)
{
    m_link = obj->m_link;
    return;
}

template<typename T>
inline TSLinkedNode<T>& TSLinkedNode<T>::operator=(TSLinkedNode<T>& obj)
{
    m_link = obj->m_link;
    return this;
}

template<typename T>
inline bool TSLinkedNode<T>::IsLinked()
{
    return m_link->IsLinked();
}

template<typename T>
inline void TSLinkedNode<T>::Unlink()
{
    m_link->Unlink();
}

template<typename T>
inline T* TSLinkedNode<T>::Next()
{
    return m_link->Next();
}

template<typename T>
inline T* TSLinkedNode<T>::Prev()
{
    return m_link->Prev();
}

template<typename T>
inline T* TSLinkedNode<T>::RawNext()
{
    return m_link->RawNext();
}

template<typename T>
inline const T* TSLinkedNode<T>::Next() const
{
    return m_link->Next();
}

template<typename T>
inline const T* TSLinkedNode<T>::Prev() const
{
    return m_link->Prev();
}

template<typename T>
inline const T* TSLinkedNode<T>::RawNext() const
{
    return m_link->RawNext();
}

