// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/childfrm.cpp
// Functions: 124
// ============================================================

#include "hammer\childfrm.h"

//------------------------------------------------------------------------------
// Address: 0x1000B120
// Name: public: void ATL::CStringData::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ATL::CStringData::Release(ATL::CStringData *this)
{
  if ( _InterlockedDecrement(&this->nRefs) <= 0 )
    this->pStringMgr->Free(this: this->pStringMgr, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1000B140
// Name: public: static void __near * CObject::operator new(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__stdcall CObject::operator new(unsigned int nSize)
{
  return operator new(nSize);
}

//------------------------------------------------------------------------------
// Address: 0x1000B160
// Name: public: virtual struct CRuntimeClass __near * CChildFrame::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CChildFrame::GetRuntimeClass(CChildFrame *this)
{
  return &CChildFrame::classCChildFrame;
}

//------------------------------------------------------------------------------
// Address: 0x1000B170
// Name: void SetDefaultChildType(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetDefaultChildType(int b4Views)
{
  g_b4Views = b4Views;
}

//------------------------------------------------------------------------------
// Address: 0x1000B180
// Name: public: virtual int CChildFrame::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChildFrame::PreCreateWindow(CChildFrame *this, tagCREATESTRUCTA *cs)
{
  return CMDIChildWnd::PreCreateWindow(this, cs);
}

//------------------------------------------------------------------------------
// Address: 0x1000B190
// Name: public: class CView __near * CChildFrame::GetActiveView(void)
// Source: json
//------------------------------------------------------------------------------
CView *__thiscall CChildFrame::GetActiveView(CChildFrame *this)
{
  int iRow; // [esp+4h] [ebp-8h] BYREF
  int iCol; // [esp+8h] [ebp-4h] BYREF

  if ( this->bUsingSplitter == 0 )
    return CFrameWnd::GetActiveView(this);
  this->m_wndSplitter->GetActivePane(this: this->m_wndSplitter, a2: &iRow, a3: &iCol);
  return (CView *)CSplitterWnd::GetPane(this: this->m_wndSplitter, row: iRow, col: iCol);
}

//------------------------------------------------------------------------------
// Address: 0x1000B1E0
// Name: protected: void CChildFrame::OnSize(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::OnSize(CChildFrame *this, unsigned int nType, int cx, int cy)
{
  CMDIChildWnd::OnSize(this, nType, cx, cy);
}

//------------------------------------------------------------------------------
// Address: 0x1000B1F0
// Name: protected: void CChildFrame::OnSetFocus(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::OnSetFocus(CChildFrame *this, CWnd *pOldWnd)
{
  CDocument *v3; // eax
  CMapDoc *v4; // eax

  CFrameWnd::OnSetFocus(this, pOldWnd);
  v3 = this->GetActiveDocument(this);
  v4 = (CMapDoc *)__RTDynamicCast(
                    inptr: v3,
                    VfDelta: 0,
                    SrcType: &CDocument `RTTI Type Descriptor',
                    TargetType: &CMapDoc `RTTI Type Descriptor',
                    isReference: 0);
  if ( v4 != nullptr )
    CMapDoc::SetActiveMapDoc(pDoc: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1000B240
// Name: public: struct HWND__ __near * CWnd::GetSafeHwnd(void)const
// Source: json
//------------------------------------------------------------------------------
HWND__ *__thiscall CWnd::GetSafeHwnd(CWnd *this)
{
  if ( this != nullptr )
    return this->m_hWnd;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000B250
// Name: public: class CWnd __near * CWnd::SetParent(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CWnd *__thiscall CWnd::SetParent(CWnd *this, CWnd *pWndNewParent)
{
  HWND__ *m_hWnd; // eax
  HWND v3; // eax

  m_hWnd = (HWND__ *)pWndNewParent;
  if ( pWndNewParent != nullptr )
    m_hWnd = pWndNewParent->m_hWnd;
  v3 = SetParent(hWndChild: this->m_hWnd, hWndNewParent: m_hWnd);
  return CWnd::FromHandle(hWnd: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1000B280
// Name: public: virtual void CWnd::BeginModalState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::BeginModalState(CWnd *this)
{
  EnableWindow(hWnd: this->m_hWnd, bEnable: false);
}

//------------------------------------------------------------------------------
// Address: 0x1000B290
// Name: public: virtual void CWnd::EndModalState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::EndModalState(CWnd *this)
{
  EnableWindow(hWnd: this->m_hWnd, bEnable: true);
}

//------------------------------------------------------------------------------
// Address: 0x1000B2A0
// Name: public: ATL::CSimpleStringT<char,0>::operator char const __near *(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall ATL::CSimpleStringT<char,0>::operator char const *(ATL::CSimpleStringT<char,0> *this)
{
  return this->m_pszData;
}

//------------------------------------------------------------------------------
// Address: 0x1000B300
// Name: public: CChildFrame::CChildFrame(void)
// Source: json
//------------------------------------------------------------------------------
CChildFrame *__thiscall CChildFrame::CChildFrame(CChildFrame *this)
{
  int v2; // eax

  CMDIChildWnd::CMDIChildWnd(this);
  this->bAutosize4 = 1;
  this->bFirstPaint = 1;
  v2 = 0;
  this->__vftable = (CChildFrame_vtbl *)&CChildFrame::`vftable';
  this->m_bReady = 0;
  if ( g_b4Views != 0 )
    LOBYTE(v2) = Options.general.bIndependentwin == 0;
  this->bUsingSplitter = v2;
  this->m_wndSplitter = nullptr;
  this->m_bNeedsCentered = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000B410
// Name: public: void CChildFrame::SetSplitterMode(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CChildFrame::SetSplitterMode(CChildFrame *this@<ecx>, int a2@<ebx>, int a3@<edi>, int bSplitter)
{
  CView *ActiveView; // ebx
  CDocument *m_pDocument; // eax
  int m_bAutoDelete; // ecx
  HWND v8; // eax
  CMySplitterWnd *m_wndSplitter; // ecx
  int v10; // eax
  CDocument *v11; // ecx
  CView *v12; // eax
  int v13; // ebx
  CDocument *v14; // ecx
  CView_vtbl *v15; // edx
  CView *v16; // ecx
  int (__thiscall *DestroyWindow)(CWnd *); // eax
  CDocument *v18; // eax
  CMySplitterWnd *v19; // ebx
  CMySplitterWnd *v20; // ecx
  int v21; // ebx
  int v22; // edi
  CMySplitterWnd *v23; // ecx
  CMySplitterWnd *v24; // ecx
  HWND m_hWnd; // [esp-18h] [ebp-54h]
  HWND__ *v26; // [esp-10h] [ebp-4Ch]
  HWND__ *v27; // [esp-10h] [ebp-4Ch]
  CCreateContext context; // [esp+4h] [ebp-38h] BYREF
  CRect r; // [esp+18h] [ebp-24h] BYREF
  CDocument *pDoc; // [esp+28h] [ebp-14h]
  int bAutoDelete; // [esp+2Ch] [ebp-10h]
  int v33; // [esp+38h] [ebp-4h]

  if ( bSplitter != this->bUsingSplitter )
  {
    if ( bSplitter == 0 )
    {
      ActiveView = CChildFrame::GetActiveView(this);
      m_pDocument = ActiveView->m_pDocument;
      m_bAutoDelete = m_pDocument->m_bAutoDelete;
      m_pDocument->m_bAutoDelete = 0;
      m_hWnd = ActiveView->m_hWnd;
      pDoc = m_pDocument;
      bAutoDelete = m_bAutoDelete;
      SendMessageA(hWnd: m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
      SendMessageA(hWnd: this->m_wndSplitter->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
      v8 = SetParent(hWndChild: ActiveView->m_hWnd, hWndNewParent: this->m_hWnd);
      CWnd::FromHandle(hWnd: v8);
      this->m_wndSplitter->DestroyWindow(this: this->m_wndSplitter);
      m_wndSplitter = this->m_wndSplitter;
      if ( m_wndSplitter != nullptr )
        ((void (__thiscall *)(CMySplitterWnd *, int))m_wndSplitter->dtr_CObject)(a1: m_wndSplitter, a2: 1);
      v10 = bAutoDelete;
      v11 = pDoc;
      this->m_wndSplitter = nullptr;
      v11->m_bAutoDelete = v10;
      v26 = this->m_hWnd;
      memset(&r, 0, sizeof(r));
      GetClientRect(hWnd: v26, lpRect: &r);
      SendMessageA(hWnd: ActiveView->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
      CWnd::MoveWindow(this: ActiveView, x: 0, y: 0, nWidth: r.right, nHeight: r.bottom, bRepaint: 1);
      goto LABEL_11;
    }
    v12 = CChildFrame::GetActiveView(this);
    v13 = (int)v12->m_pDocument;
    v14 = *(CDocument **)(v13 + 156);
    *(_DWORD *)(v13 + 156) = 0;
    v15 = v12->__vftable;
    pDoc = v14;
    v16 = v12;
    DestroyWindow = v15->DestroyWindow;
    bAutoDelete = v13;
    ((void (__thiscall *)(CView *, int, int))DestroyWindow)(a1: v16, a2: a3, a3: a2);
    *(_DWORD *)(v13 + 156) = pDoc;
    v18 = (CDocument *)operator new(nSize: 0x110u);
    v19 = (CMySplitterWnd *)v18;
    pDoc = v18;
    v33 = 0;
    if ( v18 != nullptr )
    {
      CSplitterWnd::CSplitterWnd(this: (CSplitterWnd *)v18);
      v19->__vftable = (CMySplitterWnd_vtbl *)&CMySplitterWnd::`vftable';
      v19->pMaxPrev = nullptr;
      LOBYTE(v33) = 0;
      v20 = v19;
    }
    else
    {
      v20 = nullptr;
    }
    v33 = -1;
    this->m_wndSplitter = v20;
    if ( ((int (__thiscall *)(CMySplitterWnd *, CChildFrame *, int, int))v20->CreateStatic)(
           a1: v20,
           a2: this,
           a3: 2,
           a4: 2) != 0 )
    {
      v27 = this->m_hWnd;
      memset(&r, 0, sizeof(r));
      GetClientRect(hWnd: v27, lpRect: &r);
      context.m_pCurrentFrame = nullptr;
      context.m_pNewDocTemplate = nullptr;
      context.m_pLastView = nullptr;
      v21 = (r.bottom - r.top) / 2 - 3;
      context.m_pNewViewClass = nullptr;
      v22 = (r.right - r.left) / 2 - 3;
      context.m_pCurrentDoc = (CDocument *)bAutoDelete;
      v23 = this->m_wndSplitter;
      context.m_pCurrentFrame = this;
      context.m_pNewViewClass = &CMapView2D::classCMapView2D;
      ((void (__thiscall *)(CMySplitterWnd *, _DWORD, int, CRuntimeClass *, int, int, CCreateContext *))v23->CreateView)(
        a1: v23,
        a2: 0,
        a3: 1,
        a4: &CMapView2D::classCMapView2D,
        a5: v22,
        a6: v21,
        a7: &context);
      ((void (__thiscall *)(CMySplitterWnd *, int, _DWORD, CRuntimeClass *, int, int, CCreateContext *))this->m_wndSplitter->CreateView)(
        a1: this->m_wndSplitter,
        a2: 1,
        a3: 0,
        a4: &CMapView2D::classCMapView2D,
        a5: v22,
        a6: v21,
        a7: &context);
      ((void (__thiscall *)(CMySplitterWnd *, int, int, CRuntimeClass *, int, int, CCreateContext *))this->m_wndSplitter->CreateView)(
        a1: this->m_wndSplitter,
        a2: 1,
        a3: 1,
        a4: &CMapView2D::classCMapView2D,
        a5: v22,
        a6: v21,
        a7: &context);
      v24 = this->m_wndSplitter;
      context.m_pNewViewClass = &CMapView3D::classCMapView3D;
      ((void (__thiscall *)(CMySplitterWnd *, _DWORD, _DWORD, CRuntimeClass *, int, int, CCreateContext *))v24->CreateView)(
        a1: v24,
        a2: 0,
        a3: 0,
        a4: &CMapView3D::classCMapView3D,
        a5: v22,
        a6: v21,
        a7: &context);
LABEL_11:
      this->bUsingSplitter = bSplitter;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B6B0
// Name: public: class CView __near * CChildFrame::ReplaceView(struct CRuntimeClass __near *)
// Source: json
//------------------------------------------------------------------------------
CView *__thiscall CChildFrame::ReplaceView(CChildFrame *this, CRuntimeClass *pViewClass)
{
  CView *Pane; // eax
  CWnd *Object; // edi
  CMapDoc *v6; // eax
  int m_bAutoDelete; // ecx
  CMapDoc *v8; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-60h]
  CCreateContext context; // [esp+Ch] [ebp-4Ch] BYREF
  CRect r; // [esp+20h] [ebp-38h] BYREF
  CRect rect; // [esp+30h] [ebp-28h] BYREF
  CMapDoc *pDoc; // [esp+40h] [ebp-18h]
  int bAutoDelete; // [esp+44h] [ebp-14h]
  int row; // [esp+48h] [ebp-10h] BYREF
  int col; // [esp+4Ch] [ebp-Ch] BYREF
  int iRow; // [esp+50h] [ebp-8h] BYREF
  int iCol; // [esp+54h] [ebp-4h] BYREF

  if ( this->bUsingSplitter != 0 )
  {
    this->m_wndSplitter->GetActivePane(this: this->m_wndSplitter, a2: &row, a3: &col);
    Pane = (CView *)CSplitterWnd::GetPane(this: this->m_wndSplitter, row, col);
  }
  else
  {
    Pane = CFrameWnd::GetActiveView(this);
  }
  Object = Pane;
  if ( Pane == nullptr )
    return nullptr;
  if ( CObject::IsKindOf(this: Pane, pClass: pViewClass) != 1 )
  {
    v6 = (CMapDoc *)Object[1].__vftable;
    m_bAutoDelete = v6->m_bAutoDelete;
    v6->m_bAutoDelete = 0;
    pDoc = v6;
    bAutoDelete = m_bAutoDelete;
    iRow = 0;
    iCol = 0;
    memset(&rect, 0, sizeof(rect));
    if ( this->bUsingSplitter != 0 )
    {
      GetClientRect(hWnd: Object->m_hWnd, lpRect: &rect);
      this->m_wndSplitter->GetActivePane(this: this->m_wndSplitter, a2: &iRow, a3: &iCol);
      this->m_wndSplitter->DeleteView(this: this->m_wndSplitter, a2: iRow, a3: iCol);
    }
    else
    {
      Object->DestroyWindow(this: Object);
    }
    v8 = pDoc;
    pDoc->m_bAutoDelete = bAutoDelete;
    context.m_pNewViewClass = pViewClass;
    context.m_pCurrentDoc = v8;
    context.m_pNewDocTemplate = nullptr;
    context.m_pLastView = nullptr;
    context.m_pCurrentFrame = this;
    if ( this->bUsingSplitter != 0 )
    {
      if ( ((int (__thiscall *)(CMySplitterWnd *, int, int, CRuntimeClass *, int, int, CCreateContext *))this->m_wndSplitter->CreateView)(
             a1: this->m_wndSplitter,
             a2: iRow,
             a3: iCol,
             a4: pViewClass,
             a5: rect.right - rect.left,
             a6: rect.bottom - rect.top,
             a7: &context) == 0 )
        return nullptr;
      Object = CSplitterWnd::GetPane(this: this->m_wndSplitter, row: iRow, col: iCol);
    }
    else
    {
      Object = (CWnd *)CRuntimeClass::CreateObject(this: pViewClass);
      if ( Object == nullptr )
        return nullptr;
      m_hWnd = this->m_hWnd;
      memset(&r, 0, sizeof(r));
      GetClientRect(hWnd: m_hWnd, lpRect: &r);
      if ( Object->Create(
             this: Object,
             a2: nullptr,
             a3: nullptr,
             a4: 1350565888u,
             a5: &r,
             a6: this,
             a7: 59648u,
             a8: &context) == 0 )
        return nullptr;
    }
    if ( Object != nullptr )
    {
      SendMessageA(hWnd: Object->m_hWnd, Msg: 0x364u, wParam: 0, lParam: 0);
      if ( this->bUsingSplitter != 0 )
        this->m_wndSplitter->RecalcLayout(this: this->m_wndSplitter);
      return (CView *)Object;
    }
    return nullptr;
  }
  return (CView *)Object;
}

//------------------------------------------------------------------------------
// Address: 0x1000B8B0
// Name: public: void CChildFrame::SaveOptions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::SaveOptions(CChildFrame *this)
{
  bool v1; // zf
  int v2; // ebx
  int v3; // esi
  CWnd *Pane; // eax
  void *v5; // edi
  CWinApp *m_pCurrentWinApp; // ebx
  CWinApp_vtbl *v7; // esi
  int v8; // eax
  CWnd *v9; // esi
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v11; // eax
  AFX_MODULE_STATE *v12; // eax
  char szPlacement[100]; // [esp+0h] [ebp-C8h] BYREF
  char szKey[32]; // [esp+64h] [ebp-64h] BYREF
  tagWINDOWPLACEMENT wp; // [esp+84h] [ebp-44h] BYREF
  int nMin; // [esp+B0h] [ebp-18h] BYREF
  int nHeight; // [esp+B4h] [ebp-14h] BYREF
  int nWidth; // [esp+B8h] [ebp-10h] BYREF
  CWnd *v19; // [esp+BCh] [ebp-Ch]
  int nCol; // [esp+C0h] [ebp-8h]
  int nRow; // [esp+C4h] [ebp-4h]

  v1 = this->bUsingSplitter == 0;
  v19 = this;
  if ( !v1 )
  {
    v2 = 0;
    nRow = 0;
    do
    {
      v3 = 0;
      nCol = 0;
      do
      {
        Pane = CSplitterWnd::GetPane(this: (CSplitterWnd *)v19[2].m_ulGestureArg, row: v2, col: v3);
        v5 = __RTDynamicCast(
               inptr: Pane,
               VfDelta: 0,
               SrcType: &CWnd `RTTI Type Descriptor',
               TargetType: &CMapView `RTTI Type Descriptor',
               isReference: 0);
        if ( v5 != nullptr )
        {
          sprintf(string: szKey, format: "DrawType%d,%d", v2, v3);
          m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
          v7 = m_pCurrentWinApp->__vftable;
          v8 = (*(int (__thiscall **)(void *))(*(_DWORD *)v5 + 8))(a1: v5);
          v7->WriteProfileInt(this: m_pCurrentWinApp, a2: "Splitter", a3: szKey, a4: v8);
          v2 = nRow;
          v3 = nCol;
        }
        nCol = ++v3;
      }
      while ( v3 < 2 );
      nRow = ++v2;
    }
    while ( v2 < 2 );
    v9 = v19;
    CSplitterWnd::GetColumnInfo(this: (CSplitterWnd *)v19[2].m_ulGestureArg, col: 0, cxCur: &nWidth, cxMin: &nMin);
    CSplitterWnd::GetRowInfo(this: (CSplitterWnd *)v9[2].m_ulGestureArg, row: 0, cyCur: &nHeight, cyMin: &nMin);
    ModuleState = AfxGetModuleState();
    ModuleState->m_pCurrentWinApp->WriteProfileInt(
      this: ModuleState->m_pCurrentWinApp,
      a2: "Splitter",
      a3: "SplitterWidth",
      a4: nWidth);
    v11 = AfxGetModuleState();
    v11->m_pCurrentWinApp->WriteProfileInt(
      this: v11->m_pCurrentWinApp,
      a2: "Splitter",
      a3: "SplitterHeight",
      a4: nHeight);
    wp.length = 44;
    CWnd::GetWindowPlacement(this: v9, lpwndpl: &wp);
    sprintf(
      string: szPlacement,
      format: "(%d %d) (%d %d) (%d %d %d %d) %d",
      wp.ptMaxPosition.x,
      wp.ptMaxPosition.y,
      wp.ptMinPosition.x,
      wp.ptMinPosition.y,
      wp.rcNormalPosition.bottom,
      wp.rcNormalPosition.left,
      wp.rcNormalPosition.right,
      wp.rcNormalPosition.top,
      wp.showCmd);
    v12 = AfxGetModuleState();
    v12->m_pCurrentWinApp->WriteProfileStringA(
      this: v12->m_pCurrentWinApp,
      a2: "Splitter",
      a3: "WindowPlacement",
      a4: szPlacement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BA50
// Name: public: void CChildFrame::SetViewType(enum DrawType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::SetViewType(CChildFrame *this, DrawType_t eViewType)
{
  CView *v3; // eax
  CView *v4; // esi
  void *v5; // eax
  CView *v6; // eax

  if ( eViewType >= VIEW2D_XY )
  {
    if ( eViewType <= VIEW2D_XZ )
    {
      v3 = CChildFrame::ReplaceView(this, pViewClass: &CMapView2D::classCMapView2D);
      goto LABEL_7;
    }
    if ( eViewType == VIEW_LOGICAL )
    {
      v3 = CChildFrame::ReplaceView(this, pViewClass: &CMapViewLogical::classCMapViewLogical);
      goto LABEL_7;
    }
  }
  v3 = CChildFrame::ReplaceView(this, pViewClass: &CMapView3D::classCMapView3D);
LABEL_7:
  if ( v3 != nullptr )
  {
    v4 = v3 + 1;
    if ( v3 != (CView *)-124 )
    {
      v5 = (void *)v4->GetTypeInfoCount(this: v4);
      v6 = (CView *)__RTDynamicCast(
                      inptr: v5,
                      VfDelta: 0,
                      SrcType: &CWnd `RTTI Type Descriptor',
                      TargetType: &CView `RTTI Type Descriptor',
                      isReference: 0);
      CFrameWnd::SetActiveView(this, pViewNew: v6, bNotify: 1);
      ((void (__thiscall *)(CView *, DrawType_t))v4->dtr_CObject)(a1: v4, a2: eViewType);
      v4->IsInvokeAllowed(this: v4, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BAE0
// Name: protected: void CChildFrame::OnView2dxy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::OnView2dxy(CChildFrame *this)
{
  CView *v2; // eax
  CView *v3; // esi
  void *v4; // eax
  CView *v5; // eax

  v2 = CChildFrame::ReplaceView(this, pViewClass: &CMapView2D::classCMapView2D);
  if ( v2 != nullptr )
  {
    v3 = v2 + 1;
    if ( v2 != (CView *)-124 )
    {
      v4 = (void *)v3->GetTypeInfoCount(this: v3);
      v5 = (CView *)__RTDynamicCast(
                      inptr: v4,
                      VfDelta: 0,
                      SrcType: &CWnd `RTTI Type Descriptor',
                      TargetType: &CView `RTTI Type Descriptor',
                      isReference: 0);
      CFrameWnd::SetActiveView(this, pViewNew: v5, bNotify: 1);
      ((void (__thiscall *)(CView *, _DWORD))v3->dtr_CObject)(a1: v3, a2: 0);
      v3->IsInvokeAllowed(this: v3, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BB40
// Name: protected: void CChildFrame::OnView2dyz(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::OnView2dyz(CChildFrame *this)
{
  CView *v2; // eax
  CView *v3; // esi
  void *v4; // eax
  CView *v5; // eax

  v2 = CChildFrame::ReplaceView(this, pViewClass: &CMapView2D::classCMapView2D);
  if ( v2 != nullptr )
  {
    v3 = v2 + 1;
    if ( v2 != (CView *)-124 )
    {
      v4 = (void *)v3->GetTypeInfoCount(this: v3);
      v5 = (CView *)__RTDynamicCast(
                      inptr: v4,
                      VfDelta: 0,
                      SrcType: &CWnd `RTTI Type Descriptor',
                      TargetType: &CView `RTTI Type Descriptor',
                      isReference: 0);
      CFrameWnd::SetActiveView(this, pViewNew: v5, bNotify: 1);
      ((void (__thiscall *)(CView *, int))v3->dtr_CObject)(a1: v3, a2: 1);
      v3->IsInvokeAllowed(this: v3, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BBA0
// Name: protected: void CChildFrame::OnView2dxz(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::OnView2dxz(CChildFrame *this)
{
  CView *v2; // eax
  CView *v3; // esi
  void *v4; // eax
  CView *v5; // eax

  v2 = CChildFrame::ReplaceView(this, pViewClass: &CMapView2D::classCMapView2D);
  if ( v2 != nullptr )
  {
    v3 = v2 + 1;
    if ( v2 != (CView *)-124 )
    {
      v4 = (void *)v3->GetTypeInfoCount(this: v3);
      v5 = (CView *)__RTDynamicCast(
                      inptr: v4,
                      VfDelta: 0,
                      SrcType: &CWnd `RTTI Type Descriptor',
                      TargetType: &CView `RTTI Type Descriptor',
                      isReference: 0);
      CFrameWnd::SetActiveView(this, pViewNew: v5, bNotify: 1);
      ((void (__thiscall *)(CView *, int))v3->dtr_CObject)(a1: v3, a2: 2);
      v3->IsInvokeAllowed(this: v3, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BC00
// Name: protected: void CChildFrame::OnViewLogical(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::OnViewLogical(CChildFrame *this)
{
  CView *v2; // eax
  CView *v3; // esi
  void *v4; // eax
  CView *v5; // eax

  v2 = CChildFrame::ReplaceView(this, pViewClass: &CMapViewLogical::classCMapViewLogical);
  if ( v2 != nullptr )
  {
    v3 = v2 + 1;
    if ( v2 != (CView *)-124 )
    {
      v4 = (void *)v3->GetTypeInfoCount(this: v3);
      v5 = (CView *)__RTDynamicCast(
                      inptr: v4,
                      VfDelta: 0,
                      SrcType: &CWnd `RTTI Type Descriptor',
                      TargetType: &CView `RTTI Type Descriptor',
                      isReference: 0);
      CFrameWnd::SetActiveView(this, pViewNew: v5, bNotify: 1);
      ((void (__thiscall *)(CView *, int))v3->dtr_CObject)(a1: v3, a2: 10);
      v3->IsInvokeAllowed(this: v3, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BC60
// Name: protected: void CChildFrame::OnView3dWireframe(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::OnView3dWireframe(CChildFrame *this)
{
  CView *v2; // eax
  CView *v3; // esi
  void *v4; // eax
  CView *v5; // eax

  v2 = CChildFrame::ReplaceView(this, pViewClass: &CMapView3D::classCMapView3D);
  if ( v2 != nullptr )
  {
    v3 = v2 + 1;
    if ( v2 != (CView *)-124 )
    {
      v4 = (void *)v3->GetTypeInfoCount(this: v3);
      v5 = (CView *)__RTDynamicCast(
                      inptr: v4,
                      VfDelta: 0,
                      SrcType: &CWnd `RTTI Type Descriptor',
                      TargetType: &CView `RTTI Type Descriptor',
                      isReference: 0);
      CFrameWnd::SetActiveView(this, pViewNew: v5, bNotify: 1);
      ((void (__thiscall *)(CView *, int))v3->dtr_CObject)(a1: v3, a2: 3);
      v3->IsInvokeAllowed(this: v3, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BCC0
// Name: protected: void CChildFrame::OnView3dPolygon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::OnView3dPolygon(CChildFrame *this)
{
  CView *v2; // eax
  CView *v3; // esi
  void *v4; // eax
  CView *v5; // eax

  v2 = CChildFrame::ReplaceView(this, pViewClass: &CMapView3D::classCMapView3D);
  if ( v2 != nullptr )
  {
    v3 = v2 + 1;
    if ( v2 != (CView *)-124 )
    {
      v4 = (void *)v3->GetTypeInfoCount(this: v3);
      v5 = (CView *)__RTDynamicCast(
                      inptr: v4,
                      VfDelta: 0,
                      SrcType: &CWnd `RTTI Type Descriptor',
                      TargetType: &CView `RTTI Type Descriptor',
                      isReference: 0);
      CFrameWnd::SetActiveView(this, pViewNew: v5, bNotify: 1);
      ((void (__thiscall *)(CView *, int))v3->dtr_CObject)(a1: v3, a2: 4);
      v3->IsInvokeAllowed(this: v3, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BD20
// Name: protected: void CChildFrame::OnView3dTextured(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::OnView3dTextured(CChildFrame *this)
{
  CView *v2; // eax
  CView *v3; // esi
  void *v4; // eax
  CView *v5; // eax

  v2 = CChildFrame::ReplaceView(this, pViewClass: &CMapView3D::classCMapView3D);
  if ( v2 != nullptr )
  {
    v3 = v2 + 1;
    if ( v2 != (CView *)-124 )
    {
      v4 = (void *)v3->GetTypeInfoCount(this: v3);
      v5 = (CView *)__RTDynamicCast(
                      inptr: v4,
                      VfDelta: 0,
                      SrcType: &CWnd `RTTI Type Descriptor',
                      TargetType: &CView `RTTI Type Descriptor',
                      isReference: 0);
      CFrameWnd::SetActiveView(this, pViewNew: v5, bNotify: 1);
      ((void (__thiscall *)(CView *, int))v3->dtr_CObject)(a1: v3, a2: 5);
      v3->IsInvokeAllowed(this: v3, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BD80
// Name: protected: void CChildFrame::OnView3dTexturedShaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::OnView3dTexturedShaded(CChildFrame *this)
{
  CView *v2; // eax
  CView *v3; // esi
  void *v4; // eax
  CView *v5; // eax

  v2 = CChildFrame::ReplaceView(this, pViewClass: &CMapView3D::classCMapView3D);
  if ( v2 != nullptr )
  {
    v3 = v2 + 1;
    if ( v2 != (CView *)-124 )
    {
      v4 = (void *)v3->GetTypeInfoCount(this: v3);
      v5 = (CView *)__RTDynamicCast(
                      inptr: v4,
                      VfDelta: 0,
                      SrcType: &CWnd `RTTI Type Descriptor',
                      TargetType: &CView `RTTI Type Descriptor',
                      isReference: 0);
      CFrameWnd::SetActiveView(this, pViewNew: v5, bNotify: 1);
      ((void (__thiscall *)(CView *, int))v3->dtr_CObject)(a1: v3, a2: 9);
      v3->IsInvokeAllowed(this: v3, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BDE0
// Name: protected: void CChildFrame::OnView3dLightingPreview(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::OnView3dLightingPreview(CChildFrame *this)
{
  CView *v2; // eax
  CView *v3; // esi
  void *v4; // eax
  CView *v5; // eax

  v2 = CChildFrame::ReplaceView(this, pViewClass: &CMapView3D::classCMapView3D);
  if ( v2 != nullptr )
  {
    v3 = v2 + 1;
    if ( v2 != (CView *)-124 )
    {
      v4 = (void *)v3->GetTypeInfoCount(this: v3);
      v5 = (CView *)__RTDynamicCast(
                      inptr: v4,
                      VfDelta: 0,
                      SrcType: &CWnd `RTTI Type Descriptor',
                      TargetType: &CView `RTTI Type Descriptor',
                      isReference: 0);
      CFrameWnd::SetActiveView(this, pViewNew: v5, bNotify: 1);
      ((void (__thiscall *)(CView *, int))v3->dtr_CObject)(a1: v3, a2: 11);
      v3->IsInvokeAllowed(this: v3, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BE40
// Name: protected: void CChildFrame::OnView3dLightingPreviewRayTraced(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::OnView3dLightingPreviewRayTraced(CChildFrame *this)
{
  CView *v2; // eax
  CView *v3; // esi
  void *v4; // eax
  CView *v5; // eax

  v2 = CChildFrame::ReplaceView(this, pViewClass: &CMapView3D::classCMapView3D);
  if ( v2 != nullptr )
  {
    v3 = v2 + 1;
    if ( v2 != (CView *)-124 )
    {
      v4 = (void *)v3->GetTypeInfoCount(this: v3);
      v5 = (CView *)__RTDynamicCast(
                      inptr: v4,
                      VfDelta: 0,
                      SrcType: &CWnd `RTTI Type Descriptor',
                      TargetType: &CView `RTTI Type Descriptor',
                      isReference: 0);
      CFrameWnd::SetActiveView(this, pViewNew: v5, bNotify: 1);
      ((void (__thiscall *)(CView *, int))v3->dtr_CObject)(a1: v3, a2: 12);
      v3->IsInvokeAllowed(this: v3, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BEA0
// Name: protected: void CChildFrame::OnView3dLightmapGrid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::OnView3dLightmapGrid(CChildFrame *this)
{
  CView *v2; // eax
  CView *v3; // esi
  void *v4; // eax
  CView *v5; // eax

  v2 = CChildFrame::ReplaceView(this, pViewClass: &CMapView3D::classCMapView3D);
  if ( v2 != nullptr )
  {
    v3 = v2 + 1;
    if ( v2 != (CView *)-124 )
    {
      v4 = (void *)v3->GetTypeInfoCount(this: v3);
      v5 = (CView *)__RTDynamicCast(
                      inptr: v4,
                      VfDelta: 0,
                      SrcType: &CWnd `RTTI Type Descriptor',
                      TargetType: &CView `RTTI Type Descriptor',
                      isReference: 0);
      CFrameWnd::SetActiveView(this, pViewNew: v5, bNotify: 1);
      ((void (__thiscall *)(CView *, int))v3->dtr_CObject)(a1: v3, a2: 6);
      v3->IsInvokeAllowed(this: v3, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BF00
// Name: protected: void CChildFrame::OnView3dSmooth(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::OnView3dSmooth(CChildFrame *this)
{
  CView *v2; // eax
  CView *v3; // esi
  void *v4; // eax
  CView *v5; // eax

  v2 = CChildFrame::ReplaceView(this, pViewClass: &CMapView3D::classCMapView3D);
  if ( v2 != nullptr )
  {
    v3 = v2 + 1;
    if ( v2 != (CView *)-124 )
    {
      v4 = (void *)v3->GetTypeInfoCount(this: v3);
      v5 = (CView *)__RTDynamicCast(
                      inptr: v4,
                      VfDelta: 0,
                      SrcType: &CWnd `RTTI Type Descriptor',
                      TargetType: &CView `RTTI Type Descriptor',
                      isReference: 0);
      CFrameWnd::SetActiveView(this, pViewNew: v5, bNotify: 1);
      ((void (__thiscall *)(CView *, int))v3->dtr_CObject)(a1: v3, a2: 7);
      v3->IsInvokeAllowed(this: v3, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BF60
// Name: protected: virtual int CChildFrame::OnCreateClient(struct tagCREATESTRUCTA __near *,struct CCreateContext __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CChildFrame::OnCreateClient@<eax>(
        CChildFrame *this@<ecx>,
        int a2@<ebx>,
        tagCREATESTRUCTA *lpcs,
        CCreateContext *pContext)
{
  int v5; // esi
  CSplitterWnd *v6; // eax
  CMySplitterWnd *v7; // ebx
  CMySplitterWnd *v8; // ecx
  CMySplitterWnd *m_wndSplitter; // ecx
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v12; // eax
  AFX_MODULE_STATE *v13; // eax
  AFX_MODULE_STATE *v14; // eax
  int v15; // ebx
  DrawType_t *v16; // ecx
  int v17; // eax
  CWnd *Pane; // eax
  void *v19; // eax
  AFX_MODULE_STATE *v20; // eax
  int v21; // esi
  AFX_MODULE_STATE *v22; // eax
  int v23; // eax
  HWND__ *m_hWnd; // [esp-Ch] [ebp-48h]
  DrawType_t eDrawType[2][2]; // [esp+8h] [ebp-34h] BYREF
  CRect r; // [esp+18h] [ebp-24h] BYREF
  CSize sizeView; // [esp+28h] [ebp-14h]
  int v29; // [esp+38h] [ebp-4h]
  tagCREATESTRUCTA *lpcsa; // [esp+44h] [ebp+8h]

  v5 = 0;
  if ( this->bUsingSplitter == 0 )
    return CFrameWnd::OnCreateClient(this, __formal: lpcs, pContext);
  v6 = (CSplitterWnd *)operator new(nSize: 0x110u);
  v7 = (CMySplitterWnd *)v6;
  v29 = 0;
  if ( v6 != nullptr )
  {
    CSplitterWnd::CSplitterWnd(this: v6);
    v7->__vftable = (CMySplitterWnd_vtbl *)&CMySplitterWnd::`vftable';
    v7->pMaxPrev = nullptr;
    LOBYTE(v29) = 0;
    v8 = v7;
  }
  else
  {
    v8 = nullptr;
  }
  v29 = -1;
  this->m_wndSplitter = v8;
  if ( v8 == nullptr )
    return 0;
  if ( v8->CreateStatic(this: v8, a2: this, a3: 2, a4: 2, a5: 1342177280u, a6: 59648u) == 0 )
  {
    m_wndSplitter = this->m_wndSplitter;
    if ( m_wndSplitter != nullptr )
      ((void (__thiscall *)(CMySplitterWnd *, int))m_wndSplitter->dtr_CObject)(a1: m_wndSplitter, a2: 1);
    this->m_wndSplitter = nullptr;
    return 0;
  }
  m_hWnd = this->m_hWnd;
  memset(&r, 0, sizeof(r));
  GetClientRect(hWnd: m_hWnd, lpRect: &r);
  sizeView.cx = (r.right - r.left) / 2 - 3;
  sizeView.cy = (r.bottom - r.top) / 2 - 3;
  ModuleState = AfxGetModuleState();
  eDrawType[0][0] = ((int (__thiscall *)(CWinApp *, const char *, const char *, int, int))ModuleState->m_pCurrentWinApp->GetProfileIntA)(
                      a1: ModuleState->m_pCurrentWinApp,
                      a2: "Splitter",
                      a3: "DrawType0,0",
                      a4: 3,
                      a5: a2);
  v12 = AfxGetModuleState();
  eDrawType[0][1] = v12->m_pCurrentWinApp->GetProfileIntA(
                      this: v12->m_pCurrentWinApp,
                      a2: "Splitter",
                      a3: "DrawType0,1",
                      a4: 0);
  v13 = AfxGetModuleState();
  eDrawType[1][0] = v13->m_pCurrentWinApp->GetProfileIntA(
                      this: v13->m_pCurrentWinApp,
                      a2: "Splitter",
                      a3: "DrawType1,0",
                      a4: 1);
  v14 = AfxGetModuleState();
  eDrawType[1][1] = v14->m_pCurrentWinApp->GetProfileIntA(
                      this: v14->m_pCurrentWinApp,
                      a2: "Splitter",
                      a3: "DrawType1,1",
                      a4: 2);
  v15 = 0;
  v16 = eDrawType[0];
  while ( 1 )
  {
    lpcsa = (tagCREATESTRUCTA *)v16;
    do
    {
      v17 = *v16;
      if ( *v16 == VIEW3D_ENGINE || v17 >= 13 )
      {
        *v16 = VIEW3D_TEXTURED;
        v17 = *v16;
      }
      switch ( v17 )
      {
        case 0:
        case 1:
        case 2:
          ((void (__thiscall *)(CMySplitterWnd *, int, int, CRuntimeClass *, int, int, CCreateContext *))this->m_wndSplitter->CreateView)(
            a1: this->m_wndSplitter,
            a2: v15,
            a3: v5,
            a4: &CMapView2D::classCMapView2D,
            a5: sizeView.cx,
            a6: sizeView.cy,
            a7: pContext);
          break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 9:
        case 11:
        case 12:
          ((void (__thiscall *)(CMySplitterWnd *, int, int, CRuntimeClass *, int, int, CCreateContext *))this->m_wndSplitter->CreateView)(
            a1: this->m_wndSplitter,
            a2: v15,
            a3: v5,
            a4: &CMapView3D::classCMapView3D,
            a5: sizeView.cx,
            a6: sizeView.cy,
            a7: pContext);
          break;
        case 10:
          ((void (__thiscall *)(CMySplitterWnd *, int, int, CRuntimeClass *, int, int, CCreateContext *))this->m_wndSplitter->CreateView)(
            a1: this->m_wndSplitter,
            a2: v15,
            a3: v5,
            a4: &CMapViewLogical::classCMapViewLogical,
            a5: sizeView.cx,
            a6: sizeView.cy,
            a7: pContext);
          break;
        default:
          break;
      }
      Pane = CSplitterWnd::GetPane(this: this->m_wndSplitter, row: v15, col: v5);
      v19 = __RTDynamicCast(
              inptr: Pane,
              VfDelta: 0,
              SrcType: &CWnd `RTTI Type Descriptor',
              TargetType: &CMapView `RTTI Type Descriptor',
              isReference: 0);
      if ( v19 != nullptr )
        (*(void (__thiscall **)(void *, void *))(*(_DWORD *)v19 + 4))(a1: v19, a2: lpcsa->lpCreateParams);
      lpcsa = (tagCREATESTRUCTA *)((char *)lpcsa + 4);
      v16 = (DrawType_t *)lpcsa;
      ++v5;
    }
    while ( v5 < 2 );
    if ( ++v15 >= 2 )
      break;
    v5 = 0;
  }
  v20 = AfxGetModuleState();
  v21 = ((int (__thiscall *)(CWinApp *, const char *, const char *))v20->m_pCurrentWinApp->GetProfileIntA)(
          a1: v20->m_pCurrentWinApp,
          a2: "Splitter",
          a3: "SplitterWidth");
  v22 = AfxGetModuleState();
  v23 = v22->m_pCurrentWinApp->GetProfileIntA(this: v22->m_pCurrentWinApp, a2: "Splitter", a3: "SplitterHeight", a4: -1);
  if ( v21 == -1 || v23 == -1 )
  {
    this->m_bNeedsCentered = 1;
    this->m_bReady = 1;
    return 1;
  }
  else
  {
    CSplitterWnd::SetRowInfo(this: this->m_wndSplitter, row: 0, cyIdeal: v23, cyMin: 0);
    CSplitterWnd::SetColumnInfo(this: this->m_wndSplitter, col: 0, cxIdeal: v21, cxMin: 0);
    this->m_wndSplitter->RecalcLayout(this: this->m_wndSplitter);
    this->m_bReady = 1;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C2D0
// Name: public: void CChildFrame::CenterViews(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::CenterViews(CChildFrame *this)
{
  int v2; // edi
  int v3; // ebx
  vgui::ToolWindow *v4; // ecx
  HWND__ *m_hWnd; // [esp-Ch] [ebp-24h]
  CRect r; // [esp+8h] [ebp-10h] BYREF

  if ( this->bUsingSplitter != 0 && this->m_bReady != 0 )
  {
    CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
    m_hWnd = this->m_hWnd;
    memset(&r, 0, sizeof(r));
    GetClientRect(hWnd: m_hWnd, lpRect: &r);
    v2 = ((r.bottom - r.top) / 2 - 3) & (((r.bottom - r.top) / 2 - 3 < 0) - 1);
    v3 = ((r.right - r.left) / 2 - 3) & (((r.right - r.left) / 2 - 3 < 0) - 1);
    CSplitterWnd::SetRowInfo(this: this->m_wndSplitter, row: 0, cyIdeal: v2, cyMin: 0);
    CSplitterWnd::SetRowInfo(this: this->m_wndSplitter, row: 1, cyIdeal: v2, cyMin: 0);
    CSplitterWnd::SetColumnInfo(this: this->m_wndSplitter, col: 0, cxIdeal: v3, cxMin: 0);
    CSplitterWnd::SetColumnInfo(this: this->m_wndSplitter, col: 1, cxIdeal: v3, cxMin: 0);
    this->m_wndSplitter->RecalcLayout(this: this->m_wndSplitter);
    CDmeFXClip::OnDestruction(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C3C0
// Name: protected: void CChildFrame::OnViewAutosize4(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::OnViewAutosize4(CChildFrame *this)
{
  if ( this->bUsingSplitter != 0 )
    CChildFrame::CenterViews(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000C3D0
// Name: protected: void CChildFrame::OnPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::OnPaint(CChildFrame *this)
{
  bool v2; // zf
  CPaintDC dc; // [esp+4h] [ebp-54h] BYREF

  if ( this->bFirstPaint != 0 )
  {
    ValidateRect(hWnd: this->m_hWnd, lpRect: nullptr);
    v2 = this->m_bNeedsCentered == 0;
    this->bFirstPaint = 0;
    if ( !v2 )
      CChildFrame::CenterViews(this);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
  }
  else
  {
    CPaintDC::CPaintDC(this: &dc, pWnd: this);
    CPaintDC::~CPaintDC(this: &dc);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C440
// Name: public: void CMySplitterWnd::ToggleMax(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMySplitterWnd::ToggleMax(CMySplitterWnd *this, CWnd *pWnd)
{
  int v3; // edi
  int v4; // ebx
  HWND__ *m_hWnd; // [esp-8h] [ebp-2Ch]
  CRect r; // [esp+Ch] [ebp-18h] BYREF
  int iCol; // [esp+1Ch] [ebp-8h] BYREF
  int iRow; // [esp+20h] [ebp-4h] BYREF

  v3 = 0;
  if ( this->pMaxPrev == nullptr )
  {
    CSplitterWnd::GetRowInfo(this, row: 0, cyCur: this->sizePrev[1], cyMin: &iRow);
    CSplitterWnd::GetRowInfo(this, row: 1, cyCur: &this->sizePrev[1][1], cyMin: &iRow);
    CSplitterWnd::GetColumnInfo(this, col: 0, cxCur: this->sizePrev[0], cxMin: &iRow);
    CSplitterWnd::GetColumnInfo(this, col: 1, cxCur: &this->sizePrev[0][1], cxMin: &iRow);
  }
  if ( pWnd == this->pMaxPrev )
  {
    CSplitterWnd::SetRowInfo(this, row: 0, cyIdeal: this->sizePrev[1][0], cyMin: 0);
    CSplitterWnd::SetRowInfo(this, row: 1, cyIdeal: this->sizePrev[1][1], cyMin: 0);
    CSplitterWnd::SetColumnInfo(this, col: 0, cxIdeal: this->sizePrev[0][0], cxMin: 0);
    CSplitterWnd::SetColumnInfo(this, col: 1, cxIdeal: this->sizePrev[0][1], cxMin: 0);
    this->pMaxPrev = nullptr;
  }
  else
  {
    m_hWnd = this->m_hWnd;
    memset(&r, 0, sizeof(r));
    GetClientRect(hWnd: m_hWnd, lpRect: &r);
    CSplitterWnd::IsChildPane(this, pWnd, pRow: &iRow, pCol: &iCol);
    v4 = 0;
    while ( 1 )
    {
      do
      {
        CSplitterWnd::SetRowInfo(this, row: v4, cyIdeal: 0, cyMin: 0);
        CSplitterWnd::SetColumnInfo(this, col: v3++, cxIdeal: 0, cxMin: 0);
      }
      while ( v3 < 2 );
      if ( ++v4 >= 2 )
        break;
      v3 = 0;
    }
    CSplitterWnd::SetRowInfo(this, row: iRow, cyIdeal: r.bottom - r.top, cyMin: 5);
    CSplitterWnd::SetColumnInfo(this, col: iCol, cxIdeal: r.right - r.left, cxMin: 5);
    this->pMaxPrev = pWnd;
  }
  this->RecalcLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000C5A0
// Name: protected: void CChildFrame::OnViewMaximizepane(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::OnViewMaximizepane(CChildFrame *this)
{
  CWnd *v2; // eax

  if ( this->bUsingSplitter != 0
    && this->m_wndSplitter->GetActivePane(this: this->m_wndSplitter, a2: 0, a3: 0) != nullptr )
  {
    v2 = this->m_wndSplitter->GetActivePane(this: this->m_wndSplitter, a2: 0, a3: 0);
    CMySplitterWnd::ToggleMax(this: this->m_wndSplitter, pWnd: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C5F0
// Name: protected: void CChildFrame::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::OnClose(CChildFrame *this)
{
  CChildFrame::SaveOptions(this);
  CFrameWnd::OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000C600
// Name: public: ATL::CSimpleStringT<char,0>::~CSimpleStringT<char,0>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ATL::CSimpleStringT<char,0>::~CSimpleStringT<char,0>(ATL::CSimpleStringT<char,0> *this)
{
  volatile signed __int32 *v1; // eax

  v1 = (volatile signed __int32 *)(this->m_pszData - 16);
  if ( _InterlockedDecrement(v1 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v1 + 4))(a1: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1000C620
// Name: public: static class CObject __near * CChildFrame::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CChildFrame *__stdcall CChildFrame::CreateObject()
{
  CChildFrame *v0; // eax

  v0 = (CChildFrame *)operator new(nSize: 0x130u);
  if ( v0 != nullptr )
    return CChildFrame::CChildFrame(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000C6D0
// Name: protected: int CChildFrame::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChildFrame::OnCreate(CChildFrame *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  int *p_style; // eax
  tagWINDOWPLACEMENT wp; // [esp+4h] [ebp-38h] BYREF
  int v7; // [esp+38h] [ebp-4h]

  result = CMDIChildWnd::OnCreate(this, lpCreateStruct);
  if ( result != -1 )
  {
    if ( this->bUsingSplitter != 0 && CHammer::IsNewDocumentVisible() )
    {
      ModuleState = AfxGetModuleState();
      ModuleState->m_pCurrentWinApp->GetProfileStringA(
        this: ModuleState->m_pCurrentWinApp,
        result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpCreateStruct,
        a3: "Splitter",
        a4: "WindowPlacement",
        a5: &var);
      v7 = 0;
      if ( lpCreateStruct[-1].lpszName != nullptr )
      {
        wp.length = 44;
        wp.flags = 0;
        sscanf(
          string: (const char *)lpCreateStruct,
          format: "(%d %d) (%d %d) (%d %d %d %d) %d",
          &wp.ptMaxPosition,
          &wp.ptMaxPosition.y,
          &wp.ptMinPosition,
          &wp.ptMinPosition.y,
          &wp.rcNormalPosition.bottom,
          &wp.rcNormalPosition,
          &wp.rcNormalPosition.right,
          &wp.rcNormalPosition.top,
          &wp.showCmd);
        if ( wp.showCmd == 3 )
          PostMessageA(hWnd: this->m_hWnd, Msg: 0x112u, wParam: 0xF030u, lParam: 0);
        else
          CWnd::SetWindowPlacement(this, lpwndpl: &wp);
      }
      v7 = -1;
      p_style = &lpCreateStruct[-1].style;
      if ( _InterlockedDecrement((volatile signed __int32 *)&lpCreateStruct[-1].dwExStyle) <= 0 )
        (*(void (__stdcall **)(int *))(*(_DWORD *)*p_style + 4))(a1: p_style);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000C810
// Name: protected: virtual struct AFX_MSGMAP const __near * CChildFrame::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CChildFrame::GetMessageMap(CChildFrame *this)
{
  return (const AFX_MSGMAP *)&off_105D7990;
}

//------------------------------------------------------------------------------
// Address: 0x10054100
// Name: protected: void CChildFrame::OnUpdateViewMaximizepane(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChildFrame::OnUpdateViewMaximizepane(CChildFrame *this, CCmdUI *pCmdUI)
{
  pCmdUI->Enable(this: pCmdUI, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10333419
// Name: public: virtual struct CRuntimeClass __near * CObject::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CObject::GetRuntimeClass(CObject *this)
{
  return &CObject::classCObject;
}

//------------------------------------------------------------------------------
// Address: 0x1033349D
// Name: public: int CObject::IsKindOf(struct CRuntimeClass const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CObject::IsKindOf(CObject *this, const CRuntimeClass *pClass)
{
  CRuntimeClass *v2; // eax

  if ( this == nullptr || (v2 = (CRuntimeClass *)this->GetRuntimeClass(this)) == nullptr )
    AfxThrowInvalidArgException();
  return CRuntimeClass::IsDerivedFrom(this: v2, pBaseClass: pClass);
}

//------------------------------------------------------------------------------
// Address: 0x1033FB29
// Name: public: virtual void CFrameWnd::EndModalState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::EndModalState(CFrameWnd *this)
{
  unsigned int m_cModalStack; // ecx
  int v3; // edi
  unsigned int v4; // ecx
  HWND__ **m_phWndDisable; // eax
  int v6; // ebx

  m_cModalStack = this->m_cModalStack;
  v3 = 0;
  if ( m_cModalStack != 0 )
  {
    v4 = m_cModalStack - 1;
    this->m_cModalStack = v4;
    if ( v4 == 0 )
    {
      m_phWndDisable = this->m_phWndDisable;
      if ( m_phWndDisable != nullptr )
      {
        v6 = 0;
        if ( *m_phWndDisable != nullptr )
        {
          do
          {
            if ( IsWindow(hWnd: this->m_phWndDisable[v3]) )
              EnableWindow(hWnd: this->m_phWndDisable[v3], bEnable: true);
            v3 = ++v6;
          }
          while ( this->m_phWndDisable[v6] != nullptr );
        }
        operator delete(p: this->m_phWndDisable);
        this->m_phWndDisable = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033FD61
// Name: public: class CView __near * CFrameWnd::GetActiveView(void)const
// Source: json
//------------------------------------------------------------------------------
CView *__thiscall CFrameWnd::GetActiveView(CFrameWnd *this)
{
  return this->m_pViewActive;
}

//------------------------------------------------------------------------------
// Address: 0x103403AF
// Name: protected: virtual int CFrameWnd::OnCreateClient(struct tagCREATESTRUCTA __near *,struct CCreateContext __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::OnCreateClient(CFrameWnd *this, tagCREATESTRUCTA *__formal, CCreateContext *pContext)
{
  int result; // eax

  if ( pContext == nullptr )
    return 1;
  if ( pContext->m_pNewViewClass == nullptr )
    return 1;
  result = (int)CFrameWnd::CreateView(this, pContext, nID: 0xE900u);
  if ( result != 0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10341938
// Name: public: virtual void CFrameWnd::BeginModalState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::BeginModalState(CFrameWnd *this)
{
  int m_nSize; // esi
  HWND DesktopWindow; // eax
  HWND Window; // edi
  HWND__ **v4; // eax
  CFrameWnd *v5; // edi
  CArray<HWND__ *,HWND__ *> arrDisabledWnds; // [esp+10h] [ebp-28h] BYREF
  CFrameWnd *v7; // [esp+24h] [ebp-14h]
  CWnd *TopLevelParent; // [esp+28h] [ebp-10h]
  int v9; // [esp+34h] [ebp-4h]

  v7 = this;
  if ( ++this->m_cModalStack <= 1 )
  {
    TopLevelParent = CWnd::GetTopLevelParent(this);
    if ( TopLevelParent == nullptr )
      goto LABEL_3;
    m_nSize = 0;
    arrDisabledWnds.__vftable = (CArray<HWND__ *,HWND__ *>_vtbl *)&CArray<HWND__ *,HWND__ *>::`vftable';
    memset(&arrDisabledWnds.m_pData, 0, 16);
    v9 = 0;
    DesktopWindow = GetDesktopWindow();
    Window = GetWindow(hWnd: DesktopWindow, uCmd: 5u);
    if ( Window != nullptr )
    {
      do
      {
        if ( IsWindowEnabled(hWnd: Window)
          && CWnd::FromHandlePermanent(hWnd: Window) != nullptr
          && AfxIsDescendant(hWndParent: TopLevelParent->m_hWnd, hWndChild: Window) != 0
          && SendMessageA(hWnd: Window, Msg: 0x36Cu, wParam: 0, lParam: 0) == 0 )
        {
          EnableWindow(hWnd: Window, bEnable: false);
          CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
            this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&arrDisabledWnds,
            nIndex: m_nSize,
            newElement: (CMFCRibbonKeyTip *)Window);
          m_nSize = arrDisabledWnds.m_nSize;
        }
        Window = GetWindow(hWnd: Window, uCmd: 2u);
      }
      while ( Window != nullptr );
      if ( m_nSize != 0 )
      {
        if ( m_nSize <= 0
          || (v4 = (HWND__ **)operator new(nSize: 4 * (m_nSize + 1)),
              v5 = v7,
              v7->m_phWndDisable = v4,
              v4[m_nSize] = nullptr,
              arrDisabledWnds.m_pData == nullptr) )
        {
LABEL_3:
          AfxThrowInvalidArgException();
        }
        ATL::Checked::memcpy_s(
          _S1: v5->m_phWndDisable,
          _S1max: 4 * m_nSize,
          _S2: arrDisabledWnds.m_pData,
          _N: 4 * m_nSize);
      }
    }
    v9 = -1;
    CArray<HWND__ *,HWND__ *>::~CArray<HWND__ *,HWND__ *>(this: &arrDisabledWnds);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1038E112
// Name: protected: virtual int CMDIFrameWndEx::OnCreateClient(struct tagCREATESTRUCTA __near *,struct CCreateContext __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::OnCreateClient(CMDIFrameWndEx *this, tagCREATESTRUCTA *lpcs, CCreateContext *pContext)
{
  int result; // eax

  result = CMDIFrameWnd::OnCreateClient(this, lpcs, __formal: pContext);
  if ( result != 0 )
  {
    if ( this->m_bDoSubclass != 0 )
      CWnd::SubclassWindow(this: &this->m_wndClientArea, hWnd: this->m_hWndMDIClient);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1033341F
// Name: public: class CObject __near * CRuntimeClass::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CObject *__thiscall CRuntimeClass::CreateObject(CRuntimeClass *this)
{
  if ( this == nullptr )
    AfxThrowInvalidArgException();
  if ( this->m_pfnCreateObject != nullptr )
    return this->m_pfnCreateObject();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10333469
// Name: public: int CRuntimeClass::IsDerivedFrom(struct CRuntimeClass const __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CRuntimeClass::IsDerivedFrom(CRuntimeClass *this, const CRuntimeClass *pBaseClass)
{
  CRuntimeClass *result; // eax

  result = this;
  if ( this == nullptr || pBaseClass == nullptr )
    AfxThrowInvalidArgException();
  while ( result != pBaseClass )
  {
    result = result->m_pBaseClass;
    if ( result == nullptr )
      return result;
  }
  return (CRuntimeClass *)1;
}

//------------------------------------------------------------------------------
// Address: 0x10333494
// Name: public: ATL::CComBSTR::~CComBSTR(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ATL::CComBSTR::~CComBSTR(ATL::CComBSTR *this)
{
  SysFreeString(bstrString: this->m_str);
}

//------------------------------------------------------------------------------
// Address: 0x103334BB
// Name: class CObject __near * AfxDynamicDownCast(struct CRuntimeClass __near *,class CObject __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CObject *__cdecl AfxDynamicDownCast(CRuntimeClass *pClass, CObject *pObject)
{
  if ( pObject != nullptr && CObject::IsKindOf(this: pObject, pClass) != 0 )
    return pObject;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103334DE
// Name: void AfxClassInit(struct CRuntimeClass __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall AfxClassInit(CRuntimeClass *pNewClass)
{
  AFX_MODULE_STATE *ModuleState; // esi

  ModuleState = AfxGetModuleState();
  AfxLockGlobals(nLockType: 0);
  CSimpleList::AddHead(this: &ModuleState->m_classList, p: pNewClass);
  AfxUnlockGlobals(nLockType: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10333509
// Name: public: virtual struct CRuntimeClass __near * CArchiveException::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CArchiveException::GetRuntimeClass(CArchiveException *this)
{
  return &CArchiveException::classCArchiveException;
}

//------------------------------------------------------------------------------
// Address: 0x1033350F
// Name: public: virtual int CArchiveException::GetErrorMessage(char __near *,unsigned int,unsigned int __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CArchiveException::GetErrorMessage(
        CArchiveException *this,
        char *lpszError,
        unsigned int nMaxError,
        unsigned __int8 *pnHelpContext)
{
  ATL::IAtlStringMgr *StringManager; // eax
  ATL::CStringData *v6; // eax
  char *m_pszData; // esi
  HINSTANCE__ *StringResourceHandle; // eax
  int v9; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strFileName; // [esp+14h] [ebp-14h] BYREF
  int v12; // [esp+24h] [ebp-4h]

  if ( lpszError == nullptr )
    return 0;
  if ( pnHelpContext != nullptr )
    *(_DWORD *)pnHelpContext = this->m_cause + 61872;
  v12 = 0;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
    this: (ATL::CSimpleStringT<char,0> *)&pnHelpContext,
    pStringMgr: StringManager);
  v6 = ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)this->m_strFileName.m_pszData - 1);
  m_pszData = (char *)&v6[1];
  strFileName.m_pszData = (char *)&v6[1];
  LOBYTE(v12) = 2;
  if ( v6->nDataLength == 0 )
  {
    StringResourceHandle = AfxFindStringResourceHandle(__formal: 0xF006u);
    if ( StringResourceHandle != nullptr )
    {
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
        this: &strFileName,
        hInstance: StringResourceHandle,
        nID: 0xF006u);
      m_pszData = strFileName.m_pszData;
    }
  }
  AfxFormatString1(
    rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pnHelpContext,
    nIDS: this->m_cause + 61872,
    lpsz1: m_pszData);
  v9 = _mbsnbcpy_s(_Arg1: (unsigned __int8 *)lpszError, _Arg2: nMaxError, _Arg3: pnHelpContext, _Arg4: 0xFFFFFFFF);
  AfxCrtErrorCheck(error: v9);
  ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)pnHelpContext - 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103335DB
// Name: public: CArchiveException::CArchiveException(int,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CArchiveException *__thiscall CArchiveException::CArchiveException(
        CArchiveException *this,
        int cause,
        const char *lpszFileName)
{
  ATL::IAtlStringMgr *StringManager; // eax

  CException::CException(this);
  this->__vftable = (CArchiveException_vtbl *)&CArchiveException::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strFileName, pStringMgr: StringManager);
  this->m_cause = cause;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strFileName, pszSrc: lpszFileName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10333651
// Name: void AfxThrowArchiveException(int,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall __noreturn AfxThrowArchiveException(int cause, const char *lpszArchiveName)
{
  CArchiveException *v2; // ecx
  CArchiveException *v3; // eax
  CArchiveException *pExceptionObject; // [esp+14h] [ebp-10h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  v2 = (CArchiveException *)operator new(nSize: 0x10u);
  v3 = nullptr;
  v5 = 0;
  if ( v2 != nullptr )
    v3 = CArchiveException::CArchiveException(this: v2, cause, lpszFileName: lpszArchiveName);
  v5 = -1;
  pExceptionObject = v3;
  _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI4PAVCArchiveException__);
}

//------------------------------------------------------------------------------
// Address: 0x1033FBA4
// Name: public: void CFrameWnd::ShowOwnedWindows(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::ShowOwnedWindows(CFrameWnd *this, int bShow)
{
  HWND DesktopWindow; // eax
  HWND i; // edi
  CWnd *v4; // esi
  HWND__ *m_hWnd; // eax
  LONG WindowLongA; // eax

  DesktopWindow = GetDesktopWindow();
  for ( i = GetWindow(hWnd: DesktopWindow, uCmd: 5u); i != nullptr; i = GetWindow(hWnd: i, uCmd: 2u) )
  {
    v4 = CWnd::FromHandlePermanent(hWnd: i);
    if ( v4 != nullptr )
    {
      m_hWnd = this->m_hWnd;
      if ( m_hWnd != i && AfxIsDescendant(hWndParent: m_hWnd, hWndChild: i) != 0 )
      {
        WindowLongA = GetWindowLongA(hWnd: i, nIndex: -16);
        if ( bShow != 0 )
        {
          if ( (WindowLongA & 0x18000000) == 0 && (v4->m_nFlags & 2) != 0 && this->m_lpfnCloseProc == nullptr )
          {
            ShowWindow(hWnd: i, nCmdShow: 4);
            v4->m_nFlags &= ~2u;
          }
        }
        else if ( (WindowLongA & 0x18000000) == 0x10000000 )
        {
          ShowWindow(hWnd: i, nCmdShow: 0);
          v4->m_nFlags |= 2u;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033FC4E
// Name: protected: virtual int CFrameWnd::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::PreCreateWindow(CFrameWnd *this, tagCREATESTRUCTA *cs)
{
  int style; // eax

  if ( cs->lpszClass == nullptr )
  {
    AfxEndDeferRegisterClass(fToRegister: 8);
    cs->lpszClass = "AfxFrameOrView100s";
  }
  style = cs->style;
  if ( (style & 0x8000) != 0 )
    cs->style = style | 0x4000;
  cs->dwExStyle |= 0x200u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1033FC8C
// Name: public: virtual void CFrameWnd::OnUpdateFrameMenu(struct HMENU__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnUpdateFrameMenu(CFrameWnd *this, HMENU__ *hMenuAlt)
{
  HMENU m_hMenuDefault; // eax
  CDocument *v4; // eax
  unsigned int m_dwMenuBarState; // ecx

  m_hMenuDefault = hMenuAlt;
  if ( hMenuAlt == nullptr )
  {
    v4 = this->GetActiveDocument(this);
    if ( v4 == nullptr || (m_hMenuDefault = v4->GetDefaultMenu(this: v4)) == nullptr )
      m_hMenuDefault = this->m_hMenuDefault;
  }
  m_dwMenuBarState = this->m_dwMenuBarState;
  if ( m_dwMenuBarState == 1 )
  {
    SetMenu(hWnd: this->m_hWnd, hMenu: m_hMenuDefault);
  }
  else if ( m_dwMenuBarState == 2 )
  {
    this->m_hMenu = m_hMenuDefault;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033FCDF
// Name: public: void CFrameWnd::RemoveControlBar(class CControlBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::RemoveControlBar(CFrameWnd *this, CControlBar *pBar)
{
  CObList *p_m_listControlBars; // esi
  __POSITION *v3; // eax

  p_m_listControlBars = (CObList *)&this->m_listControlBars;
  v3 = CPtrList::Find(this: (CObList *)&this->m_listControlBars, searchValue: pBar, startAfter: nullptr);
  if ( v3 != nullptr )
    CPtrList::RemoveAt(this: p_m_listControlBars, position: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1033FD08
// Name: protected: int CFrameWnd::OnNcActivate(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::OnNcActivate(CFrameWnd *this, unsigned int bActive)
{
  if ( (this->m_nFlags & 0x20) != 0 )
    bActive = 1;
  if ( CWnd::IsWindowEnabled(this) == 0 )
    bActive = 0;
  return this->DefWindowProcA(this, a2: 134u, a3: bActive, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1033FD42
// Name: protected: long CFrameWnd::OnDDETerminate(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::OnDDETerminate(CFrameWnd *this, HWND wParam, LPARAM lParam)
{
  PostMessageA(hWnd: wParam, Msg: 0x3E1u, wParam: (WPARAM)this->m_hWnd, lParam);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103403D6
// Name: protected: int CFrameWnd::OnCreateHelper(struct tagCREATESTRUCTA __near *,struct CCreateContext __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::OnCreateHelper(CFrameWnd *this, tagCREATESTRUCTA *lpcs, CCreateContext *pContext)
{
  if ( CWnd::Default(this) == -1 || this->OnCreateClient(this, a2: lpcs, a3: pContext) == 0 )
    return -1;
  PostMessageA(hWnd: this->m_hWnd, Msg: 0x362u, wParam: 0xE001u, lParam: 0);
  this->RecalcLayout(this, a2: 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10340429
// Name: protected: char const __near * CFrameWnd::GetIconWndClass(unsigned long,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__thiscall CFrameWnd::GetIconWndClass(
        CFrameWnd *this,
        unsigned int dwDefaultStyle,
        unsigned __int16 nIDResource)
{
  AFX_MODULE_STATE *ModuleState; // eax
  HICON IconW; // edi
  AFX_MODULE_STATE *v6; // eax
  tagCREATESTRUCTA v8; // [esp+8h] [ebp-58h] BYREF
  tagWNDCLASSA wndcls; // [esp+38h] [ebp-28h] BYREF

  ModuleState = AfxGetModuleState();
  IconW = LoadIconW(hInstance: ModuleState->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)nIDResource);
  if ( IconW != nullptr
    && (memset(dst: (unsigned __int8 *)&v8, value: 0, count: sizeof(v8)),
        v8.style = dwDefaultStyle,
        this->PreCreateWindow(this, a2: &v8),
        v8.lpszClass != nullptr)
    && (v6 = AfxGetModuleState(),
        AfxCtxGetClassInfoA(hInstance: v6->m_hCurrentInstanceHandle, lpClassName: v8.lpszClass, lpWndClass: &wndcls) != 0)
    && wndcls.hIcon != IconW )
  {
    return AfxRegisterWndClass(
             nClassStyle: wndcls.style,
             hCursor: wndcls.hCursor,
             hbrBackground: wndcls.hbrBackground,
             hIcon: IconW);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10341A6A
// Name: protected: void CFrameWnd::OnEnable(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnEnable(CFrameWnd *this, HWND__ *bEnable)
{
  HWND__ *v2; // ebx
  HWND Parent; // eax
  CWnd *v5; // eax
  CFrameWnd_vtbl *v6; // eax
  unsigned int m_nFlags; // eax
  HWND m_hWnd; // [esp-8h] [ebp-14h]

  v2 = bEnable;
  if ( bEnable != nullptr && (this->m_nFlags & 4) != 0 )
  {
    CWnd::EnableWindow(this, bEnable: 0);
    SetFocus(hWnd: nullptr);
  }
  else
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    v5 = CWnd::FromHandle(hWnd: Parent);
    if ( v5 == nullptr
      || (m_hWnd = v5->m_hWnd,
          bEnable = nullptr,
          GetWindowThreadProcessId(hWnd: m_hWnd, lpdwProcessId: (LPDWORD)&bEnable),
          (HWND__ *)GetCurrentProcessId() != bEnable) )
    {
      if ( v2 != nullptr )
      {
        m_nFlags = this->m_nFlags;
        if ( (m_nFlags & 0x80u) != 0 )
        {
          this->m_nFlags = m_nFlags & 0xFFFFFF7F;
          this->EndModalState(this);
          bEnable = this->m_hWnd;
          if ( GetActiveWindow() == bEnable )
            SendMessageA(hWnd: bEnable, Msg: 6u, wParam: 1u, lParam: 0);
        }
        if ( (this->m_nFlags & 0x20) != 0 )
          SendMessageA(hWnd: this->m_hWnd, Msg: 0x86u, wParam: 1u, lParam: 0);
      }
      else if ( this->m_cModalStack == 0 )
      {
        v6 = this->__vftable;
        this->m_nFlags |= 0x80u;
        v6->BeginModalState(this);
      }
      CFrameWnd::NotifyFloatingWindows(this, dwFlags: v2 != nullptr ? 16 : 32);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10341B4F
// Name: protected: int CFrameWnd::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::OnCreate(CFrameWnd *this, tagCREATESTRUCTA *lpcs)
{
  if ( lpcs == nullptr )
    AfxThrowInvalidArgException();
  return CFrameWnd::OnCreateHelper(this, lpcs, pContext: (CCreateContext *)lpcs->lpCreateParams);
}

//------------------------------------------------------------------------------
// Address: 0x10341B6C
// Name: protected: void CFrameWnd::OnEnterIdle(unsigned int,class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnEnterIdle(CFrameWnd *this, unsigned int nWhy, CWnd *pWho)
{
  CWnd::OnEnterIdle(this, __formal: nWhy, __formal: pWho);
  if ( nWhy == 2 && this->m_nIDTracking != this->m_nIDLastMessage )
    CFrameWnd::SetMessageText(this, nID: this->m_nIDTracking);
}

//------------------------------------------------------------------------------
// Address: 0x10341BA0
// Name: protected: void CFrameWnd::AddFrameWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::AddFrameWnd(CFrameWnd *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_THREAD_STATE *Data; // eax

  ModuleState = AfxGetModuleState();
  Data = CThreadLocal<AFX_MODULE_THREAD_STATE>::GetData(this: &ModuleState->m_thread);
  CSimpleList::AddHead(this: &Data->m_frameList, p: this);
}

//------------------------------------------------------------------------------
// Address: 0x10341BBD
// Name: protected: void CFrameWnd::RemoveFrameWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::RemoveFrameWnd(CFrameWnd *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_THREAD_STATE *Data; // eax

  ModuleState = AfxGetModuleState();
  Data = CThreadLocal<AFX_MODULE_THREAD_STATE>::GetData(this: &ModuleState->m_thread);
  CSimpleList::Remove(this: &Data->m_frameList, p: this);
}

//------------------------------------------------------------------------------
// Address: 0x10341BDA
// Name: protected: long CFrameWnd::OnSetMessageString(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CFrameWnd::OnSetMessageString(CFrameWnd *this, unsigned int wParam, char *lParam)
{
  unsigned int m_nIDLastMessage; // eax
  char *m_pszData; // ebx
  ATL::IAtlStringMgr *StringManager; // eax
  unsigned int v7; // edi
  CFrameWnd *ParentFrame; // eax
  unsigned int nIDLast; // [esp+10h] [ebp-18h]
  CWnd *pMessageBar; // [esp+14h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strMessage; // [esp+18h] [ebp-10h] BYREF
  int v13; // [esp+24h] [ebp-4h]

  m_nIDLastMessage = this->m_nIDLastMessage;
  this->m_nFlags &= ~0x40u;
  nIDLast = m_nIDLastMessage;
  m_pszData = nullptr;
  pMessageBar = this->GetMessageBar(this);
  if ( pMessageBar != nullptr )
  {
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strMessage, pStringMgr: StringManager);
    v7 = wParam;
    v13 = 0;
    if ( lParam != nullptr )
    {
      m_pszData = lParam;
    }
    else if ( wParam != 0 )
    {
      if ( wParam == 61190 && this->m_lpfnCloseProc != nullptr )
        v7 = 61445;
      this->GetMessageString(this, a2: v7, a3: &strMessage);
      m_pszData = strMessage.m_pszData;
    }
    CWnd::SetWindowTextA(this: pMessageBar, lpszString: m_pszData);
    ParentFrame = CWnd::GetParentFrame(this: pMessageBar);
    if ( ParentFrame != nullptr )
    {
      ParentFrame->m_nIDLastMessage = v7;
      ParentFrame->m_nIDTracking = v7;
    }
    ATL::CStringData::Release(this: (ATL::CStringData *)strMessage.m_pszData - 1);
  }
  else
  {
    v7 = wParam;
  }
  this->m_nIDLastMessage = v7;
  this->m_nIDTracking = v7;
  return nIDLast;
}

//------------------------------------------------------------------------------
// Address: 0x10341C98
// Name: public: void CFrameWnd::DestroyDockBars(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::DestroyDockBars(CFrameWnd *this)
{
  CPtrList::CNode *m_pNodeHead; // esi
  CFrameWnd **data; // edi
  int v3; // eax
  CList<HWND__ *,HWND__ *> *p_listDockBars; // ecx
  CList<HWND__ *,HWND__ *>::CNode *v5; // esi
  CWnd *v6; // eax
  CFrameWnd *ParentFrame; // eax
  CFrameWnd *v8; // ecx
  CList<HWND__ *,HWND__ *>::CNode *v9; // esi
  CWnd *v10; // eax
  CObject *v11; // eax
  HWND__ *v12; // [esp-4h] [ebp-58h]
  HWND__ *v13; // [esp-4h] [ebp-58h]
  CList<HWND__ *,HWND__ *> listDockBars; // [esp+10h] [ebp-44h] BYREF
  CList<HWND__ *,HWND__ *> listCtrlBars; // [esp+2Ch] [ebp-28h] BYREF
  int v16; // [esp+50h] [ebp-4h]

  listDockBars.__vftable = (CList<HWND__ *,HWND__ *>_vtbl *)&CList<HWND__ *,HWND__ *>::`vftable';
  memset(&listDockBars.m_pNodeHead, 0, 20);
  listDockBars.m_nBlockSize = 10;
  v16 = 0;
  listCtrlBars.__vftable = (CList<HWND__ *,HWND__ *>_vtbl *)&CList<HWND__ *,HWND__ *>::`vftable';
  memset(&listCtrlBars.m_pNodeHead, 0, 20);
  listCtrlBars.m_nBlockSize = 10;
  m_pNodeHead = this->m_listControlBars.m_pNodeHead;
  LOBYTE(v16) = 1;
  while ( m_pNodeHead != nullptr )
  {
    data = (CFrameWnd **)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    v3 = ((int (__thiscall *)(CFrameWnd **))(*data)[1].m_dwPromptContext)(a1: data);
    p_listDockBars = &listDockBars;
    if ( v3 == 0 )
      p_listDockBars = &listCtrlBars;
    CList<CFrameWnd *,CFrameWnd *>::AddTail(this: (CList<CFrameWnd *,CFrameWnd *> *)p_listDockBars, newElement: data[8]);
  }
  v5 = listDockBars.m_pNodeHead;
  while ( v5 != nullptr )
  {
    v12 = v5->data;
    v5 = v5->pNext;
    v6 = CWnd::FromHandlePermanent(hWnd: v12);
    ParentFrame = (CFrameWnd *)AfxDynamicDownCast(pClass: &CDockBar::classCDockBar, pObject: v6);
    if ( ParentFrame != nullptr )
    {
      v8 = ParentFrame;
      if ( ParentFrame->m_listControlBars.m_pBlocks != nullptr )
      {
        ParentFrame = CWnd::GetParentFrame(this: ParentFrame);
        if ( ParentFrame == nullptr )
          AfxThrowInvalidArgException();
        v8 = ParentFrame;
      }
      ParentFrame->DestroyWindow(this: v8);
    }
  }
  v9 = listCtrlBars.m_pNodeHead;
  while ( v9 != nullptr )
  {
    v13 = v9->data;
    v9 = v9->pNext;
    v10 = CWnd::FromHandlePermanent(hWnd: v13);
    v11 = AfxDynamicDownCast(pClass: &CControlBar::classCControlBar, pObject: v10);
    if ( v11 != nullptr )
      v11->__vftable[8].GetRuntimeClass(this: v11);
  }
  LOBYTE(v16) = 0;
  listCtrlBars.__vftable = (CList<HWND__ *,HWND__ *>_vtbl *)&CList<HWND__ *,HWND__ *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&listCtrlBars);
  v16 = -1;
  listDockBars.__vftable = (CList<HWND__ *,HWND__ *>_vtbl *)&CList<HWND__ *,HWND__ *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&listDockBars);
}

//------------------------------------------------------------------------------
// Address: 0x10341DAA
// Name: protected: int CFrameWnd::OnToolTipText(unsigned int,struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::OnToolTipText(CFrameWnd *this, unsigned int __formal, tagNMHDR *pNMHDR, int *pResult)
{
  ATL::IAtlStringMgr *StringManager; // eax
  unsigned int code; // ecx
  HWND idFrom; // eax
  int v8; // eax
  int v9; // eax
  ATL::CSimpleStringT<char,0> v10; // [esp+14h] [ebp-114h] BYREF
  char szBuf[268]; // [esp+18h] [ebp-110h] BYREF
  int v12; // [esp+124h] [ebp-4h]

  if ( pNMHDR == nullptr || pResult == nullptr )
    AfxThrowInvalidArgException();
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v10, pStringMgr: StringManager);
  code = pNMHDR->code;
  idFrom = (HWND)pNMHDR->idFrom;
  v12 = 0;
  if ( code == -520 && (pNMHDR[8].idFrom & 1) != 0 || code == -530 && ((int)pNMHDR[15].hwndFrom & 1) != 0 )
    idFrom = (HWND)GetDlgCtrlID(hWnd: idFrom);
  if ( idFrom != nullptr )
  {
    if ( AfxLoadString(nID: (unsigned int)idFrom, lpszBuf: szBuf, nMaxBuf: 0x100u) == 0 )
    {
      ATL::CStringData::Release(this: (ATL::CStringData *)v10.m_pszData - 1);
      return 0;
    }
    AfxExtractSubString(
      rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v10,
      lpszFullString: szBuf,
      iSubString: 1,
      chSep: 10);
  }
  if ( pNMHDR->code == -520 )
  {
    v8 = strncpy_s(_Dst: (char *)&pNMHDR[1].idFrom, _SizeInBytes: 0x50u, _Src: v10.m_pszData, _Count: 0xFFFFFFFF);
    AfxCrtErrorCheck(error: v8);
  }
  else
  {
    v9 = MultiByteToWideChar(
           CodePage: 3u,
           dwFlags: 0,
           lpMultiByteStr: v10.m_pszData,
           cbMultiByte: -1,
           lpWideCharStr: (LPWSTR)&pNMHDR[1].idFrom,
           cchWideChar: 80);
    if ( pNMHDR != (tagNMHDR *)-16 && v9 > 80 )
      ATL::AtlThrowImpl(hr: -2147467259);
    if ( v9 > 0 && pNMHDR != (tagNMHDR *)-16 )
      *((_WORD *)&pNMHDR[1].hwndFrom + v9 + 1) = 0;
  }
  *pResult = 0;
  SetWindowPos(hWnd: pNMHDR->hwndFrom, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: 0, cy: 0, uFlags: 0x213u);
  ATL::CStringData::Release(this: (ATL::CStringData *)v10.m_pszData - 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10341EF8
// Name: public: CFrameWnd::CFrameWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFrameWnd *__thiscall CFrameWnd::CFrameWnd(CFrameWnd *this)
{
  ATL::IAtlStringMgr *StringManager; // eax

  CWnd::CWnd(this);
  this->__vftable = (CFrameWnd_vtbl *)&CFrameWnd::`vftable';
  this->m_rectBorder.left = 0;
  this->m_rectBorder.top = 0;
  this->m_rectBorder.right = 0;
  this->m_rectBorder.bottom = 0;
  CPtrList::CPtrList(this: &this->m_listControlBars, nBlockSize: 10);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strTitle, pStringMgr: StringManager);
  this->m_nWindow = -1;
  this->m_bAutoMenuEnable = 1;
  this->m_lpfnCloseProc = nullptr;
  this->m_hMenuDefault = nullptr;
  this->m_hAccelTable = nullptr;
  this->m_nIDHelp = 0;
  this->m_nIDTracking = 0;
  this->m_nIDLastMessage = 0;
  this->m_pViewActive = nullptr;
  this->m_cModalStack = 0;
  this->m_phWndDisable = nullptr;
  this->m_pNotifyHook = nullptr;
  this->m_hMenuAlt = nullptr;
  this->m_nIdleFlags = 0;
  SetRectEmpty(lprc: &this->m_rectBorder);
  this->m_nShowDelay = -1;
  this->m_bHelpMode = 0;
  this->m_dwPromptContext = 0;
  this->m_pNextFrameWnd = nullptr;
  this->m_bInRecalcLayout = 0;
  this->m_pFloatingFrameClass = nullptr;
  this->m_dwMenuBarVisibility = 1;
  this->m_dwMenuBarState = 1;
  this->m_hMenu = nullptr;
  this->m_bTempShowMenu = 0;
  this->m_bMouseHitMenu = 0;
  this->m_nProgressBarRangeMin = 0;
  this->m_nProgressBarRangeMax = 100;
  CFrameWnd::AddFrameWnd(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1034200C
// Name: protected: void CFrameWnd::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnDestroy(CFrameWnd *this)
{
  HMENU__ *m_hMenuDefault; // edi
  CWinApp *m_pCurrentWinApp; // eax

  CFrameWnd::DestroyDockBars(this);
  if ( this->m_hMenuDefault != nullptr )
  {
    m_hMenuDefault = this->m_hMenuDefault;
    if ( GetMenu(hWnd: this->m_hWnd) != m_hMenuDefault )
      SetMenu(hWnd: this->m_hWnd, hMenu: m_hMenuDefault);
  }
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( m_pCurrentWinApp != nullptr
    && m_pCurrentWinApp->m_pMainWnd == this
    && m_pCurrentWinApp->m_eHelpType == afxWinHelp )
  {
    WinHelpA(hWndMain: this->m_hWnd, lpszHelp: nullptr, uCommand: 2u, dwData: 0);
  }
  CWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x10342066
// Name: public: virtual void CFrameWnd::GetMessageString(unsigned int,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::GetMessageString(
        CFrameWnd *this,
        unsigned int nID,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *rMessage)
{
  unsigned __int8 *v3; // esi
  const unsigned __int8 *v4; // eax

  v3 = (unsigned __int8 *)ATL::CSimpleStringT<char,0>::PrepareWrite(this: rMessage, nLength: 255);
  if ( AfxLoadString(nID, lpszBuf: (char *)v3, nMaxBuf: 0x100u) != 0 )
  {
    v4 = _mbschr(string: v3, c: 0xAu);
    if ( v4 != nullptr )
      *v4 = 0;
  }
  ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: rMessage, nNewLength: -1);
}

//------------------------------------------------------------------------------
// Address: 0x103420AD
// Name: public: static class CObject __near * CFrameWnd::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFrameWnd *__stdcall CFrameWnd::CreateObject()
{
  CFrameWnd *v0; // ecx
  CFrameWnd *result; // eax

  v0 = (CFrameWnd *)operator new(nSize: 0x110u);
  result = nullptr;
  if ( v0 != nullptr )
    return CFrameWnd::CFrameWnd(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103420DD
// Name: public: virtual CFrameWnd::~CFrameWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CFrameWnd::~CFrameWnd(CFrameWnd *this)
{
  _AFX_THREAD_STATE *i; // edi

  this->__vftable = (CFrameWnd_vtbl *)&CFrameWnd::`vftable';
  CFrameWnd::RemoveFrameWnd(this);
  for ( i = AfxGetThreadState(); i->m_pRoutingFrame == this; CPushRoutingFrame::Pop(this: i->m_pPushRoutingFrame) )
    ;
  if ( this->m_phWndDisable != nullptr )
    operator delete(p: this->m_phWndDisable);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strTitle.m_pszData - 1);
  CPtrList::~CPtrList(this: &this->m_listControlBars);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x10342228
// Name: public: virtual int CFrameWnd::LoadFrame(unsigned int,unsigned long,class CWnd __near *,struct CCreateContext __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::LoadFrame(
        CFrameWnd *this,
        const char *nIDResource,
        unsigned int dwDefaultStyle,
        CWnd *pParentWnd,
        CCreateContext *pContext)
{
  unsigned int v6; // edi
  ATL::IAtlStringMgr *StringManager; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  const char *v9; // ebx
  int v10; // esi
  HMENU__ *Menu; // eax
  const char *lpszClass; // [esp+14h] [ebp-10h]

  v6 = (unsigned int)nIDResource;
  this->m_nIDHelp = (unsigned int)nIDResource;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
    this: (ATL::CSimpleStringT<char,0> *)&nIDResource,
    pStringMgr: StringManager);
  StringResourceHandle = AfxFindStringResourceHandle(__formal: v6);
  if ( StringResourceHandle != nullptr
    && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
         this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&nIDResource,
         hInstance: StringResourceHandle,
         nID: v6) != 0 )
  {
    AfxExtractSubString(rString: &this->m_strTitle, lpszFullString: nIDResource, iSubString: 0, chSep: 10);
  }
  AfxEndDeferRegisterClass(fToRegister: 8);
  lpszClass = CFrameWnd::GetIconWndClass(this, dwDefaultStyle, nIDResource: v6);
  v9 = (const char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)this->m_strTitle.m_pszData - 1)[1];
  if ( this->Create(
         this,
         a2: lpszClass,
         a3: v9,
         a4: dwDefaultStyle,
         a5: &CFrameWnd::rectDefault,
         a6: pParentWnd,
         a7: (const char *)(unsigned __int16)v6,
         a8: 0,
         a9: pContext) != 0 )
  {
    if ( this->m_dwMenuBarState == 1 )
      Menu = GetMenu(hWnd: this->m_hWnd);
    else
      Menu = this->m_hMenu;
    this->m_hMenuDefault = Menu;
    CFrameWnd::LoadAccelTable(this, lpszResourceName: (const char *)(unsigned __int16)v6);
    if ( pContext == nullptr )
      CWnd::SendMessageToDescendants(hWnd: this->m_hWnd, message: 0x364u, wParam: 0, lParam: 0, bDeep: 1, bOnlyPerm: 1);
    v10 = 1;
  }
  else
  {
    v10 = 0;
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)v9 - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)nIDResource - 1);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10342334
// Name: public: virtual CChevronOwnerDrawMenu::~CChevronOwnerDrawMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CChevronOwnerDrawMenu::~CChevronOwnerDrawMenu(CChevronOwnerDrawMenu *this)
{
  CFont *p_m_MenuFont; // ecx

  p_m_MenuFont = &this->m_MenuFont;
  p_m_MenuFont->__vftable = (CFont_vtbl *)&CFont::`vftable';
  CGdiObject::~CGdiObject(this: p_m_MenuFont);
  this->__vftable = (CChevronOwnerDrawMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034236E
// Name: public: virtual int CFrameWnd::Create(char const __near *,char const __near *,unsigned long,struct tagRECT const __near &,class CWnd __near *,char const __near *,unsigned long,struct CCreateContext __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::Create(
        CFrameWnd *this,
        const char *lpszClassName,
        const char *lpszWindowName,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        const char *lpszMenuName,
        unsigned int dwExStyle,
        CCreateContext *pContext)
{
  AFX_MODULE_STATE *ModuleState; // eax
  HMENU__ *hMenu; // [esp+8h] [ebp-4h]
  HWND__ *lpszMenuNamea; // [esp+28h] [ebp+1Ch]

  hMenu = nullptr;
  if ( lpszMenuName != nullptr )
  {
    ModuleState = AfxGetModuleState();
    hMenu = LoadMenuA(hInstance: ModuleState->m_hCurrentResourceHandle, lpMenuName: lpszMenuName);
    if ( hMenu == nullptr )
    {
      this->PostNcDestroy(this);
      return 0;
    }
  }
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strTitle, pszSrc: lpszWindowName);
  if ( pParentWnd != nullptr )
    lpszMenuNamea = pParentWnd->m_hWnd;
  else
    lpszMenuNamea = nullptr;
  if ( this->CreateEx_2(
         this,
         a2: dwExStyle,
         a3: lpszClassName,
         a4: lpszWindowName,
         a5: dwStyle,
         a6: rect->left,
         a7: rect->top,
         a8: rect->right - rect->left,
         a9: rect->bottom - rect->top,
         a10: lpszMenuNamea,
         a11: hMenu,
         a12: pContext) == 0 )
  {
    if ( hMenu != nullptr )
      DestroyMenu(hMenu);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1034241A
// Name: protected: long CFrameWnd::OnDDEExecute(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::OnDDEExecute(CFrameWnd *this, HWND wParam, LPARAM lParam)
{
  const char *v3; // esi
  ATL::IAtlStringMgr *StringManager; // eax
  LPARAM v5; // eax
  CWnd *v6; // edi
  ATL::CStringData *v7; // ecx
  char *m_pszData; // esi
  AFX_MODULE_STATE *ModuleState; // eax
  unsigned int unused; // [esp+14h] [ebp-20h] BYREF
  CWnd *v12; // [esp+18h] [ebp-1Ch]
  void *hData; // [esp+1Ch] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strCommand; // [esp+20h] [ebp-14h] BYREF
  int v15; // [esp+30h] [ebp-4h]

  v12 = this;
  UnpackDDElParam(msg: 0x3E8u, lParam, puiLo: &unused, puiHi: (PUINT_PTR)&hData);
  v3 = (const char *)GlobalLock(hMem: hData);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strCommand, pStringMgr: StringManager);
  v15 = 1;
  ATL::CSimpleStringT<char,0>::SetString(this: &strCommand, pszSrc: v3);
  GlobalUnlock(hMem: hData);
  v15 = 0;
  v5 = ReuseDDElParam(lParam, msgIn: 0x3E8u, msgOut: 0x3E4u, uiLo: 0x8000u, uiHi: (UINT_PTR)hData);
  v6 = v12;
  PostMessageA(hWnd: wParam, Msg: 0x3E4u, wParam: (WPARAM)v12->m_hWnd, lParam: v5);
  if ( CWnd::IsWindowEnabled(this: v6) != 0 )
  {
    m_pszData = strCommand.m_pszData;
    if ( *((int *)strCommand.m_pszData - 1) > 1 )
    {
      ATL::CSimpleStringT<char,0>::Fork(this: &strCommand, nLength: *((_DWORD *)strCommand.m_pszData - 3));
      m_pszData = strCommand.m_pszData;
    }
    ModuleState = AfxGetModuleState();
    ModuleState->m_pCurrentWinApp->OnDDECommand(this: ModuleState->m_pCurrentWinApp, a2: m_pszData);
    ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: &strCommand, nNewLength: -1);
    v7 = (ATL::CStringData *)(m_pszData - 16);
  }
  else
  {
    v7 = (ATL::CStringData *)(strCommand.m_pszData - 16);
  }
  ATL::CStringData::Release(this: v7);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10342519
// Name: protected: int CFrameWnd::OnChevronPushed(unsigned int,struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::OnChevronPushed(CFrameWnd *this, unsigned int id, tagNMHDR *pnm, int *pResult)
{
  ATL::IAtlStringMgr *StringManager; // eax
  int v5; // edi
  CHAR *v6; // eax
  CWnd *v7; // edi
  CFrameWnd *ParentFrame; // eax
  int v9; // esi
  ATL::IAtlStringMgr *v11; // eax
  ATL::IAtlStringMgr *v12; // eax
  CHAR *v13; // eax
  CToolBarCtrl *v14; // esi
  HMENU PopupMenu; // eax
  HDC CompatibleDC; // eax
  int v17; // esi
  unsigned int v18; // edi
  HINSTANCE__ *StringResourceHandle; // eax
  _DWORD *v20; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  HBITMAP CompatibleBitmap; // eax
  CObject *v23; // eax
  CObject_vtbl *v24; // eax
  CGdiObject *v25; // eax
  DWORD SysColor; // eax
  CObject *v27; // eax
  CObject_vtbl *v28; // eax
  CGdiObject *v29; // eax
  int v30; // edi
  CObject *v31; // ecx
  HWND m_hWnd; // [esp-10h] [ebp-1B4h]
  struct _IMAGELIST *v33; // [esp-Ch] [ebp-1B0h]
  HWND__ *hwndFrom; // [esp-8h] [ebp-1ACh]
  int v35; // [esp-8h] [ebp-1ACh]
  tagMENUITEMINFOA dst; // [esp+10h] [ebp-194h] BYREF
  CClientDC v37; // [esp+40h] [ebp-164h] BYREF
  CChevronOwnerDrawMenu v38; // [esp+54h] [ebp-150h] BYREF
  CDC v39; // [esp+64h] [ebp-140h] BYREF
  RECT *lprcSrc; // [esp+74h] [ebp-130h]
  unsigned int nStyle; // [esp+78h] [ebp-12Ch] BYREF
  CGdiObject *v42; // [esp+7Ch] [ebp-128h]
  int *pResulta; // [esp+80h] [ebp-124h]
  int iImage; // [esp+84h] [ebp-120h] BYREF
  unsigned int nID; // [esp+88h] [ebp-11Ch] BYREF
  CObArray v46; // [esp+8Ch] [ebp-118h] BYREF
  CObject *v47; // [esp+A0h] [ebp-104h]
  CWnd *pWnd; // [esp+A4h] [ebp-100h]
  ATL::CSimpleStringT<char,0> v49; // [esp+A8h] [ebp-FCh] BYREF
  int nMaxCount; // [esp+ACh] [ebp-F8h]
  ATL::CSimpleStringT<char,0> v51; // [esp+B0h] [ebp-F4h] BYREF
  CWnd *v52; // [esp+B4h] [ebp-F0h]
  ATL::CSimpleStringT<char,0> v53; // [esp+B8h] [ebp-ECh] BYREF
  WPARAM wParam; // [esp+BCh] [ebp-E8h]
  LPARAM lParam[8]; // [esp+C0h] [ebp-E4h] BYREF
  HWND hWnd; // [esp+E0h] [ebp-C4h]
  _IMAGEINFO pImageInfo; // [esp+124h] [ebp-80h] BYREF
  tagRECT Rect; // [esp+144h] [ebp-60h] BYREF
  tagRECT rcDst; // [esp+154h] [ebp-50h] BYREF
  RECT v60; // [esp+164h] [ebp-40h] BYREF
  tagRECT rc; // [esp+174h] [ebp-30h] BYREF
  tagRECT v62; // [esp+184h] [ebp-20h] BYREF
  int v63; // [esp+1A0h] [ebp-4h]

  pWnd = this;
  pResulta = pResult;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v53, pStringMgr: StringManager);
  v63 = 0;
  v5 = lstrlenA(lpString: "ReBarWindow32") + 1;
  v6 = ATL::CSimpleStringT<char,0>::PrepareWrite(this: &v53, nLength: v5);
  GetClassNameA(hWnd: pnm->hwndFrom, lpClassName: v6, nMaxCount: v5);
  ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: &v53, nNewLength: -1);
  v7 = CWnd::FromHandlePermanent(hWnd: pnm->hwndFrom);
  v52 = v7;
  if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
         this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v53,
         psz: "ReBarWindow32") != 0
    || v7 == nullptr
    || CObject::IsKindOf(this: v7, pClass: &CReBar::classCReBar) == 0 )
  {
    goto LABEL_55;
  }
  ParentFrame = CWnd::GetParentFrame(this: v7);
  if ( ParentFrame != nullptr && pWnd != ParentFrame )
  {
    v9 = CFrameWnd::OnChevronPushed(this: ParentFrame, id, pnm, pResult: pResulta);
    goto LABEL_7;
  }
  memset(&v62, 0, sizeof(v62));
  memset(&v60, 0, sizeof(v60));
  memset(&rcDst, 0, sizeof(rcDst));
  CChevronOwnerDrawMenu::CChevronOwnerDrawMenu(this: &v38);
  LOBYTE(v63) = 1;
  v11 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v49, pStringMgr: v11);
  LOBYTE(v63) = 2;
  v12 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v51, pStringMgr: v12);
  LOBYTE(v63) = 3;
  CDC::CDC(this: &v39);
  LOBYTE(v63) = 4;
  CClientDC::CClientDC(this: &v37, pWnd);
  lParam[0] = v7[1].m_ulGestureArg;
  hwndFrom = pnm[1].hwndFrom;
  m_hWnd = v7->m_hWnd;
  LOBYTE(v63) = 5;
  lParam[1] = 16;
  SendMessageA(hWnd: m_hWnd, Msg: 0x41Du, wParam: (WPARAM)hwndFrom, (LPARAM)lParam);
  SendMessageA(hWnd: v52->m_hWnd, Msg: 0x409u, wParam: (WPARAM)pnm[1].hwndFrom, lParam: (LPARAM)&v62);
  nMaxCount = lstrlenA(lpString: "ToolbarWindow32") + 1;
  v13 = ATL::CSimpleStringT<char,0>::PrepareWrite(this: &v53, nLength: nMaxCount);
  GetClassNameA(hWnd, lpClassName: v13, nMaxCount);
  ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: &v53, nNewLength: -1);
  v47 = CWnd::FromHandlePermanent(hWnd);
  if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
         this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v53,
         psz: "ToolbarWindow32") != 0
    || v47 == nullptr
    || CObject::IsKindOf(this: v47, pClass: &CToolBar::classCToolBar) == 0 )
  {
    LOBYTE(v63) = 4;
    CClientDC::~CClientDC(this: &v37);
    LOBYTE(v63) = 3;
    CDC::~CDC(this: &v39);
    ATL::CStringData::Release(this: (ATL::CStringData *)v51.m_pszData - 1);
    ATL::CStringData::Release(this: (ATL::CStringData *)v49.m_pszData - 1);
    LOBYTE(v63) = 0;
    CChevronOwnerDrawMenu::~CChevronOwnerDrawMenu(this: &v38);
LABEL_55:
    ATL::CStringData::Release(this: (ATL::CStringData *)v53.m_pszData - 1);
    return 0;
  }
  v62.right = (int)pnm[2].hwndFrom;
  lprcSrc = (RECT *)&pnm[2];
  CWnd::ClientToScreen(this: v52, lpRect: &v62);
  v14 = (CToolBarCtrl *)v47;
  CWnd::ScreenToClient(this: (CWnd *)v47, lpRect: &v62);
  v52 = (CWnd *)SendMessageA(hWnd: v14->m_hWnd, Msg: 0x418u, wParam: 0, lParam: 0);
  wParam = (WPARAM)v52;
  do
    SendMessageA(hWnd: v14->m_hWnd, Msg: 0x41Du, wParam: --wParam, lParam: (LPARAM)&v60);
  while ( !IntersectRect(lprcDst: &rcDst, lprcSrc1: &v62, lprcSrc2: &v60) && wParam != 0 );
  memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst));
  dst.cbSize = 48;
  nMaxCount = (int)CToolBarCtrl::GetImageList(this: v14);
  CObArray::CObArray(this: &v46);
  v46.__vftable = (CObArray_vtbl *)&CTypedPtrArray<CObArray,CBitmap *>::`vftable';
  LOBYTE(v63) = 6;
  CUIntArray::SetSize(this: (CPtrArray *)&v46, nNewSize: (int)v52 - wParam, nGrowBy: -1);
  PopupMenu = CreatePopupMenu();
  CMenu::Attach(this: &v38, hMenu: PopupMenu);
  CompatibleDC = CreateCompatibleDC(hdc: v37.m_hDC);
  CDC::Attach(this: &v39, hDC: CompatibleDC);
  v17 = 0;
  while ( wParam < (unsigned int)v52 )
  {
    CToolBar::GetButtonInfo(this: (CToolBar *)v47, nIndex: wParam, &nID, &nStyle, &iImage);
    if ( (nStyle & 1) != 0 )
    {
      if ( v17 == 0 )
        goto LABEL_44;
      dst.fMask = 256;
      dst.fType = 2048;
    }
    else
    {
      v18 = nID;
      dst.fMask = 354;
      StringResourceHandle = AfxFindStringResourceHandle(__formal: nID);
      if ( StringResourceHandle != nullptr
        && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
             this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v49,
             hInstance: StringResourceHandle,
             nID: v18) != 0 )
      {
        AfxExtractSubString(
          rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v51,
          lpszFullString: v49.m_pszData,
          iSubString: 1,
          chSep: 10);
      }
      else
      {
        ATL::CSimpleStringT<char,0>::Empty(this: &v51);
      }
      v20 = operator new(nSize: 8u);
      if ( v20 != nullptr )
      {
        v20[1] = 0;
        *v20 = &CBitmap::`vftable';
      }
      else
      {
        v20 = nullptr;
      }
      CUIntArray::SetAtGrow(this: (CPtrArray *)&v46, nIndex: v17, newElement: v20);
      if ( nMaxCount != 0
        && (v35 = iImage,
            v33 = *(struct _IMAGELIST **)(nMaxCount + 4),
            ModuleState = AfxGetModuleState(),
            CComCtlWrapper::_ImageList_GetImageInfo(
              this: *(CComCtlWrapper **)ModuleState->m_pDllIsolationWrappers,
              himl: v33,
              i: v35,
              &pImageInfo) != 0) )
      {
        CopyRect(lprcDst: &rc, lprcSrc: &pImageInfo.rcImage);
        OffsetRect(lprc: &rc, dx: -rc.left, dy: -rc.top);
        if ( v17 < 0 )
          goto LABEL_53;
        if ( v17 >= v46.m_nSize )
          goto LABEL_53;
        v42 = (CGdiObject *)v46.m_pData[v17];
        CompatibleBitmap = CreateCompatibleBitmap(hdc: v37.m_hDC, cx: rc.right, cy: rc.bottom);
        CGdiObject::Attach(this: v42, hObject: CompatibleBitmap);
        if ( v17 >= v46.m_nSize )
          goto LABEL_53;
        v23 = v46.m_pData[v17];
        v24 = v23 != nullptr ? v23[1].__vftable : nullptr;
        v25 = CDC::SelectGdiObject(hDC: v39.m_hDC, h: v24);
        if ( v17 >= v46.m_nSize )
          goto LABEL_53;
        v46.m_pData[v17] = v25;
        SysColor = GetSysColor(nIndex: 4);
        CDC::FillSolidRect(this: &v39, lpRect: &rc, clr: SysColor);
        AfxImageList_Draw(
          himl: *(struct _IMAGELIST **)(nMaxCount + 4),
          i: iImage,
          hdcDst: v39.m_hDC,
          x: 0,
          y: 0,
          fStyle: 1u);
        if ( v17 >= v46.m_nSize )
          goto LABEL_53;
        v27 = v46.m_pData[v17];
        v28 = v27 != nullptr ? v27[1].__vftable : nullptr;
        v29 = CDC::SelectGdiObject(hDC: v39.m_hDC, h: v28);
        if ( v17 >= v46.m_nSize )
          goto LABEL_53;
        v46.m_pData[v17] = v29;
        if ( v17 >= v46.m_nSize )
          goto LABEL_53;
        dst.dwItemData = (unsigned int)v46.m_pData[v17];
      }
      else
      {
        dst.dwItemData = 0;
      }
      dst.dwTypeData = v51.m_pszData;
      dst.wID = nID;
      dst.fType = 256;
      ++v17;
    }
    InsertMenuItemA(hmenu: v38.m_hMenu, item: wParam, fByPosition: true, lpmi: &dst);
LABEL_44:
    ++wParam;
  }
  CopyRect(lprcDst: &Rect, lprcSrc);
  CWnd::ClientToScreen(this: pWnd, lpRect: &Rect);
  CMenu::TrackPopupMenu(this: &v38, nFlags: 0, x: Rect.left, y: Rect.bottom, pWnd, lpRect: nullptr);
  v30 = 0;
  *pResulta = 0;
  if ( v17 != 0 )
  {
    while ( v30 >= 0 && v30 < v46.m_nSize )
    {
      v31 = v46.m_pData[v30];
      if ( v31 != nullptr )
        ((void (__thiscall *)(CObject *, int))v31->dtr_CObject)(a1: v31, a2: 1);
      if ( ++v30 >= (unsigned int)v17 )
        goto LABEL_52;
    }
LABEL_53:
    AfxThrowInvalidArgException();
  }
LABEL_52:
  LOBYTE(v63) = 5;
  CObArray::~CObArray(this: &v46);
  LOBYTE(v63) = 4;
  CClientDC::~CClientDC(this: &v37);
  LOBYTE(v63) = 3;
  CDC::~CDC(this: &v39);
  ATL::CStringData::Release(this: (ATL::CStringData *)v51.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)v49.m_pszData - 1);
  LOBYTE(v63) = 0;
  CChevronOwnerDrawMenu::~CChevronOwnerDrawMenu(this: &v38);
  v9 = 1;
LABEL_7:
  ATL::CStringData::Release(this: (ATL::CStringData *)v53.m_pszData - 1);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10342C1A
// Name: public: void CFrameWnd::UpdateFrameTitleForDocument(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::UpdateFrameTitleForDocument(CFrameWnd *this, char *lpszDocName)
{
  ATL::IAtlStringMgr *StringManager; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  char *m_pszData; // esi
  ATL::CSimpleStringT<char,0> v9; // [esp+10h] [ebp-34h] BYREF
  char string[44]; // [esp+14h] [ebp-30h] BYREF
  int v11; // [esp+40h] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v9, pStringMgr: StringManager);
  v11 = 0;
  if ( (CWnd::GetStyle(this) & 0x4000) != 0 )
  {
    if ( lpszDocName != nullptr )
    {
      ATL::CSimpleStringT<char,0>::Append(this: &v9, pszSrc: lpszDocName);
      if ( this->m_nWindow > 0 )
      {
        sprintf_s(string, sizeInBytes: 0x20u, format: ":%d", this->m_nWindow);
        strlen(buf: (unsigned __int8 *)string);
        ATL::CSimpleStringT<char,0>::Append(this: &v9, pszSrc: string, nLength: v4);
      }
      strlen(buf: " - ");
      ATL::CSimpleStringT<char,0>::Append(this: &v9, pszSrc: " - ", nLength: v5);
    }
    ATL::CSimpleStringT<char,0>::Append(
      this: &v9,
      pszSrc: this->m_strTitle.m_pszData,
      nLength: *((_DWORD *)this->m_strTitle.m_pszData - 3));
  }
  else
  {
    ATL::CSimpleStringT<char,0>::Append(
      this: &v9,
      pszSrc: this->m_strTitle.m_pszData,
      nLength: *((_DWORD *)this->m_strTitle.m_pszData - 3));
    if ( lpszDocName != nullptr )
    {
      strlen(buf: " - ");
      ATL::CSimpleStringT<char,0>::Append(this: &v9, pszSrc: " - ", nLength: v6);
      ATL::CSimpleStringT<char,0>::Append(this: &v9, pszSrc: lpszDocName);
      if ( this->m_nWindow > 0 )
      {
        sprintf_s(string, sizeInBytes: 0x20u, format: ":%d", this->m_nWindow);
        strlen(buf: (unsigned __int8 *)string);
        ATL::CSimpleStringT<char,0>::Append(this: &v9, pszSrc: string, nLength: v7);
      }
    }
  }
  m_pszData = v9.m_pszData;
  AfxSetWindowText(hWndCtrl: this->m_hWnd, lpszNew: v9.m_pszData);
  ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x10342D2C
// Name: protected: virtual struct AFX_MSGMAP const __near * CFrameWnd::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CFrameWnd::GetMessageMap(CFrameWnd *this)
{
  return &messageMap_13;
}

//------------------------------------------------------------------------------
// Address: 0x10342D32
// Name: public: virtual void CFrameWnd::OnUpdateFrameTitle(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnUpdateFrameTitle(CFrameWnd *this, int bAddToTitle)
{
  CDocument *v3; // eax

  if ( (CWnd::GetStyle(this) & 0x8000) != 0
    && (this->m_pNotifyHook == nullptr || this->m_pNotifyHook->OnUpdateFrameTitle(this: this->m_pNotifyHook) == 0) )
  {
    v3 = this->GetActiveDocument(this);
    if ( bAddToTitle != 0 && v3 != nullptr )
      CFrameWnd::UpdateFrameTitleForDocument(this, lpszDocName: v3->m_strTitle.m_pszData);
    else
      CFrameWnd::UpdateFrameTitleForDocument(this, lpszDocName: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10342D87
// Name: public: AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(AFX_MAINTAIN_STATE2 *this)
{
  if ( this->m_bValidActCtxCookie != 0 )
    DeactivateActCtx(dwFlags: 0, ulCookie: this->m_ulActCtxCookie);
}

//------------------------------------------------------------------------------
// Address: 0x10342D98
// Name: public: CThreadLocal<class AFX_MODULE_THREAD_STATE>::~CThreadLocal<class AFX_MODULE_THREAD_STATE>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CThreadLocal<AFX_MODULE_THREAD_STATE>::~CThreadLocal<AFX_MODULE_THREAD_STATE>(
        CThreadLocal<AFX_MODULE_THREAD_STATE> *this)
{
  CThreadLocalObject::~CThreadLocalObject(this);
}

//------------------------------------------------------------------------------
// Address: 0x10342D9D
// Name: public: void AFX_MODULE_STATE::CreateActivationContext(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall AFX_MODULE_STATE::CreateActivationContext(AFX_MODULE_STATE *this)
{
  HMODULE m_hCurrentInstanceHandle; // edi
  HANDLE v3; // eax
  HANDLE v4; // eax
  tagACTCTXW actCtx; // [esp+8h] [ebp-230h] BYREF
  wchar_t rgchFullModulePath[262]; // [esp+28h] [ebp-210h] BYREF

  rgchFullModulePath[261] = 0;
  rgchFullModulePath[260] = 0;
  m_hCurrentInstanceHandle = this->m_hCurrentInstanceHandle;
  if ( GetModuleFileNameW(hModule: m_hCurrentInstanceHandle, lpFilename: rgchFullModulePath, nSize: 0x105u) != 0 )
  {
    if ( rgchFullModulePath[260] != 0 )
    {
      SetLastError(dwErrCode: 0x6Fu);
    }
    else
    {
      actCtx.lpSource = rgchFullModulePath;
      actCtx.hModule = m_hCurrentInstanceHandle;
      actCtx.cbSize = 32;
      actCtx.dwFlags = 136;
      actCtx.lpResourceName = (const wchar_t *)2;
      v3 = CreateActCtxW(pActCtx: &actCtx);
      this->m_hActCtx = v3;
      if ( v3 == (HANDLE)-1 )
      {
        actCtx.lpResourceName = (const wchar_t *)3;
        this->m_hActCtx = CreateActCtxW(pActCtx: &actCtx);
      }
      if ( this->m_hActCtx == (void *)-1 )
      {
        actCtx.lpResourceName = (const wchar_t *)1;
        v4 = CreateActCtxW(pActCtx: &actCtx);
        this->m_hActCtx = v4;
        if ( v4 == (HANDLE)-1 )
          this->m_hActCtx = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10342E91
// Name: public: void CTypeLibCache::Unlock(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CTypeLibCache::Unlock(CTypeLibCache *this)
{
  ITypeInfo *m_ptinfo; // eax
  ITypeLib *m_ptlib; // eax

  if ( InterlockedDecrement(lpAddend: &this->m_cRef) == 0 )
  {
    m_ptinfo = this->m_ptinfo;
    if ( m_ptinfo != nullptr )
    {
      m_ptinfo->Release(this: this->m_ptinfo);
      this->m_ptinfo = nullptr;
    }
    m_ptlib = this->m_ptlib;
    if ( m_ptlib != nullptr )
    {
      m_ptlib->Release(this: this->m_ptlib);
      this->m_ptlib = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10342EC8
// Name: int AfxGetPerUserRegistration(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxGetPerUserRegistration()
{
  return _afxRedirectRegistration;
}

//------------------------------------------------------------------------------
// Address: 0x10342ECE
// Name: public: _AFX_THREAD_STATE::_AFX_THREAD_STATE(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_AFX_THREAD_STATE *__thiscall _AFX_THREAD_STATE::_AFX_THREAD_STATE(_AFX_THREAD_STATE *this)
{
  this->__vftable = (_AFX_THREAD_STATE_vtbl *)&_AFX_THREAD_STATE::`vftable';
  this->m_msgCur.message = 0;
  this->m_nMsgLast = 0;
  this->m_ptCursorLast.x = 0;
  this->m_ptCursorLast.y = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10342EE7
// Name: public: virtual _AFX_THREAD_STATE::~_AFX_THREAD_STATE(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall _AFX_THREAD_STATE::~_AFX_THREAD_STATE(_AFX_THREAD_STATE *this)
{
  HHOOK__ *m_hHookOldMsgFilter; // eax
  void *m_pSafetyPoolBuffer; // esi

  m_hHookOldMsgFilter = this->m_hHookOldMsgFilter;
  this->__vftable = (_AFX_THREAD_STATE_vtbl *)&_AFX_THREAD_STATE::`vftable';
  if ( m_hHookOldMsgFilter != nullptr )
    UnhookWindowsHookEx(hhk: m_hHookOldMsgFilter);
  if ( this->m_hHookOldCbtFilter != nullptr )
    UnhookWindowsHookEx(hhk: this->m_hHookOldCbtFilter);
  m_pSafetyPoolBuffer = this->m_pSafetyPoolBuffer;
  if ( m_pSafetyPoolBuffer != nullptr )
    free(pMem: m_pSafetyPoolBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x10342F1E
// Name: public: virtual AFX_MODULE_THREAD_STATE::~AFX_MODULE_THREAD_STATE(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall AFX_MODULE_THREAD_STATE::~AFX_MODULE_THREAD_STATE(AFX_MODULE_THREAD_STATE *this)
{
  CToolTipCtrl *m_pToolTip; // ecx
  CHandleMap *m_pmapHWND; // ecx
  CHandleMap *m_pmapHMENU; // ecx
  CHandleMap *m_pmapHDC; // ecx
  CHandleMap *m_pmapHGDIOBJ; // ecx
  CHandleMap *m_pmapHIMAGELIST; // ecx
  CPtrList *m_plistSocketNotifications; // eax
  CObject *v9; // eax
  CMapPtrToPtr *m_pmapSocketHandle; // ecx
  CMapPtrToPtr *m_pmapDeadSockets; // ecx
  CPtrList *v12; // ecx

  m_pToolTip = this->m_pToolTip;
  this->__vftable = (AFX_MODULE_THREAD_STATE_vtbl *)&AFX_MODULE_THREAD_STATE::`vftable';
  if ( m_pToolTip != nullptr )
    m_pToolTip->DestroyToolTipCtrl(this: m_pToolTip);
  operator delete(p: this->m_pLastInfo);
  m_pmapHWND = this->m_pmapHWND;
  if ( m_pmapHWND != nullptr )
    ((void (__thiscall *)(CHandleMap *, int))m_pmapHWND->dtr_CHandleMap)(a1: m_pmapHWND, a2: 1);
  m_pmapHMENU = this->m_pmapHMENU;
  if ( m_pmapHMENU != nullptr )
    ((void (__thiscall *)(CHandleMap *, int))m_pmapHMENU->dtr_CHandleMap)(a1: m_pmapHMENU, a2: 1);
  m_pmapHDC = this->m_pmapHDC;
  if ( m_pmapHDC != nullptr )
    ((void (__thiscall *)(CHandleMap *, int))m_pmapHDC->dtr_CHandleMap)(a1: m_pmapHDC, a2: 1);
  m_pmapHGDIOBJ = this->m_pmapHGDIOBJ;
  if ( m_pmapHGDIOBJ != nullptr )
    ((void (__thiscall *)(CHandleMap *, int))m_pmapHGDIOBJ->dtr_CHandleMap)(a1: m_pmapHGDIOBJ, a2: 1);
  m_pmapHIMAGELIST = this->m_pmapHIMAGELIST;
  if ( m_pmapHIMAGELIST != nullptr )
    ((void (__thiscall *)(CHandleMap *, int))m_pmapHIMAGELIST->dtr_CHandleMap)(a1: m_pmapHIMAGELIST, a2: 1);
  m_plistSocketNotifications = this->m_plistSocketNotifications;
  if ( m_plistSocketNotifications != nullptr )
  {
    while ( m_plistSocketNotifications->m_nCount != 0 )
    {
      v9 = CObList::RemoveHead(this: (CObList *)this->m_plistSocketNotifications);
      operator delete(p: v9);
      m_plistSocketNotifications = this->m_plistSocketNotifications;
    }
  }
  m_pmapSocketHandle = this->m_pmapSocketHandle;
  if ( m_pmapSocketHandle != nullptr )
    ((void (__thiscall *)(CMapPtrToPtr *, int))m_pmapSocketHandle->dtr_CObject)(a1: m_pmapSocketHandle, a2: 1);
  m_pmapDeadSockets = this->m_pmapDeadSockets;
  if ( m_pmapDeadSockets != nullptr )
    ((void (__thiscall *)(CMapPtrToPtr *, int))m_pmapDeadSockets->dtr_CObject)(a1: m_pmapDeadSockets, a2: 1);
  v12 = this->m_plistSocketNotifications;
  if ( v12 != nullptr )
    ((void (__thiscall *)(CPtrList *, int))v12->dtr_CObject)(a1: v12, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10342FEC
// Name: public: AFX_MODULE_THREAD_STATE::AFX_MODULE_THREAD_STATE(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
AFX_MODULE_THREAD_STATE *__thiscall AFX_MODULE_THREAD_STATE::AFX_MODULE_THREAD_STATE(AFX_MODULE_THREAD_STATE *this)
{
  this->__vftable = (AFX_MODULE_THREAD_STATE_vtbl *)&AFX_MODULE_THREAD_STATE::`vftable';
  this->m_frameList.m_pHead = nullptr;
  this->m_frameList.m_nNextOffset = 0;
  this->m_nLastHit = -1;
  this->m_nLastStatus = -1;
  this->m_pLastInfo = nullptr;
  this->m_frameList.m_nNextOffset = 140;
  this->m_pfnNewHandler = AfxNewHandler;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10343036
// Name: class _AFX_THREAD_STATE __near * AfxGetThreadState(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_AFX_THREAD_STATE *__stdcall AfxGetThreadState()
{
  _AFX_THREAD_STATE *result; // eax

  result = (_AFX_THREAD_STATE *)CThreadLocalObject::GetData(
                                  this: &_afxThreadState,
                                  pfnCreateObject: CThreadLocal<_AFX_THREAD_STATE>::CreateObject);
  if ( result == nullptr )
    AfxThrowInvalidArgException();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034304F
// Name: public: virtual AFX_MODULE_STATE::~AFX_MODULE_STATE(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall AFX_MODULE_STATE::~AFX_MODULE_STATE(AFX_MODULE_STATE *this)
{
  _AFX_DAO_STATE *m_pDaoState; // ecx
  CTypeLibCacheMap *m_pTypeLibCacheMap; // ecx
  CTypeLibCacheMap *v4; // ecx
  CDllIsolationWrapperBase *v5; // ecx
  void (__thiscall ***v6)(_DWORD, int); // ecx
  void (__thiscall ***v7)(_DWORD, int); // ecx
  void *m_hActCtx; // eax

  this->__vftable = (AFX_MODULE_STATE_vtbl *)&AFX_MODULE_STATE::`vftable';
  m_pDaoState = this->m_pDaoState;
  if ( m_pDaoState != nullptr )
    ((void (__thiscall *)(_AFX_DAO_STATE *, int))m_pDaoState->dtr_CNoTrackObject)(a1: m_pDaoState, a2: 1);
  m_pTypeLibCacheMap = this->m_pTypeLibCacheMap;
  if ( m_pTypeLibCacheMap != nullptr )
  {
    m_pTypeLibCacheMap->RemoveAll(this: m_pTypeLibCacheMap, a2: &this->m_typeLibCache);
    v4 = this->m_pTypeLibCacheMap;
    if ( v4 != nullptr )
      ((void (__thiscall *)(CTypeLibCacheMap *, int))v4->dtr_CObject)(a1: v4, a2: 1);
  }
  v5 = *this->m_pDllIsolationWrappers;
  if ( v5 != nullptr )
    ((void (__thiscall *)(CDllIsolationWrapperBase *, int))v5->dtr_CNoTrackObject)(a1: v5, a2: 1);
  v6 = *((void (__thiscall ****)(_DWORD, int))this->m_pDllIsolationWrappers + 1);
  if ( v6 != nullptr )
    (**v6)(a1: v6, a2: 1);
  v7 = *((void (__thiscall ****)(_DWORD, int))this->m_pDllIsolationWrappers + 2);
  if ( v7 != nullptr )
    (**v7)(a1: v7, a2: 1);
  operator delete(p: this->m_pDllIsolationWrappers);
  m_hActCtx = this->m_hActCtx;
  if ( m_hActCtx != nullptr && m_hActCtx != (void *)-1 )
  {
    ReleaseActCtx(hActCtx: this->m_hActCtx);
    this->m_hActCtx = (void *)-1;
  }
  CThreadLocalObject::~CThreadLocalObject(this: &this->m_thread);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strUnregisterList.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1038E14B
// Name: protected: long CMDIFrameWndEx::OnMenuChar(unsigned int,unsigned int,class CMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::OnMenuChar(CMDIFrameWndEx *this, unsigned int nChar, unsigned int nFlags, CMenu *pMenu)
{
  if ( CFrameImpl::OnMenuChar(this: &this->m_Impl, nChar) != 0 )
    return -65534;
  else
    return CMDIFrameWnd::OnMenuChar(this, nChar, __formal: nFlags, __formal: pMenu);
}

//------------------------------------------------------------------------------
// Address: 0x1038E181
// Name: protected: virtual int CMDIFrameWndEx::OnCommand(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::OnCommand(CMDIFrameWndEx *this, unsigned int wParam, int lParam)
{
  if ( HIWORD(wParam) == 1 )
  {
    CMFCToolBar::AddCommandUsage(uiCommand: (unsigned __int16)wParam);
    if ( CFrameImpl::ProcessKeyboard(this: &this->m_Impl, nKey: 27, pbProcessAccel: nullptr) != 0
      || afxUserToolsManager != nullptr
      && CUserToolsManager::InvokeTool(this: afxUserToolsManager, uiCmdId: (unsigned __int16)wParam) != 0 )
    {
      return 1;
    }
  }
  if ( CMFCToolBar::m_bCustomizeMode != 0 )
    return 0;
  return CMDIFrameWnd::OnCommand(this, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x1038E1EC
// Name: protected: virtual struct HMENU__ __near * CMDIFrameWndEx::GetWindowMenuPopup(struct HMENU__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HMENU__ *__thiscall CMDIFrameWndEx::GetWindowMenuPopup(CMDIFrameWndEx *this, HMENU__ *hMenuBar)
{
  HMENU__ *result; // eax

  if ( this->m_bClosing != 0 )
    return nullptr;
  result = CMDIFrameWnd::GetWindowMenuPopup(this, hMenuBar);
  this->m_hmenuWindow = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1038E214
// Name: public: virtual int CMDIFrameWndEx::LoadFrame(unsigned int,unsigned long,class CWnd __near *,struct CCreateContext __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::LoadFrame(
        CMDIFrameWndEx *this,
        unsigned int nIDResource,
        unsigned int dwDefaultStyle,
        CWnd *pParentWnd,
        CCreateContext *pContext)
{
  int result; // eax

  this->m_Impl.m_nIDDefaultResource = nIDResource;
  CFrameImpl::LoadLargeIconsState(this: &this->m_Impl);
  result = CMDIFrameWnd::LoadFrame(this, nIDResource, dwDefaultStyle, pParentWnd, pContext);
  if ( result != 0 )
  {
    CFrameImpl::OnLoadFrame(this: &this->m_Impl);
    if ( this->m_Impl.m_pMenuBar != nullptr )
      this->m_hMenuDefault = this->m_Impl.m_hDefaultMenu;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1038E26E
// Name: protected: virtual int CMDIFrameWndEx::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::PreCreateWindow(CMDIFrameWndEx *this, tagCREATESTRUCTA *cs)
{
  this->m_Impl.m_pDockManager = &this->m_dockManager;
  CFrameImpl::RestorePosition(this: &this->m_Impl, cs);
  return CMDIFrameWnd::PreCreateWindow(this, cs);
}

//------------------------------------------------------------------------------
// Address: 0x1038E29F
// Name: public: virtual int CMDIFrameWndEx::OnDrawMenuImage(class CDC __near *,class CMFCToolBarMenuButton const __near *,class CRect const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::OnDrawMenuImage(
        CMDIFrameWndEx *this,
        CDC *pDC,
        const CMFCToolBarMenuButton *pMenuButton,
        const CRect *rectImage)
{
  CMFCRibbonBar *m_pRibbonBar; // ecx

  m_pRibbonBar = this->m_Impl.m_pRibbonBar;
  if ( m_pRibbonBar != nullptr )
    return CMFCRibbonBar::DrawMenuImage(this: m_pRibbonBar, pDC, pMenuItem: pMenuButton, rectImage);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1038E2BA
// Name: protected: long CMDIFrameWndEx::OnToolbarCreateNew(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const CMFCToolBar *__thiscall CMDIFrameWndEx::OnToolbarCreateNew(
        CMDIFrameWndEx *this,
        unsigned int __formal,
        const char *lp)
{
  if ( lp == nullptr )
    AfxThrowInvalidArgException();
  return CFrameImpl::CreateNewToolBar(this: &this->m_Impl, lpszName: lp);
}

//------------------------------------------------------------------------------
// Address: 0x1038E2DC
// Name: protected: long CMDIFrameWndEx::OnToolbarDelete(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::OnToolbarDelete(CMDIFrameWndEx *this, unsigned int __formal, CMFCToolBar *lp)
{
  return CFrameImpl::DeleteToolBar(this: &this->m_Impl, pToolBar: lp);
}

//------------------------------------------------------------------------------
// Address: 0x1038E2F3
// Name: protected: void CMDIFrameWndEx::OnContextHelp(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::OnContextHelp(CMDIFrameWndEx *this)
{
  bool v2; // zf

  v2 = this->m_bHelpMode == 0;
  this->m_bContextHelp = 1;
  if ( v2 && CFrameWnd::CanEnterHelpMode(this) != 0 )
    CMFCToolBar::SetHelpMode(bOn: 1);
  CFrameWnd::OnContextHelp(this);
  if ( this->m_bHelpMode == 0 )
    CMFCToolBar::SetHelpMode(bOn: 0);
  this->m_bContextHelp = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1038E33B
// Name: protected: void CMDIFrameWndEx::OnActivateApp(int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::OnActivateApp(CMDIFrameWndEx *this, int bActive, unsigned int __formal)
{
  this->m_dockManager.OnActivateFrame(this: &this->m_dockManager, a2: bActive);
  CFrameImpl::OnActivateApp(this: &this->m_Impl, bActive);
}

//------------------------------------------------------------------------------
// Address: 0x1038E364
// Name: public: virtual void CMDIFrameWndEx::OnUpdateFrameMenu(struct HMENU__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::OnUpdateFrameMenu(CMDIFrameWndEx *this, HMENU__ *hMenuAlt)
{
  CMFCMenuBar *m_pMenuBar; // ecx
  int v4; // ebx
  CMFCRibbonBar *m_pRibbonBar; // ecx
  COleClientItem *v6; // eax
  CMDIFrameWndEx_vtbl *v7; // edi
  CMenu *v8; // eax
  int bIsMenuBar; // [esp+Ch] [ebp-4h]

  CMDIFrameWnd::OnUpdateFrameMenu(this, hMenuAlt);
  m_pMenuBar = this->m_Impl.m_pMenuBar;
  v4 = 0;
  if ( m_pMenuBar == nullptr || (bIsMenuBar = 1, (CWnd::GetStyle(this: m_pMenuBar) & 0x10000000) == 0) )
    bIsMenuBar = 0;
  m_pRibbonBar = this->m_Impl.m_pRibbonBar;
  if ( m_pRibbonBar != nullptr && (CWnd::GetStyle(this: m_pRibbonBar) & 0x10000000) != 0 )
    v4 = 1;
  if ( bIsMenuBar != 0 || v4 != 0 )
  {
    v6 = this->GetInPlaceActiveItem(this);
    if ( v6 != nullptr && COleClientItem::GetInPlaceWindow(this: v6) != nullptr )
    {
      v7 = this->__vftable;
      v8 = CMenu::FromHandle(hMenu: hMenuAlt);
      v7->SetMenu(this, a2: v8);
    }
    else
    {
      this->SetMenu(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1038E3F6
// Name: public: virtual int CMDIFrameWndEx::OnShowPanes(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::OnShowPanes(CMDIFrameWndEx *this, int bShow)
{
  int v3; // edi

  v3 = this->m_dockManager.ShowPanes(this: &this->m_dockManager, a2: bShow);
  this->AdjustDockingLayout(this, a2: nullptr);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1038E423
// Name: public: int CMDIFrameWndEx::AddPane(class CBasePane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::AddPane(CMDIFrameWndEx *this, CBasePane *pControlBar, int bTail)
{
  CMFCRibbonBar *v4; // edi
  CMFCRibbonStatusBar *v5; // eax

  v4 = (CMFCRibbonBar *)AfxDynamicDownCast(pClass: &CMFCRibbonBar::classCMFCRibbonBar, pObject: pControlBar);
  if ( v4 != nullptr && v4->IsMainRibbonBar(this: v4) != 0 )
    this->m_Impl.m_pRibbonBar = v4;
  v5 = (CMFCRibbonStatusBar *)AfxDynamicDownCast(
                                pClass: &CMFCRibbonStatusBar::classCMFCRibbonStatusBar,
                                pObject: pControlBar);
  if ( v5 != nullptr )
    this->m_Impl.m_pRibbonStatusBar = v5;
  return CDockingManager::AddPane(
           this: &this->m_dockManager,
           pWnd: pControlBar,
           bTail,
           bAutoHide: 0,
           bInsertForOuterEdge: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1038E489
// Name: public: int CMDIFrameWndEx::InsertPane(class CBasePane __near *,class CBasePane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::InsertPane(CMDIFrameWndEx *this, CBasePane *pControlBar, CBasePane *pTarget, int bAfter)
{
  return CDockingManager::InsertPane(this: &this->m_dockManager, pControlBar, pTarget, bAfter);
}

//------------------------------------------------------------------------------
// Address: 0x1038E49A
// Name: public: void CMDIFrameWndEx::RemovePaneFromDockManager(class CBasePane __near *,int,int,int,class CBasePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::RemovePaneFromDockManager(
        CMDIFrameWndEx *this,
        CBasePane *pControlBar,
        int bDestroy,
        int bAdjustLayout,
        int bAutoHide,
        CBasePane *pBarReplacement)
{
  CDockingManager::RemovePaneFromDockManager(
    this: &this->m_dockManager,
    pWnd: pControlBar,
    bDestroy,
    bAdjustLayout,
    bAutoHide,
    pBarReplacement);
}

//------------------------------------------------------------------------------
// Address: 0x1038E4AB
// Name: public: void CMDIFrameWndEx::DockPane(class CBasePane __near *,unsigned int,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::DockPane(
        CMDIFrameWndEx *this,
        CBasePane *pBar,
        unsigned int nDockBarID,
        const tagRECT *lpRect)
{
  CDockingManager::DockPane(this: &this->m_dockManager, pBar, nDockBarID, lpRect);
}

//------------------------------------------------------------------------------
// Address: 0x1038E4BC
// Name: public: class CBasePane __near * CMDIFrameWndEx::GetPane(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBasePane *__thiscall CMDIFrameWndEx::GetPane(CMDIFrameWndEx *this, unsigned int nID)
{
  return this->m_dockManager.FindPaneByID(this: &this->m_dockManager, a2: nID, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1038E4D5
// Name: public: class CBasePane __near * CMDIFrameWndEx::PaneFromPoint(class CPoint,int,bool,struct CRuntimeClass __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBasePane *__thiscall CMDIFrameWndEx::PaneFromPoint(
        CMDIFrameWndEx *this,
        CPoint point,
        int nSensitivity,
        int bExactBar,
        CRuntimeClass *pRTCBarType)
{
  return ((CBasePane *(__thiscall *)(CDockingManager *, int, int, int, int, CRuntimeClass *, _DWORD, _DWORD))this->m_dockManager.PaneFromPoint_2)(
           a1: &this->m_dockManager,
           a2: point.x,
           a3: point.y,
           a4: nSensitivity,
           a5: bExactBar,
           a6: pRTCBarType,
           a7: 0,
           a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1038E4FC
// Name: public: int CMDIFrameWndEx::IsPointNearDockSite(class CPoint,unsigned long __near &,int __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::IsPointNearDockSite(
        CMDIFrameWndEx *this,
        CPoint point,
        unsigned int *dwBarAlignment,
        int *bOuterEdge)
{
  return CDockingManager::IsPointNearDockSite(this: &this->m_dockManager, point, dwBarAlignment, bOuterEdge);
}

//------------------------------------------------------------------------------
// Address: 0x1038E51C
// Name: public: virtual int CMDIFrameWndEx::OnMoveMiniFrame(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::OnMoveMiniFrame(CMDIFrameWndEx *this, CWnd *pFrame)
{
  return this->m_dockManager.OnMoveMiniFrame(this: &this->m_dockManager, a2: pFrame);
}

//------------------------------------------------------------------------------
// Address: 0x1038E52D
// Name: public: virtual int CMDIFrameWndEx::NegotiateBorderSpace(unsigned int,struct tagRECT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::NegotiateBorderSpace(
        CMDIFrameWndEx *this,
        unsigned int nBorderCmd,
        tagRECT *lpRectBorder)
{
  CRect *p_m_rectClientAreaBounds; // esi
  int *p_top; // esi
  tagRECT rectBounds; // 0:^10.16

  if ( nBorderCmd == 1 )
  {
    CFrameWnd::NegotiateBorderSpace(this, nBorderCmd: 1u, lpRectBorder);
    this->m_dockManager.AdjustDockingLayout(this: &this->m_dockManager, a2: nullptr);
    p_m_rectClientAreaBounds = &this->m_dockManager.m_rectClientAreaBounds;
    rectBounds.left = p_m_rectClientAreaBounds->left;
    p_m_rectClientAreaBounds = (CRect *)((char *)p_m_rectClientAreaBounds + 4);
    rectBounds.top = p_m_rectClientAreaBounds->left;
    p_top = &p_m_rectClientAreaBounds->top;
    if ( lpRectBorder == nullptr )
      AfxThrowInvalidArgException();
    rectBounds.right = *p_top;
    rectBounds.bottom = p_top[1];
    *lpRectBorder = rectBounds;
  }
  else if ( nBorderCmd == 3 )
  {
    return CFrameWnd::NegotiateBorderSpace(this, nBorderCmd: 3u, lpRectBorder);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1038E593
// Name: protected: long CMDIFrameWndEx::OnExitSizeMove(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::OnExitSizeMove(CMDIFrameWndEx *this, unsigned int __formal, unsigned int __formala)
{
  this->RecalcLayout(this, a2: 1);
  this->m_dockManager.FixupVirtualRects(this: &this->m_dockManager);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1038E5B3
// Name: protected: long CMDIFrameWndEx::OnIdleUpdateCmdUI(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::OnIdleUpdateCmdUI(CMDIFrameWndEx *this, unsigned int __formal, unsigned int __formala)
{
  CDockingManager::SendMessageToMiniFrames(this: &this->m_dockManager, uMessage: 0x363u, wParam: 0, lParam: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1038E5CC
// Name: public: virtual int CMDIFrameWndEx::LoadMDIState(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::LoadMDIState(CMDIFrameWndEx *this, const char *lpszProfileName)
{
  return CMDIClientAreaWnd::LoadState(this: &this->m_wndClientArea, lpszProfileName, nFrameID: this->m_nFrameID);
}

//------------------------------------------------------------------------------
// Address: 0x1038E5E9
// Name: public: virtual int CMDIFrameWndEx::SaveMDIState(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::SaveMDIState(CMDIFrameWndEx *this, const char *lpszProfileName)
{
  return CMDIClientAreaWnd::SaveState(this: &this->m_wndClientArea, lpszProfileName, nFrameID: this->m_nFrameID);
}

//------------------------------------------------------------------------------
// Address: 0x1038E606
// Name: public: virtual int CMDIFrameWndEx::OnCmdMsg(unsigned int,int,void __near *,struct AFX_CMDHANDLERINFO __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::OnCmdMsg(
        CMDIFrameWndEx *this,
        unsigned int nID,
        int nCode,
        void *pExtra,
        AFX_CMDHANDLERINFO *pHandlerInfo)
{
  if ( CMDIFrameWnd::OnCmdMsg(this, nID, nCode, pExtra, pHandlerInfo) != 0 )
    return 1;
  else
    return CDockingManager::ProcessPaneContextMenuCommand(
             this: &this->m_dockManager,
             nID,
             nCode,
             pExtra,
             __formal: pHandlerInfo);
}
