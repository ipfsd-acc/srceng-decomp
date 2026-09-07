// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/vehicle_viewblend_shared.cpp
// Functions: 95
// ============================================================

#include "game\shared\vehicle_viewblend_shared.h"

//------------------------------------------------------------------------------
// Address: 0x1017EC50
// Name: float RemapAngleRange(float,float,float,enum RemapAngleRange_CurvePart_t __near *)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl RemapAngleRange(
        float startInterval,
        float endInterval,
        float value,
        RemapAngleRange_CurvePart_t *peCurvePart)
{
  long double result; // st7
  float v5; // xmm0_4
  float v6; // xmm1_4
  float valuea; // [esp+14h] [ebp+10h]

  result = AngleNormalize(angle: value);
  valuea = result;
  LODWORD(v5) = LODWORD(valuea) & _mask__AbsFloat_;
  if ( startInterval <= COERCE_FLOAT(LODWORD(valuea) & _mask__AbsFloat_) )
  {
    if ( endInterval < v5 )
    {
      if ( peCurvePart != nullptr )
        *peCurvePart = RemapAngleRange_CurvePart_Linear;
    }
    else
    {
      v6 = (float)((float)((float)((float)((float)(v5 - startInterval) / (float)(endInterval - startInterval))
                                 * (float)((float)(v5 - startInterval) / (float)(endInterval - startInterval)))
                         * 3.0)
                 - (float)((float)((float)((float)((float)(v5 - startInterval) / (float)(endInterval - startInterval))
                                         * (float)((float)(v5 - startInterval) / (float)(endInterval - startInterval)))
                                 * 2.0)
                         * (float)((float)(v5 - startInterval) / (float)(endInterval - startInterval))))
         * endInterval;
      if ( valuea < 0.0 )
        v6 = v6 * -1.0;
      if ( peCurvePart != nullptr )
        *peCurvePart = RemapAngleRange_CurvePart_Spline;
      return v6;
    }
  }
  else
  {
    if ( peCurvePart != nullptr )
      *peCurvePart = RemapAngleRange_CurvePart_Zero;
    return 0.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017ED20
// Name: float ApplyViewLocking(float,float,struct ViewLockData_t __near &,enum RemapAngleRange_CurvePart_t)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ApplyViewLocking(
        float flAngleRaw,
        float flAngleClamped,
        ViewLockData_t *lockData,
        RemapAngleRange_CurvePart_t eCurvePart)
{
  float flLockInterval; // xmm1_4
  float flUnlockBlendInterval; // xmm1_4
  float flUnlockTime; // xmm1_4
  double v9; // st7
  float flAngleOut; // [esp+28h] [ebp+10h]

  flLockInterval = lockData->flLockInterval;
  if ( lockData->flLockInterval == 0.0 )
    return flAngleClamped;
  if ( eCurvePart != RemapAngleRange_CurvePart_Linear )
  {
    if ( !lockData->bLocked )
      goto LABEL_10;
    if ( eCurvePart != RemapAngleRange_CurvePart_Spline )
    {
      if ( *(float *)(gpGlobals.m_Index + 12) > lockData->flUnlockTime )
      {
        flUnlockBlendInterval = lockData->flUnlockBlendInterval;
        lockData->bLocked = false;
        if ( flUnlockBlendInterval <= 0.0 )
          lockData->flUnlockTime = 0.0;
        else
          lockData->flUnlockTime = *(float *)(gpGlobals.m_Index + 12);
      }
LABEL_10:
      if ( lockData->bLocked )
        return flAngleRaw;
      flUnlockTime = lockData->flUnlockTime;
      if ( flUnlockTime == 0.0 )
        return flAngleClamped;
      v9 = RemapValClamped(
             val: *(float *)(gpGlobals.m_Index + 12) - flUnlockTime,
             A: 0.0,
             B: lockData->flUnlockBlendInterval,
             C: 0.0,
             D: 1.0);
      flAngleOut = flAngleRaw + (flAngleClamped - flAngleRaw) * v9;
      if ( v9 >= 1.0 )
      {
        lockData->flUnlockTime = 0.0;
        return flAngleOut;
      }
      return flAngleOut;
    }
  }
  lockData->bLocked = true;
  lockData->flUnlockTime = *(float *)(gpGlobals.m_Index + 12) + flLockInterval;
  return flAngleRaw;
}

//------------------------------------------------------------------------------
// Address: 0x1017EE50
// Name: void RemapViewAngles(struct ViewSmoothingData_t __near *,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemapViewAngles(ViewSmoothingData_t *pData, float vehicleEyeAngles)
{
  QAngle *v2; // esi
  ViewSmoothingData_t *v3; // edi
  float x; // xmm0_4
  float v5; // xmm0_4
  long double v6; // st7
  float vecEyeAnglesRemapped; // [esp+18h] [ebp-10h]
  float vecEyeAnglesRemapped_8; // [esp+20h] [ebp-8h]
  float vecEyeAnglesRemapped_8a; // [esp+20h] [ebp-8h]
  RemapAngleRange_CurvePart_t eRollCurvePart; // [esp+24h] [ebp-4h] BYREF

  v2 = (QAngle *)LODWORD(vehicleEyeAngles);
  v3 = pData;
  vecEyeAnglesRemapped = RemapAngleRange(
                           startInterval: pData->flPitchCurveZero,
                           endInterval: pData->flPitchCurveLinear,
                           value: *(float *)LODWORD(vehicleEyeAngles),
                           peCurvePart: (RemapAngleRange_CurvePart_t *)&pData);
  vecEyeAnglesRemapped_8 = AngleNormalize(angle: v2->z);
  x = v2->x;
  v2->z = vecEyeAnglesRemapped_8;
  vehicleEyeAngles = 1.0;
  if ( fabs(x) > 60.0 )
  {
    v5 = (float)(fabs(vecEyeAnglesRemapped) - 60.0) * 0.050000001;
    if ( v5 >= 0.0 )
    {
      if ( v5 > 1.0 )
        v5 = 1.0;
    }
    else
    {
      v5 = 0.0;
    }
    vehicleEyeAngles = 1.0 - v5;
  }
  v6 = RemapAngleRange(
         startInterval: v3->flRollCurveZero,
         endInterval: v3->flRollCurveLinear,
         value: vecEyeAnglesRemapped_8,
         peCurvePart: &eRollCurvePart);
  vecEyeAnglesRemapped_8a = vecEyeAnglesRemapped_8 + (v6 - vecEyeAnglesRemapped_8) * vehicleEyeAngles;
  v2->x = ApplyViewLocking(
            flAngleRaw: v2->x,
            flAngleClamped: vecEyeAnglesRemapped,
            lockData: &v3->pitchLockData,
            eCurvePart: (RemapAngleRange_CurvePart_t)pData);
  v2->z = ApplyViewLocking(
            flAngleRaw: v2->z,
            flAngleClamped: vecEyeAnglesRemapped_8a,
            lockData: &v3->rollLockData,
            eCurvePart: eRollCurvePart);
}

//------------------------------------------------------------------------------
// Address: 0x1017EFA0
// Name: void SharedVehicleViewSmoothing(class C_BasePlayer __near *,class Vector __near *,class QAngle __near *,bool,bool,class Vector const __near &,struct ViewSmoothingData_t __near *,float __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SharedVehicleViewSmoothing(
        C_BasePlayer *pPlayer,
        Vector *pAbsOrigin,
        QAngle *pAbsAngles,
        bool bEnterAnimOn,
        bool bExitAnimOn,
        const Vector *vecEyeExitEndpoint,
        ViewSmoothingData_t *pData,
        float *pFOV,
        bool bForceViewToAttachment)
{
  int v10; // eax
  IClientRenderable_vtbl *v11; // edx
  IClientRenderable *v12; // ecx
  C_BaseAnimating *pVehicle; // ecx
  int SplitScreenPlayerSlot; // eax
  int v15; // eax
  float v16; // xmm0_4
  float flEnterExitDuration; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  int m_fValue_low; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  double x; // st7
  float z; // edx
  float v25; // xmm1_4
  float v26; // xmm2_4
  float flFOV; // xmm1_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm0_4
  float srcAngle; // [esp+20h] [ebp-138h]
  matrix3x4_t vehicleCameraToEyePos; // [esp+30h] [ebp-128h] BYREF
  matrix3x4_t cameraToWorld; // [esp+60h] [ebp-F8h] BYREF
  matrix3x4_t worldToEyePos; // [esp+90h] [ebp-C8h] BYREF
  matrix3x4_t newCameraToWorld; // [esp+C0h] [ebp-98h] BYREF
  matrix3x4_t vehicleEyePosToWorld; // [esp+F0h] [ebp-68h] BYREF
  Vector vehicleEyeOrigin; // [esp+120h] [ebp-38h] BYREF
  QAngle vecAngleDiffCur; // [esp+12Ch] [ebp-2Ch] BYREF
  QAngle vecAngleDiffBlend; // [esp+138h] [ebp-20h] BYREF
  float frac; // [esp+144h] [ebp-14h]
  int eyeAttachmentIndex; // [esp+148h] [ebp-10h]
  Vector vecAbsOrigin; // [esp+14Ch] [ebp-Ch] BYREF
  float flFracFOV; // [esp+178h] [ebp+20h]
  float flSplineFrac; // [esp+180h] [ebp+28h]
  bool flSplineFrac_3; // [esp+183h] [ebp+2Bh]

  *(float *)&v10 = COERCE_FLOAT(
                     pData->pVehicle->LookupAttachment(
                       this: &pData->pVehicle->IClientRenderable,
                       a2: "vehicle_driver_eyes"));
  v11 = pData->pVehicle->__vftable;
  v12 = &pData->pVehicle->IClientRenderable;
  eyeAttachmentIndex = v10;
  v11->GetAttachment_2(this: v12, a2: v10, a3: &vehicleEyeOrigin, a4: (QAngle *)&vecAbsOrigin);
  AngleMatrix(angles: (const QAngle *)&vecAbsOrigin, matrix: &vehicleEyePosToWorld);
  if ( bForceViewToAttachment )
  {
    *pAbsOrigin = vehicleEyeOrigin;
    *pAbsAngles = (QAngle)vecAbsOrigin;
    if ( pFOV != nullptr )
      *pFOV = pData->flFOV;
  }
  else
  {
    *pAbsAngles = *pPlayer->EyeAngles(this: pPlayer);
    if ( r_VehicleViewDampen.m_pParent != nullptr
      && r_VehicleViewDampen.m_pParent->m_Value.m_nValue != 0
      && pData->bDampenEyePosition )
    {
      ((void (__thiscall *)(C_BaseAnimating *, Vector *, Vector *))pData->pVehicle->__vftable[1].dtr_IHandleEntity)(
        a1: pData->pVehicle,
        a2: &vehicleEyeOrigin,
        a3: &vecAbsOrigin);
    }
    if ( bEnterAnimOn || bExitAnimOn )
    {
      flSplineFrac_3 = true;
      if ( !pData->bWasRunningAnim )
      {
        pData->bRunningEnterExit = true;
        pVehicle = pData->pVehicle;
        pData->flEnterExitStartTime = *(float *)(gpGlobals.m_Index + 12);
        pData->flEnterExitDuration = C_BaseAnimating::SequenceDuration(this: pVehicle, iSequence: pVehicle->m_nSequence);
        SplitScreenPlayerSlot = C_BasePlayer::GetSplitScreenPlayerSlot(this: pPlayer);
        pData->vecOriginSaved = *PrevMainViewOrigin(nSlot: SplitScreenPlayerSlot);
        v15 = C_BasePlayer::GetSplitScreenPlayerSlot(this: pPlayer);
        pData->vecAnglesSaved = *PrevMainViewAngles(nSlot: v15);
        pData->vecAngleDiffSaved.x = AngleDiff(destAngle: vecAbsOrigin.x, srcAngle: pData->vecAnglesSaved.x);
        pData->vecAngleDiffSaved.y = AngleDiff(destAngle: vecAbsOrigin.y, srcAngle: pData->vecAnglesSaved.y);
        pData->vecAngleDiffSaved.z = AngleDiff(destAngle: vecAbsOrigin.z, srcAngle: pData->vecAnglesSaved.z);
        pData->vecAngleDiffMin = pData->vecAngleDiffSaved;
      }
    }
    else
    {
      flSplineFrac_3 = false;
    }
    pData->bWasRunningAnim = flSplineFrac_3;
    frac = 0.0;
    flFracFOV = 0.0;
    if ( flSplineFrac_3 || pData->bRunningEnterExit )
    {
      *pAbsAngles = (QAngle)vecAbsOrigin;
      v16 = *(float *)(gpGlobals.m_Index + 12) - pData->flEnterExitStartTime;
      flEnterExitDuration = pData->flEnterExitDuration;
      v18 = v16 / flEnterExitDuration;
      if ( (float)(v16 / flEnterExitDuration) >= 0.0 )
      {
        if ( v18 > 1.0 )
          v18 = 1.0;
      }
      else
      {
        v18 = 0.0;
      }
      v19 = v16 / (float)(flEnterExitDuration * 0.85000002);
      frac = v18;
      if ( v19 >= 0.0 )
      {
        if ( v19 > 1.0 )
          v19 = 1.0;
      }
      else
      {
        v19 = 0.0;
      }
      flFracFOV = v19;
      if ( v18 >= 1.0 )
      {
        pData->bRunningEnterExit = false;
        if ( !bExitAnimOn )
        {
          C_BaseAnimating::GetAttachmentLocal(
            this: pData->pVehicle,
            iAttachment: eyeAttachmentIndex,
            origin: (Vector *)&vecAngleDiffCur,
            angles: &vecAngleDiffBlend);
          engine->SetViewAngles(this: engine, a2: &vecAngleDiffBlend);
        }
      }
    }
    AngleMatrix(angles: pAbsAngles, matrix: &cameraToWorld);
    MatrixInvert(in: &vehicleEyePosToWorld, out: &worldToEyePos);
    ConcatTransforms(in1: &worldToEyePos, in2: &cameraToWorld, out: &vehicleCameraToEyePos);
    if ( pData->bClampEyeAngles )
      RemapViewAngles(pData, vehicleEyeAngles: (QAngle *)&vecAbsOrigin);
    AngleMatrix(angles: (const QAngle *)&vecAbsOrigin, position: &vehicleEyeOrigin, matrix: &vehicleEyePosToWorld);
    ConcatTransforms(in1: &vehicleEyePosToWorld, in2: &vehicleCameraToEyePos, out: &newCameraToWorld);
    MatrixAngles(a1: (int)pData, src: (const VMatrix *)&newCameraToWorld, vAngles: pAbsAngles);
    MatrixGetColumn(in: &newCameraToWorld, column: 3, out: pAbsOrigin);
    m_fValue_low = SLODWORD(default_fov.m_pParent->m_Value.m_fValue);
    eyeAttachmentIndex = m_fValue_low;
    if ( flSplineFrac_3 || pData->bRunningEnterExit )
    {
      v22 = (float)((float)(frac * frac) * 3.0) - (float)((float)((float)(frac * frac) * 2.0) * frac);
      if ( v22 >= 0.0 )
      {
        if ( v22 > 1.0 )
          v22 = 1.0;
      }
      else
      {
        v22 = 0.0;
      }
      flSplineFrac = v22;
      vecAngleDiffBlend.x = pData->vecAngleDiffSaved.x * (float)(1.0 - v22);
      vecAngleDiffBlend.y = pData->vecAngleDiffSaved.y * (float)(1.0 - v22);
      srcAngle = pData->vecAnglesSaved.x;
      vecAngleDiffBlend.z = pData->vecAngleDiffSaved.z * (float)(1.0 - v22);
      vecAngleDiffCur.x = AngleDiff(destAngle: vecAbsOrigin.x, srcAngle);
      vecAngleDiffCur.y = AngleDiff(destAngle: vecAbsOrigin.y, srcAngle: pData->vecAnglesSaved.y);
      vecAngleDiffCur.z = AngleDiff(destAngle: vecAbsOrigin.z, srcAngle: pData->vecAnglesSaved.z);
      if ( fabs(pData->vecAngleDiffMin.x) > fabs(vecAngleDiffCur.x) )
        pData->vecAngleDiffMin.x = vecAngleDiffCur.x;
      if ( fabs(pData->vecAngleDiffMin.x) > fabs(vecAngleDiffBlend.x) )
        pData->vecAngleDiffMin.x = vecAngleDiffBlend.x;
      if ( fabs(pData->vecAngleDiffMin.y) > fabs(vecAngleDiffCur.y) )
        pData->vecAngleDiffMin.y = vecAngleDiffCur.y;
      if ( fabs(pData->vecAngleDiffMin.y) > fabs(vecAngleDiffBlend.y) )
        pData->vecAngleDiffMin.y = vecAngleDiffBlend.y;
      if ( fabs(pData->vecAngleDiffMin.z) > fabs(vecAngleDiffCur.z) )
        pData->vecAngleDiffMin.z = vecAngleDiffCur.z;
      if ( fabs(pData->vecAngleDiffMin.z) > fabs(vecAngleDiffBlend.z) )
        pData->vecAngleDiffMin.z = vecAngleDiffBlend.z;
      pAbsAngles->x = pAbsAngles->x - pData->vecAngleDiffMin.x;
      x = pAbsAngles->x;
      pAbsAngles->y = pAbsAngles->y - pData->vecAngleDiffMin.y;
      pAbsAngles->z = pAbsAngles->z - pData->vecAngleDiffMin.z;
      pData->vecAnglesSaved.x = x;
      pData->vecAnglesSaved.y = pAbsAngles->y;
      pData->vecAnglesSaved.z = pAbsAngles->z;
      z = pAbsOrigin->z;
      *(_QWORD *)&vecAbsOrigin.x = *(_QWORD *)&pAbsOrigin->x;
      vecAbsOrigin.z = z;
      if ( bExitAnimOn )
      {
        v25 = (float)((float)(vecEyeExitEndpoint->y - vecAbsOrigin.y) * v22) + vecAbsOrigin.y;
        v26 = (float)((float)(vecEyeExitEndpoint->z - vecAbsOrigin.z) * flSplineFrac) + vecAbsOrigin.z;
        pAbsOrigin->x = (float)((float)(vecEyeExitEndpoint->x - vecAbsOrigin.x) * flSplineFrac) + vecAbsOrigin.x;
        pAbsOrigin->y = v25;
        pAbsOrigin->z = v26;
        if ( pFOV != nullptr )
        {
          flFOV = pData->flFOV;
          if ( flFOV > *(float *)&eyeAttachmentIndex )
            *pFOV = (float)((float)(*(float *)&eyeAttachmentIndex - flFOV) * flFracFOV) + flFOV;
        }
      }
      else
      {
        v28 = pData->vecOriginSaved.y + (float)((float)(vecAbsOrigin.y - pData->vecOriginSaved.y) * v22);
        v29 = pData->vecOriginSaved.z + (float)((float)(vecAbsOrigin.z - pData->vecOriginSaved.z) * v22);
        pAbsOrigin->x = pData->vecOriginSaved.x + (float)((float)(vecAbsOrigin.x - pData->vecOriginSaved.x) * v22);
        pAbsOrigin->y = v28;
        pAbsOrigin->z = v29;
        if ( pFOV != nullptr )
        {
          v30 = pData->flFOV;
          if ( v30 > *(float *)&eyeAttachmentIndex )
            *pFOV = (float)((float)(v30 - *(float *)&eyeAttachmentIndex) * flFracFOV) + *(float *)&eyeAttachmentIndex;
        }
      }
    }
    else if ( pFOV != nullptr )
    {
      v21 = pData->flFOV;
      if ( v21 > *(float *)&m_fValue_low )
        *pFOV = v21;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041D210
// Name: ViewSmoothingData_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *ViewSmoothingData_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<ViewSmoothingData_t>();
  ViewSmoothingData_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041D220
// Name: _dynamic_initializer_for__g_CAvatarImagePanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CAvatarImagePanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CAvatarImagePanel_Helper,
           className: "CAvatarImagePanel",
           func: (vgui::Panel *(__cdecl *)())Create_CAvatarImagePanel);
}

//------------------------------------------------------------------------------
// Address: 0x1041D240
// Name: _dynamic_initializer_for__scr_centertime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__scr_centertime__()
{
  ConVar::ConVar(this: &scr_centertime, pName: "scr_centertime", pDefaultValue: "2", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__scr_centertime__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D270
// Name: _dynamic_initializer_for__g_CenterString__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_CenterString__()
{
  g_CenterString[0].__vftable = (CCenterPrint_vtbl *)&CCenterPrint::`vftable';
  dword_10652234 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1041D290
// Name: _dynamic_initializer_for__g_ButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Button *dynamic_initializer_for__g_ButtonPullInModule__()
{
  g_ButtonPullInModule = g_ButtonLinkerHack;
  return g_ButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D2A0
// Name: _dynamic_initializer_for__g_EditablePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::EditablePanel *dynamic_initializer_for__g_EditablePanelPullInModule__()
{
  g_EditablePanelPullInModule = g_EditablePanelLinkerHack;
  return g_EditablePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D2B0
// Name: _dynamic_initializer_for__g_ImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ImagePanel *dynamic_initializer_for__g_ImagePanelPullInModule__()
{
  g_ImagePanelPullInModule = g_ImagePanelLinkerHack;
  return g_ImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D2C0
// Name: _dynamic_initializer_for__g_LabelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Label *dynamic_initializer_for__g_LabelPullInModule__()
{
  g_LabelPullInModule = g_LabelLinkerHack;
  return g_LabelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D2D0
// Name: _dynamic_initializer_for__g_PanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Panel *dynamic_initializer_for__g_PanelPullInModule__()
{
  g_PanelPullInModule = g_PanelLinkerHack;
  return g_PanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D2E0
// Name: _dynamic_initializer_for__g_ToggleButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ToggleButton *dynamic_initializer_for__g_ToggleButtonPullInModule__()
{
  g_ToggleButtonPullInModule = g_ToggleButtonLinkerHack;
  return g_ToggleButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D2F0
// Name: _dynamic_initializer_for__g_AnimatingImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *dynamic_initializer_for__g_AnimatingImagePanelPullInModule__()
{
  g_AnimatingImagePanelPullInModule = g_AnimatingImagePanelLinkerHack;
  return g_AnimatingImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D300
// Name: _dynamic_initializer_for__g_CBitmapImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *dynamic_initializer_for__g_CBitmapImagePanelPullInModule__()
{
  g_CBitmapImagePanelPullInModule = g_CBitmapImagePanelLinkerHack;
  return g_CBitmapImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D310
// Name: _dynamic_initializer_for__g_CheckButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CheckButton *dynamic_initializer_for__g_CheckButtonPullInModule__()
{
  g_CheckButtonPullInModule = g_CheckButtonLinkerHack;
  return g_CheckButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D320
// Name: _dynamic_initializer_for__g_ComboBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ComboBox *dynamic_initializer_for__g_ComboBoxPullInModule__()
{
  g_ComboBoxPullInModule = g_ComboBoxLinkerHack;
  return g_ComboBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D330
// Name: _dynamic_initializer_for__g_CvarToggleCheckButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *dynamic_initializer_for__g_CvarToggleCheckButtonPullInModule__()
{
  g_CvarToggleCheckButtonPullInModule = g_CvarToggleCheckButtonLinkerHack;
  return g_CvarToggleCheckButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D340
// Name: _dynamic_initializer_for__g_DividerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Divider *dynamic_initializer_for__g_DividerPullInModule__()
{
  g_DividerPullInModule = g_DividerLinkerHack;
  return g_DividerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D350
// Name: _dynamic_initializer_for__g_ExpandButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ExpandButton *dynamic_initializer_for__g_ExpandButtonPullInModule__()
{
  g_ExpandButtonPullInModule = g_ExpandButtonLinkerHack;
  return g_ExpandButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D360
// Name: _dynamic_initializer_for__g_GraphPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::GraphPanel *dynamic_initializer_for__g_GraphPanelPullInModule__()
{
  g_GraphPanelPullInModule = g_GraphPanelLinkerHack;
  return g_GraphPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D370
// Name: _dynamic_initializer_for__g_ListPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ListPanel *dynamic_initializer_for__g_ListPanelPullInModule__()
{
  g_ListPanelPullInModule = g_ListPanelLinkerHack;
  return g_ListPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D380
// Name: _dynamic_initializer_for__g_ListViewPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ListViewPanel *dynamic_initializer_for__g_ListViewPanelPullInModule__()
{
  g_ListViewPanelPullInModule = g_ListViewPanelLinkerHack;
  return g_ListViewPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D390
// Name: _dynamic_initializer_for__g_MenuPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Menu *dynamic_initializer_for__g_MenuPullInModule__()
{
  g_MenuPullInModule = g_MenuLinkerHack;
  return g_MenuLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D3A0
// Name: _dynamic_initializer_for__g_MenuBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuBar *dynamic_initializer_for__g_MenuBarPullInModule__()
{
  g_MenuBarPullInModule = g_MenuBarLinkerHack;
  return g_MenuBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D3B0
// Name: _dynamic_initializer_for__g_MenuButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuButton *dynamic_initializer_for__g_MenuButtonPullInModule__()
{
  g_MenuButtonPullInModule = g_MenuButtonLinkerHack;
  return g_MenuButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D3C0
// Name: _dynamic_initializer_for__g_MenuItemPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuItem *dynamic_initializer_for__g_MenuItemPullInModule__()
{
  g_MenuItemPullInModule = g_MenuItemLinkerHack;
  return g_MenuItemLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D3D0
// Name: _dynamic_initializer_for__g_MessageBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MessageBox *dynamic_initializer_for__g_MessageBoxPullInModule__()
{
  g_MessageBoxPullInModule = g_MessageBoxLinkerHack;
  return g_MessageBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D3E0
// Name: _dynamic_initializer_for__g_ProgressBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ProgressBar *dynamic_initializer_for__g_ProgressBarPullInModule__()
{
  g_ProgressBarPullInModule = g_ProgressBarLinkerHack;
  return g_ProgressBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D3F0
// Name: _dynamic_initializer_for__g_CircularProgressBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CircularProgressBar *dynamic_initializer_for__g_CircularProgressBarPullInModule__()
{
  g_CircularProgressBarPullInModule = g_CircularProgressBarLinkerHack;
  return g_CircularProgressBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D400
// Name: _dynamic_initializer_for__g_RadioButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::RadioButton *dynamic_initializer_for__g_RadioButtonPullInModule__()
{
  g_RadioButtonPullInModule = g_RadioButtonLinkerHack;
  return g_RadioButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D410
// Name: _dynamic_initializer_for__g_RichTextPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::RichText *dynamic_initializer_for__g_RichTextPullInModule__()
{
  g_RichTextPullInModule = g_RichTextLinkerHack;
  return g_RichTextLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D420
// Name: _dynamic_initializer_for__g_ScalableImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *dynamic_initializer_for__g_ScalableImagePanelPullInModule__()
{
  g_ScalableImagePanelPullInModule = g_ScalableImagePanelLinkerHack;
  return g_ScalableImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D430
// Name: _dynamic_initializer_for__g_ScrollBar_VerticalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBar_VerticalPullInModule__()
{
  g_ScrollBar_VerticalPullInModule = g_ScrollBar_VerticalLinkerHack;
  return g_ScrollBar_VerticalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D440
// Name: _dynamic_initializer_for__g_ScrollBar_HorizontalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBar_HorizontalPullInModule__()
{
  g_ScrollBar_HorizontalPullInModule = g_ScrollBar_HorizontalLinkerHack;
  return g_ScrollBar_HorizontalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D450
// Name: _dynamic_initializer_for__g_ScrollBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBarPullInModule__()
{
  g_ScrollBarPullInModule = g_ScrollBarLinkerHack;
  return g_ScrollBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D460
// Name: _dynamic_initializer_for__g_TextEntryPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::TextEntry *dynamic_initializer_for__g_TextEntryPullInModule__()
{
  g_TextEntryPullInModule = g_TextEntryLinkerHack;
  return g_TextEntryLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D470
// Name: _dynamic_initializer_for__g_TreeViewPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::TreeView *dynamic_initializer_for__g_TreeViewPullInModule__()
{
  g_TreeViewPullInModule = g_TreeViewLinkerHack;
  return g_TreeViewLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D480
// Name: _dynamic_initializer_for__g_CTreeViewListControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *dynamic_initializer_for__g_CTreeViewListControlPullInModule__()
{
  g_CTreeViewListControlPullInModule = g_CTreeViewListControlLinkerHack;
  return g_CTreeViewListControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D490
// Name: _dynamic_initializer_for__g_URLLabelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::URLLabel *dynamic_initializer_for__g_URLLabelPullInModule__()
{
  g_URLLabelPullInModule = g_URLLabelLinkerHack;
  return g_URLLabelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1041D4A0
// Name: _dynamic_initializer_for__cl_showfps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_showfps__()
{
  ConVar::ConVar(
    this: &cl_showfps,
    pName: "cl_showfps",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "Draw fps meter (1 = fps, 2 = smooth, 3 = server, 4 = Show+LogToFile, +10 = detailed )");
  return atexit(func: dynamic_atexit_destructor_for__cl_showfps__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D4D0
// Name: _dynamic_initializer_for__cl_showpos__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_showpos__()
{
  ConVar::ConVar(
    this: &cl_showpos,
    pName: "cl_showpos",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "Draw current position at top of screen");
  return atexit(func: dynamic_atexit_destructor_for__cl_showpos__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D500
// Name: _dynamic_initializer_for__cl_showbattery__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_showbattery__()
{
  ConVar::ConVar(
    this: &cl_showbattery,
    pName: "cl_showbattery",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Draw current battery level at top of screen when on battery power");
  return atexit(func: dynamic_atexit_destructor_for__cl_showbattery__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D530
// Name: _dynamic_initializer_for__g_ViewportClientSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ViewportClientSystem__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ViewportClientSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D540
// Name: _dynamic_initializer_for__ss_pipsplit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_pipsplit__()
{
  ConVar::ConVar(
    this: &ss_pipsplit,
    pName: "ss_pipsplit",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "If enabled, use PIP instead of splitscreen. (Only works for 2 players)",
    callback: (void (__cdecl *)(IConVar *, const char *, float))ss_pipsplit_changed);
  return atexit(func: dynamic_atexit_destructor_for__ss_pipsplit__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D570
// Name: _dynamic_initializer_for__ss_pipscale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_pipscale__()
{
  ConVar::ConVar(
    this: &ss_pipscale,
    pName: "ss_pipscale",
    pDefaultValue: "0.3f",
    flags: 0,
    pHelpString: "Scale of the PIP aspect ratio to our resolution.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))ss_pipsplit_changed);
  return atexit(func: dynamic_atexit_destructor_for__ss_pipscale__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D5A0
// Name: _dynamic_initializer_for__ss_pip_right_offset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_pip_right_offset__()
{
  ConVar::ConVar(
    this: &ss_pip_right_offset,
    pName: "ss_pip_right_offset",
    pDefaultValue: "25",
    flags: 0,
    pHelpString: "PIP offset vector from the right of the screen",
    callback: (void (__cdecl *)(IConVar *, const char *, float))ss_pipsplit_changed);
  return atexit(func: dynamic_atexit_destructor_for__ss_pip_right_offset__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D5D0
// Name: _dynamic_initializer_for__ss_pip_bottom_offset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_pip_bottom_offset__()
{
  ConVar::ConVar(
    this: &ss_pip_bottom_offset,
    pName: "ss_pip_bottom_offset",
    pDefaultValue: "25",
    flags: 0,
    pHelpString: "PIP offset vector from the bottom of the screen",
    callback: (void (__cdecl *)(IConVar *, const char *, float))ss_pipsplit_changed);
  return atexit(func: dynamic_atexit_destructor_for__ss_pip_bottom_offset__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D600
// Name: _dynamic_initializer_for__ss_force_primary_fullscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_force_primary_fullscreen__()
{
  ConVar::ConVar(
    this: &ss_force_primary_fullscreen,
    pName: "ss_force_primary_fullscreen",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "If enabled, all splitscreen users will only see the first user's screen full screen",
    callback: (void (__cdecl *)(IConVar *, const char *, float))ss_pipsplit_changed);
  return atexit(func: dynamic_atexit_destructor_for__ss_force_primary_fullscreen__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D630
// Name: _dynamic_initializer_for__ss_verticalsplit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_verticalsplit__()
{
  ConVar::ConVar(
    this: &ss_verticalsplit_0,
    pName: "ss_verticalsplit",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Two player split screen uses vertical split (do not set this directly, use ss_splitmode instead).",
    callback: ss_verticalsplit_changed);
  return atexit(func: dynamic_atexit_destructor_for__ss_verticalsplit__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D660
// Name: _dynamic_initializer_for__ss_splitmode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_splitmode__()
{
  ConVar::ConVar(
    this: &ss_splitmode,
    pName: "ss_splitmode",
    pDefaultValue: "0",
    flags: 16777344,
    pHelpString: "Two player split screen mode (0 - recommended settings base on the width, 1 - horizontal, 2 - vertical (only allowed in widescreen)",
    callback: (void (__cdecl *)(IConVar *, const char *, float))ss_splitmode_changed);
  return atexit(func: dynamic_atexit_destructor_for__ss_splitmode__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D690
// Name: _dynamic_initializer_for__ss_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_enable__()
{
  ConVar::ConVar(
    this: &ss_enable,
    pName: "ss_enable",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "Enables Split Screen support. Play Single Player now launches into split screen mode. NO ONLINE SUPPORT");
  return atexit(func: dynamic_atexit_destructor_for__ss_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D6C0
// Name: _dynamic_initializer_for__ss_reloadletterbox_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_reloadletterbox_command__()
{
  ConCommand::ConCommand(
    this: &ss_reloadletterbox_command,
    pName: "ss_reloadletterbox",
    callback: ss_reloadletterbox,
    pHelpString: "ss_reloadletterbox",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ss_reloadletterbox_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D6F0
// Name: _dynamic_initializer_for__cl_showpausedimage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_showpausedimage__()
{
  ConVar::ConVar(
    this: &cl_showpausedimage,
    pName: "cl_showpausedimage",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Show the 'Paused' image when game is paused.");
  return atexit(func: dynamic_atexit_destructor_for__cl_showpausedimage__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D720
// Name: _dynamic_initializer_for__cl_panelanimation_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_panelanimation_command__()
{
  ConCommand::ConCommand(
    this: &cl_panelanimation_command,
    pName: "cl_panelanimation",
    callback: (void (__cdecl *)())cl_panelanimation,
    pHelpString: "Shows panel animation variables: <panelname | blank for all panels>.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_panelanimation_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D750
// Name: _dynamic_initializer_for__cl_enable_remote_splitscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_enable_remote_splitscreen__()
{
  ConVar::ConVar(
    this: &cl_enable_remote_splitscreen,
    pName: "cl_enable_remote_splitscreen",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Allows viewing of nonlocal players in a split screen fashion",
    callback: (void (__cdecl *)(IConVar *, const char *, float))ss_pipsplit_changed);
  return atexit(func: dynamic_atexit_destructor_for__cl_enable_remote_splitscreen__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D780
// Name: _dynamic_initializer_for__s_IterateNetworkedSplitScreenSlotsPushedValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_IterateNetworkedSplitScreenSlotsPushedValues__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_IterateNetworkedSplitScreenSlotsPushedValues__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D790
// Name: _dynamic_initializer_for__g_CMovieDisplayScreenFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CMovieDisplayScreenFactory__()
{
  CPanelMetaClassMgrImp *v0; // eax

  v0 = PanelMetaClassMgr();
  return ((int (__thiscall *)(CPanelMetaClassMgrImp *, const char *, CPanelFactory<CMovieDisplayScreen,VGuiScreenInitData_t> *))v0->InstallPanelType)(
           a1: v0,
           a2: "movie_display_screen",
           a3: &g_CMovieDisplayScreenFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1041D7B0
// Name: _dynamic_initializer_for__g_MovieDisplays__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MovieDisplays__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_MovieDisplays__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D7C0
// Name: _dynamic_initializer_for__net_scale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_scale__()
{
  ConVar::ConVar(this: &net_scale, pName: "net_scale", pDefaultValue: "5", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__net_scale__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D7F0
// Name: _dynamic_initializer_for__net_graphpos__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_graphpos__()
{
  ConVar::ConVar(this: &net_graphpos, pName: "net_graphpos", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__net_graphpos__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D820
// Name: _dynamic_initializer_for__net_graphsolid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_graphsolid__()
{
  ConVar::ConVar(this: &net_graphsolid, pName: "net_graphsolid", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__net_graphsolid__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D850
// Name: _dynamic_initializer_for__net_graphtext__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_graphtext__()
{
  ConVar::ConVar(
    this: &net_graphtext,
    pName: "net_graphtext",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Draw text fields");
  return atexit(func: dynamic_atexit_destructor_for__net_graphtext__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D880
// Name: _dynamic_initializer_for__net_graphmsecs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_graphmsecs__()
{
  ConVar::ConVar(
    this: &net_graphmsecs,
    pName: "net_graphmsecs",
    pDefaultValue: "400",
    flags: 128,
    pHelpString: "The latency graph represents this many milliseconds.");
  return atexit(func: dynamic_atexit_destructor_for__net_graphmsecs__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D8B0
// Name: _dynamic_initializer_for__net_graphshowlatency__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_graphshowlatency__()
{
  ConVar::ConVar(
    this: &net_graphshowlatency,
    pName: "net_graphshowlatency",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Draw the ping/packet loss graph.");
  return atexit(func: dynamic_atexit_destructor_for__net_graphshowlatency__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D8E0
// Name: _dynamic_initializer_for__net_graphshowinterp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_graphshowinterp__()
{
  ConVar::ConVar(
    this: &net_graphshowinterp,
    pName: "net_graphshowinterp",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Draw the interpolation graph.");
  return atexit(func: dynamic_atexit_destructor_for__net_graphshowinterp__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D910
// Name: _dynamic_initializer_for__net_graph__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_graph__()
{
  ConVar::ConVar(
    this: &net_graph,
    pName: "net_graph",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "Draw the network usage graph, = 2 draws data on payload, = 3 draws payload legend.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))NetgraphFontChangeCallback);
  return atexit(func: dynamic_atexit_destructor_for__net_graph__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D940
// Name: _dynamic_initializer_for__net_graphheight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_graphheight__()
{
  ConVar::ConVar(
    this: &net_graphheight,
    pName: "net_graphheight",
    pDefaultValue: "64",
    flags: 128,
    pHelpString: "Height of netgraph panel",
    callback: (void (__cdecl *)(IConVar *, const char *, float))NetgraphFontChangeCallback);
  return atexit(func: dynamic_atexit_destructor_for__net_graphheight__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D970
// Name: _dynamic_initializer_for__net_graphproportionalfont__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_graphproportionalfont__()
{
  ConVar::ConVar(
    this: &net_graphproportionalfont,
    pName: "net_graphproportionalfont",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Determines whether netgraph font is proportional or not",
    callback: (void (__cdecl *)(IConVar *, const char *, float))NetgraphFontChangeCallback);
  return atexit(func: dynamic_atexit_destructor_for__net_graphproportionalfont__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D9A0
// Name: _dynamic_initializer_for__g_CSlideshowDisplayScreenFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CSlideshowDisplayScreenFactory__()
{
  CPanelMetaClassMgrImp *v0; // eax

  v0 = PanelMetaClassMgr();
  return ((int (__thiscall *)(CPanelMetaClassMgrImp *, const char *, CPanelFactory<CSlideshowDisplayScreen,VGuiScreenInitData_t> *))v0->InstallPanelType)(
           a1: v0,
           a2: "slideshow_display_screen",
           a3: &g_CSlideshowDisplayScreenFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1041D9C0
// Name: _dynamic_initializer_for__bink_preload_videopanel_movies__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bink_preload_videopanel_movies__()
{
  ConVar::ConVar(
    this: &bink_preload_videopanel_movies,
    pName: "bink_preload_videopanel_movies",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Preload Bink movies used by VideoPanel.");
  return atexit(func: dynamic_atexit_destructor_for__bink_preload_videopanel_movies__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D9F0
// Name: _dynamic_initializer_for__g_vecVideoPanels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_vecVideoPanels__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_vecVideoPanels__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DA00
// Name: _dynamic_initializer_for__playvideo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__playvideo_command__()
{
  ConCommand::ConCommand(
    this: &playvideo_command,
    pName: "playvideo",
    callback: (void (__cdecl *)())playvideo,
    pHelpString: "Plays a video: <filename> [width height]",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__playvideo_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DA30
// Name: _dynamic_initializer_for__playvideo_nointerrupt_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__playvideo_nointerrupt_command__()
{
  ConCommand::ConCommand(
    this: &playvideo_nointerrupt_command,
    pName: "playvideo_nointerrupt",
    callback: (void (__cdecl *)())playvideo_nointerrupt,
    pHelpString: "Plays a video without ability to skip: <filename> [width height]",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__playvideo_nointerrupt_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DA60
// Name: _dynamic_initializer_for__playvideo_end_level_transition_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__playvideo_end_level_transition_command__()
{
  ConCommand::ConCommand(
    this: &playvideo_end_level_transition_command,
    pName: "playvideo_end_level_transition",
    callback: (void (__cdecl *)())playvideo_end_level_transition,
    pHelpString: "Plays a video fullscreen without ability to skip (unless dev 1) and fades in: <filename> <time>",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__playvideo_end_level_transition_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DA90
// Name: _dynamic_initializer_for__playvideo_exitcommand_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__playvideo_exitcommand_command__()
{
  ConCommand::ConCommand(
    this: &playvideo_exitcommand_command,
    pName: "playvideo_exitcommand",
    callback: (void (__cdecl *)())playvideo_exitcommand,
    pHelpString: "Plays a video and fires and exit command when it is stopped or finishes: <filename> <exit command>",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__playvideo_exitcommand_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DAC0
// Name: _dynamic_initializer_for__playvideo_exitcommand_nointerrupt_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__playvideo_exitcommand_nointerrupt_command__()
{
  ConCommand::ConCommand(
    this: &playvideo_exitcommand_nointerrupt_command,
    pName: "playvideo_exitcommand_nointerrupt",
    callback: (void (__cdecl *)())playvideo_exitcommand_nointerrupt,
    pHelpString: "Plays a video (without interruption) and fires and exit command when it is stopped or finishes: <filename> <exit command>",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__playvideo_exitcommand_nointerrupt_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DAF0
// Name: _dynamic_initializer_for__stopvideos_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__stopvideos_command__()
{
  ConCommand::ConCommand(
    this: &stopvideos_command,
    pName: "stopvideos",
    callback: stopvideos,
    pHelpString: "Stops all videos playing to the screen",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__stopvideos_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DB20
// Name: _dynamic_initializer_for__stopvideos_fadeout_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__stopvideos_fadeout_command__()
{
  ConCommand::ConCommand(
    this: &stopvideos_fadeout_command,
    pName: "stopvideos_fadeout",
    callback: (void (__cdecl *)())stopvideos_fadeout,
    pHelpString: "Fades out all videos playing to the screen: <time>",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__stopvideos_fadeout_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DB50
// Name: _dynamic_initializer_for__stop_transition_videos_fadeout_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__stop_transition_videos_fadeout_command__()
{
  ConCommand::ConCommand(
    this: &stop_transition_videos_fadeout_command,
    pName: "stop_transition_videos_fadeout",
    callback: (void (__cdecl *)())stop_transition_videos_fadeout,
    pHelpString: "Fades out all transition videos playing to the screen: <time>",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__stop_transition_videos_fadeout_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DB80
// Name: _dynamic_initializer_for__zoom_sensitivity_ratio__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__zoom_sensitivity_ratio__()
{
  ConVar::ConVar(
    this: &zoom_sensitivity_ratio,
    pName: "zoom_sensitivity_ratio",
    pDefaultValue: "0.5",
    flags: 0,
    pHelpString: "Additional mouse sensitivity scale factor applied when FOV is zoomed in.");
  return atexit(func: dynamic_atexit_destructor_for__zoom_sensitivity_ratio__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DBB0
// Name: _dynamic_initializer_for__v_centermove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__v_centermove__()
{
  ConVar::ConVar(this: &v_centermove, pName: "v_centermove", pDefaultValue: "0.15", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__v_centermove__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DBE0
// Name: _dynamic_initializer_for__v_centerspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__v_centerspeed__()
{
  ConVar::ConVar(this: &v_centerspeed, pName: "v_centerspeed", pDefaultValue: "500", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__v_centerspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DC10
// Name: _dynamic_initializer_for__v_viewmodel_fov__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__v_viewmodel_fov__()
{
  ConVar::ConVar(this: &v_viewmodel_fov, pName: "viewmodel_fov", pDefaultValue: "54", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__v_viewmodel_fov__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DC40
// Name: _dynamic_initializer_for__mat_viewportscale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_viewportscale__()
{
  ConVar::ConVar(
    this: &mat_viewportscale,
    pName: "mat_viewportscale",
    pDefaultValue: "1.0",
    flags: 0x4000,
    pHelpString: "Scale down the main viewport (to reduce GPU impact on CPU profiling)",
    bMin: true,
    fMin: 0.0015625,
    bMax: true,
    fMax: 1.0);
  return atexit(func: dynamic_atexit_destructor_for__mat_viewportscale__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DC90
// Name: _dynamic_initializer_for__cl_leveloverview__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_leveloverview__()
{
  ConVar::ConVar(this: &cl_leveloverview, pName: "cl_leveloverview", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_leveloverview__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DCC0
// Name: _dynamic_initializer_for__r_mapextents__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_mapextents__()
{
  ConVar::ConVar(
    this: &r_mapextents,
    pName: "r_mapextents",
    pDefaultValue: "16384",
    flags: 0x4000,
    pHelpString: "Set the max dimension for the map.  This determines the far clipping plane");
  return atexit(func: dynamic_atexit_destructor_for__r_mapextents__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DCF0
// Name: _dynamic_initializer_for__cl_camera_follow_bone_index__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_camera_follow_bone_index__()
{
  ConVar::ConVar(
    this: &cl_camera_follow_bone_index,
    pName: "cl_camera_follow_bone_index",
    pDefaultValue: "-2",
    flags: 0x4000,
    pHelpString: "Index of the bone to follow.  -2 == disabled.  -1 == root bone.  0+ is bone index.");
  return atexit(func: dynamic_atexit_destructor_for__cl_camera_follow_bone_index__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DD20
// Name: _dynamic_initializer_for__gl_clear__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__gl_clear__()
{
  ConVar::ConVar(this: &gl_clear, pName: "gl_clear", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__gl_clear__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DD50
// Name: _dynamic_initializer_for__gl_clear_randomcolor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__gl_clear_randomcolor__()
{
  ConVar::ConVar(
    this: &gl_clear_randomcolor,
    pName: "gl_clear_randomcolor",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Clear the back buffer to random colors every frame. Helps spot open seams in geometry.");
  return atexit(func: dynamic_atexit_destructor_for__gl_clear_randomcolor__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DD80
// Name: _dynamic_initializer_for__r_farz__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_farz__()
{
  ConVar::ConVar(
    this: &r_farz,
    pName: "r_farz",
    pDefaultValue: "-1",
    flags: 0x4000,
    pHelpString: "Override the far clipping plane. -1 means to use the value in env_fog_controller.");
  return atexit(func: dynamic_atexit_destructor_for__r_farz__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DDB0
// Name: _dynamic_initializer_for__cl_demoviewoverride__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_demoviewoverride__()
{
  ConVar::ConVar(
    this: &cl_demoviewoverride,
    pName: "cl_demoviewoverride",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Override view during demo playback");
  return atexit(func: dynamic_atexit_destructor_for__cl_demoviewoverride__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DDE0
// Name: _dynamic_initializer_for__centerview__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__centerview__()
{
  ConCommand::ConCommand(
    this: &centerview,
    pName: "centerview",
    callback: (void (__cdecl *)())StartPitchDrift,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__centerview__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DE10
// Name: _dynamic_initializer_for__ss_debug_draw_player__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_debug_draw_player__()
{
  ConVar::ConVar(this: &ss_debug_draw_player, pName: "ss_debug_draw_player", pDefaultValue: "-1", flags: 16386);
  return atexit(func: dynamic_atexit_destructor_for__ss_debug_draw_player__);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1025B730
// Name: float RemapAngleRange(float,float,float,enum RemapAngleRange_CurvePart_t __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl RemapAngleRange(
        float startInterval,
        float endInterval,
        float value,
        RemapAngleRange_CurvePart_t *peCurvePart)
{
  double result; // st7
  float v5; // xmm0_4
  float v6; // xmm1_4
  float valuea; // [esp+14h] [ebp+10h]

  result = AngleNormalize(angle: value);
  valuea = result;
  LODWORD(v5) = LODWORD(valuea) & _mask__AbsFloat_;
  if ( startInterval <= COERCE_FLOAT(LODWORD(valuea) & _mask__AbsFloat_) )
  {
    if ( endInterval < v5 )
    {
      if ( peCurvePart != nullptr )
        *peCurvePart = RemapAngleRange_CurvePart_Linear;
    }
    else
    {
      v6 = (float)((float)((float)((float)((float)(v5 - startInterval) / (float)(endInterval - startInterval))
                                 * (float)((float)(v5 - startInterval) / (float)(endInterval - startInterval)))
                         * 3.0)
                 - (float)((float)((float)((float)((float)(v5 - startInterval) / (float)(endInterval - startInterval))
                                         * (float)((float)(v5 - startInterval) / (float)(endInterval - startInterval)))
                                 * 2.0)
                         * (float)((float)(v5 - startInterval) / (float)(endInterval - startInterval))))
         * endInterval;
      if ( valuea < 0.0 )
        v6 = v6 * -1.0;
      if ( peCurvePart != nullptr )
        *peCurvePart = RemapAngleRange_CurvePart_Spline;
      return v6;
    }
  }
  else
  {
    if ( peCurvePart != nullptr )
      *peCurvePart = RemapAngleRange_CurvePart_Zero;
    return 0.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1025B800
// Name: float ApplyViewLocking(float,float,struct ViewLockData_t __near &,enum RemapAngleRange_CurvePart_t)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ApplyViewLocking(
        float flAngleRaw,
        float flAngleClamped,
        ViewLockData_t *lockData,
        RemapAngleRange_CurvePart_t eCurvePart)
{
  float flLockInterval; // xmm1_4
  float flUnlockBlendInterval; // xmm1_4
  float flUnlockTime; // xmm1_4
  double v9; // st7
  float flAngleOut; // [esp+28h] [ebp+10h]

  flLockInterval = lockData->flLockInterval;
  if ( lockData->flLockInterval == 0.0 )
    return flAngleClamped;
  if ( eCurvePart != RemapAngleRange_CurvePart_Linear )
  {
    if ( !lockData->bLocked )
      goto LABEL_10;
    if ( eCurvePart != RemapAngleRange_CurvePart_Spline )
    {
      if ( gpGlobals->curtime > lockData->flUnlockTime )
      {
        flUnlockBlendInterval = lockData->flUnlockBlendInterval;
        lockData->bLocked = false;
        if ( flUnlockBlendInterval <= 0.0 )
          lockData->flUnlockTime = 0.0;
        else
          lockData->flUnlockTime = gpGlobals->curtime;
      }
LABEL_10:
      if ( lockData->bLocked )
        return flAngleRaw;
      flUnlockTime = lockData->flUnlockTime;
      if ( flUnlockTime == 0.0 )
        return flAngleClamped;
      v9 = RemapValClamped(
             val: gpGlobals->curtime - flUnlockTime,
             A: 0.0,
             B: lockData->flUnlockBlendInterval,
             C: 0.0,
             D: 1.0);
      flAngleOut = flAngleRaw + (flAngleClamped - flAngleRaw) * v9;
      if ( v9 >= 1.0 )
      {
        lockData->flUnlockTime = 0.0;
        return flAngleOut;
      }
      return flAngleOut;
    }
  }
  lockData->bLocked = true;
  lockData->flUnlockTime = gpGlobals->curtime + flLockInterval;
  return flAngleRaw;
}

//------------------------------------------------------------------------------
// Address: 0x1025B930
// Name: void RemapViewAngles(struct ViewSmoothingData_t __near *,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemapViewAngles(ViewSmoothingData_t *pData, float vehicleEyeAngles)
{
  QAngle *v2; // esi
  ViewSmoothingData_t *v3; // edi
  float x; // xmm0_4
  float v5; // xmm0_4
  double v6; // st7
  float vecEyeAnglesRemapped; // [esp+18h] [ebp-10h]
  float vecEyeAnglesRemapped_8; // [esp+20h] [ebp-8h]
  float vecEyeAnglesRemapped_8a; // [esp+20h] [ebp-8h]
  RemapAngleRange_CurvePart_t eRollCurvePart; // [esp+24h] [ebp-4h] BYREF

  v2 = (QAngle *)LODWORD(vehicleEyeAngles);
  v3 = pData;
  vecEyeAnglesRemapped = RemapAngleRange(
                           startInterval: pData->flPitchCurveZero,
                           endInterval: pData->flPitchCurveLinear,
                           value: *(float *)LODWORD(vehicleEyeAngles),
                           peCurvePart: (RemapAngleRange_CurvePart_t *)&pData);
  vecEyeAnglesRemapped_8 = AngleNormalize(angle: v2->z);
  x = v2->x;
  v2->z = vecEyeAnglesRemapped_8;
  vehicleEyeAngles = 1.0;
  if ( fabs(x) > 60.0 )
  {
    v5 = (float)(fabs(vecEyeAnglesRemapped) - 60.0) * 0.050000001;
    if ( v5 >= 0.0 )
    {
      if ( v5 > 1.0 )
        v5 = 1.0;
    }
    else
    {
      v5 = 0.0;
    }
    vehicleEyeAngles = 1.0 - v5;
  }
  v6 = RemapAngleRange(
         startInterval: v3->flRollCurveZero,
         endInterval: v3->flRollCurveLinear,
         value: vecEyeAnglesRemapped_8,
         peCurvePart: &eRollCurvePart);
  vecEyeAnglesRemapped_8a = vecEyeAnglesRemapped_8 + (v6 - vecEyeAnglesRemapped_8) * vehicleEyeAngles;
  v2->x = ApplyViewLocking(
            flAngleRaw: v2->x,
            flAngleClamped: vecEyeAnglesRemapped,
            lockData: &v3->pitchLockData,
            eCurvePart: (RemapAngleRange_CurvePart_t)pData);
  v2->z = ApplyViewLocking(
            flAngleRaw: v2->z,
            flAngleClamped: vecEyeAnglesRemapped_8a,
            lockData: &v3->rollLockData,
            eCurvePart: eRollCurvePart);
}

//------------------------------------------------------------------------------
// Address: 0x1025BA80
// Name: void SharedVehicleViewSmoothing(class CBasePlayer __near *,class Vector __near *,class QAngle __near *,bool,bool,class Vector const __near &,struct ViewSmoothingData_t __near *,float __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SharedVehicleViewSmoothing(
        CBasePlayer *pPlayer,
        Vector *pAbsOrigin,
        QAngle *pAbsAngles,
        bool bEnterAnimOn,
        bool bExitAnimOn,
        const Vector *vecEyeExitEndpoint,
        ViewSmoothingData_t *pData,
        float *pFOV,
        bool bForceViewToAttachment)
{
  int v9; // ebx
  CBaseAnimating *pVehicle; // ecx
  float v11; // xmm0_4
  float flEnterExitDuration; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float DefaultFOV; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  double x; // st7
  float z; // ecx
  float v20; // xmm1_4
  float v21; // xmm2_4
  float flFOV; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm0_4
  float srcAngle; // [esp+Ch] [ebp-13Ch]
  matrix3x4_t vehicleCameraToEyePos; // [esp+1Ch] [ebp-12Ch] BYREF
  matrix3x4_t worldToEyePos; // [esp+4Ch] [ebp-FCh] BYREF
  matrix3x4_t cameraToWorld; // [esp+7Ch] [ebp-CCh] BYREF
  matrix3x4_t newCameraToWorld; // [esp+ACh] [ebp-9Ch] BYREF
  matrix3x4_t vehicleEyePosToWorld; // [esp+DCh] [ebp-6Ch] BYREF
  Vector vehicleEyeOrigin; // [esp+10Ch] [ebp-3Ch] BYREF
  QAngle vecAngleDiffBlend; // [esp+118h] [ebp-30h] BYREF
  QAngle vecAngleDiffCur; // [esp+124h] [ebp-24h] BYREF
  float frac; // [esp+130h] [ebp-18h]
  float flDefaultFOV; // [esp+134h] [ebp-14h]
  float flFracFOV; // [esp+138h] [ebp-10h]
  Vector vecAbsOrigin; // [esp+13Ch] [ebp-Ch] BYREF
  float flSplineFrac; // [esp+170h] [ebp+28h]
  bool flSplineFrac_3; // [esp+173h] [ebp+2Bh]

  v9 = CBaseAnimating::LookupAttachment(this: pData->pVehicle, szName: "vehicle_driver_eyes");
  CBaseAnimating::GetAttachment(
    this: pData->pVehicle,
    iAttachment: v9,
    absOrigin: &vehicleEyeOrigin,
    absAngles: (QAngle *)&vecAbsOrigin);
  AngleMatrix(angles: (const QAngle *)&vecAbsOrigin, matrix: &vehicleEyePosToWorld);
  if ( bForceViewToAttachment )
  {
    *pAbsOrigin = vehicleEyeOrigin;
    *pAbsAngles = (QAngle)vecAbsOrigin;
    if ( pFOV != nullptr )
      *pFOV = pData->flFOV;
  }
  else
  {
    *pAbsAngles = *pPlayer->EyeAngles(this: pPlayer);
    if ( r_VehicleViewDampen.m_pParent != nullptr
      && r_VehicleViewDampen.m_pParent->m_Value.m_nValue != 0
      && pData->bDampenEyePosition )
    {
      ((void (__thiscall *)(CBaseAnimating *, Vector *, Vector *))pData->pVehicle->__vftable[1].SetRefEHandle)(
        a1: pData->pVehicle,
        a2: &vehicleEyeOrigin,
        a3: &vecAbsOrigin);
    }
    if ( bEnterAnimOn || bExitAnimOn )
    {
      flSplineFrac_3 = true;
      if ( !pData->bWasRunningAnim )
      {
        pVehicle = pData->pVehicle;
        pData->bRunningEnterExit = true;
        pData->flEnterExitStartTime = gpGlobals->curtime;
        pData->flEnterExitDuration = CBaseAnimating::SequenceDuration(
                                       this: pVehicle,
                                       iSequence: pVehicle->m_nSequence.m_Value);
        pData->vecAngleDiffSaved.x = AngleDiff(destAngle: vecAbsOrigin.x, srcAngle: pData->vecAnglesSaved.x);
        pData->vecAngleDiffSaved.y = AngleDiff(destAngle: vecAbsOrigin.y, srcAngle: pData->vecAnglesSaved.y);
        pData->vecAngleDiffSaved.z = AngleDiff(destAngle: vecAbsOrigin.z, srcAngle: pData->vecAnglesSaved.z);
        pData->vecAngleDiffMin = pData->vecAngleDiffSaved;
      }
    }
    else
    {
      flSplineFrac_3 = false;
    }
    pData->bWasRunningAnim = flSplineFrac_3;
    frac = 0.0;
    flFracFOV = 0.0;
    if ( flSplineFrac_3 || pData->bRunningEnterExit )
    {
      *pAbsAngles = (QAngle)vecAbsOrigin;
      v11 = gpGlobals->curtime - pData->flEnterExitStartTime;
      flEnterExitDuration = pData->flEnterExitDuration;
      v13 = v11 / flEnterExitDuration;
      if ( (float)(v11 / flEnterExitDuration) >= 0.0 )
      {
        if ( v13 > 1.0 )
          v13 = 1.0;
      }
      else
      {
        v13 = 0.0;
      }
      v14 = v11 / (float)(flEnterExitDuration * 0.85000002);
      frac = v13;
      if ( v14 >= 0.0 )
      {
        if ( v14 > 1.0 )
          v14 = 1.0;
      }
      else
      {
        v14 = 0.0;
      }
      flFracFOV = v14;
      if ( v13 >= 1.0 )
      {
        pData->bRunningEnterExit = false;
        if ( !bExitAnimOn )
          CBaseAnimating::GetAttachmentLocal(
            this: pData->pVehicle,
            iAttachment: v9,
            origin: (Vector *)&vecAngleDiffCur,
            angles: &vecAngleDiffBlend);
      }
    }
    AngleMatrix(angles: pAbsAngles, matrix: &cameraToWorld);
    MatrixInvert(in: &vehicleEyePosToWorld, out: &worldToEyePos);
    ConcatTransforms(in1: &worldToEyePos, in2: &cameraToWorld, out: &vehicleCameraToEyePos);
    if ( pData->bClampEyeAngles )
      RemapViewAngles(pData, vehicleEyeAngles: COERCE_FLOAT(&vecAbsOrigin));
    AngleMatrix(angles: (const QAngle *)&vecAbsOrigin, position: &vehicleEyeOrigin, matrix: &vehicleEyePosToWorld);
    ConcatTransforms(in1: &vehicleEyePosToWorld, in2: &vehicleCameraToEyePos, out: &newCameraToWorld);
    MatrixAngles(a1: (int)pData, src: (const VMatrix *)&newCameraToWorld, vAngles: pAbsAngles);
    MatrixGetColumn(in: &newCameraToWorld, column: 3, out: pAbsOrigin);
    DefaultFOV = (float)CBasePlayer::GetDefaultFOV(this: pPlayer);
    flDefaultFOV = DefaultFOV;
    if ( flSplineFrac_3 || pData->bRunningEnterExit )
    {
      v17 = (float)((float)(frac * frac) * 3.0) - (float)((float)((float)(frac * frac) * 2.0) * frac);
      if ( v17 >= 0.0 )
      {
        if ( v17 > 1.0 )
          v17 = 1.0;
      }
      else
      {
        v17 = 0.0;
      }
      flSplineFrac = v17;
      vecAngleDiffBlend.x = pData->vecAngleDiffSaved.x * (float)(1.0 - v17);
      vecAngleDiffBlend.y = pData->vecAngleDiffSaved.y * (float)(1.0 - v17);
      srcAngle = pData->vecAnglesSaved.x;
      vecAngleDiffBlend.z = pData->vecAngleDiffSaved.z * (float)(1.0 - v17);
      vecAngleDiffCur.x = AngleDiff(destAngle: vecAbsOrigin.x, srcAngle);
      vecAngleDiffCur.y = AngleDiff(destAngle: vecAbsOrigin.y, srcAngle: pData->vecAnglesSaved.y);
      vecAngleDiffCur.z = AngleDiff(destAngle: vecAbsOrigin.z, srcAngle: pData->vecAnglesSaved.z);
      if ( fabs(pData->vecAngleDiffMin.x) > fabs(vecAngleDiffCur.x) )
        pData->vecAngleDiffMin.x = vecAngleDiffCur.x;
      if ( fabs(pData->vecAngleDiffMin.x) > fabs(vecAngleDiffBlend.x) )
        pData->vecAngleDiffMin.x = vecAngleDiffBlend.x;
      if ( fabs(pData->vecAngleDiffMin.y) > fabs(vecAngleDiffCur.y) )
        pData->vecAngleDiffMin.y = vecAngleDiffCur.y;
      if ( fabs(pData->vecAngleDiffMin.y) > fabs(vecAngleDiffBlend.y) )
        pData->vecAngleDiffMin.y = vecAngleDiffBlend.y;
      if ( fabs(pData->vecAngleDiffMin.z) > fabs(vecAngleDiffCur.z) )
        pData->vecAngleDiffMin.z = vecAngleDiffCur.z;
      if ( fabs(pData->vecAngleDiffMin.z) > fabs(vecAngleDiffBlend.z) )
        pData->vecAngleDiffMin.z = vecAngleDiffBlend.z;
      pAbsAngles->x = pAbsAngles->x - pData->vecAngleDiffMin.x;
      x = pAbsAngles->x;
      pAbsAngles->y = pAbsAngles->y - pData->vecAngleDiffMin.y;
      pAbsAngles->z = pAbsAngles->z - pData->vecAngleDiffMin.z;
      pData->vecAnglesSaved.x = x;
      pData->vecAnglesSaved.y = pAbsAngles->y;
      pData->vecAnglesSaved.z = pAbsAngles->z;
      z = pAbsOrigin->z;
      *(_QWORD *)&vecAbsOrigin.x = *(_QWORD *)&pAbsOrigin->x;
      vecAbsOrigin.z = z;
      if ( bExitAnimOn )
      {
        v20 = (float)((float)(vecEyeExitEndpoint->y - vecAbsOrigin.y) * v17) + vecAbsOrigin.y;
        v21 = (float)((float)(vecEyeExitEndpoint->z - vecAbsOrigin.z) * flSplineFrac) + vecAbsOrigin.z;
        pAbsOrigin->x = (float)((float)(vecEyeExitEndpoint->x - vecAbsOrigin.x) * flSplineFrac) + vecAbsOrigin.x;
        pAbsOrigin->y = v20;
        pAbsOrigin->z = v21;
        if ( pFOV != nullptr )
        {
          flFOV = pData->flFOV;
          if ( flFOV > flDefaultFOV )
            *pFOV = (float)((float)(flDefaultFOV - flFOV) * flFracFOV) + flFOV;
        }
      }
      else
      {
        v23 = (float)((float)(vecAbsOrigin.y - pData->vecOriginSaved.y) * v17) + pData->vecOriginSaved.y;
        v24 = (float)((float)(vecAbsOrigin.z - pData->vecOriginSaved.z) * flSplineFrac) + pData->vecOriginSaved.z;
        pAbsOrigin->x = (float)((float)(vecAbsOrigin.x - pData->vecOriginSaved.x) * flSplineFrac)
                      + pData->vecOriginSaved.x;
        pAbsOrigin->y = v23;
        pAbsOrigin->z = v24;
        if ( pFOV != nullptr )
        {
          v25 = pData->flFOV;
          if ( v25 > flDefaultFOV )
            *pFOV = (float)((float)(v25 - flDefaultFOV) * flFracFOV) + flDefaultFOV;
        }
      }
    }
    else if ( pFOV != nullptr )
    {
      v16 = pData->flFOV;
      if ( v16 > DefaultFOV )
        *pFOV = v16;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040C710
// Name: ViewSmoothingData_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *ViewSmoothingData_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<ViewSmoothingData_t>();
  ViewSmoothingData_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040C720
// Name: _dynamic_initializer_for__g_ButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Button *dynamic_initializer_for__g_ButtonPullInModule__()
{
  g_ButtonPullInModule = g_ButtonLinkerHack;
  return g_ButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C730
// Name: _dynamic_initializer_for__g_EditablePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::EditablePanel *dynamic_initializer_for__g_EditablePanelPullInModule__()
{
  g_EditablePanelPullInModule = g_EditablePanelLinkerHack;
  return g_EditablePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C740
// Name: _dynamic_initializer_for__g_ImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ImagePanel *dynamic_initializer_for__g_ImagePanelPullInModule__()
{
  g_ImagePanelPullInModule = g_ImagePanelLinkerHack;
  return g_ImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C750
// Name: _dynamic_initializer_for__g_LabelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Label *dynamic_initializer_for__g_LabelPullInModule__()
{
  g_LabelPullInModule = g_LabelLinkerHack;
  return g_LabelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C760
// Name: _dynamic_initializer_for__g_PanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Panel *dynamic_initializer_for__g_PanelPullInModule__()
{
  g_PanelPullInModule = g_PanelLinkerHack;
  return g_PanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C770
// Name: _dynamic_initializer_for__g_ToggleButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ToggleButton *dynamic_initializer_for__g_ToggleButtonPullInModule__()
{
  g_ToggleButtonPullInModule = g_ToggleButtonLinkerHack;
  return g_ToggleButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C780
// Name: _dynamic_initializer_for__g_AnimatingImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *dynamic_initializer_for__g_AnimatingImagePanelPullInModule__()
{
  g_AnimatingImagePanelPullInModule = g_AnimatingImagePanelLinkerHack;
  return g_AnimatingImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C790
// Name: _dynamic_initializer_for__g_CBitmapImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *dynamic_initializer_for__g_CBitmapImagePanelPullInModule__()
{
  g_CBitmapImagePanelPullInModule = g_CBitmapImagePanelLinkerHack;
  return g_CBitmapImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C7A0
// Name: _dynamic_initializer_for__g_CheckButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CheckButton *dynamic_initializer_for__g_CheckButtonPullInModule__()
{
  g_CheckButtonPullInModule = g_CheckButtonLinkerHack;
  return g_CheckButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C7B0
// Name: _dynamic_initializer_for__g_ComboBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ComboBox *dynamic_initializer_for__g_ComboBoxPullInModule__()
{
  g_ComboBoxPullInModule = g_ComboBoxLinkerHack;
  return g_ComboBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C7C0
// Name: _dynamic_initializer_for__g_CvarToggleCheckButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *dynamic_initializer_for__g_CvarToggleCheckButtonPullInModule__()
{
  g_CvarToggleCheckButtonPullInModule = g_CvarToggleCheckButtonLinkerHack;
  return g_CvarToggleCheckButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C7D0
// Name: _dynamic_initializer_for__g_DividerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Divider *dynamic_initializer_for__g_DividerPullInModule__()
{
  g_DividerPullInModule = g_DividerLinkerHack;
  return g_DividerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C7E0
// Name: _dynamic_initializer_for__g_ExpandButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ExpandButton *dynamic_initializer_for__g_ExpandButtonPullInModule__()
{
  g_ExpandButtonPullInModule = g_ExpandButtonLinkerHack;
  return g_ExpandButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C7F0
// Name: _dynamic_initializer_for__g_GraphPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::GraphPanel *dynamic_initializer_for__g_GraphPanelPullInModule__()
{
  g_GraphPanelPullInModule = g_GraphPanelLinkerHack;
  return g_GraphPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C800
// Name: _dynamic_initializer_for__g_ListPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ListPanel *dynamic_initializer_for__g_ListPanelPullInModule__()
{
  g_ListPanelPullInModule = g_ListPanelLinkerHack;
  return g_ListPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C810
// Name: _dynamic_initializer_for__g_ListViewPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ListViewPanel *dynamic_initializer_for__g_ListViewPanelPullInModule__()
{
  g_ListViewPanelPullInModule = g_ListViewPanelLinkerHack;
  return g_ListViewPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C820
// Name: _dynamic_initializer_for__g_MenuPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Menu *dynamic_initializer_for__g_MenuPullInModule__()
{
  g_MenuPullInModule = g_MenuLinkerHack;
  return g_MenuLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C830
// Name: _dynamic_initializer_for__g_MenuBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuBar *dynamic_initializer_for__g_MenuBarPullInModule__()
{
  g_MenuBarPullInModule = g_MenuBarLinkerHack;
  return g_MenuBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C840
// Name: _dynamic_initializer_for__g_MenuButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuButton *dynamic_initializer_for__g_MenuButtonPullInModule__()
{
  g_MenuButtonPullInModule = g_MenuButtonLinkerHack;
  return g_MenuButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C850
// Name: _dynamic_initializer_for__g_MenuItemPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuItem *dynamic_initializer_for__g_MenuItemPullInModule__()
{
  g_MenuItemPullInModule = g_MenuItemLinkerHack;
  return g_MenuItemLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C860
// Name: _dynamic_initializer_for__g_MessageBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MessageBox *dynamic_initializer_for__g_MessageBoxPullInModule__()
{
  g_MessageBoxPullInModule = g_MessageBoxLinkerHack;
  return g_MessageBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C870
// Name: _dynamic_initializer_for__g_ProgressBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ProgressBar *dynamic_initializer_for__g_ProgressBarPullInModule__()
{
  g_ProgressBarPullInModule = g_ProgressBarLinkerHack;
  return g_ProgressBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C880
// Name: _dynamic_initializer_for__g_CircularProgressBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CircularProgressBar *dynamic_initializer_for__g_CircularProgressBarPullInModule__()
{
  g_CircularProgressBarPullInModule = g_CircularProgressBarLinkerHack;
  return g_CircularProgressBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C890
// Name: _dynamic_initializer_for__g_RadioButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::RadioButton *dynamic_initializer_for__g_RadioButtonPullInModule__()
{
  g_RadioButtonPullInModule = g_RadioButtonLinkerHack;
  return g_RadioButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C8A0
// Name: _dynamic_initializer_for__g_RichTextPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::RichText *dynamic_initializer_for__g_RichTextPullInModule__()
{
  g_RichTextPullInModule = g_RichTextLinkerHack;
  return g_RichTextLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C8B0
// Name: _dynamic_initializer_for__g_ScalableImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *dynamic_initializer_for__g_ScalableImagePanelPullInModule__()
{
  g_ScalableImagePanelPullInModule = g_ScalableImagePanelLinkerHack;
  return g_ScalableImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C8C0
// Name: _dynamic_initializer_for__g_ScrollBar_VerticalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBar_VerticalPullInModule__()
{
  g_ScrollBar_VerticalPullInModule = g_ScrollBar_VerticalLinkerHack;
  return g_ScrollBar_VerticalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C8D0
// Name: _dynamic_initializer_for__g_ScrollBar_HorizontalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBar_HorizontalPullInModule__()
{
  g_ScrollBar_HorizontalPullInModule = g_ScrollBar_HorizontalLinkerHack;
  return g_ScrollBar_HorizontalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C8E0
// Name: _dynamic_initializer_for__g_ScrollBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBarPullInModule__()
{
  g_ScrollBarPullInModule = g_ScrollBarLinkerHack;
  return g_ScrollBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C8F0
// Name: _dynamic_initializer_for__g_TextEntryPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::TextEntry *dynamic_initializer_for__g_TextEntryPullInModule__()
{
  g_TextEntryPullInModule = g_TextEntryLinkerHack;
  return g_TextEntryLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C900
// Name: _dynamic_initializer_for__g_TreeViewPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::TreeView *dynamic_initializer_for__g_TreeViewPullInModule__()
{
  g_TreeViewPullInModule = g_TreeViewLinkerHack;
  return g_TreeViewLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C910
// Name: _dynamic_initializer_for__g_CTreeViewListControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *dynamic_initializer_for__g_CTreeViewListControlPullInModule__()
{
  g_CTreeViewListControlPullInModule = g_CTreeViewListControlLinkerHack;
  return g_CTreeViewListControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C920
// Name: _dynamic_initializer_for__g_URLLabelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::URLLabel *dynamic_initializer_for__g_URLLabelPullInModule__()
{
  g_URLLabelPullInModule = g_URLLabelLinkerHack;
  return g_URLLabelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x1040C930
// Name: _dynamic_initializer_for__g_CVGuiScreen_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CVGuiScreen_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CVGuiScreen_ClassReg,
           pNetworkName: "CVGuiScreen",
           pTable: &DT_VGuiScreen::g_SendTable);
}

} // namespace server
