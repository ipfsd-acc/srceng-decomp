// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/dt_instrumentation_server.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1016D330
// Name: void _ServerDTI_HookTimer(class SendTable const __near *,enum ServerDTITimerType,class CCycleCount const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _ServerDTI_HookTimer(const SendTable *pSendTable, ServerDTITimerType timerType, const CCycleCount *count)
{
  CSendTablePrecalc *m_pPrecalc; // eax
  CDTISendTable *m_pDTITable; // esi
  bool v5; // cf

  m_pPrecalc = pSendTable->m_pPrecalc;
  if ( m_pPrecalc != nullptr )
  {
    m_pDTITable = m_pPrecalc->m_pDTITable;
    if ( m_pDTITable != nullptr )
    {
      if ( g_bFirstHookTimer )
      {
        g_ServerDTITimer.m_Int64 = __rdtsc();
        g_bFirstHookTimer = false;
      }
      g_TotalServerDTICycles.m_Int64 += count->m_Int64;
      if ( timerType != SERVERDTI_CALCDELTA )
      {
        switch ( timerType )
        {
          case SERVERDTI_ENCODE:
            v5 = __CFADD__(count->m_Int64, m_pDTITable->m_nEncodeCycles.m_Int64);
            LODWORD(m_pDTITable->m_nEncodeCycles.m_Int64) += LODWORD(count->m_Int64);
            HIDWORD(m_pDTITable->m_nEncodeCycles.m_Int64) += HIDWORD(count->m_Int64) + v5;
            ++m_pDTITable->m_nEncodeCalls;
            break;
          case SERVERDTI_SHOULDTRANSMIT:
            v5 = __CFADD__(count->m_Int64, m_pDTITable->m_nShouldTransmitCycles.m_Int64);
            LODWORD(m_pDTITable->m_nShouldTransmitCycles.m_Int64) += LODWORD(count->m_Int64);
            HIDWORD(m_pDTITable->m_nShouldTransmitCycles.m_Int64) += HIDWORD(count->m_Int64) + v5;
            ++m_pDTITable->m_nShouldTransmitCalls;
            break;
          case SERVERDTI_WRITE_DELTA_PROPS:
            v5 = __CFADD__(count->m_Int64, m_pDTITable->m_nWriteDeltaPropsCycles.m_Int64);
            LODWORD(m_pDTITable->m_nWriteDeltaPropsCycles.m_Int64) += LODWORD(count->m_Int64);
            HIDWORD(m_pDTITable->m_nWriteDeltaPropsCycles.m_Int64) += HIDWORD(count->m_Int64) + v5;
            break;
          default:
            break;
        }
      }
      else
      {
        v5 = __CFADD__(count->m_Int64, m_pDTITable->m_nCalcDeltaCycles.m_Int64);
        LODWORD(m_pDTITable->m_nCalcDeltaCycles.m_Int64) += LODWORD(count->m_Int64);
        HIDWORD(m_pDTITable->m_nCalcDeltaCycles.m_Int64) += HIDWORD(count->m_Int64) + v5;
        ++m_pDTITable->m_nCalcDeltaCalls;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016D3E0
// Name: void ServerDTI_AddEntityEncodeEvent(class SendTable __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ServerDTI_AddEntityEncodeEvent(SendTable *pSendTable, float distToPlayer)
{
  CSendTablePrecalc *m_pPrecalc; // eax
  CDTISendTable *m_pDTITable; // ecx
  int v4; // eax

  m_pPrecalc = pSendTable->m_pPrecalc;
  if ( m_pPrecalc != nullptr )
  {
    m_pDTITable = m_pPrecalc->m_pDTITable;
    if ( m_pDTITable != nullptr )
    {
      v4 = (int)(float)(distToPlayer * 0.0049999999);
      if ( v4 >= 0 )
      {
        if ( v4 > 39 )
          v4 = 39;
        ++m_pDTITable->m_DistanceDeltaCounts[v4];
      }
      else
      {
        ++m_pDTITable->m_DistanceDeltaCounts[0];
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016D620
// Name: void ServerDTI_Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ServerDTI_Flush(__int64 a1@<esi:edi>)
{
  unsigned int v1; // esi
  void *(__thiscall *Open)(IBaseFileSystem *, const char *, const char *, const char *); // edx
  void *v3; // edi
  int m_Next; // eax
  UtlLinkedListElem_t<CDTISendTable *,unsigned short> *v5; // ecx
  CDTISendTable *m_Element; // eax
  int v7; // eax
  UtlLinkedListElem_t<CDTISendTable *,unsigned short> *m_pMemory; // ecx
  int v9; // eax
  int v10; // esi
  __int64 v11; // rax
  unsigned int v12; // kr04_4
  const char *v13; // eax
  IFileSystem_vtbl *v14; // ecx
  int v15; // edx
  int v16; // eax
  int (*FPrintf)(IFileSystem *, void *, const char *, ...); // ecx
  double v18; // st7
  IFileSystem_vtbl *v19; // ecx
  IFileSystem_vtbl *v20; // edx
  void *v21; // esi
  int i; // edi
  int v23; // eax
  UtlLinkedListElem_t<CDTISendTable *,unsigned short> *v24; // ecx
  int v25; // eax
  CUtlString *v26; // edi
  const char *v27; // eax
  unsigned __int16 *v28; // edi
  long double v30; // [esp+44h] [ebp-ECh]
  long double v31; // [esp+4Ch] [ebp-E4h]
  long double v32; // [esp+6Ch] [ebp-C4h]
  unsigned int v33; // [esp+8Ch] [ebp-A4h]
  const char *v34; // [esp+D4h] [ebp-5Ch]
  unsigned __int64 v35; // [esp+D8h] [ebp-58h]
  unsigned __int64 v36; // [esp+E0h] [ebp-50h]
  unsigned __int64 v37; // [esp+E8h] [ebp-48h] BYREF
  unsigned __int64 v38; // [esp+F0h] [ebp-40h]
  int v39; // [esp+F8h] [ebp-38h]
  _QWORD v40[4]; // [esp+FCh] [ebp-34h] BYREF
  unsigned __int64 v41; // [esp+11Ch] [ebp-14h]
  int j; // [esp+124h] [ebp-Ch]
  unsigned __int64 v43; // [esp+128h] [ebp-8h]

  if ( g_pServerDTIFilename != nullptr )
  {
    j = (int)&v37;
    v37 = __rdtsc();
    v1 = v37 - LODWORD(g_ServerDTITimer.m_Int64);
    Open = g_pFileSystem->Open;
    v38 = v37 - g_ServerDTITimer.m_Int64;
    v3 = (void *)((int (__thiscall *)(IBaseFileSystem *, const char *, const char *, const char *, _DWORD, _DWORD))Open)(
                   a1: &g_pFileSystem->IBaseFileSystem,
                   a2: g_pServerDTIFilename,
                   a3: "wt",
                   a4: "LOGDIR",
                   a5: a1,
                   a6: HIDWORD(a1));
    if ( v3 != nullptr )
    {
      g_pFileSystem->FPrintf(
        this: g_pFileSystem,
        a2: v3,
        a3: "DTName\tCalcDelta calls\tCalcDelta ms\tEncode calls\tEncode ms\tShouldTransmit calls\tShouldTransmit ms\tWriteDe"
        "ltaProps ms\t%% manual mode\tTotal\tPercent\n");
      LOWORD(m_Next) = g_DTISendTables.m_Head;
      memset(v40, 0, sizeof(v40));
      if ( g_DTISendTables.m_Head != 0xFFFF )
      {
        do
        {
          v5 = &g_DTISendTables.m_Memory.m_pMemory[(unsigned __int16)m_Next];
          m_Element = v5->m_Element;
          v40[0] += v5->m_Element->m_nCalcDeltaCycles.m_Int64;
          v40[1] += m_Element->m_nEncodeCycles.m_Int64;
          v40[2] += m_Element->m_nShouldTransmitCycles.m_Int64;
          v40[3] += m_Element->m_nWriteDeltaPropsCycles.m_Int64;
          m_Next = v5->m_Next;
        }
        while ( m_Next != 0xFFFF );
        v1 = v38;
      }
      LOWORD(v7) = g_DTISendTables.m_Head;
      if ( g_DTISendTables.m_Head != 0xFFFF )
      {
        m_pMemory = g_DTISendTables.m_Memory.m_pMemory;
        do
        {
          v9 = 8 * (unsigned __int16)v7;
          v10 = *(int *)((char *)&m_pMemory->m_Element + v9);
          v39 = v9;
          if ( *(_DWORD *)(v10 + 24) != 0 || *(_DWORD *)(v10 + 40) != 0 || *(_DWORD *)(v10 + 56) != 0 )
          {
            v36 = *(_QWORD *)(v10 + 48);
            LODWORD(v35) = *(_DWORD *)(v10 + 32);
            LODWORD(v41) = *(_DWORD *)(v10 + 16);
            LODWORD(v11) = v41;
            HIDWORD(v11) = *(_DWORD *)(v10 + 36);
            HIDWORD(v41) = *(_DWORD *)(v10 + 20);
            v33 = v36 + v35 + v41;
            v12 = (v36 + __PAIR64__(HIDWORD(v41), v35) + v11) >> 32;
            HIDWORD(v35) = HIDWORD(v11);
            v31 = (double)v38 * _g_ClockSpeedMillisecondsMultiplier;
            v32 = (double)*(unsigned __int64 *)(v10 + 64) * _g_ClockSpeedMillisecondsMultiplier;
            v43 = v41 & 0x8000000000000000uLL;
            v30 = (double)v41 * _g_ClockSpeedMillisecondsMultiplier;
            v13 = CUtlString::operator char const *(this: (CUtlString *)v10);
            v14 = g_pFileSystem->IAppSystem::__vftable;
            v15 = *(_DWORD *)(v10 + 72);
            v34 = v13;
            j = *(_DWORD *)(v10 + 76);
            v16 = *(_DWORD *)(v10 + 56);
            FPrintf = v14->FPrintf;
            v18 = (double)j;
            j += v15;
            FPrintf(
              this: g_pFileSystem,
              a2: v3,
              a3: "%s\t%d\t%.3f\t%d\t%.3f\t%d\t%.3f\t%.3f\t%.2f\t%.3f\t%.3f\n",
              v34,
              *(_DWORD *)(v10 + 24),
              v30,
              *(_DWORD *)(v10 + 40),
              (double)v35 * _g_ClockSpeedMillisecondsMultiplier,
              v16,
              (double)v36 * _g_ClockSpeedMillisecondsMultiplier,
              v32,
              v18 * 100.0 / (double)j,
              (double)__PAIR64__(v12, v33) * _g_ClockSpeedMillisecondsMultiplier,
              (double)__PAIR64__(v12, v33) * _g_ClockSpeedMillisecondsMultiplier * 100.0 / v31);
            v9 = v39;
          }
          m_pMemory = g_DTISendTables.m_Memory.m_pMemory;
          v7 = *(unsigned __int16 *)((char *)&g_DTISendTables.m_Memory.m_pMemory->m_Next + v9);
        }
        while ( v7 != 0xFFFF );
        v1 = v38;
      }
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v3, a3: "\n\n");
      v43 = v38 & 0x8000000000000000uLL;
      v19 = g_pFileSystem->IAppSystem::__vftable;
      *(double *)&v41 = (double)__PAIR64__(HIDWORD(v38), v1);
      v19->FPrintf(
        this: g_pFileSystem,
        a2: v3,
        a3: "Total profile ms:\t%.3f\n",
        *(double *)&v41 * _g_ClockSpeedMillisecondsMultiplier);
      v43 = v40[0] & 0x8000000000000000uLL;
      g_pFileSystem->FPrintf(
        this: g_pFileSystem,
        a2: v3,
        a3: "Total CalcDelta ms:\t%.3f\tPercent:\t%.3f\n",
        (double)v40[0] * _g_ClockSpeedMillisecondsMultiplier,
        100.0
      * ((double)v40[0]
       * _g_ClockSpeedMillisecondsMultiplier)
      / (*(double *)&v41
       * _g_ClockSpeedMillisecondsMultiplier));
      v43 = v40[1] & 0x80000000FFFFFFFFuLL;
      v20 = g_pFileSystem->IAppSystem::__vftable;
      LODWORD(v43) = 0;
      v20->FPrintf(
        this: g_pFileSystem,
        a2: v3,
        a3: "Total Encode ms:\t%.3f\tPercent:\t%.3f\n",
        (double)v40[1] * _g_ClockSpeedMillisecondsMultiplier,
        100.0
      * ((double)v40[1]
       * _g_ClockSpeedMillisecondsMultiplier)
      / (*(double *)&v41
       * _g_ClockSpeedMillisecondsMultiplier));
      v43 = v40[2] & 0x8000000000000000uLL;
      g_pFileSystem->FPrintf(
        this: g_pFileSystem,
        a2: v3,
        a3: "Total ShouldTransmit ms:\t%.3f\tPercent:\t%.3f\n",
        (double)v40[2] * _g_ClockSpeedMillisecondsMultiplier,
        100.0
      * ((double)v40[2]
       * _g_ClockSpeedMillisecondsMultiplier)
      / (*(double *)&v41
       * _g_ClockSpeedMillisecondsMultiplier));
      v43 = v40[3] & 0x8000000000000000uLL;
      g_pFileSystem->FPrintf(
        this: g_pFileSystem,
        a2: v3,
        a3: "Total WriteDeltaProps ms:\t%.3f\tPercent:\t%.3f\n",
        (double)v40[3] * _g_ClockSpeedMillisecondsMultiplier,
        100.0
      * ((double)v40[3]
       * _g_ClockSpeedMillisecondsMultiplier)
      / (*(double *)&v41
       * _g_ClockSpeedMillisecondsMultiplier));
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
      _Msg(a1: "DTI: Wrote delta distances into %s.\n", g_pServerDTIFilename);
    }
    v21 = (void *)((int (__thiscall *)(IBaseFileSystem *, const char *))g_pFileSystem->Open)(
                    a1: &g_pFileSystem->IBaseFileSystem,
                    a2: "dti_delta_distances.txt");
    if ( v21 != nullptr )
    {
      ((void (__stdcall *)(IFileSystem *))g_pFileSystem->FPrintf)(a1: g_pFileSystem);
      for ( i = 200; i < 8200; i += 200 )
        g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v21, a3: "\t<%d", i);
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v21, a3: "\n");
      LOWORD(v23) = g_DTISendTables.m_Head;
      if ( g_DTISendTables.m_Head != 0xFFFF )
      {
        v24 = g_DTISendTables.m_Memory.m_pMemory;
        do
        {
          v25 = 8 * (unsigned __int16)v23;
          v26 = *(CUtlString **)((char *)&v24->m_Element + v25);
          v39 = v25;
          if ( v26[1].m_Storage.m_Memory.m_nGrowSize != 0
            || v26[2].m_Storage.m_Memory.m_nGrowSize != 0
            || v26[3].m_Storage.m_Memory.m_nGrowSize != 0 )
          {
            v27 = CUtlString::operator char const *(this: v26);
            g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v21, a3: "%s", v27);
            v28 = (unsigned __int16 *)&v26[5];
            for ( j = 40; j != 0; --j )
              g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v21, a3: "\t%d", *v28++);
            g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v21, a3: "\n");
            v24 = g_DTISendTables.m_Memory.m_pMemory;
            v25 = v39;
          }
          v23 = *(unsigned __int16 *)((char *)&v24->m_Next + v25);
        }
        while ( v23 != 0xFFFF );
      }
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v21);
      _Msg(a1: "DTI: Wrote instrumentation data into %s.\n", "dti_delta_distances.txt");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016DDD0
// Name: void ServerDTI_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ServerDTI_Term(__int64 a1@<esi:edi>)
{
  if ( g_pServerDTIFilename != nullptr )
  {
    ServerDTI_Flush(a1);
    CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(this: &g_DTISendTables);
    g_pServerDTIFilename = nullptr;
    g_bServerDTIEnabled = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016DE00
// Name: class CDTISendTable __near * ServerDTI_HookTable(class SendTable __near *)
// Source: json
//------------------------------------------------------------------------------
CDTISendTable *__cdecl ServerDTI_HookTable(SendTable *pTable)
{
  CUtlString *v2; // eax
  CUtlString *v3; // esi
  unsigned __int16 v4; // ax
  int v5; // edi
  UtlLinkedListElem_t<CDTISendTable *,unsigned short> *v6; // eax

  if ( !g_bServerDTIEnabled )
    return nullptr;
  v2 = (CUtlString *)MemAlloc_Alloc(nSize: 0xA0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CUtlString::CUtlString(this: v2);
    v3[1].m_Storage.m_Memory.m_pMemory = nullptr;
    v3[1].m_Storage.m_Memory.m_nAllocationCount = 0;
    v3[2].m_Storage.m_Memory.m_pMemory = nullptr;
    v3[2].m_Storage.m_Memory.m_nAllocationCount = 0;
    v3[3].m_Storage.m_Memory.m_pMemory = nullptr;
    v3[3].m_Storage.m_Memory.m_nAllocationCount = 0;
    v3[4].m_Storage.m_Memory.m_pMemory = nullptr;
    v3[4].m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  else
  {
    v3 = nullptr;
  }
  memset(dst: (unsigned __int8 *)v3, value: 0, count: 0xA0u);
  CUtlString::Set(this: v3, pValue: pTable->m_pNetTableName);
  v4 = CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short>>::AllocInternal(
         this: &g_DTISendTables,
         multilist: false);
  v5 = v4;
  if ( v4 != 0xFFFF )
  {
    CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_DTISendTables,
      before: 0xFFFFu,
      elem: v4);
    v6 = &g_DTISendTables.m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
      v6->m_Element = (CDTISendTable *)v3;
  }
  return (CDTISendTable *)v3;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1016D4A0
// Name: void _ServerDTI_HookTimer(class SendTable const __near *,enum ServerDTITimerType,class CCycleCount const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _ServerDTI_HookTimer(const SendTable *pSendTable, ServerDTITimerType timerType, const CCycleCount *count)
{
  CSendTablePrecalc *m_pPrecalc; // eax
  CDTISendTable *m_pDTITable; // esi
  bool v5; // cf

  m_pPrecalc = pSendTable->m_pPrecalc;
  if ( m_pPrecalc != nullptr )
  {
    m_pDTITable = m_pPrecalc->m_pDTITable;
    if ( m_pDTITable != nullptr )
    {
      if ( g_bFirstHookTimer )
      {
        g_ServerDTITimer.m_Int64 = __rdtsc();
        g_bFirstHookTimer = false;
      }
      g_TotalServerDTICycles.m_Int64 += count->m_Int64;
      if ( timerType != SERVERDTI_CALCDELTA )
      {
        switch ( timerType )
        {
          case SERVERDTI_ENCODE:
            v5 = __CFADD__(count->m_Int64, m_pDTITable->m_nEncodeCycles.m_Int64);
            LODWORD(m_pDTITable->m_nEncodeCycles.m_Int64) += LODWORD(count->m_Int64);
            HIDWORD(m_pDTITable->m_nEncodeCycles.m_Int64) += HIDWORD(count->m_Int64) + v5;
            ++m_pDTITable->m_nEncodeCalls;
            break;
          case SERVERDTI_SHOULDTRANSMIT:
            v5 = __CFADD__(count->m_Int64, m_pDTITable->m_nShouldTransmitCycles.m_Int64);
            LODWORD(m_pDTITable->m_nShouldTransmitCycles.m_Int64) += LODWORD(count->m_Int64);
            HIDWORD(m_pDTITable->m_nShouldTransmitCycles.m_Int64) += HIDWORD(count->m_Int64) + v5;
            ++m_pDTITable->m_nShouldTransmitCalls;
            break;
          case SERVERDTI_WRITE_DELTA_PROPS:
            v5 = __CFADD__(count->m_Int64, m_pDTITable->m_nWriteDeltaPropsCycles.m_Int64);
            LODWORD(m_pDTITable->m_nWriteDeltaPropsCycles.m_Int64) += LODWORD(count->m_Int64);
            HIDWORD(m_pDTITable->m_nWriteDeltaPropsCycles.m_Int64) += HIDWORD(count->m_Int64) + v5;
            break;
          default:
            break;
        }
      }
      else
      {
        v5 = __CFADD__(count->m_Int64, m_pDTITable->m_nCalcDeltaCycles.m_Int64);
        LODWORD(m_pDTITable->m_nCalcDeltaCycles.m_Int64) += LODWORD(count->m_Int64);
        HIDWORD(m_pDTITable->m_nCalcDeltaCycles.m_Int64) += HIDWORD(count->m_Int64) + v5;
        ++m_pDTITable->m_nCalcDeltaCalls;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016D550
// Name: void ServerDTI_AddEntityEncodeEvent(class SendTable __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ServerDTI_AddEntityEncodeEvent(SendTable *pSendTable, float distToPlayer)
{
  CSendTablePrecalc *m_pPrecalc; // eax
  CDTISendTable *m_pDTITable; // ecx
  int v4; // eax

  m_pPrecalc = pSendTable->m_pPrecalc;
  if ( m_pPrecalc != nullptr )
  {
    m_pDTITable = m_pPrecalc->m_pDTITable;
    if ( m_pDTITable != nullptr )
    {
      v4 = (int)(float)(distToPlayer * 0.0049999999);
      if ( v4 >= 0 )
      {
        if ( v4 > 39 )
          v4 = 39;
        ++m_pDTITable->m_DistanceDeltaCounts[v4];
      }
      else
      {
        ++m_pDTITable->m_DistanceDeltaCounts[0];
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016D720
// Name: void ServerDTI_Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ServerDTI_Flush(__int64 a1@<esi:edi>)
{
  unsigned int v1; // esi
  void *(__thiscall *Open)(IBaseFileSystem *, const char *, const char *, const char *); // edx
  void *v3; // edi
  int m_Next; // eax
  UtlLinkedListElem_t<CDTISendTable *,unsigned short> *v5; // ecx
  CDTISendTable *m_Element; // eax
  int v7; // eax
  UtlLinkedListElem_t<CDTISendTable *,unsigned short> *m_pMemory; // ecx
  int v9; // eax
  int v10; // esi
  __int64 v11; // rax
  unsigned int v12; // kr04_4
  const char *v13; // eax
  IFileSystem_vtbl *v14; // ecx
  int v15; // edx
  int v16; // eax
  int (*FPrintf)(IFileSystem *, void *, const char *, ...); // ecx
  double v18; // st7
  IFileSystem_vtbl *v19; // ecx
  IFileSystem_vtbl *v20; // edx
  void *v21; // esi
  int i; // edi
  int v23; // eax
  UtlLinkedListElem_t<CDTISendTable *,unsigned short> *v24; // ecx
  int v25; // eax
  CUtlString *v26; // edi
  const char *v27; // eax
  unsigned __int16 *v28; // edi
  long double v30; // [esp+44h] [ebp-ECh]
  long double v31; // [esp+4Ch] [ebp-E4h]
  long double v32; // [esp+6Ch] [ebp-C4h]
  unsigned int v33; // [esp+8Ch] [ebp-A4h]
  const char *v34; // [esp+D4h] [ebp-5Ch]
  unsigned __int64 v35; // [esp+D8h] [ebp-58h]
  unsigned __int64 v36; // [esp+E0h] [ebp-50h]
  unsigned __int64 v37; // [esp+E8h] [ebp-48h] BYREF
  unsigned __int64 v38; // [esp+F0h] [ebp-40h]
  int v39; // [esp+F8h] [ebp-38h]
  _QWORD v40[4]; // [esp+FCh] [ebp-34h] BYREF
  unsigned __int64 v41; // [esp+11Ch] [ebp-14h]
  int j; // [esp+124h] [ebp-Ch]
  unsigned __int64 v43; // [esp+128h] [ebp-8h]

  if ( g_pServerDTIFilename != nullptr )
  {
    j = (int)&v37;
    v37 = __rdtsc();
    v1 = v37 - LODWORD(g_ServerDTITimer.m_Int64);
    Open = g_pFileSystem->Open;
    v38 = v37 - g_ServerDTITimer.m_Int64;
    v3 = (void *)((int (__thiscall *)(IBaseFileSystem *, const char *, const char *, const char *, _DWORD, _DWORD))Open)(
                   a1: &g_pFileSystem->IBaseFileSystem,
                   a2: g_pServerDTIFilename,
                   a3: "wt",
                   a4: "LOGDIR",
                   a5: a1,
                   a6: HIDWORD(a1));
    if ( v3 != nullptr )
    {
      g_pFileSystem->FPrintf(
        this: g_pFileSystem,
        a2: v3,
        a3: "DTName\tCalcDelta calls\tCalcDelta ms\tEncode calls\tEncode ms\tShouldTransmit calls\tShouldTransmit ms\tWriteDe"
        "ltaProps ms\t%% manual mode\tTotal\tPercent\n");
      LOWORD(m_Next) = g_DTISendTables.m_Head;
      memset(v40, 0, sizeof(v40));
      if ( g_DTISendTables.m_Head != 0xFFFF )
      {
        do
        {
          v5 = &g_DTISendTables.m_Memory.m_pMemory[(unsigned __int16)m_Next];
          m_Element = v5->m_Element;
          v40[0] += v5->m_Element->m_nCalcDeltaCycles.m_Int64;
          v40[1] += m_Element->m_nEncodeCycles.m_Int64;
          v40[2] += m_Element->m_nShouldTransmitCycles.m_Int64;
          v40[3] += m_Element->m_nWriteDeltaPropsCycles.m_Int64;
          m_Next = v5->m_Next;
        }
        while ( m_Next != 0xFFFF );
        v1 = v38;
      }
      LOWORD(v7) = g_DTISendTables.m_Head;
      if ( g_DTISendTables.m_Head != 0xFFFF )
      {
        m_pMemory = g_DTISendTables.m_Memory.m_pMemory;
        do
        {
          v9 = 8 * (unsigned __int16)v7;
          v10 = *(int *)((char *)&m_pMemory->m_Element + v9);
          v39 = v9;
          if ( *(_DWORD *)(v10 + 24) != 0 || *(_DWORD *)(v10 + 40) != 0 || *(_DWORD *)(v10 + 56) != 0 )
          {
            v36 = *(_QWORD *)(v10 + 48);
            LODWORD(v35) = *(_DWORD *)(v10 + 32);
            LODWORD(v41) = *(_DWORD *)(v10 + 16);
            LODWORD(v11) = v41;
            HIDWORD(v11) = *(_DWORD *)(v10 + 36);
            HIDWORD(v41) = *(_DWORD *)(v10 + 20);
            v33 = v36 + v35 + v41;
            v12 = (v36 + __PAIR64__(HIDWORD(v41), v35) + v11) >> 32;
            HIDWORD(v35) = HIDWORD(v11);
            v31 = (double)v38 * _g_ClockSpeedMillisecondsMultiplier;
            v32 = (double)*(unsigned __int64 *)(v10 + 64) * _g_ClockSpeedMillisecondsMultiplier;
            v43 = v41 & 0x8000000000000000uLL;
            v30 = (double)v41 * _g_ClockSpeedMillisecondsMultiplier;
            v13 = CUtlString::operator char const *(this: (CUtlString *)v10);
            v14 = g_pFileSystem->IAppSystem::__vftable;
            v15 = *(_DWORD *)(v10 + 72);
            v34 = v13;
            j = *(_DWORD *)(v10 + 76);
            v16 = *(_DWORD *)(v10 + 56);
            FPrintf = v14->FPrintf;
            v18 = (double)j;
            j += v15;
            FPrintf(
              this: g_pFileSystem,
              a2: v3,
              a3: "%s\t%d\t%.3f\t%d\t%.3f\t%d\t%.3f\t%.3f\t%.2f\t%.3f\t%.3f\n",
              v34,
              *(_DWORD *)(v10 + 24),
              v30,
              *(_DWORD *)(v10 + 40),
              (double)v35 * _g_ClockSpeedMillisecondsMultiplier,
              v16,
              (double)v36 * _g_ClockSpeedMillisecondsMultiplier,
              v32,
              v18 * 100.0 / (double)j,
              (double)__PAIR64__(v12, v33) * _g_ClockSpeedMillisecondsMultiplier,
              (double)__PAIR64__(v12, v33) * _g_ClockSpeedMillisecondsMultiplier * 100.0 / v31);
            v9 = v39;
          }
          m_pMemory = g_DTISendTables.m_Memory.m_pMemory;
          v7 = *(unsigned __int16 *)((char *)&g_DTISendTables.m_Memory.m_pMemory->m_Next + v9);
        }
        while ( v7 != 0xFFFF );
        v1 = v38;
      }
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v3, a3: "\n\n");
      v43 = v38 & 0x8000000000000000uLL;
      v19 = g_pFileSystem->IAppSystem::__vftable;
      *(double *)&v41 = (double)__PAIR64__(HIDWORD(v38), v1);
      v19->FPrintf(
        this: g_pFileSystem,
        a2: v3,
        a3: "Total profile ms:\t%.3f\n",
        *(double *)&v41 * _g_ClockSpeedMillisecondsMultiplier);
      v43 = v40[0] & 0x8000000000000000uLL;
      g_pFileSystem->FPrintf(
        this: g_pFileSystem,
        a2: v3,
        a3: "Total CalcDelta ms:\t%.3f\tPercent:\t%.3f\n",
        (double)v40[0] * _g_ClockSpeedMillisecondsMultiplier,
        100.0
      * ((double)v40[0]
       * _g_ClockSpeedMillisecondsMultiplier)
      / (*(double *)&v41
       * _g_ClockSpeedMillisecondsMultiplier));
      v43 = v40[1] & 0x80000000FFFFFFFFuLL;
      v20 = g_pFileSystem->IAppSystem::__vftable;
      LODWORD(v43) = 0;
      v20->FPrintf(
        this: g_pFileSystem,
        a2: v3,
        a3: "Total Encode ms:\t%.3f\tPercent:\t%.3f\n",
        (double)v40[1] * _g_ClockSpeedMillisecondsMultiplier,
        100.0
      * ((double)v40[1]
       * _g_ClockSpeedMillisecondsMultiplier)
      / (*(double *)&v41
       * _g_ClockSpeedMillisecondsMultiplier));
      v43 = v40[2] & 0x8000000000000000uLL;
      g_pFileSystem->FPrintf(
        this: g_pFileSystem,
        a2: v3,
        a3: "Total ShouldTransmit ms:\t%.3f\tPercent:\t%.3f\n",
        (double)v40[2] * _g_ClockSpeedMillisecondsMultiplier,
        100.0
      * ((double)v40[2]
       * _g_ClockSpeedMillisecondsMultiplier)
      / (*(double *)&v41
       * _g_ClockSpeedMillisecondsMultiplier));
      v43 = v40[3] & 0x8000000000000000uLL;
      g_pFileSystem->FPrintf(
        this: g_pFileSystem,
        a2: v3,
        a3: "Total WriteDeltaProps ms:\t%.3f\tPercent:\t%.3f\n",
        (double)v40[3] * _g_ClockSpeedMillisecondsMultiplier,
        100.0
      * ((double)v40[3]
       * _g_ClockSpeedMillisecondsMultiplier)
      / (*(double *)&v41
       * _g_ClockSpeedMillisecondsMultiplier));
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
      _Msg(a1: "DTI: Wrote delta distances into %s.\n", g_pServerDTIFilename);
    }
    v21 = (void *)((int (__thiscall *)(IBaseFileSystem *, const char *))g_pFileSystem->Open)(
                    a1: &g_pFileSystem->IBaseFileSystem,
                    a2: "dti_delta_distances.txt");
    if ( v21 != nullptr )
    {
      ((void (__stdcall *)(IFileSystem *))g_pFileSystem->FPrintf)(a1: g_pFileSystem);
      for ( i = 200; i < 8200; i += 200 )
        g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v21, a3: "\t<%d", i);
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v21, a3: "\n");
      LOWORD(v23) = g_DTISendTables.m_Head;
      if ( g_DTISendTables.m_Head != 0xFFFF )
      {
        v24 = g_DTISendTables.m_Memory.m_pMemory;
        do
        {
          v25 = 8 * (unsigned __int16)v23;
          v26 = *(CUtlString **)((char *)&v24->m_Element + v25);
          v39 = v25;
          if ( v26[1].m_Storage.m_Memory.m_nGrowSize != 0
            || v26[2].m_Storage.m_Memory.m_nGrowSize != 0
            || v26[3].m_Storage.m_Memory.m_nGrowSize != 0 )
          {
            v27 = CUtlString::operator char const *(this: v26);
            g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v21, a3: "%s", v27);
            v28 = (unsigned __int16 *)&v26[5];
            for ( j = 40; j != 0; --j )
              g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v21, a3: "\t%d", *v28++);
            g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v21, a3: "\n");
            v24 = g_DTISendTables.m_Memory.m_pMemory;
            v25 = v39;
          }
          v23 = *(unsigned __int16 *)((char *)&v24->m_Next + v25);
        }
        while ( v23 != 0xFFFF );
      }
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v21);
      _Msg(a1: "DTI: Wrote instrumentation data into %s.\n", "dti_delta_distances.txt");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016DED0
// Name: void ServerDTI_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ServerDTI_Term(__int64 a1@<esi:edi>)
{
  if ( g_pServerDTIFilename != nullptr )
  {
    ServerDTI_Flush(a1);
    CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(this: &g_DTISendTables);
    g_pServerDTIFilename = nullptr;
    g_bServerDTIEnabled = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016DF00
// Name: class CDTISendTable __near * ServerDTI_HookTable(class SendTable __near *)
// Source: json
//------------------------------------------------------------------------------
CDTISendTable *__cdecl ServerDTI_HookTable(SendTable *pTable)
{
  CUtlString *v2; // eax
  CUtlString *v3; // esi
  unsigned __int16 v4; // ax
  int v5; // edi
  UtlLinkedListElem_t<CDTISendTable *,unsigned short> *v6; // eax

  if ( !g_bServerDTIEnabled )
    return nullptr;
  v2 = (CUtlString *)MemAlloc_Alloc(nSize: 0xA0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CUtlString::CUtlString(this: v2);
    v3[1].m_Storage.m_Memory.m_pMemory = nullptr;
    v3[1].m_Storage.m_Memory.m_nAllocationCount = 0;
    v3[2].m_Storage.m_Memory.m_pMemory = nullptr;
    v3[2].m_Storage.m_Memory.m_nAllocationCount = 0;
    v3[3].m_Storage.m_Memory.m_pMemory = nullptr;
    v3[3].m_Storage.m_Memory.m_nAllocationCount = 0;
    v3[4].m_Storage.m_Memory.m_pMemory = nullptr;
    v3[4].m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  else
  {
    v3 = nullptr;
  }
  memset(dst: (unsigned __int8 *)v3, value: 0, count: 0xA0u);
  CUtlString::Set(this: v3, pValue: pTable->m_pNetTableName);
  v4 = CUtlLinkedList<CDTISendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDTISendTable *,unsigned short>,unsigned short>>::AllocInternal(
         this: &g_DTISendTables,
         multilist: false);
  v5 = v4;
  if ( v4 != 0xFFFF )
  {
    CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_DTISendTables,
      before: 0xFFFFu,
      elem: v4);
    v6 = &g_DTISendTables.m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
      v6->m_Element = (CDTISendTable *)v3;
  }
  return (CDTISendTable *)v3;
}

} // namespace engine_xlsp
