//
// TSHashTableReuse.hpp - template TSHashTableReuse
//

#pragma once

#include "TSHashTable.hpp"
#include "TSHashObjectChunk.hpp"

template<typename T, typename U, int iP = 1>
class TSHashTableReuse : public TSHashTable<T, U>
{
protected:
    TSExplicitList<T, ((int)0xDDDDDDDD)>        m_reuseList;
    unsigned long                               m_chunkSize;
    TSExplicitList<TSHashObjectChunk<T, U>, 20> m_chunkList;

public:
    // non-virtual functions --------------------------
    TSHashTableReuse<T, U, iP>();

    TSHashTableReuse<T, U, iP>(TSHashTableReuse<T, U, iP>&);
    TSHashTableReuse<T, U, iP>& operator=(TSHashTableReuse<T, U, iP>&);

    void Destructor();


    // virtual functions ------------------------------
    virtual void InternalDelete(T* ptr);
    virtual T* InternalNew(TSExplicitList<T, ((int)0xDDDDDDDD)>* listptr, unsigned long extrabytes, unsigned long flags);
    virtual ~TSHashTableReuse<T, U, iP>();
    virtual void Destroy();
};

