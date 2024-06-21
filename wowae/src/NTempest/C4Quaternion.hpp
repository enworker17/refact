//
// C4Quaternion.hpp - 
//

#pragma once

#include "C4Vectors.hpp"

namespace NTempest
{
    class C33Matrix;

    class C4Quaternion : public C4Vector  
    {
    public:
        static C4Quaternion __fastcall Slerp(C4Quaternion* __$ReturnUdt, float t, C4Quaternion& p);
        static void __fastcall SquadInterm(C4Quaternion& q0, C4Quaternion& q1, C4Quaternion& q2, C4Quaternion& a, C4Quaternion& b);
        static void __fastcall SquadIntermMaxCompat(C4Quaternion& q0, C4Quaternion& q1, C4Quaternion& q2, C4Quaternion& a, C4Quaternion& b);
        static void __fastcall SquadIntermTCB(C4Quaternion& q0, C4Quaternion& q1, C4Quaternion& q2, float time0, float time1, float time2, float tension, float continuity, float bias, C4Quaternion& a, C4Quaternion& b);
        static C4Quaternion __fastcall Squad(C4Quaternion* __$ReturnUdt, float t, C4Quaternion& p, C4Quaternion& a, C4Quaternion& b);

        // non-virtual functions --------------------------
        C4Quaternion(float, C3Vector&);
        C4Quaternion(float w, float x, float y, float z);
        C4Quaternion(C4Vector&);
        C4Quaternion();
        ~C4Quaternion();
        
        C3Vector Vector();
        float Real();
        void SetVector(C3Vector&);
        void SetReal(float);
        void Set(float, C3Vector&);
        void Identity();
        void Zero();
        unsigned char IsValid();

        operator C33Matrix();
        C4Quaternion& operator*=(C4Quaternion&);
        C4Quaternion operator*(float);
        C3Vector operator*(C3Vector* __$ReturnUdt);

        float Norm();
        float Abs();
        void FromRotationMatrix(C33Matrix& r);
        void FromRotationMatrixInv(C33Matrix& r);
        void ToRotationMatrix(C33Matrix&);
        void ToRotationMatrixInv(C33Matrix&);
        void FromAngleAxis(float angle, C3Vector& axis);
        void ToAngleAxis(float& angle, C3Vector& axis);
        C4Quaternion Conjugate();
        C4Quaternion Inverse();
        C4Quaternion UnitInverse();
        C4Quaternion Exp();
        C4Quaternion Log();
    };


    class C4QuaternionCompressed 
    {
    private:
        long long m_data;

    public:
        // static functions -------------------------------
        static C4Quaternion __fastcall Slerp(float, C4QuaternionCompressed&, C4QuaternionCompressed&);
        static C4Quaternion __fastcall Squad(float, C4QuaternionCompressed&, C4QuaternionCompressed&, C4QuaternionCompressed&, C4QuaternionCompressed&);

        // non-virtual functions --------------------------
        C4QuaternionCompressed(C4Quaternion&);
        C4QuaternionCompressed(C4QuaternionCompressed&);
        C4QuaternionCompressed(long long);
        C4QuaternionCompressed();

        operator C4Quaternion();
        C4QuaternionCompressed& operator=(C4QuaternionCompressed&);
        C4QuaternionCompressed& operator=(C4Quaternion&);

        float GetX();
        float GetY();
        float GetZ();
        float GetW(float x, float y, float z);
        void Set(C4Quaternion& source);
        long long Raw();
        void Identity();
        unsigned char IsIdentity();
        void FromRotationMatrix(C33Matrix&);
        void FromRotationMatrixInv(C33Matrix&);
    };
}