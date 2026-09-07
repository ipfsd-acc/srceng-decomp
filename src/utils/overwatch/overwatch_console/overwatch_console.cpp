// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/overwatch/overwatch_console/overwatch_console.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004010C0
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl __noreturn main(int argc, const char **argv, const char **envp)
{
  int (*v3)(void); // ebx
  void (__thiscall ***v4)(_DWORD, int, const char **); // eax
  int (*v5)(const char *, ...); // edi
  const COverwatchStats *OverwatchStats; // eax
  unsigned int m_nMemoryBytesLimit_high; // ecx
  unsigned int v8; // edx
  unsigned int v9; // kr00_4
  int m_nMemoryBytesUsed_high; // ecx
  int m_nMemoryBytesUsed; // edx
  unsigned int v12; // edx
  unsigned int m_nDirectoryEntriesCreated; // ecx
  unsigned int m_nFileEntriesCreated; // edx
  int v15; // esi
  int v16; // eax
  int v17; // eax
  const char *v18; // esi
  GetSnapshotStatus_t SnapshotForDir; // edi
  const char *v20; // edi
  int v21; // eax
  const char *v22; // [esp+Ch] [ebp-CCh]
  __int64 v23; // [esp+10h] [ebp-C8h]
  int i; // [esp+38h] [ebp-A0h]
  int ia; // [esp+38h] [ebp-A0h]
  int nFilesScanned; // [esp+3Ch] [ebp-9Ch] BYREF
  CFastTimer timer; // [esp+40h] [ebp-98h]
  COverwatchSnapshot *pSnapshot; // [esp+4Ch] [ebp-8Ch] BYREF
  __int64 v29; // [esp+50h] [ebp-88h] BYREF
  __int64 v30; // [esp+58h] [ebp-80h]
  int v31; // [esp+60h] [ebp-78h]
  unsigned int v32; // [esp+64h] [ebp-74h]
  __int64 v33; // [esp+68h] [ebp-70h]
  __int64 v34; // [esp+70h] [ebp-68h]
  unsigned int m_nMemoryBytesLimit; // [esp+78h] [ebp-60h]
  int v36; // [esp+7Ch] [ebp-5Ch]
  COverwatchClient client; // [esp+80h] [ebp-58h] BYREF

  v3 = _CommandLine;
  v4 = (void (__thiscall ***)(_DWORD, int, const char **))_CommandLine();
  (**v4)(a1: v4, a2: argc, a3: argv);
  v5 = _Msg;
  while ( 1 )
  {
    COverwatchClient::COverwatchClient(this: &client);
    while ( !COverwatchClient::Connect(this: &client, nTimeout: 0x64u) )
    {
      if ( !bDidMsg )
      {
        v5(a1: "Overwatch service not available. Waiting...");
        bDidMsg = true;
      }
    }
    v5(a1: "\n\nConnected to overwatch service!\n\n");
    while ( 1 )
    {
      i = 0;
      if ( !COverwatchClient::GetNumFilesScanned(this: &client, pnFilesScanned: &nFilesScanned, nTimeout: 0x64u) )
        break;
LABEL_10:
      OverwatchStats = COverwatchClient::GetOverwatchStats(this: &client);
      m_nMemoryBytesLimit_high = HIDWORD(OverwatchStats->m_nMemoryBytesLimit);
      m_nMemoryBytesLimit = OverwatchStats->m_nMemoryBytesLimit;
      v8 = m_nMemoryBytesLimit_high;
      v9 = m_nMemoryBytesLimit_high;
      v36 = m_nMemoryBytesLimit_high & 0x7FFFFFFF;
      m_nMemoryBytesUsed_high = HIDWORD(OverwatchStats->m_nMemoryBytesUsed);
      v32 = v8 & 0x80000000;
      m_nMemoryBytesUsed = OverwatchStats->m_nMemoryBytesUsed;
      v31 = 0;
      LODWORD(v33) = m_nMemoryBytesUsed;
      v12 = m_nMemoryBytesUsed_high & 0x80000000;
      HIDWORD(v33) = m_nMemoryBytesUsed_high & 0x7FFFFFFF;
      m_nDirectoryEntriesCreated = OverwatchStats->m_nDirectoryEntriesCreated;
      HIDWORD(v34) = v12;
      m_nFileEntriesCreated = OverwatchStats->m_nFileEntriesCreated;
      LODWORD(v34) = 0;
      v5(
        a1: "%d scanned, %d created, %d dirs, %.2fM used, %.2fM total\n",
        nFilesScanned,
        m_nFileEntriesCreated,
        m_nDirectoryEntriesCreated,
        0.00000095367432 * ((double)v33 - (double)v34),
        (double)__PAIR64__(v9, m_nMemoryBytesLimit) * 0.00000095367432);
      timer.m_Duration.m_Int64 = __rdtsc();
      v15 = 1;
      ia = 1;
      v16 = v3();
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)v16 + 36))(a1: v16) - 1 > 1 )
      {
        HIDWORD(v30) = &v29;
        do
        {
          v17 = v3();
          v18 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v17 + 44))(a1: v17, a2: v15);
          SnapshotForDir = COverwatchClient::GetSnapshotForDir(this: &client, pDirName: v18, &pSnapshot, nFlags: 1);
          v29 = 0;
          *(_QWORD *)HIDWORD(v30) = __rdtsc();
          timer.m_Duration.m_Int64 = v29 - timer.m_Duration.m_Int64;
          if ( SnapshotForDir != GETSNAPSHOT_OK )
          {
            if ( SnapshotForDir == GETSNAPSHOT_NOTDONESCANNING )
            {
              _Error(a1: "Overwatch service isn't done scanning %s\n", v18);
            }
            else if ( SnapshotForDir == GETSNAPSHOT_ERROR )
            {
              _Error(a1: "Unable to get snapshot for %s from overwatch!\n", v18);
            }
            else
            {
              _Error(a1: "Unknown error");
            }
          }
          v20 = "valid";
          if ( pSnapshot == nullptr )
            v20 = "(invalid)";
          HIDWORD(v23) = HIDWORD(_g_ClockSpeed);
          LODWORD(v23) = _g_ClockSpeed;
          v22 = v20;
          v5 = _Msg;
          _Msg(
            a1: "Got %s snapshot of '%s' in %du\n",
            v22,
            v18,
            (unsigned int)(1000000 * timer.m_Duration.m_Int64 / v23));
          if ( pSnapshot != nullptr )
            COverwatchSnapshot::Release(this: pSnapshot);
          v3 = _CommandLine;
          v15 = ++ia;
          v21 = _CommandLine();
        }
        while ( ia < (*(int (__thiscall **)(int))(*(_DWORD *)v21 + 36))(a1: v21) - 1 );
      }
      Sleep(dwMilliseconds: 0x64u);
    }
    while ( 1 )
    {
      i += 100;
      v5(a1: "Waited %dms\n", i);
      if ( !COverwatchClient::IsConnected(this: &client) )
        break;
      if ( COverwatchClient::GetNumFilesScanned(this: &client, pnFilesScanned: &nFilesScanned, nTimeout: 0x64u) )
        goto LABEL_10;
    }
    v5(a1: "Disconnected! Reconnecting..\n");
    COverwatchClient::~COverwatchClient(this: &client);
  }
}
