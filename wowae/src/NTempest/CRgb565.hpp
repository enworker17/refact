//
// CRgb565.hpp - 
//

#pragma once

#include "CImVector.hpp"

namespace NTempest
{
    class CRgb565
    {
        enum
        {
            eRedMask      = 0xf800,
            eNotRedMask   = 0xffff07ff,
            eGreenMask    = 0x07c0,
            eNotGreenMask = 0xfffff83f,
            eBlueMask     = 0x001f,
            eNotBlueMask  = 0xffffffe0,
        };

        enum
        {
            eBlueS  = 0x0,
            eGreenS = 0x5,
            eRedS   = 0xb,
        };

    private:
        unsigned short b : 5; // offset : 0
        unsigned short g : 6; // offset : 5
        unsigned short r : 5; // offset : b

    public:
        // static functions -------------------------------
        static unsigned char __fastcall BlendC(unsigned long, unsigned long, unsigned long);
        static CRgb565 __fastcall Blend(unsigned long, CRgb565&, CRgb565&);

        // non-virtual functions --------------------------
        CRgb565();
        CRgb565(unsigned short);
        CRgb565(unsigned char, unsigned char, unsigned char);
        
        operator unsigned short();
        CRgb565& operator=(CArgb4444 &);
        CRgb565& operator=(CArgb1555 &);
        CRgb565& operator=(CImVector &);
        CRgb565& operator=(CRgb565 &);
        CRgb565& operator=(unsigned short);

        CImVector MakeArgb();
        void From565(unsigned char, unsigned char, unsigned char);
        void From888(unsigned int, unsigned int, unsigned int);
        void From555(unsigned char, unsigned char, unsigned char);
        void From444(unsigned char, unsigned char, unsigned char);
        void FromARGB(unsigned char, CRgb565 &);
    };
} // namespace NTempest
