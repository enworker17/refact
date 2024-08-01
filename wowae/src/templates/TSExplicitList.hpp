//
// TSExplicitList.hpp - template TSExplicitList
//

#pragma once

#include "TSList.hpp"

template<typename T, int iP>
class TSExplicitList : public TSList<T, TSGetExplicitLink<T> >
{
public:
    TSExplicitList<T, iP>()
    {
        SetLinkOffset(iP);
        return;
    }

    ~TSExplicitList<T, iP>()
    {
        return;
    }

    TSExplicitList(const TSExplicitList<T, iP>& obj) : TSList<T, TSGetExplicitLink<T> >(obj)
    {
        return;
    }

    TSExplicitList<T, iP>& operator=(const TSExplicitList<T, iP>& obj)
    {
        this->m_linkoffset = obj.m_linkoffset;
        this->m_terminator = obj.m_terminator;
        return this;
    }

};

