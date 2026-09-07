// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasmouse.cpp
// Functions: 25
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasmouse.h"

//------------------------------------------------------------------------------
// Address: 0x1010AF50
// Name: protected: static void GASMouseCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMouseCtorFunction::GlobalCtor(int a1@<edi>, int fna)
{
  GASValue *v3; // esi

  v3 = *(GASValue **)(fna + 4);
  GASValue::DropRefs(this: v3, a2: a1);
  *(_BYTE *)v3 = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10117B30
// Name: protected: static void GASMouseCtorFunction::GetButtonsState(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMouseCtorFunction::GetButtonsState(long double a1@<st0>, int fna)
{
  GASValue *v3; // edi
  unsigned int v4; // edi
  struct GFxMovieRoot *MovieRoot; // ebx
  GASValue *v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // edi
  _SERVICE_STATUS *v10; // [esp-4h] [ebp-18h]

  v3 = *(GASValue **)(fna + 4);
  GASValue::DropRefs(this: v3, a2: (int)v3);
  *(_BYTE *)v3 = 0;
  v4 = 0;
  MovieRoot = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fna + 24));
  if ( *(int *)(fna + 28) > 0 )
  {
    v10 = *(_SERVICE_STATUS **)(fna + 24);
    v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
    v4 = (__int64)GASValue::ToNumber(this: v6, a2: 0, a3: a1, result: v10);
  }
  if ( v4 < (*(int (__thiscall **)(struct GFxMovieRoot *))(*(_DWORD *)MovieRoot + 228))(a1: MovieRoot) )
  {
    if ( v4 < 4 )
      v7 = (int)MovieRoot + 36 * v4 + 2356;
    else
      v7 = 0;
    v8 = *(_DWORD *)(fna + 4);
    v9 = *(_DWORD *)(v7 + 12);
    if ( *(_BYTE *)v8 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v8, a2: v9);
    *(_BYTE *)v8 = 3;
    *(double *)(v8 + 4) = (double)(unsigned int)v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117BE0
// Name: protected: virtual bool GASMouseCtorFunction::IsEmpty(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMouseCtorFunction::IsEmpty(
        GHashSet<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10117C00
// Name: protected: static void GASMouseCtorFunction::Show(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMouseCtorFunction::Show(long double a1@<st0>, int fna)
{
  GASValue *v3; // edi
  struct GFxMovieRoot *MovieRoot; // edi
  int v5; // eax
  GASValue *v6; // eax
  int v7; // ecx
  _SERVICE_STATUS *v8; // [esp-4h] [ebp-18h]
  _DWORD v9[3]; // [esp+8h] [ebp-Ch] BYREF

  v3 = *(GASValue **)(fna + 4);
  GASValue::DropRefs(this: v3, a2: (int)v3);
  *(_BYTE *)v3 = 0;
  MovieRoot = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fna + 24));
  if ( *((_DWORD *)MovieRoot + 63) != 0 )
  {
    v5 = 0;
    if ( *(int *)(fna + 28) >= 1 )
    {
      v8 = *(_SERVICE_STATUS **)(fna + 24);
      v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
      v5 = GASValue::ToUInt32(this: v6, a2: (int)MovieRoot, a3: a1, a4: v8);
    }
    v7 = *((_DWORD *)MovieRoot + 63);
    v9[2] = v5;
    v9[0] = 10;
    v9[1] = 0;
    (*(void (__thiscall **)(int, struct GFxMovieRoot *, _DWORD *))(*(_DWORD *)v7 + 4))(a1: v7, a2: MovieRoot, a3: v9);
  }
  else
  {
    GASEnvironment::LogScriptWarning(
      this: *(GASEnvironment **)(fna + 24),
      a2: "Warning: no user event handler interface is installed; Mouse.show failed.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117C90
// Name: protected: static void GASMouseCtorFunction::Hide(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMouseCtorFunction::Hide(long double a1@<st0>, int fna)
{
  GASValue *v3; // edi
  struct GFxMovieRoot *MovieRoot; // edi
  int v5; // eax
  GASValue *v6; // eax
  int v7; // ecx
  _SERVICE_STATUS *v8; // [esp-4h] [ebp-18h]
  _DWORD v9[3]; // [esp+8h] [ebp-Ch] BYREF

  v3 = *(GASValue **)(fna + 4);
  GASValue::DropRefs(this: v3, a2: (int)v3);
  *(_BYTE *)v3 = 0;
  MovieRoot = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fna + 24));
  if ( *((_DWORD *)MovieRoot + 63) != 0 )
  {
    v5 = 0;
    if ( *(int *)(fna + 28) >= 1 )
    {
      v8 = *(_SERVICE_STATUS **)(fna + 24);
      v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
      v5 = GASValue::ToUInt32(this: v6, a2: (int)MovieRoot, a3: a1, a4: v8);
    }
    v7 = *((_DWORD *)MovieRoot + 63);
    v9[2] = v5;
    v9[0] = 11;
    v9[1] = 0;
    (*(void (__thiscall **)(int, struct GFxMovieRoot *, _DWORD *))(*(_DWORD *)v7 + 4))(a1: v7, a2: MovieRoot, a3: v9);
  }
  else
  {
    GASEnvironment::LogScriptWarning(
      this: *(GASEnvironment **)(fna + 24),
      a2: "Warning: no user event handler interface is installed; Mouse.hide failed.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117D20
// Name: public: static bool GASMouseCtorFunction::SetCursorType(class GFxMovieRoot __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
static char __cdecl GASMouseCtorFunction::SetCursorType(
        struct GFxMovieRoot *a1,
        unsigned int mouseIndex,
        unsigned int cursorType)
{
  int v3; // ecx
  _DWORD v5[3]; // [esp+0h] [ebp-Ch] BYREF

  v3 = *((_DWORD *)a1 + 63);
  if ( v3 == 0 )
    return 0;
  v5[1] = cursorType;
  v5[0] = 12;
  v5[2] = mouseIndex;
  (*(void (__thiscall **)(int, struct GFxMovieRoot *, _DWORD *))(*(_DWORD *)v3 + 4))(a1: v3, a2: a1, a3: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10117D60
// Name: protected: virtual void GASMouseCtorFunction::OnMouseMove(class GASEnvironment __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMouseCtorFunction::OnMouseMove(
        GASMouseCtorFunction *this,
        struct GASEnvironment *penv,
        unsigned int a3)
{
  GASAsBroadcaster::BroadcastMessageWithCallback(penv);
}

//------------------------------------------------------------------------------
// Address: 0x10117DC0
// Name: protected: virtual void GASMouseCtorFunction::OnMouseDown(class GASEnvironment __near *,unsigned int,unsigned int,class GFxASCharacter __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMouseCtorFunction::OnMouseDown(
        GHashSet<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this,
        struct GFxAmpStream *penv,
        unsigned int mouseIndex,
        unsigned int button,
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *a5)
{
  _BYTE *v6; // ecx
  unsigned __int64 v7; // rax
  struct GFxMovieRoot *MovieRoot; // eax
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  unsigned int tm; // [esp+30h] [ebp-8h]
  float mouseIndexb; // [esp+44h] [ebp+Ch]
  float mouseIndexc; // [esp+44h] [ebp+Ch]
  unsigned int mouseIndexa; // [esp+44h] [ebp+Ch]

  v6 = *((_BYTE **)penv + 30);
  if ( v6[684] == 1 )
  {
    GTimer::GetTicks(this: v6);
    tm = v7 / 0x3E8;
    MovieRoot = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)penv);
    if ( mouseIndex < 4 )
      v9 = (int)MovieRoot + 36 * mouseIndex + 2356;
    else
      v9 = 0;
    mouseIndexb = *(float *)(v9 + 20) / 20.0;
    v10 = (int)mouseIndexb;
    mouseIndexc = *(float *)(v9 + 24) / 20.0;
    *((_DWORD *)this + 2) = v10;
    *((_DWORD *)this + 3) = (int)mouseIndexc;
    *((_DWORD *)this + 4) = tm;
  }
  if ( a5 != nullptr )
  {
    v11 = DWORD1(a5[6].m_pfnProxied);
    if ( v11 == 0 )
      GFxASCharacter::CreateCharacterHandle(this: a5);
    mouseIndexa = *(_DWORD *)(v11 + 12);
    ++*(_DWORD *)(mouseIndexa + 8);
    GASAsBroadcaster::BroadcastMessageWithCallback(penv);
    if ( (*(_DWORD *)(mouseIndexa + 8))-- == 1 )
      GASStringNode::ReleaseNode(a1: mouseIndexa);
  }
  else
  {
    GASAsBroadcaster::BroadcastMessageWithCallback(penv);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117F50
// Name: protected: virtual void GASMouseCtorFunction::OnMouseUp(class GASEnvironment __near *,unsigned int,unsigned int,class GFxASCharacter __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMouseCtorFunction::OnMouseUp(
        GHashSet<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this,
        int a2,
        unsigned int mouseIndex,
        unsigned int button,
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *a5)
{
  int v6; // eax
  struct GFxAmpStream *v7; // ecx
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v9; // [esp+38h] [ebp+14h]

  if ( a5 != nullptr )
  {
    v6 = DWORD1(a5[6].m_pfnProxied);
    if ( v6 == 0 )
      GFxASCharacter::CreateCharacterHandle(this: a5);
    v9 = *(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> **)(v6 + 12);
    ++DWORD2(v9->m_pfnProxied);
    if ( this == (GHashSet<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)56 )
      v7 = nullptr;
    else
      v7 = (struct GFxAmpStream *)(this - 10);
    GASAsBroadcaster::BroadcastMessageWithCallback(penv: v7);
    if ( DWORD2(v9->m_pfnProxied)-- == 1 )
      GASStringNode::ReleaseNode(a1: (int)v9);
  }
  else
  {
    GASAsBroadcaster::BroadcastMessageWithCallback(penv: (struct GFxAmpStream *)(*(_DWORD *)(a2 + 120) + 424));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118040
// Name: protected: virtual void GASMouseCtorFunction::OnMouseWheel(class GASEnvironment __near *,unsigned int,int,class GFxASCharacter __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMouseCtorFunction::OnMouseWheel(
        GHashSet<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this,
        const GHashSet<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *penv,
        unsigned int mouseIndex,
        int sdelta,
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *a5)
{
  int v6; // eax
  struct GFxAmpStream *v7; // ecx
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v9; // [esp+38h] [ebp+14h]

  if ( a5 != nullptr )
  {
    v6 = DWORD1(a5[6].m_pfnProxied);
    if ( v6 == 0 )
      GFxASCharacter::CreateCharacterHandle(this: a5);
    v9 = *(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> **)(v6 + 12);
    ++DWORD2(v9->m_pfnProxied);
    if ( this == (GHashSet<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)56 )
      v7 = nullptr;
    else
      v7 = (struct GFxAmpStream *)(this - 10);
    GASAsBroadcaster::BroadcastMessageWithCallback(penv: v7);
    if ( DWORD2(v9->m_pfnProxied)-- == 1 )
      GASStringNode::ReleaseNode(a1: (int)v9);
  }
  else
  {
    GASAsBroadcaster::BroadcastMessageWithCallback(penv: (struct GFxAmpStream *)((char *)penv[30].pTable + 432));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118130
// Name: protected: static void GASMouseCtorFunction::SetCursorType(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMouseCtorFunction::SetCursorType(double a1@<st0>, int fna)
{
  GASValue *v3; // edi
  int v4; // edi
  struct GFxMovieRoot *MovieRoot; // ebx
  GASValue *v6; // eax
  unsigned int v7; // eax
  GASValue *v8; // eax
  int v9; // ecx
  _SERVICE_STATUS *v10; // [esp-4h] [ebp-1Ch]
  _SERVICE_STATUS *v11; // [esp-4h] [ebp-1Ch]
  int v12; // [esp+Ch] [ebp-Ch] BYREF
  __int64 v13; // [esp+10h] [ebp-8h]

  v3 = *(GASValue **)(fna + 4);
  GASValue::DropRefs(this: v3, a2: (int)v3);
  *(_BYTE *)v3 = 0;
  v4 = 0;
  MovieRoot = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fna + 24));
  if ( *(int *)(fna + 28) > 0 )
  {
    v10 = *(_SERVICE_STATUS **)(fna + 24);
    v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
    a1 = GASValue::ToNumber(this: v6, a2: 0, a3: a1, result: v10);
    v13 = (__int64)a1;
    v4 = (__int64)a1;
  }
  v7 = 0;
  if ( *(int *)(fna + 28) >= 2 )
  {
    v11 = *(_SERVICE_STATUS **)(fna + 24);
    v8 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 1);
    v13 = (__int64)GASValue::ToNumber(this: v8, a2: v4, a3: a1, result: v11);
    v7 = v13;
  }
  v9 = *((_DWORD *)MovieRoot + 63);
  if ( v9 != 0 )
  {
    v12 = 12;
    v13 = __PAIR64__(v7, v4);
    (*(void (__thiscall **)(int, struct GFxMovieRoot *, int *))(*(_DWORD *)v9 + 4))(a1: v9, a2: MovieRoot, a3: &v12);
  }
  else
  {
    GASEnvironment::LogScriptWarning(
      this: *(GASEnvironment **)(fna + 24),
      a2: "Warning: no user event handler interface is installed; Mouse.setCursorType failed.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118210
// Name: protected: static void GASMouseCtorFunction::GetTopMostEntity(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMouseCtorFunction::GetTopMostEntity(long double a1@<st0>, int fna)
{
  GASValue *v3; // edi
  struct GFxMovieRoot *MovieRoot; // ebx
  unsigned int v5; // edi
  bool v6; // cc
  char *v7; // eax
  char v8; // al
  long double v9; // st7
  GASValue *v10; // eax
  int v11; // eax
  int v12; // eax
  GASValue *v13; // eax
  char *v14; // eax
  GASValue *v15; // eax
  GASValue *v16; // eax
  GFxCharacter *v17; // ebx
  tagBITMAPCOREHEADER *TopMostEntity; // eax
  tagPOLYTEXTW *v19; // [esp-4h] [ebp-5Ch]
  _SERVICE_STATUS *v20; // [esp-4h] [ebp-5Ch]
  _SERVICE_STATUS *v21; // [esp-4h] [ebp-5Ch]
  tagPOLYTEXTW *v22; // [esp-4h] [ebp-5Ch]
  _SERVICE_STATUS *v23; // [esp-4h] [ebp-5Ch]
  _SERVICE_STATUS *v24; // [esp-4h] [ebp-5Ch]
  int v25; // [esp+0h] [ebp-58h]
  long double v26; // [esp+Ch] [ebp-4Ch]
  double v27; // [esp+14h] [ebp-44h]
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> result; // [esp+1Ch] [ebp-3Ch] BYREF
  __int64 result_8; // [esp+24h] [ebp-34h] BYREF
  int testAll; // [esp+2Ch] [ebp-2Ch]
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>_vtbl *v31; // [esp+30h] [ebp-28h]
  int v32; // [esp+34h] [ebp-24h]
  unsigned __int16 v33; // [esp+3Ah] [ebp-1Eh]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v34; // [esp+3Ch] [ebp-1Ch] BYREF

  v3 = *(GASValue **)(fna + 4);
  GASValue::DropRefs(this: v3, a2: (int)v3);
  *(_BYTE *)v3 = 0;
  MovieRoot = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fna + 24));
  v5 = 0;
  v6 = *(_DWORD *)(fna + 28) < 1;
  v32 = (int)MovieRoot;
  LOBYTE(testAll) = 1;
  if ( v6 )
    goto LABEL_5;
  if ( *(_BYTE *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0) == 2 )
  {
    v19 = *(tagPOLYTEXTW **)(fna + 24);
    v7 = (char *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
    v8 = GASValue::ToBool(a1: v7, a2: a1, result: v19);
    v6 = *(_DWORD *)(fna + 28) < 2;
    LOBYTE(testAll) = v8;
    if ( !v6 )
    {
      v20 = *(_SERVICE_STATUS **)(fna + 24);
      v10 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 1);
      v32 = v33 | 0xC00;
      result_8 = (__int64)GASValue::ToNumber(this: v10, a2: 0, a3: v9, result: v20);
      v5 = result_8;
    }
    goto LABEL_5;
  }
  v12 = *(_DWORD *)(fna + 28);
  if ( v12 == 1 )
  {
    v21 = *(_SERVICE_STATUS **)(fna + 24);
    v13 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
    v32 = v33 | 0xC00;
    result_8 = (__int64)GASValue::ToNumber(this: v13, a2: 0, a3: a1, result: v21);
    v5 = result_8;
LABEL_5:
    if ( v5 >= (*(int (__thiscall **)(struct GFxMovieRoot *))(*(_DWORD *)MovieRoot + 228))(a1: MovieRoot) )
      return;
    if ( v5 < 4 )
      v11 = (int)MovieRoot + 36 * v5 + 2356;
    else
      v11 = 0;
    v31 = *(GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>_vtbl **)(v11 + 20);
    v32 = *(int *)(v11 + 24);
    result.__vftable = v31;
    result.pContainer = (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>::SysAllocContainer *)v32;
    goto LABEL_15;
  }
  if ( v12 < 2 )
    goto LABEL_5;
  if ( v12 >= 3 )
  {
    v22 = *(tagPOLYTEXTW **)(fna + 24);
    v14 = (char *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 2);
    LOBYTE(testAll) = GASValue::ToBool(a1: v14, a2: a1, result: v22);
  }
  v23 = *(_SERVICE_STATUS **)(fna + 24);
  v15 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  v26 = GASValue::ToNumber(this: v15, a2: 0, a3: a1, result: v23);
  v24 = *(_SERVICE_STATUS **)(fna + 24);
  v16 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 1);
  v27 = GASValue::ToNumber(this: v16, a2: 0, a3: v26, result: v24);
  v17 = *((GFxCharacter **)MovieRoot + 12);
  if ( v17 != nullptr )
  {
    GMatrix2D::SetIdentity(this: (float *)&v34);
    GFxCharacter::GetWorldMatrix(this: v17, pmat: (CMaterialDict *)&v34);
    *(float *)&result_8 = v26 * 20.0;
    *((float *)&result_8 + 1) = 20.0 * v27;
    GMatrix2D::Transform(
      this: &v34,
      (CCountedStringPoolBase<unsigned int>::hash_item_t *)&result,
      p: (float *)&result_8,
      p_4: v25);
    MovieRoot = (struct GFxMovieRoot *)v32;
LABEL_15:
    TopMostEntity = (tagBITMAPCOREHEADER *)GFxMovieRoot::GetTopMostEntity(
                                             this: (int)MovieRoot,
                                             &result,
                                             a3: *(float *)&v5,
                                             testAll,
                                             ignoreMC: 0);
    if ( TopMostEntity != nullptr )
      GASValue::SetAsCharacter(this: *(_DWORD *)(fna + 4), result: TopMostEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101183F0
// Name: protected: void GASMouseCtorFunction::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMouseCtorFunction::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(int this)
{
  int v2; // ecx
  int v3; // eax

  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this: (int *)(this + 76));
  v2 = *(_DWORD *)(this + 60);
  if ( v2 != 0 )
  {
    v3 = ++*(_DWORD *)(v2 + 8);
    if ( (v3 & 0x70000000) != 0 )
    {
      *(_DWORD *)(v2 + 8) = v3 & 0x8FFFFFFF;
      (**(void (__thiscall ***)(int, int))v2)(a1: v2, a2: 2);
    }
  }
  GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>((ISteamUserStats *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10118430
// Name: protected: void GASMouseCtorFunction::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMouseCtorFunction::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(int this)
{
  int v2; // ecx

  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this: (int *)(this + 76));
  v2 = *(_DWORD *)(this + 60);
  if ( v2 != 0 && (--*(_DWORD *)(v2 + 8) & 0x70000000) != 0x10000000 )
  {
    *(_DWORD *)(v2 + 8) = *(_DWORD *)(v2 + 8) & 0x8FFFFFFF | 0x10000000;
    (**(void (__thiscall ***)(int, int))v2)(a1: v2, a2: 1);
  }
  GASObject::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>((ISteamUserStats *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10118480
// Name: protected: void GASMouseCtorFunction::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMouseCtorFunction::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(int this)
{
  int v2; // ecx
  int v3; // eax

  GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this: (int *)(this + 76));
  v2 = *(_DWORD *)(this + 60);
  if ( v2 != 0 )
  {
    v3 = *(_DWORD *)(v2 + 8);
    if ( (v3 & 0x70000000) == 0x10000000 )
    {
      if ( (v3 & 0xFFFFFFF) != 0 )
      {
        *(_DWORD *)(v2 + 8) = v3 & 0x8FFFFFFF;
        (**(void (__thiscall ***)(int, int))v2)(a1: v2, a2: 2);
        GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>((ISteamUserStats *)this);
        return;
      }
      *(_DWORD *)(v2 + 8) = v3 & 0x8FFFFFFF | 0x20000000;
      (**(void (__thiscall ***)(int, int))v2)(a1: v2, a2: 4);
    }
  }
  GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>((ISteamUserStats *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101184F0
// Name: protected: virtual void GASMouseCtorFunction::ExecuteForEachChild_GC(enum GRefCountBaseGC<323>::OperationGC)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASMouseCtorFunction::ExecuteForEachChild_GC(
        int a1@<ecx>,
        int a2@<edi>,
        const GHashSet<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *result)
{
  int v4; // ecx
  _DWORD *v5; // ecx

  switch ( (unsigned int)result )
  {
    case 0u:
      GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(a1: (int *)(a1 + 76), a2);
      v4 = *(_DWORD *)(a1 + 60);
      if ( v4 != 0 )
        GRefCountBaseGC<323>::Release(a1: v4, a2);
      GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(this: (ISteamUserStats *)a1);
      break;
    case 1u:
      GASMouseCtorFunction::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this: a1);
      break;
    case 2u:
      GASMouseCtorFunction::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this: a1);
      break;
    case 3u:
      GASFunctionRefBase::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this: (_DWORD *)(a1 + 76));
      v5 = *(_DWORD **)(a1 + 60);
      if ( v5 != nullptr )
        GRefCountBaseGC<323>::CollectGarbage(this: v5);
      GASObject::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this: (ISteamUserStats *)a1);
      break;
    case 4u:
      GASMouseCtorFunction::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this: a1);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118580
// Name: protected: void GASMouseCtorFunction::UpdateListenersArray(class GASStringContext __near *,class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMouseCtorFunction::UpdateListenersArray(
        GHashSet<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this,
        _DWORD *psc,
        const struct GASEnvironment *psc_4)
{
  int v4; // edi
  unsigned __int8 (__thiscall *v5)(GHashSet<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *, _DWORD *, int, GASValue *); // eax
  struct GASObject *v6; // eax
  int v7; // ecx
  int v8; // ecx
  int v9; // [esp-8h] [ebp-24h]
  GASValue listenersVal[4]; // [esp+Ch] [ebp-10h] BYREF

  v4 = *((_DWORD *)this + 4);
  v9 = *psc + 332;
  v5 = *(unsigned __int8 (__thiscall **)(GHashSet<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *, _DWORD *, int, GASValue *))(v4 + 44);
  LOBYTE(listenersVal[0]) = 0;
  if ( v5(a1: this + 4, a2: psc, a3: v9, a4: listenersVal) == 0 )
  {
LABEL_10:
    GASValue::~GASValue(this: listenersVal, a2: v4);
    return;
  }
  v6 = GASValue::ToObject(this: listenersVal, a2: v4, a3: psc_4);
  v4 = (int)v6;
  if ( v6 == nullptr || ((int (__thiscall *)(struct GASObject *))v6[2].pNode[1].pNext)(a1: &v6[2]) != 7 )
  {
    v8 = *((_DWORD *)this + 15);
    if ( v8 != 0 )
      GRefCountBaseGC<323>::Release(a1: v8, a2: v4);
    *((_DWORD *)this + 15) = 0;
    goto LABEL_10;
  }
  *(_DWORD *)(v4 + 8) = (*(_DWORD *)(v4 + 8) + 1) & 0x8FFFFFFF;
  v7 = *((_DWORD *)this + 15);
  if ( v7 != 0 )
    GRefCountBaseGC<323>::Release(a1: v7, a2: v4);
  *((_DWORD *)this + 15) = v4;
  GASValue::~GASValue(this: listenersVal, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10118620
// Name: protected: static void GASMouseCtorFunction::GetPosition(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASMouseCtorFunction::GetPosition(long double a1@<st0>, _CONNECTDLGSTRUCTW fna)
{
  unsigned int cbStructure; // esi
  GASValue *v4; // edi
  unsigned int v5; // edi
  struct GFxMovieRoot *MovieRoot; // ebx
  GASValue *v7; // eax
  int v8; // eax
  int v9; // edx
  int v10; // ecx
  struct GASObject *v11; // edi
  double v12; // st7
  int X; // [esp+8h] [ebp-2Ch]
  _SERVICE_STATUS *X_4; // [esp+Ch] [ebp-28h]
  double v15[2]; // [esp+1Ch] [ebp-18h] BYREF
  __int64 v16; // [esp+2Ch] [ebp-8h]

  cbStructure = fna.cbStructure;
  v4 = *(GASValue **)(fna.cbStructure + 4);
  GASValue::DropRefs(this: v4, a2: (int)v4);
  *(_BYTE *)v4 = 0;
  v5 = 0;
  MovieRoot = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(cbStructure + 24));
  if ( *(int *)(cbStructure + 28) > 0 )
  {
    X_4 = *(_SERVICE_STATUS **)(cbStructure + 24);
    v7 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 0);
    v16 = (__int64)GASValue::ToNumber(this: v7, a2: 0, a3: a1, result: X_4);
    v5 = v16;
  }
  if ( v5 < (*(int (__thiscall **)(struct GFxMovieRoot *))(*(_DWORD *)MovieRoot + 228))(a1: MovieRoot) )
  {
    if ( v5 < 4 )
      v8 = (int)MovieRoot + 36 * v5 + 2356;
    else
      v8 = 0;
    v9 = *(_DWORD *)(cbStructure + 24);
    *(float *)&v16 = *(float *)(v8 + 20);
    fna.cbStructure = 323;
    v10 = *(_DWORD *)(*(_DWORD *)(v9 + 120) + 656);
    *((float *)&v16 + 1) = *(float *)(v8 + 24);
    if ( (*(int (__thiscall **)(int, int, _CONNECTDLGSTRUCTW *))(*(_DWORD *)v10 + 40))(a1: v10, a2: 52, a3: &fna) != 0 )
      v11 = (struct GASObject *)GASPointObject::GASPointObject(result: *(GArrayLH<GFxMovieRoot *,2,GArrayDefaultPolicy> **)(cbStructure + 24));
    else
      v11 = nullptr;
    v15[0] = floor(X: *(float *)&v16 + 0.5) / 20.0;
    v12 = floor(X: *((float *)&v16 + 1) + 0.5);
    X = *(_DWORD *)(cbStructure + 24);
    v15[1] = v12 / 20.0;
    GASPointObject::SetProperties(a1: X, a2: v15);
    GASValue::SetAsObject(this: *(GASValue **)(cbStructure + 4), a2: v11);
    if ( v11 != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v11, a2: (int)v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118750
// Name: public: virtual bool GASMouseCtorFunction::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMouseCtorFunction::GetMember(
        GHashLH<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>,2,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this,
        ID3DXFont *result,
        _IMAGE_SYMBOL_EX *name,
        GASValue *a4)
{
  ID3DXFont_vtbl *v4; // eax
  int v5; // edi
  unsigned int Short; // ecx
  double v8; // st7
  tagWNDCLASSW *v9; // eax
  tagWNDCLASSW *v10; // eax
  tagWNDCLASSW *v11; // eax
  GASValue v12[4]; // [esp+Ch] [ebp-10h] BYREF

  v4 = result[30].__vftable;
  v5 = (int)&result[30];
  if ( LOBYTE(v4[9].GetGlyphData) != 1 )
    goto LABEL_9;
  Short = name->N.Name.Short;
  if ( (HRESULT (__stdcall *)(ID3DXFont *, const char *, int))name->N.Name.Short == v4[7].PreloadTextA )
  {
    GASValue::SetAsFunction(this: a4, func: (const struct GASFunctionRefBase *)(this + 15));
    return;
  }
  if ( (HRESULT (__stdcall *)(ID3DXFont *, const wchar_t *, int))Short == v4[7].PreloadTextW )
  {
LABEL_5:
    if ( *(_BYTE *)a4 >= 5u )
      GASValue::DropRefs(this: a4, a2: v5);
    v8 = 1.0;
    *(_BYTE *)a4 = 3;
LABEL_8:
    *(double *)(a4 + 1) = v8;
LABEL_9:
    GASObject::GetMember((D3DXQUATERNION *)this, result, penv: name, val: (int *)a4);
    return;
  }
  if ( (int (__stdcall *)(ID3DXFont *, ID3DXSprite *, const char *, int, tagRECT *, unsigned int, unsigned int))Short == v4[7].DrawTextA )
    goto LABEL_11;
  if ( (int (__stdcall *)(ID3DXFont *, ID3DXSprite *, const wchar_t *, int, tagRECT *, unsigned int, unsigned int))Short == v4[7].DrawTextW )
  {
    if ( *(_BYTE *)a4 >= 5u )
      GASValue::DropRefs(this: a4, a2: v5);
    v8 = 3.0;
    *(_BYTE *)a4 = 3;
    goto LABEL_8;
  }
  if ( (HRESULT (__stdcall *)(ID3DXFont *))Short == v4[7].OnLostDevice )
  {
    if ( *(_BYTE *)a4 >= 5u )
      GASValue::DropRefs(this: a4, a2: v5);
    v8 = 0.0;
    *(_BYTE *)a4 = 3;
    goto LABEL_8;
  }
  if ( (HRESULT (__stdcall *)(ID3DXFont *))Short == v4[7].OnResetDevice )
    goto LABEL_5;
  if ( (HRESULT (__stdcall *)(IUnknown *, const _GUID *, void **))Short == v4[8].QueryInterface )
  {
LABEL_11:
    if ( *(_BYTE *)a4 >= 5u )
      GASValue::DropRefs(this: a4, a2: v5);
    v8 = 2.0;
    *(_BYTE *)a4 = 3;
    goto LABEL_8;
  }
  if ( GASString::operator==(this: (const char ***)name, a2: "getTopMostEntity") )
  {
    v9 = (tagWNDCLASSW *)GASValue::GASValue(
                           this: v12,
                           func: v5,
                           a3: (void (__cdecl *)(const struct GASFnCall *))GASMouseCtorFunction::GetTopMostEntity);
    GASValue::operator=(this: (int)a4, v: v9);
    GASValue::~GASValue(this: v12, a2: v5);
  }
  else if ( GASString::operator==(this: (const char ***)name, a2: "getPosition") )
  {
    v10 = (tagWNDCLASSW *)GASValue::GASValue(
                            this: v12,
                            func: v5,
                            a3: (void (__cdecl *)(const struct GASFnCall *))GASMouseCtorFunction::GetPosition);
    GASValue::operator=(this: (int)a4, v: v10);
    GASValue::~GASValue(this: v12, a2: v5);
  }
  else
  {
    if ( !GASString::operator==(this: (const char ***)name, a2: "getButtonsState") )
      goto LABEL_9;
    v11 = (tagWNDCLASSW *)GASValue::GASValue(
                            this: v12,
                            func: v5,
                            a3: (void (__cdecl *)(const struct GASFnCall *))GASMouseCtorFunction::GetButtonsState);
    GASValue::operator=(this: (int)a4, v: v11);
    GASValue::~GASValue(this: v12, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101188F0
// Name: public: bool GASMouseCtorFunction::HasOverloadedCursorTypeFunction(class GASStringContext __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASMouseCtorFunction::HasOverloadedCursorTypeFunction(
        GHashLH<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>,2,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this@<ecx>,
        int a2@<edi>,
        int psc)
{
  GASValue *v3; // eax
  GASValue v4[4]; // [esp+8h] [ebp-1Ch] BYREF
  int v5; // [esp+18h] [ebp-Ch] BYREF
  int v6; // [esp+1Ch] [ebp-8h]
  char v7; // [esp+20h] [ebp-4h]

  v3 = GASValue::GASValue(
         this: v4,
         func: psc,
         a3: (void (__cdecl *)(const struct GASFnCall *))GASMouseCtorFunction::SetCursorType);
  GASValue::ToFunction(a1: (int)v3, a2, a3: (int)&v5, a4: 0);
  if ( (v7 & 2) == 0 && v5 != 0 )
    GRefCountBaseGC<323>::Release(a1: v5, a2);
  v5 = 0;
  if ( (v7 & 1) == 0 && v6 != 0 )
    GRefCountBaseGC<323>::Release(a1: v6, a2);
  v6 = 0;
  GASValue::~GASValue(this: v4, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10118980
// Name: public: GASMouseCtorFunction::GASMouseCtorFunction(class GASStringContext __near *,class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMouseCtorFunction::GASMouseCtorFunction(
        GHashLH<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>,2,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *this,
        HWND__ *psc,
        int psc_4)
{
  void *v4; // ecx
  GASValue *v5; // eax
  const struct GASFunctionRefBase *v6; // eax
  tagMSG v7; // [esp-8h] [ebp-30h] BYREF
  struct GASObjectInterface *v8; // [esp+14h] [ebp-14h]
  int v9; // [esp+1Ch] [ebp-Ch] BYREF
  int v10; // [esp+20h] [ebp-8h]
  char v11; // [esp+24h] [ebp-4h]

  GASCFunctionObject::GASCFunctionObject(
    (GASCFunctionObject *)this,
    func: (_REASON_CONTEXT *)psc,
    a3: (void (__cdecl *)(const struct GASFnCall *))GASMouseCtorFunction::GlobalCtor);
  *((_DWORD *)this + 14) = &GFxASMouseListener::`vftable';
  this->Hash.pTable = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)&GASMouseCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASMouseCtorFunction::`vftable'{for `GASObjectInterface'};
  *((_DWORD *)this + 14) = &GASMouseCtorFunction::`vftable';
  *((_DWORD *)this + 15) = 0;
  *((_BYTE *)this + 84) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  v7.message = (unsigned int)(this + 4);
  v7.hwnd = psc;
  *(_DWORD *)(psc_4 + 2512) = this + 14;
  GASAsBroadcaster::Initialize(pobj: v7, a2: v8);
  GASMouseCtorFunction::UpdateListenersArray(this: &this->Hash, psc, psc_4: nullptr);
  GASNameFunction::AddConstMembers(
    pobj: v4,
    psc: (int)(this + 4),
    psca: (CTSQueue<CFunctor *,0,1>::Node_t *)psc,
    a4: (struct GASObject **)&GASMouseCtorFunction::StaticFunctionTable,
    a5: 7);
  v5 = GASValue::GASValue(
         this: (GASValue *)&v7.pt,
         func: (int)psc,
         a3: (void (__cdecl *)(const struct GASFnCall *))GASMouseCtorFunction::SetCursorType);
  v6 = (const struct GASFunctionRefBase *)GASValue::ToFunction(a1: (int)v5, a2: (int)psc, a3: (int)&v9, a4: 0);
  GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)(this + 19), orig: v6);
  if ( (v11 & 2) == 0 && v9 != 0 )
    GRefCountBaseGC<323>::Release(a1: v9, a2: 0);
  v9 = 0;
  if ( (v11 & 1) == 0 && v10 != 0 )
    GRefCountBaseGC<323>::Release(a1: v10, a2: 0);
  v10 = 0;
  GASValue::~GASValue(this: (GASValue *)&v7.pt, a2: 0);
  *((_DWORD *)this + 18) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10118AF0
// Name: private: static int GASMouseCtorFunction::PushListenersParams(class GASEnvironment __near *,unsigned int,enum GASBuiltinType,class GASValue const __near &,class GASString const __near *,unsigned int,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASMouseCtorFunction::PushListenersParams(
        void *penv,
        int a2,
        unsigned int mouseIndex,
        int a4,
        tagWNDCLASSW *eventMethod,
        _RESOURCEMANAGER_COMPLETION_INFORMATION *ptargetName,
        unsigned int button,
        int delta,
        bool dblClick)
{
  int v9; // esi
  char v11; // al
  int result; // eax
  bool v13; // zf
  _BYTE *v14; // esi
  struct GFxMovieRoot *MovieRoot; // eax
  int v16; // eax
  double v17; // st7
  unsigned int v18; // eax
  int v19; // eax
  double v20; // st7
  double v21; // st7
  unsigned int v22; // eax
  int v23; // eax
  double v24; // st7
  int v25; // esi
  int v26; // esi
  _DWORD *IoCompletionPortHandle; // eax
  _BYTE *v28; // esi
  int v29; // esi
  int v30; // esi
  _BYTE *v31; // esi
  int v32; // [esp+14h] [ebp-18h] BYREF
  double v33; // [esp+18h] [ebp-14h]
  float v34; // [esp+20h] [ebp-Ch]
  float v35; // [esp+24h] [ebp-8h]
  int nArgs; // [esp+28h] [ebp-4h]
  bool noExtraParams; // [esp+37h] [ebp+Bh]

  v9 = a4;
  v11 = *(_BYTE *)(*(_DWORD *)(a2 + 120) + 684);
  noExtraParams = v11 != 1;
  if ( v11 != 1 || button == 0 || a4 != 103 && a4 != 104 )
    goto LABEL_22;
  GASValue::ToFunction(a1: (int)eventMethod, a2, a3: (int)&v32, a4: a2);
  if ( v32 != 0 )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v32 + 64))(a1: v32) <= 0 )
    {
      if ( button > 1 )
      {
        if ( (BYTE4(v33) & 2) == 0 && v32 != 0 )
          GRefCountBaseGC<323>::Release(a1: v32, a2);
        goto LABEL_11;
      }
      noExtraParams = true;
    }
    if ( (BYTE4(v33) & 2) == 0 && v32 != 0 )
      GRefCountBaseGC<323>::Release(a1: v32, a2);
    v32 = 0;
    if ( (BYTE4(v33) & 1) == 0 && LODWORD(v33) != 0 )
      GRefCountBaseGC<323>::Release(a1: SLODWORD(v33), a2);
LABEL_22:
    v13 = *(_BYTE *)(*(_DWORD *)(a2 + 120) + 684) == 1;
    nArgs = 0;
    if ( v13 && !noExtraParams )
    {
      if ( a4 == 103 && dblClick )
      {
        *(_DWORD *)(a2 + 8) += 16;
        if ( *(_DWORD *)(a2 + 8) >= *(_DWORD *)(a2 + 16) )
          GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(a2 + 8));
        v14 = *(_BYTE **)(a2 + 8);
        if ( v14 != nullptr )
        {
          *v14 = 2;
          v14[4] = dblClick;
        }
        nArgs = 1;
      }
      MovieRoot = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)a2);
      if ( mouseIndex < 4 )
        v16 = (int)MovieRoot + 36 * mouseIndex + 2356;
      else
        v16 = 0;
      v34 = *(float *)(v16 + 20);
      v35 = *(float *)(v16 + 24);
      v17 = floor(X: v35 + 0.5);
      *(_DWORD *)(a2 + 8) += 16;
      v18 = *(_DWORD *)(a2 + 8);
      v33 = v17 / 20.0;
      if ( v18 >= *(_DWORD *)(a2 + 16) )
        GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(a2 + 8));
      v19 = *(_DWORD *)(a2 + 8);
      if ( v19 != 0 )
      {
        v20 = v33;
        *(_BYTE *)v19 = 3;
        *(double *)(v19 + 4) = v20;
      }
      v21 = floor(X: v34 + 0.5);
      *(_DWORD *)(a2 + 8) += 16;
      v22 = *(_DWORD *)(a2 + 8);
      v33 = v21 / 20.0;
      if ( v22 >= *(_DWORD *)(a2 + 16) )
        GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(a2 + 8));
      v23 = *(_DWORD *)(a2 + 8);
      if ( v23 != 0 )
      {
        v24 = v33;
        *(_BYTE *)v23 = 3;
        *(double *)(v23 + 4) = v24;
      }
      *(_DWORD *)(a2 + 8) += 16;
      if ( *(_DWORD *)(a2 + 8) >= *(_DWORD *)(a2 + 16) )
        GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(a2 + 8));
      v25 = *(_DWORD *)(a2 + 8);
      if ( v25 != 0 )
      {
        *(_BYTE *)v25 = 4;
        *(_DWORD *)(v25 + 4) = mouseIndex;
      }
      nArgs += 3;
      v9 = a4;
    }
    if ( v9 != 105 )
    {
      if ( ptargetName != nullptr && (v9 == 106 || !noExtraParams) )
      {
        *(_DWORD *)(a2 + 8) += 16;
        if ( *(_DWORD *)(a2 + 8) >= *(_DWORD *)(a2 + 16) )
          GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(a2 + 8));
        v26 = *(_DWORD *)(a2 + 8);
        if ( v26 != 0 )
        {
          *(_BYTE *)v26 = 5;
          IoCompletionPortHandle = ptargetName->IoCompletionPortHandle;
          *(_DWORD *)(v26 + 4) = ptargetName->IoCompletionPortHandle;
          ++IoCompletionPortHandle[2];
        }
      }
      else
      {
        if ( nArgs <= 0 )
          goto LABEL_61;
        *(_DWORD *)(a2 + 8) += 16;
        if ( *(_DWORD *)(a2 + 8) >= *(_DWORD *)(a2 + 16) )
          GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(a2 + 8));
        v28 = *(_BYTE **)(a2 + 8);
        if ( v28 != nullptr )
          *v28 = 1;
      }
      v9 = a4;
      ++nArgs;
    }
LABEL_61:
    if ( v9 >= 103 )
    {
      if ( v9 <= 104 )
      {
        if ( button != 0 && !noExtraParams )
        {
          *(_DWORD *)(a2 + 8) += 16;
          v33 = (double)button;
          if ( *(_DWORD *)(a2 + 8) >= *(_DWORD *)(a2 + 16) )
            GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(a2 + 8));
          v30 = *(_DWORD *)(a2 + 8);
          if ( v30 != 0 )
          {
            result = ++nArgs;
            *(double *)(v30 + 4) = v33;
            *(_BYTE *)v30 = 3;
            return result;
          }
          goto LABEL_79;
        }
        if ( nArgs > 0 )
        {
          *(_DWORD *)(a2 + 8) += 16;
          if ( *(_DWORD *)(a2 + 8) >= *(_DWORD *)(a2 + 16) )
            GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(a2 + 8));
          v31 = *(_BYTE **)(a2 + 8);
          if ( v31 != nullptr )
            *v31 = 1;
LABEL_79:
          ++nArgs;
        }
      }
      else if ( v9 == 106 )
      {
        *(_DWORD *)(a2 + 8) += 16;
        if ( *(_DWORD *)(a2 + 8) >= *(_DWORD *)(a2 + 16) )
          GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(a2 + 8));
        v29 = *(_DWORD *)(a2 + 8);
        if ( v29 != 0 )
        {
          ++nArgs;
          *(_DWORD *)(v29 + 4) = delta;
          result = nArgs;
          *(_BYTE *)v29 = 4;
          return result;
        }
        goto LABEL_79;
      }
    }
    return nArgs;
  }
LABEL_11:
  v32 = 0;
  if ( (BYTE4(v33) & 1) == 0 && LODWORD(v33) != 0 )
    GRefCountBaseGC<323>::Release(a1: SLODWORD(v33), a2);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10118E20
// Name: public: virtual bool GASMouseCtorFunction::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMouseCtorFunction::SetMember(
        CTSQueue<CFunctor *,0,1> *this,
        GASEnvironment *a2,
        _IMAGE_SYMBOL_EX *a3,
        CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **a4,
        const struct GASPropFlags *a5)
{
  int v5; // eax
  GASEnvironment *v6; // ebx
  const struct GASFunctionRefBase *v8; // eax
  char v9; // al
  char v10; // bl
  struct GFxMovieRoot *MovieRoot; // eax
  int v12; // [esp+Ch] [ebp-Ch] BYREF
  int v13; // [esp+10h] [ebp-8h]
  char v14; // [esp+14h] [ebp-4h]

  v5 = *((_DWORD *)a2 + 30);
  v6 = a2 + 30;
  if ( a3->N.Name.Short == *(_DWORD *)(v5 + 552) )
  {
    if ( *(_BYTE *)(v5 + 684) == 1 )
    {
      v8 = (const struct GASFunctionRefBase *)GASValue::ToFunction(a1: (int)a4, (int)a2, a3: (int)&v12, a4: (int)a2);
      GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)((char *)this + 60), orig: v8);
      if ( (v14 & 2) == 0 && v12 != 0 )
        GRefCountBaseGC<323>::Release(a1: v12, (int)a2);
      v12 = 0;
      if ( (v14 & 1) == 0 && v13 != 0 )
        GRefCountBaseGC<323>::Release(a1: v13, (int)a2);
      GASMouseCtorFunction::HasOverloadedCursorTypeFunction(
        this: (GHashLH<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>,2,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)this
      - 4,
        (int)a2,
        psc: (int)v6);
      v10 = v9;
      MovieRoot = GASEnvironment::GetMovieRoot(this: a2);
      if ( v10 != 0 )
        *((_DWORD *)MovieRoot + 2333) |= 0x1000u;
      else
        *((_DWORD *)MovieRoot + 2333) &= ~0x1000u;
    }
    goto LABEL_11;
  }
  if ( a3->N.Name.Short != *(_DWORD *)(v5 + 332) )
  {
LABEL_11:
    GASObject::SetMember(this, a2, name: a3, pval: a4, pmember: (char *)a5);
    return;
  }
  GASObject::SetMember(this, a2, name: a3, pval: a4, pmember: (char *)a5);
  GASMouseCtorFunction::UpdateListenersArray(
    this: (GHashSet<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)this
  - 4,
    psc: v6,
    psc_4: (const struct GASEnvironment *)a2);
}

//------------------------------------------------------------------------------
// Address: 0x10118F10
// Name: public: virtual void GASMouseCtorFunction::LocalInvokeCallback::Invoke(class GASEnvironment __near *,class GASObjectInterface __near *,class GASFunctionRef const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMouseCtorFunction::LocalInvokeCallback::Invoke(
        GASMouseCtorFunction::LocalInvokeCallback *this,
        struct GASEnvironment *a2,
        struct GASObjectInterface *nArgs,
        const struct GASFunctionRef *a4)
{
  GASValue **v6; // esi
  int v7; // eax
  int v8; // edx
  int v9; // ecx
  int i; // edi
  _DWORD v11[3]; // [esp+Ch] [ebp-34h] BYREF
  int v12; // [esp+18h] [ebp-28h]
  int v13; // [esp+1Ch] [ebp-24h]
  char v14; // [esp+20h] [ebp-20h]
  struct GASEnvironment *v15; // [esp+24h] [ebp-1Ch]
  struct GASFunctionRef *v16; // [esp+28h] [ebp-18h]
  int v17; // [esp+2Ch] [ebp-14h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *result; // [esp+30h] [ebp-10h] BYREF
  struct GASFunctionRef *v19; // [esp+50h] [ebp+10h]

  GASValue::GASValue(this: &result, a2: (int)a4, a3: a4);
  v19 = (struct GASFunctionRef *)GASMouseCtorFunction::PushListenersParams(
                                   penv: &result,
                                   (int)a2,
                                   mouseIndex: *((_DWORD *)this + 1),
                                   a4: *((_DWORD *)this + 2),
                                   eventMethod: (tagWNDCLASSW *)&result,
                                   ptargetName: *((_RESOURCEMANAGER_COMPLETION_INFORMATION **)this + 3),
                                   button: *((_DWORD *)this + 4),
                                   delta: *((_DWORD *)this + 5),
                                   dblClick: *((_BYTE *)this + 24));
  GASValue::~GASValue(this: &result, a2: (int)a4);
  if ( (int)v19 >= 0 )
  {
    v6 = (GASValue **)((char *)a2 + 8);
    v7 = ((*((_DWORD *)a2 + 2) - *((_DWORD *)a2 + 3)) >> 4) + 32 * *((_DWORD *)a2 + 7) - 32;
    v11[1] = &result;
    LOBYTE(result) = 0;
    v14 = 0;
    v12 = 0;
    v13 = 0;
    v8 = *((_DWORD *)a4 + 1);
    v15 = a2;
    v11[2] = nArgs;
    v9 = *(_DWORD *)a4;
    v17 = v7;
    v11[0] = &GASFnCall::`vftable';
    v16 = v19;
    (*(void (__thiscall **)(int, _DWORD *, int, _DWORD))(*(_DWORD *)v9 + 40))(a1: v9, a2: v11, a3: v8, a4: 0);
    v11[0] = &GASFnCall::`vftable';
    if ( (v14 & 2) == 0 && v12 != 0 )
      GRefCountBaseGC<323>::Release(a1: v12, a2: (int)a4);
    v12 = 0;
    if ( (v14 & 1) == 0 && v13 != 0 )
      GRefCountBaseGC<323>::Release(a1: v13, a2: (int)a4);
    for ( i = (int)v19; i != 0; --i )
    {
      GASValue::~GASValue(this: *v6, a2: i);
      *v6 -= 4;
      if ( *((_DWORD *)a2 + 2) < *((_DWORD *)a2 + 3) )
        GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)v6);
    }
    GASValue::~GASValue(this: &result, a2: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10119020
// Name: public: static class GASFunctionRef GASMouseCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMouseCtorFunction::Register(
        const GHashLH<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>,2,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *pgc,
        int constructor,
        _KCRM_MARSHAL_HEADER *pgca)
{
  _KCRM_MARSHAL_HEADER *v3; // edi
  unsigned int VersionMajor; // ecx
  int (__thiscall *v5)(unsigned int, int, _KCRM_MARSHAL_HEADER **); // eax
  GHashLH<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>,2,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *v6; // eax
  int v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // ecx
  int (__thiscall *v10)(unsigned int, int, int *); // edx
  int v11; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GASValue *v13; // eax
  int p_VersionMinor; // edi
  float v15; // [esp+0h] [ebp-2Ch]
  GASValue v16[4]; // [esp+Ch] [ebp-20h] BYREF
  GHashLH<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>,2,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > psc; // [esp+1Ch] [ebp-10h] BYREF
  char v18; // [esp+20h] [ebp-Ch]
  void (__thiscall **v19)(_DWORD *, GHashLH<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>,2,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *, int, GASValue *, char *); // [esp+24h] [ebp-8h]
  _DWORD *v20; // [esp+28h] [ebp-4h]

  v3 = pgca;
  VersionMajor = pgca[41].VersionMajor;
  psc.Hash.pTable = (struct GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> >::TableType *)pgca;
  v18 = 8;
  v5 = *(int (__thiscall **)(unsigned int, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)VersionMajor + 40);
  pgca = (_KCRM_MARSHAL_HEADER *)323;
  v6 = (GHashLH<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>,2,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *)v5(a1: VersionMajor, a2: 92, a3: &pgca);
  if ( v6 != nullptr )
    GASMouseCtorFunction::GASMouseCtorFunction(this: v6, (HWND__ *)&psc, psc_4: v3[40].Unused);
  else
    v7 = 0;
  v8 = constructor;
  *(_DWORD *)constructor = v7;
  *(_BYTE *)(v8 + 8) = 0;
  *(_DWORD *)(v8 + 4) = 0;
  v9 = v3[41].VersionMajor;
  v10 = *(int (__thiscall **)(unsigned int, int, int *))(*(_DWORD *)v9 + 40);
  constructor = 323;
  v11 = v10(a1: v9, a2: 84, a3: &constructor);
  if ( v11 != 0 )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: (vc_attributes::PreRangeAttribute *)v3,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASIme,GASEnvironment>::GASPrototype<GASIme,GASEnvironment>(
      this: (D3DXCOLOR *)v11,
      (struct GASStringContext *)&psc,
      pprototype: Prototype,
      constructor: v8,
      psc_12: v15);
    *(_DWORD *)v11 = &GASObjectProto::`vftable'{for `GASRefCountBase<GASObject>'};
    *(_DWORD *)(v11 + 16) = &GASPrototype<GASMouse,GASEnvironment>::`vftable'{for `GASObjectInterface'};
    *(_DWORD *)(v11 + 52) = &GASMouseProto::`vftable';
    HIBYTE(pgca) = 1;
    GASPrototypeBase::InitFunctionMembers(
      this: (GASPrototypeBase *)(v11 + 52),
      a2: v11,
      flags: (vc_attributes::PreRangeAttribute **)&psc,
      flags_4: (const struct GASNameFunction *)&GAS_MouseFunctionTable,
      flags_8: (const struct GASPropFlags *)((char *)&pgca + 3));
  }
  else
  {
    v11 = 0;
  }
  if ( v11 != 0 )
    *(_DWORD *)(v11 + 8) = (*(_DWORD *)(v11 + 8) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v3, a2: (int)v3, a3: 27, a4: v11);
  v20 = (_DWORD *)(v3[42].NumProtocols + 16);
  HIBYTE(pgca) = 0;
  v19 = (void (__thiscall **)(_DWORD *, GHashLH<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>,2,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long> >::NodeHashF> > *, int, GASValue *, char *))(*v20 + 40);
  v13 = GASValue::GASValue(this: v16, a2: (int)v3, a3: (const struct GASFunctionRef *)v8);
  p_VersionMinor = (int)&v3[7].VersionMinor;
  (*v19)(a1: v20, a2: &psc, a3: p_VersionMinor, a4: v13, a5: (char *)&pgca + 3);
  GASValue::~GASValue(this: v16, a2: p_VersionMinor);
  if ( v11 != 0 )
    GRefCountBaseGC<323>::Release(a1: v11, a2: p_VersionMinor);
}
