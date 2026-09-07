// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/taocrypt/src/algebra.cpp
// Functions: 31
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\taocrypt\src\algebra.h"

//------------------------------------------------------------------------------
// Address: 0x00420D20
// Name: public: virtual class TaoCrypt::AbstractGroup const __near & TaoCrypt::AbstractRing::MultiplicativeGroup(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::AbstractRing::MultiplicativeGroup(void *this)
{
  return (int)this + 4;
}

//------------------------------------------------------------------------------
// Address: 0x004215C0
// Name: void mySTL::FreeArrayMemory<struct mySTL::pair<int,struct yaSSL::ClientKeyBase __near * (*)(void)>>(struct mySTL::pair<int,struct yaSSL::ClientKeyBase __near * (*)(void)> __near *)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl mySTL::FreeArrayMemory<mySTL::pair<int,yaSSL::ClientKeyBase * (__cdecl *)(void)>>(unsigned __int8 *ptr)
{
  yaSSL::ysArrayDelete<unsigned char>(ptr);
}

//------------------------------------------------------------------------------
// Address: 0x0042BA50
// Name: public: void mySTL::vector<struct mySTL::pair<int,class yaSSL::HandShakeBase __near * (*)(void)>>::push_back(struct mySTL::pair<int,class yaSSL::HandShakeBase __near * (*)(void)> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back(
        int this,
        const VectorByValue *v)
{
  _DWORD *v3; // eax
  const CSplitScreenAddedConVar *v4; // ebx
  CThreadManualEvent *v5; // edi
  CThreadManualEvent *v6; // ebx
  const CUtlString *v7; // ecx
  _DWORD *v8; // eax
  unsigned __int8 *v9; // ecx

  v3 = *(_DWORD **)(this + 4);
  if ( v3 == *(_DWORD **)(this + 8) )
  {
    v4 = (const CSplitScreenAddedConVar *)(2 * (((int)v3 - *(_DWORD *)this) >> 3) + 1);
    v5 = (CThreadManualEvent *)mySTL::GetArrayMemory<mySTL::pair<int,yaSSL::Message * (__cdecl *)(void)>>(
                                 items: (const CUtlMemory<CUtlString,int>::Iterator_t *)this,
                                 itemsa: v4);
    v6 = &v5[(_DWORD)v4];
    mySTL::uninit_copy<mySTL::pair<int,yaSSL::Message * (__cdecl *)(void)> *,mySTL::pair<int,yaSSL::Message * (__cdecl *)(void)> *>(
      first: v7,
      last: *(CThreadManualEvent **)this,
      lasta: *(CThreadManualEvent **)(this + 4),
      place: v5);
    if ( v8 != nullptr )
    {
      *v8 = LODWORD(v->x);
      v8[1] = LODWORD(v->y);
    }
    v9 = *(unsigned __int8 **)this;
    *(_DWORD *)this = v5;
    *(_DWORD *)(this + 4) = v8 + 2;
    *(_DWORD *)(this + 8) = v6;
    mySTL::FreeArrayMemory<mySTL::pair<int,yaSSL::ClientKeyBase * (__cdecl *)(void)>>(ptr: v9);
  }
  else
  {
    if ( v3 != nullptr )
    {
      *v3 = LODWORD(v->x);
      v3[1] = LODWORD(v->y);
    }
    *(_DWORD *)(this + 4) += 8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00450EE0
// Name: public: void TaoCrypt::WindowSlider::FindNextWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::WindowSlider::FindNextWindow(TaoCrypt::Integer *this)
{
  unsigned int v2; // ebp
  unsigned int v3; // edi
  int v4; // ecx
  unsigned int v5; // eax
  bool v6; // zf
  int v7; // ecx
  const char *v8; // [esp+0h] [ebp-10h]

  v2 = 32 * TaoCrypt::Integer::WordCount(this: &this->m_stackLevel);
  if ( *((_BYTE *)this + 46) != 0 )
    v3 = 0;
  else
    v3 = *((_DWORD *)this + 8);
  *((_BYTE *)this + 46) = 0;
  if ( TaoCrypt::Integer::GetBit(this, a2: v3) )
  {
LABEL_7:
    TaoCrypt::Integer::operator>>=((CInternalFileSystemPassThru<IFileSystem> *)this, a2: v3);
    v4 = *((_DWORD *)this + 8);
    *((_DWORD *)this + 9) += v3;
    v5 = TaoCrypt::Integer::Modulo(this, divisor: 1 << v4);
    v6 = *((_BYTE *)this + 44) == 0;
    *((_DWORD *)this + 10) = v5;
    if ( v6 || !TaoCrypt::Integer::GetBit(this, a2: *((_DWORD *)this + 8)) )
    {
      *((_BYTE *)this + 45) = 0;
    }
    else
    {
      v7 = *((_DWORD *)this + 8);
      *((_BYTE *)this + 45) = 1;
      *((_DWORD *)this + 10) = (1 << v7) - *((_DWORD *)this + 10);
      TaoCrypt::Integer::operator+=((CInternalFileSystemPassThru<IFileSystem> *)this, t: this + 4, a3: v8);
    }
  }
  else
  {
    while ( v3 < v2 )
    {
      if ( TaoCrypt::Integer::GetBit(this, a2: ++v3) )
        goto LABEL_7;
    }
    *((_BYTE *)this + 47) = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00450F90
// Name: class TaoCrypt::Integer __near * mySTL::GetArrayMemory<class TaoCrypt::Integer>(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__cdecl mySTL::GetArrayMemory<TaoCrypt::Integer>(int a1)
{
  return operator new[](sz: (const CSplitScreenAddedConVar *)(16 * a1), sza: (const CSplitScreenAddedConVar *)(16 * a1));
}

//------------------------------------------------------------------------------
// Address: 0x00450FB0
// Name: class mySTL::vector<class TaoCrypt::Integer> __near * mySTL::GetArrayMemory<class mySTL::vector<class TaoCrypt::Integer>>(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall mySTL::GetArrayMemory<mySTL::vector<TaoCrypt::Integer>>(
        const char *items,
        unsigned int itemsa)
{
  return operator new[](
           sz: (const CSplitScreenAddedConVar *)(12 * itemsa),
           sza: (const CSplitScreenAddedConVar *)(12 * itemsa));
}

//------------------------------------------------------------------------------
// Address: 0x00450FD0
// Name: void mySTL::FreeArrayMemory<class mySTL::vector<class TaoCrypt::Integer>>(class mySTL::vector<class TaoCrypt::Integer> __near *)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall mySTL::FreeArrayMemory<mySTL::vector<TaoCrypt::Integer>>(const char *ptr, unsigned __int8 *ptra)
{
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: ptra);
}

//------------------------------------------------------------------------------
// Address: 0x00450FE0
// Name: struct TaoCrypt::WindowSlider __near * mySTL::GetArrayMemory<struct TaoCrypt::WindowSlider>(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__cdecl mySTL::GetArrayMemory<TaoCrypt::WindowSlider>(unsigned int result)
{
  return operator new[](
           sz: (const CSplitScreenAddedConVar *)(48 * result),
           sza: (const CSplitScreenAddedConVar *)(48 * result));
}

//------------------------------------------------------------------------------
// Address: 0x00451000
// Name: public: virtual class TaoCrypt::Integer TaoCrypt::AbstractGroup::ScalarMultiply(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
struct TaoCrypt::Integer __thiscall TaoCrypt::AbstractGroup::ScalarMultiply(
        TaoCrypt::AbstractGroup *this,
        TaoCrypt::Integer *a2,
        const struct TaoCrypt::Integer *a3,
        int a4)
{
  TaoCrypt::Integer::Integer(this: a2);
  (*(void (__thiscall **)(TaoCrypt::AbstractGroup *, TaoCrypt::Integer *, const struct TaoCrypt::Integer *, int, int))(*(_DWORD *)this + 48))(
    a1: this,
    a2,
    a3,
    a4,
    a5: 1);
  return (struct TaoCrypt::Integer)a2;
}

//------------------------------------------------------------------------------
// Address: 0x00451030
// Name: public: TaoCrypt::WindowSlider::WindowSlider(class TaoCrypt::Integer const __near &,bool,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CVProfSnMarkerScope *__thiscall TaoCrypt::WindowSlider::WindowSlider(
        int this,
        CVProfSnMarkerScope *result,
        bool fastNegate,
        unsigned int windowSizeIn)
{
  const CSplitScreenAddedConVar *v5; // ecx
  const CFunctorData *v6; // eax
  unsigned int v7; // eax
  int v8; // eax

  TaoCrypt::Integer::Integer((TaoCrypt::Integer *)this, a2: (const struct TaoCrypt::Integer *)result);
  v6 = TaoCrypt::Integer::One(this: v5);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)(this + 16), a2: (const struct TaoCrypt::Integer *)v6);
  *(_DWORD *)(this + 32) = windowSizeIn;
  *(_DWORD *)(this + 36) = 0;
  *(_BYTE *)(this + 44) = fastNegate;
  *(_BYTE *)(this + 46) = 1;
  *(_BYTE *)(this + 47) = 0;
  if ( windowSizeIn == 0 )
  {
    v7 = TaoCrypt::Integer::BitCount(this: (int *)result);
    if ( v7 > 0x11 )
    {
      if ( v7 > 0x18 )
      {
        if ( v7 > 0x46 )
        {
          if ( v7 > 0xC5 )
          {
            if ( v7 > 0x21B )
              v8 = (v7 > 0x59A) + 6;
            else
              v8 = 5;
          }
          else
          {
            v8 = 4;
          }
        }
        else
        {
          v8 = 3;
        }
      }
      else
      {
        v8 = 2;
      }
    }
    else
    {
      v8 = 1;
    }
    *(_DWORD *)(this + 32) = v8;
  }
  TaoCrypt::Integer::operator<<=(this: this + 16, a2: *(_DWORD *)(this + 32));
  return (CVProfSnMarkerScope *)this;
}

