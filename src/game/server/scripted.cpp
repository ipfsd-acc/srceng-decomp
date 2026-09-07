// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/scripted.cpp
// Functions: 63
// ============================================================

#include "game\server\scripted.h"

//------------------------------------------------------------------------------
// Address: 0x101F5590
// Name: public: class CRopeKeyframe __near * CGlobalEntityList::NextEntByClass<class CRopeKeyframe>(class CRopeKeyframe __near *)
// Source: json
//------------------------------------------------------------------------------
CRopeKeyframe *__thiscall CGlobalEntityList::NextEntByClass<CRopeKeyframe>(
        CGlobalEntityList *this,
        CRopeKeyframe *start)
{
  CBaseEntity *Ent; // esi
  CRopeKeyframe *result; // eax

  Ent = CGlobalEntityList::NextEnt(this, pCurrentEnt: start);
  if ( Ent == nullptr )
    return nullptr;
  while ( 1 )
  {
    result = (CRopeKeyframe *)__RTDynamicCast(
                                inptr: Ent,
                                VfDelta: 0,
                                SrcType: &CBaseEntity `RTTI Type Descriptor',
                                TargetType: &CRopeKeyframe `RTTI Type Descriptor',
                                isReference: 0);
    if ( result != nullptr )
      break;
    Ent = CGlobalEntityList::NextEnt(this, pCurrentEnt: Ent);
    if ( Ent == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020C240
// Name: public: virtual struct datamap_t __near * CAI_ScriptedSequence::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_ScriptedSequence::GetDataDescMap(CAI_ScriptedSequence *this)
{
  return &CAI_ScriptedSequence::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1020C250
// Name: public: void CAI_ScriptedSequence::FireScriptEvent(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::FireScriptEvent(CAI_ScriptedSequence *this, int nEvent)
{
  if ( (unsigned int)(nEvent - 1) <= 7 )
    COutputEvent::FireOutput(
      this: &this->m_OnCancelFailedSequence + nEvent,
      pActivator: this,
      pCaller: this,
      fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1020C280
// Name: public: bool CAI_ScriptedSequence::IsTimeToStart(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_ScriptedSequence::IsTimeToStart(CAI_ScriptedSequence *this)
{
  return this->m_iDelay == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020C290
// Name: public: void CAI_ScriptedSequence::OnBeginSequence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::OnBeginSequence(CAI_ScriptedSequence *this)
{
  COutputEvent::FireOutput(this: &this->m_OnBeginSequence, pActivator: this, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1020C2B0
// Name: private: virtual struct datamap_t __near * CAI_ScriptedSchedule::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_ScriptedSchedule::GetDataDescMap(CAI_ScriptedSchedule *this)
{
  return &CAI_ScriptedSchedule::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1020C2C0
// Name: public: virtual struct datamap_t __near * CAI_ScriptedSentence::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_ScriptedSentence::GetDataDescMap(CAI_ScriptedSentence *this)
{
  return &CAI_ScriptedSentence::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1020C2D0
// Name: public: class CAI_ScriptedSequence __near * CGlobalEntityList::NextEntByClass<class CAI_ScriptedSequence>(class CAI_ScriptedSequence __near *)
// Source: json
//------------------------------------------------------------------------------
CAI_ScriptedSequence *__thiscall CGlobalEntityList::NextEntByClass<CAI_ScriptedSequence>(
        CGlobalEntityList *this,
        CAI_ScriptedSequence *start)
{
  CBaseEntity *Ent; // esi
  CAI_ScriptedSequence *result; // eax

  Ent = CGlobalEntityList::NextEnt(this, pCurrentEnt: start);
  if ( Ent == nullptr )
    return nullptr;
  while ( 1 )
  {
    result = (CAI_ScriptedSequence *)__RTDynamicCast(
                                       inptr: Ent,
                                       VfDelta: 0,
                                       SrcType: &CBaseEntity `RTTI Type Descriptor',
                                       TargetType: &CAI_ScriptedSequence `RTTI Type Descriptor',
                                       isReference: 0);
    if ( result != nullptr )
      break;
    Ent = CGlobalEntityList::NextEnt(this, pCurrentEnt: Ent);
    if ( Ent == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020C330
// Name: public: class CBaseEntity __near * CAI_ScriptedSequence::GetTarget(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CAI_ScriptedSequence::GetTarget(CAI_ScriptedSequence *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hTargetEnt.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1020C360
// Name: private: class CAI_BaseNPC __near * CAI_ScriptedSequence::FindScriptEntity(void)
// Source: json
//------------------------------------------------------------------------------
CAI_BaseNPC *__thiscall CAI_ScriptedSequence::FindScriptEntity(CAI_ScriptedSequence *this)
{
  unsigned int m_Index; // ecx
  CBaseEntityList *v3; // edi
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  CEntInfo *v7; // eax
  CBaseEntity *m_pEntity; // eax
  const char *pszValue; // edx
  unsigned int v10; // eax
  CBaseEntity *v11; // eax
  CBasePlayer *EntityByNameWithin; // ebx
  const char *v13; // edx
  unsigned int v14; // eax
  CBaseEntity *v15; // eax
  int v16; // edi
  int v17; // eax
  const char *v18; // eax
  unsigned int v19; // eax
  const char *v20; // eax
  CBasePlayer *EntityByClassnameWithin; // eax
  const char *v22; // eax
  CAI_BaseNPC *result; // eax
  const char *v24; // edi
  const char *v25; // eax
  const char *DebugName; // [esp+14h] [ebp-1Ch]
  CAI_BaseNPC *pEnqueueNPC; // [esp+28h] [ebp-8h]
  int interrupt; // [esp+2Ch] [ebp-4h]
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  m_Index = this->m_hForcedTarget.m_Index;
  v3 = g_pEntityList;
  pEnqueueNPC = nullptr;
  if ( m_Index != -1 )
  {
    v4 = (unsigned __int16)m_Index;
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v6 = HIWORD(m_Index);
    if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
    {
      v7 = &g_pEntityList->m_EntPtrArray[v4];
      interrupt = 1;
      if ( v7->m_SerialNumber == v6 )
        m_pEntity = (CBaseEntity *)v7->m_pEntity;
      else
        m_pEntity = nullptr;
      goto LABEL_25;
    }
  }
  interrupt = 1;
  if ( (this->m_iEFlags & 0x800) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v3 = g_pEntityList;
  }
  pszValue = this->m_iszEntity.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v10 = this->m_hLastFoundEntity.m_Index;
  if ( v10 == -1 || v3->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
    v11 = nullptr;
  else
    v11 = (CBaseEntity *)v3->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
  EntityByNameWithin = CGlobalEntityList::FindEntityByNameWithin(
                         this: &gEntList,
                         pStartEntity: v11,
                         szName: pszValue,
                         vecSrc: &this->m_vecAbsOrigin,
                         flRadius: this->m_flRadius,
                         pSearchingEntity: nullptr,
                         pActivator: nullptr,
                         pCaller: nullptr);
  if ( EntityByNameWithin == nullptr )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v13 = this->m_iszEntity.pszValue;
    if ( v13 == nullptr )
      v13 = locale;
    v14 = this->m_hLastFoundEntity.m_Index;
    if ( v14 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
      v15 = nullptr;
    else
      v15 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
    m_pEntity = CGlobalEntityList::FindEntityByClassnameWithin(
                  this: &gEntList,
                  pStartEntity: v15,
                  szName: v13,
                  vecSrc: &this->m_vecAbsOrigin,
                  flRadius: this->m_flRadius);
    interrupt = 0;
LABEL_25:
    EntityByNameWithin = (CBasePlayer *)m_pEntity;
    if ( m_pEntity != nullptr )
      goto LABEL_26;
    return nullptr;
  }
  do
  {
LABEL_26:
    v16 = (int)EntityByNameWithin->MyNPCPointer(this: EntityByNameWithin);
    if ( v16 != 0 )
    {
      v17 = (*(int (__thiscall **)(int, bool, int))(*(_DWORD *)v16 + 1832))(
              a1: v16,
              a2: (this->m_spawnflags.m_Value & 0x40) != 0,
              a3: interrupt);
      if ( v17 == 1 )
        return (CAI_BaseNPC *)v16;
      if ( v17 == 2 )
      {
        pEnqueueNPC = (CAI_BaseNPC *)v16;
      }
      else if ( (this->m_spawnflags.m_Value & 0x800) == 0 )
      {
        v18 = this->m_iszEntity.pszValue;
        if ( v18 == nullptr )
          v18 = locale;
        DevMsg(a1: "Found %s, but can't play!\n", v18);
      }
    }
    v19 = this->m_hForcedTarget.m_Index;
    if ( v19 != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_SerialNumber == HIWORD(v19)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_pEntity != nullptr )
    {
      v24 = EntityByNameWithin->m_iClassname.pszValue;
      if ( v24 == nullptr )
        v24 = locale;
      DebugName = CBaseEntity::GetDebugName(this);
      v25 = CBaseEntity::GetDebugName(this: EntityByNameWithin);
      _Warning(
        a1: "Code forced %s(%s), to be the target of scripted sequence %s, but it can't play it.\n",
        v24,
        v25,
        DebugName);
      UTIL_Remove(oldObj: this);
      return nullptr;
    }
    if ( interrupt == 1 )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v20 = this->m_iszEntity.pszValue;
      if ( v20 == nullptr )
        v20 = locale;
      EntityByClassnameWithin = CGlobalEntityList::FindEntityByNameWithin(
                                  this: &gEntList,
                                  pStartEntity: EntityByNameWithin,
                                  szName: v20,
                                  vecSrc: &this->m_vecAbsOrigin,
                                  flRadius: this->m_flRadius,
                                  pSearchingEntity: nullptr,
                                  pActivator: nullptr,
                                  pCaller: nullptr);
    }
    else
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v22 = this->m_iszEntity.pszValue;
      if ( v22 == nullptr )
        v22 = locale;
      EntityByClassnameWithin = (CBasePlayer *)CGlobalEntityList::FindEntityByClassnameWithin(
                                                 this: &gEntList,
                                                 pStartEntity: EntityByNameWithin,
                                                 szName: v22,
                                                 vecSrc: &this->m_vecAbsOrigin,
                                                 flRadius: this->m_flRadius);
    }
    EntityByNameWithin = EntityByClassnameWithin;
  }
  while ( EntityByClassnameWithin != nullptr );
  result = pEnqueueNPC;
  if ( pEnqueueNPC != nullptr )
    return result;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1020C670
// Name: public: bool CAI_ScriptedSequence::FindEntity(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_ScriptedSequence::FindEntity(CAI_ScriptedSequence *this)
{
  CAI_BaseNPC *ScriptEntity; // eax
  CAI_BaseNPC *v3; // edi

  ScriptEntity = CAI_ScriptedSequence::FindScriptEntity(this);
  v3 = ScriptEntity;
  if ( (this->m_spawnflags.m_Value & 0x400) != 0 )
  {
    if ( ScriptEntity != nullptr )
      this->m_hLastFoundEntity.m_Index = ScriptEntity->GetRefEHandle(this: ScriptEntity)->m_Index;
    else
      this->m_hLastFoundEntity.m_Index = -1;
  }
  if ( v3 != nullptr )
  {
    this->m_hTargetEnt.m_Index = v3->GetRefEHandle(this: v3)->m_Index;
    return v3 != nullptr;
  }
  else
  {
    this->m_hTargetEnt.m_Index = -1;
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C6E0
// Name: public: void CAI_ScriptedSequence::AllowInterrupt(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::AllowInterrupt(CAI_ScriptedSequence *this, bool fAllow)
{
  if ( (this->m_spawnflags.m_Value & 0x20) == 0 )
    this->m_interruptable = fAllow;
}

//------------------------------------------------------------------------------
// Address: 0x1020C700
// Name: public: bool CAI_ScriptedSequence::CanInterrupt(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ScriptedSequence::CanInterrupt(CAI_ScriptedSequence *this)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  bool result; // al

  result = false;
  if ( this->m_interruptable )
  {
    m_Index = this->m_hTargetEnt.m_Index;
    if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != nullptr && m_pEntity->__vftable[22].GetRefEHandle(this: m_pEntity) != nullptr )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020C750
// Name: public: void CAI_ScriptedSequence::RemoveIgnoredConditions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::RemoveIgnoredConditions(CAI_ScriptedSequence *this)
{
  unsigned int v2; // eax
  IHandleEntity *v3; // ecx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CAI_BaseNPC *v6; // eax
  CAI_BaseNPC *v7; // esi

  if ( !this->m_interruptable
    || (v2 = this->m_hTargetEnt.m_Index) == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v2].m_SerialNumber != HIWORD(v2)
    || (v3 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v2].m_pEntity) == nullptr
    || v3->__vftable[22].GetRefEHandle(this: v3) == nullptr )
  {
    m_Index = this->m_hTargetEnt.m_Index;
    if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != nullptr )
      {
        v6 = (CAI_BaseNPC *)m_pEntity->__vftable[24].GetRefEHandle(this: m_pEntity);
        v7 = v6;
        if ( v6 != nullptr )
        {
          CAI_BaseNPC::ClearCondition(this: v6, iCondition: 17);
          CAI_BaseNPC::ClearCondition(this: v7, iCondition: 18);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C7F0
// Name: public: virtual void CAI_ScriptedSequence::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::Activate(CAI_ScriptedSequence *this)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  unsigned int m_Index; // eax

  CBaseEntity::Activate(this);
  pszValue = this->m_iszNextScript.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    this->m_hNextCine.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  else
    this->m_hNextCine.m_Index = -1;
  m_Index = this->m_hNextCine.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    this->m_iszNextScript.pszValue = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C880
// Name: public: virtual void CAI_ScriptedSequence::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_ScriptedSequence::DrawDebugGeometryOverlays(CAI_ScriptedSequence *this@<ecx>, int a2@<ebp>)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CBaseEntity **v9; // eax
  CBaseEntity *v10; // esi

  CBaseEntity::DrawDebugGeometryOverlays(this);
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    m_Index = this->m_hTargetEnt.m_Index;
    if ( m_Index != -1 )
    {
      v4 = (unsigned __int16)m_Index;
      v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v6 = HIWORD(m_Index);
      if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
      {
        v7 = v4;
        v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
        v9 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v7];
        if ( v8 )
          v10 = *v9;
        else
          v10 = nullptr;
        if ( (v10->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v10, a2);
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2);
        NDebugOverlay::HorzArrow(
          startPos: &this->m_vecAbsOrigin,
          endPos: &v10->m_vecAbsOrigin,
          width: 16.0,
          r: 0,
          g: 255,
          b: 0,
          a: 64,
          noDepthTest: 1,
          flDuration: 0.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C950
// Name: private: class CAI_BaseNPC __near * CAI_ScriptedSchedule::FindScriptEntity(bool)
// Source: json
//------------------------------------------------------------------------------
CAI_BaseNPC *__thiscall CAI_ScriptedSchedule::FindScriptEntity(CAI_ScriptedSchedule *this, bool bCyclic)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // edi
  const char *pszValue; // edx
  unsigned int v6; // eax
  CBaseEntity *v7; // ecx
  CBasePlayer *EntityGenericWithin; // edi
  int v9; // eax
  int v10; // ebx
  const char *v11; // eax
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  m_Index = this->m_hActivator.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  pszValue = this->m_iszEntity.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v6 = this->m_hLastFoundEntity.m_Index;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
    v7 = nullptr;
  else
    v7 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  EntityGenericWithin = CGlobalEntityList::FindEntityGenericWithin(
                          this: &gEntList,
                          pStartEntity: v7,
                          szName: pszValue,
                          vecSrc: &this->m_vecAbsOrigin,
                          flRadius: this->m_flRadius,
                          pSearchingEntity: this,
                          pActivator: m_pEntity,
                          pCaller: nullptr);
  if ( EntityGenericWithin != nullptr )
  {
    while ( 1 )
    {
      v9 = (int)EntityGenericWithin->MyNPCPointer(this: EntityGenericWithin);
      v10 = v9;
      if ( v9 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v9 + 272))(a1: v9) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v10 + 1468))(a1: v10) != 0 )
      {
        break;
      }
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v11 = this->m_iszEntity.pszValue;
      if ( v11 == nullptr )
        v11 = locale;
      EntityGenericWithin = CGlobalEntityList::FindEntityGenericWithin(
                              this: &gEntList,
                              pStartEntity: EntityGenericWithin,
                              szName: v11,
                              vecSrc: &this->m_vecAbsOrigin,
                              flRadius: this->m_flRadius,
                              pSearchingEntity: this,
                              pActivator: nullptr,
                              pCaller: nullptr);
      if ( EntityGenericWithin == nullptr )
        goto LABEL_22;
    }
    if ( bCyclic )
      this->m_hLastFoundEntity.m_Index = *(_DWORD *)(*(int (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
    return (CAI_BaseNPC *)v10;
  }
  else
  {
LABEL_22:
    this->m_hLastFoundEntity.m_Index = -1;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020CAD0
// Name: private: void CAI_ScriptedSchedule::StopSchedule(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSchedule::StopSchedule(CAI_ScriptedSchedule *this, CAI_BaseNPC *pTarget)
{
  const char *pszValue; // ebx
  const char *v4; // eax
  const char *DebugName; // [esp-8h] [ebp-10h]

  if ( CAI_BaseNPC::IsCurSchedule(this: pTarget, schedId: 2, fIdeal: true) )
  {
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    DebugName = CBaseEntity::GetDebugName(this: pTarget);
    v4 = CBaseEntity::GetDebugName(this);
    _DevMsg(a1: 2, a2: "%s (%s): StopSchedule called on NPC %s.\n", pszValue, v4, DebugName);
    CAI_BaseNPC::ClearSchedule(this: pTarget, szReason: "Stopping scripted schedule");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020CB30
// Name: public: virtual bool CAI_ScriptedSentence::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ScriptedSentence::KeyValue(CAI_ScriptedSentence *this, const char *szKeyName, const char *szValue)
{
  long double v4; // st7

  if ( szKeyName != "volume" && _V_stricmp(s1: szKeyName, s2: "volume") != 0 )
    return CServerOnlyPointEntity::KeyValue((CLogicalEntity *)this, szKeyName, szValue);
  v4 = atof(nptr: szValue);
  this->m_flVolume = v4 * 0.1;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1020CB90
// Name: public: bool CAI_ScriptedSentence::AcceptableSpeaker(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ScriptedSentence::AcceptableSpeaker(CAI_ScriptedSentence *this, CAI_BaseNPC *pNPC)
{
  CAI_BaseNPC *v2; // esi
  unsigned int m_Index; // ecx
  CBaseEntity *Target; // eax
  bool result; // al

  v2 = pNPC;
  result = false;
  if ( pNPC != nullptr )
  {
    if ( (this->m_spawnflags.m_Value & 2) == 0
      || (m_Index = pNPC->m_hTargetEnt.m_Index) != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr
      && (Target = CAI_BaseNPC::GetTarget(this: pNPC), Target->IsPlayer(this: Target)) )
    {
      LOBYTE(pNPC) = (this->m_spawnflags.m_Value & 4) != 0;
      if ( v2->CanPlaySentence(this: v2, a2: (bool)pNPC) )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020CC20
// Name: public: class CAI_BaseNPC __near * CAI_ScriptedSentence::FindEntity(void)
// Source: json
//------------------------------------------------------------------------------
CAI_BaseNPC *__thiscall CAI_ScriptedSentence::FindEntity(CAI_ScriptedSentence *this)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // esi
  CAI_BaseNPC *v4; // eax
  CAI_BaseNPC *v5; // edi
  const char *v6; // eax
  CBaseEntity *CurrentEntity; // esi
  const char *v8; // eax
  CAI_BaseNPC *v9; // esi
  CEntitySphereQuery sphere; // [esp+14h] [ebp-808h] BYREF
  int savedregs; // [esp+81Ch] [ebp+0h] BYREF

  pszValue = this->m_iszEntity.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
  {
    while ( 1 )
    {
      v4 = EntityByName->MyNPCPointer(this: EntityByName);
      v5 = v4;
      if ( v4 != nullptr && CAI_ScriptedSentence::AcceptableSpeaker(this, pNPC: v4) )
        return v5;
      v6 = this->m_iszEntity.pszValue;
      if ( v6 == nullptr )
        v6 = locale;
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: EntityByName,
                       szName: v6,
                       pSearchingEntity: nullptr,
                       pActivator: nullptr,
                       pCaller: nullptr,
                       pFilter: nullptr);
      if ( EntityByName == nullptr )
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    CEntitySphereQuery::CEntitySphereQuery(
      this: &sphere,
      center: &this->m_vecAbsOrigin,
      radius: this->m_flRadius,
      flagMask: 0x4000);
    CurrentEntity = CEntitySphereQuery::GetCurrentEntity(this: &sphere);
    if ( CurrentEntity != nullptr )
    {
      while ( 1 )
      {
        v8 = this->m_iszEntity.pszValue;
        if ( v8 == nullptr )
          v8 = locale;
        if ( CurrentEntity->m_iClassname.pszValue == v8
          || CBaseEntity::ClassMatchesComplex(this: CurrentEntity, pszClassOrWildcard: v8) != 0 )
        {
          v9 = CurrentEntity->MyNPCPointer(this: CurrentEntity);
          if ( CAI_ScriptedSentence::AcceptableSpeaker(this, pNPC: v9) )
            break;
        }
        ++sphere.m_listIndex;
        CurrentEntity = CEntitySphereQuery::GetCurrentEntity(this: &sphere);
        if ( CurrentEntity == nullptr )
          return nullptr;
      }
      return v9;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020CD70
// Name: public: int CAI_ScriptedSentence::StartSentence(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_ScriptedSentence::StartSentence(CAI_ScriptedSentence *this, CAI_BaseNPC *pTarget)
{
  const char *v4; // esi
  int m_Value; // ecx
  CBaseEntity *m_pActivator; // eax
  const char *pszValue; // ecx
  const char *v9; // eax
  const char *v10; // ecx
  int v11; // edi
  const char *v12; // eax
  bool bConcurrent; // [esp+24h] [ebp-4h]
  int savedregs; // [esp+28h] [ebp+0h] BYREF
  float radius; // [esp+30h] [ebp+8h]

  if ( pTarget != nullptr )
  {
    m_Value = this->m_spawnflags.m_Value;
    bConcurrent = (m_Value & 8) == 0;
    m_pActivator = nullptr;
    if ( (m_Value & 0x10) != 0 )
    {
      m_pActivator = this->m_pActivator;
    }
    else
    {
      pszValue = this->m_iszListener.pszValue;
      if ( pszValue != nullptr )
      {
        radius = this->m_flRadius;
        if ( pszValue == "!player" || _V_stricmp(s1: pszValue, s2: "!player") == 0 )
          radius = 56755.84;
        if ( (pTarget->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: pTarget, a2: (int)&savedregs);
        v9 = this->m_iszListener.pszValue;
        if ( v9 == nullptr )
          v9 = locale;
        m_pActivator = CGlobalEntityList::FindEntityGenericNearest(
                         this: &gEntList,
                         szName: v9,
                         vecSrc: &pTarget->m_vecAbsOrigin,
                         flRadius: radius,
                         pSearchingEntity: this,
                         pActivator: nullptr,
                         pCaller: nullptr);
      }
    }
    v10 = this->m_iszSentence.pszValue;
    if ( v10 == nullptr )
      v10 = locale;
    v11 = ((int (__thiscall *)(CAI_BaseNPC *, const char *, _DWORD, _DWORD, soundlevel_t, bool, CBaseEntity *))pTarget->PlayScriptedSentence)(
            a1: pTarget,
            a2: v10,
            a3: LODWORD(this->m_flDelay),
            a4: LODWORD(this->m_flVolume),
            a5: this->m_iSoundLevel,
            a6: bConcurrent,
            a7: m_pActivator);
    v12 = this->m_iszSentence.pszValue;
    if ( v12 == nullptr )
      v12 = locale;
    _DevMsg(a1: 2, a2: "Playing sentence %s\n", v12);
    COutputEvent::FireOutput(this: &this->m_OnBeginSentence, pActivator: nullptr, pCaller: this, fDelay: 0.0);
    return v11;
  }
  else
  {
    v4 = this->m_iszSentence.pszValue;
    if ( v4 == nullptr )
      v4 = locale;
    _DevMsg(a1: 2, a2: "Not Playing sentence %s\n", v4);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020CEF0
// Name: public: void CAI_ScriptedSequence::SynchNewSequence(enum CAI_BaseNPC::SCRIPTSTATE,struct string_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::SynchNewSequence(
        CAI_ScriptedSequence *this,
        CAI_BaseNPC::SCRIPTSTATE newState,
        string_t iszSequence,
        bool bSynchOtherScenes)
{
  const char *pszValue; // eax
  CBasePlayer *i; // esi
  CAI_ScriptedSequence *v7; // eax
  const char *v8; // eax
  unsigned int m_Index; // ecx
  int v10; // eax
  CEntInfo *v11; // edx
  unsigned int v12; // ecx
  int v13; // eax
  bool v14; // zf
  CEntInfo *v15; // eax
  IHandleEntity *m_pEntity; // ecx
  int v17; // eax

  if ( bSynchOtherScenes )
  {
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    for ( i = CGlobalEntityList::FindEntityByName(
                this: &gEntList,
                pStartEntity: nullptr,
                szName: pszValue,
                pSearchingEntity: nullptr,
                pActivator: nullptr,
                pCaller: nullptr,
                pFilter: nullptr);
          i != nullptr;
          i = CGlobalEntityList::FindEntityByName(
                this: &gEntList,
                pStartEntity: i,
                szName: v8,
                pSearchingEntity: nullptr,
                pActivator: nullptr,
                pCaller: nullptr,
                pFilter: nullptr) )
    {
      v7 = (CAI_ScriptedSequence *)__RTDynamicCast(
                                     inptr: i,
                                     VfDelta: 0,
                                     SrcType: &CBaseEntity `RTTI Type Descriptor',
                                     TargetType: &CAI_ScriptedSequence `RTTI Type Descriptor',
                                     isReference: 0);
      if ( v7 != nullptr && v7 != this )
        CAI_ScriptedSequence::SynchNewSequence(this: v7, newState, iszSequence, bSynchOtherScenes: false);
      v8 = this->m_iName.m_Value.pszValue;
      if ( v8 == nullptr )
        v8 = locale;
    }
  }
  m_Index = this->m_hTargetEnt.m_Index;
  if ( m_Index != -1 )
  {
    v10 = (unsigned __int16)m_Index;
    v11 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v12 = HIWORD(m_Index);
    if ( v11->m_SerialNumber == v12 && v11->m_pEntity != nullptr )
    {
      v13 = v10;
      v14 = g_pEntityList->m_EntPtrArray[v13].m_SerialNumber == v12;
      v15 = &g_pEntityList->m_EntPtrArray[v13];
      if ( v14 )
        m_pEntity = v15->m_pEntity;
      else
        m_pEntity = nullptr;
      v17 = (int)m_pEntity->__vftable[24].GetRefEHandle(this: m_pEntity);
      if ( v17 != 0 )
      {
        this->m_startTime = gpGlobals->curtime;
        *(_DWORD *)(v17 + 2872) = newState;
        CAI_ScriptedSequence::StartSequence(
          this,
          pTarget: (CAI_BaseNPC *)v17,
          iszSeq: iszSequence,
          completeOnEmpty: false);
        this->m_bForceSynch = true;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020D010
// Name: public: bool CAI_ScriptedSequence::CanEnqueueAfter(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_ScriptedSequence::CanEnqueueAfter(CAI_ScriptedSequence *this)
{
  unsigned int m_Index; // edx
  int v2; // eax
  CEntInfo *v3; // esi
  unsigned int v4; // edx
  int v6; // eax
  bool v7; // zf
  CBaseEntity **v8; // eax
  const char *DebugName; // eax
  IHandleEntity *m_pEntity; // esi
  int v11; // eax
  CBaseEntity **v12; // eax
  CBaseEntity *v13; // eax
  const char *v14; // eax

  m_Index = this->m_hNextCine.m_Index;
  if ( m_Index == -1 )
    return 1;
  v2 = (unsigned __int16)m_Index;
  v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v4 = HIWORD(m_Index);
  if ( v3->m_SerialNumber != v4 || v3->m_pEntity == nullptr )
    return 1;
  if ( this->m_iszNextScript.pszValue != nullptr )
  {
    v6 = v2;
    v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v4;
    v8 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v6];
    if ( v7 )
      DebugName = CBaseEntity::GetDebugName(this: *v8);
    else
      DebugName = CBaseEntity::GetDebugName(this: nullptr);
    _DevMsg(a1: 2, a2: "%s is specified as the 'Next Script' and cannot be kicked out of the queue\n", DebugName);
    return 0;
  }
  else
  {
    if ( g_pEntityList->m_EntPtrArray[v2].m_SerialNumber == v4 )
      m_pEntity = g_pEntityList->m_EntPtrArray[v2].m_pEntity;
    else
      m_pEntity = nullptr;
    if ( ((int)m_pEntity[190].__vftable & 0x200) == 0 )
      return 1;
    v11 = v2;
    v7 = g_pEntityList->m_EntPtrArray[v11].m_SerialNumber == v4;
    v12 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v11];
    if ( v7 )
      v13 = *v12;
    else
      v13 = nullptr;
    v14 = CBaseEntity::GetDebugName(this: v13);
    _DevMsg(a1: 2, a2: "%s is a priority script and cannot be kicked out of the queue\n", v14);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020D0F0
// Name: public: void CAI_ScriptedSequence::StopActionLoop(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::StopActionLoop(CAI_ScriptedSequence *this, bool bStopSynchronizedScenes)
{
  const char *pszValue; // eax
  CBasePlayer *i; // esi
  CAI_ScriptedSequence *v5; // eax
  const char *v6; // eax

  this->m_bLoopActionSequence = false;
  if ( bStopSynchronizedScenes )
  {
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue != nullptr )
    {
      for ( i = CGlobalEntityList::FindEntityByName(
                  this: &gEntList,
                  pStartEntity: nullptr,
                  szName: pszValue,
                  pSearchingEntity: nullptr,
                  pActivator: nullptr,
                  pCaller: nullptr,
                  pFilter: nullptr);
            i != nullptr;
            i = CGlobalEntityList::FindEntityByName(
                  this: &gEntList,
                  pStartEntity: i,
                  szName: v6,
                  pSearchingEntity: nullptr,
                  pActivator: nullptr,
                  pCaller: nullptr,
                  pFilter: nullptr) )
      {
        v5 = (CAI_ScriptedSequence *)__RTDynamicCast(
                                       inptr: i,
                                       VfDelta: 0,
                                       SrcType: &CBaseEntity `RTTI Type Descriptor',
                                       TargetType: &CAI_ScriptedSequence `RTTI Type Descriptor',
                                       isReference: 0);
        if ( v5 != nullptr && v5 != this )
          CAI_ScriptedSequence::StopActionLoop(this: v5, bStopSynchronizedScenes: false);
        v6 = this->m_iName.m_Value.pszValue;
        if ( v6 == nullptr )
          v6 = locale;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020D190
// Name: public: void CAI_ScriptedSequence::ModifyScriptedAutoMovement(class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::ModifyScriptedAutoMovement(CAI_ScriptedSequence *this, Vector *vecNewPos)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CBaseEntityList *v5; // edi
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  CEntInfo *v8; // eax
  CBaseEntity *m_pEntity; // esi
  unsigned int v10; // eax
  CBaseEntity *v11; // esi
  unsigned int v12; // eax
  IHandleEntity *v13; // ecx
  int v14; // eax
  int m_nValue; // eax
  unsigned int v16; // eax
  CBaseEntity *v17; // edi
  unsigned int v18; // eax
  CBaseEntity *v19; // esi
  unsigned int v20; // eax
  CBaseEntity *v21; // ecx
  const char *DebugName; // eax
  void (*v23)(const char *, ...); // esi
  unsigned int v24; // eax
  CBaseEntity *v25; // ecx
  const char *v26; // eax
  unsigned int v27; // eax
  IHandleEntity *v28; // ecx
  CBaseAnimating *v29; // eax
  CBaseAnimating *v30; // edi
  float v31; // xmm0_4
  float v32; // xmm1_4
  unsigned int v33; // eax
  CBaseEntity *v34; // ecx
  const char *v35; // eax
  float x; // xmm0_4
  float y; // xmm3_4
  float z; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm4_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  double fromCycle; // [esp+0h] [ebp-100h]
  double fromCyclea; // [esp+0h] [ebp-100h]
  double flYaw; // [esp+8h] [ebp-F8h]
  double flYawa; // [esp+8h] [ebp-F8h]
  VMatrix matMeToWorld; // [esp+1Ch] [ebp-E4h] BYREF
  VMatrix matLocalToWorld; // [esp+5Ch] [ebp-A4h] BYREF
  QAngle vecDeltaAngles; // [esp+9Ch] [ebp-64h] BYREF
  QAngle angAngles; // [esp+A8h] [ebp-58h] BYREF
  QAngle angRelativeAngles; // [esp+B4h] [ebp-4Ch] BYREF
  Vector maxs; // [esp+C0h] [ebp-40h] BYREF
  Vector mins; // [esp+CCh] [ebp-34h] BYREF
  Vector vecOrigin; // [esp+D8h] [ebp-28h] BYREF
  Vector vecRelativeOrigin; // [esp+E4h] [ebp-1Ch] BYREF
  Vector vecDeltaPos; // [esp+F0h] [ebp-10h] BYREF
  bool bDebug; // [esp+FFh] [ebp-1h]
  int savedregs; // [esp+100h] [ebp+0h] BYREF

  m_Index = this->m_hInteractionRelativeEntity.m_Index;
  if ( m_Index != -1 )
  {
    v4 = (unsigned __int16)m_Index;
    v5 = g_pEntityList;
    v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v7 = HIWORD(m_Index);
    if ( v6->m_SerialNumber == v7
      && v6->m_pEntity != nullptr
      && (this->m_iszEntry.pszValue == nullptr || this->m_bIsPlayingEntry) )
    {
      v8 = &g_pEntityList->m_EntPtrArray[v4];
      if ( v8->m_SerialNumber == v7 )
        m_pEntity = (CBaseEntity *)v8->m_pEntity;
      else
        m_pEntity = nullptr;
      if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
        v5 = g_pEntityList;
      }
      v10 = this->m_hInteractionRelativeEntity.m_Index;
      vecRelativeOrigin = m_pEntity->m_vecAbsOrigin;
      if ( v10 == -1 || v5->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
        v11 = nullptr;
      else
        v11 = (CBaseEntity *)v5->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
      if ( (v11->m_iEFlags & 0x800) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this: v11, a2: (int)&savedregs);
        v5 = g_pEntityList;
      }
      angRelativeAngles = v11->m_angAbsRotation;
      v12 = this->m_hInteractionRelativeEntity.m_Index;
      if ( v12 == -1 || v5->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
        v13 = nullptr;
      else
        v13 = v5->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
      v14 = (int)v13->__vftable[24].GetRefEHandle(this: v13);
      if ( v14 != 0 )
        angRelativeAngles.y = *(float *)(v14 + 2736);
      if ( ai_debug_dyninteractions.m_pParent != nullptr )
        m_nValue = ai_debug_dyninteractions.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      bDebug = m_nValue == 2;
      if ( m_nValue == 2 )
      {
        v16 = this->m_hTargetEnt.m_Index;
        if ( v16 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_SerialNumber != HIWORD(v16) )
          v17 = nullptr;
        else
          v17 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_pEntity;
        if ( (v17->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v17, a2: (int)&savedregs);
        v18 = this->m_hTargetEnt.m_Index;
        if ( v18 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_SerialNumber != HIWORD(v18) )
          v19 = nullptr;
        else
          v19 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_pEntity;
        if ( (v19->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v19, a2: (int)&savedregs);
        v20 = this->m_hTargetEnt.m_Index;
        if ( v20 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_SerialNumber != HIWORD(v20) )
          v21 = nullptr;
        else
          v21 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_pEntity;
        flYaw = v17->m_vecAbsOrigin.y;
        fromCycle = v19->m_vecAbsOrigin.x;
        DebugName = CBaseEntity::GetDebugName(this: v21);
        v23 = (void (*)(const char *, ...))_Msg;
        _Msg(a1: "--\n%s current org: %f %f\n", DebugName, fromCycle, flYaw);
        v24 = this->m_hInteractionRelativeEntity.m_Index;
        if ( v24 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_SerialNumber != HIWORD(v24) )
          v25 = nullptr;
        else
          v25 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_pEntity;
        v26 = CBaseEntity::GetDebugName(this: v25);
        _Msg(a1: "%s current org: %f %f", v26, vecRelativeOrigin.x, vecRelativeOrigin.y);
      }
      else
      {
        v23 = (void (*)(const char *, ...))_Msg;
      }
      v27 = this->m_hInteractionRelativeEntity.m_Index;
      if ( v27 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v27].m_SerialNumber != HIWORD(v27) )
        v28 = nullptr;
      else
        v28 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v27].m_pEntity;
      v29 = (CBaseAnimating *)__RTDynamicCast(
                                inptr: v28,
                                VfDelta: 0,
                                SrcType: &CBaseEntity `RTTI Type Descriptor',
                                TargetType: &CBaseAnimating `RTTI Type Descriptor',
                                isReference: 0);
      v30 = v29;
      if ( v29 != nullptr )
      {
        CBaseAnimating::GetSequenceMovement(
          this: v29,
          nSequence: v29->m_nSequence.m_Value,
          fromCycle: 0.0,
          toCycle: v29->m_flCycle.m_Value,
          deltaPosition: &vecDeltaPos,
          deltaAngles: &vecDeltaAngles);
        VectorYawRotate(in: &vecDeltaPos, flYaw: v30->m_angRotation.m_Value.y, out: &vecDeltaPos);
        if ( bDebug )
        {
          maxs.x = 2.0;
          maxs.y = 2.0;
          maxs.z = 2.0;
          mins.x = -2.0;
          mins.y = -2.0;
          mins.z = -2.0;
          NDebugOverlay::Box(origin: &vecRelativeOrigin, &mins, &maxs, r: 0, g: 255, b: 0, a: 8, flDuration: 0.1);
        }
        v31 = vecRelativeOrigin.x - vecDeltaPos.x;
        v32 = vecRelativeOrigin.y - vecDeltaPos.y;
        vecRelativeOrigin.x = vecRelativeOrigin.x - vecDeltaPos.x;
        vecRelativeOrigin.y = vecRelativeOrigin.y - vecDeltaPos.y;
        vecRelativeOrigin.z = vecRelativeOrigin.z - vecDeltaPos.z;
        if ( bDebug )
        {
          v23(a1: ", relative to sequence start: %f %f\n", v31, v32);
          mins.x = 3.0;
          mins.y = 3.0;
          mins.z = 3.0;
          maxs.x = -3.0;
          maxs.y = -3.0;
          maxs.z = -3.0;
          NDebugOverlay::Box(
            origin: &vecRelativeOrigin,
            mins: &maxs,
            maxs: &mins,
            r: 255,
            g: 0,
            b: 0,
            a: 8,
            flDuration: 0.1);
        }
      }
      VMatrix::SetupMatrixOrgAngles(this: &matMeToWorld, origin: &vecRelativeOrigin, vAngles: &angRelativeAngles);
      MatrixMultiply(src1: &matMeToWorld, src2: &this->m_matInteractionPosition, dst: &matLocalToWorld);
      vecOrigin.x = matLocalToWorld.m[0][3];
      vecOrigin.y = matLocalToWorld.m[1][3];
      vecOrigin.z = matLocalToWorld.m[2][3];
      MatrixAngles(a1: (int)v23, src: &matLocalToWorld, vAngles: &angAngles);
      if ( bDebug )
      {
        v33 = this->m_hTargetEnt.m_Index;
        if ( v33 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v33].m_SerialNumber != HIWORD(v33) )
          v34 = nullptr;
        else
          v34 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v33].m_pEntity;
        flYawa = vecOrigin.y;
        fromCyclea = vecOrigin.x;
        v35 = CBaseEntity::GetDebugName(this: v34);
        v23(a1: "Desired Origin for %s: %f %f\n", v35, fromCyclea, flYawa);
        NDebugOverlay::Axis(position: &vecOrigin, angles: &angAngles, size: 5.0, noDepthTest: 1, flDuration: 0.1);
      }
      x = vecNewPos->x;
      y = vecNewPos->y;
      z = vecOrigin.z - vecNewPos->z;
      v39 = vecOrigin.x - vecNewPos->x;
      v40 = vecOrigin.y - y;
      vecDeltaPos.x = v39;
      vecDeltaPos.y = vecOrigin.y - y;
      vecDeltaPos.z = z;
      if ( bDebug )
      {
        _Msg(a1: "Automovement's output origin: %f %f\n", x, y);
        _Msg(a1: "Vector from automovement to desired: %f %f\n", vecDeltaPos.x, vecDeltaPos.y);
        z = vecDeltaPos.z;
        v40 = vecDeltaPos.y;
        v39 = vecDeltaPos.x;
      }
      v41 = (float)(v30->m_flCycle.m_Value * v39) + vecNewPos->x;
      v42 = (float)(v30->m_flCycle.m_Value * v40) + vecNewPos->y;
      v43 = (float)(z * v30->m_flCycle.m_Value) + vecNewPos->z;
      vecNewPos->x = v41;
      vecNewPos->y = v42;
      vecNewPos->z = v43;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020D7B0
// Name: public: void CAI_ScriptedSequence::DelayStart(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::DelayStart(CAI_ScriptedSequence *this, bool bDelay)
{
  bool v3; // cl
  const char *pszValue; // eax
  CBasePlayer *i; // esi
  const char *v7; // eax

  if ( ai_task_pre_script.m_pParent != nullptr && ai_task_pre_script.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = bDelay;
    if ( bDelay == this->m_bDelayed )
      return;
    this->m_bDelayed = bDelay;
  }
  else
  {
    v3 = bDelay;
  }
  pszValue = this->m_iName.m_Value.pszValue;
  if ( pszValue != nullptr )
  {
    for ( i = CGlobalEntityList::FindEntityByName(
                this: &gEntList,
                pStartEntity: nullptr,
                szName: pszValue,
                pSearchingEntity: nullptr,
                pActivator: nullptr,
                pCaller: nullptr,
                pFilter: nullptr);
          i != nullptr;
          i = CGlobalEntityList::FindEntityByName(
                this: &gEntList,
                pStartEntity: i,
                szName: v7,
                pSearchingEntity: nullptr,
                pActivator: nullptr,
                pCaller: nullptr,
                pFilter: nullptr) )
    {
      if ( i->m_iClassname.pszValue == "scripted_sequence"
        || CBaseEntity::ClassMatchesComplex(this: i, pszClassOrWildcard: "scripted_sequence") != 0 )
      {
        if ( bDelay )
        {
          ++this->m_iDelay;
        }
        else if ( i->m_ScaleType.m_Value-- == NONHIERARCHICAL_MODEL_SCALE )
        {
          i->m_flIKGroundMinHeight = gpGlobals->curtime;
        }
      }
      v7 = this->m_iName.m_Value.pszValue;
      if ( v7 == nullptr )
        v7 = locale;
    }
  }
  else
  {
    this->m_iDelay = v3;
    this->m_startTime = gpGlobals->curtime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020D890
// Name: public: virtual int CAI_ScriptedSequence::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_ScriptedSequence::DrawDebugTextOverlays(CAI_ScriptedSequence *this)
{
  int result; // eax
  int v3; // esi
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CBaseEntity **v10; // eax
  const char *DebugName; // eax
  int v12; // esi
  int v13; // esi
  const char *v14; // eax
  int v15; // esi
  int v16; // esi
  const char *v17; // eax
  int v18; // esi
  const char *v19; // eax
  int v20; // esi
  const char *v21; // [esp+14h] [ebp-20Ch]
  char tempstr[512]; // [esp+20h] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    m_Index = this->m_hTargetEnt.m_Index;
    if ( m_Index != -1
      && (v5 = (unsigned __int16)m_Index,
          v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          v7 = HIWORD(m_Index),
          v6->m_SerialNumber == v7)
      && v6->m_pEntity != nullptr )
    {
      v8 = v5;
      v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
      v10 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v8];
      if ( v9 )
        DebugName = CBaseEntity::GetDebugName(this: *v10);
      else
        DebugName = CBaseEntity::GetDebugName(this: nullptr);
    }
    else
    {
      DebugName = "None";
    }
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Target: %s", DebugName);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v12 = v3 + 1;
    switch ( this->m_fMoveTo )
    {
      case 0:
        V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Moveto: Wait");
        break;
      case 1:
        v21 = "Moveto: Walk to Mark";
        goto LABEL_16;
      case 2:
        V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Moveto: Run to Mark");
        break;
      case 3:
        V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Moveto: Custom move to Mark");
        break;
      case 4:
        v21 = "Moveto: Teleport to Mark";
LABEL_16:
        V_snprintf(pDest: tempstr, maxLen: 512, pFormat: v21);
        break;
      case 5:
        V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Moveto: Wait Facing");
        break;
      default:
        break;
    }
    CBaseEntity::EntityText(this, text_offset: v12, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v13 = v12 + 1;
    v14 = "Yes";
    if ( !this->m_bThinking )
      v14 = "No";
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Thinking: %s", v14);
    CBaseEntity::EntityText(this, text_offset: v13, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v15 = v13 + 1;
    if ( this->m_iName.m_Value.pszValue != nullptr )
    {
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Delay: %d", this->m_iDelay);
      CBaseEntity::EntityText(this, text_offset: v15++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    }
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Start Time: %f", this->m_startTime);
    CBaseEntity::EntityText(this, text_offset: v15, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v16 = v15 + 1;
    v17 = "Yes";
    if ( !this->m_sequenceStarted )
      v17 = "No";
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Sequence has started: %s", v17);
    CBaseEntity::EntityText(this, text_offset: v16, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v18 = v16 + 1;
    v19 = "No";
    if ( !this->m_bDontCancelOtherSequences )
      v19 = "Yes";
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Cancel Other Sequences: %s", v19);
    CBaseEntity::EntityText(this, text_offset: v18, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v20 = v18 + 1;
    if ( this->m_bWaitForBeginSequence )
    {
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Is waiting for BeingSequence");
      CBaseEntity::EntityText(this, text_offset: v20++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    }
    if ( this->m_bIsPlayingEntry )
    {
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Is playing entry");
      CBaseEntity::EntityText(this, text_offset: v20++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    }
    if ( this->m_bLoopActionSequence )
    {
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Will loop action sequence");
      CBaseEntity::EntityText(this, text_offset: v20++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    }
    if ( this->m_bSynchPostIdles )
    {
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Will synch post idles");
      CBaseEntity::EntityText(this, text_offset: v20, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
      return v20 + 1;
    }
    else
    {
      return v20;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020DD20
// Name: private: void CAI_ScriptedSchedule::StartSchedule(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSchedule::StartSchedule(CAI_ScriptedSchedule *this, CAI_BaseNPC *pTarget)
{
  const char *pszValue; // eax
  CBasePlayer *EntityGeneric; // ebx
  CAI_Hint *Hint; // eax
  const char *v6; // esi
  const char *DebugName; // eax
  int m_nForceState; // ecx
  CAI_ScriptedSchedule::Schedule_t m_nSchedule; // eax
  const char *v10; // ecx
  const char *v11; // eax
  CAI_ScriptedSchedule::Schedule_t v12; // eax
  bool v13; // zf
  unsigned __int8 m_Value; // al
  Activity v15; // ecx
  const char *v16; // esi
  const char *v17; // eax
  unsigned __int8 v18; // al
  Activity v19; // ecx
  const char *v20; // esi
  const char *v21; // eax
  CHintCriteria hintCriteria; // [esp+10h] [ebp-58h] BYREF
  int savedregs; // [esp+68h] [ebp+0h] BYREF

  if ( pTarget == nullptr )
    return;
  pszValue = this->m_sGoalEnt.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  EntityGeneric = CGlobalEntityList::FindEntityGeneric(
                    this: &gEntList,
                    pStartEntity: nullptr,
                    szName: pszValue,
                    pSearchingEntity: this,
                    pActivator: nullptr,
                    pCaller: nullptr);
  if ( EntityGeneric == nullptr )
  {
    CHintCriteria::CHintCriteria(this: &hintCriteria);
    CHintCriteria::SetGroup(this: &hintCriteria, group: this->m_sGoalEnt);
    CHintCriteria::SetHintType(this: &hintCriteria, nHintType: -1);
    if ( (pTarget->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pTarget, a2: (int)&savedregs);
    CHintCriteria::AddIncludePosition(this: &hintCriteria, position: &pTarget->m_vecAbsOrigin, radius: 3.4028235e38);
    if ( (pTarget->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pTarget, a2: (int)&savedregs);
    Hint = CAI_HintManager::FindHint(position: &pTarget->m_vecAbsOrigin, &hintCriteria);
    if ( Hint == nullptr )
    {
      v6 = this->m_sGoalEnt.pszValue;
      if ( v6 == nullptr )
        v6 = locale;
      DebugName = CBaseEntity::GetDebugName(this);
      _DevMsg(a1: 1, a2: "Can't find goal entity %s\nCan't execute script %s\n", v6, DebugName);
      CHintCriteria::~CHintCriteria(this: &hintCriteria);
      return;
    }
    EntityGeneric = (CBasePlayer *)Hint;
    CHintCriteria::~CHintCriteria(this: &hintCriteria);
  }
  if ( pTarget->m_SleepState > AISS_AWAKE )
    pTarget->Wake(this: pTarget, a2: true);
  pTarget->m_flNextDecisionTime = 0.0;
  pTarget->m_Efficiency = AIE_NORMAL;
  m_nForceState = this->m_nForceState;
  if ( forcedStatesMap[m_nForceState] != NPC_STATE_NONE )
    CAI_BaseNPC::SetState(this: pTarget, State: forcedStatesMap[m_nForceState]);
  m_nSchedule = this->m_nSchedule;
  if ( m_nSchedule == SCHED_SCRIPT_ENEMY_IS_GOAL || m_nSchedule == SCHED_SCRIPT_ENEMY_IS_GOAL_AND_RUN_TO_GOAL )
  {
    if ( EntityGeneric->MyCombatCharacterPointer(this: EntityGeneric) != nullptr )
    {
      CAI_BaseNPC::SetEnemy(this: pTarget, pEnemy: EntityGeneric, bSetCondNewEnemy: true);
      if ( (EntityGeneric->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: EntityGeneric, a2: (int)&savedregs);
      pTarget->UpdateEnemyMemory(this: pTarget, a2: EntityGeneric, a3: &EntityGeneric->m_vecAbsOrigin, a4: nullptr);
      CAI_BaseNPC::SetCondition(this: pTarget, iCondition: 36);
    }
    else
    {
      v10 = this->m_sGoalEnt.pszValue;
      if ( v10 == nullptr )
        v10 = locale;
      v11 = this->m_iName.m_Value.pszValue;
      if ( v11 == nullptr )
        v11 = locale;
      DevMsg(a1: "Scripted schedule %s specified an invalid enemy %s\n", v11, v10);
    }
  }
  v12 = this->m_nSchedule;
  switch ( v12 )
  {
    case SCHED_SCRIPT_WALK_TO_GOAL:
    case SCHED_SCRIPT_RUN_TO_GOAL:
    case SCHED_SCRIPT_ENEMY_IS_GOAL_AND_RUN_TO_GOAL:
      v13 = v12 == SCHED_SCRIPT_WALK_TO_GOAL;
      m_Value = pTarget->m_MoveType.m_Value;
      v15 = 4 * !v13 + 6;
      if ( m_Value == 4 || m_Value == 5 )
        v15 = ACT_FLY;
      if ( pTarget->ScheduledMoveToGoalEntity(this: pTarget, a2: 2, a3: EntityGeneric, a4: v15) )
        goto LABEL_46;
      if ( (this->m_spawnflags.m_Value & 0x800) == 0 )
      {
        v16 = this->m_sGoalEnt.pszValue;
        if ( v16 == nullptr )
          v16 = locale;
        v17 = CBaseEntity::GetDebugName(this);
        _DevMsg(a1: 1, a2: "ScheduledMoveToGoalEntity to goal entity %s failed\nCan't execute script %s\n", v16, v17);
      }
      break;
    case SCHED_SCRIPT_WALK_PATH_GOAL:
    case SCHED_SCRIPT_RUN_PATH_GOAL:
      v13 = v12 == SCHED_SCRIPT_WALK_PATH_GOAL;
      v18 = pTarget->m_MoveType.m_Value;
      v19 = 4 * !v13 + 6;
      if ( v18 == 4 || v18 == 5 )
        v19 = ACT_FLY;
      if ( pTarget->ScheduledFollowPath(this: pTarget, a2: 2, a3: EntityGeneric, a4: v19) )
      {
LABEL_46:
        pTarget->SetScriptedScheduleIgnoreConditions(this: pTarget, a2: this->m_Interruptability);
      }
      else if ( (this->m_spawnflags.m_Value & 0x800) == 0 )
      {
        v20 = this->m_sGoalEnt.pszValue;
        if ( v20 == nullptr )
          v20 = locale;
        v21 = CBaseEntity::GetDebugName(this);
        _DevMsg(a1: 1, a2: "ScheduledFollowPath to goal entity %s failed\nCan't execute script %s\n", v20, v21);
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020E040
// Name: private: void CAI_ScriptedSchedule::InputStopSchedule(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSchedule::InputStopSchedule(CAI_ScriptedSchedule *this, inputdata_t *inputdata)
{
  CAI_BaseNPC *ScriptEntity; // eax
  CAI_BaseNPC *i; // esi
  const char *pszValue; // ebx
  const char *v6; // eax
  const char *DebugName; // [esp-Ch] [ebp-10h]

  if ( this->m_bDidFireOnce )
  {
    if ( this->m_bGrabAll )
    {
      this->m_hLastFoundEntity.m_Index = -1;
      for ( i = CAI_ScriptedSchedule::FindScriptEntity(this, bCyclic: true);
            i != nullptr;
            i = CAI_ScriptedSchedule::FindScriptEntity(this, bCyclic: true) )
      {
        if ( CAI_BaseNPC::IsCurSchedule(this: i, schedId: 2, fIdeal: true) )
        {
          pszValue = this->m_iClassname.pszValue;
          if ( pszValue == nullptr )
            pszValue = locale;
          DebugName = CBaseEntity::GetDebugName(this: i);
          v6 = CBaseEntity::GetDebugName(this);
          _DevMsg(a1: 2, a2: "%s (%s): StopSchedule called on NPC %s.\n", pszValue, v6, DebugName);
          CAI_BaseNPC::ClearSchedule(this: i, szReason: "Stopping scripted schedule");
        }
      }
    }
    else
    {
      ScriptEntity = CAI_ScriptedSchedule::FindScriptEntity(this, bCyclic: (this->m_spawnflags.m_Value & 0x400) != 0);
      if ( ScriptEntity != nullptr )
        CAI_ScriptedSchedule::StopSchedule(this, pTarget: ScriptEntity);
    }
  }
  else
  {
    _DevMsg(a1: 2, a2: "aiscripted_schedule - StopSchedule called, but schedule's never started.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020E110
// Name: public: void CAI_ScriptedSentence::FindThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSentence::FindThink(CAI_ScriptedSentence *this)
{
  CAI_BaseNPC *Entity; // eax
  int started; // eax
  double v4; // st7
  float v5; // xmm1_4
  float fDelay; // [esp+8h] [ebp-Ch]
  float lengtha; // [esp+10h] [ebp-4h]
  float length; // [esp+10h] [ebp-4h]

  Entity = CAI_ScriptedSentence::FindEntity(this);
  if ( Entity != nullptr )
  {
    started = CAI_ScriptedSentence::StartSentence(this, pTarget: Entity);
    v4 = ((double (__thiscall *)(IVEngineServer *, int))engine->SentenceLength)(a1: engine, a2: started);
    fDelay = v4 + this->m_flRepeat;
    COutputEvent::FireOutput(this: &this->m_OnEndSentence, pActivator: nullptr, pCaller: this, fDelay);
    if ( (this->m_spawnflags.m_Value & 1) != 0 )
      UTIL_Remove(oldObj: this);
    lengtha = v4;
    v5 = (float)(this->m_flDelay + lengtha) + 0.1;
    length = v5;
    if ( v5 < 0.0 )
      length = 0.0;
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CAI_ScriptedSentence::DelayThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(
      this,
      thinkTime: (float)(gpGlobals->curtime + length) + this->m_flRepeat,
      szContext: nullptr);
    this->m_active = false;
  }
  else
  {
    CBaseEntity::SetNextThink(this, thinkTime: (float)(this->m_flRepeat + gpGlobals->curtime) + 0.5, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020E210
// Name: public: void CAI_ScriptedSentence::DelayThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSentence::DelayThink(CAI_ScriptedSentence *this)
{
  const char *pszValue; // eax

  pszValue = this->m_iName.m_Value.pszValue;
  this->m_active = true;
  if ( pszValue == nullptr )
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CAI_ScriptedSentence::FindThink,
    thinkTime: 0.0,
    szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1020E260
// Name: private: static char const __near * CAI_ScriptedSequence::GetSpawnPreIdleSequenceForScript(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__cdecl CAI_ScriptedSequence::GetSpawnPreIdleSequenceForScript(CBaseEntity *pEntity)
{
  CAI_ScriptedSequence *EntBy; // eax
  CBaseEntity *Ent; // esi
  CBaseEntity *result; // eax

  EntBy = CGlobalEntityList::NextEntByClass<CAI_ScriptedSequence>(this: &gEntList, start: nullptr);
  if ( EntBy == nullptr )
    return nullptr;
  while ( (EntBy->m_spawnflags.m_Value & 0x10) == 0 || EntBy->m_iszEntity.pszValue != pEntity->m_iName.m_Value.pszValue )
  {
    Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: EntBy);
    if ( Ent == nullptr )
      return nullptr;
    while ( 1 )
    {
      EntBy = (CAI_ScriptedSequence *)__RTDynamicCast(
                                        inptr: Ent,
                                        VfDelta: 0,
                                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                                        TargetType: &CAI_ScriptedSequence `RTTI Type Descriptor',
                                        isReference: 0);
      if ( EntBy != nullptr )
        break;
      result = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: Ent);
      Ent = result;
      if ( result == nullptr )
        return result;
    }
  }
  result = (CBaseEntity *)EntBy->m_iszPreIdle.pszValue;
  if ( result == nullptr )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020E2F0
// Name: public: void CAI_ScriptedSequence::SequenceDone(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::SequenceDone(CAI_ScriptedSequence *this, CAI_BaseNPC *pNPC)
{
  unsigned int m_Index; // ecx

  if ( !this->m_bSynchPostIdles || this->m_iName.m_Value.pszValue == nullptr )
  {
    if ( this->m_iszPostIdle.pszValue != nullptr )
    {
      m_Index = this->m_hNextCine.m_Index;
      if ( m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
      {
        pNPC->m_scriptState = SCRIPT_POST_IDLE;
        CAI_ScriptedSequence::StartSequence(this, pTarget: pNPC, iszSeq: this->m_iszPostIdle, completeOnEmpty: false);
        goto LABEL_14;
      }
    }
    goto LABEL_13;
  }
  if ( pNPC->m_scriptState != SCRIPT_POST_IDLE )
  {
    if ( this->m_iszPostIdle.pszValue != nullptr
      && CHandle<CBaseEntity>::operator==(this: &this->m_hNextCine, val: nullptr) )
    {
      CAI_ScriptedSequence::SynchNewSequence(
        this,
        newState: SCRIPT_POST_IDLE,
        iszSequence: this->m_iszPostIdle,
        bSynchOtherScenes: true);
      goto LABEL_14;
    }
LABEL_13:
    CAI_ScriptedSequence::PostIdleDone(this, pNPC);
  }
LABEL_14:
  COutputEvent::FireOutput(this: &this->m_OnEndSequence, pActivator: nullptr, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1020E3D0
// Name: public: void CAI_ScriptedSequence::FixScriptNPCSchedule(class CAI_BaseNPC __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::FixScriptNPCSchedule(
        CAI_ScriptedSequence *this,
        CAI_BaseNPC *pNPC,
        __int16 iSavedCineFlags)
{
  NPC_STATE m_IdealNPCState; // eax

  m_IdealNPCState = pNPC->m_IdealNPCState;
  if ( m_IdealNPCState != NPC_STATE_DEAD && m_IdealNPCState != NPC_STATE_IDLE )
    pNPC->m_IdealNPCState = NPC_STATE_IDLE;
  if ( CAI_BaseNPC::GetTask(this: pNPC) != nullptr
    && (CAI_BaseNPC::GetTask(this: pNPC)->iTask == 117 || CAI_BaseNPC::GetTask(this: pNPC)->iTask == 118)
    && (iSavedCineFlags & 0x800) == 0
    && (pNPC->m_fFlags.m_Value & 0x800) != 0 )
  {
    CBaseEntity::RemoveFlag(this: pNPC, flagsToRemove: 2048);
  }
  CAI_BaseNPC::ClearSchedule(this: pNPC, szReason: "Finished scripted sequence");
}

//------------------------------------------------------------------------------
// Address: 0x1020E440
// Name: private: void CAI_ScriptedSchedule::ScriptThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSchedule::ScriptThink(CAI_ScriptedSchedule *this)
{
  CAI_BaseNPC *ScriptEntity; // eax
  CAI_BaseNPC *v3; // edi
  const char *pszValue; // eax
  const char *v5; // ecx
  const char *DebugName; // eax
  CAI_BaseNPC *v7; // edi
  const char *v8; // ecx
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // [esp-4h] [ebp-14h]
  const char *thinkTime; // [esp+0h] [ebp-10h]
  const char *thinkTimea; // [esp+0h] [ebp-10h]
  const char *v16; // [esp+4h] [ebp-Ch]
  const char *v17; // [esp+4h] [ebp-Ch]

  if ( !this->m_bGrabAll )
  {
    ScriptEntity = CAI_ScriptedSchedule::FindScriptEntity(this, bCyclic: (this->m_spawnflags.m_Value & 0x400) != 0);
    v3 = ScriptEntity;
    if ( ScriptEntity != nullptr )
    {
      pszValue = ScriptEntity->m_iName.m_Value.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      v5 = this->m_iszEntity.pszValue;
      if ( v5 == nullptr )
        v5 = locale;
      v16 = pszValue;
      thinkTime = v5;
      DebugName = CBaseEntity::GetDebugName(this);
      _DevMsg(a1: 2, a2: "scripted_schedule \"%s\" using NPC \"%s\"(%s)\n", DebugName, thinkTime, v16);
      CAI_ScriptedSchedule::StartSchedule(this, pTarget: v3);
      this->m_bDidFireOnce = true;
      return;
    }
    goto LABEL_15;
  }
  this->m_hLastFoundEntity.m_Index = -1;
  v7 = CAI_ScriptedSchedule::FindScriptEntity(this, bCyclic: true);
  if ( v7 == nullptr )
  {
LABEL_15:
    v11 = this->m_iszEntity.pszValue;
    if ( v11 == nullptr )
      v11 = locale;
    v17 = v11;
    v12 = CBaseEntity::GetDebugName(this);
    _DevMsg(a1: 2, a2: "scripted_schedule \"%s\" can't find NPC \"%s\"\n", v12, v17);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
    return;
  }
  do
  {
    v8 = this->m_iszEntity.pszValue;
    if ( v8 == nullptr )
      v8 = locale;
    v9 = v7->m_iName.m_Value.pszValue;
    if ( v9 == nullptr )
      v9 = locale;
    thinkTimea = v8;
    v13 = v9;
    v10 = CBaseEntity::GetDebugName(this);
    _DevMsg(a1: 2, a2: "scripted_schedule \"%s\" using NPC \"%s\"(%s)\n", v10, v13, thinkTimea);
    CAI_ScriptedSchedule::StartSchedule(this, pTarget: v7);
    v7 = CAI_ScriptedSchedule::FindScriptEntity(this, bCyclic: true);
  }
  while ( v7 != nullptr );
  this->m_bDidFireOnce = true;
}

//------------------------------------------------------------------------------
// Address: 0x1020E580
// Name: private: void CAI_ScriptedSchedule::InputStartSchedule(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSchedule::InputStartSchedule(CAI_ScriptedSchedule *this, inputdata_t *inputdata)
{
  if ( this->m_nForceState == 0 && this->m_nSchedule == SCHED_SCRIPT_NONE )
    _DevMsg(a1: 2, a2: "aiscripted_schedule - no schedule or state has been set!\n");
  if ( !this->m_bDidFireOnce || (this->m_spawnflags.m_Value & 4) != 0 )
  {
    if ( inputdata->pActivator != nullptr )
      this->m_hActivator.m_Index = inputdata->pActivator->GetRefEHandle(this: inputdata->pActivator)->m_Index;
    else
      this->m_hActivator.m_Index = -1;
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CAI_ScriptedSchedule::ScriptThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
  else
  {
    _DevMsg(a1: 2, a2: "aiscripted_schedule - not playing schedule again: not flagged to repeat\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020E630
// Name: public: void CAI_ScriptedSentence::InputBeginSentence(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSentence::InputBeginSentence(CAI_ScriptedSentence *this, inputdata_t *inputdata)
{
  if ( this->m_active )
  {
    this->m_pActivator = inputdata->pActivator;
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CAI_ScriptedSentence::FindThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020E680
// Name: public: virtual void CAI_ScriptedSentence::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSentence::Spawn(CAI_ScriptedSentence *this)
{
  bool v2; // zf
  bool v3; // cf

  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  v2 = this->m_iName.m_Value.pszValue == nullptr;
  this->m_active = true;
  if ( v2 )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CAI_ScriptedSentence::FindThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
  }
  switch ( this->m_TempAttenuation )
  {
    case 1:
      this->m_iSoundLevel = SNDLVL_80dB;
      break;
    case 2:
      this->m_iSoundLevel = SNDLVL_85dB;
      break;
    case 3:
      this->m_iSoundLevel = SNDLVL_NONE;
      break;
    default:
      this->m_iSoundLevel = SNDLVL_70dB;
      break;
  }
  v3 = this->m_flVolume > 0.0;
  this->m_TempAttenuation = 0;
  if ( !v3 )
    this->m_flVolume = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1020E790
// Name: public: CAI_ScriptedSequence::CAI_ScriptedSequence(void)
// Source: json
//------------------------------------------------------------------------------
CAI_ScriptedSequence *__thiscall CAI_ScriptedSequence::CAI_ScriptedSequence(CAI_ScriptedSequence *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CAI_ScriptedSequence_vtbl *)&CAI_ScriptedSequence::`vftable';
  this->m_hTargetEnt.m_Index = -1;
  this->m_hNextCine.m_Index = -1;
  this->m_hLastFoundEntity.m_Index = -1;
  this->m_hForcedTarget.m_Index = -1;
  this->m_OnBeginSequence.m_Value.iVal = 0;
  this->m_OnBeginSequence.m_Value.eVal.m_Index = -1;
  this->m_OnBeginSequence.m_Value.fieldType = FIELD_VOID;
  this->m_OnEndSequence.m_Value.iVal = 0;
  this->m_OnEndSequence.m_Value.eVal.m_Index = -1;
  this->m_OnEndSequence.m_Value.fieldType = FIELD_VOID;
  this->m_OnPostIdleEndSequence.m_Value.iVal = 0;
  this->m_OnPostIdleEndSequence.m_Value.eVal.m_Index = -1;
  this->m_OnPostIdleEndSequence.m_Value.fieldType = FIELD_VOID;
  this->m_OnCancelSequence.m_Value.iVal = 0;
  this->m_OnCancelSequence.m_Value.eVal.m_Index = -1;
  this->m_OnCancelSequence.m_Value.fieldType = FIELD_VOID;
  this->m_OnCancelFailedSequence.m_Value.iVal = 0;
  this->m_OnCancelFailedSequence.m_Value.eVal.m_Index = -1;
  this->m_OnCancelFailedSequence.m_Value.fieldType = FIELD_VOID;
  this->m_OnScriptEvent[0].m_Value.iVal = 0;
  this->m_OnScriptEvent[0].m_Value.eVal.m_Index = -1;
  this->m_OnScriptEvent[0].m_Value.fieldType = FIELD_VOID;
  this->m_OnScriptEvent[1].m_Value.iVal = 0;
  this->m_OnScriptEvent[1].m_Value.eVal.m_Index = -1;
  this->m_OnScriptEvent[1].m_Value.fieldType = FIELD_VOID;
  this->m_OnScriptEvent[2].m_Value.iVal = 0;
  this->m_OnScriptEvent[2].m_Value.eVal.m_Index = -1;
  this->m_OnScriptEvent[2].m_Value.fieldType = FIELD_VOID;
  this->m_OnScriptEvent[3].m_Value.iVal = 0;
  this->m_OnScriptEvent[3].m_Value.eVal.m_Index = -1;
  this->m_OnScriptEvent[3].m_Value.fieldType = FIELD_VOID;
  this->m_OnScriptEvent[4].m_Value.iVal = 0;
  this->m_OnScriptEvent[4].m_Value.eVal.m_Index = -1;
  this->m_OnScriptEvent[4].m_Value.fieldType = FIELD_VOID;
  this->m_OnScriptEvent[5].m_Value.iVal = 0;
  this->m_OnScriptEvent[5].m_Value.eVal.m_Index = -1;
  this->m_OnScriptEvent[5].m_Value.fieldType = FIELD_VOID;
  this->m_OnScriptEvent[6].m_Value.iVal = 0;
  this->m_OnScriptEvent[6].m_Value.eVal.m_Index = -1;
  this->m_OnScriptEvent[6].m_Value.fieldType = FIELD_VOID;
  this->m_OnScriptEvent[7].m_Value.iVal = 0;
  this->m_OnScriptEvent[7].m_Value.eVal.m_Index = -1;
  this->m_OnScriptEvent[7].m_Value.fieldType = FIELD_VOID;
  this->m_hInteractionRelativeEntity.m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020E8D0
// Name: public: virtual CAI_ScriptedSequence::~CAI_ScriptedSequence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::~CAI_ScriptedSequence(CAI_ScriptedSequence *this)
{
  VMatrix *p_m_matInteractionPosition; // esi
  int i; // edi

  p_m_matInteractionPosition = &this->m_matInteractionPosition;
  for ( i = 7; i >= 0; --i )
  {
    p_m_matInteractionPosition = (VMatrix *)((char *)p_m_matInteractionPosition - 24);
    CBaseEntityOutput::~CBaseEntityOutput(this: (CBaseEntityOutput *)p_m_matInteractionPosition);
  }
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnCancelFailedSequence);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnCancelSequence);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPostIdleEndSequence);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnEndSequence);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnBeginSequence);
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020E9A0
// Name: private: static void CAI_ScriptedSequence::ScriptEntityCancel(class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAI_ScriptedSequence::ScriptEntityCancel(CAI_ScriptedSequence *pentCine, bool bPretendSuccess)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  int v4; // eax
  int v5; // esi
  CHandle<CBaseEntity> *v6; // ecx
  unsigned int v7; // eax
  CTimedEventMgr *m_pEventMgr; // ebx
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( pentCine != nullptr
    && (pentCine->m_iClassname.pszValue == "scripted_sequence"
     || CBaseEntity::ClassMatchesComplex(this: pentCine, pszClassOrWildcard: "scripted_sequence") != 0) )
  {
    m_Index = pentCine->m_hTargetEnt.m_Index;
    if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != nullptr )
      {
        v4 = (int)m_pEntity->__vftable[24].GetRefEHandle(this: m_pEntity);
        v5 = v4;
        if ( v4 != 0 )
        {
          if ( *(_DWORD *)(v4 + 2520) == 4 )
          {
            v6 = (CHandle<CBaseEntity> *)(v4 + 2876);
            *(_DWORD *)(v4 + 2872) = 3;
            v7 = *(_DWORD *)(v4 + 2876);
            if ( v7 != -1
              && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7)
              && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity != nullptr )
            {
              m_pEventMgr = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: v6)[1].m_Network.m_TimerEvent.m_pEventMgr;
            }
            else
            {
              LOWORD(m_pEventMgr) = 0;
            }
            CAI_BaseNPC::CineCleanup(this: (CAI_BaseNPC *)v5, a2: (int)&savedregs);
            CAI_ScriptedSequence::FixScriptNPCSchedule(
              this: pentCine,
              pNPC: (CAI_BaseNPC *)v5,
              iSavedCineFlags: (__int16)m_pEventMgr);
          }
          else
          {
            pentCine->m_hTargetEnt.m_Index = -1;
            CBaseEntity::SetEffects(this: (CBaseEntity *)v4, nEffects: pentCine->m_saved_effects);
            *(_DWORD *)(v5 + 2876) = -1;
            CAI_BaseNPC::SetTarget(this: (CAI_BaseNPC *)v5, pTarget: nullptr);
            *(_DWORD *)(v5 + 2792) = -1;
            if ( *(_DWORD *)(v5 + 2528) != 1 )
              *(_DWORD *)(v5 + 2528) = 1;
          }
        }
      }
    }
    pentCine->m_iDelay = 0;
    if ( bPretendSuccess )
    {
      COutputEvent::FireOutput(this: &pentCine->m_OnEndSequence, pActivator: nullptr, pCaller: pentCine, fDelay: 0.0);
      COutputEvent::FireOutput(
        this: &pentCine->m_OnPostIdleEndSequence,
        pActivator: nullptr,
        pCaller: pentCine,
        fDelay: 0.0);
    }
    else
    {
      COutputEvent::FireOutput(this: &pentCine->m_OnCancelSequence, pActivator: nullptr, pCaller: pentCine, fDelay: 0.0);
      if ( pentCine->m_startTime == 0.0 )
        COutputEvent::FireOutput(
          this: &pentCine->m_OnCancelFailedSequence,
          pActivator: nullptr,
          pCaller: pentCine,
          fDelay: 0.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020EB40
// Name: public: virtual void CAI_ScriptedSequence::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::UpdateOnRemove(CAI_ScriptedSequence *this)
{
  CAI_ScriptedSequence::ScriptEntityCancel(pentCine: this, bPretendSuccess: false);
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020EB60
// Name: public: void CAI_ScriptedSequence::InputCancelSequence(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::InputCancelSequence(CAI_ScriptedSequence *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax

  if ( !this->m_bInitiatedSelfDelete )
  {
    pszValue = this->m_iszPlay.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _DevMsg(a1: 2, a2: "InputCancelScript: Cancelling script '%s'\n", pszValue);
    if ( this->m_bThinking )
    {
      CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
      this->m_bThinking = false;
    }
    CAI_ScriptedSequence::ScriptEntityCancel(pentCine: this, bPretendSuccess: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020EBC0
// Name: public: void CAI_ScriptedSequence::InputScriptPlayerDeath(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::InputScriptPlayerDeath(CAI_ScriptedSequence *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax

  if ( this->m_iPlayerDeathBehavior == 1 && !this->m_bInitiatedSelfDelete )
  {
    pszValue = this->m_iszPlay.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _DevMsg(a1: 2, a2: "InputCancelScript: Cancelling script '%s'\n", pszValue);
    if ( this->m_bThinking )
    {
      CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
      this->m_bThinking = false;
    }
    CAI_ScriptedSequence::ScriptEntityCancel(pentCine: this, bPretendSuccess: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020EC30
// Name: public: void CAI_ScriptedSequence::SynchronizeSequence(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::SynchronizeSequence(CAI_ScriptedSequence *this, CAI_BaseNPC *pNPC)
{
  int m_Value; // ebx
  CStudioHdr *m_pStudioHdr; // eax
  float v6; // xmm0_4
  edict_t *m_pPev; // ecx
  float v8; // xmm0_4
  bool v9; // zf
  edict_t *v10; // ecx
  float flCycleRate; // [esp+18h] [ebp-4h]
  float pNPCa; // [esp+24h] [ebp+8h]
  float pNPCb; // [esp+24h] [ebp+8h]

  this->m_bForceSynch = false;
  m_Value = pNPC->m_nSequence.m_Value;
  if ( pNPC->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: pNPC) != nullptr )
    CBaseAnimating::LockStudioHdr(this: pNPC);
  m_pStudioHdr = pNPC->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  flCycleRate = CBaseAnimating::GetSequenceCycleRate(this: pNPC, pStudioHdr: m_pStudioHdr, iSequence: m_Value);
  v6 = gpGlobals->curtime - this->m_startTime;
  if ( v6 >= 0.0 )
  {
    if ( v6 <= 0.15 )
    {
      pNPCa = gpGlobals->curtime - this->m_startTime;
      if ( v6 == 0.0 )
        return;
    }
    else
    {
      pNPCa = 0.15000001;
    }
    if ( pNPC->m_flCycle.m_Value != 0.0 )
    {
      if ( pNPC->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&pNPC->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = pNPC->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3ACu);
      }
      pNPC->m_flCycle.m_Value = 0.0;
    }
    CAI_BaseNPC::AutoMovement(this: pNPC, flInterval: pNPCa, pTarget: nullptr, pTraceResult: nullptr);
    v8 = pNPCa * flCycleRate;
    v9 = pNPC->m_flCycle.m_Value == (float)(pNPCa * flCycleRate);
    pNPCb = pNPCa * flCycleRate;
    if ( !v9 )
    {
      if ( pNPC->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&pNPC->m_Network + 76) |= 1u;
        pNPC->m_flCycle.m_Value = v8;
      }
      else
      {
        v10 = pNPC->m_Network.m_pPev;
        if ( v10 != nullptr )
        {
          CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x3ACu);
          v8 = pNPCb;
        }
        pNPC->m_flCycle.m_Value = v8;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020ED90
// Name: public: void CAI_ScriptedSequence::CancelScript(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::CancelScript(CAI_ScriptedSequence *this)
{
  const char *pszValue; // eax
  const char *v3; // eax
  CAI_ScriptedSequence *i; // esi
  const char *v5; // eax

  pszValue = this->m_iszPlay.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  _DevMsg(a1: 2, a2: "Cancelling script: %s\n", pszValue);
  if ( (this->m_bDontCancelOtherSequences || (this->m_spawnflags.m_Value & 0x1000) != 0) && this->m_startTime != 0.0
    || (v3 = this->m_iName.m_Value.pszValue) == nullptr )
  {
    CAI_ScriptedSequence::ScriptEntityCancel(pentCine: this, bPretendSuccess: false);
  }
  else
  {
    for ( i = (CAI_ScriptedSequence *)CGlobalEntityList::FindEntityByName(
                                        this: &gEntList,
                                        pStartEntity: nullptr,
                                        szName: v3,
                                        pSearchingEntity: nullptr,
                                        pActivator: nullptr,
                                        pCaller: nullptr,
                                        pFilter: nullptr);
          i != nullptr;
          i = (CAI_ScriptedSequence *)CGlobalEntityList::FindEntityByName(
                                        this: &gEntList,
                                        pStartEntity: i,
                                        szName: v5,
                                        pSearchingEntity: nullptr,
                                        pActivator: nullptr,
                                        pCaller: nullptr,
                                        pFilter: nullptr) )
    {
      CAI_ScriptedSequence::ScriptEntityCancel(pentCine: i, bPretendSuccess: false);
      v5 = this->m_iName.m_Value.pszValue;
      if ( v5 == nullptr )
        v5 = locale;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020EED0
// Name: public: void CAI_ScriptedSequence::StartScript(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::StartScript(CAI_ScriptedSequence *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  int v4; // eax
  int v5; // esi
  int v6; // eax
  unsigned int v7; // ebx
  CBaseEdict *v8; // ecx
  unsigned int v9; // ecx
  CBaseEntityList *v10; // ebx
  int v11; // eax
  int v12; // edx
  signed int v13; // ecx
  CEntInfo *v14; // edx
  IHandleEntity *v15; // edx
  IHandleEntity_vtbl *v16; // ecx
  IHandleEntity *v17; // ecx
  IHandleEntity_vtbl *v18; // ecx
  CBaseEntity *v19; // ecx
  int v20; // eax
  IHandleEntity *v21; // ebx
  const char *DebugName; // eax
  unsigned int v23; // esi
  CEntInfo *v24; // ebx
  IHandleEntity *v25; // ebx
  bool v26; // al
  int m_Value; // edx
  bool v28; // zf
  int v29; // ebx
  const Vector *AbsOrigin; // eax
  double y; // st7
  float v32; // ecx
  float v33; // xmm0_4
  signed int v34; // ebx
  int v35; // eax
  edict_t *m_pPev; // eax
  const char *v37; // eax
  signed int v38; // [esp+Ch] [ebp-38h]
  const char *v39; // [esp+10h] [ebp-34h]
  double curtime; // [esp+14h] [ebp-30h]
  double thinkTime; // [esp+1Ch] [ebp-28h]
  const char *thinkTime_4; // [esp+20h] [ebp-24h]
  QAngle angles; // [esp+30h] [ebp-14h] BYREF
  signed int v44; // [esp+3Ch] [ebp-8h]
  CBaseEntity *v45; // [esp+40h] [ebp-4h]

  m_Index = this->m_hTargetEnt.m_Index;
  if ( m_Index == -1 )
    return;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return;
  m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity == nullptr )
    return;
  v4 = (int)m_pEntity->__vftable[24].GetRefEHandle(this: m_pEntity);
  v5 = v4;
  if ( v4 == 0 )
    return;
  v6 = *(_DWORD *)(v4 + 760);
  v7 = v6 & 0xFFFFFF7F;
  if ( v6 != (v6 & 0xFFFFFF7F) )
  {
    if ( *(_BYTE *)(v5 + 84) != 0 )
    {
      *(_BYTE *)(v5 + 88) |= 1u;
    }
    else
    {
      v8 = *(CBaseEdict **)(v5 + 24);
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: v8, offset: 0x2F8u);
    }
    *(_DWORD *)(v5 + 760) = v7;
  }
  v9 = *(_DWORD *)(v5 + 2876);
  if ( v9 != -1 )
  {
    v10 = g_pEntityList;
    v11 = (unsigned __int16)v9;
    v12 = (unsigned __int16)v9;
    v13 = HIWORD(v9);
    v14 = &g_pEntityList->m_EntPtrArray[v12];
    v44 = v13;
    if ( v14->m_SerialNumber == v13 && v14->m_pEntity != nullptr )
    {
      if ( g_pEntityList->m_EntPtrArray[v11].m_SerialNumber == v13 )
        v15 = g_pEntityList->m_EntPtrArray[v11].m_pEntity;
      else
        v15 = nullptr;
      v16 = v15[234].__vftable;
      if ( v16 != (IHandleEntity_vtbl *)-1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_SerialNumber == (unsigned int)v16 >> 16
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_pEntity != nullptr )
      {
        if ( g_pEntityList->m_EntPtrArray[v11].m_SerialNumber == v44 )
          v17 = g_pEntityList->m_EntPtrArray[v11].m_pEntity;
        else
          v17 = nullptr;
        v18 = v17[234].__vftable;
        if ( v18 == (IHandleEntity_vtbl *)-1
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_SerialNumber != (unsigned int)v18 >> 16 )
        {
          v45 = nullptr;
        }
        else
        {
          v45 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_pEntity;
        }
        if ( g_pEntityList->m_EntPtrArray[v11].m_SerialNumber == v44 )
          v19 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[v11].m_pEntity;
        else
          v19 = nullptr;
        v20 = v11;
        if ( g_pEntityList->m_EntPtrArray[v20].m_SerialNumber == v44 )
          v21 = g_pEntityList->m_EntPtrArray[v20].m_pEntity;
        else
          v21 = nullptr;
        if ( CHandle<CBaseEntity>::operator!=(this: (CHandle<CBaseEntity> *)&v21[234], val: v19) )
          v45[1].m_Network.m_TimerEvent.m_pCallback = (IEventRegisterCallback *)-1;
        thinkTime_4 = CBaseEntity::GetDebugName(this: v45);
        DebugName = CBaseEntity::GetDebugName(this);
        _DevMsg(a1: 2, a2: "script \"%s\" kicking script \"%s\" out of the queue\n", DebugName, thinkTime_4);
        v10 = g_pEntityList;
      }
      v23 = *(_DWORD *)(v5 + 2876);
      if ( v23 == -1 || (v24 = &v10->m_EntPtrArray[(unsigned __int16)v23])->m_SerialNumber != HIWORD(v23) )
        v25 = nullptr;
      else
        v25 = v24->m_pEntity;
      if ( this != nullptr )
        v25[234].__vftable = (IHandleEntity_vtbl *)this->GetRefEHandle(this)->m_Index;
      else
        v25[234].__vftable = (IHandleEntity_vtbl *)-1;
      return;
    }
  }
  if ( this->m_iszNextScript.pszValue == nullptr )
    this->m_hNextCine.m_Index = -1;
  *(_DWORD *)(v5 + 2792) = this->GetRefEHandle(this)->m_Index;
  *(_DWORD *)(v5 + 2540) = 0;
  *(_DWORD *)(v5 + 2532) = 0;
  *(_DWORD *)(v5 + 2876) = this->GetRefEHandle(this)->m_Index;
  CAI_BaseNPC::SetTarget(this: (CAI_BaseNPC *)v5, pTarget: this);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 1472))(a1: v5);
  this->m_bTargetWasAsleep = *(_DWORD *)(v5 + 2544) != 0;
  v26 = CAI_BaseNPC::WokeThisTick(this: (CAI_BaseNPC *)v5);
  if ( this->m_bTargetWasAsleep )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 1648))(a1: v5, a2: 1);
LABEL_49:
    this->m_bTargetWasAsleep = true;
    CBaseEntity::AddEffects(this: (CBaseEntity *)v5, nEffects: 32);
    goto LABEL_50;
  }
  if ( v26 )
    goto LABEL_49;
LABEL_50:
  m_Value = this->m_fEffects.m_Value;
  this->m_saved_effects = *(_DWORD *)(v5 + 164) & 0xFFFFFFDF;
  CBaseEntity::AddEffects(this: (CBaseEntity *)v5, nEffects: m_Value);
  v28 = !this->m_bDisableNPCCollisions;
  this->m_savedFlags = *(_DWORD *)(v5 + 200);
  this->m_savedCollisionGroup = *(_DWORD *)(v5 + 324);
  if ( !v28 )
    CBaseEntity::SetCollisionGroup(this: (CBaseEntity *)v5, collisionGroup: 19);
  switch ( this->m_fMoveTo )
  {
    case 0:
    case 5:
      goto $LN8_31;
    case 1:
      *(_DWORD *)(v5 + 2872) = 4;
      break;
    case 2:
      *(_DWORD *)(v5 + 2872) = 5;
      break;
    case 3:
      *(_DWORD *)(v5 + 2872) = 6;
      break;
    case 4:
      this->m_bIsTeleportingDueToMoveTo = true;
      v29 = *(_DWORD *)v5;
      AbsOrigin = CBaseEntity::GetAbsOrigin(this);
      (*(void (__thiscall **)(int, const Vector *, _DWORD, Vector *, int))(v29 + 444))(
        a1: v5,
        a2: AbsOrigin,
        a3: 0,
        a4: &vec3_origin,
        a5: 1);
      y = this->m_angRotation.m_Value.y;
      this->m_bIsTeleportingDueToMoveTo = false;
      *(float *)(*(_DWORD *)(v5 + 2788) + 20) = y;
      CBaseEntity::SetLocalAngularVelocity(this: (CBaseEntity *)v5, vecAngVelocity: &vec3_angle);
      CBaseEntity::AddEffects(this: (CBaseEntity *)v5, nEffects: 8);
      v32 = *(float *)(v5 + 720);
      *(_QWORD *)&angles.x = *(_QWORD *)(v5 + 712);
      v33 = this->m_angRotation.m_Value.y;
      angles.z = v32;
      angles.y = v33;
      CBaseEntity::SetLocalAngles(this: (CBaseEntity *)v5, &angles);
$LN8_31:
      *(_DWORD *)(v5 + 2872) = 1;
      if ( this->m_bIgnoreGravity )
      {
        CBaseEntity::AddFlag(this: (CBaseEntity *)v5, flags: 2048);
        CBaseEntity::SetGroundEntity(this: (CBaseEntity *)v5, ground: nullptr);
      }
      break;
    default:
      break;
  }
  this->m_bDelayed = false;
  CAI_ScriptedSequence::DelayStart(this, bDelay: true);
  if ( *(_DWORD *)(v5 + 2528) != 4 )
    *(_DWORD *)(v5 + 2528) = 4;
  if ( (*(_DWORD *)(v5 + 196) & 0x400000) != 0 )
  {
    v34 = 0;
    if ( CBaseEntity::GetNextThink(this: (CBaseEntity *)v5, szContext: nullptr) != -1.0 )
    {
      v35 = *(_DWORD *)(v5 + 24);
      if ( v35 != 0 )
        v44 = (signed int)(v35 - (unsigned int)gpGlobals->pEdicts) >> 4;
      else
        v44 = 0;
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        v34 = m_pPev - gpGlobals->pEdicts;
      thinkTime = CBaseEntity::GetNextThink(this: (CBaseEntity *)v5, szContext: nullptr);
      curtime = gpGlobals->curtime;
      v39 = CBaseEntity::GetDebugName(this: (CBaseEntity *)v5);
      v38 = v44;
      v37 = CBaseEntity::GetDebugName(this);
      DevWarning(
        a1: "scripted_sequence %d:%s - restarting dormant entity %d:%s : %.1f:%.1f\n",
        v34,
        v37,
        v38,
        v39,
        curtime,
        thinkTime);
      CBaseEntity::SetNextThink(this: (CBaseEntity *)v5, thinkTime: gpGlobals->curtime, szContext: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020F3D0
// Name: public: void CAI_ScriptedSequence::ScriptThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::ScriptThink(CAI_ScriptedSequence *this)
{
  const char *v2; // ebx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  IHandleEntity_vtbl *v5; // ecx
  IHandleEntity *v6; // ecx
  IHandleEntity_vtbl *v7; // eax
  signed int v8; // eax
  edict_t *m_pPev; // ecx
  signed int v10; // edi
  const char *DebugName; // eax
  const char *v12; // ecx
  edict_t *v13; // eax
  signed int v14; // edi
  const char *v15; // eax
  signed int v16; // [esp-8h] [ebp-1Ch]
  const char *thinkTime; // [esp+4h] [ebp-10h]
  const char *pszValue; // [esp+10h] [ebp-4h]

  if ( g_pAINetworkManager == nullptr || g_pAINetworkManager->m_fInitalized )
  {
    if ( CAI_ScriptedSequence::FindEntity(this) )
    {
      CAI_ScriptedSequence::StartScript(this);
      v2 = locale;
      pszValue = this->m_iszEntity.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      m_Index = this->m_hTargetEnt.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      v5 = m_pEntity[51].__vftable;
      if ( v5 != nullptr )
        v2 = (const char *)v5;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        v6 = nullptr;
      else
        v6 = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      v7 = v6[6].__vftable;
      if ( v7 != nullptr )
        v8 = ((char *)v7 - (char *)gpGlobals->pEdicts) >> 4;
      else
        v8 = 0;
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        v10 = m_pPev - gpGlobals->pEdicts;
      else
        v10 = 0;
      v16 = v8;
      DebugName = CBaseEntity::GetDebugName(this);
      _DevMsg(a1: 2, a2: "scripted_sequence %d:\"%s\" using NPC %d:\"%s\"(%s)\n", v10, DebugName, v16, v2, pszValue);
    }
    else
    {
      CAI_ScriptedSequence::CancelScript(this);
      v12 = this->m_iszEntity.pszValue;
      if ( v12 == nullptr )
        v12 = locale;
      v13 = this->m_Network.m_pPev;
      if ( v13 != nullptr )
        v14 = v13 - gpGlobals->pEdicts;
      else
        v14 = 0;
      thinkTime = v12;
      v15 = CBaseEntity::GetDebugName(this);
      _DevMsg(a1: 2, a2: "scripted_sequence %d:\"%s\" can't find NPC \"%s\"\n", v14, v15, thinkTime);
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
    }
  }
  else
  {
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020F560
// Name: public: bool CAI_ScriptedSequence::StartSequence(class CAI_BaseNPC __near *,struct string_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_ScriptedSequence::StartSequence(
        CAI_ScriptedSequence *this,
        CAI_BaseNPC *pTarget,
        string_t iszSeq,
        bool completeOnEmpty)
{
  const char *pszValue; // eax
  bool v6; // zf
  int v8; // edi
  const char *v9; // eax
  const char *DebugName; // eax
  Activity SequenceActivity; // eax
  unsigned int v12; // esi
  edict_t *m_pPev; // ecx
  edict_t *v14; // eax
  const char *v15; // [esp-Ch] [ebp-10h]

  pszValue = iszSeq.pszValue;
  v6 = iszSeq.pszValue == this->m_iszEntry.pszValue;
  this->m_sequenceStarted = true;
  this->m_bIsPlayingEntry = v6;
  if ( iszSeq.pszValue == nullptr )
  {
    if ( completeOnEmpty )
    {
      CAI_ScriptedSequence::SequenceDone(this, pNPC: pTarget);
      return 0;
    }
    pszValue = locale;
  }
  v8 = CBaseAnimating::LookupSequence(this: pTarget, label: pszValue);
  if ( v8 == -1 )
  {
    v9 = iszSeq.pszValue;
    if ( iszSeq.pszValue == nullptr )
      v9 = locale;
    v15 = v9;
    DebugName = CBaseEntity::GetDebugName(this: pTarget);
    _Warning(a1: "%s: unknown scripted sequence \"%s\"\n", DebugName, v15);
    v8 = 0;
  }
  SequenceActivity = CBaseAnimating::GetSequenceActivity(this: pTarget, iSequence: v8);
  if ( SequenceActivity == ACT_INVALID )
    SequenceActivity = ACT_IDLE;
  CAI_BaseNPC::SetActivityAndSequence(
    this: pTarget,
    NewActivity: SequenceActivity,
    iSequence: v8,
    translatedActivity: SequenceActivity,
    weaponActivity: SequenceActivity);
  if ( this->m_bTargetWasAsleep && iszSeq.pszValue != this->m_iszPreIdle.pszValue )
  {
    this->m_bTargetWasAsleep = false;
    v12 = pTarget->m_fEffects.m_Value & 0xFFFFFFDF;
    if ( pTarget->m_fEffects.m_Value != v12 )
    {
      if ( pTarget->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&pTarget->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = pTarget->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
      }
      pTarget->m_fEffects.m_Value = v12;
    }
    v14 = pTarget->m_Network.m_pPev;
    if ( v14 != nullptr )
      v14->m_fStateFlags |= 0x80u;
    CBaseEntity::DispatchUpdateTransmitState(this: pTarget);
    CBaseEntity::AddEffects(this: pTarget, nEffects: 8);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1020F670
// Name: public: bool CAI_ScriptedSequence::FinishedActionSequence(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ScriptedSequence::FinishedActionSequence(CAI_ScriptedSequence *this, CAI_BaseNPC *pNPC)
{
  if ( !this->m_bIsPlayingEntry )
    return !this->m_bLoopActionSequence || pNPC->m_scriptState == SCRIPT_POST_IDLE;
  if ( this->m_iName.m_Value.pszValue != nullptr )
    CAI_ScriptedSequence::SynchNewSequence(
      this,
      newState: SCRIPT_PLAYING,
      iszSequence: this->m_iszPlay,
      bSynchOtherScenes: true);
  else
    CAI_ScriptedSequence::StartSequence(this, pTarget: pNPC, iszSeq: this->m_iszPlay, completeOnEmpty: true);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1020F6E0
// Name: public: void CAI_ScriptedSequence::PostIdleDone(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::PostIdleDone(CAI_ScriptedSequence *this, CAI_BaseNPC *pNPC)
{
  unsigned int v3; // eax
  const char *v4; // ebx
  const char *DebugName; // eax
  unsigned int m_Index; // ecx
  int v7; // eax
  CEntInfo *v8; // edx
  unsigned int v9; // ecx
  int v10; // eax
  bool v11; // zf
  CEntInfo *v12; // eax
  CAI_ScriptedSequence *v13; // edi
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  if ( this->m_iszPostIdle.pszValue != nullptr
    && (this->m_spawnflags.m_Value & 0x100) != 0
    && ((v3 = this->m_hNextCine.m_Index) == -1
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber != HIWORD(v3)
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_pEntity == nullptr) )
  {
    if ( (pNPC->m_debugOverlays & 0x1000) != 0 )
    {
      v4 = (const char *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&pNPC->m_hCine)[1].m_Network.__vftable;
      if ( v4 == nullptr )
        v4 = locale;
      DebugName = CBaseEntity::GetDebugName(this: pNPC);
      _DevMsg(a1: 2, a2: "Post Idle %s finished for %s\n", v4, DebugName);
    }
    pNPC->m_scriptState = SCRIPT_POST_IDLE;
    CAI_ScriptedSequence::StartSequence(this, pTarget: pNPC, iszSeq: this->m_iszPostIdle, completeOnEmpty: false);
  }
  else
  {
    if ( (this->m_spawnflags.m_Value & 4) == 0 )
    {
      CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
      *(_WORD *)&this->m_bThinking = 256;
    }
    CAI_BaseNPC::CineCleanup(this: pNPC, a2: (int)&savedregs);
    CAI_ScriptedSequence::FixScriptNPCSchedule(this, pNPC, iSavedCineFlags: this->m_savedFlags);
    m_Index = this->m_hNextCine.m_Index;
    if ( m_Index != -1 )
    {
      v7 = (unsigned __int16)m_Index;
      v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v9 = HIWORD(m_Index);
      if ( v8->m_SerialNumber == v9 && v8->m_pEntity != nullptr )
      {
        v10 = v7;
        v11 = g_pEntityList->m_EntPtrArray[v10].m_SerialNumber == v9;
        v12 = &g_pEntityList->m_EntPtrArray[v10];
        v13 = v11 ? (CAI_ScriptedSequence *)v12->m_pEntity : nullptr;
        if ( v13 != this || (this->m_spawnflags.m_Value & 4) != 0 )
        {
          if ( pNPC != nullptr )
            v13->m_hTargetEnt.m_Index = pNPC->GetRefEHandle(this: pNPC)->m_Index;
          else
            v13->m_hTargetEnt.m_Index = -1;
          CAI_ScriptedSequence::StartScript(this: v13);
        }
      }
    }
  }
  COutputEvent::FireOutput(this: &this->m_OnPostIdleEndSequence, pActivator: nullptr, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1020F8F0
// Name: public: void CAI_ScriptedSequence::InputMoveToPosition(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::InputMoveToPosition(CAI_ScriptedSequence *this, inputdata_t *inputdata)
{
  unsigned int m_Index; // ecx
  CEntInfo *v4; // eax
  const CBaseHandle *v5; // eax
  unsigned int v6; // ecx
  bool v7; // [esp+Ch] [ebp-4h]

  if ( !this->m_bInitiatedSelfDelete )
  {
    m_Index = this->m_hTargetEnt.m_Index;
    if ( m_Index != -1
      && (v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
      && v4->m_pEntity != nullptr
      && (v5 = v4->m_pEntity->__vftable[24].GetRefEHandle(this: v4->m_pEntity)) != nullptr )
    {
      v6 = v5[718].m_Index;
      if ( v6 == 0 || v6 == 2 )
      {
        v7 = (this->m_spawnflags.m_Value & 0x40) != 0;
        if ( (*(int (__thiscall **)(const CBaseHandle *, bool, int))(v5->m_Index + 1832))(a1: v5, a2: v7, a3: 1) != 0 )
        {
          CAI_ScriptedSequence::StartScript(this);
          this->m_bWaitForBeginSequence = true;
        }
      }
    }
    else
    {
      this->m_sequenceStarted = false;
      this->m_bThinking = true;
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CAI_ScriptedSequence::ScriptThink,
        thinkTime: 0.0,
        szContext: nullptr);
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
      this->m_bWaitForBeginSequence = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020F9E0
// Name: public: void CAI_ScriptedSequence::InputBeginSequence(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::InputBeginSequence(CAI_ScriptedSequence *this, inputdata_t *inputdata)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // eax
  unsigned int v5; // eax
  CAI_BaseNPC *v6; // eax
  CAI_BaseNPC::SCRIPTSTATE m_scriptState; // ecx
  bool v8; // [esp+Ch] [ebp-4h]

  if ( !this->m_bInitiatedSelfDelete )
  {
    this->m_bWaitForBeginSequence = false;
    m_Index = this->m_hTargetEnt.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( (m_pEntity != nullptr
       || (v5 = this->m_hForcedTarget.m_Index) != -1
       && g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber == HIWORD(v5)
       && g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity != nullptr
       && CAI_ScriptedSequence::FindEntity(this)
       && (m_pEntity = CAI_ScriptedSequence::GetTarget(this)) != nullptr)
      && (v6 = m_pEntity->MyNPCPointer(this: m_pEntity)) != nullptr )
    {
      m_scriptState = v6->m_scriptState;
      if ( m_scriptState == SCRIPT_PLAYING || m_scriptState == SCRIPT_POST_IDLE )
      {
        v8 = (this->m_spawnflags.m_Value & 0x40) != 0;
        if ( v6->CanPlaySequence(this: v6, a2: v8, a3: 1) != CANNOT_PLAY )
          CAI_ScriptedSequence::StartScript(this);
      }
    }
    else
    {
      this->m_sequenceStarted = false;
      this->m_bThinking = true;
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CAI_ScriptedSequence::ScriptThink,
        thinkTime: 0.0,
        szContext: nullptr);
      CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
      CAI_ScriptedSequence::ScriptThink(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102107F0
// Name: public: virtual void CAI_ScriptedSequence::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptedSequence::Spawn(CAI_ScriptedSequence *this)
{
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  if ( this->m_iName.m_Value.pszValue == nullptr || (this->m_spawnflags.m_Value & 0x10) != 0 )
  {
    this->m_sequenceStarted = false;
    this->m_bThinking = true;
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CAI_ScriptedSequence::ScriptThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
    if ( this->m_iName.m_Value.pszValue != nullptr )
      this->m_bWaitForBeginSequence = true;
  }
  this->m_interruptable = (this->m_spawnflags.m_Value & 0x20) == 0;
  this->m_sequenceStarted = false;
  this->m_startTime = 0.0;
  this->m_hNextCine.m_Index = -1;
  this->m_hLastFoundEntity.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10409AB0
// Name: CAI_ScriptedSequence_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_ScriptedSequence_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_ScriptedSequence>(__formal: nullptr);
  CAI_ScriptedSequence_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409AE0
// Name: CAI_ScriptedSchedule_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_ScriptedSchedule_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_ScriptedSchedule>(__formal: nullptr);
  CAI_ScriptedSchedule_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409B10
// Name: CAI_ScriptedSentence_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_ScriptedSentence_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_ScriptedSentence>(__formal: nullptr);
  CAI_ScriptedSentence_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020EE50
// Name: class CAI_ScriptedSentence __near * _CreateEntityTemplate<class CAI_ScriptedSentence>(class CAI_ScriptedSentence __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_ScriptedSentence *__cdecl _CreateEntityTemplate<CAI_ScriptedSentence>(
        CAI_ScriptedSentence *newEnt,
        const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x3B0u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CAI_ScriptedSentence::`vftable';
    v3[224] = 0;
    v3[227] = -1;
    v3[228] = 0;
    v3[230] = 0;
    v3[233] = -1;
    v3[234] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CAI_ScriptedSentence *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020FB10
// Name: struct datamap_t __near * DataMapInit<class CAI_ScriptedSchedule>(class CAI_ScriptedSchedule __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_ScriptedSchedule>()
{
  if ( (_S3_111 & 1) == 0 )
  {
    _S3_111 |= 1u;
    nameHolder_372.m_pszBase = "CAI_ScriptedSchedule";
    nameHolder_372.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_372.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_372.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_372.m_Names.m_Size = 0;
    nameHolder_372.m_Names.m_pElements = nullptr;
    nameHolder_372.m_nLenBase = 20;
    atexit(func: DataMapInit_CAI_ScriptedSchedule__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_ScriptedSchedule::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S3_111 & 2) == 0 )
  {
    _S3_111 |= 2u;
    dataDesc_355[11].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_372,
                                   pszIdentifier: "ScriptThink");
    *(_QWORD *)&dataDesc_355[11].td = 0;
    *(_QWORD *)&dataDesc_355[11].override_field = 0;
    *(_QWORD *)&dataDesc_355[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_355[11].flatOffset[1] = 0;
    dataDesc_355[11].fieldSize = 1;
    *(_QWORD *)&dataDesc_355[12].td = 0;
    *(_QWORD *)&dataDesc_355[12].override_field = 0;
    *(_QWORD *)&dataDesc_355[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_355[12].flatOffset[1] = 0;
    dataDesc_355[11].fieldOffset = 0;
    dataDesc_355[11].flags = 32;
    dataDesc_355[11].externalName = nullptr;
    dataDesc_355[11].pSaveRestoreOps = nullptr;
    dataDesc_355[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_ScriptedSchedule::ScriptThink;
    dataDesc_355[12].fieldType = FIELD_VOID;
    dataDesc_355[12].fieldName = "InputStartSchedule";
    dataDesc_355[12].fieldOffset = 0;
    dataDesc_355[12].fieldSize = 1;
    dataDesc_355[12].flags = 8;
    dataDesc_355[12].externalName = "StartSchedule";
    dataDesc_355[12].pSaveRestoreOps = nullptr;
    dataDesc_355[12].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_ScriptedSchedule::InputStartSchedule;
    dataDesc_355[13].fieldType = FIELD_VOID;
    dataDesc_355[13].fieldName = "InputStopSchedule";
    dataDesc_355[13].fieldOffset = 0;
    *(_DWORD *)&dataDesc_355[13].fieldSize = 524289;
    dataDesc_355[13].externalName = "StopSchedule";
    dataDesc_355[13].pSaveRestoreOps = nullptr;
    dataDesc_355[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_ScriptedSchedule::InputStopSchedule;
    *(_QWORD *)&dataDesc_355[13].td = 0;
    *(_QWORD *)&dataDesc_355[13].override_field = 0;
    *(_QWORD *)&dataDesc_355[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_355[13].flatOffset[1] = 0;
  }
  CAI_ScriptedSchedule::m_DataMap.dataNumFields = 13;
  CAI_ScriptedSchedule::m_DataMap.dataDesc = &dataDesc_355[1];
  return &CAI_ScriptedSchedule::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1020FCE0
// Name: struct datamap_t __near * DataMapInit<class CAI_ScriptedSentence>(class CAI_ScriptedSentence __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_ScriptedSentence>()
{
  if ( (_S4_52 & 1) == 0 )
  {
    _S4_52 |= 1u;
    nameHolder_373.m_pszBase = "CAI_ScriptedSentence";
    nameHolder_373.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_373.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_373.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_373.m_Names.m_Size = 0;
    nameHolder_373.m_Names.m_pElements = nullptr;
    nameHolder_373.m_nLenBase = 20;
    atexit(func: DataMapInit_CAI_ScriptedSentence__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_ScriptedSentence::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S4_52 & 2) == 0 )
  {
    _S4_52 |= 2u;
    dataDesc_356[12].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_373,
                                   pszIdentifier: "FindThink");
    dataDesc_356[12].flags = 32;
    dataDesc_356[12].fieldOffset = 0;
    dataDesc_356[12].fieldSize = 1;
    dataDesc_356[12].externalName = nullptr;
    dataDesc_356[12].pSaveRestoreOps = nullptr;
    dataDesc_356[12].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_ScriptedSentence::FindThink;
    *(_QWORD *)&dataDesc_356[12].td = 0;
    *(_QWORD *)&dataDesc_356[12].override_field = 0;
    *(_QWORD *)&dataDesc_356[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_356[12].flatOffset[1] = 0;
    dataDesc_356[13].fieldType = FIELD_VOID;
    dataDesc_356[13].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_373,
                                   pszIdentifier: "DelayThink");
    *(_QWORD *)&dataDesc_356[13].td = 0;
    *(_QWORD *)&dataDesc_356[13].override_field = 0;
    *(_QWORD *)&dataDesc_356[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_356[13].flatOffset[1] = 0;
    dataDesc_356[13].fieldSize = 1;
    dataDesc_356[13].flags = 32;
    *(_QWORD *)&dataDesc_356[14].td = 0;
    *(_QWORD *)&dataDesc_356[14].override_field = 0;
    *(_QWORD *)&dataDesc_356[14].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_356[14].flatOffset[1] = 0;
    dataDesc_356[14].fieldSize = 1;
    dataDesc_356[14].flags = 8;
    dataDesc_356[15].fieldSize = 1;
    *(_QWORD *)&dataDesc_356[15].inputFunc = 0;
    *(_QWORD *)&dataDesc_356[15].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_356[15].override_count = 0;
    *(_QWORD *)dataDesc_356[15].flatOffset = 0;
    dataDesc_356[13].fieldOffset = 0;
    dataDesc_356[13].externalName = nullptr;
    dataDesc_356[13].pSaveRestoreOps = nullptr;
    dataDesc_356[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_ScriptedSentence::DelayThink;
    dataDesc_356[14].fieldType = FIELD_VOID;
    dataDesc_356[14].fieldName = "InputBeginSentence";
    dataDesc_356[14].fieldOffset = 0;
    dataDesc_356[14].externalName = "BeginSentence";
    dataDesc_356[14].pSaveRestoreOps = nullptr;
    dataDesc_356[14].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_ScriptedSentence::InputBeginSentence;
    dataDesc_356[15].fieldType = FIELD_CUSTOM;
    dataDesc_356[15].fieldName = "m_OnBeginSentence";
    dataDesc_356[15].fieldOffset = 896;
    dataDesc_356[15].flags = 22;
    dataDesc_356[15].externalName = "OnBeginSentence";
    dataDesc_356[15].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_356[15].flatGroup = 0;
    dataDesc_356[16].fieldType = FIELD_CUSTOM;
    dataDesc_356[16].fieldName = "m_OnEndSentence";
    dataDesc_356[16].fieldOffset = 920;
    *(_DWORD *)&dataDesc_356[16].fieldSize = 1441793;
    dataDesc_356[16].externalName = "OnEndSentence";
    dataDesc_356[16].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_356[16].inputFunc = 0;
    *(_QWORD *)&dataDesc_356[16].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_356[16].override_count = 0;
    *(_QWORD *)dataDesc_356[16].flatOffset = 0;
    *(_DWORD *)&dataDesc_356[16].flatGroup = 0;
  }
  CAI_ScriptedSentence::m_DataMap.dataNumFields = 16;
  CAI_ScriptedSentence::m_DataMap.dataDesc = &dataDesc_356[1];
  return &CAI_ScriptedSentence::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1020FF90
// Name: struct datamap_t __near * DataMapInit<class CAI_ScriptedSequence>(class CAI_ScriptedSequence __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_ScriptedSequence>()
{
  char *Name; // eax

  if ( (_S2_196 & 1) == 0 )
  {
    _S2_196 |= 1u;
    nameHolder_374.m_pszBase = "CAI_ScriptedSequence";
    nameHolder_374.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_374.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_374.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_374.m_Names.m_Size = 0;
    nameHolder_374.m_Names.m_pElements = nullptr;
    nameHolder_374.m_nLenBase = 20;
    atexit(func: DataMapInit_CAI_ScriptedSequence__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_ScriptedSequence::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_196 & 2) == 0 )
  {
    _S2_196 |= 2u;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_374, pszIdentifier: "ScriptThink");
    *(_QWORD *)&dataDesc_357[37].td = 0;
    *(_QWORD *)&dataDesc_357[37].override_field = 0;
    *(_QWORD *)&dataDesc_357[37].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_357[37].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_357[38].td = 0;
    *(_QWORD *)&dataDesc_357[38].override_field = 0;
    *(_QWORD *)&dataDesc_357[38].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_357[38].flatOffset[1] = 0;
    dataDesc_357[37].fieldName = Name;
    *(_QWORD *)&dataDesc_357[39].td = 0;
    *(_QWORD *)&dataDesc_357[39].override_field = 0;
    *(_QWORD *)&dataDesc_357[39].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_357[39].flatOffset[1] = 0;
    dataDesc_357[37].fieldSize = 1;
    *(_QWORD *)&dataDesc_357[40].td = 0;
    *(_QWORD *)&dataDesc_357[40].override_field = 0;
    *(_QWORD *)&dataDesc_357[40].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_357[40].flatOffset[1] = 0;
    dataDesc_357[37].flags = 32;
    dataDesc_357[38].fieldSize = 1;
    dataDesc_357[38].flags = 8;
    dataDesc_357[39].fieldSize = 1;
    dataDesc_357[39].flags = 8;
    dataDesc_357[40].fieldSize = 1;
    dataDesc_357[41].fieldTolerance = 0.0;
    dataDesc_357[37].fieldOffset = 0;
    dataDesc_357[37].externalName = nullptr;
    dataDesc_357[37].pSaveRestoreOps = nullptr;
    dataDesc_357[37].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_ScriptedSequence::ScriptThink;
    dataDesc_357[38].fieldType = FIELD_VOID;
    dataDesc_357[38].fieldName = "InputMoveToPosition";
    dataDesc_357[38].fieldOffset = 0;
    dataDesc_357[38].externalName = "MoveToPosition";
    dataDesc_357[38].pSaveRestoreOps = nullptr;
    dataDesc_357[38].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_ScriptedSequence::InputMoveToPosition;
    dataDesc_357[39].fieldType = FIELD_VOID;
    dataDesc_357[39].fieldName = "InputBeginSequence";
    dataDesc_357[39].fieldOffset = 0;
    dataDesc_357[39].externalName = "BeginSequence";
    dataDesc_357[39].pSaveRestoreOps = nullptr;
    dataDesc_357[39].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_ScriptedSequence::InputBeginSequence;
    dataDesc_357[40].fieldType = FIELD_VOID;
    dataDesc_357[40].fieldName = "InputCancelSequence";
    dataDesc_357[40].fieldOffset = 0;
    dataDesc_357[40].flags = 8;
    dataDesc_357[40].externalName = "CancelSequence";
    dataDesc_357[40].pSaveRestoreOps = nullptr;
    dataDesc_357[40].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_ScriptedSequence::InputCancelSequence;
    dataDesc_357[41].fieldType = FIELD_INTEGER;
    dataDesc_357[41].fieldName = "m_iPlayerDeathBehavior";
    dataDesc_357[41].fieldOffset = 1336;
    dataDesc_357[41].fieldSize = 1;
    dataDesc_357[41].flags = 6;
    dataDesc_357[41].externalName = "onplayerdeath";
    dataDesc_357[41].pSaveRestoreOps = nullptr;
    dataDesc_357[41].inputFunc = nullptr;
    dataDesc_357[41].td = nullptr;
    dataDesc_357[41].fieldSizeInBytes = 4;
    dataDesc_357[41].override_field = nullptr;
    dataDesc_357[41].override_count = 0;
    *(_QWORD *)dataDesc_357[41].flatOffset = 0;
    dataDesc_357[42].flags = 8;
    dataDesc_357[43].flags = 22;
    dataDesc_357[44].fieldSize = 1;
    dataDesc_357[44].flags = 22;
    *(_QWORD *)&dataDesc_357[42].td = 0;
    *(_QWORD *)&dataDesc_357[42].override_field = 0;
    *(_QWORD *)&dataDesc_357[42].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_357[42].flatOffset[1] = 0;
    dataDesc_357[45].fieldSize = 1;
    *(_QWORD *)&dataDesc_357[43].inputFunc = 0;
    *(_QWORD *)&dataDesc_357[43].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_357[43].override_count = 0;
    *(_QWORD *)dataDesc_357[43].flatOffset = 0;
    dataDesc_357[45].flags = 22;
    *(_QWORD *)&dataDesc_357[44].inputFunc = 0;
    *(_QWORD *)&dataDesc_357[44].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_357[44].override_count = 0;
    *(_QWORD *)dataDesc_357[44].flatOffset = 0;
    dataDesc_357[42].fieldSize = 1;
    dataDesc_357[43].fieldSize = 1;
    dataDesc_357[46].fieldSize = 1;
    *(_QWORD *)&dataDesc_357[45].inputFunc = 0;
    *(_QWORD *)&dataDesc_357[45].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_357[45].override_count = 0;
    *(_QWORD *)dataDesc_357[45].flatOffset = 0;
    *(_DWORD *)&dataDesc_357[41].flatGroup = 0;
    dataDesc_357[42].fieldType = FIELD_VOID;
    dataDesc_357[42].fieldName = "InputScriptPlayerDeath";
    dataDesc_357[42].fieldOffset = 0;
    dataDesc_357[42].externalName = "ScriptPlayerDeath";
    dataDesc_357[42].pSaveRestoreOps = nullptr;
    dataDesc_357[42].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_ScriptedSequence::InputScriptPlayerDeath;
    dataDesc_357[43].fieldType = FIELD_CUSTOM;
    dataDesc_357[43].fieldName = "m_OnBeginSequence";
    dataDesc_357[43].fieldOffset = 956;
    dataDesc_357[43].externalName = "OnBeginSequence";
    dataDesc_357[43].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_357[43].flatGroup = 0;
    dataDesc_357[44].fieldType = FIELD_CUSTOM;
    dataDesc_357[44].fieldName = "m_OnEndSequence";
    dataDesc_357[44].fieldOffset = 980;
    dataDesc_357[44].externalName = "OnEndSequence";
    dataDesc_357[44].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_357[44].flatGroup = 0;
    dataDesc_357[45].fieldType = FIELD_CUSTOM;
    dataDesc_357[45].fieldName = "m_OnPostIdleEndSequence";
    dataDesc_357[45].fieldOffset = 1004;
    dataDesc_357[45].externalName = "OnPostIdleEndSequence";
    dataDesc_357[45].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_357[45].flatGroup = 0;
    dataDesc_357[46].fieldType = FIELD_CUSTOM;
    dataDesc_357[46].fieldName = "m_OnCancelSequence";
    dataDesc_357[46].fieldOffset = 1028;
    dataDesc_357[46].flags = 22;
    dataDesc_357[46].externalName = "OnCancelSequence";
    dataDesc_357[46].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_357[46].inputFunc = 0;
    *(_QWORD *)&dataDesc_357[46].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_357[46].override_count = 0;
    *(_QWORD *)dataDesc_357[46].flatOffset = 0;
    *(_DWORD *)&dataDesc_357[46].flatGroup = 0;
    dataDesc_357[47].fieldType = FIELD_CUSTOM;
    dataDesc_357[47].fieldName = "m_OnCancelFailedSequence";
    dataDesc_357[47].fieldOffset = 1052;
    dataDesc_357[47].fieldSize = 1;
    dataDesc_357[47].flags = 22;
    dataDesc_357[48].fieldSize = 1;
    dataDesc_357[48].flags = 22;
    dataDesc_357[49].fieldSize = 1;
    dataDesc_357[49].flags = 22;
    dataDesc_357[50].fieldSize = 1;
    dataDesc_357[50].flags = 22;
    *(_QWORD *)&dataDesc_357[47].inputFunc = 0;
    *(_QWORD *)&dataDesc_357[47].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_357[47].override_count = 0;
    *(_QWORD *)dataDesc_357[47].flatOffset = 0;
    dataDesc_357[51].fieldSize = 1;
    *(_QWORD *)&dataDesc_357[48].inputFunc = 0;
    *(_QWORD *)&dataDesc_357[48].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_357[48].override_count = 0;
    *(_QWORD *)dataDesc_357[48].flatOffset = 0;
    dataDesc_357[51].flags = 22;
    *(_QWORD *)&dataDesc_357[49].inputFunc = 0;
    *(_QWORD *)&dataDesc_357[49].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_357[49].override_count = 0;
    *(_QWORD *)dataDesc_357[49].flatOffset = 0;
    dataDesc_357[52].fieldSize = 1;
    *(_QWORD *)&dataDesc_357[50].inputFunc = 0;
    *(_QWORD *)&dataDesc_357[50].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_357[50].override_count = 0;
    *(_QWORD *)dataDesc_357[50].flatOffset = 0;
    dataDesc_357[47].externalName = "OnCancelFailedSequence";
    dataDesc_357[47].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_357[47].flatGroup = 0;
    dataDesc_357[48].fieldType = FIELD_CUSTOM;
    dataDesc_357[48].fieldName = "m_OnScriptEvent[0]";
    dataDesc_357[48].fieldOffset = 1076;
    dataDesc_357[48].externalName = "OnScriptEvent01";
    dataDesc_357[48].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_357[48].flatGroup = 0;
    dataDesc_357[49].fieldType = FIELD_CUSTOM;
    dataDesc_357[49].fieldName = "m_OnScriptEvent[1]";
    dataDesc_357[49].fieldOffset = 1100;
    dataDesc_357[49].externalName = "OnScriptEvent02";
    dataDesc_357[49].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_357[49].flatGroup = 0;
    dataDesc_357[50].fieldType = FIELD_CUSTOM;
    dataDesc_357[50].fieldName = "m_OnScriptEvent[2]";
    dataDesc_357[50].fieldOffset = 1124;
    dataDesc_357[50].externalName = "OnScriptEvent03";
    dataDesc_357[50].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_357[50].flatGroup = 0;
    dataDesc_357[51].fieldType = FIELD_CUSTOM;
    dataDesc_357[51].fieldName = "m_OnScriptEvent[3]";
    dataDesc_357[51].fieldOffset = 1148;
    dataDesc_357[51].externalName = "OnScriptEvent04";
    dataDesc_357[51].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_357[51].inputFunc = 0;
    *(_QWORD *)&dataDesc_357[51].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_357[51].override_count = 0;
    *(_QWORD *)dataDesc_357[51].flatOffset = 0;
    *(_DWORD *)&dataDesc_357[51].flatGroup = 0;
    dataDesc_357[52].fieldType = FIELD_CUSTOM;
    dataDesc_357[52].fieldName = "m_OnScriptEvent[4]";
    dataDesc_357[52].fieldOffset = 1172;
    dataDesc_357[52].flags = 22;
    dataDesc_357[52].externalName = "OnScriptEvent05";
    dataDesc_357[52].pSaveRestoreOps = eventFuncs;
    dataDesc_357[53].fieldSize = 1;
    *(_QWORD *)&dataDesc_357[52].inputFunc = 0;
    *(_QWORD *)&dataDesc_357[52].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_357[52].override_count = 0;
    *(_QWORD *)dataDesc_357[52].flatOffset = 0;
    dataDesc_357[53].flags = 22;
    *(_QWORD *)&dataDesc_357[53].inputFunc = 0;
    *(_QWORD *)&dataDesc_357[53].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_357[53].override_count = 0;
    *(_QWORD *)dataDesc_357[53].flatOffset = 0;
    dataDesc_357[54].fieldSize = 1;
    *(_QWORD *)&dataDesc_357[54].inputFunc = 0;
    *(_QWORD *)&dataDesc_357[54].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_357[54].override_count = 0;
    *(_QWORD *)dataDesc_357[54].flatOffset = 0;
    *(_DWORD *)&dataDesc_357[52].flatGroup = 0;
    dataDesc_357[53].fieldType = FIELD_CUSTOM;
    dataDesc_357[53].fieldName = "m_OnScriptEvent[5]";
    dataDesc_357[53].fieldOffset = 1196;
    dataDesc_357[53].externalName = "OnScriptEvent06";
    dataDesc_357[53].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_357[53].flatGroup = 0;
    dataDesc_357[54].fieldType = FIELD_CUSTOM;
    dataDesc_357[54].fieldName = "m_OnScriptEvent[6]";
    dataDesc_357[54].fieldOffset = 1220;
    dataDesc_357[54].flags = 22;
    dataDesc_357[54].externalName = "OnScriptEvent07";
    dataDesc_357[54].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_357[54].flatGroup = 0;
    dataDesc_357[55].fieldType = FIELD_CUSTOM;
    dataDesc_357[55].fieldName = "m_OnScriptEvent[7]";
    dataDesc_357[55].fieldOffset = 1244;
    *(_DWORD *)&dataDesc_357[55].fieldSize = 1441793;
    dataDesc_357[55].externalName = "OnScriptEvent08";
    dataDesc_357[55].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_357[55].inputFunc = 0;
    *(_QWORD *)&dataDesc_357[55].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_357[55].override_count = 0;
    *(_QWORD *)dataDesc_357[55].flatOffset = 0;
    *(_DWORD *)&dataDesc_357[55].flatGroup = 0;
  }
  CAI_ScriptedSequence::m_DataMap.dataNumFields = 55;
  CAI_ScriptedSequence::m_DataMap.dataDesc = &dataDesc_357[1];
  return &CAI_ScriptedSequence::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10409AF0
// Name: _dynamic_initializer_for__aiscripted_schedule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__aiscripted_schedule__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAI_ScriptedSchedule> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &aiscripted_schedule,
           a3: "aiscripted_schedule");
}
