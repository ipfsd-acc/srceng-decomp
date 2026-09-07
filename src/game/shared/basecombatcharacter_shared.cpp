// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/basecombatcharacter_shared.cpp
// Functions: 22
// ============================================================

#include "game\shared\basecombatcharacter_shared.h"

//------------------------------------------------------------------------------
// Address: 0x1000DD10
// Name: public: virtual int C_BaseCombatCharacter::BloodColor(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatCharacter::BloodColor(C_BaseCombatCharacter *this)
{
  return this->m_bloodColor;
}

//------------------------------------------------------------------------------
// Address: 0x1000DD20
// Name: public: void C_BaseCombatCharacter::SetBloodColor(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatCharacter::SetBloodColor(C_BaseCombatCharacter *this, int nBloodColor)
{
  this->m_bloodColor = nBloodColor;
}

//------------------------------------------------------------------------------
// Address: 0x1000DD30
// Name: public: virtual bool C_BaseCombatCharacter::IsLineOfSightClear(class C_BaseEntity __near *,enum C_BaseCombatCharacter::LineOfSightCheckType)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatCharacter::IsLineOfSightClear(
        C_BaseCombatCharacter *this,
        C_BaseEntity *entity,
        C_BaseCombatCharacter::LineOfSightCheckType checkType)
{
  C_BaseCombatCharacter *v4; // eax
  C_BaseCombatCharacter_vtbl *v5; // ebx
  C_BaseEntity_vtbl *v6; // edx
  int v7; // eax
  int v9; // eax
  _BYTE v10[12]; // [esp+Ch] [ebp-Ch] BYREF

  v4 = entity->MyCombatCharacterPointer(this: entity);
  v5 = this->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  v6 = entity->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v4 != nullptr )
  {
    v7 = ((int (__thiscall *)(C_BaseEntity *, _BYTE *, C_BaseCombatCharacter::LineOfSightCheckType))v6->EyePosition)(
           a1: entity,
           a2: v10,
           a3: checkType);
    return ((bool (__thiscall *)(C_BaseCombatCharacter *, int))v5->IsLineOfSightClear)(a1: this, a2: v7);
  }
  else
  {
    v9 = ((int (__thiscall *)(C_BaseEntity *, C_BaseCombatCharacter::LineOfSightCheckType))v6->WorldSpaceCenter)(
           a1: entity,
           a2: checkType);
    return ((bool (__thiscall *)(C_BaseCombatCharacter *, int))v5->IsLineOfSightClear)(a1: this, a2: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DE50
// Name: public: virtual void CTraceFilterSimple::SetCollisionGroup(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTraceFilterSimple::SetCollisionGroup(CTraceFilterSimple *this, int iCollisionGroup)
{
  this->m_collisionGroup = iCollisionGroup;
}

//------------------------------------------------------------------------------
// Address: 0x1000DE60
// Name: bool FClassnameIs(class C_BaseEntity __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl FClassnameIs(C_BaseEntity *pEntity, const char *szClassname)
{
  return pEntity != nullptr && strcmp(C_BaseEntity::GetClassname(this: pEntity), szClassname) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000DEB0
// Name: public: virtual class C_BaseCombatWeapon __near * C_BaseCombatCharacter::GetActiveWeapon(void)const
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall C_BaseCombatCharacter::GetActiveWeapon(C_BaseCombatCharacter *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hActiveWeapon.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (C_BaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1000DEE0
// Name: public: virtual class C_BaseCombatWeapon __near * C_BaseCombatCharacter::GetWeapon(int)const
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall C_BaseCombatCharacter::GetWeapon(C_BaseCombatCharacter *this, int i)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hMyWeapons[i].m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (C_BaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1000DF20
// Name: public: virtual bool CTraceFilterNoCombatCharacters::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceFilterNoCombatCharacters::ShouldHitEntity(
        CTraceFilterNoCombatCharacters *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  int v3; // eax
  C_BaseEntity *v4; // esi
  bool result; // al

  result = CTraceFilterSimple::ShouldHitEntity(this, a2: (int)pHandleEntity, pHandleEntity, contentsMask)
        && (v3 = ((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[2].SetRefEHandle)(a1: pHandleEntity),
            v4 = (C_BaseEntity *)v3,
            v3 != 0)
        && (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 592))(a1: v3) == 0
        && v4->MyCombatWeaponPointer(this: v4) == nullptr
        && C_BaseEntity::BlocksLOS(this: v4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000DF80
// Name: public: virtual bool C_BaseCombatCharacter::IsLookingTowards(class C_BaseEntity const __near *,float)const
// Source: json
//------------------------------------------------------------------------------
BOOL __userpurge C_BaseCombatCharacter::IsLookingTowards@<eax>(
        C_BaseCombatCharacter *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        C_BaseEntity *target,
        float cosTolerance)
{
  C_BaseCombatCharacter_vtbl *v7; // ebx
  int v8; // eax
  C_BaseCombatCharacter_vtbl *v9; // ebx
  int v10; // eax
  BOOL result; // eax
  _BYTE v14[12]; // [esp+24h] [ebp-Ch] BYREF

  v7 = this->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  v8 = ((int (__thiscall *)(C_BaseEntity *, _DWORD, int, int, int))target->WorldSpaceCenter)(
         a1: target,
         a2: LODWORD(cosTolerance),
         a3,
         a4,
         a5: a2);
  result = true;
  if ( ((unsigned __int8 (__thiscall *)(C_BaseCombatCharacter *, int))v7->IsLookingTowards)(a1: this, a2: v8) == 0 )
  {
    target->EyePosition(this: target, result: (Vector *)v14);
    if ( ((unsigned __int8 (__thiscall *)(C_BaseCombatCharacter *, _BYTE *, _DWORD))this->IsLookingTowards)(
           a1: this,
           a2: v14,
           a3: LODWORD(cosTolerance)) == 0 )
    {
      v9 = this->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      v10 = ((int (__thiscall *)(C_BaseEntity *, _DWORD))target->GetAbsOrigin)(a1: target, a2: LODWORD(cosTolerance));
      if ( ((unsigned __int8 (__thiscall *)(C_BaseCombatCharacter *, int))v9->IsLookingTowards)(a1: this, a2: v10) == 0 )
        return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E030
// Name: public: virtual bool C_BaseCombatCharacter::IsLookingTowards(class Vector const __near &,float)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BaseCombatCharacter::IsLookingTowards(
        C_BaseCombatCharacter *this,
        const Vector *target,
        float cosTolerance)
{
  const QAngle *v4; // eax
  Vector forward; // [esp+4h] [ebp-24h] BYREF
  float v7[3]; // [esp+10h] [ebp-18h] BYREF
  Vector toTarget; // [esp+1Ch] [ebp-Ch] BYREF

  this->EyePosition(this, result: (Vector *)v7);
  toTarget.x = target->x - v7[0];
  toTarget.y = target->y - v7[1];
  toTarget.z = target->z - v7[2];
  VectorNormalize(vec: &toTarget);
  v4 = this->EyeAngles(this);
  AngleVectors(angles: v4, &forward);
  return (float)((float)((float)(forward.y * toTarget.y) + (float)(toTarget.x * forward.x))
               + (float)(forward.z * toTarget.z)) >= cosTolerance;
}

//------------------------------------------------------------------------------
// Address: 0x1000E0E0
// Name: public: virtual bool C_BaseCombatCharacter::IsInFieldOfView(class C_BaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatCharacter::IsInFieldOfView(C_BaseCombatCharacter *this, C_BaseEntity *entity)
{
  const QAngle *v3; // eax
  const Vector *v4; // eax
  const Vector *v6; // eax
  float v7; // xmm1_4
  float v8; // xmm2_4
  Vector *v9; // eax
  float v10; // xmm1_4
  float v11; // xmm2_4
  _BYTE v12[12]; // [esp+4h] [ebp-34h] BYREF
  Vector vecForward; // [esp+10h] [ebp-28h] BYREF
  Vector vecEyePosition; // [esp+1Ch] [ebp-1Ch] BYREF
  Vector vecToTarget; // [esp+28h] [ebp-10h] BYREF
  float flTolerance; // [esp+34h] [ebp-4h]

  if ( this != nullptr && this->IsPlayer(this) )
    flTolerance = cos(
                    ((double (__thiscall *)(C_BaseCombatCharacter *))this->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetObserverCamOrigin)(a1: this)
                  * 0.5
                  * 0.017453292);
  else
    flTolerance = 0.89999998;
  this->EyePosition(this, result: &vecEyePosition);
  v3 = this->EyeAngles(this);
  AngleVectors(angles: v3, forward: &vecForward);
  v4 = entity->GetAbsOrigin(this: entity);
  vecToTarget.x = v4->x - vecEyePosition.x;
  vecToTarget.y = v4->y - vecEyePosition.y;
  vecToTarget.z = v4->z - vecEyePosition.z;
  VectorNormalize(vec: &vecToTarget);
  if ( (float)((float)((float)(vecForward.y * vecToTarget.y) + (float)(vecToTarget.x * vecForward.x))
             + (float)(vecForward.z * vecToTarget.z)) >= flTolerance )
    return true;
  v6 = entity->WorldSpaceCenter(this: entity);
  v7 = v6->y - vecEyePosition.y;
  v8 = v6->z - vecEyePosition.z;
  vecToTarget.x = v6->x - vecEyePosition.x;
  vecToTarget.y = v7;
  vecToTarget.z = v8;
  VectorNormalize(vec: &vecToTarget);
  if ( (float)((float)((float)(vecForward.y * vecToTarget.y) + (float)(vecToTarget.x * vecForward.x))
             + (float)(vecForward.z * vecToTarget.z)) >= flTolerance )
    return true;
  v9 = entity->EyePosition(this: entity, result: v12);
  v10 = v9->y - vecEyePosition.y;
  v11 = v9->z - vecEyePosition.z;
  vecToTarget.x = v9->x - vecEyePosition.x;
  vecToTarget.y = v10;
  vecToTarget.z = v11;
  VectorNormalize(vec: &vecToTarget);
  return (float)((float)((float)(vecForward.y * vecToTarget.y) + (float)(vecToTarget.x * vecForward.x))
               + (float)(vecForward.z * vecToTarget.z)) >= flTolerance;
}

//------------------------------------------------------------------------------
// Address: 0x1000E2D0
// Name: public: virtual bool C_BaseCombatCharacter::IsInFieldOfView(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatCharacter::IsInFieldOfView(C_BaseCombatCharacter *this, const Vector *pos)
{
  float v3; // xmm0_4
  float v5; // [esp+8h] [ebp-4h]

  if ( this != nullptr && this->IsPlayer(this) )
  {
    v5 = cos(
           ((double (__thiscall *)(C_BaseCombatCharacter *))this->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetObserverCamOrigin)(a1: this)
         * 0.5
         * 0.017453292);
    v3 = v5;
  }
  else
  {
    v3 = 0.89999998;
  }
  return ((bool (__thiscall *)(C_BaseCombatCharacter *, const Vector *, _DWORD))this->IsLookingTowards)(
           a1: this,
           a2: pos,
           a3: LODWORD(v3));
}

//------------------------------------------------------------------------------
// Address: 0x1000E540
// Name: public: class IClientVehicle __near * C_BasePlayer::GetVehicle(void)
// Source: json
//------------------------------------------------------------------------------
IClientVehicle *__thiscall C_BasePlayer::GetVehicle(C_BasePlayer *this)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_hVehicle.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    return ((IClientVehicle *(__thiscall *)(IHandleEntity *))m_pEntity->__vftable[31].dtr_IHandleEntity)(a1: m_pEntity);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E580
// Name: public: void C_BaseCombatCharacter::RemoveAmmo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatCharacter::RemoveAmmo(C_BaseCombatCharacter *this, int iCount, int iAmmoIndex)
{
  CCSAmmoDef *AmmoDef; // eax
  int v5; // eax

  if ( iCount > 0 && iAmmoIndex >= 0 )
  {
    AmmoDef = GetAmmoDef();
    if ( !CAmmoDef::CanCarryInfiniteAmmo(this: AmmoDef, nAmmoIndex: iAmmoIndex) )
    {
      v5 = this->m_iAmmo.m_Value[iAmmoIndex] - iCount <= 0 ? 0 : this->m_iAmmo.m_Value[iAmmoIndex] - iCount;
      if ( this->m_iAmmo.m_Value[iAmmoIndex] != v5 )
        this->m_iAmmo.m_Value[iAmmoIndex] = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E5E0
// Name: public: int C_BaseCombatCharacter::GetAmmoCount(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCombatCharacter::GetAmmoCount(C_BaseCombatCharacter *this, int iAmmoIndex)
{
  int result; // eax
  CCSAmmoDef *AmmoDef; // eax
  bool v5; // zf

  if ( iAmmoIndex == -1 )
    return 0;
  AmmoDef = GetAmmoDef();
  v5 = !CAmmoDef::CanCarryInfiniteAmmo(this: AmmoDef, nAmmoIndex: iAmmoIndex);
  result = 999;
  if ( v5 )
    return this->m_iAmmo.m_Value[iAmmoIndex];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E620
// Name: public: virtual class C_BaseCombatWeapon __near * C_BaseCombatCharacter::Weapon_OwnsThisType(char const __near *,int)const
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall C_BaseCombatCharacter::Weapon_OwnsThisType(
        C_BaseCombatCharacter *this,
        const char *pszWeapon,
        const CBaseHandle *iSubType)
{
  CBaseEntityList *v3; // esi
  int v4; // ebx
  CHandle<C_BaseCombatWeapon> *i; // edi
  unsigned int m_Index; // ecx
  int v7; // eax
  CEntInfo *v8; // edx
  unsigned int v9; // ecx
  int v10; // eax
  bool v11; // zf
  C_BaseEntity **v12; // eax
  C_BaseEntity *v13; // eax
  unsigned int v14; // ecx
  IHandleEntity *m_pEntity; // eax
  unsigned int v17; // ecx

  v3 = g_pEntityList;
  v4 = 0;
  for ( i = this->m_hMyWeapons; ; ++i )
  {
    m_Index = i->m_Index;
    if ( i->m_Index != -1 )
    {
      v7 = (unsigned __int16)m_Index;
      v8 = &v3->m_EntPtrArray[(unsigned __int16)m_Index];
      v9 = HIWORD(m_Index);
      if ( v8->m_SerialNumber != v9 )
        goto LABEL_14;
      if ( v8->m_pEntity == nullptr )
        goto LABEL_14;
      v10 = v7;
      v11 = v3->m_EntPtrArray[v10].m_SerialNumber == v9;
      v12 = (C_BaseEntity **)&v3->m_EntPtrArray[v10];
      if ( !v11 )
        goto LABEL_14;
      v13 = *v12;
      if ( v13 == nullptr )
        goto LABEL_14;
      if ( strcmp(C_BaseEntity::GetClassname(this: v13), pszWeapon) == 0 )
      {
        v14 = i->m_Index;
        if ( i->m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
          m_pEntity = nullptr;
        else
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
        if ( m_pEntity->__vftable[74].GetRefEHandle(this: m_pEntity) == iSubType )
          break;
      }
      v3 = g_pEntityList;
    }
LABEL_14:
    if ( ++v4 >= 64 )
      return nullptr;
  }
  v17 = this->m_hMyWeapons[v4].m_Index;
  if ( v17 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_SerialNumber != HIWORD(v17) )
    return nullptr;
  return (C_BaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1000E750
// Name: public: virtual class C_BaseCombatWeapon __near * C_BaseCombatCharacter::Weapon_GetSlot(int)const
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall C_BaseCombatCharacter::Weapon_GetSlot(C_BaseCombatCharacter *this, int slot)
{
  CBaseEntityList *v2; // esi
  int v3; // edi
  CHandle<C_BaseCombatWeapon> *i; // ebx
  unsigned int m_Index; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CEntInfo *v11; // eax
  IHandleEntity *v12; // eax
  unsigned int v14; // ecx

  v2 = g_pEntityList;
  v3 = 0;
  for ( i = this->m_hMyWeapons; ; ++i )
  {
    m_Index = i->m_Index;
    if ( i->m_Index != -1 )
    {
      v6 = (unsigned __int16)m_Index;
      v7 = &v2->m_EntPtrArray[(unsigned __int16)m_Index];
      v8 = HIWORD(m_Index);
      if ( v7->m_SerialNumber != v8 || v7->m_pEntity == nullptr )
        goto LABEL_10;
      v9 = v6;
      v10 = v2->m_EntPtrArray[v9].m_SerialNumber == v8;
      v11 = &v2->m_EntPtrArray[v9];
      v12 = v10 ? v11->m_pEntity : nullptr;
      if ( ((int (__thiscall *)(IHandleEntity *))v12->__vftable[107].SetRefEHandle)(a1: v12) == slot )
        break;
      v2 = g_pEntityList;
    }
LABEL_10:
    if ( ++v3 >= 64 )
      return nullptr;
  }
  v14 = this->m_hMyWeapons[v3].m_Index;
  if ( v14 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
    return nullptr;
  return (C_BaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1000E800
// Name: public: virtual bool C_BaseCombatCharacter::IsLineOfSightClear(class Vector const __near &,enum C_BaseCombatCharacter::LineOfSightCheckType,class C_BaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BaseCombatCharacter::IsLineOfSightClear(
        C_BaseCombatCharacter *this,
        const Vector *pos,
        C_BaseCombatCharacter::LineOfSightCheckType checkType,
        C_BaseEntity *entityToIgnore)
{
  Vector *(__thiscall *EyePosition)(C_BaseEntity *, Vector *); // edx
  CGameTrace trace; // [esp+4h] [ebp-74h] BYREF
  CTraceFilterSkipTwoEntities v8; // [esp+58h] [ebp-20h] BYREF
  Vector vecAbsStart; // [esp+6Ch] [ebp-Ch] BYREF

  if ( checkType == IGNORE_ACTORS )
  {
    CTraceFilterSimple::CTraceFilterSimple(
      this: (CTraceFilterSimple *)&v8.m_pPassEnt,
      passedict: entityToIgnore,
      collisionGroup: 0,
      pExtraShouldHitFunc: nullptr);
    EyePosition = this->EyePosition;
    v8.m_pPassEnt = (const IHandleEntity *)&CTraceFilterNoCombatCharacters::`vftable';
    EyePosition(this, result: &vecAbsStart);
    UTIL_TraceLine(&vecAbsStart, vecAbsEnd: pos, mask: 0x2006081u, pFilter: (ITraceFilter *)&v8.m_pPassEnt, ptr: &trace);
  }
  else
  {
    CTraceFilterSkipTwoEntities::CTraceFilterSkipTwoEntities(
      this: &v8,
      passentity: this,
      passentity2: entityToIgnore,
      collisionGroup: 0);
    this->EyePosition(this, result: &vecAbsStart);
    UTIL_TraceLine(&vecAbsStart, vecAbsEnd: pos, mask: 0x6081u, pFilter: &v8, ptr: &trace);
  }
  return trace.fraction == 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1000EAF0
// Name: public: virtual bool C_BaseCombatCharacter::Weapon_Switch(class C_BaseCombatWeapon __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatCharacter::Weapon_Switch(
        C_BaseCombatCharacter *this,
        C_BaseCombatWeapon *pWeapon,
        int viewmodelindex)
{
  unsigned int m_Index; // eax
  CHandle<C_BaseCombatWeapon> *p_m_hActiveWeapon; // ebx
  C_BaseCombatWeapon *m_pEntity; // edx
  IHandleEntity *v7; // ecx
  CHandle<C_BaseCombatWeapon> v8; // ecx
  IHandleEntity *v9; // eax
  CHandle<C_BaseCombatWeapon> v10; // ecx
  CHandle<C_BaseCombatWeapon> v11; // ecx
  C_BaseCombatWeapon *v12; // eax
  C_BaseCombatWeapon *v13; // eax

  if ( pWeapon == nullptr )
    return false;
  m_Index = this->m_hActiveWeapon.m_Index;
  p_m_hActiveWeapon = &this->m_hActiveWeapon;
  if ( m_Index == -1
    || (p_m_hActiveWeapon = &this->m_hActiveWeapon,
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (C_BaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  if ( m_pEntity != pWeapon )
  {
    if ( this->Weapon_CanSwitchTo(this, a2: pWeapon) )
    {
      v11.m_Index = p_m_hActiveWeapon->m_Index;
      if ( p_m_hActiveWeapon->m_Index == -1
        || g_pEntityList->m_EntPtrArray[LOWORD(v11.m_Index)].m_SerialNumber != HIWORD(v11.m_Index)
        || g_pEntityList->m_EntPtrArray[LOWORD(v11.m_Index)].m_pEntity == nullptr
        || (v12 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: p_m_hActiveWeapon),
            v12->IsAlwaysActive(this: v12))
        || (v13 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: p_m_hActiveWeapon),
            v13->Holster(this: v13, a2: pWeapon)) )
      {
        p_m_hActiveWeapon->m_Index = pWeapon->GetRefEHandle(this: pWeapon)->m_Index;
        return pWeapon->Deploy(this: pWeapon);
      }
    }
    return false;
  }
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    v7 = nullptr;
  else
    v7 = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))v7->__vftable[86].SetRefEHandle)(a1: v7) != 0 )
  {
    v8.m_Index = p_m_hActiveWeapon->m_Index;
    if ( p_m_hActiveWeapon->m_Index == -1
      || g_pEntityList->m_EntPtrArray[LOWORD(v8.m_Index)].m_SerialNumber != HIWORD(v8.m_Index) )
    {
      v9 = nullptr;
    }
    else
    {
      v9 = g_pEntityList->m_EntPtrArray[LOWORD(v8.m_Index)].m_pEntity;
    }
    if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))v9->__vftable[87].SetRefEHandle)(a1: v9) == 0 )
      return false;
  }
  v10.m_Index = p_m_hActiveWeapon->m_Index;
  if ( p_m_hActiveWeapon->m_Index == -1
    || g_pEntityList->m_EntPtrArray[LOWORD(v10.m_Index)].m_SerialNumber != HIWORD(v10.m_Index) )
  {
    return (*(int (__thiscall **)(_DWORD))(MEMORY[0] + 1020))(a1: 0);
  }
  else
  {
    return ((int (__thiscall *)(IHandleEntity *))g_pEntityList->m_EntPtrArray[LOWORD(v10.m_Index)].m_pEntity->__vftable[85].dtr_IHandleEntity)(a1: g_pEntityList->m_EntPtrArray[LOWORD(v10.m_Index)].m_pEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EC90
// Name: public: virtual bool C_BaseCombatCharacter::Weapon_CanSwitchTo(class C_BaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCombatCharacter::Weapon_CanSwitchTo(C_BaseCombatCharacter *this, C_BaseCombatWeapon *pWeapon)
{
  unsigned int v3; // ecx
  IHandleEntity *m_pEntity; // eax
  bool result; // al
  int m_Value; // edi
  CCSAmmoDef *AmmoDef; // eax
  unsigned int m_Index; // ecx
  int v9; // eax
  CEntInfo *v10; // edx
  unsigned int v11; // ecx
  int v12; // eax
  bool v13; // zf
  CEntInfo *v14; // eax
  IHandleEntity *v15; // eax
  int v16; // [esp-Ch] [ebp-10h]

  if ( !this->IsPlayer(this)
    || (v3 = *((_DWORD *)this + 1388)) == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber != HIWORD(v3)
    || (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_pEntity) == nullptr
    || ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[31].dtr_IHandleEntity)(a1: m_pEntity) == 0
    || (result = C_BasePlayer::UsingStandardWeaponsInVehicle((C_BasePlayer *)this)) )
  {
    if ( !pWeapon->HasAnyAmmo(this: pWeapon) )
    {
      m_Value = pWeapon->m_iPrimaryAmmoType.m_Value;
      if ( m_Value == -1 )
        return false;
      v16 = pWeapon->m_iPrimaryAmmoType.m_Value;
      AmmoDef = GetAmmoDef();
      if ( !CAmmoDef::CanCarryInfiniteAmmo(this: AmmoDef, nAmmoIndex: v16) && this->m_iAmmo.m_Value[m_Value] == 0 )
        return false;
    }
    if ( !pWeapon->CanDeploy(this: pWeapon) )
      return false;
    m_Index = this->m_hActiveWeapon.m_Index;
    if ( m_Index == -1 )
      return true;
    v9 = (unsigned __int16)m_Index;
    v10 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v11 = HIWORD(m_Index);
    if ( v10->m_SerialNumber != v11 || v10->m_pEntity == nullptr )
      return true;
    v12 = v9;
    v13 = g_pEntityList->m_EntPtrArray[v12].m_SerialNumber == v11;
    v14 = &g_pEntityList->m_EntPtrArray[v12];
    v15 = v13 ? v14->m_pEntity : nullptr;
    return ((unsigned __int8 (__thiscall *)(IHandleEntity *))v15->__vftable[84].dtr_IHandleEntity)(a1: v15) != 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F9E0
// Name: public: virtual void CCombatCharVisCache::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCombatCharVisCache::LevelShutdownPreEntity(CCombatCharVisCache *this)
{
  CUtlRBTree<CCombatCharVisCache::VisCacheEntry_t,unsigned short,CCombatCharVisCache::CVisCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<CCombatCharVisCache::VisCacheEntry_t,unsigned short>,unsigned short> > *p_m_VisCache; // esi

  p_m_VisCache = &this->m_VisCache;
  CUtlRBTree<CCombatCharVisCache::VisCacheEntry_t,unsigned short,CCombatCharVisCache::CVisCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<CCombatCharVisCache::VisCacheEntry_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_VisCache);
  p_m_VisCache->m_FirstFree = -1;
  if ( p_m_VisCache->m_Elements.m_nGrowSize < 0 )
  {
    p_m_VisCache->m_LastAlloc.index = -1;
  }
  else
  {
    if ( p_m_VisCache->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_VisCache->m_Elements.m_pMemory);
      p_m_VisCache->m_Elements.m_pMemory = nullptr;
    }
    p_m_VisCache->m_Elements.m_nAllocationCount = 0;
    p_m_VisCache->m_LastAlloc.index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FD60
// Name: public: virtual void CCombatCharVisCache::FrameUpdatePreEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCombatCharVisCache::FrameUpdatePreEntityThink(CCombatCharVisCache *this)
{
  CCombatCharVisCache *v1; // edi
  int v2; // eax
  unsigned __int16 v3; // ax
  unsigned __int16 v4; // si
  int v5; // ebx
  UtlRBTreeNode_t<CCombatCharVisCache::VisCacheEntry_t,unsigned short> *m_pMemory; // edx
  int v7; // ebx
  int nMaxIndex; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  v1 = this;
  if ( this->m_VisCache.m_NumElements >= 0x100u )
  {
    v2 = LOWORD(this->m_VisCache.m_Elements.m_nAllocationCount) - 1;
    nMaxIndex = v2;
    v9 = 8;
    while ( 1 )
    {
      v3 = _RandomInt((IUniformRandomStream *)this, a2: 0, a3: v2);
      v4 = v3;
      v5 = v3;
      if ( v3 < v1->m_VisCache.m_Elements.m_nAllocationCount
        && v3 <= v1->m_VisCache.m_LastAlloc.index
        && CUtlRBTree<CCombatCharVisCache::VisCacheEntry_t,unsigned short,CCombatCharVisCache::CVisCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<CCombatCharVisCache::VisCacheEntry_t,unsigned short>,unsigned short>>::LeftChild(
             this: &v1->m_VisCache,
             i: v3) != v3 )
      {
        this = v1;
        m_pMemory = v1->m_VisCache.m_Elements.m_pMemory;
        v7 = v5;
        if ( m_pMemory[v7].m_Data.m_hEntity1.m_Index == -1
          || m_pMemory[v7].m_Data.m_hEntity2.m_Index == -1
          || (this = (CCombatCharVisCache *)gpGlobals.m_Index,
              (float)(*(float *)(gpGlobals.m_Index + 12) - m_pMemory[v7].m_Data.m_flTime) > 10.0) )
        {
          if ( v4 != 0xFFFF )
          {
            CUtlRBTree<CCombatCharVisCache::VisCacheEntry_t,unsigned short,CCombatCharVisCache::CVisCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<CCombatCharVisCache::VisCacheEntry_t,unsigned short>,unsigned short>>::Unlink(
              this: &v1->m_VisCache,
              elem: v4);
            v1->m_VisCache.m_Elements.m_pMemory[v7].m_Left = v4;
            this = (CCombatCharVisCache *)v1->m_VisCache.m_Elements.m_pMemory;
            *(_WORD *)((char *)&this->__vftable + v7 * 24 + 2) = v1->m_VisCache.m_FirstFree;
            --v1->m_VisCache.m_NumElements;
            v1->m_VisCache.m_FirstFree = v4;
          }
        }
      }
      if ( --v9 == 0 )
        break;
      v2 = nMaxIndex;
    }
  }
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x100AAD80
// Name: public: bool CBaseCombatCharacter::SwitchToNextBestWeapon(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatCharacter::SwitchToNextBestWeapon(CBaseCombatCharacter *this, CBaseCombatWeapon *pCurrent)
{
  CBaseCombatWeapon *v3; // eax

  v3 = g_pGameRules->GetNextBestWeapon(this: g_pGameRules, a2: this, a3: pCurrent);
  return v3 != nullptr && v3 != pCurrent && this->Weapon_Switch(this, a2: v3, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100AADC0
// Name: public: virtual int CBaseCombatCharacter::BloodColor(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatCharacter::BloodColor(CBaseCombatCharacter *this)
{
  return this->m_bloodColor;
}

//------------------------------------------------------------------------------
// Address: 0x100AADD0
// Name: public: void CBaseCombatCharacter::SetBloodColor(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::SetBloodColor(CBaseCombatCharacter *this, int nBloodColor)
{
  this->m_bloodColor = nBloodColor;
}

//------------------------------------------------------------------------------
// Address: 0x100AADE0
// Name: public: virtual bool CTraceFilterNoCombatCharacters::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceFilterNoCombatCharacters::ShouldHitEntity(
        CTraceFilterNoCombatCharacters *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  const CBaseHandle *v3; // eax
  CBaseEntity *v4; // esi
  bool result; // al

  result = CTraceFilterSimple::ShouldHitEntity(this, pHandleEntity, contentsMask)
        && !staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: pHandleEntity)
        && (v3 = pHandleEntity->__vftable[1].GetRefEHandle(this: pHandleEntity), v4 = (CBaseEntity *)v3, v3 != nullptr)
        && (*(int (__thiscall **)(const CBaseHandle *))(v3->m_Index + 300))(a1: v3) == 0
        && v4->MyCombatWeaponPointer(this: v4) == nullptr
        && CBaseEntity::BlocksLOS(this: v4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AAE50
// Name: public: virtual bool CBaseCombatCharacter::IsLookingTowards(class CBaseEntity const __near *,float)const
// Source: json
//------------------------------------------------------------------------------
BOOL __userpurge CBaseCombatCharacter::IsLookingTowards@<eax>(
        CBaseCombatCharacter *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CBaseEntity *target,
        float cosTolerance)
{
  CBaseCombatCharacter_vtbl *v7; // ebx
  int v8; // eax
  _BYTE v12[12]; // [esp+24h] [ebp-Ch] BYREF
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  v7 = this->__vftable;
  v8 = ((int (__thiscall *)(CBaseEntity *, _DWORD, int, int, int))target->WorldSpaceCenter)(
         a1: target,
         a2: LODWORD(cosTolerance),
         a3,
         a4,
         a5: a2);
  if ( ((unsigned __int8 (__thiscall *)(CBaseCombatCharacter *, int))v7->IsLookingTowards)(a1: this, a2: v8) != 0 )
    return true;
  target->EyePosition(this: target, result: (Vector *)v12);
  if ( ((unsigned __int8 (__thiscall *)(CBaseCombatCharacter *, _BYTE *, _DWORD))this->IsLookingTowards)(
         a1: this,
         a2: v12,
         a3: LODWORD(cosTolerance)) != 0 )
    return true;
  if ( (target->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: target, a2: (int)&savedregs);
  return ((unsigned __int8 (__thiscall *)(CBaseCombatCharacter *, Vector *, _DWORD))this->IsLookingTowards)(
           a1: this,
           a2: &target->m_vecAbsOrigin,
           a3: LODWORD(cosTolerance)) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100AAF10
// Name: public: virtual bool CBaseCombatCharacter::IsLookingTowards(class Vector const __near &,float)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseCombatCharacter::IsLookingTowards(
        CBaseCombatCharacter *this,
        const Vector *target,
        float cosTolerance)
{
  const QAngle *v4; // eax
  Vector forward; // [esp+4h] [ebp-24h] BYREF
  float v7[3]; // [esp+10h] [ebp-18h] BYREF
  Vector toTarget; // [esp+1Ch] [ebp-Ch] BYREF

  this->EyePosition(this, result: (Vector *)v7);
  toTarget.x = target->x - v7[0];
  toTarget.y = target->y - v7[1];
  toTarget.z = target->z - v7[2];
  VectorNormalize(vec: &toTarget);
  v4 = this->EyeAngles(this);
  AngleVectors(angles: v4, &forward);
  return (float)((float)((float)(forward.y * toTarget.y) + (float)(toTarget.x * forward.x))
               + (float)(forward.z * toTarget.z)) >= cosTolerance;
}

//------------------------------------------------------------------------------
// Address: 0x100AAFC0
// Name: public: virtual bool CBaseCombatCharacter::IsInFieldOfView(class CBaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatCharacter::IsInFieldOfView(CBaseCombatCharacter *this, CBaseEntity *entity)
{
  __m128 v3; // xmm0
  double v4; // xmm0_8
  float v5; // xmm0_4
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  const QAngle *v7; // eax
  const Vector *v9; // eax
  float v10; // xmm1_4
  float v11; // xmm2_4
  Vector *v12; // eax
  float v13; // xmm1_4
  float v14; // xmm2_4
  _BYTE v15[12]; // [esp+4h] [ebp-34h] BYREF
  Vector vecForward; // [esp+10h] [ebp-28h] BYREF
  Vector vecEyePosition; // [esp+1Ch] [ebp-1Ch] BYREF
  Vector vecToTarget; // [esp+28h] [ebp-10h] BYREF
  float flTolerance; // [esp+34h] [ebp-4h]
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  if ( this != nullptr && this->IsPlayer(this) )
  {
    v3 = 0;
    v3.m128_f32[0] = (float)((float)CBasePlayer::GetFOV((CBasePlayer *)this) * 0.5) * 0.017453292;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v3));
    v5 = v4;
  }
  else
  {
    v5 = 0.89999998;
  }
  EyePosition = this->EyePosition;
  flTolerance = v5;
  EyePosition(this, result: &vecEyePosition);
  v7 = this->EyeAngles(this);
  AngleVectors(angles: v7, forward: &vecForward);
  if ( (entity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: entity, a2: (int)&savedregs);
  vecToTarget.x = entity->m_vecAbsOrigin.x - vecEyePosition.x;
  vecToTarget.y = entity->m_vecAbsOrigin.y - vecEyePosition.y;
  vecToTarget.z = entity->m_vecAbsOrigin.z - vecEyePosition.z;
  VectorNormalize(vec: &vecToTarget);
  if ( (float)((float)((float)(vecToTarget.x * vecForward.x) + (float)(vecForward.y * vecToTarget.y))
             + (float)(vecForward.z * vecToTarget.z)) >= flTolerance )
    return true;
  v9 = entity->WorldSpaceCenter(this: entity);
  v10 = v9->y - vecEyePosition.y;
  v11 = v9->z - vecEyePosition.z;
  vecToTarget.x = v9->x - vecEyePosition.x;
  vecToTarget.y = v10;
  vecToTarget.z = v11;
  VectorNormalize(vec: &vecToTarget);
  if ( (float)((float)((float)(vecToTarget.x * vecForward.x) + (float)(vecForward.y * vecToTarget.y))
             + (float)(vecForward.z * vecToTarget.z)) >= flTolerance )
    return true;
  v12 = entity->EyePosition(this: entity, result: v15);
  v13 = v12->y - vecEyePosition.y;
  v14 = v12->z - vecEyePosition.z;
  vecToTarget.x = v12->x - vecEyePosition.x;
  vecToTarget.y = v13;
  vecToTarget.z = v14;
  VectorNormalize(vec: &vecToTarget);
  return (float)((float)((float)(vecToTarget.x * vecForward.x) + (float)(vecForward.y * vecToTarget.y))
               + (float)(vecForward.z * vecToTarget.z)) >= flTolerance;
}

//------------------------------------------------------------------------------
// Address: 0x100AB1D0
// Name: public: virtual bool CBaseCombatCharacter::IsInFieldOfView(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatCharacter::IsInFieldOfView(CBaseCombatCharacter *this, const Vector *pos)
{
  __m128 v3; // xmm0
  double v4; // xmm0_8
  float v5; // xmm0_4

  if ( this != nullptr && this->IsPlayer(this) )
  {
    v3 = 0;
    v3.m128_f32[0] = (float)((float)CBasePlayer::GetFOV((CBasePlayer *)this) * 0.5) * 0.017453292;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v3));
    v5 = v4;
  }
  else
  {
    v5 = 0.89999998;
  }
  return ((bool (__thiscall *)(CBaseCombatCharacter *, const Vector *, _DWORD))this->IsLookingTowards)(
           a1: this,
           a2: pos,
           a3: LODWORD(v5));
}

//------------------------------------------------------------------------------
// Address: 0x100AB240
// Name: public: virtual bool CBaseCombatCharacter::IsLineOfSightClear(class CBaseEntity __near *,enum CBaseCombatCharacter::LineOfSightCheckType)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseCombatCharacter::IsLineOfSightClear(
        CBaseCombatCharacter *this,
        CBaseEntity *entity,
        CBaseCombatCharacter::LineOfSightCheckType checkType)
{
  CBaseEntity_vtbl *v4; // edx
  int v6; // eax
  int v7; // eax
  _BYTE v9[12]; // [esp+Ch] [ebp-10h] BYREF
  CBaseCombatCharacter_vtbl *v10; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF
  CBaseEntity *entitya; // [esp+24h] [ebp+8h]

  v4 = entity->__vftable;
  v10 = this->__vftable;
  v6 = ((int (__thiscall *)(CBaseEntity *, CBaseCombatCharacter::LineOfSightCheckType, CBaseEntity *))v4->WorldSpaceCenter)(
         a1: entity,
         a2: checkType,
         a3: entity);
  if ( ((unsigned __int8 (__thiscall *)(CBaseCombatCharacter *, int))v10->IsLineOfSightClear)(a1: this, a2: v6) != 0 )
    return true;
  entitya = (CBaseEntity *)this->__vftable;
  v7 = ((int (__thiscall *)(CBaseEntity *, _BYTE *, CBaseCombatCharacter::LineOfSightCheckType, CBaseEntity *))entity->EyePosition)(
         a1: entity,
         a2: v9,
         a3: checkType,
         a4: entity);
  if ( (*(unsigned __int8 (__thiscall **)(CBaseCombatCharacter *, int))&entitya[1].m_nTransmitStateOwnedCounter)(
         a1: this,
         a2: v7) != 0 )
    return true;
  if ( (entity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: entity, a2: (int)&savedregs);
  return this->IsLineOfSightClear(this, a2: &entity->m_vecAbsOrigin, a3: checkType, a4: entity);
}

//------------------------------------------------------------------------------
// Address: 0x100AB3D0
// Name: public: class CBaseCombatWeapon __near * CBaseCombatCharacter::GetActiveWeapon(void)const
// Source: json
//------------------------------------------------------------------------------
CBaseCombatWeapon *__thiscall CBaseCombatCharacter::GetActiveWeapon(CBaseCombatCharacter *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hActiveWeapon.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100AB400
// Name: public: class CBaseCombatWeapon __near * CBaseCombatCharacter::GetWeapon(int)const
// Source: json
//------------------------------------------------------------------------------
CBaseCombatWeapon *__thiscall CBaseCombatCharacter::GetWeapon(CBaseCombatCharacter *this, int i)
{
  unsigned int m_Index; // eax

  m_Index = this->m_hMyWeapons.m_Value[i].m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100AB440
// Name: public: void CBaseCombatCharacter::RemoveAmmo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::RemoveAmmo(CBaseCombatCharacter *this, int iCount, int iAmmoIndex)
{
  CAmmoDef *AmmoDef; // eax
  int *v5; // esi
  int v6; // ebx

  if ( iCount > 0 && iAmmoIndex >= 0 )
  {
    AmmoDef = GetAmmoDef();
    if ( !CAmmoDef::CanCarryInfiniteAmmo(this: AmmoDef, nAmmoIndex: iAmmoIndex) )
    {
      v5 = &this->m_iAmmo.m_Value[iAmmoIndex];
      v6 = (*v5 - iCount) & ((*v5 - iCount <= 0) - 1);
      if ( *v5 != v6 )
      {
        this->NetworkStateChanged_m_iAmmo(this, a2: v5);
        *v5 = v6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AB4A0
// Name: public: void CBaseCombatCharacter::RemoveAllAmmo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::RemoveAllAmmo(CBaseCombatCharacter *this)
{
  int i; // edi

  for ( i = 0; i < 32; ++i )
  {
    if ( this->m_iAmmo.m_Value[i] != 0 )
    {
      ((void (__stdcall *)(char *))this->NetworkStateChanged_m_iAmmo)(a1: (char *)&this->m_iAmmo + i * 4);
      this->m_iAmmo.m_Value[i] = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AB4F0
// Name: public: void CBaseCombatCharacter::SetAmmoCount(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatCharacter::SetAmmoCount(CBaseCombatCharacter *this, int iCount, int iAmmoIndex)
{
  int *v3; // esi

  v3 = &this->m_iAmmo.m_Value[iAmmoIndex];
  if ( *v3 != iCount )
  {
    ((void (__stdcall *)(int *))this->NetworkStateChanged_m_iAmmo)(a1: &this->m_iAmmo.m_Value[iAmmoIndex]);
    *v3 = iCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AB520
// Name: public: int CBaseCombatCharacter::GetAmmoCount(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatCharacter::GetAmmoCount(CBaseCombatCharacter *this, int iAmmoIndex)
{
  int result; // eax
  CAmmoDef *AmmoDef; // eax
  bool v5; // zf

  if ( iAmmoIndex == -1 )
    return 0;
  AmmoDef = GetAmmoDef();
  v5 = !CAmmoDef::CanCarryInfiniteAmmo(this: AmmoDef, nAmmoIndex: iAmmoIndex);
  result = 999;
  if ( v5 )
    return this->m_iAmmo.m_Value[iAmmoIndex];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AB560
// Name: public: virtual class CBaseCombatWeapon __near * CBaseCombatCharacter::Weapon_OwnsThisType(char const __near *,int)const
// Source: json
//------------------------------------------------------------------------------
CBaseCombatWeapon *__thiscall CBaseCombatCharacter::Weapon_OwnsThisType(
        CBaseCombatCharacter *this,
        const char *pszWeapon,
        int iSubType)
{
  CBaseEntityList *v3; // esi
  int v4; // ebx
  CBaseCombatCharacter::NetworkVar_m_hMyWeapons *i; // edi
  unsigned int m_Index; // ecx
  int v7; // eax
  CEntInfo *v8; // edx
  unsigned int v9; // ecx
  int v10; // eax
  bool v11; // zf
  CBaseEntity **v12; // eax
  CBaseEntity *v13; // ecx
  unsigned int v14; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v17; // eax

  v3 = g_pEntityList;
  v4 = 0;
  for ( i = &this->m_hMyWeapons; ; i = (CBaseCombatCharacter::NetworkVar_m_hMyWeapons *)((char *)i + 4) )
  {
    m_Index = i->m_Value[0].m_Index;
    if ( i->m_Value[0].m_Index != -1 )
    {
      v7 = (unsigned __int16)m_Index;
      v8 = &v3->m_EntPtrArray[(unsigned __int16)m_Index];
      v9 = HIWORD(m_Index);
      if ( v8->m_SerialNumber != v9 )
        goto LABEL_16;
      if ( v8->m_pEntity == nullptr )
        goto LABEL_16;
      v10 = v7;
      v11 = v3->m_EntPtrArray[v10].m_SerialNumber == v9;
      v12 = (CBaseEntity **)&v3->m_EntPtrArray[v10];
      if ( !v11 )
        goto LABEL_16;
      v13 = *v12;
      if ( *v12 == nullptr )
        goto LABEL_16;
      if ( v13->m_iClassname.pszValue == pszWeapon )
        break;
      if ( CBaseEntity::ClassMatchesComplex(this: v13, pszClassOrWildcard: pszWeapon) != 0 )
      {
        v3 = g_pEntityList;
        break;
      }
LABEL_15:
      v3 = g_pEntityList;
    }
LABEL_16:
    if ( ++v4 >= 64 )
      return nullptr;
  }
  v14 = i->m_Value[0].m_Index;
  if ( i->m_Value[0].m_Index == -1 || v3->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
    m_pEntity = nullptr;
  else
    m_pEntity = v3->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
  if ( ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[77].dtr_IHandleEntity)(a1: m_pEntity) != iSubType )
    goto LABEL_15;
  v17 = this->m_hMyWeapons.m_Value[v4].m_Index;
  if ( v17 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_SerialNumber != HIWORD(v17) )
    return nullptr;
  return (CBaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100AB650
// Name: public: virtual class CBaseCombatWeapon __near * CBaseCombatCharacter::Weapon_GetSlot(int)const
// Source: json
//------------------------------------------------------------------------------
CBaseCombatWeapon *__thiscall CBaseCombatCharacter::Weapon_GetSlot(CBaseCombatCharacter *this, int slot)
{
  CBaseEntityList *v2; // esi
  int v3; // edi
  CBaseCombatCharacter::NetworkVar_m_hMyWeapons *i; // ebx
  unsigned int m_Index; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CEntInfo *v11; // eax
  IHandleEntity *v12; // eax
  unsigned int v14; // eax

  v2 = g_pEntityList;
  v3 = 0;
  for ( i = &this->m_hMyWeapons; ; i = (CBaseCombatCharacter::NetworkVar_m_hMyWeapons *)((char *)i + 4) )
  {
    m_Index = i->m_Value[0].m_Index;
    if ( i->m_Value[0].m_Index != -1 )
    {
      v6 = (unsigned __int16)m_Index;
      v7 = &v2->m_EntPtrArray[(unsigned __int16)m_Index];
      v8 = HIWORD(m_Index);
      if ( v7->m_SerialNumber != v8 || v7->m_pEntity == nullptr )
        goto LABEL_10;
      v9 = v6;
      v10 = v2->m_EntPtrArray[v9].m_SerialNumber == v8;
      v11 = &v2->m_EntPtrArray[v9];
      v12 = v10 ? v11->m_pEntity : nullptr;
      if ( ((int (__thiscall *)(IHandleEntity *))v12->__vftable[109].SetRefEHandle)(a1: v12) == slot )
        break;
      v2 = g_pEntityList;
    }
LABEL_10:
    if ( ++v3 >= 64 )
      return nullptr;
  }
  v14 = this->m_hMyWeapons.m_Value[v3].m_Index;
  if ( v14 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
    return nullptr;
  return (CBaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100AB700
// Name: public: virtual bool CBaseCombatCharacter::IsLineOfSightClear(class Vector const __near &,enum CBaseCombatCharacter::LineOfSightCheckType,class CBaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseCombatCharacter::IsLineOfSightClear(
        CBaseCombatCharacter *this,
        const Vector *pos,
        CBaseCombatCharacter::LineOfSightCheckType checkType,
        CBaseEntity *entityToIgnore)
{
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  CGameTrace trace; // [esp+4h] [ebp-74h] BYREF
  CTraceFilterSkipTwoEntities v8; // [esp+58h] [ebp-20h] BYREF
  Vector vecAbsStart; // [esp+6Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+78h] [ebp+0h] BYREF

  if ( checkType == IGNORE_ACTORS )
  {
    CTraceFilterSimple::CTraceFilterSimple(
      this: (CTraceFilterSimple *)&v8.m_pPassEnt,
      passedict: entityToIgnore,
      collisionGroup: 0,
      pExtraShouldHitFunc: nullptr);
    EyePosition = this->EyePosition;
    v8.m_pPassEnt = (const IHandleEntity *)&CTraceFilterNoCombatCharacters::`vftable';
    EyePosition(this, result: &vecAbsStart);
    UTIL_TraceLine(
      a1: (int)&savedregs,
      a2: (int)this,
      &vecAbsStart,
      vecAbsEnd: pos,
      mask: 0x2006081u,
      pFilter: (ITraceFilter *)&v8.m_pPassEnt,
      ptr: &trace);
  }
  else
  {
    CTraceFilterSkipTwoEntities::CTraceFilterSkipTwoEntities(
      this: &v8,
      passentity: this,
      passentity2: entityToIgnore,
      collisionGroup: 0);
    this->EyePosition(this, result: &vecAbsStart);
    UTIL_TraceLine(
      a1: (int)&savedregs,
      a2: (int)this,
      &vecAbsStart,
      vecAbsEnd: pos,
      mask: 0x6081u,
      pFilter: &v8,
      ptr: &trace);
  }
  return trace.fraction == 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100AB9F0
// Name: public: virtual bool CBaseCombatCharacter::Weapon_CanSwitchTo(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatCharacter::Weapon_CanSwitchTo(CBaseCombatCharacter *this, CBaseCombatWeapon *pWeapon)
{
  bool result; // al
  int m_Value; // esi
  CAmmoDef *AmmoDef; // eax
  unsigned int m_Index; // ecx
  int v7; // eax
  CEntInfo *v8; // edx
  unsigned int v9; // ecx
  int v10; // eax
  bool v11; // zf
  CEntInfo *v12; // eax
  IHandleEntity *v13; // eax
  int v14; // [esp-Ch] [ebp-10h]

  if ( !this->IsPlayer(this)
    || this->GetVehicle(this) == nullptr
    || (result = CBasePlayer::UsingStandardWeaponsInVehicle((CBasePlayer *)this)) )
  {
    if ( !pWeapon->HasAnyAmmo(this: pWeapon) )
    {
      m_Value = pWeapon->m_iPrimaryAmmoType.m_Value;
      if ( m_Value == -1 )
        return false;
      v14 = pWeapon->m_iPrimaryAmmoType.m_Value;
      AmmoDef = GetAmmoDef();
      if ( !CAmmoDef::CanCarryInfiniteAmmo(this: AmmoDef, nAmmoIndex: v14) && this->m_iAmmo.m_Value[m_Value] == 0 )
        return false;
    }
    if ( !pWeapon->CanDeploy(this: pWeapon) )
      return false;
    m_Index = this->m_hActiveWeapon.m_Value.m_Index;
    if ( m_Index == -1 )
      return true;
    v7 = (unsigned __int16)m_Index;
    v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v9 = HIWORD(m_Index);
    if ( v8->m_SerialNumber != v9 || v8->m_pEntity == nullptr )
      return true;
    v10 = v7;
    v11 = g_pEntityList->m_EntPtrArray[v10].m_SerialNumber == v9;
    v12 = &g_pEntityList->m_EntPtrArray[v10];
    v13 = v11 ? v12->m_pEntity : nullptr;
    return ((unsigned __int8 (__thiscall *)(IHandleEntity *))v13->__vftable[86].SetRefEHandle)(a1: v13) != 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ABC90
// Name: public: virtual bool CBaseCombatCharacter::Weapon_Switch(class CBaseCombatWeapon __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCombatCharacter::Weapon_Switch(
        CBaseCombatCharacter *this,
        CBaseCombatWeapon *pWeapon,
        int viewmodelindex)
{
  CBaseCombatWeapon *v3; // ebx
  unsigned int m_Index; // eax
  CNetworkHandleBase<CBaseCombatWeapon,CBaseCombatCharacter::NetworkVar_m_hActiveWeapon> *p_m_hActiveWeapon; // edi
  IHandleEntity *m_pEntity; // edx
  IHandleEntity *v8; // ecx
  CNetworkHandleBase<CBaseCombatWeapon,CBaseCombatCharacter::NetworkVar_m_hActiveWeapon> v9; // eax
  IHandleEntity *v10; // ecx
  CNetworkHandleBase<CBaseCombatWeapon,CBaseCombatCharacter::NetworkVar_m_hActiveWeapon> v11; // eax
  CNetworkHandleBase<CBaseCombatWeapon,CBaseCombatCharacter::NetworkVar_m_hActiveWeapon> v12; // eax
  CBaseEntity *v13; // eax
  CBaseEntity *v14; // eax

  v3 = pWeapon;
  if ( pWeapon == nullptr )
    return false;
  m_Index = this->m_hActiveWeapon.m_Value.m_Index;
  p_m_hActiveWeapon = &this->m_hActiveWeapon;
  if ( m_Index == -1
    || (v3 = pWeapon, g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  if ( m_pEntity != v3 )
  {
    if ( this->Weapon_CanSwitchTo(this, a2: v3) )
    {
      v12.m_Value.m_Index = p_m_hActiveWeapon->m_Value.m_Index;
      if ( p_m_hActiveWeapon->m_Value.m_Index == -1
        || g_pEntityList->m_EntPtrArray[LOWORD(v12.m_Value.m_Index)].m_SerialNumber != HIWORD(v12.m_Value.m_Index)
        || g_pEntityList->m_EntPtrArray[LOWORD(v12.m_Value.m_Index)].m_pEntity == nullptr
        || (v13 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)p_m_hActiveWeapon),
            ((unsigned __int8 (__thiscall *)(CBaseEntity *))v13->__vftable[1].NetworkStateChanged_m_hGroundEntity)(a1: v13) != 0)
        || (v14 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)p_m_hActiveWeapon),
            ((unsigned __int8 (__thiscall *)(CBaseEntity *, CBaseCombatWeapon *))v14->__vftable[1].Event_Killed)(
              a1: v14,
              a2: v3) != 0) )
      {
        CNetworkHandleBase<CBaseCombatWeapon,CBaseCombatCharacter::NetworkVar_m_hActiveWeapon>::Set(
          this: p_m_hActiveWeapon,
          val: v3);
        return v3->Deploy(this: v3);
      }
    }
    return false;
  }
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    v8 = nullptr;
  else
    v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( v8->__vftable[88].GetRefEHandle(this: v8) != nullptr )
  {
    v9.m_Value.m_Index = p_m_hActiveWeapon->m_Value.m_Index;
    if ( p_m_hActiveWeapon->m_Value.m_Index == -1
      || g_pEntityList->m_EntPtrArray[LOWORD(v9.m_Value.m_Index)].m_SerialNumber != HIWORD(v9.m_Value.m_Index) )
    {
      v10 = nullptr;
    }
    else
    {
      v10 = g_pEntityList->m_EntPtrArray[LOWORD(v9.m_Value.m_Index)].m_pEntity;
    }
    if ( v10->__vftable[89].GetRefEHandle(this: v10) == nullptr )
      return false;
  }
  v11.m_Value.m_Index = p_m_hActiveWeapon->m_Value.m_Index;
  if ( p_m_hActiveWeapon->m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[LOWORD(v11.m_Value.m_Index)].m_SerialNumber != HIWORD(v11.m_Value.m_Index) )
  {
    return (*(int (**)(void))(MEMORY[0] + 1048))();
  }
  else
  {
    return ((int (__thiscall *)(IHandleEntity *))g_pEntityList->m_EntPtrArray[LOWORD(v11.m_Value.m_Index)].m_pEntity->__vftable[87].SetRefEHandle)(a1: g_pEntityList->m_EntPtrArray[LOWORD(v11.m_Value.m_Index)].m_pEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AC8B0
// Name: public: virtual void CCombatCharVisCache::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCombatCharVisCache::LevelShutdownPreEntity(CCombatCharVisCache *this)
{
  CUtlRBTree<CCombatCharVisCache::VisCacheEntry_t,unsigned short,CCombatCharVisCache::CVisCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<CCombatCharVisCache::VisCacheEntry_t,unsigned short>,unsigned short> > *p_m_VisCache; // esi

  p_m_VisCache = &this->m_VisCache;
  CUtlRBTree<CCombatCharVisCache::VisCacheEntry_t,unsigned short,CCombatCharVisCache::CVisCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<CCombatCharVisCache::VisCacheEntry_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_VisCache);
  p_m_VisCache->m_FirstFree = -1;
  if ( p_m_VisCache->m_Elements.m_nGrowSize < 0 )
  {
    p_m_VisCache->m_LastAlloc.index = -1;
  }
  else
  {
    if ( p_m_VisCache->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_VisCache->m_Elements.m_pMemory);
      p_m_VisCache->m_Elements.m_pMemory = nullptr;
    }
    p_m_VisCache->m_Elements.m_nAllocationCount = 0;
    p_m_VisCache->m_LastAlloc.index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ACC30
// Name: public: virtual void CCombatCharVisCache::FrameUpdatePreEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCombatCharVisCache::FrameUpdatePreEntityThink(CCombatCharVisCache *this)
{
  CCombatCharVisCache *v1; // edi
  int v2; // eax
  unsigned __int16 v3; // ax
  unsigned __int16 v4; // si
  int v5; // ebx
  UtlRBTreeNode_t<CCombatCharVisCache::VisCacheEntry_t,unsigned short> *m_pMemory; // edx
  int v7; // ebx
  int nMaxIndex; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  v1 = this;
  if ( this->m_VisCache.m_NumElements >= 0x100u )
  {
    v2 = LOWORD(this->m_VisCache.m_Elements.m_nAllocationCount) - 1;
    nMaxIndex = v2;
    v9 = 8;
    while ( 1 )
    {
      v3 = _RandomInt((IUniformRandomStream *)this, a2: 0, a3: v2);
      v4 = v3;
      v5 = v3;
      if ( v3 < v1->m_VisCache.m_Elements.m_nAllocationCount
        && v3 <= v1->m_VisCache.m_LastAlloc.index
        && CUtlRBTree<CCombatCharVisCache::VisCacheEntry_t,unsigned short,CCombatCharVisCache::CVisCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<CCombatCharVisCache::VisCacheEntry_t,unsigned short>,unsigned short>>::LeftChild(
             this: &v1->m_VisCache,
             i: v3) != v3 )
      {
        this = v1;
        m_pMemory = v1->m_VisCache.m_Elements.m_pMemory;
        v7 = v5;
        if ( m_pMemory[v7].m_Data.m_hEntity1.m_Index == -1
          || m_pMemory[v7].m_Data.m_hEntity2.m_Index == -1
          || (this = (CCombatCharVisCache *)gpGlobals, (float)(gpGlobals->curtime - m_pMemory[v7].m_Data.m_flTime) > 10.0) )
        {
          if ( v4 != 0xFFFF )
          {
            CUtlRBTree<CCombatCharVisCache::VisCacheEntry_t,unsigned short,CCombatCharVisCache::CVisCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<CCombatCharVisCache::VisCacheEntry_t,unsigned short>,unsigned short>>::Unlink(
              this: &v1->m_VisCache,
              elem: v4);
            v1->m_VisCache.m_Elements.m_pMemory[v7].m_Left = v4;
            this = (CCombatCharVisCache *)v1->m_VisCache.m_Elements.m_pMemory;
            *(_WORD *)((char *)&this->__vftable + v7 * 24 + 2) = v1->m_VisCache.m_FirstFree;
            --v1->m_VisCache.m_NumElements;
            v1->m_VisCache.m_FirstFree = v4;
          }
        }
      }
      if ( --v9 == 0 )
        break;
      v2 = nMaxIndex;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FF460
// Name: _dynamic_initializer_for__CBaseCombatCharacter::m_aFactions__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CBaseCombatCharacter::m_aFactions__()
{
  return atexit(func: dynamic_atexit_destructor_for__CBaseCombatCharacter::m_aFactions__);
}

//------------------------------------------------------------------------------
// Address: 0x104198E0
// Name: _dynamic_atexit_destructor_for__CBaseCombatCharacter::m_aFactions__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CBaseCombatCharacter::m_aFactions__()
{
  CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>::~CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>(this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&CBaseCombatCharacter::m_aFactions);
}

//------------------------------------------------------------------------------
// Address: 0x103FF470
// Name: _dynamic_initializer_for__g_CleanupDefaultRelationships__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupDefaultRelationships__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_CleanupDefaultRelationships, name: "CCleanupDefaultRelationShips");
  g_CleanupDefaultRelationships.__vftable = (CCleanupDefaultRelationShips_vtbl *)&CCleanupDefaultRelationShips::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupDefaultRelationships__);
}

//------------------------------------------------------------------------------
// Address: 0x104198F0
// Name: _dynamic_atexit_destructor_for__s_CombatCharVisCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_CombatCharVisCache__()
{
  CUtlRBTree<CCombatCharVisCache::VisCacheEntry_t,unsigned short,CCombatCharVisCache::CVisCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<CCombatCharVisCache::VisCacheEntry_t,unsigned short>,unsigned short>>::~CUtlRBTree<CCombatCharVisCache::VisCacheEntry_t,unsigned short,CCombatCharVisCache::CVisCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<CCombatCharVisCache::VisCacheEntry_t,unsigned short>,unsigned short>>(this: &s_CombatCharVisCache.m_VisCache);
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &s_CombatCharVisCache);
}

} // namespace server
