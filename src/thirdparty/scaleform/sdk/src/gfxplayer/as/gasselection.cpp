// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasselection.cpp
// Functions: 22
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasselection.h"

//------------------------------------------------------------------------------
// Address: 0x10114E30
// Name: protected: static void GASSelection::DoTransferFocus(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASSelection::DoTransferFocus(long double a1@<st0>, GASFnCall *result)
{
  ISteamRemoteStorage *MovieRoot; // edi
  GASValue *v3; // eax
  double v4; // st7
  int v5; // ebx
  GASValue *v6; // eax
  GASValue *v7; // eax
  GRefCountWeakSupportImpl *v8; // eax
  GPtr<GFxAmpMemItem> *v9; // [esp-Ch] [ebp-18h]
  unsigned int v10; // [esp-8h] [ebp-14h]
  _SERVICE_STATUS *v11; // [esp-4h] [ebp-10h]
  _SERVICE_STATUS *v12; // [esp-4h] [ebp-10h]

  MovieRoot = (ISteamRemoteStorage *)GASEnvironment::GetMovieRoot(this: (GASEnvironment *)result[6]);
  v11 = (_SERVICE_STATUS *)result[6];
  v3 = (GASValue *)GASFnCall::Arg(this: result, a2: 1);
  v4 = GASValue::ToNumber(this: v3, a2: (int)MovieRoot, a3: a1, result: v11);
  v12 = (_SERVICE_STATUS *)result[6];
  v5 = (int)v4;
  v6 = (GASValue *)GASFnCall::Arg(this: result, a2: 2);
  v10 = GASValue::ToUInt32(this: v6, a2: (int)MovieRoot, a3: v4, a4: v12);
  v9 = (GPtr<GFxAmpMemItem> *)result[6];
  v7 = (GASValue *)GASFnCall::Arg(this: result, a2: 0);
  GASValue::ToASCharacter(this: v7, penv: (const struct GASEnvironment *)v9);
  GFxMovieRoot::TransferFocus(this: MovieRoot, a2: v8, controllerIdx: v10, a4: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10114EA0
// Name: private: static void GASSelectionCtorFunction::SetModalClip(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASSelectionCtorFunction::SetModalClip(long double a1@<st0>, int fna)
{
  GASValue *v3; // edi
  ISteamRemoteStorage *MovieRoot; // ebx
  GASValue *v5; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v6; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v7; // edi
  GASValue *v8; // eax
  unsigned int v9; // esi
  const struct GASEnvironment *v10; // [esp-8h] [ebp-10h]
  _SERVICE_STATUS *v11; // [esp-8h] [ebp-10h]

  v3 = *(GASValue **)(fna + 4);
  GASValue::DropRefs(this: v3, a2: (int)v3);
  *(_BYTE *)v3 = 0;
  if ( *(int *)(fna + 28) >= 1 )
  {
    MovieRoot = (ISteamRemoteStorage *)GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fna + 24));
    v10 = *(const struct GASEnvironment **)(fna + 24);
    v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
    GASValue::ToASCharacter(this: v5, penv: v10);
    v7 = v6;
    if ( *(int *)(fna + 28) < 2 )
    {
      v9 = 0;
    }
    else
    {
      v11 = *(_SERVICE_STATUS **)(fna + 24);
      v8 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 1);
      v9 = GASValue::ToUInt32(this: v8, a2: (int)v7, a3: a1, a4: v11);
    }
    if ( v7 != nullptr
      && (*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(v7->m_pfnProxied) + 176))(a1: v7) == 2 )
    {
      GFxMovieRoot::SetModalClip(this: MovieRoot, pmovie: v7, controllerIdx: v9);
    }
    else
    {
      GFxMovieRoot::SetModalClip(this: MovieRoot, pmovie: nullptr, controllerIdx: v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10114F30
// Name: private: static void GASSelectionCtorFunction::GetModalClip(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASSelectionCtorFunction::GetModalClip(long double a1@<st0>, int fna)
{
  GASValue *v3; // edi
  GFxMovieRoot *MovieRoot; // edi
  GASValue *v5; // eax
  unsigned int v6; // eax
  tagBITMAPCOREHEADER *ModalClip; // eax
  _SERVICE_STATUS *v8; // [esp-4h] [ebp-Ch]

  v3 = *(GASValue **)(fna + 4);
  GASValue::DropRefs(this: v3, a2: (int)v3);
  *(_BYTE *)v3 = 0;
  MovieRoot = (GFxMovieRoot *)GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fna + 24));
  if ( *(int *)(fna + 28) < 1 )
  {
    v6 = 0;
  }
  else
  {
    v8 = *(_SERVICE_STATUS **)(fna + 24);
    v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
    v6 = GASValue::ToUInt32(this: v5, a2: (int)MovieRoot, a3: a1, a4: v8);
  }
  ModalClip = (tagBITMAPCOREHEADER *)GFxMovieRoot::GetModalClip(this: MovieRoot, a2: v6);
  GASValue::SetAsCharacter(this: *(_DWORD *)(fna + 4), result: ModalClip);
}

//------------------------------------------------------------------------------
// Address: 0x10114F90
// Name: private: static void GASSelectionCtorFunction::GetControllerMaskByFocusGroup(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASSelectionCtorFunction::GetControllerMaskByFocusGroup(long double a1@<st0>, int fna)
{
  GASValue *v3; // edi
  ISteamRemoteStorage *MovieRoot; // edi
  GASValue *v5; // eax
  int v6; // eax
  int ControllerMaskByFocusGroup; // eax
  int v8; // esi
  unsigned __int64 v9; // [esp-4h] [ebp-14h]
  _SERVICE_STATUS *v10; // [esp-4h] [ebp-14h]
  double v11; // [esp+8h] [ebp-8h]

  v3 = *(GASValue **)(fna + 4);
  GASValue::DropRefs(this: v3, a2: (int)v3);
  *(_BYTE *)v3 = 0;
  MovieRoot = (ISteamRemoteStorage *)GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fna + 24));
  if ( *(int *)(fna + 28) < 1 )
  {
    v6 = 0;
  }
  else
  {
    v10 = *(_SERVICE_STATUS **)(fna + 24);
    v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
    v6 = GASValue::ToUInt32(this: v5, a2: (int)MovieRoot, a3: a1, a4: v10);
  }
  LODWORD(v9) = v6;
  ControllerMaskByFocusGroup = GFxMovieRoot::GetControllerMaskByFocusGroup(this: MovieRoot, focusGroupIndex: v9);
  v8 = *(_DWORD *)(fna + 4);
  v11 = (double)ControllerMaskByFocusGroup;
  if ( *(_BYTE *)v8 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v8, a2: (int)MovieRoot);
  *(double *)(v8 + 4) = v11;
  *(_BYTE *)v8 = 3;
}

//------------------------------------------------------------------------------
// Address: 0x10115000
// Name: private: static void GASSelectionCtorFunction::SetControllerFocusGroup(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASSelectionCtorFunction::SetControllerFocusGroup(long double a1@<st0>, int fna)
{
  GASValue *v3; // edi
  struct GFxMovieRoot *MovieRoot; // edi
  GASValue *v5; // eax
  int v6; // eax
  int v7; // ebx
  GASValue *v8; // eax
  long double v9; // st7
  int v10; // eax
  char v11; // al
  int v12; // esi
  _SERVICE_STATUS *v13; // [esp-8h] [ebp-10h]
  _SERVICE_STATUS *v14; // [esp-8h] [ebp-10h]

  v3 = *(GASValue **)(fna + 4);
  GASValue::DropRefs(this: v3, a2: (int)v3);
  *(_BYTE *)v3 = 0;
  if ( *(int *)(fna + 28) >= 2 )
  {
    MovieRoot = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fna + 24));
    v13 = *(_SERVICE_STATUS **)(fna + 24);
    v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
    v6 = GASValue::ToUInt32(this: v5, a2: (int)MovieRoot, a3: a1, a4: v13);
    v14 = *(_SERVICE_STATUS **)(fna + 24);
    v7 = v6;
    v8 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 1);
    v10 = GASValue::ToUInt32(this: v8, a2: (int)MovieRoot, a3: v9, a4: v14);
    v11 = (*(int (__thiscall **)(struct GFxMovieRoot *, int, int))(*(_DWORD *)MovieRoot + 264))(
            a1: MovieRoot,
            a2: v7,
            a3: v10);
    v12 = *(_DWORD *)(fna + 4);
    LOBYTE(v7) = v11;
    GASValue::DropRefs(this: (GASValue *)v12, a2: (int)MovieRoot);
    *(_BYTE *)(v12 + 4) = v7;
    *(_BYTE *)v12 = 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115080
// Name: private: static void GASSelectionCtorFunction::GetControllerFocusGroup(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASSelectionCtorFunction::GetControllerFocusGroup(long double a1@<st0>, int fna)
{
  GASValue *v3; // edi
  struct GFxMovieRoot *MovieRoot; // edi
  GASValue *v5; // eax
  int v6; // eax
  double v7; // st7
  int v8; // esi
  _SERVICE_STATUS *v9; // [esp-4h] [ebp-14h]

  v3 = *(GASValue **)(fna + 4);
  GASValue::DropRefs(this: v3, a2: (int)v3);
  *(_BYTE *)v3 = 0;
  MovieRoot = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fna + 24));
  if ( *(int *)(fna + 28) < 1 )
  {
    v6 = 0;
  }
  else
  {
    v9 = *(_SERVICE_STATUS **)(fna + 24);
    v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
    v6 = GASValue::ToUInt32(this: v5, a2: (int)MovieRoot, a3: a1, a4: v9);
  }
  v7 = (double)(unsigned int)(*(int (__thiscall **)(struct GFxMovieRoot *, int))(*(_DWORD *)MovieRoot + 268))(
                               a1: MovieRoot,
                               a2: v6);
  v8 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v8 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v8, a2: (int)MovieRoot);
  *(double *)(v8 + 4) = v7;
  *(_BYTE *)v8 = 3;
}

