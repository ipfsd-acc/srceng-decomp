// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gaspointobject.cpp
// Functions: 22
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gaspointobject.h"

//------------------------------------------------------------------------------
// Address: 0x10126CB0
// Name: void GFxObject_GetPointProperties(class GASEnvironment __near *,class GASObject __near *,class GASValue __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFxObject_GetPointProperties(struct GASEnvironment *a1, struct GASObject *a2, struct GASValue *const a3)
{
  ((void (__thiscall *)(struct GASObject *, char *, int, struct GASValue *const))a2[2].pNode[5].elem)(
    a1: &a2[2],
    a2: (char *)a1 + 120,
    a3: *((_DWORD *)a1 + 30) + 524,
    a4: a3);
  ((void (__thiscall *)(struct GASObject *, char *, int, char *))a2[2].pNode[5].elem)(
    a1: &a2[2],
    a2: (char *)a1 + 120,
    a3: *((_DWORD *)a1 + 30) + 528,
    a4: (char *)a3 + 16);
}

//------------------------------------------------------------------------------
// Address: 0x10126D00
// Name: public: void GASPointObject::GetProperties(class GASStringContext __near *,class GASValue __near * const)
// Source: json
//------------------------------------------------------------------------------
const GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> *__thiscall GASPointObject::GetProperties(
        GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> *this,
        const GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> *psc,
        int psc_4)
{
  char *v3; // esi

  v3 = (char *)this + 16;
  (*(void (__thiscall **)(char *, const GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> *, struct GFxMovieRoot **, int))(*((_DWORD *)this + 4) + 44))(
    a1: (char *)this + 16,
    a2: psc,
    a3: psc->Data.Data + 131,
    a4: psc_4);
  return (*(const GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> *(__thiscall **)(char *, const GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> *, struct GFxMovieRoot **, int))(*(_DWORD *)v3 + 44))(
           a1: v3,
           a2: psc,
           a3: psc->Data.Data + 132,
           a4: psc_4 + 16);
}

