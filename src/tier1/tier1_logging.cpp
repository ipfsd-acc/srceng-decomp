// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/tier1_logging.cpp
// Functions: 3
// ============================================================

#include "tier1\tier1_logging.h"

//------------------------------------------------------------------------------
// Address: 0x1025C6C0
// Name: public: CBufferedLoggingListener::CBufferedLoggingListener(void)
// Source: json
//------------------------------------------------------------------------------
CBufferedLoggingListener *__thiscall CBufferedLoggingListener::CBufferedLoggingListener(CBufferedLoggingListener *this)
{
  this->__vftable = (CBufferedLoggingListener_vtbl *)&CBufferedLoggingListener::`vftable';
  CUtlBuffer::CUtlBuffer(this: &this->m_StoredSpew, growSize: 0, initSize: 512, nFlags: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1025C6E0
// Name: public: virtual void CBufferedLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBufferedLoggingListener::Log(
        CBufferedLoggingListener *this,
        const LoggingContext_t *pContext,
        char *pMessage)
{
  CUtlBuffer *p_m_StoredSpew; // esi
  unsigned __int8 v4; // bl
  int m_Put; // eax
  unsigned __int8 v6; // bl
  int v7; // eax
  unsigned __int8 v8; // bl
  int v9; // eax
  unsigned __int8 v10; // bl
  int v11; // eax
  int m_ChannelID; // [esp-4h] [ebp-10h]
  LoggingSeverity_t m_Severity; // [esp-4h] [ebp-10h]

  p_m_StoredSpew = &this->m_StoredSpew;
  m_ChannelID = pContext->m_ChannelID;
  if ( (this->m_StoredSpew.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &this->m_StoredSpew, pFmt: "%d", m_ChannelID);
  else
    CUtlBuffer::PutTypeBin<int>(this: &this->m_StoredSpew, src: m_ChannelID);
  m_Severity = pContext->m_Severity;
  if ( (p_m_StoredSpew->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: p_m_StoredSpew, pFmt: "%d", m_Severity);
  else
    CUtlBuffer::PutTypeBin<int>(this: p_m_StoredSpew, src: m_Severity);
  v4 = pContext->m_Color._color[0];
  if ( (p_m_StoredSpew->m_Flags & 1) != 0 )
  {
    m_Put = p_m_StoredSpew->m_Put;
    if ( m_Put != 0 && p_m_StoredSpew->m_Memory.m_pMemory[m_Put - p_m_StoredSpew->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: p_m_StoredSpew);
  }
  if ( CUtlBuffer::CheckPut(this: p_m_StoredSpew, nSize: 1) != 0 )
  {
    p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Put++ - p_m_StoredSpew->m_nOffset] = v4;
    CUtlBuffer::AddNullTermination(this: p_m_StoredSpew, nPut: p_m_StoredSpew->m_Put);
  }
  v6 = pContext->m_Color._color[1];
  if ( (p_m_StoredSpew->m_Flags & 1) != 0 )
  {
    v7 = p_m_StoredSpew->m_Put;
    if ( v7 != 0 && p_m_StoredSpew->m_Memory.m_pMemory[v7 - p_m_StoredSpew->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: p_m_StoredSpew);
  }
  if ( CUtlBuffer::CheckPut(this: p_m_StoredSpew, nSize: 1) != 0 )
  {
    p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Put++ - p_m_StoredSpew->m_nOffset] = v6;
    CUtlBuffer::AddNullTermination(this: p_m_StoredSpew, nPut: p_m_StoredSpew->m_Put);
  }
  v8 = pContext->m_Color._color[2];
  if ( (p_m_StoredSpew->m_Flags & 1) != 0 )
  {
    v9 = p_m_StoredSpew->m_Put;
    if ( v9 != 0 && p_m_StoredSpew->m_Memory.m_pMemory[v9 - p_m_StoredSpew->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: p_m_StoredSpew);
  }
  if ( CUtlBuffer::CheckPut(this: p_m_StoredSpew, nSize: 1) != 0 )
  {
    p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Put++ - p_m_StoredSpew->m_nOffset] = v8;
    CUtlBuffer::AddNullTermination(this: p_m_StoredSpew, nPut: p_m_StoredSpew->m_Put);
  }
  v10 = pContext->m_Color._color[3];
  if ( (p_m_StoredSpew->m_Flags & 1) != 0 )
  {
    v11 = p_m_StoredSpew->m_Put;
    if ( v11 != 0 && p_m_StoredSpew->m_Memory.m_pMemory[v11 - p_m_StoredSpew->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: p_m_StoredSpew);
  }
  if ( CUtlBuffer::CheckPut(this: p_m_StoredSpew, nSize: 1) != 0 )
  {
    p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Put++ - p_m_StoredSpew->m_nOffset] = v10;
    CUtlBuffer::AddNullTermination(this: p_m_StoredSpew, nPut: p_m_StoredSpew->m_Put);
  }
  CUtlBuffer::PutString(this: p_m_StoredSpew, pString: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x1025C880
// Name: public: void CBufferedLoggingListener::EmitBufferedSpew(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBufferedLoggingListener::EmitBufferedSpew(CBufferedLoggingListener *this)
{
  CUtlBuffer *p_m_StoredSpew; // esi
  int v2; // eax
  int v3; // eax
  unsigned __int8 v4; // bl
  unsigned __int8 v5; // al
  int v6; // edi
  void *v7; // esp
  char v8[12]; // [esp+0h] [ebp-1Ch] BYREF
  int channelID; // [esp+Ch] [ebp-10h]
  LoggingSeverity_t severity; // [esp+10h] [ebp-Ch]
  Color color; // [esp+14h] [ebp-8h]
  unsigned __int8 v12; // [esp+1Ah] [ebp-2h]
  unsigned __int8 v13; // [esp+1Bh] [ebp-1h]

  p_m_StoredSpew = &this->m_StoredSpew;
  if ( this->m_StoredSpew.m_nMaxPut - this->m_StoredSpew.m_Get > 0 )
  {
    do
    {
      channelID = CUtlBuffer::GetInt(this: p_m_StoredSpew);
      severity = CUtlBuffer::GetInt(this: p_m_StoredSpew);
      if ( CUtlBuffer::CheckGet(this: p_m_StoredSpew, nSize: 1) )
      {
        v2 = p_m_StoredSpew->m_Get + 1;
        v13 = p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Get - p_m_StoredSpew->m_nOffset];
        p_m_StoredSpew->m_Get = v2;
      }
      else
      {
        v13 = 0;
      }
      if ( CUtlBuffer::CheckGet(this: p_m_StoredSpew, nSize: 1) )
      {
        v3 = p_m_StoredSpew->m_Get + 1;
        v12 = p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Get - p_m_StoredSpew->m_nOffset];
        p_m_StoredSpew->m_Get = v3;
      }
      else
      {
        v12 = 0;
      }
      if ( CUtlBuffer::CheckGet(this: p_m_StoredSpew, nSize: 1) )
      {
        v4 = p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Get - p_m_StoredSpew->m_nOffset];
        ++p_m_StoredSpew->m_Get;
      }
      else
      {
        v4 = 0;
      }
      if ( CUtlBuffer::CheckGet(this: p_m_StoredSpew, nSize: 1) )
      {
        v5 = p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Get - p_m_StoredSpew->m_nOffset];
        ++p_m_StoredSpew->m_Get;
      }
      else
      {
        v5 = 0;
      }
      color._color[0] = v13;
      color._color[1] = v12;
      color._color[2] = v4;
      color._color[3] = v5;
      v6 = CUtlBuffer::PeekStringLength(this: p_m_StoredSpew);
      if ( v6 != 0 )
      {
        v7 = alloca(v6);
        CUtlBuffer::GetString(this: p_m_StoredSpew, pString: v8, nMaxChars: v6);
        ((void (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_LogDirect)(
          a1: channelID,
          a2: severity,
          a3: color,
          a4: v8);
      }
    }
    while ( p_m_StoredSpew->m_nMaxPut - p_m_StoredSpew->m_Get > 0 );
  }
  p_m_StoredSpew->m_Get = 0;
  p_m_StoredSpew->m_Put = 0;
  p_m_StoredSpew->m_Error = 0;
  p_m_StoredSpew->m_nOffset = 0;
  p_m_StoredSpew->m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: p_m_StoredSpew, nPut: 0);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005C4120
// Name: public: CBufferedLoggingListener::CBufferedLoggingListener(void)
// Source: json
//------------------------------------------------------------------------------
CBufferedLoggingListener *__thiscall CBufferedLoggingListener::CBufferedLoggingListener(CBufferedLoggingListener *this)
{
  this->__vftable = (CBufferedLoggingListener_vtbl *)&CBufferedLoggingListener::`vftable';
  CUtlBuffer::CUtlBuffer(this: &this->m_StoredSpew, growSize: 0, initSize: 512, nFlags: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005C4140
// Name: public: virtual void CBufferedLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBufferedLoggingListener::Log(
        CBufferedLoggingListener *this,
        const LoggingContext_t *pContext,
        char *pMessage)
{
  CUtlBuffer *p_m_StoredSpew; // esi
  unsigned __int8 v4; // bl
  int m_Put; // eax
  unsigned __int8 v6; // bl
  int v7; // eax
  unsigned __int8 v8; // bl
  int v9; // eax
  unsigned __int8 v10; // bl
  int v11; // eax
  int m_ChannelID; // [esp-4h] [ebp-10h]
  LoggingSeverity_t m_Severity; // [esp-4h] [ebp-10h]

  p_m_StoredSpew = &this->m_StoredSpew;
  m_ChannelID = pContext->m_ChannelID;
  if ( (this->m_StoredSpew.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &this->m_StoredSpew, pFmt: "%d", m_ChannelID);
  else
    CUtlBuffer::PutTypeBin<int>(this: &this->m_StoredSpew, src: m_ChannelID);
  m_Severity = pContext->m_Severity;
  if ( (p_m_StoredSpew->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: p_m_StoredSpew, pFmt: "%d", m_Severity);
  else
    CUtlBuffer::PutTypeBin<int>(this: p_m_StoredSpew, src: m_Severity);
  v4 = pContext->m_Color._color[0];
  if ( (p_m_StoredSpew->m_Flags & 1) != 0 )
  {
    m_Put = p_m_StoredSpew->m_Put;
    if ( m_Put != 0 && p_m_StoredSpew->m_Memory.m_pMemory[m_Put - p_m_StoredSpew->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: p_m_StoredSpew);
  }
  if ( CUtlBuffer::CheckPut(this: p_m_StoredSpew, nSize: 1) != 0 )
  {
    p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Put++ - p_m_StoredSpew->m_nOffset] = v4;
    CUtlBuffer::AddNullTermination(this: p_m_StoredSpew, nPut: p_m_StoredSpew->m_Put);
  }
  v6 = pContext->m_Color._color[1];
  if ( (p_m_StoredSpew->m_Flags & 1) != 0 )
  {
    v7 = p_m_StoredSpew->m_Put;
    if ( v7 != 0 && p_m_StoredSpew->m_Memory.m_pMemory[v7 - p_m_StoredSpew->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: p_m_StoredSpew);
  }
  if ( CUtlBuffer::CheckPut(this: p_m_StoredSpew, nSize: 1) != 0 )
  {
    p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Put++ - p_m_StoredSpew->m_nOffset] = v6;
    CUtlBuffer::AddNullTermination(this: p_m_StoredSpew, nPut: p_m_StoredSpew->m_Put);
  }
  v8 = pContext->m_Color._color[2];
  if ( (p_m_StoredSpew->m_Flags & 1) != 0 )
  {
    v9 = p_m_StoredSpew->m_Put;
    if ( v9 != 0 && p_m_StoredSpew->m_Memory.m_pMemory[v9 - p_m_StoredSpew->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: p_m_StoredSpew);
  }
  if ( CUtlBuffer::CheckPut(this: p_m_StoredSpew, nSize: 1) != 0 )
  {
    p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Put++ - p_m_StoredSpew->m_nOffset] = v8;
    CUtlBuffer::AddNullTermination(this: p_m_StoredSpew, nPut: p_m_StoredSpew->m_Put);
  }
  v10 = pContext->m_Color._color[3];
  if ( (p_m_StoredSpew->m_Flags & 1) != 0 )
  {
    v11 = p_m_StoredSpew->m_Put;
    if ( v11 != 0 && p_m_StoredSpew->m_Memory.m_pMemory[v11 - p_m_StoredSpew->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: p_m_StoredSpew);
  }
  if ( CUtlBuffer::CheckPut(this: p_m_StoredSpew, nSize: 1) != 0 )
  {
    p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Put++ - p_m_StoredSpew->m_nOffset] = v10;
    CUtlBuffer::AddNullTermination(this: p_m_StoredSpew, nPut: p_m_StoredSpew->m_Put);
  }
  CUtlBuffer::PutString(this: p_m_StoredSpew, pString: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x005C42E0
// Name: public: void CBufferedLoggingListener::EmitBufferedSpew(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBufferedLoggingListener::EmitBufferedSpew(CBufferedLoggingListener *this)
{
  CUtlBuffer *p_m_StoredSpew; // esi
  int v2; // eax
  int v3; // eax
  unsigned __int8 v4; // bl
  unsigned __int8 v5; // al
  int v6; // edi
  void *v7; // esp
  char v8[12]; // [esp+0h] [ebp-1Ch] BYREF
  int channelID; // [esp+Ch] [ebp-10h]
  LoggingSeverity_t severity; // [esp+10h] [ebp-Ch]
  Color color; // [esp+14h] [ebp-8h]
  unsigned __int8 v12; // [esp+1Ah] [ebp-2h]
  unsigned __int8 v13; // [esp+1Bh] [ebp-1h]

  p_m_StoredSpew = &this->m_StoredSpew;
  if ( this->m_StoredSpew.m_nMaxPut - this->m_StoredSpew.m_Get > 0 )
  {
    do
    {
      channelID = CUtlBuffer::GetInt(this: p_m_StoredSpew);
      severity = CUtlBuffer::GetInt(this: p_m_StoredSpew);
      if ( CUtlBuffer::CheckGet(this: p_m_StoredSpew, nSize: 1) )
      {
        v2 = p_m_StoredSpew->m_Get + 1;
        v13 = p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Get - p_m_StoredSpew->m_nOffset];
        p_m_StoredSpew->m_Get = v2;
      }
      else
      {
        v13 = 0;
      }
      if ( CUtlBuffer::CheckGet(this: p_m_StoredSpew, nSize: 1) )
      {
        v3 = p_m_StoredSpew->m_Get + 1;
        v12 = p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Get - p_m_StoredSpew->m_nOffset];
        p_m_StoredSpew->m_Get = v3;
      }
      else
      {
        v12 = 0;
      }
      if ( CUtlBuffer::CheckGet(this: p_m_StoredSpew, nSize: 1) )
      {
        v4 = p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Get - p_m_StoredSpew->m_nOffset];
        ++p_m_StoredSpew->m_Get;
      }
      else
      {
        v4 = 0;
      }
      if ( CUtlBuffer::CheckGet(this: p_m_StoredSpew, nSize: 1) )
      {
        v5 = p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Get - p_m_StoredSpew->m_nOffset];
        ++p_m_StoredSpew->m_Get;
      }
      else
      {
        v5 = 0;
      }
      color._color[0] = v13;
      color._color[1] = v12;
      color._color[2] = v4;
      color._color[3] = v5;
      v6 = CUtlBuffer::PeekStringLength(this: p_m_StoredSpew);
      if ( v6 != 0 )
      {
        v7 = alloca(v6);
        CUtlBuffer::GetString(this: p_m_StoredSpew, pString: v8, nMaxChars: v6);
        ((void (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_LogDirect)(
          a1: channelID,
          a2: severity,
          a3: color,
          a4: v8);
      }
    }
    while ( p_m_StoredSpew->m_nMaxPut - p_m_StoredSpew->m_Get > 0 );
  }
  p_m_StoredSpew->m_Get = 0;
  p_m_StoredSpew->m_Put = 0;
  p_m_StoredSpew->m_Error = 0;
  p_m_StoredSpew->m_nOffset = 0;
  p_m_StoredSpew->m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: p_m_StoredSpew, nPut: 0);
}

} // namespace mdlcompile

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005BCD20
// Name: public: CBufferedLoggingListener::CBufferedLoggingListener(void)
// Source: json
//------------------------------------------------------------------------------
CBufferedLoggingListener *__thiscall CBufferedLoggingListener::CBufferedLoggingListener(CBufferedLoggingListener *this)
{
  this->__vftable = (CBufferedLoggingListener_vtbl *)&CBufferedLoggingListener::`vftable';
  CUtlBuffer::CUtlBuffer(this: &this->m_StoredSpew, growSize: 0, initSize: 512, nFlags: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005BCD40
// Name: public: virtual void CBufferedLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBufferedLoggingListener::Log(
        CBufferedLoggingListener *this,
        const LoggingContext_t *pContext,
        char *pMessage)
{
  CUtlBuffer *p_m_StoredSpew; // esi
  unsigned __int8 v4; // bl
  int m_Put; // eax
  unsigned __int8 v6; // bl
  int v7; // eax
  unsigned __int8 v8; // bl
  int v9; // eax
  unsigned __int8 v10; // bl
  int v11; // eax
  int m_ChannelID; // [esp-4h] [ebp-10h]
  LoggingSeverity_t m_Severity; // [esp-4h] [ebp-10h]

  p_m_StoredSpew = &this->m_StoredSpew;
  m_ChannelID = pContext->m_ChannelID;
  if ( (this->m_StoredSpew.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &this->m_StoredSpew, pFmt: "%d", m_ChannelID);
  else
    CUtlBuffer::PutTypeBin<int>(this: &this->m_StoredSpew, src: m_ChannelID);
  m_Severity = pContext->m_Severity;
  if ( (p_m_StoredSpew->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: p_m_StoredSpew, pFmt: "%d", m_Severity);
  else
    CUtlBuffer::PutTypeBin<int>(this: p_m_StoredSpew, src: m_Severity);
  v4 = pContext->m_Color._color[0];
  if ( (p_m_StoredSpew->m_Flags & 1) != 0 )
  {
    m_Put = p_m_StoredSpew->m_Put;
    if ( m_Put != 0 && p_m_StoredSpew->m_Memory.m_pMemory[m_Put - p_m_StoredSpew->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: p_m_StoredSpew);
  }
  if ( CUtlBuffer::CheckPut(this: p_m_StoredSpew, nSize: 1) != 0 )
  {
    p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Put++ - p_m_StoredSpew->m_nOffset] = v4;
    CUtlBuffer::AddNullTermination(this: p_m_StoredSpew, nPut: p_m_StoredSpew->m_Put);
  }
  v6 = pContext->m_Color._color[1];
  if ( (p_m_StoredSpew->m_Flags & 1) != 0 )
  {
    v7 = p_m_StoredSpew->m_Put;
    if ( v7 != 0 && p_m_StoredSpew->m_Memory.m_pMemory[v7 - p_m_StoredSpew->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: p_m_StoredSpew);
  }
  if ( CUtlBuffer::CheckPut(this: p_m_StoredSpew, nSize: 1) != 0 )
  {
    p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Put++ - p_m_StoredSpew->m_nOffset] = v6;
    CUtlBuffer::AddNullTermination(this: p_m_StoredSpew, nPut: p_m_StoredSpew->m_Put);
  }
  v8 = pContext->m_Color._color[2];
  if ( (p_m_StoredSpew->m_Flags & 1) != 0 )
  {
    v9 = p_m_StoredSpew->m_Put;
    if ( v9 != 0 && p_m_StoredSpew->m_Memory.m_pMemory[v9 - p_m_StoredSpew->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: p_m_StoredSpew);
  }
  if ( CUtlBuffer::CheckPut(this: p_m_StoredSpew, nSize: 1) != 0 )
  {
    p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Put++ - p_m_StoredSpew->m_nOffset] = v8;
    CUtlBuffer::AddNullTermination(this: p_m_StoredSpew, nPut: p_m_StoredSpew->m_Put);
  }
  v10 = pContext->m_Color._color[3];
  if ( (p_m_StoredSpew->m_Flags & 1) != 0 )
  {
    v11 = p_m_StoredSpew->m_Put;
    if ( v11 != 0 && p_m_StoredSpew->m_Memory.m_pMemory[v11 - p_m_StoredSpew->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: p_m_StoredSpew);
  }
  if ( CUtlBuffer::CheckPut(this: p_m_StoredSpew, nSize: 1) != 0 )
  {
    p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Put++ - p_m_StoredSpew->m_nOffset] = v10;
    CUtlBuffer::AddNullTermination(this: p_m_StoredSpew, nPut: p_m_StoredSpew->m_Put);
  }
  CUtlBuffer::PutString(this: p_m_StoredSpew, pString: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x005BCEE0
// Name: public: void CBufferedLoggingListener::EmitBufferedSpew(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBufferedLoggingListener::EmitBufferedSpew(CBufferedLoggingListener *this)
{
  CUtlBuffer *p_m_StoredSpew; // esi
  int v2; // eax
  int v3; // eax
  unsigned __int8 v4; // bl
  unsigned __int8 v5; // al
  int v6; // edi
  void *v7; // esp
  char v8[12]; // [esp+0h] [ebp-1Ch] BYREF
  int channelID; // [esp+Ch] [ebp-10h]
  LoggingSeverity_t severity; // [esp+10h] [ebp-Ch]
  Color color; // [esp+14h] [ebp-8h]
  unsigned __int8 v12; // [esp+1Ah] [ebp-2h]
  unsigned __int8 v13; // [esp+1Bh] [ebp-1h]

  p_m_StoredSpew = &this->m_StoredSpew;
  if ( this->m_StoredSpew.m_nMaxPut - this->m_StoredSpew.m_Get > 0 )
  {
    do
    {
      channelID = CUtlBuffer::GetInt(this: p_m_StoredSpew);
      severity = CUtlBuffer::GetInt(this: p_m_StoredSpew);
      if ( CUtlBuffer::CheckGet(this: p_m_StoredSpew, nSize: 1) )
      {
        v2 = p_m_StoredSpew->m_Get + 1;
        v13 = p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Get - p_m_StoredSpew->m_nOffset];
        p_m_StoredSpew->m_Get = v2;
      }
      else
      {
        v13 = 0;
      }
      if ( CUtlBuffer::CheckGet(this: p_m_StoredSpew, nSize: 1) )
      {
        v3 = p_m_StoredSpew->m_Get + 1;
        v12 = p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Get - p_m_StoredSpew->m_nOffset];
        p_m_StoredSpew->m_Get = v3;
      }
      else
      {
        v12 = 0;
      }
      if ( CUtlBuffer::CheckGet(this: p_m_StoredSpew, nSize: 1) )
      {
        v4 = p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Get - p_m_StoredSpew->m_nOffset];
        ++p_m_StoredSpew->m_Get;
      }
      else
      {
        v4 = 0;
      }
      if ( CUtlBuffer::CheckGet(this: p_m_StoredSpew, nSize: 1) )
      {
        v5 = p_m_StoredSpew->m_Memory.m_pMemory[p_m_StoredSpew->m_Get - p_m_StoredSpew->m_nOffset];
        ++p_m_StoredSpew->m_Get;
      }
      else
      {
        v5 = 0;
      }
      color._color[0] = v13;
      color._color[1] = v12;
      color._color[2] = v4;
      color._color[3] = v5;
      v6 = CUtlBuffer::PeekStringLength(this: p_m_StoredSpew);
      if ( v6 != 0 )
      {
        v7 = alloca(v6);
        CUtlBuffer::GetString(this: p_m_StoredSpew, pString: v8, nMaxChars: v6);
        ((void (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_LogDirect)(
          a1: channelID,
          a2: severity,
          a3: color,
          a4: v8);
      }
    }
    while ( p_m_StoredSpew->m_nMaxPut - p_m_StoredSpew->m_Get > 0 );
  }
  p_m_StoredSpew->m_Get = 0;
  p_m_StoredSpew->m_Put = 0;
  p_m_StoredSpew->m_Error = 0;
  p_m_StoredSpew->m_nOffset = 0;
  p_m_StoredSpew->m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: p_m_StoredSpew, nPut: 0);
}

} // namespace studiomdl
