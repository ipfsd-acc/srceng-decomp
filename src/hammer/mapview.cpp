// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapview.cpp
// Functions: 8
// ============================================================

#include "hammer\mapview.h"

//------------------------------------------------------------------------------
// Address: 0x1007C550
// Name: public: CMapView::CMapView(void)
// Source: json
//------------------------------------------------------------------------------
CMapView *__thiscall CMapView::CMapView(CMapView *this)
{
  this->__vftable = (CMapView_vtbl *)&CMapView::`vftable';
  *(_WORD *)&this->m_bActive = 0;
  this->m_eDrawType = VIEW_INVALID;
  this->m_pCamera = nullptr;
  this->m_dwTimeLastRender = 0;
  this->m_nRenderedFrames = 0;
  this->m_pToolManager = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007C590
// Name: public: bool CMapView::IsOrthographic(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapView::IsOrthographic(CMapView *this)
{
  return CCamera::IsOrthographic(this: this->m_pCamera);
}

//------------------------------------------------------------------------------
// Address: 0x1007C5A0
// Name: public: virtual void CMapView::UpdateView(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView::UpdateView(CMapView *this, __int16 nFlags)
{
  this->m_bUpdateView = true;
  if ( (nFlags & 0x800) != 0 )
    this->RenderView(this);
}

//------------------------------------------------------------------------------
// Address: 0x1007C5C0
// Name: public: virtual void CMapView::ActivateView(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView::ActivateView(CMapView *this, bool bActivate)
{
  if ( bActivate != this->m_bActive )
  {
    this->m_bActive = bActivate;
    this->m_bUpdateView = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C5E0
// Name: public: virtual bool CMapView::ShouldRender(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapView::ShouldRender(CMapView *this)
{
  DWORD Time; // edx
  unsigned int m_dwTimeLastRender; // eax

  Time = timeGetTime();
  m_dwTimeLastRender = this->m_dwTimeLastRender;
  if ( m_dwTimeLastRender != 0 && (Time == m_dwTimeLastRender || 1000.0 / (double)(Time - m_dwTimeLastRender) > 100.0)
    || !this->m_bUpdateView )
  {
    return 0;
  }
  ++this->m_nRenderedFrames;
  this->m_dwTimeLastRender = Time;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1007C640
// Name: public: virtual void CMapView::BuildRay(class Vector2D const __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView::BuildRay(CMapView *this, const Vector2D *vView, Vector *vStart, Vector *vEnd)
{
  CCamera::BuildRay(this: this->m_pCamera, vView, vStart, vEnd);
}

//------------------------------------------------------------------------------
// Address: 0x1007C650
// Name: public: virtual class Vector const __near & CMapView::GetViewAxis(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CMapView::GetViewAxis(CMapView *this)
{
  if ( (_S1_3 & 1) == 0 )
    _S1_3 |= 1u;
  CCamera::GetViewForward(this: this->m_pCamera, ViewForward: &vForward);
  return &vForward;
}

//------------------------------------------------------------------------------
// Address: 0x1007C6B0
// Name: public: bool CMapView::SelectAt(class Vector2D const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CMapView::SelectAt@<al>(
        CMapView *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector2D *ptClient,
        bool bMakeFirst,
        bool bFace)
{
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  void *v8; // esp
  CMapDoc *v10; // eax
  CSelection *m_pSelection; // edi
  const CUtlReferenceVector<CMapClass> *List; // ebx
  CHistory *History; // eax
  int v14; // esi
  CMapDoc *v15; // esi
  _DWORD *v17; // ebx
  CMapClass *v18; // eax
  const CUtlReferenceVector<CMapClass> *HitList; // edi
  int v20; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *m_pHead; // ecx
  CMapSolid *v23; // edx
  CMapDoc *v24; // esi
  _BYTE v26[38912]; // [esp+0h] [ebp-981Ch] BYREF
  CMapDoc *v27; // [esp+9800h] [ebp-1Ch]
  __int64 v28; // [esp+9804h] [ebp-18h] BYREF
  CMapSolid *v29; // [esp+980Ch] [ebp-10h]
  _EXCEPTION_REGISTRATION_RECORD *v30; // [esp+9810h] [ebp-Ch]
  void *v31; // [esp+9814h] [ebp-8h]
  int v32; // [esp+9818h] [ebp-4h]
  CMapClass *ParentWnd; // [esp+9824h] [ebp+8h]
  CMapSolid *v34; // [esp+982Ch] [ebp+10h]

  v32 = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v31 = &_ehhandler__CanExecute_CToolHandler_SyncMesh__IAEHXZ;
  v30 = ExceptionList;
  v8 = alloca(38928);
  v10 = (CMapDoc *)((int (__thiscall *)(CMapView *, int, int, int))this->GetMapDoc)(a1: this, a2: a3, a3: a4, a4: a2);
  m_pSelection = v10->m_pSelection;
  v27 = v10;
  List = CSelection::GetList(this: m_pSelection);
  CSelection::ClearHitList(this: m_pSelection);
  History = GetHistory();
  CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Selection", bFromOpposite: 0);
  v14 = this->ObjectsAt(this, a2: ptClient, a3: (HitInfo_s *)v26, a4: 512, a5: 0);
  if ( v14 != 0 )
  {
    ParentWnd = CVGuiWnd::GetParentWnd(this: (CMapClass *)m_pSelection);
    if ( v14 > 0 )
    {
      v17 = v26;
      do
      {
        if ( *v17 != 0 )
        {
          v18 = (CMapClass *)(*(int (__thiscall **)(_DWORD, CMapClass *))(*(_DWORD *)*v17 + 192))(
                               a1: *v17,
                               a2: ParentWnd);
          if ( v18 != nullptr )
            CSelection::AddHit(this: m_pSelection, pObject: v18);
        }
        v17 += 19;
        --v14;
      }
      while ( v14 != 0 );
    }
    if ( bFace )
    {
      HitList = CSelection::GetHitList(this: m_pSelection);
      v20 = 0;
      if ( HitList->m_Size > 0 )
      {
        while ( 1 )
        {
          m_pObject = HitList->m_Memory.m_pMemory[v20 >> ((unsigned __int64)*((int *)&HitList->m_Memory + 2) >> 27)][v20 & ((32 * *((_DWORD *)&HitList->m_Memory + 2)) >> 5)].m_pObject;
          if ( m_pObject != nullptr )
          {
            v29 = (CMapSolid *)HitList->m_Memory.m_pMemory[v20 >> ((unsigned __int64)*((int *)&HitList->m_Memory + 2) >> 27)][v20 & ((32 * *((_DWORD *)&HitList->m_Memory + 2)) >> 5)].m_pObject;
            LODWORD(v28) = m_pObject->m_References.m_pHead;
            m_pHead = m_pObject->m_References.m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = (CUtlReference<CMapClass> *)&v28;
            HIDWORD(v28) = 0;
            m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&v28;
          }
          v23 = v29;
          v34 = v29;
          v32 = -1;
          if ( v29 != nullptr )
          {
            if ( HIDWORD(v28) != 0 )
            {
              *(_DWORD *)HIDWORD(v28) = v28;
              if ( (_DWORD)v28 != 0 )
                *(_DWORD *)(v28 + 4) = HIDWORD(v28);
            }
            else if ( (__int64 *)v29->m_References.m_pHead == &v28 )
            {
              v29->m_References.m_pHead = (CUtlReference<CMapClass> *)v28;
              if ( (_DWORD)v28 != 0 )
                *(_DWORD *)(v28 + 4) = 0;
            }
            v28 = 0;
            v29 = nullptr;
          }
          if ( v23->IsMapClass(this: v23, a2: CMapSolid::__Type) != 0 )
            break;
          if ( ++v20 >= HitList->m_Size )
            return 1;
        }
        CMapDoc::SelectFace(
          this: v27,
          pSolid: (unsigned int)v34 | 0xFFFFFFFF00000000uLL,
          cmd: (bMakeFirst ? 0x10 : 0) | 2);
      }
    }
    else
    {
      if ( bMakeFirst )
      {
        v24 = v27;
        CMapDoc::SelectFace(this: v27, pSolid: 0, cmd: 1040);
        CMapDoc::SelectObject(this: v24, pObj: nullptr, cmd: 1040);
      }
      CSelection::SetCurrentHit(this: m_pSelection, iIndex: 0, bCascading: false);
    }
    return 1;
  }
  else
  {
    if ( bMakeFirst )
    {
      v15 = v27;
      CMapDoc::SelectFace(this: v27, pSolid: 0, cmd: 1040);
      CMapDoc::SelectObject(this: v15, pObj: nullptr, cmd: 1040);
    }
    return 0;
  }
}
