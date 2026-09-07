// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasmoviecliploader.cpp
// Functions: 11
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasmoviecliploader.h"

//------------------------------------------------------------------------------
// Address: 0x10111810
// Name: public: static void GASMovieClipLoaderCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASMovieClipLoaderCtorFunction::GlobalCtor(int a1@<edi>, const struct GASFnCall *a2)
{
  int v2; // eax
  struct GASObject *v3; // edi
  GPtr<GFxAmpProfileFrame> v4; // ecx
  GASValue *v5; // esi

  if ( *((_DWORD *)a2 + 2) != 0
    && (*(int (__thiscall **)(_DWORD))(**((_DWORD **)a2 + 2) + 8))(a1: *((_DWORD *)a2 + 2)) == 25
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)a2 + 2) + 64))(a1: *((_DWORD *)a2 + 2)) == 0 )
  {
    v2 = *((_DWORD *)a2 + 2);
    if ( v2 != 0 )
    {
      v3 = (struct GASObject *)(v2 - 16);
      if ( v2 != 16 )
      {
        v4.pObject = *((GFxAmpProfileFrame **)a2 + 2);
LABEL_9:
        GASAsBroadcaster::AddListener(penv: v4);
        GASValue::SetAsObject(this: *((GASValue **)a2 + 1), a2: v3);
        return;
      }
    }
    else
    {
      v3 = nullptr;
    }
    v4.pObject = nullptr;
    goto LABEL_9;
  }
  v5 = *((GASValue **)a2 + 1);
  GASValue::DropRefs(this: v5, a2: a1);
  *(_BYTE *)v5 = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10111890
