//
// CFacet.hpp - 
//

#pragma once

#include "C4Plane.hpp"

namespace NTempest
{
    struct CFacet
    {
        enum
        {
            eComponents = 0xd, // 13
        };

        C4Plane  plane;
        C3Vector vertices[3];

        CFacet(C3Vector &a, C3Vector &b, C3Vector &c);
        CFacet(float a);
        ~CFacet();

        void Get(C3Vector *);
        void Get(C4Plane &);
        void Get(C4Plane &, C3Vector *);
        void Set(C3Vector *, C4Plane &);
        void Set(C3Vector *);
        void Set(C3Vector &a, C3Vector &b, C3Vector &c);
        void Set(float a);
    };
} // namespace NTempest
