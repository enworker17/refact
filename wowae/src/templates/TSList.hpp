//
// TSList.hpp - template TSList
//

#pragma once

#include "TSGetExplicitLink.hpp"
#include "TSGetLink.hpp"

template<typename T, typename GetLink = TSGetLink<T> >
class TSList
{
    // functions
public:
    TSList<T, GetLink>();
    ~TSList<T, GetLink>();

    TSList<T, GetLink>(iPtr linkOffset);
    TSList<T, GetLink>(const TSList<T, GetLink>& obj);
    TSList<T, GetLink>& operator=(const TSList<T, GetLink>& obj);

    void ChangeLinkOffset(iPtr linkOffset);
    void Clear();
    void Combine(TSList<T, GetLink>* list, u32 linkType, T* existingPtr);
    bool IsEmpty();
    bool IsLinked(T* ptr);

    void LinkNode(T* ptr, u32 linkType, T* existingPtr);
    void UnlinkNode(T* ptr);
    void UnlinkAll();
    T* NewNode(u32 location, u32 extraBytes, u32 flags);
    T* DeleteNode(T* ptr);

    T* Next(T* ptr);
    T* Prev(T* ptr);
    T* RawNext(T* ptr);
    T* Head();
    T* Tail();

    const T* Next(const T* ptr) const;
    const T* Prev(const T* ptr) const;
    const T* RawNext(const T* ptr) const;
    const T* Head() const;
    const T* Tail() const;

protected:
    void SetLinkOffset(iPtr linkOffset);

private:
    void Constructor();
    void CopyConstructor(TSList<T, GetLink>& obj);
    void InitializeTerminator();
    TSLink<T>* Link(T* ptr);


    // members
protected:
    iPtr      m_linkoffset;
    TSLink<T> m_terminator;

};


// Implementation
/////////////////////////////////////////////////

template<typename T, typename GetLink>
inline TSList<T, GetLink>::TSList()
{
    Constructor();
}

template<typename T, typename GetLink>
inline TSList<T, GetLink>::~TSList()
{
    UnlinkAll();
}

template<typename T, typename GetLink>
inline TSList<T, GetLink>::TSList(iPtr linkOffset)
{
    Constructor();
    m_linkoffset = linkOffset;
}

template<typename T, typename GetLink>
inline TSList<T, GetLink>::TSList(const TSList<T, GetLink>& obj)
{
    CopyConstructor(obj);
}

template<typename T, typename GetLink>
inline TSList<T, GetLink>& TSList<T, GetLink>::operator=(const TSList<T, GetLink>& obj)
{
    CopyConstructor(obj);
    return this;
}

template<typename T, typename GetLink>
inline void TSList<T, GetLink>::ChangeLinkOffset(iPtr linkOffset)
{
    if (linkOffset != m_linkoffset)
    {
        UnlinkAll();
        SetLinkOffset(linkOffset);
    }
}

template<typename T, typename GetLink>
inline void TSList<T, GetLink>::Clear()
{
    while (true)
    {
        T* obj = m_terminator.RawNext();
        if (obj <= 0)
            break;

        delete obj;
    }
}

