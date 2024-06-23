//
// CEntity.hpp - 
//

#pragma once

namespace NTempest
{
    class CEntity
    {
    public:
        // non-virtual functions --------------------------
        CEntity(CEntity&);
        CEntity();
        CEntity& operator=(CEntity&);

        // virtual functions ------------------------------
        virtual ~CEntity();
    };
}