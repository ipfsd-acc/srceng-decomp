// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/makegamedata/makescenes.cpp
// Functions: 2
// ============================================================

#include "utils\xbox\makegamedata\makescenes.h"

//------------------------------------------------------------------------------
// Address: 0x00410100
// Name: public: virtual void CDefaultStatus::UpdateStatus(char const __near *,bool,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDefaultStatus::UpdateStatus(
        CDefaultStatus *this,
        const char *pchSceneName,
        bool bQuiet,
        int nIndex,
        int nCount)
{
  _Msg(a1: "Scenes: Compiling: %s\n", pchSceneName);
}

//------------------------------------------------------------------------------
// Address: 0x00410120
// Name: bool CreateSceneImageFile(char const __near *,bool,bool,bool,enum DiskWriteMode_t)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CreateSceneImageFile(
        const char *pchModPath,
        bool bWriteToZip,
        BOOL bLittleEndian,
        BOOL bQuiet,
        DiskWriteMode_t eWriteModeForConversions)
{
  const char *v5; // esi
  char v6; // bl
  CUtlBuffer targetBuffer; // [esp+Ch] [ebp-34h] BYREF
  CDefaultStatus statusHelper; // [esp+3Ch] [ebp-4h] BYREF

  CUtlBuffer::CUtlBuffer(this: &targetBuffer, growSize: 0, initSize: 0, nFlags: 0);
  v5 = "scenes/scenes.image";
  if ( !bLittleEndian )
  {
    v5 = "scenes/scenes.ps3.image";
    if ( !g_bSonyPS3 )
      v5 = "scenes/scenes.360.image";
  }
  statusHelper.__vftable = (CDefaultStatus_vtbl *)&CDefaultStatus::`vftable';
  v6 = g_pSceneImage->CreateSceneImageFile(
         this: g_pSceneImage,
         a2: &targetBuffer,
         a3: pchModPath,
         a4: bLittleEndian,
         a5: bQuiet,
         a6: &statusHelper);
  if ( v6 != 0 )
    v6 = WriteBufferToFile(pTargetName: v5, buffer: &targetBuffer, bWriteToZip, writeMode: eWriteModeForConversions);
  if ( targetBuffer.m_Memory.m_nGrowSize >= 0 && targetBuffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetBuffer.m_Memory.m_pMemory);
  return v6;
}
