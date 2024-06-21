//
// CCone.hpp - 
//

#pragma once

#include "C3Vectors.hpp"

namespace NTempest
{
    class CCone 
    {
    private:
        C3Vector position;
        float    angle;
        C3Vector axis;
        float    height;
        float    cosAngle;

    public:
        CCone(C3Vector&, float, float, C3Vector&, unsigned char);
        ~CCone();

        void Angle(float);
        float Angle();
        float CosAngle();
    };
} // namespace NTempest
