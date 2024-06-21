//
// CiRange.hpp - 
//

#pragma once

namespace NTempest
{
    class CiRange 
    {
        enum
        {
            eComponents = 0x2,
        };

    private:
        long l;
        long h;

    public:
        // static functions -------------------------------
        static CiRange __fastcall Intersection(CiRange&, CiRange&);
        static CiRange __fastcall Union(CiRange&, CiRange&);
        static unsigned char __fastcall InRange(long, long, long);

        // non-virtual functions --------------------------
        CiRange(long l, long h);
        CiRange(long r);
        ~CiRange();

        CiRange& operator+=(CiRange&);
        CiRange& operator-=(CiRange&);
        CiRange& operator*=(CiRange&);
        CiRange& operator/=(CiRange&);
        CiRange operator-();

        void Get(long& l, long& h);
        void Set(long l, long h);
        long Low();
        long High();

        unsigned char Empty();
        unsigned char NotEmpty();
        unsigned char Invalid();
        unsigned char NotInvalid();
        unsigned char Encloses(CiRange&);
        unsigned char Contains(CiRange&);
        unsigned char InClosedRange(long);
        unsigned char InOpenRange(long);
        long Magnitude();
        long Center();
        void Center(CiRange&);
        void Stretch(long);
        void Offset(long);
        void AlignLow(CiRange&);
        void AlignHigh(CiRange&);
        long ClampClosed(long);
        long ClampOpen(long);
        CiRange Intersect(CiRange&);
        CiRange Unite(CiRange&);
    };

}