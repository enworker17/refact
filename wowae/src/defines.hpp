//
// defines.hpp - глобальные определения
//

#pragma once
typedef float              f32;
typedef double             f64;

typedef signed char        i8;
typedef signed short       i16;
typedef signed int         i32;
typedef signed long long   i64;

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

// typedef intptr_t  iPtr;
// typedef uintptr_t uPtr;

#if defined(_WIN64) || defined(WIN64) || \
    defined(__LP64__) || defined(_LP64)
typedef signed long long iPtr;
typedef unsigned long long uPtr;
#else
typedef signed int iPtr;
typedef unsigned int iPtr;
#endif

// boolean type
// #define b32   u32 /* bool 32 bit */
// #define b8    u8  /* bool 8 bit */
// #define TRUE  1
// #define FALSE 0


