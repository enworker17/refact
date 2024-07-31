//
// TSLink.hpp -  template TSLink
//

#pragma once

template <typename T> class TSLink
{
private:
  TSLink<T>* m_prevlink;
  T* m_next;

  void Constructor();
  void CopyConstructor(const TSLink<T>&);
  TSLink<T>* NextLink(int linkoffset);

public:
  TSLink<T>();
  ~TSLink<T>();

  TSLink<T>(const TSLink<T>& obj);
  TSLink<T>& operator=(const TSLink<T>& obj);

  bool IsLinked();
  void Unlink();
  T* Next();
  T* Prev();
  T* RawNext();

  const T* Next() const;
  const T* Prev() const;
  const T* RawNext() const;
};
