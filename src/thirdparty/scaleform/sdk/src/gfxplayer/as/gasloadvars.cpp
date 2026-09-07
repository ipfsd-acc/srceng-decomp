// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasloadvars.cpp
// Functions: 19
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasloadvars.h"

//------------------------------------------------------------------------------
// Address: 0x10112C60
// Name: public: virtual bool GASLoadVarsObject::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASLoadVarsObject::SetMember(
        IClientRenderable *this,
        int a2,
        _IMAGE_SYMBOL_EX *name,
        tagWNDCLASSW *val,
        int flags)
{
  _IMAGE_SYMBOL_EX *v5; // edi

  v5 = name;
  GASObject::SetMemberFlags(
    (ISteamMatchmakingServerListResponse *)this,
    name: (_IMAGE_SYMBOL_EX *)(a2 + 120),
    a3: (int)name,
    flags: 0);
  HIBYTE(name) = 0;
  GASObject::SetMember(
    (CTSQueue<CFunctor *,0,1> *)this,
    (GASEnvironment *)a2,
    name: v5,
    pval: (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)val,
    pmember: (char *)&name + 3);
}

//------------------------------------------------------------------------------
// Address: 0x10112CA0
// Name: public: static void GASLoadVarsProto::GetBytesLoaded(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASLoadVarsProto::GetBytesLoaded(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  double *p_cxItem; // ecx
  GASFnCall v4; // esi
  double v5; // [esp+4h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x1Bu) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = (double *)&v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = a2[1];
    if ( p_cxItem[7] >= 0.0 )
    {
      v5 = p_cxItem[7];
      if ( LOBYTE(v4->cbSize) >= 5u )
        GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
      LOBYTE(v4->cbSize) = 3;
      *(double *)&v4->cItems = v5;
    }
    else
    {
      GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
      LOBYTE(v4->cbSize) = 0;
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "LoadVars", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112D20
// Name: public: static void GASLoadVarsProto::GetBytesTotal(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASLoadVarsProto::GetBytesTotal(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall v2; // eax
  double *p_cxItem; // ecx
  GASFnCall v4; // esi
  double v5; // [esp+4h] [ebp-8h]

  if ( GASFnCall::CheckThisPtr(this: a2, type: 0x1Bu) )
  {
    v2 = a2[2];
    if ( v2 != nullptr )
      p_cxItem = (double *)&v2[-1].cxItem;
    else
      p_cxItem = nullptr;
    v4 = a2[1];
    if ( p_cxItem[8] >= 0.0 )
    {
      v5 = p_cxItem[8];
      if ( LOBYTE(v4->cbSize) >= 5u )
        GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
      LOBYTE(v4->cbSize) = 3;
      *(double *)&v4->cItems = v5;
    }
    else
    {
      GASValue::DropRefs(this: (GASValue *)v4, a2: a1);
      LOBYTE(v4->cbSize) = 0;
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a2, a2: "LoadVars", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112DA0
// Name: public: static void GASLoadVarsProto::Load(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASLoadVarsProto::Load(int a1@<edi>, GASFnCall *a2)
{
  GASFnCall *v2; // esi
  GASFnCall v3; // esi
  GASFnCall v4; // eax
  int p_cxItem; // edi
  tagRID_DEVICE_INFO_KEYBOARD *v6; // ebx
  unsigned __int8 *v7; // eax
  struct GFxMovieRoot *MovieRoot; // eax
  GASFnCall v9; // esi
  GASFnCall *v10; // eax
  bool v11; // zf
  char *v12; // [esp-10h] [ebp-14h]

  v2 = a2;
  if ( a2[7] != nullptr )
  {
    if ( GASFnCall::CheckThisPtr(this: a2, type: 0x1Bu) )
    {
      v4 = v2[2];
      if ( v4 != nullptr )
        p_cxItem = (int)&v4[-1].cxItem;
      else
        p_cxItem = 0;
      v6 = (tagRID_DEVICE_INFO_KEYBOARD *)v2[6];
      v7 = (unsigned __int8 *)GASFnCall::Arg(this: v2, a2: 0);
      GASValue::ToStringImpl(this: v7, (int *)&a2, a3: v6, precision: -1, debug: false);
      *(double *)(p_cxItem + 56) = 0.0;
      v12 = (char *)*a2;
      MovieRoot = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)v2[6]);
      GFxMovieRoot::AddVarLoadQueueEntry(
        this: (int)MovieRoot,
        result: (IDirect3DPixelShader9 *)p_cxItem,
        a3: v12,
        a4: nullptr);
      v9 = v2[1];
      GASValue::DropRefs(this: (GASValue *)v9, a2: p_cxItem);
      LOBYTE(v9->cbSize) = 2;
      LOBYTE(v9->cItems) = 1;
      v10 = a2;
      v11 = a2[2] == (GASFnCall)1;
      a2[2] = (GASFnCall)((char *)a2[2] - 1);
      if ( v11 )
        GASStringNode::ReleaseNode(a1: (int)v10);
    }
    else
    {
      GASFnCall::ThisPtrError(this: v2, a2: "LoadVars", a3: nullptr, a4: 0);
    }
  }
  else
  {
    v3 = a2[1];
    GASValue::DropRefs(this: (GASValue *)v3, a2: a1);
    LOBYTE(v3->cbSize) = 2;
    LOBYTE(v3->cItems) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112E60
// Name: public: static void GASLoadVarsLoaderCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASLoadVarsLoaderCtorFunction::GlobalCtor(int a1@<edi>, const struct GASFnCall *a2)
{
  int v2; // eax
  GASValue *v3; // esi

  if ( *((_DWORD *)a2 + 2) != 0
    && (*(int (__thiscall **)(_DWORD))(**((_DWORD **)a2 + 2) + 8))(a1: *((_DWORD *)a2 + 2)) == 27
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)a2 + 2) + 64))(a1: *((_DWORD *)a2 + 2)) == 0 )
  {
    v2 = *((_DWORD *)a2 + 2);
    if ( v2 != 0 )
      GASValue::SetAsObject(this: *((GASValue **)a2 + 1), a2: (struct GASObject *)(v2 - 16));
    else
      GASValue::SetAsObject(this: *((GASValue **)a2 + 1), a2: nullptr);
  }
  else
  {
    v3 = *((GASValue **)a2 + 1);
    GASValue::DropRefs(this: v3, a2: a1);
    *(_BYTE *)v3 = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112EC0
// Name: public: virtual enum GASObjectInterface::ObjectType GASLoadVarsObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int GASLoadVarsObject::GetObjectType()
{
  return 27;
}

//------------------------------------------------------------------------------
// Address: 0x10112ED0
// Name: _GASLoadVarsProto::ToString_::_7_::MemberVisitor::Visit
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GASLoadVarsProto::ToString_::_7_::MemberVisitor::Visit(
        int this,
        const char ***a2,
        unsigned __int8 *a3,
        int a4)
{
  int v5; // eax
  void *v7; // esi
  int v9; // [esp+0h] [ebp-24h]
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> v10; // [esp+4h] [ebp-20h] BYREF
  int v11; // [esp+1Ch] [ebp-8h] BYREF
  GString v12; // [esp+20h] [ebp-4h] BYREF

  GStringBuffer::GStringBuffer(
    this: &v10,
    result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)GMemory::pGlobalHeap);
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v12);
  GASGlobalContext::Escape(a1: **a2, a2: (unsigned int)(*a2)[4], a3: (CUtlMemory<CImagePacker,int> *)&v12);
  GStringBuffer::AppendString(
    this: &v10,
    putf8str: (char *)((v12.HeapTypeBits & 0xFFFFFFFC) + 8),
    utf8StrSz: *(_DWORD *)(v12.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  GStringBuffer::AppendString(this: &v10, putf8str: "=", utf8StrSz: -1);
  GString::Clear(this: &v12);
  GASValue::ToStringImpl(
    this: a3,
    a2: &v11,
    a3: *(tagRID_DEVICE_INFO_KEYBOARD **)(this + 4),
    precision: -1,
    debug: false);
  GASGlobalContext::Escape(a1: *(const char **)v11, a2: *(_DWORD *)(v11 + 16), a3: (CUtlMemory<CImagePacker,int> *)&v12);
  GStringBuffer::AppendString(
    this: &v10,
    putf8str: (char *)((v12.HeapTypeBits & 0xFFFFFFFC) + 8),
    utf8StrSz: *(_DWORD *)(v12.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  GStringBuffer::AppendString(this: &v10, putf8str: "&", utf8StrSz: -1);
  GString::operator=(
    this: *(CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > **)(this + 8),
    src: (void (__cdecl **)(int))&v10,
    polddata: v9,
    src_8: v10.m_pfnProxied);
  v5 = v11;
  if ( (*(_DWORD *)(v11 + 8))-- == 1 )
    GASStringNode::ReleaseNode(a1: v5);
  v7 = (void *)(v12.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v12.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
  return GStringBuffer::~GStringBuffer(this: &v10);
}

//------------------------------------------------------------------------------
// Address: 0x10112FE0
// Name: public: static bool GASLoadVarsProto::LoadVariables(class GASEnvironment __near *,class GASObjectInterface __near *,class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
static char __usercall GASLoadVarsProto::LoadVariables@<al>(
        unsigned int a1@<ebx>,
        unsigned int a2@<edi>,
        struct GASEnvironment *a3,
        struct GASObjectInterface *a4,
        CUtlMemory<CImagePacker,int> *a5)
{
  CUtlMemory<CImagePacker,int> *v5; // esi
  char v7; // bl
  int FirstCharAt; // eax
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v9; // eax
  struct GASStringNode *StringNode; // esi
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *m_pfnProxied; // eax
  int v12; // eax
  bool v13; // zf
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *v14; // ecx
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v15; // eax
  struct GASStringNode *v16; // esi
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v17; // eax
  int v18; // eax
  __int128 v19; // [esp-8h] [ebp-58h] BYREF
  unsigned int v20; // [esp+8h] [ebp-48h]
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> v21; // [esp+1Ch] [ebp-34h] BYREF
  GASValue v22; // [esp+34h] [ebp-1Ch] BYREF
  struct GASStringNode *v23; // [esp+38h] [ebp-18h]
  int offset; // [esp+44h] [ebp-Ch] BYREF
  struct GASStringNode *v25; // [esp+48h] [ebp-8h] BYREF
  char v26; // [esp+4Fh] [ebp-1h] BYREF

  GStringBuffer::GStringBuffer(
    this: &v21,
    result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)GMemory::pGlobalHeap);
  GStringBuffer::GStringBuffer(
    this: (_DWORD *)&v19 + 3,
    result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)GMemory::pGlobalHeap);
  v5 = a5;
  if ( (*(_DWORD *)((int)a5->m_pMemory & 0xFFFFFFFC) & 0x7FFFFFFF) == 0 )
  {
    GStringBuffer::~GStringBuffer(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&v19 + 12));
    GStringBuffer::~GStringBuffer(this: &v21);
    return 0;
  }
  *(_QWORD *)&v19 = __PAIR64__(a1, a2);
  v7 = 1;
  FirstCharAt = GString::GetFirstCharAt(
                  this: a5,
                  index: nullptr,
                  (CUtlMap<char const *,int,unsigned short>::CKeyLess)&offset);
  if ( FirstCharAt != 0 )
  {
    while ( 1 )
    {
      if ( FirstCharAt == 13 )
      {
        FirstCharAt = 10;
      }
      else if ( FirstCharAt == 38 )
      {
        v9 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)HIDWORD(v19);
        if ( HIDWORD(v19) == 0 )
          v9 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&pMem;
        StringNode = GASStringManager::CreateStringNode(
                       this: *(GASStringManager **)(*((_DWORD *)a3 + 30) + 636),
                       result: v9,
                       length: v20);
        ++*((_DWORD *)StringNode + 2);
        LOBYTE(v22) = 5;
        v23 = StringNode;
        ++*((_DWORD *)StringNode + 2);
        m_pfnProxied = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v21.m_pfnProxied;
        v26 = 0;
        if ( LODWORD(v21.m_pfnProxied) == 0 )
          m_pfnProxied = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&pMem;
        v25 = GASStringManager::CreateStringNode(
                this: *(GASStringManager **)(*((_DWORD *)a3 + 30) + 636),
                result: m_pfnProxied,
                length: DWORD1(v21.m_pfnProxied));
        ++*((_DWORD *)v25 + 2);
        (*(void (__thiscall **)(struct GASObjectInterface *, struct GASEnvironment *, struct GASStringNode **, GASValue *, char *))(*(_DWORD *)a4 + 12))(
          a1: a4,
          a2: a3,
          a3: &v25,
          a4: &v22,
          a5: &v26);
        v12 = (int)v25;
        v13 = (*((_DWORD *)v25 + 2))-- == 1;
        if ( v13 )
          GASStringNode::ReleaseNode(a1: v12);
        GASValue::~GASValue(this: &v22, a2: (int)a3);
        v13 = (*((_DWORD *)StringNode + 2))-- == 1;
        if ( v13 )
          GASStringNode::ReleaseNode(a1: (int)StringNode);
        GStringBuffer::Clear(this: &v21);
        GStringBuffer::Clear(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&v19 + 12));
        v5 = a5;
        v7 = 1;
        goto LABEL_22;
      }
      if ( v7 == 0 )
        break;
      if ( FirstCharAt != 61 )
      {
        v14 = &v21;
LABEL_21:
        GStringBuffer::AppendChar(this: v14, ch: (CMatRenderContextBase *)FirstCharAt, srcSize: v19);
        goto LABEL_22;
      }
      v7 = 0;
LABEL_22:
      FirstCharAt = (int)GString::GetNextChar(this: v5, (CUtlMap<char const *,int,unsigned short>::CKeyLess)&offset);
      if ( FirstCharAt == 0 )
        goto LABEL_23;
    }
    v14 = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&v19 + 12);
    goto LABEL_21;
  }
