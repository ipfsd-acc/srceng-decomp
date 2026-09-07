// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/sunlightshadowcontrol.cpp
// Functions: 26
// ============================================================

#include "game\server\sunlightshadowcontrol.h"

//------------------------------------------------------------------------------
// Address: 0x101163F0
// Name: public: struct color32_s const __near & CNetworkColor32Base<struct color32_s,class CEnvProjectedTexture::NetworkVar_m_LightColor>::operator=(struct color32_s const __near &)
// Source: json
//------------------------------------------------------------------------------
CNetworkColor32Base<color32_s,CEnvProjectedTexture::NetworkVar_m_LightColor> *__thiscall CNetworkColor32Base<color32_s,CEnvProjectedTexture::NetworkVar_m_LightColor>::operator=(
        CNetworkColor32Base<color32_s,CEnvProjectedTexture::NetworkVar_m_LightColor> *this,
        CNetworkColor32Base<color32_s,CEnvProjectedTexture::NetworkVar_m_LightColor> *val)
{
  CNetworkColor32Base<color32_s,CEnvProjectedTexture::NetworkVar_m_LightColor> *v3; // eax
  CBaseEdict *v5; // ecx

  if ( this->m_Value.r != val->m_Value.r
    || this->m_Value.g != val->m_Value.g
    || this->m_Value.b != val->m_Value.b
    || this->m_Value.a != val->m_Value.a )
  {
    v3 = this - 219;
    if ( *((_BYTE *)this - 792) != 0 )
    {
      v3[22].m_Value.r |= 1u;
      *this = *val;
      return this;
    }
    v5 = (CBaseEdict *)v3[6];
    if ( v5 != nullptr )
      CBaseEdict::StateChanged(this: v5, offset: 0x36Cu);
    *this = *val;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10116C10
// Name: public: void CNetworkColor32Base<struct color32_s,class CEnvProjectedTexture::NetworkVar_m_LightColor>::Init(unsigned char,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkColor32Base<color32_s,CEnvProjectedTexture::NetworkVar_m_LightColor>::Init(
        CNetworkColor32Base<color32_s,CEnvProjectedTexture::NetworkVar_m_LightColor> *this,
        unsigned __int8 rVal,
        unsigned __int8 gVal,
        unsigned __int8 bVal,
        unsigned __int8 aVal)
{
  CNetworkColor32Base<color32_s,CEnvProjectedTexture::NetworkVar_m_LightColor> *v6; // eax
  CBaseEdict *v7; // ecx
  CNetworkColor32Base<color32_s,CEnvProjectedTexture::NetworkVar_m_LightColor> *v8; // eax
  CBaseEdict *v9; // ecx
  CNetworkColor32Base<color32_s,CEnvProjectedTexture::NetworkVar_m_LightColor> *v10; // eax
  CBaseEdict *v11; // ecx
  CNetworkColor32Base<color32_s,CEnvProjectedTexture::NetworkVar_m_LightColor> *v12; // eax
  CBaseEdict *v13; // ecx

  if ( this->m_Value.r != rVal )
  {
    v6 = this - 219;
    if ( *((_BYTE *)this - 792) != 0 )
    {
      v6[22].m_Value.r |= 1u;
    }
    else
    {
      v7 = (CBaseEdict *)v6[6];
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: v7, offset: 0x36Cu);
    }
    this->m_Value.r = rVal;
  }
  if ( this->m_Value.g != gVal )
  {
    v8 = this - 219;
    if ( *((_BYTE *)this - 792) != 0 )
    {
      v8[22].m_Value.r |= 1u;
    }
    else
    {
      v9 = (CBaseEdict *)v8[6];
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: v9, offset: 0x36Cu);
    }
    this->m_Value.g = gVal;
  }
  if ( this->m_Value.b != bVal )
  {
    v10 = this - 219;
    if ( *((_BYTE *)this - 792) != 0 )
    {
      v10[22].m_Value.r |= 1u;
    }
    else
    {
      v11 = (CBaseEdict *)v10[6];
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: v11, offset: 0x36Cu);
    }
    this->m_Value.b = bVal;
  }
  if ( this->m_Value.a != aVal )
  {
    v12 = this - 219;
    if ( *((_BYTE *)this - 792) != 0 )
    {
      v12[22].m_Value.r |= 1u;
      this->m_Value.a = aVal;
    }
    else
    {
      v13 = (CBaseEdict *)v12[6];
      if ( v13 != nullptr )
        CBaseEdict::StateChanged(this: v13, offset: 0x36Cu);
      this->m_Value.a = aVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022C6A0
// Name: public: virtual struct datamap_t __near * CSunlightShadowControl::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CSunlightShadowControl::GetDataDescMap(CSunlightShadowControl *this)
{
  return &CSunlightShadowControl::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022C6B0
// Name: public: virtual class ServerClass __near * CSunlightShadowControl::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CSunlightShadowControl::GetServerClass(CSunlightShadowControl *this)
{
  return &g_CSunlightShadowControl_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1022C6C0
// Name: public: virtual bool CSunlightShadowControl::GetKeyValue(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSunlightShadowControl::GetKeyValue(
        CSunlightShadowControl *this,
        const char *szKeyName,
        char *szValue,
        int iMaxLen)
{
  if ( szKeyName != "color" && _V_stricmp(s1: szKeyName, s2: "color") != 0 )
  {
    if ( szKeyName != "texturename" && _V_stricmp(s1: szKeyName, s2: "texturename") != 0 )
    {
      return CBaseEntity::GetKeyValue(this, szKeyName, szValue, iMaxLen);
    }
    else
    {
      V_snprintf(pDest: szValue, maxLen: iMaxLen, pFormat: "%s", this->m_TextureName.m_Value);
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
// Address: 0x1022C9F0
// Name: public: char __near * CSunlightShadowControl::NetworkVar_m_TextureName::GetForModify(void)
// Source: json
//------------------------------------------------------------------------------
CSunlightShadowControl::NetworkVar_m_TextureName *__thiscall CSunlightShadowControl::NetworkVar_m_TextureName::GetForModify(
        CSunlightShadowControl::NetworkVar_m_TextureName *this)
{
  CBaseEdict *v3; // ecx

  if ( *((_BYTE *)this - 782) != 0 )
  {
    *((_BYTE *)this - 778) |= 1u;
    return this;
  }
  else
  {
    v3 = *(CBaseEdict **)((char *)this - 842);
    if ( v3 != nullptr )
    {
      v3->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: v3)->m_iChangeInfoSerialNumber = 0;
    }
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022CA30
// Name: public: void CSunlightShadowControl::InputSetTexture(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSunlightShadowControl::InputSetTexture(CSunlightShadowControl *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // ecx
  const char *v5; // edi
  CSunlightShadowControl::NetworkVar_m_TextureName *p_m_TextureName; // esi
  CBaseEdict *v7; // ecx

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( iVal != nullptr )
      v5 = iVal;
    else
      v5 = locale;
  }
  else
  {
    v5 = variant_t::ToString(this: p_value);
  }
  p_m_TextureName = &this->m_TextureName;
  if ( p_m_TextureName[-4].m_Value[258] != 0 )
  {
    p_m_TextureName[-3].m_Value[2] |= 1u;
    _V_strcpy(dest: p_m_TextureName->m_Value, src: v5);
  }
  else
  {
    v7 = *(CBaseEdict **)&p_m_TextureName[-4].m_Value[198];
    if ( v7 != nullptr )
    {
      v7->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: v7)->m_iChangeInfoSerialNumber = 0;
    }
    _V_strcpy(dest: p_m_TextureName->m_Value, src: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022CAB0
// Name: public: struct color32_s const __near & CNetworkColor32Base<struct color32_s,class CSunlightShadowControl::NetworkVar_m_LightColor>::operator=(struct color32_s const __near &)
// Source: json
//------------------------------------------------------------------------------
CNetworkColor32Base<color32_s,CSunlightShadowControl::NetworkVar_m_LightColor> *__thiscall CNetworkColor32Base<color32_s,CSunlightShadowControl::NetworkVar_m_LightColor>::operator=(
        CNetworkColor32Base<color32_s,CSunlightShadowControl::NetworkVar_m_LightColor> *this,
        CNetworkColor32Base<color32_s,CSunlightShadowControl::NetworkVar_m_LightColor> *val)
{
  char *v3; // eax
  CBaseEdict *v5; // ecx

  if ( this->m_Value.r != val->m_Value.r
    || this->m_Value.g != val->m_Value.g
    || this->m_Value.b != val->m_Value.b
    || this->m_Value.a != val->m_Value.a )
  {
    v3 = (char *)this - 1126;
    if ( *((_BYTE *)this - 1042) != 0 )
    {
      v3[88] |= 1u;
      *this = *val;
      return this;
    }
    v5 = *((CBaseEdict **)v3 + 6);
    if ( v5 != nullptr )
      CBaseEdict::StateChanged(this: v5, offset: 0x466u);
    *this = *val;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1022CB20
// Name: public: virtual bool CSunlightShadowControl::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSunlightShadowControl::KeyValue(CSunlightShadowControl *this, char *szKeyName, const char *szValue)
{
  CSunlightShadowControl *v3; // esi
  int x; // ebx
  CNetworkColor32Base<color32_s,CSunlightShadowControl::NetworkVar_m_LightColor> *p_m_LightColor; // esi
  unsigned __int8 *p_b; // eax
  CBaseEdict *v7; // ecx
  int y; // ebx
  unsigned __int8 *v9; // eax
  CBaseEdict *v10; // ecx
  int z; // ebx
  unsigned __int8 *v12; // eax
  CBaseEdict *v13; // ecx
  int v14; // ebx
  unsigned __int8 *v15; // eax
  CBaseEdict *v16; // ecx
  CBaseEdict *v18; // ecx
  CSunlightShadowControl::NetworkVar_m_TextureName *v19; // eax
  Vector vForward; // [esp+8h] [ebp-20h] BYREF
  float v21; // [esp+14h] [ebp-14h]
  QAngle angles; // [esp+18h] [ebp-10h] BYREF
  CBaseEntity *v23; // [esp+24h] [ebp-4h]

  v3 = this;
  v23 = this;
  if ( szKeyName == "color" || _V_stricmp(s1: szKeyName, s2: "color") == 0 )
  {
    UTIL_StringToFloatArray(pVector: &vForward.x, count: 4, pString: szValue);
    x = (int)vForward.x;
    p_m_LightColor = &v3->m_LightColor;
    if ( p_m_LightColor->m_Value.r != (unsigned __int8)(int)vForward.x )
    {
      p_b = &p_m_LightColor[-282].m_Value.b;
      if ( p_m_LightColor[-261].m_Value.b != 0 )
      {
        p_b[88] |= 1u;
      }
      else
      {
        v7 = *((CBaseEdict **)p_b + 6);
        if ( v7 != nullptr )
          CBaseEdict::StateChanged(this: v7, offset: 0x466u);
      }
      p_m_LightColor->m_Value.r = x;
    }
    y = (int)vForward.y;
    if ( p_m_LightColor->m_Value.g != (unsigned __int8)(int)vForward.y )
    {
      v9 = &p_m_LightColor[-282].m_Value.b;
      if ( p_m_LightColor[-261].m_Value.b != 0 )
      {
        v9[88] |= 1u;
      }
      else
      {
        v10 = *((CBaseEdict **)v9 + 6);
        if ( v10 != nullptr )
          CBaseEdict::StateChanged(this: v10, offset: 0x466u);
      }
      p_m_LightColor->m_Value.g = y;
    }
    z = (int)vForward.z;
    if ( p_m_LightColor->m_Value.b != (unsigned __int8)(int)vForward.z )
    {
      v12 = &p_m_LightColor[-282].m_Value.b;
      if ( p_m_LightColor[-261].m_Value.b != 0 )
      {
        v12[88] |= 1u;
      }
      else
      {
        v13 = *((CBaseEdict **)v12 + 6);
        if ( v13 != nullptr )
          CBaseEdict::StateChanged(this: v13, offset: 0x466u);
      }
      p_m_LightColor->m_Value.b = z;
    }
    v14 = (int)v21;
    if ( p_m_LightColor->m_Value.a != (unsigned __int8)(int)v21 )
    {
      v15 = &p_m_LightColor[-282].m_Value.b;
      if ( p_m_LightColor[-261].m_Value.b != 0 )
      {
        v15[88] |= 1u;
      }
      else
      {
        v16 = *((CBaseEdict **)v15 + 6);
        if ( v16 != nullptr )
          CBaseEdict::StateChanged(this: v16, offset: 0x466u);
      }
      p_m_LightColor->m_Value.a = v14;
    }
    v3 = (CSunlightShadowControl *)v23;
    return CBaseEntity::KeyValue(this: v3, szKeyName, szValue);
  }
  if ( szKeyName != "angles" && _V_stricmp(s1: szKeyName, s2: "angles") != 0 )
  {
    if ( szKeyName != "texturename" && _V_stricmp(s1: szKeyName, s2: "texturename") != 0 )
      return CBaseEntity::KeyValue(this: v3, szKeyName, szValue);
    v19 = CSunlightShadowControl::NetworkVar_m_TextureName::GetForModify(this: &v3->m_TextureName);
    _V_strcpy(dest: v19->m_Value, src: szValue);
    return CBaseEntity::KeyValue(this: v3, szKeyName, szValue);
  }
  else
  {
    UTIL_StringToVector(pVector: &angles.x, pString: szValue);
    if ( vec3_angle.x == angles.x && vec3_angle.y == angles.y && vec3_angle.z == angles.z )
    {
      angles.x = 80.0;
      angles.y = 30.0;
      angles.z = 0.0;
    }
    AngleVectors(&angles, forward: (Vector *)&vForward.y);
    if ( vForward.y != v3->m_shadowDirection.m_Value.x
      || vForward.z != v3->m_shadowDirection.m_Value.y
      || v21 != v3->m_shadowDirection.m_Value.z )
    {
      if ( v3->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v3->m_Network + 76) |= 1u;
      }
      else
      {
        v18 = &v3->m_Network.m_pPev->CBaseEdict;
        if ( v18 != nullptr )
          CBaseEdict::StateChanged(this: v18, offset: 0x354u);
      }
      v3->m_shadowDirection.m_Value.x = vForward.y;
      v3->m_shadowDirection.m_Value.y = vForward.z;
      v3->m_shadowDirection.m_Value.z = v21;
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022CDC0
// Name: public: virtual void CSunlightShadowControl::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSunlightShadowControl::Spawn(CSunlightShadowControl *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx

  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  if ( this->m_bStartDisabled )
  {
    if ( this->m_bEnabled.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_bEnabled.m_Value = false;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x360u);
        this->m_bEnabled.m_Value = false;
      }
    }
  }
  else if ( !this->m_bEnabled.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bEnabled.m_Value = true;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x360u);
      this->m_bEnabled.m_Value = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022CE60
// Name: public: void CSunlightShadowControl::InputSetAngles(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSunlightShadowControl::InputSetAngles(CShadowControl *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax
  edict_t *m_pPev; // ecx
  QAngle angles; // [esp+4h] [ebp-18h] BYREF
  Vector vTemp; // [esp+10h] [ebp-Ch] BYREF

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
      iVal = locale;
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  UTIL_StringToVector(pVector: &angles.x, pString: iVal);
  AngleVectors(&angles, forward: &vTemp);
  if ( vTemp.x != this->m_shadowDirection.m_Value.x
    || vTemp.y != this->m_shadowDirection.m_Value.y
    || vTemp.z != this->m_shadowDirection.m_Value.z )
  {
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
    this->m_shadowDirection.m_Value = vTemp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022CF30
// Name: public: void CSunlightShadowControl::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSunlightShadowControl::InputEnable(CSunlightShadowControl *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CSunlightShadowControl::NetworkVar_m_bEnabled> *p_m_bEnabled; // esi
  edict_t *m_pPev; // ecx

  p_m_bEnabled = &this->m_bEnabled;
  if ( !this->m_bEnabled.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bEnabled->m_Value = true;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x360u);
      p_m_bEnabled->m_Value = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022CF80
// Name: public: void CSunlightShadowControl::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSunlightShadowControl::InputDisable(CSunlightShadowControl *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CSunlightShadowControl::NetworkVar_m_bEnabled> *p_m_bEnabled; // esi
  edict_t *m_pPev; // ecx

  p_m_bEnabled = &this->m_bEnabled;
  if ( this->m_bEnabled.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bEnabled->m_Value = false;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x360u);
      p_m_bEnabled->m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022CFD0
// Name: public: void CSunlightShadowControl::InputSetEnableShadows(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSunlightShadowControl::InputSetEnableShadows(CSunlightShadowControl *this, inputdata_t *inputdata)
{
  bool v2; // bl
  CNetworkVarBase<bool,CSunlightShadowControl::NetworkVar_m_bEnableShadows> *p_m_bEnableShadows; // esi
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
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x480u);
      p_m_bEnableShadows->m_Value = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022D030
// Name: public: void CSunlightShadowControl::InputSetLightColor(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSunlightShadowControl::InputSetLightColor(CSunlightShadowControl *this, inputdata_t *inputdata)
{
  inputdata = (inputdata_t *)inputdata->value.iszVal.pszValue;
  CNetworkColor32Base<color32_s,CSunlightShadowControl::NetworkVar_m_LightColor>::operator=(
    this: &this->m_LightColor,
    val: (CNetworkColor32Base<color32_s,CSunlightShadowControl::NetworkVar_m_LightColor> *)&inputdata);
}

//------------------------------------------------------------------------------
// Address: 0x1022D050
// Name: public: void CNetworkColor32Base<struct color32_s,class CSunlightShadowControl::NetworkVar_m_LightColor>::Init(unsigned char,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkColor32Base<color32_s,CSunlightShadowControl::NetworkVar_m_LightColor>::Init(
        CNetworkColor32Base<color32_s,CSunlightShadowControl::NetworkVar_m_LightColor> *this,
        unsigned __int8 rVal,
        unsigned __int8 gVal,
        unsigned __int8 bVal,
        unsigned __int8 aVal)
{
  char *v6; // eax
  CBaseEdict *v7; // ecx
  char *v8; // eax
  CBaseEdict *v9; // ecx
  char *v10; // eax
  CBaseEdict *v11; // ecx
  char *v12; // eax
  CBaseEdict *v13; // ecx

  if ( this->m_Value.r != rVal )
  {
    v6 = (char *)this - 1126;
    if ( *((_BYTE *)this - 1042) != 0 )
    {
      v6[88] |= 1u;
    }
    else
    {
      v7 = *((CBaseEdict **)v6 + 6);
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: v7, offset: 0x466u);
    }
    this->m_Value.r = rVal;
  }
  if ( this->m_Value.g != gVal )
  {
    v8 = (char *)this - 1126;
    if ( *((_BYTE *)this - 1042) != 0 )
    {
      v8[88] |= 1u;
    }
    else
    {
      v9 = *((CBaseEdict **)v8 + 6);
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: v9, offset: 0x466u);
    }
    this->m_Value.g = gVal;
  }
  if ( this->m_Value.b != bVal )
  {
    v10 = (char *)this - 1126;
    if ( *((_BYTE *)this - 1042) != 0 )
    {
      v10[88] |= 1u;
    }
    else
    {
      v11 = *((CBaseEdict **)v10 + 6);
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: v11, offset: 0x466u);
    }
    this->m_Value.b = bVal;
  }
  if ( this->m_Value.a != aVal )
  {
    v12 = (char *)this - 1126;
    if ( *((_BYTE *)this - 1042) != 0 )
    {
      v12[88] |= 1u;
      this->m_Value.a = aVal;
    }
    else
    {
      v13 = *((CBaseEdict **)v12 + 6);
      if ( v13 != nullptr )
        CBaseEdict::StateChanged(this: v13, offset: 0x466u);
      this->m_Value.a = aVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022D130
// Name: public: CSunlightShadowControl::CSunlightShadowControl(void)
// Source: json
//------------------------------------------------------------------------------
CSunlightShadowControl *__thiscall CSunlightShadowControl::CSunlightShadowControl(CSunlightShadowControl *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  CSunlightShadowControl *result; // eax
  edict_t *v7; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CSunlightShadowControl_vtbl *)&CSunlightShadowControl::`vftable';
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
    {
      m_pPev->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &m_pPev->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
  }
  _V_strcpy(dest: this->m_TextureName.m_Value, src: "effects/flashlight001");
  CNetworkColor32Base<color32_s,CSunlightShadowControl::NetworkVar_m_LightColor>::Init(
    this: &this->m_LightColor,
    rVal: 0xFFu,
    gVal: 0xFFu,
    bVal: 0xFFu,
    aVal: 1u);
  if ( this->m_flColorTransitionTime.m_Value != 0.5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x46Cu);
    }
    this->m_flColorTransitionTime.m_Value = 0.5;
  }
  if ( this->m_flSunDistance.m_Value != 10000.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x470u);
    }
    this->m_flSunDistance.m_Value = 10000.0;
  }
  if ( this->m_flFOV.m_Value != 5.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x474u);
    }
    this->m_flFOV.m_Value = 5.0;
  }
  result = this;
  if ( this->m_bEnableShadows.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bEnableShadows.m_Value = false;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x480u);
      this->m_bEnableShadows.m_Value = false;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040AA20
// Name: _dynamic_initializer_for__sunlight_shadow_control__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__sunlight_shadow_control__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSunlightShadowControl> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &sunlight_shadow_control,
           a3: "sunlight_shadow_control");
}

//------------------------------------------------------------------------------
// Address: 0x1040AA40
// Name: CSunlightShadowControl_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSunlightShadowControl_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSunlightShadowControl>(__formal: nullptr);
  CSunlightShadowControl_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040AA70
// Name: DT_SunlightShadowControl::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SunlightShadowControl::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_SunlightShadowControl::g_SendTable);
  return atexit(func: DT_SunlightShadowControl::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040AA90
// Name: DT_SunlightShadowControl::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SunlightShadowControl::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_SunlightShadowControl::ignored>();
  DT_SunlightShadowControl::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041E370
// Name: DT_SunlightShadowControl::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SunlightShadowControl::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_SunlightShadowControl::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1022D2C0
// Name: struct datamap_t __near * DataMapInit<class CSunlightShadowControl>(class CSunlightShadowControl __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSunlightShadowControl>()
{
  if ( (_S2_214 & 1) == 0 )
  {
    _S2_214 |= 1u;
    nameHolder_405.m_pszBase = "CSunlightShadowControl";
    nameHolder_405.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_405.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_405.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_405.m_Names.m_Size = 0;
    nameHolder_405.m_Names.m_pElements = nullptr;
    nameHolder_405.m_nLenBase = 22;
    atexit(func: DataMapInit_CSunlightShadowControl__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSunlightShadowControl::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CSunlightShadowControl::m_DataMap.dataNumFields = 20;
  CSunlightShadowControl::m_DataMap.dataDesc = &dataDesc_385[1];
  return &CSunlightShadowControl::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1040AA50
// Name: _dynamic_initializer_for__g_CSunlightShadowControl_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CSunlightShadowControl_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CSunlightShadowControl_ClassReg,
           pNetworkName: "CSunlightShadowControl",
           pTable: &DT_SunlightShadowControl::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041E380
// Name: _ServerClassInit_DT_SunlightShadowControl::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_SunlightShadowControl::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_125;
  for ( i = 10; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041E3A0
// Name: _DataMapInit_CSunlightShadowControl__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSunlightShadowControl__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_405);
}
