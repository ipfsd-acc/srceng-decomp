// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasstringobject.cpp
// Functions: 25
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasstringobject.h"

//------------------------------------------------------------------------------
// Address: 0x10108980
// Name: public: virtual char const __near * GASStringObject::GetTextValue(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall GASStringObject::GetTextValue(GASStringObject *this, struct GASEnvironment *a2)
{
  return **((const char ***)this + 9);
}

//------------------------------------------------------------------------------
// Address: 0x10108990
// Name: public: virtual bool GASStringObject::GetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GASStringObject::GetMemberRaw(
        CTSQueue<CFunctor *,0,1> *this,
        CTSQueue<CFunctor *,0,1>::Node_t *psc,
        int **a3,
        struct GASValue *a4)
{
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // esi
  bool v5; // zf
  int Length; // edi
  CTSQueue<CFunctor *,0,1> *v8; // [esp+Ch] [ebp-4h]

  pNext = psc->pNext;
  v8 = this;
  if ( LOBYTE(psc->elem) <= 6u )
  {
    if ( (*a3)[1] == 0 )
    {
      GASStringNode::ResolveLowercase_Impl(a1: *a3);
      this = v8;
    }
    v5 = pNext[79].pNext->elem == (CFunctor *)(*a3)[1];
  }
  else
  {
    v5 = pNext[79].pNext == (CTSQueue<CFunctor *,0,1>::Node_t *)*a3;
  }
  if ( !v5 )
    return GASObject::GetMemberRaw(this, (_IMAGE_SYMBOL_EX *)psc, ikey: (_EXIT_THREAD_DEBUG_INFO *)a3, (GASValue *)a4) != 0;
  if ( GASObject::GetMemberRaw(this, (_IMAGE_SYMBOL_EX *)psc, ikey: (_EXIT_THREAD_DEBUG_INFO *)a3, (GASValue *)a4) == 0
    || *(_BYTE *)a4 == 10 )
  {
    Length = GASString::GetLength(this: (const char ***)&v8[1].m_Head.value.sequence);
    if ( *(_BYTE *)a4 >= 5u )
      GASValue::DropRefs(this: (GASValue *)a4, a2: Length);
    *(_BYTE *)a4 = 4;
    *((_DWORD *)a4 + 1) = Length;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10108A30
// Name: public: virtual void GASStringObject::SetValue(class GASEnvironment __near *,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
tagRID_DEVICE_INFO_KEYBOARD *__thiscall GASStringObject::SetValue(
        int *this,
        tagRID_DEVICE_INFO_KEYBOARD *a2,
        tagWNDCLASSW *v)
{
  tagRID_DEVICE_INFO_KEYBOARD *result; // eax

  GASValue::ToStringImpl(this: (unsigned __int8 *)v, (int *)&a2, a3: a2, precision: -1, debug: false);
  GASString::operator=(
    this: this + 13,
    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)a2->dwType);
  result = a2;
  if ( a2->dwKeyboardMode-- == 1 )
    return (tagRID_DEVICE_INFO_KEYBOARD *)GASStringNode::ReleaseNode(a1: (int)result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10108A70
// Name: public: virtual class GASValue GASStringObject::GetValue(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASStringObject::GetValue(_DWORD *this, int a2)
{
  int v3; // ecx

  v3 = *(this + 13);
  ++*(_DWORD *)(v3 + 8);
  *(_BYTE *)a2 = 5;
  *(_DWORD *)(a2 + 4) = v3;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10108A90
// Name: public: static void GASStringProto::StringCharCodeAt(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASStringProto::StringCharCodeAt(int a1@<edi>, long double a2@<st0>, GASFnCall *a3)
{
  GASFnCall v3; // eax
  int *p_cxItem; // eax
  unsigned int **v5; // ebx
  GASValue *v6; // eax
  double CharAt; // st7
  GASFnCall v8; // esi
  _SERVICE_STATUS *v9; // [esp-Ch] [ebp-18h]

  if ( GASFnCall::CheckThisPtr(this: a3, type: 8u) )
  {
    v3 = a3[2];
    if ( v3 != nullptr )
      p_cxItem = &v3[-1].cxItem;
    else
      p_cxItem = nullptr;
    v5 = (unsigned int **)(p_cxItem + 13);
    if ( (int)a3[7] < 1
      || (v9 = (_SERVICE_STATUS *)a3[6],
          v6 = (GASValue *)GASFnCall::Arg(this: a3, a2: 0),
          (a1 = (int)GASValue::ToNumber(this: v6, a2: a1, a3: a2, result: v9)) < 0)
      || a1 >= GASString::GetLength(this: (const char ***)v5) )
    {
      CharAt = GASNumberUtil::NaN();
    }
    else
    {
      CharAt = (double)GASString::GetCharAt(this: v5, index: a1);
    }
    v8 = a3[1];
    if ( LOBYTE(v8->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v8, a2: a1);
    *(double *)&v8->cItems = CharAt;
    LOBYTE(v8->cbSize) = 3;
  }
  else
  {
    GASFnCall::ThisPtrError(this: a3, a2: (const char *)&stru_10299D8C.m_pObject, a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108B40
// Name: public: static void GASStringProto::StringIndexOf(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASStringProto::StringIndexOf(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // ebx
  GASFnCall v4; // edi
  tagRID_DEVICE_INFO_KEYBOARD *v5; // esi
  unsigned __int8 *v6; // eax
  GASFnCall v7; // esi
  double v8; // st7
  bool (__cdecl *v9)(const char *const *, const char *const *); // edx
  int v10; // ebx
  bool v11; // cc
  GASValue *v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // esi
  unsigned int v15; // eax
  const char **v16; // eax
  bool v17; // zf
  GASFnCall v18; // esi
  const char **v19; // eax
  _SERVICE_STATUS *v20; // [esp-Ch] [ebp-2Ch]
  unsigned int Char; // [esp+4h] [ebp-1Ch]
  CUtlMap<char const *,int,unsigned short>::CKeyLess v22; // [esp+8h] [ebp-18h] BYREF
  CUtlMap<char const *,int,unsigned short>::CKeyLess v23; // [esp+Ch] [ebp-14h] BYREF
  CUtlMap<char const *,int,unsigned short>::CKeyLess putf8Buffer; // [esp+10h] [ebp-10h] BYREF
  int v25; // [esp+14h] [ebp-Ch]
  CUtlMap<char const *,int,unsigned short>::CKeyLess v26; // [esp+18h] [ebp-8h] BYREF
  bool (__cdecl **v27)(const char *const *, const char *const *); // [esp+1Ch] [ebp-4h] BYREF

  if ( !GASFnCall::CheckThisPtr(this: a2, type: 8u) )
  {
    GASFnCall::ThisPtrError(this: a2, a2: (const char *)&stru_10299D8C.m_pObject, a3: nullptr, a4: 0);
    return;
  }
  v2 = a2[2];
  if ( v2 != nullptr )
    p_cxItem = &v2[-1].cxItem;
  else
    p_cxItem = nullptr;
  if ( (int)a2[7] < 1 )
  {
    v4 = a2[1];
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v4, a2: (int)v4);
    *(double *)&v4->cItems = -1.0;
    LOBYTE(v4->cbSize) = 3;
    return;
  }
  v5 = (tagRID_DEVICE_INFO_KEYBOARD *)a2[6];
  v6 = (unsigned __int8 *)GASFnCall::Arg(this: a2, a2: 0);
  GASValue::ToStringImpl(this: v6, a2: (int *)&v27, a3: v5, precision: -1, debug: false);
  if ( GASString::GetLength(this: (const char ***)&v27) == 0 )
  {
    v7 = a2[1];
    if ( LOBYTE(v7->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)a2[1], (int)a2);
    v8 = 0.0;
LABEL_29:
    LOBYTE(v7->cbSize) = 3;
    *(double *)&v7->cItems = v8;
    goto LABEL_30;
  }
  putf8Buffer.m_LessFunc = *v27;
  v9 = *(bool (__cdecl **)(const char *const *, const char *const *))p_cxItem[13];
  v10 = 0;
  v11 = (int)a2[7] <= 1;
  v26.m_LessFunc = v9;
  v25 = 0;
  if ( !v11 )
  {
    v20 = (_SERVICE_STATUS *)a2[6];
    v12 = (GASValue *)GASFnCall::Arg(this: a2, a2: 1);
    v25 = (int)GASValue::ToNumber(this: v12, (int)a2, a3: a1, result: v20);
  }
  Char = GUTF8Util::DecodeNextChar((CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer);
  v13 = GUTF8Util::DecodeNextChar(putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&v26);
  if ( v13 == 0 )
  {
LABEL_26:
    v7 = a2[1];
    if ( LOBYTE(v7->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)a2[1], (int)a2);
    v8 = -1.0;
    goto LABEL_29;
  }
  while ( 1 )
  {
    if ( v10 < v25 || v13 != Char )
      goto LABEL_25;
    v23.m_LessFunc = v26.m_LessFunc;
    v22.m_LessFunc = putf8Buffer.m_LessFunc;
    v14 = GUTF8Util::DecodeNextChar(putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&v23);
    v15 = GUTF8Util::DecodeNextChar(putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&v22);
    if ( v14 != 0 )
      break;
LABEL_23:
    if ( v15 == 0 )
      goto LABEL_33;
    if ( v14 == 0 )
    {
      GASValue::SetInt(this: (int)a2[1], result: (tagCOMPAREITEMSTRUCT *)0xFFFFFFFF);
      v19 = (const char **)v27;
      v17 = v27[2] == (bool (__cdecl *)(const char *const *, const char *const *))1;
      v27[2] = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v27[2] - 1);
      if ( v17 )
        GASStringNode::ReleaseNode(a1: (int)v19);
      return;
    }
LABEL_25:
    ++v10;
    v13 = GUTF8Util::DecodeNextChar(putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&v26);
    if ( v13 == 0 )
      goto LABEL_26;
  }
  while ( v15 != 0 )
  {
    if ( v14 == v15 )
    {
      v14 = GUTF8Util::DecodeNextChar(putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&v23);
      v15 = GUTF8Util::DecodeNextChar(putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&v22);
      if ( v14 != 0 )
        continue;
    }
    goto LABEL_23;
  }
LABEL_33:
  v18 = a2[1];
  if ( LOBYTE(v18->cbSize) >= 5u )
    GASValue::DropRefs(this: (GASValue *)a2[1], (int)a2);
  LOBYTE(v18->cbSize) = 4;
  v18->cItems = v10;
LABEL_30:
  v16 = (const char **)v27;
  v17 = v27[2] == (bool (__cdecl *)(const char *const *, const char *const *))1;
  v27[2] = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v27[2] - 1);
  if ( v17 )
    GASStringNode::ReleaseNode(a1: (int)v16);
}

//------------------------------------------------------------------------------
// Address: 0x10108D00
// Name: public: static void GASStringProto::StringLastIndexOf(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASStringProto::StringLastIndexOf(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int *p_cxItem; // eax
  GASFnCall v4; // esi
  tagRID_DEVICE_INFO_KEYBOARD *v5; // esi
  unsigned __int8 *v6; // eax
  double Length; // st7
  GASFnCall v8; // esi
  GASValue *v9; // eax
  int v10; // ebx
  unsigned int v11; // eax
  unsigned int v12; // esi
  unsigned int v13; // eax
  GASFnCall v14; // esi
  const char **v15; // eax
  bool v16; // zf
  const char **v17; // eax
  _SERVICE_STATUS *v18; // [esp-Ch] [ebp-38h]
  unsigned int Char; // [esp+8h] [ebp-24h]
  int v20; // [esp+Ch] [ebp-20h]
  CUtlMap<char const *,int,unsigned short>::CKeyLess v21; // [esp+10h] [ebp-1Ch] BYREF
  CUtlMap<char const *,int,unsigned short>::CKeyLess v22; // [esp+14h] [ebp-18h] BYREF
  CUtlMap<char const *,int,unsigned short>::CKeyLess putf8Buffer; // [esp+18h] [ebp-14h] BYREF
  int v24; // [esp+1Ch] [ebp-10h]
  CUtlMap<char const *,int,unsigned short>::CKeyLess v25; // [esp+20h] [ebp-Ch] BYREF
  bool (__cdecl **v26)(const char *const *, const char *const *); // [esp+24h] [ebp-8h] BYREF
  bool (__cdecl **v27)(const char *const *, const char *const *); // [esp+28h] [ebp-4h] BYREF

  if ( !GASFnCall::CheckThisPtr(this: a2, type: 8u) )
  {
    GASFnCall::ThisPtrError(this: a2, a2: (const char *)&stru_10299D8C.m_pObject, a3: nullptr, a4: 0);
    return;
  }
  v2 = a2[2];
  if ( v2 != nullptr )
    p_cxItem = &v2[-1].cxItem;
  else
    p_cxItem = nullptr;
  if ( (int)a2[7] < 1 )
  {
    v4 = a2[1];
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)a2[1], (int)a2);
    LOBYTE(v4->cbSize) = 3;
    *(double *)&v4->cItems = -1.0;
    return;
  }
  v26 = (bool (__cdecl **)(const char *const *, const char *const *))p_cxItem[13];
  v26[2] = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v26[2] + 1);
  v5 = (tagRID_DEVICE_INFO_KEYBOARD *)a2[6];
  v6 = (unsigned __int8 *)GASFnCall::Arg(this: a2, a2: 0);
  GASValue::ToStringImpl(this: v6, a2: (int *)&v27, a3: v5, precision: -1, debug: false);
  if ( GASString::GetLength(this: (const char ***)&v27) != 0 )
  {
    v25.m_LessFunc = *v26;
    putf8Buffer.m_LessFunc = *v27;
    v24 = 0x7FFFFFF;
    if ( (int)a2[7] > 1 )
    {
      v18 = (_SERVICE_STATUS *)a2[6];
      v9 = (GASValue *)GASFnCall::Arg(this: a2, a2: 1);
      v24 = (int)GASValue::ToNumber(this: v9, (int)a2, a3: a1, result: v18);
    }
    Char = GUTF8Util::DecodeNextChar((CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer);
    v20 = -1;
    v10 = 0;
    v11 = GUTF8Util::DecodeNextChar(putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&v25);
    if ( v11 == 0 )
    {
LABEL_27:
      v14 = a2[1];
      if ( LOBYTE(v14->cbSize) >= 5u )
        GASValue::DropRefs(this: (GASValue *)a2[1], (int)a2);
      LOBYTE(v14->cbSize) = 4;
      v14->cItems = v20;
      goto LABEL_30;
    }
    while ( v10 > v24 || v11 != Char )
    {
LABEL_26:
      ++v10;
      v11 = GUTF8Util::DecodeNextChar(putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&v25);
      if ( v11 == 0 )
        goto LABEL_27;
    }
    v22.m_LessFunc = v25.m_LessFunc;
    v21.m_LessFunc = putf8Buffer.m_LessFunc;
    v12 = GUTF8Util::DecodeNextChar(putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&v22);
    v13 = GUTF8Util::DecodeNextChar(putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&v21);
    if ( v12 != 0 )
    {
      while ( v13 != 0 )
      {
        if ( v12 == v13 )
        {
          v12 = GUTF8Util::DecodeNextChar(putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&v22);
          v13 = GUTF8Util::DecodeNextChar(putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&v21);
          if ( v12 != 0 )
            continue;
        }
        goto LABEL_23;
      }
    }
    else
    {
LABEL_23:
      if ( v13 != 0 )
        goto LABEL_25;
    }
    v20 = v10;
LABEL_25:
    if ( v12 == 0 )
      goto LABEL_27;
    goto LABEL_26;
  }
  Length = (double)(unsigned int)GASString::GetLength(this: (const char ***)&v26);
  v8 = a2[1];
  if ( LOBYTE(v8->cbSize) >= 5u )
    GASValue::DropRefs(this: (GASValue *)v8, (int)a2);
  LOBYTE(v8->cbSize) = 3;
  *(double *)&v8->cItems = Length;
LABEL_30:
  v15 = (const char **)v27;
  v16 = v27[2] == (bool (__cdecl *)(const char *const *, const char *const *))1;
  v27[2] = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v27[2] - 1);
  if ( v16 )
    GASStringNode::ReleaseNode(a1: (int)v15);
  v17 = (const char **)v26;
  v16 = v26[2] == (bool (__cdecl *)(const char *const *, const char *const *))1;
  v26[2] = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v26[2] - 1);
  if ( v16 )
    GASStringNode::ReleaseNode(a1: (int)v17);
}

