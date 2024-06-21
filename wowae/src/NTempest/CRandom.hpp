//
// CRandom.hpp - 
//

#pragma once

#include "CRndSeed.hpp"
#include "C3Vectors.hpp"

namespace NTempest
{
    class CRandom 
    {
    public:
        enum
        {
            rexp   = 0x3f800000,
            rmant  = 0x007fffff,
            lrexp  = 0x3ff00000,
            lrmant = 0x000fffff,
        };

        static unsigned long __fastcall Seed(char* password);
        static unsigned long __fastcall uint32_(CRndSeed& seed);
        static long __fastcall int32_(CRndSeed& seed);
        static float __fastcall real_(CRndSeed& seed);
        static double __fastcall lreal_(CRndSeed& seed);
        static float __fastcall realp_(CRndSeed& seed);
        static double __fastcall lrealp_(CRndSeed& seed);
        static float __fastcall reals_(CRndSeed& seed);
        static double __fastcall lreals_(CRndSeed& seed);
        static float __fastcall reale_(float mean, CRndSeed& seed);
        static float __fastcall reale_(CRndSeed& seed);
        static double __fastcall lreale_(double mean, CRndSeed& seed);
        static double __fastcall lreale_(CRndSeed& seed);
        static float __fastcall realg_(float mean, float var, CRndSeed& seed);
        static float __fastcall realg_(CRndSeed& seed);
        static double __fastcall lrealg_(double mean, double var, CRndSeed& seed);
        static double __fastcall lrealg_(CRndSeed& seed);
        static C2Vector __fastcall C2Vector_(C2Vector* ReturnUdt);
        static C3Vector __fastcall C3Vector_(C3Vector* ReturnUdt);
        static unsigned long __fastcall dice_(unsigned long, unsigned long, CRndSeed& seed);
        static unsigned long __fastcall dice_(unsigned long, CRndSeed& seed);
        static unsigned char __fastcall coin_(float, CRndSeed& seed);
        static unsigned char __fastcall coin_(unsigned long, unsigned long, CRndSeed& seed);
        static unsigned char __fastcall coin_(unsigned long, CRndSeed& seed);
        static unsigned char __fastcall coin_(CRndSeed& seed);
        static void __fastcall array_(C3Vector* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall array_(C2Vector* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall array_(double* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall array_(float* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall array_(long* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall array_(unsigned long* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall arrayp_(double* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall arrayp_(float* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall arrays_(double* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall arrays_(float* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall arraye_(double* buf, unsigned long count, double mean, CRndSeed& seed);
        static void __fastcall arraye_(float* buf, unsigned long count, float mean, CRndSeed& seed);
        static void __fastcall arraye_(double* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall arraye_(float* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall arrayg_(double* buf, unsigned long count, double mean, double var, CRndSeed& seed);
        static void __fastcall arrayg_(float* buf, unsigned long count, float mean, float var, CRndSeed& seed);
        static void __fastcall arrayg_(double* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall arrayg_(float* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall shuffle_(double* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall shuffle_(float* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall shuffle_(unsigned long* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall shuffle_(long* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall shuffle_(unsigned short* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall shuffle_(short* buf, unsigned long count,CRndSeed& seed);
        static void __fastcall shuffle_(unsigned char* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall shuffle_(char* buf, unsigned long count, CRndSeed& seed);
        static void __fastcall shuffle_(char* buf, CRndSeed& seed);
        static void __fastcall crypt_(char* buf, unsigned long size, char* password);
        static void __fastcall crypt_(char* buf, unsigned long size, unsigned long seednum);
        static void __fastcall checksum_(CRndSeed&, unsigned long&);
        static unsigned long __fastcall checksum_(unsigned long);
        static void __fastcall checksum8_(unsigned long, unsigned long&);
        static void __fastcall checksum16_(unsigned long, unsigned long&);
        static void __fastcall checksum32_(unsigned long, unsigned long&);
        static void __fastcall checksumr_(float, unsigned long&);
        static void __fastcall checksumm32_(unsigned long*, unsigned long, unsigned long, unsigned long&);
        static void __fastcall checksumm32_(unsigned long*, unsigned long, unsigned long&);
        static void __fastcall checksumm16_(unsigned short*, unsigned long, unsigned short, unsigned long&);
        static void __fastcall checksumm16_(unsigned short*, unsigned long, unsigned long&);
        static void __fastcall checksumm8_(unsigned char*, unsigned long, unsigned char, unsigned long&);
        static void __fastcall checksumm8_(unsigned char*, unsigned long, unsigned long&);
        static void __fastcall checksumms_(char**, unsigned long, unsigned long&);
        static unsigned long __fastcall lattice_(long x, long y, long z, long w);
        static unsigned long __fastcall lattice_(long x, long y, long z);
        static unsigned long __fastcall lattice_(long x, long y);
        static unsigned long __fastcall lattice_(long x);
        static void __fastcall lattice2_(long x, unsigned long* vtx);
        static void __fastcall lattice4_(long x, long y, unsigned long* vtx);
        static void __fastcall lattice8_(long x, long y, long z, unsigned long* vtx);
        static void __fastcall lattice3_(long x, unsigned long* vtx);
        static void __fastcall lattice9_(long x, long y, unsigned long* vtx);
        static void __fastcall lattice27_(long x, long y, long zc, unsigned long* vtx);
        static float __fastcall noise_(double x, double y, double z, C3Vector& d);
        static float __fastcall noise_(double x, double y, double z);
        static float __fastcall noise_(double x, double y);
        static float __fastcall noise_(double x);
        static float __fastcall turbulence_(double x, double y, double z, C3Vector& d, unsigned long __formal);
    };
}