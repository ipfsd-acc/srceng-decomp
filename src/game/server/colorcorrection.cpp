// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/colorcorrection.cpp
// Functions: 26
// ============================================================

#include "game\server\colorcorrection.h"

//------------------------------------------------------------------------------
// Address: 0x100F2B10
// Name: public: virtual struct datamap_t __near * CColorCorrection::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CColorCorrection::GetDataDescMap(CColorCorrection *this)
{
  return &CColorCorrection::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100F2B20
// Name: public: virtual class ServerClass __near * CColorCorrection::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CColorCorrection::GetServerClass(CColorCorrection *this)
{
  return &g_CColorCorrection_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x100F2B30
// Name: class CColorCorrectionSystem __near * ColorCorrectionSystem(void)
// Source: json
//------------------------------------------------------------------------------
CColorCorrectionSystem *__cdecl ColorCorrectionSystem()
{
  return &s_ColorCorrectionSystem;
}

//------------------------------------------------------------------------------
// Address: 0x100F2E10
// Name: private: void CColorCorrectionSystem::InitMasterController(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::InitMasterController(CColorCorrectionSystem *this)
{
  CBaseEntity *v2; // esi
  CBaseEntity *EntityByClassname; // eax
  unsigned int m_Index; // eax

  v2 = nullptr;
  while ( 1 )
  {
    EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                          this: &gEntList,
                          pStartEntity: v2,
                          szName: "color_correction");
    v2 = (CBaseEntity *)__RTDynamicCast(
                          inptr: EntityByClassname,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CColorCorrection `RTTI Type Descriptor',
                          isReference: 0);
    if ( v2 == nullptr )
      break;
    m_Index = this->m_hMasterController.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr
      || (v2->m_spawnflags.m_Value & 1) != 0 )
    {
      this->m_hMasterController.m_Index = v2->GetRefEHandle(this: v2)->m_Index;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F2EB0
// Name: public: virtual void CColorCorrectionSystem::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::FireGameEvent(CColorCorrectionSystem *this, IGameEvent *pEvent)
{
  CColorCorrectionSystem::InitMasterController(this: (CColorCorrectionSystem *)((char *)this - 12));
}

//------------------------------------------------------------------------------
// Address: 0x100F2EC0
// Name: public: virtual void CColorCorrectionSystem::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::LevelInitPostEntity(CColorCorrectionSystem *this)
{
  CBasePlayer *LocalPlayer; // eax
  unsigned int m_Index; // esi

  CColorCorrectionSystem::InitMasterController(this);
  if ( gpGlobals->maxClients == 1 )
  {
    LocalPlayer = UTIL_GetLocalPlayer();
    if ( LocalPlayer != nullptr )
    {
      m_Index = LocalPlayer->m_hColorCorrectionCtrl.m_Value.m_Index;
      if ( m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
      {
        CBasePlayer::InitColorCorrectionController(this: LocalPlayer);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F2FA0
// Name: public: virtual void CColorCorrection::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrection::Activate(CColorCorrection *this)
{
  const char *pszValue; // edi
  CColorCorrection::NetworkVar_m_netlookupFilename *p_m_netlookupFilename; // esi
  CBaseEdict *v4; // ecx

  CBaseEntity::Activate(this);
  pszValue = this->m_lookupFilename.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  p_m_netlookupFilename = &this->m_netlookupFilename;
  if ( p_m_netlookupFilename[-4].m_Value[224] != 0 )
  {
    p_m_netlookupFilename[-4].m_Value[228] |= 1u;
    V_strncpy(pDest: p_m_netlookupFilename->m_Value, pSrc: pszValue, maxLen: 260);
  }
  else
  {
    v4 = *(CBaseEdict **)&p_m_netlookupFilename[-4].m_Value[164];
    if ( v4 != nullptr )
    {
      v4->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: v4)->m_iChangeInfoSerialNumber = 0;
    }
    V_strncpy(pDest: p_m_netlookupFilename->m_Value, pSrc: pszValue, maxLen: 260);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F3010
// Name: private: void CColorCorrection::FadeInThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrection::FadeInThink(CColorCorrection *this)
{
  float v2; // xmm2_4
  float m_Value; // xmm3_4
  float m_flStartFadeInWeight; // xmm0_4
  float *p_m_flStartFadeInWeight; // esi
  float v6; // xmm0_4
  edict_t *m_pPev; // ecx
  float v8; // [esp+14h] [ebp-14h]
  float flTimeToFade; // [esp+18h] [ebp-10h] BYREF
  float flWeightRatio; // [esp+1Ch] [ebp-Ch] BYREF
  float minVal; // [esp+20h] [ebp-8h] BYREF
  float flFadeRatio; // [esp+24h] [ebp-4h] BYREF

  flTimeToFade = this->m_flFadeInDuration.m_Value;
  v2 = flTimeToFade;
  if ( flTimeToFade <= 0.0
    || (m_Value = this->m_flMaxWeight.m_Value, this->m_flCurWeight.m_Value >= m_Value)
    || !this->m_bEnabled.m_Value
    || m_Value == 0.0
    || (m_flStartFadeInWeight = this->m_flStartFadeInWeight,
        p_m_flStartFadeInWeight = &this->m_flStartFadeInWeight,
        m_flStartFadeInWeight >= m_Value) )
  {
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: s_pFadeInContextThink);
  }
  else
  {
    if ( m_flStartFadeInWeight > 0.0 )
    {
      flWeightRatio = m_flStartFadeInWeight / m_Value;
      flFadeRatio = 0.99000001;
      minVal = 0.0;
      flTimeToFade = (1.0 - clamp<float,float,float>(val: &flWeightRatio, &minVal, maxVal: &flFadeRatio)) * flTimeToFade;
      v2 = flTimeToFade;
    }
    flFadeRatio = (float)(gpGlobals->curtime - this->m_flTimeStartFadeIn) / v2;
    flTimeToFade = 1.0;
    flWeightRatio = 0.0;
    flFadeRatio = clamp<float,float,float>(val: &flFadeRatio, minVal: &flWeightRatio, maxVal: &flTimeToFade);
    flTimeToFade = 1.0;
    flWeightRatio = 0.0;
    *p_m_flStartFadeInWeight = clamp<float,float,float>(
                                 val: &this->m_flStartFadeInWeight,
                                 minVal: &flWeightRatio,
                                 maxVal: &flTimeToFade);
    v8 = (float)((float)(m_Value - *p_m_flStartFadeInWeight) * flFadeRatio) + *p_m_flStartFadeInWeight;
    v6 = v8;
    if ( this->m_flCurWeight.m_Value != v8 )
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
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x380u);
          v6 = v8;
        }
      }
      this->m_flCurWeight.m_Value = v6;
    }
    CBaseEntity::SetNextThink(
      this,
      thinkTime: gpGlobals->interval_per_tick + gpGlobals->curtime,
      szContext: s_pFadeInContextThink);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F31E0
// Name: private: void CColorCorrection::FadeOutThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrection::FadeOutThink(CColorCorrection *this)
{
  float v2; // xmm3_4
  float v3; // xmm1_4
  float m_flStartFadeOutWeight; // xmm0_4
  float *p_m_flStartFadeOutWeight; // esi
  float v6; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *m_pPev; // ecx
  float flTimeToFade; // [esp+14h] [ebp-10h] BYREF
  float flWeightRatio; // [esp+18h] [ebp-Ch] BYREF
  float minVal; // [esp+1Ch] [ebp-8h] BYREF
  float flFadeRatio; // [esp+20h] [ebp-4h] BYREF

  flTimeToFade = this->m_flFadeOutDuration.m_Value;
  v2 = flTimeToFade;
  if ( flTimeToFade <= 0.0
    || this->m_flCurWeight.m_Value <= 0.0
    || this->m_bEnabled.m_Value
    || (v3 = this->m_flMaxWeight.m_Value) == 0.0
    || (m_flStartFadeOutWeight = this->m_flStartFadeOutWeight,
        p_m_flStartFadeOutWeight = &this->m_flStartFadeOutWeight,
        m_flStartFadeOutWeight <= 0.0) )
  {
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: s_pFadeOutContextThink);
  }
  else
  {
    if ( v3 > m_flStartFadeOutWeight )
    {
      flWeightRatio = m_flStartFadeOutWeight / v3;
      flFadeRatio = 1.0;
      minVal = 0.0099999998;
      flTimeToFade = clamp<float,float,float>(val: &flWeightRatio, &minVal, maxVal: &flFadeRatio) * flTimeToFade;
      v2 = flTimeToFade;
    }
    flFadeRatio = (float)(gpGlobals->curtime - this->m_flTimeStartFadeOut) / v2;
    flTimeToFade = 1.0;
    flWeightRatio = 0.0;
    flFadeRatio = clamp<float,float,float>(val: &flFadeRatio, minVal: &flWeightRatio, maxVal: &flTimeToFade);
    flTimeToFade = 1.0;
    flWeightRatio = 0.0;
    flTimeToFade = clamp<float,float,float>(
                     val: &this->m_flStartFadeOutWeight,
                     minVal: &flWeightRatio,
                     maxVal: &flTimeToFade);
    *p_m_flStartFadeOutWeight = flTimeToFade;
    m_Value = this->m_flCurWeight.m_Value;
    flTimeToFade = (float)(1.0 - flFadeRatio) * flTimeToFade;
    v6 = flTimeToFade;
    if ( m_Value != flTimeToFade )
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
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x380u);
          v6 = flTimeToFade;
        }
      }
      this->m_flCurWeight.m_Value = v6;
    }
    CBaseEntity::SetNextThink(
      this,
      thinkTime: gpGlobals->interval_per_tick + gpGlobals->curtime,
      szContext: s_pFadeOutContextThink);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F33B0
// Name: public: CColorCorrection::CColorCorrection(void)
// Source: json
//------------------------------------------------------------------------------
CColorCorrection *__thiscall CColorCorrection::CColorCorrection(CColorCorrection *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  edict_t *v7; // ecx
  edict_t *v8; // ecx
  edict_t *v9; // ecx
  edict_t *v10; // ecx
  edict_t *v11; // ecx
  CColorCorrection *result; // eax
  edict_t *v13; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CColorCorrection_vtbl *)&CColorCorrection::`vftable';
  if ( !this->m_bEnabled.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x371u);
    }
    this->m_bEnabled.m_Value = true;
  }
  if ( this->m_MinFalloff.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x378u);
    }
    this->m_MinFalloff.m_Value = 0.0;
  }
  if ( this->m_MaxFalloff.m_Value != 1000.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x37Cu);
    }
    this->m_MaxFalloff.m_Value = 1000.0;
  }
  if ( this->m_flMaxWeight.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x36Cu);
    }
    this->m_flMaxWeight.m_Value = 1.0;
  }
  if ( this->m_flCurWeight.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x380u);
    }
    this->m_flCurWeight.m_Value = 0.0;
  }
  if ( this->m_flFadeInDuration.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x354u);
    }
    this->m_flFadeInDuration.m_Value = 0.0;
  }
  if ( this->m_flFadeOutDuration.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x358u);
    }
    this->m_flFadeOutDuration.m_Value = 0.0;
  }
  this->m_flStartFadeInWeight = 0.0;
  this->m_flStartFadeOutWeight = 0.0;
  this->m_flTimeStartFadeIn = 0.0;
  this->m_flTimeStartFadeOut = 0.0;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v9 = this->m_Network.m_pPev;
    if ( v9 != nullptr )
    {
      v9->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &v9->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
  }
  this->m_netlookupFilename.m_Value[0] = 0;
  this->m_lookupFilename.pszValue = nullptr;
  if ( this->m_bMaster.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x372u);
    }
    this->m_bMaster.m_Value = false;
  }
  if ( this->m_bClientSide.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x373u);
    }
    this->m_bClientSide.m_Value = false;
  }
  result = this;
  if ( this->m_bExclusive.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bExclusive.m_Value = false;
    }
    else
    {
      v13 = this->m_Network.m_pPev;
      if ( v13 != nullptr )
        CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x374u);
      this->m_bExclusive.m_Value = false;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F3690
