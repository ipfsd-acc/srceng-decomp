// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasbooleanobject.cpp
// Functions: 8
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasbooleanobject.h"

//------------------------------------------------------------------------------
// Address: 0x1010BED0
// Name: public: virtual char const __near * GASBooleanObject::GetTextValue(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
GFxURLBuilder *__thiscall GASBooleanObject::GetTextValue(GPtr<GFxURLBuilder> *this, int a2)
{
  GFxURLBuilder *result; // eax

  result = (GFxURLBuilder *)"true";
  if ( *((_BYTE *)this + 36) == 0 )
    return (GFxURLBuilder *)"false";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010BEF0
// Name: public: virtual void GASBooleanObject::SetValue(class GASEnvironment __near *,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASBooleanObject::SetValue(
        GASBooleanObject *this@<ecx>,
        long double a2@<st0>,
        tagPOLYTEXTW *result,
        const struct GASValue *a4)
{
  *((_BYTE *)this + 52) = GASValue::ToBool(a1: (char *)a4, a2, result);
}

//------------------------------------------------------------------------------
// Address: 0x1010BF10
// Name: public: virtual class GASValue GASBooleanObject::GetValue(void)const
// Source: json
//------------------------------------------------------------------------------
_BYTE *__thiscall GASBooleanObject::GetValue(_BYTE *this, _BYTE *a2)
{
  char v3; // cl

  v3 = *(this + 52);
  *a2 = 2;
  a2[4] = v3;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x1010BF30
// Name: GAS_BooleanToString
// Source: json
//------------------------------------------------------------------------------
void __cdecl GAS_BooleanToString(_CONNECTDLGSTRUCTW fn)
{
  int v1; // eax
  int v2; // ecx
  tagRID_DEVICE_INFO_KEYBOARD *v3; // edi
  unsigned __int8 *v4; // eax
  int v5; // esi
  int v6; // eax
  GASValue v8[4]; // [esp+4h] [ebp-14h] BYREF
  int v9; // [esp+14h] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: fn.cbStructure, type: 0xAu) )
  {
    v1 = *(_DWORD *)(fn.cbStructure + 8);
    if ( v1 != 0 )
      v2 = v1 - 16;
    else
      v2 = 0;
    v3 = *(tagRID_DEVICE_INFO_KEYBOARD **)(fn.cbStructure + 24);
    v4 = (unsigned __int8 *)(*(int (__thiscall **)(int, GASValue *))(*(_DWORD *)v2 + 16))(a1: v2, a2: v8);
    GASValue::ToStringImpl(this: v4, a2: &v9, a3: v3, precision: -1, debug: false);
    v5 = *(_DWORD *)(fn.cbStructure + 4);
    if ( *(_BYTE *)v5 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v5, a2: (int)v3);
    *(_BYTE *)v5 = 5;
    *(_DWORD *)(v5 + 4) = v9;
    ++*(_DWORD *)(v9 + 8);
    v6 = v9;
    if ( (*(_DWORD *)(v9 + 8))-- == 1 )
      GASStringNode::ReleaseNode(a1: v6);
    GASValue::~GASValue(this: v8, a2: (int)v3);
  }
  else
  {
    GASFnCall::ThisPtrError(this: (GASFnCall *)fn.cbStructure, a2: "Boolean", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010BFD0
// Name: GAS_BooleanValueOf
// Source: json
//------------------------------------------------------------------------------
void __usercall GAS_BooleanValueOf(int a1@<edi>, long double a2@<st0>, _CONNECTDLGSTRUCTW fn)
{
  int v3; // eax
  int v4; // ecx
  char *v5; // eax
  char v6; // al
  int v7; // esi
  char v8; // bl
  tagPOLYTEXTW *v9; // [esp-8h] [ebp-1Ch]
  GASValue v10[4]; // [esp+4h] [ebp-10h] BYREF

  if ( GASFnCall::CheckThisPtr(this: fn.cbStructure, type: 0xAu) )
  {
    v3 = *(_DWORD *)(fn.cbStructure + 8);
    if ( v3 != 0 )
      v4 = v3 - 16;
    else
      v4 = 0;
    v9 = *(tagPOLYTEXTW **)(fn.cbStructure + 24);
    v5 = (char *)(*(int (__thiscall **)(int, GASValue *))(*(_DWORD *)v4 + 16))(a1: v4, a2: v10);
    v6 = GASValue::ToBool(a1: v5, a2, result: v9);
    v7 = *(_DWORD *)(fn.cbStructure + 4);
    v8 = v6;
    GASValue::DropRefs(this: (GASValue *)v7, a2: a1);
    *(_BYTE *)v7 = 2;
    *(_BYTE *)(v7 + 4) = v8;
    GASValue::~GASValue(this: v10, a2: a1);
  }
  else
  {
    GASFnCall::ThisPtrError(this: (GASFnCall *)fn.cbStructure, a2: "Boolean", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010C050
// Name: public: static void GASBooleanCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASBooleanCtorFunction::GlobalCtor(long double a1@<st0>, GASFnCall *result)
{
  int p_SetPrivateData; // edi
  ID3D11UnorderedAccessView_vtbl *v3; // eax
  char v4; // bl
  tagWNDCLASSW *v5; // eax
  tagWNDCLASSW *v6; // eax
  ID3D11UnorderedAccessView_vtbl *v7; // esi
  char *v8; // eax
  char v9; // al
  char v10; // bl
  tagPOLYTEXTW *v11; // [esp-4h] [ebp-44h]
  GASValue v12[4]; // [esp+Ch] [ebp-34h] BYREF
  GASValue v13[4]; // [esp+1Ch] [ebp-24h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *retVal; // [esp+2Ch] [ebp-14h] BYREF
  int v15; // [esp+3Ch] [ebp-4h]

  p_SetPrivateData = 0;
  v15 = 0;
  if ( result[2] != nullptr
    && (*(int (__thiscall **)(GASFnCall))(result[2]->cbSize + 8))(a1: result[2]) == 10
    && (*(unsigned __int8 (__thiscall **)(GASFnCall))(result[2]->cbSize + 64))(a1: result[2]) == 0 )
  {
    v3 = (ID3D11UnorderedAccessView_vtbl *)result[2];
    if ( v3 != nullptr )
      p_SetPrivateData = (int)&v3[-1].SetPrivateData;
    if ( (int)result[7] <= 0 )
    {
      v4 = 2;
      LOBYTE(v13[0]) = 0;
      v6 = (tagWNDCLASSW *)v13;
    }
    else
    {
      v4 = 1;
      v5 = (tagWNDCLASSW *)GASFnCall::Arg(this: result, a2: 0);
      v6 = (tagWNDCLASSW *)GASValue::GASValue(this: v12, v: v5);
    }
    GASValue::GASValue(this: &retVal, v: v6);
    if ( (v4 & 2) != 0 )
    {
      v4 &= ~2u;
      GASValue::~GASValue(this: v13, a2: p_SetPrivateData);
    }
    if ( (v4 & 1) != 0 )
      GASValue::~GASValue(this: v12, a2: p_SetPrivateData);
    (*(void (__thiscall **)(int, GASFnCall, CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **))(*(_DWORD *)p_SetPrivateData + 12))(
      a1: p_SetPrivateData,
      a2: result[6],
      a3: &retVal);
    GASValue::operator=(this: (int)result[1], v: (tagWNDCLASSW *)&retVal);
    GASValue::~GASValue(this: &retVal, a2: p_SetPrivateData);
  }
  else
  {
    if ( result[7] != nullptr )
    {
      v11 = (tagPOLYTEXTW *)result[6];
      v8 = (char *)GASFnCall::Arg(this: result, a2: 0);
      v9 = GASValue::ToBool(a1: v8, a2: a1, result: v11);
      v7 = (ID3D11UnorderedAccessView_vtbl *)result[1];
      v10 = v9;
      GASValue::DropRefs(this: (GASValue *)v7, a2: 0);
      LOBYTE(v7->AddRef) = v10;
    }
    else
    {
      v7 = (ID3D11UnorderedAccessView_vtbl *)result[1];
      GASValue::DropRefs(this: (GASValue *)v7, a2: 0);
      LOBYTE(v7->AddRef) = 0;
    }
    LOBYTE(v7->QueryInterface) = 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010C160
// Name: public: virtual class GASObject __near * GASBooleanCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
struct GASObject *__thiscall GASBooleanCtorFunction::CreateNewObject(GASBooleanCtorFunction *this, int a2)
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
  v6 = (GASObject *)v4(a1: v3, a2: 56, a3: &a2);
  v7 = v6;
  if ( v6 == nullptr )
    return nullptr;
  GASObject::GASObject(this: v6, a2: v2);
  v7->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASBooleanObject::`vftable'{for `GASRefCountBase<GASObject>'};
  v7[2].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASBooleanObject::`vftable'{for `GASObjectInterface'};
  LOBYTE(v7[6].sequence) = 0;
  Prototype = GASGlobalContext::GetPrototype(this: *v5, result: (vc_attributes::InvalidCheckAttribute *)5);
  ((void (__thiscall *)(GASObject *, vc_attributes::PreRangeAttribute **, vc_attributes::InvalidCheckAttribute *))v7[2].pNode[6].elem)(
    a1: &v7[2],
    a2: v5,
    a3: Prototype);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1010C300
// Name: public: static class GASFunctionRef GASBooleanCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__cdecl GASBooleanCtorFunction::Register(struct GASFunctionRef *a1, _KCRM_MARSHAL_HEADER *pgc)
{
  vc_attributes::PreRangeAttribute *v2; // edi
  unsigned int VersionMajor; // ecx
  int (__thiscall *v4)(unsigned int, int, _KCRM_MARSHAL_HEADER **); // eax
  GASCFunctionObject *v5; // eax
  GASCFunctionObject *v6; // ebx
  GASCFunctionObject *v7; // eax
  struct GASFunctionRef *v8; // ebx
  const char *MaxVal; // ecx
  int (__thiscall *v10)(const char *, int, struct GASFunctionRef **); // edx
  GASPrototypeBase *v11; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GASValue *v13; // eax
  int p_MinVal; // edi
  GASValue v16[4]; // [esp+Ch] [ebp-20h] BYREF
  _KCRM_MARSHAL_HEADER *v17; // [esp+1Ch] [ebp-10h] BYREF
  char v18; // [esp+20h] [ebp-Ch]
  void (__thiscall **v19)(_DWORD *, _KCRM_MARSHAL_HEADER **, int, GASValue *, char *); // [esp+24h] [ebp-8h]
  _DWORD *v20; // [esp+28h] [ebp-4h]

  v2 = (vc_attributes::PreRangeAttribute *)pgc;
  VersionMajor = pgc[41].VersionMajor;
  v17 = pgc;
  v18 = 8;
  v4 = *(int (__thiscall **)(unsigned int, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)VersionMajor + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v5 = (GASCFunctionObject *)v4(a1: VersionMajor, a2: 56, a3: &pgc);
  v6 = v5;
  if ( v5 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v5,
      func: (_REASON_CONTEXT *)&v17,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASBooleanCtorFunction::GlobalCtor);
    v6->dwSize = (unsigned int)&GASBooleanCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v6->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    v7 = v6;
  }
  else
  {
    v7 = nullptr;
  }
  v8 = a1;
  *(_DWORD *)a1 = v7;
  *((_BYTE *)v8 + 8) = 0;
  *((_DWORD *)v8 + 1) = 0;
  MaxVal = v2[54].MaxVal;
  v10 = *(int (__thiscall **)(const char *, int, struct GASFunctionRef **))(*(_DWORD *)MaxVal + 40);
  a1 = (struct GASFunctionRef *)323;
  v11 = (GASPrototypeBase *)v10(a1: MaxVal, a2: 88, a3: &a1);
  if ( v11 != nullptr )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v2,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASBooleanObject,GASEnvironment>::GASPrototype<GASBooleanObject,GASEnvironment>(
      this: (int)v11,
      psc: (struct GASStringContext *)&v17,
      psc_4: Prototype,
      psc_8: (unsigned int)v8);
    v11->__vftable = (IUnknown_vtbl *)&GASPrototype<GASBooleanObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
    v11[4].__vftable = (IUnknown_vtbl *)&GASBooleanProto::`vftable'{for `GASObjectInterface'};
    v11[14].__vftable = (IUnknown_vtbl *)&GASBooleanProto::`vftable';
    HIBYTE(pgc) = 1;
    GASPrototypeBase::InitFunctionMembers(
      this: v11 + 14,
      a2: (int)v11,
      flags: (vc_attributes::PreRangeAttribute **)&v17,
      flags_4: (const struct GASNameFunction *)&GAS_BooleanFunctionTable,
      flags_8: (const struct GASPropFlags *)((char *)&pgc + 3));
  }
  else
  {
    v11 = nullptr;
  }
  if ( v11 != nullptr )
    v11[2].__vftable = (IUnknown_vtbl *)(((int)&v11[2].QueryInterface + 1) & 0x8FFFFFFF);
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)v2, a3: 5, a4: (int)v11);
  v20 = v2[56].MaxVal + 16;
  HIBYTE(pgc) = 0;
  v19 = (void (__thiscall **)(_DWORD *, _KCRM_MARSHAL_HEADER **, int, GASValue *, char *))(*v20 + 40);
  v13 = GASValue::GASValue(this: v16, a2: (int)v2, a3: v8);
  p_MinVal = (int)&v2[2].MinVal;
  (*v19)(a1: v20, a2: &v17, a3: p_MinVal, a4: v13, a5: (char *)&pgc + 3);
  GASValue::~GASValue(this: v16, a2: p_MinVal);
  if ( v11 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v11, a2: p_MinVal);
  return v8;
}
