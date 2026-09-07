// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/clockdriftmgr.cpp
// Functions: 9
// ============================================================

#include "engine\clockdriftmgr.h"

//------------------------------------------------------------------------------
// Address: 0x1014A150
// Name: public: void CClockDriftMgr::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClockDriftMgr::Clear(CClockDriftMgr *this)
{
  this->m_nClientTick = 0;
  this->m_nServerTick = 0;
  this->m_iCurClockOffset = 0;
  memset(dst: (unsigned __int8 *)this, value: 0, count: 0x40u);
}

//------------------------------------------------------------------------------
// Address: 0x1014A170
// Name: public: float CClockDriftMgr::GetCurrentClockDifference(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CClockDriftMgr::GetCurrentClockDifference(CClockDriftMgr *this)
{
  float v1; // xmm0_4
  float *v2; // eax
  int i; // ecx

  v1 = 0.0;
  v2 = &this->m_ClockOffsets[2];
  for ( i = 2; i != 0; --i )
  {
    v1 = (float)((float)((float)((float)((float)((float)((float)(v1 + *(v2 - 2)) + *(v2 - 1)) + *v2) + v2[1]) + v2[2])
                       + v2[3])
               + v2[4])
       + v2[5];
    v2 += 8;
  }
  return v1 * 0.0625;
}

