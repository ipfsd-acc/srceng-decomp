// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/materialdlg.cpp
// Functions: 16
// ============================================================

#include "hammer\materialdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100D4550
// Name: protected: void CFaceSmoothingDlg::InitButtonIDs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceSmoothingDlg::InitButtonIDs(CFaceSmoothingDlg *this)
{
  this->m_ButtonIDs[0] = 0;
  this->m_ButtonIDs[1] = 1583;
  this->m_ButtonIDs[2] = 1602;
  this->m_ButtonIDs[3] = 1603;
  this->m_ButtonIDs[4] = 1604;
  this->m_ButtonIDs[5] = 1605;
  this->m_ButtonIDs[6] = 1606;
  this->m_ButtonIDs[7] = 1607;
  this->m_ButtonIDs[8] = 1608;
  this->m_ButtonIDs[9] = 1609;
  this->m_ButtonIDs[10] = 1610;
  this->m_ButtonIDs[11] = 1611;
  this->m_ButtonIDs[12] = 1612;
  this->m_ButtonIDs[13] = 1613;
  this->m_ButtonIDs[14] = 1614;
  this->m_ButtonIDs[15] = 1615;
  this->m_ButtonIDs[16] = 1616;
  this->m_ButtonIDs[17] = 1617;
  this->m_ButtonIDs[18] = 1618;
  this->m_ButtonIDs[19] = 1619;
  this->m_ButtonIDs[20] = 1620;
  this->m_ButtonIDs[21] = 1621;
  this->m_ButtonIDs[22] = 1622;
  this->m_ButtonIDs[23] = 1623;
  this->m_ButtonIDs[24] = 1624;
  this->m_ButtonIDs[25] = 1625;
  this->m_ButtonIDs[26] = 1626;
  this->m_ButtonIDs[27] = 1627;
  this->m_ButtonIDs[28] = 1628;
  this->m_ButtonIDs[29] = 1629;
  this->m_ButtonIDs[30] = 1630;
  this->m_ButtonIDs[31] = 1631;
  this->m_ButtonIDs[32] = 1632;
}

