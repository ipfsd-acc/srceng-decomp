// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_parse_event.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1008CF40
// Name: void CL_DescribeEvent(int,class CEventInfo __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_DescribeEvent(int slot, CEventInfo *event, const char *eventname)
{
  int v3; // eax
  CClientState *BaseLocalClient; // eax
  double Time; // st7
  CClientState *v6; // eax
  double v7; // st7
  int v8; // [esp-Ch] [ebp-28h]
  int v9; // [esp-Ch] [ebp-28h]
  con_nprint_s info; // [esp+0h] [ebp-1Ch] BYREF
  char v11; // [esp+18h] [ebp-4h]

  if ( cl_showevents.m_pParent != nullptr && cl_showevents.m_pParent->m_Value.m_nValue != 0 && eventname != nullptr )
  {
    LODWORD(info.time_to_live) = slot & 0x1F;
    v3 = event->bits + 7;
    info.color[0] = 4.0;
    v8 = v3 >> 3;
    info.color[1] = 0.80000001;
    info.color[2] = 0.80000001;
    v11 = 1;
    *(_DWORD *)&info.fixed_width_font = 1065353216;
    BaseLocalClient = GetBaseLocalClient();
    Time = CClientState::GetTime(this: BaseLocalClient);
    Con_NXPrintf(
      info: (con_nprint_s *)&info.time_to_live,
      fmt: "%02i %6.3ff %20s %03i bytes",
      slot,
      Time,
      eventname,
      v8);
    if ( cl_showevents.m_pParent != nullptr && cl_showevents.m_pParent->m_Value.m_nValue == 2 )
    {
      v9 = (event->bits + 7) >> 3;
      v6 = GetBaseLocalClient();
      v7 = CClientState::GetTime(this: v6);
      DevMsg(a1: "%02i %6.3ff %20s %03i bytes\n", slot, v7, eventname, v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D020
// Name: void CL_ParseEventDelta(void __near *,void __near *,class RecvTable __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_ParseEventDelta(const unsigned int *RawData, void *pToData, RecvTable *pRecvTable)
{
  bf_read fromBuf; // [esp+8h] [ebp-24h] BYREF

  fromBuf.m_bOverflow = false;
  fromBuf.m_nDataBytes = 0;
  fromBuf.m_nDataBits = -1;
  fromBuf.m_pDebugName = "CL_ParseEventDelta->fromBuf";
  CBitRead::StartReading(this: &fromBuf, pData: RawData, nBytes: 0xC0u, iStartBit: 0, nBits: -1);
  RecvTable_DecodeZeros(pTable: pRecvTable, pStruct: pToData, objectID: -1);
  RecvTable_Decode(pTable: pRecvTable, pStruct: pToData, pIn: &fromBuf, objectID: -1);
}

//------------------------------------------------------------------------------
// Address: 0x1008D300
// Name: void CL_FireEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_FireEvents()
{
  CClientState *BaseLocalClient; // eax
  CClientState *v1; // edi
  IMDLCache *v2; // ebx
  __int16 *m_Head; // esi
  __int16 *v4; // ebx
  int (*v5)(void); // eax
  int v6; // eax
  int v7; // edi
  void *v8; // eax
  RecvTable *v9; // [esp-Ch] [ebp-18h]
  IMDLCache *cacheCriticalSection; // [esp+4h] [ebp-8h]
  CClientState *v11; // [esp+8h] [ebp-4h]

  BaseLocalClient = GetBaseLocalClient();
  v1 = BaseLocalClient;
  v11 = BaseLocalClient;
  if ( BaseLocalClient->m_nSignonState != 6 )
  {
    CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::RemoveAll(this: &BaseLocalClient->events);
    return;
  }
  v2 = g_pMDLCache;
  cacheCriticalSection = g_pMDLCache;
  g_pMDLCache->BeginLock(this: g_pMDLCache);
  m_Head = (__int16 *)v1->events.m_Head;
  if ( m_Head == nullptr )
    goto LABEL_15;
  do
  {
    v4 = *((__int16 **)m_Head + 15);
    if ( *m_Head == 0 )
      goto LABEL_12;
    if ( *((float *)m_Head + 1) == 0.0 || *((float *)m_Head + 1) <= CClientState::GetTime(this: v1) )
    {
      v5 = *(int (**)(void))(*((_DWORD *)m_Head + 3) + 4);
      if ( v5 != nullptr )
      {
        v6 = v5();
        v7 = v6;
        if ( v6 != 0 )
        {
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 24))(a1: v6, a2: 0);
          v9 = *(RecvTable **)(*((_DWORD *)m_Head + 3) + 12);
          v8 = (void *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 48))(a1: v7);
          CL_ParseEventDelta(RawData: *((const unsigned int **)m_Head + 5), pToData: v8, pRecvTable: v9);
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 28))(a1: v7, a2: 0);
          CL_DescribeEvent(
            slot: (int)m_Head,
            event: (CEventInfo *)m_Head,
            eventname: *(const char **)(*((_DWORD *)m_Head + 3) + 8));
          v1 = v11;
LABEL_12:
          CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::Free(
            this: &v1->events,
            elem: (int)m_Head);
          goto LABEL_13;
        }
        v1 = v11;
      }
      _ConDMsg(a1: "Failed to execute event for classId %i\n", *m_Head - 1);
      goto LABEL_12;
    }
LABEL_13:
    m_Head = v4;
  }
  while ( v4 != nullptr );
  v2 = cacheCriticalSection;
