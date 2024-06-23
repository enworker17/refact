//
// C3Segment.hpp - 
//

#pragma once

#include "CAaBox.hpp"

namespace NTempest
{
    class C3Segment
    {
    private:
        C3Vector start;
        C3Vector end;

    public:
        C3Segment(C3Vector &, C3Vector &);
        C3Segment();
        ~C3Segment();

        C3Vector Direction();
        C3Vector Point(float);
        CAaBox AaBox();
    };
} // namespace NTempest
