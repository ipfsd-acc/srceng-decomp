// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_rope.cpp
// Functions: 101
// ============================================================

#include "game\client\c_rope.h"

//------------------------------------------------------------------------------
// Address: 0x1001F360
// Name: public: void CMeshBuilder::Begin(class IMesh __near *,enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::Begin(CMeshBuilder *this, IMesh *pMesh, int type, int numPrimitives)
{
  MaterialPrimitiveType_t v4; // ebx
  IMesh *v5; // edi
  MaterialPrimitiveType_t v7; // ebx
  IMesh *v8; // [esp-8h] [ebp-14h]
  int v9; // [esp-4h] [ebp-10h]

  v4 = type;
  v5 = pMesh;
  pMesh = nullptr;
  type = 0;
  v9 = numPrimitives;
  this->m_pMesh = v5;
  this->m_bGenerateIndices = true;
  this->m_Type = v4;
  CMeshBuilder::ComputeNumVertsAndIndices(
    this,
    pMaxVertices: (int *)&pMesh,
    pMaxIndices: &type,
    type: v4,
    nPrimitiveCount: v9);
  switch ( v4 )
  {
    case MATERIAL_LINE_STRIP:
    case MATERIAL_LINE_LOOP:
      v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
      break;
    case MATERIAL_POLYGON:
    case MATERIAL_QUADS:
      v5->SetPrimitiveType(this: v5, a2: MATERIAL_TRIANGLES);
      break;
    case MATERIAL_INSTANCED_QUADS:
      v5->SetPrimitiveType(this: v5, a2: MATERIAL_INSTANCED_QUADS);
      break;
    default:
      v5->SetPrimitiveType(this: v5, a2: v4);
      break;
  }
  v7 = type;
  this->m_pMesh->LockMesh(this: this->m_pMesh, a2: (int)pMesh, a3: type, a4: this, a5: nullptr);
  this->m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_nMaxIndexCount = v7;
  this->m_IndexBuilder.m_bModify = false;
  this->m_IndexBuilder.m_nIndexOffset = this->m_nFirstVertex;
  this->m_IndexBuilder.m_pIndices = this->m_pIndices;
  v8 = pMesh;
  this->m_IndexBuilder.m_nIndexSize = this->m_nIndexSize;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &this->m_VertexBuilder, pMesh: v5, nMaxVertexCount: (int)v8, desc: this);
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &this->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x10081EB0
// Name: public: virtual void PrecacheRopesPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheRopesPrecache::CResourcePrecacher::Cache(
        PrecacheRopesPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "cable/rope_shadowdepth",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10081EE0
