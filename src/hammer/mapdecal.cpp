// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapdecal.cpp
// Functions: 21
// ============================================================

#include "hammer\mapdecal.h"

//------------------------------------------------------------------------------
// Address: 0x10111E10
// Name: public: virtual char const __near * CMapDecal::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapDecal::GetType(CMapDecal *this)
{
  return CMapDecal::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10111E20
// Name: public: virtual int CMapDecal::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapDecal::IsMapClass(CMapDecal *this, const char *Type)
{
  return Type == CMapDecal::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10111E40
// Name: public: virtual void CMapDecal::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDecal::CalcBounds(CMapDecal *this, int bFullUpdate)
{
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm4_4
  int v6; // edi
  DecalFace_t *v7; // eax
  CMapFace *pFace; // eax
  Vector pfMins; // [esp+8h] [ebp-30h] BYREF
  Vector pfMaxs; // [esp+14h] [ebp-24h] BYREF
  Vector Mins; // [esp+20h] [ebp-18h] BYREF
  Vector Maxs; // [esp+2Ch] [ebp-Ch] BYREF

  CMapClass::CalcBounds(this, bFullUpdate);
  x = this->m_Origin.x;
  Mins.x = x - 2.0;
  y = this->m_Origin.y;
  Mins.y = y - 2.0;
  z = this->m_Origin.z;
  Mins.z = z - 2.0;
  Maxs.x = x + 2.0;
  Maxs.y = y + 2.0;
  Maxs.z = z + 2.0;
  BoundBox::UpdateBounds(this: &this->m_Render2DBox, mins: &Mins, maxs: &Maxs);
  BoundBox::ResetBounds(this: &this->m_CullBox);
  if ( this->m_Faces.m_Size <= 0 )
  {
    BoundBox::UpdateBounds(this: &this->m_CullBox, mins: &Mins, maxs: &Maxs);
  }
  else
  {
    v6 = 0;
    do
    {
      v7 = this->m_Faces.m_Memory.m_pMemory[v6];
      if ( v7 != nullptr )
      {
        pFace = v7->pFace;
        if ( pFace != nullptr )
        {
          CMapFace::GetFaceBounds(this: pFace, &pfMins, &pfMaxs);
          BoundBox::UpdateBounds(this: &this->m_CullBox, mins: &pfMins, maxs: &pfMaxs);
        }
      }
      ++v6;
    }
    while ( v6 < this->m_Faces.m_Size );
    if ( (float)(this->m_CullBox.bmaxs.x - this->m_CullBox.bmins.x) == 0.0 )
    {
      this->m_CullBox.bmins.x = this->m_CullBox.bmins.x - 0.5;
      this->m_CullBox.bmaxs.x = this->m_CullBox.bmaxs.x + 0.5;
    }
    if ( (float)(this->m_CullBox.bmaxs.y - this->m_CullBox.bmins.y) == 0.0 )
    {
      this->m_CullBox.bmins.y = this->m_CullBox.bmins.y - 0.5;
      this->m_CullBox.bmaxs.y = this->m_CullBox.bmaxs.y + 0.5;
    }
    if ( (float)(this->m_CullBox.bmaxs.z - this->m_CullBox.bmins.z) == 0.0 )
    {
      this->m_CullBox.bmins.z = this->m_CullBox.bmins.z - 0.5;
      this->m_CullBox.bmaxs.z = this->m_CullBox.bmaxs.z + 0.5;
    }
  }
  this->m_BoundingBox.bmins.x = this->m_CullBox.bmins.x;
  this->m_BoundingBox.bmins.y = this->m_CullBox.bmins.y;
  this->m_BoundingBox.bmins.z = this->m_CullBox.bmins.z;
  this->m_BoundingBox.bmaxs.x = this->m_CullBox.bmaxs.x;
  this->m_BoundingBox.bmaxs.y = this->m_CullBox.bmaxs.y;
  this->m_BoundingBox.bmaxs.z = this->m_CullBox.bmaxs.z;
}

//------------------------------------------------------------------------------
// Address: 0x10112000
// Name: public: virtual void CMapDecal::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDecal::Render3D(CMapDecal *this, CRender3D *pRender)
{
  int v3; // esi
  SelectionState_t v4; // eax
  int i; // esi
  DecalFace_t *v7; // eax
  CMapFace *pFace; // eax
  EditorRenderMode_t eDefaultRenderMode; // [esp+Ch] [ebp-8h]
  int nPasses; // [esp+10h] [ebp-4h]
  int nPass; // [esp+1Ch] [ebp+8h]

  v3 = 1;
  nPasses = 1;
  v4 = this->GetSelectionState(this);
  eDefaultRenderMode = pRender->m_eDefaultRenderMode;
  if ( v4 != SELECT_NONE && pRender->m_eDefaultRenderMode != RENDER_MODE_WIREFRAME )
    nPasses = 2;
  if ( v4 == SELECT_MODIFY )
    v3 = 2;
  CRender3D::RenderEnable(this: pRender, eRenderState: RENDER_POLYGON_OFFSET_FILL, bEnable: true);
  for ( nPass = v3; nPass <= nPasses; ++nPass )
  {
    if ( nPass == 1 )
    {
      if ( eDefaultRenderMode == RENDER_MODE_LIGHTMAP_GRID )
        CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_TEXTURED);
      else
        CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_CURRENT);
    }
    else
    {
      CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
    }
    for ( i = 0; i < this->m_Faces.m_Size; ++i )
    {
      v7 = this->m_Faces.m_Memory.m_pMemory[i];
      if ( v7 != nullptr )
      {
        pFace = v7->pFace;
        if ( pFace != nullptr )
          pFace->Render3D(this: pFace, a2: pRender);
      }
    }
    CRender::PopRenderMode(this: pRender);
  }
  CRender3D::RenderEnable(this: pRender, eRenderState: RENDER_POLYGON_OFFSET_FILL, bEnable: false);
}

