//
// CObBox.hpp - 
//

#pragma once

#include "C33Matrix.hpp"

namespace NTempest
{
    class CObBox
    {
    private:
        C3Vector c;
        C3Vector e;
        C33Matrix b;

    public:
        CObBox(C3Vector &, C3Vector &);
        CObBox(C3Vector &, C3Vector &, C33Matrix &);
        CObBox();
        ~CObBox();
    };
} // namespace NTempest