// Name: public: static void GASMovieClipLoaderProto::LoadClip(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASMovieClipLoaderProto::LoadClip(GASFnCall *a1)
{
  GASFnCall v2; // edi
  GASFnCall v3; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v4; // edi
  unsigned __int8 *v5; // eax
  GASValue *v6; // eax
  GRefCountNTSImpl *v7; // eax
  unsigned __int8 *v8; // eax
  GRefCountNTSImpl *v9; // eax
  __vc_attributes::event_receiverAttribute::type_e v10; // eax
  bool v11; // zf
  struct GFxMovieRoot *MovieRoot; // eax
  GASFnCall v13; // eax
  const void *Version; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v15; // edi
  unsigned __int8 *v16; // eax
  int v17; // edi
  int v18; // eax
  int v19; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v20; // ebx
  unsigned __int8 *v21; // eax
  ScaleformRenderTarget_vtbl **v22; // eax
  int v23; // eax
  GASFnCall v24; // esi
  GRefCountNTSImpl *v25; // ecx
  __vc_attributes::event_receiverAttribute::type_e v26; // [esp-18h] [ebp-3Ch]
  GRefCountNTSImpl *v27; // [esp-14h] [ebp-38h]
  char *v28; // [esp-10h] [ebp-34h]
  GASEnvironment *v29; // [esp-10h] [ebp-34h]
  const struct GASEnvironment *v30; // [esp-8h] [ebp-2Ch]
  const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v31; // [esp+8h] [ebp-1Ch] BYREF
  BOOL v32; // [esp+Ch] [ebp-18h]
  __vc_attributes::event_receiverAttribute::type_e *v33; // [esp+10h] [ebp-14h] BYREF
  int v34; // [esp+14h] [ebp-10h] BYREF
  __vc_attributes::event_receiverAttribute::type_e path; // [esp+18h] [ebp-Ch] BYREF
  GRefCountNTSImpl *v36; // [esp+1Ch] [ebp-8h]
  char **v37; // [esp+20h] [ebp-4h] BYREF
  GASFnCall *p_cxItem; // [esp+2Ch] [ebp+8h]

  v2 = a1[1];
  GASValue::DropRefs(this: (GASValue *)v2, a2: (int)v2);
  LOBYTE(v2->cbSize) = 2;
  LOBYTE(v2->cItems) = 0;
  if ( (int)a1[7] >= 2 )
  {
    p_cxItem = nullptr;
    if ( (*(int (__thiscall **)(GASFnCall))(a1[2]->cbSize + 8))(a1: a1[2]) == 25 )
    {
      v3 = a1[2];
      if ( v3 != nullptr )
        p_cxItem = (GASFnCall *)&v3[-1].cxItem;
      else
        p_cxItem = nullptr;
    }
    v4 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
    v5 = (unsigned __int8 *)GASFnCall::Arg(this: a1, a2: 0);
    GASValue::ToStringImpl(this: v5, a2: (int *)&v37, a3: v4, precision: -1, debug: false);
    if ( *(_BYTE *)GASFnCall::Arg(this: a1, a2: 1) == 7 )
    {
      v30 = (const struct GASEnvironment *)a1[6];
      v6 = (GASValue *)GASFnCall::Arg(this: a1, a2: 1);
      GASValue::ToASCharacter(this: v6, penv: v30);
      if ( v7 != nullptr )
        ++v7->RefCount;
      v36 = v7;
    }
    else
    {
      v4 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
      v8 = (unsigned __int8 *)GASFnCall::Arg(this: a1, a2: 1);
      GASValue::ToStringImpl(this: v8, a2: (int *)&path, a3: v4, precision: -1, debug: false);
      GASEnvironment::FindTarget(
        this: (__vc_attributes::event_receiverAttribute *)a1[6],
        (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > ***)&path,
        excludeFlags: false);
      if ( v9 != nullptr )
        ++v9->RefCount;
      v36 = v9;
      v10 = path;
      v11 = (*(_DWORD *)(path + 8))-- == 1;
      if ( v11 )
        GASStringNode::ReleaseNode(a1: v10);
    }
    if ( v36 != nullptr )
    {
      v28 = *v37;
      v27 = v36;
      MovieRoot = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)a1[6]);
      GFxMovieRoot::AddLoadQueueEntry(
        this: (int)MovieRoot,
        a2: (GString)v27,
        a3: v28,
        a4: nullptr,
        pmovieClipLoader: (GPtr<IDirect3DVertexDeclaration9>)p_cxItem);
    }
    else
    {
      v13 = a1[6];
      v31 = &pMem;
      Version = GFxCharacter::GetVersion(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)v13[2].ptStart.y);
      v15 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
      LOBYTE(v32) = (unsigned int)Version > 6;
      v16 = (unsigned __int8 *)GASFnCall::Arg(this: a1, a2: 1);
      GASValue::ToStringImpl(this: v16, a2: &v34, a3: v15, precision: -1, debug: false);
      v17 = GFxMovieRoot::ParseLevelName(
              nptr: *(char **)v34,
              ptail: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&v31,
              caseSensitive: v32);
      v18 = v34;
      v11 = (*(_DWORD *)(v34 + 8))-- == 1;
      if ( v11 )
        GASStringNode::ReleaseNode(a1: v18);
      v19 = (int)v37;
      if ( v17 == -1 )
        goto LABEL_24;
      v4 = (tagRID_DEVICE_INFO_KEYBOARD *)*v37;
      v20 = (tagRID_DEVICE_INFO_KEYBOARD *)a1[6];
      v21 = (unsigned __int8 *)GASFnCall::Arg(this: a1, a2: 1);
      GASValue::ToStringImpl(this: v21, a2: (int *)&v33, a3: v20, precision: -1, debug: false);
      v29 = (GASEnvironment *)a1[6];
      v26 = *v33;
      v22 = (ScaleformRenderTarget_vtbl **)GASEnvironment::GetMovieRoot(this: v29);
      GFxMovieRoot::AddLoadQueueEntry(
        this: v22,
        a2: v26,
        a3: (char *)v4,
        a4: (GString)v29,
        a5: nullptr,
        pmovieClipLoader: (GPtr<IDirect3DVertexDeclaration9>)p_cxItem);
      v23 = (int)v33;
      v11 = (*((_DWORD *)v33 + 2))-- == 1;
      if ( v11 )
        GASStringNode::ReleaseNode(a1: v23);
    }
    v24 = a1[1];
    GASValue::DropRefs(this: (GASValue *)v24, a2: (int)v4);
    v25 = v36;
    LOBYTE(v24->cbSize) = 2;
    LOBYTE(v24->cItems) = 1;
    if ( v25 != nullptr )
      GRefCountNTSImpl::Release(this: v25);
    v19 = (int)v37;
LABEL_24:
    v11 = (*(_DWORD *)(v19 + 8))-- == 1;
    if ( v11 )
      GASStringNode::ReleaseNode(a1: v19);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111A80
