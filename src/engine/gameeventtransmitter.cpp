// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/gameeventtransmitter.cpp
// Functions: 3
// ============================================================

#include "engine\gameeventtransmitter.h"

//------------------------------------------------------------------------------
// Address: 0x1017CD60
// Name: public: bool CGameEventTransmitter::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventTransmitter::Init(CGameEventTransmitter *this)
{
  int v2; // eax
  const char *v3; // eax

  v2 = _CommandLine();
  v3 = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v2 + 32))(
                       a1: v2,
                       a2: "-transmitevents",
                       a3: defaultValue);
  if ( *v3 != 0 )
  {
    netadr_s::SetFromString(this: &this->m_Adr, pch: v3, bUseDNS: false);
    netadr_s::IsValid(this: &this->m_Adr);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017CDA0
// Name: public: void CGameEventTransmitter::TransmitGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventTransmitter::TransmitGameEvent(CGameEventTransmitter *this, IGameEvent *event)
{
  const char *v3; // edi
  const char *v4; // eax
  unsigned __int8 buffer_data[1024]; // [esp+4h] [ebp-418h] BYREF
  bf_write eventData; // [esp+404h] [ebp-18h] BYREF

  if ( netadr_s::IsValid(this: &this->m_Adr) && event != nullptr && !event->IsLocal(this: event) )
  {
    v3 = event->GetName(this: event);
    bf_write::bf_write(this: &eventData);
    bf_write::StartWriting(this: &eventData, pData: buffer_data, nBytes: 1024, iStartBit: 0, nBits: -1);
    bf_write::WriteString(this: &eventData, pStr: v3);
    if ( g_GameEventManager->SerializeEvent(this: g_GameEventManager, a2: event, a3: &eventData) )
    {
      NET_SendPacket(
        chan: nullptr,
        sock: 0,
        to: &this->m_Adr,
        data: buffer_data,
        length: (eventData.m_iCurBit + 7) >> 3,
        pVoicePayload: nullptr,
        bUseCompression: false,
        unMillisecondsDelay: 0);
    }
    else
    {
      v4 = event->GetName(this: event);
      DevMsg(a1: "GameEventTransmitter: failed to serialize event '%s'.\n", v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017CE70
// Name: void CC_TransmitEvents(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_TransmitEvents(const CCommand *args)
{
  int m_nArgv0Size; // eax
  bool v2; // zf
  char *v3; // eax
  CGameEventTransmitter *v4; // edi
  int v5; // eax
  const char *v6; // eax
  int v7; // eax
  const char *v8; // eax

  m_nArgv0Size = args->m_nArgv0Size;
  v2 = m_nArgv0Size == 0;
  v3 = &args->m_pArgSBuffer[m_nArgv0Size];
  if ( v2 )
    v3 = (char *)defaultValue;
  v4 = g_GameEventTransmitter;
  netadr_s::SetFromString(this: &g_GameEventTransmitter->m_Adr, pch: v3, bUseDNS: 0);
  if ( netadr_s::IsValid(this: &v4->m_Adr) )
  {
    v7 = args->m_nArgv0Size;
    v2 = v7 == 0;
    v8 = &args->m_pArgSBuffer[v7];
    if ( v2 )
      v8 = defaultValue;
    _Msg(a1: "SUCCESS! address and port is now set to: %s\n", v8);
  }
  else if ( args->m_nArgc <= 1 )
  {
    _Msg(a1: "No address and port passed in.\n");
  }
  else
  {
    v5 = args->m_nArgv0Size;
    v2 = v5 == 0;
    v6 = &args->m_pArgSBuffer[v5];
    if ( v2 )
      v6 = defaultValue;
    _Msg(a1: "Invalid address or port: %s\n", v6);
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1017D120
// Name: public: bool CGameEventTransmitter::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameEventTransmitter::Init(CGameEventTransmitter *this)
{
  int v2; // eax
  const char *v3; // eax
  int v5; // [esp+0h] [ebp-4h]

  v2 = _CommandLine(a1: v5);
  v3 = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v2 + 32))(
                       a1: v2,
                       a2: "-transmitevents",
                       a3: defaultValue);
  if ( *v3 != 0 )
  {
    netadr_s::SetFromString(this: &this->m_Adr, pch: v3, bUseDNS: false);
    netadr_s::IsValid(this: &this->m_Adr);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017D160
// Name: public: void CGameEventTransmitter::TransmitGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameEventTransmitter::TransmitGameEvent(CGameEventTransmitter *this, IGameEvent *event)
{
  const char *v3; // edi
  const char *v4; // eax
  unsigned __int8 buffer_data[1024]; // [esp+4h] [ebp-418h] BYREF
  bf_write eventData; // [esp+404h] [ebp-18h] BYREF

  if ( netadr_s::IsValid(this: &this->m_Adr) && event != nullptr && !event->IsLocal(this: event) )
  {
    v3 = event->GetName(this: event);
    bf_write::bf_write(this: &eventData);
    bf_write::StartWriting(this: &eventData, pData: buffer_data, nBytes: 1024, iStartBit: 0, nBits: -1);
    bf_write::WriteString(this: &eventData, pStr: v3);
    if ( g_GameEventManager->SerializeEvent(this: g_GameEventManager, a2: event, a3: &eventData) )
    {
      NET_SendPacket(
        chan: nullptr,
        sock: 0,
        to: &this->m_Adr,
        data: buffer_data,
        length: (eventData.m_iCurBit + 7) >> 3,
        pVoicePayload: nullptr,
        bUseCompression: false,
        unMillisecondsDelay: 0);
    }
    else
    {
      v4 = event->GetName(this: event);
      DevMsg(a1: "GameEventTransmitter: failed to serialize event '%s'.\n", v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017D230
// Name: void CC_TransmitEvents(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_TransmitEvents(const CCommand *args)
{
  int m_nArgv0Size; // eax
  bool v2; // zf
  const char *v3; // eax
  CGameEventTransmitter *v4; // edi
  int v5; // eax
  const char *v6; // eax
  int v7; // eax
  const char *v8; // eax

  m_nArgv0Size = args->m_nArgv0Size;
  v2 = m_nArgv0Size == 0;
  v3 = &args->m_pArgSBuffer[m_nArgv0Size];
  if ( v2 )
    v3 = defaultValue;
  v4 = g_GameEventTransmitter;
  netadr_s::SetFromString(this: &g_GameEventTransmitter->m_Adr, pch: v3, bUseDNS: false);
  if ( netadr_s::IsValid(this: &v4->m_Adr) )
  {
    v7 = args->m_nArgv0Size;
    v2 = v7 == 0;
    v8 = &args->m_pArgSBuffer[v7];
    if ( v2 )
      v8 = defaultValue;
    _Msg(a1: "SUCCESS! address and port is now set to: %s\n", v8);
  }
  else if ( args->m_nArgc <= 1 )
  {
    _Msg(a1: "No address and port passed in.\n");
  }
  else
  {
    v5 = args->m_nArgv0Size;
    v2 = v5 == 0;
    v6 = &args->m_pArgSBuffer[v5];
    if ( v2 )
      v6 = defaultValue;
    _Msg(a1: "Invalid address or port: %s\n", v6);
  }
}

} // namespace engine_xlsp
