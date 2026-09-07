// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/common/tools_minidump.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10011010
// Name: ToolsExceptionFilter
// Source: json
//------------------------------------------------------------------------------
void __cdecl ToolsExceptionFilter(unsigned int uStructuredExceptionCode, ExceptionInfo_t *pExceptionInfo)
{
  int v2; // eax

  v2 = 0;
  if ( g_bToolsWriteFullMinidumps )
    v2 = 65;
  _WriteMiniDumpUsingExceptionInfo(a1: uStructuredExceptionCode, a2: pExceptionInfo, a3: v2, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10011040
// Name: ToolsExceptionFilter_Custom
// Source: json
//------------------------------------------------------------------------------
void __cdecl ToolsExceptionFilter_Custom(unsigned int uStructuredExceptionCode, ExceptionInfo_t *pExceptionInfo)
{
  g_pCustomExceptionHandler(a1: uStructuredExceptionCode, a2: pExceptionInfo);
}

//------------------------------------------------------------------------------
// Address: 0x10011050
// Name: void SetupDefaultToolsMinidumpHandler(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDefaultToolsMinidumpHandler()
{
  _MinidumpSetUnhandledExceptionFunction(a1: ToolsExceptionFilter);
}

//------------------------------------------------------------------------------
// Address: 0x10011060
// Name: void SetupToolsMinidumpHandler(void (*)(unsigned long,void __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupToolsMinidumpHandler(void (__cdecl *fn)(unsigned int, void *))
{
  g_pCustomExceptionHandler = fn;
  _MinidumpSetUnhandledExceptionFunction(a1: ToolsExceptionFilter_Custom);
}

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x0044D370
// Name: ToolsExceptionFilter
// Source: json
//------------------------------------------------------------------------------
void __cdecl ToolsExceptionFilter(unsigned int uStructuredExceptionCode, ExceptionInfo_t *pExceptionInfo)
{
  int v2; // eax

  v2 = 0;
  if ( g_bToolsWriteFullMinidumps )
    v2 = 65;
  _WriteMiniDumpUsingExceptionInfo(a1: uStructuredExceptionCode, a2: pExceptionInfo, a3: v2, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0044D3A0
// Name: void EnableFullMinidumps(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EnableFullMinidumps(bool bFull)
{
  g_bToolsWriteFullMinidumps = bFull;
}

//------------------------------------------------------------------------------
// Address: 0x0044D3B0
// Name: void SetupDefaultToolsMinidumpHandler(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDefaultToolsMinidumpHandler()
{
  _MinidumpSetUnhandledExceptionFunction(a1: ToolsExceptionFilter);
}

} // namespace vbsp

// ============================================================
// Overlay from vbsp2 (Missing functions)
// ============================================================
namespace vbsp2 {

//------------------------------------------------------------------------------
// Address: 0x00404C10
// Name: ToolsExceptionFilter
// Source: json
//------------------------------------------------------------------------------
void __cdecl ToolsExceptionFilter(unsigned int uStructuredExceptionCode, ExceptionInfo_t *pExceptionInfo)
{
  int v2; // eax

  v2 = 0;
  if ( g_bToolsWriteFullMinidumps )
    v2 = 65;
  _WriteMiniDumpUsingExceptionInfo(a1: uStructuredExceptionCode, a2: pExceptionInfo, a3: v2, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00404C40
// Name: void SetupDefaultToolsMinidumpHandler(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDefaultToolsMinidumpHandler()
{
  _MinidumpSetUnhandledExceptionFunction(a1: ToolsExceptionFilter);
}

} // namespace vbsp2

// ============================================================
// Overlay from vbspinfo (Missing functions)
// ============================================================
namespace vbspinfo {

//------------------------------------------------------------------------------
// Address: 0x0040E3F0
// Name: ToolsExceptionFilter
// Source: json
//------------------------------------------------------------------------------
void __cdecl ToolsExceptionFilter(unsigned int uStructuredExceptionCode, ExceptionInfo_t *pExceptionInfo)
{
  int v2; // eax

  v2 = 0;
  if ( g_bToolsWriteFullMinidumps )
    v2 = 65;
  _WriteMiniDumpUsingExceptionInfo(a1: uStructuredExceptionCode, a2: pExceptionInfo, a3: v2, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0040E420
// Name: void SetupDefaultToolsMinidumpHandler(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDefaultToolsMinidumpHandler()
{
  _MinidumpSetUnhandledExceptionFunction(a1: ToolsExceptionFilter);
}

} // namespace vbspinfo

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x004586C0
// Name: ToolsExceptionFilter
// Source: json
//------------------------------------------------------------------------------
void __cdecl ToolsExceptionFilter(unsigned int uStructuredExceptionCode, ExceptionInfo_t *pExceptionInfo)
{
  int v2; // eax

  v2 = 0;
  if ( g_bToolsWriteFullMinidumps )
    v2 = 65;
  _WriteMiniDumpUsingExceptionInfo(a1: uStructuredExceptionCode, a2: pExceptionInfo, a3: v2, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004586F0
// Name: void EnableFullMinidumps(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EnableFullMinidumps(bool bFull)
{
  g_bToolsWriteFullMinidumps = bFull;
}

//------------------------------------------------------------------------------
// Address: 0x00458700
// Name: void SetupDefaultToolsMinidumpHandler(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDefaultToolsMinidumpHandler()
{
  _MinidumpSetUnhandledExceptionFunction(a1: ToolsExceptionFilter);
}

} // namespace vmap

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x1004C940
// Name: ToolsExceptionFilter
// Source: json
//------------------------------------------------------------------------------
void __cdecl ToolsExceptionFilter(unsigned int uStructuredExceptionCode, ExceptionInfo_t *pExceptionInfo)
{
  int v2; // eax

  v2 = 0;
  if ( g_bToolsWriteFullMinidumps )
    v2 = 65;
  _WriteMiniDumpUsingExceptionInfo(a1: uStructuredExceptionCode, a2: pExceptionInfo, a3: v2, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1004C970
// Name: ToolsExceptionFilter_Custom
// Source: json
//------------------------------------------------------------------------------
void __cdecl ToolsExceptionFilter_Custom(unsigned int uStructuredExceptionCode, ExceptionInfo_t *pExceptionInfo)
{
  g_pCustomExceptionHandler(a1: uStructuredExceptionCode, a2: pExceptionInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1004C980
// Name: void EnableFullMinidumps(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EnableFullMinidumps(bool bFull)
{
  g_bToolsWriteFullMinidumps = bFull;
}

//------------------------------------------------------------------------------
// Address: 0x1004C990
// Name: void SetupDefaultToolsMinidumpHandler(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDefaultToolsMinidumpHandler()
{
  _MinidumpSetUnhandledExceptionFunction(a1: ToolsExceptionFilter);
}

//------------------------------------------------------------------------------
// Address: 0x1004C9A0
// Name: void SetupToolsMinidumpHandler(void (*)(unsigned long,void __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupToolsMinidumpHandler(void (__cdecl *fn)(unsigned int, void *))
{
  g_pCustomExceptionHandler = fn;
  _MinidumpSetUnhandledExceptionFunction(a1: ToolsExceptionFilter_Custom);
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x10014160
// Name: ToolsExceptionFilter
// Source: json
//------------------------------------------------------------------------------
void __cdecl ToolsExceptionFilter(unsigned int uStructuredExceptionCode, ExceptionInfo_t *pExceptionInfo)
{
  int v2; // eax

  v2 = 0;
  if ( g_bToolsWriteFullMinidumps )
    v2 = 65;
  _WriteMiniDumpUsingExceptionInfo(a1: uStructuredExceptionCode, a2: pExceptionInfo, a3: v2, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10014190
// Name: ToolsExceptionFilter_Custom
// Source: json
//------------------------------------------------------------------------------
void __cdecl ToolsExceptionFilter_Custom(unsigned int uStructuredExceptionCode, ExceptionInfo_t *pExceptionInfo)
{
  g_pCustomExceptionHandler(a1: uStructuredExceptionCode, a2: pExceptionInfo);
}

//------------------------------------------------------------------------------
// Address: 0x100141A0
// Name: void EnableFullMinidumps(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EnableFullMinidumps(bool bFull)
{
  g_bToolsWriteFullMinidumps = bFull;
}

//------------------------------------------------------------------------------
// Address: 0x100141B0
// Name: void SetupDefaultToolsMinidumpHandler(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDefaultToolsMinidumpHandler()
{
  _MinidumpSetUnhandledExceptionFunction(a1: ToolsExceptionFilter);
}

//------------------------------------------------------------------------------
// Address: 0x100141C0
// Name: void SetupToolsMinidumpHandler(void (*)(unsigned long,void __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupToolsMinidumpHandler(void (__cdecl *fn)(unsigned int, void *))
{
  g_pCustomExceptionHandler = fn;
  _MinidumpSetUnhandledExceptionFunction(a1: ToolsExceptionFilter_Custom);
}

} // namespace vvis_dll
