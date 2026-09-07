// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxpngsupport.cpp
// Functions: 1
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxpngsupport.h"

//------------------------------------------------------------------------------
// Address: 0x100722E0
// Name: public: virtual class GImage __near * GFxPNGSupport::CreateImage(class GFile __near *,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
struct GImage *__thiscall GFxPNGSupport::CreateImage(GFxPNGSupport *this, struct GFile *a2, struct GMemoryHeap *a3)
{
  return GImage::ReadPng(a1: a2, a2: a3);
}
