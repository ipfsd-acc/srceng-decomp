// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxfontlib.cpp
// Functions: 12
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxfontlib.h"

//------------------------------------------------------------------------------
// Address: 0x1006DB30
// Name: public: GFxFontLib::FontResult::~FontResult(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontLib::FontResult::~FontResult(GFxFontLib::FontResult *this)
{
  IShaderDevice *pMovieDef; // ecx
  IShaderDevice *pFontResource; // ecx

  pMovieDef = (IShaderDevice *)this->pMovieDef;
  if ( pMovieDef != nullptr )
    GFxResource::Release(this: pMovieDef);
  pFontResource = (IShaderDevice *)this->pFontResource;
  if ( pFontResource != nullptr )
    GFxResource::Release(this: pFontResource);
}

//------------------------------------------------------------------------------
// Address: 0x1006DB50
// Name: public: void GFxMovieDataDef::WaitForLoadFinish(bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::WaitForLoadFinish(GFxMovieDataDef *this, bool a2)
{
  if ( a2 )
    GFxMovieDataDef::LoadTaskData::OnMovieDataDefRelease(this: *((GFxMovieDataDef::LoadTaskData **)this + 8));
  GFxMovieDataDef::LoadTaskData::WaitForLoadFinish(this: *((GFxMovieDataDef::LoadTaskData **)this + 8));
}

