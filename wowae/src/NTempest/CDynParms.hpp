//
// CDynParms.hpp - 
//

#pragma once

namespace NTempest
{
    class CDynParms
    {
    private:
        unsigned long prealloc;
        unsigned long expandf;

    public:
        CDynParms(unsigned long, unsigned long);

        unsigned long Prealloc();
        unsigned long ExpandF();
        void SetPrealloc(unsigned long);
        void SetExpandF(unsigned long);
    };
}