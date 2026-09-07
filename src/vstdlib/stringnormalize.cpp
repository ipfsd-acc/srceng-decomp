// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vstdlib/stringnormalize.cpp
// Functions: 19
// ============================================================

#include "vstdlib\stringnormalize.h"

//------------------------------------------------------------------------------
// Address: 0x3F60AF20
// Name: public: class CStringNormalization __near & CStringNormalization::operator=(class CStringNormalization const __near &)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CStringNormalization::operator=(void *this, int a2)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F60B1A0
// Name: public: static int CStringNormalization::Fold(unsigned short const __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
static int __cdecl CStringNormalization::Fold(LPCWCH lpSrcStr, LPWSTR lpDestStr, int cchDest)
{
  return FoldStringW(dwMapFlags: 0x20u, lpSrcStr, cchSrc: -1, lpDestStr, cchDest);
}

//------------------------------------------------------------------------------
// Address: 0x3F60B230
// Name: public: static void CStringNormalization::ValidateStatics(class CValidator __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CStringNormalization::ValidateStatics(struct CValidator *a1, const char *a2)
{
  const char *v2; // eax
  int v3; // [esp-10h] [ebp-18h]
  int v4; // [esp-Ch] [ebp-14h]
  int v5; // [esp-8h] [ebp-10h]
  int v6; // [esp-4h] [ebp-Ch]

  CValidator::Push(this: a1, a2: "CStringNormalization statics", a3: nullptr, a4: a2);
  v2 = (const char *)sub_3F62928F(a1: &CUtlMap<unsigned short,unsigned short const *,int,bool (__cdecl *)(unsigned short const &,unsigned short const &)> `RTTI Type Descriptor');
  CValidator::Push(this: a1, a2: v2, a3: &unk_3F6643AC, a4: "g_mapPairs");
  ((void (__stdcall *)(int, int, int, int))loc_3F60BB30)(a1: v3, a2: v4, a3: v5, a4: v6);
  CValidator::Pop(this: a1);
  CValidator::Pop(this: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F60B280
// Name: public: static bool CStringNormalization::Test_BValidateStructures(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CStringNormalization::Test_BValidateStructures()
{
  if ( dword_3F6643CC > 0 )
    JUMPOUT(0x3F60B2AE);
  JUMPOUT(0x3F60B588);
}

//------------------------------------------------------------------------------
// Address: 0x3F613560
// Name: public: static void CStringNormalization::ValidateStatics(class CValidator __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CStringNormalization::ValidateStatics(
        char a1@<al>,
        int a2@<ebx>,
        _DWORD *a3@<edi>,
        _DWORD *a4@<esi>,
        CValidator *validator,
        char *pchName,
        int a7,
        char Buffer,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  *a3 = *a4;
  qmemcpy(a3 + 1, a4 + 1, a1 & 3);
  a13 = 19;
  sprintf(&Buffer, Format: " %02X", *(unsigned __int8 *)(a2 + 97));
  strlen(&Buffer);
  JUMPOUT(0x3F6135AB);
}

//------------------------------------------------------------------------------
// Address: 0x3F6139C0
// Name: public: CUtlMap<unsigned short,unsigned short const __near *,int>::CUtlMap<unsigned short,unsigned short const __near *,int>(int,int,bool (*)(unsigned short const __near &,unsigned short const __near &))
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CUtlMap<unsigned short,unsigned short const *,int>::CUtlMap<unsigned short,unsigned short const *,int>(
        CUtlMap<unsigned short,unsigned short const *,int> *this@<ecx>,
        char a2@<zf>,
        int a3@<eax>,
        int a4@<ebx>,
        void (__thiscall *a5)(CValidator *, int)@<ebp>,
        CValidator *a6@<edi>,
        int a7@<esi>,
        int growSize,
        int initSize,
        bool (__cdecl *lessfunc)(const wchar_t *, const wchar_t *))
{
  *(_DWORD *)(a4 - 1065015226) = __ROR4__(*(_DWORD *)(a4 - 1065015226), (char)this);
  if ( !a2 )
    a5(a1: a6, a2: a3);
  CValidator::Pop(this: a6);
  if ( *(_DWORD *)(a7 + 8) != 0 )
    JUMPOUT(0x3F6139A0);
  CValidator::Pop(this: a6);
}

//------------------------------------------------------------------------------
// Address: 0x3F613A00
// Name: public: unsigned short const __near * __near & CUtlMap<unsigned short,unsigned short const __near *,int>::operator[](int)
// Source: json
//------------------------------------------------------------------------------
const wchar_t **__cdecl CUtlMap<unsigned short,unsigned short const *,int>::operator[](
        CUtlMap<unsigned short,unsigned short const *,int> *this)
{
  int v1; // ecx

  return *(const wchar_t ***)(v1 + 16);
}

//------------------------------------------------------------------------------
// Address: 0x3F613A10
// Name: public: unsigned short __near & CUtlMap<unsigned short,unsigned short const __near *,int>::Key(int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F613A20
// Name: public: bool CUtlMap<unsigned short,unsigned short const __near *,int>::IsValidIndex(int)const
// Source: json
//------------------------------------------------------------------------------
void __stdcall CUtlMap<unsigned short,unsigned short const *,int>::IsValidIndex(
        CUtlMap<unsigned short,unsigned short const *,int> *this)
{
  JUMPOUT(0x3F613A3F);
}

//------------------------------------------------------------------------------
// Address: 0x3F613A40
// Name: public: int CUtlMap<unsigned short,unsigned short const __near *,int>::Insert(unsigned short const __near &,unsigned short const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CUtlMap<unsigned short,unsigned short const *,int>::Insert(
        int a1@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        CUtlMap<unsigned short,unsigned short const *,int> *this)
{
  *(_DWORD *)(a1 + 8) = a2;
  if ( a3 == 0 )
  {
    dword_3F6642A0 = a1;
    JUMPOUT(0x3F613A5E);
  }
  JUMPOUT(0x3F613A30);
}

//------------------------------------------------------------------------------
// Address: 0x3F613A60
// Name: public: int CUtlMap<unsigned short,unsigned short const __near *,int>::Find(unsigned short const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __stdcall CUtlMap<unsigned short,unsigned short const *,int>::Find(
        CUtlMap<unsigned short,unsigned short const *,int> *this)
{
  if ( dword_3F6642A0 != 0 )
    JUMPOUT(0x3F613A7B);
  JUMPOUT(0x3F613B30);
}

//------------------------------------------------------------------------------
// Address: 0x3F613A80
// Name: public: CUtlMap<unsigned short,unsigned short const __near *,int>::CKeyLess::CKeyLess(bool (*)(unsigned short const __near &,unsigned short const __near &))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMap<unsigned short,unsigned short const *,int>::CKeyLess::CKeyLess(
        CUtlMap<unsigned short,unsigned short const *,int>::CKeyLess *this,
        bool (__cdecl *lessFunc)(const wchar_t *, const wchar_t *))
{
  JUMPOUT(0x3F613A85);
}

//------------------------------------------------------------------------------
// Address: 0x3F613B10
// Name: public: int CUtlMap<unsigned short,unsigned short const __near *,int>::MaxElement(void)const
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CUtlMap<unsigned short,unsigned short const *,int>::MaxElement(
        CUtlMap<unsigned short,unsigned short const *,int> *this)
{
  JUMPOUT(0x3F613B22);
}

//------------------------------------------------------------------------------
// Address: 0x3F613DD0
// Name: public: void CUtlMap<unsigned short,unsigned short const __near *,int>::Validate(class CValidator __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlMap<unsigned short,unsigned short const *,int>::Validate(
        CValidator *validator@<eax>,
        _DWORD *a2@<esi>,
        CUtlMap<unsigned short,unsigned short const *,int> *this,
        char *pchName)
{
  ((void (*)(void))validator)();
  a2[10] = 0;
  *a2 = &ConCommandBase::`vftable';
  if ( ((unsigned __int8)pchName & 1) != 0 )
    (*(void (__thiscall **)(_DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam);
}

//------------------------------------------------------------------------------
// Address: 0x3F613E00
// Name: void SetDefLessFunc<class CUtlMap<unsigned short,unsigned short const __near *,int>>(class CUtlMap<unsigned short,unsigned short const __near *,int> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SetDefLessFunc<CUtlMap<unsigned short,unsigned short const *,int>>(
        int a1@<esi>,
        CUtlMap<unsigned short,unsigned short const *,int> *RBTree)
{
  *(_BYTE *)(a1 + 12) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 24) = 0;
  *(_DWORD *)(a1 + 28) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  JUMPOUT(0x3F613E37);
}

//------------------------------------------------------------------------------
// Address: 0x3F613E80
// Name: public: bool CUtlMap<unsigned short,unsigned short const __near *,int>::CKeyLess::operator!(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMap<unsigned short,unsigned short const *,int>::CKeyLess::operator!(
        CUtlMap<unsigned short,unsigned short const *,int>::CKeyLess *this)
{
  JUMPOUT(0x3F613E8D);
}

