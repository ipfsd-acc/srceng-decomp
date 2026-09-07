// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapfrustum.cpp
// Functions: 15
// ============================================================

#include "hammer\mapfrustum.h"

//------------------------------------------------------------------------------
// Address: 0x1012D590
// Name: public: virtual char const __near * CMapFrustum::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapFrustum::GetType(CMapFrustum *this)
{
  return CMapFrustum::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1012D5A0
// Name: public: virtual int CMapFrustum::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapFrustum::IsMapClass(CMapFrustum *this, const char *Type)
{
  return Type == CMapFrustum::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1012D5C0
// Name: private: class CMapFace __near * CMapFrustum::CreateMapFace(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
CMapFace *__userpurge CMapFrustum::CreateMapFace@<eax>(
        CMapFrustum *this@<ecx>,
        int a2@<ebx>,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *v4,
        float flAlpha)
{
  __int64 v7; // xmm0_8
  float z; // ecx
  float v10; // edx
  float v11; // eax
  CMapFace *v12; // eax
  CMapFace *v13; // esi
  Vector points[4]; // [esp+0h] [ebp-3Ch] BYREF
  int v16; // [esp+38h] [ebp-4h]

  v7 = *(_QWORD *)&v1->x;
  points[0].z = v1->z;
  *(_QWORD *)&points[0].x = v7;
  z = v2->z;
  v10 = v3->z;
  *(_QWORD *)&points[1].x = *(_QWORD *)&v2->x;
  *(_QWORD *)&points[2].x = *(_QWORD *)&v3->x;
  v11 = v4->z;
  points[1].z = z;
  points[2].z = v10;
  *(_QWORD *)&points[3].x = *(_QWORD *)&v4->x;
  points[3].z = v11;
  v12 = (CMapFace *)operator new(nSize: 0x1BCu);
  v16 = 0;
  if ( v12 != nullptr )
    v13 = CMapFace::CMapFace(this: v12);
  else
    v13 = nullptr;
  v16 = -1;
  v13->SetRenderColor_2(this: v13, a2: this->r, a3: this->g, a4: this->b);
  v13->m_uchAlpha = (int)flAlpha;
  CMapFace::CreateFace(this: v13, a2, pPoints: points, _nPoints: 4, bIsCordonFace: false);
  CMapFace::RenderUnlit(this: v13, enable: true);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x1012D6B0
// Name: public: virtual void CMapFrustum::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFrustum::CalcBounds(CMapFrustum *this, int bFullUpdate)
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
// Address: 0x1012D710
// Name: public: virtual void CMapFrustum::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapFrustum::Render3D(CMapFrustum *this@<ecx>, int a2@<ebx>, int a3@<edi>, CRender3D *pRender)
{
  int v5; // edi
  EditorRenderMode_t m_eCurrentRenderMode; // eax
  CMapFace *v8; // ecx
  CMapFace *v9; // ecx
  float x; // [esp+1Ch] [ebp-1Ch]
  float z; // [esp+24h] [ebp-14h]
  int i; // [esp+40h] [ebp+8h]
  int j; // [esp+40h] [ebp+8h]

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
    z = this->m_Angles.z;
    x = this->m_Angles.x;
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)v5 + 140))(
      a1: v5,
      a2: LODWORD(this->m_Angles.y),
      a3: 0,
      a4: 0,
      a5: 1065353216);
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
    m_eCurrentRenderMode = pRender->m_eCurrentRenderMode;
    if ( m_eCurrentRenderMode != RENDER_MODE_LIGHT_PREVIEW2
      && m_eCurrentRenderMode != RENDER_MODE_LIGHT_PREVIEW_RAYTRACED
      && this->GetSelectionState(this) != SELECT_MODIFY )
    {
      CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_TRANSLUCENT_FLAT);
      for ( i = 0; i < this->m_Faces.m_Size; ++i )
      {
        v8 = this->m_Faces.m_Memory.m_pMemory[i];
        v8->Render3D(this: v8, a2: pRender);
      }
      CRender::PopRenderMode(this: pRender);
    }
    CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
    for ( j = 0; j < this->m_Faces.m_Size; ++j )
    {
      v9 = this->m_Faces.m_Memory.m_pMemory[j];
      v9->Render3D(this: v9, a2: pRender);
    }
    CRender::PopRenderMode(this: pRender);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 88))(a1: v5);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D970
