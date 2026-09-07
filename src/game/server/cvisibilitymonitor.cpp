// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cvisibilitymonitor.cpp
// Functions: 11
// ============================================================

#include "game\server\cvisibilitymonitor.h"

//------------------------------------------------------------------------------
// Address: 0x100FA300
// Name: public: virtual void CVisibilityMonitor::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibilityMonitor::LevelInitPostEntity(CVisibilityMonitor *this)
{
  this->m_iMaxTracesPerThink = 0;
  this->m_iMaxEntitiesPerThink = 0;
  this->m_iStartElement = 0;
  this->m_flTimeNextPoll = vismon_poll_frequency.m_pParent->m_Value.m_fValue + gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x100FA330
// Name: public: virtual bool CVisibilityMonitor::EntityIsVisibleToPlayer(struct visibility_target_t const __near &,class CBasePlayer __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVisibilityMonitor::EntityIsVisibleToPlayer(
        CVisibilityMonitor *this,
        const visibility_target_t *target,
        CBasePlayer *pPlayer,
        int *numTraces)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  IHandleEntity *v6; // ecx
  CBaseCombatCharacter *v7; // esi
  unsigned int v8; // eax
  IHandleEntity *v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // eax
  CBaseEntity *v12; // ecx
  CGameTrace tr; // [esp+10h] [ebp-6Ch] BYREF
  Vector vecPlayerOrigin; // [esp+64h] [ebp-18h] BYREF
  Vector vecTargetOrigin; // [esp+70h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+7Ch] [ebp+0h] BYREF

  m_Index = target->entity.m_Index;
  if ( target->entity.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  if ( BYTE1(m_pEntity[45].__vftable) == 10 )
  {
    v6 = m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
       ? nullptr
       : g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( ((int)v6[65].__vftable & 8) == 0 )
      return 0;
  }
  v7 = pPlayer->ActivePlayerCombatCharacter(this: pPlayer);
  v8 = target->entity.m_Index;
  if ( target->entity.m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
    v9 = nullptr;
  else
    v9 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
  vecTargetOrigin = *(Vector *)((int (__thiscall *)(IHandleEntity *))v9->__vftable[49].dtr_IHandleEntity)(a1: v9);
  v7->EyePosition(this: v7, result: &vecPlayerOrigin);
  if ( target->minDistSqr < (float)((float)((float)((float)(vecPlayerOrigin.y - vecTargetOrigin.y)
                                                  * (float)(vecPlayerOrigin.y - vecTargetOrigin.y))
                                          + (float)((float)(vecPlayerOrigin.x - vecTargetOrigin.x)
                                                  * (float)(vecPlayerOrigin.x - vecTargetOrigin.x)))
                                  + (float)((float)(vecPlayerOrigin.z - vecTargetOrigin.z)
                                          * (float)(vecPlayerOrigin.z - vecTargetOrigin.z))) )
    return 0;
  ++*numTraces;
  v10 = 33570817;
  if ( target->bNotVisibleThroughGlass )
    v10 = 33570819;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)v7,
    vecAbsStart: &vecPlayerOrigin,
    vecAbsEnd: &vecTargetOrigin,
    mask: v10,
    ignore: v7,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.fraction != 1.0 )
  {
    v11 = target->entity.m_Index;
    if ( target->entity.m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
    {
      v12 = nullptr;
    }
    else
    {
      v12 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
    }
    if ( tr.m_pEnt != v12 )
    {
      if ( debug_visibility_monitor.m_pParent != nullptr && debug_visibility_monitor.m_pParent->m_Value.m_nValue > 1 )
        NDebugOverlay::Line(
          origin: &vecPlayerOrigin,
          target: &vecTargetOrigin,
          r: 255,
          g: 0,
          b: 0,
          noDepthTest: false,
          duration: vismon_poll_frequency.m_pParent->m_Value.m_fValue);
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FA510
// Name: public: bool CVisibilityMonitor::IsTrackingEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVisibilityMonitor::IsTrackingEntity(CVisibilityMonitor *this, CBaseEntity *pEntity)
{
  int m_Size; // edi
  int v3; // edx
  visibility_target_t *i; // esi
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx

  m_Size = this->m_Entities.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = this->m_Entities.m_Memory.m_pMemory; ; ++i )
  {
    m_Index = i->entity.m_Index;
    if ( i->entity.m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    }
    if ( m_pEntity == pEntity )
      break;
    if ( ++v3 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FA570
// Name: public: virtual void CVisibilityMonitor::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVisibilityMonitor::FrameUpdatePostEntityThink(
        CVisibilityMonitor *this@<ecx>,
        int a2@<ebx>,
        IGameEvent *a3@<edi>,
        const char *a4@<esi>)
{
  float curtime; // xmm0_4
  CVisibilityMonitor *v5; // esi
  float m_flTimeNextPoll; // xmm1_4
  int v7; // ebx
  int m_Size; // eax
  int v9; // edx
  unsigned int m_Index; // eax
  int v11; // eax
  visibility_target_t *m_pMemory; // ecx
  int v13; // eax
  __int64 v14; // xmm0_8
  int v15; // eax
  int m_iStartElement; // ecx
  int v17; // ebx
  CGlobalVars *v18; // ecx
  ConVar *m_pParent; // edx
  int v20; // edi
  CBasePlayer *v21; // ebx
  const visibility_target_t *v22; // edx
  unsigned int v23; // eax
  CBaseEntity **v24; // ecx
  CBaseEntity *v25; // edi
  visibility_target_t *v26; // edx
  unsigned int v27; // eax
  IHandleEntity *m_pEntity; // ecx
  const Vector *v29; // eax
  visibility_target_t *v30; // edx
  unsigned int v31; // eax
  IHandleEntity *v32; // ecx
  const Vector *v33; // eax
  IGameEvent *v34; // esi
  int v35; // eax
  signed int m_pPev; // eax
  const char *pszValue; // eax
  const char *v38; // edi
  int m_nValue; // eax
  int v40; // eax
  const char *flDuration; // [esp+1Ch] [ebp-34h]
  const char *flDuration_4; // [esp+20h] [ebp-30h]
  int i; // [esp+30h] [ebp-20h]
  int memoryBit; // [esp+34h] [ebp-1Ch]
  int numTraces; // [esp+38h] [ebp-18h] BYREF
  int j; // [esp+3Ch] [ebp-14h]
  int v50; // [esp+40h] [ebp-10h]
  CVisibilityMonitor *v51; // [esp+44h] [ebp-Ch]
  int iDebugging; // [esp+48h] [ebp-8h]
  bool bIgnore; // [esp+4Fh] [ebp-1h]

  curtime = gpGlobals->curtime;
  v5 = this;
  m_flTimeNextPoll = this->m_flTimeNextPoll;
  v51 = this;
  if ( m_flTimeNextPoll > curtime )
    return;
  this->m_flTimeNextPoll = vismon_poll_frequency.m_pParent->m_Value.m_fValue + curtime;
  v7 = 0;
  if ( debug_visibility_monitor.m_pParent != nullptr )
    iDebugging = debug_visibility_monitor.m_pParent->m_Value.m_nValue;
  else
    iDebugging = 0;
  m_Size = this->m_Entities.m_Size;
  if ( m_Size > this->m_iMaxEntitiesPerThink )
    this->m_iMaxEntitiesPerThink = m_Size;
  if ( iDebugging > 1 )
  {
    _Msg(a1: "\nVisMon: Polling now. (Frequency: %f)\n", this->m_flPollFrequency);
    _Msg(
      a1: "VisMon: Time: %f - Tracking %d Entities. (Max:%d)\n",
      gpGlobals->curtime,
      v5->m_Entities.m_Size,
      v5->m_iMaxEntitiesPerThink);
  }
  if ( v5->m_Entities.m_Size > 0 )
  {
    v9 = 0;
    do
    {
      m_Index = v5->m_Entities.m_Memory.m_pMemory[v9].entity.m_Index;
      if ( m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
      {
        v11 = v5->m_Entities.m_Size;
        if ( v11 > 0 )
        {
          if ( v7 != v11 - 1 )
          {
            m_pMemory = v5->m_Entities.m_Memory.m_pMemory;
            v13 = v11;
            v14 = *(_QWORD *)&m_pMemory[v13 - 1].entity.m_Index;
            v15 = (int)&m_pMemory[v13 - 1];
            *(_QWORD *)&m_pMemory[v9].entity.m_Index = v14;
            *(_QWORD *)&m_pMemory[v9].memory = *(_QWORD *)(v15 + 8);
            *(_QWORD *)&m_pMemory[v9].pfnCallback = *(_QWORD *)(v15 + 16);
          }
          --v5->m_Entities.m_Size;
        }
        if ( v7 >= v5->m_Entities.m_Size )
          break;
      }
      ++v7;
      ++v9;
    }
    while ( v7 < v5->m_Entities.m_Size );
  }
  m_iStartElement = v5->m_iStartElement;
  numTraces = 0;
  if ( m_iStartElement >= v5->m_Entities.m_Size )
  {
    if ( iDebugging > 1 )
      _Msg(a1: "VisMon: RESET\n");
    v5->m_iStartElement = 0;
  }
  if ( iDebugging > 1 )
    _Msg(a1: "VisMon: Starting at element: %d\n", v5->m_iStartElement);
  v17 = v5->m_iStartElement;
  i = v17;
  if ( v17 >= v5->m_Entities.m_Size )
  {
LABEL_73:
    v5->m_iStartElement = 0;
    goto LABEL_74;
  }
  v18 = gpGlobals;
  m_pParent = vismon_trace_limit.m_pParent;
  v50 = 24 * v17;
  while ( 2 )
  {
    v20 = 1;
    j = 1;
    if ( v18->maxClients < 1 )
      goto LABEL_68;
    do
    {
      v21 = UTIL_PlayerByIndex(playerIndex: v20);
      if ( v21 != nullptr && v21->IsAlive(this: v21) && !v21->IsBot(this: v21) )
      {
        v22 = &v5->m_Entities.m_Memory.m_pMemory[v50 / 0x18u];
        memoryBit = 1 << v20;
        v23 = v22->entity.m_Index;
        if ( v22->entity.m_Index != -1 )
        {
          v24 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v23];
          if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_SerialNumber == HIWORD(v23) )
          {
            v25 = *v24;
            if ( *v24 != nullptr
              && (memoryBit & v22->memory) == 0
              && v5->EntityIsVisibleToPlayer(this: v5, a2: v22, a3: v21, a4: &numTraces) )
            {
              v26 = &v5->m_Entities.m_Memory.m_pMemory[v50 / 0x18u];
              bIgnore = false;
              if ( v26->pfnEvaluator != nullptr )
              {
                v27 = v26->entity.m_Index;
                if ( v26->entity.m_Index == -1
                  || (v5 = v51, g_pEntityList->m_EntPtrArray[(unsigned __int16)v27].m_SerialNumber != HIWORD(v27)) )
                {
                  m_pEntity = nullptr;
                }
                else
                {
                  m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v27].m_pEntity;
                }
                if ( !v26->pfnEvaluator(a1: (CBaseEntity *)m_pEntity, a2: v21) )
                  bIgnore = true;
              }
              if ( iDebugging > 0 )
              {
                flDuration_4 = CBaseEntity::GetDebugName(this: v25);
                flDuration = CBaseEntity::GetDebugName(this: v21);
                if ( !bIgnore )
                {
                  _Msg(a1: "VisMon: Player %s sees Entity: %s\n", flDuration, flDuration_4);
                  v33 = v25->WorldSpaceCenter(this: v25);
                  NDebugOverlay::Cross3D(
                    position: v33,
                    size: 16.0,
                    r: 0,
                    g: 255,
                    b: 0,
                    noDepthTest: false,
                    flDuration: 10.0);
LABEL_48:
                  v30 = &v5->m_Entities.m_Memory.m_pMemory[v50 / 0x18u];
                  if ( v30->pfnCallback == nullptr
                    || ((v31 = v30->entity.m_Index, v30->entity.m_Index == -1)
                     || (v5 = v51, g_pEntityList->m_EntPtrArray[(unsigned __int16)v31].m_SerialNumber != HIWORD(v31))
                      ? (v32 = nullptr)
                      : (v32 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v31].m_pEntity),
                        v30->pfnCallback(a1: (CBaseEntity *)v32, a2: v21)) )
                  {
                    v34 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "entity_visible", a3: 0, a4: 0);
                    if ( v34 != nullptr )
                    {
                      v35 = ((int (__thiscall *)(IVEngineServer *, edict_t *, IGameEvent *, int, const char *))engine->GetPlayerUserId)(
                              a1: engine,
                              a2: v21->m_Network.m_pPev,
                              a3,
                              a4: a2,
                              a5: a4);
                      v34->SetInt(this: v34, a2: "userid", a3: v35);
                      m_pPev = (signed int)v25->m_Network.m_pPev;
                      if ( m_pPev != 0 )
                        m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
                      v34->SetInt(this: v34, a2: "subject", a3: m_pPev);
                      pszValue = v25->m_iClassname.pszValue;
                      if ( pszValue == nullptr )
                        pszValue = locale;
                      v34->SetString(this: v34, a2: "classname", a3: pszValue);
                      v38 = v25->m_iName.m_Value.pszValue;
                      if ( v38 == nullptr )
                        v38 = locale;
                      a4 = v38;
                      ((void (__thiscall *)(IGameEvent *, const char *))v34->SetString)(a1: v34, a2: "entityname");
                      a2 = 0;
                      a3 = v34;
                      ((void (__thiscall *)(IGameEventManager2 *))gameeventmanager->FireEvent)(a1: gameeventmanager);
                    }
                    v5 = v51;
                  }
                  v5->m_Entities.m_Memory.m_pMemory[v50 / 0x18u].memory |= memoryBit;
                  goto LABEL_65;
                }
                _Msg(a1: "VisMon: Player %s IGNORING VISIBILE Entity: %s\n", flDuration, flDuration_4);
                v29 = v25->WorldSpaceCenter(this: v25);
                NDebugOverlay::Cross3D(
                  position: v29,
                  size: 16.0,
                  r: 255,
                  g: 0,
                  b: 0,
                  noDepthTest: false,
                  flDuration: 10.0);
              }
              if ( !bIgnore )
                goto LABEL_48;
            }
          }
LABEL_65:
          v20 = j;
        }
      }
      v18 = gpGlobals;
      j = ++v20;
    }
    while ( v20 <= gpGlobals->maxClients );
    m_pParent = vismon_trace_limit.m_pParent;
    v17 = i;
LABEL_68:
    if ( m_pParent != nullptr )
      m_nValue = m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( numTraces < m_nValue )
    {
      v50 += 24;
      i = ++v17;
      if ( v17 >= v5->m_Entities.m_Size )
        goto LABEL_73;
      continue;
    }
    break;
  }
  if ( iDebugging > 1 )
    _Msg(a1: "VisMon: MAX Traces. Stopping after element %d\n", v17);
  v5->m_iStartElement = v17 + 1;
LABEL_74:
  v40 = numTraces;
  if ( numTraces > v5->m_iMaxTracesPerThink )
    v5->m_iMaxTracesPerThink = numTraces;
  if ( iDebugging > 1 )
    _Msg(a1: "VisMon: %d traces performed during this polling cycle (Max: %d)\n\n", v40, v5->m_iMaxTracesPerThink);
}

