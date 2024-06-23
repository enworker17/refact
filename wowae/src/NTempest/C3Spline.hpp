//
// C3Spline.hpp - 
//

#pragma once

#include "../templates/TSGrowableArray.hpp"
#include "C24Matrix.hpp"
#include "C44Matrix.hpp"

namespace NTempest
{
    class C3Spline
    {
        enum
        {
            DEFAULT_STEPS = 0x14,
        };

    private:
        float                     cachedLength;
        TSGrowableArray<C3Vector> points;
        TSGrowableArray<float>    cachedSegLength;


    public:
        enum EvalType
        {
            EVAL_PARAMETRIC = 0x0,
            EVAL_ARCLENGTH = 0x1,
            EVAL_COUNT = 0x2,
        };

        // non-virtual functions --------------------------
        C3Spline(C3Spline &);
        C3Spline();
        ~C3Spline();

        C3Spline &operator=(C3Spline &);

        void ValidateCache();
        void Evaluate(unsigned int segment, float t, C44Matrix &coeffs, C3Vector &pos);
        void EvaluateDer1(unsigned int segment, float t, C34Matrix &coeffs, C3Vector &der);
        void EvaluateDer2(unsigned int segment, float t, C24Matrix &coeffs, C3Vector &der);
        float SegLength(unsigned int segment, C44Matrix &coeffs);
        void ParametricSegT(float wholeT, unsigned int segCount, unsigned int &segment, float &t);
        void ArclengthSegT(float s, C44Matrix &coeffs, unsigned int segCount, unsigned int &seg, float &t);
        void Curvature(unsigned int segment, float t, C34Matrix &der1coeffs, C24Matrix &der2coeffs, C3Vector &centerOfCurvature);
        unsigned int NumPoints();
        C3Vector& Point(unsigned int);
        void SetPoints(TSGrowableArray<C3Vector> &);
        void SetPoints(C3Vector *pts, unsigned int count);
        void SetPoint(unsigned int pointSub, C3Vector &p);
        void Pos(float t, C3Vector &pos, EvalType ptype);
        void Vel(float t, C3Vector &vel, EvalType ptype);
        void Frame(float t, C34Matrix &frame, EvalType ptype);
        float Length();

        // virtual functions ------------------------------
        virtual float ILength(unsigned int segCount) = 0;
        virtual float ILength() = 0;
        virtual void IValidateCache() = 0;
        virtual void IPosArclength(float, C3Vector &) = 0;
        virtual void IPosParametric(float, C3Vector &) = 0;
        virtual void IVelArclength(float, C3Vector &) = 0;
        virtual void IVelParametric(float, C3Vector &) = 0;
        virtual void IFrameArclength(float, C34Matrix &) = 0;
        
        virtual void ISetPoints(C3Vector *pts, unsigned int count);
    };

    class C3Spline_CatmullRom : public C3Spline
    {
        enum SPLINE_MODE
        {
            MODE_LINEAR = 0x0,
            MODE_CATMULLROM = 0x1,
        };

    private:
        SPLINE_MODE splineMode;

    public:
        // non-virtual functions --------------------------
        C3Spline_CatmullRom();
        C3Spline_CatmullRom(C3Spline_CatmullRom &);
        ~C3Spline_CatmullRom();

        C3Spline_CatmullRom& operator=(C3Spline_CatmullRom &);

        unsigned int SegCount();
        float SegLength(unsigned int segment);
        void ParametricSegT(float wholeT, unsigned int &segment, float &t);
        void ArclengthSegT(float s, unsigned int &seg, float &t);
        void Evaluate(unsigned int segment, float t, C3Vector &pos);
        void EvaluateDer1(unsigned int segment, float t, C3Vector &der);
        void EvaluateDer2(unsigned int segment, float t, C3Vector &der);
        void Curvature(float t, C3Vector &centerOfCurvature);
        void SetSplineMode(SPLINE_MODE mode);

        // virtual functions ------------------------------
        virtual float ILength();
        virtual void IValidateCache();
        virtual void IPosArclength(float t, C3Vector &pos);
        virtual void IPosParametric(float t, C3Vector &pos);
        virtual void IVelArclength(float t, C3Vector &vel);
        virtual void IVelParametric(float t, C3Vector &vel);
        virtual void ISetPoints(C3Vector *pts, unsigned int count);
        virtual void IFrameArclength(float t, C34Matrix &frame);
    };

    class C3Spline_Bezier3 : public C3Spline
    {
    public:
        // non-virtual functions --------------------------
        C3Spline_Bezier3();
        C3Spline_Bezier3(C3Spline_Bezier3 &);
        C3Spline_Bezier3(C3Vector *, unsigned int);
        ~C3Spline_Bezier3();

        C3Spline_Bezier3 & operator=(C3Spline_Bezier3 &);

        unsigned int SegCount();
        float SegLength(unsigned int segment);
        void ParametricSegT(float wholeT, unsigned int &segment, float &t);
        void ArclengthSegT(float s, unsigned int &seg, float &t);
        void Evaluate(unsigned int segment, float t, C3Vector &pos);
        void EvaluateDer1(unsigned int segment, float t, C3Vector &der);

        // virtual functions ------------------------------
        virtual float ILength();
        virtual void IValidateCache();
        virtual void IPosArclength(float t, C3Vector &pos);
        virtual void IPosParametric(float t, C3Vector &pos);
        virtual void IVelArclength(float t, C3Vector &vel);
        virtual void IVelParametric(float t, C3Vector &vel);
        virtual void ISetPoints(C3Vector *pts, unsigned int count);
        virtual void IFrameArclength(float t, C34Matrix &frame);
    };

} // namespace NTempest