//------------------------------------------------------------------------------
// Address: 0x10126D50
// Name: public: void GASPointObject::SetProperties(class GASStringContext __near *,class GASValue const __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPointObject::SetProperties(
        GASPointObject *this,
        struct GASStringContext *params,
        const struct GASValue *a3)
{
  void (__thiscall *v3)(char *, struct GASStringContext *, int, const struct GASValue *, char *); // eax
  const struct GASValue *v4; // ebx
  char *v5; // esi
  void (__thiscall *v6)(char *, struct GASStringContext *, int, char *, char *); // edx
  int v7; // [esp-Ch] [ebp-1Ch]
  int v8; // [esp-Ch] [ebp-1Ch]
  char v9; // [esp+Fh] [ebp-1h] BYREF

  v3 = *(void (__thiscall **)(char *, struct GASStringContext *, int, const struct GASValue *, char *))(*((_DWORD *)this + 4) + 40);
  v4 = a3;
  v5 = (char *)this + 16;
  v7 = *(_DWORD *)params + 524;
  v9 = 0;
  v3(a1: (char *)this + 16, a2: params, a3: v7, a4: a3, a5: &v9);
  v6 = *(void (__thiscall **)(char *, struct GASStringContext *, int, char *, char *))(*(_DWORD *)v5 + 40);
  v8 = *(_DWORD *)params + 528;
  HIBYTE(a3) = 0;
  v6(a1: v5, a2: params, a3: v8, a4: (char *)v4 + 16, a5: (char *)&a3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x10126DB0
// Name: public: void GASPointObject::SetProperties(class GASEnvironment __near *,class GPoint<double> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPointObject::SetProperties(int *this, int a2, double *a3)
{
  int v3; // eax
  double *v4; // ebx
  int *v5; // edi
  _DWORD *v6; // esi
  void (__thiscall *v7)(int *, int, int, GASValue *, char *); // edx
  int v8; // eax
  void (__thiscall *v9)(int *, _DWORD *, int, GASValue *, char *); // edx
  int v10; // [esp-14h] [ebp-2Ch]
  int v11; // [esp-10h] [ebp-28h]
  int v12; // [esp-10h] [ebp-28h]
  GASValue v13; // [esp+8h] [ebp-10h] BYREF
  double v14; // [esp+Ch] [ebp-Ch]

  v3 = *(this + 4);
  v4 = a3;
  v14 = *a3;
  v5 = this + 4;
  v6 = (_DWORD *)(a2 + 120);
  v7 = *(void (__thiscall **)(int *, int, int, GASValue *, char *))(v3 + 40);
  v11 = *(_DWORD *)(a2 + 120) + 524;
  v10 = a2 + 120;
  LOBYTE(v13) = 3;
  HIBYTE(a2) = 0;
  v7(a1: this + 4, a2: v10, a3: v11, a4: &v13, a5: (char *)&a2 + 3);
  GASValue::~GASValue(this: &v13, a2: (int)v5);
  v8 = *v5;
  v14 = v4[1];
  v9 = *(void (__thiscall **)(int *, _DWORD *, int, GASValue *, char *))(v8 + 40);
  v12 = *v6 + 528;
  LOBYTE(v13) = 3;
  HIBYTE(a2) = 0;
  v9(a1: v5, a2: v6, a3: v12, a4: &v13, a5: (char *)&a2 + 3);
  GASValue::~GASValue(this: &v13, a2: (int)v5);
}

//------------------------------------------------------------------------------
// Address: 0x10126E40
// Name: protected: static void GASPointCtorFunction::Distance(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GASPointCtorFunction::Distance(GASFnCall *result)
{
  int v1; // edi
  long double v2; // st7
  GASValue *v3; // eax
  struct GASObject *v4; // eax
  struct GASObject *v5; // edi
  GASValue *v6; // eax
  struct GASObject *v7; // eax
  struct GASObject *v8; // ebx
  GASValue *v9; // esi
  _SERVICE_STATUS *v10; // edi
  double v11; // st7
  struct GASEnvironment *v12; // ecx
  long double v13; // st7
  long double v14; // st7
  int v15; // esi
  GASValue *v16; // esi
  int i; // edi
  HINSTANCE__ **p_hInstance; // esi
  int j; // edi
  struct GASEnvironment *v20; // [esp-10h] [ebp-90h]
  const struct GASEnvironment *v21; // [esp-8h] [ebp-88h]
  const struct GASEnvironment *v22; // [esp-8h] [ebp-88h]
  _SERVICE_STATUS *v23; // [esp-8h] [ebp-88h]
  GASValue v24[4]; // [esp+8h] [ebp-78h] BYREF
  tagWNDCLASSW v; // [esp+18h] [ebp-68h] BYREF
  GASValue v26; // [esp+48h] [ebp-38h] BYREF
  long double v27; // [esp+4Ch] [ebp-34h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *yd; // [esp+58h] [ebp-28h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *xd; // [esp+68h] [ebp-18h] BYREF
  double v30; // [esp+6Ch] [ebp-14h]
  double d; // [esp+78h] [ebp-8h]

  d = GASNumberUtil::NaN();
  v1 = (int)result[1];
  if ( *(_BYTE *)v1 >= 5u )
    GASValue::DropRefs(this: (GASValue *)result[1], a2: v1);
  v2 = d;
  *(_BYTE *)v1 = 3;
  *(long double *)(v1 + 4) = v2;
  if ( (int)result[7] > 1 )
  {
    v21 = (const struct GASEnvironment *)result[6];
    v3 = (GASValue *)GASFnCall::Arg(this: result, a2: 0);
    v4 = GASValue::ToObject(this: v3, a2: v1, a3: v21);
    v22 = (const struct GASEnvironment *)result[6];
    v5 = v4;
    v6 = (GASValue *)GASFnCall::Arg(this: result, a2: 1);
    v7 = GASValue::ToObject(this: v6, a2: (int)v5, a3: v22);
    v8 = v7;
    if ( v5 != nullptr && v7 != nullptr )
    {
      if ( ((int (__thiscall *)(struct GASObject *))v5[2].pNode[1].pNext)(a1: &v5[2]) == 16
        || ((int (__thiscall *)(struct GASObject *))v8[2].pNode[1].pNext)(a1: &v8[2]) == 16 )
      {
        v20 = (struct GASEnvironment *)result[6];
        LOBYTE(v24[0]) = 0;
        LOBYTE(v.style) = 0;
        LOBYTE(v.hInstance) = 0;
        LOBYTE(v.lpszMenuName) = 0;
        GFxObject_GetPointProperties(a1: v20, a2: v5, a3: (struct GASValue *const)v24);
        GFxObject_GetPointProperties(
          a1: (struct GASEnvironment *)result[6],
          a2: v8,
          a3: (struct GASValue *const)&v.hInstance);
        GASValue::GASValue(this: &xd, v: (tagWNDCLASSW *)&v.hInstance);
        v10 = (_SERVICE_STATUS *)result[6];
        d = GASValue::ToNumber(this: &xd, a2: (int)v10, a3: v2, result: v10);
        v11 = GASValue::ToNumber(this: v24, a2: (int)v10, a3: d, result: v10);
        d = d - v11;
        if ( (unsigned __int8)xd >= 5u )
          GASValue::DropRefs(this: &xd, a2: (int)v10);
        v12 = (struct GASEnvironment *)result[6];
        v13 = d;
        v30 = d;
        LOBYTE(xd) = 3;
        GASValue::Mul(this: (unsigned int)&xd, penv: v12, v: (tagWNDCLASSW *)&xd);
        GASValue::GASValue(this: &yd, v: (tagWNDCLASSW *)&v.lpszMenuName);
        GASValue::Sub(this: (unsigned int)&yd, penv: (struct GASEnvironment *)result[6], &v);
        GASValue::Mul(this: (unsigned int)&yd, penv: (struct GASEnvironment *)result[6], v: (tagWNDCLASSW *)&yd);
        GASValue::Add(
          this: (unsigned int)&xd,
          a2: (int)v10,
          a3: v13,
          penv: (unsigned int)result[6],
          v: (tagWNDCLASSW *)&yd);
        v27 = sqrt(GASValue::ToNumber(this: &xd, a2: (int)v10, a3: v14, result: (_SERVICE_STATUS *)result[6]));
        v23 = (_SERVICE_STATUS *)result[6];
        LOBYTE(v26) = 3;
        d = GASValue::ToNumber(this: &v26, a2: (int)v10, a3: v27, result: v23);
        GASValue::~GASValue(this: &v26, a2: (int)v10);
        v15 = (int)result[1];
        if ( *(_BYTE *)v15 >= 5u )
          GASValue::DropRefs(this: (GASValue *)v15, a2: (int)v10);
        *(double *)(v15 + 4) = d;
        *(_BYTE *)v15 = 3;
        GASValue::~GASValue(this: &yd, a2: (int)v10);
        GASValue::~GASValue(this: &xd, a2: (int)v10);
        v16 = &v26;
        for ( i = 1; i >= 0; --i )
        {
          v16 -= 4;
          GASValue::~GASValue(this: v16, a2: i);
        }
        p_hInstance = &v.hInstance;
        for ( j = 1; j >= 0; --j )
        {
          p_hInstance -= 4;
          GASValue::~GASValue(this: (GASValue *)p_hInstance, a2: j);
        }
      }
      else
      {
        v9 = (GASValue *)result[1];
        GASValue::DropRefs(this: v9, a2: (int)v5);
        *(_BYTE *)v9 = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127030
// Name: void GFxObject_GetPointProperties(class GASEnvironment __near *,class GASObject __near *,class GPoint<double> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFxObject_GetPointProperties(_SERVICE_STATUS *a1, int a2, double *a3)
{
  unsigned int dwControlsAccepted; // edx
  long double v4; // st7
  double v5; // st7
  GASValue *v6; // esi
  int v7; // edi
  GASValue v8[4]; // [esp+Ch] [ebp-28h] BYREF
  GASValue v9[4]; // [esp+1Ch] [ebp-18h] BYREF
  double v10; // [esp+2Ch] [ebp-8h] BYREF

  dwControlsAccepted = a1[4].dwControlsAccepted;
  LOBYTE(v8[0]) = 0;
  LOBYTE(v9[0]) = 0;
  (*(void (__thiscall **)(int, unsigned int *, unsigned int, GASValue *))(*(_DWORD *)(a2 + 16) + 44))(
    a1: a2 + 16,
    a2: &a1[4].dwControlsAccepted,
    a3: dwControlsAccepted + 524,
    a4: v8);
  v4 = ((double (__thiscall *)(int, unsigned int *, unsigned int, GASValue *))*(_DWORD *)(*(_DWORD *)(a2 + 16) + 44))(
         a1: a2 + 16,
         a2: &a1[4].dwControlsAccepted,
         a3: a1[4].dwControlsAccepted + 528,
         a4: v9);
  v10 = GASValue::ToNumber(this: v8, a2, a3: v4, result: a1);
  v5 = GASValue::ToNumber(this: v9, a2, a3: v10, result: a1);
  *a3 = v10;
  v6 = (GASValue *)&v10;
  v7 = 1;
  a3[1] = v5;
  do
  {
    v6 -= 4;
    GASValue::~GASValue(this: v6, a2: v7--);
  }
  while ( v7 >= 0 );
}

//------------------------------------------------------------------------------
// Address: 0x101270C0
// Name: public: void GASPointObject::GetProperties(class GASEnvironment __near *,class GPoint<double> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPointObject::GetProperties(_DWORD *this, _SERVICE_STATUS *a2, double *a3)
{
  unsigned int dwControlsAccepted; // edx
  int v4; // edi
  long double v5; // st7
  double v6; // st7
  GASValue *v7; // esi
  int v8; // edi
  GASValue v9[4]; // [esp+Ch] [ebp-28h] BYREF
  GASValue v10[4]; // [esp+1Ch] [ebp-18h] BYREF
  double v11; // [esp+2Ch] [ebp-8h] BYREF

  dwControlsAccepted = a2[4].dwControlsAccepted;
  v4 = (int)(this + 4);
  LOBYTE(v9[0]) = 0;
  LOBYTE(v10[0]) = 0;
  (*(void (__thiscall **)(_DWORD *, unsigned int *, unsigned int, GASValue *))(*(this + 4) + 44))(
    a1: this + 4,
    a2: &a2[4].dwControlsAccepted,
    a3: dwControlsAccepted + 524,
    a4: v9);
  v5 = ((double (__thiscall *)(int, unsigned int *, unsigned int, GASValue *))*(_DWORD *)(*(_DWORD *)v4 + 44))(
         a1: v4,
         a2: &a2[4].dwControlsAccepted,
         a3: a2[4].dwControlsAccepted + 528,
         a4: v10);
  v11 = GASValue::ToNumber(this: v9, a2: v4, a3: v5, result: a2);
  v6 = GASValue::ToNumber(this: v10, a2: v4, a3: v11, result: a2);
  *a3 = v11;
  v7 = (GASValue *)&v11;
  v8 = 1;
  a3[1] = v6;
  do
  {
    v7 -= 4;
    GASValue::~GASValue(this: v7, a2: v8--);
  }
  while ( v8 >= 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10127150
// Name: public: static void GASPointProto::Equals(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASPointProto::Equals(int a1@<edi>, GASFnCall *a2)
{
  bool v2; // bl
  GASValue *v3; // eax
  struct GASObject *v4; // eax
  GASFnCall v5; // eax
  int *p_cxItem; // ecx
  GASFnCall v7; // esi
  const struct GASEnvironment *v8; // [esp-4h] [ebp-30h]
  int v9[2]; // [esp+Ch] [ebp-20h] BYREF
  double v10; // [esp+14h] [ebp-18h]
  int v11[2]; // [esp+1Ch] [ebp-10h] BYREF
  double v12; // [esp+24h] [ebp-8h]

  v2 = false;
  if ( (int)a2[7] > 0 )
  {
    v8 = (const struct GASEnvironment *)a2[6];
    v3 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
    v4 = GASValue::ToObject(this: v3, a2: a1, a3: v8);
    a1 = (int)v4;
    if ( v4 != nullptr && ((int (__thiscall *)(struct GASObject *))v4[2].pNode[1].pNext)(a1: &v4[2]) == 16 )
    {
      if ( !GASFnCall::CheckThisPtr(this: a2, type: 0x10u) )
      {
        GASFnCall::ThisPtrError(this: a2, a2: "Point", a3: nullptr, a4: 0);
        return;
      }
      v5 = a2[2];
      if ( v5 != nullptr )
        p_cxItem = &v5[-1].cxItem;
      else
        p_cxItem = nullptr;
      GASPointObject::GetProperties(this: p_cxItem, a2: (_SERVICE_STATUS *)a2[6], a3: (double *)v11);
      GFxObject_GetPointProperties(a1: (_SERVICE_STATUS *)a2[6], a2: a1, a3: (double *)v9);
      v2 = *(double *)v9 == *(double *)v11 && v10 == v12;
    }
  }
  v7 = a2[1];
  GASValue::DropRefs(this: (GASValue *)v7, a2: a1);
  LOBYTE(v7->cItems) = v2;
  LOBYTE(v7->cbSize) = 2;
}

//------------------------------------------------------------------------------
// Address: 0x10127220
// Name: public: static void GASPointProto::Offset(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASPointProto::Offset(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // edi
  bool v4; // cc
  tagWNDCLASSW *v5; // eax
  tagWNDCLASSW *v6; // eax
  double v7; // st7
  double v8; // st7
  GASFnCall v9; // edx
  _SERVICE_STATUS *v10; // [esp-8h] [ebp-3Ch]
  GASValue v11[4]; // [esp+4h] [ebp-30h] BYREF
  GASValue v12[4]; // [esp+14h] [ebp-20h] BYREF
  int v13[2]; // [esp+24h] [ebp-10h] BYREF
  double v14; // [esp+2Ch] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x10u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = (int)a2[7] <= 0;
    LOBYTE(v11[0]) = 0;
    LOBYTE(v12[0]) = 0;
    if ( !v4 )
    {
      v5 = (tagWNDCLASSW *)GASFnCall::Arg(this: a2, a2: 0);
      GASValue::operator=(this: (int)v11, v: v5);
      if ( (int)a2[7] > 1 )
      {
        v6 = (tagWNDCLASSW *)GASFnCall::Arg(this: a2, a2: 1);
        GASValue::operator=(this: (int)v12, v: v6);
      }
    }
    GASPointObject::GetProperties(this: p_cxItem, a2: (_SERVICE_STATUS *)a2[6], a3: (double *)v13);
    v7 = GASValue::ToNumber(this: v11, a2: (int)p_cxItem, a3: a1, result: (_SERVICE_STATUS *)a2[6]);
    v10 = (_SERVICE_STATUS *)a2[6];
    *(double *)v13 = v7 + *(double *)v13;
    v8 = GASValue::ToNumber(this: v12, a2: (int)p_cxItem, a3: *(long double *)v13, result: v10);
    v9 = a2[6];
    v14 = v8 + v14;
    GASPointObject::SetProperties(this: p_cxItem, a2: (int)v9, a3: (double *)v13);
    GASValue::~GASValue(this: v12, a2: (int)p_cxItem);
    GASValue::~GASValue(this: v11, a2: (int)p_cxItem);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Point", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101272F0
// Name: public: static void GASPointProto::ToString(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASPointProto::ToString(GASFnCall *a1)
{
  GASFnCall v1; // eax
  int *p_cxItem; // ebx
  GASFnCall v3; // esi
  unsigned int cbSize; // edx
  struct GASStringNode *StringNode; // esi
  GASFnCall v6; // edi
  bool v7; // zf
  void *v8; // esi
  int *v9; // esi
  int i; // edi
  int v11; // ecx
  GASValue *v12; // esi
  int j; // edi
  unsigned __int8 v14[16]; // [esp+4h] [ebp-2Ch] BYREF
  unsigned __int8 v15[16]; // [esp+14h] [ebp-1Ch] BYREF
  CImagePacker **v16; // [esp+24h] [ebp-Ch] BYREF
  CImagePacker **v17; // [esp+28h] [ebp-8h] BYREF
  int v18; // [esp+2Ch] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x10u) )
  {
    v1 = a1[2];
    if ( v1 != nullptr )
    {
      p_cxItem = &v1[-1].cxItem;
      if ( v1 != (GASFnCall)16 )
      {
        v3 = a1[6];
        v14[0] = 0;
        v15[0] = 0;
        cbSize = v3[3].cbSize;
        v3 += 3;
        (*(void (__thiscall **)(GASFnCall, GASFnCall, unsigned int, unsigned __int8 *))(v1->cbSize + 44))(
          a1: v1,
          a2: v3,
          a3: cbSize + 524,
          a4: v14);
        (*(void (__thiscall **)(char *, GASFnCall, unsigned int, unsigned __int8 *))(p_cxItem[4] + 44))(
          a1: (char *)p_cxItem + 16,
          a2: v3,
          a3: v3->cbSize + 528,
          a4: v15);
        GASValue::ToStringImpl(
          this: v14,
          a2: (int *)&v16,
          a3: (tagRID_DEVICE_INFO_KEYBOARD *)a1[6],
          precision: 6,
          debug: false);
        GASValue::ToStringImpl(
          this: v15,
          a2: (int *)&v17,
          a3: (tagRID_DEVICE_INFO_KEYBOARD *)a1[6],
          precision: 6,
          debug: false);
        GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v18);
        GString::AppendString(
          this: (CUtlMemory<CImagePacker,int> *)&v18,
          putf8str: (CImagePacker *)"(x=",
          utf8StrSz: -1);
        GString::AppendString(this: (CUtlMemory<CImagePacker,int> *)&v18, putf8str: *v16, utf8StrSz: -1);
        GString::AppendString(
          this: (CUtlMemory<CImagePacker,int> *)&v18,
          putf8str: (CImagePacker *)", y=",
          utf8StrSz: -1);
        GString::AppendString(this: (CUtlMemory<CImagePacker,int> *)&v18, putf8str: *v17, utf8StrSz: -1);
        GString::AppendString(this: (CUtlMemory<CImagePacker,int> *)&v18, putf8str: (CImagePacker *)")", utf8StrSz: -1);
        StringNode = GASStringManager::CreateStringNode(
                       this: *(GASStringManager **)(a1[6][3].cbSize + 636),
                       result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((v18 & 0xFFFFFFFC) + 8),
                       length: *(_DWORD *)(v18 & 0xFFFFFFFC) & 0x7FFFFFFF);
        ++*((_DWORD *)StringNode + 2);
        v6 = a1[1];
        if ( LOBYTE(v6->cbSize) >= 5u )
          GASValue::DropRefs(this: (GASValue *)v6, a2: (int)v6);
        LOBYTE(v6->cbSize) = 5;
        v6->cItems = (int)StringNode;
        v7 = ++*((_DWORD *)StringNode + 2) == 1;
        --*((_DWORD *)StringNode + 2);
        if ( v7 )
          GASStringNode::ReleaseNode(a1: (int)StringNode);
        v8 = (void *)(v18 & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v18 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
        v9 = &v18;
        for ( i = 1; i >= 0; --i )
        {
          v11 = *--v9;
          v7 = (*(_DWORD *)(v11 + 8))-- == 1;
          if ( v7 )
            GASStringNode::ReleaseNode(a1: v11);
        }
        v12 = (GASValue *)&v16;
        for ( j = 1; j >= 0; --j )
        {
          v12 -= 4;
          GASValue::~GASValue(this: v12, a2: j);
        }
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: "Point", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127570
// Name: public: virtual bool GASPointObject::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASPointObject::GetMember(
        D3DXQUATERNION *this,
        D3DXQUATERNION *result,
        _IMAGE_SYMBOL_EX *name,
        struct GASValue *a4)
{
  unsigned int Short; // edi
  int v6[2]; // [esp+8h] [ebp-20h] BYREF
  double v7; // [esp+10h] [ebp-18h]
  GASValue v8; // [esp+18h] [ebp-10h] BYREF
  long double v9; // [esp+1Ch] [ebp-Ch]

  Short = name->N.Name.Short;
  if ( name->N.Name.Short != *(_DWORD *)(LODWORD(result[7].z) + 632) )
    return (unsigned __int8)GASObject::GetMember(this, (ID3DXFont *)result, penv: name, val: (int *)a4);
  GASPointObject::GetProperties(this: (_DWORD *)this - 4, a2: (_SERVICE_STATUS *)result, a3: (double *)v6);
  LOBYTE(v8) = 3;
  v9 = sqrt(*(double *)v6 * *(double *)v6 + v7 * v7);
  GASValue::operator=(this: (int)a4, v: (tagWNDCLASSW *)&v8);
  GASValue::~GASValue(this: &v8, a2: Short);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101275F0
// Name: public: static void GASPointProto::Normalize(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASPointProto::Normalize(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // edi
  tagWNDCLASSW *v4; // eax
  long double v5; // st7
  GASFnCall v6; // esi
  unsigned int cbSize; // ecx
  void (__thiscall *v8)(int *, GASFnCall, unsigned int, char *, char *); // edx
  void (__thiscall *v9)(int *, GASFnCall, int, char *, char *); // eax
  int v10; // [esp-10h] [ebp-40h]
  GASFnCall v11; // [esp-Ch] [ebp-3Ch]
  GASValue v12[4]; // [esp+4h] [ebp-2Ch] BYREF
  int v13[2]; // [esp+14h] [ebp-1Ch] BYREF
  long double v14; // [esp+1Ch] [ebp-14h]
  double v15; // [esp+24h] [ebp-Ch]
  char v16; // [esp+2Fh] [ebp-1h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x10u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    if ( (int)a2[7] <= 0 )
    {
      v6 = a2[6];
      cbSize = v6[3].cbSize;
      v8 = *(void (__thiscall **)(int *, GASFnCall, unsigned int, char *, char *))(p_cxItem[4] + 40);
      v6 += 3;
      v16 = 0;
      v8(a1: p_cxItem + 4, a2: v6, a3: cbSize + 524, a4: &GFxPoint_NanParams, a5: &v16);
      v9 = *(void (__thiscall **)(int *, GASFnCall, int, char *, char *))(p_cxItem[4] + 40);
      v10 = v6->cbSize + 528;
      v16 = 0;
      v9(a1: p_cxItem + 4, a2: v6, a3: v10, a4: &byte_10359854, a5: &v16);
    }
    else
    {
      v4 = (tagWNDCLASSW *)GASFnCall::Arg(this: a2, a2: 0);
      GASValue::GASValue(this: v12, v: v4);
      GASPointObject::GetProperties(this: p_cxItem, a2: (_SERVICE_STATUS *)a2[6], a3: (double *)v13);
      v15 = GASValue::ToNumber(this: v12, a2: (int)p_cxItem, a3: a1, result: (_SERVICE_STATUS *)a2[6]);
      v5 = v15 / sqrt(*(double *)v13 * *(double *)v13 + v14 * v14);
      v11 = a2[6];
      *(double *)v13 = *(double *)v13 * v5;
      v14 = v5 * v14;
      GASPointObject::SetProperties(this: p_cxItem, a2: (int)v11, a3: (double *)v13);
      GASValue::~GASValue(this: v12, a2: (int)p_cxItem);
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Point", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127700
// Name: public: GASPointObject::GASPointObject(class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> *__thiscall GASPointObject::GASPointObject(
        int this,
        CTSQueue<CFunctor *,0,1>::Node_t *result)
{
  CTSQueue<CFunctor *,0,1>::Node_t *v2; // edi
  vc_attributes::PreRangeAttribute *pNext; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  void (__thiscall *v6)(int, CTSQueue<CFunctor *,0,1>::Node_t *, int, void *, char *); // eax
  void (__thiscall *v7)(int, CTSQueue<CFunctor *,0,1>::Node_t *, int, void *, char *); // edx
  int p_elem; // [esp-Ch] [ebp-18h]
  int v10; // [esp-Ch] [ebp-18h]

  v2 = result;
  GASObject::GASObject((GASObject *)this, a2: (struct GASEnvironment *)result);
  *(_DWORD *)this = &GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &GASPointObject::`vftable'{for `GASObjectInterface'};
  pNext = (vc_attributes::PreRangeAttribute *)v2[15].pNext;
  v2 += 15;
  Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                    this: pNext,
                                                    result: (vc_attributes::InvalidCheckAttribute *)0xE);
  GASObject::Set__proto__(this: (CTSQueue<CFunctor *,0,1> *)(this + 16), psc: v2, psc_4: Prototype);
  v6 = *(void (__thiscall **)(int, CTSQueue<CFunctor *,0,1>::Node_t *, int, void *, char *))(*(_DWORD *)(this + 16) + 40);
  p_elem = (int)&v2->pNext[65].elem;
  HIBYTE(result) = 0;
  v6(a1: this + 16, a2: v2, a3: p_elem, a4: &GFxPoint_DefaultParams, a5: (char *)&result + 3);
  v7 = *(void (__thiscall **)(int, CTSQueue<CFunctor *,0,1>::Node_t *, int, void *, char *))(*(_DWORD *)(this + 16) + 40);
  v10 = (int)&v2->pNext[66];
  HIBYTE(result) = 0;
  v7(a1: this + 16, a2: v2, a3: v10, a4: &unk_103305A8, a5: (char *)&result + 3);
  return (GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> *)this;
}

//------------------------------------------------------------------------------
// Address: 0x10127790
// Name: public: static void GASPointProto::Add(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASPointProto::Add(int a1@<edi>, int a2)
{
  GASFnCall *v2; // esi
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // edx
  int v5; // eax
  struct GASObject *v6; // ebx
  GASValue *v7; // eax
  struct GASObject *v8; // edi
  GASFnCall v9; // eax
  int *p_cxItem; // ecx
  int v11; // eax
  struct GASObject *v12; // edi
  CTSQueue<CFunctor *,0,1>::Node_t *pNode; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // edx
  CTSQueue<CFunctor *,0,1>::Node_t *v15; // eax
  int v16; // [esp-Ch] [ebp-3Ch]
  const struct GASEnvironment *v17; // [esp-4h] [ebp-34h]
  int v18[2]; // [esp+Ch] [ebp-24h] BYREF
  double v19; // [esp+14h] [ebp-1Ch]
  int v20[2]; // [esp+1Ch] [ebp-14h] BYREF
  double v21; // [esp+24h] [ebp-Ch]
  struct GASObject *v22; // [esp+2Ch] [ebp-4h]

  v2 = (GASFnCall *)a2;
  v3 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 24) + 120) + 656);
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  a2 = 323;
  v5 = v4(a1: v3, a2: 52, a3: &a2);
  if ( v5 != 0 )
  {
    v6 = (struct GASObject *)GASPointObject::GASPointObject(this: v5, result: (CTSQueue<CFunctor *,0,1>::Node_t *)v2[6]);
    v22 = v6;
  }
  else
  {
    v22 = nullptr;
    v6 = nullptr;
  }
  if ( (int)v2[7] > 0
    && (v17 = (const struct GASEnvironment *)v2[6],
        v7 = (GASValue *)GASFnCall::Arg(this: v2, a2: 0),
        (v8 = GASValue::ToObject(this: v7, a2: a1, a3: v17)) != nullptr) )
  {
    if ( !GASFnCall::CheckThisPtr(this: v2, type: 0x10u) )
    {
      GASFnCall::ThisPtrError(this: v2, a2: "Point", a3: nullptr, a4: 0);
      goto LABEL_14;
    }
    v9 = v2[2];
    if ( v9 != nullptr )
      p_cxItem = &v9[-1].cxItem;
    else
      p_cxItem = nullptr;
    GASPointObject::GetProperties(this: p_cxItem, a2: (_SERVICE_STATUS *)v2[6], a3: (double *)v20);
    GFxObject_GetPointProperties(a1: (_SERVICE_STATUS *)v2[6], a2: (int)v8, a3: (double *)v18);
    v11 = (int)v2[6];
    *(double *)v20 = *(double *)v20 + *(double *)v18;
    v21 = v21 + v19;
    GASPointObject::SetProperties(this: (int *)v6, a2: v11, a3: (double *)v20);
  }
  else
  {
    v12 = (struct GASObject *)v2[6];
    pNode = v12[15].pNode;
    pNext = v6[2].pNode[5].pNext;
    v8 = v12 + 15;
    HIBYTE(a2) = 0;
    ((void (__thiscall *)(struct GASObject *, struct GASObject *, CFunctor **, char *, char *))pNext)(
      a1: &v6[2],
      a2: v8,
      a3: &pNode[65].elem,
      a4: &GFxPoint_NanParams,
      a5: (char *)&a2 + 3);
    v15 = v6[2].pNode[5].pNext;
    v16 = (int)&v8->pNode[66];
    HIBYTE(a2) = 0;
    ((void (__thiscall *)(struct GASObject *, struct GASObject *, int, char *, char *))v15)(
      a1: &v6[2],
      a2: v8,
      a3: v16,
      a4: &byte_10359854,
      a5: (char *)&a2 + 3);
    v6 = v22;
  }
  GASValue::SetAsObject(this: (GASValue *)v2[1], a2: v6);
LABEL_14:
  if ( v6 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v6, a2: (int)v8);
}

//------------------------------------------------------------------------------
// Address: 0x101278E0
// Name: public: static void GASPointProto::Clone(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASPointProto::Clone(int a1@<edi>, int a2@<esi>, GASFnCall *a3)
{
  GASFnCall v3; // eax
  int *p_cxItem; // edi
  int v5; // ecx
  int (__thiscall *v6)(int, int, struct GASObject **, int, int); // edx
  int v7; // eax
  GASFnCall v8; // esi
  struct GASObject *v9; // edi
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // edx
  CTSQueue<CFunctor *,0,1>::Node_t *v11; // edx
  struct GASObject **v12; // esi
  int i; // ebx
  int v14; // [esp-14h] [ebp-40h]
  int v15; // [esp-14h] [ebp-40h]
  char v17[16]; // [esp+4h] [ebp-28h] BYREF
  _BYTE v18[16]; // [esp+14h] [ebp-18h] BYREF
  struct GASObject *v19; // [esp+24h] [ebp-8h] BYREF
  char v20; // [esp+2Bh] [ebp-1h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a3, type: 0x10u) )
  {
    v3 = a3[2];
    if ( v3 != nullptr )
      p_cxItem = &v3[-1].cxItem;
    else
      p_cxItem = nullptr;
    v5 = *(_DWORD *)(a3[6][3].cbSize + 656);
    v6 = *(int (__thiscall **)(int, int, struct GASObject **, int, int))(*(_DWORD *)v5 + 40);
    v19 = (struct GASObject *)323;
    v7 = v6(a1: v5, a2: 52, a3: &v19, a4: a1, a5: a2);
    if ( v7 != 0 )
      v19 = (struct GASObject *)GASPointObject::GASPointObject(
                                  this: v7,
                                  result: (CTSQueue<CFunctor *,0,1>::Node_t *)a3[6]);
    else
      v19 = nullptr;
    v8 = a3[6] + 3;
    v17[0] = 0;
    v18[0] = 0;
    (*(void (__thiscall **)(char *, GASFnCall))(p_cxItem[4] + 44))(a1: (char *)p_cxItem + 16, a2: v8);
    (*(void (__thiscall **)(char *, GASFnCall, unsigned int, _BYTE *))(p_cxItem[4] + 44))(
      a1: (char *)p_cxItem + 16,
      a2: v8,
      a3: v8->cbSize + 528,
      a4: v18);
    v9 = v19;
    pNext = v19[2].pNode[5].pNext;
    v14 = v8->cbSize + 524;
    v20 = 0;
    ((void (__thiscall *)(struct GASObject *, GASFnCall, int, char *, char *))pNext)(
      a1: &v19[2],
      a2: v8,
      a3: v14,
      a4: v17,
      a5: &v20);
    v11 = v9[2].pNode[5].pNext;
    v15 = v8->cbSize + 528;
    v20 = 0;
    ((void (__thiscall *)(struct GASObject *, GASFnCall, int, _BYTE *, char *))v11)(
      a1: &v9[2],
      a2: v8,
      a3: v15,
      a4: v18,
      a5: &v20);
    GASValue::SetAsObject(this: (GASValue *)a3[1], a2: v9);
    v12 = &v19;
    for ( i = 1; i >= 0; --i )
    {
      v12 -= 4;
      GASValue::~GASValue(this: (GASValue *)v12, a2: (int)v9);
    }
    GRefCountBaseGC<323>::Release(a1: (int)v9, a2: (int)v9);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a3, a2: "Point", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127A10
// Name: public: static void GASPointProto::Subtract(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASPointProto::Subtract(int a1@<edi>, int a2)
{
  GASFnCall *v2; // esi
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // edx
  int v5; // eax
  struct GASObject *v6; // ebx
  GASValue *v7; // eax
  struct GASObject *v8; // edi
  GASFnCall v9; // eax
  int *p_cxItem; // ecx
  int v11; // eax
  struct GASObject *v12; // edi
  CTSQueue<CFunctor *,0,1>::Node_t *pNode; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // edx
  CTSQueue<CFunctor *,0,1>::Node_t *v15; // eax
  int v16; // [esp-Ch] [ebp-3Ch]
  const struct GASEnvironment *v17; // [esp-4h] [ebp-34h]
  int v18[2]; // [esp+Ch] [ebp-24h] BYREF
  double v19; // [esp+14h] [ebp-1Ch]
  int v20[2]; // [esp+1Ch] [ebp-14h] BYREF
  double v21; // [esp+24h] [ebp-Ch]
  struct GASObject *v22; // [esp+2Ch] [ebp-4h]

  v2 = (GASFnCall *)a2;
  v3 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 24) + 120) + 656);
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  a2 = 323;
  v5 = v4(a1: v3, a2: 52, a3: &a2);
  if ( v5 != 0 )
  {
    v6 = (struct GASObject *)GASPointObject::GASPointObject(this: v5, result: (CTSQueue<CFunctor *,0,1>::Node_t *)v2[6]);
    v22 = v6;
  }
  else
  {
    v22 = nullptr;
    v6 = nullptr;
  }
  if ( (int)v2[7] > 0
    && (v17 = (const struct GASEnvironment *)v2[6],
        v7 = (GASValue *)GASFnCall::Arg(this: v2, a2: 0),
        (v8 = GASValue::ToObject(this: v7, a2: a1, a3: v17)) != nullptr) )
  {
    if ( !GASFnCall::CheckThisPtr(this: v2, type: 0x10u) )
    {
      GASFnCall::ThisPtrError(this: v2, a2: "Point", a3: nullptr, a4: 0);
      goto LABEL_14;
    }
    v9 = v2[2];
    if ( v9 != nullptr )
      p_cxItem = &v9[-1].cxItem;
    else
      p_cxItem = nullptr;
    GASPointObject::GetProperties(this: p_cxItem, a2: (_SERVICE_STATUS *)v2[6], a3: (double *)v20);
    GFxObject_GetPointProperties(a1: (_SERVICE_STATUS *)v2[6], a2: (int)v8, a3: (double *)v18);
    v11 = (int)v2[6];
    *(double *)v20 = *(double *)v20 - *(double *)v18;
    v21 = v21 - v19;
    GASPointObject::SetProperties(this: (int *)v6, a2: v11, a3: (double *)v20);
  }
  else
  {
    v12 = (struct GASObject *)v2[6];
    pNode = v12[15].pNode;
    pNext = v6[2].pNode[5].pNext;
    v8 = v12 + 15;
    HIBYTE(a2) = 0;
    ((void (__thiscall *)(struct GASObject *, struct GASObject *, CFunctor **, char *, char *))pNext)(
      a1: &v6[2],
      a2: v8,
      a3: &pNode[65].elem,
      a4: &GFxPoint_NanParams,
      a5: (char *)&a2 + 3);
    v15 = v6[2].pNode[5].pNext;
    v16 = (int)&v8->pNode[66];
    HIBYTE(a2) = 0;
    ((void (__thiscall *)(struct GASObject *, struct GASObject *, int, char *, char *))v15)(
      a1: &v6[2],
      a2: v8,
      a3: v16,
      a4: &byte_10359854,
      a5: (char *)&a2 + 3);
    v6 = v22;
  }
  GASValue::SetAsObject(this: (GASValue *)v2[1], a2: v6);
LABEL_14:
  if ( v6 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v6, a2: (int)v8);
}

//------------------------------------------------------------------------------
// Address: 0x10127B60
// Name: protected: static void GASPointCtorFunction::Interpolate(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASPointCtorFunction::Interpolate(int a1@<edi>, long double a2@<st0>, int result)
{
  SIMDRandStreamContext *v3; // esi
  int v4; // ecx
  int (__thiscall *v5)(int, int, int *); // edx
  int v6; // eax
  struct GASObject *v7; // ebx
  bool v8; // cc
  GASValue *v9; // eax
  struct GASObject *v10; // edi
  GASValue *v11; // eax
  tagWNDCLASSW *v12; // eax
  double v13; // st7
  _DWORD *v14; // edi
  int v15; // edx
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *v17; // edx
  int v18; // [esp-10h] [ebp-60h]
  int v19; // [esp-Ch] [ebp-5Ch]
  const struct GASEnvironment *v20; // [esp-8h] [ebp-58h]
  const struct GASEnvironment *v21; // [esp-8h] [ebp-58h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *f; // [esp+8h] [ebp-48h] BYREF
  double v24[2]; // [esp+18h] [ebp-38h] BYREF
  int v25[2]; // [esp+28h] [ebp-28h] BYREF
  double v26; // [esp+30h] [ebp-20h]
  int v27[2]; // [esp+38h] [ebp-18h] BYREF
  double v28; // [esp+40h] [ebp-10h]
  int v29; // [esp+48h] [ebp-8h]
  struct GASObject *v30; // [esp+4Ch] [ebp-4h]

  v3 = (SIMDRandStreamContext *)result;
  v4 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(result + 24) + 120) + 656);
  v5 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v4 + 40);
  result = 323;
  v6 = v5(a1: v4, a2: 52, a3: &result);
  if ( v6 != 0 )
  {
    v7 = (struct GASObject *)GASPointObject::GASPointObject(
                               this: v6,
                               result: (CTSQueue<CFunctor *,0,1>::Node_t *)v3->m_RandY[1].m128_i32[2]);
    v30 = v7;
  }
  else
  {
    v30 = nullptr;
    v7 = nullptr;
  }
  v8 = v3->m_RandY[1].m128_i32[3] <= 2;
  HIBYTE(result) = 0;
  if ( v8 )
    goto LABEL_9;
  v20 = (const struct GASEnvironment *)v3->m_RandY[1].m128_i32[2];
  v9 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v3, a2: 0);
  v10 = GASValue::ToObject(this: v9, a2: a1, a3: v20);
  v21 = (const struct GASEnvironment *)v3->m_RandY[1].m128_i32[2];
  v11 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v3, a2: 1);
  v29 = (int)GASValue::ToObject(this: v11, a2: (int)v10, a3: v21);
  v12 = (tagWNDCLASSW *)GASFnCall::Arg(this: (GASFnCall *)v3, a2: 2);
  GASValue::GASValue(this: &f, v: v12);
  if ( v10 != nullptr && v29 != 0 )
  {
    GFxObject_GetPointProperties(a1: (_SERVICE_STATUS *)v3->m_RandY[1].m128_i32[2], a2: (int)v10, a3: (double *)v27);
    GFxObject_GetPointProperties(a1: (_SERVICE_STATUS *)v3->m_RandY[1].m128_i32[2], a2: v29, a3: (double *)v25);
    v13 = GASValue::ToNumber(this: &f, a2: (int)v10, a3: a2, result: (_SERVICE_STATUS *)v3->m_RandY[1].m128_i32[2]);
    v19 = v3->m_RandY[1].m128_i32[2];
    v24[0] = *(double *)v25 + (*(double *)v27 - *(double *)v25) * v13;
    v24[1] = v13 * (v28 - v26) + v26;
    GASPointObject::SetProperties(this: (int *)v7, a2: v19, a3: v24);
    HIBYTE(result) = 1;
  }
  GASValue::~GASValue(this: &f, a2: (int)v10);
  if ( HIBYTE(result) == 0 )
  {
LABEL_9:
    v14 = (_DWORD *)v3->m_RandY[1].m128_i32[2];
    v15 = v14[30];
    pNext = v7[2].pNode[5].pNext;
    v14 += 30;
    HIBYTE(result) = 0;
    ((void (__thiscall *)(struct GASObject *, _DWORD *, int, char *, char *))pNext)(
      a1: &v7[2],
      a2: v14,
      a3: v15 + 524,
      a4: &GFxPoint_NanParams,
      a5: (char *)&result + 3);
    v17 = v7[2].pNode[5].pNext;
    v18 = *v14 + 528;
    HIBYTE(result) = 0;
    ((void (__thiscall *)(struct GASObject *, _DWORD *, int, char *, char *))v17)(
      a1: &v7[2],
      a2: v14,
      a3: v18,
      a4: &byte_10359854,
      a5: (char *)&result + 3);
    v7 = v30;
  }
  GASValue::SetAsObject(this: (GASValue *)v3->m_RandY[0].m128_i32[1], a2: v7);
  if ( v7 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v7, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10127CE0
// Name: protected: static void GASPointCtorFunction::Polar(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASPointCtorFunction::Polar(int a1@<edi>, long double a2@<st0>, int result)
{
  SIMDRandStreamContext *v3; // esi
  int v4; // ecx
  int (__thiscall *v5)(int, int, int *); // edx
  int v6; // eax
  struct GASObject *v7; // ebx
  tagWNDCLASSW *v8; // eax
  tagWNDCLASSW *v9; // eax
  int v10; // edx
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // eax
  _DWORD *v12; // edi
  int v13; // edx
  CTSQueue<CFunctor *,0,1>::Node_t *v14; // edx
  int v15; // [esp-10h] [ebp-58h]
  int v16; // [esp-4h] [ebp-4Ch]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *length; // [esp+8h] [ebp-40h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *angle; // [esp+18h] [ebp-30h] BYREF
  double v19[2]; // [esp+28h] [ebp-20h] BYREF
  double a; // [esp+38h] [ebp-10h]
  double l; // [esp+40h] [ebp-8h]

  v3 = (SIMDRandStreamContext *)result;
  v4 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(result + 24) + 120) + 656);
  v5 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v4 + 40);
  result = 323;
  v6 = v5(a1: v4, a2: 52, a3: &result);
  if ( v6 != 0 )
  {
    v7 = (struct GASObject *)GASPointObject::GASPointObject(
                               this: v6,
                               result: (CTSQueue<CFunctor *,0,1>::Node_t *)v3->m_RandY[1].m128_i32[2]);
    HIDWORD(l) = v7;
  }
  else
  {
    HIDWORD(l) = 0;
    v7 = nullptr;
  }
  if ( v3->m_RandY[1].m128_i32[3] <= 1 )
  {
    pNext = v7[2].pNode[5].pNext;
    v16 = a1;
    v12 = (_DWORD *)v3->m_RandY[1].m128_i32[2];
    v13 = v12[30];
    v12 += 30;
    HIBYTE(result) = 0;
    ((void (__thiscall *)(struct GASObject *, _DWORD *, int, char *, char *))pNext)(
      a1: &v7[2],
      a2: v12,
      a3: v13 + 524,
      a4: &GFxPoint_NanParams,
      a5: (char *)&result + 3);
    v14 = v7[2].pNode[5].pNext;
    v15 = *v12 + 528;
    HIBYTE(result) = 0;
    ((void (__thiscall *)(struct GASObject *, _DWORD *, int, char *, char *))v14)(
      a1: &v7[2],
      a2: v12,
      a3: v15,
      a4: &byte_10359854,
      a5: (char *)&result + 3);
    v7 = (struct GASObject *)HIDWORD(l);
    a1 = v16;
  }
  else
  {
    v8 = (tagWNDCLASSW *)GASFnCall::Arg(this: (GASFnCall *)v3, a2: 0);
    GASValue::GASValue(this: &length, v: v8);
    v9 = (tagWNDCLASSW *)GASFnCall::Arg(this: (GASFnCall *)v3, a2: 1);
    GASValue::GASValue(this: &angle, v: v9);
    l = GASValue::ToNumber(this: &length, a2: a1, a3: a2, result: (_SERVICE_STATUS *)v3->m_RandY[1].m128_i32[2]);
    a = GASValue::ToNumber(this: &angle, a2: a1, a3: l, result: (_SERVICE_STATUS *)v3->m_RandY[1].m128_i32[2]);
    v19[0] = cos(a) * l;
    v10 = v3->m_RandY[1].m128_i32[2];
    v19[1] = sin(a) * l;
    GASPointObject::SetProperties(this: (int *)v7, a2: v10, a3: v19);
    GASValue::~GASValue(this: &angle, a2: a1);
    GASValue::~GASValue(this: &length, a2: a1);
  }
  GASValue::SetAsObject(this: (GASValue *)v3->m_RandY[0].m128_i32[1], a2: v7);
  if ( v7 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v7, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10127E20
// Name: public: static void GASPointCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASPointCtorFunction::GlobalCtor(int a1@<edi>, int result)
{
  SIMDRandStreamContext *v2; // esi
  int v3; // eax
  struct GASObject *v4; // eax
  int v5; // ecx
  int (__thiscall *v6)(int, int, int *); // edx
  int v7; // eax
  int v8; // ebx
  tagWNDCLASSW *v9; // eax
  tagWNDCLASSW *v10; // eax
  _DWORD *v11; // esi
  void (__thiscall *v12)(int, _DWORD *, int, _BYTE *, char *); // edx
  int v13; // eax
  void (__thiscall *v14)(int, _DWORD *, int, _BYTE *, char *); // edx
  GASValue *v15; // esi
  int i; // edi
  int v17; // [esp-10h] [ebp-38h]
  int v18; // [esp-4h] [ebp-2Ch]
  _BYTE v19[16]; // [esp+8h] [ebp-20h] BYREF
  _BYTE v20[16]; // [esp+18h] [ebp-10h] BYREF
  char vars0; // [esp+28h] [ebp+0h] BYREF

  v2 = (SIMDRandStreamContext *)result;
  if ( *(_DWORD *)(result + 8) == 0
    || (*(int (__thiscall **)(int))(**(_DWORD **)(result + 8) + 8))(a1: *(_DWORD *)(result + 8)) != 16
    || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v2->m_RandY[0].m128_i32[2] + 64))(a1: v2->m_RandY[0].m128_i32[2]) != 0 )
  {
    v5 = *(_DWORD *)(*(_DWORD *)(v2->m_RandY[1].m128_i32[2] + 120) + 656);
    v6 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v5 + 40);
    result = 323;
    v7 = v6(a1: v5, a2: 52, a3: &result);
    if ( v7 != 0 )
    {
      v4 = (struct GASObject *)GASPointObject::GASPointObject(
                                 this: v7,
                                 result: (CTSQueue<CFunctor *,0,1>::Node_t *)v2->m_RandY[1].m128_i32[2]);
      goto LABEL_10;
    }
    goto LABEL_9;
  }
  v3 = v2->m_RandY[0].m128_i32[2];
  if ( v3 == 0 )
  {
LABEL_9:
    v4 = nullptr;
    goto LABEL_10;
  }
  v4 = (struct GASObject *)(v3 - 16);
  if ( v4 != nullptr )
    v4[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v4[1].pNode->pNext + 1) & 0x8FFFFFFF);
