// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/maplightcone.cpp
// Functions: 14
// ============================================================

#include "hammer\maplightcone.h"

//------------------------------------------------------------------------------
// Address: 0x10131130
// Name: public: virtual char const __near * CMapLightCone::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapLightCone::GetType(CMapLightCone *this)
{
  return CMapLightCone::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10131140
// Name: public: virtual int CMapLightCone::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapLightCone::IsMapClass(CMapLightCone *this, const char *Type)
{
  return Type == CMapLightCone::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10131160
// Name: public: virtual void CMapLightCone::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLightCone::CalcBounds(CMapLightCone *this, int bFullUpdate)
{
  CMapClass *v3; // eax

  CMapClass::CalcBounds(this, bFullUpdate);
  if ( this->m_pParent != nullptr )
  {
    v3 = this->GetParent(this);
    v3->GetOrigin(this: v3, a2: &this->m_Origin);
  }
  BoundBox::ResetBounds(this: &this->m_Render2DBox);
  BoundBox::UpdateBounds(this: &this->m_Render2DBox, pt: &this->m_Origin);
  CMapClass::SetCullBoxFromFaceList(this, pFaces: &this->m_Faces);
}

//------------------------------------------------------------------------------
// Address: 0x101311C0
// Name: public: virtual void CMapLightCone::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapLightCone::Render3D(CMapLightCone *this@<ecx>, int a2@<ebx>, int a3@<edi>, CRender3D *pRender)
{
  int v5; // edi
  CRender3D *v6; // ebx
  EditorRenderMode_t m_eCurrentRenderMode; // eax
  int i; // ebx
  CMapFace *v9; // ecx
  int j; // ebx
  CMapFace *v11; // ecx
  float x; // [esp+1Ch] [ebp-1Ch]
  float z; // [esp+24h] [ebp-14h]

  if ( this->m_pParent->IsSelected(this: this->m_pParent) )
  {
    v5 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2: a3, a3: a2);
    if ( v5 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 80))(a1: v5, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 84))(a1: v5);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v5 + 144))(
      a1: v5,
      a2: LODWORD(this->m_Origin.x),
      a3: LODWORD(this->m_Origin.y),
      a4: LODWORD(this->m_Origin.z));
    x = this->m_Angles.x;
    z = this->m_Angles.z;
    if ( this->m_bPitchSet )
      x = this->m_fPitch;
    (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v5 + 140))(a1: v5, a2: LODWORD(this->m_Angles.y), a3: 0);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)v5 + 140))(
      a1: v5,
      a2: this->m_flPitchScale * x,
      a3: 0,
      a4: -1082130432,
      a5: 0);
    (*(void (__thiscall **)(int, float, int, _DWORD, _DWORD))(*(_DWORD *)v5 + 140))(
      a1: v5,
      a2: COERCE_FLOAT(LODWORD(z)),
      a3: 1065353216,
      a4: 0,
      a5: 0);
    v6 = pRender;
    m_eCurrentRenderMode = pRender->m_eCurrentRenderMode;
    if ( m_eCurrentRenderMode != RENDER_MODE_LIGHT_PREVIEW2
      && m_eCurrentRenderMode != RENDER_MODE_LIGHT_PREVIEW_RAYTRACED
      && this->GetSelectionState(this) != SELECT_MODIFY )
    {
      CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_TRANSLUCENT_FLAT);
      for ( i = 0; i < this->m_Faces.m_Size; ++i )
      {
        v9 = this->m_Faces.m_Memory.m_pMemory[i];
        v9->Render3D(this: v9, a2: pRender);
      }
      CRender::PopRenderMode(this: pRender);
      v6 = pRender;
    }
    CRender::PushRenderMode(this: v6, eRenderMode: RENDER_MODE_WIREFRAME);
    for ( j = 0; j < this->m_Faces.m_Size; ++j )
    {
      v11 = this->m_Faces.m_Memory.m_pMemory[j];
      v11->Render3D(this: v11, a2: pRender);
    }
    CRender::PopRenderMode(this: pRender);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 88))(a1: v5);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10131430
