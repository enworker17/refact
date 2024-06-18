//
// Link +
//
template<typename T>
class TSLink
{
private:
  TSLink<T>* m_prevlink;
  T* 		     m_next;

  void  Constructor() { }
  void  CopyConstructor(const TSLink<T>&) { }
  
public:
  TSLink<T>() { Constructor(); }
  ~TSLink<T>() { }
  
  TSLink<T>(const TSLink<T>& source) { CopyConstructor(sorce); }
  TSLink<T>&  operator=(const TSLink<T>& source) { CopyConstructor(source); return this; }
  
  TSLink<T>* NextLink(int linkoffset) { return nullptr; }
  void Unlink() { }
  bool IsLinked() { return false; }
  
  T* Next() { return nullptr; }
  T* Prev() { return nullptr; }
  T* RawNext() {return nullptr; }
  
  // const T* Next() {return nullptr; }
  // const T* Prev() {return nullptr; }
  // const T* RawNext() {return nullptr; }

};


//
// LinkedNode +
//
template<typename T>
class TSLinkedNode
{
private:
  TSLink<T> m_link;

public:
  TSLinkedNode<T>() { }
  ~TSLinkedNode<T>() { }
  
  TSLinkedNode<T>(TSLinkedNode<T>& source) { };
  TSLinkedNode<T>& operator=(TSLinkedNode<T>& source) { return this; }
  
  bool IsLinked() { return false; }
  void Unlink() { }
  
  T* Next() { return nullptr; }
  T* Prev() { return nullptr; }
  T* RawNext() { return nullptr; }
  
  // const T* Next() { return nullptr; }
  // const T* Prev() { return nullptr; }
  // const T* RawNext() { return nullptr; }

};


//
// GetLink +
//
template<typename T>
class TSGetLink
{
public:
  static TSLink<T>* /*__fastcall */ Link(TSLinkedNode<T>* nodeptr, int linkoffset) { return nullptr;}

};


//
// GetExplicitLink +
//
template<typename T>
class TSGetExplicitLink
{
public:
  static TSLink<T>* /*__fastcall */ Link(void* nodeptr, int linkoffset) { return nullptr;}

};


///////////////////////////////////////////////////////////////////////////////

//
// List +
//
template<typename T, typename GetLink = TSGetExplicitLink<T> >
class TSList
{
private:
  int m_linkoffset;
  TSLink<T> m_terminator;

  void Constructor() { }
  void CopyConstructor(TSList<T, GetLink>& source) { }
  void InitializeTerminator() { }
  
public:
  TSList<T, GetLink>() { Constructor(); }
  ~TSList<T, GetLink>() { }
  
  TSList<T, GetLink>(int linkoffset) { } // ????
  TSList<T, GetLink>(const TSList<T, GetLink>& source) { CopyConstructor(source); }
  TSList<T, GetLink>& operator=(const TSList<T, GetLink>& source) { CopyConstructor(source); return this; }
  
  void SetLinkOffset(int linkoffset) { }
  void ChangeLinkOffset(int linkoffset) { }
  void Clear() { }
  void Combine(TSList<T, GetLink>* list, unsigned long linktype, T* existingptr) { }
  bool IsEmpty() {return false; }
  bool IsLinked(T* ptr) {return false; }
  
  TSLink<T>* Link(T* ptr) { return nullptr; }
  void LinkNode(T* ptr, unsigned long linktype, T* existingptr) { }
  void UnlinkNode(T* ptr) { }
  void UnlinkAll() { }
  T* NewNode(unsigned long location, unsigned long extrabytes, unsigned long flags) { return nullptr; }
  T* DeleteNode(T* ptr) { return nullptr; }
  
  T* Next(T* ptr) { return nullptr; }
  T* Prev(T* ptr) { return nullptr; }
  T* RawNext(T* ptr) { return nullptr; }
  T* Head() { return nullptr; }
  T* Tail() { return nullptr; }
  // const T* Next(T* ptr) { return nullptr; }
  // const T* Prev(T* ptr) { return nullptr; }
  // const T* RawNext(T* ptr) { return nullptr; }
  // const T* Head() { return nullptr; }
  // const T* Tail() { return nullptr; }

};


//
// ExplicitList +
//
template<typename T, unsigned int iP>
class TSExplicitList : public TSList<T,TSGetExplicitLink<T> >  
{
public:
  TSExplicitList<T, iP>() { }
  ~TSExplicitList<T, iP>() { }
  
  TSExplicitList<T,iP>(const TSExplicitList<T, iP>& source) { }
  TSExplicitList<T,iP>& operator=(const TSExplicitList<T, iP>& source) { return this; }

};