// Name: public: virtual class ClientClass __near * C_RopeKeyframe::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_RopeKeyframe::GetClientClass(C_RopeKeyframe *this)
{
  return &__g_C_RopeKeyframeClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10081EF0
// Name: class IRopeManager __near * RopeManager(void)
// Source: json
//------------------------------------------------------------------------------
CRopeManager *__cdecl RopeManager()
{
  return &s_RopeManager;
}

//------------------------------------------------------------------------------
// Address: 0x10081F00
// Name: void Rope_ResetCounters(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Rope_ResetCounters()
{
  g_nRopePointsSimulated = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10081F10
// Name: public: virtual class Vector const __near & C_RopeKeyframe::WorldSpaceCenter(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_RopeKeyframe::WorldSpaceCenter(C_RopeKeyframe *this)
{
  return this->GetAbsOrigin(this);
}

//------------------------------------------------------------------------------
// Address: 0x10081F20
// Name: void RecvProxy_RecomputeSprings(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_RecomputeSprings(const CRecvProxyData *pData, char *pStruct, void *pOut)
{
  RecvProxy_Int32ToInt32(pData, pStruct, pOut);
  CBaseRopePhysics::ResetSpringLength(
    this: (CBaseRopePhysics *)(pStruct + 2496),
    flSpringDist: (float)((*((_DWORD *)pStruct + 792) + *((_DWORD *)pStruct + 791) - 100) / (*((_DWORD *)pStruct + 627) - 1)));
}

//------------------------------------------------------------------------------
// Address: 0x10082270
// Name: public: CFullBrightLightValuesInit::CFullBrightLightValuesInit(void)
// Source: json
//------------------------------------------------------------------------------
CFullBrightLightValuesInit *__thiscall CFullBrightLightValuesInit::CFullBrightLightValuesInit(
        CFullBrightLightValuesInit *this)
{
  g_FullBright_LightValues[0].x = 1.0;
  g_FullBright_LightValues[0].y = 1.0;
  g_FullBright_LightValues[0].z = 1.0;
  g_FullBright_LightValues[1].x = 1.0;
  g_FullBright_LightValues[1].y = 1.0;
  g_FullBright_LightValues[1].z = 1.0;
  g_FullBright_LightValues[2].x = 1.0;
  g_FullBright_LightValues[2].y = 1.0;
  g_FullBright_LightValues[2].z = 1.0;
  g_FullBright_LightValues[3].x = 1.0;
  g_FullBright_LightValues[3].y = 1.0;
  g_FullBright_LightValues[3].z = 1.0;
  g_FullBright_LightValues[4].x = 1.0;
  g_FullBright_LightValues[4].y = 1.0;
  g_FullBright_LightValues[4].z = 1.0;
  g_FullBright_LightValues[5].x = 1.0;
  g_FullBright_LightValues[5].y = 1.0;
  g_FullBright_LightValues[5].z = 1.0;
  g_FullBright_LightValues[6].x = 1.0;
  g_FullBright_LightValues[6].y = 1.0;
  g_FullBright_LightValues[6].z = 1.0;
  g_FullBright_LightValues[7].x = 1.0;
  g_FullBright_LightValues[7].y = 1.0;
  g_FullBright_LightValues[7].z = 1.0;
  g_FullBright_LightValues[8].x = 1.0;
  g_FullBright_LightValues[8].y = 1.0;
  g_FullBright_LightValues[8].z = 1.0;
  g_FullBright_LightValues[9].x = 1.0;
  g_FullBright_LightValues[9].y = 1.0;
  g_FullBright_LightValues[9].z = 1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10082370
// Name: void LockNodeDirection(class CSimplePhysics::CNode __near *,int,int,float,float,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LockNodeDirection(
        CSimplePhysics::CNode *pNodes,
        int parity,
        int nFalloffNodes,
        float flLockAmount,
        float flLockFalloff,
        const Vector *vIdealDir)
{
  int v6; // esi
  int v8; // eax
  float *p_z; // edx
  float *v10; // ecx
  float v11; // xmm5_4
  float v12; // xmm6_4
  float v13; // xmm4_4
  float v14; // xmm2_4
  float v15; // xmm7_4
  float v16; // xmm1_4
  float v17; // xmm4_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // [esp-20h] [ebp-2Ch]
  float v22; // [esp-4h] [ebp-10h]

  v6 = nFalloffNodes;
  if ( nFalloffNodes > 0 )
  {
    v8 = 36 * parity;
    p_z = &pNodes->m_vPos.z;
    v10 = &pNodes[parity].m_vPos.z;
    do
    {
      v11 = *(p_z - 2);
      v12 = *(p_z - 1);
      v13 = *v10 - *p_z;
      v22 = *p_z;
      v14 = *(v10 - 2) - v11;
      v15 = *(v10 - 1) - v12;
      v16 = fsqrt((float)((float)(v15 * v15) + (float)(v14 * v14)) + (float)(v13 * v13));
      v21 = v16;
      if ( v16 > 0.000099999997 )
      {
        v17 = v13 * (float)(1.0 / v16);
        v18 = (float)((float)(vIdealDir->x - (float)((float)(1.0 / v16) * v14)) * flLockAmount)
            + (float)((float)(1.0 / v16) * v14);
        v19 = (float)((float)((float)(vIdealDir->y - (float)((float)(1.0 / v16) * v15)) * flLockAmount)
                    + (float)((float)(1.0 / v16) * v15))
            * v16;
        v20 = (float)(vIdealDir->z - v17) * flLockAmount;
        flLockAmount = flLockAmount * flLockFalloff;
        *(v10 - 2) = v11 + (float)(v18 * v21);
        *(v10 - 1) = v12 + v19;
        *v10 = v22 + (float)((float)(v20 + v17) * v21);
      }
      p_z = (float *)((char *)p_z + v8);
      v10 = (float *)((char *)v10 + v8);
      --v6;
    }
    while ( v6 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100824D0
// Name: public: void C_RopeKeyframe::ShakeRope(class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_RopeKeyframe::ShakeRope(
        C_RopeKeyframe *this,
        const Vector *vCenter,
        float flRadius,
        float flMagnitude)
{
  int v4; // edi
  char v5; // dl
  CSimplePhysics::CNode *m_pNodes; // esi
  float v7; // xmm1_4
  float v8; // xmm1_4

  v4 = 0;
  v5 = 0;
  if ( this->m_nSegments > 0 )
  {
    m_pNodes = this->m_RopePhysics.m_pNodes;
    do
    {
      v7 = m_pNodes->m_vPos.y - vCenter->y;
      v8 = (float)(1.0 / flRadius)
         * fsqrt(
             (float)((float)(v7 * v7)
                   + (float)((float)(m_pNodes->m_vPos.z - vCenter->z) * (float)(m_pNodes->m_vPos.z - vCenter->z)))
           + (float)((float)(m_pNodes->m_vPos.x - vCenter->x) * (float)(m_pNodes->m_vPos.x - vCenter->x)));
      if ( (float)(1.0 - v8) >= 0.0 )
      {
        this->m_vecImpulse.z = (float)((float)(1.0 - v8) * flMagnitude) + this->m_vecImpulse.z;
        v5 = 1;
      }
      ++v4;
      ++m_pNodes;
    }
    while ( v4 < this->m_nSegments );
    if ( v5 != 0 )
      ((void (__stdcall *)(int))this->SetNextClientThink)(a1: -996040704);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100825C0
// Name: private: void C_RopeKeyframe::FinishInit(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_RopeKeyframe::FinishInit(C_RopeKeyframe *this, const char *pMaterialName)
{
  IMaterial *v3; // eax
  bool v4; // zf
  IMaterial *v5; // eax
  IMaterial v6; // edx
  IMaterial *m_pMaterial; // ecx
  int m_nSegments; // eax
  Vector mins; // [esp+28h] [ebp-18h] BYREF
  Vector maxs; // [esp+34h] [ebp-Ch] BYREF

  v3 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: "Other textures", a4: 1, a5: 0);
  v4 = g_pSplineCableShadowdepth == nullptr;
  this->m_pMaterial = v3;
  if ( v4 )
  {
    v5 = g_pMaterialSystem->FindMaterial(
           this: g_pMaterialSystem,
           a2: "cable/rope_shadowdepth",
           a3: "Other textures",
           a4: 1,
           a5: 0);
    v6.__vftable = v5->__vftable;
    g_pSplineCableShadowdepth = v5;
    v6.IncrementReferenceCount(this: v5);
  }
  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr )
    this->m_TextureHeight = m_pMaterial->GetMappingHeight(this: m_pMaterial);
  else
    this->m_TextureHeight = 1;
  m_nSegments = this->m_nSegments;
  if ( m_nSegments >= 2 )
  {
    if ( m_nSegments > 10 )
      m_nSegments = 10;
  }
  else
  {
    m_nSegments = 2;
  }
  this->m_nSegments = m_nSegments;
  CBaseRopePhysics::SetNumNodes(this: &this->m_RopePhysics, nNodes: m_nSegments);
  maxs.x = 10.0;
  maxs.y = 10.0;
  maxs.z = 10.0;
  mins.x = -10.0;
  mins.y = -10.0;
  mins.z = -10.0;
  CCollisionProperty::SetCollisionBounds(this: &this->m_Collision, &mins, &maxs);
  ((void (__thiscall *)(C_RopeKeyframe *, int))this->SetNextClientThink)(a1: this, a2: -996040704);
}

//------------------------------------------------------------------------------
// Address: 0x100826E0
// Name: private: void C_RopeKeyframe::ConstrainNodesBetweenEndpoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_RopeKeyframe::ConstrainNodesBetweenEndpoints(C_RopeKeyframe *this)
{
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  int v7; // ecx
  unsigned int v8; // edi
  CSimplePhysics::CNode *m_pNodes; // ebx
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  CSimplePhysics::CNode *v13; // ebx
  float v14; // xmm0_4
  double v15; // st7
  float v16; // ecx
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  CSimplePhysics::CNode *v20; // eax
  CSimplePhysics::CNode *v21; // edx
  float v22; // xmm0_4
  float v23; // xmm2_4
  int p_m_vPredicted; // ebx
  float v25; // xmm0_4
  double v26; // st7
  float v27; // edx
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm2_4
  Vector *v31; // eax
  int v32; // ecx
  Vector v33; // [esp+4h] [ebp-74h] BYREF
  Vector v34; // [esp+10h] [ebp-68h] BYREF
  __int64 v35; // [esp+1Ch] [ebp-5Ch]
  float v36; // [esp+24h] [ebp-54h]
  __int64 v37; // [esp+28h] [ebp-50h]
  float v38; // [esp+30h] [ebp-48h]
  Vector v39; // [esp+34h] [ebp-44h] BYREF
  Vector vec; // [esp+40h] [ebp-38h] BYREF
  Vector vNormal; // [esp+4Ch] [ebp-2Ch] BYREF
  Vector vMidpiont; // [esp+58h] [ebp-20h]
  float v43; // [esp+64h] [ebp-14h]
  float v44; // [esp+68h] [ebp-10h]
  int i; // [esp+6Ch] [ebp-Ch]
  float v46; // [esp+70h] [ebp-8h]
  float fNormalLength; // [esp+74h] [ebp-4h]

  if ( this->m_bConstrainBetweenEndpoints )
  {
    x = this->m_vCachedEndPointAttachmentPos[0].x;
    y = this->m_vCachedEndPointAttachmentPos[0].y;
    z = this->m_vCachedEndPointAttachmentPos[0].z;
    v5 = this->m_vCachedEndPointAttachmentPos[1].y;
    v6 = this->m_vCachedEndPointAttachmentPos[1].z;
    vMidpiont.x = (float)(x + this->m_vCachedEndPointAttachmentPos[1].x) * 0.5;
    vMidpiont.y = (float)(v5 + y) * 0.5;
    vMidpiont.z = (float)(v6 + z) * 0.5;
    vNormal.x = vMidpiont.x - x;
    vNormal.y = vMidpiont.y - y;
    vNormal.z = vMidpiont.z - z;
    fNormalLength = VectorNormalize(vec: &vNormal);
    v7 = this->m_RopePhysics.m_nNodes - 1;
    i = 1;
    if ( v7 > 1 )
    {
      v46 = fNormalLength + 1.0;
      v8 = 1;
      do
      {
        m_pNodes = this->m_RopePhysics.m_pNodes;
        v10 = m_pNodes[v8].m_vPos.x - vMidpiont.x;
        v11 = m_pNodes[v8].m_vPos.y;
        v12 = m_pNodes[v8].m_vPos.z - vMidpiont.z;
        v13 = &m_pNodes[v8];
        vec.x = v10;
        vec.y = v11 - vMidpiont.y;
        vec.z = v12;
        v14 = (float)((float)((float)(v11 - vMidpiont.y) * vNormal.y) + (float)(v10 * vNormal.x))
            + (float)(v12 * vNormal.z);
        v34.x = v14 * vNormal.x;
        v34.y = vNormal.y * v14;
        v34.z = vNormal.z * v14;
        v44 = VectorNormalize(&vec);
        v15 = VectorNormalize(vec: &v34);
        v43 = v15;
        if ( v46 <= v15 )
        {
          v18 = (float)((float)(vec.x * v44) * (float)(fNormalLength / v43)) + vMidpiont.x;
          v17 = (float)((float)(vec.y * v44) * (float)(fNormalLength / v43)) + vMidpiont.y;
          v19 = (float)((float)(vec.z * v44) * (float)(fNormalLength / v43)) + vMidpiont.z;
        }
        else
        {
          v16 = v13->m_vPos.z;
          v37 = *(_QWORD *)&v13->m_vPos.x;
          v17 = *((float *)&v37 + 1);
          v18 = *(float *)&v37;
          v38 = v16;
          v19 = v16;
        }
        v20 = this->m_RopePhysics.m_pNodes;
        v20[v8].m_vPos.x = v18;
        v20[v8].m_vPos.z = v19;
        v20[v8].m_vPos.y = v17;
        v21 = this->m_RopePhysics.m_pNodes;
        v22 = v21[v8].m_vPredicted.y;
        v23 = v21[v8].m_vPredicted.z - vMidpiont.z;
        p_m_vPredicted = (int)&v21[v8].m_vPredicted;
        v39.x = *(float *)p_m_vPredicted - vMidpiont.x;
        v39.y = v22 - vMidpiont.y;
        v39.z = v23;
        v25 = (float)((float)((float)(v22 - vMidpiont.y) * vNormal.y) + (float)(v39.x * vNormal.x))
            + (float)(v23 * vNormal.z);
        v33.x = v25 * vNormal.x;
        v33.y = vNormal.y * v25;
        v33.z = vNormal.z * v25;
        v43 = VectorNormalize(vec: &v39);
        v26 = VectorNormalize(vec: &v33);
        v44 = v26;
        if ( v46 <= v26 )
        {
          v29 = (float)((float)(v39.x * v43) * (float)(fNormalLength / v44)) + vMidpiont.x;
          v28 = (float)((float)(v39.y * v43) * (float)(fNormalLength / v44)) + vMidpiont.y;
          v30 = (float)((float)(v39.z * v43) * (float)(fNormalLength / v44)) + vMidpiont.z;
        }
        else
        {
          v27 = *(float *)(p_m_vPredicted + 8);
          v35 = *(_QWORD *)p_m_vPredicted;
          v28 = *((float *)&v35 + 1);
          v29 = *(float *)&v35;
          v36 = v27;
          v30 = v27;
        }
        v31 = &this->m_RopePhysics.m_pNodes[v8].m_vPredicted;
        v31->x = v29;
        v31->y = v28;
        v31->z = v30;
        v32 = this->m_RopePhysics.m_nNodes - 1;
        ++v8;
        ++i;
      }
      while ( i < v32 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082A00
// Name: public: virtual bool C_RopeKeyframe::GetAttachment(int,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_RopeKeyframe::GetAttachment(C_RopeKeyframe *this, int number, matrix3x4_t *matrix)
{
  CSimplePhysics::CNode *m_pNodes; // eax
  float *m_pDelegate; // eax
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  CSimplePhysics::IHelper *v9; // ecx
  int v10; // eax
  float v11; // xmm0_4
  CSimplePhysics::IHelper *v12; // eax
  Vector origin; // [esp+0h] [ebp-18h] BYREF
  Vector vForward; // [esp+Ch] [ebp-Ch] BYREF

  m_pNodes = this->m_RopePhysics.m_pNodes;
  if ( number != 1 && number != 2 || (int)m_pNodes < 2 )
    return 0;
  if ( number == 1 )
  {
    m_pDelegate = (float *)this->m_RopePhysics.m_pDelegate;
    origin.x = m_pDelegate[6];
    origin.y = m_pDelegate[7];
    origin.z = m_pDelegate[8];
    v6 = m_pDelegate[6] - m_pDelegate[15];
    v7 = m_pDelegate[7] - m_pDelegate[16];
    v8 = m_pDelegate[8] - m_pDelegate[17];
  }
  else
  {
    v9 = this->m_RopePhysics.m_pDelegate;
    v10 = 9 * (_DWORD)m_pNodes;
    v11 = *(float *)&v9[v10 - 3].__vftable;
    v12 = &v9[v10];
    origin.x = v11;
    LODWORD(origin.y) = (CSimplePhysics::IHelper)v12[-2].__vftable;
    LODWORD(origin.z) = (CSimplePhysics::IHelper)v12[-1].__vftable;
    v6 = *(float *)&v12[-3].__vftable - *(float *)&v12[-12].__vftable;
    v7 = *(float *)&v12[-2].__vftable - *(float *)&v12[-11].__vftable;
    v8 = *(float *)&v12[-1].__vftable - *(float *)&v12[-10].__vftable;
  }
  vForward.z = v8;
  vForward.y = v7;
  vForward.x = v6;
  VectorMatrix(forward: &vForward, matrix);
  MatrixSetColumn(in: &origin, column: 3, out: matrix);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10082AF0
// Name: public: virtual bool C_RopeKeyframe::GetAttachment(int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_RopeKeyframe::GetAttachment(C_RopeKeyframe *this, int number, Vector *origin)
{
  int m_nNodes; // eax
  CSimplePhysics::CNode *m_pNodes; // eax
  Vector *v6; // ecx
  double z; // st7
  CSimplePhysics::CNode *v8; // ecx
  int v9; // eax
  double x; // st7
  int p_m_vPredicted; // eax

  m_nNodes = this->m_RopePhysics.m_nNodes;
  if ( number != 1 && number != 2 || m_nNodes < 2 )
    return 0;
  if ( number == 1 )
  {
    m_pNodes = this->m_RopePhysics.m_pNodes;
    v6 = origin;
    origin->x = m_pNodes->m_vPredicted.x;
    origin->y = m_pNodes->m_vPredicted.y;
    z = m_pNodes->m_vPredicted.z;
  }
  else
  {
    v8 = this->m_RopePhysics.m_pNodes;
    v9 = m_nNodes;
    x = v8[v9 - 1].m_vPredicted.x;
    p_m_vPredicted = (int)&v8[v9 - 1].m_vPredicted;
    v6 = origin;
    origin->x = x;
    origin->y = *(float *)(p_m_vPredicted + 4);
    z = *(float *)(p_m_vPredicted + 8);
  }
  v6->z = z;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10082B60
// Name: public: virtual bool C_RopeKeyframe::GetAttachment(int,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_RopeKeyframe::GetAttachment(C_RopeKeyframe *this, int number, Vector *origin, QAngle *angles)
{
  CSimplePhysics::CNode *m_pNodes; // eax
  float *m_pDelegate; // eax
  float *v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  CSimplePhysics::IHelper *v10; // edx
  int v11; // eax
  double v12; // st7
  int v13; // edx
  CSimplePhysics::IHelper *v14; // ecx
  Vector vForward; // [esp+0h] [ebp-Ch] BYREF

  m_pNodes = this->m_RopePhysics.m_pNodes;
  if ( number != 1 && number != 2 || (int)m_pNodes < 2 )
    return 0;
  if ( number == 1 )
  {
    m_pDelegate = (float *)this->m_RopePhysics.m_pDelegate;
    origin->x = m_pDelegate[6];
    origin->y = m_pDelegate[7];
    origin->z = m_pDelegate[8];
    v6 = (float *)this->m_RopePhysics.m_pDelegate;
    v7 = v6[6] - v6[15];
    v8 = v6[7] - v6[16];
    v9 = v6[8] - v6[17];
  }
  else
  {
    v10 = this->m_RopePhysics.m_pDelegate;
    v11 = 9 * (_DWORD)m_pNodes;
    v12 = *(float *)&v10[v11 - 3].__vftable;
    v13 = (int)&v10[v11 - 3];
    origin->x = v12;
    origin->y = *(float *)(v13 + 4);
    origin->z = *(float *)(v13 + 8);
    v14 = this->m_RopePhysics.m_pDelegate;
    v7 = *(float *)&v14[v11 - 3].__vftable - *(float *)&v14[v11 - 12].__vftable;
    v8 = *(float *)&v14[v11 - 2].__vftable - *(float *)&v14[v11 - 11].__vftable;
    v9 = *(float *)&v14[v11 - 1].__vftable - *(float *)&v14[v11 - 10].__vftable;
  }
  vForward.z = v9;
  vForward.y = v8;
  vForward.x = v7;
  VectorAngles(forward: &vForward, angles);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10082C50
// Name: private: void C_RopeKeyframe::UpdateBBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_RopeKeyframe::UpdateBBox(C_RopeKeyframe *this)
{
  CSimplePhysics::CNode *m_pNodes; // eax
  int m_nNodes; // ecx
  float x; // xmm1_4
  float *p_x; // ecx
  double v6; // xmm0_8
  double v7; // xmm1_8
  float v8; // xmm0_4
  double y; // xmm0_8
  float v10; // xmm0_4
  double z; // xmm0_8
  float v12; // xmm0_4
  double v13; // xmm0_8
  float v14; // xmm0_4
  double v15; // xmm0_8
  float v16; // xmm0_4
  double v17; // xmm0_8
  int v18; // edi
  int v19; // eax
  int v20; // ebx
  const Vector *v21; // eax
  C_RopeKeyframe_vtbl *v22; // edx
  float v23; // xmm0_4
  const Vector *(__thiscall *GetAbsOrigin)(IClientEntity *); // eax
  float *v25; // eax
  Vector mins; // [esp+4h] [ebp-18h] BYREF
  Vector maxs; // [esp+10h] [ebp-Ch] BYREF

  m_pNodes = this->m_RopePhysics.m_pNodes;
  m_nNodes = this->m_RopePhysics.m_nNodes;
  x = m_pNodes[m_nNodes - 1].m_vPos.x;
  p_x = &m_pNodes[m_nNodes - 1].m_vPos.x;
  v6 = m_pNodes->m_vPos.x;
  v7 = x;
  if ( v6 > v7 )
    v6 = v7;
  v8 = v6;
  mins.x = v8;
  y = m_pNodes->m_vPos.y;
  if ( y > p_x[1] )
    y = p_x[1];
  v10 = y;
  mins.y = v10;
  z = m_pNodes->m_vPos.z;
  if ( z > p_x[2] )
    z = p_x[2];
  v12 = z;
  mins.z = v12;
  v13 = m_pNodes->m_vPos.x;
  if ( v13 < *p_x )
    v13 = *p_x;
  v14 = v13;
  maxs.x = v14;
  v15 = m_pNodes->m_vPos.y;
  if ( v15 < p_x[1] )
    v15 = p_x[1];
  v16 = v15;
  maxs.y = v16;
  v17 = m_pNodes->m_vPos.z;
  if ( v17 < p_x[2] )
    v17 = p_x[2];
  v18 = 1;
  v19 = this->m_RopePhysics.m_nNodes - 1;
  maxs.z = v17;
  if ( v19 > 1 )
  {
    v20 = 1;
    do
    {
      AddPointToBounds(v: &this->m_RopePhysics.m_pNodes[v20].m_vPos, &mins, &maxs);
      ++v18;
      ++v20;
    }
    while ( v18 < this->m_RopePhysics.m_nNodes - 1 );
  }
  v21 = this->GetAbsOrigin(this);
  v22 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  mins.x = mins.x - v21->x;
  mins.y = mins.y - v21->y;
  v23 = mins.z - v21->z;
  GetAbsOrigin = v22->GetAbsOrigin;
  mins.z = v23;
  v25 = (float *)GetAbsOrigin(this);
  maxs.x = maxs.x - *v25;
  maxs.y = maxs.y - v25[1];
  maxs.z = maxs.z - v25[2];
  CCollisionProperty::SetCollisionBounds(this: &this->m_Collision, &mins, &maxs);
}

//------------------------------------------------------------------------------
// Address: 0x10082E00
// Name: private: bool C_RopeKeyframe::CalculateEndPointAttachment(class C_BaseEntity __near *,int,class Vector __near &,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge C_RopeKeyframe::CalculateEndPointAttachment@<al>(
        C_RopeKeyframe *this@<ecx>,
        int a2@<ebx>,
        C_BaseEntity *pEnt,
        int iAttachment,
        Vector *vPos,
        QAngle *pAngles)
{
  const Vector *v8; // eax
  _DWORD *p_x; // edi
  int v10; // eax
  char v11; // al
  char v12; // bl
  bool v13; // al

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_RopeKeyframe::CalculateEndPointAttachment",
    a3: 0,
    a4: "Ropes",
    a5: false,
    a6: 4);
  if ( pEnt == nullptr )
    goto LABEL_2;
  if ( SLOBYTE(this->m_RopeFlags) < 0 && pEnt->IsPlayer(this: pEnt) )
  {
    v8 = pEnt->IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetOldOrigin(this: pEnt);
    p_x = (_DWORD *)&v8->x;
    if ( v8 == nullptr )
    {
LABEL_2:
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return 0;
    }
    v10 = (*(int (__thiscall **)(float *, const char *, int))(LODWORD(v8->y) + 132))(
            a1: &v8->y,
            a2: "buff_attach",
            a3: a2);
    if ( pAngles != nullptr )
      v11 = (*(int (__thiscall **)(_DWORD *, int, Vector *))(p_x[1] + 140))(a1: p_x + 1, a2: v10, a3: vPos);
    else
      v11 = (*(int (__thiscall **)(_DWORD *, int))(*p_x + 316))(a1: p_x, a2: v10);
    v12 = v11;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return v12;
  }
  else
  {
    if ( iAttachment <= 0
      || (pAngles == nullptr
        ? (v13 = pEnt->GetAttachment(this: pEnt, a2: iAttachment, a3: vPos))
        : (v13 = pEnt->GetAttachment_2(this: &pEnt->IClientRenderable, a2: iAttachment, a3: vPos, a4: pAngles)),
          !v13) )
    {
      *vPos = *pEnt->WorldSpaceCenter(this: pEnt);
      if ( pAngles != nullptr )
        *pAngles = *pEnt->GetAbsAngles(this: pEnt);
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082F60
// Name: public: bool C_RopeKeyframe::GetEndPointPos(int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge C_RopeKeyframe::GetEndPointPos@<al>(C_RopeKeyframe *this@<ecx>, int a2@<ebx>, int iPt, Vector *vPos)
{
  unsigned int m_Index; // ecx
  C_BaseEntity *m_pEntity; // eax
  unsigned int v7; // ecx
  C_BaseEntity *v8; // eax
  int v9; // eax
  double v10; // st7
  float *v11; // eax
  double v12; // st7

  if ( (*((_BYTE *)this + 3313) & 1) != 0 )
  {
    m_Index = this->m_hStartPoint.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    C_RopeKeyframe::CalculateEndPointAttachment(
      this,
      a2,
      pEnt: m_pEntity,
      iAttachment: this->m_iStartAttachment,
      vPos: this->m_vCachedEndPointAttachmentPos,
      pAngles: nullptr);
    v7 = this->m_hEndPoint.m_Index;
    if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
      v8 = nullptr;
    else
      v8 = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
    C_RopeKeyframe::CalculateEndPointAttachment(
      this,
      a2,
      pEnt: v8,
      iAttachment: this->m_iEndAttachment,
      vPos: &this->m_vCachedEndPointAttachmentPos[1],
      pAngles: nullptr);
    *((_BYTE *)this + 3313) &= ~1u;
  }
  v9 = 3 * iPt + 816;
  v10 = *((float *)&this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable + v9);
  v11 = (float *)(&this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable + v9);
  vPos->x = v10;
  vPos->y = v11[1];
  v12 = v11[2];
  vPos->z = v12;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10083030
// Name: private: bool C_RopeKeyframe::GetEndPointAttachment(int,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge C_RopeKeyframe::GetEndPointAttachment@<al>(
        C_RopeKeyframe *this@<ecx>,
        int a2@<ebx>,
        int iPt,
        Vector *vPos,
        QAngle *angle)
{
  unsigned int m_Index; // ecx
  C_BaseEntity *m_pEntity; // eax
  unsigned int v8; // ecx
  C_BaseEntity *v9; // eax

  if ( (*((_BYTE *)this + 3313) & 3) != 0 )
  {
    m_Index = this->m_hStartPoint.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    C_RopeKeyframe::CalculateEndPointAttachment(
      this,
      a2,
      pEnt: m_pEntity,
      iAttachment: this->m_iStartAttachment,
      vPos: this->m_vCachedEndPointAttachmentPos,
      pAngles: this->m_vCachedEndPointAttachmentAngle);
    v8 = this->m_hEndPoint.m_Index;
    if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
      v9 = nullptr;
    else
      v9 = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
    C_RopeKeyframe::CalculateEndPointAttachment(
      this,
      a2,
      pEnt: v9,
      iAttachment: this->m_iEndAttachment,
      vPos: &this->m_vCachedEndPointAttachmentPos[1],
      pAngles: &this->m_vCachedEndPointAttachmentAngle[1]);
    *((_BYTE *)this + 3313) &= 0xFCu;
  }
  *vPos = this->m_vCachedEndPointAttachmentPos[iPt];
  *angle = this->m_vCachedEndPointAttachmentAngle[iPt];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10083130
// Name: private: void C_RopeKeyframe::CalcLightValues(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall C_RopeKeyframe::CalcLightValues(C_RopeKeyframe *this@<ecx>, int a2@<ebp>)
{
  float *p_z; // esi
  float *v3; // edi
  float v4; // xmm3_4
  float *v5; // eax
  int j; // ecx
  __int128 v7; // xmm0
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  int v12; // [esp-Ch] [ebp-74h] BYREF
  int v13; // [esp-8h] [ebp-70h] BYREF
  __int128 boxColors_60; // [esp+3Ch] [ebp-2Ch] OVERLAPPED
  C_RopeKeyframe *v15; // [esp+4Ch] [ebp-1Ch]
  int v16; // [esp+50h] [ebp-18h]
  float v17; // [esp+54h] [ebp-14h]
  unsigned int v18; // [esp+58h] [ebp-10h]
  int i; // [esp+5Ch] [ebp-Ch]
  float flMaxIntensity; // [esp+60h] [ebp-8h]
  float retaddr; // [esp+68h] [ebp+0h]

  i = a2;
  flMaxIntensity = retaddr;
  v15 = this;
  v16 = 0;
  if ( this->m_RopePhysics.m_nNodes > 0 )
  {
    v18 = 0;
    p_z = &this->m_LightValues[0].z;
    do
    {
      v3 = p_z - 2;
      engine->ComputeLighting(
        this: engine,
        a2: &this->m_RopePhysics.m_pNodes[v18 / 0x24].m_vPredicted,
        a3: nullptr,
        a4: true,
        a5: (Vector *)(p_z - 2),
        a6: (Vector *)&v12);
      if ( rope_averagelight.m_pParent == nullptr || rope_averagelight.m_pParent->m_Value.m_nValue == 0 )
      {
        v4 = 0.0;
        v17 = 0.0;
        v5 = (float *)&v13;
        for ( j = 6; j != 0; --j )
        {
          v7 = 0;
          *(float *)&v7 = fsqrt((float)((float)(*(v5 - 1) * *(v5 - 1)) + (float)(v5[1] * v5[1])) + (float)(*v5 * *v5));
          boxColors_60 = v7;
          if ( v4 <= *(float *)&v7 )
            v4 = *(float *)&boxColors_60;
          v5 += 3;
        }
        v17 = v4;
        VectorNormalize(vec: (Vector *)(p_z - 2));
        v8 = v17;
        *v3 = v17 * *v3;
        *(p_z - 1) = *(p_z - 1) * v8;
        v9 = *p_z * v8;
        *p_z = v9;
        v10 = *(p_z - 1);
        if ( v10 <= v9 )
          v11 = v9;
        else
          v11 = *(p_z - 1);
        if ( *v3 <= v11 )
        {
          if ( v10 > v9 )
            v9 = *(p_z - 1);
        }
        else
        {
          v9 = *v3;
        }
        if ( v9 > 1.0 )
        {
          *v3 = (float)(1.0 / v9) * *v3;
          *(p_z - 1) = *(p_z - 1) * (float)(1.0 / v9);
          *p_z = *p_z * (float)(1.0 / v9);
        }
      }
      this = v15;
      v18 += 36;
      p_z += 3;
      ++v16;
    }
    while ( v16 < v15->m_RopePhysics.m_nNodes );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100832D0
// Name: private: virtual void C_RopeKeyframe::ReceiveMessage(int,class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_RopeKeyframe::ReceiveMessage(C_RopeKeyframe *this, int classID, bf_read *msg)
{
  int m_nBitsAvail; // edi
  unsigned int v6; // ecx
  const unsigned int *v7; // esi
  const unsigned int *v8; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int m_nInBufWord; // edx
  int v11; // esi
  const unsigned int *m_pBufferEnd; // edi
  unsigned int v13; // edi
  unsigned int v14; // ebx
  int v15; // edi
  unsigned int v16; // ecx
  const unsigned int *v17; // esi
  const unsigned int *v18; // edx
  const unsigned int *v19; // ecx
  unsigned int v20; // edx
  int v21; // esi
  const unsigned int *v22; // edi
  unsigned int v23; // edi
  unsigned int v24; // ebx
  int v25; // edi
  unsigned int v26; // ecx
  const unsigned int *v27; // esi
  const unsigned int *v28; // edx
  const unsigned int *v29; // ecx
  unsigned int v30; // ebx
  int v31; // esi
  const unsigned int *v32; // edi
  unsigned int v33; // edx
  unsigned int v34; // edi
  bf_read *msga; // [esp+14h] [ebp+Ch]
  bf_read *msgb; // [esp+14h] [ebp+Ch]
  bf_read *msgc; // [esp+14h] [ebp+Ch]

  if ( classID != *(_DWORD *)(((int (__fastcall *)(C_RopeKeyframe *))this->GetRefEHandle)(a1: this) + 20) )
  {
    C_BaseEntity::ReceiveMessage(this, classID, msg);
    return;
  }
  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 32 )
  {
    m_pDataIn = msg->m_pDataIn;
    m_nInBufWord = msg->m_nInBufWord;
    v11 = 32 - m_nBitsAvail;
    m_pBufferEnd = msg->m_pBufferEnd;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_18;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
LABEL_18:
    if ( msg->m_bOverflow )
    {
      msga = nullptr;
    }
    else
    {
      v13 = msg->m_nInBufWord;
      v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v11;
      msga = (bf_read *)(v14 | m_nInBufWord);
      msg->m_nInBufWord = v13 >> v11;
    }
    goto LABEL_21;
  }
  v6 = msg->m_nInBufWord;
  msg->m_nBitsAvail = m_nBitsAvail - 32;
  if ( m_nBitsAvail == 32 )
  {
    v7 = msg->m_pDataIn;
    v8 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v7 + 1;
      msga = (bf_read *)v6;
    }
    else
    {
      if ( v7 <= v8 )
      {
        msg->m_nInBufWord = *v7;
        msg->m_pDataIn = v7 + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      msga = (bf_read *)v6;
    }
  }
  else
  {
    msg->m_nInBufWord = 0;
    msga = (bf_read *)v6;
  }
LABEL_21:
  this->m_pMaterial = (IMaterial *)msga;
  v15 = msg->m_nBitsAvail;
  if ( v15 < 32 )
  {
    v19 = msg->m_pDataIn;
    v20 = msg->m_nInBufWord;
    v21 = 32 - v15;
    v22 = msg->m_pBufferEnd;
    if ( v19 == v22 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v19 > v22 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_36;
      }
      msg->m_nInBufWord = *v19;
    }
    msg->m_pDataIn = v19 + 1;
LABEL_36:
    if ( msg->m_bOverflow )
    {
      msgb = nullptr;
    }
    else
    {
      v23 = msg->m_nInBufWord;
      v24 = (v23 & CBitBuffer::s_nMaskTable[v21]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v21;
      msgb = (bf_read *)(v24 | v20);
      msg->m_nInBufWord = v23 >> v21;
    }
    goto LABEL_39;
  }
  v16 = msg->m_nInBufWord;
  msg->m_nBitsAvail = v15 - 32;
  if ( v15 == 32 )
  {
    v17 = msg->m_pDataIn;
    v18 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v17 == v18 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v17 + 1;
      msgb = (bf_read *)v16;
    }
    else
    {
      if ( v17 <= v18 )
      {
        msg->m_nInBufWord = *v17;
        msg->m_pDataIn = v17 + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      msgb = (bf_read *)v16;
    }
  }
  else
  {
    msg->m_nInBufWord = 0;
    msgb = (bf_read *)v16;
  }
LABEL_39:
  this->m_TextureHeight = (int)msgb;
  v25 = msg->m_nBitsAvail;
  if ( v25 < 32 )
  {
    v29 = msg->m_pDataIn;
    v30 = msg->m_nInBufWord;
    v31 = 32 - v25;
    v32 = msg->m_pBufferEnd;
    if ( v29 == v32 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v29 > v32 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_53;
      }
      msg->m_nInBufWord = *v29;
    }
    msg->m_pDataIn = v29 + 1;
LABEL_53:
    if ( msg->m_bOverflow )
    {
      msgc = nullptr;
    }
    else
    {
      v33 = msg->m_nInBufWord;
      v34 = (v33 & CBitBuffer::s_nMaskTable[v31]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v31;
      msgc = (bf_read *)(v34 | v30);
      msg->m_nInBufWord = v33 >> v31;
    }
    goto LABEL_56;
  }
  v26 = msg->m_nInBufWord;
  msg->m_nBitsAvail = v25 - 32;
  if ( v25 != 32 )
  {
LABEL_45:
    msg->m_nInBufWord = 0;
    msgc = (bf_read *)v26;
    goto LABEL_56;
  }
  v27 = msg->m_pDataIn;
  v28 = msg->m_pBufferEnd;
  msg->m_nBitsAvail = 32;
  if ( v27 != v28 )
  {
    if ( v27 <= v28 )
    {
      msg->m_nInBufWord = *v27;
      msg->m_pDataIn = v27 + 1;
      msgc = (bf_read *)v26;
      goto LABEL_56;
    }
    msg->m_bOverflow = true;
    goto LABEL_45;
  }
  msg->m_nBitsAvail = 1;
  msg->m_nInBufWord = 0;
  msg->m_pDataIn = v27 + 1;
  msgc = (bf_read *)v26;
LABEL_56:
  LODWORD(this->m_vecImpulse.x) = msgc;
}

//------------------------------------------------------------------------------
// Address: 0x100835E0
// Name: public: void CUtlMemory<struct CRopeManager::RopeRenderData_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CRopeManager::RopeRenderData_t,int>::Grow(
        CUtlMemory<CRopeManager::RopeRenderData_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CRopeManager::RopeRenderData_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 520 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CRopeManager::RopeRenderData_t *)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CRopeManager::RopeRenderData_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083680
// Name: public: void CMeshBuilder::Begin(class IMesh __near *,enum MaterialPrimitiveType_t,int,int,struct MeshBuffersAllocationSettings_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::Begin(
        CMeshBuilder *this,
        IMesh *pMesh,
        MaterialPrimitiveType_t type,
        int nVertexCount,
        int nIndexCount,
        MeshBuffersAllocationSettings_t *pMeshSettings)
{
  this->m_Type = type;
  this->m_pMesh = pMesh;
  this->m_bGenerateIndices = false;
  pMesh->SetPrimitiveType(this: pMesh, a2: type);
  this->m_pMesh->LockMesh(this: this->m_pMesh, a2: nVertexCount, a3: nIndexCount, a4: this, a5: pMeshSettings);
  this->m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_nMaxIndexCount = nIndexCount;
  this->m_IndexBuilder.m_bModify = false;
  this->m_IndexBuilder.m_nIndexOffset = this->m_nFirstVertex;
  this->m_IndexBuilder.m_pIndices = this->m_pIndices;
  this->m_IndexBuilder.m_nIndexSize = this->m_nIndexSize;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &this->m_VertexBuilder, pMesh, nMaxVertexCount: nVertexCount, desc: this);
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &this->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x10083740
// Name: public: virtual void CRopeManager::ResetRenderCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeManager::ResetRenderCache(CRopeManager *this)
{
  int m_Size; // edx
  int v2; // eax

  m_Size = this->m_aRenderCache.m_Size;
  if ( m_Size > 0 )
  {
    v2 = 0;
    do
    {
      this->m_aRenderCache.m_Memory.m_pMemory[v2++].m_nCacheCount = 0;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083770
// Name: public: virtual void C_RopeKeyframe::CPhysicsDelegate::GetNodeForces(class CSimplePhysics::CNode __near *,int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall C_RopeKeyframe::CPhysicsDelegate::GetNodeForces(
        C_RopeKeyframe::CPhysicsDelegate *this,
        CSimplePhysics::CNode *pNodes,
        int iNode,
        Vector *pAccel)
{
  C_RopeKeyframe *m_pKeyframe; // edx
  bool v5; // zf
  int v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm2_4
  float *v10; // edi
  C_RopeKeyframe *v11; // eax
  __m128 m_flCurrentGustTimer_low; // xmm0
  __m128i v13; // xmm0
  double v14; // xmm0_8
  float v15; // xmm2_4
  float v16; // xmm3_4
  IUniformRandomStream *v17; // ecx
  IUniformRandomStream *v18; // ecx
  double v19; // st7
  float *v20; // eax
  float v21; // xmm2_4
  float v22; // xmm3_4
  float z; // xmm0_4
  Vector vecWindVel; // [esp+10h] [ebp-10h] BYREF
  C_RopeKeyframe::CPhysicsDelegate *v25; // [esp+1Ch] [ebp-4h]
  int iNodea; // [esp+2Ch] [ebp+Ch]
  float pAccela; // [esp+30h] [ebp+10h]

  m_pKeyframe = this->m_pKeyframe;
  v5 = (m_pKeyframe->m_RopeFlags & 0x100) == 0;
  v25 = this;
  if ( v5 )
  {
    pAccel->x = 0.0;
    pAccel->y = 0.0;
    pAccel->z = -1500.0;
  }
  v7 = iNode & 0x1F;
  if ( ((1 << v7) & m_pKeyframe->m_LinksTouchingSomething.m_Ints[iNode >> 5]) == 0 && m_pKeyframe->m_bApplyWind )
  {
    GetWindspeedAtTime(flTime: *(float *)(gpGlobals.m_Index + 12), vecVelocity: &vecWindVel);
    if ( (float)((float)((float)(vecWindVel.y * vecWindVel.y) + (float)(vecWindVel.x * vecWindVel.x))
               + (float)(vecWindVel.z * vecWindVel.z)) <= 0.0 )
    {
      v10 = (float *)v25->m_pKeyframe;
      if ( v10[808] != 0.0 && v25->m_pKeyframe->m_flCurrentGustLifetime > v25->m_pKeyframe->m_flCurrentGustTimer )
      {
        v11 = v25->m_pKeyframe;
        m_flCurrentGustTimer_low = (__m128)LODWORD(v11->m_flCurrentGustTimer);
        m_flCurrentGustTimer_low.m128_f32[0] = m_flCurrentGustTimer_low.m128_f32[0] / v11->m_flCurrentGustLifetime;
        v13 = (__m128i)_mm_cvtps_pd(m_flCurrentGustTimer_low);
        *(double *)v13.m128i_i64 = *(double *)v13.m128i_i64 * 3.141592653589793;
        __libm_sse2_cos(X: v13);
        *(float *)&v14 = 1.0 - v14;
        v15 = v10[811] * *(float *)&v14;
        v16 = v10[812] * *(float *)&v14;
        pAccel->x = pAccel->x + (float)(v10[810] * *(float *)&v14);
        pAccel->y = pAccel->y + v15;
        pAccel->z = pAccel->z + v16;
      }
    }
    else
    {
      v8 = (float)(vecWindVel.y * 10.0) + pAccel->y;
      v9 = (float)(vecWindVel.z * 10.0) + pAccel->z;
      pAccel->x = (float)(vecWindVel.x * 10.0) + pAccel->x;
      pAccel->y = v8;
      pAccel->z = v9;
    }
  }
  if ( rope_shake.m_pParent != nullptr && rope_shake.m_pParent->m_Value.m_nValue != 0 )
  {
    iNodea = LODWORD(scale) ^ _mask__NegFloat_;
    pAccela = scale;
    vecWindVel.x = _RandomFloat(
                     this: (IUniformRandomStream *)v7,
                     a2: COERCE_FLOAT(LODWORD(scale) ^ _mask__NegFloat_),
                     a3: scale);
    _RandomFloat(this: v17, a2: *(float *)&iNodea, a3: pAccela);
    v19 = _RandomFloat(this: v18, a2: *(float *)&iNodea, a3: pAccela);
    pAccel->x = pAccel->x + vecWindVel.x;
    pAccel->y = pAccel->y + vecWindVel.y;
    pAccel->z = v19 + pAccel->z;
  }
  v20 = (float *)v25->m_pKeyframe;
  v21 = v20[803] * 20.0;
  v22 = pAccel->x + (float)(v20[801] * 20.0);
  pAccel->y = pAccel->y + (float)(v20[802] * 20.0);
  z = pAccel->z;
  pAccel->x = v22;
  pAccel->z = z + v21;
  v20[801] = v20[801] * 0.94999999;
  v20[802] = v20[802] * 0.94999999;
  v20[803] = v20[803] * 0.94999999;
  if ( (float)((float)((float)(v20[801] * v20[801]) + (float)(v20[802] * v20[802])) + (float)(v20[803] * v20[803])) < 0.1 )
    *((Vector *)v20 + 267) = vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x10083AC0
// Name: public: virtual void C_RopeKeyframe::CPhysicsDelegate::ApplyConstraints(class CSimplePhysics::CNode __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_RopeKeyframe::CPhysicsDelegate::ApplyConstraints(
        C_RopeKeyframe::CPhysicsDelegate *this@<ecx>,
        CTraceFilterWorldOnly_vtbl *a2@<ebp>,
        CSimplePhysics::CNode *pNodes,
        int nNodes)
{
  float z; // esi
  bool v5; // zf
  int v6; // edi
  float *p_z; // esi
  float v8; // xmm3_4
  int v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  _DWORD *v16; // eax
  float v17; // xmm6_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  _DWORD *v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // ecx
  CSimplePhysics::CNode *v24; // edi
  int v25; // eax
  Vector v26; // [esp+24h] [ebp-E4h] BYREF
  CGameTrace trace; // [esp+30h] [ebp-D8h] BYREF
  float v28; // [esp+84h] [ebp-84h]
  float v29; // [esp+8Ch] [ebp-7Ch]
  float v30; // [esp+90h] [ebp-78h]
  float v31; // [esp+94h] [ebp-74h]
  unsigned int v32; // [esp+9Ch] [ebp-6Ch]
  unsigned int v33; // [esp+A0h] [ebp-68h]
  unsigned int v34; // [esp+A4h] [ebp-64h]
  int v35; // [esp+ACh] [ebp-5Ch]
  int v36; // [esp+B0h] [ebp-58h]
  int v37; // [esp+B4h] [ebp-54h]
  int v38; // [esp+BCh] [ebp-4Ch]
  char v39; // [esp+C0h] [ebp-48h]
  bool v40; // [esp+C1h] [ebp-47h]
  Vector v41; // [esp+D8h] [ebp-30h] BYREF
  Vector forward; // [esp+E4h] [ebp-24h] BYREF
  QAngle angles; // [esp+F0h] [ebp-18h] BYREF
  CTraceFilterWorldOnly traceFilter; // [esp+FCh] [ebp-Ch]
  int iIteration; // [esp+100h] [ebp-8h]
  int v46; // [esp+104h] [ebp-4h] BYREF
  int retaddr; // [esp+108h] [ebp+0h]

  traceFilter.__vftable = a2;
  iIteration = retaddr;
  z = *(float *)&this;
  v5 = (this->m_pKeyframe->m_RopeFlags & 4) == 0;
  LODWORD(angles.z) = this;
  if ( !v5 )
  {
    if ( rope_collide.m_pParent == nullptr )
      goto LABEL_23;
    if ( rope_collide.m_pParent->m_Value.m_nValue != 0 )
      goto LABEL_6;
  }
  if ( rope_collide.m_pParent != nullptr && rope_collide.m_pParent->m_Value.m_nValue == 2 )
  {
LABEL_6:
    v6 = 0;
    LODWORD(angles.x) = &CTraceFilterWorldOnly::`vftable';
    if ( nNodes > 0 )
    {
      p_z = &pNodes->m_vPrevPos.z;
      do
      {
        angles.y = 0.0;
        do
        {
          v8 = *(p_z - 2);
          v9 = *((int *)p_z - 1);
          v10 = *p_z;
          v11 = *(p_z - 3);
          v12 = *(p_z - 5) - v8;
          v30 = *(p_z - 4) - *(float *)&v9;
          v29 = v12;
          v31 = v11 - v10;
          v38 = 0;
          v40 = (float)((float)((float)(v30 * v30) + (float)(v12 * v12)) + (float)(v31 * v31)) != 0.0;
          v39 = 0;
          v35 = 0x40000000;
          v36 = 0x40000000;
          v37 = 0x40000000;
          *(float *)&trace.m_pEnt = v8;
          trace.hitbox = v9;
          v28 = v10;
          v32 = 0x80000000;
          v33 = 0x80000000;
          v34 = 0x80000000;
          enginetrace->TraceRay(
            this: enginetrace,
            a2: (const Ray_t *)&trace.m_pEnt,
            a3: 16395u,
            a4: (ITraceFilter *)&angles,
            a5: (CGameTrace *)&v26);
          if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
            DebugDrawLine(vecAbsStart: &v26, vecAbsEnd: &trace.startpos, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
          if ( trace.plane.normal.z == 1.0 )
            break;
          if ( trace.plane.normal.z == 0.0 || trace.plane.pad[0] != 0 || trace.plane.pad[1] != 0 )
          {
            v20 = (_DWORD *)(*(_DWORD *)(LODWORD(angles.z) + 4) + 4 * (v6 >> 5) + 2432);
            *v20 |= 1 << (v6 & 0x1F);
            *(p_z - 5) = *(p_z - 2);
            *(p_z - 4) = *(p_z - 1);
            *(p_z - 3) = *p_z;
            break;
          }
          v13 = *(p_z - 4) - (float)((float)(*(p_z - 4) - *(p_z - 1)) * 0.30000001);
          v14 = *(p_z - 3) - (float)((float)(*(p_z - 3) - *p_z) * 0.30000001);
          v15 = *(p_z - 5) - (float)((float)(*(p_z - 5) - *(p_z - 2)) * 0.30000001);
          v16 = (_DWORD *)(*(_DWORD *)(LODWORD(angles.z) + 4) + 4 * (v6 >> 5) + 2432);
          v17 = 2.2
              - (float)((float)((float)((float)(v13 * trace.endpos.y) + (float)(trace.endpos.x * v15))
                              + (float)(v14 * trace.endpos.z))
                      - trace.plane.normal.x);
          v18 = v13 + (float)(trace.endpos.y * v17);
          v19 = v14 + (float)(trace.endpos.z * v17);
          *(p_z - 5) = (float)(trace.endpos.x * v17) + v15;
          *(p_z - 4) = v18;
          *(p_z - 3) = v19;
          *v16 |= 1 << (v6 & 0x1F);
          ++LODWORD(angles.y);
        }
        while ( SLODWORD(angles.y) < 10 );
        if ( LODWORD(angles.y) == 10 )
        {
          *(p_z - 5) = *(p_z - 2);
          *(p_z - 4) = *(p_z - 1);
          *(p_z - 3) = *p_z;
        }
        ++v6;
        p_z += 9;
      }
      while ( v6 < nNodes );
      z = angles.z;
    }
  }
LABEL_23:
  v21 = *(_DWORD *)(LODWORD(z) + 4);
  if ( (*(_BYTE *)(v21 + 3176) & 1) != 0 )
  {
    C_RopeKeyframe::GetEndPointAttachment(
      this: (C_RopeKeyframe *)v21,
      a2: (int)&v46,
      iPt: 0,
      vPos: &pNodes->m_vPos,
      angle: (QAngle *)&forward);
    if ( (*(_BYTE *)(*(_DWORD *)(LODWORD(z) + 4) + 3176) & 4) != 0 )
    {
      if ( nNodes > 3 )
      {
        AngleVectors(angles: (const QAngle *)&forward, forward: &v41);
        v22 = nNodes - 2;
        if ( nNodes - 2 > 2 )
          v22 = 2;
        LockNodeDirection(
          pNodes,
          parity: 1,
          nFalloffNodes: v22,
          flLockAmount: g_flLockAmount,
          flLockFalloff: g_flLockFalloff,
          vIdealDir: &v41);
      }
      z = angles.z;
    }
  }
  v23 = *(_DWORD *)(LODWORD(z) + 4);
  if ( (*(_BYTE *)(v23 + 3176) & 2) != 0 )
  {
    v24 = &pNodes[nNodes - 1];
    C_RopeKeyframe::GetEndPointAttachment(
      this: (C_RopeKeyframe *)v23,
      a2: (int)&v46,
      iPt: 1,
      vPos: &v24->m_vPos,
      angle: (QAngle *)&forward);
    if ( (*(_BYTE *)(*(_DWORD *)(LODWORD(z) + 4) + 3176) & 8) != 0 && nNodes > 3 )
    {
      AngleVectors(angles: (const QAngle *)&forward, forward: &v41);
      v25 = nNodes - 2;
      if ( nNodes - 2 > 2 )
        v25 = 2;
      LockNodeDirection(
        pNodes: v24,
        parity: -1,
        nFalloffNodes: v25,
        flLockAmount: g_flLockAmount,
        flLockFalloff: g_flLockFalloff,
        vIdealDir: &v41);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083EF0
// Name: public: virtual void C_RopeKeyframe::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_RopeKeyframe::OnDataChanged(
        C_RopeKeyframe *this@<ecx>,
        const char *a2@<ebx>,
        DataUpdateType_t updateType)
{
  void (__thiscall *v4)(char *, int); // edx
  const struct model_t *v5; // eax
  char *v6; // eax
  const char *v7; // ecx
  char *v8; // eax
  char str[512]; // [esp+10h] [ebp-200h] BYREF

  C_BaseEntity::OnDataChanged(this, type: updateType);
  v4 = *(void (__thiscall **)(char *, int))(*((_DWORD *)this - 2) + 456);
  BYTE1(this->m_vCachedEndPointAttachmentAngle[1].y) |= 4u;
  v4(a1: (char *)this - 8, a2: -996040704);
  if ( updateType == DATA_UPDATE_CREATED )
  {
    v5 = modelinfo->GetModel(this: modelinfo, a2: LODWORD(this->m_flScrollSpeed));
    if ( v5 != nullptr )
    {
      v6 = (char *)modelinfo->GetModelName(this: modelinfo, a2: v5);
      V_strncpy(pDest: str, pSrc: v6, maxLen: 512);
      v8 = V_stristr(a1: v7, a2, pStr: str, pSearch: ".vmt");
      if ( v8 != nullptr )
        *v8 = 0;
    }
    else
    {
      V_strncpy(pDest: str, pSrc: "missing_rope_material", maxLen: 512);
    }
    C_RopeKeyframe::FinishInit(this: (C_RopeKeyframe *)((char *)this - 8), pMaterialName: str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083FB0
// Name: private: void C_RopeKeyframe::RunRopeSimulation(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_RopeKeyframe::RunRopeSimulation(C_RopeKeyframe *this, float flSeconds)
{
  int i; // eax
  CBitVec<10> *v4; // edx
  char v5; // cl
  int v6; // eax

  for ( i = 0; i < this->m_nSegments; v4->m_Ints[0] &= ~(1 << v5) )
  {
    v4 = &this->m_LinksTouchingSomething + (i >> 5);
    v5 = i++ & 0x1F;
  }
  CBaseRopePhysics::Simulate(this: &this->m_RopePhysics, dt: flSeconds);
  v6 = 0;
  for ( this->m_nLinksTouchingSomething = 0; v6 < this->m_nSegments; ++v6 )
  {
    if ( ((1 << (v6 & 0x1F)) & this->m_LinksTouchingSomething.m_Ints[v6 >> 5]) != 0 )
      ++this->m_nLinksTouchingSomething;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084040
// Name: public: virtual bool C_RopeKeyframe::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_RopeKeyframe::ShouldDraw(C_RopeKeyframe *this)
{
  bool result; // al
  CPULevel_t ActualCPULevel; // eax
  bool m_bIsPlayerSimulated; // cl
  bool m_Value; // cl
  GPULevel_t GPULevel; // eax
  bool v7; // cl
  bool v8; // cl

  result = false;
  if ( r_ropetranslucent.m_pParent != nullptr
    && r_ropetranslucent.m_pParent->m_Value.m_nValue != 0
    && (LOBYTE(this->m_flScrollSpeed) & 8) != 0 )
  {
    ActualCPULevel = GetActualCPULevel();
    m_bIsPlayerSimulated = this->m_bIsPlayerSimulated;
    if ( !m_bIsPlayerSimulated || m_bIsPlayerSimulated - 1 <= ActualCPULevel )
    {
      m_Value = this->m_bSimulatedEveryTick.m_Value;
      if ( !m_Value || m_Value - 1 >= ActualCPULevel )
      {
        GPULevel = GetGPULevel();
        v7 = this->m_bAnimatedEveryTick.m_Value;
        if ( !v7 || v7 - 1 <= GPULevel )
        {
          v8 = this->m_bAlternateSorting.m_Value;
          if ( !v8 || v8 - 1 >= GPULevel )
            return true;
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100840C0
// Name: private: bool C_RopeKeyframe::AnyPointsMoved(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_RopeKeyframe::AnyPointsMoved(C_RopeKeyframe *this)
{
  int m_nNodes; // edi
  int v2; // edx
  CSimplePhysics::CNode *m_pNodes; // esi
  float *p_z; // eax
  int m_iForcePointMoveCounter; // eax

  m_nNodes = this->m_RopePhysics.m_nNodes;
  v2 = 0;
  if ( m_nNodes <= 0 )
  {
LABEL_5:
    m_iForcePointMoveCounter = this->m_iForcePointMoveCounter;
    if ( m_iForcePointMoveCounter < 0 )
    {
      return 0;
    }
    else
    {
      this->m_iForcePointMoveCounter = m_iForcePointMoveCounter - 1;
      return 1;
    }
  }
  else
  {
    m_pNodes = this->m_RopePhysics.m_pNodes;
    p_z = &m_pNodes->m_vPrevPos.z;
    while ( (float)((float)((float)((float)(*(p_z - 4) - *(p_z - 1)) * (float)(*(p_z - 4) - *(p_z - 1)))
                          + (float)((float)(m_pNodes->m_vPos.x - *(p_z - 2)) * (float)(m_pNodes->m_vPos.x - *(p_z - 2))))
                  + (float)((float)(*(p_z - 3) - *p_z) * (float)(*(p_z - 3) - *p_z))) <= 0.25 )
    {
      ++v2;
      ++m_pNodes;
      p_z += 9;
      if ( v2 >= m_nNodes )
        goto LABEL_5;
    }
    if ( this->m_iForcePointMoveCounter < 5 )
      this->m_iForcePointMoveCounter = 5;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084160
// Name: private: bool C_RopeKeyframe::DidEndPointMove(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_RopeKeyframe::DidEndPointMove(C_RopeKeyframe *this, int iPt)
{
  float z; // eax
  __int64 v6; // xmm0_8
  Vector *v7; // ebx
  char EndPointPos; // al
  float vOld_8; // [esp+10h] [ebp-4h]
  bool bOld_3; // [esp+1Fh] [ebp+Bh]

  if ( ((1 << iPt) & this->m_fLockedPoints) == 0 )
    return false;
  z = this->m_vPrevEndPointPos[iPt].z;
  v6 = *(_QWORD *)&this->m_vPrevEndPointPos[iPt].x;
  v7 = &this->m_vPrevEndPointPos[iPt];
  bOld_3 = this->m_bPrevEndPointPos[iPt];
  vOld_8 = z;
  EndPointPos = C_RopeKeyframe::GetEndPointPos(this, a2: (int)v7, iPt, vPos: v7);
  this->m_bPrevEndPointPos[iPt] = EndPointPos;
  return !bOld_3 && EndPointPos == 0
      || fabs(*(float *)&v6 - v7->x) > 0.1
      || fabs(*((float *)&v6 + 1) - this->m_vPrevEndPointPos[iPt].y) > 0.1
      || fabs(vOld_8 - this->m_vPrevEndPointPos[iPt].z) > 0.1;
}

//------------------------------------------------------------------------------
// Address: 0x10084230
// Name: private: bool C_RopeKeyframe::DetectRestingState(bool __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_RopeKeyframe::DetectRestingState(C_RopeKeyframe *this, bool *bApplyWind)
{
  int m_fLockedPoints; // eax
  const Vector *v6; // eax
  double v7; // st7
  float v8; // xmm0_4
  float x; // xmm0_4
  CSimplePhysics::CNode *m_pNodes; // [esp-Ch] [ebp-18h]
  CSimplePhysics::CNode *v11; // [esp-8h] [ebp-14h]
  float d; // [esp+14h] [ebp+8h]

  *bApplyWind = false;
  m_fLockedPoints = this->m_fLockedPoints;
  if ( this->m_fPrevLockedPoints != m_fLockedPoints )
  {
    this->m_iForcePointMoveCounter = 10;
    this->m_fPrevLockedPoints = m_fLockedPoints;
    return false;
  }
  if ( (*((_BYTE *)this + 3313) & 4) != 0
    || C_RopeKeyframe::DidEndPointMove(this, iPt: 0)
    || C_RopeKeyframe::DidEndPointMove(this, iPt: 1) )
  {
    return false;
  }
  if ( (this->m_RopeFlags & 0x20) != 0 )
  {
    v11 = &this->m_RopePhysics.m_pNodes[this->m_RopePhysics.m_nNodes - 1];
    m_pNodes = this->m_RopePhysics.m_pNodes;
    v6 = MainViewOrigin(nSlot: 0);
    v7 = CalcDistanceToLineSegment(P: v6, vLineA: &m_pNodes->m_vPos, vLineB: &v11->m_vPos, outT: nullptr);
    if ( v7 >= 3.4028235e38 )
    {
      v8 = 3.4028235e38;
    }
    else
    {
      d = v7;
      v8 = d;
    }
    if ( this->m_nLinksTouchingSomething < this->m_RopePhysics.m_nNodes >> 1 )
      *bApplyWind = rope_wind_dist.m_pParent->m_Value.m_fValue > v8;
  }
  x = this->m_vecImpulse.x;
  if ( x == this->m_vecPreviousImpulse.x
    && this->m_vecImpulse.y == this->m_vecPreviousImpulse.y
    && this->m_vecImpulse.z == this->m_vecPreviousImpulse.z )
  {
    return C_RopeKeyframe::AnyPointsMoved(this) == 0
        && !*bApplyWind
        && (rope_shake.m_pParent == nullptr || rope_shake.m_pParent->m_Value.m_nValue == 0);
  }
  this->m_vecPreviousImpulse.x = x;
  this->m_vecPreviousImpulse.y = this->m_vecImpulse.y;
  this->m_vecPreviousImpulse.z = this->m_vecImpulse.z;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100843B0
// Name: private: bool C_RopeKeyframe::InitRopePhysics(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_RopeKeyframe::InitRopePhysics(C_RopeKeyframe *this)
{
  char result; // al
  Vector *m_vPrevEndPointPos; // ebx
  Vector *v4; // edi
  char EndPointPos; // al
  int v6; // ecx
  CSimplePhysics::CNode *v7; // eax
  float v8; // xmm0_4
  double x; // st7
  IUniformRandomStream *v10; // ecx
  int v11; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  if ( (this->m_RopeFlags & 8) == 0 )
    return 0;
  if ( (*((_BYTE *)this + 3313) & 8) != 0 )
    return 1;
  m_vPrevEndPointPos = this->m_vPrevEndPointPos;
  result = C_RopeKeyframe::GetEndPointPos(
             this,
             a2: (int)this->m_vPrevEndPointPos,
             iPt: 0,
             vPos: this->m_vPrevEndPointPos);
  this->m_bPrevEndPointPos[0] = result;
  if ( result != 0 )
  {
    v4 = &this->m_vPrevEndPointPos[1];
    EndPointPos = C_RopeKeyframe::GetEndPointPos(
                    this,
                    a2: (int)m_vPrevEndPointPos,
                    iPt: 1,
                    vPos: &this->m_vPrevEndPointPos[1]);
    this->m_bPrevEndPointPos[1] = EndPointPos;
    if ( EndPointPos == 0 )
    {
      v4->x = m_vPrevEndPointPos->x;
      this->m_vPrevEndPointPos[1].y = this->m_vPrevEndPointPos[0].y;
      this->m_vPrevEndPointPos[1].z = this->m_vPrevEndPointPos[0].z;
    }
    CBaseRopePhysics::SetupSimulation(
      this: &this->m_RopePhysics,
      flSpringDist: 0.0,
      pDelegate: &this->m_PhysicsDelegate);
    CBaseRopePhysics::ResetSpringLength(
      this: &this->m_RopePhysics,
      flSpringDist: (float)((this->m_Slack + this->m_RopeLength - 100) / (this->m_RopePhysics.m_nNodes - 1)));
    CBaseRopePhysics::Restart(this: &this->m_RopePhysics);
    v6 = 0;
    if ( this->m_RopePhysics.m_nNodes > 0 )
    {
      v11 = 0;
      do
      {
        v7 = &this->m_RopePhysics.m_pNodes[v11++];
        v8 = (float)v6 / (float)(this->m_RopePhysics.m_nNodes - 1);
        v7->m_vPos.x = (float)((float)(v4->x - m_vPrevEndPointPos->x) * v8) + m_vPrevEndPointPos->x;
        x = v7->m_vPos.x;
        v7->m_vPos.y = (float)((float)(this->m_vPrevEndPointPos[1].y - this->m_vPrevEndPointPos[0].y) * v8)
                     + this->m_vPrevEndPointPos[0].y;
        v7->m_vPos.z = (float)((float)(this->m_vPrevEndPointPos[1].z - this->m_vPrevEndPointPos[0].z) * v8)
                     + this->m_vPrevEndPointPos[0].z;
        v7->m_vPrevPos.x = x;
        ++v6;
        v7->m_vPrevPos.y = v7->m_vPos.y;
        v7->m_vPrevPos.z = v7->m_vPos.z;
      }
      while ( v6 < this->m_RopePhysics.m_nNodes );
    }
    if ( (this->m_RopeFlags & 0x40) != 0 )
      C_RopeKeyframe::RunRopeSimulation(this, flSeconds: 5.0);
    C_RopeKeyframe::CalcLightValues(this, a2: (int)&savedregs);
    C_RopeKeyframe::UpdateBBox(this);
    this->m_flTimeToNextGust = _RandomFloat(this: v10, a2: 1.0, a3: 3.0);
    *((_BYTE *)this + 3313) |= 8u;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100848B0
// Name: public: void CRopeManager::RemoveRopeFromQueuedRenderCaches(class C_RopeKeyframe __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeManager::RemoveRopeFromQueuedRenderCaches(CRopeManager *this, C_RopeKeyframe *pRope)
{
  CRopeManager *v2; // esi
  CThreadFastMutex *p_m_RopeQueuedRenderCaches_Mutex; // ebx
  DWORD CurrentThreadId; // ecx
  unsigned __int16 k; // cx
  int v6; // eax
  char *v7; // edi
  CRopeManager::RopeRenderData_t *v8; // ebx
  int v9; // esi
  DWORD v10; // ecx
  int v11; // eax
  bool v12; // zf
  int v13; // [esp+10h] [ebp-20h]
  CThreadFastMutex *generated_id_18; // [esp+14h] [ebp-1Ch]
  int i; // [esp+1Ch] [ebp-14h]
  int j; // [esp+20h] [ebp-10h]
  CRopeManager::RopeRenderData_t *pCache; // [esp+24h] [ebp-Ch]
  int v19; // [esp+28h] [ebp-8h]
  C_RopeKeyframe **m_aCache; // [esp+2Ch] [ebp-4h]

  v2 = this;
  p_m_RopeQueuedRenderCaches_Mutex = &this->m_RopeQueuedRenderCaches_Mutex;
  generated_id_18 = &this->m_RopeQueuedRenderCaches_Mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_RopeQueuedRenderCaches_Mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_RopeQueuedRenderCaches_Mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_RopeQueuedRenderCaches_Mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_RopeQueuedRenderCaches_Mutex->m_depth;
  }
  for ( k = v2->m_RopeQueuedRenderCaches.m_Head;
        k < v2->m_RopeQueuedRenderCaches.m_Memory.m_nAllocationCount;
        k = *(unsigned __int16 *)((char *)&v2->m_RopeQueuedRenderCaches.m_Memory.m_pMemory->m_Next + v6) )
  {
    if ( k > v2->m_RopeQueuedRenderCaches.m_LastAlloc.index )
      break;
    v6 = 16 * k;
    v7 = (char *)v2->m_RopeQueuedRenderCaches.m_Memory.m_pMemory + v6;
    v13 = v6;
    if ( *((_WORD *)v7 + 6) == k && *((_WORD *)v7 + 7) != k )
      break;
    i = 0;
    if ( *((_DWORD *)v7 + 1) == 0 )
      continue;
    v19 = 0;
    do
    {
      v8 = (CRopeManager::RopeRenderData_t *)(v19 + *(_DWORD *)v7);
      j = 0;
      pCache = v8;
      if ( v8->m_nCacheCount == 0 )
        goto LABEL_24;
      m_aCache = v8->m_aCache;
      do
      {
        if ( *m_aCache != pRope )
          goto LABEL_22;
        v9 = *((_DWORD *)v7 + 2);
        v10 = GetCurrentThreadId();
        if ( v10 == *(_DWORD *)v9 )
          goto LABEL_18;
        if ( _InterlockedCompareExchange((volatile signed __int32 *)v9, v10, 0) == 0 )
        {
          v8 = pCache;
LABEL_18:
          ++*(_DWORD *)(v9 + 4);
          goto LABEL_20;
        }
        _mm_pause();
        CThreadFastMutex::Lock(a1: v9, a2: v10, a3: 0);
        v8 = pCache;
LABEL_20:
        *m_aCache = nullptr;
        v11 = *((_DWORD *)v7 + 2);
        v12 = (*(_DWORD *)(v11 + 4))-- == 1;
        if ( v12 )
          _InterlockedExchange((volatile __int32 *)v11, 0);
LABEL_22:
        ++m_aCache;
        ++j;
      }
      while ( j != v8->m_nCacheCount );
      v2 = this;
LABEL_24:
      v19 += 520;
      ++i;
    }
    while ( i != *((_DWORD *)v7 + 1) );
    p_m_RopeQueuedRenderCaches_Mutex = generated_id_18;
    v6 = v13;
  }
  v12 = p_m_RopeQueuedRenderCaches_Mutex->m_depth-- == 1;
  if ( v12 )
    _InterlockedExchange((volatile __int32 *)p_m_RopeQueuedRenderCaches_Mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10084A20
// Name: void ShakeRopesCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShakeRopesCallback(const CEffectData *data)
{
  float z; // ecx
  int m_Head; // esi
  float m_flMagnitude; // xmm0_4
  UtlLinkedListElem_t<C_RopeKeyframe *,int> *m_pMemory; // eax
  int v5; // esi
  Vector vCenter; // [esp+Ch] [ebp-10h] BYREF
  float flRadius; // [esp+18h] [ebp-4h]

  z = data->m_vOrigin.z;
  *(_QWORD *)&vCenter.x = *(_QWORD *)&data->m_vOrigin.x;
  m_Head = g_Ropes.m_Head;
  flRadius = data->m_flRadius;
  m_flMagnitude = data->m_flMagnitude;
  vCenter.z = z;
  if ( g_Ropes.m_Head != -1 )
  {
    m_pMemory = g_Ropes.m_Memory.m_pMemory;
    do
    {
      v5 = m_Head;
      C_RopeKeyframe::ShakeRope(this: m_pMemory[v5].m_Element, &vCenter, flRadius, flMagnitude: m_flMagnitude);
      m_pMemory = g_Ropes.m_Memory.m_pMemory;
      m_Head = g_Ropes.m_Memory.m_pMemory[v5].m_Next;
    }
    while ( m_Head != -1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084AA0
// Name: public: virtual void C_RopeKeyframe::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_RopeKeyframe::ClientThink(C_RopeKeyframe *this)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  float v4; // xmm1_4
  IUniformRandomStream *v5; // ecx
  double v6; // st7
  IUniformRandomStream *v7; // ecx
  IUniformRandomStream *v8; // ecx
  Vector result; // [esp+14h] [ebp-Ch] BYREF

  BYTE1(this->m_vCachedEndPointAttachmentAngle[1].x) |= 3u;
  if ( C_RopeKeyframe::InitRopePhysics(this: (C_RopeKeyframe *)((char *)this - 12)) != 0
    && r_drawropes.m_pParent != nullptr
    && r_drawropes.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( C_RopeKeyframe::DetectRestingState(
           this: (C_RopeKeyframe *)((char *)this - 12),
           bApplyWind: &this->m_bIsBlurred + 4) )
    {
      if ( (LOBYTE(this->m_vPrevEndPointPos[1].z) & 0x20) == 0 )
        (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 3) + 456))(a1: (char *)this - 12, a2: -1082130432);
    }
    else
    {
      C_RopeKeyframe::RunRopeSimulation(
        this: (C_RopeKeyframe *)((char *)this - 12),
        flSeconds: *(float *)(gpGlobals.m_Index + 16));
      g_nRopePointsSimulated += (int)this->m_RopePhysics.__vftable;
      BYTE1(this->m_vCachedEndPointAttachmentAngle[1].x) &= ~4u;
      if ( *(&this->m_bIsBlurred + 4) )
      {
        this->m_vecPreviousImpulse.x = *(float *)(gpGlobals.m_Index + 16) + this->m_vecPreviousImpulse.x;
        v2 = this->m_vecPreviousImpulse.z - *(float *)(gpGlobals.m_Index + 16);
        this->m_vecPreviousImpulse.z = v2;
        if ( v2 <= 0.0 )
        {
          *(Vector *)&this->m_flCurrentGustTimer = *RandomVector(&result, minVal: -1.0, maxVal: 1.0);
          VectorNormalize(vec: (Vector *)&this->m_flCurrentGustTimer);
          v3 = basicScale;
          this->m_flCurrentGustTimer = basicScale * this->m_flCurrentGustTimer;
          v4 = v3 * this->m_flCurrentGustLifetime;
          this->m_flTimeToNextGust = v3 * this->m_flTimeToNextGust;
          this->m_flCurrentGustLifetime = v4;
          v6 = _RandomFloat(this: v5, a2: -1.0, a3: 1.0);
          this->m_flCurrentGustTimer = v6 * this->m_flCurrentGustTimer;
          this->m_flCurrentGustLifetime = v6 * this->m_flCurrentGustLifetime;
          this->m_flTimeToNextGust = v6 * this->m_flTimeToNextGust;
          this->m_vecPreviousImpulse.x = 0.0;
          this->m_vecPreviousImpulse.y = _RandomFloat(this: v7, a2: 2.0, a3: 3.0);
          this->m_vecPreviousImpulse.z = _RandomFloat(this: v8, a2: 3.0, a3: 4.0);
        }
      }
      C_RopeKeyframe::UpdateBBox(this: (C_RopeKeyframe *)((char *)this - 12));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084CB0
// Name: public: virtual int C_RopeKeyframe::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_RopeKeyframe::DrawModel(C_RopeKeyframe *this, int flags, const RenderableInstance_t *instance)
{
  unsigned int m_nSegments; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax
  IHandleEntity *v11; // eax
  C_BaseCombatWeapon *v12; // eax
  C_BaseCombatWeapon *v13; // eax
  C_BaseCombatWeapon *v14; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_RopeKeyframe::DrawModel",
    a3: 0,
    a4: "Ropes",
    a5: false,
    a6: 4);
  if ( C_RopeKeyframe::InitRopePhysics(this: (C_RopeKeyframe *)((char *)this - 4)) == 0
    || LOBYTE(this->m_VisibilityBits.m_Ints[0]) == 0 )
  {
    goto LABEL_17;
  }
  if ( (LOBYTE(this->m_flScrollSpeed) & 1) != 0 )
    CBaseRopePhysics::ResetSpringLength(
      this: (CBaseRopePhysics *)&this->m_iRopeMaterialModelIndex,
      flSpringDist: (float)((this->m_RopeLength + this->m_Subdiv - 100) / ((int)&this->m_RopePhysics.m_pNodes[-1].m_vPredicted.z + 3)));
  m_nSegments = this->m_nSegments;
  if ( m_nSegments == -1 )
    goto LABEL_18;
  v5 = (unsigned __int16)m_nSegments;
  v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_nSegments];
  v7 = HIWORD(m_nSegments);
  if ( v6->m_SerialNumber != v7 || v6->m_pEntity == nullptr )
    goto LABEL_18;
  v8 = v5;
  v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
  v10 = &g_pEntityList->m_EntPtrArray[v8];
  v11 = v9 ? v10->m_pEntity : nullptr;
  if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))v11[2].__vftable[3].dtr_IHandleEntity)(a1: &v11[2]) != 0
    && CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_hStartPoint) != nullptr
    && (v12 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_hStartPoint),
        v12->IsDormant(this: &v12->IClientNetworkable))
    && (v13 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_nSegments),
        C_BaseEntity::GetModelIndex(this: v13) != 0)
    && (v14 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_hStartPoint),
        C_BaseEntity::GetModelIndex(this: v14) != 0) )
  {
LABEL_17:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
  else
  {
LABEL_18:
    C_RopeKeyframe::ConstrainNodesBetweenEndpoints(this: (C_RopeKeyframe *)((char *)this - 4));
    s_RopeManager.AddToRenderCache(this: &s_RopeManager, a2: (C_RopeKeyframe *)((char *)this - 4));
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084E40
// Name: public: virtual void CMemberFunctor7<class CRopeManager __near *,void (CRopeManager::*)(bool,struct CRopeManager::RopeRenderData_t __near *,int,class Vector const __near &,class Vector const __near &,struct C_RopeKeyframe::BuildRopeQueuedData_t __near *,class CThreadFastMutex __near *),bool,struct CRopeManager::RopeRenderData_t __near *,int,class Vector,class Vector,struct C_RopeKeyframe::BuildRopeQueuedData_t __near *,class CThreadFastMutex __near *,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor7<CRopeManager *,void (__thiscall CRopeManager::*)(bool,CRopeManager::RopeRenderData_t *,int,Vector const &,Vector const &,C_RopeKeyframe::BuildRopeQueuedData_t *,CThreadFastMutex *),bool,CRopeManager::RopeRenderData_t *,int,Vector,Vector,C_RopeKeyframe::BuildRopeQueuedData_t *,CThreadFastMutex *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor7<CRopeManager *,void (__thiscall CRopeManager::*)(bool,CRopeManager::RopeRenderData_t *,int,Vector const &,Vector const &,C_RopeKeyframe::BuildRopeQueuedData_t *,CThreadFastMutex *),bool,CRopeManager::RopeRenderData_t *,int,Vector,Vector,C_RopeKeyframe::BuildRopeQueuedData_t *,CThreadFastMutex *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, bool, CRopeManager::RopeRenderData_t *, int, Vector *, Vector *, C_RopeKeyframe::BuildRopeQueuedData_t *, CThreadFastMutex *))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1,
    a3: this->m_arg2,
    a4: this->m_arg3,
    a5: &this->m_arg4,
    a6: &this->m_arg5,
    a7: this->m_arg6,
    a8: this->m_arg7);
}

//------------------------------------------------------------------------------
// Address: 0x10084F00
// Name: public: CRopeManager::CRopeManager(void)
// Source: json
//------------------------------------------------------------------------------
CRopeManager *__thiscall CRopeManager::CRopeManager(CRopeManager *this)
{
  UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short> *m_pMemory; // eax

  this->__vftable = (CRopeManager_vtbl *)&CRopeManager::`vftable';
  this->m_aRenderCache.m_Memory.m_pMemory = nullptr;
  this->m_aRenderCache.m_Memory.m_nAllocationCount = 0;
  this->m_aRenderCache.m_Memory.m_nGrowSize = 0;
  this->m_aRenderCache.m_Size = 0;
  this->m_aRenderCache.m_pElements = nullptr;
  this->m_RopeQueuedRenderCaches.m_Memory.m_pMemory = nullptr;
  this->m_RopeQueuedRenderCaches.m_Memory.m_nAllocationCount = 0;
  this->m_RopeQueuedRenderCaches.m_Memory.m_nGrowSize = 0;
  this->m_RopeQueuedRenderCaches.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_RopeQueuedRenderCaches.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_RopeQueuedRenderCaches.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_RopeQueuedRenderCaches.m_Head = -1;
  this->m_RopeQueuedRenderCaches.m_NumAlloced = 0;
  this->m_RopeQueuedRenderCaches.m_pElements = m_pMemory;
  this->m_RopeQueuedRenderCaches_Mutex.m_ownerID = 0;
  this->m_RopeQueuedRenderCaches_Mutex.m_depth = 0;
  this->m_aRenderCache.m_Size = 0;
  if ( this->m_aRenderCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aRenderCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aRenderCache.m_Memory.m_pMemory);
      this->m_aRenderCache.m_Memory.m_pMemory = nullptr;
    }
    this->m_aRenderCache.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aRenderCache.m_pElements = this->m_aRenderCache.m_Memory.m_pMemory;
  this->m_pDepthWriteMaterial = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10084F80
// Name: public: virtual CRopeManager::~CRopeManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeManager::~CRopeManager(CRopeManager *this)
{
  this->__vftable = (CRopeManager_vtbl *)&CRopeManager::`vftable';
  this->m_aRenderCache.m_Size = 0;
  if ( this->m_aRenderCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aRenderCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aRenderCache.m_Memory.m_pMemory);
      this->m_aRenderCache.m_Memory.m_pMemory = nullptr;
    }
    this->m_aRenderCache.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aRenderCache.m_pElements = this->m_aRenderCache.m_Memory.m_pMemory;
  CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_RopeQueuedRenderCaches);
  if ( this->m_RopeQueuedRenderCaches.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RopeQueuedRenderCaches.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RopeQueuedRenderCaches.m_Memory.m_pMemory);
      this->m_RopeQueuedRenderCaches.m_Memory.m_pMemory = nullptr;
    }
    this->m_RopeQueuedRenderCaches.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_aRenderCache);
  this->__vftable = (CRopeManager_vtbl *)&IRopeManager::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10085030
// Name: public: virtual void CRopeManager::AddToRenderCache(class C_RopeKeyframe __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeManager::AddToRenderCache(CRopeManager *this, C_RopeKeyframe *pRope)
{
  IMaterial *m_pMaterial; // esi
  int m_Size; // eax
  int v4; // edi
  CRopeManager::RopeRenderData_t *m_pMemory; // edx
  int m_nAllocationCount; // eax
  CUtlVector<CRopeManager::RopeRenderData_t,CUtlMemory<CRopeManager::RopeRenderData_t,int> > *p_m_aRenderCache; // esi
  int v8; // ebx
  CRopeManager::RopeRenderData_t *v9; // edx
  int v10; // eax
  int v11; // ebx
  CRopeManager::RopeRenderData_t *v12; // edx
  int v13; // eax
  CRopeManager *v14; // [esp+4h] [ebp-4h]

  m_pMaterial = pRope->m_pMaterial;
  v14 = this;
  if ( m_pMaterial != nullptr )
  {
    m_Size = this->m_aRenderCache.m_Size;
    v4 = 0;
    if ( m_Size > 0 )
    {
      m_pMemory = this->m_aRenderCache.m_Memory.m_pMemory;
      do
      {
        if ( m_pMaterial == m_pMemory->m_pSolidMaterial )
          break;
        ++v4;
        ++m_pMemory;
      }
      while ( v4 < m_Size );
    }
    if ( v4 == m_Size )
    {
      m_nAllocationCount = this->m_aRenderCache.m_Memory.m_nAllocationCount;
      p_m_aRenderCache = &this->m_aRenderCache;
      v8 = this->m_aRenderCache.m_Size;
      if ( v8 + 1 > m_nAllocationCount )
      {
        CUtlMemory<CRopeManager::RopeRenderData_t,int>::Grow(
          this: &this->m_aRenderCache.m_Memory,
          num: v8 - m_nAllocationCount + 1);
        this = v14;
      }
      ++p_m_aRenderCache->m_Size;
      v9 = p_m_aRenderCache->m_Memory.m_pMemory;
      v10 = p_m_aRenderCache->m_Size - v8 - 1;
      p_m_aRenderCache->m_pElements = p_m_aRenderCache->m_Memory.m_pMemory;
      if ( v10 > 0 )
      {
        _V_memmove(dest: &v9[v8 + 1], src: &v9[v8], count: 520 * v10);
        this = v14;
      }
      v11 = v8;
      p_m_aRenderCache->m_Memory.m_pMemory[v11].m_pSolidMaterial = pRope->m_pMaterial;
      p_m_aRenderCache->m_Memory.m_pMemory[v11].m_nCacheCount = 0;
    }
    v12 = this->m_aRenderCache.m_Memory.m_pMemory;
    v13 = v4;
    if ( v12[v4].m_nCacheCount < 128 )
    {
      v12[v4].m_aCache[v12[v13].m_nCacheCount] = pRope;
      ++this->m_aRenderCache.m_Memory.m_pMemory[v13].m_nCacheCount;
    }
    else
    {
      _Warning(a1: "CRopeManager::AddToRenderCache count to large for cache!\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085130
// Name: private: void CRopeManager::DrawRenderCache_NonQueued(bool,struct CRopeManager::RopeRenderData_t __near *,int,class Vector const __near &,class Vector const __near &,struct C_RopeKeyframe::BuildRopeQueuedData_t __near *,class CThreadFastMutex __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeManager::DrawRenderCache_NonQueued(
        CRopeManager *this,
        __int16 bShadowDepth,
        CRopeManager::RopeRenderData_t *pRenderCache,
        int nRenderCacheCount,
        const Vector *vCurrentViewForward,
        const Vector *vCurrentViewOrigin,
        C_RopeKeyframe::BuildRopeQueuedData_t *pBuildRopeQueuedData,
        CThreadFastMutex *pRopeDataMutex)
{
  CThreadFastMutex *p_dummyMutex; // esi
  KeyValues *v10; // eax
  KeyValues *v11; // edi
  IMaterial *v12; // eax
  IMatRenderContext *v13; // eax
  IMatRenderContext *m_pObject; // edi
  DWORD CurrentThreadId; // eax
  int v16; // eax
  int v17; // edx
  IMesh *m_nCacheCount; // eax
  int v19; // esi
  float v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // ecx
  int v24; // eax
  IMaterial *v25; // esi
  int v26; // esi
  int (__thiscall *GetMaxIndicesToRender)(IMatRenderContext *); // edx
  IMesh *v28; // eax
  int v29; // esi
  int v30; // ecx
  int v31; // esi
  IMaterial *m_pSolidMaterial; // edi
  int v33; // eax
  int v34; // eax
  int v35; // edx
  float v36; // xmm1_4
  float w; // xmm6_4
  int v38; // ebx
  float v39; // edx
  IMaterial_vtbl *v40; // ebx
  float v41; // xmm2_4
  IMaterial_vtbl *v42; // edx
  float z; // xmm5_4
  float x; // xmm3_4
  float y; // xmm4_4
  float v46; // xmm0_4
  __m128i v47; // xmm1
  float v48; // xmm0_4
  float v49; // xmm1_4
  float v50; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm7_4
  int v53; // ebx
  float v54; // xmm0_4
  float *v55; // edi
  float *v56; // eax
  int m_nVertexCount; // eax
  int v58; // edx
  signed int v59; // ecx
  int v60; // edx
  int v61; // edi
  float v62; // xmm2_4
  float v63; // xmm0_4
  unsigned int v64; // eax
  float *m_pCurrPosition; // ecx
  float *v66; // ecx
  float v67; // xmm1_4
  float *v68; // ecx
  float v69; // xmm7_4
  float *v70; // ecx
  int m_VertexSize_Position; // eax
  float *v72; // ecx
  float *v73; // eax
  float *v74; // eax
  float v75; // xmm0_4
  char *v76; // eax
  float *v77; // eax
  float v78; // xmm0_4
  float v79; // xmm0_4
  unsigned __int8 v80; // bl
  unsigned int v81; // edx
  float *v82; // eax
  float *v83; // eax
  float v84; // xmm1_4
  char *v85; // eax
  int v86; // edi
  float *v87; // eax
  float *v88; // eax
  float v89; // xmm7_4
  char *v90; // eax
  float v91; // xmm7_4
  float *v92; // eax
  bool v93; // zf
  __int16 v94; // ax
  int v95; // edx
  float v96; // xmm0_4
  float v97; // xmm0_4
  float v98; // xmm0_4
  float v99; // xmm0_4
  unsigned int v100; // edx
  float *v101; // eax
  int v102; // edi
  float *v103; // eax
  float v104; // xmm0_4
  char *v105; // eax
  float v106; // xmm0_4
  float *v107; // eax
  float *v108; // eax
  float *v109; // eax
  float v110; // xmm0_4
  char *v111; // eax
  float v112; // xmm0_4
  float *v113; // eax
  int v114; // eax
  int v115; // edx
  int v116; // eax
  signed int v117; // eax
  int v118; // eax
  CThreadFastMutex *p_m_RopeQueuedRenderCaches_Mutex; // esi
  DWORD v120; // eax
  int v121; // eax
  CThreadFastMutex *v122; // esi
  DWORD v123; // eax
  CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short> > *v124; // esi
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-2F0h] BYREF
  float flDU; // [esp+1F4h] [ebp-108h]
  Vector4D vecDelta; // [esp+1F8h] [ebp-104h]
  float v128; // [esp+208h] [ebp-F4h]
  int nMaxVertices; // [esp+20Ch] [ebp-F0h]
  float m_flTStep; // [esp+210h] [ebp-ECh]
  float v131; // [esp+214h] [ebp-E8h]
  int iRenderCache; // [esp+218h] [ebp-E4h]
  int nMaxIndices; // [esp+21Ch] [ebp-E0h]
  float v134; // [esp+220h] [ebp-DCh]
  CMatRenderContextPtr pRenderContext; // [esp+224h] [ebp-D8h]
  float flU; // [esp+228h] [ebp-D4h]
  Vector vColor0; // [esp+22Ch] [ebp-D0h]
  int nNumIndicesPerSegment; // [esp+238h] [ebp-C4h]
  float flLastU; // [esp+23Ch] [ebp-C0h]
  Vector4D vecP1; // [esp+240h] [ebp-BCh]
  Vector vModColor; // [esp+250h] [ebp-ACh]
  int nColor; // [esp+25Ch] [ebp-A0h]
  int defaultSubdiv; // [esp+260h] [ebp-9Ch]
  float flT; // [esp+264h] [ebp-98h]
  int v145; // [esp+268h] [ebp-94h]
  Vector vColor1; // [esp+26Ch] [ebp-90h]
  int nPnt; // [esp+278h] [ebp-84h]
  CThreadFastMutex dummyMutex; // [esp+27Ch] [ebp-80h] BYREF
  float *v149; // [esp+284h] [ebp-78h]
  int nTotalIndices; // [esp+288h] [ebp-74h]
  int m_aCache; // [esp+28Ch] [ebp-70h]
  int nSubdivCount; // [esp+290h] [ebp-6Ch]
  int nTotalVerts; // [esp+294h] [ebp-68h]
  int availableVerts; // [esp+298h] [ebp-64h]
  int availableIndices; // [esp+29Ch] [ebp-60h]
  int meshIndexCount; // [esp+2A0h] [ebp-5Ch]
  int nSegmentsToRender; // [esp+2A4h] [ebp-58h]
  int nSegmentsAvailableInBuffer; // [esp+2A8h] [ebp-54h]
  int nCacheCount; // [esp+2ACh] [ebp-50h]
  int nCurIDX; // [esp+2B0h] [ebp-4Ch]
  CRopeManager::RopeRenderData_t *v161; // [esp+2B4h] [ebp-48h]
  IMesh *pMesh; // [esp+2B8h] [ebp-44h]
  CRopeManager *v163; // [esp+2BCh] [ebp-40h]
  Vector4D vecP0; // [esp+2C0h] [ebp-3Ch]
  int meshVertCount; // [esp+2D0h] [ebp-2Ch]
  float *p_GetNumPasses; // [esp+2D4h] [ebp-28h]
  Vector4D vecP2; // [esp+2D8h] [ebp-24h]
  Vector4D vecP3; // [esp+2E8h] [ebp-14h]
  bool bFirstPoint; // [esp+2F8h] [ebp-4h]
  unsigned __int8 nBlue; // [esp+2F9h] [ebp-3h]
  unsigned __int8 nRed; // [esp+2FAh] [ebp-2h]
  unsigned __int8 nGreen; // [esp+2FBh] [ebp-1h]
  CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short> > *bShadowDeptha; // [esp+304h] [ebp+8h]
  unsigned __int16 bShadowDepthb; // [esp+304h] [ebp+8h]
  CThreadFastMutex *iHeadIndex; // [esp+30Ch] [ebp+10h]
  unsigned __int16 iHeadIndexa; // [esp+30Ch] [ebp+10h]
  CThreadFastMutex *pRopeDataMutexa; // [esp+31Ch] [ebp+20h]

  v163 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CRopeManager::DrawRenderCache",
    a3: 0,
    a4: "Ropes",
    a5: false,
    a6: 4);
  p_dummyMutex = pRopeDataMutex;
  dummyMutex.m_ownerID = 0;
  dummyMutex.m_depth = 0;
  if ( pRopeDataMutex == nullptr )
  {
    p_dummyMutex = &dummyMutex;
    pRopeDataMutex = &dummyMutex;
  }
  if ( (_BYTE)bShadowDepth != 0 && this->m_pDepthWriteMaterial == nullptr && g_pMaterialSystem != nullptr )
  {
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "DepthWrite");
    else
      v11 = nullptr;
    KeyValues::SetInt(this: v11, keyName: "$no_fullbright", value: 1);
    KeyValues::SetInt(this: v11, keyName: "$alphatest", value: 0);
    KeyValues::SetInt(this: v11, keyName: "$nocull", value: 1);
    v12 = g_pMaterialSystem->FindProceduralMaterial(
            this: g_pMaterialSystem,
            a2: "__DepthWrite01",
            a3: "Other textures",
            a4: v11);
    v163->m_pDepthWriteMaterial = v12;
  }
  v13 = materials->GetRenderContext(this: materials);
  m_pObject = v13;
  pRenderContext.m_pObject = v13;
  if ( v13 != nullptr )
    v13->BeginRender(this: v13);
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId == p_dummyMutex->m_ownerID )
    goto LABEL_15;
  if ( _InterlockedCompareExchange((volatile signed __int32 *)p_dummyMutex, CurrentThreadId, 0) == 0 )
  {
    p_dummyMutex = pRopeDataMutex;
LABEL_15:
    ++p_dummyMutex->m_depth;
    goto LABEL_17;
  }
  _mm_pause();
  p_dummyMutex = pRopeDataMutex;
  CThreadFastMutex::Lock(a1: pRopeDataMutex, a2: CurrentThreadId, a3: 0);
LABEL_17:
  if ( rope_subdiv.m_pParent != nullptr )
    defaultSubdiv = rope_subdiv.m_pParent->m_Value.m_nValue;
  else
    defaultSubdiv = 0;
  v16 = 0;
  iRenderCache = 0;
  if ( nRenderCacheCount <= 0 )
  {
LABEL_111:
    v93 = p_dummyMutex->m_depth-- == 1;
    if ( v93 )
      _InterlockedExchange((volatile __int32 *)p_dummyMutex, 0);
    p_m_RopeQueuedRenderCaches_Mutex = &v163->m_RopeQueuedRenderCaches_Mutex;
    iHeadIndex = &v163->m_RopeQueuedRenderCaches_Mutex;
    v120 = GetCurrentThreadId();
    if ( v120 != p_m_RopeQueuedRenderCaches_Mutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_RopeQueuedRenderCaches_Mutex, v120, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_RopeQueuedRenderCaches_Mutex, a2: v120, a3: 0);
    }
    else
    {
      ++p_m_RopeQueuedRenderCaches_Mutex->m_depth;
    }
    if ( pBuildRopeQueuedData != nullptr && v163->m_RopeQueuedRenderCaches.m_ElementCount != 0 )
    {
      v124 = (CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short> > *)v163;
      bShadowDepthb = v163->m_RopeQueuedRenderCaches.m_Head;
      pRopeDataMutexa = (CThreadFastMutex *)(16 * bShadowDepthb);
      C_BaseEntity::operator delete(pMem: *(void **)((char *)&pRopeDataMutexa[1].m_ownerID
                                                   + (unsigned int)v163->m_RopeQueuedRenderCaches.m_Memory.m_pMemory));
      CUtlLinkedList<CDataChangedEvent,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDataChangedEvent,unsigned short>,unsigned short>>::Unlink(
        this: v124 + 1,
        elem: bShadowDepthb);
      *(_WORD *)((char *)&pRopeDataMutexa[1].m_depth + (unsigned int)v124[1].m_Memory.m_pMemory + 2) = v124[1].m_FirstFree;
      v124[1].m_FirstFree = bShadowDepthb;
      p_m_RopeQueuedRenderCaches_Mutex = iHeadIndex;
    }
    v93 = p_m_RopeQueuedRenderCaches_Mutex->m_depth-- == 1;
    if ( v93 )
      _InterlockedExchange((volatile __int32 *)p_m_RopeQueuedRenderCaches_Mutex, 0);
    if ( m_pObject != nullptr )
      goto LABEL_151;
    goto LABEL_152;
  }
  while ( 1 )
  {
    v17 = 0;
    v161 = &pRenderCache[v16];
    m_nCacheCount = (IMesh *)v161->m_nCacheCount;
    v19 = 0;
    nCacheCount = (int)m_nCacheCount;
    if ( (int)m_nCacheCount <= 0 )
      goto LABEL_109;
    m_aCache = (int)v161->m_aCache;
    p_GetNumPasses = (float *)v161->m_aCache;
    for ( pMesh = m_nCacheCount; pMesh != nullptr; pMesh = (IMesh *)((char *)pMesh - 1) )
    {
      v20 = *p_GetNumPasses;
      if ( *(_DWORD *)p_GetNumPasses != 0 )
      {
        v21 = *(_DWORD *)(LODWORD(v20) + 2508);
        v22 = *(_DWORD *)(LODWORD(v20) + 3160);
        v23 = v21 - 1;
        if ( v22 == 255 )
          v22 = defaultSubdiv;
        v24 = v23 * (v22 + 1);
        v17 += 2 * v24 + 2;
        v19 += 6 * v24;
      }
      ++p_GetNumPasses;
    }
    nTotalIndices = v19;
    nTotalVerts = v17;
    if ( v17 == 0 )
      goto LABEL_109;
    v25 = (_BYTE)bShadowDepth != 0 ? g_pSplineCableShadowdepth : v161->m_pSolidMaterial;
    m_pObject->Bind(this: m_pObject, a2: v25, a3: nullptr);
    v26 = m_pObject->GetMaxVerticesToRender(this: m_pObject, a2: v25);
    GetMaxIndicesToRender = m_pObject->GetMaxIndicesToRender;
    nMaxVertices = v26;
    nMaxIndices = GetMaxIndicesToRender(this: m_pObject);
    v28 = m_pObject->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    pMesh = v28;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_bGenerateIndices = false;
    memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
    memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
    meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshVertCount = nTotalVerts >= v26 ? v26 : nTotalVerts;
    v29 = nMaxIndices;
    if ( nTotalIndices >= nMaxIndices )
    {
      meshIndexCount = nMaxIndices;
    }
    else
    {
      v29 = nTotalIndices;
      meshIndexCount = nTotalIndices;
    }
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh: v28,
      type: MATERIAL_TRIANGLES,
      nVertexCount: meshVertCount,
      nIndexCount: v29,
      pMeshSettings: nullptr);
    if ( meshBuilder.m_ActualVertexSize == 0 )
      break;
    availableVerts = meshVertCount;
    availableIndices = v29;
    v30 = 0;
    nCurIDX = 0;
    flLastU = 1.0;
    v31 = 0;
    v161 = (CRopeManager::RopeRenderData_t *)m_aCache;
    m_aCache = nCacheCount;
    do
    {
      m_pSolidMaterial = v161->m_pSolidMaterial;
      if ( v161->m_pSolidMaterial != nullptr )
      {
        v145 = (int)m_pSolidMaterial[627].__vftable;
        nSegmentsToRender = v145 - 1;
        if ( v145 != 1 )
        {
          v33 = (int)m_pSolidMaterial[790].__vftable;
          if ( v33 == 255 )
            v33 = defaultSubdiv;
          nSubdivCount = v33 + 1;
          nNumIndicesPerSegment = 6 * (v33 + 1);
          nCacheCount = (availableVerts - 2) / (2 * (v33 + 1));
          v34 = availableIndices / nNumIndicesPerSegment;
          if ( nCacheCount >= availableIndices / nNumIndicesPerSegment )
          {
            nSegmentsAvailableInBuffer = availableIndices / nNumIndicesPerSegment;
          }
          else
          {
            v34 = nCacheCount;
            nSegmentsAvailableInBuffer = nCacheCount;
          }
          v35 = nSegmentsToRender;
          if ( v34 < nSegmentsToRender )
            v35 = v34;
          availableIndices -= nNumIndicesPerSegment * v35;
          v36 = 4.0 / *(float *)&m_pSolidMaterial[793].__vftable;
          *(_QWORD *)&vModColor.x = *(_QWORD *)&m_pSolidMaterial[813].__vftable;
          w = *(float *)&m_pSolidMaterial[796].__vftable;
          v38 = -2 - 2 * nSubdivCount * v35;
          v39 = *(float *)&m_pSolidMaterial[815].__vftable;
          availableVerts += v38;
          v40 = m_pSolidMaterial[791].__vftable;
          vModColor.z = v39;
          v41 = *(float *)&m_pSolidMaterial[620].__vftable;
          v42 = m_pSolidMaterial[626].__vftable;
          z = *(float *)&v42->GetMaterialOffset;
          x = *(float *)&v42->GetNumAnimationFrames;
          y = *(float *)&v42->InMaterialPage;
          v46 = (float)((float)(int)((int)m_pSolidMaterial[792].__vftable + (unsigned int)v40 - 100) * v36)
              / (float)(nSegmentsToRender * (nSubdivCount - 1) + 1);
          v47 = _mm_cvtsi32_si128((unsigned int)m_pSolidMaterial[800].__vftable);
          LODWORD(vecP2.z) = v42->IsTranslucent;
          flDU = v46 / _mm_cvtepi32_ps(v47).m128_f32[0];
          vecDelta.z = vecP2.z - z;
          v47.m128i_i32[0] = (int)v42->GetLowResColorSample;
          m_flTStep = 1.0 / (float)nSubdivCount;
          v48 = *(float *)&v42->RecomputeStateSnapshots;
          vecDelta.w = w - w;
          vecP2.y = v48;
          LODWORD(vecP2.x) = v47.m128i_i32[0];
          v49 = *(float *)v47.m128i_i32 - x;
          vecDelta.y = v48 - y;
          vecP0.x = x - v49;
          vecP0.z = z - (float)(vecP2.z - z);
          flU = v41;
          bFirstPoint = true;
          vecP1.x = x;
          vecP1.y = y;
          vecP1.z = z;
          vecP1.w = w;
          vecP2.w = w;
          nRed = 0;
          nGreen = 0;
          nBlue = 0;
          vecP0.y = y - (float)(v48 - y);
          vecP0.w = w - (float)(w - w);
          if ( v145 >= 3 )
          {
            v50 = *(float *)&v42->NeedsPowerOfTwoFrameBufferTexture;
            LODWORD(vecP3.y) = v42->NeedsFullFrameBufferTexture;
            LODWORD(vecP3.z) = v42->NeedsSoftwareSkinning;
            v51 = *(float *)&m_pSolidMaterial[796].__vftable;
          }
          else
          {
            v50 = v49 + vecP2.x;
            vecP3.y = vecDelta.y + vecP2.y;
            vecP3.z = vecDelta.z + vecP2.z;
            v51 = vecDelta.w + w;
          }
          vecP3.w = v51;
          v52 = v51;
          v53 = meshIndexCount;
          vColor0.x = *(float *)&m_pSolidMaterial[756].__vftable * vModColor.x;
          vColor0.y = *(float *)&m_pSolidMaterial[757].__vftable * vModColor.y;
          vColor0.z = *(float *)&m_pSolidMaterial[758].__vftable * vModColor.z;
          vColor1.x = *(float *)&m_pSolidMaterial[759].__vftable * vModColor.x;
          v54 = *(float *)&m_pSolidMaterial[760].__vftable * vModColor.y;
          v55 = (float *)&m_pSolidMaterial[761];
          vColor1.y = v54;
          vColor1.z = *v55 * vModColor.z;
          nPnt = 3;
          vecP3.x = v50;
          nColor = 1;
          flT = 0.0;
          v149 = v55;
          p_GetNumPasses = (float *)&v42->GetNumPasses;
          v56 = (float *)&v42->GetNumPasses;
          do
          {
            if ( nSegmentsAvailableInBuffer == 0 )
            {
              m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
              v58 = v30 + meshBuilder.m_VertexBuilder.m_nCurrentVertex;
              meshBuilder.m_VertexBuilder.m_nCurrentVertex = v58;
              if ( v58 > meshBuilder.m_VertexBuilder.m_nVertexCount )
              {
                m_nVertexCount = v58;
                meshBuilder.m_VertexBuilder.m_nVertexCount = v58;
              }
              meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                                    + v30
                                                                    * meshBuilder.m_VertexBuilder.m_VertexSize_Position);
              meshBuilder.m_VertexBuilder.m_pCurrColor += v30 * meshBuilder.m_VertexBuilder.m_VertexSize_Color;
              meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                       + v30
                                                                       * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
              meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                       + v30
                                                                       * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
              meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                       + v30
                                                                       * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
              meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3]
                                                                       + v30
                                                                       * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[3]);
              meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4]
                                                                       + v30
                                                                       * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[4]);
              v59 = v31 * meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
              meshBuilder.m_IndexBuilder.m_nCurrentIndex = v59;
              if ( v59 > meshBuilder.m_IndexBuilder.m_nIndexCount )
                meshBuilder.m_IndexBuilder.m_nIndexCount = v59;
              if ( meshBuilder.m_bGenerateIndices )
              {
                switch ( meshBuilder.m_Type )
                {
                  case MATERIAL_LINE_STRIP:
                    m_nVertexCount = 2 * m_nVertexCount - 2;
                    break;
                  case MATERIAL_LINE_LOOP:
                    m_nVertexCount *= 2;
                    break;
                  case MATERIAL_POLYGON:
                    m_nVertexCount = 3 * m_nVertexCount - 6;
                    break;
                  case MATERIAL_QUADS:
                    m_nVertexCount = 6 * m_nVertexCount / 4;
                    break;
                  case MATERIAL_INSTANCED_QUADS:
                    m_nVertexCount = 0;
                    break;
                  default:
                    break;
                }
                CIndexBuilder::GenerateIndices(
                  this: &meshBuilder.m_IndexBuilder,
                  primitiveType: meshBuilder.m_Type,
                  nIndexCount: m_nVertexCount);
                m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
              }
              meshBuilder.m_pMesh->UnlockMesh(
                this: meshBuilder.m_pMesh,
                a2: m_nVertexCount,
                a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
                a4: &meshBuilder);
              meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
              meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
              meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
              meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
              meshBuilder.m_pMesh = nullptr;
              meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
              pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
              v60 = availableIndices - v53 + nTotalIndices;
              nTotalVerts += availableVerts - meshVertCount;
              nTotalIndices = v60;
              meshVertCount = nTotalVerts;
              if ( nTotalVerts >= nMaxVertices )
                meshVertCount = nMaxVertices;
              v53 = nMaxIndices;
              if ( v60 >= nMaxIndices )
              {
                meshIndexCount = nMaxIndices;
              }
              else
              {
                v53 = v60;
                meshIndexCount = v60;
              }
              v61 = meshVertCount;
              CMeshBuilder::Begin(
                this: &meshBuilder,
                pMesh,
                type: MATERIAL_TRIANGLES,
                nVertexCount: meshVertCount,
                nIndexCount: v53,
                pMeshSettings: nullptr);
              v62 = flT;
              v63 = flLastU;
              x = vecP1.x;
              y = vecP1.y;
              z = vecP1.z;
              w = vecP1.w;
              v64 = nBlue | ((nGreen | ((nRed | 0xFFFFFF00) << 8)) << 8);
              *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v64;
              m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = v62;
              m_pCurrPosition[1] = v63;
              m_pCurrPosition[2] = 0.0;
              *(Vector4D *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = vecP0;
              v66 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
              v67 = vecP2.x;
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = x;
              v66[1] = y;
              v66[2] = z;
              v66[3] = w;
              v68 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
              v69 = vecP3.y;
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v67;
              v68[1] = vecP2.y;
              v68[2] = vecP2.z;
              v68[3] = vecP2.w;
              v70 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3];
              v50 = vecP3.x;
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = vecP3.x;
              v70[1] = v69;
              v70[2] = vecP3.z;
              v52 = vecP3.w;
              v70[3] = vecP3.w;
              *(_DWORD *)&meshBuilder.m_VertexBuilder.m_pCurrColor[meshBuilder.m_VertexBuilder.m_VertexSize_Color] = v64;
              m_VertexSize_Position = meshBuilder.m_VertexBuilder.m_VertexSize_Position;
              v72 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              *(float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                       + meshBuilder.m_VertexBuilder.m_VertexSize_Position) = v62;
              *(float *)((char *)v72 + m_VertexSize_Position + 4) = v63;
              *(float *)((char *)v72 + m_VertexSize_Position + 8) = 1.0;
              v31 = 0;
              v73 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                            + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
              availableVerts = v61;
              *v73 = vecP0.x;
              v73[1] = vecP0.y;
              availableIndices = v53;
              v73[2] = vecP0.z;
              v73[3] = vecP0.w;
              v74 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                            + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
              v75 = vecP2.x;
              *v74 = x;
              v74[1] = y;
              v74[2] = z;
              v74[3] = w;
              v76 = (char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                  + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2];
              v30 = 2;
              *(float *)v76 = v75;
              *((_DWORD *)v76 + 1) = LODWORD(vecP2.y);
              *((_DWORD *)v76 + 2) = LODWORD(vecP2.z);
              *((_DWORD *)v76 + 3) = LODWORD(vecP2.w);
              v77 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3]
                            + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[3]);
              v78 = vecP3.y;
              *v77 = v50;
              v77[1] = v78;
              v77[2] = vecP3.z;
              v77[3] = v52;
              nSegmentsAvailableInBuffer = (v61 - 2) / (2 * nSubdivCount);
              if ( nSegmentsAvailableInBuffer >= v53 / nNumIndicesPerSegment )
                nSegmentsAvailableInBuffer = v53 / nNumIndicesPerSegment;
              v41 = flU;
              v55 = v149;
              v56 = p_GetNumPasses;
              nCurIDX = 0;
            }
            --nSegmentsAvailableInBuffer;
            v79 = 0.0;
            flT = 0.0;
            if ( nSubdivCount > 0 )
            {
              nCacheCount = nSubdivCount;
              do
              {
                v128 = (float)((float)((float)(vColor0.x * (float)(1.0 - v79)) + (float)(vColor1.x * v79)) * 255.0)
                     + 8388608.0;
                v131 = (float)((float)((float)(vColor0.y * (float)(1.0 - v79)) + (float)(vColor1.y * v79)) * 255.0)
                     + 8388608.0;
                v80 = LOBYTE(v131);
                nRed = LOBYTE(v128);
                v134 = (float)((float)((float)(vColor0.z * (float)(1.0 - v79)) + (float)(vColor1.z * v79)) * 255.0)
                     + 8388608.0;
                nBlue = LOBYTE(v134);
                v81 = LOBYTE(v134) | ((LOBYTE(v131) | ((LOBYTE(v128) | 0xFFFFFF00) << 8)) << 8);
                *(_DWORD *)&meshBuilder.m_VertexBuilder.m_pCurrColor[v30
                                                                   * meshBuilder.m_VertexBuilder.m_VertexSize_Color] = v81;
                v82 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                              + v30 * meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                w = vecP1.w;
                nGreen = v80;
                *v82 = v79;
                v82[1] = v41;
                v82[2] = 0.0;
                *(Vector4D *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                            + v30 * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]) = vecP0;
                v83 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                              + v30 * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                v84 = vecP2.x;
                *v83 = x;
                v83[1] = y;
                v83[2] = z;
                v83[3] = w;
                v85 = (char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                    + v30 * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2];
                *(float *)v85 = v84;
                *((_DWORD *)v85 + 1) = LODWORD(vecP2.y);
                *((_DWORD *)v85 + 2) = LODWORD(vecP2.z);
                *((_DWORD *)v85 + 3) = LODWORD(vecP2.w);
                v50 = vecP3.x;
                v86 = v30 + 1;
                *(Vector4D *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3]
                            + v30 * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[3]) = vecP3;
                *(_DWORD *)&meshBuilder.m_VertexBuilder.m_pCurrColor[(v30 + 1)
                                                                   * meshBuilder.m_VertexBuilder.m_VertexSize_Color] = v81;
                v87 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                              + (v30 + 1) * meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                v30 += 2;
                *v87 = v79;
                v87[1] = v41;
                v87[2] = 1.0;
                v79 = v79 + m_flTStep;
                v41 = v41 + flDU;
                *(Vector4D *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                            + v86 * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]) = vecP0;
                v88 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                              + v86 * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                v89 = vecP2.x;
                *v88 = x;
                v88[1] = y;
                v88[2] = z;
                v88[3] = w;
                v90 = (char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                    + v86 * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2];
                *(float *)v90 = v89;
                *((_DWORD *)v90 + 1) = LODWORD(vecP2.y);
                *((_DWORD *)v90 + 2) = LODWORD(vecP2.z);
                *((_DWORD *)v90 + 3) = LODWORD(vecP2.w);
                v91 = vecP3.y;
                v92 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3]
                              + v86 * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[3]);
                v93 = !bFirstPoint;
                *v92 = v50;
                v92[1] = v91;
                v92[2] = vecP3.z;
                v52 = vecP3.w;
                v92[3] = vecP3.w;
                if ( v93 )
                {
                  v94 = nCurIDX;
                  meshBuilder.m_IndexBuilder.m_pIndices[v31 + meshBuilder.m_IndexBuilder.m_nCurrentIndex] = nCurIDX + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
                  meshBuilder.m_IndexBuilder.m_pIndices[v31 + 1 + meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v94 + 1;
                  meshBuilder.m_IndexBuilder.m_pIndices[v31 + 2 + meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v94 + 2;
                  meshBuilder.m_IndexBuilder.m_pIndices[v31 + 3 + meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v94 + 1;
                  meshBuilder.m_IndexBuilder.m_pIndices[v31 + 4 + meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v94 + 3;
                  v95 = v31 + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
                  v31 += 6;
                  nCurIDX += 2;
                  meshBuilder.m_IndexBuilder.m_pIndices[v95 + 5] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                 + v94
                                                                 + 2;
                }
                v93 = nCacheCount-- == 1;
                bFirstPoint = false;
              }
              while ( !v93 );
              v53 = meshIndexCount;
              v55 = v149;
              v56 = p_GetNumPasses;
              flU = v41;
              flT = v79;
            }
            vColor0 = vColor1;
            if ( nColor < v145 - 1 )
            {
              ++nColor;
              v96 = v55[1] * vModColor.x;
              v52 = vecP3.w;
              v55 += 3;
              vColor1.x = v96;
              vColor1.y = *(v55 - 1) * vModColor.y;
              v97 = *v55 * vModColor.z;
              v149 = v55;
              vColor1.z = v97;
            }
            if ( nSegmentsToRender > 1 )
            {
              vecP0.y = y;
              y = vecP2.y;
              vecP0.x = x;
              x = vecP2.x;
              vecP0.z = z;
              z = vecP2.z;
              vecP0.w = w;
              w = vecP2.w;
              vecP2.y = vecP3.y;
              vecP1.x = vecP2.x;
              vecP1.y = y;
              vecP1.z = vecP2.z;
              vecP1.w = vecP2.w;
              vecP2.x = v50;
              vecP2.z = vecP3.z;
              vecP2.w = v52;
              if ( nPnt >= v145 )
              {
                vecP3.x = v50 * 2.0;
                vecP3.y = vecP3.y * 2.0;
                vecP3.y = vecP3.y - y;
                v52 = (float)(v52 * 2.0) - w;
                v50 = (float)(v50 * 2.0) - x;
                v99 = (float)(vecP3.z * 2.0) - z;
                vecP3.w = v52;
              }
              else
              {
                v98 = *(v56 - 1);
                v50 = *(v56 - 2);
                ++nPnt;
                vecP3.y = v98;
                v99 = *v56;
                v56 += 9;
                p_GetNumPasses = v56;
              }
              vecP3.z = v99;
              vecP3.x = v50;
            }
            --nSegmentsToRender;
          }
          while ( nSegmentsToRender != 0 );
          v100 = nBlue | ((nGreen | ((nRed | 0xFFFFFF00) << 8)) << 8);
          *(_DWORD *)&meshBuilder.m_VertexBuilder.m_pCurrColor[v30 * meshBuilder.m_VertexBuilder.m_VertexSize_Color] = v100;
          v101 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                         + v30 * meshBuilder.m_VertexBuilder.m_VertexSize_Position);
          v102 = v30 + 1;
          *v101 = 1.0;
          v101[1] = v41;
          v101[2] = 0.0;
          *(Vector4D *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                      + v30 * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]) = vecP0;
          v103 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                         + v30 * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
          v104 = vecP2.x;
          *v103 = x;
          v103[1] = y;
          v103[2] = z;
          v103[3] = w;
          v105 = (char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
               + v30 * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2];
          *(float *)v105 = v104;
          *((_DWORD *)v105 + 1) = LODWORD(vecP2.y);
          *((_DWORD *)v105 + 2) = LODWORD(vecP2.z);
          *((_DWORD *)v105 + 3) = LODWORD(vecP2.w);
          v106 = vecP3.y;
          v107 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3]
                         + v30 * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[3]);
          *v107 = v50;
          v107[1] = v106;
          v107[2] = vecP3.z;
          v107[3] = v52;
          *(_DWORD *)&meshBuilder.m_VertexBuilder.m_pCurrColor[(v30 + 1)
                                                             * meshBuilder.m_VertexBuilder.m_VertexSize_Color] = v100;
          v108 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                         + (v30 + 1) * meshBuilder.m_VertexBuilder.m_VertexSize_Position);
          *v108 = 1.0;
          v108[1] = v41;
          v108[2] = 1.0;
          *(Vector4D *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                      + (v30 + 1) * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]) = vecP0;
          v109 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                         + (v30 + 1) * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
          v110 = vecP2.x;
          v30 += 2;
          *v109 = x;
          v109[1] = y;
          v109[2] = z;
          v109[3] = w;
          v111 = (char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
               + v102 * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2];
          flLastU = v41;
          *(float *)v111 = v110;
          *((_DWORD *)v111 + 1) = LODWORD(vecP2.y);
          *((_DWORD *)v111 + 2) = LODWORD(vecP2.z);
          *((_DWORD *)v111 + 3) = LODWORD(vecP2.w);
          v112 = vecP3.y;
          v113 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3]
                         + v102 * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[3]);
          *v113 = v50;
          v113[1] = v112;
          v113[2] = vecP3.z;
          v113[3] = v52;
          v114 = nCurIDX;
          meshBuilder.m_IndexBuilder.m_pIndices[v31 + meshBuilder.m_IndexBuilder.m_nCurrentIndex] = nCurIDX + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
          meshBuilder.m_IndexBuilder.m_pIndices[v31 + 1 + meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v114 + 1;
          meshBuilder.m_IndexBuilder.m_pIndices[v31 + 2 + meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v114 + 2;
          meshBuilder.m_IndexBuilder.m_pIndices[v31 + 3 + meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v114 + 1;
          meshBuilder.m_IndexBuilder.m_pIndices[v31 + 4 + meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v114 + 3;
          meshBuilder.m_IndexBuilder.m_pIndices[v31 + 5 + meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v114 + 2;
          v31 += 6;
          nCurIDX = v114 + 4;
        }
      }
      v161 = (CRopeManager::RopeRenderData_t *)((char *)v161 + 4);
      --m_aCache;
    }
    while ( m_aCache != 0 );
    v115 = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v116 = v30 + meshBuilder.m_VertexBuilder.m_nCurrentVertex;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v116;
    if ( v116 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      v115 = v116;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v116;
    }
    meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                          + v30 * meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += v30 * meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                             + v30
                                                             * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                             + v30
                                                             * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                             + v30
                                                             * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3]
                                                             + v30
                                                             * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[3]);
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4]
                                                             + v30
                                                             * meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[4]);
    v117 = v31 * meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = v117;
    if ( v117 > meshBuilder.m_IndexBuilder.m_nIndexCount )
      meshBuilder.m_IndexBuilder.m_nIndexCount = v117;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          v118 = 2 * v115 - 2;
          break;
        case MATERIAL_LINE_LOOP:
          v118 = 2 * v115;
          break;
        case MATERIAL_POLYGON:
          v118 = 3 * v115 - 6;
          break;
        case MATERIAL_QUADS:
          v118 = 6 * v115 / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          v118 = 0;
          break;
        default:
          v118 = v115;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: v118);
      v115 = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: v115,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
LABEL_109:
    m_pObject = pRenderContext.m_pObject;
    v16 = iRenderCache + 1;
    iRenderCache = v16;
    if ( v16 >= nRenderCacheCount )
    {
      p_dummyMutex = pRopeDataMutex;
      goto LABEL_111;
    }
  }
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        v121 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        v121 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        v121 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        v121 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        v121 = 0;
        break;
      default:
        v121 = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: v121);
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v122 = &v163->m_RopeQueuedRenderCaches_Mutex;
  v123 = GetCurrentThreadId();
  if ( v123 != v122->m_ownerID && _InterlockedCompareExchange((volatile signed __int32 *)v122, v123, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: v122, a2: v123, a3: 0);
  }
  else
  {
    ++v122->m_depth;
  }
  if ( pBuildRopeQueuedData != nullptr && v163->m_RopeQueuedRenderCaches.m_ElementCount != 0 )
  {
    iHeadIndexa = v163->m_RopeQueuedRenderCaches.m_Head;
    bShadowDeptha = &v163->m_RopeQueuedRenderCaches;
    C_BaseEntity::operator delete(pMem: v163->m_RopeQueuedRenderCaches.m_Memory.m_pMemory[iHeadIndexa].m_Element.m_pRopeDataMutex);
    CUtlLinkedList<CDataChangedEvent,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDataChangedEvent,unsigned short>,unsigned short>>::Unlink(
      this: bShadowDeptha,
      elem: iHeadIndexa);
    bShadowDeptha->m_Memory.m_pMemory[iHeadIndexa].m_Next = bShadowDeptha->m_FirstFree;
    bShadowDeptha->m_FirstFree = iHeadIndexa;
  }
  v93 = v122->m_depth-- == 1;
  if ( v93 )
    _InterlockedExchange((volatile __int32 *)v122, 0);
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
  v93 = pRopeDataMutex->m_depth-- == 1;
  if ( v93 )
    _InterlockedExchange((volatile __int32 *)pRopeDataMutex, 0);
  if ( m_pObject != nullptr )
  {
LABEL_151:
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
  }
LABEL_152:
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10086920
// Name: public: virtual void CRopeManager::DrawRenderCache(class IMatRenderContext __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CRopeManager::DrawRenderCache(
        CRopeManager *this@<ecx>,
        int a2@<ebx>,
        IMatRenderContext *pRenderContext,
        __int16 bShadowDepth)
{
  int m_Size; // esi
  const Vector *v6; // eax
  __int64 v7; // xmm0_8
  float z; // eax
  const Vector *v9; // eax
  float v10; // ecx
  CRopeManager::RopeRenderData_t *m_pMemory; // eax
  int v12; // edi
  int v13; // edx
  C_RopeKeyframe **m_aCache; // ebx
  int v15; // eax
  C_RopeKeyframe **v16; // ecx
  int v17; // esi
  int v18; // esi
  int v19; // edi
  int v20; // ebx
  float *v21; // esi
  CRopeManager::RopeRenderData_t *v22; // edi
  _DWORD *v23; // eax
  float *v24; // ecx
  _DWORD *v25; // edx
  char *v26; // esi
  int v27; // eax
  CRopeManager::RopeRenderData_t *v28; // edi
  float *p_z; // esi
  C_RopeKeyframe *v30; // eax
  C_RopeKeyframe::BuildRopeQueuedData_t *v31; // ebx
  float *m_nNodes; // edi
  __m128i v33; // xmm0
  int v34; // ebx
  float *v35; // edx
  C_RopeKeyframe *v36; // esi
  CSimplePhysics::CNode *m_pNodes; // edi
  double x; // st7
  int p_m_vPredicted; // edi
  double v40; // st7
  bool v41; // zf
  CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short> > *v42; // edi
  CThreadFastMutex *p_m_RopeQueuedRenderCaches_Mutex; // esi
  DWORD CurrentThreadId; // eax
  int v45; // ebx
  unsigned __int16 v46; // ax
  int v47; // eax
  int v48; // ecx
  CThreadFastMutex *m_pRopeDataMutex; // edi
  char *v50; // eax
  __int64 v51; // xmm0_8
  CRopeManager *v52; // ecx
  __int64 v53; // xmm0_8
  int v54; // ecx
  float v55; // edx
  __int64 v56; // xmm0_8
  float v57; // ecx
  C_RopeKeyframe::BuildRopeQueuedData_t *v58; // edx
  void *rd_4; // [esp+Ch] [ebp-6Ch]
  Vector vForward; // [esp+18h] [ebp-60h] BYREF
  Vector vOrigin; // [esp+24h] [ebp-54h] BYREF
  __int128 v63; // [esp+30h] [ebp-48h] OVERLAPPED
  ICallQueue *pCallQueue; // [esp+40h] [ebp-38h]
  char *v65; // [esp+44h] [ebp-34h]
  int v66; // [esp+48h] [ebp-30h]
  float *v67; // [esp+4Ch] [ebp-2Ch]
  C_RopeKeyframe::BuildRopeQueuedData_t *pBuildRopeQueuedDataStart; // [esp+50h] [ebp-28h]
  CRopeManager *v69; // [esp+54h] [ebp-24h]
  CRopeManager::RopeRenderData_t *pRenderCache; // [esp+58h] [ebp-20h]
  _DWORD *v71; // [esp+5Ch] [ebp-1Ch]
  int j; // [esp+60h] [ebp-18h]
  float *v73; // [esp+64h] [ebp-14h]
  int iRenderCacheCount; // [esp+68h] [ebp-10h]
  C_RopeKeyframe **i; // [esp+6Ch] [ebp-Ch]
  CRopeManager::RopeRenderData_t *v76; // [esp+70h] [ebp-8h]
  C_RopeKeyframe::BuildRopeQueuedData_t *pWriteRopeQueuedData; // [esp+74h] [ebp-4h]

  m_Size = this->m_aRenderCache.m_Size;
  v69 = this;
  iRenderCacheCount = m_Size;
  if ( m_Size != 0 && r_drawropes.m_pParent != nullptr && r_drawropes.m_pParent->m_Value.m_nValue != 0 )
  {
    v6 = CurrentViewForward();
    v7 = *(_QWORD *)&v6->x;
    z = v6->z;
    *(_QWORD *)&vForward.x = v7;
    vForward.z = z;
    v9 = CurrentViewOrigin();
    v10 = v9->z;
    *(_QWORD *)&vOrigin.x = *(_QWORD *)&v9->x;
    vOrigin.z = v10;
    if ( r_queued_ropes.m_pParent != nullptr
      && r_queued_ropes.m_pParent->m_Value.m_nValue != 0
      && (pCallQueue = pRenderContext->GetCallQueue(this: pRenderContext)) != nullptr )
    {
      m_pMemory = this->m_aRenderCache.m_Memory.m_pMemory;
      v12 = 0;
      pRenderCache = m_pMemory;
      v13 = 0;
      m_aCache = m_pMemory->m_aCache;
      for ( i = (C_RopeKeyframe **)m_Size; i != nullptr; i = (C_RopeKeyframe **)((char *)i - 1) )
      {
        v15 = (int)*(m_aCache - 1);
        v12 += v15;
        if ( v15 != 0 )
        {
          v16 = m_aCache;
          v17 = (int)*(m_aCache - 1);
          do
          {
            if ( *v16 != nullptr )
              v13 += (*v16)->m_RopePhysics.m_nNodes;
            else
              --v12;
            ++v16;
            --v17;
          }
          while ( v17 != 0 );
          m_Size = iRenderCacheCount;
        }
        m_aCache += 130;
      }
      if ( v12 != 0 )
      {
        v18 = 520 * m_Size;
        v19 = 32 * v12;
        v20 = ((int (__thiscall *)(IMatRenderContext *, int, int))pRenderContext->LockRenderData)(
                a1: pRenderContext,
                a2: v18 + v19 + 24 * v13,
                a3: a2);
        pBuildRopeQueuedDataStart = (C_RopeKeyframe::BuildRopeQueuedData_t *)(v20 + v18);
        v21 = (float *)(v19 + v20 + v18);
        v22 = (CRopeManager::RopeRenderData_t *)iRenderCacheCount;
        rd_4 = (void *)v20;
        *(_QWORD *)((char *)&v63 + 4) = __PAIR64__(iRenderCacheCount, v20);
        v23 = MemAlloc_Alloc(nSize: 8u);
        if ( v23 != nullptr )
        {
          *v23 = 0;
          v23[1] = 0;
          HIDWORD(v63) = v23;
        }
        else
        {
          HIDWORD(v63) = 0;
        }
        pWriteRopeQueuedData = pBuildRopeQueuedDataStart;
        v24 = v21;
        v76 = pRenderCache;
        v25 = (_DWORD *)(v20 + 4);
        v26 = (char *)pRenderCache - v20;
        v71 = (_DWORD *)(v20 + 4);
        v65 = (char *)pRenderCache - v20;
        pRenderCache = v22;
        do
        {
          v27 = *(_DWORD *)((char *)v25 + (_DWORD)v26);
          v28 = v76;
          *v25 = 0;
          *(v25 - 1) = v28->m_pSolidMaterial;
          if ( v27 != 0 )
          {
            p_z = &pWriteRopeQueuedData->m_vColorMod.z;
            i = v76->m_aCache;
            for ( j = v27; j != 0; --j )
            {
              v30 = *i;
              if ( *i != nullptr )
              {
                v31 = pWriteRopeQueuedData;
                v25[++*v25] = v30;
                m_nNodes = (float *)v30->m_RopePhysics.m_nNodes;
                *((_DWORD *)p_z - 3) = m_nNodes;
                *(p_z - 2) = v30->m_vColorMod.x;
                ++pWriteRopeQueuedData;
                p_z += 8;
                *(p_z - 9) = v30->m_vColorMod.y;
                v67 = p_z;
                *(p_z - 8) = v30->m_vColorMod.z;
                *(p_z - 7) = (float)v30->m_RopeLength;
                v33 = _mm_cvtsi32_si128(v30->m_Slack);
                v31->m_pPredictedPositions = (Vector *)v24;
                v66 = 12 * (_DWORD)m_nNodes;
                *((_DWORD *)p_z - 6) = _mm_cvtepi32_ps(v33).m128_u32[0];
                *((_DWORD *)p_z - 12) = &v24[3 * (_DWORD)m_nNodes];
                v73 = &v24[3 * (_DWORD)m_nNodes];
                if ( m_nNodes != nullptr )
                {
                  v34 = 0;
                  v35 = v73 + 2;
                  v36 = (C_RopeKeyframe *)&v30->m_LightValues[0].z;
                  v73 = m_nNodes;
                  do
                  {
                    m_pNodes = v30->m_RopePhysics.m_pNodes;
                    x = m_pNodes[v34].m_vPredicted.x;
                    p_m_vPredicted = (int)&m_pNodes[v34].m_vPredicted;
                    *v24 = x;
                    v24 += 3;
                    v35 += 3;
                    *(v24 - 2) = *(float *)(p_m_vPredicted + 4);
                    v36 = (C_RopeKeyframe *)((char *)v36 + 12);
                    v40 = *(float *)(p_m_vPredicted + 8);
                    ++v34;
                    v41 = v73 == (float *)1;
                    v73 = (float *)((char *)v73 - 1);
                    *(v24 - 1) = v40;
                    *(v35 - 5) = v36[-1].m_vCachedEndPointAttachmentAngle[1].x;
                    *(v35 - 4) = v36[-1].m_vCachedEndPointAttachmentAngle[1].y;
                    *(v35 - 3) = v36[-1].m_vCachedEndPointAttachmentAngle[1].z;
                  }
                  while ( !v41 );
                  p_z = v67;
                  v25 = v71;
                }
                v24 = (float *)((char *)v24 + v66);
              }
              ++i;
            }
            v26 = v65;
          }
          ++v76;
          v25 += 130;
          v41 = pRenderCache == (CRopeManager::RopeRenderData_t *)1;
          pRenderCache = (CRopeManager::RopeRenderData_t *)((char *)pRenderCache - 1);
          v71 = v25;
        }
        while ( !v41 );
        v42 = (CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short> > *)v69;
        p_m_RopeQueuedRenderCaches_Mutex = &v69->m_RopeQueuedRenderCaches_Mutex;
        CurrentThreadId = GetCurrentThreadId();
        if ( CurrentThreadId != v69->m_RopeQueuedRenderCaches_Mutex.m_ownerID
          && _InterlockedCompareExchange(
               (volatile signed __int32 *)p_m_RopeQueuedRenderCaches_Mutex,
               CurrentThreadId,
               0) != 0 )
        {
          _mm_pause();
          CThreadFastMutex::Lock(a1: p_m_RopeQueuedRenderCaches_Mutex, a2: CurrentThreadId, a3: 0);
        }
        else
        {
          ++v69->m_RopeQueuedRenderCaches_Mutex.m_depth;
        }
        v45 = (unsigned __int16)CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short>>::AllocInternal(
                                  this: v42 + 1,
                                  multilist: false);
        v46 = -1;
        if ( (_WORD)v45 != 0xFFFF )
        {
          CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short>>::LinkBefore(
            this: v42 + 1,
            before: 0xFFFFu,
            elem: v45);
          v47 = (int)&v42[1].m_Memory.m_pMemory[v45];
          if ( v47 != 0 )
          {
            v48 = HIDWORD(v63);
            *(_QWORD *)v47 = *(_QWORD *)((char *)&v63 + 4);
            *(_DWORD *)(v47 + 8) = v48;
          }
          v46 = v45;
        }
        m_pRopeDataMutex = v42[1].m_Memory.m_pMemory[v46].m_Element.m_pRopeDataMutex;
        v41 = p_m_RopeQueuedRenderCaches_Mutex->m_depth-- == 1;
        if ( v41 )
          _InterlockedExchange((volatile __int32 *)p_m_RopeQueuedRenderCaches_Mutex, 0);
        LODWORD(v63) = CRopeManager::DrawRenderCache_NonQueued;
        *(_QWORD *)((char *)&v63 + 4) = 0;
        HIDWORD(v63) = 0;
        v50 = (char *)MemAlloc_Alloc(nSize: 0x58u);
        if ( v50 != nullptr )
        {
          v51 = v63;
          v52 = v69;
          *((_DWORD *)v50 + 3) = 1;
          *(_DWORD *)v50 = &CMemberFunctor7<CRopeManager *,void (__thiscall CRopeManager::*)(bool,CRopeManager::RopeRenderData_t *,int,Vector const &,Vector const &,C_RopeKeyframe::BuildRopeQueuedData_t *,CThreadFastMutex *),bool,CRopeManager::RopeRenderData_t *,int,Vector,Vector,C_RopeKeyframe::BuildRopeQueuedData_t *,CThreadFastMutex *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          *((_DWORD *)v50 + 2) = &CMemberFunctor7<CRopeManager *,void (__thiscall CRopeManager::*)(bool,CRopeManager::RopeRenderData_t *,int,Vector const &,Vector const &,C_RopeKeyframe::BuildRopeQueuedData_t *,CThreadFastMutex *),bool,CRopeManager::RopeRenderData_t *,int,Vector,Vector,C_RopeKeyframe::BuildRopeQueuedData_t *,CThreadFastMutex *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          *((_QWORD *)v50 + 2) = v51;
          *((_QWORD *)v50 + 3) = *((_QWORD *)&v63 + 1);
          v53 = *(_QWORD *)&vForward.x;
          *((_DWORD *)v50 + 8) = v52;
          v54 = iRenderCacheCount;
          v50[40] = bShadowDepth;
          v55 = vForward.z;
          *(_QWORD *)(v50 + 52) = v53;
          v56 = *(_QWORD *)&vOrigin.x;
          *((_DWORD *)v50 + 12) = v54;
          v57 = vOrigin.z;
          *((float *)v50 + 15) = v55;
          v58 = pBuildRopeQueuedDataStart;
          *((_QWORD *)v50 + 8) = v56;
          *((_DWORD *)v50 + 11) = rd_4;
          *((float *)v50 + 18) = v57;
          *((_DWORD *)v50 + 19) = v58;
          *((_DWORD *)v50 + 20) = m_pRopeDataMutex;
        }
        else
        {
          v50 = nullptr;
        }
        pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: (CFunctor *)v50);
        if ( rd_4 != nullptr )
          pRenderContext->UnlockRenderData(this: pRenderContext, a2: rd_4);
      }
    }
    else
    {
      CRopeManager::DrawRenderCache_NonQueued(
        this,
        bShadowDepth,
        pRenderCache: this->m_aRenderCache.m_Memory.m_pMemory,
        nRenderCacheCount: m_Size,
        vCurrentViewForward: &vForward,
        vCurrentViewOrigin: &vOrigin,
        pBuildRopeQueuedData: nullptr,
        pRopeDataMutex: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086D00
// Name: public: C_RopeKeyframe::C_RopeKeyframe(void)
// Source: json
//------------------------------------------------------------------------------
C_RopeKeyframe *__thiscall C_RopeKeyframe::C_RopeKeyframe(C_RopeKeyframe *this)
{
  char v2; // cl
  C_RopeKeyframe *src; // [esp+Ch] [ebp-4h] BYREF

  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_RopeKeyframe_vtbl *)&C_RopeKeyframe::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_RopeKeyframe::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_RopeKeyframe::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_RopeKeyframe::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_RopeKeyframe::`vftable';
  if ( this != (C_RopeKeyframe *)-2432 )
    this->m_LinksTouchingSomething.m_Ints[0] = 0;
  CBaseRopePhysics::CBaseRopePhysics(
    this: &this->m_RopePhysics,
    pNodes: this->m_RopePhysics.m_Nodes,
    nNodes: 10,
    pSprings: this->m_RopePhysics.m_Springs,
    flSpringDistsSqr: this->m_RopePhysics.m_SpringDistsSqr);
  this->m_RopePhysics.__vftable = (CRopePhysics<10>_vtbl *)&CRopePhysics<10>::`vftable';
  this->m_hStartPoint.m_Index = -1;
  this->m_hEndPoint.m_Index = -1;
  this->m_PhysicsDelegate.__vftable = (C_RopeKeyframe::CPhysicsDelegate_vtbl *)&C_RopeKeyframe::CPhysicsDelegate::`vftable';
  v2 = *((_BYTE *)this + 3313);
  this->m_PhysicsDelegate.m_pKeyframe = this;
  this->m_pMaterial = nullptr;
  this->m_RopeFlags = 0;
  this->m_TextureHeight = 1;
  *((_BYTE *)this + 3313) = v2 & 0xF4 | 3;
  this->m_hEndPoint.m_Index = -1;
  this->m_hStartPoint.m_Index = -1;
  *(_DWORD *)&this->m_iStartAttachment = 0;
  this->m_vColorMod.x = 1.0;
  this->m_vColorMod.y = 1.0;
  this->m_vColorMod.z = 1.0;
  this->m_nLinksTouchingSomething = 0;
  this->m_Subdiv = 255;
  *(_QWORD *)&this->m_flCurrentGustTimer = 0;
  this->m_fLockedPoints = 0;
  this->m_fPrevLockedPoints = 0;
  this->m_iForcePointMoveCounter = 0;
  *(_QWORD *)&this->m_flCurScroll = 0;
  this->m_TextureScale = 4.0;
  this->m_vecImpulse.x = 0.0;
  this->m_vecImpulse.y = 0.0;
  this->m_vecImpulse.z = 0.0;
  src = this;
  CUtlLinkedList<C_RopeKeyframe *,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,int>,int>>::AddToTail(
    this: &g_Ropes,
    &src);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10086E70
// Name: public: static class C_RopeKeyframe __near * C_RopeKeyframe::Create(class C_BaseEntity __near *,class C_BaseEntity __near *,int,int,float,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
C_RopeKeyframe *__cdecl C_RopeKeyframe::Create(
        C_BaseEntity *pStartEnt,
        C_BaseEntity *pEndEnt,
        __int16 iStartAttachment,
        __int16 iEndAttachment,
        float ropeWidth,
        const char *pMaterialName,
        int numSegments,
        int ropeFlags)
{
  C_RopeKeyframe *v8; // eax
  C_RopeKeyframe *v9; // esi
  int v10; // eax

  v8 = (C_RopeKeyframe *)C_BaseEntity::operator new(stAllocateBlock: 0xCF8u);
  if ( v8 != nullptr )
    v9 = C_RopeKeyframe::C_RopeKeyframe(this: v8);
  else
    v9 = nullptr;
  v9->InitializeAsClientEntity(this: v9, a2: nullptr, a3: false);
  if ( pStartEnt != nullptr )
  {
    v9->m_hStartPoint.m_Index = pStartEnt->GetRefEHandle(this: pStartEnt)->m_Index;
    v9->m_fLockedPoints |= 1u;
  }
  if ( pEndEnt != nullptr )
  {
    v9->m_hEndPoint.m_Index = pEndEnt->GetRefEHandle(this: pEndEnt)->m_Index;
    v9->m_fLockedPoints |= 2u;
  }
  v9->m_iEndAttachment = iEndAttachment;
  v10 = numSegments;
  v9->m_iStartAttachment = iStartAttachment;
  v9->m_Width = ropeWidth;
  if ( numSegments >= 2 )
  {
    if ( numSegments > 10 )
      v10 = 10;
  }
  else
  {
    v10 = 2;
  }
  v9->m_RopeFlags = ropeFlags;
  v9->m_nSegments = v10;
  C_RopeKeyframe::FinishInit(this: v9, pMaterialName);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10086F40
// Name: public: static class C_RopeKeyframe __near * C_RopeKeyframe::CreateFromKeyValues(class C_BaseAnimating __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
C_RopeKeyframe *__cdecl C_RopeKeyframe::CreateFromKeyValues(C_BaseAnimating *pEnt, KeyValues *pValues)
{
  const char *v2; // eax
  __int16 v3; // ax
  C_RopeKeyframe *result; // eax
  C_RopeKeyframe *v5; // edi
  int v6; // eax
  __int16 v7; // [esp-4h] [ebp-24h]
  float defaultValue; // [esp+0h] [ebp-20h]
  float defaultValuea; // [esp+0h] [ebp-20h]
  const char *String; // [esp+4h] [ebp-1Ch]
  int Int; // [esp+8h] [ebp-18h]
  float m_TextureScale; // [esp+Ch] [ebp-14h]
  IClientRenderable_vtbl *v13; // [esp+1Ch] [ebp-4h]

  v13 = pEnt->C_BaseEntity::IClientEntity::IClientRenderable::__vftable;
  Int = KeyValues::GetInt(this: pValues, keyName: "NumSegments", defaultValue: 0);
  String = KeyValues::GetString(this: pValues, keyName: "Material", defaultValue: prType);
  defaultValue = KeyValues::GetFloat(this: pValues, keyName: "Width", defaultValue: 0.5);
  v2 = KeyValues::GetString(this: pValues, keyName: "EndAttachment", defaultValue: prType);
  defaultValuea = COERCE_FLOAT(
                    ((int (__thiscall *)(IClientRenderable *, const char *, _DWORD))v13->LookupAttachment)(
                      a1: &pEnt->IClientRenderable,
                      a2: v2,
                      a3: LODWORD(defaultValue)));
  v7 = (unsigned __int16)KeyValues::GetString(this: pValues, keyName: "StartAttachment", defaultValue: prType);
  v3 = ((int (__thiscall *)(IClientRenderable *))v13->LookupAttachment)(a1: &pEnt->IClientRenderable);
  result = C_RopeKeyframe::Create(
             pStartEnt: pEnt,
             pEndEnt: pEnt,
             iStartAttachment: v3,
             iEndAttachment: v7,
             ropeWidth: defaultValuea,
             pMaterialName: String,
             numSegments: Int,
             ropeFlags: 0);
  v5 = result;
  if ( result != nullptr )
  {
    if ( KeyValues::GetInt(this: pValues, keyName: "Gravity", defaultValue: 1) == 0 )
      v5->m_RopeFlags |= 0x100u;
    v6 = KeyValues::GetInt(this: pValues, keyName: "Length", defaultValue: 0);
    m_TextureScale = v5->m_TextureScale;
    v5->m_RopeLength = v6;
    v5->m_TextureScale = KeyValues::GetFloat(this: pValues, keyName: "TextureScale", defaultValue: m_TextureScale);
    v5->m_RopeFlags |= 8u;
    v5->m_Slack = 0;
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10369BC0
// Name: public: virtual void CMemberFunctor7<class CSOAContainer __near *,void (CSOAContainer::*)(int,int,int,int,class CSOAContainer const __near *,int,int),int,int,int,int,class CSOAContainer const __near *,int,int,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor7<CSOAContainer *,void (__thiscall CSOAContainer::*)(int,int,int,int,CSOAContainer const *,int,int),int,int,int,int,CSOAContainer const *,int,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor7<CSOAContainer *,void (__thiscall CSOAContainer::*)(int,int,int,int,CSOAContainer const *,int,int),int,int,int,int,CSOAContainer const *,int,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(
    this: this->m_Proxy.m_pObject,
    a2: this->m_arg1,
    a3: this->m_arg2,
    a4: this->m_arg3,
    a5: this->m_arg4,
    a6: this->m_arg5,
    a7: this->m_arg6,
    a8: this->m_arg7);
}

//------------------------------------------------------------------------------
// Address: 0x104131D0
// Name: PrecacheRopesPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheRopesPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheRopesPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheRopesPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413210
// Name: DT_RopeKeyframe::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_RopeKeyframe::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_RopeKeyframe::g_RecvTable);
  return atexit(func: DT_RopeKeyframe::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413230
// Name: DT_RopeKeyframe::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_RopeKeyframe::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_RopeKeyframe::ignored>();
  DT_RopeKeyframe::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413240
// Name: _dynamic_initializer_for__rope_shake__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rope_shake__()
{
  ConVar::ConVar(this: &rope_shake, pName: "rope_shake", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__rope_shake__);
}

//------------------------------------------------------------------------------
// Address: 0x10413270
// Name: _dynamic_initializer_for__rope_subdiv__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rope_subdiv__()
{
  ConVar::ConVar(
    this: &rope_subdiv,
    pName: "rope_subdiv",
    pDefaultValue: "2",
    flags: 0x800000,
    pHelpString: "Rope subdivision amount",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 8.0);
  return atexit(func: dynamic_atexit_destructor_for__rope_subdiv__);
}

//------------------------------------------------------------------------------
// Address: 0x104132C0
// Name: _dynamic_initializer_for__rope_collide__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rope_collide__()
{
  ConVar::ConVar(
    this: &rope_collide,
    pName: "rope_collide",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Collide rope with the world");
  return atexit(func: dynamic_atexit_destructor_for__rope_collide__);
}

//------------------------------------------------------------------------------
// Address: 0x104132F0
// Name: _dynamic_initializer_for__rope_smooth__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rope_smooth__()
{
  ConVar::ConVar(
    this: &rope_smooth,
    pName: "rope_smooth",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Do an antialiasing effect on ropes");
  return atexit(func: dynamic_atexit_destructor_for__rope_smooth__);
}

//------------------------------------------------------------------------------
// Address: 0x10413320
// Name: _dynamic_initializer_for__rope_smooth_enlarge__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rope_smooth_enlarge__()
{
  ConVar::ConVar(
    this: &rope_smooth_enlarge,
    pName: "rope_smooth_enlarge",
    pDefaultValue: "1.4",
    flags: 0,
    pHelpString: "How much to enlarge ropes in screen space for antialiasing effect");
  return atexit(func: dynamic_atexit_destructor_for__rope_smooth_enlarge__);
}

//------------------------------------------------------------------------------
// Address: 0x10413350
// Name: _dynamic_initializer_for__rope_smooth_minwidth__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rope_smooth_minwidth__()
{
  ConVar::ConVar(
    this: &rope_smooth_minwidth,
    pName: "rope_smooth_minwidth",
    pDefaultValue: "0.3",
    flags: 0,
    pHelpString: "When using smoothing, this is the min screenspace width it lets a rope shrink to");
  return atexit(func: dynamic_atexit_destructor_for__rope_smooth_minwidth__);
}

//------------------------------------------------------------------------------
// Address: 0x10413380
// Name: _dynamic_initializer_for__rope_smooth_minalpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rope_smooth_minalpha__()
{
  ConVar::ConVar(
    this: &rope_smooth_minalpha,
    pName: "rope_smooth_minalpha",
    pDefaultValue: "0.2",
    flags: 0,
    pHelpString: "Alpha for rope antialiasing effect");
  return atexit(func: dynamic_atexit_destructor_for__rope_smooth_minalpha__);
}

//------------------------------------------------------------------------------
// Address: 0x104133B0
// Name: _dynamic_initializer_for__rope_smooth_maxalphawidth__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rope_smooth_maxalphawidth__()
{
  ConVar::ConVar(this: &rope_smooth_maxalphawidth, pName: "rope_smooth_maxalphawidth", pDefaultValue: "1.75", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__rope_smooth_maxalphawidth__);
}

//------------------------------------------------------------------------------
// Address: 0x104133E0
// Name: _dynamic_initializer_for__rope_smooth_maxalpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rope_smooth_maxalpha__()
{
  ConVar::ConVar(
    this: &rope_smooth_maxalpha,
    pName: "rope_smooth_maxalpha",
    pDefaultValue: "0.5",
    flags: 0,
    pHelpString: "Alpha for rope antialiasing effect");
  return atexit(func: dynamic_atexit_destructor_for__rope_smooth_maxalpha__);
}

//------------------------------------------------------------------------------
// Address: 0x104134A0
// Name: _dynamic_initializer_for__rope_wind_dist__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rope_wind_dist__()
{
  ConVar::ConVar(
    this: &rope_wind_dist,
    pName: "rope_wind_dist",
    pDefaultValue: "1000",
    flags: 0,
    pHelpString: "Don't use CPU applying small wind gusts to ropes when they're past this distance.");
  return atexit(func: dynamic_atexit_destructor_for__rope_wind_dist__);
}

//------------------------------------------------------------------------------
// Address: 0x104134D0
// Name: _dynamic_initializer_for__rope_averagelight__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rope_averagelight__()
{
  ConVar::ConVar(
    this: &rope_averagelight,
    pName: "rope_averagelight",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Makes ropes use average of cubemap lighting instead of max intensity.");
  return atexit(func: dynamic_atexit_destructor_for__rope_averagelight__);
}

//------------------------------------------------------------------------------
// Address: 0x10413500
// Name: _dynamic_initializer_for__rope_rendersolid__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rope_rendersolid__()
{
  ConVar::ConVar(this: &rope_rendersolid, pName: "rope_rendersolid", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__rope_rendersolid__);
}

//------------------------------------------------------------------------------
// Address: 0x10413530
// Name: _dynamic_initializer_for__rope_solid_minwidth__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rope_solid_minwidth__()
{
  ConVar::ConVar(this: &rope_solid_minwidth, pName: "rope_solid_minwidth", pDefaultValue: "0.3", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__rope_solid_minwidth__);
}

//------------------------------------------------------------------------------
// Address: 0x10413560
// Name: _dynamic_initializer_for__rope_solid_maxwidth__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rope_solid_maxwidth__()
{
  ConVar::ConVar(this: &rope_solid_maxwidth, pName: "rope_solid_maxwidth", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__rope_solid_maxwidth__);
}

//------------------------------------------------------------------------------
// Address: 0x10413590
// Name: _dynamic_initializer_for__rope_solid_minalpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rope_solid_minalpha__()
{
  ConVar::ConVar(this: &rope_solid_minalpha, pName: "rope_solid_minalpha", pDefaultValue: "0.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__rope_solid_minalpha__);
}

//------------------------------------------------------------------------------
// Address: 0x104135C0
// Name: _dynamic_initializer_for__rope_solid_maxalpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rope_solid_maxalpha__()
{
  ConVar::ConVar(this: &rope_solid_maxalpha, pName: "rope_solid_maxalpha", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__rope_solid_maxalpha__);
}

//------------------------------------------------------------------------------
// Address: 0x10413680
// Name: ShakeRopesPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int ShakeRopesPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  ShakeRopesPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&ShakeRopesPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430910
// Name: DT_RopeKeyframe::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_RopeKeyframe::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_RopeKeyframe::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10430920
// Name: _dynamic_atexit_destructor_for__rope_shake__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rope_shake__()
{
  ConVar::~ConVar(this: &rope_shake);
}

//------------------------------------------------------------------------------
// Address: 0x10430930
// Name: _dynamic_atexit_destructor_for__rope_subdiv__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rope_subdiv__()
{
  ConVar::~ConVar(this: &rope_subdiv);
}

//------------------------------------------------------------------------------
// Address: 0x10430940
// Name: _dynamic_atexit_destructor_for__rope_collide__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rope_collide__()
{
  ConVar::~ConVar(this: &rope_collide);
}

//------------------------------------------------------------------------------
// Address: 0x10430950
// Name: _dynamic_atexit_destructor_for__rope_smooth__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rope_smooth__()
{
  ConVar::~ConVar(this: &rope_smooth);
}

//------------------------------------------------------------------------------
// Address: 0x10430960
// Name: _dynamic_atexit_destructor_for__rope_smooth_enlarge__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rope_smooth_enlarge__()
{
  ConVar::~ConVar(this: &rope_smooth_enlarge);
}

//------------------------------------------------------------------------------
// Address: 0x10430970
// Name: _dynamic_atexit_destructor_for__rope_smooth_minwidth__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rope_smooth_minwidth__()
{
  ConVar::~ConVar(this: &rope_smooth_minwidth);
}

//------------------------------------------------------------------------------
// Address: 0x10430980
// Name: _dynamic_atexit_destructor_for__rope_smooth_minalpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rope_smooth_minalpha__()
{
  ConVar::~ConVar(this: &rope_smooth_minalpha);
}

//------------------------------------------------------------------------------
// Address: 0x10430990
// Name: _dynamic_atexit_destructor_for__rope_smooth_maxalphawidth__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rope_smooth_maxalphawidth__()
{
  ConVar::~ConVar(this: &rope_smooth_maxalphawidth);
}

//------------------------------------------------------------------------------
// Address: 0x104309A0
// Name: _dynamic_atexit_destructor_for__rope_smooth_maxalpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rope_smooth_maxalpha__()
{
  ConVar::~ConVar(this: &rope_smooth_maxalpha);
}

//------------------------------------------------------------------------------
// Address: 0x104309E0
// Name: _dynamic_atexit_destructor_for__rope_wind_dist__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rope_wind_dist__()
{
  ConVar::~ConVar(this: &rope_wind_dist);
}

//------------------------------------------------------------------------------
// Address: 0x104309F0
// Name: _dynamic_atexit_destructor_for__rope_averagelight__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rope_averagelight__()
{
  ConVar::~ConVar(this: &rope_averagelight);
}

//------------------------------------------------------------------------------
// Address: 0x10430A00
// Name: _dynamic_atexit_destructor_for__rope_rendersolid__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rope_rendersolid__()
{
  ConVar::~ConVar(this: &rope_rendersolid);
}

//------------------------------------------------------------------------------
// Address: 0x10430A10
// Name: _dynamic_atexit_destructor_for__rope_solid_minwidth__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rope_solid_minwidth__()
{
  ConVar::~ConVar(this: &rope_solid_minwidth);
}

//------------------------------------------------------------------------------
// Address: 0x10430A20
// Name: _dynamic_atexit_destructor_for__rope_solid_maxwidth__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rope_solid_maxwidth__()
{
  ConVar::~ConVar(this: &rope_solid_maxwidth);
}

//------------------------------------------------------------------------------
// Address: 0x10430A30
// Name: _dynamic_atexit_destructor_for__rope_solid_minalpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rope_solid_minalpha__()
{
  ConVar::~ConVar(this: &rope_solid_minalpha);
}

//------------------------------------------------------------------------------
// Address: 0x10430A40
// Name: _dynamic_atexit_destructor_for__rope_solid_maxalpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rope_solid_maxalpha__()
{
  ConVar::~ConVar(this: &rope_solid_maxalpha);
}

//------------------------------------------------------------------------------
// Address: 0x10087060
// Name: _C_RopeKeyframe_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_RopeKeyframe_CreateObject(int entnum, int serialNum)
{
  C_RopeKeyframe *v2; // eax
  C_RopeKeyframe *v3; // eax
  C_RopeKeyframe *v4; // esi

  v2 = (C_RopeKeyframe *)C_BaseEntity::operator new(stAllocateBlock: 0xCF8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_RopeKeyframe::C_RopeKeyframe(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x104131F0
// Name: _dynamic_initializer_for____g_C_RopeKeyframeClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_RopeKeyframeClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_RopeKeyframeClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_RopeKeyframeClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413410
// Name: _dynamic_initializer_for__mat_fullbright__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_fullbright__()
{
  ConVar::ConVar(this: &mat_fullbright, pName: "mat_fullbright", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_fullbright__);
}

//------------------------------------------------------------------------------
// Address: 0x10413440
// Name: _dynamic_initializer_for__r_drawropes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawropes__()
{
  ConVar::ConVar(this: &r_drawropes, pName: "r_drawropes", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_drawropes__);
}

//------------------------------------------------------------------------------
// Address: 0x10413470
// Name: _dynamic_initializer_for__r_ropetranslucent__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_ropetranslucent__()
{
  ConVar::ConVar(this: &r_ropetranslucent, pName: "r_ropetranslucent", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_ropetranslucent__);
}

//------------------------------------------------------------------------------
// Address: 0x104135F0
// Name: _dynamic_initializer_for__g_Ropes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Ropes__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Ropes__);
}

//------------------------------------------------------------------------------
// Address: 0x10413600
// Name: _dynamic_initializer_for__g_FullBrightLightValuesInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFullBrightLightValuesInit *dynamic_initializer_for__g_FullBrightLightValuesInit__()
{
  return CFullBrightLightValuesInit::CFullBrightLightValuesInit(this: &g_FullBrightLightValuesInit);
}

//------------------------------------------------------------------------------
// Address: 0x10413610
// Name: _dynamic_initializer_for__s_RopeManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_RopeManager__()
{
  CRopeManager::CRopeManager(this: &s_RopeManager);
  return atexit(func: dynamic_atexit_destructor_for__s_RopeManager__);
}

//------------------------------------------------------------------------------
// Address: 0x10413630
// Name: _dynamic_initializer_for__r_queued_ropes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_queued_ropes__()
{
  ConVar::ConVar(this: &r_queued_ropes, pName: "r_queued_ropes", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_queued_ropes__);
}

//------------------------------------------------------------------------------
// Address: 0x10413660
// Name: _dynamic_initializer_for__ClientEffectReg_ShakeRopesCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_ShakeRopesCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_ShakeRopesCallback,
           pEffectName: "ShakeRopes",
           fn: ShakeRopesCallback);
}

//------------------------------------------------------------------------------
// Address: 0x104136A0
// Name: _dynamic_initializer_for____g_C_SceneEntityClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_SceneEntityClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_SceneEntityClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_SceneEntityClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104309B0
// Name: _dynamic_atexit_destructor_for__mat_fullbright__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_fullbright__()
{
  ConVar::~ConVar(this: &mat_fullbright);
}

//------------------------------------------------------------------------------
// Address: 0x104309C0
// Name: _dynamic_atexit_destructor_for__r_drawropes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawropes__()
{
  ConVar::~ConVar(this: &r_drawropes);
}

//------------------------------------------------------------------------------
// Address: 0x104309D0
// Name: _dynamic_atexit_destructor_for__r_ropetranslucent__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_ropetranslucent__()
{
  ConVar::~ConVar(this: &r_ropetranslucent);
}

//------------------------------------------------------------------------------
// Address: 0x10430A50
// Name: _dynamic_atexit_destructor_for__r_queued_ropes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_queued_ropes__()
{
  ConVar::~ConVar(this: &r_queued_ropes);
}

//------------------------------------------------------------------------------
// Address: 0x10430A60
// Name: _dynamic_atexit_destructor_for__g_Ropes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Ropes__()
{
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&g_Ropes);
  if ( g_Ropes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_Ropes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_Ropes.m_Memory.m_pMemory);
      g_Ropes.m_Memory.m_pMemory = nullptr;
    }
    g_Ropes.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10430AB0
// Name: _dynamic_atexit_destructor_for__s_RopeManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_RopeManager__()
{
  CRopeManager::~CRopeManager(this: &s_RopeManager);
}
