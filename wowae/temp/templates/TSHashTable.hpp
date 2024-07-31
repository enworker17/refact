//
// TSHashTable.hpp - template TSHashTable
//

#pragma once

#include "TSExplicitList.hpp"
#include "TSGrowableArray.hpp"

template<typename T, typename U>
class TSHashTable
{
protected:
    TSExplicitList<T, ((int)0xDDDDDDDD)>                   m_fulllist;
    unsigned int                                           m_fullnessIndicator;
    TSGrowableArray<TSExplicitList<T, ((int)0xDDDDDDDD)> > m_slotlistarray;
    unsigned int                                           m_slotmask;


public:
    // static functions -------------------------------
    static unsigned int /* __fastcall */ Hash(char* str);

    // non-virtual functions --------------------------
    TSHashTable<T, U>();

    TSHashTable<T, U>(TSHashTable<T, U>&);
    TSHashTable<T, U>& operator=(TSHashTable<T, U>&);

    unsigned int ComputeSlot(unsigned int);
    void GrowListArray(unsigned int newarraysize);
    void Initialize();
    int Initialized();
    void InternalClear(int warn);
    int MonitorFullness(unsigned int slot);
    void InternalLinkNode(T* ptr, unsigned int hashval);
    TSHashTable<T, U>& NonConst();
    int GetLinkOffset();
    void Clear();
    void Delete(char*);
    void Delete(unsigned int, char*);
    void Delete(unsigned int, U&);
    void Delete(T* ptr);
    void Insert(T*, char*);
    void Insert(T*, unsigned int, char*);
    void Insert(T*, unsigned int, U&);
    T* InternalNewNode(unsigned int hashval, unsigned long extrabytes, unsigned long flags);
    T* DeleteNode(T*);
    T* New(char*, unsigned long, unsigned long);
    T* New(unsigned int hashval, char* str, unsigned long extrabytes, unsigned long flags);
    T* New(unsigned int, U&, unsigned long, unsigned long);
    T* Next(T*);
    T* Prev(T*);
    T* Ptr(char*);
    T* Ptr(unsigned int, char*);
    T* Ptr(unsigned int, U&);
    T* RawNext(T*);
    T* Head();
    T* Tail();

    const T* Next(T*) const;
    const T* Prev(T*) const;
    const T* Ptr(char* str) const;
    const T* Ptr(unsigned int, char*) const;
    const T* Ptr(unsigned int hashval, U& key) const;
    const T* RawNext(T*) const;
    const T* Head() const;
    const T* Tail() const;

    void Unlink(T*)
        void SetTableSize(unsigned int);
    float GetAverageBinDepth();
    unsigned int GetPeakBinDepth();

    // virtual functions ------------------------------
    virtual void InternalDelete(T* ptr);
    virtual T* InternalNew(TSExplicitList<T, ((int)0xDDDDDDDD)>* listptr, unsigned long extrabytes, unsigned long flags);
    virtual ~TSHashTable<T, U>();
    virtual void Destroy();

};

