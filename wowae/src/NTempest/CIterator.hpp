//
// CIterator.hpp - 
//

#pragma once

namespace NTempest
{
    class CIterator
    {
    private:
        unsigned long iscan;

    public:
        CIterator();

        unsigned long Index();
        void SetIndex(unsigned long);
    };
} // namespace NTempest
