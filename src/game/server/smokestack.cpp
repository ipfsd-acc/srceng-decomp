// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/smokestack.cpp
// Functions: 22
// ============================================================

#include "game\server\smokestack.h"

//------------------------------------------------------------------------------
// Address: 0x10328D20
// Name: public: virtual class ServerClass __near * CSmokeStack::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CSmokeStack::GetServerClass(CSmokeStack *this)
{
  return &g_CSmokeStack_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10328D30
// Name: public: virtual struct datamap_t __near * CSmokeStack::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CSmokeStack::GetDataDescMap(CSmokeStack *this)
{
  return &CSmokeStack::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10329240
// Name: public: virtual void CSmokeStack::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmokeStack::Spawn(CSmokeStack *this)
{
  CNetworkVarBase<int,CSmokeStack::NetworkVar_m_bEmit> *p_m_bEmit; // esi
  edict_t *m_pPev; // ecx

  if ( this->m_InitialState )
  {
    p_m_bEmit = &this->m_bEmit;
    if ( this->m_bEmit.m_Value != 1 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_bEmit->m_Value = 1;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
        p_m_bEmit->m_Value = 1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10329290
// Name: public: virtual void CSmokeStack::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSmokeStack::Precache(CSmokeStack *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  const char *pszValue; // eax
  int v4; // edi
  edict_t *m_pPev; // ecx

  pszValue = this->m_strMaterialModel.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v4 = CBaseEntity::PrecacheModel(a1: a2, name: pszValue, bPreload: true);
  if ( this->m_iMaterialModel.m_Value != v4 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_iMaterialModel.m_Value = v4;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3C0u);
      this->m_iMaterialModel.m_Value = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103292F0
// Name: protected: void CSmokeStack::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmokeStack::InputToggle(CSmokeStack *this, inputdata_t *inputdata)
{
  CNetworkVarBase<int,CSmokeStack::NetworkVar_m_bEmit> *p_m_bEmit; // esi
  int v3; // edi
  edict_t *m_pPev; // ecx

  p_m_bEmit = &this->m_bEmit;
  v3 = this->m_bEmit.m_Value == 0;
  if ( this->m_bEmit.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bEmit->m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
      p_m_bEmit->m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10329340
// Name: protected: void CSmokeStack::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmokeStack::InputTurnOn(CSmokeStack *this, inputdata_t *inputdata)
{
  CNetworkVarBase<int,CSmokeStack::NetworkVar_m_bEmit> *p_m_bEmit; // esi
  edict_t *m_pPev; // ecx

  p_m_bEmit = &this->m_bEmit;
  if ( this->m_bEmit.m_Value != 1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bEmit->m_Value = 1;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
      p_m_bEmit->m_Value = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10329390
// Name: protected: void CSmokeStack::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmokeStack::InputTurnOff(CSmokeStack *this, inputdata_t *inputdata)
{
  CNetworkVarBase<int,CSmokeStack::NetworkVar_m_bEmit> *p_m_bEmit; // esi
  edict_t *m_pPev; // ecx

  p_m_bEmit = &this->m_bEmit;
  if ( this->m_bEmit.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bEmit->m_Value = 0;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
      p_m_bEmit->m_Value = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103293E0
// Name: protected: void CSmokeStack::RecalcWindVector(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmokeStack::RecalcWindVector(CSmokeStack *this)
{
  __m128i v2; // xmm0
  double v3; // xmm0_8
  double v4; // xmm0_8
  float v5; // xmm0_4
  edict_t *m_pPev; // ecx
  float v7; // [esp+4h] [ebp-14h]
  unsigned int v8; // [esp+10h] [ebp-8h]
  float m_WindSpeed; // [esp+14h] [ebp-4h]

  v2 = (__m128i)COERCE_UNSIGNED_INT((float)this->m_WindAngle);
  *(float *)&v8 = *(float *)v2.m128i_i32 * 0.017453292;
  m_WindSpeed = (float)this->m_WindSpeed;
  *(double *)v2.m128i_i64 = (float)(*(float *)v2.m128i_i32 * 0.017453292);
  __libm_sse2_cos(X: v2);
  *(float *)&v3 = v3;
  v7 = *(float *)&v3 * m_WindSpeed;
  __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)v8));
  *(float *)&v4 = v4;
  v5 = *(float *)&v4 * m_WindSpeed;
  if ( v7 != this->m_vWind.m_Value.x || v5 != this->m_vWind.m_Value.y || this->m_vWind.m_Value.z != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3CCu);
    }
    this->m_vWind.m_Value.y = v5;
    this->m_vWind.m_Value.x = v7;
    this->m_vWind.m_Value.z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103294C0
// Name: public: virtual void CSmokeStack::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSmokeStack::Activate(CSmokeStack *this@<ecx>, int a2@<ebp>)
{
  CBaseEntity *i; // edi
  const char *v4; // ecx
  const char *pszValue; // eax
  CSmokeStackLightInfo *p_m_AmbientLight; // esi
  CBaseEntity *m_pEnt; // eax
  CBaseEdict *v8; // eax
  CBaseEntity *v9; // eax
  CBaseEdict *v10; // eax
  CBaseEntity *v11; // eax
  CBaseEdict *v12; // eax
  CBaseEntity *v13; // eax
  CBaseEdict *v14; // eax
  CBaseEntity *v15; // eax
  CBaseEdict *v16; // eax
  int v17; // edi
  edict_t *m_pPev; // ecx

  CBaseEntity::DetectInSkybox(this);
  for ( i = CGlobalEntityList::FindEntityByClassname(
              this: &gEntList,
              pStartEntity: nullptr,
              szName: "env_particlelight");
        i != nullptr;
        i = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: i, szName: "env_particlelight") )
  {
    v4 = (const char *)i[1].m_Network.__vftable;
    if ( v4 == nullptr )
      v4 = locale;
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    if ( pszValue == v4 || _V_stricmp(s1: pszValue, s2: v4) == 0 )
    {
      p_m_AmbientLight = &this->m_AmbientLight;
      if ( LOBYTE(i[1].m_Network.m_pOuter) != 0 )
        p_m_AmbientLight = &this->m_DirLight;
      if ( p_m_AmbientLight->m_flIntensity.m_Value != *(float *)&i[1].__vftable )
      {
        m_pEnt = p_m_AmbientLight->__m_pChainEntity.m_pEnt;
        if ( p_m_AmbientLight->__m_pChainEntity.m_pEnt->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&m_pEnt->m_Network + 76) |= 1u;
        }
        else
        {
          v8 = &m_pEnt->m_Network.m_pPev->CBaseEdict;
          if ( v8 != nullptr )
          {
            v8->m_fStateFlags |= 0x101u;
            CBaseEdict::GetChangeAccessor(this: v8)->m_iChangeInfoSerialNumber = 0;
          }
        }
        p_m_AmbientLight->m_flIntensity.m_Value = *(float *)&i[1].__vftable;
      }
      if ( *(float *)&i[1].m_pfnMoveDone != p_m_AmbientLight->m_vColor.m_Value.x
        || *(float *)&i[1].m_pfnThink != p_m_AmbientLight->m_vColor.m_Value.y
        || *(float *)&i[1].m_Network.__vftable != p_m_AmbientLight->m_vColor.m_Value.z )
      {
        v9 = p_m_AmbientLight->__m_pChainEntity.m_pEnt;
        if ( p_m_AmbientLight->__m_pChainEntity.m_pEnt->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v9->m_Network + 76) |= 1u;
        }
        else
        {
          v10 = &v9->m_Network.m_pPev->CBaseEdict;
          if ( v10 != nullptr )
          {
            v10->m_fStateFlags |= 0x101u;
            CBaseEdict::GetChangeAccessor(this: v10)->m_iChangeInfoSerialNumber = 0;
          }
        }
        p_m_AmbientLight->m_vColor.m_Value.x = *(float *)&i[1].m_pfnMoveDone;
        p_m_AmbientLight->m_vColor.m_Value.y = *(float *)&i[1].m_pfnThink;
        p_m_AmbientLight->m_vColor.m_Value.z = *(float *)&i[1].m_Network.__vftable;
      }
      if ( (i->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: i, a2);
      if ( i->m_vecAbsOrigin.x != p_m_AmbientLight->m_vPos.m_Value.x
        || i->m_vecAbsOrigin.y != p_m_AmbientLight->m_vPos.m_Value.y
        || i->m_vecAbsOrigin.z != p_m_AmbientLight->m_vPos.m_Value.z )
      {
        v11 = p_m_AmbientLight->__m_pChainEntity.m_pEnt;
        if ( p_m_AmbientLight->__m_pChainEntity.m_pEnt->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v11->m_Network + 76) |= 1u;
        }
        else
        {
          v12 = &v11->m_Network.m_pPev->CBaseEdict;
          if ( v12 != nullptr )
          {
            v12->m_fStateFlags |= 0x101u;
            CBaseEdict::GetChangeAccessor(this: v12)->m_iChangeInfoSerialNumber = 0;
          }
        }
        p_m_AmbientLight->m_vPos.m_Value.x = i->m_vecAbsOrigin.x;
        p_m_AmbientLight->m_vPos.m_Value.y = i->m_vecAbsOrigin.y;
        p_m_AmbientLight->m_vPos.m_Value.z = i->m_vecAbsOrigin.z;
      }
    }
  }
  v13 = this->m_AmbientLight.__m_pChainEntity.m_pEnt;
  if ( v13->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&v13->m_Network + 76) |= 1u;
  }
  else
  {
    v14 = &v13->m_Network.m_pPev->CBaseEdict;
    if ( v14 != nullptr )
    {
      v14->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: v14)->m_iChangeInfoSerialNumber = 0;
    }
  }
  v15 = this->m_DirLight.__m_pChainEntity.m_pEnt;
  this->m_AmbientLight.m_vColor.m_Value.x = this->m_AmbientLight.m_vColor.m_Value.x * 0.0039215689;
  this->m_AmbientLight.m_vColor.m_Value.y = this->m_AmbientLight.m_vColor.m_Value.y * 0.0039215689;
  this->m_AmbientLight.m_vColor.m_Value.z = this->m_AmbientLight.m_vColor.m_Value.z * 0.0039215689;
  if ( v15->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&v15->m_Network + 76) |= 1u;
  }
  else
  {
    v16 = &v15->m_Network.m_pPev->CBaseEdict;
    if ( v16 != nullptr )
    {
      v16->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: v16)->m_iChangeInfoSerialNumber = 0;
    }
  }
  this->m_DirLight.m_vColor.m_Value.x = this->m_DirLight.m_vColor.m_Value.x * 0.0039215689;
  this->m_DirLight.m_vColor.m_Value.y = this->m_DirLight.m_vColor.m_Value.y * 0.0039215689;
  this->m_DirLight.m_vColor.m_Value.z = this->m_DirLight.m_vColor.m_Value.z * 0.0039215689;
  CEntityFlame::Activate(this);
  if ( this->m_iMaterialModel.m_Value == -1 )
  {
    v17 = CBaseEntity::PrecacheModel(
            a1: (bool (__cdecl *)(const char *))i,
            name: "particle/SmokeStack.vmt",
            bPreload: true);
    if ( this->m_iMaterialModel.m_Value != v17 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_iMaterialModel.m_Value = v17;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3C0u);
        this->m_iMaterialModel.m_Value = v17;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103297E0
// Name: public: virtual bool CSmokeStack::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSmokeStack::KeyValue(CSmokeStack *this, char *szKeyName, char *szValue)
{
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  const char *v8; // edi
  char *pszValue; // edi
  int v10; // ebx
  edict_t *m_pPev; // ecx
  int v12; // eax
  int v13; // edi
  IBaseFileSystem_vtbl *v14; // esi
  char *v15; // eax
  IBaseFileSystem_vtbl *v16; // esi
  char *v17; // eax
  char pDest[512]; // [esp+8h] [ebp-600h] BYREF
  char szStrippedName[512]; // [esp+208h] [ebp-400h] BYREF
  char str[512]; // [esp+408h] [ebp-200h] BYREF

  if ( _V_stricmp(s1: szKeyName, s2: "Wind") != 0 )
  {
    if ( _V_stricmp(s1: szKeyName, s2: "WindAngle") != 0 )
    {
      if ( _V_stricmp(s1: szKeyName, s2: "WindSpeed") != 0 )
      {
        if ( _V_stricmp(s1: szKeyName, s2: "SmokeMaterial") != 0 )
        {
          return CBaseEntity::KeyValue(this, szKeyName, szValue);
        }
        else
        {
          v8 = szValue;
          if ( V_stristr(pStr: szValue, pSearch: ".vmt") != nullptr )
          {
            this->m_strMaterialModel.pszValue = *(const char **)AllocPooledString(
                                                                  pszValue: (char *)&szValue,
                                                                  pszValuea: v8).pszValue;
          }
          else
          {
            V_snprintf(pDest, maxLen: 512, pFormat: "%s.vmt", v8);
            this->m_strMaterialModel.pszValue = *(const char **)AllocPooledString(
                                                                  pszValue: (char *)&szValue,
                                                                  pszValuea: pDest).pszValue;
          }
          pszValue = (char *)this->m_strMaterialModel.pszValue;
          if ( pszValue == nullptr )
            pszValue = (char *)locale;
          v10 = CBaseEntity::PrecacheModel(a1: (bool (__cdecl *)(const char *))pszValue, name: pszValue, bPreload: true);
          if ( this->m_iMaterialModel.m_Value != v10 )
          {
            if ( this->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&this->m_Network + 76) |= 1u;
            }
            else
            {
              m_pPev = this->m_Network.m_pPev;
              if ( m_pPev != nullptr )
                CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3C0u);
            }
            this->m_iMaterialModel.m_Value = v10;
          }
          v12 = _V_strlen(str: pszValue);
          V_StripExtension(in: pszValue, out: szStrippedName, outSize: v12 + 1);
          szStrippedName[_V_strlen(str: szStrippedName) - 1] = 0;
          v13 = 1;
          V_snprintf(pDest: str, maxLen: 512, pFormat: "%s%d.vmt", szStrippedName, 1);
          v14 = filesystem->IBaseFileSystem::__vftable;
          v15 = UTIL_VarArgs(format: "materials/%s", str);
          if ( v14->FileExists(this: &filesystem->IBaseFileSystem, a2: v15, a3: nullptr) )
          {
            do
            {
              CBaseEntity::PrecacheModel(a1: (bool (__cdecl *)(const char *))v13++, name: str, bPreload: true);
              V_snprintf(pDest: str, maxLen: 512, pFormat: "%s%d.vmt", szStrippedName, v13);
              v16 = filesystem->IBaseFileSystem::__vftable;
              v17 = UTIL_VarArgs(format: "materials/%s", str);
            }
            while ( v16->FileExists(this: &filesystem->IBaseFileSystem, a2: v17, a3: nullptr) );
          }
          return true;
        }
      }
      else
      {
        this->m_WindSpeed = atoi(nptr: szValue);
        CSmokeStack::RecalcWindVector(this);
        return true;
      }
    }
    else
    {
      this->m_WindAngle = atoi(nptr: szValue);
      CSmokeStack::RecalcWindVector(this);
      return true;
    }
  }
  else
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x3CCu);
    }
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x3CCu);
    }
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x3CCu);
    }
    sscanf(string: szValue, format: "%f %f %f", &this->m_vWind, &this->m_vWind.m_Value.y, &this->m_vWind.m_Value.z);
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10329BC0
// Name: public: CSmokeStack::CSmokeStack(void)
// Source: json
//------------------------------------------------------------------------------
CSmokeStack *__thiscall CSmokeStack::CSmokeStack(CSmokeStack *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  CSmokeStack *result; // eax
  edict_t *v7; // ecx

  CBaseParticleEntity::CBaseParticleEntity(this);
  this->__vftable = (CSmokeStack_vtbl *)&CSmokeStack::`vftable';
  this->m_AmbientLight.__m_pChainEntity.m_pEnt = nullptr;
  this->m_DirLight.__m_pChainEntity.m_pEnt = nullptr;
  *(_QWORD *)&this->m_AmbientLight.__m_pChainEntity.m_pEnt = 0;
  *(_QWORD *)&this->m_AmbientLight.m_vPos.m_Value.y = 0;
  *(_QWORD *)&this->m_AmbientLight.m_vColor.m_Value.x = 0;
  *(_QWORD *)&this->m_AmbientLight.m_vColor.m_Value.z = 0;
  *(_QWORD *)&this->m_DirLight.__m_pChainEntity.m_pEnt = 0;
  *(_QWORD *)&this->m_DirLight.m_vPos.m_Value.y = 0;
  *(_QWORD *)&this->m_DirLight.m_vColor.m_Value.x = 0;
  *(_QWORD *)&this->m_DirLight.m_vColor.m_Value.z = 0;
  this->m_AmbientLight.__m_pChainEntity.m_pEnt = this;
  this->m_DirLight.__m_pChainEntity.m_pEnt = this;
  if ( this->m_flTwist.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3B8u);
    }
    this->m_flTwist.m_Value = 0.0;
  }
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
    this: &this->m_clrRender,
    rVal: 0,
    gVal: 0,
    bVal: 0);
  if ( this->m_clrRender.m_Value.a != 0xFF )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0xB8u);
    }
    this->m_clrRender.m_Value.a = -1;
  }
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v4 = this->m_Network.m_pPev;
    if ( v4 != nullptr )
      CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x3CCu);
  }
  this->m_vWind.m_Value.x = 0.0;
  this->m_vWind.m_Value.y = 0.0;
  this->m_vWind.m_Value.z = 0.0;
  this->m_WindSpeed = 0;
  this->m_WindAngle = 0;
  if ( this->m_iMaterialModel.m_Value != -1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x3C0u);
    }
    this->m_iMaterialModel.m_Value = -1;
  }
  result = this;
  if ( this->m_flRollSpeed.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_flRollSpeed.m_Value = 0.0;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x36Cu);
      this->m_flRollSpeed.m_Value = 0.0;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104157E0
// Name: DT_SmokeStack::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SmokeStack::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_SmokeStack::g_SendTable);
  return atexit(func: DT_SmokeStack::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415800
// Name: DT_SmokeStack::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SmokeStack::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_SmokeStack::ignored>();
  DT_SmokeStack::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415830
// Name: CSmokeStackLightInfo_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSmokeStackLightInfo_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSmokeStackLightInfo>(__formal: nullptr);
  CSmokeStackLightInfo_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415840
// Name: CSmokeStack_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSmokeStack_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSmokeStack>(__formal: nullptr);
  CSmokeStack_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421CC0
// Name: DT_SmokeStack::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SmokeStack::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_SmokeStack::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10329AC0
// Name: struct datamap_t __near * DataMapInit<class CSmokeStackLightInfo>(class CSmokeStackLightInfo __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSmokeStackLightInfo>()
{
  if ( (_S3_170 & 1) == 0 )
  {
    _S3_170 |= 1u;
    nameHolder_512.m_pszBase = "CSmokeStackLightInfo";
    nameHolder_512.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_512.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_512.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_512.m_Names.m_Size = 0;
    nameHolder_512.m_Names.m_pElements = nullptr;
    nameHolder_512.m_nLenBase = 20;
    atexit(func: DataMapInit_CSmokeStackLightInfo__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSmokeStackLightInfo::m_DataMap.baseMap = nullptr;
  CSmokeStackLightInfo::m_DataMap.dataNumFields = 3;
  CSmokeStackLightInfo::m_DataMap.dataDesc = &dataDesc_463[1];
  return &CSmokeStackLightInfo::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10329B40
// Name: struct datamap_t __near * DataMapInit<class CSmokeStack>(class CSmokeStack __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSmokeStack>()
{
  if ( (_S4_76 & 1) == 0 )
  {
    _S4_76 |= 1u;
    nameHolder_513.m_pszBase = "CSmokeStack";
    nameHolder_513.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_513.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_513.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_513.m_Names.m_Size = 0;
    nameHolder_513.m_Names.m_pElements = nullptr;
    nameHolder_513.m_nLenBase = 11;
    atexit(func: DataMapInit_CSmokeStack__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSmokeStack::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CSmokeStack::m_DataMap.dataNumFields = 21;
  CSmokeStack::m_DataMap.dataDesc = &dataDesc_464[1];
  return &CSmokeStack::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10415810
// Name: _dynamic_initializer_for__env_smokestack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_smokestack__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CSmokeStack> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_smokestack,
           a3: "env_smokestack");
}

//------------------------------------------------------------------------------
// Address: 0x10421CD0
// Name: _ServerClassInit_DT_SmokeStack::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_SmokeStack::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_318;
  for ( i = 19; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10421CF0
// Name: _DataMapInit_CSmokeStackLightInfo__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSmokeStackLightInfo__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_512);
}

//------------------------------------------------------------------------------
// Address: 0x10421D00
// Name: _DataMapInit_CSmokeStack__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSmokeStack__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_513);
}
