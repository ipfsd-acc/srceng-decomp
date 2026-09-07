// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_func_tracktrain.cpp
// Functions: 6
// ============================================================

#include "game\client\c_func_tracktrain.h"

//------------------------------------------------------------------------------
// Address: 0x10073250
// Name: public: virtual class ClientClass __near * C_FuncTrackTrain::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_FuncTrackTrain::GetClientClass(C_FuncTrackTrain *this)
{
  return &__g_C_FuncTrackTrainClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10073340
// Name: public: virtual bool C_FuncTrackTrain::GetSoundSpatialization(struct SpatializationInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_FuncTrackTrain::GetSoundSpatialization(C_FuncTrackTrain *this, SpatializationInfo_t *info)
{
  float *pflRadius; // eax
  int m_nLongAxis; // ecx
  const Vector *v7; // eax
  Vector *pOrigin; // edx
  float m_flLineLength; // xmm6_4
  float v10; // xmm4_4
  Vector *v11; // eax
  float z; // xmm0_4
  QAngle *pAngles; // edi
  const QAngle *v14; // eax
  Vector vecWorldDir; // [esp+4h] [ebp-34h] BYREF
  Vector vecDir; // [esp+10h] [ebp-28h] BYREF
  Vector vecEnd; // [esp+1Ch] [ebp-1Ch] BYREF
  Vector vecStart; // [esp+28h] [ebp-10h] BYREF
  float t; // [esp+34h] [ebp-4h] BYREF
  int savedregs; // [esp+38h] [ebp+0h] BYREF
  float infoa; // [esp+40h] [ebp+8h]

  if ( this->IsDormant(this: &this->IClientNetworkable) )
    return 0;
  pflRadius = info->pflRadius;
  if ( pflRadius != nullptr )
    *pflRadius = this->m_flRadius;
  if ( info->pOrigin != nullptr )
  {
    m_nLongAxis = this->m_nLongAxis;
    vecDir = vec3_origin;
    *((_DWORD *)&vecDir.x + m_nLongAxis) = 1065353216;
    C_BaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    VectorRotate(in1: &vecDir.x, in2: &this->m_rgflCoordinateFrame, out: &vecWorldDir.x);
    infoa = this->m_flLineLength * -0.5;
    v7 = this->WorldSpaceCenter(this);
    pOrigin = info->pOrigin;
    vecStart.x = (float)(vecWorldDir.x * infoa) + v7->x;
    m_flLineLength = this->m_flLineLength;
    vecStart.y = (float)(vecWorldDir.y * infoa) + v7->y;
    v10 = (float)(vecWorldDir.z * m_flLineLength) + (float)((float)(vecWorldDir.z * infoa) + v7->z);
    vecStart.z = (float)(vecWorldDir.z * infoa) + v7->z;
    vecEnd.x = (float)(vecWorldDir.x * m_flLineLength) + vecStart.x;
    vecEnd.y = (float)(vecWorldDir.y * m_flLineLength) + vecStart.y;
    vecEnd.z = v10;
    CalcClosestPointOnLine(
      P: &info->info.vListenerOrigin,
      vLineA: &vecStart,
      vLineB: &vecEnd,
      vClosest: pOrigin,
      outT: &t);
    if ( t < 0.0 )
    {
      v11 = info->pOrigin;
      v11->x = vecStart.x;
      v11->y = vecStart.y;
      z = vecStart.z;
LABEL_10:
      v11->z = z;
      goto LABEL_11;
    }
    if ( t > 1.0 )
    {
      v11 = info->pOrigin;
      v11->x = vecEnd.x;
      v11->y = vecEnd.y;
      z = vecEnd.z;
      goto LABEL_10;
    }
  }
LABEL_11:
  pAngles = info->pAngles;
  if ( pAngles != nullptr )
  {
    v14 = this->m_Collision.GetCollisionAngles(this: &this->m_Collision);
    pAngles->x = v14->x;
    pAngles->y = v14->y;
    pAngles->z = v14->z;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10073500
// Name: public: virtual void C_FuncTrackTrain::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_FuncTrackTrain::OnDataChanged(C_FuncTrackTrain *this, DataUpdateType_t updateType)
{
  Vector *v3; // eax
  float x; // xmm1_4
  float y; // xmm2_4
  float v6; // xmm0_4
  int v7; // ecx
  int v8; // edx
  float v9; // xmm1_4
  int v10; // ecx

  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED )
  {
    v3 = AllocTempVector();
    v3->x = this->m_Collision.m_vecMins.m_Value.y - *(float *)&this->m_Collision.C_BaseEntity::__vftable;
    x = v3->x;
    v3->y = this->m_Collision.m_vecMins.m_Value.z - *(float *)&this->m_Collision.m_pOuter;
    y = v3->y;
    v6 = this->m_Collision.m_vecMaxs.m_Value.x - this->m_Collision.m_vecMins.m_Value.x;
    v3->z = v6;
    if ( x <= y || x <= v6 )
    {
      v7 = 0;
      if ( y <= v6 )
      {
        *(_DWORD *)&this->m_bIsBlurred = 2;
        v8 = 1;
      }
      else
      {
        *(_DWORD *)&this->m_bIsBlurred = 1;
        v8 = 2;
      }
    }
    else
    {
      *(_DWORD *)&this->m_bIsBlurred = 0;
      v7 = 1;
      v8 = 2;
    }
    v9 = *(&v3->x + v7);
    v10 = *(_DWORD *)&this->m_bIsBlurred;
    *((float *)&this->m_bIsBlurred + 1) = fsqrt((float)(v9 * v9) + (float)(*(&v3->x + v8) * *(&v3->x + v8))) * 0.5;
    this->m_nLongAxis = *((int *)&v3->x + v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10412440
// Name: DT_FuncTrackTrain::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncTrackTrain::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_FuncTrackTrain::g_RecvTable);
  return atexit(func: DT_FuncTrackTrain::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412460
// Name: DT_FuncTrackTrain::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncTrackTrain::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_FuncTrackTrain::ignored>();
  DT_FuncTrackTrain::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104303B0
// Name: DT_FuncTrackTrain::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncTrackTrain::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_FuncTrackTrain::g_RecvTable);
}