//------------------------------------------------------------------------------
// Address: 0x004510E0
// Name: public: virtual class TaoCrypt::Integer TaoCrypt::AbstractRing::Exponentiate(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::Integer *__thiscall TaoCrypt::AbstractRing::Exponentiate(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        TaoCrypt::Integer *base,
        const int *exponent,
        int a4)
{
  TaoCrypt::Integer::Integer(this: base);
  (*((void (__thiscall **)(CUtlVector<int,CUtlMemory<int,int> > *, TaoCrypt::Integer *, const int *, int, int))this->m_Memory.m_pMemory
   + 21))(
    a1: this,
    a2: base,
    a3: exponent,
    a4,
    a5: 1);
  return base;
}

//------------------------------------------------------------------------------
// Address: 0x00451110
// Name: class TaoCrypt::Integer __near * mySTL::uninit_fill_n<class TaoCrypt::Integer __near *,unsigned int,class TaoCrypt::Integer>(class TaoCrypt::Integer __near *,unsigned int,class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::Integer *__thiscall mySTL::uninit_fill_n<TaoCrypt::Integer *,unsigned int,TaoCrypt::Integer>(
        const char *place,
        const CFunctorData *placea,
        unsigned int n,
        struct TaoCrypt::Integer *a4)
{
  unsigned int v4; // edi
  TaoCrypt::Integer *v5; // esi

