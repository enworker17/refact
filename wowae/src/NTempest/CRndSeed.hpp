//
// CRndSeed.hpp - class CRndSeed namespace NTempest
// 

#pragma once

namespace NTempest
{
    class CRndSeed 
    {
        unsigned long rndacc;
        unsigned long rndvls;
    
    public:
        CRndSeed(char* str);
        CRndSeed(unsigned long seed);
        ~CRndSeed();
        
        void SetSeed(char* password);
        void SetSeed(unsigned long seed);

    };

}

