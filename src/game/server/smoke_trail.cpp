// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/smoke_trail.cpp
// Functions: 74
// ============================================================

#include "game\server\smoke_trail.h"

//------------------------------------------------------------------------------
// Address: 0x103262A0
// Name: public: virtual class ServerClass __near * SmokeTrail::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall SmokeTrail::GetServerClass(SmokeTrail *this)
{
  return &g_SmokeTrail_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x103262B0
// Name: private: virtual struct datamap_t __near * SmokeTrail::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall SmokeTrail::GetDataDescMap(SmokeTrail *this)
{
  return &SmokeTrail::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103262C0
// Name: public: virtual class ServerClass __near * RocketTrail::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall RocketTrail::GetServerClass(RocketTrail *this)
{
  return &g_RocketTrail_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x103262D0
// Name: private: virtual struct datamap_t __near * RocketTrail::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall RocketTrail::GetDataDescMap(RocketTrail *this)
{
  return &RocketTrail::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103262E0
// Name: public: virtual class ServerClass __near * SporeTrail::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall SporeTrail::GetServerClass(SporeTrail *this)
{
  return &g_SporeTrail_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x103262F0
// Name: private: virtual struct datamap_t __near * SporeTrail::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall SporeTrail::GetDataDescMap(SporeTrail *this)
{
  return &SporeTrail::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10326300
// Name: public: virtual class ServerClass __near * SporeExplosion::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall SporeExplosion::GetServerClass(SporeExplosion *this)
{
  return &g_SporeExplosion_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10326310
// Name: private: virtual struct datamap_t __near * SporeExplosion::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall SporeExplosion::GetDataDescMap(SporeExplosion *this)
{
  return &SporeExplosion::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10326320
// Name: private: virtual struct datamap_t __near * CFireTrail::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFireTrail::GetDataDescMap(CFireTrail *this)
{
  return &CFireTrail::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10326330
// Name: public: virtual class ServerClass __near * CFireTrail::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFireTrail::GetServerClass(CFireTrail *this)
{
  return &g_CFireTrail_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10326340
// Name: public: virtual void CFireTrail::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFireTrail::Precache(CFireTrail *this)
{
  PrecacheMaterial(pMaterialName: "sprites/flamelet1");
  PrecacheMaterial(pMaterialName: "sprites/flamelet2");
  PrecacheMaterial(pMaterialName: "sprites/flamelet3");
  PrecacheMaterial(pMaterialName: "sprites/flamelet4");
  PrecacheMaterial(pMaterialName: "sprites/flamelet5");
  PrecacheMaterial(pMaterialName: "particle/particle_smokegrenade");
  PrecacheMaterial(pMaterialName: "particle/particle_noisesphere");
}

//------------------------------------------------------------------------------
// Address: 0x10326390
// Name: public: virtual class ServerClass __near * DustTrail::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall DustTrail::GetServerClass(DustTrail *this)
{
  return &g_DustTrail_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x103263A0
// Name: private: virtual struct datamap_t __near * DustTrail::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall DustTrail::GetDataDescMap(DustTrail *this)
{
  return &DustTrail::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10327480
// Name: public: SmokeTrail::SmokeTrail(void)
// Source: json
//------------------------------------------------------------------------------
SmokeTrail *__thiscall SmokeTrail::SmokeTrail(SmokeTrail *this)
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
  edict_t *v12; // ecx
  edict_t *v13; // ecx
  edict_t *v14; // ecx
  edict_t *v15; // ecx
  SmokeTrail *result; // eax
  edict_t *v17; // ecx

  CBaseParticleEntity::CBaseParticleEntity(this);
  this->__vftable = (SmokeTrail_vtbl *)&SmokeTrail::`vftable';
  if ( this->m_SpawnRate.m_Value != 10.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
    }
    this->m_SpawnRate.m_Value = 10.0;
  }
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v3 = this->m_Network.m_pPev;
    if ( v3 != nullptr )
      CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x354u);
  }
  this->m_StartColor.m_Value.x = 0.5;
  this->m_StartColor.m_Value.y = 0.5;
  this->m_StartColor.m_Value.z = 0.5;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v4 = this->m_Network.m_pPev;
    if ( v4 != nullptr )
      CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x360u);
  }
  this->m_EndColor.m_Value.x = 0.0;
  this->m_EndColor.m_Value.y = 0.0;
  this->m_EndColor.m_Value.z = 0.0;
  if ( this->m_ParticleLifetime.m_Value != 5.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x374u);
    }
    this->m_ParticleLifetime.m_Value = 5.0;
  }
  if ( this->m_StopEmitTime.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x378u);
    }
    this->m_StopEmitTime.m_Value = 0.0;
  }
  if ( this->m_MinSpeed.m_Value != 2.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x37Cu);
    }
    this->m_MinSpeed.m_Value = 2.0;
  }
  if ( this->m_MaxSpeed.m_Value != 4.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x380u);
    }
    this->m_MaxSpeed.m_Value = 4.0;
  }
  if ( this->m_MaxDirectedSpeed.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x394u);
    }
    this->m_MaxDirectedSpeed.m_Value = 0.0;
  }
  if ( this->m_MinDirectedSpeed.m_Value != this->m_MaxDirectedSpeed.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x390u);
    }
    this->m_MinDirectedSpeed.m_Value = this->m_MaxDirectedSpeed.m_Value;
  }
  if ( this->m_StartSize.m_Value != 35.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x384u);
    }
    this->m_StartSize.m_Value = 35.0;
  }
  if ( this->m_EndSize.m_Value != 55.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v12 = this->m_Network.m_pPev;
      if ( v12 != nullptr )
        CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x388u);
    }
    this->m_EndSize.m_Value = 55.0;
  }
  if ( this->m_SpawnRadius.m_Value != 2.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v13 = this->m_Network.m_pPev;
      if ( v13 != nullptr )
        CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x38Cu);
    }
    this->m_SpawnRadius.m_Value = 2.0;
  }
  if ( !this->m_bEmit.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v14 = this->m_Network.m_pPev;
      if ( v14 != nullptr )
        CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x398u);
    }
    this->m_bEmit.m_Value = true;
  }
  if ( this->m_nAttachment.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v15 = this->m_Network.m_pPev;
      if ( v15 != nullptr )
        CBaseEdict::StateChanged(this: &v15->CBaseEdict, offset: 0x39Cu);
    }
    this->m_nAttachment.m_Value = 0;
  }
  result = this;
  if ( this->m_Opacity.m_Value != 0.5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v17 = this->m_Network.m_pPev;
      if ( v17 != nullptr )
        CBaseEdict::StateChanged(this: &v17->CBaseEdict, offset: 0x36Cu);
    }
    this->m_Opacity.m_Value = 0.5;
    return this;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103278C0
// Name: public: virtual bool SmokeTrail::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SmokeTrail::KeyValue(SmokeTrail *this, char *szKeyName, float szValue)
{
  edict_t *v4; // ecx
  unsigned __int8 v5; // ah
  int v6; // edx
  int v7; // eax
  edict_t *v9; // ecx
  unsigned __int8 v10; // ah
  int v11; // edx
  int v12; // eax
  long double v13; // st7
  edict_t *m_pPev; // ecx

  if ( szKeyName != "startcolor" && _V_stricmp(s1: szKeyName, s2: "startcolor") != 0 )
  {
    if ( szKeyName != "endcolor" && _V_stricmp(s1: szKeyName, s2: "endcolor") != 0 )
    {
      if ( szKeyName != "emittime" && _V_stricmp(s1: szKeyName, s2: "emittime") != 0 )
      {
        return CBaseEntity::KeyValue(this, szKeyName, szValue: (const char *)LODWORD(szValue));
      }
      else
      {
        v13 = atof(nptr: (const char *)LODWORD(szValue)) + gpGlobals->curtime;
        szValue = v13;
        if ( this->m_StopEmitTime.m_Value != v13 )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
            this->m_StopEmitTime.m_Value = szValue;
            return true;
          }
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x378u);
          this->m_StopEmitTime.m_Value = szValue;
        }
        return true;
      }
    }
    else
    {
      V_StringToColor32(color: (color32_s *)&szValue, pString: (const char *)LODWORD(szValue));
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v9 = this->m_Network.m_pPev;
        if ( v9 != nullptr )
          CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x360u);
      }
      v10 = BYTE1(szValue);
      this->m_EndColor.m_Value.x = (float)LOBYTE(szValue) * 0.0039215689;
      v11 = v10;
      v12 = BYTE2(szValue);
      this->m_EndColor.m_Value.y = (float)v11 * 0.0039215689;
      this->m_EndColor.m_Value.z = (float)v12 * 0.0039215689;
      return true;
    }
  }
  else
  {
    V_StringToColor32(color: (color32_s *)&szValue, pString: (const char *)LODWORD(szValue));
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x354u);
    }
    v5 = BYTE1(szValue);
    this->m_StartColor.m_Value.x = (float)LOBYTE(szValue) * 0.0039215689;
    v6 = v5;
    v7 = BYTE2(szValue);
    this->m_StartColor.m_Value.y = (float)v6 * 0.0039215689;
    this->m_StartColor.m_Value.z = (float)v7 * 0.0039215689;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10327AC0
// Name: public: RocketTrail::RocketTrail(void)
// Source: json
//------------------------------------------------------------------------------
RocketTrail *__thiscall RocketTrail::RocketTrail(RocketTrail *this)
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
  edict_t *v12; // ecx
  edict_t *v13; // ecx
  edict_t *v14; // ecx
  RocketTrail *result; // eax
  edict_t *v16; // ecx

  CBaseParticleEntity::CBaseParticleEntity(this);
  this->__vftable = (RocketTrail_vtbl *)&RocketTrail::`vftable';
  if ( this->m_SpawnRate.m_Value != 10.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
    }
    this->m_SpawnRate.m_Value = 10.0;
  }
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v3 = this->m_Network.m_pPev;
    if ( v3 != nullptr )
      CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x354u);
  }
  this->m_StartColor.m_Value.x = 0.5;
  this->m_StartColor.m_Value.y = 0.5;
  this->m_StartColor.m_Value.z = 0.5;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v4 = this->m_Network.m_pPev;
    if ( v4 != nullptr )
      CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x360u);
  }
  this->m_EndColor.m_Value.x = 0.0;
  this->m_EndColor.m_Value.y = 0.0;
  this->m_EndColor.m_Value.z = 0.0;
  if ( this->m_ParticleLifetime.m_Value != 5.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x374u);
    }
    this->m_ParticleLifetime.m_Value = 5.0;
  }
  if ( this->m_StopEmitTime.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x378u);
    }
    this->m_StopEmitTime.m_Value = 0.0;
  }
  if ( this->m_MinSpeed.m_Value != 2.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x37Cu);
    }
    this->m_MinSpeed.m_Value = 2.0;
  }
  if ( this->m_MaxSpeed.m_Value != 4.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x380u);
    }
    this->m_MaxSpeed.m_Value = 4.0;
  }
  if ( this->m_StartSize.m_Value != 35.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x384u);
    }
    this->m_StartSize.m_Value = 35.0;
  }
  if ( this->m_EndSize.m_Value != 55.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x388u);
    }
    this->m_EndSize.m_Value = 55.0;
  }
  if ( this->m_SpawnRadius.m_Value != 2.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x38Cu);
    }
    this->m_SpawnRadius.m_Value = 2.0;
  }
  if ( !this->m_bEmit.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v12 = this->m_Network.m_pPev;
      if ( v12 != nullptr )
        CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x390u);
    }
    this->m_bEmit.m_Value = true;
  }
  if ( this->m_nAttachment.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v13 = this->m_Network.m_pPev;
      if ( v13 != nullptr )
        CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x394u);
    }
    this->m_nAttachment.m_Value = 0;
  }
  if ( this->m_Opacity.m_Value != 0.5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v14 = this->m_Network.m_pPev;
      if ( v14 != nullptr )
        CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x36Cu);
    }
    this->m_Opacity.m_Value = 0.5;
  }
  result = this;
  if ( this->m_flFlareScale.m_Value != 1.5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v16 = this->m_Network.m_pPev;
      if ( v16 != nullptr )
        CBaseEdict::StateChanged(this: &v16->CBaseEdict, offset: 0x39Cu);
    }
    this->m_flFlareScale.m_Value = 1.5;
    return this;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10327E80
