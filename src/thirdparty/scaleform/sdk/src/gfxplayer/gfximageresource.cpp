// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfximageresource.cpp
// Functions: 7
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfximageresource.h"

//------------------------------------------------------------------------------
// Address: 0x10157DC0
// Name: public: virtual unsigned int GFxImageFileKeyInterface::GetHashCode(void __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxImageFileKeyInterface::GetHashCode(GFxImageFileKeyInterface *this, void *a2)
{
  unsigned int v2; // ebx
  int v3; // esi
  int v4; // edi

  v2 = *((_DWORD *)a2 + 4);
  v3 = *((_DWORD *)a2 + 2);
  v4 = *((_DWORD *)a2 + 3);
  return v3
       ^ v4
       ^ v2
       ^ ((v3 ^ v4 ^ v2) >> 7)
       ^ GFxResourceFileInfo::GetHashCode(this: *((GFxResourceFileInfo **)a2 + 5));
}

//------------------------------------------------------------------------------
// Address: 0x10157E00
// Name: public: virtual bool GFxImageFileKeyInterface::KeyEquals(void __near *,class GFxResourceKey const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxImageFileKeyInterface::KeyEquals(
        GFxImageFileKeyInterface *this,
        _DWORD *a2,
        const struct GFxResourceKey *a3)
{
  _DWORD *hKeyData; // eax

  if ( this != (GFxImageFileKeyInterface *)a3->pKeyInterface )
    return false;
  hKeyData = a3->hKeyData;
  return a2[2] == hKeyData[2]
      && a2[3] == hKeyData[3]
      && a2[4] == hKeyData[4]
      && GString::operator==(
           this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(a2[5] + 16),
           str: (_DWORD *)(hKeyData[5] + 16));
}

//------------------------------------------------------------------------------
// Address: 0x10157E60
// Name: public: virtual char const __near * GFxImageFileKeyInterface::GetFileURL(void __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall GFxImageFileKeyInterface::GetFileURL(GFxImageFileKeyInterface *this, _DWORD *a2)
{
  return (const char *)((*(_DWORD *)(a2[5] + 16) & 0xFFFFFFFC) + 8);
}

//------------------------------------------------------------------------------
// Address: 0x10157E80
// Name: public: GFxImageFileInfoKeyData::GFxImageFileInfoKeyData(struct GFxImageFileInfo __near *,class GFxFileOpener __near *,class GFxImageCreator __near *,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
GFxImageFileInfoKeyData *__thiscall GFxImageFileInfoKeyData::GFxImageFileInfoKeyData(
        GFxImageFileInfoKeyData *this,
        struct GFxImageFileInfo *a2,
        IShaderDevice *a3,
        IShaderDevice *a4,
        struct GMemoryHeap *a5)
{
  GRefCountNTSImpl *v6; // ecx
  IShaderAPI *v7; // ecx
  IShaderAPI *v8; // ecx

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxImageFileInfoKeyData::`vftable';
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 5) = 0;
  if ( a2 != nullptr )
    ++*((_DWORD *)a2 + 1);
  v6 = *((GRefCountNTSImpl **)this + 5);
  if ( v6 != nullptr )
    GRefCountNTSImpl::Release(this: v6);
  *((_DWORD *)this + 5) = a2;
  if ( a3 != nullptr )
    GRefCountImpl::AddRef(this: a3);
  v7 = *((IShaderAPI **)this + 2);
  if ( v7 != nullptr )
    GRefCountImpl::Release(this: v7);
  *((_DWORD *)this + 2) = a3;
  if ( a4 != nullptr )
    GRefCountImpl::AddRef(this: a4);
  v8 = *((IShaderAPI **)this + 3);
  if ( v8 != nullptr )
    GRefCountImpl::Release(this: v8);
  *((_DWORD *)this + 3) = a4;
  *((_DWORD *)this + 4) = a5;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10157F70
// Name: public: static class GFxResourceKey GFxImageResource::CreateImageFileKey(struct GFxImageFileInfo __near *,class GFxFileOpener __near *,class GFxImageCreator __near *,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
static GFxResourceKey *__cdecl GFxImageResource::CreateImageFileKey(
        GFxResourceKey *a1,
        struct GFxFileOpener *a2,
        IShaderDevice *a3,
        IShaderDevice *a4,
        struct GMemoryHeap *a5)
{
  struct GMemoryHeap *v5; // esi
  struct GMemoryHeap *v6; // ecx
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // eax
  GFxImageFileInfoKeyData *v8; // eax
  IShaderAPI *v9; // esi

  v5 = a5;
  v6 = a5;
  if ( a5 == nullptr )
    v6 = GMemory::pGlobalHeap;
  Alloc_2 = v6->Alloc_2;
  a5 = (struct GMemoryHeap *)2;
  v8 = (GFxImageFileInfoKeyData *)Alloc_2(this: v6, a2: 24u, a3: (const GAllocDebugInfo *)&a5);
  if ( v8 != nullptr )
    v9 = (IShaderAPI *)GFxImageFileInfoKeyData::GFxImageFileInfoKeyData(
                         this: v8,
                         (struct GFxImageFileInfo *)a2,
                         a3,
                         a4,
                         a5: v5);
  else
    v9 = nullptr;
  GFxResourceKey::GFxResourceKey(this: a1, a2: &GFxImageFileKeyInterface_Instance, a3: v9);
  if ( v9 != nullptr )
    GRefCountImpl::Release(this: v9);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x1028BDC0
// Name: _dynamic_initializer_for__GFxImageFileKeyInterface_Instance__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__GFxImageFileKeyInterface_Instance__()
{
  return atexit(func: (void (__cdecl *)())dynamic_atexit_destructor_for__GFxImageFileKeyInterface_Instance__);
}

//------------------------------------------------------------------------------
// Address: 0x1028CC30
// Name: _dynamic_atexit_destructor_for__GFxImageFileKeyInterface_Instance__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__GFxImageFileKeyInterface_Instance__()
{
  GFxImageFileKeyInterface_Instance.__vftable = (GFxResourceKey::KeyInterface_vtbl *)&GFxResourceKey::KeyInterface::`vftable';
}
