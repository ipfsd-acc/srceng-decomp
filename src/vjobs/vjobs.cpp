// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vjobs/vjobs.cpp
// Functions: 22
// ============================================================

#include "vjobs\vjobs.h"

//------------------------------------------------------------------------------
// Address: 0x100010C0
// Name: public: virtual void __near * CVJobs::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVJobs *__thiscall CVJobs::QueryInterface(CVJobs *this, const char *pInterfaceName)
{
  const char *v2; // edx
  const char *v3; // esi
  char v4; // al

  v2 = pInterfaceName;
  v3 = "VJobs01";
  if ( *pInterfaceName == 86 )
  {
    v4 = 86;
    do
    {
      if ( v4 == 0 )
        break;
      v4 = *++v2;
      ++v3;
    }
    while ( v4 == *v3 );
  }
  return *v3 == *v2 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001100
// Name: public: virtual void CVJobs::AfterReload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVJobs::AfterReload(CVJobs *this)
{
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VJOBS, a2: 0) != 0 )
    _LoggingSystem_Log(a1: LOG_VJOBS, a2: 0, a3: "[VJobs]AfterReload\n");
}

//------------------------------------------------------------------------------
// Address: 0x10001130
// Name: public: virtual void CEmptyVJobs::AfterReload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEmptyVJobs::AfterReload(CEmptyVJobs *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001140
// Name: public: void CUtlMemory<struct VJobInstance __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<VJobInstance *,int>::Grow(CUtlMemory<VJobInstance *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  VJobInstance **m_pMemory; // edx
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
        m_nAllocationCount = 8;
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
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (VJobInstance **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (VJobInstance **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100011D0
// Name: public: virtual bool CBaseAppSystem<struct IVJobs>::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAppSystem<IVJobs>::Connect(
        CBaseAppSystem<IVJobs> *this,
        void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100011E0
// Name: public: virtual void __near * CBaseAppSystem<struct IVJobs>::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CBaseAppSystem<IVJobs>::QueryInterface(CBaseAppSystem<IVJobs> *this, const char *pInterfaceName)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100011F0
// Name: public: virtual enum InitReturnVal_t CBaseAppSystem<struct IVJobs>::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IVJobs>::Init(CBaseAppSystem<IVJobs> *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001200
// Name: public: virtual struct AppSystemInfo_t const __near * CBaseAppSystem<struct IVJobs>::GetDependencies(void)
// Source: json
//------------------------------------------------------------------------------
const AppSystemInfo_t *__thiscall CBaseAppSystem<IVJobs>::GetDependencies(CBaseAppSystem<IVJobs> *this)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001210
// Name: public: virtual enum AppSystemTier_t CBaseAppSystem<struct IVJobs>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IVJobs>::GetTier(CBaseAppSystem<IVJobs> *this)
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x10001220
// Name: public: virtual void CBaseAppSystem<struct IVJobs>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IVJobs>::Reconnect(
        CBaseAppSystem<IVJobs> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10001240
// Name: public: bool CVJobs::TryInitRoot(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVJobs::TryInitRoot(CVJobs *this)
{
  void *v2; // eax
  VJobsRootInternal *v3; // ecx
  int v4; // edi
  VJobInstance *v5; // ecx

  v2 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 259);
  if ( v2 != nullptr )
  {
    v3 = (VJobsRootInternal *)(((unsigned int)v2 + 131) & 0xFFFFFF80);
    *(_DWORD *)&v3[-1].gap0[124] = v2;
  }
  else
  {
    v3 = nullptr;
  }
  this->m_pRoot = v3;
  v4 = 0;
  for ( g_pRoot = v3; v4 < this->m_instances.m_data.m_Size; ++v4 )
  {
    this->m_instances.m_data.m_Memory.m_pMemory[v4]->m_pRoot = this->m_pRoot;
    v5 = this->m_instances.m_data.m_Memory.m_pMemory[v4];
    v5->OnVjobsInit(this: v5);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100012B0
// Name: public: virtual enum InitReturnVal_t CVJobs::Init(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVJobs::Init(CVJobs *this)
{
  this->m_nDoNothingCalls = 0;
  return CVJobs::TryInitRoot(this) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100012D0
// Name: public: void CVJobs::Stop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVJobs::Stop(CVJobs *this)
{
  int i; // edi
  VJobInstance *v3; // ecx
  VJobInstance *v4; // edx
  VJobsRootInternal *m_pRoot; // eax

  if ( this->m_pRoot != nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VJOBS, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_VJOBS, a2: 0, a3: "[VJobs]Shutting down Root %p\n", this->m_pRoot);
    for ( i = 0; i < this->m_instances.m_data.m_Size; v4->m_pRoot = nullptr )
    {
      v3 = this->m_instances.m_data.m_Memory.m_pMemory[i];
      v3->OnVjobsShutdown(this: v3);
      v4 = this->m_instances.m_data.m_Memory.m_pMemory[i++];
    }
    m_pRoot = this->m_pRoot;
    if ( m_pRoot != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pRoot & 0xFFFFFFFC) - 4));
    this->m_pRoot = (VJobsRootInternal *)1;
    g_pRoot = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001370
// Name: public: int CUtlVector<struct VJobInstance __near *,class CUtlMemory<struct VJobInstance __near *,int>>::InsertBefore(int,struct VJobInstance __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<VJobInstance *,CUtlMemory<VJobInstance *,int>>::InsertBefore(
        CUtlVector<VJobInstance *,CUtlMemory<VJobInstance *,int> > *this,
        int elem,
        VJobInstance **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  VJobInstance **m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  VJobInstance **v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<VJobInstance *,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100013E0
// Name: public: virtual void CVJobs::SetRunTarget(enum RunTargetEnum)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVJobs::SetRunTarget(CVJobs *this, RunTargetEnum nRunTarget)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100013F0
// Name: public: virtual void CVJobs::DoNothing(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVJobs::DoNothing(CVJobs *this)
{
  ++this->m_nDoNothingCalls;
}

//------------------------------------------------------------------------------
// Address: 0x10001400
// Name: public: virtual void CVJobs::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CVJobs::Shutdown(CVJobs *this)
{
  CVJobs::Stop(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001410
// Name: public: virtual void CVJobs::BeforeReload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVJobs::BeforeReload(CVJobs *this)
{
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VJOBS, a2: 0) != 0 )
    _LoggingSystem_Log(a1: LOG_VJOBS, a2: 0, a3: "[VJobs]CVJobs::BeforeReload\n");
  CVJobs::Stop(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001450
// Name: public: CVJobs::CVJobs(enum CVJobs::DummyEnum)
// Source: json
//------------------------------------------------------------------------------
CVJobs *__thiscall CVJobs::CVJobs(CVJobs *this, CVJobs::DummyEnum __formal)
{
  this->__vftable = (CVJobs_vtbl *)&CVJobs::`vftable';
  this->m_instances.m_data.m_Memory.m_pMemory = nullptr;
  this->m_instances.m_data.m_Memory.m_nAllocationCount = 0;
  this->m_instances.m_data.m_Memory.m_nGrowSize = 0;
  this->m_instances.m_data.m_Size = 0;
  this->m_instances.m_data.m_pElements = nullptr;
  if ( this->m_pRoot != nullptr )
    CVJobs::TryInitRoot(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001480
// Name: public: virtual void CVJobs::Unregister(struct VJobInstance __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVJobs::Unregister(CVJobs *this, VJobInstance *pInstance)
{
  unsigned int m_nIncrementalVectorIndex; // eax
  VJobInstance **m_pMemory; // eax
  int v5; // esi
  VJobInstance *v6; // edx
  VJobInstance *v7; // ecx

  m_nIncrementalVectorIndex = pInstance->m_nIncrementalVectorIndex;
  if ( m_nIncrementalVectorIndex < this->m_instances.m_data.m_Size
    && this->m_instances.m_data.m_Memory.m_pMemory[m_nIncrementalVectorIndex] == pInstance )
  {
    if ( pInstance->m_pRoot != nullptr )
    {
      pInstance->OnVjobsShutdown(this: pInstance);
      pInstance->m_pRoot = nullptr;
      m_pMemory = this->m_instances.m_data.m_Memory.m_pMemory;
      v5 = pInstance->m_nIncrementalVectorIndex;
      v6 = m_pMemory[v5];
      v7 = m_pMemory[this->m_instances.m_data.m_Size - 1];
      m_pMemory[v5] = v7;
      --this->m_instances.m_data.m_Size;
      v7->m_nIncrementalVectorIndex = v5;
      v6->m_nIncrementalVectorIndex = -1;
    }
  }
  else
  {
    _Warning(a1: "Unregistering not registered vjobs instance %p\n", pInstance);
    pInstance->m_pRoot = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100014F0
// Name: _CreateInterface
// Source: json
//------------------------------------------------------------------------------
IVJobs *__cdecl CreateInterface(const char *pName, int *pReturnCode)
{
  IVJobs *v2; // esi
  int v3; // eax
  int v4; // eax
  bool v5; // bl
  CVJobs **VAtom; // edi
  IVJobs *v7; // eax
  IVJobs *v8; // eax

  v2 = g_pVJobs;
  if ( g_pVJobs != nullptr )
    goto LABEL_29;
  v3 = _CommandLine();
  v5 = true;
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(a1: v3, a2: "-spursDisable", a3: 0) == 0 )
  {
    v4 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-noSpurs", a3: 0) == 0 )
      v5 = false;
  }
  VAtom = (CVJobs **)_GetVAtom(a1: 0);
  if ( *VAtom == nullptr )
  {
    if ( v5 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VJOBS, a2: 0) != 0 )
        _LoggingSystem_Log(a1: LOG_VJOBS, a2: 0, a3: "[VJobs]Creating EmptyVJobs: any SPURS operations are disabled\n");
      v8 = (IVJobs *)operator new(nSize: 4u);
      if ( v8 == nullptr )
      {
        v2 = nullptr;
LABEL_28:
        *VAtom = (CVJobs *)v2;
        goto LABEL_29;
      }
      v8->__vftable = (IVJobs_vtbl *)&CEmptyVJobs::`vftable';
    }
    else
    {
      v8 = (IVJobs *)operator new(nSize: 0x30u);
      if ( v8 != nullptr )
      {
        v8->__vftable = (IVJobs_vtbl *)&CVJobs::`vftable';
        v8[3].__vftable = nullptr;
        v8[4].__vftable = nullptr;
        v8[5].__vftable = nullptr;
        v8[6].__vftable = nullptr;
        v8[7].__vftable = nullptr;
        v8[2].__vftable = nullptr;
      }
      else
      {
        v8 = nullptr;
      }
      g_pVJobs = v8;
    }
    v2 = v8;
    goto LABEL_28;
  }
  if ( v5 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VJOBS, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_VJOBS, a2: 0, a3: "[VJobs]Recreating EmptyVJobs\n");
    v7 = *VAtom;
    if ( *VAtom != nullptr )
    {
      v7->__vftable = (IVJobs_vtbl *)&CEmptyVJobs::`vftable';
      g_pVJobs = v7;
      v2 = v7;
      goto LABEL_29;
    }
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VJOBS, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_VJOBS, a2: 0, a3: "[VJobs]Recreating VJobs\n");
    if ( *VAtom != nullptr )
    {
      g_pVJobs = CVJobs::CVJobs(this: *VAtom, __formal: DO_NOT_TOUCH_CONTENT);
      v2 = g_pVJobs;
      goto LABEL_29;
    }
  }
  g_pVJobs = nullptr;
  v2 = nullptr;
LABEL_29:
  if ( _V_stricmp(s1: pName, s2: "VJobs01") != 0 )
  {
    if ( pReturnCode != nullptr )
      *pReturnCode = 1;
    return nullptr;
  }
  else
  {
    if ( pReturnCode != nullptr )
      *pReturnCode = v2 == nullptr;
    return v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100016A0
// Name: public: virtual void CVJobs::Register(struct VJobInstance __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVJobs::Register(CVJobs *this, VJobInstance *pInstance)
{
  VJobInstance *v2; // esi
  unsigned int m_nIncrementalVectorIndex; // eax
  VJobsRootInternal *m_pRoot; // edi
  int m_Size; // [esp-8h] [ebp-10h]

  v2 = pInstance;
  m_nIncrementalVectorIndex = pInstance->m_nIncrementalVectorIndex;
  if ( m_nIncrementalVectorIndex < this->m_instances.m_data.m_Size
    && this->m_instances.m_data.m_Memory.m_pMemory[m_nIncrementalVectorIndex] == pInstance )
  {
    _Warning(a1: "Double-registering vjobs instance %p\n", pInstance);
  }
  else
  {
    pInstance->m_nIncrementalVectorIndex = this->m_instances.m_data.m_Size;
    m_Size = this->m_instances.m_data.m_Size;
    pInstance = v2;
    CUtlVector<VJobInstance *,CUtlMemory<VJobInstance *,int>>::InsertBefore(
      this: &this->m_instances.m_data,
      elem: m_Size,
      src: &pInstance);
    m_pRoot = this->m_pRoot;
    v2->m_pRoot = m_pRoot;
    if ( m_pRoot != nullptr )
      v2->OnVjobsInit(this: v2);
  }
}
