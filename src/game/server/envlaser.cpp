// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/envlaser.cpp
// Functions: 13
// ============================================================

#include "game\server\envlaser.h"

//------------------------------------------------------------------------------
// Address: 0x1011D620
// Name: public: virtual struct datamap_t __near * CEnvLaser::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvLaser::GetDataDescMap(CEnvLaser *this)
{
  return &CEnvLaser::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1011D630
// Name: public: void CEnvLaser::TurnOff(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvLaser::TurnOff(CEnvLaser *this)
{
  CSprite *m_pSprite; // ecx

  CBaseEntity::AddEffects(this, nEffects: 32);
  m_pSprite = this->m_pSprite;
  if ( m_pSprite != nullptr )
    CSprite::TurnOff(this: m_pSprite);
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1011D680
// Name: public: virtual void CEnvLaser::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvLaser::Precache(CEnvLaser *this)
{
  const char *v2; // eax
  CEnvLaser_vtbl *v3; // edi
  int v4; // eax
  const char *pszValue; // esi
  _BYTE v6[4]; // [esp+4h] [ebp-4h] BYREF

  v2 = *(const char **)((int (__thiscall *)(CEnvLaser *, _BYTE *))this->GetModelName)(a1: this, a2: v6);
  if ( v2 == nullptr )
    v2 = locale;
  v3 = this->__vftable;
  v4 = CBaseEntity::PrecacheModel(a1: (bool (__cdecl *)(const char *))this->__vftable, name: v2, bPreload: true);
  v3->SetModelIndex(this, a2: v4);
  pszValue = this->m_iszSpriteName.pszValue;
  if ( pszValue != nullptr )
    CBaseEntity::PrecacheModel(a1: (bool (__cdecl *)(const char *))v3, name: pszValue, bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x1011D710
// Name: public: void CEnvLaser::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvLaser::InputTurnOff(CEnvLaser *this, inputdata_t *inputdata)
{
  CSprite *m_pSprite; // ecx

  if ( (this->m_fEffects.m_Value & 0x20) == 0 )
  {
    CBaseEntity::AddEffects(this, nEffects: 32);
    m_pSprite = this->m_pSprite;
    if ( m_pSprite != nullptr )
      CSprite::TurnOff(this: m_pSprite);
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011D770
// Name: public: void CEnvLaser::StrikeThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvLaser::StrikeThink(CEnvLaser *this)
{
  const char *pszValue; // eax
  CBaseEntity *v3; // edi
  CNetworkVectorBase<Vector,CBeam::NetworkVar_m_vecEndPos> *AbsEndPos; // eax
  __int64 v5; // xmm0_8
  float z; // eax
  CSprite *m_pSprite; // eax
  const Vector *AbsStartPos; // eax
  CGameTrace tr; // [esp+Ch] [ebp-60h] BYREF
  Vector vecFireAt; // [esp+60h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+6Ch] [ebp+0h] BYREF

  pszValue = this->m_iszLaserTarget.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v3 = CBeam::RandomTargetname(this, szName: pszValue);
  AbsEndPos = CBeam::GetAbsEndPos(this, a2: (int)&savedregs);
  v5 = *(_QWORD *)&AbsEndPos->m_Value.x;
  z = AbsEndPos->m_Value.z;
  *(_QWORD *)&vecFireAt.x = v5;
  vecFireAt.z = z;
  if ( v3 != nullptr )
  {
    if ( (v3->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v3, a2: (int)&savedregs);
    vecFireAt = v3->m_vecAbsOrigin;
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: &this->m_vecAbsOrigin,
    vecAbsEnd: &vecFireAt,
    mask: 0x200400Bu,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: &tr);
  CBeam::SetAbsEndPos(this, pos: &tr.endpos);
  m_pSprite = this->m_pSprite;
  if ( m_pSprite != nullptr )
    UTIL_SetOrigin(entity: m_pSprite, vecOrigin: &tr.endpos, bFireTriggers: false);
  if ( gpGlobals->curtime >= this->m_flFireTime + 0.1 )
  {
    CBeam::BeamDamage(this, ptr: &tr);
    AbsStartPos = CBeam::GetAbsStartPos(this, a2: (int)&savedregs);
    CBeam::DoSparks(this, start: AbsStartPos, end: &tr.endpos);
  }
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1011D8F0
// Name: public: virtual bool CEnvLaser::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEnvLaser::KeyValue(CEnvLaser *this, char *szKeyName, float szValue)
{
  long double v4; // st7
  float v5; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *m_pPev; // ecx
  float v9; // xmm0_4
  bool v10; // zf
  edict_t *v11; // ecx
  int v12; // eax

  if ( szKeyName == "width" || _V_stricmp(s1: szKeyName, s2: "width") == 0 )
  {
    v4 = atof(nptr: (const char *)LODWORD(szValue));
    szValue = v4;
    if ( v4 <= 102.3 )
      v5 = szValue;
    else
      v5 = 102.3;
    m_Value = this->m_fWidth.m_Value;
    szValue = v5;
    if ( m_Value != v5 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_fWidth.m_Value = v5;
        return 1;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
        {
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3C4u);
          v5 = szValue;
        }
        this->m_fWidth.m_Value = v5;
        return 1;
      }
    }
    return 1;
  }
  if ( szKeyName != "NoiseAmplitude" && _V_stricmp(s1: szKeyName, s2: "NoiseAmplitude") != 0 )
  {
    if ( szKeyName == "TextureScroll" || _V_stricmp(s1: szKeyName, s2: "TextureScroll") == 0 )
    {
      v12 = atoi(nptr: (const char *)LODWORD(szValue));
      CBeam::SetScrollRate(this, speed: v12);
      return 1;
    }
    if ( szKeyName == "texture" || _V_stricmp(s1: szKeyName, s2: "texture") == 0 )
    {
      this->m_ModelName.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&szValue).pszValue;
      CBaseEntity::DispatchUpdateTransmitState(this);
      return 1;
    }
    CBaseEntity::KeyValue(this, szKeyName, szValue: (const char *)LODWORD(szValue));
    return 1;
  }
  v9 = (float)atoi(nptr: (const char *)LODWORD(szValue));
  v10 = this->m_fAmplitude.m_Value == v9;
  szValue = v9;
  if ( v10 )
    return 1;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
    this->m_fAmplitude.m_Value = v9;
    return 1;
  }
  else
  {
    v11 = this->m_Network.m_pPev;
    if ( v11 != nullptr )
    {
      CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x3D4u);
      v9 = szValue;
    }
    this->m_fAmplitude.m_Value = v9;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011DAC0
// Name: public: void CEnvLaser::TurnOn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvLaser::TurnOn(CEnvLaser *this)
{
  unsigned int v2; // edi
  edict_t *m_pPev; // ecx
  CSprite *m_pSprite; // ecx

  v2 = this->m_fEffects.m_Value & 0xFFFFFFDF;
  if ( this->m_fEffects.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
    }
    this->m_fEffects.m_Value = v2;
  }
  if ( this->m_Network.m_pPev != nullptr )
    this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
  m_pSprite = this->m_pSprite;
  if ( m_pSprite != nullptr )
    CSprite::TurnOn(this: m_pSprite);
  this->m_flFireTime = gpGlobals->curtime;
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CEnvLaser::StrikeThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CEnvLaser::StrikeThink(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011DB60
// Name: public: void CEnvLaser::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvLaser::InputTurnOn(CEnvLaser *this, inputdata_t *inputdata)
{
  if ( (this->m_fEffects.m_Value & 0x20) != 0 )
    CEnvLaser::TurnOn(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011DB80
// Name: public: void CEnvLaser::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvLaser::InputToggle(CEnvLaser *this, inputdata_t *inputdata)
{
  CSprite *m_pSprite; // ecx

  if ( (this->m_fEffects.m_Value & 0x20) != 0 )
  {
    CEnvLaser::TurnOn(this);
  }
  else
  {
    CBaseEntity::AddEffects(this, nEffects: 32);
    m_pSprite = this->m_pSprite;
    if ( m_pSprite != nullptr )
      CSprite::TurnOff(this: m_pSprite);
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011DE10
// Name: public: virtual void CEnvLaser::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvLaser::Spawn(CEnvLaser *this)
{
  float m_Value; // xmm0_4
  float v3; // xmm1_4
  edict_t *m_pPev; // ecx
  const char *pszValue; // eax
  CSprite *m_pSprite; // ecx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // eax
  float v9; // [esp+10h] [ebp-4h] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  if ( *(_DWORD *)((int (__thiscall *)(CEnvLaser *, float *))this->GetModelName)(a1: this, a2: &v9) != 0 )
  {
    CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CEnvLaser::StrikeThink,
      thinkTime: 0.0,
      szContext: nullptr);
    m_Value = this->m_fWidth.m_Value;
    if ( m_Value > 102.3 )
      m_Value = 102.3;
    v3 = this->m_fEndWidth.m_Value;
    v9 = m_Value;
    if ( v3 != m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
        {
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3C8u);
          m_Value = v9;
        }
      }
      this->m_fEndWidth.m_Value = m_Value;
    }
    CBeam::PointsInit(this, start: &this->m_vecOrigin.m_Value, end: &this->m_vecOrigin.m_Value);
    this->Precache(this);
    if ( this->m_pSprite != nullptr || this->m_iszSpriteName.pszValue == nullptr )
    {
      this->m_pSprite = nullptr;
    }
    else
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      pszValue = this->m_iszSpriteName.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      this->m_pSprite = CSprite::SpriteCreate(pSpriteName: pszValue, origin: &this->m_vecAbsOrigin, animate: true);
    }
    m_pSprite = this->m_pSprite;
    if ( m_pSprite != nullptr )
    {
      m_Index = this->m_hMoveParent.m_Value.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      m_pSprite->SetParent(this: m_pSprite, a2: (CBaseEntity *)m_pEntity, a3: -1);
      CSprite::SetTransparency(
        this: this->m_pSprite,
        rendermode: 3u,
        r: this->m_clrRender.m_Value.r,
        g: this->m_clrRender.m_Value.g,
        b: this->m_clrRender.m_Value.b,
        a: this->m_clrRender.m_Value.a,
        fx: this->m_nRenderFX.m_Value);
    }
    if ( this->m_iName.m_Value.pszValue == nullptr || (this->m_spawnflags.m_Value & 1) != 0 )
      CEnvLaser::TurnOn(this);
    else
      CEnvLaser::TurnOff(this);
  }
  else
  {
    CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10402D30
// Name: CEnvLaser_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvLaser_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvLaser>(__formal: nullptr);
  CEnvLaser_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011DBE0
// Name: struct datamap_t __near * DataMapInit<class CEnvLaser>(class CEnvLaser __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvLaser>()
{
  if ( (_S2_96 & 1) == 0 )
  {
    _S2_96 |= 1u;
    nameHolder_176.m_pszBase = "CEnvLaser";
    nameHolder_176.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_176.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_176.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_176.m_Names.m_Size = 0;
    nameHolder_176.m_Names.m_pElements = nullptr;
    nameHolder_176.m_nLenBase = 9;
    atexit(func: DataMapInit_CEnvLaser__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvLaser::m_DataMap.baseMap = &CBeam::m_DataMap;
  if ( (_S2_96 & 2) == 0 )
  {
    _S2_96 |= 2u;
    dataDesc_166[6].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_176,
                                  pszIdentifier: "StrikeThink");
    *(_QWORD *)&dataDesc_166[6].td = 0;
    *(_QWORD *)&dataDesc_166[6].override_field = 0;
    *(_QWORD *)&dataDesc_166[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_166[6].flatOffset[1] = 0;
    dataDesc_166[6].fieldSize = 1;
    *(_QWORD *)&dataDesc_166[7].td = 0;
    *(_QWORD *)&dataDesc_166[7].override_field = 0;
    *(_QWORD *)&dataDesc_166[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_166[7].flatOffset[1] = 0;
    dataDesc_166[6].flags = 32;
    dataDesc_166[7].fieldSize = 1;
    *(_QWORD *)&dataDesc_166[8].td = 0;
    *(_QWORD *)&dataDesc_166[8].override_field = 0;
    *(_QWORD *)&dataDesc_166[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_166[8].flatOffset[1] = 0;
    dataDesc_166[6].fieldOffset = 0;
    dataDesc_166[6].externalName = nullptr;
    dataDesc_166[6].pSaveRestoreOps = nullptr;
    dataDesc_166[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvLaser::StrikeThink;
    dataDesc_166[7].fieldType = FIELD_VOID;
    dataDesc_166[7].fieldName = "InputTurnOn";
    dataDesc_166[7].fieldOffset = 0;
    dataDesc_166[7].flags = 8;
    dataDesc_166[7].externalName = "TurnOn";
    dataDesc_166[7].pSaveRestoreOps = nullptr;
    dataDesc_166[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvLaser::InputTurnOn;
    dataDesc_166[8].fieldType = FIELD_VOID;
    dataDesc_166[8].fieldName = "InputTurnOff";
    dataDesc_166[8].fieldOffset = 0;
    *(_DWORD *)&dataDesc_166[8].fieldSize = 524289;
    dataDesc_166[8].externalName = "TurnOff";
    dataDesc_166[8].pSaveRestoreOps = nullptr;
    dataDesc_166[8].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvLaser::InputTurnOff;
    dataDesc_166[9].fieldType = FIELD_VOID;
    dataDesc_166[9].fieldName = "InputToggle";
    dataDesc_166[9].fieldOffset = 0;
    *(_DWORD *)&dataDesc_166[9].fieldSize = 524289;
    dataDesc_166[9].externalName = "Toggle";
    dataDesc_166[9].pSaveRestoreOps = nullptr;
    dataDesc_166[9].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvLaser::InputToggle;
    *(_QWORD *)&dataDesc_166[9].td = 0;
    *(_QWORD *)&dataDesc_166[9].override_field = 0;
    *(_QWORD *)&dataDesc_166[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_166[9].flatOffset[1] = 0;
  }
  CEnvLaser::m_DataMap.dataNumFields = 9;
  CEnvLaser::m_DataMap.dataDesc = &dataDesc_166[1];
  return &CEnvLaser::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10402D40
// Name: _dynamic_initializer_for__env_message__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_message__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CMessage> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_message,
           a3: "env_message");
}
