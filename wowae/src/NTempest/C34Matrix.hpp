//
// C34Matrix.hpp - 
//

#pragma once

#include "C4Quaternion.hpp"

namespace NTempest
{
    class C34Matrix 
    {
        enum
        {
            eComponents = 0xc,
        };

    private:
        /*  
           | a0 a1 a2 |
           | b0 b1 b2 |
           | c0 c1 c2 |
           | d0 d1 d2 |
        */
        float a0;
        float a1;
        float a2;
        float b0;
        float b1;
        float b2;
        float c0;
        float c1;
        float c2;
        float d0;
        float d1;
        float d2;

    public:
        // static functions -------------------------------
        static C34Matrix __fastcall Rotation(C34Matrix* __$ReturnUdt, float angle, C3Vector& axis);
        static C3Vector __fastcall mul3v33m_(C34Matrix&, C3Vector&);
        static C3Vector __fastcall mul3v33m_(C3Vector&, C34Matrix&);

        // non-virtual functions --------------------------
        C34Matrix(C3Vector&, C3Vector&, C3Vector&, C3Vector&);
        C34Matrix(C3Vector&, C3Vector&, C3Vector&);
        C34Matrix(C33Matrix&);
        C34Matrix(float a0, float a1, float a2, float b0, float b1, float b2, float c0, float c1, float c2, float d0, float d1, float d2);
        C34Matrix(float);
        C34Matrix();
        ~C34Matrix();

        operator C33Matrix();
        C34Matrix& operator=(C34Matrix&);
        C34Matrix& operator+=(C34Matrix& a);
        C34Matrix& operator-=(C34Matrix& a);
        C34Matrix& operator*=(float a);
        C34Matrix& operator*=(C34Matrix& a);
        C34Matrix& operator/=(float a);
        float* operator[](unsigned int);
        // float* operator[](const unsigned int);

        float* Access();
        // float* Access();
        C3Vector* Row0AsVec3();
        // C3Vector* Row0AsVec3();
        C3Vector* Row1AsVec3();
        // C3Vector* Row1AsVec3();
        C3Vector* Row2AsVec3();
        // C3Vector* Row2AsVec3();
        C3Vector* Row3AsVec3();
        // C3Vector* Row3AsVec3();
        C3Vector Row0();
        C3Vector Row1();
        C3Vector Row2();
        C3Vector Row3();
        C4Vector Col0();
        C4Vector Col1();
        C4Vector Col2();
        void Zero();
        void Identity();
        float Trace();
        void Translate(C3Vector& move);
        void Scale(float scale);
        void Scale(C3Vector& scale);
        void Rotate(C4Quaternion& rotation);
        void Rotate(float angle, C3Vector& axis, unsigned char unit);
        C34Matrix AffineInverse(C34Matrix* __$ReturnUdt);
        const C34Matrix AffineInverse(const C34Matrix* __$ReturnUdt);
        C34Matrix AffineInverse();
    };
}