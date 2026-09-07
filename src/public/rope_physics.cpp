// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/rope_physics.cpp
// Functions: 7
// ============================================================

#include "public\rope_physics.h"

//------------------------------------------------------------------------------
// Address: 0x1009EC30
// Name: public: void CBaseRopePhysics::SetNumNodes(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseRopePhysics::SetNumNodes(CBaseRopePhysics *this, int nNodes)
{
  int v2; // eax
  int v3; // edx

  this->m_nNodes = nNodes;
  v2 = 0;
  if ( nNodes - 1 > 0 )
  {
    v3 = 0;
    do
    {
      this->m_pSprings[v2].m_pNode1 = &this->m_pNodes[v3].m_vPos;
      this->m_pSprings[v2].m_pNode2 = &this->m_pNodes[v3 + 1].m_vPos;
      this->m_flNodeSpringDistsSqr[v2++] = this->m_flSpringDistSqr / (float)(this->m_nNodes - 1);
      ++v3;
    }
    while ( v2 < this->m_nNodes - 1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009EC90
// Name: public: void CBaseRopePhysics::Restart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseRopePhysics::Restart(CBaseRopePhysics *this)
{
  CSimplePhysics::Init(this: &this->m_Physics, flTimeStep: 0.02);
}

//------------------------------------------------------------------------------
// Address: 0x1009ECB0
// Name: public: void CBaseRopePhysics::Simulate(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseRopePhysics::Simulate(CBaseRopePhysics *this, float dt)
{
  CSimplePhysics::Simulate(
    this: &this->m_Physics,
    pNodes: this->m_pNodes,
    nNodes: this->m_nNodes,
    pHelper: this,
    dt,
    flDamp: flEnergy);
}

//------------------------------------------------------------------------------
// Address: 0x1009ECF0
// Name: public: virtual void CBaseRopePhysics::GetNodeForces(class CSimplePhysics::CNode __near *,int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseRopePhysics::GetNodeForces(
        CBaseRopePhysics *this,
        CSimplePhysics::CNode *pNodes,
        int iNode,
        Vector *pAccel)
{
  if ( this->m_pDelegate != nullptr )
  {
    this->m_pDelegate->GetNodeForces(this: this->m_pDelegate, a2: pNodes, a3: iNode, a4: pAccel);
  }
  else
  {
    pAccel->x = 0.0;
    pAccel->y = 0.0;
    pAccel->z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009ED20
// Name: public: virtual void CBaseRopePhysics::ApplyConstraints(class CSimplePhysics::CNode __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseRopePhysics::ApplyConstraints(CBaseRopePhysics *this, CSimplePhysics::CNode *pNodes, int nNodes)
{
  int i; // ebx
  int j; // edi
  CRopeSpring *m_pSprings; // ecx
  float *p_x; // edx
  float *v8; // ecx
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float m_flSpringDistSqr; // xmm5_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4

  for ( i = 0; i < nIterations; ++i )
  {
    for ( j = 0; j < this->m_nNodes - 1; ++j )
    {
      m_pSprings = this->m_pSprings;
      p_x = &m_pSprings[j].m_pNode1->x;
      v8 = &m_pSprings[j].m_pNode2->x;
      v9 = *p_x - *v8;
      v10 = p_x[1] - v8[1];
      v11 = p_x[2] - v8[2];
      v12 = (float)((float)(v10 * v10) + (float)(v9 * v9)) + (float)(v11 * v11);
      m_flSpringDistSqr = this->m_flSpringDistSqr;
      if ( m_flSpringDistSqr == 0.0 )
        m_flSpringDistSqr = this->m_flNodeSpringDistsSqr[j];
      if ( v12 > m_flSpringDistSqr )
      {
        v14 = this->m_flSpringDist / fsqrt(v12);
        v15 = (float)(v9 * (float)(1.0 - v14)) * 0.5;
        *p_x = *p_x - v15;
        v16 = (float)(v10 * (float)(1.0 - v14)) * 0.5;
        p_x[1] = p_x[1] - v16;
        v17 = (float)(v11 * (float)(1.0 - v14)) * 0.5;
        p_x[2] = p_x[2] - v17;
        *v8 = *v8 + v15;
        v8[1] = v8[1] + v16;
        v8[2] = v8[2] + v17;
      }
    }
    if ( this->m_pDelegate != nullptr )
      this->m_pDelegate->ApplyConstraints(this: this->m_pDelegate, a2: pNodes, a3: nNodes);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009EE90
// Name: public: CBaseRopePhysics::CBaseRopePhysics(class CSimplePhysics::CNode __near *,int,class CRopeSpring __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseRopePhysics *__thiscall CBaseRopePhysics::CBaseRopePhysics(
        CBaseRopePhysics *this,
        CSimplePhysics::CNode *pNodes,
        CSimplePhysics::CNode *nNodes,
        CRopeSpring *pSprings,
        float *flSpringDistsSqr)
{
  float *p_z; // eax
  CSimplePhysics::CNode *i; // edx
  int v8; // eax
  int v9; // ecx

  this->__vftable = (CBaseRopePhysics_vtbl *)&CBaseRopePhysics::`vftable';
  CSimplePhysics::CSimplePhysics(this: &this->m_Physics);
  this->m_flNodeSpringDistsSqr = flSpringDistsSqr;
  this->m_flSpringDistSqr = 1.0;
  this->m_flSpringDist = 1.0;
  this->m_pNodes = pNodes;
  this->m_pSprings = pSprings;
  CSimplePhysics::Init(this: &this->m_Physics, flTimeStep: 0.02);
  if ( (int)nNodes > 0 )
  {
    p_z = &pNodes->m_vPrevPos.z;
    for ( i = nNodes; i != nullptr; i = (CSimplePhysics::CNode *)((char *)i - 1) )
    {
      *(p_z - 5) = 0.0;
      *(p_z - 4) = 0.0;
      *(p_z - 3) = 0.0;
      *(p_z - 2) = 0.0;
      *(p_z - 1) = 0.0;
      *p_z = 0.0;
      p_z[1] = 0.0;
      p_z[2] = 0.0;
      p_z[3] = 0.0;
      p_z += 9;
    }
  }
  this->m_nNodes = (int)nNodes;
  v8 = 0;
  if ( (int)&nNodes[-1].m_vPredicted.z + 3 > 0 )
  {
    v9 = 0;
    do
    {
      this->m_pSprings[v8].m_pNode1 = &this->m_pNodes[v9].m_vPos;
      this->m_pSprings[v8].m_pNode2 = &this->m_pNodes[v9 + 1].m_vPos;
      this->m_flNodeSpringDistsSqr[v8++] = this->m_flSpringDistSqr / (float)(this->m_nNodes - 1);
      ++v9;
    }
    while ( v8 < this->m_nNodes - 1 );
  }
  this->m_pDelegate = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009EF80
// Name: public: void CBaseRopePhysics::SetupSimulation(float,class CSimplePhysics::IHelper __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseRopePhysics::SetupSimulation(
        CBaseRopePhysics *this,
        float flSpringDist,
        CSimplePhysics::IHelper *pDelegate)
{
  float v3; // xmm0_4
  int v4; // edx
  int v5; // eax

  v3 = flSpringDist;
  if ( flSpringDist <= 0.0 )
    v3 = 0.0;
  v4 = this->m_nNodes - 1;
  this->m_flSpringDist = v3;
  v5 = 0;
  this->m_flSpringDistSqr = v3 * v3;
  if ( v4 <= 0 )
  {
    this->m_pDelegate = pDelegate;
  }
  else
  {
    do
      this->m_flNodeSpringDistsSqr[v5++] = this->m_flSpringDistSqr / (float)(this->m_nNodes - 1);
    while ( v5 < this->m_nNodes - 1 );
    this->m_pDelegate = pDelegate;
  }
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10163F90
// Name: public: void CBaseRopePhysics::SetNumNodes(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseRopePhysics::SetNumNodes(CBaseRopePhysics *this, int nNodes)
{
  int v2; // eax
  int v3; // edx

  this->m_nNodes = nNodes;
  v2 = 0;
  if ( nNodes - 1 > 0 )
  {
    v3 = 0;
    do
    {
      this->m_pSprings[v2].m_pNode1 = &this->m_pNodes[v3].m_vPos;
      this->m_pSprings[v2].m_pNode2 = &this->m_pNodes[v3 + 1].m_vPos;
      this->m_flNodeSpringDistsSqr[v2++] = this->m_flSpringDistSqr / (float)(this->m_nNodes - 1);
      ++v3;
    }
    while ( v2 < this->m_nNodes - 1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163FF0
// Name: public: void CBaseRopePhysics::Restart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseRopePhysics::Restart(CBaseRopePhysics *this)
{
  CSimplePhysics::Init(this: &this->m_Physics, flTimeStep: 0.02);
}

//------------------------------------------------------------------------------
// Address: 0x10164010
// Name: public: void CBaseRopePhysics::ResetSpringLength(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseRopePhysics::ResetSpringLength(CBaseRopePhysics *this, float flSpringDist)
{
  float v2; // xmm0_4
  int v3; // edx
  int v4; // eax

  v2 = flSpringDist;
  if ( flSpringDist <= 0.0 )
    v2 = 0.0;
  v3 = this->m_nNodes - 1;
  this->m_flSpringDist = v2;
  v4 = 0;
  this->m_flSpringDistSqr = v2 * v2;
  if ( v3 > 0 )
  {
    do
      this->m_flNodeSpringDistsSqr[v4++] = this->m_flSpringDistSqr / (float)(this->m_nNodes - 1);
    while ( v4 < this->m_nNodes - 1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164070
// Name: public: void CBaseRopePhysics::Simulate(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseRopePhysics::Simulate(CBaseRopePhysics *this, float dt)
{
  CSimplePhysics::Simulate(
    this: &this->m_Physics,
    pNodes: this->m_pNodes,
    nNodes: this->m_nNodes,
    pHelper: this,
    dt,
    flDamp: flEnergy);
}

//------------------------------------------------------------------------------
// Address: 0x101640B0
// Name: public: virtual void CBaseRopePhysics::GetNodeForces(class CSimplePhysics::CNode __near *,int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseRopePhysics::GetNodeForces(
        CBaseRopePhysics *this,
        CSimplePhysics::CNode *pNodes,
        int iNode,
        Vector *pAccel)
{
  if ( this->m_pDelegate != nullptr )
  {
    this->m_pDelegate->GetNodeForces(this: this->m_pDelegate, a2: pNodes, a3: iNode, a4: pAccel);
  }
  else
  {
    pAccel->x = 0.0;
    pAccel->y = 0.0;
    pAccel->z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101640E0
// Name: public: virtual void CBaseRopePhysics::ApplyConstraints(class CSimplePhysics::CNode __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseRopePhysics::ApplyConstraints(CBaseRopePhysics *this, CSimplePhysics::CNode *pNodes, int nNodes)
{
  int i; // ebx
  int j; // edi
  CRopeSpring *m_pSprings; // ecx
  float *p_x; // edx
  float *v8; // ecx
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float m_flSpringDistSqr; // xmm5_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4

  for ( i = 0; i < nIterations_0; ++i )
  {
    for ( j = 0; j < this->m_nNodes - 1; ++j )
    {
      m_pSprings = this->m_pSprings;
      p_x = &m_pSprings[j].m_pNode1->x;
      v8 = &m_pSprings[j].m_pNode2->x;
      v9 = *p_x - *v8;
      v10 = p_x[1] - v8[1];
      v11 = p_x[2] - v8[2];
      v12 = (float)((float)(v10 * v10) + (float)(v9 * v9)) + (float)(v11 * v11);
      m_flSpringDistSqr = this->m_flSpringDistSqr;
      if ( m_flSpringDistSqr == 0.0 )
        m_flSpringDistSqr = this->m_flNodeSpringDistsSqr[j];
      if ( v12 > m_flSpringDistSqr )
      {
        v14 = this->m_flSpringDist / fsqrt(v12);
        v15 = (float)(v9 * (float)(1.0 - v14)) * 0.5;
        *p_x = *p_x - v15;
        v16 = (float)(v10 * (float)(1.0 - v14)) * 0.5;
        p_x[1] = p_x[1] - v16;
        v17 = (float)(v11 * (float)(1.0 - v14)) * 0.5;
        p_x[2] = p_x[2] - v17;
        *v8 = *v8 + v15;
        v8[1] = v8[1] + v16;
        v8[2] = v8[2] + v17;
      }
    }
    if ( this->m_pDelegate != nullptr )
      this->m_pDelegate->ApplyConstraints(this: this->m_pDelegate, a2: pNodes, a3: nNodes);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164250
// Name: public: CBaseRopePhysics::CBaseRopePhysics(class CSimplePhysics::CNode __near *,int,class CRopeSpring __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseRopePhysics *__thiscall CBaseRopePhysics::CBaseRopePhysics(
        CBaseRopePhysics *this,
        CSimplePhysics::CNode *pNodes,
        int nNodes,
        CRopeSpring *pSprings,
        float *flSpringDistsSqr)
{
  float *p_z; // eax
  int i; // edx
  int v8; // eax
  int v9; // ecx

  this->__vftable = (CBaseRopePhysics_vtbl *)&CBaseRopePhysics::`vftable';
  CSimplePhysics::CSimplePhysics(this: &this->m_Physics);
  this->m_flNodeSpringDistsSqr = flSpringDistsSqr;
  this->m_flSpringDistSqr = 1.0;
  this->m_flSpringDist = 1.0;
  this->m_pNodes = pNodes;
  this->m_pSprings = pSprings;
  CSimplePhysics::Init(this: &this->m_Physics, flTimeStep: 0.02);
  if ( nNodes > 0 )
  {
    p_z = &pNodes->m_vPrevPos.z;
    for ( i = nNodes; i != 0; --i )
    {
      *(p_z - 5) = 0.0;
      *(p_z - 4) = 0.0;
      *(p_z - 3) = 0.0;
      *(p_z - 2) = 0.0;
      *(p_z - 1) = 0.0;
      *p_z = 0.0;
      p_z[1] = 0.0;
      p_z[2] = 0.0;
      p_z[3] = 0.0;
      p_z += 9;
    }
  }
  this->m_nNodes = nNodes;
  v8 = 0;
  if ( nNodes - 1 > 0 )
  {
    v9 = 0;
    do
    {
      this->m_pSprings[v8].m_pNode1 = &this->m_pNodes[v9].m_vPos;
      this->m_pSprings[v8].m_pNode2 = &this->m_pNodes[v9 + 1].m_vPos;
      this->m_flNodeSpringDistsSqr[v8++] = this->m_flSpringDistSqr / (float)(this->m_nNodes - 1);
      ++v9;
    }
    while ( v8 < this->m_nNodes - 1 );
  }
  this->m_pDelegate = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10164340
// Name: public: void CBaseRopePhysics::SetupSimulation(float,class CSimplePhysics::IHelper __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseRopePhysics::SetupSimulation(
        CBaseRopePhysics *this,
        float flSpringDist,
        CSimplePhysics::IHelper *pDelegate)
{
  float v3; // xmm0_4
  int v4; // edx
  int v5; // eax

  v3 = flSpringDist;
  if ( flSpringDist <= 0.0 )
    v3 = 0.0;
  v4 = this->m_nNodes - 1;
  this->m_flSpringDist = v3;
  v5 = 0;
  this->m_flSpringDistSqr = v3 * v3;
  if ( v4 <= 0 )
  {
    this->m_pDelegate = pDelegate;
  }
  else
  {
    do
      this->m_flNodeSpringDistsSqr[v5++] = this->m_flSpringDistSqr / (float)(this->m_nNodes - 1);
    while ( v5 < this->m_nNodes - 1 );
    this->m_pDelegate = pDelegate;
  }
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x101F7770
// Name: public: void CBaseRopePhysics::SetNumNodes(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseRopePhysics::SetNumNodes(CBaseRopePhysics *this, int nNodes)
{
  int v2; // eax
  int v3; // edx

  this->m_nNodes = nNodes;
  v2 = 0;
  if ( nNodes - 1 > 0 )
  {
    v3 = 0;
    do
    {
      this->m_pSprings[v2].m_pNode1 = &this->m_pNodes[v3].m_vPos;
      this->m_pSprings[v2].m_pNode2 = &this->m_pNodes[v3 + 1].m_vPos;
      this->m_flNodeSpringDistsSqr[v2++] = this->m_flSpringDistSqr / (float)(this->m_nNodes - 1);
      ++v3;
    }
    while ( v2 < this->m_nNodes - 1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F77D0
// Name: public: void CBaseRopePhysics::Restart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseRopePhysics::Restart(CBaseRopePhysics *this)
{
  CSimplePhysics::Init(this: &this->m_Physics, flTimeStep: 0.02);
}

//------------------------------------------------------------------------------
// Address: 0x101F77F0
// Name: public: void CBaseRopePhysics::Simulate(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseRopePhysics::Simulate(CBaseRopePhysics *this, float dt)
{
  CSimplePhysics::Simulate(
    this: &this->m_Physics,
    pNodes: this->m_pNodes,
    nNodes: this->m_nNodes,
    pHelper: this,
    dt,
    flDamp: flEnergy);
}

//------------------------------------------------------------------------------
// Address: 0x101F7830
// Name: public: virtual void CBaseRopePhysics::GetNodeForces(class CSimplePhysics::CNode __near *,int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseRopePhysics::GetNodeForces(
        CBaseRopePhysics *this,
        CSimplePhysics::CNode *pNodes,
        int iNode,
        Vector *pAccel)
{
  if ( this->m_pDelegate != nullptr )
  {
    this->m_pDelegate->GetNodeForces(this: this->m_pDelegate, a2: pNodes, a3: iNode, a4: pAccel);
  }
  else
  {
    pAccel->x = 0.0;
    pAccel->y = 0.0;
    pAccel->z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F7860
// Name: public: virtual void CBaseRopePhysics::ApplyConstraints(class CSimplePhysics::CNode __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseRopePhysics::ApplyConstraints(CBaseRopePhysics *this, CSimplePhysics::CNode *pNodes, int nNodes)
{
  int i; // ebx
  int j; // edi
  CRopeSpring *m_pSprings; // ecx
  float *p_x; // edx
  float *v8; // ecx
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float m_flSpringDistSqr; // xmm5_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4

  for ( i = 0; i < nIterations; ++i )
  {
    for ( j = 0; j < this->m_nNodes - 1; ++j )
    {
      m_pSprings = this->m_pSprings;
      p_x = &m_pSprings[j].m_pNode1->x;
      v8 = &m_pSprings[j].m_pNode2->x;
      v9 = *p_x - *v8;
      v10 = p_x[1] - v8[1];
      v11 = p_x[2] - v8[2];
      v12 = (float)((float)(v10 * v10) + (float)(v9 * v9)) + (float)(v11 * v11);
      m_flSpringDistSqr = this->m_flSpringDistSqr;
      if ( m_flSpringDistSqr == 0.0 )
        m_flSpringDistSqr = this->m_flNodeSpringDistsSqr[j];
      if ( v12 > m_flSpringDistSqr )
      {
        v14 = this->m_flSpringDist / fsqrt(v12);
        v15 = (float)(v9 * (float)(1.0 - v14)) * 0.5;
        *p_x = *p_x - v15;
        v16 = (float)(v10 * (float)(1.0 - v14)) * 0.5;
        p_x[1] = p_x[1] - v16;
        v17 = (float)(v11 * (float)(1.0 - v14)) * 0.5;
        p_x[2] = p_x[2] - v17;
        *v8 = *v8 + v15;
        v8[1] = v8[1] + v16;
        v8[2] = v8[2] + v17;
      }
    }
    if ( this->m_pDelegate != nullptr )
      this->m_pDelegate->ApplyConstraints(this: this->m_pDelegate, a2: pNodes, a3: nNodes);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F79D0
// Name: public: CBaseRopePhysics::CBaseRopePhysics(class CSimplePhysics::CNode __near *,int,class CRopeSpring __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseRopePhysics *__thiscall CBaseRopePhysics::CBaseRopePhysics(
        CBaseRopePhysics *this,
        CSimplePhysics::CNode *pNodes,
        int nNodes,
        CRopeSpring *pSprings,
        float *flSpringDistsSqr)
{
  float *p_z; // eax
  int i; // edx
  int v8; // eax
  int v9; // ecx

  this->__vftable = (CBaseRopePhysics_vtbl *)&CBaseRopePhysics::`vftable';
  CSimplePhysics::CSimplePhysics(this: &this->m_Physics);
  this->m_flNodeSpringDistsSqr = flSpringDistsSqr;
  this->m_flSpringDistSqr = 1.0;
  this->m_flSpringDist = 1.0;
  this->m_pNodes = pNodes;
  this->m_pSprings = pSprings;
  CSimplePhysics::Init(this: &this->m_Physics, flTimeStep: 0.02);
  if ( nNodes > 0 )
  {
    p_z = &pNodes->m_vPrevPos.z;
    for ( i = nNodes; i != 0; --i )
    {
      *(p_z - 5) = 0.0;
      *(p_z - 4) = 0.0;
      *(p_z - 3) = 0.0;
      *(p_z - 2) = 0.0;
      *(p_z - 1) = 0.0;
      *p_z = 0.0;
      p_z[1] = 0.0;
      p_z[2] = 0.0;
      p_z[3] = 0.0;
      p_z += 9;
    }
  }
  this->m_nNodes = nNodes;
  v8 = 0;
  if ( nNodes - 1 > 0 )
  {
    v9 = 0;
    do
    {
      this->m_pSprings[v8].m_pNode1 = &this->m_pNodes[v9].m_vPos;
      this->m_pSprings[v8].m_pNode2 = &this->m_pNodes[v9 + 1].m_vPos;
      this->m_flNodeSpringDistsSqr[v8++] = this->m_flSpringDistSqr / (float)(this->m_nNodes - 1);
      ++v9;
    }
    while ( v8 < this->m_nNodes - 1 );
  }
  this->m_pDelegate = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F7AC0
// Name: public: void CBaseRopePhysics::SetupSimulation(float,class CSimplePhysics::IHelper __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseRopePhysics::SetupSimulation(
        CBaseRopePhysics *this,
        float flSpringDist,
        CSimplePhysics::IHelper *pDelegate)
{
  float v3; // xmm0_4
  int v4; // edx
  int v5; // eax

  v3 = flSpringDist;
  if ( flSpringDist <= 0.0 )
    v3 = 0.0;
  v4 = this->m_nNodes - 1;
  this->m_flSpringDist = v3;
  v5 = 0;
  this->m_flSpringDistSqr = v3 * v3;
  if ( v4 <= 0 )
  {
    this->m_pDelegate = pDelegate;
  }
  else
  {
    do
      this->m_flNodeSpringDistsSqr[v5++] = this->m_flSpringDistSqr / (float)(this->m_nNodes - 1);
    while ( v5 < this->m_nNodes - 1 );
    this->m_pDelegate = pDelegate;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FB8E0
// Name: _dynamic_initializer_for__rope_anchor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rope_anchor__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CRopeAnchor> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &rope_anchor,
           a3: "rope_anchor");
}

//------------------------------------------------------------------------------
// Address: 0x103FF540
// Name: _dynamic_initializer_for__phys_stressbodyweights__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_stressbodyweights__()
{
  ConVar::ConVar(this: &phys_stressbodyweights, pName: "phys_stressbodyweights", pDefaultValue: "5.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__phys_stressbodyweights__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF570
// Name: _dynamic_initializer_for__phys_impactforcescale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_impactforcescale__()
{
  ConVar::ConVar(this: &phys_impactforcescale, pName: "phys_impactforcescale", pDefaultValue: "1.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__phys_impactforcescale__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF5A0
// Name: _dynamic_initializer_for__phys_upimpactforcescale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_upimpactforcescale__()
{
  ConVar::ConVar(this: &phys_upimpactforcescale, pName: "phys_upimpactforcescale", pDefaultValue: "0.375", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__phys_upimpactforcescale__);
}

//------------------------------------------------------------------------------
// Address: 0x104017B0
// Name: _dynamic_initializer_for__phys_ragdollmagnet__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_ragdollmagnet__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CRagdollMagnet> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &phys_ragdollmagnet,
           a3: "phys_ragdollmagnet");
}

//------------------------------------------------------------------------------
// Address: 0x10406C60
// Name: _dynamic_initializer_for__phys_thruster__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_thruster__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysThruster> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &phys_thruster,
           a3: "phys_thruster");
}

//------------------------------------------------------------------------------
// Address: 0x10406CA0
// Name: _dynamic_initializer_for__phys_torque__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_torque__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysTorque> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &phys_torque,
           a3: "phys_torque");
}

//------------------------------------------------------------------------------
// Address: 0x10406CE0
// Name: _dynamic_initializer_for__phys_motor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_motor__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysMotor> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &phys_motor,
           a3: "phys_motor");
}

//------------------------------------------------------------------------------
// Address: 0x10406D00
// Name: _dynamic_initializer_for__phys_keepupright__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_keepupright__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CKeepUpright> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &phys_keepupright,
           a3: "phys_keepupright");
}

//------------------------------------------------------------------------------
// Address: 0x10406DE0
// Name: _dynamic_initializer_for__phys_constraintsystem__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_constraintsystem__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysConstraintSystem> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &phys_constraintsystem,
           a3: "phys_constraintsystem");
}

//------------------------------------------------------------------------------
// Address: 0x10406E20
// Name: _dynamic_initializer_for__phys_hinge__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_hinge__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysHinge> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &phys_hinge,
           a3: "phys_hinge");
}

//------------------------------------------------------------------------------
// Address: 0x10406E40
// Name: _dynamic_initializer_for__phys_ballsocket__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_ballsocket__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysBallSocket> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &phys_ballsocket,
           a3: "phys_ballsocket");
}

//------------------------------------------------------------------------------
// Address: 0x10406E60
// Name: _dynamic_initializer_for__phys_slideconstraint__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_slideconstraint__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysSlideConstraint> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &phys_slideconstraint,
           a3: "phys_slideconstraint");
}

//------------------------------------------------------------------------------
// Address: 0x10406E90
// Name: _dynamic_initializer_for__phys_constraint__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_constraint__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysFixed> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &phys_constraint,
           a3: "phys_constraint");
}

//------------------------------------------------------------------------------
// Address: 0x10406EC0
// Name: _dynamic_initializer_for__phys_pulleyconstraint__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_pulleyconstraint__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysPulley> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &phys_pulleyconstraint,
           a3: "phys_pulleyconstraint");
}

//------------------------------------------------------------------------------
// Address: 0x10406EF0
// Name: _dynamic_initializer_for__phys_lengthconstraint__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_lengthconstraint__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysLength> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &phys_lengthconstraint,
           a3: "phys_lengthconstraint");
}

//------------------------------------------------------------------------------
// Address: 0x10406F20
// Name: _dynamic_initializer_for__phys_ragdollconstraint__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_ragdollconstraint__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CRagdollConstraint> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &phys_ragdollconstraint,
           a3: "phys_ragdollconstraint");
}

//------------------------------------------------------------------------------
// Address: 0x10406F40
// Name: _dynamic_initializer_for__phys_speeds__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_speeds__()
{
  ConVar::ConVar(this: &phys_speeds, pName: "phys_speeds", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__phys_speeds__);
}

//------------------------------------------------------------------------------
// Address: 0x10406F70
// Name: _dynamic_initializer_for__phys_show_active__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_show_active__()
{
  ConVar::ConVar(this: &phys_show_active, pName: "phys_show_active", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__phys_show_active__);
}

//------------------------------------------------------------------------------
// Address: 0x10406FA0
// Name: _dynamic_initializer_for__phys_debug_check_contacts__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_debug_check_contacts__()
{
  ConVar::ConVar(this: &phys_debug_check_contacts, pName: "phys_debug_check_contacts", pDefaultValue: "0", flags: 24576);
  return atexit(func: dynamic_atexit_destructor_for__phys_debug_check_contacts__);
}

//------------------------------------------------------------------------------
// Address: 0x10407000
// Name: _dynamic_initializer_for__phys_timescale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_timescale__()
{
  ConVar::ConVar(
    this: &phys_timescale,
    pName: "phys_timescale",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Scale time for physics",
    callback: (void (__cdecl *)(IConVar *, const char *, float))TimescaleChanged);
  return atexit(func: dynamic_atexit_destructor_for__phys_timescale__);
}

//------------------------------------------------------------------------------
// Address: 0x10407060
// Name: _dynamic_initializer_for__phys_penetration_error_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_penetration_error_time__()
{
  ConVar::ConVar(
    this: &phys_penetration_error_time,
    pName: "phys_penetration_error_time",
    pDefaultValue: "10",
    flags: 0,
    pHelpString: "Controls the duration of vphysics penetration error boxes.");
  return atexit(func: dynamic_atexit_destructor_for__phys_penetration_error_time__);
}

//------------------------------------------------------------------------------
// Address: 0x10407090
// Name: _dynamic_initializer_for__physics_highlight_active_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__physics_highlight_active_command__()
{
  ConCommand::ConCommand(
    this: &physics_highlight_active_command,
    pName: "physics_highlight_active",
    callback: physics_highlight_active,
    pHelpString: "Turns on the absbox for all active physics objects",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__physics_highlight_active_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104070C0
// Name: _dynamic_initializer_for__physics_report_active_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__physics_report_active_command__()
{
  ConCommand::ConCommand(
    this: &physics_report_active_command,
    pName: "physics_report_active",
    callback: physics_report_active,
    pHelpString: "Lists all active physics objects",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__physics_report_active_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10407120
// Name: _dynamic_initializer_for__physics_constraints_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__physics_constraints_command__()
{
  ConCommand::ConCommand(
    this: &physics_constraints_command,
    pName: "physics_constraints",
    callback: (void (__cdecl *)())physics_constraints,
    pHelpString: "Highlights constraint system graph for an entity",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__physics_constraints_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10407150
// Name: _dynamic_initializer_for__physics_debug_entity_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__physics_debug_entity_command__()
{
  ConCommand::ConCommand(
    this: &physics_debug_entity_command,
    pName: "physics_debug_entity",
    callback: (void (__cdecl *)())physics_debug_entity,
    pHelpString: "Dumps debug info for an entity",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__physics_debug_entity_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10407180
// Name: _dynamic_initializer_for__physics_select_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__physics_select_command__()
{
  ConCommand::ConCommand(
    this: &physics_select_command,
    pName: "physics_select",
    callback: (void (__cdecl *)())physics_select,
    pHelpString: "Dumps debug info for an entity",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__physics_select_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104071B0
// Name: _dynamic_initializer_for__physics_budget_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__physics_budget_command__()
{
  ConCommand::ConCommand(
    this: &physics_budget_command,
    pName: "physics_budget",
    callback: physics_budget,
    pHelpString: "Times the cost of each active object",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__physics_budget_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10407320
// Name: _dynamic_initializer_for__phys_bone_follower__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_bone_follower__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CBoneFollower> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &phys_bone_follower,
           a3: "phys_bone_follower");
}

//------------------------------------------------------------------------------
// Address: 0x10407350
// Name: _dynamic_initializer_for__physics_cannister__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__physics_cannister__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysicsCannister> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &physics_cannister,
           a3: "physics_cannister");
}

//------------------------------------------------------------------------------
// Address: 0x10407600
// Name: _dynamic_initializer_for__physics_npc_solver__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__physics_npc_solver__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysicsNPCSolver> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &physics_npc_solver,
           a3: "physics_npc_solver");
}

//------------------------------------------------------------------------------
// Address: 0x10407650
// Name: _dynamic_initializer_for__physics_entity_solver__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__physics_entity_solver__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysicsEntitySolver> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &physics_entity_solver,
           a3: "physics_entity_solver");
}

//------------------------------------------------------------------------------
// Address: 0x10407680
// Name: _dynamic_initializer_for__physics_prop_ragdoll__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__physics_prop_ragdoll__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CRagdollProp> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &physics_prop_ragdoll,
           a3: "physics_prop_ragdoll");
}

//------------------------------------------------------------------------------
// Address: 0x104077A0
// Name: _dynamic_initializer_for__physics_prop_statue__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__physics_prop_statue__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CStatueProp> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &physics_prop_statue,
           a3: "physics_prop_statue");
}

//------------------------------------------------------------------------------
// Address: 0x104078D0
// Name: _dynamic_initializer_for__phys_spring__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_spring__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysicsSpring> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &phys_spring,
           a3: "phys_spring");
}

//------------------------------------------------------------------------------
// Address: 0x10407A20
// Name: _dynamic_initializer_for__phys_convert__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_convert__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysConvert> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &phys_convert,
           a3: "phys_convert");
}

//------------------------------------------------------------------------------
// Address: 0x10407A50
// Name: _dynamic_initializer_for__phys_magnet__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_magnet__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysMagnet> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &phys_magnet,
           a3: "phys_magnet");
}

//------------------------------------------------------------------------------
// Address: 0x10408EE0
// Name: _dynamic_initializer_for__physics_prop__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__physics_prop__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysicsProp> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &physics_prop,
           a3: "physics_prop");
}

//------------------------------------------------------------------------------
// Address: 0x1040AAA0
// Name: _dynamic_initializer_for__phys_pushscale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__phys_pushscale__()
{
  ConVar::ConVar(this: &phys_pushscale, pName: "phys_pushscale", pDefaultValue: "1", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__phys_pushscale__);
}

//------------------------------------------------------------------------------
// Address: 0x10419850
// Name: _dynamic_atexit_destructor_for__phys_stressbodyweights__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__phys_stressbodyweights__()
{
  ConVar::~ConVar(this: &phys_stressbodyweights);
}

//------------------------------------------------------------------------------
// Address: 0x10419860
// Name: _dynamic_atexit_destructor_for__phys_impactforcescale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__phys_impactforcescale__()
{
  ConVar::~ConVar(this: &phys_impactforcescale);
}

//------------------------------------------------------------------------------
// Address: 0x10419870
// Name: _dynamic_atexit_destructor_for__phys_upimpactforcescale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__phys_upimpactforcescale__()
{
  ConVar::~ConVar(this: &phys_upimpactforcescale);
}

//------------------------------------------------------------------------------
// Address: 0x1041CA40
// Name: _dynamic_atexit_destructor_for__phys_speeds__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__phys_speeds__()
{
  ConVar::~ConVar(this: &phys_speeds);
}

//------------------------------------------------------------------------------
// Address: 0x1041CA50
// Name: _dynamic_atexit_destructor_for__phys_show_active__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__phys_show_active__()
{
  ConVar::~ConVar(this: &phys_show_active);
}

//------------------------------------------------------------------------------
// Address: 0x1041CA60
// Name: _dynamic_atexit_destructor_for__phys_debug_check_contacts__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__phys_debug_check_contacts__()
{
  ConVar::~ConVar(this: &phys_debug_check_contacts);
}

//------------------------------------------------------------------------------
// Address: 0x1041CA70
// Name: _dynamic_atexit_destructor_for__phys_timescale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__phys_timescale__()
{
  ConVar::~ConVar(this: &phys_timescale);
}

//------------------------------------------------------------------------------
// Address: 0x1041CA80
// Name: _dynamic_atexit_destructor_for__phys_penetration_error_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__phys_penetration_error_time__()
{
  ConVar::~ConVar(this: &phys_penetration_error_time);
}

//------------------------------------------------------------------------------
// Address: 0x1041CA90
// Name: _dynamic_atexit_destructor_for__physics_highlight_active_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__physics_highlight_active_command__()
{
  ConCommand::~ConCommand(this: &physics_highlight_active_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041CAA0
// Name: _dynamic_atexit_destructor_for__physics_report_active_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__physics_report_active_command__()
{
  ConCommand::~ConCommand(this: &physics_report_active_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041CAC0
// Name: _dynamic_atexit_destructor_for__physics_constraints_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__physics_constraints_command__()
{
  ConCommand::~ConCommand(this: &physics_constraints_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041CAD0
// Name: _dynamic_atexit_destructor_for__physics_debug_entity_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__physics_debug_entity_command__()
{
  ConCommand::~ConCommand(this: &physics_debug_entity_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041CAE0
// Name: _dynamic_atexit_destructor_for__physics_select_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__physics_select_command__()
{
  ConCommand::~ConCommand(this: &physics_select_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041CAF0
// Name: _dynamic_atexit_destructor_for__physics_budget_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__physics_budget_command__()
{
  ConCommand::~ConCommand(this: &physics_budget_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041E3B0
// Name: _dynamic_atexit_destructor_for__phys_pushscale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__phys_pushscale__()
{
  ConVar::~ConVar(this: &phys_pushscale);
}

//------------------------------------------------------------------------------
// Address: 0x103FB900
// Name: _dynamic_initializer_for__CAI_RappelBehavior::gm_ClassScheduleIdSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_LocalIdSpace *dynamic_initializer_for__CAI_RappelBehavior::gm_ClassScheduleIdSpace__()
{
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_RappelBehavior::gm_ClassScheduleIdSpace.m_ScheduleIds, fIsRoot: false);
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_RappelBehavior::gm_ClassScheduleIdSpace.m_TaskIds, fIsRoot: false);
  return CAI_LocalIdSpace::CAI_LocalIdSpace(
           this: &CAI_RappelBehavior::gm_ClassScheduleIdSpace.m_ConditionIds,
           fIsRoot: false);
}

//------------------------------------------------------------------------------
// Address: 0x103FB930
// Name: _dynamic_initializer_for__DrawBattleLines__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__DrawBattleLines__()
{
  ConVar::ConVar(this: &DrawBattleLines, pName: "ai_drawbattlelines", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__DrawBattleLines__);
}

//------------------------------------------------------------------------------
// Address: 0x103FB960
// Name: _dynamic_initializer_for__ai_battle_line__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_battle_line__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAI_BattleLine> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ai_battle_line,
           a3: "ai_battle_line");
}

//------------------------------------------------------------------------------
// Address: 0x103FF5D0
// Name: _dynamic_initializer_for__s_CombatCharVisCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_CombatCharVisCache__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &s_CombatCharVisCache, name: nullptr);
  s_CombatCharVisCache.__vftable = (CCombatCharVisCache_vtbl *)&CCombatCharVisCache::`vftable';
  s_CombatCharVisCache.m_VisCache.m_Elements.m_pMemory = nullptr;
  s_CombatCharVisCache.m_VisCache.m_Elements.m_nAllocationCount = 0;
  s_CombatCharVisCache.m_VisCache.m_Elements.m_nGrowSize = 0;
  *(_DWORD *)&s_CombatCharVisCache.m_VisCache.m_Root = 0xFFFF;
  *(_DWORD *)&s_CombatCharVisCache.m_VisCache.m_FirstFree = -1;
  s_CombatCharVisCache.m_VisCache.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__s_CombatCharVisCache__);
}

//------------------------------------------------------------------------------
// Address: 0x10406FD0
// Name: _dynamic_initializer_for__g_PostSimulationQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PostSimulationQueue__()
{
  CTSQueue<CFunctor *,0,1>::CTSQueue<CFunctor *,0,1>(this: &g_PostSimulationQueue.m_queue);
  g_PostSimulationQueue.m_bNoQueue = false;
  return atexit(func: dynamic_atexit_destructor_for__g_PostSimulationQueue__);
}

//------------------------------------------------------------------------------
// Address: 0x10407030
// Name: _dynamic_initializer_for__g_Collisions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Collisions__()
{
  CCollisionEvent::CCollisionEvent(this: &g_Collisions);
  return atexit(func: dynamic_atexit_destructor_for__g_Collisions__);
}

//------------------------------------------------------------------------------
// Address: 0x10407050
// Name: _dynamic_initializer_for__g_PhysicsHook__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PhysicsHook__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_PhysicsHook__);
}

//------------------------------------------------------------------------------
// Address: 0x104070F0
// Name: _dynamic_initializer_for__surfaceprop_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__surfaceprop_command__()
{
  ConCommand::ConCommand(
    this: &surfaceprop_command,
    pName: "surfaceprop",
    callback: (void (__cdecl *)())surfaceprop,
    pHelpString: "Reports the surface properties at the cursor",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__surfaceprop_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104077C0
// Name: _dynamic_initializer_for__g_CStatueProp_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CStatueProp_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CStatueProp_ClassReg,
           pNetworkName: "CStatueProp",
           pTable: &DT_StatueProp::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10419880
// Name: _ServerClassInit_DT_BCCLocalPlayerExclusive::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BCCLocalPlayerExclusive::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S4_11;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x104198A0
// Name: _dynamic_atexit_destructor_for__g_CleanupDefaultRelationships__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupDefaultRelationships__()
{
  IGameSystem::~IGameSystem(this: &g_CleanupDefaultRelationships);
}

//------------------------------------------------------------------------------
// Address: 0x104198B0
// Name: _DataMapInit_CBaseCombatCharacter__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseCombatCharacter__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_86);
}

//------------------------------------------------------------------------------
// Address: 0x104198C0
// Name: _DataMapInit_Relationship_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_Relationship_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_87);
}

//------------------------------------------------------------------------------
// Address: 0x104198D0
// Name: _dynamic_atexit_destructor_for__g_VisibilityCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VisibilityCache__()
{
  CUtlRBTree<VisibilityCacheEntry_t,unsigned short,CVisibilityCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<VisibilityCacheEntry_t,unsigned short>,unsigned short>>::~CUtlRBTree<VisibilityCacheEntry_t,unsigned short,CVisibilityCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<VisibilityCacheEntry_t,unsigned short>,unsigned short>>(this: &g_VisibilityCache);
}

//------------------------------------------------------------------------------
// Address: 0x1041CAB0
// Name: _dynamic_atexit_destructor_for__surfaceprop_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__surfaceprop_command__()
{
  ConCommand::~ConCommand(this: &surfaceprop_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041E3C0
// Name: _DataMapInit_CTakeDamageInfo__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTakeDamageInfo__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_406);
}

//------------------------------------------------------------------------------
// Address: 0x1041E3D0
// Name: _DataMapInit_CMultiDamage__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CMultiDamage__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_407);
}

//------------------------------------------------------------------------------
// Address: 0x1041E3E0
// Name: _DataMapInit_CFuncTankTrain__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncTankTrain__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_408);
}

//------------------------------------------------------------------------------
// Address: 0x1041E3F0
// Name: _DataMapInit_CTankTargetChange__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTankTargetChange__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_409);
}

//------------------------------------------------------------------------------
// Address: 0x1041E400
// Name: _DataMapInit_CTankTrainAI__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTankTrainAI__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_410);
}

} // namespace server
