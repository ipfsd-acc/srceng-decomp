// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/bot/bot_manager.cpp
// Functions: 12
// ============================================================

#include "game\shared\cstrike15\bot\bot_manager.h"

//------------------------------------------------------------------------------
// Address: 0x102CA640
// Name: public: bool CBotManager::ForEachGrenade<class GrenadeResponse>(class GrenadeResponse __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBotManager::ForEachGrenade<GrenadeResponse>(CBotManager *this, GrenadeResponse *func)
{
  int m_Head; // esi
  CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *p_m_activeGrenadeList; // edi
  ActiveGrenade *m_Element; // ebx
  unsigned __int16 current; // [esp+Ch] [ebp-4h]

  m_Head = this->m_activeGrenadeList.m_Head;
  if ( m_Head == 0xFFFF )
    return 1;
  p_m_activeGrenadeList = (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_activeGrenadeList;
  while ( 1 )
  {
    m_Element = (ActiveGrenade *)p_m_activeGrenadeList->m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Element;
    current = m_Head;
    m_Head = p_m_activeGrenadeList->m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
    if ( ActiveGrenade::IsValid(this: m_Element) )
      break;
    CUtlLinkedList<CFuncAreaPortalBase *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncAreaPortalBase *,unsigned short>,unsigned short>>::Unlink(
      this: p_m_activeGrenadeList,
      elem: current);
    p_m_activeGrenadeList->m_Memory.m_pMemory[current].m_Next = p_m_activeGrenadeList->m_FirstFree;
    p_m_activeGrenadeList->m_FirstFree = current;
    free(pMem: m_Element);
LABEL_6:
    if ( m_Head == 0xFFFF )
      return 1;
  }
  if ( GrenadeResponse::operator()(this: func, ag: m_Element) != 0 )
    goto LABEL_6;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102CD9D0
// Name: public: void CBotManager::RemoveGrenade(class CBaseGrenade __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBotManager::RemoveGrenade(CBotManager *this, CBaseGrenade *grenade)
{
  int m_Head; // eax
  UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *m_pMemory; // edx
  ActiveGrenade *m_Element; // ecx
  UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *v5; // eax

  m_Head = this->m_activeGrenadeList.m_Head;
  if ( m_Head != 0xFFFF )
  {
    m_pMemory = this->m_activeGrenadeList.m_Memory.m_pMemory;
    while ( 1 )
    {
      m_Element = m_pMemory[(unsigned __int16)m_Head].m_Element;
      v5 = &m_pMemory[(unsigned __int16)m_Head];
      if ( grenade == m_Element->m_entity )
        break;
      m_Head = v5->m_Next;
      if ( m_Head == 0xFFFF )
        return;
    }
    ActiveGrenade::OnEntityGone(this: m_Element);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CDA10
// Name: public: void CBotManager::SetGrenadeRadius(class CBaseGrenade __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBotManager::SetGrenadeRadius(CBotManager *this, CBaseGrenade *grenade, float radius)
{
  int m_Head; // eax
  UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *m_pMemory; // edx
  ActiveGrenade *m_Element; // ecx
  UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *v6; // eax

  m_Head = this->m_activeGrenadeList.m_Head;
  if ( m_Head != 0xFFFF )
  {
    m_pMemory = this->m_activeGrenadeList.m_Memory.m_pMemory;
    while ( 1 )
    {
      m_Element = m_pMemory[(unsigned __int16)m_Head].m_Element;
      v6 = &m_pMemory[(unsigned __int16)m_Head];
      if ( grenade == m_Element->m_entity )
        break;
      m_Head = v6->m_Next;
      if ( m_Head == 0xFFFF )
        return;
    }
    m_Element->m_radius = radius;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CDA60
// Name: public: bool CBotManager::IsLineBlockedBySmoke(class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CBotManager::IsLineBlockedBySmoke@<al>(
        CBotManager *this@<ecx>,
        int a2@<ebp>,
        const Vector *from,
        const Vector *to,
        float grenadeBloat)
{
  int v5; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  float v10; // xmm4_4
  float v11; // xmm0_4
  float x; // xmm1_4
  float y; // xmm2_4
  float v14; // xmm5_4
  float z; // xmm7_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm5_4
  float v21; // xmm7_4
  float v22; // xmm5_4
  float v23; // xmm7_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm4_4
  bool v27; // cc
  float v28; // xmm4_4
  float v29; // xmm6_4
  float v30; // xmm0_4
  float v32; // [esp-14h] [ebp-68h]
  float toClose; // [esp+0h] [ebp-54h]
  float toClose_4; // [esp+4h] [ebp-50h]
  float toClose_8; // [esp+8h] [ebp-4Ch]
  Vector toGrenade; // [esp+Ch] [ebp-48h] BYREF
  Vector sightDir; // [esp+18h] [ebp-3Ch]
  float v38; // [esp+24h] [ebp-30h]
  float sightLength; // [esp+28h] [ebp-2Ch]
  float toSq; // [esp+2Ch] [ebp-28h]
  float lengthSq; // [esp+30h] [ebp-24h]
  float v42; // [esp+34h] [ebp-20h]
  float v43; // [esp+38h] [ebp-1Ch]
  float v44; // [esp+3Ch] [ebp-18h]
  float v45; // [esp+40h] [ebp-14h]
  char v46; // [esp+47h] [ebp-Dh]
  int v47; // [esp+48h] [ebp-Ch]
  float totalSmokedLength; // [esp+4Ch] [ebp-8h]
  float retaddr; // [esp+54h] [ebp+0h]

  v47 = a2;
  totalSmokedLength = retaddr;
  LODWORD(sightDir.z) = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CBotManager::IsLineBlockedBySmoke",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  v45 = 0.0;
  toGrenade.x = to->x - from->x;
  toGrenade.y = to->y - from->y;
  toGrenade.z = to->z - from->z;
  sightDir.y = VectorNormalize(vec: &toGrenade);
  v5 = *(unsigned __int16 *)(LODWORD(sightDir.z) + 16);
  if ( v5 == 0xFFFF )
  {
LABEL_24:
    v46 = 0;
    goto LABEL_25;
  }
  v6 = *(_DWORD *)(LODWORD(sightDir.z) + 4);
  do
  {
    v7 = (unsigned __int16)v5;
    v8 = *(_DWORD *)(v6 + 8 * (unsigned __int16)v5);
    v9 = v6 + 8 * v7;
    v10 = (float)((float)(*(float *)(v8 + 24) * *(float *)(v8 + 24)) * grenadeBloat) * grenadeBloat;
    if ( *(_BYTE *)(v8 + 20) != 0 )
    {
      v11 = *(float *)(v8 + 4);
      x = from->x;
      y = from->y;
      v14 = *(float *)(v8 + 12);
      z = from->z;
      toSq = *(float *)(v8 + 8);
      lengthSq = v11;
      toClose_4 = toSq - y;
      toClose = v11 - x;
      sightLength = v14;
      toClose_8 = v14 - z;
      v16 = (float)((float)((float)(toSq - y) * toGrenade.y) + (float)((float)(v11 - x) * toGrenade.x))
          + (float)((float)(v14 - z) * toGrenade.z);
      if ( v16 >= 0.0 )
      {
        if ( v16 < sightDir.y )
        {
          v20 = y;
          v19 = z + (float)(toGrenade.z * v16);
          v17 = x + (float)(toGrenade.x * v16);
          v18 = v20 + (float)(toGrenade.y * v16);
        }
        else
        {
          v17 = to->x;
          v18 = to->y;
          v19 = to->z;
        }
      }
      else
      {
        v17 = x;
        v18 = y;
        v19 = z;
      }
      v38 = (float)((float)((float)(v18 - toSq) * (float)(v18 - toSq))
                  + (float)((float)(v17 - lengthSq) * (float)(v17 - lengthSq)))
          + (float)((float)(v19 - sightLength) * (float)(v19 - sightLength));
      if ( v10 > v38 )
      {
        v21 = to->y;
        v22 = lengthSq - to->x;
        v44 = to->x;
        v32 = toSq - v21;
        v43 = v21;
        v23 = to->z;
        sightDir.x = toClose_4 * toClose_4;
        sightDir.z = (float)((float)(v32 * v32) + (float)(v22 * v22))
                   + (float)((float)(sightLength - v23) * (float)(sightLength - v23));
        v42 = v23;
        if ( v10 <= (float)((float)((float)(toClose_4 * toClose_4) + (float)(toClose * toClose))
                          + (float)(toClose_8 * toClose_8)) )
        {
          v27 = v10 <= sightDir.z;
          v28 = v10 - v38;
          if ( v27 )
          {
            v24 = fsqrt(v28) * 2.0;
          }
          else
          {
            v29 = fsqrt(v28);
            v30 = fsqrt(
                    (float)((float)((float)(v18 - v43) * (float)(v18 - v43))
                          + (float)((float)(v19 - v42) * (float)(v19 - v42)))
                  + (float)((float)(v17 - v44) * (float)(v17 - v44)));
            if ( (float)((float)((float)((float)(v43 - toSq) * toGrenade.y)
                               + (float)((float)(v44 - lengthSq) * toGrenade.x))
                       + (float)((float)(v42 - sightLength) * toGrenade.z)) <= 0.0 )
            {
              v45 = (float)(v29 - v30) + v45;
              goto LABEL_22;
            }
            v24 = v30 + v29;
          }
        }
        else if ( v10 <= sightDir.z )
        {
          v25 = fsqrt(
                  (float)((float)((float)(v18 - from->y) * (float)(v18 - from->y))
                        + (float)((float)(v19 - from->z) * (float)(v19 - from->z)))
                + (float)((float)(v17 - from->x) * (float)(v17 - from->x)));
          v26 = fsqrt(v10 - v38);
          if ( v16 <= 0.0 )
          {
            v45 = (float)(v26 - v25) + v45;
            goto LABEL_22;
          }
          v24 = v25 + v26;
        }
        else
        {
          v24 = fsqrt(
                  (float)((float)((float)(v43 - from->y) * (float)(v43 - from->y))
                        + (float)((float)(v23 - from->z) * (float)(v23 - from->z)))
                + (float)((float)(v44 - from->x) * (float)(v44 - from->x)));
        }
        v45 = v24 + v45;
      }
    }
LABEL_22:
    v5 = *(unsigned __int16 *)(v9 + 6);
  }
  while ( v5 != 0xFFFF );
  v46 = 1;
  if ( v45 <= 108.5 )
    goto LABEL_24;
LABEL_25:
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v46;
}

//------------------------------------------------------------------------------
// Address: 0x102CDE80
// Name: public: void CBotManager::AddDebugMessage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBotManager::AddDebugMessage(CBotManager *this, const char *msg)
{
  int m_debugMessageCount; // eax
  IntervalTimer *p_m_age; // esi
  double v5; // st7
  float *p_m_Value; // esi
  float msga; // [esp+Ch] [ebp+8h]

  if ( ++this->m_currentDebugMessage >= 6 )
    this->m_currentDebugMessage = 0;
  m_debugMessageCount = this->m_debugMessageCount;
  if ( m_debugMessageCount < 6 )
    this->m_debugMessageCount = m_debugMessageCount + 1;
  V_strncpy(pDest: this->m_debugMessage[this->m_currentDebugMessage].m_string, pSrc: msg, maxLen: 1024);
  p_m_age = &this->m_debugMessage[this->m_currentDebugMessage].m_age;
  v5 = IntervalTimer::Now(this: (CEffectsServer *)p_m_age);
  p_m_Value = &p_m_age->m_timestamp.m_Value;
  if ( *p_m_Value != v5 )
  {
    (*(void (__thiscall **)(float *, float *))(*((_DWORD *)p_m_Value - 1) + 4))(a1: p_m_Value - 1, a2: p_m_Value);
    msga = v5;
    *p_m_Value = msga;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CDF20
// Name: public: CBotManager::CBotManager(void)
// Source: json
//------------------------------------------------------------------------------
CBotManager *__thiscall CBotManager::CBotManager(CBotManager *this)
{
  UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *m_pMemory; // eax
  int v3; // ebx
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // edi
  void (__stdcall *v5)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *); // eax
  IntervalTimer_vtbl *v6; // edx

  this->__vftable = (CBotManager_vtbl *)&CBotManager::`vftable';
  this->m_activeGrenadeList.m_Memory.m_pMemory = nullptr;
  this->m_activeGrenadeList.m_Memory.m_nAllocationCount = 0;
  this->m_activeGrenadeList.m_Memory.m_nGrowSize = 0;
  this->m_activeGrenadeList.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_activeGrenadeList.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_activeGrenadeList.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_activeGrenadeList.m_Head = -1;
  this->m_activeGrenadeList.m_NumAlloced = 0;
  this->m_activeGrenadeList.m_pElements = m_pMemory;
  v3 = 5;
  p_m_timestamp = &this->m_debugMessage[0].m_age.m_timestamp;
  do
  {
    LODWORD(p_m_timestamp[-1].m_Value) = &IntervalTimer::`vftable';
    v5 = *(void (__stdcall **)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))(LODWORD(p_m_timestamp[-1].m_Value)
                                                                                              + 4);
    p_m_timestamp->m_Value = -1.0;
    v5(a1: p_m_timestamp);
    p_m_timestamp += 258;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_frameTimer.__vftable = (IntervalTimer_vtbl *)&IntervalTimer::`vftable';
  v6 = this->m_frameTimer.__vftable;
  this->m_frameTimer.m_timestamp.m_Value = -1.0;
  ((void (__stdcall *)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))v6->NetworkStateChanged)(a1: &this->m_frameTimer.m_timestamp);
  InitBotTrig();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102CDFC0
// Name: public: virtual CBotManager::~CBotManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBotManager::~CBotManager(CBotManager *this)
{
  CUtlLinkedList<ActiveGrenade *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ActiveGrenade *,unsigned short>,unsigned short> > *p_m_activeGrenadeList; // esi

  p_m_activeGrenadeList = &this->m_activeGrenadeList;
  this->__vftable = (CBotManager_vtbl *)&CBotManager::`vftable';
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_activeGrenadeList);
  if ( p_m_activeGrenadeList->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_activeGrenadeList->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_activeGrenadeList->m_Memory.m_pMemory);
      p_m_activeGrenadeList->m_Memory.m_pMemory = nullptr;
    }
    p_m_activeGrenadeList->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CE0E0
// Name: public: virtual void CBotManager::RestartRound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBotManager::RestartRound(CBotManager *this)
{
  CUtlLinkedList<ActiveGrenade *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ActiveGrenade *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(this: &this->m_activeGrenadeList);
  this->m_debugMessageCount = 0;
  this->m_currentDebugMessage = -1;
}

//------------------------------------------------------------------------------
// Address: 0x102CE110
// Name: public: void CBotManager::ValidateActiveGrenades(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBotManager::ValidateActiveGrenades(CBotManager *this)
{
  int m_Head; // esi
  CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *p_m_activeGrenadeList; // edi
  ActiveGrenade *m_Element; // ebx
  unsigned __int16 current; // [esp+4h] [ebp-4h]

  m_Head = this->m_activeGrenadeList.m_Head;
  if ( m_Head != 0xFFFF )
  {
    p_m_activeGrenadeList = (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_activeGrenadeList;
    do
    {
      m_Element = (ActiveGrenade *)p_m_activeGrenadeList->m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Element;
      current = m_Head;
      m_Head = p_m_activeGrenadeList->m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      if ( ActiveGrenade::IsValid(this: m_Element) )
      {
        ActiveGrenade::Update(this: m_Element);
      }
      else
      {
        CUtlLinkedList<CFuncAreaPortalBase *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncAreaPortalBase *,unsigned short>,unsigned short>>::Unlink(
          this: p_m_activeGrenadeList,
          elem: current);
        p_m_activeGrenadeList->m_Memory.m_pMemory[current].m_Next = p_m_activeGrenadeList->m_FirstFree;
        p_m_activeGrenadeList->m_FirstFree = current;
        free(pMem: m_Element);
      }
    }
    while ( m_Head != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CE190
// Name: public: virtual void CBotManager::StartFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBotManager::StartFrame(CBotManager *this)
{
  int i; // eax
  int v3; // edi
  ActiveGrenade *m_Element; // esi
  float v5; // xmm0_4
  double v6; // st7
  float v7; // xmm0_4
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  double v9; // st7
  int v10; // edi
  CBasePlayer *v11; // eax
  _DWORD *v12; // esi
  int v13; // eax
  char *v14; // eax
  char *v15; // esi
  int v16; // eax
  signed int v17; // eax
  void (__thiscall *v18)(char *); // eax
  Vector v19; // [esp-10h] [ebp-60h]
  Vector v20; // [esp-4h] [ebp-54h]
  Vector lastEdge; // [esp+30h] [ebp-20h]
  Vector lastEdgea; // [esp+30h] [ebp-20h]
  float m_radius; // [esp+48h] [ebp-8h]
  float v24; // [esp+48h] [ebp-8h]
  float v25; // [esp+48h] [ebp-8h]
  float v26; // [esp+48h] [ebp-8h]
  float v27; // [esp+48h] [ebp-8h]
  float angle; // [esp+4Ch] [ebp-4h]
  float anglea; // [esp+4Ch] [ebp-4h]
  Vector edge; // 0:^4C.12
  Vector edgea; // 0:^4C.12

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CBotManager::StartFrame",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  CBotManager::ValidateActiveGrenades(this);
  if ( cv_bot_debug.m_pParent != nullptr && cv_bot_debug.m_pParent->m_Value.m_nValue == 5 )
  {
    for ( i = this->m_activeGrenadeList.m_Head; i != 0xFFFF; i = this->m_activeGrenadeList.m_Memory.m_pMemory[v3].m_Next )
    {
      v3 = (unsigned __int16)i;
      m_Element = this->m_activeGrenadeList.m_Memory.m_pMemory[v3].m_Element;
      *(_QWORD *)&v20.x = *(_QWORD *)&m_Element->m_detonationPosition.x;
      v20.z = m_Element->m_detonationPosition.z + 50.0;
      *(_QWORD *)&v19.x = *(_QWORD *)&v20.x;
      v19.z = m_Element->m_detonationPosition.z;
      UTIL_DrawBeamPoints(vecStart: v19, vecEnd: v20, iLifetime: 1, bRed: 0xFFu, bGreen: 0x64u, bBlue: 0);
      lastEdge.x = m_Element->m_radius + m_Element->m_detonationPosition.x;
      v5 = 0.0;
      lastEdge.y = m_Element->m_detonationPosition.y;
      lastEdge.z = m_Element->m_detonationPosition.z;
      angle = 0.0;
      do
      {
        m_radius = m_Element->m_radius;
        v6 = BotCOS(angle: v5);
        edge.y = m_Element->m_detonationPosition.y;
        edge.x = v6 * m_radius + m_Element->m_detonationPosition.x;
        v24 = m_Element->m_radius;
        edge.z = BotSIN(angle) * v24 + m_Element->m_detonationPosition.z;
        UTIL_DrawBeamPoints(vecStart: edge, vecEnd: lastEdge, iLifetime: 1, bRed: 0xFFu, bGreen: 0x32u, bBlue: 0);
        lastEdge.x = edge.x;
        lastEdge.y = edge.y;
        lastEdge.z = edge.z;
        v5 = angle + 22.5;
        angle = angle + 22.5;
      }
      while ( angle <= 180.0 );
      lastEdgea.y = m_Element->m_radius + m_Element->m_detonationPosition.y;
      v7 = 0.0;
      lastEdgea.x = m_Element->m_detonationPosition.x;
      lastEdgea.z = m_Element->m_detonationPosition.z;
      anglea = 0.0;
      do
      {
        v25 = m_Element->m_radius;
        edgea.x = m_Element->m_detonationPosition.x;
        edgea.y = BotCOS(angle: v7) * v25 + m_Element->m_detonationPosition.y;
        v26 = m_Element->m_radius;
        edgea.z = BotSIN(angle: anglea) * v26 + m_Element->m_detonationPosition.z;
        UTIL_DrawBeamPoints(vecStart: edgea, vecEnd: lastEdgea, iLifetime: 1, bRed: 0xFFu, bGreen: 0x32u, bBlue: 0);
        lastEdgea.y = edgea.y;
        lastEdgea.x = edgea.x;
        lastEdgea.z = edgea.z;
        v7 = anglea + 22.5;
        anglea = anglea + 22.5;
      }
      while ( anglea <= 180.0 );
    }
  }
  p_m_timestamp = &this->m_frameTimer.m_timestamp;
  if ( this->m_frameTimer.m_timestamp.m_Value <= 0.0 )
    g_BotUpkeepInterval = 99999.898;
  else
    g_BotUpkeepInterval = IntervalTimer::Now(this: (CEffectsServer *)&this->m_frameTimer) - p_m_timestamp->m_Value;
  v9 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_frameTimer);
  if ( p_m_timestamp->m_Value != v9 )
  {
    this->m_frameTimer.NetworkStateChanged(this: &this->m_frameTimer, a2: &this->m_frameTimer.m_timestamp);
    v27 = v9;
    p_m_timestamp->m_Value = v27;
  }
  v10 = 1;
  for ( g_BotUpdateInterval = g_BotUpkeepInterval * 3.0; v10 <= gpGlobals->maxClients; ++v10 )
  {
    v11 = UTIL_PlayerByIndex(playerIndex: v10);
    v12 = &v11->__vftable;
    if ( v11 != nullptr && v11->IsBot(this: v11) )
    {
      v13 = v12[6];
      if ( v13 != 0 && (signed int)(v13 - (unsigned int)gpGlobals->pEdicts) >> 4 != 0 )
      {
        v14 = (char *)__RTDynamicCast(
                        inptr: v12,
                        VfDelta: 0,
                        SrcType: &CBasePlayer `RTTI Type Descriptor',
                        TargetType: &CCSBot `RTTI Type Descriptor',
                        isReference: 0);
        v15 = v14;
        if ( v14 != nullptr )
        {
          (*(void (__thiscall **)(char *))(*(_DWORD *)v14 + 2048))(a1: v14);
          v16 = *((_DWORD *)v15 + 6);
          if ( v16 != 0 )
            v17 = (signed int)(v16 - (unsigned int)gpGlobals->pEdicts) >> 4;
          else
            v17 = 0;
          if ( (v17 + gpGlobals->tickcount) % 2 == 0 )
          {
            v18 = *(void (__thiscall **)(char *))(*(_DWORD *)v15 + 2052);
            *((_DWORD *)v15 + 1793) = 0;
            *((_DWORD *)v15 + 1794) = 0;
            *(_QWORD *)(v15 + 7180) = 1120403456;
            v18(a1: v15);
          }
          (*(void (__thiscall **)(char *))(*(_DWORD *)v15 + 2120))(a1: v15);
        }
      }
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x102CE5D0
// Name: public: void CBotManager::AddGrenade(class CBaseGrenade __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBotManager::AddGrenade(CBotManager *this, CBaseGrenade *grenade)
{
  ActiveGrenade *v3; // eax
  ActiveGrenade *v4; // ebx
  unsigned __int16 v5; // ax
  int v6; // edi
  UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *v7; // eax

  v3 = (ActiveGrenade *)operator new(nSize: 0x1Cu);
  if ( v3 != nullptr )
    v4 = ActiveGrenade::ActiveGrenade(this: v3, grenadeEntity: grenade);
  else
    v4 = nullptr;
  v5 = CUtlLinkedList<ActiveGrenade *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ActiveGrenade *,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_activeGrenadeList,
         multilist: false);
  v6 = v5;
  if ( v5 != 0xFFFF )
  {
    CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_activeGrenadeList,
      before: 0xFFFFu,
      elem: v5);
    v7 = &this->m_activeGrenadeList.m_Memory.m_pMemory[v6];
    if ( v7 != nullptr )
      v7->m_Element = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CE630
// Name: __CreateCServerGameTagsIServerGameTags_interface_34
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_34()
{
  return &_g_CServerGameTags_singleton_34;
}
