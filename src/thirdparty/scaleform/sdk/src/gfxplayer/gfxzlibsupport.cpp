// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxzlibsupport.cpp
// Functions: 2
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxzlibsupport.h"

//------------------------------------------------------------------------------
// Address: 0x10072100
// Name: public: virtual class GFile __near * GFxZlibSupport::CreateZlibFile(class GFile __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxZlibSupport::CreateZlibFile(GFxZlibSupport *this, studiohwdata_t **psourceFile)
{
  studiohwdata_t *const *v2; // eax
  int v4; // [esp+4h] [ebp-4h] BYREF

  v4 = 2;
  v2 = (studiohwdata_t *const *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                  this: GMemory::pGlobalHeap,
                                  a2: this,
                                  a3: 12,
                                  a4: &v4);
  return v2 != nullptr && GZLibFile::GZLibFile(this: v2, psourceFile);
}

//------------------------------------------------------------------------------
// Address: 0x10072170
// Name: public: virtual void GFxZlibSupport::InflateWrapper(class GFxStream __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
ITexture *__stdcall GFxZlibSupport::InflateWrapper(GFxStream *a1, void *buffer, int bufferBytes)
{
  mstudioaimconstraint_t *inited; // eax
  ITexture *result; // eax
  int v5; // eax
  int v6; // [esp+0h] [ebp-60h]
  int D_stream; // [esp+4h] [ebp-5Ch] BYREF
  int v8; // [esp+8h] [ebp-58h]
  unsigned __int8 pdestBuf[32]; // [esp+3Ch] [ebp-24h] BYREF

  inited = GZLibFile::ZLib_InitStream(result: (mstudioaimconstraint_t *)&D_stream);
  if ( inited != nullptr )
    return (ITexture *)GFxLogBase<GFxStream>::LogError(
                         this: (tagBITMAPINFOHEADER *)a1,
                         a2: (int)"Error: GFx_InflateWrapper() inflateInit() returned %d\n",
                         inited);
  D_stream = (int)pdestBuf;
  v8 = GFxStream::ReadToBuffer(this: a1, pdestBuf, a3: 0x20u);
  v5 = inflate(a1: &D_stream, a2: 2);
  if ( v5 != 1 )
  {
    while ( v5 == 0 )
    {
      D_stream = (int)pdestBuf;
      v8 = GFxStream::ReadToBuffer(this: a1, pdestBuf, a3: 0x20u);
      v5 = inflate(a1: &D_stream, a2: 2);
      if ( v5 == 1 )
        goto LABEL_9;
    }
    GFxLogBase<GFxStream>::LogError(
      this: (tagBITMAPINFOHEADER *)a1,
      a2: (int)"Error: GFx_InflateWrapper() Inflate() returned %d\n",
      v5);
    if ( v8 == 0 )
      goto LABEL_11;
    GFxStream::SetPosition(
      this: (IShaderDeviceMgr *)a1,
      pos: (int)a1[11] + (char *)a1[13] - (char *)a1[12] - v8,
      a3: v6);
  }
LABEL_9:
  if ( v8 != 0 )
    GFxStream::SetPosition(
      this: (IShaderDeviceMgr *)a1,
      pos: (int)a1[11] + (char *)a1[13] - (char *)a1[12] - v8,
      a3: v6);
LABEL_11:
  result = (ITexture *)inflateEnd(a1: &D_stream);
  if ( result != nullptr )
    return (ITexture *)GFxLogBase<GFxStream>::LogError(
                         this: (tagBITMAPINFOHEADER *)a1,
                         a2: (int)"Error: GFx_InflateWrapper() InflateEnd() return %d\n",
                         result);
  return result;
}
