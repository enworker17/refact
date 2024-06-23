//
// C3Ray.hpp - 
//

#pragma once

#include "CAaBox.hpp"

namespace NTempest
{
    class C3Ray
    {
    private:
        C3Vector origin;
        C3Vector dir;


    public:
        C3Ray(C3Vector &, C3Vector &);
        C3Ray();
        ~C3Ray();

        C3Vector Point(float);
        CAaBox AaBox();
    };
} // namespace NTempest
