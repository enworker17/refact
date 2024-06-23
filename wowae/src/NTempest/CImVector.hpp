//
// CImVector.hpp - 
//

#pragma once

namespace NTempest
{
    class C3Vector;
    class CArgb4444;
    class CArgb1555;
    class CRgb565;

    class CImVector
    {
        enum Transparent
        {
            eTransparent = 0x0000,
            eOpaque8bit  = 0x00ff,
            eOpaque      = 0x0100,
        };

        enum Mask
        {
            eAlphaMask    = 0xff000000,
            eNotAlphaMask = 0x00ffffff,
            eRedMask      = 0x00ff0000,
            eNotRedMask   = 0xff00ffff,
            eGreenMask    = 0x0000ff00,
            eNotGreenMask = 0xffff00ff,
            eBlueMask     = 0x000000ff,
            eNotBlueMask  = 0xffffff00,
        };

        enum Canal
        {
            eBlueS  = 0x0,
            eGreenS = 0x8,
            eRedS   = 0x10,
            eAlphaS = 0x18,
        };

    private:
        // static data ------------------------------------
        static unsigned char s_a1Table[0];
        static unsigned char s_a4Table[0];

        // non-static data --------------------------------
        unsigned char b;
        unsigned char g;
        unsigned char r;
        unsigned char a;


    public:
        // static functions -------------------------------
        static unsigned char __fastcall ScaleC(unsigned long, unsigned long);
        static unsigned char __fastcall ScaleC255(unsigned long, unsigned long);
        static unsigned char __fastcall BlendC(unsigned long, unsigned long, unsigned long);
        static unsigned long __fastcall MakeARGB(unsigned char, unsigned char, unsigned char, unsigned char);
        static unsigned long __fastcall MakeRGB(unsigned char, unsigned char, unsigned char);
        static unsigned long __fastcall A_(unsigned long);
        static unsigned long __fastcall R_(unsigned long);
        static unsigned long __fastcall G_(unsigned long);
        static unsigned long __fastcall B_(unsigned long);
        static void __fastcall Get_(unsigned long, float &, float &, float &, float &);
        static void __fastcall Get_(unsigned long, unsigned long &, unsigned long &, unsigned long &, unsigned long &);
        static void __fastcall Get_(unsigned long, unsigned long &, unsigned long &, unsigned long &);
        static unsigned long __fastcall Neg(unsigned long);
        static unsigned long __fastcall NegRGB(unsigned long);
        static unsigned long __fastcall Desaturate(unsigned long);
        static unsigned long __fastcall NegA(unsigned long);
        static unsigned long __fastcall NegR(unsigned long);
        static unsigned long __fastcall NegG(unsigned long);
        static unsigned long __fastcall NegB(unsigned long);
        static unsigned char __fastcall Gray(unsigned long);

        // non-virtual functions --------------------------
        CImVector(CImVector &s);
        CImVector(CImVector *);
        CImVector(unsigned char, unsigned char, unsigned char);
        CImVector(unsigned char a, unsigned char r, unsigned char g, unsigned char b);
        CImVector(unsigned long n);
        ~CImVector();

        operator unsigned long();
        operator C3Vector();
        CImVector & operator=(C3Vector & c);
        CImVector & operator=(CArgb4444 &);
        CImVector & operator=(CArgb1555 &);
        CImVector & operator=(CRgb565 & c);
        CImVector & operator=(unsigned long n);
        CImVector & operator=(CImVector &);
        unsigned long operator~();
        unsigned char & operator[](unsigned int);
        unsigned char & operator[](unsigned long);

        unsigned long SetC_(unsigned long, unsigned long, unsigned long);
        void Scale_(unsigned long);
        void ScaleRGB_(unsigned long);
        void Scale255_(unsigned long a);
        void Scale255RGB_(unsigned long);
        void Multiply_(CImVector *);
        void MultiplyRGB_(CImVector *s);
        void Blend_(unsigned long, CImVector *);
        void BlendRGB_(unsigned long a, CImVector *s);
        void BlendARGB_(unsigned long, CImVector *);
        void Blend255_(unsigned long a, CImVector *s);
        void BlendRGB255_(unsigned long a, CImVector *s);
        unsigned long A_();
        unsigned long R_();
        unsigned long G_();
        unsigned long B_();
        void Neg();
        void NegRGB();
        void Desaturate();
        void NegA();
        void NegR();
        void NegG();
        void NegB();
        unsigned char Gray();
        unsigned long * IV_();
        void Get(float &, float &, float &, float &);
        void Get(unsigned long &, unsigned long &, unsigned long &, unsigned long &);
        void Get(unsigned long &, unsigned long &, unsigned long &);
        unsigned long Get();
        unsigned long GetRGB();
        void SetA(unsigned char);
        void SetR(unsigned char);
        void SetG(unsigned char);
        void SetB(unsigned char);
        void Set(float, float, float, float);
        void Set(unsigned long);
        void Set(CImVector *);
        void Set(CImVector &);
        void Set(unsigned char, unsigned char, unsigned char);
        void Set(unsigned char a, unsigned char r, unsigned char g, unsigned char b);
        void SetRGB(unsigned long);
        void SetRGB(CImVector *s);
        void SetRGB(CImVector &);
        void SetRGB(unsigned char, unsigned char, unsigned char);
        void From565(unsigned char r5, unsigned char g6, unsigned char b5);
        void From1555(unsigned char, unsigned char, unsigned char, unsigned char);
        void From4444(unsigned char, unsigned char, unsigned char, unsigned char);
        void FromARGB(unsigned char, CImVector &);
        void Scale(unsigned long);
        void ScaleRGB(unsigned long);
        void Scale255(unsigned long);
        void Scale255RGB(unsigned long);
        void ScaleA(unsigned long);
        void ScaleA255(unsigned long);
        void Multiply(CImVector *);
        void MultiplyRGB(CImVector *);
        void Blend(unsigned long, unsigned long);
        void Blend(unsigned long, CImVector *);
        void Blend(unsigned long);
        void Blend(CImVector *);
        void BlendRGB(unsigned long, unsigned long);
        void BlendRGB(unsigned long, CImVector *);
        void BlendRGB(unsigned long);
        void BlendRGB(CImVector *);
        void BlendARGB(unsigned long, unsigned long);
        void BlendARGB(unsigned long, CImVector *);
        void Blend255(unsigned long, unsigned long);
        void Blend255(unsigned long, CImVector *);
        void Blend255RGB(unsigned long, unsigned long);
        void Blend255RGB(unsigned long, CImVector *);
    };
} // namespace NTempest
