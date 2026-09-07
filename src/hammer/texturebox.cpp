// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/texturebox.cpp
// Functions: 13
// ============================================================

#include "hammer\texturebox.h"

//------------------------------------------------------------------------------
// Address: 0x100B5390
// Name: public: virtual CTextureBox::~CTextureBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBox::~CTextureBox(CTextureBox *this)
{
  this->__vftable = (CTextureBox_vtbl *)&CTextureBox::`vftable';
  CComboBox::~CComboBox(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B53D0
// Name: public: virtual void CTextureBox::DeleteItem(struct tagDELETEITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBox::DeleteItem(CTextureBox *this, CDC *lpDeleteItemStruct)
{
  CVSListBoxBase::OnAfterMoveItemUp((CMFCRibbonBaseElement *)this, __formal: lpDeleteItemStruct);
}

//------------------------------------------------------------------------------
// Address: 0x100B53E0
// Name: public: virtual void CTextureBox::MeasureItem(struct tagMEASUREITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBox::MeasureItem(CTextureBox *this, tagMEASUREITEMSTRUCT *lpMeasureItemStruct)
{
  _BYTE *itemData; // eax

  itemData = (_BYTE *)lpMeasureItemStruct->itemData;
  lpMeasureItemStruct->itemWidth = 64;
  if ( itemData != nullptr && *itemData != 0 )
    lpMeasureItemStruct->itemHeight = 72;
  else
    lpMeasureItemStruct->itemHeight = 9;
}

//------------------------------------------------------------------------------
// Address: 0x100B5410
// Name: public: CTextureBox::CTextureBox(void)
// Source: json
//------------------------------------------------------------------------------
CTextureBox *__thiscall CTextureBox::CTextureBox(CTextureBox *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CTextureBox_vtbl *)&CComboBox::`vftable';
  this->__vftable = (CTextureBox_vtbl *)&CTextureBox::`vftable';
  this->bFirstMeasure = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B54D0
// Name: public: void CTextureBox::NotifyNewMaterial(class IEditorTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBox::NotifyNewMaterial(CTextureBox *this, IEditorTexture *pTex)
{
  WPARAM v3; // eax
  char szStr[260]; // [esp+Ch] [ebp-104h] BYREF

  pTex->GetShortName(this: pTex, a2: szStr);
  v3 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)szStr);
  if ( v3 != -1 )
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x151u, wParam: v3, lParam: (LPARAM)pTex);
}

//------------------------------------------------------------------------------
// Address: 0x100B5530
// Name: public: virtual int CTextureBox::Create(unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureBox::Create(
        CTextureBox *this,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int nID)
{
  AFX_MODULE_STATE *ModuleState; // eax
  tagWNDCLASSA wndclass; // [esp+4h] [ebp-28h] BYREF

  if ( bInitClass != 0 )
  {
    bInitClass = 0;
    ModuleState = AfxGetModuleState();
    GetClassInfoA(hInstance: ModuleState->m_hCurrentInstanceHandle, lpClassName: "COMBOBOX", lpWndClass: &wndclass);
    wndclass.hbrBackground = nullptr;
    wndclass.lpszClassName = pszTextureBoxClass;
    AfxRegisterClass(lpWndClass: &wndclass);
  }
  return CWnd::Create(
           this,
           lpszClassName: pszTextureBoxClass,
           lpszWindowName: nullptr,
           dwStyle,
           rect,
           pParentWnd,
           nID,
           pContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100B55B0
// Name: protected: long CTextureBox::OnSelectString(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
WPARAM __thiscall CTextureBox::OnSelectString(CTextureBox *this, unsigned int wParam, const char *lParam)
{
  WPARAM v4; // esi
  LRESULT v5; // eax
  char szName[260]; // [esp+Ch] [ebp-108h] BYREF
  int nCount; // [esp+110h] [ebp-4h]

  v4 = wParam + 1;
  nCount = SendMessageA(hWnd: this->m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0);
  if ( (int)(wParam + 1) >= nCount )
    return -1;
  while ( 1 )
  {
    v5 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x150u, wParam: v4, lParam: 0);
    if ( v5 != 0 )
    {
      (*(void (__thiscall **)(LRESULT, char *))(*(_DWORD *)v5 + 36))(a1: v5, a2: szName);
      if ( _V_stricmp(s1: szName, s2: lParam) == 0 )
        break;
    }
    if ( (int)++v4 >= nCount )
      return -1;
  }
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Eu, wParam: v4, lParam: 0);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100B5650
// Name: protected: int CTextureBox::OnEraseBkgnd(class CDC __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureBox::OnEraseBkgnd(CTextureBox *this, CDC *pDC)
{
  HWND__ *m_hWnd; // ecx
  HBRUSH StockObject; // eax
  CRect r; // [esp+4h] [ebp-10h] BYREF

  m_hWnd = this->m_hWnd;
  memset(&r, 0, sizeof(r));
  GetUpdateRect(hWnd: m_hWnd, lpRect: &r, bErase: false);
  CDC::SetROP2(this: pDC, nDrawMode: 13);
  StockObject = (HBRUSH)GetStockObject(i: 4);
  FillRect(hDC: pDC->m_hDC, lprc: &r, hbr: StockObject);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B56B0
// Name: public: void CTextureBox::RebuildMRU(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBox::RebuildMRU(CTextureBox *this)
{
  LRESULT v2; // eax
  LRESULT v3; // eax
  signed int v4; // ebx
  signed int v5; // edx
  TextureContext_t *m_pActiveContext; // ecx
  int v7; // eax
  LPARAM v8; // ebx
  WPARAM v9; // eax
  WPARAM v10; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-130h]
  char szBuf[260]; // [esp+Ch] [ebp-114h] BYREF
  int nCurSel; // [esp+110h] [ebp-10h]
  int nMRU; // [esp+114h] [ebp-Ch]
  int nStrCount; // [esp+118h] [ebp-8h]
  int nMRUCount; // [esp+11Ch] [ebp-4h]

  SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  v2 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  m_hWnd = this->m_hWnd;
  nCurSel = v2;
  v3 = SendMessageA(hWnd: m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0);
  v4 = 0;
  nMRUCount = v3;
  if ( v3 > 0 )
  {
    do
    {
      if ( SendMessageA(hWnd: this->m_hWnd, Msg: 0x150u, wParam: v4, lParam: 0) == 0 )
        break;
      ++v4;
    }
    while ( v4 < nMRUCount );
    v3 = nMRUCount;
  }
  if ( v4 != v3 )
  {
    do
    {
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x144u, wParam: 0, lParam: 0);
      v5 = v4--;
    }
    while ( v5 != 0 );
  }
  m_pActiveContext = g_Textures.m_pActiveContext;
  v7 = 0;
  nStrCount = 0;
  if ( g_Textures.m_pActiveContext != nullptr )
    nMRUCount = g_Textures.m_pActiveContext->MRU.m_Size;
  else
    nMRUCount = 0;
  nMRU = 0;
  if ( nMRUCount > 0 )
  {
    do
    {
      if ( m_pActiveContext != nullptr )
      {
        v8 = (LPARAM)m_pActiveContext->MRU.m_Memory.m_pMemory[v7];
        if ( v8 != 0 )
        {
          (*(void (__thiscall **)(LPARAM, char *))(*(_DWORD *)v8 + 36))(a1: v8, a2: szBuf);
          v9 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Au, wParam: nStrCount, lParam: (LPARAM)szBuf);
          SendMessageA(hWnd: this->m_hWnd, Msg: 0x151u, wParam: v9, lParam: v8);
          ++nStrCount;
          m_pActiveContext = g_Textures.m_pActiveContext;
          v7 = nMRU;
        }
      }
      nMRU = ++v7;
    }
    while ( v7 < nMRUCount );
    if ( nStrCount > 0 )
    {
      v10 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Au, wParam: nStrCount, lParam: (LPARAM)&var);
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x151u, wParam: v10, lParam: 0);
    }
  }
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Eu, wParam: nCurSel, lParam: 0);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
  InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x100B5810
// Name: public: void CTextureBox::LoadGraphicList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBox::LoadGraphicList(CTextureBox *this)
{
  int m_Size; // eax
  TextureContext_t *m_pActiveContext; // ecx
  int v4; // eax
  IEditorTexture *v5; // edi
  int v6; // edi
  int v7; // edi
  IEditorTexture *i; // edi
  int v9; // edi
  WPARAM v10; // edi
  LRESULT v11; // eax
  int v12; // eax
  LPARAM v13; // [esp-Ch] [ebp-124h]
  LPARAM v14; // [esp-Ch] [ebp-124h]
  TEXTUREFORMAT textureformat; // [esp-Ch] [ebp-124h]
  char szName[260]; // [esp+4h] [ebp-114h] BYREF
  int nIndex; // [esp+108h] [ebp-10h] BYREF
  int nMRUCount; // [esp+10Ch] [ebp-Ch]
  int nMRU; // [esp+110h] [ebp-8h]
  int nStrCount; // [esp+114h] [ebp-4h]

  if ( g_pGameConfig->textureformat != tfNone )
  {
    SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Bu, wParam: 0, lParam: 0);
    if ( g_Textures.m_pActiveGroup != nullptr )
      m_Size = g_Textures.m_pActiveGroup->m_Textures.m_Size;
    else
      m_Size = 0;
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x161u, wParam: m_Size + 32, lParam: 4);
    m_pActiveContext = g_Textures.m_pActiveContext;
    nStrCount = 0;
    if ( g_Textures.m_pActiveContext != nullptr )
      nMRUCount = g_Textures.m_pActiveContext->MRU.m_Size;
    else
      nMRUCount = 0;
    v4 = 0;
    nMRU = 0;
    if ( nMRUCount > 0 )
    {
      do
      {
        if ( m_pActiveContext != nullptr )
        {
          v5 = m_pActiveContext->MRU.m_Memory.m_pMemory[v4];
          if ( v5 != nullptr )
          {
            v5->GetShortName(this: v5, a2: szName);
            SendMessageA(hWnd: this->m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)szName);
            v13 = (LPARAM)v5;
            v6 = nStrCount;
            SendMessageA(hWnd: this->m_hWnd, Msg: 0x151u, wParam: nStrCount, lParam: v13);
            m_pActiveContext = g_Textures.m_pActiveContext;
            v4 = nMRU;
            nStrCount = v6 + 1;
          }
        }
        nMRU = ++v4;
      }
      while ( v4 < nMRUCount );
      if ( nStrCount > 0 )
      {
        SendMessageA(hWnd: this->m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)&var);
        v7 = nStrCount;
        SendMessageA(hWnd: this->m_hWnd, Msg: 0x151u, wParam: nStrCount, lParam: 0);
        nStrCount = v7 + 1;
      }
    }
    nIndex = 0;
    for ( i = CTextureSystem::EnumActiveTextures(
                this: &g_Textures,
                piIndex: &nIndex,
                eDesiredFormat: g_pGameConfig->textureformat);
          i != nullptr;
          i = CTextureSystem::EnumActiveTextures(this: &g_Textures, piIndex: &nIndex, eDesiredFormat: textureformat) )
    {
      i->GetShortName(this: i, a2: szName);
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)szName);
      v14 = (LPARAM)i;
      v9 = nStrCount;
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x151u, wParam: nStrCount, lParam: v14);
      textureformat = g_pGameConfig->textureformat;
      nStrCount = v9 + 1;
    }
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
    v10 = 0;
    nMRU = SendMessageA(hWnd: this->m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0);
    if ( nMRU > 0 )
    {
      while ( 1 )
      {
        v11 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x150u, wParam: v10, lParam: 0);
        if ( v11 != 0 )
        {
          (*(void (__thiscall **)(LRESULT, char *))(*(_DWORD *)v11 + 36))(a1: v11, a2: szName);
          if ( szName[0] != 0 && szName[0] != 42 && szName[0] != 43 && szName[0] != 33 )
          {
            strstr(str1: (unsigned __int8 *)szName, str2: "door");
            if ( v12 == 0 )
              break;
          }
        }
        if ( (int)++v10 >= nMRU )
          goto LABEL_27;
      }
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Eu, wParam: v10, lParam: 0);
    }
LABEL_27:
    SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B5A60
// Name: protected: virtual struct AFX_MSGMAP const __near * CTextureBox::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CTextureBox::GetMessageMap(CTextureBox *this)
{
  return (const AFX_MSGMAP *)&off_105E6FF8;
}

//------------------------------------------------------------------------------
// Address: 0x100B5A70
// Name: public: void CTextureBox::AddMRU(class IEditorTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBox::AddMRU(CTextureBox *this, IEditorTexture *pTex)
{
  if ( pTex != nullptr )
  {
    CTextureSystem::AddMRU(this: &g_Textures, pTex);
    CTextureBox::RebuildMRU(this);
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B5AC0
// Name: public: virtual void CTextureBox::DrawItem(struct tagDRAWITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBox::DrawItem(CTextureBox *this, tagDRAWITEMSTRUCT *lpDrawItemStruct)
{
  tagRECT *p_rcItem; // edi
  WPARAM itemID; // eax
  LRESULT v5; // esi
  COLORREF SysColor; // ebx
  CPalette *p_GDIPalette; // eax
  COLORREF v8; // eax
  HBRUSH SolidBrush; // eax
  void (__thiscall *v10)(LRESULT, CDC *, CRect *, _DWORD, _DWORD, DrawTexData_t *); // edx
  int v11; // eax
  int v12; // eax
  int v13; // [esp-4h] [ebp-15Ch]
  char szName[260]; // [esp+Ch] [ebp-14Ch] BYREF
  DrawTexData_t DrawTexData; // [esp+110h] [ebp-48h] BYREF
  tagSIZE psizl; // [esp+118h] [ebp-40h] BYREF
  CRect r2; // [esp+120h] [ebp-38h] BYREF
  CPalette *pOldPalette; // [esp+130h] [ebp-28h]
  CBrush brush; // [esp+134h] [ebp-24h] BYREF
  CDC dc; // [esp+13Ch] [ebp-1Ch] BYREF
  int v21; // [esp+154h] [ebp-4h]
  DWORD iLena; // [esp+160h] [ebp+8h]
  int iLen; // [esp+160h] [ebp+8h]

  CDC::CDC(this: &dc);
  v21 = 0;
  CDC::Attach(this: &dc, hDC: lpDrawItemStruct->hDC);
  CDC::SaveDC(this: &dc);
  p_rcItem = &lpDrawItemStruct->rcItem;
  GetTextExtentPoint32A(hdc: dc.m_hAttribDC, lpString: "J", c: 1, &psizl);
  itemID = lpDrawItemStruct->itemID;
  if ( itemID == -1 )
  {
    if ( (lpDrawItemStruct->itemState & 0x10) != 0 )
      DrawFocusRect(hDC: dc.m_hDC, lprc: &lpDrawItemStruct->rcItem);
  }
  else
  {
    v5 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x150u, wParam: itemID, lParam: 0);
    CDC::SetROP2(this: &dc, nDrawMode: 13);
    SysColor = 0;
    pOldPalette = nullptr;
    if ( v5 != 0 )
    {
      (*(void (__thiscall **)(LRESULT))(*(_DWORD *)v5 + 76))(a1: v5);
      if ( (*(unsigned __int8 (__thiscall **)(LRESULT))(*(_DWORD *)v5 + 72))(a1: v5) != 0 )
        p_GDIPalette = (CPalette *)(*(int (__thiscall **)(LRESULT))(*(_DWORD *)v5 + 64))(a1: v5);
      else
        p_GDIPalette = &g_pGameConfig->Palette.GDIPalette;
      pOldPalette = CDC::SelectPalette(this: &dc, pPalette: p_GDIPalette, bForceBackground: false);
      RealizePalette(hdc: dc.m_hDC);
    }
    v8 = 0xFFFFFF;
    if ( (lpDrawItemStruct->itemState & 1) != 0 )
    {
      iLena = GetSysColor(nIndex: 13);
      SysColor = GetSysColor(nIndex: 14);
      v8 = iLena;
    }
    brush.m_hObject = nullptr;
    brush.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
    LOBYTE(v21) = 2;
    SolidBrush = CreateSolidBrush(color: v8);
    CGdiObject::Attach(this: &brush, hObject: SolidBrush);
    FillRect(hDC: dc.m_hDC, lprc: p_rcItem, hbr: (HBRUSH)brush.m_hObject);
    if ( v5 != 0 )
    {
      iLen = (*(int (__thiscall **)(LRESULT, char *))(*(_DWORD *)v5 + 36))(a1: v5, a2: szName);
      if ( p_rcItem->bottom - p_rcItem->top <= 32 )
      {
        CDC::SetTextColor(this: &dc, crColor: SysColor);
        CDC::SetBkMode(this: &dc, nBkMode: 1);
        TextOutA(hdc: dc.m_hDC, x: p_rcItem->left + 4, y: p_rcItem->top + 2, lpString: szName, c: iLen);
      }
      else
      {
        DrawTexData.nFlags = 0;
        CopyRect(lprcDst: &r2, lprcSrc: p_rcItem);
        InflateRect(lprc: &r2, dx: -4, dy: -4);
        v10 = *(void (__thiscall **)(LRESULT, CDC *, CRect *, _DWORD, _DWORD, DrawTexData_t *))(*(_DWORD *)v5 + 44);
        r2.right = r2.left + 64;
        v10(a1: v5, a2: &dc, a3: &r2, a4: 0, a5: 0, a6: &DrawTexData);
        CDC::SetTextColor(this: &dc, crColor: SysColor);
        CDC::SetBkMode(this: &dc, nBkMode: 1);
        TextOutA(hdc: dc.m_hDC, x: r2.right + 4, y: r2.top + 4, lpString: szName, c: iLen);
        v11 = (*(int (__thiscall **)(LRESULT))(*(_DWORD *)v5 + 16))(a1: v5);
        v12 = (*(int (__thiscall **)(LRESULT, int))(*(_DWORD *)v5 + 12))(a1: v5, a2: v11);
        sprintf(string: szName, format: "%dx%d", v12, v13);
        TextOutA(hdc: dc.m_hDC, x: r2.right + 4, y: psizl.cy + r2.top + 4, lpString: szName, c: strlen(szName));
      }
    }
    else
    {
      CDC::SelectStockObject(this: &dc, nIndex: 7);
      CDC::MoveTo(this: &dc, result: (CPoint *)&psizl, x: p_rcItem->left, y: p_rcItem->top + 5);
      CDC::LineTo(this: &dc, x: p_rcItem->right, y: p_rcItem->top + 5);
    }
    if ( pOldPalette != nullptr )
      CDC::SelectPalette(this: &dc, pPalette: pOldPalette, bForceBackground: false);
    brush.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
    LOBYTE(v21) = 0;
    CGdiObject::~CGdiObject(this: &brush);
  }
  CDC::RestoreDC(this: &dc, nSavedDC: -1);
  CDC::Detach(this: &dc);
  v21 = -1;
  CDC::~CDC(this: &dc);
}