LABEL_23:
  if ( GStringBuffer::GetLength(this: (int)&v21) != nullptr )
  {
    v15 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)HIDWORD(v19);
    if ( HIDWORD(v19) == 0 )
      v15 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&pMem;
    v16 = GASStringManager::CreateStringNode(
            this: *(GASStringManager **)(*((_DWORD *)a3 + 30) + 636),
            result: v15,
            length: v20);
    ++*((_DWORD *)v16 + 2);
    LOBYTE(v22) = 5;
    v23 = v16;
    ++*((_DWORD *)v16 + 2);
    v17 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v21.m_pfnProxied;
    HIBYTE(a5) = 0;
    if ( LODWORD(v21.m_pfnProxied) == 0 )
      v17 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&pMem;
    v25 = GASStringManager::CreateStringNode(
            this: *(GASStringManager **)(*((_DWORD *)a3 + 30) + 636),
            result: v17,
            length: DWORD1(v21.m_pfnProxied));
    ++*((_DWORD *)v25 + 2);
    (*(void (__thiscall **)(struct GASObjectInterface *, struct GASEnvironment *, struct GASStringNode **, GASValue *, char *))(*(_DWORD *)a4 + 12))(
      a1: a4,
      a2: a3,
      a3: &v25,
      a4: &v22,
      a5: (char *)&a5 + 3);
    v18 = (int)v25;
    v13 = (*((_DWORD *)v25 + 2))-- == 1;
    if ( v13 )
      GASStringNode::ReleaseNode(a1: v18);
    GASValue::~GASValue(this: &v22, a2: -1);
    v13 = (*((_DWORD *)v16 + 2))-- == 1;
    if ( v13 )
      GASStringNode::ReleaseNode(a1: (int)v16);
  }
  GStringBuffer::~GStringBuffer(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&v19 + 12));
  GStringBuffer::~GStringBuffer(this: &v21);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10113250