// Name: public: virtual void SporeExplosion::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SporeExplosion::Spawn(SporeExplosion *this)
{
  edict_t *m_pPev; // ecx

  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  if ( this->m_bEmit.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bEmit.m_Value = false;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Cu);
      this->m_bEmit.m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10327ED0
// Name: public: void SporeExplosion::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SporeExplosion::InputEnable(SporeExplosion *this, inputdata_t *inputdata)
{
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx

  if ( !this->m_bDontRemove.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Du);
    }
    this->m_bDontRemove.m_Value = true;
  }
  this->m_bDisabled = false;
  if ( !this->m_bEmit.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bEmit.m_Value = true;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x36Cu);
      this->m_bEmit.m_Value = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10327F50
// Name: public: void SporeExplosion::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SporeExplosion::InputDisable(SporeExplosion *this, inputdata_t *inputdata)
{
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx

  if ( !this->m_bDontRemove.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Du);
    }
    this->m_bDontRemove.m_Value = true;
  }
  this->m_bDisabled = true;
  if ( this->m_bEmit.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bEmit.m_Value = false;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x36Cu);
      this->m_bEmit.m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10327FD0
// Name: public: DustTrail::DustTrail(void)
// Source: json
//------------------------------------------------------------------------------
DustTrail *__thiscall DustTrail::DustTrail(DustTrail *this)
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
  edict_t *v12; // ecx
  edict_t *v13; // ecx
  DustTrail *result; // eax
  edict_t *v15; // ecx

  CBaseParticleEntity::CBaseParticleEntity(this);
  this->__vftable = (DustTrail_vtbl *)&DustTrail::`vftable';
  if ( this->m_SpawnRate.m_Value != 10.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x364u);
    }
    this->m_SpawnRate.m_Value = 10.0;
  }
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v3 = this->m_Network.m_pPev;
    if ( v3 != nullptr )
      CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x354u);
  }
  this->m_Color.m_Value.x = 0.5;
  this->m_Color.m_Value.y = 0.5;
  this->m_Color.m_Value.z = 0.5;
  if ( this->m_ParticleLifetime.m_Value != 5.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x368u);
    }
    this->m_ParticleLifetime.m_Value = 5.0;
  }
  if ( this->m_StopEmitTime.m_Value != 0.0 )
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
    this->m_StopEmitTime.m_Value = 0.0;
  }
  if ( this->m_MinSpeed.m_Value != 2.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x370u);
    }
    this->m_MinSpeed.m_Value = 2.0;
  }
  if ( this->m_MaxSpeed.m_Value != 4.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x374u);
    }
    this->m_MaxSpeed.m_Value = 4.0;
  }
  if ( this->m_MaxDirectedSpeed.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x388u);
    }
    this->m_MaxDirectedSpeed.m_Value = 0.0;
  }
  if ( this->m_MinDirectedSpeed.m_Value != this->m_MaxDirectedSpeed.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x384u);
    }
    this->m_MinDirectedSpeed.m_Value = this->m_MaxDirectedSpeed.m_Value;
  }
  if ( this->m_StartSize.m_Value != 35.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x378u);
    }
    this->m_StartSize.m_Value = 35.0;
  }
  if ( this->m_EndSize.m_Value != 55.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x37Cu);
    }
    this->m_EndSize.m_Value = 55.0;
  }
  if ( this->m_SpawnRadius.m_Value != 2.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v12 = this->m_Network.m_pPev;
      if ( v12 != nullptr )
        CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x380u);
    }
    this->m_SpawnRadius.m_Value = 2.0;
  }
  if ( !this->m_bEmit.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v13 = this->m_Network.m_pPev;
      if ( v13 != nullptr )
        CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x38Cu);
    }
    this->m_bEmit.m_Value = true;
  }
  result = this;
  if ( this->m_Opacity.m_Value != 0.5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v15 = this->m_Network.m_pPev;
      if ( v15 != nullptr )
        CBaseEdict::StateChanged(this: &v15->CBaseEdict, offset: 0x360u);
    }
    this->m_Opacity.m_Value = 0.5;
    return this;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10328370
// Name: public: virtual bool DustTrail::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall DustTrail::KeyValue(DustTrail *this, char *szKeyName, float szValue)
{
  edict_t *v4; // ecx
  unsigned __int8 v5; // ah
  int v6; // edx
  int v7; // eax
  long double v9; // st7
  edict_t *m_pPev; // ecx

  if ( szKeyName != "color" && _V_stricmp(s1: szKeyName, s2: "color") != 0 )
  {
    if ( szKeyName != "emittime" && _V_stricmp(s1: szKeyName, s2: "emittime") != 0 )
    {
      return CBaseEntity::KeyValue(this, szKeyName, szValue: (const char *)LODWORD(szValue));
    }
    else
    {
      v9 = atof(nptr: (const char *)LODWORD(szValue)) + gpGlobals->curtime;
      szValue = v9;
      if ( this->m_StopEmitTime.m_Value != v9 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_StopEmitTime.m_Value = szValue;
          return true;
        }
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Cu);
        this->m_StopEmitTime.m_Value = szValue;
      }
      return true;
    }
  }
  else
  {
    V_StringToColor32(color: (color32_s *)&szValue, pString: (const char *)LODWORD(szValue));
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x354u);
    }
    v5 = BYTE1(szValue);
    this->m_Color.m_Value.x = (float)LOBYTE(szValue) * 0.0039215689;
    v6 = v5;
    v7 = BYTE2(szValue);
    this->m_Color.m_Value.y = (float)v6 * 0.0039215689;
    this->m_Color.m_Value.z = (float)v7 * 0.0039215689;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10328700
// Name: public: SporeTrail::SporeTrail(void)
// Source: json
//------------------------------------------------------------------------------
SporeTrail *__thiscall SporeTrail::SporeTrail(SporeTrail *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  edict_t *v7; // ecx
  SporeTrail *result; // eax
  edict_t *v9; // ecx

  CBaseParticleEntity::CBaseParticleEntity(this);
  this->__vftable = (SporeTrail_vtbl *)&SporeTrail::`vftable';
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
  }
  this->m_vecEndColor.m_Value.x = 0.0;
  this->m_vecEndColor.m_Value.y = 0.0;
  this->m_vecEndColor.m_Value.z = 0.0;
  if ( this->m_flSpawnRate.m_Value != 100.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x360u);
    }
    this->m_flSpawnRate.m_Value = 100.0;
  }
  if ( this->m_flParticleLifetime.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x364u);
    }
    this->m_flParticleLifetime.m_Value = 1.0;
  }
  if ( this->m_flStartSize.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x368u);
    }
    this->m_flStartSize.m_Value = 1.0;
  }
  if ( this->m_flEndSize.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x36Cu);
    }
    this->m_flEndSize.m_Value = 0.0;
  }
  if ( this->m_flSpawnRadius.m_Value != 16.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x370u);
    }
    this->m_flSpawnRadius.m_Value = 16.0;
  }
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
    this: &this->m_clrRender,
    rVal: 0xFFu,
    gVal: 0xFFu,
    bVal: 0xFFu);
  result = this;
  if ( this->m_clrRender.m_Value.a != 0xFF )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_clrRender.m_Value.a = -1;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0xB8u);
      this->m_clrRender.m_Value.a = -1;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10328990