// Name: public: static void GASMovieClipLoaderProto::UnloadClip(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASMovieClipLoaderProto::UnloadClip(
        long double a1@<st0>,
        __vc_attributes::event_receiverAttribute::type_e path)
{
  __vc_attributes::event_receiverAttribute::type_e v2; // esi
  int v3; // edi
  GASValue *v4; // eax
  struct GFxSprite *LevelMovie; // eax
  GRefCountNTSImpl *v6; // edi
  char v7; // al
  GASValue *v8; // eax
  GFxMovieRoot *MovieRoot; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v10; // edi
  unsigned __int8 *v11; // eax
  GRefCountNTSImpl *v12; // eax
  __vc_attributes::event_receiverAttribute::type_e v13; // eax
  struct GFxMovieRoot *v15; // eax
  int v16; // esi
  const struct GASEnvironment *v17; // [esp-4h] [ebp-10h]
  _SERVICE_STATUS *v18; // [esp-4h] [ebp-10h]
  int v19; // [esp-4h] [ebp-10h]

  v2 = path;
  v3 = *(_DWORD *)(path + 4);
  GASValue::DropRefs(this: (GASValue *)v3, a2: v3);
  *(_BYTE *)v3 = 2;
  *(_BYTE *)(v3 + 4) = 0;
  if ( *(int *)(v2 + 28) >= 1 )
  {
    if ( *(_BYTE *)GASFnCall::Arg(this: (GASFnCall *)v2, a2: 0) == 7 )
    {
      v17 = *(const struct GASEnvironment **)(v2 + 24);
      v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v2, a2: 0);
      GASValue::ToASCharacter(this: v4, penv: v17);
      if ( LevelMovie != nullptr )
      {
        ++*((_DWORD *)LevelMovie + 1);
        v6 = (GRefCountNTSImpl *)LevelMovie;
        goto LABEL_14;
      }
    }
    else
    {
      v7 = *(_BYTE *)GASFnCall::Arg(this: (GASFnCall *)v2, a2: 0);
      if ( v7 != 3 && v7 != 4 )
      {
        v10 = *(tagRID_DEVICE_INFO_KEYBOARD **)(v2 + 24);
        v11 = (unsigned __int8 *)GASFnCall::Arg(this: (GASFnCall *)v2, a2: 0);
        GASValue::ToStringImpl(this: v11, a2: (int *)&path, a3: v10, precision: -1, debug: false);
        GASEnvironment::FindTarget(
          this: *(__vc_attributes::event_receiverAttribute **)(v2 + 24),
          (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > ***)&path,
          excludeFlags: false);
        if ( v12 != nullptr )
          ++v12->RefCount;
        v6 = v12;
        v13 = path;
        if ( (*(_DWORD *)(path + 8))-- == 1 )
          GASStringNode::ReleaseNode(a1: v13);
        goto LABEL_14;
      }
      v18 = *(_SERVICE_STATUS **)(v2 + 24);
      v8 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v2, a2: 0);
      v19 = GASValue::ToInt32(this: v8, a2: v3, a3: a1, a4: v18);
      MovieRoot = (GFxMovieRoot *)GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(v2 + 24));
      LevelMovie = GFxMovieRoot::GetLevelMovie(this: MovieRoot, level: v19);
      if ( LevelMovie != nullptr )
        ++*((_DWORD *)LevelMovie + 1);
    }
    v6 = (GRefCountNTSImpl *)LevelMovie;
