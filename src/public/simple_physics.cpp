// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/simple_physics.cpp
// Functions: 3
// ============================================================

#include "public\simple_physics.h"

//------------------------------------------------------------------------------
// Address: 0x100A3CE0
// Name: public: void CSimplePhysics::Init(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimplePhysics::Init(CSimplePhysics *this, float flTimeStep)
{
  this->m_flPredictedTime = 0.0;
  this->m_flTimeStep = flTimeStep;
  this->m_iCurTimeStep = 0;
  this->m_flTimeStepMul = (float)(flTimeStep * flTimeStep) * 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x100A3D10
// Name: public: void CSimplePhysics::Simulate(class CSimplePhysics::CNode __near *,int,class CSimplePhysics::IHelper __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimplePhysics::Simulate(
        CSimplePhysics *this,
        CSimplePhysics::CNode *pNodes,
        int nNodes,
        CSimplePhysics::IHelper *pHelper,
        float dt,
        float flDamp)
{
  CSimplePhysics *v6; // esi
  float m_flTimeStep; // xmm1_4
  long double v8; // xmm0_8
  int x_low; // eax
  int v10; // ecx
  int v11; // edi
  float *p_z; // esi
  float y; // edx
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm0_4
  float v17; // xmm6_4
  float v18; // xmm3_4
  float x; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  double m_flPredictedTime; // xmm2_8
  int v23; // esi
  float v24; // xmm0_4
  float *p_y; // eax
  unsigned int v26; // ecx
  float *v27; // eax
  int v28; // edx
  float X_4; // [esp+10h] [ebp-28h]
  float v30; // [esp+14h] [ebp-24h]
  float v31[3]; // [esp+18h] [ebp-20h] BYREF
  Vector vAccel; // [esp+24h] [ebp-14h]
  Vector vPrevPos; // [esp+30h] [ebp-8h]
  CSimplePhysics::CNode *pNodesa; // [esp+4Ch] [ebp+14h]

  v6 = this;
  m_flTimeStep = this->m_flTimeStep;
  v8 = dt + this->m_flPredictedTime;
  this->m_flPredictedTime = v8;
  LODWORD(vPrevPos.y) = this;
  x_low = (int)ceil(X: v8 / m_flTimeStep);
  v10 = x_low - v6->m_iCurTimeStep;
  LODWORD(vPrevPos.x) = x_low;
  if ( v10 > 0 )
  {
    for ( pNodesa = (CSimplePhysics::CNode *)v10;
          pNodesa != nullptr;
          pNodesa = (CSimplePhysics::CNode *)((char *)pNodesa - 1) )
    {
      v11 = 0;
      if ( nNodes > 0 )
      {
        p_z = &pNodes->m_vPrevPos.z;
        do
        {
          pHelper->GetNodeForces(this: pHelper, a2: pNodes, a3: v11, a4: (Vector *)v31);
          y = vPrevPos.y;
          v14 = *(p_z - 4);
          v15 = *(p_z - 3);
          *(_QWORD *)&vAccel.x = *(_QWORD *)(p_z - 5);
          v16 = *(float *)(LODWORD(vPrevPos.y) + 16);
          X_4 = v31[1] * v16;
          v17 = v31[0] * v16;
          v30 = v31[2] * v16;
          v18 = vAccel.x + (float)((float)(vAccel.x - *(p_z - 2)) * flDamp);
          x = vAccel.x;
          v20 = (float)(v15 - *p_z) * flDamp;
          *(p_z - 4) = (float)(v14 + (float)((float)(v14 - *(p_z - 1)) * flDamp)) + X_4;
          *(p_z - 3) = (float)(v15 + v20) + v30;
          *(p_z - 5) = v18 + v17;
          *(p_z - 2) = x;
          *(p_z - 1) = vAccel.y;
          vAccel.z = v15;
          *p_z = v15;
          ++v11;
          p_z += 9;
        }
        while ( v11 < nNodes );
        v6 = (CSimplePhysics *)LODWORD(y);
      }
      pHelper->ApplyConstraints(this: pHelper, a2: pNodes, a3: nNodes);
    }
    x_low = LODWORD(vPrevPos.x);
  }
  v21 = v6->m_flTimeStep;
  m_flPredictedTime = v6->m_flPredictedTime;
  v6->m_iCurTimeStep = x_low;
  v23 = 0;
  v24 = (m_flPredictedTime - (float)((float)((float)x_low * v21) - v21)) / v21;
  if ( nNodes >= 4 )
  {
    p_y = &pNodes[1].m_vPrevPos.y;
    v26 = ((unsigned int)(nNodes - 4) >> 2) + 1;
    v23 = 4 * v26;
    do
    {
      *(p_y - 7) = (float)((float)(*(p_y - 13) - *(p_y - 10)) * v24) + *(p_y - 10);
      *(p_y - 6) = (float)((float)(*(p_y - 12) - *(p_y - 9)) * v24) + *(p_y - 9);
      *(p_y - 5) = (float)((float)(*(p_y - 11) - *(p_y - 8)) * v24) + *(p_y - 8);
      p_y[2] = (float)((float)(*(p_y - 4) - *(p_y - 1)) * v24) + *(p_y - 1);
      p_y[3] = (float)((float)(*(p_y - 3) - *p_y) * v24) + *p_y;
      p_y[4] = (float)((float)(*(p_y - 2) - p_y[1]) * v24) + p_y[1];
      p_y[11] = (float)((float)(p_y[5] - p_y[8]) * v24) + p_y[8];
      p_y[12] = (float)((float)(p_y[6] - p_y[9]) * v24) + p_y[9];
      p_y[13] = (float)((float)(p_y[7] - p_y[10]) * v24) + p_y[10];
      p_y[20] = (float)((float)(p_y[14] - p_y[17]) * v24) + p_y[17];
      p_y[21] = (float)((float)(p_y[15] - p_y[18]) * v24) + p_y[18];
      p_y[22] = (float)((float)(p_y[16] - p_y[19]) * v24) + p_y[19];
      p_y += 36;
      --v26;
    }
    while ( v26 != 0 );
  }
  if ( v23 < nNodes )
  {
    v27 = &pNodes[v23].m_vPrevPos.y;
    v28 = nNodes - v23;
    do
    {
      v27[2] = (float)((float)(*(v27 - 4) - *(v27 - 1)) * v24) + *(v27 - 1);
      v27[3] = (float)((float)(*(v27 - 3) - *v27) * v24) + *v27;
      v27[4] = (float)((float)(*(v27 - 2) - v27[1]) * v24) + v27[1];
      v27 += 9;
      --v28;
    }
    while ( v28 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4060
// Name: public: CSimplePhysics::CSimplePhysics(void)
// Source: json
//------------------------------------------------------------------------------
CSimplePhysics *__thiscall CSimplePhysics::CSimplePhysics(CSimplePhysics *this)
{
  this->m_flPredictedTime = 0.0;
  this->m_flTimeStep = 0.033333335;
  this->m_iCurTimeStep = 0;
  this->m_flTimeStepMul = 0.00055555563;
  return this;
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1016A690
// Name: public: void CSimplePhysics::Init(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimplePhysics::Init(CSimplePhysics *this, float flTimeStep)
{
  this->m_flPredictedTime = 0.0;
  this->m_flTimeStep = flTimeStep;
  this->m_iCurTimeStep = 0;
  this->m_flTimeStepMul = (float)(flTimeStep * flTimeStep) * 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x1016A6C0
// Name: public: void CSimplePhysics::Simulate(class CSimplePhysics::CNode __near *,int,class CSimplePhysics::IHelper __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimplePhysics::Simulate(
        CSimplePhysics *this,
        CSimplePhysics::CNode *pNodes,
        int nNodes,
        CSimplePhysics::IHelper *pHelper,
        float dt,
        float flDamp)
{
  CSimplePhysics *v6; // esi
  float m_flTimeStep; // xmm1_4
  long double v8; // xmm0_8
  int v9; // eax
  int v10; // ecx
  int v11; // edi
  float *p_z; // esi
  CSimplePhysics *v13; // edx
  float v14; // xmm4_4
  float v15; // xmm5_4
  float m_flTimeStepMul; // xmm0_4
  float v17; // xmm6_4
  float v18; // xmm3_4
  float x; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  double m_flPredictedTime; // xmm2_8
  int v23; // esi
  float v24; // xmm0_4
  float *p_y; // eax
  unsigned int v26; // ecx
  float *v27; // eax
  int v28; // edx
  float v29; // [esp+10h] [ebp-28h]
  float v30; // [esp+14h] [ebp-24h]
  Vector vAccel; // [esp+18h] [ebp-20h] BYREF
  Vector vPrevPos; // [esp+24h] [ebp-14h]
  int newTimeStep; // [esp+30h] [ebp-8h]
  CSimplePhysics *v34; // [esp+34h] [ebp-4h]
  int dta; // [esp+4Ch] [ebp+14h]

  v6 = this;
  m_flTimeStep = this->m_flTimeStep;
  v8 = dt + this->m_flPredictedTime;
  this->m_flPredictedTime = v8;
  v34 = this;
  v9 = (int)ceil(X: v8 / m_flTimeStep);
  v10 = v9 - v6->m_iCurTimeStep;
  newTimeStep = v9;
  if ( v10 > 0 )
  {
    for ( dta = v10; dta != 0; --dta )
    {
      v11 = 0;
      if ( nNodes > 0 )
      {
        p_z = &pNodes->m_vPrevPos.z;
        do
        {
          pHelper->GetNodeForces(this: pHelper, a2: pNodes, a3: v11, a4: &vAccel);
          v13 = v34;
          v14 = *(p_z - 4);
          v15 = *(p_z - 3);
          *(_QWORD *)&vPrevPos.x = *(_QWORD *)(p_z - 5);
          m_flTimeStepMul = v34->m_flTimeStepMul;
          v29 = vAccel.y * m_flTimeStepMul;
          v17 = vAccel.x * m_flTimeStepMul;
          v30 = vAccel.z * m_flTimeStepMul;
          v18 = vPrevPos.x + (float)((float)(vPrevPos.x - *(p_z - 2)) * flDamp);
          x = vPrevPos.x;
          v20 = (float)(v15 - *p_z) * flDamp;
          *(p_z - 4) = (float)(v14 + (float)((float)(v14 - *(p_z - 1)) * flDamp)) + v29;
          *(p_z - 3) = (float)(v15 + v20) + v30;
          *(p_z - 5) = v18 + v17;
          *(p_z - 2) = x;
          *(p_z - 1) = vPrevPos.y;
          vPrevPos.z = v15;
          *p_z = v15;
          ++v11;
          p_z += 9;
        }
        while ( v11 < nNodes );
        v6 = v13;
      }
      pHelper->ApplyConstraints(this: pHelper, a2: pNodes, a3: nNodes);
    }
    v9 = newTimeStep;
  }
  v21 = v6->m_flTimeStep;
  m_flPredictedTime = v6->m_flPredictedTime;
  v6->m_iCurTimeStep = v9;
  v23 = 0;
  v24 = (m_flPredictedTime - (float)((float)((float)v9 * v21) - v21)) / v21;
  if ( nNodes >= 4 )
  {
    p_y = &pNodes[1].m_vPrevPos.y;
    v26 = ((unsigned int)(nNodes - 4) >> 2) + 1;
    v23 = 4 * v26;
    do
    {
      *(p_y - 7) = (float)((float)(*(p_y - 13) - *(p_y - 10)) * v24) + *(p_y - 10);
      *(p_y - 6) = (float)((float)(*(p_y - 12) - *(p_y - 9)) * v24) + *(p_y - 9);
      *(p_y - 5) = (float)((float)(*(p_y - 11) - *(p_y - 8)) * v24) + *(p_y - 8);
      p_y[2] = (float)((float)(*(p_y - 4) - *(p_y - 1)) * v24) + *(p_y - 1);
      p_y[3] = (float)((float)(*(p_y - 3) - *p_y) * v24) + *p_y;
      p_y[4] = (float)((float)(*(p_y - 2) - p_y[1]) * v24) + p_y[1];
      p_y[11] = (float)((float)(p_y[5] - p_y[8]) * v24) + p_y[8];
      p_y[12] = (float)((float)(p_y[6] - p_y[9]) * v24) + p_y[9];
      p_y[13] = (float)((float)(p_y[7] - p_y[10]) * v24) + p_y[10];
      p_y[20] = (float)((float)(p_y[14] - p_y[17]) * v24) + p_y[17];
      p_y[21] = (float)((float)(p_y[15] - p_y[18]) * v24) + p_y[18];
      p_y[22] = (float)((float)(p_y[16] - p_y[19]) * v24) + p_y[19];
      p_y += 36;
      --v26;
    }
    while ( v26 != 0 );
  }
  if ( v23 < nNodes )
  {
    v27 = &pNodes[v23].m_vPrevPos.y;
    v28 = nNodes - v23;
    do
    {
      v27[2] = (float)((float)(*(v27 - 4) - *(v27 - 1)) * v24) + *(v27 - 1);
      v27[3] = (float)((float)(*(v27 - 3) - *v27) * v24) + *v27;
      v27[4] = (float)((float)(*(v27 - 2) - v27[1]) * v24) + v27[1];
      v27 += 9;
      --v28;
    }
    while ( v28 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016AA10
// Name: public: CSimplePhysics::CSimplePhysics(void)
// Source: json
//------------------------------------------------------------------------------
CSimplePhysics *__thiscall CSimplePhysics::CSimplePhysics(CSimplePhysics *this)
{
  this->m_flPredictedTime = 0.0;
  this->m_flTimeStep = 0.033333335;
  this->m_iCurTimeStep = 0;
  this->m_flTimeStepMul = 0.00055555563;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1041B2F0
// Name: _dynamic_initializer_for__phys_debug_check_contacts__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_debug_check_contacts__()
{
  ConVar::ConVar(this: &phys_debug_check_contacts, pName: "phys_debug_check_contacts", pDefaultValue: "0", flags: 24576);
  return atexit(func: dynamic_atexit_destructor_for__phys_debug_check_contacts__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CAB0
// Name: _dynamic_initializer_for__phys_pushscale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_pushscale__()
{
  ConVar::ConVar(this: &phys_pushscale, pName: "phys_pushscale", pDefaultValue: "1", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__phys_pushscale__);
}

//------------------------------------------------------------------------------
// Address: 0x10433300
// Name: _dynamic_atexit_destructor_for__phys_debug_check_contacts__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__phys_debug_check_contacts__()
{
  ConVar::~ConVar(this: &phys_debug_check_contacts);
}

//------------------------------------------------------------------------------
// Address: 0x10433C60
// Name: _dynamic_atexit_destructor_for__phys_pushscale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__phys_pushscale__()
{
  ConVar::~ConVar(this: &phys_pushscale);
}

//------------------------------------------------------------------------------
// Address: 0x1016AA40
// Name: struct datamap_t __near * DataMapInit<class CSimpleSimTimer>(class CSimpleSimTimer __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSimpleSimTimer>()
{
  if ( (_S5_115 & 1) == 0 )
  {
    _S5_115 |= 1u;
    nameHolder_19.m_pszBase = "CSimpleSimTimer";
    nameHolder_19.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_19.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_19.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_19.m_Names.m_Size = 0;
    nameHolder_19.m_Names.m_pElements = nullptr;
    nameHolder_19.m_nLenBase = 15;
    atexit(func: DataMapInit_CSimpleSimTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSimpleSimTimer::m_DataMap.baseMap = nullptr;
  CSimpleSimTimer::m_DataMap.dataNumFields = 1;
  CSimpleSimTimer::m_DataMap.dataDesc = &dataDesc_18[1];
  return &CSimpleSimTimer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016AAC0
// Name: struct datamap_t __near * DataMapInit<class CSimTimer>(class CSimTimer __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSimTimer>()
{
  if ( (_S6_38 & 1) == 0 )
  {
    _S6_38 |= 1u;
    nameHolder_20.m_pszBase = "CSimTimer";
    nameHolder_20.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_20.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_20.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_20.m_Names.m_Size = 0;
    nameHolder_20.m_Names.m_pElements = nullptr;
    nameHolder_20.m_nLenBase = 9;
    atexit(func: DataMapInit_CSimTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSimTimer::m_DataMap.baseMap = &CSimpleSimTimer::m_DataMap;
  CSimTimer::m_DataMap.dataNumFields = 1;
  CSimTimer::m_DataMap.dataDesc = &dataDesc_19[1];
  return &CSimTimer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016AB30
// Name: struct datamap_t __near * DataMapInit<class CRandSimTimer>(class CRandSimTimer __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CRandSimTimer>()
{
  if ( (_S7_13 & 1) == 0 )
  {
    _S7_13 |= 1u;
    nameHolder_21.m_pszBase = "CRandSimTimer";
    nameHolder_21.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_21.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_21.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_21.m_Names.m_Size = 0;
    nameHolder_21.m_Names.m_pElements = nullptr;
    nameHolder_21.m_nLenBase = 13;
    atexit(func: DataMapInit_CRandSimTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CRandSimTimer::m_DataMap.baseMap = &CSimpleSimTimer::m_DataMap;
  CRandSimTimer::m_DataMap.dataNumFields = 2;
  CRandSimTimer::m_DataMap.dataDesc = &dataDesc_20[1];
  return &CRandSimTimer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016ABB0
// Name: struct datamap_t __near * DataMapInit<class CStopwatchBase>(class CStopwatchBase __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CStopwatchBase>()
{
  if ( (_S8_8 & 1) == 0 )
  {
    _S8_8 |= 1u;
    nameHolder_22.m_pszBase = "CStopwatchBase";
    nameHolder_22.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_22.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_22.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_22.m_Names.m_Size = 0;
    nameHolder_22.m_Names.m_pElements = nullptr;
    nameHolder_22.m_nLenBase = 14;
    atexit(func: DataMapInit_CStopwatchBase__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CStopwatchBase::m_DataMap.baseMap = &CSimpleSimTimer::m_DataMap;
  CStopwatchBase::m_DataMap.dataNumFields = 1;
  CStopwatchBase::m_DataMap.dataDesc = &dataDesc_21[1];
  return &CStopwatchBase::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016AC20
// Name: struct datamap_t __near * DataMapInit<class CStopwatch>(class CStopwatch __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CStopwatch>()
{
  if ( (_S9_4 & 1) == 0 )
  {
    _S9_4 |= 1u;
    nameHolder_23.m_pszBase = "CStopwatch";
    nameHolder_23.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_23.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_23.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_23.m_Names.m_Size = 0;
    nameHolder_23.m_Names.m_pElements = nullptr;
    nameHolder_23.m_nLenBase = 10;
    atexit(func: DataMapInit_CStopwatch__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CStopwatch::m_DataMap.baseMap = &CStopwatchBase::m_DataMap;
  CStopwatch::m_DataMap.dataNumFields = 1;
  CStopwatch::m_DataMap.dataDesc = &dataDesc_22[1];
  return &CStopwatch::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016AC90
// Name: struct datamap_t __near * DataMapInit<class CRandStopwatch>(class CRandStopwatch __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CRandStopwatch>()
{
  if ( (_S10_1 & 1) == 0 )
  {
    _S10_1 |= 1u;
    nameHolder_24.m_pszBase = "CRandStopwatch";
    nameHolder_24.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_24.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_24.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_24.m_Names.m_Size = 0;
    nameHolder_24.m_Names.m_pElements = nullptr;
    nameHolder_24.m_nLenBase = 14;
    atexit(func: DataMapInit_CRandStopwatch__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CRandStopwatch::m_DataMap.baseMap = &CStopwatchBase::m_DataMap;
  CRandStopwatch::m_DataMap.dataNumFields = 2;
  CRandStopwatch::m_DataMap.dataDesc = &dataDesc_23[1];
  return &CRandStopwatch::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1041B320
// Name: _dynamic_initializer_for__cl_phys_block_fraction__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_phys_block_fraction__()
{
  ConVar::ConVar(this: &cl_phys_block_fraction, pName: "cl_phys_block_fraction", pDefaultValue: "0.1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_phys_block_fraction__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B350
// Name: _dynamic_initializer_for__cl_phys_block_dist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_phys_block_dist__()
{
  ConVar::ConVar(this: &cl_phys_block_dist, pName: "cl_phys_block_dist", pDefaultValue: "1.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_phys_block_dist__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B380
// Name: _dynamic_initializer_for__g_ShadowEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ShadowEntities__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ShadowEntities__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B390
// Name: _dynamic_initializer_for__g_Collisions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Collisions__()
{
  CCollisionEvent::CCollisionEvent(this: &g_Collisions);
  return atexit(func: dynamic_atexit_destructor_for__g_Collisions__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B3B0
// Name: _dynamic_initializer_for__cl_predictphysics__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_predictphysics__()
{
  ConVar::ConVar(
    this: &cl_predictphysics,
    pName: "cl_predictphysics",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Use a prediction-friendly physics interface on the client");
  return atexit(func: dynamic_atexit_destructor_for__cl_predictphysics__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B3E0
// Name: _dynamic_initializer_for__cl_ragdoll_collide__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_ragdoll_collide__()
{
  ConVar::ConVar(this: &cl_ragdoll_collide, pName: "cl_ragdoll_collide", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_ragdoll_collide__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B410
// Name: _dynamic_initializer_for__g_PhysicsSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PhysicsSystem__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &g_PhysicsSystem, name: "CPhysicsSystem");
  g_PhysicsSystem.__vftable = (CPhysicsSystem_vtbl *)&CPhysicsSystem::`vftable';
  g_PhysicsSystem.m_impactSounds.elements.m_Memory.m_pMemory = nullptr;
  g_PhysicsSystem.m_impactSounds.elements.m_Memory.m_nAllocationCount = 0;
  g_PhysicsSystem.m_impactSounds.elements.m_Memory.m_nGrowSize = 0;
  g_PhysicsSystem.m_impactSounds.elements.m_Size = 0;
  g_PhysicsSystem.m_impactSounds.elements.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_PhysicsSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B450
// Name: _dynamic_initializer_for__g_mp_PhysicsSimulate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_mp_PhysicsSimulate__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_mp_PhysicsSimulate__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B460
// Name: _dynamic_initializer_for__g_mp_active_object_count__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_mp_active_object_count__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_mp_active_object_count__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B470
// Name: _dynamic_initializer_for__cl_phys_show_active__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_phys_show_active__()
{
  ConVar::ConVar(this: &cl_phys_show_active, pName: "cl_phys_show_active", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_phys_show_active__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B4A0
// Name: _dynamic_initializer_for__g_EdictTouchLinks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EdictTouchLinks__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_EdictTouchLinks,
    blockSize: 0x14u,
    numElements: 2048,
    growMode: 0,
    pszAllocOwner: "g_EdictTouchLinks",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_EdictTouchLinks__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B4D0
// Name: _dynamic_initializer_for__g_EntityGroundLinks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EntityGroundLinks__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_EntityGroundLinks,
    blockSize: 0xCu,
    numElements: 2048,
    growMode: 0,
    pszAllocOwner: "g_EntityGroundLinks",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_EntityGroundLinks__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B500
// Name: _dynamic_initializer_for__g_WatcherList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_WatcherList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_WatcherList__);
}

//------------------------------------------------------------------------------
// Address: 0x10433310
// Name: _dynamic_atexit_destructor_for__cl_phys_block_fraction__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_phys_block_fraction__()
{
  ConVar::~ConVar(this: &cl_phys_block_fraction);
}

//------------------------------------------------------------------------------
// Address: 0x10433320
// Name: _dynamic_atexit_destructor_for__cl_phys_block_dist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_phys_block_dist__()
{
  ConVar::~ConVar(this: &cl_phys_block_dist);
}

//------------------------------------------------------------------------------
// Address: 0x10433330
// Name: _dynamic_atexit_destructor_for__cl_predictphysics__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_predictphysics__()
{
  ConVar::~ConVar(this: &cl_predictphysics);
}

//------------------------------------------------------------------------------
// Address: 0x10433340
// Name: _dynamic_atexit_destructor_for__cl_ragdoll_collide__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_ragdoll_collide__()
{
  ConVar::~ConVar(this: &cl_ragdoll_collide);
}

//------------------------------------------------------------------------------
// Address: 0x10433350
// Name: _dynamic_atexit_destructor_for__g_mp_PhysicsSimulate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_mp_PhysicsSimulate__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10433360
// Name: _dynamic_atexit_destructor_for__g_mp_active_object_count__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_mp_active_object_count__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10433370
// Name: _dynamic_atexit_destructor_for__cl_phys_show_active__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_phys_show_active__()
{
  ConVar::~ConVar(this: &cl_phys_show_active);
}

//------------------------------------------------------------------------------
// Address: 0x10433380
// Name: _dynamic_atexit_destructor_for__g_ShadowEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ShadowEntities__()
{
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *)&g_ShadowEntities);
  if ( g_ShadowEntities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ShadowEntities.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ShadowEntities.m_Memory.m_pMemory);
      g_ShadowEntities.m_Memory.m_pMemory = nullptr;
    }
    g_ShadowEntities.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104333D0
// Name: _dynamic_atexit_destructor_for__g_PhysicsSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PhysicsSystem__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_PhysicsSystem.m_impactSounds);
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_PhysicsSystem);
}

//------------------------------------------------------------------------------
// Address: 0x104333F0
// Name: _dynamic_atexit_destructor_for__g_Collisions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Collisions__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Collisions.m_penetrateEvents);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Collisions.m_touchEvents);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Collisions.m_fluidEvents);
}

//------------------------------------------------------------------------------
// Address: 0x10433410
// Name: _dynamic_atexit_destructor_for__g_EdictTouchLinks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EdictTouchLinks__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_EdictTouchLinks);
}

//------------------------------------------------------------------------------
// Address: 0x10433420
// Name: _dynamic_atexit_destructor_for__g_EntityGroundLinks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EntityGroundLinks__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_EntityGroundLinks);
}

//------------------------------------------------------------------------------
// Address: 0x10433C70
// Name: _DataMapInit_CTakeDamageInfo__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTakeDamageInfo__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_31);
}

//------------------------------------------------------------------------------
// Address: 0x10433C80
// Name: _DataMapInit_CMultiDamage__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CMultiDamage__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_32);
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102135C0
// Name: public: void CSimplePhysics::Init(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimplePhysics::Init(CSimplePhysics *this, float flTimeStep)
{
  this->m_flPredictedTime = 0.0;
  this->m_flTimeStep = flTimeStep;
  this->m_iCurTimeStep = 0;
  this->m_flTimeStepMul = (float)(flTimeStep * flTimeStep) * 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x102135F0
// Name: public: void CSimplePhysics::Simulate(class CSimplePhysics::CNode __near *,int,class CSimplePhysics::IHelper __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimplePhysics::Simulate(
        CSimplePhysics *this,
        CSimplePhysics::CNode *pNodes,
        int nNodes,
        CSimplePhysics::IHelper *pHelper,
        float dt,
        float flDamp)
{
  CSimplePhysics *v6; // esi
  float m_flTimeStep; // xmm1_4
  long double v8; // xmm0_8
  int v9; // eax
  int v10; // ecx
  int v11; // edi
  float *p_z; // esi
  CSimplePhysics *v13; // edx
  float v14; // xmm4_4
  float v15; // xmm5_4
  float m_flTimeStepMul; // xmm0_4
  float v17; // xmm6_4
  float v18; // xmm3_4
  float x; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  double m_flPredictedTime; // xmm2_8
  int v23; // esi
  float v24; // xmm0_4
  float *p_y; // eax
  unsigned int v26; // ecx
  float *v27; // eax
  int v28; // edx
  float v29; // [esp+10h] [ebp-28h]
  float v30; // [esp+14h] [ebp-24h]
  Vector vAccel; // [esp+18h] [ebp-20h] BYREF
  Vector vPrevPos; // [esp+24h] [ebp-14h]
  int newTimeStep; // [esp+30h] [ebp-8h]
  CSimplePhysics *v34; // [esp+34h] [ebp-4h]
  int dta; // [esp+4Ch] [ebp+14h]

  v6 = this;
  m_flTimeStep = this->m_flTimeStep;
  v8 = dt + this->m_flPredictedTime;
  this->m_flPredictedTime = v8;
  v34 = this;
  v9 = (int)ceil(X: v8 / m_flTimeStep);
  v10 = v9 - v6->m_iCurTimeStep;
  newTimeStep = v9;
  if ( v10 > 0 )
  {
    for ( dta = v10; dta != 0; --dta )
    {
      v11 = 0;
      if ( nNodes > 0 )
      {
        p_z = &pNodes->m_vPrevPos.z;
        do
        {
          pHelper->GetNodeForces(this: pHelper, a2: pNodes, a3: v11, a4: &vAccel);
          v13 = v34;
          v14 = *(p_z - 4);
          v15 = *(p_z - 3);
          *(_QWORD *)&vPrevPos.x = *(_QWORD *)(p_z - 5);
          m_flTimeStepMul = v34->m_flTimeStepMul;
          v29 = vAccel.y * m_flTimeStepMul;
          v17 = vAccel.x * m_flTimeStepMul;
          v30 = vAccel.z * m_flTimeStepMul;
          v18 = vPrevPos.x + (float)((float)(vPrevPos.x - *(p_z - 2)) * flDamp);
          x = vPrevPos.x;
          v20 = (float)(v15 - *p_z) * flDamp;
          *(p_z - 4) = (float)(v14 + (float)((float)(v14 - *(p_z - 1)) * flDamp)) + v29;
          *(p_z - 3) = (float)(v15 + v20) + v30;
          *(p_z - 5) = v18 + v17;
          *(p_z - 2) = x;
          *(p_z - 1) = vPrevPos.y;
          vPrevPos.z = v15;
          *p_z = v15;
          ++v11;
          p_z += 9;
        }
        while ( v11 < nNodes );
        v6 = v13;
      }
      pHelper->ApplyConstraints(this: pHelper, a2: pNodes, a3: nNodes);
    }
    v9 = newTimeStep;
  }
  v21 = v6->m_flTimeStep;
  m_flPredictedTime = v6->m_flPredictedTime;
  v6->m_iCurTimeStep = v9;
  v23 = 0;
  v24 = (m_flPredictedTime - (float)((float)((float)v9 * v21) - v21)) / v21;
  if ( nNodes >= 4 )
  {
    p_y = &pNodes[1].m_vPrevPos.y;
    v26 = ((unsigned int)(nNodes - 4) >> 2) + 1;
    v23 = 4 * v26;
    do
    {
      *(p_y - 7) = (float)((float)(*(p_y - 13) - *(p_y - 10)) * v24) + *(p_y - 10);
      *(p_y - 6) = (float)((float)(*(p_y - 12) - *(p_y - 9)) * v24) + *(p_y - 9);
      *(p_y - 5) = (float)((float)(*(p_y - 11) - *(p_y - 8)) * v24) + *(p_y - 8);
      p_y[2] = (float)((float)(*(p_y - 4) - *(p_y - 1)) * v24) + *(p_y - 1);
      p_y[3] = (float)((float)(*(p_y - 3) - *p_y) * v24) + *p_y;
      p_y[4] = (float)((float)(*(p_y - 2) - p_y[1]) * v24) + p_y[1];
      p_y[11] = (float)((float)(p_y[5] - p_y[8]) * v24) + p_y[8];
      p_y[12] = (float)((float)(p_y[6] - p_y[9]) * v24) + p_y[9];
      p_y[13] = (float)((float)(p_y[7] - p_y[10]) * v24) + p_y[10];
      p_y[20] = (float)((float)(p_y[14] - p_y[17]) * v24) + p_y[17];
      p_y[21] = (float)((float)(p_y[15] - p_y[18]) * v24) + p_y[18];
      p_y[22] = (float)((float)(p_y[16] - p_y[19]) * v24) + p_y[19];
      p_y += 36;
      --v26;
    }
    while ( v26 != 0 );
  }
  if ( v23 < nNodes )
  {
    v27 = &pNodes[v23].m_vPrevPos.y;
    v28 = nNodes - v23;
    do
    {
      v27[2] = (float)((float)(*(v27 - 4) - *(v27 - 1)) * v24) + *(v27 - 1);
      v27[3] = (float)((float)(*(v27 - 3) - *v27) * v24) + *v27;
      v27[4] = (float)((float)(*(v27 - 2) - v27[1]) * v24) + v27[1];
      v27 += 9;
      --v28;
    }
    while ( v28 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10213940
// Name: public: CSimplePhysics::CSimplePhysics(void)
// Source: json
//------------------------------------------------------------------------------
CSimplePhysics *__thiscall CSimplePhysics::CSimplePhysics(CSimplePhysics *this)
{
  this->m_flPredictedTime = 0.0;
  this->m_flTimeStep = 0.033333335;
  this->m_iCurTimeStep = 0;
  this->m_flTimeStepMul = 0.00055555563;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104079E0
// Name: _dynamic_initializer_for__simple_physics_brush__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__simple_physics_brush__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSimplePhysicsBrush> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &simple_physics_brush,
           a3: "simple_physics_brush");
}

//------------------------------------------------------------------------------
// Address: 0x10407A00
// Name: _dynamic_initializer_for__simple_physics_prop__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__simple_physics_prop__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSimplePhysicsProp> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &simple_physics_prop,
           a3: "simple_physics_prop");
}

//------------------------------------------------------------------------------
// Address: 0x10213970
// Name: struct datamap_t __near * DataMapInit<class CSimpleSimTimer>(class CSimpleSimTimer __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSimpleSimTimer>()
{
  if ( (_S2_200 & 1) == 0 )
  {
    _S2_200 |= 1u;
    nameHolder_378.m_pszBase = "CSimpleSimTimer";
    nameHolder_378.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_378.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_378.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_378.m_Names.m_Size = 0;
    nameHolder_378.m_Names.m_pElements = nullptr;
    nameHolder_378.m_nLenBase = 15;
    atexit(func: DataMapInit_CSimpleSimTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSimpleSimTimer::m_DataMap.baseMap = nullptr;
  CSimpleSimTimer::m_DataMap.dataNumFields = 1;
  CSimpleSimTimer::m_DataMap.dataDesc = &dataDesc_361[1];
  return &CSimpleSimTimer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102139F0
// Name: struct datamap_t __near * DataMapInit<class CSimTimer>(class CSimTimer __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSimTimer>()
{
  if ( (_S3_113 & 1) == 0 )
  {
    _S3_113 |= 1u;
    nameHolder_379.m_pszBase = "CSimTimer";
    nameHolder_379.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_379.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_379.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_379.m_Names.m_Size = 0;
    nameHolder_379.m_Names.m_pElements = nullptr;
    nameHolder_379.m_nLenBase = 9;
    atexit(func: DataMapInit_CSimTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSimTimer::m_DataMap.baseMap = &CSimpleSimTimer::m_DataMap;
  CSimTimer::m_DataMap.dataNumFields = 1;
  CSimTimer::m_DataMap.dataDesc = &dataDesc_362[1];
  return &CSimTimer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10213A60
// Name: struct datamap_t __near * DataMapInit<class CRandSimTimer>(class CRandSimTimer __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CRandSimTimer>()
{
  if ( (_S4_53 & 1) == 0 )
  {
    _S4_53 |= 1u;
    nameHolder_380.m_pszBase = "CRandSimTimer";
    nameHolder_380.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_380.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_380.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_380.m_Names.m_Size = 0;
    nameHolder_380.m_Names.m_pElements = nullptr;
    nameHolder_380.m_nLenBase = 13;
    atexit(func: DataMapInit_CRandSimTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CRandSimTimer::m_DataMap.baseMap = &CSimpleSimTimer::m_DataMap;
  CRandSimTimer::m_DataMap.dataNumFields = 2;
  CRandSimTimer::m_DataMap.dataDesc = &dataDesc_363[1];
  return &CRandSimTimer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10213AE0
// Name: struct datamap_t __near * DataMapInit<class CStopwatchBase>(class CStopwatchBase __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CStopwatchBase>()
{
  if ( (_S5_29 & 1) == 0 )
  {
    _S5_29 |= 1u;
    nameHolder_381.m_pszBase = "CStopwatchBase";
    nameHolder_381.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_381.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_381.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_381.m_Names.m_Size = 0;
    nameHolder_381.m_Names.m_pElements = nullptr;
    nameHolder_381.m_nLenBase = 14;
    atexit(func: DataMapInit_CStopwatchBase__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CStopwatchBase::m_DataMap.baseMap = &CSimpleSimTimer::m_DataMap;
  CStopwatchBase::m_DataMap.dataNumFields = 1;
  CStopwatchBase::m_DataMap.dataDesc = &dataDesc_364[1];
  return &CStopwatchBase::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10213B50
// Name: struct datamap_t __near * DataMapInit<class CStopwatch>(class CStopwatch __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CStopwatch>()
{
  if ( (_S6_23 & 1) == 0 )
  {
    _S6_23 |= 1u;
    nameHolder_382.m_pszBase = "CStopwatch";
    nameHolder_382.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_382.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_382.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_382.m_Names.m_Size = 0;
    nameHolder_382.m_Names.m_pElements = nullptr;
    nameHolder_382.m_nLenBase = 10;
    atexit(func: DataMapInit_CStopwatch__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CStopwatch::m_DataMap.baseMap = &CStopwatchBase::m_DataMap;
  CStopwatch::m_DataMap.dataNumFields = 1;
  CStopwatch::m_DataMap.dataDesc = &dataDesc_365[1];
  return &CStopwatch::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10213BC0
// Name: struct datamap_t __near * DataMapInit<class CRandStopwatch>(class CRandStopwatch __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CRandStopwatch>()
{
  if ( (_S7_15 & 1) == 0 )
  {
    _S7_15 |= 1u;
    nameHolder_383.m_pszBase = "CRandStopwatch";
    nameHolder_383.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_383.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_383.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_383.m_Names.m_Size = 0;
    nameHolder_383.m_Names.m_pElements = nullptr;
    nameHolder_383.m_nLenBase = 14;
    atexit(func: DataMapInit_CRandStopwatch__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CRandStopwatch::m_DataMap.baseMap = &CStopwatchBase::m_DataMap;
  CRandStopwatch::m_DataMap.dataNumFields = 2;
  CRandStopwatch::m_DataMap.dataDesc = &dataDesc_366[1];
  return &CRandStopwatch::m_DataMap;
}

} // namespace server