// Name: public: SporeExplosion::SporeExplosion(void)
// Source: json
//------------------------------------------------------------------------------
SporeExplosion *__thiscall SporeExplosion::SporeExplosion(SporeExplosion *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  edict_t *v7; // ecx
  SporeExplosion *result; // eax
  edict_t *v9; // ecx

  CBaseParticleEntity::CBaseParticleEntity(this);
  this->__vftable = (SporeExplosion_vtbl *)&SporeExplosion::`vftable';
  if ( this->m_flSpawnRate.m_Value != 100.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x358u);
    }
    this->m_flSpawnRate.m_Value = 100.0;
  }
  if ( this->m_flParticleLifetime.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x35Cu);
    }
    this->m_flParticleLifetime.m_Value = 1.0;
  }
  if ( this->m_flStartSize.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x360u);
    }
    this->m_flStartSize.m_Value = 1.0;
  }
  if ( this->m_flEndSize.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x364u);
    }
    this->m_flEndSize.m_Value = 0.0;
  }
  if ( this->m_flSpawnRadius.m_Value != 16.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x368u);
    }
    this->m_flSpawnRadius.m_Value = 16.0;
  }
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
    this: &this->m_clrRender,
    rVal: 0xFFu,
    gVal: 0xFFu,
    bVal: 0xFFu);
  if ( this->m_clrRender.m_Value.a != 0xFF )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0xB8u);
    }
    this->m_clrRender.m_Value.a = -1;
  }
  result = this;
  if ( !this->m_bEmit.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bEmit.m_Value = true;
      this->m_bDisabled = false;
      return result;
    }
    v9 = this->m_Network.m_pPev;
    if ( v9 != nullptr )
      CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x36Cu);
    this->m_bEmit.m_Value = true;
    result = this;
  }
  this->m_bDisabled = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104154E0
// Name: DT_SmokeTrail::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SmokeTrail::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_SmokeTrail::g_SendTable);
  return atexit(func: DT_SmokeTrail::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415500
// Name: DT_SmokeTrail::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SmokeTrail::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_SmokeTrail::ignored>();
  DT_SmokeTrail::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415530
// Name: SmokeTrail_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *SmokeTrail_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<SmokeTrail>();
  SmokeTrail_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415560
// Name: DT_RocketTrail::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_RocketTrail::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_RocketTrail::g_SendTable);
  return atexit(func: DT_RocketTrail::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415580
// Name: DT_RocketTrail::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_RocketTrail::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_RocketTrail::ignored>();
  DT_RocketTrail::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104155B0
// Name: RocketTrail_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *RocketTrail_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<RocketTrail>();
  RocketTrail_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104155E0
// Name: DT_SporeTrail::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SporeTrail::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_SporeTrail::g_SendTable);
  return atexit(func: DT_SporeTrail::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415600
// Name: DT_SporeTrail::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SporeTrail::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_SporeTrail::ignored>();
  DT_SporeTrail::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415630
// Name: SporeTrail_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *SporeTrail_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<SporeTrail>();
  SporeTrail_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415660
// Name: DT_SporeExplosion::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SporeExplosion::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_SporeExplosion::g_SendTable);
  return atexit(func: DT_SporeExplosion::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415680
// Name: DT_SporeExplosion::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SporeExplosion::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_SporeExplosion::ignored>();
  DT_SporeExplosion::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104156B0
// Name: SporeExplosion_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *SporeExplosion_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<SporeExplosion>(__formal: nullptr);
  SporeExplosion_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104156C0
// Name: CFireTrail_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFireTrail_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFireTrail>(__formal: nullptr);
  CFireTrail_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104156F0
// Name: DT_FireTrail::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FireTrail::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_FireTrail::g_SendTable);
  return atexit(func: DT_FireTrail::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415710
// Name: DT_FireTrail::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FireTrail::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_FireTrail::ignored>();
  DT_FireTrail::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415760
// Name: DT_DustTrail::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_DustTrail::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_DustTrail::g_SendTable);
  return atexit(func: DT_DustTrail::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415780
// Name: DT_DustTrail::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_DustTrail::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_DustTrail::ignored>();
  DT_DustTrail::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104157B0
// Name: DustTrail_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *DustTrail_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<DustTrail>(__formal: nullptr);
  DustTrail_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421B40
// Name: DT_SmokeTrail::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SmokeTrail::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_SmokeTrail::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10421B50
// Name: DT_RocketTrail::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_RocketTrail::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_RocketTrail::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10421B80
// Name: DT_SporeTrail::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SporeTrail::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_SporeTrail::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10421BB0
// Name: DT_SporeExplosion::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SporeExplosion::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_SporeExplosion::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10421BE0
// Name: DT_FireTrail::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FireTrail::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_FireTrail::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10421C10
// Name: DT_DustTrail::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_DustTrail::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_DustTrail::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10328910
// Name: struct datamap_t __near * DataMapInit<class SporeExplosion>(class SporeExplosion __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<SporeExplosion>()
{
  if ( (_S9_10 & 1) == 0 )
  {
    _S9_10 |= 1u;
    nameHolder_509.m_pszBase = "SporeExplosion";
    nameHolder_509.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_509.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_509.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_509.m_Names.m_Size = 0;
    nameHolder_509.m_Names.m_pElements = nullptr;
    nameHolder_509.m_nLenBase = 14;
    atexit(func: DataMapInit_SporeExplosion__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  SporeExplosion::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  SporeExplosion::m_DataMap.dataNumFields = 10;
  SporeExplosion::m_DataMap.dataDesc = &dataDesc_460[1];
  return &SporeExplosion::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10328BA0
// Name: struct datamap_t __near * DataMapInit<class CFireTrail>(class CFireTrail __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFireTrail>()
{
  if ( (_S10_7 & 1) == 0 )
  {
    _S10_7 |= 1u;
    nameHolder_510.m_pszBase = "CFireTrail";
    nameHolder_510.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_510.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_510.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_510.m_Names.m_Size = 0;
    nameHolder_510.m_Names.m_pElements = nullptr;
    nameHolder_510.m_nLenBase = 10;
    atexit(func: DataMapInit_CFireTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFireTrail::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CFireTrail::m_DataMap.dataNumFields = 2;
  CFireTrail::m_DataMap.dataDesc = &dataDesc_461[1];
  return &CFireTrail::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10328C20
// Name: struct datamap_t __near * DataMapInit<class DustTrail>(class DustTrail __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<DustTrail>()
{
  if ( (_S13_3 & 1) == 0 )
  {
    _S13_3 |= 1u;
    nameHolder_511.m_pszBase = "DustTrail";
    nameHolder_511.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_511.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_511.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_511.m_Names.m_Size = 0;
    nameHolder_511.m_Names.m_pElements = nullptr;
    nameHolder_511.m_nLenBase = 9;
    atexit(func: DataMapInit_DustTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  DustTrail::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  DustTrail::m_DataMap.dataNumFields = 14;
  DustTrail::m_DataMap.dataDesc = &dataDesc_462[1];
  return &DustTrail::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10415510
// Name: _dynamic_initializer_for__env_smoketrail__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_smoketrail__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<SmokeTrail> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_smoketrail,
           a3: "env_smoketrail");
}

//------------------------------------------------------------------------------
// Address: 0x10415540
// Name: _dynamic_initializer_for__g_RocketTrail_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_RocketTrail_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_RocketTrail_ClassReg,
           pNetworkName: "RocketTrail",
           pTable: &DT_RocketTrail::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10415590
// Name: _dynamic_initializer_for__env_rockettrail__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_rockettrail__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<RocketTrail> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_rockettrail,
           a3: "env_rockettrail");
}

//------------------------------------------------------------------------------
// Address: 0x104155C0
// Name: _dynamic_initializer_for__g_SporeTrail_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_SporeTrail_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_SporeTrail_ClassReg,
           pNetworkName: "SporeTrail",
           pTable: &DT_SporeTrail::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10415610
// Name: _dynamic_initializer_for__env_sporetrail__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_sporetrail__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<SporeTrail> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_sporetrail,
           a3: "env_sporetrail");
}

//------------------------------------------------------------------------------
// Address: 0x10415640
// Name: _dynamic_initializer_for__g_SporeExplosion_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_SporeExplosion_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_SporeExplosion_ClassReg,
           pNetworkName: "SporeExplosion",
           pTable: &DT_SporeExplosion::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10415690
// Name: _dynamic_initializer_for__env_sporeexplosion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_sporeexplosion__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<SporeExplosion> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_sporeexplosion,
           a3: "env_sporeexplosion");
}

//------------------------------------------------------------------------------
// Address: 0x104156D0
// Name: _dynamic_initializer_for__g_CFireTrail_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFireTrail_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CFireTrail_ClassReg,
           pNetworkName: "CFireTrail",
           pTable: &DT_FireTrail::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10415720
// Name: _dynamic_initializer_for__env_fire_trail__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_fire_trail__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CFireTrail> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_fire_trail,
           a3: "env_fire_trail");
}

//------------------------------------------------------------------------------
// Address: 0x10415740
// Name: _dynamic_initializer_for__g_DustTrail_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_DustTrail_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_DustTrail_ClassReg,
           pNetworkName: "DustTrail",
           pTable: &DT_DustTrail::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10415790
// Name: _dynamic_initializer_for__env_dusttrail__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_dusttrail__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<DustTrail> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_dusttrail,
           a3: "env_dusttrail");
}

//------------------------------------------------------------------------------
// Address: 0x104157C0
// Name: _dynamic_initializer_for__g_CSmokeStack_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CSmokeStack_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CSmokeStack_ClassReg,
           pNetworkName: "CSmokeStack",
           pTable: &DT_SmokeStack::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10421B60
// Name: _ServerClassInit_DT_RocketTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_RocketTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S4_75;
  for ( i = 16; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10421B90
// Name: _ServerClassInit_DT_SporeTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_SporeTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S6_31;
  for ( i = 8; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10421BC0
// Name: _ServerClassInit_DT_SporeExplosion::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_SporeExplosion::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S8_15;
  for ( i = 8; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10421BF0
// Name: _ServerClassInit_DT_FireTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_FireTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S11_5;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10421C20
// Name: _ServerClassInit_DT_DustTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_DustTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S12_4;
  for ( i = 14; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10421C40
// Name: _ServerClassInit_DT_SmokeTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_SmokeTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_317;
  for ( i = 16; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10421C60
// Name: _DataMapInit_SmokeTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_SmokeTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_506);
}

//------------------------------------------------------------------------------
// Address: 0x10421C70
// Name: _DataMapInit_RocketTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_RocketTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_507);
}

//------------------------------------------------------------------------------
// Address: 0x10421C80
// Name: _DataMapInit_SporeTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_SporeTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_508);
}

//------------------------------------------------------------------------------
// Address: 0x10421C90
// Name: _DataMapInit_SporeExplosion__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_SporeExplosion__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_509);
}

//------------------------------------------------------------------------------
// Address: 0x10421CA0
// Name: _DataMapInit_CFireTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFireTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_510);
}

//------------------------------------------------------------------------------
// Address: 0x10421CB0
// Name: _DataMapInit_DustTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_DustTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_511);
}
