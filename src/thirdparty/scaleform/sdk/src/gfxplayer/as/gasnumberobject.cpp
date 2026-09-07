// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasnumberobject.cpp
// Functions: 11
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasnumberobject.h"

//------------------------------------------------------------------------------
// Address: 0x1010B5F0
// Name: public: virtual char const __near * GASNumberObject::GetTextValue(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASNumberObject::GetTextValue(GPtr<GFxURLBuilder> *this, const GPtr<GFxURLBuilder> *penv)
{
  unsigned __int8 *v3; // eax
  char v4[64]; // [esp+18h] [ebp-44h] BYREF

  v3 = (unsigned __int8 *)GASNumberUtil::ToString(
                            value: *((double *)this + 5),
                            destStr: v4,
                            destStrSize: 0x40u,
                            ival: 10);
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(this + 12),
    a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1010B640
// Name: public: virtual void GASNumberObject::SetValue(class GASEnvironment __near *,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASNumberObject::SetValue(
        GPtr<GFxURLBuilder> *this@<ecx>,
        int a2@<edi>,
        long double a3@<st0>,
        _SERVICE_STATUS *penv,
        tagWNDCLASSW *v)
{
  *((double *)this + 7) = GASValue::ToNumber(this: (GASValue *)v, a2, a3, result: penv);
}

//------------------------------------------------------------------------------
// Address: 0x1010B660
// Name: public: virtual class GASValue GASNumberObject::GetValue(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASNumberObject::GetValue(GPtr<GFxURLBuilder> *this, int a2)
{
  *(double *)(a2 + 4) = *((double *)this + 7);
  *(_BYTE *)a2 = 3;
}

