// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/doors.cpp
// Functions: 52
// ============================================================

#include "game\server\doors.h"

//------------------------------------------------------------------------------
// Address: 0x100FEE10
// Name: public: virtual struct datamap_t __near * CBaseDoor::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseDoor::GetDataDescMap(CBaseDoor *this)
{
  return &CBaseDoor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100FEE20
// Name: public: virtual class ServerClass __near * CBaseDoor::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBaseDoor::GetServerClass(CBaseDoor *this)
{
  return &g_CBaseDoor_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x100FEE30
// Name: public: virtual void CBaseDoor::SetToggleState(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::SetToggleState(CBaseDoor *this, int state)
{
  if ( state != 0 )
    UTIL_SetOrigin(entity: this, vecOrigin: &this->m_vecPosition1, bFireTriggers: false);
  else
    UTIL_SetOrigin(entity: this, vecOrigin: &this->m_vecPosition2, bFireTriggers: false);
}

//------------------------------------------------------------------------------
// Address: 0x100FEE70
// Name: public: virtual void CBaseDoor::StartBlocked(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::StartBlocked(CBaseDoor *this, CBaseEntity *pOther)
{
  if ( this->m_toggle_state == TS_GOING_DOWN )
    COutputEvent::FireOutput(this: &this->m_OnBlockedClosing, pActivator: pOther, pCaller: this, fDelay: 0.0);
  else
    COutputEvent::FireOutput(this: &this->m_OnBlockedOpening, pActivator: pOther, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100FEEB0
// Name: public: virtual void CBaseDoor::EndBlocked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::EndBlocked(CBaseDoor *this)
{
  if ( this->m_toggle_state == TS_GOING_DOWN )
    COutputEvent::FireOutput(this: &this->m_OnUnblockedClosing, pActivator: this, pCaller: this, fDelay: 0.0);
  else
    COutputEvent::FireOutput(this: &this->m_OnUnblockedOpening, pActivator: this, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100FEEE0
// Name: public: virtual struct datamap_t __near * CRotDoor::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CRotDoor::GetDataDescMap(CRotDoor *this)
{
  return &CRotDoor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100FEEF0
// Name: public: virtual void CRotDoor::SetToggleState(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRotDoor::SetToggleState(CRotDoor *this, int state)
{
  if ( state != 0 )
    CBaseEntity::SetLocalAngles(this, angles: &this->m_vecAngle1);
  else
    CBaseEntity::SetLocalAngles(this, angles: &this->m_vecAngle2);
}

//------------------------------------------------------------------------------
// Address: 0x100FEF20
// Name: public: virtual bool CBaseDoor::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseDoor::KeyValue(CBaseDoor *this, char *szKeyName, const char *szValue)
{
  long double v4; // st7

  if ( szKeyName != "locked_sentence" && _V_stricmp(s1: szKeyName, s2: "locked_sentence") != 0 )
  {
    if ( szKeyName != "unlocked_sentence" && _V_stricmp(s1: szKeyName, s2: "unlocked_sentence") != 0 )
    {
      return CBaseToggle::KeyValue(this, szKeyName, szValue);
    }
    else
    {
      this->m_bUnlockedSentence = (int)atof(nptr: szValue);
      return true;
    }
  }
  else
  {
    v4 = atof(nptr: szValue);
    this->m_bLockedSentence = (int)v4;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FEFE0
// Name: public: virtual void CBaseDoor::StopMovingSound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::StopMovingSound(CBaseDoor *this)
{
  const char *pszValue; // ecx
  TOGGLE_STATE m_toggle_state; // eax
  edict_t *m_pPev; // eax

  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: gpGlobals->curtime, szContext: "MovingSound");
  pszValue = this->m_NoiseMovingClosed.pszValue;
  if ( pszValue == nullptr || (m_toggle_state = this->m_toggle_state) == TS_GOING_UP || m_toggle_state == TS_AT_TOP )
  {
    pszValue = this->m_NoiseMoving.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
  }
  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    CBaseEntity::StopSound(
      iEntIndex: m_pPev - gpGlobals->pEdicts,
      iChannel: 6,
      pSample: pszValue,
      bIsStoppingSpeakerSound: 0);
  else
    CBaseEntity::StopSound(iEntIndex: 0, iChannel: 6, pSample: pszValue, bIsStoppingSpeakerSound: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100FF060
// Name: public: virtual bool CBaseDoor::ShouldSavePhysics(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseDoor::ShouldSavePhysics(CBaseDoor *this)
{
  return this == nullptr
      || this->m_iClassname.pszValue != "func_water"
      && CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "func_water") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100FF0A0
// Name: public: void CBaseDoor::InputSetToggleState(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::InputSetToggleState(CBaseDoor *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_INTEGER )
    this->SetToggleState(this, a2: inputdata->value.iVal);
  else
    this->SetToggleState(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100FF0D0
// Name: public: virtual void CBaseDoor::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::Precache(CBaseDoor *this)
{
  string_t *p_m_NoiseMoving; // edi
  string_t *p_m_NoiseArrived; // ebx
  const char *v4; // eax
  const char *v5; // ebx
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  char *p_pszValue; // eax
  char *v11; // edx
  char *v12; // ecx
  char *v13; // eax
  char *v14; // edx
  char *v15; // ecx
  char v16; // [esp+Ch] [ebp-24h] BYREF
  char v17; // [esp+10h] [ebp-20h] BYREF
  char v18; // [esp+14h] [ebp-1Ch] BYREF
  char v19; // [esp+18h] [ebp-18h] BYREF
  char v20; // [esp+1Ch] [ebp-14h] BYREF
  char v21; // [esp+20h] [ebp-10h] BYREF
  char v22; // [esp+24h] [ebp-Ch] BYREF
  char v23; // [esp+28h] [ebp-8h] BYREF
  char pszValue; // [esp+2Ch] [ebp-4h] BYREF

  p_m_NoiseMoving = &this->m_NoiseMoving;
  if ( this->IsRotatingDoor(this) )
  {
    UTIL_ValidateSoundName(name: &this->m_NoiseMoving, defaultStr: "RotDoorSound.DefaultMove");
    p_m_NoiseArrived = &this->m_NoiseArrived;
    UTIL_ValidateSoundName(name: &this->m_NoiseArrived, defaultStr: "RotDoorSound.DefaultArrive");
    UTIL_ValidateSoundName(name: &this->m_ls.sLockedSound, defaultStr: "RotDoorSound.DefaultLocked");
  }
  else
  {
    UTIL_ValidateSoundName(name: &this->m_NoiseMoving, defaultStr: "DoorSound.DefaultMove");
    p_m_NoiseArrived = &this->m_NoiseArrived;
    UTIL_ValidateSoundName(name: &this->m_NoiseArrived, defaultStr: "DoorSound.DefaultArrive");
    UTIL_ValidateSoundName(name: &this->m_ls.sLockedSound, defaultStr: "DoorSound.DefaultLocked");
  }
  UTIL_ValidateSoundName(name: &this->m_ls.sUnlockedSound, defaultStr: "DoorSound.Null");
  v4 = p_m_NoiseMoving->pszValue;
  if ( p_m_NoiseMoving->pszValue == nullptr )
    v4 = locale;
  CBaseEntity::PrecacheScriptSound(soundname: v4);
  v5 = p_m_NoiseArrived->pszValue;
  if ( v5 == nullptr )
    v5 = locale;
  CBaseEntity::PrecacheScriptSound(soundname: v5);
  v6 = this->m_NoiseMovingClosed.pszValue;
  if ( v6 == nullptr )
    v6 = locale;
  CBaseEntity::PrecacheScriptSound(soundname: v6);
  v7 = this->m_NoiseArrivedClosed.pszValue;
  if ( v7 == nullptr )
    v7 = locale;
  CBaseEntity::PrecacheScriptSound(soundname: v7);
  v8 = this->m_ls.sLockedSound.pszValue;
  if ( v8 == nullptr )
    v8 = locale;
  CBaseEntity::PrecacheScriptSound(soundname: v8);
  v9 = this->m_ls.sUnlockedSound.pszValue;
  if ( v9 == nullptr )
    v9 = locale;
  CBaseEntity::PrecacheScriptSound(soundname: v9);
  switch ( this->m_bLockedSentence )
  {
    case 1u:
      p_pszValue = &pszValue;
      goto LABEL_18;
    case 2u:
      v11 = &v23;
      goto LABEL_20;
    case 3u:
      v12 = &v22;
      goto LABEL_22;
    case 4u:
      p_pszValue = &v21;
      goto LABEL_18;
    case 5u:
      v11 = &v20;
      goto LABEL_20;
    case 6u:
      v12 = &v19;
      goto LABEL_22;
    case 7u:
      p_pszValue = &v18;
LABEL_18:
      this->m_ls.sLockedSentence.pszValue = *(const char **)AllocPooledString(pszValue: p_pszValue).pszValue;
      break;
    case 8u:
      v11 = &v17;
LABEL_20:
      this->m_ls.sLockedSentence.pszValue = *(const char **)AllocPooledString(pszValue: v11).pszValue;
      break;
    case 9u:
      v12 = &v16;
LABEL_22:
      this->m_ls.sLockedSentence.pszValue = *(const char **)AllocPooledString(pszValue: v12).pszValue;
      break;
    default:
      this->m_ls.sLockedSentence.pszValue = nullptr;
      break;
  }
  switch ( this->m_bUnlockedSentence )
  {
    case 1u:
      v13 = &v16;
      goto LABEL_32;
    case 2u:
      v14 = &v17;
      goto LABEL_34;
    case 3u:
      v15 = &v18;
      goto LABEL_36;
    case 4u:
      v13 = &v19;
      goto LABEL_32;
    case 5u:
      v14 = &v20;
      goto LABEL_34;
    case 6u:
      v15 = &v21;
LABEL_36:
      this->m_ls.sUnlockedSentence.pszValue = *(const char **)AllocPooledString(pszValue: v15).pszValue;
      break;
    case 7u:
      v13 = &v22;
LABEL_32:
      this->m_ls.sUnlockedSentence.pszValue = *(const char **)AllocPooledString(pszValue: v13).pszValue;
      break;
    case 8u:
      v14 = &v23;
LABEL_34:
      this->m_ls.sUnlockedSentence.pszValue = *(const char **)AllocPooledString(pszValue: v14).pszValue;
      break;
    default:
      this->m_ls.sUnlockedSentence.pszValue = nullptr;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF390
// Name: private: void CBaseDoor::ChainUse(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::ChainUse(CBaseDoor *this)
{
  CBaseEntity *v2; // edi
  const char *pszValue; // eax
  CBaseDoor *EntityByName; // eax
  _BYTE *v5; // eax
  _BYTE *v6; // esi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx

  if ( !this->m_isChaining )
  {
    v2 = nullptr;
    while ( 1 )
    {
      pszValue = this->m_ChainTarget.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      EntityByName = (CBaseDoor *)CGlobalEntityList::FindEntityByName(
                                    this: &gEntList,
                                    pStartEntity: v2,
                                    szName: pszValue,
                                    pSearchingEntity: nullptr,
                                    pActivator: nullptr,
                                    pCaller: nullptr,
                                    pFilter: nullptr);
      v2 = EntityByName;
      if ( EntityByName == nullptr )
        break;
      if ( EntityByName != this )
      {
        v5 = __RTDynamicCast(
               inptr: EntityByName,
               VfDelta: 0,
               SrcType: &CBaseEntity `RTTI Type Descriptor',
               TargetType: &CBaseDoor `RTTI Type Descriptor',
               isReference: 0);
        v6 = v5;
        if ( v5 != nullptr )
        {
          v5[1281] = 1;
          m_Index = this->m_hActivator.m_Index;
          if ( m_Index == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
          {
            m_pEntity = nullptr;
          }
          else
          {
            m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
          }
          (*(void (__thiscall **)(_BYTE *, IHandleEntity *, _DWORD, int, _DWORD))(*(_DWORD *)v6 + 396))(
            a1: v6,
            a2: m_pEntity,
            a3: 0,
            a4: 3,
            a5: 0);
          v6[1281] = 0;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF450
// Name: private: void CBaseDoor::ChainTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::ChainTouch(CBaseDoor *this, CBaseEntity *pOther)
{
  CBaseDoor *v2; // esi
  CBaseEntity *v3; // edi
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  _BYTE *v6; // esi
  void (__thiscall *v7)(_BYTE *, CBaseEntity *); // edx

  v2 = this;
  if ( !this->m_isChaining )
  {
    v3 = nullptr;
    while ( 1 )
    {
      pszValue = v2->m_ChainTarget.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: v3,
                       szName: pszValue,
                       pSearchingEntity: nullptr,
                       pActivator: nullptr,
                       pCaller: nullptr,
                       pFilter: nullptr);
      v3 = EntityByName;
      if ( EntityByName == nullptr )
        break;
      if ( EntityByName != v2 )
      {
        v6 = __RTDynamicCast(
               inptr: EntityByName,
               VfDelta: 0,
               SrcType: &CBaseEntity `RTTI Type Descriptor',
               TargetType: &CBaseDoor `RTTI Type Descriptor',
               isReference: 0);
        if ( v6 != nullptr )
        {
          v7 = *(void (__thiscall **)(_BYTE *, CBaseEntity *))(*(_DWORD *)v6 + 404);
          v6[1281] = 1;
          v7(a1: v6, a2: pOther);
          v6[1281] = 0;
        }
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF4F0
// Name: public: void CBaseDoor::InputLock(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::InputLock(CBaseDoor *this, inputdata_t *inputdata)
{
  this->m_bLocked = true;
}

//------------------------------------------------------------------------------
// Address: 0x100FF500
// Name: public: void CBaseDoor::InputUnlock(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::InputUnlock(CBaseDoor *this, inputdata_t *inputdata)
{
  this->m_bLocked = false;
}

//------------------------------------------------------------------------------
// Address: 0x100FF510
// Name: public: void CBaseDoor::InputSetSpeed(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::InputSetSpeed(CBaseDoor *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    LODWORD(this->m_flSpeed) = inputdata->value.iVal;
  else
    this->m_flSpeed = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100FF550
// Name: public: virtual CBaseDoor::~CBaseDoor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::~CBaseDoor(CBaseDoor *this)
{
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnLockedUse);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnOpen);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnClose);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnFullyOpen);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnFullyClosed);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnUnblockedOpening);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnUnblockedClosing);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnBlockedOpening);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnBlockedClosing);
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x100FF680
// Name: public: void CBaseDoor::UpdateAreaPortals(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::UpdateAreaPortals(CBaseDoor *this, bool isOpen)
{
  bool v3; // bl
  CBaseEntity *i; // esi
  const char *name; // [esp+1Ch] [ebp+8h]

  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: gpGlobals->curtime, szContext: "CloseAreaportalThink");
  if ( this->IsRotatingDoor(this) && (this->m_spawnflags.m_Value & 1) != 0 )
    v3 = !isOpen;
  else
    v3 = isOpen;
  name = this->m_iName.m_Value.pszValue;
  if ( name != nullptr )
  {
    for ( i = CGlobalEntityList::FindEntityByClassname(
                this: &gEntList,
                pStartEntity: nullptr,
                szName: "func_areaportal");
          i != nullptr;
          i = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: i, szName: "func_areaportal") )
    {
      if ( ((unsigned __int8 (__thiscall *)(CBaseEntity *, const char *))i->HasTarget)(a1: i, a2: name) != 0 )
        ((void (__thiscall *)(CBaseEntity *, CBaseDoor *, CBaseDoor *, bool, _DWORD))i->Use)(
          a1: i,
          a2: this,
          a3: this,
          a4: v3,
          a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF740
// Name: public: int CBaseDoor::GetDoorMovementGroup(class CBaseDoor __near * __near * const,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseDoor::GetDoorMovementGroup(CBaseDoor *this, CBaseDoor **pDoorList, int listMax)
{
  int v4; // ebx
  CBaseEntity *v5; // esi
  const char *pszValue; // eax
  CBaseDoor *EntityByName; // eax
  CBaseDoor *v8; // eax

  v4 = 0;
  v5 = nullptr;
  if ( this->m_iName.m_Value.pszValue != nullptr )
  {
    while ( 1 )
    {
      do
      {
        pszValue = this->m_iName.m_Value.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        EntityByName = (CBaseDoor *)CGlobalEntityList::FindEntityByName(
                                      this: &gEntList,
                                      pStartEntity: v5,
                                      szName: pszValue,
                                      pSearchingEntity: nullptr,
                                      pActivator: nullptr,
                                      pCaller: nullptr,
                                      pFilter: nullptr);
        v5 = EntityByName;
      }
      while ( EntityByName == this );
      if ( EntityByName == nullptr )
        break;
      v8 = (CBaseDoor *)__RTDynamicCast(
                          inptr: EntityByName,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CBaseDoor `RTTI Type Descriptor',
                          isReference: 0);
      if ( v8 != nullptr && v4 < listMax )
        pDoorList[v4++] = v8;
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100FF7C0
// Name: public: virtual bool CRotDoor::CreateVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRotDoor::CreateVPhysics(CFuncRotating *this)
{
  if ( (this->m_Collision.m_usSolidFlags.m_Value & 4) == 0 )
    CBaseEntity::VPhysicsInitShadow(this, allowPhysicsMovement: 0, allowPhysicsRotation: 0, pSolid: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FF7E0
// Name: public: virtual void CBaseDoor::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::Activate(CBaseDoor *this)
{
  int v2; // ebx
  CBaseDoor *v3; // esi
  char v4; // al
  TOGGLE_STATE m_toggle_state; // eax
  CBaseDoor *pDoorList[64]; // [esp+8h] [ebp-104h] BYREF
  int doorCount; // [esp+108h] [ebp-4h]

  CBaseEntity::Activate(this);
  this->m_bDoorGroup = true;
  v2 = 0;
  doorCount = CBaseDoor::GetDoorMovementGroup(this, pDoorList, listMax: 64);
  if ( doorCount > 0 )
  {
    while ( 1 )
    {
      v3 = pDoorList[v2];
      if ( this->m_vecMoveDir.x == v3->m_vecMoveDir.x
        && this->m_vecMoveDir.y == v3->m_vecMoveDir.y
        && this->m_vecMoveDir.z == v3->m_vecMoveDir.z )
      {
        break;
      }
LABEL_17:
      if ( ++v2 >= doorCount )
        goto LABEL_18;
    }
    if ( v3->IsRotatingDoor(this: pDoorList[v2]) )
    {
      if ( this->m_angRotation.m_Value.x == v3->m_angRotation.m_Value.x
        && this->m_angRotation.m_Value.y == v3->m_angRotation.m_Value.y
        && this->m_angRotation.m_Value.z == v3->m_angRotation.m_Value.z )
      {
        v4 = 0;
        goto LABEL_15;
      }
    }
    else if ( this->m_vecOrigin.m_Value.x == v3->m_vecOrigin.m_Value.x
           && this->m_vecOrigin.m_Value.y == v3->m_vecOrigin.m_Value.y
           && this->m_vecOrigin.m_Value.z == v3->m_vecOrigin.m_Value.z )
    {
      v4 = 0;
      goto LABEL_15;
    }
    v4 = 1;
LABEL_15:
    if ( v4 != 0 )
      this->m_bDoorGroup = false;
    goto LABEL_17;
  }
LABEL_18:
  m_toggle_state = this->m_toggle_state;
  if ( m_toggle_state != TS_AT_TOP )
  {
    if ( m_toggle_state == TS_AT_BOTTOM )
      CBaseDoor::UpdateAreaPortals(this, isOpen: false);
  }
  else
  {
    CBaseDoor::UpdateAreaPortals(this, isOpen: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF960
// Name: private: void CBaseDoor::CloseAreaPortalsThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::CloseAreaPortalsThink(CBaseDoor *this)
{
  CBaseDoor::UpdateAreaPortals(this, isOpen: false);
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: gpGlobals->curtime, szContext: "CloseAreaportalThink");
}

//------------------------------------------------------------------------------
// Address: 0x100FF990
// Name: public: CBaseDoor::CBaseDoor(void)
// Source: json
//------------------------------------------------------------------------------
CBaseDoor *__thiscall CBaseDoor::CBaseDoor(CBaseDoor *this)
{
  CBaseToggle::CBaseToggle(this);
  this->__vftable = (CBaseDoor_vtbl *)&CBaseDoor::`vftable';
  this->m_ls.__vftable = (locksound_t_vtbl *)&locksound_t::`vftable';
  this->m_OnBlockedClosing.m_Value.iVal = 0;
  this->m_OnBlockedClosing.m_Value.eVal.m_Index = -1;
  this->m_OnBlockedClosing.m_Value.fieldType = FIELD_VOID;
  this->m_OnBlockedOpening.m_Value.iVal = 0;
  this->m_OnBlockedOpening.m_Value.eVal.m_Index = -1;
  this->m_OnBlockedOpening.m_Value.fieldType = FIELD_VOID;
  this->m_OnUnblockedClosing.m_Value.iVal = 0;
  this->m_OnUnblockedClosing.m_Value.eVal.m_Index = -1;
  this->m_OnUnblockedClosing.m_Value.fieldType = FIELD_VOID;
  this->m_OnUnblockedOpening.m_Value.iVal = 0;
  this->m_OnUnblockedOpening.m_Value.eVal.m_Index = -1;
  this->m_OnUnblockedOpening.m_Value.fieldType = FIELD_VOID;
  this->m_OnFullyClosed.m_Value.iVal = 0;
  this->m_OnFullyClosed.m_Value.eVal.m_Index = -1;
  this->m_OnFullyClosed.m_Value.fieldType = FIELD_VOID;
  this->m_OnFullyOpen.m_Value.iVal = 0;
  this->m_OnFullyOpen.m_Value.eVal.m_Index = -1;
  this->m_OnFullyOpen.m_Value.fieldType = FIELD_VOID;
  this->m_OnClose.m_Value.iVal = 0;
  this->m_OnClose.m_Value.eVal.m_Index = -1;
  this->m_OnClose.m_Value.fieldType = FIELD_VOID;
  this->m_OnOpen.m_Value.iVal = 0;
  this->m_OnOpen.m_Value.eVal.m_Index = -1;
  this->m_OnOpen.m_Value.fieldType = FIELD_VOID;
  this->m_OnLockedUse.m_Value.iVal = 0;
  this->m_OnLockedUse.m_Value.eVal.m_Index = -1;
  this->m_OnLockedUse.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FFA60
// Name: public: virtual int CBaseDoor::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseDoor::ObjectCaps(CBaseDoor *this)
{
  int result; // eax

  result = CBaseEntity::ObjectCaps(this);
  if ( (this->m_spawnflags.m_Value & 0x100) != 0 )
    return result | 0x21;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FFAB0
// Name: public: virtual bool CBaseDoor::CreateVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseDoor::CreateVPhysics(CBaseDoor *this)
{
  int v3; // ebx
  edict_t *m_pPev; // ecx
  IPhysicsObject *inited; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v6; // edx
  IPhysicsObject *v7; // ebx
  const Vector *(__thiscall *OBBMaxs)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  int v9; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v10; // edx
  fluidparams_t fluid; // [esp+4h] [ebp-38h] BYREF
  int v12; // [esp+38h] [ebp-4h]

  if ( this != nullptr
    && (this->m_iClassname.pszValue == "func_water"
     || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "func_water") != 0) )
  {
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x20);
    v3 = this->m_spawnflags.m_Value | 0x1000;
    if ( this->m_spawnflags.m_Value != v3 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
      }
      this->m_spawnflags.m_Value = v3;
    }
    inited = CBaseEntity::VPhysicsInitShadow(this, allowPhysicsMovement: 0, allowPhysicsRotation: 0, pSolid: nullptr);
    v6 = this->m_Collision.CBaseToggle::CBaseEntity::__vftable;
    fluid.damping = 0.0099999998;
    v7 = inited;
    OBBMaxs = v6->OBBMaxs;
    fluid.surfacePlane.x = 0.0;
    fluid.surfacePlane.y = 0.0;
    fluid.surfacePlane.z = 1.0;
    v9 = (int)OBBMaxs(this: &this->m_Collision);
    v10 = this->m_Collision.CBaseToggle::CBaseEntity::__vftable;
    v12 = v9 + 8;
    fluid.surfacePlane.w = (float)(v10->GetCollisionOrigin(this: &this->m_Collision)->z + *(float *)(v9 + 8)) - 1.0;
    memset((void *)&fluid.currentVelocity, 0, sizeof(fluid.currentVelocity));
    fluid.torqueFactor = 0.1;
    fluid.viscosityFactor = 0.0099999998;
    fluid.pGameData = this;
    fluid.contents = 32;
    physenv->CreateFluidController(this: physenv, a2: v7, a3: &fluid);
    return 1;
  }
  else
  {
    CBaseEntity::VPhysicsInitShadow(this, allowPhysicsMovement: 0, allowPhysicsRotation: 0, pSolid: nullptr);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FFC90
// Name: void PlayLockSounds(class CBaseEntity __near *,struct locksound_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PlayLockSounds(CBaseEntity *pEdict, locksound_t *pls, int flocked, int fbutton)
{
  CBaseEntity *v4; // edx
  double v5; // xmm0_8
  BOOL v6; // eax
  BOOL v7; // edi
  float v8; // xmm0_4
  const char *pszValue; // eax
  edict_t *m_pPev; // eax
  const char *v11; // ecx
  int iLockedSentence; // edi
  int v13; // eax
  BOOL v14; // eax
  BOOL v15; // edi
  float v16; // xmm0_4
  const char *v17; // eax
  edict_t *v18; // eax
  const char *v19; // ecx
  int iUnlockedSentence; // edi
  int v21; // eax
  EmitSound_t ep; // [esp+20h] [ebp-70h] BYREF
  CPASAttenuationFilter filter; // [esp+68h] [ebp-28h] BYREF
  float flsoundwait; // [esp+88h] [ebp-8h]
  float fvol; // [esp+8Ch] [ebp-4h]

  v4 = pEdict;
  if ( (pEdict->m_spawnflags.m_Value & 0x1000) == 0 )
  {
    if ( fbutton != 0 )
      v5 = 0.5;
    else
      v5 = 1.0;
    flsoundwait = v5;
    if ( flocked != 0 )
    {
      v6 = pls->sLockedSound.pszValue != nullptr && gpGlobals->curtime > pls->flwaitSound;
      v7 = pls->sLockedSentence.pszValue != nullptr && pls->bEOFLocked == 0 && gpGlobals->curtime > pls->flwaitSentence;
      if ( v6 && v7 )
        v8 = 0.25;
      else
        v8 = 1.0;
      fvol = v8;
      if ( v6 )
      {
        CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: pEdict, attenuation: 0.80000001);
        EmitSound_t::EmitSound_t(this: &ep);
        pszValue = pls->sLockedSound.pszValue;
        ep.m_nChannel = 3;
        ep.m_pSoundName = pszValue;
        if ( pszValue == nullptr )
          ep.m_pSoundName = locale;
        m_pPev = pEdict->m_Network.m_pPev;
        ep.m_flVolume = fvol;
        ep.m_SoundLevel = SNDLVL_NORM;
        if ( m_pPev != nullptr )
          m_pPev -= (int)gpGlobals->pEdicts;
        CBaseEntity::EmitSound(&filter, iEntIndex: (int)m_pPev, params: &ep);
        pls->flwaitSound = gpGlobals->curtime + flsoundwait;
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
        CRecipientFilter::~CRecipientFilter(this: &filter);
        v4 = pEdict;
      }
      if ( v7 )
      {
        v11 = pls->sLockedSentence.pszValue;
        iLockedSentence = pls->iLockedSentence;
        if ( v11 == nullptr )
          v11 = locale;
        v13 = SENTENCEG_PlaySequentialSz(
                entity: v4->m_Network.m_pPev,
                szgroupname: v11,
                volume: 0.85000002,
                soundlevel: SNDLVL_NORM,
                flags: 0,
                pitch: 100,
                ipick: iLockedSentence,
                freset: 0);
        pls->iLockedSentence = v13;
        pls->iUnlockedSentence = 0;
        pls->bEOFLocked = iLockedSentence == v13;
        pls->flwaitSentence = gpGlobals->curtime + 6.0;
      }
    }
    else
    {
      v14 = pls->sUnlockedSound.pszValue != nullptr && gpGlobals->curtime > pls->flwaitSound;
      v15 = pls->sUnlockedSentence.pszValue != nullptr
         && pls->bEOFUnlocked == 0
         && gpGlobals->curtime > pls->flwaitSentence;
      if ( v14 && v15 )
        v16 = 0.25;
      else
        v16 = 1.0;
      fvol = v16;
      if ( v14 )
      {
        CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: pEdict, attenuation: 0.80000001);
        EmitSound_t::EmitSound_t(this: &ep);
        v17 = pls->sUnlockedSound.pszValue;
        ep.m_nChannel = 3;
        ep.m_pSoundName = v17;
        if ( v17 == nullptr )
          ep.m_pSoundName = locale;
        v18 = pEdict->m_Network.m_pPev;
        ep.m_flVolume = fvol;
        ep.m_SoundLevel = SNDLVL_NORM;
        if ( v18 != nullptr )
          v18 -= (int)gpGlobals->pEdicts;
        CBaseEntity::EmitSound(&filter, iEntIndex: (int)v18, params: &ep);
        pls->flwaitSound = gpGlobals->curtime + flsoundwait;
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
        CRecipientFilter::~CRecipientFilter(this: &filter);
        v4 = pEdict;
      }
      if ( v15 )
      {
        v19 = pls->sUnlockedSentence.pszValue;
        iUnlockedSentence = pls->iUnlockedSentence;
        if ( v19 == nullptr )
          v19 = locale;
        v21 = SENTENCEG_PlaySequentialSz(
                entity: v4->m_Network.m_pPev,
                szgroupname: v19,
                volume: 0.85000002,
                soundlevel: SNDLVL_NORM,
                flags: 0,
                pitch: 100,
                ipick: iUnlockedSentence,
                freset: 0);
        pls->iUnlockedSentence = v21;
        pls->iLockedSentence = 0;
        pls->bEOFUnlocked = iUnlockedSentence == v21;
        pls->flwaitSentence = gpGlobals->curtime + 6.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FFFA0
// Name: public: void CBaseDoor::MovingSoundThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::MovingSoundThink(CBaseDoor *this)
{
  const Vector *v2; // edi
  Vector *(__thiscall *GetSoundEmissionOrigin)(CBaseEntity *, Vector *); // edx
  const Vector *v4; // eax
  const char *pszValue; // eax
  TOGGLE_STATE m_toggle_state; // ecx
  edict_t *m_pPev; // eax
  signed int v8; // eax
  float thinkTime; // [esp+Ch] [ebp-88h]
  EmitSound_t ep; // [esp+20h] [ebp-74h] BYREF
  CPASAttenuationFilter filter; // [esp+68h] [ebp-2Ch] BYREF
  float attenuation[3]; // [esp+88h] [ebp-Ch] BYREF
  int savedregs; // [esp+94h] [ebp+0h] BYREF

  v2 = (const Vector *)((int (__thiscall *)(CBaseDoor *))this->GetSoundEmissionOrigin)(a1: this);
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
  CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: v2);
  GetSoundEmissionOrigin = this->GetSoundEmissionOrigin;
  filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
  v4 = (const Vector *)((int (__thiscall *)(CBaseDoor *, float *, int))GetSoundEmissionOrigin)(
                         a1: this,
                         a2: attenuation,
                         a3: 1061997773);
  CPASAttenuationFilter::Filter(this: &filter, a2: (int)&savedregs, origin: v4, attenuation: COERCE_FLOAT(attenuation));
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
  ep.m_hSoundScriptHandle = -1;
  pszValue = this->m_NoiseMovingClosed.pszValue;
  ep.m_nFlags = 0;
  ep.m_nPitch = 100;
  memset(&ep.m_pOrigin, 0, 12);
  *(_WORD *)&ep.m_bEmitCloseCaption = 1;
  ep.m_bWarnOnDirectWaveReference = false;
  ep.m_nSpeakerEntity = -1;
  memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
  ep.m_nSoundEntryVersion = 1;
  ep.m_nChannel = 6;
  if ( pszValue == nullptr || (m_toggle_state = this->m_toggle_state) == TS_GOING_DOWN || m_toggle_state == TS_AT_BOTTOM )
  {
    ep.m_pSoundName = this->m_NoiseMoving.pszValue;
    if ( ep.m_pSoundName == nullptr )
      ep.m_pSoundName = locale;
  }
  else
  {
    ep.m_pSoundName = pszValue;
  }
  m_pPev = this->m_Network.m_pPev;
  ep.m_flVolume = 1.0;
  ep.m_SoundLevel = SNDLVL_NORM;
  if ( m_pPev != nullptr )
    v8 = m_pPev - gpGlobals->pEdicts;
  else
    v8 = 0;
  CBaseEntity::EmitSound(&filter, iEntIndex: v8, params: &ep);
  if ( this->m_bLoopMoveSound )
  {
    thinkTime = ((double (__thiscall *)(IEngineSound *, const char *))enginesound->GetSoundDuration)(
                  a1: enginesound,
                  a2: ep.m_pSoundName)
              + gpGlobals->curtime;
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CBaseDoor::MovingSoundThink,
      thinkTime,
      szContext: "MovingSound");
  }
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10100120
// Name: public: void CBaseDoor::StartMovingSound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::StartMovingSound(CBaseDoor *this)
{
  unsigned int m_Index; // eax
  CEntInfo *v3; // ecx
  IHandleEntity *m_pEntity; // esi
  IHandleEntity *v5; // edi
  IGameEvent *v6; // esi
  edict_t *m_pPev; // eax
  int v8; // eax

  CBaseDoor::MovingSoundThink(this);
  m_Index = this->m_hActivator.m_Index;
  if ( m_Index != -1
    && (v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && (m_pEntity = v3->m_pEntity, v3->m_pEntity != nullptr)
    && ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[28].dtr_IHandleEntity)(a1: v3->m_pEntity) != 0 )
  {
    v5 = m_pEntity;
  }
  else
  {
    v5 = nullptr;
  }
  v6 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "door_moving", a3: 0, a4: 0);
  if ( v6 != nullptr )
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    v6->SetInt(this: v6, a2: "entindex", a3: (int)m_pPev);
    if ( v5 != nullptr )
      v8 = engine->GetPlayerUserId(this: engine, a2: (const edict_t *)v5[6].__vftable);
    else
      v8 = 0;
    v6->SetInt(this: v6, a2: "userid", a3: v8);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v6, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101001F0
// Name: public: void CBaseDoor::DoorHitBottom(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::DoorHitBottom(CBaseDoor *this)
{
  const Vector *v2; // edi
  Vector *(__thiscall *GetSoundEmissionOrigin)(CBaseEntity *, Vector *); // edx
  const Vector *v4; // eax
  const char *pszValue; // eax
  edict_t *m_pPev; // eax
  signed int v7; // eax
  bool v8; // zf
  unsigned int m_Index; // eax
  CBaseEntity *v10; // ecx
  CBaseEntity *m_pEntity; // ecx
  EmitSound_t ep; // [esp+18h] [ebp-74h] BYREF
  CPASAttenuationFilter filter; // [esp+60h] [ebp-2Ch] BYREF
  float attenuation[3]; // [esp+80h] [ebp-Ch] BYREF
  int savedregs; // [esp+8Ch] [ebp+0h] BYREF

  if ( (this->m_spawnflags.m_Value & 0x1000) == 0 )
  {
    v2 = (const Vector *)((int (__thiscall *)(CBaseDoor *))this->GetSoundEmissionOrigin)(a1: this);
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
    CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: v2);
    GetSoundEmissionOrigin = this->GetSoundEmissionOrigin;
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
    v4 = (const Vector *)((int (__thiscall *)(CBaseDoor *, float *, int))GetSoundEmissionOrigin)(
                           a1: this,
                           a2: attenuation,
                           a3: 1061997773);
    CPASAttenuationFilter::Filter(
      this: &filter,
      a2: (int)&savedregs,
      origin: v4,
      attenuation: COERCE_FLOAT(attenuation));
    CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
    this->StopMovingSound(this);
    ep.m_nFlags = 0;
    ep.m_nPitch = 100;
    memset(&ep.m_pOrigin, 0, 12);
    *(_WORD *)&ep.m_bEmitCloseCaption = 1;
    ep.m_bWarnOnDirectWaveReference = false;
    ep.m_nSpeakerEntity = -1;
    memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
    ep.m_hSoundScriptHandle = -1;
    ep.m_nSoundEntryVersion = 1;
    ep.m_nChannel = 6;
    if ( this->m_NoiseArrivedClosed.pszValue != nullptr )
      pszValue = this->m_NoiseArrivedClosed.pszValue;
    else
      pszValue = this->m_NoiseArrived.pszValue;
    ep.m_pSoundName = pszValue;
    if ( pszValue == nullptr )
      ep.m_pSoundName = locale;
    m_pPev = this->m_Network.m_pPev;
    ep.m_flVolume = 1.0;
    ep.m_SoundLevel = SNDLVL_NORM;
    if ( m_pPev != nullptr )
      v7 = m_pPev - gpGlobals->pEdicts;
    else
      v7 = 0;
    CBaseEntity::EmitSound(&filter, iEntIndex: v7, params: &ep);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
  v8 = (this->m_spawnflags.m_Value & 1) == 0;
  this->m_toggle_state = TS_AT_BOTTOM;
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CBaseDoor::DoorTouch;
  m_Index = this->m_hActivator.m_Index;
  if ( v8 )
  {
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    COutputEvent::FireOutput(this: &this->m_OnFullyClosed, pActivator: m_pEntity, pCaller: this, fDelay: 0.0);
  }
  else
  {
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      v10 = nullptr;
    else
      v10 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    COutputEvent::FireOutput(this: &this->m_OnFullyOpen, pActivator: v10, pCaller: this, fDelay: 0.0);
  }
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CBaseDoor::CloseAreaPortalsThink,
    thinkTime: gpGlobals->curtime + 0.5,
    szContext: "CloseAreaportalThink");
}

//------------------------------------------------------------------------------
// Address: 0x10100470
// Name: public: void CBaseDoor::DoorGoDown(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseDoor::DoorGoDown(CBaseDoor *this@<ecx>, int a2@<ebp>)
{
  TOGGLE_STATE m_toggle_state; // eax
  bool (__thiscall *IsRotatingDoor)(CBaseDoor *); // eax
  bool v5; // al
  float flSpeed; // [esp+0h] [ebp-8h]

  if ( (this->m_spawnflags.m_Value & 0x1000) == 0 )
  {
    m_toggle_state = this->m_toggle_state;
    if ( m_toggle_state != TS_GOING_UP && m_toggle_state != TS_GOING_DOWN )
      CBaseDoor::StartMovingSound(this);
  }
  IsRotatingDoor = this->IsRotatingDoor;
  this->m_toggle_state = TS_GOING_DOWN;
  this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CBaseDoor::DoorHitBottom;
  v5 = IsRotatingDoor(this);
  flSpeed = this->m_flSpeed;
  if ( v5 )
    CBaseToggle::AngularMove(this, a2: *(float *)&a2, vecDestAngle: &this->m_vecAngle1, flSpeed);
  else
    CBaseToggle::LinearMove(this, a2, vecDest: &this->m_vecPosition1, flSpeed);
  COutputEvent::FireOutput(this: &this->m_OnClose, pActivator: this, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10100500
// Name: public: void CBaseDoor::InputClose(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseDoor::InputClose(CBaseDoor *this@<ecx>, int a2@<ebp>, inputdata_t *inputdata)
{
  if ( this->m_toggle_state != TS_AT_BOTTOM )
    CBaseDoor::DoorGoDown(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10100520
// Name: public: void CBaseDoor::DoorHitTop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::DoorHitTop(CBaseDoor *this)
{
  const Vector *v2; // edi
  Vector *(__thiscall *GetSoundEmissionOrigin)(CBaseEntity *, Vector *); // edx
  const Vector *v4; // eax
  const char *pszValue; // eax
  edict_t *m_pPev; // eax
  signed int v7; // eax
  unsigned int v8; // ecx
  float m_flWait; // xmm1_4
  COutputEvent *p_m_OnFullyClosed; // ecx
  EmitSound_t ep; // [esp+18h] [ebp-74h] BYREF
  CPASAttenuationFilter filter; // [esp+60h] [ebp-2Ch] BYREF
  float attenuation[3]; // [esp+80h] [ebp-Ch] BYREF
  int savedregs; // [esp+8Ch] [ebp+0h] BYREF

  if ( (this->m_spawnflags.m_Value & 0x1000) == 0 )
  {
    v2 = (const Vector *)((int (__thiscall *)(CBaseDoor *))this->GetSoundEmissionOrigin)(a1: this);
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
    CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: v2);
    GetSoundEmissionOrigin = this->GetSoundEmissionOrigin;
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
    v4 = (const Vector *)((int (__thiscall *)(CBaseDoor *, float *, int))GetSoundEmissionOrigin)(
                           a1: this,
                           a2: attenuation,
                           a3: 1061997773);
    CPASAttenuationFilter::Filter(
      this: &filter,
      a2: (int)&savedregs,
      origin: v4,
      attenuation: COERCE_FLOAT(attenuation));
    CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
    this->StopMovingSound(this);
    ep.m_hSoundScriptHandle = -1;
    pszValue = this->m_NoiseArrived.pszValue;
    ep.m_nFlags = 0;
    ep.m_nPitch = 100;
    memset(&ep.m_pOrigin, 0, 12);
    *(_WORD *)&ep.m_bEmitCloseCaption = 1;
    ep.m_bWarnOnDirectWaveReference = false;
    ep.m_nSpeakerEntity = -1;
    memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
    ep.m_nSoundEntryVersion = 1;
    ep.m_nChannel = 6;
    ep.m_pSoundName = pszValue;
    if ( pszValue == nullptr )
      ep.m_pSoundName = locale;
    m_pPev = this->m_Network.m_pPev;
    ep.m_flVolume = 1.0;
    ep.m_SoundLevel = SNDLVL_NORM;
    if ( m_pPev != nullptr )
      v7 = m_pPev - gpGlobals->pEdicts;
    else
      v7 = 0;
    CBaseEntity::EmitSound(&filter, iEntIndex: v7, params: &ep);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
  v8 = (unsigned int)this->m_spawnflags.m_Value >> 5;
  this->m_toggle_state = TS_AT_TOP;
  if ( (v8 & 1) != 0 )
  {
    this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CBaseDoor::DoorTouch;
  }
  else
  {
    CBaseEntity::SetMoveDoneTime(this, flDelay: this->m_flWait);
    m_flWait = this->m_flWait;
    this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CBaseDoor::DoorGoDown;
    if ( m_flWait == -1.0 )
      CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  }
  p_m_OnFullyClosed = &this->m_OnFullyClosed;
  if ( (this->m_spawnflags.m_Value & 1) == 0 )
    p_m_OnFullyClosed = &this->m_OnFullyOpen;
  COutputEvent::FireOutput(this: p_m_OnFullyClosed, pActivator: this, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x101006F0
// Name: public: void CBaseDoor::DoorGoUp(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall CBaseDoor::DoorGoUp(CBaseDoor *this@<ecx>, float a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  TOGGLE_STATE m_toggle_state; // eax
  bool (__thiscall *IsRotatingDoor)(CBaseDoor *); // eax
  CEntInfo *v7; // ecx
  unsigned int m_Index; // eax
  float v9; // xmm0_4
  float z; // edx
  CBaseEntity *v11; // edi
  CBaseEntity *v12; // eax
  CBaseEntity *v13; // edi
  CBaseEntity *v14; // edi
  float y; // xmm1_4
  float x; // xmm0_4
  const Vector *v17; // eax
  float v18; // xmm1_4
  CBaseEntity *v19; // eax
  const Vector *AbsOrigin; // eax
  float v21; // xmm1_4
  float v22; // xmm1_4
  float v24; // [esp+14h] [ebp-5Ch]
  Vector v25; // [esp+30h] [ebp-40h] BYREF
  Vector nearestPoint; // [esp+3Ch] [ebp-34h] BYREF
  Vector origin; // [esp+48h] [ebp-28h] BYREF
  Vector activatorToNearestPoint; // [esp+54h] [ebp-1Ch] BYREF
  Vector activatorToOrigin; // [esp+60h] [ebp-10h] BYREF
  float retaddr; // [esp+70h] [ebp+0h]

  activatorToOrigin.y = a2;
  activatorToOrigin.z = retaddr;
  CBaseDoor::UpdateAreaPortals(this, isOpen: true);
  if ( (this->m_spawnflags.m_Value & 0x1000) == 0 )
  {
    m_toggle_state = this->m_toggle_state;
    if ( m_toggle_state != TS_GOING_UP && m_toggle_state != TS_GOING_DOWN )
      CBaseDoor::StartMovingSound(this);
  }
  IsRotatingDoor = this->IsRotatingDoor;
  this->m_toggle_state = TS_GOING_UP;
  this->m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))CBaseDoor::DoorHitTop;
  if ( ((unsigned __int8 (__thiscall *)(CBaseDoor *, int, int))IsRotatingDoor)(a1: this, a2: a3, a3: a4) != 0 )
  {
    m_Index = this->m_hActivator.m_Index;
    v9 = 1.0;
    activatorToOrigin.x = 1.0;
    if ( m_Index != -1 )
    {
      v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && v7->m_pEntity != nullptr
        && (this->m_spawnflags.m_Value & 0x10) == 0
        && this->m_vecMoveAng.y != 0.0 )
      {
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&activatorToOrigin.y);
        z = this->m_vecAbsOrigin.z;
        *(_QWORD *)&nearestPoint.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
        nearestPoint.z = z;
        v11 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hActivator);
        if ( (v11->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v11, a2: (int)&activatorToOrigin.y);
        CCollisionProperty::CalcNearestPoint(
          this: &this->m_Collision,
          vecWorldPt: &v11->m_vecAbsOrigin,
          pVecNearestWorldPt: &v25);
        v12 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hActivator);
        v13 = v12;
        if ( (v12->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v12, a2: (int)&activatorToOrigin.y);
        origin.x = v25.x - v13->m_vecAbsOrigin.x;
        origin.y = v25.y - v13->m_vecAbsOrigin.y;
        origin.z = 0.0;
        v14 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hActivator);
        if ( (v14->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v14, a2: (int)&activatorToOrigin.y);
        activatorToNearestPoint.x = nearestPoint.x - v14->m_vecAbsOrigin.x;
        v24 = fsqrt(
                (float)((float)((float)((float)(nearestPoint.y - v14->m_vecAbsOrigin.y) - origin.y)
                              * (float)((float)(nearestPoint.y - v14->m_vecAbsOrigin.y) - origin.y))
                      + (float)(COERCE_FLOAT(LODWORD(origin.z) ^ _mask__NegFloat_)
                              * COERCE_FLOAT(LODWORD(origin.z) ^ _mask__NegFloat_)))
              + (float)((float)(activatorToNearestPoint.x - origin.x) * (float)(activatorToNearestPoint.x - origin.x)));
        VectorNormalize(vec: &activatorToNearestPoint);
        VectorNormalize(vec: &origin);
        y = activatorToNearestPoint.y;
        x = activatorToNearestPoint.x;
        if ( v24 < 5.0
          && (float)((float)((float)(activatorToNearestPoint.y * origin.y)
                           + (float)(activatorToNearestPoint.x * origin.x))
                   + (float)(activatorToNearestPoint.z * origin.z)) > 0.99000001 )
        {
          v17 = this->WorldSpaceCenter(this);
          v18 = (float)(nearestPoint.y - v17->y) + nearestPoint.y;
          nearestPoint.x = (float)(nearestPoint.x - v17->x) + nearestPoint.x;
          nearestPoint.y = v18;
          v19 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hActivator);
          AbsOrigin = CBaseEntity::GetAbsOrigin(this: v19);
          v21 = nearestPoint.y - AbsOrigin->y;
          activatorToNearestPoint.x = nearestPoint.x - AbsOrigin->x;
          activatorToNearestPoint.y = v21;
          VectorNormalize(vec: nullptr);
          y = activatorToNearestPoint.y;
          x = activatorToNearestPoint.x;
        }
        if ( (float)((float)(x * origin.y) - (float)(y * origin.x)) <= 0.0 )
          v9 = activatorToOrigin.x;
        else
          v9 = -1.0;
      }
    }
    nearestPoint.x = this->m_vecAngle2.x * v9;
    nearestPoint.y = this->m_vecAngle2.y * v9;
    v22 = this->m_vecAngle2.z;
    LODWORD(activatorToNearestPoint.z) = v7;
    activatorToNearestPoint.z = this->m_flSpeed;
    nearestPoint.z = v22 * v9;
    CBaseToggle::AngularMove(
      this,
      a2: COERCE_FLOAT((Vector *)&activatorToOrigin.y),
      vecDestAngle: (const QAngle *)&nearestPoint,
      flSpeed: activatorToNearestPoint.z);
  }
  else
  {
    CBaseToggle::LinearMove(
      this,
      a2: (int)&activatorToOrigin.y,
      vecDest: &this->m_vecPosition2,
      flSpeed: this->m_flSpeed);
  }
  COutputEvent::FireOutput(this: &this->m_OnOpen, pActivator: this, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10100AA0
// Name: public: virtual void CBaseDoor::Blocked(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseDoor::Blocked(CBaseDoor *this@<ecx>, CBaseEntity *a2@<esi>, CBaseEntity *pOther)
{
  float flDamage; // xmm0_4
  const CTakeDamageInfo *v5; // eax
  int v6; // ebx
  CBaseDoor *v7; // esi
  CBaseDoor_vtbl *v8; // edx
  CBaseDoor *pDoorList[64]; // [esp+18h] [ebp-15Ch] BYREF
  CTakeDamageInfo v10; // [esp+118h] [ebp-5Ch] BYREF
  int savedregs; // [esp+174h] [ebp+0h] BYREF
  int doorCount; // [esp+17Ch] [ebp+8h]

  flDamage = this->m_flBlockDamage;
  if ( flDamage != 0.0 )
  {
    a2 = pOther;
    if ( (this->m_bForceClosed || this->m_flWait < 0.0)
      && pOther->m_MoveType.m_Value == 6
      && pOther->m_takedamage.m_Value <= 1u )
    {
      EntityPhysics_CreateSolver(
        pMovingEntity: this,
        pPhysicsObject: pOther,
        disableCollisions: true,
        separationDuration: 4.0);
    }
    else
    {
      v5 = CTakeDamageInfo::CTakeDamageInfo(
             this: &v10,
             pInflictor: this,
             pAttacker: this,
             flDamage,
             bitsDamageType: 1,
             iKillType: 0,
             iObjectsPenetrated: 0);
      CBaseEntity::TakeDamage(this: pOther, a2: (int)pOther, inputInfo: v5);
    }
  }
  if ( !this->m_bForceClosed )
  {
    if ( this->m_flWait >= 0.0 )
    {
      if ( this->m_toggle_state == TS_GOING_DOWN )
        CBaseDoor::DoorGoUp(this, a2: COERCE_FLOAT(&savedregs), a3: (int)this, a4: (int)a2);
      else
        CBaseDoor::DoorGoDown(this, a2: (int)&savedregs);
    }
    if ( this->m_iName.m_Value.pszValue != nullptr )
    {
      v6 = 0;
      doorCount = CBaseDoor::GetDoorMovementGroup(this, pDoorList, listMax: 64);
      if ( doorCount > 0 )
      {
        do
        {
          v7 = pDoorList[v6];
          if ( v7->m_flWait >= 0.0 )
          {
            if ( this->m_bDoorGroup
              && this->m_vecMoveDir.x == v7->m_vecMoveDir.x
              && this->m_vecMoveDir.y == v7->m_vecMoveDir.y
              && this->m_vecMoveDir.z == v7->m_vecMoveDir.z )
            {
              if ( (this->m_iEFlags & 0x1000) != 0 )
                CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
              if ( (v7->m_iEFlags & 0x1000) != 0 )
                CBaseEntity::CalcAbsoluteVelocity(this: v7, a2: (int)&savedregs);
              if ( this->m_vecAbsVelocity.x == v7->m_vecAbsVelocity.x
                && this->m_vecAbsVelocity.y == v7->m_vecAbsVelocity.y
                && this->m_vecAbsVelocity.z == v7->m_vecAbsVelocity.z
                && this->m_vecAngVelocity.x == v7->m_vecAngVelocity.x
                && this->m_vecAngVelocity.y == v7->m_vecAngVelocity.y
                && this->m_vecAngVelocity.z == v7->m_vecAngVelocity.z )
              {
                v8 = v7->__vftable;
                v7->m_nSimulationTick = this->m_nSimulationTick;
                if ( v8->IsRotatingDoor(this: v7) )
                {
                  CBaseEntity::SetLocalAngles(this: v7, angles: &this->m_angRotation.m_Value);
                  CBaseEntity::SetLocalAngularVelocity(this: v7, vecAngVelocity: &vec3_angle);
                }
                else
                {
                  CBaseEntity::SetLocalOrigin(this: v7, origin: &this->m_vecOrigin.m_Value);
                  CBaseEntity::SetAbsVelocity(this: v7, vecAbsVelocity: &vec3_origin);
                }
              }
            }
            if ( v7->m_toggle_state == TS_GOING_DOWN )
              CBaseDoor::DoorGoUp(this: v7, a2: COERCE_FLOAT(&savedregs), a3: (int)this, a4: (int)v7);
            else
              CBaseDoor::DoorGoDown(this: v7, a2: (int)&savedregs);
          }
          ++v6;
        }
        while ( v6 < doorCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100D40
// Name: public: void CBaseDoor::InputOpen(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseDoor::InputOpen(CBaseDoor *this@<ecx>, float a2@<ebp>, int a3@<edi>, inputdata_t *inputdata)
{
  TOGGLE_STATE m_toggle_state; // eax

  m_toggle_state = this->m_toggle_state;
  if ( m_toggle_state != TS_AT_TOP && m_toggle_state != TS_GOING_UP && !this->m_bLocked )
  {
    PlayLockSounds(pEdict: this, pls: &this->m_ls, flocked: 0, fbutton: 0);
    CBaseDoor::DoorGoUp(this, a2, a3, a4: (int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100D80
// Name: public: void CBaseDoor::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseDoor::InputToggle(
        CBaseDoor *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        inputdata_t *inputdata)
{
  TOGGLE_STATE m_toggle_state; // eax

  if ( !this->m_bLocked )
  {
    m_toggle_state = this->m_toggle_state;
    if ( m_toggle_state == TS_AT_BOTTOM )
    {
      CBaseDoor::DoorGoUp(this, a2: *(float *)&a2, a3, a4);
    }
    else if ( m_toggle_state == TS_AT_TOP )
    {
      CBaseDoor::DoorGoDown(this, a2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100DB0
// Name: public: int CBaseDoor::DoorActivate(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CBaseDoor::DoorActivate@<eax>(CBaseDoor *this@<ecx>, int a2@<ebp>, int a3@<edi>)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  TOGGLE_STATE m_toggle_state; // eax

  m_Index = this->m_hActivator.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( !UTIL_IsMasterTriggered(sMaster: this->m_sMaster, pActivator: m_pEntity) )
    return 0;
  if ( (this->m_spawnflags.m_Value & 0x20) == 0 || this->m_toggle_state != TS_AT_TOP )
  {
    PlayLockSounds(pEdict: this, pls: &this->m_ls, flocked: 0, fbutton: 0);
    m_toggle_state = this->m_toggle_state;
    if ( m_toggle_state != TS_AT_TOP && m_toggle_state != TS_GOING_UP )
      CBaseDoor::DoorGoUp(this, a2: *(float *)&a2, a3, a4: (int)this);
    return 1;
  }
  else
  {
    CBaseDoor::DoorGoDown(this, a2);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100E50
// Name: public: void CBaseDoor::DoorTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::DoorTouch(CBaseDoor *this, CBaseEntity *pOther)
{
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  if ( this->m_ChainTarget.pszValue != nullptr )
    CBaseDoor::ChainTouch(this, pOther);
  if ( pOther->IsPlayer(this: pOther) && (this->m_spawnflags.m_Value & 0x400) != 0 )
  {
    if ( this->m_sMaster.pszValue != nullptr && !UTIL_IsMasterTriggered(sMaster: this->m_sMaster, pActivator: pOther) )
      PlayLockSounds(pEdict: this, pls: &this->m_ls, flocked: 1, fbutton: 0);
    if ( this->m_bLocked )
    {
      COutputEvent::FireOutput(this: &this->m_OnLockedUse, pActivator: pOther, pCaller: pOther, fDelay: 0.0);
      PlayLockSounds(pEdict: this, pls: &this->m_ls, flocked: 1, fbutton: 0);
    }
    else
    {
      this->m_hActivator.m_Index = pOther->GetRefEHandle(this: pOther)->m_Index;
      if ( CBaseDoor::DoorActivate(this, a2: (int)&savedregs, a3: (int)pOther) != 0 )
        this->m_pfnTouch = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100F30
// Name: public: virtual void CBaseDoor::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseDoor::Use(
        CBaseDoor *this@<ecx>,
        CBaseEntityList *a2@<edi>,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  unsigned int m_Index; // ecx
  int v8; // eax
  CEntInfo *v9; // edx
  unsigned int v10; // ecx
  int v11; // eax
  CEntInfo *v12; // eax
  IHandleEntity *v13; // eax
  int m_Value; // ecx
  TOGGLE_STATE m_toggle_state; // eax
  bool v16; // zf
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  if ( pActivator != nullptr )
    this->m_hActivator.m_Index = pActivator->GetRefEHandle(this: pActivator)->m_Index;
  else
    this->m_hActivator.m_Index = -1;
  if ( this->m_ChainTarget.pszValue != nullptr )
    CBaseDoor::ChainUse(this);
  m_Index = this->m_hActivator.m_Index;
  if ( m_Index != -1 )
  {
    a2 = g_pEntityList;
    v8 = (unsigned __int16)m_Index;
    v9 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v10 = HIWORD(m_Index);
    if ( v9->m_SerialNumber == v10 && v9->m_pEntity != nullptr )
    {
      v11 = v8;
      v16 = g_pEntityList->m_EntPtrArray[v11].m_SerialNumber == v10;
      v12 = &g_pEntityList->m_EntPtrArray[v11];
      v13 = v16 ? v12->m_pEntity : nullptr;
      if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))v13->__vftable[28].dtr_IHandleEntity)(a1: v13) != 0
        && (this->m_spawnflags.m_Value & 0x100) == 0 )
      {
        goto LABEL_26;
      }
    }
  }
  m_Value = this->m_spawnflags.m_Value;
  m_toggle_state = this->m_toggle_state;
  if ( (m_Value & 0x10000) != 0 )
  {
    if ( m_toggle_state == TS_AT_BOTTOM || m_toggle_state == TS_GOING_DOWN )
      goto LABEL_24;
    if ( (m_Value & 0x20) == 0 )
      return;
    if ( m_toggle_state == TS_AT_TOP )
      goto LABEL_24;
    v16 = m_toggle_state == TS_GOING_UP;
  }
  else
  {
    if ( m_toggle_state == TS_AT_BOTTOM )
      goto LABEL_24;
    if ( (m_Value & 0x20) == 0 )
      return;
    v16 = m_toggle_state == TS_AT_TOP;
  }
  if ( !v16 )
    return;
LABEL_24:
  if ( this->m_bLocked )
  {
    COutputEvent::FireOutput(this: &this->m_OnLockedUse, pActivator, pCaller, fDelay: 0.0);
LABEL_26:
    PlayLockSounds(pEdict: this, pls: &this->m_ls, flocked: 1, fbutton: 0);
    return;
  }
  CBaseDoor::DoorActivate(this, a2: (int)&savedregs, a3: (int)a2);
}

//------------------------------------------------------------------------------
// Address: 0x10101770
// Name: public: virtual void CBaseDoor::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDoor::Spawn(CBaseDoor *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *RootMoveParent; // eax
  CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // edi
  const char *v5; // eax
  Vector *v6; // eax
  float z; // ecx
  bool v8; // zf
  int v9; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v10; // edx
  float v11; // xmm0_4
  const Vector *(__thiscall *OBBMaxs)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  float x; // xmm2_4
  float y; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm6_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm3_4
  const char *DebugName; // eax
  const char *v25; // eax
  SolidType_t v26; // [esp-4h] [ebp-80h]
  matrix3x4_t mat; // [esp+Ch] [ebp-70h] BYREF
  Vector vMinsOut; // [esp+3Ch] [ebp-40h] BYREF
  Vector vMaxsOut; // [esp+48h] [ebp-34h] BYREF
  Vector vMinsIn; // [esp+54h] [ebp-28h] BYREF
  QAngle angMoveDir; // [esp+60h] [ebp-1Ch] BYREF
  Vector vMaxsIn; // [esp+6Ch] [ebp-10h] BYREF
  char v33[4]; // [esp+78h] [ebp-4h] BYREF

  this->Precache(this);
  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr
    && (RootMoveParent = CBaseEntity::GetRootMoveParent(this),
        RootMoveParent->m_Collision.GetSolid(this: &RootMoveParent->m_Collision) == SOLID_BSP) )
  {
    v26 = SOLID_BSP;
  }
  else
  {
    v26 = SOLID_VPHYSICS;
  }
  p_m_Collision = &this->m_Collision;
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: v26);
  angMoveDir = (QAngle)this->m_vecMoveDir;
  AngleVectors(angles: &angMoveDir, forward: &this->m_vecMoveDir);
  v5 = *(const char **)((int (__thiscall *)(CBaseDoor *, char *))this->GetModelName)(a1: this, a2: v33);
  if ( v5 == nullptr )
    v5 = locale;
  this->SetModel(this, a2: v5);
  this->m_vecPosition1.x = this->m_vecOrigin.m_Value.x;
  this->m_vecPosition1.y = this->m_vecOrigin.m_Value.y;
  this->m_vecPosition1.z = this->m_vecOrigin.m_Value.z;
  v6 = AllocTempVector();
  v6->x = this->m_Collision.m_vecMaxs.m_Value.x - this->m_Collision.m_vecMins.m_Value.x;
  v6->y = this->m_Collision.m_vecMaxs.m_Value.y - this->m_Collision.m_vecMins.m_Value.y;
  v6->z = this->m_Collision.m_vecMaxs.m_Value.z - this->m_Collision.m_vecMins.m_Value.z;
  z = v6->z;
  *(_QWORD *)&vMaxsIn.x = *(_QWORD *)&v6->x;
  v8 = vec3_angle.x == this->m_angRotation.m_Value.x;
  vMaxsIn.z = z;
  if ( v8 && vec3_angle.y == this->m_angRotation.m_Value.y && vec3_angle.z == this->m_angRotation.m_Value.z )
  {
    v15 = vMaxsIn.z;
    y = vMaxsIn.y;
    x = vMaxsIn.x;
  }
  else
  {
    v9 = (int)p_m_Collision->OBBMins(this: &this->m_Collision);
    v10 = p_m_Collision->__vftable;
    vMinsIn.x = *(float *)v9;
    vMinsIn.y = *(float *)(v9 + 4);
    v11 = *(float *)(v9 + 8);
    OBBMaxs = v10->OBBMaxs;
    vMinsIn.z = v11;
    vMaxsIn = *OBBMaxs(this: &this->m_Collision);
    AngleMatrix(angles: &this->m_angRotation.m_Value, matrix: &mat);
    RotateAABB(transform: &mat, vecMinsIn: &vMinsIn, vecMaxsIn: &vMaxsIn, vecMinsOut: &vMinsOut, vecMaxsOut: &vMaxsOut);
    x = vMaxsOut.x - vMinsOut.x;
    y = vMaxsOut.y - vMinsOut.y;
    v15 = vMaxsOut.z - vMinsOut.z;
  }
  v16 = this->m_vecMoveDir.y;
  v17 = x - 2.0;
  v18 = this->m_vecMoveDir.z;
  v19 = (float)((float)(fabs((float)(y - 2.0) * v16) + fabs(this->m_vecMoveDir.x * v17)) + fabs((float)(v15 - 2.0) * v18))
      - this->m_flLip;
  v20 = (float)(v19 * this->m_vecMoveDir.x) + this->m_vecPosition1.x;
  v21 = v18 * v19;
  v22 = this->m_vecPosition1.y + (float)(v19 * v16);
  v23 = this->m_vecPosition1.z + v21;
  this->m_vecPosition2.x = v20;
  this->m_vecPosition2.y = v22;
  this->m_vecPosition2.z = v23;
  if ( !this->IsRotatingDoor(this) )
  {
    if ( this->m_eSpawnPosition == FUNC_DOOR_SPAWN_OPEN || (this->m_spawnflags.m_Value & 1) != 0 )
    {
      UTIL_SetOrigin(entity: this, vecOrigin: &this->m_vecPosition2, bFireTriggers: false);
      this->m_toggle_state = TS_AT_TOP;
    }
    else
    {
      this->m_toggle_state = TS_AT_BOTTOM;
    }
  }
  if ( (this->m_spawnflags.m_Value & 0x800) != 0 )
    this->m_bLocked = true;
  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  if ( this->m_flSpeed == 0.0 )
    this->m_flSpeed = 100.0;
  v8 = this->m_iClassname.pszValue == "func_water";
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CBaseDoor::DoorTouch;
  if ( !v8 && CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "func_water") == 0 )
  {
    if ( (this->m_spawnflags.m_Value & 8) != 0 )
    {
      this->m_iEFlags |= 0x40000u;
      CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
    }
    if ( (this->m_spawnflags.m_Value & 4) != 0 )
    {
      CBaseEntity::SetCollisionGroup(this, collisionGroup: 15);
      CBaseEntity::AddFlag(this, flags: 0x80000000);
    }
    if ( this->m_bIgnoreDebris )
    {
      if ( (this->m_spawnflags.m_Value & 4) != 0 )
      {
        DebugName = CBaseEntity::GetDebugName(this);
        _Warning(a1: "Door %s with conflicting collision settings, removing ignoredebris\n", DebugName);
      }
      else
      {
        CBaseEntity::SetCollisionGroup(this, collisionGroup: 4);
      }
    }
  }
  if ( this->m_eSpawnPosition == FUNC_DOOR_SPAWN_OPEN && (this->m_spawnflags.m_Value & 1) != 0 )
  {
    v25 = CBaseEntity::GetDebugName(this);
    _Warning(
      a1: "Door %s using obsolete 'Start Open' spawnflag with 'Spawn Position' set to 'Open'. Reverting to old behavior.\n",
      v25);
  }
  this->CreateVPhysics(this);
}

//------------------------------------------------------------------------------
// Address: 0x10101B90
// Name: public: virtual void CRotDoor::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRotDoor::Spawn(CRotDoor *this)
{
  float v2; // xmm1_4
  float v3; // xmm2_4
  QAngle *p_m_vecAngle1; // eax
  QAngle *p_m_vecAngle2; // ecx
  float m_flMoveDistance; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  __int64 v9; // xmm0_8
  float z; // edx
  float v11; // xmm1_4
  float v12; // xmm2_4

  CBaseDoor::Spawn(this);
  CBaseToggle::AxisDir(this);
  if ( (this->m_spawnflags.m_Value & 2) != 0 )
  {
    v2 = this->m_vecMoveAng.y * -1.0;
    v3 = this->m_vecMoveAng.z * -1.0;
    this->m_vecMoveAng.x = this->m_vecMoveAng.x * -1.0;
    this->m_vecMoveAng.y = v2;
    this->m_vecMoveAng.z = v3;
  }
  p_m_vecAngle1 = &this->m_vecAngle1;
  this->m_vecAngle1.x = this->m_angRotation.m_Value.x;
  p_m_vecAngle2 = &this->m_vecAngle2;
  this->m_vecAngle1.y = this->m_angRotation.m_Value.y;
  this->m_vecAngle1.z = this->m_angRotation.m_Value.z;
  m_flMoveDistance = this->m_flMoveDistance;
  v7 = (float)(this->m_vecMoveAng.z * m_flMoveDistance) + this->m_angRotation.m_Value.z;
  v8 = this->m_angRotation.m_Value.y + (float)(this->m_vecMoveAng.y * m_flMoveDistance);
  this->m_vecAngle2.x = this->m_angRotation.m_Value.x + (float)(this->m_vecMoveAng.x * m_flMoveDistance);
  this->m_vecAngle2.y = v8;
  this->m_vecAngle2.z = v7;
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
  {
    v9 = *(_QWORD *)&p_m_vecAngle2->x;
    z = this->m_vecAngle2.z;
    p_m_vecAngle2->x = p_m_vecAngle1->x;
    this->m_vecAngle2.y = this->m_vecAngle1.y;
    this->m_vecAngle2.z = this->m_vecAngle1.z;
    LODWORD(p_m_vecAngle1->x) = v9;
    this->m_vecAngle1.y = *((float *)&v9 + 1);
    this->m_vecAngle1.z = z;
    v11 = -this->m_vecMoveAng.y;
    v12 = -this->m_vecMoveAng.z;
    this->m_vecMoveAng.x = -this->m_vecMoveAng.x;
    this->m_vecMoveAng.y = v11;
    this->m_vecMoveAng.z = v12;
    this->Teleport(this, a2: nullptr, a3: &this->m_vecAngle1, a4: nullptr, a5: true);
LABEL_5:
    this->m_toggle_state = TS_AT_BOTTOM;
    goto LABEL_6;
  }
  if ( this->m_eSpawnPosition != FUNC_DOOR_SPAWN_OPEN )
    goto LABEL_5;
  this->Teleport(this, a2: nullptr, a3: &this->m_vecAngle2, a4: nullptr, a5: true);
  this->m_toggle_state = TS_AT_TOP;
LABEL_6:
  if ( this->m_bSolidBsp )
    CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BSP);
}

//------------------------------------------------------------------------------
// Address: 0x104018F0
// Name: CBaseDoor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseDoor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseDoor>(__formal: nullptr);
  CBaseDoor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401960
// Name: DT_BaseDoor::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseDoor::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BaseDoor::g_SendTable);
  return atexit(func: DT_BaseDoor::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10401980
// Name: DT_BaseDoor::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseDoor::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BaseDoor::ignored>();
  DT_BaseDoor::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104019B0
// Name: CRotDoor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CRotDoor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CRotDoor>(__formal: nullptr);
  CRotDoor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041A7A0
// Name: DT_BaseDoor::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseDoor::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BaseDoor::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10100400
// Name: struct datamap_t __near * DataMapInit<class CRotDoor>(class CRotDoor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CRotDoor>()
{
  if ( (_S4_22 & 1) == 0 )
  {
    _S4_22 |= 1u;
    nameHolder_129.m_pszBase = "CRotDoor";
    nameHolder_129.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_129.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_129.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_129.m_Names.m_Size = 0;
    nameHolder_129.m_Names.m_pElements = nullptr;
    nameHolder_129.m_nLenBase = 8;
    atexit(func: DataMapInit_CRotDoor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CRotDoor::m_DataMap.baseMap = &CBaseDoor::m_DataMap;
  CRotDoor::m_DataMap.dataNumFields = 1;
  CRotDoor::m_DataMap.dataDesc = &dataDesc_124[1];
  return &CRotDoor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10101060
// Name: struct datamap_t __near * DataMapInit<class CBaseDoor>(class CBaseDoor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseDoor>()
{
  char *Name; // eax
  char *v1; // eax

  if ( (_S2_70 & 1) == 0 )
  {
    _S2_70 |= 1u;
    nameHolder_130.m_pszBase = "CBaseDoor";
    nameHolder_130.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_130.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_130.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_130.m_Names.m_Size = 0;
    nameHolder_130.m_Names.m_pElements = nullptr;
    nameHolder_130.m_nLenBase = 9;
    atexit(func: DataMapInit_CBaseDoor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseDoor::m_DataMap.baseMap = &CBaseToggle::m_DataMap;
  if ( (_S2_70 & 2) == 0 )
  {
    _S2_70 |= 2u;
    dataDesc_125[27].fieldSize = 1;
    dataDesc_125[27].flags = 22;
    dataDesc_125[28].fieldSize = 1;
    dataDesc_125[28].flags = 22;
    dataDesc_125[29].fieldSize = 1;
    dataDesc_125[29].flags = 22;
    *(_QWORD *)&dataDesc_125[26].inputFunc = 0;
    *(_QWORD *)&dataDesc_125[26].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_125[26].override_count = 0;
    *(_QWORD *)dataDesc_125[26].flatOffset = 0;
    *(_QWORD *)&dataDesc_125[27].inputFunc = 0;
    *(_QWORD *)&dataDesc_125[27].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_125[27].override_count = 0;
    *(_QWORD *)dataDesc_125[27].flatOffset = 0;
    dataDesc_125[30].fieldSize = 1;
    *(_QWORD *)&dataDesc_125[28].inputFunc = 0;
    *(_QWORD *)&dataDesc_125[28].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_125[28].override_count = 0;
    *(_QWORD *)dataDesc_125[28].flatOffset = 0;
    dataDesc_125[30].flags = 22;
    *(_QWORD *)&dataDesc_125[29].inputFunc = 0;
    *(_QWORD *)&dataDesc_125[29].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_125[29].override_count = 0;
    *(_QWORD *)dataDesc_125[29].flatOffset = 0;
    dataDesc_125[31].fieldSize = 1;
    *(_QWORD *)&dataDesc_125[30].inputFunc = 0;
    *(_QWORD *)&dataDesc_125[30].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_125[30].override_count = 0;
    *(_QWORD *)dataDesc_125[30].flatOffset = 0;
    dataDesc_125[26].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_125[26].flatGroup = 0;
    dataDesc_125[27].fieldType = FIELD_CUSTOM;
    dataDesc_125[27].fieldName = "m_OnBlockedClosing";
    dataDesc_125[27].fieldOffset = 1064;
    dataDesc_125[27].externalName = "OnBlockedClosing";
    dataDesc_125[27].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_125[27].flatGroup = 0;
    dataDesc_125[28].fieldType = FIELD_CUSTOM;
    dataDesc_125[28].fieldName = "m_OnUnblockedOpening";
    dataDesc_125[28].fieldOffset = 1136;
    dataDesc_125[28].externalName = "OnUnblockedOpening";
    dataDesc_125[28].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_125[28].flatGroup = 0;
    dataDesc_125[29].fieldType = FIELD_CUSTOM;
    dataDesc_125[29].fieldName = "m_OnUnblockedClosing";
    dataDesc_125[29].fieldOffset = 1112;
    dataDesc_125[29].externalName = "OnUnblockedClosing";
    dataDesc_125[29].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_125[29].flatGroup = 0;
    dataDesc_125[30].fieldType = FIELD_CUSTOM;
    dataDesc_125[30].fieldName = "m_OnFullyClosed";
    dataDesc_125[30].fieldOffset = 1160;
    dataDesc_125[30].externalName = "OnFullyClosed";
    dataDesc_125[30].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_125[30].flatGroup = 0;
    dataDesc_125[31].fieldType = FIELD_CUSTOM;
    dataDesc_125[31].fieldName = "m_OnFullyOpen";
    dataDesc_125[31].fieldOffset = 1184;
    dataDesc_125[31].flags = 22;
    dataDesc_125[31].externalName = "OnFullyOpen";
    dataDesc_125[31].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_125[31].inputFunc = 0;
    dataDesc_125[32].fieldSize = 1;
    *(_QWORD *)&dataDesc_125[31].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_125[31].override_count = 0;
    *(_QWORD *)dataDesc_125[31].flatOffset = 0;
    dataDesc_125[32].flags = 22;
    dataDesc_125[32].fieldType = FIELD_CUSTOM;
    dataDesc_125[33].fieldType = FIELD_CUSTOM;
    dataDesc_125[34].fieldType = FIELD_CUSTOM;
    *(_QWORD *)&dataDesc_125[32].inputFunc = 0;
    *(_QWORD *)&dataDesc_125[32].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_125[32].override_count = 0;
    *(_QWORD *)dataDesc_125[32].flatOffset = 0;
    dataDesc_125[33].fieldSize = 1;
    *(_QWORD *)&dataDesc_125[33].inputFunc = 0;
    *(_QWORD *)&dataDesc_125[33].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_125[33].override_count = 0;
    *(_QWORD *)dataDesc_125[33].flatOffset = 0;
    dataDesc_125[34].fieldSize = 1;
    *(_DWORD *)&dataDesc_125[31].flatGroup = 0;
    dataDesc_125[32].fieldName = "m_OnClose";
    dataDesc_125[32].fieldOffset = 1208;
    dataDesc_125[32].externalName = "OnClose";
    dataDesc_125[32].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_125[32].flatGroup = 0;
    dataDesc_125[33].fieldName = "m_OnOpen";
    dataDesc_125[33].fieldOffset = 1232;
    dataDesc_125[33].flags = 22;
    dataDesc_125[33].externalName = "OnOpen";
    dataDesc_125[33].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_125[33].flatGroup = 0;
    dataDesc_125[34].fieldName = "m_OnLockedUse";
    dataDesc_125[34].fieldOffset = 1256;
    dataDesc_125[34].flags = 22;
    dataDesc_125[34].externalName = "OnLockedUse";
    dataDesc_125[34].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_125[34].inputFunc = 0;
    *(_QWORD *)&dataDesc_125[34].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_125[34].override_count = 0;
    *(_QWORD *)dataDesc_125[34].flatOffset = 0;
    *(_DWORD *)&dataDesc_125[34].flatGroup = 0;
    dataDesc_125[35].fieldType = FIELD_VOID;
    dataDesc_125[35].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_130,
                                   pszIdentifier: "DoorTouch");
    dataDesc_125[35].flags = 32;
    dataDesc_125[35].fieldOffset = 0;
    dataDesc_125[35].fieldSize = 1;
    dataDesc_125[35].externalName = nullptr;
    dataDesc_125[35].pSaveRestoreOps = nullptr;
    dataDesc_125[35].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseDoor::DoorTouch;
    *(_QWORD *)&dataDesc_125[35].td = 0;
    *(_QWORD *)&dataDesc_125[35].override_field = 0;
    *(_QWORD *)&dataDesc_125[35].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_125[35].flatOffset[1] = 0;
    dataDesc_125[36].fieldType = FIELD_VOID;
    dataDesc_125[36].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_130,
                                   pszIdentifier: "DoorGoUp");
    dataDesc_125[36].fieldOffset = 0;
    dataDesc_125[36].fieldSize = 1;
    dataDesc_125[36].flags = 32;
    dataDesc_125[36].externalName = nullptr;
    dataDesc_125[36].pSaveRestoreOps = nullptr;
    dataDesc_125[36].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseDoor::DoorGoUp;
    *(_QWORD *)&dataDesc_125[36].td = 0;
    *(_QWORD *)&dataDesc_125[36].override_field = 0;
    *(_QWORD *)&dataDesc_125[36].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_125[36].flatOffset[1] = 0;
    dataDesc_125[37].fieldType = FIELD_VOID;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_130, pszIdentifier: "DoorGoDown");
    dataDesc_125[37].fieldSize = 1;
    dataDesc_125[37].fieldName = Name;
    dataDesc_125[37].fieldOffset = 0;
    dataDesc_125[37].flags = 32;
    dataDesc_125[37].externalName = nullptr;
    dataDesc_125[37].pSaveRestoreOps = nullptr;
    dataDesc_125[37].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseDoor::DoorGoDown;
    *(_QWORD *)&dataDesc_125[37].td = 0;
    *(_QWORD *)&dataDesc_125[37].override_field = 0;
    *(_QWORD *)&dataDesc_125[37].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_125[37].flatOffset[1] = 0;
    dataDesc_125[38].fieldType = FIELD_VOID;
    dataDesc_125[38].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_130,
                                   pszIdentifier: "DoorHitTop");
    dataDesc_125[38].flags = 32;
    dataDesc_125[38].fieldOffset = 0;
    dataDesc_125[38].fieldSize = 1;
    dataDesc_125[38].externalName = nullptr;
    dataDesc_125[38].pSaveRestoreOps = nullptr;
    dataDesc_125[38].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseDoor::DoorHitTop;
    *(_QWORD *)&dataDesc_125[38].td = 0;
    *(_QWORD *)&dataDesc_125[38].override_field = 0;
    *(_QWORD *)&dataDesc_125[38].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_125[38].flatOffset[1] = 0;
    dataDesc_125[39].fieldType = FIELD_VOID;
    dataDesc_125[39].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_130,
                                   pszIdentifier: "DoorHitBottom");
    dataDesc_125[39].fieldOffset = 0;
    dataDesc_125[39].fieldSize = 1;
    dataDesc_125[39].flags = 32;
    dataDesc_125[39].externalName = nullptr;
    dataDesc_125[39].pSaveRestoreOps = nullptr;
    dataDesc_125[39].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseDoor::DoorHitBottom;
    *(_QWORD *)&dataDesc_125[39].td = 0;
    *(_QWORD *)&dataDesc_125[39].override_field = 0;
    *(_QWORD *)&dataDesc_125[39].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_125[39].flatOffset[1] = 0;
    dataDesc_125[40].fieldType = FIELD_VOID;
    v1 = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_130, pszIdentifier: "MovingSoundThink");
    dataDesc_125[40].fieldSize = 1;
    dataDesc_125[40].fieldName = v1;
    dataDesc_125[40].fieldOffset = 0;
    dataDesc_125[40].flags = 32;
    dataDesc_125[40].externalName = nullptr;
    dataDesc_125[40].pSaveRestoreOps = nullptr;
    dataDesc_125[40].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseDoor::MovingSoundThink;
    *(_QWORD *)&dataDesc_125[40].td = 0;
    *(_QWORD *)&dataDesc_125[40].override_field = 0;
    *(_QWORD *)&dataDesc_125[40].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_125[40].flatOffset[1] = 0;
    dataDesc_125[41].fieldType = FIELD_VOID;
    dataDesc_125[41].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_130,
                                   pszIdentifier: "CloseAreaPortalsThink");
    dataDesc_125[41].fieldOffset = 0;
    *(_DWORD *)&dataDesc_125[41].fieldSize = 2097153;
    dataDesc_125[41].externalName = nullptr;
    dataDesc_125[41].pSaveRestoreOps = nullptr;
    dataDesc_125[41].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseDoor::CloseAreaPortalsThink;
    *(_QWORD *)&dataDesc_125[41].td = 0;
    *(_QWORD *)&dataDesc_125[41].override_field = 0;
    *(_QWORD *)&dataDesc_125[41].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_125[41].flatOffset[1] = 0;
  }
  CBaseDoor::m_DataMap.dataNumFields = 41;
  CBaseDoor::m_DataMap.dataDesc = &dataDesc_125[1];
  return &CBaseDoor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1041A7B0
// Name: _ServerClassInit_DT_BaseDoor::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BaseDoor::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_39;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041A7D0
// Name: _DataMapInit_CBaseDoor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseDoor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_130);
}

//------------------------------------------------------------------------------
// Address: 0x1041A7E0
// Name: _DataMapInit_CRotDoor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CRotDoor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_129);
}
