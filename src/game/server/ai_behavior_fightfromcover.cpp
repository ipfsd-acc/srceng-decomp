// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_behavior_fightfromcover.cpp
// Functions: 20
// ============================================================

#include "game\server\ai_behavior_fightfromcover.h"

//------------------------------------------------------------------------------
// Address: 0x10043970
// Name: public: virtual struct datamap_t __near * CAI_FightFromCoverGoal::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_FightFromCoverGoal::GetDataDescMap(CAI_FightFromCoverGoal *this)
{
  return &CAI_FightFromCoverGoal::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10043A00
// Name: public: class CBaseEntity __near * CAI_GoalEntity::GetGoalEntity(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CAI_GoalEntity::GetGoalEntity(CAI_GoalEntity *this)
{
  unsigned int m_flags; // eax
  unsigned int m_Index; // ecx

  m_flags = this->m_flags;
  if ( (m_flags & 1) != 0 && (m_flags & 2) != 0 )
  {
    CAI_GoalEntity::PruneActors(this);
  }
  else
  {
    this->ResolveNames(this);
    this->m_flags |= 2u;
  }
  m_Index = this->m_hGoalEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10043A90
// Name: public: char const __near * CBaseEntity::GetEntityNameAsCStr(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseEntity::GetEntityNameAsCStr(CBaseEntity *this)
{
  const char *result; // eax

  result = this->m_iName.m_Value.pszValue;
  if ( result == nullptr )
    return locale;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10043AA0
// Name: public: void CAI_FightFromCoverGoal::FrontThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_FightFromCoverGoal::FrontThink(CAI_FightFromCoverGoal *this)
{
  unsigned int m_Index; // eax
  int v3; // edx
  unsigned int v4; // esi
  unsigned int v5; // eax
  int v6; // edx
  CBaseEntity *m_pEntity; // ebx
  unsigned int v8; // eax
  float v9; // xmm0_4
  float v10; // xmm1_4
  CBaseEntity *v11; // ebx
  Vector vClosest; // [esp+14h] [ebp-18h] BYREF
  Vector vLineB; // [esp+20h] [ebp-Ch] BYREF
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  m_Index = this->m_hDirectionalMarker.m_Index;
  if ( m_Index != -1
    && (v3 = (unsigned __int16)m_Index,
        v4 = HIWORD(m_Index),
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr
    && (v5 = this->m_hGoalEntity.m_Index) != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber == HIWORD(v5)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity != nullptr )
  {
    v6 = v3;
    if ( g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v4 )
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[v6].m_pEntity;
    else
      m_pEntity = nullptr;
    if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
    AngleVectors(angles: &m_pEntity->m_angAbsRotation, forward: &this->m_vDir);
    v8 = this->m_hGoalEntity.m_Index;
    v9 = (float)(this->m_vDir.y * 99999.0) + this->m_vFront.y;
    v10 = (float)(this->m_vDir.z * 99999.0) + this->m_vFront.z;
    vLineB.x = this->m_vFront.x + (float)(this->m_vDir.x * 99999.0);
    vLineB.y = v9;
    vLineB.z = v10;
    if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
      v11 = nullptr;
    else
      v11 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
    if ( (v11->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v11, a2: (int)&savedregs);
    CalcClosestPointOnLineSegment(P: &v11->m_vecAbsOrigin, vLineA: &this->m_vFront, &vLineB, &vClosest, outT: nullptr);
    this->m_vFront = vClosest;
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.5, szContext: nullptr);
  }
  else
  {
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043C60
// Name: public: void CAI_FightFromCoverGoal::BeginMovingFront(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_FightFromCoverGoal::BeginMovingFront(CAI_FightFromCoverGoal *this@<ecx>, int a2@<ebp>)
{
  unsigned int m_Index; // eax
  int v4; // edx
  unsigned int v5; // esi
  unsigned int v6; // eax
  CBaseEntity *m_pEntity; // esi

  m_Index = this->m_hDirectionalMarker.m_Index;
  if ( m_Index != -1
    && (v4 = (unsigned __int16)m_Index,
        v5 = HIWORD(m_Index),
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    v6 = this->m_hGoalEntity.m_Index;
    if ( v6 != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber == HIWORD(v6)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity != nullptr )
    {
      if ( this->m_pfnThink == nullptr )
      {
        CBaseEntity::ThinkSet(
          this,
          func: (void (__thiscall *)(CBaseEntity *))CAI_FightFromCoverGoal::FrontThink,
          thinkTime: 0.0,
          szContext: nullptr);
        CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
      }
    }
    else
    {
      if ( g_pEntityList->m_EntPtrArray[v4].m_SerialNumber == v5 )
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[v4].m_pEntity;
      else
        m_pEntity = nullptr;
      if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2);
      this->m_vFront.x = m_pEntity->m_vecAbsOrigin.x;
      this->m_vFront.y = m_pEntity->m_vecAbsOrigin.y;
      this->m_vFront.z = m_pEntity->m_vecAbsOrigin.z;
    }
  }
  else
  {
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043D80
// Name: public: virtual void CAI_FightFromCoverGoal::OnActivate(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __usercall CAI_FightFromCoverGoal::OnActivate(CAI_FightFromCoverGoal *this@<ecx>, int a2@<ebp>)
{
  CAI_FightFromCoverGoal::BeginMovingFront(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10043D90
// Name: public: virtual void CAI_FightFromCoverGoal::EnableGoal(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_FightFromCoverGoal::EnableGoal(CAI_FightFromCoverGoal *this, CAI_BaseNPC *pAI)
{
  CAI_BaseNPC *v3; // edi

  if ( CAI_BaseNPC::GetBehavior<CAI_FightFromCoverBehavior>(this: pAI, ppBehavior: (CAI_FightFromCoverBehavior **)&pAI) != 0
    && CAI_GoalEntity::GetGoalEntity(this) != nullptr )
  {
    v3 = pAI;
    if ( this != nullptr )
      LODWORD(v3->m_Network.m_PVSInfo.m_vCenter[2]) = this->GetRefEHandle(this)->m_Index;
    else
      pAI->m_Network.m_PVSInfo.m_vCenter[2] = NAN;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043DE0
// Name: public: virtual void CAI_FightFromCoverGoal::DisableGoal(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_FightFromCoverGoal::DisableGoal(CAI_FightFromCoverGoal *this, CAI_BaseNPC *pAI)
{
  if ( pAI != nullptr
    && CAI_BaseNPC::GetBehavior<CAI_FightFromCoverBehavior>(this: pAI, ppBehavior: (CAI_FightFromCoverBehavior **)&pAI) != 0 )
  {
    pAI->m_Network.m_PVSInfo.m_vCenter[2] = NAN;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043E10
// Name: public: virtual void CAI_FightFromCoverGoal::ResolveNames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_FightFromCoverGoal::ResolveNames(CAI_FightFromCoverGoal *this)
{
  unsigned int m_Index; // eax
  CBasePlayer *LocalPlayer; // eax
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  unsigned int v6; // eax
  IHandleEntity *m_pEntity; // edx
  unsigned int v8; // eax
  IHandleEntity *v9; // ecx
  const char *v10; // eax
  CBaseEntity *v11; // eax
  unsigned int v12; // eax
  CBaseEntity *v13; // edi
  unsigned int v14; // eax
  CBaseEntity *v15; // edi
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  CAI_GoalEntity::ResolveNames(this);
  m_Index = this->m_hGoalEntity.m_Index;
  if ( (m_Index == -1
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr)
    && gpGlobals->maxClients == 1 )
  {
    LocalPlayer = UTIL_GetLocalPlayer();
    if ( LocalPlayer != nullptr )
      this->m_hGoalEntity.m_Index = LocalPlayer->GetRefEHandle(this: LocalPlayer)->m_Index;
    else
      this->m_hGoalEntity.m_Index = -1;
  }
  pszValue = this->m_DirectionalMarker.pszValue;
  if ( pszValue != nullptr )
  {
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: pszValue,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName != nullptr
      && (v6 = EntityByName->GetRefEHandle(this: EntityByName)->m_Index) != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber == HIWORD(v6) )
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
    }
    else
    {
      m_pEntity = nullptr;
    }
    v8 = this->m_hDirectionalMarker.m_Index;
    if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
      v9 = nullptr;
    else
      v9 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
    if ( v9 != m_pEntity )
    {
      v10 = this->m_DirectionalMarker.pszValue;
      if ( v10 == nullptr )
        v10 = locale;
      v11 = CGlobalEntityList::FindEntityByName(
              this: &gEntList,
              pStartEntity: nullptr,
              szName: v10,
              pSearchingEntity: nullptr,
              pActivator: nullptr,
              pCaller: nullptr,
              pFilter: nullptr);
      if ( v11 != nullptr )
        this->m_hDirectionalMarker.m_Index = v11->GetRefEHandle(this: v11)->m_Index;
      else
        this->m_hDirectionalMarker.m_Index = -1;
      v12 = this->m_hDirectionalMarker.m_Index;
      if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
        v13 = nullptr;
      else
        v13 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
      if ( (v13->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v13, a2: (int)&savedregs);
      this->m_vFront.x = v13->m_vecAbsOrigin.x;
      this->m_vFront.y = v13->m_vecAbsOrigin.y;
      this->m_vFront.z = v13->m_vecAbsOrigin.z;
      v14 = this->m_hDirectionalMarker.m_Index;
      if ( v14 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
        v15 = nullptr;
      else
        v15 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
      if ( (v15->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v15, a2: (int)&savedregs);
      AngleVectors(angles: &v15->m_angAbsRotation, forward: &this->m_vDir);
    }
    CAI_FightFromCoverGoal::BeginMovingFront(this, a2: (int)&savedregs);
  }
  else
  {
    this->m_hDirectionalMarker.m_Index = -1;
    this->m_vDir.z = NAN;
    this->m_vDir.y = NAN;
    this->m_vDir.x = NAN;
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044070
// Name: public: void CAI_FightFromCoverGoal::InputSetDirectionalMarker(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_FightFromCoverGoal::InputSetDirectionalMarker(CAI_FightFromCoverGoal *this, inputdata_t *inputdata)
{
  CHandle<CBaseEntity> *p_eVal; // eax
  unsigned int m_Index; // eax
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // eax
  unsigned int v10; // eax
  CBaseEntity *v11; // edi
  unsigned int v12; // eax
  CBaseEntity *v13; // edi
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  if ( inputdata->value.fieldType == FIELD_EHANDLE )
  {
    p_eVal = &inputdata->value.eVal;
  }
  else
  {
    if ( (`variant_t::Entity'::`4'::`local static guard' & 1) == 0 )
      `variant_t::Entity'::`4'::`local static guard' |= 1u;
    `variant_t::Entity'::`4'::hNull.m_Index = -1;
    p_eVal = &`variant_t::Entity'::`4'::hNull;
  }
  m_Index = p_eVal->m_Index;
  this->m_hDirectionalMarker.m_Index = m_Index;
  if ( m_Index != -1
    && (v5 = HIWORD(m_Index), g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    v6 = (unsigned __int16)m_Index;
    v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
    v8 = &g_pEntityList->m_EntPtrArray[v6];
    if ( v7 )
      m_pEntity = v8->m_pEntity;
    else
      m_pEntity = nullptr;
    this->m_DirectionalMarker.pszValue = (const char *)m_pEntity[51].__vftable;
    v10 = this->m_hDirectionalMarker.m_Index;
    if ( v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
      v11 = nullptr;
    else
      v11 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
    if ( (v11->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v11, a2: (int)&savedregs);
    this->m_vFront.x = v11->m_vecAbsOrigin.x;
    this->m_vFront.y = v11->m_vecAbsOrigin.y;
    this->m_vFront.z = v11->m_vecAbsOrigin.z;
    v12 = this->m_hDirectionalMarker.m_Index;
    if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
      v13 = nullptr;
    else
      v13 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
    if ( (v13->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v13, a2: (int)&savedregs);
    AngleVectors(angles: &v13->m_angAbsRotation, forward: &this->m_vDir);
    CAI_FightFromCoverGoal::BeginMovingFront(this, a2: (int)&savedregs);
  }
  else
  {
    this->m_DirectionalMarker.pszValue = nullptr;
    this->m_vDir.z = NAN;
    this->m_vDir.y = NAN;
    this->m_vDir.x = NAN;
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044210
// Name: public: virtual int CAI_FightFromCoverGoal::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_FightFromCoverGoal::DrawDebugTextOverlays(CAI_FightFromCoverGoal *this)
{
  int result; // eax
  int v3; // ebx
  unsigned int m_Index; // ecx
  CBaseEntityList *v5; // edx
  int v6; // eax
  CEntInfo *v7; // esi
  unsigned int v8; // ecx
  int v9; // eax
  IHandleEntity *m_pEntity; // edx
  const char *v11; // eax
  char *v12; // eax
  unsigned int v13; // eax
  CBaseEntity *v14; // ebx
  unsigned int v15; // eax
  CBaseEntity *v16; // esi
  unsigned int v17; // eax
  CBaseEntity *v18; // esi
  unsigned int v19; // eax
  CBaseEntity *v20; // esi
  unsigned int v21; // eax
  float v22; // xmm0_4
  CBaseEntity *v23; // esi
  float m_WidthZone; // xmm1_4
  float m_HeightZone; // xmm2_4
  int v26; // eax
  CHandle<CAI_BaseNPC> *v27; // esi
  unsigned int v28; // eax
  unsigned int v29; // eax
  IHandleEntity *v30; // ecx
  const Vector *v31; // eax
  unsigned int v32; // ecx
  int v33; // eax
  CEntInfo *v34; // esi
  unsigned int v35; // ecx
  int v36; // eax
  bool v37; // zf
  CEntInfo *v38; // edx
  IHandleEntity *v39; // edx
  const char *v40; // eax
  char *v41; // eax
  CFmtStrN<256> str; // [esp+30h] [ebp-138h] BYREF
  Vector mins; // [esp+13Ch] [ebp-2Ch] BYREF
  Vector vBoxDrawCenter; // [esp+148h] [ebp-20h] BYREF
  int i; // [esp+154h] [ebp-14h]
  int text_offset; // [esp+158h] [ebp-10h]
  Vector startPos; // [esp+15Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+168h] [ebp+0h] BYREF

  result = CAI_GoalEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) == 0 )
    return result;
  m_Index = this->m_hDirectionalMarker.m_Index;
  str.__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  *(_WORD *)&str.m_bQuietTruncation = 1;
  str.m_nLength = 0;
  if ( m_Index == -1 )
  {
LABEL_53:
    v5 = g_pEntityList;
    goto LABEL_54;
  }
  v5 = g_pEntityList;
  v6 = (unsigned __int16)m_Index;
  v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v8 = HIWORD(m_Index);
  if ( v7->m_SerialNumber == v8 && v7->m_pEntity != nullptr )
  {
    v9 = v6;
    if ( g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8 )
      m_pEntity = g_pEntityList->m_EntPtrArray[v9].m_pEntity;
    else
      m_pEntity = nullptr;
    v11 = (const char *)m_pEntity[51].__vftable;
    if ( v11 == nullptr )
      v11 = locale;
    v12 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "Dir ent: %s", v11);
    CBaseEntity::EntityText(this, text_offset: v3, text: v12, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v13 = this->m_hDirectionalMarker.m_Index;
    text_offset = v3 + 1;
    if ( v13 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
      v14 = nullptr;
    else
      v14 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
    if ( (v14->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v14, a2: (int)&savedregs);
    v15 = this->m_hDirectionalMarker.m_Index;
    if ( v15 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber != HIWORD(v15) )
      v16 = nullptr;
    else
      v16 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_pEntity;
    if ( (v16->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v16, a2: (int)&savedregs);
    startPos.x = v16->m_vecAbsOrigin.x;
    startPos.y = v16->m_vecAbsOrigin.y;
    startPos.z = v16->m_vecAbsOrigin.z + 6.0;
    NDebugOverlay::YawArrow(
      &startPos,
      yaw: v14->m_angAbsRotation.y,
      length: 60.0,
      width: 6.0,
      r: 255,
      g: 255,
      b: 255,
      a: 0,
      noDepthTest: true,
      flDuration: 0.0);
    v17 = this->m_hDirectionalMarker.m_Index;
    if ( v17 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_SerialNumber != HIWORD(v17) )
      v18 = nullptr;
    else
      v18 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_pEntity;
    if ( (v18->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v18, a2: (int)&savedregs);
    startPos.x = this->m_vFront.x;
    startPos.y = this->m_vFront.y;
    startPos.z = this->m_vFront.z + 6.0;
    NDebugOverlay::Cross3DOriented(
      position: &startPos,
      angles: &v18->m_angAbsRotation,
      size: 12.0,
      r: 255,
      g: 0,
      b: 0,
      noDepthTest: true,
      flDuration: 0.0);
    v19 = this->m_hDirectionalMarker.m_Index;
    if ( v19 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_SerialNumber != HIWORD(v19) )
      v20 = nullptr;
    else
      v20 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_pEntity;
    if ( (v20->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v20, a2: (int)&savedregs);
    AngleVectors(angles: &v20->m_angAbsRotation, forward: &vBoxDrawCenter);
    v21 = this->m_hDirectionalMarker.m_Index;
    v22 = -this->m_BiasZone;
    vBoxDrawCenter.x = this->m_vFront.x + (float)(v22 * vBoxDrawCenter.x);
    vBoxDrawCenter.y = this->m_vFront.y + (float)(vBoxDrawCenter.y * v22);
    vBoxDrawCenter.z = this->m_vFront.z + (float)(vBoxDrawCenter.z * v22);
    if ( v21 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_SerialNumber != HIWORD(v21) )
      v23 = nullptr;
    else
      v23 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_pEntity;
    if ( (v23->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v23, a2: (int)&savedregs);
    m_WidthZone = this->m_WidthZone;
    m_HeightZone = this->m_HeightZone;
    startPos.x = this->m_LengthZone * 0.5;
    mins.x = -startPos.x;
    startPos.y = m_WidthZone * 0.5;
    startPos.z = m_HeightZone * 0.5;
    mins.y = -(float)(m_WidthZone * 0.5);
    mins.z = -(float)(m_HeightZone * 0.5);
    NDebugOverlay::BoxAngles(
      origin: &vBoxDrawCenter,
      &mins,
      maxs: &startPos,
      angles: &v23->m_angAbsRotation,
      r: 255,
      g: 0,
      b: 0,
      a: 16,
      duration: 0.0);
    v26 = 0;
    i = 0;
    if ( this->m_actors.m_Size > 0 )
    {
      v5 = g_pEntityList;
      do
      {
        v27 = &this->m_actors.m_Memory.m_pMemory[v26];
        v28 = v27->m_Index;
        if ( v27->m_Index != -1
          && v5->m_EntPtrArray[(unsigned __int16)v28].m_SerialNumber == HIWORD(v28)
          && v5->m_EntPtrArray[(unsigned __int16)v28].m_pEntity != nullptr )
        {
          v29 = v27->m_Index;
          if ( v27->m_Index == -1 || v5->m_EntPtrArray[(unsigned __int16)v29].m_SerialNumber != HIWORD(v29) )
            v30 = nullptr;
          else
            v30 = v5->m_EntPtrArray[(unsigned __int16)v29].m_pEntity;
          v31 = (const Vector *)((int (*)(void))v30->__vftable[49].dtr_IHandleEntity)();
          NDebugOverlay::Line(
            origin: &this->m_vFront,
            target: v31,
            r: 0,
            g: 0,
            b: 127,
            noDepthTest: true,
            duration: 0.0);
          v5 = g_pEntityList;
        }
        v26 = i + 1;
        i = v26;
      }
      while ( v26 < this->m_actors.m_Size );
      v3 = text_offset;
      goto LABEL_54;
    }
    v3 = text_offset;
    goto LABEL_53;
  }
LABEL_54:
  v32 = this->m_hGoalEntity.m_Index;
  if ( v32 == -1 )
    return v3;
  v33 = (unsigned __int16)v32;
  v34 = &v5->m_EntPtrArray[(unsigned __int16)v32];
  v35 = HIWORD(v32);
  if ( v34->m_SerialNumber != v35 || v34->m_pEntity == nullptr )
    return v3;
  v36 = v33;
  v37 = v5->m_EntPtrArray[v36].m_SerialNumber == v35;
  v38 = &v5->m_EntPtrArray[v36];
  if ( v37 )
    v39 = v38->m_pEntity;
  else
    v39 = nullptr;
  v40 = (const char *)v39[51].__vftable;
  if ( v40 == nullptr )
    v40 = locale;
  v41 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "Front ent: %s", v40);
  CBaseEntity::EntityText(this, text_offset: v3, text: v41, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
  return v3 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10044760
// Name: public: CAI_FightFromCoverGoal::CAI_FightFromCoverGoal(void)
// Source: json
//------------------------------------------------------------------------------
CAI_FightFromCoverGoal *__thiscall CAI_FightFromCoverGoal::CAI_FightFromCoverGoal(CAI_FightFromCoverGoal *this)
{
  CAI_GoalEntity::CAI_GoalEntity(this);
  this->CAI_GoalEntity::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CAI_FightFromCoverGoal_vtbl *)&CAI_FightFromCoverGoal::`vftable'{for `CBaseEntity'};
  this->CAI_GoalEntity::IEntityListener::__vftable = (IEntityListener_vtbl *)&CAI_FightFromCoverGoal::`vftable'{for `IEntityListener'};
  this->m_hDirectionalMarker.m_Index = -1;
  this->m_vDir.z = NAN;
  this->m_vDir.y = NAN;
  this->m_vDir.x = NAN;
  this->m_WidthZone = 600.0;
  this->m_LengthZone = 480.0;
  this->m_BiasZone = 60.0;
  this->m_HeightZone = 2400.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103FB670
// Name: CAI_FightFromCoverBehavior_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_FightFromCoverBehavior_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_FightFromCoverBehavior>();
  CAI_FightFromCoverBehavior_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB6B0
// Name: CAI_FightFromCoverGoal_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_FightFromCoverGoal_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_FightFromCoverGoal>();
  CAI_FightFromCoverGoal_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB680
// Name: _dynamic_initializer_for__CAI_FightFromCoverBehavior::gm_ClassScheduleIdSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_LocalIdSpace *dynamic_initializer_for__CAI_FightFromCoverBehavior::gm_ClassScheduleIdSpace__()
{
  CAI_LocalIdSpace::CAI_LocalIdSpace(
    this: &CAI_FightFromCoverBehavior::gm_ClassScheduleIdSpace.m_ScheduleIds,
    fIsRoot: false);
  CAI_LocalIdSpace::CAI_LocalIdSpace(
    this: &CAI_FightFromCoverBehavior::gm_ClassScheduleIdSpace.m_TaskIds,
    fIsRoot: false);
  return CAI_LocalIdSpace::CAI_LocalIdSpace(
           this: &CAI_FightFromCoverBehavior::gm_ClassScheduleIdSpace.m_ConditionIds,
           fIsRoot: false);
}

//------------------------------------------------------------------------------
// Address: 0x103FB6C0
// Name: _dynamic_initializer_for__ai_goal_fightfromcover__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_goal_fightfromcover__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAI_FightFromCoverGoal> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ai_goal_fightfromcover,
           a3: "ai_goal_fightfromcover");
}

//------------------------------------------------------------------------------
// Address: 0x103FB6E0
// Name: _dynamic_initializer_for__ai_debug_follow__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_follow__()
{
  ConVar::ConVar(this: &ai_debug_follow, pName: "ai_debug_follow", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_follow__);
}

//------------------------------------------------------------------------------
// Address: 0x103FB710
// Name: _dynamic_initializer_for__ai_follow_use_points__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_follow_use_points__()
{
  ConVar::ConVar(this: &ai_follow_use_points, pName: "ai_follow_use_points", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_follow_use_points__);
}

//------------------------------------------------------------------------------
// Address: 0x103FB740
// Name: _dynamic_initializer_for__ai_follow_use_points_when_moving__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_follow_use_points_when_moving__()
{
  ConVar::ConVar(
    this: &ai_follow_use_points_when_moving,
    pName: "ai_follow_use_points_when_moving",
    pDefaultValue: "1",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_follow_use_points_when_moving__);
}

//------------------------------------------------------------------------------
// Address: 0x103FB770
// Name: _dynamic_initializer_for__g_AIFollowManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AIFollowManager__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_AIFollowManager__);
}