  v4 = n;
  if ( n == 0 )
    return (TaoCrypt::Integer *)placea;
  v5 = (TaoCrypt::Integer *)placea;
  do
  {
    if ( v5 != nullptr )
      TaoCrypt::Integer::Integer(this: v5, a2: a4);
    --v4;
    v5 += 4;
  }
  while ( v4 != 0 );
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00451150
// Name: class TaoCrypt::Integer __near * mySTL::uninit_copy<class TaoCrypt::Integer __near *,class TaoCrypt::Integer __near *>(class TaoCrypt::Integer __near *,class TaoCrypt::Integer __near *,class TaoCrypt::Integer __near *)
// Source: json
//------------------------------------------------------------------------------
const CFunctorData *__cdecl mySTL::uninit_copy<TaoCrypt::Integer *,TaoCrypt::Integer *>(
        const CFunctorData *const first,
        const CFunctorData *const last,
        TaoCrypt::Integer *place)
{
  const struct TaoCrypt::Integer *v3; // esi
  TaoCrypt::Integer *v4; // edi

  v3 = (const struct TaoCrypt::Integer *)first;
  if ( first == last )
    return (const CFunctorData *)place;
  v4 = place;
  do
  {
    if ( v4 != nullptr )
      TaoCrypt::Integer::Integer(this: v4, a2: v3);
    v3 += 4;
    v4 += 4;
  }
  while ( v3 != (const struct TaoCrypt::Integer *)last );
  return (const CFunctorData *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x00451190
// Name: public: TaoCrypt::WindowSlider::WindowSlider(struct TaoCrypt::WindowSlider const __near &)
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::Integer *__thiscall TaoCrypt::WindowSlider::WindowSlider(
        TaoCrypt::Integer *this,
        struct TaoCrypt::Integer *a2)
{
  TaoCrypt::Integer::Integer(this, a2);
  TaoCrypt::Integer::Integer(this: this + 4, a2: a2 + 4);
  *(this + 8) = a2[8];
  *(this + 9) = a2[9];
  *(this + 10) = a2[10];
  *((_BYTE *)this + 44) = a2[11].m_stackLevel;
  *((_BYTE *)this + 45) = BYTE1(a2[11].m_stackLevel);
  *((_BYTE *)this + 46) = BYTE2(a2[11].m_stackLevel);
  *((_BYTE *)this + 47) = HIBYTE(a2[11].m_stackLevel);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004511E0
// Name: public: mySTL::vector<class TaoCrypt::Integer>::vector<class TaoCrypt::Integer>(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall mySTL::vector<TaoCrypt::Integer>::vector<TaoCrypt::Integer>(int this, unsigned int a2)
{
  CSplitScreenAddedConVar *v3; // eax
  struct TaoCrypt::Integer *v4; // eax
  const char *v5; // ecx
  TaoCrypt::Integer *v6; // eax
  unsigned __int8 *v7; // ecx
  TaoCrypt::Integer v9; // [esp+8h] [ebp-10h] BYREF
  unsigned __int8 *v10; // [esp+Ch] [ebp-Ch]
  __int64 v11; // [esp+10h] [ebp-8h] BYREF

  v3 = mySTL::GetArrayMemory<TaoCrypt::Integer>(a1: a2);
  *(_DWORD *)(this + 8) = (char *)v3 + 16 * a2;
  *(_DWORD *)this = v3;
  *(_DWORD *)(this + 4) = v3;
  v4 = TaoCrypt::Integer::Integer(this: &v9);
  v6 = mySTL::uninit_fill_n<TaoCrypt::Integer *,unsigned int,TaoCrypt::Integer>(
         place: v5,
         placea: *(const CFunctorData **)this,
         n: a2,
         a4: v4);
  v7 = v10;
  *(_DWORD *)(this + 4) = v6;
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v11,
    p: v7,
    n: v9.m_stackLevel);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00451240
// Name: private: mySTL::vector<class TaoCrypt::Integer>::vector<class TaoCrypt::Integer>(unsigned int,class mySTL::vector<class TaoCrypt::Integer> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge mySTL::vector<TaoCrypt::Integer>::vector<TaoCrypt::Integer>(
        CByteswap *this@<ecx>,
        int n,
        __int16 *other,
        int a4)
{
  CSplitScreenAddedConVar *v5; // eax

  v5 = mySTL::GetArrayMemory<TaoCrypt::Integer>(a1: n);
  *this = (CByteswap)v5;
  *((_DWORD *)this + 1) = v5;
  *((_DWORD *)this + 2) = (char *)v5 + 16 * n;
  if ( n <= (unsigned int)((*((_DWORD *)other + 1) - *(_DWORD *)other) >> 4) )
    _wassert(
      expr: (wchar_t *)L"n > other.size()",
      filename: (wchar_t *)L"G:\\bs\\connector-c-vs2008-32bit\\src\\mysql-connector-c-6.0.2\\extlib\\yassl\\taocrypt\\mySTL\\vector.hpp",
      lineno: 0x90u);
  *((_DWORD *)this + 1) = mySTL::uninit_copy<TaoCrypt::Integer *,TaoCrypt::Integer *>(
                            first: *(const CFunctorData *const *)other,
                            last: *((const CFunctorData *const *)other + 1),
                            place: *(TaoCrypt::Integer **)this);
}

//------------------------------------------------------------------------------
// Address: 0x004512B0
// Name: struct TaoCrypt::WindowSlider __near * mySTL::uninit_copy<struct TaoCrypt::WindowSlider __near *,struct TaoCrypt::WindowSlider __near *>(struct TaoCrypt::WindowSlider __near *,struct TaoCrypt::WindowSlider __near *,struct TaoCrypt::WindowSlider __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl mySTL::uninit_copy<TaoCrypt::WindowSlider *,TaoCrypt::WindowSlider *>(CTimeAdder place)
{
  CCycleCount *m_pTotal; // esi
  int m_Int64; // edi

  m_pTotal = place.m_pTotal;
  if ( place.m_pTotal == *(&place.m_pTotal + 1) )
    return place.m_Timer.m_Duration.m_Int64;
  m_Int64 = place.m_Timer.m_Duration.m_Int64;
  do
  {
    if ( m_Int64 != 0 )
    {
      TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)m_Int64, a2: (const struct TaoCrypt::Integer *)m_pTotal);
      TaoCrypt::Integer::Integer(
        this: (TaoCrypt::Integer *)(m_Int64 + 16),
        a2: (const struct TaoCrypt::Integer *)&m_pTotal[2]);
      *(_DWORD *)(m_Int64 + 32) = m_pTotal[4].m_Int64;
      *(_DWORD *)(m_Int64 + 36) = HIDWORD(m_pTotal[4].m_Int64);
      *(_DWORD *)(m_Int64 + 40) = m_pTotal[5].m_Int64;
      *(_BYTE *)(m_Int64 + 44) = BYTE4(m_pTotal[5].m_Int64);
      *(_BYTE *)(m_Int64 + 45) = BYTE5(m_pTotal[5].m_Int64);
      *(_BYTE *)(m_Int64 + 46) = BYTE6(m_pTotal[5].m_Int64);
      *(_BYTE *)(m_Int64 + 47) = HIBYTE(m_pTotal[5].m_Int64);
    }
    m_pTotal += 6;
    m_Int64 += 48;
  }
  while ( m_pTotal != *(&place.m_pTotal + 1) );
  return m_Int64;
}

//------------------------------------------------------------------------------
// Address: 0x00451320
// Name: private: mySTL::vector<struct TaoCrypt::WindowSlider>::vector<struct TaoCrypt::WindowSlider>(unsigned int,class mySTL::vector<struct TaoCrypt::WindowSlider> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mySTL::vector<TaoCrypt::WindowSlider>::vector<TaoCrypt::WindowSlider>(
        CVProfCounter *this,
        const char *n,
        _DWORD *other)
{
  int *v4; // eax
  CTimeAdder v5; // [esp-Ch] [ebp-18h]

  v4 = (int *)mySTL::GetArrayMemory<TaoCrypt::WindowSlider>(result: (unsigned int)n);
  this->m_pCounter = v4;
  *((_DWORD *)this + 1) = v4;
  *((_DWORD *)this + 2) = &v4[12 * (_DWORD)n];
  if ( (unsigned int)n <= (other[1] - *other) / 48 )
    _wassert(
      expr: (wchar_t *)L"n > other.size()",
      filename: (wchar_t *)L"G:\\bs\\connector-c-vs2008-32bit\\src\\mysql-connector-c-6.0.2\\extlib\\yassl\\taocrypt\\mySTL\\vector.hpp",
      lineno: 0x90u);
  LODWORD(v5.m_Timer.m_Duration.m_Int64) = (CVProfCounter)this->m_pCounter;
  *(_QWORD *)&v5.m_pTotal = *(_QWORD *)other;
  *((_DWORD *)this + 1) = mySTL::uninit_copy<TaoCrypt::WindowSlider *,TaoCrypt::WindowSlider *>(place: v5);
}

