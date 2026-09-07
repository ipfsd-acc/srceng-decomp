// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/texturewindow.cpp
// Functions: 24
// ============================================================

#include "hammer\texturewindow.h"

//------------------------------------------------------------------------------
// Address: 0x100B6A90
// Name: public: void CTextureWindow::EnableUpdate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureWindow::EnableUpdate(CTextureWindow *this, bool bEnable)
{
  this->m_bEnableUpdate = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100B6AA0
// Name: public: void CTextureWindow::SetTextureFormat(enum TEXTUREFORMAT)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureWindow::SetTextureFormat(CTextureWindow *this, TEXTUREFORMAT eTextureFormat)
{
  this->m_eTextureFormat = eTextureFormat;
}

//------------------------------------------------------------------------------
// Address: 0x100B6AB0
// Name: public: virtual int CDC::RectVisible(struct tagRECT const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDC::RectVisible(CDC *this, const tagRECT *lpRect)
{
  return RectVisible(hdc: this->m_hDC, lprect: lpRect);
}

//------------------------------------------------------------------------------
// Address: 0x100B6AD0
// Name: protected: void CTextureWindow::OnHScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureWindow::OnHScroll(
        CTextureWindow *this,
        unsigned int nSBCode,
        unsigned int nPos,
        CScrollBar *pScrollBar)
{
  unsigned int v4; // esi
  int ScrollPos; // ebx
  int ScrollLimit; // eax
  unsigned int v8; // ecx
  tagSCROLLINFO ScrollInfo; // [esp+Ch] [ebp-1Ch] BYREF

  v4 = nPos;
  CWnd::GetScrollInfo(this, nBar: 0, lpScrollInfo: &ScrollInfo, nMask: 0x17u);
  ScrollPos = CWnd::GetScrollPos(this, nBar: 0);
  ScrollLimit = CWnd::GetScrollLimit(this, nBar: 0);
  v8 = nSBCode;
  switch ( nSBCode )
  {
    case 0u:
      v4 = -(ScrollInfo.nPage >> 2);
      break;
    case 1u:
      v4 = ScrollInfo.nPage >> 2;
      break;
    case 2u:
      v4 = -(ScrollInfo.nPage >> 1);
      break;
    case 3u:
      v4 = ScrollInfo.nPage >> 1;
      break;
    case 4u:
    case 5u:
      v4 = nPos - ScrollPos;
      break;
    default:
      break;
  }
  if ( (int)(ScrollPos + v4) < 0 )
    v4 = -ScrollPos;
  if ( (int)(ScrollPos + v4) > ScrollLimit )
    v4 = ScrollLimit - ScrollPos;
  if ( v4 != 0 )
  {
    CWnd::SetScrollPos(this, nBar: 0, nPos: v4 + ScrollPos, bRedraw: 1);
    CWnd::ScrollWindow(this, xAmount: -v4, yAmount: 0, lpRect: nullptr, lpClipRect: nullptr);
    UpdateWindow(hWnd: this->m_hWnd);
    v8 = nSBCode;
  }
  CWnd::OnHScroll(this, __formal: v8, __formal: nPos, pScrollBar);
}

//------------------------------------------------------------------------------
// Address: 0x100B6BB0
// Name: protected: void CTextureWindow::OnVScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureWindow::OnVScroll(
        CTextureWindow *this,
        unsigned int nSBCode,
        unsigned int nPos,
        CScrollBar *pScrollBar)
{
  int ScrollPos; // ebx
  int ScrollLimit; // eax
  unsigned int v7; // ecx
  int v8; // esi
  tagSCROLLINFO ScrollInfo; // [esp+Ch] [ebp-1Ch] BYREF

  CWnd::GetScrollInfo(this, nBar: 1, lpScrollInfo: &ScrollInfo, nMask: 0x17u);
  ScrollPos = CWnd::GetScrollPos(this, nBar: 1);
  ScrollLimit = CWnd::GetScrollLimit(this, nBar: 1);
  v7 = nSBCode;
  v8 = ScrollInfo.nPos;
  switch ( nSBCode )
  {
    case 0u:
      v8 = -(ScrollInfo.nPage >> 2);
      break;
    case 1u:
      v8 = ScrollInfo.nPage >> 2;
      break;
    case 2u:
      v8 = -(ScrollInfo.nPage >> 1);
      break;
    case 3u:
      v8 = ScrollInfo.nPage >> 1;
      break;
    case 4u:
    case 5u:
      v8 = ScrollInfo.nTrackPos - ScrollPos;
      break;
    case 8u:
      v8 = 0;
      break;
    default:
      break;
  }
  if ( v8 + ScrollPos < 0 )
    v8 = -ScrollPos;
  if ( v8 + ScrollPos > ScrollLimit )
    v8 = ScrollLimit - ScrollPos;
  if ( v8 != 0 )
  {
    CWnd::SetScrollPos(this, nBar: 1, nPos: v8 + ScrollPos, bRedraw: 1);
    CWnd::ScrollWindow(this, xAmount: 0, yAmount: -v8, lpRect: nullptr, lpClipRect: nullptr);
    UpdateWindow(hWnd: this->m_hWnd);
    v7 = nSBCode;
  }
  CWnd::OnHScroll(this, __formal: v7, __formal: nPos, pScrollBar);
}