//
// ListWinHeap +
//
template<typename T, typename GetLink = TSGetLink<T> >
class TSListWinHeap : public TSList<T, GetLink> 
{
public:
  TSListWinHeap<T, GetLink>() { }
  ~TSListWinHeap<T, GetLink>() { }
  
  TSListWinHeap<T, GetLink>(const TSListWinHeap<T, GetLink>& source) { }
  TSListWinHeap<T, GetLink>& operator=(const TSListWinHeap<T, GetLink>& source) { return this; }
  
  T* NewNode(unsigned long location, unsigned long extrabytes, unsigned long flags) { return nullptr; }
  T* DeleteNode(T* ptr) { return nullptr; }

};


///////////////////////////////////////////////////////////////////////////////

//
// StackArray +
//
template<typename T>
class TSStackArray
{
private:
  unsigned int m_maxCount;
  unsigned int m_count;
  T* m_data;

  void FatalArrayBounds() { }
  
  
public:
  TSStackArray<T>(void* ptr, unsigned int maxCount, int count) { }
  ~TSStackArray<T>() { }
  
  TSStackArray<T>& operator=(const TSStackArray<T>& source) { return this; }
  T& operator[](const unsigned int index) { return m_data[index]; }
  //const T& operator[](const unsigned int index) { return m_data[index]; }
  
  T* Ptr() { return nullptr; }
  //const T* Ptr() { return nullptr; }
  T* New(const T& source) { return nullptr; }
  T* New() { return nullptr; }
  
  void Zero() { }
  void SetCount(unsigned int count) { }
  unsigned int Count() { return m_count; }
  unsigned int Bytes() { return (m_maxCount * sizeof(T)); }
  unsigned int SizeOfElement() { return sizeof(T); }
  
  void Set(unsigned int count, int index, T* source) { }
  void Set(unsigned int count, T* source) { }
  void Add(unsigned int count, int index, T* source) { }
  void Add(unsigned int count, T* source) { }

};


//
// Array +
//
template<typename T, size_t Size>
class TSCArray
{
protected:
  unsigned int m_count;
  T m_data[Size];

  void FatalArrayBounds() { }
  
  
public:  
  TSCArray<T, Size>() { }
  ~TSCArray<T, Size>() { }
  
  TSCArray<T, Size>(const TSCArray<T, Size>& source) { }
  TSCArray<T, Size>& operator=(const TSCArray<T, Size>& source) { return this; }
  T& operator[](const unsigned int index) { return m_data[index]; }
  //const T& operator[](const unsigned int index);
  
  T* Ptr() { return nullptr; }
  // const T* Ptr();
  
  void Set(unsigned int count, int index, T* source) { }
  void Set(unsigned int count, T* source) { }
  void SetCount(unsigned int count) { }
  void Zero() { }
  
  unsigned int MaxCount() { return Size; }
  unsigned int Count() { return m_count; }
  unsigned int Bytes() { return sizeof(m_data); }
  unsigned int SizeOfElement() { return sizeof(T); }
  
  // char* MemFileName();	??
  // int MemLineNo();		??

};


//
// BaseArray +
//
template<typename T>
class TSBaseArray
{
protected:
  unsigned int m_alloc;
  unsigned int m_count;
  T*           m_data;

  void Constructor() { }
  void CheckArrayBounds(unsigned int index) { }

public:  
  TSBaseArray<T>() { }
  
  TSBaseArray<T>(const TSBaseArray<T>& source) { }
  TSBaseArray<T>& operator=(const TSBaseArray<T>& source) { return this; }
  T& operator[](const unsigned int index) { return m_data[index]; }
  // const T& operator[](const unsigned int index) { return m_data[index]; }
  
  T* Ptr() { return nullptr; }
  T* Top() { return nullptr; }

  // const T* Ptr() { return nullptr; }
  // const T* Top() { return nullptr; }
  
  unsigned int Count() { return m_count; }
  unsigned int Bytes() { return (m_alloc * sizeof(T)); }
  unsigned int SizeOfElement() { return sizeof(T); }
  unsigned int NumElements() { return m_alloc; }

  // virtual functions ------------- for wowae only -----------------
  // virtual char*  MemFileName();
  // virtual int  MemLineNo();
};


//
// FixedArray +
// TODO: нужно разобраться!!!
//
template<typename T>
class TSFixedArray : public TSBaseArray<T>
{
public:
  TSFixedArray<T>() { }
  ~TSFixedArray<T>() { }
  
  TSFixedArray<T>(const TSBaseArray<T>& source) { }
  TSFixedArray<T>(const TSFixedArray<T>& source) { }
  TSFixedArray<T>& operator=(const TSBaseArray<T>& source) { return this; }
  TSFixedArray<T>& operator=(const TSFixedArray<T>& source) { return this; }
  
