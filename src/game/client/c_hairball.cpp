// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_hairball.cpp
// Functions: 7
// ============================================================

#include "game\client\c_hairball.h"

//------------------------------------------------------------------------------
// Address: 0x10075CD0
// Name: public: virtual enum RenderableTranslucencyType_t C_Hairball::ComputeTranslucencyType(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_Hairball::ComputeTranslucencyType(C_Hairball *this)
{
  return this->m_pMaterial != nullptr && this->m_pMaterial->IsTranslucent(this: this->m_pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x10075D00
// Name: public: virtual void C_Hairball::CHairballDelegate::GetNodeForces(class CSimplePhysics::CNode __near *,int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Hairball::CHairballDelegate::GetNodeForces(
        C_Hairball::CHairballDelegate *this,
        CSimplePhysics::CNode *pNodes,
        int iNode,
        Vector *pAccel)
{
  pAccel->x = 0.0;
  pAccel->y = 0.0;
  pAccel->z = -1500.0;
}

//------------------------------------------------------------------------------
// Address: 0x10075D30
// Name: public: virtual void C_Hairball::CHairballDelegate::ApplyConstraints(class CSimplePhysics::CNode __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Hairball::CHairballDelegate::ApplyConstraints(
        C_Hairball::CHairballDelegate *this,
        CSimplePhysics::CNode *pNodes,
        int nNodes)
{
  C_Hairball *m_pParent; // eax
  int v4; // ebx
  C_Hairball *v5; // edx
  int v6; // edi
  float *p_x; // esi
  CSimplePhysics::CNode *v8; // ecx
  float *p_z; // eax
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm1_4
  float v13; // xmm7_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  int nSegments; // [esp+0h] [ebp-Ch]
  float flSpringDistSqr; // [esp+4h] [ebp-8h]
  int v25; // [esp+8h] [ebp-4h]

  m_pParent = this->m_pParent;
  v4 = m_pParent->m_nNodesPerHair - 1;
  nSegments = v4;
  flSpringDistSqr = m_pParent->m_flSpringDist * m_pParent->m_flSpringDist;
  if ( nIterations > 0 )
  {
    v5 = this->m_pParent;
    v25 = nIterations;
    do
    {
      v6 = 0;
      if ( v5->m_nHairs > 0 )
      {
        p_x = &v5->m_TransformedHairPositions.m_Memory.m_pMemory->x;
        do
        {
          v8 = &pNodes[v6 * v5->m_nNodesPerHair];
          if ( v4 > 0 )
          {
            p_z = &v8[1].m_vPos.z;
            do
            {
              v10 = *(p_z - 11);
              v11 = *(p_z - 10);
              v12 = v10 - *(p_z - 2);
              v13 = v11 - *(p_z - 1);
              v14 = *(p_z - 9) - *p_z;
              v15 = (float)((float)(v12 * v12) + (float)(v13 * v13)) + (float)(v14 * v14);
              if ( v15 > flSpringDistSqr )
              {
                v16 = 1.0 - (float)(v5->m_flSpringDist / fsqrt(v15));
                v17 = v12 * v16;
                v18 = v16;
                v19 = (float)(v16 * v14) * 0.5;
                v20 = v17 * 0.5;
                v21 = (float)(v18 * v13) * 0.5;
                *(p_z - 9) = *(p_z - 9) - v19;
                *(p_z - 11) = v10 - v20;
                *(p_z - 10) = v11 - v21;
                v22 = v19 + *p_z;
                *(p_z - 2) = *(p_z - 2) + v20;
                *(p_z - 1) = *(p_z - 1) + v21;
                *p_z = v22;
              }
              p_z += 9;
              --v4;
            }
            while ( v4 != 0 );
            v4 = nSegments;
          }
          ++v6;
          v8->m_vPos.x = *p_x;
          p_x += 3;
          v8->m_vPos.y = *(p_x - 2);
          v8->m_vPos.z = *(p_x - 1);
        }
        while ( v6 < v5->m_nHairs );
      }
      --v25;
    }
    while ( v25 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10075EB0
// Name: public: virtual void C_Hairball::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_Hairball::ClientThink(C_Hairball *this@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>)
{
  float v5; // xmm0_4
  float v6; // xmm1_4
  IUniformRandomStream *v7; // ecx
  float v8; // xmm0_4
  IUniformRandomStream *v9; // ecx
  float m_flTimeStepMul; // xmm0_4
  float v11; // xmm0_4
  int i; // ebx
  IUniformRandomStream *v13; // ecx
  IUniformRandomStream *v14; // ecx
  int (__thiscall *v15)(char *); // eax
  float *v16; // eax
  float v17; // xmm0_4
  float v18; // xmm0_4
  int (__thiscall *v19)(char *); // edx
  const Vector *v20; // eax
  float v21; // xmm0_4
  int (__thiscall *v22)(char *, int, int, int); // eax
  float *v23; // eax
  int (__thiscall *v24)(char *); // edx
  const Vector *v25; // eax
  IUniformRandomStream *v26; // ecx
  float v27; // xmm0_4
  const Vector *LocalOrigin; // eax
  const Vector *v29; // eax
  int v30; // edi
  int v31; // edx
  int m_nGrowSize; // ecx
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  int v36; // eax
  int v37; // edi
  int j; // edx
  float *v39; // ecx
  float *v40; // eax
  CSimplePhysics::CNode *m_pMemory; // eax
  float v42; // [esp+0h] [ebp-DCh]
  float x; // [esp+4h] [ebp-D8h]
  int v44; // [esp+8h] [ebp-D4h]
  float v45; // [esp+8h] [ebp-D4h]
  int v46; // [esp+Ch] [ebp-D0h]
  float v47; // [esp+Ch] [ebp-D0h]
  CGameTrace trace; // [esp+14h] [ebp-C8h] BYREF
  VMatrix mTransform; // [esp+68h] [ebp-74h] BYREF
  float v50; // [esp+A8h] [ebp-34h]
  float v51; // [esp+ACh] [ebp-30h]
  float v52; // [esp+B0h] [ebp-2Ch]
  Vector vEnd; // [esp+B4h] [ebp-28h] BYREF
  Vector vDir; // [esp+C0h] [ebp-1Ch] BYREF
  float v55; // [esp+CCh] [ebp-10h]
  float v56; // [esp+D0h] [ebp-Ch]
  float v57; // [esp+D4h] [ebp-8h]
  float flLongestFraction; // [esp+D8h] [ebp-4h]
  IHandleEntity savedregs; // [esp+DCh] [ebp+0h] BYREF

  v46 = a4;
  v5 = *(float *)(gpGlobals.m_Index + 16) + this->m_vMoveDir.y;
  v6 = this->m_vMoveDir.x;
  v44 = a3;
  this->m_vMoveDir.y = v5;
  if ( v6 <= v5 )
  {
    if ( fabs(this->m_vMoveDir.z) <= 0.0099999998 )
    {
      if ( (_S5_51 & 1) == 0 )
      {
        _S5_51 |= 1u;
        flYSpeed = flXSpeed * 0.1;
      }
      x = flXSpeed * 3.141592653589793;
      v42 = flXSpeed * -3.141592653589793;
      this->m_vMoveDir.z = _RandomFloat((IUniformRandomStream *)this, a2: v42, a3: x);
      v47 = flYSpeed * 3.141592653589793;
      v45 = flYSpeed * -3.141592653589793;
      this->m_flSpinDuration = _RandomFloat(this: v9, a2: v45, a3: v47);
      v8 = 4.0;
    }
    else
    {
      v8 = 2.0;
      this->m_flSpinDuration = 0.0;
      this->m_vMoveDir.z = 0.0;
    }
    this->m_vMoveDir.x = _RandomFloat((IUniformRandomStream *)this, a2: 1.0, a3: v8);
    this->m_vMoveDir.y = 0.0;
  }
  else
  {
    flLongestFraction = v5 / v6;
    vDir = (Vector)*C_BaseEntity::GetLocalAngles(this: (C_Hairball *)((char *)this - 12));
    vDir.x = SmoothCurve(x: v5 / v6) * this->m_vMoveDir.z + vDir.x;
    vDir.y = SmoothCurve(x: v5 / v6) * this->m_flSpinDuration + vDir.y;
    C_BaseEntity::SetLocalAngles(this: (C_Hairball *)((char *)this - 12), angles: (const QAngle *)&vDir);
  }
  m_flTimeStepMul = this->m_Physics.m_flTimeStepMul;
  if ( m_flTimeStepMul <= 0.0 )
  {
    v21 = *(float *)(gpGlobals.m_Index + 16);
    v22 = *(int (__thiscall **)(char *, int, int, int))(*((_DWORD *)this - 3) + 40);
    v55 = v21 * *(&this->m_Physics.m_flTimeStepMul + 1);
    v56 = *(float *)&this->m_pMaterial * v21;
    v57 = this->m_flSitStillTime * v21;
    v23 = (float *)v22(a1: (char *)this - 12, a2: v44, a3: v46, a4: a2);
    vEnd.x = *v23 + v55;
    vEnd.y = v23[1] + v56;
    v24 = *(int (__thiscall **)(char *))(*((_DWORD *)this - 3) + 40);
    vEnd.z = v23[2] + v57;
    v25 = (const Vector *)v24(a1: (char *)this - 12);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: v25,
      vecAbsEnd: &vEnd,
      mask: 0x200400Bu,
      ignore: nullptr,
      collisionGroup: 0,
      ptr: &trace);
    if ( trace.fraction >= 1.0 )
    {
      v27 = *(float *)(gpGlobals.m_Index + 16);
      v55 = v27 * *(&this->m_Physics.m_flTimeStepMul + 1);
      v56 = *(float *)&this->m_pMaterial * v27;
      v57 = this->m_flSitStillTime * v27;
      LocalOrigin = C_BaseEntity::GetLocalOrigin(this: (C_Hairball *)((char *)this - 12));
      vEnd.x = LocalOrigin->x + v55;
      vEnd.y = LocalOrigin->y + v56;
      vEnd.z = LocalOrigin->z + v57;
      C_BaseEntity::SetLocalOrigin(this: (C_Hairball *)((char *)this - 12), origin: &vEnd);
    }
    else
    {
      this->m_Physics.m_flTimeStepMul = _RandomFloat(this: v26, a2: 1.0, a3: 3.0);
    }
  }
  else
  {
    v11 = m_flTimeStepMul - *(float *)(gpGlobals.m_Index + 16);
    this->m_Physics.m_flTimeStepMul = v11;
    if ( v11 <= 0.0 )
    {
      *((_DWORD *)&this->m_Physics.m_flTimeStepMul + 1) = 1065353216;
      this->m_pMaterial = nullptr;
      this->m_flSitStillTime = 0.0;
      flLongestFraction = 0.0;
      for ( i = 15; i != 0; --i )
      {
        v51 = _RandomFloat(this: v7, a2: -1.0, a3: 1.0);
        v52 = _RandomFloat(this: v13, a2: -1.0, a3: 1.0);
        v50 = _RandomFloat(this: v14, a2: -1.0, a3: 1.0);
        vDir.x = v51;
        vDir.y = v52;
        vDir.z = v50;
        VectorNormalize(vec: &vDir);
        v15 = *(int (__thiscall **)(char *))(*((_DWORD *)this - 3) + 40);
        v55 = vDir.x * 10000.0;
        v56 = vDir.y * 10000.0;
        v57 = vDir.z * 10000.0;
        v16 = (float *)v15(a1: (char *)this - 12);
        v17 = v55 + *v16;
        LODWORD(trace.startpos.z) = &trace;
        vEnd.x = v17;
        v18 = v16[1] + v56;
        trace.startpos.y = 0.0;
        trace.startpos.x = 0.0;
        vEnd.y = v18;
        v19 = *(int (__thiscall **)(char *))(*((_DWORD *)this - 3) + 40);
        vEnd.z = v16[2] + v57;
        v20 = (const Vector *)v19(a1: (char *)this - 12);
        UTIL_TraceLine(
          a1: &savedregs,
          a2: (int)this,
          vecAbsStart: v20,
          vecAbsEnd: &vEnd,
          mask: 0x200400Bu,
          ignore: (const IHandleEntity *)LODWORD(trace.startpos.x),
          collisionGroup: SLODWORD(trace.startpos.y),
          ptr: (CGameTrace *)LODWORD(trace.startpos.z));
        if ( trace.fraction != 1.0 && trace.fraction > flLongestFraction )
        {
          flLongestFraction = trace.fraction;
          *(Vector *)(&this->m_Physics.m_flTimeStepMul + 1) = vDir;
        }
      }
      *(&this->m_Physics.m_flTimeStepMul + 1) = *(&this->m_Physics.m_flTimeStepMul + 1) * 650.0;
      *(float *)&this->m_pMaterial = *(float *)&this->m_pMaterial * 650.0;
      this->m_flSitStillTime = this->m_flSitStillTime * 650.0;
      this->m_Physics.m_flTimeStepMul = -1.0;
    }
  }
  LODWORD(trace.startpos.z) = C_BaseEntity::GetLocalAngles(this: (C_Hairball *)((char *)this - 12));
  v29 = C_BaseEntity::GetLocalOrigin(this: (C_Hairball *)((char *)this - 12));
  VMatrix::SetupMatrixOrgAngles(this: &mTransform, origin: v29, vAngles: (const QAngle *)LODWORD(trace.startpos.z));
  v30 = 0;
  if ( (int)this->m_HairPositions.m_Memory.m_pMemory > 0 )
  {
    v31 = 0;
    do
    {
      m_nGrowSize = this->m_Nodes.m_Memory.m_nGrowSize;
      v33 = *(float *)(m_nGrowSize + v31);
      v34 = *(float *)(m_nGrowSize + v31 + 4);
      v35 = *(float *)(m_nGrowSize + v31 + 8);
      v36 = this->m_HairPositions.m_Memory.m_nGrowSize;
      *(float *)(v36 + v31) = (float)((float)((float)(mTransform.m[0][1] * v34) + (float)(mTransform.m[0][0] * v33))
                                    + (float)(mTransform.m[0][2] * v35))
                            + mTransform.m[0][3];
      *(float *)(v36 + v31 + 4) = (float)((float)((float)(mTransform.m[1][1] * v34) + (float)(mTransform.m[1][0] * v33))
                                        + (float)(mTransform.m[1][2] * v35))
                                + mTransform.m[1][3];
      *(float *)(v36 + v31 + 8) = (float)((float)((float)(mTransform.m[2][0] * v33) + (float)(mTransform.m[2][1] * v34))
                                        + (float)(mTransform.m[2][2] * v35))
                                + mTransform.m[2][3];
      ++v30;
      v31 += 12;
    }
    while ( v30 < (int)this->m_HairPositions.m_Memory.m_pMemory );
  }
  if ( LOBYTE(this->m_flCurSpinTime) != 0 )
  {
    v37 = 0;
    LOBYTE(this->m_flCurSpinTime) = 0;
    if ( (int)this->m_HairPositions.m_Memory.m_pMemory > 0 )
    {
      flLongestFraction = 0.0;
      do
      {
        for ( j = 0; j < *((_DWORD *)&this->m_bIsBlurred + 1); v40[2] = v40[5] )
        {
          v39 = (float *)(LODWORD(flLongestFraction) + this->m_HairPositions.m_Memory.m_nGrowSize);
          v40 = (float *)(this->m_nHairs + 36 * (j + v37 * *((_DWORD *)&this->m_bIsBlurred + 1)));
          ++j;
          v40[6] = *v39;
          v40[7] = v39[1];
          v40[8] = v39[2];
          v40[3] = v40[6];
          v40[4] = v40[7];
          v40[5] = v40[8];
          *v40 = v40[3];
          v40[1] = v40[4];
        }
        LODWORD(flLongestFraction) += 12;
        ++v37;
      }
      while ( v37 < (int)this->m_HairPositions.m_Memory.m_pMemory );
    }
  }
  m_pMemory = this->m_Nodes.m_Memory.m_pMemory;
  trace.startpos.z = 0.98000002;
  CSimplePhysics::Simulate(
    this: (CSimplePhysics *)&this->m_Delegate,
    pNodes: (CSimplePhysics::CNode *)this->m_nHairs,
    nNodes: (int)m_pMemory,
    pHelper: (CSimplePhysics::IHelper *)&this->m_TransformedHairPositions.m_Memory.m_nGrowSize,
    dt: *(float *)(gpGlobals.m_Index + 16),
    flDamp: 0.98000002);
}

//------------------------------------------------------------------------------
// Address: 0x100765A0
// Name: public: virtual int C_Hairball::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __userpurge C_Hairball::DrawModel@<eax>(
        C_Hairball *this@<ecx>,
        int a2@<ebp>,
        int flags,
        const RenderableInstance_t *instance)
{
  IMatRenderContext *v6; // edi
  int m_nHairs; // edx
  float m_flSpringDist; // edi
  _DWORD *v9; // edi
  _DWORD v10[3]; // [esp-Ch] [ebp-28Ch] BYREF
  CBeamSegDraw beamDraw; // [esp+0h] [ebp-280h] BYREF
  BeamSeg_t seg; // [esp+250h] [ebp-30h]
  int v13; // [esp+270h] [ebp-10h]
  int i; // [esp+274h] [ebp-Ch] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+278h] [ebp-8h]
  IMatRenderContext *retaddr; // [esp+280h] [ebp+0h]

  i = a2;
  pRenderContext.m_pObject = retaddr;
  if ( *((_DWORD *)&this->m_Physics.m_flTimeStepMul + 1) == 0 )
    return 0;
  v6 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  *((_DWORD *)&seg.m_flWidth + 1) = v6;
  if ( v6 != nullptr )
    v6->BeginRender(this: v6);
  v13 = 0;
  if ( SLODWORD(this->m_flSphereRadius) > 0 )
  {
    do
    {
      m_nHairs = this->m_nHairs;
      m_flSpringDist = this->m_flSpringDist;
      *((_DWORD *)&seg.m_flWidth + 1) = 0;
      seg.m_flWidth = 0.0;
      v9 = (_DWORD *)(LODWORD(m_flSpringDist) + 36 * v13 * m_nHairs + 32);
      beamDraw.m_Mesh.m_nOffset = 0;
      LOBYTE(beamDraw.m_Mesh.m_nIndexSize) = 0;
      memset(&beamDraw.m_Mesh.m_IndexBuilder.m_nOffset, 0, 12);
      beamDraw.m_Mesh.m_IndexBuilder.m_nMaxIndexCount = 0;
      beamDraw.m_Mesh.m_IndexBuilder.m_nIndexCount = 0;
      beamDraw.m_Mesh.m_IndexBuilder.m_nCurrentIndex = 0;
      beamDraw.m_Mesh.m_VertexBuilder.m_pUserData = nullptr;
      beamDraw.m_Mesh.m_VertexBuilder.m_pCurrTexCoord[7] = nullptr;
      memset(&beamDraw.m_Mesh.m_VertexBuilder.m_nOffset, 0, 12);
      beamDraw.m_Mesh.m_VertexBuilder.m_pCurrTexCoord[5] = nullptr;
      beamDraw.m_vNormalLast.x = 0.0;
      seg.m_flTexCoord = *(&this->m_Physics.m_flTimeStepMul + 1);
      beamDraw.m_Mesh.m_IndexBuilder.m_nIndexOffset = -1;
      beamDraw.m_Mesh.m_VertexBuilder.m_pCurrTexCoord[6] = (float *)-1;
      beamDraw.m_Mesh.m_VertexBuilder.m_VertexSize_Wrinkle = -1;
      v10[0] = &CBeamSegDraw::`vftable';
      CBeamSegDraw::Start(
        this: (CBeamSegDraw *)v10,
        pRenderContext: nullptr,
        nSegs: m_nHairs - 1,
        pMaterial: (IMaterial *)LODWORD(seg.m_flTexCoord),
        pMeshBuilder: nullptr,
        nMeshVertCount: 0);
      seg.m_flWidth = 0.0;
      if ( this->m_nHairs > 0 )
      {
        do
        {
          *((_DWORD *)&beamDraw.m_vecCameraPos + 3) = *(v9 - 2);
          *((_DWORD *)&beamDraw.m_vecCameraPos + 4) = *(v9 - 1);
          *((_DWORD *)&beamDraw.m_vecCameraPos + 5) = *v9;
          seg.m_vPos.z = 0.0;
          seg.m_vPos.y = 0.0;
          seg.m_vPos.w = flHairWidth;
          CBeamSegDraw::NextSeg(
            this: (CBeamSegDraw *)v10,
            a2: COERCE_FLOAT(&i),
            pSeg: (BeamSeg_t *)(&beamDraw.m_vecCameraPos + 1));
          v9 += 9;
          ++LODWORD(seg.m_flWidth);
        }
        while ( SLODWORD(seg.m_flWidth) < this->m_nHairs );
      }
      CBeamSegDraw::End(this: (CBeamSegDraw *)v10);
      if ( beamDraw.m_Mesh.m_VertexBuilder.m_pUserData != nullptr
        && (*(unsigned __int8 (__thiscall **)(float *))(*(_DWORD *)beamDraw.m_Mesh.m_VertexBuilder.m_pUserData + 8))(a1: beamDraw.m_Mesh.m_VertexBuilder.m_pUserData) != 0 )
      {
        (*(void (__thiscall **)(float *))(*(_DWORD *)beamDraw.m_Mesh.m_VertexBuilder.m_pUserData + 16))(a1: beamDraw.m_Mesh.m_VertexBuilder.m_pUserData);
      }
      if ( beamDraw.m_Mesh.m_IndexBuilder.m_nOffset != 0
        && (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)beamDraw.m_Mesh.m_IndexBuilder.m_nOffset + 8))(a1: beamDraw.m_Mesh.m_IndexBuilder.m_nOffset) != 0 )
      {
        (*(void (__thiscall **)(unsigned int))(*(_DWORD *)beamDraw.m_Mesh.m_IndexBuilder.m_nOffset + 16))(a1: beamDraw.m_Mesh.m_IndexBuilder.m_nOffset);
      }
      ++v13;
    }
    while ( v13 < SLODWORD(this->m_flSphereRadius) );
    v6 = *((IMatRenderContext **)&seg.m_flWidth + 1);
  }
  if ( v6 != nullptr )
  {
    v6->EndRender(this: v6);
    v6->Release(this: v6);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100768C0
// Name: public: C_Hairball::C_Hairball(void)
// Source: json
//------------------------------------------------------------------------------
C_Hairball *__thiscall C_Hairball::C_Hairball(C_Hairball *this)
{
  IUniformRandomStream *v2; // ecx
  IUniformRandomStream *v3; // ecx
  Vector *v4; // ebx
  double v5; // xmm0_8
  double v6; // xmm0_8
  double v7; // xmm0_8
  double v8; // xmm0_8
  int m_nHairs; // [esp+4h] [ebp-30h]
  int v11; // [esp+4h] [ebp-30h]
  float flTimeStep; // [esp+14h] [ebp-20h]
  float v13; // [esp+18h] [ebp-1Ch]
  int i; // [esp+1Ch] [ebp-18h]
  float cosPhi; // [esp+20h] [ebp-14h]
  float theta; // [esp+24h] [ebp-10h]
  float phi; // [esp+28h] [ebp-Ch]
  int v18; // [esp+2Ch] [ebp-8h]
  float m_flSphereRadius; // [esp+30h] [ebp-4h]

  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_Hairball_vtbl *)&C_Hairball::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_Hairball::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_Hairball::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_Hairball::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_Hairball::`vftable';
  this->m_Nodes.m_Memory.m_pMemory = nullptr;
  this->m_Nodes.m_Memory.m_nAllocationCount = 0;
  this->m_Nodes.m_Memory.m_nGrowSize = 0;
  this->m_Nodes.m_Size = 0;
  this->m_Nodes.m_pElements = nullptr;
  this->m_HairPositions.m_Memory.m_pMemory = nullptr;
  this->m_HairPositions.m_Memory.m_nAllocationCount = 0;
  this->m_HairPositions.m_Memory.m_nGrowSize = 0;
  this->m_HairPositions.m_Size = 0;
  this->m_HairPositions.m_pElements = nullptr;
  this->m_TransformedHairPositions.m_Memory.m_pMemory = nullptr;
  this->m_TransformedHairPositions.m_Memory.m_nAllocationCount = 0;
  this->m_TransformedHairPositions.m_Memory.m_nGrowSize = 0;
  this->m_TransformedHairPositions.m_Size = 0;
  this->m_TransformedHairPositions.m_pElements = nullptr;
  this->m_Delegate.__vftable = (C_Hairball::CHairballDelegate_vtbl *)&C_Hairball::CHairballDelegate::`vftable';
  CSimplePhysics::CSimplePhysics(this: &this->m_Physics);
  this->m_nHairs = 100;
  this->m_nNodesPerHair = 3;
  this->m_flSpringDist = 10.0;
  this->m_Nodes.m_Size = 0;
  CUtlVector<CSimplePhysics::CNode,CUtlMemory<CSimplePhysics::CNode,int>>::InsertMultipleBefore(
    this: &this->m_Nodes,
    elem: 0,
    num: 300);
  m_nHairs = this->m_nHairs;
  this->m_HairPositions.m_Size = 0;
  CUtlVector<CaptionLookup_t,CUtlMemory<CaptionLookup_t,int>>::InsertMultipleBefore(
    this: &this->m_HairPositions,
    elem: 0,
    num: m_nHairs);
  v11 = this->m_nHairs;
  this->m_TransformedHairPositions.m_Size = 0;
  CUtlVector<CaptionLookup_t,CUtlMemory<CaptionLookup_t,int>>::InsertMultipleBefore(
    this: &this->m_TransformedHairPositions,
    elem: 0,
    num: v11);
  this->m_flSphereRadius = 20.0;
  this->m_vMoveDir.x = 0.0;
  this->m_vMoveDir.y = 0.0;
  this->m_vMoveDir.z = 0.0;
  this->m_flSpinDuration = 1.0;
  this->m_flCurSpinTime = 0.0;
  *(_QWORD *)&this->m_flSpinRateX = 0;
  i = 0;
  if ( this->m_HairPositions.m_Size > 0 )
  {
    v18 = 0;
    do
    {
      theta = _RandomFloat(this: v2, a2: -3.1415927, a3: 3.1415927);
      phi = _RandomFloat(this: v3, a2: -1.5707964, a3: 1.5707964);
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(phi)));
      v4 = &this->m_HairPositions.m_Memory.m_pMemory[v18];
      *(float *)&v5 = v5;
      cosPhi = *(float *)&v5;
      m_flSphereRadius = this->m_flSphereRadius;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(theta)));
      *(float *)&v6 = v6;
      v13 = (float)(*(float *)&v6 * cosPhi) * m_flSphereRadius;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(phi)));
      *(float *)&v7 = v7;
      flTimeStep = *(float *)&v7 * m_flSphereRadius;
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(theta)));
      ++v18;
      *(float *)&v8 = v8;
      v4->x = (float)(*(float *)&v8 * cosPhi) * m_flSphereRadius;
      v4->y = v13;
      v4->z = flTimeStep;
      ++i;
    }
    while ( i < this->m_HairPositions.m_Size );
  }
  this->m_Delegate.m_pParent = this;
  CSimplePhysics::Init(this: &this->m_Physics, flTimeStep: 0.050000001);
  this->m_pMaterial = nullptr;
  this->m_bFirstThink = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10076BD0
// Name: void CreateHairballCallback(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateHairballCallback()
{
  int i; // ebx
  C_Hairball *v1; // eax
  C_BaseEntity *v2; // esi
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v4; // edi
  const QAngle *v5; // eax
  IUniformRandomStream *v6; // ecx
  IUniformRandomStream *v7; // ecx
  IUniformRandomStream *v8; // ecx
  const Vector *(__thiscall *GetAbsOrigin)(IClientEntity *); // eax
  float *v10; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  Vector origin; // [esp+24h] [ebp-34h] BYREF
  Vector vForward; // [esp+30h] [ebp-28h] BYREF
  float v15; // [esp+3Ch] [ebp-1Ch]
  float v16; // [esp+40h] [ebp-18h]
  float v17; // [esp+44h] [ebp-14h]
  float v18; // [esp+48h] [ebp-10h]
  float v19; // [esp+4Ch] [ebp-Ch]
  float v20; // [esp+50h] [ebp-8h]
  CBaseHandle result; // [esp+54h] [ebp-4h] BYREF

  for ( i = 0; i < 20; ++i )
  {
    v1 = (C_Hairball *)C_BaseEntity::operator new(stAllocateBlock: 0xA18u);
    if ( v1 != nullptr )
      v2 = C_Hairball::C_Hairball(this: v1);
    else
      v2 = nullptr;
    CBaseEntityList::AddNonNetworkableEntity(this: (CBaseEntityList *)cl_entitylist.m_Index, &result, pEnt: v2);
    CClientThinkList::SetNextClientThink(this: &g_ClientThinkList, hEnt: v2->m_RefEHandle, flNextTime: -1293.0);
    C_BaseEntity::AddToLeafSystem(this: v2, bRenderWithViewModels: false);
    v2[1].m_cellbits = (int)materials->FindMaterial(
                              this: materials,
                              a2: "cable/cable",
                              a3: "Other textures",
                              a4: 1,
                              a5: 0);
    v2[1].m_cellwidth = 1084227584;
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    v4 = LocalPlayer;
    if ( LocalPlayer == nullptr )
      break;
    v5 = LocalPlayer->GetAbsAngles(this: LocalPlayer);
    AngleVectors(angles: v5, forward: &vForward);
    v15 = _RandomFloat(this: v6, a2: 0.0, a3: 100.0);
    v16 = _RandomFloat(this: v7, a2: 0.0, a3: 100.0);
    v17 = _RandomFloat(this: v8, a2: 0.0, a3: 100.0);
    GetAbsOrigin = v4->GetAbsOrigin;
    v18 = vForward.x * 300.0;
    v19 = vForward.y * 300.0;
    v20 = vForward.z * 300.0;
    v10 = (float *)GetAbsOrigin(this: v4);
    v11 = (float)(v10[1] + v19) + v16;
    v12 = (float)(v10[2] + v20) + v17;
    origin.x = (float)(*v10 + v18) + v15;
    origin.y = v11;
    origin.z = v12;
    C_BaseEntity::SetLocalOrigin(this: v2, &origin);
  }
}