//------------------------------------------------------------------------------
// Address: 0x1014A1C0
// Name: private: void CClockDriftMgr::AdjustAverageDifferenceBy(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClockDriftMgr::AdjustAverageDifferenceBy(CClockDriftMgr *this, float flAmountInSeconds)
{
  float v2; // xmm0_4
  float *v3; // eax
  float *v4; // ecx
  int i; // edx
  float v6; // xmm1_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  int j; // ecx

  v2 = 0.0;
  v3 = &this->m_ClockOffsets[2];
  v4 = &this->m_ClockOffsets[2];
  for ( i = 2; i != 0; --i )
  {
    v6 = (float)((float)((float)((float)((float)((float)((float)(*(v4 - 2) + v2) + *(v4 - 1)) + *v4) + v4[1]) + v4[2])
                       + v4[3])
               + v4[4])
       + v4[5];
    v4 += 8;
    v2 = v6;
  }
  v7 = v6 * 0.0625;
  if ( v7 >= 0.050000001 )
  {
    v8 = (float)((float)(flAmountInSeconds / host_state.interval_per_tick) / v7) + 1.0;
    for ( j = 2; j != 0; --j )
    {
      *(v3 - 2) = *(v3 - 2) * v8;
      *(v3 - 1) = *(v3 - 1) * v8;
      *v3 = *v3 * v8;
      v3[1] = v3[1] * v8;
      v3[2] = v3[2] * v8;
      v3[3] = v8 * v3[3];
      v3[4] = v3[4] * v8;
      v3[5] = v3[5] * v8;
      v3 += 8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014A2C0
// Name: GetClockAdjustmentAmount
// Source: json
//------------------------------------------------------------------------------
float __usercall GetClockAdjustmentAmount@<xmm0>(float a1@<xmm3>)
{
  float m_fValue; // xmm1_4
  float v3; // xmm0_4
  float v4; // xmm3_4

  m_fValue = cl_clock_correction_adjustment_max_offset.m_pParent->m_Value.m_fValue;
  v3 = m_fValue;
  if ( cl_clock_correction_adjustment_min_offset.m_pParent->m_Value.m_fValue <= a1 )
  {
    if ( a1 <= m_fValue )
      v3 = a1;
  }
  else
  {
    v3 = cl_clock_correction_adjustment_min_offset.m_pParent->m_Value.m_fValue;
  }
  v4 = cl_clock_correction_adjustment_min_offset.m_pParent->m_Value.m_fValue;
  if ( v4 != m_fValue )
    return (float)((float)(v3 - v4)
                 * (float)(cl_clock_correction_adjustment_max_amount.m_pParent->m_Value.m_fValue * 0.001))
         / (float)(m_fValue - v4);
  if ( (float)(v3 - m_fValue) < 0.0 )
    return 0.0;
  return cl_clock_correction_adjustment_max_amount.m_pParent->m_Value.m_fValue * 0.001;
}

//------------------------------------------------------------------------------
// Address: 0x1014A330
// Name: public: CClockDriftMgr::CClockDriftMgr(void)
// Source: json
//------------------------------------------------------------------------------
CClockDriftMgr *__thiscall CClockDriftMgr::CClockDriftMgr(CClockDriftMgr *this)
{
  this->m_nClientTick = 0;
  this->m_nServerTick = 0;
  this->m_iCurClockOffset = 0;
  memset(dst: (unsigned __int8 *)this, value: 0, count: 0x40u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014A350
// Name: public: static bool CClockDriftMgr::IsClockCorrectionEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CClockDriftMgr::IsClockCorrectionEnabled()
{
  if ( sv.m_State >= ss_active && NET_GetFakeLag() <= 0.0 )
    return false;
  if ( cl_clock_correction.m_pParent != nullptr )
    return cl_clock_correction.m_pParent->m_Value.m_nValue != 0;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1014A390
// Name: public: void CClockDriftMgr::SetServerTick(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClockDriftMgr::SetServerTick(CClockDriftMgr *this, int nTick)
{
  double m_fValue; // st7
  int v5; // edi
  int m_nValue; // eax
  int v7; // eax
  int v8; // esi
  int m_nClientTick; // esi
  int v10; // esi
  int nMaxDriftTicks; // [esp+14h] [ebp+8h]

  this->m_nServerTick = nTick;
  if ( g_bThreadedEngine )
    m_fValue = cl_clockdrift_max_ms_threadmode.m_pParent->m_Value.m_fValue;
  else
    m_fValue = cl_clockdrift_max_ms.m_pParent->m_Value.m_fValue;
  nMaxDriftTicks = (int)(m_fValue * 0.001 / host_state.interval_per_tick + 0.5);
  v5 = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick + g_ClientGlobalVariables.simTicksThisFrame - 1;
  if ( cl_clock_correction_force_server_tick.m_pParent == nullptr )
  {
    m_nValue = 0;
    goto LABEL_18;
  }
  m_nValue = cl_clock_correction_force_server_tick.m_pParent->m_Value.m_nValue;
  if ( m_nValue != 999 )
  {
LABEL_18:
    GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick = m_nValue + nTick;
    goto LABEL_19;
  }
  if ( sv.m_State >= ss_active && NET_GetFakeLag() <= 0.0
    || (cl_clock_correction.m_pParent == nullptr ? (v7 = 0) : (v7 = cl_clock_correction.m_pParent->m_Value.m_nValue),
        v7 == 0 || v5 == 0 || (int)abs32(nTick - v5) > nMaxDriftTicks) )
  {
    v8 = nTick - g_ClientGlobalVariables.simTicksThisFrame + 1;
    GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick = v8;
    m_nClientTick = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick;
    if ( m_nClientTick < GetBaseLocalClient()->oldtickcount )
    {
      v10 = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick;
      GetBaseLocalClient()->oldtickcount = v10;
    }
    memset(dst: (unsigned __int8 *)this, value: 0, count: 0x40u);
  }
LABEL_19:
  this->m_ClockOffsets[this->m_iCurClockOffset] = (float)(v5 - this->m_nServerTick);
  this->m_iCurClockOffset = (this->m_iCurClockOffset + 1) % 16;
}

//------------------------------------------------------------------------------
// Address: 0x1014A4D0
// Name: private: void CClockDriftMgr::ShowDebugInfo(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClockDriftMgr::ShowDebugInfo(CClockDriftMgr *this, float flAdjustment)
{
  int m_nValue; // eax
  int v4; // edi
  int v5; // esi
  int v6; // edx
  int i; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float *v11; // eax
  int j; // ecx

  if ( cl_clock_showdebuginfo.m_pParent != nullptr && cl_clock_showdebuginfo.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( (sv.m_State < ss_active || NET_GetFakeLag() > 0.0)
      && (cl_clock_correction.m_pParent == nullptr
        ? (m_nValue = 0)
        : (m_nValue = cl_clock_correction.m_pParent->m_Value.m_nValue),
          m_nValue != 0) )
    {
      v4 = -999;
      v5 = 999;
      v6 = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick - this->m_nServerTick;
      for ( i = 0; i < 16; ++i )
      {
        v8 = this->m_ClockOffsets[i];
        v9 = (float)v4;
        if ( (float)v4 <= v8 )
          v9 = this->m_ClockOffsets[i];
        v4 = (int)v9;
        if ( v8 > (float)v5 )
          v8 = (float)v5;
        v5 = (int)v8;
      }
      v10 = 0.0;
      v11 = &this->m_ClockOffsets[2];
      for ( j = 2; j != 0; --j )
      {
        v10 = (float)((float)((float)((float)((float)((float)((float)(v10 + *(v11 - 2)) + *(v11 - 1)) + *v11) + v11[1])
                                    + v11[2])
                            + v11[3])
                    + v11[4])
            + v11[5];
        v11 += 8;
      }
      _Msg(
        a1: "Clock drift: adjustment (per sec): %.2fms, avg: %.3f, lo: %d, hi: %d, ex: %d\n",
        flAdjustment * 1000.0,
        v10 * 0.0625,
        v5,
        v4,
        v6);
    }
    else
    {
      _Msg(a1: "Clock drift disabled.\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014A600
// Name: public: float CClockDriftMgr::AdjustFrameTime(float)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CClockDriftMgr::AdjustFrameTime@<st0>(
        CClockDriftMgr *this@<ecx>,
        float a2@<xmm14>,
        float inputFrameTime)
{
  int v4; // eax
  double CurrentClockDifference; // st7
  float m_fValue; // xmm0_4
  float v7; // xmm0_4
  float flAmountInSeconds; // [esp+0h] [ebp-Ch]
  float v10; // [esp+4h] [ebp-8h]
  float flCurDiffInSeconds; // [esp+8h] [ebp-4h]

  flCurDiffInSeconds = 0.0;
  v10 = 0.0;
  if ( sv.m_State < ss_active || NET_GetFakeLag() > 0.0 )
  {
    v4 = cl_clock_correction.m_pParent != nullptr ? cl_clock_correction.m_pParent->m_Value.m_nValue : 0;
    if ( v4 != 0 && !demoplayer->IsPlayingBack(this: demoplayer) )
    {
      CurrentClockDifference = CClockDriftMgr::GetCurrentClockDifference(this);
      m_fValue = cl_clock_correction_adjustment_min_offset.m_pParent->m_Value.m_fValue;
      flAmountInSeconds = CurrentClockDifference * host_state.interval_per_tick;
      if ( (float)(flAmountInSeconds * 1000.0) <= m_fValue )
      {
        v7 = -m_fValue;
        if ( v7 > (float)(flAmountInSeconds * 1000.0) )
        {
          GetClockAdjustmentAmount(flCurDiffInMS: a2);
          v10 = v7;
          flCurDiffInSeconds = v7 * inputFrameTime;
          if ( (float)-flAmountInSeconds <= (float)(v7 * inputFrameTime) )
            flCurDiffInSeconds = -flAmountInSeconds;
        }
      }
      else
      {
        GetClockAdjustmentAmount(flCurDiffInMS: a2);
        v10 = -m_fValue;
        flCurDiffInSeconds = (float)-m_fValue * inputFrameTime;
        if ( flCurDiffInSeconds <= (float)-flAmountInSeconds )
          flCurDiffInSeconds = -flAmountInSeconds;
      }
      if ( g_bThreadedEngine )
        flCurDiffInSeconds = -flAmountInSeconds;
      CClockDriftMgr::AdjustAverageDifferenceBy(this, flAmountInSeconds: flCurDiffInSeconds);
    }
  }
  CClockDriftMgr::ShowDebugInfo(this, flAdjustment: v10);
  return flCurDiffInSeconds + inputFrameTime;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1014A2B0
// Name: public: void CClockDriftMgr::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClockDriftMgr::Clear(CClockDriftMgr *this)
{
  this->m_nClientTick = 0;
  this->m_nServerTick = 0;
  this->m_iCurClockOffset = 0;
  memset(dst: (unsigned __int8 *)this, value: 0, count: 0x40u);
}

//------------------------------------------------------------------------------
// Address: 0x1014A2D0
// Name: public: float CClockDriftMgr::GetCurrentClockDifference(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CClockDriftMgr::GetCurrentClockDifference(CClockDriftMgr *this)
{
  float v1; // xmm0_4
  float *v2; // eax
  int i; // ecx

  v1 = 0.0;
  v2 = &this->m_ClockOffsets[2];
  for ( i = 2; i != 0; --i )
  {
    v1 = (float)((float)((float)((float)((float)((float)((float)(v1 + *(v2 - 2)) + *(v2 - 1)) + *v2) + v2[1]) + v2[2])
                       + v2[3])
               + v2[4])
       + v2[5];
    v2 += 8;
  }
  return v1 * 0.0625;
}

//------------------------------------------------------------------------------
// Address: 0x1014A320
// Name: private: void CClockDriftMgr::AdjustAverageDifferenceBy(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClockDriftMgr::AdjustAverageDifferenceBy(CClockDriftMgr *this, float flAmountInSeconds)
{
  float v2; // xmm0_4
  float *v3; // eax
  float *v4; // ecx
  int i; // edx
  float v6; // xmm1_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  int j; // ecx

  v2 = 0.0;
  v3 = &this->m_ClockOffsets[2];
  v4 = &this->m_ClockOffsets[2];
  for ( i = 2; i != 0; --i )
  {
    v6 = (float)((float)((float)((float)((float)((float)((float)(*(v4 - 2) + v2) + *(v4 - 1)) + *v4) + v4[1]) + v4[2])
                       + v4[3])
               + v4[4])
       + v4[5];
    v4 += 8;
    v2 = v6;
  }
  v7 = v6 * 0.0625;
  if ( v7 >= 0.050000001 )
  {
    v8 = (float)((float)(flAmountInSeconds / host_state.interval_per_tick) / v7) + 1.0;
    for ( j = 2; j != 0; --j )
    {
      *(v3 - 2) = *(v3 - 2) * v8;
      *(v3 - 1) = *(v3 - 1) * v8;
      *v3 = *v3 * v8;
      v3[1] = v3[1] * v8;
      v3[2] = v3[2] * v8;
      v3[3] = v8 * v3[3];
      v3[4] = v3[4] * v8;
      v3[5] = v3[5] * v8;
      v3 += 8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014A420
// Name: GetClockAdjustmentAmount
// Source: json
//------------------------------------------------------------------------------
float __usercall GetClockAdjustmentAmount@<xmm0>(float a1@<xmm3>)
{
  float m_fValue; // xmm1_4
  float v3; // xmm0_4
  float v4; // xmm3_4

  m_fValue = cl_clock_correction_adjustment_max_offset.m_pParent->m_Value.m_fValue;
  v3 = m_fValue;
  if ( cl_clock_correction_adjustment_min_offset.m_pParent->m_Value.m_fValue <= a1 )
  {
    if ( a1 <= m_fValue )
      v3 = a1;
  }
  else
  {
    v3 = cl_clock_correction_adjustment_min_offset.m_pParent->m_Value.m_fValue;
  }
  v4 = cl_clock_correction_adjustment_min_offset.m_pParent->m_Value.m_fValue;
  if ( v4 != m_fValue )
    return (float)((float)(v3 - v4)
                 * (float)(cl_clock_correction_adjustment_max_amount.m_pParent->m_Value.m_fValue * 0.001))
         / (float)(m_fValue - v4);
  if ( (float)(v3 - m_fValue) < 0.0 )
    return 0.0;
  return cl_clock_correction_adjustment_max_amount.m_pParent->m_Value.m_fValue * 0.001;
}

//------------------------------------------------------------------------------
// Address: 0x1014A490
// Name: public: CClockDriftMgr::CClockDriftMgr(void)
// Source: json
//------------------------------------------------------------------------------
CClockDriftMgr *__thiscall CClockDriftMgr::CClockDriftMgr(CClockDriftMgr *this)
{
  this->m_nClientTick = 0;
  this->m_nServerTick = 0;
  this->m_iCurClockOffset = 0;
  memset(dst: (unsigned __int8 *)this, value: 0, count: 0x40u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014A4B0
// Name: public: static bool CClockDriftMgr::IsClockCorrectionEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CClockDriftMgr::IsClockCorrectionEnabled()
{
  if ( sv.m_State >= ss_active && NET_GetFakeLag() <= 0.0 )
    return false;
  if ( cl_clock_correction.m_pParent != nullptr )
    return cl_clock_correction.m_pParent->m_Value.m_nValue != 0;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1014A4F0
// Name: public: void CClockDriftMgr::SetServerTick(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClockDriftMgr::SetServerTick(CClockDriftMgr *this, int nTick)
{
  double m_fValue; // st7
  int v5; // edi
  int m_nValue; // eax
  int v7; // eax
  int v8; // esi
  int m_nClientTick; // esi
  int v10; // esi
  int nMaxDriftTicks; // [esp+14h] [ebp+8h]

  this->m_nServerTick = nTick;
  if ( g_bThreadedEngine )
    m_fValue = cl_clockdrift_max_ms_threadmode.m_pParent->m_Value.m_fValue;
  else
    m_fValue = cl_clockdrift_max_ms.m_pParent->m_Value.m_fValue;
  nMaxDriftTicks = (int)(m_fValue * 0.001 / host_state.interval_per_tick + 0.5);
  v5 = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick + g_ClientGlobalVariables.simTicksThisFrame - 1;
  if ( cl_clock_correction_force_server_tick.m_pParent == nullptr )
  {
    m_nValue = 0;
    goto LABEL_18;
  }
  m_nValue = cl_clock_correction_force_server_tick.m_pParent->m_Value.m_nValue;
  if ( m_nValue != 999 )
  {
LABEL_18:
    GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick = m_nValue + nTick;
    goto LABEL_19;
  }
  if ( sv.m_State >= ss_active && NET_GetFakeLag() <= 0.0
    || (cl_clock_correction.m_pParent == nullptr ? (v7 = 0) : (v7 = cl_clock_correction.m_pParent->m_Value.m_nValue),
        v7 == 0 || v5 == 0 || (int)abs32(nTick - v5) > nMaxDriftTicks) )
  {
    v8 = nTick - g_ClientGlobalVariables.simTicksThisFrame + 1;
    GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick = v8;
    m_nClientTick = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick;
    if ( m_nClientTick < GetBaseLocalClient()->oldtickcount )
    {
      v10 = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick;
      GetBaseLocalClient()->oldtickcount = v10;
    }
    memset(dst: (unsigned __int8 *)this, value: 0, count: 0x40u);
  }
LABEL_19:
  this->m_ClockOffsets[this->m_iCurClockOffset] = (float)(v5 - this->m_nServerTick);
  this->m_iCurClockOffset = (this->m_iCurClockOffset + 1) % 16;
}

//------------------------------------------------------------------------------
// Address: 0x1014A630
// Name: private: void CClockDriftMgr::ShowDebugInfo(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClockDriftMgr::ShowDebugInfo(CClockDriftMgr *this, float flAdjustment)
{
  int m_nValue; // eax
  int v4; // edi
  int v5; // esi
  int v6; // edx
  int i; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float *v11; // eax
  int j; // ecx

  if ( cl_clock_showdebuginfo.m_pParent != nullptr && cl_clock_showdebuginfo.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( (sv.m_State < ss_active || NET_GetFakeLag() > 0.0)
      && (cl_clock_correction.m_pParent == nullptr
        ? (m_nValue = 0)
        : (m_nValue = cl_clock_correction.m_pParent->m_Value.m_nValue),
          m_nValue != 0) )
    {
      v4 = -999;
      v5 = 999;
      v6 = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick - this->m_nServerTick;
      for ( i = 0; i < 16; ++i )
      {
        v8 = this->m_ClockOffsets[i];
        v9 = (float)v4;
        if ( (float)v4 <= v8 )
          v9 = this->m_ClockOffsets[i];
        v4 = (int)v9;
        if ( v8 > (float)v5 )
          v8 = (float)v5;
        v5 = (int)v8;
      }
      v10 = 0.0;
      v11 = &this->m_ClockOffsets[2];
      for ( j = 2; j != 0; --j )
      {
        v10 = (float)((float)((float)((float)((float)((float)((float)(v10 + *(v11 - 2)) + *(v11 - 1)) + *v11) + v11[1])
                                    + v11[2])
                            + v11[3])
                    + v11[4])
            + v11[5];
        v11 += 8;
      }
      _Msg(
        a1: "Clock drift: adjustment (per sec): %.2fms, avg: %.3f, lo: %d, hi: %d, ex: %d\n",
        flAdjustment * 1000.0,
        v10 * 0.0625,
        v5,
        v4,
        v6);
    }
    else
    {
      _Msg(a1: "Clock drift disabled.\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014A760
// Name: public: float CClockDriftMgr::AdjustFrameTime(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CClockDriftMgr::AdjustFrameTime(CClockDriftMgr *this, float inputFrameTime)
{
  int v3; // eax
  double CurrentClockDifference; // st7
  float m_fValue; // xmm0_4
  float v6; // xmm3_4
  float flAmountInSeconds; // [esp+0h] [ebp-Ch]
  float ClockAdjustmentAmount; // [esp+4h] [ebp-8h]
  float flCurDiffInSeconds; // [esp+8h] [ebp-4h]

  flCurDiffInSeconds = 0.0;
  ClockAdjustmentAmount = 0.0;
  if ( sv.m_State < ss_active || NET_GetFakeLag() > 0.0 )
  {
    v3 = cl_clock_correction.m_pParent != nullptr ? cl_clock_correction.m_pParent->m_Value.m_nValue : 0;
    if ( v3 != 0 && !demoplayer->IsPlayingBack(this: demoplayer) )
    {
      CurrentClockDifference = CClockDriftMgr::GetCurrentClockDifference(this);
      m_fValue = cl_clock_correction_adjustment_min_offset.m_pParent->m_Value.m_fValue;
      flAmountInSeconds = CurrentClockDifference * host_state.interval_per_tick;
      v6 = flAmountInSeconds * 1000.0;
      if ( (float)(flAmountInSeconds * 1000.0) <= m_fValue )
      {
        if ( (float)-m_fValue > v6 )
        {
          ClockAdjustmentAmount = GetClockAdjustmentAmount(a1: -v6);
          flCurDiffInSeconds = ClockAdjustmentAmount * inputFrameTime;
          if ( (float)-flAmountInSeconds <= (float)(ClockAdjustmentAmount * inputFrameTime) )
            flCurDiffInSeconds = -flAmountInSeconds;
        }
      }
      else
      {
        ClockAdjustmentAmount = -GetClockAdjustmentAmount(a1: v6);
        flCurDiffInSeconds = ClockAdjustmentAmount * inputFrameTime;
        if ( (float)(ClockAdjustmentAmount * inputFrameTime) <= (float)-flAmountInSeconds )
          flCurDiffInSeconds = -flAmountInSeconds;
      }
      if ( g_bThreadedEngine )
        flCurDiffInSeconds = -flAmountInSeconds;
      CClockDriftMgr::AdjustAverageDifferenceBy(this, flAmountInSeconds: flCurDiffInSeconds);
    }
  }
  CClockDriftMgr::ShowDebugInfo(this, flAdjustment: ClockAdjustmentAmount);
  return flCurDiffInSeconds + inputFrameTime;
}

} // namespace engine_xlsp