  void ReallocAndClearData(unsigned int maxCount) { }
  void ReallocData(unsigned int maxCount) { }
  void Clear() { }
  void Detach(T**, unsigned int*, unsigned int*) { }
  void Exchange(TSFixedArray<T>* source) { }
  void Set(unsigned int count, int index, T* data) { }
  void Set(unsigned int count, T* data) { }
  void SetCount(unsigned int count) { }
  void SetOptional(unsigned int index, T* data) { }
  void Zero() { }

  // virtual functions ------------- for wowae only -----------------
  // virtual char*  MemFileName();
  // virtual int  MemLineNo();
};


//
// FixedArray_ + TODO: разобраться с числами U и W. Возможно не typename, а size_t.
//
template<typename T, typename U, typename W>
class TSFixedArray_ : public TSFixedArray<T>
{
private:
  static char s_name[5];

public:
  TSFixedArray_<T, U, W>() { }
  ~TSFixedArray_<T, U, W>() {}
  
  TSFixedArray_<T, U, W>(TSFixedArray_<T, U, W>& source) {}
  TSFixedArray_<T, U, W>& operator=(const TSFixedArray_<T, U, W>& source) { return this;}
  TSFixedArray_<T, U, W>& operator=(const TSFixedArray<T>& source) { return this; }

  // virtual functions ------------- for wowae only -----------------
  // virtual char*  MemFileName();
  // virtual int  MemLineNo();
};


//
// GrowableArray + TODO: разобраться
//
template<typename T>
class TSGrowableArray : public TSFixedArray<T>  
{
private:
  unsigned int m_chunk;

public:
  TSGrowableArray<T>() { }
  ~TSGrowableArray<T>() { }
  
  TSGrowableArray<T>(TSGrowableArray<T>&) { }
  TSGrowableArray<T>& operator=(TSGrowableArray<T>&) { return this; }
  
  T* New(T& data) { return nullptr; }
  T* New() { return nullptr; }
  T* NewElement() { return nullptr; }
  
  unsigned int Add(T* data) { return 0; }
  unsigned int Add(unsigned int count, int index, T* data) { return 0; }
  unsigned int Add(unsigned int count, T* data) { return 0; }
  unsigned int AddElement(T* data) { return 0; }
  unsigned int AddElements(unsigned int count, T* data) { return 0; }
  unsigned int Reserved() { return 0; }
  unsigned int CalcChunkSize(unsigned int count) { return 0; }
  unsigned int RoundToChunk(unsigned int count, unsigned int chunk) { return 0; }

  void Reserve(unsigned int count, int round) { }
  void GrowToFit(unsigned int count, int size) { }
  void ReserveSpace(unsigned int size) { }
  void SetChunkSize(unsigned int size) { }
  void SetCount(unsigned int count) { }
  void TrimUnusedSpace() { }
  void SetNumElements(unsigned int size) { }

  // virtual functions ------------- for wowae only -----------------
  // virtual char*  MemFileName();
  // virtual int  MemLineNo();
};


//
// GrowableArray_ +  TODO: разобраться с U и W
//
template<typename T, typename U, typename W>
class TSGrowableArray_ : public TSGrowableArray<T>  
{
private:
  static char s_name[5];

public:
  TSGrowableArray_<T, U, W>() { }
  ~TSGrowableArray_<T, U, W>() { }
  
  TSGrowableArray_<T, U, W>(const TSGrowableArray_<T, U, W>& source) { }
  TSGrowableArray_<T, U, W>& operator=(const TSGrowableArray_<T, U, W>& source) { return this; }
  TSGrowableArray_<T, U, W>& operator=(const TSGrowableArray<T>& source) { return this; }

  // virtual functions ------------- for wowae only -----------------
  // virtual char*  MemFileName();
  // virtual int  MemLineNo();
};



//
// CArray +
//
template<typename T>
class CArray
{
private:
  T*           m_data;
  unsigned int m_count;

public:
  CArray<T>() { }
  ~CArray<T>() { }
  
  CArray<T>(const CArray<T>& source) { }
  CArray<T>& operator=(const TSFixedArray<T>& source) { return this; }
  CArray<T>& operator=(const CArray<T>& source) { return this; }
  T& operator[](unsigned int index) { return m_data[index]; }
  // const T& operator[](unsigned int index) { return m_data[index]; }
  
  T* New() { return nullptr; }
  T* Ptr() { return m_data; }

  // const T* Ptr() { return m_data; }

  void Exchange(TSGrowableArray<T>* pArray) { }
  void ReserveSpace(unsigned int elements) { }
  void Zero() { }
  unsigned int Count() { return m_count; }
  unsigned int Bytes() { return (m_count * sizeof(T)); }
  void Clear() { }
  void SetCount(unsigned int count) { }
  void Set(unsigned int index, T* source) { }

};



