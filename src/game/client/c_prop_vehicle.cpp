// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_prop_vehicle.cpp
// Functions: 28
// ============================================================

#include "game\client\c_prop_vehicle.h"

//------------------------------------------------------------------------------
// Address: 0x10248EE0
// Name: public: virtual class ClientClass __near * C_PropVehicleDriveable::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_PropVehicleDriveable::GetClientClass(C_PropVehicleDriveable *this)
{
  return &__g_C_PropVehicleDriveableClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x102490E0
// Name: public: virtual struct datamap_t __near * C_PropVehicleDriveable::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_PropVehicleDriveable::GetDataDescMap(C_PropVehicleDriveable *this)
{
  return &C_PropVehicleDriveable::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102490F0
// Name: public: virtual void C_PropVehicleDriveable::OnPreDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PropVehicleDriveable::OnPreDataChanged(C_PropVehicleDriveable *this, DataUpdateType_t updateType)
{
  C_BaseAnimating::OnPreDataChanged(this, updateType);
  this->m_vecEyeExitEndpoint.z = *((float *)&this->m_vecRenderOriginOverride + 3);
}

//------------------------------------------------------------------------------
// Address: 0x10249110
// Name: public: virtual void C_PropVehicleDriveable::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PropVehicleDriveable::ClientThink(C_PropVehicleDriveable *this)
{
  IClientShadowMgr_vtbl *v1; // esi
  unsigned __int16 v2; // ax

  v1 = g_pClientShadowMgr->__vftable;
  v2 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 2) + 24))(a1: (char *)this - 8);
  v1->MarkRenderToTextureShadowDirty(this: g_pClientShadowMgr, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10249140
// Name: public: virtual void C_PropVehicleDriveable::GetVehicleClipPlanes(float __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PropVehicleDriveable::GetVehicleClipPlanes(
        C_PropVehicleDriveable *this,
        float *flZNear,
        float *flZFar)
{
  *flZNear = 6.0;
}

