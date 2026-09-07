// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/env_projectedtexture.cpp
// Functions: 37
// ============================================================

#include "game\server\env_projectedtexture.h"

//------------------------------------------------------------------------------
// Address: 0x100E0AE0
// Name: public: void CEnvProjectedTexture::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::InputTurnOff(CBeamSpotlight *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CBeamSpotlight::NetworkVar_m_bSpotlightOn> *p_m_bSpotlightOn; // esi
  edict_t *m_pPev; // ecx

  p_m_bSpotlightOn = &this->m_bSpotlightOn;
  if ( this->m_bSpotlightOn.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bSpotlightOn->m_Value = false;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x358u);
      p_m_bSpotlightOn->m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115DF0
// Name: public: virtual struct datamap_t __near * CEnvProjectedTexture::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvProjectedTexture::GetDataDescMap(CEnvProjectedTexture *this)
{
  return &CEnvProjectedTexture::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10115E00
// Name: public: virtual class ServerClass __near * CEnvProjectedTexture::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CEnvProjectedTexture::GetServerClass(CEnvProjectedTexture *this)
{
  return &g_CEnvProjectedTexture_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10115E10
// Name: public: void CEnvProjectedTexture::InputSetSpotlightTexture(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::InputSetSpotlightTexture(CEnvProjectedTexture *this, inputdata_t *inputdata)
{
  _Warning(a1: "SetSpotlightTexture is disabled. If you need this feature reimplemented, tell a programmer.\n");
}

//------------------------------------------------------------------------------
// Address: 0x10115E20
// Name: public: virtual bool CEnvProjectedTexture::GetKeyValue(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEnvProjectedTexture::GetKeyValue(
        CEnvProjectedTexture *this,
        const char *szKeyName,
        char *szValue,
        int iMaxLen)
{
  if ( szKeyName != "lightcolor" && _V_stricmp(s1: szKeyName, s2: "lightcolor") != 0 )
  {
    if ( szKeyName != "texturename" && _V_stricmp(s1: szKeyName, s2: "texturename") != 0 )
    {
      return CBaseEntity::GetKeyValue(this, szKeyName, szValue, iMaxLen);
    }
    else
    {
      V_snprintf(pDest: szValue, maxLen: iMaxLen, pFormat: "%s", this->m_SpotlightTextureName.m_Value);
      return 1;
    }
  }
  else
  {
    V_snprintf(
      pDest: szValue,
      maxLen: iMaxLen,
      pFormat: "%d %d %d %d",
      this->m_LightColor.m_Value.r,
      this->m_LightColor.m_Value.g,
      this->m_LightColor.m_Value.b,
      this->m_LightColor.m_Value.a);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115EE0
// Name: public: void CEnvProjectedTexture::InputSetPattern(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::InputSetPattern(CEnvProjectedTexture *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // ecx
  const char *v5; // edx

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType != FIELD_STRING )
  {
    inputdata = nullptr;
    p_value = (variant_t *)&inputdata;
  }
  iVal = (const char *)p_value->iVal;
  this->m_iszPattern.pszValue = iVal;
  v5 = iVal;
  if ( iVal == nullptr )
    v5 = locale;
  engine->LightStyle(this: engine, a2: this->m_iStyle.m_Value, a3: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10116320
// Name: private: void CEnvProjectedTexture::EnforceSingleProjectionRules(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::EnforceSingleProjectionRules(CEnvProjectedTexture *this, bool bWarnOnEnforcement)
{
  CEnvProjectedTexture *i; // esi
  const char *pszValue; // ebx
  const char *EntityNameAsCStr; // eax

  for ( i = (CEnvProjectedTexture *)CGlobalEntityList::FindEntityByClassname(
                                      this: &gEntList,
                                      pStartEntity: nullptr,
                                      szName: "env_projectedtexture");
        i != nullptr;
        i = (CEnvProjectedTexture *)CGlobalEntityList::FindEntityByClassname(
                                      this: &gEntList,
                                      pStartEntity: i,
                                      szName: "env_projectedtexture") )
  {
    if ( i != this )
    {
      if ( bWarnOnEnforcement && i->m_bState.m_Value )
      {
        pszValue = i->m_iName.m_Value.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        EntityNameAsCStr = CBaseEntity::GetEntityNameAsCStr(this);
        _Warning(a1: "Warning: env_projected_texture (%s) forced off by (%s)\n", pszValue, EntityNameAsCStr);
      }
      ((void (__thiscall *)(CEnvProjectedTexture *, const char *, CEnvProjectedTexture *, CEnvProjectedTexture *, _DWORD))i->AcceptInput)(
        a1: i,
        a2: "TurnOff",
        a3: this,
        a4: this,
        a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116460
// Name: public: virtual bool CEnvProjectedTexture::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEnvProjectedTexture::KeyValue(CEnvProjectedTexture *this, const char *szKeyName, const char *szValue)
{
  int v4; // ebx
  CNetworkColor32Base<color32_s,CEnvProjectedTexture::NetworkVar_m_LightColor> *p_m_LightColor; // esi
  CNetworkColor32Base<color32_s,CEnvProjectedTexture::NetworkVar_m_LightColor> *v6; // eax
  CBaseEdict *v7; // ecx
  int v8; // ebx
  CNetworkColor32Base<color32_s,CEnvProjectedTexture::NetworkVar_m_LightColor> *v9; // eax
  CBaseEdict *v10; // ecx
  int v11; // ebx
  CNetworkColor32Base<color32_s,CEnvProjectedTexture::NetworkVar_m_LightColor> *v12; // eax
  CBaseEdict *v13; // ecx
  int v14; // ebx
  CNetworkColor32Base<color32_s,CEnvProjectedTexture::NetworkVar_m_LightColor> *v15; // eax
  CBaseEdict *v17; // ecx
  CEnvProjectedTexture::NetworkVar_m_SpotlightTextureName *p_m_SpotlightTextureName; // esi
  CBaseEdict *v19; // ecx
  float tmp[4]; // [esp+Ch] [ebp-10h] BYREF

  if ( szKeyName != "lightcolor" && _V_stricmp(s1: szKeyName, s2: "lightcolor") != 0 )
  {
    if ( szKeyName != "texturename" && _V_stricmp(s1: szKeyName, s2: "texturename") != 0 )
      return CServerOnlyPointEntity::KeyValue((CLogicalEntity *)this, szKeyName, szValue);
    p_m_SpotlightTextureName = &this->m_SpotlightTextureName;
    if ( p_m_SpotlightTextureName[-4].m_Value[236] != 0 )
    {
      p_m_SpotlightTextureName[-4].m_Value[240] |= 1u;
      _V_strcpy(dest: p_m_SpotlightTextureName->m_Value, src: szValue);
      return true;
    }
    v19 = *(CBaseEdict **)&p_m_SpotlightTextureName[-4].m_Value[176];
    if ( v19 != nullptr )
    {
      v19->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: v19)->m_iChangeInfoSerialNumber = 0;
    }
    _V_strcpy(dest: p_m_SpotlightTextureName->m_Value, src: szValue);
    return true;
  }
  UTIL_StringToFloatArray(pVector: tmp, count: 4, pString: szValue);
  v4 = (int)tmp[0];
  p_m_LightColor = &this->m_LightColor;
  if ( p_m_LightColor->m_Value.r != (unsigned __int8)(int)tmp[0] )
  {
    v6 = p_m_LightColor - 219;
    if ( p_m_LightColor[-198].m_Value.r != 0 )
    {
      v6[22].m_Value.r |= 1u;
    }
    else
    {
      v7 = (CBaseEdict *)v6[6];
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: v7, offset: 0x36Cu);
    }
    p_m_LightColor->m_Value.r = v4;
  }
  v8 = (int)tmp[1];
  if ( p_m_LightColor->m_Value.g != (unsigned __int8)(int)tmp[1] )
  {
    v9 = p_m_LightColor - 219;
    if ( p_m_LightColor[-198].m_Value.r != 0 )
    {
      v9[22].m_Value.r |= 1u;
    }
    else
    {
      v10 = (CBaseEdict *)v9[6];
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: v10, offset: 0x36Cu);
    }
    p_m_LightColor->m_Value.g = v8;
  }
  v11 = (int)tmp[2];
  if ( p_m_LightColor->m_Value.b != (unsigned __int8)(int)tmp[2] )
  {
    v12 = p_m_LightColor - 219;
    if ( p_m_LightColor[-198].m_Value.r != 0 )
    {
      v12[22].m_Value.r |= 1u;
    }
    else
    {
      v13 = (CBaseEdict *)v12[6];
      if ( v13 != nullptr )
        CBaseEdict::StateChanged(this: v13, offset: 0x36Cu);
    }
    p_m_LightColor->m_Value.b = v11;
  }
  v14 = (int)tmp[3];
  if ( p_m_LightColor->m_Value.a == (unsigned __int8)(int)tmp[3] )
    return true;
  v15 = p_m_LightColor - 219;
  if ( p_m_LightColor[-198].m_Value.r != 0 )
  {
    v15[22].m_Value.r |= 1u;
    p_m_LightColor->m_Value.a = v14;
    return true;
  }
  else
  {
    v17 = (CBaseEdict *)v15[6];
    if ( v17 != nullptr )
      CBaseEdict::StateChanged(this: v17, offset: 0x36Cu);
    p_m_LightColor->m_Value.a = v14;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116620
// Name: public: void CEnvProjectedTexture::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::InputTurnOn(CEnvProjectedTexture *this, inputdata_t *inputdata)
{
  edict_t *m_pPev; // ecx

  CEnvProjectedTexture::EnforceSingleProjectionRules(this, bWarnOnEnforcement: false);
  if ( !this->m_bState.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bState.m_Value = true;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x358u);
      this->m_bState.m_Value = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116670
// Name: public: void CEnvProjectedTexture::InputAlwaysUpdateOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::InputAlwaysUpdateOn(CEnvProjectedTexture *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CEnvProjectedTexture::NetworkVar_m_bAlwaysUpdate> *p_m_bAlwaysUpdate; // esi
  edict_t *m_pPev; // ecx

  p_m_bAlwaysUpdate = &this->m_bAlwaysUpdate;
  if ( !this->m_bAlwaysUpdate.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bAlwaysUpdate->m_Value = true;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x359u);
      p_m_bAlwaysUpdate->m_Value = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101166C0
// Name: public: void CEnvProjectedTexture::InputAlwaysUpdateOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::InputAlwaysUpdateOff(CEnvProjectedTexture *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CEnvProjectedTexture::NetworkVar_m_bAlwaysUpdate> *p_m_bAlwaysUpdate; // esi
  edict_t *m_pPev; // ecx

  p_m_bAlwaysUpdate = &this->m_bAlwaysUpdate;
  if ( this->m_bAlwaysUpdate.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bAlwaysUpdate->m_Value = false;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x359u);
      p_m_bAlwaysUpdate->m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116710
// Name: public: void CEnvProjectedTexture::InputSetTarget(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::InputSetTarget(CEnvProjectedTexture *this, inputdata_t *inputdata)
{
  unsigned int m_Index; // edx

  if ( inputdata->value.fieldType != FIELD_EHANDLE )
  {
    if ( (`variant_t::Entity'::`4'::`local static guard' & 1) == 0 )
      `variant_t::Entity'::`4'::`local static guard' |= 1u;
    `variant_t::Entity'::`4'::hNull.m_Index = -1;
    goto LABEL_5;
  }
  m_Index = inputdata->value.eVal.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
LABEL_5:
    CNetworkHandleBase<CBaseEntity,CEntityFlame::NetworkVar_m_hEntAttached>::Set(
      this: (CNetworkHandleBase<CBaseEntity,CSprite::NetworkVar_m_hAttachedToEntity> *)&this->m_hTargetEntity,
      val: nullptr);
    return;
  }
  CNetworkHandleBase<CBaseEntity,CEntityFlame::NetworkVar_m_hEntAttached>::Set(
    this: (CNetworkHandleBase<CBaseEntity,CSprite::NetworkVar_m_hAttachedToEntity> *)&this->m_hTargetEntity,
    val: (const CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x10116790
// Name: public: void CEnvProjectedTexture::InputSetCameraSpace(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::InputSetCameraSpace(CEnvProjectedTexture *this, inputdata_t *inputdata)
{
  bool v2; // bl
  CNetworkVarBase<bool,CEnvProjectedTexture::NetworkVar_m_bCameraSpace> *p_m_bCameraSpace; // esi
  edict_t *m_pPev; // ecx

  v2 = inputdata->value.fieldType == FIELD_BOOLEAN && inputdata->value.bVal;
  p_m_bCameraSpace = &this->m_bCameraSpace;
  if ( this->m_bCameraSpace.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bCameraSpace->m_Value = v2;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x364u);
      p_m_bCameraSpace->m_Value = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101167F0
// Name: public: void CEnvProjectedTexture::InputSetLightOnlyTarget(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::InputSetLightOnlyTarget(CEnvProjectedTexture *this, inputdata_t *inputdata)
{
  bool v2; // bl
  CNetworkVarBase<bool,CEnvProjectedTexture::NetworkVar_m_bLightOnlyTarget> *p_m_bLightOnlyTarget; // esi
  edict_t *m_pPev; // ecx

  v2 = inputdata->value.fieldType == FIELD_BOOLEAN && inputdata->value.bVal;
  p_m_bLightOnlyTarget = &this->m_bLightOnlyTarget;
  if ( this->m_bLightOnlyTarget.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bLightOnlyTarget->m_Value = v2;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x362u);
      p_m_bLightOnlyTarget->m_Value = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116850
// Name: public: void CEnvProjectedTexture::InputSetLightWorld(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::InputSetLightWorld(CEnvProjectedTexture *this, inputdata_t *inputdata)
{
  bool v2; // bl
  CNetworkVarBase<bool,CEnvProjectedTexture::NetworkVar_m_bLightWorld> *p_m_bLightWorld; // esi
  edict_t *m_pPev; // ecx

  v2 = inputdata->value.fieldType == FIELD_BOOLEAN && inputdata->value.bVal;
  p_m_bLightWorld = &this->m_bLightWorld;
  if ( this->m_bLightWorld.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bLightWorld->m_Value = v2;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x363u);
      p_m_bLightWorld->m_Value = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101168B0
// Name: public: void CEnvProjectedTexture::InputSetEnableShadows(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::InputSetEnableShadows(CEnvProjectedTexture *this, inputdata_t *inputdata)
{
  bool v2; // bl
  CNetworkVarBase<bool,CEnvProjectedTexture::NetworkVar_m_bEnableShadows> *p_m_bEnableShadows; // esi
  edict_t *m_pPev; // ecx

  v2 = inputdata->value.fieldType == FIELD_BOOLEAN && inputdata->value.bVal;
  p_m_bEnableShadows = &this->m_bEnableShadows;
  if ( this->m_bEnableShadows.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bEnableShadows->m_Value = v2;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x360u);
      p_m_bEnableShadows->m_Value = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116910
// Name: public: void CEnvProjectedTexture::InputSetLightColor(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::InputSetLightColor(CEnvProjectedTexture *this, inputdata_t *inputdata)
{
  inputdata = (inputdata_t *)inputdata->value.iszVal.pszValue;
  CNetworkColor32Base<color32_s,CEnvProjectedTexture::NetworkVar_m_LightColor>::operator=(
    this: &this->m_LightColor,
    val: (const color32_s *)&inputdata);
}

//------------------------------------------------------------------------------
// Address: 0x10116930
// Name: public: void CEnvProjectedTexture::InputSetAmbient(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::InputSetAmbient(CEnvProjectedTexture *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CEnvProjectedTexture::NetworkVar_m_flAmbient> *p_m_flAmbient; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_flAmbient = &this->m_flAmbient;
  if ( this->m_flAmbient.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flAmbient->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x374u);
      p_m_flAmbient->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101169B0
// Name: public: void CEnvProjectedTexture::InputSetLightStyle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::InputSetLightStyle(CEnvProjectedTexture *this, inputdata_t *inputdata)
{
  const char *pszValue; // edi
  CNetworkVarBase<int,CEnvProjectedTexture::NetworkVar_m_iStyle> *p_m_iStyle; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_INTEGER )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  p_m_iStyle = &this->m_iStyle;
  if ( (const char *)this->m_iStyle.m_Value != pszValue )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_iStyle->m_Value = (int)pszValue;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x494u);
      p_m_iStyle->m_Value = (int)pszValue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116A10
// Name: public: void CEnvProjectedTexture::InputSetNearZ(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::InputSetNearZ(CEnvProjectedTexture *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CEnvProjectedTexture::NetworkVar_m_flNearZ> *p_m_flNearZ; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_flNearZ = &this->m_flNearZ;
  if ( this->m_flNearZ.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flNearZ->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x480u);
      p_m_flNearZ->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116A90
// Name: public: virtual void CEnvProjectedTexture::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::Spawn(CEnvProjectedTexture *this)
{
  bool v2; // bl
  edict_t *m_pPev; // ecx
  bool v4; // dl
  edict_t *v5; // ecx
  const char *DefaultLightstyleString; // eax
  const char *pszValue; // eax
  bool v8; // [esp+Fh] [ebp-1h]

  v2 = this->m_spawnflags.m_Value & 1;
  if ( this->m_bState.m_Value != v2 )
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
    this->m_bState.m_Value = v2;
  }
  v4 = (this->m_spawnflags.m_Value & 2) != 0;
  v8 = v4;
  if ( this->m_bAlwaysUpdate.m_Value != v4 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x359u);
        v4 = v8;
      }
    }
    this->m_bAlwaysUpdate.m_Value = v4;
  }
  if ( this->m_iStyle.m_Value < 32 )
    goto LABEL_27;
  if ( this->m_iszPattern.pszValue == nullptr && this->m_iDefaultStyle > 0 )
  {
    DefaultLightstyleString = GetDefaultLightstyleString(styleIndex: this->m_iDefaultStyle);
    if ( DefaultLightstyleString == nullptr || *DefaultLightstyleString == 0 )
      DefaultLightstyleString = nullptr;
    this->m_iszPattern.pszValue = DefaultLightstyleString;
  }
  if ( !this->m_bState.m_Value )
  {
    engine->LightStyle(this: engine, a2: this->m_iStyle.m_Value, a3: "a");
LABEL_27:
    CPointEntity::Spawn(this);
    return;
  }
  if ( this->m_iszPattern.pszValue == nullptr )
  {
    engine->LightStyle(this: engine, a2: this->m_iStyle.m_Value, a3: "m");
    goto LABEL_27;
  }
  pszValue = this->m_iszPattern.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  engine->LightStyle(this: engine, a2: this->m_iStyle.m_Value, a3: pszValue);
  CPointEntity::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x10116BD0
// Name: public: void CEnvProjectedTexture::InitialThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::InitialThink(CEnvProjectedTexture *this)
{
  const char *pszValue; // eax
  const CBaseEntity *EntityByName; // eax

  pszValue = this->m_target.pszValue;
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
  CNetworkHandleBase<CBaseEntity,CEntityFlame::NetworkVar_m_hEntAttached>::Set(
    this: (CNetworkHandleBase<CBaseEntity,CSprite::NetworkVar_m_hAttachedToEntity> *)&this->m_hTargetEntity,
    val: EntityByName);
}

//------------------------------------------------------------------------------
// Address: 0x10116CF0
// Name: public: CEnvProjectedTexture::CEnvProjectedTexture(void)
// Source: json
//------------------------------------------------------------------------------
CEnvProjectedTexture *__thiscall CEnvProjectedTexture::CEnvProjectedTexture(CEnvProjectedTexture *this)
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
  edict_t *v16; // ecx
  edict_t *v17; // ecx
  edict_t *v18; // ecx
  edict_t *v19; // ecx
  CEnvProjectedTexture *result; // eax
  edict_t *v21; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CEnvProjectedTexture_vtbl *)&CEnvProjectedTexture::`vftable';
  this->m_hTargetEntity.m_Value.m_Index = -1;
  if ( !this->m_bState.m_Value )
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
    this->m_bState.m_Value = true;
  }
  if ( this->m_bAlwaysUpdate.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x359u);
    }
    this->m_bAlwaysUpdate.m_Value = false;
  }
  if ( this->m_flLightFOV.m_Value != 45.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x35Cu);
    }
    this->m_flLightFOV.m_Value = 45.0;
  }
  if ( this->m_bEnableShadows.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x360u);
    }
    this->m_bEnableShadows.m_Value = false;
  }
  if ( this->m_bSimpleProjection.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x361u);
    }
    this->m_bSimpleProjection.m_Value = false;
  }
  if ( this->m_bLightOnlyTarget.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x362u);
    }
    this->m_bLightOnlyTarget.m_Value = false;
  }
  if ( !this->m_bLightWorld.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x363u);
    }
    this->m_bLightWorld.m_Value = true;
  }
  if ( this->m_bCameraSpace.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x364u);
    }
    this->m_bCameraSpace.m_Value = false;
  }
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v10 = this->m_Network.m_pPev;
    if ( v10 != nullptr )
    {
      v10->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &v10->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
  }
  _V_strcpy(dest: this->m_SpotlightTextureName.m_Value, src: "effects/flashlight_border");
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v11 = this->m_Network.m_pPev;
    if ( v11 != nullptr )
    {
      v11->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &v11->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
  }
  _V_strcpy(dest: this->m_SpotlightTextureName.m_Value, src: "effects/flashlight001");
  if ( this->m_nSpotlightTextureFrame.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v12 = this->m_Network.m_pPev;
      if ( v12 != nullptr )
        CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x47Cu);
    }
    this->m_nSpotlightTextureFrame.m_Value = 0;
  }
  if ( this->m_flBrightnessScale.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v13 = this->m_Network.m_pPev;
      if ( v13 != nullptr )
        CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x368u);
    }
    this->m_flBrightnessScale.m_Value = 1.0;
  }
  CNetworkColor32Base<color32_s,CEnvProjectedTexture::NetworkVar_m_LightColor>::Init(
    this: &this->m_LightColor,
    rVal: 0xFFu,
    gVal: 0xFFu,
    bVal: 0xFFu,
    aVal: 0xFFu);
  if ( this->m_flColorTransitionTime.m_Value != 0.5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v14 = this->m_Network.m_pPev;
      if ( v14 != nullptr )
        CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x370u);
    }
    this->m_flColorTransitionTime.m_Value = 0.5;
  }
  if ( this->m_flAmbient.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v15 = this->m_Network.m_pPev;
      if ( v15 != nullptr )
        CBaseEdict::StateChanged(this: &v15->CBaseEdict, offset: 0x374u);
    }
    this->m_flAmbient.m_Value = 0.0;
  }
  if ( this->m_flNearZ.m_Value != 4.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v16 = this->m_Network.m_pPev;
      if ( v16 != nullptr )
        CBaseEdict::StateChanged(this: &v16->CBaseEdict, offset: 0x480u);
    }
    this->m_flNearZ.m_Value = 4.0;
  }
  if ( this->m_flFarZ.m_Value != 750.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v17 = this->m_Network.m_pPev;
      if ( v17 != nullptr )
        CBaseEdict::StateChanged(this: &v17->CBaseEdict, offset: 0x484u);
    }
    this->m_flFarZ.m_Value = 750.0;
  }
  if ( this->m_nShadowQuality.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v18 = this->m_Network.m_pPev;
      if ( v18 != nullptr )
        CBaseEdict::StateChanged(this: &v18->CBaseEdict, offset: 0x488u);
    }
    this->m_nShadowQuality.m_Value = 0;
  }
  if ( this->m_flProjectionSize.m_Value != 500.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v19 = this->m_Network.m_pPev;
      if ( v19 != nullptr )
        CBaseEdict::StateChanged(this: &v19->CBaseEdict, offset: 0x48Cu);
    }
    this->m_flProjectionSize.m_Value = 500.0;
  }
  result = this;
  if ( this->m_flRotation.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v21 = this->m_Network.m_pPev;
      if ( v21 != nullptr )
        CBaseEdict::StateChanged(this: &v21->CBaseEdict, offset: 0x490u);
    }
    this->m_flRotation.m_Value = 0.0;
    return this;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101171A0
// Name: public: virtual void CEnvProjectedTexture::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::Activate(CEnvProjectedTexture *this)
{
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CEnvProjectedTexture::InitialThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  CBaseEntity::Activate(this);
  if ( this->m_bState.m_Value )
    CEnvProjectedTexture::EnforceSingleProjectionRules(this, bWarnOnEnforcement: true);
}

//------------------------------------------------------------------------------
// Address: 0x10117200
// Name: void CC_CreateFlashlight(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_CreateFlashlight(const CCommand *args)
{
  CBasePlayer *CommandClient; // esi
  CBaseEntity *EntityByName; // eax
  CBaseEntity *v3; // esi
  string_t v4; // eax
  Vector origin; // [esp+4h] [ebp-1Ch] BYREF
  QAngle angles; // [esp+10h] [ebp-10h] BYREF
  char pszValue[4]; // [esp+1Ch] [ebp-4h] BYREF

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient != nullptr )
  {
    angles = *CommandClient->EyeAngles(this: CommandClient);
    CommandClient->EyePosition(this: CommandClient, result: &origin);
    EntityByName = CreateEntityByName(className: "env_projectedtexture", iForceEdictIndex: -1, bNotify: true);
    v3 = (CBaseEntity *)__RTDynamicCast(
                          inptr: EntityByName,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CEnvProjectedTexture `RTTI Type Descriptor',
                          isReference: 0);
    if ( args->m_nArgc > 1 )
    {
      v4.pszValue = AllocPooledString(pszValue).pszValue;
      CBaseEntity::SetName(this: v3, newName: *(string_t *)v4.pszValue);
    }
    v3->Teleport(this: v3, a2: &origin, a3: &angles, a4: nullptr, a5: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101753F0
// Name: public: void CEnvProjectedTexture::InputSetFOV(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvProjectedTexture::InputSetFOV(CEnvProjectedTexture *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CEnvProjectedTexture::NetworkVar_m_flLightFOV> *p_m_flLightFOV; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_flLightFOV = &this->m_flLightFOV;
  if ( this->m_flLightFOV.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flLightFOV->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x35Cu);
      p_m_flLightFOV->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10402910
// Name: CEnvProjectedTexture_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvProjectedTexture_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvProjectedTexture>(__formal: nullptr);
  CEnvProjectedTexture_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402940
// Name: DT_EnvProjectedTexture::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvProjectedTexture::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_EnvProjectedTexture::g_SendTable);
  return atexit(func: DT_EnvProjectedTexture::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10402960
// Name: DT_EnvProjectedTexture::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvProjectedTexture::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_EnvProjectedTexture::ignored>();
  DT_EnvProjectedTexture::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041AEA0
// Name: DT_EnvProjectedTexture::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EnvProjectedTexture::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_EnvProjectedTexture::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x101172B0
// Name: struct datamap_t __near * DataMapInit<class CEnvProjectedTexture>(class CEnvProjectedTexture __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvProjectedTexture>()
{
  if ( (_S2_88 & 1) == 0 )
  {
    _S2_88 |= 1u;
    nameHolder_166.m_pszBase = "CEnvProjectedTexture";
    nameHolder_166.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_166.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_166.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_166.m_Names.m_Size = 0;
    nameHolder_166.m_Names.m_pElements = nullptr;
    nameHolder_166.m_nLenBase = 20;
    atexit(func: DataMapInit_CEnvProjectedTexture__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvProjectedTexture::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_88 & 2) == 0 )
  {
    _S2_88 |= 2u;
    dataDesc_156[42].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_166,
                                   pszIdentifier: "InitialThink");
    dataDesc_156[42].fieldOffset = 0;
    *(_DWORD *)&dataDesc_156[42].fieldSize = 2097153;
    dataDesc_156[42].externalName = nullptr;
    dataDesc_156[42].pSaveRestoreOps = nullptr;
    dataDesc_156[42].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvProjectedTexture::InitialThink;
    *(_QWORD *)&dataDesc_156[42].td = 0;
    *(_QWORD *)&dataDesc_156[42].override_field = 0;
    *(_QWORD *)&dataDesc_156[42].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_156[42].flatOffset[1] = 0;
  }
  CEnvProjectedTexture::m_DataMap.dataNumFields = 42;
  CEnvProjectedTexture::m_DataMap.dataDesc = &dataDesc_156[1];
  return &CEnvProjectedTexture::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10402920
// Name: _dynamic_initializer_for__g_CEnvProjectedTexture_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CEnvProjectedTexture_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CEnvProjectedTexture_ClassReg,
           pNetworkName: "CEnvProjectedTexture",
           pTable: &DT_EnvProjectedTexture::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10402970
// Name: _dynamic_initializer_for__create_flashlight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__create_flashlight__()
{
  ConCommand::ConCommand(
    this: &create_flashlight,
    pName: "create_flashlight",
    callback: (void (__cdecl *)())CC_CreateFlashlight,
    pHelpString: nullptr,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__create_flashlight__);
}

//------------------------------------------------------------------------------
// Address: 0x104029A0
// Name: _dynamic_initializer_for__env_screenoverlay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_screenoverlay__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvScreenOverlay> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_screenoverlay,
           a3: "env_screenoverlay");
}

//------------------------------------------------------------------------------
// Address: 0x1041AEB0
// Name: _dynamic_atexit_destructor_for__create_flashlight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__create_flashlight__()
{
  ConCommand::~ConCommand(this: &create_flashlight);
}

//------------------------------------------------------------------------------
// Address: 0x1041AEC0
// Name: _ServerClassInit_DT_EnvProjectedTexture::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_EnvProjectedTexture::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_51;
  for ( i = 22; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041AEE0
// Name: _DataMapInit_CEnvProjectedTexture__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvProjectedTexture__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_166);
}
