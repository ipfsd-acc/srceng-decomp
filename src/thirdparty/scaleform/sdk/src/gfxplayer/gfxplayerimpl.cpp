// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxplayerimpl.cpp
// Functions: 242
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxplayerimpl.h"

//------------------------------------------------------------------------------
// Address: 0x10058610
// Name: public: virtual enum GFxMovieView::ScaleModeType GFxMovieRoot::GetViewScaleMode(void)const
// Source: json
//------------------------------------------------------------------------------
HRESULT __cdecl GFxMovieRoot::GetViewScaleMode(IDirect3DResource9 *this)
{
  int v1; // ecx

  return *(_DWORD *)(v1 + 136);
}

//------------------------------------------------------------------------------
// Address: 0x10070090
// Name: public: GHashsetCachedEntry<class GFxTextFormatPtrWrapper<class GFxTextFormat>,struct GFxTextFormatPtrWrapper<class GFxTextFormat>::HashFunctor>::GHashsetCachedEntry<class GFxTextFormatPtrWrapper<class GFxTextFormat>,struct GFxTextFormatPtrWrapper<class GFxTextFormat>::HashFunctor>(class GHashsetCachedEntry<class GFxTextFormatPtrWrapper<class GFxTextFormat>,struct GFxTextFormatPtrWrapper<class GFxTextFormat>::HashFunctor> const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GHashsetCachedEntry<GFxTextFormatPtrWrapper<GFxTextFormat>,GFxTextFormatPtrWrapper<GFxTextFormat>::HashFunctor>::GHashsetCachedEntry<GFxTextFormatPtrWrapper<GFxTextFormat>,GFxTextFormatPtrWrapper<GFxTextFormat>::HashFunctor>(
        _DWORD *this,
        _DWORD *a2)
{
  IShaderDevice *v3; // ecx
  VertexShaderHandle_t__ *v5; // [esp+0h] [ebp-8h]

  *this = *a2;
  *(this + 1) = a2[1];
  v3 = (IShaderDevice *)a2[2];
  if ( v3 != nullptr )
    GRefCountImpl::AddRef(this: v3, a2: v5);
  *(this + 2) = a2[2];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BC840
// Name: public: GFxIMEImm32Dll::GFxIMEImm32Dll(void)
// Source: json
//------------------------------------------------------------------------------
IDirect3DDevice9 *__thiscall GFxIMEImm32Dll::GFxIMEImm32Dll(void *this)
{
  HMODULE LibraryA; // eax
  BOOL (__stdcall *ImmReleaseContext)(HWND, HIMC); // eax
  LONG (__stdcall *ImmGetCompositionStringA)(HIMC, DWORD, LPVOID, DWORD); // eax
  BOOL (__stdcall *ImmIsUIMessageA)(HWND, UINT, WPARAM, LPARAM); // eax
  BOOL (__stdcall *ImmIsUIMessageW)(HWND, UINT, WPARAM, LPARAM); // eax
  HMODULE v8; // [esp-Ch] [ebp-10h]
  HMODULE v9; // [esp-Ch] [ebp-10h]
  HMODULE v10; // [esp-Ch] [ebp-10h]
  HMODULE v11; // [esp-Ch] [ebp-10h]

  LibraryA = LoadLibraryA(lpLibFileName: "imm32.dll");
  *((_DWORD *)this + 7) = LibraryA;
  if ( LibraryA != nullptr )
  {
    *(_DWORD *)this = GetProcAddress(hModule: LibraryA, lpProcName: "ImmGetContext");
    ImmReleaseContext = (BOOL (__stdcall *)(HWND, HIMC))GetProcAddress(
                                                          hModule: *((HMODULE *)this + 7),
                                                          lpProcName: "ImmReleaseContext");
    v8 = *((HMODULE *)this + 7);
    *((_DWORD *)this + 1) = ImmReleaseContext;
    ImmGetCompositionStringA = (LONG (__stdcall *)(HIMC, DWORD, LPVOID, DWORD))GetProcAddress(
                                                                                 hModule: v8,
                                                                                 lpProcName: "ImmGetCompositionStringA");
    v9 = *((HMODULE *)this + 7);
    *((_DWORD *)this + 2) = ImmGetCompositionStringA;
    *((_DWORD *)this + 3) = GetProcAddress(hModule: v9, lpProcName: "ImmGetCompositionStringW");
    ImmIsUIMessageA = (BOOL (__stdcall *)(HWND, UINT, WPARAM, LPARAM))GetProcAddress(
                                                                        hModule: *((HMODULE *)this + 7),
                                                                        lpProcName: "ImmIsUIMessageA");
    v10 = *((HMODULE *)this + 7);
    *((_DWORD *)this + 4) = ImmIsUIMessageA;
    ImmIsUIMessageW = (BOOL (__stdcall *)(HWND, UINT, WPARAM, LPARAM))GetProcAddress(
                                                                        hModule: v10,
                                                                        lpProcName: "ImmIsUIMessageW");
    v11 = *((HMODULE *)this + 7);
    *((_DWORD *)this + 5) = ImmIsUIMessageW;
    *((_DWORD *)this + 6) = GetProcAddress(hModule: v11, lpProcName: "ImmGetDefaultIMEWnd");
    *((_DWORD *)this + 8) = 0;
  }
  else
  {
    *((_DWORD *)this + 8) = GetLastError();
  }
  return (IDirect3DDevice9 *)this;
}

//------------------------------------------------------------------------------
// Address: 0x100BC8E0
// Name: public: GFxMovieRoot::StickyVarNode::StickyVarNode(class GASString const __near &,class GASValue const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
const GList<GMemoryHeap> *__thiscall GFxMovieRoot::StickyVarNode::StickyVarNode(
        GList<GMemoryHeap> *this,
        _IMAGE_SYMBOL_EX *name,
        tagWNDCLASSW *value,
        bool permanent)
{
  GMemoryHeap *Short; // eax

  Short = (GMemoryHeap *)name->N.Name.Short;
  this->Root.pPrev = (GMemoryHeap *)name->N.Name.Short;
  ++Short->pNext;
  GASValue::GASValue(this: (GASValue *)&this->Root.pNext, a2: (const struct GASValue *)value);
  *((_DWORD *)this + 5) = 0;
  *((_BYTE *)this + 24) = permanent;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BC910
// Name: public: virtual void GFxMovieRoot::MemoryContextImpl::HeapLimit::OnFreeSegment(class GMemoryHeap __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::MemoryContextImpl::HeapLimit::OnFreeSegment(
        GFxMovieRoot::MemoryContextImpl::HeapLimit *this,
        struct GMemoryHeap *a2,
        unsigned int a3)
{
  unsigned int v3; // eax
  unsigned int v4; // eax

  v3 = *((_DWORD *)this + 4);
  if ( v3 > *((_DWORD *)this + 2) && v3 > a3 )
  {
    v4 = v3 - a3;
    *((_DWORD *)this + 4) = v4;
    a2->SetLimit(this: a2, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BC940
// Name: public: class GFxASCharacter __near * GFxMovieRoot::FindTarget(class GASString const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::FindTarget(GFxMovieRoot *this, _IMAGE_SYMBOL_EX *path)
{
  __vc_attributes::event_receiverAttribute *v2; // eax

  if ( *((_DWORD *)this + 12) != 0 && *(_DWORD *)(path->N.Name.Short + 16) != 0 )
  {
    v2 = (__vc_attributes::event_receiverAttribute *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 12) + 112))(a1: *((_DWORD *)this + 12));
    GASEnvironment::FindTarget(this: v2, (__vc_attributes::event_receiverAttribute::type_e)path, excludeFlags: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BC980
// Name: public: static int GFxMovieRoot::ParseLevelName(char const __near *,char const __near * __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GFxMovieRoot::ParseLevelName(
        char *nptr,
        CUtlMap<char const *,int,unsigned short>::CKeyLess ptail,
        bool caseSensitive)
{
  char v3; // cl
  int result; // eax
  char v5; // cl
  char v6; // cl
  char v7; // cl
  char v8; // cl
  char v9; // cl
  char v10; // cl
  char *v11; // [esp-Ch] [ebp-10h]
  char *ptail2; // [esp+0h] [ebp-4h] BYREF

  v3 = *nptr;
  if ( *nptr >= 48 && v3 <= 57 )
  {
    v11 = nptr;
    nptr = nullptr;
    result = strtol(nptr: v11, endptr: &nptr, ibase: 10);
    *(_DWORD *)ptail.m_LessFunc = nptr;
    return result;
  }
  if ( v3 != 95 )
    return -1;
  if ( caseSensitive )
  {
    if ( nptr[1] != 108 || nptr[2] != 101 || nptr[3] != 118 || nptr[4] != 101 || nptr[5] != 108 )
      return -1;
  }
  else
  {
    v5 = nptr[1];
    if ( v5 != 108 && v5 != 76 )
      return -1;
    v6 = nptr[2];
    if ( v6 != 101 && v6 != 69 )
      return -1;
    v7 = nptr[3];
    if ( v7 != 118 && v7 != 86 )
      return -1;
    v8 = nptr[4];
    if ( v8 != 101 && v8 != 69 )
      return -1;
    v9 = nptr[5];
    if ( v9 != 108 && v9 != 76 )
      return -1;
  }
  v10 = nptr[6];
  if ( v10 < 48 || v10 > 57 )
    return -1;
  ptail2 = nullptr;
  result = strtol(nptr: nptr + 6, endptr: &ptail2, ibase: 10);
  *(_DWORD *)ptail.m_LessFunc = ptail2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BCA60
// Name: public: void GFxMovieRoot::AddLoadQueueEntry(class GFxLoadQueueEntry __near *)
// Source: json
//------------------------------------------------------------------------------
ScaleformRenderTarget_vtbl *__thiscall GFxMovieRoot::AddLoadQueueEntry(
        ScaleformRenderTarget_vtbl **this,
        ScaleformRenderTarget *result)
{
  ScaleformRenderTarget_vtbl *v2; // eax

  *(this + 2575) = (ScaleformRenderTarget_vtbl *)((char *)*(this + 2575) + 1);
  result[1].pHandler = (GTexture::ChangeHandler *)*(this + 2575);
  v2 = *(this + 2574);
  if ( v2 != nullptr )
  {
    for ( ; v2->dtr_GRenderTarget != nullptr; v2 = (ScaleformRenderTarget_vtbl *)v2->dtr_GRenderTarget )
      ;
    v2->dtr_GRenderTarget = (void (__thiscall *)(struct ScaleformRenderTarget *))result;
  }
  else
  {
    *(this + 2574) = (ScaleformRenderTarget_vtbl *)result;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100BCAA0
// Name: public: unsigned int GFxMovieRoot::ActionQueueType::StartNewSession(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxMovieRoot::ActionQueueType::StartNewSession(GFxMovieRoot::ActionQueueType *this, unsigned int *a2)
{
  int result; // eax

  if ( a2 != nullptr )
    *a2 = *((_DWORD *)this + 20);
  result = *((_DWORD *)this + 22) + 1;
  *((_DWORD *)this + 22) = result;
  *((_DWORD *)this + 20) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BCAC0
// Name: public: virtual void GFxMovieRoot::GetViewport(class GViewport __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::GetViewport(
        int a1@<ecx>,
        IDirect3DResource9 *this,
        const _GUID *pviewDesc,
        void **pviewDesc_8)
{
  qmemcpy(this, (const void *)(a1 + 64), 0x34u);
}

//------------------------------------------------------------------------------
// Address: 0x100BCAE0
// Name: public: virtual void GFxMovieRoot::SetViewScaleMode(enum GFxMovieView::ScaleModeType)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxMovieRoot::SetViewScaleMode(_DWORD *ecx0, IDirect3DResource9 *this)
{
  unsigned int (__stdcall *v2)(_DWORD *); // edx

  v2 = *(unsigned int (__stdcall **)(_DWORD *))(*ecx0 + 100);
  *(ecx0 + 34) = this;
  return v2(a1: ecx0 + 16);
}

//------------------------------------------------------------------------------
// Address: 0x100BCB00
// Name: public: virtual void GFxMovieRoot::SetViewAlignment(enum GFxMovieView::AlignType)
// Source: json
//------------------------------------------------------------------------------
HRESULT __userpurge GFxMovieRoot::SetViewAlignment@<eax>(
        _DWORD *a1@<ecx>,
        IDirect3DResource9 *this,
        const _GUID *align,
        const void *a4,
        unsigned int a5,
        unsigned int a6)
{
  HRESULT (__stdcall *v6)(_DWORD *); // edx

  v6 = *(HRESULT (__stdcall **)(_DWORD *))(*a1 + 100);
  a1[35] = this;
  return v6(a1: a1 + 16);
}

//------------------------------------------------------------------------------
// Address: 0x100BCB20
// Name: public: void GFxMovieRoot::ProcessUnloadQueue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::ProcessUnloadQueue(ScaleformRenderer *this)
{
  GRefCountNTSImpl *v1; // esi
  GRefCountNTSImpl *RefCount; // edi
  void (__thiscall *dtr_GRefCountImplCore)(struct GRefCountNTSImpl *); // edx
  GRefCountNTSImpl_vtbl *v4; // ecx

  v1 = *((GRefCountNTSImpl **)this + 2563);
  if ( v1 != nullptr )
  {
    do
    {
      RefCount = (GRefCountNTSImpl *)v1[17].RefCount;
      dtr_GRefCountImplCore = v1->__vftable[34].dtr_GRefCountImplCore;
      v1[17].RefCount = 0;
      dtr_GRefCountImplCore(this: v1);
      v4 = v1[4].__vftable;
      if ( v4 != nullptr )
        (*((void (__thiscall **)(GRefCountNTSImpl_vtbl *, GRefCountNTSImpl *))v4->dtr_GRefCountImplCore + 36))(
          a1: v4,
          a2: v1);
      GRefCountNTSImpl::Release(this: v1);
      v1 = RefCount;
    }
    while ( RefCount != nullptr );
    *((_DWORD *)this + 2563) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BCB90
// Name: public: virtual unsigned int GFxMovieRoot::GetCurrentFrame(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxMovieRoot::GetCurrentFrame(_DWORD **this)
{
  if ( *(this + 12) != nullptr )
    return (*(int (__thiscall **)(_DWORD))(**(this + 12) + 316))(a1: *(this + 12));
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BCBB0
// Name: public: virtual bool GFxMovieRoot::HasLooped(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxMovieRoot::HasLooped(GFxMovieRoot *this)
{
  if ( *((_DWORD *)this + 12) != 0 )
    return (*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)this + 12) + 356))(a1: *((_DWORD *)this + 12));
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BCBD0
// Name: public: void GFxMovieRoot::SetKeyboardListener(class GFxKeyboardState::IListener __near *)
// Source: json
//------------------------------------------------------------------------------
tagWNDCLASSEXA *__thiscall GFxMovieRoot::SetKeyboardListener(_DWORD *this, tagWNDCLASSEXA *l)
{
  _DWORD *v2; // esi
  int i; // edi
  tagWNDCLASSEXA *result; // eax

  v2 = this + 629;
  for ( i = 4; i != 0; --i )
  {
    result = CDummyMaterialSystem::SetRealMaterialSystem(this: v2, result: l);
    v2 += 415;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BCC00
// Name: public: virtual void GFxMovieRoot::GotoFrame(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::GotoFrame(GFxMovieRoot *this, unsigned int a2)
{
  if ( *((_DWORD *)this + 12) != 0 )
    (*(void (__thiscall **)(_DWORD, unsigned int))(**((_DWORD **)this + 12) + 324))(a1: *((_DWORD *)this + 12), a2);
}

//------------------------------------------------------------------------------
// Address: 0x100BCC20
// Name: public: virtual void GFxMovieRoot::SetPlayState(enum GFxMovie::PlayState)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::SetPlayState(int a1@<ecx>, CDefaultDataCacheClient *s, GMemAddressStub *a3, int a4)
{
  if ( *(_DWORD *)(a1 + 48) != 0 )
    (*(void (__thiscall **)(_DWORD, CDefaultDataCacheClient *))(**(_DWORD **)(a1 + 48) + 328))(
      a1: *(_DWORD *)(a1 + 48),
      a2: s);
}

//------------------------------------------------------------------------------
// Address: 0x100BCC40
// Name: public: virtual enum GFxMovie::PlayState GFxMovieRoot::GetPlayState(void)const
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFxMovieRoot::GetPlayState()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100BCC60
// Name: public: virtual void GFxMovieRoot::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
const IDirect3DResource9 *__thiscall GFxMovieRoot::SetVisible(_DWORD **this, const IDirect3DResource9 *result)
{
  const IDirect3DResource9 *v2; // eax

  if ( *(this + 12) != nullptr )
    return (*(const IDirect3DResource9 *(__thiscall **)(_DWORD, const IDirect3DResource9 *))(**(this + 12) + 204))(
             a1: *(this + 12),
             a2: result);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100BCC80
// Name: public: virtual bool GFxMovieRoot::GetVisible(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxMovieRoot::GetVisible(GFxMovieRoot *this)
{
  if ( *((_DWORD *)this + 12) != 0 )
    return (*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)this + 12) + 16))(a1: *((_DWORD *)this + 12));
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BCCA0
// Name: public: virtual void GFxMovieRoot::SetExternalInterfaceRetVal(class GFxValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::SetExternalInterfaceRetVal(GFxMovieRoot *this, struct GFxValue *a2)
{
  GFxMovieRoot::GFxValue2ASValue(this, a2, a3: (struct GASValue *)((char *)this + 9164));
}

//------------------------------------------------------------------------------
// Address: 0x100BCCC0
// Name: public: virtual bool GFxMovieRoot::SetControllerFocusGroup(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxMovieRoot::SetControllerFocusGroup(
        GFxMovieRoot *this,
        unsigned int controllerIdx,
        unsigned int focusGroupIndex)
{
  if ( controllerIdx >= 0x10 || focusGroupIndex >= 0x10 )
    return 0;
  *((_BYTE *)this + controllerIdx + 10228) = focusGroupIndex;
  if ( focusGroupIndex >= *((_DWORD *)this + 2556) )
    *((_DWORD *)this + 2556) = focusGroupIndex + 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BCD00
// Name: public: virtual unsigned int GFxMovieRoot::GetControllerFocusGroup(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::GetControllerFocusGroup(ISteamRemoteStorage *this, bool controllerIdx)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100BCD20
// Name: public: unsigned long GFxMovieRoot::GetControllerMaskByFocusGroup(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GFxMovieRoot::GetControllerMaskByFocusGroup@<eax>(
        ISteamRemoteStorage *this@<ecx>,
        unsigned __int64 focusGroupIndex)
{
  int result; // eax
  int v3; // edx
  unsigned __int8 *v4; // ecx
  int i; // edi
  int v6; // edx
  int v7; // edx
  int v8; // edx

  result = 0;
  v3 = 1;
  v4 = (unsigned __int8 *)this + 10229;
  for ( i = 4; i != 0; --i )
  {
    if ( *(v4 - 1) == (_DWORD)focusGroupIndex )
      result |= v3;
    v6 = 2 * v3;
    if ( *v4 == (_DWORD)focusGroupIndex )
      result |= v6;
    v7 = 2 * v6;
    if ( v4[1] == (_DWORD)focusGroupIndex )
      result |= v7;
    v8 = 2 * v7;
    if ( v4[2] == (_DWORD)focusGroupIndex )
      result |= v8;
    v3 = 2 * v8;
    v4 += 4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BCD80
// Name: public: void GFxMovieRoot::GetIMECandidateListStyle(class GFxIMECandidateListStyle __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::GetIMECandidateListStyle(GFxMovieRoot *this, struct GFxIMECandidateListStyle *a2)
{
  char *v2; // esi
  char v3; // [esp+8h] [ebp-2Ch] BYREF
  __int16 v4; // [esp+30h] [ebp-4h]

  v2 = *((char **)this + 2564);
  if ( v2 == nullptr )
  {
    v4 = 0;
    v2 = &v3;
  }
  qmemcpy(a2, v2, 0x2Cu);
}

//------------------------------------------------------------------------------
// Address: 0x100BCDB0
// Name: public: virtual void GFxPlaceObjectUnpacked::Execute(class GFxSprite __near *)
// Source: json
//------------------------------------------------------------------------------
const CMemberFuncProxyBase<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),CFuncMemPolicyNone> *__thiscall GFxPlaceObjectUnpacked::Execute(
        int this,
        CMemberFuncProxyBase<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),CFuncMemPolicyNone> *result)
{
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v2; // esi
  const CMemberFuncProxyBase<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),CFuncMemPolicyNone> *v4; // eax

  v2 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)result;
  result = *(CMemberFuncProxyBase<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),CFuncMemPolicyNone> **)(*(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxyBase<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),CFuncMemPolicyNone> *))(LODWORD(result->m_pfnProxied) + 112))(a1: result) + 120) + 8);
  ++DWORD2(result->m_pfnProxied);
  GFxSprite::AddDisplayObject(
    this: v2,
    name: (_IMAGE_SYMBOL_EX *)(this + 4),
    a3: (int)&result,
    a4: 0,
    a5: 0,
    createFrame: 0xFFFFFFFF,
    addFlags: 4u,
    rh: nullptr,
    a9: 0);
  v4 = result;
  if ( DWORD2(result->m_pfnProxied)-- == 1 )
    return (const CMemberFuncProxyBase<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),CFuncMemPolicyNone> *)GASStringNode::ReleaseNode().Sid;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100BCE00
// Name: public: virtual struct GFxCharPosInfoFlags GFxPlaceObject::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
_BYTE *__thiscall GFxPlaceObject::GetFlags(_BYTE *this, _BYTE *a2)
{
  *a2 = (*(this + 4) != 0 ? 8 : 0) | 7;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100BCE20
// Name: protected: unsigned short GFxPlaceObject::GetDepth(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall GFxPlaceObject::GetDepth(GFxPlaceObject *this)
{
  return *(_WORD *)((char *)this + 7);
}

//------------------------------------------------------------------------------
// Address: 0x100BCE30
// Name: public: virtual void GFxPlaceObject::Unpack(struct GFxPlaceObjectBase::UnpackedData __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPlaceObject::Unpack(GFxPlaceObject *this, struct GFxPlaceObjectBase::UnpackedData *a2)
{
  _DWORD v3[2]; // [esp+Ch] [ebp-10h] BYREF
  int v4; // [esp+14h] [ebp-8h]
  int v5; // [esp+18h] [ebp-4h]

  *((_DWORD *)a2 + 22) = 0;
  *((_DWORD *)a2 + 21) = 0;
  *((_DWORD *)a2 + 23) = 0;
  *((_BYTE *)a2 + 83) |= 2u;
  v3[0] = (char *)this + 5;
  v4 = 0;
  v5 = 0;
  v3[1] = -1;
  *((_DWORD *)a2 + 19) = *(unsigned __int16 *)((char *)this + 5);
  *((_BYTE *)a2 + 83) |= 1u;
  v4 = 2;
  v5 = 0;
  *((_DWORD *)a2 + 18) = *(unsigned __int16 *)((char *)this + 7);
  *((_BYTE *)a2 + 83) |= 4u;
  v4 = 4;
  GFxStreamContext::ReadMatrix(this: (GFxStreamContext *)v3, pm: (CMaterialDict *)((char *)a2 + 44));
  if ( *((_BYTE *)this + 4) != 0 )
  {
    *((_BYTE *)a2 + 83) |= 8u;
    GFxStreamContext::ReadCxformRgb(this: (GFxStreamContext *)v3, a2: (struct GRenderer::Cxform *)((char *)a2 + 12));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BCED0
// Name: public: void GFxPlaceObject::CheckForCxForm(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPlaceObject::CheckForCxForm(GFxPlaceObject *this, unsigned int a2)
{
  const CMaterialDict::MissingMaterial_t *v3; // [esp+0h] [ebp-30h]
  _DWORD v4[2]; // [esp+4h] [ebp-2Ch] BYREF
  unsigned int v5; // [esp+Ch] [ebp-24h]
  int v6; // [esp+10h] [ebp-20h]
  char v7; // [esp+14h] [ebp-1Ch] BYREF

  v4[0] = (char *)this + 5;
  v4[1] = -1;
  GMatrix2D::SetIdentity(result: v3);
  v5 = 4;
  v6 = 0;
  GFxStreamContext::ReadMatrix(this: (GFxStreamContext *)v4, pm: (CMaterialDict *)&v7);
  *((_BYTE *)this + 4) = v5 < a2 - 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BCF50
// Name: public: virtual struct GFxCharPosInfoFlags GFxPlaceObject2::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
_BYTE *__thiscall GFxPlaceObject2::GetFlags(_BYTE *this, _BYTE *a2)
{
  *a2 = *(this + 4) & 0x5F;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100BCF70
// Name: protected: unsigned short GFxPlaceObject2::GetDepth(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall GFxPlaceObject2::GetDepth(GFxPlaceObject2 *this)
{
  int v1; // edx

  v1 = 1;
  if ( *((char *)this + 4) < 0 )
    v1 = 5;
  return *(_WORD *)((char *)this + v1 + 4);
}

//------------------------------------------------------------------------------
// Address: 0x100BCFA0
// Name: protected: enum GFxPlaceObjectBase::PlaceActionType GFxPlaceObject3::GetPlaceType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxPlaceObject3::GetPlaceType(_BYTE *this)
{
  char v1; // al

  v1 = *(this + 4) & 1;
  if ( (*(this + 4) & 2) != 0 )
  {
    if ( v1 != 0 )
      return 2;
  }
  else if ( v1 != 0 )
  {
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BCFD0
// Name: public: static bool GFxPlaceObject2::HasEventHandlers(class GFxStream __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxPlaceObject2::HasEventHandlers(
        const CMemberFuncProxyBase<IMesh *,void (__thiscall IMesh::*)(Vector4D const &,int,int),CFuncMemPolicyNone> *pin,
        IShaderDeviceMgr *a2)
{
  int v2; // eax
  IShaderDeviceMgr_vtbl *v3; // eax
  unsigned __int8 v4; // bl
  int v5; // edx
  _cpinfo *v7; // [esp+0h] [ebp-8h]

  v2 = (char *)a2[12].__vftable - (char *)a2[11].__vftable;
  BYTE1(a2[5].__vftable) = 0;
  if ( v2 < 1 )
    GFxStream::PopulateBuffer1(result: v7);
  v3 = a2[11].__vftable;
  v4 = *((_BYTE *)&v3->Connect + (unsigned int)a2[15].__vftable);
  v5 = (char *)a2[13].__vftable - (char *)a2[12].__vftable;
  v3 = (IShaderDeviceMgr_vtbl *)((char *)v3 + 1);
  a2[11].__vftable = v3;
  GFxStream::SetPosition(this: a2, pos: (int)v3 + v5 - 1, a3: (int)v7);
  return v4 >> 7;
}

//------------------------------------------------------------------------------
// Address: 0x100BD020
// Name: public: static void GFxPlaceObject2::RestructureForEventHandlers(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
static unsigned __int8 *__stdcall GFxPlaceObject2::RestructureForEventHandlers(unsigned __int8 *pdata)
{
  *pdata = pdata[4];
  *(_DWORD *)(pdata + 1) = 0;
  return pdata;
}

//------------------------------------------------------------------------------
// Address: 0x100BD040
// Name: public: virtual struct GFxCharPosInfoFlags GFxPlaceObject3::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
_BYTE *__thiscall GFxPlaceObject3::GetFlags(char *this, _BYTE *a2)
{
  char v2; // dl
  int v3; // eax
  char v4; // cl

  v2 = *(this + 4);
  v3 = 1;
  if ( v2 < 0 )
    v3 = 5;
  v4 = *(this + v3 + 4) & 1 | (2 * (*(this + v3 + 4) & 0xFE));
  *a2 = v2 & 0x5F | (32 * v4);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100BD080
// Name: protected: unsigned short GFxPlaceObject3::GetDepth(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPlaceObject3::GetDepth(
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,void *),IMaterial *,void *,CFuncMemPolicyNone> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100BD0B0
// Name: public: void GFxRemoveObject::Read(class GFxLoadProcess __near *)
// Source: json
//------------------------------------------------------------------------------
const CPrimList *__thiscall GFxRemoveObject::Read(_WORD *this, const CPrimList *result)
{
  const CPrimList *m_NumIndices; // esi
  int v4; // eax
  int v5; // eax
  __int16 v6; // dx
  const CPrimList *v7; // esi
  int v8; // edx
  int v9; // eax
  __int16 v10; // dx
  const CPrimList *v11; // eax

  m_NumIndices = (const CPrimList *)result[100].m_NumIndices;
  if ( m_NumIndices == nullptr )
    m_NumIndices = result + 5;
  v4 = m_NumIndices[6].m_FirstIndex - m_NumIndices[5].m_NumIndices;
  BYTE1(m_NumIndices[2].m_NumIndices) = 0;
  if ( v4 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v5 = m_NumIndices[5].m_NumIndices;
  v6 = *(_WORD *)(m_NumIndices[7].m_NumIndices + v5);
  m_NumIndices[5].m_NumIndices = v5 + 2;
  *(this + 2) = v6;
  v7 = (const CPrimList *)result[100].m_NumIndices;
  if ( v7 == nullptr )
    v7 = result + 5;
  v8 = v7[6].m_FirstIndex - v7[5].m_NumIndices;
  BYTE1(v7[2].m_NumIndices) = 0;
  if ( v8 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v9 = v7[5].m_NumIndices;
  v10 = *(_WORD *)(v7[7].m_NumIndices + v9);
  v11 = (const CPrimList *)(v9 + 2);
  v7[5].m_NumIndices = (int)v11;
  *(this + 3) = v10;
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x100BD160
// Name: public: virtual void GFxRemoveObject::Execute(class GFxSprite __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxRemoveObject::Execute(GFxRemoveObject *this, GMemoryFile *a2)
{
  GFxSprite::RemoveDisplayObject(
    this: a2,
    depth: (GFile *)*((unsigned __int16 *)this + 3),
    id: *((unsigned __int16 *)this + 2));
}

//------------------------------------------------------------------------------
// Address: 0x100BD180
// Name: public: void GFxRemoveObject2::Read(class GFxLoadProcess __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxRemoveObject2::Read(GFxRemoveObject2 *this, struct GFxLoadProcess *a2)
{
  char *v2; // esi
  int v4; // eax
  int v5; // eax
  __int16 v6; // dx

  v2 = *((char **)a2 + 201);
  if ( v2 == nullptr )
    v2 = (char *)a2 + 40;
  v4 = *((_DWORD *)v2 + 12) - *((_DWORD *)v2 + 11);
  v2[21] = 0;
  if ( v4 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v5 = *((_DWORD *)v2 + 11);
  v6 = *(_WORD *)(*((_DWORD *)v2 + 15) + v5);
  *((_DWORD *)v2 + 11) = v5 + 2;
  *((_WORD *)this + 2) = v6;
}

//------------------------------------------------------------------------------
// Address: 0x100BD1E0
// Name: public: virtual void GFxRemoveObject2::Execute(class GFxSprite __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxRemoveObject2::Execute(GFxRemoveObject2 *this, GMemoryFile *a2)
{
  GFxSprite::RemoveDisplayObject(this: a2, depth: (GFile *)*((unsigned __int16 *)this + 2), id: 0x40000);
}

//------------------------------------------------------------------------------
// Address: 0x100BD200
// Name: public: void GFxInputEventsQueue::AddMouseMove(unsigned int,class GPoint<float> const __near &)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GFxInputEventsQueue::AddMouseMove(float *this, unsigned int a2, float *a3)
{
  float *result; // eax

  result = this;
  if ( a2 < 4 )
  {
    *((_DWORD *)this + 510) |= 1 << a2;
    *(this + 2 * a2 + 502) = *a3;
    *(this + 2 * a2 + 503) = a3[1];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BD240
// Name: public: void GFxInputEventsQueue::AddMouseButtonEvent(unsigned int,class GPoint<float> const __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxInputEventsQueue::AddMouseButtonEvent(_DWORD *this, char a2, float *a3, __int16 a4, char a5)
{
  bool v5; // zf
  int v6; // esi
  unsigned int v7; // eax
  _DWORD *result; // eax

  if ( 1.1754944e-38 != *a3 )
    *(this + 510) &= ~(1 << a2);
  if ( *(this + 501) == 100 )
  {
    v5 = ++*(this + 500) == 100;
    *(this + 501) = 99;
    if ( v5 )
      *(this + 500) = 0;
  }
  v6 = *(this + 501);
  v7 = v6 + *(this + 500);
  if ( v7 >= 0x64 )
    v7 -= 100;
  *(this + 501) = v6 + 1;
  result = this + 5 * v7;
  *result = 0;
  *((_BYTE *)result + 16) = a2;
  *((float *)result + 1) = *a3;
  *((float *)result + 2) = a3[1];
  *((_WORD *)result + 6) = a4;
  *((_BYTE *)result + 15) = a5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BD2F0
// Name: public: void GFxInputEventsQueue::AddMouseWheel(unsigned int,class GPoint<float> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxInputEventsQueue::AddMouseWheel(_DWORD *this, char a2, float *a3, char a4)
{
  bool v4; // zf
  int v5; // esi
  unsigned int v6; // eax
  _DWORD *result; // eax

  if ( 1.1754944e-38 != *a3 )
    *(this + 510) &= ~(1 << a2);
  if ( *(this + 501) == 100 )
  {
    v4 = ++*(this + 500) == 100;
    *(this + 501) = 99;
    if ( v4 )
      *(this + 500) = 0;
  }
  v5 = *(this + 501);
  v6 = v5 + *(this + 500);
  if ( v6 >= 0x64 )
    v6 -= 100;
  *(this + 501) = v5 + 1;
  result = this + 5 * v6;
  *result = 0;
  *((_BYTE *)result + 16) = a2;
  *((float *)result + 1) = *a3;
  *((float *)result + 2) = a3[1];
  *((_BYTE *)result + 14) = a4;
  *((_WORD *)result + 6) = 0;
  *((_BYTE *)result + 15) = 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BD3A0
// Name: public: void GFxInputEventsQueue::AddKeyEvent(short,unsigned char,unsigned long,bool,class GFxSpecialKeysState,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxInputEventsQueue::AddKeyEvent(
        GFxInputEventsQueue *this,
        __int16 a2,
        char a3,
        unsigned int a4,
        bool a5,
        struct GFxSpecialKeysState a6,
        unsigned __int8 a7)
{
  bool v7; // zf
  int v8; // edx
  unsigned int v9; // eax
  char *v10; // eax

  if ( *((_DWORD *)this + 501) == 100 )
  {
    v7 = ++*((_DWORD *)this + 500) == 100;
    *((_DWORD *)this + 501) = 99;
    if ( v7 )
      *((_DWORD *)this + 500) = 0;
  }
  v8 = *((_DWORD *)this + 501);
  v9 = v8 + *((_DWORD *)this + 500);
  if ( v9 >= 0x64 )
    v9 -= 100;
  *((_DWORD *)this + 501) = v8 + 1;
  v10 = (char *)this + 20 * v9;
  *(_DWORD *)v10 = 1;
  *((_WORD *)v10 + 4) = a2;
  v10[10] = a3;
  *((_DWORD *)v10 + 1) = a4;
  v10[11] = a6.States;
  v10[12] = a7;
  v10[13] = a5;
}

//------------------------------------------------------------------------------
// Address: 0x100BD430
// Name: public: struct GFxInputEventsQueue::QueueEntry const __near * GFxInputEventsQueue::GetEntry(void)
// Source: json
//------------------------------------------------------------------------------
const struct GFxInputEventsQueue::QueueEntry *__thiscall GFxInputEventsQueue::GetEntry(GFxInputEventsQueue *this)
{
  const struct GFxInputEventsQueue::QueueEntry *result; // eax
  unsigned int v2; // ebx
  int v3; // edi
  float *v4; // esi
  bool v5; // zf
  int v6; // edx
  unsigned int v7; // eax
  float *v8; // eax
  double v9; // st7
  int v10; // esi

  result = *((const struct GFxInputEventsQueue::QueueEntry **)this + 501);
  if ( result != nullptr )
    goto LABEL_12;
  v2 = 0;
  v3 = 1;
  v4 = (float *)((char *)this + 2012);
  do
  {
    if ( (v3 & *((_DWORD *)this + 510)) != 0 )
    {
      if ( *((_DWORD *)this + 501) == 100 )
      {
        v5 = ++*((_DWORD *)this + 500) == 100;
        *((_DWORD *)this + 501) = 99;
        if ( v5 )
          *((_DWORD *)this + 500) = 0;
      }
      v6 = *((_DWORD *)this + 501);
      v7 = v6 + *((_DWORD *)this + 500);
      if ( v7 >= 0x64 )
        v7 -= 100;
      v8 = (float *)((char *)this + 20 * v7);
      *((_DWORD *)this + 501) = v6 + 1;
      *v8 = 0.0;
      *((_BYTE *)v8 + 16) = v2;
      v8[1] = *(v4 - 1);
      v9 = *v4;
      *((_WORD *)v8 + 6) = 0;
      v8[2] = v9;
      *((_BYTE *)v8 + 15) = 64;
      *((_DWORD *)this + 510) &= ~v3;
    }
    ++v2;
    v4 += 2;
    v3 *= 2;
  }
  while ( v2 < 4 );
  result = *((const struct GFxInputEventsQueue::QueueEntry **)this + 501);
  if ( result != nullptr )
  {
LABEL_12:
    v10 = *((_DWORD *)this + 500);
    *((_DWORD *)this + 500) = v10 + 1;
    *((_DWORD *)this + 501) = (char *)result - 1;
    if ( v10 == 99 )
      *((_DWORD *)this + 500) = 0;
    return (GFxInputEventsQueue *)((char *)this + 20 * v10);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BD520
// Name: public: GFxURLBuilder::LocationInfo::LocationInfo(enum GFxURLBuilder::FileUse,class GString const __near &,class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
GFxURLBuilder::LocationInfo *__thiscall GFxURLBuilder::LocationInfo::LocationInfo(
        GFxURLBuilder::LocationInfo *this,
        enum GFxURLBuilder::FileUse a2,
        CImagePacker *result,
        CImagePacker *a4)
{
  this->Use = a2;
  GString::GString(result);
  GString::GString(result: a4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BD550
// Name: public: void GFxInputEventsQueue::AddKeyDown(short,unsigned char,class GFxSpecialKeysState,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxInputEventsQueue::AddKeyDown(
        GFxInputEventsQueue *this,
        __int16 code,
        char ascii,
        struct GFxSpecialKeysState specialKeysState,
        unsigned __int8 keyboardIndex)
{
  GFxInputEventsQueue::AddKeyEvent(this, a2: code, a3: ascii, a4: 0, a5: true, a6: specialKeysState, a7: keyboardIndex);
}

//------------------------------------------------------------------------------
// Address: 0x100BD570
// Name: public: void GFxInputEventsQueue::AddKeyUp(short,unsigned char,class GFxSpecialKeysState,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxInputEventsQueue::AddKeyUp(
        GFxInputEventsQueue *this,
        __int16 code,
        char ascii,
        struct GFxSpecialKeysState specialKeysState,
        unsigned __int8 keyboardIndex)
{
  GFxInputEventsQueue::AddKeyEvent(this, a2: code, a3: ascii, a4: 0, a5: false, a6: specialKeysState, a7: keyboardIndex);
}

//------------------------------------------------------------------------------
// Address: 0x100BD590
// Name: public: void GFxInputEventsQueue::AddCharTyped(unsigned long,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxInputEventsQueue::AddCharTyped(GFxInputEventsQueue *this, unsigned int a2, unsigned __int8 a3)
{
  GFxInputEventsQueue::AddKeyEvent(this, a2: 0, a3: 0, a4: a2, a5: true, a6: (struct GFxSpecialKeysState)0x80, a7: a3);
}

//------------------------------------------------------------------------------
// Address: 0x100BD5B0
// Name: GetUrlStrGfx
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<CImagePacker,int> *__usercall GetUrlStrGfx@<eax>(_DWORD *a1@<edi>, CUtlMemory<CImagePacker,int> *a2@<esi>)
{
  const char *v2; // eax

  GString::GString(this: a2);
  v2 = (const char *)(*a1 & 0xFFFFFFFC);
  if ( (*(_DWORD *)v2 & 0x7FFFFFFFu) > 4
    && GString::CompareNoCase(a1: &v2[(*(_DWORD *)v2 & 0x7FFFFFFF) + 4], a2: ".swf") == 0 )
  {
    GString::Clear(this: (GString *)a2);
    GString::AppendString(this: a2, putf8str: (*a1 & 0xFFFFFFFC) + 8);
    GString::AppendString(this: a2, putf8str: (int)".gfx");
  }
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100BD620
// Name: public: void GFxMovieRoot::MemoryContextImpl::HeapLimit::Collect(class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::MemoryContextImpl::HeapLimit::Collect(
        GFxMovieRoot::MemoryContextImpl::HeapLimit *this,
        struct GMemoryHeap *a2)
{
  CMaterial *v3; // ecx

  v3 = *(CMaterial **)(*((_DWORD *)this + 1) + 20);
  if ( v3 != nullptr )
  {
    GFxTextAllocator::FlushTextFormatCache(this: v3);
    GFxTextAllocator::FlushParagraphFormatCache(this: *(CMaterial **)(*((_DWORD *)this + 1) + 20));
  }
  GASRefCountCollector::ForceEmergencyCollect(this: *(GASRefCountCollector **)(*((_DWORD *)this + 1) + 12));
  *((_DWORD *)this + 3) = a2->GetFootprint(this: a2);
}

//------------------------------------------------------------------------------
// Address: 0x100BD670
// Name: public: void GFxMovieRoot::RegisterAuxASClasses(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::RegisterAuxASClasses(ScaleformRenderer *this)
{
  int v2; // eax
  float v3; // ecx
  int v4; // eax
  int v5; // eax
  IShaderAPI *v6; // ebx
  int v7; // eax
  IShaderAPI *v8; // edi
  int v9; // [esp+8h] [ebp-Ch] BYREF
  char v10; // [esp+Ch] [ebp-8h]
  MaterialLock_t__ xmlstatea; // [esp+10h] [ebp-4h]

  v2 = *((_DWORD *)this + 2289);
  v3 = this->m_currentCxform.M_[3][1];
  v9 = v2;
  v10 = 8;
  v4 = (*(int (__thiscall **)(int, int))(*(_DWORD *)(LODWORD(v3) + 8) + 12))(a1: LODWORD(v3) + 8, a2: 28);
  xmlstatea.unused = v4;
  if ( v4 != 0 )
    (*(void (__thiscall **)(int, _DWORD, int *))(*(_DWORD *)v4 + 12))(a1: v4, a2: *((_DWORD *)this + 2289), a3: &v9);
  v5 = (*(int (__thiscall **)(int, int))(*(_DWORD *)(LODWORD(this->m_currentCxform.M_[3][1]) + 8) + 12))(
         a1: LODWORD(this->m_currentCxform.M_[3][1]) + 8,
         a2: 34);
  v6 = (IShaderAPI *)v5;
  if ( v5 != 0 )
    (*(void (__thiscall **)(int, _DWORD, int *))(*(_DWORD *)v5 + 12))(a1: v5, a2: *((_DWORD *)this + 2289), a3: &v9);
  v7 = (*(int (__thiscall **)(int, int))(*(_DWORD *)(LODWORD(this->m_currentCxform.M_[3][1]) + 8) + 12))(
         a1: LODWORD(this->m_currentCxform.M_[3][1]) + 8,
         a2: 35);
  v8 = (IShaderAPI *)v7;
  if ( v7 != 0 )
  {
    (*(void (__thiscall **)(int, _DWORD, int *))(*(_DWORD *)v7 + 24))(a1: v7, a2: *((_DWORD *)this + 2289), a3: &v9);
    GRefCountImpl::Release(this: v8);
  }
  if ( v6 != nullptr )
    GRefCountImpl::Release(this: v6);
  if ( xmlstatea.unused != 0 )
    GRefCountImpl::Release(this: (IShaderAPI *)xmlstatea.unused);
}

//------------------------------------------------------------------------------
// Address: 0x100BD740
// Name: public: class GFxSprite __near * GFxMovieRoot::GetLevelMovie(int)const
// Source: json
//------------------------------------------------------------------------------
struct GFxSprite *__thiscall GFxMovieRoot::GetLevelMovie(GFxMovieRoot *this, int level)
{
  unsigned int v2; // edx
  int v3; // eax
  _DWORD *v4; // esi
  _DWORD *i; // ecx

  v2 = *((_DWORD *)this + 10);
  v3 = 0;
  if ( v2 == 0 )
    return nullptr;
  v4 = *((_DWORD **)this + 9);
  for ( i = v4; *i != level; i += 2 )
  {
    if ( ++v3 >= v2 )
      return nullptr;
  }
  return (struct GFxSprite *)v4[2 * v3 + 1];
}

//------------------------------------------------------------------------------
// Address: 0x100BD780
// Name: public: class GFxMovieDefImpl __near * GFxMovieRoot::CreateImageMovieDef(class GFxImageResource __near *,bool,char const __near *,class GFxLoadStates __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::CreateImageMovieDef(
        ScaleformRenderer::FillStyle *this@<ecx>,
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pimageResource,
        bool a3,
        int a4,
        _PSINJECTDATA pls)
{
  unsigned int DataBytes; // ebx
  GFxLoadStates *v7; // eax
  struct GFxStateBag *v8; // ecx
  struct GFxStateBag *v9; // ecx
  GFxImageLoader *States; // eax
  int v11; // edi
  GMemoryHeap *v12; // ecx
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  int v14; // eax
  int v15; // eax
  struct GFxMovieDataDef *v16; // esi
  int (__thiscall *v17)(int, int, int *); // edx
  GFxMovieDefImpl *v18; // eax
  int v19; // [esp+Ch] [ebp-10h] BYREF
  int v20; // [esp+10h] [ebp-Ch]
  ScaleformRenderer::FillStyle *v21; // [esp+14h] [ebp-8h]
  GPtr<GFxImageLoader> plsRef; // [esp+18h] [ebp-4h]

  DataBytes = pls.DataBytes;
  v21 = this;
  plsRef.pObject = nullptr;
  if ( pls.DataBytes == 0 )
  {
    pls.DataBytes = 2;
    v7 = (GFxLoadStates *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 84, a3: &pls);
    if ( v7 != nullptr )
    {
      v8 = *((struct GFxStateBag **)this + 60);
      if ( v8 != nullptr )
        v9 = v8 + 2;
      else
        v9 = nullptr;
      States = (GFxImageLoader *)GFxLoadStates::GFxLoadStates(
                                   this: v7,
                                   a2: *(struct GFxLoaderImpl **)(*((_DWORD *)this + 13) + 20),
                                   a3: v9,
                                   a4: nullptr);
    }
    else
    {
      States = nullptr;
    }
    plsRef.pObject = States;
    DataBytes = (unsigned int)States;
  }
  if ( pimageResource != nullptr )
  {
    GFxMovieDataDef::CreateMovieFileKey(
      result: (CMemberFuncProxy1<CTexture_MultipleRenderTarget *,void (__thiscall CTexture_MultipleRenderTarget::*)(char const *),char const *,CFuncMemPolicyNone> *)&v19,
      a2: (char *)a4,
      modifyTime: 0,
      ppreprocessParams: nullptr,
      a5: nullptr,
      a6: nullptr);
    v11 = LODWORD(this->m_fillTexture.TextureMatrix.M_[1][1]);
    v12 = (GMemoryHeap *)v11;
    if ( v11 == 0 )
      v12 = GMemory::pGlobalHeap;
    Alloc_2 = v12->Alloc_2;
    pls.DataBytes = 2;
    v14 = (int)Alloc_2(this: v12, a2: 36u, a3: (const GAllocDebugInfo *)&pls);
    if ( v14 == 0
      || (v15 = GFxMovieDataDef::GFxMovieDataDef(
                  this: v14,
                  a2: (struct GFxResourceKey *)&v19,
                  a3: 2,
                  a4,
                  a5: v11,
                  a6: 0,
                  a7: 0),
          v16 = (struct GFxMovieDataDef *)v15,
          v15 == 0) )
    {
      if ( v19 != 0 )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v19 + 8))(a1: v19, a2: v20);
      if ( plsRef.pObject != nullptr )
        GRefCountImpl::Release(this: (IShaderAPI *)plsRef.pObject);
      return;
    }
    GFxMovieDataDef::LoadTaskData::InitImageFileMovieDef(
      this: *(CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)(v15 + 32),
      fileLength: 0,
      pimageResource,
      a4: a3);
    GFxLoadStates::SetRelativePathForDataDef(this: (GFxLoadStates *)DataBytes, a2: v16);
    v17 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v11 + 40);
    a4 = 2;
    v18 = (GFxMovieDefImpl *)v17(a1: v11, a2: 32, a3: &a4);
    if ( v18 != nullptr )
      GFxMovieDefImpl::GFxMovieDefImpl(
        this: v18,
        a2: (IShaderDevice *)v16,
        a3: *(IShaderDevice **)(DataBytes + 8),
        a4: *(IShaderDevice **)(DataBytes + 60),
        a5: 0,
        a6: *(struct GFxStateBagImpl **)(v21[5].m_style + 20),
        a7: (ExprNode *)v11,
        a8: true,
        a9: 0);
    GFxResource::Release(this: (IShaderDevice *)v16);
    if ( v19 != 0 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v19 + 8))(a1: v19, a2: v20);
  }
  if ( plsRef.pObject != nullptr )
    GRefCountImpl::Release(this: (IShaderAPI *)plsRef.pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100BD900
// Name: public: void GFxMovieRoot::ProcessLoadXML(class GFxLoadQueueEntry __near *,class GFxLoadStates __near *,class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxMovieRoot::ProcessLoadXML(ScaleformRenderer *this, unsigned int pentry, _PSINJECTDATA pls)
{
  void *result; // eax
  void *v5; // esi
  const struct GASEnvironment *v6; // eax
  int *v7; // ebx
  int v8; // esi
  const struct GASEnvironment *v9; // edi
  struct GASObject *v10; // eax
  void *v11; // esi
  int v12; // [esp+10h] [ebp-Ch]
  int v13; // [esp+14h] [ebp-8h]
  CP4Factory v14[4]; // [esp+18h] [ebp-4h] BYREF

  result = (void *)GString::GetLength(this: (GString *)(pentry + 12));
  if ( result != nullptr )
  {
    GString::GString(result: (CImagePacker *)(pentry + 12));
    GString::GString(result: *(CImagePacker **)&pls.InjectionPoint);
    GString::GString(this: (CUtlMemory<CImagePacker,int> *)v14);
    GFxLoadStates::BuildURL(result: v14);
    GString::GString(
      this: (GString *)&pls.InjectionPoint,
      a2: (const char *)((*(_DWORD *)&v14[0].m_bDummyMode & 0xFFFFFFFC) + 8));
    (*(void (__thiscall **)(_DWORD, unsigned __int16 *, _DWORD))(**(_DWORD **)(pentry + 80) + 4))(
      a1: *(_DWORD *)(pentry + 80),
      a2: &pls.InjectionPoint,
      a3: *(_DWORD *)(*(_DWORD *)(pls.DataBytes + 8) + 8));
    v5 = (void *)(*(_DWORD *)&pls.InjectionPoint & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((*(_DWORD *)&pls.InjectionPoint & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
    v6 = (const struct GASEnvironment *)(*(int (__thiscall **)(GRenderer::BlendType *))(*this->m_blendModeStack.Data.Data
                                                                                      + 112))(a1: this->m_blendModeStack.Data.Data);
    v7 = *(int **)(pentry + 80);
    v8 = *v7;
    v9 = v6;
    v10 = GASValue::ToObject(this: (GASValue *)(pentry + 64), a2: v6);
    (*(void (__thiscall **)(int *, const struct GASEnvironment *, struct GASObject *))(v8 + 8))(a1: v7, a2: v9, a3: v10);
    v11 = (void *)(*(_DWORD *)&v14[0].m_bDummyMode & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(
           Addend: (volatile LONG *)((*(_DWORD *)&v14[0].m_bDummyMode & 0xFFFFFFFC) + 4),
           Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v13 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)(v13 & 0xFFFFFFFC));
    result = (void *)(InterlockedExchangeAdd(Addend: (volatile LONG *)((v12 & 0xFFFFFFFC) + 4), Value: -1) - 1);
    if ( result == nullptr )
      return ((void *(__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
               a1: GMemory::pGlobalHeap,
               a2: v12 & 0xFFFFFFFC);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BDA40
// Name: public: void GFxMovieRoot::ProcessLoadCSS(class GFxLoadQueueEntry __near *,class GFxLoadStates __near *,class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxMovieRoot::ProcessLoadCSS(ScaleformRenderer *this, unsigned int pentry, _PSINJECTDATA pls)
{
  void *result; // eax
  void *v5; // esi
  const struct GASEnvironment *v6; // eax
  int *v7; // ebx
  int v8; // esi
  const struct GASEnvironment *v9; // edi
  struct GASObject *v10; // eax
  void *v11; // esi
  int v12; // [esp+10h] [ebp-Ch]
  int v13; // [esp+14h] [ebp-8h]
  CP4Factory v14[4]; // [esp+18h] [ebp-4h] BYREF

  result = (void *)GString::GetLength(this: (GString *)(pentry + 12));
  if ( result != nullptr )
  {
    GString::GString(result: (CImagePacker *)(pentry + 12));
    GString::GString(result: *(CImagePacker **)&pls.InjectionPoint);
    GString::GString(this: (CUtlMemory<CImagePacker,int> *)v14);
    GFxLoadStates::BuildURL(result: v14);
    GString::GString(
      this: (GString *)&pls.InjectionPoint,
      a2: (const char *)((*(_DWORD *)&v14[0].m_bDummyMode & 0xFFFFFFFC) + 8));
    (*(void (__thiscall **)(_DWORD, unsigned __int16 *, _DWORD))(**(_DWORD **)(pentry + 100) + 4))(
      a1: *(_DWORD *)(pentry + 100),
      a2: &pls.InjectionPoint,
      a3: *(_DWORD *)(*(_DWORD *)(pls.DataBytes + 8) + 8));
    v5 = (void *)(*(_DWORD *)&pls.InjectionPoint & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((*(_DWORD *)&pls.InjectionPoint & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
    v6 = (const struct GASEnvironment *)(*(int (__thiscall **)(GRenderer::BlendType *))(*this->m_blendModeStack.Data.Data
                                                                                      + 112))(a1: this->m_blendModeStack.Data.Data);
    v7 = *(int **)(pentry + 100);
    v8 = *v7;
    v9 = v6;
    v10 = GASValue::ToObject(this: (GASValue *)(pentry + 84), a2: v6);
    (*(void (__thiscall **)(int *, const struct GASEnvironment *, struct GASObject *))(v8 + 8))(a1: v7, a2: v9, a3: v10);
    v11 = (void *)(*(_DWORD *)&v14[0].m_bDummyMode & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(
           Addend: (volatile LONG *)((*(_DWORD *)&v14[0].m_bDummyMode & 0xFFFFFFFC) + 4),
           Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v13 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)(v13 & 0xFFFFFFFC));
    result = (void *)(InterlockedExchangeAdd(Addend: (volatile LONG *)((v12 & 0xFFFFFFFC) + 4), Value: -1) - 1);
    if ( result == nullptr )
      return ((void *(__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
               a1: GMemory::pGlobalHeap,
               a2: v12 & 0xFFFFFFFC);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BDB80
// Name: public: bool GFxMovieRoot::GetLevel0Path(class GString __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::GetLevel0Path(
        ScaleformRenderer::FillStyle *this,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *a2)
{
  const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(IMaterialInternal *),IMaterialInternal *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v2; // ecx
  char v3; // al

  if ( *((_DWORD *)this + 12) == 0
    || ((*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 13) + 48))(a1: *((_DWORD *)this + 13)),
        GString::operator=(this: a2),
        GFxURLBuilder::ExtractFilePath(ppath: v2),
        v3 == 0) )
  {
    GString::Clear(this: (GString *)a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BDBD0
// Name: public: struct GFxMovieRoot::ActionEntry __near * GFxMovieRoot::ActionQueueType::FindEntry(enum GFxActionPriority::Priority,struct GFxMovieRoot::ActionEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall GFxMovieRoot::ActionQueueType::FindEntry(_DWORD *this, int a2, int a3)
{
  int *result; // eax
  int v4; // edx

  result = (int *)*(this + 3 * a2);
  if ( result == nullptr )
    return nullptr;
  while ( 1 )
  {
    if ( result[1] == *(_DWORD *)(a3 + 4)
      && result[3] == *(_DWORD *)(a3 + 12)
      && result[2] == *(_DWORD *)(a3 + 8)
      && result[11] == *(_DWORD *)(a3 + 44)
      && result[8] == *(_DWORD *)(a3 + 32) )
    {
      v4 = result[4];
      if ( v4 == *(_DWORD *)(a3 + 16) && ((v4 & 0x20000) == 0 || *((_WORD *)result + 12) == *(_WORD *)(a3 + 24)) )
        break;
    }
    result = (int *)*result;
    if ( result == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BDC40
// Name: public: void GFxMovieRoot::ActionEntry::Execute(class GFxMovieRoot __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::ActionEntry::Execute(GMatrix3D *this, int a2)
{
  float v3; // ecx

  v3 = this->M_[0][2];
  if ( v3 != 0.0 && (*(_BYTE *)(LODWORD(v3) + 118) & 0x10) == 0 )
  {
    switch ( LODWORD(this->M_[0][1]) )
    {
      case 1:
        (*(void (__thiscall **)(float, _DWORD))(*(_DWORD *)LODWORD(v3) + 332))(
          a1: COERCE_FLOAT(LODWORD(v3)),
          a2: LODWORD(this->M_[0][3]));
        break;
      case 2:
        (*(void (__thiscall **)(float, float *))(*(_DWORD *)LODWORD(v3) + 336))(
          a1: COERCE_FLOAT(LODWORD(v3)),
          a2: this->M_[1]);
        break;
      case 3:
        (*(void (__thiscall **)(float, float *, float *))(*(_DWORD *)LODWORD(v3) + 340))(
          a1: COERCE_FLOAT(LODWORD(v3)),
          a2: this->M_[2],
          a3: this->M_[3]);
        break;
      case 4:
        (*(void (__thiscall **)(float, _DWORD, float *))(*(_DWORD *)LODWORD(v3) + 344))(
          a1: COERCE_FLOAT(LODWORD(v3)),
          a2: LODWORD(this->M_[2][3]),
          a3: this->M_[3]);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BDCD0
// Name: public: virtual void GFxMovieRoot::GetStats(class GStatBag __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::GetStats(
        GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *this,
        GImage *pbag,
        int reset)
{
  GFxAmpViewStats::GetStats(this: *((GImageInfo **)this + 2577), bag: pbag);
  GFxAmpViewStats::GetStats(this: *((GImageInfo **)this + 2578), bag: pbag);
}

//------------------------------------------------------------------------------
// Address: 0x100BDD00
// Name: public: void GFxMovieRoot::AdvanceFrame(bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::AdvanceFrame(IDirect3DResource9 *this, int nextFrame, int framePos)
{
  IDirect3DResource9 *v3; // edi
  GFxAmpViewStats *v4; // ebx
  float v5; // ecx
  IDirect3DResource9_vtbl *v6; // esi
  unsigned __int8 v7; // cl
  HRESULT (__stdcall *QueryInterface)(IUnknown *, const _GUID *, void **); // ebx
  IDirect3DResource9 *v9; // esi
  float v10; // [esp+8h] [ebp-24h]
  float *v11; // [esp+Ch] [ebp-20h]
  GFxAmpViewStats *v12; // [esp+1Ch] [ebp-10h]

  v3 = this;
  v4 = *((GFxAmpViewStats **)this + 2577);
  v12 = v4;
  if ( v4 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v4, swdHandle: 1u, a3: 0xFu);
    GTimer::GetRawTicks(li: v5, a2: v10, a3: v11);
  }
  if ( ((int)v3[2333].__vftable & 0x80000) != 0 )
  {
    v3[2562].__vftable = nullptr;
    v3[2333].__vftable = (IDirect3DResource9_vtbl *)((int)v3[2333].__vftable & ~0x80000u);
    v6 = v3[2561].__vftable;
    if ( v6 == nullptr )
      goto LABEL_20;
    do
    {
      v7 = BYTE2(v6[2].SetPriority);
      v6[3].SetPriority = (unsigned int (__stdcall *)(IDirect3DResource9 *, unsigned int))((int)v6[3].SetPriority
                                                                                         & ~0x80000u);
      QueryInterface = v6[3].QueryInterface;
      LOBYTE(this) = ~(v7 >> 6);
      v6[3].Release = nullptr;
      if ( ((unsigned __int8)this & 1) != 0 )
      {
        if ( (*((int (__thiscall **)(IDirect3DResource9_vtbl *, _DWORD))v6->QueryInterface + 73))(a1: v6, a2: 0) == 1 )
          GFxASCharacter::AddToOptimizedPlayList(
            this: (int)v6,
            result: (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)v3);
        if ( (_BYTE)nextFrame != 0
          || (this = (IDirect3DResource9 *)((unsigned int)v6[3].SetPriority >> 18),
              ((int)v6[3].SetPriority & 0x40000) != 0) )
        {
          (*((void (__thiscall **)(IDirect3DResource9_vtbl *, int, int))v6->QueryInterface + 31))(
            a1: v6,
            a2: nextFrame,
            a3: framePos);
        }
      }
      v6 = (IDirect3DResource9_vtbl *)QueryInterface;
    }
    while ( QueryInterface != nullptr );
  }
  else
  {
    this = (IDirect3DResource9 *)v3[2562].__vftable;
    if ( this == nullptr )
      goto LABEL_20;
    do
    {
      v9 = *((IDirect3DResource9 **)this + 35);
      if ( (*((_BYTE *)this + 118) & 0x40) == 0 && ((_BYTE)nextFrame != 0 || (*(_DWORD *)(this + 40) & 0x40000) != 0) )
        ((void (__stdcall *)(int, int))this->__vftable[2].PreLoad)(a1: nextFrame, a2: framePos);
      this = v9;
    }
    while ( v9 != nullptr );
  }
  v4 = v12;
LABEL_20:
  if ( v4 != nullptr )
  {
    GTimer::GetRawTicks(li: *(float *)&this, a2: v10, a3: v11);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BDE60
// Name: public: virtual void GFxMovieRoot::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::Release(ScaleformRenderer *this)
{
  float Distortion; // ecx
  float v3; // edi
  VertexShaderHandle_t__ *v4; // [esp+0h] [ebp-4h]

  if ( InterlockedExchangeAdd(Addend: &this->RefCount, Value: -1) == 1 )
  {
    Distortion = this->S3DParams.Distortion;
    if ( Distortion != 0.0 )
      GRefCountImpl::AddRef(this: (IShaderDevice *)LODWORD(Distortion), a2: v4);
    v3 = this->S3DParams.Distortion;
    if ( this != nullptr )
      ((void (__thiscall *)(ScaleformRenderer *, int))this->dtr_GRefCountImplCore)(a1: this, a2: 1);
    if ( v3 != 0.0 )
      GRefCountImpl::Release(this: (IShaderAPI *)LODWORD(v3));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BDEA0
// Name: public: virtual bool GFxMovieRoot::AttachDisplayCallback(char const __near *,void (*)(void __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GFxMovieRoot::AttachDisplayCallback@<al>(
        int a1@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        int varname,
        int a5,
        void *userPtr)
{
  __vc_attributes::max_isAttribute *v7; // esi
  int v8; // eax
  char v9; // al
  char v10; // bl
  struct GFxASCharacter *v12; // eax
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *obj; // [esp+0h] [ebp-10h] BYREF

  if ( *(_DWORD *)(a1 + 48) == 0 )
    return 0;
  v7 = (__vc_attributes::max_isAttribute *)(*(int (__thiscall **)(_DWORD, int, int))(**(_DWORD **)(a1 + 48) + 112))(
                                             a1: *(_DWORD *)(a1 + 48),
                                             a2: a3,
                                             a3: a2);
  LOBYTE(obj) = 0;
  GASStringManager::CreateStringNode(this: *((const char **)v7[30].expression + 159));
  varname = v8;
  ++*(_DWORD *)(v8 + 8);
  GASEnvironment::GetVariable(this: v7, (const char *)&varname);
  v10 = v9;
  if ( (*(_DWORD *)(varname + 8))-- == 1 )
    GASStringNode::ReleaseNode();
  if ( v10 != 0 && (v12 = GASValue::ToASCharacter(this: &obj, a2: (const struct GASEnvironment *)v7)) != nullptr )
  {
    (*(void (__thiscall **)(struct GFxASCharacter *, int, void *))(*(_DWORD *)v12 + 272))(a1: v12, a2: a5, a3: userPtr);
    GASValue::~GASValue(this: &obj);
    return 1;
  }
  else
  {
    GASValue::~GASValue(this: &obj);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BDF50
// Name: public: void GFxMovieRoot::ClearIntervalTimer(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::ClearIntervalTimer(int a1@<ecx>, unsigned int timerId, GMemAddressStub *a3)
{
  unsigned int v3; // esi
  int v4; // edx
  int v5; // ecx
  int i; // eax

  v3 = *(_DWORD *)(a1 + 9380);
  v4 = 0;
  if ( v3 != 0 )
  {
    v5 = *(_DWORD *)(a1 + 9376);
    for ( i = v5; *(_DWORD *)i == 0 || *(_DWORD *)(*(_DWORD *)i + 48) != timerId; i += 4 )
    {
      if ( ++v4 >= v3 )
        return;
    }
    GASIntervalTimer::Clear(this: *(GASIntervalTimer **)(v5 + 4 * v4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BDFA0
// Name: protected: void GFxMovieRoot::ResetMouseState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::ResetMouseState(ScaleformRenderer *this)
{
  this->m_glyphVertexBuffer[84].u = 0.0;
  this->m_glyphVertexBuffer[84].v = 0.0;
  *(float *)&this->m_glyphVertexBuffer[84].color.Raw = 0.0;
  this->m_glyphVertexBuffer[84].y = 0.0;
  this->m_glyphVertexBuffer[84].x = 0.0;
  LOBYTE(this->m_glyphVertexBuffer[85].x) &= 0xE0u;
  this->m_glyphVertexBuffer[86].u = 0.0;
  this->m_glyphVertexBuffer[86].x = 0.0;
  this->m_glyphVertexBuffer[85].v = 0.0;
  *(float *)&this->m_glyphVertexBuffer[86].color.Raw = 0.0;
  this->m_glyphVertexBuffer[86].y = 0.0;
  LOBYTE(this->m_glyphVertexBuffer[86].v) &= 0xE0u;
  this->m_glyphVertexBuffer[88].color.Raw = 0;
  this->m_glyphVertexBuffer[87].v = 0.0;
  this->m_glyphVertexBuffer[87].u = 0.0;
  this->m_glyphVertexBuffer[88].y = 0.0;
  this->m_glyphVertexBuffer[88].x = 0.0;
  LOBYTE(this->m_glyphVertexBuffer[88].u) &= 0xE0u;
  this->m_glyphVertexBuffer[90].y = 0.0;
  this->m_glyphVertexBuffer[89].u = 0.0;
  this->m_glyphVertexBuffer[89].color.Raw = 0;
  this->m_glyphVertexBuffer[90].x = 0.0;
  this->m_glyphVertexBuffer[89].v = 0.0;
  this->m_glyphVertexBuffer[90].color.Channels.Blue &= 0xE0u;
}

//------------------------------------------------------------------------------
// Address: 0x100BE040
// Name: private: void GFxMovieRoot::UpdateViewAndPerspective(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::UpdateViewAndPerspective(ScaleformRenderer *this)
{
  float EyeSeparationCm; // ecx
  int (__thiscall *v3)(_DWORD, int, int *); // eax
  GMatrix3D *v4; // eax
  float v5; // edi
  float v6; // ecx
  int (__thiscall *v7)(_DWORD, int, int *); // edx
  GMatrix3D *v8; // eax
  float v9; // edi
  IDirect3DDevice9 *i; // edi
  int v11; // ecx
  int v12; // [esp+20h] [ebp-4h] BYREF

  if ( LODWORD(this->m_viewportMatrix.M_[3][2]) == 0 )
  {
    EyeSeparationCm = this->S3DParams.EyeSeparationCm;
    v3 = *(int (__thiscall **)(_DWORD, int, int *))(*(_DWORD *)LODWORD(EyeSeparationCm) + 40);
    v12 = 322;
    v4 = (GMatrix3D *)v3(a1: LODWORD(EyeSeparationCm), a2: 64, a3: &v12);
    v5 = *(float *)&v4;
    if ( v4 != nullptr )
      GMatrix3D::SetIdentity(this: v4);
    else
      v5 = 0.0;
    this->m_viewportMatrix.M_[3][2] = v5;
  }
  if ( LODWORD(this->m_viewportMatrix.M_[3][1]) == 0 )
  {
    v6 = this->S3DParams.EyeSeparationCm;
    v7 = *(int (__thiscall **)(_DWORD, int, int *))(*(_DWORD *)LODWORD(v6) + 40);
    v12 = 322;
    v8 = (GMatrix3D *)v7(a1: LODWORD(v6), a2: 64, a3: &v12);
    v9 = *(float *)&v8;
    if ( v8 != nullptr )
      GMatrix3D::SetIdentity(this: v8);
    else
      v9 = 0.0;
    this->m_viewportMatrix.M_[3][1] = v9;
  }
  GRenderer::MakeViewAndPersp3D(result: (const CUtlMemory<unsigned char,int> *)&this->m_userMatrix.M_[1][2]);
  for ( i = nullptr; i < this->m_pDevice; i = (IDirect3DDevice9 *)((char *)i + 1) )
  {
    v11 = *(_DWORD *)(this->S3DDisplay + 8 * (_DWORD)i + 4);
    if ( v11 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(a1: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BE110
// Name: private: void GFxMovieRoot::Setup3DDisplay(class GFxDisplayContext __near &)
// Source: json
//------------------------------------------------------------------------------
_D3DADAPTER_IDENTIFIER9 *__thiscall GFxMovieRoot::Setup3DDisplay(
        const CUtlMemory<unsigned char,int> *this,
        _D3DADAPTER_IDENTIFIER9 *result)
{
  _D3DADAPTER_IDENTIFIER9 *v2; // edi
  int v3; // esi
  int v5; // ecx
  int (__thiscall *v6)(int, int, int *); // edx
  GMatrix3D *v7; // eax
  GMatrix3D *v8; // esi
  GMatrix3D *v9; // edi
  int v10; // ecx
  int (__thiscall *v11)(int, int, int *); // eax
  GMatrix3D *v12; // eax
  GMatrix3D *v13; // esi
  GMatrix3D *v14; // edi
  int v15; // ecx
  _D3DADAPTER_IDENTIFIER9 *v16; // eax
  int v17; // [esp+14h] [ebp-90h]
  int v18; // [esp+1Ch] [ebp-88h] BYREF
  GMatrix3D v19; // [esp+20h] [ebp-84h] BYREF
  GMatrix3D v20; // [esp+60h] [ebp-44h] BYREF

  v2 = result;
  v3 = *(_DWORD *)(*(_DWORD *)&result->Driver[72] + 12);
  v17 = v3;
  if ( *((_DWORD *)this + 51) == 0 || *((_DWORD *)this + 50) == 0 )
  {
    GMatrix3D::SetIdentity(this: &v19);
    GMatrix3D::SetIdentity(this: &v20);
    GRenderer::MakeViewAndPersp3D(result: this + 12);
    if ( *((_DWORD *)this + 51) == 0 )
    {
      v5 = *((_DWORD *)this + 8);
      v6 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v5 + 40);
      v18 = 322;
      v7 = (GMatrix3D *)v6(a1: v5, a2: 64, a3: &v18);
      v8 = v7;
      if ( v7 != nullptr )
      {
        GMatrix3D::SetIdentity(this: v7);
        v9 = v8;
      }
      else
      {
        v9 = nullptr;
      }
      *((_DWORD *)this + 51) = v9;
      *v9 = v19;
      v3 = v17;
      v2 = result;
    }
    if ( *((_DWORD *)this + 50) == 0 )
    {
      v10 = *((_DWORD *)this + 8);
      v11 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v10 + 40);
      v18 = 322;
      v12 = (GMatrix3D *)v11(a1: v10, a2: 64, a3: &v18);
      v13 = v12;
      if ( v12 != nullptr )
      {
        GMatrix3D::SetIdentity(this: v12);
        v14 = v13;
      }
      else
      {
        v14 = nullptr;
      }
      *((_DWORD *)this + 50) = v14;
      *v14 = v20;
      v3 = v17;
      v2 = result;
    }
  }
  *(_DWORD *)&v2->Driver[16] = *((_DWORD *)this + 51);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 88))(a1: v3, a2: *((_DWORD *)this + 51));
  v15 = *((_DWORD *)this + 50);
  *((_DWORD *)this + 57) = *((_DWORD *)this + 51);
  *(_DWORD *)&v2->Driver[12] = v15;
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 84))(a1: v3, a2: *((_DWORD *)this + 50));
  v16 = *((_D3DADAPTER_IDENTIFIER9 **)this + 50);
  *((_DWORD *)this + 56) = v16;
  return v16;
}

//------------------------------------------------------------------------------
// Address: 0x100BE2A0
// Name: public: virtual bool GFxMovieRoot::IsPaused(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxMovieRoot::IsPaused(GFxMovieRoot *this)
{
  return (*((_DWORD *)this + 2333) & 0x100000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BE2B0
// Name: public: virtual bool GFxMovieRoot::GetVariable(class GFxValue __near *,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::GetVariable(
        GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *a1@<ecx>,
        float a2@<edi>,
        unsigned int a3,
        int a4)
{
  GFxAmpViewStats *pContainer; // edi
  float v6; // ecx
  __vc_attributes::max_isAttribute *v7; // esi
  int v8; // eax
  char v9; // al
  bool v10; // zf
  float v11; // ecx
  float v12; // ecx
  float v13; // [esp-4h] [ebp-40h]
  float *v14; // [esp+0h] [ebp-3Ch]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *retVal; // [esp+20h] [ebp-1Ch] BYREF
  unsigned int v16; // [esp+30h] [ebp-Ch] BYREF
  unsigned int _CurrentState; // [esp+34h] [ebp-8h] BYREF
  char varname[4]; // [esp+38h] [ebp-4h] BYREF

  if ( a1[6].__vftable != nullptr && a3 != 0 )
  {
    v13 = a2;
    pContainer = (GFxAmpViewStats *)a1[1288].pContainer;
    if ( pContainer != nullptr )
    {
      GFxAmpViewStats::PushCallstack(this: pContainer, swdHandle: 1u, a3: 0x18u);
      GTimer::GetRawTicks(li: v6, a2: v13, a3: v14);
    }
    _controlfp_s(&_CurrentState, newctrl: 0, mask: 0);
    _controlfp_s(_CurrentState: &v16, newctrl: 0x10000u, mask: 0x30000u);
    v7 = (__vc_attributes::max_isAttribute *)(*((int (__thiscall **)(GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>_vtbl *))a1[6].dtr_GSysAllocBase
                                              + 28))(a1: a1[6].__vftable);
    GASStringManager::CreateStringNode(this: *((const char **)v7[30].expression + 159));
    *(_DWORD *)varname = v8;
    ++*(_DWORD *)(v8 + 8);
    LOBYTE(retVal) = 0;
    GASEnvironment::GetVariable(this: v7, varname);
    if ( v9 != 0 )
    {
      GFxMovieRoot::ASValue2GFxValue(this: a1);
      GASValue::~GASValue(this: &retVal);
      v10 = (*(_DWORD *)(*(_DWORD *)varname + 8))-- == 1;
      if ( v10 )
        GASStringNode::ReleaseNode();
      _controlfp_s(_CurrentState: &a3, newctrl: _CurrentState, mask: 0x30000u);
      if ( pContainer != nullptr )
      {
        GTimer::GetRawTicks(li: v11, a2: v13, a3: v14);
        GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
      }
    }
    else
    {
      GASValue::~GASValue(this: &retVal);
      v10 = (*(_DWORD *)(*(_DWORD *)varname + 8))-- == 1;
      if ( v10 )
        GASStringNode::ReleaseNode();
      _controlfp_s(_CurrentState: &a3, newctrl: _CurrentState, mask: 0x30000u);
      if ( pContainer != nullptr )
      {
        GTimer::GetRawTicks(li: v12, a2: v13, a3: v14);
        GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BE420
// Name: public: virtual unsigned int GFxMovieRoot::GetVariableArraySize(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge GFxMovieRoot::GetVariableArraySize@<eax>(
        GFxMovieRoot *this@<ecx>,
        float a2@<edi>,
        const char *a3)
{
  IInputSystem_vtbl *v4; // ebx
  GFxAmpViewStats *v6; // edi
  float v7; // ecx
  IInputSystem_vtbl *v8; // eax
  int v9; // edx
  int v10; // ecx
  int (__thiscall *v11)(int); // edx
  __vc_attributes::max_isAttribute *v12; // esi
  int v13; // eax
  float v14; // eax
  bool v15; // zf
  float v16; // ecx
  float v17; // [esp-4h] [ebp-38h]
  float *v18; // [esp+0h] [ebp-34h]
  IInputSystem v19; // [esp+8h] [ebp-2Ch]
  int v20; // [esp+Ch] [ebp-28h]
  GFxAmpViewStats *v21; // [esp+10h] [ebp-24h]
  int v22; // [esp+14h] [ebp-20h]
  int v23; // [esp+18h] [ebp-1Ch]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *retVal; // [esp+20h] [ebp-14h] BYREF
  char varname[4]; // [esp+30h] [ebp-4h] BYREF

  v4 = nullptr;
  if ( *((_DWORD *)this + 12) == 0 )
    return 0;
  v17 = a2;
  v6 = *((GFxAmpViewStats **)this + 2577);
  v21 = v6;
  v22 = 1;
  v23 = 26;
  if ( v6 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v6, swdHandle: 1u, a3: 0x1Au);
    GTimer::GetRawTicks(li: v7, a2: v17, a3: v18);
    v4 = v8;
    v20 = v9;
  }
  else
  {
    v20 = 0;
  }
  v10 = *((_DWORD *)this + 12);
  v11 = *(int (__thiscall **)(int))(*(_DWORD *)v10 + 112);
  v19.__vftable = v4;
  v12 = (__vc_attributes::max_isAttribute *)v11(a1: v10);
  GASStringManager::CreateStringNode(this: *((const char **)v12[30].expression + 159));
  *(_DWORD *)varname = v13;
  ++*(_DWORD *)(v13 + 8);
  LOBYTE(retVal) = 0;
  GASEnvironment::GetVariable(this: v12, varname);
  GASValue::~GASValue(this: &retVal);
  v14 = *(float *)varname;
  v15 = (*(_DWORD *)(*(_DWORD *)varname + 8))-- == 1;
  v16 = v14;
  if ( v15 )
    GASStringNode::ReleaseNode();
  if ( v6 != nullptr )
  {
    GTimer::GetRawTicks(li: v16, a2: v17, a3: v18);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BE550
// Name: public: virtual bool GFxMovieRoot::IsAvailable(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __userpurge GFxMovieRoot::IsAvailable@<al>(int a1@<ecx>, int a2@<esi>, int a3)
{
  int v4; // esi
  int v5; // eax
  char IsAvailable; // bl
  int v8; // [esp+0h] [ebp-4h] BYREF

  if ( *(_DWORD *)(a1 + 48) == 0 )
    return 0;
  v4 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a1 + 48) + 112))(a1: *(_DWORD *)(a1 + 48), a2);
  GASStringManager::CreateStringNode(this: *(const char **)(*(_DWORD *)(v4 + 120) + 636));
  v8 = v5;
  ++*(_DWORD *)(v5 + 8);
  IsAvailable = GASEnvironment::IsAvailable(a1: v4, a2: &v8, a3: 0);
  if ( (*(_DWORD *)(v8 + 8))-- == 1 )
    GASStringNode::ReleaseNode();
  return IsAvailable;
}

//------------------------------------------------------------------------------
// Address: 0x100BE5B0
// Name: public: void GFxMovieRoot::OnMovieFocus(bool)
// Source: json
//------------------------------------------------------------------------------
ShaderAPIOcclusionQuery_t__ *__thiscall GFxMovieRoot::OnMovieFocus(
        ScaleformRenderer *this,
        const IDirect3DResource9 *result)
{
  GFxKeyboardState *p_color; // esi
  int i; // ebx
  ShaderAPIOcclusionQuery_t__ *v5; // eax
  IShaderAPI *v6; // esi

  if ( (_BYTE)result != 0 )
  {
    *((_DWORD *)this + 2333) |= 0x40000u;
  }
  else
  {
    p_color = (GFxKeyboardState *)&this->m_glyphVertexBuffer[91].color;
    for ( i = 4; i != 0; --i )
      GFxKeyboardState::ResetState(this: p_color++);
    GFxMovieRoot::ResetMouseState(this);
    *((_DWORD *)this + 2333) &= ~0x40000u;
  }
  v5 = (ShaderAPIOcclusionQuery_t__ *)((int (__thiscall *)(GList<GRendererEventHandler> *, int))this->Handlers.Root.pPrev->pRenderer)(
                                        a1: &this->Handlers,
                                        a2: 27);
  v6 = (IShaderAPI *)v5;
  if ( v5 != nullptr )
  {
    (*(void (__thiscall **)(ShaderAPIOcclusionQuery_t__ *, ScaleformRenderer *))(*(_DWORD *)v5 + 68))(a1: v5, a2: this);
    return GRefCountImpl::Release(this: v6);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100BE630
// Name: public: void GFxMovieRoot::DisplayTopmostLevelCharacters(class GFxDisplayContext __near &)const
// Source: json
//------------------------------------------------------------------------------
CMaterialDict *__userpurge GFxMovieRoot::DisplayTopmostLevelCharacters@<eax>(
        int a1@<ecx>,
        const CMaterialDict::MissingMaterial_t *a2@<edi>,
        int *context)
{
  int v3; // eax
  int v4; // ebx
  _DWORD *v5; // edi
  const CMaterialDict::MissingMaterial_t *v7; // [esp-4h] [ebp-A0h]
  int v9; // [esp+Ch] [ebp-90h]
  CMaterialDict *pom; // [esp+10h] [ebp-8Ch]
  unsigned int n; // [esp+14h] [ebp-88h]
  int v12; // [esp+18h] [ebp-84h]
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v13; // [esp+1Ch] [ebp-80h]
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v14; // [esp+1Ch] [ebp-80h]
  CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *v15; // [esp+1Ch] [ebp-80h]
  GMatrix3D pmat; // [esp+20h] [ebp-7Ch] BYREF
  _BYTE v17[32]; // [esp+60h] [ebp-3Ch] BYREF
  struct GMatrix2D v18; // [esp+80h] [ebp-1Ch] BYREF

  v3 = a1;
  pom = (CMaterialDict *)context[1];
  v9 = context[2];
  v4 = 0;
  v12 = *context;
  n = *(_DWORD *)(a1 + 9340);
  if ( n != 0 )
  {
    v7 = a2;
    while ( 1 )
    {
      v5 = *(_DWORD **)(*(_DWORD *)(v3 + 9336) + 4 * v4);
      v13 = (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v5[8];
      GMatrix2D::SetIdentity(result: v7);
      GFxCharacter::GetWorldMatrix(this: (GFxCharacter *)v13, pmat: (CMaterialDict *)&v18);
      v14 = (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v5[8];
      GRenderer::Cxform::Cxform();
      GFxCharacter::GetWorldCxform(
        this: v14,
        pcxform: (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v17);
      v15 = (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)v5[8];
      GMatrix3D::SetIdentity(this: &pmat);
      GFxCharacter::GetWorldMatrix3D(this: v15, (CMatQueuedMesh::MST_MeshInfo_t *)&pmat);
      context[1] = (int)&v18;
      *context = (int)v17;
      context[2] = (int)&pmat;
      (*(void (__thiscall **)(_DWORD *, int *))(*v5 + 116))(a1: v5, a2: context);
      if ( ++v4 >= n )
        break;
      v3 = a1;
    }
  }
  *context = v12;
  context[1] = (int)pom;
  context[2] = v9;
  return pom;
}

//------------------------------------------------------------------------------
// Address: 0x100BE750
// Name: public: void GFxMovieRoot::SetIMECandidateListStyle(class GFxIMECandidateListStyle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::SetIMECandidateListStyle(_DWORD *ecx0, IDirect3DVertexDeclaration9 *this)
{
  IDirect3DVertexDeclaration9 *v3; // edi
  int v4; // ecx
  int (__thiscall *v5)(int, int, int *); // eax
  IDirect3DVertexDeclaration9 *v6; // eax
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v3 = (IDirect3DVertexDeclaration9 *)*(ecx0 + 2564);
  if ( v3 != nullptr )
  {
    qmemcpy(v3, this, 0x2Cu);
  }
  else
  {
    v4 = *(ecx0 + 8);
    v5 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v4 + 40);
    v7 = 326;
    v6 = (IDirect3DVertexDeclaration9 *)v5(a1: v4, a2: 44, a3: &v7);
    if ( v6 != nullptr )
    {
      qmemcpy(v6, this, 0x2Cu);
      *(ecx0 + 2564) = v6;
    }
    else
    {
      *(ecx0 + 2564) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BE7C0
// Name: public: virtual bool GFxMovieRoot::GetDirtyFlag(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxMovieRoot::GetDirtyFlag(GFxMovieRoot *this, bool a2)
{
  bool result; // al

  result = (*((_DWORD *)this + 2333) & 0x400) != 0;
  if ( a2 )
    *((_DWORD *)this + 2333) &= ~0x400u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BE7F0
// Name: public: unsigned __int64 GFxMovieRoot::GetASTimerMs(void)const
// Source: json
//------------------------------------------------------------------------------
GPtr<IDirect3DPixelShader9> *__usercall GFxMovieRoot::GetASTimerMs@<eax>(int a1@<ecx>, float a2@<ebx>)
{
  IShaderAPI *v3; // eax
  float v4; // ecx
  _DWORD *v5; // esi
  float v6; // ecx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // kr00_8
  __int64 v9; // rax
  int v10; // edi
  void *v11; // esi
  unsigned __int64 v12; // rax
  int v14; // [esp-4h] [ebp-68h]
  float *v15; // [esp+0h] [ebp-64h]
  float *v16; // [esp+4h] [ebp-60h]
  unsigned __int64 timerMs; // [esp+8h] [ebp-5Ch] BYREF
  _BYTE v18[12]; // [esp+10h] [ebp-54h] BYREF
  void **v19; // [esp+1Ch] [ebp-48h]
  int v20; // [esp+28h] [ebp-3Ch]

  v3 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(a1 + 8) + 12))(a1: a1 + 8, a2: 36);
  v5 = &v3->__vftable;
  if ( v3 != nullptr )
  {
    GRefCountImpl::Release(this: v3);
    if ( v5[3] != 0 )
    {
      GString::GString(this: (CUtlMemory<CImagePacker,int> *)((char *)&timerMs + 4));
      (*(void (__thiscall **)(_DWORD *, const char *, char *))(*v5 + 4))(a1: v5, a2: "timer", a3: (char *)&timerMs + 4);
      v10 = _strtoui64(nptr: (const char *)((HIDWORD(timerMs) & 0xFFFFFFFC) + 8), endptr: nullptr, ibase: 10);
      v11 = (void *)(HIDWORD(timerMs) & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((HIDWORD(timerMs) & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
      LODWORD(v9) = v10;
    }
    else
    {
      GTimer::GetTicks(a1: v6, a2, a3: v15);
      v8 = v7 / 0x3E8 - *(_QWORD *)(a1 + 9360);
      HIDWORD(timerMs) = HIDWORD(v8);
      GLongFormatter::GLongFormatter(this: (GLongFormatter *)v18, a2: v8);
      GLongFormatter::Convert(this: (GLongFormatter *)v18);
      (*(void (__thiscall **)(_DWORD *, const char *, int))(*v5 + 8))(a1: v5, a2: "timer", a3: v20);
      v19 = &GString::InitStruct::`vftable';
      GFormatter::~GFormatter(this: (CMeshReader *)v18, a2: v14);
      LODWORD(v9) = v8;
    }
  }
  else
  {
    GTimer::GetTicks(a1: v4, a2: *(float *)&v15, a3: v16);
    return (GPtr<IDirect3DPixelShader9> *)(v12 / 0x3E8 - *(_QWORD *)(a1 + 9360));
  }
  return (GPtr<IDirect3DPixelShader9> *)v9;
}

//------------------------------------------------------------------------------
// Address: 0x100BE940
// Name: public: virtual void GFxMovieRoot::ForceCollectGarbage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::ForceCollectGarbage(ScaleformRenderer *this, GColor a2, bool a3)
{
  JUMPOUT(0x10096060);
}

//------------------------------------------------------------------------------
// Address: 0x100BE950
// Name: public: bool GFxMovieRoot::FindExportedResource(class GFxMovieDefImpl __near *,struct GFxResourceBindData __near *,class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxMovieRoot::FindExportedResource(
        GFxMovieRoot *this,
        struct GFxMovieDefImpl *a2,
        CMatQueuedIndexBuffer *result,
        const struct GString *a4)
{
  const struct GFxMovieDefImpl *v4; // ebx
  int v7; // esi
  char *v8; // edi
  struct GFxMovieDefImpl *v9; // ecx

  v4 = a2;
  if ( GFxMovieDefImpl::GetExportedResource(this: a2, result, a3: (unsigned int)a4, ignoreDef: 0) != 0 )
    return 1;
  v7 = *((_DWORD *)this + 15);
  v8 = (char *)this + 56;
  if ( (char *)v7 == v8 )
    return 0;
  while ( 1 )
  {
    v9 = *(struct GFxMovieDefImpl **)(v7 + 12);
    if ( v9 != a2 && GFxMovieDefImpl::DoesDirectlyImport(this: v9, a2: v4) != 0 )
    {
      if ( GFxMovieDefImpl::GetExportedResource(this: *(_DWORD **)(v7 + 12), result, a3: (unsigned int)a4, ignoreDef: 0) != 0 )
        break;
      v4 = *(const struct GFxMovieDefImpl **)(v7 + 12);
    }
    v7 = *(_DWORD *)(v7 + 4);
    if ( (char *)v7 == v8 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BE9D0
// Name: public: void GFxSwfEvent::Read(struct GFxStreamContext __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxSwfEvent::Read(GFxSwfEvent *this, _PSINJECTDATA *psc, unsigned int flags)
{
  unsigned int DataBytes; // edx
  unsigned int v5; // ecx
  int v6; // ebx
  int v7; // eax
  unsigned int v8; // ecx
  int v9; // eax
  unsigned int v10; // ebx
  unsigned __int8 v11; // dl
  struct GASActionBufferData *New; // eax
  IShaderAPI *v13; // ecx
  unsigned int result; // eax
  unsigned int v15; // edx
  int v16; // ecx
  __int64 v17; // [esp+14h] [ebp-8h]
  HWND__ *flagsa; // [esp+28h] [ebp+Ch]

  *(_DWORD *)this = flags;
  LOWORD(v17) = 0;
  *(_DWORD *)((char *)&v17 + 2) = 65280;
  *((_DWORD *)this + 1) = 0;
  *((_QWORD *)this + 1) = v17;
  if ( *(_DWORD *)&psc[1].InjectionPoint != 0 )
    ++psc[1].DataBytes;
  DataBytes = psc->DataBytes;
  *(_DWORD *)&psc[1].InjectionPoint = 0;
  v5 = psc[1].DataBytes;
  v6 = *(unsigned __int8 *)(DataBytes + v5);
  v7 = (*(unsigned __int8 *)(DataBytes + v5 + 1) | (*(unsigned __int16 *)(DataBytes + v5 + 2) << 8)) << 8;
  v8 = v5 + 4;
  v9 = v6 | v7;
  psc[1].DataBytes = v8;
  v10 = v9;
  if ( (*(_DWORD *)this & 0x20000) != 0 )
  {
    *(_DWORD *)&psc[1].InjectionPoint = 0;
    v11 = *(_BYTE *)(v8 + DataBytes);
    psc[1].DataBytes = v8 + 1;
    *((_WORD *)this + 4) = v11;
    v10 = v9 - 1;
  }
  New = GASActionBufferData::CreateNew();
  v13 = *((IShaderAPI **)this + 4);
  flagsa = (HWND__ *)New;
  if ( v13 != nullptr )
    GRefCountImpl::Release(this: v13);
  *((_DWORD *)this + 4) = flagsa;
  GASActionBufferData::Read(this: flagsa, (unsigned int)psc, eventLength: v10);
  result = *(_DWORD *)(*((_DWORD *)this + 4) + 12);
  if ( v10 != result )
  {
    if ( v10 <= result )
    {
      psc[1].DataBytes += v10 - result;
    }
    else
    {
      v15 = v10 - result;
      if ( v10 != result )
      {
        v16 = *(_DWORD *)&psc[1].InjectionPoint;
        result = psc[1].DataBytes;
        do
        {
          if ( v16 != 0 )
            ++result;
          v16 = 0;
          ++result;
          --v15;
        }
        while ( v15 != 0 );
        *(_DWORD *)&psc[1].InjectionPoint = 0;
        psc[1].DataBytes = result;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BEAC0
// Name: public: GFxPlaceObject::GFxPlaceObject(void)
// Source: json
//------------------------------------------------------------------------------
GFxPlaceObject *__thiscall GFxPlaceObject::GFxPlaceObject(GFxPlaceObject *this)
{
  *(_DWORD *)this = &GFxPlaceObject::`vftable';
  *((_BYTE *)this + 4) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BEAD0
// Name: public: virtual void GFxSetBackgroundColor::Execute(class GFxSprite __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxSetBackgroundColor::Execute(
        int this,
        const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),int,matrix3x4_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *result)
{
  int v3; // eax
  _DWORD *v4; // esi
  float v5; // [esp+14h] [ebp+8h]

  v3 = LODWORD(result[4].m_arg2.m_flMatVal[1][0]);
  if ( v3 == 0 )
  {
    v4 = (_DWORD *)((int (*)(void))result->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable[5].Release)();
    v3 = v4[2333] >> 17;
    if ( (v4[2333] & 0x20000) == 0 )
    {
      v5 = ((double (__thiscall *)(_DWORD *))*(_DWORD *)(*v4 + 176))(a1: v4) * 255.0;
      *(_BYTE *)(this + 7) = (int)(v5 + 0.5);
      v3 = (*(int (__thiscall **)(_DWORD *, _DWORD))(*v4 + 168))(a1: v4, a2: *(_DWORD *)(this + 4));
      v4[2333] |= 0x20000u;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100BEB60
// Name: bool GFx_ReadLoadVariables(class GFile __near *,class GString __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall GFx_ReadLoadVariables@<al>(int a1@<esi>, CUtlMemory<CImagePacker,int> a2)
{
  CImagePacker *m_pMemory; // ebx
  int v3; // eax
  int *m_nGrowSize; // edi
  int v6; // eax
  _BYTE *v7; // esi
  int v8; // eax
  int v9; // eax
  int i; // ecx
  int v11; // eax
  int j; // ecx
  void *v13; // esi

  m_pMemory = a2.m_pMemory;
  v3 = (*(int (__thiscall **)(CImagePacker *))(a2.m_pMemory->m_MaxLightmapWidth + 24))(a1: a2.m_pMemory);
  m_nGrowSize = (int *)a2.m_nGrowSize;
  *(_DWORD *)a2.m_nGrowSize = v3;
  if ( v3 == 0 )
    return 0;
  GString::GString(this: &a2);
  v6 = *m_nGrowSize;
  a2.m_nGrowSize = 2;
  v7 = (_BYTE *)((int (__thiscall *)(GMemoryHeap *, int, int *, int))GMemory::pGlobalHeap->Alloc_2)(
                  a1: GMemory::pGlobalHeap,
                  a2: v6,
                  a3: &a2.m_nGrowSize,
                  a4: a1);
  (*(void (__thiscall **)(CImagePacker *, _BYTE *, int))(m_pMemory->m_MaxLightmapWidth + 40))(
    a1: m_pMemory,
    a2: v7,
    a3: *m_nGrowSize);
  v8 = *m_nGrowSize;
  if ( *(_WORD *)v7 == 0xFEFF )
  {
    v9 = v8 / 2 - 1;
    for ( i = 0; i < v9; ++i )
      ;
  }
  else
  {
    if ( *(_WORD *)v7 != 0xFFFE )
    {
      if ( v8 > 2 && *v7 == 0xEF && v7[1] == 0xBB && v7[2] == 0xBF )
        GString::AppendString(this: &a2, putf8str: (int)(v7 + 3));
      else
        GString::AppendString(this: &a2, putf8str: (int)v7);
      goto LABEL_17;
    }
    v11 = v8 / 2 - 1;
    for ( j = 0; j < v11; ++j )
      *(_WORD *)&v7[2 * j + 2] = __ROL2__(*(_WORD *)&v7[2 * j + 2], 8);
  }
  GString::AppendString(this: &a2, pstr: (int)(v7 + 2));
LABEL_17:
  GASGlobalContext::Unescape(
    a1: (const char *)(((int)a2.m_pMemory & 0xFFFFFFFC) + 8),
    a2: *(_DWORD *)((int)a2.m_pMemory & 0xFFFFFFFC) & 0x7FFFFFFF,
    a3: (struct GString *)a2.m_nAllocationCount);
  ((void (__thiscall *)(GMemoryHeap *))GMemory::pGlobalHeap->Free)(a1: GMemory::pGlobalHeap);
  v13 = (void *)((int)a2.m_pMemory & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)a2.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v13);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BECA0
// Name: public: void GHashsetCachedEntry<class GFxTextFormatPtrWrapper<class GFxTextParagraphFormat>,struct GFxTextFormatPtrWrapper<class GFxTextParagraphFormat>::HashFunctor>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GHashsetCachedEntry<GFxTextFormatPtrWrapper<GFxTextParagraphFormat>,GFxTextFormatPtrWrapper<GFxTextParagraphFormat>::HashFunctor>::Clear(
        GList<GRendererEventHandler> *this)
{
  GRefCountNTSImpl *v2; // ecx

  v2 = *((GRefCountNTSImpl **)this + 2);
  if ( v2 != nullptr )
    GRefCountNTSImpl::Release(this: v2);
  this->Root.pPrev = (GRendererEventHandler *)-2;
}

//------------------------------------------------------------------------------
// Address: 0x100BEE50
// Name: public: virtual bool GFxLoadQueueEntryMT_LoadMovie::IsPreloadingFinished(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxLoadQueueEntryMT_LoadMovie::IsPreloadingFinished(GFxLoadQueueEntryMT_LoadMovie *this)
{
  return *(_DWORD *)(*((_DWORD *)this + 5) + 40) == 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BEE60
// Name: public: virtual bool GFxLoadQueueEntryMT_LoadXML::LoadFinished(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxLoadQueueEntryMT_LoadXML::LoadFinished(GFxLoadQueueEntryMT_LoadXML *this)
{
  const struct GASEnvironment *v3; // ebx
  int v4; // eax
  int *v5; // esi
  int v6; // edi
  struct GASObject *v7; // eax

  if ( *(_BYTE *)(*((_DWORD *)this + 4) + 104) != 0 )
  {
    if ( *(_DWORD *)(*((_DWORD *)this + 5) + 32) == 1 )
      return 1;
  }
  else if ( *(_DWORD *)(*((_DWORD *)this + 5) + 32) == 1 )
  {
    v3 = (const struct GASEnvironment *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*((_DWORD *)this + 3) + 48) + 112))(a1: *(_DWORD *)(*((_DWORD *)this + 3) + 48));
    v4 = *((_DWORD *)this + 4);
    v5 = *(int **)(v4 + 80);
    v6 = *v5;
    v7 = GASValue::ToObject(this: (GASValue *)(v4 + 64), a2: v3);
    (*(void (__thiscall **)(int *, const struct GASEnvironment *, struct GASObject *))(v6 + 8))(a1: v5, a2: v3, a3: v7);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BEEC0
// Name: public: virtual bool GFxLoadQueueEntryMT_LoadCSS::LoadFinished(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxLoadQueueEntryMT_LoadCSS::LoadFinished(GFxLoadQueueEntryMT_LoadCSS *this)
{
  const struct GASEnvironment *v3; // ebx
  int v4; // eax
  int *v5; // esi
  int v6; // edi
  struct GASObject *v7; // eax

  if ( *(_BYTE *)(*((_DWORD *)this + 4) + 104) != 0 )
  {
    if ( *(_DWORD *)(*((_DWORD *)this + 5) + 32) == 1 )
      return 1;
  }
  else if ( *(_DWORD *)(*((_DWORD *)this + 5) + 32) == 1 )
  {
    v3 = (const struct GASEnvironment *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*((_DWORD *)this + 3) + 48) + 112))(a1: *(_DWORD *)(*((_DWORD *)this + 3) + 48));
    v4 = *((_DWORD *)this + 4);
    v5 = *(int **)(v4 + 100);
    v6 = *v5;
    v7 = GASValue::ToObject(this: (GASValue *)(v4 + 84), a2: v3);
    (*(void (__thiscall **)(int *, const struct GASEnvironment *, struct GASObject *))(v6 + 8))(a1: v5, a2: v3, a3: v7);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BEF20
// Name: public: virtual bool GFxMovieRoot::MemoryContextImpl::HeapLimit::OnExceedLimit(class GMemoryHeap __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxMovieRoot::MemoryContextImpl::HeapLimit::OnExceedLimit(
        int this,
        ScaleformRenderTarget *result,
        unsigned int overLimit)
{
  unsigned int v5; // eax
  GTexture::ChangeHandler *v6; // eax
  CMaterial *v7; // ecx
  int v8; // eax
  unsigned int v9; // ecx
  GTexture::ChangeHandler *v10; // eax
  GRendererNode *heapLimit; // [esp+Ch] [ebp-10h]
  unsigned int footprint; // [esp+10h] [ebp-Ch]
  __int64 v14; // [esp+14h] [ebp-8h]
  unsigned int newLimit; // [esp+24h] [ebp+8h]

  footprint = ((int (__thiscall *)(ScaleformRenderTarget *))result->__vftable[2].RemoveChangeHandler)(a1: result);
  heapLimit = result[1].pNext;
  v14 = (__int64)(*(float *)(this + 20) * (double)footprint);
  newLimit = (unsigned int)heapLimit + v14 + overLimit;
  if ( (int)(footprint - *(_DWORD *)(this + 12)) >= (int)v14 || (v5 = *(_DWORD *)(this + 8)) != 0 && newLimit > v5 )
  {
    v7 = *(CMaterial **)(*(_DWORD *)(this + 4) + 20);
    if ( v7 != nullptr )
    {
      GFxTextAllocator::FlushTextFormatCache(this: v7);
      GFxTextAllocator::FlushParagraphFormatCache(this: *(CMaterial **)(*(_DWORD *)(this + 4) + 20));
    }
    GASRefCountCollector::ForceEmergencyCollect(this: *(GASRefCountCollector **)(*(_DWORD *)(this + 4) + 12));
    v8 = ((int (__thiscall *)(ScaleformRenderTarget *))result->__vftable[2].RemoveChangeHandler)(a1: result);
    v9 = *(_DWORD *)(this + 8);
    *(_DWORD *)(this + 12) = v8;
    if ( v9 == 0 || newLimit <= v9 )
      return 1;
    if ( overLimit > footprint - v8 )
    {
      v10 = (GTexture::ChangeHandler *)((char *)heapLimit + v8 - footprint + overLimit);
      *(_DWORD *)(this + 16) = v10;
      result->RemoveChangeHandler(this: result, a2: v10);
      *(_DWORD *)(this + 16) = result[1].pNext;
      return 1;
    }
    v6 = *(GTexture::ChangeHandler **)(this + 16);
  }
  else
  {
    v6 = (GTexture::ChangeHandler *)((char *)heapLimit + v14 + overLimit);
  }
  result->RemoveChangeHandler(this: result, a2: v6);
  *(_DWORD *)(this + 16) = result[1].pNext;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BF030
// Name: public: void GFxMovieRoot::DragState::InitCenterDelta(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::DragState::InitCenterDelta(
        GFxMovieRoot::DragState *this@<ecx>,
        const CMaterialDict::MissingMaterial_t *a2@<edi>,
        bool a3)
{
  float *v3; // ebx
  int v4; // esi
  GFxCharacter *v5; // edi
  int v6; // eax
  int Perspective3D; // edi
  int View3D; // ebx
  CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *v9; // edi
  int v10; // eax
  const CMaterialDict::MissingMaterial_t *v11; // [esp-8h] [ebp-98h]
  int p[2]; // [esp+4h] [ebp-8Ch] BYREF
  int v13; // [esp+Ch] [ebp-84h]
  GFxMovieRoot::DragState *v14; // [esp+10h] [ebp-80h]
  CCountedStringPoolBase<unsigned int>::hash_item_t result; // [esp+14h] [ebp-7Ch] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v16; // [esp+5Ch] [ebp-34h] BYREF
  float v17; // [esp+70h] [ebp-20h]
  struct GMatrix2D v18; // [esp+74h] [ebp-1Ch] BYREF

  v3 = (float *)this;
  v14 = this;
  *((_BYTE *)this + 4) = a3;
  if ( !a3 )
  {
    GMatrix2D::SetIdentity(result: a2);
    v4 = *(_DWORD *)v3;
    v5 = *(GFxCharacter **)(*(_DWORD *)v3 + 32);
    if ( v5 != nullptr )
    {
      GMatrix2D::SetIdentity(result: v11);
      GFxCharacter::GetWorldMatrix(this: v5, pmat: (CMaterialDict *)&v18);
      *(float *)&v16.m_Memory.m_pMemory = v18.M_[0][0];
      *(float *)&v16.m_Memory.m_nAllocationCount = v18.M_[0][1];
      *(float *)&v16.m_Memory.m_nGrowSize = v18.M_[0][2];
      *(float *)&v16.m_Size = v18.M_[1][0];
      *(float *)&v16.m_pElements = v18.M_[1][1];
      v17 = v18.M_[1][2];
    }
    v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 84))(a1: v4);
    v13 = *(int *)(v6 + 2380);
    p[0] = *(int *)(v6 + 2376);
    p[1] = v13;
    GMatrix2D::TransformByInverse(this: &v16, &result, (int)p, a4: (int)v11);
    if ( GFxCharacter::Is3D(
           this: (_DWORD *)v4,
           result: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)1) != 0 )
    {
      Perspective3D = GFxCharacter::GetPerspective3D(this: (_DWORD *)v4, checkAncestors: true);
      View3D = GFxCharacter::GetView3D(this: (_DWORD *)v4, checkAncestors: true);
      if ( Perspective3D != 0 )
        *(_DWORD *)((*(int (__thiscall **)(int))(*(_DWORD *)v4 + 84))(a1: v4) + 224) = Perspective3D;
      if ( View3D != 0 )
        *(_DWORD *)((*(int (__thiscall **)(int))(*(_DWORD *)v4 + 84))(a1: v4) + 228) = View3D;
      v9 = *(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> **)(v4 + 32);
      GMatrix3D::SetIdentity(this: (GMatrix3D *)&result.nReferenceCount);
      GFxCharacter::GetWorldMatrix3D(this: v9, pmat: (CMatQueuedMesh::MST_MeshInfo_t *)&result.nReferenceCount);
      *(_DWORD *)((*(int (__thiscall **)(int))(*(_DWORD *)v4 + 84))(a1: v4) + 232) = &result.nReferenceCount;
      v10 = (*(int (__thiscall **)(int, CCountedStringPoolBase<unsigned int>::hash_item_t *))(*(_DWORD *)v4 + 84))(
              a1: v4,
              a2: &result);
      GScreenToWorld::GetWorldPoint(this: (CUtlBuffer *)(v10 + 208));
      v3 = (float *)v14;
    }
    v18.M_[0][2] = *(float *)(v4 + 76);
    v18.M_[1][2] = *(float *)(v4 + 88);
    v3[6] = v18.M_[0][2] - *(float *)&result.pString;
    v3[7] = v18.M_[1][2] - *(float *)&result.nNextElement;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF1A0
// Name: public: void GFxMovieRoot::UpdateViewport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::UpdateViewport(ScaleformRenderer *this)
{
  unsigned int Size; // edx
  double v3; // st7
  GRendererNode *pNext; // eax
  _RTL_CRITICAL_SECTION_DEBUG *DebugInfo; // ecx
  double v6; // st6
  int v7; // edi
  char *v8; // eax
  double v9; // st5
  float v10; // ecx
  float *v11; // eax
  double v12; // st5
  double v13; // st4
  double v14; // st3
  double v15; // st3
  double v16; // st5
  double v17; // rtt
  double v18; // st2
  double v19; // rt2
  double v20; // st6
  double v21; // st2
  double v22; // st5
  double v23; // st4
  double v24; // st3
  double v25; // st7
  double v26; // st6
  double v27; // st7
  double v28; // st4
  double v29; // st3
  double v30; // st6
  double v31; // st5
  double v32; // st5
  double v33; // st4
  double v34; // st5
  double v35; // st4
  float prevVisibleFrameRect; // [esp+4h] [ebp-50h]
  float prevVisibleFrameRect_4; // [esp+8h] [ebp-4Ch]
  float prevVisibleFrameRect_8; // [esp+Ch] [ebp-48h]
  float v39; // [esp+10h] [ebp-44h]
  float viewportRect; // [esp+1Ch] [ebp-38h]
  float viewportRecta; // [esp+1Ch] [ebp-38h]
  float viewportRect_4; // [esp+20h] [ebp-34h]
  float viewportRect_8; // [esp+24h] [ebp-30h]
  float v44; // [esp+28h] [ebp-2Ch]
  float v45; // [esp+28h] [ebp-2Ch]
  float prevPixelScale; // [esp+2Ch] [ebp-28h]
  float prevViewScaleY; // [esp+30h] [ebp-24h]
  float prevViewScaleX; // [esp+34h] [ebp-20h]
  float prevViewOffsetYa; // [esp+38h] [ebp-1Ch]
  float prevViewOffsetXa; // [esp+3Ch] [ebp-18h]
  int visibleWidthc; // [esp+40h] [ebp-14h]
  float visibleWidth; // [esp+40h] [ebp-14h]
  float visibleWidtha; // [esp+40h] [ebp-14h]
  float visibleWidthd; // [esp+40h] [ebp-14h]
  float visibleWidthe; // [esp+40h] [ebp-14h]
  float visibleWidthf; // [esp+40h] [ebp-14h]
  float visibleWidthg; // [esp+40h] [ebp-14h]
  float visibleWidthh; // [esp+40h] [ebp-14h]
  float visibleWidthi; // [esp+40h] [ebp-14h]
  float visibleWidthj; // [esp+40h] [ebp-14h]
  float visibleWidthk; // [esp+40h] [ebp-14h]
  float visibleWidthl; // [esp+40h] [ebp-14h]
  float visibleWidthm; // [esp+40h] [ebp-14h]
  float visibleWidthn; // [esp+40h] [ebp-14h]
  float visibleWidtho; // [esp+40h] [ebp-14h]
  float visibleWidthp; // [esp+40h] [ebp-14h]
  float visibleWidthq; // [esp+40h] [ebp-14h]
  float visibleWidthr; // [esp+40h] [ebp-14h]
  float visibleWidths; // [esp+40h] [ebp-14h]
  float visibleWidtht; // [esp+40h] [ebp-14h]
  float visibleWidthb; // [esp+40h] [ebp-14h]
  float visibleWidthu; // [esp+40h] [ebp-14h]
  float visibleWidthv; // [esp+40h] [ebp-14h]
  float visibleWidthw; // [esp+40h] [ebp-14h]
  float visibleWidthx; // [esp+40h] [ebp-14h]
  float v76; // [esp+44h] [ebp-10h]
  float v77; // [esp+44h] [ebp-10h]
  float v78; // [esp+44h] [ebp-10h]
  float v79; // [esp+44h] [ebp-10h]
  float v80; // [esp+44h] [ebp-10h]
  float v81; // [esp+48h] [ebp-Ch]
  float v82; // [esp+4Ch] [ebp-8h]
  float v83; // [esp+50h] [ebp-4h]

  Size = this->m_blendModeStack.Data.Size;
  prevVisibleFrameRect = this->m_userMatrix.M_[1][2];
  prevVisibleFrameRect_4 = this->m_viewportMatrix.M_[0][0];
  prevVisibleFrameRect_8 = this->m_viewportMatrix.M_[0][1];
  v39 = this->m_viewportMatrix.M_[0][2];
  prevViewOffsetXa = this->m_userMatrix.M_[0][1];
  prevViewOffsetYa = this->m_userMatrix.M_[0][2];
  prevViewScaleX = this->m_currentMatrix.M_[1][2];
  prevViewScaleY = this->m_userMatrix.M_[0][0];
  prevPixelScale = this->m_currentMatrix.M_[1][1];
  v3 = 1.0;
  if ( Size != 0 )
  {
    DebugInfo = this->m_texturesLock.cs.DebugInfo;
    pNext = this->m_renderTargets.pNext;
    v6 = (double)(int)pNext;
    v7 = (int)pNext + this->m_texturesLock.cs.LockCount;
    v8 = (char *)DebugInfo + this->m_texturesLock.cs.RecursionCount;
    viewportRect = v6 * 20.0;
    v9 = (double)(int)DebugInfo;
    v10 = this->m_userMatrix.M_[1][0];
    viewportRect_4 = v9 * 20.0;
    visibleWidthc = (int)v8;
    v11 = *(float **)(*(_DWORD *)(*(_DWORD *)(Size + 28) + 12) + 32);
    viewportRect_8 = (double)v7 * 20.0;
    v44 = (double)visibleWidthc * 20.0;
    v76 = viewportRect_8 - viewportRect;
    visibleWidth = v44 - viewportRect_4;
    v83 = v11[14] - v11[12];
    v82 = v11[15] - v11[13];
    v12 = 0.0;
    switch ( LODWORD(v10) )
    {
      case 0:
        v77 = this->m_currentMatrix.M_[0][2] * v76 * this->m_currentMatrix.M_[0][1];
        visibleWidtha = visibleWidth * this->m_currentMatrix.M_[0][1];
        v13 = v77;
        v14 = visibleWidtha;
        switch ( LODWORD(this->m_userMatrix.M_[1][1]) )
        {
          case 0:
            visibleWidthd = v83 * 0.5 - v13 * 0.5;
            visibleWidthe = visibleWidthd / 20.0;
            this->m_userMatrix.M_[1][2] = (float)(20 * (int)visibleWidthe);
            visibleWidthf = v82 * 0.5 - 0.5 * v14;
            visibleWidthg = visibleWidthf / 20.0;
            this->m_viewportMatrix.M_[0][0] = (float)(20 * (int)visibleWidthg);
            break;
          case 1:
            visibleWidthh = v83 * 0.5 - 0.5 * v13;
            visibleWidthi = visibleWidthh / 20.0;
            this->m_userMatrix.M_[1][2] = (float)(20 * (int)visibleWidthi);
            v17 = v14;
            v15 = 0.0;
            v16 = v17;
            this->m_viewportMatrix.M_[0][0] = 0.0;
            goto LABEL_10;
          case 2:
            visibleWidthj = v83 * 0.5 - 0.5 * v13;
            visibleWidthk = visibleWidthj / 20.0;
            v21 = (double)(20 * (int)visibleWidthk);
            goto LABEL_13;
          case 3:
            v15 = 0.0;
            v16 = visibleWidtha;
            this->m_userMatrix.M_[1][2] = 0.0;
            visibleWidthl = v82 * 0.5 - 0.5 * visibleWidtha;
            visibleWidthm = visibleWidthl / 20.0;
            v18 = (double)(20 * (int)visibleWidthm);
            goto LABEL_9;
          case 4:
            this->m_userMatrix.M_[1][2] = v83 - v13;
            visibleWidthn = v82 * 0.5 - 0.5 * v14;
            visibleWidtho = visibleWidthn / 20.0;
            this->m_viewportMatrix.M_[0][0] = (float)(20 * (int)visibleWidtho);
            break;
          case 5:
            v15 = 0.0;
            v16 = visibleWidtha;
            this->m_userMatrix.M_[1][2] = 0.0;
            this->m_viewportMatrix.M_[0][0] = 0.0;
            goto LABEL_10;
          case 6:
            this->m_userMatrix.M_[1][2] = v83 - v13;
            v15 = 0.0;
            v16 = visibleWidtha;
            this->m_viewportMatrix.M_[0][0] = 0.0;
            goto LABEL_10;
          case 7:
            v15 = 0.0;
            v16 = visibleWidtha;
            this->m_userMatrix.M_[1][2] = 0.0;
            v18 = v82 - visibleWidtha;
LABEL_9:
            this->m_viewportMatrix.M_[0][0] = v18;
LABEL_10:
            v19 = v15;
            v14 = v16;
            v12 = v19;
            break;
          case 8:
            v21 = v83 - v13;
LABEL_13:
            this->m_userMatrix.M_[1][2] = v21;
            this->m_viewportMatrix.M_[0][0] = v82 - v14;
            break;
          default:
            break;
        }
        this->m_viewportMatrix.M_[0][1] = v13 + this->m_userMatrix.M_[1][2];
        this->m_viewportMatrix.M_[0][2] = v14 + this->m_viewportMatrix.M_[0][0];
        this->m_userMatrix.M_[0][1] = this->m_userMatrix.M_[1][2] / 20.0;
        v20 = v12;
        this->m_userMatrix.M_[0][2] = this->m_viewportMatrix.M_[0][0] / 20.0;
        this->m_currentMatrix.M_[1][2] = this->m_currentMatrix.M_[0][2] * this->m_currentMatrix.M_[0][1];
        this->m_userMatrix.M_[0][0] = this->m_currentMatrix.M_[0][1];
        break;
      case 1:
      case 3:
        v81 = this->m_currentMatrix.M_[0][2] * v76;
        v22 = visibleWidth;
        v23 = v83;
        v24 = v82;
        if ( LODWORD(v10) == 1 && v22 / v24 > v81 / v23 || LODWORD(v10) == 3 && v22 / v24 < v81 / v23 )
        {
          visibleWidthp = v22 * v23 / v81;
          this->m_userMatrix.M_[1][2] = 0.0;
          this->m_viewportMatrix.M_[0][0] = v24 * 0.5 - 0.5 * visibleWidthp;
          this->m_viewportMatrix.M_[0][1] = v83 + this->m_userMatrix.M_[1][2];
          this->m_viewportMatrix.M_[0][2] = visibleWidthp + this->m_viewportMatrix.M_[0][0];
          this->m_userMatrix.M_[0][1] = 0.0;
          this->m_userMatrix.M_[0][2] = this->m_viewportMatrix.M_[0][0] / 20.0;
          if ( 0.0 == v76 )
            v25 = 0.0;
          else
            v25 = v83 / v76;
          v26 = v25;
          v27 = 0.0;
          visibleWidthq = v26;
          this->m_currentMatrix.M_[1][2] = visibleWidthq;
          this->m_userMatrix.M_[0][0] = visibleWidthq / this->m_currentMatrix.M_[0][2];
        }
        else
        {
          visibleWidthr = v81 * v24 / v22;
          this->m_userMatrix.M_[1][2] = v23 * 0.5 - 0.5 * visibleWidthr;
          this->m_viewportMatrix.M_[0][0] = 0.0;
          this->m_viewportMatrix.M_[0][1] = visibleWidthr + this->m_userMatrix.M_[1][2];
          this->m_viewportMatrix.M_[0][2] = v82 + this->m_viewportMatrix.M_[0][0];
          this->m_userMatrix.M_[0][1] = this->m_userMatrix.M_[1][2] / 20.0;
          this->m_userMatrix.M_[0][2] = 0.0;
          v27 = 0.0;
          if ( 0.0 == v22 )
          {
            this->m_userMatrix.M_[0][0] = 0.0;
            v30 = (float)0.0 * this->m_currentMatrix.M_[0][2];
          }
          else
          {
            visibleWidths = v82 / v22;
            this->m_userMatrix.M_[0][0] = visibleWidths;
            v30 = visibleWidths * this->m_currentMatrix.M_[0][2];
          }
          this->m_currentMatrix.M_[1][2] = v30;
        }
        v20 = v27;
        v3 = 1.0;
        break;
      case 2:
        v20 = 0.0;
        this->m_viewportMatrix.M_[0][0] = 0.0;
        this->m_userMatrix.M_[1][2] = 0.0;
        this->m_viewportMatrix.M_[0][1] = v83 + this->m_userMatrix.M_[1][2];
        this->m_viewportMatrix.M_[0][2] = v82 + this->m_viewportMatrix.M_[0][0];
        this->m_userMatrix.M_[0][2] = 0.0;
        this->m_userMatrix.M_[0][1] = 0.0;
        v31 = v76;
        if ( 0.0 == v76 )
        {
          v32 = 0.0;
        }
        else
        {
          v78 = this->m_viewportMatrix.M_[0][1] - this->m_userMatrix.M_[1][2];
          v32 = v78 / v31;
        }
        v33 = v32;
        v34 = 0.0;
        this->m_currentMatrix.M_[1][2] = v33;
        v35 = visibleWidth;
        if ( 0.0 != visibleWidth )
        {
          visibleWidtht = this->m_viewportMatrix.M_[0][2] - this->m_viewportMatrix.M_[0][0];
          v34 = visibleWidtht / v35;
        }
        this->m_userMatrix.M_[0][0] = v34;
        break;
      default:
        v20 = 0.0;
        break;
    }
    v28 = 0.004999999888241291;
    if ( v20 == this->m_userMatrix.M_[0][0] )
      v29 = 0.004999999888241291;
    else
      v29 = 1.0 / this->m_userMatrix.M_[0][0];
    if ( v20 != this->m_currentMatrix.M_[1][2] )
      v28 = 1.0 / this->m_currentMatrix.M_[1][2];
    v79 = v28;
    visibleWidthb = v29;
    if ( v79 > (double)visibleWidthb )
      visibleWidthb = v28;
    this->m_currentMatrix.M_[1][1] = visibleWidthb;
  }
  else
  {
    this->m_userMatrix.M_[0][2] = 0.0;
    this->m_userMatrix.M_[0][1] = 0.0;
    this->m_userMatrix.M_[0][0] = 1.0;
    this->m_currentMatrix.M_[1][2] = 1.0;
    this->m_currentMatrix.M_[1][1] = 1.0;
    v20 = 0.0;
  }
  viewportRecta = -this->m_userMatrix.M_[1][2];
  v45 = -this->m_viewportMatrix.M_[0][0];
  this->m_viewportMatrix.M_[1][3] = v3;
  this->m_viewportMatrix.M_[2][0] = v20;
  this->m_viewportMatrix.M_[2][1] = viewportRecta;
  this->m_viewportMatrix.M_[2][2] = v20;
  this->m_viewportMatrix.M_[2][3] = v3;
  this->m_viewportMatrix.M_[3][0] = v45;
  visibleWidthu = this->m_viewportMatrix.M_[0][1] - this->m_userMatrix.M_[1][2];
  v80 = (double)this->m_texturesLock.cs.LockCount / visibleWidthu;
  visibleWidthv = this->m_viewportMatrix.M_[0][2] - this->m_viewportMatrix.M_[0][0];
  visibleWidthw = (double)this->m_texturesLock.cs.RecursionCount / visibleWidthv;
  this->m_viewportMatrix.M_[1][3] = v80 * this->m_viewportMatrix.M_[1][3];
  this->m_viewportMatrix.M_[2][0] = v80 * this->m_viewportMatrix.M_[2][0];
  this->m_viewportMatrix.M_[2][1] = v80 * this->m_viewportMatrix.M_[2][1];
  this->m_viewportMatrix.M_[2][2] = visibleWidthw * this->m_viewportMatrix.M_[2][2];
  this->m_viewportMatrix.M_[2][3] = visibleWidthw * this->m_viewportMatrix.M_[2][3];
  this->m_viewportMatrix.M_[3][0] = visibleWidthw * this->m_viewportMatrix.M_[3][0];
  visibleWidthx = (float)(int)this->m_texturesLock.cs.DebugInfo;
  this->m_viewportMatrix.M_[2][1] = (double)(int)this->m_renderTargets.pNext + this->m_viewportMatrix.M_[2][1];
  this->m_viewportMatrix.M_[3][0] = visibleWidthx + this->m_viewportMatrix.M_[3][0];
  if ( this->m_userMatrix.M_[1][2] != prevVisibleFrameRect
    || this->m_viewportMatrix.M_[0][1] != prevVisibleFrameRect_8
    || this->m_viewportMatrix.M_[0][0] != prevVisibleFrameRect_4
    || this->m_viewportMatrix.M_[0][2] != v39
    || this->m_userMatrix.M_[0][1] != prevViewOffsetXa
    || this->m_userMatrix.M_[0][2] != prevViewOffsetYa
    || this->m_currentMatrix.M_[1][2] != prevViewScaleX
    || this->m_userMatrix.M_[0][0] != prevViewScaleY
    || this->m_currentMatrix.M_[1][1] != prevPixelScale )
  {
    *((_DWORD *)this + 2333) |= 0x400u;
    GFxMovieRoot::UpdateViewAndPerspective(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF960
// Name: public: class GFxASCharacter __near * GFxMovieRoot::GetTopMostEntity(class GPoint<float> const __near &,unsigned int,bool,class GFxASCharacter const __near *)
// Source: json
//------------------------------------------------------------------------------
GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *__thiscall GFxMovieRoot::GetTopMostEntity(
        int this,
        GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *result,
        float a3,
        bool testAll,
        int ignoreMC)
{
  GFxAmpViewStats *v6; // ecx
  int v7; // edi
  float v8; // ecx
  double v9; // st7
  float v10; // ecx
  double v11; // st6
  double v12; // st7
  double v13; // st6
  double v14; // st6
  int v15; // ebx
  GFxCharacter **v16; // edi
  int i; // ebx
  int v18; // ecx
  const CMaterialDict::MissingMaterial_t *v20; // [esp+0h] [ebp-60h]
  int v21; // [esp+0h] [ebp-60h]
  float *v22; // [esp+4h] [ebp-5Ch]
  GFxAmpViewStats *v23; // [esp+14h] [ebp-4Ch]
  _DWORD v24[3]; // [esp+24h] [ebp-3Ch] BYREF
  bool v25; // [esp+30h] [ebp-30h]
  int p; // [esp+34h] [ebp-2Ch]
  float nsy; // [esp+38h] [ebp-28h]
  CCountedStringPoolBase<unsigned int>::hash_item_t v28; // [esp+3Ch] [ebp-24h] BYREF

  v6 = *(GFxAmpViewStats **)(this + 10308);
  v7 = 0;
  p = (int)result;
  v23 = v6;
  if ( v6 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v6, swdHandle: 1u, a3: 0xEu);
    GTimer::GetRawTicks(li: v8, a2: *(float *)&v20, a3: v22);
  }
  v9 = *(float *)&result->pContainer;
  v10 = a3;
  v11 = *(float *)(this + 132) * 20.0;
  v24[0] = this;
  v24[1] = ignoreMC;
  *(float *)&v24[2] = a3;
  *(float *)&v28.nNextElement = v11;
  v25 = testAll;
  v12 = v9 - *(float *)&v28.nNextElement;
  *(float *)&v28.nNextElement = *(float *)(this + 156) - *(float *)(this + 148);
  nsy = v12 / *(float *)&v28.nNextElement * 2.0 - 1.0;
  v13 = *(float *)&result->__vftable;
  *(float *)&v28.nNextElement = 20.0 * *(float *)(this + 128);
  v14 = v13 - *(float *)&v28.nNextElement;
  *(float *)&v28.nNextElement = *(float *)(this + 152) - *(float *)(this + 144);
  *(float *)(this + 208) = v14 / *(float *)&v28.nNextElement * 2.0 - 1.0;
  *(float *)(this + 212) = -nsy;
  v15 = *(_DWORD *)(this + 9340) - 1;
  if ( v15 < 0 )
  {
LABEL_6:
    for ( i = *(_DWORD *)(this + 40); i > 0; --i )
    {
      v18 = *(_DWORD *)(*(_DWORD *)(this + 36) + 8 * i - 4);
      v7 = (*(int (__thiscall **)(int, int, _DWORD *))(*(_DWORD *)v18 + 72))(a1: v18, a2: p, a3: v24);
      if ( v7 != 0 )
        break;
    }
  }
  else
  {
    while ( 1 )
    {
      v16 = *(GFxCharacter ***)(*(_DWORD *)(this + 9336) + 4 * v15);
      nsy = *((float *)v16 + 8);
      GMatrix2D::SetIdentity(result: v20);
      GFxCharacter::GetWorldMatrix(this: (GFxCharacter *)LODWORD(nsy), pmat: (CMaterialDict *)&v28.nReferenceCount);
      GMatrix2D::TransformByInverse(
        this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v28.nReferenceCount,
        result: &v28,
        p,
        a4: v21);
      v7 = (*((int (__thiscall **)(GFxCharacter **, CCountedStringPoolBase<unsigned int>::hash_item_t *, _DWORD *))*v16
            + 18))(
             a1: v16,
             a2: &v28,
             a3: v24);
      if ( v7 != 0 )
        break;
      if ( --v15 < 0 )
        goto LABEL_6;
    }
  }
  if ( v23 != nullptr )
  {
    GTimer::GetRawTicks(li: v10, a2: *(float *)&v20, a3: v22);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
  return (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x100BFAF0
// Name: public: virtual unsigned int GFxMovieRoot::HandleEvent(class GFxEvent const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxMovieRoot::HandleEvent(ISteamRemoteStorage *this, struct GFxIMEEvent *a2)
{
  int result; // eax
  GFxEvent::EventType Type; // eax
  int v6; // ecx
  const struct GFxEvent *p_IMEEvtType; // ebx
  int v8; // eax
  IShaderAPI *v9; // esi
  unsigned int v10; // ebx
  GFxEvent::EventType IMEEvtType; // eax
  GFxEvent::EventType v12; // eax
  double v13; // st7
  GFxEvent::EventType v14; // ecx
  GFxEvent::EventType v15; // ebx
  GFxEvent::EventType v16; // eax
  int v17; // eax
  IShaderAPI *v18; // ebx
  int v19; // esi
  char v20; // [esp-4h] [ebp-18h]
  float v21; // [esp+Ch] [ebp-8h] BYREF
  float v22; // [esp+10h] [ebp-4h]
  struct GFxIMEEvent *v23; // [esp+1Ch] [ebp+8h]
  float v24; // [esp+1Ch] [ebp+8h]
  float v25; // [esp+1Ch] [ebp+8h]
  float v26; // [esp+1Ch] [ebp+8h]
  float v27; // [esp+1Ch] [ebp+8h]
  float v28; // [esp+1Ch] [ebp+8h]
  float v29; // [esp+1Ch] [ebp+8h]
  float v30; // [esp+1Ch] [ebp+8h]
  float v31; // [esp+1Ch] [ebp+8h]

  if ( ((unsigned __int8 (__thiscall *)(ISteamRemoteStorage *))this->__vftable[2].GetSyncPlatforms)(a1: this) == 0 )
  {
    if ( a2->Type != SetFocus )
      return 0;
    goto LABEL_5;
  }
  Type = a2->Type;
  if ( a2->Type == SetFocus )
  {
LABEL_5:
    v6 = -4 - (_DWORD)a2;
    p_IMEEvtType = (const struct GFxEvent *)&a2->IMEEvtType;
    v23 = (struct GFxIMEEvent *)(this + 629);
    LODWORD(v22) = -4 - (_DWORD)a2;
    do
    {
      if ( LOBYTE(p_IMEEvtType->Type) != 0 )
      {
        GFxKeyboardState::SetKeyToggled(result: (_JOBOBJECT_BASIC_LIMIT_INFORMATION *)0x90);
        GFxKeyboardState::SetKeyToggled(result: (_JOBOBJECT_BASIC_LIMIT_INFORMATION *)0x14);
        GFxKeyboardState::SetKeyToggled(result: (_JOBOBJECT_BASIC_LIMIT_INFORMATION *)0x91);
        v6 = LODWORD(v22);
      }
      v23 = (struct GFxIMEEvent *)((char *)v23 + 1660);
      p_IMEEvtType = (const struct GFxEvent *)((char *)p_IMEEvtType + 1);
    }
    while ( (unsigned int)p_IMEEvtType + v6 < 4 );
    *((_DWORD *)this + 2333) |= 0x40000u;
    v8 = (*(int (__thiscall **)(ISteamRemoteStorage *, int))(*((_DWORD *)this + 2) + 12))(a1: this + 2, a2: 27);
    v9 = (IShaderAPI *)v8;
    if ( v8 != 0 )
    {
      (*(void (__thiscall **)(int, ISteamRemoteStorage *))(*(_DWORD *)v8 + 68))(a1: v8, a2: this);
      GRefCountImpl::Release(this: v9);
    }
    return 1;
  }
  if ( Type == KeyDown || Type == KeyUp )
  {
    v10 = BYTE1(a2[2].Type);
    if ( v10 < 4 && this + 415 * v10 != (ISteamRemoteStorage *)-2516 && LOBYTE(a2[2].Type) != 0 )
    {
      GFxKeyboardState::SetKeyToggled(result: (_JOBOBJECT_BASIC_LIMIT_INFORMATION *)0x90);
      GFxKeyboardState::SetKeyToggled(result: (_JOBOBJECT_BASIC_LIMIT_INFORMATION *)0x14);
      GFxKeyboardState::SetKeyToggled(result: (_JOBOBJECT_BASIC_LIMIT_INFORMATION *)0x91);
    }
  }
  switch ( a2->Type )
  {
    case MouseMove:
      IMEEvtType = a2[2].IMEEvtType;
      if ( (unsigned int)IMEEvtType >= *((_DWORD *)this + 625) )
        goto LABEL_42;
      v24 = *((float *)this + 30) * *(float *)&a2->IMEEvtType + *((float *)this + 32);
      v21 = v24 * 20.0;
      v25 = *((float *)this + 31) * *(float *)&a2[1].Type + *((float *)this + 33);
      v22 = 20.0 * v25;
      GFxInputEventsQueue::AddMouseMove(this: (float *)this + 77, a2: IMEEvtType, a3: &v21);
      return 3;
    case MouseDown:
      v12 = a2[2].IMEEvtType;
      if ( (unsigned int)v12 >= *((_DWORD *)this + 625) )
        goto LABEL_42;
      v20 = 0;
      v28 = *((float *)this + 30) * *(float *)&a2->IMEEvtType + *((float *)this + 32);
      v21 = v28 * 20.0;
      v29 = *((float *)this + 31) * *(float *)&a2[1].Type + *((float *)this + 33);
      v13 = 20.0 * v29;
      goto LABEL_23;
    case MouseUp:
      v12 = a2[2].IMEEvtType;
      if ( (unsigned int)v12 >= *((_DWORD *)this + 625) )
        goto LABEL_42;
      v20 = 0x80;
      v26 = *((float *)this + 30) * *(float *)&a2->IMEEvtType + *((float *)this + 32);
      v21 = v26 * 20.0;
      v27 = *((float *)this + 31) * *(float *)&a2[1].Type + *((float *)this + 33);
      v13 = 20.0 * v27;
LABEL_23:
      v14 = a2[2].Type;
      v22 = v13;
      GFxInputEventsQueue::AddMouseButtonEvent(this: (_DWORD *)this + 77, a2: v12, a3: &v21, a4: 1 << v14, a5: v20);
LABEL_24:
      result = 3;
      break;
    case MouseWheel:
      v15 = a2[2].IMEEvtType;
      if ( (unsigned int)v15 >= *((_DWORD *)this + 625) )
        goto LABEL_42;
      v30 = *((float *)this + 30) * *(float *)&a2->IMEEvtType + *((float *)this + 32);
      v21 = v30 * 20.0;
      v31 = *((float *)this + 31) * *(float *)&a2[1].Type + *((float *)this + 33);
      v22 = 20.0 * v31;
      GFxInputEventsQueue::AddMouseWheel(
        this: (_DWORD *)this + 77,
        a2: v15,
        a3: &v21,
        a4: (int)*(float *)&a2[1].IMEEvtType);
      result = 3;
      break;
    case KeyDown:
      if ( GFxMovieRoot::GetKeyboardState((char *)this, result: BYTE1(a2[2].Type)) != nullptr )
        GFxKeyboardState::SetKeyDown(result: (tagMETAHEADER *)a2->IMEEvtType);
      GFxInputEventsQueue::AddKeyDown(
        this: (GFxInputEventsQueue *)(this + 77),
        code: a2->IMEEvtType,
        ascii: a2[1].Type,
        specialKeysState: (struct GFxSpecialKeysState)a2[2].Type,
        keyboardIndex: BYTE1(a2[2].Type));
      v16 = a2[1].IMEEvtType;
      if ( (unsigned int)v16 < 0x20 || v16 == (IMEEvent|MouseMove|0x70) )
        goto LABEL_24;
      GFxInputEventsQueue::AddCharTyped(this: (GFxInputEventsQueue *)(this + 77), a2: v16, a3: BYTE1(a2[2].Type));
      result = 3;
      break;
    case KeyUp:
      if ( GFxMovieRoot::GetKeyboardState((char *)this, result: BYTE1(a2[2].Type)) != nullptr )
        GFxKeyboardState::SetKeyUp(result: (tagMETAHEADER *)a2->IMEEvtType);
      GFxInputEventsQueue::AddKeyUp(
        this: (GFxInputEventsQueue *)(this + 77),
        code: a2->IMEEvtType,
        ascii: a2[1].Type,
        specialKeysState: (struct GFxSpecialKeysState)a2[2].Type,
        keyboardIndex: BYTE1(a2[2].Type));
      return 3;
    case KillFocus:
      GFxMovieRoot::OnMovieFocus((ScaleformRenderer *)this, result: nullptr);
      goto LABEL_42;
    case CharEvent:
      GFxInputEventsQueue::AddCharTyped(this: (GFxInputEventsQueue *)(this + 77), a2: a2->IMEEvtType, a3: a2[1].Type);
      return 3;
    case IMEEvent:
      v17 = (*(int (__thiscall **)(ISteamRemoteStorage *, int))(*((_DWORD *)this + 2) + 12))(a1: this + 2, a2: 27);
      v18 = (IShaderAPI *)v17;
      if ( v17 == 0 )
        return GFxMovieRoot::HandleKoreanIME(this, a2);
      v19 = (*(int (__thiscall **)(int, ISteamRemoteStorage *, struct GFxIMEEvent *))(*(_DWORD *)v17 + 96))(
              a1: v17,
              a2: this,
              a3: a2);
      GRefCountImpl::Release(this: v18);
      return v19;
    default:
LABEL_42:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BFF60
// Name: public: virtual void GFxMovieRoot::NotifyMouseState(float,float,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
IDirect3DResource9 *__fastcall GFxMovieRoot::NotifyMouseState(
        int a1,
        int a2,
        IDirect3DResource9 *result,
        float lastButtons,
        unsigned int buttons,
        unsigned int mouseIndex)
{
  IDirect3DResource9 *v6; // eax
  _DWORD *v7; // ebx
  double v8; // st7
  unsigned int v9; // edx
  int v10; // edi
  float v11; // [esp+4h] [ebp-8h] BYREF
  float v12; // [esp+8h] [ebp-4h]
  float xa; // [esp+14h] [ebp+8h]
  float xb; // [esp+14h] [ebp+8h]
  int x; // [esp+14h] [ebp+8h]
  unsigned int lastButtonsa; // [esp+18h] [ebp+Ch]

  v6 = (IDirect3DResource9 *)a1;
  xa = *(float *)(a1 + 120) * *(float *)&result + *(float *)(a1 + 128);
  v11 = xa * 20.0;
  xb = *(float *)(a1 + 124) * lastButtons + *(float *)(a1 + 132);
  v12 = 20.0 * xb;
  if ( mouseIndex < *(_DWORD *)(a1 + 2500) )
  {
    v7 = (_DWORD *)(a1 + 308);
    if ( mouseIndex < 4 )
    {
      v8 = v11;
      *(_DWORD *)(a1 + 2348) |= 1 << mouseIndex;
      *(float *)&v7[2 * mouseIndex + 502] = v8;
      *(float *)&v7[2 * mouseIndex + 503] = v12;
    }
    v9 = *(_DWORD *)(a1 + 36 * mouseIndex + 2368);
    lastButtonsa = v9;
    v10 = 1;
    x = 16;
    while ( 1 )
    {
      v6 = (IDirect3DResource9 *)(buttons & v10);
      if ( (buttons & v10) == 0 || (v10 & v9) != 0 )
      {
        if ( (v9 & v10) != 0 && v6 == nullptr )
          v6 = (IDirect3DResource9 *)GFxInputEventsQueue::AddMouseButtonEvent(
                                       this: v7,
                                       a2: mouseIndex,
                                       a3: &v11,
                                       a4: v9 & v10,
                                       a5: 128);
      }
      else
      {
        v6 = (IDirect3DResource9 *)GFxInputEventsQueue::AddMouseButtonEvent(
                                     this: v7,
                                     a2: mouseIndex,
                                     a3: &v11,
                                     a4: buttons & v10,
                                     a5: 0);
      }
      v10 *= 2;
      if ( --x == 0 )
        break;
      v9 = lastButtonsa;
    }
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100C00D0
// Name: public: virtual bool GFxMovieRoot::HitTest(float,float,enum GFxMovieView::HitTestType,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxMovieRoot::HitTest(
        IDirect3DResource9 *this,
        const IDirect3DResource9 *x,
        float y,
        tagTEXTMETRICA *testCond,
        unsigned int controllerIdx)
{
  GFxAmpViewStats *v6; // ebx
  float v7; // ecx
  __int64 v8; // rax
  int v9; // eax
  char result; // al
  GFxCharacter *v11; // esi
  char v12; // al
  int (__thiscall *v13)(GFxCharacter *, CCountedStringPoolBase<unsigned int>::hash_item_t *, _DWORD *); // edx
  const CMaterialDict::MissingMaterial_t *v14; // [esp+0h] [ebp-7Ch]
  const CMaterialDict::MissingMaterial_t *v15; // [esp+0h] [ebp-7Ch]
  int v16; // [esp+0h] [ebp-7Ch]
  float *v17; // [esp+4h] [ebp-78h]
  _DWORD v18[3]; // [esp+Ch] [ebp-70h] BYREF
  char v19; // [esp+18h] [ebp-64h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> movieLocalBounds; // [esp+1Ch] [ebp-60h] BYREF
  float v21; // [esp+28h] [ebp-54h]
  int p[2]; // [esp+2Ch] [ebp-50h] BYREF
  __int64 v23; // [esp+34h] [ebp-48h]
  CCountedStringPoolBase<unsigned int>::hash_item_t v24; // [esp+4Ch] [ebp-30h] BYREF
  int my; // [esp+58h] [ebp-24h]
  int movieIndex; // [esp+5Ch] [ebp-20h]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v27; // [esp+60h] [ebp-1Ch] BYREF

  v6 = *((GFxAmpViewStats **)this + 2577);
  if ( v6 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v6, swdHandle: 1u, a3: 0x1Bu);
    GTimer::GetRawTicks(li: v7, a2: *(float *)&v14, a3: v17);
    v23 = v8;
  }
  else
  {
    v23 = 0;
  }
  *(float *)&movieIndex = *((float *)this + 30) * *(float *)&x + *((float *)this + 32);
  *(float *)&my = *((float *)this + 31) * y + *((float *)this + 33);
  *(float *)&my = *(float *)&my * 20.0;
  *(float *)&v24.nReferenceCount = *((float *)this + 39) - *((float *)this + 37);
  *(float *)&v24.nNextElement = (*(float *)&my / *(float *)&v24.nReferenceCount - 0.5) * 2.0;
  *(float *)&v24.nReferenceCount = 20.0 * *(float *)&movieIndex;
  *(float *)&movieIndex = *((float *)this + 38) - *((float *)this + 36);
  *((float *)this + 52) = (*(float *)&v24.nReferenceCount / *(float *)&movieIndex - 0.5) * 2.0;
  *((float *)this + 53) = -*(float *)&v24.nNextElement;
  v9 = *((_DWORD *)this + 10);
  movieIndex = v9;
  if ( v9 > 0 )
  {
    while ( 1 )
    {
      v11 = *(GFxCharacter **)(*((_DWORD *)this + 9) + 8 * v9 - 4);
      GMatrix2D::SetIdentity(result: v14);
      (*(void (__thiscall **)(GFxCharacter *, CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *, CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *))(*(_DWORD *)v11 + 52))(
        a1: v11,
        a2: &movieLocalBounds,
        a3: &v27);
      p[0] = *(int *)&v24.nReferenceCount;
      p[1] = my;
      GMatrix2D::SetIdentity(result: v15);
      GFxCharacter::GetWorldMatrix(this: v11, pmat: (CMaterialDict *)&v27);
      GMatrix2D::TransformByInverse(this: &v27, result: &v24, (int)p, a4: v16);
      if ( (*(unsigned __int8 (__thiscall **)(GFxCharacter *))(*(_DWORD *)v11 + 8))(a1: v11) != 0
        || *(float *)&movieLocalBounds.m_nGrowSize >= (double)*(float *)&v24.pString
        && *(float *)&movieLocalBounds.m_pMemory <= (double)*(float *)&v24.pString
        && v21 >= (double)*(float *)&v24.nNextElement
        && *(float *)&movieLocalBounds.m_nAllocationCount <= (double)*(float *)&v24.nNextElement )
      {
        break;
      }
LABEL_24:
      if ( --movieIndex <= 0 )
        goto LABEL_5;
      v9 = movieIndex;
    }
    switch ( (unsigned int)testCond )
    {
      case 0u:
        v12 = (*(int (__thiscall **)(GFxCharacter *, CCountedStringPoolBase<unsigned int>::hash_item_t *, _DWORD))(*(_DWORD *)v11 + 68))(
                a1: v11,
                a2: &v24,
                a3: 0);
        goto LABEL_16;
      case 1u:
        v12 = (*(int (__thiscall **)(GFxCharacter *, CCountedStringPoolBase<unsigned int>::hash_item_t *, int))(*(_DWORD *)v11 + 68))(
                a1: v11,
                a2: &v24,
                a3: 1);
        goto LABEL_16;
      case 2u:
        v13 = *(int (__thiscall **)(GFxCharacter *, CCountedStringPoolBase<unsigned int>::hash_item_t *, _DWORD *))(*(_DWORD *)v11 + 72);
        v18[2] = controllerIdx;
        v18[0] = this;
        v18[1] = 0;
        v19 = 0;
        if ( v13(a1: v11, a2: &v24, a3: v18) == 0 )
          goto LABEL_24;
        goto LABEL_17;
      case 3u:
        v12 = (*(int (__thiscall **)(GFxCharacter *, CCountedStringPoolBase<unsigned int>::hash_item_t *, int))(*(_DWORD *)v11 + 68))(
                a1: v11,
                a2: &v24,
                a3: 3);
LABEL_16:
        if ( v12 == 0 )
          goto LABEL_24;
LABEL_17:
        if ( v6 != nullptr )
        {
          GTimer::GetRawTicks(li: *(float *)&this, a2: *(float *)&v14, a3: v17);
          GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
        }
        result = 1;
        break;
      default:
        goto LABEL_24;
    }
  }
  else
  {
LABEL_5:
    if ( v6 != nullptr )
    {
      GTimer::GetRawTicks(li: *(float *)&this, a2: *(float *)&v14, a3: v17);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C0330
// Name: public: virtual bool GFxMovieRoot::GotoLabeledFrame(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::GotoLabeledFrame(
        _DWORD *a1@<ecx>,
        int a2@<edi>,
        void *label,
        GMemAddressStub *offset,
        const char *targetFrame,
        int a6)
{
  int v7; // eax
  IShaderAPI *v8; // eax
  int v9; // esi
  unsigned int targetFramea; // [esp+4h] [ebp-4h] BYREF

  if ( a1[12] != 0 )
  {
    v7 = a1[13];
    targetFramea = -1;
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD, void *, unsigned int *, _DWORD, int))(**(_DWORD **)(*(_DWORD *)(v7 + 28) + 12)
                                                                                        + 52))(
           a1: *(_DWORD *)(*(_DWORD *)(v7 + 28) + 12),
           a2: label,
           a3: &targetFramea,
           a4: 0,
           a5: a2) != 0 )
    {
      (*(void (__thiscall **)(_DWORD *, GMemAddressStub *))(*a1 + 16))(a1, a2: &offset[targetFramea]);
    }
    else
    {
      v8 = (IShaderAPI *)(*(int (__thiscall **)(_DWORD *, int))(a1[2] + 12))(a1: a1 + 2, a2: 4);
      if ( v8 != nullptr )
      {
        GRefCountImpl::Release(this: v8);
        v9 = (*(int (__thiscall **)(_DWORD *, int))(a1[2] + 12))(a1: a1 + 2, a2: 4);
        GFxLogBase<GFxLog>::LogScriptError(
          this: (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(v9 + 12),
          pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(v9 + 12),
          this_4: (int)"Error: MovieImpl::GotoLabeledFrame('%s') unknown label\n",
          this_8: (int)label);
        if ( v9 != 0 )
          GRefCountImpl::Release(this: (IShaderAPI *)v9);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C03E0
// Name: public: bool GASAutoTabSortFunctor::operator()(class GFxASCharacter const __near *,class GFxASCharacter const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __stdcall GASAutoTabSortFunctor::operator()(GFxCharacter *a1, GFxCharacter *a2)
{
  int v2; // eax
  int v3; // eax
  double v4; // st6
  double v5; // st4
  double v6; // st5
  double v7; // st4
  const CMaterialDict::MissingMaterial_t *v9; // [esp+0h] [ebp-70h]
  const CMaterialDict::MissingMaterial_t *v10; // [esp+0h] [ebp-70h]
  _BYTE v11[8]; // [esp+8h] [ebp-68h] BYREF
  float v12; // [esp+10h] [ebp-60h]
  float v13; // [esp+14h] [ebp-5Ch]
  float v14; // [esp+18h] [ebp-58h] BYREF
  float v15; // [esp+1Ch] [ebp-54h]
  float v16; // [esp+20h] [ebp-50h]
  float v17; // [esp+24h] [ebp-4Ch]
  float v18; // [esp+28h] [ebp-48h] BYREF
  float v19; // [esp+2Ch] [ebp-44h]
  float v20; // [esp+30h] [ebp-40h]
  float v21; // [esp+34h] [ebp-3Ch]
  float v22; // [esp+38h] [ebp-38h]
  struct GMatrix2D v23; // [esp+3Ch] [ebp-34h] BYREF
  struct GMatrix2D v24; // [esp+54h] [ebp-1Ch] BYREF

  GMatrix2D::SetIdentity(result: v9);
  GFxCharacter::GetLevelMatrix(this: a1, pmat: (CMaterialDict *)&v24);
  GMatrix2D::SetIdentity(result: v10);
  GFxCharacter::GetLevelMatrix(this: a2, pmat: (CMaterialDict *)&v23);
  v2 = (*(int (__thiscall **)(GFxCharacter *, _BYTE *))(*(_DWORD *)a1 + 244))(a1, a2: v11);
  v18 = 0.0;
  v19 = 0.0;
  v20 = 0.0;
  v21 = 0.0;
  GMatrix2D::EncloseTransform(a1: &v18, a2: v2);
  v3 = (*(int (__thiscall **)(GFxCharacter *, _BYTE *))(*(_DWORD *)a2 + 244))(a1: a2, a2: v11);
  v14 = 0.0;
  v15 = 0.0;
  v16 = 0.0;
  v17 = 0.0;
  GMatrix2D::EncloseTransform(a1: &v14, a2: v3);
  v12 = (v20 + v18) * 0.5;
  v4 = v21;
  v13 = (v21 + v19) * 0.5;
  v20 = (v16 + v14) * 0.5;
  v21 = 0.5 * (v17 + v15);
  v22 = v19 - v15;
  v5 = v22;
  if ( v22 < 0.0 )
    v5 = -v5;
  v22 = v5;
  if ( v22 <= 20.0 )
    goto LABEL_12;
  v22 = v4 - v17;
  v6 = v22;
  if ( v22 < 0.0 )
    v6 = -v6;
  v22 = v6;
  if ( v22 <= 20.0 )
    goto LABEL_12;
  v22 = v13 - v21;
  v7 = v22;
  if ( v22 < 0.0 )
    v7 = -v7;
  v22 = v7;
  if ( v22 <= 20.0 )
  {
LABEL_12:
    if ( v20 <= (double)v12 )
      return 0;
  }
  else if ( v13 >= (double)v21 )
  {
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C0590
// Name: public: class GFxSprite __near * GFxMovieRoot::GetModalClip(unsigned int)
// Source: json
//------------------------------------------------------------------------------
GRefCountNTSImpl *__thiscall GFxMovieRoot::GetModalClip(GFxMovieRoot *this, unsigned int a2)
{
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v3; // ecx
  GRefCountNTSImpl *v4; // eax
  GRefCountNTSImpl *v5; // esi

  v3 = *((CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)this
       + 13 * *((unsigned __int8 *)this + a2 + 10228)
       + 2354);
  if ( v3 == nullptr )
    return nullptr;
  GFxCharacterHandle::ResolveCharacter(this: v3, a2: this);
  v5 = v4;
  if ( v4 == nullptr )
    return nullptr;
  ++v4->RefCount;
  GRefCountNTSImpl::Release(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100C06F0
// Name: public: void GFxSetBackgroundColor::Read(class GFxLoadProcess __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSetBackgroundColor::Read(GFxSetBackgroundColor *this, struct GFxLoadProcess *a2)
{
  GFxStream *v3; // ecx

  v3 = *((GFxStream **)a2 + 201);
  if ( v3 == nullptr )
    v3 = (GFxStream *)((char *)a2 + 40);
  GFxStream::ReadRgb(this: v3, a2: (struct GColor *)&this->m_nUserID);
  GFxLogBase<GFxLoadProcess>::LogParse(
    this: (GArrayLH<GString,2,GArrayDefaultPolicy> *)BYTE1(this->m_nUserID),
    pfmt: (unsigned int)a2 + 20,
    a3: (int)"  SetBackgroundColor: (%d %d %d)\n",
    a4: BYTE2(this->m_nUserID));
}

//------------------------------------------------------------------------------
// Address: 0x100C0740
// Name: public: void GFxMouseState::UpdateState(struct GFxInputEventsQueue::QueueEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
HRESULT __userpurge GFxMouseState::UpdateState@<eax>(
        int a1@<ecx>,
        IDirect3DSwapChain9 *this,
        unsigned int qe,
        _D3DBACKBUFFER_TYPE a4,
        IDirect3DSurface9 **a5)
{
  int v6; // eax
  int v7; // ecx
  char v8; // dl
  char v9; // al
  float v11; // [esp+10h] [ebp-8h]

  v6 = *(_DWORD *)(a1 + 12);
  *(_BYTE *)(a1 + 32) |= 0x10u;
  *(_DWORD *)(a1 + 16) = v6;
  v7 = *((unsigned __int16 *)this + 6);
  if ( (_WORD)v7 != 0 )
  {
    v8 = *((_BYTE *)this + 15);
    if ( (v8 & 0x40) != 0 || v8 >= 0 || *((_WORD *)this + 6) == 0 )
      *(_DWORD *)(a1 + 12) = v6 | v7;
    else
      *(_DWORD *)(a1 + 12) = v6 & ~v7;
  }
  if ( (int)*((float *)this + 1) == (int)*(float *)(a1 + 20) && (int)*((float *)this + 2) == (int)*(float *)(a1 + 24) )
    v9 = *(_BYTE *)(a1 + 32) & 0xF7;
  else
    v9 = *(_BYTE *)(a1 + 32) | 8;
  *(_BYTE *)(a1 + 32) = v9;
  v11 = *((float *)this + 2);
  *(float *)(a1 + 20) = *((float *)this + 1);
  *(float *)(a1 + 24) = v11;
  return a1 + 20;
}

//------------------------------------------------------------------------------
// Address: 0x100C1600
// Name: public: void GFxMouseState::SetTopmostEntity(class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
_D3DDISPLAYMODE *__thiscall GFxMouseState::SetTopmostEntity(struct GWeakPtrProxy **this, _D3DDISPLAYMODE *result)
{
  _DWORD *v3; // eax
  bool v4; // zf
  struct GWeakPtrProxy *WeakProxy; // ebx
  _D3DDISPLAYMODE *v6; // eax
  char v7; // cl

  if ( *this != nullptr )
    ++(*this)->RefCount;
  v3 = *(this + 1);
  if ( v3 != nullptr )
  {
    v4 = (*v3)-- == 1;
    if ( v4 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
  }
  *(this + 1) = *this;
  *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ (2 * *((_BYTE *)this + 32))) & 2;
  if ( result != nullptr )
  {
    WeakProxy = GRefCountWeakSupportImpl::CreateWeakProxy(this: (GRefCountWeakSupportImpl *)result);
    v6 = (_D3DDISPLAYMODE *)*this;
    if ( *this != nullptr )
    {
      v4 = v6->Width-- == 1;
      if ( v4 )
        v6 = (_D3DDISPLAYMODE *)((int (__thiscall *)(GMemoryHeap *, _D3DDISPLAYMODE *))GMemory::pGlobalHeap->Free)(
                                  a1: GMemory::pGlobalHeap,
                                  a2: v6);
    }
    v7 = *((_BYTE *)this + 32) ^ (result == nullptr);
    *this = WeakProxy;
    *((_BYTE *)this + 32) ^= v7 & 1;
  }
  else
  {
    v6 = (_D3DDISPLAYMODE *)*this;
    if ( *this != nullptr )
    {
      v4 = v6->Width-- == 1;
      if ( v4 )
        v6 = (_D3DDISPLAYMODE *)((int (__thiscall *)(GMemoryHeap *, _D3DDISPLAYMODE *))GMemory::pGlobalHeap->Free)(
                                  a1: GMemory::pGlobalHeap,
                                  a2: v6);
    }
    *((_BYTE *)this + 32) ^= (*((_BYTE *)this + 32) ^ 1) & 1;
    *this = nullptr;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100C16B0
// Name: public: bool GFxMouseState::IsTopmostEntityChanged(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxMouseState::IsTopmostEntityChanged(GFxMouseState *this)
{
  _DWORD *v2; // eax
  GRefCountNTSImpl *v3; // edi
  _DWORD *v4; // eax
  GRefCountNTSImpl *v5; // esi
  bool v6; // bl
  bool v7; // zf

  v2 = *(_DWORD **)this;
  v3 = nullptr;
  if ( *(_DWORD *)this != 0 )
  {
    if ( v2[1] != 0 )
    {
      v3 = (GRefCountNTSImpl *)v2[1];
      if ( v3 != nullptr )
      {
        ++v3->RefCount;
        ++v3->RefCount;
        GRefCountNTSImpl::Release(this: v3);
      }
    }
    else
    {
      v7 = (*v2)-- == 1;
      if ( v7 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
      *(_DWORD *)this = 0;
    }
  }
  v4 = *((_DWORD **)this + 1);
  v5 = nullptr;
  if ( v4 != nullptr )
  {
    if ( v4[1] != 0 )
    {
      v5 = (GRefCountNTSImpl *)v4[1];
      if ( v5 != nullptr )
      {
        ++v5->RefCount;
        ++v5->RefCount;
        GRefCountNTSImpl::Release(this: v5);
      }
    }
    else
    {
      v7 = (*v4)-- == 1;
      if ( v7 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
      *((_DWORD *)this + 1) = 0;
    }
  }
  v6 = v3 != v5
    || v3 == nullptr && (*((_BYTE *)this + 32) & 1) == 0
    || v5 == nullptr && (*((_BYTE *)this + 32) & 2) == 0;
  if ( v5 != nullptr )
    GRefCountNTSImpl::Release(this: v5);
  if ( v3 != nullptr )
    GRefCountNTSImpl::Release(this: v3);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100C1770
// Name: public: GFxLoadQueueEntry::GFxLoadQueueEntry(class GString const __near &,enum GFxLoadQueueEntry::LoadMethod,bool,bool)
// Source: json
//------------------------------------------------------------------------------
GTextureImplNode *__thiscall GFxLoadQueueEntry::GFxLoadQueueEntry(
        GTextureImplNode *this,
        _DWORD *url,
        GRendererNode *a3,
        bool loadingVars,
        bool queitOpen)
{
  volatile int v6; // eax
  GFxCharacterHandle *v7; // edi
  int v9; // [esp+0h] [ebp-Ch]

  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&this->___u1);
  *(_DWORD *)&this->HandlerArrayFlag = 0;
  *((_BYTE *)this + 28) = 0;
  *((_BYTE *)this + 44) = 0;
  *((_BYTE *)this + 64) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_BYTE *)this + 84) = 0;
  *((_DWORD *)this + 25) = 0;
  if ( loadingVars )
    v6 = 4;
  else
    v6 = (*url & 0xFFFFFFFC) == -8;
  this->RefCount.Value = v6;
  v7 = *(GFxCharacterHandle **)&this->HandlerArrayFlag;
  if ( v7 != nullptr )
  {
    *v7 = (GFxCharacterHandle)((char *)*v7 - 1);
    if ( (int)*v7 <= 0 )
    {
      GFxCharacterHandle::~GFxCharacterHandle(this: v7);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
    }
  }
  *(_DWORD *)&this->HandlerArrayFlag = 0;
  this->pPrev = a3;
  this->UserHandle = (void *)-1;
  this->__vftable = nullptr;
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&this->___u1,
    src: (int)url,
    a3: v9);
  LOBYTE(this->pHandler) = queitOpen;
  *((_BYTE *)this + 104) = 0;
  *((_DWORD *)this + 15) = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C1810
// Name: public: GFxLoadQueueEntry::GFxLoadQueueEntry(int,class GString const __near &,enum GFxLoadQueueEntry::LoadMethod,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadQueueEntry::GFxLoadQueueEntry(
        GTextureImplNode *this,
        GTexture::ChangeHandler::EventType level,
        _DWORD *src,
        GRendererNode *a4,
        bool loadingVars,
        bool queitOpen)
{
  int v7; // eax
  GFxCharacterHandle *v8; // edi
  int v9; // [esp+0h] [ebp-Ch]

  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&this->___u1);
  *(_DWORD *)&this->HandlerArrayFlag = 0;
  *((_BYTE *)this + 28) = 0;
  *((_BYTE *)this + 44) = 0;
  *((_BYTE *)this + 64) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_BYTE *)this + 84) = 0;
  *((_DWORD *)this + 25) = 0;
  if ( loadingVars )
    v7 = 4;
  else
    v7 = (*src & 0xFFFFFFFC) == -8;
  this->RefCount.Value = v7 | 2;
  v8 = *(GFxCharacterHandle **)&this->HandlerArrayFlag;
  if ( v8 != nullptr )
  {
    *v8 = (GFxCharacterHandle)((char *)*v8 - 1);
    if ( (int)*v8 <= 0 )
    {
      GFxCharacterHandle::~GFxCharacterHandle(this: v8);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
    }
  }
  *(_DWORD *)&this->HandlerArrayFlag = 0;
  this->pPrev = a4;
  this->UserHandle = (void *)level;
  this->__vftable = nullptr;
  GString::operator=(
    this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&this->___u1,
    (int)src,
    a3: v9);
  *((_BYTE *)this + 104) = 0;
  LOBYTE(this->pHandler) = queitOpen;
  *((_DWORD *)this + 15) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100C18B0
// Name: public: GFxMoviePreloadTask::GFxMoviePreloadTask(class GFxMovieRoot __near *,class GString const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
GFxMoviePreloadTask *__thiscall GFxMoviePreloadTask::GFxMoviePreloadTask(
        GFxMoviePreloadTask *this,
        struct GFxMovieRoot *a2,
        CImagePacker *result,
        bool a4,
        bool a5)
{
  GFxLoadStates *v6; // esi
  struct GFxStateBag *v7; // eax
  GFxLoadStates *States; // esi
  IShaderAPI *v9; // ecx
  unsigned int v10; // eax
  GString *v11; // ecx
  const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(IMaterialInternal *),IMaterialInternal *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v12; // ecx
  char v13; // al
  CUtlMemory<CImagePacker,int> *UrlStrGfx; // eax
  void *v15; // esi
  int v17; // [esp+0h] [ebp-14h]
  int v18; // [esp+Ch] [ebp-8h] BYREF
  int v19; // [esp+10h] [ebp-4h] BYREF
  CImagePacker *v20; // [esp+20h] [ebp+Ch]

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *(_DWORD *)this = &GFxTask::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = 131073;
  *((_DWORD *)this + 3) = 0;
  *(_DWORD *)this = &GFxMoviePreloadTask::`vftable';
  *((_DWORD *)this + 4) = 0;
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)this + 2);
  GString::GString(result);
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)((char *)this + 32));
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  v19 = 2;
  v6 = (GFxLoadStates *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 84, a3: &v19);
  if ( v6 != nullptr )
  {
    v20 = *(CImagePacker **)(*((_DWORD *)a2 + 13) + 20);
    v7 = (struct GFxStateBag *)(**((int (__thiscall ***)(char *))a2 + 2))(a1: (char *)a2 + 8);
    States = GFxLoadStates::GFxLoadStates(this: v6, a2: (struct GFxLoaderImpl *)v20, a3: v7, a4: nullptr);
  }
  else
  {
    States = nullptr;
  }
  v9 = *((IShaderAPI **)this + 4);
  if ( v9 != nullptr )
    GRefCountImpl::Release(this: v9);
  *((_DWORD *)this + 4) = States;
  v10 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)a2 + 13) + 28) + 20) & 0xFFFEFFFC | 0x10000;
  *((_DWORD *)this + 5) = v10;
  if ( a5 )
    *((_DWORD *)this + 5) = v10 | 0x200000;
  if ( *((_DWORD *)a2 + 12) == 0 )
  {
    v11 = (GString *)((char *)this + 24);
LABEL_12:
    GString::Clear(this: v11);
    goto LABEL_13;
  }
  (*(void (__thiscall **)(_DWORD))(**((_DWORD **)a2 + 13) + 48))(a1: *((_DWORD *)a2 + 13));
  GString::operator=(this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)this + 24));
  GFxURLBuilder::ExtractFilePath(ppath: v12);
  if ( v13 == 0 )
  {
    v11 = (GString *)((char *)this + 24);
    goto LABEL_12;
  }
LABEL_13:
  if ( a4 )
  {
    UrlStrGfx = GetUrlStrGfx(a1: (_DWORD *)this + 7, a2: (CUtlMemory<CImagePacker,int> *)&v18);
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)this + 32),
      src: (int)UrlStrGfx,
      a3: v17);
    v15 = (void *)(v18 & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v18 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v15);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C1A00
// Name: public: virtual GFxMoviePreloadTask::~GFxMoviePreloadTask(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMoviePreloadTask::~GFxMoviePreloadTask(IShaderAPI *this)
{
  IShaderDevice *v2; // ecx
  volatile LONG *v3; // esi
  volatile LONG *v4; // esi
  volatile LONG *v5; // esi
  IShaderAPI *v6; // ecx

  v2 = *((IShaderDevice **)this + 9);
  if ( v2 != nullptr )
    GFxResource::Release(this: v2);
  v3 = (volatile LONG *)(*(_DWORD *)(this + 8) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v3 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
  v4 = (volatile LONG *)(*(_DWORD *)(this + 7) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v4 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v4);
  v5 = (volatile LONG *)(*(_DWORD *)(this + 6) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v5 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v5);
  v6 = *((IShaderAPI **)this + 4);
  if ( v6 != nullptr )
    GRefCountImpl::Release(this: v6);
  this->__vftable = (IShaderAPI_vtbl *)&GFxTask::`vftable';
  GRefCountImplCore::~GRefCountImplCore(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C1AC0
// Name: public: virtual void GFxMoviePreloadTask::Execute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMoviePreloadTask::Execute(GFxMoviePreloadTask *this)
{
  CImagePacker *v2; // edi
  struct GFxMovieDefImpl *Movie_LoadState; // eax
  IShaderDevice *v4; // ecx
  struct GFxMovieDefImpl *v5; // edi
  void *v6; // edi
  void *v7; // edi
  struct GFxMovieDefImpl *v8; // eax
  IShaderDevice *v9; // ecx
  struct GFxMovieDefImpl *v10; // edi
  void *v11; // edi
  void *v12; // edi
  CUtlMemory<CImagePacker,int> v13; // [esp-14h] [ebp-2Ch]
  CUtlMemory<CImagePacker,int> v14; // [esp-14h] [ebp-2Ch]
  struct GFxLoaderImpl::LoadStackItem *v15; // [esp+0h] [ebp-18h]
  unsigned int v16; // [esp+4h] [ebp-14h]
  int v17; // [esp+Ch] [ebp-Ch] BYREF
  int v18; // [esp+10h] [ebp-8h]
  int v19; // [esp+14h] [ebp-4h]

  v2 = (CImagePacker *)((char *)this + 32);
  if ( GString::GetLength(this: (GString *)this + 8) != 0 )
  {
    v17 = 3;
    GString::GString(result: v2);
    GString::GString(result: (CImagePacker *)((char *)this + 24));
    v13.m_nGrowSize = *((_DWORD *)this + 5);
    v13.m_nAllocationCount = (int)&v17;
    v13.m_pMemory = *((CImagePacker **)this + 4);
    Movie_LoadState = GFxLoaderImpl::CreateMovie_LoadState(a1: v13, a2: nullptr, a3: 0, a4: v15, a5: v16);
    v4 = *((IShaderDevice **)this + 9);
    v5 = Movie_LoadState;
    if ( v4 != nullptr )
      GFxResource::Release(this: v4);
    *((_DWORD *)this + 9) = v5;
    v6 = (void *)(v19 & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v19 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
    v7 = (void *)(v18 & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v18 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
  }
  if ( *((_DWORD *)this + 9) == 0 )
  {
    v17 = 3;
    GString::GString(result: (CImagePacker *)((char *)this + 28));
    GString::GString(result: (CImagePacker *)((char *)this + 24));
    v14.m_nGrowSize = *((_DWORD *)this + 5);
    v14.m_nAllocationCount = (int)&v17;
    v14.m_pMemory = *((CImagePacker **)this + 4);
    v8 = GFxLoaderImpl::CreateMovie_LoadState(a1: v14, a2: nullptr, a3: 0, a4: v15, a5: v16);
    v9 = *((IShaderDevice **)this + 9);
    v10 = v8;
    if ( v9 != nullptr )
      GFxResource::Release(this: v9);
    *((_DWORD *)this + 9) = v10;
    v11 = (void *)(v19 & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v19 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
    v12 = (void *)(v18 & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v18 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v12);
  }
  InterlockedExchange(Target: (volatile LONG *)this + 10, Value: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100C1C10
// Name: public: GFxLoadQueueEntry::~GFxLoadQueueEntry(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall GFxLoadQueueEntry::~GFxLoadQueueEntry(int this)
{
  IShaderAPI *v2; // ecx
  IShaderAPI *v3; // ecx
  GFxCharacterHandle *v4; // edi
  unsigned int v5; // esi
  long double result; // st7

  v2 = *(IShaderAPI **)(this + 100);
  if ( v2 != nullptr )
    GRefCountImpl::Release(this: v2);
  GASValue::~GASValue(this: (GASValue *)(this + 84));
  v3 = *(IShaderAPI **)(this + 80);
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  GASValue::~GASValue(this: (GASValue *)(this + 64));
  GASValue::~GASValue(this: (GASValue *)(this + 44));
  GASValue::~GASValue(this: (GASValue *)(this + 28));
  v4 = *(GFxCharacterHandle **)(this + 20);
  if ( v4 != nullptr )
  {
    *v4 = (GFxCharacterHandle)((char *)*v4 - 1);
    if ( (int)*v4 <= 0 )
    {
      GFxCharacterHandle::~GFxCharacterHandle(this: v4);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
    }
  }
  v5 = *(_DWORD *)(this + 12) & 0xFFFFFFFC;
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(v5 + 4), Value: -1) == 1 )
    return ((long double (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
             a1: GMemory::pGlobalHeap,
             a2: v5);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C1CA0
// Name: public: GFxLoadVarsTask::GFxLoadVarsTask(class GFxLoadStates __near *,class GString const __near &,class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
GFxLoadVarsTask *__thiscall GFxLoadVarsTask::GFxLoadVarsTask(
        GFxLoadVarsTask *this,
        IShaderDevice *a2,
        CImagePacker *result,
        CImagePacker *a4)
{
  VertexShaderHandle_t__ *v6; // [esp+0h] [ebp-Ch]

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *(_DWORD *)this = &GFxTask::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = 131073;
  *((_DWORD *)this + 3) = 0;
  *(_DWORD *)this = &GFxLoadVarsTask::`vftable';
  if ( a2 != nullptr )
    GRefCountImpl::AddRef(this: a2, a2: v6);
  *((_DWORD *)this + 4) = a2;
  GString::GString(result);
  GString::GString(result: a4);
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)((char *)this + 28));
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_BYTE *)this + 40) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C1D10
// Name: public: virtual GFxLoadVarsTask::~GFxLoadVarsTask(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadVarsTask::~GFxLoadVarsTask(IShaderAPI *this)
{
  volatile LONG *v2; // esi
  volatile LONG *v3; // esi
  volatile LONG *v4; // esi
  IShaderAPI *v5; // ecx

  v2 = (volatile LONG *)(*(_DWORD *)(this + 7) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v2 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  v3 = (volatile LONG *)(*(_DWORD *)(this + 6) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v3 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
  v4 = (volatile LONG *)(*(_DWORD *)(this + 5) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v4 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v4);
  v5 = *((IShaderAPI **)this + 4);
  if ( v5 != nullptr )
    GRefCountImpl::Release(this: v5);
  this->__vftable = (IShaderAPI_vtbl *)&GFxTask::`vftable';
  GRefCountImplCore::~GRefCountImplCore(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C1DD0
// Name: public: virtual void GFxLoadVarsTask::Execute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadVarsTask::Execute(GFxLoadVarsTask *this)
{
  CImagePacker *v2; // eax
  IShaderAPI *v3; // edi
  void *v4; // esi
  CUtlMemory<CImagePacker,int> v5; // [esp-Ch] [ebp-24h]
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h]
  CP4Factory result[4]; // [esp+14h] [ebp-4h] BYREF

  GString::GString(result: (CImagePacker *)((char *)this + 24));
  GString::GString(result: (CImagePacker *)((char *)this + 20));
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)result);
  GFxLoadStates::BuildURL(result);
  v2 = (CImagePacker *)GFxLoadStates::OpenFile(
                         this: *((GFxLoadStates **)this + 4),
                         a2: (const char *)((*(_DWORD *)&result[0].m_bDummyMode & 0xFFFFFFFC) + 8),
                         a3: 0);
  v3 = (IShaderAPI *)v2;
  if ( v2 != nullptr )
  {
    v5.m_nGrowSize = (int)this + 32;
    v5.m_nAllocationCount = (int)this + 28;
    v5.m_pMemory = v2;
    *((_BYTE *)this + 40) = GFx_ReadLoadVariables(a1: (int)this, a2: v5);
  }
  else
  {
    *((_BYTE *)this + 40) = 1;
  }
  InterlockedExchange(Target: (volatile LONG *)this + 9, Value: 1);
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  v4 = (void *)(*(_DWORD *)&result[0].m_bDummyMode & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(
         Addend: (volatile LONG *)((*(_DWORD *)&result[0].m_bDummyMode & 0xFFFFFFFC) + 4),
         Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v7 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)(v7 & 0xFFFFFFFC));
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v6 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)(v6 & 0xFFFFFFFC));
}

//------------------------------------------------------------------------------
// Address: 0x100C1ED0
// Name: public: GFxLoadXMLTask::GFxLoadXMLTask(class GFxLoadStates __near *,class GString const __near &,class GString const __near &,struct GFxLoadQueueEntry::XMLHolderType)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxLoadXMLTask::GFxLoadXMLTask(
        _DWORD *this,
        IShaderDevice *a2,
        CImagePacker *a3,
        CImagePacker *a4,
        GASValue a5,
        int a6,
        int a7,
        int a8,
        IShaderDevice *a9)
{
  IShaderAPI *v10; // ecx
  VertexShaderHandle_t__ *v12; // [esp+0h] [ebp-8h]

  *this = &GRefCountImplCore::`vftable';
  *this = &GFxTask::`vftable';
  *(this + 1) = 1;
  *(this + 2) = 131073;
  *(this + 3) = 0;
  *this = &GFxLoadXMLTask::`vftable';
  if ( a2 != nullptr )
    GRefCountImpl::AddRef(this: a2, a2: v12);
  *(this + 4) = a2;
  GString::GString(result: a3);
  GString::GString(result: a4);
  v10 = (IShaderAPI *)a9;
  if ( a9 != nullptr )
  {
    GRefCountImpl::AddRef(this: a9, a2: v12);
    v10 = (IShaderAPI *)a9;
  }
  *(this + 7) = v10;
  *(this + 8) = 0;
  if ( v10 != nullptr )
    GRefCountImpl::Release(this: v10);
  GASValue::~GASValue(this: &a5);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C1F60
// Name: public: virtual void GFxLoadXMLTask::Execute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadXMLTask::Execute(GFxLoadXMLTask *this)
{
  void *v2; // edi
  void *v3; // esi
  int v4; // [esp+10h] [ebp-10h]
  int v5; // [esp+14h] [ebp-Ch]
  GString v6; // [esp+18h] [ebp-8h] BYREF
  CP4Factory result[4]; // [esp+1Ch] [ebp-4h] BYREF

  GString::GString(result: (CImagePacker *)((char *)this + 24));
  GString::GString(result: (CImagePacker *)((char *)this + 20));
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)result);
  GFxLoadStates::BuildURL(result);
  GString::GString(this: &v6, a2: (const char *)((*(_DWORD *)&result[0].m_bDummyMode & 0xFFFFFFFC) + 8));
  (*(void (__thiscall **)(_DWORD, GString *, _DWORD))(**((_DWORD **)this + 7) + 4))(
    a1: *((_DWORD *)this + 7),
    a2: &v6,
    a3: *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 8) + 8));
  v2 = (void *)(v6.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v6.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
  InterlockedExchange(Target: (volatile LONG *)this + 8, Value: 1);
  v3 = (void *)(*(_DWORD *)&result[0].m_bDummyMode & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(
         Addend: (volatile LONG *)((*(_DWORD *)&result[0].m_bDummyMode & 0xFFFFFFFC) + 4),
         Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v5 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)(v5 & 0xFFFFFFFC));
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v4 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)(v4 & 0xFFFFFFFC));
}

//------------------------------------------------------------------------------
// Address: 0x100C2070
// Name: public: GFxLoadCSSTask::GFxLoadCSSTask(class GFxLoadStates __near *,class GString const __near &,class GString const __near &,struct GFxLoadQueueEntry::CSSHolderType)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxLoadCSSTask::GFxLoadCSSTask(
        _DWORD *this,
        IShaderDevice *a2,
        CImagePacker *a3,
        CImagePacker *a4,
        GASValue a5,
        int a6,
        int a7,
        int a8,
        IShaderDevice *a9)
{
  IShaderAPI *v10; // ecx
  VertexShaderHandle_t__ *v12; // [esp+0h] [ebp-8h]

  *this = &GRefCountImplCore::`vftable';
  *this = &GFxTask::`vftable';
  *(this + 1) = 1;
  *(this + 2) = 131073;
  *(this + 3) = 0;
  *this = &GFxLoadCSSTask::`vftable';
  if ( a2 != nullptr )
    GRefCountImpl::AddRef(this: a2, a2: v12);
  *(this + 4) = a2;
  GString::GString(result: a3);
  GString::GString(result: a4);
  v10 = (IShaderAPI *)a9;
  if ( a9 != nullptr )
  {
    GRefCountImpl::AddRef(this: a9, a2: v12);
    v10 = (IShaderAPI *)a9;
  }
  *(this + 7) = v10;
  *(this + 8) = 0;
  if ( v10 != nullptr )
    GRefCountImpl::Release(this: v10);
  GASValue::~GASValue(this: &a5);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C2100
// Name: public: virtual GFxLoadCSSTask::~GFxLoadCSSTask(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadCSSTask::~GFxLoadCSSTask(IShaderAPI *this)
{
  IShaderAPI *v2; // ecx
  volatile LONG *v3; // esi
  volatile LONG *v4; // esi
  IShaderAPI *v5; // ecx

  v2 = *((IShaderAPI **)this + 7);
  if ( v2 != nullptr )
    GRefCountImpl::Release(this: v2);
  v3 = (volatile LONG *)(*(_DWORD *)(this + 6) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v3 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
  v4 = (volatile LONG *)(*(_DWORD *)(this + 5) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v4 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v4);
  v5 = *((IShaderAPI **)this + 4);
  if ( v5 != nullptr )
    GRefCountImpl::Release(this: v5);
  this->__vftable = (IShaderAPI_vtbl *)&GFxTask::`vftable';
  GRefCountImplCore::~GRefCountImplCore(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C21B0
// Name: public: virtual void GFxLoadCSSTask::Execute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadCSSTask::Execute(GFxLoadCSSTask *this)
{
  void *v2; // edi
  void *v3; // esi
  int v4; // [esp+10h] [ebp-10h]
  int v5; // [esp+14h] [ebp-Ch]
  GString v6; // [esp+18h] [ebp-8h] BYREF
  CP4Factory result[4]; // [esp+1Ch] [ebp-4h] BYREF

  GString::GString(result: (CImagePacker *)((char *)this + 24));
  GString::GString(result: (CImagePacker *)((char *)this + 20));
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)result);
  GFxLoadStates::BuildURL(result);
  GString::GString(this: &v6, a2: (const char *)((*(_DWORD *)&result[0].m_bDummyMode & 0xFFFFFFFC) + 8));
  (*(void (__thiscall **)(_DWORD, GString *, _DWORD))(**((_DWORD **)this + 7) + 4))(
    a1: *((_DWORD *)this + 7),
    a2: &v6,
    a3: *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 8) + 8));
  v2 = (void *)(v6.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v6.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
  InterlockedExchange(Target: (volatile LONG *)this + 8, Value: 1);
  v3 = (void *)(*(_DWORD *)&result[0].m_bDummyMode & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(
         Addend: (volatile LONG *)((*(_DWORD *)&result[0].m_bDummyMode & 0xFFFFFFFC) + 4),
         Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v5 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)(v5 & 0xFFFFFFFC));
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v4 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)(v4 & 0xFFFFFFFC));
}

//------------------------------------------------------------------------------
// Address: 0x100C22C0
// Name: public: virtual bool GFxMovieRoot::HitTest3D(class GPoint3<float> __near *,float,float,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxMovieRoot::HitTest3D(int this, float *a2, float a3, float a4, float a5)
{
  GFxAmpViewStats *v6; // esi
  float v7; // ecx
  float v8; // eax
  float v9; // ecx
  int v10; // edx
  double v11; // st7
  int v12; // ebx
  GFxCharacter *v13; // esi
  int v14; // eax
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *TopMostEntity; // eax
  CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *v16; // esi
  float v17; // ecx
  float *v18; // eax
  double v19; // st7
  float *v21; // eax
  float v22; // [esp-Ch] [ebp-C4h]
  const CMaterialDict::MissingMaterial_t *v23; // [esp+0h] [ebp-B8h]
  const CMaterialDict::MissingMaterial_t *v24; // [esp+0h] [ebp-B8h]
  int v25; // [esp+0h] [ebp-B8h]
  float *v26; // [esp+4h] [ebp-B4h]
  float v27[5]; // [esp+Ch] [ebp-ACh] BYREF
  int v28; // [esp+20h] [ebp-98h]
  GFxAmpViewStats *v29; // [esp+24h] [ebp-94h]
  float v30; // [esp+34h] [ebp-84h]
  float *v31; // [esp+38h] [ebp-80h]
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> p; // [esp+3Ch] [ebp-7Ch] BYREF
  CCountedStringPoolBase<unsigned int>::hash_item_t v33; // [esp+44h] [ebp-74h] BYREF
  float v34; // [esp+50h] [ebp-68h]
  float v35; // [esp+54h] [ebp-64h]
  float v36; // [esp+58h] [ebp-60h]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v37; // [esp+5Ch] [ebp-5Ch] BYREF
  GMatrix3D pmat; // [esp+74h] [ebp-44h] BYREF

  v6 = *(GFxAmpViewStats **)(this + 10308);
  v7 = a5;
  v31 = a2;
  v8 = 0.0;
  v35 = a5;
  v29 = v6;
  if ( v6 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v6, swdHandle: 1u, a3: 0x1Bu);
    GTimer::GetRawTicks(li: v9, a2: *(float *)&v23, a3: v26);
    v28 = v10;
  }
  else
  {
    v28 = 0;
  }
  v11 = *(float *)(this + 120);
  v27[4] = v8;
  v36 = v11 * a3 + *(float *)(this + 128);
  v30 = v36 * 20.0;
  v36 = *(float *)(this + 124) * a4 + *(float *)(this + 132);
  v36 = 20.0 * v36;
  *(float *)&v33.nNextElement = *(float *)(this + 156) - *(float *)(this + 148);
  *(float *)&p.pContainer = (v36 / *(float *)&v33.nNextElement - 0.5) * 2.0;
  *(float *)&v33.nNextElement = *(float *)(this + 152) - *(float *)(this + 144);
  *(float *)(this + 208) = 2.0 * (v30 / *(float *)&v33.nNextElement - 0.5);
  *(float *)(this + 212) = -*(float *)&p.pContainer;
  v12 = *(_DWORD *)(this + 40);
  if ( v12 <= 0 )
  {
LABEL_15:
    if ( v6 != nullptr )
    {
      GTimer::GetRawTicks(li: v7, a2: *(float *)&v23, a3: v26);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return 0;
  }
  else
  {
    while ( 1 )
    {
      v13 = *(GFxCharacter **)(*(_DWORD *)(this + 36) + 8 * v12 - 4);
      GMatrix2D::SetIdentity(result: v23);
      (*(void (__thiscall **)(GFxCharacter *, float *, CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *))(*(_DWORD *)v13 + 52))(
        a1: v13,
        a2: v27,
        a3: &v37);
      *(float *)&p.__vftable = v30;
      *(float *)&p.pContainer = v36;
      GMatrix2D::SetIdentity(result: v24);
      GFxCharacter::GetWorldMatrix(this: v13, pmat: (CMaterialDict *)&v37);
      GMatrix2D::TransformByInverse(this: &v37, result: &v33, (int)&p, a4: v25);
      if ( (*(unsigned __int8 (__thiscall **)(GFxCharacter *))(*(_DWORD *)v13 + 8))(a1: v13) != 0
        || v27[2] >= (double)*(float *)&v33.pString
        && v27[0] <= (double)*(float *)&v33.pString
        && v27[3] >= (double)*(float *)&v33.nNextElement
        && v27[1] <= (double)*(float *)&v33.nNextElement )
      {
        v22 = v35;
        v14 = (*(int (__thiscall **)(GFxCharacter *))(*(_DWORD *)v13 + 84))(a1: v13);
        TopMostEntity = GFxMovieRoot::GetTopMostEntity(this: v14, result: &p, a3: v22, testAll: true, ignoreMC: 0);
        v16 = (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)TopMostEntity;
        if ( TopMostEntity != nullptr )
          break;
      }
      if ( --v12 <= 0 )
      {
        v6 = v29;
        goto LABEL_15;
      }
    }
    if ( GFxCharacter::Is3D(
           this: TopMostEntity,
           result: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)1) != 0 )
    {
      v34 = *(float *)(this + 216);
      v35 = *(float *)(this + 220);
      GMatrix3D::SetIdentity(this: &pmat);
      GFxCharacter::GetWorldMatrix3D(this: v16, (CMatQueuedMesh::MST_MeshInfo_t *)&pmat);
      v18 = v31;
      v19 = v34;
      *(float *)&v33.nReferenceCount = pmat.M_[2][0] * 0.0 + pmat.M_[0][0] * v34 + pmat.M_[1][0] * v35 + pmat.M_[3][0];
      v34 = pmat.M_[0][1] * v34 + pmat.M_[1][1] * v35 + pmat.M_[2][1] * 0.0 + pmat.M_[3][1];
      v35 = 0.0 * pmat.M_[2][2] + v35 * pmat.M_[1][2] + v19 * pmat.M_[0][2] + pmat.M_[3][2];
      v31[2] = v35;
      *v18 = *(float *)&v33.nReferenceCount / 20.0;
      v18[1] = v34 / 20.0;
    }
    else
    {
      v21 = v31;
      *v31 = a3;
      v21[1] = a4;
      v21[2] = 0.0;
    }
    if ( v29 != nullptr )
    {
      GTimer::GetRawTicks(li: v17, a2: *(float *)&v23, a3: v26);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C25E0
// Name: public: void GFxMovieRoot::SetModalClip(class GFxSprite __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::SetModalClip(
        ISteamRemoteStorage *this,
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *pmovie,
        unsigned int controllerIdx)
{
  ISteamRemoteStorage *v3; // ebx
  GFxCharacterHandle *v4; // esi
  ISteamRemoteStorage_vtbl *v5; // eax
  ISteamRemoteStorage_vtbl *v6; // edi
  GFxCharacterHandle *v7; // esi

  v3 = this + 13 * *((unsigned __int8 *)this + controllerIdx + 10228) + 2348;
  if ( pmovie != nullptr )
  {
    v5 = (ISteamRemoteStorage_vtbl *)DWORD1(pmovie[6].m_pfnProxied);
    if ( v5 == nullptr )
      GFxASCharacter::CreateCharacterHandle(this: pmovie);
    v6 = v5;
    if ( v5 != nullptr )
      ++v5->FileWrite;
    v7 = (GFxCharacterHandle *)v3[6].__vftable;
    if ( v7 != nullptr )
    {
      *v7 = (GFxCharacterHandle)((char *)*v7 - 1);
      if ( (int)*v7 <= 0 )
      {
        GFxCharacterHandle::~GFxCharacterHandle(this: v7);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
      }
    }
    v3[6].__vftable = v6;
  }
  else
  {
    v4 = *((GFxCharacterHandle **)this + 13 * *((unsigned __int8 *)this + controllerIdx + 10228) + 2354);
    if ( v4 != nullptr )
    {
      *v4 = (GFxCharacterHandle)((char *)*v4 - 1);
      if ( (int)*v4 <= 0 )
      {
        GFxCharacterHandle::~GFxCharacterHandle(this: v4);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
      }
    }
    v3[6].__vftable = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C2680
// Name: public: void GFxMovieRoot::DisplayFocusRect(class GFxDisplayContext const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::DisplayFocusRect(GFxMovieRoot *this, const struct GFxDisplayContext *a2)
{
  GFxMovieRoot *v2; // edi
  char *v3; // esi
  _DWORD *v4; // eax
  GRefCountNTSImpl *v5; // ebx
  int *v6; // esi
  int v7; // edi
  int v8; // eax
  double v9; // st5
  double v10; // st4
  double v12; // rt1
  double v13; // st4
  double v14; // st5
  double v15; // rt2
  double v16; // rt0
  double v17; // st5
  double v18; // st7
  double v19; // rt1
  double v20; // st4
  double v21; // st5
  double v22; // st3
  double v23; // st1
  double v24; // st4
  double v25; // rt2
  double v26; // st1
  double v27; // st5
  double v28; // st2
  double v29; // st5
  double v30; // st1
  double v31; // st4
  double v32; // st6
  double v33; // st7
  double v34; // st3
  double v35; // rtt
  double v36; // rt2
  double v37; // st4
  const CMaterialDict::MissingMaterial_t *v38; // [esp+0h] [ebp-1A8h]
  const CMaterialDict::MissingMaterial_t *v39; // [esp+0h] [ebp-1A8h]
  float v40[4]; // [esp+Ch] [ebp-19Ch] BYREF
  int v41; // [esp+1Ch] [ebp-18Ch]
  int v42; // [esp+20h] [ebp-188h]
  int v43; // [esp+24h] [ebp-184h]
  int v44; // [esp+28h] [ebp-180h]
  int v45; // [esp+2Ch] [ebp-17Ch]
  GRefCountNTSImpl *v46; // [esp+30h] [ebp-178h]
  int v47; // [esp+34h] [ebp-174h]
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > result; // [esp+38h] [ebp-170h] BYREF
  const struct GFxDisplayContext *v49; // [esp+4Ch] [ebp-15Ch]
  char *v50; // [esp+50h] [ebp-158h]
  int v51; // [esp+54h] [ebp-154h]
  float *v52; // [esp+58h] [ebp-150h]
  int v53; // [esp+5Ch] [ebp-14Ch]
  unsigned int v54; // [esp+60h] [ebp-148h]
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > v55; // [esp+64h] [ebp-144h] BYREF
  UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short> *m_pMemory; // [esp+78h] [ebp-130h]
  int m_nGrowSize; // [esp+7Ch] [ebp-12Ch]
  int m_nAllocationCount; // [esp+80h] [ebp-128h]
  GMatrix3D pmat; // [esp+A4h] [ebp-104h] BYREF
  GMatrix3D v60; // [esp+E4h] [ebp-C4h] BYREF
  _BYTE v61[24]; // [esp+124h] [ebp-84h] BYREF
  CMaterialDict v62; // [esp+13Ch] [ebp-6Ch] BYREF
  __int16 v63; // [esp+17Ch] [ebp-2Ch]
  __int16 v64; // [esp+17Eh] [ebp-2Ah]
  __int16 v65; // [esp+180h] [ebp-28h]
  __int16 v66; // [esp+182h] [ebp-26h]
  __int16 v67; // [esp+184h] [ebp-24h]
  __int16 v68; // [esp+186h] [ebp-22h]
  __int16 v69; // [esp+188h] [ebp-20h]
  __int16 v70; // [esp+18Ah] [ebp-1Eh]
  __int16 v71; // [esp+18Ch] [ebp-1Ch]
  __int16 v72; // [esp+18Eh] [ebp-1Ah]
  __int16 v73; // [esp+190h] [ebp-18h]
  __int16 v74; // [esp+192h] [ebp-16h]
  __int16 v75; // [esp+194h] [ebp-14h]
  __int16 v76; // [esp+196h] [ebp-12h]
  __int16 v77; // [esp+198h] [ebp-10h]
  __int16 v78; // [esp+19Ah] [ebp-Eh]
  __int16 v79; // [esp+19Ch] [ebp-Ch]
  __int16 v80; // [esp+19Eh] [ebp-Ah]
  __int16 v81; // [esp+1A0h] [ebp-8h]
  __int16 v82; // [esp+1A2h] [ebp-6h]

  v2 = this;
  v49 = a2;
  v52 = (float *)this;
  v54 = 0;
  if ( *((_DWORD *)this + 2556) != 0 )
  {
    v3 = (char *)this + 9412;
    v53 = 0;
    v50 = (char *)this + 9412;
    while ( 1 )
    {
      v4 = *(_DWORD **)v3;
      if ( *(_DWORD *)v3 != 0 )
      {
        if ( v4[1] == 0 )
        {
          if ( (*v4)-- == 1 )
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
          *(_DWORD *)v3 = 0;
          goto LABEL_64;
        }
        v5 = (GRefCountNTSImpl *)v4[1];
        v46 = v5;
        if ( v5 != nullptr )
          break;
      }
LABEL_64:
      v53 += 1081552;
      v3 += 52;
      ++v54;
      v50 = v3;
      if ( v54 >= *((_DWORD *)v2 + 2556) )
        return;
    }
    ++v5->RefCount;
    ++v5->RefCount;
    GRefCountNTSImpl::Release(this: v5);
    if ( v3[28] == 0
      || ((unsigned __int8 (__thiscall *)(GRefCountNTSImpl *))v5->__vftable[54].dtr_GRefCountImplCore)(a1: v5) == 0 )
    {
LABEL_63:
      GRefCountNTSImpl::Release(this: v5);
      goto LABEL_64;
    }
    GMatrix3D::SetIdentity(this: &v60);
    GMatrix2D::SetIdentity(result: v38);
    GFxCharacter::GetWorldMatrix(this: (GFxCharacter *)v5, pmat: &v62);
    ((void (__thiscall *)(GRefCountNTSImpl *, float *))v5->__vftable[61].dtr_GRefCountImplCore)(a1: v5, a2: v40);
    if ( v40[0] != v40[2] || v40[1] != v40[3] )
    {
      GMatrix3D::SetIdentity(this: &pmat);
      GFxCharacter::GetWorldMatrix3D(
        this: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)v5,
        (CMatQueuedMesh::MST_MeshInfo_t *)&pmat);
      *(float *)&result.m_Memory.m_pMemory = 0.0;
      *(float *)&result.m_Memory.m_nAllocationCount = 0.0;
      *(float *)&result.m_Memory.m_nGrowSize = 0.0;
      v60 = pmat;
      *(float *)&result.m_Size = 0.0;
      GMatrix3D::EncloseTransform(&result);
      if ( *(float *)&result.m_Memory.m_nAllocationCount <= (double)v52[39]
        && v52[37] <= (double)*(float *)&result.m_Size
        && v52[36] <= (double)*(float *)&result.m_Memory.m_nGrowSize
        && *(float *)&result.m_Memory.m_pMemory <= (double)v52[38] )
      {
        goto LABEL_15;
      }
      if ( (*(_DWORD *)(*((_DWORD *)v49 + 18) + 20) & 0x100) != 0 )
      {
LABEL_15:
        v6 = *(int **)(*((_DWORD *)v49 + 18) + 12);
        *(float *)&v55.m_Memory.m_pMemory = 0.0;
        *(float *)&v55.m_Memory.m_nAllocationCount = 0.0;
        *(float *)&v55.m_Memory.m_nGrowSize = 0.0;
        *(float *)&v55.m_Size = 0.0;
        GMatrix3D::EncloseTransform(result: &v55);
        *(float *)&m_nAllocationCount = (double)v54 * 20.0;
        *(float *)&v55.m_Memory.m_pMemory = *(float *)&v55.m_Memory.m_pMemory - *(float *)&m_nAllocationCount;
        *(float *)&v55.m_Memory.m_nGrowSize = *(float *)&v55.m_Memory.m_nGrowSize + *(float *)&m_nAllocationCount;
        *(float *)&v55.m_Memory.m_nAllocationCount = *(float *)&v55.m_Memory.m_nAllocationCount
                                                   - *(float *)&m_nAllocationCount;
        *(float *)&v55.m_Size = *(float *)&m_nAllocationCount + *(float *)&v55.m_Size;
        v7 = *v6;
        v8 = GRenderer::Cxform::Cxform();
        (*(void (__thiscall **)(int *, int))(v7 + 64))(a1: v6, a2: v8);
        GMatrix2D::SetIdentity(result: v39);
        (*(void (__thiscall **)(int *, _BYTE *))(*v6 + 56))(a1: v6, a2: v61);
        if ( *(float *)&v55.m_Memory.m_nAllocationCount <= 32767.0 )
        {
          if ( *(float *)&v55.m_Memory.m_nAllocationCount >= -32768.0 )
          {
            v55.m_pElements = (unsigned __int16 *)v55.m_Memory.m_nAllocationCount;
            v9 = 32767.0;
            v10 = -32768.0;
          }
          else
          {
            *(float *)&v55.m_pElements = -32768.0;
            v10 = -32768.0;
            v9 = 32767.0;
          }
        }
        else
        {
          v9 = 32767.0;
          *(float *)&v55.m_pElements = 32767.0;
          v10 = -32768.0;
        }
        if ( *(float *)&v55.m_Memory.m_pMemory <= 32767.0 )
        {
          if ( *(float *)&v55.m_Memory.m_pMemory >= v10 )
            m_pMemory = (UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short> *)v55.m_Memory.m_pMemory;
          else
            *(float *)&m_pMemory = v10;
          v15 = v10;
          v13 = v9;
          v14 = v15;
        }
        else
        {
          v12 = v10;
          v13 = v9;
          v14 = v12;
          *(float *)&m_pMemory = v13;
        }
        v62.m_MaterialDict.m_pElements = m_pMemory;
        v62.m_MissingList.m_LessFunc = (bool (__cdecl *)(const CMaterialDict::MissingMaterial_t *, const CMaterialDict::MissingMaterial_t *))v55.m_pElements;
        if ( *(float *)&v55.m_Memory.m_nAllocationCount <= 32767.0 )
        {
          if ( *(float *)&v55.m_Memory.m_nAllocationCount >= v14 )
            m_nAllocationCount = v55.m_Memory.m_nAllocationCount;
          else
            *(float *)&m_nAllocationCount = v14;
          v19 = v14;
          v17 = v13;
          v18 = v19;
        }
        else
        {
          v16 = v14;
          v17 = v13;
          v18 = v16;
          *(float *)&m_nAllocationCount = v13;
        }
        if ( *(float *)&v55.m_Memory.m_nGrowSize <= 32767.0 )
        {
          if ( *(float *)&v55.m_Memory.m_nGrowSize >= v18 )
            m_nGrowSize = v55.m_Memory.m_nGrowSize;
          else
            *(float *)&m_nGrowSize = v18;
          v20 = v17;
          v21 = *(float *)&v55.m_Memory.m_nGrowSize;
        }
        else
        {
          v20 = v17;
          v21 = *(float *)&v55.m_Memory.m_nGrowSize;
          *(float *)&m_nGrowSize = v20;
        }
        v22 = *(float *)&m_nGrowSize;
        v62.m_MissingList.m_Elements.m_pMemory = (UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int> *)m_nGrowSize;
        v62.m_MissingList.m_Elements.m_nAllocationCount = m_nAllocationCount;
        if ( *(float *)&v55.m_Size <= 32767.0 )
        {
          if ( *(float *)&v55.m_Size >= v18 )
            m_nGrowSize = v55.m_Size;
          else
            *(float *)&m_nGrowSize = v18;
          v23 = v20;
          v24 = *(float *)&v55.m_Size;
        }
        else
        {
          v23 = v20;
          v24 = *(float *)&v55.m_Size;
          *(float *)&m_nGrowSize = v23;
        }
        v25 = v23;
        v26 = v21;
        v27 = v25;
        if ( v26 <= 32767.0 )
        {
          v28 = v26;
          v29 = *(float *)&m_nAllocationCount;
          if ( v26 < v18 )
          {
            *(float *)&m_nAllocationCount = v18;
LABEL_52:
            v62.m_MissingList.m_Elements.m_nGrowSize = m_nAllocationCount;
            v62.m_MissingList.m_Root = m_nGrowSize;
            v30 = v24;
            v31 = *(float *)&m_nGrowSize;
            if ( v30 <= 32767.0 )
            {
              if ( v30 < v18 )
              {
                *(float *)&m_nGrowSize = v18;
                goto LABEL_57;
              }
            }
            else
            {
              v30 = 32767.0;
            }
            *(float *)&m_nGrowSize = v30;
LABEL_57:
            if ( *(float *)&v55.m_Memory.m_pMemory <= 32767.0 )
            {
              v32 = *(float *)&m_nAllocationCount;
              if ( *(float *)&v55.m_Memory.m_pMemory >= v18 )
                v18 = *(float *)&v55.m_Memory.m_pMemory;
              v35 = v22;
              v34 = v18;
              v33 = v35;
            }
            else
            {
              v32 = *(float *)&m_nAllocationCount;
              v33 = v22;
              v34 = 32767.0;
            }
            *(float *)&m_nAllocationCount = v34;
            v62.m_MissingList.m_NumElements = m_nAllocationCount;
            v62.m_MissingList.m_FirstFree = m_nGrowSize;
            LOWORD(v42) = (int)*(float *)&m_pMemory;
            LOWORD(v62.m_MissingList.m_LastAlloc.index) = v42;
            LOWORD(result.m_pElements) = (int)*(float *)&v55.m_pElements;
            HIWORD(v62.m_MissingList.m_LastAlloc.index) = result.m_pElements;
            LOWORD(v44) = (int)v33;
            LOWORD(v62.m_MissingList.m_pElements) = v44;
            v36 = v31;
            v37 = *(float *)&m_nAllocationCount;
            LOWORD(v47) = (int)v29;
            HIWORD(v62.m_MissingList.m_pElements) = v47;
            v63 = v42;
            v64 = LOWORD(result.m_pElements) + 40;
            v65 = v44;
            m_nAllocationCount = v47 + 40;
            v66 = v47 + 40;
            v67 = v42 + 40;
            v68 = LOWORD(result.m_pElements) + 40;
            LOWORD(v45) = (int)v37;
            v69 = v45;
            LOWORD(v51) = (int)*(float *)&m_nGrowSize;
            v70 = v51 - 40;
            v71 = v45 + 40;
            v72 = v51 - 40;
            v73 = v44 - 40;
            v74 = v47 + 40;
            LOWORD(v41) = (int)v32;
            v75 = v41 - 40;
            LOWORD(v43) = (int)v36;
            v82 = v43;
            v80 = v51;
            v76 = v43 - 40;
            v77 = v41;
            v78 = v43 - 40;
            v79 = v45;
            v81 = v41;
            (*(void (__thiscall **)(int *, CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int>,int>::Iterator_t *, int, int, _DWORD))(*v6 + 104))(
              a1: v6,
              a2: &v62.m_MissingList.m_LastAlloc,
              a3: 12,
              a4: 1,
              a5: 0);
            (*(void (__thiscall **)(int *, unsigned int))(*v6 + 136))(a1: v6, a2: v53 ^ 0xFFFFFF00 | 0xFF000000);
            (*(void (__thiscall **)(int *, void *, int, int, _DWORD))(*v6 + 108))(
              a1: v6,
              a2: &unk_102A1128,
              a3: 24,
              a4: 1,
              a5: 0);
            (*(void (__thiscall **)(int *, _DWORD, _DWORD, int, _DWORD, int))(*v6 + 116))(
              a1: v6,
              a2: 0,
              a3: 0,
              a4: 12,
              a5: 0,
              a6: 8);
            (*(void (__thiscall **)(int *, _DWORD, _DWORD, _DWORD, _DWORD))(*v6 + 104))(
              a1: v6,
              a2: 0,
              a3: 0,
              a4: 0,
              a5: 0);
            (*(void (__thiscall **)(int *, _DWORD, _DWORD, _DWORD, _DWORD))(*v6 + 108))(
              a1: v6,
              a2: 0,
              a3: 0,
              a4: 0,
              a5: 0);
            v3 = v50;
            v5 = v46;
            v2 = (GFxMovieRoot *)v52;
            goto LABEL_63;
          }
        }
        else
        {
          v28 = v27;
          v29 = *(float *)&m_nAllocationCount;
        }
        *(float *)&m_nAllocationCount = v28;
        goto LABEL_52;
      }
    }
    GRefCountNTSImpl::Release(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C2D80
// Name: public: void GFxMovieRoot::HideFocusRect(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::HideFocusRect(GFxMovieRoot *this, unsigned int a2)
{
  int v2; // eax
  char *v3; // edi
  _DWORD *v4; // eax
  GRefCountNTSImpl *v5; // esi

  v2 = 52 * *((unsigned __int8 *)this + a2 + 10228);
  v3 = (char *)this + v2 + 9392;
  if ( *((_BYTE *)this + v2 + 9440) == 0 || (v4 = *(_DWORD **)((char *)this + v2 + 9412)) == nullptr )
  {
LABEL_12:
    v3[48] = 0;
    return;
  }
  if ( v4[1] != 0 )
  {
    v5 = (GRefCountNTSImpl *)v4[1];
    if ( v5 != nullptr )
    {
      ++v5->RefCount;
      ++v5->RefCount;
      GRefCountNTSImpl::Release(this: v5);
      if ( v5[4].__vftable != nullptr
        && ((unsigned __int8 (__thiscall *)(GRefCountNTSImpl *, _DWORD, unsigned int, int))v5->__vftable[60].dtr_GRefCountImplCore)(
             a1: v5,
             a2: 0,
             a3: a2,
             a4: 2) == 0 )
      {
        GRefCountNTSImpl::Release(this: v5);
        return;
      }
      GRefCountNTSImpl::Release(this: v5);
    }
    goto LABEL_12;
  }
  if ( (*v4)-- == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
  *((_DWORD *)v3 + 5) = 0;
  v3[48] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C2E30
// Name: public: void GFxMovieRoot::QueueSetFocusTo(class GFxASCharacter __near *,class GFxASCharacter __near *,unsigned int,enum GFxFocusMovedType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::QueueSetFocusTo(
        ISteamRemoteStorage *this,
        const ISteamRemoteStorage *ch,
        struct GFxASCharacter *a3,
        unsigned int controllerIdx,
        int a5)
{
  _DWORD *v6; // eax
  __int64 v7; // rdi
  GFxIMEManager *v8; // eax
  IShaderAPI *v9; // ecx
  unsigned int v11; // edx
  unsigned int v12; // eax
  _DWORD *v13; // ebx
  _DWORD *v14; // ecx
  int v15; // eax
  const GArrayBase<GArrayData<GPtr<GFxAmpMemItem>,GAllocatorLH<GPtr<GFxAmpMemItem>,2>,GArrayDefaultPolicy> > *v16; // ecx
  CUtlMemory<CImagePacker,int> v17; // [esp-10h] [ebp-1Ch]
  struct GFxASCharacter *v18; // [esp+0h] [ebp-Ch]
  struct GFxASCharacter *v19; // [esp+4h] [ebp-8h]
  IShaderAPI *v20; // [esp+14h] [ebp+8h]

  HIDWORD(v7) = 52 * (*((unsigned __int8 *)this + controllerIdx + 10228) + 181);
  v6 = *(ISteamRemoteStorage_vtbl **)((char *)&this->__vftable + HIDWORD(v7));
  LODWORD(v7) = 0;
  if ( v6 != nullptr )
  {
    if ( v6[1] != 0 )
    {
      LODWORD(v7) = v6[1];
      if ( (_DWORD)v7 != 0 )
      {
        ++*(_DWORD *)(v7 + 4);
        ++*(_DWORD *)(v7 + 4);
        GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v7);
      }
    }
    else
    {
      if ( (*v6)-- == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
      *(ISteamRemoteStorage_vtbl **)((char *)&this->__vftable + HIDWORD(v7)) = nullptr;
    }
  }
  HIDWORD(v7) = ch;
  if ( (const ISteamRemoteStorage *)v7 == ch )
    goto LABEL_26;
  v8 = (GFxIMEManager *)(*(int (__thiscall **)(ISteamRemoteStorage *, int))(*((_DWORD *)this + 2) + 12))(
                          a1: this + 2,
                          a2: 27);
  v20 = (IShaderAPI *)v8;
  if ( v8 != nullptr )
  {
    *(_QWORD *)&v17.m_nAllocationCount = v7;
    v17.m_pMemory = (CImagePacker *)this;
    HIDWORD(v7) = GFxIMEManager::HandleFocus(this: v8, a2: v17, a3, a4: v18, a5: v19);
    if ( (_DWORD)v7 == HIDWORD(v7) )
    {
      v9 = v20;
LABEL_25:
      GRefCountImpl::Release(this: v9);
      goto LABEL_26;
    }
  }
  if ( (_DWORD)v7 == 0
    || *(_DWORD *)(v7 + 32) == 0
    || (*(unsigned __int8 (__thiscall **)(_DWORD, _DWORD, unsigned int, int))(*(_DWORD *)v7 + 240))(
         a1: v7,
         a2: HIDWORD(v7),
         a3: controllerIdx,
         a4: a5) != 0 )
  {
    if ( HIDWORD(v7) != 0 )
      (*(void (__thiscall **)(_DWORD, unsigned int))(*(_DWORD *)HIDWORD(v7) + 236))(a1: HIDWORD(v7), a2: controllerIdx);
    v11 = *((_DWORD *)this + 10);
    v12 = 0;
    if ( v11 != 0 )
    {
      v13 = *((_DWORD **)this + 9);
      v14 = v13;
      while ( *v14 != 0 )
      {
        ++v12;
        v14 += 2;
        if ( v12 >= v11 )
          goto LABEL_23;
      }
      v15 = v13[2 * v12 + 1];
    }
    else
    {
LABEL_23:
      v15 = 0;
    }
    (*(void (__thiscall **)(int, _DWORD, unsigned int, int))(*(_DWORD *)v15 + 112))(
      a1: v15,
      a2: HIDWORD(v7),
      a3: controllerIdx,
      a4: a5);
    GASSelection::QueueSetFocus(penv: v16);
    v9 = v20;
    if ( v20 != nullptr )
      goto LABEL_25;
LABEL_26:
    if ( (_DWORD)v7 == 0 )
      return;
    goto LABEL_27;
  }
  if ( v20 != nullptr )
  {
    GRefCountImpl::Release(this: v20);
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v7);
    return;
  }
LABEL_27:
  GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v7);
}

//------------------------------------------------------------------------------
// Address: 0x100C2F80
// Name: public: void GFxMovieRoot::TransferFocus(class GFxASCharacter __near *,unsigned int,enum GFxFocusMovedType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::TransferFocus(
        ISteamRemoteStorage *this,
        GRefCountWeakSupportImpl *a2,
        unsigned int controllerIdx,
        int a4)
{
  int v4; // edx
  _DWORD *v5; // eax
  char *v6; // edi
  GRefCountNTSImpl *v7; // esi
  _DWORD *v9; // eax
  bool v10; // zf
  unsigned int v11; // edx
  unsigned int v12; // eax
  _DWORD *v13; // ecx
  int v14; // eax
  struct GASEnvironment *v15; // eax
  _DWORD *v16; // eax
  GRefCountWeakSupportImpl *WeakProxy; // [esp+18h] [ebp+8h]

  v4 = 52 * *((unsigned __int8 *)this + controllerIdx + 10228);
  v5 = *(_DWORD **)((char *)this + v4 + 9412);
  v6 = (char *)this + v4 + 9392;
  v7 = nullptr;
  if ( v5 != nullptr )
  {
    if ( v5[1] != 0 )
    {
      v7 = (GRefCountNTSImpl *)v5[1];
      if ( v7 != nullptr )
      {
        ++v7->RefCount;
        ++v7->RefCount;
        GRefCountNTSImpl::Release(this: v7);
      }
    }
    else
    {
      v10 = (*v5)-- == 1;
      if ( v10 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
      *((_DWORD *)v6 + 5) = 0;
    }
  }
  if ( v7 != a2 )
  {
    if ( v7 != nullptr && v7[4].__vftable != nullptr )
      ((void (__thiscall *)(GRefCountNTSImpl *, _DWORD, GRefCountWeakSupportImpl *, unsigned int, int))v7->__vftable[58].dtr_GRefCountImplCore)(
        a1: v7,
        a2: 0,
        a3: a2,
        a4: controllerIdx,
        a5: a4);
    if ( a2 != nullptr )
    {
      WeakProxy = (GRefCountWeakSupportImpl *)GRefCountWeakSupportImpl::CreateWeakProxy(this: a2);
      v9 = *((_DWORD **)v6 + 5);
      if ( v9 != nullptr )
      {
        v10 = (*v9)-- == 1;
        if ( v10 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
      }
      *((_DWORD *)v6 + 5) = WeakProxy;
      ((void (__thiscall *)(GRefCountWeakSupportImpl *, int, GRefCountNTSImpl *, unsigned int, int))a2->__vftable[58].dtr_GRefCountImplCore)(
        a1: a2,
        a2: 1,
        a3: v7,
        a4: controllerIdx,
        a5: a4);
    }
    else
    {
      v16 = *((_DWORD **)v6 + 5);
      if ( v16 != nullptr )
      {
        v10 = (*v16)-- == 1;
        if ( v10 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v16);
      }
      *((_DWORD *)v6 + 5) = 0;
    }
    v11 = *((_DWORD *)this + 10);
    v12 = 0;
    if ( v11 != 0 )
    {
      v13 = *((_DWORD **)this + 9);
      while ( *v13 != 0 )
      {
        ++v12;
        v13 += 2;
        if ( v12 >= v11 )
          goto LABEL_18;
      }
      v14 = *(_DWORD *)(*((_DWORD *)this + 9) + 8 * v12 + 4);
    }
    else
    {
LABEL_18:
      v14 = 0;
    }
    v15 = (struct GASEnvironment *)(*(int (__thiscall **)(int))(*(_DWORD *)v14 + 112))(a1: v14);
    GASSelection::BroadcastOnSetFocus(
      a1: v15,
      a2: (struct GFxASCharacter *)v7,
      a3: (struct GFxASCharacter *)a2,
      a4: controllerIdx);
  }
  if ( v7 != nullptr )
    GRefCountNTSImpl::Release(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x100C30E0
// Name: public: bool GFxMovieRoot::IsFocused(class GFxASCharacter const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::IsFocused(ScaleformRenderer *this@<ecx>, GRefCountNTSImpl *ch, bool i)
{
  ScaleformRenderer *v3; // edi
  ScaleformRenderer_vtbl *v4; // eax
  GRefCountNTSImpl *GetRenderCaps; // esi
  unsigned int ia; // [esp+10h] [ebp-4h]

  ia = 0;
  if ( *((_DWORD *)this + 2556) != 0 )
  {
    v3 = (ScaleformRenderer *)((char *)this + 9412);
    do
    {
      v4 = v3->__vftable;
      GetRenderCaps = nullptr;
      if ( v3->__vftable != nullptr )
      {
        if ( v4->GetRenderCaps != nullptr )
        {
          GetRenderCaps = (GRefCountNTSImpl *)v4->GetRenderCaps;
          if ( GetRenderCaps != nullptr )
          {
            ++GetRenderCaps->RefCount;
            ++GetRenderCaps->RefCount;
            GRefCountNTSImpl::Release(this: GetRenderCaps);
          }
        }
        else
        {
          if ( v4->dtr_GRefCountImplCore-- == (void (__thiscall *)(struct ScaleformRenderer *))1 )
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
          v3->__vftable = nullptr;
        }
      }
      if ( GetRenderCaps != nullptr )
        GRefCountNTSImpl::Release(this: GetRenderCaps);
      if ( GetRenderCaps == ch )
        break;
      v3 = (ScaleformRenderer *)((char *)v3 + 52);
      ++ia;
    }
    while ( ia < *((_DWORD *)this + 2556) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C3280
// Name: public: virtual bool GFxMovieRoot::TranslateLocalToScreen(char const __near *,class GPoint<float> const __near &,class GPoint<float> __near *,class GMatrix2D)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxMovieRoot::TranslateLocalToScreen(
        int this,
        IDirect3DVertexDeclaration9 *result,
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > pt,
        int a4,
        int a5,
        int a6)
{
  unsigned int v7; // ecx
  unsigned int v8; // eax
  _DWORD *v9; // edx
  int v10; // eax
  __vc_attributes::max_isAttribute *v11; // esi
  float v12; // eax
  char v13; // al
  char v14; // bl
  GFxCharacter *v16; // esi
  float *v18; // eax
  const CMaterialDict::MissingMaterial_t *v19; // [esp+0h] [ebp-6Ch]
  int v20; // [esp+0h] [ebp-6Ch]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *res; // [esp+Ch] [ebp-60h] BYREF
  int p[2]; // [esp+1Ch] [ebp-50h] BYREF
  float *m_nAllocationCount; // [esp+24h] [ebp-48h]
  char *pString; // [esp+28h] [ebp-44h]
  char varname[4]; // [esp+2Ch] [ebp-40h] BYREF
  CCountedStringPoolBase<unsigned int>::hash_item_t v26; // [esp+30h] [ebp-3Ch] BYREF
  GMatrix2D v27; // [esp+50h] [ebp-1Ch] BYREF

  v7 = *(_DWORD *)(this + 40);
  m_nAllocationCount = (float *)pt.m_Memory.m_nAllocationCount;
  v8 = 0;
  if ( v7 != 0 )
  {
    v9 = *(_DWORD **)(this + 36);
    while ( *v9 != 0 )
    {
      ++v8;
      v9 += 2;
      if ( v8 >= v7 )
        goto LABEL_5;
    }
    v10 = *(_DWORD *)(*(_DWORD *)(this + 36) + 8 * v8 + 4);
  }
  else
  {
LABEL_5:
    v10 = 0;
  }
  v11 = (__vc_attributes::max_isAttribute *)(*(int (__thiscall **)(int))(*(_DWORD *)v10 + 112))(a1: v10);
  LOBYTE(res) = 0;
  GASStringManager::CreateStringNode(this: *((const char **)v11[30].expression + 159));
  *(float *)varname = v12;
  ++*(_DWORD *)(LODWORD(v12) + 8);
  GASEnvironment::GetVariable(this: v11, varname);
  v14 = v13;
  if ( (*(_DWORD *)(*(_DWORD *)varname + 8))-- == 1 )
    GASStringNode::ReleaseNode();
  if ( v14 != 0 && (v16 = GASValue::ToASCharacter(this: &res, a2: (const struct GASEnvironment *)v11)) != nullptr )
  {
    pString = pt.m_Memory.m_pMemory->pString;
    *(float *)varname = *(float *)&pt.m_Memory.m_pMemory->nNextElement;
    *(float *)&v26.pString = *(float *)&pString * 20.0;
    *(float *)&v26.nNextElement = 20.0 * *(float *)varname;
    p[0] = (int)v26.pString;
    p[1] = v26.nNextElement;
    GMatrix2D::SetIdentity(result: v19);
    GFxCharacter::GetWorldMatrix(this: v16, pmat: (CMaterialDict *)&v26.nReferenceCount);
    v27.M_[0][0] = *(float *)(this + 176);
    v27.M_[0][1] = *(float *)(this + 180);
    v27.M_[0][2] = *(float *)(this + 184);
    v27.M_[1][0] = *(float *)(this + 188);
    v27.M_[1][1] = *(float *)(this + 192);
    v27.M_[1][2] = *(float *)(this + 196);
    GMatrix2D::Prepend(this: &v27, a2: (const struct GMatrix2D *)&pt.m_Memory.m_nGrowSize);
    GMatrix2D::Prepend(this: &v27, a2: (const struct GMatrix2D *)&v26.nReferenceCount);
    GMatrix2D::Transform(
      this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v27,
      result: &v26,
      (int)p,
      a4: v20);
    v18 = m_nAllocationCount;
    *m_nAllocationCount = *(float *)&v26.pString;
    v18[1] = *(float *)&v26.nNextElement;
    GASValue::~GASValue(this: &res);
    return 1;
  }
  else
  {
    GASValue::~GASValue(this: &res);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C34A0
// Name: public: void GHashsetCachedEntry<class GFxTextFormatPtrWrapper<class GFxTextFormat>,struct GFxTextFormatPtrWrapper<class GFxTextFormat>::HashFunctor>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
ShaderAPIOcclusionQuery_t__ *__thiscall GHashsetCachedEntry<GFxTextFormatPtrWrapper<GFxTextFormat>,GFxTextFormatPtrWrapper<GFxTextFormat>::HashFunctor>::Clear(
        IShaderAPI **this)
{
  IShaderAPI *v2; // ecx
  ShaderAPIOcclusionQuery_t__ *result; // eax

  v2 = *(this + 2);
  if ( v2 != nullptr )
    result = GRefCountImpl::Release(this: v2);
  *this = (IShaderAPI *)-2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C3610
// Name: public: void GMsgFormat::FormatD1<unsigned long>(unsigned long const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GMsgFormat::FormatD1<unsigned long>(GMsgFormat *this, int a2)
{
  bool result; // al
  GMemoryHeap **v4; // esi
  BGR888_t *v5; // eax
  unsigned int v6; // edx
  GMemoryHeap *v7; // ecx
  struct GFormatter *v8; // eax

  result = GMsgFormat::NextFormatter(this);
  if ( result )
  {
    v4 = (GMemoryHeap **)(this + 61);
    do
    {
      if ( (unsigned int)*(this + 191) < 0x50 )
      {
        v7 = *v4;
        if ( *v4 == nullptr )
          v7 = GMemory::pGlobalHeap;
        v5 = (BGR888_t *)v7->Alloc(this: v7, a2: 80u, a3: 4u, a4: nullptr);
      }
      else
      {
        v5 = (BGR888_t *)*(this + 190);
        *(this + 190) = (GMsgFormat)(((unsigned int)&v5[26].g & 0xFFFFFFFC) + 4);
        v6 = ((unsigned int)&v5[26].g & 0xFFFFFFFC) - (_DWORD)v4;
        if ( v6 >= 0x200 )
          *(this + 191) = nullptr;
        else
          *(this + 191) = (GMsgFormat)(512 - v6);
      }
      if ( v5 != nullptr )
        v8 = (struct GFormatter *)GLongFormatter::GLongFormatter(this: v5);
      else
        v8 = nullptr;
      GMsgFormat::Bind(this, a2: v8, a3: true);
      result = GMsgFormat::NextFormatter(this);
    }
    while ( result );
  }
  ++*((_BYTE *)this + 5);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C3930
// Name: public: GFxTextFormat::GFxTextFormat(class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
GFxTextFormat *__thiscall GFxTextFormat::GFxTextFormat(GFxTextFormat *this, struct GMemoryHeap *a2)
{
  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxTextFormat::`vftable';
  GStringDH::GStringDH(this: (GStringDH *)this + 1, a2);
  GStringDH::GStringDH(this: (GStringDH *)this + 2, a2);
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_BYTE *)this + 40) = 0;
  *((_WORD *)this + 21) = 0;
  *((_DWORD *)this + 8) = -16777216;
  *((_DWORD *)this + 9) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C3990
// Name: public: virtual GFxTextFormat::~GFxTextFormat(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100C3A50
// Name: public: virtual void GFxMovieRoot::Display(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::Display(ScaleformRenderer *this)
{
  int v2; // edi
  GFxAmpViewStats *v3; // ebx
  float v4; // ecx
  int v5; // ecx
  IShaderDevice *v6; // ecx
  IShaderAPI *v7; // ecx
  int v8; // eax
  float v9; // eax
  float v10; // edi
  GRefCountNTSImpl **v11; // ecx
  GRefCountNTSImpl *v12; // ebx
  unsigned int v13; // eax
  _DWORD *v14; // ecx
  IDirect3DDevice9 *i; // edi
  int v16; // ecx
  const FileAsyncRequest_t *v17; // [esp+10h] [ebp-1D0h]
  float *v18; // [esp+14h] [ebp-1CCh]
  GFxAmpViewStats *v19; // [esp+24h] [ebp-1BCh]
  int v20; // [esp+34h] [ebp-1ACh]
  float v21; // [esp+38h] [ebp-1A8h]
  CUtlVector<void *,CUtlMemory<void *,int> > v22; // [esp+3Ch] [ebp-1A4h] BYREF
  int v23; // [esp+84h] [ebp-15Ch]
  IShaderDevice *v24; // [esp+A0h] [ebp-140h]

  v2 = 0;
  if ( this->m_blendModeStack.Data.Data != nullptr )
  {
    v3 = *((GFxAmpViewStats **)this + 2578);
    v19 = v3;
    if ( v3 != nullptr )
    {
      GFxAmpViewStats::PushCallstack(this: v3, swdHandle: 1u, a3: 0);
      GTimer::GetRawTicks(li: v4, a2: *(float *)&v17, a3: v18);
    }
    if ( this->m_pDevice != nullptr )
    {
      while ( 1 )
      {
        v5 = *(_DWORD *)(this->S3DDisplay + 8 * v2 + 4);
        if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 16))(a1: v5) != 0 )
          break;
        if ( (IDirect3DDevice9 *)++v2 >= this->m_pDevice )
          goto LABEL_33;
      }
      v21 = this->m_currentMatrix.M_[1][1];
      GFxDisplayContext::GFxDisplayContext(this: &v22);
      if ( v23 != 0 && *(_DWORD *)(v23 + 12) != 0 )
      {
        v6 = v24;
        *((_DWORD *)this + 2333) |= 2u;
        if ( v6 != nullptr )
          GRefCountImpl::AddRef(this: v6, a2: (VertexShaderHandle_t__ *)v17);
        v7 = (IShaderAPI *)LODWORD(this->m_projection.M_[0][1]);
        if ( v7 != nullptr )
          GRefCountImpl::Release(this: v7);
        v8 = v23;
        LODWORD(this->m_projection.M_[0][1]) = v24;
        (*(void (__thiscall **)(_DWORD, _DWORD, $BA6E4D6F36D1F7A012BE29DE786EED17 *, float, float, float, float))(**(_DWORD **)(v8 + 12) + 48))(
          a1: *(_DWORD *)(v8 + 12),
          a2: LODWORD(this->m_glyphVertexBuffer[83].y),
          a3: &this->m_textures.___u1,
          a4: this->m_userMatrix.M_[1][2],
          a5: this->m_viewportMatrix.M_[0][1],
          a6: this->m_viewportMatrix.M_[0][0],
          a7: this->m_viewportMatrix.M_[0][2]);
        GFxMovieRoot::Setup3DDisplay(
          (const CUtlMemory<unsigned char,int> *)this,
          result: (_D3DADAPTER_IDENTIFIER9 *)&v22);
        v9 = this->m_projection.M_[0][0];
        if ( v9 != 0.0 && *(_DWORD *)LODWORD(v9) != 0 )
        {
          GHashSetBase<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>,GFixedSizeHash<GPtr<GFxVideoProvider>>,GAllocatorGH<GPtr<GFxVideoProvider>,2>,GHashsetCachedEntry<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>>>::Begin();
          v10 = v21;
          while ( v20 != 0 && *(_DWORD *)v20 != 0 && SLODWORD(v10) <= *(_DWORD *)(*(_DWORD *)v20 + 4) )
          {
            v11 = (GRefCountNTSImpl **)(*(_DWORD *)v20 + 12 * LODWORD(v10) + 16);
            if ( *v11 != nullptr )
            {
              ++(*v11)->RefCount;
              v10 = v21;
            }
            v12 = *v11;
            ((void (__thiscall *)(GRefCountNTSImpl *, _DWORD))(*v11)->__vftable[3].dtr_GRefCountImplCore)(
              a1: *v11,
              a2: *(_DWORD *)(v23 + 12));
            GRefCountNTSImpl::Release(this: v12);
            v13 = *(_DWORD *)(*(_DWORD *)v20 + 4);
            if ( SLODWORD(v10) <= (int)v13 )
            {
              ++LODWORD(v10);
              v21 = v10;
              if ( LODWORD(v10) <= v13 )
              {
                v14 = (_DWORD *)(*(_DWORD *)v20 + 12 * LODWORD(v10) + 8);
                do
                {
                  if ( *v14 != -2 )
                    break;
                  ++LODWORD(v10);
                  v14 += 3;
                  v21 = v10;
                }
                while ( LODWORD(v10) <= v13 );
              }
            }
            v3 = v19;
          }
        }
        for ( i = nullptr; i < this->m_pDevice; i = (IDirect3DDevice9 *)((char *)i + 1) )
        {
          v16 = *(_DWORD *)(this->S3DDisplay + 8 * (_DWORD)i + 4);
          (*(void (__thiscall **)(int, CUtlVector<void *,CUtlMemory<void *,int> > *))(*(_DWORD *)v16 + 116))(
            a1: v16,
            a2: &v22);
        }
        GFxMovieRoot::DisplayTopmostLevelCharacters(
          a1: (int)this,
          a2: (const CMaterialDict::MissingMaterial_t *)i,
          context: (int *)&v22);
        GFxMovieRoot::DisplayFocusRect((GFxMovieRoot *)this, a2: (const struct GFxDisplayContext *)&v22);
        (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v23 + 12) + 52))(a1: *(_DWORD *)(v23 + 12));
        GFxMeshCacheManager::EndDisplay(result: v17);
        *((_DWORD *)this + 2333) &= ~2u;
      }
      GFxDisplayContext::~GFxDisplayContext(this: &v22, a2: (void *const *)v17);
    }
LABEL_33:
    if ( v3 != nullptr )
    {
      GTimer::GetRawTicks(li: *(float *)&this, a2: *(float *)&v17, a3: v18);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C3D30
// Name: public: virtual void GFxMovieRoot::SetPause(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxMovieRoot::SetPause(float this, const IDirect3DResource9 *result)
{
  _DWORD *v3; // eax
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rax
  _DWORD *v6; // ecx
  _DWORD *v7; // edi
  int v8; // ebx
  unsigned int v9; // esi
  unsigned int v10; // ecx
  _DWORD *v11; // eax
  int v12; // eax
  GRefCountNTSImpl **v13; // eax
  GRefCountNTSImpl *v14; // edi
  unsigned int v15; // eax
  _DWORD *v16; // ecx
  float v18; // [esp+0h] [ebp-14h]
  float *v19; // [esp+4h] [ebp-10h]

  LOBYTE(v3) = (*(_DWORD *)(LODWORD(this) + 9332) & 0x100000) != 0;
  if ( ((*(_DWORD *)(LODWORD(this) + 9332) & 0x100000) == 0 || (_BYTE)result == 0)
    && ((*(_DWORD *)(LODWORD(this) + 9332) & 0x100000) != 0 || (_BYTE)result != 0) )
  {
    if ( (_BYTE)result != 0 )
    {
      *(_DWORD *)(LODWORD(this) + 9332) |= 0x100000u;
      GTimer::GetTicks(a1: this, a2: v18, a3: v19);
      *(_QWORD *)(LODWORD(this) + 9368) = v4 / 0x3E8;
    }
    else
    {
      *(_DWORD *)(LODWORD(this) + 9332) &= ~0x100000u;
      GTimer::GetTicks(a1: this, a2: v18, a3: v19);
      *(_QWORD *)(LODWORD(this) + 9360) += v5 / 0x3E8 - *(_QWORD *)(LODWORD(this) + 9368);
    }
    v6 = *(_DWORD **)(LODWORD(this) + 10244);
    if ( v6 != nullptr )
    {
      do
      {
        v7 = (_DWORD *)v6[33];
        (*(void (__stdcall **)(const IDirect3DResource9 *))(*v6 + 252))(a1: result);
        v6 = v7;
      }
      while ( v7 != nullptr );
    }
    v3 = *(_DWORD **)(LODWORD(this) + 244);
    v8 = LODWORD(this) + 244;
    v9 = 0;
    if ( v3 != nullptr && *v3 != 0 )
    {
      v10 = v3[1];
      v11 = v3 + 2;
      do
      {
        if ( *v11 != -2 )
          break;
        ++v9;
        v11 += 3;
      }
      while ( v9 <= v10 );
      while ( v8 != 0 )
      {
        v12 = *(_DWORD *)v8;
        if ( *(_DWORD *)v8 == 0 || (signed int)v9 > *(_DWORD *)(v12 + 4) )
          break;
        v13 = (GRefCountNTSImpl **)(v12 + 12 * v9 + 16);
        if ( *v13 != nullptr )
          ++(*v13)->RefCount;
        v14 = *v13;
        ((void (__thiscall *)(GRefCountNTSImpl *, const IDirect3DResource9 *))(*v13)->__vftable[4].dtr_GRefCountImplCore)(
          a1: *v13,
          a2: result);
        GRefCountNTSImpl::Release(this: v14);
        v15 = *(_DWORD *)(*(_DWORD *)v8 + 4);
        if ( (int)v9 <= (int)v15 && ++v9 <= v15 )
        {
          v16 = (_DWORD *)(*(_DWORD *)v8 + 12 * v9 + 8);
          do
          {
            if ( *v16 != -2 )
              break;
            ++v9;
            v16 += 3;
          }
          while ( v9 <= v15 );
        }
      }
      LOBYTE(v3) = ((int (__thiscall *)(GMemoryHeap *, _DWORD))GMemory::pGlobalHeap->Free)(
                     a1: GMemory::pGlobalHeap,
                     a2: 0);
    }
  }
  return (char)v3;
}

//------------------------------------------------------------------------------
// Address: 0x100C3EA0
// Name: public: void GFxMovieRoot::FinalizeProcessFocusKey(struct GFxMovieRoot::ProcessFocusKeyInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::FinalizeProcessFocusKey(
        GFxMovieRoot *this@<ecx>,
        GMemoryHeap *a2@<ebx>,
        GRefCountNTSImpl *a3)
{
  GRefCountNTSImpl *v3; // edi
  int v4; // edx
  char *v5; // esi
  int v6; // eax
  const ISteamRemoteStorage *v7; // ebx
  GRefCountNTSImpl *v8; // ecx
  int v10; // [esp+0h] [ebp-18h]
  const char *v11; // [esp+4h] [ebp-14h]
  ISteamRemoteStorage *v12; // [esp+8h] [ebp-10h]
  GRefCountNTSImpl_vtbl *v13; // [esp+Ch] [ebp-Ch]
  volatile int RefCount; // [esp+10h] [ebp-8h]
  GRefCountNTSImpl_vtbl *v15; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = 52 * *((unsigned __int8 *)this + BYTE2(a3[3].RefCount) + 10228);
  v5 = (char *)this + v4 + 9392;
  if ( BYTE1(a3[4].__vftable) != 0 && (*v5 & 1) != 0 )
  {
    v6 = (int)a3[1].__vftable;
    if ( v6 >= 0 && v6 < *(_DWORD *)((char *)this + v4 + 9400) )
    {
      v7 = *(const ISteamRemoteStorage **)(*(_DWORD *)((char *)this + v4 + 9396) + 4 * v6);
      GWeakPtr<GFxASCharacter>::operator GPtr<GFxASCharacter>(
        a1: (unsigned int)&a3,
        a2,
        a3: v10,
        a4: v11,
        a5: (int)this);
      v8 = a3;
      if ( a3 != nullptr )
      {
        ++a3->RefCount;
        GRefCountNTSImpl::Release(this: a3);
        v8 = a3;
      }
      if ( v8 != (GRefCountNTSImpl *)v7 )
      {
        *((_WORD *)v5 + 14) = v3[3].RefCount;
        v15 = v3[2].__vftable;
        RefCount = v3[2].RefCount;
        v13 = v3[3].__vftable;
        *((float *)v5 + 8) = *(float *)&v3[1].RefCount;
        *((float *)v5 + 9) = *(float *)&v15;
        *((float *)v5 + 10) = *(float *)&RefCount;
        *((float *)v5 + 11) = *(float *)&v13;
        GFxMovieRoot::QueueSetFocusTo(this: v12, ch: v7, a3: nullptr, controllerIdx: BYTE2(v3[3].RefCount), a5: 2);
        v5[48] = v7 == nullptr
              || ((int (__thiscall *)(const ISteamRemoteStorage *))v7->__vftable[2].FileWrite)(a1: v7) != 4;
        v12[2333].__vftable = (ISteamRemoteStorage_vtbl *)((int)v12[2333].__vftable | 0x400);
        v8 = a3;
      }
      if ( v8 != nullptr )
        GRefCountNTSImpl::Release(this: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C3FA0
// Name: public: void GFxMovieRoot::SetFocusTo(class GFxASCharacter __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::SetFocusTo(
        ISteamRemoteStorage *this,
        GRefCountWeakSupportImpl *result,
        unsigned int controllerIdx)
{
  int v4; // esi
  _DWORD *v5; // eax
  GRefCountNTSImpl *v6; // edi

  v4 = 52 * (*((unsigned __int8 *)this + controllerIdx + 10228) + 181);
  v5 = *(ISteamRemoteStorage_vtbl **)((char *)&this->__vftable + v4);
  v6 = nullptr;
  if ( v5 != nullptr )
  {
    if ( v5[1] != 0 )
    {
      v6 = (GRefCountNTSImpl *)v5[1];
      if ( v6 != nullptr )
      {
        ++v6->RefCount;
        ++v6->RefCount;
        GRefCountNTSImpl::Release(this: v6);
      }
    }
    else
    {
      if ( (*v5)-- == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
      *(ISteamRemoteStorage_vtbl **)((char *)&this->__vftable + v4) = nullptr;
    }
  }
  if ( v6 == result )
  {
LABEL_11:
    if ( v6 == nullptr )
      return;
    goto LABEL_12;
  }
  if ( v6 == nullptr
    || v6[4].__vftable == nullptr
    || ((unsigned __int8 (__thiscall *)(GRefCountNTSImpl *, GRefCountWeakSupportImpl *, unsigned int, int))v6->__vftable[60].dtr_GRefCountImplCore)(
         a1: v6,
         a2: result,
         a3: controllerIdx,
         a4: 2) != 0 )
  {
    GFxMovieRoot::TransferFocus(this, a2: result, controllerIdx, a4: 2);
    if ( result != nullptr )
      ((void (__thiscall *)(GRefCountWeakSupportImpl *, unsigned int))result->__vftable[59].dtr_GRefCountImplCore)(
        a1: result,
        a2: controllerIdx);
    goto LABEL_11;
  }
LABEL_12:
  GRefCountNTSImpl::Release(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100C4060
// Name: public: void GFxMovieRoot::SetKeyboardFocusTo(class GFxASCharacter __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::SetKeyboardFocusTo(
        CImagePacker *this,
        GRefCountWeakSupportImpl *result,
        unsigned int controllerIdx)
{
  int v4; // esi
  _DWORD *v5; // eax
  GRefCountNTSImpl *v6; // ebx
  GRefCountWeakSupportImpl *pWeakProxy; // esi
  int v8; // ebx
  bool v9; // zf
  CUtlMemory<CImagePacker,int> v10; // [esp-10h] [ebp-20h]
  struct GFxASCharacter *v11; // [esp+0h] [ebp-10h]
  struct GFxASCharacter *v12; // [esp+4h] [ebp-Ch]
  IShaderAPI *v13; // [esp+Ch] [ebp-4h]

  v13 = (IShaderAPI *)(*(int (__thiscall **)(int *, int))(this->m_pLightmapWavefront[0] + 12))(
                        a1: this->m_pLightmapWavefront,
                        a2: 27);
  if ( v13 != nullptr )
  {
    v4 = 52 * (*((unsigned __int8 *)this + controllerIdx + 10228) + 181);
    v5 = *(_DWORD **)((char *)&this->m_MaxLightmapWidth + v4);
    v6 = nullptr;
    if ( v5 != nullptr )
    {
      if ( v5[1] != 0 )
      {
        v6 = (GRefCountNTSImpl *)v5[1];
        if ( v6 != nullptr )
        {
          ++v6->RefCount;
          ++v6->RefCount;
          GRefCountNTSImpl::Release(this: v6);
        }
      }
      else
      {
        v9 = (*v5)-- == 1;
        if ( v9 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
        *(int *)((char *)&this->m_MaxLightmapWidth + v4) = 0;
      }
    }
    *(_QWORD *)&v10.m_nAllocationCount = __PAIR64__((unsigned int)result, (unsigned int)v6);
    v10.m_pMemory = this;
    pWeakProxy = (GRefCountWeakSupportImpl *)GFxIMEManager::HandleFocus(
                                               this: (GFxIMEManager *)v13,
                                               a2: v10,
                                               a3: nullptr,
                                               a4: v11,
                                               a5: v12);
    if ( v6 != nullptr )
      GRefCountNTSImpl::Release(this: v6);
  }
  else
  {
    pWeakProxy = result;
  }
  v8 = (int)this + 52 * *((unsigned __int8 *)this + controllerIdx + 10228) + 9392;
  *(_BYTE *)(v8 + 48) = pWeakProxy == nullptr
                     || ((int (__thiscall *)(GRefCountWeakSupportImpl *))pWeakProxy->__vftable[44].dtr_GRefCountImplCore)(a1: pWeakProxy) != 4;
  *(_WORD *)(v8 + 28) = 0;
  GFxMovieRoot::SetFocusTo((ISteamRemoteStorage *)this, result: pWeakProxy, controllerIdx);
  if ( *(_BYTE *)(v8 + 48) != 0 )
  {
    v9 = pWeakProxy == nullptr;
    if ( pWeakProxy != nullptr )
    {
      do
      {
        if ( ((unsigned __int8 (__thiscall *)(GRefCountWeakSupportImpl *))pWeakProxy->__vftable[4].dtr_GRefCountImplCore)(a1: pWeakProxy) == 0 )
          break;
        pWeakProxy = (GRefCountWeakSupportImpl *)pWeakProxy[2].pWeakProxy;
      }
      while ( pWeakProxy != nullptr );
      v9 = pWeakProxy == nullptr;
    }
    *(_BYTE *)(v8 + 48) = v9;
  }
  if ( v13 != nullptr )
    GRefCountImpl::Release(this: v13);
}

//------------------------------------------------------------------------------
// Address: 0x100C4180
// Name: public: void GFxMovieRoot::ResetFocusForChar(class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::ResetFocusForChar(ISteamRemoteStorage *a1@<ecx>, int a2@<edi>, GRefCountNTSImpl *a3)
{
  ISteamRemoteStorage *v4; // edi
  ISteamRemoteStorage_vtbl *v5; // eax
  GRefCountNTSImpl *FileRead; // esi
  ISteamRemoteStorage_vtbl *v7; // eax
  GRefCountNTSImpl *v8; // eax
  unsigned int v9; // edi
  int v10; // esi
  ISteamRemoteStorage_vtbl *v11; // eax
  GRefCountNTSImpl *v12; // esi
  ISteamRemoteStorage_vtbl *v13; // eax
  bool v14; // zf
  unsigned __int64 v15; // [esp-Ch] [ebp-28h]
  unsigned int cc; // [esp+4h] [ebp-18h]
  unsigned int m; // [esp+8h] [ebp-14h]
  ISteamRemoteStorage *v18; // [esp+Ch] [ebp-10h]
  unsigned int i; // [esp+10h] [ebp-Ch]
  GRefCountNTSImpl *v20; // [esp+14h] [ebp-8h]

  i = 0;
  if ( a1[2556].__vftable != nullptr )
  {
    HIDWORD(v15) = a2;
    v4 = a1 + 2353;
    v18 = a1 + 2353;
    do
    {
      v5 = v4->__vftable;
      FileRead = nullptr;
      if ( v4->__vftable != nullptr )
      {
        if ( v5->FileRead != nullptr )
        {
          FileRead = (GRefCountNTSImpl *)v5->FileRead;
          if ( FileRead != nullptr )
          {
            ++FileRead->RefCount;
            ++FileRead->RefCount;
            GRefCountNTSImpl::Release(this: FileRead);
          }
        }
        else
        {
          v14 = v5->FileWrite-- == (bool (__thiscall *)(ISteamRemoteStorage *, const char *, const void *, int))1;
          if ( v14 )
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
          v4->__vftable = nullptr;
        }
      }
      if ( FileRead != nullptr )
        GRefCountNTSImpl::Release(this: FileRead);
      if ( FileRead == a3 )
      {
        v7 = v4->__vftable;
        v20 = nullptr;
        if ( v4->__vftable != nullptr )
        {
          if ( v7->FileRead != nullptr )
          {
            v8 = (GRefCountNTSImpl *)v7->FileRead;
            v20 = v8;
            if ( v8 != nullptr )
            {
              ++v8->RefCount;
              ++v8->RefCount;
              GRefCountNTSImpl::Release(this: v8);
              LODWORD(v15) = i;
              m = GFxMovieRoot::GetControllerMaskByFocusGroup(this: a1, focusGroupIndex: v15);
              v9 = 0;
              for ( cc = ((int (__thiscall *)(ISteamRemoteStorage *))a1->__vftable[2].IsCloudEnabledForApp)(a1);
                    m != 0;
                    m >>= 1 )
              {
                if ( v9 >= cc )
                  break;
                v10 = 13 * (*((unsigned __int8 *)&a1[2557].__vftable + v9) + 181);
                v11 = a1[v10].__vftable;
                if ( v11 != nullptr )
                {
                  if ( v11->FileRead != nullptr )
                  {
                    v12 = (GRefCountNTSImpl *)v11->FileRead;
                    if ( v12 != nullptr )
                    {
                      ++v12->RefCount;
                      ++v12->RefCount;
                      GRefCountNTSImpl::Release(this: v12);
                      if ( v12[4].__vftable == nullptr
                        || ((unsigned __int8 (__thiscall *)(GRefCountNTSImpl *, _DWORD, unsigned int, int))v12->__vftable[60].dtr_GRefCountImplCore)(
                             a1: v12,
                             a2: 0,
                             a3: v9,
                             a4: 2) != 0 )
                      {
                        GFxMovieRoot::TransferFocus(this: a1, a2: nullptr, controllerIdx: v9, a4: 2);
                      }
                      GRefCountNTSImpl::Release(this: v12);
                    }
                  }
                  else
                  {
                    v14 = v11->FileWrite-- == (bool (__thiscall *)(ISteamRemoteStorage *, const char *, const void *, int))1;
                    if ( v14 )
                      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
                    a1[v10].__vftable = nullptr;
                  }
                }
                ++v9;
              }
              v4 = v18;
            }
          }
          else
          {
            v14 = v7->FileWrite-- == (bool (__thiscall *)(ISteamRemoteStorage *, const char *, const void *, int))1;
            if ( v14 )
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
            v4->__vftable = nullptr;
          }
        }
        v13 = v4->__vftable;
        if ( v4->__vftable != nullptr )
        {
          v14 = v13->FileWrite-- == (bool (__thiscall *)(ISteamRemoteStorage *, const char *, const void *, int))1;
          if ( v14 )
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v13);
        }
        v4->__vftable = nullptr;
        if ( v20 != nullptr )
          GRefCountNTSImpl::Release(this: v20);
      }
      v4 += 13;
      ++i;
      v18 = v4;
    }
    while ( (ISteamRemoteStorage_vtbl *)i < a1[2556].__vftable );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C4370
// Name: public: virtual void GFxMovieRoot::DisplayPrePass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::DisplayPrePass(ScaleformRenderer *this)
{
  GFxAmpViewStats *v2; // ebx
  float v3; // ecx
  int v4; // ecx
  unsigned int v5; // edx
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // esi
  GFxCharacter *v9; // ebx
  int v10; // ebx
  int v11; // ebx
  void (__thiscall ***v12)(_DWORD, int); // esi
  float v13; // ecx
  const CMaterialDict::MissingMaterial_t *v14; // [esp+10h] [ebp-1F4h]
  float v15; // [esp+10h] [ebp-1F4h]
  float *v16; // [esp+14h] [ebp-1F0h]
  GFxAmpViewStats *v17; // [esp+24h] [ebp-1E0h]
  unsigned int n; // [esp+34h] [ebp-1D0h]
  float v19; // [esp+38h] [ebp-1CCh]
  float v20; // [esp+3Ch] [ebp-1C8h]
  int v21; // [esp+40h] [ebp-1C4h]
  float v22; // [esp+40h] [ebp-1C4h]
  unsigned int i; // [esp+44h] [ebp-1C0h]
  CUtlVector<void *,CUtlMemory<void *,int> > v24; // [esp+48h] [ebp-1BCh] BYREF
  float v25; // [esp+6Ch] [ebp-198h]
  float v26; // [esp+70h] [ebp-194h]
  float v27; // [esp+74h] [ebp-190h]
  float v28; // [esp+78h] [ebp-18Ch]
  int v29; // [esp+7Ch] [ebp-188h]
  int v30; // [esp+80h] [ebp-184h]
  int v31; // [esp+8Ch] [ebp-178h]
  int v32; // [esp+90h] [ebp-174h]
  struct GMatrix2D v33; // [esp+1E8h] [ebp-1Ch] BYREF

  if ( *((_DWORD *)this + 2331) != 0 )
  {
    v2 = *((GFxAmpViewStats **)this + 2578);
    v17 = v2;
    if ( v2 != nullptr )
    {
      GFxAmpViewStats::PushCallstack(this: v2, swdHandle: 1u, a3: 0x1Cu);
      GTimer::GetRawTicks(li: v3, a2: *(float *)&v14, a3: v16);
    }
    GFxDisplayContext::GFxDisplayContext(this: &v24);
    if ( v32 != 0 )
    {
      v4 = *(_DWORD *)(v32 + 12);
      if ( v4 != 0 )
      {
        (*(void (__thiscall **)(int, _DWORD, $BA6E4D6F36D1F7A012BE29DE786EED17 *, float, float, float, float))(*(_DWORD *)v4 + 48))(
          a1: v4,
          a2: 0,
          a3: &this->m_textures.___u1,
          a4: this->m_userMatrix.M_[1][2],
          a5: this->m_viewportMatrix.M_[0][1],
          a6: this->m_viewportMatrix.M_[0][0],
          a7: this->m_viewportMatrix.M_[0][2]);
        v5 = *((_DWORD *)this + 2331);
        v6 = 0;
        i = 0;
        for ( n = v5; v6 < v5; i = v6 )
        {
          v7 = *(_DWORD *)(*((_DWORD *)this + 2330) + 4 * v6);
          v8 = *(_DWORD *)(v7 + 172);
          v21 = v7;
          if ( v8 != 0 )
          {
            v9 = *(GFxCharacter **)(v7 + 32);
            GMatrix2D::SetIdentity(result: v14);
            if ( v9 != nullptr )
            {
              GFxCharacter::GetWorldMatrix(this: v9, pmat: (CMaterialDict *)&v33);
              v24.m_Memory.m_nAllocationCount = (int)&v33;
            }
            else
            {
              v24.m_Memory.m_nAllocationCount = (int)&GMatrix2D::Identity;
            }
            v24.m_Memory.m_pMemory = (void **)GRenderer::Cxform::Identity;
            v10 = *(_DWORD *)(v8 + 16);
            if ( v10 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)(v10 + 4), Value: -1) == 1 )
              (**(void (__thiscall ***)(int, int))v10)(a1: v10, a2: 1);
            *(_DWORD *)(v8 + 16) = 0;
            (*(void (__thiscall **)(int, CUtlVector<void *,CUtlMemory<void *,int> > *))(*(_DWORD *)v21 + 116))(
              a1: v21,
              a2: &v24);
            v22 = v26;
            v19 = v27;
            v20 = v28;
            *(float *)(v8 + 20) = v25;
            *(float *)(v8 + 24) = v22;
            *(float *)(v8 + 28) = v19;
            *(float *)(v8 + 32) = v20;
            *(_DWORD *)(v8 + 36) = v29;
            *(_DWORD *)(v8 + 40) = v30;
            if ( v31 != 0 )
              InterlockedExchangeAdd(Addend: (volatile LONG *)(v31 + 4), Value: 1);
            v11 = *(_DWORD *)(v8 + 16);
            if ( v11 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)(v11 + 4), Value: -1) == 1 )
              (**(void (__thiscall ***)(int, int))v11)(a1: v11, a2: 1);
            *(_DWORD *)(v8 + 16) = v31;
            if ( v31 != 0 )
            {
              v12 = (void (__thiscall ***)(_DWORD, int))v31;
              if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(v31 + 4), Value: -1) == 1 )
                (**v12)(a1: v12, a2: 1);
            }
            v6 = i;
            v5 = n;
            v2 = v17;
            v31 = 0;
          }
          ++v6;
        }
        (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v32 + 12) + 52))(a1: *(_DWORD *)(v32 + 12));
      }
    }
    GFxDisplayContext::~GFxDisplayContext(this: &v24, a2: (void *const *)v14);
    if ( v2 != nullptr )
    {
      GTimer::GetRawTicks(li: v13, a2: v15, a3: v16);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C4670
// Name: public: struct GFxMovieRoot::InvokeAliasInfo __near & GFxMovieRoot::InvokeAliasInfo::operator=(struct GFxMovieRoot::InvokeAliasInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
GPtr<GFxActionControl> *__thiscall GFxMovieRoot::InvokeAliasInfo::operator=(
        GPtr<GFxActionControl> *this,
        const GPtr<GFxActionControl> *__that)
{
  GFxActionControl *pObject; // eax
  GFxCharacterHandle *v4; // esi

  if ( __that->pObject != nullptr )
    __that->pObject->SType = (__that->pObject->SType + 1) & 0x8FFFFFFF;
  if ( this->pObject != nullptr )
    GRefCountBaseGC<323>::Release(a1: this->pObject);
  this->pObject = __that->pObject;
  pObject = __that[1].pObject;
  if ( pObject != nullptr )
    ++pObject->__vftable;
  v4 = *((GFxCharacterHandle **)this + 1);
  if ( v4 != nullptr )
  {
    *v4 = (GFxCharacterHandle)((char *)*v4 - 1);
    if ( (int)*v4 <= 0 )
    {
      GFxCharacterHandle::~GFxCharacterHandle(this: v4);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
    }
  }
  *(this + 1) = __that[1];
  GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)(this + 2), a2: (const struct GASFunctionRefBase *)&__that[2]);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C4840
// Name: public: GFxLoadQueueEntryMT_LoadMovie::GFxLoadQueueEntryMT_LoadMovie(class GFxLoadQueueEntry __near *,class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
GFxLoadQueueEntryMT_LoadMovie *__thiscall GFxLoadQueueEntryMT_LoadMovie::GFxLoadQueueEntryMT_LoadMovie(
        GFxLoadQueueEntryMT_LoadMovie *this,
        struct GFxLoadQueueEntry *a2,
        struct GFxMovieRoot *a3)
{
  int v4; // eax
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v5; // ecx
  GRefCountNTSImpl *v6; // eax
  GRefCountNTSImpl *v7; // edi
  int v8; // eax
  int v9; // edx
  int v10; // edi
  unsigned int v11; // ecx
  unsigned int v12; // eax
  _DWORD *v13; // ebx
  struct GFxSprite *LevelMovie; // eax
  int v15; // eax
  GFxMoviePreloadTask *v16; // eax
  GFxMoviePreloadTask *v17; // edi
  IShaderAPI *v18; // ecx
  IShaderAPI *v19; // edi
  int v21; // [esp+Ch] [ebp-4h] BYREF
  bool v22; // [esp+1Ch] [ebp+Ch]

  *((_DWORD *)this + 3) = a3;
  *((_DWORD *)this + 4) = a2;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *(_DWORD *)this = &GFxLoadQueueEntryMT_LoadMovie::`vftable';
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 65537;
  v4 = *((_DWORD *)this + 4);
  *((_BYTE *)this + 40) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_BYTE *)this + 48) = 0;
  v5 = *(CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(v4 + 20);
  v22 = false;
  if ( v5 != nullptr )
  {
    GFxCharacterHandle::ResolveCharacter(this: v5, a2: *((GFxMovieRoot **)this + 3));
    v7 = v6;
    if ( v6 != nullptr )
    {
      ++v6->RefCount;
      v8 = ((int (__thiscall *)(GRefCountNTSImpl *))v6->__vftable[23].dtr_GRefCountImplCore)(a1: v6);
      v22 = ((*(int (__thiscall **)(int))(*(_DWORD *)v8 + 44))(a1: v8) & 0x10) != 0;
      GRefCountNTSImpl::Release(this: v7);
    }
  }
  else
  {
    v9 = *(_DWORD *)(v4 + 16);
    if ( v9 == -1 )
      goto LABEL_12;
    v10 = *((_DWORD *)this + 3);
    v11 = *(_DWORD *)(v10 + 40);
    v12 = 0;
    if ( v11 == 0 )
      goto LABEL_9;
    v13 = *(_DWORD **)(v10 + 36);
    while ( *v13 != v9 )
    {
      ++v12;
      v13 += 2;
      if ( v12 >= v11 )
        goto LABEL_9;
    }
    if ( *(_DWORD *)(*(_DWORD *)(v10 + 36) + 8 * v12 + 4) != 0 )
    {
      LevelMovie = GFxMovieRoot::GetLevelMovie(this: (GFxMovieRoot *)v10, level: v9);
    }
    else
    {
LABEL_9:
      if ( GFxMovieRoot::GetLevelMovie(this: (GFxMovieRoot *)v10, level: 0) == nullptr )
        goto LABEL_12;
      LevelMovie = GFxMovieRoot::GetLevelMovie(this: (GFxMovieRoot *)v10, level: 0);
    }
    v15 = (*(int (__thiscall **)(struct GFxSprite *))(*(_DWORD *)LevelMovie + 92))(a1: LevelMovie);
    v22 = ((*(int (__thiscall **)(int))(*(_DWORD *)v15 + 44))(a1: v15) & 0x10) != 0;
  }
LABEL_12:
  v21 = 2;
  v16 = (GFxMoviePreloadTask *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 44, a3: &v21);
  if ( v16 != nullptr )
    v17 = GFxMoviePreloadTask::GFxMoviePreloadTask(
            this: v16,
            a2: *((struct GFxMovieRoot **)this + 3),
            result: (CImagePacker *)(*((_DWORD *)this + 4) + 12),
            a4: v22,
            a5: *((_BYTE *)a2 + 24));
  else
    v17 = nullptr;
  v18 = *((IShaderAPI **)this + 5);
  if ( v18 != nullptr )
    GRefCountImpl::Release(this: v18);
  *((_DWORD *)this + 5) = v17;
  v19 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(*((_DWORD *)this + 3) + 8) + 12))(
                        a1: *((_DWORD *)this + 3) + 8,
                        a2: 23);
  ((void (__thiscall *)(IShaderAPI *, _DWORD))v19->GetLightmapDimensions)(a1: v19, a2: *((_DWORD *)this + 5));
  GRefCountImpl::Release(this: v19);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C49B0
// Name: public: GFxLoadQueueEntryMT_LoadVars::GFxLoadQueueEntryMT_LoadVars(class GFxLoadQueueEntry __near *,class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
GFxLoadQueueEntryMT_LoadVars *__userpurge GFxLoadQueueEntryMT_LoadVars::GFxLoadQueueEntryMT_LoadVars@<eax>(
        GFxLoadQueueEntryMT_LoadVars *this@<ecx>,
        struct GFxLoadQueueEntry *a2,
        CImagePacker a3)
{
  GFxLoadStates *v4; // edi
  int v5; // eax
  struct GFxLoaderImpl *v6; // ebx
  struct GFxStateBag *v7; // eax
  GFxLoadStates *States; // edi
  IShaderAPI *v9; // ecx
  int v10; // eax
  char v11; // al
  GFxLoadVarsTask *v12; // eax
  GFxLoadVarsTask *v13; // edi
  IShaderAPI *v14; // ecx
  IShaderAPI *v15; // edi
  void *v16; // edi
  int v18; // [esp+Ch] [ebp-4h] BYREF

  *((_DWORD *)this + 3) = a3.m_MaxLightmapWidth;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 4) = a2;
  *(_DWORD *)this = &GFxLoadQueueEntryMT_LoadVars::`vftable';
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  v18 = 2;
  v4 = (GFxLoadStates *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 84, a3: &v18);
  if ( v4 != nullptr )
  {
    v5 = *((_DWORD *)this + 3);
    v6 = *(struct GFxLoaderImpl **)(*(_DWORD *)(v5 + 52) + 20);
    v7 = (struct GFxStateBag *)(**(int (__thiscall ***)(int))(v5 + 8))(a1: v5 + 8);
    States = GFxLoadStates::GFxLoadStates(this: v4, a2: v6, a3: v7, a4: nullptr);
  }
  else
  {
    States = nullptr;
  }
  v9 = *((IShaderAPI **)this + 6);
  if ( v9 != nullptr )
    GRefCountImpl::Release(this: v9);
  *((_DWORD *)this + 6) = States;
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&a3);
  v10 = *((_DWORD *)this + 3);
  if ( *(_DWORD *)(v10 + 48) == 0
    || ((*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v10 + 52) + 48))(a1: *(_DWORD *)(v10 + 52)),
        GString::operator=(this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&a3),
        GFxURLBuilder::ExtractFilePath(ppath: (const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(IMaterialInternal *),IMaterialInternal *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&a3),
        v11 == 0) )
  {
    GString::Clear(this: (GString *)&a3);
  }
  v18 = 2;
  v12 = (GFxLoadVarsTask *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 44, a3: &v18);
  if ( v12 != nullptr )
    v13 = GFxLoadVarsTask::GFxLoadVarsTask(
            this: v12,
            a2: *((IShaderDevice **)this + 6),
            result: &a3,
            a4: (CImagePacker *)((char *)a2 + 12));
  else
    v13 = nullptr;
  v14 = *((IShaderAPI **)this + 5);
  if ( v14 != nullptr )
    GRefCountImpl::Release(this: v14);
  *((_DWORD *)this + 5) = v13;
  v15 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(*((_DWORD *)this + 3) + 8) + 12))(
                        a1: *((_DWORD *)this + 3) + 8,
                        a2: 23);
  ((void (__thiscall *)(IShaderAPI *, _DWORD))v15->GetLightmapDimensions)(a1: v15, a2: *((_DWORD *)this + 5));
  GRefCountImpl::Release(this: v15);
  v16 = (void *)(a3.m_MaxLightmapWidth & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((a3.m_MaxLightmapWidth & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v16);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C4B10
// Name: public: GFxLoadQueueEntryMT_LoadXML::GFxLoadQueueEntryMT_LoadXML(class GFxLoadQueueEntry __near *,class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
GFxLoadQueueEntryMT_LoadXML *__userpurge GFxLoadQueueEntryMT_LoadXML::GFxLoadQueueEntryMT_LoadXML@<eax>(
        GFxLoadQueueEntryMT_LoadXML *this@<ecx>,
        struct GFxLoadQueueEntry *a2,
        CImagePacker a3)
{
  GFxLoadStates *v4; // edi
  int v5; // eax
  struct GFxLoaderImpl *v6; // ebx
  struct GFxStateBag *v7; // eax
  GFxLoadStates *States; // edi
  IShaderAPI *v9; // ecx
  int v10; // eax
  char v11; // al
  IShaderDevice *v12; // ecx
  _DWORD *v13; // edi
  IShaderAPI *v14; // ecx
  IShaderAPI *v15; // edi
  void *v16; // edi
  _DWORD v18[8]; // [esp-14h] [ebp-28h] BYREF
  _DWORD *v19; // [esp+Ch] [ebp-8h]
  int v20; // [esp+10h] [ebp-4h] BYREF

  *((_DWORD *)this + 3) = a3.m_MaxLightmapWidth;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 4) = a2;
  *(_DWORD *)this = &GFxLoadQueueEntryMT_LoadXML::`vftable';
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  v20 = 2;
  v4 = (GFxLoadStates *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 84, a3: &v20);
  if ( v4 != nullptr )
  {
    v5 = *((_DWORD *)this + 3);
    v6 = *(struct GFxLoaderImpl **)(*(_DWORD *)(v5 + 52) + 20);
    v7 = (struct GFxStateBag *)(**(int (__thiscall ***)(int))(v5 + 8))(a1: v5 + 8);
    States = GFxLoadStates::GFxLoadStates(this: v4, a2: v6, a3: v7, a4: nullptr);
  }
  else
  {
    States = nullptr;
  }
  v9 = *((IShaderAPI **)this + 6);
  if ( v9 != nullptr )
    GRefCountImpl::Release(this: v9);
  *((_DWORD *)this + 6) = States;
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&a3);
  v10 = *((_DWORD *)this + 3);
  if ( *(_DWORD *)(v10 + 48) == 0
    || ((*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v10 + 52) + 48))(a1: *(_DWORD *)(v10 + 52)),
        GString::operator=(this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&a3),
        v18[4] = &a3,
        GFxURLBuilder::ExtractFilePath(ppath: (const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(IMaterialInternal *),IMaterialInternal *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&a3),
        v11 == 0) )
  {
    GString::Clear(this: (GString *)&a3);
  }
  v20 = 2;
  v19 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 36, a3: &v20);
  if ( v19 != nullptr )
  {
    GASValue::GASValue(this: (GASValue *)v18, a2: (struct GFxLoadQueueEntry *)((char *)a2 + 64));
    v12 = *((IShaderDevice **)a2 + 20);
    if ( v12 != nullptr )
      GRefCountImpl::AddRef(this: v12, a2: (VertexShaderHandle_t__ *)v18[0]);
    v13 = GFxLoadXMLTask::GFxLoadXMLTask(
            this: v19,
            a2: *((IShaderDevice **)this + 6),
            &a3,
            a4: (CImagePacker *)((char *)a2 + 12),
            a5: (GASValue)v18[0],
            a6: v18[1],
            a7: v18[2],
            a8: v18[3],
            a9: *((IShaderDevice **)a2 + 20));
  }
  else
  {
    v13 = nullptr;
  }
  v14 = *((IShaderAPI **)this + 5);
  if ( v14 != nullptr )
    GRefCountImpl::Release(this: v14);
  *((_DWORD *)this + 5) = v13;
  v15 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(*((_DWORD *)this + 3) + 8) + 12))(
                        a1: *((_DWORD *)this + 3) + 8,
                        a2: 23);
  ((void (__thiscall *)(IShaderAPI *, _DWORD))v15->GetLightmapDimensions)(a1: v15, a2: *((_DWORD *)this + 5));
  GRefCountImpl::Release(this: v15);
  v16 = (void *)(a3.m_MaxLightmapWidth & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((a3.m_MaxLightmapWidth & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v16);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C4CA0
// Name: public: GFxLoadQueueEntryMT_LoadCSS::GFxLoadQueueEntryMT_LoadCSS(class GFxLoadQueueEntry __near *,class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
GFxLoadQueueEntryMT_LoadCSS *__userpurge GFxLoadQueueEntryMT_LoadCSS::GFxLoadQueueEntryMT_LoadCSS@<eax>(
        GFxLoadQueueEntryMT_LoadCSS *this@<ecx>,
        struct GFxLoadQueueEntry *a2,
        CImagePacker a3)
{
  GFxLoadStates *v4; // edi
  int v5; // eax
  struct GFxLoaderImpl *v6; // ebx
  struct GFxStateBag *v7; // eax
  GFxLoadStates *States; // edi
  IShaderAPI *v9; // ecx
  int v10; // eax
  char v11; // al
  IShaderDevice *v12; // ecx
  _DWORD *v13; // edi
  IShaderAPI *v14; // ecx
  IShaderAPI *v15; // edi
  void *v16; // edi
  _DWORD v18[8]; // [esp-14h] [ebp-28h] BYREF
  _DWORD *v19; // [esp+Ch] [ebp-8h]
  int v20; // [esp+10h] [ebp-4h] BYREF

  *((_DWORD *)this + 3) = a3.m_MaxLightmapWidth;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 4) = a2;
  *(_DWORD *)this = &GFxLoadQueueEntryMT_LoadCSS::`vftable';
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  v20 = 2;
  v4 = (GFxLoadStates *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 84, a3: &v20);
  if ( v4 != nullptr )
  {
    v5 = *((_DWORD *)this + 3);
    v6 = *(struct GFxLoaderImpl **)(*(_DWORD *)(v5 + 52) + 20);
    v7 = (struct GFxStateBag *)(**(int (__thiscall ***)(int))(v5 + 8))(a1: v5 + 8);
    States = GFxLoadStates::GFxLoadStates(this: v4, a2: v6, a3: v7, a4: nullptr);
  }
  else
  {
    States = nullptr;
  }
  v9 = *((IShaderAPI **)this + 6);
  if ( v9 != nullptr )
    GRefCountImpl::Release(this: v9);
  *((_DWORD *)this + 6) = States;
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&a3);
  v10 = *((_DWORD *)this + 3);
  if ( *(_DWORD *)(v10 + 48) == 0
    || ((*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v10 + 52) + 48))(a1: *(_DWORD *)(v10 + 52)),
        GString::operator=(this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&a3),
        v18[4] = &a3,
        GFxURLBuilder::ExtractFilePath(ppath: (const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(IMaterialInternal *),IMaterialInternal *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&a3),
        v11 == 0) )
  {
    GString::Clear(this: (GString *)&a3);
  }
  v20 = 2;
  v19 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 36, a3: &v20);
  if ( v19 != nullptr )
  {
    GASValue::GASValue(this: (GASValue *)v18, a2: (struct GFxLoadQueueEntry *)((char *)a2 + 84));
    v12 = *((IShaderDevice **)a2 + 25);
    if ( v12 != nullptr )
      GRefCountImpl::AddRef(this: v12, a2: (VertexShaderHandle_t__ *)v18[0]);
    v13 = GFxLoadCSSTask::GFxLoadCSSTask(
            this: v19,
            a2: *((IShaderDevice **)this + 6),
            &a3,
            a4: (CImagePacker *)((char *)a2 + 12),
            a5: (GASValue)v18[0],
            a6: v18[1],
            a7: v18[2],
            a8: v18[3],
            a9: *((IShaderDevice **)a2 + 25));
  }
  else
  {
    v13 = nullptr;
  }
  v14 = *((IShaderAPI **)this + 5);
  if ( v14 != nullptr )
    GRefCountImpl::Release(this: v14);
  *((_DWORD *)this + 5) = v13;
  v15 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(*((_DWORD *)this + 3) + 8) + 12))(
                        a1: *((_DWORD *)this + 3) + 8,
                        a2: 23);
  ((void (__thiscall *)(IShaderAPI *, _DWORD))v15->GetLightmapDimensions)(a1: v15, a2: *((_DWORD *)this + 5));
  GRefCountImpl::Release(this: v15);
  v16 = (void *)(a3.m_MaxLightmapWidth & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((a3.m_MaxLightmapWidth & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v16);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C4E30
// Name: public: GFxMovieRoot::FocusGroupDescr::~FocusGroupDescr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::FocusGroupDescr::~FocusGroupDescr(GMatrix3D *this)
{
  GFxCharacterHandle *v2; // esi
  float v3; // eax
  float v5; // eax
  GRefCountNTSImpl **v6; // esi
  float v7; // ebx

  v2 = (GFxCharacterHandle *)LODWORD(this->M_[1][2]);
  if ( v2 != nullptr )
  {
    *v2 = (GFxCharacterHandle)((char *)*v2 - 1);
    if ( (int)*v2 <= 0 )
    {
      GFxCharacterHandle::~GFxCharacterHandle(this: v2);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
    }
  }
  v3 = this->M_[1][1];
  if ( v3 != 0.0 && (*(_DWORD *)LODWORD(v3))-- == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)LODWORD(v3));
  v5 = this->M_[0][2];
  v6 = (GRefCountNTSImpl **)(LODWORD(this->M_[0][1]) + 4 * LODWORD(v5) - 4);
  if ( v5 != 0.0 )
  {
    v7 = this->M_[0][2];
    do
    {
      if ( *v6 != nullptr )
        GRefCountNTSImpl::Release(this: *v6);
      --v6;
      --LODWORD(v7);
    }
    while ( v7 != 0.0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)LODWORD(this->M_[0][1]));
}

//------------------------------------------------------------------------------
// Address: 0x100C4EB0
// Name: public: class GASString GFxMovieRoot::CreateNewInstanceName(void)
// Source: json
//------------------------------------------------------------------------------
GPtr<IDirect3DVertexShader9> *__thiscall GFxMovieRoot::CreateNewInstanceName(
        _DWORD *this,
        GPtr<IDirect3DVertexShader9> *result)
{
  int v3; // esi
  IDirect3DVertexShader9 *v4; // eax
  unsigned __int16 v6; // [esp+0h] [ebp-34Ch]
  unsigned __int16 v7; // [esp+0h] [ebp-34Ch]
  _DWORD v8[3]; // [esp+Ch] [ebp-340h] BYREF
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v9; // [esp+18h] [ebp-334h] BYREF
  unsigned __int8 v10[48]; // [esp+318h] [ebp-34h] BYREF

  ++*(this + 2296);
  v3 = (int)(this + 2296);
  memset(v10, 0, sizeof(v10));
  v8[1] = v10;
  v8[0] = 2;
  v8[2] = 48;
  GMsgFormat::GMsgFormat(this: (GMsgFormat *)&v9, a2: (const struct GMsgFormat::Sink *)v8);
  GMsgFormat::Parse(result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&stru_102A119C);
  GMsgFormat::FormatD1<unsigned long>(this: (GMsgFormat *)&v9, a2: v3);
  GMsgFormat::FinishFormatD(this: &v9, a2: v6);
  GMsgFormat::~GMsgFormat(this: &v9, data_size: v7);
  GASStringManager::CreateStringNode(this: *(const char **)(*(this + 2289) + 636));
  result->pObject = v4;
  ++v4[2].__vftable;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4F80
// Name: public: void GFxMovieRoot::AddLoadQueueEntryMT(class GFxLoadQueueEntry __near *)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100C5200
// Name: public: void GFxMovieRoot::AddVarLoadQueueEntry(char const __near *,char const __near *,enum GFxLoadQueueEntry::LoadMethod)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::AddVarLoadQueueEntry(int this, IDirect3DStateBlock9 *result, char *a3, GRendererNode *a4)
{
  char *v4; // esi
  const char *v6; // ecx
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v7; // edi
  IDirect3DStateBlock9 *v8; // eax
  IDirect3DStateBlock9 *v9; // eax
  __vc_attributes::event_receiverAttribute *v10; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v11; // eax
  _TAPE_WMI_OPERATIONS *v13; // eax
  GTexture::ChangeHandler::EventType Method; // esi
  int v15; // ecx
  int (__thiscall *v16)(int, int, int *); // eax
  int v17; // esi
  char *v18; // eax
  char *v19; // eax
  char *v20; // edi
  GFxCharacterHandle *v21; // edi
  GRendererNode *v22; // edx
  void *v23; // edi
  LONG v24; // eax
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *v25; // ecx
  int v26; // eax
  int v27; // ecx
  int (__thiscall *v28)(int, int, int *); // edx
  GTextureImplNode *v29; // edi
  int v30; // eax
  IShaderAPI *v31; // eax
  _TAPE_WMI_OPERATIONS *v32; // [esp+0h] [ebp-18h]
  int v33; // [esp+0h] [ebp-18h]
  int v34; // [esp+Ch] [ebp-Ch] BYREF
  int src; // [esp+10h] [ebp-8h] BYREF
  int v36; // [esp+14h] [ebp-4h]

  v4 = (char *)result;
  v6 = *(const char **)(*(_DWORD *)(this + 9156) + 636);
  v7 = nullptr;
  v36 = 0;
  GASStringManager::CreateStringNode(this: v6);
  result = v8;
  ++v8[2].__vftable;
  v9 = result;
  if ( *(_DWORD *)(this + 48) != 0 && result[4].__vftable != nullptr )
  {
    v10 = (__vc_attributes::event_receiverAttribute *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 48) + 112))(a1: *(_DWORD *)(this + 48));
    GASEnvironment::FindTarget(
      this: v10,
      path: (__vc_attributes::event_receiverAttribute::type_e)&result,
      excludeFlags: false);
    v7 = v11;
    v9 = result;
  }
  if ( v9[2].__vftable-- == (IDirect3DStateBlock9_vtbl *)1 )
    GASStringNode::ReleaseNode();
  if ( v7 != nullptr )
  {
    v13 = GASObjectInterface::ToSprite(result: v32);
    if ( v13 == nullptr || (Method = v13[37].Method) == -1 )
    {
      v15 = *(_DWORD *)(this + 32);
      v16 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v15 + 40);
      v34 = 326;
      v17 = v16(a1: v15, a2: 108, a3: &v34);
      if ( v17 != 0 )
      {
        GString::GString(this: (GString *)&src, a2: a3);
        v18 = (char *)DWORD1(v7[6].m_pfnProxied);
        v36 = 1;
        if ( v18 != nullptr )
        {
          a3 = v18;
          v20 = v18;
        }
        else
        {
          GFxASCharacter::CreateCharacterHandle(this: v7);
          v20 = v19;
          a3 = v19;
        }
        GString::GString(this: (CUtlMemory<CImagePacker,int> *)(v17 + 12));
        *(_DWORD *)(v17 + 20) = 0;
        *(_BYTE *)(v17 + 28) = 0;
        *(_BYTE *)(v17 + 44) = 0;
        *(_BYTE *)(v17 + 64) = 0;
        *(_DWORD *)(v17 + 80) = 0;
        *(_BYTE *)(v17 + 84) = 0;
        *(_DWORD *)(v17 + 100) = 0;
        *(_DWORD *)(v17 + 4) = 4;
        if ( v20 != nullptr )
          ++*(_DWORD *)v20;
        v21 = *(GFxCharacterHandle **)(v17 + 20);
        if ( v21 != nullptr )
        {
          *v21 = (GFxCharacterHandle)((char *)*v21 - 1);
          if ( (int)*v21 <= 0 )
          {
            GFxCharacterHandle::~GFxCharacterHandle(this: v21);
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v21);
          }
        }
        v22 = a4;
        *(_DWORD *)(v17 + 20) = a3;
        *(_DWORD *)(v17 + 8) = v22;
        *(_DWORD *)(v17 + 16) = -1;
        *(_DWORD *)v17 = 0;
        GString::operator=(
          this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v17 + 12),
          (int)&src,
          a3: v33);
        *(_BYTE *)(v17 + 24) = 0;
        *(_DWORD *)(v17 + 60) = -1;
        *(_BYTE *)(v17 + 104) = 0;
      }
      else
      {
        v17 = 0;
      }
      if ( (v36 & 1) == 0 )
        goto LABEL_31;
      v23 = (void *)(src & 0xFFFFFFFC);
      v24 = InterlockedExchangeAdd(Addend: (volatile LONG *)((src & 0xFFFFFFFC) + 4), Value: -1);
      goto LABEL_29;
    }
  }
  else
  {
    v25 = *(CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> **)(this + 48);
    result = (IDirect3DStateBlock9 *)&pMem;
    LOBYTE(v34) = (unsigned int)GFxCharacter::GetVersion(this: v25) > 6;
    v26 = GFxMovieRoot::ParseLevelName(
            nptr: v4,
            ptail: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&result,
            caseSensitive: v34);
    Method = v26;
    if ( LOBYTE(result->__vftable) != 0 || v26 == -1 )
      return;
  }
  v27 = *(_DWORD *)(this + 32);
  v28 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v27 + 40);
  v34 = 326;
  v29 = (GTextureImplNode *)v28(a1: v27, a2: 108, a3: &v34);
  if ( v29 != nullptr )
  {
    GString::GString(this: (GString *)&result, a2: a3);
    v36 = 2;
    GFxLoadQueueEntry::GFxLoadQueueEntry(
      this: v29,
      level: Method,
      src: &result,
      a4,
      loadingVars: true,
      queitOpen: false);
    v17 = v30;
  }
  else
  {
    v17 = 0;
  }
  if ( (v36 & 2) != 0 )
  {
    v23 = (void *)((unsigned int)result & 0xFFFFFFFC);
    v24 = InterlockedExchangeAdd(Addend: (volatile LONG *)(((unsigned int)result & 0xFFFFFFFC) + 4), Value: -1);
LABEL_29:
    if ( v24 == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v23);
  }
LABEL_31:
  if ( v17 != 0 )
  {
    v31 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(this + 8) + 12))(a1: this + 8, a2: 23);
    if ( v31 != nullptr )
    {
      GRefCountImpl::Release(this: v31);
      GFxMovieRoot::AddLoadQueueEntryMT(result: (ScaleformRenderTarget *)v17);
    }
    else
    {
      GFxMovieRoot::AddLoadQueueEntry((ScaleformRenderTarget_vtbl **)this, result: (ScaleformRenderTarget *)v17);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C5470
// Name: public: void GFxMovieRoot::AddMovieLoadQueueEntry(class GFxLoadQueueEntry __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::AddMovieLoadQueueEntry(ScaleformRenderTarget_vtbl **this, IShaderAPI *result)
{
  char v2; // bl
  ScaleformRenderTarget_vtbl **v3; // edi
  char v4; // al
  struct GString v5; // eax
  char v6; // al
  void *v7; // esi
  void *v8; // esi
  void *v9; // esi
  IShaderAPI *v11; // eax
  GString v12; // [esp+Ch] [ebp-14h] BYREF
  GString v13; // [esp+10h] [ebp-10h] BYREF
  ScaleformRenderTarget_vtbl **v14; // [esp+14h] [ebp-Ch]
  GString v15; // [esp+18h] [ebp-8h] BYREF
  bool userImageProtocol; // [esp+1Eh] [ebp-2h]
  char v17; // [esp+1Fh] [ebp-1h]
  char result_3; // [esp+2Bh] [ebp+Bh]

  v2 = 0;
  v3 = this;
  v14 = this;
  v12.pData = nullptr;
  if ( result == nullptr )
    return;
  userImageProtocol = false;
  if ( GString::GetLength(this: (GString *)&result[3]) != 0 )
  {
    v4 = *(_BYTE *)(((int)result[3].__vftable & 0xFFFFFFFC) + 8);
    if ( v4 == 105 || v4 == 73 )
    {
      GString::ToLower(this: (CUtlMemory<CImagePacker,int> *)&result[3]);
      v2 = 1;
      if ( strcmp(
             (const char *)((*(_DWORD *)GString::Substring(this: &v15, a2: &v12, a3: 0).HeapTypeBits & 0xFFFFFFFC) + 8),
             (const char *)&stru_102A119C.m_pElements) == 0
        || (v2 = 3,
            v5.pData = GString::Substring(this: &v15, a2: &v13, a3: 0).pData,
            v6 = GString::operator==(this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v5.pData),
            v17 = 0,
            v6 != 0) )
      {
        v17 = 1;
      }
      if ( (v2 & 2) != 0 )
      {
        v7 = (void *)(v13.HeapTypeBits & 0xFFFFFFFC);
        v2 &= ~2u;
        if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v13.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
      }
      if ( (v2 & 1) != 0 )
      {
        v8 = (void *)(v12.HeapTypeBits & 0xFFFFFFFC);
        v2 &= ~1u;
        if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v12.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
      }
      if ( v17 != 0 )
        userImageProtocol = true;
      v9 = (void *)(v15.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v15.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
      v3 = v14;
    }
  }
  if ( GString::GetLength(this: (GString *)&result[3]) == 0 || userImageProtocol )
  {
    v11 = result;
  }
  else
  {
    v2 |= 4u;
    v11 = (IShaderAPI *)((int (__thiscall *)(ScaleformRenderTarget_vtbl **, int))v3[2]->GetUserData)(a1: v3 + 2, a2: 23);
    if ( v11 != nullptr )
    {
      result_3 = 1;
      goto LABEL_25;
    }
  }
  result_3 = 0;
LABEL_25:
  if ( (v2 & 4) != 0 && v11 != nullptr )
    GRefCountImpl::Release(this: v11);
  if ( result_3 != 0 )
    GFxMovieRoot::AddLoadQueueEntryMT((ScaleformRenderTarget *)result);
  else
    GFxMovieRoot::AddLoadQueueEntry(this: v3, (ScaleformRenderTarget *)result);
}

//------------------------------------------------------------------------------
// Address: 0x100C5630
// Name: public: void GFxMovieRoot::AddVarLoadQueueEntry(class GFxASCharacter __near *,char const __near *,enum GFxLoadQueueEntry::LoadMethod)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::AddVarLoadQueueEntry(
        GString::DataDesc *a1@<ecx>,
        _TAPE_WMI_OPERATIONS *a2@<esi>,
        unsigned int result,
        char *a4,
        GRendererNode *a5)
{
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v5; // edi
  GString::DataDesc *pData; // ebx
  _TAPE_WMI_OPERATIONS *v7; // eax
  int v8; // ecx
  int (__thiscall *v9)(int, int, int *); // eax
  int v10; // esi
  _DWORD *v11; // ebx
  _DWORD *v12; // eax
  GFxCharacterHandle *v13; // edi
  GRendererNode *v14; // ecx
  void *v15; // edi
  IShaderAPI *v16; // eax
  int v17; // ecx
  int (__thiscall *v18)(int, int, unsigned int *); // edx
  GTextureImplNode *v19; // esi
  int v20; // eax
  int v21; // [esp-4h] [ebp-18h]
  int level; // [esp+8h] [ebp-Ch] BYREF
  GString v23; // [esp+Ch] [ebp-8h] BYREF
  int v24; // [esp+10h] [ebp-4h]

  v5 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)result;
  pData = a1;
  v23.pData = a1;
  v24 = 0;
  if ( result != 0 )
  {
    v7 = GASObjectInterface::ToSprite(result: a2);
    if ( v7 != nullptr && (level = v7[37].Method) != -1 )
    {
      v17 = *(_DWORD *)pData[2].Data;
      v18 = *(int (__thiscall **)(int, int, unsigned int *))(*(_DWORD *)v17 + 40);
      result = 326;
      v19 = (GTextureImplNode *)v18(a1: v17, a2: 108, a3: &result);
      if ( v19 != nullptr )
      {
        GString::GString(this: &v23, a2: a4);
        v24 = 2;
        GFxLoadQueueEntry::GFxLoadQueueEntry(
          this: v19,
          (GTexture::ChangeHandler::EventType)level,
          src: &v23,
          a4: a5,
          loadingVars: true,
          queitOpen: false);
        v10 = v20;
      }
      else
      {
        v10 = 0;
      }
      if ( (v24 & 2) != 0 )
        GString::~GString(this: &v23);
    }
    else
    {
      v8 = *(_DWORD *)pData[2].Data;
      v9 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v8 + 40);
      level = 326;
      v10 = v9(a1: v8, a2: 108, a3: &level);
      if ( v10 != 0 )
      {
        GString::GString(this: (GString *)&result, a2: a4);
        v11 = (_DWORD *)DWORD1(v5[6].m_pfnProxied);
        v24 = 1;
        if ( v11 == nullptr )
        {
          GFxASCharacter::CreateCharacterHandle(this: v5);
          v11 = v12;
        }
        GString::GString(this: (CUtlMemory<CImagePacker,int> *)(v10 + 12));
        *(_DWORD *)(v10 + 20) = 0;
        *(_BYTE *)(v10 + 28) = 0;
        *(_BYTE *)(v10 + 44) = 0;
        *(_BYTE *)(v10 + 64) = 0;
        *(_DWORD *)(v10 + 80) = 0;
        *(_BYTE *)(v10 + 84) = 0;
        *(_DWORD *)(v10 + 100) = 0;
        *(_DWORD *)(v10 + 4) = 4;
        if ( v11 != nullptr )
          ++*v11;
        v13 = *(GFxCharacterHandle **)(v10 + 20);
        if ( v13 != nullptr )
        {
          *v13 = (GFxCharacterHandle)((char *)*v13 - 1);
          if ( (int)*v13 <= 0 )
          {
            GFxCharacterHandle::~GFxCharacterHandle(this: v13);
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v13);
          }
        }
        v14 = a5;
        *(_DWORD *)(v10 + 20) = v11;
        *(_DWORD *)(v10 + 8) = v14;
        *(_DWORD *)(v10 + 16) = -1;
        *(_DWORD *)v10 = 0;
        GString::operator=(
          this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v10 + 12),
          src: (int)&result,
          a3: v21);
        pData = v23.pData;
        *(_BYTE *)(v10 + 24) = 0;
        *(_DWORD *)(v10 + 60) = -1;
        *(_BYTE *)(v10 + 104) = 0;
      }
      else
      {
        v10 = 0;
      }
      if ( (v24 & 1) != 0 )
      {
        v15 = (void *)(result & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((result & 0xFFFFFFFC) + 4), Value: -1) == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v15);
        pData = v23.pData;
      }
    }
    if ( v10 != 0 )
    {
      v16 = (IShaderAPI *)(*(int (__thiscall **)(char *, int))(*(_DWORD *)pData->Data + 12))(a1: pData->Data, a2: 23);
      if ( v16 != nullptr )
      {
        GRefCountImpl::Release(this: v16);
        GFxMovieRoot::AddLoadQueueEntryMT(result: (ScaleformRenderTarget *)v10);
      }
      else
      {
        GFxMovieRoot::AddLoadQueueEntry(
          this: (ScaleformRenderTarget_vtbl **)pData,
          result: (ScaleformRenderTarget *)v10);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C5810
// Name: public: void GFxMovieRoot::AddVarLoadQueueEntry(class GASLoadVarsObject __near *,char const __near *,enum GFxLoadQueueEntry::LoadMethod)
// Source: json
//------------------------------------------------------------------------------
GTextureImplNode *__thiscall GFxMovieRoot::AddVarLoadQueueEntry(
        int this,
        IDirect3DPixelShader9 *result,
        char *a3,
        GRendererNode *a4)
{
  char v5; // bl
  int v6; // ecx
  int (__thiscall *v7)(int, int, int *); // eax
  GTextureImplNode *v8; // eax
  GTextureImplNode *v9; // esi
  IDirect3DPixelShader9 *v10; // esi
  unsigned int v11; // ebx
  IShaderAPI *v12; // eax
  int v13; // [esp+Ch] [ebp-8h] BYREF
  unsigned int url; // [esp+10h] [ebp-4h] BYREF

  v5 = 0;
  v13 = 0;
  v6 = *(_DWORD *)(this + 32);
  v7 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v6 + 40);
  v13 = 326;
  v8 = (GTextureImplNode *)v7(a1: v6, a2: 108, a3: &v13);
  v9 = v8;
  if ( v8 != nullptr )
  {
    GString::GString(this: (GString *)&url, a2: a3);
    v5 = 1;
    v8 = GFxLoadQueueEntry::GFxLoadQueueEntry(this: v9, &url, a3: a4, loadingVars: true, queitOpen: false);
    v10 = (IDirect3DPixelShader9 *)v8;
  }
  else
  {
    v10 = nullptr;
  }
  if ( (v5 & 1) != 0 )
  {
    v11 = url & 0xFFFFFFFC;
    v8 = (GTextureImplNode *)(InterlockedExchangeAdd(Addend: (volatile LONG *)((url & 0xFFFFFFFC) + 4), Value: -1) - 1);
    if ( v8 == nullptr )
      v8 = (GTextureImplNode *)((int (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
                                 a1: GMemory::pGlobalHeap,
                                 a2: v11);
  }
  if ( v10 != nullptr )
  {
    GASValue::SetAsObject(this: (GASValue *)&v10[11], a2: (struct GASObject *)result);
    v12 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(this + 8) + 12))(a1: this + 8, a2: 23);
    if ( v12 != nullptr )
    {
      GRefCountImpl::Release(this: v12);
      return (GTextureImplNode *)GFxMovieRoot::AddLoadQueueEntryMT(result: (ScaleformRenderTarget *)v10);
    }
    else
    {
      return (GTextureImplNode *)GFxMovieRoot::AddLoadQueueEntry(
                                   (ScaleformRenderTarget_vtbl **)this,
                                   result: (ScaleformRenderTarget *)v10);
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100C58E0
// Name: public: void GFxMovieRoot::AddCssLoadQueueEntry(class GASObject __near *,class GFxASCSSFileLoader __near *,char const __near *,enum GFxLoadQueueEntry::LoadMethod)
// Source: json
//------------------------------------------------------------------------------
GTextureImplNode *__thiscall GFxMovieRoot::AddCssLoadQueueEntry(
        int this,
        ScaleformRenderer::FillStyle *result,
        IShaderDevice *a3,
        char *a4,
        GRendererNode *a5)
{
  char v6; // bl
  int v7; // ecx
  int (__thiscall *v8)(int, int, int *); // eax
  GTextureImplNode *v9; // eax
  GTextureImplNode *v10; // esi
  ScaleformRenderer::FillStyle *v11; // esi
  unsigned int v12; // ebx
  IShaderAPI *Raw; // ecx
  IShaderAPI *v14; // eax
  VertexShaderHandle_t__ *v15; // [esp+0h] [ebp-14h]
  int v16; // [esp+Ch] [ebp-8h] BYREF
  unsigned int url; // [esp+10h] [ebp-4h] BYREF

  v6 = 0;
  v16 = 0;
  v7 = *(_DWORD *)(this + 32);
  v8 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v7 + 40);
  v16 = 326;
  v9 = (GTextureImplNode *)v8(a1: v7, a2: 108, a3: &v16);
  v10 = v9;
  if ( v9 != nullptr )
  {
    GString::GString(this: (GString *)&url, a2: a4);
    v6 = 1;
    v9 = GFxLoadQueueEntry::GFxLoadQueueEntry(this: v10, &url, a3: a5, loadingVars: false, queitOpen: false);
    v11 = (ScaleformRenderer::FillStyle *)v9;
  }
  else
  {
    v11 = nullptr;
  }
  if ( (v6 & 1) != 0 )
  {
    v12 = url & 0xFFFFFFFC;
    v9 = (GTextureImplNode *)(InterlockedExchangeAdd(Addend: (volatile LONG *)((url & 0xFFFFFFFC) + 4), Value: -1) - 1);
    if ( v9 == nullptr )
      v9 = (GTextureImplNode *)((int (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
                                 a1: GMemory::pGlobalHeap,
                                 a2: v12);
  }
  if ( v11 != nullptr )
  {
    v11->m_color.Raw = 16;
    GASValue::SetAsObject(
      this: (GASValue *)&v11[1].m_fillTexture.TextureMatrix.M_[1][2],
      a2: (struct GASObject *)result);
    if ( a3 != nullptr )
      GRefCountImpl::AddRef(this: a3, a2: v15);
    Raw = (IShaderAPI *)v11[2].m_color.Raw;
    if ( Raw != nullptr )
      GRefCountImpl::Release(this: Raw);
    v11[2].m_color.Raw = (unsigned int)a3;
    v14 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(this + 8) + 12))(a1: this + 8, a2: 23);
    if ( v14 != nullptr )
    {
      GRefCountImpl::Release(this: v14);
      return (GTextureImplNode *)GFxMovieRoot::AddLoadQueueEntryMT(result: (ScaleformRenderTarget *)v11);
    }
    else
    {
      return (GTextureImplNode *)GFxMovieRoot::AddLoadQueueEntry(
                                   (ScaleformRenderTarget_vtbl **)this,
                                   result: (ScaleformRenderTarget *)v11);
    }
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x100C59D0
// Name: public: struct GFxMovieRoot::ActionEntry __near * GFxMovieRoot::ActionQueueType::InsertEntry(enum GFxActionPriority::Priority)
// Source: json
//------------------------------------------------------------------------------
const GPoint3<float> *__thiscall GFxMovieRoot::ActionQueueType::InsertEntry(int this, const GPoint3<float> *result)
{
  const GPoint3<float> *v3; // eax
  int v4; // ecx
  int (__thiscall *v5)(int, int, int *); // edx
  int v6; // esi
  GRefCountNTSImpl *v7; // ecx
  float *v8; // edx
  int v9; // ecx
  int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = *(const GPoint3<float> **)(this + 76);
  if ( v3 != nullptr )
  {
    *(float *)(this + 76) = v3->x;
    v3->x = 0.0;
    --*(_DWORD *)(this + 84);
  }
  else
  {
    v4 = *(_DWORD *)(this + 92);
    v5 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v4 + 40);
    v10 = 323;
    v6 = v5(a1: v4, a2: 64, a3: &v10);
    v3 = nullptr;
    if ( v6 == 0 )
      return v3;
    *(_DWORD *)(v6 + 8) = 0;
    *(_DWORD *)(v6 + 12) = 0;
    *(_DWORD *)(v6 + 16) = 0;
    *(_DWORD *)(v6 + 20) = 0;
    *(_WORD *)(v6 + 24) = 0;
    *(_DWORD *)(v6 + 26) = 65280;
    *(_BYTE *)(v6 + 40) = 0;
    *(_DWORD *)(v6 + 32) = 0;
    *(_DWORD *)(v6 + 36) = 0;
    *(_DWORD *)(v6 + 48) = 0;
    *(_DWORD *)(v6 + 52) = 0;
    *(_DWORD *)(v6 + 56) = 0;
    *(_DWORD *)v6 = 0;
    *(_DWORD *)(v6 + 4) = 0;
    v7 = *(GRefCountNTSImpl **)(v6 + 12);
    if ( v7 != nullptr )
      GRefCountNTSImpl::Release(this: v7);
    *(_DWORD *)(v6 + 12) = 0;
    *(_DWORD *)(v6 + 60) = 0;
    v3 = (const GPoint3<float> *)v6;
  }
  v8 = *(float **)(this + 12 * (_DWORD)result + 4);
  v9 = this + 12 * (_DWORD)result;
  if ( v8 != nullptr )
  {
    v3->x = *v8;
    **(_DWORD **)(v9 + 4) = v3;
  }
  else
  {
    v3->x = *(float *)v9;
    *(_DWORD *)v9 = v3;
  }
  *(_DWORD *)(v9 + 4) = v3;
  if ( LODWORD(v3->x) == 0 )
    *(_DWORD *)(v9 + 8) = v3;
  v3[5].x = *(float *)(this + 80);
  ++*(_DWORD *)(this + 72);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100C5A90
// Name: public: GASIntervalTimer::~GASIntervalTimer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASIntervalTimer::~GASIntervalTimer(GASIntervalTimer *this)
{
  GFxCharacterHandle *v2; // edi
  GASValue *v3; // edi
  int v4; // ebx
  int v5; // ecx
  bool v6; // zf
  _DWORD *v7; // eax
  int v8; // ecx
  int v9; // ecx

  v2 = *((GFxCharacterHandle **)this + 13);
  if ( v2 != nullptr )
  {
    *v2 = (GFxCharacterHandle)((char *)*v2 - 1);
    if ( (int)*v2 <= 0 )
    {
      GFxCharacterHandle::~GFxCharacterHandle(this: v2);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
    }
  }
  v3 = (GASValue *)(*((_DWORD *)this + 6) + 16 * *((_DWORD *)this + 7) - 16);
  if ( *((_DWORD *)this + 7) != 0 )
  {
    v4 = *((_DWORD *)this + 7);
    do
    {
      GASValue::~GASValue(this: v3);
      v3 -= 4;
      --v4;
    }
    while ( v4 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 6));
  v5 = *((_DWORD *)this + 5);
  v6 = (*(_DWORD *)(v5 + 8))-- == 1;
  if ( v6 )
    GASStringNode::ReleaseNode();
  v7 = *((_DWORD **)this + 4);
  if ( v7 != nullptr )
  {
    v6 = (*v7)-- == 1;
    if ( v6 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
  }
  v8 = *((_DWORD *)this + 3);
  if ( v8 != 0 )
    GRefCountBaseGC<323>::Release(a1: v8);
  if ( (*((_BYTE *)this + 8) & 2) == 0 && *(_DWORD *)this != 0 )
    GRefCountBaseGC<323>::Release(a1: *(_DWORD *)this);
  v6 = (*((_BYTE *)this + 8) & 1) == 0;
  *(_DWORD *)this = 0;
  if ( v6 )
  {
    v9 = *((_DWORD *)this + 1);
    if ( v9 != 0 )
      GRefCountBaseGC<323>::Release(a1: v9);
  }
  *((_DWORD *)this + 1) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C5B50
// Name: public: int GFxMovieRoot::AddIntervalTimer(class GASIntervalTimer __near *)
// Source: json
//------------------------------------------------------------------------------
void *__userpurge GFxMovieRoot::AddIntervalTimer@<eax>(_DWORD *a1@<ecx>, unsigned int timer, const char *a3, int a4)
{
  int v5; // eax
  ScaleformUIImpl *v6; // edi
  unsigned int v7; // esi
  ScaleformUIImpl_vtbl *v8; // ecx
  ScaleformUIImpl_vtbl *v9; // esi
  int v11; // [esp+0h] [ebp-Ch]
  int v12; // [esp+4h] [ebp-8h]

  v5 = a1[2347] + 1;
  a1[2347] = v5;
  v6 = (ScaleformUIImpl *)(a1 + 2344);
  *(_DWORD *)(timer + 48) = v5;
  v7 = a1[2345] + 1;
  if ( v7 >= a1[2345] )
  {
    if ( v7 >= a1[2346] )
      GArrayDataBase<GPtr<GFxASCharacter>,GAllocatorLH<GPtr<GFxASCharacter>,326>,GArrayDefaultPolicy>::Reserve(
        this: v6,
        pheapAddr: v6,
        newCapacity: v7 + (v7 >> 2),
        a4: v11,
        a5: v12);
  }
  else if ( v7 < a1[2346] >> 1 )
  {
    GArrayDataBase<GPtr<GFxASCharacter>,GAllocatorLH<GPtr<GFxASCharacter>,326>,GArrayDefaultPolicy>::Reserve(
      this: v6,
      pheapAddr: v6,
      newCapacity: a1[2345] + 1,
      a4: v11,
      a5: v12);
  }
  v8 = v6->__vftable;
  a1[2345] = v7;
  v9 = (ScaleformUIImpl_vtbl *)((char *)v8 + 4 * v7 - 4);
  if ( v9 != nullptr )
    v9->Connect = (bool (__thiscall *)(IAppSystem *, void *(__cdecl *)(const char *, int *)))timer;
  return (void *)a1[2347];
}

//------------------------------------------------------------------------------
// Address: 0x100C5BC0
// Name: public: virtual bool GFxMovieRoot::GetVariableArray(enum GFxMovie::SetArrayType,char const __near *,unsigned int,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge GFxMovieRoot::GetVariableArray@<al>(
        GFxMovieRoot *this@<ecx>,
        float *a2@<ebx>,
        float a3@<esi>,
        enum GFxMovie::SetArrayType a4,
        const char *a5,
        unsigned int a6,
        void *a7,
        CUtlMap<char const *,int,unsigned short>::CKeyLess putf8Buffer)
{
  GFxAmpViewStats *v10; // ebx
  float v11; // ecx
  __vc_attributes::max_isAttribute *v12; // esi
  const char *v13; // ecx
  int v14; // eax
  float v16; // ecx
  float *v18; // [esp-4h] [ebp-48h]
  float *v19; // [esp+0h] [ebp-44h]
  GASValue v20; // [esp+1Ch] [ebp-28h] BYREF
  unsigned int _CurrentState; // [esp+2Ch] [ebp-18h] BYREF
  char varname[4]; // [esp+30h] [ebp-14h] BYREF
  unsigned int v23[3]; // [esp+34h] [ebp-10h] BYREF

  v23[2] = (unsigned int)this;
  if ( *((_DWORD *)this + 12) == 0 )
    return false;
  v18 = a2;
  v10 = *((GFxAmpViewStats **)this + 2577);
  if ( v10 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v10, swdHandle: 1u, a3: 0x19u);
    GTimer::GetRawTicks(li: v11, a2: *(float *)&v18, a3: v19);
  }
  _controlfp_s(&_CurrentState, newctrl: 0, mask: 0);
  _controlfp_s(_CurrentState: v23, newctrl: 0x10000u, mask: 0x30000u);
  v12 = (__vc_attributes::max_isAttribute *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 12) + 112))(a1: *((_DWORD *)this + 12));
  v13 = *((const char **)v12[30].expression + 159);
  v23[1] = (unsigned int)v12;
  GASStringManager::CreateStringNode(this: v13);
  *(_DWORD *)varname = v14;
  ++*(_DWORD *)(v14 + 8);
  LOBYTE(v20) = 0;
  GASEnvironment::GetVariable(this: v12, varname);
  GASValue::~GASValue(this: &v20);
  if ( (*(_DWORD *)(*(_DWORD *)varname + 8))-- == 1 )
    GASStringNode::ReleaseNode();
  _controlfp_s(_CurrentState: (unsigned int *)&a7, newctrl: _CurrentState, mask: 0x30000u);
  if ( v10 != nullptr )
  {
    GTimer::GetRawTicks(li: v16, a2: a3, a3: v18);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100C6210
// Name: public: void GFxMovieRoot::ClearStickyVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::ClearStickyVariables(ScaleformRenderer *this)
{
  int v1; // eax
  char *v2; // ecx
  char *v3; // ebx
  unsigned int v4; // edi
  unsigned int v5; // edx
  _DWORD *v6; // eax
  int v7; // eax
  int v8; // esi
  GASValue *v9; // ebx
  unsigned int v11; // eax
  _DWORD *v12; // edx
  char *ihasha; // [esp+Ch] [ebp-Ch]

  v1 = *((_DWORD *)this + 2305);
  v2 = (char *)this + 9220;
  if ( v1 != 0 )
  {
    v5 = *(_DWORD *)(v1 + 4);
    v4 = 0;
    v6 = (_DWORD *)(v1 + 8);
    do
    {
      if ( *v6 != -2 )
        break;
      ++v4;
      v6 += 3;
    }
    while ( v4 <= v5 );
    ihasha = v2;
    v3 = v2;
  }
  else
  {
    v3 = nullptr;
    ihasha = nullptr;
    v4 = 0;
  }
  while ( v3 != nullptr )
  {
    v7 = *(_DWORD *)v3;
    if ( *(_DWORD *)v3 == 0 || (signed int)v4 > *(_DWORD *)(v7 + 4) )
      break;
    v8 = *(_DWORD *)(v7 + 12 * v4 + 16);
    if ( v8 != 0 )
    {
      do
      {
        v9 = (GASValue *)v8;
        v8 = *(_DWORD *)(v8 + 20);
        GASValue::~GASValue(this: v9 + 1);
        if ( (*v9)->m_nGrowSize-- == 1 )
          GASStringNode::ReleaseNode();
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v9);
      }
      while ( v8 != 0 );
      v3 = ihasha;
    }
    v11 = *(_DWORD *)(*(_DWORD *)v3 + 4);
    if ( (int)v4 <= (int)v11 && ++v4 <= v11 )
    {
      v12 = (_DWORD *)(*(_DWORD *)v3 + 12 * v4 + 8);
      do
      {
        if ( *v12 != -2 )
          break;
        ++v4;
        v12 += 3;
      }
      while ( v4 <= v11 );
    }
  }
  GHashSetBase<GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeHashF>>::Clear();
}

//------------------------------------------------------------------------------
// Address: 0x100C62E0
// Name: private: bool GFxMovieRoot::InvokeAlias(char const __near *,struct GFxMovieRoot::InvokeAliasInfo const __near &,class GASValue __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __userpurge GFxMovieRoot::InvokeAlias@<al>(
        int a1@<ecx>,
        float a2@<ebx>,
        IDirect3D9 *this,
        CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **pmethodName,
        int a5,
        unsigned int numArgs)
{
  GRefCountNTSImpl *v7; // edi
  GFxAmpViewStats *v8; // ecx
  float v9; // ecx
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v10; // ecx
  GRefCountNTSImpl *v11; // eax
  unsigned __int8 v12; // bl
  void *lpImageName; // ecx
  float *v16; // [esp+0h] [ebp-34h]
  float *v17; // [esp+4h] [ebp-30h]
  GFxAmpViewStats *v18; // [esp+10h] [ebp-24h]
  _LOAD_DLL_DEBUG_INFO resulta; // [esp+20h] [ebp-14h] BYREF

  v7 = nullptr;
  if ( *(_DWORD *)(a1 + 48) == 0 )
    return 0;
  v8 = *(GFxAmpViewStats **)(a1 + 10308);
  v18 = v8;
  if ( v8 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v8, swdHandle: 1u, a3: 0x13u);
    GTimer::GetRawTicks(li: v9, a2: *(float *)&v16, a3: v17);
  }
  if ( *pmethodName != nullptr )
    (*pmethodName)->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = (CRefCountServiceDestruct<CRefST>_vtbl *)(((int)&(*pmethodName)->dtr_CRefCountServiceDestruct<CRefST> + 1) & 0x8FFFFFFF);
  v10 = pmethodName[1];
  resulta.lpImageName = *pmethodName;
  if ( v10 != nullptr )
  {
    GFxCharacterHandle::ResolveCharacter(this: v10, a2: (GFxMovieRoot *)a1);
    if ( v11 != nullptr )
      ++v11->RefCount;
    v7 = v11;
  }
  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a1 + 48) + 112))(a1: *(_DWORD *)(a1 + 48));
  GASValue::GASValue(this: (GASValue *)&resulta, a2: (const struct GASFunctionRef *)(pmethodName + 2));
  v12 = (unsigned __int8)GAS_Invoke(result: &resulta);
  GASValue::~GASValue(this: (GASValue *)&resulta);
  if ( v7 != nullptr )
    GRefCountNTSImpl::Release(this: v7);
  lpImageName = resulta.lpImageName;
  if ( resulta.lpImageName != nullptr )
    GRefCountBaseGC<323>::Release(a1: resulta.lpImageName);
  if ( v18 != nullptr )
  {
    GTimer::GetRawTicks(li: *(float *)&lpImageName, a2, a3: v16);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x100C6410
// Name: private: bool GFxMovieRoot::InvokeAliasArgs(char const __near *,struct GFxMovieRoot::InvokeAliasInfo const __near &,class GASValue __near *,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __userpurge GFxMovieRoot::InvokeAliasArgs@<al>(
        GFxMovieRoot *this@<ecx>,
        float a2@<ebx>,
        const char *a3,
        CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **a4,
        struct GASValue *method,
        const char *a6,
        char *args)
{
  GRefCountNTSImpl *v8; // esi
  GFxAmpViewStats *v9; // ecx
  float v10; // ecx
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v11; // ecx
  GRefCountNTSImpl *v12; // eax
  unsigned __int8 v13; // bl
  float v14; // ecx
  float *v17; // [esp+0h] [ebp-34h]
  float *v18; // [esp+4h] [ebp-30h]
  GFxAmpViewStats *v19; // [esp+10h] [ebp-24h]
  GASValue v20[4]; // [esp+20h] [ebp-14h] BYREF
  float v21; // [esp+30h] [ebp-4h]

  v8 = nullptr;
  if ( *((_DWORD *)this + 12) == 0 )
    return 0;
  v9 = *((GFxAmpViewStats **)this + 2577);
  v19 = v9;
  if ( v9 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v9, swdHandle: 1u, a3: 0x14u);
    GTimer::GetRawTicks(li: v10, a2: *(float *)&v17, a3: v18);
  }
  if ( *a4 != nullptr )
    (*a4)->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = (CRefCountServiceDestruct<CRefST>_vtbl *)(((int)&(*a4)->dtr_CRefCountServiceDestruct<CRefST> + 1) & 0x8FFFFFFF);
  v11 = a4[1];
  v21 = *(float *)a4;
  if ( v11 != nullptr )
  {
    GFxCharacterHandle::ResolveCharacter(this: v11, a2: this);
    if ( v12 != nullptr )
      ++v12->RefCount;
    v8 = v12;
  }
  (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 12) + 112))(a1: *((_DWORD *)this + 12));
  GASValue::GASValue(this: v20, a2: (const struct GASFunctionRef *)(a4 + 2));
  v13 = (unsigned __int8)GAS_InvokeParsed((unsigned int)method);
  GASValue::~GASValue(this: v20);
  if ( v8 != nullptr )
    GRefCountNTSImpl::Release(this: v8);
  v14 = v21;
  if ( v21 != 0.0 )
    GRefCountBaseGC<323>::Release(a1: LODWORD(v21));
  if ( v19 != nullptr )
  {
    GTimer::GetRawTicks(li: v14, a2, a3: v17);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x100C6530
// Name: public: GFxMovieRoot::InvokeAliasInfo::~InvokeAliasInfo(void)
// Source: json
//------------------------------------------------------------------------------
GPtr<GFxActionControl> *__thiscall GFxMovieRoot::InvokeAliasInfo::~InvokeAliasInfo(GPtr<GFxActionControl> *this)
{
  int v2; // ecx
  GPtr<GFxActionControl> *result; // eax
  bool v4; // zf
  int v5; // ecx
  GFxCharacterHandle *v6; // edi

  if ( (*(_BYTE *)(this + 4) & 2) == 0 )
  {
    v2 = *((_DWORD *)this + 2);
    if ( v2 != 0 )
      result = (GPtr<GFxActionControl> *)GRefCountBaseGC<323>::Release(a1: v2);
  }
  v4 = (*(_BYTE *)(this + 4) & 1) == 0;
  *((_DWORD *)this + 2) = 0;
  if ( v4 )
  {
    v5 = *((_DWORD *)this + 3);
    if ( v5 != 0 )
      result = (GPtr<GFxActionControl> *)GRefCountBaseGC<323>::Release(a1: v5);
  }
  *((_DWORD *)this + 3) = 0;
  v6 = *((GFxCharacterHandle **)this + 1);
  if ( v6 != nullptr )
  {
    *v6 = (GFxCharacterHandle)((char *)*v6 - 1);
    if ( (int)*v6 <= 0 )
    {
      GFxCharacterHandle::~GFxCharacterHandle(this: v6);
      result = (GPtr<GFxActionControl> *)((int (__thiscall *)(GMemoryHeap *, GFxCharacterHandle *))GMemory::pGlobalHeap->Free)(
                                           a1: GMemory::pGlobalHeap,
                                           a2: v6);
    }
  }
  if ( this->pObject != nullptr )
    return (GPtr<GFxActionControl> *)GRefCountBaseGC<323>::Release(a1: this->pObject);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C65A0
// Name: public: void GFxMovieRoot::ResetFocusStates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::ResetFocusStates(ScaleformRenderer *this)
{
  unsigned int v1; // ebx
  ButtonCode_t *v2; // esi
  GFxCharacterHandle *v3; // edi

  v1 = 0;
  if ( *((_DWORD *)this + 2556) != 0 )
  {
    v2 = (ButtonCode_t *)((char *)this + 9416);
    do
    {
      v3 = (GFxCharacterHandle *)*v2;
      if ( *v2 != BUTTON_CODE_NONE )
      {
        *v3 = (GFxCharacterHandle)((char *)*v3 - 1);
        if ( (int)*v3 <= 0 )
        {
          GFxCharacterHandle::~GFxCharacterHandle(this: v3);
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
        }
      }
      *v2 = BUTTON_CODE_NONE;
      if ( (*(_BYTE *)(v2 - 6) & 1) != 0 )
      {
        GArrayDataBase<GPtr<GFxASCharacter>,GAllocatorDH<GPtr<GFxASCharacter>,326>,GArrayDefaultPolicy>::ResizeNoConstruct(
          this: (GStatBag::Iterator *)(v2 - 5),
          pheapAddr: *(v2 - 2),
          newSize: 0);
        *((_BYTE *)v2 - 24) = 0;
      }
      *((_WORD *)v2 + 2) = 0;
      ++v1;
      v2 += 13;
    }
    while ( v1 < *((_DWORD *)this + 2556) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6620
// Name: protected: void GFxMovieRoot::FillTabableArray(struct GFxMovieRoot::ProcessFocusKeyInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::FillTabableArray(ISteamRemoteStorage *this, const char *pfocusInfo)
{
  int v2; // edi
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v4; // ecx
  GRefCountNTSImpl *v5; // eax
  GRefCountNTSImpl *v6; // esi
  int i; // esi
  int v8; // ecx
  void (__thiscall *p)(IMesh *, int, int); // [esp+Ch] [ebp-10h] BYREF
  char v10; // [esp+10h] [ebp-Ch]
  char v11; // [esp+11h] [ebp-Bh]
  char v12; // [esp+12h] [ebp-Ah]

  v2 = *(_DWORD *)pfocusInfo;
  if ( pfocusInfo[32] != 0 && (*(_BYTE *)v2 & 1) != 0 && (*(_BYTE *)v2 & 2) == 0 )
  {
    GArrayDataBase<GPtr<GFxASCharacter>,GAllocatorDH<GPtr<GFxASCharacter>,326>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: (GStatBag::Iterator *)(v2 + 4),
      pheapAddr: *(ButtonCode_t *)(v2 + 16),
      newSize: 0);
    *(_BYTE *)v2 = 0;
  }
  if ( (*(_BYTE *)v2 & 1) == 0 )
  {
    v11 = pfocusInfo[32];
    v4 = *(CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(v2 + 24);
    v10 = 0;
    v12 = 0;
    p = (void (__thiscall *)(IMesh *, int, int))(v2 + 4);
    if ( v4 != nullptr
      && (GFxCharacterHandle::ResolveCharacter(this: v4, a2: (GFxMovieRoot *)this), v6 = v5, v5 != nullptr) )
    {
      ++v5->RefCount;
      GRefCountNTSImpl::Release(this: v5);
      ((void (__thiscall *)(GRefCountNTSImpl *, void (__thiscall **)(IMesh *, int, int)))v6->__vftable[57].dtr_GRefCountImplCore)(
        a1: v6,
        a2: &p);
    }
    else
    {
      for ( i = *((_DWORD *)this + 10); i > 0; --i )
      {
        v8 = *(_DWORD *)(*((_DWORD *)this + 9) + 8 * i - 4);
        (*(void (__thiscall **)(int, void (__thiscall **)(IMesh *, int, int)))(*(_DWORD *)v8 + 228))(a1: v8, a2: &p);
      }
    }
    if ( v10 != 0 )
      G_QuickSortSliced<GArrayDH<GPtr<GFxASCharacter>,326,GArrayDefaultPolicy>,GASTabIndexSortFunctor>(
        a1: (int *)(v2 + 4),
        a2: 0,
        a3: *(_DWORD **)(v2 + 8));
    else
      G_QuickSortSliced<GArrayDH<GPtr<GFxASCharacter>,326,GArrayDefaultPolicy>,GASAutoTabSortFunctor>(
        a1: (_DWORD *)(v2 + 4),
        a2: nullptr,
        a3: *(GRefCountNTSImpl ***)(v2 + 8),
        (unsigned __int8)byte_10359408);
    *(_BYTE *)v2 = 1;
    if ( pfocusInfo[32] != 0 )
      *(_BYTE *)v2 = 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6710
// Name: public: void GFxMovieRoot::InitFocusKeyInfo(struct GFxMovieRoot::ProcessFocusKeyInfo __near *,struct GFxInputEventsQueue::QueueEntry::KeyEntry const __near &,bool,struct GFxMovieRoot::FocusGroupDescr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::InitFocusKeyInfo(
        ISteamRemoteStorage *this,
        GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>::SysAllocContainer *const pfocusInfo,
        const struct GFxInputEventsQueue::QueueEntry::KeyEntry *a3,
        bool inclFocusEnabled,
        struct GFxMovieRoot::FocusGroupDescr *a5)
{
  struct GFxMovieRoot::FocusGroupDescr *v7; // edi
  _DWORD *Height; // eax
  GRefCountNTSImpl *v9; // ebx
  GRefCountNTSImpl *v10; // ecx
  unsigned int v11; // edx
  unsigned int Usage; // ecx
  int v13; // eax
  _DWORD *i; // edi
  unsigned int pfocusInfoa; // [esp+Ch] [ebp+8h]
  unsigned int Width; // [esp+10h] [ebp+Ch]
  _D3DPOOL Pool; // [esp+18h] [ebp+14h]

  if ( *(&pfocusInfo[2].Initialized + 1) )
    return;
  v7 = a5;
  if ( a5 == nullptr )
    v7 = (struct GFxMovieRoot::FocusGroupDescr *)(this
                                                + 13 * *((unsigned __int8 *)this + *((unsigned __int8 *)a3 + 8) + 10228)
                                                + 2348);
  pfocusInfo->Data[0] = (unsigned int)v7;
  LOWORD(pfocusInfo[2].Data[1]) = v7[1].Format;
  pfocusInfoa = v7[1].Usage;
  Pool = v7[1].Pool;
  Width = v7[1].Width;
  pfocusInfo[1].Data[0] = v7[1].Type;
  pfocusInfo[1].Data[1] = pfocusInfoa;
  *(float *)&pfocusInfo[1].Initialized = *(float *)&Pool;
  pfocusInfo[2].Data[0] = Width;
  pfocusInfo[2].Initialized = inclFocusEnabled;
  HIBYTE(pfocusInfo[2].Data[1]) = 0;
  BYTE2(pfocusInfo[2].Data[1]) = *((_BYTE *)a3 + 8);
  GFxMovieRoot::FillTabableArray(this, (const char *)pfocusInfo);
  *(_DWORD *)&pfocusInfo->Initialized = -1;
  Height = (_DWORD *)v7->Height;
  v9 = nullptr;
  if ( Height == nullptr )
    goto LABEL_8;
  if ( Height[1] == 0 )
  {
    if ( (*Height)-- == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: Height);
    v7->Height = 0;
    goto LABEL_8;
  }
  v9 = (GRefCountNTSImpl *)Height[1];
  if ( v9 != nullptr )
  {
    ++v9->RefCount;
LABEL_8:
    if ( v9 != nullptr )
      ++v9->RefCount;
  }
  v10 = (GRefCountNTSImpl *)pfocusInfo->Data[1];
  if ( v10 != nullptr )
    GRefCountNTSImpl::Release(this: v10);
  pfocusInfo->Data[1] = (unsigned int)v9;
  if ( v9 != nullptr )
    GRefCountNTSImpl::Release(this: v9);
  v11 = pfocusInfo->Data[1];
  if ( v11 != 0 )
  {
    Usage = v7->Usage;
    v13 = 0;
    if ( Usage != 0 )
    {
      for ( i = (_DWORD *)v7->Type; *i != v11; ++i )
      {
        if ( ++v13 >= Usage )
        {
          *(&pfocusInfo[2].Initialized + 1) = true;
          return;
        }
      }
      *(_DWORD *)&pfocusInfo->Initialized = v13;
    }
  }
  *(&pfocusInfo[2].Initialized + 1) = true;
}

//------------------------------------------------------------------------------
// Address: 0x100C6820
// Name: public: void GFxMovieRoot::ProcessFocusKey(enum GFxEvent::EventType,struct GFxInputEventsQueue::QueueEntry::KeyEntry const __near &,struct GFxMovieRoot::ProcessFocusKeyInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::ProcessFocusKey(
        ISteamRemoteStorage *a1@<ecx>,
        const CMaterialDict::MissingMaterial_t *a2@<edi>,
        ISteamRemoteStorage *result,
        struct GFxInputEventsQueue::QueueEntry::KeyEntry *a4,
        GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>::SysAllocContainer *pfocusInfo)
{
  __int16 v5; // ax
  bool v6; // zf
  unsigned int v7; // edi
  int v8; // eax
  int v9; // esi
  int v10; // ecx
  int v11; // ecx
  unsigned int v12; // ecx
  GFxCharacter *v13; // esi
  int v14; // eax
  struct GFxInputEventsQueue::QueueEntry::KeyEntry *v15; // ecx
  __int16 v16; // ax
  __int16 v17; // ax
  int v18; // edi
  double v19; // st7
  int v20; // edx
  GFxCharacter **v21; // ecx
  GFxCharacter *v22; // esi
  int v23; // eax
  double v24; // st7
  double v25; // st6
  __int16 v26; // cx
  double v27; // st5
  double v28; // st5
  double v29; // st4
  double v30; // st3
  double v31; // st1
  double v32; // st0
  double v33; // st5
  double v34; // st4
  double v35; // st7
  double v36; // st6
  double v37; // st4
  double v38; // st4
  double v39; // rt0
  double v40; // st1
  double v41; // rt1
  double v42; // st1
  double v43; // rt2
  double v44; // st1
  double v45; // rt0
  double v46; // st1
  double v47; // st2
  double v48; // rt0
  double v49; // st4
  double v50; // st6
  double v51; // rt1
  double v52; // st4
  double v53; // st6
  double v54; // st3
  double v55; // st3
  double v56; // st7
  double v57; // st6
  double v58; // rt1
  double v59; // st2
  double v60; // st4
  double v61; // st3
  double v62; // st4
  double v63; // rt2
  double v64; // st4
  double v65; // st6
  double v66; // rtt
  double v67; // st4
  double v68; // st5
  double v69; // st3
  double v70; // st3
  double v71; // st5
  double v72; // st6
  bool v73; // c0
  double v74; // st7
  double v75; // st7
  int v76; // edi
  int v77; // edx
  int v78; // ecx
  int v79; // edx
  int v80; // eax
  GFxCharacter **v81; // ecx
  GFxCharacter *v82; // esi
  int v83; // eax
  double v84; // st7
  __int16 v85; // cx
  double v86; // st6
  double v87; // st5
  double v88; // st3
  double v89; // st1
  double v90; // st7
  double v91; // st2
  double v92; // st6
  double v93; // st4
  double v94; // st3
  double v95; // rtt
  double v96; // st1
  double v97; // rtt
  double v98; // st2
  double v99; // st4
  double v100; // rt2
  double v101; // st3
  double v102; // st7
  double v103; // st1
  double v104; // st1
  double v105; // st7
  double v106; // st6
  double v107; // rt1
  double v108; // st1
  double v109; // st4
  double v110; // rt0
  double v111; // st2
  double v112; // st6
  double v113; // st2
  double v114; // st6
  double v115; // rtt
  double v116; // st2
  double v117; // st7
  double v118; // st1
  double v119; // st1
  double v120; // st5
  double v121; // st6
  bool v122; // c0
  double v123; // st7
  double v124; // st7
  int v125; // eax
  int v126; // esi
  GRefCountNTSImpl *v127; // ecx
  GRefCountNTSImpl *v128; // ecx
  const CMaterialDict::MissingMaterial_t *v130; // [esp+18h] [ebp-1ACh]
  char v131[16]; // [esp+24h] [ebp-1A0h] BYREF
  char v132[16]; // [esp+34h] [ebp-190h] BYREF
  char v133[24]; // [esp+44h] [ebp-180h] BYREF
  float v134; // [esp+5Ch] [ebp-168h]
  float v135; // [esp+60h] [ebp-164h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> newrect; // [esp+64h] [ebp-160h]
  float v137; // [esp+70h] [ebp-154h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> brect; // [esp+74h] [ebp-150h]
  float v139; // [esp+88h] [ebp-13Ch]
  float v140; // [esp+8Ch] [ebp-138h]
  int v141; // [esp+9Ch] [ebp-128h]
  float v142; // [esp+A0h] [ebp-124h]
  float v143; // [esp+A4h] [ebp-120h]
  float v144; // [esp+A8h] [ebp-11Ch]
  float v145; // [esp+ACh] [ebp-118h]
  float v146; // [esp+B0h] [ebp-114h]
  float v147; // [esp+B4h] [ebp-110h]
  float v148; // [esp+B8h] [ebp-10Ch]
  float v149; // [esp+BCh] [ebp-108h]
  float v150; // [esp+C0h] [ebp-104h]
  float v151; // [esp+C4h] [ebp-100h]
  float v152; // [esp+C8h] [ebp-FCh]
  float v153; // [esp+CCh] [ebp-F8h]
  float v154; // [esp+D0h] [ebp-F4h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> bRect; // [esp+D4h] [ebp-F0h] BYREF
  float v156; // [esp+E0h] [ebp-E4h]
  float v157; // [esp+E4h] [ebp-E0h] BYREF
  int v158; // [esp+E8h] [ebp-DCh]
  int v159; // [esp+ECh] [ebp-D8h]
  float v160; // [esp+F0h] [ebp-D4h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> intersectionRect; // [esp+F4h] [ebp-D0h]
  float v162; // [esp+100h] [ebp-C4h]
  float v163; // [esp+104h] [ebp-C0h]
  int m_nAllocationCount; // [esp+108h] [ebp-BCh]
  int m_nGrowSize; // [esp+10Ch] [ebp-B8h]
  float v166; // [esp+110h] [ebp-B4h]
  unsigned int v167; // [esp+114h] [ebp-B0h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> stripeRect; // [esp+118h] [ebp-ACh]
  float v169; // [esp+124h] [ebp-A0h]
  ISteamRemoteStorage *v170; // [esp+128h] [ebp-9Ch]
  int v171; // [esp+12Ch] [ebp-98h]
  int v172; // [esp+130h] [ebp-94h]
  int v173; // [esp+134h] [ebp-90h]
  int v174; // [esp+138h] [ebp-8Ch]
  int tabableArraySize; // [esp+13Ch] [ebp-88h]
  struct GFxInputEventsQueue::QueueEntry::KeyEntry *v176; // [esp+140h] [ebp-84h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> newFocusRect; // [esp+144h] [ebp-80h]
  float v178; // [esp+150h] [ebp-74h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> aRect; // [esp+154h] [ebp-70h] BYREF
  float v180; // [esp+160h] [ebp-64h]
  int v181; // [esp+164h] [ebp-60h]
  int cnt; // [esp+168h] [ebp-5Ch]
  bool hitStipe; // [esp+16Fh] [ebp-55h]
  int i; // [esp+170h] [ebp-54h]
  float v185; // [esp+174h] [ebp-50h]
  struct GMatrix2D v186; // [esp+178h] [ebp-4Ch] BYREF
  struct GMatrix2D v187; // [esp+190h] [ebp-34h] BYREF
  struct GMatrix2D v188; // [esp+1A8h] [ebp-1Ch] BYREF

  v170 = a1;
  v176 = a4;
  if ( result != (ISteamRemoteStorage *)5 )
    return;
  v5 = *((_WORD *)a4 + 2);
  if ( v5 != 9
    && (LOBYTE(a1[13 * *((unsigned __int8 *)&a1[2557].__vftable + *((unsigned __int8 *)a4 + 8)) + 2360].__vftable) == 0
     && HIBYTE(pfocusInfo[2].Data[1]) == 0
     || v5 != 37 && v5 != 39 && v5 != 38 && v5 != 40) )
  {
    return;
  }
  GFxMovieRoot::InitFocusKeyInfo(this: a1, pfocusInfo, a3: a4, inclFocusEnabled: false, a5: nullptr);
  v6 = *((_WORD *)a4 + 2) == 9;
  v7 = pfocusInfo->Data[0];
  v8 = *(_DWORD *)(pfocusInfo->Data[0] + 8);
  v167 = pfocusInfo->Data[0];
  tabableArraySize = v8;
  if ( !v6 )
  {
    v12 = pfocusInfo->Data[1];
    if ( v12 == 0
      || (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)v12 + 216))(a1: v12) == 0
      && (HIBYTE(v170[2333].__vftable) & 3) != 1 )
    {
      goto LABEL_227;
    }
    v13 = (GFxCharacter *)pfocusInfo->Data[1];
    GMatrix2D::SetIdentity(result: a2);
    GFxCharacter::GetLevelMatrix(this: v13, pmat: (CMaterialDict *)&v186);
    v14 = (*(int (__thiscall **)(unsigned int, char *))(*(_DWORD *)pfocusInfo->Data[1] + 244))(
            a1: pfocusInfo->Data[1],
            a2: v131);
    *(float *)&aRect.m_pMemory = 0.0;
    *(float *)&aRect.m_nAllocationCount = 0.0;
    *(float *)&aRect.m_nGrowSize = 0.0;
    v180 = 0.0;
    GMatrix2D::EncloseTransform(a1: &aRect, a2: v14);
    v15 = v176;
    v16 = *((_WORD *)v176 + 2);
    if ( LOWORD(pfocusInfo[2].Data[1]) == v16 )
    {
      if ( v16 == 38 || v16 == 40 )
      {
        aRect.m_pMemory = (CMatRenderContextBase::MatrixStackItem_t *)pfocusInfo[1].Data[0];
        aRect.m_nGrowSize = *(int *)&pfocusInfo[1].Initialized;
      }
      else if ( v16 == 39 || v16 == 37 )
      {
        aRect.m_nAllocationCount = pfocusInfo[1].Data[1];
        v180 = *(float *)pfocusInfo[2].Data;
      }
    }
    else
    {
      pfocusInfo[1] = (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>::SysAllocContainer)aRect;
      *(float *)pfocusInfo[2].Data = v180;
      LOWORD(pfocusInfo[2].Data[1]) = *((_WORD *)v15 + 2);
    }
    v17 = *((_WORD *)v15 + 2);
    if ( v17 != 39 && v17 != 37 )
    {
      if ( v17 != 38 && v17 != 40 )
        goto LABEL_227;
      v170[2333].__vftable = (ISteamRemoteStorage_vtbl *)((int)v170[2333].__vftable | 0x400);
      *(float *)&newFocusRect.m_nGrowSize = 0.0;
      v18 = *(_DWORD *)&pfocusInfo->Initialized;
      v178 = 0.0;
      v19 = 2147483600.0;
      v6 = *((_WORD *)v15 + 2) == 40;
      *(float *)&newFocusRect.m_pMemory = 2147483600.0;
      if ( !v6 )
        v19 = -2147483600.0;
      *(float *)&newFocusRect.m_nAllocationCount = v19;
      hitStipe = false;
      v185 = 0.0;
      if ( tabableArraySize - 1 <= 0 )
        goto LABEL_227;
      v20 = tabableArraySize;
      while ( 1 )
      {
        if ( *((_WORD *)v176 + 2) == 40 )
          ++v18;
        else
          --v18;
        if ( v18 < v20 )
        {
          if ( v18 < 0 )
            v18 = v20 - 1;
        }
        else
        {
          v18 = 0;
        }
        v21 = (GFxCharacter **)(*(_DWORD *)(v167 + 4) + 4 * v18);
        if ( *v21 != nullptr )
          ++*((_DWORD *)*v21 + 1);
        v22 = *v21;
        if ( !pfocusInfo[2].Initialized
          && (*(unsigned __int8 (__thiscall **)(GFxCharacter *))(*(_DWORD *)v22 + 212))(a1: *v21) == 0
          || (*(unsigned __int8 (__thiscall **)(GFxCharacter *, ISteamRemoteStorage *, _DWORD))(*(_DWORD *)v22 + 196))(
               a1: v22,
               a2: v170,
               a3: BYTE2(pfocusInfo[2].Data[1])) == 0 )
        {
          goto LABEL_134;
        }
        GMatrix2D::SetIdentity(result: v130);
        GFxCharacter::GetLevelMatrix(this: v22, pmat: (CMaterialDict *)&v187);
        v23 = (*(int (__thiscall **)(GFxCharacter *, char *))(*(_DWORD *)v22 + 244))(a1: v22, a2: v133);
        v157 = 0.0;
        *(float *)&v158 = 0.0;
        *(float *)&v159 = 0.0;
        v160 = 0.0;
        GMatrix2D::EncloseTransform(a1: &v157, a2: v23);
        v24 = *(float *)&aRect.m_nAllocationCount;
        v25 = v180;
        v26 = *((_WORD *)v176 + 2);
        if ( v26 == 40 )
        {
          *(float *)&stripeRect.m_nAllocationCount = v25 + 1.0;
          v27 = 3.4028235e38;
        }
        else
        {
          v135 = v24 - 1.0;
          *(float *)&stripeRect.m_nAllocationCount = 1.1754944e-38;
          v27 = v135;
        }
        v169 = v27;
        v28 = v160;
        v29 = *(float *)&stripeRect.m_nAllocationCount;
        v30 = *(float *)&aRect.m_pMemory;
        v31 = *(float *)&v158;
        v32 = v157;
        if ( *(float *)&stripeRect.m_nAllocationCount > (double)v160 )
        {
          v38 = v157;
LABEL_84:
          v39 = v31;
          v40 = v38;
          v37 = v39;
          v41 = v40;
          v42 = v24;
          v35 = v41;
          v43 = v42;
          v44 = v25;
          v36 = *(float *)&v159;
          v45 = v44;
          v46 = v43;
          v47 = v45;
LABEL_85:
          if ( hitStipe )
            goto LABEL_134;
          goto LABEL_90;
        }
        if ( v169 < (double)*(float *)&v158 || *(float *)&aRect.m_nGrowSize < v32 || *(float *)&v159 < v30 )
        {
          v24 = *(float *)&aRect.m_nAllocationCount;
          v31 = *(float *)&v158;
          v25 = v180;
          v38 = v157;
          goto LABEL_84;
        }
        v163 = v157;
        m_nAllocationCount = v158;
        m_nGrowSize = v159;
        v33 = *(float *)&v159;
        v166 = v160;
        if ( v160 < v29 || v169 < (double)*(float *)&v158 || *(float *)&aRect.m_nGrowSize < v32 )
          break;
        v28 = v160;
        if ( *(float *)&v159 < v30 )
        {
          v33 = *(float *)&v159;
          v30 = *(float *)&aRect.m_pMemory;
          v34 = v160;
LABEL_68:
          v163 = 0.0;
          *(float *)&m_nAllocationCount = 0.0;
          *(float *)&cnt = 0.0 + 0.0;
          m_nGrowSize = cnt;
          v166 = *(float *)&cnt;
          v35 = v157;
          v36 = v33;
          v28 = v34;
          v37 = *(float *)&v158;
          goto LABEL_69;
        }
        v36 = *(float *)&v159;
        if ( v32 <= v30 )
          v163 = *(float *)&aRect.m_pMemory;
        if ( *(float *)&aRect.m_nGrowSize < (double)*(float *)&v159 )
          m_nGrowSize = aRect.m_nGrowSize;
        v35 = v157;
        if ( *(float *)&v158 > v29 )
        {
          v37 = *(float *)&v158;
        }
        else
        {
          v37 = *(float *)&v158;
          m_nAllocationCount = stripeRect.m_nAllocationCount;
        }
        if ( v169 < v28 )
          v166 = v169;
LABEL_69:
        *(float *)&i = *(float *)&m_nGrowSize - v163;
        if ( *(float *)&i < 40.0 )
        {
          v47 = v180;
          v46 = *(float *)&aRect.m_nAllocationCount;
          goto LABEL_85;
        }
        if ( !hitStipe )
        {
          *(_DWORD *)&pfocusInfo->Initialized = v18;
          hitStipe = true;
          *(float *)&newFocusRect.m_pMemory = v35;
          *(float *)&newFocusRect.m_nAllocationCount = v37;
          *(float *)&newFocusRect.m_nGrowSize = v36;
          v178 = v28;
          goto LABEL_134;
        }
        v47 = v180;
        v46 = *(float *)&aRect.m_nAllocationCount;
LABEL_90:
        if ( v26 == 38 )
        {
          *(float *)&i = *(float *)&aRect.m_nGrowSize - v30;
          v153 = v30 + *(float *)&i * 0.5;
          v142 = v28;
          v137 = v178;
          if ( v28 > v46 )
            v142 = v46;
          if ( v178 > v46 )
            v137 = v46;
          v48 = v37;
          v49 = v36;
          v50 = v48;
          if ( v49 < v35 || v142 < v50 )
            goto LABEL_134;
          v51 = v49;
          v52 = v142 - v50;
          v53 = v51;
          *(float *)&i = v52;
          *(float *)&i = *(float *)&i / 20.0;
          v54 = *(float *)&i;
          v55 = *(float *)&i <= 0.0 ? v54 - 0.5 : v54 + 0.5;
          if ( (int)v55 <= 3 )
            goto LABEL_134;
          *(float *)&i = v53 - v35;
          v145 = v35 + *(float *)&i * 0.5;
          *(float *)&i = *(float *)&newFocusRect.m_nGrowSize - *(float *)&newFocusRect.m_pMemory;
          v147 = 0.5 * *(float *)&i + *(float *)&newFocusRect.m_pMemory;
          *(float *)&i = v145 - v153;
          *(float *)&i = *(float *)&i / 20.0;
          *(float *)&i = floor(X: *(float *)&i);
          v171 = i;
          *(float *)&i = v142 - *(float *)&aRect.m_nAllocationCount;
          *(float *)&i = *(float *)&i / 20.0;
          *(float *)&i = floor(X: *(float *)&i);
          v172 = i;
          *(float *)&i = v147 - v153;
          *(float *)&i = *(float *)&i / 20.0;
          *(float *)&i = floor(X: *(float *)&i);
          v173 = i;
          *(float *)&i = v137 - *(float *)&aRect.m_nAllocationCount;
          *(float *)&i = *(float *)&i / 20.0;
          *(float *)&i = floor(X: *(float *)&i);
          v174 = i;
          v56 = 0.0;
          v57 = *(float *)&v172;
          if ( *(float *)&v172 > 0.0 )
            goto LABEL_134;
        }
        else
        {
          *(float *)&i = *(float *)&aRect.m_nGrowSize - v30;
          v151 = v30 + *(float *)&i * 0.5;
          v58 = v47;
          v59 = v37;
          v60 = v58;
          v139 = v59;
          brect.m_nAllocationCount = newFocusRect.m_nAllocationCount;
          if ( v59 < v58 )
            v139 = v60;
          if ( *(float *)&newFocusRect.m_nAllocationCount >= v60 )
          {
            v62 = 0.5;
          }
          else
          {
            v61 = v60;
            v62 = 0.5;
            *(float *)&brect.m_nAllocationCount = v61;
          }
          v63 = v62;
          v64 = v36;
          v65 = v63;
          if ( v64 < v35 || v139 > v28 )
            goto LABEL_134;
          v66 = v64;
          v67 = v28 - v139;
          v68 = v66;
          *(float *)&i = v67;
          *(float *)&i = *(float *)&i / 20.0;
          v69 = *(float *)&i;
          v70 = *(float *)&i <= 0.0 ? v69 - v65 : v69 + v65;
          if ( (int)v70 <= 3 )
            goto LABEL_134;
          *(float *)&i = v68 - v35;
          v143 = v35 + *(float *)&i * v65;
          *(float *)&i = *(float *)&newFocusRect.m_nGrowSize - *(float *)&newFocusRect.m_pMemory;
          v149 = v65 * *(float *)&i + *(float *)&newFocusRect.m_pMemory;
          *(float *)&i = v143 - v151;
          *(float *)&i = *(float *)&i / 20.0;
          *(float *)&i = floor(X: *(float *)&i);
          v171 = i;
          *(float *)&i = v139 - v180;
          *(float *)&i = *(float *)&i / 20.0;
          *(float *)&i = floor(X: *(float *)&i);
          v172 = i;
          *(float *)&i = v149 - v151;
          *(float *)&i = *(float *)&i / 20.0;
          *(float *)&i = floor(X: *(float *)&i);
          v173 = i;
          *(float *)&i = *(float *)&brect.m_nAllocationCount - v180;
          *(float *)&i = *(float *)&i / 20.0;
          *(float *)&i = floor(X: *(float *)&i);
          v174 = i;
          v56 = 0.0;
          v57 = *(float *)&v172;
          if ( *(float *)&v172 < 0.0 )
            goto LABEL_134;
        }
        if ( hitStipe )
        {
          if ( v57 < v56 )
            *(float *)&cnt = -v57;
          else
            *(float *)&cnt = v57;
          v71 = *(float *)&v174;
          if ( *(float *)&v174 < v56 )
            *(float *)&v181 = -v71;
          else
            v181 = v174;
          if ( *(float *)&v181 <= (double)*(float *)&cnt )
          {
            if ( v71 != v57 )
              goto LABEL_134;
            v72 = *(float *)&v171;
            if ( *(float *)&v171 < v56 )
              v72 = -v72;
            *(float *)&v181 = v72;
            v73 = *(float *)&v173 < v56;
            v74 = *(float *)&v173;
            if ( v73 )
              v74 = -v74;
            *(float *)&cnt = v74;
            if ( *(float *)&cnt <= (double)*(float *)&v181 )
              goto LABEL_134;
          }
LABEL_133:
          v75 = v157;
          *(_DWORD *)&pfocusInfo->Initialized = v18;
          *(float *)&newFocusRect.m_pMemory = v75;
          newFocusRect.m_nAllocationCount = v158;
          newFocusRect.m_nGrowSize = v159;
          v178 = v160;
          goto LABEL_134;
        }
        if ( *(float *)&v173 * *(float *)&v173 + *(float *)&v174 * *(float *)&v174 > v57 * v57
                                                                                   + *(float *)&v171 * *(float *)&v171 )
          goto LABEL_133;
LABEL_134:
        GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v22);
        v20 = tabableArraySize;
        ++LODWORD(v185);
        if ( SLODWORD(v185) >= tabableArraySize - 1 )
          goto LABEL_227;
      }
      v34 = v160;
      goto LABEL_68;
    }
    v170[2333].__vftable = (ISteamRemoteStorage_vtbl *)((int)v170[2333].__vftable | 0x400);
    v76 = *(_DWORD *)&pfocusInfo->Initialized;
    if ( *((_WORD *)v15 + 2) == 39 )
      *(float *)&newFocusRect.m_nGrowSize = 2147483600.0;
    else
      *(float *)&newFocusRect.m_nGrowSize = -2147483600.0;
    v77 = tabableArraySize;
    newFocusRect.m_pMemory = (CMatRenderContextBase::MatrixStackItem_t *)newFocusRect.m_nGrowSize;
    v78 = tabableArraySize - 1;
    hitStipe = false;
    v178 = 2147483600.0;
    *(float *)&i = 0.0;
    *(float *)&newFocusRect.m_nAllocationCount = 2147483600.0;
    if ( tabableArraySize - 1 <= 0 )
      goto LABEL_227;
    while ( 1 )
    {
      if ( *((_WORD *)v176 + 2) == 39 )
        ++v76;
      else
        --v76;
      if ( v76 < v77 )
      {
        if ( v76 < 0 )
          v76 = v78;
      }
      else
      {
        v76 = 0;
      }
      v79 = *(_DWORD *)(v167 + 4);
      v80 = *(_DWORD *)(v79 + 4 * v76);
      if ( v80 != 0 )
        ++*(_DWORD *)(v80 + 4);
      v81 = (GFxCharacter **)(v79 + 4 * v76);
      v82 = *v81;
      if ( !pfocusInfo[2].Initialized
        && (*(unsigned __int8 (__thiscall **)(GFxCharacter *))(*(_DWORD *)v82 + 212))(a1: *v81) == 0
        || (*(unsigned __int8 (__thiscall **)(GFxCharacter *, ISteamRemoteStorage *, _DWORD))(*(_DWORD *)v82 + 196))(
             a1: v82,
             a2: v170,
             a3: BYTE2(pfocusInfo[2].Data[1])) == 0 )
      {
        goto LABEL_226;
      }
      GMatrix2D::SetIdentity(result: v130);
      GFxCharacter::GetLevelMatrix(this: v82, pmat: (CMaterialDict *)&v188);
      v83 = (*(int (__thiscall **)(GFxCharacter *, char *))(*(_DWORD *)v82 + 244))(a1: v82, a2: v132);
      *(float *)&bRect.m_pMemory = 0.0;
      *(float *)&bRect.m_nAllocationCount = 0.0;
      *(float *)&bRect.m_nGrowSize = 0.0;
      v156 = 0.0;
      GMatrix2D::EncloseTransform(a1: &bRect, a2: v83);
      v84 = *(float *)&aRect.m_pMemory;
      v85 = *((_WORD *)v176 + 2);
      if ( v85 == 39 )
      {
        *(float *)&stripeRect.m_pMemory = *(float *)&aRect.m_nGrowSize + 1.0;
        v86 = 3.4028235e38;
      }
      else
      {
        v134 = v84 - 1.0;
        *(float *)&stripeRect.m_pMemory = 1.1754944e-38;
        v86 = v134;
      }
      *(float *)&stripeRect.m_nGrowSize = v86;
      v87 = *(float *)&aRect.m_nAllocationCount;
      v88 = v180;
      v89 = *(float *)&bRect.m_pMemory;
      if ( *(float *)&aRect.m_nAllocationCount > (double)v156 )
        goto LABEL_177;
      v90 = *(float *)&bRect.m_pMemory;
      if ( *(float *)&bRect.m_nAllocationCount > v88
        || *(float *)&stripeRect.m_nGrowSize < v90
        || *(float *)&stripeRect.m_pMemory > (double)*(float *)&bRect.m_nGrowSize )
      {
        v89 = *(float *)&bRect.m_pMemory;
        v84 = *(float *)&aRect.m_pMemory;
LABEL_177:
        v95 = v89;
        v96 = v84;
        v90 = v95;
        v92 = *(float *)&bRect.m_nGrowSize;
        v93 = v180;
        v94 = *(float *)&bRect.m_nAllocationCount;
        v91 = v156;
LABEL_178:
        if ( hitStipe )
          goto LABEL_226;
        goto LABEL_182;
      }
      intersectionRect.m_pMemory = bRect.m_pMemory;
      intersectionRect.m_nAllocationCount = bRect.m_nAllocationCount;
      intersectionRect.m_nGrowSize = bRect.m_nGrowSize;
      v91 = v156;
      v92 = *(float *)&bRect.m_nGrowSize;
      v162 = v156;
      if ( v156 < v87 )
        goto LABEL_164;
      if ( v180 < (double)*(float *)&bRect.m_nAllocationCount
        || *(float *)&stripeRect.m_nGrowSize < v90
        || *(float *)&stripeRect.m_pMemory > v92 )
      {
        break;
      }
      if ( *(float *)&stripeRect.m_pMemory >= v90 )
        intersectionRect.m_pMemory = stripeRect.m_pMemory;
      if ( *(float *)&stripeRect.m_nGrowSize < v92 )
        intersectionRect.m_nGrowSize = stripeRect.m_nGrowSize;
      v93 = v180;
      if ( *(float *)&bRect.m_nAllocationCount <= v87 )
        intersectionRect.m_nAllocationCount = aRect.m_nAllocationCount;
      v91 = v156;
      v94 = *(float *)&bRect.m_nAllocationCount;
      if ( v156 > v93 )
        v162 = v180;
LABEL_165:
      v185 = v162 - *(float *)&intersectionRect.m_nAllocationCount;
      if ( v185 < 40.0 )
      {
        v96 = *(float *)&aRect.m_pMemory;
        goto LABEL_178;
      }
      if ( !hitStipe )
      {
        *(_DWORD *)&pfocusInfo->Initialized = v76;
        hitStipe = true;
        *(float *)&newFocusRect.m_pMemory = v90;
        *(float *)&newFocusRect.m_nAllocationCount = v94;
        *(float *)&newFocusRect.m_nGrowSize = v92;
        v178 = v91;
        goto LABEL_226;
      }
      v96 = *(float *)&aRect.m_pMemory;
LABEL_182:
      if ( v85 == 39 )
      {
        v97 = v91;
        v98 = v93 - v87;
        v99 = v97;
        v185 = v98;
        v152 = v87 + v185 * 0.5;
        v100 = v94;
        v101 = v90;
        v102 = v100;
        *(float *)&brect.m_pMemory = v101;
        newrect.m_pMemory = newFocusRect.m_pMemory;
        if ( *(float *)&aRect.m_nGrowSize > v101 )
          brect.m_pMemory = (CMatRenderContextBase::MatrixStackItem_t *)aRect.m_nGrowSize;
        if ( *(float *)&newFocusRect.m_pMemory < (double)*(float *)&aRect.m_nGrowSize )
          newrect.m_pMemory = (CMatRenderContextBase::MatrixStackItem_t *)aRect.m_nGrowSize;
        if ( *(float *)&brect.m_pMemory > v92 || v99 < v102 )
          goto LABEL_226;
        v185 = v92 - *(float *)&brect.m_pMemory;
        v185 = v185 / 20.0;
        v103 = v185;
        v104 = v185 <= 0.0 ? v103 - 0.5 : v103 + 0.5;
        if ( (int)v104 <= 3 )
          goto LABEL_226;
        v185 = v99 - v102;
        v150 = v102 + v185 * 0.5;
        v185 = v178 - *(float *)&newFocusRect.m_nAllocationCount;
        v144 = 0.5 * v185 + *(float *)&newFocusRect.m_nAllocationCount;
        v185 = *(float *)&brect.m_pMemory - *(float *)&aRect.m_nGrowSize;
        v185 = v185 / 20.0;
        v185 = floor(X: v185);
        *(float *)&v173 = v185;
        v185 = v150 - v152;
        v185 = v185 / 20.0;
        v185 = floor(X: v185);
        *(float *)&v174 = v185;
        v185 = *(float *)&newrect.m_pMemory - *(float *)&aRect.m_nGrowSize;
        v185 = v185 / 20.0;
        v185 = floor(X: v185);
        *(float *)&v171 = v185;
        v185 = v144 - v152;
        v185 = v185 / 20.0;
        v185 = floor(X: v185);
        *(float *)&v172 = v185;
        v105 = 0.0;
        v106 = *(float *)&v173;
        if ( *(float *)&v173 < 0.0 )
          goto LABEL_226;
      }
      else
      {
        v107 = v96;
        v108 = v93 - v87;
        v109 = v107;
        v185 = v108;
        v154 = v87 + v185 * 0.5;
        v110 = v91;
        v111 = v92;
        v112 = v110;
        v140 = v111;
        v141 = newFocusRect.m_nGrowSize;
        if ( v111 > v107 )
          v140 = v109;
        if ( *(float *)&newFocusRect.m_nGrowSize > v109 )
          *(float *)&v141 = v109;
        if ( v140 < v90 )
          goto LABEL_226;
        v113 = v112;
        v114 = v140;
        if ( v113 < v94 )
          goto LABEL_226;
        v115 = v113;
        v116 = v114 - v90;
        v117 = v115;
        v185 = v116;
        v185 = v185 / 20.0;
        v118 = v185;
        v119 = v185 <= 0.0 ? v118 - 0.5 : v118 + 0.5;
        if ( (int)v119 <= 3 )
          goto LABEL_226;
        v185 = v117 - v94;
        v148 = v94 + v185 * 0.5;
        v185 = v178 - *(float *)&newFocusRect.m_nAllocationCount;
        v146 = 0.5 * v185 + *(float *)&newFocusRect.m_nAllocationCount;
        v185 = v114 - v109;
        v185 = v185 / 20.0;
        v185 = floor(X: v185);
        *(float *)&v173 = v185;
        v185 = v148 - v154;
        v185 = v185 / 20.0;
        v185 = floor(X: v185);
        *(float *)&v174 = v185;
        v185 = *(float *)&v141 - *(float *)&aRect.m_pMemory;
        v185 = v185 / 20.0;
        v185 = floor(X: v185);
        *(float *)&v171 = v185;
        v185 = v146 - v154;
        v185 = v185 / 20.0;
        v185 = floor(X: v185);
        *(float *)&v172 = v185;
        v105 = 0.0;
        v106 = *(float *)&v173;
        if ( *(float *)&v173 > 0.0 )
          goto LABEL_226;
      }
      if ( hitStipe )
      {
        if ( v106 < v105 )
          v185 = -v106;
        else
          v185 = v106;
        v120 = *(float *)&v171;
        if ( *(float *)&v171 < v105 )
          *(float *)&v181 = -v120;
        else
          v181 = v171;
        if ( *(float *)&v181 <= (double)v185 )
        {
          if ( v120 != v106 )
            goto LABEL_226;
          v121 = *(float *)&v174;
          if ( *(float *)&v174 < v105 )
            v121 = -v121;
          v185 = v121;
          v122 = *(float *)&v172 < v105;
          v123 = *(float *)&v172;
          if ( v122 )
            v123 = -v123;
          *(float *)&v181 = v123;
          if ( *(float *)&v181 <= (double)v185 )
            goto LABEL_226;
        }
LABEL_225:
        v124 = *(float *)&bRect.m_pMemory;
        *(_DWORD *)&pfocusInfo->Initialized = v76;
        *(float *)&newFocusRect.m_pMemory = v124;
        newFocusRect.m_nAllocationCount = bRect.m_nAllocationCount;
        newFocusRect.m_nGrowSize = bRect.m_nGrowSize;
        v178 = v156;
        goto LABEL_226;
      }
      if ( *(float *)&v171 * *(float *)&v171 + *(float *)&v172 * *(float *)&v172 > v106 * v106
                                                                                 + *(float *)&v174 * *(float *)&v174 )
        goto LABEL_225;
LABEL_226:
      GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v82);
      v77 = tabableArraySize;
      v78 = tabableArraySize - 1;
      if ( ++i >= tabableArraySize - 1 )
        goto LABEL_227;
    }
    v91 = v156;
    v88 = v180;
LABEL_164:
    *(float *)&intersectionRect.m_pMemory = 0.0;
    *(float *)&intersectionRect.m_nAllocationCount = 0.0;
    *(float *)&cnt = 0.0 + 0.0;
    intersectionRect.m_nGrowSize = cnt;
    v162 = *(float *)&cnt;
    v93 = v88;
    v94 = *(float *)&bRect.m_nAllocationCount;
    goto LABEL_165;
  }
  v9 = *(_DWORD *)&pfocusInfo->Initialized;
  *(_DWORD *)&pfocusInfo->Initialized = -1;
  *(float *)&cnt = 0.0;
  if ( v8 <= 0 )
    goto LABEL_24;
  while ( 1 )
  {
    if ( (*((_BYTE *)v176 + 7) & 1) != 0 )
    {
      if ( --v9 < 0 )
        v9 = v8 - 1;
    }
    else if ( ++v9 >= v8 )
    {
      v9 = 0;
    }
    v10 = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4 * v9);
    if ( v10 != 0 )
    {
      if ( pfocusInfo[2].Initialized || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v10 + 212))(a1: v10) != 0 )
      {
        v11 = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4 * v9);
        if ( (*(unsigned __int8 (__thiscall **)(int, ISteamRemoteStorage *, _DWORD))(*(_DWORD *)v11 + 196))(
               a1: v11,
               a2: v170,
               a3: BYTE2(pfocusInfo[2].Data[1])) != 0 )
          break;
      }
      v8 = tabableArraySize;
    }
    if ( ++cnt >= v8 )
    {
      v170[2333].__vftable = (ISteamRemoteStorage_vtbl *)((int)v170[2333].__vftable | 0x400);
      goto LABEL_227;
    }
  }
  *(_DWORD *)&pfocusInfo->Initialized = v9;
LABEL_24:
  v170[2333].__vftable = (ISteamRemoteStorage_vtbl *)((int)v170[2333].__vftable | 0x400);
LABEL_227:
  v125 = *(_DWORD *)&pfocusInfo->Initialized;
  if ( v125 < 0 || v125 >= tabableArraySize )
  {
    v128 = (GRefCountNTSImpl *)pfocusInfo->Data[1];
    if ( v128 != nullptr )
      GRefCountNTSImpl::Release(this: v128);
    pfocusInfo->Data[1] = 0;
  }
  else
  {
    v126 = *(_DWORD *)(v167 + 4) + 4 * v125;
    if ( *(_DWORD *)v126 != 0 )
      ++*(_DWORD *)(*(_DWORD *)v126 + 4);
    v127 = (GRefCountNTSImpl *)pfocusInfo->Data[1];
    if ( v127 != nullptr )
      GRefCountNTSImpl::Release(this: v127);
    pfocusInfo->Data[1] = *(_DWORD *)v126;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7B60
// Name: public: void GFxMovieRoot::ActivateFocusCapture(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::ActivateFocusCapture(
        ISteamRemoteStorage *this@<ecx>,
        const CMaterialDict::MissingMaterial_t *a2@<edi>,
        char a3)
{
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>::SysAllocContainer v4; // [esp+4h] [ebp-30h] BYREF
  float v5; // [esp+10h] [ebp-24h]
  float v6; // [esp+14h] [ebp-20h]
  float v7; // [esp+18h] [ebp-1Ch]
  float v8; // [esp+1Ch] [ebp-18h]
  int v9; // [esp+20h] [ebp-14h]
  __int16 v10; // [esp+24h] [ebp-10h]
  _BYTE v11[4]; // [esp+28h] [ebp-Ch] BYREF
  __int16 v12; // [esp+2Ch] [ebp-8h]
  char v13; // [esp+2Fh] [ebp-5h]
  char v14; // [esp+30h] [ebp-4h]

  v5 = 0.0;
  v6 = 0.0;
  v7 = 0.0;
  v8 = 0.0;
  v9 = 0;
  v12 = 9;
  v4.Data[0] = 0;
  v4.Data[1] = 0;
  *(_DWORD *)&v4.Initialized = -1;
  v10 = 0;
  v13 = 0;
  v14 = a3;
  GFxMovieRoot::ProcessFocusKey(
    a1: this,
    a2,
    result: (ISteamRemoteStorage *)5,
    a4: (struct GFxInputEventsQueue::QueueEntry::KeyEntry *)v11,
    pfocusInfo: &v4);
  GFxMovieRoot::FinalizeProcessFocusKey((GFxMovieRoot *)this, a2: nullptr, a3: (GRefCountNTSImpl *)&v4);
  if ( v4.Data[1] != 0 )
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v4.Data[1]);
}

//------------------------------------------------------------------------------
// Address: 0x100C7BE0
// Name: public: void GFxMovieRoot::AddTopmostLevelCharacter(class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::AddTopmostLevelCharacter(_DWORD *this, GRefCountNTSImpl *a2)
{
  GRefCountNTSImpl *v2; // ebx
  void (__thiscall *dtr_GRefCountImplCore)(struct GRefCountNTSImpl *); // edx
  _DWORD *v4; // edi
  unsigned int v5; // esi
  int (__thiscall *v6)(_DWORD *); // edx
  int (__thiscall *v7)(_DWORD *); // edx
  unsigned int v8; // ebx
  int v9; // eax
  GRefCountNTSImpl *v10; // edi
  unsigned int v11; // eax
  char *v12; // eax
  int v13; // edi
  GRefCountNTSImpl *v14; // edi
  GRefCountNTSImpl *v15; // eax
  unsigned int v16; // esi
  void *v17; // edx
  int v18; // eax
  int v19; // ecx
  unsigned int v20; // ebx
  ScaleformUIImpl *v21; // edi
  unsigned int v22; // esi
  int v23; // esi
  bool (__thiscall **v24)(IAppSystem *, void *(__cdecl *)(const char *, int *)); // eax
  GFxSystem *m_pSystem; // eax
  unsigned int v26; // esi
  GRefCountNTSImpl **v27; // eax
  _TAPE_WMI_OPERATIONS *v28; // [esp+0h] [ebp-40h]
  int v29; // [esp+4h] [ebp-3Ch]
  char *v30; // [esp+Ch] [ebp-34h] BYREF
  unsigned int v31; // [esp+10h] [ebp-30h]
  unsigned int v32; // [esp+14h] [ebp-2Ch]
  int v33; // [esp+18h] [ebp-28h]
  char *v34; // [esp+1Ch] [ebp-24h] BYREF
  unsigned int v35; // [esp+20h] [ebp-20h]
  unsigned int v36; // [esp+24h] [ebp-1Ch]
  int v37; // [esp+28h] [ebp-18h]
  unsigned int n; // [esp+2Ch] [ebp-14h]
  GRefCountNTSImpl *v39; // [esp+30h] [ebp-10h]
  int v40; // [esp+34h] [ebp-Ch]
  int j; // [esp+38h] [ebp-8h]
  unsigned int i; // [esp+3Ch] [ebp-4h]

  v2 = a2;
  dtr_GRefCountImplCore = a2[15].__vftable[2].dtr_GRefCountImplCore;
  v4 = this;
  v40 = (int)this;
  if ( ((int (__thiscall *)(GRefCountNTSImpl *))dtr_GRefCountImplCore)(a1: &a2[15]) == 2 )
  {
    v5 = 0;
    if ( (GASObjectInterface::ToSprite(result: v28)[37].Method & 0x80000000) == 0 )
      return;
  }
  else
  {
    v5 = 0;
  }
  i = 0;
  if ( v4[2335] == 0 )
    goto LABEL_45;
  v6 = *(int (__thiscall **)(_DWORD *))(*v4 + 244);
  v30 = nullptr;
  v31 = 0;
  v32 = 0;
  v33 = v6(a1: v4);
  v7 = *(int (__thiscall **)(_DWORD *))(*v4 + 244);
  v8 = 0;
  v34 = nullptr;
  v35 = 0;
  v36 = 0;
  v9 = v7(a1: v4);
  v10 = a2;
  v37 = v9;
  do
  {
    v11 = v5 + 1;
    j = v5 + 1;
    if ( v5 + 1 >= v5 )
    {
      if ( v11 < v32 )
        goto LABEL_13;
      GArrayDataBase<GFxCharacter *,GAllocatorDH<GFxCharacter *,2>,GArrayDefaultPolicy>::Reserve(
        this: (void **)&v30,
        a2: v33,
        a3: v11 + (v11 >> 2));
    }
    else
    {
      if ( v11 >= v32 >> 1 )
        goto LABEL_13;
      GArrayDataBase<GFxCharacter *,GAllocatorDH<GFxCharacter *,2>,GArrayDefaultPolicy>::Reserve(
        this: (void **)&v30,
        a2: v33,
        a3: v5 + 1);
    }
    v11 = j;
LABEL_13:
    v5 = v11;
    v12 = &v30[4 * v11 - 4];
    v31 = v5;
    if ( v12 != nullptr )
      *(_DWORD *)v12 = v10;
    v39 = v10;
    v10 = (GRefCountNTSImpl *)v10[4].__vftable;
  }
  while ( v10 != nullptr );
  v13 = v40;
  n = *(_DWORD *)(v40 + 9340);
  if ( n == 0 )
  {
LABEL_43:
    v17 = v34;
LABEL_44:
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v17);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v30);
    v4 = (_DWORD *)v40;
    v2 = a2;
LABEL_45:
    ++v2->RefCount;
    v20 = v4[2335];
    v21 = (ScaleformUIImpl *)(v4 + 2334);
    v22 = v20 + 1;
    if ( v20 + 1 >= v20 )
    {
      if ( (GFxLoader *)v22 >= v21->m_pLoader )
        GArrayDataBase<GPtr<GFxASCharacter>,GAllocatorLH<GPtr<GFxASCharacter>,326>,GArrayDefaultPolicy>::Reserve(
          this: v21,
          pheapAddr: v21,
          newCapacity: v22 + (v22 >> 2),
          a4: (int)v28,
          a5: v29);
    }
    else
    {
      v40 = (int)v21->__vftable + 4 * v20 - 4;
      if ( v20 != v22 )
      {
        for ( j = -1; j != 0; --j )
        {
          if ( *(_DWORD *)v40 != 0 )
            GRefCountNTSImpl::Release(this: *(GRefCountNTSImpl **)v40);
          v40 -= 4;
        }
      }
      if ( v22 < (unsigned int)v21->m_pLoader >> 1 )
        GArrayDataBase<GPtr<GFxASCharacter>,GAllocatorLH<GPtr<GFxASCharacter>,326>,GArrayDefaultPolicy>::Reserve(
          this: v21,
          pheapAddr: v21,
          newCapacity: v20 + 1,
          a4: (int)v28,
          a5: v29);
    }
    v21->m_pSystem = (GFxSystem *)v22;
    if ( v22 > v20 )
    {
      v23 = 1;
      v24 = &v21->Connect + v20;
      do
      {
        if ( v24 != nullptr )
          *v24 = nullptr;
        ++v24;
        --v23;
      }
      while ( v23 != 0 );
    }
    m_pSystem = v21->m_pSystem;
    v26 = i;
    if ( i < (unsigned int)&m_pSystem[-1] )
      memmove(
        dst: (unsigned __int8 *)&v21->Disconnect + 4 * i,
        src: (unsigned __int8 *)&v21->Connect + 4 * i,
        count: 4 * (_DWORD)&m_pSystem[-i] - 4);
    v27 = (GRefCountNTSImpl **)(&v21->Connect + v26);
    if ( v27 != nullptr )
    {
      ++a2->RefCount;
      *v27 = a2;
    }
    GRefCountNTSImpl::Release(this: a2);
    return;
  }
  while ( *(GRefCountNTSImpl **)(*(_DWORD *)(v13 + 9336) + 4 * i) != a2 )
  {
    if ( v8 != 0 )
    {
      if ( (v36 & 0xFFFFFFFE) != 0 )
      {
        if ( v34 != nullptr )
        {
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v34);
          v34 = nullptr;
        }
        v36 = 0;
      }
    }
    else if ( v36 == 0 )
    {
      GArrayDataBase<GFxCharacter *,GAllocatorDH<GFxCharacter *,2>,GArrayDefaultPolicy>::Reserve(
        this: (void **)&v34,
        a2: v37,
        a3: 0);
    }
    v14 = *(GRefCountNTSImpl **)(*(_DWORD *)(v13 + 9336) + 4 * i);
    v8 = 0;
    v15 = nullptr;
    v35 = 0;
    if ( v14 != nullptr )
    {
      do
      {
        v16 = v8 + 1;
        if ( v8 + 1 >= v8 )
        {
          if ( v16 >= v36 )
            GArrayDataBase<GFxCharacter *,GAllocatorDH<GFxCharacter *,2>,GArrayDefaultPolicy>::Reserve(
              this: (void **)&v34,
              a2: v37,
              a3: v16 + (v16 >> 2));
        }
        else if ( v16 < v36 >> 1 )
        {
          GArrayDataBase<GFxCharacter *,GAllocatorDH<GFxCharacter *,2>,GArrayDefaultPolicy>::Reserve(
            this: (void **)&v34,
            a2: v37,
            a3: v8 + 1);
        }
        v17 = v34;
        ++v8;
        v35 = v16;
        if ( &v34[4 * v16] != (char *)4 )
          *(_DWORD *)&v34[4 * v16 - 4] = v14;
        v15 = v14;
        v14 = (GRefCountNTSImpl *)v14[4].__vftable;
      }
      while ( v14 != nullptr );
    }
    else
    {
      v17 = v34;
    }
    if ( v15 == v39 )
    {
      v18 = j - 1;
      v19 = v8 - 1;
      if ( j - 1 >= 0 )
      {
        while ( v19 >= 0 )
        {
          if ( *(_DWORD *)&v30[4 * v18] != *((_DWORD *)v17 + v19) )
          {
            if ( *(_DWORD *)(*(_DWORD *)&v30[4 * v18] + 20) >= *(_DWORD *)(*((_DWORD *)v17 + v19) + 20) )
              break;
            goto LABEL_43;
          }
          --v18;
          --v19;
          if ( v18 < 0 )
            break;
        }
      }
    }
    else if ( v15[55].RefCount > v39[55].RefCount )
    {
      goto LABEL_43;
    }
    if ( ++i >= n )
      goto LABEL_44;
    v13 = v40;
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v34);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v30);
}

//------------------------------------------------------------------------------
// Address: 0x100C7F30
// Name: public: void GFxMovieRoot::AddToPreDisplayList(class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
GSysAlloc *__thiscall GFxMovieRoot::AddToPreDisplayList(_DWORD *this, GSysAlloc_vtbl *a2)
{
  CVertexBuilder *v2; // edi
  unsigned int v3; // esi
  int m_VertexSize_Position; // edx
  GSysAlloc *result; // eax

  v2 = (CVertexBuilder *)(this + 2330);
  v3 = *(this + 2331) + 1;
  if ( v3 >= *(this + 2331) )
  {
    if ( v3 >= *(this + 2332) )
      GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
        this: v2,
        pheapAddr: (ButtonCode_t)v2,
        newCapacity: v3 + (v3 >> 2));
  }
  else if ( v3 < *(this + 2332) >> 1 )
  {
    GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
      this: v2,
      pheapAddr: (ButtonCode_t)v2,
      newCapacity: *(this + 2331) + 1);
  }
  m_VertexSize_Position = v2->m_VertexSize_Position;
  v2->m_VertexSize_BoneWeight = v3;
  result = (GSysAlloc *)(m_VertexSize_Position + 4 * v3 - 4);
  if ( m_VertexSize_Position + 4 * v3 != 4 )
    result->__vftable = a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C7F80
// Name: public: void GFxSwfEvent::AttachTo(class GFxASCharacter __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxSwfEvent::AttachTo(
        CMemberFuncProxy3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CFuncMemPolicyNone> *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        CMatQueuedIndexBuffer *ch,
        __int128 method)
{
  CMatQueuedIndexBuffer *m_pObject; // eax
  int v6; // ebx
  int v7; // edi
  int (__thiscall *v8)(int, int, GRefCountNTSImpl **); // edx
  int (__thiscall *v9)(int, int, int *); // edx
  GSize<float> *v10; // eax
  GRefCountNTSImpl *v11; // esi
  GSize<float> *v12; // eax
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *methoda; // [esp+0h] [ebp-28h] BYREF
  GSize<float> *v14; // [esp+10h] [ebp-18h] BYREF
  int v15; // [esp+14h] [ebp-14h]
  char v16; // [esp+18h] [ebp-10h]
  int v17; // [esp+1Ch] [ebp-Ch] BYREF
  GRefCountNTSImpl *v18; // [esp+20h] [ebp-8h] BYREF
  struct GFxEventId *i; // [esp+24h] [ebp-4h]

  m_pObject = this->m_pObject;
  i = (struct GFxEventId *)this;
  if ( m_pObject != nullptr && m_pObject->m_pHardwareContext != nullptr && m_pObject->m_pCallQueue->m_pHead != nullptr )
  {
    v6 = ((int (__thiscall *)(CMatQueuedIndexBuffer *, int, int))ch->__vftable[2].IndexCount)(a1: ch, a2, a3);
    v7 = *(_DWORD *)(*(_DWORD *)(v6 + 120) + 656);
    v8 = *(int (__thiscall **)(int, int, GRefCountNTSImpl **))(*(_DWORD *)v7 + 40);
    v18 = (GRefCountNTSImpl *)323;
    if ( v8(a1: v7, a2: 32, a3: &v18) != 0 )
      v18 = (GRefCountNTSImpl *)GASActionBuffer::GASActionBuffer(result: (_NETRESOURCEW *)(v6 + 120));
    else
      v18 = nullptr;
    v9 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v7 + 40);
    v17 = 323;
    v10 = (GSize<float> *)v9(a1: v7, a2: 108, a3: &v17);
    v11 = v18;
    if ( v10 != nullptr )
      v12 = GASAsFunctionObject::GASAsFunctionObject(this: v10, penv: (const GSize<float> *)v6);
    else
      v12 = nullptr;
    v14 = v12;
    v16 = 0;
    v15 = 0;
    GASValue::GASValue(this: &methoda, a2: (const struct GASFunctionRef *)&v14);
    if ( (v16 & 2) == 0 && v14 != nullptr )
      GRefCountBaseGC<323>::Release(a1: v14);
    v14 = nullptr;
    if ( (v16 & 1) == 0 && v15 != 0 )
      GRefCountBaseGC<323>::Release(a1: v15);
    GFxASCharacter::SetClipEventHandlers(this: (GFxASCharacter *)ch, i, method: (tagWNDCLASSW *)&methoda);
    GASValue::~GASValue(this: &methoda);
    if ( v11 != nullptr )
      GRefCountNTSImpl::Release(this: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C80D0
// Name: public: static unsigned int GFxPlaceObject::ComputeDataSize(class GFxStream __near *)
// Source: json
//------------------------------------------------------------------------------
static int __stdcall GFxPlaceObject::ComputeDataSize(IShaderDeviceMgr *a1)
{
  int v1; // edi
  int v2; // eax
  int v3; // ebx
  IShaderDeviceMgr_vtbl *v4; // ecx
  int v5; // ecx
  IShaderDeviceMgr_vtbl *v6; // eax
  unsigned __int16 v7; // dx
  int v8; // ecx
  IShaderDeviceMgr_vtbl *v9; // eax
  unsigned __int16 v10; // dx
  int v11; // edi
  int v12; // eax
  ShaderDisplayMode_t *v14; // [esp+0h] [ebp-6Ch]
  const CMaterialDict::MissingMaterial_t *v15; // [esp+0h] [ebp-6Ch]
  ShaderDisplayMode_t *v16; // [esp+0h] [ebp-6Ch]
  int v17; // [esp+0h] [ebp-6Ch]
  int v18; // [esp+4h] [ebp-68h]
  int v19; // [esp+4h] [ebp-68h]
  int pos; // [esp+Ch] [ebp-60h]
  int v21; // [esp+10h] [ebp-5Ch]
  struct GRenderer::Cxform v22; // [esp+20h] [ebp-4Ch] BYREF
  struct GMatrix2D v23; // [esp+40h] [ebp-2Ch] BYREF
  float v24; // [esp+58h] [ebp-14h]
  int v25; // [esp+5Ch] [ebp-10h]
  int v26; // [esp+60h] [ebp-Ch]
  int v27; // [esp+64h] [ebp-8h]

  v1 = (int)a1[13].__vftable + (char *)a1[11].__vftable - (char *)a1[12].__vftable;
  pos = v1;
  GFxStream::GetTagEndPosition(this: a1, a2: v14, a3: v18);
  v3 = v2 - v1;
  v21 = v2 - v1;
  if ( !GFxStream::IsVerboseParse(this: (GFxStream *)a1) )
    return v3;
  GRenderer::Cxform::Cxform();
  GMatrix2D::SetIdentity(result: v15);
  v4 = a1[12].__vftable;
  v24 = 0.0;
  v5 = (char *)v4 - (char *)a1[11].__vftable;
  v26 = 0x40000;
  v25 = 0;
  v27 = 0;
  BYTE1(a1[5].__vftable) = 0;
  if ( v5 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v6 = a1[11].__vftable;
  v7 = *(_WORD *)((char *)&v6->Connect + (unsigned int)a1[15].__vftable);
  v6 = (IShaderDeviceMgr_vtbl *)((char *)v6 + 2);
  v8 = (char *)a1[12].__vftable - (char *)v6;
  a1[11].__vftable = v6;
  v26 = v7;
  BYTE1(a1[5].__vftable) = 0;
  if ( v8 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v9 = a1[11].__vftable;
  v10 = *(_WORD *)((char *)&v9->Connect + (unsigned int)a1[15].__vftable);
  a1[11].__vftable = (IShaderDeviceMgr_vtbl *)((char *)&v9->Connect + 2);
  v25 = v10;
  GFxStream::ReadMatrix(this: (GFxStream *)a1, a2: &v23);
  GFxLogBase<GFxStream>::LogParse(
    this: (tagBITMAPINFOHEADER *)a1,
    a2: (int)"  CharId = %d\n  depth = %d\n  mat = \n",
    (unsigned __int16)v26,
    v25);
  GFxStream::LogParseClass(result: (_MAT2 *)&v23);
  v11 = (int)a1[13].__vftable + (char *)a1[11].__vftable - (char *)a1[12].__vftable;
  GFxStream::GetTagEndPosition(this: a1, a2: v16, a3: v19);
  if ( v11 < v12 )
  {
    GFxStream::ReadCxformRgb(this: (GFxStream *)a1, a2: &v22);
    GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)a1, a2: (int)"  cxform:\n");
    GFxStream::LogParseClass(this: (GFxStream *)a1, a2: &v22);
  }
  GFxStream::SetPosition(this: a1, pos, a3: v17);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: nullptr);
  return v21;
}

//------------------------------------------------------------------------------
// Address: 0x100C8260
// Name: public: static unsigned int GFxPlaceObject2::ComputeDataSize(class GFxStream __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxPlaceObject2::ComputeDataSize(__int128 movieVersion)
{
  int v2; // eax
  int v3; // eax
  char v4; // bl
  char *v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // edx
  int v14; // edx
  int v15; // eax
  char *v16; // eax
  int v17; // eax
  int v18; // eax
  __int16 v19; // dx
  int v20; // edx
  int v21; // eax
  int v22; // edx
  int v23; // eax
  int v24; // eax
  unsigned int v25; // edx
  char v26; // bl
  const char *v27; // eax
  ShaderDisplayMode_t *v28; // [esp+8h] [ebp-80h]
  _cpinfo *v29; // [esp+8h] [ebp-80h]
  int v30; // [esp+8h] [ebp-80h]
  int v31; // [esp+8h] [ebp-80h]
  int v32; // [esp+Ch] [ebp-7Ch]
  int v33; // [esp+18h] [ebp-70h]
  int tagStart; // [esp+1Ch] [ebp-6Ch]
  char *pname; // [esp+20h] [ebp-68h]
  unsigned int allFlags; // [esp+24h] [ebp-64h]
  char v37; // [esp+28h] [ebp-60h]
  char v38; // [esp+29h] [ebp-5Fh]
  char v39; // [esp+2Ah] [ebp-5Eh]
  char v40; // [esp+2Bh] [ebp-5Dh]
  char v41; // [esp+2Ch] [ebp-5Ch]
  char v42; // [esp+2Dh] [ebp-5Bh]
  bool hasChar; // [esp+2Eh] [ebp-5Ah]
  char v44; // [esp+2Fh] [ebp-59h]
  CMemberFunctor1<CMatRenderContextBase *,bool (__thiscall IMatRenderContext::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> pos; // [esp+30h] [ebp-58h] BYREF
  float v46; // [esp+74h] [ebp-14h]
  int v47; // [esp+78h] [ebp-10h]
  int v48; // [esp+7Ch] [ebp-Ch]
  int v49; // [esp+80h] [ebp-8h]

  tagStart = *(_DWORD *)(movieVersion + 44) + *(_DWORD *)(movieVersion + 52) - *(_DWORD *)(movieVersion + 48);
  GFxStream::GetTagEndPosition(this: (IShaderDeviceMgr *)movieVersion, a2: v28, a3: v32);
  if ( GFxStream::IsVerboseParse(this: (GFxStream *)movieVersion) )
  {
    v2 = *(_DWORD *)(movieVersion + 48) - *(_DWORD *)(movieVersion + 44);
    *(_BYTE *)(movieVersion + 21) = 0;
    if ( v2 < 1 )
      GFxStream::PopulateBuffer1(result: v29);
    v3 = *(_DWORD *)(movieVersion + 44);
    v4 = *(_BYTE *)(v3 + *(_DWORD *)(movieVersion + 60));
    v5 = nullptr;
    *(_DWORD *)(movieVersion + 44) = v3 + 1;
    allFlags = 0;
    pname = nullptr;
    GRenderer::Cxform::Cxform();
    GMatrix2D::SetIdentity(result: (const CMaterialDict::MissingMaterial_t *)v29);
    v6 = *(_DWORD *)(movieVersion + 48);
    v46 = 0.0;
    v7 = v6 - *(_DWORD *)(movieVersion + 44);
    v48 = 0x40000;
    v47 = 0;
    v49 = 0;
    *(_BYTE *)(movieVersion + 21) = 0;
    if ( v7 < 2 )
      GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
    v8 = *(_DWORD *)(movieVersion + 44);
    v9 = (unsigned __int16)(*(unsigned __int8 *)(*(_DWORD *)(movieVersion + 60) + v8)
                          | (*(unsigned __int8 *)(*(_DWORD *)(movieVersion + 60) + v8 + 1) << 8));
    v10 = v8 + 2;
    *(_DWORD *)(movieVersion + 44) = v10;
    v47 = v9;
    v41 = v4 & 2;
    if ( (v4 & 2) != 0 )
    {
      v11 = *(_DWORD *)(movieVersion + 48);
      HIBYTE(v49) |= 2u;
      *(_BYTE *)(movieVersion + 21) = 0;
      if ( v11 - v10 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v12 = *(_DWORD *)(movieVersion + 44);
      v13 = (unsigned __int16)(*(unsigned __int8 *)(v12 + *(_DWORD *)(movieVersion + 60))
                             | (*(unsigned __int8 *)(v12 + *(_DWORD *)(movieVersion + 60) + 1) << 8));
      *(_DWORD *)(movieVersion + 44) = v12 + 2;
      v48 = v13;
    }
    v38 = v4 & 4;
    if ( (v4 & 4) != 0 )
    {
      HIBYTE(v49) |= 4u;
      GFxStream::ReadMatrix(this: (GFxStream *)movieVersion, a2: (struct GMatrix2D *)(&pos.m_arg1 + 4));
    }
    v39 = v4 & 8;
    if ( (v4 & 8) != 0 )
    {
      HIBYTE(v49) |= 8u;
      GFxStream::ReadCxformRgba(this: (GFxStream *)movieVersion, a2: (struct GRenderer::Cxform *)&pos.m_iRefs);
    }
    v37 = v4 & 0x10;
    if ( (v4 & 0x10) != 0 )
    {
      v14 = *(_DWORD *)(movieVersion + 48) - *(_DWORD *)(movieVersion + 44);
      HIBYTE(v49) |= 0x10u;
      *(_BYTE *)(movieVersion + 21) = 0;
      if ( v14 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v15 = *(_DWORD *)(movieVersion + 44);
      v33 = (unsigned __int16)(*(unsigned __int8 *)(*(_DWORD *)(movieVersion + 60) + v15)
                             | (*(unsigned __int8 *)(*(_DWORD *)(movieVersion + 60) + v15 + 1) << 8));
      *(_DWORD *)(movieVersion + 44) = v15 + 2;
      v46 = (double)v33 / 65535.0;
    }
    v40 = v4 & 0x20;
    if ( (v4 & 0x20) != 0 )
    {
      GFxStream::ReadString(this: (IShaderDeviceMgr *)movieVersion);
      v5 = v16;
      pname = v16;
    }
    v42 = v4 & 0x40;
    if ( (v4 & 0x40) != 0 )
    {
      v17 = *(_DWORD *)(movieVersion + 48) - *(_DWORD *)(movieVersion + 44);
      HIBYTE(v49) |= 0x40u;
      *(_BYTE *)(movieVersion + 21) = 0;
      if ( v17 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v18 = *(_DWORD *)(movieVersion + 44);
      v19 = *(_WORD *)(*(_DWORD *)(movieVersion + 60) + v18);
      *(_DWORD *)(movieVersion + 44) = v18 + 2;
      LOWORD(v49) = v19;
    }
    v44 = v4 & 0x80;
    if ( v4 < 0 )
    {
      v20 = *(_DWORD *)(movieVersion + 48) - *(_DWORD *)(movieVersion + 44);
      *(_BYTE *)(movieVersion + 21) = 0;
      if ( v20 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      *(_DWORD *)(movieVersion + 44) += 2;
      v21 = *(_DWORD *)(movieVersion + 44);
      *(_BYTE *)(movieVersion + 21) = 0;
      if ( DWORD1(movieVersion) < 6 )
      {
        if ( *(_DWORD *)(movieVersion + 48) - v21 < 2 )
          GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
        v24 = *(_DWORD *)(movieVersion + 44);
        v25 = (unsigned __int16)(*(unsigned __int8 *)(*(_DWORD *)(movieVersion + 60) + v24)
                               | (*(unsigned __int8 *)(*(_DWORD *)(movieVersion + 60) + v24 + 1) << 8));
        *(_DWORD *)(movieVersion + 44) = v24 + 2;
        allFlags = v25;
      }
      else
      {
        if ( *(_DWORD *)(movieVersion + 48) - v21 < 4 )
          GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
        v22 = *(_DWORD *)(movieVersion + 44);
        v5 = pname;
        v23 = *(unsigned __int8 *)(v22 + *(_DWORD *)(movieVersion + 60))
            | ((*(unsigned __int8 *)(v22 + *(_DWORD *)(movieVersion + 60) + 1)
              | (*(unsigned __int16 *)(v22 + *(_DWORD *)(movieVersion + 60) + 2) << 8)) << 8);
        *(_DWORD *)(movieVersion + 44) = v22 + 4;
        allFlags = v23;
      }
    }
    GFxStream::SetPosition(this: (IShaderDeviceMgr *)movieVersion, pos: tagStart, a3: v30);
    hasChar = (v4 & 2) != 0;
    v26 = v4 & 1;
    GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)movieVersion, a2: (int)"  depth = %d\n", v47);
    if ( v41 != 0 )
      GFxLogBase<GFxStream>::LogParse(
        this: (tagBITMAPINFOHEADER *)movieVersion,
        a2: (int)"  char id = %d\n",
        (unsigned __int16)v48);
    if ( v38 != 0 )
    {
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)movieVersion, a2: (int)"  mat:\n");
      GFxStream::LogParseClass(result: (_MAT2 *)(&pos.m_arg1 + 4));
    }
    if ( v39 != 0 )
    {
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)movieVersion, a2: (int)"  cxform:\n");
      GFxStream::LogParseClass(this: (GFxStream *)movieVersion, a2: (const struct GRenderer::Cxform *)&pos.m_iRefs);
    }
    if ( v37 != 0 )
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)movieVersion, a2: (int)"  ratio: %f\n", v46);
    if ( v40 != 0 )
    {
      v27 = v5;
      if ( v5 == nullptr )
        v27 = "<null>";
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)movieVersion, a2: (int)"  name = %s\n", v27);
    }
    if ( v42 != 0 )
      GFxLogBase<GFxStream>::LogParse(
        this: (tagBITMAPINFOHEADER *)movieVersion,
        a2: (int)"  ClipDepth = %d\n",
        (unsigned __int16)v49);
    if ( v44 != 0 )
      GFxLogBase<GFxStream>::LogParse(
        this: (tagBITMAPINFOHEADER *)movieVersion,
        a2: (int)"  actions: flags = 0x%X\n",
        allFlags);
    if ( hasChar )
    {
      if ( v26 != 0 )
        GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)movieVersion, a2: (int)"    * (replace)\n");
    }
    else if ( v26 != 0 )
    {
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)movieVersion, a2: (int)"    * (move)\n");
    }
    if ( v5 != nullptr )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
    GFxStream::SetPosition(this: (IShaderDeviceMgr *)movieVersion, pos: tagStart, a3: v31);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C8710
// Name: protected: void GFxPlaceObject2::UnpackBase(struct GFxPlaceObjectBase::UnpackedData __near &,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxPlaceObject2::UnpackBase(
        CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),CFuncMemPolicyNone> *this@<ecx>,
        CMatQueuedRenderContext *data,
        __int128 version)
{
  int v3; // esi
  unsigned __int8 *DataBytes; // ecx
  unsigned __int8 v5; // dl
  int v6; // eax
  bool v7; // zf
  char v8; // bl
  int v10; // edi
  int v11; // eax
  int v12; // edx
  unsigned __int8 v13; // dl
  __int16 v14; // di
  void **v15; // edi
  int v16; // eax
  GMemoryHeap *v17; // eax
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  void **v19; // eax
  int v20; // ecx
  unsigned int v21; // esi
  int v22; // ecx
  GMemoryHeap *v23; // eax
  void *(__thiscall *v24)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  int v25; // eax
  unsigned int v26; // esi
  GFxSwfEvent **v27; // eax
  char v28; // al
  char v29; // dl
  _PSINJECTDATA v30; // [esp+8h] [ebp-20h] BYREF
  int v31; // [esp+10h] [ebp-18h]
  int v32; // [esp+14h] [ebp-14h]
  int v33; // [esp+18h] [ebp-10h] BYREF
  int v34; // [esp+1Ch] [ebp-Ch] BYREF
  CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),CFuncMemPolicyNone> *v35; // [esp+20h] [ebp-8h]
  char v36; // [esp+26h] [ebp-2h]
  unsigned __int8 po2Flags; // [esp+27h] [ebp-1h]
  int versionb; // [esp+30h] [ebp+8h]
  GFxSwfEvent *versiona; // [esp+30h] [ebp+8h]

  v3 = 0;
  v35 = this;
  DataBytes = (unsigned __int8 *)&this->m_pfnProxied + 4;
  v31 = 0;
  v30.DataBytes = (unsigned int)DataBytes;
  *(_DWORD *)&v30.InjectionPoint = -1;
  v32 = 0;
  v5 = *DataBytes;
  v6 = 1;
  v8 = *DataBytes & 0x80;
  v7 = (*DataBytes & 0x80u) == 0;
  po2Flags = *DataBytes;
  v31 = 1;
  v36 = v8;
  if ( !v7 )
  {
    v6 = 5;
    v31 = 5;
  }
  v32 = 0;
  v10 = *(unsigned __int16 *)&DataBytes[v6];
  v11 = v6 + 2;
  v31 = v11;
  data->m_RenderTargetStack.m_Memory.m_nGrowSize = v10;
  if ( (v5 & 2) != 0 )
  {
    HIBYTE(data->m_RenderTargetStack.m_pElements) |= 2u;
    v3 = 0;
    v32 = 0;
    v12 = *(unsigned __int16 *)&DataBytes[v11];
    v11 += 2;
    data->m_RenderTargetStack.m_Size = v12;
    v5 = po2Flags;
    v31 = v11;
  }
  if ( (v5 & 4) != 0 )
  {
    HIBYTE(data->m_RenderTargetStack.m_pElements) |= 4u;
    GFxStreamContext::ReadMatrix(
      this: (GFxStreamContext *)&v30,
      pm: (CMaterialDict *)&data->m_pCurrentFrameBufferCopyTexture[3]);
    v3 = v32;
    v11 = v31;
    DataBytes = (unsigned __int8 *)v30.DataBytes;
    v5 = po2Flags;
  }
  if ( (v5 & 8) != 0 )
  {
    HIBYTE(data->m_RenderTargetStack.m_pElements) |= 8u;
    GFxStreamContext::ReadCxformRgba(
      this: (GFxStreamContext *)&v30,
      a2: (struct GRenderer::Cxform *)&data->m_pCurrentMaterial);
    v3 = v32;
    v11 = v31;
    DataBytes = (unsigned __int8 *)v30.DataBytes;
    v5 = po2Flags;
  }
  if ( (v5 & 0x10) != 0 )
  {
    HIBYTE(data->m_RenderTargetStack.m_pElements) |= 0x10u;
    if ( v3 != 0 )
      v31 = ++v11;
    v3 = 0;
    v32 = 0;
    versionb = *(unsigned __int16 *)&DataBytes[v11];
    v5 = po2Flags;
    v11 += 2;
    v31 = v11;
    *(float *)&data->m_RenderTargetStack.m_Memory.m_nAllocationCount = (double)versionb / 65535.0;
  }
  if ( (v5 & 0x20) != 0 )
  {
    if ( v3 != 0 )
      v31 = ++v11;
    data->m_ScissorRectStack.m_Memory.m_nAllocationCount = (int)&v35->m_pfnProxied + v11 + 4;
    do
    {
      v3 = 0;
      v32 = 0;
      v13 = DataBytes[v11++];
      v31 = v11;
    }
    while ( v13 != 0 );
    v5 = po2Flags;
  }
  else
  {
    data->m_ScissorRectStack.m_Memory.m_nAllocationCount = 0;
  }
  if ( (v5 & 0x40) != 0 )
  {
    HIBYTE(data->m_RenderTargetStack.m_pElements) |= 0x40u;
    if ( v3 != 0 )
      v31 = ++v11;
    v3 = 0;
    v32 = 0;
    v14 = *(_WORD *)&DataBytes[v11];
    v11 += 2;
    LOWORD(data->m_RenderTargetStack.m_pElements) = v14;
  }
  v15 = nullptr;
  if ( v36 != 0 )
  {
    v15 = *(void ***)((char *)&v35->m_pfnProxied + 5);
    if ( v15 == nullptr )
    {
      if ( v3 != 0 )
        ++v11;
      v32 = *(_DWORD *)((char *)&v35->m_pfnProxied + 5);
      if ( (unsigned __int8)version < 6u )
        v16 = v11 + 4;
      else
        v16 = v11 + 6;
      v31 = v16;
      v17 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: v35);
      Alloc_2 = v17->Alloc_2;
      v34 = 260;
      v19 = (void **)Alloc_2(this: v17, a2: 12u, a3: (const GAllocDebugInfo *)&v34);
      v15 = nullptr;
      if ( v19 != nullptr )
      {
        *v19 = nullptr;
        v19[1] = nullptr;
        v19[2] = nullptr;
        v15 = v19;
      }
      while ( 1 )
      {
        v20 = v31;
        if ( v32 != 0 )
          v20 = ++v31;
        v32 = 0;
        if ( (unsigned __int8)version < 6u )
        {
          v21 = *(unsigned __int16 *)(v30.DataBytes + v20);
          v22 = v20 + 2;
        }
        else
        {
          v21 = *(unsigned __int8 *)(v30.DataBytes + v20)
              | (((*(unsigned __int16 *)(v30.DataBytes + v20 + 2) << 8) | *(unsigned __int8 *)(v30.DataBytes + v20 + 1)) << 8);
          v22 = v20 + 4;
        }
        v31 = v22;
        if ( v21 == 0 )
          break;
        v23 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: v35);
        v24 = v23->Alloc_2;
        v33 = 260;
        v25 = (int)v24(this: v23, a2: 20u, a3: (const GAllocDebugInfo *)&v33);
        if ( v25 != 0 )
        {
          *(_DWORD *)v25 = 0;
          *(_DWORD *)(v25 + 4) = 0;
          *(_WORD *)(v25 + 8) = 0;
          *(_DWORD *)(v25 + 10) = 65280;
          *(_DWORD *)(v25 + 16) = 0;
          versiona = (GFxSwfEvent *)v25;
        }
        else
        {
          versiona = nullptr;
        }
        GFxSwfEvent::Read(this: versiona, psc: &v30, flags: v21);
        v26 = (unsigned int)v15[1] + 1;
        if ( v26 >= (unsigned int)v15[1] )
        {
          if ( v26 >= (unsigned int)v15[2] )
            GArrayDataBase<GFxSwfEvent *,GAllocatorLH<GFxSwfEvent *,260>,GArrayDefaultPolicy>::Reserve(
              this: v15,
              a2: v15,
              a3: v26 + (v26 >> 2));
        }
        else if ( v26 < (unsigned int)v15[2] >> 1 )
        {
          GArrayDataBase<GFxSwfEvent *,GAllocatorLH<GFxSwfEvent *,260>,GArrayDefaultPolicy>::Reserve(
            this: v15,
            a2: v15,
            a3: (int)v15[1] + 1);
        }
        v27 = (GFxSwfEvent **)((char *)*v15 + 4 * v26 - 4);
        v15[1] = (void *)v26;
        if ( v27 != nullptr )
          *v27 = versiona;
      }
      *(_DWORD *)((char *)&v35->m_pfnProxied + 5) = v15;
      v5 = po2Flags;
    }
  }
  v28 = v5 >> 1;
  v29 = v5 & 1;
  data->m_ScissorRectStack.m_Memory.m_pMemory = (CMatRenderContextBase::ScissorRectStackElement_t *)v15;
  data->m_ScissorRectStack.m_Memory.m_nGrowSize = 0;
  if ( (v28 & 1) != 0 )
  {
    if ( v29 != 0 )
      data->m_ScissorRectStack.m_Memory.m_nGrowSize = 2;
  }
  else if ( v29 != 0 )
  {
    data->m_ScissorRectStack.m_Memory.m_nGrowSize = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C8A50
// Name: public: virtual GFxPlaceObject3::~GFxPlaceObject3(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPlaceObject3::~GFxPlaceObject3(GFxPlaceObject3 *this)
{
  GFxPlaceObject3 *v1; // esi
  int v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // edi
  _DWORD *v5; // esi
  IShaderAPI *v6; // ecx
  unsigned int v8; // [esp+8h] [ebp-4h]

  v1 = this;
  *(_DWORD *)this = &GFxPlaceObject3::`vftable';
  if ( *((char *)this + 4) >= 0 )
  {
    *(_DWORD *)this = &GASExecuteTag::`vftable';
  }
  else
  {
    v2 = *(_DWORD *)((char *)this + 5);
    if ( v2 != 0 )
    {
      v3 = *(_DWORD *)(v2 + 4);
      v4 = 0;
      v8 = v3;
      if ( v3 != 0 )
      {
        do
        {
          v5 = *(_DWORD **)(*(_DWORD *)v2 + 4 * v4);
          if ( v5 != nullptr )
          {
            v6 = (IShaderAPI *)v5[4];
            if ( v6 != nullptr )
              GRefCountImpl::Release(this: v6);
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
            v3 = v8;
          }
          ++v4;
        }
        while ( v4 < v3 );
        v1 = this;
      }
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)v2);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
      *(_DWORD *)v1 = &GASExecuteTag::`vftable';
    }
    else
    {
      *(_DWORD *)this = &GASExecuteTag::`vftable';
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C8AF0
// Name: public: static unsigned int GFxPlaceObject3::ComputeDataSize(class GFxStream __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxPlaceObject3::ComputeDataSize(IShaderDeviceMgr *len, void *const *tagStart, const bool *pos)
{
  int v4; // eax
  IShaderDeviceMgr_vtbl *v5; // eax
  char v6; // bl
  int v7; // edx
  IShaderDeviceMgr_vtbl *v8; // eax
  IShaderDeviceMgr_vtbl *v9; // ecx
  int v10; // ecx
  IShaderDeviceMgr_vtbl *v11; // eax
  int v12; // edx
  IShaderDeviceMgr_vtbl *v13; // eax
  IShaderDeviceMgr_vtbl *v14; // ecx
  IShaderDeviceMgr_vtbl *v15; // eax
  int v16; // edx
  int v17; // edx
  IShaderDeviceMgr_vtbl *v18; // eax
  char *v19; // eax
  int v20; // eax
  IShaderDeviceMgr_vtbl *v21; // eax
  __int16 v22; // dx
  int v23; // ebx
  char *v24; // edi
  int v25; // eax
  IShaderDeviceMgr_vtbl *v26; // ecx
  char v27; // al
  int v28; // eax
  int v29; // ecx
  int v30; // edx
  IShaderDeviceMgr_vtbl *v31; // edx
  int v32; // eax
  bool v33; // bl
  const char *v34; // eax
  ShaderDisplayMode_t *v35; // [esp+8h] [ebp-2F4h]
  _cpinfo *v36; // [esp+8h] [ebp-2F4h]
  _cpinfo *v37; // [esp+8h] [ebp-2F4h]
  int v38; // [esp+8h] [ebp-2F4h]
  int v39; // [esp+Ch] [ebp-2F0h]
  int v40; // [esp+14h] [ebp-2E8h]
  int tagStarta; // [esp+1Ch] [ebp-2E0h]
  unsigned int allFlags; // [esp+20h] [ebp-2DCh]
  char *pname; // [esp+24h] [ebp-2D8h]
  char v44; // [esp+2Bh] [ebp-2D1h]
  char v45; // [esp+2Ch] [ebp-2D0h]
  char v46; // [esp+2Dh] [ebp-2CFh]
  char v47; // [esp+2Eh] [ebp-2CEh]
  char v48; // [esp+2Fh] [ebp-2CDh]
  char v49; // [esp+30h] [ebp-2CCh]
  char v50; // [esp+31h] [ebp-2CBh]
  unsigned __int8 po3Flags; // [esp+32h] [ebp-2CAh]
  unsigned __int8 po3Flagsa; // [esp+32h] [ebp-2CAh]
  bool flagMove; // [esp+33h] [ebp-2C9h]
  bool flagMovea; // [esp+33h] [ebp-2C9h]
  CMemberFunctor1<CMatRenderContextBase *,bool (__thiscall IMatRenderContext::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> posa; // [esp+34h] [ebp-2C8h] BYREF
  float v56; // [esp+78h] [ebp-284h]
  int v57; // [esp+7Ch] [ebp-280h]
  int v58; // [esp+80h] [ebp-27Ch]
  int v59; // [esp+84h] [ebp-278h]
  unsigned __int64 filters[4]; // [esp+88h] [ebp-274h] BYREF

  tagStarta = (int)len[11].__vftable + (char *)len[13].__vftable - (char *)len[12].__vftable;
  GFxStream::GetTagEndPosition(this: len, a2: v35, a3: v39);
  if ( GFxStream::IsVerboseParse(this: (GFxStream *)len) )
  {
    v4 = (char *)len[12].__vftable - (char *)len[11].__vftable;
    BYTE1(len[5].__vftable) = 0;
    if ( v4 < 1 )
      GFxStream::PopulateBuffer1(result: v36);
    v5 = len[11].__vftable;
    v6 = *((_BYTE *)&v5->Connect + (unsigned int)len[15].__vftable);
    v5 = (IShaderDeviceMgr_vtbl *)((char *)v5 + 1);
    v7 = (char *)len[12].__vftable - (char *)v5;
    flagMove = v6;
    len[11].__vftable = v5;
    BYTE1(len[5].__vftable) = 0;
    if ( v7 < 1 )
      GFxStream::PopulateBuffer1(result: v36);
    v8 = len[11].__vftable;
    po3Flags = *((_BYTE *)&v8->Connect + (unsigned int)len[15].__vftable);
    len[11].__vftable = (IShaderDeviceMgr_vtbl *)((char *)&v8->Connect + 1);
    allFlags = 0;
    pname = nullptr;
    GRenderer::Cxform::Cxform();
    GMatrix2D::SetIdentity(result: (const CMaterialDict::MissingMaterial_t *)v36);
    v9 = len[12].__vftable;
    v56 = 0.0;
    v10 = (char *)v9 - (char *)len[11].__vftable;
    v58 = 0x40000;
    v57 = 0;
    v59 = 0;
    BYTE1(len[5].__vftable) = 0;
    if ( v10 < 2 )
      GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
    v11 = len[11].__vftable;
    v12 = (unsigned __int16)(*((unsigned __int8 *)&v11->Connect + (unsigned int)len[15].__vftable)
                           | (*((unsigned __int8 *)&v11->Connect + (unsigned int)len[15].__vftable + 1) << 8));
    v13 = (IShaderDeviceMgr_vtbl *)((char *)&v11->Connect + 2);
    len[11].__vftable = v13;
    v57 = v12;
    v46 = v6 & 2;
    if ( (v6 & 2) != 0 )
    {
      v14 = len[12].__vftable;
      HIBYTE(v59) |= 2u;
      BYTE1(len[5].__vftable) = 0;
      if ( (char *)v14 - (char *)v13 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v15 = len[11].__vftable;
      v16 = (unsigned __int16)(*((unsigned __int8 *)&v15->Connect + (unsigned int)len[15].__vftable)
                             | (*((unsigned __int8 *)&v15->Connect + (unsigned int)len[15].__vftable + 1) << 8));
      len[11].__vftable = (IShaderDeviceMgr_vtbl *)((char *)&v15->Connect + 2);
      v58 = v16;
    }
    v45 = v6 & 4;
    if ( (v6 & 4) != 0 )
    {
      HIBYTE(v59) |= 4u;
      GFxStream::ReadMatrix(this: (GFxStream *)len, a2: (struct GMatrix2D *)(&posa.m_arg1 + 4));
    }
    v48 = v6 & 8;
    if ( (v6 & 8) != 0 )
    {
      HIBYTE(v59) |= 8u;
      GFxStream::ReadCxformRgba(this: (GFxStream *)len, a2: (struct GRenderer::Cxform *)&posa.m_iRefs);
    }
    v44 = v6 & 0x10;
    if ( (v6 & 0x10) != 0 )
    {
      v17 = (char *)len[12].__vftable - (char *)len[11].__vftable;
      HIBYTE(v59) |= 0x10u;
      BYTE1(len[5].__vftable) = 0;
      if ( v17 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v18 = len[11].__vftable;
      v40 = (unsigned __int16)(*((unsigned __int8 *)&len[15].Connect + (unsigned int)v18)
                             | (*((unsigned __int8 *)&len[15].Connect + (unsigned int)v18 + 1) << 8));
      len[11].__vftable = (IShaderDeviceMgr_vtbl *)((char *)&v18->Connect + 2);
      v56 = (double)v40 / 65535.0;
    }
    v47 = v6 & 0x20;
    if ( (v6 & 0x20) != 0 )
    {
      GFxStream::ReadString(this: len);
      pname = v19;
    }
    v50 = v6 & 0x40;
    if ( (v6 & 0x40) != 0 )
    {
      v20 = (char *)len[12].__vftable - (char *)len[11].__vftable;
      HIBYTE(v59) |= 0x40u;
      BYTE1(len[5].__vftable) = 0;
      if ( v20 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v21 = len[11].__vftable;
      v22 = *(_WORD *)((char *)&len[15].Connect + (unsigned int)v21);
      len[11].__vftable = (IShaderDeviceMgr_vtbl *)((char *)&v21->Connect + 2);
      LOWORD(v59) = v22;
    }
    if ( (po3Flags & 1) != 0 )
    {
      HIBYTE(v59) |= 0x20u;
      v23 = 3;
      v24 = (char *)&filters[1] + 4;
      do
      {
        *((_DWORD *)v24 - 1) = 0;
        *(float *)v24 = 5.0;
        *((_DWORD *)v24 + 2) = 1;
        *((float *)v24 + 1) = 5.0;
        *((float *)v24 + 3) = 0.0;
        *((float *)v24 + 4) = 0.0;
        *((float *)v24 + 7) = 1.0;
        GRenderer::Cxform::Cxform();
        v24 += 156;
        --v23;
      }
      while ( v23 >= 0 );
      GFx_LoadFilters<GFxStream>();
      v6 = flagMove;
    }
    v49 = po3Flags & 2;
    if ( (po3Flags & 2) != 0 )
    {
      v25 = (char *)len[12].__vftable - (char *)len[11].__vftable;
      BYTE1(len[5].__vftable) = 0;
      if ( v25 < 1 )
        GFxStream::PopulateBuffer1(result: v37);
      v26 = len[11].__vftable;
      v27 = *((_BYTE *)&v26->Connect + (unsigned int)len[15].__vftable);
      len[11].__vftable = (IShaderDeviceMgr_vtbl *)((char *)&v26->Connect + 1);
      if ( v27 == 0 || (unsigned __int8)v27 > 0xEu )
        v27 = 1;
      HIBYTE(v59) |= 0x80u;
      BYTE2(v59) = v27;
    }
    if ( (po3Flags & 4) != 0 )
    {
      v28 = (char *)len[12].__vftable - (char *)len[11].__vftable;
      BYTE1(len[5].__vftable) = 0;
      if ( v28 < 1 )
        GFxStream::PopulateBuffer1(result: v37);
      ++len[11].__vftable;
    }
    po3Flagsa = v6 & 0x80;
    if ( v6 < 0 )
    {
      v29 = (char *)len[12].__vftable - (char *)len[11].__vftable;
      BYTE1(len[5].__vftable) = 0;
      if ( v29 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      len[11].__vftable = (IShaderDeviceMgr_vtbl *)((char *)len[11].__vftable + 2);
      v30 = (char *)len[12].__vftable - (char *)len[11].__vftable;
      BYTE1(len[5].__vftable) = 0;
      if ( v30 < 4 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
      v31 = len[11].__vftable;
      v32 = *((unsigned __int8 *)&v31->Connect + (unsigned int)len[15].__vftable)
          | ((*((unsigned __int8 *)&v31->Connect + (unsigned int)len[15].__vftable + 1)
            | (*(unsigned __int16 *)((char *)&v31->Connect + (unsigned int)len[15].__vftable + 2) << 8)) << 8);
      len[11].__vftable = (IShaderDeviceMgr_vtbl *)&v31->Disconnect;
      allFlags = v32;
    }
    GFxStream::SetPosition(this: len, pos: tagStarta, a3: (int)v37);
    flagMovea = flagMove;
    v33 = (v6 & 2) != 0;
    GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)len, a2: (int)"  depth = %d\n", v57);
    if ( v46 != 0 )
      GFxLogBase<GFxStream>::LogParse(
        this: (tagBITMAPINFOHEADER *)len,
        a2: (int)"  char id = %d\n",
        (unsigned __int16)v58);
    if ( v45 != 0 )
    {
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)len, a2: (int)"  mat:\n");
      GFxStream::LogParseClass(result: (_MAT2 *)(&posa.m_arg1 + 4));
    }
    if ( v48 != 0 )
    {
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)len, a2: (int)"  cxform:\n");
      GFxStream::LogParseClass(this: (GFxStream *)len, a2: (const struct GRenderer::Cxform *)&posa.m_iRefs);
    }
    if ( v44 != 0 )
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)len, a2: (int)"  ratio: %f\n", v56);
    if ( v47 != 0 )
    {
      v34 = pname;
      if ( pname == nullptr )
        v34 = "<null>";
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)len, a2: (int)"  name = %s\n", v34);
    }
    if ( v50 != 0 )
      GFxLogBase<GFxStream>::LogParse(
        this: (tagBITMAPINFOHEADER *)len,
        a2: (int)"  ClipDepth = %d\n",
        (unsigned __int16)v59);
    if ( v49 != 0 )
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)len, a2: (int)"  blend mode = %d\n", BYTE2(v59));
    if ( po3Flagsa != 0 )
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)len, a2: (int)"  actions: flags = 0x%X\n", allFlags);
    if ( v33 )
    {
      if ( flagMovea )
        GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)len, a2: (int)"    * (replace)\n");
    }
    else if ( flagMovea )
    {
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)len, a2: (int)"    * (move)\n");
    }
    if ( pname != nullptr )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: pname);
    GFxStream::SetPosition(this: len, pos: tagStarta, a3: v38);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C90B0
// Name: public: virtual void GFxPlaceObject3::Execute(class GFxSprite __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPlaceObject3::Execute(
        GFxPlaceObject3 *this,
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *a2)
{
  int v3; // edx
  void (__thiscall *v4)(GFxPlaceObject3 *, _IMAGE_SYMBOL_EX *); // edx
  int v5; // eax
  int v6; // esi
  int v7; // eax
  char v8; // bl
  bool v9; // zf
  int v10; // eax
  int v11; // esi
  char v12; // bl
  int v13; // eax
  const CMaterialDict::MissingMaterial_t *v14; // [esp+0h] [ebp-7Ch]
  int v15; // [esp+10h] [ebp-6Ch] BYREF
  int v16; // [esp+14h] [ebp-68h]
  _IMAGE_SYMBOL_EX name; // [esp+18h] [ebp-64h] BYREF
  float v18; // [esp+5Ch] [ebp-20h]
  int v19; // [esp+60h] [ebp-1Ch]
  int v20; // [esp+64h] [ebp-18h]
  int v21; // [esp+68h] [ebp-14h]
  int v22; // [esp+6Ch] [ebp-10h]
  int v23; // [esp+70h] [ebp-Ch]
  int v24; // [esp+74h] [ebp-8h]

  v16 = 0;
  memset(&name, 0, 12);
  GRenderer::Cxform::Cxform();
  GMatrix2D::SetIdentity(result: v14);
  v3 = *(_DWORD *)this;
  v18 = 0.0;
  v4 = *(void (__thiscall **)(GFxPlaceObject3 *, _IMAGE_SYMBOL_EX *))(v3 + 32);
  v21 = 0;
  v20 = 0x40000;
  v19 = 0;
  v4(a1: this, a2: &name);
  if ( v24 != 0 )
  {
    if ( v24 == 1 )
    {
      GFxSprite::MoveDisplayObject(this: (GFxSprite *)a2, a2: (const struct GFxCharPosInfo *)&name);
    }
    else if ( v24 == 2 )
    {
      v5 = (*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(a2->m_pfnProxied) + 112))(a1: a2);
      if ( v23 != 0 )
      {
        v8 = 8;
        GASStringManager::CreateStringNode(this: *(const char **)(*(_DWORD *)(v5 + 120) + 636));
        ++*(_DWORD *)(v7 + 8);
        v15 = v7;
        v6 = v7;
      }
      else
      {
        v6 = *(_DWORD *)(*(_DWORD *)(v5 + 120) + 8);
        ++*(_DWORD *)(v6 + 8);
        v15 = v6;
        v7 = v6;
        v8 = 4;
      }
      v16 = v15;
      ++*(_DWORD *)(v15 + 8);
      if ( (v8 & 8) != 0 )
      {
        v8 &= ~8u;
        v9 = (*(_DWORD *)(v7 + 8))-- == 1;
        if ( v9 )
          GASStringNode::ReleaseNode();
      }
      if ( (v8 & 4) != 0 )
      {
        v9 = (*(_DWORD *)(v6 + 8))-- == 1;
        if ( v9 )
          GASStringNode::ReleaseNode();
      }
      GFxSprite::ReplaceDisplayObject(this: (GMemoryFile *)a2);
      v9 = (*(_DWORD *)(v16 + 8))-- == 1;
      if ( v9 )
LABEL_26:
        GASStringNode::ReleaseNode();
    }
  }
  else
  {
    v10 = (*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(a2->m_pfnProxied) + 112))(a1: a2);
    if ( v23 != 0 )
    {
      v12 = 2;
      GASStringManager::CreateStringNode(this: *(const char **)(*(_DWORD *)(v10 + 120) + 636));
      ++*(_DWORD *)(v13 + 8);
      v16 = v13;
      v11 = v13;
    }
    else
    {
      v11 = *(_DWORD *)(*(_DWORD *)(v10 + 120) + 8);
      v12 = 1;
      ++*(_DWORD *)(v11 + 8);
      v16 = v11;
      v13 = v11;
    }
    v15 = v16;
    ++*(_DWORD *)(v16 + 8);
    if ( (v12 & 2) != 0 )
    {
      v12 &= ~2u;
      v9 = (*(_DWORD *)(v13 + 8))-- == 1;
      if ( v9 )
        GASStringNode::ReleaseNode();
    }
    if ( (v12 & 1) != 0 )
    {
      v9 = (*(_DWORD *)(v11 + 8))-- == 1;
      if ( v9 )
        GASStringNode::ReleaseNode();
    }
    GFxSprite::AddDisplayObject(
      this: a2,
      &name,
      a3: (int)&v15,
      a4: v22,
      a5: 0,
      createFrame: 0xFFFFFFFF,
      addFlags: 4u,
      rh: nullptr,
      a9: 0);
    v9 = (*(_DWORD *)(v15 + 8))-- == 1;
    if ( v9 )
      goto LABEL_26;
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)name.N.Name.Short);
}

//------------------------------------------------------------------------------
// Address: 0x100C9500
// Name: public: GFxMovieRoot::InvokeAliasInfo::InvokeAliasInfo(struct GFxMovieRoot::InvokeAliasInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
const GPtr<GFxActionControl> *__thiscall GFxMovieRoot::InvokeAliasInfo::InvokeAliasInfo(
        GPtr<GFxActionControl> *this,
        const GPtr<GFxActionControl> *__that)
{
  GFxActionControl *pObject; // ecx
  GFxActionControl *v4; // edx
  tagIMECHARPOSITION *v5; // edx

  if ( __that->pObject != nullptr )
    __that->pObject->SType = (__that->pObject->SType + 1) & 0x8FFFFFFF;
  this->pObject = __that->pObject;
  pObject = __that[1].pObject;
  if ( pObject != nullptr )
    ++pObject->__vftable;
  *(this + 1) = __that[1];
  *((_BYTE *)this + 16) = 0;
  v4 = __that[2].pObject;
  *((_DWORD *)this + 2) = v4;
  if ( v4 != nullptr )
    v4->SType = (v4->SType + 1) & 0x8FFFFFFF;
  *((_DWORD *)this + 3) = 0;
  v5 = (tagIMECHARPOSITION *)__that[3].pObject;
  if ( v5 != nullptr )
    GASFunctionRefBase::SetLocalFrame(result: v5);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C97C0
// Name: public: bool GFxMovieRoot::SetLevelMovie(int,class GFxSprite __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GFxMovieRoot::SetLevelMovie@<al>(
        GPtr<GFxTextKeyMap> *this@<ecx>,
        VertexShaderHandle_t__ *a2@<edi>,
        GFxTextKeyMap *a3,
        GRefCountNTSImpl *a4)
{
  unsigned int v5; // eax
  _DWORD *v6; // edx
  _DWORD *v7; // ecx
  IShaderDevice *v8; // eax
  IShaderDevice *v9; // ebx
  IShaderDevice *v10; // ecx
  IShaderDevice *v11; // ecx
  void (__thiscall *SetHardwareGammaRamp)(IShaderDevice *, float, float, float, float, bool); // eax
  GFxAmpViewStats *v13; // ebx
  const char *v14; // eax
  IShaderDevice *v15; // eax
  int v16; // ebx
  IShaderAPI *v17; // ecx
  double v18; // st7
  bool v19; // zf
  int v20; // edi
  int v21; // ebx
  int v22; // eax
  GPtr<GFxTextKeyMap> v23; // eax
  void (__thiscall *RefCount)(GPtr<GFxTextKeyMap> *, float *); // edx
  GRefCountNTSImpl *v25; // ecx
  VertexShaderHandle_t__ *v27; // [esp-4h] [ebp-48h]
  float v28[13]; // [esp+8h] [ebp-3Ch] BYREF
  GFxTextKeyMap *v29; // [esp+3Ch] [ebp-8h] BYREF
  GRefCountNTSImpl *v30; // [esp+40h] [ebp-4h]
  int v31; // [esp+4Ch] [ebp+8h]
  int v32; // [esp+4Ch] [ebp+8h]
  struct GFxSprite *v33; // [esp+50h] [ebp+Ch]

  v5 = 0;
  if ( *((_DWORD *)this + 10) != 0 )
  {
    v6 = *((_DWORD **)this + 9);
    v7 = v6;
    while ( *v7 < (int)a3 )
    {
      ++v5;
      v7 += 2;
      if ( v5 >= *((_DWORD *)this + 10) )
        goto LABEL_5;
    }
    if ( (GFxTextKeyMap *)v6[2 * v5] == a3 )
      return 0;
  }
LABEL_5:
  *((_DWORD *)this + 2333) |= 0x100u;
  v27 = a2;
  v30 = nullptr;
  v29 = a3;
  if ( a4 != nullptr )
    ++a4->RefCount;
  v30 = a4;
  GArrayBase<GArrayData<GFxMovieRoot::LevelInfo,GAllocatorLH<GFxMovieRoot::LevelInfo,326>,GArrayDefaultPolicy>>::InsertAt(
    this: this + 9,
    index: (GFxTextKeyMap *)v5,
    a3: &v29);
  ((void (__thiscall *)(GRefCountNTSImpl *, GFxTextKeyMap *))a4->__vftable[94].dtr_GRefCountImplCore)(a1: a4, a2: a3);
  if ( a3 == nullptr )
  {
    *((_DWORD *)this + 12) = a4;
    v8 = (IShaderDevice *)((int (__thiscall *)(GRefCountNTSImpl *))a4->__vftable[23].dtr_GRefCountImplCore)(a1: a4);
    v9 = v8;
    if ( v8 != nullptr )
      GRefCountImpl::AddRef(this: v8, a2);
    v10 = *((IShaderDevice **)this + 13);
    if ( v10 != nullptr )
      GFxResource::Release(this: v10);
    v11 = v9;
    *((_DWORD *)this + 13) = v9;
    if ( v9 != nullptr )
    {
      SetHardwareGammaRamp = v9->SetHardwareGammaRamp;
      v13 = *((GFxAmpViewStats **)this + 2577);
      v14 = (const char *)((int (__thiscall *)(IShaderDevice *))SetHardwareGammaRamp)(a1: v11);
      GFxAmpViewStats::SetName(this: v13, a2: v14);
    }
    v15 = *(IShaderDevice **)(*((_DWORD *)this + 13) + 16);
    v16 = *((_DWORD *)this + 60);
    v31 = (int)v15;
    if ( v15 != nullptr )
    {
      GRefCountImpl::AddRef(this: v15, a2: v27);
      v15 = (IShaderDevice *)v31;
    }
    v17 = *(IShaderAPI **)(v16 + 20);
    if ( v17 != nullptr )
    {
      GRefCountImpl::Release(this: v17);
      v15 = (IShaderDevice *)v31;
    }
    *(_DWORD *)(v16 + 20) = v15;
    v18 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(**((_DWORD **)this + 13) + 36))(a1: *((_DWORD *)this + 13));
    v19 = (*(_BYTE *)(this + 2333) & 1) == 0;
    *((float *)this + 75) = 1.0 / v18;
    if ( v19 )
    {
      v20 = ((int (__thiscall *)(GRefCountNTSImpl *))a4->__vftable[23].dtr_GRefCountImplCore)(a1: a4);
      v21 = (int)((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v20 + 28))(a1: v20);
      v33 = (struct GFxSprite *)(int)((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v20 + 24))(a1: v20);
      v32 = (int)((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v20 + 28))(a1: v20);
      v22 = (int)((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v20 + 24))(a1: v20);
      v28[11] = 1.0;
      v28[10] = 1.0;
      LODWORD(v28[0]) = v22;
      LODWORD(v28[1]) = v32;
      v28[2] = 0.0;
      v28[3] = 0.0;
      v28[12] = 0.0;
      memset(&v28[6], 0, 16);
      v23.pObject = this->pObject;
      LODWORD(v28[4]) = v33;
      RefCount = (void (__thiscall *)(GPtr<GFxTextKeyMap> *, float *))v23.pObject[4].RefCount;
      LODWORD(v28[5]) = v21;
      RefCount(a1: this, a2: v28);
    }
  }
  v25 = v30;
  *((_DWORD *)this + 2333) |= 0x80u;
  if ( v25 != nullptr )
    GRefCountNTSImpl::Release(this: v25);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C9990
// Name: public: void GFxMovieRoot::AddLoadQueueEntry(char const __near *,char const __near *,class GASEnvironment __near *,enum GFxLoadQueueEntry::LoadMethod,class GASMovieClipLoader __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::AddLoadQueueEntry(
        ScaleformRenderTarget_vtbl **this,
        __vc_attributes::event_receiverAttribute::type_e a2,
        char *a3,
        GString a4,
        GRendererNode *a5,
        GPtr<IDirect3DVertexDeclaration9> pmovieClipLoader)
{
  char *v6; // esi
  __vc_attributes::event_receiverAttribute *pData; // edi
  ScaleformRenderTarget_vtbl **v8; // ebx
  const char *AddChangeHandler; // ecx
  __vc_attributes::event_receiverAttribute::type_e v10; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v11; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v12; // edi
  __vc_attributes::event_receiverAttribute::type_e v13; // eax
  const char *v14; // ecx
  __vc_attributes::event_receiverAttribute::type_e v15; // eax
  __vc_attributes::event_receiverAttribute *v16; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v17; // eax
  bool v18; // zf
  _TAPE_WMI_OPERATIONS *v19; // eax
  GTexture::ChangeHandler::EventType Method; // esi
  ScaleformRenderTarget_vtbl *v21; // ecx
  int (__thiscall *v22)(ScaleformRenderTarget_vtbl *, int, int *); // edx
  int v23; // esi
  _DWORD *v24; // ebx
  _DWORD *v25; // eax
  GFxCharacterHandle *v26; // edi
  GRendererNode *v27; // edx
  void *v28; // edi
  LONG v29; // eax
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *v30; // ecx
  int v31; // eax
  ScaleformRenderTarget_vtbl *v32; // ecx
  int (__thiscall *v33)(ScaleformRenderTarget_vtbl *, int, GString *); // edx
  GTextureImplNode *v34; // edi
  int v35; // eax
  _TAPE_WMI_OPERATIONS *v36; // [esp+0h] [ebp-1Ch]
  int v37; // [esp+0h] [ebp-1Ch]
  int v39; // [esp+10h] [ebp-Ch] BYREF
  __vc_attributes::event_receiverAttribute::type_e path; // [esp+14h] [ebp-8h] BYREF
  int v41; // [esp+18h] [ebp-4h]

  v6 = (char *)a2;
  pData = (__vc_attributes::event_receiverAttribute *)a4.pData;
  v8 = this;
  v41 = 0;
  if ( a4.pData != nullptr )
  {
    AddChangeHandler = (const char *)(*(this + 2289))[22].AddChangeHandler;
    v41 = 1;
    GASStringManager::CreateStringNode(this: AddChangeHandler);
    path = v10;
    ++*(_DWORD *)(v10 + 8);
    GASEnvironment::FindTarget(
      this: pData,
      (__vc_attributes::event_receiverAttribute::type_e)&path,
      excludeFlags: false);
    v12 = v11;
    v13 = a2;
  }
  else
  {
    v14 = (const char *)(*(this + 2289))[22].AddChangeHandler;
    v41 = 2;
    GASStringManager::CreateStringNode(this: v14);
    a2 = v15;
    ++*(_DWORD *)(v15 + 8);
    v13 = a2;
    if ( v8[12] != nullptr && *(_DWORD *)(a2 + 16) != 0 )
    {
      v16 = (__vc_attributes::event_receiverAttribute *)(*((int (__thiscall **)(ScaleformRenderTarget_vtbl *))v8[12]->dtr_GRenderTarget
                                                         + 28))(a1: v8[12]);
      GASEnvironment::FindTarget(
        this: v16,
        path: (__vc_attributes::event_receiverAttribute::type_e)&a2,
        excludeFlags: false);
      v12 = v17;
      v13 = a2;
    }
    else
    {
      v12 = nullptr;
    }
  }
  if ( (v41 & 2) != 0 )
  {
    v41 &= ~2u;
    v18 = (*(_DWORD *)(v13 + 8))-- == 1;
    if ( v18 )
      GASStringNode::ReleaseNode();
  }
  if ( (v41 & 1) != 0 )
  {
    v41 &= ~1u;
    v18 = (*(_DWORD *)(path + 8))-- == 1;
    if ( v18 )
      GASStringNode::ReleaseNode();
  }
  if ( v12 != nullptr )
  {
    v19 = GASObjectInterface::ToSprite(result: v36);
    if ( v19 == nullptr || (Method = v19[37].Method) == -1 )
    {
      v21 = v8[8];
      v22 = *((int (__thiscall **)(ScaleformRenderTarget_vtbl *, int, int *))v21->dtr_GRenderTarget + 10);
      v39 = 326;
      v23 = v22(a1: v21, a2: 108, a3: &v39);
      if ( v23 != 0 )
      {
        GString::GString(this: &a4, a2: a3);
        v24 = (_DWORD *)DWORD1(v12[6].m_pfnProxied);
        v41 |= 4u;
        if ( v24 == nullptr )
        {
          GFxASCharacter::CreateCharacterHandle(this: v12);
          v24 = v25;
        }
        GString::GString(this: (CUtlMemory<CImagePacker,int> *)(v23 + 12));
        *(_DWORD *)(v23 + 20) = 0;
        *(_BYTE *)(v23 + 28) = 0;
        *(_BYTE *)(v23 + 44) = 0;
        *(_BYTE *)(v23 + 64) = 0;
        *(_DWORD *)(v23 + 80) = 0;
        *(_BYTE *)(v23 + 84) = 0;
        *(_DWORD *)(v23 + 100) = 0;
        *(_DWORD *)(v23 + 4) = (a4.HeapTypeBits & 0xFFFFFFFC) == -8;
        if ( v24 != nullptr )
          ++*v24;
        v26 = *(GFxCharacterHandle **)(v23 + 20);
        if ( v26 != nullptr )
        {
          *v26 = (GFxCharacterHandle)((char *)*v26 - 1);
          if ( (int)*v26 <= 0 )
          {
            GFxCharacterHandle::~GFxCharacterHandle(this: v26);
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v26);
          }
        }
        v27 = a5;
        *(_DWORD *)(v23 + 20) = v24;
        *(_DWORD *)v23 = 0;
        *(_DWORD *)(v23 + 8) = v27;
        *(_DWORD *)(v23 + 16) = -1;
        GString::operator=(
          this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v23 + 12),
          src: (int)&a4,
          a3: v37);
        v8 = this;
        *(_BYTE *)(v23 + 24) = 0;
        *(_DWORD *)(v23 + 60) = -1;
        *(_BYTE *)(v23 + 104) = 0;
      }
      else
      {
        v23 = 0;
      }
      if ( (v41 & 4) == 0 )
        goto LABEL_37;
      v28 = (void *)(a4.HeapTypeBits & 0xFFFFFFFC);
      v29 = InterlockedExchangeAdd(Addend: (volatile LONG *)((a4.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1);
      goto LABEL_35;
    }
LABEL_30:
    v32 = v8[8];
    v33 = *((int (__thiscall **)(ScaleformRenderTarget_vtbl *, int, GString *))v32->dtr_GRenderTarget + 10);
    a4.pData = (GString::DataDesc *)326;
    v34 = (GTextureImplNode *)v33(a1: v32, a2: 108, a3: &a4);
    if ( v34 != nullptr )
    {
      GString::GString(this: (GString *)&a2, a2: a3);
      v41 |= 8u;
      GFxLoadQueueEntry::GFxLoadQueueEntry(
        this: v34,
        level: Method,
        src: &a2,
        a4: a5,
        loadingVars: false,
        queitOpen: false);
      v23 = v35;
    }
    else
    {
      v23 = 0;
    }
    if ( (v41 & 8) != 0 )
    {
      v28 = (void *)(a2 & 0xFFFFFFFC);
      v29 = InterlockedExchangeAdd(Addend: (volatile LONG *)((a2 & 0xFFFFFFFC) + 4), Value: -1);
LABEL_35:
      if ( v29 == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v28);
    }
LABEL_37:
    if ( v23 != 0 )
    {
      GASValue::SetAsObject(this: (GASValue *)(v23 + 28), a2: (struct GASObject *)pmovieClipLoader.pObject);
      GFxMovieRoot::AddMovieLoadQueueEntry(this: v8, result: (IShaderAPI *)v23);
    }
    return;
  }
  v30 = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)v8[12];
  a2 = (__vc_attributes::event_receiverAttribute::type_e)&pMem;
  LOBYTE(a4.pData) = (unsigned int)GFxCharacter::GetVersion(this: v30) > 6;
  v31 = GFxMovieRoot::ParseLevelName(
          nptr: v6,
          ptail: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&a2,
          caseSensitive: (bool)a4.pData);
  Method = v31;
  if ( *(_BYTE *)a2 == 0 && v31 != -1 )
    goto LABEL_30;
}

//------------------------------------------------------------------------------
// Address: 0x100C9C40
// Name: public: void GFxMovieRoot::AddLoadQueueEntry(class GFxASCharacter __near *,char const __near *,enum GFxLoadQueueEntry::LoadMethod,class GASMovieClipLoader __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::AddLoadQueueEntry(
        int this,
        GString a2,
        char *a3,
        GRendererNode *a4,
        GPtr<IDirect3DVertexDeclaration9> pmovieClipLoader)
{
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *pData; // edi
  _TAPE_WMI_OPERATIONS *v7; // eax
  int v8; // ecx
  int (__thiscall *v9)(int, int, int *); // eax
  int v10; // esi
  char *v11; // eax
  char *v12; // eax
  char *v13; // edi
  GFxCharacterHandle *v14; // edi
  GRendererNode *v15; // edx
  void *v16; // edi
  int v17; // ecx
  int (__thiscall *v18)(int, int, GString *); // edx
  GTextureImplNode *v19; // esi
  int v20; // eax
  _TAPE_WMI_OPERATIONS *v21; // [esp+0h] [ebp-1Ch]
  int v22; // [esp+0h] [ebp-1Ch]
  int level; // [esp+10h] [ebp-Ch] BYREF
  GString v25; // [esp+14h] [ebp-8h] BYREF
  int v26; // [esp+18h] [ebp-4h]

  pData = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)a2.pData;
  v26 = 0;
  if ( a2.pData != nullptr )
  {
    v7 = GASObjectInterface::ToSprite(result: v21);
    if ( v7 != nullptr && (level = v7[37].Method) != -1 )
    {
      v17 = *(_DWORD *)(this + 32);
      v18 = *(int (__thiscall **)(int, int, GString *))(*(_DWORD *)v17 + 40);
      a2.pData = (GString::DataDesc *)326;
      v19 = (GTextureImplNode *)v18(a1: v17, a2: 108, a3: &a2);
      if ( v19 != nullptr )
      {
        GString::GString(this: &v25, a2: a3);
        v26 = 2;
        GFxLoadQueueEntry::GFxLoadQueueEntry(
          this: v19,
          (GTexture::ChangeHandler::EventType)level,
          src: &v25,
          a4,
          loadingVars: false,
          queitOpen: false);
        v10 = v20;
      }
      else
      {
        v10 = 0;
      }
      if ( (v26 & 2) != 0 )
        GString::~GString(this: &v25);
    }
    else
    {
      v8 = *(_DWORD *)(this + 32);
      v9 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v8 + 40);
      level = 326;
      v10 = v9(a1: v8, a2: 108, a3: &level);
      if ( v10 != 0 )
      {
        GString::GString(this: &a2, a2: a3);
        v11 = (char *)DWORD1(pData[6].m_pfnProxied);
        v26 = 1;
        if ( v11 != nullptr )
        {
          a3 = v11;
          v13 = v11;
        }
        else
        {
          GFxASCharacter::CreateCharacterHandle(this: pData);
          v13 = v12;
          a3 = v12;
        }
        GString::GString(this: (CUtlMemory<CImagePacker,int> *)(v10 + 12));
        *(_DWORD *)(v10 + 20) = 0;
        *(_BYTE *)(v10 + 28) = 0;
        *(_BYTE *)(v10 + 44) = 0;
        *(_BYTE *)(v10 + 64) = 0;
        *(_DWORD *)(v10 + 80) = 0;
        *(_BYTE *)(v10 + 84) = 0;
        *(_DWORD *)(v10 + 100) = 0;
        *(_DWORD *)(v10 + 4) = (a2.HeapTypeBits & 0xFFFFFFFC) == -8;
        if ( v13 != nullptr )
          ++*(_DWORD *)v13;
        v14 = *(GFxCharacterHandle **)(v10 + 20);
        if ( v14 != nullptr )
        {
          *v14 = (GFxCharacterHandle)((char *)*v14 - 1);
          if ( (int)*v14 <= 0 )
          {
            GFxCharacterHandle::~GFxCharacterHandle(this: v14);
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v14);
          }
        }
        v15 = a4;
        *(_DWORD *)(v10 + 20) = a3;
        *(_DWORD *)(v10 + 8) = v15;
        *(_DWORD *)(v10 + 16) = -1;
        *(_DWORD *)v10 = 0;
        GString::operator=(
          this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v10 + 12),
          src: (int)&a2,
          a3: v22);
        *(_BYTE *)(v10 + 24) = 0;
        *(_DWORD *)(v10 + 60) = -1;
        *(_BYTE *)(v10 + 104) = 0;
      }
      else
      {
        v10 = 0;
      }
      if ( (v26 & 1) != 0 )
      {
        v16 = (void *)(a2.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((a2.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v16);
      }
    }
    if ( v10 != 0 )
    {
      GASValue::SetAsObject(this: (GASValue *)(v10 + 28), a2: (struct GASObject *)pmovieClipLoader.pObject);
      GFxMovieRoot::AddMovieLoadQueueEntry((ScaleformRenderTarget_vtbl **)this, result: (IShaderAPI *)v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9E00
// Name: public: class GFxSprite __near * GFxMovieRoot::CreateEmptySprite(class GFxLoadStates __near *,int)
// Source: json
//------------------------------------------------------------------------------
struct GFxSprite *__thiscall GFxMovieRoot::CreateEmptySprite(
        VertexShaderHandle_t__ *this,
        int a2,
        GFxZlibSupportBase *result)
{
  int v4; // esi
  GMemoryHeap *v5; // ecx
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  int v7; // eax
  int v8; // eax
  struct GFxMovieDataDef *v9; // esi
  int v10; // ebx
  int v11; // ecx
  int (__thiscall *v12)(int, int, int *); // edx
  GFxMovieDefImpl *v13; // eax
  IShaderDevice *v14; // edx
  struct GFxStateBagImpl *v15; // ecx
  IShaderDevice *v16; // ebx
  int v18; // ecx
  int (__thiscall *v19)(int, int, int *); // eax
  GFxFontLib::FontResult *v20; // eax
  int v21; // [esp+Ch] [ebp-10h] BYREF
  int v22; // [esp+10h] [ebp-Ch]
  IShaderDevice *v23; // [esp+14h] [ebp-8h]
  int v24; // [esp+18h] [ebp-4h] BYREF

  GFxMovieDataDef::CreateMovieFileKey(
    result: (CMemberFuncProxy1<CTexture_MultipleRenderTarget *,void (__thiscall CTexture_MultipleRenderTarget::*)(char const *),char const *,CFuncMemPolicyNone> *)&v21,
    a2: (char *)&pMem,
    modifyTime: 0,
    ppreprocessParams: nullptr,
    a5: nullptr,
    a6: nullptr);
  v4 = *((_DWORD *)this + 8);
  v5 = (GMemoryHeap *)v4;
  if ( v4 == 0 )
    v5 = GMemory::pGlobalHeap;
  Alloc_2 = v5->Alloc_2;
  v24 = 2;
  v7 = (int)Alloc_2(this: v5, a2: 36u, a3: (const GAllocDebugInfo *)&v24);
  if ( v7 == 0 )
    goto LABEL_8;
  v8 = GFxMovieDataDef::GFxMovieDataDef(
         this: v7,
         a2: (struct GFxResourceKey *)&v21,
         a3: 0,
         a4: (int)&pMem,
         a5: v4,
         a6: 0,
         a7: 0);
  v9 = (struct GFxMovieDataDef *)v8;
  if ( v8 == 0 )
    goto LABEL_8;
  GFxMovieDataDef::LoadTaskData::InitEmptyMovieDef(this: *(GFxMovieDataDef::LoadTaskData **)(v8 + 32));
  v10 = a2;
  GFxLoadStates::SetRelativePathForDataDef(this: (GFxLoadStates *)a2, a2: v9);
  v11 = *((_DWORD *)this + 8);
  v12 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v11 + 40);
  a2 = 2;
  v13 = (GFxMovieDefImpl *)v12(a1: v11, a2: 32, a3: &a2);
  if ( v13 == nullptr
    || (v14 = *(IShaderDevice **)(v10 + 60),
        v15 = *(struct GFxStateBagImpl **)(*((_DWORD *)this + 60) + 20),
        v23 = *(IShaderDevice **)(v10 + 8),
        (v16 = (IShaderDevice *)GFxMovieDefImpl::GFxMovieDefImpl(
                                  this: v13,
                                  a2: (IShaderDevice *)v9,
                                  a3: v23,
                                  a4: v14,
                                  a5: 0,
                                  a6: v15,
                                  a7: *((ExprNode **)this + 8),
                                  a8: true,
                                  a9: 0)) == nullptr) )
  {
    GFxResource::Release(this: (IShaderDevice *)v9);
LABEL_8:
    if ( v21 != 0 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v21 + 8))(a1: v21, a2: v22);
    return nullptr;
  }
  v18 = *((_DWORD *)this + 8);
  v19 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v18 + 40);
  a2 = 322;
  v20 = (GFxFontLib::FontResult *)v19(a1: v18, a2: 488, a3: &a2);
  if ( v20 != nullptr )
    a2 = (int)GFxSprite::GFxSprite(this: v20);
  else
    a2 = 0;
  GFxSprite::SetLevel(result);
  GFxMovieRoot::SetLevelMovie(
    (GPtr<GFxTextKeyMap> *)this,
    a2: this,
    a3: (GFxTextKeyMap *)result,
    a4: (GRefCountNTSImpl *)a2);
  GFxResource::Release(this: v16);
  GFxResource::Release(this: (IShaderDevice *)v9);
  if ( v21 != 0 )
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v21 + 8))(a1: v21, a2: v22);
  return (struct GFxSprite *)a2;
}

//------------------------------------------------------------------------------
// Address: 0x100C9F80
// Name: public: void GFxMovieRoot::ActionQueueType::AddToFreeList(struct GFxMovieRoot::ActionEntry __near *)
// Source: json
//------------------------------------------------------------------------------
GPoint3<float> *__userpurge GFxMovieRoot::ActionQueueType::AddToFreeList@<eax>(
        GMatrix3D *this@<ecx>,
        GMatrix3D *result,
        const GPoint3<float> *pentry,
        bool a4)
{
  float v5; // ecx
  float v6; // ecx
  float v7; // ecx
  bool v8; // zf
  float v9; // ecx
  GPoint3<float> *v10; // eax
  const float *v11; // [esp+0h] [ebp-Ch]
  int v12; // [esp+4h] [ebp-8h]

  result->M_[0][1] = 0.0;
  v5 = result->M_[0][3];
  if ( v5 != 0.0 )
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)LODWORD(v5));
  result->M_[0][3] = 0.0;
  v6 = result->M_[0][2];
  if ( v6 != 0.0 )
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)LODWORD(v6));
  result->M_[0][2] = 0.0;
  if ( (LOBYTE(result->M_[2][2]) & 2) == 0 )
  {
    v7 = result->M_[2][0];
    if ( v7 != 0.0 )
      GRefCountBaseGC<323>::Release(a1: LODWORD(v7));
  }
  v8 = (LOBYTE(result->M_[2][2]) & 1) == 0;
  result->M_[2][0] = 0.0;
  if ( v8 )
  {
    v9 = result->M_[2][1];
    if ( v9 != 0.0 )
      GRefCountBaseGC<323>::Release(a1: LODWORD(v9));
  }
  result->M_[2][1] = 0.0;
  GArrayDataBase<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: (GPtr<IDirect3DPixelShader9> *)result->M_[3],
    pheapAddr: (ButtonCode_t)result->M_[3],
    newSize: 0);
  if ( *((_DWORD *)this + 21) >= 0x32u )
  {
    GFxMovieRoot::ActionEntry::~ActionEntry(this: result, a2: v11, a3: v12);
    return ((GPoint3<float> *(__thiscall *)(GMemoryHeap *, GMatrix3D *))GMemory::pGlobalHeap->Free)(
             a1: GMemory::pGlobalHeap,
             a2: result);
  }
  else
  {
    v10 = *((GPoint3<float> **)this + 19);
    LODWORD(result->M_[0][0]) = v10;
    ++*((_DWORD *)this + 21);
    *((_DWORD *)this + 19) = result;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x100CA020
// Name: public: struct GFxMovieRoot::ActionEntry const __near * GFxMovieRoot::ActionQueueIterator::getNext(void)
// Source: json
//------------------------------------------------------------------------------
const struct GFxMovieRoot::ActionEntry *__thiscall GFxMovieRoot::ActionQueueIterator::getNext(
        GFxMovieRoot::ActionQueueIterator *this)
{
  int v2; // ecx
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  int v7; // eax
  const GPoint3<float> *v9; // [esp+0h] [ebp-8h]
  bool v10; // [esp+4h] [ebp-4h]

  v2 = *((_DWORD *)this + 1);
  if ( *(_DWORD *)(v2 + 72) != *(_DWORD *)this )
  {
    *((_DWORD *)this + 3) = 0;
    *(_DWORD *)this = *(_DWORD *)(v2 + 72);
  }
  v3 = *(_DWORD **)(v2 + 12 * *((_DWORD *)this + 3));
  if ( v3 != nullptr )
  {
LABEL_8:
    if ( v3 == *(_DWORD **)(v2 + 12 * *((_DWORD *)this + 3) + 4) )
      *(_DWORD *)(v2 + 12 * *((_DWORD *)this + 3) + 4) = *v3;
    *(_DWORD *)(*((_DWORD *)this + 1) + 12 * *((_DWORD *)this + 3)) = *v3;
    *v3 = 0;
  }
  else
  {
    while ( 1 )
    {
      v4 = ++*((_DWORD *)this + 3);
      if ( v4 >= 6 )
        break;
      v3 = *(_DWORD **)(v2 + 12 * v4);
      if ( v3 != nullptr )
        goto LABEL_8;
    }
  }
  v5 = *((_DWORD *)this + 1);
  v6 = *(_DWORD *)(v5 + 12 * *((_DWORD *)this + 3)) == 0;
  v7 = v5 + 12 * *((_DWORD *)this + 3);
  if ( v6 )
  {
    *(_DWORD *)(v7 + 4) = 0;
    *(_DWORD *)(*((_DWORD *)this + 1) + 12 * *((_DWORD *)this + 3) + 8) = 0;
  }
  if ( *((_DWORD *)this + 2) != 0 )
    GFxMovieRoot::ActionQueueType::AddToFreeList(
      this: *((GMatrix3D **)this + 1),
      result: *((GMatrix3D **)this + 2),
      pentry: v9,
      a4: v10);
  *((_DWORD *)this + 2) = v3;
  return (const struct GFxMovieRoot::ActionEntry *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x100CA0E0
// Name: public: struct GFxMovieRoot::ActionEntry const __near * GFxMovieRoot::ActionQueueSessionIterator::getNext(void)
// Source: json
//------------------------------------------------------------------------------
const struct GFxMovieRoot::ActionEntry *__thiscall GFxMovieRoot::ActionQueueSessionIterator::getNext(
        GFxMovieRoot::ActionQueueSessionIterator *this)
{
  int v2; // edx
  _DWORD *v3; // esi
  int v4; // eax
  _DWORD *v5; // ecx
  int v6; // eax
  _DWORD *v7; // eax
  const GPoint3<float> *v9; // [esp+0h] [ebp-8h]
  bool v10; // [esp+4h] [ebp-4h]

  v2 = *((_DWORD *)this + 1);
  if ( *(GFxMovieRoot::ActionQueueSessionIterator *)(v2 + 72) != *this )
  {
    *((_DWORD *)this + 3) = 0;
    *this = *(GFxMovieRoot::ActionQueueSessionIterator *)(v2 + 72);
  }
  v3 = nullptr;
  if ( *((int *)this + 3) < 6 )
  {
    while ( 1 )
    {
      v4 = *((_DWORD *)this + 3);
      v3 = *(_DWORD **)(v2 + 12 * v4);
      v5 = nullptr;
      if ( v3 != nullptr )
        break;
LABEL_7:
      v6 = v4 + 1;
      *((_DWORD *)this + 3) = v6;
      if ( v6 >= 6 )
        goto LABEL_19;
    }
    while ( v3[15] != *((_DWORD *)this + 4) )
    {
      v5 = v3;
      v3 = (_DWORD *)*v3;
      if ( v3 == nullptr )
        goto LABEL_7;
    }
    if ( v5 != nullptr )
      *v5 = *v3;
    else
      *(_DWORD *)(v2 + 12 * v4) = *v3;
    if ( *v3 == 0 )
      *(_DWORD *)(*((_DWORD *)this + 1) + 12 * *((_DWORD *)this + 3) + 8) = v5;
    v7 = (_DWORD *)(*((_DWORD *)this + 1) + 12 * *((_DWORD *)this + 3) + 4);
    if ( v3 == (_DWORD *)*v7 )
    {
      if ( *v3 != 0 )
        *v7 = *v3;
      else
        *v7 = v5;
    }
    *v3 = 0;
  }
LABEL_19:
  if ( *((_DWORD *)this + 2) != 0 )
    GFxMovieRoot::ActionQueueType::AddToFreeList(
      this: *((GMatrix3D **)this + 1),
      result: *((GMatrix3D **)this + 2),
      pentry: v9,
      a4: v10);
  *((_DWORD *)this + 2) = v3;
  return (const struct GFxMovieRoot::ActionEntry *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x100CA190
// Name: public: void GFxMovieRoot::DoActions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::DoActions(ScaleformRenderer *this)
{
  GFxAmpViewStats *v2; // edi
  float v3; // ecx
  const struct GFxMovieRoot::ActionEntry *i; // eax
  float v5; // ecx
  _BYTE *v6; // ecx
  const GPoint3<float> *v7; // [esp+0h] [ebp-34h]
  float *v8; // [esp+4h] [ebp-30h]
  int v9; // [esp+24h] [ebp-10h] BYREF
  GMatrix3D *v10; // [esp+28h] [ebp-Ch]
  GPoint3<float> *result; // [esp+2Ch] [ebp-8h]
  int v12; // [esp+30h] [ebp-4h]

  v2 = *((GFxAmpViewStats **)this + 2577);
  if ( v2 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v2, swdHandle: 1u, a3: 0xAu);
    GTimer::GetRawTicks(li: v3, a2: *(float *)&v7, a3: v8);
  }
  v10 = (GMatrix3D *)((char *)this + 9224);
  v9 = 0;
  v12 = 0;
  result = nullptr;
  for ( i = GFxMovieRoot::ActionQueueIterator::getNext(this: (GFxMovieRoot::ActionQueueIterator *)&v9);
        i != nullptr;
        i = GFxMovieRoot::ActionQueueIterator::getNext(this: (GFxMovieRoot::ActionQueueIterator *)&v9) )
  {
    v6 = *((_BYTE **)i + 2);
    if ( v6 != nullptr && (v6[118] & 0x10) == 0 )
    {
      switch ( *((_DWORD *)i + 1) )
      {
        case 1:
          (*(void (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)v6 + 332))(a1: v6, a2: *((_DWORD *)i + 3));
          break;
        case 2:
          (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)v6 + 336))(a1: v6, a2: (int)i + 16);
          break;
        case 3:
          (*(void (__thiscall **)(_BYTE *, int, int))(*(_DWORD *)v6 + 340))(a1: v6, a2: (int)i + 32, a3: (int)i + 48);
          break;
        case 4:
          (*(void (__thiscall **)(_BYTE *, _DWORD, int))(*(_DWORD *)v6 + 344))(
            a1: v6,
            a2: *((_DWORD *)i + 11),
            a3: (int)i + 48);
          break;
        default:
          continue;
      }
    }
  }
  if ( result != nullptr )
    GFxMovieRoot::ActionQueueType::AddToFreeList(this: v10, (GMatrix3D *)result, pentry: v7, a4: (bool)v8);
  if ( v2 != nullptr )
  {
    GTimer::GetRawTicks(li: v5, a2: *(float *)&v7, a3: v8);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA2A0
// Name: public: virtual void GFxMovieRoot::SetViewport(class GViewport const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::SetViewport(int this, IDirect3DResource9 *result)
{
  int v3; // edx
  int v4; // eax
  int v5; // ecx
  double v6; // st7
  int v7; // eax
  _DWORD *i; // ecx
  const GPoint3<float> *inserted; // edi
  unsigned int v10; // eax
  _DWORD *v11; // ecx
  float v12; // esi
  GRefCountNTSImpl *z_low; // ecx
  GRefCountNTSImpl *x_low; // ecx
  float prevVisRect; // [esp+4h] [ebp-28h]
  float prevVisRect_4; // [esp+8h] [ebp-24h]
  float prevVisRect_8; // [esp+Ch] [ebp-20h]
  float v18; // [esp+10h] [ebp-1Ch]
  float prevScale; // [esp+14h] [ebp-18h]
  int prevTop; // [esp+18h] [ebp-14h]
  int prevLeft; // [esp+1Ch] [ebp-10h]
  float prevRatio; // [esp+20h] [ebp-Ch]
  int prevHeight; // [esp+24h] [ebp-8h]
  int prevWidth; // [esp+28h] [ebp-4h]

  prevScale = *(float *)(this + 104);
  v3 = *(_DWORD *)(this + 80);
  prevRatio = *(float *)(this + 108);
  prevTop = *(_DWORD *)(this + 76);
  prevLeft = *(_DWORD *)(this + 72);
  v4 = *(_DWORD *)(this + 84);
  *(_DWORD *)(this + 9332) |= 1u;
  qmemcpy((void *)(this + 64), result, 0x34u);
  prevVisRect = *(float *)(this + 144);
  prevVisRect_4 = *(float *)(this + 148);
  prevVisRect_8 = *(float *)(this + 152);
  v18 = *(float *)(this + 156);
  prevWidth = v3;
  prevHeight = v4;
  GFxMovieRoot::UpdateViewport((ScaleformRenderer *)this);
  if ( *(float *)(this + 144) != prevVisRect
    || *(float *)(this + 152) != prevVisRect_8
    || *(float *)(this + 148) != prevVisRect_4
    || *(float *)(this + 156) != v18
    || (v5 = *(_DWORD *)(this + 136), v6 = prevRatio, v5 == 0)
    && (prevWidth != *(_DWORD *)(this + 80)
     || prevHeight != *(_DWORD *)(this + 84)
     || prevLeft != *(_DWORD *)(this + 72)
     || prevTop != *(_DWORD *)(this + 76)
     || *(float *)(this + 104) != prevScale
     || *(float *)(this + 108) != v6)
    || v5 != 2
    && (prevWidth != *(_DWORD *)(this + 80) || prevHeight != *(_DWORD *)(this + 84) || *(float *)(this + 108) != v6) )
  {
    v7 = 0;
    if ( *(_DWORD *)(this + 40) != 0 )
    {
      for ( i = *(_DWORD **)(this + 36); *i != 0; i += 2 )
      {
        if ( (unsigned int)++v7 >= *(_DWORD *)(this + 40) )
          return;
      }
      if ( *(_DWORD *)(*(_DWORD *)(this + 36) + 8 * v7 + 4) != 0 )
      {
        inserted = GFxMovieRoot::ActionQueueType::InsertEntry(this: this + 9224, result: (const GPoint3<float> *)4);
        if ( inserted != nullptr )
        {
          v10 = 0;
          if ( *(_DWORD *)(this + 40) != 0 )
          {
            v11 = *(_DWORD **)(this + 36);
            while ( *v11 != 0 )
            {
              ++v10;
              v11 += 2;
              if ( v10 >= *(_DWORD *)(this + 40) )
                goto LABEL_27;
            }
            v12 = *(float *)(*(_DWORD *)(this + 36) + 8 * v10 + 4);
          }
          else
          {
LABEL_27:
            v12 = 0.0;
          }
          LODWORD(inserted->y) = 4;
          if ( v12 != 0.0 )
            ++*(_DWORD *)(LODWORD(v12) + 4);
          z_low = (GRefCountNTSImpl *)LODWORD(inserted->z);
          if ( z_low != nullptr )
            GRefCountNTSImpl::Release(this: z_low);
          inserted->z = v12;
          x_low = (GRefCountNTSImpl *)LODWORD(inserted[1].x);
          if ( x_low != nullptr )
            GRefCountNTSImpl::Release(this: x_low);
          inserted[1].x = 0.0;
          LODWORD(inserted[3].z) = GASStageCtorFunction::NotifyOnResize;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA4A0
// Name: public: void GFxMovieRoot::ProcessKeyboard(class GASStringContext __near *,struct GFxInputEventsQueue::QueueEntry const __near *,struct GFxMovieRoot::ProcessFocusKeyInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::ProcessKeyboard(
        ISteamRemoteStorage *this,
        struct GASStringContext *psc,
        int (__stdcall *event)(HINSTANCE__ *, char *, int),
        GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>::SysAllocContainer *a4)
{
  GFxAmpViewStats *v5; // ecx
  float v6; // ecx
  float v7; // ecx
  char *v8; // esi
  unsigned __int8 v9; // al
  const CMaterialDict::MissingMaterial_t *v10; // edi
  char v11; // dl
  char v12; // al
  char v13; // cl
  int v14; // ecx
  unsigned int v15; // eax
  GFxKeyboardState *v16; // ecx
  int v17; // edi
  _DWORD *v18; // eax
  GRefCountNTSImpl *v19; // edi
  float v21; // [esp+0h] [ebp-38h]
  float *v22; // [esp+4h] [ebp-34h]
  GFxAmpViewStats *v23; // [esp+14h] [ebp-24h]
  _COMMTIMEOUTS *eventId; // [esp+24h] [ebp-14h] BYREF
  unsigned int v25; // [esp+28h] [ebp-10h]
  __int16 v26; // [esp+2Ch] [ebp-Ch]
  char v27; // [esp+2Eh] [ebp-Ah]
  char v28; // [esp+2Fh] [ebp-9h]
  char v29; // [esp+30h] [ebp-8h]
  char i; // [esp+31h] [ebp-7h]
  int keyMask; // [esp+34h] [ebp-4h] BYREF
  enum GFxEvent::EventType eventa; // [esp+44h] [ebp+Ch]

  v5 = *((GFxAmpViewStats **)this + 2577);
  v23 = v5;
  if ( v5 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v5, swdHandle: 1u, a3: 0xCu);
    GTimer::GetRawTicks(li: v6, a2: v21, a3: v22);
  }
  LODWORD(v7) = *((unsigned __int16 *)event + 4);
  v8 = (char *)event + 4;
  keyMask = 0;
  if ( LOWORD(v7) != 0 )
  {
    if ( *((_BYTE *)event + 13) != 0 )
    {
      v9 = 64;
      eventa = KeyDown;
    }
    else
    {
      v9 = 0x80;
      eventa = KeyUp;
    }
    v10 = *((const CMaterialDict::MissingMaterial_t **)this + 10);
    v25 = *(_DWORD *)v8;
    v11 = v8[7];
    eventId = (_COMMTIMEOUTS *)v9;
    v12 = v8[6];
    v26 = LOWORD(v7);
    v13 = v8[8];
    v27 = v12;
    v29 = 0;
    v28 = v13;
    for ( i = v11 | 0x80; (int)v10 > 0; v10 = (const CMaterialDict::MissingMaterial_t *)((char *)v10 - 1) )
    {
      v14 = *(_DWORD *)(*((_DWORD *)this + 9) + 8 * (_DWORD)v10 - 4);
      (*(void (__thiscall **)(int, _COMMTIMEOUTS **, int *))(*(_DWORD *)v14 + 164))(a1: v14, a2: &eventId, a3: &keyMask);
    }
    v15 = (unsigned __int8)v8[8];
    if ( v15 >= 4 )
      v16 = nullptr;
    else
      v16 = (GFxKeyboardState *)(this + 415 * v15 + 629);
    GFxKeyboardState::NotifyListeners(
      this: v16,
      code: psc,
      a3: *((_WORD *)v8 + 2),
      ascii: v8[6],
      wcharCode: *(_DWORD *)v8,
      a6: eventa);
    if ( *((_DWORD *)this + 2333) >> 30 != 1 )
      GFxMovieRoot::ProcessFocusKey(
        a1: this,
        a2: v10,
        result: (ISteamRemoteStorage *)eventa,
        a4: (struct GFxInputEventsQueue::QueueEntry::KeyEntry *)v8,
        pfocusInfo: a4);
  }
  else if ( *(_DWORD *)v8 != 0 )
  {
    v17 = 52 * (*((unsigned __int8 *)this + *((unsigned __int8 *)event + 12) + 10228) + 181);
    v18 = *(ISteamRemoteStorage_vtbl **)((char *)&this->__vftable + v17);
    if ( v18 != nullptr )
    {
      if ( v18[1] != 0 )
      {
        v19 = (GRefCountNTSImpl *)v18[1];
        if ( v19 != nullptr )
        {
          ++v19->RefCount;
          ++v19->RefCount;
          GRefCountNTSImpl::Release(this: v19);
          ((void (__thiscall *)(GRefCountNTSImpl *, _DWORD, _DWORD))v19->__vftable[38].dtr_GRefCountImplCore)(
            a1: v19,
            a2: *((_DWORD *)event + 1),
            a3: *((unsigned __int8 *)event + 12));
          GRefCountNTSImpl::Release(this: v19);
        }
      }
      else
      {
        if ( (*v18)-- == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v18);
        *(ISteamRemoteStorage_vtbl **)((char *)&this->__vftable + v17) = nullptr;
      }
    }
  }
  if ( v23 != nullptr )
  {
    GTimer::GetRawTicks(li: v7, a2: v21, a3: v22);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA660
// Name: public: void GFxMovieRoot::ShutdownTimers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::ShutdownTimers(ScaleformRenderer *this)
{
  unsigned int v2; // eax
  unsigned int v3; // edi
  int v4; // ecx
  void *v5; // esi
  void **v6; // esi
  int v7; // [esp+0h] [ebp-10h]
  int v8; // [esp+4h] [ebp-Ch]
  unsigned int na; // [esp+Ch] [ebp-4h]

  v2 = *((_DWORD *)this + 2345);
  v3 = 0;
  for ( na = v2; v3 < v2; ++v3 )
  {
    v4 = *((_DWORD *)this + 2344);
    v5 = *(void **)(v4 + 4 * v3);
    if ( v5 != nullptr )
    {
      GASIntervalTimer::~GASIntervalTimer(this: *(GASIntervalTimer **)(v4 + 4 * v3));
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
      v2 = na;
    }
  }
  v6 = (void **)((char *)this + 9376);
  if ( *((_DWORD *)this + 2345) == 0 )
  {
    if ( *((_DWORD *)this + 2346) == 0 )
    {
      GArrayDataBase<GPtr<GFxASCharacter>,GAllocatorLH<GPtr<GFxASCharacter>,326>,GArrayDefaultPolicy>::Reserve(
        this: (ScaleformUIImpl *)((char *)this + 9376),
        pheapAddr: (char *)this + 9376,
        newCapacity: 0,
        a4: v7,
        a5: v8);
      *((_DWORD *)this + 2345) = 0;
      return;
    }
    goto LABEL_12;
  }
  if ( (*((_DWORD *)this + 2346) & 0xFFFFFFFE) == 0 )
  {
LABEL_12:
    *((_DWORD *)this + 2345) = 0;
    return;
  }
  if ( *v6 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v6);
    *v6 = nullptr;
  }
  *((_DWORD *)this + 2346) = 0;
  *((_DWORD *)this + 2345) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100CA710
// Name: public: void GFxMovieRoot::RemoveTopmostLevelCharacter(class GFxCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::RemoveTopmostLevelCharacter(
        GFxMovieRoot *this@<ecx>,
        int a2@<edi>,
        struct GFxCharacter *a3)
{
  unsigned int v3; // edx
  unsigned int v4; // esi
  struct GFxCharacter **v5; // eax
  ScaleformUIImpl *v6; // edi
  GRefCountNTSImpl *v7; // eax
  int v9; // [esp+0h] [ebp-4h]

  v3 = *((_DWORD *)this + 2335);
  v4 = 0;
  if ( v3 != 0 )
  {
    v5 = *((struct GFxCharacter ***)this + 2334);
    v6 = (ScaleformUIImpl *)((char *)this + 9336);
    while ( *v5 != a3 )
    {
      ++v4;
      ++v5;
      if ( v4 >= v3 )
        return;
    }
    if ( *((_DWORD *)this + 2335) == 1 )
    {
      GArrayDataBase<GPtr<GFxSprite>,GAllocatorLH<GPtr<GFxSprite>,326>,GArrayDefaultPolicy>::ResizeNoConstruct(
        this: v6,
        pheapAddr: v6,
        newSize: 0,
        a4: a2,
        a5: v9);
    }
    else
    {
      v7 = *((GRefCountNTSImpl **)&v6->Connect + v4);
      if ( v7 != nullptr )
        GRefCountNTSImpl::Release(this: v7);
      memmove(
        dst: (unsigned __int8 *)&v6->Connect + 4 * v4,
        src: (unsigned __int8 *)&v6->Disconnect + 4 * v4,
        count: 4 * (int)&v6->m_pSystem[-v4] - 4);
      --v6->m_pSystem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA7A0
// Name: public: void GFxMovieRoot::RemoveFromPreDisplayList(class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::RemoveFromPreDisplayList(int this, int a2)
{
  unsigned int v3; // edx
  int v4; // eax
  _DWORD *i; // ecx

  v3 = *(_DWORD *)(this + 9324);
  v4 = 0;
  if ( v3 != 0 )
  {
    for ( i = *(_DWORD **)(this + 9320); *i != a2; ++i )
    {
      if ( ++v4 >= v3 )
        return;
    }
    if ( v3 == 1 )
    {
      if ( (*(_DWORD *)(this + 9328) & 0xFFFFFFFE) != 0 )
      {
        if ( *(_DWORD *)(this + 9320) != 0 )
        {
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(this + 9320));
          *(_DWORD *)(this + 9320) = 0;
        }
        *(_DWORD *)(this + 9328) = 0;
      }
      *(_DWORD *)(this + 9324) = 0;
    }
    else
    {
      memmove(
        dst: (unsigned __int8 *)(*(_DWORD *)(this + 9320) + 4 * v4),
        src: (unsigned __int8 *)(*(_DWORD *)(this + 9320) + 4 * v4 + 4),
        count: 4 * (v3 - v4) - 4);
      --*(_DWORD *)(this + 9324);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA850
// Name: public: virtual void GFxPlaceObject::Execute(class GFxSprite __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPlaceObject::Execute(
        GFxPlaceObject *this,
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *a2)
{
  int v3; // edx
  void (__thiscall *v4)(GFxPlaceObject *, _IMAGE_SYMBOL_EX *); // edx
  int v5; // eax
  const CMaterialDict::MissingMaterial_t *v6; // [esp+0h] [ebp-70h]
  _IMAGE_SYMBOL_EX name; // [esp+Ch] [ebp-64h] BYREF
  float v8; // [esp+50h] [ebp-20h]
  int v9; // [esp+54h] [ebp-1Ch]
  int v10; // [esp+58h] [ebp-18h]
  int v11; // [esp+5Ch] [ebp-14h]

  memset(&name, 0, 12);
  GRenderer::Cxform::Cxform();
  GMatrix2D::SetIdentity(result: v6);
  v3 = *(_DWORD *)this;
  v8 = 0.0;
  v4 = *(void (__thiscall **)(GFxPlaceObject *, _IMAGE_SYMBOL_EX *))(v3 + 32);
  v11 = 0;
  v10 = 0x40000;
  v9 = 0;
  v4(a1: this, a2: &name);
  v5 = (*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(a2->m_pfnProxied) + 112))(a1: a2);
  GFxSprite::AddDisplayObject(
    this: a2,
    &name,
    a3: *(_DWORD *)(v5 + 120) + 8,
    a4: 0,
    a5: 0,
    createFrame: 0xFFFFFFFF,
    addFlags: 4u,
    rh: nullptr,
    a9: 0);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)name.N.Name.Short);
}

//------------------------------------------------------------------------------
// Address: 0x100CA8F0
// Name: public: virtual GFxPlaceObject2::~GFxPlaceObject2(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPlaceObject2::~GFxPlaceObject2(GFxPlaceObject2 *this)
{
  GFxPlaceObject2 *v1; // esi
  int v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // edi
  _DWORD *v5; // esi
  IShaderAPI *v6; // ecx
  unsigned int v8; // [esp+8h] [ebp-4h]

  v1 = this;
  *(_DWORD *)this = &GFxPlaceObject2::`vftable';
  if ( *((char *)this + 4) >= 0 )
  {
    *(_DWORD *)this = &GASExecuteTag::`vftable';
  }
  else
  {
    v2 = *(_DWORD *)((char *)this + 5);
    if ( v2 != 0 )
    {
      v3 = *(_DWORD *)(v2 + 4);
      v4 = 0;
      v8 = v3;
      if ( v3 != 0 )
      {
        do
        {
          v5 = *(_DWORD **)(*(_DWORD *)v2 + 4 * v4);
          if ( v5 != nullptr )
          {
            v6 = (IShaderAPI *)v5[4];
            if ( v6 != nullptr )
              GRefCountImpl::Release(this: v6);
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
            v3 = v8;
          }
          ++v4;
        }
        while ( v4 < v3 );
        v1 = this;
      }
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)v2);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
      *(_DWORD *)v1 = &GASExecuteTag::`vftable';
    }
    else
    {
      *(_DWORD *)this = &GASExecuteTag::`vftable';
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA990
// Name: public: virtual void GFxPlaceObject2::Trace(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPlaceObject2::Trace(CUtlDict<ITextureInternal *,unsigned short> *this, const char *prenderer)
{
  CMatNullRenderContext::OverrideColorWriteEnable(this, (unsigned __int16)prenderer, ptext: (HBITMAP__)6);
}

//------------------------------------------------------------------------------
// Address: 0x100CA9B0
// Name: public: virtual void GFxPlaceObject2::Unpack(struct GFxPlaceObjectBase::UnpackedData __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100CA9D0
// Name: protected: void GFxPlaceObject2::ExecuteBase(class GFxSprite __near *,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPlaceObject2::ExecuteBase(
        CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),CFuncMemPolicyNone> *this,
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *a2,
        int version)
{
  int v4; // eax
  int v5; // esi
  int v6; // eax
  char v7; // bl
  bool v8; // zf
  int v9; // eax
  int v10; // esi
  char v11; // bl
  int v12; // eax
  __int128 v13; // [esp-4h] [ebp-80h]
  int v14; // [esp+10h] [ebp-6Ch] BYREF
  int v15; // [esp+14h] [ebp-68h]
  _IMAGE_SYMBOL_EX name; // [esp+18h] [ebp-64h] BYREF
  float v17; // [esp+5Ch] [ebp-20h]
  int v18; // [esp+60h] [ebp-1Ch]
  int v19; // [esp+64h] [ebp-18h]
  int v20; // [esp+68h] [ebp-14h]
  int v21; // [esp+6Ch] [ebp-10h]
  int v22; // [esp+70h] [ebp-Ch]
  int v23; // [esp+74h] [ebp-8h]

  v15 = 0;
  memset(&name, 0, 12);
  GRenderer::Cxform::Cxform();
  GMatrix2D::SetIdentity(result: (const CMaterialDict::MissingMaterial_t *)DWORD1(v13));
  v17 = 0.0;
  LODWORD(v13) = version;
  v19 = 0x40000;
  v18 = 0;
  v20 = 0;
  GFxPlaceObject2::UnpackBase(this, data: (CMatQueuedRenderContext *)&name, version: v13);
  if ( v23 != 0 )
  {
    if ( v23 == 1 )
    {
      GFxSprite::MoveDisplayObject(this: (GFxSprite *)a2, a2: (const struct GFxCharPosInfo *)&name);
    }
    else if ( v23 == 2 )
    {
      v4 = (*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(a2->m_pfnProxied) + 112))(a1: a2);
      if ( v22 != 0 )
      {
        v7 = 8;
        GASStringManager::CreateStringNode(this: *(const char **)(*(_DWORD *)(v4 + 120) + 636));
        ++*(_DWORD *)(v6 + 8);
        v14 = v6;
        v5 = v6;
      }
      else
      {
        v5 = *(_DWORD *)(*(_DWORD *)(v4 + 120) + 8);
        ++*(_DWORD *)(v5 + 8);
        v14 = v5;
        v6 = v5;
        v7 = 4;
      }
      v15 = v14;
      ++*(_DWORD *)(v14 + 8);
      if ( (v7 & 8) != 0 )
      {
        v7 &= ~8u;
        v8 = (*(_DWORD *)(v6 + 8))-- == 1;
        if ( v8 )
          GASStringNode::ReleaseNode();
      }
      if ( (v7 & 4) != 0 )
      {
        v8 = (*(_DWORD *)(v5 + 8))-- == 1;
        if ( v8 )
          GASStringNode::ReleaseNode();
      }
      GFxSprite::ReplaceDisplayObject(this: (GMemoryFile *)a2);
      v8 = (*(_DWORD *)(v15 + 8))-- == 1;
      if ( v8 )
LABEL_26:
        GASStringNode::ReleaseNode();
    }
  }
  else
  {
    v9 = (*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(a2->m_pfnProxied) + 112))(a1: a2);
    if ( v22 != 0 )
    {
      v11 = 2;
      GASStringManager::CreateStringNode(this: *(const char **)(*(_DWORD *)(v9 + 120) + 636));
      ++*(_DWORD *)(v12 + 8);
      v15 = v12;
      v10 = v12;
    }
    else
    {
      v10 = *(_DWORD *)(*(_DWORD *)(v9 + 120) + 8);
      v11 = 1;
      ++*(_DWORD *)(v10 + 8);
      v15 = v10;
      v12 = v10;
    }
    v14 = v15;
    ++*(_DWORD *)(v15 + 8);
    if ( (v11 & 2) != 0 )
    {
      v11 &= ~2u;
      v8 = (*(_DWORD *)(v12 + 8))-- == 1;
      if ( v8 )
        GASStringNode::ReleaseNode();
    }
    if ( (v11 & 1) != 0 )
    {
      v8 = (*(_DWORD *)(v10 + 8))-- == 1;
      if ( v8 )
        GASStringNode::ReleaseNode();
    }
    GFxSprite::AddDisplayObject(
      this: a2,
      &name,
      a3: (int)&v14,
      a4: v21,
      a5: 0,
      createFrame: 0xFFFFFFFF,
      addFlags: 4u,
      rh: nullptr,
      a9: 0);
    v8 = (*(_DWORD *)(v14 + 8))-- == 1;
    if ( v8 )
      goto LABEL_26;
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)name.N.Name.Short);
}

//------------------------------------------------------------------------------
// Address: 0x100CAC40
// Name: public: virtual void GFxPlaceObject2::Execute(class GFxSprite __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPlaceObject2::Execute(
        CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),CFuncMemPolicyNone> *this,
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *a2)
{
  GFxPlaceObject2::ExecuteBase(this, a2, version: 6);
}

//------------------------------------------------------------------------------
// Address: 0x100CAC90
// Name: public: bool GFxMovieRoot::ReleaseLevelMovie(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::ReleaseLevelMovie(
        int a1@<ecx>,
        unsigned int *level,
        unsigned int *i,
        unsigned __int8 *a4)
{
  _DWORD *v5; // esi
  GFxFontLib *v6; // ebx
  int v7; // ebx
  unsigned int v8; // ecx
  unsigned int **v9; // edx
  _DWORD *v10; // esi
  unsigned int **j; // eax
  int v12; // ebx
  unsigned int *v13; // eax
  unsigned int v14; // [esp+0h] [ebp-10h]
  GFxFontLib *v15; // [esp+Ch] [ebp-4h]
  unsigned int ia; // [esp+18h] [ebp+8h]

  if ( level != nullptr )
  {
    v8 = 0;
    if ( *(_DWORD *)(a1 + 40) != 0 )
    {
      v9 = *(unsigned int ***)(a1 + 36);
      v10 = (_DWORD *)(a1 + 36);
      for ( j = v9; *j != level; j += 2 )
      {
        if ( ++v8 >= *(_DWORD *)(a1 + 40) )
          return;
      }
      v12 = 8 * v8;
      v13 = v9[2 * v8 + 1];
      ia = v8;
      if ( v13 != nullptr )
        ++v13[1];
      v15 = (GFxFontLib *)v9[v12 / 4u + 1];
      ((void (*)(void))v15->__vftable[17].dtr_GRefCountImplCore)();
      GFxMovieRoot::DoActions(this: (ScaleformRenderer *)a1);
      GFxSprite::ForceShutdown(this: v15, a2: v14);
      if ( *(_DWORD *)(a1 + 40) == 1 )
      {
        GArrayDataBase<GFxMovieRoot::LevelInfo,GAllocatorLH<GFxMovieRoot::LevelInfo,326>,GArrayDefaultPolicy>::ResizeNoConstruct(
          this: a1 + 36,
          result: (GFxTestStream *)(a1 + 36),
          newSize: 0);
      }
      else
      {
        if ( *(_DWORD *)(*v10 + v12 + 4) != 0 )
          GRefCountNTSImpl::Release(this: *(GRefCountNTSImpl **)(*v10 + v12 + 4));
        memmove(
          dst: (unsigned __int8 *)(v12 + *v10),
          src: (unsigned __int8 *)(v12 + *v10 + 8),
          count: 8 * (*(_DWORD *)(a1 + 40) - ia) - 8);
        --*(_DWORD *)(a1 + 40);
      }
      *(_DWORD *)(a1 + 9332) |= 0x100u;
      GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v15);
    }
  }
  else
  {
    *(_DWORD *)(a1 + 9188) = 0;
    GFxMovieRoot::ShutdownTimers(this: (ScaleformRenderer *)a1);
    if ( *(_DWORD *)(a1 + 40) != 0 )
    {
      v5 = (_DWORD *)(a1 + 36);
      do
      {
        v6 = *(GFxFontLib **)(*v5 + 8 * *(_DWORD *)(a1 + 40) - 4);
        v6->__vftable[17].dtr_GRefCountImplCore(this: v6);
        GFxMovieRoot::DoActions(this: (ScaleformRenderer *)a1);
        GFxSprite::ForceShutdown(this: v6, a2: v14);
        v7 = *(_DWORD *)(a1 + 40) - 1;
        if ( *(_DWORD *)(a1 + 40) == 1 )
        {
          GArrayDataBase<GFxMovieRoot::LevelInfo,GAllocatorLH<GFxMovieRoot::LevelInfo,326>,GArrayDefaultPolicy>::ResizeNoConstruct(
            this: a1 + 36,
            result: (GFxTestStream *)(a1 + 36),
            newSize: 0);
        }
        else
        {
          if ( *(_DWORD *)(*v5 + 8 * v7 + 4) != 0 )
            GRefCountNTSImpl::Release(this: *(GRefCountNTSImpl **)(*v5 + 8 * v7 + 4));
          memmove(
            dst: (unsigned __int8 *)(*v5 + 8 * v7),
            src: (unsigned __int8 *)(*v5 + 8 * v7 + 8),
            count: 8 * (*(_DWORD *)(a1 + 40) - v7) - 8);
          --*(_DWORD *)(a1 + 40);
        }
      }
      while ( *(_DWORD *)(a1 + 40) != 0 );
    }
    *(_DWORD *)(a1 + 48) = 0;
    *(float *)(a1 + 300) = 0.083333336;
    *(_DWORD *)(a1 + 9332) |= 0x100u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CAE20
// Name: public: void GFxMovieRoot::LoadVars(class GFxLoadQueueEntry __near *,class GFxLoadStates __near *,class GString const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::LoadVars(
        VertexShaderHandle_t__ *this,
        struct GFxLoadQueueEntry *a2,
        GFxLoadStates *a3,
        const struct GString *a4,
        int a5)
{
  struct GASObject *v6; // esi
  const IClientRenderable *v7; // edi
  double v8; // st7
  int v10; // ebx
  int v11; // eax
  double *EmptySprite; // esi
  unsigned int v13; // edx
  unsigned int v14; // eax
  _DWORD *v15; // ecx
  int v16; // eax
  double v17; // st7
  struct GASEnvironment *v18; // eax
  struct GASStringNode *StringNode; // [esp+Ch] [ebp-4h]

  if ( GASValue::ToObject(this: (GASValue *)a2 + 11, a2: nullptr) != nullptr )
  {
    v6 = GASValue::ToObject(this: (GASValue *)a2 + 11, a2: nullptr);
    v7 = (const IClientRenderable *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 12) + 112))(a1: *((_DWORD *)this + 12));
    v8 = (double)a5;
    StringNode = GASStringManager::CreateStringNode(
                   this: (GASStringManager *)v7[30].__vftable[3].MarkShadowDirty,
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((a4->HeapTypeBits
                                                                                             & 0xFFFFFFFC)
                                                                                            + 8),
                   length: *(_DWORD *)(a4->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++*((_DWORD *)StringNode + 2);
    if ( *(double *)&v6[8] < 0.0 )
      *(double *)&v6[8] = 0.0;
    *(double *)&v6[7] = v8;
    *(double *)&v6[8] = v8 + *(double *)&v6[8];
    GASLoadVarsObject::NotifyOnData(this: (IClientRenderable *)v6, penv: v7);
    if ( (*((_DWORD *)StringNode + 2))-- == 1 )
      GASStringNode::ReleaseNode();
    return;
  }
  v10 = *((_DWORD *)a2 + 4);
  if ( v10 == -1 )
  {
    GFxCharacterHandle::ResolveCharacter(
      this: *((CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)a2
      + 5),
      a2: (GFxMovieRoot *)this);
    if ( v11 != 0 )
      ++*(_DWORD *)(v11 + 4);
    EmptySprite = (double *)v11;
LABEL_19:
    if ( (*(int (__thiscall **)(double *))(*(_DWORD *)EmptySprite + 176))(a1: EmptySprite) == 27 )
    {
      v17 = (double)a5;
      if ( EmptySprite[8] < 0.0 )
        EmptySprite[8] = 0.0;
      EmptySprite[7] = v17;
      EmptySprite[8] = v17 + EmptySprite[8];
    }
    v18 = (struct GASEnvironment *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 12) + 112))(a1: *((_DWORD *)this + 12));
    GASLoadVarsProto::LoadVariables(a1: v18, a2: (struct GASObjectInterface *)(EmptySprite + 15), a3: a4);
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)EmptySprite);
    return;
  }
  v13 = *((_DWORD *)this + 10);
  v14 = 0;
  if ( v13 != 0 )
  {
    v15 = *((_DWORD **)this + 9);
    while ( *v15 != v10 )
    {
      ++v14;
      v15 += 2;
      if ( v14 >= v13 )
        goto LABEL_14;
    }
    v16 = *(_DWORD *)(*((_DWORD *)this + 9) + 8 * v14 + 4);
    if ( v16 != 0 )
      ++*(_DWORD *)(v16 + 4);
  }
  else
  {
LABEL_14:
    v16 = 0;
  }
  EmptySprite = (double *)v16;
  if ( v16 != 0 )
    goto LABEL_19;
  EmptySprite = (double *)GFxMovieRoot::CreateEmptySprite(this, a2: (int)a3, result: *((GFxZlibSupportBase **)a2 + 4));
  if ( EmptySprite != nullptr )
    goto LABEL_19;
}

//------------------------------------------------------------------------------
// Address: 0x100CAF90
// Name: public: void GFxMovieRoot::DoActionsForSession(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::DoActionsForSession(GFxMovieRoot *this, unsigned int a2)
{
  const struct GFxMovieRoot::ActionEntry *i; // eax
  _BYTE *v3; // ecx
  GFxMovieRoot::ActionQueueSessionIterator v4; // [esp+0h] [ebp-14h] BYREF
  GMatrix3D *v5; // [esp+4h] [ebp-10h]
  GPoint3<float> *result; // [esp+8h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-8h]
  unsigned int v8; // [esp+10h] [ebp-4h]

  v5 = (GMatrix3D *)((char *)this + 9224);
  v4 = nullptr;
  v7 = 0;
  result = nullptr;
  v8 = a2;
  for ( i = GFxMovieRoot::ActionQueueSessionIterator::getNext(this: &v4);
        i != nullptr;
        i = GFxMovieRoot::ActionQueueSessionIterator::getNext(this: &v4) )
  {
    v3 = *((_BYTE **)i + 2);
    if ( v3 != nullptr && (v3[118] & 0x10) == 0 )
    {
      switch ( *((_DWORD *)i + 1) )
      {
        case 1:
          (*(void (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)v3 + 332))(a1: v3, a2: *((_DWORD *)i + 3));
          break;
        case 2:
          (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)v3 + 336))(a1: v3, a2: (int)i + 16);
          break;
        case 3:
          (*(void (__thiscall **)(_BYTE *, int, int))(*(_DWORD *)v3 + 340))(a1: v3, a2: (int)i + 32, a3: (int)i + 48);
          break;
        case 4:
          (*(void (__thiscall **)(_BYTE *, _DWORD, int))(*(_DWORD *)v3 + 344))(
            a1: v3,
            a2: *((_DWORD *)i + 11),
            a3: (int)i + 48);
          break;
        default:
          continue;
      }
    }
  }
  if ( result != nullptr )
    GFxMovieRoot::ActionQueueType::AddToFreeList(
      this: v5,
      (GMatrix3D *)result,
      pentry: (const GPoint3<float> *)v4,
      a4: (bool)v5);
}

//------------------------------------------------------------------------------
// Address: 0x100CB070
// Name: public: void GFxMovieRoot::ChangeMouseCursorType(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::ChangeMouseCursorType(
        IDirect3DVertexDeclaration9 *this,
        const IDirect3DVertexDeclaration9 *mouseIdx,
        unsigned int newCursorType)
{
  int v4; // ecx
  int (__thiscall *v5)(int); // edx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  struct GASObject *v9; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // edx
  int v11; // ecx
  int v12; // esi
  GASValue *v13; // eax
  double v14; // st7
  GASValue *v15; // eax
  double v16; // st7
  PPM_IDLE_STATE_ACCOUNTING *v17; // eax
  int i; // edi
  int v19; // [esp-8h] [ebp-80h]
  char *v20; // [esp+0h] [ebp-78h]
  const char *v21; // [esp+0h] [ebp-78h]
  _DWORD v22[9]; // [esp+Ch] [ebp-6Ch] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *res; // [esp+30h] [ebp-48h] BYREF
  GASValue scval[4]; // [esp+40h] [ebp-38h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *objVal; // [esp+50h] [ebp-28h] BYREF
  int v26; // [esp+60h] [ebp-18h] BYREF
  int v27; // [esp+64h] [ebp-14h]
  char v28; // [esp+68h] [ebp-10h]
  double v29; // [esp+6Ch] [ebp-Ch]
  IDirect3DVertexDeclaration9 *v30; // [esp+74h] [ebp-4h]

  v4 = *((_DWORD *)this + 12);
  v5 = *(int (__thiscall **)(int))(*(_DWORD *)v4 + 112);
  v30 = this;
  v6 = v5(a1: v4);
  if ( (*(_DWORD *)(this + 2333) & 0x1000) != 0 && *(_BYTE *)((v7 = *(_DWORD *)(v6 + 120)) + 684) == 1 )
  {
    v8 = *(_DWORD *)(v6 + 120);
    LOBYTE(objVal) = 0;
    if ( (*(unsigned __int8 (__thiscall **)(int, int, int, CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **))(*(_DWORD *)(*(_DWORD *)(v7 + 680) + 16) + 44))(
           a1: *(_DWORD *)(v7 + 680) + 16,
           a2: v6 + 120,
           a3: v8 + 116,
           a4: &objVal) != 0 )
    {
      v9 = GASValue::ToObject(this: &objVal, a2: (const struct GASEnvironment *)v6);
      if ( v9 != nullptr )
      {
        pNext = v9[2].pNode[2].pNext;
        v19 = *(_DWORD *)(v6 + 120) + 552;
        LOBYTE(scval[0]) = 0;
        if ( ((unsigned __int8 (__thiscall *)(struct GASObject *, int, int, GASValue *))pNext)(
               a1: &v9[2],
               a2: v6,
               a3: v19,
               a4: scval) != 0 )
        {
          GASValue::ToFunction(a1: &v26, a2: v6);
          v11 = v26;
          if ( v26 != 0 )
          {
            LOBYTE(res) = 0;
            *(_DWORD *)(v6 + 8) += 16;
            v29 = (double)(unsigned int)mouseIdx;
            v12 = v6 + 8;
            if ( *(_DWORD *)(v6 + 8) >= *(_DWORD *)(v6 + 16) )
              GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(v6 + 8), a2: v20);
            v13 = *(GASValue **)v12;
            if ( *(_DWORD *)v12 != 0 )
            {
              v14 = v29;
              *(_BYTE *)v13 = 3;
              *(double *)(v13 + 1) = v14;
            }
            *(_DWORD *)v12 += 16;
            v29 = (double)newCursorType;
            if ( *(_DWORD *)(v6 + 8) >= *(_DWORD *)(v6 + 16) )
              GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(v6 + 8), a2: v20);
            v15 = *(GASValue **)v12;
            if ( *(_DWORD *)v12 != 0 )
            {
              v16 = v29;
              *(_BYTE *)v15 = 3;
              *(double *)(v15 + 1) = v16;
            }
            v17 = GASFnCall::GASFnCall(
                    this: v22,
                    result: (PPM_IDLE_STATE_ACCOUNTING *)&res,
                    ThisIn: (tagWNDCLASSW *)&objVal,
                    a4: (_SERVICE_STATUS *)v6,
                    NargsIn: 2,
                    FirstIn: ((*(_DWORD *)(v6 + 8) - *(_DWORD *)(v6 + 12)) >> 4) + 32 * *(_DWORD *)(v6 + 28) - 32);
            (*(void (__thiscall **)(int, PPM_IDLE_STATE_ACCOUNTING *, int, _DWORD))(*(_DWORD *)v26 + 40))(
              a1: v26,
              a2: v17,
              a3: v27,
              a4: 0);
            GASFnCall::~GASFnCall(result: (tagMOUSEHOOKSTRUCTEX *)v20);
            if ( (unsigned int)(*(_DWORD *)(v6 + 8) - 32) >= *(_DWORD *)(v6 + 12) )
            {
              GASValue::~GASValue(this: *(GASValue **)v12);
              *(_DWORD *)v12 -= 16;
              GASValue::~GASValue(this: *(GASValue **)v12);
              *(_DWORD *)v12 -= 16;
            }
            else
            {
              for ( i = 2; i != 0; --i )
              {
                GASValue::~GASValue(this: *(GASValue **)v12);
                *(_DWORD *)v12 -= 16;
                if ( *(_DWORD *)v12 < *(_DWORD *)(v12 + 4) )
                  GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)v12, a2: v21);
              }
            }
            GASValue::~GASValue(this: &res);
            v11 = v26;
          }
          if ( (v28 & 2) == 0 && v11 != 0 )
            GRefCountBaseGC<323>::Release(a1: v11);
          v26 = 0;
          if ( (v28 & 1) == 0 && v27 != 0 )
            GRefCountBaseGC<323>::Release(a1: v27);
        }
        GASValue::~GASValue(this: scval);
      }
    }
    GASValue::~GASValue(this: &objVal);
    v30[9 * (_DWORD)mouseIdx + 596].__vftable = (IDirect3DVertexDeclaration9_vtbl *)newCursorType;
  }
  else
  {
    if ( newCursorType != *((_DWORD *)this + 9 * (_DWORD)mouseIdx + 596) )
      GASMouseCtorFunction::SetCursorType(
        a1: (struct GFxMovieRoot *)this,
        mouseIndex: (unsigned int)mouseIdx,
        cursorType: newCursorType);
    *((_DWORD *)this + 9 * (_DWORD)mouseIdx + 596) = newCursorType;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CB2A0
// Name: private: struct GFxMovieRoot::InvokeAliasInfo __near * GFxMovieRoot::ResolveInvokeAlias(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
struct GFxMovieRoot::InvokeAliasInfo *__thiscall GFxMovieRoot::ResolveInvokeAlias(GFxMovieRoot *this, const char *a2)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi
  int v6; // edi
  int Index; // eax
  int v8; // eax
  int v9; // edi

  if ( *((_DWORD *)this + 2295) == 0 || *((_DWORD *)this + 12) == 0 )
    return nullptr;
  v3 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 12) + 112))(a1: *((_DWORD *)this + 12));
  GASStringManager::CreateStringNode(this: *(const char **)(*(_DWORD *)(v3 + 120) + 636));
  v5 = v4;
  ++*(_DWORD *)(v4 + 8);
  v6 = **((_DWORD **)this + 2295);
  a2 = (const char *)v4;
  if ( v6 != 0
    && (Index = GHashSetBase<GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>(
                  a1: &a2,
                  a2: *(_DWORD *)(v4 + 12) & *(_DWORD *)(v6 + 4))) >= 0
    && (v8 = v6 + 28 * Index + 12) != 0 )
  {
    v9 = v8 + 4;
  }
  else
  {
    v9 = 0;
  }
  if ( (*(_DWORD *)(v5 + 8))-- == 1 )
    GASStringNode::ReleaseNode();
  return (struct GFxMovieRoot::InvokeAliasInfo *)v9;
}

//------------------------------------------------------------------------------
// Address: 0x100CB400
// Name: public: GFxTextAllocator::GFxTextAllocator(class GMemoryHeap __near *,unsigned char)
// Source: json
//------------------------------------------------------------------------------
GStringDH *__thiscall GFxTextAllocator::GFxTextAllocator(
        GStringDH *this,
        CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> *result,
        unsigned __int8 flags)
{
  this->HeapTypeBits = (unsigned int)&GRefCountImplCore::`vftable';
  this->pHeap = (GMemoryHeap *)1;
  this->HeapTypeBits = (unsigned int)&GFxTextAllocator::`vftable';
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 100;
  *((_DWORD *)this + 5) = 100;
  *((_DWORD *)this + 6) = 1;
  *((_DWORD *)this + 7) = result;
  *((_DWORD *)this + 8) = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 9) = 1;
  *((_DWORD *)this + 8) = &GFxTextFormat::`vftable';
  GStringDH::GStringDH(this: this + 5, a2: (struct GMemoryHeap *)result);
  GStringDH::GStringDH(this: this + 6, a2: (struct GMemoryHeap *)result);
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_BYTE *)this + 72) = 0;
  *((_DWORD *)this + 16) = -16777216;
  *((_WORD *)this + 37) = 0;
  *((_BYTE *)this + 76) = flags;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100CB4E0
// Name: public: virtual bool GFxLoadQueueEntryMT_LoadVars::LoadFinished(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxLoadQueueEntryMT_LoadVars::LoadFinished(GFxLoadQueueEntryMT_LoadVars *this)
{
  int v2; // esi
  char m_nAllocationCount_high; // dl
  CImagePacker *m_pMemory; // ebx
  char v5; // al
  int v6; // ecx
  void *v7; // esi
  GASValue *v9; // ecx
  void *v10; // esi
  int v11; // [esp+0h] [ebp-14h]
  CUtlMemory<CImagePacker,int> var8; // [esp+Ch] [ebp-8h] BYREF

  GString::GString(this: &var8);
  v2 = *((_DWORD *)this + 5);
  if ( *(_DWORD *)(v2 + 36) == 1 )
  {
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&var8,
      src: v2 + 28,
      a3: v11);
    m_pMemory = *(CImagePacker **)(v2 + 32);
    m_nAllocationCount_high = *(_BYTE *)(v2 + 40);
    v5 = 1;
  }
  else
  {
    m_nAllocationCount_high = HIBYTE(var8.m_nAllocationCount);
    m_pMemory = var8.m_pMemory;
    v5 = 0;
  }
  v6 = *((_DWORD *)this + 4);
  if ( *(_BYTE *)(v6 + 104) != 0 )
  {
    if ( v5 != 0 )
    {
LABEL_15:
      v10 = (void *)((int)var8.m_pMemory & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)var8.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v10);
      return 1;
    }
  }
  else if ( v5 != 0 )
  {
    if ( m_nAllocationCount_high == 0 )
    {
      v9 = (GASValue *)(v6 + 44);
      if ( *(_BYTE *)v9 == 6 )
        GASValue::DropRefs(this: v9);
    }
    GFxMovieRoot::LoadVars(
      this: *((VertexShaderHandle_t__ **)this + 3),
      a2: *((struct GFxLoadQueueEntry **)this + 4),
      a3: *((GFxLoadStates **)this + 6),
      a4: (const struct GString *)&var8,
      a5: (int)m_pMemory);
    goto LABEL_15;
  }
  v7 = (void *)((int)var8.m_pMemory & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)var8.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100CB5B0
// Name: public: void GFxMovieRoot::ProcessLoadVars(class GFxLoadQueueEntry __near *,class GFxLoadStates __near *,class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxMovieRoot::ProcessLoadVars(ScaleformRenderer *this, unsigned int pentry, _PSINJECTDATA pls)
{
  unsigned int v3; // ebx
  CImagePacker *v4; // esi
  unsigned int Length; // eax
  GFxLoadStates *DataBytes; // edi
  IShaderAPI *v7; // esi
  void *v8; // esi
  unsigned int v9; // esi
  void *result; // eax
  CUtlMemory<CImagePacker,int> v11; // [esp-Ch] [ebp-30h]
  CUtlMemory<CImagePacker,int> v12; // [esp-Ch] [ebp-30h]
  const CFunctorData0 *v13; // [esp+0h] [ebp-24h]
  int fileLen; // [esp+1Ch] [ebp-8h] BYREF
  struct GString v16; // [esp+20h] [ebp-4h] BYREF

  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v16);
  v3 = pentry;
  v4 = (CImagePacker *)(pentry + 12);
  fileLen = 0;
  Length = GString::GetLength(this: (GString *)(pentry + 12));
  DataBytes = (GFxLoadStates *)pls.DataBytes;
  if ( Length != 0 )
  {
    GString::GString(result: v4);
    GString::GString(result: *(CImagePacker **)&pls.InjectionPoint);
    GString::GString(this: (CUtlMemory<CImagePacker,int> *)&pentry);
    GFxLoadStates::BuildURL(result: (CP4Factory *)&pentry);
    v7 = (IShaderAPI *)GFxLoadStates::OpenFile(this: DataBytes, a2: (const char *)((pentry & 0xFFFFFFFC) + 8), a3: 0);
    if ( v7 != nullptr )
    {
      if ( *(_BYTE *)(v3 + 44) == 6 )
      {
        v11.m_nGrowSize = (int)&fileLen;
        *(_QWORD *)&v11.m_pMemory = __PAIR64__(&v16, (unsigned int)v7);
        if ( GFx_ReadLoadVariables(a1: (int)v7, a2: v11) == 0 )
          GASValue::DropRefs(this: (GASValue *)(v3 + 44));
      }
      else
      {
        v12.m_nGrowSize = (int)&fileLen;
        *(_QWORD *)&v12.m_pMemory = __PAIR64__(&v16, (unsigned int)v7);
        GFx_ReadLoadVariables(a1: (int)v7, a2: v12);
      }
      GRefCountImpl::Release(this: v7);
    }
    v8 = (void *)(pentry & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((pentry & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
    GFxURLBuilder::LocationInfo::~LocationInfo(result: v13);
  }
  GFxMovieRoot::LoadVars(
    (VertexShaderHandle_t__ *)this,
    a2: (struct GFxLoadQueueEntry *)v3,
    a3: DataBytes,
    a4: &v16,
    a5: fileLen);
  v9 = v16.HeapTypeBits & 0xFFFFFFFC;
  result = (void *)(InterlockedExchangeAdd(Addend: (volatile LONG *)((v16.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) - 1);
  if ( result == nullptr )
    return ((void *(__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
             a1: GMemory::pGlobalHeap,
             a2: v9);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CB6E0
// Name: public: GFxMovieRoot::ActionQueueType::~ActionQueueType(void)
// Source: json
//------------------------------------------------------------------------------
GPoint3<float> *__usercall GFxMovieRoot::ActionQueueType::~ActionQueueType@<eax>(int a1@<ecx>, const float *a2@<edi>)
{
  GPoint3<float> *v3; // eax
  GMatrix3D *v4; // esi
  GMatrix3D *v5; // edi
  const float *v6; // [esp-4h] [ebp-18h]
  const GPoint3<float> *v7; // [esp+0h] [ebp-14h]
  BOOL v8; // [esp+4h] [ebp-10h] BYREF
  GMatrix3D *v9; // [esp+8h] [ebp-Ch]
  GPoint3<float> *v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  v9 = (GMatrix3D *)a1;
  v8 = false;
  v11 = 0;
  v10 = nullptr;
  while ( GFxMovieRoot::ActionQueueIterator::getNext(this: (GFxMovieRoot::ActionQueueIterator *)&v8) != nullptr )
    ;
  v3 = v10;
  if ( v10 != nullptr )
    v3 = GFxMovieRoot::ActionQueueType::AddToFreeList(this: v9, result: (GMatrix3D *)v10, pentry: v7, a4: v8);
  v4 = *(GMatrix3D **)(a1 + 76);
  if ( v4 != nullptr )
  {
    v6 = a2;
    do
    {
      v5 = (GMatrix3D *)LODWORD(v4->M_[0][0]);
      GFxMovieRoot::ActionEntry::~ActionEntry(this: v4, a2: v6, a3: (int)v7);
      v3 = (GPoint3<float> *)((int (__thiscall *)(GMemoryHeap *, GMatrix3D *))GMemory::pGlobalHeap->Free)(
                               a1: GMemory::pGlobalHeap,
                               a2: v4);
      v4 = v5;
    }
    while ( v5 != nullptr );
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100CB750
// Name: public: bool GFxMovieRoot::Invoke(class GFxSprite __near *,char const __near *,class GFxValue __near *,class GFxValue const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxMovieRoot::Invoke(
        GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *this,
        struct GFxSprite *a2,
        IDirect3D9 *a3,
        struct GFxValue *a4,
        const struct GFxValue *a5,
        unsigned int numArgs)
{
  GFxSprite *v6; // edi
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *v7; // esi
  GFxAmpViewStats *v9; // ecx
  float v10; // ecx
  int (__thiscall *v11)(struct GFxSprite *); // eax
  unsigned int v12; // eax
  int v13; // ebx
  GFxValue *v14; // edi
  __vc_attributes::iid_isAttribute *v15; // esi
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **v16; // eax
  unsigned int v17; // ebx
  unsigned __int8 v18; // al
  unsigned int v19; // edi
  float v20; // ecx
  const char *v21; // [esp+0h] [ebp-50h]
  float *v22; // [esp+4h] [ebp-4Ch]
  GFxAmpViewStats *v23; // [esp+14h] [ebp-3Ch]
  GASValue asval[4]; // [esp+24h] [ebp-2Ch] BYREF
  GASValue resultVal[4]; // [esp+34h] [ebp-1Ch] BYREF
  unsigned int _CurrentState; // [esp+44h] [ebp-Ch] BYREF
  unsigned int v27; // [esp+48h] [ebp-8h] BYREF
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *v28; // [esp+4Ch] [ebp-4h]
  bool retVal; // [esp+5Bh] [ebp+Bh]

  v6 = (GFxSprite *)a2;
  v7 = this;
  v28 = this;
  if ( a2 == nullptr )
    return false;
  v9 = *((GFxAmpViewStats **)this + 2577);
  v23 = v9;
  if ( v9 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v9, swdHandle: 1u, a3: 0x11u);
    GTimer::GetRawTicks(li: v10, a2: *(float *)&v21, a3: v22);
  }
  _controlfp_s(&_CurrentState, newctrl: 0, mask: 0);
  _controlfp_s(_CurrentState: &v27, newctrl: 0x10000u, mask: 0x30000u);
  v11 = *(int (__thiscall **)(struct GFxSprite *))(*(_DWORD *)a2 + 112);
  LOBYTE(resultVal[0]) = 0;
  v12 = v11(a1: a2);
  v13 = numArgs - 1;
  v27 = v12;
  if ( (int)(numArgs - 1) >= 0 )
  {
    v14 = (GFxValue *)&a5[v13];
    v15 = (__vc_attributes::iid_isAttribute *)(v12 + 8);
    do
    {
      LOBYTE(asval[0]) = 0;
      GFxMovieRoot::GFxValue2ASValue(this: (GFxMovieRoot *)v28, a2: v14, a3: (struct GASValue *)asval);
      v15->limited_expression += 16;
      if ( v15->limited_expression >= v15[2].limited_expression )
        GASPagedStack<GASValue,32>::PushPage(this: v15, a2: v21);
      if ( v15->limited_expression != nullptr )
        GASValue::GASValue(this: (GASValue *)v15->limited_expression, a2: (const struct GASValue *)asval);
      GASValue::~GASValue(this: asval);
      --v14;
      --v13;
    }
    while ( v13 >= 0 );
    v6 = (GFxSprite *)a2;
    v7 = v28;
  }
  if ( v7[1147].pContainer != nullptr
    && (v16 = (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)GFxMovieRoot::ResolveInvokeAlias(this: (GFxMovieRoot *)v28, a2: (const char *)a3)) != nullptr )
  {
    v17 = numArgs;
    v18 = GFxMovieRoot::InvokeAlias(
            a1: (int)v28,
            a2: *(float *)&numArgs,
            this: a3,
            pmethodName: v16,
            a5: (int)resultVal,
            numArgs);
  }
  else
  {
    v18 = GFxSprite::Invoke(this: v6, varname: (const char *)a3, a3: (struct GASValue *)resultVal, a4: numArgs);
    v17 = numArgs;
  }
  v19 = v27;
  for ( retVal = v18; v17 != 0; --v17 )
  {
    GASValue::~GASValue(this: *(GASValue **)(v19 + 8));
    *(_DWORD *)(v19 + 8) -= 16;
    if ( *(_DWORD *)(v19 + 8) < *(_DWORD *)(v19 + 12) )
      GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)(v19 + 8), a2: v21);
  }
  if ( retVal && a4 != nullptr )
    GFxMovieRoot::ASValue2GFxValue(this: v28);
  GASValue::~GASValue(this: resultVal);
  _controlfp_s(_CurrentState: &numArgs, newctrl: _CurrentState, mask: 0x30000u);
  if ( v23 != nullptr )
  {
    GTimer::GetRawTicks(li: v20, a2: *(float *)&v21, a3: v22);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
  return retVal;
}

//------------------------------------------------------------------------------
// Address: 0x100CB900
// Name: public: virtual bool GFxMovieRoot::Invoke(char const __near *,class GFxValue __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
char __usercall GFxMovieRoot::Invoke@<al>(
        float a1@<ebx>,
        GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>::SysAllocContainer *result,
        char *a3,
        int a4,
        char *a5,
        ...)
{
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>::SysAllocContainer *v5; // esi
  GFxAmpViewStats *v7; // ebx
  float v8; // ecx
  bool v9; // zf
  char *v10; // edi
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **v11; // eax
  unsigned __int8 v12; // al
  float v13; // ecx
  float v14; // [esp-4h] [ebp-3Ch]
  float *v15; // [esp+0h] [ebp-38h]
  GASValue resultVal[4]; // [esp+20h] [ebp-18h] BYREF
  unsigned int v17; // [esp+30h] [ebp-8h] BYREF
  unsigned int _CurrentState; // [esp+34h] [ebp-4h] BYREF
  va_list va; // [esp+50h] [ebp+18h] BYREF

  va_start(va, a5);
  v5 = result;
  if ( result[4].Data[0] == 0 )
    return 0;
  v14 = a1;
  v7 = (GFxAmpViewStats *)result[859].Data[0];
  if ( v7 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v7, swdHandle: 1u, a3: 0x11u);
    GTimer::GetRawTicks(li: v8, a2: v14, a3: v15);
  }
  _controlfp_s(&_CurrentState, newctrl: 0, mask: 0);
  _controlfp_s(_CurrentState: (unsigned int *)&result, newctrl: 0x10000u, mask: 0x30000u);
  v9 = v5[765].Data[0] == 0;
  v10 = a3;
  LOBYTE(resultVal[0]) = 0;
  if ( v9
    || (v11 = (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)GFxMovieRoot::ResolveInvokeAlias(this: (GFxMovieRoot *)v5, a2: a3)) == nullptr )
  {
    GFxSprite::InvokeArgs(this: (GRefCountBase<GFxResourceLibBase,2> *)v5[4].Data[0]);
  }
  else
  {
    v12 = GFxMovieRoot::InvokeAliasArgs(
            this: (GFxMovieRoot *)v5,
            a2: *(float *)&v7,
            a3: v10,
            a4: v11,
            method: (struct GASValue *)resultVal,
            a6: a5,
            args: va);
  }
  HIBYTE(result) = v12;
  if ( v12 != 0 && a4 != 0 )
  {
    (*(void (__thiscall **)(unsigned int, GASValue *, int))(*(_DWORD *)v5[4].Data[0] + 112))(
      a1: v5[4].Data[0],
      a2: resultVal,
      a3: a4);
    GFxMovieRoot::ASValue2GFxValue(this: (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *)v5);
  }
  GASValue::~GASValue(this: resultVal);
  _controlfp_s(_CurrentState: &v17, newctrl: _CurrentState, mask: 0x30000u);
  if ( v7 != nullptr )
  {
    GTimer::GetRawTicks(li: v13, a2: v14, a3: v15);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
  return HIBYTE(result);
}

//------------------------------------------------------------------------------
// Address: 0x100CBA20
// Name: public: virtual bool GFxMovieRoot::InvokeArgs(char const __near *,class GFxValue __near *,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge GFxMovieRoot::InvokeArgs@<al>(
        GFxMovieRoot *this@<ecx>,
        float a2@<ebx>,
        char *a3,
        struct GFxValue *a4,
        char *a5,
        char *retVal)
{
  GFxAmpViewStats *v7; // ebx
  float v8; // ecx
  bool v9; // zf
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **v10; // eax
  unsigned __int8 v11; // al
  float v12; // ecx
  float v14; // [esp-4h] [ebp-3Ch]
  float *v15; // [esp+0h] [ebp-38h]
  GASValue resultVal[4]; // [esp+20h] [ebp-18h] BYREF
  unsigned int v17; // [esp+30h] [ebp-8h] BYREF
  unsigned int _CurrentState; // [esp+34h] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 12) == 0 )
    return false;
  v14 = a2;
  v7 = *((GFxAmpViewStats **)this + 2577);
  if ( v7 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v7, swdHandle: 1u, a3: 0x12u);
    GTimer::GetRawTicks(li: v8, a2: v14, a3: v15);
  }
  _controlfp_s(&_CurrentState, newctrl: 0, mask: 0);
  _controlfp_s(_CurrentState: &v17, newctrl: 0x10000u, mask: 0x30000u);
  v9 = *((_DWORD *)this + 2295) == 0;
  LOBYTE(resultVal[0]) = 0;
  if ( v9
    || (v10 = (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)GFxMovieRoot::ResolveInvokeAlias(this, a2: a3)) == nullptr )
  {
    GFxSprite::InvokeArgs(this: *((GRefCountBase<GFxResourceLibBase,2> **)this + 12));
  }
  else
  {
    v11 = GFxMovieRoot::InvokeAliasArgs(
            this,
            a2: *(float *)&v7,
            a3,
            a4: v10,
            method: (struct GASValue *)resultVal,
            a6: a5,
            args: retVal);
  }
  HIBYTE(retVal) = v11;
  if ( v11 != 0 && a4 != nullptr )
  {
    (*(void (__thiscall **)(_DWORD, GASValue *, struct GFxValue *))(**((_DWORD **)this + 12) + 112))(
      a1: *((_DWORD *)this + 12),
      a2: resultVal,
      a3: a4);
    GFxMovieRoot::ASValue2GFxValue((GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *)this);
  }
  GASValue::~GASValue(this: resultVal);
  _controlfp_s(_CurrentState: (unsigned int *)&a5, newctrl: _CurrentState, mask: 0x30000u);
  if ( v7 != nullptr )
  {
    GTimer::GetRawTicks(li: v12, a2: v14, a3: v15);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
  return HIBYTE(retVal);
}

//------------------------------------------------------------------------------
// Address: 0x100CBB40
// Name: public: class GFxTextAllocator __near * GFxMovieRoot::GetTextAllocator(void)
// Source: json
//------------------------------------------------------------------------------
const IDirect3DVertexDeclaration9 *__thiscall GFxMovieRoot::GetTextAllocator(int this)
{
  int v2; // eax
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // edx
  GStringDH *v5; // eax
  GStringDH *v6; // ebx
  int v7; // esi
  GRefCountNTSImpl *v8; // ecx
  int v10; // [esp+4h] [ebp-4h] BYREF

  v2 = *(_DWORD *)(this + 20);
  if ( *(_DWORD *)(v2 + 20) != 0 )
    return *(const IDirect3DVertexDeclaration9 **)(v2 + 20);
  v3 = *(_DWORD *)(this + 32);
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  v10 = 324;
  v5 = (GStringDH *)v4(a1: v3, a2: 80, a3: &v10);
  if ( v5 != nullptr )
    v6 = GFxTextAllocator::GFxTextAllocator(
           this: v5,
           result: *(CMemberFuncProxyBase<CMaterial *,void (__thiscall CMaterial::*)(enum MaterialVarFlags_t,bool),CFuncMemPolicyNone> **)(this + 32),
           flags: 0);
  else
    v6 = nullptr;
  v7 = *(_DWORD *)(this + 20);
  v8 = *(GRefCountNTSImpl **)(v7 + 20);
  if ( v8 != nullptr )
    GRefCountNTSImpl::Release(this: v8);
  *(_DWORD *)(v7 + 20) = v6;
  return *(const IDirect3DVertexDeclaration9 **)(*(_DWORD *)(this + 20) + 20);
}

//------------------------------------------------------------------------------
// Address: 0x100CBBB0
// Name: public: virtual void GFxPlaceObject3::Unpack(struct GFxPlaceObjectBase::UnpackedData __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPlaceObject3::Unpack(
        CMemberFuncProxy4<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *,bool),int,enum MaterialIndexFormat_t,void *,bool,CFuncMemPolicyNone> *this,
        int data)
{
  int v2; // esi
  unsigned __int8 *DataBytes; // ecx
  int v4; // eax
  unsigned __int8 v5; // bl
  int v6; // edx
  int v7; // eax
  int v8; // edx
  unsigned __int8 v9; // dl
  __int16 v10; // dx
  int v11; // ebx
  char *v12; // esi
  tagSTATSTG *v13; // esi
  unsigned __int8 v14; // dl
  char v15; // cl
  void **v16; // ebx
  GMemoryHeap *v17; // eax
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  void **v19; // eax
  int v20; // eax
  unsigned int v21; // esi
  GMemoryHeap *v22; // eax
  void *(__thiscall *v23)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  int v24; // eax
  unsigned int v25; // esi
  int *v26; // eax
  char v27; // cl
  bool v28; // zf
  ITypeInfo *v29; // [esp+0h] [ebp-2A8h]
  unsigned int v30; // [esp+0h] [ebp-2A8h]
  int v31; // [esp+Ch] [ebp-29Ch] BYREF
  int v32; // [esp+10h] [ebp-298h] BYREF
  CMemberFuncProxy4<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *,bool),int,enum MaterialIndexFormat_t,void *,bool,CFuncMemPolicyNone> *v33; // [esp+14h] [ebp-294h]
  int v34; // [esp+18h] [ebp-290h]
  char v35; // [esp+1Fh] [ebp-289h]
  _PSINJECTDATA v36; // [esp+20h] [ebp-288h] BYREF
  int v37; // [esp+28h] [ebp-280h]
  int v38; // [esp+2Ch] [ebp-27Ch]
  unsigned __int8 po3Flags; // [esp+32h] [ebp-276h]
  unsigned __int8 po2Flags; // [esp+33h] [ebp-275h]
  unsigned __int64 filters[4]; // [esp+34h] [ebp-274h] BYREF

  v2 = 0;
  v33 = this;
  DataBytes = (unsigned __int8 *)&this->m_pfnProxied + 4;
  v37 = 0;
  v36.DataBytes = (unsigned int)DataBytes;
  *(_DWORD *)&v36.InjectionPoint = -1;
  v38 = 0;
  po2Flags = *DataBytes;
  v4 = 1;
  v37 = 1;
  v35 = po2Flags & 0x80;
  if ( (po2Flags & 0x80u) != 0 )
  {
    v4 = 5;
    v37 = 5;
  }
  v38 = 0;
  po3Flags = DataBytes[v4];
  v37 = v4 + 1;
  v38 = 0;
  v5 = po2Flags;
  v6 = *(unsigned __int16 *)&DataBytes[v4 + 1];
  v7 = v4 + 3;
  v37 = v7;
  *(_DWORD *)(data + 72) = v6;
  if ( (v5 & 2) != 0 )
  {
    *(_BYTE *)(data + 83) |= 2u;
    v2 = 0;
    v38 = 0;
    v5 = po2Flags;
    v8 = *(unsigned __int16 *)&DataBytes[v7];
    v7 += 2;
    v37 = v7;
    *(_DWORD *)(data + 76) = v8;
  }
  if ( (v5 & 4) != 0 )
  {
    *(_BYTE *)(data + 83) |= 4u;
    GFxStreamContext::ReadMatrix(this: (GFxStreamContext *)&v36, pm: (CMaterialDict *)(data + 44));
    v2 = v38;
    v7 = v37;
    DataBytes = (unsigned __int8 *)v36.DataBytes;
  }
  if ( (v5 & 8) != 0 )
  {
    *(_BYTE *)(data + 83) |= 8u;
    GFxStreamContext::ReadCxformRgba(this: (GFxStreamContext *)&v36, a2: (struct GRenderer::Cxform *)(data + 12));
    v2 = v38;
    v7 = v37;
    DataBytes = (unsigned __int8 *)v36.DataBytes;
  }
  if ( (v5 & 0x10) != 0 )
  {
    *(_BYTE *)(data + 83) |= 0x10u;
    if ( v2 != 0 )
      v37 = ++v7;
    v2 = 0;
    v38 = 0;
    v34 = *(unsigned __int16 *)&DataBytes[v7];
    v5 = po2Flags;
    v7 += 2;
    v37 = v7;
    *(float *)(data + 68) = (double)v34 / 65535.0;
  }
  if ( (v5 & 0x20) != 0 )
  {
    if ( v2 != 0 )
      v37 = ++v7;
    *(_DWORD *)(data + 88) = (char *)&v33->m_pfnProxied + v7 + 4;
    do
    {
      v2 = 0;
      v38 = 0;
      v9 = DataBytes[v7++];
      v37 = v7;
    }
    while ( v9 != 0 );
  }
  else
  {
    *(_DWORD *)(data + 88) = 0;
  }
  if ( (v5 & 0x40) != 0 )
  {
    if ( v2 != 0 )
      v37 = ++v7;
    v2 = 0;
    v38 = 0;
    v10 = *(_WORD *)&DataBytes[v7];
    v7 += 2;
    *(_WORD *)(data + 80) = v10;
    *(_BYTE *)(data + 83) |= 0x40u;
    v37 = v7;
  }
  if ( (po3Flags & 1) != 0 )
  {
    *(_BYTE *)(data + 83) |= 0x20u;
    v11 = 3;
    v12 = (char *)&filters[1] + 4;
    do
    {
      *((_DWORD *)v12 - 1) = 0;
      *((_DWORD *)v12 + 2) = 1;
      *(float *)v12 = 5.0;
      *((float *)v12 + 1) = 5.0;
      *((float *)v12 + 3) = 0.0;
      *((float *)v12 + 4) = 0.0;
      *((float *)v12 + 7) = 1.0;
      GRenderer::Cxform::Cxform();
      v12 += 156;
      --v11;
    }
    while ( v11 >= 0 );
    v13 = (tagSTATSTG *)GFx_LoadFilters<GFxStreamContext>(a1: &v36, a2: filters, a3: 4);
    if ( v13 != nullptr )
    {
      GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::Clear(this: v29);
      GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::Append(
        a1: (CMatQueuedMesh *)data,
        this: (IStream *)filters,
        other: v13,
        count: v30);
    }
    DataBytes = (unsigned __int8 *)v36.DataBytes;
    v7 = v37;
    v2 = v38;
  }
  v14 = po3Flags;
  if ( (po3Flags & 2) != 0 )
  {
    *(_BYTE *)(data + 83) |= 0x80u;
    if ( v2 != 0 )
      v37 = ++v7;
    v2 = 0;
    v38 = 0;
    v15 = DataBytes[v7++];
    if ( v15 == 0 || (unsigned __int8)v15 > 0xEu )
      v15 = 1;
    *(_BYTE *)(data + 82) = v15;
  }
  if ( (v14 & 4) != 0 )
  {
    if ( v2 != 0 )
      ++v7;
    v2 = 0;
    ++v7;
  }
  v16 = nullptr;
  if ( v35 != 0 )
  {
    v16 = *(void ***)((char *)&v33->m_pfnProxied + 5);
    if ( v16 == nullptr )
    {
      if ( v2 != 0 )
        ++v7;
      v38 = 0;
      v37 = v7 + 6;
      v17 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: v33);
      Alloc_2 = v17->Alloc_2;
      v31 = 260;
      v19 = (void **)Alloc_2(this: v17, a2: 12u, a3: (const GAllocDebugInfo *)&v31);
      v16 = nullptr;
      if ( v19 != nullptr )
      {
        *v19 = nullptr;
        v19[1] = nullptr;
        v19[2] = nullptr;
        v16 = v19;
      }
      while ( 1 )
      {
        v20 = v37;
        if ( v38 != 0 )
          v20 = ++v37;
        v38 = 0;
        v21 = *(unsigned __int8 *)(v36.DataBytes + v20)
            | ((*(unsigned __int8 *)(v36.DataBytes + v20 + 1) | (*(unsigned __int16 *)(v36.DataBytes + v20 + 2) << 8)) << 8);
        v37 = v20 + 4;
        if ( v21 == 0 )
          break;
        v22 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: v33);
        v23 = v22->Alloc_2;
        v32 = 260;
        v24 = (int)v23(this: v22, a2: 20u, a3: (const GAllocDebugInfo *)&v32);
        if ( v24 != 0 )
        {
          *(_DWORD *)v24 = 0;
          *(_DWORD *)(v24 + 4) = 0;
          *(_WORD *)(v24 + 8) = 0;
          *(_DWORD *)(v24 + 10) = 65280;
          *(_DWORD *)(v24 + 16) = 0;
          v34 = v24;
        }
        else
        {
          v34 = 0;
        }
        GFxSwfEvent::Read(this: (GFxSwfEvent *)v34, psc: &v36, flags: v21);
        v25 = (unsigned int)v16[1] + 1;
        if ( v25 >= (unsigned int)v16[1] )
        {
          if ( v25 >= (unsigned int)v16[2] )
            GArrayDataBase<GFxSwfEvent *,GAllocatorLH<GFxSwfEvent *,260>,GArrayDefaultPolicy>::Reserve(
              this: v16,
              a2: v16,
              a3: v25 + (v25 >> 2));
        }
        else if ( v25 < (unsigned int)v16[2] >> 1 )
        {
          GArrayDataBase<GFxSwfEvent *,GAllocatorLH<GFxSwfEvent *,260>,GArrayDefaultPolicy>::Reserve(
            this: v16,
            a2: v16,
            a3: (int)v16[1] + 1);
        }
        v26 = (int *)((char *)*v16 + 4 * v25 - 4);
        v16[1] = (void *)v25;
        if ( v26 != nullptr )
          *v26 = v34;
      }
      *(_DWORD *)((char *)&v33->m_pfnProxied + 5) = v16;
    }
  }
  v27 = po2Flags & 1;
  v28 = (po2Flags & 2) == 0;
  *(_DWORD *)(data + 84) = v16;
  *(_DWORD *)(data + 92) = 0;
  if ( v28 )
  {
    if ( v27 != 0 )
      *(_DWORD *)(data + 92) = 1;
  }
  else if ( v27 != 0 )
  {
    *(_DWORD *)(data + 92) = 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CC080
// Name: public: void GFxMovieRoot::ProcessMouse(class GASEnvironment __near *,struct GFxInputEventsQueue::QueueEntry const __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::ProcessMouse(
        IDirect3DVertexDeclaration9 *this@<ecx>,
        _D3DBACKBUFFER_TYPE a2@<ebx>,
        unsigned int a3@<edi>,
        struct GASEnvironment *a4,
        IDirect3DSwapChain9 *a5,
        unsigned int *pitemUnderMousePtr)
{
  GFxAmpViewStats *v7; // ecx
  float *v8; // eax
  float v9; // ecx
  unsigned int v11; // ebx
  _D3DDISPLAYMODE *TopMostEntity; // eax
  bool v13; // zf
  SFTextObjectImpl *v14; // eax
  bool v15; // al
  SFTextObjectImpl *v16; // eax
  int v17; // ebx
  void (__thiscall *v18)(int, _DWORD *); // edx
  void (__thiscall *v19)(int, _DWORD *); // edx
  bool v20; // al
  GRefCountNTSImpl *v21; // eax
  GMemAddressStub *v22; // ecx
  unsigned int v23; // eax
  int v24; // edi
  _DWORD *v25; // eax
  GRefCountNTSImpl *v26; // eax
  GRefCountNTSImpl *v27; // edi
  float v28; // ecx
  const char *v31; // [esp-8h] [ebp-64h]
  int v33; // [esp-4h] [ebp-60h]
  IDirect3DSurface9 **v34; // [esp+0h] [ebp-5Ch]
  float v35; // [esp+0h] [ebp-5Ch]
  float *v36; // [esp+4h] [ebp-58h]
  float *v37; // [esp+4h] [ebp-58h]
  GFxAmpViewStats *v38; // [esp+Ch] [ebp-50h]
  _DWORD v39[2]; // [esp+1Ch] [ebp-40h] BYREF
  __int16 v40; // [esp+24h] [ebp-38h]
  char v41; // [esp+26h] [ebp-36h]
  char v42; // [esp+27h] [ebp-35h]
  __int16 v43; // [esp+28h] [ebp-34h]
  _DWORD v44[2]; // [esp+2Ch] [ebp-30h] BYREF
  __int16 v45; // [esp+34h] [ebp-28h]
  char v46; // [esp+36h] [ebp-26h]
  char v47; // [esp+37h] [ebp-25h]
  __int16 v48; // [esp+38h] [ebp-24h]
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> v49; // [esp+3Ch] [ebp-20h] BYREF
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> result; // [esp+44h] [ebp-18h] BYREF
  GMemAddressStub *buttonsState; // [esp+4Ch] [ebp-10h]
  GFxMouseState *v52; // [esp+50h] [ebp-Ch]
  GRefCountNTSImpl *v53; // [esp+54h] [ebp-8h]
  SFTextObjectImpl *v54; // [esp+58h] [ebp-4h]
  IDirect3DSwapChain9 *v55; // [esp+68h] [ebp+Ch]
  IDirect3DSwapChain9 *v56; // [esp+68h] [ebp+Ch]
  bool v57; // [esp+6Bh] [ebp+Fh]
  unsigned int *pitemUnderMousePtra; // [esp+6Ch] [ebp+10h]

  v7 = *((GFxAmpViewStats **)this + 2577);
  v8 = nullptr;
  v38 = v7;
  if ( v7 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v7, swdHandle: 1u, a3: 0xDu);
    GTimer::GetRawTicks(li: v9, a2: *(float *)&v34, a3: v36);
  }
  v37 = v8;
  *pitemUnderMousePtr |= 1 << LOBYTE(a5[4].__vftable);
  v11 = LOBYTE(a5[4].__vftable);
  v53 = (GRefCountNTSImpl *)v11;
  v55 = (IDirect3DSwapChain9 *)(this + 9 * v11);
  v52 = (GFxMouseState *)&v55[589];
  GFxMouseState::UpdateState(a1: (int)&v55[589], this: a5, qe: a3, a4: a2, a5: v34);
  result.__vftable = (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>_vtbl *)a5[1].__vftable;
  result.pContainer = (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>::SysAllocContainer *)a5[2].__vftable;
  TopMostEntity = (_D3DDISPLAYMODE *)GFxMovieRoot::GetTopMostEntity(
                                       (int)this,
                                       &result,
                                       a3: *(float *)&v11,
                                       testAll: false,
                                       ignoreMC: 0);
  pitemUnderMousePtra = &TopMostEntity->Width;
  if ( TopMostEntity != nullptr )
    ++TopMostEntity->Height;
  GFxMouseState::SetTopmostEntity(this: (struct GWeakPtrProxy **)v52, result: TopMostEntity);
  v13 = LOWORD(a5[3].__vftable) == 0;
  buttonsState = (GMemAddressStub *)v55[592].__vftable;
  if ( !v13 )
  {
    v14 = (SFTextObjectImpl *)(*(int (__thiscall **)(char *, int))(*((_DWORD *)this + 2) + 12))(
                                a1: (char *)this + 8,
                                a2: 27);
    v54 = v14;
    if ( v14 != nullptr )
    {
      if ( ((unsigned __int8 (__thiscall *)(SFTextObjectImpl *, IDirect3DVertexDeclaration9 *))v14->__vftable[2].SetText)(
             a1: v14,
             a2: this) != 0 )
      {
        if ( (HIBYTE(a5[3].__vftable) & 0xC0) != 0 || LOWORD(a5[3].__vftable) == 0 )
          CDummyMaterial::GetLowResColorSample(
            this: v54,
            startPos: (unsigned int)this,
            startPosa: (unsigned int)buttonsState,
            length: (unsigned int)pitemUnderMousePtra);
        else
          GFxIMEManager::OnMouseDown(
            pmovie: (unsigned int)this,
            buttonsState,
            pitemUnderMousePtr: (int)pitemUnderMousePtra,
            a4: v31,
            a5: v33);
      }
      GRefCountImpl::Release(this: (IShaderAPI *)v54);
    }
  }
  v13 = LOWORD(a5[3].__vftable) == 0;
  buttonsState = nullptr;
  if ( !v13 && ((int)a5[3].__vftable & 1) != 0 )
  {
    v15 = (HIBYTE(a5[3].__vftable) & 0xC0) == 0 && LOWORD(a5[3].__vftable) != 0;
    buttonsState = (GMemAddressStub *)(v15 ? 16 : 32);
  }
  v16 = *((SFTextObjectImpl **)this + 10);
  v54 = v16;
  if ( (int)v16 > 0 )
  {
    do
    {
      v17 = *(_DWORD *)(*((_DWORD *)this + 9) + 8 * (_DWORD)v16 - 4);
      if ( buttonsState != nullptr )
      {
        v18 = *(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v17 + 160);
        v44[0] = buttonsState;
        v45 = 0;
        v46 = 0;
        v48 = 0;
        v47 = (char)v53;
        v44[1] = 0;
        v18(a1: v17, a2: v44);
        v16 = v54;
      }
      if ( ((int)v55[597].__vftable & 8) != 0 )
      {
        v40 = 0;
        v41 = 0;
        v43 = 0;
        v19 = *(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v17 + 160);
        v42 = (char)v53;
        v39[0] = 8;
        v39[1] = 0;
        v19(a1: v17, a2: v39);
        v16 = v54;
      }
      v16 = (SFTextObjectImpl *)((char *)v16 - 1);
      v54 = v16;
    }
    while ( (int)v16 > 0 );
    v11 = (unsigned int)v53;
  }
  if ( ((int)v55[597].__vftable & 8) != 0 && ((*((_DWORD *)this + 2333) >> 22) & 3) != 1 )
    GFxMovieRoot::HideFocusRect((GFxMovieRoot *)this, a2: v11);
  if ( (HIBYTE(a5[3].__vftable) & 0x20) != 0 && pitemUnderMousePtra != nullptr )
    (*(void (__thiscall **)(unsigned int *, _DWORD))(*pitemUnderMousePtra + 156))(
      a1: pitemUnderMousePtra,
      a2: SBYTE2(a5[3].__vftable));
  if ( *((_DWORD *)this + 628) != 0
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)this + 628) + 20))(a1: *((_DWORD *)this + 628)) == 0 )
  {
    v20 = ((int)v55[597].__vftable & 8) != 0;
    if ( ((int)v55[597].__vftable & 8) != 0 || LOWORD(a5[3].__vftable) != 0 || (HIBYTE(a5[3].__vftable) & 0x20) != 0 )
    {
      v57 = *(_BYTE *)(*((_DWORD *)a4 + 30) + 684) == 1;
      if ( v20 )
        (*(void (__thiscall **)(_DWORD, struct GASEnvironment *, unsigned int))(**((_DWORD **)this + 628) + 4))(
          a1: *((_DWORD *)this + 628),
          a2: a4,
          a3: v11);
      if ( (HIBYTE(a5[3].__vftable) & 0x20) != 0 || LOWORD(a5[3].__vftable) != 0 )
      {
        v49.__vftable = (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>_vtbl *)a5[1].__vftable;
        v49.pContainer = (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>::SysAllocContainer *)a5[2].__vftable;
        v21 = (GRefCountNTSImpl *)GFxMovieRoot::GetTopMostEntity(
                                    (int)this,
                                    result: &v49,
                                    a3: *(float *)&v11,
                                    testAll: true,
                                    ignoreMC: 0);
        v53 = v21;
        if ( v21 != nullptr )
          ++v21->RefCount;
        if ( (HIBYTE(a5[3].__vftable) & 0x20) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, struct GASEnvironment *, unsigned int, _DWORD, GRefCountNTSImpl *))(**((_DWORD **)this + 628) + 16))(
            a1: *((_DWORD *)this + 628),
            a2: a4,
            a3: v11,
            a4: SBYTE2(a5[3].__vftable),
            a5: v21);
          v21 = v53;
        }
        if ( LOWORD(a5[3].__vftable) != 0 )
        {
          LOWORD(v22) = 1;
          buttonsState = (GMemAddressStub *)1;
          v54 = (SFTextObjectImpl *)1;
          do
          {
            if ( ((int)a5[3].__vftable & (unsigned __int16)v22) != 0 )
            {
              if ( (HIBYTE(a5[3].__vftable) & 0xC0) != 0 || LOWORD(a5[3].__vftable) == 0 )
                (*(void (__stdcall **)(struct GASEnvironment *, unsigned int, SFTextObjectImpl *, GRefCountNTSImpl *))(**((_DWORD **)this + 628) + 12))(
                  a1: a4,
                  a2: v11,
                  a3: v54,
                  a4: v21);
              else
                (*(void (__stdcall **)(struct GASEnvironment *, unsigned int, SFTextObjectImpl *, GRefCountNTSImpl *))(**((_DWORD **)this + 628) + 8))(
                  a1: a4,
                  a2: v11,
                  a3: v54,
                  a4: v21);
              v21 = v53;
            }
            if ( !v57 )
              break;
            v54 = (SFTextObjectImpl *)((char *)v54 + 1);
            v22 = (GMemAddressStub *)(2 * (_DWORD)buttonsState);
            buttonsState = v22;
          }
          while ( (_WORD)v22 != 0 );
        }
        if ( v21 != nullptr )
          GRefCountNTSImpl::Release(this: v21);
      }
    }
  }
  if ( GFxMouseState::IsTopmostEntityChanged(this: v52) )
  {
    v23 = 0;
    if ( pitemUnderMousePtra != nullptr )
      v23 = (*(int (__thiscall **)(unsigned int *))(*pitemUnderMousePtra + 348))(a1: pitemUnderMousePtra);
    GFxMovieRoot::ChangeMouseCursorType(this, mouseIdx: (const IDirect3DVertexDeclaration9 *)v11, newCursorType: v23);
  }
  if ( (HIBYTE(a5[3].__vftable) & 0xC0) != 0 || LOWORD(a5[3].__vftable) == 0 || ((int)a5[3].__vftable & 1) == 0 )
  {
    v27 = (GRefCountNTSImpl *)pitemUnderMousePtra;
    goto LABEL_84;
  }
  v24 = 52 * (*((unsigned __int8 *)this + v11 + 10228) + 181);
  v25 = *(IDirect3DVertexDeclaration9_vtbl **)((char *)&this->__vftable + v24);
  v56 = nullptr;
  if ( v25 != nullptr )
  {
    if ( v25[1] != 0 )
    {
      v26 = (GRefCountNTSImpl *)v25[1];
      v56 = (IDirect3DSwapChain9 *)v26;
      if ( v26 != nullptr )
      {
        ++v26->RefCount;
        ++v26->RefCount;
        GRefCountNTSImpl::Release(this: v26);
      }
    }
    else
    {
      v13 = (*v25)-- == 1;
      if ( v13 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v25);
      *(IDirect3DVertexDeclaration9_vtbl **)((char *)&this->__vftable + v24) = nullptr;
    }
  }
  v27 = (GRefCountNTSImpl *)pitemUnderMousePtra;
  if ( pitemUnderMousePtra != (unsigned int *)v56 )
  {
    if ( v56 != nullptr && ((unsigned __int8 (*)(void))v56->__vftable[5].GetRasterStatus)() != 0 )
    {
      if ( pitemUnderMousePtra == nullptr
        || (*(unsigned __int8 (__thiscall **)(unsigned int *))(*pitemUnderMousePtra + 224))(a1: pitemUnderMousePtra) == 0 )
      {
        GFxMovieRoot::QueueSetFocusTo(
          (ISteamRemoteStorage *)this,
          ch: nullptr,
          a3: (struct GFxASCharacter *)pitemUnderMousePtra,
          controllerIdx: v11,
          a5: 1);
        goto LABEL_81;
      }
      goto LABEL_80;
    }
    if ( pitemUnderMousePtra != nullptr
      && (*(unsigned __int8 (__thiscall **)(unsigned int *))(*pitemUnderMousePtra + 224))(a1: pitemUnderMousePtra) != 0 )
    {
LABEL_80:
      GFxMovieRoot::QueueSetFocusTo(
        (ISteamRemoteStorage *)this,
        ch: (const ISteamRemoteStorage *)pitemUnderMousePtra,
        a3: (struct GFxASCharacter *)pitemUnderMousePtra,
        controllerIdx: v11,
        a5: 1);
    }
  }
LABEL_81:
  if ( v56 != nullptr )
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v56);
LABEL_84:
  GFx_GenerateMouseButtonEvents(
    a1: v11,
    a2: v52,
    a3: (unsigned __int8)(*(_BYTE *)(*((_DWORD *)a4 + 30) + 684) - 1) != 0 ? 1 : 16);
  if ( v27 != nullptr )
    GRefCountNTSImpl::Release(this: v27);
  if ( v38 != nullptr )
  {
    GTimer::GetRawTicks(li: v28, a2: v35, a3: v37);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CC540
// Name: public: void GFxMovieRoot::AddStickyVariable(class GASString const __near &,class GASValue const __near &,enum GFxMovie::SetVarType)
// Source: json
//------------------------------------------------------------------------------
GSysAlloc *__userpurge GFxMovieRoot::AddStickyVariable@<eax>(
        int a1@<ecx>,
        int result,
        tagWNDCLASSW *val,
        _KTMOBJECT_CURSOR setType)
{
  GMemoryHeap *v4; // eax
  GMemoryHeap *v5; // eax
  unsigned int v6; // esi
  bool v7; // zf
  unsigned int Length; // eax
  _IMAGE_SYMBOL_EX *v9; // eax
  int v10; // eax
  unsigned int v11; // esi
  int v12; // eax
  int v13; // eax
  unsigned int v14; // esi
  int v15; // esi
  int v16; // edi
  int Index; // eax
  int v18; // eax
  const GList<GMemoryHeap> *v19; // esi
  const GList<GMemoryHeap> *pNext; // eax
  int v21; // ecx
  int (__thiscall *v22)(int, int, int *); // edx
  GList<GMemoryHeap> *v23; // eax
  const GList<GMemoryHeap> *v24; // eax
  int v25; // ecx
  int (__thiscall *v26)(int, int, int *); // edx
  int v27; // eax
  int v28; // esi
  tagWNDCLASSW *v29; // ecx
  GSysAlloc *NodeNumber; // eax
  _IMAGE_SYMBOL_EX varPath; // [esp+Ch] [ebp-20h] BYREF
  GMemoryHeap *name; // [esp+20h] [ebp-Ch] BYREF
  const GList<GMemoryHeap> *name_4; // [esp+24h] [ebp-8h] BYREF
  _SYSTEM_LOGICAL_PROCESSOR_INFORMATION::<unnamed_tag>::<unnamed_type_NumaNode> ppath; // [esp+28h] [ebp-4h] BYREF

  varPath.N.Name.Short = *(_DWORD *)(a1 + 9156);
  varPath.N.ShortName[4] = 8;
  ppath.NodeNumber = *(_DWORD *)(varPath.N.Name.Short + 8);
  ++*(_DWORD *)(ppath.NodeNumber + 8);
  v4 = *(GMemoryHeap **)(varPath.N.Name.Short + 8);
  *(_DWORD *)&varPath.Type = a1;
  name = v4;
  ++v4->pNext;
  if ( GASEnvironment::ParsePath(
         &varPath,
         a2: (const struct GASString *)result,
         (_SYSTEM_LOGICAL_PROCESSOR_INFORMATION::<unnamed_tag>::<unnamed_type_NumaNode>)&ppath,
         pvar: (_SYSTEM_LOGICAL_PROCESSOR_INFORMATION::<unnamed_tag>::<unnamed_type_NumaNode>)&name) )
  {
    if ( *(_DWORD *)(ppath.NodeNumber + 16) < 5u )
      goto LABEL_18;
    if ( **(_DWORD **)ppath.NodeNumber == 1869574751 && *(_BYTE *)(*(_DWORD *)ppath.NodeNumber + 4) == 116 )
    {
      Length = GASString::GetLength(this: (GASString *)&ppath);
      v9 = (_IMAGE_SYMBOL_EX *)GASString::Substring(a1: &ppath, a2: &varPath.SectionNumber, a3: 5, a4: Length);
      v10 = GASString::operator+(a1: (int)&result, str: v9);
      v11 = *(_DWORD *)v10;
      ++*(_DWORD *)(*(_DWORD *)v10 + 8);
      v7 = (*(_DWORD *)(ppath.NodeNumber + 8))-- == 1;
      if ( v7 )
        GASStringNode::ReleaseNode();
      ppath.NodeNumber = v11;
      v7 = (*(_DWORD *)(result + 8))-- == 1;
      if ( v7 )
        GASStringNode::ReleaseNode();
      v7 = (*(_DWORD *)(varPath.SectionNumber + 8))-- == 1;
      if ( v7 )
        GASStringNode::ReleaseNode();
    }
    v12 = *(_DWORD *)ppath.NodeNumber;
    if ( **(_DWORD **)ppath.NodeNumber != 1986358367 || *(_BYTE *)(v12 + 4) != 101 || *(_BYTE *)(v12 + 5) != 108 )
    {
LABEL_18:
      v13 = GASString::operator+(a1: (int)&result, str: (_IMAGE_SYMBOL_EX *)&ppath);
      v14 = *(_DWORD *)v13;
      ++*(_DWORD *)(*(_DWORD *)v13 + 8);
      v7 = (*(_DWORD *)(ppath.NodeNumber + 8))-- == 1;
      if ( v7 )
        GASStringNode::ReleaseNode();
      ppath.NodeNumber = v14;
      v7 = (*(_DWORD *)(result + 8))-- == 1;
      if ( v7 )
        GASStringNode::ReleaseNode();
    }
  }
  else
  {
    v5 = name;
    if ( name->RefCount == 0 )
      goto LABEL_37;
    v6 = *(_DWORD *)(varPath.N.Name.Short + 272);
    ++*(_DWORD *)(v6 + 8);
    v7 = (*(_DWORD *)(ppath.NodeNumber + 8))-- == 1;
    if ( v7 )
      GASStringNode::ReleaseNode();
    ppath.NodeNumber = v6;
  }
  v15 = *(_DWORD *)(*(_DWORD *)&varPath.Type + 9220);
  v16 = *(_DWORD *)&varPath.Type + 9220;
  name_4 = nullptr;
  if ( v15 != 0
    && (Index = GHashSetBase<GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>(
                  a1: &ppath,
                  a2: *(_DWORD *)(ppath.NodeNumber + 12) & *(_DWORD *)(v15 + 4))) >= 0
    && (v18 = v15 + 4 * (3 * Index + 3)) != 0
    && (v19 = *(const GList<GMemoryHeap> **)(v18 + 4)) != nullptr )
  {
    pNext = *(const GList<GMemoryHeap> **)(v18 + 4);
    name_4 = v19;
    do
    {
      if ( pNext->Root.pPrev == name )
      {
        GASValue::operator=(v: val);
        if ( LOBYTE(name_4[3].Root.pPrev) == 0 )
          LOBYTE(name_4[3].Root.pPrev) = setType.LastQuery.Data1 == 2;
        goto LABEL_36;
      }
      pNext = (const GList<GMemoryHeap> *)pNext[2].Root.pNext;
      name_4 = pNext;
    }
    while ( pNext != nullptr );
    v21 = *(_DWORD *)(*(_DWORD *)&varPath.Type + 32);
    v22 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v21 + 40);
    result = 323;
    v23 = (GList<GMemoryHeap> *)v22(a1: v21, a2: 28, a3: &result);
    if ( v23 == nullptr )
      goto LABEL_42;
    v24 = GFxMovieRoot::StickyVarNode::StickyVarNode(
            this: v23,
            (_IMAGE_SYMBOL_EX *)&name,
            value: val,
            permanent: setType.LastQuery.Data1 == 2);
    name_4 = v24;
    if ( v24 != nullptr )
    {
      v24[2].Root.pNext = v19[2].Root.pNext;
      v19[2].Root.pNext = (GMemoryHeap *)name_4;
    }
  }
  else
  {
    v25 = *(_DWORD *)(*(_DWORD *)&varPath.Type + 32);
    v26 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v25 + 40);
    result = 323;
    v27 = v26(a1: v25, a2: 28, a3: &result);
    v28 = v27;
    if ( v27 != 0 )
    {
      v29 = val;
      *(_DWORD *)v27 = name;
      ++name->pNext;
      GASValue::GASValue(this: (GASValue *)(v27 + 4), a2: (const struct GASValue *)v29);
      *(_BYTE *)(v28 + 24) = setType.LastQuery.Data1 == 2;
      varPath.SectionNumber = (int)&name_4;
      *(_DWORD *)(v28 + 20) = 0;
      name_4 = (const GList<GMemoryHeap> *)v28;
      varPath.Value = (unsigned int)&ppath;
      GHashSetBase<GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeHashF>>::Set<GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeRef>(
        a1: v16,
        a2: &varPath.Value);
    }
    else
    {
LABEL_42:
      name_4 = nullptr;
    }
  }
LABEL_36:
  v5 = name;
LABEL_37:
  v7 = v5->pNext-- == (GMemoryHeap *)1;
  if ( v7 )
    GASStringNode::ReleaseNode();
  NodeNumber = (GSysAlloc *)ppath.NodeNumber;
  v7 = (*(_DWORD *)(ppath.NodeNumber + 8))-- == 1;
  if ( v7 )
    return (GSysAlloc *)GASStringNode::ReleaseNode().Sid;
  return NodeNumber;
}

//------------------------------------------------------------------------------
// Address: 0x100CC820
// Name: public: void GFxMovieRoot::ResolveStickyVariables(class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::ResolveStickyVariables(
        _DWORD *this,
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *a2)
{
  int v3; // eax
  _DWORD *v4; // edi
  int v5; // esi
  _IMAGE_SYMBOL_EX *v6; // ebx
  int Index; // eax
  int v8; // esi
  _BYTE *v9; // esi
  int m_pfnProxied; // edi
  int (__thiscall *v11)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *, _BYTE *, _BYTE *, char *); // eax
  int v12; // eax
  _BYTE *v13; // edi
  _IMAGE_SYMBOL_EX *v15; // [esp+Ch] [ebp-1Ch] BYREF
  _DWORD *v16; // [esp+10h] [ebp-18h]
  _DWORD *v17; // [esp+14h] [ebp-14h]
  _IMAGE_SYMBOL_EX *path; // [esp+18h] [ebp-10h]
  _BYTE *v19; // [esp+1Ch] [ebp-Ch]
  _DWORD *v20; // [esp+20h] [ebp-8h] BYREF
  char v21; // [esp+27h] [ebp-1h] BYREF

  v3 = DWORD1(a2[6].m_pfnProxied);
  if ( v3 == 0 )
    GFxASCharacter::CreateCharacterHandle(this: a2);
  v4 = this + 2305;
  v5 = *(this + 2305);
  v6 = (_IMAGE_SYMBOL_EX *)(v3 + 12);
  path = (_IMAGE_SYMBOL_EX *)(v3 + 12);
  v17 = v4;
  if ( v5 != 0 )
  {
    Index = GHashSetBase<GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>(
              a1: v6,
              a2: *(_DWORD *)(v6->N.Name.Short + 12) & *(_DWORD *)(v5 + 4));
    if ( Index >= 0 )
    {
      v8 = v5 + 4 * (3 * Index + 3);
      if ( v8 != 0 )
      {
        v9 = *(_BYTE **)(v8 + 4);
        v16 = v9;
        v20 = nullptr;
        v19 = nullptr;
        if ( v9 != nullptr )
        {
          do
          {
            m_pfnProxied = a2[5].m_pfnProxied;
            v11 = *(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *, _BYTE *, _BYTE *, char *))(LODWORD(a2->m_pfnProxied) + 112);
            v21 = 0;
            v12 = v11(a1: a2, a2: v9, a3: v9 + 4, a4: &v21);
            (*(void (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *, int))(m_pfnProxied + 12))(
              a1: a2 + 5,
              a2: v12);
            v13 = *((_BYTE **)v9 + 5);
            if ( v9[24] != 0 )
            {
              if ( v20 != nullptr )
                *((_DWORD *)v19 + 5) = v9;
              else
                v20 = v9;
              v19 = v9;
              *((_DWORD *)v9 + 5) = 0;
            }
            else
            {
              GASValue::~GASValue(this: (GASValue *)v9 + 1);
              if ( (*(_DWORD *)(*(_DWORD *)v9 + 8))-- == 1 )
                GASStringNode::ReleaseNode();
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
            }
            v9 = v13;
          }
          while ( v13 != nullptr );
          if ( v20 != nullptr )
          {
            if ( v20 != v16 )
            {
              v15 = path;
              v16 = &v20;
              GHashSetBase<GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeHashF>>::Set<GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeRef>(
                a1: v17,
                a2: &v15);
            }
            return;
          }
          v6 = path;
        }
        GHashSetBase<GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeHashF>>::RemoveAlt<GASString>(a1: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CC960
// Name: public: virtual bool GFxMovieRoot::Invoke(char const __near *,class GFxValue __near *,class GFxValue const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxMovieRoot::Invoke(
        GFxMovieRoot *this,
        char *a2,
        struct GFxValue *a3,
        const struct GFxValue *a4,
        unsigned int numArgs)
{
  return GFxMovieRoot::Invoke(
           (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *)this,
           a2: *((struct GFxSprite **)this + 12),
           a3: (IDirect3D9 *)a2,
           a4: a3,
           a5: a4,
           numArgs);
}

//------------------------------------------------------------------------------
// Address: 0x100CCB50
// Name: public: virtual bool GFxLoadQueueEntryMT_LoadMovie::LoadFinished(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxLoadQueueEntryMT_LoadMovie::LoadFinished(GFxLoadQueueEntryMT_LoadMovie *this)
{
  int v2; // eax
  bool v3; // cl
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v5; // eax
  int v6; // eax
  int v7; // edi
  GRefCountNTSImpl *v8; // ecx
  int v9; // ecx
  unsigned int v10; // edx
  int v11; // eax
  _DWORD *v12; // edi
  _DWORD *i; // ecx
  int v14; // ecx
  int v15; // ebx
  struct GASObject *v16; // eax
  bool v17; // zf
  struct GASObject *v18; // edi
  _DWORD *v19; // ebx
  int v20; // eax
  int v21; // ebx
  CMatQueuedIndexBuffer *v22; // eax
  GRefCountNTSImpl *v23; // edi
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v24; // ecx
  unsigned int v25; // edx
  int v26; // eax
  GRefCountNTSImpl *v27; // ecx
  int v28; // eax
  struct GFxSprite *v29; // eax
  struct GFxSprite *v30; // ebx
  GRefCountNTSImpl *v31; // ecx
  int v32; // ecx
  int v33; // eax
  char v34; // al
  int v35; // eax
  unsigned int *v36; // ecx
  int v37; // ecx
  int (__thiscall *v38)(int, int, GFxTestStream **); // eax
  GFxFontLib::FontResult *v39; // eax
  GRefCountNTSImpl *v40; // edi
  int v41; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v42; // eax
  unsigned int v43; // ecx
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v44; // edx
  int v45; // eax
  GRefCountNTSImpl *v46; // ecx
  GFxTestStream *v47; // eax
  CFunctor *elem; // edx
  int v49; // eax
  struct GASObject *v50; // ecx
  int v51; // ecx
  int v52; // eax
  _TAPE_WMI_OPERATIONS *LevelMovie; // eax
  GFxFontLib *v54; // edi
  void (__thiscall *v55)(_DWORD *); // eax
  int v56; // eax
  _TAPE_WMI_OPERATIONS *v57; // eax
  GFxFontLib *v58; // edi
  struct GFxSprite *v59; // eax
  int v60; // eax
  void (__thiscall *v61)(_DWORD *); // eax
  int v62; // eax
  int v63; // eax
  int v64; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *pNode; // edx
  int v66; // [esp-4h] [ebp-2Ch]
  _TAPE_WMI_OPERATIONS *v67; // [esp+0h] [ebp-28h]
  unsigned __int8 *v68; // [esp+4h] [ebp-24h]
  CMatRenderContextBase *v69[2]; // [esp+Ch] [ebp-1Ch] BYREF
  GFxTestStream *v70; // [esp+14h] [ebp-14h] BYREF
  GFxTestStream *v71; // [esp+18h] [ebp-10h]
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v72; // [esp+1Ch] [ebp-Ch]
  struct GASObject *v73; // [esp+20h] [ebp-8h]
  bool v74; // [esp+27h] [ebp-1h]

  v2 = *((_DWORD *)this + 4);
  v3 = *(_DWORD *)(*((_DWORD *)this + 5) + 40) == 1;
  if ( *(_BYTE *)(v2 + 104) != 0 )
    return v3;
  if ( !v3 )
    return false;
  if ( *((_DWORD *)this + 8) == 0 )
  {
    v5 = *(CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(v2 + 20);
    if ( v5 != nullptr )
    {
      GFxCharacterHandle::ForceResolveCharacter(this: v5, a2: *((GFxMovieRoot **)this + 3));
      v7 = v6;
      if ( v6 != 0 )
        ++*(_DWORD *)(v6 + 4);
      v8 = *((GRefCountNTSImpl **)this + 8);
      if ( v8 != nullptr )
        GRefCountNTSImpl::Release(this: v8);
      *((_DWORD *)this + 8) = v7;
      if ( v7 == 0 )
        return true;
      *((_DWORD *)this + 9) = *(_DWORD *)(v7 + 16);
    }
  }
  v9 = *((_DWORD *)this + 3);
  v10 = *(_DWORD *)(v9 + 40);
  v11 = 0;
  if ( v10 == 0 )
    return true;
  v12 = *(_DWORD **)(v9 + 36);
  for ( i = v12; *i != 0; i += 2 )
  {
    if ( ++v11 >= v10 )
      return true;
  }
  v14 = v12[2 * v11 + 1];
  if ( v14 == 0 )
    return true;
  v15 = (*(int (__thiscall **)(int))(*(_DWORD *)v14 + 112))(a1: v14);
  v16 = GASValue::ToObject(this: (GASValue *)(*((_DWORD *)this + 4) + 28), a2: (const struct GASEnvironment *)v15);
  v17 = *(_BYTE *)(*(_DWORD *)(v15 + 120) + 684) == 1;
  v18 = v16;
  v19 = *(_DWORD **)(*((_DWORD *)this + 5) + 36);
  v74 = v17;
  v73 = v16;
  if ( v19 != nullptr )
  {
    if ( *((_DWORD *)this + 8) != 0 )
    {
      if ( (*(_BYTE *)(*((_DWORD *)this + 8) + 118) & 0x10) != 0 )
        return true;
      GFxCharacter::IsUnloading(this: *((CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> **)this
                                      + 8));
      if ( v34 != 0 )
        return true;
    }
    if ( *((_BYTE *)this + 40) == 0 )
    {
      v35 = *((_DWORD *)this + 4);
      v36 = *(unsigned int **)(v35 + 16);
      v71 = nullptr;
      if ( v36 == (unsigned int *)-1 )
      {
        if ( *(_DWORD *)(v35 + 20) != 0 )
        {
          v71 = *(GFxTestStream **)(*((_DWORD *)this + 8) + 32);
          if ( v71 == nullptr )
            return true;
        }
      }
      else
      {
        GFxMovieRoot::ReleaseLevelMovie(a1: *((_DWORD *)this + 3), level: v36, i: &v67->Method, a4: v68);
        *((_DWORD *)this + 9) = 0x40000;
      }
      v37 = *(_DWORD *)(*((_DWORD *)this + 3) + 32);
      v38 = *(int (__thiscall **)(int, int, GFxTestStream **))(*(_DWORD *)v37 + 40);
      v70 = (GFxTestStream *)322;
      v39 = (GFxFontLib::FontResult *)v38(a1: v37, a2: 488, a3: &v70);
      if ( v39 != nullptr )
        v40 = (GRefCountNTSImpl *)GFxSprite::GFxSprite(this: v39);
      else
        v40 = nullptr;
      if ( !v74 )
        v40[20].__vftable = (GRefCountNTSImpl_vtbl *)((int)v40[20].__vftable | 4);
      v41 = *((_DWORD *)this + 4);
      if ( *(_DWORD *)(v41 + 20) != 0 )
      {
        GFxASCharacter::AddToPlayList(
          this: v40,
          result: *((const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> **)this
          + 3));
        v40[3].__vftable = *(GRefCountNTSImpl_vtbl **)(*((_DWORD *)this + 8) + 24);
        v40[2].RefCount = *(_DWORD *)(*((_DWORD *)this + 8) + 20);
        v42 = *((CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> **)this
              + 8);
        v43 = (unsigned int)v42[6].m_pObject >> 14;
        v72 = v42;
        if ( (v43 & 1) == 0 )
        {
          v44 = v42;
          v45 = DWORD1(v42[6].m_pfnProxied);
          if ( v45 == 0 )
          {
            GFxASCharacter::CreateCharacterHandle(this: v44);
            if ( v45 == 0 )
              v45 = *(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(v72->m_pfnProxied) + 108))(a1: v72)
                              + 120);
          }
          ((void (__thiscall *)(GRefCountNTSImpl *, int))v40->__vftable[10].dtr_GRefCountImplCore)(a1: v40, a2: v45 + 8);
        }
        ((void (__thiscall *)(GFxTestStream *, _DWORD, GRefCountNTSImpl *))v71->__vftable[26].dtr_GRefCountImplCore)(
          a1: v71,
          a2: *((_DWORD *)this + 8),
          a3: v40);
      }
      else
      {
        GFxSprite::SetLevel(result: *(const GFxZlibSupportBase **)(v41 + 16));
        GFxMovieRoot::SetLevelMovie(
          this: *((GPtr<GFxTextKeyMap> **)this + 3),
          a2: (VertexShaderHandle_t__ *)v40,
          a3: *(GFxTextKeyMap **)(*((_DWORD *)this + 4) + 16),
          a4: v40);
        *(_DWORD *)(*((_DWORD *)this + 3) + 9332) &= ~0x100u;
      }
      ((void (__thiscall *)(GRefCountNTSImpl *, int))v40->__vftable[82].dtr_GRefCountImplCore)(a1: v40, a2: 1);
      ++v40->RefCount;
      v46 = *((GRefCountNTSImpl **)this + 8);
      if ( v46 != nullptr )
        GRefCountNTSImpl::Release(this: v46);
      v17 = v73 == nullptr;
      *((_DWORD *)this + 8) = v40;
      if ( !v17 )
      {
        v47 = (GFxTestStream *)((int (__thiscall *)(GRefCountNTSImpl *))v40->__vftable[28].dtr_GRefCountImplCore)(a1: v40);
        elem = v73->pNode[4].elem;
        v66 = *((_DWORD *)this + 8);
        v71 = v47;
        ((void (__thiscall *)(struct GASObject *, GFxTestStream *, int))elem)(a1: v73, a2: v47, a3: v66);
        v49 = *(_DWORD *)(v19[7] + 128);
        v50 = v73;
        *((_DWORD *)this + 11) = v49;
        ((void (__thiscall *)(struct GASObject *, GFxTestStream *, _DWORD, int, _DWORD))v50->pNode[6].elem)(
          a1: v73,
          a2: v71,
          a3: *((_DWORD *)this + 8),
          a4: v49,
          a5: *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v19[7] + 12) + 32) + 40));
      }
      *((_BYTE *)this + 40) = 1;
      GRefCountNTSImpl::Release(this: v40);
      v18 = v73;
    }
    if ( *((_DWORD *)this + 11) != *(_DWORD *)(v19[7] + 128) && v18 != nullptr )
    {
      v71 = (GFxTestStream *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 8) + 112))(a1: *((_DWORD *)this + 8));
      v51 = *(_DWORD *)(v19[7] + 128);
      *((_DWORD *)this + 11) = v51;
      ((void (__thiscall *)(struct GASObject *, GFxTestStream *, _DWORD, int, _DWORD))v18->pNode[6].elem)(
        a1: v18,
        a2: v71,
        a3: *((_DWORD *)this + 8),
        a4: v51,
        a5: *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v19[7] + 12) + 32) + 40));
    }
    if ( v74 && *((_BYTE *)this + 48) == 0 && (*(_DWORD *)(v19[7] + 116) & 0x100) != 0 )
    {
      v52 = *(_DWORD *)(*((_DWORD *)this + 4) + 16);
      if ( v52 == -1 )
        LevelMovie = GASObjectInterface::ToSprite(result: v67);
      else
        LevelMovie = (_TAPE_WMI_OPERATIONS *)GFxMovieRoot::GetLevelMovie(this: *((GFxMovieRoot **)this + 3), level: v52);
      if ( LevelMovie != nullptr )
        ++LevelMovie->DataBufferSize;
      v54 = (GFxFontLib *)LevelMovie;
      if ( LevelMovie != nullptr )
      {
        (*(void (__thiscall **)(_TAPE_WMI_OPERATIONS *, _DWORD))(LevelMovie->Method + 328))(a1: LevelMovie, a2: 0);
        v55 = *(void (__thiscall **)(_DWORD *))(*v19 + 20);
        v71 = *(GFxTestStream **)(v19[7] + 128);
        v55(a1: v19);
        GFxSprite::SetRootNodeLoadingStat(result: v71);
        GFxSprite::ExecuteFrame0Events(this: v54, a2: (unsigned int)v67);
        GFxMovieRoot::DoActions(this: *((ScaleformRenderer **)this + 3));
        if ( v73 != nullptr )
        {
          v56 = ((int (__thiscall *)(GFxFontLib *))v54->__vftable[14].dtr_GRefCountImplCore)(a1: v54);
          ((void (__thiscall *)(struct GASObject *, int, GFxFontLib *))v73->pNode[5].elem)(a1: v73, a2: v56, a3: v54);
        }
      }
      *((_BYTE *)this + 48) = 1;
      if ( v54 != nullptr )
        GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v54);
    }
    if ( (*(_DWORD *)(v19[7] + 116) & 3u) >= 2 )
    {
      if ( (*(_DWORD *)(v19[7] + 116) & 2) != 0 )
      {
        if ( *(_DWORD *)(*((_DWORD *)this + 4) + 16) == -1 )
        {
          v57 = GASObjectInterface::ToSprite(result: v67);
          if ( v57 != nullptr )
            ++v57->DataBufferSize;
          v58 = (GFxFontLib *)v57;
          GFxMovieRoot::ResolveStickyVariables(
            this: *((_DWORD **)this + 3),
            a2: *((CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> **)this
            + 8));
        }
        else
        {
          v59 = GFxMovieRoot::GetLevelMovie(
                  this: *((GFxMovieRoot **)this + 3),
                  level: *(_DWORD *)(*((_DWORD *)this + 4) + 16));
          if ( v59 != nullptr )
            ++*((_DWORD *)v59 + 1);
          v58 = (GFxFontLib *)v59;
        }
        if ( v58 != nullptr )
        {
          if ( !v74 )
            v58[10].__vftable = (GFxFontLib_vtbl *)((int)v58[10].__vftable & ~4u);
          if ( v73 != nullptr )
          {
            v60 = ((int (__thiscall *)(GFxFontLib *))v58->__vftable[14].dtr_GRefCountImplCore)(a1: v58);
            ((void (__thiscall *)(struct GASObject *, int, GFxFontLib *, _DWORD))v73->pNode[5].pNext)(
              a1: v73,
              a2: v60,
              a3: v58,
              a4: 0);
          }
          if ( *((_BYTE *)this + 48) == 0 )
          {
            ((void (__thiscall *)(GFxFontLib *, _DWORD))v58->__vftable[41].dtr_GRefCountImplCore)(a1: v58, a2: 0);
            v61 = *(void (__thiscall **)(_DWORD *))(*v19 + 20);
            v70 = *(GFxTestStream **)(v19[7] + 128);
            v61(a1: v19);
            GFxSprite::SetRootNodeLoadingStat(result: v70);
            GFxSprite::ExecuteFrame0Events(this: v58, a2: (unsigned int)v67);
            GFxMovieRoot::DoActions(this: *((ScaleformRenderer **)this + 3));
            if ( v73 != nullptr )
            {
              v62 = ((int (__thiscall *)(GFxFontLib *))v58->__vftable[14].dtr_GRefCountImplCore)(a1: v58);
              ((void (__thiscall *)(struct GASObject *, int, GFxFontLib *))v73->pNode[5].elem)(
                a1: v73,
                a2: v62,
                a3: v58);
            }
          }
          *((_BYTE *)this + 48) = 1;
          GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v58);
          return true;
        }
      }
      else if ( v73 != nullptr )
      {
        v63 = (*(int (__thiscall **)(_DWORD, _TAPE_WMI_OPERATIONS *))(**((_DWORD **)this + 8) + 112))(
                a1: *((_DWORD *)this + 8),
                a2: v67);
        v64 = *((_DWORD *)this + 8);
        pNode = v73->pNode;
        if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v19[7] + 12) + 32) + 128) == 4 )
        {
          ((void (__stdcall *)(int, int, const char *))pNode[6].pNext)(a1: v63, a2: v64, a3: "Error");
          return true;
        }
        ((void (__stdcall *)(int, int, const char *))pNode[6].pNext)(a1: v63, a2: v64, a3: "Canceled");
      }
      return true;
    }
    return false;
  }
  v20 = *((_DWORD *)this + 4);
  if ( *(_DWORD *)(v20 + 20) != 0 )
  {
    v21 = *(_DWORD *)(*((_DWORD *)this + 8) + 32);
    if ( v21 == 0 )
      return true;
    v22 = (CMatQueuedIndexBuffer *)(*(int (__thiscall **)(int, CMatRenderContextBase **, int))(*(_DWORD *)v21 + 92))(
                                     a1: v21,
                                     a2: v69,
                                     a3: 65537);
    GFxMovieDefImpl::GetCharacterCreateInfo(this: v22, rid: (_RATE_QUOTA_LIMIT *)v67, rh: (const IndexDesc_t *)v68);
    v68 = (unsigned __int8 *)v69[1];
    v67 = *((_TAPE_WMI_OPERATIONS **)this + 9);
    v23 = (GRefCountNTSImpl *)((int (__thiscall *)(CMatRenderContextBase *, int))v69[0]->Bind)(a1: v69[0], a2: v21);
    v23[3].__vftable = *(GRefCountNTSImpl_vtbl **)(*((_DWORD *)this + 8) + 24);
    v23[2].RefCount = *(_DWORD *)(*((_DWORD *)this + 8) + 20);
    v24 = *((CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> **)this
          + 8);
    v25 = (unsigned int)v24[6].m_pObject >> 14;
    v72 = v24;
    if ( (v25 & 1) == 0 )
    {
      v26 = DWORD1(v24[6].m_pfnProxied);
      if ( v26 == 0 )
      {
        GFxASCharacter::CreateCharacterHandle(this: v24);
        if ( v26 == 0 )
          v26 = *(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(v72->m_pfnProxied) + 108))(a1: v72)
                          + 120);
      }
      ((void (__thiscall *)(GRefCountNTSImpl *, int))v23->__vftable[10].dtr_GRefCountImplCore)(a1: v23, a2: v26 + 8);
    }
    GFxASCharacter::AddToPlayList(
      this: v23,
      result: *((const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> **)this
      + 3));
    (*(void (__thiscall **)(int, _DWORD, GRefCountNTSImpl *))(*(_DWORD *)v21 + 308))(
      a1: v21,
      a2: *((_DWORD *)this + 8),
      a3: v23);
    ++v23->RefCount;
    v27 = *((GRefCountNTSImpl **)this + 8);
    if ( v27 != nullptr )
      GRefCountNTSImpl::Release(this: v27);
    *((_DWORD *)this + 8) = v23;
    GRefCountNTSImpl::Release(this: v23);
    v18 = v73;
  }
  else
  {
    v28 = *(_DWORD *)(v20 + 16);
    if ( v28 != -1 )
    {
      v29 = GFxMovieRoot::GetLevelMovie(this: *((GFxMovieRoot **)this + 3), level: v28);
      v30 = v29;
      if ( v29 != nullptr )
        ++*((_DWORD *)v29 + 1);
      v31 = *((GRefCountNTSImpl **)this + 8);
      if ( v31 != nullptr )
        GRefCountNTSImpl::Release(this: v31);
      *((_DWORD *)this + 8) = v30;
    }
  }
  v32 = *((_DWORD *)this + 8);
  if ( v32 != 0 && v18 != nullptr )
  {
    v33 = (*(int (__thiscall **)(int))(*(_DWORD *)v32 + 112))(a1: v32);
    ((void (__thiscall *)(struct GASObject *, int, _DWORD, const char *, _DWORD))v18->pNode[6].pNext)(
      a1: v18,
      a2: v33,
      a3: *((_DWORD *)this + 8),
      a4: "URLNotFound",
      a5: 0);
  }
  if ( *(_DWORD *)(*((_DWORD *)this + 4) + 16) != -1 )
    GFxMovieRoot::ReleaseLevelMovie(
      a1: *((_DWORD *)this + 3),
      level: *(unsigned int **)(*((_DWORD *)this + 4) + 16),
      i: &v67->Method,
      a4: v68);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100CD1D0
// Name: public: GFxMovieRoot::GFxMovieRoot(class GFxMovieRoot::MemoryContextImpl __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::GFxMovieRoot(ScaleformRenderer *this@<ecx>, IShaderDevice *memContext, bool a3)
{
  GStatBag *v4; // ecx
  unsigned int v5; // eax
  GFxKeyboardState *v6; // eax
  char *v7; // edi
  GMemoryHeap *v8; // eax
  bool v9; // sf
  float EyeSeparationCm; // ecx
  int (__thiscall *v11)(_DWORD, int, int *); // edx
  int v12; // eax
  float v13; // edi
  IShaderAPI *v14; // ecx
  IShaderAPI *v15; // ecx
  unsigned __int8 v16; // al
  float *p_u; // ecx
  float v18; // ecx
  int (__thiscall *v19)(_DWORD, int, int *); // eax
  vc_attributes::PreAttribute *v20; // eax
  int v21; // eax
  int v22; // edi
  GRefCountNTSImpl *v23; // ecx
  float v24; // ecx
  int (__thiscall *v25)(_DWORD, int, int *); // edx
  _DWORD *v26; // eax
  int v27; // ecx
  int v28; // ecx
  float v29; // ecx
  int (__thiscall *v30)(_DWORD, int, int *); // eax
  _DWORD *v31; // eax
  float v32; // ecx
  int v33; // ecx
  float v34; // edi
  float v35; // ecx
  unsigned __int64 v36; // rax
  float v37; // ecx
  ScaleformRenderer **v38; // eax
  unsigned int v39; // ecx
  const void *Instance; // eax
  ScaleformUILogging *v41; // eax
  ScaleformUILogging *v42; // edi
  IShaderAPI *v43; // ecx
  const void *v44; // eax
  ScaleformUILogging *v45; // eax
  ScaleformUILogging *v46; // edi
  IShaderAPI *v47; // ecx
  ConVar *v48; // eax
  const CMaterialDict::MissingMaterial_t *v49; // [esp+0h] [ebp-2Ch]
  float v50; // [esp+0h] [ebp-2Ch]
  const ScaleformUILogging *v51; // [esp+0h] [ebp-2Ch]
  float *v52; // [esp+4h] [ebp-28h]
  int v53; // [esp+Ch] [ebp-20h] BYREF
  int v54; // [esp+10h] [ebp-1Ch] BYREF
  int v55; // [esp+14h] [ebp-18h] BYREF
  int v56; // [esp+18h] [ebp-14h] BYREF
  int v57; // [esp+1Ch] [ebp-10h] BYREF
  int v58; // [esp+20h] [ebp-Ch] BYREF
  int i; // [esp+24h] [ebp-8h] BYREF
  GFxKeyboardState *p_color; // [esp+28h] [ebp-4h]
  float memContexta; // [esp+34h] [ebp+8h]

  v4 = (GStatBag *)memContext;
  this->__vftable = (ScaleformRenderer_vtbl *)&GRefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Handlers.Root.pPrev = (GRendererEventHandler *)&GFxStateBag::`vftable';
  this->__vftable = (ScaleformRenderer_vtbl *)&GFxMovieRoot::`vftable'{for `GFxMovie'};
  this->Handlers.Root.pPrev = (GRendererEventHandler *)&GFxMovieRoot::`vftable'{for `GFxStateBag'};
  if ( memContext != nullptr )
  {
    GRefCountImpl::AddRef(this: memContext, a2: (VertexShaderHandle_t__ *)v49);
    v4 = (GStatBag *)memContext;
  }
  LODWORD(this->S3DParams.Distortion) = v4;
  this->S3DParams.DisplayDiagInches = 0.0;
  this->S3DParams.DisplayAspectRatio = 0.0;
  LODWORD(this->S3DParams.EyeSeparationCm) = v4->MemAllocOffset;
  this->S3DDisplay = StereoCenter;
  this->m_pDevice = nullptr;
  this->m_blendMode = Blend_None;
  this->m_blendModeStack.Data.Size = 0;
  this->m_blendModeStack.Data.Policy.Capacity = (unsigned int)&this->m_blendModeStack.Data.Policy;
  this->m_textures.pPrev = (GRendererNode *)&this->m_blendModeStack.Data.Policy;
  this->m_currentMatrix.M_[0][2] = 1.0;
  this->m_currentMatrix.M_[0][1] = 1.0;
  this->m_textures.pNext = nullptr;
  this->m_renderTargets.pPrev = nullptr;
  this->m_texturesLock.cs.DebugInfo = nullptr;
  this->m_renderTargets.pNext = nullptr;
  this->m_texturesLock.cs.RecursionCount = 1;
  this->m_texturesLock.cs.LockCount = 1;
  this->m_currentMatrix.M_[0][0] = 0.0;
  this->m_texturesLock.cs.SpinCount = 0;
  this->m_texturesLock.cs.LockSemaphore = nullptr;
  this->m_texturesLock.cs.OwningThread = nullptr;
  this->m_currentMatrix.M_[1][0] = 0.0;
  this->m_currentMatrix.M_[1][1] = 1.0;
  this->m_userMatrix.M_[1][2] = 0.0;
  this->m_viewportMatrix.M_[0][0] = 0.0;
  this->m_viewportMatrix.M_[0][1] = 0.0;
  this->m_viewportMatrix.M_[0][2] = 0.0;
  this->m_viewportMatrix.M_[0][3] = 0.0;
  this->m_viewportMatrix.M_[1][0] = 0.0;
  this->m_viewportMatrix.M_[1][1] = 0.0;
  this->m_viewportMatrix.M_[1][2] = 0.0;
  GMatrix2D::SetIdentity(result: v49);
  this->m_viewportMatrix.M_[3][1] = 0.0;
  this->m_viewportMatrix.M_[3][2] = 0.0;
  this->m_viewportMatrix.M_[3][3] = 3.4028235e38;
  this->m_currentCxform.M_[0][0] = 3.4028235e38;
  this->m_currentCxform.M_[1][1] = 0.0;
  this->m_currentCxform.M_[0][1] = 3.4028235e38;
  this->m_currentCxform.M_[2][0] = 0.0;
  this->m_currentCxform.M_[1][0] = 3.4028235e38;
  this->m_currentCxform.M_[2][1] = 0.0;
  this->m_currentCxform.M_[3][1] = 0.0;
  this->m_projection.M_[0][0] = 0.0;
  this->m_projection.M_[0][1] = 0.0;
  this->m_projection.M_[0][2] = 0.0;
  this->m_projection.M_[0][3] = 0.0;
  this->m_projection.M_[1][0] = 0.0;
  this->m_projection.M_[1][1] = 0.0;
  this->m_projection.M_[1][2] = 0.0;
  this->m_projection.M_[2][1] = 0.0;
  this->m_glyphVertexBuffer[81].x = 0.0;
  this->m_glyphVertexBuffer[81].y = 0.0;
  this->m_glyphVertexBuffer[83].x = 0.0;
  *(_WORD *)((char *)&this->m_glyphVertexBuffer[83].y + 1) = 0;
  LOBYTE(this->m_glyphVertexBuffer[83].y) = 0;
  HIBYTE(this->m_glyphVertexBuffer[83].y) = -1;
  this->m_glyphVertexBuffer[83].color.Raw = 0;
  this->m_glyphVertexBuffer[83].u = 0.0;
  this->m_glyphVertexBuffer[83].v = 0.0;
  this->m_glyphVertexBuffer[84].u = 0.0;
  *(float *)&this->m_glyphVertexBuffer[84].color.Raw = 0.0;
  LOBYTE(this->m_glyphVertexBuffer[85].x) &= 0xE0u;
  this->m_glyphVertexBuffer[84].v = 0.0;
  this->m_glyphVertexBuffer[84].y = 0.0;
  this->m_glyphVertexBuffer[84].x = 0.0;
  this->m_glyphVertexBuffer[85].y = 0.0;
  this->m_glyphVertexBuffer[85].color.Raw = 0;
  this->m_glyphVertexBuffer[85].u = 0.0;
  *(float *)&this->m_glyphVertexBuffer[86].color.Raw = 0.0;
  this->m_glyphVertexBuffer[86].u = 0.0;
  this->m_glyphVertexBuffer[86].x = 0.0;
  this->m_glyphVertexBuffer[85].v = 0.0;
  LOBYTE(this->m_glyphVertexBuffer[86].v) &= 0xE0u;
  this->m_glyphVertexBuffer[86].y = 0.0;
  this->m_glyphVertexBuffer[87].x = 0.0;
  this->m_glyphVertexBuffer[87].y = 0.0;
  this->m_glyphVertexBuffer[87].color.Raw = 0;
  this->m_glyphVertexBuffer[88].y = 0.0;
  LOBYTE(this->m_glyphVertexBuffer[88].u) &= 0xE0u;
  this->m_glyphVertexBuffer[88].x = 0.0;
  this->m_glyphVertexBuffer[88].color.Raw = 0;
  this->m_glyphVertexBuffer[87].v = 0.0;
  this->m_glyphVertexBuffer[87].u = 0.0;
  this->m_glyphVertexBuffer[88].v = 0.0;
  this->m_glyphVertexBuffer[89].x = 0.0;
  this->m_glyphVertexBuffer[89].y = 0.0;
  this->m_glyphVertexBuffer[90].x = 0.0;
  this->m_glyphVertexBuffer[90].color.Channels.Blue &= 0xE0u;
  this->m_glyphVertexBuffer[89].v = 0.0;
  this->m_glyphVertexBuffer[90].y = 0.0;
  this->m_glyphVertexBuffer[89].u = 0.0;
  this->m_glyphVertexBuffer[89].color.Raw = 0;
  LODWORD(this->m_glyphVertexBuffer[90].u) = 1;
  LODWORD(this->m_glyphVertexBuffer[90].v) = 1;
  this->m_glyphVertexBuffer[91].x = 0.0;
  p_color = (GFxKeyboardState *)&this->m_glyphVertexBuffer[91].color;
  for ( i = 3; i >= 0; --i )
    GFxKeyboardState::GFxKeyboardState(this: p_color++);
  *((_DWORD *)this + 2289) = 0;
  *((_BYTE *)this + 9164) = 0;
  *((_DWORD *)this + 2297) = 0;
  *((_WORD *)this + 4596) = 0;
  *((float *)this + 2300) = 0.0;
  *((_DWORD *)this + 2305) = 0;
  *((float *)this + 2299) = 0.0;
  *((float *)this + 2302) = 0.0;
  *((float *)this + 2301) = 0.0;
  i = 15;
  *((float *)this + 2304) = 0.0;
  *((float *)this + 2303) = 0.0;
  v5 = (unsigned int)memContext[2].__vftable;
  *((_DWORD *)this + 2307) = 0;
  *((_DWORD *)this + 2308) = 0;
  *((_DWORD *)this + 2306) = 0;
  *((_DWORD *)this + 2310) = 0;
  *((_DWORD *)this + 2311) = 0;
  *((_DWORD *)this + 2309) = 0;
  *((_DWORD *)this + 2313) = 0;
  *((_DWORD *)this + 2314) = 0;
  *((_DWORD *)this + 2312) = 0;
  *((_DWORD *)this + 2316) = 0;
  *((_DWORD *)this + 2317) = 0;
  *((_DWORD *)this + 2315) = 0;
  *((_DWORD *)this + 2319) = 0;
  *((_DWORD *)this + 2320) = 0;
  *((_DWORD *)this + 2318) = 0;
  *((_DWORD *)this + 2322) = 0;
  *((_DWORD *)this + 2323) = 0;
  *((_DWORD *)this + 2321) = 0;
  *((_DWORD *)this + 2329) = v5;
  *((_DWORD *)this + 2324) = 1;
  *((_DWORD *)this + 2328) = 1;
  *((_DWORD *)this + 2326) = 1;
  *((_DWORD *)this + 2325) = 0;
  *((_DWORD *)this + 2327) = 0;
  *((_DWORD *)this + 2330) = 0;
  *((_DWORD *)this + 2331) = 0;
  *((_DWORD *)this + 2332) = 0;
  *((_DWORD *)this + 2333) = 0;
  *((_DWORD *)this + 2334) = 0;
  *((_DWORD *)this + 2335) = 0;
  *((_DWORD *)this + 2336) = 0;
  *((_DWORD *)this + 2337) = 0;
  *((_DWORD *)this + 2338) = 0;
  *((_DWORD *)this + 2339) = 0;
  v6 = (GFxKeyboardState *)((char *)this + 9392);
  *((_DWORD *)this + 2344) = 0;
  *((_DWORD *)this + 2345) = 0;
  *((_DWORD *)this + 2346) = 0;
  p_color = (GFxKeyboardState *)((char *)this + 9392);
  v7 = (char *)this + 9404;
  while ( 1 )
  {
    LOBYTE(v6->__vftable) = 0;
    v8 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: v6);
    p_color = (GFxKeyboardState *)((char *)p_color + 52);
    *((_DWORD *)v7 - 2) = 0;
    *((_DWORD *)v7 - 1) = 0;
    *(_DWORD *)v7 = 0;
    *((_DWORD *)v7 + 1) = v8;
    *((_DWORD *)v7 + 2) = 0;
    *((_DWORD *)v7 + 3) = 0;
    *((_WORD *)v7 + 8) = 0;
    *((float *)v7 + 5) = 0.0;
    *((float *)v7 + 6) = 0.0;
    v7 += 52;
    v9 = --i < 0;
    *((float *)v7 - 6) = 0.0;
    *((float *)v7 - 5) = 0.0;
    *(v7 - 16) = 0;
    if ( v9 )
      break;
    v6 = p_color;
  }
  GFxIMEImm32Dll::GFxIMEImm32Dll(this: (char *)this + 10260);
  *((_DWORD *)this + 2577) = 0;
  *((_DWORD *)this + 2578) = 0;
  *((_DWORD *)this + 2333) |= 0x40180u;
  this->m_projection.M_[3][1] = 0.0;
  EyeSeparationCm = this->S3DParams.EyeSeparationCm;
  this->m_projection.M_[3][2] = 0.083333336;
  *((_DWORD *)this + 2563) = 0;
  *((_DWORD *)this + 2562) = 0;
  *((_DWORD *)this + 2561) = 0;
  this->m_projection.M_[2][3] = 0.0;
  this->m_projection.M_[3][0] = 0.0;
  this->m_projection.M_[3][3] = 0.0;
  *((_DWORD *)this + 2574) = 0;
  *((_DWORD *)this + 2576) = 0;
  v11 = *(int (__thiscall **)(_DWORD, int, int *))(*(_DWORD *)LODWORD(EyeSeparationCm) + 40);
  i = 2;
  v12 = v11(a1: LODWORD(EyeSeparationCm), a2: 52, a3: &i);
  v13 = *(float *)&v12;
  if ( v12 != 0 )
  {
    *(_DWORD *)v12 = &GRefCountImplCore::`vftable';
    *(_DWORD *)(v12 + 4) = 1;
    *(_DWORD *)(v12 + 8) = &GFxStateBag::`vftable';
    *(_DWORD *)(v12 + 16) = &GFxLogBase<GFxLoadProcess>::`vftable';
    *(_DWORD *)v12 = &GFxStateBagImpl::`vftable'{for `GRefCountBase<GFxStateBagImpl,2>'};
    *(_DWORD *)(v12 + 8) = &GFxStateBagImpl::`vftable'{for `GFxStateBag'};
    *(_DWORD *)(v12 + 16) = &GFxStateBagImpl::`vftable'{for `GFxLogBase<GFxStateBagImpl>'};
    *(_DWORD *)(v12 + 20) = 0;
    *(_DWORD *)(v12 + 24) = 0;
    GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)(v12 + 28), spinCount: 0);
    v14 = *(IShaderAPI **)(LODWORD(v13) + 20);
    if ( v14 != nullptr )
      GRefCountImpl::Release(this: v14);
    *(_DWORD *)(LODWORD(v13) + 20) = 0;
  }
  else
  {
    v13 = 0.0;
  }
  v15 = (IShaderAPI *)LODWORD(this->m_currentCxform.M_[3][1]);
  if ( v15 != nullptr )
    GRefCountImpl::Release(this: v15);
  this->m_currentCxform.M_[3][1] = v13;
  this->m_glyphVertexBuffer[91].y = 0.0;
  v16 = 0;
  p_u = &this->m_glyphVertexBuffer[172].u;
  do
  {
    *(_BYTE *)p_u = v16++;
    p_u += 415;
  }
  while ( v16 < 4u );
  v18 = this->S3DParams.EyeSeparationCm;
  v19 = *(int (__thiscall **)(_DWORD, int, int *))(*(_DWORD *)LODWORD(v18) + 40);
  v58 = 323;
  v20 = (vc_attributes::PreAttribute *)v19(a1: LODWORD(v18), a2: 692, a3: &v58);
  if ( v20 != nullptr )
  {
    GASGlobalContext::GASGlobalContext(this: v20);
    v22 = v21;
  }
  else
  {
    v22 = 0;
  }
  v23 = *((GRefCountNTSImpl **)this + 2289);
  if ( v23 != nullptr )
    GRefCountNTSImpl::Release(this: v23);
  *((_DWORD *)this + 2289) = v22;
  v24 = this->S3DParams.EyeSeparationCm;
  v25 = *(int (__thiscall **)(_DWORD, int, int *))(*(_DWORD *)LODWORD(v24) + 40);
  v57 = 323;
  v26 = (_DWORD *)v25(a1: LODWORD(v24), a2: 28, a3: &v57);
  if ( v26 != nullptr )
  {
    v27 = *((_DWORD *)this + 2289);
    *v26 = 0;
    v26[1] = 0;
    v26[2] = 0;
    v26[3] = 0;
    v26[4] = 0;
    v28 = *(_DWORD *)(v27 + 8);
    v26[5] = v28;
    ++*(_DWORD *)(v28 + 8);
    v26[6] = 0;
  }
  else
  {
    v26 = nullptr;
  }
  v29 = this->S3DParams.EyeSeparationCm;
  *((_DWORD *)this + 2290) = v26;
  v30 = *(int (__thiscall **)(_DWORD, int, int *))(*(_DWORD *)LODWORD(v29) + 40);
  v56 = 326;
  v31 = (_DWORD *)v30(a1: LODWORD(v29), a2: 32, a3: &v56);
  if ( v31 != nullptr )
  {
    v32 = this->m_currentCxform.M_[3][1];
    if ( v32 == 0.0 )
      v33 = 0;
    else
      v33 = LODWORD(v32) + 8;
    *v31 = &GRefCountImplCore::`vftable';
    v31[1] = 1;
    v31[2] = &GFxStateBag::`vftable';
    *v31 = &GFxFontManagerStates::`vftable'{for `GRefCountBaseNTS<GFxFontManagerStates,326>'};
    v31[2] = &GFxFontManagerStates::`vftable'{for `GFxStateBag'};
    v31[3] = 0;
    v31[4] = 0;
    v31[5] = 0;
    v31[6] = 0;
    v31[7] = v33;
    v34 = *(float *)&v31;
  }
  else
  {
    v34 = 0.0;
  }
  v35 = this->m_projection.M_[1][2];
  if ( v35 != 0.0 )
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)LODWORD(v35));
  this->m_projection.M_[1][2] = v34;
  this->m_currentMatrix.M_[1][2] = 1.0;
  *((_DWORD *)this + 2296) = 0;
  this->m_userMatrix.M_[0][0] = 1.0;
  this->m_blendModeStack.Data.Data = nullptr;
  this->m_userMatrix.M_[0][2] = 0.0;
  LODWORD(this->m_userMatrix.M_[1][0]) = 1;
  this->m_userMatrix.M_[0][1] = 0.0;
  this->m_userMatrix.M_[1][1] = 0.0;
  *((_DWORD *)this + 2556) = 1;
  *((_DWORD *)this + 2557) = 0;
  *((_DWORD *)this + 2558) = 0;
  *((_DWORD *)this + 2559) = 0;
  *((_DWORD *)this + 2560) = 0;
  *((_DWORD *)this + 2347) = 0;
  *((_DWORD *)this + 2564) = 0;
  GTimer::GetTicks(a1: v35, a2: v50, a3: v52);
  *((_QWORD *)this + 1170) = v36 / 0x3E8;
  *((_DWORD *)this + 2342) = 0;
  *((_DWORD *)this + 2343) = 0;
  this->m_viewportMatrix.M_[0][3] = 0.0;
  this->m_viewportMatrix.M_[1][0] = 0.0;
  v55 = 326;
  memContexta = 0.0 + 0.0;
  this->m_viewportMatrix.M_[1][1] = memContexta;
  this->m_viewportMatrix.M_[1][2] = memContexta;
  v37 = this->S3DParams.EyeSeparationCm;
  *((_DWORD *)this + 2295) = 0;
  this->m_projection.M_[1][3] = 0.0;
  this->m_projection.M_[2][0] = 0.0;
  v38 = (ScaleformRenderer **)(*(int (__thiscall **)(float, int, int *))(*(_DWORD *)LODWORD(v37) + 40))(
                                a1: COERCE_FLOAT(LODWORD(v37)),
                                a2: 4,
                                a3: &v55);
  if ( v38 != nullptr )
    *v38 = this;
  else
    v38 = nullptr;
  LODWORD(this->S3DParams.DisplayWidthCm) = v38;
  *((_DWORD *)this + 2575) = 0;
  Instance = GFxAmpServer::GetInstance(a1: v39);
  v54 = 2;
  v41 = (ScaleformUILogging *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                this: GMemory::pGlobalHeap,
                                a2: Instance,
                                a3: 160,
                                a4: &v54);
  if ( v41 != nullptr )
    v42 = GFxAmpViewStats::GFxAmpViewStats(this: v41, a2: v51);
  else
    v42 = nullptr;
  v43 = *((IShaderAPI **)this + 2577);
  if ( v43 != nullptr )
    GRefCountImpl::Release(this: v43);
  *((_DWORD *)this + 2577) = v42;
  v44 = GFxAmpServer::GetInstance(a1: (unsigned int)v43);
  v53 = 2;
  v45 = (ScaleformUILogging *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                this: GMemory::pGlobalHeap,
                                a2: v44,
                                a3: 160,
                                a4: &v53);
  if ( v45 != nullptr )
    v46 = GFxAmpViewStats::GFxAmpViewStats(this: v45, a2: v51);
  else
    v46 = nullptr;
  v47 = *((IShaderAPI **)this + 2578);
  if ( v47 != nullptr )
    GRefCountImpl::Release(this: v47);
  *((_DWORD *)this + 2578) = v46;
  v48 = (ConVar *)GFxAmpServer::GetInstance(a1: (unsigned int)v47);
  GFxAmpServer::AddMovie(this: v48, movie: (int)this);
  this->m_currentCxform.M_[3][0] = 55.0;
}

//------------------------------------------------------------------------------
// Address: 0x100CD970
// Name: public: virtual void GFxMovieRoot::SetMouseCursorCount(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::SetMouseCursorCount(GFxMovieRoot *this, unsigned int a2)
{
  unsigned int v2; // eax

  v2 = a2;
  if ( a2 > 4 )
    v2 = 4;
  *((_DWORD *)this + 625) = v2;
}

//------------------------------------------------------------------------------
// Address: 0x100CD990
// Name: public: virtual unsigned int GFxMovieRoot::GetMouseCursorCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxMovieRoot::GetMouseCursorCount(_DWORD *this)
{
  return *(this + 625);
}

//------------------------------------------------------------------------------
// Address: 0x100CD9A0
// Name: public: virtual void GFxMovieRoot::SetControllerCount(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::SetControllerCount(GFxMovieRoot *this, unsigned int a2)
{
  unsigned int v2; // eax

  v2 = a2;
  if ( a2 > 4 )
    v2 = 4;
  *((_DWORD *)this + 626) = v2;
}

//------------------------------------------------------------------------------
// Address: 0x100CD9C0
// Name: public: virtual unsigned int GFxMovieRoot::GetControllerCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxMovieRoot::GetControllerCount(_DWORD *this)
{
  return *(this + 626);
}

//------------------------------------------------------------------------------
// Address: 0x100CD9D0
// Name: public: virtual enum GFxMovieView::AlignType GFxMovieRoot::GetViewAlignment(void)const
// Source: json
//------------------------------------------------------------------------------
HRESULT __cdecl GFxMovieRoot::GetViewAlignment(IDirect3DResource9 *this)
{
  int v1; // ecx

  return *(_DWORD *)(v1 + 140);
}

//------------------------------------------------------------------------------
// Address: 0x100CD9E0
// Name: public: virtual void GFxMovieRoot::SetBackgroundColor(class GColor)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::SetBackgroundColor(GFxMovieRoot *this, struct GColor a2)
{
  *((struct GColor *)this + 588) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x100CD9F0
// Name: public: virtual float GFxMovieRoot::GetBackgroundAlpha(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxMovieRoot::GetBackgroundAlpha(ScaleformRenderer *this)
{
  return (float)((double)HIBYTE(this->m_glyphVertexBuffer[83].y) / 255.0);
}

//------------------------------------------------------------------------------
// Address: 0x100CDA20
// Name: public: virtual void __near * GFxMovieRoot::GetUserData(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxMovieRoot::GetUserData(GFxMovieRoot *this)
{
  return *((void **)this + 627);
}

//------------------------------------------------------------------------------
// Address: 0x100CDA30
// Name: public: virtual void GFxMovieRoot::SetUserData(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::SetUserData(GFxMovieRoot *this, void *a2)
{
  *((_DWORD *)this + 627) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x100CDA40
// Name: public: virtual void GFxMovieRoot::SetPerspectiveFOV(float)
// Source: json
//------------------------------------------------------------------------------
const CUtlMemory<unsigned char,int> *__thiscall GFxMovieRoot::SetPerspectiveFOV(int ecx0, IDirect3DResource9 *this)
{
  bool v3; // zf
  const CUtlMemory<unsigned char,int> *result; // eax
  GMatrix3D v5; // [esp+Ch] [ebp-44h] BYREF

  v3 = *(_DWORD *)(ecx0 + 200) == 0;
  *(float *)(ecx0 + 236) = *(float *)&this;
  if ( !v3 )
  {
    GMatrix3D::SetIdentity(this: &v5);
    return GRenderer::MakeViewAndPersp3D(result: (const CUtlMemory<unsigned char,int> *)(ecx0 + 144));
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CDAC0
// Name: public: virtual void GFxMovieRoot::SetVerboseAction(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::SetVerboseAction(_DWORD *this, const IDirect3DResource9 *result)
{
  if ( (_BYTE)result != 0 )
    *(this + 2333) |= 4u;
  else
    *(this + 2333) &= ~4u;
}

//------------------------------------------------------------------------------
// Address: 0x100CDAE0
// Name: public: virtual void GFxMovieRoot::SetActionErrorsSuppress(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::SetActionErrorsSuppress(_DWORD *this, const IDirect3DResource9 *result)
{
  if ( (_BYTE)result != 0 )
    *(this + 2333) |= 0x40u;
  else
    *(this + 2333) &= ~0x40u;
}

//------------------------------------------------------------------------------
// Address: 0x100CDB00
// Name: public: virtual class GFxStateBag __near * GFxMovieRoot::GetStateBagImpl(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxMovieRoot::GetStateBagImpl(GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *this)
{
  int v1; // eax

  v1 = *((_DWORD *)this + 58);
  if ( v1 != 0 )
    return (void *)(v1 + 8);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100CDB20
// Name: public: virtual bool GFxMovieRoot::IsMovieFocused(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxMovieRoot::IsMovieFocused(GFxMovieRoot *this)
{
  return (*((_DWORD *)this + 2333) & 0x40000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100CDB30
// Name: public: virtual class GRect<float> GFxMovieRoot::GetVisibleFrameRect(void)const
// Source: json
//------------------------------------------------------------------------------
IDirect3DResource9 *__userpurge GFxMovieRoot::GetVisibleFrameRect@<eax>(
        float *a1@<ecx>,
        IDirect3DResource9 *this,
        const _GUID *a3)
{
  *(float *)&this->__vftable = a1[36] / 20.0;
  *((float *)this + 1) = a1[37] / 20.0;
  *((float *)this + 2) = a1[38] / 20.0;
  *((float *)this + 3) = a1[39] / 20.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100CDB70
// Name: public: virtual class GRect<float> GFxMovieRoot::GetSafeRect(void)const
// Source: json
//------------------------------------------------------------------------------
IDirect3DResource9 *__userpurge GFxMovieRoot::GetSafeRect@<eax>(
        int a1@<ecx>,
        IDirect3DResource9 *this,
        const _GUID *a3)
{
  this->__vftable = *(IDirect3DResource9_vtbl **)(a1 + 160);
  *(this + 1) = *(IDirect3DResource9 *)(a1 + 164);
  *(this + 2) = *(IDirect3DResource9 *)(a1 + 168);
  *(this + 3) = *(IDirect3DResource9 *)(a1 + 172);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100CDBA0
// Name: public: virtual void GFxMovieRoot::SetSafeRect(class GRect<float> const __near &)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GFxMovieRoot::SetSafeRect(
        float *this,
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *rect)
{
  float *result; // eax
  float v3; // [esp+0h] [ebp-8h]
  float v4; // [esp+4h] [ebp-4h]
  int recta; // [esp+10h] [ebp+8h]

  result = (float *)rect;
  recta = rect->m_Memory.m_nAllocationCount;
  v4 = result[2];
  v3 = result[3];
  *(this + 40) = *result;
  *(this + 41) = *(float *)&recta;
  *(this + 42) = v4;
  *(this + 43) = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CDBF0
// Name: public: virtual void GFxMovieRoot::SetBackgroundAlpha(float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxMovieRoot::SetBackgroundAlpha(_BYTE *ecx0, IDirect3DResource9 *this)
{
  char result; // al

  result = (int)(*(float *)&this * 255.0);
  if ( result == -1 )
    result = -1;
  *(ecx0 + 2355) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CDC30
// Name: public: virtual void GFxMovieRoot::SetPerspective3D(class GMatrix3D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::SetPerspective3D(int ecx0, IDirect3DResource9 *this)
{
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // eax
  GMatrix3D *v5; // eax
  GMatrix3D *v6; // esi
  unsigned int i; // esi
  int v8; // [esp+8h] [ebp-4h] BYREF

  if ( *(_DWORD *)(ecx0 + 200) == 0 )
  {
    v3 = *(_DWORD *)(ecx0 + 32);
    v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
    v8 = 322;
    v5 = (GMatrix3D *)v4(a1: v3, a2: 64, a3: &v8);
    v6 = v5;
    if ( v5 != nullptr )
      GMatrix3D::SetIdentity(this: v5);
    else
      v6 = nullptr;
    *(_DWORD *)(ecx0 + 200) = v6;
  }
  qmemcpy(*(void **)(ecx0 + 200), this, 0x40u);
  for ( i = 0; i < *(_DWORD *)(ecx0 + 40); ++i )
    GFxCharacter::CreateMatrix3D(
      this: *(CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> **)(*(_DWORD *)(ecx0 + 36) + 8 * i + 4),
      pmat: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100CDCB0
// Name: public: virtual void GFxMovieRoot::SetView3D(class GMatrix3D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::SetView3D(int ecx0, IDirect3DResource9 *this)
{
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // eax
  GMatrix3D *v5; // eax
  GMatrix3D *v6; // esi
  unsigned int i; // esi
  int v8; // [esp+8h] [ebp-4h] BYREF

  if ( *(_DWORD *)(ecx0 + 204) == 0 )
  {
    v3 = *(_DWORD *)(ecx0 + 32);
    v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
    v8 = 322;
    v5 = (GMatrix3D *)v4(a1: v3, a2: 64, a3: &v8);
    v6 = v5;
    if ( v5 != nullptr )
      GMatrix3D::SetIdentity(this: v5);
    else
      v6 = nullptr;
    *(_DWORD *)(ecx0 + 204) = v6;
  }
  qmemcpy(*(void **)(ecx0 + 204), this, 0x40u);
  for ( i = 0; i < *(_DWORD *)(ecx0 + 40); ++i )
    GFxCharacter::CreateMatrix3D(
      this: *(CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> **)(*(_DWORD *)(ecx0 + 36) + 8 * i + 4),
      pmat: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100CDD30
// Name: public: void GFxMovieRoot::ProcessLoadMovieClip(class GFxLoadQueueEntry __near *,class GFxLoadStates __near *,class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::ProcessLoadMovieClip(
        ScaleformRenderer *this,
        VertexShaderHandle_t__ *pentry,
        unsigned int plentry,
        CImagePacker *plentry_4)
{
  struct GFxLog *v5; // edx
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v6; // ecx
  unsigned int v7; // eax
  int v8; // eax
  int v9; // esi
  GRefCountNTSImpl *v10; // ecx
  int v11; // eax
  char v12; // al
  int v13; // ecx
  IDirect3DDevice9 *m_pDevice; // edx
  unsigned int v15; // eax
  _DWORD *S3DDisplay; // ecx
  struct GFxSprite *LevelMovie; // eax
  int v18; // eax
  CUtlMemory<CImagePacker,int> *UrlStrGfx; // eax
  void *v20; // esi
  GRefCountNTSImpl *v21; // esi
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v22; // ecx
  struct GString v23; // eax
  char v24; // al
  void *v25; // esi
  struct GString v26; // eax
  void *v27; // esi
  struct GFxImageLoader *v28; // edi
  CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *MovieImage; // esi
  IShaderDevice *v30; // eax
  float EyeSeparationCm; // ecx
  int (__thiscall *v32)(_DWORD, int, GString *); // eax
  GFxFontLib::FontResult *v33; // eax
  unsigned int v34; // esi
  struct GFxMovieDefImpl *Movie_LoadState; // edi
  int v36; // eax
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v37; // edx
  bool v38; // zf
  const GFxZlibSupportBase *v39; // eax
  int v40; // esi
  CMatQueuedIndexBuffer *v41; // eax
  GStat::StatValue *v42; // edi
  const char *pName; // eax
  const struct GASEnvironment *v44; // edi
  struct GASObject *v45; // eax
  struct GASObject *v46; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // edx
  GStat::StatValue *v48; // esi
  void *v49; // esi
  void *v50; // esi
  CUtlMemory<CImagePacker,int> v51; // [esp-14h] [ebp-80h]
  CUtlMemory<CImagePacker,int> v52; // [esp-14h] [ebp-80h]
  _PSINJECTDATA v53; // [esp-4h] [ebp-70h]
  unsigned __int8 *v54; // [esp+4h] [ebp-68h]
  int v55; // [esp+Ch] [ebp-60h] BYREF
  int v56; // [esp+18h] [ebp-54h] BYREF
  int v57; // [esp+24h] [ebp-48h] BYREF
  GString v58[4]; // [esp+28h] [ebp-44h] BYREF
  GString v59; // [esp+38h] [ebp-34h] BYREF
  int filelength; // [esp+3Ch] [ebp-30h]
  BOOL bilinearImage; // [esp+40h] [ebp-2Ch] BYREF
  int v62; // [esp+44h] [ebp-28h]
  GString v63; // [esp+48h] [ebp-24h] BYREF
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v64; // [esp+4Ch] [ebp-20h]
  int v65; // [esp+50h] [ebp-1Ch]
  GStat::StatValue *poldChar; // [esp+54h] [ebp-18h]
  IShaderDevice *v67; // [esp+58h] [ebp-14h]
  GString v68; // [esp+5Ch] [ebp-10h] BYREF
  GFxFontLib *v69; // [esp+60h] [ebp-Ch]
  GString v70; // [esp+64h] [ebp-8h] BYREF
  char v71; // [esp+6Ah] [ebp-2h]
  bool userImageProtocol; // [esp+6Bh] [ebp-1h]
  int plentrya; // [esp+78h] [ebp+Ch]
  bool plentry_3; // [esp+7Bh] [ebp+Fh]

  GString::GString(result: (CImagePacker *)(pentry + 3));
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v68);
  v5 = *(struct GFxLog **)(plentry + 12);
  v6 = *((CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)pentry
       + 5);
  v7 = *(_DWORD *)(*(_DWORD *)(this->m_blendModeStack.Data.Size + 28) + 20);
  poldChar = nullptr;
  v65 = 0;
  v64 = (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v5;
  v58[2].HeapTypeBits = v7;
  v67 = nullptr;
  v69 = nullptr;
  userImageProtocol = false;
  if ( v6 == nullptr )
  {
    if ( *((_DWORD *)pentry + 4) == -1 )
    {
LABEL_106:
      v49 = (void *)(v68.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v68.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v49);
      v50 = (void *)(v70.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v70.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v50);
      return;
    }
    m_pDevice = this->m_pDevice;
    v15 = 0;
    if ( m_pDevice == nullptr )
      goto LABEL_12;
    S3DDisplay = (_DWORD *)this->S3DDisplay;
    while ( *S3DDisplay != *((_DWORD *)pentry + 4) )
    {
      ++v15;
      S3DDisplay += 2;
      if ( v15 >= (unsigned int)m_pDevice )
        goto LABEL_12;
    }
    if ( *(_DWORD *)(this->S3DDisplay + 8 * v15 + 4) != 0 )
    {
      LevelMovie = GFxMovieRoot::GetLevelMovie((GFxMovieRoot *)this, level: *((_DWORD *)pentry + 4));
    }
    else
    {
LABEL_12:
      if ( GFxMovieRoot::GetLevelMovie((GFxMovieRoot *)this, level: 0) == nullptr )
      {
LABEL_15:
        GFxMovieRoot::ReleaseLevelMovie(
          a1: (int)this,
          level: *((unsigned int **)pentry + 4),
          i: *(unsigned int **)&v53.InjectionPoint,
          a4: v54);
        v62 = 0x40000;
        goto LABEL_16;
      }
      LevelMovie = GFxMovieRoot::GetLevelMovie((GFxMovieRoot *)this, level: 0);
    }
    v18 = (*(int (__thiscall **)(struct GFxSprite *))(*(_DWORD *)LevelMovie + 92))(a1: LevelMovie);
    userImageProtocol = ((*(int (__thiscall **)(int))(*(_DWORD *)v18 + 44))(a1: v18) & 0x10) != 0;
    goto LABEL_15;
  }
  GFxCharacterHandle::ForceResolveCharacter(this: v6, a2: (GFxMovieRoot *)this);
  v9 = v8;
  if ( v8 != 0 )
    ++*(_DWORD *)(v8 + 4);
  poldChar = (GStat::StatValue *)v8;
  if ( v8 == 0 )
    goto LABEL_106;
  v65 = *(_DWORD *)(v8 + 32);
  v10 = (GRefCountNTSImpl *)v8;
  if ( v65 == 0 )
  {
LABEL_105:
    GRefCountNTSImpl::Release(this: v10);
    goto LABEL_106;
  }
  v11 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 92))(a1: v8);
  v12 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 44))(a1: v11);
  v13 = *(_DWORD *)(v9 + 16);
  userImageProtocol = (v12 & 0x10) != 0;
  v62 = v13;
LABEL_16:
  filelength = 0;
  if ( userImageProtocol )
  {
    UrlStrGfx = GetUrlStrGfx(a1: &v70, a2: (CUtlMemory<CImagePacker,int> *)&bilinearImage);
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v68,
      src: (int)UrlStrGfx,
      a3: *(int *)&v53.InjectionPoint);
    v20 = (void *)(bilinearImage & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((bilinearImage & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v20);
  }
  v21 = (GRefCountNTSImpl *)v69;
  if ( GString::GetLength(this: &v70) == 0 )
  {
    plentrya = *((_DWORD *)this + 2576);
    if ( plentrya == 0 )
      goto LABEL_65;
    while ( 1 )
    {
      v36 = *(_DWORD *)(plentrya + 16);
      v22 = *(CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(v36 + 60);
      if ( (unsigned int)v22 < *((_DWORD *)pentry + 15) )
      {
        v37 = *((CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)pentry
              + 4);
        if ( v37 != (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)-1 )
        {
          v22 = *(CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(v36 + 16);
          if ( v22 != (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)-1 )
          {
            v38 = v37 == v22;
            goto LABEL_59;
          }
        }
        v22 = *((CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)pentry
              + 5);
        if ( v22 != nullptr && *(_DWORD *)(v36 + 20) != 0 )
        {
          v38 = v22 == *(CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(v36 + 20);
LABEL_59:
          if ( v38 )
            *(_BYTE *)(v36 + 104) = 1;
        }
      }
      plentrya = *(_DWORD *)(plentrya + 4);
      if ( plentrya == 0 )
        goto LABEL_65;
    }
  }
  v38 = *(_BYTE *)((v70.HeapTypeBits & 0xFFFFFFFC) + 8) == 105;
  LOBYTE(bilinearImage) = 0;
  userImageProtocol = false;
  if ( !v38 && *(_BYTE *)((v70.HeapTypeBits & 0xFFFFFFFC) + 8) != 73 )
  {
LABEL_42:
    v34 = v58[2].HeapTypeBits | 0x10001;
    if ( *((_BYTE *)pentry + 24) != 0 )
      v34 = v58[2].HeapTypeBits | 0x210001;
    if ( GString::GetLength(this: &v68) != 0 )
    {
      v56 = 3;
      GString::GString(result: (CImagePacker *)&v68);
      GString::GString(result: plentry_4);
      v51.m_nGrowSize = v34;
      *(_QWORD *)&v51.m_pMemory = __PAIR64__(&v56, plentry);
      Movie_LoadState = GFxLoaderImpl::CreateMovie_LoadState(
                          a1: v51,
                          a2: nullptr,
                          a3: 0,
                          a4: *(struct GFxLoaderImpl::LoadStackItem **)&v53.InjectionPoint,
                          a5: (unsigned int)v54);
      v67 = (IShaderDevice *)Movie_LoadState;
      GFxURLBuilder::LocationInfo::~LocationInfo(result: *(const CFunctorData0 **)&v53.InjectionPoint);
      if ( Movie_LoadState != nullptr )
        goto LABEL_47;
    }
    v55 = 3;
    GString::GString(result: (CImagePacker *)&v70);
    GString::GString(result: plentry_4);
    v52.m_nGrowSize = v34;
    *(_QWORD *)&v52.m_pMemory = __PAIR64__(&v55, plentry);
    Movie_LoadState = GFxLoaderImpl::CreateMovie_LoadState(
                        a1: v52,
                        a2: nullptr,
                        a3: 0,
                        a4: *(struct GFxLoaderImpl::LoadStackItem **)&v53.InjectionPoint,
                        a5: (unsigned int)v54);
    v67 = (IShaderDevice *)Movie_LoadState;
    GFxURLBuilder::LocationInfo::~LocationInfo(result: *(const CFunctorData0 **)&v53.InjectionPoint);
    if ( Movie_LoadState != nullptr )
    {
LABEL_47:
      v22 = *(CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)Movie_LoadState + 7) + 12) + 32) + 40);
      filelength = (int)v22;
    }
    else
    {
      v22 = v64;
      if ( v64 != nullptr && *((_BYTE *)pentry + 24) == 0 )
        GFxLogBase<GFxLog>::LogScriptWarning(
          this: (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&v64->m_iRefs,
          pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&v64->m_iRefs,
          this_4: (int)"Error loading URL \"%s\"\n",
          this_8: (v70.HeapTypeBits & 0xFFFFFFFC) + 8);
    }
    goto LABEL_37;
  }
  GString::ToLower(this: (CUtlMemory<CImagePacker,int> *)&v70);
  v23.pData = GString::Substring(this: &v63, a2: &v59, a3: 0).pData;
  v24 = GString::operator==(this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v23.pData);
  v25 = (void *)(v59.HeapTypeBits & 0xFFFFFFFC);
  v71 = v24;
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v59.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v25);
  if ( v71 != 0 )
  {
    LOBYTE(bilinearImage) = 1;
  }
  else
  {
    v26.pData = GString::Substring(this: &v63, a2: &v58[3], a3: 0).pData;
    v71 = GString::operator==(this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v26.pData);
    GString::~GString(this: &v58[3]);
    if ( v71 == 0 )
      goto LABEL_30;
  }
  userImageProtocol = true;
LABEL_30:
  v27 = (void *)(v63.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v63.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v27);
  if ( !userImageProtocol )
    goto LABEL_42;
  v28 = (struct GFxImageLoader *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(LODWORD(this->m_currentCxform.M_[3][1])
                                                                             + 8)
                                                                 + 12))(
                                   a1: LODWORD(this->m_currentCxform.M_[3][1]) + 8,
                                   a2: 5);
  MovieImage = (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GFxLoaderImpl::LoadMovieImage(a1: (const char *)((v70.HeapTypeBits & 0xFFFFFFFC) + 8), a2: v28, a3: (struct GFxLog *)v64, a4: (struct GMemoryHeap *)LODWORD(this->S3DParams.EyeSeparationCm));
  if ( MovieImage != nullptr )
  {
    v53.DataBytes = plentry;
    GFxMovieRoot::CreateImageMovieDef(
      (ScaleformRenderer::FillStyle *)this,
      pimageResource: MovieImage,
      a3: bilinearImage,
      a4: (v70.HeapTypeBits & 0xFFFFFFFC) + 8,
      pls: v53);
    v67 = v30;
    GFxResource::Release(this: (IShaderDevice *)MovieImage);
  }
  else
  {
    v22 = v64;
    if ( v64 != nullptr )
      GFxLogBase<GFxLog>::LogScriptWarning(
        this: (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&v64->m_iRefs,
        pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&v64->m_iRefs,
        this_4: (int)"LoadMovieImageCallback failed to load image \"%s\"\n",
        this_8: (v70.HeapTypeBits & 0xFFFFFFFC) + 8);
  }
  if ( v28 != nullptr )
    GRefCountImpl::Release(this: (IShaderAPI *)v28);
LABEL_37:
  if ( v67 != nullptr )
  {
    EyeSeparationCm = this->S3DParams.EyeSeparationCm;
    v32 = *(int (__thiscall **)(_DWORD, int, GString *))(*(_DWORD *)LODWORD(EyeSeparationCm) + 40);
    v58[1].HeapTypeBits = 322;
    v33 = (GFxFontLib::FontResult *)v32(a1: LODWORD(EyeSeparationCm), a2: 488, a3: &v58[1]);
    if ( v33 != nullptr )
    {
      v21 = (GRefCountNTSImpl *)GFxSprite::GFxSprite(this: v33);
      v69 = (GFxFontLib *)v21;
    }
    else
    {
      v21 = nullptr;
      v69 = nullptr;
    }
  }
  else
  {
    v21 = (GRefCountNTSImpl *)v69;
  }
LABEL_65:
  v39 = *((const GFxZlibSupportBase **)pentry + 4);
  plentry_3 = v21 != nullptr;
  if ( v39 == (const GFxZlibSupportBase *)-1 )
  {
    if ( v21 != nullptr
      || (v40 = v65,
          v41 = (CMatQueuedIndexBuffer *)(*(int (__thiscall **)(int, int *, int))(*(_DWORD *)v65 + 92))(
                                           a1: v65,
                                           a2: &v57,
                                           a3: 65537),
          GFxMovieDefImpl::GetCharacterCreateInfo(
            this: v41,
            rid: *(_RATE_QUOTA_LIMIT **)&v53.InjectionPoint,
            rh: (const IndexDesc_t *)v54),
          *(_DWORD *)&v53.InjectionPoint = v62,
          v21 = (GRefCountNTSImpl *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v57 + 36))(a1: v57, a2: v40),
          v69 = (GFxFontLib *)v21,
          v21 != nullptr) )
    {
      GFxASCharacter::AddToPlayList(
        this: v21,
        result: (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)this);
      v42 = poldChar;
      v21[3].__vftable = (GRefCountNTSImpl_vtbl *)poldChar[1].IValue;
      v21[2].RefCount = (volatile int)v42[1].pName;
      if ( (v42[10].Type & 0x4000) == 0 )
      {
        pName = v42[9].pName;
        if ( pName == nullptr )
        {
          GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v42);
          if ( pName == nullptr )
            pName = *(const char **)((*(int (__thiscall **)(GStat::StatValue *))(v42->Type + 108))(a1: v42) + 120);
        }
        ((void (__thiscall *)(GRefCountNTSImpl *, const char *))v21->__vftable[10].dtr_GRefCountImplCore)(
          a1: v21,
          a2: pName + 8);
      }
      (*(void (__thiscall **)(int, GStat::StatValue *, GRefCountNTSImpl *))(*(_DWORD *)v65 + 312))(
        a1: v65,
        a2: v42,
        a3: v21);
      GFxMovieRoot::ResolveStickyVariables(
        this,
        a2: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v21);
      GFxASCharacter::ModifyOptimizedPlayListLocal<GFxSprite>(
        this: (int)v21,
        result: (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)this);
    }
LABEL_74:
    v44 = (const struct GASEnvironment *)(*(int (__thiscall **)(GRenderer::BlendType *))(*this->m_blendModeStack.Data.Data
                                                                                       + 112))(a1: this->m_blendModeStack.Data.Data);
    v45 = GASValue::ToObject(this: (GASValue *)pentry + 7, a2: v44);
    v46 = v45;
    if ( plentry_3 )
    {
      if ( v45 != nullptr )
      {
        ((void (__thiscall *)(struct GASObject *, const struct GASEnvironment *, GFxFontLib *))v45->pNode[4].elem)(
          a1: v45,
          a2: v44,
          a3: v69);
        ((void (__thiscall *)(struct GASObject *, const struct GASEnvironment *, GFxFontLib *, int, int))v46->pNode[6].elem)(
          a1: v46,
          a2: v44,
          a3: v69,
          a4: filelength,
          a5: filelength);
        ((void (__thiscall *)(struct GASObject *, const struct GASEnvironment *, GFxFontLib *, _DWORD))v46->pNode[5].pNext)(
          a1: v46,
          a2: v44,
          a3: v69,
          a4: 0);
      }
      GFxSprite::ExecuteFrame0Events(this: v69, a2: *(unsigned int *)&v53.InjectionPoint);
      GFxMovieRoot::DoActions(this);
      if ( v46 != nullptr )
        ((void (__thiscall *)(struct GASObject *, const struct GASEnvironment *, GFxFontLib *))v46->pNode[5].elem)(
          a1: v46,
          a2: v44,
          a3: v69);
    }
    else if ( v45 != nullptr )
    {
      v38 = GString::GetLength(this: &v70) == 0;
      pNext = v46->pNode[6].pNext;
      if ( v38 )
        ((void (__thiscall *)(struct GASObject *, const struct GASEnvironment *, GFxFontLib *, const char *, _DWORD))pNext)(
          a1: v46,
          a2: v44,
          a3: v69,
          a4: "Unknown error",
          a5: 0);
      else
        ((void (__thiscall *)(struct GASObject *, const struct GASEnvironment *, GFxFontLib *, const char *, _DWORD))pNext)(
          a1: v46,
          a2: v44,
          a3: v69,
          a4: "URLNotFound",
          a5: 0);
    }
    if ( GString::GetLength(this: &v70) != 0 )
    {
      v48 = poldChar;
    }
    else
    {
      if ( poldChar != nullptr )
        GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)poldChar);
      v48 = nullptr;
      GFxMovieRoot::MemoryContextImpl::HeapLimit::Collect(
        this: (GFxMovieRoot::MemoryContextImpl::HeapLimit *)(LODWORD(this->S3DParams.Distortion) + 24),
        a2: (struct GMemoryHeap *)LODWORD(this->S3DParams.EyeSeparationCm));
    }
    if ( v69 != nullptr )
      GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v69);
    if ( v67 != nullptr )
      GFxResource::Release(this: v67);
    if ( v48 == nullptr )
      goto LABEL_106;
    v10 = (GRefCountNTSImpl *)v48;
    goto LABEL_105;
  }
  if ( v21 != nullptr )
  {
    GFxSprite::SetLevel(result: v39);
    GFxMovieRoot::SetLevelMovie((GPtr<GFxTextKeyMap> *)this, a2: pentry, a3: *((GFxTextKeyMap **)pentry + 4), a4: v21);
    *((_DWORD *)this + 2333) &= ~0x100u;
    GFxMovieRoot::ResolveStickyVariables(
      this,
      a2: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v21);
  }
  if ( this->m_blendModeStack.Data.Data != nullptr || v64 == nullptr )
    goto LABEL_74;
  GFxLogBase<GFxLog>::LogScriptWarning(
    this: v22,
    pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&v64->m_iRefs,
    this_4: (int)"_level0 unloaded - no further playback possible\n",
    this_8: *(int *)&v53.InjectionPoint);
  if ( v21 != nullptr )
    GRefCountNTSImpl::Release(this: v21);
  if ( v67 != nullptr )
    GFxResource::Release(this: v67);
  if ( poldChar != nullptr )
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)poldChar);
  GString::~GString(this: &v68);
  GString::~GString(this: &v70);
}

//------------------------------------------------------------------------------
// Address: 0x100CE460
// Name: public: void GFxMovieRoot::ProcessLoadQueue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::ProcessLoadQueue(ScaleformRenderer *this)
{
  VertexShaderHandle_t__ *v2; // esi
  GFxLoadStates *v3; // eax
  float v4; // ecx
  struct GFxStateBag *v5; // edx
  IShaderAPI *States; // ebx
  char v7; // al
  int v8; // eax
  void *v9; // esi
  _DWORD *v10; // esi
  _DWORD *v11; // esi
  _DWORD *v12; // ebx
  int v13; // eax
  int v14; // [esp+Ch] [ebp-8h] BYREF
  GString v15; // [esp+10h] [ebp-4h] BYREF

  while ( *((_DWORD *)this + 2574) != 0 )
  {
    v2 = *((VertexShaderHandle_t__ **)this + 2574);
    *((VertexShaderHandle_t__ *)this + 2574) = *(_DWORD *)v2;
    v14 = 2;
    v3 = (GFxLoadStates *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 84, a3: &v14);
    if ( v3 != nullptr )
    {
      v4 = this->m_currentCxform.M_[3][1];
      if ( v4 == 0.0 )
        v5 = nullptr;
      else
        v5 = (struct GFxStateBag *)(LODWORD(v4) + 8);
      States = (IShaderAPI *)GFxLoadStates::GFxLoadStates(
                               this: v3,
                               a2: *(struct GFxLoaderImpl **)(this->m_blendModeStack.Data.Size + 20),
                               a3: v5,
                               a4: nullptr);
    }
    else
    {
      States = nullptr;
    }
    GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v15);
    if ( this->m_blendModeStack.Data.Data == nullptr
      || ((*(void (__thiscall **)(unsigned int))(*(_DWORD *)this->m_blendModeStack.Data.Size + 48))(a1: this->m_blendModeStack.Data.Size),
          GString::operator=(this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v15),
          GFxURLBuilder::ExtractFilePath(ppath: (const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(IMaterialInternal *),IMaterialInternal *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&v15),
          v7 == 0) )
    {
      GString::Clear(this: &v15);
    }
    v8 = *((_DWORD *)v2 + 1);
    if ( (v8 & 4) != 0 )
    {
      GFxMovieRoot::ProcessLoadVars(
        this,
        pentry: (unsigned int)v2,
        pls: (_PSINJECTDATA)__PAIR64__(&v15, (unsigned int)States));
    }
    else if ( (v8 & 8) != 0 )
    {
      GFxMovieRoot::ProcessLoadXML(
        this,
        pentry: (unsigned int)v2,
        pls: (_PSINJECTDATA)__PAIR64__(&v15, (unsigned int)States));
    }
    else if ( (v8 & 0x10) != 0 )
    {
      GFxMovieRoot::ProcessLoadCSS(
        this,
        pentry: (unsigned int)v2,
        pls: (_PSINJECTDATA)__PAIR64__(&v15, (unsigned int)States));
    }
    else
    {
      GFxMovieRoot::ProcessLoadMovieClip(
        this,
        pentry: v2,
        plentry: (unsigned int)States,
        plentry_4: (CImagePacker *)&v15);
    }
    GFxLoadQueueEntry::~GFxLoadQueueEntry(this: (int)v2);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
    v9 = (void *)(v15.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v15.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
    if ( States != nullptr )
      GRefCountImpl::Release(this: States);
  }
  v10 = *((_DWORD **)this + 2576);
  if ( v10 != nullptr )
  {
    while ( (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10) != 0 )
    {
      v10 = (_DWORD *)v10[1];
      if ( v10 == nullptr )
        goto LABEL_26;
    }
  }
  else
  {
LABEL_26:
    v11 = *((_DWORD **)this + 2576);
    while ( v11 != nullptr )
    {
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v11 + 4))(a1: v11) != 0 )
      {
        v12 = (_DWORD *)v11[1];
        if ( v12 != nullptr )
          v12[2] = v11[2];
        v13 = v11[2];
        if ( v13 != 0 )
          *(_DWORD *)(v13 + 4) = v12;
        if ( *((_DWORD **)this + 2576) == v11 )
          *((_DWORD *)this + 2576) = v12;
        (*(void (__thiscall **)(_DWORD *, int))*v11)(a1: v11, a2: 1);
        v11 = v12;
      }
      else
      {
        v11 = (_DWORD *)v11[1];
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CE620
// Name: public: void GFxMovieRoot::ProcessInput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::ProcessInput(ScaleformRenderer *this)
{
  ISteamRemoteStorage *v1; // edi
  GFxAmpViewStats *v2; // esi
  IDirect3DVertexDeclaration9 *v3; // ebx
  float v4; // ecx
  __int64 v5; // rax
  ISteamRemoteStorage_vtbl *v6; // ecx
  bool (__thiscall *FileWrite)(ISteamRemoteStorage *, const char *, const void *, int); // edx
  int (__thiscall *v8)(ISteamRemoteStorage_vtbl *); // eax
  unsigned int v9; // eax
  ISteamRemoteStorage_vtbl *v10; // ecx
  int v11; // esi
  int (__stdcall *Entry)(HINSTANCE__ *, char *, int); // eax
  ISteamRemoteStorage *v13; // eax
  _D3DDISPLAYMODE *TopMostEntity; // eax
  GRefCountNTSImpl *v15; // esi
  unsigned int v16; // eax
  float v17; // [esp+0h] [ebp-60h]
  float *v18; // [esp+4h] [ebp-5Ch]
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>::SysAllocContainer v19; // [esp+Ch] [ebp-54h] BYREF
  float v20; // [esp+18h] [ebp-48h]
  float v21; // [esp+1Ch] [ebp-44h]
  float v22; // [esp+20h] [ebp-40h]
  float v23; // [esp+24h] [ebp-3Ch]
  int v24; // [esp+28h] [ebp-38h]
  __int16 v25; // [esp+2Ch] [ebp-34h]
  __int64 v26; // [esp+30h] [ebp-30h]
  GFxAmpViewStats *v27; // [esp+38h] [ebp-28h]
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> result; // [esp+48h] [ebp-18h] BYREF
  char *psc; // [esp+50h] [ebp-10h]
  unsigned int mask; // [esp+54h] [ebp-Ch]
  unsigned int miceProceededMask; // [esp+58h] [ebp-8h] BYREF
  ISteamRemoteStorage *v32; // [esp+5Ch] [ebp-4h]

  v1 = (ISteamRemoteStorage *)this;
  v2 = *((GFxAmpViewStats **)this + 2577);
  v3 = nullptr;
  v27 = v2;
  if ( v2 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v2, swdHandle: 1u, a3: 0xBu);
    GTimer::GetRawTicks(li: v4, a2: v17, a3: v18);
    v26 = v5;
  }
  else
  {
    v26 = 0;
  }
  if ( v1[12].__vftable != nullptr )
  {
    v6 = v1[12].__vftable;
    FileWrite = v6->FileWrite;
    v20 = 0.0;
    v21 = 0.0;
    v24 = 0;
    v22 = 0.0;
    v25 = 0;
    v23 = 0.0;
    v8 = *((int (__thiscall **)(ISteamRemoteStorage_vtbl *))FileWrite + 28);
    v19.Data[0] = 0;
    v19.Data[1] = 0;
    *(_DWORD *)&v19.Initialized = -1;
    v9 = v8(a1: v6);
    v10 = v1[625].__vftable;
    mask = v9;
    psc = (char *)(v9 + 120);
    miceProceededMask = 0;
    v11 = (1 << (char)v10) - 1;
    while ( v1[578].__vftable != nullptr || v1[587].__vftable != nullptr )
    {
      Entry = (int (__stdcall *)(HINSTANCE__ *, char *, int))GFxInputEventsQueue::GetEntry(this: (GFxInputEventsQueue *)&v1[77]);
      if ( *(_DWORD *)Entry == 1 )
      {
        GFxMovieRoot::ProcessKeyboard(this: v1, (struct GASStringContext *)psc, event: Entry, a4: &v19);
      }
      else if ( *(_DWORD *)Entry == 0 )
      {
        GFxMovieRoot::ProcessMouse(
          this: (IDirect3DVertexDeclaration9 *)v1,
          a2: D3DBACKBUFFER_TYPE_MONO,
          a3: (unsigned int)v1,
          a4: (struct GASEnvironment *)mask,
          a5: (IDirect3DSwapChain9 *)Entry,
          pitemUnderMousePtr: &miceProceededMask);
      }
    }
    if ( ((int)v1[2333].__vftable & 0x80) != 0 && (miceProceededMask & v11) != v11 )
    {
      v3 = nullptr;
      mask = 1;
      if ( v1[625].__vftable != nullptr )
      {
        v13 = v1 + 593;
        v32 = v1 + 593;
        do
        {
          if ( (miceProceededMask & mask) == 0 && ((int)v13[4].__vftable & 0x10) != 0 )
          {
            v13->__vftable = v13[-1].__vftable;
            result.__vftable = (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>_vtbl *)v13[1].__vftable;
            result.pContainer = (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>::SysAllocContainer *)v13[2].__vftable;
            TopMostEntity = (_D3DDISPLAYMODE *)GFxMovieRoot::GetTopMostEntity(
                                                 this: (int)v1,
                                                 &result,
                                                 a3: *(float *)&v3,
                                                 testAll: false,
                                                 ignoreMC: 0);
            v15 = (GRefCountNTSImpl *)TopMostEntity;
            if ( TopMostEntity != nullptr )
              ++TopMostEntity->Height;
            GFxMouseState::SetTopmostEntity(this: (struct GWeakPtrProxy **)&v32[-4], result: TopMostEntity);
            if ( GFxMouseState::IsTopmostEntityChanged(this: (GFxMouseState *)&v32[-4]) )
            {
              v16 = 0;
              if ( v15 != nullptr )
                v16 = ((int (__thiscall *)(GRefCountNTSImpl *))v15->__vftable[87].dtr_GRefCountImplCore)(a1: v15);
              GFxMovieRoot::ChangeMouseCursorType(
                this: (IDirect3DVertexDeclaration9 *)v1,
                mouseIdx: v3,
                newCursorType: v16);
            }
            GFx_GenerateMouseButtonEvents(
              a1: (char)v3,
              a2: (struct GFxMouseState *)&v32[-4],
              a3: (unsigned __int8)(*(_BYTE *)(*(_DWORD *)psc + 684) - 1) != 0 ? 1 : 16);
            if ( v15 != nullptr )
              GRefCountNTSImpl::Release(this: v15);
            v13 = v32;
          }
          mask *= 2;
          v3 = (IDirect3DVertexDeclaration9 *)((char *)v3 + 1);
          v13 += 9;
          v32 = v13;
        }
        while ( (ISteamRemoteStorage_vtbl *)v3 < v1[625].__vftable );
      }
    }
    GFxMovieRoot::FinalizeProcessFocusKey(this: (GFxMovieRoot *)v1, a2: (GMemoryHeap *)v3, a3: (GRefCountNTSImpl *)&v19);
    this = (ScaleformRenderer *)v19.Data[1];
    v1[2333].__vftable = (ISteamRemoteStorage_vtbl *)((int)v1[2333].__vftable & ~0x80u);
    if ( this != nullptr )
      GRefCountNTSImpl::Release((GRefCountNTSImpl *)this);
    v2 = v27;
  }
  if ( v2 != nullptr )
  {
    GTimer::GetRawTicks(li: *(float *)&this, a2: v17, a3: v18);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CE850
// Name: public: virtual bool GFxMovieRoot::SetVariable(char const __near *,class GFxValue const __near &,enum GFxMovie::SetVarType)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::SetVariable(
        int a1@<ecx>,
        float a2@<edi>,
        _DWORD *ppathToVar,
        GFxValue *value,
        int setType)
{
  IShaderAPI *v6; // eax
  int v7; // esi
  GFxAmpViewStats *v8; // ecx
  float v9; // ecx
  __int64 v10; // rax
  int v11; // eax
  GFxValue *v12; // edx
  _DWORD *v13; // eax
  int v14; // edi
  __vc_attributes::propgetAttribute *v15; // eax
  char v16; // al
  float v18; // ecx
  _KTMOBJECT_CURSOR v19; // [esp-8h] [ebp-40h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *val; // [esp+20h] [ebp-18h] BYREF
  unsigned int v21; // [esp+30h] [ebp-8h] BYREF
  unsigned int _CurrentState; // [esp+34h] [ebp-4h] BYREF

  if ( *(_DWORD *)(a1 + 48) != 0 )
  {
    *(float *)&v19.LastQuery.Data2 = a2;
    if ( ppathToVar != nullptr )
    {
      v8 = *(GFxAmpViewStats **)(a1 + 10308);
      *(_DWORD *)&v19.ObjectIds[0].Data2 = v8;
      if ( v8 != nullptr )
      {
        GFxAmpViewStats::PushCallstack(this: v8, swdHandle: 1u, a3: 0x15u);
        GTimer::GetRawTicks(li: v9, a2, a3: *(float **)v19.LastQuery.Data4);
        *(_QWORD *)&v19.ObjectIdCount = v10;
      }
      else
      {
        *(_QWORD *)&v19.ObjectIdCount = 0;
      }
      _controlfp_s(&_CurrentState, newctrl: 0, mask: 0);
      _controlfp_s(_CurrentState: &v21, newctrl: 0x10000u, mask: 0x30000u);
      v11 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a1 + 48) + 112))(a1: *(_DWORD *)(a1 + 48));
      GASStringManager::CreateStringNode(this: *(const char **)(*(_DWORD *)(v11 + 120) + 636));
      v12 = value;
      ppathToVar = v13;
      ++v13[2];
      LOBYTE(val) = 0;
      GFxMovieRoot::GFxValue2ASValue(this: (GFxMovieRoot *)a1, a2: v12, a3: (struct GASValue *)&val);
      v14 = setType;
      v15 = (__vc_attributes::propgetAttribute *)(*(int (__thiscall **)(_DWORD, _DWORD **, CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **, _DWORD, bool))(**(_DWORD **)(a1 + 48) + 112))(
                                                   a1: *(_DWORD *)(a1 + 48),
                                                   a2: &ppathToVar,
                                                   a3: &val,
                                                   a4: 0,
                                                   a5: setType == 0);
      GASEnvironment::SetVariable(this: v15);
      if ( v16 == 0 && v14 != 0 || v14 == 2 )
      {
        v19.LastQuery.Data1 = v14;
        GFxMovieRoot::AddStickyVariable(a1, result: (int)&ppathToVar, (tagWNDCLASSW *)&val, setType: v19);
      }
      GASValue::~GASValue(this: &val);
      if ( ppathToVar[2]-- == 1 )
        GASStringNode::ReleaseNode();
      _controlfp_s(_CurrentState: (unsigned int *)&value, newctrl: _CurrentState, mask: 0x30000u);
      if ( *(_DWORD *)&v19.ObjectIds[0].Data2 != 0 )
      {
        GTimer::GetRawTicks(li: v18, a2: *(float *)&v19.LastQuery.Data2, a3: *(float **)v19.LastQuery.Data4);
        GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
      }
    }
    else
    {
      v6 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(a1 + 8) + 12))(a1: a1 + 8, a2: 4);
      if ( v6 != nullptr )
      {
        GRefCountImpl::Release(this: v6);
        v7 = (*(int (__thiscall **)(int, int))(*(_DWORD *)(a1 + 8) + 12))(a1: a1 + 8, a2: 4);
        GFxLogBase<GFxLog>::LogError(
          this: (GFxLogBase<GFxLog> *)(v7 + 12),
          pfmt: "Error: NULL pathToVar passed to SetVariable/SetDouble()\n");
        if ( v7 != 0 )
          GRefCountImpl::Release(this: (IShaderAPI *)v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CE9E0
// Name: public: virtual bool GFxMovieRoot::SetVariableArray(enum GFxMovie::SetArrayType,char const __near *,unsigned int,void const __near *,unsigned int,enum GFxMovie::SetVarType)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxMovieRoot::SetVariableArray(
        GFxMovieRoot *this,
        enum GFxMovie::SetArrayType a2,
        unsigned int a3,
        unsigned int a4,
        GFxValue *a5,
        unsigned int i,
        enum GFxMovie::SetVarType a7)
{
  GFxAmpViewStats *v9; // ecx
  float v10; // ecx
  __int64 v11; // rax
  __vc_attributes::max_isAttribute *v12; // esi
  int v13; // eax
  char v14; // al
  struct GASObject *v15; // eax
  struct GASObject *v16; // edi
  int v17; // ecx
  int (__thiscall *v18)(int, int, unsigned int *); // edx
  unsigned int v19; // eax
  struct GASObject *v20; // eax
  unsigned int v21; // ebx
  unsigned int v22; // esi
  unsigned int v23; // eax
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v24; // edx
  unsigned int v25; // eax
  unsigned int v26; // eax
  unsigned int v27; // ecx
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v28; // eax
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v29; // esi
  bool v30; // zf
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *StringNode; // eax
  unsigned int v32; // ecx
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v33; // esi
  enum GFxMovie::SetVarType v34; // esi
  GFxMovieRoot *v35; // ebx
  __vc_attributes::propgetAttribute *v36; // eax
  char v37; // al
  float v38; // ecx
  __int64 v39; // rax
  _BYTE v40[40]; // [esp-Ch] [ebp-BCh] BYREF
  GASValue v41[4]; // [esp+1Ch] [ebp-94h] BYREF
  GASValue v42; // [esp+2Ch] [ebp-84h] BYREF
  double v43; // [esp+30h] [ebp-80h]
  GASValue v44[4]; // [esp+3Ch] [ebp-74h] BYREF
  GASValue v45[4]; // [esp+4Ch] [ebp-64h] BYREF
  GASValue v46[4]; // [esp+5Ch] [ebp-54h] BYREF
  tagWNDCLASSW v47; // [esp+6Ch] [ebp-44h] BYREF
  GFxAmpViewStats *v48; // [esp+94h] [ebp-1Ch]
  unsigned int _CurrentState; // [esp+A4h] [ebp-Ch] BYREF
  char varname[4]; // [esp+A8h] [ebp-8h] BYREF
  GFxMovieRoot *v51; // [esp+ACh] [ebp-4h]

  v51 = this;
  if ( *((_DWORD *)this + 12) == 0 )
    return false;
  v9 = *((GFxAmpViewStats **)this + 2577);
  v48 = v9;
  if ( v9 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v9, swdHandle: 1u, a3: 0x16u);
    GTimer::GetRawTicks(li: v10, a2: *(float *)&v40[12], a3: *(float **)&v40[16]);
    *(_QWORD *)&v47.lpszMenuName = v11;
  }
  else
  {
    *(_QWORD *)&v47.lpszMenuName = 0;
  }
  _controlfp_s(&_CurrentState, newctrl: 0, mask: 0);
  _controlfp_s(_CurrentState: (unsigned int *)&v40[20], newctrl: 0x10000u, mask: 0x30000u);
  v12 = (__vc_attributes::max_isAttribute *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 12) + 112))(a1: *((_DWORD *)this + 12));
  *(_DWORD *)&v40[4] = a3;
  GASStringManager::CreateStringNode(this: *((const char **)v12[30].expression + 159));
  *(_DWORD *)&v40[4] = 0;
  *(_DWORD *)varname = v13;
  ++*(_DWORD *)(v13 + 8);
  LOBYTE(v47.hInstance) = 0;
  GASEnvironment::GetVariable(this: v12, varname);
  if ( v14 != 0
    && LOBYTE(v47.hInstance) == 6
    && (v15 = GASValue::ToObject(this: (GASValue *)&v47.hInstance, a2: (const struct GASEnvironment *)v12),
        v16 = v15,
        v15 != nullptr)
    && ((int (__thiscall *)(struct GASObject *))v15[2].pNode[1].pNext)(a1: &v15[2]) == 7 )
  {
    v16[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v16[1].pNode->pNext + 1) & 0x8FFFFFFF);
  }
  else
  {
    v17 = *((_DWORD *)this + 8);
    v18 = *(int (__thiscall **)(int, int, unsigned int *))(*(_DWORD *)v17 + 40);
    a3 = 323;
    if ( v18(a1: v17, a2: 76, &a3) != 0 )
    {
      v19 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 12) + 112))(a1: *((_DWORD *)this + 12));
      v20 = (struct GASObject *)GASArrayObject::GASArrayObject(
                                  penv: v19,
                                  a2: *(GMemoryHeap **)&v40[8],
                                  a3: *(const char **)&v40[12],
                                  a4: *(int *)&v40[16]);
    }
    else
    {
      v20 = nullptr;
    }
    v16 = v20;
  }
  v21 = a4;
  v22 = i;
  if ( a4 + i > v16[7].sequence )
    GASArrayObject::Resize(size: (void *)(a4 + i), a2: *(GMemoryHeap **)&v40[8]);
  switch ( a2 )
  {
    case SA_Int:
      v23 = 0;
      i = 0;
      if ( v22 != 0 )
      {
        while ( 1 )
        {
          v24 = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *)(&a5->pObjectInterface)[v23];
          LOBYTE(v46[0]) = 4;
          v46[1] = v24;
          GASArrayObject::SetElement(this: (GASArrayObject *)v16, a2: v21 + v23, a3: (const struct GASValue *)v46);
          GASValue::~GASValue(this: v46);
          if ( ++i >= v22 )
            break;
          v23 = i;
        }
      }
      break;
    case SA_Double:
      v26 = 0;
      i = 0;
      if ( v22 != 0 )
      {
        while ( 1 )
        {
          v43 = *(double *)&(&a5->pObjectInterface)[2 * v26];
          LOBYTE(v42) = 3;
          GASArrayObject::SetElement(this: (GASArrayObject *)v16, a2: v21 + v26, a3: (const struct GASValue *)&v42);
          GASValue::~GASValue(this: &v42);
          if ( ++i >= v22 )
            break;
          v26 = i;
        }
      }
      break;
    case SA_Float:
      v25 = 0;
      i = 0;
      if ( v22 != 0 )
      {
        while ( 1 )
        {
          *(double *)&v40[28] = *(float *)&(&a5->pObjectInterface)[v25];
          v40[24] = 3;
          GASArrayObject::SetElement(this: (GASArrayObject *)v16, a2: v21 + v25, a3: (const struct GASValue *)&v40[24]);
          GASValue::~GASValue(this: (GASValue *)&v40[24]);
          if ( ++i >= v22 )
            break;
          v25 = i;
        }
      }
      break;
    case SA_String:
      a3 = 0;
      if ( v22 != 0 )
      {
        do
        {
          *(_DWORD *)&v40[4] = (&a5->pObjectInterface)[a3];
          GASStringManager::CreateStringNode(this: *(const char **)(*((_DWORD *)v51 + 2289) + 636));
          v27 = a3;
          v29 = v28;
          ++v28->m_nGrowSize;
          LOBYTE(v44[0]) = 5;
          v44[1] = v28;
          ++v28->m_nGrowSize;
          GASArrayObject::SetElement(this: (GASArrayObject *)v16, a2: v21 + v27, a3: (const struct GASValue *)v44);
          GASValue::~GASValue(this: v44);
          v30 = v29->m_nGrowSize-- == 1;
          if ( v30 )
            GASStringNode::ReleaseNode();
          ++a3;
        }
        while ( a3 < i );
      }
      break;
    case SA_StringW:
      a3 = 0;
      if ( v22 != 0 )
      {
        do
        {
          StringNode = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *)GASStringManager::CreateStringNode(
                                                                                                    this: *(GASStringManager **)(*((_DWORD *)v51 + 2289) + 636),
                                                                                                    a2: (const wchar_t *)(&a5->pObjectInterface)[a3]);
          v32 = a3;
          v33 = StringNode;
          ++StringNode->m_nGrowSize;
          LOBYTE(v41[0]) = 5;
          v41[1] = StringNode;
          ++StringNode->m_nGrowSize;
          GASArrayObject::SetElement(this: (GASArrayObject *)v16, a2: v21 + v32, a3: (const struct GASValue *)v41);
          GASValue::~GASValue(this: v41);
          v30 = v33->m_nGrowSize-- == 1;
          if ( v30 )
            GASStringNode::ReleaseNode();
          ++a3;
        }
        while ( a3 < i );
      }
      break;
    case SA_Value:
      for ( i = 0; i < v22; ++i )
      {
        LOBYTE(v45[0]) = 0;
        GFxMovieRoot::GFxValue2ASValue(this: v51, a2: a5, a3: (struct GASValue *)v45);
        GASArrayObject::SetElement(this: (GASArrayObject *)v16, a2: v21 + i, a3: (const struct GASValue *)v45);
        GASValue::~GASValue(this: v45);
        ++a5;
      }
      break;
    default:
      break;
  }
  LOBYTE(v47.style) = 0;
  GASValue::SetAsObject(this: (GASValue *)&v47, a2: v16);
  v34 = a7;
  v35 = v51;
  v36 = (__vc_attributes::propgetAttribute *)(*(int (__thiscall **)(_DWORD, char *, tagWNDCLASSW *, _DWORD, bool))(**((_DWORD **)v51 + 12) + 112))(
                                               a1: *((_DWORD *)v51 + 12),
                                               a2: varname,
                                               a3: &v47,
                                               a4: 0,
                                               a5: a7 == SV_Normal);
  GASEnvironment::SetVariable(this: v36);
  HIBYTE(a5) = v37;
  if ( v37 == 0 && v34 != SV_Normal || v34 == SV_Permanent )
  {
    *(_DWORD *)&v40[4] = v34;
    GFxMovieRoot::AddStickyVariable(
      a1: (int)v35,
      result: (int)varname,
      val: &v47,
      setType: *(_KTMOBJECT_CURSOR *)&v40[4]);
  }
  GASValue::~GASValue(this: (GASValue *)&v47);
  GASValue::~GASValue(this: (GASValue *)&v47.hInstance);
  GRefCountBaseGC<323>::Release(a1: v16);
  v30 = (*(_DWORD *)(*(_DWORD *)varname + 8))-- == 1;
  if ( v30 )
    GASStringNode::ReleaseNode();
  _controlfp_s(_CurrentState: &i, newctrl: _CurrentState, mask: 0x30000u);
  if ( v48 != nullptr )
  {
    GTimer::GetRawTicks(li: v38, a2: *(float *)&v40[8], a3: *(float **)&v40[12]);
    *(_QWORD *)v40 = v39 - *(_QWORD *)&v47.lpszMenuName;
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
  return HIBYTE(a5);
}

//------------------------------------------------------------------------------
// Address: 0x100CEE30
// Name: public: virtual bool GFxMovieRoot::SetVariableArraySize(char const __near *,unsigned int,enum GFxMovie::SetVarType)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge GFxMovieRoot::SetVariableArraySize@<al>(
        GFxMovieRoot *this@<ecx>,
        int a2@<ebx>,
        int a3,
        void *size,
        enum GFxMovie::SetVarType a5)
{
  int v6; // eax
  GFxAmpViewStats *v8; // ecx
  float v9; // ecx
  int v10; // edx
  int v11; // ecx
  __vc_attributes::max_isAttribute *v12; // esi
  int v13; // eax
  int v14; // ecx
  int (__thiscall *v15)(int, int, int *); // edx
  unsigned int v16; // eax
  struct GASObject *v17; // esi
  enum GFxMovie::SetVarType v18; // ebx
  __vc_attributes::propgetAttribute *v19; // eax
  char v20; // al
  float v21; // eax
  bool v22; // zf
  float v23; // ecx
  __int64 v24; // rax
  _BYTE v25[40]; // [esp-10h] [ebp-50h]
  GASValue v26[4]; // [esp+1Ch] [ebp-24h] BYREF
  GASValue v27; // [esp+2Ch] [ebp-14h] BYREF
  char varname[4]; // [esp+3Ch] [ebp-4h] BYREF

  v6 = 0;
  if ( *((_DWORD *)this + 12) == 0 )
    return false;
  v8 = *((GFxAmpViewStats **)this + 2577);
  *(_DWORD *)&v25[12] = a2;
  *(_DWORD *)&v25[28] = v8;
  *(_DWORD *)&v25[32] = 1;
  *(_DWORD *)&v25[36] = 23;
  if ( v8 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v8, swdHandle: 1u, a3: 0x17u);
    GTimer::GetRawTicks(li: v9, a2: *(float *)&v25[12], a3: *(float **)&v25[16]);
    *(_DWORD *)&v25[24] = v10;
  }
  else
  {
    *(_DWORD *)&v25[24] = 0;
  }
  v11 = *((_DWORD *)this + 12);
  *(_DWORD *)&v25[20] = v6;
  v12 = (__vc_attributes::max_isAttribute *)(*(int (__thiscall **)(int))(*(_DWORD *)v11 + 112))(a1: v11);
  *(_DWORD *)&v25[4] = a3;
  GASStringManager::CreateStringNode(this: *((const char **)v12[30].expression + 159));
  *(_DWORD *)&v25[4] = 0;
  *(_DWORD *)varname = v13;
  ++*(_DWORD *)(v13 + 8);
  LOBYTE(v27) = 0;
  GASEnvironment::GetVariable(this: v12, varname);
  v14 = *((_DWORD *)this + 8);
  v15 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v14 + 40);
  a3 = 323;
  if ( v15(a1: v14, a2: 76, &a3) != 0 )
  {
    v16 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 12) + 112))(a1: *((_DWORD *)this + 12));
    v17 = (struct GASObject *)GASArrayObject::GASArrayObject(
                                penv: v16,
                                a2: *(GMemoryHeap **)&v25[8],
                                a3: *(const char **)&v25[12],
                                a4: *(int *)&v25[16]);
  }
  else
  {
    v17 = nullptr;
  }
  GASArrayObject::Resize(size, a2: *(GMemoryHeap **)&v25[8]);
  LOBYTE(v26[0]) = 0;
  GASValue::SetAsObject(this: v26, a2: v17);
  v18 = a5;
  v19 = (__vc_attributes::propgetAttribute *)(*(int (__thiscall **)(_DWORD, char *, GASValue *, _DWORD, bool))(**((_DWORD **)this + 12) + 112))(
                                               a1: *((_DWORD *)this + 12),
                                               a2: varname,
                                               a3: v26,
                                               a4: 0,
                                               a5: a5 == SV_Normal);
  GASEnvironment::SetVariable(this: v19);
  HIBYTE(size) = v20;
  if ( v20 == 0 && v18 != SV_Normal || v18 == SV_Permanent )
  {
    *(_DWORD *)&v25[4] = v18;
    GFxMovieRoot::AddStickyVariable(
      a1: (int)this,
      result: (int)varname,
      val: (tagWNDCLASSW *)v26,
      setType: *(_KTMOBJECT_CURSOR *)&v25[4]);
  }
  GASValue::~GASValue(this: v26);
  GASValue::~GASValue(this: &v27);
  if ( v17 != nullptr )
    GRefCountBaseGC<323>::Release(a1: v17);
  v21 = *(float *)varname;
  v22 = (*(_DWORD *)(*(_DWORD *)varname + 8))-- == 1;
  v23 = v21;
  if ( v22 )
    GASStringNode::ReleaseNode();
  if ( *(_DWORD *)&v25[28] != 0 )
  {
    GTimer::GetRawTicks(li: v23, a2: *(float *)&v25[8], a3: *(float **)&v25[12]);
    *(_QWORD *)v25 = v24 - *(_QWORD *)&v25[20];
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
  return HIBYTE(size);
}

//------------------------------------------------------------------------------
// Address: 0x100CF1A0
// Name: public: virtual float GFxMovieRoot::Advance(float,unsigned int)
// Source: json
//------------------------------------------------------------------------------
double __userpurge GFxMovieRoot::Advance@<st0>(
        IDirect3DResource9 *this@<ecx>,
        float a2@<ebx>,
        CDefaultClientRenderable *a3@<edi>,
        float deltaT,
        unsigned int frameCatchUpCount)
{
  int v7; // esi
  GFxAmpViewStats *v8; // ecx
  float v9; // ecx
  __int64 v10; // rax
  int v11; // ecx
  IShaderAPI *v12; // ecx
  int v13; // edi
  IShaderAPI *v14; // ecx
  int v15; // edi
  IShaderAPI *v16; // ecx
  int v17; // edi
  IShaderAPI *v18; // ecx
  int v19; // edi
  IShaderAPI *v20; // ecx
  unsigned int i; // edi
  int v22; // ecx
  IShaderAPI *v23; // ecx
  int v24; // edi
  IShaderAPI *v25; // ecx
  ILoggingResponsePolicy *v26; // edx
  CMemberFuncProxy2<CMaterialVar *,void (__thiscall CMaterialVar::*)(float,int),float,int,CFuncMemPolicyNone> *v27; // eax
  IShaderAPI *v28; // edi
  IShaderAPI *v29; // eax
  int v30; // ecx
  IShaderDevice *v31; // eax
  int j; // edi
  unsigned int v33; // edi
  GRefCountNTSImpl *v34; // ebx
  int v35; // ecx
  float v36; // ecx
  IShaderAPI *v37; // ecx
  IShaderAPI *v38; // ecx
  float v39; // ecx
  int k; // edi
  unsigned __int64 v41; // rax
  double v42; // st7
  bool v43; // cf
  unsigned int v44; // ebx
  unsigned __int64 v45; // rax
  unsigned int v46; // edi
  int v47; // edx
  GASIntervalTimer *v48; // ecx
  unsigned int v49; // eax
  int v50; // ebx
  GASIntervalTimer **v51; // eax
  GASIntervalTimer *v52; // edi
  int v53; // eax
  _DWORD *v54; // eax
  int v55; // edi
  unsigned int v56; // ecx
  _DWORD *v57; // eax
  IDirect3DResource9 *v58; // ebx
  IDirect3DResource9_vtbl *v59; // eax
  GRefCountNTSImpl **v60; // ecx
  GRefCountNTSImpl *v61; // ebx
  double v62; // st7
  unsigned int v63; // ebx
  GRefCountNTSImpl **v64; // ebx
  int v65; // ecx
  unsigned int v66; // eax
  _DWORD *v67; // ecx
  char *v68; // edi
  int v69; // ecx
  long double v70; // st7
  long double v71; // st7
  double v72; // st7
  _DWORD *v73; // eax
  unsigned int v74; // ecx
  unsigned int v75; // edi
  char *v76; // ebx
  _DWORD *v77; // eax
  int v78; // eax
  int v79; // ecx
  GRefCountNTSImpl *v80; // ecx
  void (*dtr_GRefCountImplCore)(void); // eax
  double v82; // st7
  unsigned int v83; // eax
  GMemoryHeap *v84; // ecx
  int v85; // edi
  int v86; // eax
  int *v87; // edx
  char *v88; // ecx
  char *v89; // edi
  GRefCountNTSImpl **v90; // eax
  int v91; // ecx
  unsigned int v92; // eax
  _DWORD *v93; // ecx
  char *v94; // edi
  int v95; // eax
  unsigned int v96; // ecx
  GRefCountNTSImpl *StatId; // ecx
  GStatBag::Iterator *v98; // edi
  unsigned int GroupId; // eax
  GRefCountNTSImpl **v100; // ebx
  double v101; // st7
  __int64 v102; // rax
  unsigned __int64 v103; // rax
  double v104; // st7
  IShaderAPI *v105; // ecx
  IShaderAPI *v106; // ecx
  float v107; // ecx
  CDefaultClientRenderable *v108; // [esp+1Ch] [ebp-A8h]
  const GPtr<GFxZlibSupportBase> *v109; // [esp+1Ch] [ebp-A8h]
  float v110; // [esp+1Ch] [ebp-A8h]
  float v111; // [esp+1Ch] [ebp-A8h]
  float *v112; // [esp+20h] [ebp-A4h]
  float *v113; // [esp+20h] [ebp-A4h]
  float *v114; // [esp+20h] [ebp-A4h]
  float *v115; // [esp+24h] [ebp-A0h]
  unsigned int v116; // [esp+28h] [ebp-9Ch] BYREF
  unsigned int v117; // [esp+2Ch] [ebp-98h] BYREF
  unsigned int v118; // [esp+30h] [ebp-94h] BYREF
  __int64 v119; // [esp+34h] [ebp-90h]
  GFxAmpViewStats *v120; // [esp+3Ch] [ebp-88h]
  int v121; // [esp+4Ch] [ebp-78h] BYREF
  int v122; // [esp+50h] [ebp-74h] BYREF
  int v123; // [esp+54h] [ebp-70h] BYREF
  int v124; // [esp+58h] [ebp-6Ch]
  int v125; // [esp+5Ch] [ebp-68h]
  IShaderAPI *v126; // [esp+60h] [ebp-64h]
  int v127; // [esp+64h] [ebp-60h]
  CMemberFuncProxy2<CMaterialVar *,void (__thiscall CMaterialVar::*)(float,int),float,int,CFuncMemPolicyNone> *v128; // [esp+68h] [ebp-5Ch]
  ILoggingResponsePolicy *v129; // [esp+6Ch] [ebp-58h]
  IShaderAPI *v130; // [esp+70h] [ebp-54h]
  IShaderAPI *v131; // [esp+74h] [ebp-50h]
  int v132; // [esp+78h] [ebp-4Ch]
  int v133; // [esp+7Ch] [ebp-48h]
  unsigned int _CurrentState; // [esp+80h] [ebp-44h] BYREF
  IShaderAPI *v135; // [esp+84h] [ebp-40h]
  double v136; // [esp+88h] [ebp-3Ch]
  unsigned __int64 advanceStart; // [esp+90h] [ebp-34h]
  char *v138; // [esp+98h] [ebp-2Ch] BYREF
  unsigned int v139; // [esp+9Ch] [ebp-28h]
  unsigned int v140; // [esp+A0h] [ebp-24h]
  char *v141; // [esp+A4h] [ebp-20h]
  unsigned int v142; // [esp+A8h] [ebp-1Ch]
  unsigned int v143; // [esp+ACh] [ebp-18h]
  IShaderAPI *v144; // [esp+B0h] [ebp-14h]
  GRefCountNTSImpl *v145[2]; // [esp+B4h] [ebp-10h]
  float delta; // [esp+BCh] [ebp-8h]
  ILoggingResponsePolicy *fm; // [esp+C0h] [ebp-4h]
  int frameCatchUp; // [esp+CCh] [ebp+8h]
  int frameCatchUpa; // [esp+CCh] [ebp+8h]
  GRefCountNTSImpl *frameCatchUpb; // [esp+CCh] [ebp+8h]
  unsigned int frameCatchUpc; // [esp+CCh] [ebp+8h]
  float frameCatchUpd; // [esp+CCh] [ebp+8h]
  int frameCatchUph; // [esp+CCh] [ebp+8h]
  float frameCatchUpi; // [esp+CCh] [ebp+8h]
  unsigned int frameCatchUpe; // [esp+CCh] [ebp+8h]
  float frameCatchUpf; // [esp+CCh] [ebp+8h]
  char frameCatchUp_3; // [esp+CFh] [ebp+Bh]
  unsigned int frameCatchUpCounta; // [esp+D0h] [ebp+Ch]

  if ( (*(_DWORD *)(this + 2333) & 0x100000) != 0 )
    return 0.050000001;
  v112 = (float *)LODWORD(a2);
  if ( *((_DWORD *)this + 10) == 0 )
  {
    v7 = *((_DWORD *)this + 13);
    if ( v7 == 0 )
      return (float)0.0;
    return (float)(1.0 / ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)v7 + 36))(a1: *((_DWORD *)this + 13)));
  }
  v8 = *((GFxAmpViewStats **)this + 2577);
  v120 = v8;
  if ( v8 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v8, swdHandle: 1u, a3: 9u);
    GTimer::GetRawTicks(li: v9, a2, a3: v115);
    v119 = v10;
  }
  else
  {
    v119 = 0;
  }
  _controlfp_s(&_CurrentState, newctrl: 0, mask: 0);
  _controlfp_s(_CurrentState: &v118, newctrl: 0x10000u, mask: 0x30000u);
  if ( deltaT < 0.0 )
    deltaT = 0.0;
  *((_DWORD *)this + 2333) |= 0x200u;
  v108 = a3;
  v11 = *((_DWORD *)this + 60) + 8;
  v123 = 0;
  v124 = 0;
  v125 = 0;
  v126 = nullptr;
  v127 = 0;
  v128 = nullptr;
  v129 = nullptr;
  v130 = nullptr;
  v131 = nullptr;
  v132 = 0;
  v133 = 0;
  (*(void (__thiscall **)(int, int *, void *, int))(*(_DWORD *)v11 + 16))(a1: v11, a2: &v123, a3: &stateQuery, a4: 11);
  v12 = *((IShaderAPI **)this + 63);
  v13 = v123;
  if ( v12 != nullptr )
    GRefCountImpl::Release(this: v12);
  *((_DWORD *)this + 63) = v13;
  v14 = *((IShaderAPI **)this + 64);
  v15 = v124;
  if ( v14 != nullptr )
    GRefCountImpl::Release(this: v14);
  *((_DWORD *)this + 64) = v15;
  v16 = *((IShaderAPI **)this + 65);
  v17 = v125;
  if ( v16 != nullptr )
    GRefCountImpl::Release(this: v16);
  v18 = v126;
  *((_DWORD *)this + 65) = v17;
  v19 = v127;
  v135 = v18;
  v20 = *((IShaderAPI **)this + 62);
  if ( v20 != nullptr )
    GRefCountImpl::Release(this: v20);
  *((_DWORD *)this + 62) = v19;
  if ( *((_DWORD *)this + 66) != v132 )
  {
    for ( i = 0; i < *((_DWORD *)this + 10); ++i )
    {
      v22 = *(_DWORD *)(*((_DWORD *)this + 9) + 8 * i + 4);
      (*(void (__thiscall **)(int))(*(_DWORD *)v22 + 192))(a1: v22);
    }
  }
  v23 = *((IShaderAPI **)this + 66);
  v24 = v132;
  if ( v23 != nullptr )
    GRefCountImpl::Release(this: v23);
  v25 = v130;
  v26 = v129;
  v27 = v128;
  *((_DWORD *)this + 66) = v24;
  v28 = v131;
  v144 = v25;
  delta = *(float *)&v27;
  fm = v26;
  LOBYTE(v145[1]) = (unsigned __int8)GFxFontManagerStates::CheckStateChange(result: v27);
  if ( v28 != nullptr )
    GRefCountImpl::Release(this: v28);
  if ( v144 != nullptr )
    GRefCountImpl::Release(this: v144);
  if ( *(float *)&fm != 0.0 )
    GRefCountImpl::Release(this: (IShaderAPI *)fm);
  if ( delta != 0.0 )
    GRefCountImpl::Release(this: (IShaderAPI *)LODWORD(delta));
  v29 = v135;
  *((_DWORD *)this + 2333) |= 2u;
  if ( v29 != nullptr )
  {
    if ( ((int)v29[3].__vftable & 1) != 0 )
      *((_DWORD *)this + 2333) |= 4u;
    else
      *((_DWORD *)this + 2333) &= ~4u;
    if ( ((int)v29[3].__vftable & 2) != 0 )
      *((_DWORD *)this + 2333) |= 0x40u;
    else
      *((_DWORD *)this + 2333) &= ~0x40u;
    if ( ((int)v29[3].__vftable & 4) != 0 )
      *((_DWORD *)this + 2333) |= 8u;
    else
      *((_DWORD *)this + 2333) &= ~8u;
    if ( ((int)v29[3].__vftable & 0x10) != 0 )
      *((_DWORD *)this + 2333) |= 0x20u;
    else
      *((_DWORD *)this + 2333) &= ~0x20u;
    if ( ((int)v29[3].__vftable & 8) != 0 )
      *((_DWORD *)this + 2333) |= 0x10u;
    else
      *((_DWORD *)this + 2333) &= ~0x10u;
  }
  else
  {
    *((_DWORD *)this + 2333) &= 0xFFFFFF83;
  }
  v30 = v133;
  *((_DWORD *)this + 68) = v133;
  if ( v30 != 0 )
  {
    v31 = (IShaderDevice *)(*(int (__thiscall **)(int))(*(_DWORD *)v30 + 4))(a1: v30);
    *((_DWORD *)this + 69) = v31;
    if ( v31 != nullptr )
      GRefCountImpl::AddRef(this: v31, a2: (VertexShaderHandle_t__ *)v108);
  }
  for ( j = *((_DWORD *)this + 15); (IDirect3DResource9 *)j != this + 14; j = *(_DWORD *)(j + 4) )
  {
    if ( *(_BYTE *)(j + 24) == 0 )
    {
      *(_DWORD *)(j + 20) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(j + 12) + 28) + 128);
      *(_DWORD *)(j + 16) = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(j + 12) + 20))(a1: *(_DWORD *)(j + 12));
    }
    if ( LOBYTE(v145[1]) != 0 )
      GFxFontManager::CleanCache(result: v108);
  }
  if ( LOBYTE(v145[1]) != 0 )
  {
    v33 = 0;
    if ( *((_DWORD *)this + 10) != 0 )
    {
      v34 = v145[1];
      do
      {
        v35 = *(_DWORD *)(*((_DWORD *)this + 9) + 8 * v33 + 4);
        (*(void (__thiscall **)(int, GRefCountNTSImpl *))(*(_DWORD *)v35 + 184))(a1: v35, a2: v34);
        ++v33;
      }
      while ( v33 < *((_DWORD *)this + 10) );
    }
  }
  if ( GFxSprite::GetLoadingFrame(result: (const GPtr<GFxZlibSupportBase> *)v108) == nullptr )
  {
    *((_DWORD *)this + 2333) &= ~2u;
    v37 = *((IShaderAPI **)this + 69);
    if ( v37 != nullptr )
    {
      GRefCountImpl::Release(this: v37);
      *((_DWORD *)this + 69) = 0;
    }
    v38 = *((IShaderAPI **)this + 68);
    if ( v38 != nullptr )
    {
      GRefCountImpl::Release(this: v38);
      *((_DWORD *)this + 68) = 0;
    }
    if ( v135 != nullptr )
      GRefCountImpl::Release(this: v135);
    _controlfp_s(_CurrentState: &v117, newctrl: _CurrentState, mask: 0x30000u);
    if ( v120 != nullptr )
    {
      GTimer::GetRawTicks(li: v39, a2: *(float *)&v109, a3: v112);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return 0.0;
  }
  if ( (*(_DWORD *)(this + 2333) & 0x100) != 0 && GFxSprite::GetLoadingFrame(result: v109) != nullptr )
  {
    *((_DWORD *)this + 2333) &= ~0x100u;
    for ( k = *((_DWORD *)this + 10); k > 0; --k )
      GFxSprite::ExecuteFrame0Events(this: *(GFxFontLib **)(*((_DWORD *)this + 9) + 8 * k - 4), a2: (unsigned int)v109);
    GFxMovieRoot::DoActions((ScaleformRenderer *)this);
    GFxMovieRoot::ProcessUnloadQueue((ScaleformRenderer *)this);
    GFxMovieRoot::ProcessLoadQueue((ScaleformRenderer *)this);
  }
  v41 = (unsigned __int64)(1000.0 * deltaT);
  v42 = deltaT + *((float *)this + 74);
  v43 = __CFADD__((_DWORD)v41, *((_DWORD *)this + 72));
  *((_DWORD *)this + 72) += v41;
  *((float *)this + 74) = v42;
  *((_DWORD *)this + 73) += HIDWORD(v41) + v43;
  GTimer::GetProfileTicks(a1: v36, a2: *(float *)&v109, a3: v112);
  v44 = *((_DWORD *)this + 2345);
  fm = *((ILoggingResponsePolicy **)this + 75);
  advanceStart = v45;
  if ( v44 != 0 )
  {
    v46 = 0;
    frameCatchUp = 0;
    v47 = *((_DWORD *)this + 2344);
    do
    {
      if ( *(_DWORD *)(v47 + 4 * v46) != 0 && *((_BYTE *)(v48 = *(GASIntervalTimer **)(v47 + 4 * v46)) + 56) != 0 )
      {
        GASIntervalTimer::Invoke(this: v48, i: (struct GFxMovieRoot *)this, frameTime: *((float *)this + 75));
        v47 = *((_DWORD *)this + 2344);
        v49 = (*(_QWORD *)(*(_DWORD *)(v47 + 4 * v46) + 40) - *((_QWORD *)this + 36)) >> 32;
        LODWORD(v136) = *(_DWORD *)(*(_DWORD *)(v47 + 4 * v46) + 40) - *((_DWORD *)this + 72);
        HIDWORD(v136) = v49 & 0x7FFFFFFF;
        v145[1] = (GRefCountNTSImpl *)(v49 & 0x80000000);
        v145[0] = nullptr;
        delta = (double)__PAIR64__(v49, LODWORD(v136)) / 1000.0;
        if ( *(float *)&fm > (double)delta )
          *(float *)&fm = delta;
      }
      else
      {
        ++frameCatchUp;
      }
      ++v46;
    }
    while ( v46 < v44 );
    if ( frameCatchUp != 0 )
    {
      v50 = 0;
      if ( *((_DWORD *)this + 2345) != 0 )
      {
        frameCatchUpa = *((_DWORD *)this + 2345);
        do
        {
          v51 = (GASIntervalTimer **)(*((_DWORD *)this + 2344) + 4 * v50);
          if ( *v51 != nullptr && *((_BYTE *)*v51 + 56) != 0 )
          {
            ++v50;
          }
          else
          {
            v52 = *v51;
            if ( *v51 != nullptr )
            {
              GASIntervalTimer::~GASIntervalTimer(this: *v51);
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v52);
            }
            v53 = *((_DWORD *)this + 2345);
            if ( v53 == 1 )
            {
              if ( (*(_DWORD *)(this + 2346) & 0xFFFFFFFE) != 0 )
              {
                if ( *((_DWORD *)this + 2344) != 0 )
                {
                  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 2344));
                  *((_DWORD *)this + 2344) = 0;
                }
                *((_DWORD *)this + 2346) = 0;
              }
              *((_DWORD *)this + 2345) = 0;
            }
            else
            {
              memmove(
                dst: (unsigned __int8 *)(*((_DWORD *)this + 2344) + 4 * v50),
                src: (unsigned __int8 *)(*((_DWORD *)this + 2344) + 4 * v50 + 4),
                count: 4 * (v53 - v50) - 4);
              --*((_DWORD *)this + 2345);
            }
          }
          --frameCatchUpa;
        }
        while ( frameCatchUpa != 0 );
      }
    }
  }
  v54 = *((_DWORD **)this + 61);
  v55 = 0;
  if ( v54 != nullptr && *v54 != 0 )
  {
    v56 = v54[1];
    v138 = nullptr;
    v139 = 0;
    v140 = 0;
    v57 = v54 + 2;
    do
    {
      if ( *v57 != -2 )
        break;
      ++v55;
      v57 += 3;
    }
    while ( v55 <= v56 );
    while ( 1 )
    {
      v58 = this + 61;
      if ( this == (IDirect3DResource9 *)-244 )
        break;
      v59 = v58->__vftable;
      if ( v58->__vftable == nullptr || v55 > (int)v59->AddRef )
        break;
      v60 = (GRefCountNTSImpl **)(&v59->SetPrivateData + 3 * v55);
      if ( *v60 != nullptr )
        ++(*v60)->RefCount;
      v61 = *v60;
      frameCatchUpb = *v60;
      (*v60)->__vftable[2].dtr_GRefCountImplCore(this: *v60);
      if ( ((unsigned __int8 (__thiscall *)(GRefCountNTSImpl *))v61->__vftable[5].dtr_GRefCountImplCore)(a1: v61) != 0 )
      {
        v62 = ((double (__thiscall *)(GRefCountNTSImpl *))v61->__vftable[6].dtr_GRefCountImplCore)(a1: v61);
        if ( *(float *)&fm > v62 )
          *(float *)&fm = ((double (__thiscall *)(GRefCountNTSImpl *))v61->__vftable[6].dtr_GRefCountImplCore)(a1: v61);
      }
      else
      {
        v63 = v139 + 1;
        if ( v139 + 1 >= v139 )
        {
          if ( v63 >= v140 )
            GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
              this: (CVertexBuilder *)&v138,
              pheapAddr: (ButtonCode_t)&v138,
              newCapacity: v63 + (v63 >> 2));
        }
        else if ( v63 < v140 >> 1 )
        {
          GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
            this: (CVertexBuilder *)&v138,
            pheapAddr: (ButtonCode_t)&v138,
            newCapacity: v139 + 1);
        }
        v139 = v63;
        v64 = (GRefCountNTSImpl **)&v138[4 * v63 - 4];
        if ( v64 != nullptr )
          *v64 = frameCatchUpb;
      }
      GRefCountNTSImpl::Release(this: frameCatchUpb);
      v65 = *((_DWORD *)this + 61);
      v66 = *(_DWORD *)(v65 + 4);
      if ( v55 <= (int)v66 && ++v55 <= v66 )
      {
        v67 = (_DWORD *)(v65 + 12 * v55 + 8);
        do
        {
          if ( *v67 != -2 )
            break;
          ++v55;
          v67 += 3;
        }
        while ( v55 <= v66 );
      }
    }
    if ( v139 != 0 )
    {
      v68 = v138;
      for ( frameCatchUpc = v139; frameCatchUpc != 0; --frameCatchUpc )
      {
        GHashSetBase<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>,GFixedSizeHash<GPtr<GFxVideoProvider>>,GAllocatorGH<GPtr<GFxVideoProvider>,2>,GHashsetCachedEntry<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>>>::RemoveAlt<GFxVideoProvider *>(a1: v68);
        v68 += 4;
      }
    }
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v138);
  }
  v69 = *((_DWORD *)this + 69);
  if ( v69 != 0 )
  {
    frameCatchUpd = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v69 + 32))(a1: v69);
    if ( *(float *)&fm > (double)frameCatchUpd )
      *(float *)&fm = frameCatchUpd;
  }
  GFxMovieRoot::ProcessInput((ScaleformRenderer *)this);
  if ( *((float *)this + 75) <= (double)*((float *)this + 74) )
  {
    GFxMovieRoot::DoActions((ScaleformRenderer *)this);
    if ( frameCatchUpCount != 0 || (frameCatchUp_3 = 0, *((_DWORD *)this + 76) != 0) )
      frameCatchUp_3 = 1;
    while ( 1 )
    {
      v70 = *((float *)this + 74);
      if ( frameCatchUp_3 != 0 )
      {
        v71 = v70 - *((float *)this + 75);
      }
      else
      {
        delta = fmod(v70, *((float *)this + 75));
        v71 = delta;
      }
      *((float *)this + 74) = v71;
      if ( *((float *)this + 75) > (double)*((float *)this + 74) )
        v72 = *((float *)this + 74) / *((float *)this + 75);
      else
        v72 = 0.0;
      delta = v72;
      GFxMovieRoot::AdvanceFrame(this, nextFrame: 1, framePos: SLODWORD(delta));
      v73 = *((_DWORD **)this + 61);
      if ( v73 == nullptr || *v73 == 0 )
        goto LABEL_189;
      v74 = v73[1];
      v75 = 0;
      v76 = nullptr;
      v141 = nullptr;
      v142 = 0;
      v143 = 0;
      v77 = v73 + 2;
      do
      {
        if ( *v77 != -2 )
          break;
        ++v75;
        v77 += 3;
      }
      while ( v75 <= v74 );
      HIDWORD(v136) = v75;
      while ( this != (IDirect3DResource9 *)-244 )
      {
        v78 = *((_DWORD *)this + 61);
        if ( v78 == 0 || (signed int)v75 > *(_DWORD *)(v78 + 4) )
          break;
        v79 = v78 + 12 * v75 + 16;
        if ( *(_DWORD *)v79 != 0 )
        {
          ++*(_DWORD *)(*(_DWORD *)v79 + 4);
          v76 = v141;
        }
        v80 = *(GRefCountNTSImpl **)v79;
        dtr_GRefCountImplCore = (void (*)(void))v80->__vftable[2].dtr_GRefCountImplCore;
        v145[1] = v80;
        dtr_GRefCountImplCore();
        if ( ((unsigned __int8 (__thiscall *)(GRefCountNTSImpl *))v145[1]->__vftable[5].dtr_GRefCountImplCore)(a1: v145[1]) != 0 )
        {
          v82 = ((double (__thiscall *)(GRefCountNTSImpl *))v145[1]->__vftable[6].dtr_GRefCountImplCore)(a1: v145[1]);
          if ( *(float *)&fm > v82 )
            *(float *)&fm = ((double (__thiscall *)(GRefCountNTSImpl *))v145[1]->__vftable[6].dtr_GRefCountImplCore)(a1: v145[1]);
          goto LABEL_179;
        }
        v83 = v142 + 1;
        v144 = (IShaderAPI *)(v142 + 1);
        if ( v142 + 1 >= v142 )
        {
          if ( v83 < v143 )
            goto LABEL_177;
          v88 = (char *)(v83 + (v83 >> 2));
          if ( v88 == nullptr )
          {
            if ( v76 != nullptr )
            {
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v76);
              v83 = (unsigned int)v144;
              v76 = nullptr;
              v141 = nullptr;
            }
LABEL_171:
            v143 = 0;
            goto LABEL_177;
          }
          v89 = v88 + 3;
          v84 = GMemory::pGlobalHeap;
          v85 = 4 * ((unsigned int)v89 >> 2);
          if ( v76 == nullptr )
          {
            v121 = 2;
            v87 = &v121;
            goto LABEL_174;
          }
LABEL_165:
          v86 = (int)v84->Realloc(this: v84, a2: v76, a3: 4 * v85);
LABEL_175:
          v143 = v85;
          v75 = HIDWORD(v136);
          v76 = (char *)v86;
          goto LABEL_176;
        }
        if ( v83 >= v143 >> 1 )
          goto LABEL_177;
        if ( v142 != -1 )
        {
          v84 = GMemory::pGlobalHeap;
          v85 = 4 * ((v142 + 4) >> 2);
          if ( v76 != nullptr )
            goto LABEL_165;
          v122 = 2;
          v87 = &v122;
LABEL_174:
          v86 = (int)v84->Alloc_2(this: v84, a2: 4 * v85, a3: (const GAllocDebugInfo *)v87);
          goto LABEL_175;
        }
        if ( v76 == nullptr )
          goto LABEL_171;
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v76);
        v76 = nullptr;
        v143 = 0;
LABEL_176:
        v83 = (unsigned int)v144;
        v141 = v76;
LABEL_177:
        v142 = v83;
        v90 = (GRefCountNTSImpl **)&v76[4 * v83 - 4];
        if ( v90 != nullptr )
          *v90 = v145[1];
LABEL_179:
        GRefCountNTSImpl::Release(this: v145[1]);
        v91 = *((_DWORD *)this + 61);
        v92 = *(_DWORD *)(v91 + 4);
        if ( (int)v75 <= (int)v92 )
        {
          HIDWORD(v136) = ++v75;
          if ( v75 <= v92 )
          {
            v93 = (_DWORD *)(v91 + 12 * v75 + 8);
            do
            {
              if ( *v93 != -2 )
                break;
              ++v75;
              v93 += 3;
              HIDWORD(v136) = v75;
            }
            while ( v75 <= v92 );
          }
        }
      }
      if ( v142 != 0 )
      {
        v94 = v76;
        v145[1] = (GRefCountNTSImpl *)v142;
        do
        {
          GHashSetBase<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>,GFixedSizeHash<GPtr<GFxVideoProvider>>,GAllocatorGH<GPtr<GFxVideoProvider>,2>,GHashsetCachedEntry<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>>>::RemoveAlt<GFxVideoProvider *>(a1: v94);
          v94 += 4;
          --v145[1];
        }
        while ( v145[1] != nullptr );
      }
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v76);
LABEL_189:
      GFxMovieRoot::DoActions((ScaleformRenderer *)this);
      GFxMovieRoot::ProcessUnloadQueue((ScaleformRenderer *)this);
      GFxMovieRoot::ProcessLoadQueue((ScaleformRenderer *)this);
      v95 = *((_DWORD *)this + 76);
      if ( v95 != 0 )
        *((_DWORD *)this + 76) = v95 - 1;
      v96 = frameCatchUpCount--;
      if ( (v96 == 0 || *((float *)this + 75) > (double)*((float *)this + 74)) && *((_DWORD *)this + 76) == 0 )
      {
        *((_DWORD *)this + 2333) |= 0x80u;
        GASRefCountCollector::AdvanceFrame(this: *(IDataCacheSection **)(*((_DWORD *)this + 5) + 12));
        goto LABEL_196;
      }
    }
  }
  *(float *)&frameCatchUph = *((float *)this + 74) / *((float *)this + 75);
  GFxMovieRoot::AdvanceFrame(this, nextFrame: 0, framePos: frameCatchUph);
  frameCatchUpi = fmod(*((float *)this + 74), *((float *)this + 75));
  *((float *)this + 74) = frameCatchUpi;
  GFxMovieRoot::DoActions((ScaleformRenderer *)this);
  GFxMovieRoot::ProcessUnloadQueue((ScaleformRenderer *)this);
  GFxMovieRoot::ProcessLoadQueue((ScaleformRenderer *)this);
LABEL_196:
  frameCatchUpCounta = 0;
  if ( *((_DWORD *)this + 2556) != 0 )
  {
    v98 = (GStatBag::Iterator *)(this + 2349);
    do
    {
      if ( ((int)v98[-1].Result.pData & 1) != 0 )
      {
        GroupId = v98->GroupId;
        StatId = (GRefCountNTSImpl *)v98->Result.StatId;
        if ( GroupId != 0 )
        {
          v100 = (GRefCountNTSImpl **)(v98->Id + 4 * GroupId - 4);
          frameCatchUpe = v98->GroupId;
          do
          {
            StatId = *v100;
            if ( *v100 != nullptr )
              GRefCountNTSImpl::Release(this: StatId);
            --v100;
            --frameCatchUpe;
          }
          while ( frameCatchUpe != 0 );
          if ( ((int)v98->pBag & 0xFFFFFFFE) != 0 )
          {
            if ( v98->Id != 0 )
            {
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v98->Id);
              v98->Id = 0;
            }
            v98->pBag = nullptr;
          }
        }
        else if ( v98->pBag == nullptr )
        {
          GArrayDataBase<GPtr<GFxASCharacter>,GAllocatorDH<GPtr<GFxASCharacter>,326>,GArrayDefaultPolicy>::Reserve(
            this: v98,
            pheapAddr: (ButtonCode_t)StatId,
            newCapacity: 0);
        }
        v98->GroupId = 0;
        LOBYTE(v98[-1].Result.pData) = 0;
      }
      v98 = (GStatBag::Iterator *)((char *)v98 + 52);
      ++frameCatchUpCounta;
    }
    while ( frameCatchUpCounta < *((_DWORD *)this + 2556) );
  }
  v101 = *(float *)&fm;
  *((_DWORD *)this + 2333) &= ~2u;
  v136 = v101;
  GTimer::GetProfileTicks(a1: *(float *)&StatId, a2: v110, a3: v113);
  v103 = v102 - advanceStart;
  advanceStart = __PAIR64__(HIDWORD(v103) & 0x80000000, 0);
  *(float *)&fm = v136 - (double)v103 / 1000000.0;
  if ( *(float *)&fm >= 0.0 )
  {
    v104 = *(float *)&fm;
  }
  else
  {
    *(float *)&fm = 0.0;
    v104 = (float)0.0;
  }
  frameCatchUpf = *((float *)this + 75) - *((float *)this + 74);
  if ( frameCatchUpf <= v104 )
    v104 = frameCatchUpf;
  v105 = *((IShaderAPI **)this + 69);
  if ( v105 != nullptr )
  {
    GRefCountImpl::Release(this: v105);
    *((_DWORD *)this + 69) = 0;
  }
  v106 = *((IShaderAPI **)this + 68);
  if ( v106 != nullptr )
  {
    GRefCountImpl::Release(this: v106);
    *((_DWORD *)this + 68) = 0;
  }
  if ( v135 != nullptr )
    GRefCountImpl::Release(this: v135);
  _controlfp_s(_CurrentState: &v116, newctrl: _CurrentState, mask: 0x30000u);
  if ( v120 != nullptr )
  {
    GTimer::GetRawTicks(li: v107, a2: v111, a3: v114);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
  return (float)v104;
}

//------------------------------------------------------------------------------
// Address: 0x100D0070
// Name: public: virtual void GFxMovieRoot::Restart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::Restart(ScaleformRenderer *this)
{
  GRenderer::BlendType *Data; // ecx
  unsigned int v3; // ebx
  IShaderDevice *v4; // eax
  unsigned int *i; // edi
  int v6; // eax
  unsigned int v7; // ecx
  _DWORD *v8; // edi
  _DWORD *v9; // edi
  int v10; // ecx
  GRefCountNTSImpl *v11; // ecx
  GRefCountNTSImpl *RefCount; // edi
  GRenderer *pRenderer; // edx
  IShaderAPI *v14; // edi
  void (__thiscall *SetPixelShaderFogParams)(struct IShaderAPI *, int); // edx
  IDirect3DDevice9 *v16; // eax
  _DWORD *S3DDisplay; // ecx
  GFxFontLib *v18; // eax
  void **v19; // edi
  float Distortion; // ebx
  CMaterial *v21; // ecx
  float EyeSeparationCm; // edi
  float v23; // ecx
  int (__thiscall *v24)(_DWORD, int, unsigned int *); // edx
  _DWORD *v25; // eax
  int v26; // ecx
  int v27; // ecx
  float v28; // ecx
  int (__thiscall *v29)(_DWORD, int, unsigned int *); // eax
  GFxFontLib::FontResult *v30; // eax
  IShaderDevice *v31; // edi
  unsigned int j; // edi
  float v33; // ecx
  float v34; // ecx
  void *v35; // edi
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v36; // edi
  GColor *p_color; // edi
  IShaderAPI *v38; // edi
  VertexShaderHandle_t__ *v39; // [esp+54h] [ebp-38h]
  GStatInfo *v40; // [esp+54h] [ebp-38h]
  unsigned __int8 *v41; // [esp+58h] [ebp-34h]
  _DWORD v42[3]; // [esp+60h] [ebp-2Ch] BYREF
  _DWORD v43[3]; // [esp+6Ch] [ebp-20h] BYREF
  unsigned int plqCounta; // [esp+78h] [ebp-14h] BYREF
  IShaderDevice *v45; // [esp+7Ch] [ebp-10h]
  GRefCountNTSImpl *v46; // [esp+80h] [ebp-Ch]
  IShaderAPI *v47; // [esp+84h] [ebp-8h]
  bool wasIMEActivea; // [esp+8Bh] [ebp-1h]

  Data = this->m_blendModeStack.Data.Data;
  v3 = 0;
  if ( Data != nullptr )
  {
    v4 = (IShaderDevice *)(*(int (__thiscall **)(GRenderer::BlendType *))(*Data + 92))(a1: Data);
    v45 = v4;
    if ( v4 != nullptr )
      GRefCountImpl::AddRef(this: v4, a2: v39);
    for ( i = (unsigned int *)((char *)&this->m_pDevice[-1].__vftable + 3); (int)i >= 0; i = (unsigned int *)((char *)i - 1) )
      GFxMovieRoot::ReleaseLevelMovie(a1: (int)this, level: i, i: (unsigned int *)v39, a4: v41);
    GArrayDataBase<GFxMovieRoot::LevelInfo,GAllocatorLH<GFxMovieRoot::LevelInfo,326>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: (int)&this->S3DDisplay,
      result: (GFxTestStream *)&this->S3DDisplay,
      newSize: 0);
    v6 = *((_DWORD *)this + 2576);
    v7 = 0;
    if ( v6 != 0 )
    {
      do
      {
        *(_BYTE *)(*(_DWORD *)(v6 + 16) + 104) = 1;
        v6 = *(_DWORD *)(v6 + 4);
        ++v7;
      }
      while ( v6 != 0 );
      plqCounta = v7;
      if ( v7 != 0 )
      {
        while ( 1 )
        {
          v8 = *((_DWORD **)this + 2576);
          if ( v8 != nullptr )
          {
            do
            {
              if ( (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v8 + 4))(a1: v8) != 0 )
                ++v3;
              v8 = (_DWORD *)v8[1];
            }
            while ( v8 != nullptr );
            v7 = plqCounta;
          }
          if ( v7 <= v3 )
            break;
          v3 = 0;
        }
      }
    }
    while ( *((_DWORD *)this + 2574) != 0 )
    {
      v9 = *((_DWORD **)this + 2574);
      *((_DWORD *)this + 2574) = *v9;
      GFxLoadQueueEntry::~GFxLoadQueueEntry(this: (int)v9);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
    }
    while ( *((_DWORD *)this + 2576) != 0 )
    {
      v10 = *((_DWORD *)this + 2576);
      *((_DWORD *)this + 2576) = *(_DWORD *)(v10 + 4);
      (**(void (__thiscall ***)(int, int))v10)(a1: v10, a2: 1);
    }
    v11 = *((GRefCountNTSImpl **)this + 2563);
    *((_DWORD *)this + 2574) = 0;
    *((_DWORD *)this + 2576) = 0;
    if ( v11 != nullptr )
    {
      do
      {
        RefCount = (GRefCountNTSImpl *)v11[17].RefCount;
        v11[17].RefCount = 0;
        GRefCountNTSImpl::Release(this: v11);
        v11 = RefCount;
      }
      while ( RefCount != nullptr );
    }
    *((_DWORD *)this + 2563) = 0;
    *((_DWORD *)this + 2333) |= 0x80000u;
    *((_DWORD *)this + 2562) = 0;
    *((_DWORD *)this + 2561) = 0;
    pRenderer = this->Handlers.Root.pPrev->pRenderer;
    wasIMEActivea = false;
    v14 = (IShaderAPI *)((int (__thiscall *)(GList<GRendererEventHandler> *, int))pRenderer)(
                          a1: &this->Handlers,
                          a2: 27);
    v47 = v14;
    if ( v14 != nullptr
      && ((unsigned __int8 (__thiscall *)(IShaderAPI *, ScaleformRenderer *))v14->InFlashlightMode)(a1: v14, a2: this) != 0 )
    {
      SetPixelShaderFogParams = v14->SetPixelShaderFogParams;
      wasIMEActivea = true;
      SetPixelShaderFogParams(this: v14, a2: 0);
    }
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 2564));
    *((_DWORD *)this + 2564) = 0;
    GHashSetBase<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>,GFixedSizeHash<GPtr<GFxVideoProvider>>,GAllocatorGH<GPtr<GFxVideoProvider>,2>,GHashsetCachedEntry<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>>>::~GHashSetBase<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>,GFixedSizeHash<GPtr<GFxVideoProvider>>,GAllocatorGH<GPtr<GFxVideoProvider>,2>,GHashsetCachedEntry<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>>>(
      this: (CColorCorrectionSystem *)&this->m_projection,
      a2: (unsigned int)v39);
    v16 = nullptr;
    if ( this->m_pDevice != nullptr )
    {
      S3DDisplay = (_DWORD *)this->S3DDisplay;
      while ( *S3DDisplay != 0 )
      {
        v16 = (IDirect3DDevice9 *)((char *)v16 + 1);
        S3DDisplay += 2;
        if ( v16 >= this->m_pDevice )
          goto LABEL_33;
      }
      v18 = *(GFxFontLib **)(this->S3DDisplay + 8 * (_DWORD)v16 + 4);
      if ( v18 != nullptr )
        GFxSprite::StopActiveSounds(this: v18, a2: (unsigned int)v40);
    }
LABEL_33:
    GASGlobalContext::UnregisterAllClasses(this: *((GASGlobalContext **)this + 2289));
    v19 = *((void ***)this + 2290);
    this->m_glyphVertexBuffer[91].y = 0.0;
    if ( v19 != nullptr )
    {
      if ( *v19 != nullptr )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v19);
      GArrayDataCC<GASString,GAllocatorLH<GASString,323>,GArrayDefaultPolicy>::~GArrayDataCC<GASString,GAllocatorLH<GASString,323>,GArrayDefaultPolicy>(result: v40);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v19);
    }
    *((_DWORD *)this + 2290) = 0;
    GFxMovieRoot::ResetFocusStates(this);
    *((_DWORD *)this + 2333) &= 0x3FFFFFu;
    Distortion = this->S3DParams.Distortion;
    v21 = *(CMaterial **)(*(_DWORD *)(LODWORD(Distortion) + 28) + 20);
    EyeSeparationCm = this->S3DParams.EyeSeparationCm;
    if ( v21 != nullptr )
    {
      GFxTextAllocator::FlushTextFormatCache(this: v21);
      GFxTextAllocator::FlushParagraphFormatCache(this: *(CMaterial **)(*(_DWORD *)(LODWORD(Distortion) + 28) + 20));
    }
    GASRefCountCollector::ForceEmergencyCollect(this: *(GASRefCountCollector **)(*(_DWORD *)(LODWORD(Distortion) + 28)
                                                                               + 12));
    *(_DWORD *)(LODWORD(Distortion) + 36) = (*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(EyeSeparationCm) + 80))(a1: COERCE_FLOAT(LODWORD(EyeSeparationCm)));
    (*(void (__thiscall **)(float, int))(*(_DWORD *)LODWORD(EyeSeparationCm) + 24))(
      a1: COERCE_FLOAT(LODWORD(EyeSeparationCm)),
      a2: 0x20000);
    *(_DWORD *)(LODWORD(Distortion) + 40) = *(_DWORD *)(LODWORD(EyeSeparationCm) + 48);
    GFxMovieRoot::ResetMouseState(this);
    GASGlobalContext::PreClean(this: *((GASGlobalContext **)this + 2289), a2: true);
    GASRefCountCollector::ForceCollect(this: *(GASRefCountCollector **)(LODWORD(this->S3DParams.Distortion) + 12));
    GASGlobalContext::Init(result: (tagENHMETAHEADER *)this);
    v23 = this->S3DParams.EyeSeparationCm;
    v24 = *(int (__thiscall **)(_DWORD, int, unsigned int *))(*(_DWORD *)LODWORD(v23) + 40);
    plqCounta = 323;
    v25 = (_DWORD *)v24(a1: LODWORD(v23), a2: 28, a3: &plqCounta);
    if ( v25 != nullptr )
    {
      v26 = *((_DWORD *)this + 2289);
      *v25 = 0;
      v25[1] = 0;
      v25[2] = 0;
      v25[3] = 0;
      v25[4] = 0;
      v27 = *(_DWORD *)(v26 + 8);
      v25[5] = v27;
      ++*(_DWORD *)(v27 + 8);
      v25[6] = 0;
    }
    else
    {
      v25 = nullptr;
    }
    v28 = this->S3DParams.EyeSeparationCm;
    *((_DWORD *)this + 2290) = v25;
    v29 = *(int (__thiscall **)(_DWORD, int, unsigned int *))(*(_DWORD *)LODWORD(v28) + 40);
    plqCounta = 322;
    v30 = (GFxFontLib::FontResult *)v29(a1: LODWORD(v28), a2: 488, a3: &plqCounta);
    v31 = v45;
    if ( v30 != nullptr && (v46 = (GRefCountNTSImpl *)GFxSprite::GFxSprite(this: v30)) != nullptr )
    {
      if ( LODWORD(this->m_projection.M_[0][2]) != 0 )
      {
        for ( j = 0; j < LODWORD(this->m_glyphVertexBuffer[90].u); ++j )
        {
          v33 = this->m_projection.M_[0][2];
          v43[0] = 10;
          v43[1] = 0;
          v43[2] = j;
          (*(void (__thiscall **)(float, ScaleformRenderer *, _DWORD *))(*(_DWORD *)LODWORD(v33) + 4))(
            a1: COERCE_FLOAT(LODWORD(v33)),
            a2: this,
            a3: v43);
          v34 = this->m_projection.M_[0][2];
          v42[0] = 12;
          v42[1] = 0;
          v42[2] = j;
          (*(void (__thiscall **)(float, ScaleformRenderer *, _DWORD *))(*(_DWORD *)LODWORD(v34) + 4))(
            a1: COERCE_FLOAT(LODWORD(v34)),
            a2: this,
            a3: v42);
        }
      }
      v35 = *((void **)this + 2295);
      if ( v35 != nullptr )
      {
        GHashSetBase<GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>::NodeHashF>>::Clear(a1: *((_DWORD *)this + 2295));
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v35);
      }
      *((_DWORD *)this + 2295) = 0;
      GFxSprite::SetLevel(result: nullptr);
      v36 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v46;
      GFxMovieRoot::SetLevelMovie((GPtr<GFxTextKeyMap> *)this, a2: (VertexShaderHandle_t__ *)v46, a3: nullptr, a4: v46);
      GFxMovieRoot::RegisterAuxASClasses(this);
      GFxMovieRoot::ResolveStickyVariables(this, a2: v36);
      p_color = &this->m_glyphVertexBuffer[91].color;
      for ( plqCounta = 4; plqCounta != 0; --plqCounta )
      {
        GFxKeyboardState::ResetState(this: (GFxKeyboardState *)p_color);
        p_color += 415;
      }
      v38 = v47;
      if ( wasIMEActivea )
        v47->SetPixelShaderFogParams(this: v47, a2: (int)this);
      ((void (__thiscall *)(ScaleformRenderer *, _DWORD, _DWORD))this->DrawBitmaps)(a1: this, a2: 0.0, a3: 0);
      *((_DWORD *)this + 2333) |= 0x400u;
      GASRefCountCollector::ForceCollect(this: *(GASRefCountCollector **)(LODWORD(this->S3DParams.Distortion) + 12));
      GRefCountNTSImpl::Release(this: v46);
      if ( v38 != nullptr )
        GRefCountImpl::Release(this: v38);
      GFxResource::Release(this: v45);
    }
    else
    {
      if ( v47 != nullptr )
        GRefCountImpl::Release(this: v47);
      if ( v31 != nullptr )
        GFxResource::Release(this: v31);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D0500
// Name: public: void GFxMovieRoot::AddInvokeAlias(class GASString const __near &,class GFxCharacterHandle __near *,class GASObject __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
GPtr<GFxActionControl> *__userpurge GFxMovieRoot::AddInvokeAlias@<eax>(
        int a1@<ecx>,
        _IMAGE_SYMBOL_EX *alias,
        GMemoryHeap *pthisChar,
        int pthisObj,
        const char *func,
        int a6)
{
  _DWORD *v7; // eax
  int v8; // ecx
  GPtr<GFxActionControl> v10; // [esp+4h] [ebp-1Ch] BYREF
  GMemoryHeap *v11; // [esp+8h] [ebp-18h]
  _DWORD v12[2]; // [esp+Ch] [ebp-14h] BYREF
  char v13; // [esp+14h] [ebp-Ch]
  unsigned int v14; // [esp+18h] [ebp-8h] BYREF
  int v15; // [esp+1Ch] [ebp-4h] BYREF

  if ( *(_DWORD *)(a1 + 9180) == 0 )
  {
    v15 = 323;
    v7 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 4, a3: &v15);
    if ( v7 != nullptr )
      *v7 = 0;
    else
      v7 = nullptr;
    *(_DWORD *)(a1 + 9180) = v7;
  }
  v13 = 0;
  v12[0] = 0;
  v12[1] = 0;
  if ( pthisObj != 0 )
    *(_DWORD *)(pthisObj + 8) = (*(_DWORD *)(pthisObj + 8) + 1) & 0x8FFFFFFF;
  v10.pObject = (GFxActionControl *)pthisObj;
  if ( pthisChar != nullptr )
    ++pthisChar->__vftable;
  v11 = pthisChar;
  GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)v12, a2: (const struct GASFunctionRefBase *)func);
  v8 = *(_DWORD *)(a1 + 9180);
  v14 = (unsigned int)alias;
  v15 = (int)&v10;
  GHashSetBase<GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>::NodeHashF>>::Set<GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>::NodeRef>(
    a1: v8,
    a2: &v14);
  return GFxMovieRoot::InvokeAliasInfo::~InvokeAliasInfo(this: &v10);
}

//------------------------------------------------------------------------------
// Address: 0x100D05B0
// Name: public: virtual GFxMovieRoot::~GFxMovieRoot(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxMovieRoot::~GFxMovieRoot(ScaleformRenderer *this@<ecx>, unsigned int a2@<ebx>)
{
  unsigned int v3; // ecx
  ConVar *Instance; // eax
  IShaderAPI *v5; // edi
  GRefCountNTSImpl *v6; // ecx
  GASStringManager *v7; // ebx
  GRenderer::BlendType *Data; // edi
  struct GFxLog *v9; // eax
  IDirect3DDevice9 *v10; // eax
  _DWORD *S3DDisplay; // ecx
  GFxFontLib *v12; // eax
  IDirect3DDevice9 *i; // edi
  IDirect3DDevice9 *j; // edi
  IDirect3DDevice9 *m_pDevice; // eax
  GRenderer::StereoDisplay *p_S3DDisplay; // edi
  GRefCountNTSImpl **v17; // edi
  IDirect3DDevice9 *v18; // ebx
  int v19; // edi
  int v20; // ecx
  bool v21; // zf
  int v22; // eax
  int v23; // ebx
  int v24; // eax
  unsigned int v25; // ecx
  _DWORD *v26; // edi
  unsigned int k; // ebx
  _DWORD *v28; // edi
  int v29; // ecx
  void *v30; // edi
  GRefCountNTSImpl *v31; // ecx
  GRefCountNTSImpl *RefCount; // edi
  IShaderAPI *v33; // ecx
  IShaderAPI *v34; // ecx
  GMatrix3D *v35; // edi
  int m; // ebx
  int v37; // eax
  GRefCountNTSImpl **v38; // edi
  int v39; // ebx
  int v40; // eax
  GRefCountNTSImpl **v41; // edi
  int v42; // ebx
  GRefCountNTSImpl *v43; // ecx
  IShaderAPI *v44; // edi
  int n; // ebx
  float *p_u; // edi
  int ii; // ebx
  _DWORD *v48; // eax
  _DWORD *v49; // eax
  _DWORD *v50; // eax
  GRefCountNTSImpl *v51; // ecx
  IShaderAPI *v52; // ecx
  IShaderAPI *v53; // ecx
  IShaderAPI *v54; // ecx
  IShaderAPI *v55; // ecx
  IShaderAPI *v56; // ecx
  IShaderAPI *v57; // ecx
  IShaderDevice *Size; // ecx
  IDirect3DDevice9 *v59; // eax
  GRefCountNTSImpl **v60; // edi
  IDirect3DDevice9 *v61; // ebx
  float Distortion; // ecx
  const char *v63; // [esp-8h] [ebp-28h]
  unsigned int v64; // [esp-4h] [ebp-24h]
  unsigned int v65; // [esp-4h] [ebp-24h]
  int v66; // [esp+0h] [ebp-20h]
  const GPoint3<float> *v67; // [esp+0h] [ebp-20h]
  int v68; // [esp+4h] [ebp-1Ch]
  bool v69; // [esp+4h] [ebp-1Ch]
  int v70; // [esp+8h] [ebp-18h] BYREF
  GMatrix3D *v71; // [esp+Ch] [ebp-14h]
  GPoint3<float> *result; // [esp+10h] [ebp-10h]
  int v73; // [esp+14h] [ebp-Ch]
  IShaderAPI *v74; // [esp+18h] [ebp-8h]
  unsigned int plqCounta; // [esp+1Ch] [ebp-4h]

  this->__vftable = (ScaleformRenderer_vtbl *)&GFxMovieRoot::`vftable'{for `GFxMovie'};
  this->Handlers.Root.pPrev = (GRendererEventHandler *)&GFxMovieRoot::`vftable'{for `GFxStateBag'};
  GArrayDataBase<GPtr<GFxSprite>,GAllocatorLH<GPtr<GFxSprite>,326>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: (ScaleformUIImpl *)((char *)this + 9348),
    pheapAddr: (char *)this + 9348,
    newSize: 0,
    a4: v66,
    a5: v68);
  Instance = (ConVar *)GFxAmpServer::GetInstance(a1: v3);
  GFxAmpServer::RemoveMovie(this: Instance, movie: (int)this);
  v5 = (IShaderAPI *)((int (__thiscall *)(GList<GRendererEventHandler> *, int))this->Handlers.Root.pPrev->pRenderer)(
                       a1: &this->Handlers,
                       a2: 27);
  v74 = v5;
  if ( v5 != nullptr
    && ((unsigned __int8 (__thiscall *)(IShaderAPI *, ScaleformRenderer *))v5->InFlashlightMode)(a1: v5, a2: this) != 0 )
  {
    v5->InEditorMode(this: v5);
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 2564));
  v6 = (GRefCountNTSImpl *)LODWORD(this->m_projection.M_[1][2]);
  if ( v6 != nullptr )
    GRefCountNTSImpl::Release(this: v6);
  this->m_projection.M_[1][2] = 0.0;
  v64 = a2;
  if ( this->m_blendModeStack.Data.Data != nullptr )
  {
    v7 = *(GASStringManager **)(*((_DWORD *)this + 2289) + 636);
    Data = this->m_blendModeStack.Data.Data;
    v63 = (const char *)(*(int (__thiscall **)(unsigned int, unsigned int))(*(_DWORD *)this->m_blendModeStack.Data.Size
                                                                          + 48))(
                          a1: this->m_blendModeStack.Data.Size,
                          a2: v64);
    v9 = (struct GFxLog *)(*(int (__thiscall **)(GRenderer::BlendType *))(*Data + 168))(a1: Data);
    GASStringManager::SetLeakReportLog(this: v7, a2: v9, a3: v63);
  }
  GFxMovieRoot::ShutdownTimers(this);
  GHashSetBase<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>,GFixedSizeHash<GPtr<GFxVideoProvider>>,GAllocatorGH<GPtr<GFxVideoProvider>,2>,GHashsetCachedEntry<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>>>::~GHashSetBase<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>,GFixedSizeHash<GPtr<GFxVideoProvider>>,GAllocatorGH<GPtr<GFxVideoProvider>,2>,GHashsetCachedEntry<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>>>(
    this: (CColorCorrectionSystem *)&this->m_projection,
    a2: v64);
  v10 = nullptr;
  if ( this->m_pDevice != nullptr )
  {
    S3DDisplay = (_DWORD *)this->S3DDisplay;
    while ( *S3DDisplay != 0 )
    {
      v10 = (IDirect3DDevice9 *)((char *)v10 + 1);
      S3DDisplay += 2;
      if ( v10 >= this->m_pDevice )
        goto LABEL_15;
    }
    v12 = *(GFxFontLib **)(this->S3DDisplay + 8 * (_DWORD)v10 + 4);
    if ( v12 != nullptr )
      GFxSprite::StopActiveSounds(this: v12, a2: v65);
  }
LABEL_15:
  for ( i = this->m_pDevice; i != nullptr; i = (IDirect3DDevice9 *)((char *)i - 1) )
    GFxSprite::ClearDisplayList(this: *(GFxFontLib **)(this->S3DDisplay + 8 * (_DWORD)i - 4), a2: v65);
  for ( j = this->m_pDevice; j != nullptr; j = (IDirect3DDevice9 *)((char *)j - 1) )
    GFxSprite::ForceShutdown(this: *(GFxFontLib **)(this->S3DDisplay + 8 * (_DWORD)j - 4), a2: v65);
  m_pDevice = this->m_pDevice;
  p_S3DDisplay = &this->S3DDisplay;
  if ( m_pDevice != nullptr )
  {
    v17 = (GRefCountNTSImpl **)(*p_S3DDisplay + 8 * (_DWORD)m_pDevice - 4);
    v18 = this->m_pDevice;
    do
    {
      if ( *v17 != nullptr )
        GRefCountNTSImpl::Release(this: *v17);
      v17 -= 2;
      v18 = (IDirect3DDevice9 *)((char *)v18 - 1);
    }
    while ( v18 != nullptr );
    p_S3DDisplay = &this->S3DDisplay;
    if ( (this->m_blendMode & 0xFFFFFFFE) != 0 )
    {
      if ( *p_S3DDisplay != StereoCenter )
      {
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)*p_S3DDisplay);
        *p_S3DDisplay = StereoCenter;
      }
      this->m_blendMode = Blend_None;
    }
  }
  else if ( this->m_blendMode == Blend_None )
  {
    GArrayDataBase<GFxMovieRoot::LevelInfo,GAllocatorLH<GFxMovieRoot::LevelInfo,326>,GArrayDefaultPolicy>::Reserve(
      this: (void **)&this->S3DDisplay,
      result: (GFxTestStream *)&this->S3DDisplay,
      newCapacity: 0);
  }
  *((_DWORD *)p_S3DDisplay + 1) = 0;
  GFxMovieRoot::ClearStickyVariables(this);
  v19 = *((_DWORD *)this + 2290);
  if ( v19 != 0 )
  {
    if ( *(_DWORD *)v19 != 0 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)v19);
    v20 = *(_DWORD *)(v19 + 20);
    v21 = (*(_DWORD *)(v20 + 8))-- == 1;
    if ( v21 )
      GASStringNode::ReleaseNode();
    v22 = *(_DWORD *)(v19 + 12);
    v23 = *(_DWORD *)(v19 + 8) + 4 * v22 - 4;
    if ( v22 != 0 )
    {
      plqCounta = *(_DWORD *)(v19 + 12);
      do
      {
        v21 = (*(_DWORD *)(*(_DWORD *)v23 + 8))-- == 1;
        if ( v21 )
          GASStringNode::ReleaseNode();
        v23 -= 4;
        --plqCounta;
      }
      while ( plqCounta != 0 );
    }
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(v19 + 8));
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v19);
  }
  v24 = *((_DWORD *)this + 2576);
  plqCounta = 0;
  if ( v24 != 0 )
  {
    v25 = plqCounta;
    do
    {
      *(_BYTE *)(*(_DWORD *)(v24 + 16) + 104) = 1;
      v24 = *(_DWORD *)(v24 + 4);
      ++v25;
    }
    while ( v24 != 0 );
    plqCounta = v25;
    if ( v25 != 0 )
    {
      do
      {
        v26 = *((_DWORD **)this + 2576);
        for ( k = 0; v26 != nullptr; v26 = (_DWORD *)v26[1] )
        {
          if ( (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v26 + 4))(a1: v26) != 0 )
            ++k;
        }
      }
      while ( plqCounta > k );
    }
  }
  while ( *((_DWORD *)this + 2574) != 0 )
  {
    v28 = *((_DWORD **)this + 2574);
    *((_DWORD *)this + 2574) = *v28;
    GFxLoadQueueEntry::~GFxLoadQueueEntry(this: (int)v28);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v28);
  }
  while ( *((_DWORD *)this + 2576) != 0 )
  {
    v29 = *((_DWORD *)this + 2576);
    *((_DWORD *)this + 2576) = *(_DWORD *)(v29 + 4);
    (**(void (__thiscall ***)(int, int))v29)(a1: v29, a2: 1);
  }
  *(_DWORD *)(*((_DWORD *)this + 2289) + 652) = 0;
  v30 = *((void **)this + 2295);
  if ( v30 != nullptr )
  {
    GHashSetBase<GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::InvokeAliasInfo,GASStringHashFunctor>::NodeHashF>>::Clear(a1: *((_DWORD *)this + 2295));
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v30);
  }
  v31 = *((GRefCountNTSImpl **)this + 2563);
  if ( v31 != nullptr )
  {
    do
    {
      RefCount = (GRefCountNTSImpl *)v31[17].RefCount;
      v31[17].RefCount = 0;
      GRefCountNTSImpl::Release(this: v31);
      v31 = RefCount;
    }
    while ( RefCount != nullptr );
  }
  *((_DWORD *)this + 2563) = 0;
  GASValue::DropRefs(this: (GASValue *)this + 2291);
  ((void (__thiscall *)(GMemoryHeap *, _DWORD, unsigned int))GMemory::pGlobalHeap->Free)(
    a1: GMemory::pGlobalHeap,
    a2: LODWORD(this->m_viewportMatrix.M_[3][1]),
    a3: v65);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)LODWORD(this->m_viewportMatrix.M_[3][2]));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)LODWORD(this->S3DParams.DisplayWidthCm));
  GASGlobalContext::PreClean(this: *((GASGlobalContext **)this + 2289), a2: false);
  v71 = (GMatrix3D *)((char *)this + 9224);
  v70 = 0;
  v73 = 0;
  result = nullptr;
  while ( GFxMovieRoot::ActionQueueIterator::getNext(this: (GFxMovieRoot::ActionQueueIterator *)&v70) != nullptr )
    ;
  if ( result != nullptr )
    GFxMovieRoot::ActionQueueType::AddToFreeList(this: v71, (GMatrix3D *)result, pentry: v67, a4: v69);
  GASRefCountCollector::ForceCollect(this: *(GASRefCountCollector **)(LODWORD(this->S3DParams.Distortion) + 12));
  if ( v74 != nullptr )
    GRefCountImpl::Release(this: v74);
  v33 = *((IShaderAPI **)this + 2578);
  if ( v33 != nullptr )
    GRefCountImpl::Release(this: v33);
  v34 = *((IShaderAPI **)this + 2577);
  if ( v34 != nullptr )
    GRefCountImpl::Release(this: v34);
  if ( *((_DWORD *)this + 2572) != 0 )
    FreeLibrary(hLibModule: *((HMODULE *)this + 2572));
  v35 = (GMatrix3D *)((char *)this + 10224);
  for ( m = 15; m >= 0; --m )
  {
    v35 = (GMatrix3D *)((char *)v35 - 52);
    GFxMovieRoot::FocusGroupDescr::~FocusGroupDescr(this: v35);
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 2344));
  v37 = *((_DWORD *)this + 2338);
  v38 = (GRefCountNTSImpl **)(*((_DWORD *)this + 2337) + 4 * v37 - 4);
  if ( v37 != 0 )
  {
    v39 = *((_DWORD *)this + 2338);
    do
    {
      if ( *v38 != nullptr )
        GRefCountNTSImpl::Release(this: *v38);
      --v38;
      --v39;
    }
    while ( v39 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 2337));
  v40 = *((_DWORD *)this + 2335);
  v41 = (GRefCountNTSImpl **)(*((_DWORD *)this + 2334) + 4 * v40 - 4);
  if ( v40 != 0 )
  {
    v42 = *((_DWORD *)this + 2335);
    do
    {
      if ( *v41 != nullptr )
        GRefCountNTSImpl::Release(this: *v41);
      --v41;
      --v42;
    }
    while ( v42 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 2334));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 2330));
  GFxMovieRoot::ActionQueueType::~ActionQueueType(a1: (int)this + 9224, a2: (const float *)v41);
  GHashSetBase<GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>,GHashNode<GASString,GFxMovieRoot::StickyVarNode *,GASStringHashFunctor>::NodeHashF>>::Clear(a1: (char *)this + 9220);
  GASValue::~GASValue(this: (GASValue *)this + 2291);
  v43 = *((GRefCountNTSImpl **)this + 2289);
  if ( v43 != nullptr )
    GRefCountNTSImpl::Release(this: v43);
  v44 = (IShaderAPI *)((char *)this + 9156);
  for ( n = 3; n >= 0; --n )
  {
    v44 -= 415;
    GRefCountImplCore::~GRefCountImplCore(this: v44);
  }
  p_u = &this->m_glyphVertexBuffer[90].u;
  for ( ii = 3; ii >= 0; --ii )
  {
    v48 = *((_DWORD **)p_u - 7);
    p_u -= 9;
    if ( v48 != nullptr )
    {
      v21 = (*v48)-- == 1;
      if ( v21 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v48);
    }
    v49 = *((_DWORD **)p_u + 1);
    if ( v49 != nullptr )
    {
      v21 = (*v49)-- == 1;
      if ( v21 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v49);
    }
    v50 = *(_DWORD **)p_u;
    if ( *(_DWORD *)p_u != 0 )
    {
      v21 = (*v50)-- == 1;
      if ( v21 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v50);
    }
  }
  v51 = (GRefCountNTSImpl *)LODWORD(this->m_projection.M_[1][2]);
  if ( v51 != nullptr )
    GRefCountNTSImpl::Release(this: v51);
  v52 = (IShaderAPI *)LODWORD(this->m_projection.M_[1][1]);
  if ( v52 != nullptr )
    GRefCountImpl::Release(this: v52);
  v53 = (IShaderAPI *)LODWORD(this->m_projection.M_[1][0]);
  if ( v53 != nullptr )
    GRefCountImpl::Release(this: v53);
  v54 = (IShaderAPI *)LODWORD(this->m_projection.M_[0][3]);
  if ( v54 != nullptr )
    GRefCountImpl::Release(this: v54);
  v55 = (IShaderAPI *)LODWORD(this->m_projection.M_[0][2]);
  if ( v55 != nullptr )
    GRefCountImpl::Release(this: v55);
  v56 = (IShaderAPI *)LODWORD(this->m_projection.M_[0][1]);
  if ( v56 != nullptr )
    GRefCountImpl::Release(this: v56);
  GHashSetBase<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>,GFixedSizeHash<GPtr<GFxVideoProvider>>,GAllocatorGH<GPtr<GFxVideoProvider>,2>,GHashsetCachedEntry<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>>>::~GHashSetBase<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>,GFixedSizeHash<GPtr<GFxVideoProvider>>,GAllocatorGH<GPtr<GFxVideoProvider>,2>,GHashsetCachedEntry<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>>>(
    this: (CColorCorrectionSystem *)&this->m_projection,
    a2: (unsigned int)v67);
  v57 = (IShaderAPI *)LODWORD(this->m_currentCxform.M_[3][1]);
  if ( v57 != nullptr )
    GRefCountImpl::Release(this: v57);
  Size = (IShaderDevice *)this->m_blendModeStack.Data.Size;
  if ( Size != nullptr )
    GFxResource::Release(this: Size);
  v59 = this->m_pDevice;
  v60 = (GRefCountNTSImpl **)(this->S3DDisplay + 8 * (_DWORD)v59 - 4);
  if ( v59 != nullptr )
  {
    v61 = this->m_pDevice;
    do
    {
      if ( *v60 != nullptr )
        GRefCountNTSImpl::Release(this: *v60);
      v60 -= 2;
      v61 = (IDirect3DDevice9 *)((char *)v61 - 1);
    }
    while ( v61 != nullptr );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)this->S3DDisplay);
  Distortion = this->S3DParams.Distortion;
  if ( Distortion != 0.0 )
    GRefCountImpl::Release(this: (IShaderAPI *)LODWORD(Distortion));
  this->Handlers.Root.pPrev = (GRendererEventHandler *)&GFxStateBag::`vftable';
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101402C0
// Name: public: GFxTextFormat::GFxTextFormat(class GFxTextFormat const __near &,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
GStringDH *__thiscall GFxTextFormat::GFxTextFormat(
        GStringDH *this,
        const CMemberFuncProxyBase<IMaterialInternal *,void (__thiscall IMaterial::*)(float),CFuncMemPolicyNone> *result,
        CUtlBuffer *srcfmt_4)
{
  CUtlBuffer *v3; // ebx
  CUtlBuffer *m_pObject; // eax
  void (__thiscall *m_pfnProxied)(IMaterial *, float); // eax
  IMaterialInternal *v7; // eax

  v3 = srcfmt_4;
  this->HeapTypeBits = (unsigned int)&GRefCountImplCore::`vftable';
  this->pHeap = (GMemoryHeap *)1;
  this->HeapTypeBits = (unsigned int)&GFxTextFormat::`vftable';
  m_pObject = srcfmt_4;
  if ( srcfmt_4 == nullptr )
    m_pObject = (CUtlBuffer *)result[1].m_pObject;
  GStringDH::CopyConstructHelper(this: this + 1, a2: (const struct GString *)&result[1], pheap: m_pObject);
  if ( srcfmt_4 == nullptr )
    v3 = (CUtlBuffer *)result[1].m_pObject;
  GStringDH::CopyConstructHelper(this: this + 2, a2: (const struct GString *)&result[2], pheap: v3);
  m_pfnProxied = result[3].m_pfnProxied;
  if ( m_pfnProxied != nullptr )
    ++*((_DWORD *)m_pfnProxied + 1);
  *((_DWORD *)this + 6) = result[3].m_pfnProxied;
  v7 = result[3].m_pObject;
  if ( v7 != nullptr )
    ++v7->__vftable;
  *((_DWORD *)this + 7) = result[3].m_pObject;
  *(this + 4) = (GStringDH)result[4];
  *((_BYTE *)this + 40) = result[5].m_pfnProxied;
  *((_WORD *)this + 21) = HIWORD(result[5].m_pfnProxied);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1028CBC0
// Name: _GFxTextFormat::GetFontList_::_2_::_dynamic_atexit_destructor_for__emptyStr__
// Source: json
//------------------------------------------------------------------------------
int GFxTextFormat::GetFontList_::_2_::_dynamic_atexit_destructor_for__emptyStr__()
{
  unsigned int v0; // esi
  int result; // eax

  v0 = (int)GFxRectangle_NaNParams.Info.pName & 0xFFFFFFFC;
  result = InterlockedExchangeAdd(
             Addend: (volatile LONG *)(((int)GFxRectangle_NaNParams.Info.pName & 0xFFFFFFFC) + 4),
             Value: -1)
         - 1;
  if ( result == 0 )
    return ((int (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
             a1: GMemory::pGlobalHeap,
             a2: v0);
  return result;
}
