//
// CRange.hpp - 
//

#pragma once

#include "CRndSeed.cpp"

namespace NTempest
{
    class CRange 
    {
        enum
        {
            eComponents = 0x2,
        };

    private:
        float l;
        float h;

    public:
        // static functions -------------------------------
        static CRange __fastcall Lerp(CRange&, CRange&, CRange&);
        static CRange __fastcall Intersection(CRange&, CRange&);
        static CRange __fastcall Union(CRange&, CRange&);
        static unsigned char __fastcall InRange(float, float, float);

        // non-virtual functions --------------------------
        CRange(float, float);
        CRange(float);
        ~CRange();

        CRange& operator+=(CRange& that);
        CRange& operator-=(CRange& that);
        CRange& operator*=(CRange& that);
        CRange& operator/=(CRange& that);
        CRange operator-();

        void Get(float& l, float& h);
        void Set(float l, float h);
        float Low();
        float High();
        float _rnd(float, CRndSeed& seed);
        unsigned char Empty();
        unsigned char NotEmpty();
        unsigned char Invalid();
        unsigned char NotInvalid();
        unsigned char Encloses(CRange& range);
        unsigned char Contains(CRange& range);
        unsigned char InClosedRange(float);
        unsigned char InOpenRange(float);
        float Magnitude();
        float Center();
        void Center(CRange& range);
        void Stretch(float);
        void Offset(float);
        void AlignLow(CRange& range);
        void AlignHigh(CRange& range);
        float ClampClosed(float);
        float ClampOpen(float);
        float Value(CRndSeed& seed);
        CRange Intersect(CRange& range);
        CRange Unite(CRange& range);
    };

}