// Name: public: virtual CMapFrustum::~CMapFrustum(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFrustum::~CMapFrustum(CMapFrustum *this)
{
  int i; // esi
  CMapFace **m_pMemory; // eax
  CMapFace *v4; // ebx
  CMapFaceList *p_m_Faces; // esi
  bool v6; // sf

  this->__vftable = (CMapFrustum_vtbl *)&CMapFrustum::`vftable';
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
  p_m_Faces = &this->m_Faces;
  v6 = this->m_Faces.m_Memory.m_nGrowSize < 0;
  this->m_Faces.m_Size = 0;
  if ( !v6 )
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
// Address: 0x1012DA60
// Name: public: virtual char const __near * CMapFrustum::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapFrustum::GetDescription(CMapFrustum *this)
{
  return "Frustum helper";
}

//------------------------------------------------------------------------------
// Address: 0x1012DA70
// Name: public: CMapFrustum::CMapFrustum(void)
// Source: json
//------------------------------------------------------------------------------
CMapFrustum *__thiscall CMapFrustum::CMapFrustum(CMapFrustum *this)
{
  CMapClass::CMapClass(this);
  this->__vftable = (CMapFrustum_vtbl *)&CMapHelper::`vftable';
  this->__vftable = (CMapFrustum_vtbl *)&CMapFrustum::`vftable';
  this->m_Faces.m_Memory.m_pMemory = nullptr;
  this->m_Faces.m_Memory.m_nAllocationCount = 0;
  this->m_Faces.m_Memory.m_nGrowSize = 0;
  this->m_Faces.m_Size = 0;
  this->m_Faces.m_pElements = this->m_Faces.m_Memory.m_pMemory;
  V_strncpy(pDest: this->m_szFOVKeyName, pSrc: "_fov", maxLen: 80);
  V_strncpy(pDest: this->m_szNearPlaneKeyName, pSrc: "_NearPlane", maxLen: 80);
  V_strncpy(pDest: this->m_szFarPlaneKeyName, pSrc: "_FarPlane", maxLen: 80);
  V_strncpy(pDest: this->m_szColorKeyName, pSrc: "_light", maxLen: 80);
  this->m_flFOV = 90.0;
  this->m_flNearPlane = 10.0;
  this->m_flFarPlane = 200.0;
  this->m_flPitchScale = -1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1012DBB0
// Name: public: void CMapFrustum::BuildFrustumFaces(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMapFrustum::BuildFrustumFaces(CMapFrustum *this@<ecx>, int a2@<ebx>)
{
  float z; // edi
  int v3; // esi
  CMapFace *ecx2; // ecx
  float v5; // xmm0_4
  CUtlMemory<CCullTreeNode *,int> *v6; // esi
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  CMapFace *MapFace; // eax
  void *v13; // ecx
  int v14; // eax
  CCullTreeNode **m_pMemory; // edx
  int v16; // eax
  void **v17; // ecx
  CMapFace *v18; // eax
  void *v19; // ecx
  int v20; // eax
  CCullTreeNode **v21; // edx
  int v22; // eax
  void **v23; // ecx
  void *v24; // ecx
  CMapFace *v25; // eax
  CCullTreeNode **v26; // edi
  int m_nAllocationCount; // eax
  CCullTreeNode **v28; // ecx
  int v29; // eax
  CCullTreeNode **v30; // edi
  void *v31; // eax
  CMapFace *v32; // eax
  CCullTreeNode **v33; // edi
  int v34; // eax
  CCullTreeNode **v35; // ecx
  int v36; // eax
  CCullTreeNode **v37; // edi
  long double flAlpha; // [esp+0h] [ebp-94h]
  Vector v1; // [esp+8h] [ebp-8Ch] BYREF
  Vector v4; // [esp+14h] [ebp-80h] BYREF
  float v41; // [esp+20h] [ebp-74h] BYREF
  Vector vFarFace[4]; // [esp+24h] [ebp-70h] BYREF
  Vector vNearFace[4]; // [esp+54h] [ebp-40h] BYREF
  CMapFrustum *v44; // [esp+84h] [ebp-10h]
  CMapFace *v45; // [esp+88h] [ebp-Ch]
  void *v46; // [esp+8Ch] [ebp-8h]
  void *p; // [esp+90h] [ebp-4h]

  z = *(float *)&this;
  v3 = 0;
  LODWORD(vNearFace[3].z) = this;
  if ( this->m_Faces.m_Size > 0 )
  {
    do
    {
      ecx2 = *(CMapFace **)(*(_DWORD *)(LODWORD(z) + 216) + 4 * v3);
      v46 = ecx2;
      if ( ecx2 != nullptr )
      {
        CMapFace::~CMapFace(this: ecx2);
        operator delete(p: v46);
      }
      ++v3;
    }
    while ( v3 < *(_DWORD *)(LODWORD(z) + 228) );
  }
  v5 = 0.0099999998;
  v6 = (CUtlMemory<CCullTreeNode *,int> *)(LODWORD(z) + 216);
  *(_DWORD *)(LODWORD(z) + 228) = 0;
  v7 = *(float *)(LODWORD(z) + 236) * 0.5;
  if ( v7 >= 0.0099999998 )
  {
    v5 = 89.0;
    if ( v7 <= 89.0 )
      v5 = *(float *)(LODWORD(z) + 236) * 0.5;
  }
  __libm_sse2_tan(x: flAlpha);
  v8 = *(float *)(LODWORD(z) + 240);
  v9 = v5 * 0.017453292;
  LODWORD(v10) = COERCE_UNSIGNED_INT(v8 * v9) ^ _mask__NegFloat_;
  vNearFace[1].x = v8 * v9;
  vNearFace[2].x = v8 * v9;
  vNearFace[2].y = v8 * v9;
  vNearFace[3].y = v8 * v9;
  vFarFace[3].z = v8;
  vNearFace[0].z = v8;
  vNearFace[1].z = v8;
  vNearFace[2].z = v8;
  v11 = *(float *)(LODWORD(z) + 244);
  vNearFace[0].x = v10;
  vNearFace[0].y = v10;
  vNearFace[1].y = v10;
  vNearFace[3].x = v10;
  vFarFace[1].x = v11 * v9;
  vFarFace[2].x = v11 * v9;
  vFarFace[2].y = v11 * v9;
  vFarFace[3].y = v11 * v9;
  v41 = v11;
  LODWORD(vFarFace[0].x) = COERCE_UNSIGNED_INT(v11 * v9) ^ _mask__NegFloat_;
  vFarFace[0].y = vFarFace[0].x;
  vFarFace[0].z = v11;
  vFarFace[1].y = vFarFace[0].x;
  vFarFace[1].z = v11;
  vFarFace[2].z = v11;
  vFarFace[3].x = vFarFace[0].x;
  MapFace = CMapFrustum::CreateMapFace(
              this: (CMapFrustum *)LODWORD(z),
              a2,
              v1: (Vector *)&vFarFace[3].z,
              v2: (Vector *)&vNearFace[0].z,
              v3: (Vector *)&vNearFace[1].z,
              v4: (Vector *)&vNearFace[2].z,
              flAlpha: 180.0);
  v13 = *(void **)(LODWORD(z) + 228);
  v46 = MapFace;
  v14 = *(_DWORD *)(LODWORD(z) + 220);
  p = v13;
  if ( (int)v13 + 1 > v14 )
  {
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)(LODWORD(z) + 216),
      num: (int)v13 - v14 + 1);
    v13 = p;
  }
  ++*(_DWORD *)(LODWORD(z) + 228);
  m_pMemory = v6->m_pMemory;
  v16 = *(_DWORD *)(LODWORD(z) + 228) - (_DWORD)v13 - 1;
  *(_DWORD *)(LODWORD(z) + 232) = *(_DWORD *)(LODWORD(z) + 216);
  if ( v16 > 0 )
  {
    _V_memmove(dest: &m_pMemory[(_DWORD)v13 + 1], src: &m_pMemory[(_DWORD)v13], count: 4 * v16);
    v13 = p;
  }
  v17 = (void **)&v6->m_pMemory[(_DWORD)v13];
  if ( v17 != nullptr )
    *v17 = v46;
  v18 = CMapFrustum::CreateMapFace(
          this: (CMapFrustum *)LODWORD(z),
          a2,
          v1: (Vector *)&vFarFace[2].z,
          v2: (Vector *)&vFarFace[1].z,
          v3: (Vector *)&vFarFace[0].z,
          v4: (const Vector *)&v41,
          flAlpha: 180.0);
  v19 = *(void **)(LODWORD(z) + 228);
  v46 = v18;
  v20 = *(_DWORD *)(LODWORD(z) + 220);
  p = v19;
  if ( (int)v19 + 1 > v20 )
  {
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)(LODWORD(z) + 216),
      num: (int)v19 - v20 + 1);
    v19 = p;
  }
  ++*(_DWORD *)(LODWORD(z) + 228);
  v21 = v6->m_pMemory;
  v22 = *(_DWORD *)(LODWORD(z) + 228) - (_DWORD)v19 - 1;
  *(_DWORD *)(LODWORD(z) + 232) = *(_DWORD *)(LODWORD(z) + 216);
  if ( v22 > 0 )
  {
    _V_memmove(dest: &v21[(_DWORD)v19 + 1], src: &v21[(_DWORD)v19], count: 4 * v22);
    v19 = p;
  }
  v23 = (void **)&v6->m_pMemory[(_DWORD)v19];
  if ( v23 != nullptr )
    *v23 = v46;
  v24 = nullptr;
  v44 = (CMapFrustum *)1;
  p = nullptr;
  v46 = (void *)4;
  while ( 1 )
  {
    v25 = CMapFrustum::CreateMapFace(
            this: (CMapFrustum *)LODWORD(z),
            a2,
            v1: (const Vector *)((char *)&vFarFace[3].z + (_DWORD)v24),
            v2: (const Vector *)((char *)&v41 + (_DWORD)v24),
            v3: (const Vector *)&v41 + (int)v44 % 4,
            v4: (Vector *)&vFarFace[(int)v44 % 4 + 3].z,
            flAlpha: 180.0);
    v26 = v6[1].m_pMemory;
    v45 = v25;
    m_nAllocationCount = v6->m_nAllocationCount;
    if ( (int)v26 + 1 > m_nAllocationCount )
      CUtlMemory<CVisGroup *,int>::Grow(this: v6, num: (int)v26 - m_nAllocationCount + 1);
    v28 = v6->m_pMemory;
    v29 = (char *)++v6[1].m_pMemory - (char *)v26 - 1;
    v6[1].m_nAllocationCount = (int)v28;
    if ( v29 > 0 )
      _V_memmove(dest: &v28[(_DWORD)v26 + 1], src: &v28[(_DWORD)v26], count: 4 * v29);
    v30 = &v6->m_pMemory[(_DWORD)v26];
    if ( v30 != nullptr )
      *v30 = (CCullTreeNode *)v45;
    v44 = (CMapFrustum *)((char *)v44 + 1);
    p = (char *)p + 12;
    v46 = (char *)v46 - 1;
    if ( v46 == nullptr )
      break;
    v24 = p;
    z = vNearFace[3].z;
  }
  v31 = nullptr;
  memset(&v4, 0, sizeof(v4));
  memset(&v1, 0, sizeof(v1));
  p = &vFarFace[3].z;
  do
  {
    v46 = (char *)v31 + 1;
    v32 = CMapFrustum::CreateMapFace(
            this: (CMapFrustum *)LODWORD(vNearFace[3].z),
            a2,
            &v1,
            v2: (const Vector *)p,
            v3: (Vector *)&vFarFace[((int)v31 + 1) % 4 + 3].z,
            &v4,
            flAlpha: 40.0);
    v33 = v6[1].m_pMemory;
    v45 = v32;
    v34 = v6->m_nAllocationCount;
    if ( (int)v33 + 1 > v34 )
      CUtlMemory<CVisGroup *,int>::Grow(this: v6, num: (int)v33 - v34 + 1);
    ++v6[1].m_pMemory;
    v35 = v6->m_pMemory;
    v36 = (char *)v6[1].m_pMemory - (char *)v33 - 1;
    v6[1].m_nAllocationCount = (int)v6->m_pMemory;
    if ( v36 > 0 )
      _V_memmove(dest: &v35[(_DWORD)v33 + 1], src: &v35[(_DWORD)v33], count: 4 * v36);
    v37 = &v6->m_pMemory[(_DWORD)v33];
    if ( v37 != nullptr )
      *v37 = (CCullTreeNode *)v45;
    v31 = v46;
    p = (char *)p + 12;
  }
  while ( (int)v46 < 4 );
}

//------------------------------------------------------------------------------
// Address: 0x1012DFA0
// Name: public: virtual class CMapClass __near * CMapFrustum::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapFrustum *__thiscall CMapFrustum::Copy(CMapFrustum *this, BOOL bUpdateDependencies)
{
  CMapFrustum *v3; // eax
  CMapFrustum *v4; // esi

  v3 = (CMapFrustum *)operator new(nSize: 0x24Cu);
  if ( v3 != nullptr )
    v4 = CMapFrustum::CMapFrustum(this: v3);
  else
    v4 = nullptr;
  if ( v4 != nullptr )
    v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1012E020
// Name: public: virtual class CMapClass __near * CMapFrustum::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapFrustum *__userpurge CMapFrustum::CopyFrom@<eax>(
        CMapFrustum *this@<ecx>,
        int a2@<ebx>,
        CMapClass *pObject,
        bool bUpdateDependencies)
{
  CMapClass::CopyFrom(this, pFrom: (CVisGroup *)pObject, bUpdateDependencies);
  *(Vector *)&this->m_flFOV = pObject[1].m_Origin;
  this->m_Angles.x = *(float *)&pObject[1].m_CullBox.__vftable;
  this->m_Angles.y = pObject[1].m_CullBox.bmins.x;
  this->m_Angles.z = pObject[1].m_CullBox.bmins.y;
  this->m_flPitchScale = *(float *)&pObject[1].m_References.m_pHead;
  V_strncpy(pDest: this->m_szFOVKeyName, pSrc: (const char *)&pObject[1].m_CullBox.bmins.z, maxLen: 80);
  V_strncpy(pDest: this->m_szNearPlaneKeyName, pSrc: (const char *)&pObject[1].m_nDropTraceMarker, maxLen: 80);
  V_strncpy(pDest: this->m_szFarPlaneKeyName, pSrc: (const char *)&pObject[2].m_BoundingBox.bmins.y, maxLen: 80);
  V_strncpy(pDest: this->m_szColorKeyName, pSrc: (const char *)&pObject[1].m_Children.m_Memory + 8, maxLen: 80);
  CMapFrustum::BuildFrustumFaces(this, a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1012E0F0
// Name: public: virtual void CMapFrustum::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapFrustum::OnParentKeyChanged(
        CMapFrustum *this@<ecx>,
        int a2@<ebx>,
        const char *szKey,
        const char *szValue)
{
  const char *v4; // edi
  unsigned __int8 v6; // cl
  unsigned __int8 v7; // dl
  int nBlue; // [esp+8h] [ebp-4h] BYREF

  v4 = szKey;
  if ( _V_stricmp(s1: szKey, s2: "angles") != 0 )
  {
    if ( _V_stricmp(s1: v4, s2: this->m_szColorKeyName) != 0 )
    {
      if ( _V_stricmp(s1: v4, s2: this->m_szFOVKeyName) != 0 )
      {
        if ( _V_stricmp(s1: v4, s2: this->m_szNearPlaneKeyName) != 0 )
        {
          if ( _V_stricmp(s1: v4, s2: this->m_szFarPlaneKeyName) != 0 )
            return;
          this->m_flFarPlane = atof(nptr: szValue);
        }
        else
        {
          this->m_flNearPlane = atof(nptr: szValue);
        }
      }
      else
      {
        this->m_flFOV = atof(nptr: szValue);
      }
    }
    else
    {
      sscanf(string: szValue, format: "%d %d %d", &szValue, &szKey, &nBlue);
      v6 = (unsigned __int8)szKey;
      v7 = nBlue;
      this->r = (unsigned __int8)szValue;
      this->g = v6;
      this->b = v7;
    }
  }
  else
  {
    sscanf(string: szValue, format: "%f %f %f", &this->m_Angles, &this->m_Angles.y, &this->m_Angles.z);
  }
  CMapFrustum::BuildFrustumFaces(this, a2);
  this->PostUpdate(this, a2: Notify_Changed);
}

//------------------------------------------------------------------------------
// Address: 0x1012E210
// Name: public: virtual void CMapFrustum::PostloadWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapFrustum::PostloadWorld(CMapFrustum *this@<ecx>, int a2@<ebx>, CMapWorld *pWorld)
{
  CMapClass::PostloadWorld(this, pWorld);
  CMapFrustum::BuildFrustumFaces(this, a2);
  this->CalcBounds(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1012E240
// Name: class CMapClass __near * CMapFrustum_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapFrustum *__cdecl CMapFrustum_CreateObject()
{
  CMapFrustum *v0; // eax

  v0 = (CMapFrustum *)operator new(nSize: 0x24Cu);
  if ( v0 != nullptr )
    return CMapFrustum::CMapFrustum(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1012E2A0
// Name: public: static class CMapClass __near * CMapFrustum::Create(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapFrustum *__cdecl CMapFrustum::Create(CHelperInfo *pHelperInfo)
{
  CMapFrustum *v1; // eax
  CMapFrustum *v2; // edi
  char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  char **m_pMemory; // edx

  v1 = (CMapFrustum *)operator new(nSize: 0x24Cu);
  if ( v1 != nullptr )
    v2 = CMapFrustum::CMapFrustum(this: v1);
  else
    v2 = nullptr;
  if ( v2 != nullptr )
  {
    if ( pHelperInfo->m_Parameters.m_Size > 0 )
    {
      v3 = *pHelperInfo->m_Parameters.m_Memory.m_pMemory;
      if ( v3 != nullptr )
        V_strncpy(pDest: v2->m_szFOVKeyName, pSrc: v3, maxLen: 80);
    }
    if ( pHelperInfo->m_Parameters.m_Size > 1 )
    {
      v4 = *((const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 1);
      if ( v4 != nullptr )
        V_strncpy(pDest: v2->m_szNearPlaneKeyName, pSrc: v4, maxLen: 80);
    }
    if ( pHelperInfo->m_Parameters.m_Size > 2 )
    {
      v5 = *((const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 2);
      if ( v5 != nullptr )
        V_strncpy(pDest: v2->m_szFarPlaneKeyName, pSrc: v5, maxLen: 80);
    }
    if ( pHelperInfo->m_Parameters.m_Size > 3 )
    {
      v6 = *((const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 3);
      if ( v6 != nullptr )
        V_strncpy(pDest: v2->m_szColorKeyName, pSrc: v6, maxLen: 80);
    }
    if ( pHelperInfo->m_Parameters.m_Size > 4 )
    {
      m_pMemory = pHelperInfo->m_Parameters.m_Memory.m_pMemory;
      if ( m_pMemory[4] != nullptr )
      {
        v2->m_flPitchScale = V_atof(str: m_pMemory[4]);
        return v2;
      }
    }
    v2->m_flPitchScale = 1.0;
  }
  return v2;
}
