//
// CAaBox.hpp - 
//

#pragma once

#include "C3Vectors.hpp"
#include "Ntemplate.hpp"

namespace NTempest
{
    class CAaBox
    {
    private:
        C3Vector b;
        C3Vector t;

    public:
        // static functions -------------------------------
        static CAaBox __fastcall Lerp(CAaBox &, CAaBox &, CAaBox &);
        static CAaBox __fastcall Intersection(CAaBox &, CAaBox &, CAaBox &);
        static CAaBox __fastcall Intersection(CAaBox &, CAaBox &);
        static CAaBox __fastcall Union(CAaBox &, CAaBox &);
        static CAaBox __fastcall Bounding(CAaBox* __$ReturnUdt, CDynTable<unsigned long> &index);
        static CAaBox __fastcall Bounding(CDynTable<C3Vector> &);
        static CAaBox __fastcall Bounding(CAaBox* __$ReturnUdt, C3Vector *vectors);

        // non-virtual functions --------------------------
        CAaBox(C3Vector &bottom, C3Vector &top);
        CAaBox(C3Vector &);
        CAaBox(float a);
        ~CAaBox();

        CAaBox & operator+=(float);
        CAaBox & operator+=(CAaBox &);
        CAaBox & operator-=(float);
        CAaBox & operator-=(CAaBox &);
        CAaBox & operator*=(float);
        CAaBox & operator*=(CAaBox &);
        CAaBox & operator/=(float);
        CAaBox & operator/=(CAaBox &);
        CAaBox operator-();

        float * Access();
        float * Access();
        void Get(C3Vector &, C3Vector &);
        void Set(C3Vector &, C3Vector &);
        void Set(C3Vector &);
        void Set(float);
        unsigned char NotEmpty();
        unsigned char Empty();
        unsigned char Encloses(CAaBox &);
        unsigned char Encloses(C2Vector &);
        unsigned char Encloses(C3Vector &);
        unsigned char Contains(CAaBox &);
        unsigned char Contains(C2Vector &);
        unsigned char Contains(C3Vector &);
        unsigned char InOpenR(CAaBox &);
        unsigned char InOpenR(C3Vector &);
        unsigned char Intersects(CAaBox &);
        unsigned char Intersects2d(CAaBox &);
        float Width();
        float Height();
        float Depth();
        C3Vector Diagonal();
        C3Vector Center();
        void CenterX(CAaBox &);
        float CenterX();
        void CenterY(CAaBox &);
        float CenterY();
        void CenterZ(CAaBox &);
        float CenterZ();
        void Stretch(float);
        void Stretch(C3Vector &);
        void StretchX(float);
        void StretchY(float);
        void StretchZ(float);
        void Offset(C3Vector &);
        void OffsetX(float);
        void OffsetY(float);
        void OffsetZ(float);
        void SetWidth(float);
        void SetHeight(float);
        void SetDepth(float);
        void SetWidthTop(float);
        void SetHeightTop(float);
        void SetDepthTop(float);
        void Enclose(C3Vector &d);
        void SetWidthCenter(float);
        void SetHeightCenter(float);
        void SetDepthCenter(float);
        void CenterAt(CAaBox &);
        void CenterAt(C3Vector &);
        void AlignBottom(CAaBox &);
        void AlignTop(CAaBox &);
        void AlignBottomX(CAaBox &);
        void AlignTopX(CAaBox &);
        void AlignBottomY(CAaBox &);
        void AlignTopY(CAaBox &);
        void AlignBottomZ(CAaBox &);
        void AlignTopZ(CAaBox &);
        CAaBox Intersect(CAaBox &);
        CAaBox Unite(CAaBox &);
    };
} // namespace NTempest
