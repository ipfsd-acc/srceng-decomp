// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/toolpickface.cpp
// Functions: 15
// ============================================================

#include "hammer\toolpickface.h"

//------------------------------------------------------------------------------
// Address: 0x101659D0
// Name: public: virtual bool CToolPickFace::OnMouseMove3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolPickFace::OnMouseMove3D(
        CToolPickFace *this,
        CMapView3D *pView,
        CMapView3D *nFlags,
        const Vector2D *vPoint)
{
  HCURSOR CursorA; // eax
  AFX_MODULE_STATE *ModuleState; // eax

  CursorA = dword_107B3808;
  if ( dword_107B3808 == nullptr )
  {
    ModuleState = AfxGetModuleState();
    CursorA = LoadCursorA(hInstance: ModuleState->m_hCurrentInstanceHandle, lpCursorName: (LPCSTR)0x138);
    dword_107B3808 = CursorA;
  }
  SetCursor(hCursor: CursorA);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10165A00
// Name: protected: void CToolPickFace::DeselectAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPickFace::DeselectAll(CToolPickFace *this)
{
  int v2; // edi
  int v3; // ebx

  v2 = 0;
  if ( this->m_Faces.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      this->m_Faces.m_Memory.m_pMemory[v3].pFace->SetSelectionState(
        this: this->m_Faces.m_Memory.m_pMemory[v3].pFace,
        a2: SELECT_NONE);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_Faces.m_Size );
  }
  this->m_Faces.m_Size = 0;
  CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 64, ub: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10165A40
// Name: protected: void CToolPickFace::RemoveFromList(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPickFace::RemoveFromList(CToolPickFace *this, int nIndex)
{
  int m_Size; // eax
  SelectedFace_t *m_pMemory; // edx
  __int64 v4; // xmm0_8
  int v5; // eax
  SelectedFace_t *v6; // edx

  if ( nIndex >= 0 && nIndex < this->m_Faces.m_Size )
  {
    m_Size = this->m_Faces.m_Size;
    if ( m_Size > 0 )
    {
      if ( nIndex != m_Size - 1 )
      {
        m_pMemory = this->m_Faces.m_Memory.m_pMemory;
        v4 = *(_QWORD *)&m_pMemory[m_Size - 1].pFace;
        v5 = (int)&m_pMemory[m_Size - 1];
        v6 = &m_pMemory[nIndex];
        *(_QWORD *)&v6->pFace = v4;
        v6->eOriginalState = *(_DWORD *)(v5 + 8);
      }
      --this->m_Faces.m_Size;
    }
    CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 64, ub: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165AA0
// Name: public: CToolPickFace::CToolPickFace(void)
// Source: json
//------------------------------------------------------------------------------
CToolPickFace *__thiscall CToolPickFace::CToolPickFace(CToolPickFace *this)
{
  SelectedFace_t *m_pMemory; // esi

  this->__vftable = (CToolPickFace_vtbl *)&CBaseTool::`vftable';
  *(_WORD *)&this->m_bActiveTool = 256;
  this->m_pDocument = nullptr;
  this->__vftable = (CToolPickFace_vtbl *)&CToolPickFace::`vftable';
  this->m_Faces.m_Memory.m_pMemory = nullptr;
  this->m_Faces.m_Memory.m_nAllocationCount = 0;
  this->m_Faces.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_Faces.m_Memory.m_pMemory;
  this->m_Faces.m_Size = 0;
  this->m_Faces.m_pElements = m_pMemory;
  this->m_pNotifyTarget = nullptr;
  this->m_bAllowMultiSelect = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10165B30
// Name: public: virtual CToolPickFace::~CToolPickFace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPickFace::~CToolPickFace(CToolPickFace *this)
{
  CUtlVector<SelectedFace_t,CUtlMemory<SelectedFace_t,int> > *p_m_Faces; // esi

  this->__vftable = (CToolPickFace_vtbl *)&CToolPickFace::`vftable';
  p_m_Faces = &this->m_Faces;
  this->m_Faces.m_Size = 0;
  if ( this->m_Faces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Faces->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Faces->m_Memory.m_pMemory);
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
      p_m_Faces->m_Memory.m_pMemory = nullptr;
    }
    p_m_Faces->m_Memory.m_nAllocationCount = 0;
  }
  this->__vftable = (CToolPickFace_vtbl *)&CBaseTool::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10165BD0
// Name: public: virtual void CToolPickFace::OnDeactivate(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CToolPickFace::OnDeactivate(CToolPickFace *this)
{
  CToolPickFace::DeselectAll(this);
}

//------------------------------------------------------------------------------
// Address: 0x10165BE0
// Name: protected: void CToolPickFace::DeselectFace(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPickFace::DeselectFace(CToolPickFace *this, int nIndex)
{
  SelectedFace_t *m_pMemory; // eax
  bool v4; // zf
  CMapFace *pFace; // ecx
  SelectionState_t (__thiscall *SetSelectionState)(struct CMapFace *, SelectionState_t); // eax

  if ( nIndex >= 0 && nIndex < this->m_Faces.m_Size )
  {
    m_pMemory = this->m_Faces.m_Memory.m_pMemory;
    v4 = m_pMemory[nIndex].eOriginalState == FaceState_Partial;
    pFace = m_pMemory[nIndex].pFace;
    SetSelectionState = pFace->SetSelectionState;
    if ( v4 )
    {
      SetSelectionState(this: pFace, a2: SELECT_NONE);
      this->m_Faces.m_Memory.m_pMemory[nIndex].eState = FaceState_None;
    }
    else
    {
      SetSelectionState(this: pFace, a2: SELECT_NONE);
      CToolPickFace::RemoveFromList(this, nIndex);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165C70
// Name: protected: void CToolPickFace::DeselectFace(class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPickFace::DeselectFace(CToolPickFace *this, CMapFace *pFace)
{
  int m_Size; // ecx
  int v4; // esi
  SelectedFace_t *m_pMemory; // edx
  CMapFace **i; // eax
  bool v7; // zf
  SelectionState_t (__thiscall *SetSelectionState)(struct CMapFace *, SelectionState_t); // edx

  m_Size = this->m_Faces.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_Faces.m_Memory.m_pMemory;
    for ( i = &m_pMemory->pFace; *i != pFace; i += 3 )
    {
      if ( ++v4 >= m_Size )
        return;
    }
    if ( v4 >= 0 && v4 < m_Size )
    {
      v7 = m_pMemory[v4].eOriginalState == FaceState_Partial;
      SetSelectionState = m_pMemory[v4].pFace->SetSelectionState;
      if ( v7 )
      {
        ((void (__stdcall *)(_DWORD))SetSelectionState)(a1: 0);
        this->m_Faces.m_Memory.m_pMemory[v4].eState = FaceState_None;
      }
      else
      {
        ((void (__stdcall *)(_DWORD))SetSelectionState)(a1: 0);
        CToolPickFace::RemoveFromList(this, nIndex: v4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165CF0
// Name: protected: void CToolPickFace::AddToList(class CMapFace __near *,enum FaceState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPickFace::AddToList(CToolPickFace *this, CMapFace *pFace, FaceState_t eState)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  SelectedFace_t *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_Faces.m_Memory.m_nAllocationCount;
  m_Size = this->m_Faces.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CheckListItem,int>::Grow(
      this: (CUtlMemory<Vector,int> *)&this->m_Faces,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Faces.m_Size;
  m_pMemory = this->m_Faces.m_Memory.m_pMemory;
  v7 = this->m_Faces.m_Size - m_Size - 1;
  this->m_Faces.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v7);
  v8 = m_Size;
  this->m_Faces.m_Memory.m_pMemory[v8].pFace = pFace;
  this->m_Faces.m_Memory.m_pMemory[v8].eState = eState;
  this->m_Faces.m_Memory.m_pMemory[v8].eOriginalState = eState;
  CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 64, ub: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10165D80
// Name: public: void CToolPickFace::GetSelectedFaces(class CMapFaceList __near &,class CMapFaceList __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPickFace::GetSelectedFaces(
        CToolPickFace *this,
        CUtlMemory<CCullTreeNode *,int> *FaceListFull,
        CUtlMemory<CCullTreeNode *,int> *FaceListPartial)
{
  int m_nAllocationCount; // eax
  int v6; // ebx
  int v7; // eax
  CMapFace **v8; // ecx
  int v9; // eax
  CMapFace **v10; // ebx
  int m_pMemory; // ebx
  int v12; // eax
  CMapFace **v13; // ecx
  int v14; // eax
  CMapFace **v15; // ebx
  CToolPickFace *v16; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]
  CMapFaceList *FaceListFulla; // [esp+18h] [ebp+8h]
  CMapFaceList *FaceListPartiala; // [esp+1Ch] [ebp+Ch]

  FaceListFull[1].m_pMemory = nullptr;
  FaceListPartial[1].m_pMemory = nullptr;
  v16 = this;
  i = 0;
  if ( this->m_Faces.m_Size > 0 )
  {
    FaceListFulla = nullptr;
    do
    {
      FaceListPartiala = (CMapFaceList *)((char *)FaceListFulla + (unsigned int)this->m_Faces.m_Memory.m_pMemory);
      m_nAllocationCount = FaceListPartiala->m_Memory.m_nAllocationCount;
      if ( m_nAllocationCount != 0 )
      {
        if ( m_nAllocationCount == 1 )
        {
          m_pMemory = (int)FaceListPartial[1].m_pMemory;
          v12 = FaceListPartial->m_nAllocationCount;
          if ( m_pMemory + 1 > v12 )
            CUtlMemory<CVisGroup *,int>::Grow(this: FaceListPartial, num: m_pMemory - v12 + 1);
          ++FaceListPartial[1].m_pMemory;
          v13 = (CMapFace **)FaceListPartial->m_pMemory;
          v14 = (int)FaceListPartial[1].m_pMemory - m_pMemory - 1;
          FaceListPartial[1].m_nAllocationCount = (int)FaceListPartial->m_pMemory;
          if ( v14 > 0 )
            _V_memmove(dest: &v13[m_pMemory + 1], src: &v13[m_pMemory], count: 4 * v14);
          v15 = (CMapFace **)&FaceListPartial->m_pMemory[m_pMemory];
          if ( v15 != nullptr )
            *v15 = (CMapFace *)FaceListPartiala->m_Memory.m_pMemory;
        }
      }
      else
      {
        v6 = (int)FaceListFull[1].m_pMemory;
        v7 = FaceListFull->m_nAllocationCount;
        if ( v6 + 1 > v7 )
          CUtlMemory<CVisGroup *,int>::Grow(this: FaceListFull, num: v6 - v7 + 1);
        ++FaceListFull[1].m_pMemory;
        v8 = (CMapFace **)FaceListFull->m_pMemory;
        v9 = (int)FaceListFull[1].m_pMemory - v6 - 1;
        FaceListFull[1].m_nAllocationCount = (int)FaceListFull->m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &v8[v6 + 1], src: &v8[v6], count: 4 * v9);
        v10 = (CMapFace **)&FaceListFull->m_pMemory[v6];
        if ( v10 != nullptr )
          *v10 = (CMapFace *)FaceListPartiala->m_Memory.m_pMemory;
      }
      this = v16;
      FaceListFulla = (CMapFaceList *)((char *)FaceListFulla + 12);
      ++i;
    }
    while ( i < v16->m_Faces.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165EA0
// Name: protected: void CToolPickFace::CycleSelectFace(class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPickFace::CycleSelectFace(CToolPickFace *this, CMapFace *pFace)
{
  int m_Size; // edx
  int v3; // eax
  SelectedFace_t *m_pMemory; // ebx
  CMapFace **p_pFace; // edi
  FaceState_t eState; // edi
  SelectedFace_t *v7; // edx

  m_Size = this->m_Faces.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    goto LABEL_5;
  m_pMemory = this->m_Faces.m_Memory.m_pMemory;
  p_pFace = &m_pMemory->pFace;
  while ( *p_pFace != pFace )
  {
    ++v3;
    p_pFace += 3;
    if ( v3 >= m_Size )
      goto LABEL_5;
  }
  if ( v3 == -1 )
  {
LABEL_5:
    CToolPickFace::AddToList(this, pFace, eState: FaceState_Select);
    pFace->SetSelectionState(this: pFace, a2: SELECT_NORMAL);
  }
  else
  {
    eState = m_pMemory[v3].eState;
    v7 = &m_pMemory[v3];
    switch ( eState )
    {
      case FaceState_Partial:
LABEL_12:
        CToolPickFace::DeselectFace(this, nIndex: v3);
        return;
      case FaceState_Select:
        if ( v7->eOriginalState == FaceState_Partial )
        {
          v7->eState = FaceState_Partial;
          pFace->SetSelectionState(this: pFace, a2: SELECT_MULTI_PARTIAL);
          return;
        }
        goto LABEL_12;
      case FaceState_None:
        v7->eState = FaceState_Select;
        pFace->SetSelectionState(this: pFace, a2: SELECT_NORMAL);
        break;
      default:
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165F40
// Name: public: void CToolPickFace::SetSelectedFaces(class CMapFaceList __near &,class CMapFaceList __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPickFace::SetSelectedFaces(
        CToolPickFace *this,
        CMapFaceList *FaceListFull,
        CMapFaceList *FaceListPartial)
{
  int v3; // ebx
  CUtlMemory<Vector,int> *p_m_Faces; // esi
  CMapFace *v5; // edi
  int m_pMemory; // edi
  CMapFace *v7; // ebx
  int m_nAllocationCount; // eax
  Vector *v9; // ecx
  int v10; // eax
  int v11; // eax
  CToolPickFace *v12; // [esp+Ch] [ebp-4h]
  int i; // [esp+18h] [ebp+8h]

  v3 = 0;
  p_m_Faces = (CUtlMemory<Vector,int> *)&this->m_Faces;
  this->m_Faces.m_Size = 0;
  v12 = this;
  if ( FaceListFull->m_Size > 0 )
  {
    while ( 1 )
    {
      v5 = FaceListFull->m_Memory.m_pMemory[v3];
      CToolPickFace::AddToList(this, pFace: v5, eState: FaceState_Select);
      v5->SetSelectionState(this: v5, a2: SELECT_NORMAL);
      if ( ++v3 >= FaceListFull->m_Size )
        break;
      this = v12;
    }
  }
  for ( i = 0; i < FaceListPartial->m_Size; ++i )
  {
    m_pMemory = (int)p_m_Faces[1].m_pMemory;
    v7 = FaceListPartial->m_Memory.m_pMemory[i];
    m_nAllocationCount = p_m_Faces->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CheckListItem,int>::Grow(this: p_m_Faces, num: m_pMemory - m_nAllocationCount + 1);
    v9 = p_m_Faces->m_pMemory;
    v10 = (int)++p_m_Faces[1].m_pMemory - m_pMemory - 1;
    p_m_Faces[1].m_nAllocationCount = (int)v9;
    if ( v10 > 0 )
      _V_memmove(dest: &v9[m_pMemory + 1], src: &v9[m_pMemory], count: 12 * v10);
    v11 = m_pMemory;
    LODWORD(p_m_Faces->m_pMemory[v11].x) = v7;
    LODWORD(p_m_Faces->m_pMemory[v11].y) = 1;
    LODWORD(p_m_Faces->m_pMemory[v11].z) = 1;
    CMapDoc::UpdateAllViews(this: v12->m_pDocument, nFlags: 64, ub: nullptr);
    v7->SetSelectionState(this: v7, a2: SELECT_MULTI_PARTIAL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166050
// Name: protected: void CToolPickFace::SelectFace(class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPickFace::SelectFace(CToolPickFace *this, CMapFace *pFace)
{
  int m_Size; // edx
  int v3; // eax
  SelectedFace_t *m_pMemory; // edi

  m_Size = this->m_Faces.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    goto LABEL_5;
  m_pMemory = this->m_Faces.m_Memory.m_pMemory;
  while ( m_pMemory->pFace != pFace )
  {
    ++v3;
    ++m_pMemory;
    if ( v3 >= m_Size )
      goto LABEL_5;
  }
  if ( v3 == -1 )
  {
LABEL_5:
    CToolPickFace::AddToList(this, pFace, eState: FaceState_Select);
    pFace->SetSelectionState(this: pFace, a2: SELECT_NORMAL);
  }
  else
  {
    this->m_Faces.m_Memory.m_pMemory[v3].eState = FaceState_Select;
    pFace->SetSelectionState(this: pFace, a2: SELECT_NORMAL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101660B0
// Name: public: void CToolPickFace::AllowMultiSelect(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPickFace::AllowMultiSelect(CToolPickFace *this, bool bAllow)
{
  CMapFace *pFace; // edi

  this->m_bAllowMultiSelect = bAllow;
  if ( !bAllow && this->m_Faces.m_Size > 1 )
  {
    pFace = this->m_Faces.m_Memory.m_pMemory->pFace;
    CToolPickFace::DeselectAll(this);
    CToolPickFace::SelectFace(this, pFace);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101660E0
// Name: public: virtual bool CToolPickFace::OnLMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolPickFace::OnLMouseDown3D(CToolPickFace *this, CMapView3D *pView, char nFlags, CMapSolid *vPoint)
{
  CToolPickFace *v4; // edi
  bool v5; // zf
  CMapClass *v6; // eax
  CMapSolid *v7; // eax
  CMapSolid *v8; // ebx
  CMapFace *Face; // eax
  CMapFace *v10; // esi
  const char *v11; // esi
  int m_Size; // edx
  int v13; // eax
  SelectedFace_t *m_pMemory; // edi
  int nCount; // eax
  unsigned int v16; // ebx
  BlockArray<CMapFace,6,86> *p_Faces; // esi
  int v18; // edi
  unsigned int v19; // esi
  CMapFace *v20; // esi
  int v21; // edx
  int v22; // eax
  SelectedFace_t *v23; // ecx
  SelectedFace_t *v25; // [esp+4h] [ebp-10h]
  unsigned int uFace; // [esp+8h] [ebp-Ch] BYREF
  CToolPickFace *v27; // [esp+Ch] [ebp-8h]
  bool bControl; // [esp+13h] [ebp-1h]
  int nFaceCount; // [esp+1Ch] [ebp+8h]
  int nFaceCounta; // [esp+1Ch] [ebp+8h]
  bool bShift_3; // [esp+23h] [ebp+Fh]
  char bShift_3a; // [esp+23h] [ebp+Fh]
  CMapSolid *pSolid; // [esp+24h] [ebp+10h]
  BlockArray<CMapFace,6,86> *pSolida; // [esp+24h] [ebp+10h]

  v4 = this;
  v5 = !this->m_bAllowMultiSelect;
  v27 = this;
  bControl = (nFlags & 8) != 0;
  bShift_3 = (nFlags & 4) != 0;
  if ( v5 )
    bShift_3 = false;
  v6 = CMapView3D::NearestObjectAt(
         this: pView,
         (const Vector2D *)vPoint,
         ulFace: &uFace,
         nFlags: 0,
         pLocalMatrix: nullptr);
  if ( v6 == nullptr )
    return 1;
  v7 = (CMapSolid *)__RTDynamicCast(
                      inptr: v6,
                      VfDelta: 0,
                      SrcType: &CMapClass `RTTI Type Descriptor',
                      TargetType: &CMapSolid `RTTI Type Descriptor',
                      isReference: 0);
  v8 = v7;
  pSolid = v7;
  if ( v7 != nullptr )
  {
    if ( bShift_3 )
    {
      v11 = nullptr;
      bShift_3a = 1;
      nFaceCount = v7->Faces.nCount;
      if ( nFaceCount > 0 )
      {
        while ( 1 )
        {
          if ( (int)v11 >= v8->Faces.nCount )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v11, v8->Faces.nCount);
            BlockArray<CMapFace,6,86>::SetCount(this: &v8->Faces, nObjects: (int)(v11 + 1));
          }
          m_Size = v4->m_Faces.m_Size;
          v13 = 0;
          if ( m_Size <= 0 )
            break;
          m_pMemory = v4->m_Faces.m_Memory.m_pMemory;
          v25 = m_pMemory;
          while ( m_pMemory->pFace != &v8->Faces.Blocks[(int)v11 / 6][(int)v11 % 6] )
          {
            ++v13;
            ++m_pMemory;
            if ( v13 >= m_Size )
              goto LABEL_18;
          }
          if ( v13 == -1 || v25[v13].eState != FaceState_Select )
          {
LABEL_18:
            v4 = v27;
            break;
          }
          v4 = v27;
          if ( (int)++v11 >= nFaceCount )
            goto LABEL_20;
        }
        bShift_3a = 0;
      }
LABEL_20:
      if ( !bControl )
        CToolPickFace::DeselectAll(this: v4);
      nCount = v8->Faces.nCount;
      v16 = 0;
      nFaceCounta = nCount;
      if ( nCount > 0 )
      {
        p_Faces = &pSolid->Faces;
        for ( pSolida = &pSolid->Faces; ; p_Faces = pSolida )
        {
          if ( (int)v16 >= p_Faces->nCount )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v16, p_Faces->nCount);
            v18 = v16 + 1;
            if ( v16 + 1 != p_Faces->nCount )
            {
              v19 = v18 / 6;
              if ( 6 * (v18 / 6) < v18 )
                ++v19;
              if ( v19 != pSolida->nBlocks )
              {
                if ( v19 > 0x57 )
                  _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
                BlockArray<CMapFace,6,86>::GetBlocks(this: pSolida, nNewBlocks: v19);
              }
              pSolida->nCount = v18;
            }
            v4 = v27;
          }
          v20 = &pSolida->Blocks[v16 / 6][v16 % 6];
          if ( bShift_3a != 0 )
          {
            CToolPickFace::DeselectFace(this: v4, pFace: &pSolida->Blocks[v16 / 6][v16 % 6]);
          }
          else
          {
            v21 = v4->m_Faces.m_Size;
            v22 = 0;
            if ( v21 <= 0 )
              goto LABEL_45;
            v23 = v4->m_Faces.m_Memory.m_pMemory;
            while ( v23->pFace != v20 )
            {
              ++v22;
              ++v23;
              if ( v22 >= v21 )
                goto LABEL_45;
            }
            if ( v22 == -1 )
LABEL_45:
              CToolPickFace::AddToList(this: v4, pFace: v20, eState: FaceState_Select);
            else
              v4->m_Faces.m_Memory.m_pMemory[v22].eState = FaceState_Select;
            v20->SetSelectionState(this: v20, a2: SELECT_NORMAL);
          }
          if ( (int)++v16 >= nFaceCounta )
            break;
        }
      }
    }
    else
    {
      Face = CMapSolid::GetFace(this: v7, nFace: uFace);
      v10 = Face;
      if ( Face != nullptr )
      {
        if ( v4->m_bAllowMultiSelect && bControl )
        {
          CToolPickFace::CycleSelectFace(this: v4, pFace: Face);
        }
        else
        {
          CToolPickFace::DeselectAll(this: v4);
          CToolPickFace::SelectFace(this: v4, pFace: v10);
        }
      }
    }
    if ( v4->m_pNotifyTarget != nullptr )
      v4->m_pNotifyTarget->OnNotifyPickFace(this: v4->m_pNotifyTarget, a2: v4);
  }
  return 1;
}