//------------------------------------------------------------------------------
// Address: 0x101120D0
// Name: protected: int CMapDecal::CanDecalSolid(class CMapSolid __near *,class CMapFace __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapDecal::CanDecalSolid(CMapDecal *this, CMapSolid *pSolid, CMapFace **ppFaces)
{
  int result; // eax
  int v4; // edi
  BlockArray<CMapFace,6,86> *p_Faces; // esi
  int v6; // ebx
  unsigned int v7; // esi
  CMapFace *v8; // esi
  double NormalDistance; // st7
  int nFaces; // [esp+8h] [ebp-10h]
  float fDistance; // [esp+Ch] [ebp-Ch]
  Vector *fPoint; // [esp+10h] [ebp-8h]
  int nDecalFaces; // [esp+14h] [ebp-4h]
  BlockArray<CMapFace,6,86> *pSolida; // [esp+20h] [ebp+8h]

  result = 0;
  v4 = 0;
  nDecalFaces = 0;
  nFaces = pSolid->Faces.nCount;
  if ( nFaces > 0 )
  {
    p_Faces = &pSolid->Faces;
    pSolida = &pSolid->Faces;
    fPoint = &this->m_Origin;
    while ( 1 )
    {
      if ( v4 >= p_Faces->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v4, p_Faces->nCount);
        v6 = v4 + 1;
        if ( v4 + 1 != p_Faces->nCount )
        {
          v7 = v6 / 6;
          if ( 6 * (v6 / 6) < v6 )
            ++v7;
          if ( v7 != pSolida->nBlocks )
          {
            if ( v7 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: pSolida, nNewBlocks: v7);
          }
          pSolida->nCount = v6;
        }
      }
      v8 = &pSolida->Blocks[v4 / 6u][v4 % 6u];
      NormalDistance = CMapFace::GetNormalDistance(this: v8, fPoint);
      if ( NormalDistance <= 16.0 )
      {
        fDistance = NormalDistance;
        if ( fDistance >= -0.0001 )
        {
          if ( ppFaces != nullptr )
            ppFaces[nDecalFaces] = v8;
          ++nDecalFaces;
        }
      }
      if ( ++v4 >= nFaces )
        break;
      p_Faces = pSolida;
    }
    return nDecalFaces;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10112200
// Name: protected: int CMapDecal::DecalSolid(class CMapSolid __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapDecal::DecalSolid(CMapDecal *this, CMapSolid *pSolid)
{
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  void *v3; // esp
  int v5; // esi
  int ClippedPoly; // eax
  int v8; // edi
  int v9; // esi
  unsigned int v10; // edx
  float *p_y; // ecx
  float *v12; // eax
  double v13; // st7
  float *v14; // ecx
  float *v15; // eax
  int v16; // edx
  double v17; // st7
  CMapFace **v18; // esi
  CMapFace *v19; // eax
  CMapFace *v20; // eax
  int v21; // ebx
  float *v22; // eax
  CUtlMemory<CCullTreeNode *,int> *v23; // edi
  CCullTreeNode **m_pMemory; // ebx
  int m_nAllocationCount; // eax
  CCullTreeNode **v26; // ecx
  int v27; // eax
  CMapFace ***v28; // eax
  CMapFace *pFace[512]; // [esp+14h] [ebp-1018h] BYREF
  Vector v30[64]; // [esp+814h] [ebp-818h] BYREF
  float v31[320]; // [esp+B14h] [ebp-518h] BYREF
  CUtlMemory<CCullTreeNode *,int> *v32; // [esp+1014h] [ebp-18h]
  int CanDecalSolid; // [esp+1018h] [ebp-14h]
  int v34; // [esp+101Ch] [ebp-10h]
  _EXCEPTION_REGISTRATION_RECORD *v35; // [esp+1020h] [ebp-Ch]
  void *v36; // [esp+1024h] [ebp-8h]
  int v37; // [esp+1028h] [ebp-4h]
  CMapSolid *i; // [esp+1034h] [ebp+8h]

  v37 = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v36 = &_ehhandler__CopyFrom_CEditGameClass__QAEPAV1_PAV1__Z;
  v35 = ExceptionList;
  v3 = alloca(4108);
  v5 = 0;
  v32 = (CUtlMemory<CCullTreeNode *,int> *)this;
  if ( this->m_pTexture == nullptr )
    return 0;
  v34 = 0;
  CanDecalSolid = CMapDecal::CanDecalSolid(this, pSolid, ppFaces: pFace);
  if ( CanDecalSolid > 0 )
  {
    while ( 1 )
    {
      ClippedPoly = CreateClippedPoly(
                      pFace: pFace[v5],
                      pDecalTex: this->m_pTexture,
                      org: &this->m_Origin,
                      pOutPoints: (float (*)[5])v31,
                      nOutSize: 64);
      v8 = ClippedPoly;
      if ( ClippedPoly != 0 )
        break;
      if ( ++v5 >= CanDecalSolid )
        return v34;
    }
    v9 = 0;
    v34 = 1;
    if ( ClippedPoly >= 4 )
    {
      v10 = ((unsigned int)(ClippedPoly - 4) >> 2) + 1;
      p_y = &v30[0].y;
      v12 = &v31[1];
      v9 = 4 * v10;
      do
      {
        v13 = *(v12 - 1);
        v12 += 20;
        *(p_y - 1) = v13;
        p_y += 12;
        --v10;
        *(p_y - 12) = *(v12 - 20);
        *(p_y - 11) = *(v12 - 19);
        *(p_y - 10) = *(v12 - 16);
        *(p_y - 9) = *(v12 - 15);
        *(p_y - 8) = *(v12 - 14);
        *(p_y - 7) = *(v12 - 11);
        *(p_y - 6) = *(v12 - 10);
        *(p_y - 5) = *(v12 - 9);
        *(p_y - 4) = *(v12 - 6);
        *(p_y - 3) = *(v12 - 5);
        *(p_y - 2) = *(v12 - 4);
      }
      while ( v10 != 0 );
    }
    if ( v9 < v8 )
    {
      v14 = &v30[v9].y;
      v15 = &v31[5 * v9 + 1];
      v16 = v8 - v9;
      do
      {
        v17 = *(v15 - 1);
        v15 += 5;
        *(v14 - 1) = v17;
        v14 += 3;
        --v16;
        *(v14 - 3) = *(v15 - 5);
        *(v14 - 2) = *(v15 - 4);
      }
      while ( v16 != 0 );
    }
    v18 = (CMapFace **)operator new(nSize: 8u);
    v19 = (CMapFace *)operator new(nSize: 0x1BCu);
    CanDecalSolid = (int)v19;
    v37 = 0;
    if ( v19 != nullptr )
      v20 = CMapFace::CMapFace(this: v19);
    else
      v20 = nullptr;
    v37 = -1;
    *v18 = v20;
    CMapFace::CreateFace(this: v20, pPoints: v30, _nPoints: v8, bIsCordonFace: false);
    (*v18)->SetRenderColor_2(this: *v18, a2: 255u, a3: 255u, a4: 255u);
    (*v18)->SetParent(this: *v18, a2: this);
    v18[1] = (CMapFace *)pSolid;
    CMapFace::SetTexture(this: *v18, pTexture: this->m_pTexture, bRescaleTextureCoordinates: false);
    CMapFace::CalcTextureCoords(this: *v18);
    v21 = 0;
    if ( v8 > 0 )
    {
      v22 = &v31[3];
      for ( i = (CMapSolid *)&v31[3]; ; v22 = (float *)i )
      {
        CMapFace::SetTextureCoords(this: *v18, nPoint: v21, u: *v22, v: v22[1]);
        i = (CMapSolid *)((char *)i + 20);
        if ( ++v21 >= v8 )
          break;
      }
    }
    v23 = v32;
    m_pMemory = v32[21].m_pMemory;
    m_nAllocationCount = v32[20].m_nAllocationCount;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CVisGroup *,int>::Grow(this: v32 + 20, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++v23[21].m_pMemory;
    v26 = v23[20].m_pMemory;
    v27 = (char *)v23[21].m_pMemory - (char *)m_pMemory - 1;
    v23[21].m_nAllocationCount = (int)v26;
    if ( v27 > 0 )
      _V_memmove(dest: &v26[(_DWORD)m_pMemory + 1], src: &v26[(_DWORD)m_pMemory], count: 4 * v27);
    v28 = (CMapFace ***)&v23[20].m_pMemory[(_DWORD)m_pMemory];
    if ( v28 != nullptr )
      *v28 = v18;
  }
  return v34;
}

//------------------------------------------------------------------------------
// Address: 0x101124B0
// Name: public: virtual void CMapDecal::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDecal::OnParentKeyChanged(CMapDecal *this, const char *szKey, const char *szValue)
{
  IEditorTexture *ActiveTexture; // eax
  int v5; // edi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v7; // ecx
  CMapClass *v8; // edx
  CUtlReference<CMapClass> *m_pHead; // [esp+4h] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v10; // [esp+8h] [ebp-14h]
  CMapClass *v11; // [esp+Ch] [ebp-10h]
  int v12; // [esp+18h] [ebp-4h]

  if ( _V_stricmp(s1: szKey, s2: "texture") == 0 )
  {
    ActiveTexture = CTextureSystem::FindActiveTexture(
                      this: &g_Textures,
                      pszInputName: szValue,
                      piIndex: nullptr,
                      bDummy: 1);
    if ( ActiveTexture != nullptr )
    {
      v5 = 0;
      for ( this->m_pTexture = ActiveTexture; v5 < this->m_Solids.m_Size; ++v5 )
      {
        m_pObject = this->m_Solids.m_Memory.m_pMemory[v5 >> ((unsigned __int64)*((int *)&this->m_Solids.m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&this->m_Solids.m_Memory + 2)) >> 5)].m_pObject;
        if ( m_pObject != nullptr )
        {
          v11 = this->m_Solids.m_Memory.m_pMemory[v5 >> ((unsigned __int64)*((int *)&this->m_Solids.m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&this->m_Solids.m_Memory + 2)) >> 5)].m_pObject;
          m_pHead = m_pObject->m_References.m_pHead;
          v7 = m_pObject->m_References.m_pHead;
          if ( v7 != nullptr )
            v7->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
          v10 = nullptr;
          m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
        }
        v8 = v11;
        v12 = -1;
        if ( v11 != nullptr )
        {
          if ( v10 != nullptr )
          {
            v10->m_pNext = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = v10;
          }
          else if ( (CUtlReference<CMapClass> **)v11->m_References.m_pHead == &m_pHead )
          {
            v11->m_References.m_pHead = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = nullptr;
          }
          v10 = nullptr;
          m_pHead = nullptr;
          v11 = nullptr;
        }
        if ( v8 != nullptr )
          this->OnNotifyDependent(this, a2: v8, a3: Notify_Changed);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101125F0
// Name: public: virtual void CMapDecal::OnNotifyDependent(class CMapClass __near *,enum Notify_Dependent_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDecal::OnNotifyDependent(CMapDecal *this, CMapSolid *pObject, Notify_Dependent_t eNotifyType)
{
  CMapSolid *v4; // edi
  int v5; // ebx
  DecalFace_t *v6; // edi
  CMapFace *pFace; // ecx
  CUtlReference<CMapClass> *m_pHead; // ecx
  int v9; // eax
  CUtlReference<CMapClass> src; // [esp+Ch] [ebp-1Ch] BYREF
  void *p; // [esp+18h] [ebp-10h]
  int v12; // [esp+24h] [ebp-4h]
  CMapSolid *pSolid; // [esp+30h] [ebp+8h]

  v4 = (CMapSolid *)__RTDynamicCast(
                      inptr: pObject,
                      VfDelta: 0,
                      SrcType: &CMapClass `RTTI Type Descriptor',
                      TargetType: &CMapSolid `RTTI Type Descriptor',
                      isReference: 0);
  pSolid = v4;
  if ( v4 != nullptr )
  {
    v5 = this->m_Faces.m_Size - 1;
    if ( v5 >= 0 )
    {
      do
      {
        v6 = this->m_Faces.m_Memory.m_pMemory[v5];
        if ( v6 != nullptr && v6->pSolid == pSolid )
        {
          pFace = v6->pFace;
          p = pFace;
          if ( pFace != nullptr )
          {
            CMapFace::~CMapFace(this: pFace);
            operator delete(p);
          }
          operator delete(p: v6);
          if ( this->m_Faces.m_Size - v5 - 1 > 0 )
            _V_memmove(
              dest: &this->m_Faces.m_Memory.m_pMemory[v5],
              src: &this->m_Faces.m_Memory.m_pMemory[v5 + 1],
              count: 4 * (this->m_Faces.m_Size - v5 - 1));
          --this->m_Faces.m_Size;
        }
        --v5;
      }
      while ( v5 >= 0 );
      v4 = pSolid;
    }
    if ( eNotifyType != Notify_Removed && CMapDecal::DecalSolid(this, pSolid: v4) != 0 )
    {
      this->CalcBounds(this, a2: 0);
      return;
    }
    m_pHead = v4->m_References.m_pHead;
    src.m_pPrev = nullptr;
    src.m_pObject = v4;
    src.m_pNext = m_pHead;
    if ( m_pHead != nullptr )
      m_pHead->m_pPrev = &src;
    src.m_pPrev = nullptr;
    v4->m_References.m_pHead = &src;
    v12 = 0;
    v9 = CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(
           this: &this->m_Solids,
           &src);
    v12 = -1;
    if ( src.m_pObject != nullptr )
    {
      if ( src.m_pPrev != nullptr )
      {
        src.m_pPrev->m_pNext = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = src.m_pPrev;
      }
      else if ( src.m_pObject->m_References.m_pHead == &src )
      {
        src.m_pObject->m_References.m_pHead = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = nullptr;
      }
      memset(&src, 0, sizeof(src));
    }
    if ( v9 != -1 )
    {
      CUtlReferenceVector<CMapClass>::FastRemove(this: &this->m_Solids, elem: v9);
      CMapClass::UpdateDependency(this, pOldAttached: v4, pNewAttached: nullptr);
    }
  }
  this->CalcBounds(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101127B0
// Name: protected: void CMapDecal::AddSolid(class CMapSolid __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDecal::AddSolid(CMapDecal *this, CMapSolid *pSolid)
{
  CUtlReference<CMapClass> *m_pHead; // eax
  CUtlReferenceVector<CMapClass> *p_m_Solids; // edi
  bool v4; // dl
  CUtlReference<CMapClass> *v5; // eax
  CUtlReference<CMapClass> src; // [esp+Ch] [ebp-1Ch] BYREF
  CMapClass *v7; // [esp+18h] [ebp-10h]
  int v8; // [esp+24h] [ebp-4h]

  v7 = this;
  src.m_pPrev = nullptr;
  src.m_pNext = nullptr;
  src.m_pObject = pSolid;
  if ( pSolid != nullptr )
  {
    m_pHead = pSolid->m_References.m_pHead;
    src.m_pNext = m_pHead;
    if ( m_pHead != nullptr )
      m_pHead->m_pPrev = &src;
    src.m_pPrev = nullptr;
    pSolid->m_References.m_pHead = &src;
  }
  v8 = 0;
  p_m_Solids = &this->m_Solids;
  v4 = CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(
         this: &this->m_Solids,
         &src) == -1;
  v8 = -1;
  if ( src.m_pObject != nullptr )
  {
    if ( src.m_pPrev != nullptr )
    {
      src.m_pPrev->m_pNext = src.m_pNext;
      if ( src.m_pNext != nullptr )
        src.m_pNext->m_pPrev = src.m_pPrev;
    }
    else if ( src.m_pObject->m_References.m_pHead == &src )
    {
      src.m_pObject->m_References.m_pHead = src.m_pNext;
      if ( src.m_pNext != nullptr )
        src.m_pNext->m_pPrev = nullptr;
    }
    memset(&src, 0, sizeof(src));
  }
  if ( v4 )
  {
    CMapClass::UpdateDependency(this: v7, pOldAttached: nullptr, pNewAttached: pSolid);
    src.m_pPrev = nullptr;
    src.m_pNext = nullptr;
    src.m_pObject = pSolid;
    if ( pSolid != nullptr )
    {
      v5 = pSolid->m_References.m_pHead;
      src.m_pNext = v5;
      if ( v5 != nullptr )
        v5->m_pPrev = &src;
      src.m_pPrev = nullptr;
      pSolid->m_References.m_pHead = &src;
    }
    v8 = 1;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
      this: p_m_Solids,
      elem: p_m_Solids->m_Size,
      &src);
    v8 = -1;
    if ( src.m_pObject != nullptr )
    {
      if ( src.m_pPrev != nullptr )
      {
        src.m_pPrev->m_pNext = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = src.m_pPrev;
      }
      else if ( src.m_pObject->m_References.m_pHead == &src )
      {
        src.m_pObject->m_References.m_pHead = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112910
// Name: public: virtual class CMapClass __near * CMapDecal::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapDecal *__thiscall CMapDecal::CopyFrom(CMapDecal *this, CMapClass *pObject, bool bUpdateDependencies)
{
  CMapClass *v3; // edi
  CUtlMemory<CCullTreeNode *,int> *p_m_Faces; // esi
  CMapFace **v6; // ebx
  CMapFace *v7; // eax
  CMapFace *v8; // eax
  int v9; // edi
  CCullTreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CCullTreeNode **v12; // ecx
  int v13; // eax
  CCullTreeNode **v14; // edi
  int pos; // [esp+2Ch] [ebp+Ch]

  v3 = pObject;
  CMapClass::CopyFrom(this, pFrom: (CVisGroup *)pObject, bUpdateDependencies);
  this->m_pTexture = (IEditorTexture *)pObject[1].__vftable;
  CUtlReferenceVector<CMapClass>::RemoveAll(this: &this->m_Solids);
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::AddVectorToTail(
    this: &this->m_Solids,
    src: (const CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *)&pObject[1].m_nObjectID);
  p_m_Faces = (CUtlMemory<CCullTreeNode *,int> *)&this->m_Faces;
  this->m_Faces.m_Size = 0;
  pos = 0;
  if ( (int)pObject[1].dwKept <= 0 )
    return this;
  do
  {
    v6 = (CMapFace **)operator new(nSize: 8u);
    if ( v6 != nullptr )
    {
      v7 = (CMapFace *)operator new(nSize: 0x1BCu);
      v8 = v7 != nullptr ? CMapFace::CMapFace(this: v7) : nullptr;
      *v6 = v8;
      if ( v8 != nullptr )
      {
        v9 = *(_DWORD *)(LODWORD(v3[1].m_Origin.y) + 4 * pos);
        CMapFace::CopyFrom(this: v8, pObject: *(const CMapFace **)v9, dwFlags: 2u, bUpdateDependencies: true);
        (*v6)->SetParent(this: *v6, a2: this);
        v6[1] = *(CMapFace **)(v9 + 4);
        m_pMemory = p_m_Faces[1].m_pMemory;
        m_nAllocationCount = p_m_Faces->m_nAllocationCount;
        if ( (int)m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<CVisGroup *,int>::Grow(this: p_m_Faces, num: (int)m_pMemory - m_nAllocationCount + 1);
        ++p_m_Faces[1].m_pMemory;
        v12 = p_m_Faces->m_pMemory;
        v13 = (char *)p_m_Faces[1].m_pMemory - (char *)m_pMemory - 1;
        p_m_Faces[1].m_nAllocationCount = (int)p_m_Faces->m_pMemory;
        if ( v13 > 0 )
          _V_memmove(dest: &v12[(_DWORD)m_pMemory + 1], src: &v12[(_DWORD)m_pMemory], count: 4 * v13);
        v14 = &p_m_Faces->m_pMemory[(_DWORD)m_pMemory];
        if ( v14 != nullptr )
          *v14 = (CCullTreeNode *)v6;
        v3 = pObject;
      }
    }
    ++pos;
  }
  while ( pos < (signed int)v3[1].dwKept );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10112A90
// Name: public: void CMapDecal::DecalAllSolids(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDecal::DecalAllSolids(CMapDecal *this, CMapWorld *pWorld)
{
  CMapClass *i; // eax
  CMapSolid *v4; // eax
  CMapSolid *v5; // esi
  EnumChildrenPos_t pos; // [esp+8h] [ebp-84h] BYREF

  if ( pWorld != nullptr )
  {
    for ( i = CMapClass::GetFirstDescendent(this: pWorld, (CMapClass *)&pos);
          i != nullptr;
          i = CMapClass::GetNextDescendent(this: pWorld, (CMapClass *)&pos) )
    {
      v4 = (CMapSolid *)__RTDynamicCast(
                          inptr: i,
                          VfDelta: 0,
                          SrcType: &CMapClass `RTTI Type Descriptor',
                          TargetType: &CMapSolid `RTTI Type Descriptor',
                          isReference: 0);
      v5 = v4;
      if ( v4 != nullptr && CMapDecal::DecalSolid(this, pSolid: v4) != 0 )
        CMapDecal::AddSolid(this, pSolid: v5);
    }
    this->PostUpdate(this, a2: Notify_Changed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112B20
// Name: public: virtual void CMapDecal::PostloadWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDecal::PostloadWorld(CMapDecal *this, CMapWorld *pWorld)
{
  CMapClass::PostloadWorld(this, pWorld);
  CMapDecal::DecalAllSolids(this, pWorld);
}

//------------------------------------------------------------------------------
// Address: 0x10112B40
// Name: protected: void CMapDecal::RebuildDecalFaces(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDecal::RebuildDecalFaces(CMapDecal *this)
{
  int i; // ebx
  DecalFace_t *v3; // edi
  CMapWorld *WorldObject; // eax
  CMapFace *p; // [esp+8h] [ebp-4h]

  for ( i = 0; i < this->m_Faces.m_Size; ++i )
  {
    v3 = this->m_Faces.m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      p = v3->pFace;
      if ( v3->pFace != nullptr )
      {
        CMapFace::~CMapFace(this: v3->pFace);
        operator delete(p);
      }
      operator delete(p: v3);
    }
  }
  this->m_Faces.m_Size = 0;
  WorldObject = CMapClass::GetWorldObject(pStart: this);
  CMapDecal::DecalAllSolids(this, pWorld: WorldObject);
}

//------------------------------------------------------------------------------
// Address: 0x10112BB0
// Name: public: virtual void CMapDecal::OnPaste(class CMapClass __near *,class CMapWorld __near *,class CMapWorld __near *,class CUtlReferenceVector<class CMapClass> const __near &,class CUtlReferenceVector<class CMapClass> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDecal::OnPaste(
        CMapDecal *this,
        CMapDecal *pCopy,
        CMapWorld *pSourceWorld,
        CMapWorld *pDestWorld,
        const CUtlReferenceVector<CMapClass> *OriginalList,
        CUtlReferenceVector<CMapClass> *NewList)
{
  CMapClass::OnPaste(this, pCopy, pSourceWorld, pDestWorld, OriginalList, NewList);
  CMapDecal::DecalAllSolids(this: pCopy, pWorld: pDestWorld);
}

//------------------------------------------------------------------------------
// Address: 0x10112BE0
// Name: public: virtual void CMapDecal::OnRemoveFromWorld(class CMapWorld __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDecal::OnRemoveFromWorld(CMapDecal *this, CMapWorld *pWorld, bool bNotifyChildren)
{
  int i; // edi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v6; // ecx
  CMapClass *v7; // edx
  CUtlReference<CMapClass> *m_pHead; // [esp+Ch] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v9; // [esp+10h] [ebp-14h]
  CMapClass *pOldAttached; // [esp+14h] [ebp-10h]
  int v11; // [esp+20h] [ebp-4h]

  CMapClass::OnRemoveFromWorld(this, pWorld, bNotifyChildren);
  for ( i = 0; i < this->m_Solids.m_Size; ++i )
  {
    m_pObject = this->m_Solids.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Solids.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Solids.m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
    {
      pOldAttached = this->m_Solids.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Solids.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Solids.m_Memory + 2)) >> 5)].m_pObject;
      m_pHead = m_pObject->m_References.m_pHead;
      v6 = m_pObject->m_References.m_pHead;
      if ( v6 != nullptr )
        v6->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
      v9 = nullptr;
      m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
    }
    v7 = pOldAttached;
    v11 = -1;
    if ( pOldAttached != nullptr )
    {
      if ( v9 != nullptr )
      {
        v9->m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = v9;
      }
      else if ( (CUtlReference<CMapClass> **)pOldAttached->m_References.m_pHead == &m_pHead )
      {
        pOldAttached->m_References.m_pHead = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = nullptr;
      }
      v9 = nullptr;
      m_pHead = nullptr;
      pOldAttached = nullptr;
    }
    CMapClass::UpdateDependency(this, pOldAttached: v7, pNewAttached: nullptr);
  }
  CUtlReferenceVector<CMapClass>::RemoveAll(this: &this->m_Solids);
}

//------------------------------------------------------------------------------
// Address: 0x10112CF0
// Name: protected: virtual void CMapDecal::DoTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDecal::DoTransform(CMapDecal *this, const VMatrix *matrix)
{
  CMapClass::DoTransform(this, matrix);
  CMapDecal::RebuildDecalFaces(this);
}

//------------------------------------------------------------------------------
// Address: 0x10112D10
// Name: public: virtual CMapDecal::~CMapDecal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDecal::~CMapDecal(CMapDecal *this)
{
  int i; // esi
  DecalFace_t *v2; // edi
  CMapFace *pFace; // ebx
  CUtlVector<DecalFace_t *,CUtlMemory<DecalFace_t *,int> > *p_m_Faces; // esi
  bool v5; // sf
  CUtlReferenceVector<CMapClass> *p_m_Solids; // esi
  int j; // edi
  int k; // edi
  CUtlReference<CMapClass> **m_pMemory; // [esp-4h] [ebp-24h]
  CUtlReference<CMapClass> **v10; // [esp-4h] [ebp-24h]
  CMapDecal *v11; // [esp+10h] [ebp-10h]

  v11 = this;
  this->__vftable = (CMapDecal_vtbl *)&CMapDecal::`vftable';
  for ( i = 0; i < v11->m_Faces.m_Size; ++i )
  {
    v2 = this->m_Faces.m_Memory.m_pMemory[i];
    pFace = v2->pFace;
    if ( v2->pFace != nullptr )
    {
      CMapFace::~CMapFace(this: v2->pFace);
      operator delete(p: pFace);
    }
    operator delete(p: v2);
    this = v11;
  }
  p_m_Faces = &this->m_Faces;
  v5 = this->m_Faces.m_Memory.m_nGrowSize < 0;
  this->m_Faces.m_Size = 0;
  if ( !v5 )
  {
    if ( p_m_Faces->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Faces->m_Memory.m_pMemory);
      this = v11;
      p_m_Faces->m_Memory.m_pMemory = nullptr;
    }
    p_m_Faces->m_Memory.m_nAllocationCount = 0;
  }
  p_m_Faces->m_pElements = p_m_Faces->m_Memory.m_pMemory;
  if ( p_m_Faces->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Faces->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Faces->m_Memory.m_pMemory);
      this = v11;
      p_m_Faces->m_Memory.m_pMemory = nullptr;
    }
    p_m_Faces->m_Memory.m_nAllocationCount = 0;
  }
  p_m_Solids = &this->m_Solids;
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this: &this->m_Solids);
  if ( p_m_Solids->m_Memory.m_pMemory != nullptr )
  {
    for ( j = 0; j < p_m_Solids->m_Memory.m_nBlocks; ++j )
      free(pMem: p_m_Solids->m_Memory.m_pMemory[j]);
    m_pMemory = p_m_Solids->m_Memory.m_pMemory;
    p_m_Solids->m_Memory.m_nBlocks = 0;
    free(pMem: m_pMemory);
    p_m_Solids->m_Memory.m_pMemory = nullptr;
  }
  p_m_Solids->m_pElements = nullptr;
  if ( p_m_Solids->m_Memory.m_pMemory != nullptr )
  {
    for ( k = 0; k < p_m_Solids->m_Memory.m_nBlocks; ++k )
      free(pMem: p_m_Solids->m_Memory.m_pMemory[k]);
    v10 = p_m_Solids->m_Memory.m_pMemory;
    p_m_Solids->m_Memory.m_nBlocks = 0;
    free(pMem: v10);
    p_m_Solids->m_Memory.m_pMemory = nullptr;
  }
  CMapClass::~CMapClass(this: v11);
}

//------------------------------------------------------------------------------
// Address: 0x10112EA0
// Name: public: virtual char const __near * CMapDecal::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapDecal::GetDescription(CMapDecal *this)
{
  return "Decal helper";
}

//------------------------------------------------------------------------------
// Address: 0x10112EB0
// Name: public: CMapDecal::CMapDecal(void)
// Source: json
//------------------------------------------------------------------------------
CMapDecal *__thiscall CMapDecal::CMapDecal(CMapDecal *this)
{
  DecalFace_t **m_pMemory; // ecx

  CMapClass::CMapClass(this);
  this->__vftable = (CMapDecal_vtbl *)&CMapHelper::`vftable';
  this->__vftable = (CMapDecal_vtbl *)&CMapDecal::`vftable';
  this->m_Solids.m_Memory.m_pMemory = nullptr;
  this->m_Solids.m_Memory.m_nBlocks = 0;
  *((_DWORD *)&this->m_Solids.m_Memory + 2) = 0;
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &this->m_Solids.m_Memory, nGrowSize: 0, nInitSize: 0);
  this->m_Solids.m_Size = 0;
  this->m_Solids.m_pElements = nullptr;
  this->m_Faces.m_Memory.m_pMemory = nullptr;
  this->m_Faces.m_Memory.m_nAllocationCount = 0;
  this->m_Faces.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_Faces.m_Memory.m_pMemory;
  this->m_Faces.m_Size = 0;
  this->m_Faces.m_pElements = m_pMemory;
  this->m_pTexture = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10112F90
// Name: public: virtual class CMapClass __near * CMapDecal::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapDecal *__thiscall CMapDecal::Copy(CMapDecal *this, BOOL bUpdateDependencies)
{
  CMapDecal *v3; // eax
  CMapDecal *v4; // esi

  v3 = (CMapDecal *)operator new(nSize: 0x104u);
  if ( v3 != nullptr )
    v4 = CMapDecal::CMapDecal(this: v3);
  else
    v4 = nullptr;
  if ( v4 != nullptr )
    v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10113010
// Name: class CMapClass __near * CMapDecal_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapDecal *__cdecl CMapDecal_CreateObject()
{
  CMapDecal *v0; // eax

  v0 = (CMapDecal *)operator new(nSize: 0x104u);
  if ( v0 != nullptr )
    return CMapDecal::CMapDecal(this: v0);
  else
    return nullptr;
}
