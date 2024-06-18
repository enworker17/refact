//
// namespace NTempest - пространство имен NTempest.
// временный файл
//

namespace NTempest
{
    class C2Vector;

    class C3Vector 
    {
    private:

        float x;
        float y;
        float z;


    public:
        enum EAxis 
        {
            C3AXIS_X = 0x0,
            C3AXIS_Y = 0x1,
            C3AXIS_Z = 0x2,
        };


        // static functions -------------------------------
        static C3Vector /* __fastcall */ Min(C3Vector& a, C3Vector& b);
        static C3Vector /* __fastcall */ Max(C3Vector& a, C3Vector& b);
        static C3Vector /* __fastcall */ Lerp(C3Vector& a, C3Vector& b, C3Vector& c);
        static float    /* __fastcall */ Dot(C3Vector& l, C3Vector& r);
        static C3Vector /* __fastcall */ Cross(C3Vector& a, C2Vector& b);
        static C3Vector /* __fastcall */ Cross(C2Vector& a, C3Vector& b);
        static C3Vector /* __fastcall */ Cross(const C3Vector& a, C3Vector& l);
        static C3Vector /* __fastcall */ ProjectionOnPlane(C3Vector& a, C3Vector& b);
        static C3Vector /* __fastcall */ NearestOnPlane(C3Vector& a, C3Vector& b, C3Vector& c);


        // non-virtual functions --------------------------
        C3Vector(C3iVector& a);
        C3Vector(C2Vector& a);
        C3Vector(float x, float y, float z);
        C3Vector(float a);
        ~C3Vector();

        C2Vector operator C2Vector();
        C3Vector& operator+=(float);
        C3Vector& operator+=(C3Vector& a);
        C3Vector& operator-=(float a);
        C3Vector& operator-=(C3Vector& a);
        C3Vector& operator*=(float a);
        C3Vector& operator*=(class C3Vector&);
        C3Vector& operator/=(float a);
        C3Vector& operator/=(C3Vector& a);
        C3Vector operator-();
        float& operator[](unsigned int sub);
        float& operator[](unsigned int sub);

        C3Vector asC3Vector();
        C3Vector* asFloatPtr();
        float SquaredMag();
        float Mag();
        float SumC();
        unsigned char IsUnit();
        void Get(float& x, float& y, float& z);
        void Set(float tx, float ty, float tz);
        void Normalize();
        void SafeNormalize();
        void Scale(float);
        void Minimize(C3Vector& a);
        void Maximize(C3Vector& a);
        EAxis MajorAxis();
        EAxis MinorAxis();

    };

}