///////////////////////////////////////////////////////////////////////////////

//
// HashObject +
//
template<typename T, typename U>
class TSHashObject
{
private:
  unsigned int m_hashval;
  TSLink<T> m_linktoslot;
  TSLink<T> m_linktofull;
  U m_key;

public:
  TSHashObject<T,U>() { }
  ~TSHashObject<T,U>() { }
  
  TSHashObject<T,U>(TSHashObject<T,U>&) { }
  TSHashObject<T,U>& operator=(TSHashObject<T,U>&) { return this; }
  
  U GetKey() { return m_key; }
  void* GetData() { return nullptr; }
  char* GetString() { return nullptr; }
  unsigned int  GetHashValue() { return m_hashval; }

};


//
// HashObjectChunk +
//
template<typename T, typename U>
class TSHashObjectChunk
{
private:
  TSGrowableArray<T>               m_array;
  TSLink<TSHashObjectChunk<T,U> >  m_link;

public:
  TSHashObjectChunk<T,U>() { }
  ~TSHashObjectChunk<T,U>() { }
  
  TSHashObjectChunk<T,U>(const TSHashObjectChunk<T,U>& source) { }
  TSHashObjectChunk<T,U>& operator=(const TSHashObjectChunk<T,U>& source) { return this; }

};


//
// TSHashTable +
//
template<typename T, typename U>
class TSHashTable
{
protected:
  TSExplicitList<T, 0xDDDDDDDD>                   m_fulllist;
  unsigned int                                    m_fullnessIndicator;
  TSGrowableArray<TSExplicitList<T, 0xDDDDDDDD> > m_slotlistarray;
  unsigned int                                    m_slotmask;


public:
  // static functions -------------------------------
  static unsigned int /* __fastcall */ Hash(char*) { return 0; }

  // non-virtual functions --------------------------
  TSHashTable<T,U>() { }
  
  TSHashTable<T,U>(TSHashTable<T,U>&) { }
  TSHashTable<T,U>& operator=(TSHashTable<T,U>&) { return this; }
  
  unsigned int ComputeSlot(unsigned int) { return 0; }
  void GrowListArray(unsigned int newarraysize) { }
  void Initialize() { }
  int Initialized() { return 0; }
  void InternalClear(int warn) { }
  int MonitorFullness(unsigned int slot) { return 0; }
  void InternalLinkNode(T* ptr, unsigned int hashval) { }
  TSHashTable<T,U>& NonConst() { return nullptr; }
  int GetLinkOffset() { return 0; }
  void Clear() { }
  void Delete(char*) { }
  void Delete(unsigned int, char*) { }
  void Delete(unsigned int, U&) { }
  void Delete(T* ptr) { }
  void Insert(T*, char*) { }
  void Insert(T*, unsigned int, char*) { }
  void Insert(T*, unsigned int, U&) { }
  T* InternalNewNode(unsigned int hashval, unsigned long extrabytes, unsigned long flags) { return nullptr; }
  T* DeleteNode(T*) { return nullptr; }
  T* New(char*, unsigned long, unsigned long) { return nullptr; }
  T* New(unsigned int hashval, char* str, unsigned long extrabytes, unsigned long flags) { return nullptr; }
  T* New(unsigned int, U&, unsigned long, unsigned long) { return nullptr; }
  T* Next(T*) { return nullptr; }
  T* Prev(T*) { return nullptr; }
  T* Ptr(char*) { return nullptr; }
  T* Ptr(unsigned int, char*) { return nullptr; }
  T* Ptr(unsigned int, U&) { return nullptr; }
  T* RawNext(T*) { return nullptr; }
  T* Head() { return nullptr; }
  T* Tail() { return nullptr; }

  // const T* Next(T*) { return nullptr; }
  // const T* Prev(T*) { return nullptr; }
  // const T* Ptr(char* str) { return nullptr; }
  // const T* Ptr(unsigned int, char*) { return nullptr; }
  // const T* Ptr(unsigned int hashval, U& key) { return nullptr; }
  // const T* RawNext(T*) { return nullptr; }
  // const T* Head() { return nullptr; }
  // const T* Tail() { return nullptr; }

  void Unlink(T*) { }
  void SetTableSize(unsigned int) { }
  float GetAverageBinDepth() { return 0.0f; }
  unsigned int GetPeakBinDepth() { return 0; }

  // virtual functions ------------------------------
  virtual void InternalDelete(T* ptr) { }
  virtual T* InternalNew(TSExplicitList<T, 0xDDDDDDDD>* listptr, unsigned long extrabytes, unsigned long flags) { return nullptr; }
  virtual ~TSHashTable<T,U>() { }
  virtual void Destroy() { }
};