//------------------------------------------------------------------------------
// Address: 0x10115100
// Name: private: static void GASSelectionCtorFunction::SetFocus(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASSelectionCtorFunction::SetFocus(long double a1@<st0>, int retVal)
{
  int v4; // edi
  tagRID_DEVICE_INFO_KEYBOARD *v5; // edi
  unsigned __int8 *v6; // eax
  tagBITMAPCOREHEADER **v7; // ecx
  int v8; // eax
  GStat::StatValue *v10; // eax
  GASValue *v11; // eax
  GStat::StatValue *v12; // eax
  int v13; // edi
  GASValue *v14; // eax
  CImagePacker *MovieRoot; // eax
  int v16; // esi
  CImagePacker *v17; // eax
  int v18; // esi
  GStat::StatValue *v19; // [esp-8h] [ebp-44h]
  const struct GASEnvironment *v20; // [esp-4h] [ebp-40h]
  _SERVICE_STATUS *v21; // [esp-4h] [ebp-40h]
  struct GASEnvironment::GetVarParams v22[4]; // [esp+Ch] [ebp-30h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **p_val; // [esp+10h] [ebp-2Ch]
  int v24; // [esp+14h] [ebp-28h]
  int v25; // [esp+18h] [ebp-24h]
  int v26; // [esp+1Ch] [ebp-20h]
  int v27; // [esp+20h] [ebp-1Ch]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *val; // [esp+24h] [ebp-18h] BYREF
  int v29; // [esp+34h] [ebp-8h] BYREF
  GStat::StatValue *newFocus; // [esp+38h] [ebp-4h]
  char retVal_3; // [esp+47h] [ebp+Bh]

  v4 = *(_DWORD *)(retVal + 4);
  GASValue::DropRefs(this: (GASValue *)v4, a2: v4);
  *(_BYTE *)v4 = 2;
  *(_BYTE *)(v4 + 4) = 0;
  if ( *(int *)(retVal + 28) >= 1 && *(_DWORD *)(retVal + 24) != 0 )
  {
    newFocus = nullptr;
    if ( *(_BYTE *)GASFnCall::Arg(this: (GASFnCall *)retVal, a2: 0) == 5 )
    {
      v5 = *(tagRID_DEVICE_INFO_KEYBOARD **)(retVal + 24);
      LOBYTE(val) = 0;
      v6 = (unsigned __int8 *)GASFnCall::Arg(this: (GASFnCall *)retVal, a2: 0);
      GASValue::ToStringImpl(this: v6, a2: &v29, a3: v5, precision: -1, debug: false);
      v7 = *(tagBITMAPCOREHEADER ***)(retVal + 24);
      *(_DWORD *)v22 = &v29;
      p_val = &val;
      v24 = 0;
      v25 = 0;
      v26 = 0;
      v27 = 0;
      retVal_3 = GASEnvironment::FindVariable(this: v7, a2: v22, onlyTargets: false, varName: nullptr);
      v8 = v29;
      if ( (*(_DWORD *)(v29 + 8))-- == 1 )
        GASStringNode::ReleaseNode(a1: v8);
      if ( retVal_3 != 0 && (_BYTE)val == 7 )
      {
        GASValue::ToASCharacter(this: &val, penv: *(const struct GASEnvironment **)(retVal + 24));
        if ( v10 != nullptr )
          ++v10->pName;
        newFocus = v10;
      }
      GASValue::~GASValue(this: &val, a2: (int)v5);
    }
    else
    {
      v20 = *(const struct GASEnvironment **)(retVal + 24);
      v11 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)retVal, a2: 0);
      GASValue::ToASCharacter(this: v11, penv: v20);
      if ( v12 != nullptr )
        ++v12->pName;
      newFocus = v12;
    }
    v13 = 0;
    if ( *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(retVal + 24) + 120) + 684) == 1 && *(int *)(retVal + 28) >= 2 )
    {
      v21 = *(_SERVICE_STATUS **)(retVal + 24);
      v14 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)retVal, a2: 1);
      v13 = GASValue::ToUInt32(this: v14, a2: 0, a3: a1, a4: v21);
    }
    if ( newFocus != nullptr )
    {
      if ( (*(unsigned __int8 (__thiscall **)(GStat::StatValue *))(newFocus->Type + 220))(a1: newFocus) != 0 )
      {
        v19 = newFocus;
        MovieRoot = (CImagePacker *)GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(retVal + 24));
        GFxMovieRoot::SetKeyboardFocusTo(this: MovieRoot, result: (GRefCountWeakSupportImpl *)v19, controllerIdx: v13);
        v16 = *(_DWORD *)(retVal + 4);
        GASValue::DropRefs(this: (GASValue *)v16, a2: v13);
        *(_BYTE *)v16 = 2;
        *(_BYTE *)(v16 + 4) = 1;
      }
      GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)newFocus);
    }
    else
    {
      v17 = (CImagePacker *)GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(retVal + 24));
      GFxMovieRoot::SetKeyboardFocusTo(this: v17, result: nullptr, controllerIdx: v13);
      v18 = *(_DWORD *)(retVal + 4);
      GASValue::DropRefs(this: (GASValue *)v18, a2: v13);
      *(_BYTE *)v18 = 2;
      *(_BYTE *)(v18 + 4) = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115280
