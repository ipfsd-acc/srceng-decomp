// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/tooloverlay.cpp
// Functions: 20
// ============================================================

#include "hammer\tooloverlay.h"

//------------------------------------------------------------------------------
// Address: 0x1015B080
// Name: public: virtual bool CToolOverlay::OnKeyDown2D(class CMapView2D __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolOverlay::OnKeyDown2D(
        CToolDecal *this,
        CMapView2D *pView,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  CToolManager *v6; // eax

  if ( nChar != 27 )
    return 0;
  v6 = ToolManager();
  CToolManager::SetTool(this: v6, eNewTool: TOOL_POINTER);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10163DB0
// Name: public: virtual void CToolOverlay::OnActivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolOverlay::OnActivate(CToolOverlay *this)
{
  this->m_bDragging = false;
  this->m_pActiveOverlay = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10163DD0
// Name: private: bool CToolOverlay::HandleSnap(class CMapOverlay __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CToolOverlay::HandleSnap@<al>(
        CToolOverlay *this@<ecx>,
        float a2@<ebp>,
        CMapOverlay *pOverlay,
        Vector *vecHandlePt)
{
  int v4; // esi
  float v5; // xmm1_4
  float v6; // xmm2_4
  Vector v8; // [esp-Ch] [ebp-18h] BYREF
  Vector vecTmp; // [esp+0h] [ebp-Ch]
  float retaddr; // [esp+Ch] [ebp+0h]

  vecTmp.x = a2;
  vecTmp.y = retaddr;
  v4 = 0;
  while ( 1 )
  {
    CMapOverlay::GetHandlePos(this: pOverlay, iHandle: v4, vecPos: &v8);
    v5 = v8.y - vecHandlePt->y;
    v6 = v8.z - vecHandlePt->z;
    v8.x = v8.x - vecHandlePt->x;
    v8.y = v5;
    v8.z = v6;
    if ( fsqrt((float)((float)(v5 * v5) + (float)(v6 * v6)) + (float)(v8.x * v8.x)) < 35.0 )
      break;
    if ( ++v4 >= 4 )
      return 0;
  }
  CMapOverlay::GetHandlePos(this: pOverlay, iHandle: v4, vecPos: vecHandlePt);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10163E90
// Name: private: bool CToolOverlay::HandleInBBox(class CMapOverlay __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolOverlay::HandleInBBox(CToolOverlay *this, CMapOverlay *pOverlay, const Vector *vecHandlePt)
{
  int v3; // ecx
  float v4; // xmm2_4
  float v5; // xmm0_4
  Vector vecMin; // [esp+0h] [ebp-18h] BYREF
  Vector vecMax; // [esp+Ch] [ebp-Ch] BYREF

  CMapClass::GetCullBox(this: pOverlay, mins: &vecMin, maxs: &vecMax);
  v3 = 0;
  while ( 1 )
  {
    *(float *)((char *)&vecMin.x + v3) = *(float *)((char *)&vecMin.x + v3) - 35.0;
    v4 = *(float *)((char *)&vecMin.x + v3);
    *(float *)((char *)&vecMax.x + v3) = *(float *)((char *)&vecMax.x + v3) + 35.0;
    v5 = *(float *)((char *)&vecMin.x + v3 + (char *)vecHandlePt - (char *)&vecMin);
    if ( v4 > v5 || v5 > *(float *)((char *)&vecMax.x + v3) )
      break;
    v3 += 4;
    if ( v3 >= 12 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10163F20
// Name: private: void CToolOverlay::PreDrag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolOverlay::PreDrag(CToolOverlay *this)
{
  CMapOverlay *m_pActiveOverlay; // ecx
  CMapClass *v3; // edi
  CHistory *History; // eax
  CHistory *v5; // eax
  const CUtlReferenceVector<CMapClass> *List; // [esp-10h] [ebp-14h]

  m_pActiveOverlay = this->m_pActiveOverlay;
  this->m_bDragging = true;
  if ( m_pActiveOverlay != nullptr )
  {
    v3 = m_pActiveOverlay->GetParent(this: m_pActiveOverlay);
    if ( v3 != nullptr )
    {
      List = CSelection::GetList(this: this->m_pDocument->m_pSelection);
      History = GetHistory();
      CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Drag Overlay Handle", bFromOpposite: 0);
      v5 = GetHistory();
      CHistory::Keep(this: v5, pObject: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163F80
// Name: public: CToolOverlay::CToolOverlay(void)
// Source: json
//------------------------------------------------------------------------------
CToolOverlay *__thiscall CToolOverlay::CToolOverlay(CToolOverlay *this)
{
  Box3D::Box3D(this);
  this->Box3D::Tool3D::CBaseTool::__vftable = (CToolOverlay_vtbl *)&CToolOverlay::`vftable'{for `Tool3D'};
  this->Box3D::BoundBox::__vftable = (BoundBox_vtbl *)&CToolOverlay::`vftable'{for `BoundBox'};
  this->m_bDragging = false;
  this->m_pActiveOverlay = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10164040
// Name: public: virtual bool CToolOverlay::OnContextMenu2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolOverlay::OnContextMenu2D(
        CToolOverlay *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  AFX_MODULE_STATE *ModuleState; // eax
  HMENU MenuW; // eax
  HMENU SubMenu; // eax
  float x; // xmm1_4
  float y; // xmm0_4
  int v12; // eax
  HWND__ *m_hWnd; // edx
  CPoint ptScreen; // [esp+Ch] [ebp-14h] BYREF
  int v15; // [esp+1Ch] [ebp-4h]
  const Vector2D *vPointa; // [esp+30h] [ebp+10h]

  if ( (_S1_24 & 1) == 0 )
  {
    _S1_24 |= 1u;
    menu_2.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
    menu_2.m_hMenu = nullptr;
    atexit(func: CToolOverlay::OnContextMenu2D_::_2_::_dynamic_atexit_destructor_for__menu__);
    v15 = -1;
  }
  if ( (_S1_24 & 2) == 0 )
  {
    _S1_24 |= 2u;
    menuOverlay.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
    menuOverlay.m_hMenu = nullptr;
    atexit(func: CToolOverlay::OnContextMenu2D_::_2_::_dynamic_atexit_destructor_for__menuOverlay__);
    v15 = -1;
  }
  if ( !bInit_8 )
  {
    ModuleState = AfxGetModuleState();
    MenuW = LoadMenuW(hInstance: ModuleState->m_hCurrentResourceHandle, lpMenuName: (LPCWSTR)0xB6);
    CMenu::Attach(this: &menu_2, hMenu: MenuW);
    SubMenu = GetSubMenu(hMenu: menu_2.m_hMenu, nPos: 6);
    CMenu::Attach(this: &menuOverlay, hMenu: SubMenu);
    bInit_8 = true;
  }
  x = vPoint->x;
  if ( vPoint->x < 0.0 )
    return 0;
  y = vPoint->y;
  vPointa = (const Vector2D *)&vPoint->y;
  if ( y < 0.0 || (float)pView->m_ClientWidth <= x || (float)pView->m_ClientHeight <= y )
    return 0;
  if ( !this->IsEmpty(this) && this->HitTest(this, a2: &pView->CMapView, a3: vPoint, a4: false) != 0 )
  {
    v12 = (int)vPointa->x;
    m_hWnd = pView->m_hWnd;
    ptScreen.x = (int)vPoint->x;
    ptScreen.y = v12;
    ClientToScreen(hWnd: m_hWnd, lpPoint: &ptScreen);
    CMenu::TrackPopupMenu(this: &menuOverlay, nFlags: 2u, x: ptScreen.x, y: ptScreen.y, pWnd: pView, lpRect: nullptr);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101641F0
// Name: private: void CToolOverlay::InitOverlay(class CMapEntity __near *,class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolOverlay::InitOverlay(CToolOverlay *this, CMapEntity *pEntity, CMapFace *pFace)
{
  int i; // edi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v5; // ecx
  void *v6; // esi
  CMapOverlay *v7; // eax
  CMapOverlay *v8; // esi
  void (__thiscall *CalcBounds)(CMapClass *, int); // eax
  CUtlReference<CMapClass> *m_pHead; // [esp+0h] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v11; // [esp+4h] [ebp-14h]
  void *inptr; // [esp+8h] [ebp-10h]
  int v13; // [esp+14h] [ebp-4h]

  if ( pFace != nullptr )
  {
    for ( i = 0; i < pEntity->m_Children.m_Size; ++i )
    {
      m_pObject = pEntity->m_Children.m_Memory.m_pMemory[i >> (*((int *)&pEntity->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&pEntity->m_Children.m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        inptr = pEntity->m_Children.m_Memory.m_pMemory[i >> (*((int *)&pEntity->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&pEntity->m_Children.m_Memory + 2)) >> 5)].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v5 = m_pObject->m_References.m_pHead;
        if ( v5 != nullptr )
          v5->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v11 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v6 = inptr;
      v13 = -1;
      if ( inptr != nullptr )
      {
        if ( v11 != nullptr )
        {
          v11->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v11;
        }
        else if ( *((CUtlReference<CMapClass> ***)inptr + 8) == &m_pHead )
        {
          *((_DWORD *)inptr + 8) = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v11 = nullptr;
        m_pHead = nullptr;
        inptr = nullptr;
      }
      v7 = (CMapOverlay *)__RTDynamicCast(
                            inptr: v6,
                            VfDelta: 0,
                            SrcType: &CMapClass `RTTI Type Descriptor',
                            TargetType: &CMapOverlay `RTTI Type Descriptor',
                            isReference: 0);
      v8 = v7;
      if ( v7 != nullptr )
      {
        CMapOverlay::Basis_Init(this: v7, pFace);
        CMapOverlay::Handles_Init(this: v8, pFace);
        CMapOverlay::SideList_Init(this: v8, pFace);
        CalcBounds = v8->CalcBounds;
        v8->m_uiFlags |= 1u;
        v8->m_bLoaded = true;
        CalcBounds(this: v8, a2: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164350
// Name: private: void CToolOverlay::HandlesReset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolOverlay::HandlesReset(CToolOverlay *this)
{
  const CUtlReferenceVector<CMapClass> *List; // esi
  int v2; // edx
  __int64 v3; // kr00_8
  CUtlReference<CMapClass> *v4; // ecx
  int v5; // edx
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v7; // ecx
  _DWORD *v8; // edi
  int v9; // esi
  int v10; // eax
  int v11; // ecx
  void *v12; // edx
  CMapOverlay *v13; // eax
  int v14; // [esp+8h] [ebp-2Ch] BYREF
  _DWORD *v15; // [esp+Ch] [ebp-28h]
  void *inptr; // [esp+10h] [ebp-24h]
  CUtlReference<CMapClass> *m_pHead; // [esp+14h] [ebp-20h] BYREF
  CUtlReference<CMapClass> *v18; // [esp+18h] [ebp-1Ch]
  _DWORD *v19; // [esp+1Ch] [ebp-18h]
  int iSelection; // [esp+20h] [ebp-14h]
  const CUtlReferenceVector<CMapClass> *pSelection; // [esp+24h] [ebp-10h]
  int v22; // [esp+30h] [ebp-4h]

  List = CSelection::GetList(this: this->m_pDocument->m_pSelection);
  v2 = 0;
  pSelection = List;
  for ( iSelection = 0; v2 < List->m_Size; iSelection = v2 )
  {
    v3 = 32LL * *((int *)&List->m_Memory + 2);
    v4 = List->m_Memory.m_pMemory[v2 >> SBYTE4(v3)];
    v5 = v2 & ((int)v3 >> 5);
    m_pObject = v4[v5].m_pObject;
    if ( m_pObject != nullptr )
    {
      v19 = &v4[v5].m_pObject->__vftable;
      m_pHead = m_pObject->m_References.m_pHead;
      v7 = m_pObject->m_References.m_pHead;
      if ( v7 != nullptr )
        v7->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
      v18 = nullptr;
      m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
    }
    v8 = v19;
    v22 = -1;
    if ( v19 != nullptr )
    {
      if ( v18 != nullptr )
      {
        v18->m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = v18;
      }
      else if ( (CUtlReference<CMapClass> **)v19[8] == &m_pHead )
      {
        v19[8] = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = nullptr;
      }
      v18 = nullptr;
      m_pHead = nullptr;
      v19 = nullptr;
    }
    if ( v8 != nullptr && (*(int (__thiscall **)(_DWORD *, char *))(*v8 + 204))(a1: v8, a2: CMapEntity::__Type) != 0 )
    {
      v9 = 0;
      if ( (int)v8[34] > 0 )
      {
        while ( 1 )
        {
          v10 = *(_DWORD *)(*(_DWORD *)(v8[31] + 4 * (v9 >> ((unsigned __int64)(int)v8[33] >> 27)))
                          + 12 * (v9 & ((32 * v8[33]) >> 5))
                          + 8);
          if ( v10 != 0 )
          {
            inptr = *(void **)(*(_DWORD *)(v8[31] + 4 * (v9 >> ((unsigned __int64)(int)v8[33] >> 27)))
                             + 12 * (v9 & ((32 * v8[33]) >> 5))
                             + 8);
            v14 = *(_DWORD *)(v10 + 32);
            v11 = *(_DWORD *)(v10 + 32);
            if ( v11 != 0 )
              *(_DWORD *)(v11 + 4) = &v14;
            v15 = nullptr;
            *(_DWORD *)(v10 + 32) = &v14;
          }
          v12 = inptr;
          v22 = -1;
          if ( inptr != nullptr )
          {
            if ( v15 != nullptr )
            {
              *v15 = v14;
              if ( v14 != 0 )
                *(_DWORD *)(v14 + 4) = v15;
            }
            else if ( *((int **)inptr + 8) == &v14 )
            {
              *((_DWORD *)inptr + 8) = v14;
              if ( v14 != 0 )
                *(_DWORD *)(v14 + 4) = 0;
            }
            v15 = nullptr;
            v14 = 0;
            inptr = nullptr;
          }
          v13 = (CMapOverlay *)__RTDynamicCast(
                                 inptr: v12,
                                 VfDelta: 0,
                                 SrcType: &CMapClass `RTTI Type Descriptor',
                                 TargetType: &CMapOverlay `RTTI Type Descriptor',
                                 isReference: 0);
          if ( v13 != nullptr )
            break;
          if ( ++v9 >= v8[34] )
            goto LABEL_33;
        }
        CMapOverlay::HandlesReset(this: v13);
      }
LABEL_33:
      List = pSelection;
    }
    v2 = iSelection + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164550
// Name: private: bool CToolOverlay::HandleSelection(class CMapView __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolOverlay::HandleSelection(CToolOverlay *this, CMapView *pView, const Vector2D *vPoint)
{
  CToolOverlay *v3; // ebx
  CMapDoc *m_pDocument; // eax
  CSelection *m_pSelection; // ecx
  const CUtlReferenceVector<CMapClass> *List; // edi
  int v7; // edx
  __int64 v8; // kr00_8
  CUtlReference<CMapClass> *v9; // ecx
  int v10; // edx
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v12; // ecx
  _DWORD *v13; // ebx
  int v14; // edi
  int v15; // eax
  int v16; // ecx
  void *v17; // edx
  CMapOverlay *v18; // eax
  CMapOverlay *v19; // esi
  int v21; // [esp+Ch] [ebp-30h] BYREF
  _DWORD *v22; // [esp+10h] [ebp-2Ch]
  void *inptr; // [esp+14h] [ebp-28h]
  CUtlReference<CMapClass> *m_pHead; // [esp+18h] [ebp-24h] BYREF
  CUtlReference<CMapClass> *v25; // [esp+1Ch] [ebp-20h]
  _DWORD *v26; // [esp+20h] [ebp-1Ch]
  CToolOverlay *v27; // [esp+24h] [ebp-18h]
  int iSelection; // [esp+28h] [ebp-14h]
  const CUtlReferenceVector<CMapClass> *pSelection; // [esp+2Ch] [ebp-10h]
  int v30; // [esp+38h] [ebp-4h]

  v3 = this;
  m_pDocument = this->m_pDocument;
  this->m_pActiveOverlay = nullptr;
  m_pSelection = m_pDocument->m_pSelection;
  v27 = v3;
  List = CSelection::GetList(this: m_pSelection);
  v7 = 0;
  pSelection = List;
  iSelection = 0;
  if ( List->m_Size > 0 )
  {
    do
    {
      v8 = 32LL * *((int *)&List->m_Memory + 2);
      v9 = List->m_Memory.m_pMemory[v7 >> SBYTE4(v8)];
      v10 = v7 & ((int)v8 >> 5);
      m_pObject = v9[v10].m_pObject;
      if ( m_pObject != nullptr )
      {
        v26 = &v9[v10].m_pObject->__vftable;
        m_pHead = m_pObject->m_References.m_pHead;
        v12 = m_pObject->m_References.m_pHead;
        if ( v12 != nullptr )
          v12->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v25 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v13 = v26;
      v30 = -1;
      if ( v26 != nullptr )
      {
        if ( v25 != nullptr )
        {
          v25->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v25;
        }
        else if ( (CUtlReference<CMapClass> **)v26[8] == &m_pHead )
        {
          v26[8] = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v25 = nullptr;
        m_pHead = nullptr;
        v26 = nullptr;
      }
      if ( v13 != nullptr
        && (*(int (__thiscall **)(_DWORD *, char *))(*v13 + 204))(a1: v13, a2: CMapEntity::__Type) != 0 )
      {
        v14 = 0;
        if ( (int)v13[34] > 0 )
        {
          while ( 1 )
          {
            v15 = *(_DWORD *)(*(_DWORD *)(v13[31] + 4 * (v14 >> ((unsigned __int64)(int)v13[33] >> 27)))
                            + 12 * (v14 & ((32 * v13[33]) >> 5))
                            + 8);
            if ( v15 != 0 )
            {
              inptr = *(void **)(*(_DWORD *)(v13[31] + 4 * (v14 >> ((unsigned __int64)(int)v13[33] >> 27)))
                               + 12 * (v14 & ((32 * v13[33]) >> 5))
                               + 8);
              v21 = *(_DWORD *)(v15 + 32);
              v16 = *(_DWORD *)(v15 + 32);
              if ( v16 != 0 )
                *(_DWORD *)(v16 + 4) = &v21;
              v22 = nullptr;
              *(_DWORD *)(v15 + 32) = &v21;
            }
            v17 = inptr;
            v30 = -1;
            if ( inptr != nullptr )
            {
              if ( v22 != nullptr )
              {
                *v22 = v21;
                if ( v21 != 0 )
                  *(_DWORD *)(v21 + 4) = v22;
              }
              else if ( *((int **)inptr + 8) == &v21 )
              {
                *((_DWORD *)inptr + 8) = v21;
                if ( v21 != 0 )
                  *(_DWORD *)(v21 + 4) = 0;
              }
              v22 = nullptr;
              v21 = 0;
              inptr = nullptr;
            }
            v18 = (CMapOverlay *)__RTDynamicCast(
                                   inptr: v17,
                                   VfDelta: 0,
                                   SrcType: &CMapClass `RTTI Type Descriptor',
                                   TargetType: &CMapOverlay `RTTI Type Descriptor',
                                   isReference: 0);
            v19 = v18;
            if ( v18 != nullptr
              && v18->GetSelectionState(this: v18) == SELECT_NORMAL
              && CMapOverlay::HandlesHitTest(this: v19, pView, vPoint) != 0 )
            {
              break;
            }
            if ( ++v14 >= v13[34] )
              goto LABEL_35;
          }
          v27->m_pActiveOverlay = v19;
        }
LABEL_35:
        List = pSelection;
      }
      v7 = iSelection + 1;
      iSelection = v7;
    }
    while ( v7 < List->m_Size );
    v3 = v27;
  }
  return v3->m_pActiveOverlay != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10164790
// Name: private: void CToolOverlay::SnapHandle(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolOverlay::SnapHandle(CToolOverlay *this, Vector *vecHandlePt)
{
  CMapWorld *ActiveWorld; // eax
  CMapClass *FirstDescendent; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // edi
  int v6; // ebx
  int v7; // eax
  int v8; // ecx
  void *v9; // edx
  CMapOverlay *v10; // eax
  CMapOverlay *v11; // esi
  EnumChildrenPos_t pos; // [esp+4h] [ebp-A4h] BYREF
  CMapWorld *pWorld; // [esp+88h] [ebp-20h]
  CToolOverlay *v14; // [esp+8Ch] [ebp-1Ch]
  int v15; // [esp+90h] [ebp-18h] BYREF
  _DWORD *v16; // [esp+94h] [ebp-14h]
  void *inptr; // [esp+98h] [ebp-10h]
  int v18; // [esp+A4h] [ebp-4h]
  int savedregs; // [esp+A8h] [ebp+0h] BYREF

  v14 = this;
  ActiveWorld = GetActiveWorld();
  pWorld = ActiveWorld;
  if ( ActiveWorld != nullptr )
  {
    FirstDescendent = CMapClass::GetFirstDescendent(this: ActiveWorld, (CMapClass *)&pos);
    if ( FirstDescendent != nullptr )
    {
      while ( 1 )
      {
        v4 = __RTDynamicCast(
               inptr: FirstDescendent,
               VfDelta: 0,
               SrcType: &CMapClass `RTTI Type Descriptor',
               TargetType: &CMapEntity `RTTI Type Descriptor',
               isReference: 0);
        v5 = v4;
        if ( v4 != nullptr )
        {
          v6 = 0;
          if ( (int)v4[34] > 0 )
            break;
        }
LABEL_23:
        FirstDescendent = CMapClass::GetNextDescendent(this: pWorld, (CMapClass *)&pos);
        if ( FirstDescendent == nullptr )
          return;
      }
      while ( 1 )
      {
        v7 = *(_DWORD *)(*(_DWORD *)(v5[31] + 4 * (v6 >> ((unsigned __int64)(int)v5[33] >> 27)))
                       + 12 * (v6 & ((32 * v5[33]) >> 5))
                       + 8);
        if ( v7 != 0 )
        {
          inptr = *(void **)(*(_DWORD *)(v5[31] + 4 * (v6 >> ((unsigned __int64)(int)v5[33] >> 27)))
                           + 12 * (v6 & ((32 * v5[33]) >> 5))
                           + 8);
          v15 = *(_DWORD *)(v7 + 32);
          v8 = *(_DWORD *)(v7 + 32);
          if ( v8 != 0 )
            *(_DWORD *)(v8 + 4) = &v15;
          v16 = nullptr;
          *(_DWORD *)(v7 + 32) = &v15;
        }
        v9 = inptr;
        v18 = -1;
        if ( inptr != nullptr )
        {
          if ( v16 != nullptr )
          {
            *v16 = v15;
            if ( v15 != 0 )
              *(_DWORD *)(v15 + 4) = v16;
          }
          else if ( *((int **)inptr + 8) == &v15 )
          {
            *((_DWORD *)inptr + 8) = v15;
            if ( v15 != 0 )
              *(_DWORD *)(v15 + 4) = 0;
          }
          v16 = nullptr;
          v15 = 0;
          inptr = nullptr;
        }
        v10 = (CMapOverlay *)__RTDynamicCast(
                               inptr: v9,
                               VfDelta: 0,
                               SrcType: &CMapClass `RTTI Type Descriptor',
                               TargetType: &CMapOverlay `RTTI Type Descriptor',
                               isReference: 0);
        v11 = v10;
        if ( v10 != nullptr
          && v10 != v14->m_pActiveOverlay
          && v10->GetSelectionState(this: v10) == SELECT_NORMAL
          && CToolOverlay::HandleInBBox(this: v14, pOverlay: v11, vecHandlePt) != 0
          && CToolOverlay::HandleSnap(this: v14, a2: COERCE_FLOAT(&savedregs), pOverlay: v11, vecHandlePt) != 0 )
        {
          break;
        }
        if ( ++v6 >= v5[34] )
          goto LABEL_23;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164940
// Name: private: void CToolOverlay::OnDrag(class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolOverlay::OnDrag(
        CToolOverlay *this,
        const Vector *vecRayStart,
        const Vector *vecRayEnd,
        bool bShift)
{
  CMapOverlay *m_pActiveOverlay; // ebx
  int m_Size; // eax
  CMapFace *v6; // esi
  int v7; // edi
  bool v8; // zf
  Vector vecImpactNormal; // [esp+4h] [ebp-20h] BYREF
  Vector vecImpact; // [esp+10h] [ebp-14h] BYREF
  CToolOverlay *v11; // [esp+1Ch] [ebp-8h]
  int nFaceCount; // [esp+20h] [ebp-4h]

  m_pActiveOverlay = this->m_pActiveOverlay;
  v11 = this;
  if ( m_pActiveOverlay != nullptr )
  {
    memset(&vecImpact, 0, sizeof(vecImpact));
    memset(&vecImpactNormal, 0, sizeof(vecImpactNormal));
    m_Size = m_pActiveOverlay->m_Faces.m_Size;
    v6 = nullptr;
    v7 = 0;
    for ( nFaceCount = m_Size; v7 < m_Size; ++v7 )
    {
      v6 = m_pActiveOverlay->m_Faces.m_Memory.m_pMemory[v7];
      if ( v6 != nullptr )
      {
        v8 = CMapFace::TraceLineInside(
               this: v6,
               HitPos: &vecImpact,
               HitNormal: &vecImpactNormal,
               Start: vecRayStart,
               End: vecRayEnd,
               bNoDisp: false) == 0;
        m_Size = nFaceCount;
        if ( !v8 )
          break;
      }
    }
    if ( v7 != m_Size )
    {
      if ( bShift )
        CToolOverlay::SnapHandle(this: v11, vecHandlePt: &vecImpact);
      CMapOverlay::HandlesDragTo(this: m_pActiveOverlay, &vecImpact, pFace: v6);
      CMapDoc::UpdateAllViews(this: v11->m_pDocument, nFlags: 64, ub: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164A00
// Name: public: virtual bool CToolOverlay::OnLMouseUp3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolOverlay::OnLMouseUp3D(
        CToolOverlay *this,
        CMapView3D *pView,
        CMapView3D *nFlags,
        const Vector2D *vPoint)
{
  CMapOverlay *m_pActiveOverlay; // esi
  CMainFrame *MainWnd; // eax

  if ( this->m_bDragging )
  {
    m_pActiveOverlay = this->m_pActiveOverlay;
    this->m_bDragging = false;
    if ( m_pActiveOverlay != nullptr )
    {
      CMapOverlay::DoClip(this: m_pActiveOverlay);
      CMapOverlay::CenterEntity(this: m_pActiveOverlay);
      m_pActiveOverlay->PostUpdate(this: m_pActiveOverlay, a2: Notify_Changed);
      CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 1, ub: nullptr);
    }
    CToolOverlay::HandlesReset(this);
  }
  MainWnd = GetMainWnd();
  CObjectProperties::MarkDataDirty(this: MainWnd->pObjectProperties);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10164A70
// Name: public: virtual bool CToolOverlay::OnMouseMove3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolOverlay::OnMouseMove3D(
        CToolOverlay *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  Vector vecStart; // [esp+4h] [ebp-1Ch] BYREF
  Vector vecEnd; // [esp+10h] [ebp-10h] BYREF
  BOOL bShift; // [esp+1Ch] [ebp-4h]

  if ( this->m_bDragging )
  {
    LOBYTE(bShift) = GetKeyState(nVirtKey: 16) < 0;
    if ( pView->m_pCamera != nullptr )
    {
      pView->BuildRay(this: &pView->CMapView, a2: vPoint, a3: &vecStart, a4: &vecEnd);
      CToolOverlay::OnDrag(this, vecRayStart: &vecStart, vecRayEnd: &vecEnd, bShift);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10164AD0
// Name: private: bool CToolOverlay::CreateOverlay(class CMapSolid __near *,unsigned long,class CMapView3D __near *,class Vector2D)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolOverlay::CreateOverlay(
        CToolOverlay *this,
        CMapFace *pSolid,
        signed int iFace,
        CMapView3D *pView,
        Vector2D point)
{
  CMapEntity *v6; // eax
  CMapEntity *v7; // esi
  char *DefaultTextureName; // eax
  void (__thiscall *SetOrigin)(CMapPoint *, Vector *); // edx
  CHistory *History; // eax
  CHistory *v11; // eax
  CMapDoc *m_pDocument; // ecx
  Vector vecHitNormal; // [esp+Ch] [ebp-3Ch] BYREF
  Vector vecHitPos; // [esp+18h] [ebp-30h] BYREF
  Vector vecStart; // [esp+24h] [ebp-24h] BYREF
  Vector vecEnd; // [esp+30h] [ebp-18h] BYREF
  int v18; // [esp+44h] [ebp-4h]
  CMapFace *pFace; // [esp+50h] [ebp+8h]
  CMapView3D *pViewa; // [esp+58h] [ebp+10h]

  pView->BuildRay(this: &pView->CMapView, a2: &point, a3: &vecStart, a4: &vecEnd);
  if ( iFace >= *(__int16 *)&pSolid[1].texture.texture[100] )
  {
    _Error(
      this: (ISceneTokenProcessor *)&stru_105DC45C,
      a2: (const char *)iFace,
      *(__int16 *)&pSolid[1].texture.texture[100]);
    BlockArray<CMapFace,6,86>::SetCount(
      this: (BlockArray<CMapFace,6,86> *)&pSolid->texture.texture[196],
      nObjects: iFace + 1);
  }
  pFace = (CMapFace *)(*(_DWORD *)&pSolid->texture.texture[4 * (iFace / 6) + 196] + 444 * (iFace % 6));
  if ( CMapFace::TraceLine(this: pFace, HitPos: &vecHitPos, HitNormal: &vecHitNormal, Start: &vecStart, End: &vecEnd) == 0 )
    return 0;
  v6 = (CMapEntity *)operator new(nSize: 0x184u);
  v7 = nullptr;
  v18 = 0;
  if ( v6 != nullptr )
    v7 = CMapEntity::CMapEntity(this: v6);
  v18 = -1;
  pViewa = (CMapView3D *)&v7->SetKeyValue;
  DefaultTextureName = GetDefaultTextureName();
  ((void (__thiscall *)(CEditGameClass *, const char *, char *))pViewa->CView::CWnd::CCmdTarget::CObject::__vftable)(
    a1: &v7->CEditGameClass,
    a2: "material",
    a3: DefaultTextureName);
  SetOrigin = v7->SetOrigin;
  v7->flags |= 1u;
  SetOrigin(this: v7, a2: &vecHitPos);
  v7->SetClass(this: &v7->CEditGameClass, a2: "info_overlay", a3: false);
  this->m_pDocument->AddObjectToWorld(this: this->m_pDocument, a2: v7, a3: nullptr);
  History = GetHistory();
  CHistory::MarkUndoPosition(this: History, pSelection: nullptr, pszName: "Create Overlay", bFromOpposite: 0);
  v11 = GetHistory();
  CHistory::KeepNew(this: v11, pObject: v7, bKeepChildren: true);
  CToolOverlay::InitOverlay(this, pEntity: v7, pFace);
  v7->CalcBounds(this: v7, a2: 1);
  CMapDoc::SelectObject(this: this->m_pDocument, pObj: v7, cmd: 2);
  m_pDocument = this->m_pDocument;
  this->m_bEmpty = false;
  m_pDocument->SetModifiedFlag(this: m_pDocument, a2: 1);
  this->m_pShoreline = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10164CA0
// Name: private: void CToolOverlay::OverlaySelection(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolOverlay::OverlaySelection(
        CToolOverlay *this,
        CMapView3D *pView,
        char nFlags,
        const Vector2D *vPoint)
{
  int v5; // eax
  CMapClass **v6; // esi
  CMapClass *v7; // eax
  CUtlReference<CMapClass> *m_pHead; // ecx
  CMapDoc *m_pDocument; // ecx
  int v10; // edi
  CMapClass *m_pObject; // ecx
  int v12; // esi
  int j; // edi
  int v14; // eax
  int v15; // ecx
  CMapClass *v16; // edx
  CToolOverlay *v17; // ecx
  int v18; // eax
  int k; // esi
  _BYTE v20[38912]; // [esp+Ch] [ebp-9834h] BYREF
  CMapClass *ParentWnd; // [esp+980Ch] [ebp-34h]
  CToolOverlay *v22; // [esp+9810h] [ebp-30h]
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > v23; // [esp+9814h] [ebp-2Ch] BYREF
  CUtlReference<CMapClass> src; // [esp+9828h] [ebp-18h] BYREF
  int v25; // [esp+983Ch] [ebp-4h]
  int i; // [esp+9848h] [ebp+8h]
  char v27; // [esp+984Bh] [ebp+Bh]
  int v28; // [esp+9850h] [ebp+10h]

  v22 = this;
  memset(&v23, 0, 12);
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &v23.m_Memory, nGrowSize: 0, nInitSize: 0);
  v23.m_Size = 0;
  v23.m_pElements = nullptr;
  v25 = 3;
  CSelection::ClearHitList(this: this->m_pDocument->m_pSelection);
  v5 = pView->ObjectsAt(this: &pView->CMapView, a2: vPoint, a3: (HitInfo_s *)v20, a4: 512, a5: 0);
  if ( v5 > 0 )
  {
    v6 = (CMapClass **)v20;
    for ( i = v5; i != 0; --i )
    {
      v7 = *v6;
      if ( *v6 != nullptr )
      {
        m_pHead = v7->m_References.m_pHead;
        src.m_pPrev = nullptr;
        src.m_pObject = v7;
        src.m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = &src;
        src.m_pPrev = nullptr;
        v7->m_References.m_pHead = &src;
        LOBYTE(v25) = 4;
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
          this: &v23,
          elem: v23.m_Size,
          &src);
        LOBYTE(v25) = 3;
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
      }
      v6 += 19;
    }
  }
  m_pDocument = this->m_pDocument;
  if ( v23.m_Size != 0 )
  {
    v27 = 0;
    v10 = 0;
    ParentWnd = CVGuiWnd::GetParentWnd(this: (CMapClass *)m_pDocument->m_pSelection);
    v28 = 0;
    if ( v23.m_Size > 0 )
    {
      do
      {
        m_pObject = v23.m_Memory.m_pMemory[v10 >> ((unsigned __int64)*((int *)&v23.m_Memory + 2) >> 27)][v10 & ((32 * *((_DWORD *)&v23.m_Memory + 2)) >> 5)].m_pObject;
        v12 = (int)m_pObject->PrepareSelection(this: m_pObject, a2: (SelectMode_t)ParentWnd);
        if ( v12 != 0
          && (*(int (__thiscall **)(int, char *))(*(_DWORD *)v12 + 204))(a1: v12, a2: CMapEntity::__Type) != 0 )
        {
          for ( j = 0; j < *(_DWORD *)(v12 + 136); ++j )
          {
            v14 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v12 + 124)
                                        + 4 * (j >> ((unsigned __int64)*(int *)(v12 + 132) >> 27)))
                            + 12 * (j & ((32 * *(_DWORD *)(v12 + 132)) >> 5))
                            + 8);
            if ( v14 != 0 )
            {
              src.m_pObject = *(CMapClass **)(*(_DWORD *)(*(_DWORD *)(v12 + 124)
                                                        + 4 * (j >> ((unsigned __int64)*(int *)(v12 + 132) >> 27)))
                                            + 12 * (j & ((32 * *(_DWORD *)(v12 + 132)) >> 5))
                                            + 8);
              src.m_pNext = *(CUtlReference<CMapClass> **)(v14 + 32);
              v15 = *(_DWORD *)(v14 + 32);
              if ( v15 != 0 )
                *(_DWORD *)(v15 + 4) = &src;
              src.m_pPrev = nullptr;
              *(_DWORD *)(v14 + 32) = &src;
            }
            v16 = src.m_pObject;
            LOBYTE(v25) = 3;
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
            if ( __RTDynamicCast(
                   inptr: v16,
                   VfDelta: 0,
                   SrcType: &CMapClass `RTTI Type Descriptor',
                   TargetType: &CMapOverlay `RTTI Type Descriptor',
                   isReference: 0) != nullptr )
            {
              CSelection::AddHit(this: v22->m_pDocument->m_pSelection, pObject: (CMapClass *)v12);
              v17 = v22;
              v22->m_bEmpty = false;
              v18 = 1042;
              if ( (nFlags & 8) != 0 )
                v18 = 1;
              CMapDoc::SelectObject(this: v17->m_pDocument, pObj: (CMapClass *)v12, cmd: v18);
              v27 = 1;
            }
          }
          v10 = v28;
        }
        v28 = ++v10;
      }
      while ( v10 < v23.m_Size );
      if ( v27 != 0 )
        CMapDoc::UpdateAllViews(this: v22->m_pDocument, nFlags: 1, ub: nullptr);
    }
    v25 = 10;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this: &v23);
    if ( v23.m_Memory.m_pMemory != nullptr )
    {
      for ( k = 0; k < v23.m_Memory.m_nBlocks; ++k )
        free(pMem: v23.m_Memory.m_pMemory[k]);
      v23.m_Memory.m_nBlocks = 0;
      free(pMem: v23.m_Memory.m_pMemory);
    }
  }
  else
  {
    CMapDoc::SelectFace(this: m_pDocument, pSolid: 0, cmd: 16);
    CMapDoc::SelectObject(this: this->m_pDocument, pObj: nullptr, cmd: 1040);
    this->SetEmpty(this);
    v25 = -1;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &v23);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165040
// Name: public: virtual bool CToolOverlay::OnLMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolOverlay::OnLMouseDown3D(
        CToolOverlay *this,
        CMapView3D *pView,
        char nFlags,
        const Vector2D *vPoint)
{
  CMapView3D *v4; // edi
  CMapView *v6; // eax
  const Vector2D *v7; // esi
  CMapClass *v9; // eax
  CMapFace *v10; // eax

  v4 = pView;
  if ( pView != nullptr )
    v6 = &pView->CMapView;
  else
    v6 = nullptr;
  v7 = vPoint;
  if ( CToolOverlay::HandleSelection(this, pView: v6, vPoint) )
  {
    CToolOverlay::PreDrag(this);
    return 1;
  }
  CToolOverlay::OverlaySelection(this, pView: v4, nFlags, vPoint: v7);
  v9 = CMapView3D::NearestObjectAt(
         this: v4,
         vPoint: v7,
         ulFace: (unsigned int *)&pView,
         nFlags: 0,
         pLocalMatrix: nullptr);
  if ( v9 == nullptr )
    return 1;
  v10 = (CMapFace *)__RTDynamicCast(
                      inptr: v9,
                      VfDelta: 0,
                      SrcType: &CMapClass `RTTI Type Descriptor',
                      TargetType: &CMapSolid `RTTI Type Descriptor',
                      isReference: 0);
  if ( v10 == nullptr )
    return 1;
  return CToolOverlay::CreateOverlay(this, pSolid: v10, iFace: (signed int)pView, pView: v4, point: *v7);
}

//------------------------------------------------------------------------------
// Address: 0x105CB870
// Name: _CToolOverlay::OnContextMenu2D_::_2_::_dynamic_atexit_destructor_for__menuOverlay__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CToolOverlay::OnContextMenu2D_::_2_::_dynamic_atexit_destructor_for__menuOverlay__()
{
  menuOverlay.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menuOverlay);
}

//------------------------------------------------------------------------------
// Address: 0x105CB890
// Name: _CToolOverlay::OnContextMenu2D_::_2_::_dynamic_atexit_destructor_for__menu__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CToolOverlay::OnContextMenu2D_::_2_::_dynamic_atexit_destructor_for__menu__()
{
  menu_2.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menu_2);
}

//------------------------------------------------------------------------------
// Address: 0x105CB8B0
// Name: _dynamic_atexit_destructor_for__s_wndToolMessage___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_wndToolMessage___1()
{
  CWnd::~CWnd(this: &s_wndToolMessage_1);
}
