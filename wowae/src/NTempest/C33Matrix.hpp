//
// C33Matrix.hpp - 
//

#pragma once

#include "C3Vectors.hpp"

namespace NTempest
{
    class C4Quaternion;

    class C33Matrix 
    {
        enum
        {
            eComponents = 0x9,
        };

    private:
        float a0;
        float a1;
        float a2;
        float b0;
        float b1;
        float b2;
        float c0;
        float c1;
        float c2;

    public:
        // static functions -------------------------------
        static float __fastcall Det(float, float, float, float);
        static C33Matrix __fastcall Rotation(C33Matrix* __$ReturnUdt);
        static C33Matrix __fastcall Rotation(C33Matrix* __$ReturnUdt, float angle, C3Vector& axis);

        // non-virtual functions --------------------------
        C33Matrix(C3Vector&, C3Vector&, C3Vector&);
        C33Matrix(float a0, float a1, float a2, float b0, float b1, float b2, float c0, float c1, float c2);
        C33Matrix(float);
        C33Matrix();
        ~C33Matrix();

        C33Matrix& operator+=(C33Matrix&);
        C33Matrix& operator-=(C33Matrix&);
        C33Matrix& operator*=(float);
        C33Matrix& operator*=(C33Matrix&);
        C33Matrix& operator/=(float);
        float* operator[](unsigned int);
    //    float* operator[](const unsigned int);

        C33Matrix asC33Matrix();
        C33Matrix* asFloatPtr();
        float* Access();
        // const float* Access();
        C2Vector* Row0AsVec2();
        C2Vector* Row1AsVec2();
        C2Vector* Row2AsVec2();
        C3Vector* Row0AsVec3();
        // C3Vector* Row0AsVec3();
        C3Vector* Row1AsVec3();
        // C3Vector* Row1AsVec3();
        C3Vector* Row2AsVec3();
        // C3Vector* Row2AsVec3();
        C3Vector Row0();
        C3Vector Row1();
        C3Vector Row2();
        C3Vector Col0();
        C3Vector Col1();
        C3Vector Col2();
        void Zero();
        void Identity();
        float Trace();
        void Scale(float x, float y);
        void Scale(C2Vector& scale);
        void Scale(float scale);
        void Scale(float x, float y, float z);
        void Scale(C3Vector& scale);
        void Rotate(float angle);
        void Rotate(C4Quaternion& rotation);
        void Rotate(float angle, C3Vector& axis, unsigned char unit);
        void Translate(C2Vector& move);
        C33Matrix Transpose();
        float Determinant();
        C33Matrix Cofactors();
        C33Matrix Adjoint();
        C33Matrix Inverse();
        C33Matrix Inverse(C33Matrix* __$ReturnUdt);
        C33Matrix AffineInverse(C33Matrix* __$ReturnUdt);
        // C33Matrix AffineInverse(C33Matrix* __$ReturnUdt); ?????
        C33Matrix AffineInverse();
        unsigned char ToEulerAnglesXYZ(float& xa_, float& ya_, float& za_);
        unsigned char ToEulerAnglesXZY(float& xa_, float& za_, float& ya_);
        unsigned char ToEulerAnglesYXZ(float& ya_, float& xa_, float& za_);
        unsigned char ToEulerAnglesYZX(float& ya_, float& za_, float& xa_);
        unsigned char ToEulerAnglesZXY(float& za_, float& xa_, float& ya_);
        unsigned char ToEulerAnglesZYX(float& za_, float& ya_, float& xa_);
        void FromEulerAnglesXYZ(float yaw, float pitch, float roll);
        void FromEulerAnglesXZY(float yaw, float pitch, float roll);
        void FromEulerAnglesYXZ(float yaw, float pitch, float roll);
        void FromEulerAnglesYZX(float yaw, float pitch, float roll);
        void FromEulerAnglesZXY(float yaw, float pitch, float roll);
        void FromEulerAnglesZYX(float yaw, float pitch, float roll);
    };
}