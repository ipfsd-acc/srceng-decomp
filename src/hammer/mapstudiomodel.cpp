// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapstudiomodel.cpp
// Functions: 33
// ============================================================

#include "hammer\mapstudiomodel.h"

//------------------------------------------------------------------------------
// Address: 0x101461E0
// Name: public: virtual char const __near * CMapStudioModel::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapStudioModel::GetType(CMapStudioModel *this)
{
  return CMapStudioModel::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x101461F0
// Name: public: virtual int CMapStudioModel::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapStudioModel::IsMapClass(CMapStudioModel *this, const char *Type)
{
  return Type == CMapStudioModel::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10146210
// Name: public: virtual char const __near * CMapStudioModel::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapStudioModel::GetDescription(CMapStudioModel *this)
{
  return "Studio model";
}

//------------------------------------------------------------------------------
// Address: 0x10146220
// Name: public: static void CMapStudioModel::AdvanceAnimation(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapStudioModel::AdvanceAnimation(float flInterval)
{
  if ( CMapStudioModel::m_bAnimateModels != 0 )
    CStudioModelCache::AdvanceAnimation(flInterval);
}

//------------------------------------------------------------------------------
// Address: 0x10146250
// Name: public: static void CMapStudioModel::EnableAnimation(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapStudioModel::EnableAnimation(int bEnable)
{
  CMapStudioModel::m_bAnimateModels = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x10146260
// Name: public: virtual bool CMapStudioModel::RenderPreload(class CRender3D __near *,bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapStudioModel::RenderPreload(CMapStudioModel *this, CRender3D *pRender, bool bNewContext)
{
  return this->m_pStudioModel != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10146270
// Name: public: virtual bool CMapStudioModel::ShouldRenderLast(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapStudioModel::ShouldRenderLast(CMapStudioModel *this)
{
  return StudioModel::IsTranslucent(this: this->m_pStudioModel) != 0 || Options.view3d.bPreviewModelFade;
}

//------------------------------------------------------------------------------
// Address: 0x10146290
// Name: public: virtual void CMapStudioModel::Render2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapStudioModel::Render2D(CMapStudioModel *this, CRender2D *pRender)
{
  bool v4; // bl
  int v5; // eax
  int v6; // ecx
  bool v7; // zf
  float x; // xmm0_4
  float v9; // xmm1_4
  char v10; // bl
  float v11; // xmm3_4
  float v12; // xmm0_4
  Vector vEnd; // [esp+18h] [ebp-58h] BYREF
  Vector z; // [esp+24h] [ebp-4Ch] BYREF
  Vector mins; // [esp+30h] [ebp-40h] BYREF
  Vector maxs; // [esp+3Ch] [ebp-34h] BYREF
  QAngle pfAngles; // [esp+48h] [ebp-28h] BYREF
  float v18; // [esp+54h] [ebp-1Ch] BYREF
  Vector vecMaxs; // [esp+58h] [ebp-18h] BYREF
  QAngle vecAngles; // [esp+64h] [ebp-Ch] BYREF
  int pt2; // [esp+78h] [ebp+8h]

  CMapClass::GetRender2DBox(this, &mins, &maxs);
  CRender::TransformPoint(this: pRender, vClient: (Vector2D *)&v18, vWorld: &mins);
  CRender::TransformPoint(this: pRender, vClient: (Vector2D *)&vecMaxs.y, vWorld: &maxs);
  ((void (__thiscall *)(CMapStudioModel *, QAngle *))this->GetRenderColor)(a1: this, a2: &vecAngles);
  v4 = this->IsEditable(this);
  if ( this->GetSelectionState(this) != SELECT_NONE )
  {
    CRender::SetDrawColor(
      this: pRender,
      r: Options.colors.clrSelection,
      g: BYTE1(Options.colors.clrSelection),
      b: BYTE2(Options.colors.clrSelection));
    CRender::SetHandleColor(
      this: pRender,
      r: Options.colors.clrSelection,
      g: BYTE1(Options.colors.clrSelection),
      b: BYTE2(Options.colors.clrSelection));
  }
  else
  {
    CRender::SetDrawColor(this: pRender, r: LOBYTE(vecAngles.x), g: BYTE1(vecAngles.x), b: BYTE2(vecAngles.x));
    CRender::SetHandleColor(this: pRender, r: LOBYTE(vecAngles.x), g: BYTE1(vecAngles.x), b: BYTE2(vecAngles.x));
  }
  v5 = (int)fabs(vecMaxs.y - v18);
  v6 = (int)fabs(vecMaxs.z - vecMaxs.x);
  LODWORD(vecAngles.z) = v5;
  pt2 = v6;
  if ( v4 && v5 >= 8 && v6 >= 8 && CRender::IsActiveView(this: pRender) )
  {
    CRender::SetHandleStyle(this: pRender, size: 4, type: 4);
    z.x = (float)(maxs.x + mins.x) * 0.5;
    z.y = (float)(mins.y + maxs.y) * 0.5;
    z.z = (float)(maxs.z + mins.z) * 0.5;
    CRender::DrawHandle(this: pRender, vCenter: &z, vOffset: nullptr);
  }
  v7 = !this->m_bPitchSet;
  x = this->m_Angles.x;
  pfAngles.y = this->m_Angles.y;
  v9 = this->m_Angles.z;
  pfAngles.x = x;
  pfAngles.z = v9;
  if ( !v7 )
  {
    x = this->m_flPitch;
    pfAngles.x = x;
  }
  if ( this->m_bReversePitch )
    pfAngles.x = x * -1.0;
  if ( (Options.view2d.bDrawModels == 0 || LODWORD(vecAngles.z) + pt2 <= 50)
    && !this->IsSelected(this)
    && (!CRender::IsInLocalTransformMode(this: pRender) || pRender->m_bInstanceRendering) )
  {
    v10 = 0;
    goto LABEL_20;
  }
  v10 = 1;
  if ( this->IsSelected(this) )
  {
LABEL_20:
    pRender->DrawBox(this: pRender, a2: &mins, a3: &maxs, a4: false);
    if ( v10 == 0 )
      goto LABEL_25;
  }
  StudioModel::SetAngles(this: this->m_pStudioModel, &pfAngles);
  StudioModel::SetOrigin(this: this->m_pStudioModel, x: this->m_Origin.x, y: this->m_Origin.y, z: this->m_Origin.z);
  StudioModel::SetSkin(this: this->m_pStudioModel, iValue: (CStudioHdr *)this->m_Skin);
  StudioModel::SetBodygroups(this: this->m_pStudioModel, iValue: this->m_BodyGroup);
  if ( this->GetSelectionState(this) == SELECT_NORMAL || CRender::IsInLocalTransformMode(this: pRender) )
    StudioModel::DrawModel2D(this: this->m_pStudioModel, a2: (int)this, pRender, flAlpha: 0.60000002, bWireFrame: false);
  else
    StudioModel::DrawModel2D(this: this->m_pStudioModel, a2: (int)this, pRender, flAlpha: 1.0, bWireFrame: true);
LABEL_25:
  if ( this->IsSelected(this) )
  {
    AngleVectors(angles: &pfAngles, forward: &z, right: nullptr, up: nullptr);
    CRender::SetDrawColor(this: pRender, r: 0xFFu, g: 0xFFu, b: 0);
    v11 = this->m_Origin.x + (float)(z.x * 24.0);
    vEnd.y = this->m_Origin.y + (float)(z.y * 24.0);
    v12 = this->m_Origin.z + (float)(z.z * 24.0);
    vEnd.x = v11;
    vEnd.z = v12;
    CRender::DrawLine(this: pRender, a2: (int)pRender, a3: (int)this, vStart: &this->m_Origin, &vEnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101465E0
// Name: public: void CMapStudioModel::SetAngles(class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapStudioModel::SetAngles(CMapStudioModel *this, QAngle *Angles)
{
  float y; // xmm0_4
  CMapEntity *v4; // edi
  char string[32]; // [esp+20h] [ebp-50h] BYREF

  this->m_Angles = *Angles;
  if ( fabs(this->m_Angles.x) < 0.001 )
    this->m_Angles.x = 0.0;
  if ( fabs(this->m_Angles.y) < 0.001 )
    this->m_Angles.y = 0.0;
  if ( fabs(this->m_Angles.z) < 0.001 )
    this->m_Angles.z = 0.0;
  if ( this->m_Angles.y < 0.0 )
  {
    y = this->m_Angles.y;
    do
      y = y + 360.0;
    while ( y < 0.0 );
    this->m_Angles.y = y;
  }
  if ( this->m_bPitchSet )
    this->m_flPitch = this->m_Angles.x;
  v4 = (CMapEntity *)__RTDynamicCast(
                       inptr: this->m_pParent,
                       VfDelta: 0,
                       SrcType: &CMapAtom `RTTI Type Descriptor',
                       TargetType: &CMapEntity `RTTI Type Descriptor',
                       isReference: 0);
  if ( v4 != nullptr )
  {
    sprintf(string, format: "%g %g %g", this->m_Angles.x, this->m_Angles.y, this->m_Angles.z);
    CMapEntity::NotifyChildKeyChanged(this: v4, pChild: this, szKey: "angles", szValue: string);
    if ( this->m_bPitchSet )
    {
      sprintf(string, format: "%g", this->m_flPitch);
      CMapEntity::NotifyChildKeyChanged(this: v4, pChild: this, szKey: "pitch", szValue: string);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10146780
// Name: public: static void CMapStudioModel::SetRenderDistance(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapStudioModel::SetRenderDistance(float fRenderDistance)
{
  CMapStudioModel::m_fRenderDistance = fRenderDistance;
}

//------------------------------------------------------------------------------
// Address: 0x101467A0
// Name: protected: virtual void CMapStudioModel::DoTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapStudioModel::DoTransform(CMapStudioModel *this, const VMatrix *matrix)
{
  bool v3; // zf
  matrix3x4_t fMatrixNew; // [esp+8h] [ebp-A8h] BYREF
  matrix3x4_t fCurrentMatrix; // [esp+38h] [ebp-78h] BYREF
  matrix3x4_t fRotateMatrix; // [esp+68h] [ebp-48h] BYREF
  QAngle rotAngles; // [esp+98h] [ebp-18h] BYREF
  QAngle angles; // [esp+A4h] [ebp-Ch] BYREF

  CMapClass::DoTransform(this, matrix);
  v3 = !this->m_bReversePitch;
  fRotateMatrix = *(matrix3x4_t *)&matrix->m[0][0];
  if ( !v3 )
  {
    MatrixAngles(src: (const VMatrix *)&fRotateMatrix, vAngles: &rotAngles);
    rotAngles.x = rotAngles.x * -1.0;
    rotAngles.z = rotAngles.z * -1.0;
    AngleMatrix(angles: &rotAngles, matrix: &fRotateMatrix);
  }
  v3 = !this->m_bPitchSet;
  angles = this->m_Angles;
  if ( !v3 )
    angles.x = this->m_flPitch;
  AngleMatrix(&angles, matrix: &fCurrentMatrix);
  ConcatTransforms(in1: &fRotateMatrix, in2: &fCurrentMatrix, out: &fMatrixNew);
  MatrixAngles(src: (const VMatrix *)&fMatrixNew, vAngles: &angles);
  CMapStudioModel::SetAngles(this, Angles: &angles);
}

//------------------------------------------------------------------------------
// Address: 0x101468C0
// Name: public: int CMapStudioModel::GetMaxFrame(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapStudioModel::GetMaxFrame(CMapStudioModel *this)
{
  return StudioModel::GetMaxFrame(this: this->m_pStudioModel);
}

//------------------------------------------------------------------------------
// Address: 0x101468D0
// Name: public: void CMapStudioModel::SetFrame(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapStudioModel::SetFrame(CMapStudioModel *this, int nFrame)
{
  StudioModel::SetFrame(this: this->m_pStudioModel, nFrame);
}

//------------------------------------------------------------------------------
// Address: 0x101468E0
// Name: public: int CMapStudioModel::GetSequence(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapStudioModel::GetSequence(CMapStudioModel *this)
{
  StudioModel *m_pStudioModel; // ecx

  m_pStudioModel = this->m_pStudioModel;
  if ( m_pStudioModel != nullptr )
    return CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)m_pStudioModel);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10146900
// Name: public: int CMapStudioModel::GetSequenceCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapStudioModel::GetSequenceCount(CMapStudioModel *this)
{
  StudioModel *m_pStudioModel; // ecx

  m_pStudioModel = this->m_pStudioModel;
  if ( m_pStudioModel != nullptr )
    return StudioModel::GetSequenceCount(this: m_pStudioModel);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10146920
// Name: public: void CMapStudioModel::GetSequenceName(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapStudioModel::GetSequenceName(CMapStudioModel *this, int nIndex, char *szName)
{
  StudioModel *m_pStudioModel; // ecx

  m_pStudioModel = this->m_pStudioModel;
  if ( m_pStudioModel != nullptr )
    StudioModel::GetSequenceName(this: m_pStudioModel, nIndex, szName);
}

//------------------------------------------------------------------------------
// Address: 0x10146940
// Name: public: void CMapStudioModel::SetSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapStudioModel::SetSequence(CMapStudioModel *this, int nIndex)
{
  StudioModel *m_pStudioModel; // ecx

  m_pStudioModel = this->m_pStudioModel;
  if ( m_pStudioModel != nullptr )
    StudioModel::SetSequence(this: m_pStudioModel, iSequence: nIndex);
}

//------------------------------------------------------------------------------
// Address: 0x10146960
// Name: public: int CMapStudioModel::GetSequenceIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapStudioModel::GetSequenceIndex(CMapStudioModel *this, const char *pSequenceName)
{
  StudioModel *m_pStudioModel; // ecx
  int SequenceCount; // edi
  int v5; // esi
  char name[2048]; // [esp+Ch] [ebp-800h] BYREF

  m_pStudioModel = this->m_pStudioModel;
  if ( m_pStudioModel == nullptr )
    return -1;
  SequenceCount = StudioModel::GetSequenceCount(this: m_pStudioModel);
  v5 = 0;
  if ( SequenceCount <= 0 )
    return -1;
  while ( 1 )
  {
    StudioModel::GetSequenceName(this: this->m_pStudioModel, nIndex: v5, szName: name);
    if ( _V_stricmp(s1: pSequenceName, s2: name) == 0 )
      break;
    if ( ++v5 >= SequenceCount )
      return -1;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101469E0
// Name: public: CMapStudioModel::CMapStudioModel(void)
// Source: json
//------------------------------------------------------------------------------
CMapStudioModel *__thiscall CMapStudioModel::CMapStudioModel(CMapStudioModel *this)
{
  CMapClass::CMapClass(this);
  this->__vftable = (CMapStudioModel_vtbl *)&CMapHelper::`vftable';
  this->__vftable = (CMapStudioModel_vtbl *)&CMapStudioModel::`vftable';
  this->m_Angles.x = 0.0;
  this->m_Angles.y = 0.0;
  this->m_Angles.z = 0.0;
  this->m_bPitchSet = false;
  this->m_flPitch = 0.0;
  this->m_bReversePitch = false;
  this->m_pStudioModel = nullptr;
  this->m_Skin = 0;
  this->m_BodyGroup = 0;
  this->m_ModelRenderColor = (Color)-1;
  this->m_flFadeScale = 1.0;
  this->m_flFadeMinDist = 0.0;
  this->m_flFadeMaxDist = 0.0;
  this->m_iSolid = -1;
  InitViewerSettings();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10146B20
// Name: public: virtual void CMapStudioModel::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapStudioModel::CalcBounds(CMapStudioModel *this, int bFullUpdate)
{
  StudioModel *m_pStudioModel; // ecx
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm6_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  bool v10; // zf
  float x; // xmm0_4
  float z; // xmm1_4
  Vector *p_bmaxs; // edi
  Vector *p_bmins; // ebx
  float v15; // xmm2_4
  float y; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm7_4
  float v19; // xmm5_4
  float v20; // xmm6_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  QAngle angles; // [esp+4h] [ebp-24h] BYREF
  Vector Mins; // [esp+10h] [ebp-18h] BYREF
  Vector Maxs; // [esp+1Ch] [ebp-Ch] BYREF

  CMapClass::CalcBounds(this, bFullUpdate);
  m_pStudioModel = this->m_pStudioModel;
  v4 = 0.0;
  v5 = 0.0;
  v6 = 0.0;
  v7 = 0.0;
  v8 = 0.0;
  v9 = 0.0;
  memset(&Mins, 0, sizeof(Mins));
  memset(&Maxs, 0, sizeof(Maxs));
  if ( m_pStudioModel != nullptr )
  {
    v10 = !this->m_bPitchSet;
    x = this->m_Angles.x;
    angles.y = this->m_Angles.y;
    z = this->m_Angles.z;
    angles.x = x;
    angles.z = z;
    if ( !v10 )
    {
      x = this->m_flPitch;
      angles.x = x;
    }
    if ( this->m_bReversePitch )
      angles.x = x * -1.0;
    StudioModel::SetAngles(this: m_pStudioModel, pfAngles: &angles);
    p_bmaxs = &this->m_CullBox.bmaxs;
    p_bmins = &this->m_CullBox.bmins;
    StudioModel::ExtractBbox(this: this->m_pStudioModel, mins: &this->m_CullBox.bmins, maxs: &this->m_CullBox.bmaxs);
    if ( this->m_bOrientedBounds )
    {
      v15 = p_bmins->x;
      y = this->m_CullBox.bmins.y;
      v17 = this->m_CullBox.bmins.z;
      v18 = p_bmaxs->x;
      Maxs.y = this->m_CullBox.bmaxs.y;
      Maxs.z = this->m_CullBox.bmaxs.z;
    }
    else
    {
      StudioModel::ExtractMovementBbox(this: this->m_pStudioModel, mins: &Mins, maxs: &Maxs);
      v17 = Mins.z;
      y = Mins.y;
      v15 = Mins.x;
      v18 = Maxs.x;
    }
    v4 = this->m_Origin.x + v15;
    v19 = this->m_Origin.y;
    v8 = v19 + Maxs.y;
    v5 = v19 + y;
    v20 = this->m_Origin.z;
    v9 = v20 + Maxs.z;
    v6 = v20 + v17;
    v21 = this->m_Origin.x;
    p_bmins->x = v21 + p_bmins->x;
    this->m_CullBox.bmins.y = this->m_Origin.y + this->m_CullBox.bmins.y;
    this->m_CullBox.bmins.z = this->m_Origin.z + this->m_CullBox.bmins.z;
    p_bmaxs->x = p_bmaxs->x + this->m_Origin.x;
    this->m_CullBox.bmaxs.y = this->m_Origin.y + this->m_CullBox.bmaxs.y;
    this->m_CullBox.bmaxs.z = this->m_Origin.z + this->m_CullBox.bmaxs.z;
    v7 = v21 + v18;
    Mins.x = v4;
    Mins.y = v5;
    Mins.z = v6;
    Maxs.x = v7;
    Maxs.y = v8;
    Maxs.z = v9;
  }
  v22 = v8 - v5;
  v23 = v9 - v6;
  if ( (float)(v7 - v4) == 0.0 && v22 == 0.0 && v23 == 0.0 )
  {
    v24 = this->m_Origin.y;
    v25 = this->m_Origin.z;
    v26 = this->m_Origin.x - 10.0;
    this->m_CullBox.bmins.x = v26;
    v27 = v24 - 10.0;
    this->m_CullBox.bmins.y = v27;
    v28 = v25 - 10.0;
    this->m_CullBox.bmins.z = v28;
    Mins.x = v26;
    v29 = this->m_Origin.x;
    Mins.y = v27;
    v30 = this->m_Origin.y;
    Mins.z = v28;
    v31 = v29 + 10.0;
    v32 = v30 + 10.0;
    v33 = this->m_Origin.z + 10.0;
    this->m_CullBox.bmaxs.x = v31;
    this->m_CullBox.bmaxs.y = v32;
    this->m_CullBox.bmaxs.z = v33;
    Maxs.x = v31;
    Maxs.y = v32;
    Maxs.z = v33;
  }
  this->m_BoundingBox.bmins.x = this->m_CullBox.bmins.x;
  this->m_BoundingBox.bmins.y = this->m_CullBox.bmins.y;
  this->m_BoundingBox.bmins.z = this->m_CullBox.bmins.z;
  this->m_BoundingBox.bmaxs.x = this->m_CullBox.bmaxs.x;
  this->m_BoundingBox.bmaxs.y = this->m_CullBox.bmaxs.y;
  this->m_BoundingBox.bmaxs.z = this->m_CullBox.bmaxs.z;
  BoundBox::UpdateBounds(this: &this->m_Render2DBox, mins: &Mins, maxs: &Maxs);
}

//------------------------------------------------------------------------------
// Address: 0x10146DD0
// Name: public: virtual class CMapClass __near * CMapStudioModel::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapStudioModel *__thiscall CMapStudioModel::Copy(CMapStudioModel *this, BOOL bUpdateDependencies)
{
  CMapStudioModel *v3; // eax
  CMapStudioModel *v4; // esi

  v3 = (CMapStudioModel *)operator new(nSize: 0x110u);
  if ( v3 != nullptr )
    v4 = CMapStudioModel::CMapStudioModel(this: v3);
  else
    v4 = nullptr;
  if ( v4 != nullptr )
    v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10146E50
// Name: public: virtual class CMapClass __near * CMapStudioModel::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapStudioModel *__thiscall CMapStudioModel::CopyFrom(
        CMapStudioModel *this,
        CMapClass *pObject,
        bool bUpdateDependencies)
{
  StudioModel *v4; // ecx
  char *ModelName; // eax

  CMapClass::CopyFrom(this, pFrom: (CVisGroup *)pObject, bUpdateDependencies);
  v4 = (StudioModel *)pObject[1].__vftable;
  if ( v4 != nullptr )
    ModelName = StudioModel::GetModelName(this: v4);
  else
    ModelName = nullptr;
  this->m_pStudioModel = CStudioModelCache::CreateModel(pszModelPath: ModelName);
  this->m_Angles.x = *(float *)&pObject[1].m_nObjectID;
  this->m_Angles.y = *(float *)&pObject[1].m_pParent;
  this->m_Angles.z = *(float *)&pObject[1].m_eSelectionState;
  this->m_Skin = LODWORD(pObject[1].m_Origin.y);
  this->m_BodyGroup = LODWORD(pObject[1].m_Origin.z);
  *(_WORD *)&this->m_bOrientedBounds = pObject[1].m_References.m_pHead;
  this->m_bPitchSet = LOBYTE(pObject[1].m_Origin.x);
  this->m_flPitch = *(float *)&pObject[1].r;
  this->m_flFadeScale = *(float *)&pObject[1].dwKept;
  this->m_flFadeMinDist = *(float *)&pObject[1].m_CullBox.__vftable;
  *(Vector *)&this->m_flFadeMaxDist = pObject[1].m_CullBox.bmins;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10146F40
// Name: public: virtual void CMapStudioModel::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapStudioModel::OnParentKeyChanged(CMapStudioModel *this, const char *szKey, const char *szValue)
{
  const char *v3; // edi
  void (__thiscall *PostUpdate)(CMapAtom *, Notify_Dependent_t); // eax
  int v6; // eax
  CMapStudioModel_vtbl *v7; // edx
  int v8; // eax
  CMapStudioModel_vtbl *v9; // edx
  unsigned __int8 v10; // al
  unsigned __int8 v11; // cl
  int SequenceIndex; // eax
  int b; // [esp+8h] [ebp-4h] BYREF

  v3 = szKey;
  if ( _V_stricmp(s1: szKey, s2: "angles") != 0 )
  {
    if ( _V_stricmp(s1: v3, s2: "pitch") != 0 )
    {
      if ( _V_stricmp(s1: v3, s2: "skin") != 0 )
      {
        if ( _V_stricmp(s1: v3, s2: "body") != 0 )
        {
          if ( _V_stricmp(s1: v3, s2: "fademindist") != 0 )
          {
            if ( _V_stricmp(s1: v3, s2: "fademaxdist") != 0 )
            {
              if ( _V_stricmp(s1: v3, s2: "fadescale") != 0 )
              {
                if ( _V_stricmp(s1: v3, s2: "rendercolor") != 0 )
                {
                  if ( _V_stricmp(s1: v3, s2: "defaultanim") != 0 )
                  {
                    if ( _V_stricmp(s1: v3, s2: "solid") == 0 )
                      this->m_iSolid = (int)atof(nptr: szValue);
                  }
                  else
                  {
                    SequenceIndex = CMapStudioModel::GetSequenceIndex(this, pSequenceName: szValue);
                    if ( SequenceIndex != -1 )
                      StudioModel::SetSequence(this: this->m_pStudioModel, iSequence: SequenceIndex);
                  }
                }
                else
                {
                  sscanf(string: szValue, format: "%d %d %d", &szValue, &szKey, &b);
                  v10 = (unsigned __int8)szKey;
                  v11 = b;
                  this->m_ModelRenderColor._color[0] = (unsigned __int8)szValue;
                  this->m_ModelRenderColor._color[1] = v10;
                  this->m_ModelRenderColor._color[2] = v11;
                  this->m_ModelRenderColor._color[3] = -1;
                }
              }
              else
              {
                this->m_flFadeScale = atof(nptr: szValue);
              }
            }
            else
            {
              this->m_flFadeMaxDist = (float)atoi(nptr: szValue);
            }
          }
          else
          {
            this->m_flFadeMinDist = (float)atoi(nptr: szValue);
          }
        }
        else
        {
          v8 = atoi(nptr: szValue);
          v9 = this->__vftable;
          this->m_BodyGroup = v8;
          v9->PostUpdate(this, a2: Notify_Changed);
        }
      }
      else
      {
        v6 = atoi(nptr: szValue);
        v7 = this->__vftable;
        this->m_Skin = v6;
        v7->PostUpdate(this, a2: Notify_Changed);
      }
    }
    else
    {
      this->m_flPitch = atof(nptr: szValue);
      PostUpdate = this->PostUpdate;
      this->m_bPitchSet = true;
      PostUpdate(this, a2: Notify_Changed);
    }
  }
  else
  {
    sscanf(string: szValue, format: "%f %f %f", &this->m_Angles, &this->m_Angles.y, &this->m_Angles.z);
    this->PostUpdate(this, a2: Notify_Changed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101471A0
// Name: protected: float CMapStudioModel::ComputeDistanceFade(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CMapStudioModel::ComputeDistanceFade@<st0>(
        CMapStudioModel *this@<ecx>,
        float a2@<ebp>,
        CRender3D *pRender)
{
  CCamera *Camera; // eax
  float m_flFadeMinDist; // xmm3_4
  float m_flFadeMaxDist; // xmm4_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm5_4
  float v11; // xmm1_4
  __int128 v12; // xmm0
  __int128 v14; // [esp+24h] [ebp-2Ch] BYREF
  float C; // [esp+40h] [ebp-10h]
  float D; // [esp+44h] [ebp-Ch]
  int v17; // [esp+48h] [ebp-8h]
  int vars0; // [esp+50h] [ebp+0h]

  D = a2;
  v17 = vars0;
  Camera = CRender::GetCamera(this: pRender);
  CCamera::GetViewPoint(this: Camera, ViewPoint: (Vector *)((char *)&v14 + 4));
  m_flFadeMinDist = this->m_flFadeMinDist;
  m_flFadeMaxDist = this->m_flFadeMaxDist;
  v7 = this->m_Origin.x - *((float *)&v14 + 1);
  v8 = this->m_Origin.y - *((float *)&v14 + 2);
  v9 = this->m_Origin.z - *((float *)&v14 + 3);
  if ( m_flFadeMaxDist <= m_flFadeMinDist )
    v10 = this->m_flFadeMaxDist;
  else
    v10 = this->m_flFadeMinDist;
  if ( m_flFadeMinDist <= m_flFadeMaxDist )
    m_flFadeMinDist = this->m_flFadeMaxDist;
  if ( v10 < 0.0 )
  {
    v10 = m_flFadeMinDist + v10;
    if ( v10 < 0.0 )
      v10 = 0.0;
  }
  C = 1.0;
  if ( m_flFadeMinDist <= 0.0 )
    return C;
  v11 = (float)((float)(v8 * v8) + (float)(v9 * v9)) + (float)(v7 * v7);
  v12 = 0;
  *(float *)&v12 = fsqrt(v11);
  v14 = v12;
  if ( *(float *)&v12 > m_flFadeMinDist )
    return 0.0;
  if ( *(float *)&v14 <= v10 )
    return C;
  return RemapValClamped(val: *(float *)&v14, A: v10, B: m_flFadeMinDist, C: 1.0, D: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x101472C0
// Name: protected: float CMapStudioModel::ComputeScreenFadeInternal(class CRender3D __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CMapStudioModel::ComputeScreenFadeInternal@<st0>(
        CMapStudioModel *this@<ecx>,
        float a2@<ebp>,
        CRender3D *pRender,
        float flMinSize,
        float flMaxSize)
{
  __int128 v6; // xmm0
  long double v7; // st7
  float v8; // xmm0_4
  __int128 v10; // [esp+14h] [ebp-3Ch] BYREF
  Vector v11; // [esp+30h] [ebp-20h] BYREF
  float v12; // [esp+3Ch] [ebp-14h]
  float v13; // [esp+40h] [ebp-10h]
  float flRadius; // [esp+44h] [ebp-Ch]
  int v15; // [esp+48h] [ebp-8h]
  int vars0; // [esp+50h] [ebp+0h]

  flRadius = a2;
  v15 = vars0;
  CMapClass::GetCullBox(this, mins: &v11, maxs: (Vector *)((char *)&v10 + 4));
  v6 = 0;
  *(float *)&v6 = fsqrt(
                    (float)((float)((float)(v11.y - *((float *)&v10 + 2)) * (float)(v11.y - *((float *)&v10 + 2)))
                          + (float)((float)(v11.z - *((float *)&v10 + 3)) * (float)(v11.z - *((float *)&v10 + 3))))
                  + (float)((float)(v11.x - *((float *)&v10 + 1)) * (float)(v11.x - *((float *)&v10 + 1))));
  v10 = v6;
  v7 = CRender3D::ComputePixelWidthOfSphere(this: pRender, vecOrigin: &this->m_Origin, flRadius: *(float *)&v6 * 0.5);
  v12 = v7;
  v13 = 0.0;
  if ( v7 > flMinSize )
  {
    if ( flMaxSize < 0.0 || flMaxSize <= v12 )
    {
      return 1.0;
    }
    else
    {
      if ( flMaxSize == flMinSize )
        return 0.0;
      v8 = (float)(v12 - flMinSize) / (float)(flMaxSize - flMinSize);
      if ( v8 < 0.0 )
        return 0.0;
      if ( v8 > 1.0 )
        return 1.0;
    }
    return v8;
  }
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x10147400
// Name: protected: float CMapStudioModel::ComputeScreenFade(class CRender3D __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMapStudioModel::ComputeScreenFade(
        CMapStudioModel *this,
        CRender3D *pRender,
        float flMinSize,
        float flMaxSize)
{
  CRender3D *v4; // edi
  CCamera *Camera; // eax
  float v8; // xmm0_4
  int height; // [esp+10h] [ebp-4h] BYREF
  int _14; // [esp+14h] [ebp+0h] BYREF

  v4 = pRender;
  Camera = CRender::GetCamera(this: pRender);
  if ( Camera == nullptr )
    return 1.0;
  CCamera::GetViewPort(this: Camera, width: (int *)&pRender, &height);
  v8 = (float)(int)pRender / g_aFadeData[Options.view3d.nFadeMode].m_flWidth;
  return CMapStudioModel::ComputeScreenFadeInternal(
           this,
           a2: COERCE_FLOAT(&_14),
           pRender: v4,
           flMinSize: v8 * flMinSize,
           flMaxSize: v8 * flMaxSize);
}

//------------------------------------------------------------------------------
// Address: 0x10147480
// Name: protected: float CMapStudioModel::ComputeLevelFade(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMapStudioModel::ComputeLevelFade(CMapStudioModel *this, CRender3D *pRender)
{
  CMapWorld *m_pWorld; // eax
  WCKeyValuesT<WCKVBase_Dict> *p_m_KeyValues; // esi
  const char *Value; // edi
  const char *v6; // eax
  const char *v7; // esi
  float flMinSize; // [esp+0h] [ebp-8h]
  float flMinSize_4; // [esp+4h] [ebp-4h]

  if ( CMapDoc::m_pMapDoc == nullptr )
    return 1.0;
  m_pWorld = CMapDoc::m_pMapDoc->m_pWorld;
  if ( m_pWorld == nullptr )
    return 1.0;
  p_m_KeyValues = &m_pWorld->m_KeyValues;
  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
            this: &m_pWorld->m_KeyValues,
            pszKey: "maxpropscreenwidth",
            piIndex: nullptr);
  v6 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: "minpropscreenwidth", piIndex: nullptr);
  v7 = v6;
  if ( Value == nullptr || v6 == nullptr )
    return 1.0;
  flMinSize = atof(nptr: Value);
  flMinSize_4 = atof(nptr: v7);
  return CMapStudioModel::ComputeScreenFade(this, pRender, flMinSize, flMaxSize: flMinSize_4);
}

//------------------------------------------------------------------------------
// Address: 0x10147530
// Name: protected: float CMapStudioModel::ComputeFade(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMapStudioModel::ComputeFade(CMapStudioModel *this, CRender3D *pRender)
{
  bool v4; // bl
  double v6; // st7
  float flMinSize; // [esp+14h] [ebp-8h]
  float flMaxSize; // [esp+18h] [ebp-4h]
  int _1C; // [esp+1Ch] [ebp+0h] BYREF
  float pRendera; // [esp+24h] [ebp+8h]

  if ( this->m_flFadeScale == 0.0 )
    return 1.0;
  v4 = Options.view3d.nFadeMode == 1
    || Options.view3d.nFadeMode == 2
    || Options.view3d.nFadeMode == 4
    || Options.view3d.nFadeMode == 5;
  if ( !v4 && this->m_flFadeMaxDist == 0.0 )
    return 1.0;
  flMaxSize = 1.0;
  if ( this->m_flFadeMaxDist != 0.0 )
    flMaxSize = CMapStudioModel::ComputeDistanceFade(this, a2: COERCE_FLOAT(&_1C), pRender);
  pRendera = 1.0;
  if ( v4 )
  {
    flMinSize = CMapStudioModel::ComputeLevelFade(this, pRender);
    v6 = CMapStudioModel::ComputeScreenFade(
           this,
           pRender,
           flMinSize: g_aFadeData[Options.view3d.nFadeMode].m_flPixelMin,
           flMaxSize: g_aFadeData[Options.view3d.nFadeMode].m_flPixelMax);
    pRendera = v6;
    if ( v6 > flMinSize )
      pRendera = flMinSize;
  }
  if ( pRendera <= flMaxSize )
    return pRendera;
  else
    return flMaxSize;
}

//------------------------------------------------------------------------------
// Address: 0x10147650
// Name: class CMapClass __near * CMapStudioModel_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapStudioModel *__cdecl CMapStudioModel_CreateObject()
{
  CMapStudioModel *v0; // eax

  v0 = (CMapStudioModel *)operator new(nSize: 0x110u);
  if ( v0 != nullptr )
    return CMapStudioModel::CMapStudioModel(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101476B0
// Name: public: static class CMapStudioModel __near * CMapStudioModel::CreateMapStudioModel(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CMapStudioModel *__cdecl CMapStudioModel::CreateMapStudioModel(
        const char *pszModelPath,
        bool bOrientedBounds,
        bool bReversePitch)
{
  CMapStudioModel *v3; // eax
  CMapStudioModel *v4; // esi
  StudioModel *Model; // eax
  bool v6; // zf
  CMapStudioModel_vtbl *v7; // eax

  v3 = (CMapStudioModel *)operator new(nSize: 0x110u);
  if ( v3 != nullptr )
    v4 = CMapStudioModel::CMapStudioModel(this: v3);
  else
    v4 = nullptr;
  Model = CStudioModelCache::CreateModel(pszModelPath);
  v4->m_pStudioModel = Model;
  v6 = Model == nullptr;
  v7 = v4->__vftable;
  if ( v6 )
  {
    ((void (__thiscall *)(CMapStudioModel *, int))v7->~CMapClass)(a1: v4, a2: 1);
    return nullptr;
  }
  else
  {
    v4->m_bOrientedBounds = bOrientedBounds;
    v4->m_bReversePitch = bReversePitch;
    v7->CalcBounds(this: v4, a2: 0);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10147760
// Name: DrawBasisVectors
// Source: json
//------------------------------------------------------------------------------
void __fastcall DrawBasisVectors(const QAngle *angles, const Vector *origin, CRender3D *pRender)
{
  IMatRenderContext *v4; // eax
  IMatRenderContext *v5; // ebx
  IMesh *v6; // edi
  float *m_pCurrPosition; // eax
  float z; // xmm0_4
  float y; // xmm1_4
  float *v10; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  float *v13; // eax
  float v14; // xmm0_4
  float v15; // xmm1_4
  float *v16; // eax
  float v17; // xmm1_4
  float v18; // xmm2_4
  float *v19; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4
  float *v22; // eax
  float v23; // xmm1_4
  float v24; // xmm2_4
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-228h] BYREF
  matrix3x4_t fCurrentMatrix; // [esp+1F4h] [ebp-40h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+224h] [ebp-10h]
  int v29; // [esp+230h] [ebp-4h]

  AngleMatrix(angles, matrix: &fCurrentMatrix);
  CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v29 = 0;
  v4 = materials->GetRenderContext(this: materials);
  v5 = v4;
  pRenderContext.m_pObject = v4;
  LOBYTE(v29) = 1;
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  LOBYTE(v29) = 2;
  v6 = v5->GetDynamicMesh(this: v5, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  meshBuilder.m_pMesh = v6;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_LINES;
  v6->SetPrimitiveType(this: v6, a2: MATERIAL_LINES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v6->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v6, nMaxVertexCount: 6, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  z = origin->z;
  y = origin->y;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = origin->x;
  m_pCurrPosition[1] = y;
  m_pCurrPosition[2] = z;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
  v10 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v11 = (float)(fCurrentMatrix.m_flMatVal[1][0] * 100.0) + origin->y;
  v12 = (float)(fCurrentMatrix.m_flMatVal[2][0] * 100.0) + origin->z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(fCurrentMatrix.m_flMatVal[0][0] * 100.0) + origin->x;
  v10[1] = v11;
  v10[2] = v12;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v14 = origin->z;
  v15 = origin->y;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = origin->x;
  v13[1] = v15;
  v13[2] = v14;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
  v16 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v17 = (float)(fCurrentMatrix.m_flMatVal[1][1] * 100.0) + origin->y;
  v18 = (float)(fCurrentMatrix.m_flMatVal[2][1] * 100.0) + origin->z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(fCurrentMatrix.m_flMatVal[0][1] * 100.0) + origin->x;
  v16[1] = v17;
  v16[2] = v18;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
  v19 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v20 = origin->z;
  v21 = origin->y;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = origin->x;
  v19[1] = v21;
  v19[2] = v20;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
  v22 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v23 = (float)(fCurrentMatrix.m_flMatVal[1][2] * 100.0) + origin->y;
  v24 = (float)(fCurrentMatrix.m_flMatVal[2][2] * 100.0) + origin->z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(fCurrentMatrix.m_flMatVal[0][2] * 100.0) + origin->x;
  v22[1] = v23;
  v22[2] = v24;
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
  v6->Draw_2(this: v6, a2: -1, a3: 0);
  CRender::PopRenderMode(this: pRender);
  LOBYTE(v29) = 3;
  v5->EndRender(this: v5);
  LOBYTE(v29) = 0;
  v5->Release(this: v5);
  v29 = -1;
  CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x10147B60
// Name: public: virtual void CMapStudioModel::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CMapStudioModel::Render3D(CMapStudioModel *this, CRender3D *pRender)
{
  unsigned __int8 r; // al
  unsigned __int8 b; // dl
  bool v6; // zf
  float x; // xmm0_4
  float z; // xmm1_4
  CCamera *Camera; // eax
  float v10; // ecx
  Vector *p_m_Origin; // ebx
  int m_iSolid; // eax
  unsigned __int8 v13; // ah
  SelectionState_t v14; // [esp+8h] [ebp-40h]
  SelectionState_t v15; // [esp+8h] [ebp-40h]
  Vector y; // [esp+18h] [ebp-30h] BYREF
  Vector Out; // [esp+24h] [ebp-24h] BYREF
  QAngle pfAngles; // [esp+30h] [ebp-18h] BYREF
  unsigned __int8 clrModelCollisionWireframe; // [esp+3Ch] [ebp-Ch] BYREF
  unsigned __int8 g; // [esp+3Dh] [ebp-Bh]
  unsigned __int8 v21; // [esp+3Eh] [ebp-Ah]
  char v22; // [esp+3Fh] [ebp-9h]
  float vecAngles; // [esp+44h] [ebp-4h] OVERLAPPED
  bool rgbColor; // [esp+50h] [ebp+8h]

  r = this->r;
  b = this->b;
  v6 = pRender->m_eCurrentRenderMode == RENDER_MODE_LIGHTMAP_GRID;
  g = this->g;
  clrModelCollisionWireframe = r;
  v21 = b;
  if ( v6 )
    CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_TEXTURED);
  else
    CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_CURRENT);
  v6 = !this->m_bPitchSet;
  x = this->m_Angles.x;
  pfAngles.y = this->m_Angles.y;
  z = this->m_Angles.z;
  pfAngles.x = x;
  pfAngles.z = z;
  if ( !v6 )
  {
    x = this->m_flPitch;
    pfAngles.x = x;
  }
  if ( this->m_bReversePitch )
    pfAngles.x = x * -1.0;
  if ( this->m_pStudioModel == nullptr )
  {
    CRender3D::BeginRenderHitTarget(this: pRender, pObject: (CMapInstance *)this, uHandle: 0);
    v15 = this->GetSelectionState(this);
    CRender3D::RenderBox(
      this: pRender,
      Mins: &this->m_Render2DBox.bmins,
      Maxs: &this->m_Render2DBox.bmaxs,
      chRed: clrModelCollisionWireframe,
      chGreen: g,
      chBlue: v21,
      eBoxSelectionState: v15);
    goto LABEL_30;
  }
  Camera = CRender::GetCamera(this: pRender);
  CCamera::GetViewPoint(this: Camera, ViewPoint: &y);
  v6 = !pRender->m_bInstanceRendering;
  v10 = this->m_Origin.z;
  p_m_Origin = &this->m_Origin;
  *(_QWORD *)&Out.x = *(_QWORD *)&this->m_Origin.x;
  Out.z = v10;
  if ( !v6 )
    CRender::TransformInstanceVector(this: pRender, In: &this->m_Origin, &Out);
  if ( CMapStudioModel::m_fRenderDistance <= fabs(y.x - Out.x)
    || CMapStudioModel::m_fRenderDistance <= fabs(y.y - Out.y)
    || CMapStudioModel::m_fRenderDistance <= fabs(y.z - Out.z) )
  {
    CRender3D::BeginRenderHitTarget(this: pRender, pObject: (CMapInstance *)this, uHandle: 0);
    v14 = this->GetSelectionState(this);
    CRender3D::RenderBox(
      this: pRender,
      Mins: &this->m_Render2DBox.bmins,
      Maxs: &this->m_Render2DBox.bmaxs,
      chRed: clrModelCollisionWireframe,
      chGreen: g,
      chBlue: v21,
      eBoxSelectionState: v14);
LABEL_30:
    CRender3D::EndRenderHitTarget(this: pRender, a2: (int)pRender);
    goto LABEL_31;
  }
  ((void (__thiscall *)(CMapStudioModel *, unsigned __int8 *))this->GetRenderColor)(
    a1: this,
    a2: &clrModelCollisionWireframe);
  if ( this->GetSelectionState(this) != SELECT_NONE )
  {
    CRender::SetDrawColor(
      this: pRender,
      r: Options.colors.clrSelection,
      g: BYTE1(Options.colors.clrSelection),
      b: BYTE2(Options.colors.clrSelection));
  }
  else
  {
    m_iSolid = this->m_iSolid;
    if ( m_iSolid != -1 )
    {
      v22 = -1;
      if ( m_iSolid != 0 )
      {
        v13 = BYTE1(Options.colors.clrModelCollisionWireframe);
        clrModelCollisionWireframe = Options.colors.clrModelCollisionWireframe;
        v21 = BYTE2(Options.colors.clrModelCollisionWireframe);
      }
      else
      {
        v13 = BYTE1(Options.colors.clrModelCollisionWireframeDisabled);
        clrModelCollisionWireframe = Options.colors.clrModelCollisionWireframeDisabled;
        v21 = BYTE2(Options.colors.clrModelCollisionWireframeDisabled);
      }
      g = v13;
    }
    CRender::SetDrawColor(this: pRender, r: clrModelCollisionWireframe, g, b: v21);
  }
  StudioModel::SetAngles(this: this->m_pStudioModel, &pfAngles);
  StudioModel::SetOrigin(this: this->m_pStudioModel, x: p_m_Origin->x, y: this->m_Origin.y, z: this->m_Origin.z);
  StudioModel::SetSkin(this: this->m_pStudioModel, iValue: (CStudioHdr *)this->m_Skin);
  StudioModel::SetBodygroups(this: this->m_pStudioModel, iValue: this->m_BodyGroup);
  vecAngles = 1.0;
  if ( Options.view3d.bPreviewModelFade )
    vecAngles = CMapStudioModel::ComputeFade(this, pRender);
  rgbColor = pRender->m_eCurrentRenderMode == RENDER_MODE_WIREFRAME;
  if ( this->GetSelectionState(this) == SELECT_MODIFY )
    rgbColor = true;
  CRender3D::BeginRenderHitTarget(this: pRender, pObject: (CMapInstance *)this, uHandle: 0);
  StudioModel::DrawModel3D(
    this: this->m_pStudioModel,
    a2: (int)p_m_Origin,
    pRender,
    color: &this->m_ModelRenderColor,
    flAlpha: vecAngles,
    bWireframe: rgbColor);
  CRender3D::EndRenderHitTarget(this: pRender, a2: (int)pRender);
  if ( this->IsSelected(this) )
    pRender->RenderWireframeBox(
      this: pRender,
      a2: &this->m_Render2DBox.bmins,
      a3: &this->m_Render2DBox.bmaxs,
      a4: 255u,
      a5: 255u,
      a6: 0);
LABEL_31:
  if ( this->IsSelected(this) )
    DrawBasisVectors(angles: &pfAngles, origin: &this->m_Origin, pRender);
  CRender::PopRenderMode(this: pRender);
}

//------------------------------------------------------------------------------
// Address: 0x10147E90
// Name: public: static class CMapClass __near * CMapStudioModel::CreateMapStudioModel(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapStudioModel *__cdecl CMapStudioModel::CreateMapStudioModel(CHelperInfo *pHelperInfo, CMapEntity *pParent)
{
  char *Value; // esi
  int v4; // eax
  bool bLightProp; // [esp+14h] [ebp+8h]

  if ( pHelperInfo->m_Parameters.m_Size <= 0 || (Value = *pHelperInfo->m_Parameters.m_Memory.m_pMemory) == nullptr )
  {
    Value = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(
                      this: &pParent->m_KeyValues,
                      pszKey: "model",
                      piIndex: nullptr);
    if ( Value == nullptr )
      return nullptr;
  }
  bLightProp = _V_stricmp(s1: pHelperInfo->m_szName, s2: "lightprop") == 0;
  v4 = _V_stricmp(s1: pHelperInfo->m_szName, s2: "studioprop");
  return CMapStudioModel::CreateMapStudioModel(
           pszModelPath: Value,
           bOrientedBounds: bLightProp || v4 == 0,
           bReversePitch: bLightProp);
}