//
// TSHashTableReuse +
//
template<typename T, typename U, int iP = 1>
class TSHashTableReuse : public TSHashTable<T, U>
{
protected:
  TSExplicitList<T, 0xDDDDDDDD>               m_reuseList;
  unsigned long                               m_chunkSize;
  TSExplicitList<TSHashObjectChunk<T, U>, 20> m_chunkList;

public:
  // non-virtual functions --------------------------
  TSHashTableReuse<T,U,iP>() { }
  
  TSHashTableReuse<T,U,iP>(TSHashTableReuse<T,U,iP>&) { }
  TSHashTableReuse<T,U,iP>& operator=(TSHashTableReuse<T,U,iP>&) { return this; }
  
  void Destructor() { }


  // virtual functions ------------------------------
  virtual void InternalDelete(T* ptr) { }
  virtual T* InternalNew(TSExplicitList<T,0xDDDDDDDD>* listptr, unsigned long extrabytes, unsigned long flags) { return nullptr; }
  virtual ~TSHashTableReuse<T,U,iP>() { }
  virtual void Destroy() { }
};



//////////////////////////////////////////////////////////////////////////////

// TODO: разобраться с синтаксисом

//
// DBCache 
//

class CHashKeyGUID;
struct NETMESSAGE;
struct DBCACHECALLBACK;
class CGContainer_C;
class CGPlayer_C;
class CDataStore;

template<typename T, typename U, typename W>
class DBCache
{
  struct DBCACHEHASH : public TSHashObject<DBCache<T, U, W>::DBCACHEHASH, CHashKeyGUID>
  {
    T m_record;
    U m_dbkey;
    unsigned char m_haveData;
    TSList<DBCACHECALLBACK,TSGetLink<DBCACHECALLBACK> > m_callbacks;
    unsigned char m_temp;
    
    DBCACHEHASH() { }
    ~DBCACHEHASH() { }
    
    DBCACHEHASH& operator=(DBCACHEHASH& ) { return this; }
  };
	
protected:
  TSHashTable<DBCache<T, U, W>::DBCACHEHASH, W> m_table;
  unsigned long m_fileTag;
  char* m_fileName;
  // NETMESSAGE m_singleQueryMsg;
  // NETMESSAGE m_multiQueryMsg;
  unsigned char m_requireGuids;
  unsigned char m_persistent;

public:
  ~DBCache<T, U, W>() { }
  DBCache<T, U, W>(unsigned long fileTag, char* fileName, NETMESSAGE singleQuery, NETMESSAGE multiQuery, unsigned char requireGuids, unsigned char persistent) { }
  DBCache<T, U, W>(DBCache<T, U, W>&) { }
  DBCache<T, U, W>& operator=(DBCache<T, U, W>&) { return this; }
  
  T* GetRecord(U id, unsigned __int64& guid, void  (*cb)(int, unsigned __int64&, void*, unsigned char), void* cbArg) { return nullptr; }
  void VerifyPack(CGContainer_C* container, void  (*callback)(int, unsigned __int64&, void*, unsigned char), void* arg) { }
  void VerifyCache(CGPlayer_C* player, void  (*callback)(int, unsigned __int64&, void*, unsigned char), void* arg) { }
  void AddItem(T* item, U key) { }
  void AddItems(CDataStore* msg, unsigned char single) { }
  void DenyItem(U key) { }
  void CancelCallback(U id, void (*cb)(int, unsigned __int64&, void*, unsigned char), void* cbArg) { }
  void Load() { }
  void Save() { }
  void Clear() { }
  void Invalidate(U id) { }
  void SetTemporary(U id) { }

};


//
// WowClientDB
//
template<typename T>
class WowClientDB
{
private:
  T* m_records;
  int m_numRecords;
  T** m_recordsById;
  int m_maxID;
  int m_loaded;

public:
  WowClientDB<T>() { }
  ~WowClientDB<T>() { }
  
  T* GetRecord(int) { return nullptr; }
  T* GetRecordByIndex(int) { return nullptr; }
  
  void Load() { }
  void Reload() { }
  void Unload() { }
  void Free() { }
  void Init() { }
  int GetMaxID() { return 0; }
  int GetNumRecords() { return 0; }

};



///////////////////////////////////////////////////////////////////////////////

// TODO: включить нужный заголовочный файл
class CDebugSCritSect;
class CInitCritSect;
struct CDebugLockData;
struct CDebugLockEntry;

