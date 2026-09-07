// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/faceedit_disppage.cpp
// Functions: 39
// ============================================================

#include "hammer\faceedit_disppage.h"

//------------------------------------------------------------------------------
// Address: 0x100C9140
// Name: class CToolDisplace __near * GetDisplacementTool(void)
// Source: json
//------------------------------------------------------------------------------
CToolDisplace *__cdecl GetDisplacementTool()
{
  CToolManager *v0; // eax
  CBaseTool *ToolForID; // eax

  v0 = ToolManager();
  ToolForID = CToolManager::GetToolForID(this: v0, eToolID: TOOL_FACEEDIT_DISP);
  return (CToolDisplace *)__RTDynamicCast(
                            inptr: ToolForID,
                            VfDelta: 0,
                            SrcType: &CBaseTool `RTTI Type Descriptor',
                            TargetType: &CToolDisplace `RTTI Type Descriptor',
                            isReference: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100C9170
// Name: public: virtual struct CRuntimeClass __near * CFaceEditDispPage::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CFaceEditDispPage::GetRuntimeClass(CFaceEditDispPage *this)
{
  return &CFaceEditDispPage::classCFaceEditDispPage;
}

//------------------------------------------------------------------------------
// Address: 0x100C9180
// Name: public: virtual CFaceEditDispPage::~CFaceEditDispPage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::~CFaceEditDispPage(CFaceEditDispPage *this)
{
  this->__vftable = (CFaceEditDispPage_vtbl *)&CFaceEditDispPage::`vftable';
  CPaintSculptDlg::~CPaintSculptDlg(this: &this->m_PaintSculptDlg);
  CDispPaintDataDlg::~CDispPaintDataDlg(this: &this->m_PaintDataDlg);
  CDispPaintDistDlg::~CDispPaintDistDlg(this: &this->m_PaintDistDlg);
  CSpinButtonCtrl::~CSpinButtonCtrl(this: &this->m_NoiseDlg.m_spinMax);
  CSpinButtonCtrl::~CSpinButtonCtrl(this: &this->m_NoiseDlg.m_spinMin);
  CEdit::~CEdit(this: &this->m_NoiseDlg.m_editMax);
  CEdit::~CEdit(this: &this->m_NoiseDlg.m_editMin);
  CDialog::~CDialog(this: &this->m_NoiseDlg);
  CSpinButtonCtrl::~CSpinButtonCtrl(this: &this->m_CreateDlg.m_spinPower);
  CEdit::~CEdit(this: &this->m_CreateDlg.m_editPower);
  CDialog::~CDialog(this: &this->m_CreateDlg);
  CPropertyPage::~CPropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C9280
// Name: protected: void CFaceEditDispPage::UpdateEditControls(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::UpdateEditControls(CFaceEditDispPage *this, bool bAllDisps, bool bHasFace)
{
  CWnd *DlgItem; // edi
  CWnd *v5; // ebx
  CWnd *v6; // edi
  CWnd *v7; // ebx
  CWnd *v8; // ecx
  CButton *pbuttonSelecta; // [esp+Ch] [ebp-40h]
  CButton *pbuttonSelect; // [esp+Ch] [ebp-40h]
  CButton *pButtonWalka; // [esp+10h] [ebp-3Ch]
  CButton *pButtonWalk; // [esp+10h] [ebp-3Ch]
  CButton *pButtonBuilda; // [esp+14h] [ebp-38h]
  CButton *pButtonBuild; // [esp+14h] [ebp-38h]
  CButton *pbuttonInvertAlpha; // [esp+18h] [ebp-34h]
  CButton *pbuttonApply; // [esp+1Ch] [ebp-30h]
  CEdit *peditScale; // [esp+20h] [ebp-2Ch]
  CSpinButtonCtrl *pspinElevation; // [esp+24h] [ebp-28h]
  CEdit *peditElevation; // [esp+28h] [ebp-24h]
  CSpinButtonCtrl *pspinPower; // [esp+2Ch] [ebp-20h]
  CEdit *peditPower; // [esp+30h] [ebp-1Ch]
  CButton *pbuttonNoise; // [esp+34h] [ebp-18h]
  CButton *pbuttonSubdiv; // [esp+38h] [ebp-14h]
  CButton *pbuttonPaintData; // [esp+3Ch] [ebp-10h]
  CButton *pbuttonPaintSculpt; // [esp+40h] [ebp-Ch]
  CButton *pbuttonPaintGeo; // [esp+44h] [ebp-8h]
  CButton *pbuttonCreate; // [esp+48h] [ebp-4h]

  DlgItem = CWnd::GetDlgItem(this, nID: 1489);
  v5 = CWnd::GetDlgItem(this, nID: 1490);
  CWnd::EnableWindow(this: DlgItem, bEnable: 1);
  CWnd::EnableWindow(this: v5, bEnable: 1);
  pbuttonSelecta = (CButton *)CWnd::GetDlgItem(this, nID: 1552);
  pbuttonCreate = (CButton *)CWnd::GetDlgItem(this, nID: 1474);
  v6 = CWnd::GetDlgItem(this, nID: 1476);
  pbuttonPaintGeo = (CButton *)CWnd::GetDlgItem(this, nID: 1558);
  pbuttonPaintSculpt = (CButton *)CWnd::GetDlgItem(this, nID: 1560);
  pbuttonPaintData = (CButton *)CWnd::GetDlgItem(this, nID: 1559);
  pbuttonSubdiv = (CButton *)CWnd::GetDlgItem(this, nID: 1495);
  v7 = CWnd::GetDlgItem(this, nID: 1496);
  pbuttonNoise = (CButton *)CWnd::GetDlgItem(this, nID: 1557);
  pButtonWalka = (CButton *)CWnd::GetDlgItem(this, nID: 1580);
  pButtonBuilda = (CButton *)CWnd::GetDlgItem(this, nID: 1581);
  CWnd::EnableWindow(this: pbuttonSelecta, bEnable: 1);
  CWnd::EnableWindow(this: pbuttonCreate, bEnable: 0);
  CWnd::EnableWindow(this: v6, bEnable: 0);
  CWnd::EnableWindow(this: pbuttonPaintGeo, bEnable: 0);
  CWnd::EnableWindow(this: pbuttonPaintSculpt, bEnable: 0);
  CWnd::EnableWindow(this: pbuttonPaintData, bEnable: 0);
  CWnd::EnableWindow(this: pbuttonSubdiv, bEnable: 0);
  CWnd::EnableWindow(this: v7, bEnable: 0);
  CWnd::EnableWindow(this: pbuttonNoise, bEnable: 0);
  CWnd::EnableWindow(this: pButtonWalka, bEnable: 1);
  CWnd::EnableWindow(this: pButtonBuilda, bEnable: 1);
  peditPower = (CEdit *)CWnd::GetDlgItem(this, nID: 1478);
  pspinPower = (CSpinButtonCtrl *)CWnd::GetDlgItem(this, nID: 1008);
  peditElevation = (CEdit *)CWnd::GetDlgItem(this, nID: 1480);
  pspinElevation = (CSpinButtonCtrl *)CWnd::GetDlgItem(this, nID: 1486);
  peditScale = (CEdit *)CWnd::GetDlgItem(this, nID: 1009);
  pbuttonApply = (CButton *)CWnd::GetDlgItem(this, nID: 1475);
  pbuttonInvertAlpha = (CButton *)CWnd::GetDlgItem(this, nID: 1010);
  pButtonBuild = (CButton *)CWnd::GetDlgItem(this, nID: 1656);
  pButtonWalk = (CButton *)CWnd::GetDlgItem(this, nID: 1648);
  pbuttonSelect = (CButton *)CWnd::GetDlgItem(this, nID: 1657);
  CWnd::EnableWindow(this: peditPower, bEnable: 0);
  CWnd::EnableWindow(this: pspinPower, bEnable: 0);
  CWnd::EnableWindow(this: peditElevation, bEnable: 0);
  CWnd::EnableWindow(this: pspinElevation, bEnable: 0);
  CWnd::EnableWindow(this: peditScale, bEnable: 0);
  CWnd::EnableWindow(this: pbuttonApply, bEnable: 0);
  CWnd::EnableWindow(this: pbuttonInvertAlpha, bEnable: 0);
  CWnd::EnableWindow(this: pButtonBuild, bEnable: 0);
  CWnd::EnableWindow(this: pButtonWalk, bEnable: 0);
  CWnd::EnableWindow(this: pbuttonSelect, bEnable: 0);
  if ( bHasFace && this->m_bIsEditable )
  {
    if ( bAllDisps )
    {
      CWnd::EnableWindow(this: v6, bEnable: 1);
      CWnd::EnableWindow(this: pbuttonPaintGeo, bEnable: 1);
      CWnd::EnableWindow(this: pbuttonPaintSculpt, bEnable: 1);
      CWnd::EnableWindow(this: pbuttonPaintData, bEnable: 1);
      CWnd::EnableWindow(this: pbuttonSubdiv, bEnable: 1);
      CWnd::EnableWindow(this: v7, bEnable: 1);
      v8 = pbuttonNoise;
    }
    else
    {
      CWnd::EnableWindow(this: pbuttonCreate, bEnable: 1);
      CWnd::EnableWindow(this: v6, bEnable: 1);
      v8 = v7;
    }
    CWnd::EnableWindow(this: v8, bEnable: 1);
    if ( this->m_uiTool == 0 )
    {
      CWnd::EnableWindow(this: peditPower, bEnable: 1);
      CWnd::EnableWindow(this: pspinPower, bEnable: 1);
      CWnd::EnableWindow(this: peditElevation, bEnable: 1);
      CWnd::EnableWindow(this: pspinElevation, bEnable: 1);
      CWnd::EnableWindow(this: peditScale, bEnable: 1);
      CWnd::EnableWindow(this: pbuttonApply, bEnable: 1);
      CWnd::EnableWindow(this: pbuttonInvertAlpha, bEnable: 1);
      CWnd::EnableWindow(this: pButtonBuild, bEnable: 1);
      CWnd::EnableWindow(this: pButtonWalk, bEnable: 1);
      CWnd::EnableWindow(this: pbuttonSelect, bEnable: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C95B0
// Name: public: void CFaceEditDispPage::UpdatePaintDialogs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::UpdatePaintDialogs(CFaceEditDispPage *this)
{
  CDispPaintDistDlg::UpdateSpatialData(this: &this->m_PaintDistDlg);
}

//------------------------------------------------------------------------------
// Address: 0x100C95C0
// Name: protected: void CFaceEditDispPage::OnCheckMaskSelect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnCheckMaskSelect(CFaceEditDispPage *this)
{
  CToolManager *v1; // eax
  CBaseTool *ToolForID; // eax
  _BYTE *v3; // eax
  bool v4; // cl

  v1 = ToolManager();
  ToolForID = CToolManager::GetToolForID(this: v1, eToolID: TOOL_FACEEDIT_DISP);
  v3 = __RTDynamicCast(
         inptr: ToolForID,
         VfDelta: 0,
         SrcType: &CBaseTool `RTTI Type Descriptor',
         TargetType: &CToolDisplace `RTTI Type Descriptor',
         isReference: 0);
  if ( v3 != nullptr )
  {
    v4 = v3[1181] == 0;
    v3[1181] = v4;
    CMapDisp::SetSelectMask(bSelectMask: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9610
// Name: protected: void CFaceEditDispPage::OnCheckMaskGrid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnCheckMaskGrid(CFaceEditDispPage *this)
{
  CToolManager *v1; // eax
  CBaseTool *ToolForID; // eax
  _BYTE *v3; // eax
  bool v4; // cl

  v1 = ToolManager();
  ToolForID = CToolManager::GetToolForID(this: v1, eToolID: TOOL_FACEEDIT_DISP);
  v3 = __RTDynamicCast(
         inptr: ToolForID,
         VfDelta: 0,
         SrcType: &CBaseTool `RTTI Type Descriptor',
         TargetType: &CToolDisplace `RTTI Type Descriptor',
         isReference: 0);
  if ( v3 != nullptr )
  {
    v4 = v3[1182] == 0;
    v3[1182] = v4;
    CMapDisp::SetGridMask(bGridMask: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9660
// Name: public: void CFaceEditDispPage::CloseAllDialogs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::CloseAllDialogs(CFaceEditDispPage *this)
{
  if ( this->m_uiTool == 3 )
    this->m_PaintDistDlg.DestroyWindow(this: &this->m_PaintDistDlg);
  if ( this->m_uiTool == 5 )
    this->m_PaintSculptDlg.DestroyWindow(this: &this->m_PaintSculptDlg);
  if ( this->m_uiTool == 4 )
    this->m_PaintDataDlg.DestroyWindow(this: &this->m_PaintDataDlg);
}

//------------------------------------------------------------------------------
// Address: 0x100C96C0
// Name: public: void CFaceEditDispPage::ResetForceShows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::ResetForceShows(CFaceEditDispPage *this)
{
  if ( this->m_bForceShowWalkable )
  {
    if ( CMapDoc::m_pMapDoc != nullptr )
      CMapDoc::m_pMapDoc->m_bDispDrawWalkable = false;
    this->m_bForceShowWalkable = false;
  }
  if ( this->m_bForceShowBuildable )
  {
    if ( CMapDoc::m_pMapDoc != nullptr )
      CMapDoc::m_pMapDoc->m_bDispDrawBuildable = false;
    this->m_bForceShowBuildable = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9700
// Name: public: virtual int CFaceEditDispPage::OnKillActive(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFaceEditDispPage::OnKillActive(CFaceEditDispPage *this)
{
  if ( this->m_uiTool == 3 )
    this->m_PaintDistDlg.DestroyWindow(this: &this->m_PaintDistDlg);
  if ( this->m_uiTool == 5 )
    this->m_PaintSculptDlg.DestroyWindow(this: &this->m_PaintSculptDlg);
  if ( this->m_uiTool == 4 )
    this->m_PaintDataDlg.DestroyWindow(this: &this->m_PaintDataDlg);
  if ( this->m_bForceShowWalkable )
  {
    if ( CMapDoc::m_pMapDoc != nullptr )
      CMapDoc::m_pMapDoc->m_bDispDrawWalkable = false;
    this->m_bForceShowWalkable = false;
  }
  if ( this->m_bForceShowBuildable )
  {
    if ( CMapDoc::m_pMapDoc != nullptr )
      CMapDoc::m_pMapDoc->m_bDispDrawBuildable = false;
    this->m_bForceShowBuildable = false;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C97A0
// Name: public: virtual int CFaceEditDispPage::PreTranslateMessage(struct tagMSG __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFaceEditDispPage::PreTranslateMessage(CFaceEditDispPage *this, tagMSG *pMsg)
{
  HACCEL__ *m_hAccelTable; // eax
  CMainFrame *MainWnd; // eax
  HACCEL v6; // [esp-8h] [ebp-10h]

  m_hAccelTable = GetMainWnd()->m_hAccelTable;
  if ( m_hAccelTable != nullptr
    && (v6 = m_hAccelTable,
        MainWnd = GetMainWnd(),
        TranslateAcceleratorA(hWnd: MainWnd->m_hWnd, hAccTable: v6, lpMsg: pMsg) != 0) )
  {
    return 1;
  }
  else
  {
    return CPropertyPage::PreTranslateMessage(this, pMsg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C97F0
// Name: public: CFaceEditDispPage::CFaceEditDispPage(void)
// Source: json
//------------------------------------------------------------------------------
CFaceEditDispPage *__thiscall CFaceEditDispPage::CFaceEditDispPage(CFaceEditDispPage *this)
{
  CPropertyPage::CPropertyPage(this, nIDTemplate: 0x12Fu, nIDCaption: 0, dwSize: 0x38u);
  this->__vftable = (CFaceEditDispPage_vtbl *)&CFaceEditDispPage::`vftable';
  CDispCreateDlg::CDispCreateDlg(this: &this->m_CreateDlg, pParent: nullptr);
  CDispNoiseDlg::CDispNoiseDlg(this: &this->m_NoiseDlg, pParent: nullptr);
  CDispPaintDistDlg::CDispPaintDistDlg(this: &this->m_PaintDistDlg, pParent: nullptr);
  CDispPaintDataDlg::CDispPaintDataDlg(this: &this->m_PaintDataDlg, pParent: nullptr);
  CPaintSculptDlg::CPaintSculptDlg(this: &this->m_PaintSculptDlg, pParent: nullptr);
  this->m_uiTool = 0;
  *(_WORD *)&this->m_bForceShowWalkable = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C98D0
// Name: protected: void CFaceEditDispPage::OnCheckNoPhysicsCollide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnCheckNoPhysicsCollide(CFaceEditDispPage *this)
{
  HWND Parent; // eax
  CWnd *v3; // eax
  int y; // edi
  CWnd *DlgItem; // eax
  int v6; // ebx
  CMapFace *pMapFace; // eax
  int m_DispHandle; // eax
  int v9; // esi
  CEditDispMgr *v10; // eax
  int v11; // eax
  CFaceEditSheet *pSheet; // [esp+4h] [ebp-8h]
  bool bReset; // [esp+Bh] [ebp-1h]

  Parent = GetParent(hWnd: this->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  pSheet = (CFaceEditSheet *)v3;
  if ( v3 != nullptr )
  {
    y = v3[49].m_ptGestureFrom.y;
    if ( y != 0 )
    {
      DlgItem = CWnd::GetDlgItem(this, nID: 1656);
      bReset = SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) == 0;
      if ( y > 0 )
      {
        v6 = 0;
        do
        {
          pMapFace = pSheet->m_Faces.m_Memory.m_pMemory[v6].pMapFace;
          if ( pMapFace != nullptr )
          {
            m_DispHandle = pMapFace->m_DispHandle;
            if ( (_WORD)m_DispHandle != 0xFFFF )
            {
              v9 = m_DispHandle;
              v10 = EditDispMgr();
              v11 = (int)v10->GetDisp(this: v10, a2: v9);
              if ( v11 != 0 )
              {
                if ( bReset )
                  *(_DWORD *)(v11 + 736) &= ~2u;
                else
                  *(_DWORD *)(v11 + 736) |= 2u;
              }
            }
          }
          ++v6;
          --y;
        }
        while ( y != 0 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C99A0
// Name: protected: void CFaceEditDispPage::OnCheckNoHullCollide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnCheckNoHullCollide(CFaceEditDispPage *this)
{
  HWND Parent; // eax
  CWnd *v3; // eax
  int y; // edi
  CWnd *DlgItem; // eax
  int v6; // ebx
  CMapFace *pMapFace; // eax
  int m_DispHandle; // eax
  int v9; // esi
  CEditDispMgr *v10; // eax
  int v11; // eax
  CFaceEditSheet *pSheet; // [esp+4h] [ebp-8h]
  bool bReset; // [esp+Bh] [ebp-1h]

  Parent = GetParent(hWnd: this->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  pSheet = (CFaceEditSheet *)v3;
  if ( v3 != nullptr )
  {
    y = v3[49].m_ptGestureFrom.y;
    if ( y != 0 )
    {
      DlgItem = CWnd::GetDlgItem(this, nID: 1648);
      bReset = SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) == 0;
      if ( y > 0 )
      {
        v6 = 0;
        do
        {
          pMapFace = pSheet->m_Faces.m_Memory.m_pMemory[v6].pMapFace;
          if ( pMapFace != nullptr )
          {
            m_DispHandle = pMapFace->m_DispHandle;
            if ( (_WORD)m_DispHandle != 0xFFFF )
            {
              v9 = m_DispHandle;
              v10 = EditDispMgr();
              v11 = (int)v10->GetDisp(this: v10, a2: v9);
              if ( v11 != 0 )
              {
                if ( bReset )
                  *(_DWORD *)(v11 + 736) &= ~4u;
                else
                  *(_DWORD *)(v11 + 736) |= 4u;
              }
            }
          }
          ++v6;
          --y;
        }
        while ( y != 0 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9A70
// Name: protected: void CFaceEditDispPage::OnCheckNoRayCollide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnCheckNoRayCollide(CFaceEditDispPage *this)
{
  HWND Parent; // eax
  CWnd *v3; // eax
  int y; // edi
  CWnd *DlgItem; // eax
  int v6; // ebx
  CMapFace *pMapFace; // eax
  int m_DispHandle; // eax
  int v9; // esi
  CEditDispMgr *v10; // eax
  int v11; // eax
  CFaceEditSheet *pSheet; // [esp+4h] [ebp-8h]
  bool bReset; // [esp+Bh] [ebp-1h]

  Parent = GetParent(hWnd: this->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  pSheet = (CFaceEditSheet *)v3;
  if ( v3 != nullptr )
  {
    y = v3[49].m_ptGestureFrom.y;
    if ( y != 0 )
    {
      DlgItem = CWnd::GetDlgItem(this, nID: 1657);
      bReset = SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) == 0;
      if ( y > 0 )
      {
        v6 = 0;
        do
        {
          pMapFace = pSheet->m_Faces.m_Memory.m_pMemory[v6].pMapFace;
          if ( pMapFace != nullptr )
          {
            m_DispHandle = pMapFace->m_DispHandle;
            if ( (_WORD)m_DispHandle != 0xFFFF )
            {
              v9 = m_DispHandle;
              v10 = EditDispMgr();
              v11 = (int)v10->GetDisp(this: v10, a2: v9);
              if ( v11 != 0 )
              {
                if ( bReset )
                  *(_DWORD *)(v11 + 736) &= ~8u;
                else
                  *(_DWORD *)(v11 + 736) |= 8u;
              }
            }
          }
          ++v6;
          --y;
        }
        while ( y != 0 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9B40
// Name: protected: void CFaceEditDispPage::OnSelectAdjacent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnSelectAdjacent(CFaceEditDispPage *this)
{
  IWorldEditDispMgr *ActiveWorldEditDispManager; // ebx
  HWND Parent; // eax
  CFaceEditSheet *v4; // eax
  CFaceEditSheet *v5; // ecx
  int m_Size; // eax
  CMapFace *pMapFace; // eax
  int m_DispHandle; // eax
  int v9; // esi
  CEditDispMgr *v10; // eax
  CMapDisp *v11; // edi
  int (__thiscall *WorldCount)(IWorldEditDispMgr *); // eax
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // esi
  void *v17; // eax
  CMapFace *v18; // esi
  CMapAtom *v19; // eax
  CMapSolid *v20; // eax
  CMapSolid *v21; // edi
  int FaceIndex; // eax
  HWND__ *m_hWnd; // [esp-4h] [ebp-48h]
  int edge1[4]; // [esp+8h] [ebp-3Ch] BYREF
  int edge2[4]; // [esp+18h] [ebp-2Ch] BYREF
  int totalDispCount; // [esp+28h] [ebp-1Ch]
  CMapDisp *pDisp; // [esp+2Ch] [ebp-18h]
  int v28; // [esp+30h] [ebp-14h]
  int iTestDisp; // [esp+34h] [ebp-10h]
  CFaceEditSheet *pSheet; // [esp+38h] [ebp-Ch]
  unsigned int v31; // [esp+3Ch] [ebp-8h]
  bool bSelectedAny; // [esp+43h] [ebp-1h]

  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  m_hWnd = this->m_hWnd;
  bSelectedAny = false;
  Parent = GetParent(hWnd: m_hWnd);
  v4 = (CFaceEditSheet *)CWnd::FromHandle(hWnd: Parent);
  v5 = v4;
  pSheet = v4;
  if ( v4 != nullptr )
  {
    m_Size = v4->m_Faces.m_Size;
    if ( m_Size > 0 )
    {
      v31 = 0;
      v28 = m_Size;
      while ( 1 )
      {
        pMapFace = v5->m_Faces.m_Memory.m_pMemory[v31 / 0xC].pMapFace;
        if ( pMapFace != nullptr )
        {
          m_DispHandle = pMapFace->m_DispHandle;
          if ( (_WORD)m_DispHandle != 0xFFFF )
          {
            v9 = m_DispHandle;
            v10 = EditDispMgr();
            v11 = v10->GetDisp(this: v10, a2: v9);
            WorldCount = ActiveWorldEditDispManager->WorldCount;
            pDisp = v11;
            v13 = WorldCount(this: ActiveWorldEditDispManager);
            v14 = 0;
            totalDispCount = v13;
            iTestDisp = 0;
            if ( v13 > 0 )
            {
              while ( 1 )
              {
                v15 = (int)ActiveWorldEditDispManager->GetFromWorld_2(this: ActiveWorldEditDispManager, a2: v14);
                v16 = v15;
                if ( v15 != 0
                  && (CMapDisp *)v15 != v11
                  && ActiveWorldEditDispManager->NumSharedPoints(
                       this: ActiveWorldEditDispManager,
                       a2: v11,
                       a3: (CMapDisp *)v15,
                       a4: edge1,
                       a5: edge2) == 2 )
                {
                  v17 = (void *)(*(int (__thiscall **)(int))(*(_DWORD *)v16 + 36))(a1: v16);
                  v18 = (CMapFace *)__RTDynamicCast(
                                      inptr: v17,
                                      VfDelta: 0,
                                      SrcType: &CMapAtom `RTTI Type Descriptor',
                                      TargetType: &CMapFace `RTTI Type Descriptor',
                                      isReference: 0);
                  if ( v18 != nullptr && v18->GetSelectionState(this: v18) == SELECT_NONE )
                  {
                    v19 = v18->GetParent(this: v18);
                    v20 = (CMapSolid *)__RTDynamicCast(
                                         inptr: v19,
                                         VfDelta: 0,
                                         SrcType: &CMapAtom `RTTI Type Descriptor',
                                         TargetType: &CMapSolid `RTTI Type Descriptor',
                                         isReference: 0);
                    v21 = v20;
                    if ( v20 != nullptr && (*((_BYTE *)&v20->CMapClass + 180) & 2) != 0 )
                    {
                      FaceIndex = CMapSolid::GetFaceIndex(this: v20, pFace: v18);
                      if ( FaceIndex != -1 )
                      {
                        CFaceEditSheet::ClickFace(
                          this: pSheet,
                          pSolid: v21,
                          faceIndex: FaceIndex,
                          cmd: 2,
                          clickMode: 259);
                        bSelectedAny = true;
                      }
                    }
                  }
                }
                v14 = iTestDisp + 1;
                iTestDisp = v14;
                if ( v14 >= totalDispCount )
                  break;
                v11 = pDisp;
              }
            }
          }
        }
        v31 += 12;
        if ( --v28 == 0 )
          break;
        v5 = pSheet;
      }
      if ( bSelectedAny )
        CMapDoc::UpdateAllViews(this: CMapDoc::m_pMapDoc, nFlags: 16, ub: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9CF0
// Name: protected: void CFaceEditDispPage::UpdatePower(class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::UpdatePower(CFaceEditDispPage *this, CMapDisp *pDisp)
{
  CMapDisp *v2; // edi
  CAfxStringMgr *StringManager; // eax
  int v5; // eax
  bool *v6; // eax

  v2 = pDisp;
  if ( pDisp != nullptr )
  {
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    pDisp = (CMapDisp *)&StringManager->GetNilString(this: StringManager)[1];
    CWnd::GetDlgItemTextA(
      this,
      nID: 1478,
      rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDisp);
    v5 = atoi(nptr: (const char *)pDisp);
    if ( v5 >= 2 )
    {
      if ( v5 > 4 )
        v5 = 4;
    }
    else
    {
      v5 = 2;
    }
    if ( v5 != v2->m_CoreDispInfo.m_Power )
      CMapDisp::Resample(this: v2, power: v5);
    v6 = &pDisp[-1].m_Canvas.m_bValuesDirty[280];
    if ( _InterlockedDecrement(&pDisp[-1].m_FoWTriSoupID) <= 0 )
      (*(void (__stdcall **)(bool *))(**(_DWORD **)v6 + 4))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9DC0
// Name: protected: void CFaceEditDispPage::UpdateElevation(class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFaceEditDispPage::UpdateElevation(CFaceEditDispPage *this@<ecx>, int a2@<ebx>, CMapDisp *pDisp)
{
  CMapDisp *v3; // esi
  CAfxStringMgr *StringManager; // eax
  float v6; // xmm0_4
  bool *v7; // eax

  v3 = pDisp;
  if ( pDisp != nullptr )
  {
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    pDisp = (CMapDisp *)&StringManager->GetNilString(this: StringManager)[1];
    CWnd::GetDlgItemTextA(
      this,
      nID: 1480,
      rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDisp);
    v6 = (float)(int)atof(nptr: (const char *)pDisp);
    if ( v6 != v3->m_CoreDispInfo.m_Elevation )
      CMapDisp::Elevate(this: v3, a2, elevation: v6);
    v7 = &pDisp[-1].m_Canvas.m_bValuesDirty[280];
    if ( _InterlockedDecrement(&pDisp[-1].m_FoWTriSoupID) <= 0 )
      (*(void (__stdcall **)(bool *))(**(_DWORD **)v7 + 4))(a1: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9E90
// Name: protected: void CFaceEditDispPage::UpdateScale(class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFaceEditDispPage::UpdateScale(CFaceEditDispPage *this@<ecx>, int a2@<ebx>, CMapDisp *pDisp)
{
  CMapDisp *v3; // esi
  CAfxStringMgr *StringManager; // eax
  bool *v6; // eax
  float v7; // [esp+Ch] [ebp-10h]

  v3 = pDisp;
  if ( pDisp != nullptr )
  {
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    pDisp = (CMapDisp *)&StringManager->GetNilString(this: StringManager)[1];
    CWnd::GetDlgItemTextA(
      this,
      nID: 1009,
      rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDisp);
    v7 = atof(nptr: (const char *)pDisp);
    if ( v7 != v3->m_Scale )
      CMapDisp::Scale(this: v3, a2, scale: v7);
    v6 = &pDisp[-1].m_Canvas.m_bValuesDirty[280];
    if ( _InterlockedDecrement(&pDisp[-1].m_FoWTriSoupID) <= 0 )
      (*(void (__stdcall **)(bool *))(**(_DWORD **)v6 + 4))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9F60
// Name: protected: void CFaceEditDispPage::FillEditControls(bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CFaceEditDispPage::FillEditControls(CFaceEditDispPage *this, bool bAllDisps)
{
  CAfxStringMgr *StringManager; // eax
  HWND__ *m_hWnd; // ecx
  HWND Parent; // eax
  CWnd *v6; // eax
  CWnd *v7; // ebx
  int v8; // edi
  CEditDispMgr *v9; // eax
  int v10; // eax
  int v11; // edi
  CEditDispMgr *v12; // eax
  int v13; // eax
  int v14; // ecx
  void (__stdcall *v15)(HWND, UINT, WPARAM, LPARAM); // ebx
  CWnd *v16; // edi
  CWnd *v17; // edi
  CWnd *v18; // edi
  CWnd *DlgItem; // eax
  CWnd *v20; // eax
  CToolManager *v21; // eax
  CBaseTool *ToolForID; // eax
  unsigned __int8 *v23; // edi
  CWnd *v24; // eax
  CWnd *v25; // eax
  char *v26; // eax
  int y; // [esp+14h] [ebp-2Ch]
  float v28; // [esp+18h] [ebp-28h]
  float v29; // [esp+1Ch] [ebp-24h]
  unsigned int nValue; // [esp+20h] [ebp-20h]
  int faceCount; // [esp+24h] [ebp-1Ch]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > scale; // [esp+28h] [ebp-18h] BYREF
  float elevation; // [esp+2Ch] [ebp-14h]
  int power; // [esp+30h] [ebp-10h]
  int v35; // [esp+3Ch] [ebp-4h] OVERLAPPED
  char v36; // [esp+4Bh] [ebp+Bh]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  scale.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v35 = 1;
  if ( !bAllDisps )
  {
    DlgItem = CWnd::GetDlgItem(this, nID: 1008);
    SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0x467u, wParam: 0, lParam: 0);
    CWnd::SetDlgItemInt(this, nID: 1478, nValue: 0, bSigned: 1);
    v20 = CWnd::GetDlgItem(this, nID: 1486);
    SendMessageA(hWnd: v20->m_hWnd, Msg: 0x467u, wParam: 0, lParam: 0);
    CWnd::SetDlgItemTextA(this, nID: 1480, lpszString: &var);
    CWnd::SetDlgItemTextA(this, nID: 1009, lpszString: &var);
    goto LABEL_34;
  }
  m_hWnd = this->m_hWnd;
  v29 = 0.0;
  nValue = 0;
  v36 = 1;
  v28 = 1.0;
  power = 16843009;
  HIBYTE(elevation) = 1;
  Parent = GetParent(hWnd: m_hWnd);
  v6 = CWnd::FromHandle(hWnd: Parent);
  v7 = v6;
  if ( v6 == nullptr )
  {
LABEL_34:
    v15 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
    goto LABEL_35;
  }
  y = v6[49].m_ptGestureFrom.y;
  if ( y > 0 )
  {
    v8 = *((unsigned __int16 *)v6[49].m_xAccessibleServer.Release + 210);
    v9 = EditDispMgr();
    v10 = (int)v9->GetDisp(this: v9, a2: v8);
    v29 = *(float *)(v10 + 32);
    nValue = *(_DWORD *)(v10 + 36);
    v28 = *(float *)(v10 + 1088);
    faceCount = 0;
    do
    {
      v11 = (*(unsigned __int16 **)((char *)&v7[49].m_xAccessibleServer.Release + faceCount))[210];
      v12 = EditDispMgr();
      v13 = (int)v12->GetDisp(this: v12, a2: v11);
      if ( nValue != *(_DWORD *)(v13 + 36) )
        v36 = 0;
      if ( v29 != *(float *)(v13 + 32) )
        HIBYTE(power) = 0;
      if ( v28 != *(float *)(v13 + 1088) )
        BYTE2(power) = 0;
      v14 = *(_DWORD *)(v13 + 736);
      if ( (v14 & 2) == 0 )
        BYTE1(power) = 0;
      if ( (v14 & 4) == 0 )
        LOBYTE(power) = 0;
      if ( (v14 & 8) == 0 )
        HIBYTE(elevation) = 0;
      faceCount += 12;
      --y;
    }
    while ( y != 0 );
  }
  CWnd::SetDlgItemTextA(this, nID: 1478, lpszString: &var);
  if ( v36 != 0 )
    CWnd::SetDlgItemInt(this, nID: 1478, nValue, bSigned: 1);
  CWnd::SetDlgItemTextA(this, nID: 1480, lpszString: &var);
  if ( HIBYTE(power) != 0 )
  {
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &scale, pszFormat: "%4.2f", v29);
    CWnd::SetDlgItemTextA(this, nID: 1480, lpszString: scale.m_pszData);
  }
  CWnd::SetDlgItemTextA(this, nID: 1009, lpszString: &var);
  if ( BYTE2(power) != 0 )
  {
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &scale, pszFormat: "%4.4f", v28);
    CWnd::SetDlgItemTextA(this, nID: 1009, lpszString: scale.m_pszData);
  }
  v15 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
  v16 = CWnd::GetDlgItem(this, nID: 1656);
  SendMessageA(hWnd: v16->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
  if ( BYTE1(power) != 0 )
    SendMessageA(hWnd: v16->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
  v17 = CWnd::GetDlgItem(this, nID: 1648);
  SendMessageA(hWnd: v17->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
  if ( (_BYTE)power != 0 )
    SendMessageA(hWnd: v17->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
  v18 = CWnd::GetDlgItem(this, nID: 1657);
  SendMessageA(hWnd: v18->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
  if ( HIBYTE(elevation) != 0 )
    SendMessageA(hWnd: v18->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
LABEL_35:
  v21 = ToolManager();
  ToolForID = CToolManager::GetToolForID(this: v21, eToolID: TOOL_FACEEDIT_DISP);
  v23 = (unsigned __int8 *)__RTDynamicCast(
                             inptr: ToolForID,
                             VfDelta: 0,
                             SrcType: &CBaseTool `RTTI Type Descriptor',
                             TargetType: &CToolDisplace `RTTI Type Descriptor',
                             isReference: 0);
  if ( v23 != nullptr )
  {
    v24 = CWnd::GetDlgItem(this, nID: 1489);
    v15(hWnd: v24->m_hWnd, Msg: 0xF1u, wParam: v23[1181], lParam: 0);
    v25 = CWnd::GetDlgItem(this, nID: 1490);
    v15(hWnd: v25->m_hWnd, Msg: 0xF1u, wParam: v23[1182], lParam: 0);
  }
  v35 = -1;
  v26 = scale.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)scale.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v26 + 4))(a1: v26);
}

//------------------------------------------------------------------------------
// Address: 0x100CA380
// Name: public: void CFaceEditDispPage::UpdateDialogData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::UpdateDialogData(CFaceEditDispPage *this)
{
  HWND Parent; // eax
  CWnd *v3; // eax
  int y; // ecx
  int p_Release; // eax
  bool bHasFace; // [esp+Ch] [ebp-8h]
  bool bAllDisps; // [esp+10h] [ebp-4h]

  bAllDisps = false;
  bHasFace = false;
  Parent = GetParent(hWnd: this->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  if ( v3 != nullptr )
  {
    y = v3[49].m_ptGestureFrom.y;
    if ( y > 0 )
    {
      bHasFace = true;
      bAllDisps = true;
      p_Release = (int)&v3[49].m_xAccessibleServer.Release;
      do
      {
        if ( *(_WORD *)(*(_DWORD *)p_Release + 420) == 0xFFFF )
          bAllDisps = false;
        p_Release += 12;
        --y;
      }
      while ( y != 0 );
    }
  }
  CFaceEditDispPage::FillEditControls(this, bAllDisps);
  CFaceEditDispPage::UpdateEditControls(this, bAllDisps, bHasFace);
}

//------------------------------------------------------------------------------
// Address: 0x100CA400
// Name: public: void CFaceEditDispPage::SetTool(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::SetTool(CFaceEditDispPage *this, CButton *tool)
{
  CWnd *DlgItem; // edi
  CWnd *v4; // ebx
  CButton *pButtonBuild; // [esp+Ch] [ebp-20h]
  CButton *pButtonWalk; // [esp+10h] [ebp-1Ch]
  CButton *pbuttonNoise; // [esp+14h] [ebp-18h]
  CButton *pbuttonSew; // [esp+18h] [ebp-14h]
  CButton *pbuttonSubdiv; // [esp+1Ch] [ebp-10h]
  CButton *pbuttonPaintData; // [esp+20h] [ebp-Ch]
  CButton *pbuttonPaintSculpt; // [esp+24h] [ebp-8h]
  CButton *pbuttonPaintGeo; // [esp+28h] [ebp-4h]
  CButton *pbuttonDestroy; // [esp+34h] [ebp+8h]

  if ( this->m_uiTool == 3 )
    this->m_PaintDistDlg.DestroyWindow(this: &this->m_PaintDistDlg);
  if ( this->m_uiTool == 5 )
    this->m_PaintSculptDlg.DestroyWindow(this: &this->m_PaintSculptDlg);
  if ( this->m_uiTool == 4 )
    this->m_PaintDataDlg.DestroyWindow(this: &this->m_PaintDataDlg);
  if ( this->m_uiTool == 9 )
  {
    if ( this->m_bForceShowWalkable )
    {
      if ( CMapDoc::m_pMapDoc != nullptr )
        CMapDoc::m_pMapDoc->m_bDispDrawWalkable = false;
      this->m_bForceShowWalkable = false;
    }
    if ( this->m_bForceShowBuildable )
    {
      if ( CMapDoc::m_pMapDoc != nullptr )
        CMapDoc::m_pMapDoc->m_bDispDrawBuildable = false;
      this->m_bForceShowBuildable = false;
    }
  }
  if ( this->m_uiTool == 10 )
  {
    if ( this->m_bForceShowWalkable )
    {
      if ( CMapDoc::m_pMapDoc != nullptr )
        CMapDoc::m_pMapDoc->m_bDispDrawWalkable = false;
      this->m_bForceShowWalkable = false;
    }
    if ( this->m_bForceShowBuildable )
    {
      if ( CMapDoc::m_pMapDoc != nullptr )
        CMapDoc::m_pMapDoc->m_bDispDrawBuildable = false;
      this->m_bForceShowBuildable = false;
    }
  }
  this->m_uiTool = (unsigned int)tool;
  DlgItem = CWnd::GetDlgItem(this, nID: 1552);
  v4 = CWnd::GetDlgItem(this, nID: 1474);
  pbuttonDestroy = (CButton *)CWnd::GetDlgItem(this, nID: 1476);
  pbuttonPaintGeo = (CButton *)CWnd::GetDlgItem(this, nID: 1558);
  pbuttonPaintSculpt = (CButton *)CWnd::GetDlgItem(this, nID: 1560);
  pbuttonPaintData = (CButton *)CWnd::GetDlgItem(this, nID: 1559);
  pbuttonSubdiv = (CButton *)CWnd::GetDlgItem(this, nID: 1495);
  pbuttonSew = (CButton *)CWnd::GetDlgItem(this, nID: 1496);
  pbuttonNoise = (CButton *)CWnd::GetDlgItem(this, nID: 1557);
  pButtonWalk = (CButton *)CWnd::GetDlgItem(this, nID: 1580);
  pButtonBuild = (CButton *)CWnd::GetDlgItem(this, nID: 1581);
  SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: this->m_uiTool == 0, lParam: 0);
  SendMessageA(hWnd: v4->m_hWnd, Msg: 0xF1u, wParam: this->m_uiTool == 1, lParam: 0);
  SendMessageA(hWnd: pbuttonDestroy->m_hWnd, Msg: 0xF1u, wParam: this->m_uiTool == 2, lParam: 0);
  SendMessageA(hWnd: pbuttonPaintGeo->m_hWnd, Msg: 0xF1u, wParam: this->m_uiTool == 3, lParam: 0);
  SendMessageA(hWnd: pbuttonPaintSculpt->m_hWnd, Msg: 0xF1u, wParam: this->m_uiTool == 5, lParam: 0);
  SendMessageA(hWnd: pbuttonPaintData->m_hWnd, Msg: 0xF1u, wParam: this->m_uiTool == 4, lParam: 0);
  SendMessageA(hWnd: pbuttonSubdiv->m_hWnd, Msg: 0xF1u, wParam: this->m_uiTool == 7, lParam: 0);
  SendMessageA(hWnd: pbuttonSew->m_hWnd, Msg: 0xF1u, wParam: this->m_uiTool == 6, lParam: 0);
  SendMessageA(hWnd: pbuttonNoise->m_hWnd, Msg: 0xF1u, wParam: this->m_uiTool == 8, lParam: 0);
  SendMessageA(hWnd: pButtonWalk->m_hWnd, Msg: 0xF1u, wParam: this->m_uiTool == 9, lParam: 0);
  SendMessageA(hWnd: pButtonBuild->m_hWnd, Msg: 0xF1u, wParam: this->m_uiTool == 10, lParam: 0);
  CFaceEditDispPage::UpdateDialogData(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CA6F0
// Name: protected: void CFaceEditDispPage::OnButtonSelect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnButtonSelect(CFaceEditDispPage *this)
{
  CToolManager *v2; // eax
  CBaseTool *ToolForID; // eax
  _DWORD *v4; // eax

  CFaceEditDispPage::SetTool(this, tool: nullptr);
  v2 = ToolManager();
  ToolForID = CToolManager::GetToolForID(this: v2, eToolID: TOOL_FACEEDIT_DISP);
  v4 = __RTDynamicCast(
         inptr: ToolForID,
         VfDelta: 0,
         SrcType: &CBaseTool `RTTI Type Descriptor',
         TargetType: &CToolDisplace `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 != nullptr )
  {
    v4[3] = 1;
    CFaceEditDispPage::UpdateDialogData(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA740
// Name: protected: void CFaceEditDispPage::OnButtonPaintGeo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnButtonPaintGeo(CFaceEditDispPage *this)
{
  CToolManager *v2; // eax
  CBaseTool *ToolForID; // eax
  _DWORD *v4; // eax

  CFaceEditDispPage::SetTool(this, tool: (CButton *)3);
  v2 = ToolManager();
  ToolForID = CToolManager::GetToolForID(this: v2, eToolID: TOOL_FACEEDIT_DISP);
  v4 = __RTDynamicCast(
         inptr: ToolForID,
         VfDelta: 0,
         SrcType: &CBaseTool `RTTI Type Descriptor',
         TargetType: &CToolDisplace `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 != nullptr )
  {
    v4[3] = 2;
    CFaceEditDispPage::UpdateDialogData(this);
  }
  if ( this->m_PaintDistDlg.Create(this: &this->m_PaintDistDlg, a2: 309u, a3: this) != 0 )
    CWnd::ShowWindow(this: &this->m_PaintDistDlg, nCmdShow: 5);
}

//------------------------------------------------------------------------------
// Address: 0x100CA7B0
// Name: public: void CFaceEditDispPage::OnBnClickedDispSculptPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnBnClickedDispSculptPaint(CFaceEditDispPage *this)
{
  CToolManager *v2; // eax
  CBaseTool *ToolForID; // eax
  _DWORD *v4; // eax

  CFaceEditDispPage::SetTool(this, tool: (CButton *)5);
  v2 = ToolManager();
  ToolForID = CToolManager::GetToolForID(this: v2, eToolID: TOOL_FACEEDIT_DISP);
  v4 = __RTDynamicCast(
         inptr: ToolForID,
         VfDelta: 0,
         SrcType: &CBaseTool `RTTI Type Descriptor',
         TargetType: &CToolDisplace `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 != nullptr )
  {
    v4[3] = 6;
    CFaceEditDispPage::UpdateDialogData(this);
  }
  if ( this->m_PaintSculptDlg.Create(this: &this->m_PaintSculptDlg, a2: 351u, a3: this) != 0 )
    CWnd::ShowWindow(this: &this->m_PaintSculptDlg, nCmdShow: 5);
}

//------------------------------------------------------------------------------
// Address: 0x100CA820
// Name: protected: void CFaceEditDispPage::OnButtonPaintData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnButtonPaintData(CFaceEditDispPage *this)
{
  CToolManager *v2; // eax
  CBaseTool *ToolForID; // eax
  _DWORD *v4; // eax

  CFaceEditDispPage::SetTool(this, tool: (CButton *)4);
  v2 = ToolManager();
  ToolForID = CToolManager::GetToolForID(this: v2, eToolID: TOOL_FACEEDIT_DISP);
  v4 = __RTDynamicCast(
         inptr: ToolForID,
         VfDelta: 0,
         SrcType: &CBaseTool `RTTI Type Descriptor',
         TargetType: &CToolDisplace `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 != nullptr )
  {
    v4[3] = 2;
    CFaceEditDispPage::UpdateDialogData(this);
  }
  if ( this->m_PaintDataDlg.Create(this: &this->m_PaintDataDlg, a2: 310u, a3: this) != 0 )
    CWnd::ShowWindow(this: &this->m_PaintDataDlg, nCmdShow: 5);
}

//------------------------------------------------------------------------------
// Address: 0x100CA890
// Name: protected: void CFaceEditDispPage::OnButtonTagWalkable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnButtonTagWalkable(CFaceEditDispPage *this)
{
  CMapDoc *v1; // edi
  CToolManager *v3; // eax
  CBaseTool *ToolForID; // eax
  _DWORD *v5; // ebx

  v1 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    v3 = ToolManager();
    ToolForID = CToolManager::GetToolForID(this: v3, eToolID: TOOL_FACEEDIT_DISP);
    v5 = __RTDynamicCast(
           inptr: ToolForID,
           VfDelta: 0,
           SrcType: &CBaseTool `RTTI Type Descriptor',
           TargetType: &CToolDisplace `RTTI Type Descriptor',
           isReference: 0);
    if ( v5 != nullptr )
    {
      if ( this->m_uiTool == 9 )
      {
        CFaceEditDispPage::SetTool(this, tool: nullptr);
        v5[3] = 3;
        if ( this->m_bForceShowWalkable )
        {
          v1->m_bDispDrawWalkable = false;
          this->m_bForceShowWalkable = false;
          CFaceEditDispPage::UpdateDialogData(this);
          return;
        }
      }
      else
      {
        CFaceEditDispPage::SetTool(this, tool: (CButton *)9);
        v5[3] = 4;
        if ( !v1->m_bDispDrawWalkable )
        {
          v1->m_bDispDrawWalkable = true;
          this->m_bForceShowWalkable = true;
        }
      }
      CFaceEditDispPage::UpdateDialogData(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA940
// Name: protected: void CFaceEditDispPage::OnButtonTagBuildable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnButtonTagBuildable(CFaceEditDispPage *this)
{
  CMapDoc *v1; // ebx
  CToolManager *v3; // eax
  CBaseTool *ToolForID; // eax
  _DWORD *v5; // edi

  v1 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    v3 = ToolManager();
    ToolForID = CToolManager::GetToolForID(this: v3, eToolID: TOOL_FACEEDIT_DISP);
    v5 = __RTDynamicCast(
           inptr: ToolForID,
           VfDelta: 0,
           SrcType: &CBaseTool `RTTI Type Descriptor',
           TargetType: &CToolDisplace `RTTI Type Descriptor',
           isReference: 0);
    if ( v5 != nullptr )
    {
      if ( this->m_uiTool == 10 )
      {
        CFaceEditDispPage::SetTool(this, tool: nullptr);
        v5[3] = 3;
        if ( this->m_bForceShowBuildable )
        {
          v1->m_bDispDrawBuildable = false;
          this->m_bForceShowBuildable = false;
          CFaceEditDispPage::UpdateDialogData(this);
          return;
        }
      }
      else
      {
        CFaceEditDispPage::SetTool(this, tool: (CButton *)0xA);
        v5[3] = 5;
        if ( !v1->m_bDispDrawBuildable )
        {
          v1->m_bDispDrawBuildable = true;
          this->m_bForceShowBuildable = true;
        }
      }
      CFaceEditDispPage::UpdateDialogData(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA9F0
// Name: protected: void CFaceEditDispPage::OnSpinUpDown(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnSpinUpDown(CFaceEditDispPage *this, ATL::CStringData *pNMHDR, int *pResult)
{
  tagNMHDR *v3; // edi
  unsigned int nDataLength; // eax
  CWnd *v5; // esi
  CAfxStringMgr *v6; // eax
  CWnd *DlgItem; // esi
  CAfxStringMgr *StringManager; // eax
  int v9; // eax
  unsigned int *v10; // eax
  float v11; // [esp+10h] [ebp-10h]

  v3 = (tagNMHDR *)pNMHDR;
  nDataLength = pNMHDR->nDataLength;
  if ( nDataLength == 1008 )
  {
    DlgItem = CWnd::GetDlgItem(this, nID: 1478);
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    pNMHDR = StringManager->GetNilString(this: StringManager) + 1;
    CWnd::GetWindowTextA(
      this: DlgItem,
      rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pNMHDR);
    v9 = atoi(nptr: (const char *)pNMHDR) - v3[1].idFrom;
    if ( v9 >= 2 )
    {
      if ( v9 > 4 )
        v9 = 4;
    }
    else
    {
      v9 = 2;
    }
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pNMHDR,
      pszFormat: "%d",
      v9);
    CWnd::SetWindowTextA(this: DlgItem, lpszString: (const char *)pNMHDR);
    *pResult = 0;
  }
  else
  {
    if ( nDataLength != 1486 )
      return;
    v5 = CWnd::GetDlgItem(this, nID: 1480);
    v6 = AfxGetStringManager();
    if ( v6 == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    pNMHDR = v6->GetNilString(this: v6) + 1;
    CWnd::GetWindowTextA(this: v5, rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pNMHDR);
    v11 = atof(nptr: (const char *)pNMHDR);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pNMHDR,
      pszFormat: "%4.2f",
      (float)(v11 - (float)((float)(int)v3[1].idFrom * 0.5)));
    CWnd::SetWindowTextA(this: v5, lpszString: (const char *)pNMHDR);
    *pResult = 0;
  }
  v10 = (unsigned int *)&pNMHDR[-1];
  if ( _InterlockedDecrement(&pNMHDR[-1].nRefs) <= 0 )
    (*(void (__stdcall **)(unsigned int *))(*(_DWORD *)*v10 + 4))(a1: v10);
}

//------------------------------------------------------------------------------
// Address: 0x100CAB90
// Name: public: virtual int CFaceEditDispPage::OnSetActive(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFaceEditDispPage::OnSetActive(CFaceEditDispPage *this)
{
  CToolManager *v2; // eax
  CToolManager *v3; // eax
  CBaseTool *ToolForID; // eax
  _DWORD *v5; // eax

  v2 = ToolManager();
  CToolManager::SetTool(this: v2, eNewTool: TOOL_FACEEDIT_DISP);
  CFaceEditDispPage::SetTool(this, tool: nullptr);
  v3 = ToolManager();
  ToolForID = CToolManager::GetToolForID(this: v3, eToolID: TOOL_FACEEDIT_DISP);
  v5 = __RTDynamicCast(
         inptr: ToolForID,
         VfDelta: 0,
         SrcType: &CBaseTool `RTTI Type Descriptor',
         TargetType: &CToolDisplace `RTTI Type Descriptor',
         isReference: 0);
  if ( v5 != nullptr )
  {
    v5[3] = 1;
    CFaceEditDispPage::UpdateDialogData(this);
  }
  return CPropertyPage::OnSetActive(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CABF0
// Name: public: void CFaceEditDispPage::ClickFace(class CMapSolid __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::ClickFace(
        CFaceEditDispPage *this,
        CMapSolid *pSolid,
        int faceIndex,
        int cmd,
        int clickMode)
{
  this->m_bIsEditable = pSolid == nullptr || pSolid->IsEditable(this: pSolid);
  CFaceEditDispPage::UpdateDialogData(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CAC30
// Name: protected: void CFaceEditDispPage::OnButtonCreate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnButtonCreate(CFaceEditDispPage *this)
{
  CFaceEditDispPage *v1; // ebx
  HWND Parent; // eax
  CWnd *v3; // eax
  CFaceEditSheet *v4; // edi
  int y; // esi
  CMapFace *pMapFace; // edi
  CEditDispMgr *v7; // eax
  int v8; // ebx
  CEditDispMgr *v9; // eax
  CMapDisp *v10; // esi
  CMapClass *v11; // esi
  CMapDoc *v12; // edi
  int power; // [esp+Ch] [ebp-18h]
  IWorldEditDispMgr *pDispMgr; // [esp+10h] [ebp-14h]
  CFaceEditSheet *pSheet; // [esp+14h] [ebp-10h]
  int v16; // [esp+18h] [ebp-Ch]
  int v18; // [esp+20h] [ebp-4h]

  v1 = this;
  CFaceEditDispPage::SetTool(this, tool: (CButton *)1);
  Parent = GetParent(hWnd: v1->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  v4 = (CFaceEditSheet *)v3;
  pSheet = (CFaceEditSheet *)v3;
  if ( v3 == nullptr )
  {
LABEL_16:
    CFaceEditDispPage::SetTool(this: v1, tool: nullptr);
    if ( CMapDoc::m_pMapDoc != nullptr )
      CMapDoc::m_pMapDoc->SetModifiedFlag(this: CMapDoc::m_pMapDoc, a2: 1);
    CFaceEditDispPage::UpdateDialogData(this: v1);
    return;
  }
  y = v3[49].m_ptGestureFrom.y;
  if ( y == 0 )
    return;
  if ( v1->m_CreateDlg.DoModal(this: &v1->m_CreateDlg) == 2 )
  {
    CFaceEditDispPage::SetTool(this: v1, tool: nullptr);
    return;
  }
  power = v1->m_CreateDlg.m_Power;
  pDispMgr = GetActiveWorldEditDispManager();
  if ( pDispMgr != nullptr )
  {
    if ( y > 0 )
    {
      v18 = 0;
      v16 = y;
      while ( 1 )
      {
        pMapFace = v4->m_Faces.m_Memory.m_pMemory[v18].pMapFace;
        if ( pMapFace != nullptr && pMapFace->nPoints == 4 && pMapFace->m_DispHandle == 0xFFFF )
        {
          v7 = EditDispMgr();
          v8 = v7->Create(this: v7);
          v9 = EditDispMgr();
          v10 = v9->GetDisp(this: v9, a2: v8);
          if ( v10 != nullptr )
          {
            CMapFace::SetDisp(this: pMapFace, handle: v8, bDestroyPrevious: true);
            v10->SetParent(this: v10, a2: pMapFace);
            CMapDisp::InitDispSurfaceData(this: v10, pFace: pMapFace, bGenerateStartPoint: true);
            pDispMgr->AddToWorld(this: pDispMgr, a2: v8);
            CMapDisp::InitData(this: v10, power);
            CMapDisp::Create(this: v10, a2: v8);
            v11 = (CMapClass *)pMapFace->GetParent(this: pMapFace);
            v11->PostUpdate(this: v11, a2: Notify_Changed);
            v12 = CMapDoc::m_pMapDoc;
            CMapDoc::RemoveFromAutoVisGroups(this: CMapDoc::m_pMapDoc, pObject: v11);
            CMapDoc::AddToAutoVisGroup(this: v12, pObject: v11);
          }
          v1 = this;
        }
        ++v18;
        if ( --v16 == 0 )
          break;
        v4 = pSheet;
      }
    }
    goto LABEL_16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CADD0
// Name: protected: void CFaceEditDispPage::OnButtonDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnButtonDestroy(CFaceEditDispPage *this)
{
  CFaceEditDispPage *v1; // esi
  HWND Parent; // eax
  CWnd *v3; // eax
  CFaceEditSheet *v4; // ebx
  int y; // esi
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  IWorldEditDispMgr *v7; // edi
  CFaceEditSheet::StoredFace_t *m_pMemory; // ecx
  unsigned __int16 *pMapFace; // esi
  int v10; // eax
  CMapClass *v11; // edi
  int v12; // ebx
  CEditDispMgr *v13; // eax
  CMapDoc *v14; // esi
  CFaceEditSheet *pSheet; // [esp+10h] [ebp-10h]
  int i; // [esp+14h] [ebp-Ch]
  int v18; // [esp+18h] [ebp-8h]
  IWorldEditDispMgr *pDispMgr; // [esp+1Ch] [ebp-4h]

  v1 = this;
  CFaceEditDispPage::SetTool(this, tool: (CButton *)2);
  Parent = GetParent(hWnd: v1->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  v4 = (CFaceEditSheet *)v3;
  pSheet = (CFaceEditSheet *)v3;
  if ( v3 != nullptr )
  {
    y = v3[49].m_ptGestureFrom.y;
    if ( y == 0 )
      return;
    ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
    v7 = ActiveWorldEditDispManager;
    pDispMgr = ActiveWorldEditDispManager;
    if ( ActiveWorldEditDispManager == nullptr )
      return;
    ActiveWorldEditDispManager->PreUndo(this: ActiveWorldEditDispManager, a2: "Displacement Destroy");
    if ( y > 0 )
    {
      v18 = 0;
      for ( i = y; i != 0; --i )
      {
        m_pMemory = v4->m_Faces.m_Memory.m_pMemory;
        pMapFace = (unsigned __int16 *)m_pMemory[v18].pMapFace;
        if ( pMapFace != nullptr && pMapFace[210] != 0xFFFF )
        {
          v10 = (*(int (__thiscall **)(CMapFace *))(*(_DWORD *)pMapFace + 36))(a1: m_pMemory[v18].pMapFace);
          v11 = (CMapClass *)v10;
          if ( v10 == 0 || (*(_BYTE *)(v10 + 180) & 2) != 0 )
          {
            v12 = pMapFace[210];
            pDispMgr->Undo(this: pDispMgr, a2: v12, a3: false);
            pDispMgr->RemoveFromWorld(this: pDispMgr, a2: v12);
            if ( pMapFace[210] != 0xFFFF )
            {
              v13 = EditDispMgr();
              v13->Destroy(this: v13, a2: pMapFace[210]);
            }
            pMapFace[210] = -1;
            v11->PostUpdate(this: v11, a2: Notify_Changed);
            v14 = CMapDoc::m_pMapDoc;
            CMapDoc::RemoveFromAutoVisGroups(this: CMapDoc::m_pMapDoc, pObject: v11);
            CMapDoc::AddToAutoVisGroup(this: v14, pObject: v11);
            v4 = pSheet;
          }
          v7 = pDispMgr;
        }
        ++v18;
      }
    }
    v7->PostUndo(this: v7);
    v1 = this;
  }
  CFaceEditDispPage::SetTool(this: v1, tool: nullptr);
  if ( CMapDoc::m_pMapDoc != nullptr )
    CMapDoc::m_pMapDoc->SetModifiedFlag(this: CMapDoc::m_pMapDoc, a2: 1);
  CFaceEditDispPage::UpdateDialogData(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100CAF40
// Name: protected: void CFaceEditDispPage::OnButtonNoise(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnButtonNoise(CFaceEditDispPage *this)
{
  HWND Parent; // eax
  CWnd *v3; // eax
  int y; // esi
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  IWorldEditDispMgr *v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // esi
  CEditDispMgr *v10; // eax
  CMapDisp *v11; // eax
  CWnd *v12; // [esp+18h] [ebp-Ch]
  int min; // [esp+1Ch] [ebp-8h]
  int max; // [esp+20h] [ebp-4h]

  CFaceEditDispPage::SetTool(this, tool: (CButton *)8);
  Parent = GetParent(hWnd: this->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  v12 = v3;
  if ( v3 == nullptr )
  {
LABEL_13:
    CFaceEditDispPage::SetTool(this, tool: nullptr);
    if ( CMapDoc::m_pMapDoc != nullptr )
      CMapDoc::m_pMapDoc->SetModifiedFlag(this: CMapDoc::m_pMapDoc, a2: 1);
    CFaceEditDispPage::UpdateDialogData(this);
    return;
  }
  y = v3[49].m_ptGestureFrom.y;
  if ( y == 0 )
    return;
  if ( this->m_NoiseDlg.DoModal(this: &this->m_NoiseDlg) == 2 )
  {
    CFaceEditDispPage::SetTool(this, tool: nullptr);
    return;
  }
  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  v6 = ActiveWorldEditDispManager;
  if ( ActiveWorldEditDispManager != nullptr )
  {
    ActiveWorldEditDispManager->PreUndo(this: ActiveWorldEditDispManager, a2: "Displacement Noise");
    if ( y > 0 )
    {
      max = 0;
      for ( min = y; min != 0; --min )
      {
        v7 = *(int *)((char *)&v12[49].m_xAccessibleServer.Release + max);
        if ( v7 != 0 )
        {
          v8 = *(unsigned __int16 *)(v7 + 420);
          if ( (_WORD)v8 != 0xFFFF )
          {
            v9 = v8;
            v6->Undo(this: v6, a2: v8, a3: false);
            v10 = EditDispMgr();
            v11 = v10->GetDisp(this: v10, a2: v9);
            CMapDisp::ApplyNoise(this: v11, min: this->m_NoiseDlg.m_Min, max: this->m_NoiseDlg.m_Max, rockiness: 1.0);
          }
        }
        max += 12;
      }
    }
    v6->PostUndo(this: v6);
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CB090
// Name: protected: void CFaceEditDispPage::OnButtonSubdivide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnButtonSubdivide(CFaceEditDispPage *this)
{
  CFaceEditDispPage *v1; // esi
  IWorldEditDispMgr *ActiveWorldEditDispManager; // edi
  HWND Parent; // eax
  CWnd *v4; // eax
  CFaceEditSheet *v5; // ecx
  int y; // eax
  int v7; // ebx
  CMapFace *pMapFace; // eax
  int m_DispHandle; // eax
  int v10; // esi
  CEditDispMgr *v11; // eax
  int v12; // eax
  CFaceEditSheet *pSheet; // [esp+8h] [ebp-Ch]
  int i; // [esp+10h] [ebp-4h]

  v1 = this;
  CFaceEditDispPage::SetTool(this, tool: (CButton *)7);
  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  if ( ActiveWorldEditDispManager != nullptr )
  {
    ActiveWorldEditDispManager->SelectClear(this: ActiveWorldEditDispManager);
    Parent = GetParent(hWnd: v1->m_hWnd);
    v4 = CWnd::FromHandle(hWnd: Parent);
    v5 = (CFaceEditSheet *)v4;
    pSheet = (CFaceEditSheet *)v4;
    if ( v4 != nullptr )
    {
      y = v4[49].m_ptGestureFrom.y;
      if ( y == 0 )
        return;
      if ( y > 0 )
      {
        v7 = 0;
        for ( i = y; i != 0; --i )
        {
          pMapFace = v5->m_Faces.m_Memory.m_pMemory[v7].pMapFace;
          if ( pMapFace != nullptr )
          {
            m_DispHandle = pMapFace->m_DispHandle;
            if ( (_WORD)m_DispHandle != 0xFFFF )
            {
              v10 = m_DispHandle;
              ActiveWorldEditDispManager->AddToSelect(this: ActiveWorldEditDispManager, a2: m_DispHandle);
              v11 = EditDispMgr();
              v12 = (int)v11->GetDisp(this: v11, a2: v10);
              v1 = this;
              v5 = pSheet;
              *(_DWORD *)(v12 + 868) = -1;
            }
          }
          ++v7;
        }
      }
    }
    ActiveWorldEditDispManager->CatmullClarkSubdivide(this: ActiveWorldEditDispManager);
    CFaceEditDispPage::SetTool(this: v1, tool: nullptr);
    if ( CMapDoc::m_pMapDoc != nullptr )
      CMapDoc::m_pMapDoc->SetModifiedFlag(this: CMapDoc::m_pMapDoc, a2: 1);
    CFaceEditDispPage::UpdateDialogData(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CB180
// Name: protected: void CFaceEditDispPage::OnButtonSew(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnButtonSew(CFaceEditDispPage *this)
{
  CFaceEditDispPage *v1; // esi
  HWND Parent; // eax
  CWnd *v3; // eax
  CFaceEditSheet *v4; // edi
  int y; // ebx
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  IWorldEditDispMgr *v7; // esi
  int v8; // edi
  CMapFace *pMapFace; // eax
  int m_DispHandle; // eax
  int v11; // esi
  CMapFace *v12; // ecx
  int v13; // eax
  CFaceEditSheet *pSheet; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v1 = this;
  CFaceEditDispPage::SetTool(this, tool: (CButton *)6);
  Parent = GetParent(hWnd: v1->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  v4 = (CFaceEditSheet *)v3;
  pSheet = (CFaceEditSheet *)v3;
  if ( v3 != nullptr )
  {
    y = v3[49].m_ptGestureFrom.y;
    if ( y == 0 )
      return;
    ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
    v7 = ActiveWorldEditDispManager;
    if ( ActiveWorldEditDispManager == nullptr )
      return;
    ActiveWorldEditDispManager->PreUndo(this: ActiveWorldEditDispManager, a2: "Displacement Sewing");
    if ( y > 0 )
    {
      v8 = 0;
      for ( i = y; i != 0; --i )
      {
        pMapFace = pSheet->m_Faces.m_Memory.m_pMemory[v8].pMapFace;
        if ( pMapFace != nullptr )
        {
          m_DispHandle = pMapFace->m_DispHandle;
          if ( (_WORD)m_DispHandle != 0xFFFF )
            v7->Undo(this: v7, a2: m_DispHandle, a3: false);
        }
        ++v8;
      }
      v4 = pSheet;
    }
    v7->PostUndo(this: v7);
    FaceListSewEdges();
    if ( y > 0 )
    {
      v11 = 0;
      do
      {
        v12 = v4->m_Faces.m_Memory.m_pMemory[v11].pMapFace;
        if ( v12 != nullptr && v12->m_DispHandle != 0xFFFF )
        {
          v13 = (int)v12->GetParent(this: v12);
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v13 + 60))(a1: v13, a2: 4);
        }
        ++v11;
        --y;
      }
      while ( y != 0 );
    }
    v1 = this;
  }
  CFaceEditDispPage::SetTool(this: v1, tool: nullptr);
  if ( CMapDoc::m_pMapDoc != nullptr )
    CMapDoc::m_pMapDoc->SetModifiedFlag(this: CMapDoc::m_pMapDoc, a2: 1);
  CFaceEditDispPage::UpdateDialogData(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100CB2B0
// Name: protected: void CFaceEditDispPage::OnButtonInvertAlpha(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnButtonInvertAlpha(CFaceEditDispPage *this)
{
  CFaceEditDispPage *v1; // esi
  HWND Parent; // eax
  CWnd *v3; // eax
  int v4; // ebx
  int y; // eax
  int v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // esi
  CEditDispMgr *v10; // eax
  CMapDisp *v11; // eax
  int i; // [esp+Ch] [ebp-4h]

  v1 = this;
  Parent = GetParent(hWnd: this->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  v4 = (int)v3;
  if ( v3 != nullptr )
  {
    y = v3[49].m_ptGestureFrom.y;
    if ( y > 0 )
    {
      v6 = 0;
      for ( i = y; i != 0; --i )
      {
        v7 = *(_DWORD *)(v6 + *(_DWORD *)(v4 + 5736) + 4);
        if ( v7 != 0 )
        {
          v8 = *(unsigned __int16 *)(v7 + 420);
          if ( (_WORD)v8 != 0xFFFF )
          {
            v9 = v8;
            v10 = EditDispMgr();
            v11 = v10->GetDisp(this: v10, a2: v9);
            CMapDisp::InvertAlpha(this: v11, a2: v4, a3: v9);
          }
        }
        v6 += 12;
      }
      v1 = this;
    }
  }
  if ( CMapDoc::m_pMapDoc != nullptr )
    CMapDoc::m_pMapDoc->SetModifiedFlag(this: CMapDoc::m_pMapDoc, a2: 1);
  CFaceEditDispPage::UpdateDialogData(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100CB350
// Name: protected: void CFaceEditDispPage::OnButtonApply(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditDispPage::OnButtonApply(CFaceEditDispPage *this)
{
  HWND Parent; // eax
  CWnd *v3; // eax
  CFaceEditSheet *v4; // ecx
  int y; // eax
  int v6; // ebx
  CMapFace *pMapFace; // eax
  int m_DispHandle; // eax
  int v9; // esi
  CEditDispMgr *v10; // eax
  CMapDisp *v11; // esi
  CFaceEditSheet *pSheet; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  Parent = GetParent(hWnd: this->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  v4 = (CFaceEditSheet *)v3;
  pSheet = (CFaceEditSheet *)v3;
  if ( v3 != nullptr )
  {
    y = v3[49].m_ptGestureFrom.y;
    if ( y > 0 )
    {
      v6 = 0;
      for ( i = y; i != 0; --i )
      {
        pMapFace = v4->m_Faces.m_Memory.m_pMemory[v6].pMapFace;
        if ( pMapFace != nullptr )
        {
          m_DispHandle = pMapFace->m_DispHandle;
          if ( (_WORD)m_DispHandle != 0xFFFF )
          {
            v9 = m_DispHandle;
            v10 = EditDispMgr();
            v11 = v10->GetDisp(this: v10, a2: v9);
            CFaceEditDispPage::UpdatePower(this, pDisp: v11);
            CFaceEditDispPage::UpdateElevation(this, a2: v6 * 12, pDisp: v11);
            CFaceEditDispPage::UpdateScale(this, a2: v6 * 12, pDisp: v11);
            v4 = pSheet;
          }
        }
        ++v6;
      }
    }
  }
  if ( CMapDoc::m_pMapDoc != nullptr )
    CMapDoc::m_pMapDoc->SetModifiedFlag(this: CMapDoc::m_pMapDoc, a2: 1);
  CFaceEditDispPage::UpdateDialogData(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CB400
// Name: protected: virtual struct AFX_MSGMAP const __near * CFaceEditDispPage::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CFaceEditDispPage::GetMessageMap(CFaceEditDispPage *this)
{
  return (const AFX_MSGMAP *)&off_105EB0A8;
}