//------------------------------------------------------------------------------
// Address: 0x100FAB00
// Name: public: virtual char const __near * CVisibilityMonitor::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVisibilityMonitor::Name(CVisibilityMonitor *this)
{
  return "VisibilityMonitor";
}

//------------------------------------------------------------------------------
// Address: 0x100FAB40
// Name: public: void CVisibilityMonitor::AddEntity(class CBaseEntity __near *,float,bool (*)(class CBaseEntity __near *,class CBasePlayer __near *),bool (*)(class CBaseEntity __near *,class CBasePlayer __near *),bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibilityMonitor::AddEntity(
        CVisibilityMonitor *this,
        CBaseEntity *pEntity,
        float flMinDist,
        bool (__cdecl *pfnCallback)(CBaseEntity *, CBasePlayer *),
        bool (__cdecl *pfnEvaluator)(CBaseEntity *, CBasePlayer *),
        bool bNotVisibleThroughGlass)
{
  const char *pszValue; // edi
  const char *DebugName; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  visibility_target_t newTarget; // [esp+8h] [ebp-18h] BYREF

  if ( CVisibilityMonitor::IsTrackingEntity(this, pEntity) == 0 )
  {
    newTarget.entity.m_Index = pEntity != nullptr ? pEntity->GetRefEHandle(this: pEntity)->m_Index : -1;
    newTarget.pfnCallback = pfnCallback;
    newTarget.pfnEvaluator = pfnEvaluator;
    newTarget.bNotVisibleThroughGlass = bNotVisibleThroughGlass;
    m_Size = this->m_Entities.m_Size;
    newTarget.minDistSqr = flMinDist * flMinDist;
    newTarget.memory = 0;
    CUtlVector<visibility_target_t,CUtlMemory<visibility_target_t,int>>::InsertBefore(
      this: &this->m_Entities,
      elem: m_Size,
      src: &newTarget);
    if ( debug_visibility_monitor.m_pParent != nullptr && debug_visibility_monitor.m_pParent->m_Value.m_nValue != 0 )
    {
      pszValue = pEntity->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      DebugName = CBaseEntity::GetDebugName(this: pEntity);
      _Msg(a1: "VisMon: Added Entity: %s (%s)\n", pszValue, DebugName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FABF0
// Name: void VisibilityMonitor_AddEntity(class CBaseEntity __near *,float,bool (*)(class CBaseEntity __near *,class CBasePlayer __near *),bool (*)(class CBaseEntity __near *,class CBasePlayer __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl VisibilityMonitor_AddEntity(
        CBaseEntity *pEntity,
        float flMinDist,
        bool (__cdecl *pfnCallback)(CBaseEntity *, CBasePlayer *),
        bool (__cdecl *pfnEvaluator)(CBaseEntity *, CBasePlayer *))
{
  CVisibilityMonitor::AddEntity(
    this: &VisibilityMonitor,
    pEntity,
    flMinDist,
    pfnCallback,
    pfnEvaluator,
    bNotVisibleThroughGlass: false);
}

//------------------------------------------------------------------------------
// Address: 0x10401870
// Name: _dynamic_initializer_for__VisibilityMonitor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__VisibilityMonitor__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &VisibilityMonitor, name: "CVisibilityMonitor");
  VisibilityMonitor.m_flPollFrequency = 1.0;
  VisibilityMonitor.__vftable = (CVisibilityMonitor_vtbl *)&CVisibilityMonitor::`vftable';
  VisibilityMonitor.m_Entities.m_Memory.m_pMemory = nullptr;
  VisibilityMonitor.m_Entities.m_Memory.m_nAllocationCount = 0;
  VisibilityMonitor.m_Entities.m_Memory.m_nGrowSize = 0;
  VisibilityMonitor.m_Entities.m_Size = 0;
  VisibilityMonitor.m_Entities.m_pElements = nullptr;
  VisibilityMonitor.m_flTimeNextPoll = 0.0;
  return atexit(func: dynamic_atexit_destructor_for__VisibilityMonitor__);
}

//------------------------------------------------------------------------------
// Address: 0x1041A730
// Name: _dynamic_atexit_destructor_for__VisibilityMonitor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__VisibilityMonitor__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&VisibilityMonitor.m_Entities);
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &VisibilityMonitor);
}

//------------------------------------------------------------------------------
// Address: 0x104018D0
// Name: _dynamic_initializer_for__g_DecalSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DecalSystem__()
{
  CDecalEmitterSystem::CDecalEmitterSystem(this: &g_DecalSystem, name: "CDecalEmitterSystem");
  return atexit(func: dynamic_atexit_destructor_for__g_DecalSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x1041A750
// Name: _dynamic_atexit_destructor_for__g_DecalSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DecalSystem__()
{
  CUtlDict<int,int>::RemoveAll(this: &g_DecalSystem.m_GameMaterialTranslation);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &g_DecalSystem.m_GameMaterialTranslation.m_Elements.m_Tree);
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_DecalSystem.m_DecalFileNames);
  CUtlDict<CDecalEmitterSystem::DecalEntry,int>::RemoveAll(this: &g_DecalSystem.m_Decals);
  CUtlRBTree<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int,CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int,CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int>,int>>(this: &g_DecalSystem.m_Decals.m_Elements.m_Tree);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_DecalSystem.m_AllDecals);
  IGameSystem::~IGameSystem(this: &g_DecalSystem.CAutoGameSystem);
}