//
// CDebugLock
//
template<typename T = CDebugSCritSect>
class CDebugLock : public T  
{
private:
  // static data ------------------------------------
  static CInitCritSect s_critsect;
  static CDebugLockData* s_locks;
  static CDebugLockEntry s_entries[256];
  static unsigned long s_freeEntries;
  
public:
  ~CDebugLock<T>() { }
  
  CDebugLock<T>(CDebugLock<T>&) { }
  CDebugLock<T>&  operator=(CDebugLock<T>&) { return this; }

  // static functions -------------------------------
  static void /* __fastcall */ Construct(CDebugLockData* lock) { }
  static void /* __fastcall */ Destruct(CDebugLockData* lock) { }
  static void /* __fastcall */ IEnter() { }
  static void /* __fastcall */ ILeave() { }
  static void /* __fastcall */ IDumpAllEntries() { }
  static void /* __fastcall */ IDumpEntries(CDebugLockData* lock) { }
  static void /* __fastcall */ IEnterEntry(unsigned long e) { }
  static void /* __fastcall */ IRepairBadEntry(CDebugLockData* lock, unsigned long e, CDebugLockEntry* eptr, char* fileName, unsigned long line) { }
  static unsigned long /* __fastcall */ IClashingEntry(struct CDebugLockData*, unsigned long, int) { return 0; }
  static unsigned long /* __fastcall */ IAddEntry(CDebugLockData* lock, unsigned long threadId, int forwriting, char* fileName, unsigned long line) { return 0; }
  static unsigned long /* __fastcall */ IDeleteEntry(CDebugLockData* lock, unsigned long threadId, int fromwriting) { return 0; }

};



///////////////////////////////////////////////////////////////////////////////

//
// CLinearKeyFrame
//

class CKeyFrame;

template<typename T>
struct CLinearKeyFrame: public CKeyFrame 
{

  T transform;

  CLinearKeyFrame<T>() { }
  ~CLinearKeyFrame<T>() { }
  
  CLinearKeyFrame<T>(CLinearKeyFrame<T>&) { }
  CLinearKeyFrame<T>& operator=(CLinearKeyFrame<T>&) { return this; }

};


//
// CSplineKeyFrame
//
template<typename T>
struct CSplineKeyFrame : public CLinearKeyFrame<T>  
{
  T inTan;
  T outTan;

  CSplineKeyFrame<T>() { }
  ~CSplineKeyFrame<T>() { }
  
  CSplineKeyFrame<T>(CSplineKeyFrame<T>&) { }
  CSplineKeyFrame<T>& operator=(CSplineKeyFrame<T>&) { return this; }

};


//
// CKeyFrameTrack
//

struct InterpInfo;
class CBaseStatus;
class CKeyTrackStatus;
struct KEYTYPE;

template<typename T, typename U>
class CKeyFrameTrack : public CKeyFrameTrackBase  {
private:
  KEYTYPE m_trackType;

public:
  CKeyFrameTrack<T,U>() { }
  ~CKeyFrameTrack<T,U>() { }
  
  CKeyFrameTrack<T,U>(CKeyFrameTrack<T,U>&) { }
  CKeyFrameTrack<T,U>& operator=(CKeyFrameTrack<T,U>&) { return this; }
  
  void SetTrackType(KEYTYPE) { }
  void SetNumKeys(unsigned int numKeys) { }
  void AddKey(int time, U& keydata) { }
  void AddKey(int time, U& keydata, U& inTan, U& outTan) { }
  int InterpolateVolatile(InterpInfo&, CBaseStatus&, CKeyTrackStatus*, U&, U*) { return 0; }
  int InterpolateRetained(InterpInfo&, CBaseStatus&, CKeyTrackStatus*, U&, U*) { return 0; }
  unsigned int Bytes() { return 0; }
  KEYTYPE GetTrackType() { return 0; }
  CLinearKeyFrame<T>* GetLinearKey(unsigned int index) { return nullptr; }
  CLinearKeyFrame<T>* ToLinearKey(CKeyFrame*) { return nullptr; }
  CLinearKeyFrame<T>* ToLinearKey(CKeyFrame*) { return nullptr; }
  CSplineKeyFrame<T>* ToSplineKey(CKeyFrame*) { return nullptr; }
  CSplineKeyFrame<T>* ToSplineKey(CKeyFrame*) { return nullptr; }
  CSplineKeyFrame<T>* GetSplineKey(unsigned int index);
  int InterpolateVolatileFewKeys(CKeyTrackStatus& keyStat, U* transform) { return 0; }
  int InterpolateRetainedFewKeys(CKeyTrackStatus&, U*) { return 0; }
  void Interpolate(CKeyTrackStatus& keyStat, unsigned int seqTime, U* transform) { }
  void InterpolateHermite(CSplineKeyFrame<T>& currkey, CSplineKeyFrame<T>& nextkey, float ratio, U* transform) { }
  void InterpolateBezier(CSplineKeyFrame<T>& __formal, CSplineKeyFrame<T>& __formal, float __formal, U* __formal) { }
  void InterpolateLinear(CLinearKeyFrame<T>& currkey, CLinearKeyFrame<T>& nextkey, float ratio, U* transform) { }

};



