// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/toolswepthull.cpp
// Functions: 11
// ============================================================

#include "hammer\toolswepthull.h"

//------------------------------------------------------------------------------
// Address: 0x1016BE50
// Name: public: CToolSweptPlayerHull::CToolSweptPlayerHull(void)
// Source: json
//------------------------------------------------------------------------------
CToolSweptPlayerHull *__thiscall CToolSweptPlayerHull::CToolSweptPlayerHull(CToolSweptPlayerHull *this)
{
  this->__vftable = (CToolSweptPlayerHull_vtbl *)&CBaseTool::`vftable';
  *(_WORD *)&this->m_bActiveTool = 256;
  this->m_pDocument = nullptr;
  this->__vftable = (CToolSweptPlayerHull_vtbl *)&CToolSweptPlayerHull::`vftable';
  this->m_pSweptHull = nullptr;
  this->m_nPointIndex = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016BF10
// Name: public: virtual bool CToolSweptPlayerHull::OnMouseMove2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolSweptPlayerHull::OnMouseMove2D(
        CToolSweptPlayerHull *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CMapDoc *v6; // edi
  int m_nPointIndex; // eax
  int axVert; // ebx
  char string[36]; // [esp+20h] [ebp-A8h] BYREF
  char szBuf[128]; // [esp+44h] [ebp-84h] BYREF

  CMapView2DBase::ToolScrollToPoint(this: pView, ptClient: vPoint);
  pView->ClientToWorld(this: &pView->CMapView, a2: (Vector *)&szBuf[96], a3: vPoint);
  v6 = pView->GetMapDoc(this: &pView->CMapView);
  CMapDoc::Snap(this: v6, pt: (Vector *)&szBuf[96], nFlags: 0);
  CMapSweptPlayerHull::GetEndPoint(
    this: this->m_pSweptHull,
    vecPos: (Vector *)&szBuf[12 * this->m_nPointIndex + 108],
    nPointIndex: this->m_nPointIndex);
  m_nPointIndex = this->m_nPointIndex;
  axVert = pView->axVert;
  *(float *)&szBuf[12 * m_nPointIndex + 108 + 4 * pView->axHorz] = *(float *)&szBuf[4 * pView->axHorz + 96];
  *(float *)&szBuf[12 * m_nPointIndex + 108 + 4 * axVert] = *(float *)&szBuf[4 * axVert + 96];
  CMapSweptPlayerHull::UpdateEndPoint(
    this: this->m_pSweptHull,
    vecPos: (Vector *)&szBuf[12 * m_nPointIndex + 108],
    nPointIndex: m_nPointIndex);
  CMapSweptPlayerHull::GetEndPoint(
    this: this->m_pSweptHull,
    vecPos: (Vector *)&szBuf[12 * (this->m_nPointIndex == 0) + 108],
    nPointIndex: this->m_nPointIndex == 0);
  sprintf(
    string: &string[4],
    format: " (%.0f %.0f %0.f) ",
    *(float *)&szBuf[12 * this->m_nPointIndex + 108],
    *(float *)&szBuf[12 * this->m_nPointIndex + 112],
    *(float *)&szBuf[12 * this->m_nPointIndex + 116]);
  SetStatusText(nIndex: 2, pszText: &string[4]);
  CMapDoc::UpdateAllViews(this: v6, nFlags: 16, ub: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016C040
// Name: public: virtual void CToolSweptPlayerHull::RenderTool2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolSweptPlayerHull::RenderTool2D(CToolSweptPlayerHull *this, CRender2D *pRender)
{
  SelectionState_t v3; // edi

  v3 = CMapSweptPlayerHull::SetSelectionState(
         this: this->m_pSweptHull,
         eSelectionState: SELECT_MODIFY,
         nHandle: this->m_nPointIndex);
  this->m_pSweptHull->Render2D(this: this->m_pSweptHull, a2: pRender);
  this->m_pSweptHull->SetSelectionState(this: this->m_pSweptHull, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1016C080
// Name: public: virtual bool CToolSweptPlayerHull::OnLMouseDown2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolSweptPlayerHull::OnLMouseDown2D(
        CToolSweptPlayerHull *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CToolManager *v5; // eax
  HWND v6; // eax
  CMapDoc *v7; // eax
  CHistory *History; // eax
  CHistory *v9; // eax
  const CUtlReferenceVector<CMapClass> *List; // [esp-Ch] [ebp-14h]
  CMapSweptPlayerHull *m_pSweptHull; // [esp-4h] [ebp-Ch]

  v5 = ToolManager();
  CToolManager::PushTool(this: v5, eToolID: TOOL_SWEPT_HULL);
  v6 = SetCapture(hWnd: pView->m_hWnd);
  CWnd::FromHandle(hWnd: v6);
  v7 = pView->GetMapDoc(this: &pView->CMapView);
  List = CSelection::GetList(this: v7->m_pSelection);
  History = GetHistory();
  CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Modify Swept Hull", bFromOpposite: 0);
  m_pSweptHull = this->m_pSweptHull;
  v9 = GetHistory();
  CHistory::Keep(this: v9, pObject: m_pSweptHull);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016C0F0
// Name: WTInfoA(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall WTInfoA(int a1, int a2, int a3)
{
  if ( dword_107326D0 != nullptr )
    return dword_107326D0(a1, a2, a3);
  __Wintabdynlink(a1: &off_107326C8);
  if ( dword_107326D0 != nullptr )
    return dword_107326D0(a1, a2, a3);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016C130
// Name: WTQueueSizeSet(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall WTQueueSizeSet(int a1, int a2)
{
  if ( dword_107326E8 != nullptr )
    return dword_107326E8(a1, a2);
  __Wintabdynlink(a1: &off_107326E0);
  if ( dword_107326E8 != nullptr )
    return dword_107326E8(a1, a2);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016C170
// Name: WTOpenA(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall WTOpenA(int a1, int a2, int a3)
{
  if ( dword_10732708 != nullptr )
    return dword_10732708(a1, a2, a3);
  __Wintabdynlink(a1: &off_10732700);
  if ( dword_10732708 != nullptr )
    return dword_10732708(a1, a2, a3);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016C1B0
// Name: WTPacketsGet(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall WTPacketsGet(int a1, int a2, int a3)
{
  if ( dword_10732720 != nullptr )
    return dword_10732720(a1, a2, a3);
  __Wintabdynlink(a1: &off_10732718);
  if ( dword_10732720 != nullptr )
    return dword_10732720(a1, a2, a3);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016C1F0
// Name: __Wintabdynlink(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
FARPROC __stdcall __Wintabdynlink(int a1)
{
  UINT v1; // esi
  FARPROC result; // eax
  int v3; // esi

  if ( hLibModule != nullptr
    || (v1 = SetErrorMode(uMode: 0x8001u),
        hLibModule = LoadLibraryA(lpLibFileName: LibFileName),
        result = (FARPROC)SetErrorMode(uMode: v1),
        hLibModule != nullptr) )
  {
    v3 = a1;
    if ( *(_DWORD *)(a1 + 4) != 0 )
      result = GetProcAddress(hModule: hLibModule, lpProcName: *(LPCSTR *)(a1 + 4));
    else
      result = GetProcAddress(hModule: hLibModule, lpProcName: *(LPCSTR *)a1);
    *(_DWORD *)(a1 + 8) = result;
  }
  else
  {
    v3 = a1;
  }
  if ( *(_DWORD *)(v3 + 8) != 0 )
  {
    result = (FARPROC)dword_1073273C;
    dword_1073273C = v3;
    *(_DWORD *)(v3 + 12) = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016C280
// Name: __Wintabunlink()
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall __Wintabunlink()
{
  int result; // eax

  if ( hLibModule != nullptr )
  {
    result = FreeLibrary(hLibModule: hLibModule);
    hLibModule = nullptr;
    if ( dword_1073273C != 0 )
    {
      do
      {
        *(_DWORD *)(dword_1073273C + 8) = 0;
        result = *(_DWORD *)(dword_1073273C + 12);
        *(_DWORD *)(dword_1073273C + 12) = 0;
        dword_1073273C = result;
      }
      while ( result != 0 );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016C2D0
// Name: _UnlinkWintab()
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall _UnlinkWintab()
{
  return __Wintabunlink();
}
