// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/richeditctrlex.cpp
// Functions: 235
// ============================================================

#include "hammer\richeditctrlex.h"

//------------------------------------------------------------------------------
// Address: 0x10001080
// Name: void __near * operator new[](unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl operator new[](unsigned int nSize)
{
  return operator new(nSize);
}

//------------------------------------------------------------------------------
// Address: 0x1009CAA0
// Name: class CRTFBuilder __near & operator<<(class CRTFBuilder __near &,class CManip __near &)
// Source: json
//------------------------------------------------------------------------------
CRTFBuilder *__cdecl operator<<(CRTFBuilder *b, CManip *f)
{
  return f->go(this: f, a2: b);
}

//------------------------------------------------------------------------------
// Address: 0x1009CAF0
// Name: public: CRichEditCtrlEx::CRichEditCtrlEx(void)
// Source: json
//------------------------------------------------------------------------------
CRichEditCtrlEx *__thiscall CRichEditCtrlEx::CRichEditCtrlEx(CRichEditCtrlEx *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CRichEditCtrlEx_vtbl *)&CRichEditCtrl::`vftable';
  this->__vftable = (CRichEditCtrlEx_vtbl *)&CRichEditCtrlEx::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009CBB0
// Name: protected: virtual void CRichEditCtrlEx::PreSubclassWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRichEditCtrlEx::PreSubclassWindow(CRichEditCtrlEx *this)
{
  LPARAM SysColor; // eax

  CMultiPaneFrameWnd::AdjustLayout((CMFCRibbonBaseElement *)this);
  SysColor = GetSysColor(nIndex: 15);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x443u, wParam: 0, lParam: SysColor);
  CWnd::ModifyStyle(this, dwRemove: 0, dwAdd: 0x8000000u, nFlags: 0);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0xCFu, wParam: 1u, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1009CC00
// Name: class CRTFBuilder __near & doSize(class CRTFBuilder __near &,int)
// Source: json
//------------------------------------------------------------------------------
CRTFBuilder *__cdecl doSize(CRTFBuilder *r, int n)
{
  r->m_attr.m_nFontSize = n;
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x1009CC10
// Name: class CRTFBuilder __near & doBold(class CRTFBuilder __near &,bool)
// Source: json
//------------------------------------------------------------------------------
CRTFBuilder *__cdecl doBold(CRTFBuilder *r, bool b)
{
  r->m_attr.m_bsBold.m_b = b;
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x1009CC20
// Name: class CRTFBuilder __near & doItalic(class CRTFBuilder __near &,bool)
// Source: json
//------------------------------------------------------------------------------
CRTFBuilder *__cdecl doItalic(CRTFBuilder *r, bool b)
{
  r->m_attr.m_bsItalic.m_b = b;
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x1009CC30
// Name: public: std::_List_val<unsigned long,class std::allocator<unsigned long>>::~_List_val<unsigned long,class std::allocator<unsigned long>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_List_val<unsigned long>::~_List_val<unsigned long>(std::_List_val<unsigned long> *this)
{
  operator delete(p: this->_Myhead);
}

//------------------------------------------------------------------------------
// Address: 0x1009CC40
// Name: void std::_Cons_val<class std::allocator<unsigned long>,unsigned long,unsigned long const __near &>(class std::allocator<unsigned long> __near &,unsigned long __near *,unsigned long const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Cons_val<std::allocator<unsigned long>,unsigned long,unsigned long const &>(
        std::allocator<unsigned long> *_Alval,
        unsigned int *_Pdest,
        const unsigned int *_Src)
{
  if ( _Pdest != nullptr )
    *_Pdest = *_Src;
}

//------------------------------------------------------------------------------
// Address: 0x1009CCF0
// Name: public: CManip::~CManip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManip::~CManip(CManip *this)
{
  volatile signed __int32 *v1; // eax

  v1 = (volatile signed __int32 *)(this->m_strVal.m_pszData - 16);
  if ( _InterlockedDecrement(v1 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v1 + 4))(a1: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1009CD50
// Name: public: virtual class CRTFBuilder __near & CIntManip::go(class CRTFBuilder __near &)
// Source: json
//------------------------------------------------------------------------------
CRTFBuilder *__thiscall CIntManip::go(CIntManip *this, CRTFBuilder *b)
{
  return ((CRTFBuilder *(__cdecl *)(CRTFBuilder *, int))this->m_pFunc)(a1: b, a2: this->m_nVal);
}

//------------------------------------------------------------------------------
// Address: 0x1009CD70
// Name: public: virtual class CRTFBuilder __near & CBoolManip::go(class CRTFBuilder __near &)
// Source: json
//------------------------------------------------------------------------------
CRTFBuilder *__thiscall CBoolManip::go(CBoolManip *this, CRTFBuilder *b)
{
  return ((CRTFBuilder *(__cdecl *)(CRTFBuilder *, bool))this->m_pFunc)(a1: b, a2: this->m_bVal);
}

//------------------------------------------------------------------------------
// Address: 0x1009CD90
// Name: public: CIntManip::~CIntManip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIntManip::~CIntManip(CBoolManip *this)
{
  volatile signed __int32 *v1; // eax

  v1 = (volatile signed __int32 *)(this->m_strVal.m_pszData - 16);
  if ( _InterlockedDecrement(v1 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v1 + 4))(a1: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1009CDF0
// Name: class CBoolManip italic(bool)
// Source: json
//------------------------------------------------------------------------------
CBoolManip *__cdecl italic(CBoolManip *result, bool b)
{
  ATL::IAtlStringMgr *StringManager; // eax

  result->__vftable = (CBoolManip_vtbl *)&CManip::`vftable';
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  result->m_strVal.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  result->m_pFunc = doItalic;
  result->m_bVal = b;
  result->__vftable = (CBoolManip_vtbl *)&CBoolManip::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009CE90
// Name: public: CTextAttributes::~CTextAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextAttributes::~CTextAttributes(CTextAttributes *this)
{
  CInstanceParmData::~CInstanceParmData(this: &this->m_bsStrike);
  CInstanceParmData::~CInstanceParmData(this: &this->m_bsItalic);
  CInstanceParmData::~CInstanceParmData(this: &this->m_bsUnderline);
  CInstanceParmData::~CInstanceParmData(this: &this->m_bsBold);
}

//------------------------------------------------------------------------------
// Address: 0x1009CF00
// Name: public: std::_Deque_val<class CTextAttributes,class std::allocator<class CTextAttributes>>::~_Deque_val<class CTextAttributes,class std::allocator<class CTextAttributes>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Deque_val<CTextAttributes>::~_Deque_val<CTextAttributes>(std::_Deque_val<CTextAttributes> *this)
{
  operator delete(p: this->_Myproxy);
  this->_Myproxy = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1009CF20
// Name: public: struct std::_List_nod<unsigned long,class std::allocator<unsigned long>>::_Node __near * std::_List_val<unsigned long,class std::allocator<unsigned long>>::_Buynode(struct std::_List_nod<unsigned long,class std::allocator<unsigned long>>::_Node __near *,struct std::_List_nod<unsigned long,class std::allocator<unsigned long>>::_Node __near *,unsigned long const __near &)
// Source: json
//------------------------------------------------------------------------------
std::_List_nod<unsigned long>::_Node *__thiscall std::_List_val<unsigned long>::_Buynode(
        std::_List_val<unsigned long> *this,
        std::_List_nod<unsigned long>::_Node *_Next,
        std::_List_nod<unsigned long>::_Node *_Prev,
        const unsigned int *_Val)
{
  unsigned int *v5; // eax
  unsigned int *v6; // esi
  int v8; // [esp+0h] [ebp-2Ch] BYREF
  std::exception pExceptionObject; // [esp+Ch] [ebp-20h] BYREF
  void *p; // [esp+18h] [ebp-14h]
  int *v11; // [esp+1Ch] [ebp-10h]
  int v12; // [esp+28h] [ebp-4h]

  v11 = &v8;
  v5 = (unsigned int *)operator new(nSize: 0xCu);
  v6 = v5;
  p = v5;
  if ( v5 == nullptr )
  {
    _Next = nullptr;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Next);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    v12 = -1;
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  v12 = 1;
  *v5 = (unsigned int)_Next;
  v5[1] = (unsigned int)_Prev;
  std::_Cons_val<std::allocator<unsigned long>,unsigned long,unsigned long const &>(
    _Alval: &this->_Alval,
    _Pdest: v5 + 2,
    _Src: _Val);
  v12 = -1;
  return (std::_List_nod<unsigned long>::_Node *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x1009CFF0
// Name: class CIntManip size(int)
// Source: json
//------------------------------------------------------------------------------
CIntManip *__cdecl size(CIntManip *result, int n)
{
  ATL::IAtlStringMgr *StringManager; // eax

  result->__vftable = (CIntManip_vtbl *)&CManip::`vftable';
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  result->m_strVal.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  result->m_pFunc = doSize;
  result->m_nVal = n;
  result->__vftable = (CIntManip_vtbl *)&CIntManip::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009D090
// Name: class CBoolManip bold(bool)
// Source: json
//------------------------------------------------------------------------------
CBoolManip *__cdecl bold(CBoolManip *result, bool b)
{
  ATL::IAtlStringMgr *StringManager; // eax

  result->__vftable = (CBoolManip_vtbl *)&CManip::`vftable';
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  result->m_strVal.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  result->m_pFunc = doBold;
  result->m_bVal = b;
  result->__vftable = (CBoolManip_vtbl *)&CBoolManip::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009D380
// Name: public: std::list<unsigned long,class std::allocator<unsigned long>>::~list<unsigned long,class std::allocator<unsigned long>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::list<unsigned long>::~list<unsigned long>(std::list<unsigned long> *this)
{
  std::_List_nod<unsigned long>::_Node *Myhead; // ecx
  std::_List_nod<unsigned long>::_Node *Next; // eax
  std::_List_nod<unsigned long>::_Node *v4; // edi

  Myhead = this->_Myhead;
  Next = Myhead->_Next;
  Myhead->_Next = Myhead;
  this->_Myhead->_Prev = this->_Myhead;
  this->_Mysize = 0;
  if ( Next != this->_Myhead )
  {
    do
    {
      v4 = Next->_Next;
      operator delete(p: Next);
      Next = v4;
    }
    while ( v4 != this->_Myhead );
  }
  operator delete(p: this->_Myhead);
}

//------------------------------------------------------------------------------
// Address: 0x1009D3F0
// Name: void std::_Cons_val<class std::allocator<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>>,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &>(class std::allocator<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>> __near &,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Cons_val<std::allocator<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>>,ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>> const &>(
        std::allocator<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > > *_Alval,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *_Pdest,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *_Src)
{
  if ( _Pdest != nullptr )
    _Pdest->m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)_Src->m_pszData - 1)[1];
}

//------------------------------------------------------------------------------
// Address: 0x1009D450
// Name: public: CBoolString::CBoolString(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>)
// Source: json
//------------------------------------------------------------------------------
CBoolString *__thiscall CBoolString::CBoolString(
        CBoolString *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strOn,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strOff)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_strOn; // edi
  ATL::IAtlStringMgr *StringManager; // eax
  ATL::IAtlStringMgr *v6; // eax
  char *v7; // eax
  char *v8; // eax

  p_m_strOn = &this->m_strOn;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  p_m_strOn->m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v6 = AfxGetStringManager();
  if ( v6 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strOff.m_pszData = (char *)&v6->GetNilString(this: v6)[1];
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strOn, strSrc: &strOn);
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strOff, strSrc: &strOff);
  this->m_b = false;
  v7 = strOn.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strOn.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v7 + 4))(a1: v7);
  v8 = strOff.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strOff.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v8 + 4))(a1: v8);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009D560
// Name: public: CManip::CManip(void __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>)
// Source: json
//------------------------------------------------------------------------------
CManip *__thiscall CManip::CManip(
        CManip *this,
        void *p,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > s)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_strVal; // edi
  ATL::IAtlStringMgr *StringManager; // eax
  char *v6; // eax

  p_m_strVal = &this->m_strVal;
  this->__vftable = (CManip_vtbl *)&CManip::`vftable';
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  p_m_strVal->m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  this->m_pFunc = p;
  ATL::CSimpleStringT<char,0>::operator=(this: p_m_strVal, strSrc: &s);
  v6 = s.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)s.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v6 + 4))(a1: v6);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009D610
// Name: public: CColorList::~CColorList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorList::~CColorList(CColorList *this)
{
  std::_List_nod<unsigned long>::_Node *Myhead; // ecx
  std::_List_nod<unsigned long>::_Node *Next; // eax
  std::_List_nod<unsigned long>::_Node *v4; // edi

  Myhead = this->_Myhead;
  Next = Myhead->_Next;
  Myhead->_Next = Myhead;
  this->_Myhead->_Prev = this->_Myhead;
  this->_Mysize = 0;
  if ( Next != this->_Myhead )
  {
    do
    {
      v4 = Next->_Next;
      operator delete(p: Next);
      Next = v4;
    }
    while ( v4 != this->_Myhead );
  }
  operator delete(p: this->_Myhead);
}

//------------------------------------------------------------------------------
// Address: 0x1009D690
// Name: public: void CRTFBuilder::color(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRTFBuilder::color(CRTFBuilder *this, unsigned int c)
{
  std::_List_nod<unsigned long>::_Node *Myhead; // ecx
  std::_List_nod<unsigned long>::_Node *Next; // eax
  int v5; // edx
  std::_List_nod<unsigned long>::_Node *v6; // edi
  std::_List_nod<unsigned long>::_Node *v7; // eax
  unsigned int Mysize; // ecx

  Myhead = this->m_colorList._Myhead;
  Next = Myhead->_Next;
  v5 = 0;
  if ( Myhead->_Next == Myhead )
    goto LABEL_6;
  while ( Next->_Myval != c )
  {
    Next = Next->_Next;
    ++v5;
    if ( Next == Myhead )
      goto LABEL_6;
  }
  if ( v5 < 0 )
  {
LABEL_6:
    v6 = Myhead;
    v7 = std::_List_val<unsigned long>::_Buynode(
           this: &this->m_colorList,
           _Next: Myhead,
           _Prev: Myhead->_Prev,
           _Val: &c);
    Mysize = this->m_colorList._Mysize;
    if ( Mysize == 1073741822 )
      std::_Xlength_error(_Message: "list<T> too long");
    this->m_colorList._Mysize = Mysize + 1;
    v6->_Prev = v7;
    v7->_Prev->_Next = v7;
    this->m_attr.m_nColorFground = this->m_colorList._Mysize - 1;
  }
  else
  {
    this->m_attr.m_nColorFground = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D710
// Name: EditStreamCallBack
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall EditStreamCallBack(
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *dwCookie,
        unsigned __int8 *pbBuff,
        int cb,
        int *pcb)
{
  signed int v4; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v6; // eax
  int *v7; // eax

  v4 = *((_DWORD *)dwCookie->m_pszData - 3);
  if ( v4 >= cb )
  {
    *pcb = cb;
    memcpy(dst: pbBuff, src: (unsigned __int8 *)dwCookie->m_pszData, count: cb);
    v6 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Right(
           this: dwCookie,
           result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pcb,
           nCount: *((_DWORD *)dwCookie->m_pszData - 3) - cb);
    ATL::CSimpleStringT<char,0>::operator=(this: dwCookie, strSrc: v6);
    v7 = pcb - 4;
    if ( _InterlockedDecrement(pcb - 1) <= 0 )
      (*(void (__stdcall **)(int *))(*(_DWORD *)*v7 + 4))(a1: v7);
    return 0;
  }
  else
  {
    *pcb = v4;
    memcpy(dst: pbBuff, src: (unsigned __int8 *)dwCookie->m_pszData, count: v4);
    ATL::CSimpleStringT<char,0>::Empty(this: dwCookie);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D7E0
// Name: public: void CRTFBuilder::write(class CRichEditCtrl __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRTFBuilder::write(CRTFBuilder *this, CRichEditCtrl *c)
{
  char *m_pszData; // eax
  int v3; // ebx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_string; // esi
  int v5; // edi
  HWND__ *m_hWnd; // [esp-10h] [ebp-28h]
  _editstream v7; // [esp+Ch] [ebp-Ch] BYREF

  m_pszData = this->m_string.m_pszData;
  v3 = *((_DWORD *)m_pszData - 3);
  p_m_string = &this->m_string;
  v5 = v3 + 1;
  if ( v3 + 1 < 0 )
    goto LABEL_2;
  if ( ((*((_DWORD *)m_pszData - 2) - v5) | (1 - *((_DWORD *)m_pszData - 1))) < 0 )
    ATL::CSimpleStringT<char,0>::PrepareWrite2(this: p_m_string, nLength: v3 + 1);
  p_m_string->m_pszData[v3] = 125;
  if ( v5 > *((_DWORD *)p_m_string->m_pszData - 2) )
LABEL_2:
    ATL::AtlThrowImpl(hr: -2147024809);
  *((_DWORD *)p_m_string->m_pszData - 3) = v5;
  p_m_string->m_pszData[v5] = 0;
  m_hWnd = c->m_hWnd;
  v7.dwCookie = (unsigned int)p_m_string;
  v7.dwError = 0;
  v7.pfnCallback = (unsigned int (__stdcall *)(unsigned int, unsigned __int8 *, int, int *))EditStreamCallBack;
  SendMessageA(hWnd: m_hWnd, Msg: 0x449u, wParam: 0x8002u, lParam: (LPARAM)&v7);
  ATL::CSimpleStringT<char,0>::Empty(this: p_m_string);
}

//------------------------------------------------------------------------------
// Address: 0x1009D870
// Name: public: struct std::_List_nod<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class std::allocator<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>>>::_Node __near * std::_List_val<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class std::allocator<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>>>::_Buynode(struct std::_List_nod<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class std::allocator<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>>>::_Node __near *,struct std::_List_nod<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class std::allocator<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>>>::_Node __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &)
// Source: json
//------------------------------------------------------------------------------
ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *__thiscall std::_List_val<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>>::_Buynode(
        std::_List_val<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >> *this,
        std::_List_nod<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >>::_Node *_Next,
        std::_List_nod<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >>::_Node *_Prev,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *_Val)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v5; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v6; // esi
  int v8; // [esp+0h] [ebp-2Ch] BYREF
  std::exception pExceptionObject; // [esp+Ch] [ebp-20h] BYREF
  void *p; // [esp+18h] [ebp-14h]
  int *v11; // [esp+1Ch] [ebp-10h]
  int v12; // [esp+28h] [ebp-4h]

  v11 = &v8;
  v5 = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)operator new(nSize: 0xCu);
  v6 = v5;
  p = v5;
  if ( v5 == nullptr )
  {
    _Next = nullptr;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Next);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    v12 = -1;
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  v12 = 1;
  v5->m_pszData = (char *)_Next;
  v5[1].m_pszData = (char *)_Prev;
  std::_Cons_val<std::allocator<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>>,ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>> const &>(
    _Alval: &this->_Alval,
    _Pdest: v5 + 2,
    _Src: _Val);
  v12 = -1;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1009D940
// Name: class CRTFBuilder __near & doWrite(class CRTFBuilder __near &,class CRichEditCtrl __near &)
// Source: json
//------------------------------------------------------------------------------
CRTFBuilder *__cdecl doWrite(CRTFBuilder *r, CRichEditCtrl *c)
{
  CRTFBuilder::write(this: r, c);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x1009D960
// Name: class CRTFBuilder __near & doColor(class CRTFBuilder __near &,int)
// Source: json
//------------------------------------------------------------------------------
CRTFBuilder *__cdecl doColor(CRTFBuilder *r, unsigned int n)
{
  CRTFBuilder::color(this: r, c: n);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x1009D980
// Name: class CIntManip color(int)
// Source: json
//------------------------------------------------------------------------------
CIntManip *__cdecl color(CIntManip *result, int n)
{
  ATL::IAtlStringMgr *StringManager; // eax

  result->__vftable = (CIntManip_vtbl *)&CManip::`vftable';
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  result->m_strVal.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  result->m_pFunc = doColor;
  result->m_nVal = n;
  result->__vftable = (CIntManip_vtbl *)&CIntManip::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009DA20
// Name: protected: void std::deque<class CTextAttributes,class std::allocator<class CTextAttributes>>::_Tidy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::deque<CTextAttributes>::_Tidy(std::deque<CTextAttributes> *this)
{
  unsigned int Mysize; // eax
  unsigned int v3; // eax
  unsigned int Mapsize; // ecx
  CTextAttributes *v5; // esi
  volatile signed __int32 *v6; // eax
  volatile signed __int32 *v7; // eax
  volatile signed __int32 *v8; // eax
  volatile signed __int32 *v9; // eax
  volatile signed __int32 *v10; // eax
  volatile signed __int32 *v11; // eax
  CBoolString *p_m_bsBold; // esi
  volatile signed __int32 *v13; // eax
  volatile signed __int32 *v14; // eax
  unsigned int v16; // esi
  void **v17; // eax

  while ( this->_Mysize != 0 )
  {
    Mysize = this->_Mysize;
    if ( Mysize != 0 )
    {
      v3 = Mysize + this->_Myoff - 1;
      Mapsize = this->_Mapsize;
      if ( Mapsize <= v3 )
        v3 -= Mapsize;
      v5 = this->_Map[v3];
      v6 = (volatile signed __int32 *)(v5->m_bsStrike.m_strOff.m_pszData - 16);
      if ( _InterlockedDecrement(v6 + 3) <= 0 )
        (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v6 + 4))(a1: v6);
      v7 = (volatile signed __int32 *)(v5->m_bsStrike.m_strOn.m_pszData - 16);
      if ( _InterlockedDecrement(v7 + 3) <= 0 )
        (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v7 + 4))(a1: v7);
      v8 = (volatile signed __int32 *)(v5->m_bsItalic.m_strOff.m_pszData - 16);
      if ( _InterlockedDecrement(v8 + 3) <= 0 )
        (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v8 + 4))(a1: v8);
      v9 = (volatile signed __int32 *)(v5->m_bsItalic.m_strOn.m_pszData - 16);
      if ( _InterlockedDecrement(v9 + 3) <= 0 )
        (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v9 + 4))(a1: v9);
      v10 = (volatile signed __int32 *)(v5->m_bsUnderline.m_strOff.m_pszData - 16);
      if ( _InterlockedDecrement(v10 + 3) <= 0 )
        (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v10 + 4))(a1: v10);
      v11 = (volatile signed __int32 *)(v5->m_bsUnderline.m_strOn.m_pszData - 16);
      if ( _InterlockedDecrement(v11 + 3) <= 0 )
        (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v11 + 4))(a1: v11);
      p_m_bsBold = &v5->m_bsBold;
      v13 = (volatile signed __int32 *)(p_m_bsBold->m_strOff.m_pszData - 16);
      if ( _InterlockedDecrement(v13 + 3) <= 0 )
        (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v13 + 4))(a1: v13);
      v14 = (volatile signed __int32 *)(p_m_bsBold->m_strOn.m_pszData - 16);
      if ( _InterlockedDecrement(v14 + 3) <= 0 )
        (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v14 + 4))(a1: v14);
      if ( this->_Mysize-- == 1 )
        this->_Myoff = 0;
    }
  }
  v16 = this->_Mapsize;
  while ( v16 != 0 )
  {
    v17 = (void **)&this->_Map[--v16];
    if ( *v17 != nullptr )
      operator delete(p: *v17);
  }
  if ( this->_Map != nullptr )
    operator delete(p: this->_Map);
  this->_Map = nullptr;
  this->_Mapsize = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009DC70
// Name: public: CTextAttributes::CTextAttributes(void)
// Source: json
//------------------------------------------------------------------------------
CTextAttributes *__thiscall CTextAttributes::CTextAttributes(CTextAttributes *this)
{
  char *v2; // ecx
  char *v3; // ecx
  char *v4; // ecx
  char *v5; // ecx
  char *v6; // ecx
  char *v7; // ecx
  char *v8; // ecx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v10; // [esp-8h] [ebp-2Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v11[4]; // [esp-4h] [ebp-28h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v12; // [esp+Ch] [ebp-18h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v13; // [esp+10h] [ebp-14h]
  CTextAttributes *v14; // [esp+14h] [ebp-10h]
  int v15; // [esp+20h] [ebp-4h]

  v11[0].m_pszData = (char *)this;
  v13 = v11;
  v14 = this;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: v11,
    pszSrc: &szGroupName);
  v15 = 0;
  v10.m_pszData = v2;
  v12 = &v10;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &v10,
    pszSrc: "\\b");
  v15 = -1;
  CBoolString::CBoolString(this: &this->m_bsBold, strOn: v10, strOff: v11[0]);
  v15 = 2;
  v11[0].m_pszData = v3;
  v12 = v11;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: v11,
    pszSrc: &szGroupName);
  LOBYTE(v15) = 3;
  v10.m_pszData = v4;
  v13 = &v10;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &v10,
    pszSrc: "\\ul");
  LOBYTE(v15) = 2;
  CBoolString::CBoolString(this: &this->m_bsUnderline, strOn: v10, strOff: v11[0]);
  LOBYTE(v15) = 5;
  v11[0].m_pszData = v5;
  v12 = v11;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: v11,
    pszSrc: &szGroupName);
  LOBYTE(v15) = 6;
  v10.m_pszData = v6;
  v13 = &v10;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &v10,
    pszSrc: "\\i");
  LOBYTE(v15) = 5;
  CBoolString::CBoolString(this: &this->m_bsItalic, strOn: v10, strOff: v11[0]);
  LOBYTE(v15) = 8;
  v11[0].m_pszData = v7;
  v12 = v11;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: v11,
    pszSrc: &szGroupName);
  LOBYTE(v15) = 9;
  v10.m_pszData = v8;
  v13 = &v10;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &v10,
    pszSrc: "\\strike");
  LOBYTE(v15) = 8;
  CBoolString::CBoolString(this: &this->m_bsStrike, strOn: v10, strOff: v11[0]);
  this->m_nFontSize = 0;
  this->m_nFontNumber = 0;
  this->m_nColorFground = 0;
  this->m_nColorBground = 0;
  this->m_bsBold.m_b = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009E080
// Name: public: virtual class CRTFBuilder __near & CControlManip::go(class CRTFBuilder __near &)
// Source: json
//------------------------------------------------------------------------------
CRTFBuilder *__thiscall CControlManip::go(CControlManip *this, CRTFBuilder *b)
{
  return ((CRTFBuilder *(__cdecl *)(CRTFBuilder *, CRichEditCtrl *))this->m_pFunc)(a1: b, a2: this->m_control);
}

