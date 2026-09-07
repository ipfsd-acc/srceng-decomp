// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier2/util_init.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004206E0
// Name: PrintFReportHandler
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintFReportHandler(char *job_name, int total_units_to_do, int n_units_completed)
{
  if ( V_strncmp(s1: LastJobName, s2: job_name, count: 1024) != 0 )
  {
    if ( work_in_progress )
      printf(format: "..done\n");
    V_strncpy(pDest: LastJobName, pSrc: job_name, maxLen: 1024);
  }
  if ( total_units_to_do <= 0 || total_units_to_do < n_units_completed )
  {
    printf(format: "%s\n", LastJobName);
    work_in_progress = false;
  }
  else
  {
    printf(format: "\r%s : %d%%", LastJobName, 100 * n_units_completed / total_units_to_do);
    work_in_progress = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420780
// Name: void InitCommandLineProgram(int __near &,char __near * __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitCommandLineProgram(int *argc, char ***argv)
{
  void (__thiscall ***v2)(_DWORD, _DWORD, _DWORD); // eax

  MathLib_Init(gamma: 1.0, texGamma: 1.0, brightness: 1.0, overbright: 0);
  v2 = (void (__thiscall ***)(_DWORD, _DWORD, _DWORD))_CommandLine();
  (**v2)(a1: v2, a2: *argc, a3: *argv);
  InitDefaultFileSystem();
  _InstallProgressReportHandler(a1: PrintFReportHandler);
  if ( *argc > 1 && strcmp((*argv)[1], "-allowdebug") == 0 )
  {
    ++*argv;
    --*argc;
  }
}

// ============================================================
// Overlay from Dist2alpha (Missing functions)
// ============================================================
namespace Dist2alpha {

//------------------------------------------------------------------------------
// Address: 0x0042F750
// Name: PrintFReportHandler
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintFReportHandler(char *job_name, int total_units_to_do, int n_units_completed)
{
  if ( V_strncmp(s1: LastJobName, s2: job_name, count: 1024) != 0 )
  {
    if ( work_in_progress )
      printf(format: "..done\n");
    V_strncpy(pDest: LastJobName, pSrc: job_name, maxLen: 1024);
  }
  if ( total_units_to_do <= 0 || total_units_to_do < n_units_completed )
  {
    printf(format: "%s\n", LastJobName);
    work_in_progress = false;
  }
  else
  {
    printf(format: "\r%s : %d%%", LastJobName, 100 * n_units_completed / total_units_to_do);
    work_in_progress = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F7F0
// Name: void InitCommandLineProgram(int __near &,char __near * __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitCommandLineProgram(int *argc, char ***argv)
{
  void (__thiscall ***v2)(_DWORD, _DWORD, _DWORD); // eax

  MathLib_Init(gamma: 1.0, texGamma: 1.0, brightness: 1.0, overbright: 0);
  v2 = (void (__thiscall ***)(_DWORD, _DWORD, _DWORD))_CommandLine();
  (**v2)(a1: v2, a2: *argc, a3: *argv);
  InitDefaultFileSystem();
  _InstallProgressReportHandler(a1: PrintFReportHandler);
  if ( *argc > 1 && strcmp((*argv)[1], "-allowdebug") == 0 )
  {
    ++*argv;
    --*argc;
  }
}

} // namespace Dist2alpha

// ============================================================
// Overlay from height2ssbump (Missing functions)
// ============================================================
namespace height2ssbump {

//------------------------------------------------------------------------------
// Address: 0x00432420
// Name: PrintFReportHandler
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintFReportHandler(char *job_name, int total_units_to_do, int n_units_completed)
{
  if ( V_strncmp(s1: LastJobName, s2: job_name, count: 1024) != 0 )
  {
    if ( work_in_progress )
      printf(format: "..done\n");
    V_strncpy(pDest: LastJobName, pSrc: job_name, maxLen: 1024);
  }
  if ( total_units_to_do <= 0 || total_units_to_do < n_units_completed )
  {
    printf(format: "%s\n", LastJobName);
    work_in_progress = false;
  }
  else
  {
    printf(format: "\r%s : %d%%", LastJobName, 100 * n_units_completed / total_units_to_do);
    work_in_progress = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004324C0
// Name: void InitCommandLineProgram(int __near &,char __near * __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitCommandLineProgram(int *argc, char ***argv)
{
  void (__thiscall ***v2)(_DWORD, _DWORD, _DWORD); // eax

  MathLib_Init(gamma: 1.0, texGamma: 1.0, brightness: 1.0, overbright: 0);
  v2 = (void (__thiscall ***)(_DWORD, _DWORD, _DWORD))_CommandLine();
  (**v2)(a1: v2, a2: *argc, a3: *argv);
  InitDefaultFileSystem();
  _InstallProgressReportHandler(a1: PrintFReportHandler);
  if ( *argc > 1 && strcmp((*argv)[1], "-allowdebug") == 0 )
  {
    ++*argv;
    --*argc;
  }
}

} // namespace height2ssbump

// ============================================================
// Overlay from ps3shaderoptimizer (Missing functions)
// ============================================================
namespace ps3shaderoptimizer {

//------------------------------------------------------------------------------
// Address: 0x00408030
// Name: PrintFReportHandler
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintFReportHandler(const char *job_name, int total_units_to_do, int n_units_completed)
{
  if ( V_strncmp(s1: LastJobName, s2: job_name, count: 1024) != 0 )
  {
    if ( work_in_progress )
      printf(format: "..done\n");
    V_strncpy(pDest: LastJobName, pSrc: job_name, maxLen: 1024);
  }
  if ( total_units_to_do <= 0 || total_units_to_do < n_units_completed )
  {
    printf(format: "%s\n", LastJobName);
    work_in_progress = false;
  }
  else
  {
    printf(format: "\r%s : %d%%", LastJobName, 100 * n_units_completed / total_units_to_do);
    work_in_progress = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004080D0
// Name: void InitCommandLineProgram(int __near &,char __near * __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitCommandLineProgram(int *argc, char ***argv)
{
  void (__thiscall ***v2)(_DWORD, _DWORD, _DWORD); // eax

  MathLib_Init(
    gamma: 1.0,
    texGamma: 1.0,
    brightness: 1.0,
    overbright: 0,
    bAllow3DNow: false,
    bAllowSSE: true,
    bAllowSSE2: true,
    bAllowMMX: true);
  v2 = (void (__thiscall ***)(_DWORD, _DWORD, _DWORD))_CommandLine();
  (**v2)(a1: v2, a2: *argc, a3: *argv);
  InitDefaultFileSystem();
  _InstallProgressReportHandler(a1: PrintFReportHandler);
  if ( *argc > 1 && strcmp((*argv)[1], "-allowdebug") == 0 )
  {
    ++*argv;
    --*argc;
  }
}

} // namespace ps3shaderoptimizer

// ============================================================
// Overlay from simdtest (Missing functions)
// ============================================================
namespace simdtest {

//------------------------------------------------------------------------------
// Address: 0x00401DA0
// Name: PrintFReportHandler
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintFReportHandler(const char *job_name, int total_units_to_do, int n_units_completed)
{
  if ( V_strncmp(s1: LastJobName, s2: job_name, count: 1024) != 0 )
  {
    if ( work_in_progress )
      printf(format: "..done\n");
    V_strncpy(pDest: LastJobName, pSrc: job_name, maxLen: 1024);
  }
  if ( total_units_to_do <= 0 || total_units_to_do < n_units_completed )
  {
    printf(format: "%s\n", LastJobName);
    work_in_progress = false;
  }
  else
  {
    printf(format: "\r%s : %d%%", LastJobName, 100 * n_units_completed / total_units_to_do);
    work_in_progress = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401E40
// Name: void InitCommandLineProgram(int __near &,char __near * __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitCommandLineProgram(int *argc, char ***argv)
{
  void (__thiscall ***v2)(_DWORD, _DWORD, _DWORD); // eax

  MathLib_Init(
    gamma: 1.0,
    texGamma: 1.0,
    brightness: 1.0,
    overbright: 0,
    bAllow3DNow: false,
    bAllowSSE: true,
    bAllowSSE2: true,
    bAllowMMX: true);
  v2 = (void (__thiscall ***)(_DWORD, _DWORD, _DWORD))_CommandLine();
  (**v2)(a1: v2, a2: *argc, a3: *argv);
  InitDefaultFileSystem();
  _InstallProgressReportHandler(a1: PrintFReportHandler);
  if ( *argc > 1 && strcmp((*argv)[1], "-allowdebug") == 0 )
  {
    ++*argv;
    --*argc;
  }
}

} // namespace simdtest

// ============================================================
// Overlay from vbspinfo (Missing functions)
// ============================================================
namespace vbspinfo {

//------------------------------------------------------------------------------
// Address: 0x004180B0
// Name: PrintFReportHandler
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintFReportHandler(char *job_name, int total_units_to_do, int n_units_completed)
{
  if ( V_strncmp(s1: LastJobName, s2: job_name, count: 1024) != 0 )
  {
    if ( work_in_progress )
      printf(format: "..done\n");
    V_strncpy(pDest: LastJobName, pSrc: job_name, maxLen: 1024);
  }
  if ( total_units_to_do <= 0 || total_units_to_do < n_units_completed )
  {
    printf(format: "%s\n", LastJobName);
    work_in_progress = false;
  }
  else
  {
    printf(format: "\r%s : %d%%", LastJobName, 100 * n_units_completed / total_units_to_do);
    work_in_progress = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418150
// Name: void InitCommandLineProgram(int __near &,char __near * __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitCommandLineProgram(int *argc, char ***argv)
{
  void (__thiscall ***v2)(_DWORD, _DWORD, _DWORD); // eax

  MathLib_Init(gamma: 1.0, texGamma: 1.0, brightness: 1.0, overbright: 0);
  v2 = (void (__thiscall ***)(_DWORD, _DWORD, _DWORD))_CommandLine();
  (**v2)(a1: v2, a2: *argc, a3: *argv);
  InitDefaultFileSystem();
  _InstallProgressReportHandler(a1: PrintFReportHandler);
  if ( *argc > 1 && strcmp((*argv)[1], "-allowdebug") == 0 )
  {
    ++*argv;
    --*argc;
  }
}

} // namespace vbspinfo

// ============================================================
// Overlay from videocache (Missing functions)
// ============================================================
namespace videocache {

//------------------------------------------------------------------------------
// Address: 0x00407DD0
// Name: PrintFReportHandler
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintFReportHandler(char *job_name, int total_units_to_do, int n_units_completed)
{
  if ( V_strncmp(s1: LastJobName, s2: job_name, count: 1024) != 0 )
  {
    if ( work_in_progress )
      printf(format: "..done\n");
    V_strncpy(pDest: LastJobName, pSrc: job_name, maxLen: 1024);
  }
  if ( total_units_to_do <= 0 || total_units_to_do < n_units_completed )
  {
    printf(format: "%s\n", LastJobName);
    work_in_progress = false;
  }
  else
  {
    printf(format: "\r%s : %d%%", LastJobName, 100 * n_units_completed / total_units_to_do);
    work_in_progress = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407E70
// Name: void InitCommandLineProgram(int __near &,char __near * __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitCommandLineProgram(int *argc, char ***argv)
{
  void (__thiscall ***v2)(_DWORD, _DWORD, _DWORD); // eax

  MathLib_Init(
    gamma: 1.0,
    texGamma: 1.0,
    brightness: 1.0,
    overbright: 0,
    bAllow3DNow: false,
    bAllowSSE: true,
    bAllowSSE2: true,
    bAllowMMX: true);
  v2 = (void (__thiscall ***)(_DWORD, _DWORD, _DWORD))_CommandLine();
  (**v2)(a1: v2, a2: *argc, a3: *argv);
  InitDefaultFileSystem();
  _InstallProgressReportHandler(a1: PrintFReportHandler);
  if ( *argc > 1 && strcmp((*argv)[1], "-allowdebug") == 0 )
  {
    ++*argv;
    --*argc;
  }
}

} // namespace videocache
