// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/takedamageinfo.cpp
// Functions: 11
// ============================================================

#include "game\shared\takedamageinfo.h"

//------------------------------------------------------------------------------
// Address: 0x10179250
// Name: void CalculateBulletDamageForce(class CTakeDamageInfo __near *,int,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalculateBulletDamageForce(
        CTakeDamageInfo *info,
        int iBulletType,
        const Vector *vecBulletDir,
        const Vector *vecForceOrigin,
        float flScale)
{
  float z; // eax
  CAmmoDef *AmmoDef; // eax
  float m_fValue; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  Vector vecForce; // [esp+4h] [ebp-Ch] BYREF
  float infoa; // [esp+18h] [ebp+8h]

  info->m_vecDamagePosition = *vecForceOrigin;
  z = vecBulletDir->z;
  *(_QWORD *)&vecForce.x = *(_QWORD *)&vecBulletDir->x;
  vecForce.z = z;
  VectorNormalize(vec: &vecForce);
  AmmoDef = GetAmmoDef();
  infoa = CAmmoDef::DamageForce(this: AmmoDef, nAmmoIndex: iBulletType);
  vecForce.x = vecForce.x * infoa;
  vecForce.y = vecForce.y * infoa;
  vecForce.z = vecForce.z * infoa;
  m_fValue = phys_pushscale.m_pParent->m_Value.m_fValue;
  v9 = vecForce.y * m_fValue;
  v10 = vecForce.z * m_fValue;
  info->m_vecDamageForce.x = (float)(vecForce.x * m_fValue) * flScale;
  info->m_vecDamageForce.y = v9 * flScale;
  info->m_vecDamageForce.z = v10 * flScale;
}

//------------------------------------------------------------------------------
// Address: 0x10179310
// Name: protected: void CTakeDamageInfo::Init(class C_BaseEntity __near *,class C_BaseEntity __near *,class C_BaseEntity __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTakeDamageInfo::Init(
        CTakeDamageInfo *this,
        C_BaseEntity *pInflictor,
        C_BaseEntity *pAttacker,
        C_BaseEntity *pWeapon,
        const Vector *damageForce,
        const Vector *damagePosition,
        const Vector *reportedPosition,
        float flDamage,
        int bitsDamageType,
        int iCustomDamage,
        int iObjectsPenetrated)
{
  if ( pInflictor != nullptr )
    this->m_hInflictor.m_Index = pInflictor->GetRefEHandle(this: pInflictor)->m_Index;
  else
    this->m_hInflictor.m_Index = -1;
  if ( pAttacker != nullptr )
  {
    this->m_hAttacker.m_Index = pAttacker->GetRefEHandle(this: pAttacker)->m_Index;
  }
  else if ( pInflictor != nullptr )
  {
    this->m_hAttacker.m_Index = pInflictor->GetRefEHandle(this: pInflictor)->m_Index;
  }
  else
  {
    this->m_hAttacker.m_Index = -1;
  }
  if ( pWeapon != nullptr )
    this->m_hWeapon.m_Index = pWeapon->GetRefEHandle(this: pWeapon)->m_Index;
  else
    this->m_hWeapon.m_Index = -1;
  this->m_iDamageCustom = iCustomDamage;
  this->m_flDamage = flDamage;
  this->m_flMaxDamage = flDamage;
  this->m_flBaseDamage = 3.4028235e38;
  this->m_bitsDamageType = bitsDamageType;
  this->m_vecDamageForce = *damageForce;
  this->m_vecDamagePosition = *damagePosition;
  this->m_vecReportedPosition = *reportedPosition;
  this->m_iAmmoType = -1;
  *(_QWORD *)&this->m_flRadius = 0;
  this->m_iObjectsPenetrated = iObjectsPenetrated;
}

