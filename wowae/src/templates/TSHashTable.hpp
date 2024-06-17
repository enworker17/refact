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
    static unsigned int /* __fastcall */ Hash(char* str) 
    {
        return 0;
    }


    // non-virtual functions --------------------------
    TSHashTable<T,U>() 
    {
        return;
    }

    
    TSHashTable<T,U>(TSHashTable<T,U>&) 
    {
        return;
    }

    TSHashTable<T,U>& operator=(TSHashTable<T,U>&) 
    {
        return this;
    }

    
    unsigned int ComputeSlot(unsigned int) { return 0; }
    void GrowListArray(unsigned int newarraysize) 
    {
        return;
    }

    void Initialize() 
    {
        return;
    }

    int Initialized() 
    {
        return 0;
    }

    void InternalClear(int warn) 
    {
        return;
    }

    int MonitorFullness(unsigned int slot) 
    {
        return 0;
    }

    void InternalLinkNode(T* ptr, unsigned int hashval) 
    {
        return;
    }

    TSHashTable<T,U>& NonConst() 
    {
        return nullptr;
    }

    int GetLinkOffset() 
    {
        return 0;
    }

    void Clear() 
    {
        return;
    }

    void Delete(char*) 
    {
        return;
    }

    void Delete(unsigned int, char*) 
    {
        return;
    }

    void Delete(unsigned int, U&) 
    {
        return;
    }

    void Delete(T* ptr) 
    {
        return;
    }

    void Insert(T*, char*) 
    {
        return;
    }

    void Insert(T*, unsigned int, char*) 
    {
        return;
    }

    void Insert(T*, unsigned int, U&) 
    {
        return;
    }

    T* InternalNewNode(unsigned int hashval, unsigned long extrabytes, unsigned long flags) 
    {
        return nullptr;
    }

    T* DeleteNode(T*) 
    {
        return nullptr;
    }

    T* New(char*, unsigned long, unsigned long) 
    {
        return nullptr;
    }

    T* New(unsigned int hashval, char* str, unsigned long extrabytes, unsigned long flags) 
    {
        return nullptr;
    }

    T* New(unsigned int, U&, unsigned long, unsigned long) 
    {
        return nullptr;
    }

    T* Next(T*) 
    {
        return nullptr;
    }

    T* Prev(T*) 
    {
        return nullptr;
    }

    T* Ptr(char*) 
    {
        return nullptr;
    }

    T* Ptr(unsigned int, char*) 
    {
        return nullptr;
    }

    T* Ptr(unsigned int, U&) 
    {
        return nullptr;
    }

    T* RawNext(T*) 
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


    // const T* Next(T*) { return nullptr; }
    // const T* Prev(T*) { return nullptr; }
    // const T* Ptr(char* str) { return nullptr; }
    // const T* Ptr(unsigned int, char*) { return nullptr; }
    // const T* Ptr(unsigned int hashval, U& key) { return nullptr; }
    // const T* RawNext(T*) { return nullptr; }
    // const T* Head() { return nullptr; }
    // const T* Tail() { return nullptr; }

    void Unlink(T*) 
    {
        return;
    }

    void SetTableSize(unsigned int) 
    {
        return;
    }

    float GetAverageBinDepth() 
    {
        return 0.0f;
    }

    unsigned int GetPeakBinDepth() 
    {
        return 0;
    }


    // virtual functions ------------------------------
    virtual void InternalDelete(T* ptr) 
    {
        return;
    }

    virtual T* InternalNew(TSExplicitList<T, 0xDDDDDDDD>* listptr, unsigned long extrabytes, unsigned long flags) 
    {
        return nullptr;
    }

    virtual ~TSHashTable<T,U>() 
    {
        return;
    }

    virtual void Destroy() 
    {
        return;
    }

};