///////////////////////////////////////////////////////////////////////////////

//
// TInstanceId
//
template<typename T>
class TInstanceId : public TSLinkedNode<T>  
{
private:
  unsigned long m_id;

public:
  // non-virtual functions --------------------------
  TInstanceId<T>() { }
  
  TInstanceId<T>( TInstanceId<T>&) { }
  TInstanceId<T>& operator=(TInstanceId<T>&) { return this; }
  
  void SetId(unsigned long id) { m_id = id; }
  unsigned long Id() { return m_id; }

  // virtual functions ------------------------------
  virtual ~TInstanceId<T>() { }
};


//
// TInstanceIdTable
//

class SCritSect;
class CSRWLock;
struct INSTANCELOCK__;

template<typename T, int iP>
class TInstanceIdTable 
{

	class Iterator {
	private:
	  TInstanceIdTable<T, iP>& m_table;
	  int m_slot;
	  T* m_next;

	public:
	  Iterator(TInstanceIdTable<T,iP>&) { }
	  
	  Iterator(Iterator&) { }
	  Iterator& operator=(Iterator&) { return this; }
	  
	  T* Next(int) { return nullptr; }
	  T* SlotNext() { return nullptr; }
	  void SetSlot(int, int) { }
	  void SlotBegin(int) { }
	  void SlotEnd(int) { }

	};


private:
  SCritSect m_idCritsect;
  unsigned long m_id;
  int m_idWrapped;
  CSRWLock m_idLock[iP];
  TSList<T,TSGetLink<T> > m_idList[iP];

public:
  // static functions -------------------------------
  static int __fastcall Slots() { return 0; }

  // non-virtual functions --------------------------
  TInstanceIdTable<T,iP>() { }
  ~TInstanceIdTable<T,iP>() { }
 
  TInstanceIdTable<T,iP>(TInstanceIdTable<T,iP>&) { }
  TInstanceIdTable<T,iP>& operator=(TInstanceIdTable<T,iP>&) { return this; }
  
  unsigned long Link(T* ptr) { return 0; }
  void Unlink(T* ptr) { }
  T* Lock(unsigned long, int, INSTANCELOCK__*&, char*, unsigned long) { return nullptr; }
  void Unlock(INSTANCELOCK__*, char*, unsigned long) { }

};



//
// TSingletonInstanceId
//
template<typename T, int iP>
class TSingletonInstanceId : public TInstanceId<T>  
{
private:
  // static data ------------------------------------
  static TInstanceIdTable<T,iP> s_idTable;

public:
  // static functions -------------------------------
  static  TInstanceIdTable<T,iP>& __fastcall GetTable() { return s_idTable; }

  // non-virtual functions --------------------------
  TSingletonInstanceId<T,iP>() { }
  
  TSingletonInstanceId<T,iP>(TSingletonInstanceId<T,iP>&) { }
  TSingletonInstanceId<T,iP>& operator=(TSingletonInstanceId<T,iP>&) { return this; }

  // virtual functions ------------------------------
  virtual ~TSingletonInstanceId<T,iP>() { }
};



///////////////////////////////////////////////////////////////////////////////

//
// TManaged
//

class CBaseManaged;

template<typename T>
class TManaged : CBaseManaged  
{
private:
  T m_data;

public:
  // non-virtual functions --------------------------
  TManaged<T>() { }
  TManaged<T>(T&) { }
  TManaged<T>(TManaged<T>&) { }
  TManaged<T>& operator=(TManaged<T>&) { return this; }
  
  TManaged<T>& operator+=(T&) { return this; }
  TManaged<T>& operator-=(T&) { return this; }
  TManaged<T>& operator*=(T&) { return this; }
  TManaged<T>& operator/=(T&) { return this; }
  
  T& Get() { return m_data; }
  void Set(T& source) { }

  // virtual functions ------------------------------
  virtual void  Set_(T&) { }
  virtual void  Update(float) { }
  virtual void  UpdateR(float) { }
  
  virtual ~TManaged<T>() { }
 
 };



///////////////////////////////////////////////////////////////////////////////

//
// TRefCntPtr
//
template<typename T>
class TRefCntPtr 
{
private:
  T* m_ptr;

public:
  TRefCntPtr<T>(T* ptr) { }
  ~TRefCntPtr<T>() { }
  
