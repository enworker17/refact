//
// TSLink.hpp -  template TSLink
//

#pragma once

#include "../defines.hpp"
template <typename T>
class TSLink // <size 0x8>
{
  template<typename U, typename GetLink>
  friend class TSList;

  // Functions
public:
  TSLink<T>();
  ~TSLink<T>();

  TSLink<T>(const TSLink<T>& obj);
  TSLink<T>& operator=(const TSLink<T>& obj);

  // void Link(TSLink<T>* link); // добавлено
  void Unlink();
  bool IsLinked();

  T* Next();
  T* Prev();
  T* RawNext();
  const T* Next() const;
  const T* Prev() const;
  const T* RawNext() const;

private:
  void Constructor();
  void CopyConstructor(TSLink<T>& obj);
  TSLink<T>* NextLink(iPtr linkOffset) const;


  // members
public:
  TSLink<T>* m_prevlink;
  T* m_next;
};


// Implementation
/////////////////////////////////////////////////

template <typename T>
inline TSLink<T>::TSLink()
{
  Constructor();
  return;
}

template <typename T>
inline TSLink<T>::~TSLink()
{
  return Unlink();
}

template <typename T>
inline TSLink<T>::TSLink(const TSLink<T>& obj)
{
  CopyConstructor(&obj);
  return;
}

template <typename T>
inline TSLink<T>& TSLink<T>::operator=(const TSLink<T>& obj)
{
  CopyConstructor(&obj);
  return this;
}

// template<typename T>
// inline void TSLink<T>::Link(TSLink<T>* link) // added
// {
//   m_prevlink = link;
//   m_next = static_cast<T>(~static_cast<iPtr>(link));
// }

template <typename T>
inline void TSLink<T>::Unlink()
{
  /*
    {
      if ( this->m_prevlink )
      {
        TSLink<T>::NextLink(this, -1)->m_link.m_prevlink = this->m_prevlink;
        this->m_prevlink->m_next = this->m_next;
        this->m_prevlink = 0;
        this->m_next = 0;
      }
    }
  */

  if (m_prevlink)
  {
    TSLink* link = NextLink(-1);
    link->m_prevlink = m_prevlink;
    m_prevlink->m_next = m_next;
    m_prevlink = 0;
    m_next = 0;
  }

  return;
}

template <typename T>
inline bool TSLink<T>::IsLinked()
{
  return (m_next != 0);
}

template <typename T>
inline T* TSLink<T>::Next()
{
  return (m_next <= 0 ? 0 : m_next);
}

template <typename T>
inline T* TSLink<T>::Prev()
{
  return Next(m_prevlink->m_prevlink);;
}

template <typename T>
inline T* TSLink<T>::RawNext()
{
  return m_next;
}

template <typename T>
inline const T* TSLink<T>::Next() const
{
  /* return (int)this->m_next <= 0 ? 0 : this->m_next; */
  return (m_next <= 0 ? 0 : m_next);
}

template <typename T>
inline const T* TSLink<T>::Prev() const
{
  return Next(m_prevlink->m_prevlink);
}

template <typename T>
inline const T* TSLink<T>::RawNext() const
{
  return m_next;
}

template <typename T>
inline void TSLink<T>::Constructor()
{
  m_prevlink = 0;
  m_next = 0;
  return;
}

template <typename T>
inline void TSLink<T>::CopyConstructor(TSLink<T>& obj)
{
  m_prevlink = obj.m_prevlink;
  m_next = obj.m_next;
  return;
}

template <typename T>
inline TSLink<T>* TSLink<T>::NextLink(iPtr linkOffset) const
{
  /*
    { // for x86
      int next; // eax
      int offset; // edx

      next = (int)m_next;
      if ( next <= 0 )
        return (TSLink<T>*)~next;
      offset = linkOffset;
      if ( linkOffset < 0 )
        offset = (int)this - (int)m_prevlink->m_next;
      return (TSLink<T>*)(offset + next);
    }
  */

  iPtr next = static_cast<iPtr>(m_next);
  if (next > 0)
  {
    iPtr offset = (linkOffset < 0) ? 
        (static_cast<iPtr>(this) - static_cast<iPtr>(m_prevlink->m_next)) : linkOffset;

    return static_cast<TSLink<T>*>(offset + next);
  }

  return static_cast<TSLink<T>*>(~next);
}
