// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxfileopener.cpp
// Functions: 3
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxfileopener.h"

//------------------------------------------------------------------------------
// Address: 0x100722F0
// Name: public: virtual class GFile __near * GFxFileOpener::OpenFile(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFileOpener::OpenFile(CMatRenderContextBase *this, Vector *purl, Vector *flags, Vector *modes)
{
  char v4; // bl
  GSysFile *v5; // esi
  void *v6; // esi
  int v7; // [esp+Ch] [ebp-8h] BYREF
  GString v8; // [esp+10h] [ebp-4h] BYREF

  v4 = 0;
  v7 = 2;
  v5 = (GSysFile *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 12, a3: &v7);
  if ( v5 != nullptr )
  {
    GString::GString(this: &v8, a2: (const char *)purl);
    v4 = 1;
    GSysFile::GSysFile(this: v5, a2: &v8, (int)flags, mode: (int)modes);
  }
  if ( (v4 & 1) != 0 )
  {
    v6 = (void *)(v8.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v8.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072380
// Name: public: virtual __int64 GFxFileOpener::GetFileModifyTime(char const __near *)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall GFxFileOpener::GetFileModifyTime(CMatRenderContextBase *this, Vector *result)
{
  bool FileStat; // al
  void *v3; // esi
  bool v4; // bl
  GString v6; // [esp+8h] [ebp-20h] BYREF
  struct GFileStat v7; // [esp+Ch] [ebp-1Ch] BYREF

  GString::GString(this: &v6, a2: (const char *)result);
  FileStat = GSysFile::GetFileStat(a1: &v7, a2: &v6);
  v3 = (void *)(v6.HeapTypeBits & 0xFFFFFFFC);
  v4 = FileStat;
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v6.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
  if ( v4 )
    return v7.ModifyTime;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10072410
// Name: public: virtual class GFile __near * GFxFileOpener::OpenFileEx(char const __near *,class GFxLog __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
IShaderAPI *__thiscall GFxFileOpener::OpenFileEx(
        CMatRenderContextBase *this,
        const char *a2,
        GFxLogBase<GFxLog> *a3,
        int flags,
        int modes)
{
  int v5; // eax
  IShaderAPI *v6; // esi

  v5 = ((int (__thiscall *)(CMatRenderContextBase *, const char *, int, int))this->Release)(
         a1: this,
         a2,
         a3: flags,
         a4: modes);
  v6 = (IShaderAPI *)v5;
  if ( v5 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 32))(a1: v5) == 0 )
    return v6;
  if ( a3 != nullptr )
    GFxLogBase<GFxLog>::LogError(this: a3 + 3, pfmt: "Error: GFxLoader failed to open '%s'\n", a2);
  if ( v6 != nullptr )
    GRefCountImpl::Release(this: v6);
  return nullptr;
}
