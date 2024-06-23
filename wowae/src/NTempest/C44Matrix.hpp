//
// C44Matrix.hpp - 
//

#pragma once

#include "C34Matrix.hpp"

namespace NTempest
{
    class C44Matrix 
    {
        enum Components 
        {
            eComponents = 0x10,
        };

    private:
        float a0;
        float a1;
        float a2;
        float a3;
        float b0;
        float b1;
        float b2;
        float b3;
        float c0;
        float c1;
        float c2;
        float c3;
        float d0;
        float d1;
        float d2;
        float d3;

    public:
        // static functions -------------------------------
        static float __fastcall Det(float a, float b, float c, float d, float e, float f, float g, float h, float i);
        static C44Matrix __fastcall Rotation(C44Matrix* __$ReturnUdt, float angle, C3Vector& axis);
        static C3Vector __fastcall mul3v33m_(C44Matrix&, C3Vector&);
        static C3Vector __fastcall mul3v33m_(C3Vector&, C44Matrix&);

        // non-virtual functions --------------------------
        C44Matrix(C4Vector&, C4Vector&, C4Vector&, C4Vector&);
        C44Matrix(C3Vector&, C3Vector&, C3Vector&, C3Vector&);
        C44Matrix(C3Vector&, C3Vector&, C3Vector&);
        C44Matrix(C34Matrix&);
        C44Matrix(C33Matrix&);
        C44Matrix(float a0, float a1, float a2, float a3, float b0, float b1, float b2, float b3, float c0, float c1, float c2, float c3, float d0, float d1, float d2, float d3);
        C44Matrix(float);
        C44Matrix();
        ~C44Matrix();

        operator C33Matrix();
        operator C34Matrix();
        C44Matrix& operator=(C44Matrix& a);
        C44Matrix& operator+=(C44Matrix& a);
        C44Matrix& operator-=(C44Matrix& a);
        C44Matrix& operator*=(float a);
        C44Matrix& operator*=(C44Matrix& a);
        C44Matrix& operator/=(float a);
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
        C4Vector* Row0AsVec4();
        C4Vector* Row1AsVec4();
        C4Vector* Row2AsVec4();
        C4Vector* Row3AsVec4();
        C4Vector Row0();
        C4Vector Row1();
        C4Vector Row2();
        C4Vector Row3();
        C4Vector Col0();
        C4Vector Col1();
        C4Vector Col2();
        C4Vector Col3();
        void Zero();
        void Identity();
        float Trace();
        void Translate(C3Vector& move);
        void Scale(float scale);
        void Scale(C3Vector& scale);
        void Rotate(C4Quaternion& rotation);
        void Rotate(float angle, C3Vector& axis, unsigned char unit);
        C44Matrix Transpose();
        float Determinant();
        C44Matrix Cofactors();
        C44Matrix Adjoint();
        C44Matrix Inverse();
        C44Matrix Inverse(C44Matrix* __$ReturnUdt);
        C44Matrix AffineInverse(C44Matrix* __$ReturnUdt);
        // const C44Matrix AffineInverse(const C44Matrix* __$ReturnUdt);
        C44Matrix AffineInverse();
    };
}