//------------------------------------------------------------------------------
// Address: 0x1009E0A0
// Name: class CControlManip write(class CRichEditCtrl __near &)
// Source: json
//------------------------------------------------------------------------------
CControlManip *__cdecl write(CControlManip *result, CRichEditCtrl *c)
{
  char *v2; // ecx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v4[7]; // [esp-4h] [ebp-1Ch] BYREF

  v4[0].m_pszData = v2;
  v4[3].m_pszData = nullptr;
  v4[2].m_pszData = (char *)v4;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: v4,
    pszSrc: &szGroupName);
  v4[6].m_pszData = nullptr;
  CManip::CManip(this: result, p: doWrite, s: v4[0]);
  result->__vftable = (CControlManip_vtbl *)&CControlManip::`vftable';
  result->m_control = c;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009E120
// Name: public: class CRTFBuilder __near & CRTFBuilder::operator+=(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CRTFBuilder *__thiscall CRTFBuilder::operator+=(CRTFBuilder *this, const char *p)
{
  int v2; // edi
  ATL::IAtlStringMgr *StringManager; // eax
  char *v4; // ebx
  char *m_pszData; // esi
  int v6; // eax
  char v7; // dl
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v8; // esi
  char *v9; // eax
  CRTFBuilder *v10; // esi
  char *v11; // esi
  int (__thiscall ***v12)(_DWORD, _DWORD, int); // eax
  char *v13; // edi
  int v14; // edi
  int v15; // esi
  int v16; // eax
  char *v17; // esi
  int (__thiscall ***v18)(_DWORD, _DWORD, int); // eax
  char *v19; // edi
  int v20; // eax
  char *v21; // esi
  int (__thiscall ***v22)(_DWORD, _DWORD, int); // eax
  char *v23; // edi
  int v24; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v25; // esi
  char *v26; // edi
  char *v27; // eax
  volatile signed __int32 *v28; // edi
  const char *v29; // eax
  int v30; // eax
  char *v31; // eax
  char *v32; // eax
  char *v33; // eax
  volatile signed __int32 *v34; // ebx
  char *v35; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v37; // [esp+Ch] [ebp-30h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v38; // [esp+10h] [ebp-2Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v39; // [esp+14h] [ebp-28h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v40; // [esp+18h] [ebp-24h] BYREF
  ATL::CSimpleStringT<char,0> v41; // [esp+1Ch] [ebp-20h] BYREF
  CRTFBuilder *v42; // [esp+20h] [ebp-1Ch]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > s; // [esp+24h] [ebp-18h] BYREF
  int i; // [esp+28h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > s2; // [esp+2Ch] [ebp-10h] BYREF
  int v46; // [esp+38h] [ebp-4h]

  v42 = this;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &s,
    pszSrc: p);
  v2 = 0;
  v46 = 0;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  v4 = (char *)&StringManager->GetNilString(this: StringManager)[1];
  s2.m_pszData = v4;
  LOBYTE(v46) = 2;
  m_pszData = s.m_pszData;
  v6 = *((_DWORD *)s.m_pszData - 3);
  i = 0;
  if ( v6 > 0 )
  {
    while ( v2 >= 0 && v2 <= v6 )
    {
      v7 = m_pszData[v2];
      HIBYTE(p) = v7;
      if ( v7 == 10 )
      {
        v8 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
               this: &v38,
               pszSrc: "\r\n");
        LOBYTE(v46) = 3;
        ATL::CSimpleStringT<char,0>::Append(this: v8, pszSrc: "\\par ", nLength: 5);
        ATL::CSimpleStringT<char,0>::Append(this: &s2, pszSrc: v8->m_pszData, nLength: *((_DWORD *)v8->m_pszData - 3));
        LOBYTE(v46) = 2;
        v9 = v38.m_pszData - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)v38.m_pszData - 1) <= 0 )
          (*(void (__stdcall **)(char *))(**(_DWORD **)v9 + 4))(a1: v9);
        v4 = s2.m_pszData;
      }
      else
      {
        if ( v2 > v6 )
          break;
        v14 = *((_DWORD *)v4 - 3);
        v15 = v14 + 1;
        if ( v14 + 1 < 0 )
          break;
        if ( ((1 - *((_DWORD *)v4 - 1)) | (*((_DWORD *)v4 - 2) - v15)) < 0 )
        {
          ATL::CSimpleStringT<char,0>::PrepareWrite2(this: &s2, nLength: v14 + 1);
          v4 = s2.m_pszData;
          v7 = HIBYTE(p);
        }
        v4[v14] = v7;
        if ( v15 > *((_DWORD *)v4 - 2) )
          break;
        v2 = i;
        *((_DWORD *)v4 - 3) = v15;
        v4[v15] = 0;
      }
      m_pszData = s.m_pszData;
      v6 = *((_DWORD *)s.m_pszData - 3);
      i = ++v2;
      if ( v2 >= v6 )
        goto LABEL_11;
    }
    ATL::AtlThrowImpl(hr: -2147024809);
  }
LABEL_11:
  v10 = v42;
  CTextAttributes::operator ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &v42->m_attr,
    result: &v38);
  LOBYTE(v46) = 5;
  CColorList::operator ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &v10->m_colorList,
    result: &v39);
  LOBYTE(v46) = 6;
  CFontList::operator ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &v10->m_fontList, result: &v40);
  LOBYTE(v46) = 7;
  v11 = v38.m_pszData;
  v12 = (int (__thiscall ***)(_DWORD, _DWORD, int))(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v38.m_pszData - 4) + 16))(a1: *((_DWORD *)v38.m_pszData - 4));
  if ( *((int *)v11 - 1) >= 0 && v12 == *((int (__thiscall ****)(_DWORD, _DWORD, int))v11 - 4) )
  {
    v13 = v11 - 16;
    _InterlockedExchangeAdd((volatile signed __int32 *)v11 - 1, 1u);
  }
  else
  {
    v16 = (**v12)(a1: v12, a2: *((_DWORD *)v11 - 3), a3: 1);
    v13 = (char *)v16;
    if ( v16 == 0 )
      ATL::CSimpleStringT<char,0>::ThrowMemoryException();
    *(_DWORD *)(v16 + 4) = *((_DWORD *)v11 - 3);
    memcpy_s(dst: (void *)(v16 + 16), sizeInBytes: *((_DWORD *)v11 - 3) + 1, src: v11, count: *((_DWORD *)v11 - 3) + 1);
  }
  i = (int)(v13 + 16);
  LOBYTE(v46) = 9;
  v17 = v39.m_pszData;
  v18 = (int (__thiscall ***)(_DWORD, _DWORD, int))(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v39.m_pszData - 4) + 16))(a1: *((_DWORD *)v39.m_pszData - 4));
  if ( *((int *)v17 - 1) >= 0 && v18 == *((int (__thiscall ****)(_DWORD, _DWORD, int))v17 - 4) )
  {
    v19 = v17 - 16;
    _InterlockedExchangeAdd((volatile signed __int32 *)v17 - 1, 1u);
  }
  else
  {
    v20 = (**v18)(a1: v18, a2: *((_DWORD *)v17 - 3), a3: 1);
    v19 = (char *)v20;
    if ( v20 == 0 )
      ATL::CSimpleStringT<char,0>::ThrowMemoryException();
    *(_DWORD *)(v20 + 4) = *((_DWORD *)v17 - 3);
    memcpy_s(dst: (void *)(v20 + 16), sizeInBytes: *((_DWORD *)v17 - 3) + 1, src: v17, count: *((_DWORD *)v17 - 3) + 1);
  }
  p = v19 + 16;
  LOBYTE(v46) = 11;
  v21 = v40.m_pszData;
  v22 = (int (__thiscall ***)(_DWORD, _DWORD, int))(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v40.m_pszData - 4) + 16))(a1: *((_DWORD *)v40.m_pszData - 4));
  if ( *((int *)v21 - 1) >= 0 && v22 == *((int (__thiscall ****)(_DWORD, _DWORD, int))v21 - 4) )
  {
    v23 = v21 - 16;
    _InterlockedExchangeAdd((volatile signed __int32 *)v21 - 1, 1u);
  }
  else
  {
    v24 = (**v22)(a1: v22, a2: *((_DWORD *)v21 - 3), a3: 1);
    v23 = (char *)v24;
    if ( v24 == 0 )
      ATL::CSimpleStringT<char,0>::ThrowMemoryException();
    *(_DWORD *)(v24 + 4) = *((_DWORD *)v21 - 3);
    memcpy_s(dst: (void *)(v24 + 16), sizeInBytes: *((_DWORD *)v21 - 3) + 1, src: v21, count: *((_DWORD *)v21 - 3) + 1);
  }
  v41.m_pszData = v23 + 16;
  LOBYTE(v46) = 13;
  v25 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
          this: &v37,
          pszSrc: "{\\rtf1\\ansi\\ansicpg1252\\deff0\\deftab720");
  LOBYTE(v46) = 14;
  ATL::CSimpleStringT<char,0>::Append(this: (ATL::CSimpleStringT<char,0> *)&i, pszSrc: v4, nLength: *((_DWORD *)v4 - 3));
  ATL::CSimpleStringT<char,0>::Append(
    this: (ATL::CSimpleStringT<char,0> *)&p,
    pszSrc: (const char *)i,
    nLength: *(_DWORD *)(i - 12));
  ATL::CSimpleStringT<char,0>::Append(this: &v41, pszSrc: p, nLength: *((_DWORD *)p - 3));
  v26 = v41.m_pszData;
  ATL::CSimpleStringT<char,0>::Append(this: v25, pszSrc: v41.m_pszData, nLength: *((_DWORD *)v41.m_pszData - 3));
  ATL::CSimpleStringT<char,0>::Append(
    this: &v42->m_string,
    pszSrc: v25->m_pszData,
    nLength: *((_DWORD *)v25->m_pszData - 3));
  LOBYTE(v46) = 13;
  v27 = v37.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)v37.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v27 + 4))(a1: v27);
  LOBYTE(v46) = 11;
  v28 = (volatile signed __int32 *)(v26 - 16);
  if ( _InterlockedDecrement(v28 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v28 + 4))(a1: v28);
  LOBYTE(v46) = 9;
  v29 = p - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)p - 1) <= 0 )
    (*(void (__stdcall **)(const char *))(**(_DWORD **)v29 + 4))(a1: v29);
  LOBYTE(v46) = 7;
  v30 = i - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)(i - 16 + 12)) <= 0 )
    (*(void (__stdcall **)(int))(**(_DWORD **)v30 + 4))(a1: v30);
  LOBYTE(v46) = 6;
  v31 = v40.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)v40.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v31 + 4))(a1: v31);
  LOBYTE(v46) = 5;
  v32 = v39.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)v39.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v32 + 4))(a1: v32);
  LOBYTE(v46) = 2;
  v33 = v38.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)v38.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v33 + 4))(a1: v33);
  LOBYTE(v46) = 0;
  v34 = (volatile signed __int32 *)(v4 - 16);
  if ( _InterlockedDecrement(v34 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v34 + 4))(a1: v34);
  v46 = -1;
  v35 = s.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)s.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v35 + 4))(a1: v35);
  return v42;
}

//------------------------------------------------------------------------------
// Address: 0x1009E580
// Name: public: class CRTFBuilder __near & CRTFBuilder::operator<<(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CRTFBuilder *__thiscall CRTFBuilder::operator<<(CRTFBuilder *this, const char *p)
{
  CRTFBuilder::operator+=(this, p);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009E5A0
// Name: public: std::deque<class CTextAttributes,class std::allocator<class CTextAttributes>>::~deque<class CTextAttributes,class std::allocator<class CTextAttributes>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::deque<CTextAttributes>::~deque<CTextAttributes>(std::deque<CTextAttributes> *this)
{
  std::deque<CTextAttributes>::_Tidy(this);
  operator delete(p: this->_Myproxy);
  this->_Myproxy = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1009E600
// Name: public: void std::list<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class std::allocator<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>>>::clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::list<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>>::clear(
        std::list<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >> *this)
{
  std::_List_nod<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >>::_Node *Next; // esi
  std::_List_nod<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >>::_Node *v3; // edi
  volatile signed __int32 *v4; // eax

  Next = this->_Myhead->_Next;
  this->_Myhead->_Next = this->_Myhead;
  this->_Myhead->_Prev = this->_Myhead;
  this->_Mysize = 0;
  if ( Next != this->_Myhead )
  {
    do
    {
      v3 = Next->_Next;
      v4 = (volatile signed __int32 *)(Next->_Myval.m_pszData - 16);
      if ( _InterlockedDecrement(v4 + 3) <= 0 )
        (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v4 + 4))(a1: v4);
      operator delete(p: Next);
      Next = v3;
    }
    while ( v3 != this->_Myhead );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E690
// Name: public: std::stack<class CTextAttributes,class std::deque<class CTextAttributes,class std::allocator<class CTextAttributes>>>::~stack<class CTextAttributes,class std::deque<class CTextAttributes,class std::allocator<class CTextAttributes>>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::stack<CTextAttributes>::~stack<CTextAttributes,std::deque<CTextAttributes>>(
        std::stack<CTextAttributes> *this)
{
  std::deque<CTextAttributes>::_Tidy(this: &this->c);
  operator delete(p: this->c._Myproxy);
  this->c._Myproxy = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1009E6F0
// Name: public: std::list<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class std::allocator<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>>>::~list<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class std::allocator<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::list<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>>::~list<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>>(
        std::list<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >> *this)
{
  std::list<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>>::clear(this);
  operator delete(p: this->_Myhead);
}

//------------------------------------------------------------------------------
// Address: 0x1009E740
// Name: public: CFontList::~CFontList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontList::~CFontList(CFontList *this)
{
  std::list<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>>::clear(this);
  operator delete(p: this->_Myhead);
}

//------------------------------------------------------------------------------
// Address: 0x1009E790
// Name: public: virtual CRTFBuilder::~CRTFBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRTFBuilder::~CRTFBuilder(CRTFBuilder *this)
{
  std::stack<CTextAttributes> *p_m_attrStack; // edi
  CColorList *p_m_colorList; // edi
  std::_List_nod<unsigned long>::_Node *Myhead; // eax
  std::_List_nod<unsigned long>::_Node *Next; // ecx
  std::_List_nod<unsigned long>::_Node *v6; // ebx
  volatile signed __int32 *v7; // eax

  this->__vftable = (CRTFBuilder_vtbl *)&CRTFBuilder::`vftable';
  p_m_attrStack = &this->m_attrStack;
  std::deque<CTextAttributes>::_Tidy(this: &this->m_attrStack.c);
  operator delete(p: p_m_attrStack->c._Myproxy);
  p_m_attrStack->c._Myproxy = nullptr;
  p_m_colorList = &this->m_colorList;
  Myhead = this->m_colorList._Myhead;
  Next = Myhead->_Next;
  Myhead->_Next = Myhead;
  this->m_colorList._Myhead->_Prev = this->m_colorList._Myhead;
  this->m_colorList._Mysize = 0;
  if ( Next != this->m_colorList._Myhead )
  {
    do
    {
      v6 = Next->_Next;
      operator delete(p: Next);
      Next = v6;
    }
    while ( v6 != p_m_colorList->_Myhead );
  }
  operator delete(p: p_m_colorList->_Myhead);
  std::list<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>>::clear(this: &this->m_fontList);
  operator delete(p: this->m_fontList._Myhead);
  CInstanceParmData::~CInstanceParmData(this: &this->m_attr.m_bsStrike);
  CInstanceParmData::~CInstanceParmData(this: &this->m_attr.m_bsItalic);
  CInstanceParmData::~CInstanceParmData(this: &this->m_attr.m_bsUnderline);
  CInstanceParmData::~CInstanceParmData(this: &this->m_attr.m_bsBold);
  v7 = (volatile signed __int32 *)(this->m_string.m_pszData - 16);
  if ( _InterlockedDecrement(v7 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v7 + 4))(a1: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1009E8D0
// Name: public: CRTFBuilder::CRTFBuilder(void)
// Source: json
//------------------------------------------------------------------------------
CRTFBuilder *__thiscall CRTFBuilder::CRTFBuilder(CRTFBuilder *this)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_string; // esi
  ATL::IAtlStringMgr *StringManager; // eax
  CFontList *p_m_fontList; // ebx
  std::_List_nod<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >>::_Node *v5; // eax
  CColorList *p_m_colorList; // esi
  std::_List_nod<unsigned long>::_Node *v7; // eax
  std::stack<CTextAttributes> *p_m_attrStack; // edi
  std::_Container_proxy *v9; // eax
  std::_List_nod<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >>::_Node *Myhead; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v11; // eax
  unsigned int Mysize; // ecx
  char *v13; // eax
  std::_List_nod<unsigned long>::_Node *v14; // edi
  std::_List_nod<unsigned long>::_Node *v15; // eax
  unsigned int v16; // ecx
  std::_List_nod<unsigned long>::_Node *v17; // edi
  std::_List_nod<unsigned long>::_Node *v18; // eax
  unsigned int v19; // ecx
  std::_List_nod<unsigned long>::_Node *v20; // edi
  std::_List_nod<unsigned long>::_Node *v21; // eax
  unsigned int v22; // ecx
  std::_List_nod<unsigned long>::_Node *v23; // edi
  std::_List_nod<unsigned long>::_Node *v24; // eax
  unsigned int v25; // ecx
  CRTFBuilder *result; // eax
  std::_List_nod<unsigned long>::_Node *v27; // [esp-Ch] [ebp-4Ch]
  std::_List_nod<unsigned long>::_Node *v28; // [esp-Ch] [ebp-4Ch]
  std::_List_nod<unsigned long>::_Node *v29; // [esp-Ch] [ebp-4Ch]
  std::_List_nod<unsigned long>::_Node *v30; // [esp-Ch] [ebp-4Ch]
  std::_List_nod<unsigned long>::_Node *Prev; // [esp-8h] [ebp-48h]
  std::_List_nod<unsigned long>::_Node *v32; // [esp-8h] [ebp-48h]
  std::_List_nod<unsigned long>::_Node *v33; // [esp-8h] [ebp-48h]
  std::_List_nod<unsigned long>::_Node *v34; // [esp-8h] [ebp-48h]
  std::exception v35; // [esp+8h] [ebp-38h] BYREF
  std::exception pExceptionObject; // [esp+14h] [ebp-2Ch] BYREF
  vgui::ToolWindow *v37; // [esp+20h] [ebp-20h]
  char *v38; // [esp+24h] [ebp-1Ch] BYREF
  char *_What; // [esp+28h] [ebp-18h] BYREF
  CRTFBuilder *v40; // [esp+2Ch] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > _Val; // [esp+30h] [ebp-10h] BYREF
  int v42; // [esp+3Ch] [ebp-4h]

  p_m_string = &this->m_string;
  v40 = this;
  this->__vftable = (CRTFBuilder_vtbl *)&CRTFBuilder::`vftable';
  v38 = (char *)&this->m_string;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  p_m_string->m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v42 = 2;
  CTextAttributes::CTextAttributes(this: &this->m_attr);
  p_m_fontList = &this->m_fontList;
  v38 = (char *)&this->m_fontList;
  this->m_fontList._Mysize = 0;
  v5 = (std::_List_nod<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >>::_Node *)operator new(nSize: 0xCu);
  if ( v5 == nullptr )
  {
    _What = nullptr;
    std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    LOBYTE(v42) = 2;
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  p_m_fontList->_Myhead = v5;
  v5->_Next = v5;
  p_m_fontList->_Myhead->_Prev = p_m_fontList->_Myhead;
  LOBYTE(v42) = 6;
  p_m_colorList = &this->m_colorList;
  _Val.m_pszData = (char *)&this->m_colorList;
  this->m_colorList._Mysize = 0;
  v7 = (std::_List_nod<unsigned long>::_Node *)operator new(nSize: 0xCu);
  if ( v7 == nullptr )
  {
    v38 = nullptr;
    std::exception::exception(this: &v35, _What: (const char *const *)&v38);
    v35.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    LOBYTE(v42) = 6;
    _CxxThrowException(pExceptionObject: &v35, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  p_m_colorList->_Myhead = v7;
  v7->_Next = v7;
  p_m_colorList->_Myhead->_Prev = p_m_colorList->_Myhead;
  LOBYTE(v42) = 10;
  p_m_attrStack = &this->m_attrStack;
  _Val.m_pszData = (char *)p_m_attrStack;
  p_m_attrStack->c._Myproxy = nullptr;
  v9 = (std::_Container_proxy *)operator new(nSize: 8u);
  if ( v9 == nullptr )
  {
    _What = nullptr;
    std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    LOBYTE(v42) = 10;
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  p_m_attrStack->c._Myproxy = v9;
  v38 = (char *)v9;
  v37 = (vgui::ToolWindow *)v9;
  v9->_Mycont = nullptr;
  v9->_Myfirstiter = nullptr;
  LOBYTE(v42) = 10;
  p_m_attrStack->c._Myproxy->_Mycont = &p_m_attrStack->c;
  p_m_attrStack->c._Map = nullptr;
  p_m_attrStack->c._Mapsize = 0;
  p_m_attrStack->c._Myoff = 0;
  p_m_attrStack->c._Mysize = 0;
  LOBYTE(v42) = 15;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &_Val,
    pszSrc: "Arial");
  LOBYTE(v42) = 16;
  Myhead = p_m_fontList->_Myhead;
  v11 = std::_List_val<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>>::_Buynode(
          this: p_m_fontList,
          _Next: p_m_fontList->_Myhead,
          _Prev: p_m_fontList->_Myhead->_Prev,
          &_Val);
  Mysize = p_m_fontList->_Mysize;
  if ( Mysize == 1073741822 )
    std::_Xlength_error(_Message: "list<T> too long");
  p_m_fontList->_Mysize = Mysize + 1;
  Myhead->_Prev = (std::_List_nod<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >>::_Node *)v11;
  *(_DWORD *)v11[1].m_pszData = v11;
  LOBYTE(v42) = 15;
  v13 = _Val.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)_Val.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v13 + 4))(a1: v13);
  v14 = p_m_colorList->_Myhead;
  Prev = p_m_colorList->_Myhead->_Prev;
  v27 = p_m_colorList->_Myhead;
  _Val.m_pszData = nullptr;
  v15 = std::_List_val<unsigned long>::_Buynode(
          this: p_m_colorList,
          _Next: v27,
          _Prev: Prev,
          (const unsigned int *)&_Val);
  v16 = p_m_colorList->_Mysize;
  if ( v16 == 1073741822 )
    std::_Xlength_error(_Message: "list<T> too long");
  p_m_colorList->_Mysize = v16 + 1;
  v14->_Prev = v15;
  v15->_Prev->_Next = v15;
  v17 = p_m_colorList->_Myhead;
  v32 = p_m_colorList->_Myhead->_Prev;
  v28 = p_m_colorList->_Myhead;
  _Val.m_pszData = (char *)255;
  v18 = std::_List_val<unsigned long>::_Buynode(
          this: p_m_colorList,
          _Next: v28,
          _Prev: v32,
          (const unsigned int *)&_Val);
  v19 = p_m_colorList->_Mysize;
  if ( v19 == 1073741822 )
    std::_Xlength_error(_Message: "list<T> too long");
  p_m_colorList->_Mysize = v19 + 1;
  v17->_Prev = v18;
  v18->_Prev->_Next = v18;
  v20 = p_m_colorList->_Myhead;
  v33 = p_m_colorList->_Myhead->_Prev;
  v29 = p_m_colorList->_Myhead;
  _Val.m_pszData = (char *)65280;
  v21 = std::_List_val<unsigned long>::_Buynode(
          this: p_m_colorList,
          _Next: v29,
          _Prev: v33,
          (const unsigned int *)&_Val);
  v22 = p_m_colorList->_Mysize;
  if ( v22 == 1073741822 )
    std::_Xlength_error(_Message: "list<T> too long");
  p_m_colorList->_Mysize = v22 + 1;
  v20->_Prev = v21;
  v21->_Prev->_Next = v21;
  v23 = p_m_colorList->_Myhead;
  v34 = p_m_colorList->_Myhead->_Prev;
  v30 = p_m_colorList->_Myhead;
  _Val.m_pszData = (char *)16711680;
  v24 = std::_List_val<unsigned long>::_Buynode(
          this: p_m_colorList,
          _Next: v30,
          _Prev: v34,
          (const unsigned int *)&_Val);
  v25 = p_m_colorList->_Mysize;
  if ( v25 == 1073741822 )
    std::_Xlength_error(_Message: "list<T> too long");
  p_m_colorList->_Mysize = v25 + 1;
  v23->_Prev = v24;
  v24->_Prev->_Next = v24;
  result = v40;
  v40->m_attr.m_nFontSize = 35;
  v42 = -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F8A80
// Name: protected: virtual struct AFX_MSGMAP const __near * CRichEditCtrlEx::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CRichEditCtrlEx::GetMessageMap(CRichEditCtrlEx *this)
{
  return (const AFX_MSGMAP *)&off_105F2924;
}

//------------------------------------------------------------------------------
// Address: 0x1034AB9B
// Name: public: virtual CRichEditCtrl::~CRichEditCtrl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRichEditCtrl::~CRichEditCtrl(CRichEditCtrl *this)
{
  this->__vftable = (CRichEditCtrl_vtbl *)&CRichEditCtrl::`vftable';
  CWnd::DestroyWindow(this);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034ABFC
// Name: public: virtual struct CRuntimeClass __near * CRichEditCtrl::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CRichEditCtrl::GetRuntimeClass(CRichEditCtrl *this)
{
  return &CRichEditCtrl::classCRichEditCtrl;
}

//------------------------------------------------------------------------------
// Address: 0x1034EE2F
// Name: public: void CRichEditCtrl::LineScroll(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRichEditCtrl::LineScroll(CRichEditCtrl *this, LPARAM nLines, WPARAM nChars)
{
  SendMessageA(hWnd: this->m_hWnd, Msg: 0xB6u, wParam: nChars, lParam: nLines);
}

//------------------------------------------------------------------------------
// Address: 0x1034EE4C
// Name: public: void CRichEditCtrl::SetSel(long,long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRichEditCtrl::SetSel(CRichEditCtrl *this, int nStartChar, int nEndChar)
{
  _charrange cr; // [esp+0h] [ebp-8h] BYREF

  cr.cpMin = nStartChar;
  cr.cpMax = nEndChar;
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x437u, wParam: 0, lParam: (LPARAM)&cr);
}

