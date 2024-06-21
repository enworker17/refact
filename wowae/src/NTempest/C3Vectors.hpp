//
// C3Vectors.hpp - classes C3Vector and C3iVector
//

#pragma once

#include "C2Vectors.hpp"

namespace NTempest
{
    class C3iVector;
    class C3Vector;
    class C3Vector 
    {
    private:
        float x;
        float y;
        float z;

    public:
        enum Componets 
        {
            eComponents = 0x3,
        };

        enum EAxis 
        {
            C3AXIS_X = 0x0,
            C3AXIS_Y = 0x1,
            C3AXIS_Z = 0x2,
        };


        // static functions -------------------------------
        static C3Vector __fastcall Min(C3Vector& a, C3Vector& b);
        static C3Vector __fastcall Max(C3Vector& a, C3Vector& b);
        static C3Vector __fastcall Lerp(C3Vector&, C3Vector&, C3Vector&);
        static float __fastcall Dot(C3Vector& l, C3Vector& r);
        static C3Vector __fastcall Cross(C3Vector& l, C2Vector& r);
        static C3Vector __fastcall Cross(C2Vector& l, C3Vector& r);
        static C3Vector __fastcall Cross(C3Vector& l, C3Vector& r);
        static C3Vector __fastcall ProjectionOnPlane(C3Vector&, C3Vector&);
        static C3Vector __fastcall NearestOnPlane(C3Vector&, C3Vector&, C3Vector&);

        // non-virtual functions --------------------------
        C3Vector(C3iVector&);
        C3Vector(C2Vector&);
        C3Vector(float x, float y, float z);
        C3Vector(float a);
        ~C3Vector();

        C3Vector asC3Vector();
        C3Vector* asFloatPtr();

        void Get(float&, float&, float&);
        void Set(float tx, float ty, float tz);

        operator C2Vector();
        C3Vector& operator+=(float);
        C3Vector& operator+=(C3Vector& a);
        C3Vector& operator-=(float);
        C3Vector& operator-=(C3Vector& a);
        C3Vector& operator*=(float a);
        C3Vector& operator*=(C3Vector&);
        C3Vector& operator/=(float a);
        C3Vector& operator/=(C3Vector&);
        C3Vector operator-();
        float& operator[](unsigned int sub);
        // float& operator[](const unsigned int sub);

        float SquaredMag();
        float Mag();
        float SumC();
        unsigned char IsUnit();
        void Normalize();
        void SafeNormalize();
        void Scale(float);
        void Minimize(C3Vector&);
        void Maximize(C3Vector& a);
        
        EAxis MajorAxis();
        EAxis MinorAxis();
    };


    class C3iVector 
    {
        enum
        {
            eComponents = 0x3,
        };

    private:
        long x;
        long y;
        long z;

    public:
        // static functions -------------------------------
        static C3iVector __fastcall Min(C3iVector&, C3iVector&);
        static C3iVector __fastcall Max(C3iVector&, C3iVector&);
        static long __fastcall Dot(C3iVector&, C3iVector&);
        static C3iVector __fastcall Cross(C3iVector&, C3iVector&);

        // non-virtual functions --------------------------
        C3iVector(C3Vector&);
        C3iVector(C2iVector&);
        C3iVector(long, long, long);
        C3iVector(long);
        ~C3iVector();

        void Get(long&, long&, long&);
        void Set(long, long, long);

        operator C2iVector();
        C3iVector& operator+=(long);
        C3iVector& operator+=(C3iVector&);
        C3iVector& operator-=(long);
        C3iVector& operator-=(C3iVector&);
        C3iVector& operator*=(long);
        C3iVector& operator*=(C3iVector&);
        C3iVector& operator/=(long);
        C3iVector& operator/=(C3iVector&);
        C3iVector& operator>>=(long);
        C3iVector& operator>>=(C3iVector&);
        C3iVector& operator<<=(long);
        C3iVector& operator<<=(C3iVector&);
        C3iVector operator-();
        long& operator[](unsigned int);
        // long& operator[](const unsigned int);

        long SquaredMag();
        long Mag();
        long SumC();
        unsigned char IsUnit();
        void Normalize();
        void Scale(long);
        void Minimize(C3iVector&);
        void Maximize(C3iVector&);
    };
}