// Name: public: virtual bool GASSelectionCtorFunction::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASSelectionCtorFunction::SetMember(
        CTSQueue<CFunctor *,0,1> *this@<ecx>,
        long double a2@<st0>,
        tagPOLYTEXTW *result,
        const char ***a4,
        GASValue *a5,
        const struct GASPropFlags *a6)
{
  ISteamRemoteStorage *MovieRoot; // esi
  _IMAGE_SYMBOL_EX *v7; // ebx
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v8; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v9; // edi

  if ( *(_BYTE *)(result[3].x + 684) != 1 )
  {
    v7 = (_IMAGE_SYMBOL_EX *)a4;
LABEL_18:
    GASObject::SetMember(
      this,
      a2: (GASEnvironment *)result,
      name: v7,
      pval: (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)a5,
      pmember: (char *)a6);
    return;
  }
  MovieRoot = (ISteamRemoteStorage *)GASEnvironment::GetMovieRoot(this: (GASEnvironment *)result);
  if ( strcmp(**a4, "disableFocusAutoRelease") == 0 )
  {
    MovieRoot[2333].__vftable = (ISteamRemoteStorage_vtbl *)((int)MovieRoot[2333].__vftable
                                                           ^ ((int)MovieRoot[2333].__vftable
                                                            ^ ((unsigned __int8)GASValue::ToBool(
                                                                                  a1: (char *)a5,
                                                                                  a2,
                                                                                  result) << 22))
                                                           & 0xC00000);
    return;
  }
  if ( strcmp(**a4, "alwaysEnableArrowKeys") == 0 )
  {
    MovieRoot[2333].__vftable = (ISteamRemoteStorage_vtbl *)((int)MovieRoot[2333].__vftable
                                                           ^ ((int)MovieRoot[2333].__vftable
                                                            ^ ((unsigned __int8)GASValue::ToBool(
                                                                                  a1: (char *)a5,
                                                                                  a2,
                                                                                  result) << 24))
                                                           & 0x3000000);
    return;
  }
  v7 = (_IMAGE_SYMBOL_EX *)a4;
  if ( GASString::operator==(this: a4, a2: "alwaysEnableKeyboardPress") )
  {
    MovieRoot[2333].__vftable = (ISteamRemoteStorage_vtbl *)((int)MovieRoot[2333].__vftable
                                                           ^ ((int)MovieRoot[2333].__vftable
                                                            ^ ((unsigned __int8)GASValue::ToBool(
                                                                                  a1: (char *)a5,
                                                                                  a2,
                                                                                  result) << 26))
                                                           & 0xC000000);
    return;
  }
  if ( GASString::operator==(this: a4, a2: "disableFocusRolloverEvent") )
  {
    MovieRoot[2333].__vftable = (ISteamRemoteStorage_vtbl *)((int)MovieRoot[2333].__vftable
                                                           ^ ((int)MovieRoot[2333].__vftable
                                                            ^ ((unsigned __int8)GASValue::ToBool(
                                                                                  a1: (char *)a5,
                                                                                  a2,
                                                                                  result) << 28))
                                                           & 0x30000000);
    return;
  }
  if ( GASString::operator==(this: a4, a2: "disableFocusKeys") )
  {
    MovieRoot[2333].__vftable = (ISteamRemoteStorage_vtbl *)((int)MovieRoot[2333].__vftable & 0x3FFFFFFF
                                                           | ((unsigned __int8)GASValue::ToBool(
                                                                                 a1: (char *)a5,
                                                                                 a2,
                                                                                 result) << 30));
    return;
  }
  if ( !GASString::operator==(this: a4, a2: "modalClip") )
    goto LABEL_18;
  GASValue::ToASCharacter(this: a5, penv: (const struct GASEnvironment *)result);
  v9 = v8;
  if ( v8 != nullptr
    && (*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(v8->m_pfnProxied) + 176))(a1: v8) == 2 )
  {
    GFxMovieRoot::SetModalClip(this: MovieRoot, pmovie: v9, controllerIdx: 0);
  }
  else
  {
    GFxMovieRoot::SetModalClip(this: MovieRoot, pmovie: nullptr, controllerIdx: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101154A0
// Name: private: static void GASSelectionCtorFunction::GetFocus(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASSelectionCtorFunction::GetFocus(long double a1@<st0>, int fna)
{
  GASValue *v3; // esi
  int v4; // eax
  int v5; // esi
  GASValue *v6; // eax
  struct GFxMovieRoot *MovieRoot; // eax
  _DWORD **v8; // esi
  _DWORD *v9; // eax
  GRefCountNTSImpl *v10; // esi
  volatile int RefCount; // eax
  int v12; // edi
  volatile int v13; // ebx
  int v14; // eax
  _SERVICE_STATUS *v16; // [esp-8h] [ebp-10h]

  v3 = *(GASValue **)(fna + 4);
  GASValue::DropRefs(this: v3, a2: fna);
  *(_BYTE *)v3 = 1;
  v4 = *(_DWORD *)(fna + 24);
  if ( v4 != 0 )
  {
    v5 = 0;
    if ( *(_BYTE *)(*(_DWORD *)(v4 + 120) + 684) == 1 && *(int *)(fna + 28) >= 1 )
    {
      v16 = *(_SERVICE_STATUS **)(fna + 24);
      v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
      v5 = GASValue::ToUInt32(this: v6, a2: fna, a3: a1, a4: v16);
    }
    MovieRoot = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fna + 24));
    v8 = (_DWORD **)((char *)MovieRoot + 52 * *((unsigned __int8 *)MovieRoot + v5 + 10228) + 9412);
    v9 = *v8;
    if ( *v8 != nullptr )
    {
      if ( v9[1] != 0 )
      {
        v10 = (GRefCountNTSImpl *)v9[1];
        if ( v10 != nullptr )
        {
          ++v10->RefCount;
          ++v10->RefCount;
          GRefCountNTSImpl::Release(this: v10);
          RefCount = v10[18].RefCount;
          if ( RefCount == 0 )
            GFxASCharacter::CreateCharacterHandle(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v10);
          v12 = *(_DWORD *)(fna + 4);
          v13 = RefCount;
          if ( *(_BYTE *)v12 >= 5u )
            GASValue::DropRefs(this: (GASValue *)v12, a2: v12);
          *(_BYTE *)v12 = 5;
          v14 = *(_DWORD *)(v13 + 12);
          *(_DWORD *)(v12 + 4) = v14;
          ++*(_DWORD *)(v14 + 8);
          GRefCountNTSImpl::Release(this: v10);
        }
      }
      else
      {
        if ( (*v9)-- == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
        *v8 = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115580
// Name: private: static void GASSelectionCtorFunction::GetFocusBitmask(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSelectionCtorFunction::GetFocusBitmask(void *fn, int fna)
{
  int v2; // edi
  GASValue *v3; // esi
  int v4; // eax
  int v5; // ebx
  GASValue *v6; // eax
  GRefCountNTSImpl *v7; // eax
  struct GFxMovieRoot *MovieRoot; // eax
  _DWORD **v9; // esi
  _DWORD *v10; // eax
  GRefCountNTSImpl *v11; // edi
  int v12; // esi
  const struct GASEnvironment *v14; // [esp-4h] [ebp-1Ch]
  GRefCountNTSImpl *v15; // [esp+Ch] [ebp-Ch]
  unsigned __int16 bm; // [esp+10h] [ebp-8h]
  __int16 mask; // [esp+14h] [ebp-4h]

  v2 = fna;
  v3 = *(GASValue **)(fna + 4);
  GASValue::DropRefs(this: v3, a2: fna);
  *(_BYTE *)v3 = 1;
  v4 = *(_DWORD *)(fna + 24);
  v5 = 0;
  if ( v4 != 0 && *(_BYTE *)(*(_DWORD *)(v4 + 120) + 684) == 1 && *(int *)(fna + 28) >= 1 )
  {
    v14 = *(const struct GASEnvironment **)(fna + 24);
    v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
    GASValue::ToASCharacter(this: v6, penv: v14);
    v15 = v7;
    if ( v7 != nullptr )
      ++v7->RefCount;
    bm = 0;
    mask = 1;
    while ( 1 )
    {
      MovieRoot = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(v2 + 24));
      v9 = (_DWORD **)((char *)MovieRoot + 52 * *((unsigned __int8 *)MovieRoot + v5 + 10228) + 9412);
      v10 = *v9;
      v11 = nullptr;
      if ( *v9 != nullptr )
      {
        if ( v10[1] != 0 )
        {
          v11 = (GRefCountNTSImpl *)v10[1];
          if ( v11 != nullptr )
          {
            ++v11->RefCount;
            ++v11->RefCount;
            GRefCountNTSImpl::Release(this: v11);
          }
        }
        else
        {
          if ( (*v10)-- == 1 )
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v10);
          *v9 = nullptr;
        }
      }
      if ( v11 == v15 )
        bm |= mask;
      if ( v11 != nullptr )
        GRefCountNTSImpl::Release(this: v11);
      mask *= 2;
      if ( (unsigned int)++v5 >= 4 )
        break;
      v2 = fna;
    }
    v12 = *(_DWORD *)(fna + 4);
    if ( *(_BYTE *)v12 >= 5u )
      GASValue::DropRefs(this: *(GASValue **)(fna + 4), a2: (int)v11);
    *(_BYTE *)v12 = 3;
    *(double *)(v12 + 4) = (double)bm;
    if ( v15 != nullptr )
      GRefCountNTSImpl::Release(this: v15);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101156A0
// Name: private: static void GASSelectionCtorFunction::GetCaretIndex(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSelectionCtorFunction::GetCaretIndex(void *fn, int fna)
{
  int v2; // esi
  int v3; // eax
  int v4; // esi
  GASValue *v5; // eax
  struct GFxMovieRoot *MovieRoot; // eax
  _DWORD **v7; // esi
  _DWORD *v8; // eax
  GRefCountNTSImpl *v9; // esi
  int v10; // eax
  int v11; // edi
  _SERVICE_STATUS *v13; // [esp-8h] [ebp-18h]
  double v14; // [esp+8h] [ebp-8h]

  v2 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v2 >= 5u )
    GASValue::DropRefs(this: *(GASValue **)(fna + 4), a2: fna);
  *(_BYTE *)v2 = 3;
  *(double *)(v2 + 4) = -1.0;
  v3 = *(_DWORD *)(fna + 24);
  if ( v3 != 0 )
  {
    v4 = 0;
    if ( *(_BYTE *)(*(_DWORD *)(v3 + 120) + 684) == 1 && *(int *)(fna + 28) >= 1 )
    {
      v13 = *(_SERVICE_STATUS **)(fna + 24);
      v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
      v4 = GASValue::ToUInt32(this: v5, a2: fna, a3: -1.0, a4: v13);
    }
    MovieRoot = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fna + 24));
    v7 = (_DWORD **)((char *)MovieRoot + 52 * *((unsigned __int8 *)MovieRoot + v4 + 10228) + 9412);
    v8 = *v7;
    if ( *v7 != nullptr )
    {
      if ( v8[1] != 0 )
      {
        v9 = (GRefCountNTSImpl *)v8[1];
        if ( v9 != nullptr )
        {
          ++v9->RefCount;
          ++v9->RefCount;
          GRefCountNTSImpl::Release(this: v9);
          if ( ((int (__thiscall *)(GRefCountNTSImpl *))v9->__vftable[44].dtr_GRefCountImplCore)(a1: v9) == 4 )
          {
            v10 = ((int (__thiscall *)(GRefCountNTSImpl *))v9->__vftable[95].dtr_GRefCountImplCore)(a1: v9);
            v11 = *(_DWORD *)(fna + 4);
            v14 = (double)v10;
            if ( *(_BYTE *)v11 >= 5u )
              GASValue::DropRefs(this: (GASValue *)v11, a2: v11);
            *(_BYTE *)v11 = 3;
            *(double *)(v11 + 4) = v14;
          }
          GRefCountNTSImpl::Release(this: v9);
        }
      }
      else
      {
        if ( (*v8)-- == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
        *v7 = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101157B0
// Name: private: static void GASSelectionCtorFunction::SetSelection(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASSelectionCtorFunction::SetSelection(long double a1@<st0>, int fna)
{
  GASValue *v3; // esi
  int v4; // eax
  int v5; // esi
  GASValue *v6; // eax
  struct GFxMovieRoot *MovieRoot; // eax
  _DWORD **v8; // esi
  _DWORD *v9; // eax
  GRefCountNTSImpl *v10; // esi
  int v11; // ebx
  int v12; // eax
  GASValue *v13; // eax
  int v14; // eax
  GASValue *v15; // eax
  long double v16; // st7
  _SERVICE_STATUS *v18; // [esp-8h] [ebp-10h]
  _SERVICE_STATUS *v19; // [esp-8h] [ebp-10h]
  _SERVICE_STATUS *v20; // [esp-4h] [ebp-Ch]

  v3 = *(GASValue **)(fna + 4);
  GASValue::DropRefs(this: v3, a2: fna);
  *(_BYTE *)v3 = 0;
  v4 = *(_DWORD *)(fna + 24);
  if ( v4 != 0 )
  {
    v5 = 0;
    if ( *(_BYTE *)(*(_DWORD *)(v4 + 120) + 684) == 1 && *(int *)(fna + 28) >= 3 )
    {
      v20 = *(_SERVICE_STATUS **)(fna + 24);
      v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 2);
      v5 = GASValue::ToUInt32(this: v6, a2: fna, a3: a1, a4: v20);
    }
    MovieRoot = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fna + 24));
    v8 = (_DWORD **)((char *)MovieRoot + 52 * *((unsigned __int8 *)MovieRoot + v5 + 10228) + 9412);
    v9 = *v8;
    if ( *v8 != nullptr )
    {
      if ( v9[1] != 0 )
      {
        v10 = (GRefCountNTSImpl *)v9[1];
        if ( v10 != nullptr )
        {
          ++v10->RefCount;
          ++v10->RefCount;
          GRefCountNTSImpl::Release(this: v10);
          if ( ((int (__thiscall *)(GRefCountNTSImpl *))v10->__vftable[44].dtr_GRefCountImplCore)(a1: v10) == 4 )
          {
            v11 = 0;
            v12 = 0x7FFFFFFF;
            if ( *(int *)(fna + 28) >= 2 )
            {
              v18 = *(_SERVICE_STATUS **)(fna + 24);
              v13 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
              v14 = GASValue::ToInt32(this: v13, a2: fna, a3: a1, a4: v18);
              v19 = *(_SERVICE_STATUS **)(fna + 24);
              v11 = v14;
              v15 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 1);
              v12 = GASValue::ToInt32(this: v15, a2: fna, a3: v16, a4: v19);
            }
            ((void (__thiscall *)(GRefCountNTSImpl *, int, int))v10->__vftable[94].dtr_GRefCountImplCore)(
              a1: v10,
              a2: v11,
              a3: v12);
          }
          GRefCountNTSImpl::Release(this: v10);
        }
      }
      else
      {
        if ( (*v9)-- == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
        *v8 = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101158C0
// Name: private: static void GASSelectionCtorFunction::GetBeginIndex(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSelectionCtorFunction::GetBeginIndex(void *fn, int fna)
{
  int v2; // esi
  int v3; // eax
  int v4; // esi
  GASValue *v5; // eax
  struct GFxMovieRoot *MovieRoot; // eax
  _DWORD **v7; // esi
  _DWORD *v8; // eax
  GRefCountNTSImpl *v9; // esi
  double v10; // st7
  int v11; // edi
  _SERVICE_STATUS *v13; // [esp-8h] [ebp-18h]

  v2 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v2 >= 5u )
    GASValue::DropRefs(this: *(GASValue **)(fna + 4), a2: fna);
  *(_BYTE *)v2 = 3;
  *(double *)(v2 + 4) = -1.0;
  v3 = *(_DWORD *)(fna + 24);
  if ( v3 != 0 )
  {
    v4 = 0;
    if ( *(_BYTE *)(*(_DWORD *)(v3 + 120) + 684) == 1 && *(int *)(fna + 28) >= 1 )
    {
      v13 = *(_SERVICE_STATUS **)(fna + 24);
      v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
      v4 = GASValue::ToUInt32(this: v5, a2: fna, a3: -1.0, a4: v13);
    }
    MovieRoot = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fna + 24));
    v7 = (_DWORD **)((char *)MovieRoot + 52 * *((unsigned __int8 *)MovieRoot + v4 + 10228) + 9412);
    v8 = *v7;
    if ( *v7 != nullptr )
    {
      if ( v8[1] != 0 )
      {
        v9 = (GRefCountNTSImpl *)v8[1];
        if ( v9 != nullptr )
        {
          ++v9->RefCount;
          ++v9->RefCount;
          GRefCountNTSImpl::Release(this: v9);
          if ( ((int (__thiscall *)(GRefCountNTSImpl *))v9->__vftable[44].dtr_GRefCountImplCore)(a1: v9) == 4 )
          {
            v10 = (double)(unsigned int)((int (__thiscall *)(GRefCountNTSImpl *))v9->__vftable[96].dtr_GRefCountImplCore)(a1: v9);
            v11 = *(_DWORD *)(fna + 4);
            if ( *(_BYTE *)v11 >= 5u )
              GASValue::DropRefs(this: (GASValue *)v11, a2: v11);
            *(_BYTE *)v11 = 3;
            *(double *)(v11 + 4) = v10;
          }
          GRefCountNTSImpl::Release(this: v9);
        }
      }
      else
      {
        if ( (*v8)-- == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
        *v7 = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101159D0
// Name: private: static void GASSelectionCtorFunction::GetEndIndex(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSelectionCtorFunction::GetEndIndex(void *fn, int fna)
{
  int v2; // esi
  int v3; // eax
  int v4; // esi
  GASValue *v5; // eax
  struct GFxMovieRoot *MovieRoot; // eax
  _DWORD **v7; // esi
  _DWORD *v8; // eax
  GRefCountNTSImpl *v9; // esi
  double v10; // st7
  int v11; // edi
  _SERVICE_STATUS *v13; // [esp-8h] [ebp-18h]

  v2 = *(_DWORD *)(fna + 4);
  if ( *(_BYTE *)v2 >= 5u )
    GASValue::DropRefs(this: *(GASValue **)(fna + 4), a2: fna);
  *(_BYTE *)v2 = 3;
  *(double *)(v2 + 4) = -1.0;
  v3 = *(_DWORD *)(fna + 24);
  if ( v3 != 0 )
  {
    v4 = 0;
    if ( *(_BYTE *)(*(_DWORD *)(v3 + 120) + 684) == 1 && *(int *)(fna + 28) >= 1 )
    {
      v13 = *(_SERVICE_STATUS **)(fna + 24);
      v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
      v4 = GASValue::ToUInt32(this: v5, a2: fna, a3: -1.0, a4: v13);
    }
    MovieRoot = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fna + 24));
    v7 = (_DWORD **)((char *)MovieRoot + 52 * *((unsigned __int8 *)MovieRoot + v4 + 10228) + 9412);
    v8 = *v7;
    if ( *v7 != nullptr )
    {
      if ( v8[1] != 0 )
      {
        v9 = (GRefCountNTSImpl *)v8[1];
        if ( v9 != nullptr )
        {
          ++v9->RefCount;
          ++v9->RefCount;
          GRefCountNTSImpl::Release(this: v9);
          if ( ((int (__thiscall *)(GRefCountNTSImpl *))v9->__vftable[44].dtr_GRefCountImplCore)(a1: v9) == 4 )
          {
            v10 = (double)(unsigned int)((int (__thiscall *)(GRefCountNTSImpl *))v9->__vftable[97].dtr_GRefCountImplCore)(a1: v9);
            v11 = *(_DWORD *)(fna + 4);
            if ( *(_BYTE *)v11 >= 5u )
              GASValue::DropRefs(this: (GASValue *)v11, a2: v11);
            *(_BYTE *)v11 = 3;
            *(double *)(v11 + 4) = v10;
          }
          GRefCountNTSImpl::Release(this: v9);
        }
      }
      else
      {
        if ( (*v8)-- == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
        *v7 = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115AE0
// Name: private: static void GASSelectionCtorFunction::CaptureFocus(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASSelectionCtorFunction::CaptureFocus(long double a1@<st0>, int fna)
{
  GASValue *v3; // edi
  char *v4; // eax
  GRefCountWeakSupportImpl *FileRead; // edi
  ISteamRemoteStorage *MovieRoot; // ebx
  GASValue *v7; // eax
  int v8; // esi
  ISteamRemoteStorage_vtbl *v9; // eax
  int v10; // esi
  ISteamRemoteStorage_vtbl *v11; // eax
  bool v12; // zf
  tagPOLYTEXTW *v13; // [esp-4h] [ebp-18h]
  _SERVICE_STATUS *v14; // [esp-4h] [ebp-18h]
  int controllerIdx; // [esp+Ch] [ebp-8h]
  char capture; // [esp+13h] [ebp-1h]

  v3 = *(GASValue **)(fna + 4);
  GASValue::DropRefs(this: v3, a2: (int)v3);
  *(_BYTE *)v3 = 0;
  if ( *(int *)(fna + 28) < 1 )
  {
    capture = 1;
  }
  else
  {
    v13 = *(tagPOLYTEXTW **)(fna + 24);
    v4 = (char *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
    capture = GASValue::ToBool(a1: v4, a2: a1, result: v13);
  }
  FileRead = nullptr;
  MovieRoot = (ISteamRemoteStorage *)GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fna + 24));
  controllerIdx = 0;
  if ( *(int *)(fna + 28) >= 2 )
  {
    v14 = *(_SERVICE_STATUS **)(fna + 24);
    v7 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 1);
    controllerIdx = GASValue::ToUInt32(this: v7, a2: 0, a3: a1, a4: v14);
  }
  v8 = 13 * (*((unsigned __int8 *)&MovieRoot[2557].__vftable + controllerIdx) + 181);
  v9 = MovieRoot[v8].__vftable;
  if ( v9 != nullptr )
  {
    if ( v9->FileRead != nullptr )
    {
      FileRead = (GRefCountWeakSupportImpl *)v9->FileRead;
      if ( FileRead == nullptr )
        goto LABEL_11;
      ++FileRead->RefCount;
      ++FileRead->RefCount;
    }
    else
    {
      v12 = v9->FileWrite-- == (bool (__thiscall *)(ISteamRemoteStorage *, const char *, const void *, int))1;
      if ( v12 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
      MovieRoot[v8].__vftable = nullptr;
    }
  }
  if ( FileRead != nullptr )
  {
LABEL_16:
    GRefCountNTSImpl::Release(this: FileRead);
    goto LABEL_17;
  }
LABEL_11:
  GFxMovieRoot::ActivateFocusCapture(
    this: MovieRoot,
    a2: (const CMaterialDict::MissingMaterial_t *)FileRead,
    a3: controllerIdx);
  v10 = 13 * (*((unsigned __int8 *)&MovieRoot[2557].__vftable + controllerIdx) + 181);
  v11 = MovieRoot[v10].__vftable;
  FileRead = nullptr;
  if ( v11 != nullptr )
  {
    if ( v11->FileRead != nullptr )
    {
      FileRead = (GRefCountWeakSupportImpl *)v11->FileRead;
      if ( FileRead == nullptr )
        goto LABEL_17;
      ++FileRead->RefCount;
      ++FileRead->RefCount;
      GRefCountNTSImpl::Release(this: FileRead);
      ++FileRead->RefCount;
    }
    else
    {
      v12 = v11->FileWrite-- == (bool (__thiscall *)(ISteamRemoteStorage *, const char *, const void *, int))1;
      if ( v12 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
      MovieRoot[v10].__vftable = nullptr;
    }
  }
  if ( FileRead != nullptr )
    goto LABEL_16;
LABEL_17:
  if ( capture != 0 )
  {
    if ( FileRead == nullptr )
      return;
    if ( ((unsigned __int8 (__thiscall *)(GRefCountWeakSupportImpl *))FileRead->__vftable[55].dtr_GRefCountImplCore)(a1: FileRead) != 0 )
      GFxMovieRoot::SetKeyboardFocusTo(this: (CImagePacker *)MovieRoot, result: FileRead, controllerIdx);
  }
  else
  {
    GFxMovieRoot::HideFocusRect(this: (GFxMovieRoot *)MovieRoot, a2: controllerIdx);
  }
  if ( FileRead != nullptr )
  {
    GASValue::SetAsCharacter(this: *(_DWORD *)(fna + 4), result: (tagBITMAPCOREHEADER *)FileRead);
    GRefCountNTSImpl::Release(this: FileRead);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115C60
// Name: private: static void GASSelectionCtorFunction::MoveFocus(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASSelectionCtorFunction::MoveFocus(int a1@<edi>, long double a2@<st0>, int fna)
{
  GASValue *v4; // esi
  int v5; // eax
  GASValue *v6; // eax
  struct GFxMovieRoot *MovieRoot; // edi
  char v8; // al
  GASValue *v9; // eax
  GRefCountNTSImpl *v10; // eax
  GRefCountNTSImpl *v11; // edi
  int v12; // esi
  _DWORD *v13; // eax
  _DWORD *v14; // esi
  char *v15; // eax
  bool v16; // zf
  tagRID_DEVICE_INFO_KEYBOARD *v17; // esi
  unsigned __int8 *v18; // eax
  const char *v19; // esi
  __int16 v20; // ax
  struct GFxLog *Log; // eax
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v22; // ecx
  const char **v23; // eax
  const struct GASEnvironment *v24; // [esp-8h] [ebp-58h]
  tagPOLYTEXTW *v25; // [esp-8h] [ebp-58h]
  int v26; // [esp-8h] [ebp-58h]
  _SERVICE_STATUS *v27; // [esp-4h] [ebp-54h]
  ISteamRemoteStorage *v28; // [esp+8h] [ebp-48h]
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>::SysAllocContainer pfocusInfo; // [esp+Ch] [ebp-44h] BYREF
  float v30; // [esp+18h] [ebp-38h]
  float v31; // [esp+1Ch] [ebp-34h]
  float v32; // [esp+20h] [ebp-30h]
  float v33; // [esp+24h] [ebp-2Ch]
  int v34; // [esp+28h] [ebp-28h]
  __int16 v35; // [esp+2Ch] [ebp-24h]
  int includeFocusEnabled; // [esp+30h] [ebp-20h]
  unsigned int controllerIdx; // [esp+34h] [ebp-1Ch]
  const char **v38; // [esp+38h] [ebp-18h] BYREF
  HINSTANCE__ specKeysState; // [esp+3Fh] [ebp-11h] BYREF
  __int16 v40; // [esp+44h] [ebp-Ch]
  char unused; // [esp+47h] [ebp-9h]
  char v42; // [esp+48h] [ebp-8h]

  v4 = *(GASValue **)(fna + 4);
  GASValue::DropRefs(this: v4, a2: a1);
  *(_BYTE *)v4 = 0;
  v5 = *(_DWORD *)(fna + 28);
  if ( v5 == 0 )
    return;
  controllerIdx = 0;
  if ( v5 >= 4 )
  {
    v27 = *(_SERVICE_STATUS **)(fna + 24);
    v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 3);
    controllerIdx = GASValue::ToUInt32(this: v6, a2: a1, a3: a2, a4: v27);
  }
  MovieRoot = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fna + 24));
  v28 = (ISteamRemoteStorage *)MovieRoot;
  if ( *(int *)(fna + 28) < 2
    || (v8 = *(_BYTE *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 1)) == 0
    || v8 == 10
    || *(_BYTE *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 1) == 1 )
  {
    v12 = 52 * (*((unsigned __int8 *)MovieRoot + controllerIdx + 10228) + 181);
    v13 = *(_DWORD **)((char *)MovieRoot + v12);
    v14 = (_DWORD *)((char *)MovieRoot + v12);
    v11 = nullptr;
    if ( v13 != nullptr )
    {
      if ( v13[1] != 0 )
      {
        v11 = (GRefCountNTSImpl *)v13[1];
        if ( v11 == nullptr )
          goto LABEL_17;
        ++v11->RefCount;
        ++v11->RefCount;
        GRefCountNTSImpl::Release(this: v11);
        ++v11->RefCount;
      }
      else
      {
        v16 = (*v13)-- == 1;
        if ( v16 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v13);
        *v14 = 0;
      }
    }
    if ( v11 != nullptr )
      GRefCountNTSImpl::Release(this: v11);
  }
  else
  {
    v24 = *(const struct GASEnvironment **)(fna + 24);
    v9 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 1);
    GASValue::ToASCharacter(this: v9, penv: v24);
    if ( v10 != nullptr )
      ++v10->RefCount;
    v11 = v10;
  }
LABEL_17:
  if ( *(int *)(fna + 28) < 3 )
  {
    LOBYTE(includeFocusEnabled) = 0;
  }
  else
  {
    v25 = *(tagPOLYTEXTW **)(fna + 24);
    v15 = (char *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 2);
    LOBYTE(includeFocusEnabled) = GASValue::ToBool(a1: v15, a2, result: v25);
  }
  v17 = *(tagRID_DEVICE_INFO_KEYBOARD **)(fna + 24);
  v18 = (unsigned __int8 *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  GASValue::ToStringImpl(this: v18, a2: (int *)&v38, a3: v17, precision: -1, debug: false);
  v19 = *v38;
  LOBYTE(specKeysState.unused) = 0;
  if ( strcmp(v19, "up") == 0 )
  {
    v20 = 38;
  }
  else if ( strcmp(v19, "down") == 0 )
  {
    v20 = 40;
  }
  else if ( GASString::operator==(this: &v38, a2: "left") )
  {
    v20 = 37;
  }
  else if ( GASString::operator==(this: &v38, a2: "right") )
  {
    v20 = 39;
  }
  else
  {
    if ( !GASString::operator==(this: &v38, a2: "tab") )
    {
      if ( !GASString::operator==(this: &v38, a2: "shifttab") )
      {
        if ( GASEnvironment::GetLog(this: *(GASEnvironment **)(fna + 24)) != nullptr )
        {
          v26 = (int)*v38;
          Log = GASEnvironment::GetLog(this: *(GASEnvironment **)(fna + 24));
          GFxLogBase<GFxLog>::LogWarning(
            this: v22,
            pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&Log->GFxLogBase<GFxLog>,
            this_4: (int)"moveFocus: invalid string id for key: '%s'\n",
            this_8: v26);
        }
        goto LABEL_43;
      }
      LOBYTE(specKeysState.unused) = 1;
    }
    v20 = 9;
  }
  v30 = 0.0;
  v31 = 0.0;
  v32 = 0.0;
  v34 = 0;
  v33 = 0.0;
  v35 = 0;
  v40 = v20;
  v42 = controllerIdx;
  pfocusInfo.Data[0] = 0;
  pfocusInfo.Data[1] = 0;
  unused = specKeysState.unused;
  *(_DWORD *)&pfocusInfo.Initialized = -1;
  GFxMovieRoot::InitFocusKeyInfo(
    this: v28,
    &pfocusInfo,
    a3: (const struct GFxInputEventsQueue::QueueEntry::KeyEntry *)((char *)&specKeysState.unused + 1),
    inclFocusEnabled: includeFocusEnabled,
    a5: nullptr);
  if ( v11 != nullptr )
    ++v11->RefCount;
  if ( pfocusInfo.Data[1] != 0 )
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)pfocusInfo.Data[1]);
  pfocusInfo.Data[1] = (unsigned int)v11;
  HIBYTE(v34) = 1;
  GFxMovieRoot::ProcessFocusKey(
    a1: v28,
    a2: (const CMaterialDict::MissingMaterial_t *)v11,
    result: (ISteamRemoteStorage *)5,
    a4: (struct GFxInputEventsQueue::QueueEntry::KeyEntry *)((char *)&specKeysState.unused + 1),
    &pfocusInfo);
  GFxMovieRoot::FinalizeProcessFocusKey(
    this: (GFxMovieRoot *)v28,
    a2: (GMemoryHeap *)fna,
    a3: (GRefCountNTSImpl *)&pfocusInfo);
  GASValue::SetAsCharacter(this: *(_DWORD *)(fna + 4), result: (tagBITMAPCOREHEADER *)pfocusInfo.Data[1]);
  if ( pfocusInfo.Data[1] != 0 )
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)pfocusInfo.Data[1]);
LABEL_43:
  v23 = v38;
  v16 = v38[2]-- == (const char *)1;
  if ( v16 )
    GASStringNode::ReleaseNode(a1: (int)v23);
  if ( v11 != nullptr )
    GRefCountNTSImpl::Release(this: v11);
}

//------------------------------------------------------------------------------
// Address: 0x10115F80
// Name: private: static void GASSelectionCtorFunction::GetFocusArray(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSelectionCtorFunction::GetFocusArray(void *fn, int fna)
{
  int v2; // edi
  GASValue *v3; // esi
  int v4; // eax
  GASValue *v5; // eax
  GRefCountNTSImpl *v6; // eax
  struct GASObject *v7; // eax
  struct GASObject *v8; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *v9; // eax
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v10; // ebx
  struct GFxMovieRoot *MovieRoot; // eax
  _DWORD **v12; // esi
  _DWORD *v13; // eax
  GRefCountNTSImpl *v14; // edi
  struct GASObject *v15; // esi
  const struct GASEnvironment *v17; // [esp-4h] [ebp-28h]
  GASValue v18[4]; // [esp+8h] [ebp-1Ch] BYREF
  int v19; // [esp+18h] [ebp-Ch] BYREF
  GRefCountNTSImpl *v20; // [esp+1Ch] [ebp-8h]
  struct GASObject *v21; // [esp+20h] [ebp-4h]

  v2 = fna;
  v3 = *(GASValue **)(fna + 4);
  GASValue::DropRefs(this: v3, a2: fna);
  *(_BYTE *)v3 = 1;
  v4 = *(_DWORD *)(fna + 24);
  if ( v4 == 0 || *(_BYTE *)(*(_DWORD *)(v4 + 120) + 684) != 1 || *(int *)(fna + 28) < 1 )
    return;
  v17 = *(const struct GASEnvironment **)(fna + 24);
  v5 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  GASValue::ToASCharacter(this: v5, penv: v17);
  v20 = v6;
  if ( v6 != nullptr )
    ++v6->RefCount;
  v7 = GASEnvironment::OperatorNew(
         this: *(__vc_attributes::idl_quoteAttribute **)(fna + 24),
         a2: fna,
         a3: *(struct GASObject **)(*(_DWORD *)(*(_DWORD *)(fna + 24) + 120) + 680),
         a4: (const struct GASString *)(*(_DWORD *)(*(_DWORD *)(fna + 24) + 120) + 16),
         nargs: 0,
         argsTopOff: -1);
  v8 = v7 + 7;
  v21 = v7;
  if ( v7[8].pNode >= (CTSQueue<CFunctor *,0,1>::Node_t *)4 )
    goto LABEL_10;
  if ( v8->pNode == nullptr )
  {
    v19 = 2;
    v8->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                                      this: GMemory::pGlobalHeap,
                                                      a2: v8,
                                                      a3: 16,
                                                      a4: &v19);
    v8[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)4;
LABEL_10:
    v10 = nullptr;
    goto LABEL_12;
  }
  v9 = (CTSQueue<CFunctor *,0,1>::Node_t *)GMemory::pGlobalHeap->Realloc(
                                             this: GMemory::pGlobalHeap,
                                             a2: v8->pNode,
                                             a3: 16);
  v8[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)4;
  v8->pNode = v9;
  v10 = nullptr;
  while ( 1 )
  {
LABEL_12:
    MovieRoot = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(v2 + 24));
    v12 = (_DWORD **)((char *)MovieRoot
                    + 52 * *((unsigned __int8 *)&v10[852].m_nAllocationCount + (_DWORD)MovieRoot)
                    + 9412);
    v13 = *v12;
    v14 = nullptr;
    if ( *v12 != nullptr )
    {
      if ( v13[1] != 0 )
      {
        v14 = (GRefCountNTSImpl *)v13[1];
        if ( v14 != nullptr )
        {
          ++v14->RefCount;
          ++v14->RefCount;
          GRefCountNTSImpl::Release(this: v14);
        }
      }
      else
      {
        if ( (*v13)-- == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v13);
        *v12 = nullptr;
      }
    }
    if ( v14 == v20 )
    {
      LOBYTE(v18[0]) = 4;
      v18[1] = v10;
      GASArrayObject::PushBack(this: (GASArrayObject *)v21, val: (tagWNDCLASSW *)v18);
      GASValue::~GASValue(this: v18, a2: (int)v14);
    }
    if ( v14 != nullptr )
      GRefCountNTSImpl::Release(this: v14);
    v10 = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *)((char *)v10 + 1);
    if ( (unsigned int)v10 >= 4 )
      break;
    v2 = fna;
  }
  v15 = v21;
  GASValue::SetAsObject(this: *(GASValue **)(fna + 4), a2: v21);
  if ( v15 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v15, a2: (int)v14);
  if ( v20 != nullptr )
    GRefCountNTSImpl::Release(this: v20);
}

//------------------------------------------------------------------------------
// Address: 0x10116100
// Name: public: static void GASSelection::BroadcastOnSetFocus(class GASEnvironment __near *,class GFxASCharacter __near *,class GFxASCharacter __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASSelection::BroadcastOnSetFocus(
        __vc_attributes::iid_isAttribute *nargs,
        tagAXISINFOA *a2,
        tagAXISINFOA *result,
        unsigned int controllerIdx)
{
  const char *limited_expression; // eax
  __vc_attributes::iid_isAttribute *v6; // esi
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **v7; // edi
  struct GASObject *v8; // eax
  char *v9; // esi
  double v10; // st7
  tagAXISINFOA *v11; // eax
  __vc_attributes::iid_isAttribute *v12; // esi
  tagWNDCLASSW *v13; // edi
  tagAXISINFOA *v14; // eax
  tagWNDCLASSW *v15; // edi
  int v16; // edi
  struct GASStringNode *ConstStringNode; // eax
  _IMAGE_SYMBOL_EX *v18; // ecx
  int v19; // eax
  int v21; // [esp-4h] [ebp-34h]
  GASValue selectionCtorVal[4]; // [esp+Ch] [ebp-24h] BYREF
  _IMAGE_SYMBOL_EX *v23; // [esp+1Ch] [ebp-14h]
  GASValue v24[2]; // [esp+20h] [ebp-10h] BYREF
  double v25; // [esp+28h] [ebp-8h] BYREF
  int nargsa; // [esp+38h] [ebp+8h]

  limited_expression = nargs[30].limited_expression;
  v6 = nargs + 30;
  LOBYTE(selectionCtorVal[0]) = 0;
  v7 = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)selectionCtorVal;
  if ( (*(unsigned __int8 (__thiscall **)(int, __vc_attributes::iid_isAttribute *, const char *, GASValue *))(*(_DWORD *)(*((_DWORD *)limited_expression + 170) + 16) + 44))(
         a1: *((_DWORD *)limited_expression + 170) + 16,
         a2: nargs + 30,
         a3: limited_expression + 92,
         a4: selectionCtorVal) != 0 )
  {
    v8 = GASValue::ToObject(this: selectionCtorVal, a2: (int)selectionCtorVal, a3: (const struct GASEnvironment *)nargs);
    if ( v8 != nullptr )
    {
      v23 = (_IMAGE_SYMBOL_EX *)&v8[2];
      if ( v8 != (struct GASObject *)-16 )
      {
        nargsa = 2;
        if ( *((_BYTE *)v6->limited_expression + 684) == 1 )
        {
          nargs[2].limited_expression += 16;
          v25 = (double)controllerIdx;
          if ( nargs[2].limited_expression >= nargs[4].limited_expression )
            GASPagedStack<GASValue,32>::PushPage(this: nargs + 2);
          v9 = (char *)nargs[2].limited_expression;
          if ( v9 != nullptr )
          {
            v10 = v25;
            *v9 = 3;
            *(double *)(v9 + 4) = v10;
          }
          nargsa = 3;
        }
        if ( result != nullptr )
        {
          v11 = GASValue::GASValue(this: v24, result);
          nargs[2].limited_expression += 16;
          v12 = nargs + 2;
          v13 = (tagWNDCLASSW *)v11;
          if ( nargs[2].limited_expression >= nargs[4].limited_expression )
            GASPagedStack<GASValue,32>::PushPage(this: nargs + 2);
          if ( v12->limited_expression != nullptr )
            GASValue::GASValue(this: (GASValue *)v12->limited_expression, v: v13);
          GASValue::~GASValue(this: v24, a2: (int)v13);
        }
        else
        {
          nargs[2].limited_expression += 16;
          v12 = nargs + 2;
          if ( nargs[2].limited_expression >= nargs[4].limited_expression )
            GASPagedStack<GASValue,32>::PushPage(this: nargs + 2);
          if ( v12->limited_expression != nullptr )
            *v12->limited_expression = 1;
        }
        if ( a2 != nullptr )
        {
          v14 = GASValue::GASValue(this: v24, result: a2);
          v12->limited_expression += 16;
          v15 = (tagWNDCLASSW *)v14;
          if ( v12->limited_expression >= v12[2].limited_expression )
            GASPagedStack<GASValue,32>::PushPage(this: v12);
          if ( v12->limited_expression != nullptr )
            GASValue::GASValue(this: (GASValue *)v12->limited_expression, v: v15);
          GASValue::~GASValue(this: v24, a2: (int)v15);
        }
        else
        {
          v12->limited_expression += 16;
          if ( v12->limited_expression >= v12[2].limited_expression )
            GASPagedStack<GASValue,32>::PushPage(this: v12);
          if ( v12->limited_expression != nullptr )
            *v12->limited_expression = 1;
        }
        v16 = ((v12->limited_expression - v12[1].limited_expression) >> 4) + 32 * (int)v12[5].limited_expression - 32;
        ConstStringNode = GASStringManager::CreateConstStringNode(
                            this: *((GASStringManager **)nargs[30].limited_expression + 159),
                            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A4128,
                            a3: 0xAu,
                            a4: 0);
        v18 = v23;
        v21 = v16;
        v7 = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)nargsa;
        HIDWORD(v25) = ConstStringNode;
        ++*((_DWORD *)ConstStringNode + 2);
        GASAsBroadcaster::BroadcastMessage(
          a1: (struct GASEnvironment *)nargs,
          eventName: v18,
          a3: (const struct GASString *)((char *)&v25 + 4),
          nArgs: nargsa,
          firstArgBottomIndex: v21);
        v19 = HIDWORD(v25);
        if ( (*(_DWORD *)(HIDWORD(v25) + 8))-- == 1 )
          GASStringNode::ReleaseNode(a1: v19);
        do
        {
          GASValue::~GASValue(this: (GASValue *)v12->limited_expression, a2: (int)v7);
          v12->limited_expression -= 16;
          if ( v12->limited_expression < v12[1].limited_expression )
            GASPagedStack<GASValue,32>::PopPage(this: v12);
          v7 = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)((char *)v7 - 1);
        }
        while ( v7 != nullptr );
      }
    }
  }
  GASValue::~GASValue(this: selectionCtorVal, a2: (int)v7);
}

//------------------------------------------------------------------------------
// Address: 0x101162E0
// Name: public: static void GASSelection::QueueSetFocus(class GASEnvironment __near *,class GFxASCharacter __near *,unsigned int,enum GFxFocusMovedType)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASSelection::QueueSetFocus(
        tagAXISINFOA *a1@<edi>,
        GASEnvironment *a2,
        tagAXISINFOA *result,
        unsigned int controllerIdx,
        const wchar_t *a5)
{
  int v6; // esi
  GASValue *v7; // ecx
  int v8; // esi
  const IDirect3DPixelShader9 *v9; // ebx
  struct GFxMovieRoot *MovieRoot; // eax
  GPtr<IDirect3DPixelShader9> *inserted; // esi
  GFxMovieRoot *v12; // eax
  struct GFxSprite *LevelMovie; // eax
  IDirect3DPixelShader9 *v14; // edi
  GRefCountNTSImpl *pObject; // ecx
  GRefCountNTSImpl *v16; // ecx
  int v17; // edi
  GASValue *i; // esi
  _DWORD v19[4]; // [esp+Ch] [ebp-4Ch] BYREF
  tagWNDCLASSW v20; // [esp+1Ch] [ebp-3Ch] BYREF
  const IDirect3DPixelShader9 *params; // [esp+4Ch] [ebp-Ch] BYREF
  int v22; // [esp+50h] [ebp-8h]
  int v23; // [esp+54h] [ebp-4h]

  params = nullptr;
  v22 = 0;
  v23 = 0;
  if ( result != nullptr )
  {
    a1 = GASValue::GASValue(this: v19, result);
    GArrayDataBase<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: (GPtr<IDirect3DPixelShader9> *)&params,
      pheapAddr: (ButtonCode_t)&params,
      newSize: 1u);
    v6 = v22;
    if ( &params[4 * v22] != (const IDirect3DPixelShader9 *)16 )
      GASValue::GASValue(this: (GASValue *)&params[4 * v22 - 4], v: (tagWNDCLASSW *)a1);
    v7 = (GASValue *)v19;
  }
  else
  {
    LOBYTE(v20.style) = 1;
    GArrayDataBase<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: (GPtr<IDirect3DPixelShader9> *)&params,
      pheapAddr: (ButtonCode_t)&params,
      newSize: 1u);
    v6 = v22;
    if ( &params[4 * v22] != (const IDirect3DPixelShader9 *)16 )
      GASValue::GASValue(this: (GASValue *)&params[4 * v22 - 4], v: &v20);
    v7 = (GASValue *)&v20;
  }
  GASValue::~GASValue(this: v7, a2: (int)a1);
  v20.lpszClassName = a5;
  LOBYTE(v20.lpszMenuName) = 4;
  GArrayDataBase<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: (GPtr<IDirect3DPixelShader9> *)&params,
    pheapAddr: (ButtonCode_t)&params,
    newSize: v6 + 1);
  v8 = v22;
  if ( &params[4 * v22] != (const IDirect3DPixelShader9 *)16 )
    GASValue::GASValue(this: (GASValue *)&params[4 * v22 - 4], v: (tagWNDCLASSW *)&v20.lpszMenuName);
  GASValue::~GASValue(this: (GASValue *)&v20.lpszMenuName, a2: (int)a1);
  LOBYTE(v20.hInstance) = 3;
  *(double *)&v20.hIcon = (double)controllerIdx;
  GArrayDataBase<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: (GPtr<IDirect3DPixelShader9> *)&params,
    pheapAddr: (ButtonCode_t)&params,
    newSize: v8 + 1);
  v9 = &params[4 * v22 - 4];
  if ( &params[4 * v22] != (const IDirect3DPixelShader9 *)16 )
    GASValue::GASValue(this: (GASValue *)&params[4 * v22 - 4], v: (tagWNDCLASSW *)&v20.hInstance);
  GASValue::~GASValue(this: (GASValue *)&v20.hInstance, a2: (int)a1);
  MovieRoot = GASEnvironment::GetMovieRoot(this: a2);
  inserted = (GPtr<IDirect3DPixelShader9> *)GFxMovieRoot::ActionQueueType::InsertEntry(
                                              this: (int)MovieRoot + 9224,
                                              result: (const GPoint3<float> *)4);
  v12 = (GFxMovieRoot *)GASEnvironment::GetMovieRoot(this: a2);
  LevelMovie = GFxMovieRoot::GetLevelMovie(this: v12, level: 0);
  v14 = (IDirect3DPixelShader9 *)LevelMovie;
  inserted[1].pObject = (IDirect3DPixelShader9 *)4;
  if ( LevelMovie != nullptr )
    ++*((_DWORD *)LevelMovie + 1);
  pObject = (GRefCountNTSImpl *)inserted[2].pObject;
  if ( pObject != nullptr )
    GRefCountNTSImpl::Release(this: pObject);
  inserted[2].pObject = v14;
  v16 = (GRefCountNTSImpl *)inserted[3].pObject;
  if ( v16 != nullptr )
    GRefCountNTSImpl::Release(this: v16);
  inserted[3].pObject = nullptr;
  inserted[11].pObject = (IDirect3DPixelShader9 *)GASSelection::DoTransferFocus;
  GArrayBase<GArrayData<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>>::operator=(
    this: inserted + 12,
    a2: &params);
  v17 = v22;
  for ( i = (GASValue *)v9; v17 != 0; --v17 )
  {
    GASValue::~GASValue(this: i, a2: v17);
    i -= 4;
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)params);
}