//------------------------------------------------------------------------------
// Address: 0x3F613E90
// Name: public: bool CUtlMap<unsigned short,unsigned short const __near *,int>::CKeyLess::operator()(struct CUtlMap<unsigned short,unsigned short const __near *,int>::Node_t const __near &,struct CUtlMap<unsigned short,unsigned short const __near *,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlMap<unsigned short,unsigned short const *,int>::CKeyLess::operator()(
        _DWORD *a1@<esi>,
        CUtlMap<unsigned short,unsigned short const *,int>::CKeyLess *this)
{
  *a1 = &ConVar::`vftable';
  ((void (__thiscall *)(_DWORD *))loc_3F614450)(a1);
  JUMPOUT(0x3F613E9D);
}

//------------------------------------------------------------------------------
// Address: 0x3F613EA0
// Name: public: static bool CDefOps<unsigned short>::LessFunc(unsigned short const __near &,unsigned short const __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F613EC0
// Name: public: struct CUtlMap<unsigned short,unsigned short const __near *,int>::Node_t const __near & CUtlRBTree<struct CUtlMap<unsigned short,unsigned short const __near *,int>::Node_t,int,class CUtlMap<unsigned short,unsigned short const __near *,int>::CKeyLess>::Element(int)const
// Source: json
//------------------------------------------------------------------------------
const CUtlMap<unsigned short,unsigned short const *,int>::Node_t *__userpurge CUtlRBTree<CUtlMap<unsigned short,unsigned short const *,int>::Node_t,int,CUtlMap<unsigned short,unsigned short const *,int>::CKeyLess>::Element@<eax>(
        int i@<esi>,
        char a2@<cf>,
        int a3@<eax>,
        int a4@<edx>,
        int a5@<ecx>,
        CUtlRBTree<CUtlMap<unsigned short,unsigned short const *,int>::Node_t,int,CUtlMap<unsigned short,unsigned short const *,int>::CKeyLess> *this,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  LOBYTE(a3) = a3 - (a2 + 36);
  *(_BYTE *)(i + 12) = a3;
  *(_DWORD *)(i + 16) = a3;
  *(_DWORD *)(i + 20) = a3;
  *(_DWORD *)(i + 24) = a3;
  *(_DWORD *)(i + 28) = a3;
  *(_DWORD *)(i + 8) = a3;
  *(_DWORD *)i = &ConVar::`vftable';
  ((void (__thiscall *)(int, int, int, int, int, int, int))loc_3F614450)(
    a1: i,
    a2: a10,
    a3: a11,
    a4: a5,
    a5: a13,
    a6: a4,
    a7: a3);
  return (const CUtlMap<unsigned short,unsigned short const *,int>::Node_t *)i;
}
