// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/studiomodel.cpp
// Functions: 34
// ============================================================

#include "hammer\studiomodel.h"

//------------------------------------------------------------------------------
// Address: 0x100B1620
// Name: protected: static int CStudioModelCache::AddModel(class StudioModel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CStudioModelCache::AddModel(StudioModel *pModel, const char *pszModelPath)
{
  _BYTE *v2; // eax
  const char *v3; // ecx
  int v4; // edx
  char v5; // al
  int v6; // ecx

  CStudioModelCache::m_Cache[CStudioModelCache::m_nItems].pModel = pModel;
  v2 = operator new[](nSize: strlen(pszModelPath) + 1);
  dword_107AC304[3 * CStudioModelCache::m_nItems] = (int)v2;
  if ( v2 == nullptr )
    return 0;
  v3 = pszModelPath;
  v4 = v2 - pszModelPath;
  do
  {
    v5 = *v3;
    v3[v4] = *v3;
    ++v3;
  }
  while ( v5 != 0 );
  v6 = 3 * CStudioModelCache::m_nItems++;
  dword_107AC308[v6] = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B16A0
// Name: public: StudioModel::StudioModel(void)
// Source: json
//------------------------------------------------------------------------------
StudioModel *__thiscall StudioModel::StudioModel(StudioModel *this)
{
  this->m_pModelName = nullptr;
  this->m_origin.x = 0.0;
  this->m_origin.y = 0.0;
  this->m_origin.z = 0.0;
  this->m_angles.x = 0.0;
  this->m_angles.y = 0.0;
  this->m_angles.z = 0.0;
  this->m_sequence = 0;
  this->m_cycle = 0.0;
  this->m_bodynum = 0;
  this->m_skinnum = 0;
  *(_DWORD *)this->m_controller = 0;
  this->m_poseParameter[0] = 0.0;
  this->m_poseParameter[1] = 0.0;
  this->m_poseParameter[2] = 0.0;
  this->m_poseParameter[3] = 0.0;
  this->m_poseParameter[4] = 0.0;
  this->m_poseParameter[5] = 0.0;
  this->m_poseParameter[6] = 0.0;
  this->m_poseParameter[7] = 0.0;
  this->m_poseParameter[8] = 0.0;
  this->m_poseParameter[9] = 0.0;
  this->m_poseParameter[10] = 0.0;
  this->m_poseParameter[11] = 0.0;
  this->m_poseParameter[12] = 0.0;
  this->m_poseParameter[13] = 0.0;
  this->m_poseParameter[14] = 0.0;
  this->m_poseParameter[15] = 0.0;
  this->m_poseParameter[16] = 0.0;
  this->m_poseParameter[17] = 0.0;
  this->m_poseParameter[18] = 0.0;
  this->m_poseParameter[19] = 0.0;
  this->m_poseParameter[20] = 0.0;
  this->m_poseParameter[21] = 0.0;
  this->m_poseParameter[22] = 0.0;
  this->m_poseParameter[23] = 0.0;
  this->m_mouth = 0;
  this->m_MDLHandle = -1;
  this->m_pModel = nullptr;
  this->m_pStudioHdr = nullptr;
  this->m_pPosePos = nullptr;
  this->m_pPoseAng = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B1760
// Name: public: void StudioModel::SetAngles(class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::SetAngles(StudioModel *this, QAngle *pfAngles)
{
  this->m_angles = *pfAngles;
}

//------------------------------------------------------------------------------
// Address: 0x100B1780
// Name: public: int StudioModel::GetSequenceCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::GetSequenceCount(StudioModel *this)
{
  CStudioHdr *m_pStudioHdr; // ecx
  const studiohdr_t *v3; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
  }
  if ( m_pStudioHdr->m_pVModel != nullptr )
    return CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr);
  else
    return m_pStudioHdr->m_pStudioHdr->numlocalseq;
}

