//
// C2Vectors.hpp - clases C2iVector and C2Vector
//

#pragma once

struct tagPOINT; // объявлено в windef.h (включено в Windows.h)
typedef struct tagPOINT POINT;

namespace NTempest
{
    class C2iVector;
    class C2Vector;
    class C2Vector 
    {
        enum
        {
            eComponents = 0x2,
        };

    private:
        float x;
        float y;

    public:
        // static functions -------------------------------
        static C2Vector __fastcall FromAxisAngle(float, float);
        static float __fastcall AngleToAxisAngle(float);
        static C2Vector __fastcall Min(C2Vector&, C2Vector&);
        static C2Vector __fastcall Max(C2Vector&, C2Vector&);
        static C2Vector __fastcall Lerp(C2Vector&, C2Vector&, C2Vector&);
        static float __fastcall Dot(C2Vector&, C2Vector&);
        static float __fastcall Cross(C2Vector&, C2Vector&);

        // non-virtual functions --------------------------
        C2Vector(C2iVector&);
        C2Vector(float x, float y);
        C2Vector(float);
        ~C2Vector();

        C2Vector asC2Vector();
        C2Vector* asFloatPtr();
        void Get(float&, float&);
        void Set(float, float);

        C2Vector& operator+=(float);
        C2Vector& operator+=(C2Vector&);
        C2Vector& operator-=(float);
        C2Vector& operator-=(C2Vector& a);
        C2Vector& operator*=(float);
        C2Vector& operator*=(C2Vector&);
        C2Vector& operator/=(float);
        C2Vector& operator/=(C2Vector&);
        C2Vector operator-();
        float& operator[](unsigned int);
        // float& operator[](const unsigned int);

        float SquaredMag();
        float Mag();
        float SumC();
        unsigned char IsUnit();
        float AxisAngle();
        float AxisAngle(float);
        void Normalize();
        void SafeNormalize();
        void Scale(float);
        void Minimize(C2Vector&);
        void Maximize(C2Vector&);
    };

    class C2iVector 
    {
        enum
        {
            eComponents = 0x2,
        };

    private:
        long x;
        long y;

    public:
        // static functions -------------------------------
        static C2iVector __fastcall Min(C2iVector&, C2iVector&);
        static C2iVector __fastcall Max(C2iVector&, C2iVector&);
        static long __fastcall Dot(C2iVector&, C2iVector&);

        // non-virtual functions --------------------------
        C2iVector(POINT&);
        C2iVector(C2Vector&);
        C2iVector(long x, long y);
        C2iVector(long a);
        ~C2iVector();

        void Get(long&, long&);
        void Set(long, long);

        operator POINT();
        C2iVector& operator+=(long);
        C2iVector& operator+=(C2iVector&);
        C2iVector& operator-=(long);
        C2iVector& operator-=(C2iVector&);
        C2iVector& operator*=(long);
        C2iVector& operator*=(C2iVector&);
        C2iVector& operator/=(long);
        C2iVector& operator/=(C2iVector&);
        C2iVector& operator>>=(long);
        C2iVector& operator>>=(C2iVector&);
        C2iVector& operator<<=(long);
        C2iVector& operator<<=(C2iVector&);
        C2iVector  operator-();

        long SquaredMag();
        long Mag();
        long SumC();
        unsigned char  IsUnit();
        void Normalize();
        void Scale(long);
        void Minimize(C2iVector&);
        void Maximize(C2iVector&);
    };
}