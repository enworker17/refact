//
// CArgb1555.hpp - 
//

#pragma once

#include "CImVector.hpp"

namespace NTempest
{
    class CArgb1555
    {
        enum 
        {
            eAlphaMask    = 0x8000,
            eNotAlphaMask = 0xffff7fff,
            eRedMask      = 0x7c00,
            eNotRedMask   = 0xffff83ff,
            eGreenMask    = 0x3e0,
            eNotGreenMask = 0xfffffc1f,
            eBlueMask     = 0x1f,
            eNotBlueMask  = 0xe0,
        };

        enum
        {
            eBlueS  = 0x0,
            eGreenS = 0x5,
            eRedS   = 0xa,
            eAlphaS = 0xf,
        };

    private:
        unsigned short b : 5;     // offset bits : 0x0
        unsigned short g : 5;     // offset bits : 0x5
        unsigned short r : 5;     // offset bits : 0xa
        unsigned short a : 1;     // offset bits : 0xf

    public:
        CArgb1555();
        CArgb1555(unsigned short);
        CArgb1555(unsigned char, unsigned char, unsigned char, unsigned char);

        operator unsigned short();
        CArgb1555 & operator=(CImVector &);
        CArgb1555 & operator=(CArgb4444 &);
        CArgb1555 & operator=(CRgb565 & c);
        CArgb1555 & operator=(CArgb1555 &);
        CArgb1555 & operator=(unsigned short);

        void From1555(unsigned char, unsigned char, unsigned char, unsigned char);
        void From565(unsigned char r5, unsigned char g6, unsigned char b5);
        void From4444(unsigned char, unsigned char, unsigned char, unsigned char);
        void From8888(unsigned char, unsigned char, unsigned char, unsigned char);
        void FromARGB(unsigned char, CArgb1555 &);
    };
} // namespace NTempest