LABEL_15:
  v2->EndLock(this: v2);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1008CC70
// Name: void CL_DescribeEvent(int,class CEventInfo __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_DescribeEvent(int slot, CEventInfo *event, const char *eventname)
{
  int v3; // eax
  CClientState *BaseLocalClient; // eax
  double Time; // st7
  CClientState *v6; // eax
  double v7; // st7
  int v8; // [esp+Ch] [ebp-28h]
  int v9; // [esp+Ch] [ebp-28h]
  con_nprint_s n; // [esp+1Ch] [ebp-18h] BYREF

  if ( cl_showevents.m_pParent != nullptr && cl_showevents.m_pParent->m_Value.m_nValue != 0 && eventname != nullptr )
  {
    n.index = slot & 0x1F;
    v3 = event->bits + 7;
    n.time_to_live = 4.0;
    v8 = v3 >> 3;
    n.color[0] = 0.80000001;
    n.color[1] = 0.80000001;
    n.fixed_width_font = true;
    n.color[2] = 1.0;
    BaseLocalClient = GetBaseLocalClient();
    Time = CClientState::GetTime(this: BaseLocalClient);
    Con_NXPrintf(info: &n, fmt: "%02i %6.3ff %20s %03i bytes", slot, Time, eventname, v8);
    if ( cl_showevents.m_pParent != nullptr && cl_showevents.m_pParent->m_Value.m_nValue == 2 )
    {
      v9 = (event->bits + 7) >> 3;
      v6 = GetBaseLocalClient();
      v7 = CClientState::GetTime(this: v6);
      DevMsg(a1: "%02i %6.3ff %20s %03i bytes\n", slot, v7, eventname, v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008CD50
// Name: void CL_ParseEventDelta(void __near *,void __near *,class RecvTable __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_ParseEventDelta(void *RawData, void *pToData, RecvTable *pRecvTable)
{
  bf_read fromBuf; // [esp+8h] [ebp-24h] BYREF

  fromBuf.m_bOverflow = false;
  fromBuf.m_nDataBytes = 0;
  fromBuf.m_nDataBits = -1;
  fromBuf.m_pDebugName = "CL_ParseEventDelta->fromBuf";
  CBitRead::StartReading(this: &fromBuf, pData: RawData, nBytes: 192, iStartBit: 0, nBits: -1);
  RecvTable_DecodeZeros(pTable: pRecvTable, pStruct: pToData, objectID: -1);
  RecvTable_Decode(pTable: pRecvTable, pStruct: pToData, pIn: &fromBuf, objectID: -1);
}

//------------------------------------------------------------------------------
// Address: 0x1008CFB0
// Name: void CL_FireEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_FireEvents()
{
  CClientState *BaseLocalClient; // eax
  CClientState *v1; // edi
  IMDLCache *v2; // ebx
  CEventInfo *m_Head; // esi
  float fire_delay; // ebx
  int (*m_pCreateEventFn)(void); // eax
  int v6; // eax
  int v7; // edi
  void *v8; // eax
  RecvTable *m_pRecvTable; // [esp-Ch] [ebp-18h]
  IMDLCache *cacheCriticalSection; // [esp+4h] [ebp-8h]
  CClientState *v11; // [esp+8h] [ebp-4h]

  BaseLocalClient = GetBaseLocalClient();
  v1 = BaseLocalClient;
  v11 = BaseLocalClient;
  if ( BaseLocalClient->m_nSignonState != 6 )
  {
    CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::RemoveAll(this: &BaseLocalClient->events);
    return;
  }
  v2 = g_pMDLCache;
  cacheCriticalSection = g_pMDLCache;
  g_pMDLCache->BeginLock(this: g_pMDLCache);
  m_Head = (CEventInfo *)v1->events.m_Head;
  if ( m_Head == nullptr )
    goto LABEL_15;
  do
  {
    fire_delay = m_Head[1].fire_delay;
    if ( m_Head->classID == 0 )
      goto LABEL_12;
    if ( m_Head->fire_delay == 0.0 || (double)m_Head->fire_delay <= CClientState::GetTime(this: v1) )
    {
      m_pCreateEventFn = (int (*)(void))m_Head->pClientClass->m_pCreateEventFn;
      if ( m_pCreateEventFn != nullptr )
      {
        v6 = m_pCreateEventFn();
        v7 = v6;
        if ( v6 != 0 )
        {
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 24))(a1: v6, a2: 0);
          m_pRecvTable = m_Head->pClientClass->m_pRecvTable;
          v8 = (void *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 48))(a1: v7);
          CL_ParseEventDelta(RawData: m_Head->pData, pToData: v8, pRecvTable: m_pRecvTable);
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 28))(a1: v7, a2: 0);
          CL_DescribeEvent(slot: (int)m_Head, event: m_Head, eventname: m_Head->pClientClass->m_pNetworkName);
          v1 = v11;
LABEL_12:
          CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::Free(
            this: &v1->events,
            elem: (int)m_Head);
          goto LABEL_13;
        }
        v1 = v11;
      }
      _ConDMsg(a1: "Failed to execute event for classId %i\n", m_Head->classID - 1);
      goto LABEL_12;
    }
LABEL_13:
    m_Head = (CEventInfo *)LODWORD(fire_delay);
  }
  while ( fire_delay != 0.0 );
  v2 = cacheCriticalSection;
LABEL_15:
  v2->EndLock(this: v2);
}

} // namespace engine_xlsp
