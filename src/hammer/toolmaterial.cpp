// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/toolmaterial.cpp
// Functions: 7
// ============================================================

#include "hammer\toolmaterial.h"

//------------------------------------------------------------------------------
// Address: 0x1015F4E0
// Name: private: virtual void CToolMaterial::OnDeactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolMaterial::OnDeactivate(CToolMaterial *this)
{
  if ( CToolManager::GetActiveToolID(this: this->m_pDocument->m_pToolManager) != TOOL_FACEEDIT_DISP )
    CMapDoc::SelectFace(this: this->m_pDocument, pSolid: 0, cmd: 16);
}

//------------------------------------------------------------------------------
// Address: 0x1015F510
// Name: private: virtual bool CToolMaterial::OnLMouseDown2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CToolMaterial::OnLMouseDown2D@<al>(
        CToolMaterial *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CMapView2D *pView,
        char nFlags,
        const Vector2D *vPoint)
{
  if ( (nFlags & 8) != 0 )
    CMapView::SelectAt(this: &pView->CMapView, a2, a3, a4, ptClient: vPoint, bMakeFirst: false, bFace: true);
  else
    CMapView::SelectAt(this: &pView->CMapView, a2, a3, a4, ptClient: vPoint, bMakeFirst: true, bFace: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015F550
// Name: private: virtual bool CToolMaterial::OnLMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolMaterial::OnLMouseDown3D(
        CToolMaterial *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CMapClass *v6; // esi
  int v7; // edi
  unsigned int ulFace; // [esp+4h] [ebp-8h] BYREF
  CMapDoc *pDoc; // [esp+8h] [ebp-4h]
  bool bShift_3; // [esp+17h] [ebp+Bh]

  pDoc = pView->GetMapDoc(this: &pView->CMapView);
  if ( pDoc == nullptr )
    return 0;
  bShift_3 = GetAsyncKeyState(vKey: 16) < 0;
  v6 = CMapView3D::NearestObjectAt(this: pView, vPoint, &ulFace, nFlags: 0, pLocalMatrix: nullptr);
  if ( v6 != nullptr && v6->IsMapClass(this: v6, a2: CMapSolid::__Type) != 0 )
  {
    v7 = 17;
    if ( GetAsyncKeyState(vKey: 17) < 0 )
      v7 = 1;
    if ( bShift_3 )
    {
      CMapDoc::SelectFace(this: pDoc, pSolid: (unsigned int)v6 | 0xFFFFFFFF00000000uLL, cmd: v7);
      return 1;
    }
    CMapDoc::SelectFace(this: pDoc, pSolid: __PAIR64__(ulFace, (unsigned int)v6), cmd: v7);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015F610
// Name: private: virtual bool CToolMaterial::OnRMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolMaterial::OnRMouseDown3D(
        CToolMaterial *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  int v4; // edi
  int v5; // esi
  CMapSolid *v6; // ebx
  CHistory *History; // eax
  CHistory *v8; // eax
  DrawType_t v9; // eax
  int v10; // esi
  int v11; // edi
  CMainFrame *v12; // eax
  CMainFrame *MainWnd; // eax
  unsigned int v15; // [esp-Ch] [ebp-1Ch]
  int v16; // [esp-4h] [ebp-14h]
  unsigned int ulFace; // [esp+Ch] [ebp-4h] BYREF
  int nFaces; // [esp+18h] [ebp+8h]
  int cmdFlags; // [esp+20h] [ebp+10h]

  v4 = (unsigned __int16)GetAsyncKeyState(vKey: 16) >> 15;
  v5 = (unsigned __int16)GetAsyncKeyState(vKey: 18) >> 15;
  v6 = (CMapSolid *)CMapView3D::NearestObjectAt(this: pView, vPoint, &ulFace, nFlags: 0, pLocalMatrix: nullptr);
  if ( v6 == nullptr || v6->IsMapClass(this: v6, a2: CMapSolid::__Type) == 0 )
    return 1;
  History = GetHistory();
  CHistory::MarkUndoPosition(this: History, pSelection: nullptr, pszName: "Apply texture", bFromOpposite: 0);
  v8 = GetHistory();
  CHistory::Keep(this: v8, pObject: v6);
  cmdFlags = 0;
  if ( v5 != 0 )
    cmdFlags = 16;
  v9 = pView->GetDrawType(this: &pView->CMapView);
  v10 = 262 - (v9 != VIEW3D_LIGHTMAP_GRID);
  if ( v4 == 0 )
  {
    v16 = 262 - (v9 != VIEW3D_LIGHTMAP_GRID);
    v15 = ulFace;
    MainWnd = GetMainWnd();
    CFaceEditSheet::ClickFace(
      this: MainWnd->m_pFaceEditSheet,
      pSolid: v6,
      faceIndex: v15,
      cmd: cmdFlags,
      clickMode: v16);
    return 1;
  }
  v11 = 0;
  nFaces = v6->Faces.nCount;
  if ( nFaces <= 0 )
    return 1;
  do
  {
    v12 = GetMainWnd();
    CFaceEditSheet::ClickFace(this: v12->m_pFaceEditSheet, pSolid: v6, faceIndex: v11++, cmd: cmdFlags, clickMode: v10);
  }
  while ( v11 < nFaces );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015F720
// Name: private: virtual bool CToolMaterial::OnMouseMove3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolMaterial::OnMouseMove3D(
        CToolMaterial *this,
        CMapView3D *pView,
        CMapView3D *nFlags,
        const Vector2D *vPoint)
{
  HCURSOR CursorA; // eax
  AFX_MODULE_STATE *ModuleState; // eax

  CursorA = hcurFacePaint;
  if ( hcurFacePaint == nullptr )
  {
    ModuleState = AfxGetModuleState();
    CursorA = LoadCursorA(hInstance: ModuleState->m_hCurrentInstanceHandle, lpCursorName: (LPCSTR)0x68);
    hcurFacePaint = CursorA;
  }
  SetCursor(hCursor: CursorA);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015F750
// Name: private: virtual bool CToolMaterial::OnKeyDown3D(class CMapView3D __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolMaterial::OnKeyDown3D(
        CToolMaterial *this,
        CMapView3D *pView,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  CMapDoc *v6; // edi
  CFaceEditSheet *m_pFaceEditSheet; // eax
  int m_Size; // ebx
  int m_nGridSpacing; // esi
  float v11; // xmm0_4
  int v12; // edi
  CMapFace *pMapFace; // esi
  float v14; // xmm0_4
  CMapDoc *pDoc; // [esp+8h] [ebp-Ch]
  CFaceEditSheet *pSheet; // [esp+Ch] [ebp-8h]
  float v17; // [esp+10h] [ebp-4h]
  CMapView3D *pViewa; // [esp+1Ch] [ebp+8h]

  v6 = pView->GetMapDoc(this: &pView->CMapView);
  pDoc = v6;
  if ( v6 == nullptr || nChar != 38 && nChar != 40 && nChar != 37 && nChar != 39 )
    return 0;
  if ( Options.view2d.bNudge == 0 )
    return 0;
  m_pFaceEditSheet = GetMainWnd()->m_pFaceEditSheet;
  pSheet = m_pFaceEditSheet;
  if ( m_pFaceEditSheet == nullptr )
    return 0;
  m_Size = m_pFaceEditSheet->m_Faces.m_Size;
  if ( m_Size == 0 )
    return 0;
  m_nGridSpacing = this->m_pDocument->m_nGridSpacing;
  if ( m_nGridSpacing <= 1 )
    m_nGridSpacing = 1;
  if ( GetAsyncKeyState(vKey: 17) < 0 )
    m_nGridSpacing = 1;
  if ( m_Size > 0 )
  {
    v11 = (float)m_nGridSpacing;
    v17 = (float)m_nGridSpacing;
    v12 = 0;
    pViewa = (CMapView3D *)m_Size;
    while ( 1 )
    {
      pMapFace = pSheet->m_Faces.m_Memory.m_pMemory[v12].pMapFace;
      if ( nChar == 38 )
      {
        pMapFace->texture.VAxis.w = (float)((int)(float)(pMapFace->texture.VAxis.w + v11) % 1024);
      }
      else if ( nChar == 40 )
      {
        pMapFace->texture.VAxis.w = (float)((int)(float)(pMapFace->texture.VAxis.w - v11) % 1024);
      }
      else
      {
        v14 = nChar == 37
            ? (float)((int)(float)(v11 + pMapFace->texture.UAxis.w) % 1024)
            : (float)((int)(float)(pMapFace->texture.UAxis.w - v11) % 1024);
        pMapFace->texture.UAxis.w = v14;
      }
      CMapFace::CalcTextureCoords(this: pMapFace, a2: (int)pSheet);
      CFaceEditMaterialPage::UpdateDialogData(this: &pSheet->m_MaterialPage, pOnlyFace: pMapFace);
      ++v12;
      pViewa = (CMapView3D *)((char *)pViewa - 1);
      if ( pViewa == nullptr )
        break;
      v11 = v17;
    }
    v6 = pDoc;
  }
  v6->SetModifiedFlag(this: v6, a2: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015F930
// Name: private: virtual void CToolMaterial::UpdateStatusBar(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CToolMaterial::UpdateStatusBar(CToolMaterial *this@<ecx>, int a2@<esi>)
{
  CAfxStringMgr *StringManager; // eax
  CMainFrame *MainWnd; // eax
  char *m_pszData; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+0h] [ebp-10h] BYREF
  int v6; // [esp+Ch] [ebp-4h]

  str.m_pszData = (char *)this;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  str.m_pszData = (char *)(((int (__thiscall *)(CAfxStringMgr *, int))StringManager->GetNilString)(
                             a1: StringManager,
                             a2)
                         + 16);
  v6 = 1;
  MainWnd = GetMainWnd();
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
    this: &str,
    pszFormat: "%d faces selected",
    MainWnd->m_pFaceEditSheet->m_Faces.m_Size);
  m_pszData = str.m_pszData;
  SetStatusText(nIndex: 1, pszText: str.m_pszData);
  SetStatusText(nIndex: 3, pszText: &var);
  v6 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**((_DWORD **)m_pszData - 4) + 4))(a1: m_pszData - 16);
}