//------------------------------------------------------------------------------
// Address: 0x004513A0
// Name: void mySTL::destroy<class TaoCrypt::Integer __near *>(class TaoCrypt::Integer __near *,class TaoCrypt::Integer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mySTL::destroy<TaoCrypt::Integer *>(
        void (__cdecl *first)(),
        const CFunctorData *firsta,
        const CFunctorData *last)
{
  const CFunctorData *i; // esi

  for ( i = firsta; i != last; i += 4 )
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&i[2],
      p: (unsigned __int8 *)i[1].__vftable,
      n: (unsigned int)i->__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x004513D0
// Name: class mySTL::vector<class TaoCrypt::Integer> __near * mySTL::uninit_fill_n<class mySTL::vector<class TaoCrypt::Integer> __near *,unsigned int,class mySTL::vector<class TaoCrypt::Integer>>(class mySTL::vector<class TaoCrypt::Integer> __near *,unsigned int,class mySTL::vector<class TaoCrypt::Integer> const __near &)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar **__cdecl mySTL::uninit_fill_n<mySTL::vector<TaoCrypt::Integer> *,unsigned int,mySTL::vector<TaoCrypt::Integer>>(
        CSplitScreenAddedConVar **a1,
        unsigned int n,
        const CFunctorData *const *a3)
{
  unsigned int v3; // ebp
  CSplitScreenAddedConVar **v4; // edi
  int v5; // esi
  CSplitScreenAddedConVar *v6; // eax

  v3 = n;
  if ( n == 0 )
    return a1;
  v4 = a1;
  do
  {
    if ( v4 != nullptr )
    {
      v5 = (signed int)(*((_DWORD *)a3 + 1) - (unsigned int)*a3) >> 4;
      v6 = mySTL::GetArrayMemory<TaoCrypt::Integer>(a1: v5);
      *v4 = v6;
      v4[1] = v6;
      v4[2] = (CSplitScreenAddedConVar *)((char *)v6 + 16 * v5);
      v4[1] = (CSplitScreenAddedConVar *)mySTL::uninit_copy<TaoCrypt::Integer *,TaoCrypt::Integer *>(
                                           first: *a3,
                                           last: a3[1],
                                           place: (TaoCrypt::Integer *)v6);
    }
    --v3;
    v4 += 3;
  }
  while ( v3 != 0 );
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00451430
// Name: void mySTL::destroy<struct TaoCrypt::WindowSlider __near *>(struct TaoCrypt::WindowSlider __near *,struct TaoCrypt::WindowSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mySTL::destroy<TaoCrypt::WindowSlider *>(int a1, unsigned int *a2)
{
  unsigned int *v2; // edi
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *v3; // esi

  v2 = (unsigned int *)a1;
  if ( (unsigned int *)a1 != a2 )
  {
    v3 = (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(a1 + 24);
    do
    {
      TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
        this: v3,
        p: (unsigned __int8 *)v3[-1].m_iRefs,
        n: (unsigned int)v3[-1].CRefCountServiceBase<1,CRefMT>::__vftable);
      TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
        this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)((char *)v3 - 16),
        p: (unsigned __int8 *)v3[-2].CRefCountServiceBase<1,CRefMT>::__vftable,
        n: *v2);
      v2 += 12;
      v3 += 4;
    }
    while ( v2 != a2 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00451470
// Name: public: void mySTL::vector<class TaoCrypt::Integer>::resize(unsigned int,class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mySTL::vector<TaoCrypt::Integer>::resize(__int16 *other, unsigned int n, struct TaoCrypt::Integer *a3)
{
  void (__cdecl *v4)(); // ecx
  unsigned int v5; // eax
  const CFunctorData *v6; // edi
  const char *v7; // ecx
  TaoCrypt::Integer *v8; // eax
  CFunctorData *v9; // edi
  int v10; // edx
  void (__cdecl *v11)(); // ecx
  const char *v12; // ecx
  int v13; // [esp+0h] [ebp-14h]
  CLimitTimer tmp; // [esp+8h] [ebp-Ch] BYREF
  int v15; // [esp+10h] [ebp-4h]

  v4 = *((void (__cdecl **)())other + 1);
  v5 = ((int)v4 - *(_DWORD *)other) >> 4;
  if ( n != v5 )
  {
    if ( n >= v5 )
    {
      mySTL::vector<TaoCrypt::Integer>::vector<TaoCrypt::Integer>(this: (CByteswap *)&tmp, n, other, a4: v13);
      v8 = mySTL::uninit_fill_n<TaoCrypt::Integer *,unsigned int,TaoCrypt::Integer>(
             place: v7,
             placea: (const CFunctorData *)HIDWORD(tmp.m_lCycleLimit),
             n: n - ((*((_DWORD *)other + 1) - *(_DWORD *)other) >> 4),
             a4: a3);
      v9 = *(CFunctorData **)other;
      v10 = v15;
      *(_DWORD *)other = tmp.m_lCycleLimit;
      v11 = *((void (__cdecl **)())other + 1);
      *((_DWORD *)other + 1) = v8;
      *((_DWORD *)other + 2) = v10;
      mySTL::destroy<TaoCrypt::Integer *>(first: v11, firsta: v9, last: (const CFunctorData *)v11);
      mySTL::FreeArrayMemory<mySTL::vector<TaoCrypt::Integer>>(ptr: v12, ptra: (unsigned __int8 *)v9);
    }
    else
    {
      v6 = (const CFunctorData *)(*(_DWORD *)other + 16 * n);
      mySTL::destroy<TaoCrypt::Integer *>(first: v4, firsta: v6, last: (const CFunctorData *)v4);
      *((_DWORD *)other + 1) -= 16 * ((*((_DWORD *)other + 1) - (int)v6) >> 4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00451510
// Name: public: mySTL::vector<class mySTL::vector<class TaoCrypt::Integer>>::vector<class mySTL::vector<class TaoCrypt::Integer>>(unsigned int)
// Source: json
//------------------------------------------------------------------------------
const CCycleCount *__thiscall mySTL::vector<mySTL::vector<TaoCrypt::Integer>>::vector<mySTL::vector<TaoCrypt::Integer>>(
        int this,
        unsigned int result)
{
  CSplitScreenAddedConVar **v3; // eax
  void (__cdecl *v4)(); // ecx
  const char *v5; // ecx
  const CFunctorData *v7[3]; // [esp+8h] [ebp-Ch] BYREF

  v3 = (CSplitScreenAddedConVar **)mySTL::GetArrayMemory<mySTL::vector<TaoCrypt::Integer>>(
                                     items: (const char *)this,
                                     itemsa: result);
  *(_DWORD *)this = v3;
  *(_DWORD *)(this + 4) = v3;
  *(_DWORD *)(this + 8) = &v3[3 * result];
  memset(v7, 0, sizeof(v7));
  *(_DWORD *)(this + 4) = mySTL::uninit_fill_n<mySTL::vector<TaoCrypt::Integer> *,unsigned int,mySTL::vector<TaoCrypt::Integer>>(
                            a1: v3,
                            n: result,
                            a3: v7);
  mySTL::destroy<TaoCrypt::Integer *>(first: v4, firsta: nullptr, last: nullptr);
  mySTL::FreeArrayMemory<mySTL::vector<TaoCrypt::Integer>>(ptr: v5, ptra: nullptr);
  return (const CCycleCount *)this;
}

//------------------------------------------------------------------------------
// Address: 0x00451580
// Name: public: void mySTL::vector<struct TaoCrypt::WindowSlider>::push_back(struct TaoCrypt::WindowSlider const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mySTL::vector<TaoCrypt::WindowSlider>::push_back(int **other, struct TaoCrypt::WindowSlider *a2)
{
  TaoCrypt::Integer *v3; // ecx
  TaoCrypt::WindowSlider *v4; // edi
  unsigned __int8 *v5; // ebx
  int *v6; // edx
  const char *v7; // ecx
  unsigned int *v8; // [esp-Ch] [ebp-1Ch]
  CVProfCounter v9; // [esp+4h] [ebp-Ch] BYREF
  TaoCrypt::WindowSlider *v10; // [esp+8h] [ebp-8h]
  int *v11; // [esp+Ch] [ebp-4h]

  v3 = (TaoCrypt::Integer *)*(other + 1);
  if ( v3 == (TaoCrypt::Integer *)*(other + 2) )
  {
    mySTL::vector<TaoCrypt::WindowSlider>::vector<TaoCrypt::WindowSlider>(
      this: &v9,
      n: (const char *)(2 * (((char *)v3 - (char *)*other) / 48) + 1),
      other);
    v4 = v10;
    if ( v10 != nullptr )
      TaoCrypt::WindowSlider::WindowSlider(this: (TaoCrypt::Integer *)v10, (struct TaoCrypt::Integer *)a2);
    v5 = (unsigned __int8 *)*other;
    v6 = v11;
    *other = v9.m_pCounter;
    v8 = (unsigned int *)*(other + 1);
    *(other + 1) = (int *)((char *)v4 + 48);
    *(other + 2) = v6;
    mySTL::destroy<TaoCrypt::WindowSlider *>(a1: (int)v5, a2: v8);
    mySTL::FreeArrayMemory<mySTL::vector<TaoCrypt::Integer>>(ptr: v7, ptra: v5);
  }
  else
  {
    if ( v3 != nullptr )
      TaoCrypt::WindowSlider::WindowSlider(this: v3, (struct TaoCrypt::Integer *)a2);
    *(other + 1) += 12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00451610
// Name: public: void mySTL::vector<struct TaoCrypt::WindowSlider>::reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mySTL::vector<TaoCrypt::WindowSlider>::reserve(CVProfile *this, unsigned int n)
{
  unsigned __int8 *v3; // edi
  int v4; // ecx
  int v5; // edx
  const char *v6; // ecx
  unsigned int *m_nVTuneGroupID; // [esp-8h] [ebp-18h]
  CVProfCounter v8; // [esp+4h] [ebp-Ch] BYREF
  int v9; // [esp+8h] [ebp-8h]
  int v10; // [esp+Ch] [ebp-4h]

  if ( (this->m_GroupIDStack[0] - *(_DWORD *)&this->m_bVTuneGroupEnabled) / 48 < n )
  {
    mySTL::vector<TaoCrypt::WindowSlider>::vector<TaoCrypt::WindowSlider>(this: &v8, (const char *)n, other: this);
    v3 = *(unsigned __int8 **)&this->m_bVTuneGroupEnabled;
    v4 = v9;
    *(CVProfCounter *)&this->m_bVTuneGroupEnabled = v8;
    v5 = v10;
    m_nVTuneGroupID = (unsigned int *)this->m_nVTuneGroupID;
    this->m_nVTuneGroupID = v4;
    this->m_GroupIDStack[0] = v5;
    mySTL::destroy<TaoCrypt::WindowSlider *>(a1: (int)v3, a2: m_nVTuneGroupID);
    mySTL::FreeArrayMemory<mySTL::vector<TaoCrypt::Integer>>(ptr: v6, ptra: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00451680
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::AbstractEuclideanDomain::Gcd(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
CInternalFileSystemPassThru<IFileSystem> *__thiscall TaoCrypt::AbstractEuclideanDomain::Gcd(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        char *i1,
        char *i0)
{
  int m_lCycleLimit; // edi
  int v5; // ebp
  char *m_pMemory; // ebx
  int v7; // eax
  int v8; // ebx
  char *v9; // eax
  unsigned int v10; // ecx
  int v11; // edx
  int v12; // eax
  CInternalFileSystemPassThru<IFileSystem> *v13; // esi
  const char *v14; // ecx
  const char *v16; // [esp+0h] [ebp-30h]
  const char *v17; // [esp+0h] [ebp-30h]
  const char *v18; // [esp+0h] [ebp-30h]
  unsigned int i2; // [esp+10h] [ebp-20h]
  int v20; // [esp+14h] [ebp-1Ch]
  int v21; // [esp+18h] [ebp-18h]
  int v22; // [esp+1Ch] [ebp-14h]
  char *v23; // [esp+20h] [ebp-10h]
  CLimitTimer g; // [esp+24h] [ebp-Ch] BYREF
  unsigned int i1a; // [esp+34h] [ebp+4h]
  unsigned int i0a; // [esp+38h] [ebp+8h]

  mySTL::vector<TaoCrypt::Integer>::vector<TaoCrypt::Integer>(this: (int)&g, a2: 3u);
  m_lCycleLimit = g.m_lCycleLimit;
  TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)g.m_lCycleLimit, t: i0, a3: v16);
  v5 = m_lCycleLimit + 16;
  TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)(m_lCycleLimit + 16), t: i1, a3: v17);
  m_pMemory = this->m_Memory.m_pMemory;
  i0a = 0;
  i1a = 1;
  i2 = 2;
  v7 = (*((int (__thiscall **)(CUtlVector<char,CUtlMemory<char,int> > *))this->m_Memory.m_pMemory + 2))(a1: this);
  if ( (*((unsigned __int8 (__thiscall **)(CUtlVector<char,CUtlMemory<char,int> > *, int, int))m_pMemory + 1))(
         a1: this,
         a2: m_lCycleLimit + 16,
         a3: v7) == 0 )
  {
    v21 = 16;
    v20 = 32;
    v8 = 0;
    do
    {
      v9 = (char *)(*((int (__thiscall **)(CUtlVector<char,CUtlMemory<char,int> > *, int, int))this->m_Memory.m_pMemory
                    + 24))(
                     a1: this,
                     a2: v8 + m_lCycleLimit,
                     a3: v5);
      TaoCrypt::Integer::operator=(
        this: (CInternalFileSystemPassThru<IFileSystem> *)(v20 + m_lCycleLimit),
        t: v9,
        a3: v18);
      v10 = i0a;
      i0a = i1a;
      i1a = i2;
      v11 = v8;
      v8 = v21;
      v21 = 16 * i2;
      v22 = m_lCycleLimit + 16 * i2;
      v20 = v11;
      i2 = v10;
      v23 = this->m_Memory.m_pMemory;
      v12 = (*((int (__thiscall **)(CUtlVector<char,CUtlMemory<char,int> > *))this->m_Memory.m_pMemory + 2))(a1: this);
      v5 = v22;
    }
    while ( (*((unsigned __int8 (__thiscall **)(CUtlVector<char,CUtlMemory<char,int> > *, int, int))v23 + 1))(
              a1: this,
              a2: v22,
              a3: v12) == 0 );
  }
  v13 = TaoCrypt::Integer::operator=(
          this: (CInternalFileSystemPassThru<IFileSystem> *)&this->m_Size,
          t: (char *)(m_lCycleLimit + 16 * i0a),
          a3: v18);
  mySTL::destroy<TaoCrypt::Integer *>(
    first: (void (__cdecl *)())HIDWORD(g.m_lCycleLimit),
    firsta: (const CFunctorData *)m_lCycleLimit,
    last: (const CFunctorData *)HIDWORD(g.m_lCycleLimit));
  mySTL::FreeArrayMemory<mySTL::vector<TaoCrypt::Integer>>(ptr: v14, ptra: (unsigned __int8 *)m_lCycleLimit);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x004517B0
// Name: public: virtual class TaoCrypt::Integer TaoCrypt::AbstractGroup::CascadeScalarMultiply(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
struct TaoCrypt::Integer *__userpurge TaoCrypt::AbstractGroup::CascadeScalarMultiply@<eax>(
        TaoCrypt::AbstractGroup *this@<ecx>,
        const char *a2@<ebp>,
        struct TaoCrypt::Integer *a3,
        struct TaoCrypt::Integer *power1,
        struct TaoCrypt::Integer *a5,
        struct TaoCrypt::Integer *firstTime,
        TaoCrypt::Integer *a7)
{
  unsigned int *p_prevPosition; // eax
  unsigned int v9; // eax
  const struct TaoCrypt::Integer *v10; // eax
  char v12; // cl
  BOOL v13; // eax
  unsigned int v14; // edi
  int m_lCycleLimit; // ebp
  int v16; // ebx
  int v17; // edx
  char *v18; // eax
  char *v19; // eax
  char *v20; // eax
  CInternalFileSystemPassThru<IFileSystem> *v21; // ebp
  char *v22; // eax
  unsigned int v23; // eax
  int v24; // ebp
  unsigned int v25; // edi
  char *v26; // eax
  unsigned int v27; // ebp
  CInternalFileSystemPassThru<IFileSystem> *v28; // ebx
  int v29; // edi
  char *v30; // eax
  int v31; // ebp
  CInternalFileSystemPassThru<IFileSystem> *v32; // ecx
  unsigned int v33; // eax
  int v34; // ebx
  unsigned int v35; // edi
  CInternalFileSystemPassThru<IFileSystem> *v36; // ebx
  unsigned int v37; // edi
  char *v38; // eax
  unsigned int v39; // ebx
  unsigned int v40; // eax
  bool Bit; // al
  unsigned int v42; // ecx
  unsigned int v43; // eax
  unsigned int v44; // edi
  int v45; // ebp
  char *v46; // eax
  char *v47; // eax
  void (__cdecl *v48)(); // ecx
  const char *v49; // ecx
  const char *v51; // [esp+28h] [ebp-58h]
  const char *v52; // [esp+28h] [ebp-58h]
  const char *v53; // [esp+28h] [ebp-58h]
  const char *v54; // [esp+28h] [ebp-58h]
  unsigned int v55; // [esp+38h] [ebp-48h]
  unsigned int v56; // [esp+3Ch] [ebp-44h]
  int i; // [esp+40h] [ebp-40h]
  unsigned int ia; // [esp+40h] [ebp-40h]
  unsigned int ib; // [esp+40h] [ebp-40h]
  int v60; // [esp+44h] [ebp-3Ch]
  CInternalFileSystemPassThru<IFileSystem> *v61; // [esp+48h] [ebp-38h]
  CInternalFileSystemPassThru<IFileSystem> *v62; // [esp+48h] [ebp-38h]
  CInternalFileSystemPassThru<IFileSystem> *v63; // [esp+4Ch] [ebp-34h]
  CInternalFileSystemPassThru<IFileSystem> *v64; // [esp+4Ch] [ebp-34h]
  CInternalFileSystemPassThru<IFileSystem> *v65; // [esp+50h] [ebp-30h]
  int v66; // [esp+50h] [ebp-30h]
  CInternalFileSystemPassThru<IFileSystem> *v67; // [esp+54h] [ebp-2Ch] BYREF
  unsigned int prevPosition; // [esp+58h] [ebp-28h] BYREF
  int v69; // [esp+5Ch] [ebp-24h]
  unsigned int v70; // [esp+60h] [ebp-20h]
  CLimitTimer powerTable; // [esp+64h] [ebp-1Ch] BYREF
  CKeyErrorContext v72; // [esp+70h] [ebp-10h] BYREF
  unsigned __int8 *v73; // [esp+74h] [ebp-Ch]
  __int64 v74; // [esp+78h] [ebp-8h] BYREF
  unsigned int power1a; // [esp+88h] [ebp+8h]
  unsigned int power1b; // [esp+88h] [ebp+8h]
  int firstTimea; // [esp+90h] [ebp+10h]
  char firstTimeb; // [esp+90h] [ebp+10h]

  v67 = (CInternalFileSystemPassThru<IFileSystem> *)TaoCrypt::Integer::BitCount(this: &a7->m_stackLevel);
  prevPosition = TaoCrypt::Integer::BitCount(this: &a5->m_stackLevel);
  p_prevPosition = &prevPosition;
  if ( prevPosition <= (unsigned int)v67 )
    p_prevPosition = (unsigned int *)&v67;
  v9 = *p_prevPosition;
  v70 = v9;
  if ( v9 != 0 )
  {
    if ( v9 > 0x2E )
    {
      v13 = v9 > 0x104;
      v60 = v13 + 2;
      v12 = v13 + 2;
    }
    else
    {
      v12 = 1;
      v60 = 1;
    }
    v14 = 1 << v12;
    v55 = 1 << v12;
    v56 = 1 << v12 << v12;
    mySTL::vector<TaoCrypt::Integer>::vector<TaoCrypt::Integer>(this: (int)&powerTable, a2: v56);
    m_lCycleLimit = powerTable.m_lCycleLimit;
    v69 = LODWORD(powerTable.m_lCycleLimit) + 16;
    TaoCrypt::Integer::operator=(
      this: (CInternalFileSystemPassThru<IFileSystem> *)(LODWORD(powerTable.m_lCycleLimit) + 16),
      t: (char *)power1,
      a3: a2);
    v16 = 16 * v14;
    v65 = (CInternalFileSystemPassThru<IFileSystem> *)(16 * v14 + m_lCycleLimit);
    TaoCrypt::Integer::operator=(this: v65, t: (char *)firstTime, a3: v51);
    v17 = *(_DWORD *)this;
    if ( v60 == 1 )
    {
      v18 = (char *)(*(int (__thiscall **)(TaoCrypt::AbstractGroup *, struct TaoCrypt::Integer *, struct TaoCrypt::Integer *))(v17 + 12))(
                      a1: this,
                      a2: power1,
                      a3: firstTime);
      TaoCrypt::Integer::operator=(
        this: (CInternalFileSystemPassThru<IFileSystem> *)(m_lCycleLimit + 48),
        t: v18,
        a3: v52);
    }
    else
    {
      v63 = (CInternalFileSystemPassThru<IFileSystem> *)(m_lCycleLimit + 32);
      v19 = (char *)(*(int (__thiscall **)(_DWORD, struct TaoCrypt::Integer *))(v17 + 24))(a1: this, a2: power1);
      TaoCrypt::Integer::operator=(
        this: (CInternalFileSystemPassThru<IFileSystem> *)(m_lCycleLimit + 32),
        t: v19,
        a3: v52);
      prevPosition = 32 * v14;
      v67 = (CInternalFileSystemPassThru<IFileSystem> *)(m_lCycleLimit + 32 * v14);
      v20 = (char *)(*(int (__thiscall **)(_DWORD, struct TaoCrypt::Integer *))(*(_DWORD *)this + 24))(
                      a1: this,
                      a2: firstTime);
      TaoCrypt::Integer::operator=(this: v67, t: v20, a3: v54);
      if ( v14 > 3 )
      {
        v21 = (CInternalFileSystemPassThru<IFileSystem> *)(m_lCycleLimit + 48);
        v61 = (CInternalFileSystemPassThru<IFileSystem> *)(((v14 - 4) >> 1) + 1);
        do
        {
          v22 = (char *)(*(int (__thiscall **)(TaoCrypt::AbstractGroup *, IBaseFileSystem *, CInternalFileSystemPassThru<IFileSystem> *))(*(_DWORD *)this + 12))(
                          a1: this,
                          a2: &v21[-3].IBaseFileSystem,
                          a3: v63);
          TaoCrypt::Integer::operator=(this: v21, t: v22, a3: v53);
          v21 = (CInternalFileSystemPassThru<IFileSystem> *)((char *)v21 + 32);
          v61 = (CInternalFileSystemPassThru<IFileSystem> *)((char *)v61 - 1);
        }
        while ( v61 != nullptr );
      }
      v23 = 1;
      i = 1;
      if ( v14 > 1 )
      {
        v24 = v69;
        v64 = (CInternalFileSystemPassThru<IFileSystem> *)((char *)v65 + 16);
        v66 = v69;
        do
        {
          v25 = v23 + v14;
          if ( v25 < v56 )
          {
            v62 = v64;
            do
            {
              v26 = (char *)(*(int (__thiscall **)(TaoCrypt::AbstractGroup *, int, struct TaoCrypt::Integer *))(*(_DWORD *)this + 12))(
                              a1: this,
                              a2: v24,
                              a3: firstTime);
              TaoCrypt::Integer::operator=(this: v62, t: v26, a3: v53);
              v25 += v55;
              v62 = (CInternalFileSystemPassThru<IFileSystem> *)((char *)v62 + v16);
              v24 += v16;
            }
            while ( v25 < v56 );
            v23 = i;
          }
          v14 = v55;
          v64 = (CInternalFileSystemPassThru<IFileSystem> *)((char *)v64 + 32);
          v23 += 2;
          v24 = v66 + 32;
          i = v23;
          v66 += 32;
        }
        while ( v23 < v55 );
      }
      v27 = 3 * v14;
      if ( 3 * v14 < v56 )
      {
        v28 = (CInternalFileSystemPassThru<IFileSystem> *)(LODWORD(powerTable.m_lCycleLimit) + 48 * v14);
        v29 = LODWORD(powerTable.m_lCycleLimit) + 16 * v14;
        do
        {
          v30 = (char *)(*(int (__thiscall **)(TaoCrypt::AbstractGroup *, int, CInternalFileSystemPassThru<IFileSystem> *))(*(_DWORD *)this + 12))(
                          a1: this,
                          a2: v29,
                          a3: v67);
          TaoCrypt::Integer::operator=(this: v28, t: v30, a3: v53);
          v27 += 2 * v55;
          v29 += prevPosition;
          v28 = (CInternalFileSystemPassThru<IFileSystem> *)((char *)v28 + prevPosition);
        }
        while ( v27 < v56 );
        v14 = v55;
      }
      ia = v14;
      if ( v14 < v56 )
      {
        v31 = LODWORD(powerTable.m_lCycleLimit) + 16 * (v14 + 2);
        v32 = (CInternalFileSystemPassThru<IFileSystem> *)(2 * v14);
        v33 = 2 * v14;
        v34 = 2 - v14;
        v67 = (CInternalFileSystemPassThru<IFileSystem> *)(2 * v14);
        firstTimea = 2 * v14;
        v69 = 2 - v14;
        do
        {
          if ( v34 + v33 < v33 )
          {
            v35 = (unsigned int)(-v34 - 1) >> 1;
            v36 = (CInternalFileSystemPassThru<IFileSystem> *)v31;
            v37 = v35 + 1;
            do
            {
              v38 = (char *)(*(int (__thiscall **)(TaoCrypt::AbstractGroup *, IBaseFileSystem **, struct TaoCrypt::Integer *))(*(_DWORD *)this + 12))(
                              a1: this,
                              a2: &v36[-2].m_pBaseFileSystemPassThru,
                              a3: power1);
              TaoCrypt::Integer::operator=(this: v36, t: v38, a3: v53);
              v36 = (CInternalFileSystemPassThru<IFileSystem> *)((char *)v36 + 32);
              --v37;
            }
            while ( v37 != 0 );
            v14 = v55;
            v34 = v69;
            v33 = firstTimea;
            v32 = v67;
          }
          ia += (unsigned int)v32;
          v31 += prevPosition;
          v33 += (unsigned int)v32;
          firstTimea = v33;
        }
        while ( ia < v56 );
      }
      m_lCycleLimit = powerTable.m_lCycleLimit;
    }
    TaoCrypt::Integer::Integer(this: &v72);
    v39 = 0;
    v40 = v70 - 1;
    power1a = 0;
    prevPosition = v70 - 1;
    firstTimeb = 1;
    ib = v70 - 1;
    if ( (int)(v70 - 1) >= 0 )
    {
      while ( 1 )
      {
        power1a = TaoCrypt::Integer::GetBit(this: a5, a2: v40) + 2 * power1a;
        Bit = TaoCrypt::Integer::GetBit(this: a7, a2: ib);
        v42 = ib;
        v39 = Bit + 2 * v39;
        v43 = power1a;
        if ( ib == 0 || 2 * power1a >= v14 || 2 * v39 >= v14 )
        {
          v44 = prevPosition - ib;
          v45 = 0;
          prevPosition = ib;
          while ( (v43 != 0 || v39 != 0) && (v43 & 1) == 0 && (v39 & 1) == 0 )
          {
            v43 >>= 1;
            v39 >>= 1;
            --v44;
            ++v45;
          }
          power1b = v43;
          if ( firstTimeb != 0 )
          {
            TaoCrypt::Integer::operator=(
              this: (CInternalFileSystemPassThru<IFileSystem> *)&v72,
              t: (char *)(LODWORD(powerTable.m_lCycleLimit) + 16 * (v43 + (v39 << v60))),
              a3: v53);
            firstTimeb = 0;
          }
          else
          {
            if ( v44 != 0 )
            {
              do
              {
                --v44;
                v46 = (char *)(*(int (__thiscall **)(_DWORD, CKeyErrorContext *))(*(_DWORD *)this + 24))(
                                a1: this,
                                a2: &v72);
                TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)&v72, t: v46, a3: v53);
              }
              while ( v44 != 0 );
              v43 = power1b;
            }
            if ( v43 != 0 || v39 != 0 )
              (*(void (__thiscall **)(TaoCrypt::AbstractGroup *, CKeyErrorContext *, unsigned int))(*(_DWORD *)this + 32))(
                a1: this,
                a2: &v72,
                a3: LODWORD(powerTable.m_lCycleLimit) + 16 * (v43 + (v39 << v60)));
          }
          while ( v45 != 0 )
          {
            --v45;
            v47 = (char *)(*(int (__thiscall **)(_DWORD, CKeyErrorContext *))(*(_DWORD *)this + 24))(a1: this, a2: &v72);
            TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)&v72, t: v47, a3: v53);
          }
          v14 = v55;
          m_lCycleLimit = powerTable.m_lCycleLimit;
          v42 = ib;
          v39 = 0;
          power1a = 0;
        }
        ib = v42 - 1;
        if ( (int)(v42 - 1) < 0 )
          break;
        v40 = v42 - 1;
      }
    }
    TaoCrypt::Integer::Integer(this: a3, a2: &v72);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v74,
      p: v73,
      n: v72.m_stackLevel);
    mySTL::destroy<TaoCrypt::Integer *>(
      first: v48,
      firsta: (const CFunctorData *)m_lCycleLimit,
      last: (const CFunctorData *)HIDWORD(powerTable.m_lCycleLimit));
    mySTL::FreeArrayMemory<mySTL::vector<TaoCrypt::Integer>>(ptr: v49, ptra: (unsigned __int8 *)m_lCycleLimit);
    return a3;
  }
  else
  {
    v10 = (const struct TaoCrypt::Integer *)(*(int (__thiscall **)(TaoCrypt::AbstractGroup *))(*(_DWORD *)this + 8))(a1: this);
    TaoCrypt::Integer::Integer(this: a3, a2: v10);
    return a3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00451C30
// Name: public: virtual class TaoCrypt::Integer TaoCrypt::AbstractRing::CascadeExponentiate(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
struct TaoCrypt::Integer *__userpurge TaoCrypt::AbstractRing::CascadeExponentiate@<eax>(
        CUtlVector<int,CUtlMemory<int,int> > *this@<ecx>,
        const char *a2@<ebp>,
        struct TaoCrypt::Integer *x,
        struct TaoCrypt::Integer *a4,
        struct TaoCrypt::Integer *a5,
        struct TaoCrypt::Integer *a6,
        TaoCrypt::Integer *a7)
{
  TaoCrypt::AbstractGroup *v7; // eax

  v7 = (TaoCrypt::AbstractGroup *)(*((int (__thiscall **)(CUtlVector<int,CUtlMemory<int,int> > *))this->m_Memory.m_pMemory
                                   + 22))(a1: this);
  TaoCrypt::AbstractGroup::CascadeScalarMultiply(this: v7, a2, a3: x, power1: a4, a5, firstTime: a6, a7);
  return x;
}

//------------------------------------------------------------------------------
// Address: 0x00451C60
// Name: void mySTL::destroy<class mySTL::vector<class TaoCrypt::Integer> __near *>(class mySTL::vector<class TaoCrypt::Integer> __near *,class mySTL::vector<class TaoCrypt::Integer> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mySTL::destroy<mySTL::vector<TaoCrypt::Integer> *>(void *first, int a2, int a3)
{
  int i; // esi
  const char *v4; // ecx

  for ( i = a2; i != a3; i += 12 )
  {
    mySTL::destroy<TaoCrypt::Integer *>(
      first: *(void (__cdecl **)())i,
      firsta: *(const CFunctorData **)i,
      last: *(const CFunctorData **)(i + 4));
    mySTL::FreeArrayMemory<mySTL::vector<TaoCrypt::Integer>>(ptr: v4, ptra: *(unsigned __int8 **)i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00451CA0
// Name: public: virtual void TaoCrypt::AbstractGroup::SimultaneousMultiply(class TaoCrypt::Integer __near *,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::AbstractGroup::SimultaneousMultiply(
        int *this,
        const CFunctorData *result,
        struct TaoCrypt::Integer *a3,
        int notDone,
        unsigned int expCount)
{
  unsigned int v5; // edi
  int v7; // ebx
  char v9; // al
  CVProfSnMarkerScope *v10; // eax
  int v11; // edi
  struct TaoCrypt::Integer *v12; // eax
  bool v13; // zf
  __int32 v14; // ebp
  int v15; // edi
  int v16; // ebx
  int v17; // eax
  char *v18; // eax
  char *v19; // edi
  CInternalFileSystemPassThru<IFileSystem> *v20; // ebx
  unsigned int v21; // eax
  int v22; // eax
  int v23; // ebp
  int v24; // ebp
  int v25; // eax
  char *v26; // eax
  unsigned __int8 *v27; // esi
  const char *v28; // ecx
  unsigned __int8 *v29; // esi
  void *v30; // ecx
  const char *v31; // ecx
  const char *v32; // [esp+14h] [ebp-70h]
  __int16 *expBitPosition; // [esp+24h] [ebp-60h]
  unsigned int expBitPositiona; // [esp+24h] [ebp-60h]
  unsigned int v35; // [esp+28h] [ebp-5Ch]
  unsigned int i; // [esp+28h] [ebp-5Ch]
  CounterGroup_t other; // [esp+2Ch] [ebp-58h] BYREF
  int v38; // [esp+30h] [ebp-54h]
  int v39; // [esp+34h] [ebp-50h]
  char *v40[3]; // [esp+38h] [ebp-4Ch] BYREF
  CKeyErrorContext g; // [esp+44h] [ebp-40h] BYREF
  unsigned __int8 *v42; // [esp+48h] [ebp-3Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v43; // [esp+4Ch] [ebp-38h] BYREF
  unsigned __int8 *v44; // [esp+58h] [ebp-2Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v45; // [esp+5Ch] [ebp-28h] BYREF
  unsigned __int8 *v46; // [esp+68h] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v47; // [esp+6Ch] [ebp-18h] BYREF
  struct TaoCrypt::Integer *v48; // [esp+8Ch] [ebp+8h]
  char notDonea; // [esp+90h] [ebp+Ch]
  unsigned int notDoneb; // [esp+90h] [ebp+Ch]
  unsigned int expCounta; // [esp+94h] [ebp+10h]

  v5 = expCount;
  mySTL::vector<mySTL::vector<TaoCrypt::Integer>>::vector<mySTL::vector<TaoCrypt::Integer>>(
    this: (int)v40,
    result: expCount);
  v7 = 0;
  other = COUNTER_GROUP_DEFAULT;
  v38 = 0;
  v39 = 0;
  mySTL::vector<TaoCrypt::WindowSlider>::reserve(this: (CVProfile *)&other, n: expCount);
  if ( expCount != 0 )
  {
    expBitPosition = (__int16 *)v40[0];
    v35 = expCount;
    do
    {
      if ( *(_DWORD *)(notDone + 12) == 1 )
        _wassert(
          expr: (wchar_t *)L"expBegin->NotNegative()",
          filename: (wchar_t *)L"..\\extlib\\yassl\\taocrypt\\src\\algebra.cpp",
          lineno: 0xFAu);
      v9 = (*(int (__thiscall **)(int *))(*this + 20))(a1: this);
      v10 = TaoCrypt::WindowSlider::WindowSlider(
              this: (int)&v43.m_iRefs,
              result: (CVProfSnMarkerScope *)notDone,
              fastNegate: v9,
              windowSizeIn: 0);
      mySTL::vector<TaoCrypt::WindowSlider>::push_back((int **)&other, a2: (struct TaoCrypt::WindowSlider *)v10);
      notDone += 16;
      TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v47, p: v46, n: v45.m_iRefs);
      TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v45, p: v44, n: v43.m_iRefs);
      v11 = v7 + other;
      TaoCrypt::WindowSlider::FindNextWindow(this: (TaoCrypt::Integer *)(v7 + other));
      v12 = (struct TaoCrypt::Integer *)(*(int (__thiscall **)(int *))(*this + 8))(a1: this);
      mySTL::vector<TaoCrypt::Integer>::resize(other: expBitPosition, n: 1 << (*(_DWORD *)(v11 + 32) - 1), a3: v12);
      v7 += 48;
      v13 = v35-- == 1;
      expBitPosition += 6;
    }
    while ( !v13 );
    v5 = expCount;
  }
  expBitPositiona = 0;
  TaoCrypt::Integer::Integer(this: &g, a2: a3);
  while ( 1 )
  {
    notDonea = 0;
    if ( v5 == 0 )
      break;
    v48 = (struct TaoCrypt::Integer *)v40[0];
    v14 = other + 40;
    for ( i = v5; i != 0; --i )
    {
      if ( *(_BYTE *)(v14 + 7) == 0 && expBitPositiona == *(_DWORD *)(v14 - 4) )
      {
        v15 = v48->m_stackLevel + 16 * (*(_DWORD *)v14 >> 1);
        if ( *(_BYTE *)(v14 + 5) != 0 )
        {
          v16 = *this;
          v17 = (*(int (__thiscall **)(int *, CKeyErrorContext *))(*this + 16))(a1: this, a2: &g);
          (*(void (__thiscall **)(int *, int, int))(v16 + 32))(a1: this, a2: v15, a3: v17);
        }
        else
        {
          (*(void (__thiscall **)(int *, int, CKeyErrorContext *))(*this + 32))(a1: this, a2: v15, a3: &g);
        }
        TaoCrypt::WindowSlider::FindNextWindow(this: (TaoCrypt::Integer *)(v14 - 40));
        v5 = expCount;
      }
      if ( notDonea != 0 || (notDonea = 0, *(_BYTE *)(v14 + 7) == 0) )
        notDonea = 1;
      v48 += 3;
      v14 += 48;
    }
    if ( notDonea == 0 )
    {
      if ( v5 != 0 )
      {
        v19 = v40[0];
        notDoneb = expCount;
        do
        {
          v20 = (CInternalFileSystemPassThru<IFileSystem> *)result;
          result += 4;
          TaoCrypt::Integer::operator=(
            this: v20,
            t: (char *)(16 * ((*((_DWORD *)v19 + 1) - *(_DWORD *)v19) >> 4) + *(_DWORD *)v19 - 16),
            a3: v32);
          v21 = (*((_DWORD *)v19 + 1) - *(_DWORD *)v19) >> 4;
          if ( v21 > 1 )
          {
            v22 = v21 - 2;
            if ( v22 >= 1 )
            {
              v23 = 16 * v22;
              for ( expCounta = v22; expCounta != 0; --expCounta )
              {
                (*(void (__thiscall **)(int *, int, int))(*this + 32))(
                  a1: this,
                  a2: *(_DWORD *)v19 + v23,
                  a3: *(_DWORD *)v19 + v23 + 16);
                (*(void (__thiscall **)(int *, CInternalFileSystemPassThru<IFileSystem> *, int))(*this + 32))(
                  a1: this,
                  a2: v20,
                  a3: v23 + *(_DWORD *)v19);
                v23 -= 16;
              }
            }
            (*(void (__thiscall **)(int *, _DWORD, int))(*this + 32))(
              a1: this,
              a2: *(_DWORD *)v19,
              a3: *(_DWORD *)v19 + 16);
            v24 = *this;
            v25 = (*(int (__thiscall **)(int *, CInternalFileSystemPassThru<IFileSystem> *, _DWORD))(*this + 24))(
                    a1: this,
                    a2: v20,
                    a3: *(_DWORD *)v19);
            v26 = (char *)(*(int (__thiscall **)(int *, int))(v24 + 12))(a1: this, a2: v25);
            TaoCrypt::Integer::operator=(this: v20, t: v26, a3: v32);
          }
          v19 += 12;
          --notDoneb;
        }
        while ( notDoneb != 0 );
      }
      break;
    }
    v18 = (char *)(*(int (__thiscall **)(int *, CKeyErrorContext *))(*this + 24))(a1: this, a2: &g);
    TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)&g, t: v18, a3: v32);
    ++expBitPositiona;
  }
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v43, p: v42, n: g.m_stackLevel);
  v27 = (unsigned __int8 *)other;
  mySTL::destroy<TaoCrypt::WindowSlider *>(a1: other, a2: (unsigned int *)v38);
  mySTL::FreeArrayMemory<mySTL::vector<TaoCrypt::Integer>>(ptr: v28, ptra: v27);
  v29 = (unsigned __int8 *)v40[0];
  mySTL::destroy<mySTL::vector<TaoCrypt::Integer> *>(first: v30, a2: (int)v40[0], a3: (int)v40[1]);
  mySTL::FreeArrayMemory<mySTL::vector<TaoCrypt::Integer>>(ptr: v31, ptra: v29);
}

//------------------------------------------------------------------------------
// Address: 0x00451FA0
// Name: public: virtual void TaoCrypt::AbstractRing::SimultaneousExponentiate(class TaoCrypt::Integer __near *,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::AbstractRing::SimultaneousExponentiate(
        TaoCrypt::AbstractRing *this,
        CUtlVector<int,CUtlMemory<int,int> > *result,
        struct TaoCrypt::Integer *a3,
        const struct TaoCrypt::Integer *a4,
        unsigned int a5)
{
  int *v5; // eax

  v5 = (int *)(*(int (__thiscall **)(TaoCrypt::AbstractRing *))(*(_DWORD *)this + 88))(a1: this);
  TaoCrypt::AbstractGroup::SimultaneousMultiply(
    this: v5,
    (const CFunctorData *)result,
    a3,
    notDone: (int)a4,
    expCount: a5);
}
