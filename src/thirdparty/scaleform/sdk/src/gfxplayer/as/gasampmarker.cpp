// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasampmarker.cpp
// Functions: 4
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasampmarker.h"

//------------------------------------------------------------------------------
// Address: 0x101233D0
// Name: private: static void GASAmpMarkerCtorFunction::AddMarker(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASAmpMarkerCtorFunction::AddMarker(const struct GASFnCall *fn)
{
  const struct GASFnCall *v1; // esi
  GASValue *v2; // edi
  tagRID_DEVICE_INFO_KEYBOARD *v3; // edi
  unsigned __int8 *v4; // eax
  GString v5; // edi
  struct GFxMovieRoot *MovieRoot; // eax
  const struct GASFnCall *v7; // eax

  v1 = fn;
  v2 = *((GASValue **)fn + 1);
  GASValue::DropRefs(this: v2, a2: (int)v2);
  *(_BYTE *)v2 = 1;
  v3 = *((tagRID_DEVICE_INFO_KEYBOARD **)v1 + 6);
  if ( v3 != nullptr && *((_DWORD *)v1 + 7) != 0 )
  {
    v4 = (unsigned __int8 *)GASFnCall::Arg(this: (GASFnCall *)v1, a2: 0);
    GASValue::ToStringImpl(this: v4, a2: (int *)&fn, a3: v3, precision: -1, debug: false);
    v5.pData = *(GString::DataDesc **)fn;
    MovieRoot = GASEnvironment::GetMovieRoot(this: *((GASEnvironment **)v1 + 6));
    GFxAmpViewStats::AddMarker(this: *((GFxAmpViewStats **)MovieRoot + 2577), a2: v5);
    v7 = fn;
    if ( (*((_DWORD *)fn + 2))-- == 1 )
      GASStringNode::ReleaseNode(a1: (int)v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123440
// Name: public: virtual bool GASAmpMarkerCtorFunction::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __userpurge GASAmpMarkerCtorFunction::GetMember@<al>(
        D3DXQUATERNION *this@<ecx>,
        int a2@<edi>,
        D3DXQUATERNION *result,
        _IMAGE_SYMBOL_EX *penv,
        struct GASValue *a5)
{
  tagWNDCLASSW *v5; // eax
  GASValue v7[4]; // [esp+4h] [ebp-10h] BYREF

  if ( strcmp(*(const char **)penv->N.Name.Short, "addMarker") != 0 )
    return (unsigned __int8)GASObject::GetMember(this, (ID3DXFont *)result, penv, val: (int *)a5);
  v5 = (tagWNDCLASSW *)GASValue::GASValue(
                         this: v7,
                         func: (int)&result[7].z,
                         a3: (void (__cdecl *)(const struct GASFnCall *))GASAmpMarkerCtorFunction::AddMarker);
  GASValue::operator=(this: (int)a5, v: v5);
  GASValue::~GASValue(this: v7, a2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101234D0
// Name: public: virtual bool GASAmpMarkerCtorFunction::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASAmpMarkerCtorFunction::SetMember(
        CTSQueue<CFunctor *,0,1> *this,
        struct GASEnvironment *a2,
        _IMAGE_SYMBOL_EX *name,
        const struct GASValue *val,
        const struct GASPropFlags *flags)
{
  struct GFxMovieRoot *MovieRoot; // edi
  const struct GASValue *v7; // eax

  MovieRoot = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)a2);
  if ( strcmp(*(const char **)name->N.Name.Short, "addMarker") == 0 )
  {
    GASValue::ToStringImpl(
      this: (unsigned __int8 *)val,
      a2: (int *)&val,
      a3: (tagRID_DEVICE_INFO_KEYBOARD *)a2,
      precision: -1,
      debug: false);
    GFxAmpViewStats::AddMarker(this: *((GFxAmpViewStats **)MovieRoot + 2577), a2: *(GString *)val);
    v7 = val;
    if ( (*((_DWORD *)val + 2))-- == 1 )
      GASStringNode::ReleaseNode(a1: (int)v7);
  }
  else
  {
    GASObject::SetMember(
      this,
      (GASEnvironment *)a2,
      name,
      pval: (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)val,
      pmember: (char *)flags);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101235F0
// Name: public: static class GASFunctionRef GASAmpMarkerCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
GArrayData<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy> *__cdecl GASAmpMarkerCtorFunction::Register(
        int result,
        _KCRM_MARSHAL_HEADER *pgc)
{
  vc_attributes::PreRangeAttribute *v2; // edi
  unsigned int VersionMajor; // ecx
  int (__thiscall *v4)(unsigned int, int, _KCRM_MARSHAL_HEADER **); // eax
  GASCFunctionObject *v5; // eax
  GASCFunctionObject *v6; // ebx
  void *v7; // ecx
  GString *v8; // eax
  GArrayData<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy> *v9; // ebx
  const char *MaxVal; // ecx
  int (__thiscall *v11)(const char *, int, int *); // eax
  int v12; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GASValue *v14; // eax
  int p_MinVal; // edi
  float v17; // [esp+0h] [ebp-2Ch]
  GASValue v18[4]; // [esp+Ch] [ebp-20h] BYREF
  _KCRM_MARSHAL_HEADER *psc; // [esp+1Ch] [ebp-10h] BYREF
  char v20; // [esp+20h] [ebp-Ch]
  void (__thiscall **v21)(_DWORD *, _KCRM_MARSHAL_HEADER **, int, GASValue *, char *); // [esp+24h] [ebp-8h]
  _DWORD *v22; // [esp+28h] [ebp-4h]

  v2 = (vc_attributes::PreRangeAttribute *)pgc;
  VersionMajor = pgc[41].VersionMajor;
  psc = pgc;
  v20 = 8;
  v4 = *(int (__thiscall **)(unsigned int, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)VersionMajor + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v5 = (GASCFunctionObject *)v4(a1: VersionMajor, a2: 56, a3: &pgc);
  v6 = v5;
  if ( v5 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v5,
      func: (_REASON_CONTEXT *)&psc,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASMouseCtorFunction::GlobalCtor);
    v6->dwSize = (unsigned int)&GASSelectionCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v6->cLineHeight = (unsigned int)&GASAmpMarkerCtorFunction::`vftable'{for `GASObjectInterface'};
    GASNameFunction::AddConstMembers(
      pobj: v7,
      psc: (int)&v6->cLineHeight,
      psca: (CTSQueue<CFunctor *,0,1>::Node_t *)&psc,
      a4: (struct GASObject **)GASAmpMarkerCtorFunction::StaticFunctionTable,
      a5: 7);
    v8 = (GString *)v6;
  }
  else
  {
    v8 = nullptr;
  }
  v9 = (GArrayData<GString,GAllocatorLH<GString,2>,GArrayDefaultPolicy> *)result;
  *(_DWORD *)result = v8;
  LOBYTE(v9->Policy.Capacity) = 0;
  v9->Size = 0;
  MaxVal = v2[54].MaxVal;
  v11 = *(int (__thiscall **)(const char *, int, int *))(*(_DWORD *)MaxVal + 40);
  result = 323;
  v12 = v11(a1: MaxVal, a2: 84, a3: &result);
  if ( v12 != 0 )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v2,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASIme,GASEnvironment>::GASPrototype<GASIme,GASEnvironment>(
      this: (D3DXCOLOR *)v12,
      (struct GASStringContext *)&psc,
      pprototype: Prototype,
      constructor: (unsigned int)v9,
      psc_12: v17);
    *(_DWORD *)v12 = &GASObjectProto::`vftable'{for `GASRefCountBase<GASObject>'};
    *(_DWORD *)(v12 + 16) = &GASPrototype<GASMouse,GASEnvironment>::`vftable'{for `GASObjectInterface'};
    *(_DWORD *)(v12 + 52) = &GASPrototype<GASObject,GASEnvironment>::`vftable';
  }
  else
  {
    v12 = 0;
  }
  if ( v12 != 0 )
    *(_DWORD *)(v12 + 8) = (*(_DWORD *)(v12 + 8) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)v2, a3: 155, a4: v12);
  v22 = v2[56].MaxVal + 16;
  HIBYTE(pgc) = 0;
  v21 = (void (__thiscall **)(_DWORD *, _KCRM_MARSHAL_HEADER **, int, GASValue *, char *))(*v22 + 40);
  v14 = GASValue::GASValue(this: v18, a2: (int)v2, a3: (const struct GASFunctionRef *)v9);
  p_MinVal = (int)&v2[52].MinVal;
  (*v21)(a1: v22, a2: &psc, a3: p_MinVal, a4: v14, a5: (char *)&pgc + 3);
  GASValue::~GASValue(this: v18, a2: p_MinVal);
  if ( v12 != 0 )
    GRefCountBaseGC<323>::Release(a1: v12, a2: p_MinVal);
  return v9;
}