//------------------------------------------------------------------------------
// Address: 0x10108EE0
// Name: public: static void GASStringProto::StringToLowerCase(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASStringProto::StringToLowerCase(GASFnCall *a1)
{
  GASFnCall v1; // eax
  int **p_cxItem; // eax
  int *v3; // eax
  GASFnCall v4; // esi
  int *v5; // edi
  int v6; // eax
  int v7; // eax
  int v9; // [esp+4h] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a1, type: 8u) )
  {
    v1 = a1[2];
    if ( v1 != nullptr )
      p_cxItem = (int **)&v1[-1].cxItem;
    else
      p_cxItem = nullptr;
    v3 = GASString::ToLower(this: p_cxItem + 13, a2: &v9);
    v4 = a1[1];
    v5 = v3;
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v4, a2: (int)v3);
    LOBYTE(v4->cbSize) = 5;
    v6 = *v5;
    v4->cItems = *v5;
    ++*(_DWORD *)(v6 + 8);
    v7 = v9;
    if ( (*(_DWORD *)(v9 + 8))-- == 1 )
      GASStringNode::ReleaseNode(a1: v7);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: (const char *)&stru_10299D8C.m_pObject, a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108F60
// Name: public: static void GASStringProto::StringToUpperCase(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASStringProto::StringToUpperCase(GASFnCall *a1)
{
  GASFnCall v1; // eax
  int **p_cxItem; // eax
  struct GASStringNode **v3; // eax
  GASFnCall v4; // esi
  int *v5; // edi
  int v6; // eax
  struct GASStringNode *v7; // eax
  struct GASStringNode *v9; // [esp+4h] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a1, type: 8u) )
  {
    v1 = a1[2];
    if ( v1 != nullptr )
      p_cxItem = (int **)&v1[-1].cxItem;
    else
      p_cxItem = nullptr;
    v3 = GASString::ToUpper(this: p_cxItem + 13, a2: &v9);
    v4 = a1[1];
    v5 = (int *)v3;
    if ( LOBYTE(v4->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v4, a2: (int)v3);
    LOBYTE(v4->cbSize) = 5;
    v6 = *v5;
    v4->cItems = *v5;
    ++*(_DWORD *)(v6 + 8);
    v7 = v9;
    if ( (*((_DWORD *)v9 + 2))-- == 1 )
      GASStringNode::ReleaseNode(a1: (int)v7);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: (const char *)&stru_10299D8C.m_pObject, a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108FE0
// Name: public: static void GASStringProto::StringValueOf(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASStringProto::StringValueOf(GASFnCall *a1)
{
  GASFnCall v1; // eax
  int p_cxItem; // edi
  GASFnCall v3; // esi
  int v4; // eax

  if ( GASFnCall::CheckThisPtr(this: a1, type: 8u) )
  {
    v1 = a1[2];
    if ( v1 != nullptr )
      p_cxItem = (int)&v1[-1].cxItem;
    else
      p_cxItem = 0;
    v3 = a1[1];
    if ( LOBYTE(v3->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v3, a2: p_cxItem);
    LOBYTE(v3->cbSize) = 5;
    v4 = *(_DWORD *)(p_cxItem + 52);
    v3->cItems = v4;
    ++*(_DWORD *)(v4 + 8);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: (const char *)&stru_10299D8C.m_pObject, a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109040
// Name: public: static void GASStringProto::StringLocaleCompare(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASStringProto::StringLocaleCompare(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall *v2; // esi
  GASValue *v3; // edi
  GASFnCall v4; // eax
  CUtlMap<char const *,int,unsigned short>::CKeyLess **p_cxItem; // ebx
  tagRID_DEVICE_INFO_KEYBOARD *v6; // edi
  unsigned __int8 *v7; // eax
  char *v8; // eax
  bool (__cdecl *v9)(const char *const *, const char *const *); // edi
  unsigned int Length; // eax
  int v11; // eax
  GASFnCall v12; // esi
  GASFnCall *v13; // eax
  bool v14; // zf
  tagPOLYTEXTW *v15; // [esp-8h] [ebp-14h]
  bool v16; // [esp+8h] [ebp-4h]
  bool v17[4]; // [esp+8h] [ebp-4h]

  v2 = a2;
  v3 = (GASValue *)a2[1];
  GASValue::DropRefs(this: v3, a2: (int)v3);
  *(_BYTE *)v3 = 0;
  if ( *(_BYTE *)(v2[6][3].cbSize + 684) == 1 )
  {
    if ( GASFnCall::CheckThisPtr(this: v2, type: 8u) )
    {
      v4 = v2[2];
      if ( v4 != nullptr )
        p_cxItem = (CUtlMap<char const *,int,unsigned short>::CKeyLess **)&v4[-1].cxItem;
      else
        p_cxItem = nullptr;
      if ( (int)v2[7] >= 1 )
      {
        v6 = (tagRID_DEVICE_INFO_KEYBOARD *)v2[6];
        v7 = (unsigned __int8 *)GASFnCall::Arg(this: v2, a2: 0);
        GASValue::ToStringImpl(this: v7, (int *)&a2, a3: v6, precision: -1, debug: false);
        v16 = true;
        if ( (int)v2[7] >= 2 )
        {
          v15 = (tagPOLYTEXTW *)v2[6];
          v8 = (char *)GASFnCall::Arg(this: v2, a2: 1);
          v16 = GASValue::ToBool(a1: v8, a2: a1, result: v15) == 0;
        }
        v9 = (bool (__cdecl *)(const char *const *, const char *const *))*a2;
        Length = GASString::GetLength(this: (const char ***)&a2);
        v11 = GASString::LocaleCompare_CaseCheck(this: p_cxItem + 13, a2: v9, len: Length, caseSensitive: v16);
        v12 = v2[1];
        *(_DWORD *)v17 = v11;
        if ( LOBYTE(v12->cbSize) >= 5u )
          GASValue::DropRefs(this: (GASValue *)v12, a2: (int)v9);
        LOBYTE(v12->cbSize) = 3;
        *(double *)&v12->cItems = (double)*(int *)v17;
        v13 = a2;
        v14 = a2[2] == (GASFnCall)1;
        a2[2] = (GASFnCall)((char *)a2[2] - 1);
        if ( v14 )
          GASStringNode::ReleaseNode(a1: (int)v13);
      }
    }
    else
    {
      GASFnCall::ThisPtrError(this: v2, a2: (const char *)&stru_10299D8C.m_pObject, a3: nullptr, a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109140
// Name: public: static void GASStringCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStringCtorFunction::GlobalCtor(void *fn, _CONNECTDLGSTRUCTW fna)
{
  unsigned int cbStructure; // esi
  bool v3; // zf
  int v4; // eax
  int v5; // edi
  char v6; // bl
  tagWNDCLASSW *v7; // eax
  tagWNDCLASSW *v8; // eax
  int v9; // eax
  int v10; // ecx
  int v11; // esi
  int v12; // edi
  int v13; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v14; // edi
  unsigned __int8 *v15; // eax
  int v16; // esi
  unsigned int v17; // eax
  GASValue v18[4]; // [esp+8h] [ebp-34h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *retVal; // [esp+18h] [ebp-24h] BYREF
  GASValue v20; // [esp+28h] [ebp-14h] BYREF
  int v21; // [esp+2Ch] [ebp-10h]
  int v22; // [esp+38h] [ebp-4h]

  cbStructure = fna.cbStructure;
  v3 = *(_DWORD *)(fna.cbStructure + 8) == 0;
  v22 = 0;
  if ( v3
    || (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(fna.cbStructure + 8) + 8))(a1: *(_DWORD *)(fna.cbStructure + 8)) != 8
    || (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(cbStructure + 8) + 64))(a1: *(_DWORD *)(cbStructure + 8)) != 0 )
  {
    if ( *(_DWORD *)(cbStructure + 28) != 0 )
    {
      v14 = *(tagRID_DEVICE_INFO_KEYBOARD **)(cbStructure + 24);
      v15 = (unsigned __int8 *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 0);
      GASValue::ToStringImpl(this: v15, a2: (int *)&fna, a3: v14, precision: -1, debug: false);
      v16 = *(_DWORD *)(cbStructure + 4);
      if ( *(_BYTE *)v16 >= 5u )
        GASValue::DropRefs(this: (GASValue *)v16, a2: (int)v14);
      *(_BYTE *)v16 = 5;
      *(_DWORD *)(v16 + 4) = fna.cbStructure;
      ++*(_DWORD *)(fna.cbStructure + 8);
      v17 = fna.cbStructure;
      v3 = (*(_DWORD *)(fna.cbStructure + 8))-- == 1;
      if ( v3 )
        GASStringNode::ReleaseNode(a1: v17);
    }
    else
    {
      v10 = *(_DWORD *)(cbStructure + 24);
      v11 = *(_DWORD *)(cbStructure + 4);
      v12 = *(_DWORD *)(v10 + 120);
      if ( *(_BYTE *)v11 >= 5u )
        GASValue::DropRefs(this: (GASValue *)v11, a2: v12);
      *(_BYTE *)v11 = 5;
      v13 = *(_DWORD *)(v12 + 8);
      *(_DWORD *)(v11 + 4) = v13;
      ++*(_DWORD *)(v13 + 8);
    }
  }
  else
  {
    v4 = *(_DWORD *)(cbStructure + 8);
    if ( v4 != 0 )
      v5 = v4 - 16;
    else
      v5 = 0;
    if ( *(int *)(cbStructure + 28) <= 0 )
    {
      v9 = *(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120);
      LOBYTE(v20) = 5;
      v21 = *(_DWORD *)(v9 + 8);
      ++*(_DWORD *)(v21 + 8);
      v6 = 2;
      v8 = (tagWNDCLASSW *)&v20;
    }
    else
    {
      v6 = 1;
      v7 = (tagWNDCLASSW *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 0);
      v8 = (tagWNDCLASSW *)GASValue::GASValue(this: v18, v: v7);
    }
    GASValue::GASValue(this: &retVal, v: v8);
    if ( (v6 & 2) != 0 )
    {
      v6 &= ~2u;
      GASValue::~GASValue(this: &v20, a2: v5);
    }
    if ( (v6 & 1) != 0 )
      GASValue::~GASValue(this: v18, a2: v5);
    (*(void (__thiscall **)(int, _DWORD, CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **))(*(_DWORD *)v5 + 12))(
      a1: v5,
      a2: *(_DWORD *)(cbStructure + 24),
      a3: &retVal);
    GASValue::operator=(this: *(_DWORD *)(cbStructure + 4), v: (tagWNDCLASSW *)&retVal);
    GASValue::~GASValue(this: &retVal, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101093B0
// Name: protected: virtual void GASStringObject::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStringObject::Finalize_GC(GASObject *this)
{
  int v2; // ecx

  v2 = *((_DWORD *)this + 13);
  if ( (*(_DWORD *)(v2 + 8))-- == 1 )
    GASStringNode::ReleaseNode(a1: v2);
  GASObject::Finalize_GC(this);
}

//------------------------------------------------------------------------------
// Address: 0x10109420
// Name: public: static void GASStringProto::StringCharAt(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASStringProto::StringCharAt(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  unsigned int **p_cxItem; // ebx
  GASValue *v4; // eax
  signed int v5; // esi
  unsigned int CharAt; // eax
  unsigned __int8 ***appended; // eax
  char **v8; // esi
  char **v9; // eax
  bool v10; // zf
  unsigned __int8 **v11; // eax
  GASFnCall v12; // edi
  char **v13; // eax
  _SERVICE_STATUS *v14; // [esp-Ch] [ebp-18h]
  unsigned __int8 **v15; // [esp+4h] [ebp-8h] BYREF
  char **v16; // [esp+8h] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a2, type: 8u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = (unsigned int **)&v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v16 = *(char ***)(a2[6][3].cbSize + 8);
    ++v16[2];
    v14 = (_SERVICE_STATUS *)a2[6];
    v4 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
    v5 = (int)GASValue::ToNumber(this: v4, (int)a2, a3: a1, result: v14);
    if ( v5 >= 0 && v5 < GASString::GetLength(this: (const char ***)p_cxItem + 13) )
    {
      CharAt = GASString::GetCharAt(this: p_cxItem + 13, index: v5);
      appended = GASString::AppendChar(this: &v16, a2: &v15, a3: CharAt);
      v8 = (char **)*appended;
      ++(*appended)[2];
      v9 = v16;
      v10 = v16[2]-- == (char *)1;
      if ( v10 )
        GASStringNode::ReleaseNode(a1: (int)v9);
      v11 = v15;
      v16 = v8;
      v10 = v15[2]-- == (unsigned __int8 *)1;
      if ( v10 )
        GASStringNode::ReleaseNode(a1: (int)v11);
    }
    v12 = a2[1];
    if ( LOBYTE(v12->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v12, a2: (int)v12);
    LOBYTE(v12->cbSize) = 5;
    v12->cItems = (int)v16;
    ++v16[2];
    v13 = v16;
    v10 = v16[2]-- == (char *)1;
    if ( v10 )
      GASStringNode::ReleaseNode(a1: (int)v13);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: (const char *)&stru_10299D8C.m_pObject, a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109510
// Name: public: static void GASStringProto::StringConcat(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASStringProto::StringConcat(GASFnCall *a1)
{
  GASFnCall v1; // eax
  char ***p_cxItem; // eax
  int i; // edi
  tagRID_DEVICE_INFO_KEYBOARD *v4; // ebx
  unsigned __int8 *v5; // eax
  int v6; // eax
  bool v7; // zf
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *m_pfnProxied; // eax
  struct GASStringNode *StringNode; // edi
  GASFnCall v10; // esi
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> v11; // [esp+4h] [ebp-1Ch] BYREF
  int v12; // [esp+1Ch] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a1, type: 8u) )
  {
    v1 = a1[2];
    if ( v1 != nullptr )
      p_cxItem = (char ***)&v1[-1].cxItem;
    else
      p_cxItem = nullptr;
    GStringBuffer::GStringBuffer(
      this: (GStringBuffer *)&v11,
      src: *p_cxItem[13],
      count: (unsigned int)p_cxItem[13][4],
      a4: GMemory::pGlobalHeap);
    for ( i = 0; i < (int)a1[7]; ++i )
    {
      v4 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
      v5 = (unsigned __int8 *)GASFnCall::Arg(this: a1, a2: i);
      GASValue::ToStringImpl(this: v5, a2: &v12, a3: v4, precision: -1, debug: false);
      GStringBuffer::AppendString(this: &v11, putf8str: *(char **)v12, utf8StrSz: -1);
      v6 = v12;
      v7 = (*(_DWORD *)(v12 + 8))-- == 1;
      if ( v7 )
        GASStringNode::ReleaseNode(a1: v6);
    }
    m_pfnProxied = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v11.m_pfnProxied;
    if ( LODWORD(v11.m_pfnProxied) == 0 )
      m_pfnProxied = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&pMem;
    StringNode = GASStringManager::CreateStringNode(
                   this: *(GASStringManager **)(a1[6][3].cbSize + 636),
                   result: m_pfnProxied,
                   length: DWORD1(v11.m_pfnProxied));
    ++*((_DWORD *)StringNode + 2);
    v10 = a1[1];
    if ( LOBYTE(v10->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v10, a2: (int)StringNode);
    LOBYTE(v10->cbSize) = 5;
    v10->cItems = (int)StringNode;
    v7 = ++*((_DWORD *)StringNode + 2) == 1;
    --*((_DWORD *)StringNode + 2);
    if ( v7 )
      GASStringNode::ReleaseNode(a1: (int)StringNode);
    GStringBuffer::~GStringBuffer(this: &v11);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: (const char *)&stru_10299D8C.m_pObject, a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109610
// Name: public: static class GASString GASStringProto::StringSubstring(class GASString const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
struct GASStringNode **__cdecl GASStringProto::StringSubstring(
        struct GASStringNode **a1,
        const char ***self,
        int start,
        int length)
{
  int v4; // edi
  int v6; // ecx
  int v7; // esi
  int v8; // eax
  int v9; // ecx

  v4 = length;
  if ( length != 0 )
  {
    v7 = start;
    if ( start < 0 )
      v7 = 0;
    v8 = GASString::GetLength(this: self);
    if ( v7 < v8 )
    {
      if ( length < 0 || v7 + length > v8 )
        v4 = v8 - v7;
      GASString::Substring(this: self, a2: a1, start: v7, end: v7 + v4);
      return a1;
    }
    else
    {
      v9 = *(_DWORD *)(*(_DWORD *)((unsigned int)*self & 0xFFFFFC00) + 32);
      *a1 = (struct GASStringNode *)v9;
      ++*(_DWORD *)(v9 + 8);
      return a1;
    }
  }
  else
  {
    v6 = *(_DWORD *)(*(_DWORD *)((unsigned int)*self & 0xFFFFFC00) + 32);
    *a1 = (struct GASStringNode *)v6;
    ++*(_DWORD *)(v6 + 8);
    return a1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109690
// Name: public: static class GASString GASStringProto::CreateStringFromCStr(class GASStringContext __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CD3D11_RASTERIZER_DESC *__cdecl GASStringProto::CreateStringFromCStr(
        CD3D11_RASTERIZER_DESC *result,
        int psc,
        char *psc_4,
        int psc_8)
{
  signed int v4; // eax
  struct GASStringNode *StringNode; // eax
  D3D11_FILL_MODE v7; // ecx

  if ( psc_8 != 0 )
    v4 = psc_8 - (_DWORD)psc_4;
  else
    v4 = strlen(psc_4);
  if ( v4 <= 0 )
  {
    v7 = *(_DWORD *)(*(_DWORD *)psc + 8);
    ++*(_DWORD *)(v7 + 8);
    result->FillMode = v7;
  }
  else
  {
    StringNode = GASStringManager::CreateStringNode(
                   this: *(GASStringManager **)(*(_DWORD *)psc + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)psc_4,
                   length: v4);
    ++*((_DWORD *)StringNode + 2);
    result->FillMode = (D3D11_FILL_MODE)StringNode;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101096F0
// Name: public: static void GASStringProto::StringSubstr(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASStringProto::StringSubstr(double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int v3; // ebx
  int v4; // edi
  GASValue *v5; // eax
  GASValue *v6; // eax
  struct GASStringNode **v7; // eax
  GASFnCall v8; // esi
  int *v9; // edi
  int v10; // eax
  struct GASStringNode *v11; // eax
  bool v12; // zf
  _SERVICE_STATUS *v13; // [esp-Ch] [ebp-14h]
  _SERVICE_STATUS *v14; // [esp-Ch] [ebp-14h]
  const char ***p_cxItem; // [esp+4h] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a2, type: 8u) )
  {
    v2 = a2[2];
    v3 = 0;
    if ( v2 != nullptr )
      p_cxItem = (const char ***)&v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = -1;
    if ( (int)a2[7] >= 1 )
    {
      v13 = (_SERVICE_STATUS *)a2[6];
      v5 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
      a1 = GASValue::ToNumber(this: v5, a2: -1, a3: a1, result: v13);
      v3 = (int)a1;
      if ( (int)a1 < 0 )
        v3 += GASString::GetLength(this: p_cxItem + 13);
    }
    if ( (int)a2[7] >= 2 )
    {
      v14 = (_SERVICE_STATUS *)a2[6];
      v6 = (GASValue *)GASFnCall::Arg(this: a2, a2: 1);
      v4 = (int)GASValue::ToNumber(this: v6, a2: -1, a3: a1, result: v14);
      if ( v4 < 0 )
        v4 = 0;
    }
    v7 = GASStringProto::StringSubstring(
           a1: (struct GASStringNode **)&p_cxItem,
           self: p_cxItem + 13,
           start: v3,
           length: v4);
    v8 = a2[1];
    v9 = (int *)v7;
    if ( LOBYTE(v8->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v8, a2: (int)v7);
    LOBYTE(v8->cbSize) = 5;
    v10 = *v9;
    v8->cItems = *v9;
    ++*(_DWORD *)(v10 + 8);
    v11 = (struct GASStringNode *)p_cxItem;
    v12 = p_cxItem[2] == (const char **)1;
    p_cxItem[2] = (const char **)((char *)p_cxItem[2] - 1);
    if ( v12 )
      GASStringNode::ReleaseNode(a1: (int)v11);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: (const char *)&stru_10299D8C.m_pObject, a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101097E0
// Name: public: static void GASStringProto::StringSubstring(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASStringProto::StringSubstring(double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int v3; // esi
  int v4; // ebx
  GASValue *v5; // eax
  GASValue *v6; // eax
  int v7; // ebx
  GASFnCall v8; // edi
  unsigned int cbSize; // esi
  int v10; // eax
  int v11; // eax
  struct GASStringNode **v12; // eax
  GASFnCall v13; // edi
  int *v14; // esi
  int v15; // eax
  struct GASStringNode *v16; // eax
  bool v17; // zf
  _SERVICE_STATUS *v18; // [esp-Ch] [ebp-14h]
  _SERVICE_STATUS *v19; // [esp-Ch] [ebp-14h]
  const char ***p_cxItem; // [esp+4h] [ebp-4h] BYREF

  if ( !GASFnCall::CheckThisPtr(this: a2, type: 8u) )
  {
    GASFnCall::ThisPtrError(this: a2, a2: (const char *)&stru_10299D8C.m_pObject, a3: nullptr, a4: 0);
    return;
  }
  v2 = a2[2];
  v3 = 0;
  if ( v2 != nullptr )
    p_cxItem = (const char ***)&v2[-1].cxItem;
  else
    p_cxItem = nullptr;
  v4 = -1;
  if ( (int)a2[7] >= 1 )
  {
    v18 = (_SERVICE_STATUS *)a2[6];
    v5 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
    a1 = GASValue::ToNumber(this: v5, (int)a2, a3: a1, result: v18);
    v3 = (int)a1;
  }
  if ( (int)a2[7] >= 2 )
  {
    v19 = (_SERVICE_STATUS *)a2[6];
    v6 = (GASValue *)GASFnCall::Arg(this: a2, a2: 1);
    v7 = (int)GASValue::ToNumber(this: v6, (int)a2, a3: a1, result: v19);
    if ( v7 < v3 )
    {
      if ( v3 >= GASString::GetLength(this: p_cxItem + 13) )
      {
        v8 = a2[1];
        cbSize = a2[6][3].cbSize;
        if ( LOBYTE(v8->cbSize) >= 5u )
          GASValue::DropRefs(this: (GASValue *)v8, a2: (int)v8);
        LOBYTE(v8->cbSize) = 5;
        v10 = *(_DWORD *)(cbSize + 8);
        v8->cItems = v10;
        ++*(_DWORD *)(v10 + 8);
        return;
      }
      v11 = v3;
      v3 = v7;
      v7 = v11;
    }
    if ( v3 < 0 )
      v3 = 0;
    v4 = v7 - v3;
  }
  v12 = GASStringProto::StringSubstring(
          a1: (struct GASStringNode **)&p_cxItem,
          self: p_cxItem + 13,
          start: v3,
          length: v4);
  v13 = a2[1];
  v14 = (int *)v12;
  if ( LOBYTE(v13->cbSize) >= 5u )
    GASValue::DropRefs(this: (GASValue *)v13, a2: (int)v13);
  LOBYTE(v13->cbSize) = 5;
  v15 = *v14;
  v13->cItems = *v14;
  ++*(_DWORD *)(v15 + 8);
  v16 = (struct GASStringNode *)p_cxItem;
  v17 = p_cxItem[2] == (const char **)1;
  p_cxItem[2] = (const char **)((char *)p_cxItem[2] - 1);
  if ( v17 )
    GASStringNode::ReleaseNode(a1: (int)v16);
}

//------------------------------------------------------------------------------
// Address: 0x10109900
// Name: private: static void GASStringCtorFunction::StringFromCharCode(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __usercall GASStringCtorFunction::StringFromCharCode@<al>(double a1@<st0>, int fna)
{
  int i; // edi
  GASValue *v4; // eax
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v5; // eax
  struct GASStringNode *StringNode; // edi
  int v7; // esi
  bool v8; // zf
  _SERVICE_STATUS *v10; // [esp-4h] [ebp-2Ch]
  __int128 v11; // [esp+0h] [ebp-28h] OVERLAPPED BYREF
  CMatRenderContextBase *v12[2]; // [esp+20h] [ebp-8h]

  GStringBuffer::GStringBuffer(
    this: (_DWORD *)&v11 + 2,
    result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)GMemory::pGlobalHeap);
  for ( i = 0; i < *(_DWORD *)(fna + 28); ++i )
  {
    v10 = *(_SERVICE_STATUS **)(fna + 24);
    v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: i);
    a1 = GASValue::ToNumber(this: v4, a2: i, a3: a1, result: v10);
    *(_QWORD *)v12 = (__int64)a1;
    GStringBuffer::AppendChar(
      this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&v11 + 8),
      ch: (CMatRenderContextBase *)(__int64)a1,
      srcSize: v11);
  }
  v5 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)DWORD2(v11);
  if ( DWORD2(v11) == 0 )
    v5 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&pMem;
  StringNode = GASStringManager::CreateStringNode(
                 this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(fna + 24) + 120) + 636),
                 result: v5,
                 length: HIDWORD(v11));
  ++*((_DWORD *)StringNode + 2);
  v7 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v7 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v7, a2: (int)StringNode);
  *(_BYTE *)v7 = 5;
  *(_DWORD *)(v7 + 4) = StringNode;
  v8 = ++*((_DWORD *)StringNode + 2) == 1;
  --*((_DWORD *)StringNode + 2);
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)StringNode);
  return GStringBuffer::~GStringBuffer(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&v11 + 8));
}

//------------------------------------------------------------------------------
// Address: 0x101099C0
// Name: public: virtual class GASObject __near * GASStringCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStringCtorFunction::CreateNewObject(ID3D11DomainShader *this, ID3D11DomainShader *penv)
{
  struct GASEnvironment *v2; // ebx
  void (__stdcall *GetDevice)(ID3D11DeviceChild *, ID3D11Device **); // ecx
  int (__thiscall *v4)(void (__stdcall *)(ID3D11DeviceChild *, ID3D11Device **), int, int *); // edx
  vc_attributes::PreRangeAttribute **v5; // edi
  GASObject *v6; // eax
  GASObject *v7; // esi
  const char *MaxVal; // eax
  vc_attributes::InvalidCheckAttribute *Prototype; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // edx
  int p_MaxVal; // [esp-Ch] [ebp-2Ch]
  GASValue v12[4]; // [esp+Ch] [ebp-14h] BYREF
  int v13; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (struct GASEnvironment *)penv;
  GetDevice = penv[30].__vftable[23].GetDevice;
  v4 = *(int (__thiscall **)(void (__stdcall *)(ID3D11DeviceChild *, ID3D11Device **), int, int *))(*(_DWORD *)GetDevice
                                                                                                  + 40);
  v5 = (vc_attributes::PreRangeAttribute **)&penv[30];
  v13 = 323;
  v6 = (GASObject *)v4(a1: GetDevice, a2: 56, a3: &v13);
  v7 = v6;
  if ( v6 != nullptr )
  {
    GASObject::GASObject(this: v6, a2: v2);
    v7->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASStringObject::`vftable'{for `GASRefCountBase<GASObject>'};
    v7[2].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASStringObject::`vftable'{for `GASObjectInterface'};
    MaxVal = (*v5)->MaxVal;
    v7[6].sequence = (int)MaxVal;
    ++*((_DWORD *)MaxVal + 2);
    Prototype = GASGlobalContext::GetPrototype(this: *v5, result: (vc_attributes::InvalidCheckAttribute *)3);
    ((void (__thiscall *)(CTSQueue<CFunctor *,0,1>::Node_t **, vc_attributes::PreRangeAttribute **, vc_attributes::InvalidCheckAttribute *))v7[2].pNode[6].elem)(
      a1: &v7[2].pNode,
      a2: v5,
      a3: Prototype);
  }
  else
  {
    v7 = nullptr;
  }
  pNext = v7[2].pNode[5].pNext;
  p_MaxVal = (int)&(*v5)[52].MaxVal;
  HIBYTE(penv) = 0;
  LOBYTE(v12[0]) = 10;
  ((void (__thiscall *)(GASObject *, vc_attributes::PreRangeAttribute **, int, GASValue *, char *))pNext)(
    a1: &v7[2],
    a2: v5,
    a3: p_MaxVal,
    a4: v12,
    a5: (char *)&penv + 3);
  GASValue::~GASValue(this: v12, a2: (int)v5);
}

//------------------------------------------------------------------------------
// Address: 0x10109AB0
// Name: public: static void GASStringProto::StringSlice(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASStringProto::StringSlice(double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int v3; // edi
  int v4; // ebx
  GASValue *v5; // eax
  GASValue *v6; // eax
  int v7; // ebx
  GASFnCall v8; // esi
  unsigned int cbSize; // edi
  int v10; // eax
  struct GASStringNode **v11; // eax
  GASFnCall v12; // esi
  int *v13; // edi
  int v14; // eax
  struct GASStringNode *v15; // eax
  bool v16; // zf
  _SERVICE_STATUS *v17; // [esp-Ch] [ebp-14h]
  _SERVICE_STATUS *v18; // [esp-Ch] [ebp-14h]
  const char ***p_cxItem; // [esp+4h] [ebp-4h] BYREF

  if ( !GASFnCall::CheckThisPtr(this: a2, type: 8u) )
  {
    GASFnCall::ThisPtrError(this: a2, a2: (const char *)&stru_10299D8C.m_pObject, a3: nullptr, a4: 0);
    return;
  }
  v2 = a2[2];
  v3 = 0;
  if ( v2 != nullptr )
    p_cxItem = (const char ***)&v2[-1].cxItem;
  else
    p_cxItem = nullptr;
  v4 = -1;
  if ( (int)a2[7] >= 1 )
  {
    v17 = (_SERVICE_STATUS *)a2[6];
    v5 = (GASValue *)GASFnCall::Arg(this: a2, a2: 0);
    a1 = GASValue::ToNumber(this: v5, a2: 0, a3: a1, result: v17);
    v3 = (int)a1;
    if ( (int)a1 < 0 )
      v3 += GASString::GetLength(this: p_cxItem + 13);
  }
  if ( (int)a2[7] >= 2 )
  {
    v18 = (_SERVICE_STATUS *)a2[6];
    v6 = (GASValue *)GASFnCall::Arg(this: a2, a2: 1);
    v7 = (int)GASValue::ToNumber(this: v6, a2: v3, a3: a1, result: v18);
    if ( v7 < 0 )
      v7 += GASString::GetLength(this: p_cxItem + 13);
    if ( v7 < v3 )
    {
      v8 = a2[1];
      cbSize = a2[6][3].cbSize;
      if ( LOBYTE(v8->cbSize) >= 5u )
        GASValue::DropRefs(this: (GASValue *)v8, a2: cbSize);
      LOBYTE(v8->cbSize) = 5;
      v10 = *(_DWORD *)(cbSize + 8);
      v8->cItems = v10;
      ++*(_DWORD *)(v10 + 8);
      return;
    }
    v4 = v7 - v3;
  }
  v11 = GASStringProto::StringSubstring(
          a1: (struct GASStringNode **)&p_cxItem,
          self: p_cxItem + 13,
          start: v3,
          length: v4);
  v12 = a2[1];
  v13 = (int *)v11;
  if ( LOBYTE(v12->cbSize) >= 5u )
    GASValue::DropRefs(this: (GASValue *)v12, a2: (int)v11);
  LOBYTE(v12->cbSize) = 5;
  v14 = *v13;
  v12->cItems = *v13;
  ++*(_DWORD *)(v14 + 8);
  v15 = (struct GASStringNode *)p_cxItem;
  v16 = p_cxItem[2] == (const char **)1;
  p_cxItem[2] = (const char **)((char *)p_cxItem[2] - 1);
  if ( v16 )
    GASStringNode::ReleaseNode(a1: (int)v15);
}

//------------------------------------------------------------------------------
// Address: 0x10109F90
// Name: public: static void GASStringProto::StringSplit(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASStringProto::StringSplit(long double a1@<st0>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  int v3; // edi
  bool (__cdecl *v4)(const char *const *, const char *const *); // ebx
  tagRID_DEVICE_INFO_KEYBOARD *v5; // ebx
  unsigned __int8 *v6; // eax
  int v7; // eax
  bool v8; // zf
  bool (__cdecl **v9)(const char *const *, const char *const *); // ebx
  int v10; // eax
  int v11; // eax
  GASValue *v12; // eax
  struct GASObject *v13; // ebx
  _SERVICE_STATUS *v14; // [esp-Ch] [ebp-18h]
  struct GASObject *p_cxItem; // [esp+4h] [ebp-8h] BYREF
  int v16; // [esp+8h] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a2, type: 8u) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = (struct GASObject *)&v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v3 = *(_DWORD *)(a2[6][3].cbSize + 8);
    ++*(_DWORD *)(v3 + 8);
    v4 = nullptr;
    if ( (int)a2[7] >= 1 )
    {
      v5 = (tagRID_DEVICE_INFO_KEYBOARD *)a2[6];
      v6 = (unsigned __int8 *)GASFnCall::Arg(this: a2, a2: 0);
      GASValue::ToStringImpl(this: v6, a2: &v16, a3: v5, precision: -1, debug: false);
      v7 = v16;
      ++*(_DWORD *)(v16 + 8);
      v8 = (*(_DWORD *)(v3 + 8))-- == 1;
      v9 = (bool (__cdecl **)(const char *const *, const char *const *))v7;
      if ( v8 )
        GASStringNode::ReleaseNode(a1: v3);
      v10 = v16;
      v8 = (*(_DWORD *)(v16 + 8))-- == 1;
      v3 = (int)v9;
      if ( v8 )
        GASStringNode::ReleaseNode(a1: v10);
      v4 = *v9;
    }
    v11 = 0x3FFFFFFF;
    if ( (int)a2[7] >= 2 )
    {
      v14 = (_SERVICE_STATUS *)a2[6];
      v12 = (GASValue *)GASFnCall::Arg(this: a2, a2: 1);
      v11 = (int)GASValue::ToNumber(this: v12, a2: v3, a3: a1, result: v14);
      if ( v11 < 0 )
        v11 = 0;
    }
    GASStringProto::StringSplit(
      result: (SFUIMemoryFile *)&p_cxItem,
      putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)a2[6],
      count: (int)&p_cxItem[6].sequence,
      a4: v4,
      limit: v11);
    v13 = p_cxItem;
    GASValue::SetAsObject(this: (GASValue *)a2[1], a2: p_cxItem);
    if ( v13 != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v13, a2: v3);
    v8 = (*(_DWORD *)(v3 + 8))-- == 1;
    if ( v8 )
      GASStringNode::ReleaseNode(a1: v3);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: (const char *)&stru_10299D8C.m_pObject, a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010A0A0
// Name: public: GASStringProto::GASStringProto(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
GASStringProto *__thiscall GASStringProto::GASStringProto(GASStringProto *this, GImage *result, CTSQueue<CFunctor *,0,1>::Node_t *a3, const struct GASFunctionRef *a4)
{
  void (__thiscall *dtr_GRefCountImplCore)(struct GImage *); // edi
  int v6; // ecx

  GASPrototype<GASStringObject,GASEnvironment>::GASPrototype<GASStringObject,GASEnvironment>(
    (int)this,
    result,
    psc_4: a3,
    psc_8: (unsigned int)a4);
  *(_DWORD *)this = &GASPrototype<GASStringObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASStringProto::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 14) = &GASStringProto::`vftable';
  dtr_GRefCountImplCore = result->__vftable[86].dtr_GRefCountImplCore;
  ++*((_DWORD *)dtr_GRefCountImplCore + 2);
  v6 = *((_DWORD *)this + 13);
  if ( (*(_DWORD *)(v6 + 8))-- == 1 )
    GASStringNode::ReleaseNode(a1: v6);
  *((_DWORD *)this + 13) = dtr_GRefCountImplCore;
  HIBYTE(a4) = 1;
  GASPrototypeBase::InitFunctionMembers(
    this: (GASPrototypeBase *)this + 14,
    a2: (int)this,
    flags: (vc_attributes::PreRangeAttribute **)result,
    flags_4: (const struct GASNameFunction *)&GAS_StringFunctionTable,
    flags_8: (const struct GASPropFlags *)((char *)&a4 + 3));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010A170
// Name: public: static class GASFunctionRef GASStringCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__cdecl GASStringCtorFunction::Register(struct GASFunctionRef *a1, _KCRM_MARSHAL_HEADER *pgc)
{
  vc_attributes::PreRangeAttribute *v2; // esi
  unsigned int VersionMajor; // ecx
  int (__thiscall *v4)(unsigned int, int, _KCRM_MARSHAL_HEADER **); // eax
  GASCFunctionObject *v5; // eax
  GASCFunctionObject *v6; // edi
  void *v7; // ecx
  GASCFunctionObject *v8; // eax
  const char *MaxVal; // ecx
  int (__thiscall *v11)(const char *, int, _KCRM_MARSHAL_HEADER **); // eax
  GASStringProto *v12; // ebx
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GASStringProto *v14; // eax
  _DWORD *v15; // eax
  int v16; // ebx
  GASValue *v17; // eax
  GASValue v19[4]; // [esp+Ch] [ebp-1Ch] BYREF
  CTSQueue<CFunctor *,0,1>::Node_t v20; // [esp+1Ch] [ebp-Ch] BYREF
  _DWORD *v21; // [esp+24h] [ebp-4h]
  struct GASFunctionRef *v22; // [esp+30h] [ebp+8h]

  v2 = (vc_attributes::PreRangeAttribute *)pgc;
  VersionMajor = pgc[41].VersionMajor;
  v20.pNext = (CTSQueue<CFunctor *,0,1>::Node_t *)pgc;
  LOBYTE(v20.elem) = 8;
  v4 = *(int (__thiscall **)(unsigned int, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)VersionMajor + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v5 = (GASCFunctionObject *)v4(a1: VersionMajor, a2: 56, a3: &pgc);
  v6 = v5;
  if ( v5 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v5,
      func: (_REASON_CONTEXT *)&v20,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASStringCtorFunction::GlobalCtor);
    v6->dwSize = (unsigned int)&GASStringCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v6->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    GASNameFunction::AddConstMembers(
      pobj: v7,
      psc: (int)&v6->cLineHeight,
      psca: &v20,
      a4: (struct GASObject **)GASStringCtorFunction::StaticFunctionTable,
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
  v11 = *(int (__thiscall **)(const char *, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)MaxVal + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v12 = (GASStringProto *)v11(a1: MaxVal, a2: 88, a3: &pgc);
  if ( v12 != nullptr )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v2,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    v14 = GASStringProto::GASStringProto(this: v12, result: (GImage *)&v20, a3: Prototype, a4: a1);
    v22 = (struct GASFunctionRef *)v14;
  }
  else
  {
    v22 = nullptr;
    v14 = nullptr;
  }
  if ( v14 != nullptr )
    *((_DWORD *)v14 + 2) = (*((_DWORD *)v14 + 2) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)a1, a3: 3, a4: (int)v14);
  v15 = v2[56].MaxVal + 16;
  HIBYTE(pgc) = 0;
  v16 = *v15;
  v21 = v15;
  v17 = GASValue::GASValue(this: v19, a2: (int)a1, a3: a1);
  (*(void (__thiscall **)(_DWORD *, CTSQueue<CFunctor *,0,1>::Node_t *, const char **, GASValue *, char *))(v16 + 40))(
    a1: v21,
    a2: &v20,
    a3: &v2[1].MaxVal,
    a4: v17,
    a5: (char *)&pgc + 3);
  GASValue::~GASValue(this: v19, a2: (int)a1);
  if ( v22 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v22, a2: (int)a1);
  return a1;
}
