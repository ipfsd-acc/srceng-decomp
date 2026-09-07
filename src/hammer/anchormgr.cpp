// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/anchormgr.cpp
// Functions: 11
// ============================================================

#include "hammer\anchormgr.h"

//------------------------------------------------------------------------------
// Address: 0x10001150
// Name: public: CAnchorDef::CAnchorDef(int,enum EAnchorHorz,enum EAnchorVert,enum EAnchorHorz,enum EAnchorVert)
// Source: json
//------------------------------------------------------------------------------
CAnchorDef *__thiscall CAnchorDef::CAnchorDef(
        CAnchorDef *this,
        int dlgItemID,
        EAnchorHorz eLeftSide,
        EAnchorVert eTopSide,
        EAnchorHorz eRightSide,
        EAnchorVert eBottomSide)
{
  this->m_DlgItemID = dlgItemID;
  this->m_AnchorLeft = eLeftSide;
  this->m_AnchorTop = eTopSide;
  this->m_hInputWnd = nullptr;
  this->m_AnchorRight = eRightSide;
  this->m_AnchorBottom = eBottomSide;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001180
// Name: public: void CAnchorDef::Init(struct HWND__ __near *,int,enum ESimpleAnchor)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnchorDef::Init(CAnchorDef *this, HWND__ *hWnd, int dlgItemID, ESimpleAnchor eSimpleAnchor)
{
  if ( eSimpleAnchor == k_eSimpleAnchorBottomRight )
  {
    this->m_hInputWnd = hWnd;
    this->m_DlgItemID = dlgItemID;
    this->m_AnchorLeft = k_eAnchorRight;
    this->m_AnchorRight = k_eAnchorRight;
    this->m_AnchorTop = k_eAnchorBottom;
    this->m_AnchorBottom = k_eAnchorBottom;
  }
  else if ( eSimpleAnchor != k_eSimpleAnchorAllSides )
  {
    switch ( eSimpleAnchor )
    {
      case k_eSimpleAnchorStretchRight:
        this->m_hInputWnd = hWnd;
        this->m_DlgItemID = dlgItemID;
        this->m_AnchorLeft = k_eAnchorLeft;
        this->m_AnchorTop = k_eAnchorTop;
        this->m_AnchorRight = k_eAnchorRight;
        this->m_AnchorBottom = k_eAnchorTop;
        break;
      case k_eSimpleAnchorRightSide:
        this->m_hInputWnd = hWnd;
        this->m_DlgItemID = dlgItemID;
        this->m_AnchorLeft = k_eAnchorRight;
        this->m_AnchorTop = k_eAnchorTop;
        this->m_AnchorRight = k_eAnchorRight;
        this->m_AnchorBottom = k_eAnchorTop;
        break;
      case k_eSimpleAnchorBottomSide:
        this->m_hInputWnd = hWnd;
        this->m_DlgItemID = dlgItemID;
        this->m_AnchorLeft = k_eAnchorLeft;
        this->m_AnchorRight = k_eAnchorLeft;
        this->m_AnchorTop = k_eAnchorBottom;
        this->m_AnchorBottom = k_eAnchorBottom;
        break;
      default:
        break;
    }
  }
  else
  {
    this->m_hInputWnd = hWnd;
    this->m_DlgItemID = dlgItemID;
    this->m_AnchorLeft = k_eAnchorLeft;
    this->m_AnchorTop = k_eAnchorTop;
    this->m_AnchorRight = k_eAnchorRight;
    this->m_AnchorBottom = k_eAnchorBottom;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001240
// Name: public: CAnchorDef::CAnchorDef(int,enum ESimpleAnchor)
// Source: json
//------------------------------------------------------------------------------
CAnchorDef *__thiscall CAnchorDef::CAnchorDef(CAnchorDef *this, int dlgItemID, ESimpleAnchor eSimpleAnchor)
{
  CAnchorDef *v3; // ecx

  CAnchorDef::Init(this, hWnd: nullptr, dlgItemID, eSimpleAnchor);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10001260
// Name: public: CAnchorDef::CAnchorDef(struct HWND__ __near *,enum ESimpleAnchor)
// Source: json
//------------------------------------------------------------------------------
CAnchorDef *__thiscall CAnchorDef::CAnchorDef(CAnchorDef *this, HWND__ *hWnd, ESimpleAnchor eSimpleAnchor)
{
  CAnchorDef *v3; // ecx

  CAnchorDef::Init(this, hWnd, dlgItemID: -1, eSimpleAnchor);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10001280
// Name: public: void CAnchorMgr::OnSize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnchorMgr::OnSize(CAnchorMgr *this)
{
  int v2; // edx
  CAnchorDef *v3; // esi
  int v4; // ebx
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  tagRECT rcParent; // [esp+4h] [ebp-20h] BYREF
  int width; // [esp+14h] [ebp-10h]
  int i; // [esp+18h] [ebp-Ch]
  int height; // [esp+1Ch] [ebp-8h]
  unsigned int v12; // [esp+20h] [ebp-4h]

  GetWindowRect(hWnd: this->m_hParentWnd, lpRect: &rcParent);
  v2 = rcParent.right - rcParent.left;
  height = rcParent.bottom - rcParent.top;
  width = rcParent.right - rcParent.left;
  i = 0;
  if ( this->m_Anchors.m_Size > 0 )
  {
    v12 = 0;
    do
    {
      v3 = &this->m_Anchors.m_Memory.m_pMemory[v12 / 0x2C];
      if ( v3->m_hWnd != nullptr )
      {
        if ( v3->m_AnchorLeft != k_eAnchorLeft )
          v4 = v2 + v3->m_OriginalPos[0] - this->m_OriginalParentSize[0];
        else
          v4 = v3->m_OriginalPos[0];
        v5 = v3->m_OriginalPos[2];
        if ( v3->m_AnchorRight != k_eAnchorLeft )
          v5 = v2 + v5 - this->m_OriginalParentSize[0];
        v6 = v3->m_OriginalPos[1];
        if ( v3->m_AnchorTop != k_eAnchorTop )
          v6 = height + v6 - this->m_OriginalParentSize[1];
        v7 = v3->m_OriginalPos[3];
        if ( v3->m_AnchorBottom != k_eAnchorTop )
          v7 = height + v7 - this->m_OriginalParentSize[1];
        SetWindowPos(hWnd: v3->m_hWnd, hWndInsertAfter: nullptr, X: v4, Y: v6, cx: v5 - v4, cy: v7 - v6, uFlags: 4u);
        InvalidateRect(hWnd: v3->m_hWnd, lpRect: nullptr, bErase: false);
        v2 = width;
      }
      v12 += 44;
      ++i;
    }
    while ( i < this->m_Anchors.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001410
// Name: public: CAnchorMgr::CAnchorMgr(void)
// Source: json
//------------------------------------------------------------------------------
CAnchorMgr *__thiscall CAnchorMgr::CAnchorMgr(CAnchorMgr *this)
{
  this->m_Anchors.m_Memory.m_pMemory = nullptr;
  this->m_Anchors.m_Memory.m_nAllocationCount = 0;
  this->m_Anchors.m_Memory.m_nGrowSize = 0;
  this->m_Anchors.m_Size = 0;
  this->m_Anchors.m_pElements = this->m_Anchors.m_Memory.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100014E0
// Name: public: void CAnchorMgr::Init(struct HWND__ __near *,class CAnchorDef __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnchorMgr::Init(CAnchorMgr *this, HWND__ *hParentWnd, CAnchorDef *pAnchors, int nAnchors)
{
  int v5; // ecx
  int v6; // ebx
  HWND__ *m_hInputWnd; // eax
  tagPOINT *v8; // esi
  HWND__ *m_hParentWnd; // [esp-Ch] [ebp-3Ch]
  tagRECT rcParent; // [esp+8h] [ebp-28h] BYREF
  tagRECT rcItem; // [esp+18h] [ebp-18h] BYREF
  tagPOINT ptTopLeft; // [esp+28h] [ebp-8h] BYREF
  int i; // [esp+40h] [ebp+10h]

  CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int>>::CopyArray(this: &this->m_Anchors, pArray: pAnchors, size: nAnchors);
  this->m_hParentWnd = hParentWnd;
  GetWindowRect(hWnd: hParentWnd, lpRect: &rcParent);
  v5 = rcParent.bottom - rcParent.top;
  v6 = 0;
  this->m_OriginalParentSize[0] = rcParent.right - rcParent.left;
  this->m_OriginalParentSize[1] = v5;
  for ( i = 0; i < this->m_Anchors.m_Size; ++i )
  {
    m_hInputWnd = this->m_Anchors.m_Memory.m_pMemory[v6].m_hInputWnd;
    v8 = (tagPOINT *)&this->m_Anchors.m_Memory.m_pMemory[v6];
    if ( m_hInputWnd == nullptr )
      m_hInputWnd = GetDlgItem(hDlg: this->m_hParentWnd, nIDDlgItem: v8->x);
    v8[5].x = (int)m_hInputWnd;
    if ( m_hInputWnd != nullptr )
    {
      GetWindowRect(hWnd: m_hInputWnd, lpRect: &rcItem);
      ptTopLeft.x = rcItem.left;
      m_hParentWnd = this->m_hParentWnd;
      ptTopLeft.y = rcItem.top;
      ScreenToClient(hWnd: m_hParentWnd, lpPoint: &ptTopLeft);
      v8[3] = ptTopLeft;
      v8[4].x = ptTopLeft.x + rcItem.right - rcItem.left;
      v8[4].y = ptTopLeft.y + rcItem.bottom - rcItem.top;
    }
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035F2F7
// Name: public: static void CNoTrackObject::operator delete(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __stdcall CNoTrackObject::operator delete(void *p)
{
  if ( p != nullptr )
    LocalFree(hMem: p);
}

//------------------------------------------------------------------------------
// Address: 0x1035F30D
// Name: public: void __near * CThreadSlotData::GetThreadValue(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CThreadSlotData::GetThreadValue(CThreadSlotData *this, int nSlot)
{
  _RTL_CRITICAL_SECTION *p_m_sect; // ebx
  _DWORD *Value; // eax
  int v5; // edi

  p_m_sect = &this->m_sect;
  EnterCriticalSection(lpCriticalSection: &this->m_sect);
  if ( nSlot > 0
    && nSlot < this->m_nMax
    && (Value = TlsGetValue(dwTlsIndex: this->m_tlsIndex)) != nullptr
    && nSlot < Value[2] )
  {
    v5 = *(_DWORD *)(Value[3] + 4 * nSlot);
    LeaveCriticalSection(lpCriticalSection: p_m_sect);
    return v5;
  }
  else
  {
    LeaveCriticalSection(lpCriticalSection: p_m_sect);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035F35F
// Name: public: void CThreadSlotData::AssignInstance(struct HINSTANCE__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CThreadSlotData::AssignInstance(CThreadSlotData *this, HINSTANCE__ *hInst)
{
  _RTL_CRITICAL_SECTION *p_m_sect; // edi
  int i; // ecx
  CSlotData *v5; // eax

  p_m_sect = &this->m_sect;
  EnterCriticalSection(lpCriticalSection: &this->m_sect);
  for ( i = 1; i < this->m_nMax; ++i )
  {
    v5 = &this->m_pSlotData[i];
    if ( v5->hInst == nullptr && (v5->dwFlags & 1) != 0 )
      v5->hInst = hInst;
  }
  LeaveCriticalSection(lpCriticalSection: p_m_sect);
}

//------------------------------------------------------------------------------
// Address: 0x1035F3A4
// Name: public: class CNoTrackObject __near * CThreadLocalObject::GetDataNA(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CNoTrackObject *__thiscall CThreadLocalObject::GetDataNA(CThreadLocalObject *this)
{
  if ( this->m_nSlot != 0 && _afxThreadData != nullptr )
    return (CNoTrackObject *)CThreadSlotData::GetThreadValue(this: _afxThreadData, nSlot: this->m_nSlot);
  else
    return nullptr;
}