//------------------------------------------------------------------------------
// Address: 0x10116490
// Name: private: static void GASSelectionCtorFunction::FindFocus(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASSelectionCtorFunction::FindFocus(int a1@<edi>, long double a2@<st0>, int fna)
{
  GASValue *v4; // esi
  int v5; // eax
  GASValue *v6; // eax
  GFxMovieRoot *MovieRoot; // eax
  bool v8; // cc
  char v9; // al
  GASValue *v10; // eax
  GStat::StatValue *v11; // eax
  _DWORD **v12; // esi
  _DWORD *v13; // eax
  GRefCountNTSImpl *v14; // edi
  char *v15; // eax
  bool v16; // zf
  tagRID_DEVICE_INFO_KEYBOARD *v17; // esi
  unsigned __int8 *v18; // eax
  const char **v19; // edi
  const char *v20; // esi
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v21; // edi
  tagWNDCLASSW *v22; // eax
  GStat::StatValue *v23; // eax
  GStat::StatValue *ModalClip; // eax
  char *v25; // eax
  double v26; // st7
  int v27; // ecx
  GMemoryHeap *v28; // eax
  _DWORD *v29; // esi
  _DWORD *v30; // eax
  GFxCharacterHandle *Depth; // eax
  GFxCharacterHandle *v32; // edi
  GStat::StatValue *v33; // edi
  struct GWeakPtrProxy *WeakProxy; // esi
  _DWORD *Height; // eax
  _DWORD *v36; // eax
  ISteamRemoteStorage *v37; // esi
  unsigned int v38; // ebx
  unsigned int v39; // edi
  __int32 v40; // ecx
  GFxCharacter *v41; // esi
  float *v42; // eax
  double v43; // st7
  char v44; // fps^1
  bool v45; // c0
  char v46; // c2
  bool v47; // c3
  char v48; // ah
  double v49; // st6
  bool v50; // c0
  double v51; // st7
  double v52; // st7
  char v53; // fps^1
  bool v54; // c0
  char v55; // c2
  bool v56; // c3
  char v57; // ah
  char v58; // fps^1
  bool v59; // c0
  char v60; // c2
  bool v61; // c3
  char v62; // fps^1
  bool v63; // c0
  char v64; // c2
  bool v65; // c3
  GASValue *v66; // esi
  const char **v67; // eax
  GStat::StatValue *v68; // ecx
  const struct GASEnvironment *v69; // [esp-8h] [ebp-E8h]
  tagPOLYTEXTW *v70; // [esp-8h] [ebp-E8h]
  tagPOLYTEXTW *v71; // [esp-8h] [ebp-E8h]
  _SERVICE_STATUS *v72; // [esp-4h] [ebp-E4h]
  _BYTE v73[16]; // [esp+8h] [ebp-D8h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *context; // [esp+18h] [ebp-C8h] BYREF
  int v75; // [esp+28h] [ebp-B8h]
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>::SysAllocContainer pfocusInfo; // [esp+2Ch] [ebp-B4h] BYREF
  float v77; // [esp+38h] [ebp-A8h]
  float v78; // [esp+3Ch] [ebp-A4h]
  float v79; // [esp+40h] [ebp-A0h]
  float v80; // [esp+44h] [ebp-9Ch]
  int v81; // [esp+48h] [ebp-98h]
  __int16 v82; // [esp+4Ch] [ebp-94h]
  _D3DVOLUME_DESC focusGroup; // [esp+50h] [ebp-90h] BYREF
  __int16 v84; // [esp+6Ch] [ebp-74h]
  float v85; // [esp+70h] [ebp-70h]
  float v86; // [esp+74h] [ebp-6Ch]
  float v87; // [esp+78h] [ebp-68h]
  float v88; // [esp+7Ch] [ebp-64h]
  char v89; // [esp+80h] [ebp-60h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> bRect; // [esp+84h] [ebp-5Ch] BYREF
  float v91; // [esp+90h] [ebp-50h]
  GStat::StatValue *panelChar; // [esp+94h] [ebp-4Ch]
  GFxMovieRoot *v93; // [esp+98h] [ebp-48h]
  unsigned int n; // [esp+9Ch] [ebp-44h]
  const char **v95; // [esp+A0h] [ebp-40h] BYREF
  GStat::StatValue *startChar; // [esp+A4h] [ebp-3Ch]
  int keycode; // [esp+A8h] [ebp-38h]
  bool looping; // [esp+AFh] [ebp-31h]
  float lastV; // [esp+B0h] [ebp-30h]
  HINSTANCE__ specKeysState; // [esp+B7h] [ebp-29h] BYREF
  _BYTE v101[4]; // [esp+D0h] [ebp-10h] BYREF
  __int16 v102; // [esp+D4h] [ebp-Ch]
  char unused; // [esp+D7h] [ebp-9h]
  char v104; // [esp+D8h] [ebp-8h]

  v4 = *(GASValue **)(fna + 4);
  v75 = fna;
  GASValue::DropRefs(this: v4, a2: a1);
  *(_BYTE *)v4 = 0;
  v5 = *(_DWORD *)(fna + 28);
  if ( v5 == 0 )
    return;
  lastV = 0.0;
  if ( v5 >= 6 )
  {
    v72 = *(_SERVICE_STATUS **)(fna + 24);
    v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 5);
    lastV = COERCE_FLOAT(GASValue::ToUInt32(this: v6, a2: a1, a3: a2, a4: v72));
  }
  MovieRoot = (GFxMovieRoot *)GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(fna + 24));
  v8 = *(_DWORD *)(fna + 28) < 4;
  v93 = MovieRoot;
  if ( v8
    || (v9 = *(_BYTE *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 3)) == 0
    || v9 == 10
    || *(_BYTE *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 3) == 1 )
  {
    v12 = (_DWORD **)((char *)v93 + 52 * *((unsigned __int8 *)v93 + LODWORD(lastV) + 10228) + 9412);
    v13 = *v12;
    v14 = nullptr;
    if ( *v12 != nullptr )
    {
      if ( v13[1] != 0 )
      {
        v14 = (GRefCountNTSImpl *)v13[1];
        if ( v14 != nullptr )
        {
          ++v14->RefCount;
          ++v14->RefCount;
          GRefCountNTSImpl::Release(this: v14);
          ++v14->RefCount;
        }
      }
      else
      {
        v16 = (*v13)-- == 1;
        if ( v16 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v13);
        *v12 = nullptr;
      }
    }
    startChar = (GStat::StatValue *)v14;
    if ( v14 != nullptr )
      GRefCountNTSImpl::Release(this: v14);
  }
  else
  {
    v69 = *(const struct GASEnvironment **)(fna + 24);
    v10 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 3);
    GASValue::ToASCharacter(this: v10, penv: v69);
    if ( v11 != nullptr )
      ++v11->pName;
    startChar = v11;
  }
  if ( *(int *)(fna + 28) < 5 )
  {
    LOBYTE(n) = 0;
  }
  else
  {
    v70 = *(tagPOLYTEXTW **)(fna + 24);
    v15 = (char *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 4);
    LOBYTE(n) = GASValue::ToBool(a1: v15, a2, result: v70);
  }
  v17 = *(tagRID_DEVICE_INFO_KEYBOARD **)(fna + 24);
  v18 = (unsigned __int8 *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 0);
  GASValue::ToStringImpl(this: v18, a2: (int *)&v95, a3: v17, precision: -1, debug: false);
  v19 = v95;
  v20 = *v95;
  LOBYTE(specKeysState.unused) = 0;
  if ( strcmp(v20, "up") == 0 )
  {
    keycode = 38;
  }
  else if ( strcmp(v20, "down") == 0 )
  {
    keycode = 40;
  }
  else if ( GASString::operator==(this: &v95, a2: "left") )
  {
    keycode = 37;
  }
  else if ( GASString::operator==(this: &v95, a2: "right") )
  {
    keycode = 39;
  }
  else
  {
    if ( !GASString::operator==(this: &v95, a2: "tab") )
    {
      if ( !GASString::operator==(this: &v95, a2: "shifttab") )
      {
        v16 = v19[2]-- == (const char *)1;
        if ( v16 )
          GASStringNode::ReleaseNode(a1: (int)v19);
        v68 = startChar;
        if ( startChar != nullptr )
          goto LABEL_108;
        return;
      }
      LOBYTE(specKeysState.unused) = 1;
    }
    keycode = 9;
  }
  v21 = nullptr;
  v8 = *(_DWORD *)(fna + 28) < 2;
  panelChar = nullptr;
  if ( !v8 )
  {
    v22 = (tagWNDCLASSW *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 1);
    GASValue::GASValue(this: &context, v: v22);
    if ( (unsigned __int8)context < 2u || (_BYTE)context == 10 )
    {
      ModalClip = (GStat::StatValue *)GFxMovieRoot::GetModalClip(this: v93, a2: LODWORD(lastV));
      if ( ModalClip != nullptr )
        ++ModalClip->pName;
      v21 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)ModalClip;
      panelChar = ModalClip;
    }
    else
    {
      GASValue::ToASCharacter(this: &context, penv: *(const struct GASEnvironment **)(fna + 24));
      if ( v23 != nullptr )
        ++v23->pName;
      v21 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v23;
      panelChar = v23;
    }
    GASValue::~GASValue(this: &context, a2: (int)v21);
  }
  if ( *(int *)(fna + 28) < 3 )
  {
    looping = false;
  }
  else
  {
    v71 = *(tagPOLYTEXTW **)(fna + 24);
    v25 = (char *)GASFnCall::Arg(this: (GASFnCall *)fna, a2: 2);
    looping = GASValue::ToBool(a1: v25, a2, result: v71);
  }
  v26 = 0.0;
  v77 = 0.0;
  v78 = 0.0;
  v81 = 0;
  v79 = 0.0;
  v82 = 0;
  v80 = 0.0;
  v104 = LOBYTE(lastV);
  v27 = *(_DWORD *)(fna + 24);
  pfocusInfo.Data[0] = 0;
  pfocusInfo.Data[1] = 0;
  *(_DWORD *)&pfocusInfo.Initialized = -1;
  v102 = keycode;
  unused = specKeysState.unused;
  v28 = *(GMemoryHeap **)(*(_DWORD *)(v27 + 120) + 656);
  LOBYTE(focusGroup.Format) = 0;
  if ( v28 == nullptr )
  {
    v28 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: &focusGroup);
    v26 = 0.0;
  }
  v85 = v26;
  focusGroup.Width = (unsigned int)v28;
  v86 = v26;
  v87 = v26;
  v88 = v26;
  memset(&focusGroup.Type, 0, 12);
  focusGroup.Height = 0;
  focusGroup.Depth = 0;
  v84 = 0;
  v89 = 0;
  if ( v21 != nullptr )
  {
    v29 = (_DWORD *)DWORD1(v21[6].m_pfnProxied);
    if ( v29 != nullptr
      || (GFxASCharacter::CreateCharacterHandle(this: v21),
          v29 = v30,
          Depth = (GFxCharacterHandle *)focusGroup.Depth,
          v29 != nullptr) )
    {
      ++*v29;
      Depth = (GFxCharacterHandle *)focusGroup.Depth;
    }
    if ( Depth != nullptr )
    {
      *Depth = (GFxCharacterHandle)((char *)*Depth - 1);
      v32 = Depth;
      if ( (int)*Depth <= 0 )
      {
        GFxCharacterHandle::~GFxCharacterHandle(this: Depth);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v32);
      }
    }
  }
  else
  {
    v29 = nullptr;
  }
  focusGroup.Depth = (unsigned int)v29;
  if ( startChar != nullptr )
  {
    v33 = startChar;
    WeakProxy = GRefCountWeakSupportImpl::CreateWeakProxy(this: (GRefCountWeakSupportImpl *)startChar);
    Height = (_DWORD *)focusGroup.Height;
    if ( focusGroup.Height != 0 )
    {
      --*(_DWORD *)focusGroup.Height;
      if ( *Height == 0 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: Height);
    }
    focusGroup.Height = (unsigned int)WeakProxy;
  }
  else
  {
    v36 = (_DWORD *)focusGroup.Height;
    if ( focusGroup.Height != 0 )
    {
      --*(_DWORD *)focusGroup.Height;
      if ( *v36 == 0 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v36);
    }
    v33 = startChar;
    focusGroup.Height = 0;
  }
  v37 = (ISteamRemoteStorage *)v93;
  GFxMovieRoot::InitFocusKeyInfo(
    this: (ISteamRemoteStorage *)v93,
    &pfocusInfo,
    a3: (const struct GFxInputEventsQueue::QueueEntry::KeyEntry *)v101,
    inclFocusEnabled: n,
    a5: &focusGroup);
  HIBYTE(v81) = 1;
  GFxMovieRoot::ProcessFocusKey(
    a1: v37,
    a2: (const CMaterialDict::MissingMaterial_t *)v33,
    result: (ISteamRemoteStorage *)5,
    a4: (struct GFxInputEventsQueue::QueueEntry::KeyEntry *)v101,
    &pfocusInfo);
  if ( pfocusInfo.Data[1] == 0 || (GStat::StatValue *)pfocusInfo.Data[1] == v33 )
  {
    if ( looping && focusGroup.Usage != 0 )
    {
      if ( (_WORD)keycode == 9 )
      {
        if ( (specKeysState.unused & 1) != 0 )
          GASValue::SetAsCharacter(
            this: *(_DWORD *)(fna + 4),
            result: *(tagBITMAPCOREHEADER **)(focusGroup.Type + 4 * focusGroup.Usage - 4));
        else
          GASValue::SetAsCharacter(this: *(_DWORD *)(fna + 4), result: *(tagBITMAPCOREHEADER **)focusGroup.Type);
      }
      else
      {
        v38 = 0;
        v39 = 0;
        lastV = 1.1754944e-38;
        n = focusGroup.Usage;
        do
        {
          v40 = focusGroup.Type + 4 * v39;
          if ( *(_DWORD *)v40 != 0 )
            ++*(_DWORD *)(*(_DWORD *)v40 + 4);
          v41 = *(GFxCharacter **)v40;
          if ( ((_BYTE)v82 != 0
             || (*(unsigned __int8 (__thiscall **)(GFxCharacter *))(*(_DWORD *)v41 + 212))(a1: v41) != 0)
            && (*(unsigned __int8 (__thiscall **)(GFxCharacter *, GFxMovieRoot *, _DWORD))(*(_DWORD *)v41 + 196))(
                 a1: v41,
                 a2: v93,
                 a3: BYTE2(v81)) != 0 )
          {
            GMatrix2D::SetIdentity(this: (float *)((char *)&specKeysState.unused + 1));
            GFxCharacter::GetLevelMatrix(this: v41, pmat: (CMaterialDict *)((char *)&specKeysState.unused + 1));
            v42 = (float *)(*(int (__thiscall **)(GFxCharacter *, _BYTE *))(*(_DWORD *)v41 + 244))(a1: v41, a2: v73);
            *(float *)&bRect.m_pMemory = 0.0;
            *(float *)&bRect.m_nAllocationCount = 0.0;
            *(float *)&bRect.m_nGrowSize = 0.0;
            v91 = 0.0;
            GMatrix2D::EncloseTransform(
              this: (float *)((char *)&specKeysState.unused + 1),
              a2: (float *)&bRect,
              a3: v42);
            switch ( (__int16)keycode )
            {
              case '%':
                v52 = lastV;
                v59 = lastV > 1.1754944e-38;
                v60 = 0;
                v61 = 1.1754944e-38 == lastV;
                v57 = v58;
                v49 = *(float *)&bRect.m_nGrowSize;
                goto LABEL_91;
              case '&':
                v52 = lastV;
                v54 = lastV > 1.1754944e-38;
                v55 = 0;
                v56 = 1.1754944e-38 == lastV;
                v57 = v53;
                v49 = v91;
LABEL_91:
                if ( !__SETP__(v57 & 0x44, 0) )
                  goto LABEL_88;
                if ( v49 > v52 )
                {
                  lastV = v49;
                  v38 = v39;
                }
                break;
              case '\'':
                v43 = lastV;
                v63 = lastV > 1.1754944e-38;
                v64 = 0;
                v65 = 1.1754944e-38 == lastV;
                v48 = v62;
                v49 = *(float *)&bRect.m_pMemory;
                goto LABEL_84;
              case '(':
                v43 = lastV;
                v45 = lastV > 1.1754944e-38;
                v46 = 0;
                v47 = 1.1754944e-38 == lastV;
                v48 = v44;
                v49 = *(float *)&bRect.m_nAllocationCount;
LABEL_84:
                if ( __SETP__(v48 & 0x44, 0) )
                {
                  v50 = v49 < v43;
                  v51 = v49;
                  if ( !v50 )
                    break;
                }
                else
                {
LABEL_88:
                  v51 = v49;
                }
                lastV = v51;
                v38 = v39;
                break;
              default:
                break;
            }
          }
          GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v41);
          ++v39;
        }
        while ( v39 < n );
        GASValue::SetAsCharacter(
          this: *(_DWORD *)(v75 + 4),
          result: *(tagBITMAPCOREHEADER **)(focusGroup.Type + 4 * v38));
        v33 = startChar;
      }
    }
    else
    {
      v66 = *(GASValue **)(fna + 4);
      GASValue::DropRefs(this: v66, a2: (int)v33);
      *(_BYTE *)v66 = 1;
    }
  }
  else
  {
    GASValue::SetAsCharacter(this: *(_DWORD *)(fna + 4), result: (tagBITMAPCOREHEADER *)pfocusInfo.Data[1]);
  }
  GFxMovieRoot::FocusGroupDescr::~FocusGroupDescr(this: (GMatrix3D *)&focusGroup);
  if ( pfocusInfo.Data[1] != 0 )
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)pfocusInfo.Data[1]);
  if ( panelChar != nullptr )
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)panelChar);
  v67 = v95;
  v16 = v95[2]-- == (const char *)1;
  if ( v16 )
    GASStringNode::ReleaseNode(a1: (int)v67);
  if ( v33 != nullptr )
  {
    v68 = v33;
LABEL_108:
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v68);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116B60
// Name: public: virtual bool GASSelectionCtorFunction::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASSelectionCtorFunction::GetMember(
        GArrayBase<GArrayData<GPtr<GFxAmpMemItem>,GAllocatorLH<GPtr<GFxAmpMemItem>,2>,GArrayDefaultPolicy> > *this,
        D3DXQUATERNION *a2,
        const char ***name,
        GASValue *a4)
{
  ID3DXFont *v4; // ecx
  struct GFxMovieRoot *MovieRoot; // ebx
  tagWNDCLASSW *v6; // eax
  int v8; // eax
  int v9; // edi
  int v10; // eax
  int v11; // edi
  int v12; // eax
  tagBITMAPCOREHEADER *ModalClip; // eax
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v14; // eax
  GASValue v15[4]; // [esp+Ch] [ebp-18h] BYREF
  D3DXQUATERNION *v16; // [esp+1Ch] [ebp-8h]
  _REASON_CONTEXT *func; // [esp+20h] [ebp-4h]

  v16 = (D3DXQUATERNION *)this;
  v4 = (ID3DXFont *)a2;
  func = (_REASON_CONTEXT *)&a2[7].z;
  if ( *(_BYTE *)(LODWORD(a2[7].z) + 684) == 1 )
  {
    MovieRoot = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)a2);
    if ( strcmp(**name, "captureFocus") == 0 )
    {
      v6 = (tagWNDCLASSW *)GASValue::GASValue(
                             this: v15,
                             (int)func,
                             a3: (void (__cdecl *)(const struct GASFnCall *))GASSelectionCtorFunction::CaptureFocus);
LABEL_4:
      GASValue::operator=(this: (int)a4, v: v6);
LABEL_5:
      GASValue::~GASValue(this: v15, a2: (int)name);
      return 1;
    }
    if ( strcmp(**name, "disableFocusAutoRelease") == 0 )
    {
      v8 = (*((_DWORD *)MovieRoot + 2333) >> 22) & 3;
      if ( v8 != 3 )
      {
        if ( v8 != 0 )
        {
LABEL_11:
          v9 = v8;
          goto LABEL_12;
        }
        goto LABEL_13;
      }
LABEL_10:
      v9 = -1;
LABEL_12:
      GASValue::DropRefs(this: a4, a2: v9);
      *((_BYTE *)a4 + 4) = v9 == 1;
      *(_BYTE *)a4 = 2;
      return 1;
    }
    if ( GASString::operator==(this: name, a2: "alwaysEnableArrowKeys") )
    {
      v10 = *((_BYTE *)MovieRoot + 9335) & 3;
      if ( v10 != 3 )
      {
        if ( (*((_BYTE *)MovieRoot + 9335) & 3) != 0 )
        {
LABEL_19:
          v11 = v10;
          goto LABEL_25;
        }
LABEL_13:
        GASValue::DropRefs(this: a4, a2: (int)name);
        *(_BYTE *)a4 = 0;
        return 1;
      }
      goto LABEL_18;
    }
    if ( GASString::operator==(this: name, a2: "alwaysEnableKeyboardPress") )
    {
      v12 = (*((_DWORD *)MovieRoot + 2333) >> 26) & 3;
      if ( v12 == 3 )
      {
        v11 = -1;
        goto LABEL_25;
      }
      if ( v12 != 0 )
      {
        v11 = (*((_DWORD *)MovieRoot + 2333) >> 26) & 3;
        goto LABEL_25;
      }
      goto LABEL_13;
    }
    if ( GASString::operator==(this: name, a2: "disableFocusRolloverEvent") )
    {
      v8 = (*((_DWORD *)MovieRoot + 2333) >> 28) & 3;
      if ( v8 == 3 )
        goto LABEL_10;
      if ( v8 != 0 )
        goto LABEL_11;
      goto LABEL_13;
    }
    if ( GASString::operator==(this: name, a2: "disableFocusKeys") )
    {
      v10 = *((_DWORD *)MovieRoot + 2333) >> 30;
      if ( v10 != 3 )
      {
        if ( v10 != 0 )
          goto LABEL_19;
        goto LABEL_13;
      }
LABEL_18:
      v11 = -1;
LABEL_25:
      GASValue::DropRefs(this: a4, a2: v11);
      *(_BYTE *)a4 = 2;
      *((_BYTE *)a4 + 4) = v11 == 1;
      return 1;
    }
    if ( GASString::operator==(this: name, a2: "modalClip") )
    {
      ModalClip = (tagBITMAPCOREHEADER *)GFxMovieRoot::GetModalClip(this: (GFxMovieRoot *)MovieRoot, a2: 0);
      GASValue::SetAsCharacter(this: (int)a4, result: ModalClip);
      return 1;
    }
    if ( GASString::operator==(this: name, a2: "moveFocus") )
    {
      v6 = (tagWNDCLASSW *)GASValue::GASValue(
                             this: v15,
                             (int)func,
                             a3: (void (__cdecl *)(const struct GASFnCall *))GASSelectionCtorFunction::MoveFocus);
      goto LABEL_4;
    }
    if ( GASString::operator==(this: name, a2: "findFocus") )
    {
      v6 = (tagWNDCLASSW *)GASValue::GASValue(
                             this: v15,
                             (int)func,
                             a3: (void (__cdecl *)(const struct GASFnCall *))GASSelectionCtorFunction::FindFocus);
      goto LABEL_4;
    }
    if ( GASString::operator==(this: name, a2: "setModalClip") )
    {
      v6 = (tagWNDCLASSW *)GASValue::GASValue(
                             this: v15,
                             (int)func,
                             a3: (void (__cdecl *)(const struct GASFnCall *))GASSelectionCtorFunction::SetModalClip);
      goto LABEL_4;
    }
    if ( GASString::operator==(this: name, a2: "getModalClip") )
    {
      v6 = (tagWNDCLASSW *)GASValue::GASValue(
                             this: v15,
                             (int)func,
                             a3: (void (__cdecl *)(const struct GASFnCall *))GASSelectionCtorFunction::GetModalClip);
      goto LABEL_4;
    }
    if ( GASString::operator==(this: name, a2: "setControllerFocusGroup") )
    {
      v6 = (tagWNDCLASSW *)GASValue::GASValue(
                             this: v15,
                             (int)func,
                             a3: (void (__cdecl *)(const struct GASFnCall *))GASSelectionCtorFunction::SetControllerFocusGroup);
      goto LABEL_4;
    }
    if ( GASString::operator==(this: name, a2: "getControllerFocusGroup") )
    {
      v6 = (tagWNDCLASSW *)GASValue::GASValue(
                             this: v15,
                             (int)func,
                             a3: (void (__cdecl *)(const struct GASFnCall *))GASSelectionCtorFunction::GetControllerFocusGroup);
      goto LABEL_4;
    }
    if ( GASString::operator==(this: name, a2: "getFocusBitmask") )
    {
      v6 = (tagWNDCLASSW *)GASValue::GASValue(
                             this: v15,
                             (int)func,
                             a3: (void (__cdecl *)(const struct GASFnCall *))GASSelectionCtorFunction::GetFocusBitmask);
      goto LABEL_4;
    }
    if ( GASString::operator==(this: name, a2: "numFocusGroups") )
    {
      v14 = *((CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)MovieRoot + 2556);
      LOBYTE(v15[0]) = 4;
      v15[1] = v14;
      GASValue::operator=(this: (int)a4, v: (tagWNDCLASSW *)v15);
      goto LABEL_5;
    }
    if ( GASString::operator==(this: name, a2: "getControllerMaskByFocusGroup") )
    {
      v6 = (tagWNDCLASSW *)GASValue::GASValue(
                             this: v15,
                             (int)func,
                             a3: (void (__cdecl *)(const struct GASFnCall *))GASSelectionCtorFunction::GetControllerMaskByFocusGroup);
      goto LABEL_4;
    }
    if ( GASString::operator==(this: name, a2: "getFocusArray") )
    {
      v6 = (tagWNDCLASSW *)GASValue::GASValue(
                             this: v15,
                             (int)func,
                             a3: (void (__cdecl *)(const struct GASFnCall *))GASSelectionCtorFunction::GetFocusArray);
      goto LABEL_4;
    }
    v4 = (ID3DXFont *)a2;
  }
  return (unsigned __int8)GASObject::GetMember(this: v16, result: v4, penv: (_IMAGE_SYMBOL_EX *)name, val: (int *)a4);
}