//------------------------------------------------------------------------------
// Address: 0x100B17C0
// Name: public: void StudioModel::GetSequenceName(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::GetSequenceName(StudioModel *this, int nIndex, char *szName)
{
  CStudioHdr *m_pStudioHdr; // esi
  const studiohdr_t *v5; // eax
  int NumSeq_Internal; // ecx
  int v7; // eax
  const studiohdr_t *v8; // esi
  mstudioseqdesc_t *v9; // eax
  char *v11; // ecx
  char v12; // al

  m_pStudioHdr = this->m_pStudioHdr;
  if ( this->m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
  }
  if ( m_pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr);
  else
    NumSeq_Internal = m_pStudioHdr->m_pStudioHdr->numlocalseq;
  v7 = nIndex;
  if ( nIndex < NumSeq_Internal )
  {
    if ( m_pStudioHdr->m_pVModel != nullptr )
    {
      v9 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: nIndex);
    }
    else
    {
      v8 = m_pStudioHdr->m_pStudioHdr;
      if ( nIndex < 0 || nIndex >= v8->numlocalseq )
        v7 = 0;
      v9 = (mstudioseqdesc_t *)((char *)v8 + 212 * v7 + v8->localseqindex);
    }
    v11 = (char *)v9 + v9->szlabelindex;
    do
    {
      v12 = *v11;
      *szName++ = *v11++;
    }
    while ( v12 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B1860
// Name: public: int StudioModel::SetSequence(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::SetSequence(StudioModel *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // ecx
  const studiohdr_t *v4; // eax
  int NumSeq_Internal; // ecx
  int result; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
  }
  if ( m_pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr);
  else
    NumSeq_Internal = m_pStudioHdr->m_pStudioHdr->numlocalseq;
  result = iSequence;
  if ( iSequence > NumSeq_Internal )
    return this->m_sequence;
  this->m_sequence = iSequence;
  this->m_cycle = 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B18D0
// Name: public: void StudioModel::RotateBbox(class Vector __near &,class Vector __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::RotateBbox(StudioModel *this, Vector *Mins, Vector *Maxs, const QAngle *Angles)
{
  int i; // esi
  int v5; // eax
  float *p_y; // ecx
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  Vector RotatedPoints[8]; // [esp+Ch] [ebp-130h] BYREF
  Vector Points[8]; // [esp+6Ch] [ebp-D0h] BYREF
  VMatrix mMatrix; // [esp+CCh] [ebp-70h] BYREF
  matrix3x4_t fMatrix2; // [esp+10Ch] [ebp-30h] BYREF

  PointsFromBox(mins: Mins, maxs: Maxs, points: Points);
  VMatrix::SetupMatrixOrgAngles(this: &mMatrix, origin: &vec3_origin, vAngles: Angles);
  fMatrix2 = *(matrix3x4_t *)&mMatrix.m[0][0];
  for ( i = 0; i < 8; ++i )
    VectorRotate(in1: &Points[i].x, in2: &fMatrix2, out: &RotatedPoints[i].x);
  v5 = 0;
  p_y = &RotatedPoints[0].y;
  do
  {
    if ( v5 == 0 || (v7 = *(p_y - 1), Mins->x > v7) )
    {
      v7 = *(p_y - 1);
      Mins->x = v7;
    }
    if ( v5 == 0 || v7 > Maxs->x )
      Maxs->x = v7;
    if ( v5 == 0 || (v8 = *p_y, Mins->y > *p_y) )
    {
      v8 = *p_y;
      Mins->y = *p_y;
    }
    if ( v5 == 0 || v8 > Maxs->y )
      Maxs->y = v8;
    if ( v5 == 0 || (v9 = p_y[1], Mins->z > v9) )
    {
      v9 = p_y[1];
      Mins->z = v9;
    }
    if ( v5 == 0 || v9 > Maxs->z )
      Maxs->z = v9;
    ++v5;
    p_y += 3;
  }
  while ( v5 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x100B1A10
// Name: public: void StudioModel::ExtractBbox(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::ExtractBbox(StudioModel *this, Vector *mins, Vector *maxs)
{
  CStudioHdr *m_pStudioHdr; // ecx
  const studiohdr_t *v5; // eax
  int m_sequence; // eax
  const studiohdr_t *v7; // ecx
  mstudioseqdesc_t *v8; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
  }
  m_sequence = this->m_sequence;
  if ( m_pStudioHdr->m_pVModel != nullptr )
  {
    v8 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: this->m_sequence);
  }
  else
  {
    v7 = m_pStudioHdr->m_pStudioHdr;
    if ( m_sequence < 0 || m_sequence >= v7->numlocalseq )
      m_sequence = 0;
    v8 = (mstudioseqdesc_t *)((char *)v7 + 212 * m_sequence + v7->localseqindex);
  }
  *mins = v8->bbmin;
  *maxs = v8->bbmax;
  StudioModel::RotateBbox(this, Mins: mins, Maxs: maxs, Angles: &this->m_angles);
}

//------------------------------------------------------------------------------
// Address: 0x100B1AB0
// Name: public: void StudioModel::ExtractMovementBbox(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::ExtractMovementBbox(StudioModel *this, Vector *mins, Vector *maxs)
{
  CStudioHdr *m_pStudioHdr; // esi
  const studiohdr_t *v5; // eax
  const studiohdr_t *v6; // eax

  if ( this->m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    m_pStudioHdr = this->m_pStudioHdr;
  }
  else
  {
    v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
  }
  if ( m_pStudioHdr != nullptr )
    v6 = m_pStudioHdr->m_pStudioHdr;
  else
    v6 = nullptr;
  *mins = v6->hull_min;
  *maxs = v6->hull_max;
}

//------------------------------------------------------------------------------
// Address: 0x100B1B20
// Name: public: void StudioModel::SetOrigin(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::SetOrigin(StudioModel *this, float x, float y, float z)
{
  this->m_origin.x = x;
  this->m_origin.y = y;
  this->m_origin.z = z;
}

//------------------------------------------------------------------------------
// Address: 0x100B1B50
// Name: public: int StudioModel::SetBodygroups(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::SetBodygroups(StudioModel *this, int iValue)
{
  this->m_bodynum = iValue;
  return iValue;
}

//------------------------------------------------------------------------------
// Address: 0x100B1B60
// Name: public: int StudioModel::SetBodygroup(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::SetBodygroup(StudioModel *this, int iGroup, int iValue)
{
  int result; // eax
  const studiohdr_t *v5; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // ebx
  int v9; // edi

  result = (int)this->m_pStudioHdr;
  if ( this->m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
    result = (int)this->m_pStudioHdr;
  }
  if ( result != 0 )
  {
    v6 = *(_DWORD *)result;
    if ( iGroup <= *(_DWORD *)(*(_DWORD *)result + 232) )
    {
      v7 = 16 * iGroup + *(_DWORD *)(v6 + 236);
      v8 = *(_DWORD *)(v7 + v6 + 8);
      if ( v8 != 0 && *(_DWORD *)(v7 + v6 + 4) != 0 )
      {
        v9 = *(_DWORD *)(v7 + v6 + 4);
        result = iValue;
        if ( iValue < v9 )
          this->m_bodynum += v8 * (iValue - this->m_bodynum / v8 % v9);
        else
          return this->m_bodynum / v8 % v9;
      }
      else
      {
        return -1;
      }
    }
    else
    {
      return -1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B1C10
// Name: public: int StudioModel::SetSkin(int)
// Source: json
//------------------------------------------------------------------------------
CStudioHdr *__thiscall StudioModel::SetSkin(StudioModel *this, CStudioHdr *iValue)
{
  CStudioHdr *result; // eax
  const studiohdr_t *v4; // eax
  const studiohdr_t *m_pStudioHdr; // ecx

  result = this->m_pStudioHdr;
  if ( this->m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    result = this->m_pStudioHdr;
  }
  if ( result != nullptr )
  {
    m_pStudioHdr = result->m_pStudioHdr;
    result = iValue;
    if ( (int)iValue >= m_pStudioHdr->numskinfamilies )
      result = nullptr;
    this->m_skinnum = (int)result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B1C60
// Name: public: char const __near * StudioModel::GetModelName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall StudioModel::GetModelName(StudioModel *this)
{
  return this->m_pModelName;
}

//------------------------------------------------------------------------------
// Address: 0x100B1C70
// Name: public: int StudioModel::GetMaxFrame(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::GetMaxFrame(StudioModel *this)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v3; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( this->m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
  }
  return Studio_MaxFrame(pStudioHdr: m_pStudioHdr, iSequence: this->m_sequence, poseParameter: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100B1CB0
// Name: private: void StudioModel::SetUpBones(bool,class matrix3x4a_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::SetUpBones(StudioModel *this, IBoneSetup bUpdatePose, CBoneSetup *pBoneToWorld)
{
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v5; // eax
  IPoseDebugger *v6; // eax
  CBoneSetup *v7; // ecx
  int v8; // ebx
  Vector *m_pPosePos; // eax
  float v10; // xmm0_4
  int v11; // eax
  const studiohdr_t *v12; // ecx
  float flTime[5]; // [esp+1Ch] [ebp-88h] BYREF
  matrix3x4_t cameraTransform; // [esp+30h] [ebp-74h] BYREF
  matrix3x4_t bonematrix; // [esp+60h] [ebp-44h] BYREF
  CBoneAccessor bonetoworld; // [esp+90h] [ebp-14h]
  mstudiobone_t *pbones; // [esp+A0h] [ebp-4h]

  m_pStudioHdr = this->m_pStudioHdr;
  if ( this->m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
  }
  if ( this->m_pPosePos != nullptr )
  {
    if ( LOBYTE(bUpdatePose.m_pBoneSetup) == 0 )
      goto LABEL_10;
  }
  else
  {
    bUpdatePose.m_pBoneSetup = (CBoneSetup *)operator new[](nSize: 12 * m_pStudioHdr->m_pStudioHdr->numbones);
    pbones = (mstudiobone_t *)-1;
    this->m_pPosePos = (Vector *)bUpdatePose.m_pBoneSetup;
    v6 = (IPoseDebugger *)_g_pMemAlloc->Alloc_2(
                            this: _g_pMemAlloc,
                            a2: (unsigned __int64)(unsigned int)m_pStudioHdr->m_pStudioHdr->numbones >> 28 != 0
                          ? 18
                          : 16 * m_pStudioHdr->m_pStudioHdr->numbones + 19);
    if ( v6 != nullptr )
    {
      v7 = (CBoneSetup *)(((unsigned int)&v6[4].__vftable + 3) & 0xFFFFFFF0);
      v7[-1].m_pPoseDebugger = v6;
    }
    else
    {
      v7 = nullptr;
    }
    bUpdatePose.m_pBoneSetup = v7;
    pbones = (mstudiobone_t *)-1;
    this->m_pPoseAng = (QuaternionAligned *)v7;
  }
  IBoneSetup::IBoneSetup(
    this: &bUpdatePose,
    pStudioHdr: m_pStudioHdr,
    boneMask: 524032,
    poseParameter: this->m_poseParameter,
    pPoseDebugger: nullptr);
  pbones = (mstudiobone_t *)2;
  IBoneSetup::InitPose(this: &bUpdatePose, pos: this->m_pPosePos, q: this->m_pPoseAng);
  IBoneSetup::AccumulatePose(
    this: &bUpdatePose,
    pos: this->m_pPosePos,
    q: this->m_pPoseAng,
    sequence: this->m_sequence,
    cycle: this->m_cycle,
    flWeight: 1.0,
    flTime: 0.0,
    pIKContext: nullptr);
  pbones = (mstudiobone_t *)-1;
  IBoneSetup::~IBoneSetup(this: &bUpdatePose);
LABEL_10:
  LODWORD(bonematrix.m_flMatVal[2][3]) = (char *)m_pStudioHdr->m_pStudioHdr + m_pStudioHdr->m_pStudioHdr->boneindex;
  AngleMatrix(angles: &this->m_angles, matrix: (matrix3x4_t *)flTime);
  flTime[3] = this->m_origin.x;
  cameraTransform.m_flMatVal[0][2] = this->m_origin.y;
  cameraTransform.m_flMatVal[1][2] = this->m_origin.z;
  v8 = 0;
  if ( m_pStudioHdr->m_pStudioHdr->numbones > 0 )
  {
    bonetoworld.m_pAnimating = nullptr;
    bonetoworld.m_pBones = nullptr;
    bUpdatePose.m_pBoneSetup = pBoneToWorld;
    LODWORD(bonematrix.m_flMatVal[2][3]) += 4;
    do
    {
      bonematrix.m_flMatVal[1][3] = 0.0;
      LODWORD(bonematrix.m_flMatVal[2][0]) = pBoneToWorld;
      if ( !CalcProceduralBone(
              pStudioHdr: m_pStudioHdr,
              iBone: v8,
              bonetoworld: (CBoneAccessor *)&bonematrix.m_flMatVal[1][3]) )
      {
        QuaternionMatrix(
          q: (const Quaternion *)((char *)bonetoworld.m_pBones + (unsigned int)this->m_pPoseAng),
          matrix: (matrix3x4_t *)&cameraTransform.m_flMatVal[1][3]);
        m_pPosePos = this->m_pPosePos;
        cameraTransform.m_flMatVal[2][2] = *(float *)((char *)&m_pPosePos->x + (unsigned int)bonetoworld.m_pAnimating);
        bonematrix.m_flMatVal[0][2] = *(float *)((char *)&m_pPosePos->y + (unsigned int)bonetoworld.m_pAnimating);
        v10 = *(float *)((char *)&m_pPosePos->z + (unsigned int)bonetoworld.m_pAnimating);
        v11 = *(_DWORD *)LODWORD(bonematrix.m_flMatVal[2][3]);
        bonematrix.m_flMatVal[1][2] = v10;
        if ( v11 == -1 )
          ConcatTransforms(
            in1: (const matrix3x4_t *)flTime,
            in2: (matrix3x4_t *)&cameraTransform.m_flMatVal[1][3],
            out: (matrix3x4_t *)bUpdatePose.m_pBoneSetup);
        else
          ConcatTransforms(
            in1: (const matrix3x4_t *)&pBoneToWorld[3 * v11],
            in2: (matrix3x4_t *)&cameraTransform.m_flMatVal[1][3],
            out: (matrix3x4_t *)bUpdatePose.m_pBoneSetup);
      }
      v12 = m_pStudioHdr->m_pStudioHdr;
      bonetoworld.m_pBones = (matrix3x4a_t *)((char *)bonetoworld.m_pBones + 16);
      bonetoworld.m_pAnimating = (const struct C_BaseAnimating *)((char *)bonetoworld.m_pAnimating + 12);
      bUpdatePose.m_pBoneSetup += 3;
      LODWORD(bonematrix.m_flMatVal[2][3]) += 216;
      ++v8;
    }
    while ( v8 < v12->numbones );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B1F50
// Name: public: bool StudioModel::IsTranslucent(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall StudioModel::IsTranslucent(StudioModel *this)
{
  studiohwdata_t *v1; // eax
  studiohwdata_t *v2; // esi
  int m_RootLOD; // eax
  int i; // ebx
  int v6; // edi
  IMaterial *v7; // ecx
  int lodID; // [esp+4h] [ebp-4h]

  v1 = g_pMDLCache->GetHardwareData(this: g_pMDLCache, a2: this->m_MDLHandle);
  v2 = v1;
  if ( v1 == nullptr )
    return 0;
  m_RootLOD = v1->m_RootLOD;
  lodID = m_RootLOD;
  if ( m_RootLOD >= v2->m_NumLODs )
    return 0;
  for ( i = m_RootLOD; ; ++i )
  {
    v6 = 0;
    if ( v2->m_pLODs[i].numMaterials > 0 )
      break;
LABEL_9:
    lodID = ++m_RootLOD;
    if ( m_RootLOD >= v2->m_NumLODs )
      return 0;
  }
  while ( 1 )
  {
    v7 = v2->m_pLODs[i].ppMaterials[v6];
    if ( v7->IsTranslucent(this: v7) )
      return 1;
    if ( ++v6 >= v2->m_pLODs[i].numMaterials )
    {
      m_RootLOD = lodID;
      goto LABEL_9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B1FE0
// Name: public: bool StudioModel::PostLoadModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall StudioModel::PostLoadModel(StudioModel *this, const char *modelname)
{
  CStudioHdr *m_pStudioHdr; // ebx
  const studiohdr_t *v4; // eax
  int v6; // edi
  CStudioHdr *v7; // eax
  const studiohdr_t *v8; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( this->m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  StudioModel::SetSequence(this, iSequence: 0);
  v6 = 0;
  if ( m_pStudioHdr->m_pStudioHdr->numbodyparts <= 0 )
  {
LABEL_8:
    v7 = this->m_pStudioHdr;
    if ( this->m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v8 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
      CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v8, mdlcache: nullptr);
      v7 = this->m_pStudioHdr;
    }
    if ( v7 != nullptr )
      this->m_skinnum = 0;
    return 1;
  }
  else
  {
    while ( StudioModel::SetBodygroup(this, iGroup: v6, iValue: 0) >= 0 )
    {
      if ( ++v6 >= m_pStudioHdr->m_pStudioHdr->numbodyparts )
        goto LABEL_8;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2090
// Name: public: void StudioModel::SetFrame(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::SetFrame(StudioModel *this, int nFrame)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  int v5; // edi
  const studiohdr_t *v6; // eax
  int v7; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( this->m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
  }
  if ( m_pStudioHdr != nullptr )
  {
    v5 = nFrame;
    if ( nFrame <= 0 )
      v5 = 0;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v6 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
      CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v6, mdlcache: nullptr);
      m_pStudioHdr = this->m_pStudioHdr;
    }
    v7 = Studio_MaxFrame(pStudioHdr: m_pStudioHdr, iSequence: this->m_sequence, poseParameter: nullptr);
    if ( v5 < v7 )
      this->m_cycle = (float)v5 / (float)v7;
    else
      this->m_cycle = 0.99998999;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2140
// Name: public: static void CStudioModelCache::AdvanceAnimation(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CStudioModelCache::AdvanceAnimation(float flInterval)
{
  int v1; // edi
  ModelCache_t *v2; // ebx
  StudioModel *pModel; // esi
  const CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  double v6; // st7
  float v7; // xmm0_4
  float v8; // [esp+4h] [ebp-8h]
  float v9; // [esp+8h] [ebp-4h]

  v1 = 0;
  if ( CStudioModelCache::m_nItems > 0 )
  {
    v2 = CStudioModelCache::m_Cache;
    do
    {
      pModel = v2->pModel;
      v9 = flInterval;
      if ( flInterval > 0.1 )
        v9 = 0.1;
      m_pStudioHdr = pModel->m_pStudioHdr;
      if ( pModel->m_pStudioHdr->m_pStudioHdr == nullptr )
      {
        v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: pModel->m_MDLHandle);
        CStudioHdr::Init(this: pModel->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
        m_pStudioHdr = pModel->m_pStudioHdr;
      }
      v6 = Studio_Duration(
             pStudioHdr: m_pStudioHdr,
             iSequence: pModel->m_sequence,
             poseParameter: pModel->m_poseParameter);
      if ( v6 <= 0.0 )
      {
        v7 = 0.0;
      }
      else
      {
        v8 = v6;
        v7 = (float)((float)(v9 / v8) + pModel->m_cycle) - (float)(int)(float)((float)(v9 / v8) + pModel->m_cycle);
      }
      ++v1;
      pModel->m_cycle = v7;
      ++v2;
    }
    while ( v1 < CStudioModelCache::m_nItems );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2210
// Name: public: void CStudioFileChangeWatcher::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioFileChangeWatcher::Init(CStudioFileChangeWatcher *this)
{
  CFileChangeWatcher *p_m_Watcher; // edi
  int v2; // esi
  char pString[16384]; // [esp+8h] [ebp-4024h] BYREF
  CSplitString v4; // [esp+4008h] [ebp-24h] BYREF
  int v5; // [esp+4028h] [ebp-4h]

  p_m_Watcher = &this->m_Watcher;
  CFileChangeWatcher::Init(this: &this->m_Watcher, pCallbacks: this);
  v2 = 0;
  if ( g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "GAME", a3: false, a4: pString, a5: 0x4000) <= 0 )
  {
    _Warning(a1: "Error in GetSearchPath. Hammer will not automatically reload modified models.");
  }
  else
  {
    CSplitString::CSplitString(this: &v4, pString, pSeparator: ";");
    v5 = 0;
    if ( v4.m_Size > 0 )
    {
      do
        CFileChangeWatcher::AddDirectory(
          this: p_m_Watcher,
          pSearchPathBase: v4.m_Memory.m_pMemory[v2++],
          pDirName: "models",
          bRecursive: true);
      while ( v2 < v4.m_Size );
    }
    v5 = -1;
    CSplitString::~CSplitString(this: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B22E0
// Name: void InitStudioFileChangeWatcher(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitStudioFileChangeWatcher()
{
  CStudioFileChangeWatcher::Init(this: &g_StudioFileChangeWatcher);
}

//------------------------------------------------------------------------------
// Address: 0x100B22F0
// Name: public: void StudioModel::DrawModel3D(class CRender3D __near *,class Color const __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge StudioModel::DrawModel3D(
        StudioModel *this@<ecx>,
        int a2@<ebx>,
        CRender3D *pRender,
        const Color *color,
        float flAlpha,
        bool bWireframe)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v8; // eax
  const studiohdr_t *v9; // eax
  int v10; // eax
  int v11; // ebx
  int m_MDLHandle; // eax
  studiohwdata_t *v13; // eax
  int m_bodynum; // ecx
  int m_skinnum; // eax
  float z; // edx
  Vector *p_m_origin; // edi
  __int64 v18; // xmm0_8
  float v19; // eax
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  matrix3x4_t *v23; // eax
  float v24; // xmm5_4
  CStudioHdr *v25; // eax
  const studiohdr_t *v26; // eax
  int v27; // edx
  int (__thiscall *v28)(int, int); // eax
  matrix3x4_t *v29; // eax
  CStudioHdr *v30; // eax
  const studiohdr_t *v31; // eax
  int v32; // edx
  int (__thiscall *v33)(int, int); // eax
  DrawModelInfo_t pInfo; // [esp+18h] [ebp-2C0h] BYREF
  _BYTE v35[32]; // [esp+1F8h] [ebp-E0h] BYREF
  matrix3x4_t fCurrentMatrix; // [esp+218h] [ebp-C0h] BYREF
  matrix3x4_t fMatrixNew; // [esp+248h] [ebp-90h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+278h] [ebp-60h]
  VMatrix mViewMatrix; // [esp+27Ch] [ebp-5Ch] BYREF
  QAngle orgAngles; // [esp+2BCh] [ebp-1Ch]
  matrix3x4_t *pBoneToWorld; // [esp+2C8h] [ebp-10h]
  Vector orgOrigin; // [esp+2CCh] [ebp-Ch]

  m_pStudioHdr = this->m_pStudioHdr;
  if ( this->m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v8 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v8, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
  }
  if ( m_pStudioHdr != nullptr )
  {
    v9 = m_pStudioHdr->m_pStudioHdr;
    pBoneToWorld = (matrix3x4_t *)v9;
    if ( v9 != nullptr && v9->numbodyparts != 0 )
    {
      v10 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
      v11 = v10;
      LODWORD(fMatrixNew.m_flMatVal[1][0]) = v10;
      orgOrigin.z = 0.0;
      if ( v10 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
      LODWORD(orgOrigin.z) = 1;
      m_MDLHandle = this->m_MDLHandle;
      pInfo.m_pStudioHdr = (studiohdr_t *)pBoneToWorld;
      v13 = g_pMDLCache->GetHardwareData(this: g_pMDLCache, a2: m_MDLHandle);
      m_bodynum = this->m_bodynum;
      pInfo.m_pHardwareData = v13;
      m_skinnum = this->m_skinnum;
      pInfo.m_Body = m_bodynum;
      pInfo.m_Decals = nullptr;
      pInfo.m_Skin = m_skinnum;
      pInfo.m_HitboxSet = 0;
      pInfo.m_pClientEntity = nullptr;
      pInfo.m_Lod = -1;
      pInfo.m_pColorMeshes = nullptr;
      if ( CRender::IsInLocalTransformMode(this: pRender) )
      {
        z = this->m_origin.z;
        p_m_origin = &this->m_origin;
        *(_QWORD *)&mViewMatrix.m[3][0] = *(_QWORD *)&this->m_origin.x;
        v18 = *(_QWORD *)&this->m_angles.x;
        pBoneToWorld = (matrix3x4_t *)&this->m_angles;
        v19 = this->m_angles.z;
        mViewMatrix.m[3][2] = z;
        *(_QWORD *)&mViewMatrix.m[2][0] = v18;
        mViewMatrix.m[2][2] = v19;
        CRender::GetLocalTranform(this: pRender, matrix: (VMatrix *)&fMatrixNew.m_flMatVal[1][1]);
        v20 = mViewMatrix.m[3][1];
        v21 = mViewMatrix.m[3][0];
        v22 = mViewMatrix.m[3][2];
        v23 = pBoneToWorld;
        *(float *)&v18 = 1.0
                       / (float)((float)((float)((float)(mViewMatrix.m[3][1] * mViewMatrix.m[1][1])
                                               + (float)(mViewMatrix.m[1][0] * mViewMatrix.m[3][0]))
                                       + (float)(mViewMatrix.m[3][2] * mViewMatrix.m[1][2]))
                               + mViewMatrix.m[1][3]);
        v24 = fMatrixNew.m_flMatVal[2][1];
        this->m_origin.x = (float)((float)((float)((float)(fMatrixNew.m_flMatVal[1][2] * mViewMatrix.m[3][1])
                                                 + (float)(fMatrixNew.m_flMatVal[1][1] * mViewMatrix.m[3][0]))
                                         + (float)(fMatrixNew.m_flMatVal[1][3] * mViewMatrix.m[3][2]))
                                 + fMatrixNew.m_flMatVal[2][0])
                         * *(float *)&v18;
        this->m_origin.y = (float)((float)((float)((float)(fMatrixNew.m_flMatVal[2][2] * v20) + (float)(v24 * v21))
                                         + (float)(fMatrixNew.m_flMatVal[2][3] * v22))
                                 + *(float *)&pRenderContext.m_pObject)
                         * *(float *)&v18;
        this->m_origin.z = (float)((float)((float)((float)(mViewMatrix.m[0][1] * v20)
                                                 + (float)(mViewMatrix.m[0][0] * v21))
                                         + (float)(mViewMatrix.m[0][2] * v22))
                                 + mViewMatrix.m[0][3])
                         * *(float *)&v18;
        AngleMatrix(angles: (const QAngle *)v23, matrix: (matrix3x4_t *)v35);
        ConcatTransforms(
          in1: (matrix3x4_t *)&fMatrixNew.m_flMatVal[1][1],
          in2: (const matrix3x4_t *)v35,
          out: (matrix3x4_t *)fCurrentMatrix.m_flMatVal[1]);
        MatrixAngles(src: (const VMatrix *)fCurrentMatrix.m_flMatVal[1], vAngles: (QAngle *)pBoneToWorld);
        v25 = this->m_pStudioHdr;
        if ( this->m_pStudioHdr->m_pStudioHdr == nullptr )
        {
          v26 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
          CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v26, mdlcache: nullptr);
          v25 = this->m_pStudioHdr;
        }
        v27 = *(_DWORD *)v11;
        LODWORD(orgAngles.y) = v25->m_pStudioHdr->numbones;
        orgAngles.x = 0.0;
        LOBYTE(orgAngles.z) = 0;
        v28 = *(int (__thiscall **)(int, int))(v27 + 392);
        LODWORD(mViewMatrix.m[3][3]) = v11;
        LODWORD(mViewMatrix.m[2][3]) = v28(a1: v11, a2: 48 * LODWORD(orgAngles.y));
        orgAngles.x = mViewMatrix.m[2][3];
        LOBYTE(orgAngles.z) = 1;
        LOBYTE(orgOrigin.z) = 2;
        StudioModel::SetUpBones(this, bUpdatePose: 0, pBoneToWorld: (CBoneSetup *)LODWORD(mViewMatrix.m[2][3]));
        CRender::DrawModel(
          this: pRender,
          a2: (int)p_m_origin,
          &pInfo,
          pBoneToWorld: (matrix3x4_t *)LODWORD(mViewMatrix.m[2][3]),
          vOrigin: &this->m_origin,
          fAlpha: flAlpha,
          bWireFrame: bWireframe,
          color);
        v29 = pBoneToWorld;
        *(_QWORD *)&p_m_origin->x = *(_QWORD *)&mViewMatrix.m[3][0];
        this->m_origin.z = mViewMatrix.m[3][2];
        *(_QWORD *)&v29->m_flMatVal[0][0] = *(_QWORD *)&mViewMatrix.m[2][0];
        v29->m_flMatVal[0][2] = mViewMatrix.m[2][2];
      }
      else
      {
        v30 = this->m_pStudioHdr;
        if ( this->m_pStudioHdr->m_pStudioHdr == nullptr )
        {
          v31 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
          CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v31, mdlcache: nullptr);
          v30 = this->m_pStudioHdr;
        }
        v32 = *(_DWORD *)v11;
        LODWORD(orgAngles.y) = v30->m_pStudioHdr->numbones;
        v33 = *(int (__thiscall **)(int, int))(v32 + 392);
        LODWORD(mViewMatrix.m[3][3]) = v11;
        LODWORD(orgAngles.x) = v33(a1: v11, a2: 48 * LODWORD(orgAngles.y));
        LOBYTE(orgAngles.z) = 1;
        LOBYTE(orgOrigin.z) = 3;
        StudioModel::SetUpBones(this, bUpdatePose: (IBoneSetup)1, pBoneToWorld: (CBoneSetup *)LODWORD(orgAngles.x));
        CRender::DrawModel(
          this: pRender,
          a2: (int)pRender,
          &pInfo,
          pBoneToWorld: (matrix3x4_t *)LODWORD(orgAngles.x),
          vOrigin: &this->m_origin,
          fAlpha: flAlpha,
          bWireFrame: bWireframe,
          color);
        if ( Options.general.bShowCollisionModels != 0 )
        {
          SetupMatrixOrgAngles(
            result: (VMatrix *)&fMatrixNew.m_flMatVal[1][1],
            origin: &this->m_origin,
            vAngles: &this->m_angles);
          CRender::DrawCollisionModel(
            this: pRender,
            a2: v11,
            a3: (int)this,
            mdlHandle: this->m_MDLHandle,
            mViewMatrix: (const VMatrix *)&fMatrixNew.m_flMatVal[1][1]);
        }
      }
      LOBYTE(orgOrigin.z) = 1;
      CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<float> *)&mViewMatrix.m[3][3]);
      LODWORD(orgOrigin.z) = 4;
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(a1: v11);
      orgOrigin.z = NAN;
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 4))(a1: v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2710
// Name: public: void StudioModel::DrawModel2D(class CRender2D __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge StudioModel::DrawModel2D(
        StudioModel *this@<ecx>,
        int a2@<esi>,
        CRender2D *pRender,
        float flAlpha,
        bool bWireFrame)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v7; // eax
  studiohdr_t *v8; // eax
  float z; // ecx
  float v10; // edx
  Vector *p_m_origin; // esi
  int p_m_angles; // ebx
  int m_MDLHandle; // edx
  studiohwdata_t *(__thiscall *GetHardwareData)(IMDLCache *, unsigned __int16); // eax
  studiohwdata_t *v15; // eax
  int m_skinnum; // ecx
  int m_bodynum; // edx
  float y; // xmm1_4
  float x; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  float v22; // xmm5_4
  int v23; // eax
  float v24; // esi
  CStudioHdr *v25; // eax
  const studiohdr_t *v26; // eax
  int v27; // edx
  int (__thiscall *v28)(_DWORD, int); // eax
  CBoneSetup *v29; // ebx
  DrawModelInfo_t pInfo; // [esp+18h] [ebp-2C8h] BYREF
  _BYTE v32[36]; // [esp+1F8h] [ebp-E8h] BYREF
  matrix3x4_t fMatrixNew; // [esp+21Ch] [ebp-C4h] BYREF
  matrix3x4_t fCurrentMatrix; // [esp+24Ch] [ebp-94h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+27Ch] [ebp-64h]
  VMatrix mViewMatrix; // [esp+280h] [ebp-60h] BYREF
  Vector origin; // [esp+2C0h] [ebp-20h] BYREF
  Color v38; // [esp+2CFh] [ebp-11h] BYREF
  bool v39; // [esp+2D3h] [ebp-Dh]
  int v40; // [esp+2DCh] [ebp-4h]

  m_pStudioHdr = this->m_pStudioHdr;
  if ( this->m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v7 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v7, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
  }
  if ( m_pStudioHdr != nullptr )
  {
    v8 = m_pStudioHdr->m_pStudioHdr;
    if ( v8 != nullptr && v8->numbodyparts != 0 )
    {
      z = this->m_origin.z;
      v10 = this->m_angles.z;
      p_m_origin = &this->m_origin;
      p_m_angles = (int)&this->m_angles;
      *(_QWORD *)&origin.x = *(_QWORD *)&this->m_origin.x;
      origin.z = z;
      mViewMatrix.m[2][2] = v10;
      m_MDLHandle = this->m_MDLHandle;
      pInfo.m_pStudioHdr = v8;
      *(_QWORD *)&mViewMatrix.m[2][0] = *(_QWORD *)&this->m_angles.x;
      GetHardwareData = g_pMDLCache->GetHardwareData;
      LODWORD(mViewMatrix.m[3][3]) = &this->m_origin;
      LODWORD(mViewMatrix.m[1][3]) = &this->m_angles;
      v15 = GetHardwareData(this: g_pMDLCache, a2: m_MDLHandle);
      m_skinnum = this->m_skinnum;
      m_bodynum = this->m_bodynum;
      pInfo.m_pHardwareData = v15;
      pInfo.m_Skin = m_skinnum;
      pInfo.m_Decals = nullptr;
      pInfo.m_Body = m_bodynum;
      pInfo.m_HitboxSet = 0;
      pInfo.m_pClientEntity = nullptr;
      pInfo.m_Lod = -1;
      pInfo.m_pColorMeshes = nullptr;
      v39 = CRender::IsInLocalTransformMode(this: pRender);
      if ( v39 )
      {
        CRender::GetLocalTranform(this: pRender, matrix: (VMatrix *)fCurrentMatrix.m_flMatVal[1]);
        y = origin.y;
        x = origin.x;
        v20 = origin.z;
        v21 = 1.0
            / (float)((float)((float)((float)(origin.y * mViewMatrix.m[1][0]) + (float)(mViewMatrix.m[0][3] * origin.x))
                            + (float)(origin.z * mViewMatrix.m[1][1]))
                    + mViewMatrix.m[1][2]);
        v22 = fCurrentMatrix.m_flMatVal[2][0];
        p_m_origin->x = (float)((float)((float)((float)(origin.y * fCurrentMatrix.m_flMatVal[1][1])
                                              + (float)(fCurrentMatrix.m_flMatVal[1][0] * origin.x))
                                      + (float)(fCurrentMatrix.m_flMatVal[1][2] * origin.z))
                              + fCurrentMatrix.m_flMatVal[1][3])
                      * v21;
        this->m_origin.y = (float)((float)((float)((float)(fCurrentMatrix.m_flMatVal[2][1] * y) + (float)(v22 * x))
                                         + (float)(fCurrentMatrix.m_flMatVal[2][2] * v20))
                                 + fCurrentMatrix.m_flMatVal[2][3])
                         * v21;
        this->m_origin.z = (float)((float)((float)((float)(mViewMatrix.m[0][0] * y)
                                                 + (float)(*(float *)&pRenderContext.m_pObject * x))
                                         + (float)(mViewMatrix.m[0][1] * v20))
                                 + mViewMatrix.m[0][2])
                         * v21;
        AngleMatrix(angles: &this->m_angles, matrix: (matrix3x4_t *)&fMatrixNew.m_flMatVal[0][3]);
        ConcatTransforms(
          in1: (matrix3x4_t *)fCurrentMatrix.m_flMatVal[1],
          in2: (matrix3x4_t *)&fMatrixNew.m_flMatVal[0][3],
          out: (matrix3x4_t *)v32);
        MatrixAngles(src: (const VMatrix *)v32, vAngles: &this->m_angles);
      }
      if ( Options.general.bShowCollisionModels != 0 )
      {
        SetupMatrixOrgAngles(
          result: (VMatrix *)fCurrentMatrix.m_flMatVal[1],
          &origin,
          vAngles: (const QAngle *)mViewMatrix.m[2]);
        CRender::DrawCollisionModel(
          this: pRender,
          a2: p_m_angles,
          a3: (int)p_m_origin,
          mdlHandle: this->m_MDLHandle,
          mViewMatrix: (const VMatrix *)fCurrentMatrix.m_flMatVal[1]);
      }
      else
      {
        v23 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
                a1: g_pMaterialSystem,
                a2);
        v24 = *(float *)&v23;
        LODWORD(fCurrentMatrix.m_flMatVal[0][3]) = v23;
        v40 = 0;
        if ( v23 != 0 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v23 + 8))(a1: v23);
        v40 = 1;
        v25 = this->m_pStudioHdr;
        if ( this->m_pStudioHdr->m_pStudioHdr == nullptr )
        {
          v26 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
          CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v26, mdlcache: nullptr);
          v25 = this->m_pStudioHdr;
        }
        v27 = *(_DWORD *)LODWORD(v24);
        LODWORD(mViewMatrix.m[3][1]) = v25->m_pStudioHdr->numbones;
        v28 = *(int (__thiscall **)(_DWORD, int))(v27 + 392);
        mViewMatrix.m[2][3] = v24;
        mViewMatrix.m[3][0] = 0.0;
        LOBYTE(mViewMatrix.m[3][2]) = 0;
        v29 = (CBoneSetup *)v28(a1: LODWORD(v24), a2: 48 * LODWORD(mViewMatrix.m[3][1]));
        LODWORD(mViewMatrix.m[3][0]) = v29;
        LOBYTE(mViewMatrix.m[3][2]) = 1;
        LOBYTE(v40) = 2;
        StudioModel::SetUpBones(this, bUpdatePose: 0, pBoneToWorld: v29);
        v38 = (Color)-1;
        CRender::DrawModel(
          this: pRender,
          a2: (int)this,
          &pInfo,
          pBoneToWorld: (matrix3x4_t *)v29,
          vOrigin: (const Vector *)LODWORD(mViewMatrix.m[3][3]),
          fAlpha: flAlpha,
          bWireFrame,
          color: &v38);
        LOBYTE(v40) = 1;
        CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<float> *)&mViewMatrix.m[2][3]);
        v40 = 3;
        (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v24) + 12))(a1: COERCE_FLOAT(LODWORD(v24)));
        v40 = -1;
        (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v24) + 4))(a1: COERCE_FLOAT(LODWORD(v24)));
        p_m_origin = (Vector *)LODWORD(mViewMatrix.m[3][3]);
        p_m_angles = LODWORD(mViewMatrix.m[1][3]);
      }
      if ( v39 )
      {
        *p_m_origin = origin;
        *(_QWORD *)p_m_angles = *(_QWORD *)&mViewMatrix.m[2][0];
        *(float *)(p_m_angles + 8) = mViewMatrix.m[2][2];
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2AC0
// Name: public: CStudioHdr::~CStudioHdr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioHdr::~CStudioHdr(CStudioHdr *this)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_boneParent; // esi
  CUtlVector<int,CUtlMemory<int,int> > *p_m_boneFlags; // esi
  CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *p_m_pStudioHdrCache; // esi

  CStudioHdr::Term(this);
  p_m_boneParent = &this->m_boneParent;
  this->m_boneParent.m_Size = 0;
  if ( this->m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_boneParent->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_boneParent->m_Memory.m_pMemory);
      p_m_boneParent->m_Memory.m_pMemory = nullptr;
    }
    this->m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  this->m_boneParent.m_pElements = this->m_boneParent.m_Memory.m_pMemory;
  if ( this->m_boneParent.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_boneParent->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_boneParent->m_Memory.m_pMemory);
      p_m_boneParent->m_Memory.m_pMemory = nullptr;
    }
    this->m_boneParent.m_Memory.m_nAllocationCount = 0;
  }
  p_m_boneFlags = &this->m_boneFlags;
  this->m_boneFlags.m_Size = 0;
  if ( this->m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_boneFlags->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_boneFlags->m_Memory.m_pMemory);
      p_m_boneFlags->m_Memory.m_pMemory = nullptr;
    }
    this->m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  this->m_boneFlags.m_pElements = this->m_boneFlags.m_Memory.m_pMemory;
  if ( this->m_boneFlags.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_boneFlags->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_boneFlags->m_Memory.m_pMemory);
      p_m_boneFlags->m_Memory.m_pMemory = nullptr;
    }
    this->m_boneFlags.m_Memory.m_nAllocationCount = 0;
  }
  p_m_pStudioHdrCache = &this->m_pStudioHdrCache;
  this->m_pStudioHdrCache.m_Size = 0;
  if ( this->m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_pStudioHdrCache->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_pStudioHdrCache->m_Memory.m_pMemory);
      p_m_pStudioHdrCache->m_Memory.m_pMemory = nullptr;
    }
    this->m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
  }
  this->m_pStudioHdrCache.m_pElements = this->m_pStudioHdrCache.m_Memory.m_pMemory;
  if ( this->m_pStudioHdrCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_pStudioHdrCache->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_pStudioHdrCache->m_Memory.m_pMemory);
      p_m_pStudioHdrCache->m_Memory.m_pMemory = nullptr;
    }
    this->m_pStudioHdrCache.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2BF0