// Name: public: static void GASLoadVarsProto::AddRequestHeader(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASLoadVarsProto::AddRequestHeader(GASFnCall *a1)
{
  struct GFxLog *Log; // eax
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v2; // ecx
  int v3; // [esp+0h] [ebp-4h]

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x1Bu) )
  {
    Log = GASFnCall::GetLog(this: a1);
    if ( Log != nullptr )
      GFxLogBase<GFxLog>::LogScriptError(
        this: v2,
        pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&Log->GFxLogBase<GFxLog>,
        this_4: (int)"LoadVars.addRequestHeader is not implemented.",
        this_8: v3);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: "LoadVars", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101132A0
// Name: public: static void GASLoadVarsProto::Decode(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASLoadVarsProto::Decode(CUtlMemory<CImagePacker,int> a1)
{
  CImagePacker *m_pMemory; // esi
  int v2; // eax
  unsigned int v3; // ebx
  tagRID_DEVICE_INFO_KEYBOARD *v4; // edi
  unsigned __int8 *v5; // eax
  const char *v6; // edi
  unsigned int Length; // eax
  struct GASObjectInterface *v8; // eax
  void *v9; // esi
  const char **v10; // eax
  const char **v12; // [esp+4h] [ebp-4h] BYREF

  m_pMemory = a1.m_pMemory;
  if ( a1.m_pMemory->m_pLightmapWavefront[5] > 0 )
  {
    if ( GASFnCall::CheckThisPtr(this: &a1.m_pMemory->m_MaxLightmapWidth, type: 0x1Bu) )
    {
      v2 = m_pMemory->m_pLightmapWavefront[0];
      if ( v2 != 0 )
        v3 = v2 - 16;
      else
        v3 = 0;
      v4 = (tagRID_DEVICE_INFO_KEYBOARD *)m_pMemory->m_pLightmapWavefront[4];
      v5 = (unsigned __int8 *)GASFnCall::Arg(this: (GASFnCall *)m_pMemory, a2: 0);
      GASValue::ToStringImpl(this: v5, a2: (int *)&v12, a3: v4, precision: -1, debug: false);
      GString::GString(this: &a1);
      v6 = *v12;
      Length = GASString::GetLength(this: &v12);
      GASGlobalContext::Unescape(a1: v6, a2: Length, a3: &a1);
      if ( v3 != 0 )
        v8 = (struct GASObjectInterface *)(v3 + 16);
      else
        v8 = nullptr;
      GASLoadVarsProto::LoadVariables(
        a1: v3,
        a2: (unsigned int)v6,
        a3: (struct GASEnvironment *)m_pMemory->m_pLightmapWavefront[4],
        a4: v8,
        a5: &a1);
      v9 = (void *)((int)a1.m_pMemory & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)a1.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
      v10 = v12;
      if ( v12[2]-- == (const char *)1 )
        GASStringNode::ReleaseNode(a1: (int)v10);
    }
    else
    {
      GASFnCall::ThisPtrError(this: (GASFnCall *)m_pMemory, a2: "LoadVars", a3: nullptr, a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10113380
// Name: public: static void GASLoadVarsProto::Send(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASLoadVarsProto::Send(GASFnCall *a1)
{
  struct GFxLog *Log; // eax
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v2; // ecx
  int v3; // [esp+0h] [ebp-4h]

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x1Bu) )
  {
    Log = GASFnCall::GetLog(this: a1);
    if ( Log != nullptr )
      GFxLogBase<GFxLog>::LogScriptError(
        this: v2,
        pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&Log->GFxLogBase<GFxLog>,
        this_4: (int)"LoadVars.send is not implemented.",
        this_8: v3);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: "LoadVars", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101133D0
// Name: public: static void GASLoadVarsProto::SendAndLoad(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASLoadVarsProto::SendAndLoad(GASFnCall *a1)
{
  struct GFxLog *Log; // eax
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v2; // ecx
  int v3; // [esp+0h] [ebp-4h]

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x1Bu) )
  {
    Log = GASFnCall::GetLog(this: a1);
    if ( Log != nullptr )
      GFxLogBase<GFxLog>::LogScriptError(
        this: v2,
        pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&Log->GFxLogBase<GFxLog>,
        this_4: (int)"LoadVars.sendAndLoad is not implemented.",
        this_8: v3);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: "LoadVars", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10113420
// Name: public: static void GASLoadVarsProto::ToString(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASLoadVarsProto::ToString(GASFnCall *a1)
{
  GASFnCall v1; // eax
  int *p_cxItem; // esi
  GASFnCall v3; // eax
  int Length; // eax
  struct GASStringNode *StringNode; // esi
  GASFnCall v6; // edi
  bool v7; // zf
  void *v8; // esi
  _DWORD v9[3]; // [esp+4h] [ebp-10h] BYREF
  GString v10; // [esp+10h] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x1Bu) )
  {
    v1 = a1[2];
    if ( v1 != nullptr )
      p_cxItem = &v1[-1].cxItem;
    else
      p_cxItem = nullptr;
    GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v10);
    v3 = a1[6];
    v9[2] = &v10;
    v9[1] = v3;
    v9[0] = &`GASLoadVarsProto::ToString'::`7'::MemberVisitor::`vftable';
    (*(void (__thiscall **)(char *, GASFnCall, _DWORD *, _DWORD, _DWORD))(p_cxItem[4] + 32))(
      a1: (char *)p_cxItem + 16,
      a2: v3 + 3,
      a3: v9,
      a4: 0,
      a5: 0);
    Length = GString::GetLength(this: &v10);
    GString::Remove(this: (CUtlMemory<CImagePacker,int> *)&v10, posAt: (CImagePacker *)(Length - 1), removeLength: 1);
    StringNode = GASStringManager::CreateStringNode(
                   this: *(GASStringManager **)(a1[6][3].cbSize + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((v10.HeapTypeBits
                                                                                             & 0xFFFFFFFC)
                                                                                            + 8),
                   length: *(_DWORD *)(v10.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
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
    v8 = (void *)(v10.HeapTypeBits & 0xFFFFFFFC);
    v9[0] = &GString::InitStruct::`vftable';
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v10.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: "LoadVars", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101135B0
// Name: public: GASLoadVarsObject::GASLoadVarsObject(class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
GASLoadVarsObject *__thiscall GASLoadVarsObject::GASLoadVarsObject(GASLoadVarsObject *this, struct GASEnvironment *a2)
{
  struct GASEnvironment *v2; // esi
  GASObject *v4; // edi
  vc_attributes::PreRangeAttribute *v5; // ecx
  HWND__ *v6; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GPtr<GFxAmpProfileFrame> v8; // ecx
  int v9; // ecx
  struct GASStringNode *ConstStringNode; // ebx
  unsigned int dwExitCode; // eax
  bool v12; // zf
  int v13; // eax
  unsigned int v14; // eax
  tagMSG v16; // [esp-8h] [ebp-2Ch] BYREF
  struct GASObjectInterface *v17; // [esp+14h] [ebp-10h]
  GASLoadVarsObject *v18; // [esp+1Ch] [ebp-8h]
  _EXIT_THREAD_DEBUG_INFO v19; // [esp+20h] [ebp-4h] BYREF

  v2 = a2;
  v18 = this;
  GASObject::GASObject((GASObject *)this, a2);
  v4 = (GASObject *)(this + 4);
  *this = (GASLoadVarsObject)&GASStageObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASLoadVarsObject::`vftable'{for `GASObjectInterface'};
  v5 = *((vc_attributes::PreRangeAttribute **)v2 + 30);
  v6 = (HWND__ *)((char *)v2 + 120);
  Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                    this: v5,
                                                    result: (vc_attributes::InvalidCheckAttribute *)0x1F);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)(this + 4),
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)v6,
    psc_4: Prototype);
  v16.message = (unsigned int)(this + 4);
  v16.hwnd = v6;
  GASAsBroadcaster::Initialize(pobj: v16, a2: v17);
  *((double *)this + 7) = -1.0;
  *((double *)this + 8) = -1.0;
  GASAsBroadcaster::AddListener(penv: v8);
  v9 = *(_DWORD *)v6;
  HIBYTE(a2) = 1;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(v9 + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"application/x-www-form-urlencoded",
                      a3: 0x21u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  LOBYTE(v16.pt.x) = 5;
  v16.pt.y = (int)ConstStringNode;
  ++*((_DWORD *)ConstStringNode + 2);
  v19.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(*(_DWORD *)v6 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A52B4.m_Memory.m_nGrowSize,
                                   a3: 0xBu,
                                   a4: 0);
  ++*(_DWORD *)(v19.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: v4,
    a2: (struct GASStringContext *)v6,
    a3: &v19,
    a4: (GASValue *)&v16.pt,
    a5: (const struct GASPropFlags *)((char *)&a2 + 3));
  dwExitCode = v19.dwExitCode;
  v12 = (*(_DWORD *)(v19.dwExitCode + 8))-- == 1;
  if ( v12 )
    GASStringNode::ReleaseNode(a1: dwExitCode);
  GASValue::~GASValue(this: (GASValue *)&v16.pt, a2: (int)v4);
  v12 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v12 )
    GASStringNode::ReleaseNode(a1: (int)ConstStringNode);
  v13 = *(_DWORD *)v6;
  HIBYTE(a2) = 1;
  LOBYTE(v16.pt.x) = 0;
  v19.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(v13 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A52B4,
                                   a3: 6u,
                                   a4: 0);
  ++*(_DWORD *)(v19.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: v4,
    a2: (struct GASStringContext *)v6,
    a3: &v19,
    a4: (GASValue *)&v16.pt,
    a5: (const struct GASPropFlags *)((char *)&a2 + 3));
  v14 = v19.dwExitCode;
  v12 = (*(_DWORD *)(v19.dwExitCode + 8))-- == 1;
  if ( v12 )
    GASStringNode::ReleaseNode(a1: v14);
  GASValue::~GASValue(this: (GASValue *)&v16.pt, a2: v16.wParam);
  return v18;
}

//------------------------------------------------------------------------------
// Address: 0x101136F0
// Name: public: virtual class GASObject __near * GASLoadVarsLoaderCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASLoadVarsLoaderCtorFunction::CreateNewObject(matrix3x4_t *this, struct GASEnvironment *a2)
{
  struct GASEnvironment *v2; // esi
  int v3; // ecx
  int (__thiscall *v4)(int, int, struct GASEnvironment **); // edx
  GASLoadVarsObject *v5; // eax

  v2 = a2;
  v3 = *(_DWORD *)(*((_DWORD *)a2 + 30) + 656);
  v4 = *(int (__thiscall **)(int, int, struct GASEnvironment **))(*(_DWORD *)v3 + 40);
  a2 = (struct GASEnvironment *)323;
  v5 = (GASLoadVarsObject *)v4(a1: v3, a2: 72, a3: &a2);
  if ( v5 != nullptr )
    GASLoadVarsObject::GASLoadVarsObject(this: v5, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101137B0
// Name: public: void GASLoadVarsObject::NotifyOnData(class GASEnvironment __near *,class GASString __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASLoadVarsObject::NotifyOnData(
        IClientRenderable *this,
        IClientRenderable *penv,
        const IClientRenderable *src)
{
  IClientRenderable_vtbl *v5; // eax
  const IClientRenderable *v6; // ecx
  IClientRenderable_vtbl *v7; // ecx
  int v8; // edi
  const IClientRenderable *v9; // eax
  IClientRenderable *penva; // [esp+14h] [ebp+8h]

  penv[2].__vftable = (IClientRenderable_vtbl *)((char *)penv[2].__vftable + 16);
  if ( penv[2].__vftable >= penv[4].__vftable )
    GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)&penv[2]);
  v5 = penv[2].__vftable;
  if ( v5 != nullptr )
  {
    v6 = src;
    LOBYTE(v5->GetIClientUnknown) = 5;
    v7 = v6->__vftable;
    v5->GetRenderOrigin = (const Vector *(__thiscall *)(IClientRenderable *))v7;
    ++v7->GetRenderAngles;
  }
  if ( this != nullptr )
    penva = this + 4;
  else
    penva = nullptr;
  v8 = (((char *)penv[2].__vftable - (char *)penv[3].__vftable) >> 4) + 32 * (int)penv[7].__vftable - 32;
  src = (const IClientRenderable *)GASStringManager::CreateConstStringNode(
                                     this: (GASStringManager *)penv[30].__vftable[3].MarkShadowDirty,
                                     result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A402C,
                                     a3: 6u,
                                     a4: 0);
  ++src[2].__vftable;
  GASAsBroadcaster::BroadcastMessage(
    a1: (struct GASEnvironment *)penv,
    eventName: (_IMAGE_SYMBOL_EX *)penva,
    a3: (const struct GASString *)&src,
    nArgs: 1,
    firstArgBottomIndex: v8);
  v9 = src;
  if ( src[2].__vftable-- == (IClientRenderable_vtbl *)1 )
    GASStringNode::ReleaseNode(a1: (int)v9);
  GASValue::~GASValue(this: (GASValue *)penv[2].__vftable, a2: v8);
  penv[2].__vftable = (IClientRenderable_vtbl *)((char *)penv[2].__vftable - 16);
  if ( penv[2].__vftable < penv[3].__vftable )
    GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)&penv[2]);
}