LABEL_14:
    if ( v6 != nullptr )
    {
      v15 = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(v2 + 24));
      GFxMovieRoot::AddLoadQueueEntry(
        this: (int)v15,
        a2: (GString)v6,
        a3: (char *)&pMem,
        a4: nullptr,
        pmovieClipLoader: 0);
      v16 = *(_DWORD *)(v2 + 4);
      GASValue::DropRefs(this: (GASValue *)v16, a2: (int)v6);
      *(_BYTE *)(v16 + 4) = 1;
      *(_BYTE *)v16 = 2;
      GRefCountNTSImpl::Release(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111CE0
// Name: public: static void GASMovieClipLoaderProto::GetProgress(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASMovieClipLoaderProto::GetProgress(GASFnCall *a1)
{
  GASFnCall *v1; // esi
  GASValue *v2; // edi
  GASFnCall v3; // ebx
  IClientRenderable *p_cxItem; // ebx
  int v5; // ecx
  int (__thiscall *v6)(int, int, GASFnCall **); // edx
  GASObject *v7; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v8; // edi
  unsigned __int8 *v9; // eax
  const QAngle *v10; // ebx
  void *v11; // edi
  GASFnCall *v12; // edi
  tagWNDCLASSW *v13; // eax
  tagWNDCLASSW *v14; // eax
  GASFnCall *v15; // edi
  int v16; // eax
  GASValue v18; // [esp+4h] [ebp-18h] BYREF
  float x; // [esp+8h] [ebp-14h]
  int *v20; // [esp+14h] [ebp-8h] BYREF
  GString v21; // [esp+18h] [ebp-4h] BYREF

  v1 = a1;
  if ( (int)a1[7] >= 1 )
  {
    v2 = (GASValue *)a1[1];
    GASValue::DropRefs(this: v2, a2: (int)v2);
    *(_BYTE *)v2 = 0;
    if ( (*(int (__thiscall **)(GASFnCall))(v1[2]->cbSize + 8))(a1: v1[2]) == 25 )
    {
      v3 = v1[2];
      if ( v3 != nullptr )
        p_cxItem = (IClientRenderable *)&v3[-1].cxItem;
      else
        p_cxItem = nullptr;
      v5 = *(_DWORD *)(v1[6][3].cbSize + 656);
      v6 = *(int (__thiscall **)(int, int, GASFnCall **))(*(_DWORD *)v5 + 40);
      a1 = (GASFnCall *)323;
      v7 = (GASObject *)v6(a1: v5, a2: 52, a3: &a1);
      if ( v7 != nullptr )
        a1 = (GASFnCall *)GASObject::GASObject(this: v7, a2: (struct GASEnvironment *)v1[6]);
      else
        a1 = nullptr;
      v8 = (tagRID_DEVICE_INFO_KEYBOARD *)v1[6];
      v9 = (unsigned __int8 *)GASFnCall::Arg(this: v1, a2: 0);
      GASValue::ToStringImpl(this: v9, a2: (int *)&v20, a3: v8, precision: -1, debug: false);
      GString::GString(this: &v21, src: *v20);
      v10 = GStringHashLH<GASMovieClipLoader::ProgressDesc,2,GString::NoCaseHashFunctor,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>,GHashsetCachedNodeEntry<GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeHashF>>::Get(
              this: p_cxItem + 13,
              a2: &v21);
      v11 = (void *)(v21.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v21.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
      if ( v10 != nullptr )
      {
        v12 = a1;
        v13 = (tagWNDCLASSW *)&v1[6][3];
        x = v10->x;
        LOBYTE(v18) = 4;
        GASObjectInterface::SetConstMemberRaw(
          this: a1 + 4,
          result: v13,
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"bytesLoaded",
          a4: (int)&v18);
        GASValue::~GASValue(this: &v18, a2: (int)v12);
        v14 = (tagWNDCLASSW *)&v1[6][3];
        x = v10->y;
        LOBYTE(v18) = 4;
        GASObjectInterface::SetConstMemberRaw(
          this: v12 + 4,
          result: v14,
          a3: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"bytesTotal",
          a4: (int)&v18);
        GASValue::~GASValue(this: &v18, a2: (int)v12);
      }
      v15 = a1;
      GASValue::SetAsObject(this: (GASValue *)v1[1], a2: (struct GASObject *)a1);
      v16 = (int)v20;
      if ( v20[2]-- == 1 )
        GASStringNode::ReleaseNode(a1: v16);
      if ( v15 != nullptr )
        GRefCountBaseGC<323>::Release(a1: (int)v15, a2: (int)v15);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111FF0
// Name: public: virtual void GASMovieClipLoader::NotifyOnLoadStart(class GASEnvironment __near *,class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMovieClipLoader::NotifyOnLoadStart(
        GASMovieClipLoader *this,
        __vc_attributes::iid_isAttribute *a2,
        tagAXISINFOA *result)
{
  char *limited_expression; // ecx
  int v6; // edi
  struct GFxASCharacter *v7; // eax
  float *fDecayExponentBase; // [esp+14h] [ebp+8h]

  a2[2].limited_expression += 16;
  if ( a2[2].limited_expression >= a2[4].limited_expression )
    GASPagedStack<GASValue,32>::PushPage(this: a2 + 2);
  limited_expression = (char *)a2[2].limited_expression;
  if ( limited_expression != nullptr )
    GASValue::GASValue(this: limited_expression, result);
  if ( this != nullptr )
    fDecayExponentBase = this->fDecayExponentBase;
  else
    fDecayExponentBase = nullptr;
  v6 = ((a2[2].limited_expression - a2[3].limited_expression) >> 4) + 32 * (int)a2[7].limited_expression - 32;
  result = (tagAXISINFOA *)GASStringManager::CreateConstStringNode(
                             this: *((GASStringManager **)a2[30].limited_expression + 159),
                             result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A4008.m_Size,
                             a3: 0xBu,
                             a4: 0);
  ++*(_DWORD *)result->axAxisName;
  GASAsBroadcaster::BroadcastMessage(
    a1: (struct GASEnvironment *)a2,
    eventName: (_IMAGE_SYMBOL_EX *)fDecayExponentBase,
    a3: (const struct GASString *)&result,
    nArgs: 1,
    firstArgBottomIndex: v6);
  v7 = (struct GFxASCharacter *)result;
  if ( (*(_DWORD *)result->axAxisName)-- == 1 )
    GASStringNode::ReleaseNode(a1: (int)v7);
  GASValue::~GASValue(this: (GASValue *)a2[2].limited_expression, a2: v6);
  a2[2].limited_expression -= 16;
  if ( a2[2].limited_expression < a2[3].limited_expression )
    GASPagedStack<GASValue,32>::PopPage(this: a2 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x101120B0
// Name: public: virtual void GASMovieClipLoader::NotifyOnLoadInit(class GASEnvironment __near *,class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMovieClipLoader::NotifyOnLoadInit(
        GASMovieClipLoader *this,
        __vc_attributes::iid_isAttribute *a2,
        tagAXISINFOA *result)
{
  char *limited_expression; // ecx
  int v6; // edi
  struct GFxASCharacter *v7; // eax
  float *fDecayExponentBase; // [esp+14h] [ebp+8h]

  a2[2].limited_expression += 16;
  if ( a2[2].limited_expression >= a2[4].limited_expression )
    GASPagedStack<GASValue,32>::PushPage(this: a2 + 2);
  limited_expression = (char *)a2[2].limited_expression;
  if ( limited_expression != nullptr )
    GASValue::GASValue(this: limited_expression, result);
  if ( this != nullptr )
    fDecayExponentBase = this->fDecayExponentBase;
  else
    fDecayExponentBase = nullptr;
  v6 = ((a2[2].limited_expression - a2[3].limited_expression) >> 4) + 32 * (int)a2[7].limited_expression - 32;
  result = (tagAXISINFOA *)GASStringManager::CreateConstStringNode(
                             this: *((GASStringManager **)a2[30].limited_expression + 159),
                             result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A3FEC,
                             a3: 0xAu,
                             a4: 0);
  ++*(_DWORD *)result->axAxisName;
  GASAsBroadcaster::BroadcastMessage(
    a1: (struct GASEnvironment *)a2,
    eventName: (_IMAGE_SYMBOL_EX *)fDecayExponentBase,
    a3: (const struct GASString *)&result,
    nArgs: 1,
    firstArgBottomIndex: v6);
  v7 = (struct GFxASCharacter *)result;
  if ( (*(_DWORD *)result->axAxisName)-- == 1 )
    GASStringNode::ReleaseNode(a1: (int)v7);
  GASValue::~GASValue(this: (GASValue *)a2[2].limited_expression, a2: v6);
  a2[2].limited_expression -= 16;
  if ( a2[2].limited_expression < a2[3].limited_expression )
    GASPagedStack<GASValue,32>::PopPage(this: a2 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x101122F0
// Name: public: virtual void GASMovieClipLoader::NotifyOnLoadComplete(class GASEnvironment __near *,class GFxASCharacter __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMovieClipLoader::NotifyOnLoadComplete(
        char *this,
        CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(float),float,CFuncMemPolicyNone> *result,
        tagAXISINFOA *a3,
        int status)
{
  int v6; // eax
  int v7; // ecx
  _DWORD *v8; // ecx
  int v9; // edi
  int v10; // eax
  GASValue *v12; // ecx
  int i; // edi
  _IMAGE_SYMBOL_EX *v14; // [esp+14h] [ebp+8h]

  DWORD2(result->m_pfnProxied) += 16;
  if ( (CMaterialVar *)DWORD2(result->m_pfnProxied) >= result->m_pObject )
    GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)&result->m_pfnProxied + 2);
  v6 = DWORD2(result->m_pfnProxied);
  if ( v6 != 0 )
  {
    v7 = status;
    *(_BYTE *)v6 = 4;
    *(_DWORD *)(v6 + 4) = v7;
  }
  DWORD2(result->m_pfnProxied) += 16;
  if ( (CMaterialVar *)DWORD2(result->m_pfnProxied) >= result->m_pObject )
    GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)&result->m_pfnProxied + 2);
  v8 = (_DWORD *)DWORD2(result->m_pfnProxied);
  if ( v8 != nullptr )
    GASValue::GASValue(this: v8, result: a3);
  if ( this != nullptr )
    v14 = (_IMAGE_SYMBOL_EX *)(this + 16);
  else
    v14 = nullptr;
  v9 = ((DWORD2(result->m_pfnProxied) - HIDWORD(result->m_pfnProxied)) >> 4) + 32 * DWORD1(result[1].m_pfnProxied) - 32;
  status = (int)GASStringManager::CreateConstStringNode(
                  this: *(GASStringManager **)(LODWORD(result[5].m_pfnProxied) + 636),
                  result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A4FB4,
                  a3: 0xEu,
                  a4: 0);
  ++*(_DWORD *)(status + 8);
  GASAsBroadcaster::BroadcastMessage(
    a1: (struct GASEnvironment *)result,
    eventName: v14,
    a3: (const struct GASString *)&status,
    nArgs: 2,
    firstArgBottomIndex: v9);
  v10 = status;
  if ( (*(_DWORD *)(status + 8))-- == 1 )
    GASStringNode::ReleaseNode(a1: v10);
  v12 = (GASValue *)DWORD2(result->m_pfnProxied);
  if ( (unsigned int)(v12 - 8) >= HIDWORD(result->m_pfnProxied) )
  {
    GASValue::~GASValue(this: v12, a2: v9);
    DWORD2(result->m_pfnProxied) -= 16;
    GASValue::~GASValue(this: (GASValue *)DWORD2(result->m_pfnProxied), a2: v9);
    DWORD2(result->m_pfnProxied) -= 16;
  }
  else
  {
    for ( i = 2; i != 0; --i )
    {
      GASValue::~GASValue(this: (GASValue *)DWORD2(result->m_pfnProxied), a2: i);
      DWORD2(result->m_pfnProxied) -= 16;
      if ( DWORD2(result->m_pfnProxied) < HIDWORD(result->m_pfnProxied) )
        GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)&result->m_pfnProxied + 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112410
// Name: public: virtual void GASMovieClipLoader::NotifyOnLoadError(class GASEnvironment __near *,class GFxASCharacter __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMovieClipLoader::NotifyOnLoadError(
        GASMovieClipLoader *this,
        __vc_attributes::iid_isAttribute *a2,
        tagAXISINFOA *result,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *a4,
        struct GASStringNode *a5)
{
  __vc_attributes::iid_isAttribute *v5; // esi
  __vc_attributes::iid_isAttribute v6; // eax
  struct GASStringNode *v7; // ecx
  struct GASStringNode *ConstStringNode; // edi
  __vc_attributes::iid_isAttribute v9; // eax
  bool v10; // zf
  float *fDecayExponentBase; // ebx
  int v12; // edi
  int v13; // eax

  a2[2].limited_expression += 16;
  v5 = a2 + 2;
  if ( a2[2].limited_expression >= a2[4].limited_expression )
    GASPagedStack<GASValue,32>::PushPage(this: a2 + 2);
  v6.limited_expression = v5->limited_expression;
  if ( v5->limited_expression != nullptr )
  {
    v7 = a5;
    *v6.limited_expression = 4;
    *((_DWORD *)v6.limited_expression + 1) = v7;
  }
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *((GASStringManager **)a2[30].limited_expression + 159),
                      result: a4,
                      a3: strlen((const char *)a4),
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  v5->limited_expression += 16;
  if ( a2[2].limited_expression >= a2[4].limited_expression )
    GASPagedStack<GASValue,32>::PushPage(this: v5);
  v9.limited_expression = v5->limited_expression;
  if ( v5->limited_expression != nullptr )
  {
    *v9.limited_expression = 5;
    *((_DWORD *)v9.limited_expression + 1) = ConstStringNode;
    ++*((_DWORD *)ConstStringNode + 2);
  }
  v10 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: (int)ConstStringNode);
  v5->limited_expression += 16;
  if ( a2[2].limited_expression >= a2[4].limited_expression )
    GASPagedStack<GASValue,32>::PushPage(this: v5);
  if ( v5->limited_expression != nullptr )
    GASValue::GASValue(this: v5->limited_expression, result);
  if ( this != nullptr )
    fDecayExponentBase = this->fDecayExponentBase;
  else
    fDecayExponentBase = nullptr;
  v12 = ((a2[2].limited_expression - a2[3].limited_expression) >> 4) + 32 * (int)a2[7].limited_expression - 32;
  a5 = GASStringManager::CreateConstStringNode(
         this: *((GASStringManager **)a2[30].limited_expression + 159),
         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A4008,
         a3: 0xBu,
         a4: 0);
  ++*((_DWORD *)a5 + 2);
  GASAsBroadcaster::BroadcastMessage(
    a1: (struct GASEnvironment *)a2,
    eventName: (_IMAGE_SYMBOL_EX *)fDecayExponentBase,
    a3: (const struct GASString *)&a5,
    nArgs: 3,
    firstArgBottomIndex: v12);
  v13 = (int)a5;
  v10 = (*((_DWORD *)a5 + 2))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v13);
  GASPagedStack<GASValue,32>::Pop3(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101126D0
// Name: public: virtual class GASObject __near * GASMovieClipLoaderCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10112940
// Name: public: virtual void GASMovieClipLoader::NotifyOnLoadProgress(class GASEnvironment __near *,class GFxASCharacter __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMovieClipLoader::NotifyOnLoadProgress(
        CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(float),float,CFuncMemPolicyNone> *this,
        float *penv,
        tagAXISINFOA *result,
        int loadedBytes,
        int totalBytes)
{
  int v5; // ebx
  int v7; // edi
  IClientRenderable *v8; // esi
  QAngle *v9; // eax
  int v10; // eax
  void *v11; // esi
  __vc_attributes::iid_isAttribute *v12; // esi
  __vc_attributes::iid_isAttribute v13; // eax
  __vc_attributes::iid_isAttribute v14; // eax
  _IMAGE_SYMBOL_EX *p_m_pObject; // ebx
  int v16; // edi
  tagAXISINFOA *v17; // eax
  unsigned int v19; // [esp-8h] [ebp-28h]
  _DWORD v20[2]; // [esp+Ch] [ebp-14h] BYREF
  _DWORD v21[2]; // [esp+14h] [ebp-Ch] BYREF
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(float),float,CFuncMemPolicyNone> *v22; // [esp+1Ch] [ebp-4h]

  v5 = loadedBytes;
  v7 = totalBytes;
  v22 = this;
  if ( result != nullptr )
  {
    GString::GString(this: (CUtlMemory<CImagePacker,int> *)&totalBytes);
    GFxASCharacter::GetAbsolutePath(
      this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)result,
      a2: (CUtlMemory<CImagePacker,int> *)&totalBytes);
    v8 = (IClientRenderable *)((char *)this + 52);
    v9 = (QAngle *)GStringHashLH<GASMovieClipLoader::ProgressDesc,2,GString::NoCaseHashFunctor,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>,GHashsetCachedNodeEntry<GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeHashF>>::Get(
                     this: v8,
                     a2: &totalBytes);
    if ( v9 != nullptr )
    {
      LODWORD(v9->x) = v5;
      LODWORD(v9->y) = v7;
    }
    else
    {
      v20[1] = v21;
      v21[0] = v5;
      v21[1] = v7;
      v19 = *(_DWORD *)(totalBytes & 0xFFFFFFFC) & 0x7FFFFFFF;
      v20[0] = &totalBytes;
      v10 = GString::BernsteinHashFunctionCIS(
              result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((totalBytes & 0xFFFFFFFC)
                                                                                             + 8),
              size: v19,
              seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505);
      GHashSetBase<GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<GASMovieClipLoader::ProgressDesc,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeHashF>>::add<GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeRef>(
        this: (void **)&v8->__vftable,
        a2: (GWeakPtrProxy *)v8,
        a3: (int)v20,
        a4: v10);
    }
    v11 = (void *)(totalBytes & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((totalBytes & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
  }
  *((_DWORD *)penv + 2) += 16;
  v12 = (__vc_attributes::iid_isAttribute *)(penv + 2);
  if ( *((_DWORD *)penv + 2) >= *((_DWORD *)penv + 4) )
    GASPagedStack<GASValue,32>::PushPage(this: v12);
  v13.limited_expression = v12->limited_expression;
  if ( v12->limited_expression != nullptr )
  {
    *v13.limited_expression = 4;
    *((_DWORD *)v13.limited_expression + 1) = v7;
  }
  v12->limited_expression += 16;
  if ( *((_DWORD *)penv + 2) >= *((_DWORD *)penv + 4) )
    GASPagedStack<GASValue,32>::PushPage(this: v12);
  v14.limited_expression = v12->limited_expression;
  if ( v12->limited_expression != nullptr )
  {
    *v14.limited_expression = 4;
    *((_DWORD *)v14.limited_expression + 1) = v5;
  }
  v12->limited_expression += 16;
  if ( *((_DWORD *)penv + 2) >= *((_DWORD *)penv + 4) )
    GASPagedStack<GASValue,32>::PushPage(this: v12);
  if ( v12->limited_expression != nullptr )
    GASValue::GASValue(this: v12->limited_expression, result);
  if ( v22 != nullptr )
    p_m_pObject = (_IMAGE_SYMBOL_EX *)&v22->m_pObject;
  else
    p_m_pObject = nullptr;
  v16 = ((*((_DWORD *)penv + 2) - *((_DWORD *)penv + 3)) >> 4) + 32 * *((_DWORD *)penv + 7) - 32;
  result = (tagAXISINFOA *)GASStringManager::CreateConstStringNode(
                             this: *(GASStringManager **)(*((_DWORD *)penv + 30) + 636),
                             result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A3FEC.m_Size,
                             a3: 0xEu,
                             a4: 0);
  ++*(_DWORD *)result->axAxisName;
  GASAsBroadcaster::BroadcastMessage(
    a1: (struct GASEnvironment *)penv,
    eventName: p_m_pObject,
    a3: (const struct GASString *)&result,
    nArgs: 3,
    firstArgBottomIndex: v16);
  v17 = result;
  if ( (*(_DWORD *)result->axAxisName)-- == 1 )
    GASStringNode::ReleaseNode(a1: (int)v17);
  GASPagedStack<GASValue,32>::Pop3(this: v12);
}

//------------------------------------------------------------------------------
// Address: 0x10112B20
// Name: public: static class GASFunctionRef GASMovieClipLoaderCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__cdecl GASMovieClipLoaderCtorFunction::Register(
        struct GASFunctionRef *a1,
        _KCRM_MARSHAL_HEADER *pgc)
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
  int v11; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GASValue *v13; // eax
  int p_MinVal; // edi
  GASValue v16[4]; // [esp+Ch] [ebp-20h] BYREF
  _KCRM_MARSHAL_HEADER *psc; // [esp+1Ch] [ebp-10h] BYREF
  char v18; // [esp+20h] [ebp-Ch]
  void (__thiscall **v19)(_DWORD *, _KCRM_MARSHAL_HEADER **, int, GASValue *, char *); // [esp+24h] [ebp-8h]
  _DWORD *v20; // [esp+28h] [ebp-4h]

  v2 = (vc_attributes::PreRangeAttribute *)pgc;
  VersionMajor = pgc[41].VersionMajor;
  psc = pgc;
  v18 = 8;
  v4 = *(int (__thiscall **)(unsigned int, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)VersionMajor + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v5 = (GASCFunctionObject *)v4(a1: VersionMajor, a2: 56, a3: &pgc);
  v6 = v5;
  if ( v5 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v5,
      func: (_REASON_CONTEXT *)&psc,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASMovieClipLoaderCtorFunction::GlobalCtor);
    v6->dwSize = (unsigned int)&GASMovieClipLoaderCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
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
  v11 = v10(a1: MaxVal, a2: 88, a3: &a1);
  if ( v11 != 0 )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v2,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASMovieClipLoader,GASEnvironment>::GASPrototype<GASMovieClipLoader,GASEnvironment>(
      this: (GRenderer *)v11,
      (struct GASStringContext *)&psc,
      psc_4: Prototype,
      psc_8: (unsigned int)v8);
    *(_DWORD *)v11 = &GASMovieClipLoaderProto::`vftable'{for `GASRefCountBase<GASObject>'};
    *(_DWORD *)(v11 + 16) = &GASPrototype<GASMovieClipLoader,GASEnvironment>::`vftable'{for `GASObjectInterface'};
    *(_DWORD *)(v11 + 56) = &GASPrototype<GASMovieClipLoader,GASEnvironment>::`vftable';
    HIBYTE(pgc) = 1;
    GASPrototypeBase::InitFunctionMembers(
      this: (GASPrototypeBase *)(v11 + 56),
      a2: v11,
      flags: (vc_attributes::PreRangeAttribute **)&psc,
      flags_4: (const struct GASNameFunction *)&GAS_MovieClipLoaderFuncTable,
      flags_8: (const struct GASPropFlags *)((char *)&pgc + 3));
  }
  else
  {
    v11 = 0;
  }
  if ( v11 != 0 )
    *(_DWORD *)(v11 + 8) = (*(_DWORD *)(v11 + 8) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)v2, a3: 29, a4: v11);
  v20 = v2[56].MaxVal + 16;
  HIBYTE(pgc) = 0;
  v19 = (void (__thiscall **)(_DWORD *, _KCRM_MARSHAL_HEADER **, int, GASValue *, char *))(*v20 + 40);
  v13 = GASValue::GASValue(this: v16, a2: (int)v2, a3: v8);
  p_MinVal = (int)&v2[10].MinVal;
  (*v19)(a1: v20, a2: &psc, a3: p_MinVal, a4: v13, a5: (char *)&pgc + 3);
  GASValue::~GASValue(this: v16, a2: p_MinVal);
  if ( v11 != 0 )
    GRefCountBaseGC<323>::Release(a1: v11, a2: p_MinVal);
  return v8;
}