// Name: public: bool StudioModel::LoadModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall StudioModel::LoadModel(StudioModel *this, const char *modelname)
{
  char *m_pModelName; // eax
  char *v4; // eax
  const char *v5; // ecx
  int v6; // edx
  char v7; // al
  int v8; // eax
  CStudioHdr *m_pStudioHdr; // edi
  CStudioHdr *v10; // eax

  this->m_MDLHandle = -1;
  if ( g_pStudioRender == nullptr || modelname == nullptr )
    return 0;
  m_pModelName = this->m_pModelName;
  if ( m_pModelName != modelname )
  {
    if ( m_pModelName != nullptr )
      operator delete(p: this->m_pModelName);
    v4 = (char *)operator new[](nSize: strlen(modelname) + 1);
    this->m_pModelName = v4;
    v5 = modelname;
    v6 = v4 - modelname;
    do
    {
      v7 = *v5;
      v5[v6] = *v5;
      ++v5;
    }
    while ( v7 != 0 );
  }
  v8 = ((int (__thiscall *)(IMDLCache *, const char *))g_pMDLCache->FindMDL)(a1: g_pMDLCache, a2: modelname);
  this->m_MDLHandle = v8;
  if ( (_WORD)v8 == 0xFFFF )
    return 0;
  g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: v8);
  ((void (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: this->m_MDLHandle);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( this->m_pStudioHdr != nullptr )
  {
    CStudioHdr::~CStudioHdr(this: this->m_pStudioHdr);
    operator delete(p: m_pStudioHdr);
    this->m_pStudioHdr = nullptr;
  }
  v10 = (CStudioHdr *)operator new(nSize: 0x64u);
  if ( v10 != nullptr )
  {
    this->m_pStudioHdr = CStudioHdr::CStudioHdr(this: v10);
    return 1;
  }
  else
  {
    this->m_pStudioHdr = nullptr;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2D50
// Name: public: static void CStudioModelCache::ReloadModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CStudioModelCache::ReloadModel(const char *pszModelPath)
{
  int v1; // ebx
  ModelCache_t *v2; // edi
  StudioModel *pModel; // esi
  char testPath[260]; // [esp+4h] [ebp-208h] BYREF
  char testPath2[260]; // [esp+108h] [ebp-104h] BYREF

  V_strncpy(pDest: testPath, pSrc: pszModelPath, maxLen: 260);
  V_FixSlashes(pname: testPath, separator: 92);
  v1 = 0;
  if ( CStudioModelCache::m_nItems > 0 )
  {
    v2 = CStudioModelCache::m_Cache;
    do
    {
      V_strncpy(pDest: testPath2, pSrc: v2->pszPath, maxLen: 260);
      V_FixSlashes(pname: testPath2, separator: 92);
      if ( _V_stricmp(s1: testPath, s2: testPath2) == 0 )
      {
        pModel = v2->pModel;
        ((void (__stdcall *)(_DWORD))g_pMDLCache->Release)(a1: v2->pModel->m_MDLHandle);
        pModel->m_MDLHandle = -1;
        pModel->m_pModel = nullptr;
        StudioModel::LoadModel(this: v2->pModel, modelname: pszModelPath);
      }
      ++v1;
      ++v2;
    }
    while ( v1 < CStudioModelCache::m_nItems );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2E30
// Name: public: StudioModel::~StudioModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::~StudioModel(StudioModel *this)
{
  char *m_pModelName; // eax
  CStudioHdr *m_pStudioHdr; // edi
  QuaternionAligned *m_pPoseAng; // esi

  ((void (__stdcall *)(_DWORD))g_pMDLCache->Release)(a1: this->m_MDLHandle);
  m_pModelName = this->m_pModelName;
  this->m_MDLHandle = -1;
  this->m_pModel = nullptr;
  if ( m_pModelName != nullptr )
    operator delete(p: m_pModelName);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( this->m_pStudioHdr != nullptr )
  {
    CStudioHdr::~CStudioHdr(this: this->m_pStudioHdr);
    operator delete(p: m_pStudioHdr);
  }
  operator delete(p: this->m_pPosePos);
  m_pPoseAng = this->m_pPoseAng;
  if ( m_pPoseAng != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pPoseAng & 0xFFFFFFFC) - 4));
}

//------------------------------------------------------------------------------
// Address: 0x100B2EC0
// Name: public: static void CStudioModelCache::Release(class StudioModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CStudioModelCache::Release(StudioModel *pModel)
{
  int v1; // eax
  ModelCache_t *i; // ecx
  unsigned int v3; // esi
  StudioModel *v4; // edi
  int v5; // eax

  v1 = 0;
  if ( CStudioModelCache::m_nItems > 0 )
  {
    for ( i = CStudioModelCache::m_Cache; i->pModel != pModel; ++i )
    {
      if ( ++v1 >= CStudioModelCache::m_nItems )
        return;
    }
    --dword_107AC308[3 * v1];
    v3 = 3 * v1;
    if ( dword_107AC308[3 * v1] <= 0 )
    {
      operator delete(p: (void *)dword_107AC304[3 * v1]);
      v4 = CStudioModelCache::m_Cache[v3 / 3].pModel;
      if ( v4 != nullptr )
      {
        StudioModel::~StudioModel(this: CStudioModelCache::m_Cache[v3 / 3].pModel);
        operator delete(p: v4);
      }
      --CStudioModelCache::m_nItems;
      v5 = 3 * CStudioModelCache::m_nItems;
      CStudioModelCache::m_Cache[v3 / 3].pModel = CStudioModelCache::m_Cache[CStudioModelCache::m_nItems].pModel;
      dword_107AC304[v3] = dword_107AC304[v5];
      dword_107AC308[v3] = dword_107AC308[v5];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B2F70
// Name: public: void CStudioFileChangeWatcher::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioFileChangeWatcher::Update(CStudioFileChangeWatcher *this)
{
  CStudioFileChangeWatcher *v1; // ebx
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *p_m_Tree; // edi
  int Inorder; // esi
  const char *key; // edi
  int v5; // ebx
  int i; // esi
  int j; // esi
  CMapDoc *Document; // eax
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *v10; // [esp+8h] [ebp-4h]

  v1 = this;
  if ( g_pMDLCache != nullptr )
  {
    CFileChangeWatcher::Update(this: &this->m_Watcher);
    if ( v1->m_ChangedModels.m_Elements.m_Tree.m_NumElements != 0 )
    {
      p_m_Tree = &v1->m_ChangedModels.m_Elements.m_Tree;
      v10 = &v1->m_ChangedModels.m_Elements.m_Tree;
      Inorder = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &v1->m_ChangedModels.m_Elements.m_Tree);
      if ( Inorder != -1 )
      {
        while ( 1 )
        {
          key = v1->m_ChangedModels.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.key;
          v5 = g_pMDLCache->FindMDL(this: g_pMDLCache, a2: key);
          g_pMDLCache->Flush(this: g_pMDLCache, a2: v5, a3: -1);
          g_pMDLCache->ResetErrorModelStatus(this: g_pMDLCache, a2: v5);
          CStudioModelCache::ReloadModel(pszModelPath: key);
          Inorder = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                      this: v10,
                      i: Inorder);
          if ( Inorder == -1 )
            break;
          v1 = this;
        }
        p_m_Tree = v10;
      }
      for ( i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: p_m_Tree);
            i != -1;
            i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                  this: p_m_Tree,
                  i) )
      {
        free(pMem: (void *)p_m_Tree->m_Elements.m_pMemory[i].m_Data.key);
      }
      CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: p_m_Tree);
      for ( j = 0; j < CMapDoc::GetDocumentCount(); ++j )
      {
        Document = CMapDoc::GetDocument(index: j);
        Document->m_pWorld->CalcBounds(this: Document->m_pWorld, a2: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3080
// Name: void UpdateStudioFileChangeWatcher(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateStudioFileChangeWatcher()
{
  CStudioFileChangeWatcher::Update(this: &g_StudioFileChangeWatcher);
}

//------------------------------------------------------------------------------
// Address: 0x100B3090
// Name: public: static class StudioModel __near * CStudioModelCache::CreateModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
StudioModel *__cdecl CStudioModelCache::CreateModel(const char *pszModelPath)
{
  StudioModel *v1; // eax
  StudioModel *v2; // esi

  v1 = (StudioModel *)operator new(nSize: 0xA8u);
  if ( v1 != nullptr )
    v2 = StudioModel::StudioModel(this: v1);
  else
    v2 = nullptr;
  if ( v2 == nullptr )
    return nullptr;
  if ( StudioModel::LoadModel(this: v2, modelname: pszModelPath) != 0
    && StudioModel::PostLoadModel(this: v2, modelname: pszModelPath) != 0 )
  {
    CStudioModelCache::AddModel(pModel: v2, pszModelPath);
    return v2;
  }
  else
  {
    StudioModel::~StudioModel(this: v2);
    operator delete(p: v2);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3150
// Name: private: virtual void CStudioFileChangeWatcher::OnFileChange(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioFileChangeWatcher::OnFileChange(
        CStudioFileChangeWatcher *this,
        const char *pRelativeFilename,
        const char *pFullFilename)
{
  const char *FileExtension; // eax
  const char *v5; // esi
  const char *v6; // eax
  const char *v7; // eax
  char filename[260]; // [esp+8h] [ebp-314h] BYREF
  char tempFilename[260]; // [esp+10Ch] [ebp-210h] BYREF
  char relativeFilename[260]; // [esp+210h] [ebp-10Ch] BYREF
  CUtlMap<char const *,int,int>::Node_t search; // [esp+314h] [ebp-8h] BYREF

  V_ComposeFileName(path: "models", filename: pRelativeFilename, dest: relativeFilename, destSize: 260);
  V_FixSlashes(pname: relativeFilename, separator: 92);
  FileExtension = V_GetFileExtension(path: relativeFilename);
  v5 = FileExtension;
  if ( FileExtension != nullptr
    && (_V_stricmp(s1: FileExtension, s2: "mdl") == 0
     || _V_stricmp(s1: v5, s2: "vtx") == 0
     || _V_stricmp(s1: v5, s2: "phy") == 0
     || _V_stricmp(s1: v5, s2: "vvd") == 0) )
  {
    V_strncpy(pDest: tempFilename, pSrc: relativeFilename, maxLen: v5 - relativeFilename);
    v6 = V_UnqualifiedFileName(in: tempFilename);
    v7 = V_GetFileExtension(path: v6);
    if ( v7 != nullptr )
      V_strncpy(pDest: filename, pSrc: tempFilename, maxLen: v7 - tempFilename);
    else
      V_strncpy(pDest: filename, pSrc: tempFilename, maxLen: 260);
    V_strncat(pDest: filename, pSrc: ".mdl", destBufferSize: 0x104u, max_chars_to_copy: -1);
    search.key = filename;
    if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
           this: &this->m_ChangedModels.m_Elements.m_Tree,
           &search) == -1 )
    {
      search.key = _strdup(string: filename);
      CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Insert(
        this: &this->m_ChangedModels.m_Elements.m_Tree,
        insert: &search);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10212C10
// Name: public: CMatRenderData<struct matrix3x4_t>::~CMatRenderData<struct matrix3x4_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(CMatRenderData<float> *this)
{
  IMatRenderContext *m_pRenderContext; // ecx
  IMatRenderContext_vtbl *v3; // edx

  m_pRenderContext = this->m_pRenderContext;
  if ( m_pRenderContext != nullptr && this->m_pRenderData != nullptr )
  {
    v3 = m_pRenderContext->__vftable;
    if ( this->m_bNeedsUnlock )
    {
      ((void (__stdcall *)(float *))v3->UnlockRenderData)(a1: this->m_pRenderData);
      this->m_pRenderData = nullptr;
      this->m_nCount = 0;
      this->m_bNeedsUnlock = false;
      return;
    }
    ((void (*)(void))v3->ReleaseRenderData)();
  }
  this->m_pRenderData = nullptr;
  this->m_nCount = 0;
  this->m_bNeedsUnlock = false;
}
