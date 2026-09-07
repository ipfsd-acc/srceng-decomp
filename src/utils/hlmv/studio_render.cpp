// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlmv/studio_render.cpp
// Functions: 35
// ============================================================

#include "utils\hlmv\studio_render.h"

//------------------------------------------------------------------------------
// Address: 0x00415230
// Name: float GetRealtimeTime(void)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GetRealtimeTime()
{
  DWORD TickCount; // eax
  int v1; // ecx
  double result; // st7

  TickCount = GetTickCount();
  v1 = g_prevTicksRT;
  if ( g_prevTicksRT == 0 )
    v1 = TickCount;
  g_prevTicksRT = TickCount;
  result = (double)(int)(TickCount - v1) * 0.001 + g_timeRT;
  g_timeRT = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415270
// Name: public: virtual void StudioModel::AdvanceFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::AdvanceFrame(StudioModel *this, float dt)
{
  float v2; // xmm0_4
  double Duration; // st7
  float v5; // xmm0_4
  float v6; // xmm0_4
  AnimationLayer *m_Layer; // esi
  int i; // ebx
  double v9; // st7
  float v10; // xmm0_4
  float v11; // xmm0_4
  float t; // [esp+0h] [ebp-4h]
  float ta; // [esp+0h] [ebp-4h]

  v2 = dt;
  if ( dt > 0.1 )
  {
    v2 = 0.1;
    dt = 0.1;
  }
  this->m_dt = v2;
  Duration = StudioModel::GetDuration(this);
  if ( Duration <= 0.0 )
  {
    v6 = 0.0;
    goto LABEL_7;
  }
  if ( dt > 0.0 )
  {
    t = Duration;
    v5 = (float)(dt / t) + this->m_cycle;
    this->m_sequencetime = dt + this->m_sequencetime;
    v6 = v5 - (float)(int)v5;
LABEL_7:
    this->m_cycle = v6;
  }
  m_Layer = this->m_Layer;
  for ( i = 8; i != 0; --i )
  {
    v9 = StudioModel::GetDuration(this, iSequence: m_Layer->m_sequence);
    if ( v9 <= 0.0 )
    {
      v11 = 0.0;
    }
    else
    {
      if ( dt <= 0.0 )
        goto LABEL_14;
      ta = v9;
      v10 = (float)((float)(dt / ta) * m_Layer->m_playbackrate) + m_Layer->m_cycle;
      v11 = v10 - (float)(int)v10;
    }
    m_Layer->m_cycle = v11;
LABEL_14:
    ++m_Layer;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415370
// Name: public: virtual int StudioModel::BoneMask(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::BoneMask(StudioModel *this)
{
  int v1; // esi

  v1 = 1024 << (g_viewerSettings.autoLOD ? 0 : LOBYTE(g_viewerSettings.lod));
  if ( g_viewerSettings.showAttachments
    || g_viewerSettings.m_iEditAttachment != -1
    || this->m_nSolveHeadTurn != 0
    || StudioModel::LookupAttachment(this, szName: "eyes") != -1 )
  {
    v1 |= 0x200u;
  }
  if ( g_viewerSettings.highlightBone >= 0 )
    v1 |= 0x7FF00u;
  if ( g_viewerSettings.showHitBoxes )
    v1 |= 0x100u;
  return v1 | 0x40000;
}

//------------------------------------------------------------------------------
// Address: 0x004153F0
// Name: private: void StudioModel::SetupLighting(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall StudioModel::SetupLighting(StudioModel *this@<ecx>, int a2@<esi>)
{
  int v2; // esi
  int v3; // edi
  LightDesc_t light[2]; // [esp+0h] [ebp-B0h] BYREF

  light[0].m_Attenuation0 = 1.0;
  light[0].m_Attenuation1 = 0.0;
  light[0].m_Attenuation2 = 0.0;
  light[0].m_Color = *(Vector *)g_viewerSettings.lColor;
  light[0].m_Type = MATERIAL_LIGHT_DIRECTIONAL;
  light[0].m_Range = 2000.0;
  AngleVectors(angles: &g_viewerSettings.lightrot, forward: &light[0].m_Direction, right: nullptr, up: nullptr);
  ((void (__thiscall *)(IStudioRender *, int, LightDesc_t *, int))g_pStudioRender->SetLocalLights)(
    a1: g_pStudioRender,
    a2: 1,
    a3: light,
    a4: a2);
  v2 = 0;
  if ( ((int (__thiscall *)(IStudioRender *, LightType_t, _DWORD, _DWORD, _DWORD))g_pStudioRender->GetNumAmbientLightSamples)(
         a1: g_pStudioRender,
         a2: light[0].m_Type,
         a3: LODWORD(light[0].m_Color.x),
         a4: LODWORD(light[0].m_Color.y),
         a5: LODWORD(light[0].m_Color.z)) > 0 )
  {
    v3 = 0;
    do
    {
      StudioModel::m_AmbientLightColors[v3] = *(Vector *)g_viewerSettings.aColor;
      ++v2;
      ++v3;
    }
    while ( v2 < g_pStudioRender->GetNumAmbientLightSamples(this: g_pStudioRender) );
  }
  g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: StudioModel::m_AmbientLightColors);
}

//------------------------------------------------------------------------------
// Address: 0x00415500
// Name: int FindBoneIndex(class CStudioHdr __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindBoneIndex(CStudioHdr *pstudiohdr, const char *pName)
{
  int v2; // edi
  const char *v3; // esi

  v2 = 0;
  v3 = (char *)pstudiohdr->m_pStudioHdr + pstudiohdr->m_pStudioHdr->boneindex;
  if ( pstudiohdr->m_pStudioHdr->numbones <= 0 )
    return -1;
  while ( _V_stricmp(s1: pName, s2: &v3[*(_DWORD *)v3]) != 0 )
  {
    ++v2;
    v3 += 216;
    if ( v2 >= pstudiohdr->m_pStudioHdr->numbones )
      return -1;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00415560
// Name: public: int StudioModel::FindBone(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::FindBone(StudioModel *this, const char *pName)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
  }
  return FindBoneIndex(pstudiohdr: m_pStudioHdr, pName);
}

//------------------------------------------------------------------------------
// Address: 0x004155B0
// Name: private: virtual void StudioModel::SetupModel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::SetupModel(StudioModel *this, int bodypart)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  const studiohdr_t *v5; // eax
  int v6; // edx
  _DWORD *v7; // ecx
  bool v8; // zf
  mstudiomodel_t *v9; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
  }
  v5 = m_pStudioHdr->m_pStudioHdr;
  v6 = bodypart;
  if ( bodypart > v5->numbodyparts )
    v6 = 0;
  v7 = (int *)((char *)&v5->id + 16 * v6 + v5->bodypartindex);
  v8 = first == 0;
  v9 = (mstudiomodel_t *)((char *)&v7[37 * (this->m_bodynum / v7[2] % v7[1])] + v7[3]);
  this->m_pmodel = v9;
  if ( !v8 )
  {
    maxNumVertices = v9->numvertices;
    first = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415650
// Name: public: static void StudioModel::UpdateStudioRenderConfig(bool,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StudioModel::UpdateStudioRenderConfig(
        bool bWireframe,
        bool bZBufferWireframe,
        bool bNormals,
        bool bTangentFrame)
{
  char v4; // al
  MaterialSystem_Config_t matSysConfig; // [esp+Ch] [ebp-9Ch] BYREF
  StudioRenderConfig_t config; // [esp+70h] [ebp-38h] BYREF

  memset(dst: (unsigned __int8 *)&config, value: 0, count: sizeof(config));
  memset((void *)&config, 0, 16);
  config.drawEntities = 1;
  config.skin = 0;
  config.fullbright = 0;
  if ( g_viewerSettings.renderMode == 0
    || g_viewerSettings.softwareSkin
    || (((bWireframe << 7) | *((_BYTE *)&config + 36) & 0x7E) & 0x80u) != 0
    || bNormals
    || bTangentFrame )
  {
    v4 = (bWireframe << 7) | *((_BYTE *)&config + 36) & 0x7E | 3;
  }
  else
  {
    v4 = (bWireframe << 7) | *((_BYTE *)&config + 36) & 0x7C | 1;
  }
  *((_BYTE *)&config + 36) = v4 & 0x83 | 0x70;
  *((_BYTE *)&config + 37) = bNormals
                           | *((_BYTE *)&config + 37) & 0xE0
                           | (2 * (bTangentFrame | (2 * bZBufferWireframe)));
  g_pStudioRender->UpdateConfig(this: g_pStudioRender, a2: &config);
  matSysConfig = *g_pMaterialSystem->GetCurrentConfigForVideoCard(this: g_pMaterialSystem);
  InitMaterialSystemConfig(pConfig: &matSysConfig);
  matSysConfig.nFullbright = 0;
  if ( g_viewerSettings.renderMode == 1 )
    matSysConfig.nFullbright = 2;
  if ( g_dxlevel != 0 )
    matSysConfig.dxSupportLevel = g_dxlevel;
  g_pMaterialSystem->OverrideConfig(this: g_pMaterialSystem, a2: &matSysConfig, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00415770
// Name: public: float StudioModel::SetHeadPosition(struct matrix3x4_t __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
double __userpurge StudioModel::SetHeadPosition@<st0>(
        StudioModel *this@<ecx>,
        float a2@<ebp>,
        matrix3x4_t *attToWorld,
        const Vector *vTargetPos,
        float dt)
{
  int v6; // edi
  double FlexController; // st7
  int v8; // edi
  double v9; // st7
  int v10; // edi
  double v11; // st7
  float flValue; // [esp+0h] [ebp-DCh]
  float flValuea; // [esp+0h] [ebp-DCh]
  float flValueb; // [esp+0h] [ebp-DCh]
  float z; // [esp+4h] [ebp-D8h]
  float v17; // [esp+4h] [ebp-D8h]
  float v18; // [esp+4h] [ebp-D8h]
  float y; // [esp+8h] [ebp-D4h]
  float v20; // [esp+8h] [ebp-D4h]
  float v21; // [esp+8h] [ebp-D4h]
  _BYTE v22[12]; // [esp+20h] [ebp-BCh] BYREF
  matrix3x4_t headXform; // [esp+2Ch] [ebp-B0h] BYREF
  _BYTE invAttToWorld_36[60]; // [esp+80h] [ebp-5Ch] OVERLAPPED BYREF
  float v25; // [esp+BCh] [ebp-20h]
  float v26; // [esp+C0h] [ebp-1Ch]
  QAngle vEyeAngles; // [esp+C4h] [ebp-18h] BYREF
  float flDiff; // [esp+D0h] [ebp-Ch]
  float flMax; // [esp+D4h] [ebp-8h]
  float retaddr; // [esp+DCh] [ebp+0h]

  flDiff = a2;
  flMax = retaddr;
  *(matrix3x4_t *)invAttToWorld_36 = *attToWorld;
  Studio_AlignIKMatrix(mMat: (matrix3x4a_t *)invAttToWorld_36, vAlignTo: vTargetPos);
  MatrixInvert(in: attToWorld, out: (matrix3x4_t *)&headXform.m_flMatVal[2][1]);
  ConcatTransforms(
    in1: (matrix3x4_t *)&headXform.m_flMatVal[2][1],
    in2: (const matrix3x4_t *)invAttToWorld_36,
    out: (matrix3x4_t *)v22);
  MatrixAngles(matrix: (const matrix3x4_t *)v22, angles: (float *)&invAttToWorld_36[56]);
  v6 = StudioModel::LookupPoseParameter(this, szName: "head_yaw");
  StudioModel::GetPoseParameterRange(this, iParameter: v6, pflMin: &vEyeAngles.z, pflMax: &vEyeAngles.y);
  y = vEyeAngles.y;
  z = vEyeAngles.z;
  FlexController = StudioModel::GetFlexController(this, szName: "head_rightleft");
  flValue = FlexController + v25;
  vEyeAngles.x = RangeCompressor(flValue, flMin: z, flMax: y, flBase: 0.0);
  StudioModel::SetPoseParameter(this, iParameter: v6, flValue: vEyeAngles.x);
  v8 = StudioModel::LookupPoseParameter(this, szName: "head_pitch");
  StudioModel::GetPoseParameterRange(this, iParameter: v8, pflMin: &vEyeAngles.z, pflMax: &vEyeAngles.y);
  v20 = vEyeAngles.y;
  v17 = vEyeAngles.z;
  v9 = StudioModel::GetFlexController(this, szName: "head_updown");
  flValuea = v9 + *(float *)&invAttToWorld_36[56];
  vEyeAngles.x = RangeCompressor(flValue: flValuea, flMin: v17, flMax: v20, flBase: 0.0);
  StudioModel::SetPoseParameter(this, iParameter: v8, flValue: vEyeAngles.x);
  v10 = StudioModel::LookupPoseParameter(this, szName: "head_roll");
  StudioModel::GetPoseParameterRange(this, iParameter: v10, pflMin: &vEyeAngles.z, pflMax: &vEyeAngles.y);
  v21 = vEyeAngles.y;
  v18 = vEyeAngles.z;
  v11 = StudioModel::GetFlexController(this, szName: "head_tilt");
  flValueb = v11 + v26;
  vEyeAngles.x = RangeCompressor(flValue: flValueb, flMin: v18, flMax: v21, flBase: 0.0);
  StudioModel::SetPoseParameter(this, iParameter: v10, flValue: vEyeAngles.x);
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x00415970
// Name: void RandomColor(float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RandomColor(float *color, unsigned __int8 key)
{
  int *v2; // esi
  int v3; // edi
  int v4; // ebx
  int v5; // eax
  unsigned int v6; // eax

  if ( first_0 )
  {
    first_0 = false;
    v2 = dword_705BA4;
    do
    {
      do
      {
        v3 = (unsigned __int8)rand();
        v4 = (unsigned __int8)rand();
        v5 = (unsigned __int8)rand();
      }
      while ( v3 + v5 + v4 < 256 );
      *(v2 - 1) = v3;
      *v2 = v4;
      v2[1] = v5;
      v2[2] = 255;
      v2 += 4;
    }
    while ( (int)v2 < (int)dword_706BA4 );
  }
  v6 = 4 * key;
  *color = (double)colors[v6 / 4].r * 0.0039215689;
  color[1] = (double)(unsigned int)dword_705BA4[v6] * 0.0039215689;
  color[2] = (double)(unsigned int)dword_705BA8[v6] * 0.0039215689;
  color[3] = 0.0039215689 * (double)(unsigned int)dword_705BAC[v6];
}

//------------------------------------------------------------------------------
// Address: 0x00415A70
// Name: public: char const __near * StudioModel::GetKeyValueText(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall StudioModel::GetKeyValueText(StudioModel *this, int iSequence)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
  }
  return Studio_GetKeyValueText(pStudioHdr: m_pStudioHdr, iSequence);
}

//------------------------------------------------------------------------------
// Address: 0x00415AC0
// Name: public: void StudioModel::SetSolveHeadTurn(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::SetSolveHeadTurn(StudioModel *this, int solve)
{
  this->m_nSolveHeadTurn = solve;
}

//------------------------------------------------------------------------------
// Address: 0x00415AD0
// Name: public: void StudioModel::OverrideBones(bool __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge StudioModel::OverrideBones(StudioModel *this@<ecx>, int a2@<esi>, bool *override)
{
  IStudioPhysics *m_pPhysics; // ecx
  int (__thiscall *Count)(IStudioPhysics *); // eax
  matrix3x4_t *v6; // eax
  CStudioHdr *m_pStudioHdr; // edi
  matrix3x4_t *v8; // ebx
  const studiohdr_t *v9; // eax
  int v10; // ecx
  bool v11; // cc
  const char *v12; // ebx
  const studiohdr_t *v13; // edx
  int v14; // edi
  CPhysmesh *v15; // edi
  CStudioHdr *v16; // eax
  const studiohdr_t *v17; // eax
  int BoneIndex; // eax
  int m_physPreviewAxis; // ecx
  int v20; // eax
  int v21; // ecx
  IStudioPhysics *v22; // ecx
  int (__thiscall *v23)(IStudioPhysics *); // edx
  int v24; // edi
  matrix3x4_t tmpmatrix; // [esp+0h] [ebp-B4h] BYREF
  matrix3x4_t basematrix; // [esp+30h] [ebp-84h] BYREF
  matrix3x4_t bonematrix; // [esp+60h] [ebp-54h] BYREF
  QAngle tmp; // [esp+90h] [ebp-24h] BYREF
  QAngle rot; // [esp+9Ch] [ebp-18h] BYREF
  int i; // [esp+A8h] [ebp-Ch]
  matrix3x4_t *parentMatrix; // [esp+ACh] [ebp-8h]
  int v33; // [esp+B0h] [ebp-4h]

  tmp.x = 0.0;
  tmp.y = 90.0;
  tmp.z = 0.0;
  AngleMatrix(angles: &tmp, matrix: &bonematrix);
  ConcatTransforms(in1: &g_viewtransform, in2: &bonematrix, out: &basematrix);
  m_pPhysics = this->m_pPhysics;
  Count = m_pPhysics->Count;
  i = 0;
  if ( ((int (__thiscall *)(IStudioPhysics *, int))Count)(a1: m_pPhysics, a2) > 0 )
  {
    do
    {
      v6 = (matrix3x4_t *)this->m_pPhysics->GetMesh(this: this->m_pPhysics, a2: i);
      m_pStudioHdr = this->m_pStudioHdr;
      v8 = v6;
      parentMatrix = v6;
      if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
      {
        v9 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
        CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v9, mdlcache: nullptr);
        m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
      }
      v10 = (int)m_pStudioHdr->m_pStudioHdr + m_pStudioHdr->m_pStudioHdr->boneindex;
      v11 = m_pStudioHdr->m_pStudioHdr->numbones <= 0;
      v33 = 0;
      if ( v11 )
      {
LABEL_10:
        v33 = -1;
        v14 = -1;
      }
      else
      {
        v12 = (const char *)v10;
        while ( _V_stricmp(s1: (const char *)parentMatrix, s2: &v12[*(_DWORD *)v12]) != 0 )
        {
          v13 = m_pStudioHdr->m_pStudioHdr;
          v12 += 216;
          if ( ++v33 >= v13->numbones )
          {
            v8 = parentMatrix;
            goto LABEL_10;
          }
        }
        v14 = v33;
        v8 = parentMatrix;
      }
      if ( (LODWORD(v8[38].m_flMatVal[1][2]) != 0 || LODWORD(v8[38].m_flMatVal[1][3]) != 0) && v14 >= 0 )
      {
        parentMatrix = &basematrix;
        override[v14] = true;
        if ( v8[38].m_flMatVal[1][2] >= 0.0 )
        {
          v15 = this->m_pPhysics->GetMesh(this: this->m_pPhysics, a2: LODWORD(v8[38].m_flMatVal[1][2]));
          v16 = this->m_pStudioHdr;
          if ( v16 != nullptr && v16->m_pStudioHdr == nullptr )
          {
            v17 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
            CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v17, mdlcache: nullptr);
            v16 = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
          }
          BoneIndex = FindBoneIndex(pstudiohdr: v16, pName: v15->m_boneName);
          v14 = v33;
          if ( BoneIndex >= 0 )
            parentMatrix = &this->m_pBoneToWorld[BoneIndex];
        }
        if ( this->m_physPreviewBone == i )
        {
          m_physPreviewAxis = this->m_physPreviewAxis;
          v20 = m_physPreviewAxis + 116;
          if ( m_physPreviewAxis != 0 )
            v21 = m_physPreviewAxis == 2;
          else
            v21 = 2;
          memset(&rot, 0, sizeof(rot));
          *(&rot.x + v21) = (float)((float)(v8->m_flMatVal[v20][1] - v8->m_flMatVal[v20][0]) * this->m_physPreviewParam)
                          + v8->m_flMatVal[v20][0];
          AngleMatrix(angles: &rot, matrix: &tmpmatrix);
          ConcatTransforms(in1: (matrix3x4_t *)((char *)v8 + 72), in2: &tmpmatrix, out: &bonematrix);
        }
        else
        {
          MatrixCopy(in: (matrix3x4_t *)((char *)v8 + 72), out: &bonematrix);
        }
        ConcatTransforms(in1: parentMatrix, in2: &bonematrix, out: &this->m_pBoneToWorld[v14]);
      }
      v22 = this->m_pPhysics;
      v23 = v22->Count;
      v24 = ++i;
    }
    while ( v24 < v23(this: v22) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415D80
// Name: public: void StudioModel::GetBodyPoseParametersFromFlex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::GetBodyPoseParametersFromFlex(StudioModel *this)
{
  float flGoal; // [esp+8h] [ebp-4h]
  float flGoala; // [esp+8h] [ebp-4h]
  float flGoalb; // [esp+8h] [ebp-4h]
  float flGoalc; // [esp+8h] [ebp-4h]
  float flGoald; // [esp+8h] [ebp-4h]
  float flGoale; // [esp+8h] [ebp-4h]
  float flGoalf; // [esp+8h] [ebp-4h]
  float flGoalg; // [esp+8h] [ebp-4h]
  float flGoalh; // [esp+8h] [ebp-4h]
  float flGoali; // [esp+8h] [ebp-4h]
  float flGoalj; // [esp+8h] [ebp-4h]
  float flGoalk; // [esp+8h] [ebp-4h]
  float flGoall; // [esp+8h] [ebp-4h]
  float flGoalm; // [esp+8h] [ebp-4h]

  flGoal = StudioModel::GetFlexController(this, szName: "move_rightleft");
  StudioModel::SetPoseParameter(this, szName: "body_trans_Y", flValue: flGoal);
  flGoala = StudioModel::GetFlexController(this, szName: "move_forwardback");
  StudioModel::SetPoseParameter(this, szName: "body_trans_X", flValue: flGoala);
  flGoalb = StudioModel::GetFlexController(this, szName: "move_updown");
  StudioModel::SetPoseParameter(this, szName: "body_lift", flValue: flGoalb);
  flGoalc = this->m_flBodyYaw;
  flGoald = StudioModel::GetFlexController(this, szName: "body_rightleft") + flGoalc;
  StudioModel::SetPoseParameter(this, szName: "body_yaw", flValue: flGoald);
  flGoale = StudioModel::GetFlexController(this, szName: "body_updown");
  StudioModel::SetPoseParameter(this, szName: "body_pitch", flValue: flGoale);
  flGoalf = StudioModel::GetFlexController(this, szName: "body_tilt");
  StudioModel::SetPoseParameter(this, szName: "body_roll", flValue: flGoalf);
  flGoalg = this->m_flSpineYaw;
  flGoalh = StudioModel::GetFlexController(this, szName: "chest_rightleft") + flGoalg;
  StudioModel::SetPoseParameter(this, szName: "spine_yaw", flValue: flGoalh);
  flGoali = StudioModel::GetFlexController(this, szName: "chest_updown");
  StudioModel::SetPoseParameter(this, szName: "spine_pitch", flValue: flGoali);
  flGoalj = StudioModel::GetFlexController(this, szName: "chest_tilt");
  StudioModel::SetPoseParameter(this, szName: "spine_roll", flValue: flGoalj);
  flGoalk = StudioModel::GetFlexController(this, szName: "head_forwardback");
  StudioModel::SetPoseParameter(this, szName: "neck_trans", flValue: flGoalk);
  flGoall = StudioModel::GetFlexController(this, szName: "gesture_updown");
  StudioModel::SetPoseParameter(this, szName: "gesture_height", flValue: flGoall);
  flGoalm = StudioModel::GetFlexController(this, szName: "gesture_rightleft");
  StudioModel::SetPoseParameter(this, szName: "gesture_width", flValue: flGoalm);
}

//------------------------------------------------------------------------------
// Address: 0x00415F90
// Name: public: void StudioModel::drawBox(class Vector const __near *,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge StudioModel::drawBox(StudioModel *this@<ecx>, int a2@<ebx>, const Vector *v, const float *color)
{
  IMatRenderContext *v4; // esi
  int v5; // edi
  IMesh *v6; // esi
  float *m_pCurrPosition; // ecx
  const Vector *v9; // eax
  int m_nVertexCount; // eax
  float *m_pPosition; // ecx
  double x; // st7
  int v13; // eax
  IMesh *v14; // esi
  float *v15; // ecx
  double v17; // st7
  int v18; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1FCh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-14h]
  IMesh *pMesh; // [esp+1F4h] [ebp-10h]
  float v23; // [esp+1F8h] [ebp-Ch]
  float v24; // [esp+1FCh] [ebp-8h]
  float v25; // [esp+200h] [ebp-4h]
  float va; // [esp+20Ch] [ebp+8h]
  float vb; // [esp+20Ch] [ebp+8h]
  float vc; // [esp+20Ch] [ebp+8h]
  float vd; // [esp+20Ch] [ebp+8h]
  float colora; // [esp+210h] [ebp+Ch]
  float colorb; // [esp+210h] [ebp+Ch]
  float colorc; // [esp+210h] [ebp+Ch]
  float colord; // [esp+210h] [ebp+Ch]
  float colore; // [esp+210h] [ebp+Ch]
  float colorf; // [esp+210h] [ebp+Ch]
  float colorg; // [esp+210h] [ebp+Ch]
  float colorh; // [esp+210h] [ebp+Ch]
  float colori; // [esp+210h] [ebp+Ch]

  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v5 = 0;
  pRenderContext.m_pObject = v4;
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v6 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int))v4->GetDynamicMesh)(
                  a1: v4,
                  a2: 1,
                  a3: 0,
                  a4: 0,
                  a5: 0,
                  a6: a2);
  pMesh = v6;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v6;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLE_STRIP;
  v6->SetPrimitiveType(this: v6, a2: MATERIAL_TRIANGLE_STRIP);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 10, a3: 10, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v6->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 10;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v6, nMaxVertexCount: 10, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  do
  {
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v9 = &v[v5 & 7];
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = v9->x;
    m_pCurrPosition[1] = v9->y;
    m_pCurrPosition[2] = v9->z;
    v24 = (float)(color[2] * 255.0) + 8388608.0;
    v25 = (float)(color[1] * 255.0) + 8388608.0;
    v23 = (float)(*color * 255.0) + 8388608.0;
    colora = (float)(color[3] * 255.0) + 8388608.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v24)
                                                        | ((LOBYTE(v25) | ((LOBYTE(v23) | (LOBYTE(colora) << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    ++v5;
  }
  while ( v5 < 10 );
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
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
  v6->Draw_2(this: v6, a2: -1, a3: 0);
  meshBuilder.m_pMesh = v6;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLE_STRIP;
  v6->SetPrimitiveType(this: v6, a2: MATERIAL_TRIANGLE_STRIP);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 4, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v6->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = v6;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 4;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 4;
  meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
  meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_bModify = false;
  if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
  {
    meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
    meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
  }
  m_pPosition = meshBuilder.m_VertexBuilder.m_pPosition;
  x = v[6].x;
  meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
  qmemcpy(
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
    meshBuilder.m_VertexBuilder.m_pTexCoord,
    sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
  meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
  meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
  *meshBuilder.m_VertexBuilder.m_pPosition = x;
  m_pPosition[1] = v[6].y;
  m_pPosition[2] = v[6].z;
  v23 = (float)(color[2] * 255.0) + 8388608.0;
  v25 = (float)(color[1] * 255.0) + 8388608.0;
  v24 = (float)(*color * 255.0) + 8388608.0;
  colorb = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v23)
                                                      | ((LOBYTE(v25) | ((LOBYTE(v24) | (LOBYTE(colorb) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = *v;
  v23 = (float)(color[2] * 255.0) + 8388608.0;
  v25 = (float)(color[1] * 255.0) + 8388608.0;
  v24 = (float)(*color * 255.0) + 8388608.0;
  colorc = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v23)
                                                      | ((LOBYTE(v25) | ((LOBYTE(v24) | (LOBYTE(colorc) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v[4];
  v23 = (float)(color[2] * 255.0) + 8388608.0;
  v25 = (float)(color[1] * 255.0) + 8388608.0;
  v24 = (float)(*color * 255.0) + 8388608.0;
  colord = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v23)
                                                      | ((LOBYTE(v25) | ((LOBYTE(v24) | (LOBYTE(colord) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v[2];
  v23 = (float)(color[2] * 255.0) + 8388608.0;
  v25 = (float)(color[1] * 255.0) + 8388608.0;
  v24 = (float)(*color * 255.0) + 8388608.0;
  colore = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v23)
                                                      | ((LOBYTE(v25) | ((LOBYTE(v24) | (LOBYTE(colore) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        v13 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        v13 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        v13 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        v13 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        v13 = 0;
        break;
      default:
        v13 = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: v13);
  }
  ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
    a1: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
  v14 = pMesh;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
  meshBuilder.m_pMesh = v14;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLE_STRIP;
  v14->SetPrimitiveType(this: v14, a2: MATERIAL_TRIANGLE_STRIP);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 4, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v14->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = v14;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 4;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 4;
  meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
  meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_bModify = false;
  if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
  {
    meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
    meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
  }
  v15 = meshBuilder.m_VertexBuilder.m_pPosition;
  v17 = v[1].x;
  meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
  qmemcpy(
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
    meshBuilder.m_VertexBuilder.m_pTexCoord,
    sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
  meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
  meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
  *meshBuilder.m_VertexBuilder.m_pPosition = v17;
  v15[1] = v[1].y;
  v15[2] = v[1].z;
  v25 = (float)(color[2] * 255.0) + 8388608.0;
  v24 = (float)(color[1] * 255.0) + 8388608.0;
  colorf = (float)(*color * 255.0) + 8388608.0;
  va = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v25)
                                                      | ((LOBYTE(v24) | ((LOBYTE(colorf) | (LOBYTE(va) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v[7];
  v25 = (float)(color[2] * 255.0) + 8388608.0;
  v24 = (float)(color[1] * 255.0) + 8388608.0;
  colorg = (float)(*color * 255.0) + 8388608.0;
  vb = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v25)
                                                      | ((LOBYTE(v24) | ((LOBYTE(colorg) | (LOBYTE(vb) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v[3];
  v25 = (float)(color[2] * 255.0) + 8388608.0;
  v24 = (float)(color[1] * 255.0) + 8388608.0;
  colorh = (float)(*color * 255.0) + 8388608.0;
  vc = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v25)
                                                      | ((LOBYTE(v24) | ((LOBYTE(colorh) | (LOBYTE(vc) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v[5];
  v25 = (float)(color[2] * 255.0) + 8388608.0;
  v24 = (float)(color[1] * 255.0) + 8388608.0;
  colori = (float)(*color * 255.0) + 8388608.0;
  vd = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v25)
                                                      | ((LOBYTE(v24) | ((LOBYTE(colori) | (LOBYTE(vd) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        v18 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        v18 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        v18 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        v18 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        v18 = 0;
        break;
      default:
        v18 = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: v18);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x00416B40
// Name: public: void StudioModel::drawWireframeBox(class Vector const __near *,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge StudioModel::drawWireframeBox(
        StudioModel *this@<ecx>,
        int a2@<ebx>,
        const Vector *v,
        const float *color)
{
  IMatRenderContext *v4; // esi
  IMesh *v5; // ebx
  float *m_pCurrPosition; // ecx
  const Vector *v9; // eax
  int m_nVertexCount; // eax
  float *v11; // eax
  float *v12; // eax
  float *v13; // ecx
  float *v14; // ecx
  float *v15; // eax
  int v16; // eax
  float *v17; // eax
  float *v18; // ecx
  float *v19; // ecx
  float *v20; // ecx
  float *v21; // eax
  int v22; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1F8h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-10h]
  int i; // [esp+1F4h] [ebp-Ch]
  float v27; // [esp+1F8h] [ebp-8h]
  float v28; // [esp+1FCh] [ebp-4h]
  float va; // [esp+208h] [ebp+8h]
  float vb; // [esp+208h] [ebp+8h]
  float vc; // [esp+208h] [ebp+8h]
  float vd; // [esp+208h] [ebp+8h]
  float ve; // [esp+208h] [ebp+8h]
  float vf; // [esp+208h] [ebp+8h]
  float vg; // [esp+208h] [ebp+8h]
  float vh; // [esp+208h] [ebp+8h]
  float vi; // [esp+208h] [ebp+8h]
  float vj; // [esp+208h] [ebp+8h]
  float vk; // [esp+208h] [ebp+8h]
  float colora; // [esp+20Ch] [ebp+Ch]
  float colorb; // [esp+20Ch] [ebp+Ch]
  float colorc; // [esp+20Ch] [ebp+Ch]
  float colord; // [esp+20Ch] [ebp+Ch]
  float colore; // [esp+20Ch] [ebp+Ch]
  float colorf; // [esp+20Ch] [ebp+Ch]
  float colorg; // [esp+20Ch] [ebp+Ch]
  float colorh; // [esp+20Ch] [ebp+Ch]
  float colori; // [esp+20Ch] [ebp+Ch]
  float colorj; // [esp+20Ch] [ebp+Ch]
  float colork; // [esp+20Ch] [ebp+Ch]

  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = v4;
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v5 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int))v4->GetDynamicMesh)(
                  a1: v4,
                  a2: 1,
                  a3: 0,
                  a4: 0,
                  a5: 0,
                  a6: a2);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v5;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_LINES;
  v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 8, a3: 8, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 8;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: 8, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  for ( i = 0; i < 10; ++i )
  {
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v9 = &v[i & 7];
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = v9->x;
    m_pCurrPosition[1] = v9->y;
    m_pCurrPosition[2] = v9->z;
    v28 = (float)(color[2] * 255.0) + 8388608.0;
    v27 = (float)(color[1] * 255.0) + 8388608.0;
    va = (float)(*color * 255.0) + 8388608.0;
    colora = (float)(color[3] * 255.0) + 8388608.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v28)
                                                        | ((LOBYTE(v27) | ((LOBYTE(va) | (LOBYTE(colora) << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  }
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
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
  meshBuilder.m_pMesh = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  v5->Draw_2(this: v5, a2: -1, a3: 0);
  CMeshBuilder::Begin(this: &meshBuilder, pMesh: v5, type: 4, numPrimitives: 4);
  v11 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v[6].x;
  v11[1] = v[6].y;
  v11[2] = v[6].z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  vb = (float)(*color * 255.0) + 8388608.0;
  colorb = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(vb) | (LOBYTE(colorb) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v12 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v->x;
  v12[1] = v->y;
  v12[2] = v->z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  vc = (float)(*color * 255.0) + 8388608.0;
  colorc = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(vc) | (LOBYTE(colorc) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v13 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v[2].x;
  v13[1] = v[2].y;
  v13[2] = v[2].z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  vd = (float)(*color * 255.0) + 8388608.0;
  colord = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(vd) | (LOBYTE(colord) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v14 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v[4].x;
  v14[1] = v[4].y;
  v14[2] = v[4].z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  ve = (float)(*color * 255.0) + 8388608.0;
  colore = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(ve) | (LOBYTE(colore) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v15 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v[6].x;
  v15[1] = v[6].y;
  v15[2] = v[6].z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  vf = (float)(*color * 255.0) + 8388608.0;
  colorf = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(vf) | (LOBYTE(colorf) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        v16 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        v16 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        v16 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        v16 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        v16 = 0;
        break;
      default:
        v16 = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: v16);
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
  meshBuilder.m_pMesh = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  v5->Draw_2(this: v5, a2: -1, a3: 0);
  CMeshBuilder::Begin(this: &meshBuilder, pMesh: v5, type: 4, numPrimitives: 4);
  v17 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v[1].x;
  v17[1] = v[1].y;
  v17[2] = v[1].z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  vg = (float)(*color * 255.0) + 8388608.0;
  colorg = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(vg) | (LOBYTE(colorg) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v18 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v[7].x;
  v18[1] = v[7].y;
  v18[2] = v[7].z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  vh = (float)(*color * 255.0) + 8388608.0;
  colorh = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(vh) | (LOBYTE(colorh) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v19 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v[5].x;
  v19[1] = v[5].y;
  v19[2] = v[5].z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  vi = (float)(*color * 255.0) + 8388608.0;
  colori = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(vi) | (LOBYTE(colori) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v20 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v[3].x;
  v20[1] = v[3].y;
  v20[2] = v[3].z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  vj = (float)(*color * 255.0) + 8388608.0;
  colorj = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(vj) | (LOBYTE(colorj) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v21 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v[1].x;
  v21[1] = v[1].y;
  v21[2] = v[1].z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  vk = (float)(*color * 255.0) + 8388608.0;
  colork = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(vk) | (LOBYTE(colork) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        v22 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        v22 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        v22 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        v22 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        v22 = 0;
        break;
      default:
        v22 = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: v22);
  }
  ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
    a1: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v5->Draw_2(this: v5, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x004175E0
// Name: public: void StudioModel::drawTransform(struct matrix3x4_t __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge StudioModel::drawTransform(
        StudioModel *this@<ecx>,
        CMeshBuilder *p_meshBuilder@<ebx>,
        int m_nIndexCount@<edi>,
        matrix3x4_t *m,
        float flLength)
{
  IMatRenderContext *v5; // esi
  IMesh *v6; // esi
  unsigned __int8 *v7; // ebx
  char v8; // cl
  int v9; // edx
  unsigned int v10; // ecx
  int v11; // edx
  float *m_pCurrPosition; // eax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float *v15; // edi
  float *v16; // eax
  float v17; // xmm0_4
  float v18; // xmm1_4
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-1F4h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1ECh] [ebp-Ch]
  IMesh *pMesh; // [esp+1F0h] [ebp-8h]
  float *v26; // [esp+1F4h] [ebp-4h]

  v5 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = v5;
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  v6 = v5->GetDynamicMesh(this: v5, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  pMesh = v6;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v26 = m->m_flMatVal[2];
  v7 = &color[0][2];
  while ( 1 )
  {
    meshBuilder.m_pMesh = v6;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    ((void (__thiscall *)(IMesh *, int, int, CMeshBuilder *))v6->SetPrimitiveType)(
      a1: v6,
      a2: 1,
      a3: m_nIndexCount,
      a4: p_meshBuilder);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 2, a3: 2, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v6->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = v6;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 2;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
    meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 2;
    meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_bModify = false;
    if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
    {
      meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
      meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
    }
    meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = meshBuilder.m_VertexBuilder.m_pTexCoord[2];
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5] = meshBuilder.m_VertexBuilder.m_pTexCoord[5];
    v8 = *(v7 - 2);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = meshBuilder.m_VertexBuilder.m_pTexCoord[0];
    meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = meshBuilder.m_VertexBuilder.m_pTexCoord[3];
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = meshBuilder.m_VertexBuilder.m_pTexCoord[1];
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6] = meshBuilder.m_VertexBuilder.m_pTexCoord[6];
    v9 = *(v7 - 1);
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = meshBuilder.m_VertexBuilder.m_pTexCoord[4];
    v10 = v9 | ((*(_DWORD *)&v8 | 0xFFFFFF00) << 8);
    v11 = *v7;
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7] = meshBuilder.m_VertexBuilder.m_pTexCoord[7];
    meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pColor = v11 | (v10 << 8);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v13 = m->m_flMatVal[1][3];
    v14 = m->m_flMatVal[2][3];
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = m->m_flMatVal[0][3];
    m_pCurrPosition[1] = v13;
    m_pCurrPosition[2] = v14;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v15 = v26;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *v7 | ((*(v7 - 1) | ((*(v7 - 2) | 0xFFFFFF00) << 8)) << 8);
    v16 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v17 = (float)(*(v15 - 4) * flLength) + m->m_flMatVal[1][3];
    v18 = (float)(*v15 * flLength) + m->m_flMatVal[2][3];
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(*(v15 - 8) * flLength) + m->m_flMatVal[0][3];
    v16[1] = v17;
    v16[2] = v18;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    p_meshBuilder = &meshBuilder;
    m_nIndexCount = meshBuilder.m_IndexBuilder.m_nIndexCount;
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
    v7 += 3;
    v26 = v15 + 1;
    if ( (int)v7 >= (int)&unk_51814F )
      break;
    v6 = pMesh;
  }
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x00417980
// Name: public: void StudioModel::drawLine(class Vector const __near &,class Vector const __near &,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge StudioModel::drawLine(
        StudioModel *this@<ecx>,
        int a2@<edi>,
        const Vector *p1,
        const Vector *p2,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b)
{
  IMatRenderContext *v7; // ebx
  IMesh *v8; // edi
  unsigned int v9; // esi
  float y; // xmm0_4
  float z; // xmm1_4
  float *m_pCurrPosition; // eax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float *v15; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1E8h] BYREF

  v7 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, int))v7->Bind)(
    a1: v7,
    a2: g_materialVertexColor,
    a3: 0,
    a4: a2);
  v8 = v7->GetDynamicMesh(this: v7, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v8;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_LINES;
  v8->SetPrimitiveType(this: v8, a2: MATERIAL_LINES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 2, a3: 2, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v8->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 2;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v8, nMaxVertexCount: 2, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  v9 = b | ((g | ((r | 0xFFFFFF00) << 8)) << 8);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v9;
  y = p1->y;
  z = p1->z;
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = p1->x;
  m_pCurrPosition[1] = y;
  m_pCurrPosition[2] = z;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v9;
  v13 = p2->y;
  v14 = p2->z;
  v15 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = p2->x;
  v15[1] = v13;
  v15[2] = v14;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
    a1: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v8->Draw_2(this: v8, a2: -1, a3: 0);
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
  v7->EndRender(this: v7);
  v7->Release(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00417C30
// Name: public: void StudioModel::drawTransparentBox(class Vector const __near &,class Vector const __near &,struct matrix3x4_t const __near &,float const __near *,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge StudioModel::drawTransparentBox(
        StudioModel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *bbmin,
        const Vector *bbmax,
        const matrix3x4_t *m,
        const float *color,
        const float *wirecolor)
{
  float x; // xmm0_4
  float y; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm4_4
  float z; // xmm2_4
  int v15; // eax
  int v16; // esi
  Vector v2[8]; // [esp+0h] [ebp-C0h] BYREF
  Vector v[8]; // [esp+60h] [ebp-60h] BYREF

  x = bbmin->x;
  y = bbmin->y;
  v12 = bbmax->y;
  v13 = bbmax->x;
  v[0].z = bbmin->z;
  v[1].z = v[0].z;
  v[2].z = v[0].z;
  v[3].z = v[0].z;
  z = bbmax->z;
  v[0].x = x;
  v[0].y = v12;
  v[1].x = x;
  v[1].y = y;
  v[2].x = v13;
  v[2].y = v12;
  v[3].x = v13;
  v[3].y = y;
  v[4].x = v13;
  v[4].y = v12;
  v[4].z = z;
  v[5].x = v13;
  v[5].y = y;
  v[5].z = z;
  v[6].x = x;
  v[6].y = v12;
  v[6].z = z;
  v[7].x = x;
  v[7].y = y;
  v[7].z = z;
  VectorTransform(in1: &v[0].x, in2: m, out: &v2[0].x);
  VectorTransform(in1: &v[1].x, in2: m, out: &v2[1].x);
  VectorTransform(in1: &v[2].x, in2: m, out: &v2[2].x);
  VectorTransform(in1: &v[3].x, in2: m, out: &v2[3].x);
  VectorTransform(in1: &v[4].x, in2: m, out: &v2[4].x);
  VectorTransform(in1: &v[5].x, in2: m, out: &v2[5].x);
  VectorTransform(in1: &v[6].x, in2: m, out: &v2[6].x);
  VectorTransform(in1: &v[7].x, in2: m, out: &v2[7].x);
  v15 = ((int (__thiscall *)(IMaterialSystem *, int, int))g_pMaterialSystem->GetRenderContext)(
          a1: g_pMaterialSystem,
          a2: a3,
          a3: a4);
  v16 = v15;
  if ( v15 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v15 + 8))(a1: v15);
  (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v16 + 36))(a1: v16, a2: g_pAlpha, a3: 0);
  StudioModel::drawBox(this, a2, v: v2, color);
  (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v16 + 36))(a1: v16, a2: g_materialBones, a3: 0);
  StudioModel::drawWireframeBox(this, a2, v: v2, color: wirecolor);
  (*(void (__thiscall **)(int))(*(_DWORD *)v16 + 12))(a1: v16);
  (*(void (__thiscall **)(int))(*(_DWORD *)v16 + 4))(a1: v16);
}

//------------------------------------------------------------------------------
// Address: 0x00417DF0
// Name: private: void StudioModel::DrawBones(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall StudioModel::DrawBones(StudioModel *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  CStudioHdr *v6; // edi
  IMatRenderContext *v7; // eax
  IMatRenderContext *v8; // esi
  IMesh *v9; // esi
  const studiohdr_t *v10; // eax
  mstudiobone_t *v11; // edx
  int v12; // ecx
  char *v13; // edi
  int sznameindex; // edi
  int highlightBone; // eax
  matrix3x4a_t *m_pBoneToWorld; // eax
  float *m_pCurrPosition; // ecx
  float v18; // xmm0_4
  float v19; // xmm1_4
  matrix3x4a_t *v20; // eax
  float *v21; // ecx
  float v22; // xmm0_4
  float v23; // xmm1_4
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  int m_nIndexCount; // [esp+44h] [ebp-210h]
  CMeshBuilder *p_meshBuilder; // [esp+48h] [ebp-20Ch]
  CMeshBuilder meshBuilder; // [esp+50h] [ebp-204h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+238h] [ebp-1Ch]
  int j; // [esp+23Ch] [ebp-18h]
  CStudioHdr *pStudioHdr; // [esp+240h] [ebp-14h]
  int i; // [esp+244h] [ebp-10h]
  unsigned int v34; // [esp+248h] [ebp-Ch]
  mstudiobone_t *pbones; // [esp+24Ch] [ebp-8h]
  bool drawRed; // [esp+253h] [ebp-1h]

  if ( g_viewerSettings.showBones || g_viewerSettings.highlightBone >= 0 )
  {
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      pStudioHdr = this->m_pStudioHdr;
      v6 = m_pStudioHdr;
    }
    else
    {
      v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
      CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
      v6 = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
      pStudioHdr = v6;
    }
    pbones = (mstudiobone_t *)((char *)v6->m_pStudioHdr + v6->m_pStudioHdr->boneindex);
    v7 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int))g_pMaterialSystem->GetRenderContext)(
                                a1: g_pMaterialSystem,
                                a2,
                                a3);
    v8 = v7;
    pRenderContext.m_pObject = v7;
    if ( v7 != nullptr )
      v7->BeginRender(this: v7);
    v8->Bind(this: v8, a2: g_materialBones, a3: nullptr);
    v9 = v8->GetDynamicMesh(this: v8, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    v10 = v6->m_pStudioHdr;
    i = 0;
    drawRed = g_viewerSettings.highlightBone >= 0;
    if ( v10->numbones > 0 )
    {
      v11 = pbones;
      v34 = 0;
      pbones = (mstudiobone_t *)((char *)pbones + 4);
      v12 = -4 - (_DWORD)v11;
      for ( j = -4 - (_DWORD)v11; ; v12 = j )
      {
        v13 = (char *)pbones + v12 + v10->boneindex + (_DWORD)v10;
        if ( (this->BoneMask(this) & *((_DWORD *)v13 + 40)) != 0 )
        {
          sznameindex = pbones->sznameindex;
          highlightBone = g_viewerSettings.highlightBone;
          if ( pbones->sznameindex >= 0
            && (g_viewerSettings.highlightBone < 0 || sznameindex == g_viewerSettings.highlightBone) )
          {
            meshBuilder.m_pMesh = v9;
            meshBuilder.m_bGenerateIndices = true;
            meshBuilder.m_Type = MATERIAL_LINES;
            ((void (__thiscall *)(IMesh *, int, int, CMeshBuilder *))v9->SetPrimitiveType)(
              a1: v9,
              a2: 1,
              a3: m_nIndexCount,
              a4: p_meshBuilder);
            meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 2, a3: 2, a4: &meshBuilder, a5: nullptr);
            meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
            meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
            meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v9->IIndexBuffer;
            meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
            meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
            meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 2;
            meshBuilder.m_IndexBuilder.m_bModify = false;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
            CVertexBuilder::AttachBegin(
              this: &meshBuilder.m_VertexBuilder,
              pMesh: v9,
              nMaxVertexCount: 2,
              desc: &meshBuilder);
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
            CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
            *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = drawRed ? -256 : -16711681;
            m_pBoneToWorld = this->m_pBoneToWorld;
            m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
            v18 = m_pBoneToWorld[sznameindex].m_flMatVal[1][3];
            v19 = m_pBoneToWorld[sznameindex].m_flMatVal[2][3];
            *meshBuilder.m_VertexBuilder.m_pCurrPosition = m_pBoneToWorld[sznameindex].m_flMatVal[0][3];
            m_pCurrPosition[1] = v18;
            m_pCurrPosition[2] = v19;
            CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
            *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = drawRed ? -256 : -16711681;
            v20 = &this->m_pBoneToWorld[v34 / 0x30];
            v21 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
            v22 = v20->m_flMatVal[1][3];
            v23 = v20->m_flMatVal[2][3];
            *meshBuilder.m_VertexBuilder.m_pCurrPosition = v20->m_flMatVal[0][3];
            v21[1] = v22;
            v21[2] = v23;
            CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
            if ( meshBuilder.m_bGenerateIndices )
            {
              switch ( meshBuilder.m_Type )
              {
                case MATERIAL_LINE_STRIP:
                  m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                  break;
                case MATERIAL_LINE_LOOP:
                  m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                  break;
                case MATERIAL_POLYGON:
                  m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                  break;
                case MATERIAL_QUADS:
                  m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                  break;
                case MATERIAL_INSTANCED_QUADS:
                  m_nVertexCount = 0;
                  break;
                default:
                  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
                  break;
              }
              CIndexBuilder::GenerateIndices(
                this: &meshBuilder.m_IndexBuilder,
                primitiveType: meshBuilder.m_Type,
                nIndexCount: m_nVertexCount);
            }
            p_meshBuilder = &meshBuilder;
            m_nIndexCount = meshBuilder.m_IndexBuilder.m_nIndexCount;
            ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
              a1: meshBuilder.m_pMesh,
              a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
            meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
            meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
            meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
            meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
            meshBuilder.m_pMesh = nullptr;
            meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
            v9->Draw_2(this: v9, a2: -1, a3: 0);
            highlightBone = g_viewerSettings.highlightBone;
          }
          if ( highlightBone < 0 || i == highlightBone )
            StudioModel::drawTransform(
              this,
              p_meshBuilder: (CMeshBuilder *)this,
              m_nIndexCount: sznameindex,
              m: &this->m_pBoneToWorld[v34 / 0x30],
              flLength: g_viewerSettings.originAxisLength * 0.40000001);
        }
        v10 = pStudioHdr->m_pStudioHdr;
        ++pbones;
        v34 += 48;
        if ( ++i >= v10->numbones )
          break;
      }
    }
    StudioModel::SetCurrentModel(this);
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
    m_pObject = pRenderContext.m_pObject;
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418200
// Name: private: void StudioModel::DrawAttachments(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall StudioModel::DrawAttachments(StudioModel *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  IMatRenderContext *v4; // esi
  CStudioHdr *m_pStudioHdr; // esi
  const studiohdr_t *v6; // eax
  int i; // edi
  int AttachmentBone; // eax
  IMatRenderContext *m_pObject; // esi
  matrix3x4_t *p_local; // [esp+8h] [ebp-48h]
  matrix3x4_t world; // [esp+1Ch] [ebp-34h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+4Ch] [ebp-4h]

  if ( g_viewerSettings.showAttachments )
  {
    v4 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int))g_pMaterialSystem->GetRenderContext)(
                                a1: g_pMaterialSystem,
                                a2,
                                a3);
    pRenderContext.m_pObject = v4;
    if ( v4 != nullptr )
      v4->BeginRender(this: v4);
    v4->Bind(this: v4, a2: g_materialBones, a3: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v6 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
      CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v6, mdlcache: nullptr);
      m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
    }
    for ( i = 0; i < CStudioHdr::GetNumAttachments(this: m_pStudioHdr); ++i )
    {
      p_local = &CStudioHdr::pAttachment(this: m_pStudioHdr, i)->local;
      AttachmentBone = CStudioHdr::GetAttachmentBone(this: m_pStudioHdr, i);
      ConcatTransforms(in1: &this->m_pBoneToWorld[AttachmentBone], in2: p_local, out: &world);
      StudioModel::drawTransform(
        this,
        p_meshBuilder: (CMeshBuilder *)this,
        m_nIndexCount: i,
        m: &world,
        flLength: g_viewerSettings.originAxisLength * 0.40000001);
    }
    m_pObject = pRenderContext.m_pObject;
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418310
// Name: private: void StudioModel::DrawOriginAxis(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall StudioModel::DrawOriginAxis(StudioModel *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  int v3; // esi
  IMesh *v4; // edi
  float *m_pCurrPosition; // eax
  float *v6; // eax
  float *v7; // eax
  float *v8; // eax
  float v9; // xmm1_4
  float *v10; // eax
  float *v11; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+7Ch] [ebp-1ECh] BYREF
  float fAxisLength; // [esp+264h] [ebp-4h]

  if ( g_viewerSettings.showOriginAxis )
  {
    fAxisLength = g_viewerSettings.originAxisLength;
    if ( g_viewerSettings.originAxisLength > 0.0 )
    {
      v3 = ((int (__thiscall *)(IMaterialSystem *, int, int))g_pMaterialSystem->GetRenderContext)(
             a1: g_pMaterialSystem,
             a2,
             a3);
      if ( v3 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
      (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v3 + 36))(a1: v3, a2: g_materialBones, a3: 0);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 80))(a1: v3, a2: 10);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 84))(a1: v3);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 80))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 84))(a1: v3);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 80))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3);
      (*(void (__thiscall **)(int, int, int, _DWORD, _DWORD))(*(_DWORD *)v3 + 140))(
        a1: v3,
        a2: -1028390912,
        a3: 1065353216,
        a4: 0,
        a5: 0);
      (*(void (__thiscall **)(int, int, _DWORD, _DWORD, int))(*(_DWORD *)v3 + 140))(
        a1: v3,
        a2: -1028390912,
        a3: 0,
        a4: 0,
        a5: 1065353216);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v3 + 144))(
        a1: v3,
        a2: -g_pStudioModel->m_origin.x,
        a3: -g_pStudioModel->m_origin.y,
        a4: -g_pStudioModel->m_origin.z);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)v3 + 140))(
        a1: v3,
        a2: LODWORD(g_pStudioModel->m_angles.y),
        a3: 0,
        a4: 0,
        a5: 1065353216);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)v3 + 140))(
        a1: v3,
        a2: LODWORD(g_pStudioModel->m_angles.x),
        a3: 0,
        a4: 1065353216,
        a5: 0);
      (*(void (__thiscall **)(int, _DWORD, int, _DWORD, _DWORD))(*(_DWORD *)v3 + 140))(
        a1: v3,
        a2: LODWORD(g_pStudioModel->m_angles.z),
        a3: 1065353216,
        a4: 0,
        a5: 0);
      v4 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v3 + 228))(
                      a1: v3,
                      a2: 1,
                      a3: 0,
                      a4: 0,
                      a5: 0);
      CMeshBuilder::CMeshBuilder(this: &meshBuilder);
      meshBuilder.m_pMesh = v4;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_LINES;
      v4->SetPrimitiveType(this: v4, a2: MATERIAL_LINES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: 6, desc: &meshBuilder);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
      m_pCurrPosition[1] = 0.0;
      m_pCurrPosition[2] = 0.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v6 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = fAxisLength;
      v6[1] = 0.0;
      v6[2] = 0.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v7 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
      v7[1] = 0.0;
      v7[2] = 0.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v8 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v9 = fAxisLength;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
      v8[1] = v9;
      v8[2] = 0.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v10 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
      v10[1] = 0.0;
      v10[2] = 0.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v11 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
      v11[1] = 0.0;
      v11[2] = fAxisLength;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      if ( meshBuilder.m_bGenerateIndices )
      {
        switch ( meshBuilder.m_Type )
        {
          case MATERIAL_LINE_STRIP:
            m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
            break;
          case MATERIAL_LINE_LOOP:
            m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
            break;
          case MATERIAL_POLYGON:
            m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
            break;
          case MATERIAL_QUADS:
            m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
            break;
          case MATERIAL_INSTANCED_QUADS:
            m_nVertexCount = 0;
            break;
          default:
            m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
            break;
        }
        CIndexBuilder::GenerateIndices(
          this: &meshBuilder.m_IndexBuilder,
          primitiveType: meshBuilder.m_Type,
          nIndexCount: m_nVertexCount);
      }
      ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
        a1: meshBuilder.m_pMesh,
        a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      meshBuilder.m_pMesh = nullptr;
      v4->Draw_2(this: v4, a2: -1, a3: 0);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 80))(a1: v3, a2: 10);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 88))(a1: v3);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 80))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 88))(a1: v3);
      CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418810
// Name: private: void StudioModel::DrawEditAttachment(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::DrawEditAttachment(StudioModel *this)
{
  CStudioHdr *m_pStudioHdr; // esi
  const studiohdr_t *v3; // eax
  int m_iEditAttachment; // edi
  IMatRenderContext *v5; // eax
  int v6; // edi
  int AttachmentBone; // eax
  matrix3x4_t *p_local; // [esp+8h] [ebp-48h]
  matrix3x4_t world; // [esp+1Ch] [ebp-34h] BYREF
  int iEditAttachment; // [esp+4Ch] [ebp-4h]

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
  }
  m_iEditAttachment = g_viewerSettings.m_iEditAttachment;
  iEditAttachment = g_viewerSettings.m_iEditAttachment;
  if ( g_viewerSettings.m_iEditAttachment >= 0 && m_iEditAttachment < CStudioHdr::GetNumAttachments(this: m_pStudioHdr) )
  {
    v5 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v6 = (int)v5;
    if ( v5 != nullptr )
      v5->BeginRender(this: v5);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v6 + 36))(a1: v6, a2: g_materialBones, a3: 0);
    p_local = &CStudioHdr::pAttachment(this: m_pStudioHdr, i: iEditAttachment)->local;
    AttachmentBone = CStudioHdr::GetAttachmentBone(this: m_pStudioHdr, i: iEditAttachment);
    ConcatTransforms(in1: &this->m_pBoneToWorld[AttachmentBone], in2: p_local, out: &world);
    StudioModel::drawTransform(
      this,
      p_meshBuilder: (CMeshBuilder *)this,
      m_nIndexCount: v6,
      m: &world,
      flLength: g_viewerSettings.originAxisLength * 0.40000001);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418910
// Name: private: void StudioModel::DrawIllumPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::DrawIllumPosition(StudioModel *this)
{
  CStudioHdr *m_pStudioHdr; // esi
  const studiohdr_t *v3; // eax
  float z; // ecx
  float v5; // edx
  float v6; // eax
  float v7; // ecx
  float v8; // edx
  const studiohdr_t *v9; // esi
  float v10; // eax
  __int64 v11; // [esp+4h] [ebp-3Ch]
  __int64 v12; // [esp+4h] [ebp-3Ch]
  __int64 v13; // [esp+4h] [ebp-3Ch]
  Vector worldPt0; // [esp+10h] [ebp-30h] BYREF
  Vector worldPt1; // [esp+1Ch] [ebp-24h] BYREF
  Vector modelPt1; // [esp+28h] [ebp-18h] BYREF
  Vector modelPt0; // [esp+34h] [ebp-Ch] BYREF

  if ( g_viewerSettings.showIllumPosition )
  {
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
      CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
      m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
    }
    z = m_pStudioHdr->m_pStudioHdr->illumposition.z;
    *(_QWORD *)&modelPt0.x = *(_QWORD *)&m_pStudioHdr->m_pStudioHdr->illumposition.x;
    modelPt0.z = z;
    v5 = m_pStudioHdr->m_pStudioHdr->illumposition.z;
    v11 = *(_QWORD *)&m_pStudioHdr->m_pStudioHdr->illumposition.x;
    modelPt0.x = modelPt0.x - 4.0;
    modelPt1.y = *((float *)&v11 + 1);
    modelPt1.z = v5;
    modelPt1.x = *(float *)&v11 + 4.0;
    VectorTransform(in1: &modelPt0.x, in2: &g_viewtransform, out: &worldPt0.x);
    VectorTransform(in1: &modelPt1.x, in2: &g_viewtransform, out: &worldPt1.x);
    StudioModel::drawLine(this, a2: (int)this, p1: &worldPt0, p2: &worldPt1, r: 0xFFu, g: 0, b: 0);
    v6 = m_pStudioHdr->m_pStudioHdr->illumposition.z;
    *(_QWORD *)&modelPt0.x = *(_QWORD *)&m_pStudioHdr->m_pStudioHdr->illumposition.x;
    modelPt0.z = v6;
    v7 = m_pStudioHdr->m_pStudioHdr->illumposition.z;
    v12 = *(_QWORD *)&m_pStudioHdr->m_pStudioHdr->illumposition.x;
    modelPt0.y = modelPt0.y - 4.0;
    LODWORD(modelPt1.x) = v12;
    modelPt1.z = v7;
    modelPt1.y = *((float *)&v12 + 1) + 4.0;
    VectorTransform(in1: &modelPt0.x, in2: &g_viewtransform, out: &worldPt0.x);
    VectorTransform(in1: &modelPt1.x, in2: &g_viewtransform, out: &worldPt1.x);
    StudioModel::drawLine(this, a2: (int)this, p1: &worldPt0, p2: &worldPt1, r: 0, g: 0xFFu, b: 0);
    v8 = m_pStudioHdr->m_pStudioHdr->illumposition.z;
    *(_QWORD *)&modelPt0.x = *(_QWORD *)&m_pStudioHdr->m_pStudioHdr->illumposition.x;
    modelPt0.z = v8;
    v9 = m_pStudioHdr->m_pStudioHdr;
    v10 = v9->illumposition.z;
    v13 = *(_QWORD *)&v9->illumposition.x;
    modelPt0.z = v8 - 4.0;
    *(_QWORD *)&modelPt1.x = v13;
    modelPt1.z = v10 + 4.0;
    VectorTransform(in1: &modelPt0.x, in2: &g_viewtransform, out: &worldPt0.x);
    VectorTransform(in1: &modelPt1.x, in2: &g_viewtransform, out: &worldPt1.x);
    StudioModel::drawLine(this, a2: (int)this, p1: &worldPt0, p2: &worldPt1, r: 0, g: 0, b: 0xFFu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418B80
// Name: public: void StudioModel::SetViewTarget(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall StudioModel::SetViewTarget(StudioModel *this@<ecx>, float a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  float x; // eax
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v7; // eax
  const mstudioattachment_t *v8; // eax
  int AttachmentBone; // eax
  float z; // xmm0_4
  float v11; // xmm2_4
  bool v12; // cc
  float y; // xmm1_4
  StudioLookTarget *v14; // eax
  float v15; // xmm1_4
  __int128 v16; // xmm0
  double FlexController; // st7
  float v18; // xmm4_4
  int studiohdr2index; // ecx
  float v20; // xmm4_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  _DWORD v26[3]; // [esp-Ch] [ebp-84h] BYREF
  matrix3x4_t attToWorld; // [esp+0h] [ebp-78h] BYREF
  Vector tmp; // [esp+30h] [ebp-48h] BYREF
  __int128 eyeAng; // [esp+3Ch] [ebp-3Ch] OVERLAPPED BYREF
  int v30; // [esp+4Ch] [ebp-2Ch]
  Vector v31; // [esp+50h] [ebp-28h] BYREF
  Vector eyeDeflect; // [esp+5Ch] [ebp-1Ch] BYREF
  Vector local; // [esp+68h] [ebp-10h]
  float retaddr; // [esp+78h] [ebp+0h]

  local.y = a2;
  local.z = retaddr;
  if ( (((int (__thiscall *)(StudioModel *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->BoneMask)(
          a1: this,
          a2: a3,
          a3: a4,
          a4: v26[0],
          a5: v26[1],
          a6: v26[2],
          a7: LODWORD(attToWorld.m_flMatVal[0][0]),
          a8: LODWORD(attToWorld.m_flMatVal[0][1]),
          a9: LODWORD(attToWorld.m_flMatVal[0][2]),
          a10: LODWORD(attToWorld.m_flMatVal[0][3]),
          a11: LODWORD(attToWorld.m_flMatVal[1][0]),
          a12: LODWORD(attToWorld.m_flMatVal[1][1]),
          a13: LODWORD(attToWorld.m_flMatVal[1][2]),
          a14: LODWORD(attToWorld.m_flMatVal[1][3]),
          a15: LODWORD(attToWorld.m_flMatVal[2][0]),
          a16: LODWORD(attToWorld.m_flMatVal[2][1]),
          a17: LODWORD(attToWorld.m_flMatVal[2][2]),
          a18: LODWORD(attToWorld.m_flMatVal[2][3]),
          a19: LODWORD(tmp.x),
          a20: LODWORD(tmp.y),
          a21: LODWORD(tmp.z),
          a22: eyeAng,
          a23: DWORD1(eyeAng),
          a24: DWORD2(eyeAng),
          a25: HIDWORD(eyeAng),
          a26: v30,
          a27: LODWORD(v31.x),
          a28: LODWORD(v31.y),
          a29: LODWORD(v31.z),
          a30: LODWORD(eyeDeflect.x),
          a31: LODWORD(eyeDeflect.y),
          a32: LODWORD(eyeDeflect.z))
      & 0x200) != 0 )
  {
    x = COERCE_FLOAT(StudioModel::LookupAttachment(this, szName: "eyes"));
    local.x = x;
    if ( x != NAN )
    {
      m_pStudioHdr = this->m_pStudioHdr;
      if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
      {
        v7 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
        CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v7, mdlcache: nullptr);
        m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
        x = local.x;
      }
      v8 = CStudioHdr::pAttachment(this: m_pStudioHdr, i: SLODWORD(x));
      LODWORD(eyeDeflect.z) = v26;
      LODWORD(eyeDeflect.y) = &v8->local;
      AttachmentBone = CStudioHdr::GetAttachmentBone(this: m_pStudioHdr, i: SLODWORD(local.x));
      ConcatTransforms(
        in1: &this->m_pBoneToWorld[AttachmentBone],
        in2: (const matrix3x4_t *)LODWORD(eyeDeflect.y),
        out: (matrix3x4_t *)LODWORD(eyeDeflect.z));
      z = 0.0;
      v11 = 32.0;
      v12 = this->m_vecHeadTargets.m_Size <= 0;
      y = 0.0;
      eyeDeflect.x = 32.0;
      eyeDeflect.y = 0.0;
      eyeDeflect.z = 0.0;
      if ( !v12 )
      {
        v14 = &this->m_vecHeadTargets.m_Memory.m_pMemory[this->m_vecHeadTargets.m_Size];
        if ( !v14[-1].m_bSelf )
        {
          *((float *)&eyeAng + 1) = v14[-1].m_vecPosition.x - attToWorld.m_flMatVal[0][0];
          *((float *)&eyeAng + 2) = v14[-1].m_vecPosition.y - attToWorld.m_flMatVal[1][0];
          *((float *)&eyeAng + 3) = v14[-1].m_vecPosition.z - attToWorld.m_flMatVal[2][0];
          VectorITransform(in1: (const float *)&eyeAng + 1, in2: (const matrix3x4_t *)v26, out: &eyeDeflect.x);
          z = eyeDeflect.z;
          y = eyeDeflect.y;
          v11 = eyeDeflect.x;
        }
      }
      v15 = (float)(y * y) + (float)(z * z);
      v16 = 0;
      *(float *)&v16 = fsqrt(v15 + (float)(v11 * v11));
      eyeAng = v16;
      VectorNormalize(vec: &eyeDeflect);
      local.x = StudioModel::GetFlexController(this, szName: "eyes_updown");
      FlexController = StudioModel::GetFlexController(this, szName: "eyes_rightleft");
      tmp.x = local.x;
      tmp.y = FlexController;
      tmp.z = 0.0;
      AngleVectors(angles: (const QAngle *)&tmp, forward: &v31);
      v18 = eyeDeflect.x;
      v31.x = (float)(v18 * v18) * 0.0;
      v31.y = v31.y * (float)(v18 * v18);
      v31.z = v31.z * (float)(v18 * v18);
      eyeDeflect.x = v31.x + eyeDeflect.x;
      eyeDeflect.y = v31.y + eyeDeflect.y;
      eyeDeflect.z = v31.z + eyeDeflect.z;
      VectorNormalize(vec: (Vector *)LODWORD(eyeDeflect.x));
      studiohdr2index = m_pStudioHdr->m_pStudioHdr->studiohdr2index;
      if ( studiohdr2index == 0 || (v20 = *(float *)&m_pStudioHdr->m_pStudioHdr->name[studiohdr2index]) == 0.0 )
        v20 = 0.866;
      v21 = eyeDeflect.x;
      v22 = eyeDeflect.y;
      v23 = eyeDeflect.z;
      if ( v20 > eyeDeflect.x )
      {
        if ( (float)((float)(eyeDeflect.z * eyeDeflect.z) + (float)(eyeDeflect.y * eyeDeflect.y)) <= 0.0 )
        {
          v21 = 1.0;
        }
        else
        {
          v24 = fsqrt(
                  (float)(1.0 - (float)(v20 * v20))
                / (float)((float)(eyeDeflect.z * eyeDeflect.z) + (float)(eyeDeflect.y * eyeDeflect.y)));
          v21 = v20;
          v22 = eyeDeflect.y * v24;
          v23 = eyeDeflect.z * v24;
        }
      }
      VectorTransform(
        in1: COERCE_CONST_FLOAT_(*(float *)&eyeAng * v21),
        in2: COERCE_CONST_MATRIX3X4_T_(*(float *)&eyeAng * v22),
        out: COERCE_FLOAT_(*(float *)&eyeAng * v23));
      g_pStudioRender->SetEyeViewTarget(
        this: g_pStudioRender,
        a2: m_pStudioHdr->m_pStudioHdr,
        a3: this->m_bodynum,
        a4: (const Vector *)&attToWorld.m_flMatVal[2][1]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418E80
// Name: public: void StudioModel::CalcHeadRotation(class Vector __near * const,class Quaternion __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::CalcHeadRotation(StudioModel *this, Vector *pos, Quaternion *q)
{
  unsigned int v3; // eax
  int v5; // ebx
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v7; // eax
  int AttachmentBone; // ebx
  float v9; // xmm4_4
  int v10; // ebx
  StudioLookTarget *m_pMemory; // ecx
  int v12; // edi
  float v13; // xmm1_4
  float v14; // xmm2_4
  float m_flWeight; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  matrix3x4_t attToWorld; // [esp+14h] [ebp-70h] BYREF
  Vector vTargetDir; // [esp+44h] [ebp-40h] BYREF
  Vector vEyes; // [esp+50h] [ebp-34h] BYREF
  Vector vForward; // [esp+5Ch] [ebp-28h] BYREF
  Vector dir; // [esp+68h] [ebp-1Ch] BYREF
  Vector vHead; // [esp+74h] [ebp-10h]
  mstudioattachment_t *patt; // [esp+80h] [ebp-4h]
  int savedregs; // [esp+84h] [ebp+0h] BYREF
  float dt; // [esp+8Ch] [ebp+8h]
  float flHeadInfluence; // [esp+90h] [ebp+Ch]

  v3 = _S2;
  if ( (_S2 & 1) == 0 )
  {
    v3 = _S2 | 1;
    _S2 |= 1u;
  }
  if ( (v3 & 2) == 0 )
    _S2 = v3 | 2;
  if ( this->m_nSolveHeadTurn != 0 )
  {
    if ( this->m_dt == 0.0 )
      this->m_dt = 0.1;
    v5 = StudioModel::LookupAttachment(this, szName: "forward");
    if ( v5 != -1 )
    {
      m_pStudioHdr = this->m_pStudioHdr;
      if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
      {
        v7 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
        CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v7, mdlcache: nullptr);
        m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
      }
      patt = (mstudioattachment_t *)CStudioHdr::pAttachment(this: m_pStudioHdr, i: v5);
      AttachmentBone = CStudioHdr::GetAttachmentBone(this: m_pStudioHdr, i: v5);
      BuildBoneChain(
        pStudioHdr: m_pStudioHdr,
        rootxform: &g_viewtransform,
        pos,
        q,
        iBone: AttachmentBone,
        pBoneToWorld: this->m_pBoneToWorld);
      ConcatTransforms(in1: &this->m_pBoneToWorld[AttachmentBone], in2: &patt->local, out: &attToWorld);
      vEyes.x = 1.0;
      vEyes.y = 0.0;
      vEyes.z = 0.0;
      VectorRotate(in1: &vEyes.x, in2: &attToWorld, out: &vForward.x);
      dt = this->m_dt;
      if ( this->m_nSolveHeadTurn == 2 )
        dt = 0.1;
      v9 = 0.0;
      vEyes.x = attToWorld.m_flMatVal[0][3];
      vEyes.y = attToWorld.m_flMatVal[1][3];
      v10 = 0;
      vEyes.z = attToWorld.m_flMatVal[2][3];
      vHead = vForward;
      flHeadInfluence = 0.0;
      if ( this->m_vecHeadTargets.m_Size > 0 )
      {
        m_pMemory = this->m_vecHeadTargets.m_Memory.m_pMemory;
        v12 = 0;
        do
        {
          if ( m_pMemory[v12].m_bSelf )
          {
            dir = vForward;
          }
          else
          {
            v13 = m_pMemory[v12].m_vecPosition.y - vEyes.y;
            v14 = m_pMemory[v12].m_vecPosition.z - vEyes.z;
            dir.x = m_pMemory[v12].m_vecPosition.x - vEyes.x;
            dir.y = v13;
            dir.z = v14;
          }
          VectorNormalize(vec: &dir);
          m_pMemory = this->m_vecHeadTargets.m_Memory.m_pMemory;
          m_flWeight = m_pMemory[v12].m_flWeight;
          if ( m_flWeight <= 0.0 )
          {
            v9 = flHeadInfluence;
          }
          else if ( flHeadInfluence == 0.0 )
          {
            vHead = dir;
            v9 = m_flWeight;
            flHeadInfluence = m_flWeight;
          }
          else
          {
            v9 = (float)((float)(1.0 - m_flWeight) * flHeadInfluence) + m_flWeight;
            v16 = m_flWeight / v9;
            v17 = 1.0 - (float)(m_flWeight / v9);
            flHeadInfluence = v9;
            vHead.x = (float)(vHead.x * v17) + (float)(dir.x * v16);
            vHead.y = (float)(vHead.y * v17) + (float)(dir.y * v16);
            vHead.z = (float)(vHead.z * v17) + (float)(dir.z * v16);
          }
          ++v10;
          ++v12;
        }
        while ( v10 < this->m_vecHeadTargets.m_Size );
      }
      vTargetDir.x = (float)((float)(1.0 - v9) * vForward.x) + (float)(vHead.x * v9);
      vTargetDir.y = (float)(vForward.y * (float)(1.0 - v9)) + (float)(vHead.y * v9);
      vTargetDir.z = (float)(vForward.z * (float)(1.0 - v9)) + (float)(vHead.z * v9);
      VectorNormalize(vec: &vTargetDir);
      StudioModel::SetPoseParameter(this, szName: "head_pitch", flValue: 0.0);
      StudioModel::SetPoseParameter(this, szName: "head_yaw", flValue: 0.0);
      StudioModel::SetPoseParameter(this, szName: "head_roll", flValue: 0.0);
      StudioModel::SetHeadPosition(this, a2: COERCE_FLOAT(&savedregs), &attToWorld, vTargetPos: &vTargetDir, dt);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419230
// Name: private: void StudioModel::DrawPhysmesh(class CPhysmesh __near *,int,class IMaterial __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge StudioModel::DrawPhysmesh(
        StudioModel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CPhysmesh *pMesh,
        matrix3x4_t *boneIndex,
        IMaterial *pMaterial,
        float *color)
{
  IMatRenderContext *v8; // esi
  IMesh *v9; // edi
  int v11; // eax
  int v12; // esi
  int v14; // edi
  int v15; // edi
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-224h] BYREF
  float v19; // [esp+1E8h] [ebp-3Ch]
  float v20; // [esp+1ECh] [ebp-38h]
  float v21; // [esp+1F0h] [ebp-34h]
  CMatRenderContextPtr pRenderContext; // [esp+1F4h] [ebp-30h]
  float v23; // [esp+1F8h] [ebp-2Ch]
  IMesh *pMatMesh; // [esp+1FCh] [ebp-28h]
  float v25; // [esp+200h] [ebp-24h]
  float v26; // [esp+204h] [ebp-20h]
  float v27; // [esp+208h] [ebp-1Ch]
  float v28; // [esp+20Ch] [ebp-18h]
  float v29; // [esp+210h] [ebp-14h]
  float v30; // [esp+214h] [ebp-10h]
  Vector v; // [esp+218h] [ebp-Ch] BYREF
  float pMesha; // [esp+22Ch] [ebp+8h]
  matrix3x4a_t *pMatrix; // [esp+230h] [ebp+Ch]
  int i; // [esp+234h] [ebp+10h]
  float colora; // [esp+238h] [ebp+14h]

  if ( (int)boneIndex < 0 )
    pMatrix = &g_viewtransform;
  else
    pMatrix = &this->m_pBoneToWorld[(_DWORD)boneIndex];
  v8 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
                              a1: g_pMaterialSystem,
                              a2: a4);
  pRenderContext.m_pObject = v8;
  if ( v8 != nullptr )
    v8->BeginRender(this: v8);
  ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, int, int))v8->Bind)(
    a1: v8,
    a2: pMaterial,
    a3: 0,
    a4: a3,
    a5: a2);
  v9 = v8->GetDynamicMesh(this: v8, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  pMatMesh = v9;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v11 = pMesh->m_vertCount / 3;
  meshBuilder.m_pMesh = v9;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLES;
  v12 = 3 * v11;
  v9->SetPrimitiveType(this: v9, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v12, a3: v12, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v9->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v12;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v9, nMaxVertexCount: v12, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  i = 0;
  if ( pMesh->m_vertCount > 0 )
  {
    v14 = 0;
    do
    {
      VectorTransform(in1: (const float *)((char *)&pMesh->m_pVerts->x + v14), in2: pMatrix, out: &v.x);
      *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v;
      v20 = (float)(color[2] * 255.0) + 8388608.0;
      v21 = (float)(color[1] * 255.0) + 8388608.0;
      colora = (float)(*color * 255.0) + 8388608.0;
      pMesha = (float)(color[3] * 255.0) + 8388608.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v20)
                                                          | ((LOBYTE(v21)
                                                            | ((LOBYTE(colora) | (LOBYTE(pMesha) << 8)) << 8)) << 8);
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v15 = v14 + 12;
      VectorTransform(in1: (const float *)((char *)&pMesh->m_pVerts->x + v15), in2: pMatrix, out: &v.x);
      *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v;
      v25 = (float)(color[2] * 255.0) + 8388608.0;
      v19 = (float)(color[1] * 255.0) + 8388608.0;
      v27 = (float)(*color * 255.0) + 8388608.0;
      v23 = (float)(color[3] * 255.0) + 8388608.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v25)
                                                          | ((LOBYTE(v19) | ((LOBYTE(v27) | (LOBYTE(v23) << 8)) << 8)) << 8);
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v15 += 12;
      VectorTransform(in1: (const float *)((char *)&pMesh->m_pVerts->x + v15), in2: pMatrix, out: &v.x);
      *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v;
      v26 = (float)(color[2] * 255.0) + 8388608.0;
      v28 = (float)(color[1] * 255.0) + 8388608.0;
      v29 = (float)(*color * 255.0) + 8388608.0;
      v30 = (float)(color[3] * 255.0) + 8388608.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v26)
                                                          | ((LOBYTE(v28) | ((LOBYTE(v29) | (LOBYTE(v30) << 8)) << 8)) << 8);
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v14 = v15 + 12;
      i += 3;
    }
    while ( i < pMesh->m_vertCount );
    v9 = pMatMesh;
  }
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
    a1: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v9->Draw_2(this: v9, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x00419710
// Name: private: void StudioModel::DrawPhysConvex(class CPhysmesh __near *,int,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::DrawPhysConvex(StudioModel *this, CPhysmesh *pMesh, int boneIndex, IMaterial *pMaterial)
{
  IMatRenderContext *m_pObject; // esi
  IMesh *v6; // esi
  ICollisionQuery *m_pCollisionModel; // ecx
  int (__thiscall *TriangleCount)(ICollisionQuery *, int); // edx
  int v9; // eax
  int v10; // edi
  int m_nVertexCount; // eax
  Vector *v12; // esi
  int k; // edi
  int v14; // eax
  Vector objectSpaceVerts[3]; // [esp+Ch] [ebp-260h] BYREF
  CMeshBuilder meshBuilder; // [esp+30h] [ebp-23Ch] BYREF
  float color[4]; // [esp+218h] [ebp-54h] BYREF
  Vector v; // [esp+228h] [ebp-44h] BYREF
  float v19; // [esp+234h] [ebp-38h]
  float v20; // [esp+238h] [ebp-34h]
  matrix3x4_t *matrix; // [esp+23Ch] [ebp-30h]
  float v22; // [esp+240h] [ebp-2Ch]
  int v23; // [esp+244h] [ebp-28h]
  float v24; // [esp+248h] [ebp-24h]
  IMesh *pMatMesh; // [esp+24Ch] [ebp-20h]
  float v26; // [esp+250h] [ebp-1Ch]
  float v27; // [esp+254h] [ebp-18h]
  float v28; // [esp+258h] [ebp-14h]
  float v29; // [esp+25Ch] [ebp-10h]
  CMatRenderContextPtr pRenderContext; // [esp+260h] [ebp-Ch]
  int triCount; // [esp+264h] [ebp-8h]
  int key; // [esp+268h] [ebp-4h]
  int i; // [esp+278h] [ebp+Ch]
  int ja; // [esp+27Ch] [ebp+10h]
  int j; // [esp+27Ch] [ebp+10h]

  matrix = &this->m_pBoneToWorld[boneIndex];
  m_pObject = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  m_pObject->Bind(this: m_pObject, a2: pMaterial, a3: nullptr);
  i = 0;
  if ( pMesh->m_pCollisionModel->ConvexCount(this: pMesh->m_pCollisionModel) > 0 )
  {
    v23 = boneIndex + 1;
    key = boneIndex + 1;
    do
    {
      RandomColor(color, key);
      v6 = m_pObject->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      m_pCollisionModel = pMesh->m_pCollisionModel;
      meshBuilder.m_pMesh = nullptr;
      meshBuilder.m_bGenerateIndices = false;
      memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
      memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
      meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
      TriangleCount = m_pCollisionModel->TriangleCount;
      pMatMesh = v6;
      v9 = TriangleCount(this: m_pCollisionModel, a2: i);
      v10 = 3 * v9;
      triCount = v9;
      meshBuilder.m_pMesh = v6;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_TRIANGLES;
      ja = 3 * v9;
      v6->SetPrimitiveType(this: v6, a2: MATERIAL_TRIANGLES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v10, a3: v10, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v6->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v10;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = v6;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = ja;
      meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
      m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_bModify = false;
      if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
      {
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
      }
      meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
      meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
      qmemcpy(
        meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
        meshBuilder.m_VertexBuilder.m_pTexCoord,
        sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
      meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
      j = 0;
      if ( triCount > 0 )
      {
        v19 = (float)(color[2] * 255.0) + 8388608.0;
        v26 = (float)(color[1] * 255.0) + 8388608.0;
        v20 = (float)(color[0] * 255.0) + 8388608.0;
        v24 = (float)(color[3] * 255.0) + 8388608.0;
        do
        {
          pMesh->m_pCollisionModel->GetTriangleVerts(this: pMesh->m_pCollisionModel, a2: i, a3: j, a4: objectSpaceVerts);
          v12 = objectSpaceVerts;
          for ( k = 3; k != 0; --k )
          {
            VectorTransform(in1: &v12->x, in2: matrix, out: &v.x);
            *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v;
            v27 = v19;
            v28 = v26;
            v22 = v20;
            v29 = v24;
            *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v19)
                                                                | ((LOBYTE(v26)
                                                                  | ((LOBYTE(v20) | (LOBYTE(v24) << 8)) << 8)) << 8);
            CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
            ++v12;
          }
          ++j;
        }
        while ( j < triCount );
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
      }
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
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      meshBuilder.m_pMesh = nullptr;
      pMatMesh->Draw_2(this: pMatMesh, a2: -1, a3: 0);
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
      key += v23;
      ++i;
      v14 = pMesh->m_pCollisionModel->ConvexCount(this: pMesh->m_pCollisionModel);
      m_pObject = pRenderContext.m_pObject;
    }
    while ( i < v14 );
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x00419C10
// Name: private: void StudioModel::DrawHitboxes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::DrawHitboxes(StudioModel *this)
{
  CStudioHdr *m_pStudioHdr; // ebx
  const studiohdr_t *v3; // eax
  int Sentence; // eax
  CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *p_m_Hitboxes; // ecx
  unsigned __int16 m_Head; // ax
  int highlightHitbox; // edx
  int v8; // esi
  int p_m_BBox; // ecx
  int v10; // eax
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  bool v14; // zf
  int m_sequence; // eax
  const studiohdr_t *v16; // ecx
  mstudioseqdesc_t *v17; // esi
  int v18; // eax
  mstudioseqdesc_t *v19; // eax
  matrix3x4a_t *v20; // [esp-Ch] [ebp-3Ch]
  float color[4]; // [esp+Ch] [ebp-24h] BYREF
  float wirecolor[4]; // [esp+1Ch] [ebp-14h] BYREF
  CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *list; // [esp+2Ch] [ebp-4h]

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
  }
  if ( g_pAlpha == nullptr )
    g_pAlpha = g_pMaterialSystem->FindMaterial(
                 this: g_pMaterialSystem,
                 a2: "debug/debughitbox",
                 a3: "Other textures",
                 a4: 0,
                 a5: 0);
  if ( g_viewerSettings.showHitBoxes || g_viewerSettings.highlightHitbox >= 0 )
  {
    Sentence = CAudioSource::GetSentence(this: (ConVar *)g_MDLViewer);
    p_m_Hitboxes = &g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory[Sentence].m_Hitboxes;
    m_Head = g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory[Sentence].m_Hitboxes.m_Head;
    list = p_m_Hitboxes;
    if ( m_Head != 0xFFFF )
    {
      highlightHitbox = g_viewerSettings.highlightHitbox;
      do
      {
        if ( highlightHitbox < 0 || (v8 = m_Head, highlightHitbox == m_Head) )
        {
          v8 = m_Head;
          p_m_BBox = (int)&p_m_Hitboxes->m_Memory.m_pMemory[m_Head].m_Element.m_BBox;
          v10 = *(_DWORD *)(p_m_BBox + 4) % 8;
          v11 = hullcolor[v10][0] * 0.7;
          wirecolor[0] = v11;
          v12 = hullcolor[v10][1] * 0.7;
          wirecolor[1] = v12;
          v13 = hullcolor[v10][2] * 0.7;
          wirecolor[2] = v13;
          v20 = &this->m_pBoneToWorld[*(_DWORD *)p_m_BBox];
          wirecolor[3] = hullcolor[v10][3] * 0.4;
          StudioModel::drawTransparentBox(
            this,
            a2: (int)m_pStudioHdr,
            a3: (int)this,
            a4: v8,
            bbmin: (const Vector *)(p_m_BBox + 8),
            bbmax: (const Vector *)(p_m_BBox + 20),
            m: v20,
            color: wirecolor,
            wirecolor: hullcolor[v10]);
          highlightHitbox = g_viewerSettings.highlightHitbox;
          p_m_Hitboxes = list;
        }
        m_Head = p_m_Hitboxes->m_Memory.m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
  }
  if ( g_viewerSettings.showSequenceBoxes )
  {
    v14 = m_pStudioHdr->m_pVModel == nullptr;
    m_sequence = this->m_sequence;
    color[0] = 0.69999999;
    color[1] = 1.0;
    color[2] = 0.0;
    color[3] = 0.60000002;
    wirecolor[0] = 1.0;
    wirecolor[1] = 1.0;
    wirecolor[2] = 0.0;
    wirecolor[3] = 1.0;
    if ( v14 )
    {
      v16 = m_pStudioHdr->m_pStudioHdr;
      if ( m_sequence < 0 || m_sequence >= v16->numlocalseq )
        m_sequence = 0;
      v17 = (mstudioseqdesc_t *)((char *)v16 + 212 * m_sequence + v16->localseqindex);
    }
    else
    {
      v17 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: m_sequence);
    }
    v18 = this->m_sequence;
    if ( m_pStudioHdr->m_pVModel != nullptr )
    {
      v19 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: this->m_sequence);
    }
    else
    {
      m_pStudioHdr = (CStudioHdr *)m_pStudioHdr->m_pStudioHdr;
      if ( v18 < 0 || v18 >= m_pStudioHdr[1].m_nPerfAnimatedBones )
        v18 = 0;
      v19 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v18 + m_pStudioHdr[1].m_nPerfUsedBones);
    }
    StudioModel::drawTransparentBox(
      this,
      a2: (int)m_pStudioHdr,
      a3: (int)this,
      a4: (int)&v17->bbmax,
      bbmin: &v19->bbmin,
      bbmax: &v17->bbmax,
      m: &g_viewtransform,
      color,
      wirecolor);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419EA0
// Name: private: void StudioModel::DrawPhysicsModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::DrawPhysicsModel(StudioModel *this)
{
  IStudioPhysics *m_pPhysics; // ecx
  int v3; // edi
  CPhysmesh *v4; // ebx
  CStudioHdr *v5; // eax
  const studiohdr_t *v6; // eax
  int v7; // eax
  int v8; // ebx
  CPhysmesh *v9; // edi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v11; // eax
  matrix3x4_t *BoneIndex; // eax
  float yellow[4]; // [esp+4h] [ebp-20h] BYREF
  float red[4]; // [esp+14h] [ebp-10h] BYREF

  if ( g_viewerSettings.showPhysicsModel )
  {
    m_pPhysics = this->m_pPhysics;
    if ( g_viewerSettings.renderMode != 0 )
    {
      v8 = 0;
      if ( m_pPhysics->Count(this: m_pPhysics) > 0 )
      {
        red[0] = 1.0;
        yellow[0] = 1.0;
        yellow[1] = 1.0;
        red[1] = 0.0;
        red[2] = 0.0;
        red[3] = 0.25;
        yellow[2] = 0.0;
        yellow[3] = 0.5;
        do
        {
          v9 = this->m_pPhysics->GetMesh(this: this->m_pPhysics, a2: v8);
          m_pStudioHdr = this->m_pStudioHdr;
          if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
          {
            v11 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
            CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v11, mdlcache: nullptr);
            m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
          }
          BoneIndex = (matrix3x4_t *)FindBoneIndex(pstudiohdr: m_pStudioHdr, pName: v9->m_boneName);
          if ( (int)BoneIndex < 0 )
          {
            StudioModel::DrawPhysmesh(
              this,
              a2: v8,
              a3: (int)v9,
              a4: (int)this,
              pMesh: v9,
              boneIndex: (matrix3x4_t *)0xFFFFFFFF,
              pMaterial: g_materialBones,
              color: red);
          }
          else if ( v8 + 1 == g_viewerSettings.highlightPhysicsBone )
          {
            StudioModel::DrawPhysmesh(
              this,
              a2: v8,
              a3: (int)v9,
              a4: (int)this,
              pMesh: v9,
              boneIndex: BoneIndex,
              pMaterial: g_materialBones,
              color: red);
          }
          else if ( g_viewerSettings.highlightPhysicsBone < 1 )
          {
            StudioModel::DrawPhysmesh(
              this,
              a2: v8,
              a3: (int)v9,
              a4: (int)this,
              pMesh: v9,
              boneIndex: BoneIndex,
              pMaterial: g_materialBones,
              color: yellow);
          }
          ++v8;
        }
        while ( v8 < this->m_pPhysics->Count(this: this->m_pPhysics) );
      }
    }
    else
    {
      v3 = 0;
      if ( m_pPhysics->Count(this: m_pPhysics) > 0 )
      {
        do
        {
          v4 = this->m_pPhysics->GetMesh(this: this->m_pPhysics, a2: v3);
          v5 = this->m_pStudioHdr;
          if ( v5 != nullptr && v5->m_pStudioHdr == nullptr )
          {
            v6 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
            CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v6, mdlcache: nullptr);
            v5 = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
          }
          v7 = FindBoneIndex(pstudiohdr: v5, pName: v4->m_boneName);
          StudioModel::DrawPhysConvex(this, pMesh: v4, boneIndex: v7, pMaterial: g_materialFlatshaded);
          ++v3;
        }
        while ( v3 < this->m_pPhysics->Count(this: this->m_pPhysics) );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A070
// Name: public: virtual int StudioModel::DrawModel(bool)
// Source: json
//------------------------------------------------------------------------------
int __userpurge StudioModel::DrawModel@<eax>(StudioModel *this@<ecx>, int a2@<edi>, float *mergeBones)
{
  IMDLCache *v3; // ebx
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v7; // eax
  CStudioHdr *v8; // eax
  const studiohdr_t *v9; // eax
  CStudioHdr *v10; // edi
  float *m_pRenderData; // ebx
  int j; // eax
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  IMatRenderContext *v14; // eax
  int numflexdesc; // edi
  float *v16; // eax
  IMatRenderContext_vtbl *v17; // edx
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // eax
  float *v19; // eax
  float v20; // xmm0_4
  int v21; // ecx
  float *v22; // edx
  float v23; // xmm1_4
  float *v24; // eax
  char *v25; // edi
  float v26; // xmm2_4
  char *v27; // ebx
  float v28; // xmm2_4
  char *v29; // ebx
  float v30; // xmm2_4
  char *v31; // ebx
  double v32; // st7
  int v33; // ebx
  float v34; // xmm2_4
  int v35; // ebx
  int v36; // eax
  float v37; // xmm1_4
  float *materialIndex; // edi
  IMatRenderContext *m_pObject; // esi
  IMatRenderContext_vtbl *v40; // edx
  IMatRenderContext_vtbl *v41; // edx
  studioloddata_t *m_pLODs; // ecx
  const char *v44; // eax
  IMaterial *v45; // ecx
  const studiohdr_t *v46; // edx
  matrix3x4_t *v47; // edi
  const studiohdr_t *v48; // edx
  IMatRenderContext *v49; // esi
  IMatRenderContext_vtbl *v50; // eax
  IMatRenderContext_vtbl *v51; // edx
  IStudioRender *v52; // [esp+4h] [ebp-110h]
  matrix3x4a_t *m_pBoneToWorld; // [esp+Ch] [ebp-108h]
  matrix3x4a_t *v54; // [esp+Ch] [ebp-108h]
  long double v56; // [esp+34h] [ebp-E0h]
  long double v57; // [esp+34h] [ebp-E0h]
  matrix3x4_t invViewTransform; // [esp+3Ch] [ebp-D8h] BYREF
  matrix3x4_t tmp1; // [esp+6Ch] [ebp-A8h] BYREF
  float one[4]; // [esp+9Ch] [ebp-78h] BYREF
  char *v61; // [esp+ACh] [ebp-68h]
  char *v62; // [esp+B0h] [ebp-64h]
  char *v63; // [esp+B4h] [ebp-60h]
  char *v64; // [esp+B8h] [ebp-5Ch]
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+BCh] [ebp-58h]
  CMatRenderData<float> rdDelayedFlexWeights; // [esp+C0h] [ebp-54h] BYREF
  CMatRenderData<float> rdFlexWeights; // [esp+D0h] [ebp-44h] BYREF
  int nCount; // [esp+E0h] [ebp-34h]
  float *pFlexWeights; // [esp+E4h] [ebp-30h]
  Vector vecModelOrigin; // [esp+E8h] [ebp-2Ch] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+F4h] [ebp-20h]
  float zero[4]; // [esp+F8h] [ebp-1Ch] BYREF
  CStudioHdr *pStudioHdr; // [esp+108h] [ebp-Ch]
  int i; // [esp+10Ch] [ebp-8h]
  float d; // [esp+110h] [ebp-4h]
  int savedregs; // [esp+114h] [ebp+0h] BYREF
  float pFlexDelayedWeights; // [esp+11Ch] [ebp+8h]
  float *pFlexDelayedWeightsa; // [esp+11Ch] [ebp+8h]

  v3 = g_pMDLCache;
  BeginLock = g_pMDLCache->BeginLock;
  cacheCriticalSection.m_pCache = g_pMDLCache;
  BeginLock(this: g_pMDLCache);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    goto LABEL_74;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v7 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v7, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      goto LABEL_74;
  }
  if ( m_pStudioHdr == nullptr )
    goto LABEL_74;
  ++g_smodels_total;
  StudioModel::UpdateStudioRenderConfig(
    bWireframe: g_viewerSettings.renderMode == 0,
    bZBufferWireframe: false,
    bNormals: g_viewerSettings.showNormals,
    bTangentFrame: g_viewerSettings.showTangentFrame);
  v8 = this->m_pStudioHdr;
  if ( v8 == nullptr || v8->m_pStudioHdr != nullptr )
  {
    pStudioHdr = this->m_pStudioHdr;
    v10 = v8;
  }
  else
  {
    v9 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v9, mdlcache: nullptr);
    v10 = this->m_pStudioHdr;
    if ( v10->m_pStudioHdr == nullptr )
    {
LABEL_74:
      v3->EndLock(this: v3);
      return 0;
    }
    pStudioHdr = this->m_pStudioHdr;
  }
  if ( v10 == nullptr || v10->m_pStudioHdr->numbodyparts == 0 )
    goto LABEL_74;
  AngleMatrix(angles: &this->m_angles, matrix: &g_viewtransform);
  *(float *)&rdDelayedFlexWeights.m_pRenderData = this->m_origin.x * -1.0;
  *(float *)&rdDelayedFlexWeights.m_nCount = this->m_origin.y * -1.0;
  *(float *)&rdDelayedFlexWeights.m_bNeedsUnlock = this->m_origin.z * -1.0;
  MatrixSetColumn(in: (const Vector *)&rdDelayedFlexWeights.m_pRenderData, column: 3, out: &g_viewtransform);
  vecModelOrigin.x = this->m_origin.x * -1.0;
  vecModelOrigin.y = this->m_origin.y * -1.0;
  vecModelOrigin.z = this->m_origin.z * -1.0;
  MatrixSetColumn(in: &vecModelOrigin, column: 3, out: &g_viewtransform);
  rdDelayedFlexWeights.m_pRenderData = (float *)1065353216;
  rdDelayedFlexWeights.m_nCount = 0;
  *(_DWORD *)&rdDelayedFlexWeights.m_bNeedsUnlock = 0;
  rdFlexWeights.m_pRenderData = nullptr;
  rdFlexWeights.m_nCount = 0;
  *(_DWORD *)&rdFlexWeights.m_bNeedsUnlock = 1065353216;
  zero[1] = 0.0;
  zero[2] = 1.0;
  zero[3] = 0.0;
  ((void (__thiscall *)(IStudioRender *, Vector *, float *, float **, float **, int))g_pStudioRender->SetViewState)(
    a1: g_pStudioRender,
    a2: &vec3_origin,
    a3: &zero[1],
    a4: &rdFlexWeights.m_pRenderData,
    a5: &rdDelayedFlexWeights.m_pRenderData,
    a6: a2);
  this->SetUpBones(this, a2: (bool)mergeBones);
  StudioModel::SetupLighting(this, a2: (int)this);
  StudioModel::SetViewTarget(this, a2: COERCE_FLOAT(&savedregs), a3: (int)v10, a4: (int)this);
  m_pRenderData = nullptr;
  for ( j = 0; j < v10->m_pStudioHdr->numflexdesc; ++j )
    g_flexdescweight[j] = 0.0;
  this->RunFlexRules(this);
  d = 0.80000001;
  pFlexDelayedWeights = this->m_dt;
  if ( pFlexDelayedWeights != 0.0 )
  {
    __libm_sse2_log(x: v56);
    __libm_sse2_exp(x: v57);
    d = (float)((float)0.800000011920929 * 30.30303) * pFlexDelayedWeights;
  }
  GetRenderContext = g_pMaterialSystem->GetRenderContext;
  pFlexWeights = nullptr;
  pFlexDelayedWeightsa = nullptr;
  v14 = GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = v14;
  if ( v14 != nullptr )
    v14->BeginRender(this: v14);
  numflexdesc = v10->m_pStudioHdr->numflexdesc;
  rdFlexWeights.m_pRenderData = nullptr;
  rdFlexWeights.m_bNeedsUnlock = false;
  rdDelayedFlexWeights.m_bNeedsUnlock = false;
  i = numflexdesc;
  if ( numflexdesc != 0 )
  {
    v16 = (float *)pRenderContext.m_pObject->LockRenderData(this: pRenderContext.m_pObject, a2: 4 * numflexdesc);
    v17 = pRenderContext.m_pObject->__vftable;
    rdFlexWeights.m_pRenderData = v16;
    pFlexWeights = v16;
    LockRenderData = v17->LockRenderData;
    rdFlexWeights.m_bNeedsUnlock = true;
    v19 = (float *)LockRenderData(this: pRenderContext.m_pObject, a2: 4 * numflexdesc);
    v20 = d;
    m_pRenderData = v19;
    v21 = 0;
    rdDelayedFlexWeights.m_pRenderData = v19;
    rdDelayedFlexWeights.m_bNeedsUnlock = true;
    pFlexDelayedWeightsa = v19;
    if ( numflexdesc >= 4 )
    {
      v22 = rdFlexWeights.m_pRenderData + 3;
      v62 = (char *)((char *)rdFlexWeights.m_pRenderData - (char *)v19);
      v63 = (char *)((char *)g_flexdescweight - (char *)v19);
      LODWORD(d) = (char *)g_flexdescweight2 - (char *)v19;
      v64 = (char *)(&unk_5438D4 - (_UNKNOWN *)v19);
      v61 = (char *)(&unk_5448D4 - (_UNKNOWN *)v19);
      nCount = &unk_5438D8 - (_UNKNOWN *)v19;
      v23 = 1.0 - v20;
      v24 = v19 + 1;
      v25 = (char *)(&unk_5448D8 - (_UNKNOWN *)m_pRenderData);
      do
      {
        v26 = g_flexdescweight[v21];
        v27 = v63;
        g_flexdescweight2[v21] = (float)(v23 * v26) + (float)(v20 * g_flexdescweight2[v21]);
        *(v22 - 3) = v26;
        *(v24 - 1) = g_flexdescweight2[v21];
        v28 = *(float *)((char *)v24 + (_DWORD)v27);
        *(float *)((char *)v24 + LODWORD(d)) = (float)(*(float *)((char *)v24 + LODWORD(d)) * v20) + (float)(v23 * v28);
        *(float *)((char *)v24 + (_DWORD)v62) = v28;
        v29 = v64;
        *v24 = *(float *)((char *)v24 + LODWORD(d));
        v30 = *(float *)((char *)v24 + (_DWORD)v29);
        v31 = v61;
        *(float *)((char *)v24 + (_DWORD)v61) = (float)(v23 * v30)
                                              + (float)(v20 * *(float *)((char *)v24 + (_DWORD)v61));
        *(v22 - 1) = v30;
        v32 = *(float *)((char *)v24 + (_DWORD)v31);
        v33 = nCount;
        v24[1] = v32;
        v34 = *(float *)((char *)v24 + v33);
        v35 = i;
        *(float *)((char *)v24 + (_DWORD)v25) = (float)(*(float *)((char *)v24 + (_DWORD)v25) * v20)
                                              + (float)(v23 * v34);
        *v22 = v34;
        v24[2] = *(float *)((char *)v24 + (_DWORD)v25);
        v21 += 4;
        v24 += 4;
        v22 += 4;
      }
      while ( v21 < v35 - 3 );
      m_pRenderData = rdDelayedFlexWeights.m_pRenderData;
      numflexdesc = i;
    }
    if ( v21 < numflexdesc )
    {
      v36 = (char *)rdFlexWeights.m_pRenderData - (char *)g_flexdescweight;
      do
      {
        v37 = g_flexdescweight[v21];
        g_flexdescweight2[v21] = (float)(v37 * (float)(1.0 - v20)) + (float)(v20 * g_flexdescweight2[v21]);
        *(float *)((char *)&g_flexdescweight[v21] + v36) = v37;
        m_pRenderData[v21] = g_flexdescweight2[v21];
        ++v21;
      }
      while ( v21 < numflexdesc );
    }
  }
  ((void (__cdecl *)(int))g_pStudioRender->SetAlphaModulation)(a1: 1065353216);
  materialIndex = nullptr;
  g_bDrawModelInfoValid = true;
  memset(dst: (unsigned __int8 *)&g_DrawModelInfo, value: 0, count: sizeof(g_DrawModelInfo));
  g_DrawModelInfo.m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  g_DrawModelInfo.m_pHardwareData = (studiohwdata_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: this->m_MDLHandle);
  if ( g_DrawModelInfo.m_pHardwareData == nullptr )
  {
    m_pObject = pRenderContext.m_pObject;
    if ( pRenderContext.m_pObject != nullptr )
    {
      if ( m_pRenderData != nullptr )
      {
        v40 = pRenderContext.m_pObject->__vftable;
        if ( rdDelayedFlexWeights.m_bNeedsUnlock )
          v40->UnlockRenderData(this: pRenderContext.m_pObject, a2: m_pRenderData);
        else
          v40->ReleaseRenderData(this: pRenderContext.m_pObject);
      }
      if ( rdFlexWeights.m_pRenderData != nullptr )
      {
        v41 = m_pObject->__vftable;
        if ( rdFlexWeights.m_bNeedsUnlock )
          v41->UnlockRenderData(this: m_pObject, a2: rdFlexWeights.m_pRenderData);
        else
          v41->ReleaseRenderData(this: m_pObject);
      }
      m_pObject->EndRender(this: m_pObject);
      m_pObject->Release(this: m_pObject);
    }
    cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
    return 0;
  }
  g_DrawModelInfo.m_Decals = nullptr;
  g_DrawModelInfo.m_Skin = this->m_skinnum;
  g_DrawModelInfo.m_Body = this->m_bodynum;
  g_DrawModelInfo.m_HitboxSet = CAudioSource::GetSentence(this: (ConVar *)g_MDLViewer);
  g_DrawModelInfo.m_pClientEntity = nullptr;
  if ( g_viewerSettings.autoLOD )
    g_DrawModelInfo.m_Lod = -1;
  else
    g_DrawModelInfo.m_Lod = g_viewerSettings.lod;
  g_DrawModelInfo.m_pColorMeshes = nullptr;
  if ( g_viewerSettings.renderMode == 4 )
  {
    DebugDrawModelBadVerts(
      a1: (int)&savedregs,
      a2: 0,
      a3: (int)this,
      pStudioRender: g_pStudioRender,
      info: &g_DrawModelInfo,
      pBoneToWorld: this->m_pBoneToWorld);
    m_pBoneToWorld = this->m_pBoneToWorld;
    zero[1] = 0.2;
    zero[2] = 0.2;
    zero[3] = 0.2;
    DebugDrawModelWireframe(
      pStudioRender: g_pStudioRender,
      info: &g_DrawModelInfo,
      pBoneToWorld: m_pBoneToWorld,
      modelOrigin: &vecModelOrigin,
      color: (const Vector *)&zero[1]);
    g_DrawModelInfo.m_Lod = this->m_LodUsed;
    g_pStudioRender->GetPerfStats(this: g_pStudioRender, a2: &g_DrawModelResults, a3: &g_DrawModelInfo, a4: nullptr);
  }
  else
  {
    switch ( g_viewerSettings.renderMode )
    {
      case 3:
        DebugDrawModelBoneWeights(
          pStudioRender: g_pStudioRender,
          info: &g_DrawModelInfo,
          pBoneToWorld: this->m_pBoneToWorld);
        v54 = this->m_pBoneToWorld;
        v52 = g_pStudioRender;
        break;
      case 5:
        m_pLODs = g_DrawModelInfo.m_pHardwareData->m_pLODs;
        v44 = defaultValue;
        if ( m_pLODs != nullptr )
        {
          materialIndex = (float *)g_viewerSettings.materialIndex;
          if ( g_viewerSettings.materialIndex < m_pLODs->numMaterials )
          {
            v45 = m_pLODs->ppMaterials[g_viewerSettings.materialIndex];
            v44 = (const char *)v45->GetName(this: v45);
          }
        }
        DebugDrawModelTexCoord(
          pStudioRender: g_pStudioRender,
          pMaterialName: v44,
          info: &g_DrawModelInfo,
          pBoneToWorld: this->m_pBoneToWorld,
          w: (float)g_viewerSettings.width,
          h: (float)g_viewerSettings.height);
        g_pStudioRender->GetPerfStats(this: g_pStudioRender, a2: &g_DrawModelResults, a3: &g_DrawModelInfo, a4: nullptr);
        this->m_LodUsed = g_DrawModelInfo.m_Lod;
        goto LABEL_57;
      case 6:
        DebugDrawModelVertColocation(
          a1: 0,
          pStudioRender: g_pStudioRender,
          info: &g_DrawModelInfo,
          pBoneToWorld: this->m_pBoneToWorld);
        v54 = this->m_pBoneToWorld;
        v52 = g_pStudioRender;
        break;
      default:
        materialIndex = pFlexWeights;
        g_pStudioRender->DrawModel(
          this: g_pStudioRender,
          a2: &g_DrawModelResults,
          a3: &g_DrawModelInfo,
          a4: this->m_pBoneToWorld,
          a5: pFlexWeights,
          a6: pFlexDelayedWeightsa,
          a7: &vecModelOrigin,
          a8: 0);
        this->m_LodUsed = g_DrawModelResults.m_nLODUsed;
        this->m_LodMetric = (float)g_DrawModelResults.m_flLODMetric;
        g_pStudioRender->GetPerfStats(this: g_pStudioRender, a2: &g_DrawModelResults, a3: &g_DrawModelInfo, a4: nullptr);
        if ( g_viewerSettings.overlayWireframe && g_viewerSettings.renderMode != 0 )
        {
          StudioModel::UpdateStudioRenderConfig(
            bWireframe: true,
            bZBufferWireframe: true,
            bNormals: false,
            bTangentFrame: false);
          g_pStudioRender->DrawModel(
            this: g_pStudioRender,
            a2: nullptr,
            a3: &g_DrawModelInfo,
            a4: this->m_pBoneToWorld,
            a5: materialIndex,
            a6: pFlexDelayedWeightsa,
            a7: &vecModelOrigin,
            a8: 0);
          StudioModel::UpdateStudioRenderConfig(
            bWireframe: g_viewerSettings.renderMode == 0,
            bZBufferWireframe: false,
            bNormals: g_viewerSettings.showNormals,
            bTangentFrame: g_viewerSettings.showTangentFrame);
        }
        goto LABEL_57;
    }
    zero[3] = 0.2;
    zero[2] = 0.2;
    zero[1] = 0.2;
    DebugDrawModelWireframe(
      pStudioRender: v52,
      info: &g_DrawModelInfo,
      pBoneToWorld: v54,
      modelOrigin: &vecModelOrigin,
      color: (const Vector *)&zero[1]);
    g_pStudioRender->GetPerfStats(this: g_pStudioRender, a2: &g_DrawModelResults, a3: &g_DrawModelInfo, a4: nullptr);
    this->m_LodUsed = g_DrawModelInfo.m_Lod;
  }
LABEL_57:
  nCount = g_DrawModelResults.m_ActualTriCount;
  StudioModel::DrawBones(this, a2: (int)materialIndex, a3: (int)this);
  StudioModel::DrawAttachments(this, a2: (int)materialIndex, a3: (int)this);
  StudioModel::DrawOriginAxis(this, a2: (int)materialIndex, a3: (int)this);
  StudioModel::DrawEditAttachment(this);
  StudioModel::DrawHitboxes(this);
  StudioModel::DrawPhysicsModel(this);
  StudioModel::DrawIllumPosition(this);
  if ( g_viewerSettings.showShadow && g_viewerSettings.showGround )
  {
    MatrixInvert(in: &g_viewtransform, out: &invViewTransform);
    v46 = pStudioHdr->m_pStudioHdr;
    i = 0;
    if ( v46->numbones > 0 )
    {
      d = 0.0;
      do
      {
        v47 = (matrix3x4a_t *)((char *)this->m_pBoneToWorld + LODWORD(d));
        ConcatTransforms(in1: &invViewTransform, in2: v47, out: &tmp1);
        *(_QWORD *)&tmp1.m_flMatVal[2][0] = 0;
        *(_QWORD *)&tmp1.m_flMatVal[2][2] = 0x3D4CCCCD00000000LL;
        ConcatTransforms(in1: &g_viewtransform, in2: &tmp1, out: v47);
        v48 = pStudioHdr->m_pStudioHdr;
        LODWORD(d) += 48;
        ++i;
      }
      while ( i < v48->numbones );
    }
    g_DrawModelInfo.m_Lod = *(_DWORD *)(((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: this->m_MDLHandle)
                                      + 4)
                          - 1;
    memset(zero, 0, sizeof(zero));
    g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: zero);
    g_pStudioRender->ForcedMaterialOverride(this: g_pStudioRender, a2: g_materialShadow, a3: OVERRIDE_NORMAL);
    StudioModel::UpdateStudioRenderConfig(
      bWireframe: false,
      bZBufferWireframe: false,
      bNormals: false,
      bTangentFrame: false);
    g_pStudioRender->DrawModel(
      this: g_pStudioRender,
      a2: nullptr,
      a3: &g_DrawModelInfo,
      a4: this->m_pBoneToWorld,
      a5: pFlexWeights,
      a6: pFlexDelayedWeightsa,
      a7: &vecModelOrigin,
      a8: 0);
    StudioModel::UpdateStudioRenderConfig(
      bWireframe: g_viewerSettings.renderMode == 0,
      bZBufferWireframe: false,
      bNormals: g_viewerSettings.showNormals,
      bTangentFrame: g_viewerSettings.showTangentFrame);
    g_pStudioRender->ForcedMaterialOverride(this: g_pStudioRender, a2: nullptr, a3: OVERRIDE_NORMAL);
    one[0] = 1.0;
    one[1] = 1.0;
    one[2] = 1.0;
    one[3] = 1.0;
    g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: one);
  }
  v49 = pRenderContext.m_pObject;
  if ( pRenderContext.m_pObject != nullptr )
  {
    if ( m_pRenderData != nullptr )
    {
      v50 = pRenderContext.m_pObject->__vftable;
      if ( rdDelayedFlexWeights.m_bNeedsUnlock )
        v50->UnlockRenderData(this: pRenderContext.m_pObject, a2: m_pRenderData);
      else
        v50->ReleaseRenderData(this: pRenderContext.m_pObject);
    }
    if ( rdFlexWeights.m_pRenderData != nullptr )
    {
      v51 = v49->__vftable;
      if ( rdFlexWeights.m_bNeedsUnlock )
        v51->UnlockRenderData(this: v49, a2: rdFlexWeights.m_pRenderData);
      else
        v51->ReleaseRenderData(this: v49);
    }
    v49->EndRender(this: v49);
    v49->Release(this: v49);
  }
  cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
  return nCount;
}

//------------------------------------------------------------------------------
// Address: 0x0041ABA0
// Name: public: void StudioModel::ClearLookTargets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::ClearLookTargets(StudioModel *this)
{
  this->m_vecHeadTargets.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041AC30
// Name: public: void StudioModel::AddLookTarget(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::AddLookTarget(StudioModel *this, const Vector *vecPosition, float flWeight)
{
  int m_Size; // edx
  StudioLookTarget tmp; // [esp+0h] [ebp-14h] BYREF

  if ( this->m_vecHeadTargets.m_Size <= 8 )
  {
    m_Size = this->m_vecHeadTargets.m_Size;
    tmp.m_flWeight = flWeight;
    tmp.m_vecPosition = *vecPosition;
    tmp.m_bSelf = false;
    CUtlVector<StudioLookTarget,CUtlMemory<StudioLookTarget,int>>::InsertBefore(
      this: &this->m_vecHeadTargets,
      elem: m_Size,
      src: &tmp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041AC90
// Name: public: void StudioModel::AddLookTargetSelf(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::AddLookTargetSelf(StudioModel *this, float flWeight)
{
  int m_Size; // edx
  StudioLookTarget tmp; // [esp+0h] [ebp-14h] BYREF

  if ( this->m_vecHeadTargets.m_Size <= 8 )
  {
    m_Size = this->m_vecHeadTargets.m_Size;
    tmp.m_flWeight = flWeight;
    memset(&tmp.m_vecPosition, 0, sizeof(tmp.m_vecPosition));
    tmp.m_bSelf = true;
    CUtlVector<StudioLookTarget,CUtlMemory<StudioLookTarget,int>>::InsertBefore(
      this: &this->m_vecHeadTargets,
      elem: m_Size,
      src: &tmp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041ADE0
// Name: public: virtual void StudioModel::SetUpBones(bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge StudioModel::SetUpBones(
        StudioModel *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        bool mergeBones)
{
  void *v5; // esp
  unsigned int v6; // eax
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v9; // eax
  CStudioHdr *v10; // edi
  int m_sequence; // eax
  float v12; // ecx
  matrix3x4_t *v13; // eax
  DWORD TickCount; // eax
  int v15; // ecx
  int (__thiscall *BoneMask)(StudioModel *); // edx
  int v17; // eax
  StudioModel_vtbl *v18; // edx
  int v19; // eax
  DWORD v20; // eax
  int v21; // ecx
  int v22; // edx
  int v23; // ecx
  int NumSeq_Internal; // eax
  float v25; // xmm0_4
  double RealtimeTime; // st7
  int m_prevsequence; // edx
  const Quaternion *v28; // eax
  int *p_m_priority; // ecx
  int i; // edi
  int v31; // eax
  float *p_m_weight; // edi
  DWORD v33; // eax
  int v34; // ecx
  int v35; // edx
  int v36; // ecx
  int v37; // eax
  DWORD v38; // eax
  int v39; // ecx
  CIKContext *v40; // edi
  matrix3x4a_t *m_pBoneToWorld; // edx
  bool v42; // cc
  int v43; // edi
  float v44; // xmm0_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  float v47; // xmm3_4
  float v48; // edi
  int v49; // eax
  int v50; // ecx
  int v51; // eax
  int v52; // edi
  matrix3x4a_t *v53; // edx
  int v54; // eax
  matrix3x4a_t *v55; // edx
  matrix3x4a_t *v56; // edx
  matrix3x4a_t *v57; // edx
  matrix3x4a_t *v58; // edx
  matrix3x4a_t *v59; // edx
  matrix3x4a_t *v60; // edx
  matrix3x4a_t *v61; // edx
  matrix3x4a_t *v62; // edx
  matrix3x4a_t *v63; // edx
  matrix3x4a_t *v64; // edx
  float v65; // edi
  int v66; // eax
  int v67; // ecx
  int v68; // edi
  int v69; // eax
  int v70; // eax
  int v71; // ecx
  CJiggleBones *v72; // eax
  UtlLinkedListElem_t<JiggleData,unsigned short> *m_pMemory; // edx
  DWORD v74; // eax
  int v75; // ecx
  unsigned int v76; // edi
  float v77; // xmm0_4
  CJiggleBones *m_pJiggleBones; // ecx
  int v79; // eax
  matrix3x4a_t *v80; // edx
  const matrix3x4_t *v81; // eax
  CStudioHdr *v82; // edx
  float v83; // eax
  const studiohdr_t *v84; // ecx
  int v85; // edi
  const char *v86; // eax
  int v87; // eax
  bool v88; // zf
  ikcontextikrule_t *v89; // eax
  CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *v90; // eax
  CIKContext v93; // [esp+20h] [ebp-12CCh] BYREF
  bool v94[256]; // [esp+1098h] [ebp-254h] BYREF
  Vector v95; // [esp+1198h] [ebp-154h] BYREF
  QAngle v96; // [esp+11A4h] [ebp-148h] BYREF
  matrix3x4_t v97; // [esp+11B0h] [ebp-13Ch] BYREF
  CBoneBitList v98; // [esp+11E0h] [ebp-10Ch] BYREF
  matrix3x4_t v99; // [esp+1200h] [ebp-ECh] BYREF
  QAngle v100; // [esp+1230h] [ebp-BCh] BYREF
  float v101[4]; // [esp+123Ch] [ebp-B0h] BYREF
  Vector v102; // [esp+124Ch] [ebp-A0h] BYREF
  Vector v103; // [esp+1258h] [ebp-94h] BYREF
  Vector v104; // [esp+1264h] [ebp-88h] BYREF
  Quaternion v105; // [esp+1270h] [ebp-7Ch] BYREF
  Vector v106; // [esp+1280h] [ebp-6Ch] BYREF
  float v107[4]; // [esp+128Ch] [ebp-60h] BYREF
  float v108[2]; // [esp+129Ch] [ebp-50h] BYREF
  float v109; // [esp+12A4h] [ebp-48h]
  Vector v110; // [esp+12A8h] [ebp-44h] BYREF
  int v111; // [esp+12B4h] [ebp-38h]
  int v112; // [esp+12B8h] [ebp-34h]
  int v113; // [esp+12BCh] [ebp-30h]
  float v114; // [esp+12C0h] [ebp-2Ch]
  const Quaternion *v115; // [esp+12C4h] [ebp-28h]
  unsigned int v116; // [esp+12C8h] [ebp-24h]
  IBoneSetup cycle; // [esp+12CCh] [ebp-20h] BYREF
  float flTime; // [esp+12D0h] [ebp-1Ch]
  float flRealTime; // [esp+12D4h] [ebp-18h]
  int flLength; // [esp+12D8h] [ebp-14h]
  int p_m_ik; // [esp+12DCh] [ebp-10h]
  int v122; // [esp+12E0h] [ebp-Ch]
  void *v123; // [esp+12E4h] [ebp-8h]
  int v124; // [esp+12E8h] [ebp-4h] BYREF
  void *retaddr; // [esp+12ECh] [ebp+0h]

  v122 = a2;
  v123 = retaddr;
  v5 = alloca(4808);
  v6 = _S1;
  if ( (_S1 & 1) == 0 )
  {
    v6 = _S1 | 1;
    _S1 |= 1u;
  }
  if ( (v6 & 2) == 0 )
  {
    v6 |= 2u;
    _S1 = v6;
  }
  if ( (v6 & 4) == 0 )
  {
    v6 |= 4u;
    _S1 = v6;
  }
  if ( (v6 & 8) == 0 )
  {
    v6 |= 8u;
    _S1 = v6;
  }
  if ( (v6 & 0x10) == 0 )
    _S1 = v6 | 0x10;
  m_pStudioHdr = this->m_pStudioHdr;
  if ( *(float *)&m_pStudioHdr == 0.0 || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    flRealTime = *(float *)&this->m_pStudioHdr;
    v10 = m_pStudioHdr;
  }
  else
  {
    v9 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v9, mdlcache: nullptr);
    v10 = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
    flRealTime = *(float *)&v10;
  }
  m_sequence = this->m_sequence;
  if ( v10->m_pVModel != nullptr )
  {
    v13 = (matrix3x4_t *)CStudioHdr::pSeqdesc_Internal(this: v10, i: this->m_sequence);
  }
  else
  {
    v12 = *(float *)&v10->m_pStudioHdr;
    if ( m_sequence < 0 || m_sequence >= *(_DWORD *)(LODWORD(v12) + 188) )
      m_sequence = 0;
    v13 = (matrix3x4_t *)(LODWORD(v12) + *(_DWORD *)(LODWORD(v12) + 192) + 212 * m_sequence);
  }
  flLength = (int)v13;
  MatrixAngles(matrix: &g_viewtransform, angles: &v100.x);
  v106.x = g_viewtransform.m_flMatVal[0][3];
  v106.y = g_viewtransform.m_flMatVal[1][3];
  v106.z = g_viewtransform.m_flMatVal[2][3];
  p_m_ik = 0;
  TickCount = GetTickCount();
  v15 = g_prevTicksRT;
  if ( g_prevTicksRT == 0 )
    v15 = TickCount;
  g_prevTicksRT = TickCount;
  BoneMask = this->BoneMask;
  g_timeRT = (float)((float)(int)(TickCount - v15) * 0.001) + g_timeRT;
  v114 = g_timeRT;
  v17 = ((int (__thiscall *)(StudioModel *, int, int))BoneMask)(a1: this, a2: a3, a3: a4);
  CIKContext::Init(
    this: &this->m_ik,
    pStudioHdr: v10,
    angles: &v100,
    pos: &v106,
    flTime: v114,
    iFramecounter: this->m_iFramecounter,
    boneMask: v17);
  if ( g_viewerSettings.enableIK )
    p_m_ik = (int)&this->m_ik;
  v18 = this->__vftable;
  flLength = 0;
  LODWORD(flRealTime) = this->m_poseparameter;
  v19 = v18->BoneMask(this);
  IBoneSetup::IBoneSetup(
    this: &cycle,
    pStudioHdr: v10,
    boneMask: v19,
    poseParameter: (const float *)LODWORD(flRealTime),
    pPoseDebugger: (IPoseDebugger *)flLength);
  IBoneSetup::InitPose(this: &cycle, pos: pos, q: (QuaternionAligned *)&q);
  v20 = GetTickCount();
  v21 = g_prevTicksRT;
  if ( g_prevTicksRT == 0 )
    v21 = v20;
  v22 = v20 - v21;
  v23 = this->m_sequence;
  g_prevTicksRT = v20;
  flLength = p_m_ik;
  g_timeRT = (float)((float)v22 * 0.001) + g_timeRT;
  flRealTime = g_timeRT;
  flTime = 1.0;
  IBoneSetup::AccumulatePose(
    this: &cycle,
    pos: pos,
    q: &q,
    sequence: v23,
    cycle: this->m_cycle,
    flWeight: 1.0,
    flTime: g_timeRT,
    pIKContext: (CIKContext *)p_m_ik);
  if ( !g_viewerSettings.blendSequenceChanges
    || this->m_blendtime <= this->m_sequencetime
    || this->m_prevsequence == this->m_sequence
    || (v10->m_pVModel != nullptr
      ? (NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: v10))
      : (NumSeq_Internal = v10->m_pStudioHdr->numlocalseq),
        this->m_prevsequence >= NumSeq_Internal || (*(_BYTE *)(flLength + 12) & 2) != 0) )
  {
    this->m_prevcycle = this->m_cycle;
  }
  else
  {
    if ( this->m_prevcycle >= 1.0 )
      this->m_prevcycle = 0.0;
    v25 = 1.0 - (float)(this->m_sequencetime / this->m_blendtime);
    flLength = 0;
    v114 = v25;
    RealtimeTime = GetRealtimeTime();
    m_prevsequence = this->m_prevsequence;
    flRealTime = RealtimeTime;
    IBoneSetup::AccumulatePose(
      this: &cycle,
      pos: pos,
      q: &q,
      sequence: m_prevsequence,
      cycle: this->m_prevcycle,
      flWeight: (float)((float)(v114 * 3.0) * v114) - (float)((float)((float)(v114 * 2.0) * v114) * v114),
      flTime: flRealTime,
      pIKContext: (CIKContext *)flLength);
  }
  v28 = nullptr;
  p_m_priority = &this->m_Layer[0].m_priority;
  for ( i = 2; i != 0; --i )
  {
    if ( *((float *)p_m_priority - 2) > 0.0 && *p_m_priority > (int)v28 )
      v28 = (const Quaternion *)*p_m_priority;
    if ( *((float *)p_m_priority + 3) > 0.0 && p_m_priority[5] > (int)v28 )
      v28 = (const Quaternion *)p_m_priority[5];
    if ( *((float *)p_m_priority + 8) > 0.0 && p_m_priority[10] > (int)v28 )
      v28 = (const Quaternion *)p_m_priority[10];
    if ( *((float *)p_m_priority + 13) > 0.0 && p_m_priority[15] > (int)v28 )
      v28 = (const Quaternion *)p_m_priority[15];
    p_m_priority += 20;
  }
  v115 = v28;
  flTime = 0.0;
  if ( (int)v28 >= 0 )
  {
    *(float *)&v31 = 0.0;
    do
    {
      p_m_weight = &this->m_Layer[0].m_weight;
      for ( flLength = 8; flLength != 0; --flLength )
      {
        if ( *((_DWORD *)p_m_weight + 2) == v31 && *p_m_weight > 0.0 )
        {
          v33 = GetTickCount();
          v34 = g_prevTicksRT;
          if ( g_prevTicksRT == 0 )
            v34 = v33;
          v35 = v33 - v34;
          v36 = *((_DWORD *)p_m_weight - 1);
          g_prevTicksRT = v33;
          flLength = p_m_ik;
          g_timeRT = (float)((float)v35 * 0.001) + g_timeRT;
          flRealTime = g_timeRT;
          IBoneSetup::AccumulatePose(
            this: &cycle,
            pos: pos,
            q: &q,
            sequence: v36,
            cycle: *(p_m_weight - 2),
            flWeight: *p_m_weight,
            flTime: g_timeRT,
            pIKContext: (CIKContext *)p_m_ik);
          *(float *)&v31 = flTime;
        }
        p_m_weight += 5;
      }
      ++v31;
      flTime = *(float *)&v31;
    }
    while ( v31 <= (int)v115 );
  }
  if ( this->m_nSolveHeadTurn != 0 )
    StudioModel::GetBodyPoseParametersFromFlex(this);
  StudioModel::CalcHeadRotation(this, pos: pos, q: &q);
  CIKContext::CIKContext(this: &v93);
  v37 = this->BoneMask(this);
  CIKContext::Init(
    this: &v93,
    pStudioHdr: (const CStudioHdr *)LODWORD(flRealTime),
    angles: &v100,
    pos: &v106,
    flTime: 0.0,
    iFramecounter: 0,
    boneMask: v37);
  v38 = GetTickCount();
  v39 = dword_705B94;
  if ( dword_705B94 == 0 )
    v39 = v38;
  dword_705B94 = v38;
  *(float *)&dword_705B90 = (float)((float)((float)(int)(v38 - v39) * 0.001) * g_viewerSettings.speedScale)
                          + *(float *)&dword_705B90;
  IBoneSetup::CalcAutoplaySequences(
    this: &cycle,
    pos: pos,
    q: &q,
    flRealTime: *(float *)&dword_705B90,
    pIKContext: &v93);
  IBoneSetup::CalcBoneAdj(this: &cycle, pos: pos, q: &q, controllers: this->m_controller);
  v40 = (CIKContext *)p_m_ik;
  memset(&v98, 0, sizeof(v98));
  if ( p_m_ik != 0 )
  {
    StudioModel::GetMovement(this, prevcycle: this->m_prevIKCycles, vecPos: &v110, vecAngles: &v96);
    VectorRotate(in1: &v110.x, in2: &g_viewtransform, out: &v103.x);
    m_pBoneToWorld = this->m_pBoneToWorld;
    v110 = v103;
    CIKContext::UpdateTargets(this: v40, pos: pos, q: &q, boneToWorld: m_pBoneToWorld, boneComputed: &v98);
    v42 = v40->m_target.m_Size <= 0;
    flLength = 0;
    if ( !v42 )
    {
      v43 = (int)&v40->m_target.m_Memory.m_Memory[104];
      do
      {
        if ( *(_DWORD *)(v43 - 100) == 3 )
        {
          *(float *)(v43 - 8) = *(float *)(v43 - 8) - v110.x;
          *(float *)(v43 - 4) = *(float *)(v43 - 4) - v110.y;
          v44 = *(float *)v43 - v110.z;
          flLength = (int)&v97;
          flRealTime = COERCE_FLOAT(&g_viewtransform);
          *(float *)v43 = v44;
          MatrixInvert(in: (const matrix3x4_t *)LODWORD(flRealTime), out: (matrix3x4_t *)flLength);
          VectorTransform(in1: (const float *)(v43 - 8), in2: &v97, out: v108);
          v109 = *(float *)(v43 - 24);
          VectorTransform(in1: v108, in2: &g_viewtransform, out: (float *)(v43 - 8));
          MatrixAngles(matrix: &g_viewtransform, q: &v105, pos: &v95);
          v45 = *(float *)(v43 - 36);
          *(Quaternion *)(v43 + 4) = v105;
          memset(v101, 0, sizeof(v101));
          v107[2] = 0.0;
          v46 = 1.0 - *(float *)(v43 - 12);
          v107[0] = 1.0;
          v107[1] = 1.0;
          v107[3] = 1.0;
          if ( v45 <= 0.0 )
            v107[0] = v46;
          else
            v107[1] = v46;
          v47 = *(float *)(v43 - 20);
          if ( v47 <= 1.0 )
            v47 = 1.0;
          v104.x = COERCE_FLOAT(LODWORD(v47) ^ _mask__NegFloat_) + v108[0];
          v104.y = COERCE_FLOAT(LODWORD(v47) ^ _mask__NegFloat_) + v108[1];
          v104.z = v109;
          v102.x = v108[0] + v47;
          v102.y = v108[1] + v47;
          v102.z = v109;
          StudioModel::drawTransparentBox(
            this,
            a2: (int)&v124,
            a3: v43,
            a4: (int)this,
            bbmin: &v104,
            bbmax: &v102,
            m: &g_viewtransform,
            color: v101,
            wirecolor: v107);
          if ( !g_viewerSettings.enableTargetIK )
            *(_DWORD *)(v43 - 12) = 0;
        }
        else if ( *(_DWORD *)(v43 - 100) == 5 )
        {
          QuaternionMatrix(q: (const Quaternion *)(v43 + 4), pos: (const Vector *)(v43 - 8), matrix: &v97);
          StudioModel::drawTransform(
            this,
            p_meshBuilder: (CMeshBuilder *)&v124,
            m_nIndexCount: v43,
            m: &v97,
            flLength: g_viewerSettings.originAxisLength * 0.40000001);
        }
        v43 += 340;
        ++flLength;
      }
      while ( flLength < *(_DWORD *)(p_m_ik + 4080) );
      v40 = (CIKContext *)p_m_ik;
    }
    CIKContext::SolveDependencies(this: v40, pos: pos, q: &q, boneToWorld: this->m_pBoneToWorld, boneComputed: &v98);
  }
  v48 = flRealTime;
  v49 = *(_DWORD *)LODWORD(flRealTime);
  v50 = *(_DWORD *)(*(_DWORD *)LODWORD(flRealTime) + 160);
  flLength = *(_DWORD *)(*(_DWORD *)LODWORD(flRealTime) + 156);
  LODWORD(v114) = v49 + v50;
  memset(dst: (unsigned __int8 *)v94, value: 0, count: flLength);
  if ( g_viewerSettings.showPhysicsPreview )
    StudioModel::OverrideBones(this, a2: (int)this, override: v94);
  v51 = *(_DWORD *)LODWORD(v48);
  v112 = 0;
  if ( *(int *)(v51 + 156) > 0 )
  {
    v116 = 0;
    v113 = 0;
    flLength = (int)&pos[0].y;
    v115 = &q;
    v111 = 12;
    do
    {
      v52 = v51 + v113 + *(_DWORD *)(v51 + 160);
      if ( (this->BoneMask(this) & *(_DWORD *)(v52 + 160)) != 0 )
      {
        if ( !v94[v112] )
        {
          if ( ((1 << (v112 & 0x1F)) & v98.m_Ints[(unsigned int)v112 >> 5]) != 0 )
          {
            v76 = v116;
          }
          else
          {
            v64 = this->m_pBoneToWorld;
            v65 = flRealTime;
            v105.x = 0.0;
            LODWORD(v105.y) = v64;
            if ( CalcProceduralBone(
                   pStudioHdr: (const CStudioHdr *)LODWORD(flRealTime),
                   iBone: v112,
                   bonetoworld: (CBoneAccessor *)&v105) )
            {
              goto LABEL_122;
            }
            QuaternionMatrix(q: v115, matrix: &v99);
            v99.m_flMatVal[0][3] = *(float *)(flLength - 4);
            v99.m_flMatVal[1][3] = *(float *)flLength;
            v99.m_flMatVal[2][3] = *(float *)(flLength + 4);
            v66 = *(_DWORD *)LODWORD(v65);
            v67 = *(_DWORD *)(*(_DWORD *)LODWORD(v65) + 160);
            v68 = v113;
            if ( (*(_BYTE *)(v113 + v67 + v66 + 160) & 4) != 0
              && (*(_BYTE *)(v113 + *(_DWORD *)(v66 + 160) + v66 + 164) & 5) != 0 )
            {
              v69 = *(_DWORD *)(v113 + LODWORD(v114) + 4);
              flLength = (int)&v97;
              flRealTime = COERCE_FLOAT(&v99);
              if ( v69 == -1 )
                flTime = COERCE_FLOAT(&g_viewtransform);
              else
                LODWORD(flTime) = &this->m_pBoneToWorld[v69];
              ConcatTransforms(
                in1: (const matrix3x4_t *)LODWORD(flTime),
                in2: (const matrix3x4_t *)LODWORD(flRealTime),
                out: (matrix3x4_t *)flLength);
              v70 = *(_DWORD *)LODWORD(flRealTime) + v68 + *(_DWORD *)(*(_DWORD *)LODWORD(flRealTime) + 160);
              v71 = *(_DWORD *)(v70 + 168);
              if ( v71 != 0 )
                LODWORD(flTime) = v70 + v71;
              else
                flTime = 0.0;
              if ( this->m_pJiggleBones == nullptr )
              {
                v72 = (CJiggleBones *)operator new(nSize: 0x1Cu);
                if ( v72 != nullptr )
                {
                  v72->m_jiggleBoneState.m_Memory.m_pMemory = nullptr;
                  v72->m_jiggleBoneState.m_Memory.m_nAllocationCount = 0;
                  v72->m_jiggleBoneState.m_Memory.m_nGrowSize = 0;
                  v72->m_jiggleBoneState.m_LastAlloc.index = -1;
                  *(_DWORD *)&v72->m_jiggleBoneState.m_FirstFree = 0xFFFF;
                  m_pMemory = v72->m_jiggleBoneState.m_Memory.m_pMemory;
                  *(_DWORD *)&v72->m_jiggleBoneState.m_Head = -1;
                  v72->m_jiggleBoneState.m_NumAlloced = 0;
                  v72->m_jiggleBoneState.m_pElements = m_pMemory;
                }
                else
                {
                  v72 = nullptr;
                }
                this->m_pJiggleBones = v72;
              }
              v74 = GetTickCount();
              v75 = g_prevTicksRT;
              v76 = v116;
              if ( g_prevTicksRT == 0 )
                v75 = v74;
              g_prevTicksRT = v74;
              flLength = (int)&this->m_pBoneToWorld[v116 / 0x30];
              v77 = (float)((float)(int)(v74 - v75) * 0.001) + g_timeRT;
              flRealTime = COERCE_FLOAT(&v97);
              cycle.m_pBoneSetup = (CBoneSetup *)&v97;
              m_pJiggleBones = this->m_pJiggleBones;
              g_timeRT = v77;
              CJiggleBones::BuildJiggleTransformations(
                this: m_pJiggleBones,
                boneIndex: v112,
                currenttime: v77,
                jiggleInfo: flTime,
                goalMX: &v97,
                boneMX: (matrix3x4_t *)flLength);
            }
            else
            {
              v79 = *(_DWORD *)(v113 + LODWORD(v114) + 4);
              v76 = v116;
              if ( v79 == -1 )
                ConcatTransforms(in1: &g_viewtransform, in2: &v99, out: &this->m_pBoneToWorld[v116 / 0x30]);
              else
                ConcatTransforms(in1: &this->m_pBoneToWorld[v79], in2: &v99, out: &this->m_pBoneToWorld[v116 / 0x30]);
            }
          }
          if ( mergeBones )
          {
            v82 = g_pCacheHdr;
            v83 = 0.0;
            if ( g_pCacheHdr == nullptr )
              goto LABEL_122;
            v84 = g_pCacheHdr->m_pStudioHdr;
            flTime = 0.0;
            if ( v84->numbones > 0 )
            {
              v85 = v113;
              p_m_ik = 0;
              do
              {
                v86 = (const char *)(*(_DWORD *)LODWORD(flRealTime)
                                   + v85
                                   + *(_DWORD *)(*(_DWORD *)LODWORD(flRealTime) + 160));
                v87 = _V_stricmp(
                        s1: &v86[*(_DWORD *)v86],
                        s2: (const char *)v84
                      + p_m_ik
                      + v84->boneindex
                      + *(int *)((char *)&v84->id + p_m_ik + v84->boneindex));
                v82 = g_pCacheHdr;
                v88 = v87 == 0;
                v83 = flTime;
                if ( v88 )
                  break;
                v84 = g_pCacheHdr->m_pStudioHdr;
                p_m_ik += 216;
                LODWORD(v83) = LODWORD(flTime) + 1;
                flTime = v83;
              }
              while ( SLODWORD(v83) < v84->numbones );
            }
            if ( SLODWORD(v83) >= v82->m_pStudioHdr->numbones )
              goto LABEL_122;
            v80 = &this->m_pBoneToWorld[v116 / 0x30];
            v81 = &boneCache[LODWORD(v83)];
          }
          else
          {
            g_pCacheHdr = (CStudioHdr *)LODWORD(flRealTime);
            v80 = (matrix3x4a_t *)((char *)boneCache + v76);
            v81 = (matrix3x4a_t *)((char *)this->m_pBoneToWorld + v76);
          }
          MatrixCopy(in: v81, out: v80);
        }
      }
      else
      {
        v53 = this->m_pBoneToWorld;
        v54 = v111;
        p_m_ik = 2143289344;
        v53->m_flMatVal[0][v111 / 4u - 3] = NAN;
        v55 = this->m_pBoneToWorld;
        p_m_ik = 2143289344;
        *(float *)((char *)&v55->m_flMatVal[0][-2] + v54) = NAN;
        v56 = this->m_pBoneToWorld;
        p_m_ik = 2143289344;
        *(float *)((char *)&v56->m_flMatVal[0][-1] + v54) = NAN;
        v57 = this->m_pBoneToWorld;
        p_m_ik = 2143289344;
        *(float *)((char *)v57->m_flMatVal[0] + v54) = NAN;
        v58 = this->m_pBoneToWorld;
        p_m_ik = 2143289344;
        *(float *)((char *)&v58->m_flMatVal[0][1] + v54) = NAN;
        v59 = this->m_pBoneToWorld;
        p_m_ik = 2143289344;
        *(float *)((char *)&v59->m_flMatVal[0][2] + v54) = NAN;
        v60 = this->m_pBoneToWorld;
        p_m_ik = 2143289344;
        *(float *)((char *)&v60->m_flMatVal[0][3] + v54) = NAN;
        v61 = this->m_pBoneToWorld;
        p_m_ik = 2143289344;
        *(float *)((char *)v61->m_flMatVal[1] + v54) = NAN;
        v62 = this->m_pBoneToWorld;
        p_m_ik = 2143289344;
        *(float *)((char *)&v62->m_flMatVal[1][1] + v54) = NAN;
        v63 = this->m_pBoneToWorld;
        p_m_ik = 2143289344;
        *(float *)((char *)&v63->m_flMatVal[1][2] + v54) = NAN;
        *(float *)((char *)&this->m_pBoneToWorld->m_flMatVal[1][3] + v54) = NAN;
        p_m_ik = 2143289344;
        *(float *)((char *)this->m_pBoneToWorld->m_flMatVal[2] + v54) = NAN;
      }
LABEL_122:
      ++v115;
      flLength += 12;
      v113 += 216;
      v111 += 48;
      v116 += 48;
      v51 = *(_DWORD *)LODWORD(flRealTime);
      ++v112;
    }
    while ( v112 < *(_DWORD *)(v51 + 156) );
  }
  flLength = (int)&g_mCachedViewTransform;
  if ( mergeBones )
  {
    Studio_RunBoneFlexDrivers(
      pflFlexControllerWeights: this->m_flexweight,
      pStudioHdr: (const CStudioHdr *)LODWORD(flRealTime),
      pvPositions: pos,
      pBoneToWorld: this->m_pBoneToWorld,
      mRootToWorld: (const matrix3x4_t *)flLength);
  }
  else
  {
    MatrixCopy(in: &g_viewtransform, out: (matrix3x4_t *)flLength);
    Studio_RunBoneFlexDrivers(
      pflFlexControllerWeights: this->m_flexweight,
      pStudioHdr: (const CStudioHdr *)LODWORD(flRealTime),
      pvPositions: pos,
      pBoneToWorld: this->m_pBoneToWorld,
      mRootToWorld: &g_viewtransform);
  }
  v89 = v93.m_ikLock.m_Memory.m_pMemory;
  v93.m_ikLock.m_Size = 0;
  if ( v93.m_ikLock.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v93.m_ikLock.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v93.m_ikLock.m_Memory.m_pMemory);
      v89 = nullptr;
      v93.m_ikLock.m_Memory.m_pMemory = nullptr;
    }
    v93.m_ikLock.m_Memory.m_nAllocationCount = 0;
  }
  v93.m_ikLock.m_pElements = v89;
  if ( v93.m_ikLock.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v89 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v89);
      v93.m_ikLock.m_Memory.m_pMemory = nullptr;
    }
    v93.m_ikLock.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&v93.m_ikChainRule);
  v90 = v93.m_ikChainRule.m_Memory.m_pMemory;
  if ( v93.m_ikChainRule.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v93.m_ikChainRule.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v93.m_ikChainRule.m_Memory.m_pMemory);
      v90 = nullptr;
      v93.m_ikChainRule.m_Memory.m_pMemory = nullptr;
    }
    v93.m_ikChainRule.m_Memory.m_nAllocationCount = 0;
  }
  v93.m_ikChainRule.m_pElements = v90;
  if ( v93.m_ikChainRule.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v90 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v90);
      v93.m_ikChainRule.m_Memory.m_pMemory = nullptr;
    }
    v93.m_ikChainRule.m_Memory.m_nAllocationCount = 0;
  }
  IBoneSetup::~IBoneSetup(this: &cycle);
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0041FAB0
// Name: float GetRealtimeTime(void)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GetRealtimeTime()
{
  DWORD TickCount; // eax
  int v1; // ecx
  double result; // st7

  TickCount = GetTickCount();
  v1 = g_prevTicksRT;
  if ( g_prevTicksRT == 0 )
    v1 = TickCount;
  g_prevTicksRT = TickCount;
  result = (double)(int)(TickCount - v1) * 0.001 + g_timeRT;
  g_timeRT = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041FAF0
// Name: public: virtual void StudioModel::AdvanceFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::AdvanceFrame(StudioModel *this, float dt)
{
  float v2; // xmm0_4
  double Duration; // st7
  float v5; // xmm0_4
  float v6; // xmm0_4
  AnimationLayer *m_Layer; // esi
  int i; // ebx
  double v9; // st7
  float v10; // xmm0_4
  float v11; // xmm0_4
  float t; // [esp+0h] [ebp-4h]
  float ta; // [esp+0h] [ebp-4h]

  v2 = dt;
  if ( dt > 0.1 )
  {
    v2 = 0.1;
    dt = 0.1;
  }
  this->m_dt = v2;
  Duration = StudioModel::GetDuration(this);
  if ( Duration <= 0.0 )
  {
    v6 = 0.0;
    goto LABEL_7;
  }
  if ( dt > 0.0 )
  {
    t = Duration;
    v5 = (float)(dt / t) + this->m_cycle;
    this->m_sequencetime = dt + this->m_sequencetime;
    v6 = v5 - (float)(int)v5;
LABEL_7:
    this->m_cycle = v6;
  }
  m_Layer = this->m_Layer;
  for ( i = 8; i != 0; --i )
  {
    v9 = StudioModel::GetDuration(this, iSequence: m_Layer->m_sequence);
    if ( v9 <= 0.0 )
    {
      v11 = 0.0;
    }
    else
    {
      if ( dt <= 0.0 )
        goto LABEL_14;
      ta = v9;
      v10 = (float)((float)(dt / ta) * m_Layer->m_playbackrate) + m_Layer->m_cycle;
      v11 = v10 - (float)(int)v10;
    }
    m_Layer->m_cycle = v11;
LABEL_14:
    ++m_Layer;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FBF0
// Name: public: float StudioModel::GetCycle(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::GetCycle(StudioModel *this)
{
  return this->m_cycle;
}

//------------------------------------------------------------------------------
// Address: 0x0041FC00
// Name: public: int StudioModel::GetMaxFrame(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::GetMaxFrame(StudioModel *this)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v3; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
  }
  return Studio_MaxFrame(pStudioHdr: m_pStudioHdr, iSequence: this->m_sequence, poseParameter: this->m_poseparameter);
}

//------------------------------------------------------------------------------
// Address: 0x0041FC60
// Name: public: int StudioModel::SetFrame(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::SetFrame(StudioModel *this, int frame)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  int result; // eax
  int v6; // edi
  float v7; // xmm1_4

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return 0;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  v6 = frame;
  if ( frame <= 0 )
    v6 = 0;
  result = StudioModel::GetMaxFrame(this);
  if ( v6 < result )
  {
    v7 = (float)result;
    this->m_cycle = (float)v6 / v7;
    return v6;
  }
  else
  {
    this->m_cycle = 0.99998999;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041FD00
// Name: public: float StudioModel::GetCycle(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::GetCycle(StudioModel *this, int iLayer)
{
  if ( iLayer == 0 )
    return this->m_cycle;
  if ( iLayer > 8 )
    return 0.0;
  return *(&this->m_blendtime + 5 * iLayer);
}

//------------------------------------------------------------------------------
// Address: 0x0041FD30
// Name: public: int StudioModel::GetMaxFrame(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::GetMaxFrame(StudioModel *this, int iLayer)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return 0;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( iLayer == 0 )
    return Studio_MaxFrame(pStudioHdr: m_pStudioHdr, iSequence: this->m_sequence, poseParameter: this->m_poseparameter);
  if ( iLayer <= 8 )
    return Studio_MaxFrame(
             pStudioHdr: m_pStudioHdr,
             iSequence: *((_DWORD *)&this->m_sequencetime + 5 * iLayer),
             poseParameter: this->m_poseparameter);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041FDC0
// Name: public: int StudioModel::SetFrame(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::SetFrame(StudioModel *this, int iLayer, int frame)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  int v7; // ebx
  int MaxFrame; // eax
  float v9; // xmm0_4

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      return 0;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  v7 = frame;
  if ( frame <= 0 )
    v7 = 0;
  MaxFrame = StudioModel::GetMaxFrame(this, iLayer);
  v9 = 0.0;
  if ( MaxFrame != 0 )
  {
    if ( v7 >= MaxFrame )
      v7 = MaxFrame;
    v9 = (float)v7 / (float)MaxFrame;
  }
  if ( iLayer != 0 )
  {
    if ( iLayer <= 8 )
      *(&this->m_blendtime + 5 * iLayer) = v9;
    return v7;
  }
  else
  {
    this->m_cycle = v9;
    return v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FE70
// Name: public: void StudioModel::Physics_SetPreview(int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::Physics_SetPreview(StudioModel *this, int previewBone, int axis, float t)
{
  this->m_physPreviewBone = previewBone;
  this->m_physPreviewAxis = axis;
  this->m_physPreviewParam = t;
}

//------------------------------------------------------------------------------
// Address: 0x0041FEA0
// Name: public: virtual int StudioModel::BoneMask(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::BoneMask(StudioModel *this)
{
  int v1; // esi

  v1 = 1024 << (g_viewerSettings.autoLOD ? 0 : LOBYTE(g_viewerSettings.lod));
  if ( g_viewerSettings.showAttachments
    || g_viewerSettings.m_iEditAttachment != -1
    || this->m_nSolveHeadTurn != 0
    || StudioModel::LookupAttachment(this, szName: "eyes") != -1 )
  {
    v1 |= 0x200u;
  }
  if ( g_viewerSettings.highlightBone >= 0 )
    v1 |= 0x7FF00u;
  if ( g_viewerSettings.showHitBoxes )
    v1 |= 0x100u;
  return v1 | 0x40000;
}

//------------------------------------------------------------------------------
// Address: 0x0041FF20
// Name: private: void StudioModel::SetupLighting(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall StudioModel::SetupLighting(StudioModel *this@<ecx>, int a2@<esi>)
{
  int v2; // esi
  int v3; // edi
  LightDesc_t light[2]; // [esp+0h] [ebp-B0h] BYREF

  light[0].m_Attenuation0 = 1.0;
  light[0].m_Attenuation1 = 0.0;
  light[0].m_Attenuation2 = 0.0;
  light[0].m_Color = *(Vector *)g_viewerSettings.lColor;
  light[0].m_Type = MATERIAL_LIGHT_DIRECTIONAL;
  light[0].m_Range = 2000.0;
  AngleVectors(angles: &g_viewerSettings.lightrot, forward: &light[0].m_Direction, right: nullptr, up: nullptr);
  ((void (__thiscall *)(IStudioRender *, int, LightDesc_t *, int))g_pStudioRender->SetLocalLights)(
    a1: g_pStudioRender,
    a2: 1,
    a3: light,
    a4: a2);
  v2 = 0;
  if ( ((int (__thiscall *)(IStudioRender *, LightType_t, _DWORD, _DWORD, _DWORD))g_pStudioRender->GetNumAmbientLightSamples)(
         a1: g_pStudioRender,
         a2: light[0].m_Type,
         a3: LODWORD(light[0].m_Color.x),
         a4: LODWORD(light[0].m_Color.y),
         a5: LODWORD(light[0].m_Color.z)) > 0 )
  {
    v3 = 0;
    do
    {
      StudioModel::m_AmbientLightColors[v3] = *(Vector *)g_viewerSettings.aColor;
      ++v2;
      ++v3;
    }
    while ( v2 < g_pStudioRender->GetNumAmbientLightSamples(this: g_pStudioRender) );
  }
  g_pStudioRender->SetAmbientLightColors(this: g_pStudioRender, a2: StudioModel::m_AmbientLightColors);
}

//------------------------------------------------------------------------------
// Address: 0x00420030
// Name: int FindBoneIndex(class CStudioHdr __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindBoneIndex(CStudioHdr *pstudiohdr, const char *pName)
{
  int v2; // edi
  const char *v3; // esi

  v2 = 0;
  v3 = (char *)pstudiohdr->m_pStudioHdr + pstudiohdr->m_pStudioHdr->boneindex;
  if ( pstudiohdr->m_pStudioHdr->numbones <= 0 )
    return -1;
  while ( _V_stricmp(s1: pName, s2: &v3[*(_DWORD *)v3]) != 0 )
  {
    ++v2;
    v3 += 216;
    if ( v2 >= pstudiohdr->m_pStudioHdr->numbones )
      return -1;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00420090
// Name: public: int StudioModel::FindBone(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::FindBone(StudioModel *this, const char *pName)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
  }
  return FindBoneIndex(pstudiohdr: m_pStudioHdr, pName);
}

//------------------------------------------------------------------------------
// Address: 0x004200E0
// Name: private: virtual void StudioModel::SetupModel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::SetupModel(StudioModel *this, int bodypart)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  const studiohdr_t *v5; // eax
  int v6; // edx
  _DWORD *v7; // ecx
  bool v8; // zf
  mstudiomodel_t *v9; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
  }
  v5 = m_pStudioHdr->m_pStudioHdr;
  v6 = bodypart;
  if ( bodypart > v5->numbodyparts )
    v6 = 0;
  v7 = (int *)((char *)&v5->id + 16 * v6 + v5->bodypartindex);
  v8 = first == 0;
  v9 = (mstudiomodel_t *)((char *)&v7[37 * (this->m_bodynum / v7[2] % v7[1])] + v7[3]);
  this->m_pmodel = v9;
  if ( !v8 )
  {
    maxNumVertices = v9->numvertices;
    first = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420180
// Name: public: static void StudioModel::UpdateStudioRenderConfig(bool,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StudioModel::UpdateStudioRenderConfig(
        bool bWireframe,
        bool bZBufferWireframe,
        bool bNormals,
        bool bTangentFrame)
{
  char v4; // al
  MaterialSystem_Config_t matSysConfig; // [esp+Ch] [ebp-9Ch] BYREF
  StudioRenderConfig_t config; // [esp+70h] [ebp-38h] BYREF

  memset(dst: (unsigned __int8 *)&config, value: 0, count: sizeof(config));
  memset((void *)&config, 0, 16);
  config.drawEntities = 1;
  config.skin = 0;
  config.fullbright = 0;
  if ( g_viewerSettings.renderMode == 0
    || g_viewerSettings.softwareSkin
    || (((bWireframe << 7) | *((_BYTE *)&config + 36) & 0x7E) & 0x80u) != 0
    || bNormals
    || bTangentFrame )
  {
    v4 = (bWireframe << 7) | *((_BYTE *)&config + 36) & 0x7E | 3;
  }
  else
  {
    v4 = (bWireframe << 7) | *((_BYTE *)&config + 36) & 0x7C | 1;
  }
  *((_BYTE *)&config + 36) = v4 & 0x83 | 0x70;
  *((_BYTE *)&config + 37) = bNormals
                           | *((_BYTE *)&config + 37) & 0xE0
                           | (2 * (bTangentFrame | (2 * bZBufferWireframe)));
  g_pStudioRender->UpdateConfig(this: g_pStudioRender, a2: &config);
  matSysConfig = *g_pMaterialSystem->GetCurrentConfigForVideoCard(this: g_pMaterialSystem);
  InitMaterialSystemConfig();
  matSysConfig.nFullbright = 0;
  if ( g_viewerSettings.renderMode == 1 )
    matSysConfig.nFullbright = 2;
  if ( g_dxlevel != 0 )
    matSysConfig.dxSupportLevel = g_dxlevel;
  g_pMaterialSystem->OverrideConfig(this: g_pMaterialSystem, a2: &matSysConfig, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x004202A0
// Name: public: float StudioModel::SetHeadPosition(struct matrix3x4_t __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
double __userpurge StudioModel::SetHeadPosition@<st0>(
        StudioModel *this@<ecx>,
        float a2@<ebp>,
        matrix3x4_t *attToWorld,
        const Vector *vTargetPos,
        float dt)
{
  int v6; // edi
  double FlexController; // st7
  int v8; // edi
  double v9; // st7
  int v10; // edi
  double v11; // st7
  float flValue; // [esp+0h] [ebp-DCh]
  float flValuea; // [esp+0h] [ebp-DCh]
  float flValueb; // [esp+0h] [ebp-DCh]
  float z; // [esp+4h] [ebp-D8h]
  float v17; // [esp+4h] [ebp-D8h]
  float v18; // [esp+4h] [ebp-D8h]
  float y; // [esp+8h] [ebp-D4h]
  float v20; // [esp+8h] [ebp-D4h]
  float v21; // [esp+8h] [ebp-D4h]
  _BYTE v22[12]; // [esp+20h] [ebp-BCh] BYREF
  matrix3x4_t headXform; // [esp+2Ch] [ebp-B0h] BYREF
  _BYTE invAttToWorld_36[60]; // [esp+80h] [ebp-5Ch] OVERLAPPED BYREF
  float v25; // [esp+BCh] [ebp-20h]
  float v26; // [esp+C0h] [ebp-1Ch]
  QAngle vEyeAngles; // [esp+C4h] [ebp-18h] BYREF
  float flDiff; // [esp+D0h] [ebp-Ch]
  float flMax; // [esp+D4h] [ebp-8h]
  float retaddr; // [esp+DCh] [ebp+0h]

  flDiff = a2;
  flMax = retaddr;
  *(matrix3x4_t *)invAttToWorld_36 = *attToWorld;
  Studio_AlignIKMatrix(mMat: (matrix3x4a_t *)invAttToWorld_36, vAlignTo: vTargetPos);
  MatrixInvert(in: attToWorld, out: (matrix3x4_t *)&headXform.m_flMatVal[2][1]);
  ConcatTransforms(
    in1: (matrix3x4_t *)&headXform.m_flMatVal[2][1],
    in2: (const matrix3x4_t *)invAttToWorld_36,
    out: (matrix3x4_t *)v22);
  MatrixAngles(matrix: (const matrix3x4_t *)v22, angles: (float *)&invAttToWorld_36[56]);
  v6 = StudioModel::LookupPoseParameter(this, szName: "head_yaw");
  StudioModel::GetPoseParameterRange(this, iParameter: v6, pflMin: &vEyeAngles.z, pflMax: &vEyeAngles.y);
  y = vEyeAngles.y;
  z = vEyeAngles.z;
  FlexController = StudioModel::GetFlexController(this, szName: "head_rightleft");
  flValue = FlexController + v25;
  vEyeAngles.x = RangeCompressor(flValue, flMin: z, flMax: y, flBase: 0.0);
  StudioModel::SetPoseParameter(this, iParameter: v6, flValue: vEyeAngles.x);
  v8 = StudioModel::LookupPoseParameter(this, szName: "head_pitch");
  StudioModel::GetPoseParameterRange(this, iParameter: v8, pflMin: &vEyeAngles.z, pflMax: &vEyeAngles.y);
  v20 = vEyeAngles.y;
  v17 = vEyeAngles.z;
  v9 = StudioModel::GetFlexController(this, szName: "head_updown");
  flValuea = v9 + *(float *)&invAttToWorld_36[56];
  vEyeAngles.x = RangeCompressor(flValue: flValuea, flMin: v17, flMax: v20, flBase: 0.0);
  StudioModel::SetPoseParameter(this, iParameter: v8, flValue: vEyeAngles.x);
  v10 = StudioModel::LookupPoseParameter(this, szName: "head_roll");
  StudioModel::GetPoseParameterRange(this, iParameter: v10, pflMin: &vEyeAngles.z, pflMax: &vEyeAngles.y);
  v21 = vEyeAngles.y;
  v18 = vEyeAngles.z;
  v11 = StudioModel::GetFlexController(this, szName: "head_tilt");
  flValueb = v11 + v26;
  vEyeAngles.x = RangeCompressor(flValue: flValueb, flMin: v18, flMax: v21, flBase: 0.0);
  StudioModel::SetPoseParameter(this, iParameter: v10, flValue: vEyeAngles.x);
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004204A0
// Name: public: void StudioModel::GetModelTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::GetModelTransform(StudioModel *this, matrix3x4_t *mat)
{
  Vector vecModelOrigin; // [esp+8h] [ebp-Ch] BYREF

  AngleMatrix(angles: &this->m_angles, matrix: mat);
  vecModelOrigin.x = this->m_origin.x * -1.0;
  vecModelOrigin.y = this->m_origin.y * -1.0;
  vecModelOrigin.z = this->m_origin.z * -1.0;
  MatrixSetColumn(in: &vecModelOrigin, column: 3, out: mat);
}

//------------------------------------------------------------------------------
// Address: 0x00420500
// Name: public: void StudioModel::SetModelTransform(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::SetModelTransform(StudioModel *this, const matrix3x4_t *mat)
{
  this->m_origin.x = -mat->m_flMatVal[0][3];
  this->m_origin.y = -mat->m_flMatVal[1][3];
  this->m_origin.z = -mat->m_flMatVal[2][3];
  MatrixAngles(matrix: mat, angles: &this->m_angles.x);
}

//------------------------------------------------------------------------------
// Address: 0x00420550
// Name: void RandomColor(float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RandomColor(float *color, unsigned __int8 key)
{
  int *v2; // esi
  int v3; // edi
  int v4; // ebx
  int v5; // eax
  unsigned int v6; // eax

  if ( first_0 )
  {
    first_0 = false;
    v2 = dword_7C7274;
    do
    {
      do
      {
        v3 = (unsigned __int8)rand();
        v4 = (unsigned __int8)rand();
        v5 = (unsigned __int8)rand();
      }
      while ( v3 + v5 + v4 < 256 );
      *(v2 - 1) = v3;
      *v2 = v4;
      v2[1] = v5;
      v2[2] = 255;
      v2 += 4;
    }
    while ( (int)v2 < (int)dword_7C8274 );
  }
  v6 = 4 * key;
  *color = (double)colors[v6 / 4].r * 0.0039215689;
  color[1] = (double)(unsigned int)dword_7C7274[v6] * 0.0039215689;
  color[2] = (double)(unsigned int)dword_7C7278[v6] * 0.0039215689;
  color[3] = 0.0039215689 * (double)(unsigned int)dword_7C727C[v6];
}

//------------------------------------------------------------------------------
// Address: 0x00420650
// Name: public: void StudioModel::ExtractVertExtents(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::ExtractVertExtents(StudioModel *this, Vector *vecMin, Vector *vecMax)
{
  if ( ((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle) != 0 )
  {
    this->SetUpBones(this, a2: false);
    DebugModelVertExtents(
      pStudioRender: g_pStudioRender,
      info: &g_DrawModelInfo,
      pBoneToWorld: this->m_pBoneToWorld,
      vecMin,
      vecMax);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004206B0
// Name: public: int StudioModel::GetLodUsed(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::GetLodUsed(StudioModel *this)
{
  return this->m_LodUsed;
}

//------------------------------------------------------------------------------
// Address: 0x004206C0
// Name: public: float StudioModel::GetLodMetric(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::GetLodMetric(StudioModel *this)
{
  return this->m_LodMetric;
}

//------------------------------------------------------------------------------
// Address: 0x004206D0
// Name: public: void StudioModel::SetSolveHeadTurn(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::SetSolveHeadTurn(StudioModel *this, int solve)
{
  this->m_nSolveHeadTurn = solve;
}

//------------------------------------------------------------------------------
// Address: 0x004206E0
// Name: public: int StudioModel::GetSolveHeadTurn(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::GetSolveHeadTurn(StudioModel *this)
{
  return this->m_nSolveHeadTurn;
}

//------------------------------------------------------------------------------
// Address: 0x004206F0
// Name: public: int StudioModel::GetNumIncludeModels(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall StudioModel::GetNumIncludeModels(StudioModel *this)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v3; // eax
  CStudioHdr *v4; // esi
  const studiohdr_t *v6; // eax

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
    v4 = this->m_pStudioHdr;
    if ( v4->m_pStudioHdr == nullptr )
      return 0;
    m_pStudioHdr = v4;
  }
  if ( m_pStudioHdr == nullptr )
    return 0;
  v6 = m_pStudioHdr->m_pStudioHdr;
  if ( v6 == nullptr )
    return 0;
  return v6->numincludemodels;
}

//------------------------------------------------------------------------------
// Address: 0x00420740
// Name: public: char const __near * StudioModel::GetIncludeModelName(int)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall StudioModel::GetIncludeModelName(StudioModel *this, int index)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  const studiohdr_t *v6; // eax
  char *v7; // ecx

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return (char *)WindowName;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    v5 = this->m_pStudioHdr;
    if ( v5->m_pStudioHdr == nullptr )
      return (char *)WindowName;
    m_pStudioHdr = v5;
  }
  if ( m_pStudioHdr != nullptr )
  {
    v6 = m_pStudioHdr->m_pStudioHdr;
    if ( v6 != nullptr && index >= 0 && index <= v6->numincludemodels )
    {
      v7 = (char *)v6 + 8 * index + v6->includemodelindex;
      if ( v7 != nullptr )
        return &v7[*((_DWORD *)v7 + 1)];
    }
  }
  return (char *)WindowName;
}

//------------------------------------------------------------------------------
// Address: 0x004207C0
// Name: public: float StudioModel::GetFrame(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall StudioModel::GetFrame(StudioModel *this, int iLayer)
{
  float m_cycle; // xmm0_4

  if ( iLayer != 0 )
  {
    if ( iLayer > 8 )
      m_cycle = 0.0;
    else
      m_cycle = *(&this->m_blendtime + 5 * iLayer);
  }
  else
  {
    m_cycle = this->m_cycle;
  }
  return (double)StudioModel::GetMaxFrame(this, iLayer) * m_cycle;
}

//------------------------------------------------------------------------------
// Address: 0x00420810
// Name: public: void StudioModel::OverrideBones(bool __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge StudioModel::OverrideBones(StudioModel *this@<ecx>, int a2@<esi>, bool *override)
{
  IStudioPhysics *m_pPhysics; // ecx
  int (__thiscall *Count)(IStudioPhysics *); // eax
  matrix3x4_t *v6; // eax
  CStudioHdr *m_pStudioHdr; // edi
  matrix3x4_t *v8; // ebx
  const studiohdr_t *v9; // eax
  int v10; // ecx
  bool v11; // cc
  const char *v12; // ebx
  const studiohdr_t *v13; // edx
  int v14; // edi
  CPhysmesh *v15; // edi
  CStudioHdr *v16; // eax
  const studiohdr_t *v17; // eax
  int BoneIndex; // eax
  int m_physPreviewAxis; // ecx
  int v20; // eax
  int v21; // ecx
  IStudioPhysics *v22; // ecx
  int (__thiscall *v23)(IStudioPhysics *); // edx
  int v24; // edi
  matrix3x4_t tmpmatrix; // [esp+0h] [ebp-B4h] BYREF
  matrix3x4_t basematrix; // [esp+30h] [ebp-84h] BYREF
  matrix3x4_t bonematrix; // [esp+60h] [ebp-54h] BYREF
  QAngle tmp; // [esp+90h] [ebp-24h] BYREF
  QAngle rot; // [esp+9Ch] [ebp-18h] BYREF
  int i; // [esp+A8h] [ebp-Ch]
  matrix3x4_t *parentMatrix; // [esp+ACh] [ebp-8h]
  int v33; // [esp+B0h] [ebp-4h]

  tmp.x = 0.0;
  tmp.y = 90.0;
  tmp.z = 0.0;
  AngleMatrix(angles: &tmp, matrix: &bonematrix);
  ConcatTransforms(in1: &g_viewtransform, in2: &bonematrix, out: &basematrix);
  m_pPhysics = this->m_pPhysics;
  Count = m_pPhysics->Count;
  i = 0;
  if ( ((int (__thiscall *)(IStudioPhysics *, int))Count)(a1: m_pPhysics, a2) > 0 )
  {
    do
    {
      v6 = (matrix3x4_t *)this->m_pPhysics->GetMesh(this: this->m_pPhysics, a2: i);
      m_pStudioHdr = this->m_pStudioHdr;
      v8 = v6;
      parentMatrix = v6;
      if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
      {
        v9 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
        CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v9, mdlcache: nullptr);
        m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
      }
      v10 = (int)m_pStudioHdr->m_pStudioHdr + m_pStudioHdr->m_pStudioHdr->boneindex;
      v11 = m_pStudioHdr->m_pStudioHdr->numbones <= 0;
      v33 = 0;
      if ( v11 )
      {
LABEL_10:
        v33 = -1;
        v14 = -1;
      }
      else
      {
        v12 = (const char *)v10;
        while ( _V_stricmp(s1: (const char *)parentMatrix, s2: &v12[*(_DWORD *)v12]) != 0 )
        {
          v13 = m_pStudioHdr->m_pStudioHdr;
          v12 += 216;
          if ( ++v33 >= v13->numbones )
          {
            v8 = parentMatrix;
            goto LABEL_10;
          }
        }
        v14 = v33;
        v8 = parentMatrix;
      }
      if ( (LODWORD(v8[38].m_flMatVal[1][2]) != 0 || LODWORD(v8[38].m_flMatVal[1][3]) != 0) && v14 >= 0 )
      {
        parentMatrix = &basematrix;
        override[v14] = true;
        if ( v8[38].m_flMatVal[1][2] >= 0.0 )
        {
          v15 = this->m_pPhysics->GetMesh(this: this->m_pPhysics, a2: LODWORD(v8[38].m_flMatVal[1][2]));
          v16 = this->m_pStudioHdr;
          if ( v16 != nullptr && v16->m_pStudioHdr == nullptr )
          {
            v17 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
            CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v17, mdlcache: nullptr);
            v16 = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
          }
          BoneIndex = FindBoneIndex(pstudiohdr: v16, pName: v15->m_boneName);
          v14 = v33;
          if ( BoneIndex >= 0 )
            parentMatrix = &this->m_pBoneToWorld[BoneIndex];
        }
        if ( this->m_physPreviewBone == i )
        {
          m_physPreviewAxis = this->m_physPreviewAxis;
          v20 = m_physPreviewAxis + 116;
          if ( m_physPreviewAxis != 0 )
            v21 = m_physPreviewAxis == 2;
          else
            v21 = 2;
          memset(&rot, 0, sizeof(rot));
          *(&rot.x + v21) = (float)((float)(v8->m_flMatVal[v20][1] - v8->m_flMatVal[v20][0]) * this->m_physPreviewParam)
                          + v8->m_flMatVal[v20][0];
          AngleMatrix(angles: &rot, matrix: &tmpmatrix);
          ConcatTransforms(in1: (matrix3x4_t *)((char *)v8 + 72), in2: &tmpmatrix, out: &bonematrix);
        }
        else
        {
          MatrixCopy(in: (matrix3x4_t *)((char *)v8 + 72), out: &bonematrix);
        }
        ConcatTransforms(in1: parentMatrix, in2: &bonematrix, out: &this->m_pBoneToWorld[v14]);
      }
      v22 = this->m_pPhysics;
      v23 = v22->Count;
      v24 = ++i;
    }
    while ( v24 < v23(this: v22) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420AC0
// Name: public: void StudioModel::GetBodyPoseParametersFromFlex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::GetBodyPoseParametersFromFlex(StudioModel *this)
{
  float flGoal; // [esp+8h] [ebp-4h]
  float flGoala; // [esp+8h] [ebp-4h]
  float flGoalb; // [esp+8h] [ebp-4h]
  float flGoalc; // [esp+8h] [ebp-4h]
  float flGoald; // [esp+8h] [ebp-4h]
  float flGoale; // [esp+8h] [ebp-4h]
  float flGoalf; // [esp+8h] [ebp-4h]
  float flGoalg; // [esp+8h] [ebp-4h]
  float flGoalh; // [esp+8h] [ebp-4h]
  float flGoali; // [esp+8h] [ebp-4h]
  float flGoalj; // [esp+8h] [ebp-4h]
  float flGoalk; // [esp+8h] [ebp-4h]
  float flGoall; // [esp+8h] [ebp-4h]
  float flGoalm; // [esp+8h] [ebp-4h]

  flGoal = StudioModel::GetFlexController(this, szName: "move_rightleft");
  StudioModel::SetPoseParameter(this, szName: "body_trans_Y", flValue: flGoal);
  flGoala = StudioModel::GetFlexController(this, szName: "move_forwardback");
  StudioModel::SetPoseParameter(this, szName: "body_trans_X", flValue: flGoala);
  flGoalb = StudioModel::GetFlexController(this, szName: "move_updown");
  StudioModel::SetPoseParameter(this, szName: "body_lift", flValue: flGoalb);
  flGoalc = this->m_flBodyYaw;
  flGoald = StudioModel::GetFlexController(this, szName: "body_rightleft") + flGoalc;
  StudioModel::SetPoseParameter(this, szName: "body_yaw", flValue: flGoald);
  flGoale = StudioModel::GetFlexController(this, szName: "body_updown");
  StudioModel::SetPoseParameter(this, szName: "body_pitch", flValue: flGoale);
  flGoalf = StudioModel::GetFlexController(this, szName: "body_tilt");
  StudioModel::SetPoseParameter(this, szName: "body_roll", flValue: flGoalf);
  flGoalg = this->m_flSpineYaw;
  flGoalh = StudioModel::GetFlexController(this, szName: "chest_rightleft") + flGoalg;
  StudioModel::SetPoseParameter(this, szName: "spine_yaw", flValue: flGoalh);
  flGoali = StudioModel::GetFlexController(this, szName: "chest_updown");
  StudioModel::SetPoseParameter(this, szName: "spine_pitch", flValue: flGoali);
  flGoalj = StudioModel::GetFlexController(this, szName: "chest_tilt");
  StudioModel::SetPoseParameter(this, szName: "spine_roll", flValue: flGoalj);
  flGoalk = StudioModel::GetFlexController(this, szName: "head_forwardback");
  StudioModel::SetPoseParameter(this, szName: "neck_trans", flValue: flGoalk);
  flGoall = StudioModel::GetFlexController(this, szName: "gesture_updown");
  StudioModel::SetPoseParameter(this, szName: "gesture_height", flValue: flGoall);
  flGoalm = StudioModel::GetFlexController(this, szName: "gesture_rightleft");
  StudioModel::SetPoseParameter(this, szName: "gesture_width", flValue: flGoalm);
}

//------------------------------------------------------------------------------
// Address: 0x00420D70
// Name: public: void StudioModel::drawBox(class Vector const __near *,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge StudioModel::drawBox(StudioModel *this@<ecx>, int a2@<ebx>, const Vector *v, const float *color)
{
  IMatRenderContext *v4; // esi
  int v5; // edi
  IMesh *v6; // esi
  float *m_pCurrPosition; // ecx
  const Vector *v9; // eax
  int m_nVertexCount; // eax
  float *m_pPosition; // ecx
  double x; // st7
  int v13; // eax
  IMesh *v14; // esi
  float *v15; // ecx
  double v17; // st7
  int v18; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1FCh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-14h]
  IMesh *pMesh; // [esp+1F4h] [ebp-10h]
  float v23; // [esp+1F8h] [ebp-Ch]
  float v24; // [esp+1FCh] [ebp-8h]
  float v25; // [esp+200h] [ebp-4h]
  float va; // [esp+20Ch] [ebp+8h]
  float vb; // [esp+20Ch] [ebp+8h]
  float vc; // [esp+20Ch] [ebp+8h]
  float vd; // [esp+20Ch] [ebp+8h]
  float colora; // [esp+210h] [ebp+Ch]
  float colorb; // [esp+210h] [ebp+Ch]
  float colorc; // [esp+210h] [ebp+Ch]
  float colord; // [esp+210h] [ebp+Ch]
  float colore; // [esp+210h] [ebp+Ch]
  float colorf; // [esp+210h] [ebp+Ch]
  float colorg; // [esp+210h] [ebp+Ch]
  float colorh; // [esp+210h] [ebp+Ch]
  float colori; // [esp+210h] [ebp+Ch]

  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v5 = 0;
  pRenderContext.m_pObject = v4;
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v6 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int))v4->GetDynamicMesh)(
                  a1: v4,
                  a2: 1,
                  a3: 0,
                  a4: 0,
                  a5: 0,
                  a6: a2);
  pMesh = v6;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v6;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLE_STRIP;
  v6->SetPrimitiveType(this: v6, a2: MATERIAL_TRIANGLE_STRIP);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 10, a3: 10, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v6->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 10;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v6, nMaxVertexCount: 10, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  do
  {
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v9 = &v[v5 & 7];
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = v9->x;
    m_pCurrPosition[1] = v9->y;
    m_pCurrPosition[2] = v9->z;
    v24 = (float)(color[2] * 255.0) + 8388608.0;
    v25 = (float)(color[1] * 255.0) + 8388608.0;
    v23 = (float)(*color * 255.0) + 8388608.0;
    colora = (float)(color[3] * 255.0) + 8388608.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v24)
                                                        | ((LOBYTE(v25) | ((LOBYTE(v23) | (LOBYTE(colora) << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    ++v5;
  }
  while ( v5 < 10 );
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
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
  v6->Draw_2(this: v6, a2: -1, a3: 0);
  meshBuilder.m_pMesh = v6;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLE_STRIP;
  v6->SetPrimitiveType(this: v6, a2: MATERIAL_TRIANGLE_STRIP);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 4, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v6->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = v6;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 4;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 4;
  meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
  meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_bModify = false;
  if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
  {
    meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
    meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
  }
  m_pPosition = meshBuilder.m_VertexBuilder.m_pPosition;
  x = v[6].x;
  meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
  qmemcpy(
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
    meshBuilder.m_VertexBuilder.m_pTexCoord,
    sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
  meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
  meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
  *meshBuilder.m_VertexBuilder.m_pPosition = x;
  m_pPosition[1] = v[6].y;
  m_pPosition[2] = v[6].z;
  v23 = (float)(color[2] * 255.0) + 8388608.0;
  v25 = (float)(color[1] * 255.0) + 8388608.0;
  v24 = (float)(*color * 255.0) + 8388608.0;
  colorb = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v23)
                                                      | ((LOBYTE(v25) | ((LOBYTE(v24) | (LOBYTE(colorb) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = *v;
  v23 = (float)(color[2] * 255.0) + 8388608.0;
  v25 = (float)(color[1] * 255.0) + 8388608.0;
  v24 = (float)(*color * 255.0) + 8388608.0;
  colorc = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v23)
                                                      | ((LOBYTE(v25) | ((LOBYTE(v24) | (LOBYTE(colorc) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v[4];
  v23 = (float)(color[2] * 255.0) + 8388608.0;
  v25 = (float)(color[1] * 255.0) + 8388608.0;
  v24 = (float)(*color * 255.0) + 8388608.0;
  colord = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v23)
                                                      | ((LOBYTE(v25) | ((LOBYTE(v24) | (LOBYTE(colord) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v[2];
  v23 = (float)(color[2] * 255.0) + 8388608.0;
  v25 = (float)(color[1] * 255.0) + 8388608.0;
  v24 = (float)(*color * 255.0) + 8388608.0;
  colore = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v23)
                                                      | ((LOBYTE(v25) | ((LOBYTE(v24) | (LOBYTE(colore) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        v13 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        v13 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        v13 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        v13 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        v13 = 0;
        break;
      default:
        v13 = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: v13);
  }
  ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
    a1: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
  v14 = pMesh;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
  meshBuilder.m_pMesh = v14;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLE_STRIP;
  v14->SetPrimitiveType(this: v14, a2: MATERIAL_TRIANGLE_STRIP);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 4, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v14->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = v14;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 4;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 4;
  meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
  meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_bModify = false;
  if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
  {
    meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
    meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
  }
  v15 = meshBuilder.m_VertexBuilder.m_pPosition;
  v17 = v[1].x;
  meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
  qmemcpy(
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
    meshBuilder.m_VertexBuilder.m_pTexCoord,
    sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
  meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
  meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
  *meshBuilder.m_VertexBuilder.m_pPosition = v17;
  v15[1] = v[1].y;
  v15[2] = v[1].z;
  v25 = (float)(color[2] * 255.0) + 8388608.0;
  v24 = (float)(color[1] * 255.0) + 8388608.0;
  colorf = (float)(*color * 255.0) + 8388608.0;
  va = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v25)
                                                      | ((LOBYTE(v24) | ((LOBYTE(colorf) | (LOBYTE(va) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v[7];
  v25 = (float)(color[2] * 255.0) + 8388608.0;
  v24 = (float)(color[1] * 255.0) + 8388608.0;
  colorg = (float)(*color * 255.0) + 8388608.0;
  vb = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v25)
                                                      | ((LOBYTE(v24) | ((LOBYTE(colorg) | (LOBYTE(vb) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v[3];
  v25 = (float)(color[2] * 255.0) + 8388608.0;
  v24 = (float)(color[1] * 255.0) + 8388608.0;
  colorh = (float)(*color * 255.0) + 8388608.0;
  vc = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v25)
                                                      | ((LOBYTE(v24) | ((LOBYTE(colorh) | (LOBYTE(vc) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v[5];
  v25 = (float)(color[2] * 255.0) + 8388608.0;
  v24 = (float)(color[1] * 255.0) + 8388608.0;
  colori = (float)(*color * 255.0) + 8388608.0;
  vd = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v25)
                                                      | ((LOBYTE(v24) | ((LOBYTE(colori) | (LOBYTE(vd) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        v18 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        v18 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        v18 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        v18 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        v18 = 0;
        break;
      default:
        v18 = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: v18);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x00421930
// Name: public: void StudioModel::drawWireframeBox(class Vector const __near *,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge StudioModel::drawWireframeBox(
        StudioModel *this@<ecx>,
        int a2@<ebx>,
        const Vector *v,
        const float *color)
{
  IMatRenderContext *v4; // esi
  IMesh *v5; // ebx
  float *m_pCurrPosition; // ecx
  const Vector *v9; // eax
  int m_nVertexCount; // eax
  float *v11; // eax
  float *v12; // eax
  float *v13; // ecx
  float *v14; // ecx
  float *v15; // eax
  int v16; // eax
  float *v17; // eax
  float *v18; // ecx
  float *v19; // ecx
  float *v20; // ecx
  float *v21; // eax
  int v22; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1F8h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-10h]
  int i; // [esp+1F4h] [ebp-Ch]
  float v27; // [esp+1F8h] [ebp-8h]
  float v28; // [esp+1FCh] [ebp-4h]
  float va; // [esp+208h] [ebp+8h]
  float vb; // [esp+208h] [ebp+8h]
  float vc; // [esp+208h] [ebp+8h]
  float vd; // [esp+208h] [ebp+8h]
  float ve; // [esp+208h] [ebp+8h]
  float vf; // [esp+208h] [ebp+8h]
  float vg; // [esp+208h] [ebp+8h]
  float vh; // [esp+208h] [ebp+8h]
  float vi; // [esp+208h] [ebp+8h]
  float vj; // [esp+208h] [ebp+8h]
  float vk; // [esp+208h] [ebp+8h]
  float colora; // [esp+20Ch] [ebp+Ch]
  float colorb; // [esp+20Ch] [ebp+Ch]
  float colorc; // [esp+20Ch] [ebp+Ch]
  float colord; // [esp+20Ch] [ebp+Ch]
  float colore; // [esp+20Ch] [ebp+Ch]
  float colorf; // [esp+20Ch] [ebp+Ch]
  float colorg; // [esp+20Ch] [ebp+Ch]
  float colorh; // [esp+20Ch] [ebp+Ch]
  float colori; // [esp+20Ch] [ebp+Ch]
  float colorj; // [esp+20Ch] [ebp+Ch]
  float colork; // [esp+20Ch] [ebp+Ch]

  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = v4;
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v5 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int))v4->GetDynamicMesh)(
                  a1: v4,
                  a2: 1,
                  a3: 0,
                  a4: 0,
                  a5: 0,
                  a6: a2);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v5;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_LINES;
  v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 8, a3: 8, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 8;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: 8, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  for ( i = 0; i < 10; ++i )
  {
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v9 = &v[i & 7];
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = v9->x;
    m_pCurrPosition[1] = v9->y;
    m_pCurrPosition[2] = v9->z;
    v28 = (float)(color[2] * 255.0) + 8388608.0;
    v27 = (float)(color[1] * 255.0) + 8388608.0;
    va = (float)(*color * 255.0) + 8388608.0;
    colora = (float)(color[3] * 255.0) + 8388608.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v28)
                                                        | ((LOBYTE(v27) | ((LOBYTE(va) | (LOBYTE(colora) << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  }
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
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
  meshBuilder.m_pMesh = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  v5->Draw_2(this: v5, a2: -1, a3: 0);
  CMeshBuilder::Begin(this: &meshBuilder, pMesh: v5, type: 4, numPrimitives: 4);
  v11 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v[6].x;
  v11[1] = v[6].y;
  v11[2] = v[6].z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  vb = (float)(*color * 255.0) + 8388608.0;
  colorb = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(vb) | (LOBYTE(colorb) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v12 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v->x;
  v12[1] = v->y;
  v12[2] = v->z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  vc = (float)(*color * 255.0) + 8388608.0;
  colorc = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(vc) | (LOBYTE(colorc) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v13 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v[2].x;
  v13[1] = v[2].y;
  v13[2] = v[2].z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  vd = (float)(*color * 255.0) + 8388608.0;
  colord = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(vd) | (LOBYTE(colord) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v14 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v[4].x;
  v14[1] = v[4].y;
  v14[2] = v[4].z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  ve = (float)(*color * 255.0) + 8388608.0;
  colore = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(ve) | (LOBYTE(colore) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v15 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v[6].x;
  v15[1] = v[6].y;
  v15[2] = v[6].z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  vf = (float)(*color * 255.0) + 8388608.0;
  colorf = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(vf) | (LOBYTE(colorf) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        v16 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        v16 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        v16 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        v16 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        v16 = 0;
        break;
      default:
        v16 = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: v16);
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
  meshBuilder.m_pMesh = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  v5->Draw_2(this: v5, a2: -1, a3: 0);
  CMeshBuilder::Begin(this: &meshBuilder, pMesh: v5, type: 4, numPrimitives: 4);
  v17 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v[1].x;
  v17[1] = v[1].y;
  v17[2] = v[1].z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  vg = (float)(*color * 255.0) + 8388608.0;
  colorg = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(vg) | (LOBYTE(colorg) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v18 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v[7].x;
  v18[1] = v[7].y;
  v18[2] = v[7].z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  vh = (float)(*color * 255.0) + 8388608.0;
  colorh = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(vh) | (LOBYTE(colorh) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v19 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v[5].x;
  v19[1] = v[5].y;
  v19[2] = v[5].z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  vi = (float)(*color * 255.0) + 8388608.0;
  colori = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(vi) | (LOBYTE(colori) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v20 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v[3].x;
  v20[1] = v[3].y;
  v20[2] = v[3].z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  vj = (float)(*color * 255.0) + 8388608.0;
  colorj = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(vj) | (LOBYTE(colorj) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v21 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = v[1].x;
  v21[1] = v[1].y;
  v21[2] = v[1].z;
  v27 = (float)(color[2] * 255.0) + 8388608.0;
  v28 = (float)(color[1] * 255.0) + 8388608.0;
  vk = (float)(*color * 255.0) + 8388608.0;
  colork = (float)(color[3] * 255.0) + 8388608.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v27)
                                                      | ((LOBYTE(v28) | ((LOBYTE(vk) | (LOBYTE(colork) << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        v22 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        v22 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        v22 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        v22 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        v22 = 0;
        break;
      default:
        v22 = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: v22);
  }
  ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
    a1: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v5->Draw_2(this: v5, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x004223D0
// Name: public: void StudioModel::drawTransform(struct matrix3x4_t __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge StudioModel::drawTransform(
        StudioModel *this@<ecx>,
        CMeshBuilder *p_meshBuilder@<ebx>,
        int m_nIndexCount@<edi>,
        matrix3x4_t *m,
        float flLength)
{
  IMatRenderContext *v5; // esi
  IMesh *v6; // esi
  unsigned __int8 *v7; // ebx
  char v8; // cl
  int v9; // edx
  unsigned int v10; // ecx
  int v11; // edx
  float *m_pCurrPosition; // eax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float *v15; // edi
  float *v16; // eax
  float v17; // xmm0_4
  float v18; // xmm1_4
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-1F4h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1ECh] [ebp-Ch]
  IMesh *pMesh; // [esp+1F0h] [ebp-8h]
  float *v26; // [esp+1F4h] [ebp-4h]

  v5 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = v5;
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  v6 = v5->GetDynamicMesh(this: v5, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  pMesh = v6;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v26 = m->m_flMatVal[2];
  v7 = &color[0][2];
  while ( 1 )
  {
    meshBuilder.m_pMesh = v6;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    ((void (__thiscall *)(IMesh *, int, int, CMeshBuilder *))v6->SetPrimitiveType)(
      a1: v6,
      a2: 1,
      a3: m_nIndexCount,
      a4: p_meshBuilder);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 2, a3: 2, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v6->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = v6;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 2;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
    meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 2;
    meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_bModify = false;
    if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
    {
      meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
      meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
    }
    meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = meshBuilder.m_VertexBuilder.m_pTexCoord[2];
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[5] = meshBuilder.m_VertexBuilder.m_pTexCoord[5];
    v8 = *(v7 - 2);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = meshBuilder.m_VertexBuilder.m_pTexCoord[0];
    meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[3] = meshBuilder.m_VertexBuilder.m_pTexCoord[3];
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = meshBuilder.m_VertexBuilder.m_pTexCoord[1];
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[6] = meshBuilder.m_VertexBuilder.m_pTexCoord[6];
    v9 = *(v7 - 1);
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[4] = meshBuilder.m_VertexBuilder.m_pTexCoord[4];
    v10 = v9 | ((*(_DWORD *)&v8 | 0xFFFFFF00) << 8);
    v11 = *v7;
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord[7] = meshBuilder.m_VertexBuilder.m_pTexCoord[7];
    meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pColor = v11 | (v10 << 8);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v13 = m->m_flMatVal[1][3];
    v14 = m->m_flMatVal[2][3];
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = m->m_flMatVal[0][3];
    m_pCurrPosition[1] = v13;
    m_pCurrPosition[2] = v14;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v15 = v26;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *v7 | ((*(v7 - 1) | ((*(v7 - 2) | 0xFFFFFF00) << 8)) << 8);
    v16 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v17 = (float)(*(v15 - 4) * flLength) + m->m_flMatVal[1][3];
    v18 = (float)(*v15 * flLength) + m->m_flMatVal[2][3];
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(*(v15 - 8) * flLength) + m->m_flMatVal[0][3];
    v16[1] = v17;
    v16[2] = v18;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    p_meshBuilder = &meshBuilder;
    m_nIndexCount = meshBuilder.m_IndexBuilder.m_nIndexCount;
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
    v7 += 3;
    v26 = v15 + 1;
    if ( (int)v7 >= (int)&unk_5E29BF )
      break;
    v6 = pMesh;
  }
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x00422770
// Name: public: void StudioModel::drawLine(class Vector const __near &,class Vector const __near &,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge StudioModel::drawLine(
        StudioModel *this@<ecx>,
        int a2@<edi>,
        const Vector *p1,
        const Vector *p2,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b)
{
  IMatRenderContext *v7; // ebx
  IMesh *v8; // edi
  unsigned int v9; // esi
  float y; // xmm0_4
  float z; // xmm1_4
  float *m_pCurrPosition; // eax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float *v15; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1E8h] BYREF

  v7 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, int))v7->Bind)(
    a1: v7,
    a2: g_materialVertexColor,
    a3: 0,
    a4: a2);
  v8 = v7->GetDynamicMesh(this: v7, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v8;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_LINES;
  v8->SetPrimitiveType(this: v8, a2: MATERIAL_LINES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 2, a3: 2, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v8->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 2;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v8, nMaxVertexCount: 2, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  v9 = b | ((g | ((r | 0xFFFFFF00) << 8)) << 8);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v9;
  y = p1->y;
  z = p1->z;
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = p1->x;
  m_pCurrPosition[1] = y;
  m_pCurrPosition[2] = z;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v9;
  v13 = p2->y;
  v14 = p2->z;
  v15 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = p2->x;
  v15[1] = v13;
  v15[2] = v14;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
    a1: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v8->Draw_2(this: v8, a2: -1, a3: 0);
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
  v7->EndRender(this: v7);
  v7->Release(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00422A20
// Name: public: void StudioModel::drawTransparentBox(class Vector const __near &,class Vector const __near &,struct matrix3x4_t const __near &,float const __near *,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge StudioModel::drawTransparentBox(
        StudioModel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *bbmin,
        const Vector *bbmax,
        const matrix3x4_t *m,
        const float *color,
        const float *wirecolor)
{
  float x; // xmm0_4
  float y; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm4_4
  float z; // xmm2_4
  int v15; // eax
  int v16; // esi
  Vector v2[8]; // [esp+0h] [ebp-C0h] BYREF
  Vector v[8]; // [esp+60h] [ebp-60h] BYREF

  x = bbmin->x;
  y = bbmin->y;
  v12 = bbmax->y;
  v13 = bbmax->x;
  v[0].z = bbmin->z;
  v[1].z = v[0].z;
  v[2].z = v[0].z;
  v[3].z = v[0].z;
  z = bbmax->z;
  v[0].x = x;
  v[0].y = v12;
  v[1].x = x;
  v[1].y = y;
  v[2].x = v13;
  v[2].y = v12;
  v[3].x = v13;
  v[3].y = y;
  v[4].x = v13;
  v[4].y = v12;
  v[4].z = z;
  v[5].x = v13;
  v[5].y = y;
  v[5].z = z;
  v[6].x = x;
  v[6].y = v12;
  v[6].z = z;
  v[7].x = x;
  v[7].y = y;
  v[7].z = z;
  VectorTransform(in1: &v[0].x, in2: m, out: &v2[0].x);
  VectorTransform(in1: &v[1].x, in2: m, out: &v2[1].x);
  VectorTransform(in1: &v[2].x, in2: m, out: &v2[2].x);
  VectorTransform(in1: &v[3].x, in2: m, out: &v2[3].x);
  VectorTransform(in1: &v[4].x, in2: m, out: &v2[4].x);
  VectorTransform(in1: &v[5].x, in2: m, out: &v2[5].x);
  VectorTransform(in1: &v[6].x, in2: m, out: &v2[6].x);
  VectorTransform(in1: &v[7].x, in2: m, out: &v2[7].x);
  v15 = ((int (__thiscall *)(IMaterialSystem *, int, int))g_pMaterialSystem->GetRenderContext)(
          a1: g_pMaterialSystem,
          a2: a3,
          a3: a4);
  v16 = v15;
  if ( v15 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v15 + 8))(a1: v15);
  (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v16 + 36))(a1: v16, a2: g_pAlpha, a3: 0);
  StudioModel::drawBox(this, a2, v: v2, color);
  (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v16 + 36))(a1: v16, a2: g_materialBones, a3: 0);
  StudioModel::drawWireframeBox(this, a2, v: v2, color: wirecolor);
  (*(void (__thiscall **)(int))(*(_DWORD *)v16 + 12))(a1: v16);
  (*(void (__thiscall **)(int))(*(_DWORD *)v16 + 4))(a1: v16);
}

//------------------------------------------------------------------------------
// Address: 0x00422BE0
// Name: private: void StudioModel::DrawBones(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall StudioModel::DrawBones(StudioModel *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v5; // eax
  CStudioHdr *v6; // edi
  IMatRenderContext *v7; // eax
  IMatRenderContext *v8; // esi
  IMesh *v9; // esi
  const studiohdr_t *v10; // eax
  mstudiobone_t *v11; // edx
  int v12; // ecx
  char *v13; // edi
  int sznameindex; // edi
  int highlightBone; // eax
  matrix3x4a_t *m_pBoneToWorld; // eax
  float *m_pCurrPosition; // ecx
  float v18; // xmm0_4
  float v19; // xmm1_4
  matrix3x4a_t *v20; // eax
  float *v21; // ecx
  float v22; // xmm0_4
  float v23; // xmm1_4
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  int m_nIndexCount; // [esp+44h] [ebp-210h]
  CMeshBuilder *p_meshBuilder; // [esp+48h] [ebp-20Ch]
  CMeshBuilder meshBuilder; // [esp+50h] [ebp-204h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+238h] [ebp-1Ch]
  int j; // [esp+23Ch] [ebp-18h]
  CStudioHdr *pStudioHdr; // [esp+240h] [ebp-14h]
  int i; // [esp+244h] [ebp-10h]
  unsigned int v34; // [esp+248h] [ebp-Ch]
  mstudiobone_t *pbones; // [esp+24Ch] [ebp-8h]
  bool drawRed; // [esp+253h] [ebp-1h]

  if ( g_viewerSettings.showBones || g_viewerSettings.highlightBone >= 0 )
  {
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      pStudioHdr = this->m_pStudioHdr;
      v6 = m_pStudioHdr;
    }
    else
    {
      v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
      CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
      v6 = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
      pStudioHdr = v6;
    }
    pbones = (mstudiobone_t *)((char *)v6->m_pStudioHdr + v6->m_pStudioHdr->boneindex);
    v7 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int))g_pMaterialSystem->GetRenderContext)(
                                a1: g_pMaterialSystem,
                                a2,
                                a3);
    v8 = v7;
    pRenderContext.m_pObject = v7;
    if ( v7 != nullptr )
      v7->BeginRender(this: v7);
    v8->Bind(this: v8, a2: g_materialBones, a3: nullptr);
    v9 = v8->GetDynamicMesh(this: v8, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    v10 = v6->m_pStudioHdr;
    i = 0;
    drawRed = g_viewerSettings.highlightBone >= 0;
    if ( v10->numbones > 0 )
    {
      v11 = pbones;
      v34 = 0;
      pbones = (mstudiobone_t *)((char *)pbones + 4);
      v12 = -4 - (_DWORD)v11;
      for ( j = -4 - (_DWORD)v11; ; v12 = j )
      {
        v13 = (char *)pbones + v12 + v10->boneindex + (_DWORD)v10;
        if ( (this->BoneMask(this) & *((_DWORD *)v13 + 40)) != 0 )
        {
          sznameindex = pbones->sznameindex;
          highlightBone = g_viewerSettings.highlightBone;
          if ( pbones->sznameindex >= 0
            && (g_viewerSettings.highlightBone < 0 || sznameindex == g_viewerSettings.highlightBone) )
          {
            meshBuilder.m_pMesh = v9;
            meshBuilder.m_bGenerateIndices = true;
            meshBuilder.m_Type = MATERIAL_LINES;
            ((void (__thiscall *)(IMesh *, int, int, CMeshBuilder *))v9->SetPrimitiveType)(
              a1: v9,
              a2: 1,
              a3: m_nIndexCount,
              a4: p_meshBuilder);
            meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 2, a3: 2, a4: &meshBuilder, a5: nullptr);
            meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
            meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
            meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v9->IIndexBuffer;
            meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
            meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
            meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 2;
            meshBuilder.m_IndexBuilder.m_bModify = false;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
            CVertexBuilder::AttachBegin(
              this: &meshBuilder.m_VertexBuilder,
              pMesh: v9,
              nMaxVertexCount: 2,
              desc: &meshBuilder);
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
            CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
            *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = drawRed ? -256 : -16711681;
            m_pBoneToWorld = this->m_pBoneToWorld;
            m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
            v18 = m_pBoneToWorld[sznameindex].m_flMatVal[1][3];
            v19 = m_pBoneToWorld[sznameindex].m_flMatVal[2][3];
            *meshBuilder.m_VertexBuilder.m_pCurrPosition = m_pBoneToWorld[sznameindex].m_flMatVal[0][3];
            m_pCurrPosition[1] = v18;
            m_pCurrPosition[2] = v19;
            CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
            *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = drawRed ? -256 : -16711681;
            v20 = &this->m_pBoneToWorld[v34 / 0x30];
            v21 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
            v22 = v20->m_flMatVal[1][3];
            v23 = v20->m_flMatVal[2][3];
            *meshBuilder.m_VertexBuilder.m_pCurrPosition = v20->m_flMatVal[0][3];
            v21[1] = v22;
            v21[2] = v23;
            CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
            if ( meshBuilder.m_bGenerateIndices )
            {
              switch ( meshBuilder.m_Type )
              {
                case MATERIAL_LINE_STRIP:
                  m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                  break;
                case MATERIAL_LINE_LOOP:
                  m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                  break;
                case MATERIAL_POLYGON:
                  m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                  break;
                case MATERIAL_QUADS:
                  m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                  break;
                case MATERIAL_INSTANCED_QUADS:
                  m_nVertexCount = 0;
                  break;
                default:
                  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
                  break;
              }
              CIndexBuilder::GenerateIndices(
                this: &meshBuilder.m_IndexBuilder,
                primitiveType: meshBuilder.m_Type,
                nIndexCount: m_nVertexCount);
            }
            p_meshBuilder = &meshBuilder;
            m_nIndexCount = meshBuilder.m_IndexBuilder.m_nIndexCount;
            ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
              a1: meshBuilder.m_pMesh,
              a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
            meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
            meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
            meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
            meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
            meshBuilder.m_pMesh = nullptr;
            meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
            v9->Draw_2(this: v9, a2: -1, a3: 0);
            highlightBone = g_viewerSettings.highlightBone;
          }
          if ( highlightBone < 0 || i == highlightBone )
            StudioModel::drawTransform(
              this,
              p_meshBuilder: (CMeshBuilder *)this,
              m_nIndexCount: sznameindex,
              m: &this->m_pBoneToWorld[v34 / 0x30],
              flLength: g_viewerSettings.originAxisLength * 0.40000001);
        }
        v10 = pStudioHdr->m_pStudioHdr;
        ++pbones;
        v34 += 48;
        if ( ++i >= v10->numbones )
          break;
      }
    }
    StudioModel::SetCurrentModel(this);
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
    m_pObject = pRenderContext.m_pObject;
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422FF0
// Name: private: void StudioModel::DrawAttachments(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall StudioModel::DrawAttachments(StudioModel *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  IMatRenderContext *v4; // esi
  CStudioHdr *m_pStudioHdr; // esi
  const studiohdr_t *v6; // eax
  int i; // edi
  int AttachmentBone; // eax
  IMatRenderContext *m_pObject; // esi
  matrix3x4_t *p_local; // [esp+8h] [ebp-48h]
  matrix3x4_t world; // [esp+1Ch] [ebp-34h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+4Ch] [ebp-4h]

  if ( g_viewerSettings.showAttachments )
  {
    v4 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int))g_pMaterialSystem->GetRenderContext)(
                                a1: g_pMaterialSystem,
                                a2,
                                a3);
    pRenderContext.m_pObject = v4;
    if ( v4 != nullptr )
      v4->BeginRender(this: v4);
    v4->Bind(this: v4, a2: g_materialBones, a3: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v6 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
      CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v6, mdlcache: nullptr);
      m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
    }
    for ( i = 0; i < CStudioHdr::GetNumAttachments(this: m_pStudioHdr); ++i )
    {
      p_local = &CStudioHdr::pAttachment(this: m_pStudioHdr, i)->local;
      AttachmentBone = CStudioHdr::GetAttachmentBone(this: m_pStudioHdr, i);
      ConcatTransforms(in1: &this->m_pBoneToWorld[AttachmentBone], in2: p_local, out: &world);
      StudioModel::drawTransform(
        this,
        p_meshBuilder: (CMeshBuilder *)this,
        m_nIndexCount: i,
        m: &world,
        flLength: g_viewerSettings.originAxisLength * 0.40000001);
    }
    m_pObject = pRenderContext.m_pObject;
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423100
// Name: private: void StudioModel::DrawOriginAxis(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall StudioModel::DrawOriginAxis(StudioModel *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  int v3; // esi
  IMesh *v4; // edi
  float *m_pCurrPosition; // eax
  float *v6; // eax
  float *v7; // eax
  float *v8; // eax
  float v9; // xmm1_4
  float *v10; // eax
  float *v11; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+7Ch] [ebp-1ECh] BYREF
  float fAxisLength; // [esp+264h] [ebp-4h]

  if ( g_viewerSettings.showOriginAxis )
  {
    fAxisLength = g_viewerSettings.originAxisLength;
    if ( g_viewerSettings.originAxisLength > 0.0 )
    {
      v3 = ((int (__thiscall *)(IMaterialSystem *, int, int))g_pMaterialSystem->GetRenderContext)(
             a1: g_pMaterialSystem,
             a2,
             a3);
      if ( v3 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
      (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v3 + 36))(a1: v3, a2: g_materialBones, a3: 0);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 80))(a1: v3, a2: 10);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 84))(a1: v3);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 80))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 84))(a1: v3);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 80))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3);
      (*(void (__thiscall **)(int, int, int, _DWORD, _DWORD))(*(_DWORD *)v3 + 140))(
        a1: v3,
        a2: -1028390912,
        a3: 1065353216,
        a4: 0,
        a5: 0);
      (*(void (__thiscall **)(int, int, _DWORD, _DWORD, int))(*(_DWORD *)v3 + 140))(
        a1: v3,
        a2: -1028390912,
        a3: 0,
        a4: 0,
        a5: 1065353216);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v3 + 144))(
        a1: v3,
        a2: -g_pStudioModel->m_origin.x,
        a3: -g_pStudioModel->m_origin.y,
        a4: -g_pStudioModel->m_origin.z);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)v3 + 140))(
        a1: v3,
        a2: LODWORD(g_pStudioModel->m_angles.y),
        a3: 0,
        a4: 0,
        a5: 1065353216);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)v3 + 140))(
        a1: v3,
        a2: LODWORD(g_pStudioModel->m_angles.x),
        a3: 0,
        a4: 1065353216,
        a5: 0);
      (*(void (__thiscall **)(int, _DWORD, int, _DWORD, _DWORD))(*(_DWORD *)v3 + 140))(
        a1: v3,
        a2: LODWORD(g_pStudioModel->m_angles.z),
        a3: 1065353216,
        a4: 0,
        a5: 0);
      v4 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v3 + 228))(
                      a1: v3,
                      a2: 1,
                      a3: 0,
                      a4: 0,
                      a5: 0);
      CMeshBuilder::CMeshBuilder(this: &meshBuilder);
      meshBuilder.m_pMesh = v4;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_LINES;
      v4->SetPrimitiveType(this: v4, a2: MATERIAL_LINES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: 6, desc: &meshBuilder);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
      m_pCurrPosition[1] = 0.0;
      m_pCurrPosition[2] = 0.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v6 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = fAxisLength;
      v6[1] = 0.0;
      v6[2] = 0.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v7 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
      v7[1] = 0.0;
      v7[2] = 0.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v8 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v9 = fAxisLength;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
      v8[1] = v9;
      v8[2] = 0.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v10 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
      v10[1] = 0.0;
      v10[2] = 0.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v11 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
      v11[1] = 0.0;
      v11[2] = fAxisLength;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      if ( meshBuilder.m_bGenerateIndices )
      {
        switch ( meshBuilder.m_Type )
        {
          case MATERIAL_LINE_STRIP:
            m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
            break;
          case MATERIAL_LINE_LOOP:
            m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
            break;
          case MATERIAL_POLYGON:
            m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
            break;
          case MATERIAL_QUADS:
            m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
            break;
          case MATERIAL_INSTANCED_QUADS:
            m_nVertexCount = 0;
            break;
          default:
            m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
            break;
        }
        CIndexBuilder::GenerateIndices(
          this: &meshBuilder.m_IndexBuilder,
          primitiveType: meshBuilder.m_Type,
          nIndexCount: m_nVertexCount);
      }
      ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
        a1: meshBuilder.m_pMesh,
        a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      meshBuilder.m_pMesh = nullptr;
      v4->Draw_2(this: v4, a2: -1, a3: 0);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 80))(a1: v3, a2: 10);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 88))(a1: v3);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 80))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 88))(a1: v3);
      CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423600
// Name: private: void StudioModel::DrawEditAttachment(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::DrawEditAttachment(StudioModel *this)
{
  CStudioHdr *m_pStudioHdr; // esi
  const studiohdr_t *v3; // eax
  int m_iEditAttachment; // edi
  IMatRenderContext *v5; // eax
  int v6; // edi
  int AttachmentBone; // eax
  matrix3x4_t *p_local; // [esp+8h] [ebp-48h]
  matrix3x4_t world; // [esp+1Ch] [ebp-34h] BYREF
  int iEditAttachment; // [esp+4Ch] [ebp-4h]

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
  }
  m_iEditAttachment = g_viewerSettings.m_iEditAttachment;
  iEditAttachment = g_viewerSettings.m_iEditAttachment;
  if ( g_viewerSettings.m_iEditAttachment >= 0 && m_iEditAttachment < CStudioHdr::GetNumAttachments(this: m_pStudioHdr) )
  {
    v5 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v6 = (int)v5;
    if ( v5 != nullptr )
      v5->BeginRender(this: v5);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v6 + 36))(a1: v6, a2: g_materialBones, a3: 0);
    p_local = &CStudioHdr::pAttachment(this: m_pStudioHdr, i: iEditAttachment)->local;
    AttachmentBone = CStudioHdr::GetAttachmentBone(this: m_pStudioHdr, i: iEditAttachment);
    ConcatTransforms(in1: &this->m_pBoneToWorld[AttachmentBone], in2: p_local, out: &world);
    StudioModel::drawTransform(
      this,
      p_meshBuilder: (CMeshBuilder *)this,
      m_nIndexCount: v6,
      m: &world,
      flLength: g_viewerSettings.originAxisLength * 0.40000001);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423700
// Name: private: void StudioModel::DrawIllumPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::DrawIllumPosition(StudioModel *this)
{
  CStudioHdr *m_pStudioHdr; // esi
  const studiohdr_t *v3; // eax
  float z; // ecx
  float v5; // edx
  float v6; // eax
  float v7; // ecx
  float v8; // edx
  const studiohdr_t *v9; // esi
  float v10; // eax
  __int64 v11; // [esp+4h] [ebp-3Ch]
  __int64 v12; // [esp+4h] [ebp-3Ch]
  __int64 v13; // [esp+4h] [ebp-3Ch]
  Vector worldPt0; // [esp+10h] [ebp-30h] BYREF
  Vector worldPt1; // [esp+1Ch] [ebp-24h] BYREF
  Vector modelPt1; // [esp+28h] [ebp-18h] BYREF
  Vector modelPt0; // [esp+34h] [ebp-Ch] BYREF

  if ( g_viewerSettings.showIllumPosition )
  {
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
      CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
      m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
    }
    z = m_pStudioHdr->m_pStudioHdr->illumposition.z;
    *(_QWORD *)&modelPt0.x = *(_QWORD *)&m_pStudioHdr->m_pStudioHdr->illumposition.x;
    modelPt0.z = z;
    v5 = m_pStudioHdr->m_pStudioHdr->illumposition.z;
    v11 = *(_QWORD *)&m_pStudioHdr->m_pStudioHdr->illumposition.x;
    modelPt0.x = modelPt0.x - 4.0;
    modelPt1.y = *((float *)&v11 + 1);
    modelPt1.z = v5;
    modelPt1.x = *(float *)&v11 + 4.0;
    VectorTransform(in1: &modelPt0.x, in2: &g_viewtransform, out: &worldPt0.x);
    VectorTransform(in1: &modelPt1.x, in2: &g_viewtransform, out: &worldPt1.x);
    StudioModel::drawLine(this, a2: (int)this, p1: &worldPt0, p2: &worldPt1, r: 0xFFu, g: 0, b: 0);
    v6 = m_pStudioHdr->m_pStudioHdr->illumposition.z;
    *(_QWORD *)&modelPt0.x = *(_QWORD *)&m_pStudioHdr->m_pStudioHdr->illumposition.x;
    modelPt0.z = v6;
    v7 = m_pStudioHdr->m_pStudioHdr->illumposition.z;
    v12 = *(_QWORD *)&m_pStudioHdr->m_pStudioHdr->illumposition.x;
    modelPt0.y = modelPt0.y - 4.0;
    LODWORD(modelPt1.x) = v12;
    modelPt1.z = v7;
    modelPt1.y = *((float *)&v12 + 1) + 4.0;
    VectorTransform(in1: &modelPt0.x, in2: &g_viewtransform, out: &worldPt0.x);
    VectorTransform(in1: &modelPt1.x, in2: &g_viewtransform, out: &worldPt1.x);
    StudioModel::drawLine(this, a2: (int)this, p1: &worldPt0, p2: &worldPt1, r: 0, g: 0xFFu, b: 0);
    v8 = m_pStudioHdr->m_pStudioHdr->illumposition.z;
    *(_QWORD *)&modelPt0.x = *(_QWORD *)&m_pStudioHdr->m_pStudioHdr->illumposition.x;
    modelPt0.z = v8;
    v9 = m_pStudioHdr->m_pStudioHdr;
    v10 = v9->illumposition.z;
    v13 = *(_QWORD *)&v9->illumposition.x;
    modelPt0.z = v8 - 4.0;
    *(_QWORD *)&modelPt1.x = v13;
    modelPt1.z = v10 + 4.0;
    VectorTransform(in1: &modelPt0.x, in2: &g_viewtransform, out: &worldPt0.x);
    VectorTransform(in1: &modelPt1.x, in2: &g_viewtransform, out: &worldPt1.x);
    StudioModel::drawLine(this, a2: (int)this, p1: &worldPt0, p2: &worldPt1, r: 0, g: 0, b: 0xFFu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423970
// Name: public: void StudioModel::SetViewTarget(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall StudioModel::SetViewTarget(StudioModel *this@<ecx>, float a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  float x; // eax
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v7; // eax
  const mstudioattachment_t *v8; // eax
  int AttachmentBone; // eax
  float z; // xmm0_4
  float v11; // xmm2_4
  bool v12; // cc
  float y; // xmm1_4
  StudioLookTarget *v14; // eax
  float v15; // xmm1_4
  __int128 v16; // xmm0
  double FlexController; // st7
  float v18; // xmm4_4
  int studiohdr2index; // ecx
  float v20; // xmm4_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  _DWORD v26[3]; // [esp-Ch] [ebp-84h] BYREF
  matrix3x4_t attToWorld; // [esp+0h] [ebp-78h] BYREF
  Vector tmp; // [esp+30h] [ebp-48h] BYREF
  __int128 eyeAng; // [esp+3Ch] [ebp-3Ch] OVERLAPPED BYREF
  int v30; // [esp+4Ch] [ebp-2Ch]
  Vector v31; // [esp+50h] [ebp-28h] BYREF
  Vector eyeDeflect; // [esp+5Ch] [ebp-1Ch] BYREF
  Vector local; // [esp+68h] [ebp-10h]
  float retaddr; // [esp+78h] [ebp+0h]

  local.y = a2;
  local.z = retaddr;
  if ( (((int (__thiscall *)(StudioModel *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->BoneMask)(
          a1: this,
          a2: a3,
          a3: a4,
          a4: v26[0],
          a5: v26[1],
          a6: v26[2],
          a7: LODWORD(attToWorld.m_flMatVal[0][0]),
          a8: LODWORD(attToWorld.m_flMatVal[0][1]),
          a9: LODWORD(attToWorld.m_flMatVal[0][2]),
          a10: LODWORD(attToWorld.m_flMatVal[0][3]),
          a11: LODWORD(attToWorld.m_flMatVal[1][0]),
          a12: LODWORD(attToWorld.m_flMatVal[1][1]),
          a13: LODWORD(attToWorld.m_flMatVal[1][2]),
          a14: LODWORD(attToWorld.m_flMatVal[1][3]),
          a15: LODWORD(attToWorld.m_flMatVal[2][0]),
          a16: LODWORD(attToWorld.m_flMatVal[2][1]),
          a17: LODWORD(attToWorld.m_flMatVal[2][2]),
          a18: LODWORD(attToWorld.m_flMatVal[2][3]),
          a19: LODWORD(tmp.x),
          a20: LODWORD(tmp.y),
          a21: LODWORD(tmp.z),
          a22: eyeAng,
          a23: DWORD1(eyeAng),
          a24: DWORD2(eyeAng),
          a25: HIDWORD(eyeAng),
          a26: v30,
          a27: LODWORD(v31.x),
          a28: LODWORD(v31.y),
          a29: LODWORD(v31.z),
          a30: LODWORD(eyeDeflect.x),
          a31: LODWORD(eyeDeflect.y),
          a32: LODWORD(eyeDeflect.z))
      & 0x200) != 0 )
  {
    x = COERCE_FLOAT(StudioModel::LookupAttachment(this, szName: "eyes"));
    local.x = x;
    if ( x != NAN )
    {
      m_pStudioHdr = this->m_pStudioHdr;
      if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
      {
        v7 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
        CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v7, mdlcache: nullptr);
        m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
        x = local.x;
      }
      v8 = CStudioHdr::pAttachment(this: m_pStudioHdr, i: SLODWORD(x));
      LODWORD(eyeDeflect.z) = v26;
      LODWORD(eyeDeflect.y) = &v8->local;
      AttachmentBone = CStudioHdr::GetAttachmentBone(this: m_pStudioHdr, i: SLODWORD(local.x));
      ConcatTransforms(
        in1: &this->m_pBoneToWorld[AttachmentBone],
        in2: (const matrix3x4_t *)LODWORD(eyeDeflect.y),
        out: (matrix3x4_t *)LODWORD(eyeDeflect.z));
      z = 0.0;
      v11 = 32.0;
      v12 = this->m_vecHeadTargets.m_Size <= 0;
      y = 0.0;
      eyeDeflect.x = 32.0;
      eyeDeflect.y = 0.0;
      eyeDeflect.z = 0.0;
      if ( !v12 )
      {
        v14 = &this->m_vecHeadTargets.m_Memory.m_pMemory[this->m_vecHeadTargets.m_Size];
        if ( !v14[-1].m_bSelf )
        {
          *((float *)&eyeAng + 1) = v14[-1].m_vecPosition.x - attToWorld.m_flMatVal[0][0];
          *((float *)&eyeAng + 2) = v14[-1].m_vecPosition.y - attToWorld.m_flMatVal[1][0];
          *((float *)&eyeAng + 3) = v14[-1].m_vecPosition.z - attToWorld.m_flMatVal[2][0];
          VectorITransform(in1: (const float *)&eyeAng + 1, in2: (const matrix3x4_t *)v26, out: &eyeDeflect.x);
          z = eyeDeflect.z;
          y = eyeDeflect.y;
          v11 = eyeDeflect.x;
        }
      }
      v15 = (float)(y * y) + (float)(z * z);
      v16 = 0;
      *(float *)&v16 = fsqrt(v15 + (float)(v11 * v11));
      eyeAng = v16;
      VectorNormalize(vec: &eyeDeflect);
      local.x = StudioModel::GetFlexController(this, szName: "eyes_updown");
      FlexController = StudioModel::GetFlexController(this, szName: "eyes_rightleft");
      tmp.x = local.x;
      tmp.y = FlexController;
      tmp.z = 0.0;
      AngleVectors(angles: (const QAngle *)&tmp, forward: &v31);
      v18 = eyeDeflect.x;
      v31.x = (float)(v18 * v18) * 0.0;
      v31.y = v31.y * (float)(v18 * v18);
      v31.z = v31.z * (float)(v18 * v18);
      eyeDeflect.x = v31.x + eyeDeflect.x;
      eyeDeflect.y = v31.y + eyeDeflect.y;
      eyeDeflect.z = v31.z + eyeDeflect.z;
      VectorNormalize(vec: (Vector *)LODWORD(eyeDeflect.x));
      studiohdr2index = m_pStudioHdr->m_pStudioHdr->studiohdr2index;
      if ( studiohdr2index == 0 || (v20 = *(float *)&m_pStudioHdr->m_pStudioHdr->name[studiohdr2index]) == 0.0 )
        v20 = 0.866;
      v21 = eyeDeflect.x;
      v22 = eyeDeflect.y;
      v23 = eyeDeflect.z;
      if ( v20 > eyeDeflect.x )
      {
        if ( (float)((float)(eyeDeflect.z * eyeDeflect.z) + (float)(eyeDeflect.y * eyeDeflect.y)) <= 0.0 )
        {
          v21 = 1.0;
        }
        else
        {
          v24 = fsqrt(
                  (float)(1.0 - (float)(v20 * v20))
                / (float)((float)(eyeDeflect.z * eyeDeflect.z) + (float)(eyeDeflect.y * eyeDeflect.y)));
          v21 = v20;
          v22 = eyeDeflect.y * v24;
          v23 = eyeDeflect.z * v24;
        }
      }
      VectorTransform(
        in1: COERCE_CONST_FLOAT_(*(float *)&eyeAng * v21),
        in2: COERCE_CONST_MATRIX3X4_T_(*(float *)&eyeAng * v22),
        out: COERCE_FLOAT_(*(float *)&eyeAng * v23));
      g_pStudioRender->SetEyeViewTarget(
        this: g_pStudioRender,
        a2: m_pStudioHdr->m_pStudioHdr,
        a3: this->m_bodynum,
        a4: (const Vector *)&attToWorld.m_flMatVal[2][1]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423C70
// Name: public: void StudioModel::CalcHeadRotation(class Vector __near * const,class Quaternion __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::CalcHeadRotation(StudioModel *this, Vector *pos, Quaternion *q)
{
  unsigned int v3; // eax
  int v5; // ebx
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v7; // eax
  int AttachmentBone; // ebx
  float v9; // xmm4_4
  int v10; // ebx
  StudioLookTarget *m_pMemory; // ecx
  int v12; // edi
  float v13; // xmm1_4
  float v14; // xmm2_4
  float m_flWeight; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  matrix3x4_t attToWorld; // [esp+14h] [ebp-70h] BYREF
  Vector vTargetDir; // [esp+44h] [ebp-40h] BYREF
  Vector vEyes; // [esp+50h] [ebp-34h] BYREF
  Vector vForward; // [esp+5Ch] [ebp-28h] BYREF
  Vector dir; // [esp+68h] [ebp-1Ch] BYREF
  Vector vHead; // [esp+74h] [ebp-10h]
  mstudioattachment_t *patt; // [esp+80h] [ebp-4h]
  int savedregs; // [esp+84h] [ebp+0h] BYREF
  float dt; // [esp+8Ch] [ebp+8h]
  float flHeadInfluence; // [esp+90h] [ebp+Ch]

  v3 = _S2_0;
  if ( (_S2_0 & 1) == 0 )
  {
    v3 = _S2_0 | 1;
    _S2_0 |= 1u;
  }
  if ( (v3 & 2) == 0 )
    _S2_0 = v3 | 2;
  if ( this->m_nSolveHeadTurn != 0 )
  {
    if ( this->m_dt == 0.0 )
      this->m_dt = 0.1;
    v5 = StudioModel::LookupAttachment(this, szName: "forward");
    if ( v5 != -1 )
    {
      m_pStudioHdr = this->m_pStudioHdr;
      if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
      {
        v7 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
        CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v7, mdlcache: nullptr);
        m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
      }
      patt = (mstudioattachment_t *)CStudioHdr::pAttachment(this: m_pStudioHdr, i: v5);
      AttachmentBone = CStudioHdr::GetAttachmentBone(this: m_pStudioHdr, i: v5);
      BuildBoneChain(
        pStudioHdr: m_pStudioHdr,
        rootxform: &g_viewtransform,
        pos,
        q,
        iBone: AttachmentBone,
        pBoneToWorld: this->m_pBoneToWorld);
      ConcatTransforms(in1: &this->m_pBoneToWorld[AttachmentBone], in2: &patt->local, out: &attToWorld);
      vEyes.x = 1.0;
      vEyes.y = 0.0;
      vEyes.z = 0.0;
      VectorRotate(in1: &vEyes.x, in2: &attToWorld, out: &vForward.x);
      dt = this->m_dt;
      if ( this->m_nSolveHeadTurn == 2 )
        dt = 0.1;
      v9 = 0.0;
      vEyes.x = attToWorld.m_flMatVal[0][3];
      vEyes.y = attToWorld.m_flMatVal[1][3];
      v10 = 0;
      vEyes.z = attToWorld.m_flMatVal[2][3];
      vHead = vForward;
      flHeadInfluence = 0.0;
      if ( this->m_vecHeadTargets.m_Size > 0 )
      {
        m_pMemory = this->m_vecHeadTargets.m_Memory.m_pMemory;
        v12 = 0;
        do
        {
          if ( m_pMemory[v12].m_bSelf )
          {
            dir = vForward;
          }
          else
          {
            v13 = m_pMemory[v12].m_vecPosition.y - vEyes.y;
            v14 = m_pMemory[v12].m_vecPosition.z - vEyes.z;
            dir.x = m_pMemory[v12].m_vecPosition.x - vEyes.x;
            dir.y = v13;
            dir.z = v14;
          }
          VectorNormalize(vec: &dir);
          m_pMemory = this->m_vecHeadTargets.m_Memory.m_pMemory;
          m_flWeight = m_pMemory[v12].m_flWeight;
          if ( m_flWeight <= 0.0 )
          {
            v9 = flHeadInfluence;
          }
          else if ( flHeadInfluence == 0.0 )
          {
            vHead = dir;
            v9 = m_flWeight;
            flHeadInfluence = m_flWeight;
          }
          else
          {
            v9 = (float)((float)(1.0 - m_flWeight) * flHeadInfluence) + m_flWeight;
            v16 = m_flWeight / v9;
            v17 = 1.0 - (float)(m_flWeight / v9);
            flHeadInfluence = v9;
            vHead.x = (float)(vHead.x * v17) + (float)(dir.x * v16);
            vHead.y = (float)(vHead.y * v17) + (float)(dir.y * v16);
            vHead.z = (float)(vHead.z * v17) + (float)(dir.z * v16);
          }
          ++v10;
          ++v12;
        }
        while ( v10 < this->m_vecHeadTargets.m_Size );
      }
      vTargetDir.x = (float)((float)(1.0 - v9) * vForward.x) + (float)(vHead.x * v9);
      vTargetDir.y = (float)(vForward.y * (float)(1.0 - v9)) + (float)(vHead.y * v9);
      vTargetDir.z = (float)(vForward.z * (float)(1.0 - v9)) + (float)(vHead.z * v9);
      VectorNormalize(vec: &vTargetDir);
      StudioModel::SetPoseParameter(this, szName: "head_pitch", flValue: 0.0);
      StudioModel::SetPoseParameter(this, szName: "head_yaw", flValue: 0.0);
      StudioModel::SetPoseParameter(this, szName: "head_roll", flValue: 0.0);
      StudioModel::SetHeadPosition(this, a2: COERCE_FLOAT(&savedregs), &attToWorld, vTargetPos: &vTargetDir, dt);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424020
// Name: private: void StudioModel::DrawPhysmesh(class CPhysmesh __near *,int,class IMaterial __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge StudioModel::DrawPhysmesh(
        StudioModel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CPhysmesh *pMesh,
        matrix3x4_t *boneIndex,
        IMaterial *pMaterial,
        float *color)
{
  IMatRenderContext *v8; // esi
  IMesh *v9; // edi
  int v11; // eax
  int v12; // esi
  int v14; // edi
  int v15; // edi
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-224h] BYREF
  float v19; // [esp+1E8h] [ebp-3Ch]
  float v20; // [esp+1ECh] [ebp-38h]
  float v21; // [esp+1F0h] [ebp-34h]
  CMatRenderContextPtr pRenderContext; // [esp+1F4h] [ebp-30h]
  float v23; // [esp+1F8h] [ebp-2Ch]
  IMesh *pMatMesh; // [esp+1FCh] [ebp-28h]
  float v25; // [esp+200h] [ebp-24h]
  float v26; // [esp+204h] [ebp-20h]
  float v27; // [esp+208h] [ebp-1Ch]
  float v28; // [esp+20Ch] [ebp-18h]
  float v29; // [esp+210h] [ebp-14h]
  float v30; // [esp+214h] [ebp-10h]
  Vector v; // [esp+218h] [ebp-Ch] BYREF
  float pMesha; // [esp+22Ch] [ebp+8h]
  matrix3x4a_t *pMatrix; // [esp+230h] [ebp+Ch]
  int i; // [esp+234h] [ebp+10h]
  float colora; // [esp+238h] [ebp+14h]

  if ( (int)boneIndex < 0 )
    pMatrix = &g_viewtransform;
  else
    pMatrix = &this->m_pBoneToWorld[(_DWORD)boneIndex];
  v8 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
                              a1: g_pMaterialSystem,
                              a2: a4);
  pRenderContext.m_pObject = v8;
  if ( v8 != nullptr )
    v8->BeginRender(this: v8);
  ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, int, int))v8->Bind)(
    a1: v8,
    a2: pMaterial,
    a3: 0,
    a4: a3,
    a5: a2);
  v9 = v8->GetDynamicMesh(this: v8, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  pMatMesh = v9;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v11 = pMesh->m_vertCount / 3;
  meshBuilder.m_pMesh = v9;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLES;
  v12 = 3 * v11;
  v9->SetPrimitiveType(this: v9, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v12, a3: v12, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v9->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v12;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v9, nMaxVertexCount: v12, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  i = 0;
  if ( pMesh->m_vertCount > 0 )
  {
    v14 = 0;
    do
    {
      VectorTransform(in1: (const float *)((char *)&pMesh->m_pVerts->x + v14), in2: pMatrix, out: &v.x);
      *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v;
      v20 = (float)(color[2] * 255.0) + 8388608.0;
      v21 = (float)(color[1] * 255.0) + 8388608.0;
      colora = (float)(*color * 255.0) + 8388608.0;
      pMesha = (float)(color[3] * 255.0) + 8388608.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v20)
                                                          | ((LOBYTE(v21)
                                                            | ((LOBYTE(colora) | (LOBYTE(pMesha) << 8)) << 8)) << 8);
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v15 = v14 + 12;
      VectorTransform(in1: (const float *)((char *)&pMesh->m_pVerts->x + v15), in2: pMatrix, out: &v.x);
      *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v;
      v25 = (float)(color[2] * 255.0) + 8388608.0;
      v19 = (float)(color[1] * 255.0) + 8388608.0;
      v27 = (float)(*color * 255.0) + 8388608.0;
      v23 = (float)(color[3] * 255.0) + 8388608.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v25)
                                                          | ((LOBYTE(v19) | ((LOBYTE(v27) | (LOBYTE(v23) << 8)) << 8)) << 8);
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v15 += 12;
      VectorTransform(in1: (const float *)((char *)&pMesh->m_pVerts->x + v15), in2: pMatrix, out: &v.x);
      *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v;
      v26 = (float)(color[2] * 255.0) + 8388608.0;
      v28 = (float)(color[1] * 255.0) + 8388608.0;
      v29 = (float)(*color * 255.0) + 8388608.0;
      v30 = (float)(color[3] * 255.0) + 8388608.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v26)
                                                          | ((LOBYTE(v28) | ((LOBYTE(v29) | (LOBYTE(v30) << 8)) << 8)) << 8);
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v14 = v15 + 12;
      i += 3;
    }
    while ( i < pMesh->m_vertCount );
    v9 = pMatMesh;
  }
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
    a1: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v9->Draw_2(this: v9, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x00424500
// Name: private: void StudioModel::DrawPhysConvex(class CPhysmesh __near *,int,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::DrawPhysConvex(StudioModel *this, CPhysmesh *pMesh, int boneIndex, IMaterial *pMaterial)
{
  IMatRenderContext *m_pObject; // esi
  IMesh *v6; // esi
  ICollisionQuery *m_pCollisionModel; // ecx
  int (__thiscall *TriangleCount)(ICollisionQuery *, int); // edx
  int v9; // eax
  int v10; // edi
  int m_nVertexCount; // eax
  Vector *v12; // esi
  int k; // edi
  int v14; // eax
  Vector objectSpaceVerts[3]; // [esp+Ch] [ebp-260h] BYREF
  CMeshBuilder meshBuilder; // [esp+30h] [ebp-23Ch] BYREF
  float color[4]; // [esp+218h] [ebp-54h] BYREF
  Vector v; // [esp+228h] [ebp-44h] BYREF
  float v19; // [esp+234h] [ebp-38h]
  float v20; // [esp+238h] [ebp-34h]
  matrix3x4_t *matrix; // [esp+23Ch] [ebp-30h]
  float v22; // [esp+240h] [ebp-2Ch]
  int v23; // [esp+244h] [ebp-28h]
  float v24; // [esp+248h] [ebp-24h]
  IMesh *pMatMesh; // [esp+24Ch] [ebp-20h]
  float v26; // [esp+250h] [ebp-1Ch]
  float v27; // [esp+254h] [ebp-18h]
  float v28; // [esp+258h] [ebp-14h]
  float v29; // [esp+25Ch] [ebp-10h]
  CMatRenderContextPtr pRenderContext; // [esp+260h] [ebp-Ch]
  int triCount; // [esp+264h] [ebp-8h]
  int key; // [esp+268h] [ebp-4h]
  int i; // [esp+278h] [ebp+Ch]
  int ja; // [esp+27Ch] [ebp+10h]
  int j; // [esp+27Ch] [ebp+10h]

  matrix = &this->m_pBoneToWorld[boneIndex];
  m_pObject = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  m_pObject->Bind(this: m_pObject, a2: pMaterial, a3: nullptr);
  i = 0;
  if ( pMesh->m_pCollisionModel->ConvexCount(this: pMesh->m_pCollisionModel) > 0 )
  {
    v23 = boneIndex + 1;
    key = boneIndex + 1;
    do
    {
      RandomColor(color, key);
      v6 = m_pObject->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      m_pCollisionModel = pMesh->m_pCollisionModel;
      meshBuilder.m_pMesh = nullptr;
      meshBuilder.m_bGenerateIndices = false;
      memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
      memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
      meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
      TriangleCount = m_pCollisionModel->TriangleCount;
      pMatMesh = v6;
      v9 = TriangleCount(this: m_pCollisionModel, a2: i);
      v10 = 3 * v9;
      triCount = v9;
      meshBuilder.m_pMesh = v6;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_TRIANGLES;
      ja = 3 * v9;
      v6->SetPrimitiveType(this: v6, a2: MATERIAL_TRIANGLES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v10, a3: v10, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v6->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v10;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = v6;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = ja;
      meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
      m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_bModify = false;
      if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
      {
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
      }
      meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
      meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
      qmemcpy(
        meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
        meshBuilder.m_VertexBuilder.m_pTexCoord,
        sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
      meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
      j = 0;
      if ( triCount > 0 )
      {
        v19 = (float)(color[2] * 255.0) + 8388608.0;
        v26 = (float)(color[1] * 255.0) + 8388608.0;
        v20 = (float)(color[0] * 255.0) + 8388608.0;
        v24 = (float)(color[3] * 255.0) + 8388608.0;
        do
        {
          pMesh->m_pCollisionModel->GetTriangleVerts(this: pMesh->m_pCollisionModel, a2: i, a3: j, a4: objectSpaceVerts);
          v12 = objectSpaceVerts;
          for ( k = 3; k != 0; --k )
          {
            VectorTransform(in1: &v12->x, in2: matrix, out: &v.x);
            *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = v;
            v27 = v19;
            v28 = v26;
            v22 = v20;
            v29 = v24;
            *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v19)
                                                                | ((LOBYTE(v26)
                                                                  | ((LOBYTE(v20) | (LOBYTE(v24) << 8)) << 8)) << 8);
            CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
            ++v12;
          }
          ++j;
        }
        while ( j < triCount );
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
      }
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
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      meshBuilder.m_pMesh = nullptr;
      pMatMesh->Draw_2(this: pMatMesh, a2: -1, a3: 0);
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
      key += v23;
      ++i;
      v14 = pMesh->m_pCollisionModel->ConvexCount(this: pMesh->m_pCollisionModel);
      m_pObject = pRenderContext.m_pObject;
    }
    while ( i < v14 );
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x00424A00
// Name: private: void StudioModel::DrawHitboxes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::DrawHitboxes(StudioModel *this)
{
  CStudioHdr *m_pStudioHdr; // ebx
  const studiohdr_t *v3; // eax
  int CurrentHitboxSet; // eax
  CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *p_m_Hitboxes; // ecx
  unsigned __int16 m_Head; // ax
  int highlightHitbox; // edx
  int v8; // esi
  int p_m_BBox; // ecx
  int v10; // eax
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  bool v14; // zf
  int m_sequence; // eax
  const studiohdr_t *v16; // ecx
  mstudioseqdesc_t *v17; // esi
  int v18; // eax
  mstudioseqdesc_t *v19; // eax
  matrix3x4a_t *v20; // [esp-Ch] [ebp-3Ch]
  float color[4]; // [esp+Ch] [ebp-24h] BYREF
  float wirecolor[4]; // [esp+1Ch] [ebp-14h] BYREF
  CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *list; // [esp+2Ch] [ebp-4h]

  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
  }
  if ( g_pAlpha == nullptr )
    g_pAlpha = g_pMaterialSystem->FindMaterial(
                 this: g_pMaterialSystem,
                 a2: "debug/debughitbox",
                 a3: "Other textures",
                 a4: 0,
                 a5: 0);
  if ( g_viewerSettings.showHitBoxes || g_viewerSettings.highlightHitbox >= 0 )
  {
    CurrentHitboxSet = MDLViewer::GetCurrentHitboxSet(this: g_MDLViewer);
    p_m_Hitboxes = &g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory[CurrentHitboxSet].m_Hitboxes;
    m_Head = g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory[CurrentHitboxSet].m_Hitboxes.m_Head;
    list = p_m_Hitboxes;
    if ( m_Head != 0xFFFF )
    {
      highlightHitbox = g_viewerSettings.highlightHitbox;
      do
      {
        if ( highlightHitbox < 0 || (v8 = m_Head, highlightHitbox == m_Head) )
        {
          v8 = m_Head;
          p_m_BBox = (int)&p_m_Hitboxes->m_Memory.m_pMemory[m_Head].m_Element.m_BBox;
          v10 = *(_DWORD *)(p_m_BBox + 4) % 8;
          v11 = hullcolor[v10][0] * 0.7;
          wirecolor[0] = v11;
          v12 = hullcolor[v10][1] * 0.7;
          wirecolor[1] = v12;
          v13 = hullcolor[v10][2] * 0.7;
          wirecolor[2] = v13;
          v20 = &this->m_pBoneToWorld[*(_DWORD *)p_m_BBox];
          wirecolor[3] = hullcolor[v10][3] * 0.4;
          StudioModel::drawTransparentBox(
            this,
            a2: (int)m_pStudioHdr,
            a3: (int)this,
            a4: v8,
            bbmin: (const Vector *)(p_m_BBox + 8),
            bbmax: (const Vector *)(p_m_BBox + 20),
            m: v20,
            color: wirecolor,
            wirecolor: hullcolor[v10]);
          highlightHitbox = g_viewerSettings.highlightHitbox;
          p_m_Hitboxes = list;
        }
        m_Head = p_m_Hitboxes->m_Memory.m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
  }
  if ( g_viewerSettings.showSequenceBoxes )
  {
    v14 = m_pStudioHdr->m_pVModel == nullptr;
    m_sequence = this->m_sequence;
    color[0] = 0.69999999;
    color[1] = 1.0;
    color[2] = 0.0;
    color[3] = 0.60000002;
    wirecolor[0] = 1.0;
    wirecolor[1] = 1.0;
    wirecolor[2] = 0.0;
    wirecolor[3] = 1.0;
    if ( v14 )
    {
      v16 = m_pStudioHdr->m_pStudioHdr;
      if ( m_sequence < 0 || m_sequence >= v16->numlocalseq )
        m_sequence = 0;
      v17 = (mstudioseqdesc_t *)((char *)v16 + 212 * m_sequence + v16->localseqindex);
    }
    else
    {
      v17 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: m_sequence);
    }
    v18 = this->m_sequence;
    if ( m_pStudioHdr->m_pVModel != nullptr )
    {
      v19 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: this->m_sequence);
    }
    else
    {
      m_pStudioHdr = (CStudioHdr *)m_pStudioHdr->m_pStudioHdr;
      if ( v18 < 0 || v18 >= m_pStudioHdr[1].m_nPerfAnimatedBones )
        v18 = 0;
      v19 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v18 + m_pStudioHdr[1].m_nPerfUsedBones);
    }
    StudioModel::drawTransparentBox(
      this,
      a2: (int)m_pStudioHdr,
      a3: (int)this,
      a4: (int)&v17->bbmax,
      bbmin: &v19->bbmin,
      bbmax: &v17->bbmax,
      m: &g_viewtransform,
      color,
      wirecolor);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424C90
// Name: private: void StudioModel::DrawPhysicsModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::DrawPhysicsModel(StudioModel *this)
{
  IStudioPhysics *m_pPhysics; // ecx
  int v3; // edi
  CPhysmesh *v4; // ebx
  CStudioHdr *v5; // eax
  const studiohdr_t *v6; // eax
  int v7; // eax
  int v8; // ebx
  CPhysmesh *v9; // edi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v11; // eax
  matrix3x4_t *BoneIndex; // eax
  float yellow[4]; // [esp+4h] [ebp-20h] BYREF
  float red[4]; // [esp+14h] [ebp-10h] BYREF

  if ( g_viewerSettings.showPhysicsModel )
  {
    m_pPhysics = this->m_pPhysics;
    if ( g_viewerSettings.renderMode != 0 )
    {
      v8 = 0;
      if ( m_pPhysics->Count(this: m_pPhysics) > 0 )
      {
        red[0] = 1.0;
        yellow[0] = 1.0;
        yellow[1] = 1.0;
        red[1] = 0.0;
        red[2] = 0.0;
        red[3] = 0.25;
        yellow[2] = 0.0;
        yellow[3] = 0.5;
        do
        {
          v9 = this->m_pPhysics->GetMesh(this: this->m_pPhysics, a2: v8);
          m_pStudioHdr = this->m_pStudioHdr;
          if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
          {
            v11 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
            CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v11, mdlcache: nullptr);
            m_pStudioHdr = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
          }
          BoneIndex = (matrix3x4_t *)FindBoneIndex(pstudiohdr: m_pStudioHdr, pName: v9->m_boneName);
          if ( (int)BoneIndex < 0 )
          {
            StudioModel::DrawPhysmesh(
              this,
              a2: v8,
              a3: (int)v9,
              a4: (int)this,
              pMesh: v9,
              boneIndex: (matrix3x4_t *)0xFFFFFFFF,
              pMaterial: g_materialBones,
              color: red);
          }
          else if ( v8 + 1 == g_viewerSettings.highlightPhysicsBone )
          {
            StudioModel::DrawPhysmesh(
              this,
              a2: v8,
              a3: (int)v9,
              a4: (int)this,
              pMesh: v9,
              boneIndex: BoneIndex,
              pMaterial: g_materialBones,
              color: red);
          }
          else if ( g_viewerSettings.highlightPhysicsBone < 1 )
          {
            StudioModel::DrawPhysmesh(
              this,
              a2: v8,
              a3: (int)v9,
              a4: (int)this,
              pMesh: v9,
              boneIndex: BoneIndex,
              pMaterial: g_materialBones,
              color: yellow);
          }
          ++v8;
        }
        while ( v8 < this->m_pPhysics->Count(this: this->m_pPhysics) );
      }
    }
    else
    {
      v3 = 0;
      if ( m_pPhysics->Count(this: m_pPhysics) > 0 )
      {
        do
        {
          v4 = this->m_pPhysics->GetMesh(this: this->m_pPhysics, a2: v3);
          v5 = this->m_pStudioHdr;
          if ( v5 != nullptr && v5->m_pStudioHdr == nullptr )
          {
            v6 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
            CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v6, mdlcache: nullptr);
            v5 = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
          }
          v7 = FindBoneIndex(pstudiohdr: v5, pName: v4->m_boneName);
          StudioModel::DrawPhysConvex(this, pMesh: v4, boneIndex: v7, pMaterial: g_materialFlatshaded);
          ++v3;
        }
        while ( v3 < this->m_pPhysics->Count(this: this->m_pPhysics) );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424E60
// Name: public: virtual int StudioModel::DrawModel(bool)
// Source: json
//------------------------------------------------------------------------------
int __userpurge StudioModel::DrawModel@<eax>(StudioModel *this@<ecx>, int a2@<edi>, float *mergeBones)
{
  IMDLCache *v3; // ebx
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v7; // eax
  CStudioHdr *v8; // eax
  const studiohdr_t *v9; // eax
  CStudioHdr *v10; // edi
  float *m_pRenderData; // ebx
  int j; // eax
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  IMatRenderContext *v14; // eax
  int numflexdesc; // edi
  float *v16; // eax
  IMatRenderContext_vtbl *v17; // edx
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // eax
  float *v19; // eax
  float v20; // xmm0_4
  int v21; // ecx
  float *v22; // edx
  float v23; // xmm1_4
  float *v24; // eax
  char *v25; // edi
  float v26; // xmm2_4
  char *v27; // ebx
  float v28; // xmm2_4
  char *v29; // ebx
  float v30; // xmm2_4
  char *v31; // ebx
  double v32; // st7
  int v33; // ebx
  float v34; // xmm2_4
  int v35; // ebx
  int v36; // eax
  float v37; // xmm1_4
  float *materialIndex; // edi
  IMatRenderContext *m_pObject; // esi
  IMatRenderContext_vtbl *v40; // edx
  IMatRenderContext_vtbl *v41; // edx
  studioloddata_t *m_pLODs; // ecx
  const char *v44; // eax
  IMaterial *v45; // ecx
  const studiohdr_t *v46; // edx
  matrix3x4_t *v47; // edi
  const studiohdr_t *v48; // edx
  IMatRenderContext *v49; // esi
  IMatRenderContext_vtbl *v50; // eax
  IMatRenderContext_vtbl *v51; // edx
  IStudioRender *v52; // [esp+4h] [ebp-110h]
  matrix3x4a_t *m_pBoneToWorld; // [esp+Ch] [ebp-108h]
  matrix3x4a_t *v54; // [esp+Ch] [ebp-108h]
  long double v56; // [esp+34h] [ebp-E0h]
  long double v57; // [esp+34h] [ebp-E0h]
  matrix3x4_t invViewTransform; // [esp+3Ch] [ebp-D8h] BYREF
  matrix3x4_t tmp1; // [esp+6Ch] [ebp-A8h] BYREF
  float one[4]; // [esp+9Ch] [ebp-78h] BYREF
  char *v61; // [esp+ACh] [ebp-68h]
  char *v62; // [esp+B0h] [ebp-64h]
  char *v63; // [esp+B4h] [ebp-60h]
  char *v64; // [esp+B8h] [ebp-5Ch]
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+BCh] [ebp-58h]
  CMatRenderData<float> rdDelayedFlexWeights; // [esp+C0h] [ebp-54h] BYREF
  CMatRenderData<float> rdFlexWeights; // [esp+D0h] [ebp-44h] BYREF
  int nCount; // [esp+E0h] [ebp-34h]
  float *pFlexWeights; // [esp+E4h] [ebp-30h]
  Vector vecModelOrigin; // [esp+E8h] [ebp-2Ch] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+F4h] [ebp-20h]
  float zero[4]; // [esp+F8h] [ebp-1Ch] BYREF
  CStudioHdr *pStudioHdr; // [esp+108h] [ebp-Ch]
  int i; // [esp+10Ch] [ebp-8h]
  float d; // [esp+110h] [ebp-4h]
  int savedregs; // [esp+114h] [ebp+0h] BYREF
  float pFlexDelayedWeights; // [esp+11Ch] [ebp+8h]
  float *pFlexDelayedWeightsa; // [esp+11Ch] [ebp+8h]

  v3 = g_pMDLCache;
  BeginLock = g_pMDLCache->BeginLock;
  cacheCriticalSection.m_pCache = g_pMDLCache;
  BeginLock(this: g_pMDLCache);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    goto LABEL_74;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v7 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v7, mdlcache: nullptr);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
      goto LABEL_74;
  }
  if ( m_pStudioHdr == nullptr )
    goto LABEL_74;
  ++g_smodels_total;
  StudioModel::UpdateStudioRenderConfig(
    bWireframe: g_viewerSettings.renderMode == 0,
    bZBufferWireframe: false,
    bNormals: g_viewerSettings.showNormals,
    bTangentFrame: g_viewerSettings.showTangentFrame);
  v8 = this->m_pStudioHdr;
  if ( v8 == nullptr || v8->m_pStudioHdr != nullptr )
  {
    pStudioHdr = this->m_pStudioHdr;
    v10 = v8;
  }
  else
  {
    v9 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v9, mdlcache: nullptr);
    v10 = this->m_pStudioHdr;
    if ( v10->m_pStudioHdr == nullptr )
    {
LABEL_74:
      v3->EndLock(this: v3);
      return 0;
    }
    pStudioHdr = this->m_pStudioHdr;
  }
  if ( v10 == nullptr || v10->m_pStudioHdr->numbodyparts == 0 )
    goto LABEL_74;
  AngleMatrix(angles: &this->m_angles, matrix: &g_viewtransform);
  *(float *)&rdDelayedFlexWeights.m_pRenderData = this->m_origin.x * -1.0;
  *(float *)&rdDelayedFlexWeights.m_nCount = this->m_origin.y * -1.0;
  *(float *)&rdDelayedFlexWeights.m_bNeedsUnlock = this->m_origin.z * -1.0;
  MatrixSetColumn(in: (const Vector *)&rdDelayedFlexWeights.m_pRenderData, column: 3, out: &g_viewtransform);
  vecModelOrigin.x = this->m_origin.x * -1.0;
  vecModelOrigin.y = this->m_origin.y * -1.0;
  vecModelOrigin.z = this->m_origin.z * -1.0;
  MatrixSetColumn(in: &vecModelOrigin, column: 3, out: &g_viewtransform);
  rdDelayedFlexWeights.m_pRenderData = (float *)1065353216;
  rdDelayedFlexWeights.m_nCount = 0;
  *(_DWORD *)&rdDelayedFlexWeights.m_bNeedsUnlock = 0;
  rdFlexWeights.m_pRenderData = nullptr;
  rdFlexWeights.m_nCount = 0;
  *(_DWORD *)&rdFlexWeights.m_bNeedsUnlock = 1065353216;
  zero[1] = 0.0;
  zero[2] = 1.0;
  zero[3] = 0.0;
  ((void (__thiscall *)(IStudioRender *, Vector *, float *, float **, float **, int))g_pStudioRender->SetViewState)(
    a1: g_pStudioRender,
    a2: &vec3_origin,
    a3: &zero[1],
    a4: &rdFlexWeights.m_pRenderData,
    a5: &rdDelayedFlexWeights.m_pRenderData,
    a6: a2);
  this->SetUpBones(this, a2: (bool)mergeBones);
  StudioModel::SetupLighting(this, a2: (int)this);
  StudioModel::SetViewTarget(this, a2: COERCE_FLOAT(&savedregs), a3: (int)v10, a4: (int)this);
  m_pRenderData = nullptr;
  for ( j = 0; j < v10->m_pStudioHdr->numflexdesc; ++j )
    g_flexdescweight[j] = 0.0;
  this->RunFlexRules(this);
  d = 0.80000001;
  pFlexDelayedWeights = this->m_dt;
  if ( pFlexDelayedWeights != 0.0 )
  {
    __libm_sse2_log(x: v56);
    __libm_sse2_exp(x: v57);
    d = (float)((float)0.800000011920929 * 30.30303) * pFlexDelayedWeights;
  }
  GetRenderContext = g_pMaterialSystem->GetRenderContext;
  pFlexWeights = nullptr;
  pFlexDelayedWeightsa = nullptr;
  v14 = GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = v14;
  if ( v14 != nullptr )
    v14->BeginRender(this: v14);
  numflexdesc = v10->m_pStudioHdr->numflexdesc;
  rdFlexWeights.m_pRenderData = nullptr;
  rdFlexWeights.m_bNeedsUnlock = false;
  rdDelayedFlexWeights.m_bNeedsUnlock = false;
  i = numflexdesc;
  if ( numflexdesc != 0 )
  {
    v16 = (float *)pRenderContext.m_pObject->LockRenderData(this: pRenderContext.m_pObject, a2: 4 * numflexdesc);
    v17 = pRenderContext.m_pObject->__vftable;
    rdFlexWeights.m_pRenderData = v16;
    pFlexWeights = v16;
    LockRenderData = v17->LockRenderData;
    rdFlexWeights.m_bNeedsUnlock = true;
    v19 = (float *)LockRenderData(this: pRenderContext.m_pObject, a2: 4 * numflexdesc);
    v20 = d;
    m_pRenderData = v19;
    v21 = 0;
    rdDelayedFlexWeights.m_pRenderData = v19;
    rdDelayedFlexWeights.m_bNeedsUnlock = true;
    pFlexDelayedWeightsa = v19;
    if ( numflexdesc >= 4 )
    {
      v22 = rdFlexWeights.m_pRenderData + 3;
      v62 = (char *)((char *)rdFlexWeights.m_pRenderData - (char *)v19);
      v63 = (char *)((char *)g_flexdescweight - (char *)v19);
      LODWORD(d) = (char *)g_flexdescweight2 - (char *)v19;
      v64 = (char *)(&unk_604FA4 - (_UNKNOWN *)v19);
      v61 = (char *)(&unk_605FA4 - (_UNKNOWN *)v19);
      nCount = &unk_604FA8 - (_UNKNOWN *)v19;
      v23 = 1.0 - v20;
      v24 = v19 + 1;
      v25 = (char *)(&unk_605FA8 - (_UNKNOWN *)m_pRenderData);
      do
      {
        v26 = g_flexdescweight[v21];
        v27 = v63;
        g_flexdescweight2[v21] = (float)(v23 * v26) + (float)(v20 * g_flexdescweight2[v21]);
        *(v22 - 3) = v26;
        *(v24 - 1) = g_flexdescweight2[v21];
        v28 = *(float *)((char *)v24 + (_DWORD)v27);
        *(float *)((char *)v24 + LODWORD(d)) = (float)(*(float *)((char *)v24 + LODWORD(d)) * v20) + (float)(v23 * v28);
        *(float *)((char *)v24 + (_DWORD)v62) = v28;
        v29 = v64;
        *v24 = *(float *)((char *)v24 + LODWORD(d));
        v30 = *(float *)((char *)v24 + (_DWORD)v29);
        v31 = v61;
        *(float *)((char *)v24 + (_DWORD)v61) = (float)(v23 * v30)
                                              + (float)(v20 * *(float *)((char *)v24 + (_DWORD)v61));
        *(v22 - 1) = v30;
        v32 = *(float *)((char *)v24 + (_DWORD)v31);
        v33 = nCount;
        v24[1] = v32;
        v34 = *(float *)((char *)v24 + v33);
        v35 = i;
        *(float *)((char *)v24 + (_DWORD)v25) = (float)(*(float *)((char *)v24 + (_DWORD)v25) * v20)
                                              + (float)(v23 * v34);
        *v22 = v34;
        v24[2] = *(float *)((char *)v24 + (_DWORD)v25);
        v21 += 4;
        v24 += 4;
        v22 += 4;
      }
      while ( v21 < v35 - 3 );
      m_pRenderData = rdDelayedFlexWeights.m_pRenderData;
      numflexdesc = i;
    }
    if ( v21 < numflexdesc )
    {
      v36 = (char *)rdFlexWeights.m_pRenderData - (char *)g_flexdescweight;
      do
      {
        v37 = g_flexdescweight[v21];
        g_flexdescweight2[v21] = (float)(v37 * (float)(1.0 - v20)) + (float)(v20 * g_flexdescweight2[v21]);
        *(float *)((char *)&g_flexdescweight[v21] + v36) = v37;
        m_pRenderData[v21] = g_flexdescweight2[v21];
        ++v21;
      }
      while ( v21 < numflexdesc );
    }
  }
  ((void (__cdecl *)(int))g_pStudioRender->SetAlphaModulation)(a1: 1065353216);
  materialIndex = nullptr;
  g_bDrawModelInfoValid = true;
  memset(dst: (unsigned __int8 *)&g_DrawModelInfo, value: 0, count: sizeof(g_DrawModelInfo));
  g_DrawModelInfo.m_pStudioHdr = (studiohdr_t *)pStudioHdr->m_pStudioHdr;
  g_DrawModelInfo.m_pHardwareData = (studiohwdata_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: this->m_MDLHandle);
  if ( g_DrawModelInfo.m_pHardwareData == nullptr )
  {
    m_pObject = pRenderContext.m_pObject;
    if ( pRenderContext.m_pObject != nullptr )
    {
      if ( m_pRenderData != nullptr )
      {
        v40 = pRenderContext.m_pObject->__vftable;
        if ( rdDelayedFlexWeights.m_bNeedsUnlock )
          v40->UnlockRenderData(this: pRenderContext.m_pObject, a2: m_pRenderData);
        else
          v40->ReleaseRenderData(this: pRenderContext.m_pObject);
      }
      if ( rdFlexWeights.m_pRenderData != nullptr )
      {
        v41 = m_pObject->__vftable;
        if ( rdFlexWeights.m_bNeedsUnlock )
          v41->UnlockRenderData(this: m_pObject, a2: rdFlexWeights.m_pRenderData);
        else
          v41->ReleaseRenderData(this: m_pObject);
      }
      m_pObject->EndRender(this: m_pObject);
      m_pObject->Release(this: m_pObject);
    }
    cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
    return 0;
  }
  g_DrawModelInfo.m_Decals = nullptr;
  g_DrawModelInfo.m_Skin = this->m_skinnum;
  g_DrawModelInfo.m_Body = this->m_bodynum;
  g_DrawModelInfo.m_HitboxSet = MDLViewer::GetCurrentHitboxSet(this: g_MDLViewer);
  g_DrawModelInfo.m_pClientEntity = nullptr;
  if ( g_viewerSettings.autoLOD )
    g_DrawModelInfo.m_Lod = -1;
  else
    g_DrawModelInfo.m_Lod = g_viewerSettings.lod;
  g_DrawModelInfo.m_pColorMeshes = nullptr;
  if ( g_viewerSettings.renderMode == 4 )
  {
    DebugDrawModelBadVerts(
      a1: (int)&savedregs,
      a2: 0,
      a3: (int)this,
      pStudioRender: g_pStudioRender,
      info: &g_DrawModelInfo,
      pBoneToWorld: this->m_pBoneToWorld);
    m_pBoneToWorld = this->m_pBoneToWorld;
    zero[1] = 0.2;
    zero[2] = 0.2;
    zero[3] = 0.2;
    DebugDrawModelWireframe(
      pStudioRender: g_pStudioRender,
      info: &g_DrawModelInfo,
      pBoneToWorld: m_pBoneToWorld,
      modelOrigin: &vecModelOrigin,
      color: (const Vector *)&zero[1]);
    g_DrawModelInfo.m_Lod = this->m_LodUsed;
    g_pStudioRender->GetPerfStats(this: g_pStudioRender, a2: &g_DrawModelResults, a3: &g_DrawModelInfo, a4: nullptr);
  }
  else
  {
    switch ( g_viewerSettings.renderMode )
    {
      case 3:
        DebugDrawModelBoneWeights(
          pStudioRender: g_pStudioRender,
          info: &g_DrawModelInfo,
          pBoneToWorld: this->m_pBoneToWorld);
        v54 = this->m_pBoneToWorld;
        v52 = g_pStudioRender;
        break;
      case 5:
        m_pLODs = g_DrawModelInfo.m_pHardwareData->m_pLODs;
        v44 = WindowName;
        if ( m_pLODs != nullptr )
        {
          materialIndex = (float *)g_viewerSettings.materialIndex;
          if ( g_viewerSettings.materialIndex < m_pLODs->numMaterials )
          {
            v45 = m_pLODs->ppMaterials[g_viewerSettings.materialIndex];
            v44 = (const char *)v45->GetName(this: v45);
          }
        }
        DebugDrawModelTexCoord(
          pStudioRender: g_pStudioRender,
          pMaterialName: v44,
          info: &g_DrawModelInfo,
          pBoneToWorld: this->m_pBoneToWorld,
          w: (float)g_viewerSettings.width,
          h: (float)g_viewerSettings.height);
        g_pStudioRender->GetPerfStats(this: g_pStudioRender, a2: &g_DrawModelResults, a3: &g_DrawModelInfo, a4: nullptr);
        this->m_LodUsed = g_DrawModelInfo.m_Lod;
        goto LABEL_57;
      case 6:
        DebugDrawModelVertColocation(
          a1: 0,
          pStudioRender: g_pStudioRender,
          info: &g_DrawModelInfo,
          pBoneToWorld: this->m_pBoneToWorld);
        v54 = this->m_pBoneToWorld;
        v52 = g_pStudioRender;
        break;
      default:
        materialIndex = pFlexWeights;
        g_pStudioRender->DrawModel(
          this: g_pStudioRender,
          a2: &g_DrawModelResults,
          a3: &g_DrawModelInfo,
          a4: this->m_pBoneToWorld,
          a5: pFlexWeights,
          a6: pFlexDelayedWeightsa,
          a7: &vecModelOrigin,
          a8: 0);
        this->m_LodUsed = g_DrawModelResults.m_nLODUsed;
        this->m_LodMetric = (float)g_DrawModelResults.m_flLODMetric;
        g_pStudioRender->GetPerfStats(this: g_pStudioRender, a2: &g_DrawModelResults, a3: &g_DrawModelInfo, a4: nullptr);
        if ( g_viewerSettings.overlayWireframe && g_viewerSettings.renderMode != 0 )
        {
          StudioModel::UpdateStudioRenderConfig(
            bWireframe: true,
            bZBufferWireframe: true,
            bNormals: false,
            bTangentFrame: false);
          g_pStudioRender->DrawModel(
            this: g_pStudioRender,
            a2: nullptr,
            a3: &g_DrawModelInfo,
            a4: this->m_pBoneToWorld,
            a5: materialIndex,
            a6: pFlexDelayedWeightsa,
            a7: &vecModelOrigin,
            a8: 0);
          StudioModel::UpdateStudioRenderConfig(
            bWireframe: g_viewerSettings.renderMode == 0,
            bZBufferWireframe: false,
            bNormals: g_viewerSettings.showNormals,
            bTangentFrame: g_viewerSettings.showTangentFrame);
        }
        goto LABEL_57;
    }
    zero[3] = 0.2;
    zero[2] = 0.2;
    zero[1] = 0.2;
    DebugDrawModelWireframe(
      pStudioRender: v52,
      info: &g_DrawModelInfo,
      pBoneToWorld: v54,
      modelOrigin: &vecModelOrigin,
      color: (const Vector *)&zero[1]);
    g_pStudioRender->GetPerfStats(this: g_pStudioRender, a2: &g_DrawModelResults, a3: &g_DrawModelInfo, a4: nullptr);
    this->m_LodUsed = g_DrawModelInfo.m_Lod;
  }
LABEL_57:
  nCount = g_DrawModelResults.m_ActualTriCount;
  StudioModel::DrawBones(this, a2: (int)materialIndex, a3: (int)this);
  StudioModel::DrawAttachments(this, a2: (int)materialIndex, a3: (int)this);
  StudioModel::DrawOriginAxis(this, a2: (int)materialIndex, a3: (int)this);
  StudioModel::DrawEditAttachment(this);
  StudioModel::DrawHitboxes(this);
  StudioModel::DrawPhysicsModel(this);
  StudioModel::DrawIllumPosition(this);
  if ( g_viewerSettings.showShadow && g_viewerSettings.showGround )
  {
    MatrixInvert(in: &g_viewtransform, out: &invViewTransform);
    v46 = pStudioHdr->m_pStudioHdr;
    i = 0;
    if ( v46->numbones > 0 )
    {
      d = 0.0;
      do
      {
        v47 = (matrix3x4a_t *)((char *)this->m_pBoneToWorld + LODWORD(d));
        ConcatTransforms(in1: &invViewTransform, in2: v47, out: &tmp1);
        *(_QWORD *)&tmp1.m_flMatVal[2][0] = 0;
        *(_QWORD *)&tmp1.m_flMatVal[2][2] = 0x3D4CCCCD00000000LL;
        ConcatTransforms(in1: &g_viewtransform, in2: &tmp1, out: v47);
        v48 = pStudioHdr->m_pStudioHdr;
        LODWORD(d) += 48;
        ++i;
      }
      while ( i < v48->numbones );
    }
    g_DrawModelInfo.m_Lod = *(_DWORD *)(((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: this->m_MDLHandle)
                                      + 4)
                          - 1;
    memset(zero, 0, sizeof(zero));
    g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: zero);
    g_pStudioRender->ForcedMaterialOverride(this: g_pStudioRender, a2: g_materialShadow, a3: OVERRIDE_NORMAL);
    StudioModel::UpdateStudioRenderConfig(
      bWireframe: false,
      bZBufferWireframe: false,
      bNormals: false,
      bTangentFrame: false);
    g_pStudioRender->DrawModel(
      this: g_pStudioRender,
      a2: nullptr,
      a3: &g_DrawModelInfo,
      a4: this->m_pBoneToWorld,
      a5: pFlexWeights,
      a6: pFlexDelayedWeightsa,
      a7: &vecModelOrigin,
      a8: 0);
    StudioModel::UpdateStudioRenderConfig(
      bWireframe: g_viewerSettings.renderMode == 0,
      bZBufferWireframe: false,
      bNormals: g_viewerSettings.showNormals,
      bTangentFrame: g_viewerSettings.showTangentFrame);
    g_pStudioRender->ForcedMaterialOverride(this: g_pStudioRender, a2: nullptr, a3: OVERRIDE_NORMAL);
    one[0] = 1.0;
    one[1] = 1.0;
    one[2] = 1.0;
    one[3] = 1.0;
    g_pStudioRender->SetColorModulation(this: g_pStudioRender, a2: one);
  }
  v49 = pRenderContext.m_pObject;
  if ( pRenderContext.m_pObject != nullptr )
  {
    if ( m_pRenderData != nullptr )
    {
      v50 = pRenderContext.m_pObject->__vftable;
      if ( rdDelayedFlexWeights.m_bNeedsUnlock )
        v50->UnlockRenderData(this: pRenderContext.m_pObject, a2: m_pRenderData);
      else
        v50->ReleaseRenderData(this: pRenderContext.m_pObject);
    }
    if ( rdFlexWeights.m_pRenderData != nullptr )
    {
      v51 = v49->__vftable;
      if ( rdFlexWeights.m_bNeedsUnlock )
        v51->UnlockRenderData(this: v49, a2: rdFlexWeights.m_pRenderData);
      else
        v51->ReleaseRenderData(this: v49);
    }
    v49->EndRender(this: v49);
    v49->Release(this: v49);
  }
  cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
  return nCount;
}

//------------------------------------------------------------------------------
// Address: 0x00425990
// Name: public: void StudioModel::ClearLookTargets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::ClearLookTargets(StudioModel *this)
{
  this->m_vecHeadTargets.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00425A20
// Name: public: void StudioModel::AddLookTarget(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StudioModel::AddLookTarget(StudioModel *this, const Vector *vecPosition, float flWeight)
{
  int m_Size; // edx
  StudioLookTarget tmp; // [esp+0h] [ebp-14h] BYREF

  if ( this->m_vecHeadTargets.m_Size <= 8 )
  {
    m_Size = this->m_vecHeadTargets.m_Size;
    tmp.m_flWeight = flWeight;
    tmp.m_vecPosition = *vecPosition;
    tmp.m_bSelf = false;
    CUtlVector<StudioLookTarget,CUtlMemory<StudioLookTarget,int>>::InsertBefore(
      this: &this->m_vecHeadTargets,
      elem: m_Size,
      src: &tmp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425A80
// Name: public: virtual void StudioModel::SetUpBones(bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge StudioModel::SetUpBones(
        StudioModel *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        bool mergeBones)
{
  void *v5; // esp
  unsigned int v6; // eax
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v9; // eax
  CStudioHdr *v10; // edi
  int m_sequence; // eax
  float v12; // ecx
  matrix3x4_t *v13; // eax
  DWORD TickCount; // eax
  int v15; // ecx
  int (__thiscall *BoneMask)(StudioModel *); // edx
  int v17; // eax
  StudioModel_vtbl *v18; // edx
  int v19; // eax
  DWORD v20; // eax
  int v21; // ecx
  int v22; // edx
  int v23; // ecx
  int NumSeq_Internal; // eax
  float v25; // xmm0_4
  double RealtimeTime; // st7
  int m_prevsequence; // edx
  const Quaternion *v28; // eax
  int *p_m_priority; // ecx
  int i; // edi
  int v31; // eax
  float *p_m_weight; // edi
  DWORD v33; // eax
  int v34; // ecx
  int v35; // edx
  int v36; // ecx
  int v37; // eax
  DWORD v38; // eax
  int v39; // ecx
  CIKContext *v40; // edi
  matrix3x4a_t *m_pBoneToWorld; // edx
  bool v42; // cc
  int v43; // edi
  float v44; // xmm0_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  float v47; // xmm3_4
  float v48; // edi
  int v49; // eax
  int v50; // ecx
  int v51; // eax
  int v52; // edi
  matrix3x4a_t *v53; // edx
  int v54; // eax
  matrix3x4a_t *v55; // edx
  matrix3x4a_t *v56; // edx
  matrix3x4a_t *v57; // edx
  matrix3x4a_t *v58; // edx
  matrix3x4a_t *v59; // edx
  matrix3x4a_t *v60; // edx
  matrix3x4a_t *v61; // edx
  matrix3x4a_t *v62; // edx
  matrix3x4a_t *v63; // edx
  matrix3x4a_t *v64; // edx
  float v65; // edi
  int v66; // eax
  int v67; // ecx
  int v68; // edi
  int v69; // eax
  int v70; // eax
  int v71; // ecx
  CJiggleBones *v72; // eax
  UtlLinkedListElem_t<JiggleData,unsigned short> *m_pMemory; // edx
  DWORD v74; // eax
  int v75; // ecx
  unsigned int v76; // edi
  float v77; // xmm0_4
  CJiggleBones *m_pJiggleBones; // ecx
  int v79; // eax
  matrix3x4a_t *v80; // edx
  const matrix3x4_t *v81; // eax
  CStudioHdr *v82; // edx
  float v83; // eax
  const studiohdr_t *v84; // ecx
  int v85; // edi
  const char *v86; // eax
  int v87; // eax
  bool v88; // zf
  ikcontextikrule_t *v89; // eax
  CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *v90; // eax
  CIKContext v93; // [esp+20h] [ebp-12CCh] BYREF
  bool v94[256]; // [esp+1098h] [ebp-254h] BYREF
  Vector v95; // [esp+1198h] [ebp-154h] BYREF
  QAngle v96; // [esp+11A4h] [ebp-148h] BYREF
  matrix3x4_t v97; // [esp+11B0h] [ebp-13Ch] BYREF
  CBoneBitList v98; // [esp+11E0h] [ebp-10Ch] BYREF
  matrix3x4_t v99; // [esp+1200h] [ebp-ECh] BYREF
  QAngle v100; // [esp+1230h] [ebp-BCh] BYREF
  float v101[4]; // [esp+123Ch] [ebp-B0h] BYREF
  Vector v102; // [esp+124Ch] [ebp-A0h] BYREF
  Vector v103; // [esp+1258h] [ebp-94h] BYREF
  Vector v104; // [esp+1264h] [ebp-88h] BYREF
  Quaternion v105; // [esp+1270h] [ebp-7Ch] BYREF
  Vector v106; // [esp+1280h] [ebp-6Ch] BYREF
  float v107[4]; // [esp+128Ch] [ebp-60h] BYREF
  float v108[2]; // [esp+129Ch] [ebp-50h] BYREF
  float v109; // [esp+12A4h] [ebp-48h]
  Vector v110; // [esp+12A8h] [ebp-44h] BYREF
  int v111; // [esp+12B4h] [ebp-38h]
  int v112; // [esp+12B8h] [ebp-34h]
  int v113; // [esp+12BCh] [ebp-30h]
  float v114; // [esp+12C0h] [ebp-2Ch]
  const Quaternion *v115; // [esp+12C4h] [ebp-28h]
  unsigned int v116; // [esp+12C8h] [ebp-24h]
  IBoneSetup cycle; // [esp+12CCh] [ebp-20h] BYREF
  float flTime; // [esp+12D0h] [ebp-1Ch]
  float flRealTime; // [esp+12D4h] [ebp-18h]
  int flLength; // [esp+12D8h] [ebp-14h]
  int p_m_ik; // [esp+12DCh] [ebp-10h]
  int v122; // [esp+12E0h] [ebp-Ch]
  void *v123; // [esp+12E4h] [ebp-8h]
  int v124; // [esp+12E8h] [ebp-4h] BYREF
  void *retaddr; // [esp+12ECh] [ebp+0h]

  v122 = a2;
  v123 = retaddr;
  v5 = alloca(4808);
  v6 = _S1_1;
  if ( (_S1_1 & 1) == 0 )
  {
    v6 = _S1_1 | 1;
    _S1_1 |= 1u;
  }
  if ( (v6 & 2) == 0 )
  {
    v6 |= 2u;
    _S1_1 = v6;
  }
  if ( (v6 & 4) == 0 )
  {
    v6 |= 4u;
    _S1_1 = v6;
  }
  if ( (v6 & 8) == 0 )
  {
    v6 |= 8u;
    _S1_1 = v6;
  }
  if ( (v6 & 0x10) == 0 )
    _S1_1 = v6 | 0x10;
  m_pStudioHdr = this->m_pStudioHdr;
  if ( *(float *)&m_pStudioHdr == 0.0 || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    flRealTime = *(float *)&this->m_pStudioHdr;
    v10 = m_pStudioHdr;
  }
  else
  {
    v9 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v9, mdlcache: nullptr);
    v10 = this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
    flRealTime = *(float *)&v10;
  }
  m_sequence = this->m_sequence;
  if ( v10->m_pVModel != nullptr )
  {
    v13 = (matrix3x4_t *)CStudioHdr::pSeqdesc_Internal(this: v10, i: this->m_sequence);
  }
  else
  {
    v12 = *(float *)&v10->m_pStudioHdr;
    if ( m_sequence < 0 || m_sequence >= *(_DWORD *)(LODWORD(v12) + 188) )
      m_sequence = 0;
    v13 = (matrix3x4_t *)(LODWORD(v12) + *(_DWORD *)(LODWORD(v12) + 192) + 212 * m_sequence);
  }
  flLength = (int)v13;
  MatrixAngles(matrix: &g_viewtransform, angles: &v100.x);
  v106.x = g_viewtransform.m_flMatVal[0][3];
  v106.y = g_viewtransform.m_flMatVal[1][3];
  v106.z = g_viewtransform.m_flMatVal[2][3];
  p_m_ik = 0;
  TickCount = GetTickCount();
  v15 = g_prevTicksRT;
  if ( g_prevTicksRT == 0 )
    v15 = TickCount;
  g_prevTicksRT = TickCount;
  BoneMask = this->BoneMask;
  g_timeRT = (float)((float)(int)(TickCount - v15) * 0.001) + g_timeRT;
  v114 = g_timeRT;
  v17 = ((int (__thiscall *)(StudioModel *, int, int))BoneMask)(a1: this, a2: a3, a3: a4);
  CIKContext::Init(
    this: &this->m_ik,
    pStudioHdr: v10,
    angles: &v100,
    pos: &v106,
    flTime: v114,
    iFramecounter: this->m_iFramecounter,
    boneMask: v17);
  if ( g_viewerSettings.enableIK )
    p_m_ik = (int)&this->m_ik;
  v18 = this->__vftable;
  flLength = 0;
  LODWORD(flRealTime) = this->m_poseparameter;
  v19 = v18->BoneMask(this);
  IBoneSetup::IBoneSetup(
    this: &cycle,
    pStudioHdr: v10,
    boneMask: v19,
    poseParameter: (const float *)LODWORD(flRealTime),
    pPoseDebugger: (IPoseDebugger *)flLength);
  IBoneSetup::InitPose(this: &cycle, pos: pos, q: (QuaternionAligned *)&q);
  v20 = GetTickCount();
  v21 = g_prevTicksRT;
  if ( g_prevTicksRT == 0 )
    v21 = v20;
  v22 = v20 - v21;
  v23 = this->m_sequence;
  g_prevTicksRT = v20;
  flLength = p_m_ik;
  g_timeRT = (float)((float)v22 * 0.001) + g_timeRT;
  flRealTime = g_timeRT;
  flTime = 1.0;
  IBoneSetup::AccumulatePose(
    this: &cycle,
    pos: pos,
    q: &q,
    sequence: v23,
    cycle: this->m_cycle,
    flWeight: 1.0,
    flTime: g_timeRT,
    pIKContext: (CIKContext *)p_m_ik);
  if ( !g_viewerSettings.blendSequenceChanges
    || this->m_blendtime <= this->m_sequencetime
    || this->m_prevsequence == this->m_sequence
    || (v10->m_pVModel != nullptr
      ? (NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: v10))
      : (NumSeq_Internal = v10->m_pStudioHdr->numlocalseq),
        this->m_prevsequence >= NumSeq_Internal || (*(_BYTE *)(flLength + 12) & 2) != 0) )
  {
    this->m_prevcycle = this->m_cycle;
  }
  else
  {
    if ( this->m_prevcycle >= 1.0 )
      this->m_prevcycle = 0.0;
    v25 = 1.0 - (float)(this->m_sequencetime / this->m_blendtime);
    flLength = 0;
    v114 = v25;
    RealtimeTime = GetRealtimeTime();
    m_prevsequence = this->m_prevsequence;
    flRealTime = RealtimeTime;
    IBoneSetup::AccumulatePose(
      this: &cycle,
      pos: pos,
      q: &q,
      sequence: m_prevsequence,
      cycle: this->m_prevcycle,
      flWeight: (float)((float)(v114 * 3.0) * v114) - (float)((float)((float)(v114 * 2.0) * v114) * v114),
      flTime: flRealTime,
      pIKContext: (CIKContext *)flLength);
  }
  v28 = nullptr;
  p_m_priority = &this->m_Layer[0].m_priority;
  for ( i = 2; i != 0; --i )
  {
    if ( *((float *)p_m_priority - 2) > 0.0 && *p_m_priority > (int)v28 )
      v28 = (const Quaternion *)*p_m_priority;
    if ( *((float *)p_m_priority + 3) > 0.0 && p_m_priority[5] > (int)v28 )
      v28 = (const Quaternion *)p_m_priority[5];
    if ( *((float *)p_m_priority + 8) > 0.0 && p_m_priority[10] > (int)v28 )
      v28 = (const Quaternion *)p_m_priority[10];
    if ( *((float *)p_m_priority + 13) > 0.0 && p_m_priority[15] > (int)v28 )
      v28 = (const Quaternion *)p_m_priority[15];
    p_m_priority += 20;
  }
  v115 = v28;
  flTime = 0.0;
  if ( (int)v28 >= 0 )
  {
    *(float *)&v31 = 0.0;
    do
    {
      p_m_weight = &this->m_Layer[0].m_weight;
      for ( flLength = 8; flLength != 0; --flLength )
      {
        if ( *((_DWORD *)p_m_weight + 2) == v31 && *p_m_weight > 0.0 )
        {
          v33 = GetTickCount();
          v34 = g_prevTicksRT;
          if ( g_prevTicksRT == 0 )
            v34 = v33;
          v35 = v33 - v34;
          v36 = *((_DWORD *)p_m_weight - 1);
          g_prevTicksRT = v33;
          flLength = p_m_ik;
          g_timeRT = (float)((float)v35 * 0.001) + g_timeRT;
          flRealTime = g_timeRT;
          IBoneSetup::AccumulatePose(
            this: &cycle,
            pos: pos,
            q: &q,
            sequence: v36,
            cycle: *(p_m_weight - 2),
            flWeight: *p_m_weight,
            flTime: g_timeRT,
            pIKContext: (CIKContext *)p_m_ik);
          *(float *)&v31 = flTime;
        }
        p_m_weight += 5;
      }
      ++v31;
      flTime = *(float *)&v31;
    }
    while ( v31 <= (int)v115 );
  }
  if ( this->m_nSolveHeadTurn != 0 )
    StudioModel::GetBodyPoseParametersFromFlex(this);
  StudioModel::CalcHeadRotation(this, pos: pos, q: &q);
  CIKContext::CIKContext(this: &v93);
  v37 = this->BoneMask(this);
  CIKContext::Init(
    this: &v93,
    pStudioHdr: (const CStudioHdr *)LODWORD(flRealTime),
    angles: &v100,
    pos: &v106,
    flTime: 0.0,
    iFramecounter: 0,
    boneMask: v37);
  v38 = GetTickCount();
  v39 = dword_7C7264;
  if ( dword_7C7264 == 0 )
    v39 = v38;
  dword_7C7264 = v38;
  *(float *)&dword_7C7260 = (float)((float)((float)(int)(v38 - v39) * 0.001) * g_viewerSettings.speedScale)
                          + *(float *)&dword_7C7260;
  IBoneSetup::CalcAutoplaySequences(
    this: &cycle,
    pos: pos,
    q: &q,
    flRealTime: *(float *)&dword_7C7260,
    pIKContext: &v93);
  IBoneSetup::CalcBoneAdj(this: &cycle, pos: pos, q: &q, controllers: this->m_controller);
  v40 = (CIKContext *)p_m_ik;
  memset(&v98, 0, sizeof(v98));
  if ( p_m_ik != 0 )
  {
    StudioModel::GetMovement(this, prevcycle: this->m_prevIKCycles, vecPos: &v110, vecAngles: &v96);
    VectorRotate(in1: &v110.x, in2: &g_viewtransform, out: &v103.x);
    m_pBoneToWorld = this->m_pBoneToWorld;
    v110 = v103;
    CIKContext::UpdateTargets(this: v40, pos: pos, q: &q, boneToWorld: m_pBoneToWorld, boneComputed: &v98);
    v42 = v40->m_target.m_Size <= 0;
    flLength = 0;
    if ( !v42 )
    {
      v43 = (int)&v40->m_target.m_Memory.m_Memory[104];
      do
      {
        if ( *(_DWORD *)(v43 - 100) == 3 )
        {
          *(float *)(v43 - 8) = *(float *)(v43 - 8) - v110.x;
          *(float *)(v43 - 4) = *(float *)(v43 - 4) - v110.y;
          v44 = *(float *)v43 - v110.z;
          flLength = (int)&v97;
          flRealTime = COERCE_FLOAT(&g_viewtransform);
          *(float *)v43 = v44;
          MatrixInvert(in: (const matrix3x4_t *)LODWORD(flRealTime), out: (matrix3x4_t *)flLength);
          VectorTransform(in1: (const float *)(v43 - 8), in2: &v97, out: v108);
          v109 = *(float *)(v43 - 24);
          VectorTransform(in1: v108, in2: &g_viewtransform, out: (float *)(v43 - 8));
          MatrixAngles(matrix: &g_viewtransform, q: &v105, pos: &v95);
          v45 = *(float *)(v43 - 36);
          *(Quaternion *)(v43 + 4) = v105;
          memset(v101, 0, sizeof(v101));
          v107[2] = 0.0;
          v46 = 1.0 - *(float *)(v43 - 12);
          v107[0] = 1.0;
          v107[1] = 1.0;
          v107[3] = 1.0;
          if ( v45 <= 0.0 )
            v107[0] = v46;
          else
            v107[1] = v46;
          v47 = *(float *)(v43 - 20);
          if ( v47 <= 1.0 )
            v47 = 1.0;
          v104.x = COERCE_FLOAT(LODWORD(v47) ^ _mask__NegFloat_) + v108[0];
          v104.y = COERCE_FLOAT(LODWORD(v47) ^ _mask__NegFloat_) + v108[1];
          v104.z = v109;
          v102.x = v108[0] + v47;
          v102.y = v108[1] + v47;
          v102.z = v109;
          StudioModel::drawTransparentBox(
            this,
            a2: (int)&v124,
            a3: v43,
            a4: (int)this,
            bbmin: &v104,
            bbmax: &v102,
            m: &g_viewtransform,
            color: v101,
            wirecolor: v107);
          if ( !g_viewerSettings.enableTargetIK )
            *(_DWORD *)(v43 - 12) = 0;
        }
        else if ( *(_DWORD *)(v43 - 100) == 5 )
        {
          QuaternionMatrix(q: (const Quaternion *)(v43 + 4), pos: (const Vector *)(v43 - 8), matrix: &v97);
          StudioModel::drawTransform(
            this,
            p_meshBuilder: (CMeshBuilder *)&v124,
            m_nIndexCount: v43,
            m: &v97,
            flLength: g_viewerSettings.originAxisLength * 0.40000001);
        }
        v43 += 340;
        ++flLength;
      }
      while ( flLength < *(_DWORD *)(p_m_ik + 4080) );
      v40 = (CIKContext *)p_m_ik;
    }
    CIKContext::SolveDependencies(this: v40, pos: pos, q: &q, boneToWorld: this->m_pBoneToWorld, boneComputed: &v98);
  }
  v48 = flRealTime;
  v49 = *(_DWORD *)LODWORD(flRealTime);
  v50 = *(_DWORD *)(*(_DWORD *)LODWORD(flRealTime) + 160);
  flLength = *(_DWORD *)(*(_DWORD *)LODWORD(flRealTime) + 156);
  LODWORD(v114) = v49 + v50;
  memset(dst: (unsigned __int8 *)v94, value: 0, count: flLength);
  if ( g_viewerSettings.showPhysicsPreview )
    StudioModel::OverrideBones(this, a2: (int)this, override: v94);
  v51 = *(_DWORD *)LODWORD(v48);
  v112 = 0;
  if ( *(int *)(v51 + 156) > 0 )
  {
    v116 = 0;
    v113 = 0;
    flLength = (int)&pos[0].y;
    v115 = &q;
    v111 = 12;
    do
    {
      v52 = v51 + v113 + *(_DWORD *)(v51 + 160);
      if ( (this->BoneMask(this) & *(_DWORD *)(v52 + 160)) != 0 )
      {
        if ( !v94[v112] )
        {
          if ( ((1 << (v112 & 0x1F)) & v98.m_Ints[(unsigned int)v112 >> 5]) != 0 )
          {
            v76 = v116;
          }
          else
          {
            v64 = this->m_pBoneToWorld;
            v65 = flRealTime;
            v105.x = 0.0;
            LODWORD(v105.y) = v64;
            if ( CalcProceduralBone(
                   pStudioHdr: (const CStudioHdr *)LODWORD(flRealTime),
                   iBone: v112,
                   bonetoworld: (CBoneAccessor *)&v105) )
            {
              goto LABEL_122;
            }
            QuaternionMatrix(q: v115, matrix: &v99);
            v99.m_flMatVal[0][3] = *(float *)(flLength - 4);
            v99.m_flMatVal[1][3] = *(float *)flLength;
            v99.m_flMatVal[2][3] = *(float *)(flLength + 4);
            v66 = *(_DWORD *)LODWORD(v65);
            v67 = *(_DWORD *)(*(_DWORD *)LODWORD(v65) + 160);
            v68 = v113;
            if ( (*(_BYTE *)(v113 + v67 + v66 + 160) & 4) != 0
              && (*(_BYTE *)(v113 + *(_DWORD *)(v66 + 160) + v66 + 164) & 5) != 0 )
            {
              v69 = *(_DWORD *)(v113 + LODWORD(v114) + 4);
              flLength = (int)&v97;
              flRealTime = COERCE_FLOAT(&v99);
              if ( v69 == -1 )
                flTime = COERCE_FLOAT(&g_viewtransform);
              else
                LODWORD(flTime) = &this->m_pBoneToWorld[v69];
              ConcatTransforms(
                in1: (const matrix3x4_t *)LODWORD(flTime),
                in2: (const matrix3x4_t *)LODWORD(flRealTime),
                out: (matrix3x4_t *)flLength);
              v70 = *(_DWORD *)LODWORD(flRealTime) + v68 + *(_DWORD *)(*(_DWORD *)LODWORD(flRealTime) + 160);
              v71 = *(_DWORD *)(v70 + 168);
              if ( v71 != 0 )
                LODWORD(flTime) = v70 + v71;
              else
                flTime = 0.0;
              if ( this->m_pJiggleBones == nullptr )
              {
                v72 = (CJiggleBones *)operator new(nSize: 0x1Cu);
                if ( v72 != nullptr )
                {
                  v72->m_jiggleBoneState.m_Memory.m_pMemory = nullptr;
                  v72->m_jiggleBoneState.m_Memory.m_nAllocationCount = 0;
                  v72->m_jiggleBoneState.m_Memory.m_nGrowSize = 0;
                  v72->m_jiggleBoneState.m_LastAlloc.index = -1;
                  *(_DWORD *)&v72->m_jiggleBoneState.m_FirstFree = 0xFFFF;
                  m_pMemory = v72->m_jiggleBoneState.m_Memory.m_pMemory;
                  *(_DWORD *)&v72->m_jiggleBoneState.m_Head = -1;
                  v72->m_jiggleBoneState.m_NumAlloced = 0;
                  v72->m_jiggleBoneState.m_pElements = m_pMemory;
                }
                else
                {
                  v72 = nullptr;
                }
                this->m_pJiggleBones = v72;
              }
              v74 = GetTickCount();
              v75 = g_prevTicksRT;
              v76 = v116;
              if ( g_prevTicksRT == 0 )
                v75 = v74;
              g_prevTicksRT = v74;
              flLength = (int)&this->m_pBoneToWorld[v116 / 0x30];
              v77 = (float)((float)(int)(v74 - v75) * 0.001) + g_timeRT;
              flRealTime = COERCE_FLOAT(&v97);
              cycle.m_pBoneSetup = (CBoneSetup *)&v97;
              m_pJiggleBones = this->m_pJiggleBones;
              g_timeRT = v77;
              CJiggleBones::BuildJiggleTransformations(
                this: m_pJiggleBones,
                boneIndex: v112,
                currenttime: v77,
                jiggleInfo: flTime,
                goalMX: &v97,
                boneMX: (matrix3x4_t *)flLength);
            }
            else
            {
              v79 = *(_DWORD *)(v113 + LODWORD(v114) + 4);
              v76 = v116;
              if ( v79 == -1 )
                ConcatTransforms(in1: &g_viewtransform, in2: &v99, out: &this->m_pBoneToWorld[v116 / 0x30]);
              else
                ConcatTransforms(in1: &this->m_pBoneToWorld[v79], in2: &v99, out: &this->m_pBoneToWorld[v116 / 0x30]);
            }
          }
          if ( mergeBones )
          {
            v82 = g_pCacheHdr;
            v83 = 0.0;
            if ( g_pCacheHdr == nullptr )
              goto LABEL_122;
            v84 = g_pCacheHdr->m_pStudioHdr;
            flTime = 0.0;
            if ( v84->numbones > 0 )
            {
              v85 = v113;
              p_m_ik = 0;
              do
              {
                v86 = (const char *)(*(_DWORD *)LODWORD(flRealTime)
                                   + v85
                                   + *(_DWORD *)(*(_DWORD *)LODWORD(flRealTime) + 160));
                v87 = _V_stricmp(
                        s1: &v86[*(_DWORD *)v86],
                        s2: (const char *)v84
                      + p_m_ik
                      + v84->boneindex
                      + *(int *)((char *)&v84->id + p_m_ik + v84->boneindex));
                v82 = g_pCacheHdr;
                v88 = v87 == 0;
                v83 = flTime;
                if ( v88 )
                  break;
                v84 = g_pCacheHdr->m_pStudioHdr;
                p_m_ik += 216;
                LODWORD(v83) = LODWORD(flTime) + 1;
                flTime = v83;
              }
              while ( SLODWORD(v83) < v84->numbones );
            }
            if ( SLODWORD(v83) >= v82->m_pStudioHdr->numbones )
              goto LABEL_122;
            v80 = &this->m_pBoneToWorld[v116 / 0x30];
            v81 = &boneCache[LODWORD(v83)];
          }
          else
          {
            g_pCacheHdr = (CStudioHdr *)LODWORD(flRealTime);
            v80 = (matrix3x4a_t *)((char *)boneCache + v76);
            v81 = (matrix3x4a_t *)((char *)this->m_pBoneToWorld + v76);
          }
          MatrixCopy(in: v81, out: v80);
        }
      }
      else
      {
        v53 = this->m_pBoneToWorld;
        v54 = v111;
        p_m_ik = 2143289344;
        v53->m_flMatVal[0][v111 / 4u - 3] = NAN;
        v55 = this->m_pBoneToWorld;
        p_m_ik = 2143289344;
        *(float *)((char *)&v55->m_flMatVal[0][-2] + v54) = NAN;
        v56 = this->m_pBoneToWorld;
        p_m_ik = 2143289344;
        *(float *)((char *)&v56->m_flMatVal[0][-1] + v54) = NAN;
        v57 = this->m_pBoneToWorld;
        p_m_ik = 2143289344;
        *(float *)((char *)v57->m_flMatVal[0] + v54) = NAN;
        v58 = this->m_pBoneToWorld;
        p_m_ik = 2143289344;
        *(float *)((char *)&v58->m_flMatVal[0][1] + v54) = NAN;
        v59 = this->m_pBoneToWorld;
        p_m_ik = 2143289344;
        *(float *)((char *)&v59->m_flMatVal[0][2] + v54) = NAN;
        v60 = this->m_pBoneToWorld;
        p_m_ik = 2143289344;
        *(float *)((char *)&v60->m_flMatVal[0][3] + v54) = NAN;
        v61 = this->m_pBoneToWorld;
        p_m_ik = 2143289344;
        *(float *)((char *)v61->m_flMatVal[1] + v54) = NAN;
        v62 = this->m_pBoneToWorld;
        p_m_ik = 2143289344;
        *(float *)((char *)&v62->m_flMatVal[1][1] + v54) = NAN;
        v63 = this->m_pBoneToWorld;
        p_m_ik = 2143289344;
        *(float *)((char *)&v63->m_flMatVal[1][2] + v54) = NAN;
        *(float *)((char *)&this->m_pBoneToWorld->m_flMatVal[1][3] + v54) = NAN;
        p_m_ik = 2143289344;
        *(float *)((char *)this->m_pBoneToWorld->m_flMatVal[2] + v54) = NAN;
      }
LABEL_122:
      ++v115;
      flLength += 12;
      v113 += 216;
      v111 += 48;
      v116 += 48;
      v51 = *(_DWORD *)LODWORD(flRealTime);
      ++v112;
    }
    while ( v112 < *(_DWORD *)(v51 + 156) );
  }
  flLength = (int)&g_mCachedViewTransform;
  if ( mergeBones )
  {
    Studio_RunBoneFlexDrivers(
      pflFlexControllerWeights: this->m_flexweight,
      pStudioHdr: (const CStudioHdr *)LODWORD(flRealTime),
      pvPositions: pos,
      pBoneToWorld: this->m_pBoneToWorld,
      mRootToWorld: (const matrix3x4_t *)flLength);
  }
  else
  {
    MatrixCopy(in: &g_viewtransform, out: (matrix3x4_t *)flLength);
    Studio_RunBoneFlexDrivers(
      pflFlexControllerWeights: this->m_flexweight,
      pStudioHdr: (const CStudioHdr *)LODWORD(flRealTime),
      pvPositions: pos,
      pBoneToWorld: this->m_pBoneToWorld,
      mRootToWorld: &g_viewtransform);
  }
  v89 = v93.m_ikLock.m_Memory.m_pMemory;
  v93.m_ikLock.m_Size = 0;
  if ( v93.m_ikLock.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v93.m_ikLock.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v93.m_ikLock.m_Memory.m_pMemory);
      v89 = nullptr;
      v93.m_ikLock.m_Memory.m_pMemory = nullptr;
    }
    v93.m_ikLock.m_Memory.m_nAllocationCount = 0;
  }
  v93.m_ikLock.m_pElements = v89;
  if ( v93.m_ikLock.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v89 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v89);
      v93.m_ikLock.m_Memory.m_pMemory = nullptr;
    }
    v93.m_ikLock.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&v93.m_ikChainRule);
  v90 = v93.m_ikChainRule.m_Memory.m_pMemory;
  if ( v93.m_ikChainRule.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v93.m_ikChainRule.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v93.m_ikChainRule.m_Memory.m_pMemory);
      v90 = nullptr;
      v93.m_ikChainRule.m_Memory.m_pMemory = nullptr;
    }
    v93.m_ikChainRule.m_Memory.m_nAllocationCount = 0;
  }
  v93.m_ikChainRule.m_pElements = v90;
  if ( v93.m_ikChainRule.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v90 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v90);
      v93.m_ikChainRule.m_Memory.m_pMemory = nullptr;
    }
    v93.m_ikChainRule.m_Memory.m_nAllocationCount = 0;
  }
  IBoneSetup::~IBoneSetup(this: &cycle);
}

//------------------------------------------------------------------------------
// Address: 0x0055F9A0
// Name: public: CMatRenderData<struct matrix3x4_t>::~CMatRenderData<struct matrix3x4_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(CMatRenderData<matrix3x4_t> *this)
{
  IMatRenderContext *m_pRenderContext; // ecx
  IMatRenderContext_vtbl *v3; // edx

  m_pRenderContext = this->m_pRenderContext;
  if ( m_pRenderContext != nullptr && this->m_pRenderData != nullptr )
  {
    v3 = m_pRenderContext->__vftable;
    if ( this->m_bNeedsUnlock )
    {
      ((void (__stdcall *)(matrix3x4_t *))v3->UnlockRenderData)(a1: this->m_pRenderData);
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

} // namespace hlmv
