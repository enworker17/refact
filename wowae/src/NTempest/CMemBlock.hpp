//
// CMemBlock.hpp - 
//

#pragma once

#include "CEntity.hpp"

namespace NTempest
{
    class CMemBlock : public CEntity
    {

    private:
        // non-static data --------------------------------
        char *        mem_;
        unsigned long size_;
        char *        mem;
        unsigned long size;
        char *        filen_;
        long          linen_;

    public:
        // static functions -------------------------------
        static void __fastcall Set32b_(unsigned long *d, unsigned long c, unsigned long size);
        static void __fastcall Set32b_(char *d, unsigned char c, unsigned long size);
        static void __fastcall SetM_(unsigned long *d, unsigned long c, unsigned long size);
        static void __fastcall SetM_(char *d, unsigned char c, unsigned long size);
        static void __fastcall Set(char *, unsigned char, unsigned long);
        static void __fastcall Set32(unsigned long *, unsigned long, unsigned long);
        static void __fastcall Zero(char *, unsigned long);
        static void __fastcall Copy(char *, char *, unsigned long);
        static long __fastcall Compare(char *, char *, unsigned long);
        static char *__fastcall Allocate(unsigned long, char *, long);
        static void __fastcall Dispose(char *, char *, long);

        // non-virtual functions --------------------------
        void Constructor_(unsigned long bsize, unsigned long prologue, char *filen, long linen);
        void Destructor_();

        CMemBlock(CMemBlock &m);
        CMemBlock(unsigned long bsize, unsigned long prologue, char *filen, long linen);

        CMemBlock & operator=(CMemBlock & m);

        unsigned char IsValid();
        char * Get();
        unsigned long  Size();
        void Set(unsigned char);
        void Set32(unsigned long);
        void Zero();
        unsigned longCopy(CMemBlock &from);
        long Compare(CMemBlock &to);
        char * Get_();
        unsigned long Size_();
        unsigned long Prologue_();
        void Set_(unsigned char);
        void Set32_(unsigned long);
        void Zero_();
        unsigned long Copy_(CMemBlock &from);
        long Compare_(CMemBlock &to);
        unsigned char Swap(CMemBlock &with);
        unsigned char Resize(unsigned long newsize, unsigned char preserve);
        void Detach(char *&mem, unsigned long &size);
        void Attach(char *mem, unsigned long size);
        void Detach_(char *&mem, unsigned long &size, char *&mem_, unsigned long &size_);
        void Attach_(char *mem, unsigned long size, char *mem_, unsigned long size_);
        char * FileN_();
        long LineN_();
        void SetFileN_(char *filen);
        void SetLineN_(long linen);

        // virtual functions ------------------------------
        virtual ~CMemBlock();
    };
}