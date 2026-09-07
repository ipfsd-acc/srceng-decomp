// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/gclogger.cpp
// Functions: 3
// ============================================================

#include "gcsdk\gclogger.h"

//------------------------------------------------------------------------------
// Address: 0x10025340
// Name: void GCSDK::EmitWarning(char const __near *,int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void GCSDK::EmitWarning(const char *pchGroupName, int iLevel, const char *pchMsg, ...)
{
  char *PchTempTextBuffer; // esi
  int CchTempTextBuffer; // eax
  IGameCoordinatorHost *v5; // eax
  va_list params; // [esp+1Ch] [ebp+14h] BYREF

  va_start(params, pchMsg);
  PchTempTextBuffer = GCSDK::GetPchTempTextBuffer();
  CchTempTextBuffer = GCSDK::GetCchTempTextBuffer();
  V_vsnprintf(pDest: PchTempTextBuffer, maxLen: CchTempTextBuffer, pFormat: pchMsg, params);
  if ( GCSDK::GGCHost() != nullptr )
  {
    v5 = GCSDK::GGCHost();
    v5->EmitMessage(this: v5, a2: pchGroupName, a3: SPEW_WARNING, a4: iLevel, a5: 1, a6: PchTempTextBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025390
// Name: void GCSDK::EmitError(char const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void GCSDK::EmitError(const char *pchGroupName, const char *pchMsg, ...)
{
  char *PchTempTextBuffer; // esi
  int CchTempTextBuffer; // eax
  IGameCoordinatorHost *v4; // eax
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pchMsg);
  PchTempTextBuffer = GCSDK::GetPchTempTextBuffer();
  CchTempTextBuffer = GCSDK::GetCchTempTextBuffer();
  V_vsnprintf(pDest: PchTempTextBuffer, maxLen: CchTempTextBuffer, pFormat: pchMsg, params);
  if ( GCSDK::GGCHost() != nullptr )
  {
    v4 = GCSDK::GGCHost();
    v4->EmitMessage(this: v4, a2: pchGroupName, a3: SPEW_ERROR, a4: 1, a5: 1, a6: PchTempTextBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100253E0
// Name: void GCSDK::EmitInfo(char const __near *,int,int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void GCSDK::EmitInfo(const char *pchGroupName, int iSpewLevel, int iLevelLog, const char *pchMsg, ...)
{
  char *PchTempTextBuffer; // esi
  int CchTempTextBuffer; // eax
  IGameCoordinatorHost *v6; // eax
  va_list params; // [esp+20h] [ebp+18h] BYREF

  va_start(params, pchMsg);
  PchTempTextBuffer = GCSDK::GetPchTempTextBuffer();
  CchTempTextBuffer = GCSDK::GetCchTempTextBuffer();
  V_vsnprintf(pDest: PchTempTextBuffer, maxLen: CchTempTextBuffer, pFormat: pchMsg, params);
  if ( GCSDK::GGCHost() != nullptr )
  {
    v6 = GCSDK::GGCHost();
    v6->EmitMessage(this: v6, a2: pchGroupName, a3: SPEW_MESSAGE, a4: iSpewLevel, a5: iLevelLog, a6: PchTempTextBuffer);
  }
}
