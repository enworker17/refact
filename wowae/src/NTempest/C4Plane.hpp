//
// C4Plane.hpp - 
//

#pragma once

#include "C4Vectors.hpp"

namespace NTempest
{
    class C4Plane
    {
        enum
        {
            eComponents = 0x4,
        };

    private:
        C3Vector n;
        float    d;

    public:
        C4Plane(C3Vector &, C3Vector &);
        C4Plane(C3Vector &, C3Vector &, C3Vector &);
        C4Plane(float, float, float, float);
        C4Plane(C3Vector &n, float d);
        ~C4Plane();
        
        operator C4Vector();
        C4Plane operator-();

        void From3Pos(C3Vector &a, C3Vector &b, C3Vector &c);
        float * Access();
        float * Access();
        void Get(float &, float &, float &, float &);
        void Get(C3Vector &, float &);
        void Set(C3Vector &pn, C3Vector &a);
        void Set(C3Vector &, C3Vector &, C3Vector &);
        void Set(float, float, float, float);
        void Set(C3Vector &, float);
        void Translate(C3Vector &);
        float DistSigned(C3Vector &);
        float DistSquared(C3Vector &);
        float Dist(C3Vector &);
        float SolveForX(float, float);
        float SolveForY(float, float);
        float SolveForZ(float, float);
    };
}