//------------------------------------------------------------------------------
// Address: 0x10179400
// Name: void ClearMultiDamage(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClearMultiDamage()
{
  g_MultiDamage.m_flBaseDamage = 3.4028235e38;
  g_MultiDamage.m_hTarget.m_Index = -1;
  g_MultiDamage.m_hInflictor.m_Index = -1;
  g_MultiDamage.m_hAttacker.m_Index = -1;
  g_MultiDamage.m_hWeapon.m_Index = -1;
  g_MultiDamage.m_flDamage = 0.0;
  g_MultiDamage.m_bitsDamageType = 0;
  g_MultiDamage.m_iDamageCustom = 0;
  g_MultiDamage.m_flMaxDamage = 0.0;
  g_MultiDamage.m_vecDamageForce = vec3_origin;
  g_MultiDamage.m_vecDamagePosition.x = vec3_origin.x;
  g_MultiDamage.m_vecDamagePosition.y = vec3_origin.y;
  g_MultiDamage.m_vecDamagePosition.z = vec3_origin.z;
  g_MultiDamage.m_vecReportedPosition = vec3_origin;
  g_MultiDamage.m_iAmmoType = -1;
  g_MultiDamage.m_flRadius = 0.0;
  g_MultiDamage.m_iDamagedOtherPlayers = 0;
  g_MultiDamage.m_iObjectsPenetrated = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101794D0
// Name: void ApplyMultiDamage(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyMultiDamage()
{
  if ( g_MultiDamage.m_hTarget.m_Index != -1
    && g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_SerialNumber == HIWORD(g_MultiDamage.m_hTarget.m_Index)
    && g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_pEntity != nullptr )
  {
    if ( g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_SerialNumber == HIWORD(g_MultiDamage.m_hTarget.m_Index) )
      g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_pEntity->__vftable[10].SetRefEHandle(
        this: g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_pEntity,
        a2: (const CBaseHandle *)&g_MultiDamage);
    else
      (*(void (__thiscall **)(_DWORD, CMultiDamage *))(MEMORY[0] + 124))(a1: 0, a2: &g_MultiDamage);
    ClearMultiDamage();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10179540
// Name: void AddMultiDamage(class CTakeDamageInfo const __near &,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall AddMultiDamage(int a1@<esi>, const CTakeDamageInfo *info, C_BaseEntity *pEntity)
{
  C_BaseEntity *v3; // edi
  C_BaseEntity *m_pEntity; // eax
  int m_bitsDamageType; // edx
  int m_iDamageCustom; // ecx
  unsigned int m_Index; // eax
  unsigned int v8; // ecx
  C_BaseEntity *v9; // ebx
  unsigned int v10; // ecx
  float z; // ecx
  float v12; // edx
  float v13; // eax
  float m_flMaxDamage; // xmm0_4
  int v15; // [esp+14h] [ebp-24h]
  QAngle m_vecDamageForce; // [esp+1Ch] [ebp-1Ch] BYREF
  int bitsDamageType; // [esp+28h] [ebp-10h]
  int iCustomDamage; // [esp+2Ch] [ebp-Ch]
  int iObjectsPenetrated; // [esp+30h] [ebp-8h]
  C_BaseEntity *pWeapon; // [esp+34h] [ebp-4h]

  v3 = nullptr;
  if ( pEntity != nullptr )
  {
    if ( g_MultiDamage.m_hTarget.m_Index == -1
      || g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_SerialNumber != HIWORD(g_MultiDamage.m_hTarget.m_Index) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_pEntity;
    }
    v15 = a1;
    if ( pEntity != m_pEntity )
    {
      ApplyMultiDamage();
      m_bitsDamageType = info->m_bitsDamageType;
      m_iDamageCustom = info->m_iDamageCustom;
      iObjectsPenetrated = info->m_iObjectsPenetrated;
      m_Index = info->m_hWeapon.m_Index;
      bitsDamageType = m_bitsDamageType;
      iCustomDamage = m_iDamageCustom;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        pWeapon = nullptr;
      else
        pWeapon = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      v8 = info->m_hAttacker.m_Index;
      if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
        v9 = nullptr;
      else
        v9 = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
      v10 = info->m_hInflictor.m_Index;
      if ( v10 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber == HIWORD(v10) )
        v3 = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
      g_MultiDamage.m_hTarget.m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
      CTakeDamageInfo::Init(
        this: &g_MultiDamage,
        pInflictor: v3,
        pAttacker: v9,
        pWeapon,
        damageForce: &vec3_origin,
        damagePosition: &vec3_origin,
        reportedPosition: &vec3_origin,
        flDamage: 0.0,
        bitsDamageType,
        iCustomDamage,
        iObjectsPenetrated);
    }
    g_MultiDamage.m_bitsDamageType |= info->m_bitsDamageType;
    g_MultiDamage.m_flDamage = info->m_flDamage + g_MultiDamage.m_flDamage;
    z = info->m_vecDamageForce.z;
    *(_QWORD *)&m_vecDamageForce.x = *(_QWORD *)&info->m_vecDamageForce.x;
    g_MultiDamage.m_vecDamageForce.x = g_MultiDamage.m_vecDamageForce.x + m_vecDamageForce.x;
    g_MultiDamage.m_vecDamageForce.y = m_vecDamageForce.y + g_MultiDamage.m_vecDamageForce.y;
    m_vecDamageForce.z = z;
    g_MultiDamage.m_vecDamageForce.z = z + g_MultiDamage.m_vecDamageForce.z;
    v12 = info->m_vecDamagePosition.z;
    *(_QWORD *)&m_vecDamageForce.x = *(_QWORD *)&info->m_vecDamagePosition.x;
    *(_QWORD *)&g_MultiDamage.m_vecDamagePosition.x = *(_QWORD *)&m_vecDamageForce.x;
    m_vecDamageForce.z = v12;
    g_MultiDamage.m_vecDamagePosition.z = v12;
    v13 = info->m_vecReportedPosition.z;
    *(_QWORD *)&m_vecDamageForce.x = *(_QWORD *)&info->m_vecReportedPosition.x;
    *(_QWORD *)&g_MultiDamage.m_vecReportedPosition.x = *(_QWORD *)&m_vecDamageForce.x;
    m_vecDamageForce.z = v13;
    g_MultiDamage.m_vecReportedPosition.z = v13;
    m_flMaxDamage = info->m_flMaxDamage;
    if ( g_MultiDamage.m_flMaxDamage > m_flMaxDamage )
      m_flMaxDamage = g_MultiDamage.m_flMaxDamage;
    g_MultiDamage.m_flMaxDamage = m_flMaxDamage;
    g_MultiDamage.m_iAmmoType = info->m_iAmmoType;
    g_MultiDamage.m_uiBulletID = info->m_uiBulletID;
    if ( !g_pGameRules->Damage_NoPhysicsForce(this: g_pGameRules, a2: info->m_bitsDamageType)
      && g_MultiDamage.m_bitsDamageType != 0
      && (vec3_origin.x == g_MultiDamage.m_vecDamageForce.x
       && vec3_origin.y == g_MultiDamage.m_vecDamageForce.y
       && vec3_origin.z == g_MultiDamage.m_vecDamageForce.z
       || vec3_origin.x == g_MultiDamage.m_vecDamagePosition.x
       && vec3_origin.y == g_MultiDamage.m_vecDamagePosition.y
       && vec3_origin.z == g_MultiDamage.m_vecDamagePosition.z)
      && ++warningCount < 10 )
    {
      m_vecDamageForce = (QAngle)g_MultiDamage.m_vecDamageForce;
      if ( Vector::operator==(this: &m_vecDamageForce, src: (const QAngle *)&vec3_origin) )
        _Warning(a1: "AddMultiDamage:  g_MultiDamage.GetDamageForce() == vec3_origin\n", a2: a1);
      m_vecDamageForce = (QAngle)g_MultiDamage.m_vecDamagePosition;
      if ( Vector::operator==(this: &m_vecDamageForce, src: (const QAngle *)&vec3_origin) )
        _Warning(a1: "AddMultiDamage:  g_MultiDamage.GetDamagePosition() == vec3_origin\n", a2: v15);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10179880
// Name: public: CTakeDamageInfo::CTakeDamageInfo(class C_BaseEntity __near *,class C_BaseEntity __near *,float,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CTakeDamageInfo *__thiscall CTakeDamageInfo::CTakeDamageInfo(
        CTakeDamageInfo *this,
        C_BaseEntity *pInflictor,
        C_BaseEntity *pAttacker,
        float flDamage,
        int bitsDamageType,
        int iKillType,
        int iObjectsPenetrated)
{
  this->m_hInflictor.m_Index = -1;
  this->m_hAttacker.m_Index = -1;
  this->m_hWeapon.m_Index = -1;
  CTakeDamageInfo::Init(
    this,
    pInflictor,
    pAttacker,
    pWeapon: nullptr,
    damageForce: &vec3_origin,
    damagePosition: &vec3_origin,
    reportedPosition: &vec3_origin,
    flDamage,
    bitsDamageType,
    iCustomDamage: iKillType,
    iObjectsPenetrated);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1041CAE0
// Name: CTakeDamageInfo_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTakeDamageInfo_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTakeDamageInfo>();
  CTakeDamageInfo_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041CAF0
// Name: CMultiDamage_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CMultiDamage_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CMultiDamage>();
  CMultiDamage_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101798D0
// Name: struct datamap_t __near * DataMapInit<class CTakeDamageInfo>(class CTakeDamageInfo __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTakeDamageInfo>()
{
  if ( (_S5_120 & 1) == 0 )
  {
    _S5_120 |= 1u;
    nameHolder_31.m_pszBase = "CTakeDamageInfo";
    nameHolder_31.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_31.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_31.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_31.m_Names.m_Size = 0;
    nameHolder_31.m_Names.m_pElements = nullptr;
    nameHolder_31.m_nLenBase = 15;
    atexit(func: DataMapInit_CTakeDamageInfo__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTakeDamageInfo::m_DataMap.baseMap = nullptr;
  CTakeDamageInfo::m_DataMap.dataNumFields = 15;
  CTakeDamageInfo::m_DataMap.dataDesc = &dataDesc_30[1];
  return &CTakeDamageInfo::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10179950
// Name: struct datamap_t __near * DataMapInit<class CMultiDamage>(class CMultiDamage __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CMultiDamage>()
{
  if ( (_S6_42 & 1) == 0 )
  {
    _S6_42 |= 1u;
    nameHolder_32.m_pszBase = "CMultiDamage";
    nameHolder_32.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_32.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_32.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_32.m_Names.m_Size = 0;
    nameHolder_32.m_Names.m_pElements = nullptr;
    nameHolder_32.m_nLenBase = 12;
    atexit(func: DataMapInit_CMultiDamage__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CMultiDamage::m_DataMap.baseMap = &CTakeDamageInfo::m_DataMap;
  CMultiDamage::m_DataMap.dataNumFields = 1;
  CMultiDamage::m_DataMap.dataDesc = &dataDesc_31[1];
  return &CMultiDamage::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1041CB00
// Name: _dynamic_initializer_for__g_MultiDamage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_MultiDamage__()
{
  g_MultiDamage.m_vecDamageForce = vec3_origin;
  g_MultiDamage.m_vecDamagePosition.x = vec3_origin.x;
  g_MultiDamage.m_vecDamagePosition.y = vec3_origin.y;
  g_MultiDamage.m_vecDamagePosition.z = vec3_origin.z;
  g_MultiDamage.m_vecReportedPosition = vec3_origin;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10017B20
// Name: public: CTakeDamageInfo::CTakeDamageInfo(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
CTakeDamageInfo *__thiscall CTakeDamageInfo::CTakeDamageInfo(CTakeDamageInfo *this, const CTakeDamageInfo *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1022D380
// Name: public: static void CTakeDamageInfo::DebugGetDamageTypeString(unsigned int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTakeDamageInfo::DebugGetDamageTypeString(unsigned int damageType, char *outbuf, int outbuflength)
{
  char *v3; // ebx
  int v4; // esi
  int v5; // eax
  int i; // edi
  int v7; // eax

  v3 = outbuf;
  v4 = outbuflength;
  if ( damageType == 0 )
  {
    v5 = V_snprintf(pDest: outbuf, maxLen: outbuflength, pFormat: "%s", "GENERIC");
    v4 = outbuflength - v5;
    v3 = &outbuf[v5];
  }
  for ( i = 0; v4 > 0; ++i )
  {
    if ( i >= 30 )
      break;
    if ( ((1 << i) & damageType) != 0 )
    {
      v7 = V_snprintf(pDest: v3, maxLen: v4, pFormat: "%s ", s_DamageTypeToStrTable[i + 1]);
      v4 -= v7;
      v3 += v7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022D3F0
// Name: protected: void CTakeDamageInfo::Init(class CBaseEntity __near *,class CBaseEntity __near *,class CBaseEntity __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTakeDamageInfo::Init(
        CTakeDamageInfo *this,
        CBaseEntity *pInflictor,
        CBaseEntity *pAttacker,
        CBaseEntity *pWeapon,
        const Vector *damageForce,
        const Vector *damagePosition,
        const Vector *reportedPosition,
        float flDamage,
        int bitsDamageType,
        int iCustomDamage,
        int iObjectsPenetrated)
{
  if ( pInflictor != nullptr )
    this->m_hInflictor.m_Index = pInflictor->GetRefEHandle(this: pInflictor)->m_Index;
  else
    this->m_hInflictor.m_Index = -1;
  if ( pAttacker != nullptr )
  {
    this->m_hAttacker.m_Index = pAttacker->GetRefEHandle(this: pAttacker)->m_Index;
  }
  else if ( pInflictor != nullptr )
  {
    this->m_hAttacker.m_Index = pInflictor->GetRefEHandle(this: pInflictor)->m_Index;
  }
  else
  {
    this->m_hAttacker.m_Index = -1;
  }
  if ( pWeapon != nullptr )
    this->m_hWeapon.m_Index = pWeapon->GetRefEHandle(this: pWeapon)->m_Index;
  else
    this->m_hWeapon.m_Index = -1;
  this->m_iDamageCustom = iCustomDamage;
  this->m_flDamage = flDamage;
  this->m_flMaxDamage = flDamage;
  this->m_flBaseDamage = 3.4028235e38;
  this->m_bitsDamageType = bitsDamageType;
  this->m_vecDamageForce = *damageForce;
  this->m_vecDamagePosition = *damagePosition;
  this->m_vecReportedPosition = *reportedPosition;
  this->m_iAmmoType = -1;
  *(_QWORD *)&this->m_flRadius = 0;
  this->m_iObjectsPenetrated = iObjectsPenetrated;
}

//------------------------------------------------------------------------------
// Address: 0x1022D4E0
// Name: public: CTakeDamageInfo::CTakeDamageInfo(void)
// Source: json
//------------------------------------------------------------------------------
CTakeDamageInfo *__thiscall CTakeDamageInfo::CTakeDamageInfo(CTakeDamageInfo *this)
{
  this->m_hInflictor.m_Index = -1;
  this->m_hAttacker.m_Index = -1;
  this->m_hWeapon.m_Index = -1;
  this->m_flDamage = 0.0;
  this->m_flBaseDamage = 3.4028235e38;
  this->m_flMaxDamage = 0.0;
  this->m_bitsDamageType = 0;
  this->m_iDamageCustom = 0;
  this->m_vecDamageForce = vec3_origin;
  this->m_vecDamagePosition = vec3_origin;
  this->m_vecReportedPosition = vec3_origin;
  this->m_iAmmoType = -1;
  this->m_flRadius = 0.0;
  this->m_iDamagedOtherPlayers = 0;
  this->m_iObjectsPenetrated = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1022D5A0
// Name: public: void CTakeDamageInfo::AdjustPlayerDamageInflictedForSkillLevel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTakeDamageInfo::AdjustPlayerDamageInflictedForSkillLevel(CTakeDamageInfo *this)
{
  float m_flDamage; // xmm0_4

  m_flDamage = this->m_flDamage;
  this->m_flBaseDamage = m_flDamage;
  this->m_flDamage = ((double (__stdcall *)(_DWORD))g_pGameRules->AdjustPlayerDamageInflicted)(a1: LODWORD(m_flDamage));
}

//------------------------------------------------------------------------------
// Address: 0x1022D5D0
// Name: void ClearMultiDamage(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClearMultiDamage()
{
  g_MultiDamage.m_flBaseDamage = 3.4028235e38;
  g_MultiDamage.m_hTarget.m_Index = -1;
  g_MultiDamage.m_hInflictor.m_Index = -1;
  g_MultiDamage.m_hAttacker.m_Index = -1;
  g_MultiDamage.m_hWeapon.m_Index = -1;
  g_MultiDamage.m_flDamage = 0.0;
  g_MultiDamage.m_bitsDamageType = 0;
  g_MultiDamage.m_iDamageCustom = 0;
  g_MultiDamage.m_flMaxDamage = 0.0;
  g_MultiDamage.m_vecDamageForce = vec3_origin;
  g_MultiDamage.m_vecDamagePosition.x = vec3_origin.x;
  g_MultiDamage.m_vecDamagePosition.y = vec3_origin.y;
  g_MultiDamage.m_vecDamagePosition.z = vec3_origin.z;
  g_MultiDamage.m_vecReportedPosition = vec3_origin;
  g_MultiDamage.m_iAmmoType = -1;
  g_MultiDamage.m_flRadius = 0.0;
  g_MultiDamage.m_iDamagedOtherPlayers = 0;
  g_MultiDamage.m_iObjectsPenetrated = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1022D6A0
// Name: void CalculateBulletDamageForce(class CTakeDamageInfo __near *,int,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalculateBulletDamageForce(
        CTakeDamageInfo *info,
        int iBulletType,
        const Vector *vecBulletDir,
        const Vector *vecForceOrigin,
        float flScale)
{
  float z; // eax
  CAmmoDef *AmmoDef; // eax
  float m_fValue; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  Vector vecForce; // [esp+4h] [ebp-Ch] BYREF
  float infoa; // [esp+18h] [ebp+8h]

  info->m_vecDamagePosition = *vecForceOrigin;
  z = vecBulletDir->z;
  *(_QWORD *)&vecForce.x = *(_QWORD *)&vecBulletDir->x;
  vecForce.z = z;
  VectorNormalize(vec: &vecForce);
  AmmoDef = GetAmmoDef();
  infoa = CAmmoDef::DamageForce(this: AmmoDef, nAmmoIndex: iBulletType);
  vecForce.x = vecForce.x * infoa;
  vecForce.y = vecForce.y * infoa;
  vecForce.z = vecForce.z * infoa;
  m_fValue = phys_pushscale.m_pParent->m_Value.m_fValue;
  v9 = vecForce.y * m_fValue;
  v10 = vecForce.z * m_fValue;
  info->m_vecDamageForce.x = (float)(vecForce.x * m_fValue) * flScale;
  info->m_vecDamageForce.y = v9 * flScale;
  info->m_vecDamageForce.z = v10 * flScale;
}

//------------------------------------------------------------------------------
// Address: 0x1022D760
// Name: public: CTakeDamageInfo::CTakeDamageInfo(class CBaseEntity __near *,class CBaseEntity __near *,float,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CTakeDamageInfo *__thiscall CTakeDamageInfo::CTakeDamageInfo(
        CTakeDamageInfo *this,
        CBaseEntity *pInflictor,
        CBaseEntity *pAttacker,
        float flDamage,
        int bitsDamageType,
        int iKillType,
        int iObjectsPenetrated)
{
  this->m_hInflictor.m_Index = -1;
  this->m_hAttacker.m_Index = -1;
  this->m_hWeapon.m_Index = -1;
  CTakeDamageInfo::Init(
    this,
    pInflictor,
    pAttacker,
    pWeapon: nullptr,
    damageForce: &vec3_origin,
    damagePosition: &vec3_origin,
    reportedPosition: &vec3_origin,
    flDamage,
    bitsDamageType,
    iCustomDamage: iKillType,
    iObjectsPenetrated);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1022D7B0
// Name: void ApplyMultiDamage(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyMultiDamage()
{
  CBaseEntity *m_pSuppressHost; // esi
  CBaseEntity *m_pEntity; // eax

  if ( g_MultiDamage.m_hTarget.m_Index != -1
    && g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_SerialNumber == HIWORD(g_MultiDamage.m_hTarget.m_Index)
    && g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_pEntity != nullptr )
  {
    if ( te->m_nStatusPushed <= 0 )
      m_pSuppressHost = te->m_pSuppressHost;
    else
      m_pSuppressHost = nullptr;
    te->m_pSuppressHost = nullptr;
    if ( g_MultiDamage.m_hTarget.m_Index == -1
      || g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_SerialNumber != HIWORD(g_MultiDamage.m_hTarget.m_Index) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_pEntity;
    }
    CBaseEntity::TakeDamage(this: m_pEntity, inputInfo: &g_MultiDamage);
    te->m_pSuppressHost = m_pSuppressHost;
    ClearMultiDamage();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022D850
// Name: void AddMultiDamage(class CTakeDamageInfo const __near &,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddMultiDamage(const CTakeDamageInfo *info, CBaseEntity *pEntity)
{
  CBaseEntity *v2; // edi
  CBaseEntity *m_pEntity; // eax
  int m_bitsDamageType; // edx
  int m_iDamageCustom; // ecx
  unsigned int m_Index; // eax
  unsigned int v7; // eax
  CBaseEntity *v8; // ebx
  unsigned int v9; // eax
  float z; // ecx
  float v11; // edx
  float v12; // eax
  float m_flMaxDamage; // xmm0_4
  Vector m_vecDamageForce; // [esp+1Ch] [ebp-1Ch] BYREF
  int bitsDamageType; // [esp+28h] [ebp-10h]
  int iCustomDamage; // [esp+2Ch] [ebp-Ch]
  int iObjectsPenetrated; // [esp+30h] [ebp-8h]
  CBaseEntity *pWeapon; // [esp+34h] [ebp-4h]

  v2 = nullptr;
  if ( pEntity != nullptr )
  {
    if ( g_MultiDamage.m_hTarget.m_Index == -1
      || g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_SerialNumber != HIWORD(g_MultiDamage.m_hTarget.m_Index) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(g_MultiDamage.m_hTarget.m_Index)].m_pEntity;
    }
    if ( pEntity != m_pEntity )
    {
      ApplyMultiDamage();
      m_bitsDamageType = info->m_bitsDamageType;
      m_iDamageCustom = info->m_iDamageCustom;
      iObjectsPenetrated = info->m_iObjectsPenetrated;
      m_Index = info->m_hWeapon.m_Index;
      bitsDamageType = m_bitsDamageType;
      iCustomDamage = m_iDamageCustom;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        pWeapon = nullptr;
      else
        pWeapon = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      v7 = info->m_hAttacker.m_Index;
      if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
        v8 = nullptr;
      else
        v8 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
      v9 = info->m_hInflictor.m_Index;
      if ( v9 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber == HIWORD(v9) )
        v2 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity;
      g_MultiDamage.m_hTarget.m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
      CTakeDamageInfo::Init(
        this: &g_MultiDamage,
        pInflictor: v2,
        pAttacker: v8,
        pWeapon,
        damageForce: &vec3_origin,
        damagePosition: &vec3_origin,
        reportedPosition: &vec3_origin,
        flDamage: 0.0,
        bitsDamageType,
        iCustomDamage,
        iObjectsPenetrated);
    }
    g_MultiDamage.m_bitsDamageType |= info->m_bitsDamageType;
    g_MultiDamage.m_flDamage = info->m_flDamage + g_MultiDamage.m_flDamage;
    z = info->m_vecDamageForce.z;
    *(_QWORD *)&m_vecDamageForce.x = *(_QWORD *)&info->m_vecDamageForce.x;
    g_MultiDamage.m_vecDamageForce.x = g_MultiDamage.m_vecDamageForce.x + m_vecDamageForce.x;
    g_MultiDamage.m_vecDamageForce.y = m_vecDamageForce.y + g_MultiDamage.m_vecDamageForce.y;
    m_vecDamageForce.z = z;
    g_MultiDamage.m_vecDamageForce.z = z + g_MultiDamage.m_vecDamageForce.z;
    v11 = info->m_vecDamagePosition.z;
    *(_QWORD *)&m_vecDamageForce.x = *(_QWORD *)&info->m_vecDamagePosition.x;
    *(_QWORD *)&g_MultiDamage.m_vecDamagePosition.x = *(_QWORD *)&m_vecDamageForce.x;
    m_vecDamageForce.z = v11;
    g_MultiDamage.m_vecDamagePosition.z = v11;
    v12 = info->m_vecReportedPosition.z;
    *(_QWORD *)&m_vecDamageForce.x = *(_QWORD *)&info->m_vecReportedPosition.x;
    *(_QWORD *)&g_MultiDamage.m_vecReportedPosition.x = *(_QWORD *)&m_vecDamageForce.x;
    m_vecDamageForce.z = v12;
    g_MultiDamage.m_vecReportedPosition.z = v12;
    m_flMaxDamage = info->m_flMaxDamage;
    if ( g_MultiDamage.m_flMaxDamage > m_flMaxDamage )
      m_flMaxDamage = g_MultiDamage.m_flMaxDamage;
    g_MultiDamage.m_flMaxDamage = m_flMaxDamage;
    g_MultiDamage.m_iAmmoType = info->m_iAmmoType;
    g_MultiDamage.m_uiBulletID = info->m_uiBulletID;
    if ( !g_pGameRules->Damage_NoPhysicsForce(this: g_pGameRules, a2: info->m_bitsDamageType)
      && g_MultiDamage.m_bitsDamageType != 0
      && (vec3_origin.x == g_MultiDamage.m_vecDamageForce.x
       && vec3_origin.y == g_MultiDamage.m_vecDamageForce.y
       && vec3_origin.z == g_MultiDamage.m_vecDamageForce.z
       || vec3_origin.x == g_MultiDamage.m_vecDamagePosition.x
       && vec3_origin.y == g_MultiDamage.m_vecDamagePosition.y
       && vec3_origin.z == g_MultiDamage.m_vecDamagePosition.z)
      && ++warningCount_0 < 10 )
    {
      m_vecDamageForce = g_MultiDamage.m_vecDamageForce;
      if ( Vector::operator==(this: &m_vecDamageForce, src: &vec3_origin) )
        _Warning(a1: "AddMultiDamage:  g_MultiDamage.GetDamageForce() == vec3_origin\n");
      m_vecDamageForce = g_MultiDamage.m_vecDamagePosition;
      if ( Vector::operator==(this: &m_vecDamageForce, src: &vec3_origin) )
        _Warning(a1: "AddMultiDamage:  g_MultiDamage.GetDamagePosition() == vec3_origin\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022DB90
// Name: void CalculateExplosiveDamageForce(class CTakeDamageInfo __near *,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalculateExplosiveDamageForce(
        CTakeDamageInfo *info,
        const Vector *vecDir,
        const Vector *vecForceOrigin,
        float flScale)
{
  float m_flBaseDamage; // xmm0_4
  double v6; // st7
  float z; // eax
  float m_fValue; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  Vector vecForce; // [esp+Ch] [ebp-Ch] BYREF
  float flForceScale; // [esp+20h] [ebp+8h]
  float flForceScalea; // [esp+20h] [ebp+8h]

  info->m_vecDamagePosition = *vecForceOrigin;
  m_flBaseDamage = info->m_flBaseDamage;
  if ( m_flBaseDamage == 3.4028235e38 )
    m_flBaseDamage = info->m_flDamage;
  flForceScale = m_flBaseDamage * 300.0;
  if ( (float)(m_flBaseDamage * 300.0) > 30000.0 )
    flForceScale = 30000.0;
  v6 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
         a1: random,
         a2: 1062836634,
         a3: 1066611507);
  z = vecDir->z;
  flForceScalea = v6 * flForceScale;
  *(_QWORD *)&vecForce.x = *(_QWORD *)&vecDir->x;
  vecForce.z = z;
  VectorNormalize(vec: &vecForce);
  vecForce.x = vecForce.x * flForceScalea;
  vecForce.y = vecForce.y * flForceScalea;
  vecForce.z = vecForce.z * flForceScalea;
  m_fValue = phys_pushscale.m_pParent->m_Value.m_fValue;
  v9 = vecForce.y * m_fValue;
  v10 = vecForce.z * m_fValue;
  info->m_vecDamageForce.x = (float)(vecForce.x * m_fValue) * flScale;
  info->m_vecDamageForce.y = v9 * flScale;
  info->m_vecDamageForce.z = v10 * flScale;
}

//------------------------------------------------------------------------------
// Address: 0x1022DCA0
// Name: void CalculateMeleeDamageForce(class CTakeDamageInfo __near *,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalculateMeleeDamageForce(
        CTakeDamageInfo *info,
        const Vector *vecMeleeDir,
        const Vector *vecForceOrigin,
        float flScale)
{
  float m_flBaseDamage; // xmm0_4
  float z; // eax
  float m_fValue; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  Vector vecForce; // [esp+4h] [ebp-Ch] BYREF

  info->m_vecDamagePosition = *vecForceOrigin;
  m_flBaseDamage = info->m_flBaseDamage;
  if ( m_flBaseDamage == 3.4028235e38 )
    m_flBaseDamage = info->m_flDamage;
  z = vecMeleeDir->z;
  *(_QWORD *)&vecForce.x = *(_QWORD *)&vecMeleeDir->x;
  vecForce.z = z;
  VectorNormalize(vec: &vecForce);
  vecForce.x = vecForce.x * (float)(m_flBaseDamage * 300.0);
  vecForce.y = vecForce.y * (float)(m_flBaseDamage * 300.0);
  vecForce.z = vecForce.z * (float)(m_flBaseDamage * 300.0);
  m_fValue = phys_pushscale.m_pParent->m_Value.m_fValue;
  v7 = vecForce.y * m_fValue;
  v8 = vecForce.z * m_fValue;
  info->m_vecDamageForce.x = (float)(vecForce.x * m_fValue) * flScale;
  info->m_vecDamageForce.y = v7 * flScale;
  info->m_vecDamageForce.z = v8 * flScale;
}

//------------------------------------------------------------------------------
// Address: 0x1022DD70
// Name: void GuessDamageForce(class CTakeDamageInfo __near *,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GuessDamageForce(
        CTakeDamageInfo *info,
        const Vector *vecForceDir,
        const Vector *vecForceOrigin,
        float flScale)
{
  int m_bitsDamageType; // eax
  CAmmoDef *AmmoDef; // eax
  int v6; // eax

  m_bitsDamageType = info->m_bitsDamageType;
  if ( (m_bitsDamageType & 2) != 0 )
  {
    AmmoDef = GetAmmoDef();
    v6 = CAmmoDef::Index(this: AmmoDef, psz: "SMG1");
    CalculateBulletDamageForce(info, iBulletType: v6, vecBulletDir: vecForceDir, vecForceOrigin, flScale);
  }
  else if ( (m_bitsDamageType & 0x40) != 0 )
  {
    CalculateExplosiveDamageForce(info, vecDir: vecForceDir, vecForceOrigin, flScale);
  }
  else
  {
    CalculateMeleeDamageForce(info, vecMeleeDir: vecForceDir, vecForceOrigin, flScale);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022DDE0
// Name: public: CTakeDamageInfo::CTakeDamageInfo(class CBaseEntity __near *,class CBaseEntity __near *,class Vector const __near &,class Vector const __near &,float,int,int,class Vector __near *,int)
// Source: json
//------------------------------------------------------------------------------
CTakeDamageInfo *__thiscall CTakeDamageInfo::CTakeDamageInfo(
        CTakeDamageInfo *this,
        CBaseEntity *pInflictor,
        CBaseEntity *pAttacker,
        const Vector *damageForce,
        const Vector *damagePosition,
        float flDamage,
        int bitsDamageType,
        int iKillType,
        Vector *reportedPosition,
        int iObjectsPenetrated)
{
  Vector v12; // [esp+14h] [ebp-Ch] BYREF

  this->m_hInflictor.m_Index = -1;
  this->m_hAttacker.m_Index = -1;
  this->m_hWeapon.m_Index = -1;
  v12 = vec3_origin;
  if ( reportedPosition != nullptr )
    v12 = *reportedPosition;
  CTakeDamageInfo::Init(
    this,
    pInflictor,
    pAttacker,
    pWeapon: nullptr,
    damageForce,
    damagePosition,
    reportedPosition: &v12,
    flDamage,
    bitsDamageType,
    iCustomDamage: iKillType,
    iObjectsPenetrated);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1040AAD0
// Name: CTakeDamageInfo_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTakeDamageInfo_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTakeDamageInfo>(__formal: nullptr);
  CTakeDamageInfo_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040AAE0
// Name: CMultiDamage_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CMultiDamage_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CMultiDamage>(__formal: nullptr);
  CMultiDamage_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1022DE70
// Name: struct datamap_t __near * DataMapInit<class CTakeDamageInfo>(class CTakeDamageInfo __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTakeDamageInfo>()
{
  if ( (_S2_215 & 1) == 0 )
  {
    _S2_215 |= 1u;
    nameHolder_406.m_pszBase = "CTakeDamageInfo";
    nameHolder_406.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_406.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_406.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_406.m_Names.m_Size = 0;
    nameHolder_406.m_Names.m_pElements = nullptr;
    nameHolder_406.m_nLenBase = 15;
    atexit(func: DataMapInit_CTakeDamageInfo__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTakeDamageInfo::m_DataMap.baseMap = nullptr;
  CTakeDamageInfo::m_DataMap.dataNumFields = 15;
  CTakeDamageInfo::m_DataMap.dataDesc = &dataDesc_386[1];
  return &CTakeDamageInfo::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022DEF0
// Name: struct datamap_t __near * DataMapInit<class CMultiDamage>(class CMultiDamage __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CMultiDamage>()
{
  if ( (_S3_126 & 1) == 0 )
  {
    _S3_126 |= 1u;
    nameHolder_407.m_pszBase = "CMultiDamage";
    nameHolder_407.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_407.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_407.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_407.m_Names.m_Size = 0;
    nameHolder_407.m_Names.m_pElements = nullptr;
    nameHolder_407.m_nLenBase = 12;
    atexit(func: DataMapInit_CMultiDamage__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CMultiDamage::m_DataMap.baseMap = &CTakeDamageInfo::m_DataMap;
  CMultiDamage::m_DataMap.dataNumFields = 1;
  CMultiDamage::m_DataMap.dataDesc = &dataDesc_387[1];
  return &CMultiDamage::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1040AAF0
// Name: _dynamic_initializer_for__g_MultiDamage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_MultiDamage__()
{
  g_MultiDamage.m_vecDamageForce = vec3_origin;
  g_MultiDamage.m_vecDamagePosition.x = vec3_origin.x;
  g_MultiDamage.m_vecDamagePosition.y = vec3_origin.y;
  g_MultiDamage.m_vecDamagePosition.z = vec3_origin.z;
  g_MultiDamage.m_vecReportedPosition = vec3_origin;
}

} // namespace server