//------------------------------------------------------------------------------
// Address: 0x10249160
// Name: public: virtual int C_PropVehicleDriveable::GetJoystickResponseCurve(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_PropVehicleDriveable::GetJoystickResponseCurve(C_PropVehicleDriveable *this)
{
  if ( joy_response_move_vehicle.m_pParent != nullptr )
    return joy_response_move_vehicle.m_pParent->m_Value.m_nValue;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10249170
// Name: public: virtual class C_BaseCombatCharacter __near * C_PropVehicleDriveable::GetPassenger(int)
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatCharacter *__thiscall C_PropVehicleDriveable::GetPassenger(C_PropVehicleDriveable *this, int nRole)
{
  IClientRenderable_vtbl *v2; // ecx

  if ( nRole != 0 )
    return nullptr;
  v2 = this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable;
  if ( v2 == (IClientRenderable_vtbl *)-1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v2].m_SerialNumber != (unsigned int)v2 >> 16 )
  {
    return nullptr;
  }
  else
  {
    return (C_BaseCombatCharacter *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v2].m_pEntity;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102491B0
// Name: public: virtual int C_PropVehicleDriveable::GetPassengerRole(class C_BaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_PropVehicleDriveable::GetPassengerRole(
        C_PropVehicleDriveable *this,
        C_BaseCombatCharacter *pPassenger)
{
  IClientRenderable_vtbl *v2; // ecx

  v2 = this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable;
  if ( v2 == (IClientRenderable_vtbl *)-1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v2].m_SerialNumber != (unsigned int)v2 >> 16 )
  {
    return -(pPassenger != nullptr);
  }
  else
  {
    return -(pPassenger != g_pEntityList->m_EntPtrArray[(unsigned __int16)v2].m_pEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102491F0
// Name: public: virtual enum ShadowType_t C_PropVehicleDriveable::ShadowCastType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_PropVehicleDriveable::ShadowCastType(C_PropVehicleDriveable *this)
{
  _DWORD *v2; // esi

  if ( *(_DWORD *)&this->m_nOldMuzzleFlashParity == 0 && this->GetClientThinkable(this) != nullptr )
    C_BaseAnimating::LockStudioHdr(this: (C_PropVehicleDriveable *)((char *)this - 4));
  v2 = *(_DWORD **)&this->m_nOldMuzzleFlashParity;
  if ( v2 != nullptr && *v2 != 0 )
    return (this->m_nWaterType & 0x30) != 0 ? 0 : 2;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10249240
// Name: protected: virtual void C_PropVehicleDriveable::RestrictView(float __near *,float __near *,float __near *,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PropVehicleDriveable::RestrictView(
        C_PropVehicleDriveable *this,
        float *pYawBounds,
        float *pPitchBounds,
        float *pRollBounds,
        QAngle *vecViewAngles)
{
  int v6; // eax
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  Vector vehicleEyeOrigin; // [esp+14h] [ebp-18h] BYREF
  QAngle vehicleEyeAngles; // [esp+20h] [ebp-Ch] BYREF
  float flAngleDiff; // [esp+34h] [ebp+8h]
  float flAngleDiffa; // [esp+34h] [ebp+8h]
  float flAngleDiffb; // [esp+34h] [ebp+8h]

  v6 = this->LookupAttachment(this: &this->IClientRenderable, a2: "vehicle_driver_eyes");
  C_BaseAnimating::GetAttachmentLocal(this, iAttachment: v6, origin: &vehicleEyeOrigin, angles: &vehicleEyeAngles);
  if ( pYawBounds != nullptr )
  {
    flAngleDiff = AngleDiff(destAngle: vecViewAngles->y, srcAngle: vehicleEyeAngles.y);
    v8 = *pYawBounds;
    if ( *pYawBounds <= flAngleDiff )
    {
      v8 = pYawBounds[1];
      if ( flAngleDiff <= v8 )
        v8 = flAngleDiff;
    }
    vecViewAngles->y = v8 + vehicleEyeAngles.y;
  }
  if ( pPitchBounds != nullptr )
  {
    flAngleDiffa = AngleDiff(destAngle: vecViewAngles->x, srcAngle: vehicleEyeAngles.x);
    v9 = *pPitchBounds;
    if ( *pPitchBounds <= flAngleDiffa )
    {
      v9 = pPitchBounds[1];
      if ( flAngleDiffa <= v9 )
        v9 = flAngleDiffa;
    }
    vecViewAngles->x = v9 + vehicleEyeAngles.x;
  }
  if ( pRollBounds != nullptr )
  {
    flAngleDiffb = AngleDiff(destAngle: vecViewAngles->z, srcAngle: vehicleEyeAngles.z);
    v10 = *pRollBounds;
    if ( *pRollBounds <= flAngleDiffb )
    {
      v10 = pRollBounds[1];
      if ( flAngleDiffb <= v10 )
        v10 = flAngleDiffb;
    }
    vecViewAngles->z = v10 + vehicleEyeAngles.z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10249370
// Name: public: virtual void C_PropVehicleDriveable::UpdateViewAngles(class C_BasePlayer __near *,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PropVehicleDriveable::UpdateViewAngles(
        C_PropVehicleDriveable *this,
        C_BasePlayer *pLocalPlayer,
        CUserCmd *pCmd)
{
  void (__thiscall *v3)(char *, _DWORD, float *, _DWORD, QAngle *); // eax
  float pitchBounds[2]; // [esp+0h] [ebp-8h] BYREF

  if ( r_VehicleViewClamp.m_pParent != nullptr && r_VehicleViewClamp.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = *(void (__thiscall **)(char *, _DWORD, float *, _DWORD, QAngle *))(*((_DWORD *)this - 814) + 904);
    pitchBounds[0] = -85.0;
    pitchBounds[1] = 25.0;
    v3(a1: (char *)this - 3256, a2: 0, a3: pitchBounds, a4: 0, a5: &pCmd->viewangles);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102493D0
// Name: public: virtual void C_PropVehicleDriveable::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PropVehicleDriveable::OnDataChanged(C_PropVehicleDriveable *this, DataUpdateType_t updateType)
{
  C_PropVehicleDriveable *v2; // ebx
  unsigned int v3; // eax
  float z; // edx
  IHandleEntity *m_pEntity; // eax
  float v6; // edx
  int v7; // xmm0_4
  char *p_z; // ecx
  float v9; // ecx
  int v10; // eax
  CEntInfo *v11; // edx
  int v12; // ecx
  int v13; // eax
  bool v14; // zf
  CEntInfo *v15; // eax
  IHandleEntity *v16; // eax

  v2 = this;
  C_BaseAnimating::OnDataChanged(this, updateType);
  v3 = *((_DWORD *)&v2->m_vecRenderOriginOverride + 3);
  if ( v3 == -1 )
    goto LABEL_14;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber == HIWORD(v3)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_pEntity != nullptr )
  {
    z = this->m_vecEyeExitEndpoint.z;
    if ( z == NAN
      || g_pEntityList->m_EntPtrArray[LOWORD(z)].m_SerialNumber != HIWORD(LODWORD(z))
      || g_pEntityList->m_EntPtrArray[LOWORD(z)].m_pEntity == nullptr )
    {
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber == HIWORD(v3) )
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_pEntity;
      else
        m_pEntity = nullptr;
      (*(void (__thiscall **)(char *, IHandleEntity *))(*((_DWORD *)this - 2) + 896))(
        a1: (char *)this - 8,
        a2: m_pEntity);
      v6 = *((float *)this - 2);
      v7 = -996040704;
      p_z = (char *)this - 8;
LABEL_21:
      (*(void (__thiscall **)(char *, int))(LODWORD(v6) + 456))(a1: p_z, a2: v7);
      return;
    }
  }
  v2 = this;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber != HIWORD(v3)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_pEntity == nullptr )
  {
LABEL_14:
    v9 = v2->m_vecEyeExitEndpoint.z;
    if ( v9 != NAN )
    {
      v10 = LOWORD(v9);
      v11 = &g_pEntityList->m_EntPtrArray[LOWORD(v9)];
      v12 = HIWORD(LODWORD(v9));
      if ( v11->m_SerialNumber == v12 && v11->m_pEntity != nullptr )
      {
        v13 = v10;
        v14 = g_pEntityList->m_EntPtrArray[v13].m_SerialNumber == v12;
        v15 = &g_pEntityList->m_EntPtrArray[v13];
        if ( v14 )
          v16 = v15->m_pEntity;
        else
          v16 = nullptr;
        (*(void (__thiscall **)(float *, IHandleEntity *))(LODWORD(v2[-1].m_ViewSmoothingData.vecAngleDiffMin.z) + 900))(
          a1: &v2[-1].m_ViewSmoothingData.vecAngleDiffMin.z,
          a2: v16);
        v6 = v2[-1].m_ViewSmoothingData.vecAngleDiffMin.z;
        v7 = -1082130432;
        BYTE2(v2->m_ViewSmoothingData.rollLockData.flUnlockTime) = 0;
        p_z = (char *)&v2[-1].m_ViewSmoothingData.vecAngleDiffMin.z;
        goto LABEL_21;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10249520
// Name: public: virtual void C_PropVehicleDriveable::GetVehicleViewPosition(int,class Vector __near *,class QAngle __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PropVehicleDriveable::GetVehicleViewPosition(
        C_PropVehicleDriveable *this,
        int nRole,
        Vector *pAbsOrigin,
        QAngle *pAbsAngles,
        float *pFOV)
{
  IClientRenderable_vtbl *v5; // edx
  C_BasePlayer *m_pEntity; // eax

  v5 = this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable;
  if ( v5 == (IClientRenderable_vtbl *)-1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != (unsigned int)v5 >> 16 )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (C_BasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
  }
  SharedVehicleViewSmoothing(
    pPlayer: m_pEntity,
    pAbsOrigin,
    pAbsAngles,
    bEnterAnimOn: this->m_pfnThink,
    bExitAnimOn: BYTE1(this->m_pfnThink),
    vecEyeExitEndpoint: (const Vector *)&this->m_cellZ,
    pData: (ViewSmoothingData_t *)&this->m_vecAbsVelocity.y,
    pFOV,
    bForceViewToAttachment: false);
}

//------------------------------------------------------------------------------
// Address: 0x10249590
// Name: public: virtual void C_PropVehicleDriveable::DrawHudElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PropVehicleDriveable::DrawHudElements(C_PropVehicleDriveable *this)
{
  CHudIcons *v2; // eax
  CHudTexture *Icon; // edi
  int v4; // xmm0_4
  float v5; // xmm0_4
  int v6; // kr0C_4
  Color *p_m_clrCaution; // eax
  CHudIcons *v8; // eax
  CHudTexture *v9; // eax
  CHudTexture *v10; // edi
  __int64 v11; // rax
  int v12; // eax
  int m_Size; // eax
  unsigned __int8 v14; // al
  int v15; // eax
  int v16; // edx
  CHudIcons *v17; // eax
  CHudTexture *v18; // eax
  CHudTexture *v19; // edi
  __int64 v20; // rax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // edx
  int v25; // [esp-8h] [ebp-38h]
  int v26; // [esp-8h] [ebp-38h]
  int v27; // [esp-8h] [ebp-38h]
  int v28; // [esp-8h] [ebp-38h]
  Vector screen; // [esp+10h] [ebp-20h] BYREF
  double v30; // [esp+1Ch] [ebp-14h]
  Color clr; // [esp+24h] [ebp-Ch] BYREF
  float y; // [esp+28h] [ebp-8h] BYREF
  int x; // [esp+2Ch] [ebp-4h]

  if ( LOBYTE(this->m_vecCellOrigin.z) != 0 )
  {
    v2 = HudIcons();
    Icon = CHudIcons::GetIcon(this: v2, szIcon: "gunhair");
    if ( Icon != nullptr )
    {
      *(float *)&x = (float)(ScreenWidth() / 2);
      y = (float)(ScreenHeight() / 2);
      ScreenTransform(point: (const Vector *)((char *)&this->m_pfnThink + 8), &screen);
      *(float *)&v4 = (double)ScreenWidth() * (float)(screen.x * 0.5) + 0.5 + *(float *)&x;
      x = v4;
      v30 = y;
      v5 = v30 - ((double)ScreenHeight() * (float)(screen.y * 0.5) + 0.5);
      v6 = Icon->rc.bottom - Icon->rc.top;
      *(float *)&x = *(float *)&x - (float)((Icon->rc.right - Icon->rc.left) / 2);
      y = v5 - (float)(v6 / 2);
      if ( BYTE1(this->m_vecCellOrigin.z) != 0 )
        p_m_clrCaution = &GetHud(nSlot: -1)->m_clrCaution;
      else
        p_m_clrCaution = &GetHud(nSlot: -1)->m_clrNormal;
      clr = *p_m_clrCaution;
      CHudTexture::DrawSelf(this: Icon, x: (int)*(float *)&x, (int)y, &clr, flApparentZ: 1.0);
    }
    if ( this->m_iszScriptId != nullptr )
    {
      v8 = HudIcons();
      v9 = CHudIcons::GetIcon(this: v8, szIcon: "dmg_bio");
      v10 = v9;
      if ( v9 != nullptr )
      {
        v11 = v9->rc.bottom - v9->rc.top;
        x = 467 - (((int)v11 - HIDWORD(v11)) >> 1);
        if ( BYTE1(this->m_VarMap.m_Entries.m_pElements) != 0 )
        {
          m_Size = this->m_VarMap.m_Entries.m_Size;
          if ( LOBYTE(this->m_VarMap.m_Entries.m_pElements) != 0 )
            v14 = -1 - 10 * m_Size;
          else
            v14 = 10 * m_Size + 55;
          BYTE2(y) = v14;
          LOWORD(y) = 0;
          HIBYTE(y) = -1;
          v26 = (int)((float)ScreenHeight() * 0.002083333333333333 * (double)x);
          v15 = ScreenWidth();
          CHudTexture::DrawSelf(
            this: v10,
            x: (int)(float)((float)((float)v15 * 0.0015625) * 385.0),
            y: v26,
            clr: (const Color *)&y,
            flApparentZ: 1.0);
          v16 = (this->m_VarMap.m_Entries.m_Size + 1) % 20;
          this->m_VarMap.m_Entries.m_Size = v16;
          if ( v16 == 0 )
            LOBYTE(this->m_VarMap.m_Entries.m_pElements) ^= 1u;
        }
        else
        {
          y = NAN;
          v25 = (int)((float)ScreenHeight() * 0.002083333333333333 * (double)x);
          v12 = ScreenWidth();
          CHudTexture::DrawSelf(
            this: v10,
            x: (int)(float)((float)((float)v12 * 0.0015625) * 385.0),
            y: v25,
            clr: (const Color *)&y,
            flApparentZ: 1.0);
          this->m_VarMap.m_Entries.m_Size = 0;
          LOWORD(this->m_VarMap.m_Entries.m_pElements) = 257;
        }
      }
    }
  }
  if ( this->m_VarMap.m_Entries.m_Memory.m_pMemory != nullptr )
  {
    v17 = HudIcons();
    v18 = CHudIcons::GetIcon(this: v17, szIcon: "dmg_bio");
    v19 = v18;
    if ( v18 != nullptr )
    {
      v20 = v18->rc.bottom - v18->rc.top;
      x = 467 - (((int)v20 - HIDWORD(v20)) >> 1);
      if ( BYTE1(this->m_VarMap.m_lastInterpolationTime) != 0 )
      {
        if ( LOBYTE(this->m_VarMap.m_lastInterpolationTime) != 0 )
          v22 = 255 - 10 * this->m_VarMap.m_nInterpolatedEntries;
        else
          v22 = 10 * this->m_VarMap.m_nInterpolatedEntries + 55;
        LOWORD(y) = 0;
        BYTE2(y) = v22;
        HIBYTE(y) = -1;
        v28 = (int)((float)ScreenHeight() * 0.002083333333333333 * (double)x);
        v23 = ScreenWidth();
        CHudTexture::DrawSelf(
          this: v19,
          x: (int)((float)((float)v23 * 0.0015625) * 410.0),
          y: v28,
          clr: (const Color *)&y,
          flApparentZ: 1.0);
        v24 = (this->m_VarMap.m_nInterpolatedEntries + 1) % 20;
        this->m_VarMap.m_nInterpolatedEntries = v24;
        if ( v24 == 0 )
          LOBYTE(this->m_VarMap.m_lastInterpolationTime) ^= 1u;
      }
      else
      {
        y = NAN;
        v27 = (int)((float)ScreenHeight() * 0.002083333333333333 * (double)x);
        v21 = ScreenWidth();
        CHudTexture::DrawSelf(
          this: v19,
          x: (int)((float)((float)v21 * 0.0015625) * 410.0),
          y: v27,
          clr: (const Color *)&y,
          flApparentZ: 1.0);
        this->m_VarMap.m_nInterpolatedEntries = 0;
        LOWORD(this->m_VarMap.m_lastInterpolationTime) = 257;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102499E0
// Name: public: virtual C_PropVehicleDriveable::~C_PropVehicleDriveable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PropVehicleDriveable::~C_PropVehicleDriveable(C_PropVehicleDriveable *this)
{
  CInterpolatedVarEntryBase<Vector,0> *m_pElements; // eax

  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PropVehicleDriveable_vtbl *)&C_PropVehicleDriveable::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PropVehicleDriveable::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PropVehicleDriveable::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PropVehicleDriveable::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PropVehicleDriveable::`vftable'{for `C_BaseAnimating'};
  this->IClientVehicle::IVehicle::__vftable = (IClientVehicle_vtbl *)&C_PropVehicleDriveable::`vftable'{for `IClientVehicle'};
  this->m_iv_vecGunCrosshair.__vftable = (CInterpolatedVar<Vector>_vtbl *)&CInterpolatedVarArrayBase<Vector,0>::`vftable';
  *(_DWORD *)&this->m_iv_vecGunCrosshair.m_VarHistory.m_firstElement = 0;
  C_BaseEntity::operator delete(pMem: this->m_iv_vecGunCrosshair.m_bLooping);
  C_BaseEntity::operator delete(pMem: (void *)this->m_iv_vecGunCrosshair.m_LastNetworkedValue);
  m_pElements = this->m_iv_vecGunCrosshair.m_VarHistory.m_pElements;
  if ( m_pElements != nullptr )
    C_BaseEntity::operator delete(pMem: &m_pElements[-1].value.z);
  this->m_iv_vecGunCrosshair.m_VarHistory.m_pElements = nullptr;
  this->m_iv_vecGunCrosshair.__vftable = (CInterpolatedVar<Vector>_vtbl *)&IInterpolatedVar::`vftable';
  C_BaseAnimating::~C_BaseAnimating(this);
}

//------------------------------------------------------------------------------
// Address: 0x10249B10
// Name: public: C_PropVehicleDriveable::C_PropVehicleDriveable(void)
// Source: json
//------------------------------------------------------------------------------
C_PropVehicleDriveable *__thiscall C_PropVehicleDriveable::C_PropVehicleDriveable(C_PropVehicleDriveable *this)
{
  float m_fValue; // xmm0_4

  C_BaseAnimating::C_BaseAnimating(this);
  this->IClientVehicle::IVehicle::__vftable = (IClientVehicle_vtbl *)&IClientVehicle::`vftable';
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PropVehicleDriveable_vtbl *)&C_PropVehicleDriveable::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PropVehicleDriveable::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PropVehicleDriveable::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PropVehicleDriveable::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PropVehicleDriveable::`vftable'{for `C_BaseAnimating'};
  this->IClientVehicle::IVehicle::__vftable = (IClientVehicle_vtbl *)&C_PropVehicleDriveable::`vftable'{for `IClientVehicle'};
  this->m_hPlayer.m_Index = -1;
  this->m_iv_vecGunCrosshair.__vftable = (CInterpolatedVar<Vector>_vtbl *)&CInterpolatedVarArrayBase<Vector,0>::`vftable';
  this->m_iv_vecGunCrosshair.m_VarHistory.m_pElements = nullptr;
  *(_DWORD *)&this->m_iv_vecGunCrosshair.m_VarHistory.m_maxElement = 0;
  *(_DWORD *)&this->m_iv_vecGunCrosshair.m_VarHistory.m_count = 0x100000;
  CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0>>::EnsureCapacity(
    this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0> > *)&this->m_iv_vecGunCrosshair.m_VarHistory,
    capSize: (CInterpolatedVarEntryBase<QAngle,0> *)4);
  this->m_iv_vecGunCrosshair.m_pDebugName = "C_PropVehicleDriveable::m_iv_vecGunCrosshair";
  this->m_iv_vecGunCrosshair.m_pValue = nullptr;
  this->m_iv_vecGunCrosshair.m_InterpolationAmount = 0.0;
  *(_WORD *)&this->m_iv_vecGunCrosshair.m_fType = 1;
  this->m_iv_vecGunCrosshair.m_LastNetworkedTime = 0.0;
  this->m_iv_vecGunCrosshair.m_LastNetworkedValue = nullptr;
  this->m_iv_vecGunCrosshair.m_bLooping = nullptr;
  this->m_iv_vecGunCrosshair.__vftable = (CInterpolatedVar<Vector>_vtbl *)&CInterpolatedVar<Vector>::`vftable';
  CInterpolatedVarArrayBase<QAngle,0>::SetMaxCount(
    this: (CInterpolatedVarArrayBase<QAngle,0> *)&this->m_iv_vecGunCrosshair,
    flCurrentTime: 0.0,
    newmax: 1);
  this->m_hPrevPlayer.m_Index = -1;
  memset(dst: (int)&this->m_ViewSmoothingData, value: nullptr, count: sizeof(this->m_ViewSmoothingData));
  this->m_ViewSmoothingData.flPitchCurveZero = 10.0;
  this->m_ViewSmoothingData.flPitchCurveLinear = 45.0;
  this->m_ViewSmoothingData.flRollCurveZero = 20.0;
  this->m_ViewSmoothingData.pVehicle = this;
  this->m_ViewSmoothingData.bClampEyeAngles = true;
  this->m_ViewSmoothingData.bDampenEyePosition = true;
  this->m_ViewSmoothingData.flRollCurveLinear = 90.0;
  m_fValue = default_fov.m_pParent->m_Value.m_fValue;
  this->m_flFOV = m_fValue;
  this->m_ViewSmoothingData.flFOV = m_fValue;
  C_BaseEntity::AddVar(
    this,
    data: (void *)&this->m_vecGunCrosshair,
    watcher: &this->m_iv_vecGunCrosshair,
    type: 2,
    bSetup: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1042AB50
// Name: DT_PropVehicleDriveable::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PropVehicleDriveable::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_PropVehicleDriveable::g_RecvTable);
  return atexit(func: DT_PropVehicleDriveable::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042AB70
// Name: DT_PropVehicleDriveable::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PropVehicleDriveable::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_PropVehicleDriveable::ignored>();
  DT_PropVehicleDriveable::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042AB80
// Name: C_PropVehicleDriveable_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *C_PropVehicleDriveable_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<C_PropVehicleDriveable>();
  C_PropVehicleDriveable_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436620
// Name: DT_PropVehicleDriveable::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PropVehicleDriveable::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_PropVehicleDriveable::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10249AA0
// Name: struct datamap_t __near * DataMapInit<class C_PropVehicleDriveable>(class C_PropVehicleDriveable __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<C_PropVehicleDriveable>()
{
  if ( (_S6_58 & 1) == 0 )
  {
    _S6_58 |= 1u;
    nameHolder_39.m_pszBase = "C_PropVehicleDriveable";
    nameHolder_39.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_39.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_39.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_39.m_Names.m_Size = 0;
    nameHolder_39.m_Names.m_pElements = nullptr;
    nameHolder_39.m_nLenBase = 22;
    atexit(func: DataMapInit_C_PropVehicleDriveable__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  C_PropVehicleDriveable::m_DataMap.baseMap = &C_BaseEntity::m_DataMap;
  C_PropVehicleDriveable::m_DataMap.dataNumFields = 1;
  C_PropVehicleDriveable::m_DataMap.dataDesc = &dataDesc_37[1];
  return &C_PropVehicleDriveable::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10249C60
// Name: _C_PropVehicleDriveable_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_PropVehicleDriveable_CreateObject(int entnum, int serialNum)
{
  C_PropVehicleDriveable *v2; // eax
  C_PropVehicleDriveable *v3; // eax
  C_PropVehicleDriveable *v4; // esi

  v2 = (C_PropVehicleDriveable *)C_BaseEntity::operator new(stAllocateBlock: 0xDC8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_PropVehicleDriveable::C_PropVehicleDriveable(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042AB90
// Name: _dynamic_initializer_for__r_VehicleViewClamp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_VehicleViewClamp__()
{
  ConVar::ConVar(this: &r_VehicleViewClamp, pName: "r_VehicleViewClamp", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_VehicleViewClamp__);
}

//------------------------------------------------------------------------------
// Address: 0x1042ABC0
// Name: _dynamic_initializer_for__g_RecipientFilterPredictionSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RecipientFilterPredictionSystem__()
{
  g_RecipientFilterPredictionSystem.m_pNextSystem = IPredictionSystem::g_pPredictionSystems;
  IPredictionSystem::g_pPredictionSystems = &g_RecipientFilterPredictionSystem;
  return atexit(func: dynamic_atexit_destructor_for__g_RecipientFilterPredictionSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x1042ABE0
// Name: _dynamic_initializer_for____g_C_SmokeTrailClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_SmokeTrailClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_SmokeTrailClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_SmokeTrailClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436630
// Name: _dynamic_atexit_destructor_for__r_VehicleViewClamp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_VehicleViewClamp__()
{
  ConVar::~ConVar(this: &r_VehicleViewClamp);
}

//------------------------------------------------------------------------------
// Address: 0x10436640
// Name: _DataMapInit_C_PropVehicleDriveable__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_C_PropVehicleDriveable__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_39);
}

//------------------------------------------------------------------------------
// Address: 0x10436650
// Name: _dynamic_atexit_destructor_for__g_RecipientFilterPredictionSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_RecipientFilterPredictionSystem__()
{
  g_RecipientFilterPredictionSystem.__vftable = (IPredictionSystem_vtbl *)&IPredictionSystem::`vftable';
}
