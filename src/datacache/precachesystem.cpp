// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: datacache/precachesystem.cpp
// Functions: 13
// ============================================================

#include "datacache\precachesystem.h"

//------------------------------------------------------------------------------
// Address: 0x10003150
// Name: public: virtual enum InitReturnVal_t CTier2AppSystem<class IPrecacheSystem,0>::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier2AppSystem<IPrecacheSystem,0>::Init(CDataCache *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010320
// Name: public: virtual void CPrecacheSystem::Register(class IResourcePrecacher __near *,enum PrecacheSystem_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheSystem::Register(
        CPrecacheSystem *this,
        IResourcePrecacher *pResourcePrecacherFirst,
        PrecacheSystem_t nSystem)
{
  IResourcePrecacher *v3; // esi

  v3 = this->m_pFirstPrecacher[nSystem];
  if ( v3 != nullptr )
  {
    if ( v3->GetNext(this: this->m_pFirstPrecacher[nSystem]) != nullptr )
    {
      do
        v3 = v3->GetNext(this: v3);
      while ( v3->GetNext(this: v3) != nullptr );
    }
    v3->SetNext(this: v3, a2: pResourcePrecacherFirst);
  }
  else
  {
    this->m_pFirstPrecacher[nSystem] = pResourcePrecacherFirst;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010380
// Name: public: virtual void CPrecacheSystem::EndLimitedResourceAccess(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheSystem::EndLimitedResourceAccess(CPrecacheSystem *this)
{
  if ( g_pResourceAccessControl != nullptr )
    g_pResourceAccessControl->LimitAccess(this: g_pResourceAccessControl, a2: (struct ResourceList_t__ *)-1);
}

//------------------------------------------------------------------------------
// Address: 0x100103C0
// Name: public: virtual void CPrecacheSystem::LimitResourceAccess(enum PrecacheSystem_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheSystem::LimitResourceAccess(
        CPrecacheSystem *this,
        PrecacheSystem_t nSystem,
        const char *pName)
{
  IResourceAccessControl *v3; // edx
  char *v4; // esi
  int m_Id; // eax

  v3 = g_pResourceAccessControl;
  if ( g_pResourceAccessControl != nullptr )
  {
    if ( pName != nullptr )
    {
      v4 = (char *)this + 76 * nSystem;
      m_Id = CUtlSymbolTable::Find(this: (CUtlSymbolTable *)(v4 + 44), result: (CUtlSymbol *)&pName + 1, pString: pName)->m_Id;
      if ( (_WORD)m_Id != 0xFFFF )
      {
        g_pResourceAccessControl->LimitAccess(
          this: g_pResourceAccessControl,
          a2: *(struct ResourceList_t__ **)(*((_DWORD *)v4 + 6) + 4 * m_Id));
        return;
      }
      v3 = g_pResourceAccessControl;
    }
    v3->LimitAccess(this: v3, a2: (struct ResourceList_t__ *)-1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100104A0
// Name: public: virtual enum AppSystemTier_t CTier2AppSystem<class IPrecacheSystem,0>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier2AppSystem<IPrecacheSystem,0>::GetTier(CTier2AppSystem<IPrecacheSystem,0> *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x100104B0
// Name: public: virtual bool CTier2AppSystem<class IPrecacheSystem,0>::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTier2AppSystem<IPrecacheSystem,0>::Connect(
        CTier2AppSystem<IPrecacheSystem,0> *this,
        void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+0h] [ebp-4h] BYREF

  pFactoryList = factory;
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConnectTier2Libraries(pFactoryList: &factory, nFactoryCount: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100104E0
// Name: public: virtual void CTier2AppSystem<class IPrecacheSystem,0>::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier2AppSystem<IPrecacheSystem,0>::Shutdown(CTier2AppSystem<IPrecacheSystem,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x100104F0
// Name: public: virtual void CTier2AppSystem<class IPrecacheSystem,0>::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier2AppSystem<IPrecacheSystem,0>::Disconnect(CTier2AppSystem<IPrecacheSystem,0> *this)
{
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x10010500
// Name: public: virtual void CPrecacheSystem::UncacheAll(class IPrecacheHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheSystem::UncacheAll(CPrecacheSystem *this, IPrecacheHandler *pPrecacheHandler)
{
  int *p_m_nGrowSize; // edi
  int j; // esi
  int i; // [esp+Ch] [ebp-8h]
  IResourcePrecacher **m_pFirstPrecacher; // [esp+10h] [ebp-4h]

  m_pFirstPrecacher = this->m_pFirstPrecacher;
  p_m_nGrowSize = &this->m_ResourceList[0].m_Vector.m_Memory.m_nGrowSize;
  for ( i = 5; i != 0; --i )
  {
    for ( j = (int)*m_pFirstPrecacher; j != 0; j = (*(int (__thiscall **)(int))(*(_DWORD *)j + 12))(a1: j) )
      (**(void (__thiscall ***)(int, IPrecacheHandler *, _DWORD, int, _DWORD))j)(
        a1: j,
        a2: pPrecacheHandler,
        a3: 0,
        a4: -1,
        a5: 0);
    p_m_nGrowSize[1] = 0;
    if ( *p_m_nGrowSize >= 0 )
    {
      if ( *(p_m_nGrowSize - 2) != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*(p_m_nGrowSize - 2));
        *(p_m_nGrowSize - 2) = 0;
      }
      *(p_m_nGrowSize - 1) = 0;
    }
    p_m_nGrowSize[2] = *(p_m_nGrowSize - 2);
    CUtlSymbolTable::RemoveAll(this: (CUtlSymbolTable *)(p_m_nGrowSize + 3));
    ++m_pFirstPrecacher;
    p_m_nGrowSize += 19;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100105A0
// Name: public: CPrecacheSystem::~CPrecacheSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheSystem::~CPrecacheSystem(CPrecacheSystem *this)
{
  CPrecacheSystem *v1; // esi
  int i; // ebx
  CPrecacheSystem_vtbl *v3; // eax

  v1 = this + 1;
  for ( i = 4; i >= 0; --i )
  {
    v1 = (CPrecacheSystem *)((char *)v1 - 76);
    CUtlSymbolTable::~CUtlSymbolTable(this: (CUtlSymbolTable *)&v1->m_pFirstPrecacher[4]);
    v1->m_pFirstPrecacher[2] = nullptr;
    if ( (int)v1->m_pFirstPrecacher[1] >= 0 )
    {
      if ( v1->__vftable != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->__vftable);
        v1->__vftable = nullptr;
      }
      v1->m_pFirstPrecacher[0] = nullptr;
    }
    v3 = v1->__vftable;
    v1->m_pFirstPrecacher[3] = (IResourcePrecacher *)v1->__vftable;
    if ( (int)v1->m_pFirstPrecacher[1] >= 0 )
    {
      if ( v3 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
        v1->__vftable = nullptr;
      }
      v1->m_pFirstPrecacher[0] = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010610
// Name: public: CPrecacheSystem::CPrecacheSystem(void)
// Source: json
//------------------------------------------------------------------------------
CPrecacheSystem *__thiscall CPrecacheSystem::CPrecacheSystem(CPrecacheSystem *this)
{
  CUtlStringMap<ResourceList_t__ *> *m_ResourceList; // esi
  int i; // ebx

  this->__vftable = (CPrecacheSystem_vtbl *)&CPrecacheSystem::`vftable';
  m_ResourceList = this->m_ResourceList;
  for ( i = 4; i >= 0; --i )
  {
    m_ResourceList->m_Vector.m_Memory.m_pMemory = nullptr;
    m_ResourceList->m_Vector.m_Memory.m_nAllocationCount = 0;
    m_ResourceList->m_Vector.m_Memory.m_nGrowSize = 32;
    m_ResourceList->m_Vector.m_Size = 0;
    m_ResourceList->m_Vector.m_pElements = nullptr;
    CUtlSymbolTable::CUtlSymbolTable(
      this: &m_ResourceList->m_SymbolTable,
      growSize: 0,
      initSize: 32,
      caseInsensitive: true);
    ++m_ResourceList;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10010660
// Name: public: virtual void CPrecacheSystem::Cache(class IPrecacheHandler __near *,enum PrecacheSystem_t,char const __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecacheSystem::Cache(
        CPrecacheSystem *this,
        IPrecacheHandler *pPrecacheHandler,
        PrecacheSystem_t nSystem,
        const char *pName,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bBuildResourceList)
{
  PrecacheSystem_t v7; // edi
  IResourcePrecacher *v8; // esi
  const char *v9; // ebx
  const char *v10; // eax
  int v11; // edi
  CUtlVector<int,CUtlMemory<int,int> > *v12; // esi
  int v13; // edi
  int m_Size; // eax
  int *m_pMemory; // edx
  int v16; // edi
  CUtlVector<int,CUtlMemory<int,int> > *v17; // esi
  int m_Id; // edi
  int v19; // ecx
  int *v20; // edx
  char pDebugName[256]; // [esp+8h] [ebp-10Ch] BYREF
  CPrecacheSystem *v22; // [esp+108h] [ebp-Ch]
  CUtlSymbol result; // [esp+10Ch] [ebp-8h] BYREF
  IResourcePrecacher *pPrecacher; // [esp+110h] [ebp-4h]

  v7 = nSystem;
  v8 = this->m_pFirstPrecacher[nSystem];
  v22 = this;
  pPrecacher = v8;
  if ( v8 != nullptr )
  {
    v9 = pName;
    while ( 1 )
    {
      if ( v9 == nullptr || (v10 = v8->GetName(this: v8), _V_stricmp(s1: v9, s2: v10) == 0) )
      {
        if ( bBuildResourceList && g_pResourceAccessControl != nullptr )
        {
          V_snprintf(pDest: pDebugName, maxLen: 256, pFormat: "%s \"%s\"", s_pResourceSystemName[v7], v9);
          v11 = v7;
          hResourceList = g_pResourceAccessControl->CreateResourceList(this: g_pResourceAccessControl, a2: pDebugName);
          v12 = (CUtlVector<int,CUtlMemory<int,int> > *)&v22->m_ResourceList[v11];
          CUtlSymbolTable::AddString(
            this: &v22->m_ResourceList[v11].m_SymbolTable,
            result: (CUtlSymbol *)&pName,
            pString: v9);
          v13 = (unsigned __int16)pName;
          m_Size = v12->m_Size;
          if ( m_Size <= (unsigned __int16)pName && m_Size < (unsigned __int16)pName + 1 )
            CUtlVector<ResourceList_t__ *,CUtlMemory<ResourceList_t__ *,int>>::InsertMultipleBefore(
              this: v12,
              elem: m_Size,
              num: (unsigned __int16)pName + 1 - m_Size);
          m_pMemory = v12->m_Memory.m_pMemory;
          v8 = pPrecacher;
          m_pMemory[v13] = (int)hResourceList;
          v7 = nSystem;
        }
        v8->Cache(this: v8, a2: pPrecacheHandler, a3: bPrecache, a4: hResourceList, a5: false);
        if ( !bPrecache )
        {
          v16 = v7;
          v17 = (CUtlVector<int,CUtlMemory<int,int> > *)&v22->m_ResourceList[v16];
          CUtlSymbolTable::AddString(this: &v22->m_ResourceList[v16].m_SymbolTable, &result, pString: v9);
          m_Id = result.m_Id;
          v19 = v17->m_Size;
          if ( v19 <= result.m_Id && v19 < result.m_Id + 1 )
            CUtlVector<ResourceList_t__ *,CUtlMemory<ResourceList_t__ *,int>>::InsertMultipleBefore(
              this: v17,
              elem: v19,
              num: result.m_Id + 1 - v19);
          v20 = v17->m_Memory.m_pMemory;
          v8 = pPrecacher;
          v20[m_Id] = 0;
          v7 = nSystem;
        }
      }
      pPrecacher = v8->GetNext(this: v8);
      if ( pPrecacher == nullptr )
        break;
      v8 = pPrecacher;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100107C0
// Name: __CreateCResourceAccessControlIResourceAccessControl_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CResourceAccessControl *__cdecl _CreateCResourceAccessControlIResourceAccessControl_interface()
{
  return &g_ResourceAccessControl;
}