  TRefCntPtr<T>( TRefCntPtr<T>&) { }
  TRefCntPtr<T>& operator=(T*) { return this; }
  TRefCntPtr<T>& operator=(TRefCntPtr<T>&) {return this; }
  
  T& operator*() { return nullptr; }
  T* operator->() { return nullptr; }
  // const T& operator*() { return nullptr; }
  // const T* operator->() { return nullptr; }

  unsigned char operator==(T*) { return 0; }
  unsigned char operator==(TRefCntPtr<T>&) { return 0; }
  unsigned char operator!=(T*) { return 0; }
  unsigned char operator!=(TRefCntPtr<T>&) { return 0; }
  unsigned char operator!() { return 0; }

  T* operator T *() { return nullptr; }
  const T* operator const T *() { return nullptr; }

};



///////////////////////////////////////////////////////////////////////////////

//
// TSExportTableSimple
//

struct HASHKEY_NONE;

template<typename T, typename U, int iP>
class TSExportTableSimple : public TSHashTableReuse<T, HASHKEY_NONE, iP>  
{
protected:
  HASHKEY_NONE m_key;
  unsigned int m_sequence;
  int m_wrapped;

public:
  TSExportTableSimple<T, U, iP>() { }
  TSExportTableSimple<T, U, iP>(TSExportTableSimple<T, U, iP>&) { }
  TSExportTableSimple<T, U, iP>& operator=(TSExportTableSimple<T, U, iP>&) { return this; }
  
  U* GenerateUniqueHandle() { return nullptr; }
  
  void Delete(U*) { }
  void Delete(T* ptr) { }
  T* New(U** handle) { return nullptr; }
  T* Ptr(U* handle) { return nullptr; }

  // virtual functions ------------------------------
  virtual ~TSExportTableSimple<T, U, iP>() { }

};


//
// TSExportTableSync
//

class CCritSect;

template<typename T, typename U, typename W, typename CritSect = CCritSect, int iP = 1>
class TSExportTableSync : public TSExportTableSimple<T, U, iP>  
{
private:
  CritSect m_sync;

public:
  // non-virtual functions --------------------------
  TSExportTableSync<T, U, W, CritSect, iP>() { }
  TSExportTableSync<T, U, W, CritSect, iP>( TSExportTableSync<T, U, W, CritSect, iP>&) { }
  TSExportTableSync<T, U, W, CritSect, iP>& operator=(TSExportTableSync<T, U, W, CritSect, iP>&) { return this; }
  
  int IsForWriting(W* lockedhandle) { return 0; }
  void New(struct U**) { }
  void SyncEnterLock(W** lockedhandle, int forwriting) { }
  void SyncLeaveLock(W* lockedhandle) { }
  void Unlock(W* lockedhandle) { }
  void DeleteUnlock(T* ptr, W* lockedhandle) { }
  void Delete(U* handle) { }
  
  T* Lock(U* handle, W** lockedhandle, int forwriting) { return nullptr; }
  T* NewLock(U** handle, W** lockedhandle) { return nullptr; }

  // virtual functions ------------------------------
  virtual ~TSExportTableSync<T, U, W,CritSect,iP>() { }

};



///////////////////////////////////////////////////////////////////////////////

//
// TSPriorityQueue
//

class CSBasePriorityQueue;

template<typename T>
class TSPriorityQueue : public CSBasePriorityQueue  {
public:
  TSPriorityQueue<T>(int linkOffset) { }
  ~TSPriorityQueue<T>() { }
  
  TSPriorityQueue<T>(TSPriorityQueue<T>&) { }
  TSPriorityQueue<T>& operator=(TSPriorityQueue<T>&) { return this; }
  
  T* operator[](unsigned int) { return nullptr; }
  T* operator[](unsigned int) { return nullptr; }
  
  T* Root() { return nullptr; }
  T* Dequeue() { return nullptr; }
  void Enqueue(T*) { }
  void Remove(unsigned int) { }

};


//
// TSTimerPriority
//

class CSBasePriority;

template<typename T>
class TSTimerPriority : public CSBasePriority  {
private:
  T m_val;

public:
  TSTimerPriority<T>() { }
  ~TSTimerPriority<T>() { }
  
  TSTimerPriority<T>(TSTimerPriority<T>&) { }
  TSTimerPriority<T>& operator=(TSTimerPriority<T>&) { return this; }
  
  T Get() { return m_val; }
  void Set(T val) { m_val = val; }

  // virtual functions ------------------------------
  virtual int Compare(CSBasePriority* a) { return 0; }
};



///////////////////////////////////////////////////////////////////////////////

//
// TSSwap
//
template<typename T>
void __fastcall TSSwap(T& a, T& b)
{
	return;
}
