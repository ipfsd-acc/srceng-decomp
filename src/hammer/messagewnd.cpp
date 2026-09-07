// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/messagewnd.cpp
// Functions: 140
// ============================================================

#include "hammer\messagewnd.h"

//------------------------------------------------------------------------------
// Address: 0x10002600
// Name: public: void CArray<struct error3d,struct error3d __near &>::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<error3d,error3d &>::SetSize(CArray<error3d,error3d &> *this, int nNewSize, error3d *nGrowBy)
{
  int v3; // ebx
  error3d *m_pData; // edx
  error3d *v6; // eax
  int m_nMaxSize; // ecx
  int m_nSize; // ecx
  int m_nGrowBy; // eax
  int v10; // edi
  unsigned int v11; // edi
  error3d *pNewData; // [esp+18h] [ebp+Ch]

  v3 = nNewSize;
  if ( nNewSize < 0 )
    AfxThrowInvalidArgException();
  if ( (int)nGrowBy >= 0 )
    this->m_nGrowBy = (int)nGrowBy;
  if ( nNewSize != 0 )
  {
    m_pData = this->m_pData;
    if ( m_pData != nullptr )
    {
      m_nMaxSize = this->m_nMaxSize;
      if ( nNewSize > m_nMaxSize )
      {
        m_nGrowBy = this->m_nGrowBy;
        if ( m_nGrowBy == 0 )
        {
          m_nGrowBy = this->m_nSize / 8;
          if ( m_nGrowBy >= 4 )
          {
            if ( m_nGrowBy > 1024 )
              m_nGrowBy = 1024;
          }
          else
          {
            m_nGrowBy = 4;
          }
        }
        v10 = m_nMaxSize + m_nGrowBy;
        if ( nNewSize >= m_nMaxSize + m_nGrowBy )
          v10 = nNewSize;
        else
          nNewSize = m_nMaxSize + m_nGrowBy;
        if ( v10 < m_nMaxSize )
          AfxThrowInvalidArgException();
        v11 = 12 * v10;
        pNewData = (error3d *)operator new[](nSize: v11);
        ATL::Checked::memcpy_s(_S1: pNewData, _S1max: v11, _S2: this->m_pData, _N: 12 * this->m_nSize);
        memset(dst: (int)&pNewData[this->m_nSize], value: nullptr, count: 12 * (v3 - this->m_nSize));
        operator delete(p: this->m_pData);
        this->m_pData = pNewData;
        this->m_nMaxSize = nNewSize;
      }
      else
      {
        m_nSize = this->m_nSize;
        if ( nNewSize > m_nSize )
        {
          memset(dst: (int)&m_pData[m_nSize], value: nullptr, count: 12 * (nNewSize - m_nSize));
          this->m_nSize = nNewSize;
          return;
        }
      }
      this->m_nSize = v3;
    }
    else
    {
      if ( nNewSize <= this->m_nGrowBy )
        nNewSize = this->m_nGrowBy;
      v6 = (error3d *)operator new[](nSize: 12 * nNewSize);
      this->m_pData = v6;
      memset(dst: (int)v6, value: nullptr, count: 12 * nNewSize);
      this->m_nSize = v3;
      this->m_nMaxSize = nNewSize;
    }
  }
  else
  {
    if ( this->m_pData != nullptr )
    {
      operator delete(p: this->m_pData);
      this->m_pData = nullptr;
    }
    this->m_nMaxSize = 0;
    this->m_nSize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002860
// Name: public: virtual void CArray<struct error3d,struct error3d __near &>::Serialize(class CArchive __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<error3d,error3d &>::Serialize(CArray<error3d,error3d &> *this, CArchive *ar)
{
  int Count; // eax

  if ( (ar->m_nMode & 1) != 0 )
  {
    Count = CArchive::ReadCount(this: ar);
    CArray<error3d,error3d &>::SetSize(this, nNewSize: Count, nGrowBy: (error3d *)0xFFFFFFFF);
  }
  else
  {
    CArchive::WriteCount(this: ar, dwCount: this->m_nSize);
  }
  SerializeElements<error3d>(ar, pElements: this->m_pData, nCount: this->m_nSize);
}

//------------------------------------------------------------------------------
// Address: 0x1003DF40
// Name: public: virtual CArray<struct CCOMMAND,struct CCOMMAND __near &>::~CArray<struct CCOMMAND,struct CCOMMAND __near &>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<CCOMMAND,CCOMMAND &>::~CArray<CCOMMAND,CCOMMAND &>(CArray<CCOMMAND,CCOMMAND &> *this)
{
  CCOMMAND *m_pData; // ecx

  this->__vftable = (CArray<CCOMMAND,CCOMMAND &>_vtbl *)&CArray<CCOMMAND,CCOMMAND &>::`vftable';
  m_pData = this->m_pData;
  if ( m_pData != nullptr )
    operator delete(p: m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1003DFA0
// Name: public: void CArray<struct CCOMMAND,struct CCOMMAND __near &>::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<CCOMMAND,CCOMMAND &>::SetSize(
        CArray<CCOMMAND,CCOMMAND &> *this,
        int nNewSize,
        CCOMMAND *nGrowBy)
{
  int v3; // edi
  CCOMMAND *m_pData; // edx
  CCOMMAND *v6; // eax
  int m_nMaxSize; // ecx
  int m_nSize; // eax
  int m_nGrowBy; // eax
  int v10; // ebx
  unsigned int v11; // ebx
  CCOMMAND *pNewData; // [esp+18h] [ebp+Ch]

  v3 = nNewSize;
  if ( nNewSize < 0 )
    AfxThrowInvalidArgException();
  if ( (int)nGrowBy >= 0 )
    this->m_nGrowBy = (int)nGrowBy;
  if ( nNewSize != 0 )
  {
    m_pData = this->m_pData;
    if ( m_pData != nullptr )
    {
      m_nMaxSize = this->m_nMaxSize;
      if ( nNewSize > m_nMaxSize )
      {
        m_nGrowBy = this->m_nGrowBy;
        if ( m_nGrowBy == 0 )
        {
          m_nGrowBy = this->m_nSize / 8;
          if ( m_nGrowBy >= 4 )
          {
            if ( m_nGrowBy > 1024 )
              m_nGrowBy = 1024;
          }
          else
          {
            m_nGrowBy = 4;
          }
        }
        v10 = m_nMaxSize + m_nGrowBy;
        if ( nNewSize >= m_nMaxSize + m_nGrowBy )
          v10 = nNewSize;
        else
          nNewSize = m_nMaxSize + m_nGrowBy;
        if ( v10 < m_nMaxSize )
          AfxThrowInvalidArgException();
        v11 = 804 * v10;
        pNewData = (CCOMMAND *)operator new[](nSize: v11);
        ATL::Checked::memcpy_s(_S1: pNewData, _S1max: v11, _S2: this->m_pData, _N: 804 * this->m_nSize);
        memset(dst: (int)&pNewData[this->m_nSize], value: nullptr, count: 804 * (v3 - this->m_nSize));
        operator delete(p: this->m_pData);
        this->m_pData = pNewData;
        this->m_nMaxSize = nNewSize;
      }
      else
      {
        m_nSize = this->m_nSize;
        if ( nNewSize > m_nSize )
        {
          memset(dst: (int)&m_pData[m_nSize], value: nullptr, count: 804 * (nNewSize - m_nSize));
          this->m_nSize = nNewSize;
          return;
        }
      }
      this->m_nSize = v3;
    }
    else
    {
      if ( nNewSize <= this->m_nGrowBy )
        nNewSize = this->m_nGrowBy;
      v6 = (CCOMMAND *)operator new[](nSize: 804 * nNewSize);
      this->m_pData = v6;
      memset(dst: (int)v6, value: nullptr, count: 804 * nNewSize);
      this->m_nSize = v3;
      this->m_nMaxSize = nNewSize;
    }
  }
  else
  {
    if ( this->m_pData != nullptr )
    {
      operator delete(p: this->m_pData);
      this->m_pData = nullptr;
    }
    this->m_nMaxSize = 0;
    this->m_nSize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E710
// Name: public: int CArray<struct CCOMMAND,struct CCOMMAND __near &>::Add(struct CCOMMAND __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CArray<CCOMMAND,CCOMMAND &>::Add(CArray<CCOMMAND,CCOMMAND &> *this, CCOMMAND *newElement)
{
  int m_nSize; // ebx

  m_nSize = this->m_nSize;
  if ( m_nSize < 0 )
    AfxThrowInvalidArgException();
  CArray<CCOMMAND,CCOMMAND &>::SetSize(this, nNewSize: m_nSize + 1, nGrowBy: (CCOMMAND *)0xFFFFFFFF);
  qmemcpy(&this->m_pData[m_nSize], newElement, sizeof(this->m_pData[m_nSize]));
  return m_nSize;
}

//------------------------------------------------------------------------------
// Address: 0x1003E750
// Name: public: virtual void CArray<struct CCOMMAND,struct CCOMMAND __near &>::Serialize(class CArchive __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<CCOMMAND,CCOMMAND &>::Serialize(CArray<CCOMMAND,CCOMMAND &> *this, CArchive *ar)
{
  int Count; // eax

  if ( (ar->m_nMode & 1) != 0 )
  {
    Count = CArchive::ReadCount(this: ar);
    CArray<CCOMMAND,CCOMMAND &>::SetSize(this, nNewSize: Count, nGrowBy: (CCOMMAND *)0xFFFFFFFF);
  }
  else
  {
    CArchive::WriteCount(this: ar, dwCount: this->m_nSize);
  }
  SerializeElements<CCOMMAND>(ar, pElements: this->m_pData, nCount: this->m_nSize);
}

//------------------------------------------------------------------------------
// Address: 0x100865C0
// Name: public: virtual struct CRuntimeClass __near * CMessageWnd::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMessageWnd::GetRuntimeClass(CMessageWnd *this)
{
  return &CMessageWnd::classCMessageWnd;
}

//------------------------------------------------------------------------------
// Address: 0x100865D0
// Name: public: static class CMessageWnd __near * CMessageWnd::CreateMessageWndObject(void)
// Source: json
//------------------------------------------------------------------------------
CMessageWnd *__cdecl CMessageWnd::CreateMessageWndObject()
{
  return (CMessageWnd *)CRuntimeClass::CreateObject(this: &CMessageWnd::classCMessageWnd);
}

//------------------------------------------------------------------------------
// Address: 0x100865E0
// Name: public: void CMessageWnd::ShowMessageWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageWnd::ShowMessageWindow(CMessageWnd *this)
{
  if ( this->m_hWnd != nullptr && !this->bDestroyed )
    CWnd::ShowWindow(this, nCmdShow: 5);
}

//------------------------------------------------------------------------------
// Address: 0x10086600
// Name: protected: void CMessageWnd::OnDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageWnd::OnDestroy(CMessageWnd *this)
{
  this->bDestroyed = true;
}

//------------------------------------------------------------------------------
// Address: 0x10086610
// Name: public: void CArray<struct CMessageWnd::MWMSGSTRUCT,struct CMessageWnd::MWMSGSTRUCT __near &>::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<CMessageWnd::MWMSGSTRUCT,CMessageWnd::MWMSGSTRUCT &>::SetSize(
        CArray<CMessageWnd::MWMSGSTRUCT,CMessageWnd::MWMSGSTRUCT &> *this,
        int nNewSize,
        CMessageWnd::MWMSGSTRUCT *nGrowBy)
{
  int v3; // ebx
  CMessageWnd::MWMSGSTRUCT *m_pData; // edx
  CMessageWnd::MWMSGSTRUCT *v6; // eax
  int m_nMaxSize; // ecx
  int m_nSize; // ecx
  int m_nGrowBy; // eax
  int v10; // edi
  unsigned int v11; // edi
  CMessageWnd::MWMSGSTRUCT *pNewData; // [esp+18h] [ebp+Ch]

  v3 = nNewSize;
  if ( nNewSize < 0 )
    AfxThrowInvalidArgException();
  if ( (int)nGrowBy >= 0 )
    this->m_nGrowBy = (int)nGrowBy;
  if ( nNewSize != 0 )
  {
    m_pData = this->m_pData;
    if ( m_pData != nullptr )
    {
      m_nMaxSize = this->m_nMaxSize;
      if ( nNewSize > m_nMaxSize )
      {
        m_nGrowBy = this->m_nGrowBy;
        if ( m_nGrowBy == 0 )
        {
          m_nGrowBy = this->m_nSize / 8;
          if ( m_nGrowBy >= 4 )
          {
            if ( m_nGrowBy > 1024 )
              m_nGrowBy = 1024;
          }
          else
          {
            m_nGrowBy = 4;
          }
        }
        v10 = m_nMaxSize + m_nGrowBy;
        if ( nNewSize >= m_nMaxSize + m_nGrowBy )
          v10 = nNewSize;
        else
          nNewSize = m_nMaxSize + m_nGrowBy;
        if ( v10 < m_nMaxSize )
          AfxThrowInvalidArgException();
        v11 = 160 * v10;
        pNewData = (CMessageWnd::MWMSGSTRUCT *)operator new[](nSize: v11);
        ATL::Checked::memcpy_s(_S1: pNewData, _S1max: v11, _S2: this->m_pData, _N: 160 * this->m_nSize);
        memset(dst: (int)&pNewData[this->m_nSize], value: nullptr, count: 160 * (v3 - this->m_nSize));
        operator delete(p: this->m_pData);
        this->m_pData = pNewData;
        this->m_nMaxSize = nNewSize;
      }
      else
      {
        m_nSize = this->m_nSize;
        if ( nNewSize > m_nSize )
        {
          memset(dst: (int)&m_pData[m_nSize], value: nullptr, count: 160 * (nNewSize - m_nSize));
          this->m_nSize = nNewSize;
          return;
        }
      }
      this->m_nSize = v3;
    }
    else
    {
      if ( nNewSize <= this->m_nGrowBy )
        nNewSize = this->m_nGrowBy;
      v6 = (CMessageWnd::MWMSGSTRUCT *)operator new[](nSize: 160 * nNewSize);
      this->m_pData = v6;
      memset(dst: (int)v6, value: nullptr, count: 160 * nNewSize);
      this->m_nSize = v3;
      this->m_nMaxSize = nNewSize;
    }
  }
  else
  {
    if ( this->m_pData != nullptr )
    {
      operator delete(p: this->m_pData);
      this->m_pData = nullptr;
    }
    this->m_nMaxSize = 0;
    this->m_nSize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086780
// Name: public: void CMessageWnd::ToggleMessageWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageWnd::ToggleMessageWindow(CMessageWnd *this)
{
  BOOL v2; // eax

  if ( this->m_hWnd != nullptr && !this->bDestroyed )
  {
    v2 = IsWindowVisible(hWnd: this->m_hWnd);
    CWnd::ShowWindow(this, nCmdShow: v2 ? 0 : 8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100867B0
// Name: public: void CMessageWnd::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageWnd::Activate(CMessageWnd *this)
{
  if ( this->m_hWnd != nullptr && !this->bDestroyed )
  {
    CWnd::ShowWindow(this, nCmdShow: 5);
    CWnd::SetWindowPos(this, pWndInsertAfter: &CWnd::wndTopMost, x: 0, y: 0, cx: 0, cy: 0, nFlags: 0x43u);
    BringWindowToTop(hWnd: this->m_hWnd);
    CWnd::SetFocus(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086800
// Name: public: bool CMessageWnd::IsVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMessageWnd::IsVisible(CMessageWnd *this)
{
  return this->m_hWnd != nullptr && !this->bDestroyed && IsWindowVisible(hWnd: this->m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x10086830
// Name: public: void CMessageWnd::Resize(class CRect __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageWnd::Resize(CMessageWnd *this, CRect *rect)
{
  if ( this->m_hWnd != nullptr && !this->bDestroyed )
    CWnd::MoveWindow(
      this,
      x: rect->left,
      y: rect->top,
      nWidth: rect->right - rect->left,
      nHeight: rect->bottom - rect->top,
      bRepaint: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10086870
// Name: protected: void CMessageWnd::OnHScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageWnd::OnHScroll(
        CMessageWnd *this,
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
  CFrameWnd::OnHScroll(this, __formal: v8, __formal: nPos, __formal: pScrollBar);
}

//------------------------------------------------------------------------------
// Address: 0x10086950
// Name: protected: void CMessageWnd::OnVScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageWnd::OnVScroll(
        CMessageWnd *this,
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
  CWnd::GetScrollInfo(this, nBar: 1, lpScrollInfo: &ScrollInfo, nMask: 0x17u);
  ScrollPos = CWnd::GetScrollPos(this, nBar: 1);
  ScrollLimit = CWnd::GetScrollLimit(this, nBar: 1);
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
    CWnd::SetScrollPos(this, nBar: 1, nPos: v4 + ScrollPos, bRedraw: 1);
    CWnd::ScrollWindow(this, xAmount: 0, yAmount: -v4, lpRect: nullptr, lpClipRect: nullptr);
    UpdateWindow(hWnd: this->m_hWnd);
    v8 = nSBCode;
  }
  CFrameWnd::OnVScroll(this, __formal: v8, __formal: nPos, __formal: pScrollBar);
}

//------------------------------------------------------------------------------
// Address: 0x10086A30
// Name: protected: void CMessageWnd::OnKeyDown(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageWnd::OnKeyDown(
        CMessageWnd *this,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  int v5; // ebx
  int v6; // eax
  int v7; // edi
  int v8; // ebx
  int v9; // eax
  unsigned int v10; // edi
  int ScrollPos; // ebx
  int ScrollLimit; // eax
  int v13; // edi
  int v14; // ebx
  int v15; // eax
  unsigned int v16; // edi
  int v17; // ebx
  int v18; // eax
  int v19; // edi
  int v20; // ebx
  int v21; // eax
  int v22; // edi
  unsigned int v23; // [esp-10h] [ebp-30h]
  tagSCROLLINFO ScrollInfo; // [esp+4h] [ebp-1Ch] BYREF
  signed int nChara; // [esp+28h] [ebp+8h]

  switch ( nChar )
  {
    case '!':
      CWnd::GetScrollInfo(this, nBar: 1, lpScrollInfo: &ScrollInfo, nMask: 0x17u);
      ScrollPos = CWnd::GetScrollPos(this, nBar: 1);
      ScrollLimit = CWnd::GetScrollLimit(this, nBar: 1);
      v13 = -(ScrollInfo.nPage >> 1);
      if ( (signed int)(ScrollPos - (ScrollInfo.nPage >> 1)) < 0 )
        v13 = -ScrollPos;
      if ( ScrollPos + v13 > ScrollLimit )
        v13 = ScrollLimit - ScrollPos;
      if ( v13 != 0 )
      {
        CWnd::SetScrollPos(this, nBar: 1, nPos: v13 + ScrollPos, bRedraw: 1);
        CWnd::ScrollWindow(this, xAmount: 0, yAmount: -v13, lpRect: nullptr, lpClipRect: nullptr);
        UpdateWindow(hWnd: this->m_hWnd);
      }
      CFrameWnd::OnVScroll(this, __formal: 2u, __formal: 0, __formal: nullptr);
      break;
    case '"':
      CWnd::GetScrollInfo(this, nBar: 1, lpScrollInfo: &ScrollInfo, nMask: 0x17u);
      v14 = CWnd::GetScrollPos(this, nBar: 1);
      v15 = CWnd::GetScrollLimit(this, nBar: 1);
      v16 = ScrollInfo.nPage >> 1;
      if ( (signed int)(v14 + (ScrollInfo.nPage >> 1)) < 0 )
        v16 = -v14;
      if ( (int)(v14 + v16) > v15 )
        v16 = v15 - v14;
      if ( v16 != 0 )
      {
        CWnd::SetScrollPos(this, nBar: 1, nPos: v16 + v14, bRedraw: 1);
        CWnd::ScrollWindow(this, xAmount: 0, yAmount: -v16, lpRect: nullptr, lpClipRect: nullptr);
        UpdateWindow(hWnd: this->m_hWnd);
      }
      CFrameWnd::OnVScroll(this, __formal: 3u, __formal: 0, __formal: nullptr);
      break;
    case '#':
      nChara = CWnd::GetScrollLimit(this, nBar: 1);
      CWnd::GetScrollInfo(this, nBar: 1, lpScrollInfo: &ScrollInfo, nMask: 0x17u);
      v20 = CWnd::GetScrollPos(this, nBar: 1);
      v21 = CWnd::GetScrollLimit(this, nBar: 1);
      v22 = nChara - v20;
      if ( nChara < 0 )
        v22 = -v20;
      if ( v20 + v22 > v21 )
        v22 = v21 - v20;
      if ( v22 != 0 )
      {
        CWnd::SetScrollPos(this, nBar: 1, nPos: v22 + v20, bRedraw: 1);
        CWnd::ScrollWindow(this, xAmount: 0, yAmount: -v22, lpRect: nullptr, lpClipRect: nullptr);
        UpdateWindow(hWnd: this->m_hWnd);
      }
      v23 = nChara;
      goto LABEL_42;
    case '$':
      CWnd::GetScrollInfo(this, nBar: 1, lpScrollInfo: &ScrollInfo, nMask: 0x17u);
      v17 = CWnd::GetScrollPos(this, nBar: 1);
      v18 = CWnd::GetScrollLimit(this, nBar: 1);
      v19 = -v17;
      if ( v18 < 0 )
        v19 = v18 - v17;
      if ( v19 != 0 )
      {
        CWnd::SetScrollPos(this, nBar: 1, nPos: v19 + v17, bRedraw: 1);
        CWnd::ScrollWindow(this, xAmount: 0, yAmount: -v19, lpRect: nullptr, lpClipRect: nullptr);
        UpdateWindow(hWnd: this->m_hWnd);
      }
      v23 = 0;
LABEL_42:
      CFrameWnd::OnVScroll(this, __formal: 4u, __formal: v23, __formal: nullptr);
      break;
    case '&':
      CWnd::GetScrollInfo(this, nBar: 1, lpScrollInfo: &ScrollInfo, nMask: 0x17u);
      v5 = CWnd::GetScrollPos(this, nBar: 1);
      v6 = CWnd::GetScrollLimit(this, nBar: 1);
      v7 = -(ScrollInfo.nPage >> 2);
      if ( (signed int)(v5 - (ScrollInfo.nPage >> 2)) < 0 )
        v7 = -v5;
      if ( v5 + v7 > v6 )
        v7 = v6 - v5;
      if ( v7 != 0 )
      {
        CWnd::SetScrollPos(this, nBar: 1, nPos: v7 + v5, bRedraw: 1);
        CWnd::ScrollWindow(this, xAmount: 0, yAmount: -v7, lpRect: nullptr, lpClipRect: nullptr);
        UpdateWindow(hWnd: this->m_hWnd);
      }
      CFrameWnd::OnVScroll(this, __formal: 0, __formal: 0, __formal: nullptr);
      break;
    case '(':
      CWnd::GetScrollInfo(this, nBar: 1, lpScrollInfo: &ScrollInfo, nMask: 0x17u);
      v8 = CWnd::GetScrollPos(this, nBar: 1);
      v9 = CWnd::GetScrollLimit(this, nBar: 1);
      v10 = ScrollInfo.nPage >> 2;
      if ( (signed int)(v8 + (ScrollInfo.nPage >> 2)) < 0 )
        v10 = -v8;
      if ( (int)(v8 + v10) > v9 )
        v10 = v9 - v8;
      if ( v10 != 0 )
      {
        CWnd::SetScrollPos(this, nBar: 1, nPos: v10 + v8, bRedraw: 1);
        CWnd::ScrollWindow(this, xAmount: 0, yAmount: -v10, lpRect: nullptr, lpClipRect: nullptr);
        UpdateWindow(hWnd: this->m_hWnd);
      }
      CFrameWnd::OnVScroll(this, __formal: 1u, __formal: 0, __formal: nullptr);
      break;
    default:
      break;
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10086D50
// Name: public: virtual CArray<struct CMessageWnd::MWMSGSTRUCT,struct CMessageWnd::MWMSGSTRUCT __near &>::~CArray<struct CMessageWnd::MWMSGSTRUCT,struct CMessageWnd::MWMSGSTRUCT __near &>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<CMessageWnd::MWMSGSTRUCT,CMessageWnd::MWMSGSTRUCT &>::~CArray<CMessageWnd::MWMSGSTRUCT,CMessageWnd::MWMSGSTRUCT &>(
        CArray<CMessageWnd::MWMSGSTRUCT,CMessageWnd::MWMSGSTRUCT &> *this)
{
  CMessageWnd::MWMSGSTRUCT *m_pData; // ecx

  this->__vftable = (CArray<CMessageWnd::MWMSGSTRUCT,CMessageWnd::MWMSGSTRUCT &>_vtbl *)&CArray<CMessageWnd::MWMSGSTRUCT,CMessageWnd::MWMSGSTRUCT &>::`vftable';
  m_pData = this->m_pData;
  if ( m_pData != nullptr )
    operator delete(p: m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x10086DB0
// Name: void SerializeElements<struct CMessageWnd::MWMSGSTRUCT>(class CArchive __near &,struct CMessageWnd::MWMSGSTRUCT __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __stdcall SerializeElements<CMessageWnd::MWMSGSTRUCT>(
        CArchive *ar,
        CMessageWnd::MWMSGSTRUCT *pElements,
        CMessageWnd::MWMSGSTRUCT *nCount)
{
  unsigned int v3; // ebx
  int v4; // edi
  int v5; // edi
  CMessageWnd::MWMSGSTRUCT *pData; // [esp+1Ch] [ebp+10h]

  v3 = (unsigned int)nCount;
  if ( nCount != nullptr && pElements == nullptr )
    AfxThrowInvalidArgException();
  pData = pElements;
  if ( (ar->m_nMode & 1) != 0 )
  {
    for ( ; v3 != 0; v3 -= v5 )
    {
      v5 = v3;
      if ( v3 >= 0xCCCCCC )
        v5 = 13421772;
      if ( CArchive::Read(this: ar, lpBuf: (char *)pData, nMax: 160 * v5) != 160 * v5 )
        AfxThrowArchiveException(cause: 3, lpszArchiveName: nullptr);
      pData += v5;
    }
  }
  else
  {
    for ( ; v3 != 0; v3 -= v4 )
    {
      v4 = v3;
      if ( v3 >= 0xCCCCCC )
        v4 = 13421772;
      CArchive::Write(this: ar, lpBuf: (char *)pData, nMax: 160 * v4);
      pData += v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086E60
// Name: public: void CMessageWnd::CreateMessageWindow(class CMDIFrameWnd __near *,class CRect __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageWnd::CreateMessageWindow(CMessageWnd *this, CMDIFrameWnd *pwndParent, CRect *rect)
{
  int iNumMsgs; // ecx
  int v5; // eax
  int v6; // edx

  this->Create(this, a2: nullptr, a3: "Messages", a4: 1087307776u, a5: rect, a6: pwndParent, a7: nullptr);
  iNumMsgs = this->iNumMsgs;
  v5 = 0;
  if ( iNumMsgs > 0 )
  {
    v6 = 0;
    do
    {
      if ( v5 < 0 || v5 >= this->MsgArray.m_nSize )
        AfxThrowInvalidArgException();
      ++v5;
      v6 += 160;
    }
    while ( v5 < iNumMsgs );
  }
  CWnd::ShowWindow(this, nCmdShow: 5);
}

//------------------------------------------------------------------------------
// Address: 0x10086ED0
// Name: protected: void CMessageWnd::CalculateScrollSize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageWnd::CalculateScrollSize(CMessageWnd *this)
{
  int iNumMsgs; // edx
  int v3; // ebx
  int v4; // edi
  int v5; // ecx
  int v6; // ebx
  tagSCROLLINFO ScrollInfo; // [esp+4h] [ebp-30h] BYREF
  CRect clientrect; // [esp+20h] [ebp-14h] BYREF
  int iVert; // [esp+30h] [ebp-4h]

  if ( this->m_hWnd != nullptr && !this->bDestroyed )
  {
    iNumMsgs = this->iNumMsgs;
    v3 = 12 * iNumMsgs;
    v4 = 0;
    v5 = 0;
    iVert = 12 * iNumMsgs;
    if ( iNumMsgs > 0 )
    {
      v6 = 0;
      do
      {
        if ( v5 < 0 || v5 >= this->MsgArray.m_nSize )
          AfxThrowInvalidArgException();
        if ( this->iCharWidth * this->MsgArray.m_pData[v6].MsgLen > v4 )
          v4 = this->iCharWidth * this->MsgArray.m_pData[v6].MsgLen;
        ++v5;
        ++v6;
      }
      while ( v5 < iNumMsgs );
      v3 = iVert;
    }
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
    ScrollInfo.cbSize = 28;
    ScrollInfo.fMask = 23;
    CWnd::GetScrollInfo(this, nBar: 1, lpScrollInfo: &ScrollInfo, nMask: 0x17u);
    ScrollInfo.nMin = 0;
    memset(&clientrect, 0, sizeof(clientrect));
    GetClientRect(hWnd: this->m_hWnd, lpRect: &clientrect);
    ScrollInfo.nPage = clientrect.right - clientrect.left;
    ScrollInfo.nMax = v4;
    CWnd::SetScrollInfo(this, nBar: 0, lpScrollInfo: &ScrollInfo, bRedraw: 1);
    ScrollInfo.nMax = v3;
    ScrollInfo.nPage = clientrect.bottom - clientrect.top;
    CWnd::SetScrollInfo(this, nBar: 1, lpScrollInfo: &ScrollInfo, bRedraw: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086FE0
// Name: protected: void CMessageWnd::OnPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageWnd::OnPaint(CMessageWnd *this)
{
  int v2; // eax
  int y; // eax
  int iCharWidth; // edx
  int ScrollPos; // [esp-4h] [ebp-130h]
  CMessageWnd::MWMSGSTRUCT mws; // [esp+8h] [ebp-124h] BYREF
  CPaintDC dc; // [esp+A8h] [ebp-84h] BYREF
  CPoint result; // [esp+FCh] [ebp-30h] BYREF
  int nScrollMin; // [esp+104h] [ebp-28h] BYREF
  int nScrollMax; // [esp+108h] [ebp-24h] BYREF
  CRect r; // [esp+10Ch] [ebp-20h] BYREF
  unsigned int v12; // [esp+11Ch] [ebp-10h]
  int v13; // [esp+128h] [ebp-4h]

  CPaintDC::CPaintDC(this: &dc, pWnd: this);
  v13 = 0;
  CDC::SelectObject(this: &dc, pFont: &this->Font);
  CDC::SetBkMode(this: &dc, nBkMode: 1);
  if ( this->iCharWidth == -1 )
  {
    GetCharWidthA(hdc: dc.m_hAttribDC, iFirst: 0x41u, iLast: 0x41u, lpBuffer: &this->iCharWidth);
    CMessageWnd::CalculateScrollSize(this);
  }
  CWnd::GetScrollRange(this, nBar: 1, lpMinPos: &nScrollMin, lpMaxPos: &nScrollMax);
  r.left = 0;
  r.top = 0;
  r.right = 1;
  r.bottom = 12;
  ScrollPos = CWnd::GetScrollPos(this, nBar: 1);
  v2 = CWnd::GetScrollPos(this, nBar: 0);
  CDC::SetWindowOrg(this: &dc, &result, x: v2, y: ScrollPos);
  y = 0;
  result.y = 0;
  if ( this->iNumMsgs > 0 )
  {
    v12 = 0;
    do
    {
      if ( y < 0 || y >= this->MsgArray.m_nSize )
        AfxThrowInvalidArgException();
      iCharWidth = this->iCharWidth;
      mws = this->MsgArray.m_pData[v12 / 0xA0];
      r.right = mws.MsgLen * iCharWidth;
      if ( r.bottom >= nScrollMin )
      {
        if ( r.top > nScrollMax )
          break;
        if ( mws.type != mwStatus )
        {
          if ( mws.type == mwError )
            CDC::SetTextColor(this: &dc, crColor: 0x3C3CFFu);
        }
        else
        {
          CDC::SetTextColor(this: &dc, crColor: 0);
        }
        TextOutA(hdc: dc.m_hDC, x: r.left, y: r.top, lpString: mws.szMsg, c: mws.MsgLen);
        OffsetRect(lprc: &r, dx: 0, dy: 12);
        y = result.y;
      }
      v12 += 160;
      result.y = ++y;
    }
    while ( y < this->iNumMsgs );
  }
  v13 = -1;
  CPaintDC::~CPaintDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x100871A0
// Name: protected: void CMessageWnd::OnSize(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageWnd::OnSize(CMessageWnd *this, unsigned int nType, int cx, int cy)
{
  CMDIChildWnd::OnSize(this, nType, cx, cy);
  CMessageWnd::CalculateScrollSize(this);
}

//------------------------------------------------------------------------------
// Address: 0x100871D0
// Name: public: virtual void CArray<struct CMessageWnd::MWMSGSTRUCT,struct CMessageWnd::MWMSGSTRUCT __near &>::Serialize(class CArchive __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<CMessageWnd::MWMSGSTRUCT,CMessageWnd::MWMSGSTRUCT &>::Serialize(
        CArray<CMessageWnd::MWMSGSTRUCT,CMessageWnd::MWMSGSTRUCT &> *this,
        CArchive *ar)
{
  int Count; // eax

  if ( (ar->m_nMode & 1) != 0 )
  {
    Count = CArchive::ReadCount(this: ar);
    CArray<CMessageWnd::MWMSGSTRUCT,CMessageWnd::MWMSGSTRUCT &>::SetSize(
      this,
      nNewSize: Count,
      nGrowBy: (CMessageWnd::MWMSGSTRUCT *)0xFFFFFFFF);
  }
  else
  {
    CArchive::WriteCount(this: ar, dwCount: this->m_nSize);
  }
  SerializeElements<CMessageWnd::MWMSGSTRUCT>(
    ar,
    pElements: this->m_pData,
    nCount: (CMessageWnd::MWMSGSTRUCT *)this->m_nSize);
}

//------------------------------------------------------------------------------
// Address: 0x10087230
// Name: public: void CMessageWnd::AddMsg(enum MWMSGTYPE,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageWnd::AddMsg(CMessageWnd *this, MWMSGTYPE type, char *msg)
{
  int iNumMsgs; // esi
  CMessageWnd::MWMSGSTRUCT mws; // [esp+4h] [ebp-A4h] BYREF

  if ( !this->bDestroyed )
  {
    iNumMsgs = this->iNumMsgs;
    if ( iNumMsgs == 5000 )
    {
      memcpy(
        dst: (unsigned __int8 *)this->MsgArray.m_pData,
        src: (unsigned __int8 *)&this->MsgArray.m_pData[1],
        count: 0xC3460u);
      iNumMsgs = 4999;
    }
    else
    {
      this->iNumMsgs = iNumMsgs + 1;
    }
    mws.MsgLen = strlen(msg);
    mws.type = type;
    strcpy(mws.szMsg, msg);
    if ( iNumMsgs < 0 )
      AfxThrowInvalidArgException();
    if ( iNumMsgs >= this->MsgArray.m_nSize )
      CArray<CMessageWnd::MWMSGSTRUCT,CMessageWnd::MWMSGSTRUCT &>::SetSize(
        this: &this->MsgArray,
        nNewSize: iNumMsgs + 1,
        nGrowBy: (CMessageWnd::MWMSGSTRUCT *)0xFFFFFFFF);
    this->MsgArray.m_pData[iNumMsgs] = mws;
    if ( this->m_hWnd != nullptr )
    {
      CMessageWnd::CalculateScrollSize(this);
      InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087320
// Name: protected: virtual struct AFX_MSGMAP const __near * CMessageWnd::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMessageWnd::GetMessageMap(CMessageWnd *this)
{
  return (const AFX_MSGMAP *)&off_105E35A0;
}

//------------------------------------------------------------------------------
// Address: 0x10087330
// Name: protected: CMessageWnd::CMessageWnd(void)
// Source: json
//------------------------------------------------------------------------------
CMessageWnd *__thiscall CMessageWnd::CMessageWnd(CMessageWnd *this)
{
  CMDIChildWnd::CMDIChildWnd(this);
  this->__vftable = (CMessageWnd_vtbl *)&CMessageWnd::`vftable';
  this->MsgArray.__vftable = (CArray<CMessageWnd::MWMSGSTRUCT,CMessageWnd::MWMSGSTRUCT &>_vtbl *)&CArray<CMessageWnd::MWMSGSTRUCT,CMessageWnd::MWMSGSTRUCT &>::`vftable';
  this->MsgArray.m_pData = nullptr;
  this->MsgArray.m_nGrowBy = 0;
  this->MsgArray.m_nMaxSize = 0;
  this->MsgArray.m_nSize = 0;
  this->Font.__vftable = (CFont_vtbl *)&CGdiObject::`vftable';
  this->Font.m_hObject = nullptr;
  this->Font.__vftable = (CFont_vtbl *)&CFont::`vftable';
  this->iCharWidth = -1;
  this->iNumMsgs = 0;
  this->bDestroyed = false;
  CFont::CreatePointFont(this: &this->Font, nPointSize: 100, lpszFaceName: "Courier New", pDC: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100873F0
// Name: protected: virtual CMessageWnd::~CMessageWnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageWnd::~CMessageWnd(CMessageWnd *this)
{
  CMessageWnd::MWMSGSTRUCT *m_pData; // eax

  this->__vftable = (CMessageWnd_vtbl *)&CMessageWnd::`vftable';
  this->Font.__vftable = (CFont_vtbl *)&CFont::`vftable';
  CGdiObject::~CGdiObject(this: &this->Font);
  m_pData = this->MsgArray.m_pData;
  this->MsgArray.__vftable = (CArray<CMessageWnd::MWMSGSTRUCT,CMessageWnd::MWMSGSTRUCT &>_vtbl *)&CArray<CMessageWnd::MWMSGSTRUCT,CMessageWnd::MWMSGSTRUCT &>::`vftable';
  if ( m_pData != nullptr )
    operator delete(p: m_pData);
  CFrameWnd::~CFrameWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x10087480
// Name: public: static class CObject __near * CMessageWnd::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMessageWnd *__stdcall CMessageWnd::CreateObject()
{
  CMessageWnd *v0; // eax

  v0 = (CMessageWnd *)operator new(nSize: 0x140u);
  if ( v0 != nullptr )
    return CMessageWnd::CMessageWnd(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103417CB
// Name: public: virtual CArray<struct HWND__ __near *,struct HWND__ __near *>::~CArray<struct HWND__ __near *,struct HWND__ __near *>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<HWND__ *,HWND__ *>::~CArray<HWND__ *,HWND__ *>(CArray<HWND__ *,HWND__ *> *this)
{
  HWND__ **m_pData; // ecx

  this->__vftable = (CArray<HWND__ *,HWND__ *>_vtbl *)&CArray<HWND__ *,HWND__ *>::`vftable';
  m_pData = this->m_pData;
  if ( m_pData != nullptr )
    operator delete(p: m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x10349B3C
// Name: void SerializeElements<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>>(class CArchive __near &,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __stdcall SerializeElements<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>>(
        CArchive *ar,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *pElements,
        int nCount)
{
  SerializeElementsInsertExtract<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>>(ar, pElements, nCount);
}

//------------------------------------------------------------------------------
// Address: 0x1034FBEC
// Name: public: void CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *>::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
        CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *this,
        int nNewSize,
        int nGrowBy)
{
  CMFCRibbonKeyTip **m_pData; // ecx
  int v6; // edi
  CMFCRibbonKeyTip **v7; // eax
  int m_nMaxSize; // edi
  int m_nSize; // eax
  int m_nGrowBy; // eax
  void *v11; // edi
  int nNewMax; // [esp+10h] [ebp+8h]

  if ( nNewSize < 0 )
    goto LABEL_2;
  if ( nGrowBy >= 0 )
    this->m_nGrowBy = nGrowBy;
  if ( nNewSize != 0 )
  {
    m_pData = this->m_pData;
    if ( m_pData != nullptr )
    {
      m_nMaxSize = this->m_nMaxSize;
      if ( nNewSize > m_nMaxSize )
      {
        m_nGrowBy = this->m_nGrowBy;
        if ( m_nGrowBy == 0 )
        {
          m_nGrowBy = this->m_nSize / 8;
          if ( m_nGrowBy >= 4 )
          {
            if ( m_nGrowBy > 1024 )
              m_nGrowBy = 1024;
          }
          else
          {
            m_nGrowBy = 4;
          }
        }
        nNewMax = m_nMaxSize + m_nGrowBy;
        if ( nNewSize >= m_nMaxSize + m_nGrowBy )
          nNewMax = nNewSize;
        if ( nNewMax < m_nMaxSize )
LABEL_2:
          AfxThrowInvalidArgException();
        v11 = operator new(nSize: 4 * nNewMax);
        ATL::Checked::memcpy_s(_S1: v11, _S1max: 4 * nNewMax, _S2: this->m_pData, _N: 4 * this->m_nSize);
        memset(dst: (int)v11 + 4 * this->m_nSize, value: nullptr, count: 4 * (nNewSize - this->m_nSize));
        operator delete(p: this->m_pData);
        this->m_pData = (CMFCRibbonKeyTip **)v11;
        this->m_nMaxSize = nNewMax;
      }
      else
      {
        m_nSize = this->m_nSize;
        if ( nNewSize > m_nSize )
          memset(dst: (int)&m_pData[m_nSize], value: nullptr, count: 4 * (nNewSize - m_nSize));
      }
    }
    else
    {
      v6 = this->m_nGrowBy;
      if ( nNewSize > v6 )
        v6 = nNewSize;
      v7 = (CMFCRibbonKeyTip **)operator new(nSize: 4 * v6);
      this->m_pData = v7;
      memset(dst: (int)v7, value: nullptr, count: 4 * v6);
      this->m_nMaxSize = v6;
    }
    this->m_nSize = nNewSize;
  }
  else
  {
    if ( this->m_pData != nullptr )
    {
      operator delete(p: this->m_pData);
      this->m_pData = nullptr;
    }
    this->m_nMaxSize = 0;
    this->m_nSize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034FD27
// Name: public: virtual CArray<int,int const __near &>::~CArray<int,int const __near &>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<int,int const &>::~CArray<int,int const &>(CArray<int,int const &> *this)
{
  int *m_pData; // ecx

  this->__vftable = (CArray<int,int const &>_vtbl *)&CArray<int,int const &>::`vftable';
  m_pData = this->m_pData;
  if ( m_pData != nullptr )
    operator delete(p: m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1034FDDC
// Name: public: virtual void CArray<int,int>::Serialize(class CArchive __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<int,int>::Serialize(CArray<int,int> *this, CArchive *ar)
{
  int Count; // eax

  if ( (ar->m_nMode & 1) != 0 )
  {
    Count = CArchive::ReadCount(this: ar);
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
      (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)this,
      nNewSize: Count,
      nGrowBy: -1);
  }
  else
  {
    CArchive::WriteCount(this: ar, dwCount: this->m_nSize);
  }
  SerializeElements<int>(ar, pElements: this->m_pData, nCount: this->m_nSize);
}

//------------------------------------------------------------------------------
// Address: 0x1036C1ED
// Name: public: void CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const __near &>::InsertAt(int,enum CArchive::LoadArrayObjType const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &>::InsertAt(
        CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &> *this,
        int nIndex,
        const CArchive::LoadArrayObjType *newElement,
        int nCount)
{
  int v4; // esi
  int v6; // ebx
  int m_nSize; // esi
  int v8; // eax

  v4 = nIndex;
  if ( nIndex < 0 || (v6 = nCount, nCount <= 0) )
    AfxThrowInvalidArgException();
  if ( nIndex < this->m_nSize )
  {
    m_nSize = this->m_nSize;
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
      (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)this,
      nNewSize: m_nSize + nCount,
      nGrowBy: -1);
    ATL::Checked::memmove_s(
      _S1: &this->m_pData[nCount + nIndex],
      _S1max: 4 * (m_nSize - nIndex),
      _S2: &this->m_pData[nIndex],
      _N: 4 * (m_nSize - nIndex));
    memset(dst: (int)&this->m_pData[nIndex], value: nullptr, count: 4 * nCount);
    v4 = nIndex;
  }
  else
  {
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
      (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)this,
      nNewSize: nIndex + nCount,
      nGrowBy: -1);
  }
  v8 = v4;
  do
  {
    this->m_pData[v8++] = *newElement;
    --v6;
  }
  while ( v6 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x1036C28B
// Name: public: virtual CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const __near &>::~CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const __near &>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &>::~CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &>(
        CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &> *this)
{
  CArchive::LoadArrayObjType *m_pData; // ecx

  this->__vftable = (CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &>_vtbl *)&CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &>::`vftable';
  m_pData = this->m_pData;
  if ( m_pData != nullptr )
    operator delete(p: m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x1036C791
// Name: public: virtual void CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const __near &>::Serialize(class CArchive __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &>::Serialize(
        CArray<unsigned long,unsigned long> *this,
        CArchive *ar)
{
  int Count; // eax

  if ( (ar->m_nMode & 1) != 0 )
  {
    Count = CArchive::ReadCount(this: ar);
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
      (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)this,
      nNewSize: Count,
      nGrowBy: -1);
  }
  else
  {
    CArchive::WriteCount(this: ar, dwCount: this->m_nSize);
  }
  SerializeElements<long>(ar, pElements: (CDocument **)this->m_pData, nCount: this->m_nSize);
}

//------------------------------------------------------------------------------
// Address: 0x10389DC3
// Name: public: virtual CArray<unsigned long,unsigned long>::~CArray<unsigned long,unsigned long>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<unsigned long,unsigned long>::~CArray<unsigned long,unsigned long>(
        CArray<unsigned long,unsigned long> *this)
{
  unsigned int *m_pData; // ecx

  this->__vftable = (CArray<unsigned long,unsigned long>_vtbl *)&CArray<unsigned long,unsigned long>::`vftable';
  m_pData = this->m_pData;
  if ( m_pData != nullptr )
    operator delete(p: m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x103C5C7A
// Name: public: void CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *>::RemoveAt(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::RemoveAt(
        CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *this,
        int nIndex,
        int nCount)
{
  int v4; // ecx
  int m_nSize; // eax
  int v6; // eax

  v4 = nIndex + nCount;
  if ( nIndex < 0 || nCount < 0 || (m_nSize = this->m_nSize, v4 > m_nSize) || v4 < nIndex || v4 < nCount )
    AfxThrowInvalidArgException();
  v6 = m_nSize - v4;
  if ( v6 != 0 )
    ATL::Checked::memmove_s(_S1: &this->m_pData[nIndex], _S1max: 4 * v6, _S2: &this->m_pData[v4], _N: 4 * v6);
  this->m_nSize -= nCount;
}

//------------------------------------------------------------------------------
// Address: 0x103C5CD2
// Name: public: virtual CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *>::~CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::~CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>(
        CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *this)
{
  CMFCRibbonBaseElement **m_pData; // ecx

  this->__vftable = (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>_vtbl *)&CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::`vftable';
  m_pData = this->m_pData;
  if ( m_pData != nullptr )
    operator delete(p: m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x103C5CE7
// Name: public: virtual CArray<int,int>::~CArray<int,int>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<int,int>::~CArray<int,int>(CArray<int,int> *this)
{
  int *m_pData; // ecx

  this->__vftable = (CArray<int,int>_vtbl *)&CArray<int,int>::`vftable';
  m_pData = this->m_pData;
  if ( m_pData != nullptr )
    operator delete(p: m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x103C63A0
// Name: public: void CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *>::InsertAt(int,class CMFCRibbonBaseElement __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::InsertAt(
        CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *this,
        int nIndex,
        CMFCRibbonBaseElement *newElement,
        int nCount)
{
  int v4; // esi
  int v6; // ebx
  int m_nSize; // esi
  int v8; // eax

  v4 = nIndex;
  if ( nIndex < 0 || (v6 = nCount, nCount <= 0) )
    AfxThrowInvalidArgException();
  if ( nIndex < this->m_nSize )
  {
    m_nSize = this->m_nSize;
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
      (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)this,
      nNewSize: m_nSize + nCount,
      nGrowBy: -1);
    ATL::Checked::memmove_s(
      _S1: &this->m_pData[nCount] + nIndex,
      _S1max: 4 * (m_nSize - nIndex),
      _S2: &this->m_pData[nIndex],
      _N: 4 * (m_nSize - nIndex));
    memset(dst: (int)&this->m_pData[nIndex], value: nullptr, count: 4 * nCount);
    v4 = nIndex;
  }
  else
  {
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
      (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)this,
      nNewSize: nIndex + nCount,
      nGrowBy: -1);
  }
  v8 = v4;
  do
  {
    this->m_pData[v8++] = newElement;
    --v6;
  }
  while ( v6 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x103DE70B
// Name: public: virtual CArray<class CMFCRibbonPanel __near *,class CMFCRibbonPanel __near *>::~CArray<class CMFCRibbonPanel __near *,class CMFCRibbonPanel __near *>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<CMFCRibbonPanel *,CMFCRibbonPanel *>::~CArray<CMFCRibbonPanel *,CMFCRibbonPanel *>(
        CArray<CMFCRibbonPanel *,CMFCRibbonPanel *> *this)
{
  CMFCRibbonPanel **m_pData; // ecx

  this->__vftable = (CArray<CMFCRibbonPanel *,CMFCRibbonPanel *>_vtbl *)&CArray<CMFCRibbonPanel *,CMFCRibbonPanel *>::`vftable';
  m_pData = this->m_pData;
  if ( m_pData != nullptr )
    operator delete(p: m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x103DE776
// Name: public: void CArray<class CMFCRibbonKeyTip __near *,class CMFCRibbonKeyTip __near *>::SetAtGrow(int,class CMFCRibbonKeyTip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *this,
        int nIndex,
        CMFCRibbonKeyTip *newElement)
{
  if ( nIndex < 0 )
    AfxThrowInvalidArgException();
  if ( nIndex >= this->m_nSize )
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(this, nNewSize: nIndex + 1, nGrowBy: -1);
  this->m_pData[nIndex] = newElement;
}

//------------------------------------------------------------------------------
// Address: 0x103DEAD3
// Name: public: void CArray<int,int>::Copy(class CArray<int,int> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<int,int>::Copy(CArray<int,int> *this, const CArray<int,int> *src)
{
  if ( this != src )
  {
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
      (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)this,
      nNewSize: src->m_nSize,
      nGrowBy: -1);
    CopyElements<int>(pDest: this->m_pData, pSrc: src->m_pData, nCount: src->m_nSize);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10419566
// Name: public: class CArray<int,int> const __near & CBaseTabbedPane::GetDefaultTabsOrder(void)
// Source: json
//------------------------------------------------------------------------------
const CArray<int,int> *__thiscall CBaseTabbedPane::GetDefaultTabsOrder(CBaseTabbedPane *this)
{
  if ( this->m_arDefaultTabsOrder.m_nSize == 0 )
    CBaseTabbedPane::FillDefaultTabsOrderArray(this);
  return &this->m_arDefaultTabsOrder;
}

//------------------------------------------------------------------------------
// Address: 0x1042BBA7
// Name: public: virtual CArray<long,long>::~CArray<long,long>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArray<long,long>::~CArray<long,long>(CArray<long,long> *this)
{
  int *m_pData; // ecx

  this->__vftable = (CArray<long,long>_vtbl *)&CArray<long,long>::`vftable';
  m_pData = this->m_pData;
  if ( m_pData != nullptr )
    operator delete(p: m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x10002770
// Name: void SerializeElements<struct error3d>(class CArchive __near &,struct error3d __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SerializeElements<error3d>(CArchive *ar, error3d *pElements, error3d *nCount)
{
  unsigned int v3; // ebx
  int v4; // edi
  int v5; // edi
  error3d *pData; // [esp+1Ch] [ebp+10h]

  v3 = (unsigned int)nCount;
  if ( nCount != nullptr && pElements == nullptr )
    AfxThrowInvalidArgException();
  pData = pElements;
  if ( (ar->m_nMode & 1) != 0 )
  {
    for ( ; v3 != 0; v3 -= v5 )
    {
      v5 = v3;
      if ( v3 >= 0xAAAAAAA )
        v5 = 178956970;
      if ( CArchive::Read(this: ar, lpBuf: (char *)pData, nMax: 12 * v5) != 12 * v5 )
        AfxThrowArchiveException(cause: 3, lpszArchiveName: nullptr);
      pData += v5;
    }
  }
  else
  {
    for ( ; v3 != 0; v3 -= v4 )
    {
      v4 = v3;
      if ( v3 >= 0xAAAAAAA )
        v4 = 178956970;
      CArchive::Write(this: ar, lpBuf: (char *)pData, nMax: 12 * v4);
      pData += v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E110
// Name: void SerializeElements<struct CCOMMAND>(class CArchive __near &,struct CCOMMAND __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall SerializeElements<CCOMMAND>(CArchive *ar, CCOMMAND *pElements, CCOMMAND *nCount)
{
  unsigned int v3; // edi
  int v4; // ebx
  int v5; // ebx
  CCOMMAND *pData; // [esp+1Ch] [ebp+10h]

  v3 = (unsigned int)nCount;
  if ( nCount != nullptr && pElements == nullptr )
    AfxThrowInvalidArgException();
  pData = pElements;
  if ( (ar->m_nMode & 1) != 0 )
  {
    for ( ; v3 != 0; v3 -= v5 )
    {
      v5 = v3;
      if ( v3 >= 0x28C197 )
        v5 = 2670999;
      if ( CArchive::Read(this: ar, lpBuf: (char *)pData, nMax: 804 * v5) != 804 * v5 )
        AfxThrowArchiveException(cause: 3, lpszArchiveName: nullptr);
      pData += v5;
    }
  }
  else
  {
    for ( ; v3 != 0; v3 -= v4 )
    {
      v4 = v3;
      if ( v3 >= 0x28C197 )
        v4 = 2670999;
      CArchive::Write(this: ar, lpBuf: (char *)pData, nMax: 804 * v4);
      pData += v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103417E0
// Name: public: CList<struct HWND__ __near *,struct HWND__ __near *>::CList<struct HWND__ __near *,struct HWND__ __near *>(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<HWND__ *,HWND__ *> *__thiscall CList<HWND__ *,HWND__ *>::CList<HWND__ *,HWND__ *>(
        CList<HWND__ *,HWND__ *> *this,
        int nBlockSize)
{
  this->m_nCount = 0;
  this->m_pNodeFree = nullptr;
  this->m_pNodeTail = nullptr;
  this->m_pNodeHead = nullptr;
  this->m_pBlocks = nullptr;
  this->__vftable = (CList<HWND__ *,HWND__ *>_vtbl *)&CList<HWND__ *,HWND__ *>::`vftable';
  this->m_nBlockSize = nBlockSize;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10341808
// Name: public: virtual CList<struct HWND__ __near *,struct HWND__ __near *>::~CList<struct HWND__ __near *,struct HWND__ __near *>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CList<HWND__ *,HWND__ *>::~CList<HWND__ *,HWND__ *>(CList<HWND__ *,HWND__ *> *this)
{
  this->__vftable = (CList<HWND__ *,HWND__ *>_vtbl *)&CList<HWND__ *,HWND__ *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll((CList<HWND__ *,HWND__ * &> *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10349B47
// Name: protected: static class CFrameWnd __near * CCmdTarget::GetRoutingFrame_(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFrameWnd *__stdcall CCmdTarget::GetRoutingFrame_()
{
  return AfxGetThreadState()->m_pRoutingFrame;
}

//------------------------------------------------------------------------------
// Address: 0x1034FD5D
// Name: protected: long CStatusBar::OnGetText(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CStatusBar::OnGetText(CStatusBar *this, signed int wParam, void *lParam)
{
  signed int v3; // esi
  int v6; // eax
  _DWORD *v7; // eax

  v3 = 0;
  if ( wParam == 0 )
    return 0;
  v6 = CStatusBar::CommandToIndex(this, nIDFind: 0);
  if ( v6 >= 0 )
  {
    v7 = *((_DWORD **)this->m_pData + 5 * v6 + 4);
    v3 = *(v7 - 3);
    if ( v3 > wParam )
      v3 = wParam - 1;
    ATL::Checked::memcpy_s(_S1: lParam, _S1max: wParam, _S2: v7, _N: v3);
  }
  *((_BYTE *)lParam + v3) = 0;
  return v3 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x1034FDB3
// Name: protected: long CStatusBar::OnGetTextLength(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CStatusBar::OnGetTextLength(CStatusBar *this, unsigned int __formal, unsigned int __formala)
{
  int v3; // edi
  int v5; // eax

  v3 = 0;
  v5 = CStatusBar::CommandToIndex(this, nIDFind: 0);
  if ( v5 >= 0 )
    return *(_DWORD *)(*((_DWORD *)this->m_pData + 5 * v5 + 4) - 12);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1034FE1E
// Name: public: int CStatusBar::AllocElements(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CStatusBar::AllocElements(CStatusBar *this, int nElements, int cbElement)
{
  int v4; // ebx
  _DWORD *v5; // edi
  int result; // eax
  int v7; // edi
  ATL::CSimpleStringT<char,0> *v8; // ebx
  ATL::IAtlStringMgr *StringManager; // eax

  v4 = 0;
  if ( this->m_nCount > 0 )
  {
    v5 = (char *)this->m_pData + 16;
    do
    {
      ATL::CStringData::Release(this: (ATL::CStringData *)(*v5 - 16));
      v5 += 5;
      ++v4;
    }
    while ( v4 < this->m_nCount );
  }
  result = CControlBar::AllocElements(this, nElements, cbElement);
  if ( result != 0 )
  {
    v7 = 0;
    if ( this->m_nCount > 0 )
    {
      v8 = (ATL::CSimpleStringT<char,0> *)((char *)this->m_pData + 16);
      do
      {
        if ( v8 != nullptr )
        {
          StringManager = AfxGetStringManager();
          ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: v8, pStringMgr: StringManager);
        }
        v8 += 5;
        ++v7;
      }
      while ( v7 < this->m_nCount );
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034FE9C
// Name: public: virtual CStatusBar::~CStatusBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CStatusBar::~CStatusBar(CStatusBar *this)
{
  this->__vftable = (CStatusBar_vtbl *)&CStatusBar::`vftable';
  CStatusBar::AllocElements(this, nElements: 0, cbElement: 0);
  CControlBar::~CControlBar(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034FEF1
// Name: public: int CStatusBar::SetPaneText(int,char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CStatusBar::SetPaneText(CStatusBar *this, int nIndex, const char *lpszNewText, int bUpdate)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v5; // esi
  bool v6; // zf
  ATL::CSimpleStringT<char,0> *v7; // ecx
  int m_pszData; // edi

  v5 = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)((char *)this->m_pData + 20 * nIndex);
  if ( ((int)v5[3].m_pszData & 1) != 0
    || (lpszNewText != nullptr
      ? (v6 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(this: v5 + 4, psz: lpszNewText) == 0)
      : (v6 = *((_DWORD *)v5[4].m_pszData - 3) == 0),
        !v6) )
  {
    v7 = v5 + 4;
    if ( lpszNewText != nullptr )
      ATL::CSimpleStringT<char,0>::SetString(this: v7, pszSrc: lpszNewText);
    else
      ATL::CSimpleStringT<char,0>::Empty(this: v7);
    if ( bUpdate == 0 )
    {
      v5[3].m_pszData = (char *)((int)v5[3].m_pszData | 1);
      return 1;
    }
    v5[3].m_pszData = (char *)((int)v5[3].m_pszData & ~1u);
    if ( ((int)v5[2].m_pszData & 0x4000000) != 0 )
      m_pszData = 0;
    else
      m_pszData = (int)v5[4].m_pszData;
    this->DefWindowProcA(this, a2: 1025u, a3: nIndex | LOWORD(v5[2].m_pszData), a4: m_pszData);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1034FF9F
// Name: protected: long CStatusBar::OnSetText(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CStatusBar::OnSetText(CStatusBar *this, unsigned int __formal, const char *lParam)
{
  int v4; // eax

  v4 = CStatusBar::CommandToIndex(this, nIDFind: 0);
  if ( v4 >= 0 )
    return (CStatusBar::SetPaneText(this, nIndex: v4, lpszNewText: lParam, bUpdate: 1) != 0) - 1;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1034FFD0
// Name: public: virtual void CStatusCmdUI::SetText(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CStatusCmdUI::SetText(CStatusCmdUI *this, const char *lpszText)
{
  CStatusBar::SetPaneText(this: (CStatusBar *)this->m_pOther, nIndex: this->m_nIndex, lpszNewText: lpszText, bUpdate: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1034FFE9
// Name: protected: void CStatusBar::UpdateAllPanes(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CStatusBar::UpdateAllPanes(CStatusBar *this, int bUpdateRects, int bUpdateText)
{
  int v3; // ebx
  int m_nCount; // eax
  int v6; // edi
  char *m_pData; // ecx
  _DWORD *v8; // ecx
  int v9; // edx
  char *v10; // ecx
  char *v11; // edx
  int v12; // eax
  CMFCRibbonKeyTip *v13; // ecx
  int v14; // eax
  const char **v15; // edi
  HWND__ *m_hWnd; // [esp-8h] [ebp-64h]
  CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> v17; // [esp+10h] [ebp-4Ch] BYREF
  int v18; // [esp+24h] [ebp-38h]
  int v19; // [esp+28h] [ebp-34h]
  _DWORD *i; // [esp+2Ch] [ebp-30h]
  tagRECT Rect; // [esp+30h] [ebp-2Ch] BYREF
  char *v22; // [esp+40h] [ebp-1Ch] BYREF
  int v23; // [esp+48h] [ebp-14h]
  int v24; // [esp+58h] [ebp-4h]

  v3 = 0;
  if ( bUpdateRects != 0 )
  {
    m_hWnd = this->m_hWnd;
    memset(&Rect, 0, sizeof(Rect));
    GetWindowRect(hWnd: m_hWnd, lpRect: &Rect);
    OffsetRect(lprc: &Rect, dx: -Rect.left, dy: -Rect.top);
    this->CalcInsideRect(this, a2: (CRect *)&Rect, a3: 1);
    this->DefWindowProcA(this, a2: 1031u, a3: 0, a4: (int)&v22);
    m_nCount = this->m_nCount;
    v6 = v23 + Rect.right - Rect.left;
    m_pData = (char *)this->m_pData;
    v19 = 0;
    if ( m_nCount > 0 )
    {
      v8 = m_pData + 4;
      for ( i = (_DWORD *)m_nCount; i != nullptr; i = (_DWORD *)((char *)i - 1) )
      {
        if ( (v8[1] & 0x8000000) != 0 )
          ++v19;
        v9 = -6 - *v8;
        v8 += 5;
        v6 += v9 - v23;
      }
    }
    v17.__vftable = (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>_vtbl *)&CArray<int,int const &>::`vftable';
    memset(&v17.m_pData, 0, 16);
    v24 = 0;
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(this: &v17, nNewSize: m_nCount, nGrowBy: -1);
    v10 = v22;
    v11 = (char *)this->m_pData;
    v12 = 0;
    v18 = 0;
    if ( this->m_nCount > 0 )
    {
      i = v11 + 8;
      do
      {
        v13 = (CMFCRibbonKeyTip *)&v10[*(i - 1) + 6];
        if ( (*i & 0x8000000) != 0 && v6 > 0 )
        {
          v14 = v6 / v19;
          v13 = (CMFCRibbonKeyTip *)((char *)v13 + v6 / v19--);
          v6 -= v14;
          v12 = v18;
          v3 = 0;
        }
        if ( v12 < 0 || v12 >= v17.m_nSize )
          AfxThrowInvalidArgException();
        i += 5;
        v17.m_pData[v12] = v13;
        v10 = (char *)v13 + v23;
        v18 = ++v12;
      }
      while ( v12 < this->m_nCount );
    }
    this->DefWindowProcA(this, a2: 1028u, a3: this->m_nCount, a4: (int)v17.m_pData);
    v24 = -1;
    CArray<int,int const &>::~CArray<int,int const &>(this: (CArray<int,int const &> *)&v17);
  }
  if ( bUpdateText != 0 && this->m_nCount > 0 )
  {
    v15 = (const char **)((char *)this->m_pData + 16);
    do
    {
      if ( (*(_BYTE *)(v15 - 1) & 1) != 0 )
        CStatusBar::SetPaneText(this, nIndex: v3, lpszNewText: *v15, bUpdate: 1);
      v15 += 5;
      ++v3;
    }
    while ( v3 < this->m_nCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10350185
// Name: public: void CStatusBar::SetPaneStyle(int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CStatusBar::SetPaneStyle(CStatusBar *this, int nIndex, unsigned int nStyle)
{
  _DWORD *v4; // esi
  int v5; // eax
  const char *v6; // [esp-8h] [ebp-14h]

  v4 = (char *)this->m_pData + 20 * nIndex;
  v5 = v4[2];
  if ( v5 != nStyle )
  {
    if ( ((nStyle ^ v5) & 0x8000000) != 0 )
    {
      v4[2] = nStyle;
      CStatusBar::UpdateAllPanes(this, bUpdateRects: 1, bUpdateText: 0);
    }
    v4[3] |= 1u;
    v6 = (const char *)v4[4];
    v4[2] = nStyle;
    CStatusBar::SetPaneText(this, nIndex, lpszNewText: v6, bUpdate: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103501D7
// Name: public: void CStatusBar::SetPaneInfo(int,unsigned int,unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CStatusBar::SetPaneInfo(
        CStatusBar *this,
        int nIndex,
        unsigned int nID,
        unsigned int nStyle,
        int cxWidth)
{
  _DWORD *v6; // esi
  int v7; // eax
  const char *v8; // [esp-8h] [ebp-18h]
  int bChanged; // [esp+Ch] [ebp-4h]

  bChanged = 0;
  v6 = (char *)this->m_pData + 20 * nIndex;
  *v6 = nID;
  v7 = v6[2];
  if ( v7 != nStyle )
  {
    if ( ((nStyle ^ v7) & 0x8000000) != 0 )
    {
      bChanged = 1;
    }
    else
    {
      v6[3] |= 1u;
      v8 = (const char *)v6[4];
      v6[2] = nStyle;
      CStatusBar::SetPaneText(this, nIndex, lpszNewText: v8, bUpdate: 1);
    }
    v6[2] = nStyle;
  }
  if ( cxWidth != v6[1] )
  {
    v6[1] = cxWidth;
    bChanged = 1;
  }
  if ( bChanged != 0 )
    CStatusBar::UpdateAllPanes(this, bUpdateRects: 1, bUpdateText: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10350254
// Name: protected: void CStatusBar::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CStatusBar::OnPaint(CStatusBar *this)
{
  CStatusBar::UpdateAllPanes(this, bUpdateRects: 0, bUpdateText: 1);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1035026A
// Name: protected: void CStatusBar::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CStatusBar::OnSize(CStatusBar *this, unsigned int nType, unsigned int cx, int cy)
{
  CWnd::Default(this);
  CStatusBar::UpdateAllPanes(this, bUpdateRects: 1, bUpdateText: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103C5D3E
// Name: public: CMFCRibbonButton::CMFCRibbonButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonButton *__thiscall CMFCRibbonButton::CMFCRibbonButton(CMFCRibbonButton *this)
{
  CMFCRibbonBaseElement::CMFCRibbonBaseElement(this);
  this->__vftable = (CMFCRibbonButton_vtbl *)&CMFCRibbonButton::`vftable';
  this->m_sizeTextRight.cx = 0;
  this->m_sizeTextRight.cy = 0;
  this->m_sizeTextBottom.cx = 0;
  this->m_sizeTextBottom.cy = 0;
  this->m_szMargin.cx = 0;
  this->m_szMargin.cy = 0;
  this->m_rectMenu.left = 0;
  this->m_rectMenu.top = 0;
  this->m_rectMenu.right = 0;
  this->m_rectMenu.bottom = 0;
  this->m_rectCommand.left = 0;
  this->m_rectCommand.top = 0;
  this->m_rectCommand.right = 0;
  this->m_rectCommand.bottom = 0;
  this->m_arWordIndexes.__vftable = (CArray<int,int>_vtbl *)&CArray<int,int>::`vftable';
  this->m_arWordIndexes.m_pData = nullptr;
  this->m_arWordIndexes.m_nGrowBy = 0;
  this->m_arWordIndexes.m_nMaxSize = 0;
  this->m_arWordIndexes.m_nSize = 0;
  this->m_arSubItems.__vftable = (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>_vtbl *)&CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::`vftable';
  this->m_arSubItems.m_pData = nullptr;
  this->m_arSubItems.m_nGrowBy = 0;
  this->m_arSubItems.m_nMaxSize = 0;
  this->m_arSubItems.m_nSize = 0;
  CMFCRibbonButton::CommonInit(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103C5DF3
// Name: public: virtual int CMFCRibbonBaseElement::IsHighlighted(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonBaseElement::IsHighlighted(CMFCRibbonBaseElement *this)
{
  return this->m_bIsHighlighted;
}

//------------------------------------------------------------------------------
// Address: 0x103C5DF7
// Name: public: virtual int CMFCRibbonBaseElement::IsFocused(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonBaseElement::IsFocused(CMFCRibbonBaseElement *this)
{
  return this->m_bIsFocused;
}

//------------------------------------------------------------------------------
// Address: 0x103C5DFB
// Name: public: virtual int CMFCRibbonBaseElement::IsPressed(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonBaseElement::IsPressed(CMFCRibbonBaseElement *this)
{
  return this->m_bIsPressed;
}

//------------------------------------------------------------------------------
// Address: 0x103C5DFF
// Name: public: virtual int CBasePane::IsRestoredFromRegistry(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CBasePane::IsRestoredFromRegistry(CBasePane *this)
{
  return this->m_bIsRestoredFromRegistry;
}

//------------------------------------------------------------------------------
// Address: 0x103C5E03
// Name: public: virtual void CMFCRibbonBaseElement::SetCompactMode(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBaseElement::SetCompactMode(CMFCRibbonBaseElement *this, int bCompactMode)
{
  int v3; // eax
  CMFCRibbonBaseElement_vtbl *v4; // eax

  if ( bCompactMode == 0 )
  {
    if ( this->m_bCompactMode == 0 )
      return;
    v3 = this->HasIntermediateMode(this);
    this->m_bCompactMode = 0;
    if ( v3 == 0 )
    {
LABEL_9:
      this->m_bIntermediateMode = 0;
      return;
    }
    goto LABEL_12;
  }
  if ( this->m_bCompactMode != 0 )
    return;
  v4 = this->__vftable;
  if ( this->m_bIntermediateMode != 0 )
  {
    if ( ((int (*)(void))v4->HasCompactMode)() == 0 )
      return;
    this->m_bCompactMode = 1;
    goto LABEL_9;
  }
  if ( ((int (*)(void))v4->HasIntermediateMode)() != 0 )
  {
    this->m_bCompactMode = 0;
LABEL_12:
    this->m_bIntermediateMode = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C5E5C
// Name: public: virtual int CMFCRibbonBaseElement::CanBeCompacted(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonBaseElement::CanBeCompacted(CMFCRibbonBaseElement *this)
{
  CMFCRibbonBaseElement_vtbl *v2; // eax

  if ( this->IsAlwaysLargeImage(this) != 0 || this->m_bCompactMode != 0 )
    return 0;
  v2 = this->__vftable;
  if ( this->m_bIntermediateMode != 0 )
    return v2->HasCompactMode(this);
  else
    return v2->HasIntermediateMode(this);
}

//------------------------------------------------------------------------------
// Address: 0x103C5E84
// Name: public: virtual class CSize CMFCRibbonBaseElement::GetSize(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCRibbonBaseElement::GetSize(CMFCRibbonBaseElement *this, CSize *result, CDC *pDC)
{
  CMFCRibbonBaseElement_vtbl *v3; // eax
  int *v4; // eax
  int v5; // edx
  _BYTE v7[8]; // [esp+0h] [ebp-18h] BYREF
  _BYTE v8[8]; // [esp+8h] [ebp-10h] BYREF
  _BYTE v9[8]; // [esp+10h] [ebp-8h] BYREF

  v3 = this->__vftable;
  if ( this->m_bIntermediateMode != 0 )
  {
    v4 = (int *)((int (__stdcall *)(_BYTE *, CDC *))v3->GetIntermediateSize)(a1: v9, a2: pDC);
  }
  else if ( this->m_bCompactMode != 0 )
  {
    v4 = (int *)((int (__stdcall *)(_BYTE *, CDC *))v3->GetCompactSize)(a1: v8, a2: pDC);
  }
  else
  {
    v4 = (int *)((int (__stdcall *)(_BYTE *, CDC *))v3->GetRegularSize)(a1: v7, a2: pDC);
  }
  v5 = *v4;
  result->cy = v4[1];
  result->cx = v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C5EC9
// Name: public: virtual void CMFCRibbonBaseElement::SetInitialMode(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBaseElement::SetInitialMode(CMFCRibbonBaseElement *this, int bOneRow)
{
  this->m_bIntermediateMode = 0;
  this->m_bCompactMode = 0;
  if ( this->m_pParentGroup != nullptr || bOneRow != 0 )
  {
    if ( this->HasCompactMode(this) != 0 )
    {
      this->m_bCompactMode = 1;
    }
    else if ( this->HasIntermediateMode(this) != 0 )
    {
      this->m_bIntermediateMode = 1;
    }
  }
  else if ( this->HasLargeMode(this) == 0 )
  {
    this->m_bIntermediateMode = this->HasIntermediateMode(this) != 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C5F27
// Name: public: virtual int CMFCRibbonBaseElement::OnDrawMenuImage(class CDC __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonBaseElement::OnDrawMenuImage(CMFCRibbonBaseElement *this, CDC *pDC, CRect rect)
{
  ((void (__thiscall *)(CMFCRibbonBaseElement *, CDC *, int, int, int, int, int))this->DrawImage)(
    a1: this,
    a2: pDC,
    a3: 1,
    a4: rect.left,
    a5: rect.top,
    a6: rect.right,
    a7: rect.bottom);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103C5F4D
// Name: public: virtual unsigned int CMFCRibbonBaseElement::GetQuickAccessToolBarID(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonBaseElement::GetQuickAccessToolBarID(CMFCToolBarButton *this)
{
  return this->m_bExtraSize;
}

//------------------------------------------------------------------------------
// Address: 0x103C5F51
// Name: public: virtual int CMFCRibbonBaseElement::IsShowTooltipOnBottom(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCRibbonBaseElement::IsShowTooltipOnBottom(CMFCRibbonBaseElement *this)
{
  return this->m_pRibbonBar == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103C5F5A
// Name: public: virtual int CMFCRibbonButton::IsCommandAreaHighlighted(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCRibbonButton::IsCommandAreaHighlighted(CMFCRibbonButton *this)
{
  return this->m_bIsCommandHighlighted != 0 && this->IsHighlighted(this) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x103C5F73
// Name: public: virtual int CMFCRibbonButton::IsMenuAreaHighlighted(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCRibbonButton::IsMenuAreaHighlighted(CMFCRibbonButton *this)
{
  return this->m_bIsMenuHighlighted != 0 && this->IsHighlighted(this) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x103C5F8C
// Name: public: virtual int CMFCRibbonButton::IsAlwaysDrawBorder(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonButton::IsAlwaysDrawBorder(CMFCRibbonButton *this)
{
  return this->m_bForceDrawBorder;
}

//------------------------------------------------------------------------------
// Address: 0x103C5F93
// Name: public: virtual int CMFCRibbonButton::IsAlwaysLargeImage(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonButton::IsAlwaysLargeImage(CMFCRibbonButton *this)
{
  int result; // eax

  result = 0;
  if ( this->m_bIsAlwaysLarge != 0 || this->m_nLargeImageIndex >= 0 && this->m_nSmallImageIndex < 0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C5FB1
// Name: public: virtual int CMFCRibbonButton::HasLargeMode(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonButton::HasLargeMode(CMFCRibbonButton *this)
{
  CPoint *v1; // eax
  _BYTE v3[8]; // [esp+0h] [ebp-8h] BYREF

  v1 = (CPoint *)this->GetImageSize(this, result: v3, a3: 0);
  return CPoint::operator!=(this: v1, point: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103C5FD1
// Name: public: virtual int CMFCRibbonButton::HasCompactMode(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonButton::HasCompactMode(CMFCRibbonButton *this)
{
  CPoint *v1; // eax
  _BYTE v3[8]; // [esp+0h] [ebp-8h] BYREF

  v1 = (CPoint *)this->GetImageSize(this, result: v3, a3: 1);
  return CPoint::operator!=(this: v1, point: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103C5FF2
// Name: public: virtual void CMFCRibbonButton::CleanUpSizes(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonButton::CleanUpSizes(CMFCRibbonButton *this)
{
  this->m_sizeTextBottom.cx = 0;
  this->m_sizeTextBottom.cy = 0;
  this->m_sizeTextRight.cx = 0;
  this->m_sizeTextRight.cy = 0;
}

//------------------------------------------------------------------------------
// Address: 0x103C600F
// Name: protected: virtual void CMFCRibbonButton::SetMargin(class CSize const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonButton::SetMargin(CMFCRibbonButton *this, const CSize *sizeMargin)
{
  this->m_szMargin = *sizeMargin;
}

//------------------------------------------------------------------------------
// Address: 0x103C602C
// Name: public: virtual class CMFCRibbonBaseElement __near * CMFCRibbonBaseElement::GetLastTabStop(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonBaseElement::GetLastTabStop(CMFCRibbonBaseElement *this)
{
  if ( this->IsTabStop(this) == 0 || IsRectEmpty(lprc: &this->m_rect) )
    return nullptr;
  else
    return this;
}

//------------------------------------------------------------------------------
// Address: 0x103C643C
// Name: public: virtual void CMFCRibbonBaseElement::GetElements(class CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBaseElement::GetElements(
        CMFCRibbonBaseElement *this,
        CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *arElements)
{
  CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
    this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)arElements,
    nIndex: arElements->m_nSize,
    newElement: (CMFCRibbonKeyTip *)this);
}

//------------------------------------------------------------------------------
// Address: 0x103C6451
// Name: public: static class CObject __near * CMFCRibbonButton::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonButton *__stdcall CMFCRibbonButton::CreateObject()
{
  CMFCRibbonButton *v0; // ecx
  CMFCRibbonButton *result; // eax

  v0 = (CMFCRibbonButton *)operator new(nSize: 0x164u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCRibbonButton::CMFCRibbonButton(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C6481
// Name: public: virtual class CSize CMFCRibbonButton::GetRegularSize(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCRibbonButton::GetRegularSize(CMFCRibbonButton *this, CSize *result, CDC *pDC)
{
  int i; // edi
  CMFCRibbonBaseElement *v5; // ecx
  bool v6; // zf
  CMFCRibbonButton_vtbl *v7; // eax
  CSize *v8; // eax
  int cy; // ecx
  int GroupButtonExtraWidth; // eax
  int cx; // edx
  int v12; // ebx
  CMFCRibbonButton_vtbl *v13; // eax
  int v14; // edi
  int v15; // ecx
  int v16; // edx
  int v17; // eax
  int v18; // edi
  int v19; // ecx
  int v20; // ecx
  int v21; // eax
  int v22; // ebx
  unsigned int m_nID; // eax
  _DWORD v24[2]; // [esp+Ch] [ebp-18h] BYREF
  CSize sizeImageSmall; // [esp+14h] [ebp-10h] BYREF
  CSize sizeImageLarge; // [esp+1Ch] [ebp-8h] BYREF
  int cxExtra; // [esp+30h] [ebp+Ch]

  for ( i = 0; i < this->m_arSubItems.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arSubItems.m_nSize )
      AfxThrowInvalidArgException();
    v5 = this->m_arSubItems.m_pData[i];
    v5->SetParentCategory(this: v5, a2: this->m_pParent);
  }
  if ( this->m_bQuickAccessMode != 0 || this->m_bFloatyMode != 0 )
  {
    this->GetCompactSize(this, result, a3: pDC);
    return result;
  }
  v6 = this->HasLargeMode(this) == 0;
  v7 = this->__vftable;
  if ( v6 )
  {
    v7->GetIntermediateSize(this, result, a3: pDC);
    return result;
  }
  v7->GetImageSize(this, result: &sizeImageLarge, a3: RibbonImageLarge);
  this->GetImageSize(this, result: &sizeImageSmall, a3: RibbonImageSmall);
  if ( this->IsApplicationButton(this) != 0 )
  {
    v8 = result;
    result->cx = sizeImageLarge.cx;
    cy = sizeImageLarge.cy;
LABEL_12:
    v8->cy = cy;
    return v8;
  }
  GroupButtonExtraWidth = CMFCRibbonButton::GetGroupButtonExtraWidth(this);
  cx = sizeImageLarge.cx;
  v12 = sizeImageLarge.cy;
  cxExtra = GroupButtonExtraWidth;
  if ( sizeImageLarge.cx != 0 || sizeImageLarge.cy != 0 )
  {
    if ( this->m_bTextAlwaysOnRight == 0 )
    {
      v13 = this->__vftable;
      v24[0] = 5;
      v24[1] = 1;
      v13->SetMargin(this, a2: (const CSize *)v24);
      if ( this->IsDefaultPanelButton(this) != 0 )
        sizeImageLarge.cx += 2 * this->m_szMargin.cx + 2;
      v14 = sizeImageLarge.cx + 2 * this->m_szMargin.cx;
      if ( v14 <= this->m_sizeTextBottom.cx + 5 )
        v14 = this->m_sizeTextBottom.cx + 5;
      if ( this->IsDefaultPanelButton(this) != 0 )
        v14 += 2;
      if ( this->m_bIsDefaultMenuLook != 0 )
        v14 += 6;
      v15 = sizeImageLarge.cy;
      v16 = this->m_sizeTextBottom.cy;
      if ( v16 <= sizeImageLarge.cy + 1 )
        v16 = sizeImageLarge.cy + 1;
      v8 = result;
      result->cx = cxExtra + v14;
      cy = v16 + v15 + 1;
      goto LABEL_12;
    }
  }
  else if ( this->m_bTextAlwaysOnRight == 0 )
  {
LABEL_31:
    v17 = this->m_szMargin.cx;
    v18 = sizeImageSmall.cx + 2 * v17;
    v19 = this->m_sizeTextRight.cx;
    if ( v19 > 0 )
    {
      v18 += v17 + v19;
      if ( (cx != 0 || v12 != 0) && this->m_bTextAlwaysOnRight != 0 )
        v18 += v17;
    }
    if ( (cx != 0 || v12 != 0) && this->m_bTextAlwaysOnRight != 0 )
      v18 += v17;
    v20 = this->m_sizeTextRight.cy;
    if ( sizeImageSmall.cy > v20 )
      v20 = sizeImageSmall.cy;
    v21 = 2 * this->m_szMargin.cy;
    v22 = v21 + v20;
    if ( sizeImageSmall.cy == 0 )
      v22 += v21;
    if ( this->HasMenu(this) != 0 )
    {
      v18 += this->GetDropDownImageWidth(this);
      if ( this->m_bIsDefaultCommand != 0 )
      {
        m_nID = this->m_nID;
        if ( m_nID != -1 && m_nID != 0 && this->m_sizeTextRight.cx > 0 )
          v18 += this->m_nMenuArrowMargin;
      }
    }
    if ( this->m_bIsDefaultMenuLook != 0 && this->m_bQuickAccessMode == 0 )
      v18 += 6;
    result->cx = cxExtra + v18;
    result->cy = v22;
    return result;
  }
  if ( sizeImageLarge.cx != 0 || sizeImageLarge.cy != 0 )
  {
    sizeImageSmall.cx = sizeImageLarge.cx + 2;
    sizeImageSmall.cy = sizeImageLarge.cy + 2;
    this->m_szMargin.cy = 5;
  }
  goto LABEL_31;
}

//------------------------------------------------------------------------------
// Address: 0x103C66DD
// Name: public: virtual class CSize CMFCRibbonButton::GetCompactSize(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCRibbonButton::GetCompactSize(CMFCRibbonButton *this, CSize *result, CDC *__formal)
{
  int i; // edi
  CMFCRibbonBaseElement *v5; // ecx
  CSize *v6; // eax
  int cy; // ecx
  long double m_dblRibbonImageScale; // st6
  const CSize *v9; // eax
  long double v10; // st7
  long double v11; // st6
  long double v12; // st5
  bool v13; // c3
  long double v14; // st6
  double v15; // st6
  long double v16; // rt2
  int v17; // edi
  int v18; // eax
  int v19; // edx
  _DWORD v20[2]; // [esp+Ch] [ebp-24h] BYREF
  _DWORD v21[2]; // [esp+14h] [ebp-1Ch] BYREF
  CSize sizeImageSmall; // [esp+1Ch] [ebp-14h] BYREF
  int cxDropDown; // [esp+24h] [ebp-Ch]
  int v24; // [esp+28h] [ebp-8h] BYREF
  int cxExtra; // [esp+2Ch] [ebp-4h]

  for ( i = 0; i < this->m_arSubItems.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arSubItems.m_nSize )
      AfxThrowInvalidArgException();
    v5 = this->m_arSubItems.m_pData[i];
    v5->SetParentCategory(this: v5, a2: this->m_pParent);
  }
  this->GetImageSize(this, result: &sizeImageSmall, a3: RibbonImageSmall);
  if ( this->IsApplicationButton(this) != 0 )
  {
    v6 = result;
    result->cx = sizeImageSmall.cx;
    cy = sizeImageSmall.cy;
  }
  else
  {
    cxDropDown = this->GetDropDownImageWidth(this);
    cxExtra = 0;
    if ( this->m_bQuickAccessMode != 0 || this->m_bFloatyMode != 0 )
    {
      if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
        m_dblRibbonImageScale = afxGlobalData.m_dblRibbonImageScale;
      else
        m_dblRibbonImageScale = 1.0;
      if ( m_dblRibbonImageScale == 1.0 )
      {
        v20[0] = 3;
        v20[1] = 3;
        v9 = (const CSize *)v20;
      }
      else
      {
        v21[0] = 3;
        v21[1] = 2;
        v9 = (const CSize *)v21;
      }
      this->SetMargin(this, a2: v9);
      if ( sizeImageSmall.cx == 0 && sizeImageSmall.cy == 0 )
      {
        v10 = afxGlobalData.m_dblRibbonImageScale;
        sizeImageSmall.cx = 16;
        sizeImageSmall.cy = 16;
        if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
        {
          v11 = afxGlobalData.m_dblRibbonImageScale;
          v12 = 1.0;
        }
        else
        {
          v12 = 1.0;
          v11 = 1.0;
        }
        v13 = v12 == v11;
        v14 = v12;
        if ( !v13 )
        {
          if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
            v12 = afxGlobalData.m_dblRibbonImageScale;
          sizeImageSmall.cx = (int)(v12 * 16.0 + 0.5);
          if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
          {
            v15 = 0.5;
          }
          else
          {
            v16 = v14;
            v15 = 0.5;
            v10 = v16;
          }
          sizeImageSmall.cy = (int)(v10 * (double)sizeImageSmall.cy + v15);
        }
      }
    }
    else
    {
      v24 = 3;
      cxExtra = 3;
      this->SetMargin(this, a2: (const CSize *)&v24);
      cxExtra = CMFCRibbonButton::GetGroupButtonExtraWidth(this);
      if ( this->m_bIsDefaultMenuLook != 0 )
        cxExtra += 6;
    }
    v17 = 0;
    if ( this->HasMenu(this) != 0 )
    {
      v18 = this->m_szMargin.cx / 2;
      if ( this->m_bIsDefaultCommand != 0 )
        v17 = v18 + cxDropDown + 1;
      else
        v17 = cxDropDown - v18 - 1;
    }
    v19 = sizeImageSmall.cy;
    v6 = result;
    result->cx = cxExtra + sizeImageSmall.cx + v17 + 2 * this->m_szMargin.cx;
    cy = v19 + 2 * this->m_szMargin.cy;
  }
  v6->cy = cy;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x103C68C3
// Name: public: virtual class CSize CMFCRibbonButton::GetIntermediateSize(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCRibbonButton::GetIntermediateSize(CMFCRibbonButton *this, CSize *result, CDC *pDC)
{
  int v4; // ebx
  int i; // edi
  CMFCRibbonBaseElement *v6; // ecx
  int cy; // eax
  int v8; // edi
  int GroupButtonExtraWidth; // eax
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  _DWORD v14[2]; // [esp+Ch] [ebp-10h] BYREF
  CSize sizeImageSmall; // [esp+14h] [ebp-8h] BYREF

  v4 = 0;
  for ( i = 0; i < this->m_arSubItems.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arSubItems.m_nSize )
      AfxThrowInvalidArgException();
    v6 = this->m_arSubItems.m_pData[i];
    v6->SetParentCategory(this: v6, a2: this->m_pParent);
  }
  if ( this->m_bQuickAccessMode != 0 || this->m_bFloatyMode != 0 )
  {
    this->GetCompactSize(this, result, a3: pDC);
    return result;
  }
  else
  {
    v14[0] = 3;
    v14[1] = 3;
    this->SetMargin(this, a2: (const CSize *)v14);
    if ( this->HasMenu(this) != 0 )
      v4 = this->GetDropDownImageWidth(this);
    this->GetImageSize(this, result: &sizeImageSmall, a3: RibbonImageSmall);
    if ( sizeImageSmall.cy < 16 )
      sizeImageSmall.cy = 16;
    cy = this->m_sizeTextRight.cy;
    if ( sizeImageSmall.cy > cy )
      cy = sizeImageSmall.cy;
    v8 = cy + 2 * this->m_szMargin.cy;
    this->GetTextOffset(this);
    GroupButtonExtraWidth = CMFCRibbonButton::GetGroupButtonExtraWidth(this);
    v11 = sizeImageSmall.cx + this->m_sizeTextRight.cx + GroupButtonExtraWidth + v10 + 2 * this->m_szMargin.cx;
    v12 = v11 + v4 + 1;
    if ( this->m_bIsDefaultMenuLook != 0 )
      v12 = v11 + v4 + 7;
    result->cx = v12;
    result->cy = v8;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C69DC
// Name: public: virtual void CMFCRibbonButton::SetParentCategory(class CMFCRibbonCategory __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonButton::SetParentCategory(CMFCRibbonButton *this, CMFCRibbonCategory *pParent)
{
  int i; // ebx
  CMFCRibbonBaseElement *v4; // edi
  BOOL v5; // eax

  CMFCRibbonBaseElement::SetParentCategory(this, pParent);
  for ( i = 0; i < this->m_arSubItems.m_nSize; v4->m_bIsDefaultMenuLook = v5 )
  {
    if ( i < 0 || i >= this->m_arSubItems.m_nSize )
      AfxThrowInvalidArgException();
    v4 = this->m_arSubItems.m_pData[i];
    v4->SetParentCategory(this: v4, a2: this->m_pParent);
    v5 = CMFCRibbonButton::m_bUseMenuHandle == 0 && v4->HasLargeMode(this: v4) == 0;
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C6A4F
// Name: protected: virtual void CMFCRibbonButton::SetOriginal(class CMFCRibbonBaseElement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonButton::SetOriginal(CMFCRibbonButton *this, CMFCRibbonBaseElement *pOriginal)
{
  CObject *v3; // ebx
  int m_nSize; // eax
  int v5; // esi
  CMFCRibbonBaseElement *v6; // ecx

  CMFCRibbonBaseElement::SetOriginal(this, pOriginal);
  v3 = AfxDynamicDownCast(pClass: &CMFCRibbonButton::classCMFCRibbonButton, pObject: pOriginal);
  if ( v3 != nullptr )
  {
    m_nSize = this->m_arSubItems.m_nSize;
    if ( v3[86].__vftable == (CObject_vtbl *)m_nSize )
    {
      v5 = 0;
      if ( m_nSize > 0 )
      {
        do
        {
          if ( v5 < 0 || v5 >= this->m_arSubItems.m_nSize || v5 >= (int)v3[86].__vftable )
            AfxThrowInvalidArgException();
          v6 = this->m_arSubItems.m_pData[v5];
          v6->SetOriginal(this: v6, a2: *((CMFCRibbonBaseElement **)&v3[85].GetRuntimeClass + v5++));
        }
        while ( v5 < this->m_arSubItems.m_nSize );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C6ACE
// Name: public: void CMFCRibbonButton::AddSubItem(class CMFCRibbonBaseElement __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonButton::AddSubItem(CMFCRibbonButton *this, CMFCRibbonBaseElement *pSubItem, int nIndex)
{
  BOOL v4; // eax
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *p_m_arSubItems; // ecx

  pSubItem->SetParentCategory(this: pSubItem, a2: this->m_pParent);
  v4 = CMFCRibbonButton::m_bUseMenuHandle == 0 && pSubItem->HasLargeMode(this: pSubItem) == 0;
  pSubItem->m_bIsDefaultMenuLook = v4;
  p_m_arSubItems = &this->m_arSubItems;
  if ( nIndex == -1 )
    CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
      this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)p_m_arSubItems,
      nIndex: this->m_arSubItems.m_nSize,
      newElement: (CMFCRibbonKeyTip *)pSubItem);
  else
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::InsertAt(
      this: p_m_arSubItems,
      nIndex,
      newElement: pSubItem,
      nCount: 1);
}

//------------------------------------------------------------------------------
// Address: 0x103C6B2E
// Name: public: void CMFCRibbonButton::RemoveAllSubItems(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonButton::RemoveAllSubItems(CMFCRibbonButton *this)
{
  int i; // edi
  CMFCRibbonBaseElement *v3; // ecx

  for ( i = 0; i < this->m_arSubItems.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arSubItems.m_nSize )
      AfxThrowInvalidArgException();
    v3 = this->m_arSubItems.m_pData[i];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CMFCRibbonBaseElement *, int))v3->dtr_CObject)(a1: v3, a2: 1);
  }
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
    this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arSubItems,
    nNewSize: 0,
    nGrowBy: -1);
}

//------------------------------------------------------------------------------
// Address: 0x103C6B7F
// Name: protected: virtual int CMFCRibbonButton::AddToListBox(class CMFCRibbonCommandsListBox __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonButton::AddToListBox(
        CMFCRibbonButton *this,
        CMFCRibbonCommandsListBox *pWndListBox,
        int bDeep)
{
  int result; // eax
  int i; // edi
  CMFCRibbonBaseElement *v6; // ecx

  result = CMFCRibbonBaseElement::AddToListBox(this, pWndListBox, __formal: bDeep);
  if ( bDeep != 0 && this->m_bCreatedFromMenu == 0 )
  {
    for ( i = 0; i < this->m_arSubItems.m_nSize; ++i )
    {
      if ( i < 0 || i >= this->m_arSubItems.m_nSize )
        AfxThrowInvalidArgException();
      v6 = this->m_arSubItems.m_pData[i];
      if ( v6->m_nID != 0 )
        result = v6->AddToListBox(this: v6, a2: pWndListBox, a3: 1);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C6BE9
// Name: public: virtual void CMFCRibbonButton::ClosePopupMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonButton::ClosePopupMenu(CMFCRibbonButton *this)
{
  int i; // edi
  CMFCRibbonBaseElement *v3; // ecx

  for ( i = 0; i < this->m_arSubItems.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arSubItems.m_nSize )
      AfxThrowInvalidArgException();
    v3 = this->m_arSubItems.m_pData[i];
    v3->ClosePopupMenu(this: v3);
  }
  CMFCRibbonBaseElement::ClosePopupMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x103C6C2E
// Name: protected: virtual class CMFCRibbonBaseElement __near * CMFCRibbonButton::FindByID(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonButton::FindByID(CMFCRibbonButton *this, unsigned int uiCmdID)
{
  CMFCRibbonBaseElement *result; // eax
  int v4; // edi
  CMFCRibbonBaseElement *v5; // ecx

  result = CMFCRibbonBaseElement::FindByID(this, uiCmdID);
  if ( result == nullptr )
  {
    v4 = 0;
    if ( this->m_arSubItems.m_nSize <= 0 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        if ( v4 < 0 || v4 >= this->m_arSubItems.m_nSize )
          AfxThrowInvalidArgException();
        v5 = this->m_arSubItems.m_pData[v4];
        result = v5->FindByID(this: v5, a2: uiCmdID);
        if ( result != nullptr )
          break;
        if ( ++v4 >= this->m_arSubItems.m_nSize )
          return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C6C88
// Name: protected: virtual class CMFCRibbonBaseElement __near * CMFCRibbonButton::FindByData(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonButton::FindByData(CMFCRibbonButton *this, unsigned int dwData)
{
  CMFCRibbonBaseElement *result; // eax
  int v4; // edi
  CMFCRibbonBaseElement *v5; // ecx

  result = CMFCRibbonBaseElement::FindByData(this, dwData);
  if ( result == nullptr )
  {
    v4 = 0;
    if ( this->m_arSubItems.m_nSize <= 0 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        if ( v4 < 0 || v4 >= this->m_arSubItems.m_nSize )
          AfxThrowInvalidArgException();
        v5 = this->m_arSubItems.m_pData[v4];
        result = v5->FindByData(this: v5, a2: dwData);
        if ( result != nullptr )
          break;
        if ( ++v4 >= this->m_arSubItems.m_nSize )
          return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C6CE2
// Name: protected: virtual void CMFCRibbonButton::SetParentRibbonBar(class CMFCRibbonBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonButton::SetParentRibbonBar(CMFCRibbonButton *this, CMFCRibbonBar *pRibbonBar)
{
  int v3; // edi
  CMFCRibbonBaseElement *v4; // ecx

  v3 = 0;
  for ( this->m_pRibbonBar = pRibbonBar; v3 < this->m_arSubItems.m_nSize; ++v3 )
  {
    if ( v3 < 0 || v3 >= this->m_arSubItems.m_nSize )
      AfxThrowInvalidArgException();
    v4 = this->m_arSubItems.m_pData[v3];
    v4->SetParentRibbonBar(this: v4, a2: pRibbonBar);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C6D30
// Name: protected: virtual void CMFCRibbonButton::GetElementsByID(unsigned int,class CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonButton::GetElementsByID(
        CMFCRibbonButton *this,
        unsigned int uiCmdID,
        CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *arElements)
{
  int i; // edi
  CMFCRibbonBaseElement *v5; // ecx

  CMFCRibbonBaseElement::GetElementsByID(this, uiCmdID, arElements);
  for ( i = 0; i < this->m_arSubItems.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arSubItems.m_nSize )
      AfxThrowInvalidArgException();
    v5 = this->m_arSubItems.m_pData[i];
    v5->GetElementsByID(this: v5, a2: uiCmdID, a3: arElements);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C6D86
// Name: protected: virtual void CMFCRibbonButton::GetElements(class CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonButton::GetElements(
        CMFCRibbonButton *this,
        CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *arElements)
{
  int i; // edi
  CMFCRibbonBaseElement *v4; // ecx

  CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
    this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)arElements,
    nIndex: arElements->m_nSize,
    newElement: (CMFCRibbonKeyTip *)this);
  for ( i = 0; i < this->m_arSubItems.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arSubItems.m_nSize )
      AfxThrowInvalidArgException();
    v4 = this->m_arSubItems.m_pData[i];
    v4->GetElements(this: v4, a2: arElements);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C6DDC
// Name: public: virtual int CMFCRibbonButton::HasIntermediateMode(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCRibbonButton::HasIntermediateMode(CMFCRibbonButton *this)
{
  return *((_DWORD *)this->m_strText.m_pszData - 3) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x103C6DEA
// Name: public: virtual CMFCRibbonButton::~CMFCRibbonButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonButton::~CMFCRibbonButton(CMFCRibbonButton *this)
{
  this->__vftable = (CMFCRibbonButton_vtbl *)&CMFCRibbonButton::`vftable';
  CMFCRibbonButton::RemoveAllSubItems(this);
  if ( this->m_bAutodestroyMenu != 0 && this->m_hMenu != nullptr )
    DestroyMenu(hMenu: this->m_hMenu);
  if ( this->m_bAutoDestroyIcon != 0 )
  {
    if ( this->m_hIcon != nullptr )
      DestroyIcon(hIcon: this->m_hIcon);
    if ( this->m_bAutoDestroyIcon != 0 && this->m_hIconSmall != nullptr )
      DestroyIcon(hIcon: this->m_hIconSmall);
  }
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::~CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>(this: &this->m_arSubItems);
  CArray<int,int>::~CArray<int,int>(this: &this->m_arWordIndexes);
  CMFCRibbonBaseElement::~CMFCRibbonBaseElement(this);
}

//------------------------------------------------------------------------------
// Address: 0x103C6E88
// Name: public: virtual void CMFCRibbonButton::SetText(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonButton::SetText(CMFCRibbonButton *this, const char *lpszText)
{
  CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *p_m_arWordIndexes; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_strText; // ebx
  CMFCRibbonKeyTip *i; // eax
  CMFCRibbonKeyTip *v6; // esi

  CMFCRibbonBaseElement::SetText(this, lpszText);
  this->m_sizeTextRight.cy = 0;
  this->m_sizeTextBottom.cy = 0;
  p_m_arWordIndexes = (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arWordIndexes;
  this->m_sizeTextRight.cx = 0;
  this->m_sizeTextBottom.cx = 0;
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
    this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arWordIndexes,
    nNewSize: 0,
    nGrowBy: -1);
  p_m_strText = &this->m_strText;
  for ( i = (CMFCRibbonKeyTip *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(
                                  this: &this->m_strText,
                                  ch: 32,
                                  iStart: 0);
        ;
        i = (CMFCRibbonKeyTip *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(
                                  this: p_m_strText,
                                  ch: 32,
                                  iStart: (int)&v6->__vftable + 1) )
  {
    v6 = i;
    if ( (int)i < 0 )
      break;
    CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
      this: p_m_arWordIndexes,
      nIndex: p_m_arWordIndexes->m_nSize,
      newElement: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C6EF0
// Name: protected: virtual void CMFCRibbonButton::OnDrawOnList(class CDC __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int,class CRect,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonButton::OnDrawOnList(
        CMFCRibbonButton *this,
        CDC *pDC,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strText,
        int nTextOffset,
        tagRECT rect,
        int __formal,
        int bHighlighted)
{
  int m_bIsDisabled; // eax
  int v9; // eax
  CMFCVisualManager *Instance; // eax
  CMFCRibbonButton_vtbl *v11; // eax
  BOOL v12; // esi
  DWORD SysColor; // eax
  long double m_dblRibbonImageScale; // st6
  int v15; // [esp+10h] [ebp-6Ch]
  int v16; // [esp+14h] [ebp-68h] BYREF
  int v17; // [esp+18h] [ebp-64h]
  CSize sizeImageDest; // [esp+1Ch] [ebp-60h] BYREF
  CMenuImages::IMAGES_IDS id; // [esp+24h] [ebp-58h]
  CDC *pDCa; // [esp+28h] [ebp-54h]
  tagRECT v21; // [esp+2Ch] [ebp-50h] BYREF
  CRect rectImage; // [esp+3Ch] [ebp-40h] BYREF
  tagRECT v23; // [esp+4Ch] [ebp-30h] BYREF
  tagRECT rc; // [esp+5Ch] [ebp-20h] BYREF
  int v25; // [esp+78h] [ebp-4h]

  pDCa = pDC;
  m_bIsDisabled = this->m_bIsDisabled;
  v25 = 0;
  this->m_bIsDisabled = 0;
  rc.left = rect.left;
  rc.top = rect.top;
  v15 = m_bIsDisabled;
  rc.bottom = rect.bottom;
  rc.right = nTextOffset + rect.left;
  this->GetImageSize(this, result: (CSize *)&v16, a3: RibbonImageSmall);
  if ( v16 != 0 || v17 != 0 )
  {
    InflateRect(lprc: &rc, dx: -1, dy: 0);
    v9 = (rc.bottom - rc.top - v17) / 2;
    if ( v9 < 0 )
      v9 = 0;
    rc.top += v9;
    rc.bottom = v17 + rc.top;
    ((void (__thiscall *)(CMFCRibbonButton *, CDC *, int, int, int, int, int))this->DrawImage)(
      a1: this,
      a2: pDCa,
      a3: 1,
      a4: rc.left,
      a5: rc.top,
      a6: rc.right,
      a7: v17 + rc.top);
  }
  else if ( this->m_bDrawDefaultIcon != 0 )
  {
    Instance = CMFCVisualManager::GetInstance();
    ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, _DWORD, _DWORD, _DWORD))Instance->OnDrawDefaultRibbonImage)(
      a1: Instance,
      a2: pDCa,
      a3: rc.left,
      a4: rc.top,
      a5: rc.right,
      a6: rc.bottom,
      a7: 0,
      a8: 0,
      a9: 0);
  }
  v11 = this->__vftable;
  v23 = rect;
  if ( v11->HasMenu(this) != 0 )
  {
    rectImage.top = rect.top;
    rectImage.right = rect.right;
    rectImage.bottom = rect.bottom;
    rectImage.left = rect.top + rect.right - rect.bottom;
    v21 = rectImage.tagRECT;
    v12 = true;
    OffsetRect(lprc: &v21, dx: 0, dy: 1);
    if ( bHighlighted != 0 )
    {
      SysColor = GetSysColor(nIndex: 14);
      if ( (unsigned __int8)SysColor > 0x80u && BYTE1(SysColor) > 0x80u )
        v12 = BYTE2(SysColor) <= 0x80u;
    }
    if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
      m_dblRibbonImageScale = afxGlobalData.m_dblRibbonImageScale;
    else
      m_dblRibbonImageScale = 1.0;
    id = IdArrowRightLarge;
    if ( m_dblRibbonImageScale <= 1.0 )
      id = IdArrowRight;
    sizeImageDest.cx = 0;
    sizeImageDest.cy = 0;
    CMenuImages::Draw(
      pDC: pDCa,
      id,
      rectImage: (const CRect *)&v21,
      state: v12 ? ImageWhite : ImageBlack,
      &sizeImageDest);
    sizeImageDest.cx = 0;
    sizeImageDest.cy = 0;
    CMenuImages::Draw(pDC: pDCa, id, &rectImage, state: v12 ? ImageBlack : ImageWhite, &sizeImageDest);
    v23.right = rectImage.left;
  }
  v23.left += nTextOffset;
  InflateRect(lprc: &v23, dx: -3, dy: 0);
  pDCa->DrawTextA(this: pDCa, a2: strText.m_pszData, a3: *((_DWORD *)strText.m_pszData - 3), a4: &v23, a5: 2084u);
  this->m_bIsDisabled = v15;
  ATL::CStringData::Release(this: (ATL::CStringData *)strText.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x103C70DE
// Name: protected: virtual void CMFCRibbonButton::CopyFrom(class CMFCRibbonBaseElement const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonButton::CopyFrom(CMFCRibbonButton *this, const CMFCRibbonBaseElement *s)
{
  int v3; // ebx
  CRuntimeClass *v5; // eax
  int v6; // ebx
  CMFCRibbonBaseElement *pElem; // [esp+Ch] [ebp-4h]
  CMFCRibbonBaseElement *pSrcElem; // [esp+18h] [ebp+8h]

  v3 = 0;
  if ( this->m_bAutodestroyMenu != 0 && this->m_hMenu != nullptr )
    DestroyMenu(hMenu: this->m_hMenu);
  if ( this->m_bAutoDestroyIcon != 0 )
  {
    if ( this->m_hIcon != nullptr )
      DestroyIcon(hIcon: this->m_hIcon);
    if ( this->m_bAutoDestroyIcon != 0 && this->m_hIconSmall != nullptr )
      DestroyIcon(hIcon: this->m_hIconSmall);
  }
  CMFCRibbonButton::RemoveAllSubItems(this);
  CMFCRibbonBaseElement::CopyFrom(this, src: s);
  this->m_nSmallImageIndex = (int)s[1].m_pParentMenu;
  this->m_nLargeImageIndex = s[1].m_Location;
  this->m_hMenu = (HMENU__ *)s[1].m_nRow;
  this->m_bAutodestroyMenu = 0;
  this->m_bRightAlignMenu = s[1].m_bDontNotify;
  this->m_bIsDefaultCommand = s[1].m_bCompactMode;
  this->m_szMargin.cx = (int)s[1].m_strToolTip.m_pszData;
  this->m_szMargin.cy = (int)s[1].m_strDescription.m_pszData;
  this->m_hIcon = (HICON__ *)s[1].m_nImageOffset;
  this->m_hIconSmall = (HICON__ *)s[1].m_bTextAlwaysOnRight;
  this->m_bAutoDestroyIcon = 0;
  this->m_bAlphaBlendIcon = s[1].m_bIsPressed;
  this->m_bForceDrawBorder = s[1].m_bIsDisabled;
  this->m_bAlwaysShowDescription = s[1].m_bIsRadio;
  this->m_bCreatedFromMenu = s[1].m_bShowGroupBorder;
  this->m_bIsWindowsMenu = s[1].m_bIsVisible;
  this->m_nWindowsMenuItems = s[1].m_dwData;
  if ( (int)s[2].__vftable > 0 )
  {
    while ( v3 >= 0 && v3 < (int)s[2].__vftable )
    {
      pSrcElem = *(CMFCRibbonBaseElement **)(s[1].m_bEnableTooltipInfoShortcut + 4 * v3);
      v5 = (CRuntimeClass *)((int (*)(void))pSrcElem->GetRuntimeClass)();
      pElem = (CMFCRibbonBaseElement *)CRuntimeClass::CreateObject(this: v5);
      pElem->CopyFrom(this: pElem, a2: pSrcElem);
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arSubItems,
        nIndex: this->m_arSubItems.m_nSize,
        newElement: (CMFCRibbonKeyTip *)pElem);
      if ( ++v3 >= (int)s[2].__vftable )
        goto LABEL_14;
    }
LABEL_19:
    AfxThrowInvalidArgException();
  }
LABEL_14:
  this->m_nWrapIndex = s[1].m_nID;
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
    this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arWordIndexes,
    nNewSize: 0,
    nGrowBy: -1);
  v6 = 0;
  if ( s[1].m_bDrawDefaultIcon > 0 )
  {
    while ( v6 >= 0 && v6 < s[1].m_bDrawDefaultIcon )
    {
      CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
        this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arWordIndexes,
        nIndex: this->m_arWordIndexes.m_nSize,
        newElement: *(CMFCRibbonKeyTip **)(s[1].m_bIsAlwaysLarge + 4 * v6++));
      if ( v6 >= s[1].m_bDrawDefaultIcon )
        return;
    }
    goto LABEL_19;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C72C4
// Name: public: virtual int CMFCRibbonButton::DrawRibbonText(class CDC __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &,class CRect,unsigned int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonButton::DrawRibbonText(
        CMFCRibbonButton *this,
        CDC *pDC,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strText,
        CRect rectText,
        unsigned int uiDTFlags,
        unsigned int clrText)
{
  CMFCRibbonBar *m_pRibbonBar; // eax
  HWND Parent; // eax
  CWnd *v8; // eax
  unsigned int v9; // esi
  CMFCVisualManager *Instance; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v11; // edi
  char *m_pszData; // eax
  int v13; // ecx
  ATL::CStringData *v14; // eax
  unsigned int v16; // edi
  int v17; // esi
  int v18; // [esp-20h] [ebp-3Ch] BYREF
  CRect v19; // [esp-1Ch] [ebp-38h]
  unsigned int v20; // [esp-Ch] [ebp-28h]
  int v21; // [esp-8h] [ebp-24h]
  unsigned int v22; // [esp-4h] [ebp-20h]
  CSize v23; // [esp+Ch] [ebp-10h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *str; // [esp+14h] [ebp-8h]
  CMFCVisualManager *v25; // [esp+18h] [ebp-4h]

  str = strText;
  if ( CMFCToolBarImages::m_bIsDrawOnGlass != 0 )
  {
    m_pRibbonBar = this->m_pRibbonBar;
    if ( m_pRibbonBar == nullptr
      || m_pRibbonBar->m_hWnd == nullptr
      || (Parent = GetParent(hWnd: m_pRibbonBar->m_hWnd),
          v8 = CWnd::FromHandle(hWnd: Parent),
          v9 = 0xFFFFFF,
          !IsZoomed(hWnd: v8->m_hWnd)) )
    {
      v9 = clrText;
    }
    Instance = CMFCVisualManager::GetInstance();
    v22 = v9;
    v21 = 0;
    v20 = uiDTFlags;
    v19 = rectText;
    v11 = str;
    v25 = Instance;
    m_pszData = str->m_pszData;
    v18 = v13;
    v23.cy = (int)&v18;
    v14 = ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)m_pszData - 1);
    ((void (__thiscall *)(CMFCVisualManager *, CDC *, ATL::CStringData *, int, int, int, int, unsigned int, int, unsigned int))v25->DrawTextOnGlass)(
      a1: v25,
      a2: pDC,
      a3: v14 + 1,
      a4: v19.left,
      a5: v19.top,
      a6: v19.right,
      a7: v19.bottom,
      a8: v20,
      a9: v21,
      a10: v22);
    return CDC::GetTextExtent(this: pDC, result: &v23, str: v11)->cy;
  }
  else
  {
    v16 = -1;
    if ( clrText != -1 )
      v16 = pDC->SetTextColor(this: pDC, a2: clrText);
    v17 = pDC->DrawTextA(
            this: pDC,
            a2: strText->m_pszData,
            a3: *((_DWORD *)strText->m_pszData - 3),
            a4: &rectText,
            a5: uiDTFlags);
    if ( v16 != -1 )
      pDC->SetTextColor(this: pDC, a2: v16);
    return v17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C73AA
// Name: protected: virtual int CMFCRibbonButton::OnKey(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonButton::OnKey(CMFCRibbonButton *this, int bIsMenuKey)
{
  CMFCRibbonBar *TopLevelRibbonBar; // ebx
  CMFCRibbonPanel *v5; // eax
  CMFCPopupMenu *m_pPopupMenu; // eax
  CFrameWnd *TopLevelFrame; // eax

  if ( this->IsDisabled(this) != 0 )
    return 0;
  if ( IsRectEmpty(lprc: &this->m_rect) )
    return CMFCRibbonBaseElement::OnKey(this, bIsMenuKey);
  TopLevelRibbonBar = CMFCRibbonBaseElement::GetTopLevelRibbonBar(this);
  if ( this->HasMenu(this) == 0 || bIsMenuKey == 0 && *((_DWORD *)this->m_strMenuKeys.m_pszData - 3) != 0 )
  {
    if ( TopLevelRibbonBar != nullptr && CWnd::GetTopLevelFrame(this: TopLevelRibbonBar) != nullptr )
    {
      TopLevelFrame = CWnd::GetTopLevelFrame(this: TopLevelRibbonBar);
      CWnd::SetFocus(this: TopLevelFrame);
    }
    ((void (__thiscall *)(CMFCRibbonButton *, int, int))this->OnClick)(
      a1: this,
      a2: this->m_rect.left,
      a3: this->m_rect.top);
  }
  else if ( this->IsDroppedDown(this) == 0 )
  {
    if ( TopLevelRibbonBar != nullptr )
      CMFCRibbonBar::HideKeyTips(this: TopLevelRibbonBar);
    v5 = this->GetParentPanel(this);
    if ( v5 != nullptr )
      CMFCRibbonPanel::SetFocused(this: v5, pNewFocus: this);
    this->OnShowPopupMenu(this);
    m_pPopupMenu = this->m_pPopupMenu;
    if ( m_pPopupMenu != nullptr )
      SendMessageA(hWnd: m_pPopupMenu->m_hWnd, Msg: 0x100u, wParam: 0x24u, lParam: 0);
    return this->m_hMenu != nullptr;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103C7497
// Name: public: CMFCRibbonButton::CMFCRibbonButton(unsigned int,char const __near *,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonButton *__thiscall CMFCRibbonButton::CMFCRibbonButton(
        CMFCRibbonButton *this,
        unsigned int nID,
        const char *lpszText,
        int nSmallImageIndex,
        int nLargeImageIndex,
        int bAlwaysShowDescription)
{
  CMFCRibbonBaseElement::CMFCRibbonBaseElement(this);
  this->__vftable = (CMFCRibbonButton_vtbl *)&CMFCRibbonButton::`vftable';
  this->m_sizeTextRight.cx = 0;
  this->m_sizeTextRight.cy = 0;
  this->m_sizeTextBottom.cx = 0;
  this->m_sizeTextBottom.cy = 0;
  this->m_szMargin.cx = 0;
  this->m_szMargin.cy = 0;
  this->m_rectMenu.left = 0;
  this->m_rectMenu.top = 0;
  this->m_rectMenu.right = 0;
  this->m_rectMenu.bottom = 0;
  this->m_rectCommand.left = 0;
  this->m_rectCommand.top = 0;
  this->m_rectCommand.right = 0;
  this->m_rectCommand.bottom = 0;
  this->m_arWordIndexes.__vftable = (CArray<int,int>_vtbl *)&CArray<int,int>::`vftable';
  this->m_arWordIndexes.m_pData = nullptr;
  this->m_arWordIndexes.m_nGrowBy = 0;
  this->m_arWordIndexes.m_nMaxSize = 0;
  this->m_arWordIndexes.m_nSize = 0;
  this->m_arSubItems.__vftable = (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>_vtbl *)&CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::`vftable';
  this->m_arSubItems.m_pData = nullptr;
  this->m_arSubItems.m_nGrowBy = 0;
  this->m_arSubItems.m_nMaxSize = 0;
  this->m_arSubItems.m_nSize = 0;
  CMFCRibbonButton::CommonInit(this);
  this->m_nID = nID;
  CMFCRibbonButton::SetText(this, lpszText);
  this->m_nSmallImageIndex = nSmallImageIndex;
  this->m_nLargeImageIndex = nLargeImageIndex;
  this->m_bAlwaysShowDescription = bAlwaysShowDescription;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103C7590
// Name: protected: void CMFCRibbonButton::FillWindowList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonButton::FillWindowList(CMFCRibbonButton *this)
{
  int v2; // edi
  CMFCRibbonBaseElement *v3; // eax
  CMFCRibbonBar *TopLevelRibbonBar; // eax
  CFrameWnd *TopLevelFrame; // eax
  CObject *v6; // eax
  HWND Window; // eax
  HWND v8; // edi
  CWnd *v9; // eax
  CObject *v10; // eax
  CMFCRibbonSeparator *v11; // eax
  CMFCRibbonSeparator *v12; // eax
  ATL::IAtlStringMgr *StringManager; // eax
  CMFCRibbonButton *v14; // eax
  CMFCRibbonButton *v15; // eax
  HWND v16; // eax
  char *m_pszData; // ecx
  CMFCRibbonButton *v18; // ecx
  CMFCRibbonButton *v19; // eax
  CObject *v20; // [esp+10h] [ebp-120h]
  ATL::CSimpleStringT<char,0> v21; // [esp+18h] [ebp-118h] BYREF
  int v22; // [esp+1Ch] [ebp-114h]
  CHAR String[268]; // [esp+20h] [ebp-110h] BYREF
  int v24; // [esp+12Ch] [ebp-4h]

  if ( this->m_nWindowsMenuItems > 0 )
  {
    v22 = 0;
    do
    {
      v2 = this->m_arSubItems.m_nSize - 1;
      if ( v2 < 0 || v2 >= this->m_arSubItems.m_nSize )
        AfxThrowInvalidArgException();
      v3 = this->m_arSubItems.m_pData[v2];
      if ( v3 != nullptr )
        ((void (__thiscall *)(CMFCRibbonBaseElement *, int))v3->dtr_CObject)(a1: v3, a2: 1);
      CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::RemoveAt(
        this: &this->m_arSubItems,
        nIndex: v2,
        nCount: 1);
      ++v22;
    }
    while ( v22 < this->m_nWindowsMenuItems );
  }
  this->m_nWindowsMenuItems = 0;
  TopLevelRibbonBar = CMFCRibbonBaseElement::GetTopLevelRibbonBar(this);
  if ( TopLevelRibbonBar != nullptr )
  {
    TopLevelFrame = CWnd::GetTopLevelFrame(this: TopLevelRibbonBar);
    v6 = AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
    v20 = v6;
    if ( v6 != nullptr )
    {
      Window = GetWindow(hWnd: (HWND)v6[68].__vftable, uCmd: 5u);
      v22 = 0;
      v8 = Window;
      while ( v8 != nullptr && v22 < 9 )
      {
        v9 = CWnd::FromHandle(hWnd: v8);
        v10 = AfxDynamicDownCast(pClass: &CMDIChildWndEx::classCMDIChildWndEx, pObject: v9);
        if ( v10 != nullptr && ((int (__thiscall *)(CObject *))v10->__vftable[39].Serialize)(a1: v10) != 0 )
        {
          if ( v22 == 0 )
          {
            v11 = (CMFCRibbonSeparator *)operator new(nSize: 0xB0u);
            v24 = 0;
            if ( v11 != nullptr )
              v12 = CMFCRibbonSeparator::CMFCRibbonSeparator(this: v11, bIsHoriz: 1);
            else
              v12 = nullptr;
            v24 = -1;
            v12->m_bIsDefaultMenuLook = 1;
            CMFCRibbonButton::AddSubItem(this, pSubItem: v12, nIndex: -1);
            this->m_nWindowsMenuItems = 1;
          }
          GetWindowTextA(hWnd: v8, lpString: String, nMaxCount: 256);
          StringManager = AfxGetStringManager();
          ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v21, pStringMgr: StringManager);
          v24 = 1;
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
            this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v21,
            pszFormat: "&%d %s",
            v22 + 1,
            String);
          v14 = (CMFCRibbonButton *)operator new(nSize: 0x164u);
          LOBYTE(v24) = 2;
          if ( v14 != nullptr )
            v15 = CMFCRibbonButton::CMFCRibbonButton(
                    this: v14,
                    nID: 0xFF00u,
                    lpszText: v21.m_pszData,
                    nSmallImageIndex: -1,
                    nLargeImageIndex: -1,
                    bAlwaysShowDescription: 0);
          else
            v15 = nullptr;
          v15->m_dwData = (unsigned int)v8;
          v15->m_bIsDefaultMenuLook = 1;
          v15->m_pRibbonBar = this->m_pRibbonBar;
          LOBYTE(v24) = 1;
          CMFCRibbonButton::AddSubItem(this, pSubItem: v15, nIndex: -1);
          v16 = GetWindow(hWnd: v8, uCmd: 2u);
          m_pszData = v21.m_pszData;
          ++this->m_nWindowsMenuItems;
          v24 = -1;
          v8 = v16;
          ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
        }
        else
        {
          v8 = GetWindow(hWnd: v8, uCmd: 2u);
        }
        ++v22;
      }
      if ( v20[71].__vftable != nullptr && (v22 == 9 || v20[75].__vftable != nullptr) )
      {
        v18 = (CMFCRibbonButton *)operator new(nSize: 0x164u);
        v24 = 3;
        if ( v18 != nullptr )
          v19 = CMFCRibbonButton::CMFCRibbonButton(
                  this: v18,
                  nID: (unsigned int)v20[71].__vftable,
                  lpszText: (const char *)v20[69].__vftable,
                  nSmallImageIndex: -1,
                  nLargeImageIndex: -1,
                  bAlwaysShowDescription: 0);
        else
          v19 = nullptr;
        v24 = -1;
        v19->m_bIsDefaultMenuLook = 1;
        v19->m_pRibbonBar = this->m_pRibbonBar;
        CMFCRibbonButton::AddSubItem(this, pSubItem: v19, nIndex: -1);
        ++this->m_nWindowsMenuItems;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C7848
// Name: protected: virtual void CMFCRibbonButton::OnShowPopupMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonButton::OnShowPopupMenu(CMFCRibbonButton *this)
{
  CWnd *v2; // eax
  CMFCRibbonBar *TopLevelRibbonBar; // eax
  CMFCRibbonBar *v4; // edi
  CMFCRibbonPanelMenu *v5; // ecx
  CMFCRibbonPanelMenu *v6; // edi
  int v7; // eax
  int i; // ecx
  CMFCRibbonPanel *v9; // eax
  int m_bRightAlignMenu; // eax
  int left; // ecx
  CMFCPopupMenu *v12; // esi
  int v13; // eax
  CMFCRibbonPanel *v14; // eax
  CMFCPopupMenu *v15; // eax
  BOOL v16; // eax
  HWND v17; // edi
  HWND Parent; // eax
  CWnd *v19; // eax
  int right; // eax
  CSize v21; // [esp-8h] [ebp-70h]
  CWnd *SafeOwner; // [esp+10h] [ebp-58h]
  CWnd *v23; // [esp+14h] [ebp-54h]
  CMFCPopupMenu *pPopupMenu; // [esp+18h] [ebp-50h]
  HMENU__ *pPopupMenua; // [esp+18h] [ebp-50h]
  int v26; // [esp+1Ch] [ebp-4Ch]
  unsigned int v27; // [esp+20h] [ebp-48h]
  void *pData; // [esp+24h] [ebp-44h]
  CWnd *pDataa; // [esp+24h] [ebp-44h]
  tagRECT m_rect; // [esp+28h] [ebp-40h] BYREF
  tagRECT Rect; // [esp+38h] [ebp-30h] BYREF
  tagRECT rc; // [esp+48h] [ebp-20h] BYREF
  int v33; // [esp+64h] [ebp-4h]

  if ( this->IsDroppedDown(this) == 0 )
  {
    v2 = this->GetParentWnd(this);
    v23 = v2;
    if ( v2 != nullptr && v2->m_hWnd != nullptr )
    {
      TopLevelRibbonBar = CMFCRibbonBaseElement::GetTopLevelRibbonBar(this);
      v4 = TopLevelRibbonBar;
      if ( TopLevelRibbonBar != nullptr && TopLevelRibbonBar->m_hWnd != nullptr )
      {
        CMFCRibbonBaseElement::OnShowPopupMenu(this);
        v27 = CWnd::GetExStyle(this: v4) & 0x400000;
        SafeOwner = CWnd::GetSafeOwner(pParent: nullptr, pWndTop: nullptr);
        if ( this->m_arSubItems.m_nSize <= 0 )
        {
          pPopupMenua = this->m_hMenu;
          if ( pPopupMenua == nullptr )
            return;
          m_rect = (tagRECT)this->m_rect;
          CWnd::ClientToScreen(this: v23, lpRect: &m_rect);
          v15 = (CMFCPopupMenu *)operator new(nSize: 0x10C4u);
          v33 = 1;
          if ( v15 != nullptr )
            v12 = CMFCPopupMenu::CMFCPopupMenu(this: v15);
          else
            v12 = nullptr;
          v33 = -1;
          v16 = false;
          v12->m_bAutoDestroy = 0;
          if ( this->m_bRightAlignMenu != 0 )
            v16 = v27 == 0;
          v12->m_bRightAlign = v16;
          CMFCPopupMenu::SetParentRibbonElement(this: v12, pElem: this);
          v17 = CMFCPopupMenu::m_pActivePopupMenu;
          if ( CMFCPopupMenu::m_pActivePopupMenu != nullptr )
          {
            pDataa = *((CWnd **)CMFCPopupMenu::m_pActivePopupMenu + 8);
            Parent = GetParent(hWnd: v23->m_hWnd);
            v19 = CWnd::FromHandle(hWnd: Parent);
            if ( v19 != nullptr )
              v19 = (CWnd *)v19->m_hWnd;
            if ( pDataa != v19 )
              SendMessageA(hWnd: *((HWND *)v17 + 8), Msg: 0x10u, wParam: 0, lParam: 0);
          }
          if ( this->m_bRightAlignMenu != 0 || (right = m_rect.left, v27 != 0) )
            right = m_rect.right;
          v12->Create(this: v12, a2: SafeOwner, a3: right, a4: m_rect.bottom, a5: pPopupMenua, a6: 0, a7: 0);
        }
        else
        {
          if ( this->m_bIsWindowsMenu != 0 )
            CMFCRibbonButton::FillWindowList(this);
          v5 = (CMFCRibbonPanelMenu *)operator new(nSize: 0x1F00u);
          v33 = 0;
          if ( v5 != nullptr )
          {
            v6 = CMFCRibbonPanelMenu::CMFCRibbonPanelMenu(
                   this: v5,
                   pRibbonBar: v4,
                   arButtons: &this->m_arSubItems,
                   bIsFloatyMode: 0);
            pPopupMenu = &v6->CMFCPopupMenu;
          }
          else
          {
            pPopupMenu = nullptr;
            v6 = nullptr;
          }
          v33 = -1;
          CMFCPopupMenu::SetParentRibbonElement(this: &v6->CMFCPopupMenu, pElem: this);
          v6->m_wndRibbonBar.m_bIsMenuMode = 1;
          v7 = this->IsPopupDefaultMenuLook(this);
          for ( i = 0; v7 != 0 && i < this->m_arSubItems.m_nSize; ++i )
          {
            if ( i < 0 || i >= this->m_arSubItems.m_nSize )
              AfxThrowInvalidArgException();
            if ( this->m_arSubItems.m_pData[i]->m_bIsDefaultMenuLook == 0 )
              v7 = 0;
          }
          v6->m_wndRibbonBar.m_bIsDefaultMenuLook = v7;
          if ( this->m_pOriginal != nullptr && this->m_pOriginal->GetParentPanel(this: this->m_pOriginal) != nullptr )
          {
            v9 = this->m_pOriginal->GetParentPanel(this: this->m_pOriginal);
            if ( v9->IsMainPanel(this: v9) != 0 )
              v6->m_wndRibbonBar.m_bIsDefaultMenuLook = 0;
          }
          Rect = (tagRECT)this->m_rect;
          CWnd::ClientToScreen(this: v23, lpRect: &Rect);
          m_bRightAlignMenu = this->m_bRightAlignMenu;
          if ( m_bRightAlignMenu != 0 || (left = Rect.left, v27 != 0) )
            left = Rect.right;
          v26 = left;
          pData = (void *)Rect.bottom;
          if ( this->m_bCreatedFromMenu != 0 && m_bRightAlignMenu != 0 && v27 == 0 )
          {
            v12 = pPopupMenu;
            pPopupMenu->m_bRightAlign = 1;
          }
          else
          {
            v12 = pPopupMenu;
          }
          if ( CMFCRibbonBaseElement::IsMenuMode(this) != 0 )
          {
            v13 = Rect.left;
            if ( v27 == 0 )
              v13 = Rect.right;
            v26 = v13;
            pData = (void *)Rect.top;
          }
          memset(&rc, 0, sizeof(rc));
          SetRectEmpty(lprc: &rc);
          v14 = this->GetParentPanel(this);
          if ( v14 != nullptr && v14->GetPreferedMenuLocation(this: v14, a2: (CRect *)&rc) != 0 )
          {
            CWnd::ClientToScreen(this: v23, lpRect: &rc);
            v26 = rc.right;
            if ( v27 == 0 )
              v26 = rc.left;
            v21.cy = rc.bottom - rc.top;
            pData = (void *)rc.top;
            v21.cx = rc.right - rc.left;
            CMFCRibbonPanelMenuBar::SetPreferedSize(this: (CMFCRibbonPanelMenuBar *)&v12[1], size: v21);
            v12[1].m_wndMenuBar.m_OrigResetButtons.m_nBlockSize = 0;
          }
          v12->Create(this: v12, a2: SafeOwner, a3: v26, a4: (int)pData, a5: nullptr, a6: 0, a7: 0);
        }
        CMFCRibbonBaseElement::SetDroppedDown(this, pPopupMenu: v12);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C7B8C
// Name: public: virtual int CMFCRibbonButton::SetACCData(class CWnd __near *,class CAccessibilityData __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonButton::SetACCData(CMFCRibbonButton *this, CWnd *pParent, CAccessibilityData *data)
{
  int result; // eax

  result = CMFCRibbonBaseElement::SetACCData(this, pParent, data);
  if ( result != 0 )
  {
    if ( this->HasMenu(this) != 0 )
    {
      data->m_nAccRole = this->IsCommandAreaHighlighted(this) != 0 ? 62 : 56;
      if ( this->IsCommandAreaHighlighted(this) == 0 )
      {
        data->m_bAccState |= 0x40000000u;
        ATL::CSimpleStringT<char,0>::SetString(this: &data->m_strAccDefAction, pszSrc: "Open");
        if ( this->IsDroppedDown(this) != 0 )
        {
          data->m_bAccState |= 8u;
          ATL::CSimpleStringT<char,0>::SetString(this: &data->m_strAccDefAction, pszSrc: "Close");
        }
      }
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103DE741
// Name: void CopyElements<int>(int __near *,int const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CopyElements<int>(int *pDest, char *pSrc, int nCount)
{
  char *v3; // eax

  if ( nCount != 0 )
  {
    if ( pDest == nullptr || (v3 = pSrc, pSrc == nullptr) )
      AfxThrowInvalidArgException();
    do
    {
      --nCount;
      *(_DWORD *)&v3[(char *)pDest - pSrc] = *(_DWORD *)v3;
      v3 += 4;
    }
    while ( nCount != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DE7AA
// Name: public: virtual void CMFCRibbonTab::Redraw(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonTab::Redraw(CMFCRibbonTab *this)
{
  CRect *p_m_rect; // esi
  CMFCRibbonBar *m_pParentRibbonBar; // ebx
  int *p_top; // esi
  CRect rect; // [esp+8h] [ebp-14h] BYREF

  p_m_rect = &this->m_rect;
  if ( !IsRectEmpty(lprc: &this->m_rect) )
  {
    m_pParentRibbonBar = this->m_pParent->m_pParentRibbonBar;
    rect.left = p_m_rect->left;
    p_top = &p_m_rect->top;
    rect.top = *p_top++;
    rect.right = *p_top;
    rect.bottom = p_top[1];
    InflateRect(lprc: &rect, dx: 10, dy: 10);
    RedrawWindow(hWnd: m_pParentRibbonBar->m_hWnd, lprcUpdate: &rect, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DE810
// Name: protected: void CMFCRibbonCategory::UpdateScrollButtons(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::UpdateScrollButtons(CMFCRibbonCategory *this)
{
  CMFCRibbonPanelMenuBar *m_pParentMenuBar; // eax
  long double m_dblRibbonImageScale; // st7
  int v4; // eax
  int m_nScrollOffset; // ecx
  int rectScrollLeft; // [esp+Ch] [ebp-34h]
  int rectScrollLeft_4; // [esp+10h] [ebp-30h]
  int rectScrollLeft_8; // [esp+14h] [ebp-2Ch]
  int rectScrollLeft_12; // [esp+18h] [ebp-28h]
  CRect rectScrollRightOld; // [esp+1Ch] [ebp-24h] BYREF
  CRect rectScrollRight; // [esp+2Ch] [ebp-14h] BYREF

  m_pParentMenuBar = this->m_pParentMenuBar;
  rectScrollRightOld = this->m_ScrollRight.m_rect;
  this->m_ScrollLeft.m_pParentMenu = m_pParentMenuBar;
  this->m_ScrollRight.m_pParentMenu = m_pParentMenuBar;
  if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
    m_dblRibbonImageScale = afxGlobalData.m_dblRibbonImageScale;
  else
    m_dblRibbonImageScale = 1.0;
  v4 = (int)(m_dblRibbonImageScale * 13.0);
  m_nScrollOffset = this->m_nScrollOffset;
  rectScrollLeft = 0;
  rectScrollLeft_4 = 0;
  rectScrollLeft_8 = 0;
  rectScrollLeft_12 = 0;
  memset(&rectScrollRight, 0, sizeof(rectScrollRight));
  if ( m_nScrollOffset > 0 )
  {
    rectScrollLeft = this->m_rect.left;
    rectScrollLeft_4 = this->m_rect.top;
    rectScrollLeft_12 = this->m_rect.bottom;
    rectScrollLeft_8 = v4 + rectScrollLeft;
  }
  if ( m_nScrollOffset + this->m_rect.right - this->m_rect.left < this->m_nMinWidth )
  {
    rectScrollRight = this->m_rect;
    rectScrollRight.left = rectScrollRight.right - v4;
  }
  this->m_ScrollLeft.m_rect.left = rectScrollLeft;
  this->m_ScrollLeft.m_rect.top = rectScrollLeft_4;
  this->m_ScrollLeft.m_rect.right = rectScrollLeft_8;
  this->m_ScrollLeft.m_rect.bottom = rectScrollLeft_12;
  this->m_ScrollRight.m_rect = rectScrollRight;
  if ( IsRectEmpty(lprc: &rectScrollRight) && !IsRectEmpty(lprc: &rectScrollRightOld) )
    RedrawWindow(
      hWnd: this->m_pParentRibbonBar->m_hWnd,
      lprcUpdate: &rectScrollRightOld,
      hrgnUpdate: nullptr,
      flags: 0x105u);
}

//------------------------------------------------------------------------------
// Address: 0x103DE916
// Name: public: virtual int CMFCRibbonCategory::OnDrawImage(class CDC __near *,class CRect,class CMFCRibbonBaseElement __near *,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonCategory::OnDrawImage(
        CMFCRibbonCategory *this,
        CDC *pDC,
        CRect rect,
        CMFCRibbonBaseElement *pElement,
        int bIsLargeImage,
        int nImageIndex,
        int bCenter)
{
  CMFCToolBarImages *p_m_LargeImages; // ebx
  int left; // esi
  int v10; // esi
  int v11; // eax
  tagAFXDrawState v12; // [esp+8h] [ebp-1Ch] BYREF
  CPoint ptImage; // [esp+14h] [ebp-10h]
  CSize sizeImage; // [esp+1Ch] [ebp-8h] BYREF
  int bIsLargeImagea; // [esp+44h] [ebp+20h]

  p_m_LargeImages = &this->m_LargeImages;
  if ( bIsLargeImage == 0 )
    p_m_LargeImages = &this->m_SmallImages;
  if ( nImageIndex >= p_m_LargeImages->m_iCount )
    return 0;
  left = rect.left;
  ptImage.y = rect.top;
  CMFCRibbonCategory::GetImageSize(this, result: &sizeImage, bIsLargeImage);
  if ( bCenter != 0 )
  {
    bIsLargeImagea = 0;
    if ( (rect.bottom - rect.top - sizeImage.cy) / 2 >= 0 )
      bIsLargeImagea = (rect.bottom - rect.top - sizeImage.cy) / 2;
    if ( (rect.right - rect.left - sizeImage.cx) / 2 >= 0 )
      v10 = (rect.right - rect.left - sizeImage.cx) / 2;
    else
      v10 = 0;
    left = rect.left + v10;
    ptImage.y += bIsLargeImagea;
  }
  CMFCToolBarImages::SetTransparentColor(this: p_m_LargeImages, clrTransparent: afxGlobalData.clrBtnFace);
  CMFCToolBarImages::PrepareDrawImage(this: p_m_LargeImages, ds: &v12, sizeImageDest: sizeImage, bFadeInactive: 0);
  v11 = pElement->IsDisabled(this: pElement);
  CMFCToolBarImages::Draw(
    this: p_m_LargeImages,
    pDCDest: pDC,
    xDest: left,
    yDest: ptImage.y,
    iImage: nImageIndex,
    bHilite: 0,
    bDisabled: v11,
    bIndeterminate: 0,
    bShadow: 0,
    bInactive: 0,
    alphaSrc: 0xFFu);
  CMFCToolBarImages::EndDrawImage(this: p_m_LargeImages, ds: &v12);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103DE9EA
// Name: public: virtual int CMFCRibbonCategory::OnScrollHorz(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCRibbonCategory::OnScrollHorz(CMFCRibbonCategory *this, int bScrollLeft, CFont *nScrollOffset)
{
  int v4; // ecx
  int m_nScrollOffset; // eax
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  CMFCRibbonBar *m_pParentRibbonBar; // edi
  CFont *Font; // eax
  CMFCRibbonPanelMenuBar *m_pParentMenuBar; // eax
  BOOL v13; // eax
  BOOL v14; // esi
  CClientDC dc; // [esp+10h] [ebp-24h] BYREF
  int nPrevScrollOffset; // [esp+24h] [ebp-10h]
  int v18; // [esp+30h] [ebp-4h]
  CFont *pOldFont; // [esp+40h] [ebp+Ch]

  v4 = (int)nScrollOffset;
  m_nScrollOffset = this->m_nScrollOffset;
  v6 = 0;
  nPrevScrollOffset = m_nScrollOffset;
  if ( nScrollOffset == nullptr )
    v4 = 50;
  if ( bScrollLeft != 0 )
    v7 = m_nScrollOffset - v4;
  else
    v7 = v4 + m_nScrollOffset;
  v8 = v7;
  this->m_nScrollOffset = v7;
  if ( v7 >= 0 )
    v6 = v7;
  v9 = this->m_rect.left + this->m_nMinWidth - this->m_rect.right;
  if ( v9 >= v6 )
  {
    if ( v8 >= 0 )
      v9 = v8;
    else
      v9 = 0;
  }
  m_pParentRibbonBar = this->m_pParentRibbonBar;
  this->m_nScrollOffset = v9;
  CClientDC::CClientDC(this: &dc, pWnd: m_pParentRibbonBar);
  v18 = 0;
  Font = CWnd::GetFont(this: m_pParentRibbonBar);
  pOldFont = CDC::SelectObject(this: &dc, pFont: Font);
  this->ReposPanels(this, a2: &dc);
  CDC::SelectObject(this: &dc, pFont: pOldFont);
  CMFCRibbonCategory::UpdateScrollButtons(this);
  m_pParentMenuBar = this->m_pParentMenuBar;
  if ( m_pParentMenuBar != nullptr )
    RedrawWindow(hWnd: m_pParentMenuBar->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  else
    RedrawWindow(hWnd: m_pParentRibbonBar->m_hWnd, lprcUpdate: &this->m_rect, hrgnUpdate: nullptr, flags: 0x105u);
  v13 = nPrevScrollOffset != this->m_nScrollOffset;
  v18 = -1;
  v14 = v13;
  CClientDC::~CClientDC(this: &dc);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x10419581
// Name: public: static class CObject __near * COutlookCustomizeButton::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCCustomizeButton *__stdcall COutlookCustomizeButton::CreateObject()
{
  CMFCCustomizeButton *v0; // esi
  CMFCCustomizeButton *result; // eax

  v0 = (CMFCCustomizeButton *)operator new(nSize: 0x12Cu);
  result = nullptr;
  if ( v0 != nullptr )
  {
    CMFCCustomizeButton::CMFCCustomizeButton(this: v0);
    v0->__vftable = (CMFCCustomizeButton_vtbl *)&COutlookCustomizeButton::`vftable';
    return v0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104195DC
// Name: public: CMFCOutlookBarToolBar::CMFCOutlookBarToolBar(class CMFCOutlookBarTabCtrl __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCOutlookBarToolBar *__thiscall CMFCOutlookBarToolBar::CMFCOutlookBarToolBar(
        CMFCOutlookBarToolBar *this,
        CMFCOutlookBarTabCtrl *pParentBar)
{
  CMFCToolBar::CMFCToolBar(this);
  this->__vftable = (CMFCOutlookBarToolBar_vtbl *)&CMFCOutlookBarToolBar::`vftable';
  CMap<int,int,int,int>::CMap<int,int,int,int>(this: &this->m_TabButtons, nBlockSize: 10);
  this->m_pParentBar = pParentBar;
  this->m_bLocked = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10419616
// Name: public: virtual int CMFCOutlookBarToolBar::SaveState(char const __near *,int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarToolBar::SaveState(
        CMFCOutlookBarToolBar *this,
        const char *__formal,
        HINSTANCE__ *hInstance,
        unsigned int dwReason)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1041961C
// Name: public: virtual CMFCOutlookBarToolBar::~CMFCOutlookBarToolBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarToolBar::~CMFCOutlookBarToolBar(CMFCOutlookBarToolBar *this)
{
  CMap<unsigned int,unsigned int,unsigned long,unsigned long> *p_m_TabButtons; // ecx

  p_m_TabButtons = (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&this->m_TabButtons;
  p_m_TabButtons->__vftable = (CMap<unsigned int,unsigned int,unsigned long,unsigned long>_vtbl *)&CMap<int,int,int,int>::`vftable';
  CMap<unsigned int,unsigned int,CPane *,CPane *>::RemoveAll(this: p_m_TabButtons);
  CMFCToolBar::~CMFCToolBar(this);
}

//------------------------------------------------------------------------------
// Address: 0x1042BBDD
// Name: public: void CMFCRibbonColorButton::SetColorBoxSize(class CSize)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonColorButton::SetColorBoxSize(CMFCRibbonColorButton *this, CSize sizeBox)
{
  long double m_dblRibbonImageScale; // st6
  long double v3; // st5
  long double v4; // st5
  int cx; // ebx
  int cy; // eax
  bool v7; // zf

  m_dblRibbonImageScale = afxGlobalData.m_dblRibbonImageScale;
  if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
    v3 = afxGlobalData.m_dblRibbonImageScale;
  else
    v3 = 1.0;
  if ( 1.0 == v3 )
  {
    cy = sizeBox.cy;
    cx = sizeBox.cx;
  }
  else
  {
    if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
      v4 = afxGlobalData.m_dblRibbonImageScale;
    else
      v4 = 1.0;
    cx = (int)(v4 * (double)sizeBox.cx + 0.5);
    if ( afxGlobalData.m_bIsRibbonImageScale == 0 )
      m_dblRibbonImageScale = 1.0;
    cy = (int)(m_dblRibbonImageScale * (double)sizeBox.cy + 0.5);
  }
  v7 = this->m_bHasGroups == 0;
  this->m_sizeBox.cx = cx;
  this->m_sizeBox.cy = cy;
  if ( v7 || this->m_arContColumnsRanges.m_nSize <= 0 )
  {
    this->m_imagesPalette.m_sizeImage.cx = cx;
  }
  else
  {
    cy -= 3;
    this->m_imagesPalette.m_sizeImage.cx = cx;
  }
  this->m_imagesPalette.m_sizeImage.cy = cy;
}

//------------------------------------------------------------------------------
// Address: 0x1042BC88
// Name: public: void CMFCRibbonColorButton::UpdateColor(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonColorButton::UpdateColor(CMFCRibbonColorButton *this, unsigned int color)
{
  CMFCRibbonBar *TopLevelRibbonBar; // eax
  int i; // ebx
  CMFCRibbonColorButton *v5; // eax
  CMFCRibbonColorButton_vtbl *v6; // edx
  CMFCRibbonPanelMenuBar *m_pParentMenu; // eax
  HWND Parent; // eax
  CWnd *v9; // eax
  CObject *v10; // eax
  CFrameWnd *v11; // eax
  unsigned int m_nID; // [esp-8h] [ebp-38h]
  CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> arButtons; // [esp+10h] [ebp-20h] BYREF
  int v14; // [esp+2Ch] [ebp-4h]

  if ( this->m_Color != color )
  {
    this->m_Color = color;
    TopLevelRibbonBar = CMFCRibbonBaseElement::GetTopLevelRibbonBar(this);
    if ( TopLevelRibbonBar != nullptr )
    {
      arButtons.__vftable = (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>_vtbl *)&CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::`vftable';
      memset(&arButtons.m_pData, 0, 16);
      m_nID = this->m_nID;
      v14 = 0;
      CMFCRibbonBar::GetElementsByID(this: TopLevelRibbonBar, uiCmdID: m_nID, &arButtons);
      for ( i = 0; i < arButtons.m_nSize; ++i )
      {
        if ( i < 0 || i >= arButtons.m_nSize )
          AfxThrowInvalidArgException();
        v5 = (CMFCRibbonColorButton *)AfxDynamicDownCast(
                                        pClass: &CMFCRibbonColorButton::classCMFCRibbonColorButton,
                                        pObject: arButtons.m_pData[i]);
        if ( v5 != nullptr && v5 != this )
        {
          v6 = v5->__vftable;
          v5->m_Color = color;
          v6->Redraw(this: v5);
        }
      }
      v14 = -1;
      CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::~CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>(this: &arButtons);
    }
    m_pParentMenu = this->m_pParentMenu;
    if ( m_pParentMenu != nullptr )
    {
      if ( m_pParentMenu->m_bIsFloaty == 0
        || (Parent = GetParent(hWnd: m_pParentMenu->m_hWnd),
            v9 = CWnd::FromHandle(hWnd: Parent),
            (v10 = AfxDynamicDownCast(pClass: &CMFCRibbonMiniToolBar::classCMFCRibbonMiniToolBar, pObject: v9)) == nullptr)
        || v10[1984].__vftable != nullptr )
      {
        v11 = AFXGetParentFrame(pWnd: this->m_pParentMenu);
        PostMessageA(hWnd: v11->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
      }
    }
    else
    {
      this->Redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042BD9B
// Name: public: void CMFCRibbonColorButton::SetPalette(class CPalette __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonColorButton::SetPalette(CMFCRibbonColorButton *this, CPalette *pPalette)
{
  CArray<unsigned long,unsigned long> *p_m_Colors; // esi

  if ( this->m_bHasGroups == 0 )
  {
    if ( pPalette != nullptr )
      CMFCRibbonColorButton::SetColorBoxSize(this, sizeBox: (CSize)0x1000000010LL);
    p_m_Colors = &this->m_Colors;
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
      this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)p_m_Colors,
      nNewSize: 0,
      nGrowBy: -1);
    CMFCColorBar::InitColors(pPalette, arColors: p_m_Colors);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042BDDF
// Name: protected: virtual void CMFCRibbonColorButton::OnShowPopupMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonColorButton::OnShowPopupMenu(CMFCRibbonColorButton *this)
{
  int v2; // edi
  CObject *v3; // eax
  int m_nSize; // ecx
  CMFCRibbonColorMenuButton *v5; // ecx
  CMFCRibbonColorMenuButton *v6; // eax
  char *m_pszData; // ecx
  CMFCRibbonColorMenuButton *v8; // ecx
  CMFCRibbonColorMenuButton *v9; // eax
  int v10; // eax
  int cy; // ecx
  char *v12; // [esp-4h] [ebp-28h]
  int nDocColors; // [esp+14h] [ebp-10h]

  this->m_ColorHighlighted = -1;
  CMFCRibbonBaseElement::OnShowPopupMenu(this);
  v2 = 0;
  while ( v2 < this->m_arSubItems.m_nSize )
  {
    if ( v2 < 0 || v2 >= this->m_arSubItems.m_nSize )
      AfxThrowInvalidArgException();
    v3 = AfxDynamicDownCast(
           pClass: &CMFCRibbonColorMenuButton::classCMFCRibbonColorMenuButton,
           pObject: this->m_arSubItems.m_pData[v2]);
    if ( v3 != nullptr )
    {
      ((void (__thiscall *)(CObject *, int))v3->dtr_CObject)(a1: v3, a2: 1);
      CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::RemoveAt(
        this: &this->m_arSubItems,
        nIndex: v2,
        nCount: 1);
    }
    else
    {
      ++v2;
    }
  }
  if ( this->m_bHasGroups == 0 )
  {
    this->Clear(this);
    CMFCRibbonGallery::AddGroup(this, lpszGroupName: &szGroupName, nIconsNum: this->m_Colors.m_nSize);
  }
  m_nSize = this->m_DocumentColors.m_nSize;
  nDocColors = m_nSize;
  if ( m_nSize > 0 )
    CMFCRibbonGallery::AddGroup(this, lpszGroupName: this->m_strDocumentColorsLabel.m_pszData, nIconsNum: m_nSize);
  if ( this->m_bIsOtherButton != 0 )
  {
    v5 = (CMFCRibbonColorMenuButton *)operator new(nSize: 0x16Cu);
    if ( v5 != nullptr )
      v6 = CMFCRibbonColorMenuButton::CMFCRibbonColorMenuButton(
             this: v5,
             nType: 2,
             pColorButton: this,
             lpszLabel: this->m_strOtherButtonLabel.m_pszData,
             bIsChecked: 0);
    else
      v6 = nullptr;
    m_pszData = this->m_strOtherButtonToolTip.m_pszData;
    this->m_pOtherButton = v6;
    v6->SetToolTipText(this: v6, a2: m_pszData);
    CMFCRibbonGallery::AddSubItem(this, pSubItem: this->m_pOtherButton, nIndex: 0, bOnTop: 0);
  }
  if ( this->m_bIsAutomaticButton != 0 )
  {
    v8 = (CMFCRibbonColorMenuButton *)operator new(nSize: 0x16Cu);
    if ( v8 != nullptr )
      v9 = CMFCRibbonColorMenuButton::CMFCRibbonColorMenuButton(
             this: v8,
             nType: 1,
             pColorButton: this,
             lpszLabel: this->m_strAutomaticButtonLabel.m_pszData,
             bIsChecked: this->m_Color == -1);
    else
      v9 = nullptr;
    v12 = this->m_strAutomaticButtonToolTip.m_pszData;
    this->m_pAutoButton = v9;
    v9->SetToolTipText(this: v9, a2: v12);
    CMFCRibbonGallery::AddSubItem(
      this,
      pSubItem: this->m_pAutoButton,
      nIndex: 0,
      bOnTop: this->m_bIsAutomaticButtonOnTop);
  }
  if ( this->m_bHasGroups != 0 && this->m_arContColumnsRanges.m_nSize > 0 )
  {
    v10 = this->m_sizeBox.cy - 3;
    this->m_imagesPalette.m_sizeImage.cx = this->m_sizeBox.cx;
    this->m_imagesPalette.m_sizeImage.cy = v10;
  }
  else
  {
    cy = this->m_sizeBox.cy;
    this->m_imagesPalette.m_sizeImage.cx = this->m_sizeBox.cx;
    this->m_imagesPalette.m_sizeImage.cy = cy;
  }
  CMFCRibbonGallery::OnShowPopupMenu(this);
  if ( nDocColors > 0 )
  {
    CStringArray::RemoveAt(this: &this->m_arGroupNames, nIndex: this->m_arGroupNames.m_nSize - 1, nCount: 1);
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::RemoveAt(
      this: (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *)&this->m_arGroupLen,
      nIndex: this->m_arGroupLen.m_nSize - 1,
      nCount: 1);
    this->m_nIcons -= nDocColors;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042BFF2
// Name: protected: virtual int CMFCRibbonColorButton::OnClickPaletteSubItem(class CMFCRibbonButton __near *,class CMFCRibbonPanelMenuBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonColorButton::OnClickPaletteSubItem(
        CMFCRibbonColorButton *this,
        CMFCRibbonButton *pButton,
        CMFCRibbonPanelMenuBar *pMenuBar)
{
  CMFCRibbonBaseElement *m_pOriginal; // ecx
  CMFCRibbonButton *m_pOtherButton; // eax
  CMFCRibbonColorButton *v6; // edi
  CMFCRibbonBar *TopLevelRibbonBar; // eax
  CMFCRibbonButton *m_pAutoButton; // eax
  CMFCColorDialog v10; // [esp+10h] [ebp-96Ch] BYREF
  int v11; // [esp+978h] [ebp-4h]

  m_pOriginal = pButton->m_pOriginal;
  m_pOtherButton = this->m_pOtherButton;
  if ( m_pOriginal == m_pOtherButton && m_pOtherButton != nullptr )
  {
    v6 = this;
    if ( this->m_pOriginal != nullptr )
      v6 = (CMFCRibbonColorButton *)this->m_pOriginal;
    this->ClosePopupMenu(this);
    TopLevelRibbonBar = CMFCRibbonBaseElement::GetTopLevelRibbonBar(this);
    CMFCColorDialog::CMFCColorDialog(
      this: &v10,
      clrInit: this->m_Color,
      __formal: 0,
      pParentWnd: TopLevelRibbonBar,
      hPal: nullptr);
    v11 = 0;
    if ( CDialog::DoModal(this: &v10) == 1 )
    {
      CMFCRibbonColorButton::UpdateColor(this: v6, color: v10.m_NewColor);
      CMFCRibbonBaseElement::NotifyCommand(this: v6, bWithDelay: 0);
    }
    v11 = -1;
    CMFCColorDialog::~CMFCColorDialog(this: &v10);
    return 1;
  }
  else
  {
    m_pAutoButton = this->m_pAutoButton;
    if ( m_pOriginal == m_pAutoButton && m_pAutoButton != nullptr )
    {
      CMFCRibbonColorButton::UpdateColor(this, color: 0xFFFFFFFF);
      CMFCRibbonBaseElement::NotifyCommand(this, bWithDelay: 1);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042C0B1
// Name: protected: unsigned long CMFCRibbonColorButton::GetColorByIndex(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCRibbonColorButton::GetColorByIndex(CMFCRibbonColorButton *this, int nIconIndex)
{
  int v2; // eax
  int m_nSize; // edx
  unsigned int *m_pData; // ecx

  v2 = nIconIndex;
  if ( nIconIndex >= 0 )
  {
    m_nSize = this->m_Colors.m_nSize;
    if ( nIconIndex < m_nSize )
    {
      m_pData = this->m_Colors.m_pData;
      return m_pData[v2];
    }
    v2 = nIconIndex - m_nSize;
    if ( nIconIndex - m_nSize < this->m_DocumentColors.m_nSize )
    {
      if ( v2 < 0 || v2 >= this->m_DocumentColors.m_nSize )
        AfxThrowInvalidArgException();
      m_pData = this->m_DocumentColors.m_pData;
      return m_pData[v2];
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1042C0FC
// Name: protected: virtual void CMFCRibbonColorButton::NotifyHighlightListItem(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonColorButton::NotifyHighlightListItem(CMFCRibbonColorButton *this, int nIndex)
{
  this->m_ColorHighlighted = CMFCRibbonColorButton::GetColorByIndex(this, nIconIndex: nIndex);
  CMFCRibbonBaseElement::NotifyHighlightListItem(this, nIndex);
}

//------------------------------------------------------------------------------
// Address: 0x1042C121
// Name: public: virtual void CMFCRibbonColorMenuButton::OnDraw(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonColorMenuButton::OnDraw(CMFCRibbonColorMenuButton *this, CDC *pDC)
{
  CMFCVisualManager *Instance; // eax
  int v4; // edi
  unsigned int v5; // eax
  CMFCVisualManager *v6; // eax
  CDC *v7; // esi
  int m_nType; // eax
  int left; // edi
  int v10; // ebx
  HICON__ *m_hiconColors; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  int v13; // esi
  CMFCRibbonColorButton *m_pColorButton; // ebx
  int v15; // [esp+Ch] [ebp-40h]
  int v16; // [esp+10h] [ebp-3Ch]
  CSize result; // [esp+14h] [ebp-38h] BYREF
  CRect *p_m_rect; // [esp+1Ch] [ebp-30h]
  CDC *v19; // [esp+20h] [ebp-2Ch]
  unsigned int clrTextOld; // [esp+24h] [ebp-28h]
  CRect rectColorBox; // [esp+28h] [ebp-24h] BYREF
  CRect rectText; // [esp+38h] [ebp-14h] BYREF

  v19 = pDC;
  p_m_rect = &this->m_rect;
  if ( IsRectEmpty(lprc: &this->m_rect) )
    return;
  Instance = CMFCVisualManager::GetInstance();
  v4 = 2 * Instance->GetMenuImageMargin(this: Instance);
  result.cy = v4 + CMFCToolBar::GetMenuImageSize(&result)->cx + 2;
  v5 = this->OnFillBackground(this, a2: pDC);
  clrTextOld = -1;
  if ( this->m_bIsDisabled != 0 )
  {
    if ( v5 == -1 )
    {
      v6 = CMFCVisualManager::GetInstance();
      v5 = v6->GetToolbarDisabledTextColor(this: v6);
    }
    goto LABEL_6;
  }
  if ( v5 != -1 )
LABEL_6:
    clrTextOld = pDC->SetTextColor(this: pDC, a2: v5);
  rectText = *p_m_rect;
  rectText.left += result.cy + 3;
  InflateRect(lprc: &rectText, dx: -this->m_szMargin.cx, dy: -this->m_szMargin.cx);
  v7 = v19;
  v19->DrawTextA(
    this: v19,
    a2: this->m_strText.m_pszData,
    a3: *((_DWORD *)this->m_strText.m_pszData - 3),
    a4: &rectText,
    a5: 32804u);
  if ( clrTextOld != -1 )
    v7->SetTextColor(this: v7, a2: clrTextOld);
  m_nType = this->m_nType;
  if ( m_nType == 2 )
  {
    rectColorBox = *p_m_rect;
    left = rectColorBox.left;
    v10 = rectColorBox.left + result.cy;
    m_hiconColors = afxGlobalData.m_hiconColors;
    if ( afxGlobalData.m_hiconColors == nullptr )
    {
      ModuleState = AfxGetModuleState();
      m_hiconColors = (HICON__ *)LoadImageW(
                                   hInst: ModuleState->m_hCurrentResourceHandle,
                                   name: (LPCWSTR)0x42D1,
                                   type: 1u,
                                   cx: 16,
                                   cy: 16,
                                   fuLoad: 0x8000u);
      afxGlobalData.m_hiconColors = m_hiconColors;
    }
    DrawIconEx(
      hdc: v19->m_hDC,
      xLeft: left + (v10 - left - 16) / 2,
      yTop: rectColorBox.top + (rectColorBox.bottom - rectColorBox.top - 16) / 2,
      hIcon: m_hiconColors,
      cxWidth: 16,
      cyWidth: 16,
      istepIfAniCur: 0,
      hbrFlickerFreeDraw: nullptr,
      diFlags: 3u);
  }
  else if ( m_nType == 1 )
  {
    rectColorBox = *p_m_rect;
    rectColorBox.right = result.cy + rectColorBox.left;
    InflateRect(lprc: &rectColorBox, dx: -2, dy: -2);
    v13 = rectColorBox.right - rectColorBox.left;
    if ( rectColorBox.right - rectColorBox.left >= rectColorBox.bottom - rectColorBox.top )
      v13 = rectColorBox.bottom - rectColorBox.top;
    m_pColorButton = this->m_pColorButton;
    v15 = rectColorBox.left + (rectColorBox.right - v13 - rectColorBox.left) / 2;
    v16 = rectColorBox.top + (rectColorBox.bottom - rectColorBox.top - v13) / 2;
    result.cx = v13 + v15;
    result.cy = v13 + v16;
    rectColorBox.left = v15;
    rectColorBox.top = v16;
    rectColorBox.right = v13 + v15;
    rectColorBox.bottom = v13 + v16;
    ((void (__thiscall *)(CMFCRibbonColorButton *, CDC *, int, int, int, int, int, _DWORD, int))m_pColorButton->OnDrawPaletteIcon)(
      a1: m_pColorButton,
      a2: v19,
      a3: v15,
      a4: v16,
      a5: v13 + v15,
      a6: v13 + v16,
      a7: -1,
      a8: 0,
      a9: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042C337
// Name: protected: void CMFCRibbonColorButton::CommonInit(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonColorButton::CommonInit(CMFCRibbonColorButton *this)
{
  this->m_ColorHighlighted = -1;
  this->m_ColorAutomatic = 0;
  this->m_bIsAutomaticButton = 0;
  this->m_bIsAutomaticButtonOnTop = 1;
  this->m_bIsAutomaticButtonBorder = 0;
  this->m_bIsOtherButton = 0;
  this->m_bIsDefaultCommand = 1;
  this->m_bSimpleButtonLook = 0;
  this->m_bIsOwnerDraw = 1;
  this->m_bDefaultButtonStyle = 0;
  this->m_bIsButtonMode = 1;
  this->m_bHasGroups = 0;
  CMFCRibbonColorButton::SetPalette(this, pPalette: nullptr);
  this->m_nIconsInRow = 5;
  this->m_pOtherButton = nullptr;
  this->m_pAutoButton = nullptr;
  this->m_bSmallIcons = 1;
  CMFCRibbonColorButton::SetColorBoxSize(this, sizeBox: (CSize)0x1600000016LL);
}

//------------------------------------------------------------------------------
// Address: 0x1042C3C0
// Name: public: virtual CMFCRibbonColorButton::~CMFCRibbonColorButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonColorButton::~CMFCRibbonColorButton(CMFCRibbonColorButton *this)
{
  this->__vftable = (CMFCRibbonColorButton_vtbl *)&CMFCRibbonColorButton::`vftable';
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strDocumentColorsLabel.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strOtherButtonToolTip.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strOtherButtonLabel.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strAutomaticButtonToolTip.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strAutomaticButtonLabel.m_pszData - 1);
  CArray<long,long>::~CArray<long,long>(this: &this->m_arContColumnsRanges);
  CArray<unsigned long,unsigned long>::~CArray<unsigned long,unsigned long>(this: &this->m_DocumentColors);
  CArray<unsigned long,unsigned long>::~CArray<unsigned long,unsigned long>(this: &this->m_Colors);
  CMFCRibbonGallery::~CMFCRibbonGallery(this);
}

//------------------------------------------------------------------------------
// Address: 0x1042C45E
// Name: public: virtual int CMFCRibbonColorButton::IsSimpleButtonLook(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonColorButton::IsSimpleButtonLook(CMFCRibbonColorButton *this)
{
  return this->m_bSimpleButtonLook;
}

//------------------------------------------------------------------------------
// Address: 0x1042C465
// Name: protected: virtual void CMFCRibbonColorButton::OnDrawPaletteIcon(class CDC __near *,class CRect,int,class CMFCRibbonGalleryIcon __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonColorButton::OnDrawPaletteIcon(
        CMFCRibbonColorButton *this,
        CDC *pDC,
        CRect rectIcon,
        int nIconIndex,
        CMFCRibbonGalleryIcon *pIcon,
        unsigned int __formal)
{
  CMFCRibbonGalleryIcon *v6; // edi
  int v8; // esi
  int v9; // ecx
  int *v10; // eax
  CMFCVisualManager *Instance; // eax
  CMFCRibbonGalleryIcon *v12; // [esp+10h] [ebp-18h]
  BOOL bIsChecked; // [esp+14h] [ebp-14h]
  unsigned int color; // [esp+18h] [ebp-10h]
  int bIsHighlighted; // [esp+1Ch] [ebp-Ch]
  int bDrawTopEdge; // [esp+20h] [ebp-8h]
  int bDrawBottomEdge; // [esp+24h] [ebp-4h]

  bIsHighlighted = 0;
  v6 = pIcon;
  v12 = pIcon;
  bDrawTopEdge = 1;
  bDrawBottomEdge = 1;
  if ( this->m_arContColumnsRanges.m_nSize <= 0 )
    v8 = 2;
  else
    v8 = 0;
  if ( pIcon == nullptr )
  {
    color = this->m_ColorAutomatic;
    v8 = 2;
    bIsChecked = this->m_Color == -1;
    goto LABEL_15;
  }
  color = CMFCRibbonColorButton::GetColorByIndex(this, nIconIndex);
  bIsChecked = this->m_Color == color;
  bIsHighlighted = v6->IsHighlighted(this: v6);
  if ( nIconIndex >= this->m_Colors.m_nSize || (v9 = 0, this->m_arContColumnsRanges.m_nSize <= 0) )
  {
LABEL_13:
    if ( this->m_arContColumnsRanges.m_nSize <= 0 )
      goto LABEL_15;
LABEL_14:
    --rectIcon.bottom;
    goto LABEL_15;
  }
  while ( 1 )
  {
    if ( v9 < 0 || v9 >= this->m_arContColumnsRanges.m_nSize )
      AfxThrowInvalidArgException();
    v10 = &this->m_arContColumnsRanges.m_pData[v9];
    if ( nIconIndex >= *(unsigned __int16 *)v10 && nIconIndex <= *((unsigned __int16 *)v10 + 1) )
      break;
    if ( ++v9 >= this->m_arContColumnsRanges.m_nSize )
      goto LABEL_13;
  }
  v8 = 0;
  bDrawBottomEdge = 0;
  bDrawTopEdge = 0;
  if ( v6->m_bIsFirstInColumn != 0 )
  {
    ++rectIcon.top;
    bDrawTopEdge = 1;
  }
  if ( v6->m_bIsLastInColumn != 0 )
  {
    bDrawBottomEdge = 1;
    goto LABEL_14;
  }
LABEL_15:
  InflateRect(lprc: &rectIcon, dx: -2, dy: -v8);
  Instance = CMFCVisualManager::GetInstance();
  ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCRibbonColorButton *, CMFCRibbonGalleryIcon *, unsigned int, int, int, int, int, int, int, int, BOOL, _DWORD))Instance->OnDrawRibbonColorPaletteBox)(
    a1: Instance,
    a2: pDC,
    a3: this,
    a4: v12,
    a5: color,
    a6: rectIcon.left,
    a7: rectIcon.top,
    a8: rectIcon.right,
    a9: rectIcon.bottom,
    a10: bDrawTopEdge,
    a11: bDrawBottomEdge,
    a12: bIsHighlighted,
    a13: bIsChecked,
    a14: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1042C5AC
// Name: protected: virtual void CMFCRibbonColorButton::OnClickPaletteIcon(class CMFCRibbonGalleryIcon __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonColorButton::OnClickPaletteIcon(CMFCRibbonColorButton *this, CMFCRibbonGalleryIcon *pIcon)
{
  unsigned int ColorByIndex; // eax

  ColorByIndex = CMFCRibbonColorButton::GetColorByIndex(this, nIconIndex: pIcon->m_nIndex);
  if ( ColorByIndex != -1 )
    CMFCRibbonColorButton::UpdateColor(this, color: ColorByIndex);
  CMFCRibbonGallery::OnClickPaletteIcon(this, pIcon);
}

//------------------------------------------------------------------------------
// Address: 0x1042C5DE
// Name: public: CMFCRibbonColorButton::CMFCRibbonColorButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonColorButton *__thiscall CMFCRibbonColorButton::CMFCRibbonColorButton(CMFCRibbonColorButton *this)
{
  ATL::IAtlStringMgr *StringManager; // eax
  ATL::IAtlStringMgr *v3; // eax
  ATL::IAtlStringMgr *v4; // eax
  ATL::IAtlStringMgr *v5; // eax
  ATL::IAtlStringMgr *v6; // eax

  CMFCRibbonGallery::CMFCRibbonGallery(this);
  this->__vftable = (CMFCRibbonColorButton_vtbl *)&CMFCRibbonColorButton::`vftable';
  this->m_Colors.__vftable = (CArray<unsigned long,unsigned long>_vtbl *)&CArray<unsigned long,unsigned long>::`vftable';
  this->m_Colors.m_pData = nullptr;
  this->m_Colors.m_nGrowBy = 0;
  this->m_Colors.m_nMaxSize = 0;
  this->m_Colors.m_nSize = 0;
  this->m_DocumentColors.__vftable = (CArray<unsigned long,unsigned long>_vtbl *)&CArray<unsigned long,unsigned long>::`vftable';
  this->m_DocumentColors.m_pData = nullptr;
  this->m_DocumentColors.m_nGrowBy = 0;
  this->m_DocumentColors.m_nMaxSize = 0;
  this->m_DocumentColors.m_nSize = 0;
  this->m_arContColumnsRanges.__vftable = (CArray<long,long>_vtbl *)&CArray<long,long>::`vftable';
  this->m_arContColumnsRanges.m_pData = nullptr;
  this->m_arContColumnsRanges.m_nGrowBy = 0;
  this->m_arContColumnsRanges.m_nMaxSize = 0;
  this->m_arContColumnsRanges.m_nSize = 0;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strAutomaticButtonLabel, pStringMgr: StringManager);
  v3 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strAutomaticButtonToolTip, pStringMgr: v3);
  v4 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strOtherButtonLabel, pStringMgr: v4);
  v5 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strOtherButtonToolTip, pStringMgr: v5);
  v6 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strDocumentColorsLabel, pStringMgr: v6);
  this->m_sizeBox.cx = 0;
  this->m_sizeBox.cy = 0;
  this->m_Color = -1;
  CMFCRibbonColorButton::CommonInit(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1042C712
// Name: public: static class CObject __near * CMFCRibbonColorButton::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonColorButton *__stdcall CMFCRibbonColorButton::CreateObject()
{
  CMFCRibbonColorButton *v0; // ecx
  CMFCRibbonColorButton *result; // eax

  v0 = (CMFCRibbonColorButton *)operator new(nSize: 0x390u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCRibbonColorButton::CMFCRibbonColorButton(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042C742
// Name: protected: virtual void CMFCRibbonColorButton::DrawImage(class CDC __near *,enum CMFCRibbonBaseElement::RibbonImageType,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonColorButton::DrawImage(
        CMFCRibbonColorButton *this,
        CDC *pDC,
        CMFCRibbonBaseElement::RibbonImageType type,
        tagRECT rectImage)
{
  bool v5; // zf
  long double v6; // st7
  int v7; // edx
  long double m_dblRibbonImageScale; // st5
  void *clrBarShadow; // eax
  unsigned int v10; // edi
  HDC__ *m_hDC; // [esp-Ch] [ebp-4Ch]
  CDrawingManager v12; // [esp+10h] [ebp-30h] BYREF
  CBrush v13; // [esp+18h] [ebp-28h] BYREF
  tagRECT Rect; // [esp+20h] [ebp-20h] BYREF
  int v15; // [esp+3Ch] [ebp-4h]

  v5 = this->m_bSimpleButtonLook == 0;
  v12.m_dc = pDC;
  if ( v5 )
  {
    v6 = 1.0;
    Rect = rectImage;
    v7 = 5;
    if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
      m_dblRibbonImageScale = afxGlobalData.m_dblRibbonImageScale;
    else
      m_dblRibbonImageScale = 1.0;
    if ( 1.0 != m_dblRibbonImageScale )
    {
      if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
        v6 = afxGlobalData.m_dblRibbonImageScale;
      v7 = (int)(v6 * 5.0);
    }
    Rect.top = rectImage.bottom - v7 + 1;
    if ( (this->m_rect.right - this->m_rect.left) % 2 == 0 )
    {
      ++Rect.left;
      ++Rect.right;
    }
    OffsetRect(lprc: &rectImage, dx: 0, dy: -1);
    CMFCRibbonButton::DrawImage(this, pDC: v12.m_dc, type, (CRect)rectImage);
    if ( this->IsDisabled(this) != 0 )
    {
      clrBarShadow = (void *)afxGlobalData.clrBarShadow;
    }
    else
    {
      clrBarShadow = (void *)this->m_Color;
      if ( clrBarShadow == (void *)-1 )
        clrBarShadow = (void *)this->m_ColorAutomatic;
    }
    v5 = this->m_bIsAutomaticButtonBorder == 0;
    v13.m_hObject = clrBarShadow;
    v10 = -1;
    if ( !v5 && this->m_Color == -1 )
      v10 = 12961221;
    if ( CMFCToolBarImages::m_bIsDrawOnGlass != 0 )
    {
      CDrawingManager::CDrawingManager(this: &v12, m_dc: v12.m_dc);
      v15 = 0;
      InflateRect(lprc: &Rect, dx: -1, dy: -1);
      CDrawingManager::DrawRect(
        this: &v12,
        rect: (const CRect *)&Rect,
        clrFill: (unsigned int)v13.m_hObject,
        clrLine: v10);
      v15 = -1;
      CDrawingManager::~CDrawingManager(this: &v12);
    }
    else
    {
      CBrush::CBrush(
        this: &v13,
        crColor: LOBYTE(v13.m_hObject) | ((BYTE1(v13.m_hObject) | ((BYTE2(v13.m_hObject) | 0x200) << 8)) << 8));
      m_hDC = v12.m_dc->m_hDC;
      v15 = 1;
      FillRect(hDC: m_hDC, lprc: &Rect, hbr: (HBRUSH)v13.m_hObject);
      if ( v10 != -1 )
        CDC::Draw3dRect(this: v12.m_dc, lpRect: &Rect, clrTopLeft: v10, clrBottomRight: v10);
      v15 = -1;
      v13.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
      CGdiObject::~CGdiObject(this: &v13);
    }
  }
  else
  {
    CMFCRibbonButton::DrawImage(this, pDC, type, (CRect)rectImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042C901
// Name: public: virtual int CMFCRibbonColorButton::SetACCData(class CWnd __near *,class CAccessibilityData __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonColorButton::SetACCData(CMFCRibbonColorButton *this, CWnd *pParent, CAccessibilityData *data)
{
  CAccessibilityData *v4; // edi
  ATL::IAtlStringMgr *StringManager; // eax

  v4 = data;
  CMFCRibbonGallery::SetACCData(this, pParent, data);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
    this: (ATL::CSimpleStringT<char,0> *)&data,
    pStringMgr: StringManager);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&data,
    pszFormat: "RGB(%d, %d, %d)",
    LOBYTE(this->m_Color),
    BYTE1(this->m_Color),
    BYTE2(this->m_Color));
  ATL::CSimpleStringT<char,0>::operator=(this: &v4->m_strAccValue, strSrc: (const ATL::CSimpleStringT<char,0> *)&data);
  ATL::CStringData::Release(this: (ATL::CStringData *)&data[-1].m_rectAccLocation.right);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1042C978
// Name: protected: virtual void CMFCRibbonColorButton::CopyFrom(class CMFCRibbonBaseElement const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonColorButton::CopyFrom(CMFCRibbonColorButton *this, const CMFCRibbonBaseElement *s)
{
  int v4; // eax
  int v5; // ebx
  int v6; // ebx
  int m_bIsOnPaletteTop; // eax
  int i; // [esp+10h] [ebp+8h]

  CMFCRibbonGallery::CopyFrom(this, s);
  if ( CObject::IsKindOf(this: &s->CObject, pClass: &CMFCRibbonColorButton::classCMFCRibbonColorButton) != 0 )
  {
    this->m_Color = s[4].m_bCompactMode;
    this->m_ColorAutomatic = s[4].m_bFloatyMode;
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
      this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_Colors,
      nNewSize: 0,
      nGrowBy: -1);
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
      this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_DocumentColors,
      nNewSize: 0,
      nGrowBy: -1);
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
      this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arContColumnsRanges,
      nNewSize: 0,
      nGrowBy: -1);
    v4 = 0;
    i = 0;
    if ( s[4].m_bIsFocused > 0 )
    {
      while ( v4 >= 0 && v4 < s[4].m_bIsFocused )
      {
        CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
          this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_Colors,
          nIndex: this->m_Colors.m_nSize,
          newElement: *(CMFCRibbonKeyTip **)(s[4].m_bIsHighlighted + 4 * v4));
        if ( ++i >= s[4].m_bIsFocused )
          goto LABEL_3;
        v4 = i;
      }
LABEL_18:
      AfxThrowInvalidArgException();
    }
LABEL_3:
    v5 = 0;
    if ( s[4].m_bIsDroppedDown > 0 )
    {
      while ( v5 >= 0 && v5 < s[4].m_bIsDroppedDown )
      {
        CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
          this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_DocumentColors,
          nIndex: this->m_DocumentColors.m_nSize,
          newElement: *(CMFCRibbonKeyTip **)(s[4].m_bIsRadio + 4 * v5++));
        if ( v5 >= s[4].m_bIsDroppedDown )
          goto LABEL_7;
      }
      goto LABEL_18;
    }
LABEL_7:
    v6 = 0;
    if ( s[4].m_bDrawDefaultIcon > 0 )
    {
      while ( v6 >= 0 && v6 < s[4].m_bDrawDefaultIcon )
      {
        CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
          this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&this->m_arContColumnsRanges,
          nIndex: this->m_arContColumnsRanges.m_nSize,
          newElement: *(CMFCRibbonKeyTip **)(s[4].m_bIsAlwaysLarge + 4 * v6++));
        if ( v6 >= s[4].m_bDrawDefaultIcon )
          goto LABEL_11;
      }
      goto LABEL_18;
    }
LABEL_11:
    this->m_bIsAutomaticButton = s[4].m_bEnableUpdateTooltipInfo;
    this->m_bIsAutomaticButtonOnTop = s[4].m_bEnableTooltipInfoShortcut;
    this->m_bIsAutomaticButtonBorder = (int)s[5].__vftable;
    this->m_bIsOtherButton = (int)s[5].m_strText.m_pszData;
    ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strAutomaticButtonLabel, strSrc: &s[5].m_strToolTip);
    ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strAutomaticButtonToolTip, strSrc: &s[5].m_strDescription);
    ATL::CSimpleStringT<char,0>::operator=(
      this: &this->m_strOtherButtonLabel,
      strSrc: (const ATL::CSimpleStringT<char,0> *)&s[5].m_rect);
    ATL::CSimpleStringT<char,0>::operator=(
      this: &this->m_strOtherButtonToolTip,
      strSrc: (const ATL::CSimpleStringT<char,0> *)&s[5].m_rect.top);
    ATL::CSimpleStringT<char,0>::operator=(
      this: &this->m_strDocumentColorsLabel,
      strSrc: (const ATL::CSimpleStringT<char,0> *)&s[5].m_rect.right);
    this->m_bHasGroups = (int)s[5].m_strKeys.m_pszData;
    this->m_sizeBox.cx = (int)s[5].m_pParent;
    this->m_sizeBox.cy = (int)s[5].m_pOriginal;
    this->m_bSimpleButtonLook = (int)s[5].m_strMenuKeys.m_pszData;
    m_bIsOnPaletteTop = s[2].m_bIsOnPaletteTop;
    this->m_imagesPalette.m_sizeImage.cx = s[2].m_bDrawDefaultIcon;
    this->m_imagesPalette.m_sizeImage.cy = m_bIsOnPaletteTop;
  }
}