//------------------------------------------------------------------------------
// Address: 0x10113930
// Name: public: static void GASLoadVarsProto::DefaultOnData(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASLoadVarsProto::DefaultOnData(GASFnCall *a1)
{
  GASFnCall v1; // edi
  GArrayBase<GArrayData<enum GRenderer::BlendType,GAllocatorLH<enum GRenderer::BlendType,2>,GArrayConstPolicy<0,4,1> > > *p_cxItem; // edi
  tagRID_DEVICE_INFO_KEYBOARD *v3; // ebx
  unsigned __int8 *v4; // eax
  GString::DataDesc *pData; // eax
  bool v6; // zf
  tagRID_DEVICE_INFO_KEYBOARD *v7; // ebx
  unsigned __int8 *v8; // eax
  struct GASObjectInterface *p_Size; // eax
  void *v10; // esi
  int v11; // eax
  void *v12; // esi
  GString v13; // [esp+4h] [ebp-Ch] BYREF
  int *v14; // [esp+8h] [ebp-8h] BYREF
  GString v15; // [esp+Ch] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: a1, type: 0x1Bu) )
  {
    v1 = a1[2];
    if ( v1 != nullptr )
      p_cxItem = (GArrayBase<GArrayData<enum GRenderer::BlendType,GAllocatorLH<enum GRenderer::BlendType,2>,GArrayConstPolicy<0,4,1> > > *)&v1[-1].cxItem;
    else
      p_cxItem = nullptr;
    v3 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
    v4 = (unsigned __int8 *)GASFnCall::Arg(this: a1, a2: 0);
    GASValue::ToStringImpl(this: v4, a2: (int *)&v15, a3: v3, precision: -1, debug: false);
    GString::GString(this: &v13, src: v15.pData->Size);
    pData = v15.pData;
    v6 = (*(_DWORD *)v15.pData->Data)-- == 1;
    if ( v6 )
      GASStringNode::ReleaseNode(a1: (int)pData);
    v7 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
    v8 = (unsigned __int8 *)GASFnCall::Arg(this: a1, a2: 0);
    GASValue::ToStringImpl(this: v8, a2: (int *)&v14, a3: v7, precision: -1, debug: false);
    GString::GString(this: &v15, src: *v14);
    if ( p_cxItem != nullptr )
      p_Size = (struct GASObjectInterface *)&p_cxItem[1].Data.Size;
    else
      p_Size = nullptr;
    GASLoadVarsProto::LoadVariables(
      a1: (unsigned int)v7,
      a2: (unsigned int)p_cxItem,
      a3: (struct GASEnvironment *)a1[6],
      a4: p_Size,
      a5: (CUtlMemory<CImagePacker,int> *)&v15);
    GASStyleSheetObject::NotifyOnLoad(this: p_cxItem);
    v10 = (void *)(v15.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v15.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v10);
    v11 = (int)v14;
    v6 = v14[2]-- == 1;
    if ( v6 )
      GASStringNode::ReleaseNode(a1: v11);
    v12 = (void *)(v13.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v13.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v12);
  }
  else
  {
    GASFnCall::ThisPtrError(this: a1, a2: "LoadVars", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10113AC0
// Name: public: GASLoadVarsProto::GASLoadVarsProto(class GASStringContext __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
GASLoadVarsProto *__thiscall GASLoadVarsProto::GASLoadVarsProto(
        GASLoadVarsProto *this,
        GRenderer::DistanceFieldParams *result,
        CTSQueue<CFunctor *,0,1>::Node_t *ConstStringNode,
        const struct GASFunctionRef *a4)
{
  struct GASObject *v6; // eax
  GASValue v9[4]; // [esp+Ch] [ebp-10h] BYREF
  GRenderer::DistanceFieldParams *v10; // [esp+24h] [ebp+8h]

  GASPrototype<GASLoadVarsObject,GASEnvironment>::GASPrototype<GASLoadVarsObject,GASEnvironment>(
    (int)this,
    result,
    psc_4: ConstStringNode,
    psc_8: (unsigned int)a4);
  *(_DWORD *)this = &GASLoadVarsProto::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASLoadVarsProto::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 18) = &GASLoadVarsProto::`vftable';
  HIBYTE(a4) = 1;
  GASPrototypeBase::InitFunctionMembers(
    this: (GASPrototypeBase *)this + 18,
    a2: (int)this,
    flags: (vc_attributes::PreRangeAttribute **)result,
    flags_4: (const struct GASNameFunction *)&GASLoadVarsProto::FunctionTable,
    flags_8: (const struct GASPropFlags *)((char *)&a4 + 3));
  HIBYTE(a4) = 1;
  v10 = (GRenderer::DistanceFieldParams *)GASValue::GASValue(
                                            this: v9,
                                            func: (int)result,
                                            a3: (void (__cdecl *)(const struct GASFnCall *))GASLoadVarsProto::DefaultOnData);
  ConstStringNode = (CTSQueue<CFunctor *,0,1>::Node_t *)GASStringManager::CreateConstStringNode(
                                                          this: *(GASStringManager **)(LODWORD(result->Width) + 636),
                                                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A402C,
                                                          a3: 6u,
                                                          a4: 0);
  ++ConstStringNode[1].pNext;
  (*(void (__thiscall **)(char *, GRenderer::DistanceFieldParams *, CTSQueue<CFunctor *,0,1>::Node_t **, GRenderer::DistanceFieldParams *, char *))(*((_DWORD *)this + 4) + 40))(
    a1: (char *)this + 16,
    a2: result,
    a3: &ConstStringNode,
    a4: v10,
    a5: (char *)&a4 + 3);
  v6 = (struct GASObject *)ConstStringNode;
  if ( ConstStringNode[1].pNext-- == (CTSQueue<CFunctor *,0,1>::Node_t *)1 )
    GASStringNode::ReleaseNode(a1: (int)v6);
  GASValue::~GASValue(this: v9, a2: (int)result);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10113BF0
// Name: public: static class GASFunctionRef GASLoadVarsLoaderCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GASLoadVarsLoaderCtorFunction::Register(const Vector *pgc, int sc)
{
  vc_attributes::PreRangeAttribute *v2; // esi
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // eax
  GASCFunctionObject *v5; // eax
  GASCFunctionObject *v6; // edi
  float v7; // eax
  const char *MaxVal; // ecx
  int (__thiscall *v10)(const char *, int, int *); // edx
  GASLoadVarsProto *v11; // ebx
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GASLoadVarsProto *v13; // eax
  _DWORD *v14; // eax
  int v15; // ebx
  GASValue *v16; // eax
  GASValue v17[4]; // [esp+Ch] [ebp-1Ch] BYREF
  int v18; // [esp+1Ch] [ebp-Ch] BYREF
  char v19; // [esp+20h] [ebp-8h]
  _DWORD *v20; // [esp+24h] [ebp-4h]
  struct GASFunctionRef *v21; // [esp+30h] [ebp+8h]

  v2 = (vc_attributes::PreRangeAttribute *)sc;
  v3 = *(_DWORD *)(sc + 656);
  v18 = sc;
  v19 = 8;
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  sc = 323;
  v5 = (GASCFunctionObject *)v4(a1: v3, a2: 56, a3: &sc);
  v6 = v5;
  if ( v5 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v5,
      func: (_REASON_CONTEXT *)&v18,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASLoadVarsLoaderCtorFunction::GlobalCtor);
    v6->dwSize = (unsigned int)&GASLoadVarsLoaderCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v6->cLineHeight = (unsigned int)&GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
    v7 = *(float *)&v6;
  }
  else
  {
    v7 = 0.0;
  }
  pgc->x = v7;
  LOBYTE(pgc->z) = 0;
  pgc->y = 0.0;
  MaxVal = v2[54].MaxVal;
  v10 = *(int (__thiscall **)(const char *, int, int *))(*(_DWORD *)MaxVal + 40);
  sc = 323;
  v11 = (GASLoadVarsProto *)v10(a1: MaxVal, a2: 104, a3: &sc);
  if ( v11 != nullptr )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v2,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    v13 = GASLoadVarsProto::GASLoadVarsProto(
            this: v11,
            result: (GRenderer::DistanceFieldParams *)&v18,
            ConstStringNode: Prototype,
            a4: (const struct GASFunctionRef *)pgc);
    v21 = v13;
  }
  else
  {
    v21 = nullptr;
    v13 = nullptr;
  }
  if ( v13 != nullptr )
    *((_DWORD *)v13 + 2) = (*((_DWORD *)v13 + 2) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)pgc, a3: 31, a4: (int)v13);
  v14 = v2[56].MaxVal + 16;
  HIBYTE(sc) = 0;
  v15 = *v14;
  v20 = v14;
  v16 = GASValue::GASValue(this: v17, a2: (int)pgc, a3: (const struct GASFunctionRef *)pgc);
  (*(void (__thiscall **)(_DWORD *, int *, vc_attributes::PreRangeAttribute *, GASValue *, char *))(v15 + 40))(
    a1: v20,
    a2: &v18,
    a3: v2 + 11,
    a4: v16,
    a5: (char *)&sc + 3);
  GASValue::~GASValue(this: v17, a2: (int)pgc);
  if ( v21 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v21, a2: (int)pgc);
}