LABEL_10:
  v8 = (int)v4;
  GASValue::SetAsObject(this: (GASValue *)v2->m_RandY[0].m128_i32[1], a2: v4);
  if ( v2->m_RandY[1].m128_i32[3] > 0 )
  {
    v19[0] = 0;
    v20[0] = 0;
    v9 = (tagWNDCLASSW *)GASFnCall::Arg(this: (GASFnCall *)v2, a2: 0);
    GASValue::operator=(this: (int)v19, v: v9);
    if ( v2->m_RandY[1].m128_i32[3] > 1 )
    {
      v10 = (tagWNDCLASSW *)GASFnCall::Arg(this: (GASFnCall *)v2, a2: 1);
      GASValue::operator=(this: (int)v20, v: v10);
    }
    v11 = (_DWORD *)v2->m_RandY[1].m128_i32[2];
    v12 = *(void (__thiscall **)(int, _DWORD *, int, _BYTE *, char *))(*(_DWORD *)(v8 + 16) + 40);
    v18 = a1;
    v13 = v11[30];
    v11 += 30;
    HIBYTE(result) = 0;
    v12(a1: v8 + 16, a2: v11, a3: v13 + 524, a4: v19, a5: (char *)&result + 3);
    v14 = *(void (__thiscall **)(int, _DWORD *, int, _BYTE *, char *))(*(_DWORD *)(v8 + 16) + 40);
    v17 = *v11 + 528;
    HIBYTE(result) = 0;
    v14(a1: v8 + 16, a2: v11, a3: v17, a4: v20, a5: (char *)&result + 3);
    v15 = (GASValue *)&vars0;
    for ( i = 1; i >= 0; --i )
    {
      v15 -= 4;
      GASValue::~GASValue(this: v15, a2: i);
    }
    a1 = v18;
  }
  if ( v8 != 0 )
    GRefCountBaseGC<323>::Release(a1: v8, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10127F60
// Name: public: virtual class GASObject __near * GASPointCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASPointCtorFunction::CreateNewObject(const VMatrix *this, int penv)
{
  CTSQueue<CFunctor *,0,1>::Node_t *v2; // esi
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // edx
  int v5; // eax

  v2 = (CTSQueue<CFunctor *,0,1>::Node_t *)penv;
  v3 = *(_DWORD *)(*(_DWORD *)(penv + 120) + 656);
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  penv = 323;
  v5 = v4(a1: v3, a2: 52, a3: &penv);
  if ( v5 != 0 )
    GASPointObject::GASPointObject(this: v5, result: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10128020
// Name: public: GASPointProto::GASPointProto(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
vgui::ISurface *__thiscall GASPointProto::GASPointProto(
        vgui::ISurface *this,
        vgui::ISurface *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *ConstStringNode,
        const struct GASFunctionRef *a4)
{
  vgui::ISurface_vtbl *v5; // eax
  struct GASObject *v6; // eax
  GASValue v9[4]; // [esp+Ch] [ebp-10h] BYREF

  GASPrototype<GASPointObject,GASEnvironment>::GASPrototype<GASPointObject,GASEnvironment>(
    this,
    psc,
    psc_4: ConstStringNode,
    psc_8: (unsigned int)a4);
  this->__vftable = (vgui::ISurface_vtbl *)&GASPointProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPointProto::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 13) = &GASPointProto::`vftable';
  HIBYTE(a4) = 6;
  GASPrototypeBase::InitFunctionMembers(
    this: (GASPrototypeBase *)this + 13,
    a2: (int)this,
    flags: (vc_attributes::PreRangeAttribute **)psc,
    flags_4: (const struct GASNameFunction *)&GASPointProto::FunctionTable,
    flags_8: (const struct GASPropFlags *)((char *)&a4 + 3));
  v5 = psc->__vftable;
  HIBYTE(a4) = 2;
  LOBYTE(v9[0]) = 4;
  v9[1] = nullptr;
  ConstStringNode = (CTSQueue<CFunctor *,0,1>::Node_t *)GASStringManager::CreateConstStringNode(
                                                          this: (GASStringManager *)v5[1].RunFrame,
                                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_1029E390,
                                                          a3: 6u,
                                                          a4: 0);
  ++ConstStringNode[1].pNext;
  GASObject::SetMemberRaw(
    this: (GASObject *)this + 2,
    a2: (struct GASStringContext *)psc,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: v9,
    a5: (const struct GASPropFlags *)((char *)&a4 + 3));
  v6 = (struct GASObject *)ConstStringNode;
  if ( ConstStringNode[1].pNext-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1 )
    GASStringNode::ReleaseNode(a1: (int)v6);
  GASValue::~GASValue(this: v9, a2: (int)psc);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101281A0
// Name: public: static class GASFunctionRef GASPointCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__cdecl GASPointCtorFunction::Register(struct GASFunctionRef *a1, int a2)
{
  vc_attributes::PreRangeAttribute *v2; // esi
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // eax
  GASCFunctionObject *v5; // eax
  GASCFunctionObject *v6; // edi
  void *v7; // ecx
  GASCFunctionObject *v8; // eax
  const char *MaxVal; // ecx
  int (__thiscall *v11)(const char *, int, int *); // eax
  vgui::ISurface *v12; // ebx
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  vgui::ISurface *v14; // ebx
  unsigned int Deref; // eax
  GASValue *v16; // eax
  GASValue v18[4]; // [esp+Ch] [ebp-18h] BYREF
  CTSQueue<CFunctor *,0,1>::Node_t psc; // [esp+1Ch] [ebp-8h] BYREF
  struct GASFunctionRef *v20; // [esp+2Ch] [ebp+8h]

  v2 = (vc_attributes::PreRangeAttribute *)a2;
  v3 = *(_DWORD *)(a2 + 656);
  psc.pNext = (CTSQueue<CFunctor *,0,1>::Node_t *)a2;
  LOBYTE(psc.elem) = 8;
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  a2 = 323;
  v5 = (GASCFunctionObject *)v4(a1: v3, a2: 56, a3: &a2);
  v6 = v5;
  if ( v5 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v5,
      func: (_REASON_CONTEXT *)&psc,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASPointCtorFunction::GlobalCtor);
    v6->dwSize = (unsigned int)&GASPointCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v6->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    GASNameFunction::AddConstMembers(
      pobj: v7,
      psc: (int)&v6->cLineHeight,
      psca: &psc,
      a4: (struct GASObject **)&GASPointCtorFunction::StaticFunctionTable,
      a5: 7);
    v8 = v6;
  }
  else
  {
    v8 = nullptr;
  }
  *(_DWORD *)a1 = v8;
  *((_BYTE *)a1 + 8) = 0;
  *((_DWORD *)a1 + 1) = 0;
  MaxVal = v2[54].MaxVal;
  v11 = *(int (__thiscall **)(const char *, int, int *))(*(_DWORD *)MaxVal + 40);
  a2 = 323;
  v12 = (vgui::ISurface *)v11(a1: MaxVal, a2: 84, a3: &a2);
  if ( v12 != nullptr )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v2,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    v14 = GASPointProto::GASPointProto(this: v12, (vgui::ISurface *)&psc, ConstStringNode: Prototype, a4: a1);
  }
  else
  {
    v14 = nullptr;
  }
  if ( v14 != nullptr )
    v14[2].__vftable = (vgui::ISurface_vtbl *)(((int)&v14[2].Connect + 1) & 0x8FFFFFFF);
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)a1, a3: 14, a4: (int)v14);
  Deref = v2[55].Deref;
  HIBYTE(a2) = 0;
  v20 = *(struct GASFunctionRef **)(Deref + 16);
  v16 = GASValue::GASValue(this: v18, a2: (int)a1, a3: a1);
  (*((void (__thiscall **)(unsigned int, CTSQueue<CFunctor *,0,1>::Node_t *, const char **, GASValue *, char *))v20 + 10))(
    a1: v2[55].Deref + 16,
    a2: &psc,
    a3: &v2[5].MinVal,
    a4: v16,
    a5: (char *)&a2 + 3);
  GASValue::~GASValue(this: v18, a2: (int)a1);
  if ( v14 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v14, a2: (int)a1);
  return a1;
}
