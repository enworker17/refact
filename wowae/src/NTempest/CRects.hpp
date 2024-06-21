//
// CRects.hpp - classes CRect and CiRect
//

#pragma once

#include "C2Vectors.hpp"

struct tagRECT; // объявлена в windef.h (влючен в Windows.h)
typedef struct tagRECT RECT;

namespace NTempest
{
    class CiRect;
    class CRect;

    class CiRect 
    {
        enum
        {
            eComponents = 0x4,
        };

    private:
        long t;
        long miny;
        long l;
        long minx;
        long b;
        long maxy;
        long r;
        long maxx;

    public:
        // static functions -------------------------------
        static CiRect __fastcall Intersection(CiRect&, CiRect&, CiRect&);
        static CiRect __fastcall Intersection(CiRect* __$ReturnUdt, CiRect& l);
        static CiRect __fastcall Union(CiRect&, CiRect&);
        static CiRect __fastcall ClippedLocal(CiRect&, CiRect&);
        static unsigned long __fastcall Difference(CiRect&, CiRect&, CiRect*);

        // non-virtual functions --------------------------
        CiRect(RECT&);
        CiRect(C2iVector&, C2iVector&);
        CiRect(C2iVector&);
        CiRect(long top, long left, long bottom, long right);
        CiRect(long);
        ~CiRect();

        void Get(long&, long&, long&, long&);
        void Set(long, long, long, long);

        operator RECT();
        CiRect& operator+=(CiRect&);
        CiRect& operator-=(CiRect&);
        CiRect& operator*=(CiRect&);
        CiRect& operator/=(CiRect&);
        CiRect operator-();

        void Stretch(C2iVector&);
        void Stretch(long, long);
        void Offset(C2iVector&);
        void Offset(long, long);

        unsigned char NotEmpty();
        unsigned char Empty();
        unsigned char Invalid();
        unsigned char NotInvalid();
        unsigned char Encloses(CiRect&);
        unsigned char Encloses(C2iVector&);
        unsigned char Contains(CiRect&);
        unsigned char Contains(C2iVector&);
        unsigned char InOpenR(CiRect&);
        unsigned char InOpenR(C2iVector&);

        long Width();
        long Height();
        void SetWidth(long);
        void SetHeight(long);

        C2iVector TopLeft();
        C2iVector TopRight();
        C2iVector BottomLeft();
        C2iVector BottomRight();
        void Center(CiRect&);
        C2iVector Center();
        C2iVector Diagonal();
        void CenterV(CiRect&);
        void CenterH(CiRect&);
        void AlignTop(CiRect&);
        void AlignLeft(CiRect&);
        void AlignBottom(CiRect&);
        void AlignRight(CiRect&);
        CiRect Intersect(CiRect&);
        CiRect Unite(CiRect&);
    };


    class CRect 
    {
        enum
        {
            eComponents = 0x4,
        };

    private:
        float t;
        float miny;
        float l;
        float minx;
        float b;
        float maxy;
        float r;
        float maxx;

    public:
        // static functions -------------------------------
        static CRect __fastcall Lerp(CRect&, CRect&, CRect&);
        static CRect __fastcall Intersection(CRect&, CRect&, CRect&);
        static CRect __fastcall Intersection(CRect* __$ReturnUdt, CRect& l);
        static CRect __fastcall Union(CRect&, CRect&);
        static CRect __fastcall ClippedLocal(CRect&, CRect&);
        static unsigned long __fastcall Difference(CRect&, CRect&, CRect*);

        // non-virtual functions --------------------------
        CRect(RECT&);
        CRect(CiRect&);
        CRect(C2Vector&, C2Vector&);
        CRect(C2Vector&);
        CRect(float top, float left, float bottom, float right);
        CRect(float a);
        ~CRect();

        void Get(float&, float&, float&, float&);
        void Set(float, float, float, float);

        operator RECT();
        CRect  asCRect();
        CRect* asFloatPtr();
        CRect& operator+=(CRect&);
        CRect& operator-=(CRect&);
        CRect& operator*=(CRect&);
        CRect& operator/=(CRect&);
        CRect  operator-();

        void Stretch(C2Vector&);
        void Stretch(float, float);
        void Offset(C2Vector&);
        void Offset(float, float);
        unsigned char NotEmpty();
        unsigned char Empty();
        unsigned char Invalid();
        unsigned char NotInvalid();
        unsigned char Encloses(CRect&);
        unsigned char Encloses(C2Vector&);
        unsigned char Contains(CRect&);
        unsigned char Contains(C2Vector&);
        unsigned char InOpenR(CRect&);
        unsigned char InOpenR(C2Vector&);
        
        float Width();
        float Height();
        void SetWidth(float);
        void SetHeight(float);
        class C2Vector TopLeft();
        class C2Vector TopRight();
        class C2Vector BottomLeft();
        class C2Vector BottomRight();
        void Center(CRect&);
        C2Vector Center();
        C2Vector Diagonal();
        void CenterV(CRect&);
        void CenterH(CRect&);
        void AlignTop(CRect&);
        void AlignLeft(CRect&);
        void AlignBottom(CRect&);
        void AlignRight(CRect&);
        CRect Intersect(CRect* __$ReturnUdt);
        CRect Unite(CRect&);
    };
}