// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxaudio/gassoundobject.cpp
// Functions: 14
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxaudio\gassoundobject.h"

//------------------------------------------------------------------------------
// Address: 0x10113D10
// Name: public: static void GASSoundProto::GetTransform(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASSoundProto::GetTransform(int a1@<edi>, const IUnknown *result)
{
  IUnknown_vtbl *v2; // esi

  v2 = result[1].__vftable;
  GASValue::DropRefs(this: (GASValue *)v2, a2: a1);
  LOBYTE(v2->QueryInterface) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013DDD0
// Name: public: class GFxSprite __near * GASSoundObject::GetSprite(void)
// Source: json
//------------------------------------------------------------------------------
_TAPE_WMI_OPERATIONS *__thiscall GASSoundObject::GetSprite(GASSoundObject *this)
{
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v2; // ecx
  GFxMovieRoot *v4; // eax
  int v5; // eax

  v2 = *((CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)this
       + 15);
  if ( v2 != nullptr
    && (v4 = *((GFxMovieRoot **)this + 16)) != nullptr
    && (GFxCharacterHandle::ResolveCharacter(this: v2, a2: v4), v5 != 0) )
  {
    return GASObjectInterface::ToSprite(this: (char *)(v5 + 120));
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013DE00
// Name: public: static void GASSoundProto::Start(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASSoundProto::Start(long double a1@<st0>, GASEnvironment **a2)
{
  struct GFxMovieRoot *MovieRoot; // eax
  IShaderAPI *v4; // ebx
  int v5; // edi
  GASEnvironment *v6; // ebx
  GASSoundObject *v7; // ebx
  GASValue *v8; // eax
  GASValue *v9; // eax
  int v10; // edi
  int v11; // eax
  _TAPE_WMI_OPERATIONS *v12; // esi
  unsigned int Method; // edi
  unsigned int v14; // edi
  float v15; // [esp+18h] [ebp-1Ch]
  _SERVICE_STATUS *v16; // [esp+1Ch] [ebp-18h]
  _SERVICE_STATUS *v17; // [esp+1Ch] [ebp-18h]
  float RealSoundVolume; // [esp+1Ch] [ebp-18h]
  float RealSoundPan; // [esp+1Ch] [ebp-18h]
  int v20; // [esp+2Ch] [ebp-8h]
  int v21; // [esp+30h] [ebp-4h]
  _TAPE_WMI_OPERATIONS *Sprite; // [esp+3Ch] [ebp+8h]

  MovieRoot = GASEnvironment::GetMovieRoot(this: a2[6]);
  if ( MovieRoot != nullptr )
  {
    v4 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*((_DWORD *)MovieRoot + 2) + 12))(
                         a1: (int)MovieRoot + 8,
                         a2: 34);
    if ( v4 != nullptr )
    {
      v5 = ((int (__thiscall *)(IShaderAPI *))v4->GetLightmapDimensions)(a1: v4);
      v20 = v5;
      GRefCountImpl::Release(this: v4);
      if ( v5 != 0 && a2[2] != nullptr && (*(int (__thiscall **)(GASEnvironment *))(*a2[2] + 8))(a1: a2[2]) == 32 )
      {
        v6 = a2[2];
        if ( v6 != nullptr )
        {
          v7 = (GASSoundObject *)(v6 - 4);
          if ( v7 != nullptr )
          {
            Sprite = GASSoundObject::GetSprite(this: v7);
            if ( Sprite != nullptr )
            {
              v21 = 0;
              if ( (int)a2[7] > 0 )
              {
                v16 = (_SERVICE_STATUS *)a2[6];
                v8 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)a2, a2: 0);
                v21 = GASValue::ToInt32(this: v8, a2: v5, a3: a1, a4: v16);
              }
              if ( (int)a2[7] <= 1
                || (v17 = (_SERVICE_STATUS *)a2[6],
                    v9 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)a2, a2: 1),
                    (v10 = GASValue::ToInt32(this: v9, a2: v5, a3: a1, a4: v17)) == 0) )
              {
                v10 = 1;
              }
              if ( *((_DWORD *)v7 + 14) != 0 || !GFxSprite::IsSoundPlaying(this: Sprite, result: (const GFxValue *)v7) )
              {
                v11 = (*(int (__thiscall **)(int, _DWORD, int))(*(_DWORD *)v20 + 20))(
                        a1: v20,
                        a2: *((_DWORD *)v7 + 13),
                        a3: 1);
                v12 = (_TAPE_WMI_OPERATIONS *)v11;
                if ( v11 != 0 )
                {
                  if ( v21 > 0 || v10 > 0 )
                  {
                    v15 = (float)v21;
                    (*(void (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v11 + 32))(
                      a1: v11,
                      a2: v10,
                      a3: LODWORD(v15),
                      a4: 0.0);
                  }
                  Method = v12->Method;
                  RealSoundVolume = GFxSprite::GetRealSoundVolume(this: (GFxValue *)Sprite, a2: v12);
                  (*(void (__thiscall **)(_TAPE_WMI_OPERATIONS *, _DWORD))(Method + 40))(
                    a1: v12,
                    a2: LODWORD(RealSoundVolume));
                  v14 = v12->Method;
                  RealSoundPan = GFxSprite::GetRealSoundPan(this: (GFxValue *)Sprite, a2: v12);
                  (*(void (__thiscall **)(_TAPE_WMI_OPERATIONS *, _DWORD))(v14 + 48))(
                    a1: v12,
                    a2: LODWORD(RealSoundPan));
                  (*(void (__thiscall **)(_TAPE_WMI_OPERATIONS *, _DWORD))(v12->Method + 16))(a1: v12, a2: 0);
                  GFxSprite::AddActiveSound(
                    this: (GFxValue *)Sprite,
                    a2: (IShaderDevice *)v12,
                    a3: (int)v7,
                    a4: *((_DWORD *)v7 + 14));
                  GRefCountImpl::Release(this: (IShaderAPI *)v12);
                }
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013DF80
// Name: public: static void GASSoundProto::Stop(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASSoundProto::Stop(GASFnCall *a1)
{
  GASFnCall *v1; // esi
  GASFnCall v2; // eax
  int *p_cxItem; // eax
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v4; // ecx
  GFxMovieRoot *v5; // eax
  int v6; // eax
  _TAPE_WMI_OPERATIONS *v7; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v8; // edi
  unsigned __int8 *v9; // eax
  GASFnCall v10; // eax
  const MorphWeight_t *v11; // ebx
  IShaderDevice *v12; // eax
  IShaderDevice *v13; // edi
  GFxMovieRoot *MovieRoot; // eax
  IShaderDevice *v15; // ecx
  const struct GASFnCall *v16; // eax
  bool v17; // zf
  const struct GASFnCall *v18; // eax
  IShaderDevice *v19[2]; // [esp+4h] [ebp-10h] BYREF
  GFxValue *v20; // [esp+Ch] [ebp-8h]
  GString v21; // [esp+10h] [ebp-4h] BYREF

  v1 = a1;
  v2 = a1[2];
  if ( v2 == nullptr )
    return;
  p_cxItem = &v2[-1].cxItem;
  if ( p_cxItem == nullptr )
    return;
  v4 = (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)p_cxItem[15];
  if ( v4 == nullptr )
    return;
  v5 = (GFxMovieRoot *)p_cxItem[16];
  if ( v5 == nullptr )
    return;
  GFxCharacterHandle::ResolveCharacter(this: v4, a2: v5);
  if ( v6 == 0 )
    return;
  v7 = GASObjectInterface::ToSprite(this: (char *)(v6 + 120));
  v20 = (GFxValue *)v7;
  if ( v7 == nullptr )
    return;
  if ( (int)v1[7] <= 0 )
  {
    GFxSprite::StopActiveSounds(this: (GFxFontLib *)v7);
    return;
  }
  v8 = (tagRID_DEVICE_INFO_KEYBOARD *)v1[6];
  v9 = (unsigned __int8 *)GASFnCall::Arg(this: v1, a2: 0);
  GASValue::ToStringImpl(this: v9, a2: (int *)&a1, a3: v8, precision: -1, debug: false);
  v10 = v1[2];
  if ( v10 != nullptr )
    v11 = (const MorphWeight_t *)&v10[-1].cxItem;
  else
    v11 = nullptr;
  v12 = (IShaderDevice *)(*(int (__thiscall **)(int))(*(_DWORD *)v1[6][2].ptStart.y + 92))(a1: v1[6][2].ptStart.y);
  v13 = v12;
  if ( v12 != nullptr )
    GRefCountImpl::AddRef(this: v12);
  if ( v11 == nullptr )
  {
LABEL_26:
    if ( v13 != nullptr )
      GFxResource::Release(this: v13);
    goto LABEL_28;
  }
  if ( v13 != nullptr )
  {
    v19[0] = nullptr;
    v19[1] = nullptr;
    GString::GString(this: &v21, src: (int)*a1);
    MovieRoot = (GFxMovieRoot *)GASEnvironment::GetMovieRoot(this: (GASEnvironment *)v1[6]);
    LOBYTE(v11) = GFxMovieRoot::FindExportedResource(
                    this: MovieRoot,
                    a2: (struct GFxMovieDefImpl *)v13,
                    result: (CMatQueuedIndexBuffer *)v19,
                    a4: &v21) == 0;
    GString::~GString(this: &v21);
    v15 = v19[0];
    if ( (_BYTE)v11 != 0 )
    {
LABEL_18:
      if ( v15 != nullptr )
        GFxResource::Release(this: v15);
      GFxResource::Release(this: v13);
      v16 = (const struct GASFnCall *)a1;
      v17 = a1[2] == (GASFnCall)1;
      a1[2] = (GASFnCall)((char *)a1[2] - 1);
      if ( v17 )
        GASStringNode::ReleaseNode(a1: (int)v16);
      return;
    }
    if ( (v19[0]->GetBackBufferFormat(this: v19[0]) & 0xFF00) != 0x400 )
    {
      v15 = v19[0];
      goto LABEL_18;
    }
    if ( v19[0] != nullptr )
    {
      GFxSprite::StopActiveSounds(this: v20, a2: v11, pres: (wchar_t *)v19[0]);
      if ( v19[0] != nullptr )
        GFxResource::Release(this: v19[0]);
    }
    goto LABEL_26;
  }
LABEL_28:
  v18 = (const struct GASFnCall *)a1;
  v17 = a1[2] == (GASFnCall)1;
  a1[2] = (GASFnCall)((char *)a1[2] - 1);
  if ( v17 )
    GASStringNode::ReleaseNode(a1: (int)v18);
}

//------------------------------------------------------------------------------
// Address: 0x1013E100
// Name: public: static void GASSoundProto::GetBytesLoaded(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASSoundProto::GetBytesLoaded(const struct GASFnCall *a1)
{
  GASValue *v1; // esi
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // esi
  int v6; // ebx

  v1 = *((GASValue **)a1 + 1);
  GASValue::DropRefs(this: v1, a2: (int)a1);
  *(_BYTE *)v1 = 0;
  v2 = *((_DWORD *)a1 + 2);
  if ( v2 != 0 )
  {
    v3 = v2 - 16;
    if ( v3 != 0 && *(_DWORD *)(v3 + 56) == 0 )
    {
      v4 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v3 + 52) + 20))(a1: *(_DWORD *)(v3 + 52));
      v5 = *((_DWORD *)a1 + 1);
      v6 = v4;
      if ( *(_BYTE *)v5 >= 5u )
        GASValue::DropRefs(this: *((GASValue **)a1 + 1), a2: (int)a1);
      *(_DWORD *)(v5 + 4) = v6;
      *(_BYTE *)v5 = 4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013E150
// Name: public: static void GASSoundProto::GetBytesTotal(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASSoundProto::GetBytesTotal(const struct GASFnCall *a1)
{
  GASValue *v1; // esi
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // esi
  int v6; // ebx

  v1 = *((GASValue **)a1 + 1);
  GASValue::DropRefs(this: v1, a2: (int)a1);
  *(_BYTE *)v1 = 0;
  v2 = *((_DWORD *)a1 + 2);
  if ( v2 != 0 )
  {
    v3 = v2 - 16;
    if ( v3 != 0 && *(_DWORD *)(v3 + 56) == 0 )
    {
      v4 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v3 + 52) + 16))(a1: *(_DWORD *)(v3 + 52));
      v5 = *((_DWORD *)a1 + 1);
      v6 = v4;
      if ( *(_BYTE *)v5 >= 5u )
        GASValue::DropRefs(this: *((GASValue **)a1 + 1), a2: (int)a1);
      *(_DWORD *)(v5 + 4) = v6;
      *(_BYTE *)v5 = 4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013E1A0
// Name: public: static void GASSoundProto::GetPan(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASSoundProto::GetPan(const struct GASFnCall *a1)
{
  int v1; // eax
  int v2; // eax
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v3; // ecx
  GFxMovieRoot *v4; // eax
  int v5; // eax
  _TAPE_WMI_OPERATIONS *v6; // eax
  GPtr<GFxZlibSupportBase> *SoundPan; // eax
  int v8; // esi
  GPtr<GFxZlibSupportBase> *v9; // edi

  v1 = *((_DWORD *)a1 + 2);
  if ( v1 != 0 )
  {
    v2 = v1 - 16;
    if ( v2 != 0 )
    {
      v3 = *(CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(v2 + 60);
      if ( v3 != nullptr )
      {
        v4 = *(GFxMovieRoot **)(v2 + 64);
        if ( v4 != nullptr )
        {
          GFxCharacterHandle::ResolveCharacter(this: v3, a2: v4);
          if ( v5 != 0 )
          {
            v6 = GASObjectInterface::ToSprite(this: (char *)(v5 + 120));
            if ( v6 != nullptr )
            {
              SoundPan = GFxSprite::GetSoundPan(this: (GPtr<GFxZlibSupportBase> *)v6);
              v8 = *((_DWORD *)a1 + 1);
              v9 = SoundPan;
              if ( *(_BYTE *)v8 >= 5u )
                GASValue::DropRefs(this: (GASValue *)v8, a2: (int)SoundPan);
              *(_DWORD *)(v8 + 4) = v9;
              *(_BYTE *)v8 = 4;
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013E200
// Name: public: static void GASSoundProto::GetVolume(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASSoundProto::GetVolume(const struct GASFnCall *a1)
{
  int v1; // eax
  int v2; // esi
  GASValue *v3; // edi
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v4; // ecx
  GFxMovieRoot *v5; // esi
  int v6; // eax
  _TAPE_WMI_OPERATIONS *v7; // eax
  int SoundVolume; // eax
  int v9; // esi
  int v10; // edi

  v1 = *((_DWORD *)a1 + 2);
  if ( v1 != 0 )
    v2 = v1 - 16;
  else
    v2 = 0;
  v3 = *((GASValue **)a1 + 1);
  GASValue::DropRefs(this: v3, a2: (int)v3);
  *(_BYTE *)v3 = 0;
  if ( v2 != 0 )
  {
    v4 = *(CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(v2 + 60);
    if ( v4 != nullptr )
    {
      v5 = *(GFxMovieRoot **)(v2 + 64);
      if ( v5 != nullptr )
      {
        GFxCharacterHandle::ResolveCharacter(this: v4, a2: v5);
        if ( v6 != 0 )
        {
          v7 = GASObjectInterface::ToSprite(this: (char *)(v6 + 120));
          if ( v7 != nullptr )
          {
            SoundVolume = GFxSprite::GetSoundVolume(this: (GPtr<GFxZlibSupportBase> *)v7);
            v9 = *((_DWORD *)a1 + 1);
            v10 = SoundVolume;
            if ( *(_BYTE *)v9 >= 5u )
              GASValue::DropRefs(this: *((GASValue **)a1 + 1), a2: SoundVolume);
            *(_BYTE *)v9 = 4;
            *(_DWORD *)(v9 + 4) = v10;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013E270
// Name: public: static void GASSoundProto::SetPan(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASSoundProto::SetPan(int a1@<edi>, long double a2@<st0>, GASFnCall *a3)
{
  GASValue *v3; // eax
  int v4; // eax
  GASFnCall v5; // esi
  const GFxZlibSupportBase *v6; // edi
  int *p_cxItem; // eax
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v8; // ecx
  GFxMovieRoot *v9; // eax
  int v10; // eax
  _TAPE_WMI_OPERATIONS *v11; // eax
  _SERVICE_STATUS *v12; // [esp-8h] [ebp-Ch]

  if ( (int)a3[7] >= 1 )
  {
    v12 = (_SERVICE_STATUS *)a3[6];
    v3 = (GASValue *)GASFnCall::Arg(this: a3, a2: 0);
    v4 = GASValue::ToInt32(this: v3, a2: a1, a3: a2, a4: v12);
    v5 = a3[2];
    v6 = (const GFxZlibSupportBase *)v4;
    if ( v5 != nullptr )
    {
      p_cxItem = &v5[-1].cxItem;
      if ( v5 != (GASFnCall)16 )
      {
        v8 = (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)p_cxItem[15];
        if ( v8 != nullptr )
        {
          v9 = (GFxMovieRoot *)p_cxItem[16];
          if ( v9 != nullptr )
          {
            GFxCharacterHandle::ResolveCharacter(this: v8, a2: v9);
            if ( v10 != 0 )
            {
              v11 = GASObjectInterface::ToSprite(this: (char *)(v10 + 120));
              if ( v11 != nullptr )
                GFxSprite::SetSoundPan(this: (int)v11, result: v6);
            }
          }
        }
      }
    }
  }
  else
  {
    GASEnvironment::LogScriptError(this: (GASEnvironment *)a3[6], a2: "Error: Sound.SetPan needs one Argument\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013E2F0
// Name: public: static void GASSoundProto::SetVolume(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASSoundProto::SetVolume(int a1@<edi>, long double a2@<st0>, const struct GASFnCall *volume)
{
  GASValue *v4; // eax
  long double v5; // st7
  int v6; // ebx
  GASValue *v7; // eax
  int v8; // esi
  int v9; // eax
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v10; // ecx
  GFxMovieRoot *v11; // eax
  int v12; // eax
  _TAPE_WMI_OPERATIONS *v13; // eax
  _SERVICE_STATUS *v14; // [esp-8h] [ebp-Ch]
  _SERVICE_STATUS *v15; // [esp-8h] [ebp-Ch]
  int volumea; // [esp+Ch] [ebp+8h]

  if ( *((int *)volume + 7) >= 1 )
  {
    v14 = *((_SERVICE_STATUS **)volume + 6);
    v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)volume, a2: 0);
    volumea = GASValue::ToInt32(this: v4, a2: a1, a3: a2, a4: v14);
    v6 = 100;
    if ( *((int *)volume + 7) > 1 )
    {
      v15 = *((_SERVICE_STATUS **)volume + 6);
      v7 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)volume, a2: 1);
      v6 = GASValue::ToInt32(this: v7, a2: a1, a3: v5, a4: v15);
    }
    v8 = *((_DWORD *)volume + 2);
    if ( v8 != 0 )
    {
      v9 = v8 - 16;
      if ( v8 != 16 )
      {
        v10 = *(CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(v9 + 60);
        if ( v10 != nullptr )
        {
          v11 = *(GFxMovieRoot **)(v9 + 64);
          if ( v11 != nullptr )
          {
            GFxCharacterHandle::ResolveCharacter(this: v10, a2: v11);
            if ( v12 != 0 )
            {
              v13 = GASObjectInterface::ToSprite(this: (char *)(v12 + 120));
              if ( v13 != nullptr )
                GFxSprite::SetSoundVolume(this: (GFxValue *)v13, volume: COERCE_LONG_DOUBLE(__PAIR64__(v6, volumea)));
            }
          }
        }
      }
    }
  }
  else
  {
    GASEnvironment::LogScriptError(
      this: *((GASEnvironment **)volume + 6),
      a2: "Error: Sound.SetVolume needs, at least, one Argument\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013E390
// Name: public: void GASSoundObject::ReleaseTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSoundObject::ReleaseTarget(GASSoundObject *this)
{
  GFxCharacterHandle *v2; // esi

  v2 = *((GFxCharacterHandle **)this + 15);
  if ( v2 != nullptr )
  {
    *v2 = (GFxCharacterHandle)((char *)*v2 - 1);
    if ( (int)*v2 <= 0 )
    {
      GFxCharacterHandle::~GFxCharacterHandle(this: v2);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
    }
  }
  *((_DWORD *)this + 15) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013E3D0
// Name: public: static void GASSoundProto::Attach(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASSoundProto::Attach(GASEnvironment **a1)
{
  GASEnvironment **v1; // esi
  struct GFxMovieRoot *MovieRoot; // eax
  IShaderAPI *v3; // edi
  tagRID_DEVICE_INFO_KEYBOARD *v4; // edi
  unsigned __int8 *v5; // eax
  GASEnvironment *v6; // eax
  IShaderDevice *v7; // eax
  struct GFxMovieDefImpl *v8; // edi
  GFxMovieRoot *v9; // eax
  bool v10; // bl
  IShaderDevice *v11; // ecx
  int v12; // edi
  GASEnvironment *v13; // ebx
  int v14; // esi
  GString::DataDesc *pData; // esi
  IShaderDevice *v16; // ecx
  IShaderDevice *v17; // ecx
  IShaderDevice *v18; // ecx
  const struct GASFnCall *v19; // eax
  bool v20; // zf
  IShaderDevice *v21[2]; // [esp+4h] [ebp-18h] BYREF
  int v22; // [esp+Ch] [ebp-10h]
  IShaderDevice *v23; // [esp+10h] [ebp-Ch]
  GString v24; // [esp+14h] [ebp-8h] BYREF
  GASEnvironment *v25; // [esp+18h] [ebp-4h]

  v1 = a1;
  MovieRoot = GASEnvironment::GetMovieRoot(this: a1[6]);
  if ( MovieRoot != nullptr )
  {
    v3 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*((_DWORD *)MovieRoot + 2) + 12))(
                         a1: (int)MovieRoot + 8,
                         a2: 34);
    if ( v3 != nullptr )
    {
      v22 = ((int (__thiscall *)(IShaderAPI *))v3->GetLightmapDimensions)(a1: v3);
      GRefCountImpl::Release(this: v3);
      if ( v22 != 0 )
      {
        if ( (int)v1[7] < 1 )
        {
          GASEnvironment::LogScriptError(
            this: v1[6],
            a2: "Error: Sound.AttachSound needs one Argument (the file name)\n");
          return;
        }
        v4 = (tagRID_DEVICE_INFO_KEYBOARD *)v1[6];
        v5 = (unsigned __int8 *)GASFnCall::Arg(this: (GASFnCall *)v1, a2: 0);
        GASValue::ToStringImpl(this: v5, a2: (int *)&a1, a3: v4, precision: -1, debug: false);
        v6 = v1[2];
        if ( v6 != nullptr )
          v25 = v6 - 4;
        else
          v25 = nullptr;
        v7 = (IShaderDevice *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v1[6] + 29) + 92))(a1: *((_DWORD *)v1[6] + 29));
        v8 = (struct GFxMovieDefImpl *)v7;
        v23 = v7;
        if ( v7 != nullptr )
          GRefCountImpl::AddRef(this: v7);
        if ( v25 != nullptr )
        {
          if ( v8 == nullptr )
            goto LABEL_32;
          v21[0] = nullptr;
          v21[1] = nullptr;
          GString::GString(this: &v24, src: (int)*a1);
          v9 = (GFxMovieRoot *)GASEnvironment::GetMovieRoot(this: v1[6]);
          v10 = GFxMovieRoot::FindExportedResource(this: v9, a2: v8, result: (CMatQueuedIndexBuffer *)v21, a4: &v24) == 0;
          GString::~GString(this: &v24);
          v11 = v21[0];
          if ( v10 )
          {
            if ( v21[0] == nullptr )
            {
LABEL_31:
              GFxResource::Release(this: (IShaderDevice *)v8);
LABEL_32:
              v19 = (const struct GASFnCall *)a1;
              v20 = a1[2] == (GASEnvironment *)1;
              a1[2] = (GASEnvironment *)((char *)a1[2] - 1);
              if ( v20 )
                GASStringNode::ReleaseNode(a1: (int)v19);
              return;
            }
LABEL_15:
            GFxResource::Release(this: v11);
            goto LABEL_31;
          }
          if ( (v21[0]->GetBackBufferFormat(this: v21[0]) & 0xFF00) != 0x400 )
          {
            v11 = v21[0];
            if ( v21[0] == nullptr )
              goto LABEL_31;
            goto LABEL_15;
          }
          v24.pData = (GString::DataDesc *)v21[0];
          if ( v21[0] != nullptr )
          {
            v12 = (*((int (__thiscall **)(IShaderDevice_vtbl *, int))v21[0][3].ReleaseResources + 3))(
                    a1: v21[0][3].__vftable,
                    a2: v22);
            if ( v12 != 0 )
              InterlockedExchangeAdd(Addend: (volatile LONG *)(v12 + 4), Value: 1);
            v13 = v25;
            v14 = *((_DWORD *)v25 + 13);
            if ( v14 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)(v14 + 4), Value: -1) == 1 )
              (**(void (__thiscall ***)(int, int))v14)(a1: v14, a2: 1);
            pData = v24.pData;
            v16 = (IShaderDevice *)v24.pData;
            *((_DWORD *)v13 + 13) = v12;
            GRefCountImpl::AddRef(this: v16);
            v17 = *((IShaderDevice **)v13 + 14);
            if ( v17 != nullptr )
              GFxResource::Release(this: v17);
            v18 = v21[0];
            *((_DWORD *)v13 + 14) = pData;
            if ( v18 != nullptr )
              GFxResource::Release(this: v18);
            v8 = (struct GFxMovieDefImpl *)v23;
          }
        }
        if ( v8 == nullptr )
          goto LABEL_32;
        goto LABEL_31;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013E5C0
// Name: public: void GASSoundObject::ExecuteOnSoundComplete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSoundObject::ExecuteOnSoundComplete(GASSoundObject *this)
{
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v2; // ecx
  int v3; // eax
  _TAPE_WMI_OPERATIONS *v4; // eax
  _DWORD *v5; // esi
  int (__thiscall *v6)(char *, _DWORD *, struct GASStringNode **, GASValue *); // edx
  char *v7; // edi
  char v8; // bl
  int v9; // eax
  int v11; // eax
  _DWORD v12[3]; // [esp+4h] [ebp-54h] BYREF
  int v13; // [esp+10h] [ebp-48h]
  int v14; // [esp+14h] [ebp-44h]
  char v15; // [esp+18h] [ebp-40h]
  _DWORD *v16; // [esp+1Ch] [ebp-3Ch]
  int v17; // [esp+20h] [ebp-38h]
  int v18; // [esp+24h] [ebp-34h]
  GASValue v19[4]; // [esp+28h] [ebp-30h] BYREF
  GASValue v20[4]; // [esp+38h] [ebp-20h] BYREF
  int v21; // [esp+48h] [ebp-10h] BYREF
  int v22; // [esp+4Ch] [ebp-Ch]
  char v23; // [esp+50h] [ebp-8h]
  struct GASStringNode *ConstStringNode; // [esp+54h] [ebp-4h] BYREF

  v2 = *((CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)this
       + 15);
  if ( v2 != nullptr && *((_DWORD *)this + 16) != 0 )
  {
    GFxCharacterHandle::ResolveCharacter(this: v2, a2: *((GFxMovieRoot **)this + 16));
    if ( v3 != 0 )
    {
      v4 = GASObjectInterface::ToSprite(this: (char *)(v3 + 120));
      if ( v4 != nullptr )
      {
        v5 = (_DWORD *)(*(int (__thiscall **)(_TAPE_WMI_OPERATIONS *))(v4->Method + 112))(a1: v4);
        LOBYTE(v20[0]) = 0;
        ConstStringNode = GASStringManager::CreateConstStringNode(
                            this: *(GASStringManager **)(v5[30] + 636),
                            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A8E54,
                            a3: 0xFu,
                            a4: 0);
        ++*((_DWORD *)ConstStringNode + 2);
        v6 = *(int (__thiscall **)(char *, _DWORD *, struct GASStringNode **, GASValue *))(*((_DWORD *)this + 4) + 44);
        v7 = (char *)this + 16;
        v8 = v6(a1: v7, a2: v5 + 30, a3: &ConstStringNode, a4: v20);
        v9 = (int)ConstStringNode;
        if ( (*((_DWORD *)ConstStringNode + 2))-- == 1 )
          GASStringNode::ReleaseNode(a1: v9);
        if ( v8 != 0 )
        {
          GASValue::ToFunction(a1: (int)v20, a2: (int)v7, a3: (int)&v21, a4: (int)v5);
          v11 = ((v5[2] - v5[3]) >> 4) + 32 * v5[7] - 32;
          v12[2] = v7;
          v7 = nullptr;
          v18 = v11;
          v12[1] = v19;
          LOBYTE(v19[0]) = 0;
          v12[0] = &GASFnCall::`vftable';
          v15 = 0;
          v13 = 0;
          v14 = 0;
          v16 = v5;
          v17 = 0;
          (*(void (__thiscall **)(int, _DWORD *, int, _DWORD))(*(_DWORD *)v21 + 40))(a1: v21, a2: v12, a3: v22, a4: 0);
          v12[0] = &GASFnCall::`vftable';
          if ( (v15 & 2) == 0 && v13 != 0 )
            GRefCountBaseGC<323>::Release(a1: v13, a2: 0);
          v13 = 0;
          if ( (v15 & 1) == 0 && v14 != 0 )
            GRefCountBaseGC<323>::Release(a1: v14, a2: 0);
          GASValue::~GASValue(this: v19, a2: 0);
          if ( (v23 & 2) == 0 && v21 != 0 )
            GRefCountBaseGC<323>::Release(a1: v21, a2: 0);
          v21 = 0;
          if ( (v23 & 1) == 0 && v22 != 0 )
            GRefCountBaseGC<323>::Release(a1: v22, a2: 0);
        }
        GASValue::~GASValue(this: v20, a2: (int)v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013E730
// Name: public: static void GASSoundProto::LoadSound(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASSoundProto::LoadSound(int a1@<ebx>, int a2@<esi>, long double a3@<st0>, GASEnvironment **a4)
{
  const struct GASFnCall *v4; // edi
  struct GFxMovieRoot *MovieRoot; // eax
  IShaderAPI *v6; // ebx
  GASEnvironment *v7; // ebx
  int v8; // ebx
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v9; // ecx
  int v10; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v11; // esi
  unsigned __int8 *v12; // eax
  char *v13; // eax
  GFxLoadStates *v14; // eax
  ScaleformRenderer::FillStyle *pData; // esi
  unsigned int Size; // ecx
  struct GFxStateBag *v17; // ecx
  CImagePacker *v18; // eax
  GString::DataDesc *v19; // esi
  int v20; // ecx
  int (__thiscall *v21)(int, int); // edx
  int v22; // ebx
  GString::DataDesc *v23; // eax
  bool v24; // zf
  __vc_attributes::iid_isAttribute *v25; // esi
  char *v26; // eax
  _DWORD *v27; // eax
  CCountedStringPoolBase<unsigned int>::hash_item_t *v28; // ecx
  IShaderDevice *v29; // ecx
  int v30; // esi
  GString::DataDesc *v31; // ecx
  _TAPE_WMI_OPERATIONS *v32; // esi
  int v33; // edx
  int (__thiscall *v34)(int, int); // edx
  int v35; // ebx
  int v36; // eax
  __vc_attributes::iid_isAttribute *v37; // esi
  char *limited_expression; // esi
  _DWORD *v39; // eax
  CCountedStringPoolBase<unsigned int>::hash_item_t *v40; // ecx
  int v41; // esi
  int v42; // edi
  GString::DataDesc *v43; // esi
  StringPoolCase_t m_caseSensitivity; // eax
  tagPOLYTEXTW *v45; // [esp+24h] [ebp-98h]
  float RealSoundVolume; // [esp+2Ch] [ebp-90h]
  float RealSoundPan; // [esp+2Ch] [ebp-90h]
  GASValue v50[4]; // [esp+34h] [ebp-88h] BYREF
  GASValue v51[4]; // [esp+44h] [ebp-78h] BYREF
  GASValue v52[4]; // [esp+54h] [ebp-68h] BYREF
  int v53; // [esp+64h] [ebp-58h] BYREF
  CCountedStringPoolBase<unsigned int> v54; // [esp+68h] [ebp-54h] BYREF
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > v55; // [esp+9Ch] [ebp-20h] BYREF
  char v56[4]; // [esp+B0h] [ebp-Ch]
  IShaderAPI *States; // [esp+B4h] [ebp-8h] BYREF
  GString v58; // [esp+B8h] [ebp-4h] BYREF
  GASFnCall *v59; // [esp+C4h] [ebp+8h]
  GASFnCall *v60; // [esp+C4h] [ebp+8h]
  char v61; // [esp+C7h] [ebp+Bh]
  char v62; // [esp+C7h] [ebp+Bh]

  v4 = (const struct GASFnCall *)a4;
  MovieRoot = GASEnvironment::GetMovieRoot(this: a4[6]);
  v58.pData = (GString::DataDesc *)MovieRoot;
  if ( MovieRoot != nullptr )
  {
    v6 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*((_DWORD *)MovieRoot + 2) + 12))(
                         a1: (int)MovieRoot + 8,
                         a2: 34);
    if ( v6 != nullptr )
    {
      *(_DWORD *)v56 = ((int (__thiscall *)(IShaderAPI *))v6->GetLightmapDimensions)(a1: v6);
      GRefCountImpl::Release(this: v6);
      if ( *(_DWORD *)v56 != 0 )
      {
        v7 = a4[2];
        v8 = v7 != nullptr ? (int)(v7 - 4) : 0;
        v9 = *(CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(v8 + 60);
        if ( v9 != nullptr && *(_DWORD *)(v8 + 64) != 0 )
        {
          GFxCharacterHandle::ResolveCharacter(this: v9, a2: *(GFxMovieRoot **)(v8 + 64));
          if ( v10 != 0 )
          {
            v54.m_FreeListStart = (unsigned int)GASObjectInterface::ToSprite(this: (char *)(v10 + 120));
            if ( v54.m_FreeListStart != 0 )
            {
              if ( (int)a4[7] >= 1 )
              {
                v11 = (tagRID_DEVICE_INFO_KEYBOARD *)a4[6];
                v12 = (unsigned __int8 *)GASFnCall::Arg(this: (GASFnCall *)a4, a2: 0);
                GASValue::ToStringImpl(
                  this: v12,
                  a2: (int *)&v54.m_caseSensitivity,
                  a3: v11,
                  precision: -1,
                  debug: false);
                LOBYTE(a4) = 0;
                if ( *((int *)v4 + 7) > 1 )
                {
                  v45 = *((tagPOLYTEXTW **)v4 + 6);
                  v13 = (char *)GASFnCall::Arg(this: (GASFnCall *)v4, a2: 1);
                  LOBYTE(a4) = GASValue::ToBool(a1: v13, a2: a3, result: v45);
                }
                States = (IShaderAPI *)2;
                v14 = (GFxLoadStates *)((int (__thiscall *)(GMemoryHeap *, int, IShaderAPI **, int, int))GMemory::pGlobalHeap->Alloc_2)(
                                         a1: GMemory::pGlobalHeap,
                                         a2: 84,
                                         a3: &States,
                                         a4: a2,
                                         a5: a1);
                pData = (ScaleformRenderer::FillStyle *)v58.pData;
                if ( v14 != nullptr )
                {
                  Size = v58.pData[20].Size;
                  if ( Size != 0 )
                    v17 = (struct GFxStateBag *)(Size + 8);
                  else
                    v17 = nullptr;
                  States = (IShaderAPI *)GFxLoadStates::GFxLoadStates(
                                           this: v14,
                                           pimpl: *(IShaderDevice **)(v58.pData[4].RefCount + 20),
                                           psharedState: v17,
                                           pother: nullptr);
                }
                else
                {
                  States = nullptr;
                }
                GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v55);
                GFxMovieRoot::GetLevel0Path(this: pData, a2: &v55);
                v18 = (CImagePacker *)GString::GString(this: &v58, src: *(_DWORD *)v54.m_caseSensitivity);
                v53 = 0;
                GString::GString(this: &v54, result: v18);
                GString::GString(
                  this: (CCountedStringPoolBase<unsigned int> *)&v54.m_HashTable,
                  result: (CImagePacker *)&v55);
                GString::~GString(this: &v58);
                GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v55.m_Memory.m_nAllocationCount);
                GFxLoadStates::BuildURL(
                  a1: (int)States,
                  a2: (int)v4,
                  result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v55.m_Memory.m_nAllocationCount,
                  loc: (int)&v53);
                v19 = (GString::DataDesc *)(*(int (__thiscall **)(_DWORD, unsigned int, GASEnvironment **))(**(_DWORD **)v56 + 8))(
                                             a1: *(_DWORD *)v56,
                                             a2: (v55.m_Memory.m_nAllocationCount & 0xFFFFFFFC) + 8,
                                             a3: a4);
                v58.pData = v19;
                if ( v19 != nullptr )
                {
                  v29 = *(IShaderDevice **)(v8 + 56);
                  if ( v29 != nullptr )
                    GFxResource::Release(this: v29);
                  *(_DWORD *)(v8 + 56) = 0;
                  InterlockedExchangeAdd(Addend: &v19->RefCount, Value: 1);
                  v30 = *(_DWORD *)(v8 + 52);
                  if ( v30 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)(v30 + 4), Value: -1) == 1 )
                    (**(void (__thiscall ***)(int, int))v30)(a1: v30, a2: 1);
                  v31 = v58.pData;
                  *(GString *)(v8 + 52) = v58;
                  if ( (_BYTE)a4 != 0 )
                  {
                    v32 = (_TAPE_WMI_OPERATIONS *)(*(int (__thiscall **)(_DWORD, GString::DataDesc *, int))(**(_DWORD **)v56 + 20))(
                                                    a1: *(_DWORD *)v56,
                                                    a2: v31,
                                                    a3: 1);
                    if ( v32 != nullptr )
                    {
                      v59 = (GASFnCall *)(v32->Method + 40);
                      RealSoundVolume = GFxSprite::GetRealSoundVolume(this: (GFxValue *)v54.m_FreeListStart, a2: v32);
                      ((void (__thiscall *)(_TAPE_WMI_OPERATIONS *, _DWORD))*v59)(a1: v32, a2: LODWORD(RealSoundVolume));
                      v60 = (GASFnCall *)(v32->Method + 48);
                      RealSoundPan = GFxSprite::GetRealSoundPan(this: (GFxValue *)v54.m_FreeListStart, a2: v32);
                      ((void (__thiscall *)(_TAPE_WMI_OPERATIONS *, _DWORD))*v60)(a1: v32, a2: LODWORD(RealSoundPan));
                      (*(void (__thiscall **)(_TAPE_WMI_OPERATIONS *, _DWORD))(v32->Method + 16))(a1: v32, a2: 0);
                      GFxSprite::AddActiveSound(
                        this: (GFxValue *)v54.m_FreeListStart,
                        a2: (IShaderDevice *)v32,
                        a3: v8,
                        a4: *(_DWORD *)(v8 + 56));
                      GRefCountImpl::Release(this: (IShaderAPI *)v32);
                    }
                  }
                  v33 = *((_DWORD *)v4 + 6);
                  LOBYTE(v51[0]) = 0;
                  *(_DWORD *)v56 = GASStringManager::CreateConstStringNode(
                                     this: *(GASStringManager **)(*(_DWORD *)(v33 + 120) + 636),
                                     result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A4098,
                                     a3: 6u,
                                     a4: 0);
                  ++*(_DWORD *)(*(_DWORD *)v56 + 8);
                  v34 = *(int (__thiscall **)(int, int))(*(_DWORD *)(v8 + 16) + 44);
                  v35 = v8 + 16;
                  v62 = v34(a1: v35, a2: *((_DWORD *)v4 + 6) + 120);
                  v36 = *(_DWORD *)v56;
                  v24 = (*(_DWORD *)(*(_DWORD *)v56 + 8))-- == 1;
                  if ( v24 )
                    GASStringNode::ReleaseNode(a1: v36);
                  if ( v62 != 0 )
                  {
                    GASValue::ToFunction(
                      a1: (int)v51,
                      a2: (int)v4,
                      a3: (int)&v55.m_Memory.m_nGrowSize,
                      a4: *((_DWORD *)v4 + 6));
                    v37 = *((__vc_attributes::iid_isAttribute **)v4 + 6);
                    LOBYTE(v52[0]) = 0;
                    v37[2].limited_expression += 16;
                    if ( v37[2].limited_expression >= v37[4].limited_expression )
                      GASPagedStack<GASValue,32>::PushPage(this: v37 + 2);
                    limited_expression = (char *)v37[2].limited_expression;
                    if ( limited_expression != nullptr )
                    {
                      *limited_expression = 2;
                      limited_expression[4] = 1;
                    }
                    v39 = *((_DWORD **)v4 + 6);
                    v40 = (CCountedStringPoolBase<unsigned int>::hash_item_t *)(((v39[2] - v39[3]) >> 4)
                                                                              + 32 * v39[7]
                                                                              - 32);
                    memset(&v54.m_HashTable.m_pElements, 0, 9);
                    v54.m_Elements.m_pElements = v40;
                    v54.m_Elements.m_Memory.m_nGrowSize = (int)v39;
                    v54.m_HashTable.m_Memory.m_nAllocationCount = (int)&GASFnCall::`vftable';
                    v54.m_HashTable.m_Memory.m_nGrowSize = (int)v52;
                    v54.m_HashTable.m_Size = v35;
                    v54.m_Elements.m_Size = 1;
                    (*(void (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v55.m_Memory.m_nGrowSize + 40))(
                      a1: v55.m_Memory.m_nGrowSize,
                      a2: &v54.m_HashTable.m_Memory.m_nAllocationCount,
                      a3: v55.m_Size,
                      a4: 0);
                    GASFnCall::~GASFnCall(this: &v54.m_HashTable.m_Memory.m_nAllocationCount);
                    v41 = *((_DWORD *)v4 + 6);
                    GASValue::~GASValue(this: *(GASValue **)(v41 + 8), a2: (int)v4);
                    *(_DWORD *)(v41 + 8) -= 16;
                    if ( *(_DWORD *)(v41 + 8) < *(_DWORD *)(v41 + 12) )
                      GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)(v41 + 8));
                    GASValue::~GASValue(this: v52, a2: (int)v4);
                    if ( ((int)v55.m_pElements & 2) == 0 && v55.m_Memory.m_nGrowSize != 0 )
                      GRefCountBaseGC<323>::Release(a1: v55.m_Memory.m_nGrowSize, a2: (int)v4);
                    v55.m_Memory.m_nGrowSize = 0;
                    if ( ((int)v55.m_pElements & 1) == 0 && v55.m_Size != 0 )
                      GRefCountBaseGC<323>::Release(a1: v55.m_Size, a2: (int)v4);
                  }
                  v42 = *((_DWORD *)v4 + 6);
                  GASValue::~GASValue(this: *(GASValue **)(v42 + 8), a2: v42);
                  *(_DWORD *)(v42 + 8) -= 16;
                  if ( *(_DWORD *)(v42 + 8) < *(_DWORD *)(v42 + 12) )
                    GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)(v42 + 8));
                  GASValue::~GASValue(this: v51, a2: v42);
                  v43 = v58.pData;
                  if ( InterlockedExchangeAdd(Addend: &v58.pData->RefCount, Value: -1) == 1 )
                    (*(void (__thiscall **)(GString::DataDesc *, int))v43->Size)(a1: v43, a2: 1);
                }
                else
                {
                  v20 = *((_DWORD *)v4 + 6);
                  LOBYTE(v50[0]) = 0;
                  v58.pData = (GString::DataDesc *)GASStringManager::CreateConstStringNode(
                                                     this: *(GASStringManager **)(*(_DWORD *)(v20 + 120) + 636),
                                                     result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A4098,
                                                     a3: 6u,
                                                     a4: 0);
                  ++*(_DWORD *)v58.pData->Data;
                  v21 = *(int (__thiscall **)(int, int))(*(_DWORD *)(v8 + 16) + 44);
                  v22 = v8 + 16;
                  v61 = v21(a1: v22, a2: *((_DWORD *)v4 + 6) + 120);
                  v23 = v58.pData;
                  v24 = (*(_DWORD *)v58.pData->Data)-- == 1;
                  if ( v24 )
                    GASStringNode::ReleaseNode(a1: (int)v23);
                  if ( v61 != 0 )
                  {
                    GASValue::ToFunction(
                      a1: (int)v50,
                      a2: (int)v4,
                      a3: (int)&v55.m_Memory.m_nGrowSize,
                      a4: *((_DWORD *)v4 + 6));
                    v25 = *((__vc_attributes::iid_isAttribute **)v4 + 6);
                    LOBYTE(v52[0]) = 0;
                    v25[2].limited_expression += 16;
                    if ( v25[2].limited_expression >= v25[4].limited_expression )
                      GASPagedStack<GASValue,32>::PushPage(this: v25 + 2);
                    v26 = (char *)v25[2].limited_expression;
                    if ( v26 != nullptr )
                    {
                      *v26 = 2;
                      v26[4] = 0;
                    }
                    v27 = *((_DWORD **)v4 + 6);
                    v28 = (CCountedStringPoolBase<unsigned int>::hash_item_t *)(((v27[2] - v27[3]) >> 4)
                                                                              + 32 * v27[7]
                                                                              - 32);
                    v54.m_HashTable.m_Memory.m_nGrowSize = (int)v52;
                    v54.m_Elements.m_pElements = v28;
                    v54.m_Elements.m_Memory.m_nGrowSize = (int)v27;
                    v54.m_HashTable.m_Memory.m_nAllocationCount = (int)&GASFnCall::`vftable';
                    v54.m_HashTable.m_Size = v22;
                    memset(&v54.m_HashTable.m_pElements, 0, 9);
                    v54.m_Elements.m_Size = 1;
                    (*(void (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v55.m_Memory.m_nGrowSize + 40))(
                      a1: v55.m_Memory.m_nGrowSize,
                      a2: &v54.m_HashTable.m_Memory.m_nAllocationCount,
                      a3: v55.m_Size,
                      a4: 0);
                    GASFnCall::~GASFnCall(this: &v54.m_HashTable.m_Memory.m_nAllocationCount);
                    v4 = *((const struct GASFnCall **)v4 + 6);
                    GASValue::~GASValue(this: *((GASValue **)v4 + 2), a2: (int)v4);
                    *((_DWORD *)v4 + 2) -= 16;
                    if ( *((_DWORD *)v4 + 2) < *((_DWORD *)v4 + 3) )
                      GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)v4 + 2);
                    GASValue::~GASValue(this: v52, a2: (int)v4);
                    if ( ((int)v55.m_pElements & 2) == 0 && v55.m_Memory.m_nGrowSize != 0 )
                      GRefCountBaseGC<323>::Release(a1: v55.m_Memory.m_nGrowSize, a2: (int)v4);
                    v55.m_Memory.m_nGrowSize = 0;
                    if ( ((int)v55.m_pElements & 1) == 0 && v55.m_Size != 0 )
                      GRefCountBaseGC<323>::Release(a1: v55.m_Size, a2: (int)v4);
                  }
                  GASValue::~GASValue(this: v50, a2: (int)v4);
                }
                GString::~GString(this: (GString *)&v55.m_Memory.m_nAllocationCount);
                GFxURLBuilder::LocationInfo::~LocationInfo(this: &v53);
                GString::~GString(this: (GString *)&v55);
                if ( States != nullptr )
                  GRefCountImpl::Release(this: States);
                m_caseSensitivity = v54.m_caseSensitivity;
                v24 = (*(_DWORD *)(v54.m_caseSensitivity + 8))-- == 1;
                if ( v24 )
                  GASStringNode::ReleaseNode(a1: m_caseSensitivity);
              }
              else
              {
                GASEnvironment::LogScriptError(
                  this: a4[6],
                  a2: "Error: Sound.AttachSound needs one Argument (the file name)\n");
              }
            }
          }
        }
      }
    }
  }
}