//------------------------------------------------------------------------------
// Address: 0x1034EF23
// Name: public: int CRichEditCtrl::Create(unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRichEditCtrl::Create(
        CRichEditCtrl *this,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int nID)
{
  int result; // eax

  result = AfxInitRichEdit2();
  if ( result != 0 )
    return this->Create(
             this,
             a2: "RichEdit20A",
             a3: nullptr,
             a4: dwStyle,
             a5: rect,
             a6: pParentWnd,
             a7: nID,
             a8: nullptr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10389C7A
// Name: protected: virtual void CMDIClientAreaWnd::PreSubclassWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDIClientAreaWnd::PreSubclassWindow(CMDIClientAreaWnd *this)
{
  CMultiPaneFrameWnd::AdjustLayout((CMFCRibbonBaseElement *)this);
  this->CreateTabGroup(this, a2: &this->m_wndTab);
}

//------------------------------------------------------------------------------
// Address: 0x10397CC4
// Name: protected: virtual void CMFCShellListCtrl::PreSubclassWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCShellListCtrl::PreSubclassWindow(CMFCShellListCtrl *this)
{
  CMFCListCtrl::PreSubclassWindow(this);
  if ( AfxGetThreadState()->m_pWndInit == nullptr )
    CMFCShellListCtrl::InitList(this);
}

//------------------------------------------------------------------------------
// Address: 0x1039974D
// Name: protected: virtual void CVSListBoxBase::PreSubclassWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVSListBoxBase::PreSubclassWindow(CVSListBoxBase *this)
{
  CMultiPaneFrameWnd::AdjustLayout((CMFCRibbonBaseElement *)this);
  if ( AfxGetThreadState()->m_pWndInit == nullptr )
    CVSListBoxBase::Init(this);
}

//------------------------------------------------------------------------------
// Address: 0x1039B3E8
// Name: protected: virtual void CMFCShellTreeCtrl::PreSubclassWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCShellTreeCtrl::PreSubclassWindow(CMFCShellTreeCtrl *this)
{
  CMultiPaneFrameWnd::AdjustLayout((CMFCRibbonBaseElement *)this);
  if ( AfxGetThreadState()->m_pWndInit == nullptr )
    CMFCShellTreeCtrl::InitTree(this);
}

//------------------------------------------------------------------------------
// Address: 0x1039B530
// Name: protected: virtual void CMFCPropertyGridCtrl::PreSubclassWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::PreSubclassWindow(CMFCPropertyGridCtrl *this)
{
  CMultiPaneFrameWnd::AdjustLayout((CMFCRibbonBaseElement *)this);
  if ( AfxGetThreadState()->m_pWndInit == nullptr )
    this->Init(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A3913
// Name: protected: virtual void CMFCFontComboBox::PreSubclassWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCFontComboBox::PreSubclassWindow(CMFCFontComboBox *this)
{
  CMultiPaneFrameWnd::AdjustLayout((CMFCRibbonBaseElement *)this);
  if ( AfxGetThreadState()->m_pWndInit == nullptr )
    CMFCFontComboBox::Init(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A6895
// Name: protected: virtual void CMFCButton::PreSubclassWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCButton::PreSubclassWindow(CMFCButton *this)
{
  unsigned int Style; // eax

  Style = CWnd::GetStyle(this);
  CMFCButton::InitStyle(this, dwStyle: Style);
  CWnd::ModifyStyle(this, dwRemove: 1u, dwAdd: 0xBu, nFlags: 0);
  CMultiPaneFrameWnd::AdjustLayout((CMFCRibbonBaseElement *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1040B677
// Name: protected: virtual void CMFCListCtrl::PreSubclassWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCListCtrl::PreSubclassWindow(CMFCListCtrl *this)
{
  CMultiPaneFrameWnd::AdjustLayout((CMFCRibbonBaseElement *)this);
  if ( AfxGetThreadState()->m_pWndInit == nullptr )
    CMFCListCtrl::InitList(this);
}

//------------------------------------------------------------------------------
// Address: 0x1040CE23
// Name: protected: virtual void CMFCHeaderCtrl::PreSubclassWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCHeaderCtrl::PreSubclassWindow(CMFCHeaderCtrl *this)
{
  CMFCHeaderCtrl::CommonInit(this);
  CMultiPaneFrameWnd::AdjustLayout((CMFCRibbonBaseElement *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10423FC1
// Name: protected: virtual void CMFCImagePaintArea::PreSubclassWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCImagePaintArea::PreSubclassWindow(CMFCImagePaintArea *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v3; // eax
  AFX_MODULE_STATE *v4; // eax
  AFX_MODULE_STATE *v5; // eax
  AFX_MODULE_STATE *v6; // eax
  AFX_MODULE_STATE *v7; // eax

  AfxGetModuleState();
  ModuleState = AfxGetModuleState();
  this->m_hcurPen = LoadCursorW(hInstance: ModuleState->m_hCurrentResourceHandle, lpCursorName: (LPCWSTR)0x3F10);
  AfxGetModuleState();
  v3 = AfxGetModuleState();
  this->m_hcurFill = LoadCursorW(hInstance: v3->m_hCurrentResourceHandle, lpCursorName: (LPCWSTR)0x3F0E);
  AfxGetModuleState();
  v4 = AfxGetModuleState();
  this->m_hcurLine = LoadCursorW(hInstance: v4->m_hCurrentResourceHandle, lpCursorName: (LPCWSTR)0x3F0F);
  AfxGetModuleState();
  v5 = AfxGetModuleState();
  this->m_hcurRect = LoadCursorW(hInstance: v5->m_hCurrentResourceHandle, lpCursorName: (LPCWSTR)0x3F0C);
  AfxGetModuleState();
  v6 = AfxGetModuleState();
  this->m_hcurEllipse = LoadCursorW(hInstance: v6->m_hCurrentResourceHandle, lpCursorName: (LPCWSTR)0x3F0D);
  AfxGetModuleState();
  v7 = AfxGetModuleState();
  this->m_hcurColor = LoadCursorW(hInstance: v7->m_hCurrentResourceHandle, lpCursorName: (LPCWSTR)0x3F11);
  CMultiPaneFrameWnd::AdjustLayout((CMFCRibbonBaseElement *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10433CDB
// Name: protected: virtual void CMFCToolBarsCommandsListBox::PreSubclassWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsCommandsListBox::PreSubclassWindow(CMFCToolBarsCommandsListBox *this)
{
  int v2; // ecx
  CSize sizeMenuImage; // [esp+4h] [ebp-8h] BYREF

  CMultiPaneFrameWnd::AdjustLayout((CMFCRibbonBaseElement *)this);
  CMFCToolBar::GetMenuImageSize(result: &sizeMenuImage);
  v2 = sizeMenuImage.cy + 6;
  this->m_sizeButton.cx = sizeMenuImage.cx + 6;
  this->m_sizeButton.cy = v2;
}

//------------------------------------------------------------------------------
// Address: 0x104343F6
// Name: protected: virtual void CMFCColorPickerCtrl::PreSubclassWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::PreSubclassWindow(CMFCColorPickerCtrl *this)
{
  CWnd::ModifyStyle(this, dwRemove: 1u, dwAdd: 0xBu, nFlags: 0);
  CMultiPaneFrameWnd::AdjustLayout((CMFCRibbonBaseElement *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1043B55B
// Name: __write
// Source: json
//------------------------------------------------------------------------------
int __cdecl _write(int fh, const void *buf, unsigned int cnt)
{
  ioinfo **v4; // edi
  int v5; // esi
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v4 = &__pioinfo[fh >> 5], v5 = (fh & 0x1F) << 6, (*(&(*v4)->osfile + v5) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v4)->osfile + v5) & 1) != 0 )
  {
    r = _write_nolock(fh, buf, cnt);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x1034EE77
// Name: public: static class CNoTrackObject __near * CProcessLocal<class _AFX_RICHEDIT_STATE>::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_AFX_EDIT_STATE *__stdcall CProcessLocal<_AFX_RICHEDIT_STATE>::CreateObject()
{
  _AFX_EDIT_STATE *v0; // esi
  _AFX_EDIT_STATE *result; // eax

  v0 = (_AFX_EDIT_STATE *)CNoTrackObject::operator new(nSize: 0x28u);
  result = nullptr;
  if ( v0 != nullptr )
  {
    _AFX_EDIT_STATE::_AFX_EDIT_STATE(this: v0);
    v0->__vftable = (_AFX_EDIT_STATE_vtbl *)&_AFX_RICHEDIT_STATE::`vftable';
    return v0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034EEAD
// Name: int AfxInitRichEdit(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall AfxInitRichEdit()
{
  CNoTrackObject *Data; // eax
  CNoTrackObject *v1; // esi

  Data = CProcessLocalObject::GetData(
           this: &_afxRichEditState,
           pfnCreateObject: (CNoTrackObject *(__stdcall *)())CProcessLocal<_AFX_RICHEDIT_STATE>::CreateObject);
  v1 = Data;
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  if ( Data[8].__vftable == nullptr )
    Data[8].__vftable = (CNoTrackObject_vtbl *)AfxCtxLoadLibraryW(lpLibFileName: L"RICHED32.DLL");
  return v1[8].__vftable != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1034EEE8
// Name: int AfxInitRichEdit2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall AfxInitRichEdit2()
{
  CNoTrackObject *Data; // eax
  CNoTrackObject *v1; // esi

  Data = CProcessLocalObject::GetData(
           this: &_afxRichEditState,
           pfnCreateObject: (CNoTrackObject *(__stdcall *)())CProcessLocal<_AFX_RICHEDIT_STATE>::CreateObject);
  v1 = Data;
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  if ( Data[9].__vftable == nullptr )
    Data[9].__vftable = (CNoTrackObject_vtbl *)AfxCtxLoadLibraryW(lpLibFileName: L"RICHED20.DLL");
  return v1[9].__vftable != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10389C94
// Name: public: class CMFCTabCtrl __near * CMDIClientAreaWnd::FindTabWndByChild(struct HWND__ __near *,int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCTabCtrl *__thiscall CMDIClientAreaWnd::FindTabWndByChild(CMDIClientAreaWnd *this, HWND__ *hWndChild, int *iIndex)
{
  CObList::CNode *m_pNodeHead; // esi
  CObject *v5; // edi
  int v6; // eax
  CObject *data; // [esp-Ch] [ebp-Ch]

  if ( hWndChild == nullptr )
    return nullptr;
  m_pNodeHead = this->m_lstTabbedGroups.m_pNodeHead;
  do
  {
    if ( m_pNodeHead == nullptr )
      return nullptr;
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    v5 = AfxDynamicDownCast(pClass: &CMFCTabCtrl::classCMFCTabCtrl, pObject: data);
    v6 = ((int (__thiscall *)(CObject *, HWND__ *))v5->__vftable[44].Serialize)(a1: v5, a2: hWndChild);
    *iIndex = v6;
  }
  while ( v6 < 0 );
  return (CMFCTabCtrl *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10389CF1
// Name: public: class CMFCTabCtrl __near * CMDIClientAreaWnd::FindActiveTabWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCTabCtrl *__thiscall CMDIClientAreaWnd::FindActiveTabWnd(CMDIClientAreaWnd *this)
{
  CObList::CNode *m_pNodeHead; // esi
  CMFCTabCtrl *result; // eax
  CObject *data; // [esp-4h] [ebp-8h]

  m_pNodeHead = this->m_lstTabbedGroups.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    result = (CMFCTabCtrl *)AfxDynamicDownCast(pClass: &CMFCTabCtrl::classCMFCTabCtrl, pObject: data);
    if ( result->m_bIsActiveInMDITabGroup != 0 )
      return result;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10389D2A
// Name: public: int CMDIClientAreaWnd::IsMemberOfMDITabGroup(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMDIClientAreaWnd::IsMemberOfMDITabGroup(CMDIClientAreaWnd *this, CWnd *pWnd)
{
  return this->m_bIsMDITabbedGroup != 0
      && CPtrList::Find(this: &this->m_lstTabbedGroups, searchValue: pWnd, startAfter: nullptr) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10389D56
// Name: private: class CMFCTabCtrl __near * CMDIClientAreaWnd::GetNextTabWnd(class CMFCTabCtrl __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCTabCtrl *__thiscall CMDIClientAreaWnd::GetNextTabWnd(
        CMDIClientAreaWnd *this,
        CMFCTabCtrl *pOrgTabWnd,
        int bWithoutAsserts)
{
  __POSITION *v3; // eax
  int v5; // eax

  v3 = CPtrList::Find(this: &this->m_lstTabbedGroups, searchValue: pOrgTabWnd, startAfter: nullptr);
  if ( v3 != nullptr && (v5 = *(_DWORD *)v3) != 0 )
    return (CMFCTabCtrl *)AfxDynamicDownCast(pClass: &CMFCTabCtrl::classCMFCTabCtrl, pObject: *(CObject **)(v5 + 8));
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10397CE3
// Name: protected: virtual long CMFCShellListCtrl::EnumObjects(struct IShellFolder __near *,struct _ITEMIDLIST __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CMFCShellListCtrl::EnumObjects(
        CMFCShellListCtrl *this,
        IShellFolder *pParentFolder,
        _ITEMIDLIST *pidlParent)
{
  IShellFolder_vtbl *v5; // eax
  HRESULT i; // eax
  IShellFolder_vtbl *v7; // eax
  _AFX_SHELLITEMINFO *v8; // edi
  LRESULT v9; // eax
  IShellFolder_vtbl *v10; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-88h]
  char *m_pszData; // [esp-4h] [ebp-7Ch]
  tagLVITEMA lvItem; // [esp+10h] [ebp-68h] BYREF
  HRESULT hRes; // [esp+4Ch] [ebp-2Ch]
  int nColumns; // [esp+50h] [ebp-28h]
  int v17; // [esp+54h] [ebp-24h] BYREF
  int iItem; // [esp+58h] [ebp-20h]
  unsigned int dwAttr; // [esp+5Ch] [ebp-1Ch] BYREF
  IEnumIDList *pEnum; // [esp+60h] [ebp-18h] BYREF
  _ITEMIDLIST *pidlTemp; // [esp+64h] [ebp-14h] BYREF
  unsigned int dwFetched[3]; // [esp+68h] [ebp-10h] BYREF
  int v23; // [esp+74h] [ebp-4h]
  int iColumn; // [esp+80h] [ebp+8h]

  v5 = pParentFolder->__vftable;
  pEnum = nullptr;
  hRes = v5->EnumObjects(this: pParentFolder, a2: nullptr, a3: this->m_nTypes, a4: &pEnum);
  if ( hRes >= 0 && pEnum != nullptr )
  {
    dwFetched[0] = 1;
    for ( i = pEnum->Next(this: pEnum, a2: 1u, a3: &pidlTemp, a4: dwFetched);
          i == 0 && dwFetched[0] != 0;
          i = pEnum->Next(this: pEnum, a2: 1u, a3: &pidlTemp, a4: dwFetched) )
    {
      memset(dst: (unsigned __int8 *)&lvItem, value: 0, count: sizeof(lvItem));
      v7 = pParentFolder->__vftable;
      lvItem.mask = 15;
      v7->AddRef(this: pParentFolder);
      v8 = (_AFX_SHELLITEMINFO *)GlobalAlloc(uFlags: 0x40u, dwBytes: 0xCu);
      v8->pidlRel = pidlTemp;
      v8->pidlFQ = CShellManager::ConcatenateItem(this: afxShellManager, pidl1: pidlParent, pidl2: pidlTemp);
      v8->pParentFolder = pParentFolder;
      m_hWnd = this->m_hWnd;
      lvItem.lParam = (int)v8;
      lvItem.pszText = (char *)&szGroupName;
      v9 = SendMessageA(hWnd: m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
      lvItem.iImage = this->OnGetItemIcon(this, a2: v9, a3: v8);
      v10 = pParentFolder->__vftable;
      dwAttr = 1032192;
      v10->GetAttributesOf(this: pParentFolder, a2: 1u, a3: (const _ITEMIDLIST **)&pidlTemp, a4: &dwAttr);
      if ( (dwAttr & 0x20000) != 0 )
      {
        lvItem.mask |= 8u;
        lvItem.stateMask |= 0xF00u;
        lvItem.state |= 0x100u;
      }
      if ( (dwAttr & 0x8000) != 0 )
      {
        lvItem.mask |= 8u;
        lvItem.stateMask |= 4u;
        lvItem.state |= 4u;
      }
      iItem = SendMessageA(hWnd: this->m_hWnd, Msg: 0x1007u, wParam: 0, lParam: (LPARAM)&lvItem);
      if ( iItem >= 0 )
      {
        iColumn = 0;
        nColumns = SendMessageA(hWnd: this->m_wndHeader.m_hWnd, Msg: 0x1200u, wParam: 0, lParam: 0);
        if ( nColumns > 0 )
        {
          do
          {
            m_pszData = this->OnGetItemText(this, result: &v17, a3: iItem, a4: iColumn, a5: v8)->m_pszData;
            v23 = 0;
            CListCtrl::SetItemText(this, nItem: iItem, nSubItem: iColumn, lpszText: m_pszData);
            v23 = -1;
            ATL::CStringData::Release(this: (ATL::CStringData *)(v17 - 16));
            ++iColumn;
          }
          while ( iColumn < nColumns );
        }
      }
      dwFetched[0] = 0;
    }
    pEnum->Release(this: pEnum);
  }
  return hRes;
}

//------------------------------------------------------------------------------
// Address: 0x10397EAB
// Name: protected: long CMFCShellListCtrl::OnInitControl(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCShellListCtrl::OnInitControl(CMFCShellListCtrl *this, unsigned int wParam, const char *lParam)
{
  ATL::IAtlStringMgr *StringManager; // eax
  ATL::IAtlStringMgr *v5; // eax
  CTagManager tagManager; // [esp+10h] [ebp-1Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strDst; // [esp+18h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strEnableShellContextMenu; // [esp+1Ch] [ebp-10h] BYREF
  int v10; // [esp+28h] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strDst, pStringMgr: StringManager);
  v10 = 0;
  CMFCControlContainer::UTF8ToString(lpSrc: lParam, &strDst, nLength: wParam);
  CTagManager::CTagManager(this: &tagManager, lpszBuffer: strDst.m_pszData);
  LOBYTE(v10) = 1;
  v5 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strEnableShellContextMenu, pStringMgr: v5);
  LOBYTE(v10) = 2;
  if ( CTagManager::ExcludeTag(
         this: &tagManager,
         lpszTag: "MFCShellListCtrl_EnableShellContextMenu",
         strTag: &strEnableShellContextMenu,
         bIsCharsList: 0) != 0
    && *((_DWORD *)strEnableShellContextMenu.m_pszData - 3) != 0 )
  {
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::MakeUpper(this: &strEnableShellContextMenu);
    this->m_bContextMenu = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
                             this: &strEnableShellContextMenu,
                             psz: "TRUE") == 0;
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)strEnableShellContextMenu.m_pszData - 1);
  LOBYTE(v10) = 0;
  CTagManager::~CTagManager(this: &tagManager);
  ATL::CStringData::Release(this: (ATL::CStringData *)strDst.m_pszData - 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10397F67
// Name: public: virtual long CMFCShellListCtrl::DisplayFolder(struct _AFX_SHELLITEMINFO __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CMFCShellListCtrl::DisplayFolder(CMFCShellListCtrl *this, _AFX_SHELLITEMINFO *pItemInfo)
{
  HRESULT result; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  CMFCShellTreeCtrl *RelatedTree; // eax
  HWND Parent; // eax
  HWND v7; // eax
  CWnd *v8; // eax
  HRESULT hr; // [esp+10h] [ebp-10h]

  result = -2147467259;
  hr = -2147467259;
  if ( afxShellManager != nullptr )
  {
    if ( pItemInfo == nullptr
      || (CMFCShellListCtrl::ReleaseCurrFolder(this),
          result = CMFCShellListCtrl::LockCurrentFolder(this, pItemInfo),
          hr = result,
          result >= 0) )
    {
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x1009u, wParam: 0, lParam: 0);
      if ( this->m_psfCurFolder != nullptr )
      {
        ModuleState = AfxGetModuleState();
        CCmdTarget::BeginWaitCursor(this: ModuleState->m_pCurrentWinApp);
        SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
        hr = this->EnumObjects(this, a2: this->m_psfCurFolder, a3: this->m_pidlCurFQ);
        if ( (CWnd::GetStyle(this) & 1) != 0 )
          this->Sort(this, a2: 0, a3: 1, a4: 0);
        SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
        RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
        CWaitCursor::~CWaitCursor(this: (CWaitCursor *)&pItemInfo + 3);
      }
      if ( hr >= 0 && pItemInfo != nullptr )
      {
        RelatedTree = CMFCShellListCtrl::GetRelatedTree(this);
        if ( RelatedTree != nullptr && this->m_bNoNotify == 0 )
          CMFCShellTreeCtrl::SelectPath(this: RelatedTree, lpidl: this->m_pidlCurFQ);
        Parent = GetParent(hWnd: this->m_hWnd);
        if ( CWnd::FromHandle(hWnd: Parent) != nullptr )
        {
          v7 = GetParent(hWnd: this->m_hWnd);
          v8 = CWnd::FromHandle(hWnd: v7);
          SendMessageA(hWnd: v8->m_hWnd, Msg: AFX_WM_CHANGE_CURRENT_FOLDER, wParam: 0, lParam: 0);
        }
      }
      return hr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10398099
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCShellListCtrl::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCShellListCtrl::GetMessageMap(CMFCShellListCtrl *this)
{
  return (const AFX_MSGMAP *)&off_1067DCEC;
}

//------------------------------------------------------------------------------
// Address: 0x1039976C
// Name: protected: int CVSListBoxBase::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CVSListBoxBase::OnCreate(CVSListBoxBase *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax

  result = CWnd::Default(this);
  if ( result != -1 )
  {
    CVSListBoxBase::Init(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039978C
// Name: public: unsigned int CVSListBoxBase::GetButtonID(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CVSListBoxBase::GetButtonID(CVSListBoxBase *this, int iButtonNum)
{
  unsigned int uiID; // [esp+0h] [ebp-4h] BYREF

  uiID = 0;
  CMap<int,int,unsigned int,unsigned int>::Lookup(
    this: (CMap<int,int,int,int> *)&this->m_mapButtonIDs,
    key: iButtonNum,
    rValue: (int *)&uiID);
  return uiID;
}

//------------------------------------------------------------------------------
// Address: 0x103997AF
// Name: public: virtual void CVSListBoxBase::OnClickButton(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBoxBase::OnClickButton(CVSListBoxBase *this, int iButton)
{
  int v3; // edi
  unsigned int ButtonID; // eax
  CVSListBoxBase_vtbl *v6; // eax
  int v7; // eax
  int v8; // edi
  HWND__ *v9; // eax
  CWnd *v10; // eax
  CVSListBoxBase_vtbl *v11; // eax
  int v12; // [esp-4h] [ebp-2Ch]
  unsigned int dwData; // [esp+10h] [ebp-18h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strLabel; // [esp+14h] [ebp-14h] BYREF
  int iSelItem; // [esp+18h] [ebp-10h]
  int v16; // [esp+24h] [ebp-4h]
  BOOL bIsUp; // [esp+30h] [ebp+8h]

  if ( this->m_uiStandardBtns != 0 )
  {
    v3 = this->GetSelItem(this);
    iSelItem = v3;
    ButtonID = CVSListBoxBase::GetButtonID(this, iButtonNum: iButton);
    if ( ButtonID >= 0xFFFFFFF2 )
    {
      if ( ButtonID <= 0xFFFFFFF3 )
      {
        if ( v3 >= 0 )
        {
          bIsUp = ButtonID == -13;
          if ( !(ButtonID == -13 ? v3 == 0 : v3 == this->GetCount(this) - 1) )
          {
            SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
            this->GetItemText(this, result: &strLabel, a3: v3);
            v6 = this->__vftable;
            v16 = 0;
            v7 = v6->GetItemData(this, a2: v3);
            v12 = iSelItem;
            this->m_bIsActualDelete = 0;
            dwData = v7;
            this->RemoveItem(this, a2: v12);
            this->m_bIsActualDelete = 1;
            if ( bIsUp )
              --iSelItem;
            else
              ++iSelItem;
            v8 = iSelItem;
            this->AddItem(this, a2: &strLabel, a3: dwData, a4: iSelItem);
            this->SelectItem(this, a2: v8);
            SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
            v9 = this->GetListHwnd(this);
            v10 = CWnd::FromHandle(hWnd: v9);
            if ( v10 != nullptr )
              InvalidateRect(hWnd: v10->m_hWnd, lpRect: nullptr, bErase: true);
            v11 = this->__vftable;
            if ( bIsUp )
              v11->OnAfterMoveItemUp(this, a2: v8);
            else
              v11->OnAfterMoveItemDown(this, a2: v8);
            ATL::CStringData::Release(this: (ATL::CStringData *)strLabel.m_pszData - 1);
          }
        }
      }
      else if ( ButtonID == -12 )
      {
        if ( v3 >= 0 && this->OnBeforeRemoveItem(this, a2: v3) != 0 )
          this->RemoveItem(this, a2: v3);
      }
      else if ( ButtonID == -11 )
      {
        this->CreateNewItem(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039B407
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCShellTreeCtrl::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCShellTreeCtrl::GetMessageMap(CMFCShellTreeCtrl *this)
{
  return (const AFX_MSGMAP *)&off_1067E9C8;
}

//------------------------------------------------------------------------------
// Address: 0x1039B552
// Name: public: virtual void CMFCPropertyGridCtrl::InitHeader(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::InitHeader(CMFCPropertyGridCtrl *this)
{
  CRect rectDummy; // [esp+4h] [ebp-14h] BYREF

  memset(&rectDummy, 0, sizeof(rectDummy));
  SetRectEmpty(lprc: &rectDummy);
  this->m_wndHeader.Create_2(this: &this->m_wndHeader, a2: 1342177280u, a3: &rectDummy, a4: this, a5: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x1039B5A6
// Name: protected: long CMFCPropertyGridCtrl::OnGetFont(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HFONT__ *__thiscall CMFCPropertyGridCtrl::OnGetFont(
        CMFCPropertyGridCtrl *this,
        unsigned int __formal,
        unsigned int __formala)
{
  HFONT__ *result; // eax

  result = this->m_hFont;
  if ( result == nullptr )
    return (HFONT__ *)GetStockObject(i: 17);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039B5BB
// Name: protected: void CMFCPropertyGridCtrl::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnPaint(CMFCPropertyGridCtrl *this)
{
  CMFCPropertyGridCtrl_vtbl *v2; // eax
  CPaintDC v3; // [esp+10h] [ebp-64h] BYREF
  int v4; // [esp+70h] [ebp-4h]

  CPaintDC::CPaintDC(this: &v3, pWnd: this);
  v2 = this->__vftable;
  v4 = 0;
  v2->OnDraw(this, a2: &v3);
  v4 = -1;
  CPaintDC::~CPaintDC(this: &v3);
}

//------------------------------------------------------------------------------
// Address: 0x1039B5F6
// Name: protected: long CMFCPropertyGridCtrl::OnUpdateSpin(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridCtrl::OnUpdateSpin(
        CMFCPropertyGridCtrl *this,
        unsigned int __formal,
        unsigned int __formala)
{
  CMFCPropertyGridProperty *m_pSel; // eax

  m_pSel = this->m_pSel;
  if ( m_pSel != nullptr && m_pSel->m_bInPlaceEdit != 0 && m_pSel->m_bEnabled != 0 )
    ((void (*)(void))m_pSel->OnUpdateValue)();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1039B618
// Name: protected: unsigned int CMFCPropertyGridCtrl::OnGetDlgCode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCPropertyGridCtrl::OnGetDlgCode(CMFCPropertyGridCtrl *this)
{
  return 129;
}

//------------------------------------------------------------------------------
// Address: 0x1039B61E
// Name: protected: void CMFCPropertyGridCtrl::OnSelectCombo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnSelectCombo(CMFCPropertyGridCtrl *this)
{
  if ( this->m_pSel != nullptr )
    this->m_pSel->OnSelectCombo(this: this->m_pSel);
}

//------------------------------------------------------------------------------
// Address: 0x1039B635
// Name: protected: void CMFCPropertyGridCtrl::OnCloseCombo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnCloseCombo(CMFCPropertyGridCtrl *this)
{
  if ( this->m_pSel != nullptr )
    this->m_pSel->OnCloseCombo(this: this->m_pSel);
}

//------------------------------------------------------------------------------
// Address: 0x1039B64C
// Name: protected: virtual int CMFCPropertyGridCtrl::OnNotify(unsigned int,long,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridCtrl::OnNotify(
        CMFCPropertyGridCtrl *this,
        unsigned int wParam,
        int lParam,
        int *pResult)
{
  int v5; // ebx

  v5 = CWnd::OnNotify(this, __formal: wParam, lParam, pResult);
  if ( lParam == 0 )
    AfxThrowInvalidArgException();
  if ( *(_DWORD *)(lParam + 8) == -521 )
    CWnd::SetWindowPos(
      this: &this->m_ToolTip,
      pWndInsertAfter: &CWnd::wndTop,
      x: -1,
      y: -1,
      cx: -1,
      cy: -1,
      nFlags: 0x13u);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x103A3932
// Name: protected: int CMFCFontComboBox::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCFontComboBox::OnCreate(CMFCFontComboBox *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax

  result = CWnd::Default(this);
  if ( result != -1 )
  {
    CMFCFontComboBox::Init(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A3952
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCFontComboBox::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCFontComboBox::GetMessageMap(CMFCFontComboBox *this)
{
  return (const AFX_MSGMAP *)&off_1067FEDC;
}

//------------------------------------------------------------------------------
// Address: 0x103A3958
// Name: public: virtual int CMFCEditBrowseCtrl::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCEditBrowseCtrl::PreTranslateMessage(CMFCEditBrowseCtrl *this, tagMSG *pMsg)
{
  unsigned int wParam; // edx

  if ( pMsg->message != 260 )
    return CWnd::PreTranslateMessage(this, pMsg);
  if ( this->m_Mode == BrowseMode_None )
    return CWnd::PreTranslateMessage(this, pMsg);
  wParam = pMsg->wParam;
  if ( wParam != 40 && wParam != 39 )
    return CWnd::PreTranslateMessage(this, pMsg);
  this->OnBrowse(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103A3996
// Name: protected: void CMFCEditBrowseCtrl::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnLButtonUp(CMFCEditBrowseCtrl *this, unsigned int nFlags, CPoint point)
{
  HWND__ *m_hWnd; // [esp-10h] [ebp-1Ch]

  if ( this->m_bIsButtonCaptured != 0 )
  {
    ReleaseCapture();
    m_hWnd = this->m_hWnd;
    this->m_bIsButtonPressed = 0;
    this->m_bIsButtonCaptured = 0;
    this->m_bIsButtonHighlighted = 0;
    RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x401u);
    if ( PtInRect(lprc: &this->m_rectBtn, pt: point.tagPOINT) )
      this->OnBrowse(this);
  }
  else
  {
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A39FB
// Name: protected: void CMFCEditBrowseCtrl::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnMouseMove(CMFCEditBrowseCtrl *this, unsigned int nFlags, CPoint point)
{
  int v4; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-18h]

  if ( this->m_bIsButtonCaptured != 0 )
  {
    v4 = PtInRect(lprc: &this->m_rectBtn, pt: point.tagPOINT);
    if ( v4 != this->m_bIsButtonPressed )
    {
      m_hWnd = this->m_hWnd;
      this->m_bIsButtonPressed = v4;
      RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x401u);
    }
  }
  else
  {
    if ( this->m_bIsButtonHighlighted != 0 && !PtInRect(lprc: &this->m_rectBtn, pt: point.tagPOINT) )
    {
      this->m_bIsButtonHighlighted = 0;
      ReleaseCapture();
      RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x401u);
    }
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A3A7D
// Name: protected: void CMFCEditBrowseCtrl::OnNcCalcSize(int,struct tagNCCALCSIZE_PARAMS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnNcCalcSize(
        CMFCEditBrowseCtrl *this,
        int bCalcValidRects,
        tagNCCALCSIZE_PARAMS *lpncsp)
{
  CWnd::Default(this);
  if ( this->m_Mode != BrowseMode_None )
    lpncsp->rgrc[0].right -= this->m_nBrowseButtonWidth;
}

//------------------------------------------------------------------------------
// Address: 0x103A3AA1
// Name: protected: long CMFCEditBrowseCtrl::OnNcHitTest(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCEditBrowseCtrl::OnNcHitTest(CMFCEditBrowseCtrl *this, CPoint point)
{
  CPoint ptClient; // [esp+4h] [ebp-8h] BYREF

  ptClient = point;
  ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptClient);
  if ( this->m_Mode != BrowseMode_None && PtInRect(lprc: &this->m_rectBtn, pt: ptClient.tagPOINT) )
    return 2;
  else
    return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A68BC
// Name: protected: virtual int CMFCButton::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCButton::PreCreateWindow(CMFCButton *this, tagCREATESTRUCTA *cs)
{
  CMFCButton::InitStyle(this, dwStyle: cs->style);
  cs->style = cs->style & 0xFFFFFFF4 | 0xA;
  return CWnd::PreCreateWindow(this, cs);
}

//------------------------------------------------------------------------------
// Address: 0x103A68EA
// Name: public: void CMFCButton::SetImage(unsigned int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::SetImage(
        CMFCButton *this,
        unsigned int uiBmpResId,
        unsigned int uiBmpHotResId,
        unsigned int uiBmpDsblResID)
{
  CMFCButton::SetImageInternal(this, uiBmpResId, uiBmpHotResId, bChecked: 0, uiBmpDsblResID);
}

//------------------------------------------------------------------------------
// Address: 0x103A6903
// Name: protected: void CMFCButton::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::OnLButtonUp(CMFCButton *this, unsigned int nFlags, CPoint point)
{
  BOOL v4; // eax
  HWND__ *m_hWnd; // ecx
  HWND Parent; // eax
  CWnd *v7; // ebx
  unsigned __int16 DlgCtrlID; // ax
  CToolTipCtrl *m_pToolTip; // esi
  HWND__ *lParam; // [esp+Ch] [ebp-8h]
  HWND hWnd; // [esp+10h] [ebp-4h]

  v4 = this->m_bPushed != 0 && this->m_bClickiedInside != 0 && this->m_bHighlighted != 0;
  this->m_bPushed = 0;
  this->m_bClickiedInside = 0;
  this->m_bHighlighted = 0;
  if ( v4 && this->m_bAutoCheck != 0 )
  {
    if ( this->m_bCheckButton != 0 )
    {
      this->m_bChecked = this->m_bChecked == 0;
    }
    else if ( this->m_bRadioButton != 0 && this->m_bChecked == 0 )
    {
      this->m_bChecked = 1;
      CMFCButton::UncheckRadioButtonsInGroup(this);
    }
  }
  m_hWnd = this->m_hWnd;
  hWnd = m_hWnd;
  if ( this->m_bWasDblClk != 0 )
  {
    this->m_bWasDblClk = 0;
    Parent = GetParent(hWnd: m_hWnd);
    v7 = CWnd::FromHandle(hWnd: Parent);
    if ( v7 != nullptr )
    {
      lParam = this->m_hWnd;
      DlgCtrlID = CWnd::GetDlgCtrlID(this);
      SendMessageA(hWnd: v7->m_hWnd, Msg: 0x111u, wParam: DlgCtrlID, (LPARAM)lParam);
    }
  }
  if ( IsWindow(hWnd) )
  {
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
    CWnd::Default(this);
    if ( IsWindow(hWnd) )
    {
      if ( this->m_bCaptured != 0 )
      {
        ReleaseCapture();
        this->m_bCaptured = 0;
      }
      if ( this->m_nAutoRepeatTimeDelay > 0 )
        KillTimer(hWnd: this->m_hWnd, uIDEvent: 1u);
      m_pToolTip = this->m_pToolTip;
      if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr )
        SendMessageA(hWnd: m_pToolTip->m_hWnd, Msg: 0x41Cu, wParam: 0, lParam: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A6A4D
// Name: public: virtual int CMFCButton::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCButton::PreTranslateMessage(CMFCButton *this, tagMSG *pMsg)
{
  CToolTipCtrl *m_pToolTip; // eax
  tagMSG *v4; // ebx
  unsigned int message; // ecx
  HWND Parent; // eax
  CWnd *v7; // ebx
  HWND__ *m_hWnd; // edi
  HWND v10; // eax
  unsigned int wParam; // eax
  int v12; // eax
  HWND v13; // eax
  CWnd *v14; // eax
  HWND v15; // edi
  HWND__ *v16; // [esp-10h] [ebp-1Ch]
  WPARAM DlgCtrlID; // [esp-8h] [ebp-14h]
  WPARAM WindowLongA; // [esp-8h] [ebp-14h]
  HWND__ *v19; // [esp-4h] [ebp-10h]

  m_pToolTip = this->m_pToolTip;
  if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr )
  {
    v4 = pMsg;
    message = pMsg->message;
    if ( message == 513 || message == 514 || message == 512 )
      SendMessageA(hWnd: m_pToolTip->m_hWnd, Msg: 0x407u, wParam: 0, lParam: (LPARAM)pMsg);
  }
  else
  {
    v4 = pMsg;
  }
  if ( v4->message == 256 )
  {
    if ( v4->wParam == 13 && CMFCPopupMenu::m_pActivePopupMenu == nullptr )
    {
      Parent = GetParent(hWnd: this->m_hWnd);
      v7 = CWnd::FromHandle(hWnd: Parent);
      if ( v7 != nullptr )
      {
        m_hWnd = this->m_hWnd;
        DlgCtrlID = (unsigned __int16)CWnd::GetDlgCtrlID(this);
        SendMessageA(hWnd: v7->m_hWnd, Msg: 0x111u, wParam: DlgCtrlID, lParam: (LPARAM)m_hWnd);
        return 1;
      }
      v4 = pMsg;
    }
    if ( v4->message == 256 && this->m_bAutoCheck != 0 )
    {
      v10 = GetParent(hWnd: this->m_hWnd);
      if ( CWnd::FromHandle(hWnd: v10) != nullptr )
      {
        wParam = v4->wParam;
        if ( wParam == 32 )
        {
          if ( this->m_bCheckButton != 0 )
          {
            v16 = this->m_hWnd;
            this->m_bChecked = this->m_bChecked == 0;
            RedrawWindow(hWnd: v16, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
            v13 = GetParent(hWnd: this->m_hWnd);
            v14 = CWnd::FromHandle(hWnd: v13);
            if ( v14 != nullptr )
              v15 = v14->m_hWnd;
            else
              v15 = nullptr;
            v19 = this->m_hWnd;
            WindowLongA = (unsigned __int16)GetWindowLongA(hWnd: v19, nIndex: -12);
            SendMessageA(hWnd: v15, Msg: 0x111u, wParam: WindowLongA, lParam: (LPARAM)v19);
            return 1;
          }
        }
        else if ( wParam > 0x24 )
        {
          if ( wParam <= 0x26 )
          {
            v12 = CMFCButton::CheckNextPrevRadioButton(this, bNext: 0);
          }
          else
          {
            if ( wParam > 0x28 )
              return CWnd::PreTranslateMessage(this, pMsg: v4);
            v12 = CMFCButton::CheckNextPrevRadioButton(this, bNext: 1);
          }
          if ( v12 != 0 )
            return 1;
        }
      }
    }
  }
  return CWnd::PreTranslateMessage(this, pMsg: v4);
}

//------------------------------------------------------------------------------
// Address: 0x103A6BA8
// Name: protected: long CMFCButton::OnSetCheck(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCButton::OnSetCheck(CMFCButton *this, unsigned int fCheck, int __formal)
{
  if ( (this->m_bCheckButton != 0 || this->m_bRadioButton != 0) && (this->m_bChecked == 0) != (fCheck == 0) )
  {
    this->m_bChecked = fCheck != 0;
    if ( this->m_bRadioButton != 0 )
      CMFCButton::UncheckRadioButtonsInGroup(this);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A6C14
// Name: protected: long CMFCButton::OnSetImage(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCButton::OnSetImage(CMFCButton *this, unsigned int wParam, HBITMAP__ *lParam)
{
  if ( wParam != 0 )
  {
    if ( wParam == 1 )
      CMFCButton::SetImageInternal(
        this,
        hIconCold: (HICON__ *)lParam,
        bAutoDestroy: 0,
        hIconHot: nullptr,
        bChecked: 0,
        hIconDisabled: nullptr,
        bAlphaBlend: 0);
  }
  else
  {
    CMFCButton::SetImageInternal(
      this,
      hBitmapCold: lParam,
      bAutoDestroy: 0,
      hBitmapHot: nullptr,
      bMap3dColors: 1,
      bChecked: 0,
      hBitmapDisabled: nullptr);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A6C48
// Name: protected: virtual void CMFCButton::OnDraw(class CDC __near *,class CRect const __near &,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::OnDraw(CMFCButton *this, CDC *pDC, const CRect *rect, unsigned int uiState)
{
  ATL::IAtlStringMgr *StringManager; // eax
  CMFCButton_vtbl *v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  unsigned int clrBtnText; // esi
  int v15; // eax
  CMFCButton::AlignStyle m_nAlignStyle; // eax
  __int32 v17; // eax
  CMFCButton_vtbl *v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // esi
  char *m_pszData; // eax
  CMenuImages::IMAGES_IDS m_nStdImageId; // eax
  CMFCToolBarImages *p_m_ImageChecked; // eax
  CMFCToolBarImages *p_m_ImageDisabled; // esi
  BOOL v26; // eax
  CMFCToolBarImages *v27; // ecx
  BOOL v28; // eax
  CMenuImages::IMAGE_STATE m_StdImageState; // [esp-8h] [ebp-74h]
  CFont *v30; // [esp+10h] [ebp-5Ch]
  CSize sizeImage; // [esp+14h] [ebp-58h] BYREF
  int v32; // [esp+1Ch] [ebp-50h]
  ATL::CSimpleStringT<char,0> v33; // [esp+20h] [ebp-4Ch] BYREF
  CDC *pDCa; // [esp+24h] [ebp-48h]
  CMFCToolBarImages *p_m_ImageCheckedDisabled; // [esp+28h] [ebp-44h]
  tagRECT v36; // [esp+2Ch] [ebp-40h] BYREF
  tagRECT v37; // [esp+3Ch] [ebp-30h] BYREF
  tagRECT rc; // [esp+4Ch] [ebp-20h] BYREF
  int v39; // [esp+68h] [ebp-4h]

  pDCa = pDC;
  v37 = rect->tagRECT;
  rc = rect->tagRECT;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v33, pStringMgr: StringManager);
  v39 = 0;
  CWnd::GetWindowTextA(this, rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v33);
  if ( this->m_sizeImage.cx != 0 )
  {
    if ( *((_DWORD *)v33.m_pszData - 3) != 0 )
    {
      v6 = this->__vftable;
      if ( this->m_bTopImage != 0 )
      {
        v7 = v6->GetVertMargin(this);
        rc.bottom = rc.top + this->m_sizeImage.cy + v7;
        v37.top = rc.bottom;
        v8 = this->GetVertMargin(this);
        v37.bottom -= v8;
      }
      else if ( this->m_bRightImage != 0 )
      {
        v9 = ((int (__fastcall *)(CMFCButton *))v6->GetImageHorzMargin)(a1: this);
        v37.right += -this->m_sizeImage.cx - v9 / 2;
        rc.left = v37.right;
        v10 = this->GetImageHorzMargin(this);
        rc.right += v10 / -2;
      }
      else
      {
        v11 = ((int (__fastcall *)(CMFCButton *))v6->GetImageHorzMargin)(a1: this);
        v37.left += this->m_sizeImage.cx + v11 / 2;
        v12 = this->GetImageHorzMargin(this);
        rc.left += v12 / 2;
        rc.right = v37.left;
      }
    }
    v13 = (rc.bottom - this->m_sizeImage.cy - rc.top) / 2;
    if ( v13 < 0 )
      v13 = 0;
    InflateRect(lprc: &rc, dx: (rc.right - this->m_sizeImage.cx - rc.left) / -2, dy: -v13);
  }
  else
  {
    SetRectEmpty(lprc: &rc);
  }
  v30 = this->SelectFont(this, a2: pDCa);
  if ( v30 == nullptr )
    AfxThrowInvalidArgException();
  CDC::SetBkMode(this: pDCa, nBkMode: 1);
  clrBtnText = afxGlobalData.clrBtnText;
  if ( this->m_clrRegular != -1 )
    clrBtnText = this->m_clrRegular;
  if ( this->m_bHighlighted != 0 && this->m_clrHover != -1 )
    clrBtnText = this->m_clrHover;
  p_m_ImageCheckedDisabled = (CMFCToolBarImages *)0x8000;
  v32 = 0;
  if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(
         this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v33,
         ch: 10,
         iStart: 0) >= 0 )
  {
    v15 = this->GetVertMargin(this);
    InflateRect(lprc: &v37, dx: 0, dy: v15 / -2);
  }
  else
  {
    p_m_ImageCheckedDisabled = (CMFCToolBarImages *)32804;
    v32 = 1;
  }
  m_nAlignStyle = this->m_nAlignStyle;
  if ( m_nAlignStyle != ALIGN_INVALID )
  {
    v17 = m_nAlignStyle - 1;
    if ( v17 != 0 )
    {
      if ( v17 == 1 )
        p_m_ImageCheckedDisabled = (CMFCToolBarImages *)((unsigned int)p_m_ImageCheckedDisabled | 1);
    }
    else
    {
      v18 = this->__vftable;
      p_m_ImageCheckedDisabled = (CMFCToolBarImages *)((unsigned int)p_m_ImageCheckedDisabled | 2);
      v19 = v18->GetImageHorzMargin(this);
      v37.right += v19 / -2;
    }
  }
  else
  {
    v20 = this->GetImageHorzMargin(this);
    v37.left += v20 / 2;
  }
  if ( (CWnd::GetExStyle(this) & 0x400000) != 0 )
    p_m_ImageCheckedDisabled = (CMFCToolBarImages *)((unsigned int)p_m_ImageCheckedDisabled | 0x20000);
  sizeImage.cy = uiState & 4;
  if ( (uiState & 4) != 0 && this->m_bGrayDisabled != 0 )
  {
    pDCa->SetTextColor(this: pDCa, a2: afxGlobalData.clrBtnHilite);
    v36 = v37;
    OffsetRect(lprc: &v36, dx: 1, dy: 1);
    this->OnDrawText(
      this,
      a2: pDCa,
      a3: (const CRect *)&v36,
      a4: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v33,
      a5: (unsigned int)p_m_ImageCheckedDisabled,
      a6: uiState);
    clrBtnText = afxGlobalData.clrGrayedText;
  }
  pDCa->SetTextColor(this: pDCa, a2: clrBtnText);
  if ( this->m_bDelayFullTextTooltipSet != 0 )
  {
    v21 = v37.right - v37.left;
    if ( CDC::GetTextExtent(
           this: pDCa,
           result: (CSize *)&v36.right,
           str: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v33)->cx > v21
      && v32 != 0 )
    {
      m_pszData = v33.m_pszData;
    }
    else
    {
      m_pszData = nullptr;
    }
    CMFCButton::SetTooltip(this, lpszToolTipText: m_pszData);
    this->m_bDelayFullTextTooltipSet = 0;
  }
  this->OnDrawText(
    this,
    a2: pDCa,
    a3: (const CRect *)&v37,
    a4: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v33,
    a5: (unsigned int)p_m_ImageCheckedDisabled,
    a6: uiState);
  if ( !IsRectEmpty(lprc: &rc) )
  {
    m_nStdImageId = this->m_nStdImageId;
    if ( m_nStdImageId != -1 )
    {
      if ( sizeImage.cy != 0 && this->m_bGrayDisabled != 0 && this->m_nStdImageDisabledId != IdArrowDown )
        m_nStdImageId = this->m_nStdImageDisabledId;
      m_StdImageState = this->m_StdImageState;
      sizeImage.cx = 0;
      sizeImage.cy = 0;
      CMenuImages::Draw(pDC: pDCa, id: m_nStdImageId, ptImage: (const CPoint *)&rc, state: m_StdImageState, &sizeImage);
      goto LABEL_74;
    }
    if ( sizeImage.cy != 0 && this->m_bGrayDisabled != 0 )
    {
      v32 = 1;
      if ( this->m_ImageCheckedDisabled.m_iCount != 0 )
      {
        p_m_ImageCheckedDisabled = &this->m_ImageCheckedDisabled;
LABEL_55:
        if ( this->m_ImageDisabled.m_iCount != 0 )
        {
          p_m_ImageDisabled = &this->m_ImageDisabled;
          goto LABEL_60;
        }
LABEL_57:
        if ( this->m_bHighlighted == 0 || (p_m_ImageDisabled = &this->m_ImageHot, this->m_ImageHot.m_iCount == 0) )
          p_m_ImageDisabled = &this->m_Image;
LABEL_60:
        if ( this->m_bChecked != 0 && p_m_ImageCheckedDisabled->m_iCount != 0 )
        {
          CMFCToolBarImages::PrepareDrawImage(
            this: p_m_ImageCheckedDisabled,
            ds: (tagAFXDrawState *)&v36.top,
            sizeImageDest: 0,
            bFadeInactive: 0);
          v26 = v32 != 0 && this->m_ImageCheckedDisabled.m_iCount == 0;
          CMFCToolBarImages::Draw(
            this: p_m_ImageCheckedDisabled,
            pDCDest: pDCa,
            xDest: rc.left,
            yDest: rc.top,
            iImage: 0,
            bHilite: 0,
            bDisabled: v26,
            bIndeterminate: 0,
            bShadow: 0,
            bInactive: 0,
            alphaSrc: 0xFFu);
          v27 = p_m_ImageCheckedDisabled;
        }
        else
        {
          if ( p_m_ImageDisabled->m_iCount == 0 )
            goto LABEL_74;
          CMFCToolBarImages::PrepareDrawImage(
            this: p_m_ImageDisabled,
            ds: (tagAFXDrawState *)&v36.top,
            sizeImageDest: 0,
            bFadeInactive: 0);
          v28 = v32 != 0 && this->m_ImageDisabled.m_iCount == 0;
          CMFCToolBarImages::Draw(
            this: p_m_ImageDisabled,
            pDCDest: pDCa,
            xDest: rc.left,
            yDest: rc.top,
            iImage: 0,
            bHilite: 0,
            bDisabled: v28,
            bIndeterminate: 0,
            bShadow: 0,
            bInactive: 0,
            alphaSrc: 0xFFu);
          v27 = p_m_ImageDisabled;
        }
        CMFCToolBarImages::EndDrawImage(this: v27, ds: (tagAFXDrawState *)&v36.top);
        goto LABEL_74;
      }
    }
    else
    {
      v32 = 0;
    }
    if ( this->m_bHighlighted == 0
      || (p_m_ImageChecked = &this->m_ImageCheckedHot, this->m_ImageCheckedHot.m_iCount == 0) )
    {
      p_m_ImageChecked = &this->m_ImageChecked;
    }
    p_m_ImageCheckedDisabled = p_m_ImageChecked;
    if ( v32 == 0 )
      goto LABEL_57;
    goto LABEL_55;
  }
LABEL_74:
  pDCa->SelectObject(this: pDCa, a2: v30);
  ATL::CStringData::Release(this: (ATL::CStringData *)v33.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x103A70B1
// Name: protected: virtual void CMFCButton::OnDrawText(class CDC __near *,class CRect const __near &,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCButton::OnDrawText(
        CMFCButton *this,
        CDC *pDC,
        const CRect *rect,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strText,
        unsigned int uiDTFlags,
        unsigned int __formal)
{
  char *m_pszData; // eax
  CDC_vtbl *v7; // edx
  CRect rectText; // [esp+8h] [ebp-14h] BYREF

  m_pszData = strText->m_pszData;
  v7 = pDC->__vftable;
  rectText = *rect;
  v7->DrawTextA(this: pDC, a2: m_pszData, a3: *((_DWORD *)m_pszData - 3), a4: &rectText, a5: uiDTFlags);
}

//------------------------------------------------------------------------------
// Address: 0x103A70F7
// Name: public: virtual class CSize CMFCButton::SizeToContent(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCButton::SizeToContent(CMFCButton *this, CSize *result, int bCalcOnly)
{
  HWND__ *m_hWnd; // eax
  CMFCButton_vtbl *v5; // eax
  ATL::IAtlStringMgr *StringManager; // eax
  CSize *TextExtent; // eax
  int cx; // ebx
  int cy; // eax
  int v10; // eax
  int v11; // eax
  int v12; // edi
  int v13; // eax
  int v14; // ebx
  int v15; // ebx
  CSize *v16; // esi
  ATL::CStringData *v17; // ecx
  HWND__ *v19; // [esp-8h] [ebp-64h]
  CClientDC v20; // [esp+10h] [ebp-4Ch] BYREF
  CFont *pFont; // [esp+24h] [ebp-38h]
  CSize *v22; // [esp+28h] [ebp-34h]
  CSize v23; // [esp+2Ch] [ebp-30h] BYREF
  ATL::CSimpleStringT<char,0> v24; // [esp+34h] [ebp-28h] BYREF
  int v25; // [esp+38h] [ebp-24h]
  tagRECT Rect; // [esp+3Ch] [ebp-20h] BYREF
  int v27; // [esp+58h] [ebp-4h]

  v22 = result;
  if ( this != nullptr )
    m_hWnd = this->m_hWnd;
  else
    m_hWnd = nullptr;
  if ( m_hWnd == nullptr
    || (CClientDC::CClientDC(this: &v20, pWnd: this),
        v5 = this->__vftable,
        v27 = 0,
        (pFont = v5->SelectFont(this, a2: &v20)) == nullptr) )
  {
    AfxThrowInvalidArgException();
  }
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v24, pStringMgr: StringManager);
  LOBYTE(v27) = 1;
  CWnd::GetWindowTextA(this, rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v24);
  if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(
         this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v24,
         ch: 10,
         iStart: 0) >= 0 )
  {
    v19 = this->m_hWnd;
    memset(&Rect, 0, sizeof(Rect));
    GetClientRect(hWnd: v19, lpRect: &Rect);
    v20.DrawTextA(this: &v20, a2: v24.m_pszData, a3: *((_DWORD *)v24.m_pszData - 3), a4: &Rect, a5: 1024u);
    cy = Rect.bottom - Rect.top;
    cx = Rect.right - Rect.left;
  }
  else
  {
    TextExtent = CDC::GetTextExtent(
                   this: &v20,
                   result: &v23,
                   str: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v24);
    cx = TextExtent->cx;
    cy = TextExtent->cy;
  }
  v23.cy = cy;
  if ( this->m_bTopImage != 0 )
  {
    v10 = this->m_sizeImage.cx;
    v25 = cx;
    if ( cx <= v10 )
      v25 = v10;
    v11 = this->GetImageHorzMargin(this);
    v12 = v25 + v11;
    if ( cx > 0 )
      v12 += this->GetImageHorzMargin(this);
    v25 = this->m_sizeImage.cy;
    v13 = this->GetVertMargin(this);
    v14 = v23.cy + v25 + v13;
    if ( v25 > 0 )
      v14 += this->GetVertMargin(this);
    if ( v23.cy > 0 )
      v14 += this->GetVertMargin(this);
  }
  else
  {
    v12 = cx + this->m_sizeImage.cx + this->GetImageHorzMargin(this);
    if ( cx > 0 )
      v12 += this->GetImageHorzMargin(this);
    v15 = v23.cy;
    if ( v23.cy <= this->m_sizeImage.cy )
      v15 = this->m_sizeImage.cy;
    v14 = v15 + 2 * this->GetVertMargin(this);
  }
  if ( bCalcOnly == 0 )
    CWnd::SetWindowPos(this, pWndInsertAfter: nullptr, x: -1, y: -1, cx: v12, cy: v14, nFlags: 0x16u);
  CDC::SelectObject(this: &v20, pFont);
  v16 = v22;
  v17 = (ATL::CStringData *)(v24.m_pszData - 16);
  v22->cx = v12;
  v16->cy = v14;
  ATL::CStringData::Release(this: v17);
  v27 = -1;
  CClientDC::~CClientDC(this: &v20);
  return v16;
}

//------------------------------------------------------------------------------
// Address: 0x103A72D8
// Name: protected: long CMFCButton::OnUpdateToolTips(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCButton::OnUpdateToolTips(
        CMFCButton *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > wp,
        int __formal)
{
  CToolTipCtrl **p_m_pToolTip; // esi
  CToolTipCtrl *m_pToolTip; // eax
  ATL::IAtlStringMgr *StringManager; // eax

  p_m_pToolTip = &this->m_pToolTip;
  m_pToolTip = this->m_pToolTip;
  if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr && ((int)wp.m_pszData & 0x40) != 0 )
  {
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &wp, pStringMgr: StringManager);
    CToolTipCtrl::GetText(this: *p_m_pToolTip, str: &wp, pWnd: this, nIDTool: 0);
    CTooltipManager::CreateToolTip(pToolTip: p_m_pToolTip, pWndParent: this, nType: 0x40u);
    if ( *p_m_pToolTip != nullptr )
      CToolTipCtrl::AddTool(this: *p_m_pToolTip, pWnd: this, lpszText: wp.m_pszData, lpRectTool: nullptr, nIDTool: 0);
    ATL::CStringData::Release(this: (ATL::CStringData *)wp.m_pszData - 1);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A734C
// Name: protected: long CMFCButton::OnInitControl(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCButton::OnInitControl(CMFCButton *this, const char *wParam, const char *lParam)
{
  ATL::IAtlStringMgr *StringManager; // eax
  ATL::IAtlStringMgr *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  ATL::IAtlStringMgr *v9; // eax
  ATL::IAtlStringMgr *v10; // eax
  BOOL v11; // eax
  ATL::IAtlStringMgr *v12; // eax
  int v13; // eax
  int v14; // eax
  ATL::IAtlStringMgr *v15; // eax
  int v16; // eax
  int v17; // esi
  ATL::IAtlStringMgr *v18; // eax
  unsigned int v19; // eax
  HICON IconA; // eax
  const char *v21; // esi
  HINSTANCE__ *m_hCurrentResourceHandle; // eax
  char v24[8]; // [esp+10h] [ebp-40h] BYREF
  CTagManager tagManager; // [esp+18h] [ebp-38h] BYREF
  int bImageOnRight; // [esp+20h] [ebp-30h] BYREF
  int bImageOnTop; // [esp+24h] [ebp-2Ch] BYREF
  int bAutosize; // [esp+28h] [ebp-28h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strDst; // [esp+2Ch] [ebp-24h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strStyle; // [esp+30h] [ebp-20h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strTooltip; // [esp+34h] [ebp-1Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strCursorType; // [esp+38h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strImageType; // [esp+3Ch] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strFullTextTooltip; // [esp+40h] [ebp-10h] BYREF
  int v35; // [esp+4Ch] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strDst, pStringMgr: StringManager);
  v35 = 0;
  CMFCControlContainer::UTF8ToString(lpSrc: lParam, &strDst, nLength: (int)wParam);
  CTagManager::CTagManager(this: &tagManager, lpszBuffer: strDst.m_pszData);
  LOBYTE(v35) = 1;
  v5 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strStyle, pStringMgr: v5);
  LOBYTE(v35) = 2;
  if ( CTagManager::ExcludeTag(this: &tagManager, lpszTag: "MFCButton_Style", strTag: &strStyle, bIsCharsList: 0) != 0
    && *((_DWORD *)strStyle.m_pszData - 3) != 0 )
  {
    v6 = atoi(nptr: strStyle.m_pszData) - 4;
    if ( v6 != 0 )
    {
      v7 = v6 - 1;
      if ( v7 != 0 )
      {
        v8 = v7 - 1;
        if ( v8 != 0 )
        {
          if ( v8 == 1 )
            this->m_nFlatStyle = BUTTONSTYLE_SEMIFLAT;
        }
        else
        {
          this->m_nFlatStyle = BUTTONSTYLE_NOBORDERS;
        }
      }
      else
      {
        this->m_nFlatStyle = BUTTONSTYLE_FLAT;
      }
    }
    else
    {
      this->m_nFlatStyle = BUTTONSTYLE_3D;
    }
  }
  bAutosize = 0;
  if ( CMFCControlContainer::ReadBoolProp(&tagManager, lpszTag: "MFCButton_Autosize", bMember: &bAutosize) != 0
    && bAutosize != 0 )
  {
    this->SizeToContent(this, result: (CSize *)v24, a3: 0);
  }
  v9 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strTooltip, pStringMgr: v9);
  LOBYTE(v35) = 3;
  if ( CTagManager::ExcludeTag(this: &tagManager, lpszTag: "MFCButton_Tooltip", strTag: &strTooltip, bIsCharsList: 0) != 0 )
    CMFCButton::SetTooltip(this, lpszToolTipText: strTooltip.m_pszData);
  v10 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strFullTextTooltip, pStringMgr: v10);
  LOBYTE(v35) = 4;
  if ( CTagManager::ExcludeTag(
         this: &tagManager,
         lpszTag: "MFCButton_FullTextTool",
         strTag: &strFullTextTooltip,
         bIsCharsList: 0) != 0
    && *((_DWORD *)strFullTextTooltip.m_pszData - 3) != 0 )
  {
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::MakeUpper(this: &strFullTextTooltip);
    v11 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(this: &strFullTextTooltip, psz: "TRUE") == 0;
    this->m_bFullTextTooltip = v11;
    this->m_bDelayFullTextTooltipSet = v11;
  }
  v12 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strCursorType, pStringMgr: v12);
  LOBYTE(v35) = 5;
  if ( CTagManager::ExcludeTag(
         this: &tagManager,
         lpszTag: "MFCButton_CursorType",
         strTag: &strCursorType,
         bIsCharsList: 0) != 0
    && *((_DWORD *)strCursorType.m_pszData - 3) != 0 )
  {
    v13 = atoi(nptr: strCursorType.m_pszData) - 11;
    if ( v13 == 0 )
      goto LABEL_24;
    v14 = v13 - 1;
    if ( v14 == 0 )
    {
      CMFCButton::SetMouseCursorHand(this);
      goto LABEL_25;
    }
    if ( v14 == 1 )
LABEL_24:
      this->m_hCursor = nullptr;
  }
LABEL_25:
  v15 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strImageType, pStringMgr: v15);
  LOBYTE(v35) = 6;
  if ( CTagManager::ExcludeTag(
         this: &tagManager,
         lpszTag: "MFCButton_ImageType",
         strTag: &strImageType,
         bIsCharsList: 0) != 0
    && *((_DWORD *)strImageType.m_pszData - 3) != 0 )
  {
    v16 = atoi(nptr: strImageType.m_pszData);
    v17 = v16;
    if ( v16 == 8 )
    {
      CMFCButton::ClearImages(this, bChecked: 0);
    }
    else if ( v16 > 8 && v16 <= 10 )
    {
      v18 = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: (ATL::CSimpleStringT<char,0> *)&wParam, pStringMgr: v18);
      LOBYTE(v35) = 7;
      if ( CTagManager::ExcludeTag(
             this: &tagManager,
             lpszTag: "MFCButton_ImageID",
             strTag: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&wParam,
             bIsCharsList: 0) != 0 )
      {
        if ( *((_DWORD *)wParam - 3) != 0 )
        {
          v19 = atoi(nptr: wParam);
          if ( v17 == 10 )
          {
            CMFCButton::SetImageInternal(this, uiBmpResId: v19, uiBmpHotResId: 0, bChecked: 0, uiBmpDsblResID: 0);
          }
          else if ( v17 == 9 )
          {
            if ( v19 == 0 )
              goto LABEL_37;
            v21 = (const char *)(unsigned __int16)v19;
            if ( (_WORD)v19 == 0 )
              AfxThrowInvalidArgException();
            m_hCurrentResourceHandle = AfxGetModuleState()->m_hCurrentResourceHandle;
            if ( m_hCurrentResourceHandle != nullptr )
              IconA = LoadIconA(hInstance: m_hCurrentResourceHandle, lpIconName: v21);
            else
LABEL_37:
              IconA = nullptr;
            CMFCButton::SetImageInternal(
              this,
              hIconCold: IconA,
              bAutoDestroy: 1,
              hIconHot: nullptr,
              bChecked: 0,
              hIconDisabled: nullptr,
              bAlphaBlend: 0);
          }
        }
        else
        {
          CMFCButton::ClearImages(this, bChecked: 0);
        }
      }
      LOBYTE(v35) = 6;
      ATL::CStringData::Release(this: (ATL::CStringData *)wParam - 1);
    }
  }
  bImageOnTop = 0;
  if ( CMFCControlContainer::ReadBoolProp(&tagManager, lpszTag: "MFCButton_ImageOnTop", bMember: &bImageOnTop) != 0 )
    this->m_bTopImage = bImageOnTop;
  bImageOnRight = 0;
  if ( CMFCControlContainer::ReadBoolProp(&tagManager, lpszTag: "MFCButton_ImageOnRight", bMember: &bImageOnRight) != 0 )
    this->m_bRightImage = bImageOnRight;
  ATL::CStringData::Release(this: (ATL::CStringData *)strImageType.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)strCursorType.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)strFullTextTooltip.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)strTooltip.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)strStyle.m_pszData - 1);
  LOBYTE(v35) = 0;
  CTagManager::~CTagManager(this: &tagManager);
  ATL::CStringData::Release(this: (ATL::CStringData *)strDst.m_pszData - 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A769A
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCButton::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCButton::GetMessageMap(CMFCButton *this)
{
  return &messageMap_34;
}

//------------------------------------------------------------------------------
// Address: 0x103A76A0
// Name: public: virtual struct CRuntimeClass __near * COleDocIPFrameWndEx::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall COleDocIPFrameWndEx::GetRuntimeClass(COleDocIPFrameWndEx *this)
{
  return &COleDocIPFrameWndEx::classCOleDocIPFrameWndEx;
}

//------------------------------------------------------------------------------
// Address: 0x103A76A6
// Name: protected: COleDocIPFrameWndEx::COleDocIPFrameWndEx(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
COleDocIPFrameWndEx *__thiscall COleDocIPFrameWndEx::COleDocIPFrameWndEx(COleDocIPFrameWndEx *this)
{
  COleDocIPFrameWnd::COleDocIPFrameWnd(this);
  this->__vftable = (COleDocIPFrameWndEx_vtbl *)&COleDocIPFrameWndEx::`vftable';
  this->m_bContextHelp = 0;
  this->m_hwndLastTopLevelFrame = nullptr;
  CFrameImpl::CFrameImpl(this: &this->m_Impl, pFrame: this);
  CDockingManager::CDockingManager(this: &this->m_dockManager);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103A76F6
// Name: public: virtual int COleDocIPFrameWndEx::OnShowCustomizePane(class CMFCPopupMenu __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDocIPFrameWndEx::OnShowCustomizePane(
        COleDocIPFrameWndEx *this,
        CMFCPopupMenu *pMenuPane,
        unsigned int uiToolbarID)
{
  CFrameImpl::AddDefaultButtonsToCustomizePane(this: &this->m_Impl, pMenuPane, __formal: uiToolbarID);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103A7713
// Name: protected: virtual COleDocIPFrameWndEx::~COleDocIPFrameWndEx(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleDocIPFrameWndEx::~COleDocIPFrameWndEx(COleDocIPFrameWndEx *this)
{
  this->__vftable = (COleDocIPFrameWndEx_vtbl *)&COleDocIPFrameWndEx::`vftable';
  CDockingManager::~CDockingManager(this: &this->m_dockManager);
  CFrameImpl::~CFrameImpl(this: &this->m_Impl);
  COleDocIPFrameWnd::~COleDocIPFrameWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A775C
// Name: protected: long COleDocIPFrameWndEx::OnMenuChar(unsigned int,unsigned int,class CMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDocIPFrameWndEx::OnMenuChar(
        COleDocIPFrameWndEx *this,
        unsigned int nChar,
        unsigned int nFlags,
        CMenu *pMenu)
{
  if ( CFrameImpl::OnMenuChar(this: &this->m_Impl, nChar) != 0 )
    return -65534;
  else
    return CFrameWnd::OnMenuChar(this, nChar, nFlags, pMenu);
}

//------------------------------------------------------------------------------
// Address: 0x103A7792
// Name: protected: int COleDocIPFrameWndEx::ShowPopupMenu(class CMFCPopupMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDocIPFrameWndEx::ShowPopupMenu(COleDocIPFrameWndEx *this, CMFCPopupMenu *pMenuPopup)
{
  int result; // eax

  result = CFrameImpl::OnShowPopupMenu(this: &this->m_Impl, pMenuPopup, __formal: this);
  if ( result != 0 )
  {
    if ( pMenuPopup != nullptr && pMenuPopup->m_bShown != 0 )
      return 1;
    else
      return this->OnShowPopupMenu(this, a2: pMenuPopup);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A77D2
// Name: public: virtual void COleDocIPFrameWndEx::OnClosePopupMenu(class CMFCPopupMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleDocIPFrameWndEx::OnClosePopupMenu(COleDocIPFrameWndEx *this, CMFCPopupMenu *pMenuPopup)
{
  if ( CMFCPopupMenu::m_pActivePopupMenu == (HWND)pMenuPopup )
    CMFCPopupMenu::m_pActivePopupMenu = nullptr;
  CDockingManager::OnClosePopupMenu(this: &this->m_dockManager);
}

//------------------------------------------------------------------------------
// Address: 0x103A77F7
// Name: protected: virtual int COleDocIPFrameWndEx::OnCommand(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDocIPFrameWndEx::OnCommand(COleDocIPFrameWndEx *this, unsigned int wParam, int lParam)
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
  return CFrameWnd::OnCommand(this, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x103A7862
// Name: public: virtual int COleDocIPFrameWndEx::LoadFrame(unsigned int,unsigned long,class CWnd __near *,struct CCreateContext __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDocIPFrameWndEx::LoadFrame(
        COleDocIPFrameWndEx *this,
        unsigned int nIDResource,
        unsigned int dwDefaultStyle,
        CWnd *pParentWnd,
        CCreateContext *pContext)
{
  this->m_Impl.m_nIDDefaultResource = nIDResource;
  CFrameImpl::LoadLargeIconsState(this: &this->m_Impl);
  return CFrameWnd::LoadFrame(this, nIDResource, dwDefaultStyle, pParentWnd, pContext);
}

//------------------------------------------------------------------------------
// Address: 0x103A7896
// Name: protected: void COleDocIPFrameWndEx::OnContextHelp(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleDocIPFrameWndEx::OnContextHelp(COleDocIPFrameWndEx *this)
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
// Address: 0x103A78DE
// Name: protected: long COleDocIPFrameWndEx::OnToolbarCreateNew(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const CMFCToolBar *__thiscall COleDocIPFrameWndEx::OnToolbarCreateNew(
        COleDocIPFrameWndEx *this,
        unsigned int __formal,
        const char *lp)
{
  if ( lp == nullptr )
    AfxThrowInvalidArgException();
  return CFrameImpl::CreateNewToolBar(this: &this->m_Impl, lpszName: lp);
}

//------------------------------------------------------------------------------
// Address: 0x103A7900
// Name: protected: long COleDocIPFrameWndEx::OnToolbarDelete(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDocIPFrameWndEx::OnToolbarDelete(COleDocIPFrameWndEx *this, unsigned int __formal, CMFCToolBar *lp)
{
  return CFrameImpl::DeleteToolBar(this: &this->m_Impl, pToolBar: lp);
}

//------------------------------------------------------------------------------
// Address: 0x103A7917
// Name: protected: void COleDocIPFrameWndEx::OnClose(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleDocIPFrameWndEx::OnClose(COleDocIPFrameWndEx *this)
{
  CFrameImpl::OnCloseFrame(this: &this->m_Impl);
  CFrameWnd::OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A792F
// Name: public: int COleDocIPFrameWndEx::AddPane(class CBasePane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDocIPFrameWndEx::AddPane(COleDocIPFrameWndEx *this, CBasePane *pControlBar, int bTail)
{
  return CDockingManager::AddPane(
           this: &this->m_dockManager,
           pWnd: pControlBar,
           bTail,
           bAutoHide: 0,
           bInsertForOuterEdge: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103A794D
// Name: public: int COleDocIPFrameWndEx::InsertPane(class CBasePane __near *,class CBasePane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDocIPFrameWndEx::InsertPane(
        COleDocIPFrameWndEx *this,
        CBasePane *pControlBar,
        CBasePane *pTarget,
        int bAfter)
{
  return CDockingManager::InsertPane(this: &this->m_dockManager, pControlBar, pTarget, bAfter);
}

//------------------------------------------------------------------------------
// Address: 0x103A795E
// Name: public: void COleDocIPFrameWndEx::RemovePaneFromDockManager(class CBasePane __near *,int,int,int,class CBasePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleDocIPFrameWndEx::RemovePaneFromDockManager(
        COleDocIPFrameWndEx *this,
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
// Address: 0x103A796F
// Name: public: void COleDocIPFrameWndEx::DockPane(class CBasePane __near *,unsigned int,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleDocIPFrameWndEx::DockPane(
        COleDocIPFrameWndEx *this,
        CBasePane *pBar,
        unsigned int nDockBarID,
        const tagRECT *lpRect)
{
  CDockingManager::DockPane(this: &this->m_dockManager, pBar, nDockBarID, lpRect);
}

//------------------------------------------------------------------------------
// Address: 0x103A7980
// Name: public: class CBasePane __near * COleDocIPFrameWndEx::PaneFromPoint(class CPoint,int,bool,struct CRuntimeClass __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBasePane *__thiscall COleDocIPFrameWndEx::PaneFromPoint(
        COleDocIPFrameWndEx *this,
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
// Address: 0x103A79A7
// Name: public: int COleDocIPFrameWndEx::IsPointNearDockSite(class CPoint,unsigned long __near &,int __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDocIPFrameWndEx::IsPointNearDockSite(
        COleDocIPFrameWndEx *this,
        CPoint point,
        unsigned int *dwBarAlignment,
        int *bOuterEdge)
{
  return CDockingManager::IsPointNearDockSite(this: &this->m_dockManager, point, dwBarAlignment, bOuterEdge);
}

//------------------------------------------------------------------------------
// Address: 0x103A79C7
// Name: public: virtual int COleDocIPFrameWndEx::OnMoveMiniFrame(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDocIPFrameWndEx::OnMoveMiniFrame(COleDocIPFrameWndEx *this, CWnd *pFrame)
{
  return this->m_dockManager.OnMoveMiniFrame(this: &this->m_dockManager, a2: pFrame);
}

//------------------------------------------------------------------------------
// Address: 0x103A79D8
// Name: protected: virtual int COleDocIPFrameWndEx::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDocIPFrameWndEx::PreCreateWindow(COleDocIPFrameWndEx *this, tagCREATESTRUCTA *cs)
{
  this->m_Impl.m_pDockManager = &this->m_dockManager;
  return CFrameWnd::PreCreateWindow(this, cs);
}

//------------------------------------------------------------------------------
// Address: 0x103A79EF
// Name: public: class CBasePane __near * COleDocIPFrameWndEx::GetPane(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBasePane *__thiscall COleDocIPFrameWndEx::GetPane(COleDocIPFrameWndEx *this, unsigned int nID)
{
  return this->m_dockManager.FindPaneByID(this: &this->m_dockManager, a2: nID, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x103A7A08
// Name: protected: int COleDocIPFrameWndEx::OnPaneCheck(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDocIPFrameWndEx::OnPaneCheck(COleDocIPFrameWndEx *this, unsigned int nID)
{
  CBasePane *Pane; // eax
  CBasePane *v3; // esi
  unsigned int Style; // eax

  Pane = COleDocIPFrameWndEx::GetPane(this, nID);
  v3 = Pane;
  if ( Pane == nullptr )
    return 0;
  Style = CWnd::GetStyle(this: Pane);
  v3->ShowPane(this: v3, a2: (Style & 0x10000000) == 0, a3: 0, a4: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103A7A46
// Name: public: virtual void COleDocIPFrameWndEx::OnSetPreviewMode(int,struct CPrintPreviewState __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleDocIPFrameWndEx::OnSetPreviewMode(
        COleDocIPFrameWndEx *this,
        int bPreview,
        CPrintPreviewState *pState)
{
  unsigned int dwStates; // ebx

  CDockingManager::SetPrintPreviewMode(this: &this->m_dockManager, bPreview, __formal: pState);
  dwStates = pState->dwStates;
  CFrameWnd::OnSetPreviewMode(this, bPreview, pState);
  pState->dwStates = dwStates;
  this->RecalcLayout(this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x103A7A86
// Name: public: virtual void COleDocIPFrameWndEx::RecalcLayout(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleDocIPFrameWndEx::RecalcLayout(COleDocIPFrameWndEx *this, CView *bNotify)
{
  CDockingManager_vtbl *v3; // eax
  CView *ActiveView; // ecx
  CView *pView; // [esp+1Ch] [ebp+8h]

  COleDocIPFrameWnd::RecalcLayout(this, __formal: (int)bNotify);
  if ( this->m_bInRecalcLayout == 0 )
  {
    v3 = this->m_dockManager.__vftable;
    this->m_bInRecalcLayout = 1;
    ((void (__stdcall *)(CView *))v3->RecalcLayout)(a1: bNotify);
    ActiveView = CFrameWnd::GetActiveView(this);
    pView = ActiveView;
    if ( ActiveView != nullptr
      && CObject::IsKindOf(this: ActiveView, pClass: &CPreviewViewEx::classCPreviewViewEx) != 0
      && this->m_dockManager.m_bIsPrintPreviewMode != 0 )
    {
      CWnd::SetWindowPos(
        this: pView,
        pWndInsertAfter: nullptr,
        x: this->m_dockManager.m_rectClientAreaBounds.left,
        y: this->m_dockManager.m_rectClientAreaBounds.top,
        cx: this->m_dockManager.m_rectClientAreaBounds.right - this->m_dockManager.m_rectClientAreaBounds.left,
        cy: this->m_dockManager.m_rectClientAreaBounds.bottom - this->m_dockManager.m_rectClientAreaBounds.top,
        nFlags: 0x14u);
    }
    this->m_bInRecalcLayout = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A7B1E
// Name: protected: long COleDocIPFrameWndEx::OnIdleUpdateCmdUI(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDocIPFrameWndEx::OnIdleUpdateCmdUI(
        COleDocIPFrameWndEx *this,
        unsigned int __formal,
        unsigned int __formala)
{
  COleCntrFrameWndEx *v4; // eax

  COleIPFrameWnd::OnIdleUpdateCmdUI(this);
  CDockingManager::SendMessageToMiniFrames(this: &this->m_dockManager, uMessage: 0x363u, wParam: 0, lParam: 0);
  v4 = (COleCntrFrameWndEx *)AfxDynamicDownCast(
                               pClass: &COleCntrFrameWndEx::classCOleCntrFrameWndEx,
                               pObject: this->m_pMainFrame);
  if ( v4 != nullptr )
    COleCntrFrameWndEx::OnIdleUpdateCmdUI(this: v4);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A7B5F
// Name: public: virtual int COleDocIPFrameWndEx::OnShowPanes(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDocIPFrameWndEx::OnShowPanes(COleDocIPFrameWndEx *this, int bShow)
{
  int v3; // edi

  v3 = this->m_dockManager.ShowPanes(this: &this->m_dockManager, a2: bShow);
  this->AdjustDockingLayout(this, a2: nullptr);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x103A7B8C
// Name: public: virtual int COleDocIPFrameWndEx::OnCmdMsg(unsigned int,int,void __near *,struct AFX_CMDHANDLERINFO __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDocIPFrameWndEx::OnCmdMsg(
        COleDocIPFrameWndEx *this,
        unsigned int nID,
        int nCode,
        void *pExtra,
        AFX_CMDHANDLERINFO *pHandlerInfo)
{
  if ( CFrameWnd::OnCmdMsg(this, nID, nCode, pExtra, pHandlerInfo) != 0 )
    return 1;
  else
    return CDockingManager::ProcessPaneContextMenuCommand(
             this: &this->m_dockManager,
             nID,
             nCode,
             pExtra,
             __formal: pHandlerInfo);
}

//------------------------------------------------------------------------------
// Address: 0x103A7BCA
// Name: public: static class CObject __near * COleDocIPFrameWndEx::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
COleDocIPFrameWndEx *__stdcall COleDocIPFrameWndEx::CreateObject()
{
  COleDocIPFrameWndEx *v0; // ecx
  COleDocIPFrameWndEx *result; // eax

  v0 = (COleDocIPFrameWndEx *)operator new(nSize: 0x488u);
  result = nullptr;
  if ( v0 != nullptr )
    return COleDocIPFrameWndEx::COleDocIPFrameWndEx(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A7C1B
// Name: public: virtual int COleDocIPFrameWndEx::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDocIPFrameWndEx::PreTranslateMessage(COleDocIPFrameWndEx *this, CWnd *pMsg)
{
  unsigned int m_dwRef; // eax
  int v5; // eax
  CWnd *v7; // eax
  tagPOINT v8; // [esp-Ch] [ebp-20h]
  HWND__ *v9; // [esp-4h] [ebp-18h]
  HWND__ *v10; // [esp-4h] [ebp-18h]
  CPoint pt; // [esp+Ch] [ebp-8h] BYREF
  CWnd *pWnd; // [esp+1Ch] [ebp+8h]

  m_dwRef = pMsg->m_dwRef;
  if ( m_dwRef > 0x100 )
  {
    if ( m_dwRef != 512 )
    {
      if ( m_dwRef == 513 || m_dwRef - 515 <= 6 )
      {
        v9 = (HWND__ *)pMsg->__vftable;
        pt.x = SLOWORD(pMsg->m_xInnerUnknown);
        pt.y = SHIWORD(pMsg->m_xInnerUnknown);
        pWnd = CWnd::FromHandle(hWnd: v9);
        if ( pWnd != nullptr && IsWindow(hWnd: (HWND)pMsg->__vftable) )
          ClientToScreen(hWnd: pWnd->m_hWnd, lpPoint: &pt);
        if ( CFrameImpl::ProcessMouseClick(
               this: &this->m_Impl,
               uiMsg: pMsg->m_dwRef,
               pt: pt.tagPOINT,
               hwnd: (HWND__ *)pMsg->__vftable) != 0
          || !IsWindow(hWnd: (HWND)pMsg->__vftable) )
        {
          return 1;
        }
      }
      return CFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
    }
    v10 = (HWND__ *)pMsg->__vftable;
    pt.x = SLOWORD(pMsg->m_xInnerUnknown);
    pt.y = SHIWORD(pMsg->m_xInnerUnknown);
    v7 = CWnd::FromHandle(hWnd: v10);
    if ( v7 != nullptr )
      ClientToScreen(hWnd: v7->m_hWnd, lpPoint: &pt);
    v5 = CFrameImpl::ProcessMouseMove(this: &this->m_Impl, pt: pt.tagPOINT);
  }
  else if ( m_dwRef == 256 )
  {
    if ( CFrameImpl::IsHelpKey(lpMsg: (tagMSG *)pMsg) != 0 )
      return CFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
    v5 = CFrameImpl::ProcessKeyboard(this: &this->m_Impl, nKey: (int)pMsg->m_pOuterUnknown, pbProcessAccel: nullptr);
  }
  else
  {
    if ( m_dwRef < 0xA1 || m_dwRef > 0xA2 && (m_dwRef <= 0xA3 || m_dwRef > 0xA5 && m_dwRef - 167 > 1) )
      return CFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
    v8.y = SHIWORD(pMsg->m_xInnerUnknown);
    v8.x = SLOWORD(pMsg->m_xInnerUnknown);
    v5 = CFrameImpl::ProcessMouseClick(this: &this->m_Impl, uiMsg: m_dwRef, pt: v8, hwnd: (HWND__ *)pMsg->__vftable);
  }
  if ( v5 != 0 )
    return 1;
  return CFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x103A7D6A
// Name: protected: virtual void COleDocIPFrameWndEx::HtmlHelpA(unsigned long,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleDocIPFrameWndEx::HtmlHelpA(COleDocIPFrameWndEx *this, unsigned int dwData, unsigned int nCmd)
{
  if ( dwData != 0 || this->m_bContextHelp == 0 )
    CWnd::HtmlHelpA(this, dwData, nCmd);
  else
    COleDocIPFrameWndEx::OnContextHelp(this);
}

//------------------------------------------------------------------------------
// Address: 0x1040B696
// Name: protected: int CMFCListCtrl::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCListCtrl::OnCreate(CMFCListCtrl *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax

  result = CWnd::Default(this);
  if ( result != -1 )
    return (CMFCListCtrl::InitList(this) != 0) - 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040B6BB
// Name: protected: void CMFCListCtrl::OnSysColorChange(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCListCtrl::OnSysColorChange(CMFCListCtrl *this)
{
  CWnd::OnSysColorChange(this);
  CMFCListCtrl::InitColors(this);
  RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
}

//------------------------------------------------------------------------------
// Address: 0x1040B6E0
// Name: public: virtual void CMFCListCtrl::Sort(int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCListCtrl::Sort(CMFCListCtrl *this, int iColumn, int bAscending, int bAdd)
{
  AFX_MODULE_STATE *ModuleState; // eax
  CMFCHeaderCtrl *v6; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-2Ch]
  int v8; // [esp-4h] [ebp-20h]

  ModuleState = AfxGetModuleState();
  CCmdTarget::BeginWaitCursor(this: ModuleState->m_pCurrentWinApp);
  v8 = bAdd;
  v6 = this->GetHeaderCtrl(this);
  CMFCHeaderCtrl::SetSortColumn(this: v6, iColumn, bAscending, bAdd: v8);
  m_hWnd = this->m_hWnd;
  this->m_iSortedColumn = iColumn;
  this->m_bAscending = bAscending;
  SendMessageA(hWnd: m_hWnd, Msg: 0x1030u, wParam: (WPARAM)this, lParam: (LPARAM)CMFCListCtrl::CompareProc);
  CWaitCursor::~CWaitCursor(this: (CWaitCursor *)&bAdd + 3);
}

//------------------------------------------------------------------------------
// Address: 0x1040B74F
// Name: protected: int CMFCListCtrl::OnEraseBkgnd(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCListCtrl::OnEraseBkgnd(CMFCListCtrl *this, CDC *pDC)
{
  CMFCListCtrl_vtbl *v3; // eax
  WPARAM m_iSortedColumn; // esi
  int v5; // eax
  CMFCHeaderCtrl *v6; // eax
  HWND__ *m_hWnd; // [esp-Ch] [ebp-58h]
  unsigned int m_clrSortedColumn; // [esp-8h] [ebp-54h]
  int bRes; // [esp+8h] [ebp-44h]
  CBrush br; // [esp+10h] [ebp-3Ch] BYREF
  CRect rectColumn; // [esp+18h] [ebp-34h] BYREF
  CRect rectClient; // [esp+28h] [ebp-24h] BYREF
  CRect rectHeader; // [esp+38h] [ebp-14h] BYREF

  bRes = CWnd::Default(this);
  if ( this->m_iSortedColumn >= 0 && this->m_bMarkSortedColumn != 0 )
  {
    m_hWnd = this->m_hWnd;
    memset(&rectClient, 0, sizeof(rectClient));
    GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
    v3 = this->__vftable;
    memset(&rectHeader, 0, sizeof(rectHeader));
    m_iSortedColumn = this->m_iSortedColumn;
    v5 = (int)v3->GetHeaderCtrl(this);
    SendMessageA(hWnd: *(HWND *)(v5 + 32), Msg: 0x1207u, wParam: m_iSortedColumn, lParam: (LPARAM)&rectHeader);
    v6 = this->GetHeaderCtrl(this);
    MapWindowPoints(hWndFrom: v6->m_hWnd, hWndTo: this->m_hWnd, lpPoints: (LPPOINT)&rectHeader, cPoints: 2u);
    m_clrSortedColumn = this->m_clrSortedColumn;
    rectColumn.top = rectClient.top;
    rectColumn.bottom = rectClient.bottom;
    rectColumn.left = rectHeader.left;
    rectColumn.right = rectHeader.right;
    CBrush::CBrush(this: &br, crColor: m_clrSortedColumn);
    FillRect(hDC: pDC->m_hDC, lprc: &rectColumn, hbr: (HBRUSH)br.m_hObject);
    br.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
    CGdiObject::~CGdiObject(this: &br);
  }
  return bRes;
}

//------------------------------------------------------------------------------
// Address: 0x1040B84D
// Name: protected: static struct AFX_MSGMAP const __near * CMFCListCtrl::GetThisMessageMap(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCListCtrl::GetThisMessageMap(CMFCListCtrl *this)
{
  return &messageMap_45;
}

//------------------------------------------------------------------------------
// Address: 0x1040CE56
// Name: public: int CMFCHeaderCtrl::GetColumnState(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCHeaderCtrl::GetColumnState(CMFCHeaderCtrl *this, int iColumn)
{
  int nSortVal; // [esp+0h] [ebp-4h] BYREF

  nSortVal = 0;
  CMap<int,int,unsigned int,unsigned int>::Lookup(this: &this->m_mapColumnsStatus, key: iColumn, rValue: &nSortVal);
  return nSortVal;
}

//------------------------------------------------------------------------------
// Address: 0x1040CE76
// Name: public: void CMFCHeaderCtrl::SetSortColumn(int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCHeaderCtrl::SetSortColumn(CMFCHeaderCtrl *this, int iColumn, int bAscending, int bAdd)
{
  if ( iColumn >= 0 )
  {
    if ( bAdd == 0 )
      goto LABEL_7;
    if ( this->m_bMultipleSort == 0 )
      bAdd = 0;
    if ( bAdd == 0 )
LABEL_7:
      CMap<unsigned int,unsigned int,CPane *,CPane *>::RemoveAll(this: (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&this->m_mapColumnsStatus);
    *CMap<int,int,int,int>::operator[](this: &this->m_mapColumnsStatus, key: iColumn) = 2 * (bAscending != 0) - 1;
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
  else
  {
    CMap<unsigned int,unsigned int,CPane *,CPane *>::RemoveAll(this: (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&this->m_mapColumnsStatus);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040CEDC
// Name: protected: void CMFCHeaderCtrl::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCHeaderCtrl::OnPaint(CMFCHeaderCtrl *this)
{
  CDC *p_m_dcMem; // eax
  LRESULT v3; // eax
  BOOL v4; // eax
  BOOL v5; // edi
  HRGN v6; // eax
  WPARAM v7; // esi
  CDC *v8; // esi
  HWND__ *v9; // [esp-10h] [ebp-134h]
  HWND__ *m_hWnd; // [esp-8h] [ebp-12Ch]
  HWND__ *v11; // [esp-8h] [ebp-12Ch]
  CFont *v12; // [esp+10h] [ebp-114h]
  tagPOINT Point; // [esp+14h] [ebp-110h] BYREF
  LRESULT v14; // [esp+1Ch] [ebp-108h]
  CGdiObject v15; // [esp+20h] [ebp-104h] BYREF
  int right; // [esp+28h] [ebp-FCh]
  WPARAM wParam; // [esp+2Ch] [ebp-F8h]
  CDC *pDC; // [esp+30h] [ebp-F4h]
  CPaintDC v19; // [esp+34h] [ebp-F0h] BYREF
  CMemDC v20; // [esp+88h] [ebp-9Ch] BYREF
  tagPOINT lParam; // [esp+C4h] [ebp-60h] BYREF
  char v22; // [esp+CCh] [ebp-58h]
  tagRECT v23; // [esp+D4h] [ebp-50h] BYREF
  tagRECT Rect; // [esp+E4h] [ebp-40h] BYREF
  tagRECT v25; // [esp+F4h] [ebp-30h] BYREF
  RECT v26; // [esp+104h] [ebp-20h] BYREF
  int v27; // [esp+120h] [ebp-4h]

  if ( (CWnd::GetStyle(this) & 0x100) != 0 )
  {
    CWnd::Default(this);
  }
  else
  {
    CPaintDC::CPaintDC(this: &v19, pWnd: this);
    v27 = 0;
    CMemDC::CMemDC(this: &v20, dc: &v19, pWnd: this);
    LOBYTE(v27) = 1;
    p_m_dcMem = &v20.m_dcMem;
    if ( v20.m_bMemDC == 0 )
      p_m_dcMem = v20.m_dc;
    pDC = p_m_dcMem;
    memset(&Rect, 0, sizeof(Rect));
    CDC::GetClipBox(this: &v19, lpRect: &Rect);
    m_hWnd = this->m_hWnd;
    memset(&v23, 0, sizeof(v23));
    GetClientRect(hWnd: m_hWnd, lpRect: &v23);
    this->OnFillBackground(this, a2: pDC);
    v12 = CMFCHeaderCtrl::SelectFont(this, pDC);
    pDC->SetTextColor(this: pDC, a2: afxGlobalData.clrBtnText);
    CDC::SetBkMode(this: pDC, nBkMode: 1);
    v11 = this->m_hWnd;
    memset(&v25, 0, sizeof(v25));
    GetClientRect(hWnd: v11, lpRect: &v25);
    v9 = this->m_hWnd;
    memset(&v26, 0, sizeof(v26));
    v14 = SendMessageA(hWnd: v9, Msg: 0x1200u, wParam: 0, lParam: 0);
    right = 0;
    wParam = 0;
    if ( v14 > 0 )
    {
      do
      {
        Point.x = 0;
        Point.y = 0;
        GetCursorPos(lpPoint: &Point);
        ScreenToClient(hWnd: this->m_hWnd, lpPoint: &Point);
        lParam = Point;
        v3 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x1206u, wParam: 0, (LPARAM)&lParam);
        v4 = v3 == wParam && (v22 & 2) != 0;
        v5 = this->m_bIsMousePressed != 0 && v4;
        SendMessageA(hWnd: this->m_hWnd, Msg: 0x1207u, wParam, lParam: (LPARAM)&v26);
        v15.m_hObject = nullptr;
        v15.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
        LOBYTE(v27) = 2;
        v6 = CreateRectRgnIndirect(lprect: &v26);
        CGdiObject::Attach(this: &v15, hObject: v6);
        CDC::SelectClipRgn(this: pDC, pRgn: (CRgn *)&v15);
        v7 = wParam;
        ((void (__thiscall *)(CMFCHeaderCtrl *, CDC *, WPARAM, int, int, int, int, BOOL, bool))this->OnDrawItem)(
          a1: this,
          a2: pDC,
          a3: wParam,
          a4: v26.left,
          a5: v26.top,
          a6: v26.right,
          a7: v26.bottom,
          a8: v5,
          a9: this->m_nHighlightedItem == wParam);
        CDC::SelectClipRgn(this: pDC, pRgn: nullptr);
        if ( right <= v26.right )
          right = v26.right;
        LOBYTE(v27) = 1;
        v15.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
        CGdiObject::~CGdiObject(this: &v15);
        wParam = v7 + 1;
      }
      while ( (int)(v7 + 1) < v14 );
    }
    if ( v14 != 0 )
      v26.left = right;
    else
      v26 = v25;
    v26.right = v25.right + 1;
    v8 = pDC;
    ((void (__thiscall *)(CMFCHeaderCtrl *, CDC *, int, int, int, int, int, _DWORD, _DWORD))this->OnDrawItem)(
      a1: this,
      a2: pDC,
      a3: -1,
      a4: v26.left,
      a5: v26.top,
      a6: v25.right + 1,
      a7: v26.bottom,
      a8: 0,
      a9: 0);
    v8->SelectObject(this: v8, a2: v12);
    LOBYTE(v27) = 0;
    CMemDC::~CMemDC(this: &v20);
    v27 = -1;
    CPaintDC::~CPaintDC(this: &v19);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040D1D1
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCHeaderCtrl::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCHeaderCtrl::GetMessageMap(CMFCHeaderCtrl *this)
{
  return (const AFX_MSGMAP *)&off_1068C9F4;
}

//------------------------------------------------------------------------------
// Address: 0x1040D1D7
// Name: protected: virtual void CMFCHeaderCtrl::OnDrawItem(class CDC __near *,int,class CRect,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCHeaderCtrl::OnDrawItem(
        CMFCHeaderCtrl *this,
        CDC *pDC,
        int iItem,
        CRect rect,
        int bIsPressed,
        int bIsHighlighted)
{
  CMFCVisualManager *Instance; // eax
  int right; // ecx
  int v9; // eax
  CImageList *ImageList; // eax
  CImageList *v11; // esi
  CBitmap *v12; // eax
  int v13; // ecx
  int v14; // edi
  int v15; // eax
  unsigned int v16; // eax
  CPoint v17; // [esp-1Ch] [ebp-1B4h]
  CDC *v18; // [esp-14h] [ebp-1ACh]
  CSize v19; // [esp-14h] [ebp-1ACh]
  int left; // [esp-10h] [ebp-1A8h]
  HWND__ *m_hWnd; // [esp-10h] [ebp-1A8h]
  int top; // [esp-Ch] [ebp-1A4h]
  struct _IMAGELIST *m_hImageList; // [esp-Ch] [ebp-1A4h]
  tagPOINT v24; // [esp-Ch] [ebp-1A4h]
  void *m_hObject; // [esp-Ch] [ebp-1A4h]
  int v26; // [esp-8h] [ebp-1A0h]
  _BYTE pv[4]; // [esp+10h] [ebp-188h] BYREF
  int v28; // [esp+14h] [ebp-184h]
  int v29; // [esp+18h] [ebp-180h]
  unsigned __int8 dst[48]; // [esp+28h] [ebp-170h] BYREF
  CDC *pDCa; // [esp+58h] [ebp-140h]
  CBitmap *pBitmap; // [esp+5Ch] [ebp-13Ch] BYREF
  int v33; // [esp+60h] [ebp-138h] BYREF
  int rValue; // [esp+64h] [ebp-134h] BYREF
  tagRECT v35; // [esp+68h] [ebp-130h] BYREF
  tagRECT rc; // [esp+78h] [ebp-120h] BYREF
  char v37; // [esp+88h] [ebp-110h] BYREF
  int v38; // [esp+194h] [ebp-4h]

  pDCa = pDC;
  Instance = CMFCVisualManager::GetInstance();
  Instance->OnDrawHeaderCtrlBorder(this: Instance, a2: this, a3: pDC, a4: &rect, a5: bIsPressed, a6: bIsHighlighted);
  if ( iItem >= 0 )
  {
    rValue = 0;
    if ( CMap<int,int,unsigned int,unsigned int>::Lookup(this: &this->m_mapColumnsStatus, key: iItem, &rValue) != 0
      && rValue != 0 )
    {
      rc = rect.tagRECT;
      InflateRect(lprc: &rc, dx: -5, dy: -5);
      right = rc.right;
      v9 = rc.right + rc.top - rc.bottom;
      rc.left = v9;
      if ( bIsPressed != 0 )
      {
        right = rc.right + 1;
        ++rc.bottom;
        ++rc.right;
      }
      v33 = right - v9;
      rect.right = v9 - 1;
      InflateRect(lprc: &rc, dx: 0, dy: -(int)((double)(right - v9) * 0.134));
      v18 = pDCa;
      left = rc.left;
      top = rc.top;
      v26 = rc.right;
      this->m_bAscending = rValue > 0;
      ((void (__thiscall *)(CMFCHeaderCtrl *, CDC *, int, int, int, int))this->OnDrawSortArrow)(
        a1: this,
        a2: v18,
        a3: left,
        a4: top,
        a5: v26,
        a6: rc.bottom);
    }
    memset(dst, value: 0, count: sizeof(dst));
    *(_DWORD *)&dst[8] = &v37;
    *(_DWORD *)dst = 54;
    m_hWnd = this->m_hWnd;
    *(_DWORD *)&dst[16] = 255;
    if ( SendMessageA(hWnd: m_hWnd, Msg: 0x1203u, wParam: iItem, lParam: (LPARAM)dst) != 0 )
    {
      if ( (*(_WORD *)&dst[20] & 0x800) != 0 && *(int *)&dst[28] >= 0 )
      {
        ImageList = CHeaderCtrl::GetImageList(this, nImageList: 0);
        v11 = ImageList;
        if ( ImageList != nullptr )
        {
          m_hImageList = ImageList->m_hImageList;
          v33 = 0;
          rValue = 0;
          ImageList_GetIconSize(himl: m_hImageList, cx: &v33, cy: &rValue);
          *(_QWORD *)&rc.right = *(_QWORD *)&rect.left;
          v24.y = (rect.top + rect.bottom - rValue) / 2;
          v24.x = rect.left + 1;
          CImageList::Draw(this: v11, pDC: pDCa, nImage: *(int *)&dst[28], pt: v24, nStyle: 0);
          rect.left += v33;
        }
      }
      if ( (*(_WORD *)&dst[20] & 0x3000) != 0 && *(_DWORD *)&dst[12] != 0 )
      {
        v12 = (CBitmap *)CGdiObject::FromHandle(h: *(void **)&dst[12]);
        m_hObject = v12->m_hObject;
        pBitmap = v12;
        GetObjectA(h: m_hObject, c: 24, pv);
        rc = rect.tagRECT;
        if ( (*(_WORD *)&dst[20] & 0x1000) != 0 )
        {
          v13 = rect.right - 1;
          v14 = rect.right - 1 - v28;
          rect.right = v14;
        }
        else
        {
          v14 = rect.left + 1;
          v13 = rect.left + 1 + v28;
          rect.left = v13;
        }
        v15 = (rc.bottom - rc.top - v29) / 2;
        if ( v15 < 0 )
          v15 = 0;
        v19.cy = v29;
        v19.cx = v13 - v14;
        v17.y = v15 + rc.top;
        v17.x = v14;
        CDC::DrawState(this: pDCa, pt: v17, size: v19, pBitmap, nFlags: 0, pBrush: nullptr);
      }
      if ( (*(_WORD *)&dst[20] & 0x4000) != 0 && *(_DWORD *)&dst[8] != 0 )
      {
        v35 = rect.tagRECT;
        InflateRect(lprc: &v35, dx: -5, dy: 0);
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
          this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pBitmap,
          pszSrc: *(const char **)&dst[8]);
        v38 = 0;
        v16 = 34852;
        if ( (dst[20] & 2) != 0 )
        {
          v16 = 34853;
        }
        else if ( (dst[20] & 1) != 0 )
        {
          v16 = 34854;
        }
        pDCa->DrawTextA(this: pDCa, a2: (const char *)pBitmap, a3: (int)pBitmap[-2].m_hObject, a4: &v35, a5: v16);
        ATL::CStringData::Release(this: (ATL::CStringData *)&pBitmap[-2]);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040D521
// Name: public: virtual struct CRuntimeClass __near * CMFCToolBarComboBoxButton::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCToolBarComboBoxButton::GetRuntimeClass(CMFCToolBarComboBoxButton *this)
{
  return &CMFCToolBarComboBoxButton::classCMFCToolBarComboBoxButton;
}

//------------------------------------------------------------------------------
// Address: 0x1040D527
// Name: protected: void CMFCToolBarComboBoxButton::Initialize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarComboBoxButton::Initialize(CMFCToolBarComboBoxButton *this)
{
  this->m_iSelIndex = -1;
  this->m_pWndCombo = nullptr;
  this->m_pWndEdit = nullptr;
  this->m_bHorz = 1;
  SetRectEmpty(lprc: &this->m_rectCombo);
  SetRectEmpty(lprc: &this->m_rectButton);
  this->m_bIsHotEdit = 0;
  this->m_uiMenuResID = 0;
  this->m_bIsRibbon = 0;
  this->m_nDropDownHeight = 150;
}

//------------------------------------------------------------------------------
// Address: 0x1040D57C
// Name: public: int CMFCToolBarComboBoxButton::GetCount(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarComboBoxButton::GetCount(CMFCToolBarComboBoxButton *this)
{
  return this->m_lstItems.m_nCount;
}

//------------------------------------------------------------------------------
// Address: 0x1040D583
// Name: protected: void CMFCToolBarComboBoxEdit::OnChange(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarComboBoxEdit::OnChange(CMFCToolBarComboBoxEdit *this)
{
  this->m_combo->NotifyCommand(this: this->m_combo, a2: 5);
}

//------------------------------------------------------------------------------
// Address: 0x1040D58E
// Name: public: virtual int CMFCToolBarComboBoxButton::Compare(char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarComboBoxButton::Compare(
        CMFCToolBarComboBoxButton *this,
        const char *lpszItem1,
        const char *lpszItem2)
{
  return _mbscmp(s1: (const unsigned __int8 *)lpszItem1, s2: (const unsigned __int8 *)lpszItem2);
}

//------------------------------------------------------------------------------
// Address: 0x1040D5A4
// Name: public: struct __POSITION __near * CStringList::FindIndex(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<unsigned long,unsigned long>::CNode *__thiscall CStringList::FindIndex(
        CList<unsigned long,unsigned long> *this,
        int nIndex)
{
  int v2; // edx
  CList<unsigned long,unsigned long>::CNode *result; // eax

  v2 = nIndex;
  if ( nIndex >= this->m_nCount || nIndex < 0 )
    return nullptr;
  result = this->m_pNodeHead;
  if ( nIndex != 0 )
  {
    do
    {
      --v2;
      result = result->pNext;
    }
    while ( v2 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040D5C7
// Name: public: char const __near * CMFCToolBarComboBoxButton::GetItem(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__thiscall CMFCToolBarComboBoxButton::GetItem(CMFCToolBarComboBoxButton *this, LRESULT iIndex)
{
  LRESULT m_iSelIndex; // eax
  CComboBox *m_pWndCombo; // eax
  CList<unsigned long,unsigned long>::CNode *Index; // eax

  m_iSelIndex = iIndex;
  if ( iIndex == -1 )
  {
    m_pWndCombo = this->m_pWndCombo;
    if ( m_pWndCombo != nullptr && m_pWndCombo->m_hWnd != nullptr )
    {
      m_iSelIndex = SendMessageA(hWnd: m_pWndCombo->m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    }
    else
    {
      m_iSelIndex = this->m_iSelIndex;
      if ( m_iSelIndex == -1 )
        return nullptr;
    }
  }
  Index = CStringList::FindIndex(this: (CList<unsigned long,unsigned long> *)&this->m_lstItems, nIndex: m_iSelIndex);
  if ( Index == nullptr )
    return nullptr;
  return (const char *)Index->data;
}

//------------------------------------------------------------------------------
// Address: 0x1040D61D
// Name: public: unsigned long CMFCToolBarComboBoxButton::GetItemData(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LRESULT __thiscall CMFCToolBarComboBoxButton::GetItemData(CMFCToolBarComboBoxButton *this, LRESULT iIndex)
{
  LRESULT m_iSelIndex; // eax
  CComboBox *m_pWndCombo; // eax
  CComboBox *v6; // ecx
  CList<unsigned long,unsigned long>::CNode *Index; // eax

  m_iSelIndex = iIndex;
  if ( iIndex == -1 )
  {
    m_pWndCombo = this->m_pWndCombo;
    if ( m_pWndCombo != nullptr && m_pWndCombo->m_hWnd != nullptr )
    {
      m_iSelIndex = SendMessageA(hWnd: m_pWndCombo->m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    }
    else
    {
      m_iSelIndex = this->m_iSelIndex;
      if ( m_iSelIndex == -1 )
        return 0;
    }
  }
  v6 = this->m_pWndCombo;
  if ( v6 != nullptr && v6->m_hWnd != nullptr )
    return SendMessageA(hWnd: v6->m_hWnd, Msg: 0x150u, wParam: m_iSelIndex, lParam: 0);
  Index = CStringList::FindIndex(this: &this->m_lstItemData, nIndex: m_iSelIndex);
  if ( Index == nullptr )
    return 0;
  return Index->data;
}

//------------------------------------------------------------------------------
// Address: 0x1040D695
// Name: protected: void CMFCToolBarComboBoxButton::SetHotEdit(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarComboBoxButton::SetHotEdit(CMFCToolBarComboBoxButton *this, int bHot)
{
  CComboBox *m_pWndCombo; // eax
  HWND Parent; // eax
  HWND v5; // eax
  CWnd *v6; // eax
  HWND v7; // eax
  CWnd *v8; // eax

  if ( this->m_bIsHotEdit != bHot )
  {
    m_pWndCombo = this->m_pWndCombo;
    this->m_bIsHotEdit = bHot;
    Parent = GetParent(hWnd: m_pWndCombo->m_hWnd);
    if ( CWnd::FromHandle(hWnd: Parent) != nullptr )
    {
      v5 = GetParent(hWnd: this->m_pWndCombo->m_hWnd);
      v6 = CWnd::FromHandle(hWnd: v5);
      InvalidateRect(hWnd: v6->m_hWnd, lpRect: &this->m_rectCombo, bErase: true);
      v7 = GetParent(hWnd: this->m_pWndCombo->m_hWnd);
      v8 = CWnd::FromHandle(hWnd: v7);
      UpdateWindow(hWnd: v8->m_hWnd);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040D70D
// Name: public: virtual struct HBRUSH__ __near * CMFCToolBarComboBoxButton::OnCtlColor(class CDC __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HBRUSH__ *__thiscall CMFCToolBarComboBoxButton::OnCtlColor(
        CMFCToolBarComboBoxButton *this,
        CDC *pDC,
        unsigned int __formal)
{
  pDC->SetTextColor(this: pDC, a2: afxGlobalData.clrWindowText);
  pDC->SetBkColor(this: pDC, a2: afxGlobalData.clrWindow);
  return (HBRUSH__ *)afxGlobalData.brWindow.m_hObject;
}

//------------------------------------------------------------------------------
// Address: 0x1040D73A
// Name: public: virtual int CMFCToolBarComboBoxButton::OnClick(class CWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarComboBoxButton::OnClick(CMFCToolBarComboBoxButton *this, CWnd *pWnd, int __formal)
{
  CComboBox *m_pWndCombo; // eax
  CEdit *m_pWndEdit; // ecx

  m_pWndCombo = this->m_pWndCombo;
  if ( m_pWndCombo == nullptr || m_pWndCombo->m_hWnd == nullptr || this->m_bHorz == 0 )
    return 0;
  if ( CMFCToolBarComboBoxButton::m_bFlat != 0 )
  {
    m_pWndEdit = this->m_pWndEdit;
    if ( m_pWndEdit == nullptr )
      m_pWndEdit = (CEdit *)m_pWndCombo;
    CWnd::SetFocus(this: m_pWndEdit);
    SendMessageA(hWnd: this->m_pWndCombo->m_hWnd, Msg: 0x14Fu, wParam: 1u, lParam: 0);
    if ( pWnd != nullptr )
      InvalidateRect(hWnd: pWnd->m_hWnd, lpRect: &this->m_rectCombo, bErase: true);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1040D7AF
// Name: public: virtual int CMFCToolBarComboBoxButton::OnDrawOnCustomizeList(class CDC __near *,class CRect const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarComboBoxButton::OnDrawOnCustomizeList(
        CMFCToolBarComboBoxButton *this,
        CDC *pDC,
        const CRect *rect,
        int bSelected)
{
  int v4; // eax
  int v5; // ecx
  int v6; // ecx
  CMFCVisualManager *Instance; // eax
  CRect rectBtn; // [esp+14h] [ebp-24h] BYREF
  CRect rectCombo; // [esp+24h] [ebp-14h] BYREF

  v4 = CMFCToolBarButton::OnDrawOnCustomizeList(this, pDC, rect, bSelected);
  v5 = rect->right - rect->left;
  rectCombo = *rect;
  v6 = v5 - (v4 + 10);
  if ( v6 < 20 )
    v6 = 20;
  rectCombo.left = rectCombo.right - v6;
  InflateRect(lprc: &rectCombo, dx: -1, dy: -1);
  FillRect(hDC: pDC->m_hDC, lprc: &rectCombo, hbr: (HBRUSH)afxGlobalData.brWindow.m_hObject);
  CDC::Draw3dRect(
    this: pDC,
    lpRect: &rectCombo,
    clrTopLeft: afxGlobalData.clrBarShadow,
    clrBottomRight: afxGlobalData.clrBarShadow);
  rectBtn.top = rectCombo.top;
  rectBtn.right = rectCombo.right;
  rectBtn.bottom = rectCombo.bottom;
  rectBtn.left = rectCombo.top - rectCombo.bottom + rectCombo.right + 2;
  InflateRect(lprc: &rectBtn, dx: -1, dy: -1);
  Instance = CMFCVisualManager::GetInstance();
  ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, _DWORD, _DWORD, _DWORD, CMFCToolBarComboBoxButton *))Instance->OnDrawComboDropButton)(
    a1: Instance,
    a2: pDC,
    a3: rectBtn.left,
    a4: rectBtn.top,
    a5: rectBtn.right,
    a6: rectBtn.bottom,
    a7: 0,
    a8: 0,
    a9: 0,
    a10: this);
  return rect->right - rect->left;
}

//------------------------------------------------------------------------------
// Address: 0x1040D894
// Name: public: virtual class CComboBox __near * CMFCToolBarComboBoxButton::CreateCombo(class CWnd __near *,class CRect const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CComboBox *__thiscall CMFCToolBarComboBoxButton::CreateCombo(
        CMFCToolBarComboBoxButton *this,
        CWnd *pWndParent,
        const CRect *rect)
{
  CWnd *v4; // eax
  CWnd *v5; // esi

  v4 = (CWnd *)operator new(nSize: 0x74u);
  v5 = v4;
  if ( v4 != nullptr )
  {
    CWnd::CWnd(this: v4);
    v5->__vftable = (CWnd_vtbl *)&CComboBox::`vftable';
  }
  else
  {
    v5 = nullptr;
  }
  if ( ((int (__thiscall *)(CWnd *, unsigned int, const CRect *, CWnd *, unsigned int))v5->__vftable[1].GetRuntimeClass)(
         a1: v5,
         a2: this->m_dwStyle,
         a3: rect,
         a4: pWndParent,
         a5: this->m_nID) != 0 )
    return (CComboBox *)v5;
  ((void (__thiscall *)(CWnd *, int))v5->dtr_CObject)(a1: v5, a2: 1);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1040D900
// Name: public: virtual void CMFCToolBarComboBoxButton::OnShow(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarComboBoxButton::OnShow(CMFCToolBarComboBoxButton *this, int bShow)
{
  CComboBox *m_pWndCombo; // ecx
  CEdit *m_pWndEdit; // ecx

  m_pWndCombo = this->m_pWndCombo;
  if ( m_pWndCombo != nullptr && m_pWndCombo->m_hWnd != nullptr )
  {
    if ( bShow != 0 && this->m_bHorz != 0 )
    {
      this->OnMove(this);
      CWnd::ShowWindow(this: this->m_pWndCombo, nCmdShow: CMFCToolBarComboBoxButton::m_bFlat != 0 ? 0 : 4);
    }
    else
    {
      CWnd::ShowWindow(this: m_pWndCombo, nCmdShow: 0);
    }
  }
  m_pWndEdit = this->m_pWndEdit;
  if ( m_pWndEdit != nullptr && m_pWndEdit->m_hWnd != nullptr )
  {
    if ( bShow != 0 && this->m_bHorz != 0 )
      CWnd::ShowWindow(this: m_pWndEdit, nCmdShow: 4);
    else
      CWnd::ShowWindow(this: m_pWndEdit, nCmdShow: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040D972
// Name: public: virtual void CMFCToolBarComboBoxButton::SetStyle(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarComboBoxButton::SetStyle(CMFCToolBarComboBoxButton *this, unsigned int nStyle)
{
  CComboBox *m_pWndCombo; // ecx
  CEdit *m_pWndEdit; // ecx
  BOOL bDisabled; // [esp+14h] [ebp+8h]

  this->m_nStyle = nStyle;
  bDisabled = CMFCToolBar::m_bCustomizeMode != 0 || this->IsEditable(this) == 0 || (this->m_nStyle & 0x40000) != 0;
  m_pWndCombo = this->m_pWndCombo;
  if ( m_pWndCombo != nullptr && m_pWndCombo->m_hWnd != nullptr )
  {
    CWnd::EnableWindow(this: m_pWndCombo, bEnable: !bDisabled);
    RedrawWindow(hWnd: this->m_pWndCombo->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
  m_pWndEdit = this->m_pWndEdit;
  if ( m_pWndEdit != nullptr && m_pWndEdit->m_hWnd != nullptr )
  {
    CWnd::EnableWindow(this: m_pWndEdit, bEnable: !bDisabled);
    RedrawWindow(hWnd: this->m_pWndEdit->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040DA18
// Name: public: virtual int CMFCToolBarComboBoxButton::HasFocus(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCToolBarComboBoxButton::HasFocus(CMFCToolBarComboBoxButton *this)
{
  HWND Focus; // eax
  HWND v4; // edi
  CComboBox *m_pWndCombo; // eax
  HWND v6; // ecx
  CEdit *m_pWndEdit; // esi

  if ( this->m_pWndCombo == nullptr )
    return false;
  Focus = GetFocus();
  v4 = (HWND)CWnd::FromHandle(hWnd: Focus);
  if ( SendMessageA(hWnd: this->m_pWndCombo->m_hWnd, Msg: 0x157u, wParam: 0, lParam: 0) != 0 )
    return true;
  m_pWndCombo = this->m_pWndCombo;
  if ( v4 == (HWND)m_pWndCombo )
    return true;
  v6 = v4 != nullptr ? *((HWND *)v4 + 8) : nullptr;
  if ( IsChild(hWndParent: m_pWndCombo->m_hWnd, hWnd: v6) )
    return true;
  m_pWndEdit = this->m_pWndEdit;
  if ( m_pWndEdit == nullptr )
    return false;
  if ( v4 == (HWND)m_pWndEdit )
    return true;
  if ( v4 != nullptr )
    v4 = *((HWND *)v4 + 8);
  return IsChild(hWndParent: m_pWndEdit->m_hWnd, hWnd: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1040DAA4
// Name: public: CMFCToolBarComboBoxEdit::CMFCToolBarComboBoxEdit(class CMFCToolBarComboBoxButton __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarComboBoxEdit *__thiscall CMFCToolBarComboBoxEdit::CMFCToolBarComboBoxEdit(
        CMFCToolBarComboBoxEdit *this,
        CMFCToolBarComboBoxButton *combo)
{
  CWnd::CWnd(this);
  this->m_bTracked = 0;
  this->m_combo = combo;
  this->__vftable = (CMFCToolBarComboBoxEdit_vtbl *)&CMFCToolBarComboBoxEdit::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1040DAEF
// Name: protected: void CMFCToolBarComboBoxEdit::OnSetFocus(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarComboBoxEdit::OnSetFocus(CMFCToolBarComboBoxEdit *this, CWnd *pOldWnd)
{
  CWnd::OnSetFocus(this, __formal: pOldWnd);
  CMFCToolBarComboBoxButton::SetHotEdit(this: this->m_combo, bHot: 1);
  this->m_combo->NotifyCommand(this: this->m_combo, a2: 3);
}

//------------------------------------------------------------------------------
// Address: 0x1040DB18
// Name: protected: void CMFCToolBarComboBoxEdit::OnKillFocus(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarComboBoxEdit::OnKillFocus(CMFCToolBarComboBoxEdit *this, CWnd *pNewWnd)
{
  HWND v3; // eax

  CWnd::Default(this);
  v3 = this->m_combo->GetHwnd(this: this->m_combo);
  if ( IsWindow(hWnd: v3) )
  {
    CMFCToolBarComboBoxButton::SetHotEdit(this: this->m_combo, bHot: 0);
    this->m_combo->NotifyCommand(this: this->m_combo, a2: 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040DB4D
// Name: protected: void CMFCToolBarComboBoxEdit::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarComboBoxEdit::OnMouseMove(CMFCToolBarComboBoxEdit *this, unsigned int nFlags, CPoint point)
{
  HWND__ *m_hWnd; // eax
  tagTRACKMOUSEEVENT trackmouseevent; // [esp+4h] [ebp-10h] BYREF

  CWnd::Default(this);
  CMFCToolBarComboBoxButton::SetHotEdit(this: this->m_combo, bHot: 1);
  if ( this->m_bTracked == 0 )
  {
    m_hWnd = this->m_hWnd;
    trackmouseevent.dwHoverTime = -1;
    trackmouseevent.hwndTrack = m_hWnd;
    this->m_bTracked = 1;
    trackmouseevent.cbSize = 16;
    trackmouseevent.dwFlags = 2;
    AFXTrackMouse(ptme: &trackmouseevent);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10424078
// Name: public: void CMFCImagePaintArea::SetColor(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImagePaintArea::SetColor(CMFCImagePaintArea *this, unsigned int color)
{
  CPen *p_m_penDraw; // edi
  HPEN Pen; // eax

  p_m_penDraw = &this->m_penDraw;
  this->m_rgbColor = color;
  if ( this != (CMFCImagePaintArea *)-196 && this->m_penDraw.m_hObject != nullptr )
    CGdiObject::DeleteObject(this: &this->m_penDraw);
  Pen = CreatePen(iStyle: 0, cWidth: 1, color: this->m_rgbColor);
  CGdiObject::Attach(this: p_m_penDraw, hObject: Pen);
}

//------------------------------------------------------------------------------
// Address: 0x104240BF
// Name: protected: void CMFCImagePaintArea::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImagePaintArea::OnLButtonDown(CMFCImagePaintArea *this, unsigned int __formal, CPoint point)
{
  CMFCImagePaintArea::IMAGE_EDIT_MODE m_Mode; // eax
  HWND v5; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-34h]
  CRect rectDraw; // [esp+18h] [ebp-14h] BYREF
  CPoint v8; // 0:^1C.8

  if ( this->m_pBitmap != nullptr )
  {
    m_hWnd = this->m_hWnd;
    memset(&rectDraw, 0, sizeof(rectDraw));
    GetClientRect(hWnd: m_hWnd, lpRect: &rectDraw);
    rectDraw.right = rectDraw.left + this->m_sizeImage.cx * this->m_sizeCell.cx;
    rectDraw.bottom = rectDraw.top + this->m_sizeImage.cy * this->m_sizeCell.cy;
    InflateRect(lprc: &rectDraw, dx: -1, dy: -1);
    if ( PtInRect(lprc: &rectDraw, pt: point.tagPOINT) )
    {
      m_Mode = this->m_Mode;
      if ( m_Mode != IMAGE_EDIT_MODE_PEN )
      {
        if ( (unsigned int)(m_Mode - 2) <= 2 )
        {
          CMFCImagePaintArea::ScreenToBitmap(this, &point);
          v8 = point;
          *(CPoint *)&this->m_rectDraw.left = point;
          *(CPoint *)&this->m_rectDraw.right = v8;
        }
      }
      else
      {
        CMFCImagePaintArea::DrawPixel(this, point: point.tagPOINT);
      }
      v5 = SetCapture(hWnd: this->m_hWnd);
      CWnd::FromHandle(hWnd: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104241B0
// Name: public: CMFCImagePaintArea::CMFCImagePaintArea(class CMFCImageEditorDialog __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCImagePaintArea *__thiscall CMFCImagePaintArea::CMFCImagePaintArea(
        CMFCImagePaintArea *this,
        CMFCImageEditorDialog *pParentDlg)
{
  HDC CompatibleDC; // eax
  HPEN Pen; // eax

  CWnd::CWnd(this);
  this->__vftable = (CMFCImagePaintArea_vtbl *)&CMFCImagePaintArea::`vftable';
  this->m_rectParentPreviewArea.left = 0;
  this->m_rectParentPreviewArea.top = 0;
  this->m_rectParentPreviewArea.right = 0;
  this->m_rectParentPreviewArea.bottom = 0;
  CDC::CDC(this: &this->m_memDC);
  this->m_sizeImage.cx = 0;
  this->m_sizeImage.cy = 0;
  this->m_sizeCell.cx = 0;
  this->m_sizeCell.cy = 0;
  this->m_penDraw.m_hObject = nullptr;
  this->m_penDraw.__vftable = (CPen_vtbl *)&CPen::`vftable';
  this->m_penStretch.m_hObject = nullptr;
  this->m_penStretch.__vftable = (CPen_vtbl *)&CPen::`vftable';
  this->m_rectDraw.left = 0;
  this->m_rectDraw.top = 0;
  this->m_rectDraw.right = 0;
  this->m_rectDraw.bottom = 0;
  if ( pParentDlg == nullptr )
    AfxThrowInvalidArgException();
  this->m_pParentDlg = pParentDlg;
  this->m_sizeImage.cx = 0;
  this->m_sizeImage.cy = 0;
  this->m_pBitmap = nullptr;
  this->m_rgbColor = 0;
  SetRectEmpty(lprc: &this->m_rectParentPreviewArea);
  CompatibleDC = CreateCompatibleDC(hdc: nullptr);
  CDC::Attach(this: &this->m_memDC, hDC: CompatibleDC);
  this->m_Mode = IMAGE_EDIT_MODE_PEN;
  SetRectEmpty(lprc: &this->m_rectDraw);
  Pen = CreatePen(iStyle: 0, cWidth: 1, color: this->m_rgbColor);
  CGdiObject::Attach(this: &this->m_penDraw, hObject: Pen);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104242B5
// Name: public: virtual CMFCImagePaintArea::~CMFCImagePaintArea(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImagePaintArea::~CMFCImagePaintArea(CMFCImagePaintArea *this)
{
  this->__vftable = (CMFCImagePaintArea_vtbl *)&CMFCImagePaintArea::`vftable';
  DestroyCursor(hCursor: this->m_hcurPen);
  DestroyCursor(hCursor: this->m_hcurFill);
  DestroyCursor(hCursor: this->m_hcurLine);
  DestroyCursor(hCursor: this->m_hcurRect);
  DestroyCursor(hCursor: this->m_hcurEllipse);
  DestroyCursor(hCursor: this->m_hcurColor);
  this->m_penStretch.__vftable = (CPen_vtbl *)&CPen::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_penStretch);
  this->m_penDraw.__vftable = (CPen_vtbl *)&CPen::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_penDraw);
  CDC::~CDC(this: &this->m_memDC);
  CButton::~CButton(this);
}

//------------------------------------------------------------------------------
// Address: 0x1042434C
// Name: protected: virtual void CMFCImagePaintArea::DrawItem(struct tagDRAWITEMSTRUCT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImagePaintArea::DrawItem(CMFCImagePaintArea *this, tagDRAWITEMSTRUCT *lpDIS)
{
  int v3; // eax
  int cx; // eax
  int i; // esi
  int cy; // eax
  int j; // esi
  CBitmap *m_pBitmap; // eax
  COLORREF Pixel; // eax
  int v10; // edx
  int v11; // esi
  void *v12; // eax
  unsigned int clr; // [esp+10h] [ebp-60h]
  CPoint result; // [esp+14h] [ebp-5Ch] BYREF
  CPen v15; // [esp+1Ch] [ebp-54h] BYREF
  int y; // [esp+24h] [ebp-4Ch]
  CFont *pFont; // [esp+28h] [ebp-48h]
  CDC *v18; // [esp+2Ch] [ebp-44h]
  tagRECT Rect; // [esp+30h] [ebp-40h] BYREF
  tagRECT rc; // [esp+40h] [ebp-30h] BYREF
  tagRECT rcDst; // [esp+50h] [ebp-20h] BYREF
  int v22; // [esp+6Ch] [ebp-4h]

  v18 = CDC::FromHandle(hDC: lpDIS->hDC);
  CopyRect(lprcDst: &rcDst, lprcSrc: &lpDIS->rcItem);
  FillRect(hDC: v18->m_hDC, lprc: &rcDst, hbr: (HBRUSH)afxGlobalData.brBtnFace.m_hObject);
  InflateRect(lprc: &rcDst, dx: -1, dy: -1);
  v3 = rcDst.left + this->m_sizeCell.cx * this->m_sizeImage.cx;
  Rect.left = rcDst.left;
  Rect.top = rcDst.top;
  Rect.bottom = rcDst.bottom;
  Rect.right = v3;
  Rect.bottom = rcDst.top + this->m_sizeCell.cy * this->m_sizeImage.cy;
  rcDst.right = v3;
  rcDst.bottom = Rect.bottom;
  InflateRect(lprc: &rcDst, dx: 1, dy: 1);
  CDC::Draw3dRect(
    this: v18,
    lpRect: &Rect,
    clrTopLeft: afxGlobalData.clrBtnDkShadow,
    clrBottomRight: afxGlobalData.clrBtnHilite);
  CPen::CPen(this: &v15, nPenStyle: 0, nWidth: 1, crColor: afxGlobalData.clrBtnShadow);
  v22 = 0;
  pFont = CDC::SelectObject(this: v18, pFont: (CFont *)&v15);
  cx = this->m_sizeCell.cx;
  for ( i = cx + Rect.left; i <= Rect.right - cx; i += cx )
  {
    CDC::MoveTo(this: v18, &result, x: i, y: Rect.top + 1);
    CDC::LineTo(this: v18, x: i, y: Rect.bottom - 1);
    cx = this->m_sizeCell.cx;
  }
  cy = this->m_sizeCell.cy;
  for ( j = cy + Rect.top; j <= Rect.bottom - cy; j += cy )
  {
    CDC::MoveTo(this: v18, &result, x: Rect.left + 1, y: j);
    CDC::LineTo(this: v18, x: Rect.right - 1, y: j);
    cy = this->m_sizeCell.cy;
  }
  CDC::SelectObject(this: v18, pFont);
  m_pBitmap = this->m_pBitmap;
  if ( m_pBitmap != nullptr )
  {
    result.y = (int)CDC::SelectGdiObject(hDC: this->m_memDC.m_hDC, h: m_pBitmap->m_hObject);
    for ( pFont = nullptr; (int)pFont < this->m_sizeImage.cx; pFont = (CFont *)((char *)pFont + 1) )
    {
      for ( y = 0; y < this->m_sizeImage.cy; ++y )
      {
        Pixel = GetPixel(hdc: this->m_memDC.m_hDC, x: (int)pFont, y);
        clr = CMFCToolBarImages::MapFromSysColor(color: Pixel, bUseRGBQUAD: 0);
        if ( clr != -1 )
        {
          v10 = this->m_sizeCell.cx;
          v11 = Rect.top + y * this->m_sizeCell.cy + this->m_sizeCell.cy;
          rc.top = Rect.top + y * this->m_sizeCell.cy;
          rc.left = Rect.left + (_DWORD)pFont * v10;
          rc.right = rc.left + v10;
          rc.bottom = v11;
          InflateRect(lprc: &rc, dx: -1, dy: -1);
          CDC::FillSolidRect(this: v18, lpRect: &rc, clr);
        }
      }
    }
    if ( result.y != 0 )
      v12 = *(void **)(result.y + 4);
    else
      v12 = nullptr;
    CDC::SelectGdiObject(hDC: this->m_memDC.m_hDC, h: v12);
  }
  v22 = -1;
  v15.__vftable = (CPen_vtbl *)&CPen::`vftable';
  CGdiObject::~CGdiObject(this: &v15);
}

//------------------------------------------------------------------------------
// Address: 0x104245A0
// Name: protected: void CMFCImagePaintArea::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImagePaintArea::OnMouseMove(CMFCImagePaintArea *this, char nFlags, tagPOINT point)
{
  int x; // eax
  int y; // eax
  CMFCImagePaintArea::IMAGE_EDIT_MODE m_Mode; // eax
  int v7; // eax
  CRect *p_m_rectDraw; // esi
  HRGN v9; // eax
  int *v10; // esi
  int *v11; // esi
  int *v12; // esi
  int *v13; // esi
  int *p_left; // esi
  int *v15; // esi
  HWND__ *m_hWnd; // [esp-8h] [ebp-94h]
  CPoint v17; // [esp+10h] [ebp-7Ch] BYREF
  CPoint result; // [esp+18h] [ebp-74h] BYREF
  CFont *pFont; // [esp+20h] [ebp-6Ch]
  CFont *v20; // [esp+24h] [ebp-68h]
  int nDrawMode; // [esp+28h] [ebp-64h]
  CGdiObject v22; // [esp+2Ch] [ebp-60h] BYREF
  CClientDC v23; // [esp+34h] [ebp-58h] BYREF
  CRect *v24; // [esp+48h] [ebp-44h]
  tagRECT rc; // [esp+4Ch] [ebp-40h] BYREF
  tagRECT Rect; // [esp+5Ch] [ebp-30h] BYREF
  CRect rect; // [esp+6Ch] [ebp-20h] BYREF
  int v28; // [esp+88h] [ebp-4h]

  if ( (nFlags & 1) != 0 )
  {
    m_hWnd = this->m_hWnd;
    memset(&Rect, 0, sizeof(Rect));
    GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
    x = point.x;
    if ( point.x <= Rect.left )
      x = Rect.left;
    if ( x >= Rect.right )
    {
      point.x = Rect.right;
    }
    else if ( point.x <= Rect.left )
    {
      point.x = Rect.left;
    }
    y = point.y;
    if ( point.y <= Rect.top )
      y = Rect.top;
    if ( y >= Rect.bottom )
    {
      point.y = Rect.bottom;
    }
    else if ( point.y <= Rect.top )
    {
      point.y = Rect.top;
    }
    m_Mode = this->m_Mode;
    if ( m_Mode != IMAGE_EDIT_MODE_PEN )
    {
      if ( m_Mode == IMAGE_EDIT_MODE_LINE || m_Mode == IMAGE_EDIT_MODE_RECT || m_Mode == IMAGE_EDIT_MODE_ELLIPSE )
      {
        v7 = this->m_sizeImage.cx * this->m_sizeCell.cx;
        rc.left = Rect.left;
        rc.top = Rect.top;
        rc.bottom = Rect.bottom;
        rc.right = Rect.left + v7;
        rc.bottom = Rect.top + this->m_sizeImage.cy * this->m_sizeCell.cy;
        InflateRect(lprc: &rc, dx: -1, dy: -1);
        p_m_rectDraw = &this->m_rectDraw;
        v24 = &this->m_rectDraw;
        if ( !EqualRect(lprc1: &this->m_rectDraw, lprc2: &rc) )
        {
          v22.m_hObject = nullptr;
          v22.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
          v28 = 0;
          v9 = CreateRectRgnIndirect(lprect: &rc);
          CGdiObject::Attach(this: &v22, hObject: v9);
          CClientDC::CClientDC(this: &v23, pWnd: this);
          LOBYTE(v28) = 1;
          CDC::SelectObject(this: &v23, pRgn: (CRgn *)&v22);
          v20 = CDC::SelectObject(this: &v23, pFont: (CFont *)&this->m_penStretch);
          pFont = (CFont *)CDC::SelectStockObject(this: &v23, nIndex: 5);
          nDrawMode = CDC::SetROP2(this: &v23, nDrawMode: 6);
          switch ( this->m_Mode )
          {
            case IMAGE_EDIT_MODE_LINE:
              rect.left = p_m_rectDraw->left;
              rect.top = this->m_rectDraw.top;
              rect.right = this->m_rectDraw.right;
              rect.bottom = this->m_rectDraw.bottom;
              CMFCImagePaintArea::BitmapToClient(this, &rect);
              p_left = &v24->left;
              if ( v24->right != v24->left || v24->bottom != v24->top )
              {
                CDC::MoveTo(this: &v23, &result, x: rect.left, y: rect.top);
                CDC::LineTo(this: &v23, x: rect.right, y: rect.bottom);
              }
              CMFCImagePaintArea::ScreenToBitmap(this, (CPoint *)&point);
              *(CPoint *)&this->m_rectDraw.right = (CPoint)point;
              rect.left = *p_left;
              v15 = p_left + 1;
              rect.top = *v15++;
              rect.right = *v15;
              rect.bottom = v15[1];
              CMFCImagePaintArea::BitmapToClient(this, &rect);
              if ( v24->right != v24->left || v24->bottom != v24->top )
              {
                CDC::MoveTo(this: &v23, result: &v17, x: rect.left, y: rect.top);
                CDC::LineTo(this: &v23, x: rect.right, y: rect.bottom);
              }
              break;
            case IMAGE_EDIT_MODE_RECT:
              rect.left = p_m_rectDraw->left;
              rect.top = this->m_rectDraw.top;
              rect.right = this->m_rectDraw.right;
              rect.bottom = this->m_rectDraw.bottom;
              CMFCImagePaintArea::BitmapToClient(this, &rect);
              v12 = &v24->left;
              if ( v24->right != v24->left || v24->bottom != v24->top )
                Rectangle(hdc: v23.m_hDC, left: rect.left, top: rect.top, right: rect.right, bottom: rect.bottom);
              CMFCImagePaintArea::ScreenToBitmap(this, (CPoint *)&point);
              *(CPoint *)&this->m_rectDraw.right = (CPoint)point;
              rect.left = *v12;
              v13 = v12 + 1;
              rect.top = *v13++;
              rect.right = *v13;
              rect.bottom = v13[1];
              CMFCImagePaintArea::BitmapToClient(this, &rect);
              if ( v24->right != v24->left || v24->bottom != v24->top )
                Rectangle(hdc: v23.m_hDC, left: rect.left, top: rect.top, right: rect.right, bottom: rect.bottom);
              break;
            case IMAGE_EDIT_MODE_ELLIPSE:
              rect.left = p_m_rectDraw->left;
              rect.top = this->m_rectDraw.top;
              rect.right = this->m_rectDraw.right;
              rect.bottom = this->m_rectDraw.bottom;
              CMFCImagePaintArea::BitmapToClient(this, &rect);
              v10 = &v24->left;
              if ( v24->right != v24->left || v24->bottom != v24->top )
                Ellipse(hdc: v23.m_hDC, left: rect.left, top: rect.top, right: rect.right, bottom: rect.bottom);
              CMFCImagePaintArea::ScreenToBitmap(this, (CPoint *)&point);
              *(CPoint *)&this->m_rectDraw.right = (CPoint)point;
              rect.left = *v10;
              v11 = v10 + 1;
              rect.top = *v11++;
              rect.right = *v11;
              rect.bottom = v11[1];
              CMFCImagePaintArea::BitmapToClient(this, &rect);
              if ( v24->right != v24->left || v24->bottom != v24->top )
                Ellipse(hdc: v23.m_hDC, left: rect.left, top: rect.top, right: rect.right, bottom: rect.bottom);
              break;
            default:
              break;
          }
          CDC::SetROP2(this: &v23, nDrawMode);
          CDC::SelectObject(this: &v23, pFont);
          CDC::SelectObject(this: &v23, pFont: v20);
          CDC::SelectClipRgn(this: &v23, pRgn: nullptr);
          LOBYTE(v28) = 0;
          CClientDC::~CClientDC(this: &v23);
          v28 = -1;
          v22.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
          CGdiObject::~CGdiObject(this: &v22);
        }
      }
    }
    else
    {
      CMFCImagePaintArea::DrawPixel(this, point);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10424944
// Name: protected: void CMFCImagePaintArea::FloodFill(class CPoint const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImagePaintArea::FloodFill(CMFCImagePaintArea *this, const CPoint *point)
{
  CBitmap *m_pBitmap; // eax
  CBitmap *v4; // eax
  CBrush *v5; // eax
  COLORREF Pixel; // eax
  void *m_hObject; // eax
  HWND Parent; // eax
  CWnd *v9; // eax
  unsigned int m_rgbColor; // [esp-4h] [ebp-30h]
  int y; // [esp-4h] [ebp-30h]
  CBrush br; // [esp+10h] [ebp-1Ch] BYREF
  CBrush *pBrOld; // [esp+18h] [ebp-14h]
  CBitmap *pOldBitmap; // [esp+1Ch] [ebp-10h]
  int v15; // [esp+28h] [ebp-4h]

  m_pBitmap = this->m_pBitmap;
  if ( m_pBitmap == nullptr )
    AfxThrowInvalidArgException();
  v4 = (CBitmap *)CDC::SelectGdiObject(hDC: this->m_memDC.m_hDC, h: m_pBitmap->m_hObject);
  m_rgbColor = this->m_rgbColor;
  pOldBitmap = v4;
  CBrush::CBrush(this: &br, crColor: m_rgbColor);
  v15 = 0;
  v5 = (CBrush *)CDC::SelectObject(this: &this->m_memDC, pFont: (CFont *)&br);
  y = point->y;
  pBrOld = v5;
  Pixel = GetPixel(hdc: this->m_memDC.m_hDC, x: point->x, y);
  ExtFloodFill(hdc: this->m_memDC.m_hDC, x: point->x, y: point->y, color: Pixel, type: 1u);
  m_hObject = pOldBitmap;
  if ( pOldBitmap != nullptr )
    m_hObject = pOldBitmap->m_hObject;
  CDC::SelectGdiObject(hDC: this->m_memDC.m_hDC, h: m_hObject);
  CDC::SelectObject(this: &this->m_memDC, pFont: (CFont *)pBrOld);
  InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
  UpdateWindow(hWnd: this->m_hWnd);
  Parent = GetParent(hWnd: this->m_hWnd);
  v9 = CWnd::FromHandle(hWnd: Parent);
  InvalidateRect(hWnd: v9->m_hWnd, lpRect: &this->m_rectParentPreviewArea, bErase: true);
  v15 = -1;
  br.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  CGdiObject::~CGdiObject(this: &br);
}

//------------------------------------------------------------------------------
// Address: 0x10424A5F
// Name: protected: void CMFCImagePaintArea::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCImagePaintArea::OnLButtonUp(CMFCImagePaintArea *this, unsigned int __formal, CPoint point)
{
  HWND Capture; // eax
  CMFCImagePaintArea::IMAGE_EDIT_MODE m_Mode; // ebx
  int top; // edx
  int bottom; // edi
  int left; // ecx
  int right; // edx
  CBitmap *v10; // eax
  CGdiObject *v11; // edi
  COLORREF Pixel; // ebx
  CBitmap *v13; // eax
  void *v14; // eax
  CBitmap *m_hObject; // eax
  void *v16; // eax
  CBitmap *m_pBitmap; // eax
  CGdiObject *v18; // ebx
  CBitmap *v19; // eax
  HWND Parent; // eax
  CWnd *v21; // eax
  int v22; // [esp-4h] [ebp-24h]
  CPoint result; // [esp+Ch] [ebp-14h] BYREF
  CBitmap *pOldBitmap; // [esp+14h] [ebp-Ch]
  CPen *pOldPen; // [esp+18h] [ebp-8h]
  CBrush *pOldBrush; // [esp+1Ch] [ebp-4h]

  Capture = GetCapture();
  if ( CWnd::FromHandle(hWnd: Capture) == this )
    ReleaseCapture();
  m_Mode = this->m_Mode;
  if ( m_Mode == IMAGE_EDIT_MODE_RECT || m_Mode == IMAGE_EDIT_MODE_ELLIPSE )
  {
    if ( this->m_rectDraw.bottom != this->m_rectDraw.top )
    {
      top = this->m_rectDraw.top;
      bottom = this->m_rectDraw.bottom;
      if ( top >= bottom )
        this->m_rectDraw.top = top + 1;
      else
        this->m_rectDraw.bottom = bottom + 1;
    }
    if ( this->m_rectDraw.right != this->m_rectDraw.left )
    {
      left = this->m_rectDraw.left;
      right = this->m_rectDraw.right;
      if ( left >= right )
        this->m_rectDraw.left = left + 1;
      else
        this->m_rectDraw.right = right + 1;
    }
  }
  switch ( m_Mode )
  {
    case IMAGE_EDIT_MODE_PEN:
      goto LABEL_48;
    case IMAGE_EDIT_MODE_FILL:
      CMFCImagePaintArea::ScreenToBitmap(this, &point);
      CMFCImagePaintArea::FloodFill(this, &point);
      break;
    case IMAGE_EDIT_MODE_LINE:
      if ( this->m_rectDraw.bottom != this->m_rectDraw.top || this->m_rectDraw.right != this->m_rectDraw.left )
      {
        m_pBitmap = this->m_pBitmap;
        if ( m_pBitmap != nullptr )
          m_pBitmap = (CBitmap *)m_pBitmap->m_hObject;
        v18 = CDC::SelectGdiObject(hDC: this->m_memDC.m_hDC, h: m_pBitmap);
        v19 = (CBitmap *)CDC::SelectObject(this: &this->m_memDC, pFont: (CFont *)&this->m_penDraw);
        v22 = this->m_rectDraw.top;
        pOldBitmap = v19;
        CDC::MoveTo(this: &this->m_memDC, &result, x: this->m_rectDraw.left, y: v22);
        CDC::LineTo(this: &this->m_memDC, x: this->m_rectDraw.right, y: this->m_rectDraw.bottom);
        CMFCImagePaintArea::DrawPixel(this, point: point.tagPOINT);
        if ( v18 != nullptr )
          v18 = (CGdiObject *)v18->m_hObject;
        CDC::SelectGdiObject(hDC: this->m_memDC.m_hDC, h: v18);
        CDC::SelectObject(this: &this->m_memDC, pFont: (CFont *)pOldBitmap);
        goto LABEL_46;
      }
      goto LABEL_48;
    case IMAGE_EDIT_MODE_RECT:
      if ( this->m_rectDraw.bottom != this->m_rectDraw.top || this->m_rectDraw.right != this->m_rectDraw.left )
      {
        m_hObject = this->m_pBitmap;
        if ( m_hObject != nullptr )
          m_hObject = (CBitmap *)m_hObject->m_hObject;
        pOldBitmap = (CBitmap *)CDC::SelectGdiObject(hDC: this->m_memDC.m_hDC, h: m_hObject);
        pOldPen = (CPen *)CDC::SelectObject(this: &this->m_memDC, pFont: (CFont *)&this->m_penDraw);
        pOldBrush = (CBrush *)this->m_memDC.SelectStockObject(this: &this->m_memDC, a2: 5);
        CDC::Rectangle(this: &this->m_memDC, lpRect: &this->m_rectDraw);
        v16 = pOldBitmap;
        if ( pOldBitmap != nullptr )
          v16 = pOldBitmap->m_hObject;
        CDC::SelectGdiObject(hDC: this->m_memDC.m_hDC, h: v16);
        CDC::SelectObject(this: &this->m_memDC, pFont: (CFont *)pOldPen);
        CDC::SelectObject(this: &this->m_memDC, pFont: (CFont *)pOldBrush);
        goto LABEL_46;
      }
LABEL_48:
      CMFCImagePaintArea::DrawPixel(this, point: point.tagPOINT);
      break;
    case IMAGE_EDIT_MODE_ELLIPSE:
      if ( this->m_rectDraw.bottom != this->m_rectDraw.top || this->m_rectDraw.right != this->m_rectDraw.left )
      {
        v13 = this->m_pBitmap;
        if ( v13 != nullptr )
          v13 = (CBitmap *)v13->m_hObject;
        pOldBrush = (CBrush *)CDC::SelectGdiObject(hDC: this->m_memDC.m_hDC, h: v13);
        pOldPen = (CPen *)CDC::SelectObject(this: &this->m_memDC, pFont: (CFont *)&this->m_penDraw);
        pOldBitmap = (CBitmap *)this->m_memDC.SelectStockObject(this: &this->m_memDC, a2: 5);
        CDC::Ellipse(this: &this->m_memDC, lpRect: &this->m_rectDraw);
        v14 = pOldBrush;
        if ( pOldBrush != nullptr )
          v14 = pOldBrush->m_hObject;
        CDC::SelectGdiObject(hDC: this->m_memDC.m_hDC, h: v14);
        CDC::SelectObject(this: &this->m_memDC, pFont: (CFont *)pOldPen);
        CDC::SelectObject(this: &this->m_memDC, pFont: (CFont *)pOldBitmap);
LABEL_46:
        InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
        UpdateWindow(hWnd: this->m_hWnd);
        Parent = GetParent(hWnd: this->m_hWnd);
        v21 = CWnd::FromHandle(hWnd: Parent);
        InvalidateRect(hWnd: v21->m_hWnd, lpRect: &this->m_rectParentPreviewArea, bErase: true);
        break;
      }
      goto LABEL_48;
    case IMAGE_EDIT_MODE_COLOR:
      CMFCImagePaintArea::ScreenToBitmap(this, &point);
      v10 = this->m_pBitmap;
      if ( v10 != nullptr )
        v10 = (CBitmap *)v10->m_hObject;
      v11 = CDC::SelectGdiObject(hDC: this->m_memDC.m_hDC, h: v10);
      Pixel = GetPixel(hdc: this->m_memDC.m_hDC, x: point.x, y: point.y);
      if ( v11 != nullptr )
        v11 = (CGdiObject *)v11->m_hObject;
      CDC::SelectGdiObject(hDC: this->m_memDC.m_hDC, h: v11);
      CMFCImageEditorDialog::OnPickColor(this: this->m_pParentDlg, color: Pixel);
      break;
    default:
      break;
  }
  SetRectEmpty(lprc: &this->m_rectDraw);
}

//------------------------------------------------------------------------------
// Address: 0x10424DCA
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCImagePaintArea::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCImagePaintArea::GetMessageMap(CMFCImagePaintArea *this)
{
  return (const AFX_MSGMAP *)&off_1069162C;
}

//------------------------------------------------------------------------------
// Address: 0x10433D08
// Name: public: CMFCToolBarsCommandsListBox::CMFCToolBarsCommandsListBox(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarsCommandsListBox *__thiscall CMFCToolBarsCommandsListBox::CMFCToolBarsCommandsListBox(
        CMFCToolBarsCommandsListBox *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CMFCToolBarsCommandsListBox_vtbl *)&CMFCToolBarsCommandsListBox::`vftable';
  this->m_sizeButton.cx = 0;
  this->m_sizeButton.cy = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10433D4B
// Name: protected: void CMFCToolBarsCommandsListBox::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsCommandsListBox::OnLButtonDown(
        CMFCToolBarsCommandsListBox *this,
        WPARAM nFlags,
        POINT point)
{
  WPARAM v4; // eax
  int *v5; // esi
  int v6; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  HCURSOR CursorW; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-78h]
  COleDataSource v10; // [esp+10h] [ebp-58h] BYREF
  WPARAM v11; // [esp+44h] [ebp-24h]
  tagRECT lParam; // [esp+48h] [ebp-20h] BYREF
  int v13; // [esp+64h] [ebp-4h]

  CWnd::Default(this);
  v4 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  v11 = v4;
  if ( v4 != -1 )
  {
    m_hWnd = this->m_hWnd;
    memset(&lParam, 0, sizeof(lParam));
    SendMessageA(hWnd: m_hWnd, Msg: 0x198u, wParam: v4, (LPARAM)&lParam);
    if ( PtInRect(lprc: &lParam, pt: point) )
    {
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x202u, wParam: nFlags, lParam: LOWORD(point.x) | (LOWORD(point.y) << 16));
      v5 = (int *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x199u, wParam: v11, lParam: 0);
      COleDataSource::COleDataSource(this: &v10);
      v6 = *v5;
      v13 = 0;
      v5[7] = 1;
      (*(void (__thiscall **)(int *, COleDataSource *))(v6 + 12))(a1: v5, a2: &v10);
      v5[7] = 0;
      AfxGetModuleState();
      ModuleState = AfxGetModuleState();
      CursorW = LoadCursorW(hInstance: ModuleState->m_hCurrentResourceHandle, lpCursorName: (LPCWSTR)0x3F05);
      SetCursor(hCursor: CursorW);
      COleDataSource::DoDragDrop(
        this: &v10,
        dwEffects: 3u,
        lpRectStartDrag: &lParam,
        pDropSource: &CMFCToolBar::m_DropSource);
      v13 = -1;
      COleDataSource::~COleDataSource(this: &v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10433E43
// Name: protected: int CMFCToolBarsCommandsListBox::OnEraseBkgnd(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarsCommandsListBox::OnEraseBkgnd(CMFCToolBarsCommandsListBox *this, CDC *pDC)
{
  CMFCVisualManager *Instance; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-28h]
  CRect rectClient; // [esp+Ch] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
  Instance = CMFCVisualManager::GetInstance();
  ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, _DWORD))Instance->OnFillCommandsListBackground)(
    a1: Instance,
    a2: pDC,
    a3: rectClient.left,
    a4: rectClient.top,
    a5: rectClient.right,
    a6: rectClient.bottom,
    a7: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10433EA9
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCToolBarsCommandsListBox::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCToolBarsCommandsListBox::GetMessageMap(CMFCToolBarsCommandsListBox *this)
{
  return (const AFX_MSGMAP *)&off_106957C0;
}

//------------------------------------------------------------------------------
// Address: 0x10433EAF
// Name: public: virtual void CMFCToolBarsCommandsListBox::DrawItem(struct tagDRAWITEMSTRUCT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsCommandsListBox::DrawItem(CMFCToolBarsCommandsListBox *this, tagDRAWITEMSTRUCT *lpDIS)
{
  WPARAM itemID; // eax
  LRESULT v4; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v5; // esi
  CMFCVisualManager *Instance; // eax
  unsigned int itemState; // ebx
  int v8; // eax
  ATL::CSimpleStringT<char,0> *v9; // [esp+10h] [ebp-30h]
  LRESULT v10; // [esp+14h] [ebp-2Ch]
  CDC *v11; // [esp+18h] [ebp-28h]
  ATL::CSimpleStringT<char,0> strSrc; // [esp+1Ch] [ebp-24h] BYREF
  tagRECT rcDst; // [esp+20h] [ebp-20h] BYREF
  int v14; // [esp+3Ch] [ebp-4h]

  v11 = CDC::FromHandle(hDC: lpDIS->hDC);
  CopyRect(lprcDst: &rcDst, lprcSrc: &lpDIS->rcItem);
  itemID = lpDIS->itemID;
  if ( itemID != -1 )
  {
    v4 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x199u, wParam: itemID, lParam: 0);
    v5 = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)(v4 + 44);
    v10 = v4;
    v9 = (ATL::CSimpleStringT<char,0> *)(v4 + 44);
    strSrc.m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)(*(_DWORD *)(v4 + 44)
                                                                                                 - 16))[1];
    v14 = 0;
    CListBox::GetText(this, nIndex: lpDIS->itemID, rString: v5);
    Instance = CMFCVisualManager::GetInstance();
    ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, _DWORD))Instance->OnFillCommandsListBackground)(
      a1: Instance,
      a2: v11,
      a3: rcDst.left,
      a4: rcDst.top,
      a5: rcDst.right,
      a6: rcDst.bottom,
      a7: 0);
    itemState = lpDIS->itemState;
    v8 = 1;
    if ( (itemState & 1) == 0 || (itemState & 0x10) == 0 )
      v8 = 0;
    (*(void (__thiscall **)(LRESULT, CDC *, tagRECT *, int))(*(_DWORD *)v10 + 108))(
      a1: v10,
      a2: v11,
      a3: &rcDst,
      a4: v8);
    ATL::CSimpleStringT<char,0>::operator=(this: v9, &strSrc);
    ATL::CStringData::Release(this: (ATL::CStringData *)strSrc.m_pszData - 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10433F80
// Name: protected: virtual void CMFCToolBarNameDialog::DoDataExchange(class CDataExchange __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarNameDialog::DoDataExchange(CMFCToolBarNameDialog *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: 1, rControl: &this->m_btnOk);
  DDX_Text(pDX, nIDC: 16516, value: &this->m_strToolbarName);
}

//------------------------------------------------------------------------------
// Address: 0x10433FB2
// Name: protected: void CMFCToolBarNameDialog::OnUpdateToolbarName(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarNameDialog::OnUpdateToolbarName(CMFCToolBarNameDialog *this)
{
  CWnd::UpdateData(this, bSaveAndValidate: 1);
  CWnd::EnableWindow(this: &this->m_btnOk, bEnable: *((_DWORD *)this->m_strToolbarName.m_pszData - 3) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10433FDA
// Name: protected: virtual int CMFCToolBarNameDialog::OnInitDialog(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarNameDialog::OnInitDialog(CMFCToolBarNameDialog *this)
{
  CWnd *MainWnd; // eax

  CDialog::OnInitDialog(this);
  if ( AfxGetMainWnd() != nullptr )
  {
    MainWnd = AfxGetMainWnd();
    if ( (CWnd::GetExStyle(this: MainWnd) & 0x400000) != 0 )
      CWnd::ModifyStyleEx(this, dwRemove: 0, dwAdd: 0x400000u, nFlags: 0);
  }
  CWnd::EnableWindow(this: &this->m_btnOk, bEnable: *((_DWORD *)this->m_strToolbarName.m_pszData - 3) != 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1043402D
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCToolBarNameDialog::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCToolBarNameDialog::GetMessageMap(CMFCToolBarNameDialog *this)
{
  return (const AFX_MSGMAP *)&off_10695810;
}

//------------------------------------------------------------------------------
// Address: 0x10434033
// Name: public: CMFCToolBarNameDialog::CMFCToolBarNameDialog(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarNameDialog *__thiscall CMFCToolBarNameDialog::CMFCToolBarNameDialog(
        CMFCToolBarNameDialog *this,
        CWnd *pParent)
{
  ATL::IAtlStringMgr *StringManager; // eax

  CDialog::CDialog(this, nIDTemplate: 0x3F02u, pParentWnd: pParent);
  this->__vftable = (CMFCToolBarNameDialog_vtbl *)&CMFCToolBarNameDialog::`vftable';
  CWnd::CWnd(this: &this->m_btnOk);
  this->m_btnOk.__vftable = (CButton_vtbl *)&CButton::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strToolbarName, pStringMgr: StringManager);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strToolbarName, pszSrc: &szGroupName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104340C4
// Name: public: virtual CMFCAcceleratorKeyAssignCtrl::~CMFCAcceleratorKeyAssignCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCAcceleratorKeyAssignCtrl::~CMFCAcceleratorKeyAssignCtrl(CMFCAcceleratorKeyAssignCtrl *this)
{
  this->__vftable = (CMFCAcceleratorKeyAssignCtrl_vtbl *)&CMFCAcceleratorKeyAssignCtrl::`vftable';
  CMFCAcceleratorKey::~CMFCAcceleratorKey(this: &this->m_Helper);
  CEdit::~CEdit(this);
}

//------------------------------------------------------------------------------
// Address: 0x104340FB
// Name: public: void CMFCAcceleratorKeyAssignCtrl::ResetKey(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCAcceleratorKeyAssignCtrl::ResetKey(CMFCAcceleratorKeyAssignCtrl *this)
{
  memset(dst: &this->m_Accel.fVirt, value: 0, count: 6u);
  this->m_bIsDefined = 0;
  if ( this->m_hWnd != nullptr )
    CWnd::SetWindowTextA(this, lpszString: &szGroupName);
}

//------------------------------------------------------------------------------
// Address: 0x10434128
// Name: protected: void CMFCAcceleratorKeyAssignCtrl::SetAccelFlag(unsigned char,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCAcceleratorKeyAssignCtrl::SetAccelFlag(
        CMFCAcceleratorKeyAssignCtrl *this,
        unsigned __int8 bFlag,
        int bOn)
{
  if ( bOn != 0 )
    this->m_Accel.fVirt |= bFlag;
  else
    this->m_Accel.fVirt &= ~bFlag;
}

//------------------------------------------------------------------------------
// Address: 0x10434144
// Name: public: CMFCAcceleratorKeyAssignCtrl::CMFCAcceleratorKeyAssignCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCAcceleratorKeyAssignCtrl *__thiscall CMFCAcceleratorKeyAssignCtrl::CMFCAcceleratorKeyAssignCtrl(
        CMFCAcceleratorKeyAssignCtrl *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CMFCAcceleratorKeyAssignCtrl_vtbl *)&CMFCAcceleratorKeyAssignCtrl::`vftable';
  CMFCAcceleratorKey::CMFCAcceleratorKey(this: &this->m_Helper, lpAccel: &this->m_Accel);
  this->m_bIsDefined = 0;
  this->m_bIsFocused = 0;
  CMFCAcceleratorKeyAssignCtrl::ResetKey(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104341B2
// Name: protected: void CMFCAcceleratorKeyAssignCtrl::OnKillFocus(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCAcceleratorKeyAssignCtrl::OnKillFocus(CMFCAcceleratorKeyAssignCtrl *this, CWnd *pNewWnd)
{
  this->m_bIsFocused = 0;
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x104341C1
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCAcceleratorKeyAssignCtrl::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCAcceleratorKeyAssignCtrl::GetMessageMap(CMFCAcceleratorKeyAssignCtrl *this)
{
  return (const AFX_MSGMAP *)&off_10695B3C;
}

//------------------------------------------------------------------------------
// Address: 0x104341C7
// Name: public: virtual int CMFCAcceleratorKeyAssignCtrl::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCAcceleratorKeyAssignCtrl::PreTranslateMessage(CMFCAcceleratorKeyAssignCtrl *this, tagMSG *pMsg)
{
  tagMSG *v3; // edi
  unsigned __int8 fVirt; // al
  int key; // eax
  ATL::IAtlStringMgr *StringManager; // eax
  int bIsKeyPressed; // [esp+10h] [ebp-10h]

  v3 = pMsg;
  bIsKeyPressed = 0;
  if ( pMsg->message != 256 )
  {
    if ( pMsg->message == 257 )
      goto LABEL_13;
    if ( pMsg->message != 260 )
    {
      if ( pMsg->message == 261 )
        goto LABEL_13;
      if ( pMsg->message == 513 || pMsg->message == 516 || pMsg->message == 519 )
      {
        this->m_bIsFocused = 1;
        CWnd::SetFocus(this);
        return 1;
      }
      return CWnd::PreTranslateMessage(this, pMsg: v3);
    }
  }
  bIsKeyPressed = 1;
  if ( this->m_bIsDefined == 0 )
    goto LABEL_14;
  if ( (pMsg->lParam & 0x40000000) == 0 )
    CMFCAcceleratorKeyAssignCtrl::ResetKey(this);
LABEL_13:
  if ( this->m_bIsDefined != 0 )
  {
LABEL_24:
    fVirt = this->m_Accel.fVirt;
    if ( (fVirt & 0x1C) == 0 && (fVirt & 1) != 0 )
    {
      key = this->m_Accel.key;
      switch ( key )
      {
        case 9:
          goto LABEL_31;
        case 27:
          CMFCAcceleratorKeyAssignCtrl::ResetKey(this);
          return 1;
        case 229:
LABEL_31:
          CMFCAcceleratorKeyAssignCtrl::ResetKey(this);
          return CWnd::PreTranslateMessage(this, pMsg: v3);
        default:
          break;
      }
    }
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
      this: (ATL::CSimpleStringT<char,0> *)&pMsg,
      pStringMgr: StringManager);
    CMFCAcceleratorKey::Format(
      this: &this->m_Helper,
      str: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pMsg);
    CWnd::SetWindowTextA(this, lpszString: (const char *)pMsg);
    ATL::CStringData::Release(this: (ATL::CStringData *)&pMsg[-1].lParam);
    return 1;
  }
LABEL_14:
  switch ( v3->wParam )
  {
    case 0x10u:
      CMFCAcceleratorKeyAssignCtrl::SetAccelFlag(this, bFlag: 4u, bOn: bIsKeyPressed);
      break;
    case 0x11u:
      CMFCAcceleratorKeyAssignCtrl::SetAccelFlag(this, bFlag: 8u, bOn: bIsKeyPressed);
      break;
    case 0x12u:
      CMFCAcceleratorKeyAssignCtrl::SetAccelFlag(this, bFlag: 0x10u, bOn: bIsKeyPressed);
      break;
    default:
      if ( this->m_bIsFocused == 0 )
      {
        this->m_bIsFocused = 1;
        return 1;
      }
      this->m_Accel.key = v3->wParam;
      if ( bIsKeyPressed != 0 )
      {
        this->m_Accel.fVirt |= 1u;
        this->m_bIsDefined = 1;
      }
      break;
  }
  goto LABEL_24;
}

//------------------------------------------------------------------------------
// Address: 0x1043430C
// Name: private: void CCellObj::GetPoints(int,int,int,struct tagPOINT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CCellObj::GetPoints(CCellObj *this, int x, int y, int nCellWidth, tagPOINT *pptArray)
{
  int v5; // eax
  int v6; // ebx
  int v7; // eax

  pptArray->x = x - nCellWidth / 2;
  pptArray[1].y = y - nCellWidth / 2;
  v5 = (int)((double)nCellWidth * 0.5773502588272095) / 2;
  v6 = y - v5;
  pptArray[2].x = nCellWidth / 2 + x;
  pptArray[3].x = nCellWidth / 2 + x;
  v7 = y + v5;
  pptArray[1].x = x;
  pptArray[4].x = x;
  pptArray[4].y = y + nCellWidth / 2;
  pptArray->y = v6;
  pptArray[2].y = v6;
  pptArray[3].y = v7;
  pptArray[5].x = x - nCellWidth / 2;
  pptArray[5].y = v7;
}

//------------------------------------------------------------------------------
// Address: 0x1043437F
// Name: protected: int CMFCColorPickerCtrl::GetAngleFromPoint(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorPickerCtrl::GetAngleFromPoint(CMFCColorPickerCtrl *this, int nX, int nY)
{
  return (int)(atan2(Y: (double)nY, X: (double)nX) * 180.0 / 3.14159265358979);
}

//------------------------------------------------------------------------------
// Address: 0x104343B1
// Name: public: void CMFCColorPickerCtrl::GetHLS(double __near *,double __near *,double __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::GetHLS(
        CMFCColorPickerCtrl *this,
        long double *hue,
        long double *luminance,
        long double *saturation)
{
  *hue = this->m_dblHue;
  *luminance = this->m_dblLum;
  *saturation = this->m_dblSat;
}

//------------------------------------------------------------------------------
// Address: 0x104343D8
// Name: protected: virtual int CMFCColorPickerCtrl::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorPickerCtrl::PreCreateWindow(CMFCColorPickerCtrl *this, tagCREATESTRUCTA *cs)
{
  cs->style = cs->style & 0xFFFFFFF4 | 0xA;
  return CWnd::PreCreateWindow(this, cs);
}

//------------------------------------------------------------------------------
// Address: 0x1043440E
// Name: AlignColor
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall AlignColor@<eax>(int lPart@<esi>, int lDelta@<edi>)
{
  int result; // eax
  bool v3; // cc

  if ( lDelta == 0 )
    return lPart;
  if ( lPart < lDelta )
    return 0;
  result = 255;
  if ( lPart <= 255 - lDelta )
  {
    if ( abs(lnumber: lPart - 128) < lDelta )
      return 128;
    v3 = abs(lnumber: lPart - 192) < lDelta;
    result = 192;
    if ( !v3 )
      return lPart;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10434453
// Name: private: CCellObj::CCellObj(class CPalette __near *,unsigned long,int,int,int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCellObj *__thiscall CCellObj::CCellObj(
        CCellObj *this,
        CPalette *pPalette,
        unsigned int color,
        int x,
        int y,
        int nCellWidth,
        int lDelta)
{
  unsigned int v8; // eax
  unsigned __int8 lGreen; // [esp+1Ch] [ebp+10h]
  unsigned __int8 lRed; // [esp+20h] [ebp+14h]

  this->m_x = x;
  this->m_y = y;
  this->__vftable = (CCellObj_vtbl *)&CCellObj::`vftable';
  this->m_nCellWidth = nCellWidth;
  lRed = AlignColor(lPart: (unsigned __int8)color, lDelta);
  lGreen = AlignColor(lPart: BYTE1(color), lDelta);
  v8 = lRed | ((lGreen | ((unsigned __int8)AlignColor(lPart: BYTE2(color), lDelta) << 8)) << 8);
  this->m_CellColor = v8;
  if ( afxGlobalData.m_nBitsPerPixel == 8 )
    v8 = (unsigned __int16)GetNearestPaletteIndex(h: (HPALETTE)pPalette->m_hObject, color) | 0x1000000;
  this->m_CellDrawColor = v8;
  CCellObj::GetPoints(this, x: this->m_x, y: this->m_y, nCellWidth, pptArray: this->m_CellPoints);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104344FB
// Name: protected: void CMFCColorPickerCtrl::CreateHexGreyScaleBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::CreateHexGreyScaleBar(CMFCColorPickerCtrl *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // esi
  CCellObj *v5; // ecx
  CCellObj *v6; // eax
  CCellObj *v7; // eax
  CCellObj *v8; // eax
  CCellObj *v9; // eax
  CCellObj *v10; // eax
  int y2; // [esp+4h] [ebp-3Ch]
  int i; // [esp+Ch] [ebp-34h]
  unsigned __int8 nRGB; // [esp+10h] [ebp-30h]
  int nStartOffset; // [esp+14h] [ebp-2Ch]
  int yCenter; // [esp+18h] [ebp-28h]
  int v16; // [esp+1Ch] [ebp-24h]
  int x; // [esp+20h] [ebp-20h]
  int nRowNum; // [esp+24h] [ebp-1Ch]
  int nCurry; // [esp+28h] [ebp-18h]
  int nCurrya; // [esp+28h] [ebp-18h]
  CRect area; // [esp+2Ch] [ebp-14h] BYREF

  if ( this->m_arCells.m_nSize == 0 )
  {
    memset(&area, 0, sizeof(area));
    GetClientRect(hWnd: this->m_hWnd, lpRect: &area);
    v2 = (area.bottom - area.top) / 2 - 2;
    if ( v2 >= (area.right - area.left) / 13 )
    {
      v2 = (area.right - area.left) / 13;
      nCurry = v2;
    }
    else
    {
      nCurry = (area.bottom - area.top) / 2 - 2;
    }
    if ( v2 % 2 != 0 )
      nCurry = ++v2;
    yCenter = (area.bottom + area.top) / 2;
    v3 = (int)((double)nCurry * 0.5773502588272095 * 1.5);
    nRowNum = 0;
    v4 = yCenter - v3 / 2;
    y2 = v4 + v3;
    nStartOffset = area.left;
    v16 = v2 / 2;
    do
    {
      if ( nRowNum == 1 )
      {
        v5 = (CCellObj *)operator new(nSize: 0x48u);
        v6 = nullptr;
        if ( v5 != nullptr )
          v6 = CCellObj::CCellObj(
                 this: v5,
                 pPalette: this->m_pPalette,
                 color: 0xFFFFFFu,
                 x: nStartOffset + 2 * v2 / 2,
                 y: yCenter,
                 nCellWidth: 2 * v2,
                 lDelta: 0);
        CUIntArray::SetAtGrow(this: (CPtrArray *)&this->m_arCells, nIndex: this->m_arCells.m_nSize, newElement: v6);
      }
      nCurrya = v4;
      x = nStartOffset + 3 * v2;
      nRGB = -16;
      for ( i = 15; i != 0; --i )
      {
        if ( nRowNum == 1 )
        {
          v7 = (CCellObj *)operator new(nSize: 0x48u);
          if ( v7 != nullptr )
            v8 = CCellObj::CCellObj(
                   this: v7,
                   pPalette: this->m_pPalette,
                   color: nRGB | ((nRGB | (nRGB << 8)) << 8),
                   x,
                   y: nCurrya,
                   nCellWidth: v2,
                   lDelta: 7);
          else
            v8 = nullptr;
          CUIntArray::SetAtGrow(this: (CPtrArray *)&this->m_arCells, nIndex: this->m_arCells.m_nSize, newElement: v8);
        }
        x += v16;
        if ( nCurrya == v4 )
          nCurrya = y2;
        else
          nCurrya = v4;
        nRGB -= 15;
      }
      if ( nRowNum == 1 )
      {
        v9 = (CCellObj *)operator new(nSize: 0x48u);
        if ( v9 != nullptr )
          v10 = CCellObj::CCellObj(
                  this: v9,
                  pPalette: this->m_pPalette,
                  color: 0,
                  x: x + v16 + v2 - 1,
                  y: yCenter,
                  nCellWidth: 2 * v2,
                  lDelta: 0);
        else
          v10 = nullptr;
        CUIntArray::SetAtGrow(this: (CPtrArray *)&this->m_arCells, nIndex: this->m_arCells.m_nSize, newElement: v10);
      }
      if ( nRowNum == 0 )
        nStartOffset = (area.right - v16 - x - 2 * v2) / 2;
      ++nRowNum;
    }
    while ( nRowNum < 2 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10434715
// Name: public: void CMFCColorPickerCtrl::SetColor(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::SetColor(CMFCColorPickerCtrl *this, unsigned int Color)
{
  HWND__ *m_hWnd; // esi

  this->m_colorNew = Color;
  CDrawingManager::RGBtoHSL(rgb: Color, H: &this->m_dblHue, S: &this->m_dblSat, L: &this->m_dblLum);
  m_hWnd = this->m_hWnd;
  if ( m_hWnd != nullptr )
    RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
}

//------------------------------------------------------------------------------
// Address: 0x1043475A
// Name: protected: void CMFCColorPickerCtrl::CreateHexagon(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::CreateHexagon(CMFCColorPickerCtrl *this)
{
  int v2; // esi
  int v3; // edi
  CCellObj *v4; // eax
  CCellObj *v5; // eax
  unsigned int v6; // eax
  CCellObj *v7; // eax
  HWND__ *m_hWnd; // [esp+20h] [ebp-74h]
  int v9; // [esp+40h] [ebp-54h]
  int AngleFromPoint; // [esp+44h] [ebp-50h]
  CCellObj *v11; // [esp+48h] [ebp-4Ch]
  int v12; // [esp+4Ch] [ebp-48h]
  float v13; // [esp+50h] [ebp-44h]
  int v14; // [esp+54h] [ebp-40h]
  int v15; // [esp+58h] [ebp-3Ch]
  int y; // [esp+5Ch] [ebp-38h]
  int i; // [esp+60h] [ebp-34h]
  int v18; // [esp+64h] [ebp-30h]
  int x; // [esp+68h] [ebp-2Ch]
  int v20; // [esp+6Ch] [ebp-28h]
  int v21; // [esp+70h] [ebp-24h]
  tagRECT Rect; // [esp+74h] [ebp-20h] BYREF
  int v23; // [esp+90h] [ebp-4h]

  if ( this->m_arCells.m_nSize == 0 )
  {
    m_hWnd = this->m_hWnd;
    memset(&Rect, 0, sizeof(Rect));
    GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
    if ( Rect.bottom - Rect.top >= Rect.right - Rect.left )
      InflateRect(lprc: &Rect, dx: 0, dy: (Rect.left + Rect.bottom - Rect.top - Rect.right) / -2);
    else
      InflateRect(lprc: &Rect, dx: (Rect.right + Rect.top - Rect.bottom - Rect.left) / -2, dy: 0);
    v2 = (Rect.bottom - Rect.top) / 13 + 1;
    v3 = (Rect.right + Rect.left) / 2;
    y = (Rect.bottom + Rect.top) / 2;
    v4 = (CCellObj *)operator new(nSize: 0x48u);
    if ( v4 != nullptr )
      v5 = CCellObj::CCellObj(
             this: v4,
             pPalette: this->m_pPalette,
             color: 0xFFFFFFu,
             x: v3,
             y,
             nCellWidth: v2,
             lDelta: 0);
    else
      v5 = nullptr;
    CUIntArray::SetAtGrow(this: (CPtrArray *)&this->m_arCells, nIndex: this->m_arCells.m_nSize, newElement: v5);
    v15 = 1;
    v13 = (float)v2;
    v18 = 6;
    v14 = v3 + v2;
    do
    {
      v21 = 0;
      x = v14;
      v20 = y;
      do
      {
        v9 = (int)(cfxOffset[v21] * v13);
        v12 = (int)(cfyOffset[v21] * v13);
        if ( v15 > 0 )
        {
          for ( i = v15; i != 0; --i )
          {
            AngleFromPoint = CMFCColorPickerCtrl::GetAngleFromPoint(this, nX: x - v3, nY: v20 - y);
            v11 = (CCellObj *)operator new(nSize: 0x48u);
            v23 = 0;
            if ( v11 != nullptr )
            {
              v6 = CDrawingManager::HLStoRGB_TWO(H: (double)AngleFromPoint, L: (double)v18 / 7.0 + 0.1, S: 1.0);
              v7 = CCellObj::CCellObj(
                     this: v11,
                     pPalette: this->m_pPalette,
                     color: v6,
                     x,
                     y: v20,
                     nCellWidth: v2,
                     lDelta: 16);
            }
            else
            {
              v7 = nullptr;
            }
            v23 = -1;
            CUIntArray::SetAtGrow(this: (CPtrArray *)&this->m_arCells, nIndex: this->m_arCells.m_nSize, newElement: v7);
            x += v9;
            v20 += v12;
          }
        }
        ++v21;
      }
      while ( v21 < 6 );
      ++v15;
      v14 += v2;
      --v18;
    }
    while ( v18 > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10434958
// Name: public: void CMFCColorPickerCtrl::SetHLS(double,double,double,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::SetHLS(
        CMFCColorPickerCtrl *this,
        long double hue,
        long double luminance,
        long double saturation,
        int bInvalidate)
{
  HWND__ *m_hWnd; // eax

  if ( -1.0 != hue )
    this->m_dblHue = hue;
  if ( -1.0 != saturation )
    this->m_dblSat = saturation;
  if ( luminance != -1.0 )
    this->m_dblLum = luminance;
  this->m_colorNew = CDrawingManager::HLStoRGB_TWO(H: this->m_dblHue, L: this->m_dblSat, S: this->m_dblLum);
  if ( bInvalidate != 0 )
  {
    m_hWnd = this->m_hWnd;
    if ( m_hWnd != nullptr )
    {
      InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
      UpdateWindow(hWnd: this->m_hWnd);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104349F6
// Name: protected: void CMFCColorPickerCtrl::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::OnLButtonUp(CMFCColorPickerCtrl *this, unsigned int nFlags, CPoint point)
{
  HWND Capture; // eax

  Capture = GetCapture();
  if ( CWnd::FromHandle(hWnd: Capture) == this )
    ReleaseCapture();
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10434A1C
// Name: public: void CMFCColorPickerCtrl::SetLuminanceBarWidth(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::SetLuminanceBarWidth(CMFCColorPickerCtrl *this, int w)
{
  int v3; // ecx
  int v4; // kr00_4
  HWND__ *v5; // [esp-Ch] [ebp-28h]
  HWND__ *m_hWnd; // [esp-8h] [ebp-24h]
  CRect rectClient; // [esp+8h] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
  v3 = w;
  v4 = 3 * (rectClient.right - rectClient.left);
  if ( w >= v4 / 4 )
    v3 = v4 / 4;
  v5 = this->m_hWnd;
  this->m_nLumBarWidth = v3;
  InvalidateRect(hWnd: v5, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x10434A8A
// Name: protected: void CMFCColorPickerCtrl::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::OnSize(CMFCColorPickerCtrl *this, unsigned int nType, unsigned int cx, int cy)
{
  void *v5; // eax

  CWnd::Default(this);
  if ( this != (CMFCColorPickerCtrl *)-160 && this->m_bmpPicker.m_hObject != nullptr )
  {
    v5 = CGdiObject::Detach(this: &this->m_bmpPicker);
    DeleteObject(ho: v5);
  }
  InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
  UpdateWindow(hWnd: this->m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x10434ACA
// Name: protected: void CMFCColorPickerCtrl::OnSetFocus(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::OnSetFocus(CMFCColorPickerCtrl *this, CWnd *pOldWnd)
{
  CWnd::OnSetFocus(this, __formal: pOldWnd);
  InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x10434AEC
// Name: protected: void CMFCColorPickerCtrl::OnKillFocus(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::OnKillFocus(CMFCColorPickerCtrl *this, CWnd *pNewWnd)
{
  CWnd::Default(this);
  InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x10434B07
// Name: protected: int CMFCColorPickerCtrl::OnQueryNewPalette(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorPickerCtrl::OnQueryNewPalette(CMFCColorPickerCtrl *this)
{
  InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10434B21
// Name: protected: void CMFCColorPickerCtrl::OnPaletteChanged(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::OnPaletteChanged(CMFCColorPickerCtrl *this, CWnd *pFocusWnd)
{
  HWND__ *m_hWnd; // ecx
  HWND__ *v4; // eax

  CWnd::Default(this);
  if ( pFocusWnd != nullptr )
    m_hWnd = pFocusWnd->m_hWnd;
  else
    m_hWnd = nullptr;
  if ( this != nullptr )
    v4 = this->m_hWnd;
  else
    v4 = nullptr;
  if ( m_hWnd != v4 )
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x10434B5D
// Name: public: void CMFCColorPickerCtrl::SetPalette(class CPalette __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::SetPalette(CMFCColorPickerCtrl *this, CPalette *pPalette)
{
  CBitmap *p_m_bmpPicker; // ecx
  void *v4; // eax
  HWND__ *m_hWnd; // eax

  p_m_bmpPicker = &this->m_bmpPicker;
  this->m_pPalette = pPalette;
  if ( p_m_bmpPicker != nullptr && p_m_bmpPicker->m_hObject != nullptr )
  {
    v4 = CGdiObject::Detach(this: p_m_bmpPicker);
    DeleteObject(ho: v4);
  }
  m_hWnd = this->m_hWnd;
  if ( m_hWnd != nullptr )
  {
    InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10434BAA
// Name: protected: double CMFCColorPickerCtrl::LumFromPoint(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __thiscall CMFCColorPickerCtrl::LumFromPoint(CMFCColorPickerCtrl *this, int nY)
{
  int top; // edx
  HWND__ *m_hWnd; // [esp-8h] [ebp-24h]
  CRect rectClient; // [esp+8h] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
  InflateRect(lprc: &rectClient, dx: 0, dy: -5);
  top = rectClient.top;
  if ( rectClient.top <= nY )
    top = nY;
  if ( top >= rectClient.bottom )
  {
    nY = rectClient.bottom;
  }
  else if ( rectClient.top > nY )
  {
    nY = rectClient.top;
  }
  return ((double)rectClient.bottom - (double)nY) / (double)(rectClient.bottom - rectClient.top);
}

//------------------------------------------------------------------------------
// Address: 0x10434C27
// Name: protected: int CMFCColorPickerCtrl::PointFromLum(double)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorPickerCtrl::PointFromLum(CMFCColorPickerCtrl *this, long double dblLum)
{
  HWND__ *m_hWnd; // [esp-8h] [ebp-24h]
  CRect rectClient; // [esp+8h] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
  InflateRect(lprc: &rectClient, dx: 0, dy: -5);
  return rectClient.top + (int)((double)(rectClient.bottom - rectClient.top) * (1.0 - dblLum));
}

//------------------------------------------------------------------------------
// Address: 0x10434C8E
// Name: protected: class CPoint CMFCColorPickerCtrl::GetCursorPos(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPoint *__thiscall CMFCColorPickerCtrl::GetCursorPos(CMFCColorPickerCtrl *this, CPoint *result)
{
  int v3; // eax
  HWND__ *dblLum; // [esp+0h] [ebp-2Ch]
  CRect rectClient; // [esp+18h] [ebp-14h] BYREF

  dblLum = this->m_hWnd;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: dblLum, lpRect: &rectClient);
  result->x = 0;
  result->y = 0;
  if ( this->m_COLORTYPE == LUMINANCE )
  {
    v3 = CMFCColorPickerCtrl::PointFromLum(this, dblLum: this->m_dblLum);
    result->x = this->m_nLumBarWidth + rectClient.left + 6;
    goto LABEL_5;
  }
  if ( this->m_COLORTYPE == PICKER )
  {
    v3 = (int)((1.0 - this->m_dblSat) * (double)(rectClient.bottom - rectClient.top));
    result->x = (int)((double)(rectClient.right - rectClient.left) * this->m_dblHue);
LABEL_5:
    result->y = v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10434D3D
// Name: protected: class CRect CMFCColorPickerCtrl::GetCursorRect(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRect *__thiscall CMFCColorPickerCtrl::GetCursorRect(CMFCColorPickerCtrl *this, CRect *result)
{
  int v2; // ecx
  int v3; // eax
  CRect v5; // [esp+Ch] [ebp-18h] BYREF
  CPoint v6; // [esp+1Ch] [ebp-8h] BYREF

  result->left = 0;
  result->top = 0;
  result->right = 0;
  result->bottom = 0;
  if ( this->m_COLORTYPE == LUMINANCE )
  {
    *(CPoint *)&v5.left = *CMFCColorPickerCtrl::GetCursorPos(this, result: (CPoint *)&v5.right);
    v2 = v5.left + 9;
    v3 = v5.top + 9;
    goto LABEL_6;
  }
  if ( this->m_COLORTYPE == PICKER )
  {
    *(CPoint *)&v5.left = *CMFCColorPickerCtrl::GetCursorPos(this, result: &v6);
    v2 = v5.left + 19;
    v3 = v5.top + 19;
LABEL_6:
    v5.right = v2;
    v5.bottom = v3;
    *result = v5;
    goto LABEL_7;
  }
  SetRectEmpty(lprc: result);
LABEL_7:
  OffsetRect(lprc: result, dx: (result->right - result->left) / -2, dy: (result->bottom - result->top) / -2);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10434DDA
// Name: protected: void CMFCColorPickerCtrl::NotifyParent(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::NotifyParent(CMFCColorPickerCtrl *this)
{
  HWND Parent; // eax
  CWnd *v3; // ebx
  HWND__ *m_hWnd; // edi
  unsigned __int16 DlgCtrlID; // ax

  Parent = GetParent(hWnd: this->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  if ( v3 != nullptr )
  {
    m_hWnd = this->m_hWnd;
    DlgCtrlID = CWnd::GetDlgCtrlID(this);
    SendMessageA(hWnd: v3->m_hWnd, Msg: 0x111u, wParam: DlgCtrlID, lParam: (LPARAM)m_hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10434E33
// Name: public: void CMFCColorPickerCtrl::SelectCellHexagon(unsigned char,unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::SelectCellHexagon(
        CMFCColorPickerCtrl *this,
        unsigned __int8 R,
        unsigned __int8 G,
        unsigned __int8 B)
{
  CMFCColorPickerCtrl::SetColor(this, Color: R | ((G | (B << 8)) << 8));
}

//------------------------------------------------------------------------------
// Address: 0x10434E58
// Name: protected: void CMFCColorPickerCtrl::OnKeyDown(unsigned int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::OnKeyDown(
        CMFCColorPickerCtrl *this,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  long double m_dblSat; // st7
  long double m_dblHue; // st6
  long double v7; // st5
  long double v8; // st5
  double H; // st4
  double v10; // st3
  long double v11; // st5
  bool v12; // c3
  long double S; // st7
  void (__stdcall *v14)(HWND, const RECT *, BOOL); // edi
  CRect *p_result; // eax
  CRect *CursorRect; // eax
  long double m_dblLum; // st7
  long double v18; // st6
  long double v19; // st6
  bool v20; // c0
  bool v21; // c3
  double L; // st6
  char v23; // [esp+20h] [ebp-34h] BYREF
  CRect result; // [esp+30h] [ebp-24h] BYREF
  CRect rectCursorOld; // [esp+40h] [ebp-14h] BYREF

  if ( this->m_COLORTYPE == LUMINANCE )
  {
    CMFCColorPickerCtrl::GetCursorRect(this, result: &rectCursorOld);
    InflateRect(lprc: &rectCursorOld, dx: 1, dy: 1);
    m_dblLum = this->m_dblLum;
    if ( nChar == 38 )
    {
      v18 = this->m_dblLum + 0.05;
    }
    else
    {
      if ( nChar != 40 )
      {
LABEL_36:
        v19 = this->m_dblLum;
        v20 = v19 > 0.0;
        v21 = 0.0 == v19;
        L = 0.0;
        if ( (v20 || v21) && this->m_dblLum > 1.0 )
        {
          L = 1.0;
        }
        else if ( this->m_dblLum >= 0.0 )
        {
          L = this->m_dblLum;
        }
        this->m_dblLum = L;
        if ( L != m_dblLum )
        {
          v14 = (void (__stdcall *)(HWND, const RECT *, BOOL))InvalidateRect;
          this->m_colorNew = CDrawingManager::HLStoRGB_ONE(H: this->m_dblHue, L, S: this->m_dblSat);
          InvalidateRect(hWnd: this->m_hWnd, lpRect: &rectCursorOld, bErase: true);
          p_result = (CRect *)&v23;
          goto LABEL_30;
        }
        goto LABEL_27;
      }
      v18 = this->m_dblLum - 0.05;
    }
    this->m_dblLum = v18;
    goto LABEL_36;
  }
  if ( this->m_COLORTYPE == PICKER )
  {
    CMFCColorPickerCtrl::GetCursorRect(this, result: &rectCursorOld);
    InflateRect(lprc: &rectCursorOld, dx: 1, dy: 1);
    m_dblSat = this->m_dblSat;
    m_dblHue = this->m_dblHue;
    switch ( nChar )
    {
      case '%':
        v8 = this->m_dblHue - 0.05;
        break;
      case '&':
        v7 = this->m_dblSat + 0.05;
LABEL_10:
        this->m_dblSat = v7;
        goto LABEL_13;
      case '\'':
        v8 = this->m_dblHue + 0.05;
        break;
      case '(':
        v7 = this->m_dblSat - 0.05;
        goto LABEL_10;
      default:
        goto LABEL_13;
    }
    this->m_dblHue = v8;
LABEL_13:
    H = 1.0;
    if ( this->m_dblSat < 0.0 || this->m_dblSat <= 1.0 )
    {
      if ( this->m_dblSat >= 0.0 )
        v10 = this->m_dblSat;
      else
        v10 = 0.0;
    }
    else
    {
      v10 = 1.0;
    }
    this->m_dblSat = v10;
    if ( this->m_dblHue < 0.0 || this->m_dblHue <= 1.0 )
    {
      if ( this->m_dblHue < 0.0 )
      {
        H = 0.0;
        v11 = v10;
      }
      else
      {
        v11 = v10;
        H = this->m_dblHue;
      }
    }
    else
    {
      v11 = v10;
    }
    this->m_dblHue = H;
    if ( H == m_dblHue )
    {
      v12 = v11 == m_dblSat;
      S = v11;
      if ( v12 )
        goto LABEL_27;
    }
    else
    {
      S = v11;
    }
    v14 = (void (__stdcall *)(HWND, const RECT *, BOOL))InvalidateRect;
    this->m_colorNew = CDrawingManager::HLStoRGB_ONE(H, L: this->m_dblLum, S);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: &rectCursorOld, bErase: true);
    p_result = &result;
LABEL_30:
    CursorRect = CMFCColorPickerCtrl::GetCursorRect(this, result: p_result);
    v14(hWnd: this->m_hWnd, lpRect: CursorRect, bErase: true);
    CMFCColorPickerCtrl::NotifyParent(this);
  }
LABEL_27:
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x104350C5
// Name: private: int CCellObj::HitTest(struct tagPOINT)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CCellObj::HitTest(CCellObj *this, tagPOINT pt)
{
  HRGN PolygonRgn; // eax
  BOOL v3; // eax
  BOOL v4; // edi
  CRgn rgn; // [esp+10h] [ebp-14h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  rgn.m_hObject = nullptr;
  rgn.__vftable = (CRgn_vtbl *)&CRgn::`vftable';
  v7 = 0;
  PolygonRgn = CreatePolygonRgn(pptl: this->m_CellPoints, cPoint: 6, iMode: 1);
  CGdiObject::Attach(this: &rgn, hObject: PolygonRgn);
  v3 = PtInRegion(hrgn: (HRGN)rgn.m_hObject, x: pt.x, y: pt.y);
  v7 = -1;
  v4 = v3;
  rgn.__vftable = (CRgn_vtbl *)&CRgn::`vftable';
  CGdiObject::~CGdiObject(this: &rgn);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10435122
// Name: private: void CCellObj::Draw(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CCellObj::Draw(CCellObj *this, CDC *pDC)
{
  unsigned int m_CellDrawColor; // [esp-4h] [ebp-34h]
  CBrush br; // [esp+10h] [ebp-20h] BYREF
  CPen pen; // [esp+18h] [ebp-18h] BYREF
  CBrush *pOldBrush; // [esp+20h] [ebp-10h]
  int v8; // [esp+2Ch] [ebp-4h]
  CFont *pOldPen; // [esp+38h] [ebp+8h]

  CBrush::CBrush(this: &br, crColor: this->m_CellDrawColor);
  m_CellDrawColor = this->m_CellDrawColor;
  v8 = 0;
  CPen::CPen(this: &pen, nPenStyle: 0, nWidth: 1, crColor: m_CellDrawColor);
  LOBYTE(v8) = 1;
  pOldBrush = (CBrush *)CDC::SelectObject(this: pDC, pFont: (CFont *)&br);
  pOldPen = CDC::SelectObject(this: pDC, pFont: (CFont *)&pen);
  Polygon(hdc: pDC->m_hDC, apt: this->m_CellPoints, cpt: 6);
  CDC::SelectObject(this: pDC, pFont: pOldPen);
  CDC::SelectObject(this: pDC, pFont: (CFont *)pOldBrush);
  LOBYTE(v8) = 0;
  pen.__vftable = (CPen_vtbl *)&CPen::`vftable';
  CGdiObject::~CGdiObject(this: &pen);
  v8 = -1;
  br.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  CGdiObject::~CGdiObject(this: &br);
}

//------------------------------------------------------------------------------
// Address: 0x104351C2
// Name: private: void CCellObj::DrawSelected(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CCellObj::DrawSelected(CCellObj *this, CDC *pDC)
{
  HGDIOBJ StockObject; // eax
  HGDIOBJ v4; // eax
  HRGN v5; // eax
  HRGN v6; // eax
  HRGN v7; // eax
  int m_x; // [esp-10h] [ebp-E4h]
  int v9; // [esp-Ch] [ebp-E0h]
  int v10; // [esp-8h] [ebp-DCh]
  CBrush *pBrush; // [esp+10h] [ebp-C4h]
  CGdiObject v12; // [esp+14h] [ebp-C0h] BYREF
  CBrush *v13; // [esp+1Ch] [ebp-B8h]
  CGdiObject v14; // [esp+20h] [ebp-B4h] BYREF
  CGdiObject v15; // [esp+28h] [ebp-ACh] BYREF
  CDC *v16; // [esp+30h] [ebp-A4h]
  tagPOINT pptArray; // [esp+34h] [ebp-A0h] BYREF
  tagPOINT pptl; // [esp+64h] [ebp-70h] BYREF
  tagPOINT v19; // [esp+94h] [ebp-40h] BYREF
  int v20; // [esp+D0h] [ebp-4h]

  v16 = pDC;
  StockObject = GetStockObject(i: 0);
  pBrush = (CBrush *)CGdiObject::FromHandle(h: StockObject);
  v4 = GetStockObject(i: 4);
  v13 = (CBrush *)CGdiObject::FromHandle(h: v4);
  v14.m_hObject = nullptr;
  v14.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  v20 = 0;
  v15.m_hObject = nullptr;
  v15.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  v12.m_hObject = nullptr;
  v12.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  v10 = this->m_nCellWidth + 2;
  v9 = this->m_y - 1;
  m_x = this->m_x;
  LOBYTE(v20) = 2;
  CCellObj::GetPoints(this, x: m_x, y: v9, nCellWidth: v10, &pptArray);
  v5 = CreatePolygonRgn(pptl: &pptArray, cPoint: 6, iMode: 1);
  CGdiObject::Attach(this: &v15, hObject: v5);
  CDC::FrameRgn(this: v16, pRgn: (CRgn *)&v15, pBrush, nWidth: 2, nHeight: 2);
  CCellObj::GetPoints(this, x: this->m_x, y: this->m_y, nCellWidth: this->m_nCellWidth + 2, pptArray: &pptl);
  v6 = CreatePolygonRgn(&pptl, cPoint: 6, iMode: 1);
  CGdiObject::Attach(this: &v12, hObject: v6);
  CDC::FrameRgn(this: v16, pRgn: (CRgn *)&v12, pBrush: v13, nWidth: 1, nHeight: 1);
  CCellObj::GetPoints(this, x: this->m_x, y: this->m_y, nCellWidth: this->m_nCellWidth - 1, pptArray: &v19);
  v7 = CreatePolygonRgn(pptl: &v19, cPoint: 6, iMode: 1);
  CGdiObject::Attach(this: &v14, hObject: v7);
  CDC::FrameRgn(this: v16, pRgn: (CRgn *)&v14, pBrush: v13, nWidth: 1, nHeight: 1);
  LOBYTE(v20) = 1;
  v12.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  CGdiObject::~CGdiObject(this: &v12);
  LOBYTE(v20) = 0;
  v15.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  CGdiObject::~CGdiObject(this: &v15);
  v20 = -1;
  v14.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  CGdiObject::~CGdiObject(this: &v14);
}

//------------------------------------------------------------------------------
// Address: 0x10435364
// Name: public: CMFCColorPickerCtrl::CMFCColorPickerCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCColorPickerCtrl *__thiscall CMFCColorPickerCtrl::CMFCColorPickerCtrl(CMFCColorPickerCtrl *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CMFCColorPickerCtrl_vtbl *)&CMFCColorPickerCtrl::`vftable';
  this->m_bmpPicker.m_hObject = nullptr;
  this->m_bmpPicker.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  CObArray::CObArray(this: &this->m_arCells);
  this->m_colorNew = 0;
  this->m_colorOriginal = 0;
  CDrawingManager::RGBtoHSL(rgb: 0, H: &this->m_dblHue, S: &this->m_dblSat, L: &this->m_dblLum);
  this->m_dblLum = 0.5;
  this->m_nLumBarWidth = 20;
  this->m_COLORTYPE = PICKER;
  this->m_pPalette = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104353F3
// Name: public: virtual CMFCColorPickerCtrl::~CMFCColorPickerCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::~CMFCColorPickerCtrl(CMFCColorPickerCtrl *this)
{
  int i; // edi
  CObject *v3; // eax

  this->__vftable = (CMFCColorPickerCtrl_vtbl *)&CMFCColorPickerCtrl::`vftable';
  for ( i = 0; i < this->m_arCells.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arCells.m_nSize )
      AfxThrowInvalidArgException();
    v3 = this->m_arCells.m_pData[i];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CObject *, int))v3->dtr_CObject)(a1: v3, a2: 1);
  }
  CObArray::~CObArray(this: &this->m_arCells);
  this->m_bmpPicker.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_bmpPicker);
  CButton::~CButton(this);
}

//------------------------------------------------------------------------------
// Address: 0x10435485
// Name: protected: int CMFCColorPickerCtrl::SelectCellHexagon(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCColorPickerCtrl::SelectCellHexagon(CMFCColorPickerCtrl *this, unsigned int x, unsigned int y)
{
  int v4; // edi
  CCellObj *v5; // ebx
  unsigned int m_CellColor; // ebx

  v4 = 0;
  if ( this->m_arCells.m_nSize <= 0 )
    return 0;
  while ( 1 )
  {
    if ( v4 < 0 || v4 >= this->m_arCells.m_nSize )
      AfxThrowInvalidArgException();
    v5 = (CCellObj *)this->m_arCells.m_pData[v4];
    if ( CCellObj::HitTest(this: v5, pt: (tagPOINT)__PAIR64__(y, x)) )
      break;
    if ( ++v4 >= this->m_arCells.m_nSize )
      return 0;
  }
  m_CellColor = v5->m_CellColor;
  this->m_colorNew = m_CellColor;
  CDrawingManager::RGBtoHSL(rgb: m_CellColor, H: &this->m_dblHue, S: &this->m_dblSat, L: &this->m_dblLum);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104354FD
// Name: protected: void CMFCColorPickerCtrl::DrawHex(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::DrawHex(CMFCColorPickerCtrl *this, CDC *pDC)
{
  int v2; // edi
  CCellObj *v4; // ebx
  CCellObj *pSelCell; // [esp+8h] [ebp-4h]

  v2 = 0;
  AFX_GLOBAL_DATA::DrawParentBackground(this: &afxGlobalData, pWnd: this, pDC, rectClip: nullptr);
  pSelCell = nullptr;
  if ( this->m_arCells.m_nSize > 0 )
  {
    do
    {
      if ( v2 < 0 || v2 >= this->m_arCells.m_nSize )
        AfxThrowInvalidArgException();
      v4 = (CCellObj *)this->m_arCells.m_pData[v2];
      CCellObj::Draw(this: v4, pDC);
      if ( v4->m_CellColor == this->m_colorNew )
        pSelCell = v4;
      ++v2;
    }
    while ( v2 < this->m_arCells.m_nSize );
    if ( pSelCell != nullptr )
      CCellObj::DrawSelected(this: pSelCell, pDC);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10435576
// Name: protected: void CMFCColorPickerCtrl::DrawPicker(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::DrawPicker(CMFCColorPickerCtrl *this, CDC *pDC)
{
  int v3; // edi
  int v4; // ebx
  bool v5; // zf
  CBitmap *p_m_bmpPicker; // esi
  HDC v7; // eax
  HDC CompatibleDC; // eax
  HBITMAP CompatibleBitmap; // eax
  void *m_hObject; // eax
  int v11; // ebx
  int v12; // esi
  void *v13; // eax
  unsigned int S_4; // [esp+14h] [ebp-90h]
  double S; // [esp+28h] [ebp-7Ch]
  double v16; // [esp+30h] [ebp-74h]
  CDC v17; // [esp+38h] [ebp-6Ch] BYREF
  CBitmap *v18; // [esp+48h] [ebp-5Ch]
  int v19; // [esp+4Ch] [ebp-58h]
  CBrush v20; // [esp+50h] [ebp-54h] BYREF
  void *h; // [esp+58h] [ebp-4Ch]
  int v22; // [esp+5Ch] [ebp-48h]
  int v23; // [esp+64h] [ebp-40h]
  HDC hdc; // [esp+68h] [ebp-3Ch]
  int v25; // [esp+6Ch] [ebp-38h]
  int x; // [esp+70h] [ebp-34h]
  RECT rc; // [esp+74h] [ebp-30h] BYREF
  tagRECT Rect; // [esp+84h] [ebp-20h] BYREF
  int v29; // [esp+A0h] [ebp-4h]

  hdc = (HDC)pDC;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: this->m_hWnd, lpRect: &Rect);
  v3 = Rect.bottom - Rect.top;
  v4 = Rect.right - Rect.left;
  v5 = &this->m_bmpPicker == nullptr;
  p_m_bmpPicker = &this->m_bmpPicker;
  v19 = Rect.bottom - Rect.top;
  v22 = Rect.right - Rect.left;
  v18 = p_m_bmpPicker;
  if ( v5 || p_m_bmpPicker->m_hObject == nullptr )
  {
    CDC::CDC(this: &v17);
    v7 = hdc;
    v29 = 0;
    if ( hdc != nullptr )
      v7 = *((HDC *)hdc + 1);
    CompatibleDC = CreateCompatibleDC(hdc: v7);
    if ( CDC::Attach(this: &v17, hDC: CompatibleDC) != 0 )
    {
      CompatibleBitmap = CreateCompatibleBitmap(hdc: *((HDC *)hdc + 1), cx: v4, cy: v3);
      if ( CGdiObject::Attach(this: p_m_bmpPicker, hObject: CompatibleBitmap) != 0 )
      {
        if ( p_m_bmpPicker != nullptr )
          m_hObject = p_m_bmpPicker->m_hObject;
        else
          m_hObject = nullptr;
        h = CDC::SelectGdiObject(hDC: v17.m_hDC, h: m_hObject);
        v25 = 0;
        v11 = afxGlobalData.m_nBitsPerPixel <= 8 ? 4 : 1;
        if ( v3 > 0 )
        {
          v23 = -v11;
          v12 = v3 - v11;
          do
          {
            x = 0;
            if ( v22 > 0 )
            {
              S = (double)v25 / (double)v19;
              v16 = (double)v22;
              do
              {
                S_4 = CDrawingManager::HLStoRGB_ONE(H: (double)x / v16, L: 0.5, S);
                if ( afxGlobalData.m_nBitsPerPixel <= 8 )
                {
                  CBrush::CBrush(this: &v20, crColor: S_4);
                  rc.left = x;
                  rc.right = v11 + x;
                  rc.bottom = v12 + v11;
                  rc.top = v12;
                  FillRect(hDC: v17.m_hDC, lprc: &rc, hbr: (HBRUSH)v20.m_hObject);
                  v20.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
                  CGdiObject::~CGdiObject(this: &v20);
                }
                else
                {
                  SetPixelV(hdc: v17.m_hDC, x, y: v12, color: S_4);
                }
                x += v11;
              }
              while ( x < v22 );
            }
            v25 += v11;
            v12 += v23;
          }
          while ( v25 < v3 );
          p_m_bmpPicker = v18;
        }
        v13 = h;
        if ( h != nullptr )
          v13 = *((void **)h + 1);
        CDC::SelectGdiObject(hDC: v17.m_hDC, h: v13);
        v4 = v22;
      }
    }
    v29 = -1;
    CDC::~CDC(this: &v17);
  }
  CDC::DrawState(
    this: (CDC *)hdc,
    pt: 0,
    size: (CSize)__PAIR64__(v3, v4),
    pBitmap: p_m_bmpPicker,
    nFlags: 0,
    pBrush: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10435749
// Name: protected: void CMFCColorPickerCtrl::DrawLuminanceBar(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPickerCtrl::DrawLuminanceBar(CMFCColorPickerCtrl *this, CDC *pDC)
{
  int top; // edi
  double L; // st7
  unsigned int v5; // eax
  int m_nLumBarWidth; // eax
  HDC__ *L_4; // [esp+Ch] [ebp-44h]
  HWND__ *S; // [esp+10h] [ebp-40h]
  long double Sa; // [esp+10h] [ebp-40h]
  CBrush br; // [esp+24h] [ebp-2Ch] BYREF
  RECT rc; // [esp+2Ch] [ebp-24h] BYREF
  CRect rectClient; // [esp+3Ch] [ebp-14h] BYREF

  S = this->m_hWnd;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: S, lpRect: &rectClient);
  InflateRect(lprc: &rectClient, dx: 0, dy: -5);
  top = rectClient.top;
  while ( top <= rectClient.bottom )
  {
    Sa = this->m_dblSat;
    L = CMFCColorPickerCtrl::LumFromPoint(this, nY: top);
    v5 = CDrawingManager::HLStoRGB_ONE(H: this->m_dblHue, L, S: Sa);
    CBrush::CBrush(this: &br, crColor: v5);
    m_nLumBarWidth = this->m_nLumBarWidth;
    rc.left = 0;
    rc.right = m_nLumBarWidth;
    L_4 = pDC->m_hDC;
    rc.top = top++;
    rc.bottom = top;
    FillRect(hDC: L_4, lprc: &rc, hbr: (HBRUSH)br.m_hObject);
    br.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
    CGdiObject::~CGdiObject(this: &br);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1043B62F
// Name: _rename
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl rename(const char *oldname, const char *newname)
{
  DWORD LastError; // eax

  if ( MoveFileA(lpExistingFileName: oldname, lpNewFileName: newname) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1043B662
// Name: ___libm_sse2_sin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_sin@<st0>(__m128i X@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(X, 3) & 0x7FFF) - 12336) > 4293 && (_mm_extract_epi16(X, 3) & 0x7FF0) != 0x7FF0 )
    return sin(X: *(double *)X.m128i_i64);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1043B81A
// Name: ___libm_sse2_cos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_cos@<st0>(__m128i X@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(X, 3) & 0x7FFF) - 12336) > 4293 && (_mm_extract_epi16(X, 3) & 0x7FF0) != 0x7FF0 )
    return cos(X: *(double *)X.m128i_i64);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1043B9C5
// Name: _srand
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl srand(unsigned int seed)
{
  _getptd()->_holdrand = seed;
}

//------------------------------------------------------------------------------
// Address: 0x1043B9D7
// Name: _rand
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl rand()
{
  _tiddata *v0; // ecx
  unsigned int v1; // eax

  v0 = _getptd();
  v1 = 214013 * v0->_holdrand + 2531011;
  v0->_holdrand = v1;
  return HIWORD(v1) & 0x7FFF;
}

//------------------------------------------------------------------------------
// Address: 0x1043B9F8
// Name: _strtok
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strtok(char *string, const char *control)
{
  char v3; // dl
  char *token; // edx
  char *v5; // ebx
  _tiddata *ptd; // [esp+10h] [ebp-28h]
  unsigned __int8 map[32]; // [esp+14h] [ebp-24h] BYREF

  ptd = _getptd();
  memset(map, 0, sizeof(map));
  do
  {
    v3 = *control;
    map[*(unsigned __int8 *)control >> 3] |= 1 << (*control & 7);
    ++control;
  }
  while ( v3 != 0 );
  token = string;
  if ( string == nullptr )
    token = ptd->_token;
  while ( ((unsigned __int8)(1 << (*token & 7)) & map[(unsigned __int8)*token >> 3]) != 0 && *token != 0 )
    ++token;
  v5 = token;
  while ( *token != 0 )
  {
    if ( ((unsigned __int8)(1 << (*token & 7)) & map[(unsigned __int8)*token >> 3]) != 0 )
    {
      *token++ = 0;
      break;
    }
    ++token;
  }
  ptd->_token = token;
  return token != v5 ? v5 : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1043BAB5
// Name: __mbscmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbscmp_l(unsigned __int8 *s1, unsigned __int8 *s2, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 *v4; // esi
  __int16 v5; // cx
  __int16 v6; // ax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = s1;
  if ( s1 != nullptr )
  {
    v4 = s2;
    if ( s2 != nullptr )
    {
      if ( _loc_update.localeinfo.mbcinfo->ismbcodepage != 0 )
      {
        while ( 1 )
        {
          v5 = *v3++;
          if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v5 + 1] & 4) != 0 )
          {
            if ( *v3 != 0 )
              v5 = *v3++ | (unsigned __int16)(v5 << 8);
            else
              v5 = 0;
          }
          v6 = *v4++;
          if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v6 + 1] & 4) != 0 )
          {
            if ( *v4 != 0 )
              v6 = *v4++ | (unsigned __int16)(v6 << 8);
            else
              v6 = 0;
          }
          if ( v6 != v5 )
            break;
          if ( v5 == 0 )
          {
            if ( _loc_update.updated )
              _loc_update.ptd->_ownlocale &= ~2u;
            return;
          }
        }
      }
      else
      {
        strcmp(str1: s1, str2: s2);
      }
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1043BBB4
// Name: __mbscmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbscmp(unsigned __int8 *s1, unsigned __int8 *s2)
{
  _mbscmp_l(s1, s2, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1043BBCB
// Name: ___libm_sse2_exp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_exp@<st0>(__m128d a1@<xmm0>)
{
  __m128d v1; // xmm0
  int v2; // eax
  __m128d v3; // xmm7
  __m128d v4; // xmm1
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  __m128d v8; // xmm0
  __m128d v9; // xmm2
  __m128d v10; // xmm4
  __m128d v11; // xmm0
  __m128d v12; // xmm0
  __m128i v13; // xmm2
  double v14; // xmm0_8
  int v15; // edx
  int v16; // eax
  double result; // st7
  double v18; // [esp+8h] [ebp-16h]

  v1 = _mm_unpacklo_pd(a1, a1);
  v2 = _mm_extract_epi16((__m128i)v1, 3) & 0x7FFF;
  if ( ((v2 - 15504) | (unsigned int)(16527 - v2)) < 0x80000000 )
  {
    v3 = _mm_add_pd(_mm_mul_pd(*(__m128d *)cv_0, v1), *(__m128d *)Shifter);
    v4 = _mm_sub_pd(v3, *(__m128d *)Shifter);
    v5 = _mm_cvtsi128_si32((__m128i)v3);
    v6 = 4 * (v5 & 0x3F);
    v7 = v5 >> 6;
    v8 = _mm_sub_pd(_mm_sub_pd(v1, _mm_mul_pd(*(__m128d *)&cv_0[4], v4)), _mm_mul_pd(*(__m128d *)&cv_0[8], v4));
    v9 = *(__m128d *)&Tbl_addr_0[v6];
    v10 = _mm_mul_pd(*(__m128d *)&cv_0[12], v8);
    v4.m128d_f64[0] = v8.m128d_f64[0];
    v11 = _mm_mul_pd(v8, v8);
    v11.m128d_f64[0] = v11.m128d_f64[0] * v11.m128d_f64[0];
    v12 = _mm_mul_pd(v11, _mm_add_pd(*(__m128d *)&cv_0[16], v10));
    v4.m128d_f64[0] = v4.m128d_f64[0] + v9.m128d_f64[0] + v12.m128d_f64[0];
    v13 = (__m128i)_mm_or_pd(
                     _mm_unpackhi_pd(v9, v9),
                     (__m128d)_mm_slli_epi64(
                                _mm_add_epi64(
                                  _mm_and_si128((__m128i)v3, _mm_load_si128((const __m128i *)mmask)),
                                  _mm_load_si128((const __m128i *)bias)),
                                0x2Eu));
    v14 = _mm_unpackhi_pd(v12, v12).m128d_f64[0] + v4.m128d_f64[0];
    if ( (unsigned int)(v7 + 894) > 0x77C )
    {
      v15 = v7;
      v16 = v7 >> 1;
      *(_QWORD *)&v18 = _mm_andnot_si128(_mm_load_si128((const __m128i *)emask), v13).m128i_u64[0]
                      | (_mm_cvtsi32_si128(v16 + 1023).m128i_u64[0] << 52);
      return (v14 * v18 + v18) * COERCE_DOUBLE(_mm_cvtsi32_si128(v15 - v16 + 1023).m128i_u64[0] << 52);
    }
  }
  return result;
}
