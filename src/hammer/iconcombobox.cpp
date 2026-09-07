// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/iconcombobox.cpp
// Functions: 90
// ============================================================

#include "hammer\iconcombobox.h"

//------------------------------------------------------------------------------
// Address: 0x10047200
// Name: public: virtual CIconComboBox::~CIconComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconComboBox::~CIconComboBox(CIconComboBox *this)
{
  this->__vftable = (CIconComboBox_vtbl *)&CIconComboBox::`vftable';
  CComboBox::~CComboBox(this);
}

//------------------------------------------------------------------------------
// Address: 0x10047240
// Name: public: void CIconComboBox::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconComboBox::Init(CIconComboBox *this)
{
  this->m_IconSize.cx = GetSystemMetrics(nIndex: 11);
  this->m_IconSize.cy = GetSystemMetrics(nIndex: 12);
}

//------------------------------------------------------------------------------
// Address: 0x10047260
// Name: public: virtual void CIconComboBox::MeasureItem(struct tagMEASUREITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconComboBox::MeasureItem(CIconComboBox *this, tagMEASUREITEMSTRUCT *lpMeasureItemStruct)
{
  lpMeasureItemStruct->itemWidth = this->m_IconSize.cx;
  lpMeasureItemStruct->itemHeight = this->m_IconSize.cy + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10047280
// Name: public: int CDC::Rectangle(struct tagRECT const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDC::Rectangle(CDC *this, const tagRECT *lpRect)
{
  return Rectangle(hdc: this->m_hDC, left: lpRect->left, top: lpRect->top, right: lpRect->right, bottom: lpRect->bottom);
}

//------------------------------------------------------------------------------
// Address: 0x100472B0
// Name: public: CIconComboBox::CIconComboBox(void)
// Source: json
//------------------------------------------------------------------------------
CIconComboBox *__thiscall CIconComboBox::CIconComboBox(CIconComboBox *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CIconComboBox_vtbl *)&CComboBox::`vftable';
  this->__vftable = (CIconComboBox_vtbl *)&CIconComboBox::`vftable';
  this->m_IconSize.cx = 0;
  this->m_IconSize.cy = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10047370
// Name: public: int CIconComboBox::AddIcon(char const __near *)
// Source: json
//------------------------------------------------------------------------------
WPARAM __thiscall CIconComboBox::AddIcon(CIconComboBox *this, const char *pIconName)
{
  AFX_MODULE_STATE *ModuleState; // eax
  HICON IconA; // ebx
  WPARAM result; // eax
  WPARAM v6; // esi

  ModuleState = AfxGetModuleState();
  IconA = ExtractIconA(hInst: ModuleState->m_hCurrentInstanceHandle, pszExeFileName: pIconName, nIconIndex: 0);
  if ( (unsigned int)IconA < 2 )
    return -1;
  result = SendMessageA(hWnd: this->m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)pIconName);
  v6 = result;
  if ( result != -1 && result != -2 )
  {
    if ( SendMessageA(hWnd: this->m_hWnd, Msg: 0x151u, wParam: result, lParam: (LPARAM)IconA) != -1 )
      return v6;
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100473E0
// Name: public: int CIconComboBox::DeleteIcon(int)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CIconComboBox::DeleteIcon(CIconComboBox *this, WPARAM ndx)
{
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x144u, wParam: ndx, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10047400
// Name: public: void CIconComboBox::OnDrawIcon(struct tagDRAWITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconComboBox::OnDrawIcon(CIconComboBox *this, tagDRAWITEMSTRUCT *lpDrawItemStruct)
{
  HICON itemData; // eax
  CDC *pDC; // [esp+4h] [ebp-8h]

  if ( SendMessageA(hWnd: this->m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0) != 0 )
  {
    pDC = CDC::FromHandle(hDC: lpDrawItemStruct->hDC);
    itemData = (HICON)lpDrawItemStruct->itemData;
    if ( itemData != nullptr )
      DrawIcon(
        hDC: pDC->m_hDC,
        X: lpDrawItemStruct->rcItem.left
      + (lpDrawItemStruct->rcItem.right - lpDrawItemStruct->rcItem.left) / 2
      - this->m_IconSize.cx / 2,
        Y: lpDrawItemStruct->rcItem.top
      + (lpDrawItemStruct->rcItem.bottom - lpDrawItemStruct->rcItem.top) / 2
      - this->m_IconSize.cy / 2,
        hIcon: itemData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047490
// Name: public: virtual CPen::~CPen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPen::~CPen(CPen *this)
{
  this->__vftable = (CPen_vtbl *)&CPen::`vftable';
  CGdiObject::~CGdiObject(this);
}

//------------------------------------------------------------------------------
// Address: 0x100474D0
// Name: public: virtual CBrush::~CBrush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrush::~CBrush(CBrush *this)
{
  this->__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  CGdiObject::~CGdiObject(this);
}

//------------------------------------------------------------------------------
// Address: 0x10047510
// Name: public: void CIconComboBox::SetDisabledBrushAndPen(struct tagDRAWITEMSTRUCT __near *,class CBrush __near * __near *,class CPen __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconComboBox::SetDisabledBrushAndPen(
        CIconComboBox *this,
        tagDRAWITEMSTRUCT *lpDrawItemStruct,
        CBrush **ppOldBrush,
        CPen **ppOldPen)
{
  CDC *v4; // esi
  CBrush brushDisabled; // [esp+4h] [ebp-1Ch] BYREF
  CPen penDisabled; // [esp+Ch] [ebp-14h] BYREF
  int v7; // [esp+1Ch] [ebp-4h]

  v4 = CDC::FromHandle(hDC: lpDrawItemStruct->hDC);
  CBrush::CBrush(this: &brushDisabled, crColor: 0xC0C0C0u);
  v7 = 0;
  CPen::CPen(this: &penDisabled, nPenStyle: 0, nWidth: 1, crColor: 0xC0C0C0u);
  LOBYTE(v7) = 1;
  *ppOldBrush = (CBrush *)CDC::SelectObject(this: v4, pFont: (CFont *)&brushDisabled);
  *ppOldPen = (CPen *)CDC::SelectObject(this: v4, pFont: (CFont *)&penDisabled);
  penDisabled.__vftable = (CPen_vtbl *)&CPen::`vftable';
  LOBYTE(v7) = 0;
  CGdiObject::~CGdiObject(this: &penDisabled);
  brushDisabled.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  v7 = -1;
  CGdiObject::~CGdiObject(this: &brushDisabled);
}

//------------------------------------------------------------------------------
// Address: 0x100475D0
// Name: public: void CIconComboBox::SetUnSelectedBrushAndPen(struct tagDRAWITEMSTRUCT __near *,class CBrush __near * __near *,class CPen __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconComboBox::SetUnSelectedBrushAndPen(
        CIconComboBox *this,
        tagDRAWITEMSTRUCT *lpDrawItemStruct,
        CBrush **ppOldBrush,
        CPen **ppOldPen)
{
  CDC *v4; // esi
  DWORD SysColor; // eax
  DWORD v6; // eax
  CDC_vtbl *v7; // edi
  DWORD v8; // eax
  CDC_vtbl *v9; // edi
  DWORD v10; // eax
  CBrush brushUnSelected; // [esp+Ch] [ebp-1Ch] BYREF
  CPen penUnSelected; // [esp+14h] [ebp-14h] BYREF
  int v13; // [esp+24h] [ebp-4h]

  v4 = CDC::FromHandle(hDC: lpDrawItemStruct->hDC);
  SysColor = GetSysColor(nIndex: 5);
  CBrush::CBrush(this: &brushUnSelected, crColor: SysColor);
  v13 = 0;
  v6 = GetSysColor(nIndex: 5);
  CPen::CPen(this: &penUnSelected, nPenStyle: 0, nWidth: 1, crColor: v6);
  LOBYTE(v13) = 1;
  *ppOldBrush = (CBrush *)CDC::SelectObject(this: v4, pFont: (CFont *)&brushUnSelected);
  *ppOldPen = (CPen *)CDC::SelectObject(this: v4, pFont: (CFont *)&penUnSelected);
  Rectangle(
    hdc: v4->m_hDC,
    left: lpDrawItemStruct->rcItem.left,
    top: lpDrawItemStruct->rcItem.top,
    right: lpDrawItemStruct->rcItem.right,
    bottom: lpDrawItemStruct->rcItem.bottom);
  v7 = v4->__vftable;
  v8 = GetSysColor(nIndex: 5);
  v7->SetBkColor(this: v4, a2: v8);
  v9 = v4->__vftable;
  v10 = GetSysColor(nIndex: 8);
  v9->SetTextColor(this: v4, a2: v10);
  penUnSelected.__vftable = (CPen_vtbl *)&CPen::`vftable';
  LOBYTE(v13) = 0;
  CGdiObject::~CGdiObject(this: &penUnSelected);
  brushUnSelected.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  v13 = -1;
  CGdiObject::~CGdiObject(this: &brushUnSelected);
}