//------------------------------------------------------------------------------
// Address: 0x1006DB80
// Name: public: void GFxResourceBinding::GetResourceData(struct GFxResourceBindData __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxResourceBinding::GetResourceData(GFxResourceBinding *this, IShaderDevice **a2, unsigned int a3)
{
  const char *v3; // esi

  if ( this->m_Identifier[20] != 0 && a3 < *(_DWORD *)&this->m_CurToken )
  {
    v3 = &this->m_pExpression[8 * a3];
    if ( *(_DWORD *)v3 != 0 )
      GRefCountImpl::AddRef(this: *(IShaderDevice **)v3);
    if ( *a2 != nullptr )
      GFxResource::Release(this: *a2);
    *a2 = *(IShaderDevice **)v3;
    a2[1] = *((IShaderDevice **)v3 + 1);
  }
  else
  {
    GFxResourceBinding::GetResourceData_Locked(this, (struct GFxResourceBindData *)a2, a3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006DC60
// Name: public: GFxMovieDefBindStates::GFxMovieDefBindStates(class GFxStateBag __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieDefBindStates::GFxMovieDefBindStates(
        CReferenceToHandleTexture *this@<ecx>,
        Sampler_t psharedState,
        TextureBindFlags_t pstates)
{
  void (__thiscall *v4)(Sampler_t, int *, void *(__thiscall *)(CTexture *, unsigned int), int); // eax
  IShaderAPI *m_hTexture; // ecx
  int v6; // ebx
  IShaderAPI *m_nRefCount; // ecx
  int v8; // ebx
  IShaderAPI *v9; // ecx
  int v10; // ebx
  IShaderAPI *v11; // ecx
  int v12; // ebx
  IShaderAPI *v13; // ecx
  int v14; // ebx
  IShaderAPI *v15; // ecx
  int v16; // ebx
  IShaderAPI *v17; // ecx
  int v18; // ebx
  IShaderAPI *v19; // ecx
  int v20; // ebx
  IShaderAPI *v21; // ecx
  int v22; // ebx
  int v23; // [esp+Ch] [ebp-24h] BYREF
  int v24; // [esp+10h] [ebp-20h]
  int v25; // [esp+14h] [ebp-1Ch]
  int v26; // [esp+18h] [ebp-18h]
  int v27; // [esp+1Ch] [ebp-14h]
  int v28; // [esp+20h] [ebp-10h]
  int v29; // [esp+24h] [ebp-Ch]
  int v30; // [esp+28h] [ebp-8h]
  int v31; // [esp+2Ch] [ebp-4h]

  this->__vftable = (CReferenceToHandleTexture_vtbl *)&GRefCountImplCore::`vftable';
  *(_DWORD *)&this->m_Name.m_Id = 1;
  this->__vftable = (CReferenceToHandleTexture_vtbl *)&GFxMovieDefBindStates::`vftable';
  this->m_hTexture = 0;
  this->m_nRefCount = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  v4 = *(void (__thiscall **)(Sampler_t, int *, void *(__thiscall *)(CTexture *, unsigned int), int))(*(_DWORD *)psharedState + 16);
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v4(a1: psharedState, a2: &v23, a3: `GFxMovieDefBindStates::GFxMovieDefBindStates'::`2'::stateQuery, a4: 9);
  m_hTexture = (IShaderAPI *)this->m_hTexture;
  v6 = v23;
  if ( m_hTexture != nullptr )
    GRefCountImpl::Release(this: m_hTexture);
  this->m_hTexture = v6;
  m_nRefCount = (IShaderAPI *)this->m_nRefCount;
  v8 = v24;
  if ( m_nRefCount != nullptr )
    GRefCountImpl::Release(this: m_nRefCount);
  this->m_nRefCount = v8;
  v9 = *((IShaderAPI **)this + 4);
  v10 = v25;
  if ( v9 != nullptr )
    GRefCountImpl::Release(this: v9);
  *((_DWORD *)this + 4) = v10;
  v11 = *((IShaderAPI **)this + 5);
  v12 = v26;
  if ( v11 != nullptr )
    GRefCountImpl::Release(this: v11);
  *((_DWORD *)this + 5) = v12;
  v13 = *((IShaderAPI **)this + 6);
  v14 = v27;
  if ( v13 != nullptr )
    GRefCountImpl::Release(this: v13);
  *((_DWORD *)this + 6) = v14;
  v15 = *((IShaderAPI **)this + 7);
  v16 = v28;
  if ( v15 != nullptr )
    GRefCountImpl::Release(this: v15);
  *((_DWORD *)this + 7) = v16;
  v17 = *((IShaderAPI **)this + 8);
  v18 = v29;
  if ( v17 != nullptr )
    GRefCountImpl::Release(this: v17);
  *((_DWORD *)this + 8) = v18;
  v19 = *((IShaderAPI **)this + 9);
  v20 = v30;
  if ( v19 != nullptr )
    GRefCountImpl::Release(this: v19);
  *((_DWORD *)this + 9) = v20;
  v21 = *((IShaderAPI **)this + 10);
  v22 = v31;
  if ( v21 != nullptr )
    GRefCountImpl::Release(this: v21);
  *((_DWORD *)this + 10) = v22;
}

//------------------------------------------------------------------------------
// Address: 0x1006DD80
// Name: public: virtual GFxMovieDefBindStates::~GFxMovieDefBindStates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDefBindStates::~GFxMovieDefBindStates(CReferenceToHandleTexture *this)
{
  IShaderAPI *v2; // ecx
  IShaderAPI *v3; // ecx
  IShaderAPI *v4; // ecx
  IShaderAPI *v5; // ecx
  IShaderAPI *v6; // ecx
  IShaderAPI *v7; // ecx
  IShaderAPI *v8; // ecx
  IShaderAPI *m_nRefCount; // ecx
  IShaderAPI *m_hTexture; // ecx

  v2 = *((IShaderAPI **)this + 10);
  if ( v2 != nullptr )
    GRefCountImpl::Release(this: v2);
  v3 = *((IShaderAPI **)this + 9);
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  v4 = *((IShaderAPI **)this + 8);
  if ( v4 != nullptr )
    GRefCountImpl::Release(this: v4);
  v5 = *((IShaderAPI **)this + 7);
  if ( v5 != nullptr )
    GRefCountImpl::Release(this: v5);
  v6 = *((IShaderAPI **)this + 6);
  if ( v6 != nullptr )
    GRefCountImpl::Release(this: v6);
  v7 = *((IShaderAPI **)this + 5);
  if ( v7 != nullptr )
    GRefCountImpl::Release(this: v7);
  v8 = *((IShaderAPI **)this + 4);
  if ( v8 != nullptr )
    GRefCountImpl::Release(this: v8);
  m_nRefCount = (IShaderAPI *)this->m_nRefCount;
  if ( m_nRefCount != nullptr )
    GRefCountImpl::Release(this: m_nRefCount);
  m_hTexture = (IShaderAPI *)this->m_hTexture;
  if ( m_hTexture != nullptr )
    GRefCountImpl::Release(this: m_hTexture);
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1006DE30
// Name: public: virtual bool GFxFontLib::FindFont(class GFxFontLib::FontResult __near *,char const __near *,unsigned int,class GFxMovieDef __near *,class GFxStateBag __near *,class GFxResourceWeakLib __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GFxFontLib::FindFont@<al>(
        int a1@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        IRecordInfo *this,
        char *a5,
        __int16 fontFlags,
        int a7,
        struct GFxStateBag *psharedState,
        int a9)
{
  _DWORD *v9; // eax
  __int16 v10; // bx
  IShaderAPI *v12; // esi
  GFxMovieDataDef::LoadTaskData *v13; // ecx
  bool (__thiscall *ShouldWriteDepthToDestAlpha)(struct IShaderAPI *); // edi
  int v15; // esi
  int v16; // ebx
  _DWORD *v17; // ecx
  const char *v18; // eax
  GFxLoadStates *v19; // eax
  tagNEWTEXTMETRICA *States; // esi
  IShaderDevice *Movie_LoadState; // edi
  IShaderAPI *v22; // eax
  struct GFxStateBag v23; // edx
  IShaderAPI *v24; // eax
  struct GFxStateBag v25; // edx
  CReferenceToHandleTexture *v26; // eax
  struct GFxMovieDefBindStates *v27; // eax
  struct GFxMovieDefBindStates *v28; // ebx
  GFxLoadStates *v29; // eax
  tagNEWTEXTMETRICA *v30; // esi
  IShaderDevice_vtbl *v31; // ecx
  char SetView; // al
  bool (__thiscall **p_IsUsingGraphics)(IShaderDevice *); // ecx
  unsigned int v34; // esi
  IShaderDevice *v35; // ebx
  IShaderDevice *v36; // ecx
  IShaderDevice *v37; // ecx
  VMatrix *v40; // [esp+0h] [ebp-48h]
  TextureBindFlags_t v41; // [esp+0h] [ebp-48h]
  char v42; // [esp+4h] [ebp-44h] BYREF
  struct GFxLoaderImpl *v43; // [esp+8h] [ebp-40h]
  _ENUM_SERVICE_STATUSA *rbd; // [esp+14h] [ebp-34h] BYREF
  int v45; // [esp+18h] [ebp-30h]
  int v46; // [esp+1Ch] [ebp-2Ch] BYREF
  int v47; // [esp+20h] [ebp-28h] BYREF
  int v48; // [esp+24h] [ebp-24h] BYREF
  int v49; // [esp+28h] [ebp-20h]
  IShaderAPI *v50; // [esp+2Ch] [ebp-1Ch]
  IShaderAPI *v51; // [esp+30h] [ebp-18h]
  IShaderAPI *v52; // [esp+34h] [ebp-14h] BYREF
  unsigned int fontBindIndex; // [esp+38h] [ebp-10h]
  IShaderAPI *v54; // [esp+3Ch] [ebp-Ch]
  unsigned int i; // [esp+40h] [ebp-8h]
  bool fontFound; // [esp+47h] [ebp-1h]
  __int16 fontFlagsa; // [esp+58h] [ebp+10h]

  v9 = *(_DWORD **)(a1 + 12);
  v49 = a1;
  v10 = fontFlags & 0x313;
  fontFlagsa = fontFlags & 0x313;
  if ( v9 == nullptr )
    return 0;
  fontBindIndex = 0;
  v54 = nullptr;
  fontFound = false;
  i = 0;
  if ( v9[1] == 0 )
    return 0;
  while ( !fontFound )
  {
    v12 = *(IShaderAPI **)(*v9 + 4 * i);
    v13 = (GFxMovieDataDef::LoadTaskData *)v12[8].__vftable;
    v54 = v12;
    GFxMovieDataDef::LoadTaskData::WaitForLoadFinish(this: v13);
    ShouldWriteDepthToDestAlpha = v12[8].ShouldWriteDepthToDestAlpha;
    if ( ShouldWriteDepthToDestAlpha != nullptr )
    {
      v15 = v10 & 0x10 | ((v10 & 0x300) != 0 ? 0x300 : 0) | 3;
      v16 = v10 & 0x313;
      while ( 1 )
      {
        v17 = *((_DWORD **)ShouldWriteDepthToDestAlpha + 1);
        if ( (v15 & v17[5]) == v16 )
        {
          v18 = (const char *)(*(int (__thiscall **)(_DWORD *))(*v17 + 60))(a1: v17);
          if ( GString::CompareNoCase(a1: v18, a2: a5) == 0 )
            break;
        }
        ShouldWriteDepthToDestAlpha = *((bool (__thiscall **)(struct IShaderAPI *))ShouldWriteDepthToDestAlpha + 3);
        if ( ShouldWriteDepthToDestAlpha == nullptr )
          goto LABEL_12;
      }
      fontBindIndex = *((_DWORD *)ShouldWriteDepthToDestAlpha + 2);
      fontFound = true;
LABEL_12:
      v10 = fontFlagsa;
    }
    v9 = *(_DWORD **)(v49 + 12);
    if ( ++i >= v9[1] )
    {
      if ( !fontFound )
        return 0;
      break;
    }
  }
  if ( a7 != 0 )
  {
    v48 = 2;
    v19 = (GFxLoadStates *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 84, a3: &v48);
    if ( v19 != nullptr )
      States = (tagNEWTEXTMETRICA *)GFxLoadStates::GFxLoadStates(
                                      this: v19,
                                      a2: *(struct GFxLoaderImpl **)(a7 + 20),
                                      a3: psharedState,
                                      a4: *(struct GFxMovieDefBindStates **)(a7 + 24));
    else
      States = nullptr;
    Movie_LoadState = GFxLoaderImpl::CreateMovie_LoadState(
                        result: States,
                        a2: v54,
                        a3: *(_DWORD *)(*(_DWORD *)(a7 + 28) + 20) | 1,
                        memoryArena: 0);
    if ( States != nullptr )
      GRefCountImpl::Release(this: (IShaderAPI *)States);
  }
  else
  {
    if ( a9 == 0 )
      return 0;
    v22 = (IShaderAPI *)((int (__thiscall *)(struct GFxStateBag *, int, int, int))psharedState->GetStateAddRef)(
                          a1: psharedState,
                          a2: 29,
                          a3: a2,
                          a4: a3);
    v23.__vftable = psharedState->__vftable;
    v50 = v22;
    v24 = (IShaderAPI *)v23.GetStateAddRef(this: psharedState, a2: State_ZlibSupport);
    v25.__vftable = psharedState->__vftable;
    v51 = v24;
    v52 = (IShaderAPI *)v25.GetStateAddRef(this: psharedState, a2: State_FileOpener);
    GFxLoader::GFxLoader(this: (CMatRenderContextBase *)&v42, pfileOpener: (const matrix3x4_t *)&v52);
    if ( v52 != nullptr )
      GRefCountImpl::Release(this: v52);
    if ( v51 != nullptr )
      GRefCountImpl::Release(this: v51);
    if ( v50 != nullptr )
      GRefCountImpl::Release(this: v50);
    GFxLoader::SetResourceLib(this: (CMatRenderContextBase *)&v42, plib: *(MaterialMatrixMode_t *)(a9 + 8), a3: v40);
    v47 = 2;
    v26 = (CReferenceToHandleTexture *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 44, a3: &v47);
    if ( v26 != nullptr )
    {
      GFxMovieDefBindStates::GFxMovieDefBindStates(this: v26, (Sampler_t)psharedState, pstates: v41);
      v28 = v27;
    }
    else
    {
      v28 = nullptr;
    }
    v46 = 2;
    v29 = (GFxLoadStates *)((int (__thiscall *)(GMemoryHeap *))GMemory::pGlobalHeap->Alloc_2)(a1: GMemory::pGlobalHeap);
    if ( v29 != nullptr )
      v30 = (tagNEWTEXTMETRICA *)GFxLoadStates::GFxLoadStates(this: v29, a2: v43, a3: psharedState, a4: v28);
    else
      v30 = nullptr;
    Movie_LoadState = GFxLoaderImpl::CreateMovie_LoadState(result: v30, a2: v54, a3: 1u, memoryArena: 0);
    if ( v30 != nullptr )
      GRefCountImpl::Release(this: (IShaderAPI *)v30);
    if ( v28 != nullptr )
      GRefCountImpl::Release(this: (IShaderAPI *)v28);
    GFxLoader::~GFxLoader(this: (CMatRenderContextBase *)&v42, a2: (MaterialMatrixMode_t)84, a3: (matrix3x4_t *)&v46);
  }
  if ( Movie_LoadState == nullptr )
    return 0;
  rbd = nullptr;
  v45 = 0;
  v31 = Movie_LoadState[7].__vftable;
  SetView = (char)v31->SetView;
  p_IsUsingGraphics = &v31->IsUsingGraphics;
  if ( SetView != 0 && fontBindIndex < (unsigned int)p_IsUsingGraphics[1] )
  {
    v34 = (unsigned int)p_IsUsingGraphics[2] + 8 * fontBindIndex;
    if ( *(_DWORD *)v34 != 0 )
    {
      GRefCountImpl::AddRef(this: *(IShaderDevice **)v34);
      if ( rbd != nullptr )
        GFxResource::Release(this: (IShaderDevice *)rbd);
    }
    v35 = *(IShaderDevice **)v34;
    rbd = *(_ENUM_SERVICE_STATUSA **)v34;
    v45 = *(_DWORD *)(v34 + 4);
  }
  else
  {
    GFxResourceBinding::GetResourceData_Locked(
      this: (GFxResourceBinding *)p_IsUsingGraphics,
      a2: (struct GFxResourceBindData *)&rbd,
      a3: fontBindIndex);
    v35 = (IShaderDevice *)rbd;
  }
  if ( v35 == nullptr )
  {
    GFxResource::Release(this: Movie_LoadState);
    return 0;
  }
  GRefCountImpl::AddRef(this: Movie_LoadState);
  GRefCountImpl::AddRef(this: v35);
  if ( this->__vftable != nullptr )
    GFxResource::Release(this: (IShaderDevice *)this->__vftable);
  v36 = *((IShaderDevice **)this + 1);
  if ( v36 != nullptr )
    GFxResource::Release(this: v36);
  v37 = (IShaderDevice *)rbd;
  this->__vftable = (IRecordInfo_vtbl *)Movie_LoadState;
  *((_DWORD *)this + 1) = v35;
  if ( v37 != nullptr )
    GFxResource::Release(this: v37);
  GFxResource::Release(this: Movie_LoadState);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006E3C0
// Name: public: void GFxFontLib::AddFontsFrom(class GFxMovieDef __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxFontLib::AddFontsFrom(int a1@<ecx>, IRecordInfo *this, unsigned int *md, wchar_t **pin)
{
  int v5; // eax
  IShaderDevice *v6; // edi
  CVertexBuilder *v7; // esi
  IShaderDevice **v8; // esi

  if ( *(_DWORD *)(a1 + 12) != 0 && this != nullptr )
  {
    v5 = *((_DWORD *)this + 7);
    v6 = *(IShaderDevice **)(v5 + 12);
    if ( v6 != nullptr )
      GRefCountImpl::AddRef(this: *(IShaderDevice **)(v5 + 12));
    v7 = *(CVertexBuilder **)(a1 + 12);
    GArrayDataBase<GPtr<GFxMovieDefImpl>,GAllocatorGH<GPtr<GFxMovieDefImpl>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: v7,
      a2: (VertexShaderHandle_t__ *)this,
      a3: (int)v7,
      a4: v7->m_VertexSize_BoneWeight + 1);
    v8 = (IShaderDevice **)(v7->m_VertexSize_Position + 4 * v7->m_VertexSize_BoneWeight - 4);
    if ( v8 != nullptr )
    {
      if ( v6 != nullptr )
        GRefCountImpl::AddRef(this: v6);
      *v8 = v6;
    }
    if ( v6 != nullptr )
      GFxResource::Release(this: v6);
    if ( (_BYTE)md != 0 && *((_DWORD *)this + 2) != 0 )
      (*(void (__thiscall **)(_DWORD, IRecordInfo *))(**((_DWORD **)this + 2) + 8))(a1: *((_DWORD *)this + 2), a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006E740
// Name: public: GFxFontLib::GFxFontLib(void)
// Source: json
//------------------------------------------------------------------------------
IRecordInfo *__stdcall GFxFontLib::GFxFontLib(IRecordInfo *this)
{
  IRecordInfo *v1; // ecx
  IRecordInfo *v2; // esi
  IRecordInfo_vtbl *v3; // eax
  int v5; // [esp+4h] [ebp-4h] BYREF

  v2 = v1;
  v1->__vftable = (IRecordInfo_vtbl *)&GRefCountImplCore::`vftable';
  v1[1].__vftable = (IRecordInfo_vtbl *)1;
  v1[2].__vftable = (IRecordInfo_vtbl *)19;
  v1->__vftable = (IRecordInfo_vtbl *)&GFxFontLib::`vftable';
  v5 = 2;
  v3 = (IRecordInfo_vtbl *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 12, a3: &v5);
  if ( v3 != nullptr )
  {
    v3->QueryInterface = nullptr;
    v3->AddRef = nullptr;
    v3->Release = nullptr;
    v2[3].__vftable = v3;
  }
  else
  {
    v2[3].__vftable = nullptr;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1006E7A0
// Name: public: virtual GFxFontLib::~GFxFontLib(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFxFontLib::~GFxFontLib(IRecordInfo *this)
{
  IShaderAPI *v1; // ecx
  IShaderAPI *v2; // ebx
  IShaderAPI_vtbl *v3; // edi
  void (__thiscall *GetLightmapDimensions)(struct IShaderAPI *, int *, int *); // eax
  IShaderDevice **v5; // esi
  void (__thiscall *v6)(struct IShaderAPI *, int *, int *); // ebx
  IShaderAPI *v7; // [esp+8h] [ebp-4h]

  v2 = v1;
  v3 = v1[3].__vftable;
  v7 = v1;
  v1->__vftable = (IShaderAPI_vtbl *)&GFxFontLib::`vftable';
  if ( v3 != nullptr )
  {
    GetLightmapDimensions = v3->GetLightmapDimensions;
    v5 = (IShaderDevice **)((char *)v3->CurrentTime + 4 * (_DWORD)GetLightmapDimensions - 4);
    if ( GetLightmapDimensions != nullptr )
    {
      v6 = v3->GetLightmapDimensions;
      do
      {
        if ( *v5 != nullptr )
          GFxResource::Release(this: *v5);
        --v5;
        v6 = (void (__thiscall *)(struct IShaderAPI *, int *, int *))((char *)v6 - 1);
      }
      while ( v6 != nullptr );
      v2 = v7;
    }
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3->CurrentTime);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
  }
  v2->__vftable = (IShaderAPI_vtbl *)&GFxState::`vftable';
  GRefCountImplCore::~GRefCountImplCore(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1006E8D0
// Name: public: void GFxFontLib::LoadFontNames(class GStringHash<class GString,struct GAllocatorGH<class GString,2>> __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__userpurge GFxFontLib::LoadFontNames@<eax>(int a1@<ecx>, int a2@<esi>, int *a3)
{
  _DWORD *result; // eax
  unsigned int v4; // edi
  int v5; // esi
  int v6; // ebx
  const char *v7; // eax
  int v8; // eax
  void **v9; // ecx
  int v10; // esi
  int v11; // edi
  int v12; // eax
  int v13; // edi
  void *v14; // esi
  int v15; // [esp-Ch] [ebp-20h]
  int v16; // [esp-Ch] [ebp-20h]
  _DWORD *v17[2]; // [esp+0h] [ebp-14h] BYREF
  int v18; // [esp+8h] [ebp-Ch]
  unsigned int i; // [esp+Ch] [ebp-8h]
  int src; // [esp+10h] [ebp-4h] BYREF

  result = *(_DWORD **)(a1 + 12);
  v18 = a1;
  if ( result == nullptr )
    return result;
  v4 = 0;
  i = 0;
  if ( result[1] == 0 )
    return result;
  v15 = a2;
  do
  {
    v5 = *(_DWORD *)(*result + 4 * v4);
    GFxMovieDataDef::LoadTaskData::WaitForLoadFinish(this: *(GFxMovieDataDef::LoadTaskData **)(v5 + 32));
    v6 = *(_DWORD *)(*(_DWORD *)(v5 + 32) + 164);
    if ( v6 == 0 )
      goto LABEL_15;
    v17[0] = &src;
    v17[1] = &src;
    do
    {
      v7 = (const char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v6 + 4) + 60))(a1: *(_DWORD *)(v6 + 4));
      GString::GString(this: (GString *)&src, a2: v7);
      v8 = (int)GString::BernsteinHashFunctionCIS(result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((src & 0xFFFFFFFC) + 8));
      v9 = (void **)a3;
      v10 = *a3;
      v11 = v8;
      if ( *a3 != 0 )
      {
        v12 = GHashSetBase<GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<unsigned int,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeRef>(
                this: a3,
                a2: v17,
                a3: v8 & *(_DWORD *)(v10 + 4));
        if ( v12 >= 0 )
        {
          v13 = v10 + 16 * (v12 + 1);
          GString::operator=(
            this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v13,
            (int)&src,
            a3: v15);
          GString::operator=(
            this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v13 + 4),
            (int)&src,
            a3: v16);
          goto LABEL_11;
        }
        v9 = (void **)a3;
      }
      GHashSetBase<GHashNode<GString,GString,GString::NoCaseHashFunctor>,GHashNode<GString,GString,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,GString,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<GString,2>,GHashsetCachedNodeEntry<GHashNode<GString,GString,GString::NoCaseHashFunctor>,GHashNode<GString,GString,GString::NoCaseHashFunctor>::NodeHashF>>::add<GHashNode<GString,GString,GString::NoCaseHashFunctor>::NodeRef>(
        this: v9,
        a2: (int)v9,
        a3: (CImagePacker **)v17,
        a4: v11);
LABEL_11:
      v14 = (void *)(src & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((src & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v14);
      v6 = *(_DWORD *)(v6 + 12);
    }
    while ( v6 != 0 );
    v4 = i;
LABEL_15:
    result = *(_DWORD **)(v18 + 12);
    i = ++v4;
  }
  while ( v4 < result[1] );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DBEB0
// Name: public: GFxMovieDefBindStates::GFxMovieDefBindStates(class GFxMovieDefBindStates __near *)
// Source: json
//------------------------------------------------------------------------------
CReferenceToHandleTexture *__userpurge GFxMovieDefBindStates::GFxMovieDefBindStates@<eax>(
        CReferenceToHandleTexture *this@<ecx>,
        int *pother,
        int a3)
{
  IShaderDevice *v4; // ecx
  IShaderAPI *m_hTexture; // ecx
  IShaderDevice *v6; // ecx
  IShaderAPI *m_nRefCount; // ecx
  IShaderDevice *v8; // ecx
  IShaderAPI *v9; // ecx
  IShaderDevice *v10; // ecx
  IShaderAPI *v11; // ecx
  IShaderDevice *v12; // ecx
  IShaderAPI *v13; // ecx
  IShaderDevice *v14; // ecx
  IShaderAPI *v15; // ecx
  IShaderDevice *v16; // ecx
  IShaderAPI *v17; // ecx
  IShaderDevice *v18; // ecx
  IShaderAPI *v19; // ecx
  IShaderDevice *v20; // ecx
  IShaderAPI *v21; // ecx

  this->__vftable = (CReferenceToHandleTexture_vtbl *)&GRefCountImplCore::`vftable';
  *(_DWORD *)&this->m_Name.m_Id = 1;
  this->__vftable = (CReferenceToHandleTexture_vtbl *)&GFxMovieDefBindStates::`vftable';
  this->m_hTexture = 0;
  this->m_nRefCount = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  v4 = (IShaderDevice *)pother[2];
  if ( v4 != nullptr )
    GRefCountImpl::AddRef(this: v4);
  m_hTexture = (IShaderAPI *)this->m_hTexture;
  if ( m_hTexture != nullptr )
    GRefCountImpl::Release(this: m_hTexture);
  this->m_hTexture = pother[2];
  v6 = (IShaderDevice *)pother[3];
  if ( v6 != nullptr )
    GRefCountImpl::AddRef(this: v6);
  m_nRefCount = (IShaderAPI *)this->m_nRefCount;
  if ( m_nRefCount != nullptr )
    GRefCountImpl::Release(this: m_nRefCount);
  this->m_nRefCount = pother[3];
  v8 = (IShaderDevice *)pother[4];
  if ( v8 != nullptr )
    GRefCountImpl::AddRef(this: v8);
  v9 = *((IShaderAPI **)this + 4);
  if ( v9 != nullptr )
    GRefCountImpl::Release(this: v9);
  *((_DWORD *)this + 4) = pother[4];
  v10 = (IShaderDevice *)pother[5];
  if ( v10 != nullptr )
    GRefCountImpl::AddRef(this: v10);
  v11 = *((IShaderAPI **)this + 5);
  if ( v11 != nullptr )
    GRefCountImpl::Release(this: v11);
  *((_DWORD *)this + 5) = pother[5];
  v12 = (IShaderDevice *)pother[7];
  if ( v12 != nullptr )
    GRefCountImpl::AddRef(this: v12);
  v13 = *((IShaderAPI **)this + 7);
  if ( v13 != nullptr )
    GRefCountImpl::Release(this: v13);
  *((_DWORD *)this + 7) = pother[7];
  v14 = (IShaderDevice *)pother[6];
  if ( v14 != nullptr )
    GRefCountImpl::AddRef(this: v14);
  v15 = *((IShaderAPI **)this + 6);
  if ( v15 != nullptr )
    GRefCountImpl::Release(this: v15);
  *((_DWORD *)this + 6) = pother[6];
  v16 = (IShaderDevice *)pother[8];
  if ( v16 != nullptr )
    GRefCountImpl::AddRef(this: v16);
  v17 = *((IShaderAPI **)this + 8);
  if ( v17 != nullptr )
    GRefCountImpl::Release(this: v17);
  *((_DWORD *)this + 8) = pother[8];
  v18 = (IShaderDevice *)pother[9];
  if ( v18 != nullptr )
    GRefCountImpl::AddRef(this: v18);
  v19 = *((IShaderAPI **)this + 9);
  if ( v19 != nullptr )
    GRefCountImpl::Release(this: v19);
  *((_DWORD *)this + 9) = pother[9];
  v20 = (IShaderDevice *)pother[10];
  if ( v20 != nullptr )
    GRefCountImpl::AddRef(this: v20);
  v21 = *((IShaderAPI **)this + 10);
  if ( v21 != nullptr )
    GRefCountImpl::Release(this: v21);
  *((_DWORD *)this + 10) = pother[10];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E58F0
// Name: public: struct GFxResourceBindData GFxResourceBinding::GetResourceData(class GFxResourceHandle const __near &)
// Source: json
//------------------------------------------------------------------------------
ExprNode **__userpurge GFxResourceBinding::GetResourceData@<eax>(
        CExpressionEvaluator *this@<ecx>,
        ExprNode **h,
        const GenericThreadLocals::CThreadLocal<int> *ha,
        Kind a4,
        ExprNode *a5,
        ExprNode *a6)
{
  unsigned int m_index; // eax
  const char *v7; // edi
  ExprNode *v9; // edi

  *h = nullptr;
  h[1] = nullptr;
  if ( ha->m_index == 1 )
  {
    m_index = ha[1].m_index;
    if ( this->m_Identifier[20] != 0 && m_index < *(_DWORD *)&this->m_CurToken )
    {
      v7 = &this->m_pExpression[8 * m_index];
      if ( *(_DWORD *)v7 != 0 )
        GRefCountImpl::AddRef(this: *(IShaderDevice **)v7);
      if ( *h != nullptr )
        GFxResource::Release(this: (IShaderDevice *)*h);
      *h = *(ExprNode **)v7;
      h[1] = *((ExprNode **)v7 + 1);
      return h;
    }
    else
    {
      GFxResourceBinding::GetResourceData_Locked(this, a2: (struct GFxResourceBindData *)h, a3: m_index);
      return h;
    }
  }
  else
  {
    h[1] = (ExprNode *)this;
    if ( ha->m_index != 0 )
    {
      *h = nullptr;
      return h;
    }
    else
    {
      v9 = (ExprNode *)ha[1].m_index;
      if ( v9 != nullptr )
      {
        GRefCountImpl::AddRef(this: (IShaderDevice *)ha[1].m_index);
        if ( *h != nullptr )
          GFxResource::Release(this: (IShaderDevice *)*h);
      }
      *h = v9;
      return h;
    }
  }
}
