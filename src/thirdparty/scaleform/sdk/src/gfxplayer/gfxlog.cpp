// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxlog.cpp
// Functions: 1
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxlog.h"

//------------------------------------------------------------------------------
// Address: 0x10072280
// Name: public: virtual void GFxLog::LogMessageVarg(enum GFxLogConstants::LogMessageType,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLog::LogMessageVarg(GFxLog *this, enum GFxLogConstants::LogMessageType a2, char *format, char *ap)
{
  char string[2048]; // [esp+0h] [ebp-804h] BYREF

  string[0] = 0;
  if ( vsnprintf_s(string, sizeInBytes: 0x800u, count: 0xFFFFFFFF, format, ap) == -1 )
    string[2047] = 0;
  OutputDebugStringA(lpOutputString: string);
}
