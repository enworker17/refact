//
// Ntemplate.hpp - template
//

#pragma once

#include "CMemBlock.hpp"
#include "CIterator.hpp"

namespace NTempest
{
    template <typename T>
    class CMemBlockT : public CMemBlock
    {
    public:
        // non-virtual functions --------------------------
        CMemBlockT<T>(CMemBlockT<T> &)
        {
            return;
        }

        CMemBlockT<T>(unsigned long, unsigned long, char *, long)
        {
            return;
        }


        CMemBlockT<T> &  operator=(CMemBlockT<T> &) 
        {
            return this;
        }

        T &  operator[](unsigned long)
        {
            return nullptr;
        }


        T *  Get()
        {
            return nullptr;
        }

        unsigned char Resize(unsigned long, unsigned char) // TODO: return bool
        {
            return 0;
        }


        // virtual functions ------------------------------
        virtual ~CMemBlockT<T>()
        {
            return;
        }
    };

    template <typename T>
    class CDynTable : public CMemBlockT<T>
    {
        enum
        {
            eLessThan = 0xff,
            eEqualTo = 0x0,
            eGreaterThan = 0x1,
        };

    private:
        unsigned long expand;
        unsigned long iallocated;
        unsigned long iused;

    public:
        // static functions -------------------------------
        static long __cdecl MemSortP(T *, T *)
        {
            return 0;
        }

        static long __cdecl Int32SortP(long *, long *)
        {
            return 0;
        }

        static long __cdecl UInt32SortP(unsigned long *, unsigned long *)
        {
            return 0;
        }



        // non-virtual functions --------------------------
        CDynTable<T>(CDynTable<T> &)
        {
            return;
        }

        CDynTable<T>(CDynParms &, unsigned long, char *, long)
        {
            return;
        }


        CDynTable<T> & operator=(CDynTable<T> &)
        {
            return this;
        }

        T & operator[](unsigned long i)
        {
            return nullptr;
        }


        T * Item_(unsigned long)
        {
            return nullptr;
        }

        unsigned long Expansion()
        {
            return 0;
        }

        unsigned long OutIndex()
        {
            return 0;
        }

        unsigned long EntrySize()
        {
            return 0;
        }

        unsigned long Allocated()
        {
            return 0;
        }

        unsigned long Unused()
        {
            return 0;
        }

        unsigned long Used()
        {
            return 0;
        }

        void SetExpansion(unsigned long)
        {
            return;
        }

        unsigned char Swap(CMemBlock &)
        {
            return 0;
        }

        unsigned char Swap(CDynTable<T> &)
        {
            return 0;
        }

        unsigned char Resize(unsigned long, unsigned char)
        {
            return 0;
        }

        T * GetEntry(unsigned long)
        {
            return nullptr;
        }

        void SetEntry(unsigned long, T *, unsigned long)
        {
            return;
        }

        void SetEntry(unsigned long, T &, unsigned long)
        {
            return;
        }

        void SetAllEntries(T *)
        {
            return;
        }

        void SetAllEntries(T &)
        {
            return;
        }

        unsigned char  SwapEntries(unsigned long, unsigned long)
        {
            return 0;
        }

        long CompareEntries(unsigned long, unsigned long, long (*)(T *, T *))
        {
            return 0;
        }

        long CompareEntries(T *, T *, long (*)(T *, T *))
        {
            return 0;
        }

        unsigned char Grow(T *entry, unsigned long count)
        {
            return 0;
        }

        unsigned char Grow(T &, unsigned long)
        {
            return 0;
        }

        unsigned char GrowAll(T *)
        {
            return 0;
        }

        unsigned char GrowAll(T &)
        {
            return 0;
        }

        unsigned char Insert(unsigned long, T *, unsigned long)
        {
            return 0;
        }

        unsigned char Insert(unsigned long, T &, unsigned long)
        {
            return 0;
        }

        unsigned char Remove(unsigned long at, unsigned long count)
        {
            return 0;
        }

        unsigned char RemoveLast()
        {
            return 0;
        }

        unsigned char RemoveAll()
        {
            return 0;
        }

        unsigned long Optimize()
        {
            return 0;
        }

        unsigned char Search(T *, unsigned long &, long (*)(T *, T *))
        {
            return 0;
        }

        unsigned char Search(T &, unsigned long &, long (*)(T *, T *))
        {
            return 0;
        }

        unsigned char Sort(long (*)(T *, T *))
        {
            return 0;
        }

        unsigned char BeginScan(CIterator &)
        {
            return 0;
        }

        T * Current(CIterator &)
        {
            return nullptr;
        }
        
        unsigned long CurrentIndex(CIterator &)
        {
            return 0;
        }

        unsigned char Goto(unsigned long, CIterator &)
        {
            return 0;
        }

        unsigned char Previous(CIterator &)
        {
            return 0;
        }

        unsigned char Next(CIterator &)
        {
            return 0;
        }

        unsigned char SearchBackwards(T *, CIterator &, long (*)(T *, T *))
        {
            return 0;
        }

        unsigned char SearchBackwards(T &, CIterator &, long (*)(T *, T *))
        {
            return 0;
        }

        unsigned char SearchForward(T *, CIterator &, long (*)(T *, T *))
        {
            return 0;
        }

        unsigned char SearchForward(T &, CIterator &, long (*)(T *, T *))
        {
            return 0;
        }

        void EndScan(CIterator &)
        {
            return;
        }


        // virtual functions ------------------------------
        virtual  ~CDynTable<T>()
        {
            return;
        }
    };

    template <typename T, typename U = T>
    class CPriorityQ : public CDynTable<T>
    {
        enum
        {
            eRootIndex = 0x1,
        };

    public:
        // non-virtual functions --------------------------
        CPriorityQ<T, U>(CPriorityQ<T, U> &)
        {
            return;
        }

        CPriorityQ<T, U>(CDynParms &)
        {
            return;
        }


        CPriorityQ<T, U> & operator=(CPriorityQ<T, U> &)
        {
            return this;
        }


        void Validate()
        {
            return;
        }

        unsigned char HasEntries()
        {
            return 0;
        }

        unsigned long EntriesInQueue()
        {
            return 0;
        }

        T Root()
        {
            T t;
            return t;
        }

        void Enqueue(T)
        {
            return;
        }

        T Dequeue()
        {
            T t;
            return t;
        }

        void DiscardAll()
        {
            return;
        }


        // virtual functions ------------------------------
        virtual ~CPriorityQ<T, U>()
        {
            return;
        }
    };

} // namespace NTempest
