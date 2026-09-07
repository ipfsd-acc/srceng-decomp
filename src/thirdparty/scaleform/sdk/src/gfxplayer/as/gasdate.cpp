// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasdate.cpp
// Functions: 50
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasdate.h"

//------------------------------------------------------------------------------
// Address: 0x1011DB10
// Name: public: virtual char const __near * GASDate::GetTextValue(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASDate::GetTextValue(GPtr<GFxAmpThreadMgr> *this, GFxAmpThreadMgr *__formal)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1011DB20
// Name: IsLeapYear
// Source: json
//------------------------------------------------------------------------------
BOOL __fastcall IsLeapYear(int a1)
{
  return a1 % 4 == 0 && (a1 % 100 != 0 || a1 % 400 == 0);
}

//------------------------------------------------------------------------------
// Address: 0x1011DB70
// Name: protected: void GASDate::UpdateLocal(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASDate::UpdateLocal(GASDate *this)
{
  int v2; // eax
  const GFxAmpThreadMgr *v3; // ebx
  const GFxAmpThreadMgr *v4; // ecx
  __int64 v5; // rax
  int v6; // edi
  int v7; // eax
  const GFxAmpThreadMgr *v8; // ebx

  v2 = (int)*(this + 25);
  v3 = *(this + 18);
  v4 = (GASDate)((char *)*(this + 16) + v2);
  v5 = *((_QWORD *)this + 7) + v2;
  v6 = (int)*(this + 17);
  *(this + 22) = v4;
  *((_QWORD *)this + 10) = v5;
  *(this + 24) = v3;
  *(this + 23) = (GASDate)v6;
  if ( (unsigned int)v4 >= 0x5265C00 )
  {
    v7 = ((int)v4 + 864000000) / 86400000 - 10;
    v8 = (const GFxAmpThreadMgr *)((char *)v3 + v7);
    *(this + 22) = (const GFxAmpThreadMgr *)((char *)v4 - 86400000 * v7);
    *(this + 24) = v8;
    LODWORD(v5) = v6 % 4 == 0 && (v6 % 100 != 0 || v6 % 400 == 0);
    if ( (int)v8 < ((_BYTE)v5 != 0) + 365 )
    {
      if ( (int)v8 < 0 )
      {
        *(this + 23) = (GASDate)(v6 - 1);
        LODWORD(v5) = IsLeapYear(a1: v6 - 1);
        *(this + 24) = (const GFxAmpThreadMgr *)((char *)v8 + ((_BYTE)v5 != 0) + 365);
      }
    }
    else
    {
      LODWORD(v5) = IsLeapYear(a1: v6);
      *(this + 23) = (GASDate)(v6 + 1);
      *(this + 24) = (const GFxAmpThreadMgr *)((char *)v8 - ((_BYTE)v5 != 0) - 365);
    }
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1011DC80
// Name: protected: void GASDate::UpdateGMT(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASDate::UpdateGMT(GASDate *this)
{
  int v2; // eax
  const GFxAmpThreadMgr *v3; // ebx
  const GFxAmpThreadMgr *v4; // ecx
  int result; // eax
  __int64 v6; // kr00_8
  int v7; // edi
  int v8; // eax
  const GFxAmpThreadMgr *v9; // ebx

  v2 = (int)*(this + 25);
  v3 = *(this + 24);
  v4 = (GASDate)((char *)*(this + 22) - v2);
  v6 = *((_QWORD *)this + 10) - v2;
  result = HIDWORD(v6);
  *(this + 14) = (GASDate)v6;
  v7 = (int)*(this + 23);
  *(this + 16) = v4;
  *(this + 15) = (GASDate)HIDWORD(v6);
  *(this + 18) = v3;
  *(this + 17) = (GASDate)v7;
  if ( (unsigned int)v4 >= 0x5265C00 )
  {
    v8 = ((int)v4 + 864000000) / 86400000 - 10;
    v9 = (const GFxAmpThreadMgr *)((char *)v3 + v8);
    *(this + 16) = (const GFxAmpThreadMgr *)((char *)v4 - 86400000 * v8);
    *(this + 18) = v9;
    result = v7 % 4 == 0 && (v7 % 100 != 0 || v7 % 400 == 0);
    if ( (int)v9 < ((_BYTE)result != 0) + 365 )
    {
      if ( (int)v9 < 0 )
      {
        *(this + 17) = (GASDate)(v7 - 1);
        result = IsLeapYear(a1: v7 - 1);
        *(this + 18) = (const GFxAmpThreadMgr *)((char *)v9 + (unsigned __int8)result);
      }
    }
    else
    {
      result = IsLeapYear(a1: v7);
      *(this + 17) = (GASDate)(v7 + 1);
      *(this + 18) = (const GFxAmpThreadMgr *)((char *)v9 - ((_BYTE)result != 0) - 365);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011DD90
// Name: public: static void GASDateProto::DateGetTimezoneOffset(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateGetTimezoneOffset(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // eax
  GASFnCall v4; // esi
  double v5; // [esp+4h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = a2[1];
    v5 = (double)(p_cxItem[25] / -60000);
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
    LOBYTE(v4->cbSize) = 3;
    *(double *)&v4->cItems = v5;
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011DE10
// Name: public: static void GASDateProto::DateGetMonth(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASDateProto::DateGetMonth(GASFnCall *a1)
{
  GASFnCall v1; // eax
  int *p_cxItem; // eax
  int v3; // ecx
  int v4; // esi
  int v5; // edi
  int v6; // ebx
  bool v7; // al
  GASFnCall v8; // esi
  GASFnCall v9; // esi
  int v10; // [esp+4h] [ebp-4h]

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x23u) )
  {
    v1 = a1[2];
    if ( v1 != nullptr )
      p_cxItem = &v1[-1].cxItem;
    else
      p_cxItem = nullptr;
    v3 = p_cxItem[23];
    v4 = 0;
    v5 = v3 % 4;
    v6 = p_cxItem[24];
    while ( 1 )
    {
      v7 = v5 == 0 && (v3 % 100 != 0 || v3 % 400 == 0);
      if ( v6 < months[12 * v7 + v4] )
        break;
      if ( ++v4 >= 12 )
      {
        v8 = a1[1];
        if ( LOBYTE(v8->cbSize) >= 5u )
          GASValue::DropRefs(this: (GASValue *)a1[1], a2: v5);
        *(double *)&v8->cItems = -1.0;
        LOBYTE(v8->cbSize) = 3;
        return;
      }
    }
    v10 = v4;
    v9 = a1[1];
    if ( LOBYTE(v9->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)a1[1], a2: v5);
    *(double *)&v9->cItems = (double)v10;
    LOBYTE(v9->cbSize) = 3;
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011DF10
// Name: public: static void GASDateProto::DateGetDate(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASDateProto::DateGetDate(GASFnCall *a1)
{
  GASFnCall v1; // eax
  int p_cxItem; // edi
  int v3; // esi
  bool v4; // al
  int v5; // ecx
  BOOL v6; // ebx
  double v7; // st7
  GASFnCall v8; // esi
  int i; // eax
  bool v10; // al
  GASFnCall v11; // esi

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x23u) )
  {
    v1 = a1[2];
    if ( v1 != nullptr )
      p_cxItem = (int)&v1[-1].cxItem;
    else
      p_cxItem = 0;
    v3 = *(_DWORD *)(p_cxItem + 92);
    v4 = IsLeapYear(a1: v3);
    v5 = *(_DWORD *)(p_cxItem + 96);
    v6 = v4;
    if ( v5 >= months[12 * v4] )
    {
      p_cxItem = 1;
      for ( i = v3 % 4; ; i = v3 % 4 )
      {
        v10 = i == 0 && (v3 % 100 != 0 || v3 % 400 == 0);
        if ( v5 < months[12 * v10 + p_cxItem] )
        {
          v8 = a1[1];
          v7 = (double)(v5 - dword_102A6374[12 * v6 + p_cxItem] + 1);
          goto LABEL_8;
        }
        if ( ++p_cxItem >= 12 )
          break;
      }
      v11 = a1[1];
      if ( LOBYTE(v11->cbSize) >= 5u )
        GASValue::DropRefs(this: (GASValue *)a1[1], a2: p_cxItem);
      *(double *)&v11->cItems = -1.0;
      LOBYTE(v11->cbSize) = 3;
    }
    else
    {
      v7 = (double)(v5 + 1);
      v8 = a1[1];
LABEL_8:
      if ( LOBYTE(v8->cbSize) >= 5u )
        GASValue::DropRefs(this: (GASValue *)v8, a2: p_cxItem);
      *(double *)&v8->cItems = v7;
      LOBYTE(v8->cbSize) = 3;
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E060
// Name: public: static void GASDateProto::DateGetDay(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateGetDay(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // eax
  GASFnCall v4; // esi
  double v5; // [esp+4h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = a2[1];
    v5 = (double)((int)(*((_QWORD *)p_cxItem + 10) / 86400000LL + 4) % 7);
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
    LOBYTE(v4->cbSize) = 3;
    *(double *)&v4->cItems = v5;
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E0E0
// Name: public: static void GASDateProto::DateGetHours(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateGetHours(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // eax
  GASFnCall v4; // esi
  double v5; // [esp+4h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = a2[1];
    v5 = (double)(p_cxItem[22] / 3600000);
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
    LOBYTE(v4->cbSize) = 3;
    *(double *)&v4->cItems = v5;
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E160
// Name: public: static void GASDateProto::DateGetMinutes(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateGetMinutes(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // eax
  GASFnCall v4; // esi
  double v5; // [esp+4h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = a2[1];
    v5 = (double)(p_cxItem[22] % 3600000 / 60000);
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
    LOBYTE(v4->cbSize) = 3;
    *(double *)&v4->cItems = v5;
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E1E0
// Name: public: static void GASDateProto::DateGetSeconds(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateGetSeconds(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // eax
  GASFnCall v4; // esi
  double v5; // [esp+4h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = a2[1];
    v5 = (double)(p_cxItem[22] % 60000 / 1000);
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
    LOBYTE(v4->cbSize) = 3;
    *(double *)&v4->cItems = v5;
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E260
// Name: public: static void GASDateProto::DateGetMilliseconds(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateGetMilliseconds(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // eax
  GASFnCall v4; // esi
  double v5; // [esp+4h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = a2[1];
    v5 = (double)(p_cxItem[22] % 1000);
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
    LOBYTE(v4->cbSize) = 3;
    *(double *)&v4->cItems = v5;
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E2D0
// Name: public: static void GASDateProto::DateGetYear(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateGetYear(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // eax
  GASFnCall v4; // esi
  double v5; // [esp+4h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = a2[1];
    v5 = (double)(p_cxItem[23] - 1900);
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
    LOBYTE(v4->cbSize) = 3;
    *(double *)&v4->cItems = v5;
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E340
// Name: public: static void GASDateProto::DateGetFullYear(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateGetFullYear(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // eax
  GASFnCall v4; // esi
  double v5; // [esp+4h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = a2[1];
    v5 = (double)p_cxItem[23];
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
    LOBYTE(v4->cbSize) = 3;
    *(double *)&v4->cItems = v5;
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E3A0
// Name: public: static void GASDateProto::DateSetYear(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateSetYear(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // esi
  char *p_cxItem; // esi
  GASValue *v4; // eax
  unsigned int v5; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // ebx
  _SERVICE_STATUS *v9; // [esp-8h] [ebp-Ch]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = (char *)&v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    if ( (int)a2[7] >= 1 )
    {
      v9 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = (int)GASValue::ToNumber(this: v4, (int)a2, a3: a1, result: v9);
      v6 = v5;
      if ( v5 <= 0x63 )
        v6 = v5 + 1900;
      v7 = *((_DWORD *)p_cxItem + 24);
      if ( v7 >= 60 )
      {
        v8 = v7 - IsLeapYear(a1: *((_DWORD *)p_cxItem + 23));
        *((_DWORD *)p_cxItem + 24) = IsLeapYear(a1: v6) + v8;
      }
      *((_QWORD *)p_cxItem + 10) = *((int *)p_cxItem + 22)
                                 + 86400000LL
                                 * (*((_DWORD *)p_cxItem + 24)
                                  + 365 * (v6 - 1970)
                                  + (v6 - 1970 + 369) / 400
                                  - (v6 - 1970 + 69) / 100
                                  + (v6 - 1970 + 1) / 4);
      *((_DWORD *)p_cxItem + 23) = v6;
      GASDate::UpdateGMT(this: (GASDate *)p_cxItem);
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E4B0
// Name: public: static void GASDateProto::DateSetFullYear(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateSetFullYear(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // esi
  char *p_cxItem; // esi
  GASValue *v4; // eax
  double v5; // st7
  int v6; // ebx
  int v7; // edi
  int v8; // ebx
  _SERVICE_STATUS *v9; // [esp-Ch] [ebp-10h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = (char *)&v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    if ( (int)a2[7] >= 1 )
    {
      v9 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = GASValue::ToNumber(this: v4, (int)a2, a3: a1, result: v9);
      v6 = *((_DWORD *)p_cxItem + 24);
      v7 = (int)v5;
      if ( v6 >= 60 )
      {
        v8 = v6 - IsLeapYear(a1: *((_DWORD *)p_cxItem + 23));
        *((_DWORD *)p_cxItem + 24) = IsLeapYear(a1: v7) + v8;
      }
      *((_QWORD *)p_cxItem + 10) = *((int *)p_cxItem + 22)
                                 + 86400000LL
                                 * (*((_DWORD *)p_cxItem + 24)
                                  + 365 * (v7 - 1970)
                                  + (v7 - 1970 + 369) / 400
                                  - (v7 - 1970 + 69) / 100
                                  + (v7 - 1970 + 1) / 4);
      *((_DWORD *)p_cxItem + 23) = v7;
      GASDate::UpdateGMT(this: (GASDate *)p_cxItem);
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E5B0
// Name: public: static void GASDateProto::DateSetMonth(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateSetMonth(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // esi
  int *p_cxItem; // esi
  GASValue *v4; // eax
  double v5; // st7
  int v6; // ebx
  int v7; // edx
  int v8; // eax
  GASValue *v9; // edi
  _SERVICE_STATUS *v10; // [esp-Ch] [ebp-1Ch]
  int v11; // [esp+4h] [ebp-Ch]
  int v12; // [esp+8h] [ebp-8h]
  int v13; // [esp+Ch] [ebp-4h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    if ( (int)a2[7] >= 1 )
    {
      v10 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = GASValue::ToNumber(this: v4, (int)a2, a3: a1, result: v10);
      v13 = (int)v5;
      GASDateProto::DateGetDate(a1: a2);
      v6 = 0;
      v12 = (int)GASValue::ToNumber(this: (GASValue *)a2[1], (int)a2, a3: v5, result: (_SERVICE_STATUS *)a2[6]);
      v11 = p_cxItem[24];
      if ( v13 > 0 )
        v6 = dword_102A6374[12 * IsLeapYear(a1: p_cxItem[23]) + v13];
      v7 = v13 + 12 * IsLeapYear(a1: p_cxItem[23]);
      if ( v12 > months[v7] - v6 )
        v12 = months[v7] - v6;
      v8 = v6 + v12 - 1;
      p_cxItem[24] = v8;
      *((_QWORD *)p_cxItem + 10) += 86400000LL * (v8 - v11);
      v9 = (GASValue *)a2[1];
      GASValue::DropRefs(this: v9, a2: (int)v9);
      *(_BYTE *)v9 = 0;
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E6C0
// Name: public: static void GASDateProto::DateSetDate(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateSetDate(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // esi
  int *p_cxItem; // esi
  GASValue *v4; // eax
  double v5; // st7
  int v6; // ecx
  int v7; // edi
  bool v8; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  __int64 v12; // rax
  bool v13; // cf
  _SERVICE_STATUS *v14; // [esp-Ch] [ebp-14h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    if ( (int)a2[7] >= 1 )
    {
      v14 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = GASValue::ToNumber(this: v4, (int)a2, a3: a1, result: v14);
      v6 = p_cxItem[23];
      v7 = 0;
      while ( 1 )
      {
        v8 = p_cxItem[23] % 4 == 0 && (v6 % 100 != 0 || v6 % 400 == 0);
        if ( p_cxItem[24] < months[12 * v8 + v7] )
          break;
        if ( ++v7 >= 12 )
          return;
      }
      if ( v7 != 0 )
        v9 = dword_102A6374[12 * IsLeapYear(a1: v6) + v7];
      else
        v9 = 0;
      v10 = p_cxItem[24];
      v11 = v9 - v10 + (int)v5 - 1;
      p_cxItem[24] = v11 + v10;
      v12 = 86400000LL * v11;
      v13 = __CFADD__((_DWORD)v12, p_cxItem[20]);
      p_cxItem[20] += v12;
      p_cxItem[21] += HIDWORD(v12) + v13;
      GASDate::UpdateGMT(this: (GASDate *)p_cxItem);
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E7F0
// Name: public: static void GASDateProto::DateSetHours(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateSetHours(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // esi
  GASValue *v4; // eax
  double v5; // st7
  int v6; // edi
  __int64 v7; // rax
  _SERVICE_STATUS *v8; // [esp-8h] [ebp-Ch]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    if ( (int)a2[7] >= 1 )
    {
      v8 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = GASValue::ToNumber(this: v4, (int)a2, a3: a1, result: v8);
      v6 = p_cxItem[22];
      v7 = 3600000 * ((int)v5 - v6 / 3600000);
      *((_QWORD *)p_cxItem + 10) += v7;
      p_cxItem[22] = v7 + v6;
      GASDate::UpdateGMT(this: (GASDate *)p_cxItem);
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E880
// Name: public: static void GASDateProto::DateSetMinutes(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateSetMinutes(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // esi
  GASValue *v4; // eax
  double v5; // st7
  int v6; // edi
  __int64 v7; // rax
  _SERVICE_STATUS *v8; // [esp-Ch] [ebp-10h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    if ( (int)a2[7] >= 1 )
    {
      v8 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = GASValue::ToNumber(this: v4, (int)a2, a3: a1, result: v8);
      v6 = p_cxItem[22];
      v7 = 60000 * ((int)v5 - v6 % 3600000 / 60000);
      *((_QWORD *)p_cxItem + 10) += v7;
      p_cxItem[22] = v7 + v6;
      GASDate::UpdateGMT(this: (GASDate *)p_cxItem);
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E920
// Name: public: static void GASDateProto::DateSetSeconds(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateSetSeconds(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // esi
  GASValue *v4; // eax
  double v5; // st7
  int v6; // edi
  __int64 v7; // rax
  _SERVICE_STATUS *v8; // [esp-Ch] [ebp-10h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    if ( (int)a2[7] >= 1 )
    {
      v8 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = GASValue::ToNumber(this: v4, (int)a2, a3: a1, result: v8);
      v6 = p_cxItem[22];
      v7 = 1000 * ((int)v5 - v6 % 60000 / 1000);
      *((_QWORD *)p_cxItem + 10) += v7;
      p_cxItem[22] = v7 + v6;
      GASDate::UpdateGMT(this: (GASDate *)p_cxItem);
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E9C0
// Name: public: static void GASDateProto::DateSetMilliseconds(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateSetMilliseconds(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // esi
  GASValue *v4; // eax
  double v5; // st7
  int v6; // edi
  __int64 v7; // rax
  _SERVICE_STATUS *v8; // [esp-Ch] [ebp-10h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    if ( (int)a2[7] >= 1 )
    {
      v8 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = GASValue::ToNumber(this: v4, (int)a2, a3: a1, result: v8);
      v6 = p_cxItem[22];
      v7 = (int)v5 - v6 % 1000;
      *((_QWORD *)p_cxItem + 10) += v7;
      p_cxItem[22] = v7 + v6;
      GASDate::UpdateGMT(this: (GASDate *)p_cxItem);
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011EA50
// Name: public: static void GASDateProto::DateGetUTCMonth(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASDateProto::DateGetUTCMonth(GASFnCall *a1)
{
  GASFnCall v1; // eax
  int *p_cxItem; // eax
  int v3; // ecx
  int v4; // esi
  int v5; // edi
  int v6; // ebx
  bool v7; // al
  GASFnCall v8; // esi
  GASFnCall v9; // esi
  int v10; // [esp+4h] [ebp-4h]

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x23u) )
  {
    v1 = a1[2];
    if ( v1 != nullptr )
      p_cxItem = &v1[-1].cxItem;
    else
      p_cxItem = nullptr;
    v3 = p_cxItem[17];
    v4 = 0;
    v5 = v3 % 4;
    v6 = p_cxItem[18];
    while ( 1 )
    {
      v7 = v5 == 0 && (v3 % 100 != 0 || v3 % 400 == 0);
      if ( v6 < months[12 * v7 + v4] )
        break;
      if ( ++v4 >= 12 )
      {
        v8 = a1[1];
        if ( LOBYTE(v8->cbSize) >= 5u )
          GASValue::DropRefs(this: (GASValue *)a1[1], a2: v5);
        *(double *)&v8->cItems = -1.0;
        LOBYTE(v8->cbSize) = 3;
        return;
      }
    }
    v10 = v4;
    v9 = a1[1];
    if ( LOBYTE(v9->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)a1[1], a2: v5);
    *(double *)&v9->cItems = (double)v10;
    LOBYTE(v9->cbSize) = 3;
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011EB50
// Name: public: static void GASDateProto::DateGetUTCDate(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASDateProto::DateGetUTCDate(GASFnCall *a1)
{
  GASFnCall v1; // eax
  int p_cxItem; // edi
  int v3; // esi
  bool v4; // al
  int v5; // ecx
  BOOL v6; // ebx
  double v7; // st7
  GASFnCall v8; // esi
  int i; // eax
  bool v10; // al
  GASFnCall v11; // esi

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x23u) )
  {
    v1 = a1[2];
    if ( v1 != nullptr )
      p_cxItem = (int)&v1[-1].cxItem;
    else
      p_cxItem = 0;
    v3 = *(_DWORD *)(p_cxItem + 68);
    v4 = IsLeapYear(a1: v3);
    v5 = *(_DWORD *)(p_cxItem + 72);
    v6 = v4;
    if ( v5 >= months[12 * v4] )
    {
      p_cxItem = 1;
      for ( i = v3 % 4; ; i = v3 % 4 )
      {
        v10 = i == 0 && (v3 % 100 != 0 || v3 % 400 == 0);
        if ( v5 < months[12 * v10 + p_cxItem] )
        {
          v8 = a1[1];
          v7 = (double)(v5 - dword_102A6374[12 * v6 + p_cxItem] + 1);
          goto LABEL_8;
        }
        if ( ++p_cxItem >= 12 )
          break;
      }
      v11 = a1[1];
      if ( LOBYTE(v11->cbSize) >= 5u )
        GASValue::DropRefs(this: (GASValue *)a1[1], a2: p_cxItem);
      *(double *)&v11->cItems = -1.0;
      LOBYTE(v11->cbSize) = 3;
    }
    else
    {
      v7 = (double)(v5 + 1);
      v8 = a1[1];
LABEL_8:
      if ( LOBYTE(v8->cbSize) >= 5u )
        GASValue::DropRefs(this: (GASValue *)v8, a2: p_cxItem);
      *(double *)&v8->cItems = v7;
      LOBYTE(v8->cbSize) = 3;
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011ECA0
// Name: public: static void GASDateProto::DateGetUTCDay(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateGetUTCDay(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // eax
  GASFnCall v4; // esi
  double v5; // [esp+4h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = a2[1];
    v5 = (double)((int)(*((_QWORD *)p_cxItem + 7) / 86400000LL + 4) % 7);
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
    LOBYTE(v4->cbSize) = 3;
    *(double *)&v4->cItems = v5;
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011ED20
// Name: public: static void GASDateProto::DateGetUTCHours(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateGetUTCHours(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // eax
  GASFnCall v4; // esi
  double v5; // [esp+4h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = a2[1];
    v5 = (double)(p_cxItem[16] / 3600000);
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
    LOBYTE(v4->cbSize) = 3;
    *(double *)&v4->cItems = v5;
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011EDA0
// Name: public: static void GASDateProto::DateGetUTCMinutes(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateGetUTCMinutes(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // eax
  GASFnCall v4; // esi
  double v5; // [esp+4h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = a2[1];
    v5 = (double)(p_cxItem[16] % 3600000 / 60000);
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
    LOBYTE(v4->cbSize) = 3;
    *(double *)&v4->cItems = v5;
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011EE20
// Name: public: static void GASDateProto::DateGetUTCSeconds(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateGetUTCSeconds(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // eax
  GASFnCall v4; // esi
  double v5; // [esp+4h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = a2[1];
    v5 = (double)(p_cxItem[16] % 60000 / 1000);
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
    LOBYTE(v4->cbSize) = 3;
    *(double *)&v4->cItems = v5;
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011EEA0
// Name: public: static void GASDateProto::DateGetUTCMilliseconds(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateGetUTCMilliseconds(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // eax
  GASFnCall v4; // esi
  double v5; // [esp+4h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = a2[1];
    v5 = (double)(p_cxItem[16] % 1000);
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
    LOBYTE(v4->cbSize) = 3;
    *(double *)&v4->cItems = v5;
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011EF10
// Name: public: static void GASDateProto::DateGetUTCYear(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateGetUTCYear(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // eax
  GASFnCall v4; // esi
  double v5; // [esp+4h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = a2[1];
    v5 = (double)(p_cxItem[17] - 1900);
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
    LOBYTE(v4->cbSize) = 3;
    *(double *)&v4->cItems = v5;
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011EF80
// Name: public: static void GASDateProto::DateGetUTCFullYear(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateGetUTCFullYear(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // eax
  GASFnCall v4; // esi
  double v5; // [esp+4h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = a2[1];
    v5 = (double)p_cxItem[17];
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
    LOBYTE(v4->cbSize) = 3;
    *(double *)&v4->cItems = v5;
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011EFE0
// Name: public: static void GASDateProto::DateSetUTCYear(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateSetUTCYear(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // esi
  char *p_cxItem; // esi
  GASValue *v4; // eax
  unsigned int v5; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // ebx
  _SERVICE_STATUS *v9; // [esp-8h] [ebp-Ch]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = (char *)&v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    if ( (int)a2[7] >= 1 )
    {
      v9 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = (int)GASValue::ToNumber(this: v4, (int)a2, a3: a1, result: v9);
      v6 = v5;
      if ( v5 <= 0x63 )
        v6 = v5 + 1900;
      v7 = *((_DWORD *)p_cxItem + 18);
      if ( v7 >= 60 )
      {
        v8 = v7 - IsLeapYear(a1: *((_DWORD *)p_cxItem + 17));
        *((_DWORD *)p_cxItem + 18) = IsLeapYear(a1: v6) + v8;
      }
      *((_QWORD *)p_cxItem + 7) = *((int *)p_cxItem + 16)
                                + 86400000LL
                                * (*((_DWORD *)p_cxItem + 18)
                                 + 365 * (v6 - 1970)
                                 + (v6 - 1970 + 369) / 400
                                 - (v6 - 1970 + 69) / 100
                                 + (v6 - 1970 + 1) / 4);
      *((_DWORD *)p_cxItem + 17) = v6;
      GASDate::UpdateLocal(this: (GASDate *)p_cxItem);
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011F0F0
// Name: public: static void GASDateProto::DateSetUTCFullYear(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateSetUTCFullYear(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // esi
  char *p_cxItem; // esi
  GASValue *v4; // eax
  double v5; // st7
  int v6; // ebx
  int v7; // edi
  int v8; // ebx
  _SERVICE_STATUS *v9; // [esp-Ch] [ebp-10h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = (char *)&v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    if ( (int)a2[7] >= 1 )
    {
      v9 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = GASValue::ToNumber(this: v4, (int)a2, a3: a1, result: v9);
      v6 = *((_DWORD *)p_cxItem + 18);
      v7 = (int)v5;
      if ( v6 >= 60 )
      {
        v8 = v6 - IsLeapYear(a1: *((_DWORD *)p_cxItem + 17));
        *((_DWORD *)p_cxItem + 18) = IsLeapYear(a1: v7) + v8;
      }
      *((_QWORD *)p_cxItem + 7) = *((int *)p_cxItem + 16)
                                + 86400000LL
                                * (*((_DWORD *)p_cxItem + 18)
                                 + 365 * (v7 - 1970)
                                 + (v7 - 1970 + 369) / 400
                                 - (v7 - 1970 + 69) / 100
                                 + (v7 - 1970 + 1) / 4);
      *((_DWORD *)p_cxItem + 17) = v7;
      GASDate::UpdateLocal(this: (GASDate *)p_cxItem);
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011F1F0
// Name: public: static void GASDateProto::DateSetUTCMonth(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateSetUTCMonth(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // esi
  int *p_cxItem; // esi
  GASValue *v4; // eax
  double v5; // st7
  int v6; // ecx
  int v7; // edi
  bool v8; // al
  bool v9; // al
  int v10; // eax
  __int64 v11; // rax
  bool v12; // cf
  _SERVICE_STATUS *v13; // [esp-Ch] [ebp-14h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    if ( (int)a2[7] >= 1 )
    {
      v13 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = GASValue::ToNumber(this: v4, (int)a2, a3: a1, result: v13);
      v6 = p_cxItem[17];
      v7 = 0;
      while ( 1 )
      {
        v8 = p_cxItem[17] % 4 == 0 && (v6 % 100 != 0 || v6 % 400 == 0);
        if ( p_cxItem[18] < months[12 * v8 + v7] )
          break;
        if ( ++v7 >= 12 )
          return;
      }
      v9 = IsLeapYear(a1: v6);
      v10 = months[12 * v9 + (int)v5] - months[12 * v9 + v7];
      p_cxItem[18] += v10;
      v11 = 86400000LL * v10;
      v12 = __CFADD__((_DWORD)v11, p_cxItem[14]);
      p_cxItem[14] += v11;
      p_cxItem[15] += HIDWORD(v11) + v12;
      GASDate::UpdateLocal(this: (GASDate *)p_cxItem);
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011F320
// Name: public: static void GASDateProto::DateSetUTCDate(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateSetUTCDate(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // esi
  int *p_cxItem; // esi
  GASValue *v4; // eax
  double v5; // st7
  int v6; // ecx
  int v7; // edi
  bool v8; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  __int64 v12; // rax
  bool v13; // cf
  _SERVICE_STATUS *v14; // [esp-Ch] [ebp-14h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    if ( (int)a2[7] >= 1 )
    {
      v14 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = GASValue::ToNumber(this: v4, (int)a2, a3: a1, result: v14);
      v6 = p_cxItem[17];
      v7 = 0;
      while ( 1 )
      {
        v8 = p_cxItem[17] % 4 == 0 && (v6 % 100 != 0 || v6 % 400 == 0);
        if ( p_cxItem[18] < months[12 * v8 + v7] )
          break;
        if ( ++v7 >= 12 )
          return;
      }
      if ( v7 != 0 )
        v9 = dword_102A6374[12 * IsLeapYear(a1: v6) + v7];
      else
        v9 = 0;
      v10 = p_cxItem[18];
      v11 = v9 - v10 + (int)v5 - 1;
      p_cxItem[18] = v11 + v10;
      v12 = 86400000LL * v11;
      v13 = __CFADD__((_DWORD)v12, p_cxItem[14]);
      p_cxItem[14] += v12;
      p_cxItem[15] += HIDWORD(v12) + v13;
      GASDate::UpdateLocal(this: (GASDate *)p_cxItem);
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011F450
// Name: public: static void GASDateProto::DateSetUTCHours(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateSetUTCHours(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // esi
  GASValue *v4; // eax
  double v5; // st7
  int v6; // edi
  __int64 v7; // rax
  _SERVICE_STATUS *v8; // [esp-8h] [ebp-Ch]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    if ( (int)a2[7] >= 1 )
    {
      v8 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = GASValue::ToNumber(this: v4, (int)a2, a3: a1, result: v8);
      v6 = p_cxItem[16];
      v7 = 3600000 * ((int)v5 - v6 / 3600000);
      *((_QWORD *)p_cxItem + 7) += v7;
      p_cxItem[16] = v7 + v6;
      GASDate::UpdateLocal(this: (GASDate *)p_cxItem);
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011F4E0
// Name: public: static void GASDateProto::DateSetUTCMinutes(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateSetUTCMinutes(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // esi
  GASValue *v4; // eax
  double v5; // st7
  int v6; // edi
  __int64 v7; // rax
  _SERVICE_STATUS *v8; // [esp-Ch] [ebp-10h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    if ( (int)a2[7] >= 1 )
    {
      v8 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = GASValue::ToNumber(this: v4, (int)a2, a3: a1, result: v8);
      v6 = p_cxItem[16];
      v7 = 60000 * ((int)v5 - v6 % 3600000 / 60000);
      *((_QWORD *)p_cxItem + 7) += v7;
      p_cxItem[16] = v7 + v6;
      GASDate::UpdateLocal(this: (GASDate *)p_cxItem);
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011F580
// Name: public: static void GASDateProto::DateSetUTCSeconds(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateSetUTCSeconds(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // esi
  GASValue *v4; // eax
  double v5; // st7
  int v6; // edi
  __int64 v7; // rax
  _SERVICE_STATUS *v8; // [esp-Ch] [ebp-10h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    if ( (int)a2[7] >= 1 )
    {
      v8 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = GASValue::ToNumber(this: v4, (int)a2, a3: a1, result: v8);
      v6 = p_cxItem[16];
      v7 = 1000 * ((int)v5 - v6 % 60000 / 1000);
      *((_QWORD *)p_cxItem + 7) += v7;
      p_cxItem[16] = v7 + v6;
      GASDate::UpdateLocal(this: (GASDate *)p_cxItem);
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011F620
// Name: public: static void GASDateProto::DateSetUTCMilliseconds(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateSetUTCMilliseconds(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // esi
  GASValue *v4; // eax
  double v5; // st7
  int v6; // edi
  __int64 v7; // rax
  _SERVICE_STATUS *v8; // [esp-Ch] [ebp-10h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = &v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    if ( (int)a2[7] >= 1 )
    {
      v8 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = GASValue::ToNumber(this: v4, (int)a2, a3: a1, result: v8);
      v6 = p_cxItem[16];
      v7 = (int)v5 - v6 % 1000;
      *((_QWORD *)p_cxItem + 7) += v7;
      p_cxItem[16] = v7 + v6;
      GASDate::UpdateLocal(this: (GASDate *)p_cxItem);
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011F6B0
// Name: public: static void GASDateProto::DateValueOf(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateValueOf(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  __int64 *p_cxItem; // eax
  GASFnCall v4; // esi
  double v5; // [esp+4h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = (__int64 *)&v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = a2[1];
    v5 = (double)p_cxItem[7];
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
    LOBYTE(v4->cbSize) = 3;
    *(double *)&v4->cItems = v5;
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011F710
// Name: private: static void GASDateCtorFunction::DateUTC(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateCtorFunction::DateUTC(int a1@<edi>, long double a2@<st0>, const struct GASFnCall *fn)
{
  GASValue *v4; // eax
  double v5; // st7
  int v6; // ebx
  GASValue *v7; // eax
  double v8; // st7
  GASValue *v9; // eax
  GASValue *v10; // eax
  GASValue *v11; // eax
  GASValue *v12; // eax
  GASValue *v13; // eax
  int v14; // esi
  int v15; // esi
  _SERVICE_STATUS *v16; // [esp-Ch] [ebp-20h]
  _SERVICE_STATUS *v17; // [esp-Ch] [ebp-20h]
  _SERVICE_STATUS *v18; // [esp-4h] [ebp-18h]
  _SERVICE_STATUS *v19; // [esp-4h] [ebp-18h]
  _SERVICE_STATUS *v20; // [esp-4h] [ebp-18h]
  _SERVICE_STATUS *v21; // [esp-4h] [ebp-18h]
  _SERVICE_STATUS *v22; // [esp-4h] [ebp-18h]
  double days; // [esp+4h] [ebp-10h]
  double ms; // [esp+Ch] [ebp-8h]
  int fna; // [esp+1Ch] [ebp+8h]

  if ( *((int *)fn + 7) < 2 )
  {
    v15 = *((_DWORD *)fn + 1);
    if ( *(_BYTE *)v15 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v15, a2: a1);
    *(double *)(v15 + 4) = 0.0;
    *(_BYTE *)v15 = 3;
  }
  else
  {
    v16 = *((_SERVICE_STATUS **)fn + 6);
    v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
    v5 = GASValue::ToNumber(this: v4, a2: a1, a3: a2, result: v16);
    v6 = (int)v5 + 1900;
    if ( (unsigned int)(int)v5 > 0x63 )
      v6 = (int)v5;
    fna = 365 * (v6 - 1970) + (v6 - 1970 + 1) / 4 + (v6 - 1970 + 369) / 400 - (v6 - 1970 + 69) / 100;
    v17 = *((_SERVICE_STATUS **)fn + 6);
    days = (double)fna;
    ms = 0.0;
    v7 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 1);
    v8 = GASValue::ToNumber(this: v7, a2: fna, a3: 0.0, result: v17);
    if ( (int)v8 != 0 )
    {
      v8 = (double)dword_102A6374[12 * IsLeapYear(a1: v6) + (int)v8] + days;
      days = v8;
    }
    if ( *((int *)fn + 7) >= 3 )
    {
      v18 = *((_SERVICE_STATUS **)fn + 6);
      v9 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 2);
      v8 = (double)((int)GASValue::ToNumber(this: v9, a2: a1, a3: v8, result: v18) - 1) + days;
      days = v8;
    }
    if ( *((int *)fn + 7) >= 4 )
    {
      v19 = *((_SERVICE_STATUS **)fn + 6);
      v10 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 3);
      v8 = GASValue::ToNumber(this: v10, a2: a1, a3: v8, result: v19) * 3600000.0 + 0.0;
      ms = v8;
    }
    if ( *((int *)fn + 7) >= 5 )
    {
      v20 = *((_SERVICE_STATUS **)fn + 6);
      v11 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 4);
      v8 = GASValue::ToNumber(this: v11, a2: a1, a3: v8, result: v20) * 60000.0 + ms;
      ms = v8;
    }
    if ( *((int *)fn + 7) >= 6 )
    {
      v21 = *((_SERVICE_STATUS **)fn + 6);
      v12 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 5);
      v8 = GASValue::ToNumber(this: v12, a2: a1, a3: v8, result: v21) * 1000.0 + ms;
      ms = v8;
    }
    if ( *((int *)fn + 7) >= 7 )
    {
      v22 = *((_SERVICE_STATUS **)fn + 6);
      v13 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 6);
      ms = GASValue::ToNumber(this: v13, a2: a1, a3: v8, result: v22) + ms;
    }
    v14 = *((_DWORD *)fn + 1);
    if ( *(_BYTE *)v14 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v14, a2: a1);
    *(double *)(v14 + 4) = days * 86400000.0 + ms;
    *(_BYTE *)v14 = 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011F8F0
// Name: public: virtual enum GASObjectInterface::ObjectType GASDate::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASDate::GetObjectType(GPtr<GFxAmpThreadMgr> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1011FA00
// Name: public: GASDate::GASDate(class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
GASDate *__thiscall GASDate::GASDate(GASDate *this, struct GASEnvironment *a2)
{
  vc_attributes::InvalidCheckAttribute *Prototype; // eax

  GASObject::GASObject((GASObject *)this, a2);
  *this = (GASDate)&GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *(this + 4) = (GASDate)&GASDate::`vftable'{for `GASObjectInterface'};
  *(this + 14) = nullptr;
  *(this + 15) = nullptr;
  *(this + 16) = nullptr;
  *(this + 17) = nullptr;
  *(this + 18) = nullptr;
  *(this + 20) = nullptr;
  *(this + 21) = nullptr;
  *(this + 22) = nullptr;
  *(this + 23) = nullptr;
  *(this + 24) = nullptr;
  *(this + 25) = nullptr;
  Prototype = GASGlobalContext::GetPrototype(
                this: *((vc_attributes::PreRangeAttribute **)a2 + 30),
                result: (vc_attributes::InvalidCheckAttribute *)0x14);
  (*((void (__thiscall **)(GASDate *, char *, vc_attributes::InvalidCheckAttribute *))*(this + 4) + 13))(
    a1: this + 4,
    a2: (char *)a2 + 120,
    a3: Prototype);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1011FA70
// Name: public: void GASDate::SetDate(__int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASDate::SetDate(GASDate *this, __int64 a2)
{
  __int64 v2; // rax
  bool v3; // cf
  __int64 v4; // rcx
  int v5; // esi
  bool v6; // al
  bool v7; // al
  signed __int64 v8; // kr00_8
  int v9; // esi
  bool v10; // al
  const GFxAmpThreadMgr *v11; // esi
  bool v12; // al
  __int64 v13; // rax
  unsigned int v14; // [esp+Ch] [ebp-Ch]

  *(this + 16) = (GASDate)(a2 % 86400000);
  v2 = 146097 * (a2 / 86400000 / 146097);
  v3 = (unsigned int)(a2 / 86400000) < (unsigned int)v2;
  LODWORD(v2) = this;
  HIDWORD(v4) = ((unsigned __int64)(a2 / 86400000) >> 32) - (v3 + HIDWORD(v2));
  LODWORD(v4) = a2 / 86400000 % 146097;
  v14 = v4;
  *(_DWORD *)(v2 + 68) = 400 * (a2 / 86400000 / 146097) + 1970;
  if ( a2 < 0 )
  {
    while ( 1 )
    {
      v8 = abs64(v4);
      v9 = (int)*(this + 17);
      v10 = v9 % 4 == 0 && (v9 % 100 != 0 || v9 % 400 == 0);
      if ( v8 < v10 + 365 )
        break;
      v11 = (const GFxAmpThreadMgr *)(v9 - 1);
      *(this + 17) = v11;
      v12 = (int)v11 % 4 == 0 && ((int)v11 % 100 != 0 || (int)v11 % 400 == 0);
      v13 = v12 + 365;
      v4 = v13 + __PAIR64__(HIDWORD(v4), v14);
      v14 += v13;
    }
    LODWORD(v4) = v14;
  }
  else
  {
    while ( 1 )
    {
      v5 = (int)*(this + 17);
      v6 = v5 % 4 == 0 && (v5 % 100 != 0 || v5 % 400 == 0);
      if ( v4 < v6 + 365 )
        break;
      v7 = v5 % 4 == 0 && (v5 % 100 != 0 || v5 % 400 == 0);
      v4 -= v7 + 365;
      *(this + 17) = (GASDate)(v5 + 1);
    }
  }
  *(this + 18) = (GASDate)v4;
  *((_QWORD *)this + 7) = a2;
  GASDate::UpdateLocal(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011FCF0
// Name: public: static void GASDateProto::DateSetTime(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateProto::DateSetTime(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  GASDate *p_cxItem; // edi
  GASValue *v4; // eax
  __int64 v5; // rax
  _SERVICE_STATUS *v6; // [esp-8h] [ebp-Ch]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x23u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = (GASDate *)&v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    if ( (int)a2[7] >= 1 )
    {
      v6 = (_SERVICE_STATUS *)a2[6];
      v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      v5 = (unsigned __int64)GASValue::ToNumber(this: v4, a2: (int)p_cxItem, a3: a1, result: v6);
      GASDate::SetDate(this: p_cxItem, a2: v5);
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "Date", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011FD60
// Name: public: virtual class GASObject __near * GASDateCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
GASDate *__thiscall GASDateCtorFunction::CreateNewObject(GASDateCtorFunction *this, int a2)
{
  struct GASEnvironment *v2; // esi
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // edx
  GASDate *v5; // eax

  v2 = (struct GASEnvironment *)a2;
  v3 = *(_DWORD *)(*(_DWORD *)(a2 + 120) + 656);
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  a2 = 323;
  v5 = (GASDate *)v4(a1: v3, a2: 104, a3: &a2);
  if ( v5 != nullptr )
    return GASDate::GASDate(this: v5, a2: v2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1011FFB0
// Name: unsigned int G_Format<char const __near *,char const __near *,int,int,int,int,int,int,int>(class GMsgFormat::Sink const __near &,char const __near *,char const __near * const __near &,char const __near * const __near &,int const __near &,int const __near &,int const __near &,int const __near &,int const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl G_Format<char const *,char const *,int,int,int,int,int,int,int>(
        struct GMsgFormat::Sink *a1,
        CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *a2,
        CMatQueuedRenderContext::CCallQueueExternal *v,
        CMatQueuedRenderContext::CCallQueueExternal *a4,
        CUtlSymbolTable::StringPool_t *a5,
        CUtlSymbolTable::StringPool_t *a6,
        CUtlSymbolTable::StringPool_t *a7,
        CUtlSymbolTable::StringPool_t *a8,
        CUtlSymbolTable::StringPool_t *a9,
        CUtlSymbolTable::StringPool_t *a10,
        CUtlSymbolTable::StringPool_t *a11)
{
  int m_nGrowSize; // esi
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v13[27]; // [esp+28h] [ebp-304h] BYREF

  GMsgFormat::GMsgFormat(this: (GMsgFormat *)v13, a2: a1);
  GMsgFormat::Parse(this: v13, result: a2);
  GMsgFormat::FormatD1<char const *>(this: (CMatQueuedRenderContext::CCallQueueExternal *)v13, v);
  GMsgFormat::FormatD1<char const *>(this: (CMatQueuedRenderContext::CCallQueueExternal *)v13, v: a4);
  GMsgFormat::FormatD1<int>(this: (int)v13, result: a5);
  GMsgFormat::FormatD1<int>(this: (int)v13, result: a6);
  GMsgFormat::FormatD1<int>(this: (int)v13, result: a7);
  GMsgFormat::FormatD1<int>(this: (int)v13, result: a8);
  GMsgFormat::FormatD1<int>(this: (int)v13, result: a9);
  GMsgFormat::FormatD1<int>(this: (int)v13, result: a10);
  GMsgFormat::FormatD1<int>(this: (int)v13, result: a11);
  GMsgFormat::FinishFormatD(this: v13);
  m_nGrowSize = v13[0].m_Elements.m_nGrowSize;
  GMsgFormat::~GMsgFormat(this: v13);
  return m_nGrowSize;
}

//------------------------------------------------------------------------------
// Address: 0x10120140
// Name: public: static void GASDateProto::DateToString(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASDateProto::DateToString(GASFnCall *a1)
{
  GASFnCall v1; // esi
  int v2; // edi
  int *p_cxItem; // esi
  int v4; // ecx
  int m_TotalLen; // eax
  int v6; // edx
  unsigned __int8 v7; // al
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // edx
  int v13; // ecx
  int v14; // eax
  int v15; // esi
  GASFnCall v16; // edi
  bool v17; // zf
  _DWORD v18[3]; // [esp+4h] [ebp-B4h] BYREF
  CUtlSymbolTable::StringPool_t v19; // [esp+10h] [ebp-A8h] BYREF
  CUtlSymbolTable::StringPool_t v20; // [esp+1Ch] [ebp-9Ch] BYREF
  int v21; // [esp+28h] [ebp-90h]
  CUtlSymbolTable::StringPool_t v22[11]; // [esp+2Ch] [ebp-8Ch] BYREF

  if ( !GASFnCall::CheckThisPtr(this: a1, type: 0x23u) )
  {
    GASFnCall::ThisPtrError(this: a1, a2: "Date", a3: nullptr, a4: 0);
    return;
  }
  v1 = a1[2];
  v2 = 0;
  if ( v1 != nullptr )
    p_cxItem = &v1[-1].cxItem;
  else
    p_cxItem = nullptr;
  v4 = p_cxItem[23];
  v19.m_SpaceUsed = (int)(p_cxItem + 23);
  v21 = 0;
  *(_DWORD *)v20.m_Data = 0;
  m_TotalLen = v4 % 4;
  v6 = p_cxItem[24];
  for ( v22[0].m_TotalLen = v4 % 4; ; m_TotalLen = v22[0].m_TotalLen )
  {
    if ( m_TotalLen == 0 )
    {
      if ( v4 % 100 != 0 || v4 % 400 == 0 )
      {
        v6 = p_cxItem[24];
        v7 = 1;
        goto LABEL_14;
      }
      v6 = p_cxItem[24];
    }
    v7 = 0;
LABEL_14:
    if ( v6 < months[12 * v7 + v2] )
      break;
    if ( ++v2 >= 12 )
      goto LABEL_21;
  }
  v21 = v2;
  if ( v2 != 0 )
  {
    v8 = dword_102A6374[12 * IsLeapYear(a1: v4) + v2];
    v6 = p_cxItem[24];
  }
  else
  {
    v8 = 0;
  }
  *(_DWORD *)v20.m_Data = v6 - v8 + 1;
LABEL_21:
  v9 = p_cxItem[21];
  v10 = p_cxItem[20];
  if ( v9 < 0 )
    v22[0].m_SpaceUsed = (int)daynames[(unsigned int)(((3
                                                      - (__int64)(__PAIR64__(
                                                                    (v9 >> 31) ^ (unsigned int)v9,
                                                                    (v9 >> 31) ^ (unsigned int)v10)
                                                                - __PAIR64__(v9 >> 31, v9 >> 31))
                                                      / 86400000)
                                                     % 7
                                                     + 7)
                                                    % 7)];
  else
    v22[0].m_SpaceUsed = (int)daynames[(unsigned int)((__SPAIR64__(v9, v10) / 86400000 + 4) % 7)];
  v11 = p_cxItem[25] / 3600000;
  v12 = p_cxItem[25] % 3600000;
  v18[0] = 2;
  v18[2] = 128;
  v22[0].m_TotalLen = v12 / 60000;
  v20.m_SpaceUsed = v11;
  v13 = p_cxItem[22];
  *(_DWORD *)v19.m_Data = v13 % 60000 / 1000;
  v20.m_TotalLen = v13 / 3600000;
  v19.m_TotalLen = v13 % 3600000 / 60000;
  v18[1] = v22[0].m_Data;
  G_Format<char const *,char const *,int,int,int,int,int,int,int>(
    a1: (struct GMsgFormat::Sink *)v18,
    a2: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)"{0} {1} {2:2} {3:02}:{4:02}:{5:02} GMT{6:+03}{7:02} {8}",
    v: (CMatQueuedRenderContext::CCallQueueExternal *)&v22[0].m_SpaceUsed,
    a4: (CMatQueuedRenderContext::CCallQueueExternal *)&monthnames[v21],
    a5: (CUtlSymbolTable::StringPool_t *)v20.m_Data,
    a6: &v20,
    a7: &v19,
    a8: (CUtlSymbolTable::StringPool_t *)v19.m_Data,
    a9: (CUtlSymbolTable::StringPool_t *)&v20.m_SpaceUsed,
    a10: v22,
    a11: (CUtlSymbolTable::StringPool_t *)v19.m_SpaceUsed);
  GASStringManager::CreateStringNode(
    this: *(GASStringManager **)(a1[6][3].cbSize + 636),
    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v22[0].m_Data);
  v15 = v14;
  ++*(_DWORD *)(v14 + 8);
  v16 = a1[1];
  if ( LOBYTE(v16->cbSize) >= 5u )
    GASValue::DropRefs(this: (GASValue *)a1[1], a2: (int)v16);
  LOBYTE(v16->cbSize) = 5;
  v16->cItems = v15;
  v17 = ++*(_DWORD *)(v15 + 8) == 1;
  --*(_DWORD *)(v15 + 8);
  if ( v17 )
    GASStringNode::ReleaseNode(a1: v15);
}

//------------------------------------------------------------------------------
// Address: 0x10120430
// Name: public: static void GASDateCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASDateCtorFunction::GlobalCtor(long double a1@<st0>, const struct GASFnCall *fn)
{
  int v2; // eax
  int v3; // esi
  int v4; // ecx
  int (__thiscall *v5)(int, int, int *); // eax
  GASDate *v6; // eax
  GASDate *v7; // eax
  DWORD v8; // eax
  int Bias; // ecx
  int v10; // eax
  GASValue *v11; // eax
  __int64 v12; // rax
  GASValue *v13; // eax
  double v14; // st7
  int v15; // eax
  int v16; // ecx
  int v17; // esi
  int v18; // eax
  int v19; // ebx
  GASValue *v20; // eax
  double v21; // st7
  GASValue *v22; // eax
  GASValue *v23; // eax
  GASValue *v24; // eax
  GASValue *v25; // eax
  GASValue *v26; // eax
  int v27; // ecx
  int v28; // edi
  int v29; // eax
  _SERVICE_STATUS *v31; // [esp-8h] [ebp-ECh]
  _SERVICE_STATUS *v32; // [esp-8h] [ebp-ECh]
  _SERVICE_STATUS *v33; // [esp-8h] [ebp-ECh]
  _SERVICE_STATUS *v34; // [esp-8h] [ebp-ECh]
  _SERVICE_STATUS *v35; // [esp-8h] [ebp-ECh]
  _SERVICE_STATUS *v36; // [esp-8h] [ebp-ECh]
  _SERVICE_STATUS *v37; // [esp-8h] [ebp-ECh]
  _SERVICE_STATUS *v38; // [esp-8h] [ebp-ECh]
  int v39; // [esp+8h] [ebp-DCh]
  int v40; // [esp+Ch] [ebp-D8h]
  int v41; // [esp+14h] [ebp-D0h]
  GASDate *v42; // [esp+18h] [ebp-CCh]
  int ms; // [esp+1Ch] [ebp-C8h]
  int y; // [esp+20h] [ebp-C4h] BYREF
  _TIME_ZONE_INFORMATION TimeZoneInformation; // [esp+24h] [ebp-C0h] BYREF
  __timeb64 tp; // [esp+D0h] [ebp-14h] BYREF

  if ( *((_DWORD *)fn + 2) != 0
    && (*(int (__thiscall **)(_DWORD))(**((_DWORD **)fn + 2) + 8))(a1: *((_DWORD *)fn + 2)) == 35 )
  {
    v2 = *((_DWORD *)fn + 2);
    if ( v2 != 0 )
    {
      v3 = v2 - 16;
      if ( v2 != 16 )
        *(_DWORD *)(v3 + 8) = (*(_DWORD *)(v3 + 8) + 1) & 0x8FFFFFFF;
      v42 = (GASDate *)(v2 - 16);
    }
    else
    {
      v3 = 0;
      v42 = nullptr;
    }
  }
  else
  {
    v4 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)fn + 6) + 120) + 656);
    v5 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v4 + 40);
    y = 323;
    v6 = (GASDate *)v5(a1: v4, a2: 104, a3: &y);
    if ( v6 != nullptr )
      v7 = GASDate::GASDate(this: v6, a2: *((struct GASEnvironment **)fn + 6));
    else
      v7 = nullptr;
    v42 = v7;
    v3 = (int)v7;
  }
  _ftime64(&tp);
  v8 = GetTimeZoneInformation(lpTimeZoneInformation: &TimeZoneInformation);
  Bias = TimeZoneInformation.Bias;
  if ( v8 == 1 )
  {
    Bias = TimeZoneInformation.StandardBias + TimeZoneInformation.Bias;
  }
  else if ( v8 == 2 )
  {
    Bias = TimeZoneInformation.DaylightBias + TimeZoneInformation.Bias;
  }
  *(_DWORD *)(v3 + 100) = -60000 * Bias;
  GASDate::SetDate(this: (GASDate *)v3, a2: tp.millitm + 1000 * tp.time);
  v10 = *((_DWORD *)fn + 7);
  if ( v10 == 1 )
  {
    v31 = *((_SERVICE_STATUS **)fn + 6);
    v11 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
    v12 = (unsigned __int64)GASValue::ToNumber(this: v11, a2: (int)fn, a3: a1, result: v31);
    GASDate::SetDate(this: (GASDate *)v3, a2: v12);
  }
  else if ( v10 >= 2 )
  {
    v32 = *((_SERVICE_STATUS **)fn + 6);
    v13 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
    v14 = GASValue::ToNumber(this: v13, a2: (int)fn, a3: a1, result: v32);
    v15 = (int)v14;
    if ( (unsigned int)(int)v14 <= 0x63 )
      v15 += 1900;
    y = v15;
    v16 = (v15 - 1970 + 369) / 400;
    v17 = (v15 - 1970 + 69) / 100;
    v41 = 365 * (v15 - 1970);
    v18 = (v15 - 1970 + 1) / 4;
    v40 = v16;
    v19 = v16 + v18 + v41 - v17;
    v33 = *((_SERVICE_STATUS **)fn + 6);
    v39 = v18;
    ms = 0;
    v20 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 1);
    v21 = GASValue::ToNumber(this: v20, a2: (int)fn, a3: v14, result: v33);
    if ( (int)v21 != 0 )
      v19 += dword_102A6374[12 * IsLeapYear(a1: y) + (int)v21];
    if ( *((int *)fn + 7) >= 3 )
    {
      v34 = *((_SERVICE_STATUS **)fn + 6);
      v22 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 2);
      v21 = GASValue::ToNumber(this: v22, a2: (int)fn, a3: v21, result: v34);
      v19 = v19 + (int)v21 - 1;
    }
    if ( *((int *)fn + 7) >= 4 )
    {
      v35 = *((_SERVICE_STATUS **)fn + 6);
      v23 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 3);
      v21 = GASValue::ToNumber(this: v23, a2: (int)fn, a3: v21, result: v35);
      ms = 3600000 * (int)v21;
    }
    if ( *((int *)fn + 7) >= 5 )
    {
      v36 = *((_SERVICE_STATUS **)fn + 6);
      v24 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 4);
      v21 = GASValue::ToNumber(this: v24, a2: (int)fn, a3: v21, result: v36);
      ms += 60000 * (int)v21;
    }
    if ( *((int *)fn + 7) >= 6 )
    {
      v37 = *((_SERVICE_STATUS **)fn + 6);
      v25 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 5);
      v21 = GASValue::ToNumber(this: v25, a2: (int)fn, a3: v21, result: v37);
      ms += 1000 * (int)v21;
    }
    if ( *((int *)fn + 7) >= 7 )
    {
      v38 = *((_SERVICE_STATUS **)fn + 6);
      v26 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 6);
      ms += (int)GASValue::ToNumber(this: v26, a2: (int)fn, a3: v21, result: v38);
    }
    v27 = y;
    v42[24] = (GASDate)(v19 + v17 - v41 - v39 - v40);
    v42[23] = (GASDate)v27;
    v42[22] = (GASDate)ms;
    v3 = (int)v42;
    *((_QWORD *)v42 + 10) = ms + 86400000LL * v19;
    GASDate::UpdateGMT(this: v42);
    GASDate::SetDate(this: (GASDate *)v3, a2: *(_QWORD *)(v3 + 56));
  }
  GASValue::SetAsObject(this: *((GASValue **)fn + 1), a2: (struct GASObject *)v3);
  GASValue::ToStringImpl(
    this: *((unsigned __int8 **)fn + 1),
    a2: &y,
    a3: *((tagRID_DEVICE_INFO_KEYBOARD **)fn + 6),
    precision: -1,
    debug: false);
  v28 = *((_DWORD *)fn + 1);
  if ( *(_BYTE *)v28 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v28, a2: v28);
  *(_BYTE *)v28 = 5;
  *(_DWORD *)(v28 + 4) = y;
  ++*(_DWORD *)(y + 8);
  v29 = y;
  if ( (*(_DWORD *)(y + 8))-- == 1 )
    GASStringNode::ReleaseNode(a1: v29);
  GRefCountBaseGC<323>::Release(a1: v3, a2: v28);
}

//------------------------------------------------------------------------------
// Address: 0x10120940
// Name: public: static class GASFunctionRef GASDateCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__cdecl GASDateCtorFunction::Register(struct GASFunctionRef *a1, int a2)
{
  vc_attributes::PreRangeAttribute *v2; // edi
  const char *v3; // ecx
  int (__thiscall *v4)(const char *, int, int *); // eax
  GASCFunctionObject *v5; // eax
  GASCFunctionObject *v6; // ebx
  void *v7; // ecx
  GASCFunctionObject *v8; // eax
  struct GASFunctionRef *v9; // ebx
  const char *MaxVal; // ecx
  int (__thiscall *v11)(const char *, int, struct GASFunctionRef **); // eax
  int v12; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GASValue *v14; // eax
  int p_MinVal; // edi
  GASValue v17[4]; // [esp+Ch] [ebp-20h] BYREF
  vc_attributes::PreRangeAttribute *psc; // [esp+1Ch] [ebp-10h] BYREF
  char v19; // [esp+20h] [ebp-Ch]
  void (__thiscall **v20)(_DWORD *, vc_attributes::PreRangeAttribute **, int, GASValue *, char *); // [esp+24h] [ebp-8h]
  _DWORD *v21; // [esp+28h] [ebp-4h]

  v2 = (vc_attributes::PreRangeAttribute *)a2;
  v3 = *(const char **)(a2 + 656);
  psc = (vc_attributes::PreRangeAttribute *)a2;
  v19 = 8;
  v4 = *(int (__thiscall **)(const char *, int, int *))(*(_DWORD *)v3 + 40);
  a2 = 323;
  v5 = (GASCFunctionObject *)v4(a1: v3, a2: 56, a3: &a2);
  v6 = v5;
  if ( v5 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v5,
      func: (_REASON_CONTEXT *)&psc,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASDateCtorFunction::GlobalCtor);
    v6->dwSize = (unsigned int)&GASDateCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v6->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    GASNameFunction::AddConstMembers(
      pobj: v7,
      psc: (int)&v6->cLineHeight,
      psca: (CTSQueue<CFunctor *,0,1>::Node_t *)&psc,
      a4: (struct GASObject **)GASDateCtorFunction::StaticFunctionTable,
      a5: 7);
    v8 = v6;
  }
  else
  {
    v8 = nullptr;
  }
  v9 = a1;
  *(_DWORD *)a1 = v8;
  *((_BYTE *)v9 + 8) = 0;
  *((_DWORD *)v9 + 1) = 0;
  MaxVal = v2[54].MaxVal;
  v11 = *(int (__thiscall **)(const char *, int, struct GASFunctionRef **))(*(_DWORD *)MaxVal + 40);
  a1 = (struct GASFunctionRef *)323;
  v12 = v11(a1: MaxVal, a2: 136, a3: &a1);
  if ( v12 != 0 )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v2,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASDate,GASEnvironment>::GASPrototype<GASDate,GASEnvironment>(
      this: (vgui::IPanel *)v12,
      (struct GASStringContext *)&psc,
      psc_4: Prototype,
      psc_8: (unsigned int)v9);
    *(_DWORD *)v12 = &GASDateProto::`vftable'{for `GASRefCountBase<GASObject>'};
    *(_DWORD *)(v12 + 16) = &GASPrototype<GASDate,GASEnvironment>::`vftable'{for `GASObjectInterface'};
    *(_DWORD *)(v12 + 104) = &GASDateProto::`vftable';
    HIBYTE(a2) = 1;
    GASPrototypeBase::InitFunctionMembers(
      this: (GASPrototypeBase *)(v12 + 104),
      a2: v12,
      flags: &psc,
      flags_4: (const struct GASNameFunction *)&GAS_DateFunctionTable,
      flags_8: (const struct GASPropFlags *)((char *)&a2 + 3));
  }
  else
  {
    v12 = 0;
  }
  if ( v12 != 0 )
    *(_DWORD *)(v12 + 8) = (*(_DWORD *)(v12 + 8) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)v2, a3: 20, a4: v12);
  v21 = v2[56].MaxVal + 16;
  HIBYTE(a2) = 0;
  v20 = (void (__thiscall **)(_DWORD *, vc_attributes::PreRangeAttribute **, int, GASValue *, char *))(*v21 + 40);
  v14 = GASValue::GASValue(this: v17, a2: (int)v2, a3: v9);
  p_MinVal = (int)&v2[7].MinVal;
  (*v20)(a1: v21, a2: &psc, a3: p_MinVal, a4: v14, a5: (char *)&a2 + 3);
  GASValue::~GASValue(this: v17, a2: p_MinVal);
  if ( v12 != 0 )
    GRefCountBaseGC<323>::Release(a1: v12, a2: p_MinVal);
  return v9;
}