// Name: public: virtual void CColorCorrection::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrection::Spawn(CColorCorrection *this)
{
  edict_t *m_pPev; // ecx
  float v3; // xmm0_4
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  bool v7; // bl
  edict_t *v8; // ecx
  bool v9; // bl
  edict_t *v10; // ecx

  this->m_iEFlags |= 0x880u;
  CBaseEntity::DispatchUpdateTransmitState(this);
  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CColorCorrection::FadeInThink,
    thinkTime: -1.0,
    szContext: s_pFadeInContextThink);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CColorCorrection::FadeOutThink,
    thinkTime: -1.0,
    szContext: s_pFadeOutContextThink);
  if ( this->m_bStartDisabled )
  {
    if ( this->m_bEnabled.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x371u);
      }
      this->m_bEnabled.m_Value = false;
    }
    if ( this->m_flCurWeight.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        v3 = 0.0;
      }
      else
      {
        v4 = this->m_Network.m_pPev;
        if ( v4 != nullptr )
          CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x380u);
        v3 = 0.0;
      }
LABEL_26:
      this->m_flCurWeight.m_Value = v3;
    }
  }
  else
  {
    if ( !this->m_bEnabled.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v5 = this->m_Network.m_pPev;
        if ( v5 != nullptr )
          CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x371u);
      }
      this->m_bEnabled.m_Value = true;
    }
    if ( this->m_flCurWeight.m_Value != 1.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v6 = this->m_Network.m_pPev;
        if ( v6 != nullptr )
          CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x380u);
      }
      v3 = 1.0;
      goto LABEL_26;
    }
  }
  v7 = this->m_spawnflags.m_Value & 1;
  if ( this->m_bMaster.m_Value != v7 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x372u);
    }
    this->m_bMaster.m_Value = v7;
  }
  v9 = (this->m_spawnflags.m_Value & 2) != 0;
  if ( this->m_bClientSide.m_Value != v9 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bClientSide.m_Value = v9;
      CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
      return;
    }
    v10 = this->m_Network.m_pPev;
    if ( v10 != nullptr )
      CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x373u);
    this->m_bClientSide.m_Value = v9;
  }
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100F3890
// Name: private: void CColorCorrection::FadeIn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrection::FadeIn(CColorCorrection *this)
{
  edict_t *m_pPev; // ecx
  const char *v3; // ecx

  if ( !this->m_bClientSide.m_Value
    && (!this->m_bEnabled.m_Value || this->m_flCurWeight.m_Value < this->m_flMaxWeight.m_Value) )
  {
    if ( !this->m_bEnabled.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x371u);
      }
      this->m_bEnabled.m_Value = true;
    }
    v3 = s_pFadeInContextThink;
    this->m_flTimeStartFadeIn = gpGlobals->curtime;
    this->m_flStartFadeInWeight = this->m_flCurWeight.m_Value;
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->interval_per_tick + gpGlobals->curtime, szContext: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F3930
// Name: private: void CColorCorrection::FadeOut(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrection::FadeOut(CColorCorrection *this)
{
  edict_t *m_pPev; // ecx
  const char *v3; // ecx

  if ( !this->m_bClientSide.m_Value )
  {
    if ( this->m_bEnabled.m_Value )
      goto LABEL_5;
    if ( this->m_flCurWeight.m_Value <= 0.0 )
      return;
    if ( this->m_bEnabled.m_Value )
    {
LABEL_5:
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x371u);
      }
      this->m_bEnabled.m_Value = false;
    }
    v3 = s_pFadeOutContextThink;
    this->m_flTimeStartFadeOut = gpGlobals->curtime;
    this->m_flStartFadeOutWeight = this->m_flCurWeight.m_Value;
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->interval_per_tick + gpGlobals->curtime, szContext: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F39D0
// Name: public: void CColorCorrection::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrection::InputEnable(CColorCorrection *this, inputdata_t *inputdata)
{
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx

  if ( !this->m_bEnabled.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x371u);
    }
    this->m_bEnabled.m_Value = true;
  }
  if ( this->m_flFadeInDuration.m_Value <= 0.0 )
  {
    if ( this->m_flCurWeight.m_Value != this->m_flMaxWeight.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flCurWeight.m_Value = this->m_flMaxWeight.m_Value;
      }
      else
      {
        v4 = this->m_Network.m_pPev;
        if ( v4 != nullptr )
          CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x380u);
        this->m_flCurWeight.m_Value = this->m_flMaxWeight.m_Value;
      }
    }
  }
  else
  {
    CColorCorrection::FadeIn(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F3A80
// Name: public: void CColorCorrection::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrection::InputDisable(CColorCorrection *this, inputdata_t *inputdata)
{
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx

  if ( this->m_bEnabled.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x371u);
    }
    this->m_bEnabled.m_Value = false;
  }
  if ( this->m_flFadeOutDuration.m_Value <= 0.0 )
  {
    if ( this->m_flCurWeight.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flCurWeight.m_Value = 0.0;
      }
      else
      {
        v4 = this->m_Network.m_pPev;
        if ( v4 != nullptr )
          CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x380u);
        this->m_flCurWeight.m_Value = 0.0;
      }
    }
  }
  else
  {
    CColorCorrection::FadeOut(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F3B30
// Name: public: void CColorCorrection::InputSetFadeInDuration(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrection::InputSetFadeInDuration(CColorCorrection *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CColorCorrection::NetworkVar_m_flFadeInDuration> *p_m_flFadeInDuration; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_flFadeInDuration = &this->m_flFadeInDuration;
  if ( this->m_flFadeInDuration.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flFadeInDuration->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
      p_m_flFadeInDuration->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F3BB0
// Name: public: void CColorCorrection::InputSetFadeOutDuration(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrection::InputSetFadeOutDuration(CColorCorrection *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CColorCorrection::NetworkVar_m_flFadeOutDuration> *p_m_flFadeOutDuration; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_flFadeOutDuration = &this->m_flFadeOutDuration;
  if ( this->m_flFadeOutDuration.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flFadeOutDuration->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x358u);
      p_m_flFadeOutDuration->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10401380
// Name: CColorCorrection_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CColorCorrection_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CColorCorrection>();
  CColorCorrection_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104013B0
// Name: DT_ColorCorrection::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ColorCorrection::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_ColorCorrection::g_SendTable);
  return atexit(func: DT_ColorCorrection::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104013D0
// Name: DT_ColorCorrection::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ColorCorrection::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_ColorCorrection::ignored>();
  DT_ColorCorrection::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041A4A0
// Name: DT_ColorCorrection::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ColorCorrection::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_ColorCorrection::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10401390
// Name: _dynamic_initializer_for__g_CColorCorrection_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CColorCorrection_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CColorCorrection_ClassReg,
           pNetworkName: "CColorCorrection",
           pTable: &DT_ColorCorrection::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104013E0
// Name: _dynamic_initializer_for__s_ColorCorrectionSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ColorCorrectionSystem__()
{
  CAutoGameSystem::CAutoGameSystem(this: &s_ColorCorrectionSystem, name: "ColorCorrectionSystem");
  s_ColorCorrectionSystem.m_bRegisteredForEvents = false;
  s_ColorCorrectionSystem.m_nDebugID = 42;
  s_ColorCorrectionSystem.CAutoGameSystem::CBaseGameSystem::IGameSystem::__vftable = (CColorCorrectionSystem_vtbl *)&CColorCorrectionSystem::`vftable'{for `CAutoGameSystem'};
  s_ColorCorrectionSystem.CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CColorCorrectionSystem::`vftable'{for `CGameEventListener'};
  s_ColorCorrectionSystem.m_hMasterController.m_Index = -1;
  return atexit(func: dynamic_atexit_destructor_for__s_ColorCorrectionSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x1041A4B0
// Name: _ServerClassInit_DT_ColorCorrection::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_ColorCorrection::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_35;
  for ( i = 12; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041A4D0
// Name: _dynamic_atexit_destructor_for__s_ColorCorrectionSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ColorCorrectionSystem__()
{
  s_ColorCorrectionSystem.CAutoGameSystem::CBaseGameSystem::IGameSystem::__vftable = (CColorCorrectionSystem_vtbl *)&CColorCorrectionSystem::`vftable'{for `CAutoGameSystem'};
  s_ColorCorrectionSystem.m_hMasterController.m_Index = -1;
  s_ColorCorrectionSystem.CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  s_ColorCorrectionSystem.m_nDebugID = 13;
  if ( s_ColorCorrectionSystem.m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: &s_ColorCorrectionSystem.CGameEventListener);
    s_ColorCorrectionSystem.m_bRegisteredForEvents = false;
  }
  s_ColorCorrectionSystem.CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&IGameEventListener2::`vftable';
  IGameSystem::~IGameSystem(this: &s_ColorCorrectionSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1041A540
// Name: _DataMapInit_CColorCorrection__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CColorCorrection__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_118);
}