template<typename T, typename GetLink>
inline void TSList<T, GetLink>::Combine(TSList<T, GetLink>* list, u32 linkType, T* existingPtr)
{
    /* TODO: нужно зделать реализацию
    {
        TSList<EvtMessage,TSGetExplicitLink<EvtMessage> > *v4; // ebx
        int linkoffset; // edx
        TSLink<EvtMessage> *terminator; // eax
        TSLink<EvtMessage> *link; // ecx
        TSLink<EvtMessage> *prevlink; // edx
        EvtMessage *v9; // edi
        int v10; // ecx
        int v11; // esi
        EvtMessage *v1; // edi
        EvtMessage *next; // edx
        int v14; // edx
        int v15; // esi
        int v16; // edx

        v4 = list;
        if ( !list )
        {
            SErrPrepareAppFatal(aStormHStplH, 1939);
            SErrDisplayAppFatal(aList);
        }

        if ( list == this )
        {
            SErrPrepareAppFatal(aStormHStplH, 1940);
            SErrDisplayAppFatal(aListThis);
        }

        linkoffset = this->m_linkoffset;
        if ( list->m_linkoffset != this->m_linkoffset )
        {
            SErrPrepareAppFatal(aStormHStplH, 1941);
            SErrDisplayAppFatal(aListMLinkoffse);
        }

        terminator = &list->m_terminator;
        if ( list->m_terminator.m_prevlink != &list->m_terminator )
        {
            if ( existingptr )
                link = (TSLink<EvtMessage> *)((char *)existingptr + linkoffset);
            else
                link = &this->m_terminator;

            if ( linktype == 1 )
            {
                v1 = link->m_next;
                if ( (int)v1 > 0 )
                {
                    if ( linkoffset < 0 )
                        linkoffset = (char *)link - (char *)link->m_prevlink->m_next;

                    next = (EvtMessage *)((char *)v1 + linkoffset);
                }
                else
                {
                    next = (EvtMessage *)~(unsigned int)v1;
                }

                next->m_recycleBytes = (unsigned int)terminator->m_prevlink;
                link->m_next = list->m_terminator.m_next;
                v14 = (int)list->m_terminator.m_next;
                v15 = list->m_linkoffset;

                if ( v14 > 0 )
                {
                    if ( v15 < 0 )
                    {
                        v15 = (char *)terminator - (char *)terminator->m_prevlink->m_next;
                        v4 = list;
                    }
                    v16 = v15 + v14;
                }
                else
                {
                    v16 = ~v14;
                }

                *(_DWORD *)v16 = link;
                terminator->m_prevlink->m_next = v1;
                terminator->m_prevlink = terminator;
                v4->m_terminator.m_next = (EvtMessage *)~(unsigned int)terminator;
            }
            else
            {
                if ( linktype != 2 )
                {
                    SErrPrepareAppFatal(aStormHStplH, 1981);
                    SErrDisplayAppFatal("Invalid case: %s=%u", aLinktype, linktype);
                }

                prevlink = link->m_prevlink;
                v9 = link->m_prevlink->m_next;
                link->m_prevlink->m_next = list->m_terminator.m_next;
                link->m_prevlink = terminator->m_prevlink;
                v10 = (int)list->m_terminator.m_next;
                v11 = list->m_linkoffset;

                if ( v10 > 0 )
                {
                    if ( v11 < 0 )
                    {
                        v11 = (char *)terminator - (char *)terminator->m_prevlink->m_next;
                        v4 = list;
                    }

                    *(_DWORD *)(v11 + v10) = prevlink;
                    terminator->m_prevlink->m_next = v9;
                    terminator->m_prevlink = terminator;
                    v4->m_terminator.m_next = (EvtMessage *)~(unsigned int)terminator;
                }
                else
                {
                    *(_DWORD *)~v10 = prevlink;
                    terminator->m_prevlink->m_next = v9;
                    terminator->m_prevlink = terminator;
                    list->m_terminator.m_next = (EvtMessage *)~(unsigned int)terminator;
                }
            }
        }
    }
    */
    return;
}

template<typename T, typename GetLink>
inline bool TSList<T, GetLink>::IsEmpty()
{
    return (m_terminator.Next() == 0);
}

template<typename T, typename GetLink>
inline bool TSList<T, GetLink>::IsLinked(T* ptr)
{
    return (Link(ptr))->IsLinked();
}

template<typename T, typename GetLink>
inline TSLink<T>* TSList<T, GetLink>::Link(T* ptr)
{
    TSLink<T>* link = (ptr) ? GetLink::Link(ptr, m_linkoffset) : &m_terminator;
    return link;
}

template<typename T, typename GetLink>
inline void TSList<T, GetLink>::LinkNode(T* ptr, u32 linkType, T* existingPtr)
{
    /*
    {
        TSLink<HANDLER> *link; // eax
        TSLink<HANDLER> *v6_link; // edi
        TSLink<HANDLER> *terminator; // esi
        TSLink<HANDLER> *prevlink; // eax

        link = TSList<HANDLER,TSGetLink<HANDLER>>::Link(this, ptr);
        v6_link = link;

        if ( link->m_prevlink )
            TSLink<HANDLER>::Unlink(link);

        if ( existingptr )
            terminator = TSList<HANDLER,TSGetLink<HANDLER>>::Link(this, existingptr);
        else
            terminator = &this->m_terminator;

        if ( linktype == 1 )
        {
            v6_link->m_prevlink = terminator;
            v6_link->m_next = terminator->m_next;
            TSLink<HANDLER>::NextLink(terminator, this->m_linkoffset)->m_link.m_prevlink = v6_link;
            terminator->m_next = ptr;
        }
        else
        {
            if ( linktype != 2 )
            {
                SErrPrepareAppFatal(aHStplH, 2061);
                SErrDisplayAppFatal("Invalid case: %s=%u", aLinktype, linktype);
            }

            prevlink = terminator->m_prevlink;
            v6_link->m_prevlink = prevlink;
            v6_link->m_next = prevlink->m_next;
            prevlink->m_next = ptr;
            prevlink = v6_link;
        }
    }
    */
    TSLink<T>* link = Link(ptr);
    if (link->m_prevlink)
    {
        link->Unlink();
    }

    TSLink<T>* terminator = Link(existingPtr);
    if (linkType == 1)
    {
        link->m_prevlink = terminator->m_prevlink;
        link->m_next = terminator->m_next;
        (terminator->NextLink(m_linkoffset))->m_prevlink = link;
        terminator->m_next = ptr;
    }
    else
    {
        if (linkType != 2)
        {
            // SErrPrepareAppFatal(aHStplH, 2061);
            // SErrDisplayAppFatal("Invalid case: %s=%u", aLinktype, linktype);
            return;
        }

        TSLink<T>* prevlink = terminator->m_prevlink;
        link->m_prevlink = prevlink;
        link->m_next = prevlink->m_next;
        prevlink->m_next = ptr;
        prevlink = link;
    }
}