// Name: public: virtual CMapLightCone::~CMapLightCone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLightCone::~CMapLightCone(CMapLightCone *this)
{
  int i; // esi
  CMapFace **m_pMemory; // eax
  CMapFace *v4; // ebx
  CMapFaceList *p_m_Faces; // esi

  this->__vftable = (CMapLightCone_vtbl *)&CMapLightCone::`vftable';
  for ( i = 0; i < this->m_Faces.m_Size; ++i )
  {
    m_pMemory = this->m_Faces.m_Memory.m_pMemory;
    v4 = m_pMemory[i];
    if ( v4 != nullptr )
    {
      CMapFace::~CMapFace(this: m_pMemory[i]);
      operator delete(p: v4);
    }
  }
  SignalUpdate(ev: 1);
  p_m_Faces = &this->m_Faces;
  this->m_Faces.m_Size = 0;
  if ( this->m_Faces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Faces->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Faces->m_Memory.m_pMemory);
      p_m_Faces->m_Memory.m_pMemory = nullptr;
    }
    this->m_Faces.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Faces.m_pElements = this->m_Faces.m_Memory.m_pMemory;
  if ( this->m_Faces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Faces->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Faces->m_Memory.m_pMemory);
      p_m_Faces->m_Memory.m_pMemory = nullptr;
    }
    this->m_Faces.m_Memory.m_nAllocationCount = 0;
  }
  CMapClass::~CMapClass(this);
}

//------------------------------------------------------------------------------
// Address: 0x10131510
// Name: public: virtual char const __near * CMapLightCone::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapLightCone::GetDescription(CMapLightCone *this)
{
  return "Light cone helper";
}

//------------------------------------------------------------------------------
// Address: 0x10131520
// Name: public: CMapLightCone::CMapLightCone(void)
// Source: json
//------------------------------------------------------------------------------
CMapLightCone *__thiscall CMapLightCone::CMapLightCone(CMapLightCone *this)
{
  CMapFace **m_pMemory; // edx

  CMapClass::CMapClass(this);
  this->__vftable = (CMapLightCone_vtbl *)&CMapHelper::`vftable';
  this->__vftable = (CMapLightCone_vtbl *)&CMapLightCone::`vftable';
  this->m_Faces.m_Memory.m_pMemory = nullptr;
  this->m_Faces.m_Memory.m_nAllocationCount = 0;
  this->m_Faces.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_Faces.m_Memory.m_pMemory;
  this->m_Faces.m_Size = 0;
  this->m_Faces.m_pElements = m_pMemory;
  this->m_fQuadraticAttn = 1.0;
  this->m_fFocus = 1.0;
  this->m_flPitchScale = 1.0;
  this->m_fBrightness = 100.0;
  this->m_fOuterConeAngle = 45.0;
  this->m_fLinearAttn = 0.0;
  this->m_fConstantAttn = 0.0;
  this->m_bPitchSet = false;
  this->m_fPitch = 0.0;
  this->m_fInnerConeAngle = 0.0;
  this->m_fFiftyPercentDistance = -1.0;
  this->m_Angles.x = 0.0;
  this->m_Angles.y = 0.0;
  this->m_Angles.z = 0.0;
  SignalUpdate(ev: 1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10131670
// Name: protected: void CMapLightCone::BuildCone(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CMapLightCone::BuildCone(CMapLightCone *this)
{
  CMapLightCone *v1; // ebx
  int m_Size; // eax
  int v3; // esi
  CMapFace **m_pMemory; // eax
  CMapFace *v5; // edi
  CUtlMemory<CCullTreeNode *,int> *p_m_Faces; // esi
  float m_fQuadraticAttn; // xmm3_4
  float m_fLinearAttn; // xmm5_4
  float m_fConstantAttn; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  bool v12; // zf
  float v13; // xmm3_4
  float v14; // xmm7_4
  float v15; // xmm5_4
  float v16; // xmm5_4
  float v17; // xmm3_4
  float v18; // xmm6_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm5_4
  float v22; // xmm3_4
  float v23; // xmm5_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm1_4
  float m_fOuterConeAngle; // xmm1_4
  int i; // eax
  int v30; // ecx
  int v31; // eax
  double v32; // xmm0_8
  double v33; // xmm0_8
  float v34; // xmm1_4
  CMapFace *v35; // eax
  CMapFace *v36; // edi
  CCullTreeNode **v37; // ebx
  int m_nAllocationCount; // eax
  CCullTreeNode **v39; // ecx
  int v40; // eax
  CMapFace **v41; // ebx
  int v42; // xmm0_4
  double v43; // xmm0_8
  float v44; // xmm0_4
  float v45; // xmm1_4
  float m_fFocus; // xmm1_4
  float v47; // xmm0_4
  double v48; // xmm0_8
  int v49; // eax
  double v50; // xmm0_8
  double v51; // xmm0_8
  float v52; // xmm1_4
  CMapFace *v53; // eax
  CMapFace *v54; // edi
  CCullTreeNode **v55; // ebx
  int v56; // eax
  CCullTreeNode **v57; // ecx
  int v58; // eax
  CMapFace **v59; // ebx
  float v60; // xmm2_4
  bool v61; // cc
  int v62; // [esp-8h] [ebp-C0h]
  int v63; // [esp-8h] [ebp-C0h]
  long double v64; // [esp+0h] [ebp-B8h]
  long double v65; // [esp+0h] [ebp-B8h]
  long double v66; // [esp+0h] [ebp-B8h]
  long double v67; // [esp+0h] [ebp-B8h]
  long double v68; // [esp+0h] [ebp-B8h]
  long double v69; // [esp+0h] [ebp-B8h]
  _BYTE v70[9]; // [esp+8h] [ebp-B0h] OVERLAPPED
  void *v71; // [esp+20h] [ebp-98h]
  float v72; // [esp+24h] [ebp-94h]
  float v73; // [esp+28h] [ebp-90h]
  Vector Points[4]; // [esp+2Ch] [ebp-8Ch] BYREF
  void *p; // [esp+5Ch] [ebp-5Ch]
  float fOuterDot; // [esp+60h] [ebp-58h]
  float v77; // [esp+64h] [ebp-54h]
  int fCos1; // [esp+68h] [ebp-50h]
  float fZoneDist[5]; // [esp+6Ch] [ebp-4Ch] BYREF
  float fBottomDist; // [esp+80h] [ebp-38h]
  float fTopDist; // [esp+84h] [ebp-34h]
  float fFocusDist1; // [esp+88h] [ebp-30h]
  float fFocusRadius1; // [esp+8Ch] [ebp-2Ch]
  float fSin0; // [esp+90h] [ebp-28h]
  float fSin1; // [esp+94h] [ebp-24h]
  CMapLightCone *v86; // [esp+98h] [ebp-20h]
  float fFocusDist0; // [esp+9Ch] [ebp-1Ch]
  int nPoints; // [esp+A0h] [ebp-18h]
  int fIllumination; // [esp+A4h] [ebp-14h]
  float fPitch; // [esp+A8h] [ebp-10h]
  int v91; // [esp+B4h] [ebp-4h]

  v1 = this;
  m_Size = this->m_Faces.m_Size;
  v3 = 0;
  v86 = this;
  if ( m_Size > 0 )
  {
    do
    {
      m_pMemory = v1->m_Faces.m_Memory.m_pMemory;
      v5 = m_pMemory[v3];
      if ( v5 != nullptr )
      {
        CMapFace::~CMapFace(this: m_pMemory[v3]);
        operator delete(p: v5);
      }
      ++v3;
    }
    while ( v3 < v1->m_Faces.m_Size );
  }
  p_m_Faces = (CUtlMemory<CCullTreeNode *,int> *)&v1->m_Faces;
  v1->m_Faces.m_Size = 0;
  m_fQuadraticAttn = v1->m_fQuadraticAttn;
  if ( m_fQuadraticAttn == 0.0 && v1->m_fLinearAttn == 0.0 && v1->m_fConstantAttn == 0.0 )
    v1->m_fConstantAttn = 1.0;
  m_fLinearAttn = v1->m_fLinearAttn;
  m_fConstantAttn = v1->m_fConstantAttn;
  v10 = (float)((float)(m_fLinearAttn * 100.0) + (float)(m_fQuadraticAttn * 10000.0)) + m_fConstantAttn;
  if ( v10 != 0.0 )
  {
    v11 = m_fQuadraticAttn;
    v12 = m_fQuadraticAttn == 0.0;
    memset(fZoneDist, 0, sizeof(fZoneDist));
    fFocusDist0 = m_fLinearAttn;
    v13 = m_fConstantAttn - (float)(v10 * 0.25);
    if ( v12 )
    {
      if ( m_fLinearAttn != 0.0 )
      {
        v14 = (float)(-1.0 / m_fLinearAttn) * v13;
        fZoneDist[1] = v14;
LABEL_16:
        v16 = v1->m_fQuadraticAttn;
        v17 = v1->m_fLinearAttn;
        v18 = m_fConstantAttn - v10;
        if ( v16 == 0.0 )
        {
          if ( v17 != 0.0 )
            fZoneDist[2] = (float)(-1.0 / v17) * v18;
        }
        else
        {
          v14 = fZoneDist[1];
          v19 = (float)(v17 * v17) - (float)((float)(v16 * 4.0) * v18);
          if ( v19 > 0.0 )
            fZoneDist[2] = (float)(fsqrt(v19) - v1->m_fLinearAttn) / (float)(v16 * 2.0);
        }
        v20 = v1->m_fQuadraticAttn;
        v21 = v1->m_fLinearAttn;
        v22 = m_fConstantAttn - (float)(v10 * 4.0);
        if ( v20 == 0.0 )
        {
          if ( v21 != 0.0 )
            fZoneDist[3] = (float)(-1.0 / v21) * v22;
        }
        else
        {
          v14 = fZoneDist[1];
          v23 = (float)(v21 * v21) - (float)((float)(v20 * 4.0) * v22);
          if ( v23 > 0.0 )
            fZoneDist[3] = (float)(fsqrt(v23) - v1->m_fLinearAttn) / (float)(v20 * 2.0);
        }
        v24 = v1->m_fQuadraticAttn;
        v25 = v1->m_fLinearAttn;
        v26 = m_fConstantAttn - (float)(v10 * 10.0);
        if ( v24 == 0.0 )
        {
          if ( v25 != 0.0 )
            fZoneDist[4] = (float)(-1.0 / v25) * v26;
        }
        else
        {
          v27 = (float)(v25 * v25) - (float)((float)(v24 * 4.0) * v26);
          if ( v27 > 0.0 )
            fZoneDist[4] = (float)(fsqrt(v27) - v25) / (float)(v24 * 2.0);
        }
        m_fOuterConeAngle = v1->m_fOuterConeAngle;
        if ( m_fOuterConeAngle < 90.0 )
        {
          __libm_sse2_tan(x: v64);
          for ( i = 0; i < 5; ++i )
            *(float *)&v70[i * 4 + 4] = fZoneDist[i] * (float)(m_fOuterConeAngle * 0.017453292);
          v30 = 0;
          for ( fPitch = 0.0; ; v30 = LODWORD(fPitch) )
          {
            fTopDist = fZoneDist[v30];
            fBottomDist = fZoneDist[v30 + 1];
            fFocusRadius1 = *(float *)&v70[4 * v30 + 4];
            fFocusDist1 = *(float *)&v70[4 * v30 + 8];
            fSin0 = 0.0;
            *(float *)&nPoints = 1.0;
            v31 = 24;
            v77 = 1.0 - (float)((float)v30 * 0.2);
            do
            {
              fOuterDot = (float)v31;
              fFocusDist0 = (float)v31 * 0.017453292;
              v32 = fFocusDist0;
              __libm_sse2_sin(x: v64);
              *(float *)&v32 = v32;
              fSin1 = *(float *)&v32;
              v33 = fFocusDist0;
              __libm_sse2_cos(x: v65);
              v34 = v33;
              Points[0].z = v34 * fFocusDist1;
              Points[0].y = fSin1 * fFocusDist1;
              Points[1].y = fFocusDist1 * fSin0;
              Points[0].x = fBottomDist;
              Points[1].x = fBottomDist;
              Points[1].z = fFocusDist1 * *(float *)&nPoints;
              *(float *)&fCos1 = v34;
              Points[2].z = fFocusRadius1 * *(float *)&nPoints;
              Points[2].y = fFocusRadius1 * fSin0;
              Points[2].x = fTopDist;
              fIllumination = 3;
              if ( fFocusRadius1 != 0.0 )
              {
                Points[3].z = v34 * fFocusRadius1;
                Points[3].y = fSin1 * fFocusRadius1;
                Points[3].x = fTopDist;
                fIllumination = 4;
              }
              *(float *)&v35 = COERCE_FLOAT(operator new(nSize: 0x1BCu));
              p = v35;
              v36 = nullptr;
              v91 = 0;
              if ( *(float *)&v35 != 0.0 )
                v36 = CMapFace::CMapFace(this: v35);
              v91 = -1;
              v36->SetRenderColor_2(
                this: v36,
                a2: (int)(float)((float)v1->r * v77),
                a3: (int)(float)((float)v1->g * v77),
                a4: (int)(float)((float)v1->b * v77));
              v62 = fIllumination;
              v36->m_uchAlpha = -76;
              CMapFace::CreateFace(this: v36, a2: (int)v1, pPoints: Points, _nPoints: v62, bIsCordonFace: false);
              CMapFace::RenderUnlit(this: v36, enable: true);
              v37 = p_m_Faces[1].m_pMemory;
              m_nAllocationCount = p_m_Faces->m_nAllocationCount;
              if ( (int)v37 + 1 > m_nAllocationCount )
                CUtlMemory<CVisGroup *,int>::Grow(this: p_m_Faces, num: (int)v37 - m_nAllocationCount + 1);
              ++p_m_Faces[1].m_pMemory;
              v39 = p_m_Faces->m_pMemory;
              v40 = (char *)p_m_Faces[1].m_pMemory - (char *)v37 - 1;
              p_m_Faces[1].m_nAllocationCount = (int)p_m_Faces->m_pMemory;
              if ( v40 > 0 )
                _V_memmove(dest: &v39[(_DWORD)v37 + 1], src: &v39[(_DWORD)v37], count: 4 * v40);
              v41 = (CMapFace **)&p_m_Faces->m_pMemory[(_DWORD)v37];
              if ( v41 != nullptr )
                *v41 = v36;
              v1 = v86;
              fSin0 = fSin1;
              nPoints = fCos1;
              v31 = (int)(float)(fOuterDot + 24.0);
            }
            while ( v31 <= 361 );
            ++LODWORD(fPitch);
            if ( SLODWORD(fPitch) >= 4 )
              break;
          }
          v14 = fZoneDist[1];
        }
        nPoints = SLODWORD(v1->m_fOuterConeAngle);
        if ( *(float *)&nPoints <= 90.0 )
        {
          fBottomDist = 0.0;
          *(float *)&v42 = v1->m_fInnerConeAngle * 0.017453292;
          fFocusDist0 = v14;
          __libm_sse2_cos(x: v64);
          fCos1 = v42;
          v43 = (float)(*(float *)&nPoints * 0.017453292);
          __libm_sse2_cos(x: v66);
          *(float *)&v43 = v43;
          fOuterDot = *(float *)&v43;
          v44 = 6.0;
          fPitch = 6.0;
          if ( (float)(*(float *)&nPoints + 6.0) > 6.0 )
          {
            while ( 1 )
            {
              fSin1 = 0.0;
              v45 = v1->m_fOuterConeAngle;
              fTopDist = 1.0;
              if ( v44 > v45 )
              {
                v44 = v45;
                fPitch = v45;
              }
              if ( v1->m_fInnerConeAngle < v44 )
              {
                __libm_sse2_cos(x: v67);
                m_fFocus = v1->m_fFocus;
                v47 = (float)((float)(v44 * 0.017453292) - fOuterDot) / (float)(*(float *)&fCos1 - fOuterDot);
                *(float *)&fIllumination = v47;
                if ( m_fFocus != 1.0 && m_fFocus != 0.0 )
                {
                  __libm_sse2_pow(x: v67, y: *(long double *)v70);
                  *(float *)&fIllumination = v47;
                }
                v44 = fPitch;
              }
              else
              {
                *(float *)&fIllumination = 1.0;
              }
              v77 = v44 * 0.017453292;
              __libm_sse2_cos(x: v67);
              fFocusDist1 = (float)((float)(v44 * 0.017453292) * *(float *)&fIllumination) * fZoneDist[1];
              v48 = v77;
              __libm_sse2_sin(x: v68);
              *(float *)&v48 = v48;
              fFocusRadius1 = (float)(*(float *)&v48 * *(float *)&fIllumination) * fZoneDist[1];
              v49 = 24;
              while ( 1 )
              {
                *(float *)&p = (float)v49;
                v72 = (float)v49 * 0.017453292;
                v50 = v72;
                __libm_sse2_sin(x: v67);
                *(float *)&v50 = v50;
                fSin0 = *(float *)&v50;
                v51 = v72;
                __libm_sse2_cos(x: v69);
                v52 = v51;
                Points[0].z = fFocusRadius1 * fTopDist;
                Points[0].y = fFocusRadius1 * fSin1;
                Points[1].z = v52 * fFocusRadius1;
                v73 = v52;
                Points[2].z = v52 * fBottomDist;
                Points[0].x = fFocusDist1;
                Points[1].y = fSin0 * fFocusRadius1;
                Points[1].x = fFocusDist1;
                Points[2].y = fSin0 * fBottomDist;
                Points[2].x = fFocusDist0;
                nPoints = 3;
                if ( fBottomDist != 0.0 )
                {
                  Points[3].z = fTopDist * fBottomDist;
                  Points[3].y = fSin1 * fBottomDist;
                  Points[3].x = fFocusDist0;
                  nPoints = 4;
                }
                v53 = (CMapFace *)operator new(nSize: 0x1BCu);
                v71 = v53;
                v91 = 1;
                if ( v53 != nullptr )
                  v54 = CMapFace::CMapFace(this: v53);
                else
                  v54 = nullptr;
                v91 = -1;
                v54->SetRenderColor_2(
                  this: v54,
                  a2: (int)(float)((float)v1->r * *(float *)&fIllumination),
                  a3: (int)(float)((float)v1->g * *(float *)&fIllumination),
                  a4: (int)(float)((float)v1->b * *(float *)&fIllumination));
                v63 = nPoints;
                v54->m_uchAlpha = -76;
                CMapFace::CreateFace(this: v54, a2: (int)v1, pPoints: Points, _nPoints: v63, bIsCordonFace: false);
                CMapFace::RenderUnlit(this: v54, enable: true);
                v55 = p_m_Faces[1].m_pMemory;
                v56 = p_m_Faces->m_nAllocationCount;
                if ( (int)v55 + 1 > v56 )
                  CUtlMemory<CVisGroup *,int>::Grow(this: p_m_Faces, num: (int)v55 - v56 + 1);
                ++p_m_Faces[1].m_pMemory;
                v57 = p_m_Faces->m_pMemory;
                v58 = (char *)p_m_Faces[1].m_pMemory - (char *)v55 - 1;
                p_m_Faces[1].m_nAllocationCount = (int)p_m_Faces->m_pMemory;
                if ( v58 > 0 )
                  _V_memmove(dest: &v57[(_DWORD)v55 + 1], src: &v57[(_DWORD)v55], count: 4 * v58);
                v59 = (CMapFace **)&p_m_Faces->m_pMemory[(_DWORD)v55];
                if ( v59 != nullptr )
                  *v59 = v54;
                fSin1 = fSin0;
                fTopDist = v73;
                v49 = (int)(float)(*(float *)&p + 24.0);
                if ( v49 > 361 )
                  break;
                v1 = v86;
              }
              v60 = v86->m_fOuterConeAngle;
              fBottomDist = fFocusRadius1;
              fFocusDist0 = fFocusDist1;
              v44 = fPitch + 6.0;
              v61 = (float)(v60 + 6.0) <= (float)(fPitch + 6.0);
              fPitch = fPitch + 6.0;
              if ( v61 )
                break;
              v1 = v86;
            }
          }
        }
        return;
      }
    }
    else
    {
      v15 = (float)(m_fLinearAttn * m_fLinearAttn) - (float)((float)(v11 * 4.0) * v13);
      if ( v15 > 0.0 )
      {
        v14 = (float)(fsqrt(v15) - fFocusDist0) / (float)(v11 * 2.0);
        fZoneDist[1] = v14;
        goto LABEL_16;
      }
    }
    v14 = fZoneDist[1];
    goto LABEL_16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132070
// Name: public: virtual class CMapClass __near * CMapLightCone::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapLightCone *__thiscall CMapLightCone::Copy(CMapLightCone *this, BOOL bUpdateDependencies)
{
  CMapLightCone *v3; // eax
  CMapLightCone *v4; // esi

  v3 = (CMapLightCone *)operator new(nSize: 0x224u);
  if ( v3 != nullptr )
    v4 = CMapLightCone::CMapLightCone(this: v3);
  else
    v4 = nullptr;
  if ( v4 != nullptr )
    v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101320F0
// Name: public: virtual class CMapClass __near * CMapLightCone::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapLightCone *__thiscall CMapLightCone::CopyFrom(CMapLightCone *this, CMapClass *pObject, bool bUpdateDependencies)
{
  CMapClass::CopyFrom(this, pFrom: (CVisGroup *)pObject, bUpdateDependencies);
  this->m_fBrightness = *(float *)&pObject[1].m_References.m_pHead;
  this->m_fQuadraticAttn = *(float *)&pObject[1].__vftable;
  this->m_fLinearAttn = *(float *)&pObject[1].m_nObjectID;
  this->m_fConstantAttn = *(float *)&pObject[1].m_pParent;
  this->m_flPitchScale = pObject[2].m_Render2DBox.bmaxs.x;
  this->m_fInnerConeAngle = *(float *)&pObject[1].dwKept;
  this->m_fOuterConeAngle = *(float *)&pObject[1].m_CullBox.__vftable;
  this->m_Angles = (QAngle)pObject[1].m_CullBox.bmins;
  this->m_bPitchSet = LOBYTE(pObject[1].m_CullBox.bmaxs.x);
  this->m_fPitch = pObject[1].m_CullBox.bmaxs.y;
  this->m_fFocus = pObject[1].m_CullBox.bmaxs.z;
  this->m_fFiftyPercentDistance = *(float *)&pObject[1].m_eSelectionState;
  this->m_fZeroPercentDistance = *(float *)&pObject[1].r;
  this->m_LightColor = pObject[1].m_Origin;
  V_strncpy(pDest: this->m_szColorKeyName, pSrc: (const char *)&pObject[1].m_BoundingBox.bmaxs.y, maxLen: 80);
  V_strncpy(pDest: this->m_szInnerConeKeyName, pSrc: (const char *)&pObject[1].m_nLoadID, maxLen: 80);
  V_strncpy(pDest: this->m_szOuterConeKeyName, pSrc: (const char *)&pObject[2].m_References, maxLen: 80);
  CMapLightCone::BuildCone(this);
  SignalUpdate(ev: 1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10132240
// Name: public: virtual void CMapLightCone::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLightCone::OnParentKeyChanged(CMapLightCone *this, const char *szKey, const char *szValue)
{
  const char *v3; // edi
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  float v8; // xmm0_4
  int v9; // eax
  const char *v10; // ebx
  const char *v11; // [esp-4h] [ebp-18h]
  int nBrightness; // [esp+Ch] [ebp-8h] BYREF
  int nBlue; // [esp+10h] [ebp-4h] BYREF

  v3 = szKey;
  if ( _V_stricmp(s1: szKey, s2: "angles") == 0 )
  {
    sscanf(string: szValue, format: "%f %f %f", &this->m_Angles, &this->m_Angles.y, &this->m_Angles.z);
LABEL_25:
    SignalUpdate(ev: 1);
    CMapLightCone::BuildCone(this);
    this->PostUpdate(this, a2: Notify_Changed);
    return;
  }
  if ( _V_stricmp(s1: v3, s2: this->m_szColorKeyName) == 0 )
  {
    sscanf(string: szValue, format: "%d %d %d %d", &szValue, &szKey, &nBlue, &nBrightness);
    v5 = (int)(float)(int)szValue;
    this->m_LightColor.x = (float)(int)szValue;
    v6 = (int)(float)(int)szKey;
    this->m_LightColor.y = (float)(int)szKey;
    v7 = (int)(float)nBlue;
    this->m_LightColor.z = (float)nBlue;
    v8 = (float)nBrightness;
    this->r = v5;
    this->g = v6;
    this->b = v7;
    this->m_fBrightness = v8;
    goto LABEL_25;
  }
  if ( _V_stricmp(s1: v3, s2: "pitch") == 0 )
  {
    v11 = szValue;
    this->m_bPitchSet = true;
    this->m_fPitch = atof(nptr: v11);
    goto LABEL_25;
  }
  if ( _V_stricmp(s1: v3, s2: "_constant_attn") == 0 )
  {
    this->m_fConstantAttn = atof(nptr: szValue);
    goto LABEL_25;
  }
  if ( _V_stricmp(s1: v3, s2: "_linear_attn") == 0 )
  {
    this->m_fLinearAttn = atof(nptr: szValue);
    goto LABEL_25;
  }
  if ( _V_stricmp(s1: v3, s2: "_quadratic_attn") == 0 )
  {
    this->m_fQuadraticAttn = atof(nptr: szValue);
    goto LABEL_25;
  }
  if ( _V_stricmp(s1: v3, s2: "_exponent") == 0 )
  {
    this->m_fFocus = atof(nptr: szValue);
    goto LABEL_25;
  }
  if ( _V_stricmp(s1: v3, s2: "_fifty_percent_distance") == 0 )
  {
    this->m_fFiftyPercentDistance = atof(nptr: szValue);
    goto LABEL_25;
  }
  if ( _V_stricmp(s1: v3, s2: "_zero_percent_distance") == 0 )
  {
    this->m_fZeroPercentDistance = atof(nptr: szValue);
    goto LABEL_25;
  }
  if ( _V_stricmp(s1: v3, s2: this->m_szInnerConeKeyName) == 0
    || _V_stricmp(s1: v3, s2: this->m_szOuterConeKeyName) == 0 )
  {
    v9 = _V_stricmp(s1: v3, s2: this->m_szInnerConeKeyName);
    v10 = szValue;
    if ( v9 == 0 )
      this->m_fInnerConeAngle = atof(nptr: szValue);
    if ( _V_stricmp(s1: v3, s2: this->m_szOuterConeKeyName) == 0 )
      this->m_fOuterConeAngle = atof(nptr: v10);
    goto LABEL_25;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101324C0
// Name: public: virtual void CMapLightCone::PostloadWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLightCone::PostloadWorld(CMapLightCone *this, CMapWorld *pWorld)
{
  CMapClass::PostloadWorld(this, pWorld);
  CMapLightCone::BuildCone(this);
  SignalUpdate(ev: 1);
  this->CalcBounds(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10132500
// Name: class CMapClass __near * CMapLightCone_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapLightCone *__cdecl CMapLightCone_CreateObject()
{
  CMapLightCone *v0; // eax

  v0 = (CMapLightCone *)operator new(nSize: 0x224u);
  if ( v0 != nullptr )
    return CMapLightCone::CMapLightCone(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10132560
// Name: public: static class CMapClass __near * CMapLightCone::Create(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapLightCone *__cdecl CMapLightCone::Create(CHelperInfo *pHelperInfo)
{
  CMapLightCone *v1; // eax
  CMapLightCone *v2; // esi
  char *v3; // eax
  int v4; // edx
  char v5; // cl
  char *v6; // eax
  int v7; // edx
  char v8; // cl
  char *v9; // eax
  int v10; // edx
  char v11; // cl

  v1 = (CMapLightCone *)operator new(nSize: 0x224u);
  if ( v1 != nullptr )
    v2 = CMapLightCone::CMapLightCone(this: v1);
  else
    v2 = nullptr;
  if ( v2 != nullptr )
  {
    if ( pHelperInfo->m_Parameters.m_Size > 0 && (v3 = *pHelperInfo->m_Parameters.m_Memory.m_pMemory) != nullptr )
    {
      v4 = v2->m_szInnerConeKeyName - v3;
      do
      {
        v5 = *v3;
        v3[v4] = *v3;
        ++v3;
      }
      while ( v5 != 0 );
    }
    else
    {
      strcpy(v2->m_szInnerConeKeyName, "_inner_cone");
    }
    if ( pHelperInfo->m_Parameters.m_Size > 1 && (v6 = pHelperInfo->m_Parameters.m_Memory.m_pMemory[1]) != nullptr )
    {
      v7 = v2->m_szOuterConeKeyName - v6;
      do
      {
        v8 = *v6;
        v6[v7] = *v6;
        ++v6;
      }
      while ( v8 != 0 );
    }
    else
    {
      strcpy(v2->m_szOuterConeKeyName, "_cone");
    }
    if ( pHelperInfo->m_Parameters.m_Size > 2 && (v9 = pHelperInfo->m_Parameters.m_Memory.m_pMemory[2]) != nullptr )
    {
      v10 = v2->m_szColorKeyName - v9;
      do
      {
        v11 = *v9;
        v9[v10] = *v9;
        ++v9;
      }
      while ( v11 != 0 );
    }
    else
    {
      strcpy(v2->m_szColorKeyName, "_light");
    }
    if ( pHelperInfo->m_Parameters.m_Size > 3 && *((_DWORD *)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 3) != 0 )
    {
      v2->m_flPitchScale = V_atof(str: *((const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 3));
      return v2;
    }
    v2->m_flPitchScale = 1.0;
  }
  return v2;
}
