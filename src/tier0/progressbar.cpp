// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/progressbar.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000C460
// Name: _ReportProgress
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReportProgress(const char *job_name, int total_units_to_do, int n_units_completed)
{
  if ( pReportHandlerFN != nullptr )
    pReportHandlerFN(a1: job_name, a2: total_units_to_do, a3: n_units_completed);
}

//------------------------------------------------------------------------------
// Address: 0x1000C480
// Name: _InstallProgressReportHandler
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__cdecl InstallProgressReportHandler(
        void (__cdecl *pfn)(const char *, int, int)))(const char *, int, int)
{
  void (__cdecl *result)(const char *, int, int); // eax

  result = pReportHandlerFN;
  pReportHandlerFN = pfn;
  return result;
}