//------------------------------------------------------------------------------
// Address: 0x1010B680
// Name: GAS_NumberValueOf
// Source: json
//------------------------------------------------------------------------------
void __usercall GAS_NumberValueOf(int a1@<edi>, long double a2@<st0>, _CONNECTDLGSTRUCTW fn)
{
  int v3; // eax
  int v4; // ecx
  GASValue *v5; // eax
  int v6; // esi
  _SERVICE_STATUS *v7; // [esp-4h] [ebp-20h]
  GASValue v8[4]; // [esp+4h] [ebp-18h] BYREF
  double v9; // [esp+14h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: fn.cbStructure, type: 9u) )
  {
    v3 = *(_DWORD *)(fn.cbStructure + 8);
    if ( v3 != 0 )
      v4 = v3 - 16;
    else
      v4 = 0;
    v7 = *(_SERVICE_STATUS **)(fn.cbStructure + 24);
    v5 = (GASValue *)(*(int (__thiscall **)(int, GASValue *))(*(_DWORD *)v4 + 16))(a1: v4, a2: v8);
    v9 = GASValue::ToNumber(this: v5, a2: a1, a3: a2, result: v7);
    v6 = *(_DWORD *)(fn.cbStructure + 4);
    if ( *(_BYTE *)v6 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v6, a2: a1);
    *(double *)(v6 + 4) = v9;
    *(_BYTE *)v6 = 3;
    GASValue::~GASValue(this: v8, a2: a1);
  }
  else
  {
    GASFnCall::ThisPtrError(this: (GASFnCall *)fn.cbStructure, a2: "Number", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010B700
// Name: public: static void GASNumberCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASNumberCtorFunction::GlobalCtor(int a1@<edi>, long double a2@<st0>, GASFnCall *result)
{
  unsigned int v3; // eax
  int v4; // edi
  char v5; // bl
  tagWNDCLASSW *v6; // eax
  tagWNDCLASSW *v7; // eax
  double v8; // st7
  GASValue *v9; // eax
  D3D11_USAGE v10; // esi
  double v11; // st7
  _SERVICE_STATUS *v12; // [esp-4h] [ebp-38h]
  GASValue v13[4]; // [esp+4h] [ebp-30h] BYREF
  GASValue v14[4]; // [esp+14h] [ebp-20h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *retVal; // [esp+24h] [ebp-10h] BYREF
  double v16; // [esp+2Ch] [ebp-8h]

  HIDWORD(v16) = 0;
  if ( result[2] != nullptr
    && (*(int (__thiscall **)(GASFnCall))(result[2]->cbSize + 8))(a1: result[2]) == 9
    && (*(unsigned __int8 (__thiscall **)(GASFnCall))(result[2]->cbSize + 64))(a1: result[2]) == 0 )
  {
    v3 = (unsigned int)result[2];
    if ( v3 != 0 )
      v4 = v3 - 16;
    else
      v4 = 0;
    if ( (int)result[7] <= 0 )
    {
      v5 = 2;
      LOBYTE(v14[0]) = 0;
      v7 = (tagWNDCLASSW *)v14;
    }
    else
    {
      v5 = 1;
      v6 = (tagWNDCLASSW *)GASFnCall::Arg(this: result, a2: 0);
      v7 = (tagWNDCLASSW *)GASValue::GASValue(this: v13, v: v6);
    }
    GASValue::GASValue(this: &retVal, v: v7);
    if ( (v5 & 2) != 0 )
    {
      v5 &= ~2u;
      GASValue::~GASValue(this: v14, a2: v4);
    }
    if ( (v5 & 1) != 0 )
      GASValue::~GASValue(this: v13, a2: v4);
    (*(void (__thiscall **)(int, GASFnCall, CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **))(*(_DWORD *)v4 + 12))(
      a1: v4,
      a2: result[6],
      a3: &retVal);
    GASValue::operator=(this: (int)result[1], v: (tagWNDCLASSW *)&retVal);
    GASValue::~GASValue(this: &retVal, a2: v4);
  }
  else
  {
    if ( result[7] != nullptr )
    {
      v12 = (_SERVICE_STATUS *)result[6];
      v9 = (GASValue *)GASFnCall::Arg(this: result, a2: 0);
      v8 = GASValue::ToNumber(this: v9, a2: a1, a3: a2, result: v12);
    }
    else
    {
      v8 = 0.0;
    }
    v10 = (D3D11_USAGE)result[1];
    v16 = v8;
    if ( *(_BYTE *)v10 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v10, a2: a1);
    v11 = v16;
    *(_BYTE *)v10 = 3;
    *(double *)(v10 + 4) = v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010B810
// Name: public: virtual enum GASObjectInterface::ObjectType GASNumberObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASNumberObject::GetObjectType(GPtr<GFxURLBuilder> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1010B830
// Name: GAS_NumberToString
// Source: json
//------------------------------------------------------------------------------
void __usercall GAS_NumberToString(long double a1@<st0>, _CONNECTDLGSTRUCTW fn)
{
  int v2; // eax
  int v3; // esi
  int v4; // eax
  GASValue *v5; // eax
  unsigned __int8 *v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // edi
  bool v10; // zf
  _SERVICE_STATUS *v11; // [esp+10h] [ebp-50h]
  char v12[64]; // [esp+1Ch] [ebp-44h] BYREF

  if ( GASFnCall::CheckThisPtr(this: fn.cbStructure, type: 9u) )
  {
    v2 = *(_DWORD *)(fn.cbStructure + 8);
    if ( v2 != 0 )
      v3 = v2 - 16;
    else
      v3 = 0;
    v4 = 10;
    if ( *(int *)(fn.cbStructure + 28) > 0 )
    {
      v11 = *(_SERVICE_STATUS **)(fn.cbStructure + 24);
      v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn.cbStructure, a2: 0);
      v4 = (int)GASValue::ToNumber(this: v5, a2: fn.cbStructure, a3: a1, result: v11);
    }
    v6 = (unsigned __int8 *)GASNumberUtil::ToString(
                              value: *(double *)(v3 + 56),
                              destStr: v12,
                              destStrSize: 0x40u,
                              ival: v4);
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v3 + 64),
      a2: v6);
    GASStringManager::CreateStringNode(
      this: *(GASStringManager **)(*(_DWORD *)(*(_DWORD *)(fn.cbStructure + 24) + 120) + 636),
      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*(_DWORD *)(v3 + 64) & 0xFFFFFFFC) + 8));
    v8 = v7;
    ++*(_DWORD *)(v7 + 8);
    v9 = *(_DWORD *)(fn.cbStructure + 4);
    if ( *(_BYTE *)v9 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v9, a2: v9);
    *(_BYTE *)v9 = 5;
    *(_DWORD *)(v9 + 4) = v8;
    v10 = ++*(_DWORD *)(v8 + 8) == 1;
    --*(_DWORD *)(v8 + 8);
    if ( v10 )
      GASStringNode::ReleaseNode(a1: v8);
  }
  else
  {
    GASFnCall::ThisPtrError(this: (GASFnCall *)fn.cbStructure, a2: "Number", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010B920
// Name: public: virtual class GASObject __near * GASNumberCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
struct GASObject *__thiscall GASNumberCtorFunction::CreateNewObject(GASNumberCtorFunction *this, int a2)
{
  struct GASEnvironment *v2; // edi
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // edx
  vc_attributes::PreRangeAttribute **v5; // ebx
  GASObject *v6; // eax
  GASObject *v7; // esi
  vc_attributes::InvalidCheckAttribute *Prototype; // eax

  v2 = (struct GASEnvironment *)a2;
  v3 = *(_DWORD *)(*(_DWORD *)(a2 + 120) + 656);
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  v5 = (vc_attributes::PreRangeAttribute **)(a2 + 120);
  a2 = 323;
  v6 = (GASObject *)v4(a1: v3, a2: 72, a3: &a2);
  v7 = v6;
  if ( v6 == nullptr )
    return nullptr;
  GASObject::GASObject(this: v6, a2: v2);
  *(double *)&v7[7] = 0.0;
  v7->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASNumberObject::`vftable'{for `GASRefCountBase<GASObject>'};
  v7[2].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASNumberObject::`vftable'{for `GASObjectInterface'};
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)&v7[8]);
  Prototype = GASGlobalContext::GetPrototype(this: *v5, result: (vc_attributes::InvalidCheckAttribute *)4);
  ((void (__thiscall *)(GASObject *, vc_attributes::PreRangeAttribute **, vc_attributes::InvalidCheckAttribute *))v7[2].pNode[6].elem)(
    a1: &v7[2],
    a2: v5,
    a3: Prototype);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1010BA60
// Name: protected: virtual void GASNumberObject::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASNumberObject::Finalize_GC(_DWORD *this, const GPtr<GFxURLBuilder> *result)
{
  volatile LONG *v2; // esi

  v2 = (volatile LONG *)(*(this + 16) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v2 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  JUMPOUT(0x100914D0);
}

//------------------------------------------------------------------------------
// Address: 0x1010BAE0
// Name: public: GASNumberCtorFunction::GASNumberCtorFunction(class GASStringContext __near *)
// Source: json
//------------------------------------------------------------------------------
GASCFunctionObject *__userpurge GASNumberCtorFunction::GASNumberCtorFunction@<eax>(
        GASCFunctionObject *a1@<ecx>,
        char *a2@<edi>,
        _REASON_CONTEXT *result)
{
  unsigned int *p_cLineHeight; // ebx
  int v5; // eax
  char **v6; // esi
  double (__stdcall *v7)(char *); // ecx
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v8; // edx
  unsigned int Version; // ecx
  const char *v10; // eax
  int v11; // edi
  int v12; // eax
  GASValue v16; // [esp+8h] [ebp-20h] BYREF
  double v17; // [esp+Ch] [ebp-1Ch]
  GASCFunctionObject *v18; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]
  struct GASStringNode *ConstStringNode; // [esp+20h] [ebp-8h] BYREF
  char v21; // [esp+27h] [ebp-1h] BYREF

  v18 = a1;
  GASCFunctionObject::GASCFunctionObject(
    this: a1,
    func: result,
    a3: (void (__cdecl *)(const struct GASFnCall *))GASNumberCtorFunction::GlobalCtor);
  p_cLineHeight = &a1->cLineHeight;
  v5 = 0;
  a1->dwSize = (unsigned int)&GASNumberCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
  a1->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
  i = 0;
  if ( "MAX_VALUE" == nullptr )
    return a1;
  v6 = &GASNumberConstTable;
  do
  {
    v7 = *(double (__stdcall **)(char *))((char *)&off_102A4670 + v5);
    v21 = 7;
    v17 = v7(a1: a2);
    v8 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)*v6;
    Version = result->Version;
    v10 = *v6;
    LOBYTE(v16) = 3;
    v11 = (int)(v10 + 1);
    ConstStringNode = GASStringManager::CreateConstStringNode(
                        this: *(GASStringManager **)(Version + 636),
                        result: v8,
                        a3: strlen(v10),
                        a4: 0);
    ++*((_DWORD *)ConstStringNode + 2);
    a2 = &v21;
    (*(void (__thiscall **)(unsigned int *, _REASON_CONTEXT *, struct GASStringNode **, GASValue *))(*p_cLineHeight + 40))(
      a1: p_cLineHeight,
      a2: result,
      a3: &ConstStringNode,
      a4: &v16);
    v12 = (int)ConstStringNode;
    if ( (*((_DWORD *)ConstStringNode + 2))-- == 1 )
      GASStringNode::ReleaseNode(a1: v12);
    GASValue::~GASValue(this: &v16, a2: v11);
    ++i;
    v5 = 8 * i;
    v6 = &(&GASNumberConstTable)[2 * i];
  }
  while ( *v6 != nullptr );
  return v18;
}

//------------------------------------------------------------------------------
// Address: 0x1010BDA0
// Name: public: static class GASFunctionRef GASNumberCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__cdecl GASNumberCtorFunction::Register(struct GASFunctionRef *a1, int a2)
{
  int v2; // edi
  const char *v3; // ecx
  int (__thiscall *v4)(const char *, int, int *); // eax
  GASCFunctionObject *v5; // eax
  GASCFunctionObject *v6; // eax
  struct GASFunctionRef *v7; // ebx
  int v8; // ecx
  int (__thiscall *v9)(int, int, struct GASFunctionRef **); // edx
  GASPrototypeBase *v10; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GASValue *v12; // eax
  int v13; // edi
  GASValue v15[4]; // [esp+Ch] [ebp-20h] BYREF
  vc_attributes::PreRangeAttribute *v16[2]; // [esp+1Ch] [ebp-10h] BYREF
  void (__thiscall **result_8)(_DWORD *, vc_attributes::PreRangeAttribute **, int, GASValue *, char *); // [esp+24h] [ebp-8h]
  _DWORD *v18; // [esp+28h] [ebp-4h]

  v2 = a2;
  v3 = *(const char **)(a2 + 656);
  v16[0] = (vc_attributes::PreRangeAttribute *)a2;
  LOBYTE(v16[1]) = 8;
  v4 = *(int (__thiscall **)(const char *, int, int *))(*(_DWORD *)v3 + 40);
  a2 = 323;
  v5 = (GASCFunctionObject *)v4(a1: v3, a2: 56, a3: &a2);
  if ( v5 != nullptr )
    v6 = GASNumberCtorFunction::GASNumberCtorFunction(a1: v5, a2: (char *)v2, result: (_REASON_CONTEXT *)v16);
  else
    v6 = nullptr;
  v7 = a1;
  *(_DWORD *)a1 = v6;
  *((_BYTE *)v7 + 8) = 0;
  *((_DWORD *)v7 + 1) = 0;
  v8 = *(_DWORD *)(v2 + 656);
  v9 = *(int (__thiscall **)(int, int, struct GASFunctionRef **))(*(_DWORD *)v8 + 40);
  a1 = (struct GASFunctionRef *)323;
  v10 = (GASPrototypeBase *)v9(a1: v8, a2: 104, a3: &a1);
  if ( v10 != nullptr )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: (vc_attributes::PreRangeAttribute *)v2,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASNumberObject,GASEnvironment>::GASPrototype<GASNumberObject,GASEnvironment>(
      this: (int)v10,
      result: (GFxFileOpenerBase *)v16,
      psc_4: Prototype,
      psc_8: (unsigned int)v7);
    v10->__vftable = (IUnknown_vtbl *)&GASNumberProto::`vftable'{for `GASRefCountBase<GASObject>'};
    v10[4].__vftable = (IUnknown_vtbl *)&GASPrototype<GASNumberObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
    v10[18].__vftable = (IUnknown_vtbl *)&GASPrototype<GASNumberObject,GASEnvironment>::`vftable';
    HIBYTE(a2) = 1;
    GASPrototypeBase::InitFunctionMembers(
      this: v10 + 18,
      a2: (int)v10,
      flags: v16,
      flags_4: (const struct GASNameFunction *)&NumberFunctionTable,
      flags_8: (const struct GASPropFlags *)((char *)&a2 + 3));
  }
  else
  {
    v10 = nullptr;
  }
  if ( v10 != nullptr )
    v10[2].__vftable = (IUnknown_vtbl *)(((int)&v10[2].QueryInterface + 1) & 0x8FFFFFFF);
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: v2, a3: 4, a4: (int)v10);
  v18 = (_DWORD *)(*(_DWORD *)(v2 + 680) + 16);
  HIBYTE(a2) = 0;
  result_8 = (void (__thiscall **)(_DWORD *, vc_attributes::PreRangeAttribute **, int, GASValue *, char *))(*v18 + 40);
  v12 = GASValue::GASValue(this: v15, a2: v2, a3: v7);
  v13 = v2 + 24;
  (*result_8)(a1: v18, a2: v16, a3: v13, a4: v12, a5: (char *)&a2 + 3);
  GASValue::~GASValue(this: v15, a2: v13);
  if ( v10 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v10, a2: v13);
  return v7;
}