//------------------------------------------------------------------------------
// Address: 0x100B6CA0
// Name: public: void CTextureWindow::HighlightCurTexture(class CDC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureWindow::HighlightCurTexture(CTextureWindow *this, CDC *pDC)
{
  int v3; // ebx
  CDC *p_dc; // edi
  HDC v5; // eax
  int v6; // eax
  HDC v7; // eax
  int ScrollPos; // [esp-8h] [ebp-34h]
  CDC dc; // [esp+8h] [ebp-24h] BYREF
  CPoint result; // [esp+18h] [ebp-14h] BYREF
  int v11; // [esp+28h] [ebp-4h]

  CDC::CDC(this: &dc);
  v3 = 0;
  v11 = 0;
  if ( this->rectHighlight.left >= 0 )
  {
    p_dc = pDC;
    if ( pDC == nullptr )
    {
      v5 = GetDC(hWnd: this->m_hWnd);
      CDC::Attach(this: &dc, hDC: v5);
      ScrollPos = CWnd::GetScrollPos(this, nBar: 1);
      v6 = CWnd::GetScrollPos(this, nBar: 0);
      CDC::SetWindowOrg(this: &dc, &result, x: v6, y: ScrollPos);
      v3 = 1;
      p_dc = &dc;
    }
    p_dc->SelectStockObject(this: p_dc, a2: 6);
    p_dc->SelectStockObject(this: p_dc, a2: 5);
    CDC::SetROP2(this: p_dc, nDrawMode: 7);
    Rectangle(
      hdc: p_dc->m_hDC,
      left: this->rectHighlight.left,
      top: this->rectHighlight.top,
      right: this->rectHighlight.right,
      bottom: this->rectHighlight.bottom);
    if ( v3 != 0 )
    {
      v7 = CDC::Detach(this: &dc);
      ReleaseDC(hWnd: this->m_hWnd, hDC: v7);
    }
  }
  v11 = -1;
  CDC::~CDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x100B6DA0
// Name: protected: void CTextureWindow::OnLButtonDblClk(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureWindow::OnLButtonDblClk(CTextureWindow *this, unsigned int nFlags, CPoint point)
{
  HWND Parent; // eax
  CWnd *v5; // eax

  Parent = GetParent(hWnd: this->m_hWnd);
  v5 = CWnd::FromHandle(hWnd: Parent);
  PostMessageA(hWnd: v5->m_hWnd, Msg: 0x407u, wParam: 0, lParam: 0);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B6DF0
// Name: protected: int CTextureWindow::OnMouseWheel(unsigned int,short,class CPoint)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureWindow::OnMouseWheel(CTextureWindow *this, unsigned int nFlags, __int16 zDelta, CPoint point)
{
  int ScrollPos; // ebx
  int ScrollLimit; // eax
  int v7; // esi
  tagSCROLLINFO ScrollInfo; // [esp+Ch] [ebp-1Ch] BYREF

  CWnd::GetScrollInfo(this, nBar: 1, lpScrollInfo: &ScrollInfo, nMask: 0x17u);
  ScrollPos = CWnd::GetScrollPos(this, nBar: 1);
  ScrollLimit = CWnd::GetScrollLimit(this, nBar: 1);
  if ( zDelta > 0 )
    v7 = (signed int)ScrollInfo.nPage / -4;
  else
    v7 = ScrollInfo.nPage >> 2;
  if ( v7 + ScrollPos < 0 )
    v7 = -ScrollPos;
  if ( v7 + ScrollPos > ScrollLimit )
    v7 = ScrollLimit - ScrollPos;
  if ( v7 != 0 )
  {
    CWnd::SetScrollPos(this, nBar: 1, nPos: v7 + ScrollPos, bRedraw: 1);
    CWnd::ScrollWindow(this, xAmount: 0, yAmount: -v7, lpRect: nullptr, lpClipRect: nullptr);
    UpdateWindow(hWnd: this->m_hWnd);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B6EB0
// Name: public: int CTextureWindow::EnumTexturePositions(struct CTextureWindow::TWENUMPOS __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureWindow::EnumTexturePositions(CTextureWindow *this, CTextureWindow::TWENUMPOS *pTE, int bStart)
{
  CTextureWindow *v4; // edi
  IEditorTexture *v5; // eax
  TextureWindowTexList *m_pSpecificList; // ebx
  int m_Size; // edi
  int v8; // edx
  IEditorTexture **p_pTex; // ecx
  int m_nFilters; // edi
  int v11; // ebx
  CTextureWindow *v12; // edi
  int m_nKeywords; // ebx
  int v14; // edi
  IMaterial *v15; // eax
  IMaterial *v16; // edi
  bool v17; // al
  CTextureWindow *v18; // ebx
  int v19; // edx
  CTextureWindow *v20; // eax
  int bottom; // ecx
  char szTemp[260]; // [esp+Ch] [ebp-108h] BYREF
  CTextureWindow *v24; // [esp+110h] [ebp-4h]
  bool bFound_3; // [esp+11Fh] [ebp+Bh]
  const char **bStarta; // [esp+120h] [ebp+Ch]
  const char **bStartb; // [esp+120h] [ebp+Ch]

  v4 = this;
  v24 = this;
  if ( bStart != 0 )
  {
    pTE->cur_x = 4;
    pTE->cur_y = 4;
    pTE->largest_y = 0;
    pTE->iTexIndex = 0;
    if ( IsWindow(hWnd: this->m_hWnd) )
      GetClientRect(hWnd: v4->m_hWnd, lpRect: &pTE->clientrect);
    SetRect(lprc: &pTE->texrect, xLeft: 0, yTop: 0, xRight: 0, yBottom: 0);
  }
  bFound_3 = false;
  while ( 1 )
  {
    v5 = CTextureSystem::EnumActiveTextures(
           this: &g_Textures,
           piIndex: &pTE->iTexIndex,
           eDesiredFormat: v4->m_eTextureFormat);
    pTE->pTex = v5;
    if ( v5 == nullptr )
      break;
    m_pSpecificList = v4->m_pSpecificList;
    bFound_3 = false;
    if ( m_pSpecificList != nullptr )
    {
      m_Size = m_pSpecificList->m_Size;
      v8 = 0;
      if ( m_Size <= 0 )
        goto LABEL_44;
      p_pTex = &m_pSpecificList->m_Memory.m_pMemory->pTex;
      while ( *p_pTex != v5 )
      {
        ++v8;
        p_pTex += 2;
        if ( v8 >= m_Size )
          goto LABEL_44;
      }
      if ( v8 == -1 )
        goto LABEL_44;
      v4 = v24;
      pTE->nUsageCount = m_pSpecificList->m_Memory.m_pMemory[v8].nUsageCount;
    }
    v5->GetShortName(this: v5, a2: szTemp);
    m_nFilters = v4->m_nFilters;
    if ( m_nFilters != 0 )
    {
      v11 = 0;
      if ( m_nFilters > 0 )
      {
        bStarta = (const char **)v24->m_Filters;
        while ( V_stristr(pStr: szTemp, pSearch: *bStarta) != nullptr )
        {
          ++bStarta;
          if ( ++v11 >= m_nFilters )
            goto LABEL_20;
        }
        goto LABEL_44;
      }
    }
LABEL_20:
    v12 = v24;
    if ( v24->m_nKeywords != 0 )
    {
      pTE->pTex->GetKeywords(this: pTE->pTex, a2: szTemp);
      m_nKeywords = v12->m_nKeywords;
      if ( m_nKeywords != 0 )
      {
        v14 = 0;
        if ( m_nKeywords > 0 )
        {
          bStartb = (const char **)v24->m_Keyword;
          while ( V_stristr(pStr: szTemp, pSearch: *bStartb) != nullptr )
          {
            ++bStartb;
            if ( ++v14 >= m_nKeywords )
              goto LABEL_26;
          }
          goto LABEL_44;
        }
      }
LABEL_26:
      v12 = v24;
    }
    bFound_3 = true;
    if ( (v12->m_nTypeFilter & 0xF) == 0xF )
      goto LABEL_40;
    v15 = pTE->pTex->GetMaterial(this: pTE->pTex, a2: 1);
    v16 = v15;
    if ( v15 == nullptr )
      goto LABEL_40;
    bFound_3 = false;
    v17 = v15->GetMaterialVarFlag(this: v15, a2: MATERIAL_VAR_SELFILLUM);
    v18 = v24;
    if ( v17 )
      bFound_3 = (v24->m_nTypeFilter & 4) != 0;
    if ( v16->GetMaterialVarFlag(this: v16, a2: MATERIAL_VAR_BASEALPHAENVMAPMASK) && (v18->m_nTypeFilter & 8) != 0 )
      bFound_3 = true;
    if ( v16->GetMaterialVarFlag(this: v16, a2: MATERIAL_VAR_TRANSLUCENT) )
    {
      if ( (v18->m_nTypeFilter & 2) != 0 )
      {
        bFound_3 = true;
LABEL_40:
        if ( pTE->pTex->IsLoaded(this: pTE->pTex)
          && (pTE->pTex->GetWidth(this: pTE->pTex) == 0 || pTE->pTex->GetHeight(this: pTE->pTex) == 0) )
        {
          bFound_3 = false;
        }
        goto LABEL_44;
      }
    }
    else if ( (v18->m_nTypeFilter & 1) != 0 )
    {
      bFound_3 = true;
      goto LABEL_40;
    }
    if ( bFound_3 )
      goto LABEL_40;
LABEL_44:
    v4 = v24;
    if ( pTE->pTex == nullptr )
      break;
    if ( bFound_3 )
      goto LABEL_48;
  }
  if ( !bFound_3 )
    return 0;
LABEL_48:
  if ( pTE->pTex == nullptr )
    return 0;
  SetRect(
    lprc: &pTE->texrect,
    xLeft: pTE->cur_x,
    yTop: pTE->cur_y,
    xRight: pTE->cur_x + v4->iDisplaySize,
    yBottom: pTE->cur_y + v4->iDisplaySize);
  while ( pTE->cur_x > 4 )
  {
    if ( pTE->texrect.right <= pTE->clientrect.right )
      break;
    v19 = pTE->largest_y + 4;
    pTE->cur_x = 4;
    v20 = v24;
    pTE->cur_y = v19;
    SetRect(
      lprc: &pTE->texrect,
      xLeft: pTE->cur_x,
      yTop: v19,
      xRight: pTE->cur_x + v20->iDisplaySize,
      yBottom: v19 + v20->iDisplaySize);
  }
  pTE->texrect.bottom += 27;
  bottom = pTE->texrect.bottom;
  if ( bottom > pTE->largest_y )
    pTE->largest_y = bottom;
  pTE->cur_x = pTE->texrect.right + 4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B71B0
// Name: public: void CTextureWindow::UpdateScrollSizes(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTextureWindow::UpdateScrollSizes(CTextureWindow *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  CTextureWindow *v3; // ebx
  int bottom; // eax
  int right; // ecx
  IEditorTexture *pTex; // eax
  TextureWindowTexList *m_pSpecificList; // ecx
  int m_Size; // edi
  int v9; // edx
  IEditorTexture **p_pTex; // esi
  int m_nFilters; // edi
  int v12; // esi
  int m_nKeywords; // edi
  int v14; // esi
  const char **m_Keyword; // ebx
  int v16; // edx
  IMaterial *v17; // esi
  bool (__thiscall *GetMaterialVarFlag)(IMaterial *, MaterialVarFlags_t); // edx
  int iDisplaySize; // ecx
  char szbuf[100]; // [esp+4h] [ebp-1C8h] BYREF
  char pStr[260]; // [esp+68h] [ebp-164h] BYREF
  tagSCROLLINFO ScrollInfo; // [esp+16Ch] [ebp-60h] BYREF
  CTextureWindow::TWENUMPOS TE; // [esp+188h] [ebp-44h] BYREF
  CTextureWindow *v26; // [esp+1C0h] [ebp-Ch]
  const char **m_Filters; // [esp+1C4h] [ebp-8h]
  char v28; // [esp+1CBh] [ebp-1h]

  v3 = this;
  v26 = this;
  this->total_y = 0;
  this->total_x = 0;
  if ( CTextureWindow::EnumTexturePositions(this, pTE: &TE, bStart: 1) == 0 )
    goto LABEL_61;
  bottom = TE.texrect.bottom;
  right = TE.texrect.right;
  while ( 2 )
  {
    if ( right > v3->total_x )
      v3->total_x = right;
    if ( bottom > v3->total_y )
      v3->total_y = bottom;
    v28 = 0;
    while ( 1 )
    {
      pTex = CTextureSystem::EnumActiveTextures(
               this: &g_Textures,
               piIndex: &TE.iTexIndex,
               eDesiredFormat: v3->m_eTextureFormat);
      TE.pTex = pTex;
      if ( pTex == nullptr )
        break;
      m_pSpecificList = v3->m_pSpecificList;
      v28 = 0;
      if ( m_pSpecificList == nullptr )
        goto LABEL_17;
      m_Size = m_pSpecificList->m_Size;
      v9 = 0;
      if ( m_Size > 0 )
      {
        p_pTex = &m_pSpecificList->m_Memory.m_pMemory->pTex;
        while ( *p_pTex != pTex )
        {
          ++v9;
          p_pTex += 2;
          if ( v9 >= m_Size )
            goto LABEL_49;
        }
        if ( v9 != -1 )
        {
          TE.nUsageCount = m_pSpecificList->m_Memory.m_pMemory[v9].nUsageCount;
LABEL_17:
          pTex->GetShortName(this: pTex, a2: pStr);
          m_nFilters = v3->m_nFilters;
          if ( m_nFilters != 0 )
          {
            v12 = 0;
            if ( m_nFilters > 0 )
            {
              m_Filters = (const char **)v3->m_Filters;
              while ( V_stristr(pStr, pSearch: *m_Filters) != nullptr )
              {
                ++m_Filters;
                if ( ++v12 >= m_nFilters )
                  goto LABEL_22;
              }
              goto LABEL_48;
            }
          }
LABEL_22:
          if ( v3->m_nKeywords != 0 )
          {
            TE.pTex->GetKeywords(this: TE.pTex, a2: pStr);
            m_nKeywords = v3->m_nKeywords;
            if ( m_nKeywords != 0 )
            {
              v14 = 0;
              if ( m_nKeywords > 0 )
              {
                m_Keyword = (const char **)v3->m_Keyword;
                while ( V_stristr(pStr, pSearch: *m_Keyword) != nullptr )
                {
                  ++v14;
                  ++m_Keyword;
                  if ( v14 >= m_nKeywords )
                  {
                    v3 = v26;
                    goto LABEL_29;
                  }
                }
                v3 = v26;
                goto LABEL_48;
              }
            }
          }
LABEL_29:
          v16 = v3->m_nTypeFilter & 0xF;
          v28 = 1;
          if ( (_BYTE)v16 == 15 )
            goto LABEL_43;
          v17 = TE.pTex->GetMaterial(this: TE.pTex, a2: 1);
          if ( v17 == nullptr )
            goto LABEL_43;
          GetMaterialVarFlag = v17->GetMaterialVarFlag;
          v28 = 0;
          if ( ((unsigned __int8 (__thiscall *)(IMaterial *, int, int, int))GetMaterialVarFlag)(
                 a1: v17,
                 a2: 64,
                 a3: a2,
                 a4: a3) != 0
            && (v3->m_nTypeFilter & 4) != 0 )
          {
            v28 = 1;
          }
          a3 = 0x100000;
          if ( ((unsigned __int8 (__thiscall *)(IMaterial *))v17->GetMaterialVarFlag)(a1: v17) != 0
            && (v3->m_nTypeFilter & 8) != 0 )
          {
            v28 = 1;
          }
          a2 = 0x200000;
          if ( ((unsigned __int8 (__thiscall *)(IMaterial *))v17->GetMaterialVarFlag)(a1: v17) != 0 )
          {
            if ( (v3->m_nTypeFilter & 2) != 0 )
            {
              v28 = 1;
              goto LABEL_43;
            }
LABEL_42:
            if ( v28 != 0 )
              goto LABEL_43;
          }
          else
          {
            if ( (v3->m_nTypeFilter & 1) == 0 )
              goto LABEL_42;
            v28 = 1;
LABEL_43:
            if ( TE.pTex->IsLoaded(this: TE.pTex)
              && (TE.pTex->GetWidth(this: TE.pTex) == 0 || TE.pTex->GetHeight(this: TE.pTex) == 0) )
            {
              v28 = 0;
            }
          }
LABEL_48:
          pTex = TE.pTex;
        }
      }
LABEL_49:
      if ( pTex == nullptr )
        break;
      if ( v28 != 0 )
        goto LABEL_53;
    }
    if ( v28 == 0 )
      break;
LABEL_53:
    if ( pTex != nullptr )
    {
      SetRect(
        lprc: &TE.texrect,
        xLeft: TE.cur_x,
        yTop: TE.cur_y,
        xRight: TE.cur_x + v3->iDisplaySize,
        yBottom: v3->iDisplaySize + TE.cur_y);
      if ( TE.cur_x <= 4 )
      {
LABEL_57:
        right = TE.texrect.right;
      }
      else
      {
        while ( 1 )
        {
          right = TE.texrect.right;
          if ( TE.texrect.right <= TE.clientrect.right )
            break;
          iDisplaySize = v3->iDisplaySize;
          TE.cur_y = TE.largest_y + 4;
          TE.cur_x = 4;
          SetRect(
            lprc: &TE.texrect,
            xLeft: 4,
            yTop: TE.largest_y + 4,
            xRight: iDisplaySize + 4,
            yBottom: iDisplaySize + TE.largest_y + 4);
          if ( TE.cur_x <= 4 )
            goto LABEL_57;
        }
      }
      bottom = TE.texrect.bottom + 27;
      TE.texrect.bottom = bottom;
      if ( bottom > TE.largest_y )
        TE.largest_y = bottom;
      TE.cur_x = right + 4;
      continue;
    }
    break;
  }
LABEL_61:
  v3->total_x += 4;
  v3->total_y += 4;
  ScrollInfo.nMax = v3->total_x;
  ScrollInfo.cbSize = 28;
  ScrollInfo.fMask = 23;
  ScrollInfo.nMin = 0;
  ScrollInfo.nPos = 0;
  ScrollInfo.nPage = TE.clientrect.right;
  CWnd::SetScrollInfo(this: v3, nBar: 0, lpScrollInfo: &ScrollInfo, bRedraw: 1);
  ScrollInfo.nMax = v3->total_y;
  ScrollInfo.nPage = TE.clientrect.bottom;
  CWnd::SetScrollInfo(this: v3, nBar: 1, lpScrollInfo: &ScrollInfo, bRedraw: 1);
  sprintf(string: szbuf, format: "Size = %d %d\n", v3->total_y, TE.clientrect.bottom);
}

//------------------------------------------------------------------------------
// Address: 0x100B7510
// Name: protected: void CTextureWindow::OnSize(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTextureWindow::OnSize(
        CTextureWindow *this@<ecx>,
        int a2@<edi>,
        unsigned int nType,
        unsigned int cx,
        int cy)
{
  CWnd::Default(this);
  CTextureWindow::UpdateScrollSizes(this, a2, a3: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x100B7530
// Name: public: void CTextureWindow::SelectTexture(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureWindow::SelectTexture(CTextureWindow *this, IEditorTexture *pszTexture, int bAllowRedraw)
{
  IEditorTexture *ActiveTexture; // eax
  HWND__ *m_hWnd; // edx
  IEditorTexture *v6; // edi
  int v7; // ebx
  int ScrollPos; // edi
  HWND Parent; // eax
  CWnd *v10; // eax
  CTextureWindow::TWENUMPOS TE; // [esp+Ch] [ebp-5Ch] BYREF
  tagRECT rcDst; // [esp+44h] [ebp-24h] BYREF
  CRect r; // [esp+54h] [ebp-14h] BYREF
  int bNotDone; // [esp+64h] [ebp-4h]
  IEditorTexture *pTex; // [esp+70h] [ebp+8h]

  bNotDone = CTextureWindow::EnumTexturePositions(this, pTE: &TE, bStart: 1);
  ActiveTexture = CTextureSystem::FindActiveTexture(
                    this: &g_Textures,
                    pszInputName: (const char *)pszTexture,
                    piIndex: nullptr,
                    bDummy: 1);
  m_hWnd = this->m_hWnd;
  v6 = ActiveTexture;
  r.left = 100;
  r.top = 100;
  pTex = ActiveTexture;
  r.right = 500;
  r.bottom = 500;
  if ( IsWindow(hWnd: m_hWnd) )
    GetClientRect(hWnd: this->m_hWnd, lpRect: &r);
  v7 = r.bottom - r.top;
  if ( v6 != nullptr && bNotDone != 0 )
  {
    while ( v6 != TE.pTex )
    {
      if ( CTextureWindow::EnumTexturePositions(this, pTE: &TE, bStart: 0) == 0 )
        return;
    }
    if ( IsWindow(hWnd: this->m_hWnd) )
    {
      ScrollPos = CWnd::GetScrollPos(this, nBar: 1);
      if ( ScrollPos + v7 < TE.texrect.top || TE.texrect.bottom < ScrollPos )
      {
        CWnd::SetScrollPos(this, nBar: 1, nPos: TE.texrect.top, bRedraw: 1);
        CWnd::ScrollWindow(this, xAmount: 0, yAmount: ScrollPos - TE.texrect.top, lpRect: nullptr, lpClipRect: nullptr);
        if ( bAllowRedraw != 0 )
          RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
      }
      CTextureWindow::HighlightCurTexture(this, pDC: nullptr);
      v6 = pTex;
    }
    v6->GetShortName(this: v6, a2: this->szCurTexture);
    if ( IsWindow(hWnd: this->m_hWnd) )
    {
      CopyRect(lprcDst: &rcDst, lprcSrc: &TE.texrect);
      this->rectHighlight = (CRect)rcDst;
      InflateRect(lprc: &this->rectHighlight, dx: 2, dy: 4);
      CTextureWindow::HighlightCurTexture(this, pDC: nullptr);
    }
    Parent = GetParent(hWnd: this->m_hWnd);
    v10 = CWnd::FromHandle(hWnd: Parent);
    PostMessageA(hWnd: v10->m_hWnd, Msg: 0x406u, wParam: 0, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B76C0
// Name: protected: void CTextureWindow::OnLButtonDown(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureWindow::OnLButtonDown(CTextureWindow *this, unsigned int nFlags, CPoint point)
{
  int v4; // edi
  int v5; // edi
  HWND Parent; // eax
  CWnd *v7; // eax
  char szNewTexture[128]; // [esp+Ch] [ebp-C8h] BYREF
  CTextureWindow::TWENUMPOS TE; // [esp+8Ch] [ebp-48h] BYREF
  tagRECT rcDst; // [esp+C4h] [ebp-10h] BYREF

  v4 = CTextureWindow::EnumTexturePositions(this, pTE: &TE, bStart: 1);
  point.x += CWnd::GetScrollPos(this, nBar: 0);
  point.y += CWnd::GetScrollPos(this, nBar: 1);
  if ( v4 != 0 )
  {
    while ( !PtInRect(lprc: &TE.texrect, pt: point.tagPOINT) )
    {
      v5 = CTextureWindow::EnumTexturePositions(this, pTE: &TE, bStart: 0);
      if ( v5 == 0 )
        return;
    }
    TE.pTex->GetShortName(this: TE.pTex, a2: szNewTexture);
    CTextureWindow::HighlightCurTexture(this, pDC: nullptr);
    strcpy(this->szCurTexture, szNewTexture);
    CopyRect(lprcDst: &rcDst, lprcSrc: &TE.texrect);
    this->rectHighlight = (CRect)rcDst;
    InflateRect(lprc: &this->rectHighlight, dx: 2, dy: 4);
    CTextureWindow::HighlightCurTexture(this, pDC: nullptr);
    Parent = GetParent(hWnd: this->m_hWnd);
    v7 = CWnd::FromHandle(hWnd: Parent);
    PostMessageA(hWnd: v7->m_hWnd, Msg: 0x406u, wParam: 0, lParam: 0);
    CWnd::SetFocus(this);
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B77E0
// Name: public: void CTextureWindow::SetSpecificList(class TextureWindowTexList __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTextureWindow::SetSpecificList(CTextureWindow *this@<ecx>, int a2@<edi>, TextureWindowTexList *pList)
{
  bool v4; // zf

  v4 = this->m_hWnd == nullptr;
  this->m_pSpecificList = pList;
  if ( !v4 )
  {
    CTextureWindow::UpdateScrollSizes(this, a2, a3: (int)this);
    CTextureWindow::SelectTexture(this, pszTexture: (IEditorTexture *)this->szCurTexture, bAllowRedraw: 0);
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B7820
// Name: public: void CTextureWindow::SetTypeFilter(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTextureWindow::SetTypeFilter(CTextureWindow *this@<ecx>, int a2@<edi>, int filter, bool enable)
{
  if ( enable )
    this->m_nTypeFilter |= filter;
  else
    this->m_nTypeFilter &= ~filter;
  if ( this->m_bEnableUpdate )
  {
    CTextureWindow::UpdateScrollSizes(this, a2, a3: (int)this);
    CTextureWindow::SelectTexture(this, pszTexture: (IEditorTexture *)this->szCurTexture, bAllowRedraw: 0);
    if ( IsWindow(hWnd: this->m_hWnd) )
    {
      InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
      UpdateWindow(hWnd: this->m_hWnd);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B7890
// Name: public: void CTextureWindow::SetDisplaySize(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTextureWindow::SetDisplaySize(CTextureWindow *this@<ecx>, int a2@<edi>, int iSize)
{
  this->iDisplaySize = iSize;
  CTextureWindow::UpdateScrollSizes(this, a2, a3: (int)this);
  CTextureWindow::SelectTexture(this, pszTexture: (IEditorTexture *)this->szCurTexture, bAllowRedraw: 0);
  RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
}

//------------------------------------------------------------------------------
// Address: 0x100B78D0
// Name: public: void CTextureWindow::SetNameFilter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTextureWindow::SetNameFilter(CTextureWindow *this@<ecx>, int a2@<edi>, const char *pszFilter)
{
  char *i; // eax

  if ( this->m_bEnableUpdate )
    CTextureWindow::HighlightCurTexture(this, pDC: nullptr);
  strcpy(this->m_szFilter, pszFilter);
  strupr(string: this->m_szFilter);
  this->m_nFilters = 0;
  for ( i = strtok(string: this->m_szFilter, control: " ,;"); i != nullptr; i = strtok(string: nullptr, control: " ,;") )
    this->m_Filters[this->m_nFilters++] = i;
  if ( this->m_bEnableUpdate )
  {
    CTextureWindow::UpdateScrollSizes(this, a2, a3: (int)this);
    CTextureWindow::SelectTexture(this, pszTexture: (IEditorTexture *)this->szCurTexture, bAllowRedraw: 0);
    if ( IsWindow(hWnd: this->m_hWnd) )
    {
      InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
      UpdateWindow(hWnd: this->m_hWnd);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B7990
// Name: public: void CTextureWindow::SetKeywords(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTextureWindow::SetKeywords(CTextureWindow *this@<ecx>, int a2@<edi>, const char *pszKeywords)
{
  char *i; // eax

  if ( this->m_bEnableUpdate )
    CTextureWindow::HighlightCurTexture(this, pDC: nullptr);
  strcpy(this->m_szKeywords, pszKeywords);
  strupr(string: this->m_szKeywords);
  this->m_nKeywords = 0;
  for ( i = strtok(string: this->m_szKeywords, control: " ,;"); i != nullptr; i = strtok(
                                                                                    string: nullptr,
                                                                                    control: " ,;") )
    this->m_Keyword[this->m_nKeywords++] = i;
  if ( this->m_bEnableUpdate )
  {
    CTextureWindow::UpdateScrollSizes(this, a2, a3: (int)this);
    CTextureWindow::SelectTexture(this, pszTexture: (IEditorTexture *)this->szCurTexture, bAllowRedraw: 0);
    if ( IsWindow(hWnd: this->m_hWnd) )
    {
      InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
      UpdateWindow(hWnd: this->m_hWnd);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B7A50
// Name: protected: void CTextureWindow::OnPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureWindow::OnPaint(CTextureWindow *this)
{
  int v2; // eax
  int v3; // eax
  CPalette *p_GDIPalette; // eax
  CPalette *v5; // edi
  int v6; // eax
  int v7; // edx
  int v8; // eax
  char v9; // cl
  HWND__ *m_hWnd; // [esp-8h] [ebp-1CCh]
  int ScrollPos; // [esp-4h] [ebp-1C8h]
  char szFirstDrawnTexture[128]; // [esp+Ch] [ebp-1B8h] BYREF
  char szDrawTexture[128]; // [esp+8Ch] [ebp-138h] BYREF
  CPaintDC dc; // [esp+10Ch] [ebp-B8h] BYREF
  CTextureWindow::TWENUMPOS TE; // [esp+160h] [ebp-64h] BYREF
  CRect clientrect; // [esp+198h] [ebp-2Ch] BYREF
  DrawTexData_t DrawTexData; // [esp+1A8h] [ebp-1Ch] BYREF
  int bFirst; // [esp+1B0h] [ebp-14h]
  int bFoundHighlight; // [esp+1B4h] [ebp-10h]
  int v20; // [esp+1C0h] [ebp-4h]

  CPaintDC::CPaintDC(this: &dc, pWnd: this);
  v20 = 0;
  CDC::SelectObject(this: &dc, pFont: &this->TexFont);
  CDC::SetTextColor(this: &dc, crColor: 0xFFFFFFu);
  CDC::SetBkMode(this: &dc, nBkMode: 1);
  m_hWnd = this->m_hWnd;
  memset(&clientrect, 0, sizeof(clientrect));
  GetClientRect(hWnd: m_hWnd, lpRect: &clientrect);
  ScrollPos = CWnd::GetScrollPos(this, nBar: 1);
  v2 = CWnd::GetScrollPos(this, nBar: 0);
  CDC::SetWindowOrg(this: &dc, result: (CPoint *)&DrawTexData, x: v2, y: ScrollPos);
  v3 = CTextureWindow::EnumTexturePositions(this, pTE: &TE, bStart: 1);
  bFoundHighlight = 0;
  this->rectHighlight.left = -1;
  bFirst = 1;
  if ( v3 == 0 )
    goto LABEL_17;
  do
  {
    TE.pTex->GetShortName(this: TE.pTex, a2: szDrawTexture);
    if ( _V_stricmp(s1: this->szCurTexture, s2: szDrawTexture) == 0 )
    {
      CopyRect(lprcDst: &this->rectHighlight, lprcSrc: &TE.texrect);
      InflateRect(lprc: &this->rectHighlight, dx: 2, dy: 4);
      bFoundHighlight = 1;
    }
    if ( RectVisible(hdc: dc.m_hDC, lprect: &TE.texrect) )
    {
      TE.pTex->Load(this: TE.pTex);
      if ( TE.pTex->HasPalette(this: TE.pTex) )
        p_GDIPalette = TE.pTex->GetPalette(this: TE.pTex);
      else
        p_GDIPalette = &g_pGameConfig->Palette.GDIPalette;
      v5 = CDC::SelectPalette(this: &dc, pPalette: p_GDIPalette, bForceBackground: false);
      RealizePalette(hdc: dc.m_hDC);
      v6 = 5;
      if ( this->m_bShowErrors )
        v6 = 13;
      v7 = v6 | (this->m_pSpecificList != nullptr ? 0x10 : 0);
      DrawTexData.nUsageCount = TE.nUsageCount;
      DrawTexData.nFlags = v7;
      TE.pTex->Draw(this: TE.pTex, a2: &dc, a3: &TE.texrect, a4: 7, a5: 12, a6: &DrawTexData);
      CDC::SelectPalette(this: &dc, pPalette: v5, bForceBackground: false);
    }
    if ( bFirst != 0 )
    {
      bFirst = 0;
      v8 = 0;
      do
      {
        v9 = szDrawTexture[v8];
        szFirstDrawnTexture[v8++] = v9;
      }
      while ( v9 != 0 );
    }
  }
  while ( CTextureWindow::EnumTexturePositions(this, pTE: &TE, bStart: 0) != 0 );
  if ( bFoundHighlight != 0 )
    CTextureWindow::HighlightCurTexture(this, pDC: &dc);
  else
LABEL_17:
    CTextureWindow::SelectTexture(this, pszTexture: (IEditorTexture *)szFirstDrawnTexture, bAllowRedraw: 1);
  v20 = -1;
  CPaintDC::~CPaintDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x100B7CA0
// Name: protected: virtual struct AFX_MSGMAP const __near * CTextureWindow::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CTextureWindow::GetMessageMap(CTextureWindow *this)
{
  return (const AFX_MSGMAP *)&off_105E74E4;
}

//------------------------------------------------------------------------------
// Address: 0x100B7CB0
// Name: public: CTextureWindow::CTextureWindow(void)
// Source: json
//------------------------------------------------------------------------------
CTextureWindow *__thiscall CTextureWindow::CTextureWindow(CTextureWindow *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CTextureWindow_vtbl *)&CTextureWindow::`vftable';
  this->TexFont.__vftable = (CFont_vtbl *)&CGdiObject::`vftable';
  this->TexFont.m_hObject = nullptr;
  this->TexFont.__vftable = (CFont_vtbl *)&CFont::`vftable';
  this->rectHighlight.left = 0;
  this->rectHighlight.top = 0;
  this->rectHighlight.right = 0;
  this->rectHighlight.bottom = 0;
  this->m_szFilter[0] = 0;
  this->m_nFilters = 0;
  this->m_szKeywords[0] = 0;
  this->m_nKeywords = 0;
  this->m_pSpecificList = nullptr;
  this->szCurTexture[0] = 0;
  this->bFirstPaint = 1;
  this->m_eTextureFormat = g_pGameConfig->textureformat;
  this->m_nTypeFilter = -1;
  *(_WORD *)&this->m_bEnableUpdate = 257;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B7D80
// Name: public: virtual CTextureWindow::~CTextureWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureWindow::~CTextureWindow(CTextureWindow *this)
{
  this->__vftable = (CTextureWindow_vtbl *)&CTextureWindow::`vftable';
  this->TexFont.__vftable = (CFont_vtbl *)&CFont::`vftable';
  CGdiObject::~CGdiObject(this: &this->TexFont);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B7E60
// Name: public: void CTextureWindow::Create(class CWnd __near *,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTextureWindow::Create(CTextureWindow *this@<ecx>, int a2@<edi>, CWnd *pParentWnd, tagRECT *rect)
{
  CAfxStringMgr *StringManager; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  HCURSOR CursorA; // eax
  const char *v8; // eax
  int v9; // ecx
  HDC DC; // eax
  CDC *v11; // edi
  HBRUSH__ *StockObject; // [esp-8h] [ebp-1Ch]
  HICON IconW; // [esp-4h] [ebp-18h]

  if ( (_S1_11 & 1) == 0 )
  {
    _S1_11 |= 1u;
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    TextureWndClassName.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    atexit(func: CTextureWindow::Create_::_2_::_dynamic_atexit_destructor_for__TextureWndClassName__);
  }
  this->iDisplaySize = 64;
  if ( *((_DWORD *)TextureWndClassName.m_pszData - 3) == 0 )
  {
    AfxGetModuleState();
    ModuleState = AfxGetModuleState();
    IconW = LoadIconW(hInstance: ModuleState->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x94);
    StockObject = (HBRUSH__ *)GetStockObject(i: 4);
    CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
    v8 = AfxRegisterWndClass(nClassStyle: 0xBu, hCursor: CursorA, hbrBackground: StockObject, hIcon: IconW);
    if ( v8 != nullptr )
    {
      a2 = (int)(v8 + 1);
      v9 = strlen(v8);
    }
    else
    {
      v9 = 0;
    }
    ATL::CSimpleStringT<char,0>::SetString(this: &TextureWndClassName, pszSrc: v8, nLength: v9);
  }
  CWnd::Create(
    this,
    lpszClassName: TextureWndClassName.m_pszData,
    lpszWindowName: "TextureBrowserWindow",
    dwStyle: 0x40311000u,
    rect,
    pParentWnd,
    nID: 0x6Au,
    pContext: nullptr);
  CTextureWindow::UpdateScrollSizes(this, a2, a3: (int)this);
  if ( this->TexFont.m_hObject == nullptr )
    CFont::CreatePointFont(this: &this->TexFont, nPointSize: 70, lpszFaceName: "Courier New", pDC: nullptr);
  DC = GetDC(hWnd: this->m_hWnd);
  v11 = CDC::FromHandle(hDC: DC);
  v11->SelectObject(this: v11, a2: &this->TexFont);
  GetCharWidthA(hdc: v11->m_hAttribDC, iFirst: 0x41u, iLast: 0x41u, lpBuffer: &this->iTexNameCharWidth);
  ReleaseDC(hWnd: this->m_hWnd, hDC: v11->m_hDC);
}

//------------------------------------------------------------------------------
// Address: 0x105CAE60
// Name: _CTextureWindow::Create_::_2_::_dynamic_atexit_destructor_for__TextureWndClassName__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTextureWindow::Create_::_2_::_dynamic_atexit_destructor_for__TextureWndClassName__()
{
  char *v0; // eax

  v0 = TextureWndClassName.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)TextureWndClassName.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v0 + 4))(a1: v0);
}
