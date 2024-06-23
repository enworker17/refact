//
// C24Matrix.hpp - 
//

#pragma once

namespace NTempest
{
    class C24Matrix
    {
        enum
        {
            eComponents = 0x8,
        };

    private:
        float a0;
        float a1;
        float b0;
        float b1;
        float c0;
        float c1;
        float d0;
        float d1;

    public:
        C24Matrix();
        C24Matrix(float);
        C24Matrix(float, float, float, float, float, float, float, float);
        ~C24Matrix();

        float* operator[](unsigned int);
        float* operator[](const unsigned long);

        float* Access();
        float* Access();
    };
}