template<typename T, typename GetLink>
inline void TSList<T, GetLink>::UnlinkNode(T* ptr)
{
    (Link(ptr))->Unlink();
}

template<typename T, typename GetLink>
inline void TSList<T, GetLink>::UnlinkAll()
{
    /*
    {
        T* i; // eax

        for ( i = Head(); i; i = Head() )
            UnlinkNode(i);
    }
    */
    auto obj = Head();
    while (obj)
    {
        UnlinkNode(obj);
        obj = Head();
    }
}

template<typename T, typename GetLink>
inline T* TSList<T, GetLink>::NewNode(u32 location, u32 extraBytes, u32 flags)
{
    T* obj = new T; // TODO: исправить потом на свой менеджер памяти
    if (location)
    {
        LinkNode(obj, location, 0);
    }
    return obj;
}

template<typename T, typename GetLink>
inline T* TSList<T, GetLink>::DeleteNode(T* ptr)
{
    // TODO: реализация для GetLink = TSGetLink<T>, 
    // возможно потребуется отдельная для GetLink = TSGetExplicitLink<T>
    T* obj = Next(ptr);
    delete ptr;
    return obj;
}

template<typename T, typename GetLink>
inline T* TSList<T, GetLink>::Next(T* ptr)
{
    return (Link(ptr))->Next();
}

template<typename T, typename GetLink>
inline T* TSList<T, GetLink>::Prev(T* ptr)
{
    return (Link(ptr))->Prev();
}

template<typename T, typename GetLink>
inline T* TSList<T, GetLink>::RawNext(T* ptr)
{
    return (Link(ptr))->RawNext();
}

template<typename T, typename GetLink>
inline T* TSList<T, GetLink>::Head()
{
    return m_terminator.Next();
}

template<typename T, typename GetLink>
inline T* TSList<T, GetLink>::Tail()
{
    return m_terminator->Prev();
}

template<typename T, typename GetLink>
inline const T* TSList<T, GetLink>::Next(const T* ptr) const
{
    return (Link(ptr))->Next();
}

template<typename T, typename GetLink>
inline const T* TSList<T, GetLink>::Prev(const T* ptr) const
{
    return (Link(ptr))->Prev();
}

template<typename T, typename GetLink>
inline const T* TSList<T, GetLink>::RawNext(const T* ptr) const
{
    return (Link(ptr))->RawNext();
}

template<typename T, typename GetLink>
inline const T* TSList<T, GetLink>::Head() const
{
    return m_terminator.Next();
}

template<typename T, typename GetLink>
inline const T* TSList<T, GetLink>::Tail() const
{
    return m_terminator.Prev();
}

template<typename T, typename GetLink>
inline void TSList<T, GetLink>::SetLinkOffset(iPtr linkOffset)
{
    m_linkoffset = linkOffset;
    InitializeTerminator();
}

template<typename T, typename GetLink>
inline void TSList<T, GetLink>::Constructor()
{
    m_linkoffset = 0;
    InitializeTerminator();
    return;
}

template<typename T, typename GetLink>
inline void TSList<T, GetLink>::CopyConstructor(TSList<T, GetLink>& obj)
{
    m_linkoffset = obj.m_linkoffset;
    InitializeTerminator();
    return;
}

template<typename T, typename GetLink>
inline void TSList<T, GetLink>::InitializeTerminator()
{
    // m_terminator.Link(&m_terminator);
    // TODO: разобраться с доступом
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = static_cast<T*>(~static_cast<iPtr>(&m_terminator));
    return;
}

