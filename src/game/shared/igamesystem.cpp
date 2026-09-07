// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/igamesystem.cpp
// Functions: 20
// ============================================================

#include "game\shared\igamesystem.h"

//------------------------------------------------------------------------------
// Address: 0x10110AE0
// Name: public: static char const __near * IGameSystem::MapName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl IGameSystem::MapName()
{
  return s_pMapName;
}

//------------------------------------------------------------------------------
// Address: 0x10110C10
// Name: InvokeMethod
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvokeMethod(__int128 f)
{
  IMDLCache *v1; // edi
  IMDLCache *v2; // ebx
  int v3; // esi
  int c; // [esp+Ch] [ebp-4h]

  v1 = mdlcache;
  mdlcache->BeginCoarseLock(this: mdlcache);
  v2 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  v3 = 0;
  for ( c = s_GameSystems.m_Size; v3 < c; ++v3 )
    ((void (__thiscall *)(char *))f)(a1: (char *)s_GameSystems.m_Memory.m_pMemory[v3] + DWORD1(f));
  v2->EndLock(this: v2);
  v1->EndCoarseLock(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10110C80
// Name: InvokeMethodTickProgress
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvokeMethodTickProgress(__int128 f)
{
  int v1; // ebx
  IMDLCache *v2; // esi
  IMDLCache *v3; // edi
  int c; // [esp+4h] [ebp-8h]
  IGameSystem *sys; // [esp+8h] [ebp-4h]

  v1 = 0;
  for ( c = s_GameSystems.m_Size; v1 < c; ++v1 )
  {
    v2 = mdlcache;
    sys = s_GameSystems.m_Memory.m_pMemory[v1];
    mdlcache->BeginCoarseLock(this: mdlcache);
    v3 = mdlcache;
    mdlcache->BeginLock(this: mdlcache);
    engine->TickProgressBar(this: engine);
    ((void (__thiscall *)(char *))f)(a1: (char *)sys + DWORD1(f));
    v3->EndLock(this: v3);
    v2->EndCoarseLock(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110D10
// Name: public: static void IGameSystem::PostInitAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IGameSystem::PostInitAllSystems()
{
  InvokeMethod(f: (unsigned int) __thiscall IGameSystem::`vcall'{8,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x10110D50
// Name: public: static void IGameSystem::ShutdownAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IGameSystem::ShutdownAllSystems()
{
  int m_Size; // esi
  IMDLCache *v1; // edi
  int i; // esi

  m_Size = s_GameSystems.m_Size;
  v1 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  for ( i = m_Size - 1; i >= 0; --i )
     __thiscall IGameSystem::`vcall'{12,{flat}}(a1: s_GameSystems.m_Memory.m_pMemory[i]);
  v1->EndLock(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10110D90
// Name: public: static void IGameSystem::LevelInitPreEntityAllSystems(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IGameSystem::LevelInitPreEntityAllSystems(char *pMapName)
{
  unsigned int v1; // esi

  if ( s_pMapName != nullptr )
    C_BaseEntity::operator delete(pMem: s_pMapName);
  v1 = _V_strlen(str: pMapName) + 1;
  s_pMapName = (char *)MemAlloc_Alloc(nSize: v1);
  V_strncpy(pDest: s_pMapName, pSrc: pMapName, maxLen: v1);
  InvokeMethodTickProgress(f: (unsigned int) __thiscall IGameSystem::`vcall'{16,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x10110E10
// Name: public: static void IGameSystem::LevelInitPostEntityAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IGameSystem::LevelInitPostEntityAllSystems()
{
  InvokeMethod(f: (unsigned int) __thiscall IGameSystem::`vcall'{20,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x10110E50
// Name: public: static void IGameSystem::LevelShutdownPreEntityAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IGameSystem::LevelShutdownPreEntityAllSystems()
{
  int m_Size; // esi
  IMDLCache *v1; // edi
  int i; // esi

  m_Size = s_GameSystems.m_Size;
  v1 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  for ( i = m_Size - 1; i >= 0; --i )
     __thiscall IGameSystem::`vcall'{24,{flat}}(a1: s_GameSystems.m_Memory.m_pMemory[i]);
  v1->EndLock(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10110E90
// Name: public: static void IGameSystem::LevelShutdownPostEntityAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IGameSystem::LevelShutdownPostEntityAllSystems()
{
  int m_Size; // esi
  IMDLCache *v1; // edi
  int i; // esi

  m_Size = s_GameSystems.m_Size;
  v1 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  for ( i = m_Size - 1; i >= 0; --i )
     __thiscall IGameSystem::`vcall'{28,{flat}}(a1: s_GameSystems.m_Memory.m_pMemory[i]);
  v1->EndLock(this: v1);
  if ( s_pMapName != nullptr )
  {
    C_BaseEntity::operator delete(pMem: s_pMapName);
    s_pMapName = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110EF0
// Name: public: static void IGameSystem::OnSaveAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IGameSystem::OnSaveAllSystems()
{
  InvokeMethod(f: (unsigned int) __thiscall IGameSystem::`vcall'{32,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x10110F30
// Name: public: static void IGameSystem::OnRestoreAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IGameSystem::OnRestoreAllSystems()
{
  InvokeMethod(f: (unsigned int) __thiscall IGameSystem::`vcall'{36,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x10110F70
// Name: public: static void IGameSystem::PreRenderAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IGameSystem::PreRenderAllSystems()
{
  int m_Size; // edi
  int i; // esi

  m_Size = s_GameSystemsPerFrame.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IGameSystemPerFrame::`vcall'{52,{flat}}(a1: s_GameSystemsPerFrame.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10110FA0
// Name: public: static void IGameSystem::UpdateAllSystems(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IGameSystem::UpdateAllSystems(float frametime)
{
  IMDLCache *v1; // esi
  int m_Size; // edi
  int i; // edi
  IMDLCache *v4; // ebx
  int v5; // edi
  int j; // esi

  v1 = mdlcache;
  m_Size = s_GameSystems.m_Size;
  mdlcache->BeginLock(this: mdlcache);
  for ( i = m_Size - 1; i >= 0; --i )
     __thiscall IGameSystem::`vcall'{40,{flat}}(a1: s_GameSystems.m_Memory.m_pMemory[i]);
  v1->EndLock(this: v1);
  v4 = mdlcache;
  v5 = s_GameSystemsPerFrame.m_Size;
  mdlcache->BeginLock(this: mdlcache);
  for ( j = 0; j < v5; ++j )
    ((void (__stdcall *)(_DWORD))s_GameSystemsPerFrame.m_Memory.m_pMemory[j]->Update)(a1: LODWORD(frametime));
  v4->EndLock(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10111030
// Name: public: static void IGameSystem::PostRenderAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IGameSystem::PostRenderAllSystems()
{
  int m_Size; // edi
  int i; // esi

  m_Size = s_GameSystemsPerFrame.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IGameSystemPerFrame::`vcall'{60,{flat}}(a1: s_GameSystemsPerFrame.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10111060
// Name: public: virtual IGameSystem::~IGameSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IGameSystem::~IGameSystem(IGameSystem *this)
{
  vgui::TreeNode *src; // [esp+4h] [ebp-4h] BYREF

  this->__vftable = (IGameSystem_vtbl *)&IGameSystem::`vftable';
  src = (vgui::TreeNode *)this;
  CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_GameSystems,
    &src);
  if ( __RTDynamicCast(
         inptr: this,
         VfDelta: 0,
         SrcType: &IGameSystem `RTTI Type Descriptor',
         TargetType: &IGameSystemPerFrame `RTTI Type Descriptor',
         isReference: 0) != nullptr )
  {
    src = (vgui::TreeNode *)this;
    CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_GameSystemsPerFrame,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101110B0
// Name: public: virtual IGameSystemPerFrame::~IGameSystemPerFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IGameSystemPerFrame::~IGameSystemPerFrame(IGameSystemPerFrame *this)
{
  vgui::TreeNode *src; // [esp+4h] [ebp-4h] BYREF

  this->__vftable = (IGameSystemPerFrame_vtbl *)&IGameSystemPerFrame::`vftable';
  src = (vgui::TreeNode *)this;
  CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_GameSystems,
    &src);
  if ( __RTDynamicCast(
         inptr: this,
         VfDelta: 0,
         SrcType: &IGameSystem `RTTI Type Descriptor',
         TargetType: &IGameSystemPerFrame `RTTI Type Descriptor',
         isReference: 0) != nullptr )
  {
    src = (vgui::TreeNode *)this;
    CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_GameSystemsPerFrame,
      &src);
  }
  this->__vftable = (IGameSystemPerFrame_vtbl *)&IGameSystem::`vftable';
  src = (vgui::TreeNode *)this;
  CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_GameSystems,
    &src);
  if ( __RTDynamicCast(
         inptr: this,
         VfDelta: 0,
         SrcType: &IGameSystem `RTTI Type Descriptor',
         TargetType: &IGameSystemPerFrame `RTTI Type Descriptor',
         isReference: 0) != nullptr )
  {
    src = (vgui::TreeNode *)this;
    CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_GameSystemsPerFrame,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111150
// Name: public: static void IGameSystem::Add(class IGameSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IGameSystem::Add(IGameSystemPerFrame *pSys)
{
  int m_Size; // eax
  int v2; // esi
  IGameSystem **m_pMemory; // ecx
  int v4; // eax
  IGameSystem **v5; // eax
  int v6; // eax
  int v7; // esi
  IGameSystemPerFrame **v8; // ecx
  int v9; // eax
  IGameSystemPerFrame **v10; // eax

  m_Size = s_GameSystems.m_Size;
  v2 = s_GameSystems.m_Size;
  if ( s_GameSystems.m_Size + 1 > s_GameSystems.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&s_GameSystems,
      num: s_GameSystems.m_Size - s_GameSystems.m_Memory.m_nAllocationCount + 1);
    m_Size = s_GameSystems.m_Size;
  }
  m_pMemory = s_GameSystems.m_Memory.m_pMemory;
  s_GameSystems.m_Size = m_Size + 1;
  v4 = m_Size - v2;
  s_GameSystems.m_pElements = s_GameSystems.m_Memory.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(
      dest: (unsigned __int8 *)&s_GameSystems.m_Memory.m_pMemory[v2 + 1],
      src: (unsigned __int8 *)&s_GameSystems.m_Memory.m_pMemory[v2],
      count: 4 * v4);
    m_pMemory = s_GameSystems.m_Memory.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = pSys;
  if ( __RTDynamicCast(
         inptr: pSys,
         VfDelta: 0,
         SrcType: &IGameSystem `RTTI Type Descriptor',
         TargetType: &IGameSystemPerFrame `RTTI Type Descriptor',
         isReference: 0) != nullptr )
  {
    v6 = s_GameSystemsPerFrame.m_Size;
    v7 = s_GameSystemsPerFrame.m_Size;
    if ( s_GameSystemsPerFrame.m_Size + 1 > s_GameSystemsPerFrame.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&s_GameSystemsPerFrame,
        num: s_GameSystemsPerFrame.m_Size - s_GameSystemsPerFrame.m_Memory.m_nAllocationCount + 1);
      v6 = s_GameSystemsPerFrame.m_Size;
    }
    v8 = s_GameSystemsPerFrame.m_Memory.m_pMemory;
    s_GameSystemsPerFrame.m_Size = v6 + 1;
    v9 = v6 - v7;
    s_GameSystemsPerFrame.m_pElements = s_GameSystemsPerFrame.m_Memory.m_pMemory;
    if ( v9 > 0 )
    {
      _V_memmove(
        dest: (unsigned __int8 *)&s_GameSystemsPerFrame.m_Memory.m_pMemory[v7 + 1],
        src: (unsigned __int8 *)&s_GameSystemsPerFrame.m_Memory.m_pMemory[v7],
        count: 4 * v9);
      v8 = s_GameSystemsPerFrame.m_Memory.m_pMemory;
    }
    v10 = &v8[v7];
    if ( v10 != nullptr )
      *v10 = pSys;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111240
// Name: public: static bool IGameSystem::InitAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IGameSystem::InitAllSystems()
{
  IGameSystemPerFrame *v0; // esi
  int v1; // eax
  CAutoGameSystemPerFrame *v2; // esi
  int v3; // eax
  IMDLCache *v4; // esi
  IMDLCache *v5; // edi
  IGameSystem *v6; // ebx
  const char *v8; // eax
  int i; // [esp+Ch] [ebp-4h]

  v0 = (IGameSystemPerFrame *)s_pSystemList;
  if ( s_pSystemList != nullptr )
  {
    do
    {
      v1 = 0;
      if ( s_GameSystems.m_Size <= 0 )
        goto LABEL_5;
      while ( s_GameSystems.m_Memory.m_pMemory[v1] != v0 )
      {
        if ( ++v1 >= s_GameSystems.m_Size )
          goto LABEL_5;
      }
      if ( v1 == -1 )
LABEL_5:
        IGameSystem::Add(pSys: v0);
      else
        _DevWarning(a1: 1, a2: "AutoGameSystem already added to game system list!!!\n");
      v0 = (IGameSystemPerFrame *)v0[1].__vftable;
    }
    while ( v0 != nullptr );
  }
  v2 = s_pPerFrameSystemList;
  for ( s_pSystemList = nullptr; v2 != nullptr; v2 = v2->m_pNext )
  {
    v3 = 0;
    if ( s_GameSystems.m_Size <= 0 )
      goto LABEL_14;
    while ( s_GameSystems.m_Memory.m_pMemory[v3] != v2 )
    {
      if ( ++v3 >= s_GameSystems.m_Size )
        goto LABEL_14;
    }
    if ( v3 == -1 )
LABEL_14:
      IGameSystem::Add(pSys: v2);
    else
      _DevWarning(a1: 1, a2: "AutoGameSystem already added to game system list!!!\n");
  }
  s_pSystemList = nullptr;
  s_bSystemsInitted = true;
  i = 0;
  if ( s_GameSystems.m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    v4 = mdlcache;
    mdlcache->BeginCoarseLock(this: mdlcache);
    v5 = mdlcache;
    mdlcache->BeginLock(this: mdlcache);
    v6 = s_GameSystems.m_Memory.m_pMemory[i];
    if ( !v6->Init(this: v6) )
      break;
    v5->EndLock(this: v5);
    v4->EndCoarseLock(this: v4);
    if ( ++i >= s_GameSystems.m_Size )
      return 1;
  }
  v8 = (const char *)v6->Name(this: v6);
  _DevWarning(a1: 1, a2: "Failed to load %s\n", v8);
  v5->EndLock(this: v5);
  v4->EndCoarseLock(this: v4);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101113C0
// Name: public: CAutoGameSystem::CAutoGameSystem(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAutoGameSystem *__thiscall CAutoGameSystem::CAutoGameSystem(CAutoGameSystem *this, const char *name)
{
  bool v2; // zf

  v2 = !s_bSystemsInitted;
  this->__vftable = (CAutoGameSystem_vtbl *)&CAutoGameSystem::`vftable';
  this->m_pszName = name;
  if ( v2 )
  {
    this->m_pNext = s_pSystemList;
    s_pSystemList = this;
  }
  else
  {
    IGameSystem::Add(pSys: this);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10111480
// Name: public: CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAutoGameSystemPerFrame *__thiscall CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(
        CAutoGameSystemPerFrame *this,
        const char *name)
{
  bool v2; // zf

  v2 = !s_bSystemsInitted;
  this->__vftable = (CAutoGameSystemPerFrame_vtbl *)&CAutoGameSystemPerFrame::`vftable';
  this->m_pszName = name;
  if ( v2 )
  {
    this->m_pNext = s_pPerFrameSystemList;
    s_pPerFrameSystemList = this;
  }
  else
  {
    IGameSystem::Add(pSys: this);
  }
  return this;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10161240
// Name: public: static char const __near * IGameSystem::MapName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl IGameSystem::MapName()
{
  return s_pMapName;
}

//------------------------------------------------------------------------------
// Address: 0x10161300
// Name: InvokeMethod
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvokeMethod(void (__thiscall *f)(IGameSystem *this))
{
  IMDLCache *v1; // edi
  IMDLCache *v2; // ebx
  int v3; // esi
  int c; // [esp+Ch] [ebp-4h]

  v1 = mdlcache;
  mdlcache->BeginCoarseLock(this: mdlcache);
  v2 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  v3 = 0;
  for ( c = s_GameSystems.m_Size; v3 < c; ++v3 )
    f(this: s_GameSystems.m_Memory.m_pMemory[v3]);
  v2->EndLock(this: v2);
  v1->EndCoarseLock(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10161370
// Name: InvokeMethodTickProgress
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvokeMethodTickProgress(void (__thiscall *f)(IGameSystem *this))
{
  int v1; // ebx
  IMDLCache *v2; // esi
  IMDLCache *v3; // edi
  int c; // [esp+4h] [ebp-8h]
  IGameSystem *sys; // [esp+8h] [ebp-4h]

  v1 = 0;
  for ( c = s_GameSystems.m_Size; v1 < c; ++v1 )
  {
    v2 = mdlcache;
    sys = s_GameSystems.m_Memory.m_pMemory[v1];
    mdlcache->BeginCoarseLock(this: mdlcache);
    v3 = mdlcache;
    mdlcache->BeginLock(this: mdlcache);
    f(this: sys);
    v3->EndLock(this: v3);
    v2->EndCoarseLock(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101613F0
// Name: public: static void IGameSystem::PostInitAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IGameSystem::PostInitAllSystems()
{
  InvokeMethod(f:  __thiscall IGameSystem::`vcall'{8,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x10161400
// Name: public: static void IGameSystem::ShutdownAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IGameSystem::ShutdownAllSystems()
{
  int m_Size; // esi
  IMDLCache *v1; // edi
  int i; // esi

  m_Size = s_GameSystems.m_Size;
  v1 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  for ( i = m_Size - 1; i >= 0; --i )
     __thiscall IGameSystem::`vcall'{12,{flat}}(a1: s_GameSystems.m_Memory.m_pMemory[i]);
  v1->EndLock(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10161440
// Name: public: static void IGameSystem::LevelInitPreEntityAllSystems(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IGameSystem::LevelInitPreEntityAllSystems(const char *pMapName)
{
  int v1; // esi

  if ( s_pMapName != nullptr )
    free(pMem: s_pMapName);
  v1 = _V_strlen(str: pMapName) + 1;
  s_pMapName = (char *)operator new(nSize: v1);
  V_strncpy(pDest: s_pMapName, pSrc: pMapName, maxLen: v1);
  InvokeMethodTickProgress(f:  __thiscall IGameSystem::`vcall'{16,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x10161490
// Name: public: static void IGameSystem::LevelInitPostEntityAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IGameSystem::LevelInitPostEntityAllSystems()
{
  InvokeMethod(f: (void (__thiscall *)(IGameSystem *)) __thiscall IGameSystem::`vcall'{20,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x101614A0
// Name: public: static void IGameSystem::LevelShutdownPreEntityAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IGameSystem::LevelShutdownPreEntityAllSystems()
{
  int m_Size; // esi
  IMDLCache *v1; // edi
  int i; // esi

  m_Size = s_GameSystems.m_Size;
  v1 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  for ( i = m_Size - 1; i >= 0; --i )
     __thiscall IGameSystem::`vcall'{24,{flat}}(a1: s_GameSystems.m_Memory.m_pMemory[i]);
  v1->EndLock(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x101614E0
// Name: public: static void IGameSystem::LevelShutdownPostEntityAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IGameSystem::LevelShutdownPostEntityAllSystems()
{
  int m_Size; // esi
  IMDLCache *v1; // edi
  int i; // esi

  m_Size = s_GameSystems.m_Size;
  v1 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  for ( i = m_Size - 1; i >= 0; --i )
     __thiscall IGameSystem::`vcall'{28,{flat}}(a1: s_GameSystems.m_Memory.m_pMemory[i]);
  v1->EndLock(this: v1);
  if ( s_pMapName != nullptr )
  {
    free(pMem: s_pMapName);
    s_pMapName = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161540
// Name: public: static void IGameSystem::OnSaveAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IGameSystem::OnSaveAllSystems()
{
  InvokeMethod(f:  __thiscall IGameSystem::`vcall'{32,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x10161550
// Name: public: static void IGameSystem::OnRestoreAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IGameSystem::OnRestoreAllSystems()
{
  InvokeMethod(f:  __thiscall IGameSystem::`vcall'{36,{flat}});
}

//------------------------------------------------------------------------------
// Address: 0x10161560
// Name: public: static void IGameSystem::FrameUpdatePreEntityThinkAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IGameSystem::FrameUpdatePreEntityThinkAllSystems()
{
  int m_Size; // edi
  int i; // esi

  m_Size = s_GameSystemsPerFrame.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IGameSystemPerFrame::`vcall'{52,{flat}}(a1: s_GameSystemsPerFrame.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10161590
// Name: public: static void IGameSystem::FrameUpdatePostEntityThinkAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IGameSystem::FrameUpdatePostEntityThinkAllSystems()
{
  IMDLCache *v0; // esi
  int m_Size; // edi
  int i; // edi
  int v3; // edi
  int j; // esi

  v0 = mdlcache;
  m_Size = s_GameSystems.m_Size;
  mdlcache->BeginLock(this: mdlcache);
  for ( i = m_Size - 1; i >= 0; --i )
     __thiscall IGameSystem::`vcall'{40,{flat}}(a1: s_GameSystems.m_Memory.m_pMemory[i]);
  v0->EndLock(this: v0);
  v3 = s_GameSystemsPerFrame.m_Size;
  for ( j = 0; j < v3; ++j )
     __thiscall IGameSystemPerFrame::`vcall'{56,{flat}}(a1: s_GameSystemsPerFrame.m_Memory.m_pMemory[j]);
}

//------------------------------------------------------------------------------
// Address: 0x10161600
// Name: public: static void IGameSystem::PreClientUpdateAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl IGameSystem::PreClientUpdateAllSystems()
{
  int m_Size; // edi
  int i; // esi

  m_Size = s_GameSystemsPerFrame.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IGameSystemPerFrame::`vcall'{60,{flat}}(a1: s_GameSystemsPerFrame.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10161630
// Name: public: static void IGameSystem::Remove(class IGameSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IGameSystem::Remove(IGameSystem *pSys)
{
  vgui::TreeNode *v1; // esi
  vgui::TreeNode *src; // [esp+4h] [ebp-4h] BYREF

  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_GameSystems,
    src: (vgui::TreeNode **)&pSys);
  v1 = (vgui::TreeNode *)pSys;
  if ( __RTDynamicCast(
         inptr: pSys,
         VfDelta: 0,
         SrcType: &IGameSystem `RTTI Type Descriptor',
         TargetType: &IGameSystemPerFrame `RTTI Type Descriptor',
         isReference: 0) != nullptr )
  {
    src = v1;
    CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_GameSystemsPerFrame,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161680
// Name: public: virtual IGameSystem::~IGameSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IGameSystem::~IGameSystem(IGameSystem *this)
{
  vgui::TreeNode *src; // [esp+4h] [ebp-4h] BYREF

  this->__vftable = (IGameSystem_vtbl *)&IGameSystem::`vftable';
  src = (vgui::TreeNode *)this;
  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_GameSystems,
    &src);
  if ( __RTDynamicCast(
         inptr: this,
         VfDelta: 0,
         SrcType: &IGameSystem `RTTI Type Descriptor',
         TargetType: &IGameSystemPerFrame `RTTI Type Descriptor',
         isReference: 0) != nullptr )
  {
    src = (vgui::TreeNode *)this;
    CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_GameSystemsPerFrame,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101616D0
// Name: public: virtual IGameSystemPerFrame::~IGameSystemPerFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IGameSystemPerFrame::~IGameSystemPerFrame(IGameSystemPerFrame *this)
{
  vgui::TreeNode *src; // [esp+4h] [ebp-4h] BYREF

  this->__vftable = (IGameSystemPerFrame_vtbl *)&IGameSystemPerFrame::`vftable';
  src = (vgui::TreeNode *)this;
  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_GameSystems,
    &src);
  if ( __RTDynamicCast(
         inptr: this,
         VfDelta: 0,
         SrcType: &IGameSystem `RTTI Type Descriptor',
         TargetType: &IGameSystemPerFrame `RTTI Type Descriptor',
         isReference: 0) != nullptr )
  {
    src = (vgui::TreeNode *)this;
    CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_GameSystemsPerFrame,
      &src);
  }
  this->__vftable = (IGameSystemPerFrame_vtbl *)&IGameSystem::`vftable';
  src = (vgui::TreeNode *)this;
  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_GameSystems,
    &src);
  if ( __RTDynamicCast(
         inptr: this,
         VfDelta: 0,
         SrcType: &IGameSystem `RTTI Type Descriptor',
         TargetType: &IGameSystemPerFrame `RTTI Type Descriptor',
         isReference: 0) != nullptr )
  {
    src = (vgui::TreeNode *)this;
    CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_GameSystemsPerFrame,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161770
// Name: public: static void IGameSystem::Add(class IGameSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IGameSystem::Add(IGameSystemPerFrame *pSys)
{
  int m_Size; // eax
  int v2; // esi
  IGameSystem **m_pMemory; // ecx
  int v4; // eax
  IGameSystem **v5; // eax
  int v6; // eax
  int v7; // esi
  IGameSystemPerFrame **v8; // ecx
  int v9; // eax
  IGameSystemPerFrame **v10; // eax

  m_Size = s_GameSystems.m_Size;
  v2 = s_GameSystems.m_Size;
  if ( s_GameSystems.m_Size + 1 > s_GameSystems.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&s_GameSystems,
      num: s_GameSystems.m_Size - s_GameSystems.m_Memory.m_nAllocationCount + 1);
    m_Size = s_GameSystems.m_Size;
  }
  m_pMemory = s_GameSystems.m_Memory.m_pMemory;
  s_GameSystems.m_Size = m_Size + 1;
  v4 = m_Size - v2;
  s_GameSystems.m_pElements = s_GameSystems.m_Memory.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(
      dest: &s_GameSystems.m_Memory.m_pMemory[v2 + 1],
      src: &s_GameSystems.m_Memory.m_pMemory[v2],
      count: 4 * v4);
    m_pMemory = s_GameSystems.m_Memory.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = pSys;
  if ( __RTDynamicCast(
         inptr: pSys,
         VfDelta: 0,
         SrcType: &IGameSystem `RTTI Type Descriptor',
         TargetType: &IGameSystemPerFrame `RTTI Type Descriptor',
         isReference: 0) != nullptr )
  {
    v6 = s_GameSystemsPerFrame.m_Size;
    v7 = s_GameSystemsPerFrame.m_Size;
    if ( s_GameSystemsPerFrame.m_Size + 1 > s_GameSystemsPerFrame.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&s_GameSystemsPerFrame,
        num: s_GameSystemsPerFrame.m_Size - s_GameSystemsPerFrame.m_Memory.m_nAllocationCount + 1);
      v6 = s_GameSystemsPerFrame.m_Size;
    }
    v8 = s_GameSystemsPerFrame.m_Memory.m_pMemory;
    s_GameSystemsPerFrame.m_Size = v6 + 1;
    v9 = v6 - v7;
    s_GameSystemsPerFrame.m_pElements = s_GameSystemsPerFrame.m_Memory.m_pMemory;
    if ( v9 > 0 )
    {
      _V_memmove(
        dest: &s_GameSystemsPerFrame.m_Memory.m_pMemory[v7 + 1],
        src: &s_GameSystemsPerFrame.m_Memory.m_pMemory[v7],
        count: 4 * v9);
      v8 = s_GameSystemsPerFrame.m_Memory.m_pMemory;
    }
    v10 = &v8[v7];
    if ( v10 != nullptr )
      *v10 = pSys;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161860
// Name: public: static bool IGameSystem::InitAllSystems(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IGameSystem::InitAllSystems()
{
  IGameSystemPerFrame *v0; // esi
  int v1; // eax
  CAutoGameSystemPerFrame *v2; // esi
  int v3; // eax
  IMDLCache *v4; // esi
  IMDLCache *v5; // edi
  IGameSystem *v6; // ebx
  const char *v8; // eax
  int i; // [esp+Ch] [ebp-4h]

  v0 = (IGameSystemPerFrame *)s_pSystemList;
  if ( s_pSystemList != nullptr )
  {
    do
    {
      v1 = 0;
      if ( s_GameSystems.m_Size <= 0 )
        goto LABEL_5;
      while ( s_GameSystems.m_Memory.m_pMemory[v1] != v0 )
      {
        if ( ++v1 >= s_GameSystems.m_Size )
          goto LABEL_5;
      }
      if ( v1 == -1 )
LABEL_5:
        IGameSystem::Add(pSys: v0);
      else
        _DevWarning(a1: 1, a2: "AutoGameSystem already added to game system list!!!\n");
      v0 = (IGameSystemPerFrame *)v0[1].__vftable;
    }
    while ( v0 != nullptr );
  }
  v2 = s_pPerFrameSystemList;
  for ( s_pSystemList = nullptr; v2 != nullptr; v2 = v2->m_pNext )
  {
    v3 = 0;
    if ( s_GameSystems.m_Size <= 0 )
      goto LABEL_14;
    while ( s_GameSystems.m_Memory.m_pMemory[v3] != v2 )
    {
      if ( ++v3 >= s_GameSystems.m_Size )
        goto LABEL_14;
    }
    if ( v3 == -1 )
LABEL_14:
      IGameSystem::Add(pSys: v2);
    else
      _DevWarning(a1: 1, a2: "AutoGameSystem already added to game system list!!!\n");
  }
  s_pSystemList = nullptr;
  s_bSystemsInitted = true;
  i = 0;
  if ( s_GameSystems.m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    v4 = mdlcache;
    mdlcache->BeginCoarseLock(this: mdlcache);
    v5 = mdlcache;
    mdlcache->BeginLock(this: mdlcache);
    v6 = s_GameSystems.m_Memory.m_pMemory[i];
    if ( !v6->Init(this: v6) )
      break;
    v5->EndLock(this: v5);
    v4->EndCoarseLock(this: v4);
    if ( ++i >= s_GameSystems.m_Size )
      return 1;
  }
  v8 = (const char *)v6->Name(this: v6);
  _DevWarning(a1: 1, a2: "Failed to load %s\n", v8);
  v5->EndLock(this: v5);
  v4->EndCoarseLock(this: v4);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101619E0
// Name: public: CAutoGameSystem::CAutoGameSystem(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAutoGameSystem *__thiscall CAutoGameSystem::CAutoGameSystem(CAutoGameSystem *this, const char *name)
{
  bool v2; // zf

  v2 = !s_bSystemsInitted;
  this->__vftable = (CAutoGameSystem_vtbl *)&CAutoGameSystem::`vftable';
  this->m_pszName = name;
  if ( v2 )
  {
    this->m_pNext = s_pSystemList;
    s_pSystemList = this;
  }
  else
  {
    IGameSystem::Add(pSys: (IGameSystemPerFrame *)this);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10161AA0
// Name: public: CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAutoGameSystemPerFrame *__thiscall CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(
        CAutoGameSystemPerFrame *this,
        const char *name)
{
  bool v2; // zf

  v2 = !s_bSystemsInitted;
  this->__vftable = (CAutoGameSystemPerFrame_vtbl *)&CAutoGameSystemPerFrame::`vftable';
  this->m_pszName = name;
  if ( v2 )
  {
    this->m_pNext = s_pPerFrameSystemList;
    s_pPerFrameSystemList = this;
  }
  else
  {
    IGameSystem::Add(pSys: this);
  }
  return this;
}

} // namespace server
