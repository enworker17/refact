//
// CArgb4444.hpp - 
//

#pragma once

#include "CImVector.hpp"

namespace NTempest
{
    class CArgb4444
    {
        enum
        {
            eAlphaMask    = 0x0000f000,
            eNotAlphaMask = 0xffff0fff,
            eRedMask      = 0x00000f00,
            eNotRedMask   = 0xfffff0ff,
            eGreenMask    = 0x000000f0,
            eNotGreenMask = 0xffffff0f,
            eBlueMask     = 0x0000000f,
            eNotBlueMask  = 0x000000f0,
        };

        enum // offset bits
        {
            eBlueS  = 0x0,
            eGreenS = 0x4,
            eRedS   = 0x8,
            eAlphaS = 0xc,
        };

    private:
        // static data --------------------------------
        static unsigned char s_a1Table[0];

        // non-static data --------------------------------
        unsigned short b : 4; // offset : 0
        unsigned short g : 4; // offset : 4
        unsigned short r : 4; // offset : 8
        unsigned short a : 4; // offset : c

    public:
        CArgb4444();
        CArgb4444(unsigned short);
        CArgb4444(unsigned char, unsigned char, unsigned char, unsigned char);
        
        operator unsigned short();
        CArgb4444 & operator=(CImVector &);
        CArgb4444 & operator=(CArgb1555 &);
        CArgb4444 & operator=(CRgb565 &);
        CArgb4444 & operator=(CArgb4444 &);
        CArgb4444 & operator=(unsigned short);

        void From1555(unsigned char, unsigned char, unsigned char, unsigned char);
        void From565(unsigned char r5, unsigned char g6, unsigned char b5);
        void From4444(unsigned char, unsigned char, unsigned char, unsigned char);
        void From8888(unsigned char, unsigned char, unsigned char, unsigned char);
        void FromARGB(unsigned char, CArgb4444 &);
    };
}