//
// CAaSphere.hpp - 
//

#pragma once

#include "CAaBox.hpp"

namespace NTempest
{
    class CAaSphere
    {
    private:
        C3Vector c;
        float r;

    public:
        // static functions -------------------------------
        static float __fastcall square_(float);
        static float __fastcall cube_(float);
        static CAaBox __fastcall FindExtrema(CAaSphere *, unsigned long);
        static CAaSphere __fastcall Lerp(CAaSphere &, CAaSphere &, CAaSphere &);
        static CAaSphere __fastcall Bounding(CDynTable<CAaSphere> &);
        static CAaSphere __fastcall Bounding(CAaSphere *, unsigned long);
        static CAaSphere __fastcall Bounding(CDynTable<unsigned long> &, CDynTable<C3Vector> &);
        static CAaSphere __fastcall Bounding(CDynTable<C3Vector> &);
        static CAaSphere __fastcall Bounding(C3Vector *, unsigned long);

        // non-virtual functions --------------------------
        CAaSphere(C3Vector &center, float radius);
        ~CAaSphere();

        float *Access();
        float *Access();
        void Get(C3Vector &, float &);
        void Set(C3Vector &, float);
        float SquaredD(CAaSphere &);
        float SquaredD(C3Vector &p);
        unsigned char NotEmpty();
        unsigned char Empty();
        unsigned char Intersects(CAaSphere &);
        unsigned char Intersects(C3Vector &);
        unsigned char Encloses(CAaSphere &);
        unsigned char Encloses(C3Vector &);
        unsigned char Contains(CAaSphere &);
        unsigned char Contains(C3Vector &);
        float Diameter();
        float Area();
        float Volume();
        C3Vector Minimum();
        C3Vector Maximum();
    };
} // namespace NTempest
