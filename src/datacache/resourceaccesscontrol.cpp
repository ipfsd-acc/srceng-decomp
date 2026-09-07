// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: datacache/resourceaccesscontrol.cpp
// Functions: 14
// ============================================================

#include "datacache\resourceaccesscontrol.h"

//------------------------------------------------------------------------------
// Address: 0x100107D0
// Name: private: int CResourceAccessControl::FindOrAddCurrentThreadID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CResourceAccessControl::FindOrAddCurrentThreadID(CResourceAccessControl *this)
{
  DWORD CurrentThreadId; // eax
  int m_nThreadCount; // edx
  unsigned int v4; // edi
  int result; // eax
  unsigned int *m_pThread; // ecx
  int v7; // ebx

  CurrentThreadId = GetCurrentThreadId();
  m_nThreadCount = this->m_nThreadCount;
  v4 = CurrentThreadId;
  result = 0;
  if ( m_nThreadCount <= 0 )
  {
LABEL_5:
    if ( m_nThreadCount < 16 )
    {
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
      v7 = this->m_nThreadCount;
      this->m_pThread[v7] = v4;
      ++this->m_nThreadCount;
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
      return v7;
    }
    else
    {
      _Error(a1: "Exceeded maximum number of unique threads (%d) attempting to access datacache.\n", 16);
      return -1;
    }
  }
  else
  {
    m_pThread = this->m_pThread;
    while ( *m_pThread != v4 )
    {
      ++result;
      ++m_pThread;
      if ( result >= m_nThreadCount )
        goto LABEL_5;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010850
// Name: public: virtual void CResourceAccessControl::LimitAccess(struct ResourceList_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceAccessControl::LimitAccess(
        CResourceAccessControl *this,
        struct ResourceList_t__ *hResourceList)
{
  int v3; // eax

  if ( res_restrict_access.m_pParent != nullptr && res_restrict_access.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = CResourceAccessControl::FindOrAddCurrentThreadID(this);
    if ( this->m_pLimitAccess[v3] < 0 || hResourceList == (struct ResourceList_t__ *)-1 )
      this->m_pLimitAccess[v3] = (int)hResourceList;
    else
      _Warning(a1: "Attempted to limit access while already limiting access!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100108A0
// Name: public: void CUtlMemory<struct CResourceAccessControl::ResourceInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CResourceAccessControl::ResourceInfo_t,int>::Grow(
        CUtlMemory<CResourceAccessControl::ResourceInfo_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CResourceAccessControl::ResourceInfo_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 116 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CResourceAccessControl::ResourceInfo_t *)_g_pMemAlloc->Realloc_2(
                                                                    this: _g_pMemAlloc,
                                                                    a2: m_pMemory,
                                                                    a3: v7);
    else
      this->m_pMemory = (CResourceAccessControl::ResourceInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100109C0
// Name: public: virtual void __near * CBaseAppSystem<class IResourceAccessControl>::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CBaseAppSystem<IResourceAccessControl>::QueryInterface(
        CBaseAppSystem<IPrecacheSystem> *this,
        const char *pInterfaceName)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100109D0
// Name: public: virtual void CResourceAccessControl::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceAccessControl::Shutdown(CResourceAccessControl *this)
{
  this->DestroyAllResourceLists(this);
  memset(dst: (unsigned __int8 *)this->m_pLimitAccess, value: 0xFFu, count: sizeof(this->m_pLimitAccess));
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x10010A00
// Name: public: virtual bool CResourceAccessControl::IsAccessAllowed(enum ResourceTypeOld_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CResourceAccessControl::IsAccessAllowed(
        CResourceAccessControl *this,
        ResourceTypeOld_t nType,
        const char *pResourceName)
{
  int v4; // edi
  bool v5; // sf
  __int32 v7; // eax
  CResourceAccessControl::ResourceInfo_t *m_pMemory; // ecx
  int v9; // ebx
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v10; // eax
  int v11; // edi
  const char *v12; // eax
  const char *v13; // eax
  char pBuf[260]; // [esp+8h] [ebp-110h] BYREF
  int nIndex; // [esp+10Ch] [ebp-Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *list; // [esp+110h] [ebp-8h]
  unsigned int v17; // [esp+114h] [ebp-4h]

  v4 = CResourceAccessControl::FindOrAddCurrentThreadID(this);
  v5 = this->m_pLimitAccess[v4] < 0;
  nIndex = v4;
  if ( v5 )
    return 1;
  V_StripExtension(in: pResourceName, out: pBuf, outSize: 260);
  V_FixSlashes(pname: pBuf, separator: 47);
  V_RemoveDotSlashes(pFilename: pBuf, separator: 47);
  v7 = 116 * this->m_pLimitAccess[v4] + 20 * nType;
  m_pMemory = this->m_ResourceLists.m_Memory.m_pMemory;
  v9 = *(int *)((char *)&m_pMemory->m_Resources[0].m_Size + v7);
  v10 = (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)((char *)m_pMemory->m_Resources + v7);
  v11 = 0;
  list = v10;
  if ( v9 <= 0 )
  {
LABEL_8:
    v13 = CUtlString::Get(this: &this->m_ResourceLists.m_Memory.m_pMemory[this->m_pLimitAccess[nIndex]].m_DebugName);
    _Warning(
      a1: "Access to %s resource \"%s\" denied. Missing precache in %s?\n",
      s_pResourceTypeName[nType],
      pResourceName,
      v13);
    return 0;
  }
  else
  {
    v17 = 0;
    while ( 1 )
    {
      v12 = CUtlString::Get(this: &v10->m_Memory.m_pMemory[v17 / 0x10]);
      if ( _V_stricmp(s1: pBuf, s2: v12) == 0 )
        return 1;
      v17 += 16;
      if ( ++v11 >= v9 )
        goto LABEL_8;
      v10 = list;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010B00
// Name: public: virtual enum AppSystemTier_t CTier1AppSystem<class IResourceAccessControl,0>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier1AppSystem<IResourceAccessControl,0>::GetTier(CTier1AppSystem<IResourceAccessControl,0> *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010B10
// Name: public: virtual bool CTier1AppSystem<class IResourceAccessControl,0>::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTier1AppSystem<IResourceAccessControl,0>::Connect(
        CTier1AppSystem<IResourceAccessControl,0> *this,
        void *(__cdecl *factory)(const char *, int *))
{
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010B30
// Name: public: virtual void CTier1AppSystem<class IResourceAccessControl,0>::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CTier1AppSystem<IResourceAccessControl,0>::Disconnect(CTier1AppSystem<IResourceAccessControl,0> *this)
{
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x10010C20
// Name: public: virtual void CResourceAccessControl::AddResource(struct ResourceList_t__ __near *,enum ResourceTypeOld_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceAccessControl::AddResource(
        CResourceAccessControl *this,
        int hResourceList,
        ResourceTypeOld_t nType,
        const char *pResourceName)
{
  int v4; // esi
  char pBuf[260]; // [esp+Ch] [ebp-104h] BYREF
  int nSubIndex; // [esp+118h] [ebp+8h]

  v4 = 116 * hResourceList;
  nSubIndex = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
                this: &this->m_ResourceLists.m_Memory.m_pMemory[hResourceList].m_Resources[nType],
                elem: this->m_ResourceLists.m_Memory.m_pMemory[hResourceList].m_Resources[nType].m_Size);
  V_StripExtension(in: pResourceName, out: pBuf, outSize: 260);
  V_FixSlashes(pname: pBuf, separator: 47);
  V_RemoveDotSlashes(pFilename: pBuf, separator: 47);
  CUtlString::Set(
    this: &(*(CUtlString **)((char *)&this->m_ResourceLists.m_Memory.m_pMemory->m_Resources[nType].m_Memory.m_pMemory + v4))[nSubIndex],
    pValue: pBuf);
}

//------------------------------------------------------------------------------
// Address: 0x10010CB0
// Name: public: CResourceAccessControl::ResourceInfo_t::~ResourceInfo_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceAccessControl::ResourceInfo_t::~ResourceInfo_t(CResourceAccessControl::ResourceInfo_t *this)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v2; // esi
  CUtlString *m_pMemory; // eax
  int i; // [esp+Ch] [ebp-4h]

  v2 = (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)(this + 1);
  for ( i = 4; i >= 0; --i )
  {
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: --v2);
    if ( v2->m_Memory.m_nGrowSize >= 0 )
    {
      if ( v2->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2->m_Memory.m_pMemory);
        v2->m_Memory.m_pMemory = nullptr;
      }
      v2->m_Memory.m_nAllocationCount = 0;
    }
    m_pMemory = v2->m_Memory.m_pMemory;
    v2->m_pElements = v2->m_Memory.m_pMemory;
    if ( v2->m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        v2->m_Memory.m_pMemory = nullptr;
      }
      v2->m_Memory.m_nAllocationCount = 0;
    }
  }
  this->m_DebugName.m_Storage.m_nActualLength = 0;
  if ( this->m_DebugName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DebugName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DebugName.m_Storage.m_Memory.m_pMemory);
      this->m_DebugName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_DebugName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010DE0
// Name: public: virtual struct ResourceList_t__ __near * CResourceAccessControl::CreateResourceList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
struct ResourceList_t__ *__thiscall CResourceAccessControl::CreateResourceList(
        CResourceAccessControl *this,
        const char *pDebugName)
{
  CUtlVector<CResourceAccessControl::ResourceInfo_t,CUtlMemory<CResourceAccessControl::ResourceInfo_t,int> > *p_m_ResourceLists; // esi
  int v3; // edi

  p_m_ResourceLists = &this->m_ResourceLists;
  v3 = CUtlVector<CResourceAccessControl::ResourceInfo_t,CUtlMemory<CResourceAccessControl::ResourceInfo_t,int>>::InsertBefore(
         this: &this->m_ResourceLists,
         elem: this->m_ResourceLists.m_Size);
  CUtlString::Set(this: &p_m_ResourceLists->m_Memory.m_pMemory[v3].m_DebugName, pValue: pDebugName);
  return (struct ResourceList_t__ *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10010E70
// Name: public: virtual void CResourceAccessControl::DestroyAllResourceLists(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceAccessControl::DestroyAllResourceLists(CResourceAccessControl *this)
{
  CUtlVector<CResourceAccessControl::ResourceInfo_t,CUtlMemory<CResourceAccessControl::ResourceInfo_t,int>>::Purge(this: &this->m_ResourceLists);
  memset(dst: (unsigned __int8 *)this->m_pLimitAccess, value: 0xFFu, count: sizeof(this->m_pLimitAccess));
}

//------------------------------------------------------------------------------
// Address: 0x10019300
// Name: public: virtual struct AppSystemInfo_t const __near * CBaseAppSystem<class IDataCache>::GetDependencies(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IDataCache>::GetDependencies(ConVar *this)
{
  return 0;
}