//------------------------------------------------------------------------------
// Address: 0x100D46A0
// Name: public: virtual CFaceSmoothingVisualDlg::~CFaceSmoothingVisualDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceSmoothingVisualDlg::~CFaceSmoothingVisualDlg(CFaceSmoothingVisualDlg *this)
{
  this->__vftable = (CFaceSmoothingVisualDlg_vtbl *)&CFaceSmoothingVisualDlg::`vftable';
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D46E0
// Name: public: virtual int CFaceSmoothingVisualDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFaceSmoothingVisualDlg::OnInitDialog(CRunMap *this)
{
  CDialog::OnInitDialog(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D46F0
// Name: protected: void CFaceSmoothingVisualDlg::InitButtonIDs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceSmoothingVisualDlg::InitButtonIDs(CFaceSmoothingVisualDlg *this)
{
  this->m_ButtonIDs[0] = 0;
  this->m_ButtonIDs[1] = 1010;
  this->m_ButtonIDs[2] = 1012;
  this->m_ButtonIDs[3] = 1013;
  this->m_ButtonIDs[4] = 1014;
  this->m_ButtonIDs[5] = 1015;
  this->m_ButtonIDs[6] = 1016;
  this->m_ButtonIDs[7] = 1017;
  this->m_ButtonIDs[8] = 1018;
  this->m_ButtonIDs[9] = 1019;
  this->m_ButtonIDs[10] = 1020;
  this->m_ButtonIDs[11] = 1021;
  this->m_ButtonIDs[12] = 1022;
  this->m_ButtonIDs[13] = 1023;
  this->m_ButtonIDs[14] = 1024;
  this->m_ButtonIDs[15] = 1025;
  this->m_ButtonIDs[16] = 1026;
  this->m_ButtonIDs[17] = 1027;
  this->m_ButtonIDs[18] = 1028;
  this->m_ButtonIDs[19] = 1029;
  this->m_ButtonIDs[20] = 1030;
  this->m_ButtonIDs[21] = 1031;
  this->m_ButtonIDs[22] = 1032;
  this->m_ButtonIDs[23] = 1033;
  this->m_ButtonIDs[24] = 1034;
  this->m_ButtonIDs[25] = 1035;
  this->m_ButtonIDs[26] = 1036;
  this->m_ButtonIDs[27] = 1037;
  this->m_ButtonIDs[28] = 1038;
  this->m_ButtonIDs[29] = 1039;
  this->m_ButtonIDs[30] = 1040;
  this->m_ButtonIDs[31] = 1041;
  this->m_ButtonIDs[32] = 1042;
}

//------------------------------------------------------------------------------
// Address: 0x100D4840
// Name: protected: void CFaceSmoothingDlg::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceSmoothingDlg::OnClose(CFaceSmoothingDlg *this)
{
  HWND Parent; // eax
  CWnd *v2; // eax

  Parent = GetParent(hWnd: this->m_hWnd);
  v2 = CWnd::FromHandle(hWnd: Parent);
  if ( v2 != nullptr )
    CFaceEditMaterialPage::SetMaterialPageTool(this: (CFaceEditMaterialPage *)&v2[1].m_nFlags, iMaterialTool: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x100D4870
// Name: protected: void CFaceSmoothingDlg::OnDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceSmoothingDlg::OnDestroy(CFaceSmoothingDlg *this)
{
  GetWindowRect(hWnd: this->m_hWnd, lpRect: &this->m_DialogPosRect);
}

//------------------------------------------------------------------------------
// Address: 0x100D4890
// Name: protected: void CFaceSmoothingDlg::CheckGroupButtons(int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceSmoothingDlg::CheckGroupButtons(CFaceSmoothingDlg *this, int *pGroupCounts, int nFaceCount)
{
  CFaceSmoothingDlg *v3; // edi
  CWnd *DlgItem; // eax
  CWnd *v5; // esi
  int v6; // eax
  HDC DC; // eax
  CDC *v8; // ebx
  COLORREF TextColor; // eax
  CGdiObject *p_m_Brush; // edi
  HBRUSH SolidBrush; // eax
  HWND m_hWnd; // ecx
  HBRUSH m_hObject; // eax
  CRect buttonRect; // [esp+Ch] [ebp-1Ch] BYREF
  CFaceSmoothingDlg *v15; // [esp+1Ch] [ebp-Ch]
  int *v16; // [esp+20h] [ebp-8h]
  int iButton; // [esp+24h] [ebp-4h]

  v3 = this;
  v15 = this;
  this->m_bColorOverride = true;
  iButton = 1;
  v16 = (int *)&this->m_ButtonIDs[1];
  do
  {
    DlgItem = CWnd::GetDlgItem(this: v3, nID: *v16);
    v5 = DlgItem;
    if ( DlgItem != nullptr )
    {
      SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
      v6 = pGroupCounts[iButton];
      if ( v6 != 0 )
      {
        if ( v6 == nFaceCount )
        {
          SendMessageA(hWnd: v5->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
        }
        else
        {
          DC = GetDC(hWnd: v5->m_hWnd);
          v8 = CDC::FromHandle(hDC: DC);
          TextColor = GetTextColor(hdc: v8->m_hAttribDC);
          p_m_Brush = &v3->m_Brush;
          SolidBrush = CreateSolidBrush(color: TextColor);
          CGdiObject::Attach(this: p_m_Brush, hObject: SolidBrush);
          m_hWnd = v5->m_hWnd;
          memset(&buttonRect, 0, sizeof(buttonRect));
          GetClientRect(hWnd: m_hWnd, lpRect: &buttonRect);
          if ( p_m_Brush != nullptr )
            m_hObject = (HBRUSH)p_m_Brush->m_hObject;
          else
            m_hObject = nullptr;
          FillRect(hDC: v8->m_hDC, lprc: &buttonRect, hbr: m_hObject);
          CGdiObject::DeleteObject(this: p_m_Brush);
          ReleaseDC(hWnd: v5->m_hWnd, hDC: v8->m_hDC);
          v3 = v15;
        }
      }
    }
    ++v16;
    ++iButton;
  }
  while ( iButton <= 32 );
  v3->m_bColorOverride = false;
}

//------------------------------------------------------------------------------
// Address: 0x100D49B0
// Name: public: CFaceSmoothingVisualDlg::CFaceSmoothingVisualDlg(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CFaceSmoothingVisualDlg *__thiscall CFaceSmoothingVisualDlg::CFaceSmoothingVisualDlg(
        CFaceSmoothingVisualDlg *this,
        CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x13Eu, pParentWnd: pParent);
  this->__vftable = (CFaceSmoothingVisualDlg_vtbl *)&CFaceSmoothingVisualDlg::`vftable';
  CFaceSmoothingVisualDlg::InitButtonIDs(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D4A70
// Name: protected: int CFaceSmoothingVisualDlg::OnButtonGroup(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFaceSmoothingVisualDlg::OnButtonGroup(CFaceSmoothingVisualDlg *this, unsigned int uCmd)
{
  int v2; // eax
  unsigned int *i; // ecx

  v2 = 1;
  for ( i = &this->m_ButtonIDs[1]; *i != uCmd; ++i )
  {
    if ( ++v2 > 32 )
      return 0;
  }
  if ( v2 == -1 )
    return 0;
  if ( CMapDoc::m_pMapDoc != nullptr )
    CMapDoc::m_pMapDoc->m_SmoothingGroupVisual = v2;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D4AC0
// Name: public: void CFaceSmoothingDlg::UpdateControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceSmoothingDlg::UpdateControls(CFaceSmoothingDlg *this)
{
  CFaceSmoothingDlg *v1; // esi
  HWND Parent; // eax
  CFaceEditSheet *v3; // eax
  CFaceEditSheet *v4; // ecx
  int m_Size; // edx
  int v6; // ebx
  CMapFace *pMapFace; // edi
  int j; // esi
  HWND__ *m_hWnd; // [esp-4h] [ebp-9Ch]
  int nGroupCounts[33]; // [esp+4h] [ebp-94h] BYREF
  CFaceEditSheet *pSheet; // [esp+88h] [ebp-10h]
  CFaceSmoothingDlg *v12; // [esp+8Ch] [ebp-Ch]
  int nFaceCount; // [esp+90h] [ebp-8h]
  int i; // [esp+94h] [ebp-4h]

  v1 = this;
  m_hWnd = this->m_hWnd;
  v12 = this;
  Parent = GetParent(hWnd: m_hWnd);
  v3 = (CFaceEditSheet *)CWnd::FromHandle(hWnd: Parent);
  v4 = v3;
  pSheet = v3;
  if ( v3 != nullptr )
  {
    m_Size = v3->m_Faces.m_Size;
    nFaceCount = m_Size;
    if ( m_Size != 0 )
    {
      memset(nGroupCounts, 0, sizeof(nGroupCounts));
      if ( m_Size > 0 )
      {
        v6 = 0;
        for ( i = m_Size; i != 0; --i )
        {
          pMapFace = v4->m_Faces.m_Memory.m_pMemory[v6].pMapFace;
          if ( pMapFace != nullptr )
          {
            for ( j = 1; j <= 32; ++j )
            {
              if ( CMapFace::InSmoothingGroup(this: pMapFace, iGroup: j) )
                ++nGroupCounts[j];
            }
            v4 = pSheet;
            m_Size = nFaceCount;
          }
          ++v6;
        }
        v1 = v12;
      }
      CFaceSmoothingDlg::CheckGroupButtons(this: v1, pGroupCounts: nGroupCounts, nFaceCount: m_Size);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D4BE0
// Name: public: virtual int CFaceSmoothingDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFaceSmoothingDlg::OnInitDialog(CFaceSmoothingDlg *this)
{
  CDialog::OnInitDialog(this);
  if ( bInit_3 )
    CWnd::SetWindowPos(
      this,
      pWndInsertAfter: &CWnd::wndTop,
      x: this->m_DialogPosRect.left,
      y: this->m_DialogPosRect.top,
      cx: this->m_DialogPosRect.right - this->m_DialogPosRect.left,
      cy: this->m_DialogPosRect.bottom - this->m_DialogPosRect.top,
      nFlags: 4u);
  CFaceSmoothingDlg::UpdateControls(this);
  bInit_3 = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D4C40
// Name: protected: int CFaceSmoothingDlg::OnButtonGroup(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFaceSmoothingDlg::OnButtonGroup(CFaceSmoothingDlg *this, int uCmd)
{
  CFaceSmoothingDlg *v2; // esi
  int v3; // edi
  unsigned int *i; // eax
  CWnd *DlgItem; // eax
  HWND Parent; // eax
  CWnd *v8; // eax
  CWnd *v9; // ebx
  int v10; // esi
  CMapFace *v11; // ecx
  int y; // [esp+Ch] [ebp-4h]
  bool bAdd_3; // [esp+1Bh] [ebp+Bh]

  v2 = this;
  v3 = 1;
  for ( i = &this->m_ButtonIDs[1]; *i != uCmd; ++i )
  {
    if ( ++v3 > 32 )
      return 0;
  }
  if ( v3 == -1 )
    return 0;
  DlgItem = CWnd::GetDlgItem(this, nID: uCmd);
  if ( DlgItem == nullptr )
    return 0;
  bAdd_3 = SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) != 0;
  Parent = GetParent(hWnd: v2->m_hWnd);
  v8 = CWnd::FromHandle(hWnd: Parent);
  v9 = v8;
  if ( v8 != nullptr && v8[49].m_ptGestureFrom.y > 0 )
  {
    v10 = 0;
    y = v8[49].m_ptGestureFrom.y;
    do
    {
      v11 = *(CMapFace **)((char *)&v9[49].m_xAccessibleServer.Release + v10);
      if ( v11 != nullptr )
      {
        if ( bAdd_3 )
          CMapFace::AddSmoothingGroup(this: v11, iGroup: v3);
        else
          CMapFace::RemoveSmoothingGroup(this: v11, iGroup: v3);
      }
      v10 += 12;
      --y;
    }
    while ( y != 0 );
    v2 = this;
  }
  CFaceSmoothingDlg::UpdateControls(this: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D4D20
// Name: protected: virtual struct AFX_MSGMAP const __near * CFaceSmoothingVisualDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CFaceSmoothingVisualDlg::GetMessageMap(CFaceSmoothingVisualDlg *this)
{
  return (const AFX_MSGMAP *)&off_105ED074;
}

//------------------------------------------------------------------------------
// Address: 0x100D4D30
// Name: protected: virtual struct AFX_MSGMAP const __near * CFaceSmoothingDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CFaceSmoothingDlg::GetMessageMap(CFaceSmoothingDlg *this)
{
  return (const AFX_MSGMAP *)&off_105ED398;
}

//------------------------------------------------------------------------------
// Address: 0x100D4D40
// Name: public: CFaceSmoothingDlg::CFaceSmoothingDlg(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CFaceSmoothingDlg *__thiscall CFaceSmoothingDlg::CFaceSmoothingDlg(CFaceSmoothingDlg *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x13Eu, pParentWnd: pParent);
  this->__vftable = (CFaceSmoothingDlg_vtbl *)&CFaceSmoothingDlg::`vftable';
  this->m_DialogPosRect.left = 0;
  this->m_DialogPosRect.top = 0;
  this->m_DialogPosRect.right = 0;
  this->m_DialogPosRect.bottom = 0;
  this->m_Brush.__vftable = (CBrush_vtbl *)&CGdiObject::`vftable';
  this->m_Brush.m_hObject = nullptr;
  this->m_Brush.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  CFaceSmoothingDlg::InitButtonIDs(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D4DE0
// Name: public: virtual CFaceSmoothingDlg::~CFaceSmoothingDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceSmoothingDlg::~CFaceSmoothingDlg(CFaceSmoothingDlg *this)
{
  this->__vftable = (CFaceSmoothingDlg_vtbl *)&CFaceSmoothingDlg::`vftable';
  this->m_Brush.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_Brush);
  CDialog::~CDialog(this);
}