//------------------------------------------------------------------------------
// Address: 0x10116F10
// Name: public: static class GASFunctionRef GASSelectionCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
const GArrayBase<GArrayData<GPtr<GFxAmpMemItem>,GAllocatorLH<GPtr<GFxAmpMemItem>,2>,GArrayDefaultPolicy> > *__thiscall GASSelectionCtorFunction::Register(
        const GArrayBase<GArrayData<GPtr<GFxAmpMemItem>,GAllocatorLH<GPtr<GFxAmpMemItem>,2>,GArrayDefaultPolicy> > *pgc,
        int constructor,
        _KCRM_MARSHAL_HEADER *pgca)
{
  vc_attributes::PreRangeAttribute *v3; // edi
  unsigned int VersionMajor; // ecx
  int (__thiscall *v5)(unsigned int, int, _KCRM_MARSHAL_HEADER **); // eax
  GASCFunctionObject *v6; // eax
  GASCFunctionObject *v7; // ebx
  void *v8; // ecx
  GASCFunctionObject *v9; // eax
  unsigned int v10; // ebx
  const char *MaxVal; // ecx
  int (__thiscall *v12)(const char *, int, int *); // edx
  unsigned int v13; // ecx
  int v14; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GASValue *v16; // eax
  int p_MaxVal; // edi
  tagMSG v19; // [esp-8h] [ebp-34h] BYREF
  struct GASObjectInterface *v20; // [esp+14h] [ebp-18h]
  _KCRM_MARSHAL_HEADER *psc; // [esp+1Ch] [ebp-10h] BYREF
  char v22; // [esp+20h] [ebp-Ch]
  void (__thiscall **v23)(_DWORD *, _KCRM_MARSHAL_HEADER **, int, GASValue *, char *); // [esp+24h] [ebp-8h]
  _DWORD *v24; // [esp+28h] [ebp-4h]

  v3 = (vc_attributes::PreRangeAttribute *)pgca;
  VersionMajor = pgca[41].VersionMajor;
  psc = pgca;
  v22 = 8;
  v5 = *(int (__thiscall **)(unsigned int, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)VersionMajor + 40);
  pgca = (_KCRM_MARSHAL_HEADER *)323;
  v6 = (GASCFunctionObject *)v5(a1: VersionMajor, a2: 56, a3: &pgca);
  v7 = v6;
  if ( v6 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v6,
      func: (_REASON_CONTEXT *)&psc,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASMouseCtorFunction::GlobalCtor);
    v19.message = (unsigned int)&v7->cLineHeight;
    v19.hwnd = (HWND__ *)&psc;
    v7->dwSize = (unsigned int)&GASSelectionCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v7->cLineHeight = (unsigned int)&GASSelectionCtorFunction::`vftable'{for `GASObjectInterface'};
    GASAsBroadcaster::Initialize(pobj: v19, a2: v20);
    GASNameFunction::AddConstMembers(
      pobj: v8,
      psc: (int)&v7->cLineHeight,
      psca: (CTSQueue<CFunctor *,0,1>::Node_t *)&psc,
      a4: (struct GASObject **)&GASSelectionCtorFunction::StaticFunctionTable,
      a5: 7);
    v9 = v7;
  }
  else
  {
    v9 = nullptr;
  }
  v10 = constructor;
  *(_DWORD *)constructor = v9;
  *(_BYTE *)(v10 + 8) = 0;
  *(_DWORD *)(v10 + 4) = 0;
  MaxVal = v3[54].MaxVal;
  v12 = *(int (__thiscall **)(const char *, int, int *))(*(_DWORD *)MaxVal + 40);
  constructor = 323;
  v14 = v12(a1: MaxVal, a2: 84, a3: &constructor);
  if ( v14 != 0 )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v3,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASIme,GASEnvironment>::GASPrototype<GASIme,GASEnvironment>(
      this: (D3DXCOLOR *)v14,
      (struct GASStringContext *)&psc,
      pprototype: Prototype,
      constructor: v10,
      psc_12: *(float *)&v19.wParam);
    v19.message = (unsigned int)&pgca + 3;
    *(_DWORD *)v14 = &GASObjectProto::`vftable'{for `GASRefCountBase<GASObject>'};
    *(_DWORD *)(v14 + 16) = &GASPrototype<GASMouse,GASEnvironment>::`vftable'{for `GASObjectInterface'};
    *(_DWORD *)(v14 + 52) = &GASPrototype<GASObject,GASEnvironment>::`vftable';
    HIBYTE(pgca) = 1;
    GASPrototypeBase::InitFunctionMembers(
      this: (GASPrototypeBase *)(v14 + 52),
      a2: v14,
      flags: (vc_attributes::PreRangeAttribute **)&psc,
      flags_4: (const struct GASNameFunction *)&GAS_SelectionFunctionTable,
      flags_8: (const struct GASPropFlags *)v19.message);
  }
  else
  {
    v14 = 0;
  }
  v19.message = v13;
  if ( v14 != 0 )
    *(_DWORD *)(v14 + 8) = (*(_DWORD *)(v14 + 8) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v3, a2: (int)v3, a3: 21, a4: v14);
  v24 = v3[56].MaxVal + 16;
  HIBYTE(pgca) = 0;
  v23 = (void (__thiscall **)(_DWORD *, _KCRM_MARSHAL_HEADER **, int, GASValue *, char *))(*v24 + 40);
  v16 = GASValue::GASValue(this: (GASValue *)&v19.pt, a2: (int)v3, a3: (const struct GASFunctionRef *)v10);
  p_MaxVal = (int)&v3[7].MaxVal;
  (*v23)(a1: v24, a2: &psc, a3: p_MaxVal, a4: v16, a5: (char *)&pgca + 3);
  GASValue::~GASValue(this: (GASValue *)&v19.pt, a2: p_MaxVal);
  if ( v14 != 0 )
    GRefCountBaseGC<323>::Release(a1: v14, a2: p_MaxVal);
  return (const GArrayBase<GArrayData<GPtr<GFxAmpMemItem>,GAllocatorLH<GPtr<GFxAmpMemItem>,2>,GArrayDefaultPolicy> > *)v10;
}