//------------------------------------------------------------------------------
// Address: 0x100476D0
// Name: public: void CIconComboBox::SetSelectedBrushAndPen(struct tagDRAWITEMSTRUCT __near *,class CBrush __near * __near *,class CPen __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconComboBox::SetSelectedBrushAndPen(
        CIconComboBox *this,
        tagDRAWITEMSTRUCT *lpDrawItemStruct,
        CBrush **ppOldBrush,
        CPen **ppOldPen)
{
  CDC *v4; // esi
  DWORD SysColor; // eax
  DWORD v6; // eax
  CDC_vtbl *v7; // edi
  DWORD v8; // eax
  CDC_vtbl *v9; // edi
  DWORD v10; // eax
  CBrush brushSelected; // [esp+Ch] [ebp-1Ch] BYREF
  CPen penSelected; // [esp+14h] [ebp-14h] BYREF
  int v13; // [esp+24h] [ebp-4h]

  v4 = CDC::FromHandle(hDC: lpDrawItemStruct->hDC);
  SysColor = GetSysColor(nIndex: 13);
  CBrush::CBrush(this: &brushSelected, crColor: SysColor);
  v13 = 0;
  v6 = GetSysColor(nIndex: 13);
  CPen::CPen(this: &penSelected, nPenStyle: 0, nWidth: 1, crColor: v6);
  LOBYTE(v13) = 1;
  *ppOldBrush = (CBrush *)CDC::SelectObject(this: v4, pFont: (CFont *)&brushSelected);
  *ppOldPen = (CPen *)CDC::SelectObject(this: v4, pFont: (CFont *)&penSelected);
  Rectangle(
    hdc: v4->m_hDC,
    left: lpDrawItemStruct->rcItem.left,
    top: lpDrawItemStruct->rcItem.top,
    right: lpDrawItemStruct->rcItem.right,
    bottom: lpDrawItemStruct->rcItem.bottom);
  v7 = v4->__vftable;
  v8 = GetSysColor(nIndex: 13);
  v7->SetBkColor(this: v4, a2: v8);
  v9 = v4->__vftable;
  v10 = GetSysColor(nIndex: 14);
  v9->SetTextColor(this: v4, a2: v10);
  penSelected.__vftable = (CPen_vtbl *)&CPen::`vftable';
  LOBYTE(v13) = 0;
  CGdiObject::~CGdiObject(this: &penSelected);
  brushSelected.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  v13 = -1;
  CGdiObject::~CGdiObject(this: &brushSelected);
}

//------------------------------------------------------------------------------
// Address: 0x10047890
// Name: public: virtual void CIconComboBox::DrawItem(struct tagDRAWITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconComboBox::DrawItem(CIconComboBox *this, tagDRAWITEMSTRUCT *lpDrawItemStruct)
{
  CDC *v3; // esi
  CDC *v4; // ebx
  CDC *v5; // edi
  CDC *v6; // eax
  CPen *pOldPen; // [esp+8h] [ebp-8h] BYREF
  CBrush *pOldBrush; // [esp+Ch] [ebp-4h] BYREF

  pOldBrush = nullptr;
  pOldPen = nullptr;
  if ( CWnd::IsWindowEnabled(this) != 0 )
  {
    if ( (lpDrawItemStruct->itemState & 1) == 0 )
      goto LABEL_7;
    if ( (lpDrawItemStruct->itemAction & 3) != 0 )
    {
      CIconComboBox::SetSelectedBrushAndPen(this, lpDrawItemStruct, ppOldBrush: &pOldBrush, ppOldPen: &pOldPen);
      CIconComboBox::OnDrawIcon(this, lpDrawItemStruct);
      v4 = CDC::FromHandle(hDC: lpDrawItemStruct->hDC);
      CDC::SelectObject(this: v4, pFont: (CFont *)pOldBrush);
      CDC::SelectObject(this: v4, pFont: (CFont *)pOldPen);
    }
    if ( (lpDrawItemStruct->itemState & 1) == 0 )
    {
LABEL_7:
      if ( (lpDrawItemStruct->itemAction & 3) != 0 )
      {
        CIconComboBox::SetUnSelectedBrushAndPen(this, lpDrawItemStruct, ppOldBrush: &pOldBrush, ppOldPen: &pOldPen);
        CIconComboBox::OnDrawIcon(this, lpDrawItemStruct);
        v5 = CDC::FromHandle(hDC: lpDrawItemStruct->hDC);
        CDC::SelectObject(this: v5, pFont: (CFont *)pOldBrush);
        CDC::SelectObject(this: v5, pFont: (CFont *)pOldPen);
      }
    }
    if ( (lpDrawItemStruct->itemAction & 4) != 0 )
    {
      v6 = CDC::FromHandle(hDC: lpDrawItemStruct->hDC);
      DrawFocusRect(hDC: v6->m_hDC, lprc: &lpDrawItemStruct->rcItem);
    }
  }
  else
  {
    CIconComboBox::SetDisabledBrushAndPen(this, lpDrawItemStruct, ppOldBrush: &pOldBrush, ppOldPen: &pOldPen);
    CIconComboBox::OnDrawIcon(this, lpDrawItemStruct);
    v3 = CDC::FromHandle(hDC: lpDrawItemStruct->hDC);
    CDC::SelectObject(this: v3, pFont: (CFont *)pOldBrush);
    CDC::SelectObject(this: v3, pFont: (CFont *)pOldPen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103439D2
// Name: public: virtual struct CRuntimeClass __near * CPen::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CPen::GetRuntimeClass(CPen *this)
{
  return &CPen::classCPen;
}

//------------------------------------------------------------------------------
// Address: 0x103439D8
// Name: public: virtual struct CRuntimeClass __near * CBrush::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CBrush::GetRuntimeClass(CBrush *this)
{
  return &CBrush::classCBrush;
}

//------------------------------------------------------------------------------
// Address: 0x103444A7
// Name: public: CPen::CPen(int,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
CPen *__thiscall CPen::CPen(CPen *this, int nPenStyle, int nWidth, COLORREF crColor)
{
  HPEN Pen; // eax

  this->m_hObject = nullptr;
  this->__vftable = (CPen_vtbl *)&CPen::`vftable';
  Pen = CreatePen(iStyle: nPenStyle, cWidth: nWidth, color: crColor);
  if ( CGdiObject::Attach(this, hObject: Pen) == 0 )
    AfxThrowResourceException();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103444F0
// Name: public: CPen::CPen(int,int,struct tagLOGBRUSH const __near *,int,unsigned long const __near *)
// Source: json
//------------------------------------------------------------------------------
CPen *__thiscall CPen::CPen(
        CPen *this,
        DWORD nPenStyle,
        DWORD nWidth,
        const tagLOGBRUSH *pLogBrush,
        DWORD nStyleCount,
        const unsigned int *lpStyle)
{
  HPEN Pen; // eax

  this->m_hObject = nullptr;
  this->__vftable = (CPen_vtbl *)&CPen::`vftable';
  Pen = ExtCreatePen(iPenStyle: nPenStyle, cWidth: nWidth, plbrush: pLogBrush, cStyle: nStyleCount, pstyle: lpStyle);
  if ( CGdiObject::Attach(this, hObject: Pen) == 0 )
    AfxThrowResourceException();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1034453F
// Name: public: CBrush::CBrush(unsigned long)
// Source: json
//------------------------------------------------------------------------------
CBrush *__thiscall CBrush::CBrush(CBrush *this, COLORREF crColor)
{
  HBRUSH SolidBrush; // eax

  this->m_hObject = nullptr;
  this->__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  SolidBrush = CreateSolidBrush(color: crColor);
  if ( CGdiObject::Attach(this, hObject: SolidBrush) == 0 )
    AfxThrowResourceException();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103BEA8F
// Name: public: int CMFCToolBarImages::AddIcon(struct HICON__ __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarImages::AddIcon(CMFCToolBarImages *this, HICON__ *hIcon, int bAlphaBlend)
{
  HDC CompatibleDC; // eax
  int cx; // esi
  int cy; // edi
  HBITMAP CompatibleBitmap; // eax
  int v8; // esi
  void *m_hObject; // eax
  CMFCToolBarImages *v11; // esi
  int m_bAutoCheckPremlt; // [esp-4h] [ebp-9Ch]
  CWindowDC v13; // [esp+10h] [ebp-88h] BYREF
  CDC v14; // [esp+24h] [ebp-74h] BYREF
  CGdiObject *v15; // [esp+34h] [ebp-64h]
  void *ppvBits; // [esp+38h] [ebp-60h] BYREF
  HICON__ *hIcona; // [esp+3Ch] [ebp-5Ch]
  CGdiObject v18; // [esp+40h] [ebp-58h] BYREF
  CMFCToolBarImages *v19; // [esp+48h] [ebp-50h]
  BITMAPINFO pbmi; // [esp+4Ch] [ebp-4Ch] BYREF
  RECT rc; // [esp+78h] [ebp-20h] BYREF
  int v22; // [esp+94h] [ebp-4h]

  v19 = this;
  hIcona = hIcon;
  CWindowDC::CWindowDC(this: &v13, pWnd: nullptr);
  v22 = 0;
  if ( hIcon == nullptr )
    bAlphaBlend = 0;
  CDC::CDC(this: &v14);
  LOBYTE(v22) = 1;
  CompatibleDC = CreateCompatibleDC(hdc: nullptr);
  CDC::Attach(this: &v14, hDC: CompatibleDC);
  v18.m_hObject = nullptr;
  v18.__vftable = (CGdiObject_vtbl *)&CBitmap::`vftable';
  cx = this->m_sizeImage.cx;
  cy = this->m_sizeImage.cy;
  LOBYTE(v22) = 2;
  if ( CMFCToolBarImages::IsScaled(this: v19) != 0 )
  {
    cx = v19->m_sizeImageOriginal.cx;
    cy = v19->m_sizeImageOriginal.cy;
  }
  if ( bAlphaBlend != 0 )
  {
    pbmi.bmiHeader.biPlanes = 1;
    pbmi.bmiHeader.biBitCount = 32;
    pbmi.bmiHeader.biSizeImage = cx * cy;
    pbmi.bmiHeader.biSize = 40;
    pbmi.bmiHeader.biWidth = cx;
    pbmi.bmiHeader.biHeight = cy;
    pbmi.bmiHeader.biCompression = 0;
    memset(&pbmi.bmiHeader.biXPelsPerMeter, 0, 16);
    ppvBits = nullptr;
    CompatibleBitmap = CreateDIBSection(hdc: v14.m_hDC, &pbmi, usage: 0, &ppvBits, hSection: nullptr, offset: 0);
    if ( CompatibleBitmap == nullptr )
    {
      v8 = -1;
      goto LABEL_8;
    }
  }
  else
  {
    CompatibleBitmap = CreateCompatibleBitmap(hdc: v13.m_hDC, cx, cy);
  }
  CGdiObject::Attach(this: &v18, hObject: CompatibleBitmap);
  v15 = CDC::SelectGdiObject(hDC: v14.m_hDC, h: v18.m_hObject);
  if ( bAlphaBlend == 0 )
  {
    rc.left = 0;
    rc.top = 0;
    rc.right = cx;
    rc.bottom = cy;
    FillRect(hDC: v14.m_hDC, lprc: &rc, hbr: (HBRUSH)afxGlobalData.brBtnFace.m_hObject);
  }
  if ( hIcona != nullptr )
    CDC::DrawState(this: &v14, pt: 0, size: (CSize)__PAIR64__(cy, cx), hIcon: hIcona, nFlags: 0, pBrush: nullptr);
  if ( v15 != nullptr )
    m_hObject = v15->m_hObject;
  else
    m_hObject = nullptr;
  CDC::SelectGdiObject(hDC: v14.m_hDC, h: m_hObject);
  v11 = v19;
  if ( bAlphaBlend != 0 )
  {
    m_bAutoCheckPremlt = v19->m_bAutoCheckPremlt;
    v19->m_nBitsPerPixel = 32;
    CMFCToolBarImages::PreMultiplyAlpha(hbmp: (HBITMAP__ *)v18.m_hObject, bAutoCheckPremlt: m_bAutoCheckPremlt);
  }
  v8 = CMFCToolBarImages::AddImage(this: v11, hbmp: (HBITMAP__ *)v18.m_hObject, bSetBitPerPixel: 0);
LABEL_8:
  LOBYTE(v22) = 1;
  v18.__vftable = (CGdiObject_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: &v18);
  LOBYTE(v22) = 0;
  CDC::~CDC(this: &v14);
  v22 = -1;
  CWindowDC::~CWindowDC(this: &v13);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10415ED3
// Name: protected: virtual void CUserTool::DeleteIcon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUserTool::DeleteIcon(CUserTool *this)
{
  HICON__ *m_hIcon; // eax

  m_hIcon = this->m_hIcon;
  if ( m_hIcon != nullptr && m_hIcon != afxGlobalData.m_hiconTool )
    DestroyIcon(hIcon: this->m_hIcon);
  this->m_hIcon = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1041F941
// Name: public: virtual int CMFCToolTipCtrl::OnDrawIcon(class CDC __near *,class CRect)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCToolTipCtrl::OnDrawIcon(CMFCToolTipCtrl *this, CDC *pDC, CRect rectImage)
{
  CMFCRibbonButton *m_pRibbonButton; // eax
  int m_bIsDisabled; // ecx
  CMFCToolBarImages *v7; // ecx
  CMFCToolBarButton *m_pHotButton; // eax
  int m_bText; // ecx
  int v10; // eax
  CMFCToolBarImages *m_pToolBarImages; // [esp-18h] [ebp-44h]
  int m_nRibbonImageType; // [esp-14h] [ebp-40h]
  tagAFXDrawState v13; // [esp+Ch] [ebp-20h] BYREF
  unsigned int nSaveStyle; // [esp+18h] [ebp-14h]
  int bSaveLargeIcons; // [esp+1Ch] [ebp-10h]
  int bSaveImage; // [esp+20h] [ebp-Ch]
  int bSaveText; // [esp+24h] [ebp-8h]
  int bIsDisabled; // [esp+28h] [ebp-4h]

  m_pRibbonButton = this->m_pRibbonButton;
  bIsDisabled = (int)pDC;
  if ( m_pRibbonButton != nullptr )
  {
    m_bIsDisabled = m_pRibbonButton->m_bIsDisabled;
    m_pRibbonButton->m_bIsDisabled = 0;
    m_nRibbonImageType = this->m_nRibbonImageType;
    bIsDisabled = m_bIsDisabled;
    ((void (__thiscall *)(CMFCRibbonButton *, CDC *, int, int, int, int, int))this->m_pRibbonButton->DrawImage)(
      a1: this->m_pRibbonButton,
      a2: pDC,
      a3: m_nRibbonImageType,
      a4: rectImage.left,
      a5: rectImage.top,
      a6: rectImage.right,
      a7: rectImage.bottom);
    this->m_pRibbonButton->m_bIsDisabled = bIsDisabled;
    return 1;
  }
  else if ( this->m_pHotButton != nullptr && (v7 = this->m_pToolBarImages) != nullptr )
  {
    CMFCToolBarImages::PrepareDrawImage(this: v7, ds: &v13, sizeImageDest: 0, bFadeInactive: 0);
    m_pHotButton = this->m_pHotButton;
    nSaveStyle = m_pHotButton->m_nStyle;
    m_bText = m_pHotButton->m_bText;
    bSaveImage = m_pHotButton->m_bImage;
    v10 = CMFCToolBar::m_bLargeIcons;
    CMFCToolBar::m_bLargeIcons = 0;
    bSaveLargeIcons = v10;
    this->m_pHotButton->m_bText = 0;
    this->m_pHotButton->m_bImage = 1;
    this->m_pHotButton->m_nStyle = 0;
    m_pToolBarImages = this->m_pToolBarImages;
    bSaveText = m_bText;
    CMFCToolBarButton::OnDraw(
      this: this->m_pHotButton,
      pDC: (CDC *)bIsDisabled,
      rect: &rectImage,
      pImages: m_pToolBarImages,
      bHorz: 1,
      bCustomizeMode: 0,
      bHighlight: 0,
      bDrawBorder: 1,
      bGrayDisabledButtons: 1);
    this->m_pHotButton->m_nStyle = nSaveStyle;
    this->m_pHotButton->m_bText = bSaveText;
    this->m_pHotButton->m_bImage = bSaveImage;
    CMFCToolBar::m_bLargeIcons = bSaveLargeIcons;
    CMFCToolBarImages::EndDrawImage(this: this->m_pToolBarImages, ds: &v13);
    return 1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10344582
// Name: void AfxGetGrayBitmap(class CBitmap const __near &,class CBitmap __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall AfxGetGrayBitmap(const CBitmap *rSrc, CBrush *pDest, COLORREF crBackground)
{
  COLORREF SysColor; // eax
  COLORREF v4; // eax
  HDC CompatibleDC; // eax
  HDC v6; // eax
  HBITMAP Bitmap; // eax
  HBITMAP v8; // eax
  CBitmap *v9; // eax
  COLORREF Pixel; // eax
  void *m_hObject; // eax
  tagBITMAP bm; // [esp+10h] [ebp-64h] BYREF
  CDC dcMask; // [esp+28h] [ebp-4Ch] BYREF
  CDC dcMem; // [esp+38h] [ebp-3Ch] BYREF
  CBrush brHighLight; // [esp+48h] [ebp-2Ch] BYREF
  CBrush brShadow; // [esp+50h] [ebp-24h] BYREF
  CBitmap bmpMask; // [esp+58h] [ebp-1Ch] BYREF
  CBitmap *pOldMask; // [esp+60h] [ebp-14h]
  unsigned int cr; // [esp+64h] [ebp-10h]
  int v20; // [esp+70h] [ebp-4h]
  CBitmap *pOldMem; // [esp+7Ch] [ebp+8h]
  CFont *pbr; // [esp+80h] [ebp+Ch]

  dcMem.__vftable = (CDC_vtbl *)&CDC::`vftable';
  memset(&dcMem.m_hDC, 0, 12);
  v20 = 2;
  dcMask.__vftable = (CDC_vtbl *)&CDC::`vftable';
  memset(&dcMask.m_hDC, 0, 12);
  bmpMask.m_hObject = nullptr;
  bmpMask.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  SysColor = GetSysColor(nIndex: 20);
  CBrush::CBrush(this: &brHighLight, crColor: SysColor);
  LOBYTE(v20) = 3;
  v4 = GetSysColor(nIndex: 16);
  CBrush::CBrush(this: &brShadow, crColor: v4);
  LOBYTE(v20) = 4;
  CompatibleDC = CreateCompatibleDC(hdc: nullptr);
  if ( CDC::Attach(this: &dcMem, hDC: CompatibleDC) != 0 )
  {
    v6 = CreateCompatibleDC(hdc: nullptr);
    if ( CDC::Attach(this: &dcMask, hDC: v6) != 0 )
    {
      GetObjectA(h: rSrc->m_hObject, c: 24, pv: &bm);
      CGdiObject::DeleteObject(this: pDest);
      Bitmap = CreateBitmap(
                 nWidth: bm.bmWidth,
                 nHeight: bm.bmHeight,
                 nPlanes: bm.bmPlanes,
                 nBitCount: bm.bmBitsPixel,
                 lpBits: nullptr);
      if ( CGdiObject::Attach(this: pDest, hObject: Bitmap) != 0 )
      {
        v8 = CreateBitmap(nWidth: bm.bmWidth, nHeight: bm.bmHeight, nPlanes: 1u, nBitCount: 1u, lpBits: nullptr);
        if ( CGdiObject::Attach(this: &bmpMask, hObject: v8) != 0 )
        {
          pOldMem = (CBitmap *)CDC::SelectGdiObject(hDC: dcMem.m_hDC, h: rSrc->m_hObject);
          v9 = (CBitmap *)CDC::SelectGdiObject(hDC: dcMask.m_hDC, h: bmpMask.m_hObject);
          pOldMask = v9;
          if ( pOldMem != nullptr && v9 != nullptr )
          {
            Pixel = GetPixel(hdc: dcMem.m_hDC, x: 0, y: 0);
            cr = CDC::SetBkColor(this: &dcMem, crColor: Pixel);
            BitBlt(
              hdc: dcMask.m_hDC,
              x: 0,
              y: 0,
              cx: bm.bmWidth,
              cy: bm.bmHeight,
              hdcSrc: dcMem.m_hDC,
              x1: 0,
              y1: 0,
              rop: 0xCC0020u);
            CDC::SetBkColor(this: &dcMem, crColor: 0xFFFFFFu);
            BitBlt(
              hdc: dcMask.m_hDC,
              x: 0,
              y: 0,
              cx: bm.bmWidth,
              cy: bm.bmHeight,
              hdcSrc: dcMem.m_hDC,
              x1: 0,
              y1: 0,
              rop: 0x1100A6u);
            if ( pDest != nullptr )
              m_hObject = pDest->m_hObject;
            else
              m_hObject = nullptr;
            if ( CDC::SelectGdiObject(hDC: dcMem.m_hDC, h: m_hObject) != nullptr )
            {
              CDC::FillSolidRect(this: &dcMem, x: 0, y: 0, cx: bm.bmWidth, cy: bm.bmHeight, clr: crBackground);
              CDC::SetBkColor(this: &dcMem, crColor: 0xFFFFFFu);
              pbr = CDC::SelectObject(this: &dcMem, pFont: (CFont *)&brHighLight);
              BitBlt(
                hdc: dcMem.m_hDC,
                x: 1,
                y: 1,
                cx: bm.bmWidth,
                cy: bm.bmHeight,
                hdcSrc: dcMask.m_hDC,
                x1: 0,
                y1: 0,
                rop: 0xE20746u);
              CDC::SelectObject(this: &dcMem, pFont: (CFont *)&brShadow);
              BitBlt(
                hdc: dcMem.m_hDC,
                x: 0,
                y: 0,
                cx: bm.bmWidth,
                cy: bm.bmHeight,
                hdcSrc: dcMask.m_hDC,
                x1: 0,
                y1: 0,
                rop: 0xE20746u);
              CDC::SelectObject(this: &dcMem, pFont: pbr);
              CDC::SetBkColor(this: &dcMem, crColor: cr);
            }
            CDC::SelectGdiObject(hDC: dcMask.m_hDC, h: pOldMask->m_hObject);
            CDC::SelectGdiObject(hDC: dcMem.m_hDC, h: pOldMem->m_hObject);
          }
        }
      }
    }
  }
  LOBYTE(v20) = 3;
  brShadow.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  CGdiObject::~CGdiObject(this: &brShadow);
  LOBYTE(v20) = 2;
  brHighLight.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  CGdiObject::~CGdiObject(this: &brHighLight);
  LOBYTE(v20) = 1;
  bmpMask.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: &bmpMask);
  LOBYTE(v20) = 0;
  CDC::~CDC(this: &dcMask);
  v20 = -1;
  CDC::~CDC(this: &dcMem);
}

//------------------------------------------------------------------------------
// Address: 0x10344802
// Name: void AfxGetDitheredBitmap(class CBitmap const __near &,class CBitmap __near *,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall AfxGetDitheredBitmap(const CBitmap *rSrc, CBitmap *pDest, COLORREF cr1, COLORREF cr2)
{
  HDC CompatibleDC; // eax
  HDC v5; // eax
  HDC v6; // eax
  HBITMAP Bitmap; // eax
  HBITMAP v8; // eax
  HBRUSH PatternBrush; // eax
  HBITMAP v10; // eax
  CGdiObject *v11; // eax
  COLORREF Pixel; // eax
  COLORREF v13; // edi
  void *m_hObject; // eax
  COLORREF v15; // edi
  void *v16; // eax
  CGdiObject *v17; // [esp+10h] [ebp-84h]
  CGdiObject *v18; // [esp+14h] [ebp-80h]
  CDC v19; // [esp+18h] [ebp-7Ch] BYREF
  _BYTE pv[4]; // [esp+28h] [ebp-6Ch] BYREF
  int nWidth; // [esp+2Ch] [ebp-68h]
  int nHeight; // [esp+30h] [ebp-64h]
  unsigned __int16 v23; // [esp+38h] [ebp-5Ch]
  unsigned __int16 v24; // [esp+3Ah] [ebp-5Ah]
  CGdiObject v25; // [esp+40h] [ebp-54h] BYREF
  CDC v26; // [esp+48h] [ebp-4Ch] BYREF
  CDC v27; // [esp+58h] [ebp-3Ch] BYREF
  CGdiObject v28; // [esp+68h] [ebp-2Ch] BYREF
  CGdiObject *v29; // [esp+70h] [ebp-24h]
  RECT rc; // [esp+74h] [ebp-20h] BYREF
  int v31; // [esp+90h] [ebp-4h]
  COLORREF v32; // [esp+A8h] [ebp+14h]

  v29 = pDest;
  v26.__vftable = (CDC_vtbl *)&CDC::`vftable';
  memset(&v26.m_hDC, 0, 12);
  v31 = 4;
  v19.__vftable = (CDC_vtbl *)&CDC::`vftable';
  memset(&v19.m_hDC, 0, 12);
  v27.__vftable = (CDC_vtbl *)&CDC::`vftable';
  memset(&v27.m_hDC, 0, 12);
  v28.m_hObject = nullptr;
  v28.__vftable = (CGdiObject_vtbl *)&CBitmap::`vftable';
  v25.m_hObject = nullptr;
  v25.__vftable = (CGdiObject_vtbl *)&CBrush::`vftable';
  CompatibleDC = CreateCompatibleDC(hdc: nullptr);
  if ( CDC::Attach(this: &v26, hDC: CompatibleDC) != 0 )
  {
    v5 = CreateCompatibleDC(hdc: nullptr);
    if ( CDC::Attach(this: &v19, hDC: v5) != 0 )
    {
      v6 = CreateCompatibleDC(hdc: nullptr);
      if ( CDC::Attach(this: &v27, hDC: v6) != 0 && GetObjectA(h: rSrc->m_hObject, c: 24, pv) != 0 )
      {
        CGdiObject::DeleteObject(this: v29);
        Bitmap = CreateBitmap(nWidth, nHeight, nPlanes: v23, nBitCount: v24, lpBits: nullptr);
        if ( CGdiObject::Attach(this: v29, hObject: Bitmap) != 0 )
        {
          v8 = CreateBitmap(nWidth: 8, nHeight: 8, nPlanes: 1u, nBitCount: 1u, lpBits: wPat);
          CGdiObject::Attach(this: &v28, hObject: v8);
          PatternBrush = CreatePatternBrush(hbm: (HBITMAP)v28.m_hObject);
          CGdiObject::Attach(this: &v25, hObject: PatternBrush);
          CGdiObject::DeleteObject(this: &v28);
          v10 = CreateBitmap(nWidth, nHeight, nPlanes: 1u, nBitCount: 1u, lpBits: nullptr);
          CGdiObject::Attach(this: &v28, hObject: v10);
          v18 = CDC::SelectGdiObject(hDC: v26.m_hDC, h: rSrc->m_hObject);
          v11 = CDC::SelectGdiObject(hDC: v19.m_hDC, h: v28.m_hObject);
          v17 = v11;
          if ( v18 != nullptr && v11 != nullptr )
          {
            Pixel = GetPixel(hdc: v26.m_hDC, x: 0, y: 0);
            v13 = CDC::SetBkColor(this: &v26, crColor: Pixel);
            BitBlt(hdc: v19.m_hDC, x: 0, y: 0, cx: nWidth, cy: nHeight, hdcSrc: v26.m_hDC, x1: 0, y1: 0, rop: 0xCC0020u);
            CDC::SetBkColor(this: &v26, crColor: 0xFFFFFFu);
            BitBlt(hdc: v19.m_hDC, x: 0, y: 0, cx: nWidth, cy: nHeight, hdcSrc: v26.m_hDC, x1: 0, y1: 0, rop: 0xEE0086u);
            CDC::SetBkColor(this: &v26, crColor: v13);
            if ( v29 != nullptr )
              m_hObject = v29->m_hObject;
            else
              m_hObject = nullptr;
            v29 = CDC::SelectGdiObject(hDC: v27.m_hDC, h: m_hObject);
            if ( v29 != nullptr )
            {
              v15 = CDC::SetTextColor(this: &v27, crColor: cr1);
              v32 = CDC::SetBkColor(this: &v27, crColor: cr2);
              rc.right = nWidth;
              rc.bottom = nHeight;
              rc.left = 0;
              rc.top = 0;
              FillRect(hDC: v27.m_hDC, lprc: &rc, hbr: (HBRUSH)v25.m_hObject);
              CDC::SetTextColor(this: &v27, crColor: v15);
              CDC::SetBkColor(this: &v27, crColor: v32);
              BitBlt(
                hdc: v27.m_hDC,
                x: 0,
                y: 0,
                cx: nWidth,
                cy: nHeight,
                hdcSrc: v26.m_hDC,
                x1: 0,
                y1: 0,
                rop: 0x660046u);
              BitBlt(
                hdc: v27.m_hDC,
                x: 0,
                y: 0,
                cx: nWidth,
                cy: nHeight,
                hdcSrc: v19.m_hDC,
                x1: 0,
                y1: 0,
                rop: 0x8800C6u);
              BitBlt(
                hdc: v27.m_hDC,
                x: 0,
                y: 0,
                cx: nWidth,
                cy: nHeight,
                hdcSrc: v26.m_hDC,
                x1: 0,
                y1: 0,
                rop: 0x660046u);
              v16 = v29->m_hObject;
            }
            else
            {
              v16 = nullptr;
            }
            CDC::SelectGdiObject(hDC: v27.m_hDC, h: v16);
            CDC::SelectGdiObject(hDC: v19.m_hDC, h: v17->m_hObject);
            CDC::SelectGdiObject(hDC: v26.m_hDC, h: v18->m_hObject);
          }
        }
      }
    }
  }
  LOBYTE(v31) = 3;
  v25.__vftable = (CGdiObject_vtbl *)&CBrush::`vftable';
  CGdiObject::~CGdiObject(this: &v25);
  LOBYTE(v31) = 2;
  v28.__vftable = (CGdiObject_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: &v28);
  LOBYTE(v31) = 1;
  CDC::~CDC(this: &v27);
  LOBYTE(v31) = 0;
  CDC::~CDC(this: &v19);
  v31 = -1;
  CDC::~CDC(this: &v26);
}

//------------------------------------------------------------------------------
// Address: 0x10344AF8
// Name: public: static long COleException::Process(class CException const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall COleException::Process(const CException *pAnyException)
{
  if ( CObject::IsKindOf(this: &pAnyException->CObject, pClass: &COleException::classCOleException) != 0 )
    return (int)pAnyException[1].__vftable;
  if ( CObject::IsKindOf(this: &pAnyException->CObject, pClass: &CMemoryException::classCMemoryException) != 0 )
    return -2147024882;
  return CObject::IsKindOf(this: &pAnyException->CObject, pClass: &CNotSupportedException::classCNotSupportedException) != 0
       ? -2147467263
       : -2147418113;
}

//------------------------------------------------------------------------------
// Address: 0x10344B4C
// Name: void AfxUnmergeMenus(struct HMENU__ __near *,struct HMENU__ __near *,struct HMENU__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall AfxUnmergeMenus(HMENU__ *hMenuShared, HMENU__ *hMenuSource, HMENU__ *hHelpMenuPopup)
{
  int v3; // eax
  HMENU SubMenu; // ebx
  int cPopupItems; // [esp+4h] [ebp-10h]
  int cOurItems; // [esp+8h] [ebp-Ch]
  UINT i; // [esp+Ch] [ebp-8h]
  int j; // [esp+10h] [ebp-4h]
  int ja; // [esp+10h] [ebp-4h]

  cOurItems = GetMenuItemCount(hMenu: hMenuSource);
  v3 = GetMenuItemCount(hMenu: hMenuShared) - 1;
  i = v3;
  if ( v3 >= 0 )
  {
    while ( 1 )
    {
      SubMenu = GetSubMenu(hMenu: hMenuShared, nPos: v3);
      if ( SubMenu != nullptr )
      {
        if ( hHelpMenuPopup != nullptr )
        {
          j = 0;
          cPopupItems = GetMenuItemCount(hMenu: SubMenu);
          if ( cPopupItems > 0 )
          {
            while ( GetSubMenu(hMenu: SubMenu, nPos: j) != hHelpMenuPopup )
            {
              if ( ++j >= cPopupItems )
                goto LABEL_16;
            }
            RemoveMenu(hMenu: SubMenu, uPosition: j, uFlags: 0x400u);
            hHelpMenuPopup = nullptr;
          }
        }
        else
        {
          ja = 0;
          if ( cOurItems > 0 )
          {
            while ( GetSubMenu(hMenu: hMenuSource, nPos: ja) != SubMenu )
            {
              if ( ++ja >= cOurItems )
                goto LABEL_16;
            }
            RemoveMenu(hMenu: hMenuShared, uPosition: i, uFlags: 0x400u);
          }
        }
      }
LABEL_16:
      if ( (--i & 0x80000000) != 0 )
        break;
      v3 = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10344C0F
// Name: struct tagFORMATETC __near * _AfxFillFormatEtc(struct tagFORMATETC __near *,unsigned short,struct tagFORMATETC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
tagFORMATETC *__stdcall _AfxFillFormatEtc(
        tagFORMATETC *lpFormatEtc,
        unsigned __int16 cfFormat,
        tagFORMATETC *lpFormatEtcFill)
{
  if ( lpFormatEtcFill == nullptr )
    AfxThrowInvalidArgException();
  if ( lpFormatEtc == nullptr && cfFormat != 0 )
  {
    lpFormatEtcFill->ptd = nullptr;
    lpFormatEtcFill->lindex = -1;
    lpFormatEtcFill->tymed = -1;
    lpFormatEtc = lpFormatEtcFill;
    lpFormatEtcFill->cfFormat = cfFormat;
    lpFormatEtcFill->dwAspect = 1;
  }
  return lpFormatEtc;
}

//------------------------------------------------------------------------------
// Address: 0x10344C4F
// Name: public: virtual struct CRuntimeClass __near * COleException::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall COleException::GetRuntimeClass(COleException *this)
{
  return &COleException::classCOleException;
}

//------------------------------------------------------------------------------
// Address: 0x103BEC37
// Name: public: int CMFCToolBarImages::LoadStr(char const __near *,struct HINSTANCE__ __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarImages::LoadStr(
        CMFCToolBarImages *this,
        HBITMAP__ *lpszResourceName,
        HINSTANCE hinstRes,
        int bAdd)
{
  int v5; // ebx
  CFrameWnd *v7; // esi
  HBITMAP__ *ImageA; // eax
  UINT v9; // eax
  HDC CompatibleDC; // eax
  HDC v11; // eax
  COLORREF Pixel; // eax
  COLORREF v13; // eax
  int bmBitsPixel; // eax
  tagBITMAP bmp; // [esp+10h] [ebp-88h] BYREF
  _BYTE pv[4]; // [esp+28h] [ebp-70h] BYREF
  int v17; // [esp+2Ch] [ebp-6Ch]
  int cy; // [esp+30h] [ebp-68h]
  __int16 v19; // [esp+3Ah] [ebp-5Eh]
  CDC v20; // [esp+40h] [ebp-58h] BYREF
  CDC v21; // [esp+50h] [ebp-48h] BYREF
  CPngImage pngImage; // [esp+60h] [ebp-38h] BYREF
  HGDIOBJ v23; // [esp+68h] [ebp-30h]
  COLORREF v24; // [esp+6Ch] [ebp-2Ch]
  HGDIOBJ ho; // [esp+70h] [ebp-28h]
  HGDIOBJ h; // [esp+74h] [ebp-24h]
  int v27; // [esp+78h] [ebp-20h]
  int v28; // [esp+7Ch] [ebp-1Ch]
  unsigned int uiResID; // [esp+80h] [ebp-18h]
  int x; // [esp+84h] [ebp-14h]
  int y; // [esp+88h] [ebp-10h]
  int v32; // [esp+94h] [ebp-4h]
  HBITMAP__ *hbmp; // [esp+A0h] [ebp+8h]
  unsigned int bAdda; // [esp+A8h] [ebp+10h]

  v5 = 0;
  if ( this->m_bIsTemporary != 0 || lpszResourceName == nullptr )
    return 0;
  v7 = ((unsigned int)lpszResourceName & 0xFFFF0000) == 0 ? (CFrameWnd *)lpszResourceName : nullptr;
  uiResID = (unsigned int)v7;
  if ( bAdd != 0 )
  {
    if ( v7 != nullptr
      && CList<unsigned int,unsigned int>::Find(
           this: (CList<HWND__ *,HWND__ *> *)&this->m_lstOrigResIds,
           searchValue: ((unsigned int)lpszResourceName & 0xFFFF0000) == 0 ? (HWND__ *)lpszResourceName : nullptr,
           startAfter: nullptr) != nullptr )
    {
      return 1;
    }
  }
  else
  {
    AfxDeleteObject(pObject: (void **)&this->m_hbmImageWell);
    CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&this->m_lstOrigResIds);
    CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&this->m_lstOrigResInstances);
    CMap<unsigned int,unsigned int,CPane *,CPane *>::RemoveAll(this: (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&this->m_mapOrigResOffsets);
  }
  pngImage.m_hObject = nullptr;
  pngImage.__vftable = (CPngImage_vtbl *)&CPngImage::`vftable';
  v32 = 0;
  if ( CPngImage::Load(this: &pngImage, (const char *)lpszResourceName, hinstRes) != 0 )
  {
    ImageA = (HBITMAP__ *)CGdiObject::Detach(this: &pngImage);
  }
  else
  {
    if ( hinstRes == nullptr )
      hinstRes = AfxGetModuleState()->m_hCurrentResourceHandle;
    v9 = 0x2000;
    if ( this->m_bMapTo3DColors != 0 && afxGlobalData.m_bIsBlackHighContrast == 0 )
      v9 = 12288;
    ImageA = (HBITMAP__ *)LoadImageA(hInst: hinstRes, name: (LPCSTR)lpszResourceName, type: 0, cx: 0, cy: 0, fuLoad: v9);
  }
  hbmp = ImageA;
  if ( ImageA == nullptr )
  {
    v32 = -1;
    pngImage.__vftable = (CPngImage_vtbl *)&CBitmap::`vftable';
    CGdiObject::~CGdiObject(this: &pngImage);
    return 0;
  }
  if ( GetObjectA(h: ImageA, c: 24, pv: &bmp) != 0 )
  {
    if ( bmp.bmBitsPixel < 0x20u )
    {
      if ( bmp.bmBitsPixel > 8u && this->m_bMapTo3DColors != 0 || afxGlobalData.m_bIsBlackHighContrast != 0 )
      {
        CDC::CDC(this: &v21);
        LOBYTE(v32) = 1;
        CompatibleDC = CreateCompatibleDC(hdc: nullptr);
        CDC::Attach(this: &v21, hDC: CompatibleDC);
        if ( GetObjectA(h: hbmp, c: 24, pv) != 0 )
        {
          h = SelectObject(hdc: v21.m_hDC, h: hbmp);
          if ( h != nullptr )
          {
            v27 = v17;
            v28 = cy;
            ho = CreateCompatibleBitmap(hdc: v21.m_hDC, cx: v17, cy);
            if ( ho != nullptr )
            {
              CDC::CDC(this: &v20);
              LOBYTE(v32) = 2;
              v11 = CreateCompatibleDC(hdc: v21.m_hDC);
              CDC::Attach(this: &v20, hDC: v11);
              v23 = SelectObject(hdc: v20.m_hDC, h: ho);
              if ( v23 != nullptr )
              {
                BitBlt(hdc: v20.m_hDC, x: 0, y: 0, cx: v27, cy: v28, hdcSrc: v21.m_hDC, x1: 0, y1: 0, rop: 0xCC0020u);
                for ( x = 0; x < v27; ++x )
                {
                  for ( y = 0; y < v28; ++y )
                  {
                    Pixel = GetPixel(hdc: v20.m_hDC, x, y);
                    v24 = Pixel;
                    if ( v19 != 24 || CMFCToolBarImages::m_bDisableTrueColorAlpha != 0 )
                      v13 = CMFCToolBarImages::MapToSysColor(color: Pixel, bUseRGBQUAD: 0);
                    else
                      v13 = CMFCToolBarImages::MapToSysColorAlpha(color: Pixel);
                    if ( v24 != v13 )
                      SetPixel(hdc: v20.m_hDC, x, y, color: v13);
                  }
                }
                SelectObject(hdc: v20.m_hDC, h: v23);
                SelectObject(hdc: v21.m_hDC, h);
                DeleteObject(ho: hbmp);
                hbmp = (HBITMAP__ *)ho;
              }
              else
              {
                SelectObject(hdc: v21.m_hDC, h);
                DeleteObject(ho);
              }
              LOBYTE(v32) = 1;
              CDC::~CDC(this: &v20);
            }
            else
            {
              SelectObject(hdc: v21.m_hDC, h);
            }
          }
          LOBYTE(v32) = 0;
          CDC::~CDC(this: &v21);
          v7 = (CFrameWnd *)uiResID;
        }
        else
        {
          LOBYTE(v32) = 0;
          CDC::~CDC(this: &v21);
        }
      }
    }
    else
    {
      CMFCToolBarImages::PreMultiplyAlpha(hbmp, bAutoCheckPremlt: this->m_bAutoCheckPremlt);
    }
    bmBitsPixel = bmp.bmBitsPixel;
    if ( this->m_nBitsPerPixel > bmp.bmBitsPixel )
      bmBitsPixel = this->m_nBitsPerPixel;
    this->m_nBitsPerPixel = bmBitsPixel;
    if ( bAdd != 0 )
    {
      if ( v7 != nullptr )
      {
        bAdda = this->m_iCount;
        *CMap<unsigned int,unsigned int,unsigned long,unsigned long>::operator[](
           this: (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&this->m_mapOrigResOffsets,
           key: (unsigned int)v7) = bAdda;
      }
      CMFCToolBarImages::AddImage(this, hbmp, bSetBitPerPixel: 0);
      if ( v7 != nullptr )
      {
        CList<CFrameWnd *,CFrameWnd *>::AddTail(
          this: (CList<CFrameWnd *,CFrameWnd *> *)&this->m_lstOrigResIds,
          newElement: v7);
        CList<CFrameWnd *,CFrameWnd *>::AddTail(
          this: (CList<CFrameWnd *,CFrameWnd *> *)&this->m_lstOrigResInstances,
          newElement: (CFrameWnd *)hinstRes);
      }
      DeleteObject(ho: hbmp);
    }
    else
    {
      this->m_hbmImageWell = hbmp;
    }
    CMFCToolBarImages::UpdateCount(this);
    AfxDeleteObject(pObject: (void **)&this->m_hbmImageLight);
    this->m_hbmImageLight = nullptr;
    AfxDeleteObject(pObject: (void **)&this->m_hbmImageShadow);
    this->m_hbmImageShadow = nullptr;
    v5 = 1;
  }
  else
  {
    DeleteObject(ho: hbmp);
  }
  v32 = -1;
  pngImage.__vftable = (CPngImage_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: &pngImage);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x103BEFC3
// Name: public: int CMFCToolBarImages::Load(unsigned int,struct HINSTANCE__ __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarImages::Load(
        CMFCToolBarImages *this,
        unsigned __int16 uiResID,
        HINSTANCE__ *hinstRes,
        int bAdd)
{
  int v5; // ebx
  unsigned int v6; // esi
  HBITMAP__ *ImageA; // eax
  UINT v8; // eax
  HDC CompatibleDC; // eax
  HDC v10; // eax
  COLORREF Pixel; // eax
  COLORREF v12; // eax
  int m_nBitsPerPixel; // eax
  _BYTE pv[18]; // [esp+10h] [ebp-88h] BYREF
  unsigned __int16 v16; // [esp+22h] [ebp-76h]
  _BYTE v17[4]; // [esp+28h] [ebp-70h] BYREF
  int v18; // [esp+2Ch] [ebp-6Ch]
  int cy; // [esp+30h] [ebp-68h]
  __int16 v20; // [esp+3Ah] [ebp-5Eh]
  CDC v21; // [esp+40h] [ebp-58h] BYREF
  CDC v22; // [esp+50h] [ebp-48h] BYREF
  CPngImage v23; // [esp+60h] [ebp-38h] BYREF
  HGDIOBJ v24; // [esp+68h] [ebp-30h]
  COLORREF v25; // [esp+6Ch] [ebp-2Ch]
  HINSTANCE hInst; // [esp+70h] [ebp-28h]
  HGDIOBJ ho; // [esp+74h] [ebp-24h]
  HGDIOBJ h; // [esp+78h] [ebp-20h]
  int v29; // [esp+7Ch] [ebp-1Ch]
  int v30; // [esp+80h] [ebp-18h]
  unsigned int v31; // [esp+84h] [ebp-14h]
  int x; // [esp+88h] [ebp-10h]
  int v33; // [esp+94h] [ebp-4h]
  signed int uiResIDa; // [esp+A0h] [ebp+8h]
  unsigned int uiResIDb; // [esp+A0h] [ebp+8h]
  HBITMAP__ *hinstResa; // [esp+A4h] [ebp+Ch]

  v5 = 0;
  hInst = hinstRes;
  if ( this->m_bIsTemporary == 0 && uiResID != 0 )
  {
    v6 = uiResID;
    v31 = uiResID;
    if ( bAdd != 0 )
    {
      if ( CList<unsigned int,unsigned int>::Find(
             this: (CList<HWND__ *,HWND__ *> *)&this->m_lstOrigResIds,
             searchValue: (HWND__ *)uiResID,
             startAfter: nullptr) != nullptr )
        return 1;
    }
    else
    {
      AfxDeleteObject(pObject: (void **)&this->m_hbmImageWell);
      CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&this->m_lstOrigResIds);
      CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&this->m_lstOrigResInstances);
      CMap<unsigned int,unsigned int,CPane *,CPane *>::RemoveAll(this: (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&this->m_mapOrigResOffsets);
    }
    v23.m_hObject = nullptr;
    v23.__vftable = (CPngImage_vtbl *)&CPngImage::`vftable';
    v33 = 0;
    if ( CPngImage::Load(this: &v23, lpszResourceName: (const char *)uiResID, hinstRes) != 0 )
    {
      ImageA = (HBITMAP__ *)CGdiObject::Detach(this: &v23);
    }
    else
    {
      if ( hinstRes == nullptr )
        hInst = AfxGetModuleState()->m_hCurrentResourceHandle;
      v8 = 0x2000;
      if ( this->m_bMapTo3DColors != 0 && afxGlobalData.m_bIsBlackHighContrast == 0 )
        v8 = 12288;
      ImageA = (HBITMAP__ *)LoadImageA(hInst, name: (LPCSTR)uiResID, type: 0, cx: 0, cy: 0, fuLoad: v8);
    }
    hinstResa = ImageA;
    if ( ImageA == nullptr )
      goto LABEL_15;
    if ( GetObjectA(h: ImageA, c: 24, pv) == 0 )
    {
      DeleteObject(ho: hinstResa);
LABEL_15:
      v33 = -1;
      v23.__vftable = (CPngImage_vtbl *)&CBitmap::`vftable';
      CGdiObject::~CGdiObject(this: &v23);
      return v5;
    }
    if ( v16 < 0x20u )
    {
      if ( v16 > 8u && this->m_bMapTo3DColors != 0 || afxGlobalData.m_bIsBlackHighContrast != 0 )
      {
        CDC::CDC(this: &v22);
        LOBYTE(v33) = 1;
        CompatibleDC = CreateCompatibleDC(hdc: nullptr);
        CDC::Attach(this: &v22, hDC: CompatibleDC);
        if ( GetObjectA(h: hinstResa, c: 24, pv: v17) != 0 )
        {
          h = SelectObject(hdc: v22.m_hDC, h: hinstResa);
          if ( h != nullptr )
          {
            v29 = v18;
            v30 = cy;
            ho = CreateCompatibleBitmap(hdc: v22.m_hDC, cx: v18, cy);
            if ( ho != nullptr )
            {
              CDC::CDC(this: &v21);
              LOBYTE(v33) = 2;
              v10 = CreateCompatibleDC(hdc: v22.m_hDC);
              CDC::Attach(this: &v21, hDC: v10);
              v24 = SelectObject(hdc: v21.m_hDC, h: ho);
              if ( v24 != nullptr )
              {
                BitBlt(hdc: v21.m_hDC, x: 0, y: 0, cx: v29, cy: v30, hdcSrc: v22.m_hDC, x1: 0, y1: 0, rop: 0xCC0020u);
                for ( x = 0; x < v29; ++x )
                {
                  for ( uiResIDa = 0; uiResIDa < v30; ++uiResIDa )
                  {
                    Pixel = GetPixel(hdc: v21.m_hDC, x, y: uiResIDa);
                    v25 = Pixel;
                    if ( v20 != 24 || CMFCToolBarImages::m_bDisableTrueColorAlpha != 0 )
                      v12 = CMFCToolBarImages::MapToSysColor(color: Pixel, bUseRGBQUAD: 0);
                    else
                      v12 = CMFCToolBarImages::MapToSysColorAlpha(color: Pixel);
                    if ( v25 != v12 )
                      SetPixel(hdc: v21.m_hDC, x, y: uiResIDa, color: v12);
                  }
                }
                SelectObject(hdc: v21.m_hDC, h: v24);
                SelectObject(hdc: v22.m_hDC, h);
                DeleteObject(ho: hinstResa);
                hinstResa = (HBITMAP__ *)ho;
              }
              else
              {
                SelectObject(hdc: v22.m_hDC, h);
                DeleteObject(ho);
              }
              LOBYTE(v33) = 1;
              CDC::~CDC(this: &v21);
            }
            else
            {
              SelectObject(hdc: v22.m_hDC, h);
            }
          }
          LOBYTE(v33) = 0;
          CDC::~CDC(this: &v22);
          v6 = v31;
        }
        else
        {
          LOBYTE(v33) = 0;
          CDC::~CDC(this: &v22);
        }
      }
    }
    else
    {
      CMFCToolBarImages::PreMultiplyAlpha(hbmp: hinstResa, bAutoCheckPremlt: this->m_bAutoCheckPremlt);
    }
    m_nBitsPerPixel = v16;
    if ( this->m_nBitsPerPixel > v16 )
      m_nBitsPerPixel = this->m_nBitsPerPixel;
    this->m_nBitsPerPixel = m_nBitsPerPixel;
    if ( bAdd != 0 )
    {
      if ( v6 != 0 )
      {
        uiResIDb = this->m_iCount;
        *CMap<unsigned int,unsigned int,unsigned long,unsigned long>::operator[](
           this: (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&this->m_mapOrigResOffsets,
           key: v6) = uiResIDb;
      }
      CMFCToolBarImages::AddImage(this, hbmp: hinstResa, bSetBitPerPixel: 0);
      if ( v6 != 0 )
      {
        CList<CFrameWnd *,CFrameWnd *>::AddTail(
          this: (CList<CFrameWnd *,CFrameWnd *> *)&this->m_lstOrigResIds,
          newElement: (CFrameWnd *)v6);
        CList<CFrameWnd *,CFrameWnd *>::AddTail(
          this: (CList<CFrameWnd *,CFrameWnd *> *)&this->m_lstOrigResInstances,
          newElement: (CFrameWnd *)hInst);
      }
      DeleteObject(ho: hinstResa);
    }
    else
    {
      this->m_hbmImageWell = hinstResa;
    }
    CMFCToolBarImages::UpdateCount(this);
    AfxDeleteObject(pObject: (void **)&this->m_hbmImageLight);
    this->m_hbmImageLight = nullptr;
    AfxDeleteObject(pObject: (void **)&this->m_hbmImageShadow);
    v33 = -1;
    this->m_hbmImageShadow = nullptr;
    v23.__vftable = (CPngImage_vtbl *)&CBitmap::`vftable';
    CGdiObject::~CGdiObject(this: &v23);
    return 1;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x103BF356
// Name: public: virtual struct CRuntimeClass __near * CMFCOutlookBarPaneButton::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCOutlookBarPaneButton::GetRuntimeClass(CMFCOutlookBarPaneButton *this)
{
  return &CMFCOutlookBarPaneButton::classCMFCOutlookBarPaneButton;
}

//------------------------------------------------------------------------------
// Address: 0x103BF35C
// Name: public: CMFCOutlookBarPaneButton::CMFCOutlookBarPaneButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCOutlookBarPaneButton *__thiscall CMFCOutlookBarPaneButton::CMFCOutlookBarPaneButton(CMFCOutlookBarPaneButton *this)
{
  CMFCToolBarButton::CMFCToolBarButton(this);
  this->m_pWndParentBar = nullptr;
  this->m_sizeImage.cx = 0;
  this->__vftable = (CMFCOutlookBarPaneButton_vtbl *)&CMFCOutlookBarPaneButton::`vftable';
  this->m_sizeImage.cy = 0;
  this->m_bIsWholeText = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103BF384
// Name: protected: virtual int CMFCToolBar::OnKey(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::OnKey(CMFCBaseTabCtrl *this, int __formal)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103BF389
// Name: public: virtual class CRect const CMFCToolBarButton::GetInvalidateRect(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const CRect *__thiscall CMFCToolBarButton::GetInvalidateRect(CMFCToolBarButton *this, CRect *result)
{
  *result = this->m_rect;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BF3A2
// Name: public: virtual void CMFCToolBarButton::SetStyle(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarButton::SetStyle(CMFCToolBarButton *this, unsigned int nStyle)
{
  this->m_nStyle = nStyle;
}

//------------------------------------------------------------------------------
// Address: 0x10415EF4
// Name: public: void CUserTool::DrawToolIcon(class CDC __near *,class CRect const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CUserTool::DrawToolIcon(CUserTool *this, CDC *pDC, const CRect *rectImage)
{
  int left; // edi
  int top; // ebx
  int v6; // eax
  HDC__ *m_hDC; // ecx
  int x; // [esp+1Ch] [ebp+Ch]

  left = rectImage->left;
  if ( (rectImage->right - rectImage->left - afxGlobalData.m_sizeSmallIcon.cx) / 2 >= 0 )
    x = (rectImage->right - rectImage->left - afxGlobalData.m_sizeSmallIcon.cx) / 2;
  else
    x = 0;
  top = rectImage->top;
  v6 = (rectImage->bottom - top - afxGlobalData.m_sizeSmallIcon.cy) / 2;
  if ( v6 < 0 )
    v6 = 0;
  if ( pDC != nullptr )
    m_hDC = pDC->m_hDC;
  else
    m_hDC = nullptr;
  DrawIconEx(
    hdc: m_hDC,
    xLeft: x + left,
    yTop: v6 + top,
    hIcon: this->m_hIcon,
    cxWidth: 0,
    cyWidth: 0,
    istepIfAniCur: 0,
    hbrFlickerFreeDraw: nullptr,
    diFlags: 3u);
}

//------------------------------------------------------------------------------
// Address: 0x10415F6A
// Name: protected: virtual struct HICON__ __near * CUserTool::LoadDefaultIcon(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HICON__ *__thiscall CUserTool::LoadDefaultIcon(CUserTool *this)
{
  HICON__ *result; // eax
  AFX_MODULE_STATE *ModuleState; // eax

  result = afxGlobalData.m_hiconTool;
  if ( afxGlobalData.m_hiconTool == nullptr )
  {
    ModuleState = AfxGetModuleState();
    result = (HICON__ *)LoadImageW(
                          hInst: ModuleState->m_hCurrentResourceHandle,
                          name: (LPCWSTR)0x4223,
                          type: 1u,
                          cx: afxGlobalData.m_sizeSmallIcon.cx,
                          cy: afxGlobalData.m_sizeSmallIcon.cy,
                          fuLoad: 0x8000u);
    afxGlobalData.m_hiconTool = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415FA0
// Name: public: CUserTool::CUserTool(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUserTool *__thiscall CUserTool::CUserTool(CUserTool *this)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v3; // eax
  CAfxStringMgr *v4; // eax
  CAfxStringMgr *v5; // eax

  this->__vftable = (CUserTool_vtbl *)&CUserTool::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strLabel, pStringMgr: StringManager);
  v3 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strArguments, pStringMgr: v3);
  v4 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strInitialDirectory, pStringMgr: v4);
  v5 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strCommand, pStringMgr: v5);
  this->m_uiCmdId = 0;
  this->m_hIcon = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10415FEF
// Name: public: virtual CUserTool::~CUserTool(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CUserTool::~CUserTool(CUserTool *this)
{
  this->__vftable = (CUserTool_vtbl *)&CUserTool::`vftable';
  CUserTool::DeleteIcon(this);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strCommand.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strInitialDirectory.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strArguments.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strLabel.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1041602C
// Name: public: virtual int CUserTool::Invoke(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CUserTool::Invoke(CUserTool *this)
{
  char *m_pszData; // ebx
  char *v3; // esi
  char *v4; // edi
  HWND MainWnd; // eax

  m_pszData = this->m_strCommand.m_pszData;
  if ( *((_DWORD *)m_pszData - 3) == 0 )
    return false;
  v3 = this->m_strInitialDirectory.m_pszData;
  v4 = this->m_strArguments.m_pszData;
  MainWnd = (HWND)AfxGetMainWnd();
  if ( MainWnd != nullptr )
    MainWnd = *((HWND *)MainWnd + 8);
  return (unsigned int)ShellExecuteA(
                         hwnd: MainWnd,
                         lpOperation: nullptr,
                         lpFile: m_pszData,
                         lpParameters: v4,
                         lpDirectory: v3,
                         nShowCmd: 1) >= 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x10416068
// Name: public: static class CObject __near * CUserTool::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUserTool *__stdcall CUserTool::CreateObject()
{
  CUserTool *v0; // ecx
  CUserTool *result; // eax

  v0 = (CUserTool *)operator new(nSize: 0x1Cu);
  result = nullptr;
  if ( v0 != nullptr )
    return CUserTool::CUserTool(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104160B6
// Name: public: int CUserTool::CopyIconToClipboard(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CUserTool::CopyIconToClipboard(CUserTool *this)
{
  int cx; // esi
  int cy; // edi
  HDC CompatibleDC; // eax
  HBITMAP CompatibleBitmap; // eax
  CGdiObject *v6; // eax
  void *v7; // eax
  CWnd *MainWnd; // eax
  void *v9; // eax
  CWindowDC v10; // [esp+10h] [ebp-58h] BYREF
  CUserTool *v11; // [esp+24h] [ebp-44h]
  CGdiObject *v12; // [esp+28h] [ebp-40h]
  CDC pDC; // [esp+2Ch] [ebp-3Ch] BYREF
  CGdiObject v14; // [esp+3Ch] [ebp-2Ch] BYREF
  RECT rc; // [esp+44h] [ebp-24h] BYREF
  int v16; // [esp+64h] [ebp-4h]

  v11 = this;
  v16 = 0;
  CWindowDC::CWindowDC(this: &v10, pWnd: nullptr);
  cx = afxGlobalData.m_sizeSmallIcon.cx;
  cy = afxGlobalData.m_sizeSmallIcon.cy;
  LOBYTE(v16) = 1;
  CDC::CDC(this: &pDC);
  LOBYTE(v16) = 2;
  CompatibleDC = CreateCompatibleDC(hdc: nullptr);
  CDC::Attach(this: &pDC, hDC: CompatibleDC);
  v14.m_hObject = nullptr;
  v14.__vftable = (CGdiObject_vtbl *)&CBitmap::`vftable';
  LOBYTE(v16) = 3;
  CompatibleBitmap = CreateCompatibleBitmap(hdc: v10.m_hDC, cx, cy);
  if ( CGdiObject::Attach(this: &v14, hObject: CompatibleBitmap) != 0 )
  {
    v6 = CDC::SelectGdiObject(hDC: pDC.m_hDC, h: v14.m_hObject);
    rc.left = 0;
    rc.top = 0;
    v12 = v6;
    rc.right = cx;
    rc.bottom = cy;
    FillRect(hDC: pDC.m_hDC, lprc: &rc, hbr: (HBRUSH)afxGlobalData.brBtnFace.m_hObject);
    CUserTool::DrawToolIcon(this: v11, &pDC, rectImage: (const CRect *)&rc);
    v7 = v12 != nullptr ? v12->m_hObject : nullptr;
    CDC::SelectGdiObject(hDC: pDC.m_hDC, h: v7);
    MainWnd = AfxGetMainWnd();
    if ( OpenClipboard(hWndNewOwner: MainWnd->m_hWnd) )
    {
      if ( !EmptyClipboard() )
      {
        AfxMessageBox(nIDPrompt: 0x3E8Au, nType: 0, nIDHelp: 0xFFFFFFFF);
        CloseClipboard();
        goto LABEL_3;
      }
      v9 = CGdiObject::Detach(this: &v14);
      if ( SetClipboardData(uFormat: 2u, hMem: v9) == nullptr )
        AfxMessageBox(nIDPrompt: 0x3E8Au, nType: 0, nIDHelp: 0xFFFFFFFF);
      CloseClipboard();
      LOBYTE(v16) = 2;
      v14.__vftable = (CGdiObject_vtbl *)&CBitmap::`vftable';
      CGdiObject::~CGdiObject(this: &v14);
      LOBYTE(v16) = 1;
      CDC::~CDC(this: &pDC);
      LOBYTE(v16) = 0;
      CWindowDC::~CWindowDC(this: &v10);
      return 1;
    }
  }
  AfxMessageBox(nIDPrompt: 0x3E8Au, nType: 0, nIDHelp: 0xFFFFFFFF);
LABEL_3:
  LOBYTE(v16) = 2;
  v14.__vftable = (CGdiObject_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: &v14);
  LOBYTE(v16) = 1;
  CDC::~CDC(this: &pDC);
  LOBYTE(v16) = 0;
  CWindowDC::~CWindowDC(this: &v10);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10416261
// Name: public: void CUserTool::SetCommand(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CUserTool::SetCommand(CUserTool *this, const char *lpszCmd)
{
  if ( lpszCmd != nullptr
    && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(this: &this->m_strCommand, psz: lpszCmd) != 0 )
  {
    ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strCommand, pszSrc: lpszCmd);
    this->DeleteIcon(this);
    this->m_hIcon = this->SetToolIcon(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104162A1
// Name: public: virtual struct HICON__ __near * CUserTool::SetToolIcon(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HICON__ *__thiscall CUserTool::SetToolIcon(CUserTool *this)
{
  const char *v2; // edi
  HICON__ *hIcon; // esi
  int v5; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v6; // [esp+14h] [ebp-278h] BYREF
  SHFILEINFOA psfi; // [esp+18h] [ebp-274h] BYREF
  CHAR Buffer[272]; // [esp+178h] [ebp-114h] BYREF
  int v9; // [esp+288h] [ebp-4h]

  v6.m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)this->m_strCommand.m_pszData - 1)[1];
  v9 = 0;
  if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(this: &v6, pszSub: "\\", iStart: 0) == -1
    && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(this: &v6, pszSub: "/", iStart: 0) == -1
    && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(this: &v6, pszSub: ":", iStart: 0) == -1 )
  {
    v2 = (const char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)this->m_strCommand.m_pszData - 1)[1];
    LOBYTE(v9) = 1;
    if ( SearchPathA(
           lpPath: nullptr,
           lpFileName: v2,
           lpExtension: nullptr,
           nBufferLength: 0x104u,
           lpBuffer: Buffer,
           lpFilePart: nullptr) == 0 )
    {
      hIcon = this->LoadDefaultIcon(this);
      ATL::CStringData::Release(this: (ATL::CStringData *)v2 - 1);
      goto LABEL_6;
    }
    strlen(buf: (unsigned __int8 *)Buffer);
    ATL::CSimpleStringT<char,0>::SetString(this: &v6, pszSrc: Buffer, nLength: v5);
    LOBYTE(v9) = 0;
    ATL::CStringData::Release(this: (ATL::CStringData *)v2 - 1);
  }
  if ( SHGetFileInfoA(pszPath: v6.m_pszData, dwFileAttributes: 0, &psfi, cbFileInfo: 0x160u, uFlags: 0x105u) != 0 )
    hIcon = psfi.hIcon;
  else
    hIcon = this->LoadDefaultIcon(this);
LABEL_6:
  ATL::CStringData::Release(this: (ATL::CStringData *)v6.m_pszData - 1);
  return hIcon;
}

//------------------------------------------------------------------------------
// Address: 0x1041FA6E
// Name: public: virtual void CMFCToolTipCtrl::OnDrawSeparator(class CDC __near *,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::OnDrawSeparator(CMFCToolTipCtrl *this, CDC *pDC, int x1, int x2, int y)
{
  CPoint result; // [esp+0h] [ebp-8h] BYREF

  CDC::MoveTo(this: pDC, &result, x: x1, y);
  CDC::LineTo(this: pDC, x: x2, y);
}

//------------------------------------------------------------------------------
// Address: 0x1041FA99
// Name: public: void CMFCToolTipCtrl::SetParams(class CMFCToolTipInfo __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::SetParams(CMFCToolTipCtrl *this, CMFCToolTipInfo *pParams)
{
  CMFCToolTipInfo paramsDefault; // [esp+4h] [ebp-34h] BYREF

  if ( pParams != nullptr )
  {
    CMFCToolTipInfo::operator=(this: &this->m_Params, src: pParams);
  }
  else
  {
    CMFCToolTipInfo::CMFCToolTipInfo(this: &paramsDefault);
    CMFCToolTipInfo::operator=(this: &this->m_Params, src: &paramsDefault);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041FACB
// Name: public: void CMFCToolTipCtrl::SetLocation(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::SetLocation(CMFCToolTipCtrl *this, CPoint pt)
{
  this->m_ptLocation = pt;
}

//------------------------------------------------------------------------------
// Address: 0x1041FAE6
// Name: public: void CMFCToolTipCtrl::SetHotRibbonButton(class CMFCRibbonButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::SetHotRibbonButton(CMFCToolTipCtrl *this, CMFCRibbonButton *pRibbonButton)
{
  this->m_pRibbonButton = pRibbonButton;
}

//------------------------------------------------------------------------------
// Address: 0x1041FAF8
// Name: protected: int CMFCToolTipCtrl::GetFixedWidth(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolTipCtrl::GetFixedWidth(CMFCToolTipCtrl *this)
{
  long double m_dblRibbonImageScale; // st7

  if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
    m_dblRibbonImageScale = afxGlobalData.m_dblRibbonImageScale;
  else
    m_dblRibbonImageScale = 1.0;
  if ( this->m_sizeImage.cx > (int)(m_dblRibbonImageScale * 32.0) )
    return this->m_nFixedWidthWithImage;
  else
    return this->m_nFixedWidthRegular;
}

//------------------------------------------------------------------------------
// Address: 0x1041FB31
// Name: protected: int CMFCToolTipCtrl::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolTipCtrl::OnCreate(CMFCToolTipCtrl *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax
  CWnd *v4; // eax
  CMFCToolBar *v5; // eax

  result = CWnd::Default(this);
  if ( result != -1 )
  {
    v4 = CWnd::FromHandlePermanent(hWnd: lpCreateStruct->hwndParent);
    v5 = (CMFCToolBar *)AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: v4);
    this->m_pToolBar = v5;
    if ( v5 != nullptr && CObject::IsKindOf(this: v5, pClass: &CMFCOutlookBarPane::classCMFCOutlookBarPane) != 0 )
      this->m_pToolBar = nullptr;
    CWnd::ModifyStyle(this, dwRemove: 0x800000u, dwAdd: 0, nFlags: 0);
    if ( this->m_Params.m_bBalloonTooltip != 0 )
      CWnd::ModifyStyle(this, dwRemove: 0, dwAdd: 0x40u, nFlags: 0);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041FBAD
// Name: protected: int CMFCToolTipCtrl::OnEraseBkgnd(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolTipCtrl::OnEraseBkgnd(CMFCToolTipCtrl *this, CDC *pDC)
{
  unsigned int clrDummy; // [esp+Ch] [ebp-1Ch] BYREF
  CDC *v5; // [esp+10h] [ebp-18h]
  CRect rect; // [esp+14h] [ebp-14h] BYREF

  v5 = pDC;
  memset(&rect, 0, sizeof(rect));
  GetClientRect(hWnd: this->m_hWnd, lpRect: &rect);
  ((void (__thiscall *)(CMFCToolTipCtrl *, CDC *, int, int, int, int, unsigned int *, unsigned int *))this->OnFillBackground)(
    a1: this,
    a2: pDC,
    a3: rect.left,
    a4: rect.top,
    a5: rect.right,
    a6: rect.bottom,
    a7: &clrDummy,
    a8: &clrDummy);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1041FC17
// Name: protected: void CMFCToolTipCtrl::GetHotButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::GetHotButton(CMFCToolTipCtrl *this)
{
  int v2; // eax
  CMFCToolBarButton *Button; // eax
  CMFCToolBar *m_pToolBar; // ecx
  CMFCToolBarImages *LockedMenuImages; // eax
  CPoint ptToolBar; // [esp+8h] [ebp-8h] BYREF

  this->m_pHotButton = nullptr;
  this->m_pToolBarImages = nullptr;
  if ( this->m_pRibbonButton == nullptr && this->m_pToolBar != nullptr )
  {
    ptToolBar.x = 0;
    ptToolBar.y = 0;
    GetCursorPos(lpPoint: &ptToolBar);
    ScreenToClient(hWnd: this->m_pToolBar->m_hWnd, lpPoint: &ptToolBar);
    v2 = ((int (__thiscall *)(CMFCToolBar *, int, int))this->m_pToolBar->HitTest)(
           a1: this->m_pToolBar,
           a2: ptToolBar.x,
           a3: ptToolBar.y);
    Button = CMFCToolBar::GetButton(this: this->m_pToolBar, nIndex: v2);
    this->m_pHotButton = Button;
    if ( Button != nullptr )
    {
      m_pToolBar = this->m_pToolBar;
      if ( m_pToolBar->m_bLocked != 0 )
      {
        LockedMenuImages = CMFCToolBar::GetLockedMenuImages(this: m_pToolBar);
LABEL_8:
        this->m_pToolBarImages = LockedMenuImages;
        return;
      }
      if ( Button->m_bUserButton != 0 )
      {
        LockedMenuImages = CMFCToolBar::m_pUserImages;
        goto LABEL_8;
      }
      this->m_pToolBarImages = &CMFCToolBar::m_MenuImages;
      if ( CMFCToolBar::m_MenuImages.m_iCount <= 0 )
        this->m_pToolBarImages = &CMFCToolBar::m_Images;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041FCDC
// Name: protected: void CMFCToolTipCtrl::OnPop(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::OnPop(CMFCToolTipCtrl *this, tagNMHDR *__formal, int *pResult)
{
  this->m_pHotButton = nullptr;
  this->m_pToolBarImages = nullptr;
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strDescription);
  this->m_ptLocation.x = -1;
  this->m_pRibbonButton = nullptr;
  this->m_nRibbonImageType = 0;
  this->m_ptLocation.y = -1;
  *pResult = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1041FD26
// Name: public: CMFCToolTipCtrl::CMFCToolTipCtrl(class CMFCToolTipInfo __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolTipCtrl *__thiscall CMFCToolTipCtrl::CMFCToolTipCtrl(CMFCToolTipCtrl *this, CMFCToolTipInfo *pParams)
{
  CAfxStringMgr *StringManager; // eax

  CToolTipCtrl::CToolTipCtrl(this);
  this->__vftable = (CMFCToolTipCtrl_vtbl *)&CMFCToolTipCtrl::`vftable';
  CMFCToolTipInfo::CMFCToolTipInfo(this: &this->m_Params);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strDescription, pStringMgr: StringManager);
  this->m_sizeImage.cx = 0;
  this->m_sizeImage.cy = 0;
  this->m_ptMargin.x = 0;
  this->m_ptMargin.y = 0;
  this->m_ptLocation.x = 0;
  this->m_ptLocation.y = 0;
  CMFCToolTipCtrl::SetParams(this, pParams);
  this->m_sizeImage.cy = 0;
  this->m_ptMargin.y = 0;
  this->m_sizeImage.cx = 0;
  this->m_ptMargin.x = 0;
  this->m_pToolBar = nullptr;
  this->m_pToolBarImages = nullptr;
  this->m_pHotButton = nullptr;
  this->m_pRibbonButton = nullptr;
  this->m_nRibbonImageType = 0;
  this->m_nFixedWidthRegular = 0;
  this->m_nFixedWidthWithImage = 0;
  this->m_ptLocation.x = -1;
  this->m_ptLocation.y = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1041FDE5
// Name: public: virtual CMFCToolTipCtrl::~CMFCToolTipCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::~CMFCToolTipCtrl(CMFCToolTipCtrl *this)
{
  ATL::CStringData *v2; // ecx

  v2 = (ATL::CStringData *)(this->m_strDescription.m_pszData - 16);
  this->__vftable = (CMFCToolTipCtrl_vtbl *)&CMFCToolTipCtrl::`vftable';
  ATL::CStringData::Release(this: v2);
  CToolTipCtrl::~CToolTipCtrl(this);
}

//------------------------------------------------------------------------------
// Address: 0x1041FE06
// Name: public: virtual class CSize CMFCToolTipCtrl::OnDrawDescription(class CDC __near *,class CRect,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCToolTipCtrl::OnDrawDescription(
        CMFCToolTipCtrl *this,
        CSize *result,
        CDC *pDC,
        CRect rect,
        int bCalcOnly)
{
  int v6; // eax
  int FixedWidth; // eax
  int cx; // ecx
  unsigned int v9; // ecx
  int v10; // ebx
  CFont *pOldFont; // [esp+Ch] [ebp-4h]

  v6 = 0;
  if ( this->m_Params.m_bDrawDescription != 0 )
  {
    pOldFont = pDC->SelectObject(this: pDC, a2: &afxGlobalData.fontTooltip);
    FixedWidth = CMFCToolTipCtrl::GetFixedWidth(this);
    if ( FixedWidth <= 0 || (cx = this->m_sizeImage.cx) > 32 )
    {
      rect.right = rect.left + this->m_Params.m_nMaxDescrWidth;
    }
    else
    {
      rect.right = FixedWidth + rect.left;
      if ( cx > 0 && this->m_Params.m_bDrawIcon != 0 )
        rect.right -= cx + this->m_ptMargin.x;
    }
    v9 = 16;
    if ( bCalcOnly != 0 )
      v9 = 1040;
    v10 = pDC->DrawTextA(
            this: pDC,
            a2: this->m_strDescription.m_pszData,
            a3: *((_DWORD *)this->m_strDescription.m_pszData - 3),
            a4: &rect,
            a5: v9);
    pDC->SelectObject(this: pDC, a2: pOldFont);
    v6 = rect.right - rect.left;
    result->cy = v10;
  }
  else
  {
    result->cy = 0;
  }
  result->cx = v6;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041FEC3
// Name: public: static class CObject __near * CMFCToolTipCtrl::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolTipCtrl *__stdcall CMFCToolTipCtrl::CreateObject()
{
  CMFCToolTipCtrl *v0; // ecx
  CMFCToolTipCtrl *result; // eax

  v0 = (CMFCToolTipCtrl *)operator new(nSize: 0xFCu);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCToolTipCtrl::CMFCToolTipCtrl(this: v0, pParams: nullptr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041FF15
// Name: public: virtual class CSize CMFCToolTipCtrl::OnDrawLabel(class CDC __near *,class CRect,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCToolTipCtrl::OnDrawLabel(
        CMFCToolTipCtrl *this,
        CSize *result,
        CDC *pDC,
        CRect rect,
        int bCalcOnly)
{
  CAfxStringMgr *StringManager; // eax
  COleDropTarget *m_pDropTarget; // ecx
  CFont *p_fontTooltip; // eax
  unsigned int v8; // edx
  int cy; // eax
  CSize *TextExtent; // eax
  unsigned int v11; // edx
  CFont *pOldFont; // [esp+10h] [ebp-20h]
  CSize v14; // [esp+14h] [ebp-1Ch] BYREF
  CWnd *v15; // [esp+1Ch] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strText; // [esp+20h] [ebp-10h] BYREF
  int v17; // [esp+2Ch] [ebp-4h]

  v15 = this;
  result->cx = 0;
  result->cy = 0;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strText, pStringMgr: StringManager);
  v17 = 0;
  CWnd::GetWindowTextA(this: v15, rString: &strText);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Replace(this: &strText, pszOld: "\t", pszNew: "    ");
  if ( v15[1].m_xAccessibleServer.__vftable == nullptr
    || (m_pDropTarget = v15[1].m_pDropTarget, v14.cy = 1, m_pDropTarget[-1].m_dwLastTick == 0) )
  {
    v14.cy = 0;
  }
  if ( v15[1].m_ptGestureFrom.x == 0 || (p_fontTooltip = &afxGlobalData.fontBold, v14.cy == 0) )
    p_fontTooltip = &afxGlobalData.fontTooltip;
  pOldFont = pDC->SelectObject(this: pDC, a2: p_fontTooltip);
  if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(this: &strText, ch: 0xAu, iStart: 0) >= 0 )
  {
    v8 = 2048;
    if ( bCalcOnly != 0 )
      v8 = 3072;
    if ( v15[1].m_pStdObject != nullptr )
      v8 |= 0x800u;
    cy = pDC->DrawTextA(this: pDC, a2: strText.m_pszData, a3: *((_DWORD *)strText.m_pszData - 3), a4: &rect, a5: v8);
    result->cx = rect.right - rect.left;
    goto LABEL_15;
  }
  if ( bCalcOnly != 0 )
  {
    TextExtent = CDC::GetTextExtent(this: pDC, result: &v14, str: &strText);
    result->cx = TextExtent->cx;
    cy = TextExtent->cy;
LABEL_15:
    result->cy = cy;
    goto LABEL_21;
  }
  v11 = 288;
  if ( v14.cy == 0 )
    v11 = 292;
  if ( v15[1].m_pStdObject != nullptr )
    v11 |= 0x800u;
  result->cy = pDC->DrawTextA(
                 this: pDC,
                 a2: strText.m_pszData,
                 a3: *((_DWORD *)strText.m_pszData - 3),
                 a4: &rect,
                 a5: v11);
  result->cx = rect.right - rect.left;
LABEL_21:
  pDC->SelectObject(this: pDC, a2: pOldFont);
  ATL::CStringData::Release(this: (ATL::CStringData *)strText.m_pszData - 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420069
// Name: protected: void CMFCToolTipCtrl::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::OnPaint(CMFCToolTipCtrl *this)
{
  CDC *p_m_dcMem; // eax
  int y; // eax
  unsigned int m_clrBorder; // eax
  unsigned int m_clrText; // eax
  int v6; // eax
  CDC *v7; // esi
  int v8; // ecx
  HWND__ *v9; // [esp-10h] [ebp-128h]
  HWND__ *m_hWnd; // [esp-8h] [ebp-120h]
  int v11; // [esp+10h] [ebp-108h]
  int v12; // [esp+14h] [ebp-104h]
  int right; // [esp+18h] [ebp-100h]
  int v14; // [esp+1Ch] [ebp-FCh]
  CFont *pFont; // [esp+20h] [ebp-F8h]
  CPen v16; // [esp+24h] [ebp-F4h] BYREF
  int left; // [esp+2Ch] [ebp-ECh]
  int top; // [esp+30h] [ebp-E8h]
  int v19; // [esp+34h] [ebp-E4h] BYREF
  int bottom; // [esp+38h] [ebp-E0h]
  unsigned int v21; // [esp+3Ch] [ebp-DCh] BYREF
  unsigned int crColor; // [esp+40h] [ebp-D8h] BYREF
  CDC *v23; // [esp+44h] [ebp-D4h]
  tagRECT rc; // [esp+48h] [ebp-D0h] BYREF
  CPaintDC v25; // [esp+58h] [ebp-C0h] BYREF
  CMemDC v26; // [esp+ACh] [ebp-6Ch] BYREF
  LPARAM lParam; // [esp+E8h] [ebp-30h] BYREF
  int v28; // [esp+ECh] [ebp-2Ch]
  int v29; // [esp+F0h] [ebp-28h]
  int v30; // [esp+F4h] [ebp-24h]
  tagRECT Rect; // [esp+F8h] [ebp-20h] BYREF
  int v32; // [esp+114h] [ebp-4h]

  if ( this->m_Params.m_bBalloonTooltip != 0 )
  {
    CWnd::OnPaint(this);
  }
  else
  {
    CPaintDC::CPaintDC(this: &v25, pWnd: this);
    v32 = 0;
    CMemDC::CMemDC(this: &v26, dc: &v25, pWnd: (HDC__ *)this);
    LOBYTE(v32) = 1;
    p_m_dcMem = &v26.m_dcMem;
    if ( v26.m_bMemDC == 0 )
      p_m_dcMem = v26.m_dc;
    v23 = p_m_dcMem;
    m_hWnd = this->m_hWnd;
    memset(&Rect, 0, sizeof(Rect));
    GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
    v9 = this->m_hWnd;
    lParam = 0;
    v28 = 0;
    v29 = 0;
    v30 = 0;
    SendMessageA(hWnd: v9, Msg: 0x41Bu, wParam: 0, (LPARAM)&lParam);
    rc.left = Rect.left;
    rc.top = v28 + Rect.top;
    rc.right = Rect.right - v29;
    rc.bottom = Rect.bottom - v30;
    y = this->m_ptMargin.y;
    rc.left = lParam + Rect.left;
    InflateRect(lprc: &rc, dx: -this->m_ptMargin.x, dy: -y);
    m_clrBorder = this->m_Params.m_clrBorder;
    if ( m_clrBorder == -1 )
      m_clrBorder = GetSysColor(nIndex: 23);
    crColor = m_clrBorder;
    m_clrText = this->m_Params.m_clrText;
    if ( m_clrText == -1 )
      m_clrText = GetSysColor(nIndex: 23);
    v21 = m_clrText;
    ((void (__thiscall *)(CMFCToolTipCtrl *, CDC *, int, int, int, int, unsigned int *, unsigned int *))this->OnFillBackground)(
      a1: this,
      a2: v23,
      a3: Rect.left,
      a4: Rect.top,
      a5: Rect.right,
      a6: Rect.bottom,
      a7: &v21,
      a8: &crColor);
    CPen::CPen(this: &v16, nPenStyle: 0, nWidth: 1, crColor);
    LOBYTE(v32) = 2;
    pFont = CDC::SelectObject(this: v23, pFont: (CFont *)&v16);
    ((void (__thiscall *)(CMFCToolTipCtrl *, CDC *, int, int, int, int, unsigned int))this->OnDrawBorder)(
      a1: this,
      a2: v23,
      a3: Rect.left,
      a4: Rect.top,
      a5: Rect.right,
      a6: Rect.bottom,
      a7: crColor);
    if ( CPoint::operator!=(this: (CPoint *)&this->m_sizeImage, point: 0) != 0 && this->m_Params.m_bDrawIcon != 0 )
    {
      v6 = rc.left + this->m_sizeImage.cx;
      left = rc.left;
      top = rc.top;
      bottom = rc.bottom;
      v19 = v6;
      bottom = rc.top + this->m_sizeImage.cy;
      ((void (__thiscall *)(CMFCToolTipCtrl *, CDC *, int, int, int, int))this->OnDrawIcon)(
        a1: this,
        a2: v23,
        a3: rc.left,
        a4: rc.top,
        a5: v6,
        a6: bottom);
      rc.left += this->m_sizeImage.cx + this->m_ptMargin.x;
    }
    v7 = v23;
    CDC::SetBkMode(this: v23, nBkMode: 1);
    v7->SetTextColor(this: v7, a2: v21);
    v8 = *(_DWORD *)(((int (__thiscall *)(CMFCToolTipCtrl *, int *, CDC *, int, int, int, int, _DWORD))this->OnDrawLabel)(
                       a1: this,
                       a2: &v19,
                       a3: v23,
                       a4: rc.left,
                       a5: rc.top,
                       a6: rc.right,
                       a7: rc.bottom,
                       a8: 0)
                   + 4);
    if ( *((_DWORD *)this->m_strDescription.m_pszData - 3) != 0 && this->m_Params.m_bDrawDescription != 0 )
    {
      v11 = rc.left;
      right = rc.right;
      v14 = rc.bottom;
      v12 = v8 + rc.top + 3 * this->m_ptMargin.y / 2;
      if ( this->m_Params.m_bDrawSeparator != 0 )
        this->OnDrawSeparator(
          this,
          a2: v23,
          a3: rc.left,
          a4: rc.right,
          a5: v8 + rc.top + 3 * this->m_ptMargin.y / 2 - this->m_ptMargin.y / 2);
      ((void (__thiscall *)(CMFCToolTipCtrl *, int *, CDC *, int, int, int, int, _DWORD))this->OnDrawDescription)(
        a1: this,
        a2: &v19,
        a3: v23,
        a4: v11,
        a5: v12,
        a6: right,
        a7: v14,
        a8: 0);
    }
    CDC::SelectObject(this: v23, pFont);
    LOBYTE(v32) = 1;
    v16.__vftable = (CPen_vtbl *)&CPen::`vftable';
    CGdiObject::~CGdiObject(this: &v16);
    LOBYTE(v32) = 0;
    CMemDC::~CMemDC(this: &v26);
    v32 = -1;
    CPaintDC::~CPaintDC(this: &v25);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104203B3
// Name: protected: void CMFCToolTipCtrl::OnShow(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::OnShow(CMFCToolTipCtrl *this, tagNMHDR *__formal, int *pResult)
{
  CMFCVisualManager *Instance; // eax
  CSize *v5; // eax
  int v6; // ecx
  CMFCToolTipCtrl_vtbl *v7; // eax
  int v8; // edi
  int *v9; // eax
  int v10; // ecx
  int v11; // eax
  bool v12; // cc
  int cx; // eax
  int FixedWidth; // eax
  int top; // edi
  HMONITOR v16; // eax
  int SystemMetrics; // eax
  int y; // ecx
  int v19; // edx
  int v20; // eax
  int v21; // eax
  CMFCRibbonBar *TopLevelRibbonBar; // eax
  HWND v23; // eax
  _DWORD *m_hObject; // ecx
  int right; // eax
  HRGN RoundRectRgn; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-E4h]
  HWND__ *v28; // [esp-8h] [ebp-DCh]
  HWND__ *v29; // [esp-8h] [ebp-DCh]
  CClientDC v30; // [esp+10h] [ebp-C4h] BYREF
  int v31; // [esp+24h] [ebp-B0h] BYREF
  int v32; // [esp+28h] [ebp-ACh]
  tagPOINT Point; // [esp+2Ch] [ebp-A8h] BYREF
  CGdiObject v34; // [esp+34h] [ebp-A0h] BYREF
  int v35; // [esp+3Ch] [ebp-98h] BYREF
  int left; // [esp+40h] [ebp-94h]
  int cy; // [esp+44h] [ebp-90h]
  int v38; // [esp+48h] [ebp-8Ch]
  tagRECT Rect; // [esp+4Ch] [ebp-88h] BYREF
  tagMONITORINFO mi; // [esp+5Ch] [ebp-78h] BYREF
  LPARAM lParam[4]; // [esp+84h] [ebp-50h] BYREF
  tagRECT v42; // [esp+94h] [ebp-40h] BYREF
  tagRECT rcDst; // [esp+A4h] [ebp-30h] BYREF
  tagRECT v44; // [esp+B4h] [ebp-20h] BYREF
  int v45; // [esp+D0h] [ebp-4h]

  *pResult = 0;
  v34.m_hObject = pResult;
  if ( this->m_Params.m_bVislManagerTheme != 0 )
  {
    Instance = CMFCVisualManager::GetInstance();
    Instance->GetToolTipInfo(this: Instance, a2: &this->m_Params, a3: -1u);
    this->m_Params.m_bVislManagerTheme = 1;
  }
  if ( this->m_Params.m_bBalloonTooltip == 0 )
  {
    Point.x = 0;
    Point.y = 0;
    GetCursorPos(lpPoint: &Point);
    CMFCToolTipCtrl::GetHotButton(this);
    if ( this->m_Params.m_bDrawIcon != 0 )
    {
      v5 = this->GetIconSize(this, result: &v35);
    }
    else
    {
      v35 = 0;
      left = 0;
      v5 = (CSize *)&v35;
    }
    this->m_sizeImage.cx = v5->cx;
    this->m_sizeImage.cy = v5->cy;
    if ( this->m_Params.m_bRoundedCorners != 0 )
    {
      v35 = 6;
      left = 4;
    }
    else
    {
      v35 = 4;
      left = 2;
    }
    v6 = v35;
    this->m_ptMargin.y = left;
    m_hWnd = this->m_hWnd;
    this->m_ptMargin.x = v6;
    memset(lParam, 0, sizeof(lParam));
    SendMessageA(hWnd: m_hWnd, Msg: 0x41Bu, wParam: 0, (LPARAM)lParam);
    v28 = this->m_hWnd;
    memset(&Rect, 0, sizeof(Rect));
    GetClientRect(hWnd: v28, lpRect: &Rect);
    CClientDC::CClientDC(this: &v30, pWnd: this);
    v7 = this->__vftable;
    v45 = 0;
    ((void (__thiscall *)(CMFCToolTipCtrl *, int *, CClientDC *, int, int, int, int, int))v7->OnDrawLabel)(
      a1: this,
      a2: &v31,
      a3: &v30,
      a4: Rect.left,
      a5: Rect.top,
      a6: Rect.right,
      a7: Rect.bottom,
      a8: 1);
    v8 = 0;
    v38 = v31;
    cy = v32;
    v35 = 0;
    if ( this->m_Params.m_bDrawDescription != 0 && *((_DWORD *)this->m_strDescription.m_pszData - 3) != 0 )
    {
      v9 = (int *)((int (__thiscall *)(CMFCToolTipCtrl *, int *, CClientDC *, int, int, int, int, int))this->OnDrawDescription)(
                    a1: this,
                    a2: &v42.right,
                    a3: &v30,
                    a4: Rect.left,
                    a5: Rect.top,
                    a6: Rect.right,
                    a7: Rect.bottom,
                    a8: 1);
      v10 = *v9;
      v8 = v9[1];
      cy += v8 + 2 * this->m_ptMargin.y;
      v35 = v10;
      if ( v38 <= v10 )
        v38 = v10;
      v11 = this->m_sizeImage.cy;
      v12 = cy <= v11;
    }
    else
    {
      v11 = this->m_sizeImage.cy;
      v12 = v32 <= v11;
    }
    if ( v12 )
      cy = v11;
    cx = this->m_sizeImage.cx;
    if ( cx > 0 && this->m_Params.m_bDrawIcon != 0 )
      v38 += cx + this->m_ptMargin.x;
    v38 += 2 * this->m_ptMargin.x;
    cy += 2 * this->m_ptMargin.y;
    FixedWidth = CMFCToolTipCtrl::GetFixedWidth(this);
    if ( FixedWidth > 0 && (v35 != 0 || v8 != 0) && v38 <= FixedWidth )
      v38 = FixedWidth;
    v29 = this->m_hWnd;
    memset(&v44, 0, sizeof(v44));
    GetWindowRect(hWnd: v29, lpRect: &v44);
    top = v44.top;
    left = v44.left;
    if ( CPoint::operator!=(this: &this->m_ptLocation, point: (tagPOINT)-1LL) != 0 )
    {
      top = this->m_ptLocation.y;
      left = this->m_ptLocation.x;
      *(_DWORD *)v34.m_hObject = 1;
    }
    memset(&rcDst, 0, sizeof(rcDst));
    mi.cbSize = 40;
    v16 = MonitorFromPoint(pt: *(POINT *)&v44.left, dwFlags: 2u);
    if ( GetMonitorInfoA(hMonitor: v16, lpmi: &mi) )
      CopyRect(lprcDst: &rcDst, lprcSrc: &mi.rcWork);
    else
      SystemParametersInfoA(uiAction: 0x30u, uiParam: 0, pvParam: &rcDst, fWinIni: 0);
    SystemMetrics = GetSystemMetrics(nIndex: 14);
    y = Point.y;
    v19 = cy + Point.y + SystemMetrics;
    v20 = top + cy + 2;
    if ( v19 > v20 )
    {
      v21 = GetSystemMetrics(nIndex: 14);
      y = Point.y;
      v20 = cy + Point.y + v21;
    }
    if ( v20 <= rcDst.bottom )
    {
      m_hObject = v34.m_hObject;
    }
    else
    {
      top = y - cy - 1;
      if ( this->m_pRibbonButton != nullptr && CPoint::operator!=(this: &this->m_ptLocation, point: (tagPOINT)-1LL) != 0 )
      {
        TopLevelRibbonBar = CMFCRibbonBaseElement::GetTopLevelRibbonBar(this: this->m_pRibbonButton);
        if ( TopLevelRibbonBar != nullptr )
        {
          v23 = TopLevelRibbonBar->m_hWnd;
          if ( v23 != nullptr )
          {
            memset(&v42, 0, sizeof(v42));
            GetWindowRect(hWnd: v23, lpRect: &v42);
            top = v42.top - cy;
          }
        }
      }
      m_hObject = v34.m_hObject;
      *(_DWORD *)v34.m_hObject = 1;
    }
    right = rcDst.right;
    if ( left + v38 + 2 > rcDst.right )
    {
      if ( *m_hObject == 1 )
        right = Point.x;
      else
        *m_hObject = 1;
      left = right - v38 - 1;
    }
    if ( *m_hObject == 1 )
      CWnd::SetWindowPos(this, pWndInsertAfter: nullptr, x: left, y: top, cx: v38, cy, nFlags: 0x14u);
    else
      CWnd::SetWindowPos(this, pWndInsertAfter: nullptr, x: -1, y: -1, cx: v38, cy, nFlags: 0x16u);
    if ( this->m_Params.m_bRoundedCorners != 0 )
    {
      v34.m_hObject = nullptr;
      v34.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
      LOBYTE(v45) = 1;
      RoundRectRgn = CreateRoundRectRgn(x1: 0, y1: 0, x2: v38 + 1, y2: cy + 1, w: 4, h: 4);
      CGdiObject::Attach(this: &v34, hObject: RoundRectRgn);
      SetWindowRgn(hWnd: this->m_hWnd, hRgn: (HRGN)v34.m_hObject, bRedraw: false);
      LOBYTE(v45) = 0;
      v34.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
      CGdiObject::~CGdiObject(this: &v34);
    }
    v45 = -1;
    CClientDC::~CClientDC(this: &v30);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042087B
// Name: public: virtual void CMFCToolTipCtrl::OnFillBackground(class CDC __near *,class CRect,unsigned long __near &,unsigned long __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::OnFillBackground(
        CMFCToolTipCtrl *this,
        CDC *pDC,
        CRect rect,
        unsigned int *__formal,
        unsigned int *a5)
{
  HDC__ *m_hDC; // edi
  HBRUSH SysColorBrush; // eax
  unsigned int m_nGradientAngle; // eax
  CDrawingManager dm; // [esp+10h] [ebp-1Ch] BYREF
  CBrush br; // [esp+18h] [ebp-14h] BYREF
  int v11; // [esp+28h] [ebp-4h]

  m_hDC = (HDC__ *)pDC;
  if ( this->m_Params.m_clrFill == -1 )
  {
    if ( pDC != nullptr )
      m_hDC = pDC->m_hDC;
    SysColorBrush = GetSysColorBrush(nIndex: 24);
    FillRect(hDC: m_hDC, lprc: &rect, hbr: SysColorBrush);
  }
  else if ( this->m_Params.m_clrFillGradient == -1 )
  {
    CBrush::CBrush(this: &br, crColor: this->m_Params.m_clrFill);
    FillRect(hDC: pDC->m_hDC, lprc: &rect, hbr: (HBRUSH)br.m_hObject);
    br.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
    CGdiObject::~CGdiObject(this: &br);
  }
  else
  {
    CDrawingManager::CDrawingManager(this: &dm, m_dc: pDC);
    m_nGradientAngle = this->m_Params.m_nGradientAngle;
    v11 = 0;
    if ( m_nGradientAngle == -1 )
      m_nGradientAngle = 90;
    CDrawingManager::FillGradient2(
      this: &dm,
      rect,
      colorStart: this->m_Params.m_clrFillGradient,
      colorFinish: this->m_Params.m_clrFill,
      nAngle: m_nGradientAngle);
    v11 = -1;
    CDrawingManager::~CDrawingManager(this: &dm);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10420937
// Name: public: virtual void CMFCToolTipCtrl::SetDescription(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::SetDescription(
        CMFCToolTipCtrl *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strDescription)
{
  CMFCToolTipCtrl::GetHotButton(this);
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strDescription, strSrc: (ATL::CStringData *)&strDescription);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Replace(
    this: &this->m_strDescription,
    pszOld: "\t",
    pszNew: "    ");
  ATL::CStringData::Release(this: (ATL::CStringData *)strDescription.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x10420985
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCToolTipCtrl::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCToolTipCtrl::GetMessageMap(CMFCToolTipCtrl *this)
{
  return (const AFX_MSGMAP *)&off_106902A8;
}

//------------------------------------------------------------------------------
// Address: 0x1042098B
// Name: public: virtual struct CRuntimeClass __near * CMFCRibbonLabel::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCRibbonLabel::GetRuntimeClass(CMFCRibbonLabel *this)
{
  return &CMFCRibbonLabel::classCMFCRibbonLabel;
}

//------------------------------------------------------------------------------
// Address: 0x10420991
// Name: protected: CMFCRibbonLabel::CMFCRibbonLabel(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonLabel *__thiscall CMFCRibbonLabel::CMFCRibbonLabel(CMFCRibbonLabel *this)
{
  CMFCRibbonButton::CMFCRibbonButton(this);
  this->__vftable = (CMFCRibbonLabel_vtbl *)&CMFCRibbonLabel::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104209A5
// Name: protected: virtual class CSize CMFCRibbonLabel::GetRegularSize(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCRibbonLabel::GetRegularSize(CMFCRibbonLabel *this, CSize *result, CDC *pDC)
{
  this->GetIntermediateSize(this, result, a3: pDC);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104209BC
// Name: protected: virtual int CMFCRibbonCaptionButton::AddToListBox(class CMFCRibbonCommandsListBox __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonCaptionButton::AddToListBox(
        CMFCRibbonCaptionButton *this,
        CMFCRibbonCommandsListBox *__formal,
        CMFCRibbonCommandsListBox *__formala)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104209C2
// Name: public: virtual int CMFCRibbonLabel::SetACCData(class CWnd __near *,class CAccessibilityData __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonLabel::SetACCData(CMFCRibbonLabel *this, CWnd *pParent, CAccessibilityData *data)
{
  CMFCRibbonBaseElement::SetACCData(this, pParent, data);
  data->m_bAccState = 0;
  data->m_nAccRole = 20;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104209E7
// Name: protected: virtual class CSize CMFCRibbonLabel::GetIntermediateSize(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCRibbonLabel::GetIntermediateSize(CMFCRibbonLabel *this, CSize *result, CDC *pDC)
{
  int v4; // ecx
  int v5; // eax
  int cy; // edx

  if ( CMFCRibbonBaseElement::IsMenuMode(this) != 0 )
  {
    v4 = 3;
    v5 = 3;
  }
  else
  {
    v5 = 2;
    v4 = 4;
  }
  this->m_szMargin.cy = v4;
  this->m_szMargin.cx = v5;
  this->OnCalcTextSize(this, a2: pDC);
  cy = this->m_sizeTextRight.cy;
  result->cx = this->m_sizeTextRight.cx + 2 * this->m_szMargin.cx;
  result->cy = cy + 2 * this->m_szMargin.cy;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420A49
// Name: public: static class CObject __near * CMFCRibbonLabel::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonLabel *__stdcall CMFCRibbonLabel::CreateObject()
{
  CMFCRibbonLabel *v0; // ecx
  CMFCRibbonLabel *result; // eax

  v0 = (CMFCRibbonLabel *)operator new(nSize: 0x164u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCRibbonLabel::CMFCRibbonLabel(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420AA0
// Name: protected: virtual void CMFCRibbonLabel::OnDraw(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonLabel::OnDraw(CMFCRibbonLabel *this, CDC *pDC)
{
  CRect *p_m_rect; // esi
  int *p_top; // esi
  int cx; // eax
  CMFCVisualManager *Instance; // eax
  CDC *v7; // esi
  unsigned int v8; // eax
  CMFCVisualManager *v9; // eax
  int v10; // esi
  int v11; // eax
  unsigned int cltTextOld; // [esp+Ch] [ebp-20h]
  CFont *pOldFont; // [esp+10h] [ebp-1Ch]
  CRect rectText; // [esp+18h] [ebp-14h] BYREF

  p_m_rect = &this->m_rect;
  if ( !IsRectEmpty(lprc: &this->m_rect) )
  {
    rectText.left = p_m_rect->left;
    p_top = &p_m_rect->top;
    cx = this->m_szMargin.cx;
    rectText.top = *p_top++;
    rectText.right = *p_top;
    rectText.bottom = p_top[1];
    InflateRect(lprc: &rectText, dx: -cx, dy: 0);
    cltTextOld = -1;
    if ( CMFCRibbonBaseElement::IsMenuMode(this) != 0 )
    {
      rectText.bottom -= 2;
      Instance = CMFCVisualManager::GetInstance();
      v7 = pDC;
      v8 = ((int (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int))Instance->OnDrawMenuLabel)(
             a1: Instance,
             a2: pDC,
             a3: this->m_rect.left,
             a4: this->m_rect.top,
             a5: this->m_rect.right,
             a6: this->m_rect.bottom);
      if ( v8 != -1 )
        cltTextOld = pDC->SetTextColor(this: pDC, a2: v8);
    }
    else
    {
      v9 = CMFCVisualManager::GetInstance();
      ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCRibbonLabel *, int, int, int, int))v9->OnDrawRibbonLabel)(
        a1: v9,
        a2: pDC,
        a3: this,
        a4: this->m_rect.left,
        a5: this->m_rect.top,
        a6: this->m_rect.right,
        a7: this->m_rect.bottom);
      v7 = pDC;
    }
    pOldFont = nullptr;
    if ( CMFCRibbonBaseElement::IsMenuMode(this) != 0 )
      pOldFont = v7->SelectObject(this: v7, a2: &afxGlobalData.fontBold);
    if ( CMFCRibbonBaseElement::IsMenuMode(this) != 0 || (v10 = 2064, this->m_bIsAlwaysLarge == 0) )
      v10 = 2084;
    if ( CMFCRibbonBaseElement::IsMenuMode(this) == 0 && this->m_bIsAlwaysLarge != 0 )
    {
      v11 = (rectText.bottom - this->m_sizeTextRight.cy - rectText.top) / 2;
      if ( v11 < 0 )
        v11 = 0;
      InflateRect(lprc: &rectText, dx: 0, dy: -v11);
    }
    ((void (__thiscall *)(CMFCRibbonLabel *, CDC *, ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *, int, int, int, int, int, int))this->DrawRibbonText)(
      a1: this,
      a2: pDC,
      a3: &this->m_strText,
      a4: rectText.left,
      a5: rectText.top,
      a6: rectText.right,
      a7: rectText.bottom,
      a8: v10,
      a9: -1);
    if ( pOldFont != nullptr )
      pDC->SelectObject(this: pDC, a2: pOldFont);
    if ( cltTextOld != -1 )
      pDC->SetTextColor(this: pDC, a2: cltTextOld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10420C11
// Name: protected: virtual void CMFCRibbonLabel::OnAfterChangeRect(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonLabel::OnAfterChangeRect(CMFCRibbonBaseElement *this, CDC *__formal)
{
  if ( *((_DWORD *)this->m_strToolTip.m_pszData - 3) == 0 )
    this->UpdateTooltipInfo(this);
}

//------------------------------------------------------------------------------
// Address: 0x10420C25
// Name: protected: virtual void CMFCRibbonLabel::OnCalcTextSize(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonLabel::OnCalcTextSize(CMFCRibbonLabel *this, CDC *pDC)
{
  ATL::CStringData *v3; // esi
  CDC_vtbl *v4; // edx
  int v5; // eax
  int v6; // ecx
  CFont *v7; // esi
  CSize result; // [esp+14h] [ebp-30h] BYREF
  int v9; // [esp+1Ch] [ebp-28h]
  int i; // [esp+20h] [ebp-24h]
  _DWORD v11[2]; // [esp+24h] [ebp-20h] BYREF
  int v12; // [esp+2Ch] [ebp-18h]
  int v13; // [esp+30h] [ebp-14h]
  int v14; // [esp+40h] [ebp-4h]

  if ( CMFCRibbonBaseElement::IsMenuMode(this) != 0 || this->m_bIsAlwaysLarge == 0 )
  {
    v7 = nullptr;
    if ( CMFCRibbonBaseElement::IsMenuMode(this) != 0 )
      v7 = pDC->SelectObject(this: pDC, a2: &afxGlobalData.fontBold);
    CMFCRibbonButton::OnCalcTextSize(this, pDC);
    if ( v7 != nullptr )
      pDC->SelectObject(this: pDC, a2: v7);
  }
  else
  {
    CMFCRibbonCategory::GetImageSize(this: this->m_pParent, &result, bIsLargeImage: 1);
    if ( result.cx != 0 || result.cy != 0 )
    {
      v9 = 2 * result.cy;
      v3 = ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)this->m_strText.m_pszData - 1) + 1;
      v14 = 0;
      for ( i = 10; i < 200; i += 10 )
      {
        v11[0] = 0;
        v11[1] = 0;
        v4 = pDC->__vftable;
        v12 = i;
        v13 = 10000;
        v5 = v4->DrawTextA(this: pDC, a2: (const char *)v3, a3: v3[-1].nDataLength, a4: (tagRECT *)v11, a5: 1040u);
        v6 = v12 - v11[0];
        if ( v5 <= v9 && v6 >= v5 )
          break;
      }
      this->m_sizeTextRight.cx = v6;
      this->m_sizeTextRight.cy = v5;
      ATL::CStringData::Release(this: v3 - 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10420D24
// Name: public: CMFCRibbonLabel::CMFCRibbonLabel(char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonLabel *__thiscall CMFCRibbonLabel::CMFCRibbonLabel(
        CMFCRibbonLabel *this,
        const char *lpszText,
        int bIsMultiLine)
{
  CMFCRibbonButton::CMFCRibbonButton(this);
  this->__vftable = (CMFCRibbonLabel_vtbl *)&CMFCRibbonLabel::`vftable';
  if ( lpszText == nullptr )
    AfxThrowInvalidArgException();
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strText, pszSrc: lpszText);
  this->m_bIsAlwaysLarge = bIsMultiLine;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10420D6D
// Name: public: CRibbonUndoLabel::CRibbonUndoLabel(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRibbonUndoLabel *__thiscall CRibbonUndoLabel::CRibbonUndoLabel(CRibbonUndoLabel *this, const char *lpszText)
{
  CMFCRibbonButton::CMFCRibbonButton(
    this,
    nID: 0,
    lpszText,
    nSmallImageIndex: -1,
    nLargeImageIndex: -1,
    bAlwaysShowDescription: 0);
  this->m_szMargin.cx = 0;
  this->__vftable = (CRibbonUndoLabel_vtbl *)&CRibbonUndoLabel::`vftable';
  this->m_szMargin.cy = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10420DA2
// Name: public: virtual void CRibbonUndoLabel::OnDraw(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRibbonUndoLabel::OnDraw(CRibbonUndoLabel *this, CDC *pDC)
{
  CRect rectText; // [esp+10h] [ebp-14h] BYREF

  rectText = this->m_rect;
  InflateRect(lprc: &rectText, dx: -5, dy: 0);
  ((void (__thiscall *)(CRibbonUndoLabel *, CDC *, ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *, int, int, int, int, int, int))this->DrawRibbonText)(
    a1: this,
    a2: pDC,
    a3: &this->m_strText,
    a4: rectText.left,
    a5: rectText.top,
    a6: rectText.right,
    a7: rectText.bottom,
    a8: 36,
    a9: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10420E09
// Name: public: static class CObject __near * CRibbonUndoLabel::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRibbonUndoLabel *__stdcall CRibbonUndoLabel::CreateObject()
{
  CRibbonUndoLabel *v0; // ecx
  CRibbonUndoLabel *result; // eax

  v0 = (CRibbonUndoLabel *)operator new(nSize: 0x164u);
  result = nullptr;
  if ( v0 != nullptr )
    return CRibbonUndoLabel::CRibbonUndoLabel(this: v0, lpszText: nullptr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420E3A
// Name: public: virtual struct CRuntimeClass __near * CRibbonUndoLabel::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CRibbonUndoLabel::GetRuntimeClass(CRibbonUndoLabel *this)
{
  return &CRibbonUndoLabel::classCRibbonUndoLabel;
}

//------------------------------------------------------------------------------
// Address: 0x10420E40
// Name: public: virtual struct CRuntimeClass __near * CMFCRibbonUndoButton::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCRibbonUndoButton::GetRuntimeClass(CMFCRibbonUndoButton *this)
{
  return &CMFCRibbonUndoButton::classCMFCRibbonUndoButton;
}

//------------------------------------------------------------------------------
// Address: 0x10420E46
// Name: protected: virtual void CMFCRibbonUndoButton::CopyFrom(class CMFCRibbonBaseElement const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonUndoButton::CopyFrom(CMFCRibbonUndoButton *this, const CMFCRibbonBaseElement *s)
{
  CMFCRibbonGallery::CopyFrom(this, s);
  this->m_nActionNumber = s[4].m_bCompactMode;
  CStringArray::SetSize(this: &this->m_arLabels, nNewSize: 0, nGrowBy: -1);
  CStringArray::Copy(this: &this->m_arLabels, src: (const CStringArray *)&s[4].m_bIsPressed);
  this->m_nIcons = (int)s[4].m_pOriginal;
  this->m_sizeMaxText = *(CSize *)&s[4].m_bIntermediateMode;
}

//------------------------------------------------------------------------------
// Address: 0x10420EB1
// Name: protected: virtual void CMFCRibbonUndoButton::OnClick(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonUndoButton::OnClick(CMFCRibbonUndoButton *this, CPoint point)
{
  this->m_nActionNumber = -1;
  CMFCRibbonButton::OnClick(this, point);
}

//------------------------------------------------------------------------------
// Address: 0x10420ECC
// Name: protected: virtual class CSize CMFCRibbonUndoButton::GetIconSize(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCRibbonUndoButton::GetIconSize(CMFCRibbonUndoButton *this, CSize *result)
{
  int cx; // edx
  int cy; // ecx

  cx = this->m_sizeMaxText.cx;
  cy = this->m_sizeMaxText.cy;
  result->cx = cx;
  result->cy = cy;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420EE9
// Name: protected: virtual int CMFCRibbonUndoButton::OnClickPaletteSubItem(class CMFCRibbonButton __near *,class CMFCRibbonPanelMenuBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonUndoButton::OnClickPaletteSubItem(
        CMFCRibbonUndoButton *this,
        CMFCRibbonButton *pButton,
        CMFCRibbonPanelMenuBar *pMenuBar)
{
  if ( CObject::IsKindOf(this: pButton, pClass: &CRibbonUndoLabel::classCRibbonUndoLabel) == 0 )
    return 0;
  this->ClosePopupMenu(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10420F18
// Name: public: virtual CMFCRibbonUndoButton::~CMFCRibbonUndoButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonUndoButton::~CMFCRibbonUndoButton(CMFCRibbonUndoButton *this)
{
  this->__vftable = (CMFCRibbonUndoButton_vtbl *)&CMFCRibbonUndoButton::`vftable';
  CStringArray::~CStringArray(this: &this->m_arLabels);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strUndoFmt.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strUndoOne.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strCancel.m_pszData - 1);
  CMFCRibbonGallery::~CMFCRibbonGallery(this);
}

//------------------------------------------------------------------------------
// Address: 0x10420F7C
// Name: protected: virtual void CMFCRibbonUndoButton::OnDrawPaletteIcon(class CDC __near *,class CRect,int,class CMFCRibbonGalleryIcon __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonUndoButton::OnDrawPaletteIcon(
        CMFCRibbonUndoButton *this,
        CDC *pDC,
        CRect rectIcon,
        int nIconIndex,
        CMFCRibbonGalleryIcon *pIcon,
        unsigned int clrText)
{
  int m_bIsChecked; // ecx
  CMFCRibbonGalleryIcon_vtbl *v8; // eax
  unsigned int v9; // edi
  int bIsChecked; // [esp+10h] [ebp-24h]
  int bIsHighlighted; // [esp+14h] [ebp-20h]
  CRect rectText; // [esp+20h] [ebp-14h] BYREF

  m_bIsChecked = pIcon->m_bIsChecked;
  pIcon->m_bIsChecked = 0;
  bIsChecked = m_bIsChecked;
  bIsHighlighted = pIcon->m_bIsHighlighted;
  v8 = pIcon->__vftable;
  pIcon->m_bIsHighlighted = nIconIndex < this->m_nActionNumber;
  v8->OnFillBackground(this: pIcon, a2: pDC);
  rectText = rectIcon;
  InflateRect(lprc: &rectText, dx: -5, dy: 0);
  v9 = -1;
  if ( clrText != -1 )
    v9 = pDC->SetTextColor(this: pDC, a2: clrText);
  if ( nIconIndex < 0 || nIconIndex >= this->m_arLabels.m_nSize )
    AfxThrowInvalidArgException();
  pDC->DrawTextA(
    this: pDC,
    a2: this->m_arLabels.m_pData[nIconIndex].m_pszData,
    a3: *((_DWORD *)this->m_arLabels.m_pData[nIconIndex].m_pszData - 3),
    a4: &rectText,
    a5: 36u);
  if ( clrText != -1 )
    pDC->SetTextColor(this: pDC, a2: v9);
  pIcon->OnDrawBorder(this: pIcon, a2: pDC);
  pIcon->m_bIsChecked = bIsChecked;
  pIcon->m_bIsHighlighted = bIsHighlighted;
}

//------------------------------------------------------------------------------
// Address: 0x10421067
// Name: protected: virtual void CMFCRibbonUndoButton::OnShowPopupMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonUndoButton::OnShowPopupMenu(CMFCRibbonUndoButton *this)
{
  CMFCRibbonBar *TopLevelRibbonBar; // ebx
  CFont *Font; // eax
  int v4; // ebx
  int cx; // eax
  int cy; // ecx
  CSize *TextExtent; // eax
  int v8; // ecx
  CSize *v9; // eax
  int v10; // ecx
  CSize *v11; // eax
  int v12; // ecx
  CFont *v13; // [esp-4h] [ebp-48h]
  CClientDC dc; // [esp+10h] [ebp-34h] BYREF
  CSize result; // [esp+24h] [ebp-20h] BYREF
  CSize szText; // [esp+2Ch] [ebp-18h] BYREF
  CFont *pOldFont; // [esp+34h] [ebp-10h]
  int v18; // [esp+40h] [ebp-4h]

  CMFCRibbonBaseElement::OnShowPopupMenu(this);
  this->m_bSmallIcons = 0;
  if ( CSize::operator==(this: &this->m_sizeMaxText, size: 0) != 0 )
  {
    TopLevelRibbonBar = CMFCRibbonBaseElement::GetTopLevelRibbonBar(this);
    CClientDC::CClientDC(this: &dc, pWnd: TopLevelRibbonBar);
    v18 = 0;
    Font = CWnd::GetFont(this: TopLevelRibbonBar);
    v4 = 0;
    for ( pOldFont = CDC::SelectObject(this: &dc, pFont: Font); v4 < this->m_arLabels.m_nSize; this->m_sizeMaxText.cy = cy )
    {
      if ( v4 < 0 || v4 >= this->m_arLabels.m_nSize )
        AfxThrowInvalidArgException();
      CDC::GetTextExtent(this: &dc, result: &szText, str: &this->m_arLabels.m_pData[v4]);
      cx = this->m_sizeMaxText.cx;
      if ( cx <= szText.cx )
        cx = szText.cx;
      cy = this->m_sizeMaxText.cy;
      this->m_sizeMaxText.cx = cx;
      if ( cy <= szText.cy )
        cy = szText.cy;
      ++v4;
    }
    TextExtent = CDC::GetTextExtent(this: &dc, result: &szText, str: &this->m_strCancel);
    v8 = this->m_sizeMaxText.cx;
    if ( v8 <= TextExtent->cx )
      v8 = CDC::GetTextExtent(this: &dc, &result, str: &this->m_strCancel)->cx;
    this->m_sizeMaxText.cx = v8;
    v9 = CDC::GetTextExtent(this: &dc, &result, str: &this->m_strUndoOne);
    v10 = this->m_sizeMaxText.cx;
    if ( v10 <= v9->cx )
      v10 = CDC::GetTextExtent(this: &dc, result: &szText, str: &this->m_strUndoOne)->cx;
    this->m_sizeMaxText.cx = v10;
    v11 = CDC::GetTextExtent(this: &dc, &result, str: &this->m_strUndoFmt);
    v12 = this->m_sizeMaxText.cx;
    if ( v12 <= v11->cx )
      v12 = CDC::GetTextExtent(this: &dc, result: &szText, str: &this->m_strUndoFmt)->cx;
    v13 = pOldFont;
    this->m_sizeMaxText.cx = v12 + 10;
    CDC::SelectObject(this: &dc, pFont: v13);
    v18 = -1;
    CClientDC::~CClientDC(this: &dc);
  }
  this->m_nActionNumber = -1;
  CMFCRibbonGallery::OnShowPopupMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x10421212
// Name: protected: void CMFCRibbonUndoButton::CommonInit(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonUndoButton::CommonInit(CMFCRibbonUndoButton *this)
{
  HINSTANCE__ *StringResourceHandle; // eax
  HINSTANCE__ *StringA; // eax
  HINSTANCE__ *v4; // eax
  CRibbonUndoLabel *v5; // ecx
  CRibbonUndoLabel *v6; // eax

  this->m_nActionNumber = -1;
  this->m_bIsButtonMode = 1;
  this->m_nIconsInRow = 1;
  this->m_bIsDefaultCommand = 1;
  this->m_sizeMaxText.cx = 0;
  this->m_sizeMaxText.cy = 0;
  StringResourceHandle = AfxFindStringResourceHandle(__formal: 0x42CDu);
  if ( StringResourceHandle != nullptr )
    StringResourceHandle = (HINSTANCE__ *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                                            this: &this->m_strCancel,
                                            hInstance: StringResourceHandle,
                                            nID: 0x42CDu);
  if ( StringResourceHandle == nullptr )
    goto LABEL_4;
  StringA = AfxFindStringResourceHandle(__formal: 0x42CFu);
  if ( StringA != nullptr )
    StringA = (HINSTANCE__ *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                               this: &this->m_strUndoOne,
                               hInstance: StringA,
                               nID: 0x42CFu);
  if ( StringA == nullptr )
    goto LABEL_4;
  v4 = AfxFindStringResourceHandle(__formal: 0x42CEu);
  if ( v4 != nullptr )
    v4 = (HINSTANCE__ *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                          this: &this->m_strUndoFmt,
                          hInstance: v4,
                          nID: 0x42CEu);
  if ( v4 == nullptr )
LABEL_4:
    AfxThrowInvalidArgException();
  v5 = (CRibbonUndoLabel *)operator new(nSize: 0x164u);
  if ( v5 != nullptr )
    v6 = CRibbonUndoLabel::CRibbonUndoLabel(this: v5, lpszText: this->m_strCancel.m_pszData);
  else
    v6 = nullptr;
  CMFCRibbonGallery::AddSubItem(this, pSubItem: v6, nIndex: -1, bOnTop: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10421309
// Name: public: CMFCRibbonUndoButton::CMFCRibbonUndoButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonUndoButton *__thiscall CMFCRibbonUndoButton::CMFCRibbonUndoButton(CMFCRibbonUndoButton *this)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v3; // eax
  CAfxStringMgr *v4; // eax

  CMFCRibbonGallery::CMFCRibbonGallery(this);
  this->__vftable = (CMFCRibbonUndoButton_vtbl *)&CMFCRibbonUndoButton::`vftable';
  this->m_sizeMaxText.cx = 0;
  this->m_sizeMaxText.cy = 0;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strCancel, pStringMgr: StringManager);
  v3 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strUndoOne, pStringMgr: v3);
  v4 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strUndoFmt, pStringMgr: v4);
  CStringArray::CStringArray(this: &this->m_arLabels);
  CMFCRibbonUndoButton::CommonInit(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10421393
// Name: protected: virtual void CMFCRibbonUndoButton::NotifyHighlightListItem(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonUndoButton::NotifyHighlightListItem(CMFCRibbonUndoButton *this, int nIndex)
{
  int m_nActionNumber; // eax
  CObject *v4; // eax
  CMFCRibbonPanel *v5; // ecx
  CMFCRibbonBaseElement *v6; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strLabel; // [esp+10h] [ebp-10h] BYREF
  int v8; // [esp+1Ch] [ebp-4h]

  if ( this->m_pPopupMenu != nullptr )
  {
    this->m_nActionNumber = nIndex + 1;
    strLabel.m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)this->m_strCancel.m_pszData - 1)[1];
    m_nActionNumber = this->m_nActionNumber;
    v8 = 0;
    if ( m_nActionNumber > 0 )
    {
      if ( m_nActionNumber == 1 )
        ATL::CSimpleStringT<char,0>::operator=(this: &strLabel, strSrc: (ATL::CStringData *)&this->m_strUndoOne);
      else
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
          this: &strLabel,
          pszFormat: this->m_strUndoFmt.m_pszData,
          m_nActionNumber);
    }
    v4 = AfxDynamicDownCast(pClass: &CMFCRibbonPanelMenu::classCMFCRibbonPanelMenu, pObject: this->m_pPopupMenu);
    if ( v4 != nullptr )
    {
      v5 = (CMFCRibbonPanel *)v4[1977].__vftable;
      if ( v5 != nullptr )
      {
        v6 = CMFCRibbonPanel::FindByID(this: v5, uiCmdID: 0);
        if ( v6 != nullptr )
        {
          v6->SetText(this: v6, a2: strLabel.m_pszData);
          v6->Redraw(this: v6);
        }
      }
    }
    CMFCRibbonGallery::RedrawIcons(this);
    v8 = -1;
    ATL::CStringData::Release(this: (ATL::CStringData *)strLabel.m_pszData - 1);
  }
  CMFCRibbonBaseElement::NotifyHighlightListItem(this, nIndex);
}

//------------------------------------------------------------------------------
// Address: 0x10421469
// Name: public: static class CObject __near * CMFCRibbonUndoButton::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonUndoButton *__stdcall CMFCRibbonUndoButton::CreateObject()
{
  CMFCRibbonUndoButton *v0; // ecx
  CMFCRibbonUndoButton *result; // eax

  v0 = (CMFCRibbonUndoButton *)operator new(nSize: 0x338u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCRibbonUndoButton::CMFCRibbonUndoButton(this: v0);
  return result;
}
