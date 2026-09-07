// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/env_wind_shared.cpp
// Functions: 9
// ============================================================

#include "game\shared\env_wind_shared.h"

//------------------------------------------------------------------------------
// Address: 0x100D1B10
// Name: private: void CEnvWindShared::ComputeWindVariation(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvWindShared::ComputeWindVariation(CEnvWindShared *this, float flTime)
{
  double v3; // st7

  for ( ; flTime >= this->m_flVariationTime; this->m_flWindSpeedVariation = v3 + 1.0 )
  {
    this->m_flWindAngleVariation = ((double (__thiscall *)(CUniformRandomStream *, int, int))this->m_WindVariationStream.RandomFloat)(
                                     a1: &this->m_WindVariationStream,
                                     a2: -1054867456,
                                     a3: 1092616192);
    v3 = ((double (__thiscall *)(CUniformRandomStream *, int, int))this->m_WindVariationStream.RandomFloat)(
           a1: &this->m_WindVariationStream,
           a2: -1102263091,
           a3: 1045220557);
    this->m_flVariationTime = this->m_flVariationTime + 0.1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1BD0
// Name: void GetWindspeedAtTime(float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetWindspeedAtTime(float flTime, Vector *vecVelocity)
{
  if ( s_windControllers.m_ElementCount != 0 )
  {
    *vecVelocity = s_windControllers.m_Memory.m_pMemory[s_windControllers.m_Head].m_Element->m_currentWindVector;
  }
  else
  {
    vecVelocity->x = 0.0;
    vecVelocity->y = 0.0;
    vecVelocity->z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1DA0
// Name: cl_tree_sway_dir
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_tree_sway_dir(const CCommand *args)
{
  IMatRenderContext *v1; // esi
  const char *v2; // edi
  void (__thiscall *SetVectorRenderingParameter)(IMatRenderContext *, int, const Vector *); // edx
  Vector windDir; // [esp+4h] [ebp-Ch] BYREF

  v1 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v1 != nullptr )
    v1->BeginRender(this: v1);
  if ( args->m_nArgc == 3 )
  {
    windDir.x = V_atof(str: args->m_ppArgv[1]);
    if ( args->m_nArgc > 2 )
      v2 = args->m_ppArgv[2];
    else
      v2 = prType;
    windDir.y = V_atof(str: v2);
    SetVectorRenderingParameter = v1->SetVectorRenderingParameter;
    windDir.z = 0.0;
    SetVectorRenderingParameter(this: v1, a2: 3, a3: &windDir);
  }
  if ( v1 != nullptr )
  {
    v1->EndRender(this: v1);
    v1->Release(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1E40
// Name: public: void CEnvWindShared::Init(int,int,float,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvWindShared::Init(
        CEnvWindShared *this,
        int nEntIndex,
        int iRandomSeed,
        float flTime,
        int iInitialWindYaw,
        float flInitialWindSpeed)
{
  CNetworkVarBase<float,CEnvWindShared::NetworkVar_m_flStartTime> *p_m_flStartTime; // edi
  CNetworkVarBase<int,CEnvWindShared::NetworkVar_m_iInitialWindDir> *p_m_iInitialWindDir; // edi
  int v9; // edx
  int v10; // ebx
  CNetworkVarBase<float,CEnvWindShared::NetworkVar_m_flInitialWindSpeed> *p_m_flInitialWindSpeed; // edi
  float m_Value; // xmm0_4

  this->m_flWindSpeedVariation = 1.0;
  this->m_flWindAngleVariation = 1.0;
  this->m_iEntIndex = nEntIndex;
  this->m_flVariationTime = flTime;
  this->m_flSwitchTime = flTime;
  this->m_flSimTime = flTime;
  p_m_flStartTime = &this->m_flStartTime;
  if ( this->m_flStartTime.m_Value != this->m_flSimTime )
  {
    this->NetworkStateChanged(this, a2: &this->m_flStartTime);
    p_m_flStartTime->m_Value = this->m_flSimTime;
  }
  if ( this->m_iWindSeed.m_Value != iRandomSeed )
  {
    this->NetworkStateChanged(this, a2: &this->m_iWindSeed);
    this->m_iWindSeed.m_Value = iRandomSeed;
  }
  this->m_Stream.SetSeed(this: &this->m_Stream, a2: iRandomSeed);
  this->m_WindVariationStream.SetSeed(this: &this->m_WindVariationStream, a2: iRandomSeed);
  p_m_iInitialWindDir = &this->m_iInitialWindDir;
  if ( this->m_iInitialWindDir.m_Value != iInitialWindYaw )
  {
    this->NetworkStateChanged(this, a2: &this->m_iInitialWindDir);
    p_m_iInitialWindDir->m_Value = iInitialWindYaw;
  }
  v9 = (unsigned __int16)(int)(float)((float)p_m_iInitialWindDir->m_Value * 182.04445);
  this->m_iWindDir = p_m_iInitialWindDir->m_Value;
  v10 = (int)(float)((float)v9 * 0.0054931641);
  if ( p_m_iInitialWindDir->m_Value != v10 )
  {
    this->NetworkStateChanged(this, a2: &this->m_iInitialWindDir);
    p_m_iInitialWindDir->m_Value = v10;
  }
  p_m_flInitialWindSpeed = &this->m_flInitialWindSpeed;
  if ( this->m_flInitialWindSpeed.m_Value != flInitialWindSpeed )
  {
    this->NetworkStateChanged(this, a2: &this->m_flInitialWindSpeed);
    p_m_flInitialWindSpeed->m_Value = flInitialWindSpeed;
  }
  m_Value = p_m_flInitialWindSpeed->m_Value;
  this->m_flWindSpeed = p_m_flInitialWindSpeed->m_Value;
  this->m_flAveWindSpeed = m_Value;
  this->m_bGusting = true;
}

//------------------------------------------------------------------------------
// Address: 0x100D1F80
// Name: private: void CEnvWindShared::UpdateTreeSway(float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CEnvWindShared::UpdateTreeSway(CEnvWindShared *this@<ecx>, int a2@<edi>, int a3@<esi>, float flTime)
{
  float v5; // xmm2_4
  int v6; // edi
  float v7; // xmm4_4
  float v8; // xmm5_4
  Vector vecWind; // [esp+0h] [ebp-Ch] BYREF
  float flPercentage; // [esp+14h] [ebp+8h]

  if ( flTime >= this->m_flSwayTime )
  {
    do
    {
      this->m_PrevSwayVector = this->m_CurrentSwayVector;
      this->m_CurrentSwayVector = this->m_currentWindVector;
      v5 = this->m_flSwayTime + 2.0;
      this->m_flSwayTime = v5;
    }
    while ( flTime >= v5 );
  }
  flPercentage = 1.0 - (float)((float)(this->m_flSwayTime - flTime) * 0.5);
  v6 = ((int (__thiscall *)(IMaterialSystem *, int, int, _DWORD, _DWORD, _DWORD))g_pMaterialSystem->GetRenderContext)(
         a1: g_pMaterialSystem,
         a2,
         a3,
         a4: LODWORD(vecWind.x),
         a5: LODWORD(vecWind.y),
         a6: LODWORD(vecWind.z));
  if ( v6 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
  v7 = (float)(this->m_PrevSwayVector.y
             + (float)((float)(this->m_CurrentSwayVector.y - this->m_PrevSwayVector.y) * flPercentage))
     * 0.5;
  v8 = (float)(this->m_PrevSwayVector.z
             + (float)((float)(this->m_CurrentSwayVector.z - this->m_PrevSwayVector.z) * flPercentage))
     * 0.5;
  vecWind.x = (float)(this->m_PrevSwayVector.x
                    + (float)((float)(this->m_CurrentSwayVector.x - this->m_PrevSwayVector.x) * flPercentage))
            * 0.5;
  vecWind.y = v7;
  vecWind.z = v8;
  (*(void (__thiscall **)(int, int, Vector *))(*(_DWORD *)v6 + 468))(a1: v6, a2: 3, a3: &vecWind);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
  (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100D20B0
// Name: public: float CEnvWindShared::WindThink(float)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CEnvWindShared::WindThink@<st0>(CEnvWindShared *this@<ecx>, int a2@<edi>, float flTime)
{
  float m_flSwitchTime; // xmm3_4
  float m_flSimTime; // xmm2_4
  float v6; // xmm0_4
  char v7; // al
  float m_flAveWindSpeed; // xmm2_4
  float m_flWindSpeed; // xmm1_4
  float v10; // xmm0_4
  bool v11; // cc
  float v12; // xmm1_4
  bool v13; // zf
  float v14; // xmm0_4
  float (__thiscall *RandomFloat)(struct CUniformRandomStream *, float, float); // eax
  float v16; // xmm0_4
  int (__thiscall *RandomInt)(struct CUniformRandomStream *, int, int); // eax
  int v18; // eax
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v22; // xmm0_4
  float v23; // [esp+Ch] [ebp-18h]
  int m_Value; // [esp+Ch] [ebp-18h]
  QAngle vecWindAngle; // [esp+18h] [ebp-Ch] BYREF

  CEnvWindShared::ComputeWindVariation(this, flTime);
  CEnvWindShared::UpdateTreeSway(this, a2, a3: (int)this, flTime);
  while ( 1 )
  {
    m_flSwitchTime = this->m_flSwitchTime;
    m_flSimTime = this->m_flSimTime;
    v6 = m_flSwitchTime - m_flSimTime;
    if ( (float)(flTime - m_flSimTime) <= (float)(m_flSwitchTime - m_flSimTime) )
    {
      v7 = 0;
      v6 = flTime - m_flSimTime;
    }
    else
    {
      v7 = 1;
    }
    m_flAveWindSpeed = this->m_flAveWindSpeed;
    m_flWindSpeed = this->m_flWindSpeed;
    if ( m_flAveWindSpeed <= m_flWindSpeed )
    {
      if ( m_flWindSpeed <= m_flAveWindSpeed )
        goto LABEL_11;
      v12 = m_flWindSpeed - (float)(v6 * 15.0);
      this->m_flWindSpeed = v12;
      v11 = m_flAveWindSpeed <= v12;
    }
    else
    {
      v10 = (float)(v6 * 150.0) + m_flWindSpeed;
      this->m_flWindSpeed = v10;
      v11 = v10 <= m_flAveWindSpeed;
    }
    if ( !v11 )
      this->m_flWindSpeed = m_flAveWindSpeed;
LABEL_11:
    if ( v7 == 0 )
      break;
    v13 = !this->m_bGusting;
    this->m_flSimTime = m_flSwitchTime;
    if ( v13 )
    {
      v16 = (float)this->m_Stream.RandomInt(
                     this: &this->m_Stream,
                     a2: this->m_iMinGust.m_Value,
                     a3: this->m_iMaxGust.m_Value);
      m_Value = this->m_iGustDirChange.m_Value;
      RandomInt = this->m_Stream.RandomInt;
      this->m_flAveWindSpeed = v16;
      v18 = RandomInt(this: &this->m_Stream, a2: -m_Value, a3: m_Value);
      v19 = this->m_flGustDuration.m_Value + this->m_flSwitchTime;
      this->m_iWindDir = (int)(float)((float)(unsigned __int16)(int)(float)((float)(this->m_iWindDir + v18) * 182.04445)
                                    * 0.0054931641);
      this->m_bGusting = true;
      this->m_flSwitchTime = v19;
    }
    else
    {
      v14 = (float)this->m_Stream.RandomInt(
                     this: &this->m_Stream,
                     a2: this->m_iMinWind.m_Value,
                     a3: this->m_iMaxWind.m_Value);
      RandomFloat = this->m_Stream.RandomFloat;
      this->m_flAveWindSpeed = v14;
      v23 = this->m_flMaxGustDelay.m_Value;
      this->m_bGusting = false;
      this->m_flSwitchTime = ((double (__thiscall *)(CUniformRandomStream *, _DWORD, _DWORD))RandomFloat)(
                               a1: &this->m_Stream,
                               a2: 0,
                               a3: LODWORD(v23))
                           + this->m_flMinGustDelay.m_Value
                           + this->m_flSwitchTime;
    }
  }
  v20 = (float)this->m_iWindDir + this->m_flWindAngleVariation;
  this->m_flSimTime = flTime;
  vecWindAngle.x = 0.0;
  vecWindAngle.y = v20;
  vecWindAngle.z = 0.0;
  AngleVectors(angles: &vecWindAngle, forward: &this->m_currentWindVector);
  v22 = this->m_flWindSpeedVariation * this->m_flWindSpeed;
  this->m_currentWindVector.x = v22 * this->m_currentWindVector.x;
  this->m_currentWindVector.y = this->m_currentWindVector.y * v22;
  this->m_currentWindVector.z = this->m_currentWindVector.z * v22;
  return flTime + 0.0099999998;
}

//------------------------------------------------------------------------------
// Address: 0x100D22F0
// Name: void ResetWindspeed(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ResetWindspeed()
{
  int m_Next; // eax
  UtlLinkedListElem_t<CEnvWindShared *,unsigned short> *m_pMemory; // edx
  int v2; // ecx
  CEnvWindShared *m_Element; // eax

  LOWORD(m_Next) = s_windControllers.m_Head;
  if ( s_windControllers.m_Head != 0xFFFF )
  {
    m_pMemory = s_windControllers.m_Memory.m_pMemory;
    do
    {
      v2 = (unsigned __int16)m_Next;
      m_Element = m_pMemory[v2].m_Element;
      m_Element->m_currentWindVector.x = 0.0;
      m_Element->m_currentWindVector.y = 0.0;
      m_Element->m_currentWindVector.z = 0.0;
      m_pMemory = s_windControllers.m_Memory.m_pMemory;
      m_Next = s_windControllers.m_Memory.m_pMemory[v2].m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2430
// Name: public: CEnvWindShared::CEnvWindShared(void)
// Source: json
//------------------------------------------------------------------------------
CEnvWindShared *__thiscall CEnvWindShared::CEnvWindShared(CEnvWindShared *this)
{
  unsigned __int16 v2; // ax
  int v3; // edi
  UtlLinkedListElem_t<CEnvWindShared *,unsigned short> *v4; // eax

  this->__vftable = (CEnvWindShared_vtbl *)&CEnvWindShared::`vftable';
  CUniformRandomStream::CUniformRandomStream(this: &this->m_Stream);
  CUniformRandomStream::CUniformRandomStream(this: &this->m_WindVariationStream);
  this->m_WindAveQueue.m_flMaxTime = 10.0;
  this->m_WindAveQueue.m_Queue.m_Memory.m_pMemory = nullptr;
  this->m_WindAveQueue.m_Queue.m_Memory.m_nAllocationCount = 0;
  this->m_WindAveQueue.m_Queue.m_Memory.m_nGrowSize = 0;
  this->m_WindAveQueue.m_Queue.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_WindAveQueue.m_Queue.m_FirstFree = 0xFFFF;
  this->m_WindAveQueue.m_Queue.m_pElements = this->m_WindAveQueue.m_Queue.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_WindAveQueue.m_Queue.m_Head = -1;
  this->m_WindAveQueue.m_Queue.m_NumAlloced = 0;
  this->m_WindAveQueue.m_flQueueHeadTime = -3.4028235e38;
  this->m_WindVariationQueue.m_flMaxTime = 10.0;
  this->m_WindVariationQueue.m_Queue.m_Memory.m_pMemory = nullptr;
  this->m_WindVariationQueue.m_Queue.m_Memory.m_nAllocationCount = 0;
  this->m_WindVariationQueue.m_Queue.m_Memory.m_nGrowSize = 0;
  this->m_WindVariationQueue.m_Queue.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_WindVariationQueue.m_Queue.m_FirstFree = 0xFFFF;
  this->m_WindVariationQueue.m_Queue.m_pElements = this->m_WindVariationQueue.m_Queue.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_WindVariationQueue.m_Queue.m_Head = -1;
  this->m_WindVariationQueue.m_Queue.m_NumAlloced = 0;
  this->m_WindVariationQueue.m_flQueueHeadTime = -3.4028235e38;
  this->m_pWindSound = nullptr;
  v2 = CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::AllocInternal(
         this: &s_windControllers,
         multilist: false);
  v3 = v2;
  if ( v2 != 0xFFFF )
  {
    CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)&s_windControllers,
      before: 0xFFFFu,
      elem: v2);
    v4 = &s_windControllers.m_Memory.m_pMemory[v3];
    if ( v4 != nullptr )
      v4->m_Element = this;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D2550
// Name: public: CEnvWindShared::~CEnvWindShared(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvWindShared::~CEnvWindShared(CEnvWindShared *this)
{
  bool v2; // zf
  CSoundEnvelopeController *Controller; // eax
  CEnvWindShared *src; // [esp+8h] [ebp-4h] BYREF

  v2 = this->m_pWindSound == nullptr;
  this->__vftable = (CEnvWindShared_vtbl *)&CEnvWindShared::`vftable';
  if ( !v2 )
  {
    Controller = CSoundEnvelopeController::GetController();
    Controller->Shutdown(this: Controller, a2: this->m_pWindSound);
  }
  src = this;
  CUtlLinkedList<C_BaseEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseEntity *,unsigned short>,unsigned short>>::FindAndRemove(
    this: &s_windControllers,
    &src);
  CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_WindVariationQueue.m_Queue);
  if ( this->m_WindVariationQueue.m_Queue.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_WindVariationQueue.m_Queue.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WindVariationQueue.m_Queue.m_Memory.m_pMemory);
      this->m_WindVariationQueue.m_Queue.m_Memory.m_pMemory = nullptr;
    }
    this->m_WindVariationQueue.m_Queue.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CEnvWindShared::WindVariationEvent_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared::WindVariationEvent_t,unsigned short>,unsigned short> > *)&this->m_WindAveQueue.m_Queue);
  if ( this->m_WindAveQueue.m_Queue.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_WindAveQueue.m_Queue.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WindAveQueue.m_Queue.m_Memory.m_pMemory);
      this->m_WindAveQueue.m_Queue.m_Memory.m_pMemory = nullptr;
    }
    this->m_WindAveQueue.m_Queue.m_Memory.m_nAllocationCount = 0;
  }
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1011A450
// Name: private: void CEnvWindShared::ComputeWindVariation(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvWindShared::ComputeWindVariation(CEnvWindShared *this, float flTime)
{
  double v3; // st7

  for ( ; flTime >= this->m_flVariationTime; this->m_flWindSpeedVariation = v3 + 1.0 )
  {
    this->m_flWindAngleVariation = ((double (__thiscall *)(CUniformRandomStream *, int, int))this->m_WindVariationStream.RandomFloat)(
                                     a1: &this->m_WindVariationStream,
                                     a2: -1054867456,
                                     a3: 1092616192);
    v3 = ((double (__thiscall *)(CUniformRandomStream *, int, int))this->m_WindVariationStream.RandomFloat)(
           a1: &this->m_WindVariationStream,
           a2: -1102263091,
           a3: 1045220557);
    this->m_flVariationTime = this->m_flVariationTime + 0.1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011A510
// Name: public: float CEnvWindShared::WindThink(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEnvWindShared::WindThink(CEnvWindShared *this, float flTime)
{
  float m_flSwitchTime; // xmm3_4
  float m_flSimTime; // xmm2_4
  float v5; // xmm0_4
  char v6; // al
  float m_flAveWindSpeed; // xmm2_4
  float m_flWindSpeed; // xmm1_4
  float v9; // xmm0_4
  bool v10; // cc
  float v11; // xmm1_4
  bool v12; // zf
  float v13; // xmm0_4
  float (__thiscall *RandomFloat)(struct CUniformRandomStream *, float, float); // eax
  float v15; // xmm0_4
  int (__thiscall *RandomInt)(struct CUniformRandomStream *, int, int); // eax
  float v17; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float fDelay; // [esp+10h] [ebp-18h]
  int fDelaya; // [esp+10h] [ebp-18h]
  QAngle vecWindAngle; // [esp+1Ch] [ebp-Ch] BYREF

  CEnvWindShared::ComputeWindVariation(this, flTime);
  while ( 1 )
  {
    m_flSwitchTime = this->m_flSwitchTime;
    m_flSimTime = this->m_flSimTime;
    v5 = m_flSwitchTime - m_flSimTime;
    if ( (float)(flTime - m_flSimTime) <= (float)(m_flSwitchTime - m_flSimTime) )
    {
      v6 = 0;
      v5 = flTime - m_flSimTime;
    }
    else
    {
      v6 = 1;
    }
    m_flAveWindSpeed = this->m_flAveWindSpeed;
    m_flWindSpeed = this->m_flWindSpeed;
    if ( m_flAveWindSpeed <= m_flWindSpeed )
    {
      if ( m_flWindSpeed <= m_flAveWindSpeed )
        goto LABEL_11;
      v11 = m_flWindSpeed - (float)(v5 * 15.0);
      this->m_flWindSpeed = v11;
      v10 = m_flAveWindSpeed <= v11;
    }
    else
    {
      v9 = (float)(v5 * 150.0) + m_flWindSpeed;
      this->m_flWindSpeed = v9;
      v10 = v9 <= m_flAveWindSpeed;
    }
    if ( !v10 )
      this->m_flWindSpeed = m_flAveWindSpeed;
LABEL_11:
    if ( v6 == 0 )
      break;
    v12 = !this->m_bGusting;
    this->m_flSimTime = m_flSwitchTime;
    if ( v12 )
    {
      v15 = (float)this->m_Stream.RandomInt(
                     this: &this->m_Stream,
                     a2: this->m_iMinGust.m_Value,
                     a3: this->m_iMaxGust.m_Value);
      fDelaya = this->m_iGustDirChange.m_Value;
      RandomInt = this->m_Stream.RandomInt;
      this->m_flAveWindSpeed = v15;
      this->m_iWindDir = (int)(float)((float)(unsigned __int16)(int)(float)((float)(this->m_iWindDir
                                                                                  + RandomInt(
                                                                                      this: &this->m_Stream,
                                                                                      a2: -fDelaya,
                                                                                      a3: fDelaya))
                                                                          * 182.04445)
                                    * 0.0054931641);
      this->m_bGusting = true;
      COutputEvent::FireOutput(this: &this->m_OnGustStart, pActivator: nullptr, pCaller: nullptr, fDelay: 0.0);
      this->m_flSwitchTime = this->m_flGustDuration.m_Value + this->m_flSwitchTime;
    }
    else
    {
      v13 = (float)this->m_Stream.RandomInt(
                     this: &this->m_Stream,
                     a2: this->m_iMinWind.m_Value,
                     a3: this->m_iMaxWind.m_Value);
      RandomFloat = this->m_Stream.RandomFloat;
      this->m_flAveWindSpeed = v13;
      fDelay = this->m_flMaxGustDelay.m_Value;
      this->m_bGusting = false;
      this->m_flSwitchTime = ((double (__thiscall *)(CUniformRandomStream *, _DWORD, _DWORD))RandomFloat)(
                               a1: &this->m_Stream,
                               a2: 0,
                               a3: LODWORD(fDelay))
                           + this->m_flMinGustDelay.m_Value
                           + this->m_flSwitchTime;
      COutputEvent::FireOutput(this: &this->m_OnGustEnd, pActivator: nullptr, pCaller: nullptr, fDelay: 0.0);
    }
  }
  v17 = (float)this->m_iWindDir + this->m_flWindAngleVariation;
  this->m_flSimTime = flTime;
  vecWindAngle.x = 0.0;
  vecWindAngle.y = v17;
  vecWindAngle.z = 0.0;
  AngleVectors(angles: &vecWindAngle, forward: &this->m_currentWindVector);
  v19 = this->m_flWindSpeedVariation * this->m_flWindSpeed;
  this->m_currentWindVector.x = this->m_currentWindVector.x * v19;
  v20 = v19 * this->m_currentWindVector.y;
  v21 = v19 * this->m_currentWindVector.z;
  this->m_currentWindVector.y = v20;
  this->m_currentWindVector.z = v21;
  return flTime + 0.0099999998;
}

//------------------------------------------------------------------------------
// Address: 0x1011A8F0
// Name: public: void CEnvWindShared::Init(int,int,float,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvWindShared::Init(
        CEnvWindShared *this,
        int nEntIndex,
        int iRandomSeed,
        float flTime,
        int iInitialWindYaw,
        float flInitialWindSpeed)
{
  CNetworkVarBase<float,CEnvWindShared::NetworkVar_m_flStartTime> *p_m_flStartTime; // edi
  CNetworkVarBase<int,CEnvWindShared::NetworkVar_m_iInitialWindDir> *p_m_iInitialWindDir; // edi
  int v9; // edx
  int v10; // ebx
  CNetworkVarBase<float,CEnvWindShared::NetworkVar_m_flInitialWindSpeed> *p_m_flInitialWindSpeed; // edi
  float m_Value; // xmm0_4

  this->m_flWindSpeedVariation = 1.0;
  this->m_flWindAngleVariation = 1.0;
  this->m_iEntIndex = nEntIndex;
  this->m_flVariationTime = flTime;
  this->m_flSwitchTime = flTime;
  this->m_flSimTime = flTime;
  p_m_flStartTime = &this->m_flStartTime;
  if ( this->m_flStartTime.m_Value != this->m_flSimTime )
  {
    this->NetworkStateChanged(this, a2: &this->m_flStartTime);
    p_m_flStartTime->m_Value = this->m_flSimTime;
  }
  if ( this->m_iWindSeed.m_Value != iRandomSeed )
  {
    this->NetworkStateChanged(this, a2: &this->m_iWindSeed);
    this->m_iWindSeed.m_Value = iRandomSeed;
  }
  this->m_Stream.SetSeed(this: &this->m_Stream, a2: iRandomSeed);
  this->m_WindVariationStream.SetSeed(this: &this->m_WindVariationStream, a2: iRandomSeed);
  p_m_iInitialWindDir = &this->m_iInitialWindDir;
  if ( this->m_iInitialWindDir.m_Value != iInitialWindYaw )
  {
    this->NetworkStateChanged(this, a2: &this->m_iInitialWindDir);
    p_m_iInitialWindDir->m_Value = iInitialWindYaw;
  }
  v9 = (unsigned __int16)(int)(float)((float)p_m_iInitialWindDir->m_Value * 182.04445);
  this->m_iWindDir = p_m_iInitialWindDir->m_Value;
  v10 = (int)(float)((float)v9 * 0.0054931641);
  if ( p_m_iInitialWindDir->m_Value != v10 )
  {
    this->NetworkStateChanged(this, a2: &this->m_iInitialWindDir);
    p_m_iInitialWindDir->m_Value = v10;
  }
  p_m_flInitialWindSpeed = &this->m_flInitialWindSpeed;
  if ( this->m_flInitialWindSpeed.m_Value != flInitialWindSpeed )
  {
    this->NetworkStateChanged(this, a2: &this->m_flInitialWindSpeed);
    p_m_flInitialWindSpeed->m_Value = flInitialWindSpeed;
  }
  m_Value = p_m_flInitialWindSpeed->m_Value;
  this->m_flWindSpeed = p_m_flInitialWindSpeed->m_Value;
  this->m_flAveWindSpeed = m_Value;
  this->m_bGusting = true;
}

//------------------------------------------------------------------------------
// Address: 0x1011AA40
// Name: void ResetWindspeed(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ResetWindspeed()
{
  int m_Next; // eax
  UtlLinkedListElem_t<CEnvWindShared *,unsigned short> *m_pMemory; // edx
  int v2; // ecx
  CEnvWindShared *m_Element; // eax

  LOWORD(m_Next) = s_windControllers.m_Head;
  if ( s_windControllers.m_Head != 0xFFFF )
  {
    m_pMemory = s_windControllers.m_Memory.m_pMemory;
    do
    {
      v2 = (unsigned __int16)m_Next;
      m_Element = m_pMemory[v2].m_Element;
      m_Element->m_currentWindVector.x = 0.0;
      m_Element->m_currentWindVector.y = 0.0;
      m_Element->m_currentWindVector.z = 0.0;
      m_pMemory = s_windControllers.m_Memory.m_pMemory;
      m_Next = s_windControllers.m_Memory.m_pMemory[v2].m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011AA90
// Name: public: CEnvWindShared::CEnvWindShared(void)
// Source: json
//------------------------------------------------------------------------------
CEnvWindShared *__thiscall CEnvWindShared::CEnvWindShared(CEnvWindShared *this)
{
  unsigned __int16 v2; // ax
  int v3; // ebx
  UtlLinkedListElem_t<CEnvWindShared *,unsigned short> *v4; // eax

  this->__vftable = (CEnvWindShared_vtbl *)&CEnvWindShared::`vftable';
  this->m_OnGustStart.m_Value.iVal = 0;
  this->m_OnGustStart.m_Value.eVal.m_Index = -1;
  this->m_OnGustStart.m_Value.fieldType = FIELD_VOID;
  this->m_OnGustEnd.m_Value.iVal = 0;
  this->m_OnGustEnd.m_Value.eVal.m_Index = -1;
  this->m_OnGustEnd.m_Value.fieldType = FIELD_VOID;
  CUniformRandomStream::CUniformRandomStream(this: &this->m_Stream);
  CUniformRandomStream::CUniformRandomStream(this: &this->m_WindVariationStream);
  this->m_WindAveQueue.m_flMaxTime = 10.0;
  this->m_WindAveQueue.m_Queue.m_Memory.m_pMemory = nullptr;
  this->m_WindAveQueue.m_Queue.m_Memory.m_nAllocationCount = 0;
  this->m_WindAveQueue.m_Queue.m_Memory.m_nGrowSize = 0;
  this->m_WindAveQueue.m_Queue.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_WindAveQueue.m_Queue.m_FirstFree = 0xFFFF;
  this->m_WindAveQueue.m_Queue.m_pElements = this->m_WindAveQueue.m_Queue.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_WindAveQueue.m_Queue.m_Head = -1;
  this->m_WindAveQueue.m_Queue.m_NumAlloced = 0;
  this->m_WindAveQueue.m_flQueueHeadTime = -3.4028235e38;
  this->m_WindVariationQueue.m_flMaxTime = 10.0;
  this->m_WindVariationQueue.m_Queue.m_Memory.m_pMemory = nullptr;
  this->m_WindVariationQueue.m_Queue.m_Memory.m_nAllocationCount = 0;
  this->m_WindVariationQueue.m_Queue.m_Memory.m_nGrowSize = 0;
  this->m_WindVariationQueue.m_Queue.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_WindVariationQueue.m_Queue.m_FirstFree = 0xFFFF;
  this->m_WindVariationQueue.m_Queue.m_pElements = this->m_WindVariationQueue.m_Queue.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_WindVariationQueue.m_Queue.m_Head = -1;
  this->m_WindVariationQueue.m_Queue.m_NumAlloced = 0;
  this->m_WindVariationQueue.m_flQueueHeadTime = -3.4028235e38;
  this->m_pWindSound = nullptr;
  v2 = CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::AllocInternal(
         this: &s_windControllers,
         multilist: false);
  v3 = v2;
  if ( v2 != 0xFFFF )
  {
    CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&s_windControllers,
      before: 0xFFFFu,
      elem: v2);
    v4 = &s_windControllers.m_Memory.m_pMemory[v3];
    if ( v4 != nullptr )
      v4->m_Element = this;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1011ABD0
// Name: public: CEnvWindShared::~CEnvWindShared(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvWindShared::~CEnvWindShared(CEnvWindShared *this)
{
  bool v2; // zf
  CSoundEnvelopeController *Controller; // eax
  CBaseCombatWeapon *src; // [esp+8h] [ebp-4h] BYREF

  v2 = this->m_pWindSound == nullptr;
  this->__vftable = (CEnvWindShared_vtbl *)&CEnvWindShared::`vftable';
  if ( !v2 )
  {
    Controller = CSoundEnvelopeController::GetController();
    Controller->Shutdown(this: Controller, a2: this->m_pWindSound);
  }
  src = (CBaseCombatWeapon *)this;
  CUtlLinkedList<CFuncNavBlocker *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFuncNavBlocker *,unsigned short>,unsigned short>>::FindAndRemove(
    this: (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&s_windControllers,
    &src);
  CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_WindVariationQueue.m_Queue);
  if ( this->m_WindVariationQueue.m_Queue.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_WindVariationQueue.m_Queue.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WindVariationQueue.m_Queue.m_Memory.m_pMemory);
      this->m_WindVariationQueue.m_Queue.m_Memory.m_pMemory = nullptr;
    }
    this->m_WindVariationQueue.m_Queue.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CEnvWindShared::WindVariationEvent_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared::WindVariationEvent_t,unsigned short>,unsigned short> > *)&this->m_WindAveQueue.m_Queue);
  if ( this->m_WindAveQueue.m_Queue.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_WindAveQueue.m_Queue.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WindAveQueue.m_Queue.m_Memory.m_pMemory);
      this->m_WindAveQueue.m_Queue.m_Memory.m_pMemory = nullptr;
    }
    this->m_WindAveQueue.m_Queue.m_Memory.m_nAllocationCount = 0;
  }
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnGustEnd);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnGustStart);
}

} // namespace server
