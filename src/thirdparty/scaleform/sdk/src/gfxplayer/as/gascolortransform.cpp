// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gascolortransform.cpp
// Functions: 11
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gascolortransform.h"

//------------------------------------------------------------------------------
// Address: 0x1012B060
// Name: public: virtual bool GASColorTransformObject::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASColorTransformObject::GetMember(
        D3DXQUATERNION *this,
        D3DXQUATERNION *result,
        const char ***penv,
        struct GASValue *a4)
{
  double v5; // st7
  double v7; // st7
  GASValue v8; // [esp+8h] [ebp-40h] BYREF
  GASValue v9; // [esp+18h] [ebp-30h] BYREF
  GASValue v10; // [esp+28h] [ebp-20h] BYREF
  GASValue v11; // [esp+38h] [ebp-10h] BYREF
  double v12; // [esp+3Ch] [ebp-Ch]

  if ( strcmp(**penv, "redMultiplier") == 0 )
  {
    v5 = *((float *)this + 9);
LABEL_3:
    v12 = v5;
    LOBYTE(v11) = 3;
    GASValue::operator=(this: (int)a4, v: (tagWNDCLASSW *)&v11);
    GASValue::~GASValue(this: &v11, a2: (int)this);
    return 1;
  }
  if ( strcmp(**penv, "greenMultiplier") == 0 )
  {
    v5 = *((float *)this + 11);
    goto LABEL_3;
  }
  if ( strcmp(**penv, "blueMultiplier") == 0 )
  {
    v5 = *((float *)this + 13);
    goto LABEL_3;
  }
  if ( GASString::operator==(this: penv, a2: "alphaMultiplier") )
  {
    v5 = *((float *)this + 15);
    goto LABEL_3;
  }
  if ( GASString::operator==(this: penv, a2: "redOffset") )
  {
    v5 = *((float *)this + 10);
    goto LABEL_3;
  }
  if ( GASString::operator==(this: penv, a2: "greenOffset") )
  {
    v5 = *((float *)this + 12);
    goto LABEL_3;
  }
  if ( GASString::operator==(this: penv, a2: (const char *)&stru_102A7128.m_pElements) )
  {
    v5 = *((float *)this + 14);
    goto LABEL_3;
  }
  if ( GASString::operator==(this: penv, a2: (const char *)&stru_102A7128.m_Memory.m_nAllocationCount) )
  {
    v5 = *((float *)this + 16);
    goto LABEL_3;
  }
  if ( !GASString::operator==(this: penv, a2: (const char *)&stru_102A7128) )
    return (unsigned __int8)GASObject::GetMember(this, (ID3DXFont *)result, (_IMAGE_SYMBOL_EX *)penv, val: (int *)a4);
  v7 = *((float *)this + 10);
  LOBYTE(v8) = 0;
  LOBYTE(v9) = 0;
  LOBYTE(v10) = 0;
  LOBYTE(v11) = 3;
  v12 = (double)((unsigned __int8)(int)*((float *)this + 14)
               | (((unsigned __int8)(int)*((float *)this + 12) | ((unsigned __int8)(int)v7 << 8)) << 8));
  GASValue::operator=(this: (int)a4, v: (tagWNDCLASSW *)&v11);
  GASValue::~GASValue(this: &v11, a2: (int)this);
  GASValue::~GASValue(this: &v10, a2: (int)this);
  GASValue::~GASValue(this: &v9, a2: (int)this);
  GASValue::~GASValue(this: &v8, a2: (int)this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1012B2C0
// Name: public: virtual bool GASColorTransformObject::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASColorTransformObject::SetMember(
        GArrayBase<GArrayData<GFxMovieRoot *,GAllocatorLH<GFxMovieRoot *,2>,GArrayDefaultPolicy> > *this@<ecx>,
        long double a2@<st0>,
        _SERVICE_STATUS *penv,
        GFxMovieRoot **name,
        tagWNDCLASSW *val,
        char *flags)
{
  unsigned int v7; // esi
  int v8; // edi
  int v9; // ebx
  double v10; // st7
  GViewport *v11; // ecx
  char v12; // al
  double v13; // st7

  if ( strcmp(*(const char **)*name, "redMultiplier") == 0 )
  {
    *((float *)this + 9) = GASValue::ToNumber(this: (GASValue *)val, a2: (int)this, a3: a2, result: penv);
  }
  else if ( strcmp(*(const char **)*name, "greenMultiplier") == 0 )
  {
    *((float *)this + 11) = GASValue::ToNumber(this: (GASValue *)val, a2: (int)this, a3: a2, result: penv);
  }
  else if ( strcmp(*(const char **)*name, "blueMultiplier") == 0 )
  {
    *((float *)this + 13) = GASValue::ToNumber(this: (GASValue *)val, a2: (int)this, a3: a2, result: penv);
  }
  else if ( GASString::operator==(this: (const char ***)name, a2: "alphaMultiplier") )
  {
    *((float *)this + 15) = GASValue::ToNumber(this: (GASValue *)val, a2: (int)this, a3: a2, result: penv);
  }
  else if ( GASString::operator==(this: (const char ***)name, a2: "redOffset") )
  {
    *((float *)this + 10) = GASValue::ToNumber(this: (GASValue *)val, a2: (int)this, a3: a2, result: penv);
  }
  else if ( GASString::operator==(this: (const char ***)name, a2: "greenOffset") )
  {
    *((float *)this + 12) = GASValue::ToNumber(this: (GASValue *)val, a2: (int)this, a3: a2, result: penv);
  }
  else if ( GASString::operator==(this: (const char ***)name, a2: (const char *)&stru_102A7128.m_pElements) )
  {
    *((float *)this + 14) = GASValue::ToNumber(this: (GASValue *)val, a2: (int)this, a3: a2, result: penv);
  }
  else if ( GASString::operator==(
              this: (const char ***)name,
              a2: (const char *)&stru_102A7128.m_Memory.m_nAllocationCount) )
  {
    *((float *)this + 16) = GASValue::ToNumber(this: (GASValue *)val, a2: (int)this, a3: a2, result: penv);
  }
  else if ( GASString::operator==(this: (const char ***)name, a2: (const char *)&stru_102A7128) )
  {
    *((float *)this + 9) = 0.0;
    *((float *)this + 11) = 0.0;
    *((float *)this + 13) = 0.0;
    v7 = 0;
    v8 = 0;
    v9 = 0;
    v10 = GASValue::ToNumber(this: (GASValue *)val, a2: 0, a3: 0.0, result: penv);
    GASNumberUtil::IsNaN(v: v11, u: SLODWORD(v10), u_4: HIDWORD(*(unsigned __int64 *)&v10));
    if ( v12 == 0 )
    {
      v13 = GASValue::ToNumber(this: (GASValue *)val, a2: 0, a3: v10, result: penv);
      v7 = (unsigned __int8)((unsigned int)(__int64)v13 >> 16);
      v8 = (unsigned __int8)((unsigned __int16)(__int64)v13 >> 8);
      v9 = (unsigned __int8)(__int64)v13;
    }
    *((float *)this + 10) = (float)v7;
    *((float *)this + 12) = (float)v8;
    *((float *)this + 14) = (float)v9;
  }
  else
  {
    GASObject::SetMember(
      (CTSQueue<CFunctor *,0,1> *)this,
      a2: (GASEnvironment *)penv,
      (_IMAGE_SYMBOL_EX *)name,
      pval: (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)val,
      pmember: flags);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012B580
// Name: public: virtual enum GASObjectInterface::ObjectType GASColorTransformObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int GASColorTransformObject::GetObjectType()
{
  return 18;
}

//------------------------------------------------------------------------------
// Address: 0x1012B700
// Name: public: static void GASColorTransformProto::ToString(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASColorTransformProto::ToString(GASFnCall *a1)
{
  GASFnCall v1; // edi
  float *p_cxItem; // edi
  tagRID_DEVICE_INFO_KEYBOARD *v3; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v4; // edx
  tagRID_DEVICE_INFO_KEYBOARD *v5; // ecx
  tagRID_DEVICE_INFO_KEYBOARD *v6; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v7; // edx
  tagRID_DEVICE_INFO_KEYBOARD *v8; // ecx
  double v9; // st7
  tagRID_DEVICE_INFO_KEYBOARD *v10; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v11; // edx
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *m_pfnProxied; // eax
  struct GASStringNode *StringNode; // edi
  GASFnCall v14; // esi
  bool v15; // zf
  int *v16; // esi
  int i; // edi
  int v18; // ecx
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> v19; // [esp+4h] [ebp-4Ch] BYREF
  GASValue v20; // [esp+1Ch] [ebp-34h] BYREF
  double v21; // [esp+20h] [ebp-30h]
  char **v22; // [esp+2Ch] [ebp-24h] BYREF
  char **v23; // [esp+30h] [ebp-20h] BYREF
  char **v24; // [esp+34h] [ebp-1Ch] BYREF
  char **v25; // [esp+38h] [ebp-18h] BYREF
  char **v26; // [esp+3Ch] [ebp-14h] BYREF
  char **v27; // [esp+40h] [ebp-10h] BYREF
  char **v28; // [esp+44h] [ebp-Ch] BYREF
  char **v29; // [esp+48h] [ebp-8h] BYREF
  int v30; // [esp+4Ch] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x12u) )
  {
    v1 = a1[2];
    if ( v1 != nullptr )
      p_cxItem = (float *)&v1[-1].cxItem;
    else
      p_cxItem = nullptr;
    v3 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
    v21 = p_cxItem[13];
    LOBYTE(v20) = 3;
    GASValue::ToStringImpl(this: (unsigned __int8 *)&v20, a2: (int *)&v22, a3: v3, precision: 6, debug: false);
    GASValue::~GASValue(this: &v20, a2: (int)p_cxItem);
    v4 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
    v21 = p_cxItem[15];
    LOBYTE(v20) = 3;
    GASValue::ToStringImpl(this: (unsigned __int8 *)&v20, a2: (int *)&v23, a3: v4, precision: 6, debug: false);
    GASValue::~GASValue(this: &v20, a2: (int)p_cxItem);
    v5 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
    v21 = p_cxItem[17];
    LOBYTE(v20) = 3;
    GASValue::ToStringImpl(this: (unsigned __int8 *)&v20, a2: (int *)&v24, a3: v5, precision: 6, debug: false);
    GASValue::~GASValue(this: &v20, a2: (int)p_cxItem);
    v6 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
    v21 = p_cxItem[19];
    LOBYTE(v20) = 3;
    GASValue::ToStringImpl(this: (unsigned __int8 *)&v20, a2: (int *)&v25, a3: v6, precision: 6, debug: false);
    GASValue::~GASValue(this: &v20, a2: (int)p_cxItem);
    v7 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
    v21 = p_cxItem[14];
    LOBYTE(v20) = 3;
    GASValue::ToStringImpl(this: (unsigned __int8 *)&v20, a2: (int *)&v26, a3: v7, precision: 6, debug: false);
    GASValue::~GASValue(this: &v20, a2: (int)p_cxItem);
    v8 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
    v21 = p_cxItem[16];
    LOBYTE(v20) = 3;
    GASValue::ToStringImpl(this: (unsigned __int8 *)&v20, a2: (int *)&v27, a3: v8, precision: 6, debug: false);
    GASValue::~GASValue(this: &v20, a2: (int)p_cxItem);
    v9 = p_cxItem[18];
    LOBYTE(v20) = 3;
    v10 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
    v21 = v9;
    GASValue::ToStringImpl(this: (unsigned __int8 *)&v20, a2: (int *)&v28, a3: v10, precision: 6, debug: false);
    GASValue::~GASValue(this: &v20, a2: (int)p_cxItem);
    v11 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
    v21 = p_cxItem[20];
    LOBYTE(v20) = 3;
    GASValue::ToStringImpl(this: (unsigned __int8 *)&v20, a2: (int *)&v29, a3: v11, precision: 6, debug: false);
    GASValue::~GASValue(this: &v20, a2: (int)p_cxItem);
    GStringBuffer::GStringBuffer(
      this: &v19,
      result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)GMemory::pGlobalHeap);
    GStringBuffer::AppendString(this: &v19, putf8str: "(redMultiplier=", utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v19, putf8str: *v22, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v19, putf8str: ", greenMultiplier=", utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v19, putf8str: *v23, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v19, putf8str: ", blueMultiplier=", utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v19, putf8str: *v24, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v19, putf8str: ", alphaMultiplier=", utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v19, putf8str: *v25, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v19, putf8str: ", redOffset=", utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v19, putf8str: *v26, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v19, putf8str: ", greenOffset=", utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v19, putf8str: *v27, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v19, putf8str: ", blueOffset=", utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v19, putf8str: *v28, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v19, putf8str: ", alphaOffset=", utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v19, putf8str: *v29, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v19, putf8str: ")", utf8StrSz: -1);
    m_pfnProxied = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v19.m_pfnProxied;
    if ( LODWORD(v19.m_pfnProxied) == 0 )
      m_pfnProxied = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&pMem;
    StringNode = GASStringManager::CreateStringNode(
                   this: *(GASStringManager **)(a1[6][3].cbSize + 636),
                   result: m_pfnProxied,
                   length: DWORD1(v19.m_pfnProxied));
    ++*((_DWORD *)StringNode + 2);
    v14 = a1[1];
    if ( LOBYTE(v14->cbSize) >= 5u )
      GASValue::DropRefs(this: (GASValue *)v14, a2: (int)StringNode);
    LOBYTE(v14->cbSize) = 5;
    v14->cItems = (int)StringNode;
    v15 = ++*((_DWORD *)StringNode + 2) == 1;
    --*((_DWORD *)StringNode + 2);
    if ( v15 )
      GASStringNode::ReleaseNode(a1: (int)StringNode);
    GStringBuffer::~GStringBuffer(this: &v19);
    v16 = &v30;
    for ( i = 7; i >= 0; --i )
    {
      v18 = *--v16;
      v15 = (*(_DWORD *)(v18 + 8))-- == 1;
      if ( v15 )
        GASStringNode::ReleaseNode(a1: v18);
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: "ColorTransform", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012BA60
// Name: void GFxObject_GetColorTransformProperties(class GASEnvironment __near *,class GASObject __near *,class GASValue __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFxObject_GetColorTransformProperties(
        struct GASEnvironment *a1,
        struct GASObject *a2,
        struct GASValue *const a3)
{
  char *v3; // esi
  struct GASObject *v4; // edi
  struct GASStringNode *ConstStringNode; // eax
  struct GASValue *v6; // ebx
  struct GASEnvironment *v7; // eax
  bool v8; // zf
  struct GASEnvironment *v9; // eax
  struct GASEnvironment *v10; // eax
  struct GASEnvironment *v11; // eax
  struct GASEnvironment *v12; // eax
  struct GASEnvironment *v13; // eax
  struct GASEnvironment *v14; // eax
  struct GASEnvironment *v15; // eax

  v3 = (char *)a1 + 120;
  v4 = a2 + 2;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(*((_DWORD *)a1 + 30) + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"redMultiplier",
                      a3: 0xDu,
                      a4: 0);
  v6 = a3;
  a1 = ConstStringNode;
  ++*((_DWORD *)ConstStringNode + 2);
  ((void (__thiscall *)(struct GASObject *, char *, struct GASEnvironment **, struct GASValue *))v4->pNode[5].elem)(
    a1: v4,
    a2: v3,
    a3: &a1,
    a4: v6);
  v7 = a1;
  v8 = (*((_DWORD *)a1 + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v7);
  a1 = GASStringManager::CreateConstStringNode(
         this: *(GASStringManager **)(*(_DWORD *)v3 + 636),
         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"greenMultiplier",
         a3: 0xFu,
         a4: 0);
  ++*((_DWORD *)a1 + 2);
  ((void (__thiscall *)(struct GASObject *, char *, struct GASEnvironment **, int))v4->pNode[5].elem)(
    a1: v4,
    a2: v3,
    a3: &a1,
    a4: (int)v6 + 16);
  v9 = a1;
  v8 = (*((_DWORD *)a1 + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v9);
  a1 = GASStringManager::CreateConstStringNode(
         this: *(GASStringManager **)(*(_DWORD *)v3 + 636),
         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"blueMultiplier",
         a3: 0xEu,
         a4: 0);
  ++*((_DWORD *)a1 + 2);
  ((void (__thiscall *)(struct GASObject *, char *, struct GASEnvironment **, int))v4->pNode[5].elem)(
    a1: v4,
    a2: v3,
    a3: &a1,
    a4: (int)v6 + 32);
  v10 = a1;
  v8 = (*((_DWORD *)a1 + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v10);
  a1 = GASStringManager::CreateConstStringNode(
         this: *(GASStringManager **)(*(_DWORD *)v3 + 636),
         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"alphaMultiplier",
         a3: 0xFu,
         a4: 0);
  ++*((_DWORD *)a1 + 2);
  ((void (__thiscall *)(struct GASObject *, char *, struct GASEnvironment **, int))v4->pNode[5].elem)(
    a1: v4,
    a2: v3,
    a3: &a1,
    a4: (int)v6 + 48);
  v11 = a1;
  v8 = (*((_DWORD *)a1 + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v11);
  a1 = GASStringManager::CreateConstStringNode(
         this: *(GASStringManager **)(*(_DWORD *)v3 + 636),
         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"redOffset",
         a3: 9u,
         a4: 0);
  ++*((_DWORD *)a1 + 2);
  ((void (__thiscall *)(struct GASObject *, char *, struct GASEnvironment **, int))v4->pNode[5].elem)(
    a1: v4,
    a2: v3,
    a3: &a1,
    a4: (int)v6 + 64);
  v12 = a1;
  v8 = (*((_DWORD *)a1 + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v12);
  a1 = GASStringManager::CreateConstStringNode(
         this: *(GASStringManager **)(*(_DWORD *)v3 + 636),
         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"greenOffset",
         a3: 0xBu,
         a4: 0);
  ++*((_DWORD *)a1 + 2);
  ((void (__thiscall *)(struct GASObject *, char *, struct GASEnvironment **, int))v4->pNode[5].elem)(
    a1: v4,
    a2: v3,
    a3: &a1,
    a4: (int)v6 + 80);
  v13 = a1;
  v8 = (*((_DWORD *)a1 + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v13);
  a1 = GASStringManager::CreateConstStringNode(
         this: *(GASStringManager **)(*(_DWORD *)v3 + 636),
         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7128.m_pElements,
         a3: 0xAu,
         a4: 0);
  ++*((_DWORD *)a1 + 2);
  ((void (__thiscall *)(struct GASObject *, char *, struct GASEnvironment **, int))v4->pNode[5].elem)(
    a1: v4,
    a2: v3,
    a3: &a1,
    a4: (int)v6 + 96);
  v14 = a1;
  v8 = (*((_DWORD *)a1 + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v14);
  a1 = GASStringManager::CreateConstStringNode(
         this: *(GASStringManager **)(*(_DWORD *)v3 + 636),
         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7128.m_Memory.m_nAllocationCount,
         a3: 0xBu,
         a4: 0);
  ++*((_DWORD *)a1 + 2);
  ((void (__thiscall *)(struct GASObject *, char *, struct GASEnvironment **, int))v4->pNode[5].elem)(
    a1: v4,
    a2: v3,
    a3: &a1,
    a4: (int)v6 + 112);
  v15 = a1;
  v8 = (*((_DWORD *)a1 + 2))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v15);
}

//------------------------------------------------------------------------------
// Address: 0x1012BC70
// Name: public: static void GASColorTransformProto::Concat(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASColorTransformProto::Concat(int a1@<edi>, long double a2@<st0>, GASFnCall *a3)
{
  GASValue *v3; // eax
  struct GASObject *v4; // edi
  GASFnCall v5; // eax
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  GASValue *v13; // esi
  int i; // edi
  struct GASEnvironment *v15; // [esp-10h] [ebp-C0h]
  const struct GASEnvironment *v16; // [esp-8h] [ebp-B8h]
  int *p_cxItem; // [esp+8h] [ebp-A8h]
  struct GRenderer::Cxform v18; // [esp+Ch] [ebp-A4h] BYREF
  GASValue v19[4]; // [esp+2Ch] [ebp-84h] BYREF
  GASValue v20; // [esp+3Ch] [ebp-74h] BYREF
  GASValue v21; // [esp+4Ch] [ebp-64h] BYREF
  GASValue v22; // [esp+5Ch] [ebp-54h] BYREF
  GASValue v23; // [esp+6Ch] [ebp-44h] BYREF
  GASValue v24; // [esp+7Ch] [ebp-34h] BYREF
  GASValue v25; // [esp+8Ch] [ebp-24h] BYREF
  GASValue v26; // [esp+9Ch] [ebp-14h] BYREF
  int v27; // [esp+ACh] [ebp-4h] BYREF

  if ( (int)a3[7] > 0 )
  {
    v16 = (const struct GASEnvironment *)a3[6];
    v3 = (GASValue *)GASFnCall::Arg(this: a3, a2: 0);
    v4 = GASValue::ToObject(this: v3, a2: a1, a3: v16);
    if ( v4 != nullptr )
    {
      if ( GASFnCall::CheckThisPtr(this: a3, type: 0x12u) )
      {
        v5 = a3[2];
        if ( v5 != nullptr )
          p_cxItem = &v5[-1].cxItem;
        else
          p_cxItem = nullptr;
        if ( ((int (__thiscall *)(struct GASObject *))v4[2].pNode[1].pNext)(a1: &v4[2]) == 18 )
        {
          GRenderer::Cxform::Concatenate(
            this: (GRenderer::Cxform *)(p_cxItem + 13),
            a2: (const struct GRenderer::Cxform *)&v4[6].sequence);
        }
        else
        {
          v15 = (struct GASEnvironment *)a3[6];
          LOBYTE(v19[0]) = 0;
          LOBYTE(v20) = 0;
          LOBYTE(v21) = 0;
          LOBYTE(v22) = 0;
          LOBYTE(v23) = 0;
          LOBYTE(v24) = 0;
          LOBYTE(v25) = 0;
          LOBYTE(v26) = 0;
          GFxObject_GetColorTransformProperties(a1: v15, a2: v4, a3: (struct GASValue *const)v19);
          GRenderer::Cxform::Cxform(this: (float *)&v18);
          v6 = GASValue::ToNumber(this: v19, a2: (int)v4, a3: a2, result: (_SERVICE_STATUS *)a3[6]);
          v18.M_[0][0] = v6;
          v7 = GASValue::ToNumber(this: &v20, a2: (int)v4, a3: v6, result: (_SERVICE_STATUS *)a3[6]);
          v18.M_[1][0] = v7;
          v8 = GASValue::ToNumber(this: &v21, a2: (int)v4, a3: v7, result: (_SERVICE_STATUS *)a3[6]);
          v18.M_[2][0] = v8;
          v9 = GASValue::ToNumber(this: &v22, a2: (int)v4, a3: v8, result: (_SERVICE_STATUS *)a3[6]);
          v18.M_[3][0] = v9;
          v10 = GASValue::ToNumber(this: &v23, a2: (int)v4, a3: v9, result: (_SERVICE_STATUS *)a3[6]);
          v18.M_[0][1] = v10;
          v11 = GASValue::ToNumber(this: &v24, a2: (int)v4, a3: v10, result: (_SERVICE_STATUS *)a3[6]);
          v18.M_[1][1] = v11;
          v12 = GASValue::ToNumber(this: &v25, a2: (int)v4, a3: v11, result: (_SERVICE_STATUS *)a3[6]);
          v18.M_[2][1] = v12;
          v18.M_[3][1] = GASValue::ToNumber(this: &v26, a2: (int)v4, a3: v12, result: (_SERVICE_STATUS *)a3[6]);
          GRenderer::Cxform::Concatenate(this: (GRenderer::Cxform *)(p_cxItem + 13), a2: &v18);
          v13 = (GASValue *)&v27;
          for ( i = 7; i >= 0; --i )
          {
            v13 -= 4;
            GASValue::~GASValue(this: v13, a2: i);
          }
        }
      }
      else
      {
        GASFnCall::ThisPtrError(this: a3, a2: "ColorTransform", a3: nullptr, a4: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012C040
// Name: public: GASColorTransformObject::GASColorTransformObject(class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
GArrayBase<GArrayData<GFxMovieRoot *,GAllocatorLH<GFxMovieRoot *,2>,GArrayDefaultPolicy> > *__thiscall GASColorTransformObject::GASColorTransformObject(
        GArrayBase<GArrayData<GFxMovieRoot *,GAllocatorLH<GFxMovieRoot *,2>,GArrayDefaultPolicy> > *this,
        unsigned int penv)
{
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax

  GASObject::GASObject((GASObject *)this, a2: (struct GASEnvironment *)penv);
  this->Data.Data = (struct GFxMovieRoot **)&GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASColorTransformObject::`vftable'{for `GASObjectInterface'};
  GRenderer::Cxform::Cxform(this: (float *)this + 13);
  Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                    this: *(vc_attributes::PreRangeAttribute **)(penv + 120),
                                                    result: (vc_attributes::InvalidCheckAttribute *)0x10);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)((char *)this + 16),
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)(penv + 120),
    psc_4: Prototype);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1012C090
// Name: public: static void GASColorTransformCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASColorTransformCtorFunction::GlobalCtor(
        int a1@<edi>,
        long double a2@<st0>,
        const struct GASFnCall *fn)
{
  int v3; // eax
  int v4; // edi
  GASValue *v5; // eax
  double v6; // st7
  GASValue *v7; // eax
  double v8; // st7
  GASValue *v9; // eax
  double v10; // st7
  GASValue *v11; // eax
  double v12; // st7
  GASValue *v13; // eax
  double v14; // st7
  GASValue *v15; // eax
  double v16; // st7
  GASValue *v17; // eax
  double v18; // st7
  GASValue *v19; // eax
  _SERVICE_STATUS *v20; // [esp-8h] [ebp-Ch]
  _SERVICE_STATUS *v21; // [esp-8h] [ebp-Ch]
  _SERVICE_STATUS *v22; // [esp-8h] [ebp-Ch]
  _SERVICE_STATUS *v23; // [esp-8h] [ebp-Ch]
  _SERVICE_STATUS *v24; // [esp-8h] [ebp-Ch]
  _SERVICE_STATUS *v25; // [esp-8h] [ebp-Ch]
  _SERVICE_STATUS *v26; // [esp-8h] [ebp-Ch]
  _SERVICE_STATUS *v27; // [esp-8h] [ebp-Ch]

  if ( *((_DWORD *)fn + 2) != 0
    && (*(int (__thiscall **)(_DWORD))(**((_DWORD **)fn + 2) + 8))(a1: *((_DWORD *)fn + 2)) == 18 )
  {
    v3 = *((_DWORD *)fn + 2);
    if ( v3 != 0 )
    {
      v4 = v3 - 16;
      if ( v3 != 16 )
        *(_DWORD *)(v4 + 8) = (*(_DWORD *)(v4 + 8) + 1) & 0x8FFFFFFF;
    }
    else
    {
      v4 = 0;
    }
    GASValue::SetAsObject(this: *((GASValue **)fn + 1), a2: (struct GASObject *)v4);
    if ( *((int *)fn + 7) > 7 )
    {
      v20 = *((_SERVICE_STATUS **)fn + 6);
      v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
      v6 = GASValue::ToNumber(this: v5, a2: v4, a3: a2, result: v20);
      *(float *)(v4 + 52) = v6;
      v21 = *((_SERVICE_STATUS **)fn + 6);
      v7 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 1);
      v8 = GASValue::ToNumber(this: v7, a2: v4, a3: v6, result: v21);
      *(float *)(v4 + 60) = v8;
      v22 = *((_SERVICE_STATUS **)fn + 6);
      v9 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 2);
      v10 = GASValue::ToNumber(this: v9, a2: v4, a3: v8, result: v22);
      *(float *)(v4 + 68) = v10;
      v23 = *((_SERVICE_STATUS **)fn + 6);
      v11 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 3);
      v12 = GASValue::ToNumber(this: v11, a2: v4, a3: v10, result: v23);
      *(float *)(v4 + 76) = v12;
      v24 = *((_SERVICE_STATUS **)fn + 6);
      v13 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 4);
      v14 = GASValue::ToNumber(this: v13, a2: v4, a3: v12, result: v24);
      *(float *)(v4 + 56) = v14;
      v25 = *((_SERVICE_STATUS **)fn + 6);
      v15 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 5);
      v16 = GASValue::ToNumber(this: v15, a2: v4, a3: v14, result: v25);
      *(float *)(v4 + 64) = v16;
      v26 = *((_SERVICE_STATUS **)fn + 6);
      v17 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 6);
      v18 = GASValue::ToNumber(this: v17, a2: v4, a3: v16, result: v26);
      *(float *)(v4 + 72) = v18;
      v27 = *((_SERVICE_STATUS **)fn + 6);
      v19 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 7);
      *(float *)(v4 + 80) = GASValue::ToNumber(this: v19, a2: v4, a3: v18, result: v27);
    }
    if ( v4 != 0 )
      GRefCountBaseGC<323>::Release(a1: v4, a2: a1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012C1C0
// Name: public: virtual class GASObject __near * GASColorTransformCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
struct GASObject *__thiscall GASColorTransformCtorFunction::CreateNewObject(
        GASColorTransformCtorFunction *this,
        int a2)
{
  struct GASEnvironment *v2; // ebx
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // edx
  vc_attributes::PreRangeAttribute **v5; // edi
  GASObject *v6; // eax
  GASObject *v7; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax

  v2 = (struct GASEnvironment *)a2;
  v3 = *(_DWORD *)(*(_DWORD *)(a2 + 120) + 656);
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  v5 = (vc_attributes::PreRangeAttribute **)(a2 + 120);
  a2 = 323;
  v6 = (GASObject *)v4(a1: v3, a2: 84, a3: &a2);
  v7 = v6;
  if ( v6 == nullptr )
    return nullptr;
  GASObject::GASObject(this: v6, a2: v2);
  v7->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  v7[2].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASColorTransformObject::`vftable'{for `GASObjectInterface'};
  GRenderer::Cxform::Cxform(this: (float *)&v7[6].sequence);
  Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                    this: *v5,
                                                    result: (vc_attributes::InvalidCheckAttribute *)0x10);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)&v7[2],
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)v5,
    psc_4: Prototype);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1012C2C0
// Name: public: GASColorTransformProto::GASColorTransformProto(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
GASColorTransformProto *__thiscall GASColorTransformProto::GASColorTransformProto(
        GASColorTransformProto *this,
        struct GASStringContext *a2,
        struct GASObject *ConstStringNode,
        const struct GASFunctionRef *a4)
{
  GASObject *v5; // edi
  int v6; // eax
  struct GASObject *v7; // eax
  bool v8; // zf
  int v9; // ecx
  struct GASObject *v10; // eax
  int v11; // edx
  struct GASObject *v12; // eax
  int v13; // eax
  struct GASObject *v14; // eax
  int v15; // ecx
  struct GASObject *v16; // eax
  int v17; // edx
  struct GASObject *v18; // eax
  int v19; // eax
  struct GASObject *v20; // eax
  int v21; // ecx
  struct GASObject *v22; // eax
  int v23; // edx
  struct GASObject *v24; // eax
  int v26; // [esp+0h] [ebp-20h]
  GASValue v27; // [esp+Ch] [ebp-14h] BYREF
  int v28; // [esp+10h] [ebp-10h]
  GASColorTransformProto *v29; // [esp+1Ch] [ebp-4h]

  v29 = this;
  GASPrototype<GASColorTransformObject,GASEnvironment>::GASPrototype<GASColorTransformObject,GASEnvironment>(
    (int)this,
    psc: a2,
    psc_4: (CTSQueue<CFunctor *,0,1>::Node_t *)ConstStringNode,
    psc_8: (unsigned int)a4);
  v5 = (GASObject *)((char *)this + 16);
  *(_DWORD *)this = &GASColorTransformProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASPrototype<GASColorTransformObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 21) = &GASPrototype<GASColorTransformObject,GASEnvironment>::`vftable';
  HIBYTE(a4) = 6;
  GASPrototypeBase::InitFunctionMembers(
    this: (GASPrototypeBase *)this + 21,
    a2: (int)this,
    flags: (vc_attributes::PreRangeAttribute **)a2,
    flags_4: (const struct GASNameFunction *)&GASColorTransformProto::FunctionTable,
    flags_8: (const struct GASPropFlags *)((char *)&a4 + 3));
  v6 = *(_DWORD *)a2;
  HIBYTE(a4) = 2;
  LOBYTE(v27) = 4;
  v28 = 0;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v6 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"redMultiplier",
                                          a3: 0xDu,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: (GASObject *)this + 2,
    a2,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: &v27,
    a5: (const struct GASPropFlags *)((char *)&a4 + 3));
  v7 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v7);
  GASValue::~GASValue(this: &v27, a2: (int)v5);
  v9 = *(_DWORD *)a2;
  HIBYTE(a4) = 2;
  LOBYTE(v27) = 4;
  v28 = 0;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v9 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"greenMultiplier",
                                          a3: 0xFu,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: v5,
    a2,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: &v27,
    a5: (const struct GASPropFlags *)((char *)&a4 + 3));
  v10 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v10);
  GASValue::~GASValue(this: &v27, a2: (int)v5);
  v11 = *(_DWORD *)a2;
  HIBYTE(a4) = 2;
  LOBYTE(v27) = 4;
  v28 = 0;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v11 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"blueMultiplier",
                                          a3: 0xEu,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: v5,
    a2,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: &v27,
    a5: (const struct GASPropFlags *)((char *)&a4 + 3));
  v12 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v12);
  GASValue::~GASValue(this: &v27, a2: (int)v5);
  v13 = *(_DWORD *)a2;
  HIBYTE(a4) = 2;
  LOBYTE(v27) = 4;
  v28 = 0;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v13 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"alphaMultiplier",
                                          a3: 0xFu,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: v5,
    a2,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: &v27,
    a5: (const struct GASPropFlags *)((char *)&a4 + 3));
  v14 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v14);
  GASValue::~GASValue(this: &v27, a2: (int)v5);
  v15 = *(_DWORD *)a2;
  HIBYTE(a4) = 2;
  LOBYTE(v27) = 4;
  v28 = 0;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v15 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"redOffset",
                                          a3: 9u,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: v5,
    a2,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: &v27,
    a5: (const struct GASPropFlags *)((char *)&a4 + 3));
  v16 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v16);
  GASValue::~GASValue(this: &v27, a2: (int)v5);
  v17 = *(_DWORD *)a2;
  HIBYTE(a4) = 2;
  LOBYTE(v27) = 4;
  v28 = 0;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v17 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"greenOffset",
                                          a3: 0xBu,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: v5,
    a2,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: &v27,
    a5: (const struct GASPropFlags *)((char *)&a4 + 3));
  v18 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v18);
  GASValue::~GASValue(this: &v27, a2: (int)v5);
  v19 = *(_DWORD *)a2;
  HIBYTE(a4) = 2;
  LOBYTE(v27) = 4;
  v28 = 0;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v19 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7128.m_pElements,
                                          a3: 0xAu,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: v5,
    a2,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: &v27,
    a5: (const struct GASPropFlags *)((char *)&a4 + 3));
  v20 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v20);
  GASValue::~GASValue(this: &v27, a2: (int)v5);
  v21 = *(_DWORD *)a2;
  HIBYTE(a4) = 2;
  LOBYTE(v27) = 4;
  v28 = 0;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v21 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7128.m_Memory.m_nAllocationCount,
                                          a3: 0xBu,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: v5,
    a2,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: &v27,
    a5: (const struct GASPropFlags *)((char *)&a4 + 3));
  v22 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v22);
  GASValue::~GASValue(this: &v27, a2: (int)v5);
  v23 = *(_DWORD *)a2;
  HIBYTE(a4) = 2;
  LOBYTE(v27) = 4;
  v28 = 0;
  ConstStringNode = (struct GASObject *)GASStringManager::CreateConstStringNode(
                                          this: *(GASStringManager **)(v23 + 636),
                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7128,
                                          a3: 3u,
                                          a4: 0);
  ++ConstStringNode[1].pNode;
  GASObject::SetMemberRaw(
    this: v5,
    a2,
    a3: (_EXIT_THREAD_DEBUG_INFO *)&ConstStringNode,
    a4: &v27,
    a5: (const struct GASPropFlags *)((char *)&a4 + 3));
  v24 = ConstStringNode;
  v8 = ConstStringNode[1].pNode-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v24);
  GASValue::~GASValue(this: &v27, a2: v26);
  return v29;
}

//------------------------------------------------------------------------------
// Address: 0x1012C690
// Name: public: static class GASFunctionRef GASColorTransformCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__cdecl GASColorTransformCtorFunction::Register(
        struct GASFunctionRef *a1,
        _KCRM_MARSHAL_HEADER *pgc)
{
  vc_attributes::PreRangeAttribute *v2; // esi
  unsigned int VersionMajor; // ecx
  int (__thiscall *v4)(unsigned int, int, _KCRM_MARSHAL_HEADER **); // eax
  GASCFunctionObject *v5; // eax
  GASCFunctionObject *v6; // edi
  GASCFunctionObject *v7; // eax
  const char *MaxVal; // ecx
  int (__thiscall *v10)(const char *, int, _KCRM_MARSHAL_HEADER **); // edx
  GASColorTransformProto *v11; // ebx
  vc_attributes::InvalidCheckAttribute *Prototype; // eax
  GASColorTransformProto *v13; // ebx
  unsigned int Deref; // edx
  GASValue *v15; // eax
  GASValue v17[4]; // [esp+Ch] [ebp-18h] BYREF
  _KCRM_MARSHAL_HEADER *v18; // [esp+1Ch] [ebp-8h] BYREF
  char v19; // [esp+20h] [ebp-4h]
  struct GASFunctionRef *v20; // [esp+2Ch] [ebp+8h]

  v2 = (vc_attributes::PreRangeAttribute *)pgc;
  VersionMajor = pgc[41].VersionMajor;
  v18 = pgc;
  v19 = 8;
  v4 = *(int (__thiscall **)(unsigned int, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)VersionMajor + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v5 = (GASCFunctionObject *)v4(a1: VersionMajor, a2: 56, a3: &pgc);
  v6 = v5;
  if ( v5 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v5,
      func: (_REASON_CONTEXT *)&v18,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASColorTransformCtorFunction::GlobalCtor);
    v6->dwSize = (unsigned int)&GASColorTransformCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v6->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    v7 = v6;
  }
  else
  {
    v7 = nullptr;
  }
  *(_DWORD *)a1 = v7;
  *((_BYTE *)a1 + 8) = 0;
  *((_DWORD *)a1 + 1) = 0;
  MaxVal = v2[54].MaxVal;
  v10 = *(int (__thiscall **)(const char *, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)MaxVal + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v11 = (GASColorTransformProto *)v10(a1: MaxVal, a2: 116, a3: &pgc);
  if ( v11 != nullptr )
  {
    Prototype = GASGlobalContext::GetPrototype(this: v2, result: (vc_attributes::InvalidCheckAttribute *)1);
    v13 = GASColorTransformProto::GASColorTransformProto(
            this: v11,
            a2: (struct GASStringContext *)&v18,
            ConstStringNode: (struct GASObject *)Prototype,
            a4: a1);
  }
  else
  {
    v13 = nullptr;
  }
  if ( v13 != nullptr )
    *((_DWORD *)v13 + 2) = (*((_DWORD *)v13 + 2) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)a1, a3: 16, a4: (int)v13);
  Deref = v2[55].Deref;
  HIBYTE(pgc) = 0;
  v20 = *(struct GASFunctionRef **)(Deref + 16);
  v15 = GASValue::GASValue(this: v17, a2: (int)a1, a3: a1);
  (*((void (__thiscall **)(unsigned int, _KCRM_MARSHAL_HEADER **, vc_attributes::PreRangeAttribute *, GASValue *, char *))v20
   + 10))(
    a1: v2[55].Deref + 16,
    a2: &v18,
    a3: v2 + 6,
    a4: v15,
    a5: (char *)&pgc + 3);
  GASValue::~GASValue(this: v17, a2: (int)a1);
  if ( v13 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v13, a2: (int)a1);
  return a1;
}
