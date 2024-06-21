//
// C22Matrix.hpp - 
//

#pragma once

#include "C2Vectors.hpp"

namespace NTempest
{
    class C22Matrix 
    {
        enum
        {
            eComponents = 0x4,
        };

    private:
        float a0;
        float a1;
        float b0;
        float b1;

    public:
        // static functions -------------------------------
        static C22Matrix __fastcall Rotation(C22Matrix* __$ReturnUdt);

        // non-virtual functions --------------------------
        C22Matrix(C2Vector&, C2Vector&);
        C22Matrix(float, float, float, float);
        C22Matrix(float);
        C22Matrix();
        ~C22Matrix();

        C22Matrix& operator+=(C22Matrix&);
        C22Matrix& operator-=(C22Matrix&);
        C22Matrix& operator*=(float);
        C22Matrix& operator*=(C22Matrix&);
        C22Matrix& operator/=(float);
        float* operator[](unsigned int);
        // float* operator[](const unsigned int);

        C22Matrix asC22Matrix();
        C22Matrix* asFloatPtr();
        
        float* Access();
        // const float* Access();

        C2Vector* Row0AsVec2();
        C2Vector* Row1AsVec2();
        C2Vector Row0();
        C2Vector Row1();
        C2Vector Col0();
        C2Vector Col1();
        void Zero();
        void Identity();
        float Trace();
        C22Matrix Transpose();
        float Determinant();
        C22Matrix Inverse();
        C22Matrix Inverse(float);
    };
} // namespace NTempest
