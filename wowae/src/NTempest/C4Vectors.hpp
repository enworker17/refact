//
// C4Vectors.hpp - classes C4Vector and C4iVector
//

#pragma once

#include "C3Vectors.hpp"

namespace NTempest
{

    class C4Vector;
    class C4iVector;
    class C4Vector 
    {
        enum
        {
            eComponents = 0x4,
        };

    private:
        float x;
        float y;
        float z;
        float w;

    public:
        // static functions -------------------------------
        static C4Vector __fastcall Min(C4Vector&, C4Vector&);
        static C4Vector __fastcall Max(C4Vector&, C4Vector&);
        static C4Vector __fastcall Lerp(C4Vector&, C4Vector&, C4Vector&);
        static float __fastcall Dot(C4Vector&, C4Vector&);

        // non-virtual functions --------------------------
        C4Vector(C4iVector&);
        C4Vector(C3Vector&);
        C4Vector(C2Vector&);
        C4Vector(float x, float y, float z, float w);
        C4Vector(float a);
        ~C4Vector();
        
        C4Vector asC4Vector();
        C4Vector* asFloatPtr();

        void Get(float&, float&, float&, float&);
        void Set(float, float, float, float);

        operator C2Vector();
        operator C3Vector();
        C4Vector& operator+=(float);
        C4Vector& operator+=(C4Vector&);
        C4Vector& operator-=(float);
        C4Vector& operator-=(C4Vector&);
        C4Vector& operator*=(float a);
        C4Vector& operator*=(C4Vector&);
        C4Vector& operator/=(float);
        C4Vector& operator/=(C4Vector&);
        C4Vector operator-();
        float& operator[](unsigned int);
        // float& operator[](const unsigned int);

        float SquaredMag();
        float Mag();
        float SumC();
        unsigned char IsUnit();
        void Normalize();
        void SafeNormalize();
        void Scale(float);
        void Minimize(C4Vector&);
        void Maximize(C4Vector&);
    };


    class C4iVector 
    {
        enum
        {
            eComponents = 0x4,
        };

    private:
        long x;
        long y;
        long z;
        long w;

    public:
        // static functions -------------------------------
        static C4iVector __fastcall Min(C4iVector&, C4iVector&);
        static C4iVector __fastcall Max(C4iVector&, C4iVector&);
        static long __fastcall Dot(C4iVector&, C4iVector&);

        // non-virtual functions --------------------------
        C4iVector(C4Vector&);
        C4iVector(C3iVector&);
        C4iVector(C2iVector&);
        C4iVector(long, long, long, long);
        C4iVector(long);
        ~C4iVector();

        void Get(long&, long&, long&, long&);
        void Set(long, long, long, long);

        operator C2iVector();
        operator C3iVector();
        C4iVector& operator+=(long);
        C4iVector& operator+=(C4iVector&);
        C4iVector& operator-=(long);
        C4iVector& operator-=(C4iVector&);
        C4iVector& operator*=(long);
        C4iVector& operator*=(C4iVector&);
        C4iVector& operator/=(long);
        C4iVector& operator/=(C4iVector&);
        C4iVector& operator>>=(long);
        C4iVector& operator>>=(C4iVector&);
        C4iVector& operator<<=(long);
        C4iVector& operator<<=(C4iVector&);
        C4iVector operator-();

        long SquaredMag();
        long Mag();
        long SumC();
        unsigned char IsUnit();
        void Normalize();
        void Scale(long);
        void Minimize(C4iVector&);
        void Maximize(C4iVector&);
    };
}