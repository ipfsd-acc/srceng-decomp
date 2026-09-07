// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: common/netmessages.cpp
// Functions: 136
// ============================================================

#include "common\netmessages.h"

//------------------------------------------------------------------------------
// Address: 0x10047D10
// Name: public: virtual int SVC_CmdKeyValues::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SVC_CmdKeyValues::GetType(CSosOperatorDelta *this)
{
  return 32;
}

//------------------------------------------------------------------------------
// Address: 0x1005E570
// Name: public: virtual int CLC_CmdKeyValues::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLC_CmdKeyValues::GetType(SVC_SetView *this)
{
  return 18;
}

//------------------------------------------------------------------------------
// Address: 0x101BA1F0
// Name: public: virtual char const __near * CLC_VoiceData::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLC_VoiceData::ToString(CLC_VoiceData *this)
{
  const char *v1; // eax
  int v3; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(CLC_VoiceData *, int))this->GetName)(a1: this, a2: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: %i bytes", v1, v3);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BA220
// Name: public: virtual bool CLC_VoiceData::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_VoiceData::WriteToBuffer(CLC_VoiceData *this, bf_write *buffer)
{
  unsigned int v3; // eax
  int m_iCurBit; // [esp-4h] [ebp-Ch]

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_iCurBit = this->m_DataOut.m_iCurBit;
  this->m_nLength = m_iCurBit;
  bf_write::WriteWord(this: buffer, val: m_iCurBit);
  bf_write::WriteLongLong(this: buffer, val: this->m_xuid);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BA270
// Name: public: virtual char const __near * CLC_Move::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLC_Move::ToString(CLC_Move *this)
{
  const char *v1; // eax
  int v3; // [esp-Ch] [ebp-Ch]
  int v4; // [esp-8h] [ebp-8h]
  int v5; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(CLC_Move *, int, int, int))this->GetName)(
                       a1: this,
                       a2: this->m_nBackupCommands,
                       a3: this->m_nNewCommands,
                       a4: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: backup %i, new %i, bytes %i", v1, v3, v4, v5);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BA2B0
// Name: public: virtual bool CLC_Move::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_Move::WriteToBuffer(CLC_Move *this, bf_write *buffer)
{
  unsigned int v3; // eax
  unsigned int m_nNewCommands; // [esp-Ch] [ebp-14h]

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_nNewCommands = this->m_nNewCommands;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  bf_write::WriteUBitLong(this: buffer, curData: m_nNewCommands, numbits: 4, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nBackupCommands, numbits: 3, bCheckRange: true);
  bf_write::WriteWord(this: buffer, val: this->m_nLength);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BA320
// Name: public: virtual char const __near * CLC_ClientInfo::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLC_ClientInfo::ToString(CLC_ClientInfo *this)
{
  const char *v1; // eax
  int v3; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(CLC_ClientInfo *, unsigned int))this->GetName)(
                       a1: this,
                       a2: this->m_nSendTableCRC);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: SendTableCRC %lu", v1, v3);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BA350
// Name: public: virtual bool CLC_ClientInfo::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLC_ClientInfo::ReadFromBuffer(CLC_ClientInfo *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  int m_nInBufWord; // eax
  int v5; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  const unsigned int *v8; // edx
  unsigned int v9; // edi
  int v10; // eax
  const unsigned int *v11; // ecx
  unsigned int v12; // edx
  unsigned int v13; // ebx
  unsigned int v14; // edx
  int v15; // ecx
  unsigned int v16; // eax
  int v17; // ecx
  const unsigned int *v18; // ecx
  const unsigned int *v19; // edx
  const unsigned int *v20; // edx
  unsigned int v21; // edi
  int v22; // eax
  const unsigned int *v23; // ecx
  unsigned int v24; // edx
  unsigned int v25; // ebx
  unsigned int v26; // edx
  unsigned int v27; // eax
  int v28; // ecx
  bool v29; // zf
  const unsigned int *v30; // eax
  const unsigned int *v31; // edx
  int v32; // ecx
  unsigned int v33; // eax
  int v34; // ecx
  const unsigned int *v35; // ecx
  const unsigned int *v36; // edx
  const unsigned int *v37; // edx
  unsigned int v38; // edi
  int v39; // eax
  const unsigned int *v40; // ecx
  unsigned int v41; // edx
  unsigned int v42; // ebx
  unsigned int v43; // edx
  unsigned int v44; // eax
  int v45; // edx
  const unsigned int *v46; // eax
  const unsigned int *v47; // ecx
  int v48; // ecx
  unsigned int v49; // eax
  int v50; // ecx
  const unsigned int *v51; // ecx
  const unsigned int *v52; // edx
  unsigned int *v53; // edx
  const unsigned int *v54; // edx
  unsigned int v55; // edi
  int v56; // eax
  const unsigned int *v57; // ecx
  unsigned int v58; // edx
  unsigned int v59; // ebx
  int i; // [esp+Ch] [ebp-4h]
  unsigned int *buffera; // [esp+18h] [ebp+8h]

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 32 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v5 = m_nBitsAvail - 32;
    buffer->m_nBitsAvail = v5;
    if ( v5 != 0 )
    {
      buffer->m_nInBufWord = 0;
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        buffer->m_nInBufWord = *m_pDataIn;
        buffer->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
    }
    goto LABEL_18;
  }
  v8 = buffer->m_pBufferEnd;
  v9 = buffer->m_nInBufWord;
  v10 = 32 - m_nBitsAvail;
  v11 = buffer->m_pDataIn;
  if ( v11 == v8 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v11 > v8 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_15;
    }
    buffer->m_nInBufWord = *v11;
  }
  buffer->m_pDataIn = v11 + 1;
LABEL_15:
  if ( buffer->m_bOverflow )
  {
    m_nInBufWord = 0;
  }
  else
  {
    v12 = buffer->m_nInBufWord;
    v13 = (v12 & CBitBuffer::s_nMaskTable[v10]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v10;
    v14 = v12 >> v10;
    m_nInBufWord = v13 | v9;
    buffer->m_nInBufWord = v14;
  }
LABEL_18:
  this->m_nServerCount = m_nInBufWord;
  v15 = buffer->m_nBitsAvail;
  if ( v15 < 32 )
  {
    v20 = buffer->m_pBufferEnd;
    v21 = buffer->m_nInBufWord;
    v22 = 32 - v15;
    v23 = buffer->m_pDataIn;
    if ( v23 == v20 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v23 > v20 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_32;
      }
      buffer->m_nInBufWord = *v23;
    }
    buffer->m_pDataIn = v23 + 1;
LABEL_32:
    if ( buffer->m_bOverflow )
    {
      v16 = 0;
    }
    else
    {
      v24 = buffer->m_nInBufWord;
      v25 = (v24 & CBitBuffer::s_nMaskTable[v22]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v22;
      v26 = v24 >> v22;
      v16 = v25 | v21;
      buffer->m_nInBufWord = v26;
    }
    goto LABEL_35;
  }
  v16 = buffer->m_nInBufWord;
  v17 = v15 - 32;
  buffer->m_nBitsAvail = v17;
  if ( v17 != 0 )
  {
    buffer->m_nInBufWord = 0;
  }
  else
  {
    v18 = buffer->m_pDataIn;
    v19 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v18 == v19 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v18 + 1;
    }
    else if ( v18 <= v19 )
    {
      buffer->m_nInBufWord = *v18;
      buffer->m_pDataIn = v18 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
LABEL_35:
  this->m_nSendTableCRC = v16;
  v27 = buffer->m_nInBufWord;
  v28 = v27 & 1;
  v29 = buffer->m_nBitsAvail-- == 1;
  if ( v29 )
  {
    v30 = buffer->m_pDataIn;
    v31 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v30 == v31 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v30 + 1;
    }
    else if ( v30 <= v31 )
    {
      buffer->m_nInBufWord = *v30;
      buffer->m_pDataIn = v30 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v27 >> 1;
  }
  this->m_bIsHLTV = v28 != 0;
  v32 = buffer->m_nBitsAvail;
  if ( v32 < 32 )
  {
    v37 = buffer->m_pBufferEnd;
    v38 = buffer->m_nInBufWord;
    v39 = 32 - v32;
    v40 = buffer->m_pDataIn;
    if ( v40 == v37 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v40 > v37 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_56;
      }
      buffer->m_nInBufWord = *v40;
    }
    buffer->m_pDataIn = v40 + 1;
LABEL_56:
    if ( buffer->m_bOverflow )
    {
      v33 = 0;
    }
    else
    {
      v41 = buffer->m_nInBufWord;
      v42 = (v41 & CBitBuffer::s_nMaskTable[v39]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v39;
      v43 = v41 >> v39;
      v33 = v42 | v38;
      buffer->m_nInBufWord = v43;
    }
    goto LABEL_59;
  }
  v33 = buffer->m_nInBufWord;
  v34 = v32 - 32;
  buffer->m_nBitsAvail = v34;
  if ( v34 != 0 )
  {
    buffer->m_nInBufWord = 0;
  }
  else
  {
    v35 = buffer->m_pDataIn;
    v36 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v35 == v36 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v35 + 1;
    }
    else if ( v35 <= v36 )
    {
      buffer->m_nInBufWord = *v35;
      buffer->m_pDataIn = v35 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
LABEL_59:
  this->m_nFriendsID = v33;
  CBitRead::ReadString(this: buffer, pStr: this->m_FriendsName, maxLen: 32, bLine: false, pOutNumChars: nullptr);
  buffera = this->m_nCustomFiles;
  for ( i = 4; i != 0; --i )
  {
    v44 = buffer->m_nInBufWord;
    v45 = v44 & 1;
    v29 = buffer->m_nBitsAvail-- == 1;
    if ( v29 )
    {
      v46 = buffer->m_pDataIn;
      v47 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v46 == v47 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v46 + 1;
      }
      else if ( v46 <= v47 )
      {
        buffer->m_nInBufWord = *v46;
        buffer->m_pDataIn = v46 + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
    }
    else
    {
      buffer->m_nInBufWord = v44 >> 1;
    }
    if ( v45 == 0 )
    {
      *buffera = 0;
      goto LABEL_88;
    }
    v48 = buffer->m_nBitsAvail;
    if ( v48 < 32 )
    {
      v54 = buffer->m_pBufferEnd;
      v55 = buffer->m_nInBufWord;
      v56 = 32 - v48;
      v57 = buffer->m_pDataIn;
      if ( v57 == v54 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_bOverflow = true;
      }
      else
      {
        if ( v57 > v54 )
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
          goto LABEL_83;
        }
        buffer->m_nInBufWord = *v57;
      }
      buffer->m_pDataIn = v57 + 1;
LABEL_83:
      if ( buffer->m_bOverflow )
      {
        *buffera = 0;
      }
      else
      {
        v58 = buffer->m_nInBufWord;
        v59 = (v58 & CBitBuffer::s_nMaskTable[v56]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v56;
        buffer->m_nInBufWord = v58 >> v56;
        *buffera = v59 | v55;
      }
      goto LABEL_88;
    }
    v49 = buffer->m_nInBufWord;
    v50 = v48 - 32;
    buffer->m_nBitsAvail = v50;
    if ( v50 != 0 )
    {
      buffer->m_nInBufWord = 0;
      *buffera = v49;
    }
    else
    {
      v51 = buffer->m_pDataIn;
      v52 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v51 == v52 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v51 + 1;
        *buffera = v49;
      }
      else
      {
        if ( v51 <= v52 )
        {
          buffer->m_nInBufWord = *v51;
          v53 = buffera;
          buffer->m_pDataIn = v51 + 1;
        }
        else
        {
          v53 = buffera;
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        *v53 = v49;
      }
    }
LABEL_88:
    ++buffera;
  }
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BA7E0
// Name: public: virtual char const __near * CLC_LoadingProgress::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLC_LoadingProgress::ToString(CLC_LoadingProgress *this)
{
  const char *v1; // eax
  int v3; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(CLC_LoadingProgress *, int))this->GetName)(a1: this, a2: this->m_nProgress);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: LoadingProgress %i", v1, v3);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BA810
// Name: public: virtual bool CLC_LoadingProgress::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLC_LoadingProgress::WriteToBuffer(CLC_LoadingProgress *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteByte(this: buffer, val: this->m_nProgress);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BA850
// Name: public: virtual bool CLC_LoadingProgress::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_LoadingProgress::ReadFromBuffer(CLC_LoadingProgress *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // ecx
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  unsigned int v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v12 = 8 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_16;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( buffer->m_bOverflow )
    {
      v6 = 0;
    }
    else
    {
      v14 = buffer->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v12;
      v6 = v15 | m_nInBufWord;
      buffer->m_nInBufWord = v14 >> v12;
    }
    goto LABEL_19;
  }
  v3 = buffer->m_nInBufWord;
  v4 = (unsigned __int8)v3;
  v5 = m_nBitsAvail - 8;
  buffer->m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    buffer->m_nInBufWord = v3 >> 8;
    v6 = (unsigned __int8)v3;
  }
  else
  {
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      buffer->m_pDataIn = v7 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v6 = v4;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v9 = *v7;
        buffer->m_pDataIn = v7 + 1;
        buffer->m_nInBufWord = v9;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v6 = v4;
    }
  }
LABEL_19:
  this->m_nProgress = v6;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BA960
// Name: public: virtual bool CLC_BaselineAck::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLC_BaselineAck::WriteToBuffer(CLC_BaselineAck *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteLong(this: buffer, val: this->m_nBaselineTick);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nBaselineNr, numbits: 1, bCheckRange: true);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BA9B0
// Name: public: virtual bool CLC_BaselineAck::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_BaselineAck::ReadFromBuffer(CLC_BaselineAck *this, bf_read *buffer)
{
  int m_nBitsAvail; // esi
  int m_nInBufWord; // ecx
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // esi
  const unsigned int *v6; // ecx
  unsigned int v7; // edi
  int v8; // edx
  const unsigned int *v9; // esi
  unsigned int v10; // esi
  unsigned int v11; // ebx
  int v12; // ecx
  unsigned int v13; // edx
  int v14; // esi
  int v15; // ecx
  int v16; // ecx
  const unsigned int *v17; // ecx
  const unsigned int *v18; // edx
  unsigned int v19; // edx
  const unsigned int *v20; // esi
  unsigned int v21; // edi
  int v22; // edx
  const unsigned int *v23; // ecx
  unsigned int v24; // esi
  unsigned int v25; // ebx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 32 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    buffer->m_nBitsAvail = m_nBitsAvail - 32;
    if ( m_nBitsAvail == 32 )
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        buffer->m_nInBufWord = *m_pDataIn;
        buffer->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
    }
    else
    {
      buffer->m_nInBufWord = 0;
    }
    goto LABEL_18;
  }
  v6 = buffer->m_pDataIn;
  v7 = buffer->m_nInBufWord;
  v8 = 32 - m_nBitsAvail;
  v9 = buffer->m_pBufferEnd;
  if ( v6 == v9 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v6 > v9 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_15;
    }
    buffer->m_nInBufWord = *v6;
  }
  buffer->m_pDataIn = v6 + 1;
LABEL_15:
  if ( buffer->m_bOverflow )
  {
    m_nInBufWord = 0;
  }
  else
  {
    v10 = buffer->m_nInBufWord;
    v11 = (v10 & CBitBuffer::s_nMaskTable[v8]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v8;
    m_nInBufWord = v11 | v7;
    buffer->m_nInBufWord = v10 >> v8;
  }
LABEL_18:
  this->m_nBaselineTick = m_nInBufWord;
  v12 = buffer->m_nBitsAvail;
  if ( v12 < 1 )
  {
    v20 = buffer->m_pBufferEnd;
    v21 = buffer->m_nInBufWord;
    v22 = 1 - v12;
    v23 = buffer->m_pDataIn;
    if ( v23 == v20 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v23 > v20 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_33;
      }
      buffer->m_nInBufWord = *v23;
    }
    buffer->m_pDataIn = v23 + 1;
LABEL_33:
    if ( buffer->m_bOverflow )
    {
      v16 = 0;
    }
    else
    {
      v24 = buffer->m_nInBufWord;
      v25 = (v24 & CBitBuffer::s_nMaskTable[v22]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v22;
      v16 = v25 | v21;
      buffer->m_nInBufWord = v24 >> v22;
    }
    goto LABEL_36;
  }
  v13 = buffer->m_nInBufWord;
  v14 = v13 & 1;
  v15 = v12 - 1;
  buffer->m_nBitsAvail = v15;
  if ( v15 != 0 )
  {
    buffer->m_nInBufWord = v13 >> 1;
    v16 = v13 & 1;
  }
  else
  {
    v17 = buffer->m_pDataIn;
    v18 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v17 == v18 )
    {
      buffer->m_pDataIn = v17 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v16 = v14;
    }
    else
    {
      if ( v17 <= v18 )
      {
        v19 = *v17;
        buffer->m_pDataIn = v17 + 1;
        buffer->m_nInBufWord = v19;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v16 = v14;
    }
  }
LABEL_36:
  this->m_nBaselineNr = v16;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BAB90
// Name: public: virtual bool CLC_RespondCvarValue::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLC_RespondCvarValue::WriteToBuffer(CLC_RespondCvarValue *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteSBitLong(this: buffer, data: this->m_iCookie, numbits: 32);
  bf_write::WriteSBitLong(this: buffer, data: this->m_eStatusCode, numbits: 4);
  bf_write::WriteString(this: buffer, pStr: this->m_szCvarName);
  bf_write::WriteString(this: buffer, pStr: this->m_szCvarValue);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BABF0
// Name: public: virtual bool CLC_RespondCvarValue::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLC_RespondCvarValue::ReadFromBuffer(CLC_RespondCvarValue *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v5; // ecx
  unsigned int v6; // edi
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  const unsigned int *v9; // edx
  unsigned int v10; // edi
  int v11; // eax
  const unsigned int *v12; // ecx
  unsigned int v13; // edx
  unsigned int v14; // ebx
  int v15; // edi
  unsigned int v16; // edx
  int v17; // ecx
  unsigned int v18; // edx
  int v19; // eax
  int v20; // ecx
  const unsigned int *v21; // ecx
  const unsigned int *v22; // edx
  unsigned int v23; // edx
  const unsigned int *v24; // edi
  unsigned int v25; // eax
  int v26; // edx
  const unsigned int *v27; // ecx
  unsigned int v28; // edi
  unsigned int v29; // ebx
  CLC_RespondCvarValue *v31; // [esp+Ch] [ebp-4h]

  m_nBitsAvail = buffer->m_nBitsAvail;
  v31 = this;
  if ( m_nBitsAvail >= 32 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v5 = m_nBitsAvail - 32;
    v6 = 0;
    buffer->m_nBitsAvail = v5;
    if ( v5 != 0 )
    {
      buffer->m_nInBufWord = 0;
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        buffer->m_nInBufWord = *m_pDataIn;
        buffer->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
    }
    goto LABEL_19;
  }
  v9 = buffer->m_pBufferEnd;
  v10 = buffer->m_nInBufWord;
  v11 = 32 - m_nBitsAvail;
  v12 = buffer->m_pDataIn;
  if ( v12 == v9 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_14:
    buffer->m_pDataIn = v12 + 1;
    goto LABEL_15;
  }
  if ( v12 <= v9 )
  {
    buffer->m_nInBufWord = *v12;
    goto LABEL_14;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_15:
  if ( buffer->m_bOverflow )
  {
    m_nInBufWord = 0;
  }
  else
  {
    v13 = buffer->m_nInBufWord;
    v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v11;
    v15 = v14 | v10;
    this = v31;
    v16 = v13 >> v11;
    m_nInBufWord = v15;
    buffer->m_nInBufWord = v16;
  }
  v6 = 0;
LABEL_19:
  this->m_iCookie = m_nInBufWord;
  v17 = buffer->m_nBitsAvail;
  if ( v17 < 4 )
  {
    v24 = buffer->m_pBufferEnd;
    v25 = buffer->m_nInBufWord;
    v26 = 4 - v17;
    v27 = buffer->m_pDataIn;
    if ( v27 == v24 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v27 > v24 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_33:
        if ( buffer->m_bOverflow )
        {
          v19 = 0;
          goto LABEL_37;
        }
        v28 = buffer->m_nInBufWord;
        v29 = (v28 & CBitBuffer::s_nMaskTable[v26]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v26;
        v19 = v29 | v25;
        this = v31;
        v6 = v28 >> v26;
        goto LABEL_36;
      }
      buffer->m_nInBufWord = *v27;
    }
    buffer->m_pDataIn = v27 + 1;
    goto LABEL_33;
  }
  v18 = buffer->m_nInBufWord;
  v19 = v18 & 0xF;
  v20 = v17 - 4;
  buffer->m_nBitsAvail = v20;
  if ( v20 == 0 )
  {
    v21 = buffer->m_pDataIn;
    v22 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v21 == v22 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_pDataIn = v21 + 1;
    }
    else
    {
      if ( v21 <= v22 )
      {
        v23 = *v21;
        buffer->m_pDataIn = v21 + 1;
        buffer->m_nInBufWord = v23;
        goto LABEL_37;
      }
      buffer->m_bOverflow = true;
    }
LABEL_36:
    buffer->m_nInBufWord = v6;
    goto LABEL_37;
  }
  buffer->m_nInBufWord = v18 >> 4;
LABEL_37:
  this->m_eStatusCode = v19 << 28 >> 28;
  CBitRead::ReadString(this: buffer, pStr: this->m_szCvarNameBuffer, maxLen: 256, bLine: false, pOutNumChars: nullptr);
  this->m_szCvarName = this->m_szCvarNameBuffer;
  CBitRead::ReadString(this: buffer, pStr: this->m_szCvarValueBuffer, maxLen: 256, bLine: false, pOutNumChars: nullptr);
  this->m_szCvarValue = this->m_szCvarValueBuffer;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BAE00
// Name: public: virtual char const __near * CLC_RespondCvarValue::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLC_RespondCvarValue::ToString(CLC_RespondCvarValue *this)
{
  const char *v1; // eax
  int v3; // [esp-Ch] [ebp-Ch]
  const char *v4; // [esp-8h] [ebp-8h]
  int v5; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(CLC_RespondCvarValue *, EQueryCvarValueStatus, const char *, int))this->GetName)(
                       a1: this,
                       a2: this->m_eStatusCode,
                       a3: this->m_szCvarValue,
                       a4: this->m_iCookie);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: status: %d, value: %s, cookie: %d", v1, v3, v4, v5);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BAE40
// Name: FindCommonPrefix
// Source: json
//------------------------------------------------------------------------------
int __usercall FindCommonPrefix@<eax>(const char *pStr@<edi>)
{
  int v1; // esi
  char v2; // al

  v1 = 0;
  while ( 1 )
  {
    if ( V_stristr(pStr, pSearch: g_MostCommonPrefixes[v1]) == pStr )
    {
      v2 = pStr[_V_strlen(str: g_MostCommonPrefixes[v1])];
      if ( v2 == 47 || v2 == 92 )
        break;
    }
    if ( (unsigned int)++v1 >= 4 )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101BAE90
// Name: public: virtual bool CLC_FileCRCCheck::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_FileCRCCheck::ReadFromBuffer(CLC_FileCRCCheck *this, bf_read *buffer)
{
  bool v2; // zf
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // eax
  const unsigned int *v10; // eax
  const unsigned int *v11; // ecx
  unsigned int v12; // ecx
  const unsigned int *v13; // edx
  unsigned int v14; // edi
  int v15; // eax
  const unsigned int *v16; // ecx
  unsigned int v17; // edx
  unsigned int v18; // ebx
  unsigned int v19; // edx
  int v20; // ecx
  unsigned int v21; // eax
  int v22; // edi
  int v23; // ecx
  const unsigned int *v24; // eax
  const unsigned int *v25; // ecx
  const unsigned int *v26; // edx
  unsigned int v27; // edi
  int v28; // eax
  const unsigned int *v29; // ecx
  unsigned int v30; // edx
  unsigned int v31; // ebx
  int v32; // ecx
  unsigned int v33; // eax
  int v34; // ecx
  const unsigned int *v35; // ecx
  const unsigned int *v36; // edx
  const unsigned int *v37; // edx
  unsigned int v38; // edi
  int v39; // eax
  const unsigned int *v40; // ecx
  unsigned int v41; // edx
  unsigned int v42; // ebx
  unsigned int v43; // edx
  char szTemp[260]; // [esp+Ch] [ebp-108h] BYREF
  CLC_FileCRCCheck *v46; // [esp+110h] [ebp-4h]

  v2 = buffer->m_nBitsAvail-- == 1;
  v46 = this;
  if ( v2 )
  {
    m_pDataIn = buffer->m_pDataIn;
    m_pBufferEnd = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      buffer->m_nInBufWord = *m_pDataIn;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord >>= 1;
  }
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 2 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v7 = m_nInBufWord & 3;
    v8 = m_nBitsAvail - 2;
    buffer->m_nBitsAvail = v8;
    if ( v8 != 0 )
    {
      buffer->m_nInBufWord = m_nInBufWord >> 2;
      v9 = m_nInBufWord & 3;
    }
    else
    {
      v10 = buffer->m_pDataIn;
      v11 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v10 == v11 )
      {
        buffer->m_pDataIn = v10 + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        v9 = v7;
      }
      else
      {
        if ( v10 <= v11 )
        {
          v12 = *v10;
          buffer->m_pDataIn = v10 + 1;
          buffer->m_nInBufWord = v12;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v9 = v7;
      }
    }
    goto LABEL_25;
  }
  v13 = buffer->m_pBufferEnd;
  v14 = buffer->m_nInBufWord;
  v15 = 2 - m_nBitsAvail;
  v16 = buffer->m_pDataIn;
  if ( v16 == v13 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_22:
    buffer->m_pDataIn = v16 + 1;
    goto LABEL_23;
  }
  if ( v16 <= v13 )
  {
    buffer->m_nInBufWord = *v16;
    goto LABEL_22;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_23:
  if ( buffer->m_bOverflow )
  {
LABEL_26:
    CBitRead::ReadString(this: buffer, pStr: v46->m_szPathID, maxLen: 260, bLine: false, pOutNumChars: nullptr);
    goto LABEL_29;
  }
  v17 = buffer->m_nInBufWord;
  v18 = (v17 & CBitBuffer::s_nMaskTable[v15]) << buffer->m_nBitsAvail;
  buffer->m_nBitsAvail = 32 - v15;
  v19 = v17 >> v15;
  v9 = v18 | v14;
  buffer->m_nInBufWord = v19;
LABEL_25:
  if ( v9 == 0 )
    goto LABEL_26;
  if ( (unsigned int)(v9 - 1) >= 2 )
    return false;
  V_strncpy(pDest: v46->m_szPathID, pSrc: (&dword_104213B0)[v9], maxLen: 260);
LABEL_29:
  v20 = buffer->m_nBitsAvail;
  if ( v20 < 3 )
  {
    v26 = buffer->m_pBufferEnd;
    v27 = buffer->m_nInBufWord;
    v28 = 3 - v20;
    v29 = buffer->m_pDataIn;
    if ( v29 == v26 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v29 > v26 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_43:
        if ( buffer->m_bOverflow )
        {
LABEL_46:
          CBitRead::ReadString(this: buffer, pStr: v46->m_szFilename, maxLen: 260, bLine: false, pOutNumChars: nullptr);
          goto LABEL_49;
        }
        v30 = buffer->m_nInBufWord;
        v31 = (v30 & CBitBuffer::s_nMaskTable[v28]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v28;
        v22 = v31 | v27;
        buffer->m_nInBufWord = v30 >> v28;
        goto LABEL_45;
      }
      buffer->m_nInBufWord = *v29;
    }
    buffer->m_pDataIn = v29 + 1;
    goto LABEL_43;
  }
  v21 = buffer->m_nInBufWord;
  v22 = v21 & 7;
  v23 = v20 - 3;
  buffer->m_nBitsAvail = v23;
  if ( v23 != 0 )
  {
    buffer->m_nInBufWord = v21 >> 3;
  }
  else
  {
    v24 = buffer->m_pDataIn;
    v25 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v24 == v25 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v24 + 1;
    }
    else if ( v24 <= v25 )
    {
      buffer->m_nInBufWord = *v24;
      buffer->m_pDataIn = v24 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
LABEL_45:
  if ( v22 == 0 )
    goto LABEL_46;
  if ( (unsigned int)(v22 - 1) < 4 )
  {
    CBitRead::ReadString(this: buffer, pStr: szTemp, maxLen: 260, bLine: false, pOutNumChars: nullptr);
    V_snprintf(pDest: v46->m_szFilename, maxLen: 260, pFormat: "%s%c%s", off_104213B8[v22], 92, szTemp);
LABEL_49:
    v32 = buffer->m_nBitsAvail;
    if ( v32 >= 32 )
    {
      v33 = buffer->m_nInBufWord;
      v34 = v32 - 32;
      buffer->m_nBitsAvail = v34;
      if ( v34 == 0 )
      {
        v35 = buffer->m_pDataIn;
        v36 = buffer->m_pBufferEnd;
        buffer->m_nBitsAvail = 32;
        if ( v35 == v36 )
        {
          buffer->m_nBitsAvail = 1;
          buffer->m_nInBufWord = 0;
          buffer->m_pDataIn = v35 + 1;
LABEL_66:
          v46->m_CRC = v33;
          return !buffer->m_bOverflow;
        }
        if ( v35 <= v36 )
        {
          buffer->m_nInBufWord = *v35;
          buffer->m_pDataIn = v35 + 1;
          goto LABEL_66;
        }
        buffer->m_bOverflow = true;
      }
      buffer->m_nInBufWord = 0;
      goto LABEL_66;
    }
    v37 = buffer->m_pBufferEnd;
    v38 = buffer->m_nInBufWord;
    v39 = 32 - v32;
    v40 = buffer->m_pDataIn;
    if ( v40 == v37 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v40 > v37 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_63;
      }
      buffer->m_nInBufWord = *v40;
    }
    buffer->m_pDataIn = v40 + 1;
LABEL_63:
    if ( buffer->m_bOverflow )
    {
      v33 = 0;
    }
    else
    {
      v41 = buffer->m_nInBufWord;
      v42 = (v41 & CBitBuffer::s_nMaskTable[v39]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v39;
      v43 = v41 >> v39;
      v33 = v42 | v38;
      buffer->m_nInBufWord = v43;
    }
    goto LABEL_66;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101BB220
// Name: public: virtual char const __near * CLC_FileCRCCheck::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLC_FileCRCCheck::ToString(CLC_FileCRCCheck *this)
{
  const char *v1; // eax
  const char *v3; // [esp-8h] [ebp-8h]
  const char *v4; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(CLC_FileCRCCheck *, char *, char *))this->GetName)(
                       a1: this,
                       a2: this->m_szPathID,
                       a3: this->m_szFilename);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: path: %s, file: %s", v1, v3, v4);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BB250
// Name: protected: virtual Base_CmdKeyValues::~Base_CmdKeyValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Base_CmdKeyValues::~Base_CmdKeyValues(Base_CmdKeyValues *this)
{
  KeyValues *m_pKeyValues; // ecx

  m_pKeyValues = this->m_pKeyValues;
  this->__vftable = (Base_CmdKeyValues_vtbl *)&Base_CmdKeyValues::`vftable';
  if ( m_pKeyValues != nullptr )
    KeyValues::deleteThis(this: m_pKeyValues);
  this->__vftable = (Base_CmdKeyValues_vtbl *)&INetMessage::`vftable';
  this->m_pKeyValues = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101BB280
// Name: public: virtual char const __near * SVC_CmdKeyValues::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_CmdKeyValues::ToString(SVC_CmdKeyValues *this)
{
  KeyValues *m_pKeyValues; // ecx
  const char *Name; // eax
  const char *v4; // eax
  const char *v6; // [esp-4h] [ebp-8h]

  m_pKeyValues = this->m_pKeyValues;
  if ( m_pKeyValues != nullptr )
    Name = KeyValues::GetName(this: m_pKeyValues);
  else
    Name = "<<null>>";
  v4 = (const char *)((int (__thiscall *)(SVC_CmdKeyValues *, const char *))this->GetName)(a1: this, a2: Name);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: %s", v4, v6);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BB2C0
// Name: public: virtual bool SVC_Print::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_Print::WriteToBuffer(SVC_Print *this, bf_write *buffer)
{
  unsigned int v3; // eax
  const char *m_szText; // esi

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_szText = this->m_szText;
  if ( m_szText == nullptr )
    m_szText = " svc_print NULL";
  return bf_write::WriteString(this: buffer, pStr: m_szText);
}

//------------------------------------------------------------------------------
// Address: 0x101BB300
// Name: public: virtual bool SVC_Print::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_Print::ReadFromBuffer(SVC_Print *this, bf_read *buffer)
{
  this->m_szText = this->m_szTextBuffer;
  return CBitRead::ReadString(
           this: buffer,
           pStr: this->m_szTextBuffer,
           maxLen: 2048,
           bLine: false,
           pOutNumChars: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101BB320
// Name: public: virtual char const __near * SVC_Print::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_Print::ToString(NET_StringCmd *this)
{
  const char *v1; // eax
  const char *v3; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(NET_StringCmd *, const char *))this->GetName)(a1: this, a2: this->m_szCommand);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: \"%s\"", v1, v3);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BB350
// Name: public: virtual bool NET_StringCmd::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NET_StringCmd::WriteToBuffer(NET_StringCmd *this, bf_write *buffer)
{
  unsigned int v3; // eax
  const char *m_szCommand; // esi

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_szCommand = this->m_szCommand;
  if ( m_szCommand == nullptr )
    m_szCommand = " NET_StringCmd NULL";
  return bf_write::WriteString(this: buffer, pStr: m_szCommand);
}

//------------------------------------------------------------------------------
// Address: 0x101BB390
// Name: public: virtual bool NET_StringCmd::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall NET_StringCmd::ReadFromBuffer(NET_StringCmd *this, bf_read *buffer)
{
  this->m_szCommand = this->m_szCommandBuffer;
  return CBitRead::ReadString(
           this: buffer,
           pStr: this->m_szCommandBuffer,
           maxLen: 1024,
           bLine: false,
           pOutNumChars: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101BB3B0
// Name: public: virtual bool SVC_ServerInfo::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_ServerInfo::ReadFromBuffer(SVC_ServerInfo *this, bf_read *buffer)
{
  char *m_szHostNameBuffer; // eax
  int m_nBitsAvail; // ecx
  unsigned int v5; // edx
  __int16 v6; // di
  unsigned int v7; // edx
  const unsigned int *v8; // eax
  const unsigned int *v9; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v12; // eax
  const unsigned int *m_pDataIn; // ecx
  __int16 v14; // ax
  unsigned int v15; // edx
  unsigned int v16; // ebx
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  const unsigned int *v20; // ecx
  const unsigned int *v21; // edx
  const unsigned int *v22; // edx
  unsigned int v23; // edi
  int v24; // eax
  const unsigned int *v25; // ecx
  unsigned int v26; // edx
  unsigned int v27; // ebx
  unsigned int v28; // edx
  unsigned int v29; // ecx
  int v30; // eax
  bool v31; // zf
  const unsigned int *v32; // ecx
  const unsigned int *v33; // edx
  unsigned int v34; // eax
  int v35; // ecx
  const unsigned int *v36; // eax
  const unsigned int *v37; // edx
  int v38; // ecx
  unsigned int v39; // eax
  int v40; // ecx
  const unsigned int *v41; // ecx
  const unsigned int *v42; // edx
  const unsigned int *v43; // edx
  unsigned int v44; // edi
  int v45; // eax
  const unsigned int *v46; // ecx
  unsigned int v47; // edx
  unsigned int v48; // ebx
  unsigned int v49; // edx
  int v50; // ecx
  unsigned int v51; // eax
  int v52; // ecx
  const unsigned int *v53; // ecx
  const unsigned int *v54; // edx
  const unsigned int *v55; // edx
  unsigned int v56; // edi
  int v57; // eax
  const unsigned int *v58; // ecx
  unsigned int v59; // edx
  unsigned int v60; // ebx
  unsigned int v61; // edx
  int v62; // ecx
  unsigned int v63; // eax
  unsigned int v64; // edx
  int v65; // ecx
  const unsigned int *v66; // eax
  const unsigned int *v67; // ecx
  unsigned int v68; // ecx
  const unsigned int *v69; // edx
  unsigned int v70; // edi
  int v71; // eax
  const unsigned int *v72; // ecx
  unsigned int v73; // edx
  unsigned int v74; // ebx
  unsigned int v75; // edx
  int v76; // ecx
  unsigned int v77; // eax
  int v78; // ecx
  const unsigned int *v79; // ecx
  const unsigned int *v80; // edx
  const unsigned int *v81; // edx
  unsigned int v82; // edi
  int v83; // eax
  const unsigned int *v84; // ecx
  unsigned int v85; // edx
  unsigned int v86; // ebx
  unsigned int v87; // edx
  int v88; // ecx
  unsigned int v89; // eax
  unsigned int v90; // edx
  int v91; // ecx
  const unsigned int *v92; // eax
  const unsigned int *v93; // ecx
  unsigned int v94; // ecx
  const unsigned int *v95; // edx
  unsigned int v96; // edi
  int v97; // eax
  const unsigned int *v98; // ecx
  unsigned int v99; // edx
  unsigned int v100; // ebx
  unsigned int v101; // edx
  int v102; // ecx
  unsigned int v103; // eax
  unsigned int v104; // edx
  int v105; // ecx
  const unsigned int *v106; // eax
  const unsigned int *v107; // ecx
  unsigned int v108; // ecx
  const unsigned int *v109; // edx
  unsigned int v110; // edi
  int v111; // eax
  const unsigned int *v112; // ecx
  unsigned int v113; // edx
  unsigned int v114; // ebx
  unsigned int v115; // edx
  int v116; // ecx
  unsigned int v117; // eax
  int v118; // ecx
  const unsigned int *v119; // ecx
  const unsigned int *v120; // edx
  const unsigned int *v121; // edx
  unsigned int v122; // edi
  int v123; // eax
  const unsigned int *v124; // ecx
  unsigned int v125; // edx
  unsigned int v126; // ebx
  int v127; // ecx
  unsigned int v128; // edx
  char v129; // al
  int v130; // ecx
  unsigned int v131; // edx
  const unsigned int *v132; // ecx
  const unsigned int *v133; // edx
  const unsigned int *v134; // edx
  unsigned int v135; // edi
  int v136; // eax
  const unsigned int *v137; // ecx
  unsigned int v138; // edx
  unsigned int v139; // ebx
  char *v141; // [esp+Ch] [ebp-14h]
  char *m_szSkyNameBuffer; // [esp+10h] [ebp-10h]
  char *m_szMapNameBuffer; // [esp+14h] [ebp-Ch]
  char *pStr; // [esp+18h] [ebp-8h]
  bf_read *buffera; // [esp+28h] [ebp+8h]

  this->m_szGameDir = this->m_szGameDirBuffer;
  pStr = this->m_szGameDirBuffer;
  this->m_szMapName = this->m_szMapNameBuffer;
  m_szMapNameBuffer = this->m_szMapNameBuffer;
  this->m_szSkyName = this->m_szSkyNameBuffer;
  m_szSkyNameBuffer = this->m_szSkyNameBuffer;
  m_szHostNameBuffer = this->m_szHostNameBuffer;
  this->m_szHostName = this->m_szHostNameBuffer;
  m_nBitsAvail = buffer->m_nBitsAvail;
  v141 = m_szHostNameBuffer;
  if ( m_nBitsAvail < 16 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v12 = 16 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_15:
        if ( buffer->m_bOverflow )
        {
          v14 = 0;
          goto LABEL_20;
        }
        v15 = buffer->m_nInBufWord;
        v16 = (v15 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v12;
        v6 = v16 | m_nInBufWord;
        v7 = v15 >> v12;
        goto LABEL_18;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v5 = buffer->m_nInBufWord;
  v6 = v5;
  buffer->m_nBitsAvail = m_nBitsAvail - 16;
  if ( m_nBitsAvail == 16 )
  {
    v8 = buffer->m_pDataIn;
    v9 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v8 + 1;
    }
    else if ( v8 <= v9 )
    {
      buffer->m_nInBufWord = *v8;
      buffer->m_pDataIn = v8 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
    goto LABEL_19;
  }
  v7 = HIWORD(v5);
LABEL_18:
  buffer->m_nInBufWord = v7;
LABEL_19:
  v14 = v6;
LABEL_20:
  this->m_nProtocol = v14;
  v17 = buffer->m_nBitsAvail;
  if ( v17 < 32 )
  {
    v22 = buffer->m_pBufferEnd;
    v23 = buffer->m_nInBufWord;
    v24 = 32 - v17;
    v25 = buffer->m_pDataIn;
    if ( v25 == v22 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v25 > v22 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_34;
      }
      buffer->m_nInBufWord = *v25;
    }
    buffer->m_pDataIn = v25 + 1;
LABEL_34:
    if ( buffer->m_bOverflow )
    {
      v18 = 0;
    }
    else
    {
      v26 = buffer->m_nInBufWord;
      v27 = (v26 & CBitBuffer::s_nMaskTable[v24]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v24;
      v28 = v26 >> v24;
      v18 = v27 | v23;
      buffer->m_nInBufWord = v28;
    }
    goto LABEL_37;
  }
  v18 = buffer->m_nInBufWord;
  v19 = v17 - 32;
  buffer->m_nBitsAvail = v19;
  if ( v19 != 0 )
  {
    buffer->m_nInBufWord = 0;
  }
  else
  {
    v20 = buffer->m_pDataIn;
    v21 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v20 == v21 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v20 + 1;
    }
    else if ( v20 <= v21 )
    {
      buffer->m_nInBufWord = *v20;
      buffer->m_pDataIn = v20 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
LABEL_37:
  this->m_nServerCount = v18;
  v29 = buffer->m_nInBufWord;
  v30 = v29 & 1;
  v31 = buffer->m_nBitsAvail-- == 1;
  if ( v31 )
  {
    v32 = buffer->m_pDataIn;
    v33 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v32 == v33 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v32 + 1;
    }
    else if ( v32 <= v33 )
    {
      buffer->m_nInBufWord = *v32;
      buffer->m_pDataIn = v32 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v29 >> 1;
  }
  this->m_bIsHLTV = v30 != 0;
  v34 = buffer->m_nInBufWord;
  v35 = v34 & 1;
  v31 = buffer->m_nBitsAvail-- == 1;
  if ( v31 )
  {
    v36 = buffer->m_pDataIn;
    v37 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v36 == v37 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v36 + 1;
    }
    else if ( v36 <= v37 )
    {
      buffer->m_nInBufWord = *v36;
      buffer->m_pDataIn = v36 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v34 >> 1;
  }
  this->m_bIsDedicated = v35 != 0;
  v38 = buffer->m_nBitsAvail;
  if ( v38 >= 32 )
  {
    v39 = buffer->m_nInBufWord;
    v40 = v38 - 32;
    buffer->m_nBitsAvail = v40;
    if ( v40 != 0 )
    {
      buffer->m_nInBufWord = 0;
    }
    else
    {
      v41 = buffer->m_pDataIn;
      v42 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v41 == v42 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v41 + 1;
      }
      else if ( v41 <= v42 )
      {
        buffer->m_nInBufWord = *v41;
        buffer->m_pDataIn = v41 + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
    }
    goto LABEL_68;
  }
  v43 = buffer->m_pBufferEnd;
  v44 = buffer->m_nInBufWord;
  v45 = 32 - v38;
  v46 = buffer->m_pDataIn;
  if ( v46 == v43 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v46 > v43 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_65;
    }
    buffer->m_nInBufWord = *v46;
  }
  buffer->m_pDataIn = v46 + 1;
LABEL_65:
  if ( buffer->m_bOverflow )
  {
    v39 = 0;
  }
  else
  {
    v47 = buffer->m_nInBufWord;
    v48 = (v47 & CBitBuffer::s_nMaskTable[v45]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v45;
    v49 = v47 >> v45;
    v39 = v48 | v44;
    buffer->m_nInBufWord = v49;
  }
LABEL_68:
  this->m_nClientCRC = v39;
  v50 = buffer->m_nBitsAvail;
  if ( v50 >= 32 )
  {
    v51 = buffer->m_nInBufWord;
    v52 = v50 - 32;
    buffer->m_nBitsAvail = v52;
    if ( v52 != 0 )
    {
      buffer->m_nInBufWord = 0;
    }
    else
    {
      v53 = buffer->m_pDataIn;
      v54 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v53 == v54 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v53 + 1;
      }
      else if ( v53 <= v54 )
      {
        buffer->m_nInBufWord = *v53;
        buffer->m_pDataIn = v53 + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
    }
    goto LABEL_85;
  }
  v55 = buffer->m_pBufferEnd;
  v56 = buffer->m_nInBufWord;
  v57 = 32 - v50;
  v58 = buffer->m_pDataIn;
  if ( v58 == v55 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v58 > v55 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_82;
    }
    buffer->m_nInBufWord = *v58;
  }
  buffer->m_pDataIn = v58 + 1;
LABEL_82:
  if ( buffer->m_bOverflow )
  {
    v51 = 0;
  }
  else
  {
    v59 = buffer->m_nInBufWord;
    v60 = (v59 & CBitBuffer::s_nMaskTable[v57]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v57;
    v61 = v59 >> v57;
    v51 = v60 | v56;
    buffer->m_nInBufWord = v61;
  }
LABEL_85:
  this->m_nStringTableCRC = v51;
  v62 = buffer->m_nBitsAvail;
  if ( v62 < 16 )
  {
    v69 = buffer->m_pBufferEnd;
    v70 = buffer->m_nInBufWord;
    v71 = 16 - v62;
    v72 = buffer->m_pDataIn;
    if ( v72 == v69 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v72 > v69 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_100;
      }
      buffer->m_nInBufWord = *v72;
    }
    buffer->m_pDataIn = v72 + 1;
LABEL_100:
    if ( buffer->m_bOverflow )
    {
      v63 = 0;
    }
    else
    {
      v73 = buffer->m_nInBufWord;
      v74 = (v73 & CBitBuffer::s_nMaskTable[v71]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v71;
      v75 = v73 >> v71;
      v63 = v74 | v70;
      buffer->m_nInBufWord = v75;
    }
    goto LABEL_103;
  }
  v63 = buffer->m_nInBufWord;
  v64 = (unsigned __int16)v63;
  v65 = v62 - 16;
  buffer->m_nBitsAvail = v65;
  if ( v65 != 0 )
  {
    buffer->m_nInBufWord = HIWORD(v63);
    v63 = (unsigned __int16)v63;
  }
  else
  {
    v66 = buffer->m_pDataIn;
    v67 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v66 == v67 )
    {
      buffer->m_pDataIn = v66 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v63 = v64;
    }
    else
    {
      if ( v66 <= v67 )
      {
        v68 = *v66;
        buffer->m_pDataIn = v66 + 1;
        buffer->m_nInBufWord = v68;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v63 = v64;
    }
  }
LABEL_103:
  this->m_nMaxClasses = v63;
  v76 = buffer->m_nBitsAvail;
  if ( v76 >= 32 )
  {
    v77 = buffer->m_nInBufWord;
    v78 = v76 - 32;
    buffer->m_nBitsAvail = v78;
    if ( v78 != 0 )
    {
      buffer->m_nInBufWord = 0;
    }
    else
    {
      v79 = buffer->m_pDataIn;
      v80 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v79 == v80 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v79 + 1;
      }
      else if ( v79 <= v80 )
      {
        buffer->m_nInBufWord = *v79;
        buffer->m_pDataIn = v79 + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
    }
    goto LABEL_120;
  }
  v81 = buffer->m_pBufferEnd;
  v82 = buffer->m_nInBufWord;
  v83 = 32 - v76;
  v84 = buffer->m_pDataIn;
  if ( v84 == v81 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v84 > v81 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_117;
    }
    buffer->m_nInBufWord = *v84;
  }
  buffer->m_pDataIn = v84 + 1;
LABEL_117:
  if ( buffer->m_bOverflow )
  {
    v77 = 0;
  }
  else
  {
    v85 = buffer->m_nInBufWord;
    v86 = (v85 & CBitBuffer::s_nMaskTable[v83]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v83;
    v87 = v85 >> v83;
    v77 = v86 | v82;
    buffer->m_nInBufWord = v87;
  }
LABEL_120:
  this->m_nMapCRC = v77;
  v88 = buffer->m_nBitsAvail;
  if ( v88 < 8 )
  {
    v95 = buffer->m_pBufferEnd;
    v96 = buffer->m_nInBufWord;
    v97 = 8 - v88;
    v98 = buffer->m_pDataIn;
    if ( v98 == v95 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v98 > v95 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_135;
      }
      buffer->m_nInBufWord = *v98;
    }
    buffer->m_pDataIn = v98 + 1;
LABEL_135:
    if ( buffer->m_bOverflow )
    {
      v89 = 0;
    }
    else
    {
      v99 = buffer->m_nInBufWord;
      v100 = (v99 & CBitBuffer::s_nMaskTable[v97]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v97;
      v101 = v99 >> v97;
      v89 = v100 | v96;
      buffer->m_nInBufWord = v101;
    }
    goto LABEL_138;
  }
  v89 = buffer->m_nInBufWord;
  v90 = (unsigned __int8)v89;
  v91 = v88 - 8;
  buffer->m_nBitsAvail = v91;
  if ( v91 != 0 )
  {
    buffer->m_nInBufWord = v89 >> 8;
    v89 = (unsigned __int8)v89;
  }
  else
  {
    v92 = buffer->m_pDataIn;
    v93 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v92 == v93 )
    {
      buffer->m_pDataIn = v92 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v89 = v90;
    }
    else
    {
      if ( v92 <= v93 )
      {
        v94 = *v92;
        buffer->m_pDataIn = v92 + 1;
        buffer->m_nInBufWord = v94;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v89 = v90;
    }
  }
LABEL_138:
  this->m_nPlayerSlot = v89;
  v102 = buffer->m_nBitsAvail;
  if ( v102 < 8 )
  {
    v109 = buffer->m_pBufferEnd;
    v110 = buffer->m_nInBufWord;
    v111 = 8 - v102;
    v112 = buffer->m_pDataIn;
    if ( v112 == v109 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v112 > v109 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_153;
      }
      buffer->m_nInBufWord = *v112;
    }
    buffer->m_pDataIn = v112 + 1;
LABEL_153:
    if ( buffer->m_bOverflow )
    {
      v103 = 0;
    }
    else
    {
      v113 = buffer->m_nInBufWord;
      v114 = (v113 & CBitBuffer::s_nMaskTable[v111]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v111;
      v115 = v113 >> v111;
      v103 = v114 | v110;
      buffer->m_nInBufWord = v115;
    }
    goto LABEL_156;
  }
  v103 = buffer->m_nInBufWord;
  v104 = (unsigned __int8)v103;
  v105 = v102 - 8;
  buffer->m_nBitsAvail = v105;
  if ( v105 != 0 )
  {
    buffer->m_nInBufWord = v103 >> 8;
    v103 = (unsigned __int8)v103;
  }
  else
  {
    v106 = buffer->m_pDataIn;
    v107 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v106 == v107 )
    {
      buffer->m_pDataIn = v106 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v103 = v104;
    }
    else
    {
      if ( v106 <= v107 )
      {
        v108 = *v106;
        buffer->m_pDataIn = v106 + 1;
        buffer->m_nInBufWord = v108;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v103 = v104;
    }
  }
LABEL_156:
  this->m_nMaxClients = v103;
  v116 = buffer->m_nBitsAvail;
  if ( v116 < 32 )
  {
    v121 = buffer->m_pBufferEnd;
    v122 = buffer->m_nInBufWord;
    v123 = 32 - v116;
    v124 = buffer->m_pDataIn;
    if ( v124 == v121 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v124 > v121 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_171;
      }
      buffer->m_nInBufWord = *v124;
    }
    buffer->m_pDataIn = v124 + 1;
LABEL_171:
    if ( buffer->m_bOverflow )
    {
      buffera = nullptr;
    }
    else
    {
      v125 = buffer->m_nInBufWord;
      v126 = (v125 & CBitBuffer::s_nMaskTable[v123]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v123;
      buffera = (bf_read *)(v126 | v122);
      buffer->m_nInBufWord = v125 >> v123;
    }
    goto LABEL_174;
  }
  v117 = buffer->m_nInBufWord;
  v118 = v116 - 32;
  buffer->m_nBitsAvail = v118;
  if ( v118 != 0 )
  {
    buffer->m_nInBufWord = 0;
    buffera = (bf_read *)v117;
  }
  else
  {
    v119 = buffer->m_pDataIn;
    v120 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v119 == v120 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v119 + 1;
      buffera = (bf_read *)v117;
    }
    else
    {
      if ( v119 <= v120 )
      {
        buffer->m_nInBufWord = *v119;
        buffer->m_pDataIn = v119 + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      buffera = (bf_read *)v117;
    }
  }
LABEL_174:
  LODWORD(this->m_fTickInterval) = buffera;
  v127 = buffer->m_nBitsAvail;
  if ( v127 < 8 )
  {
    v134 = buffer->m_pBufferEnd;
    v135 = buffer->m_nInBufWord;
    v136 = 8 - v127;
    v137 = buffer->m_pDataIn;
    if ( v137 == v134 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v137 > v134 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_188:
        if ( !buffer->m_bOverflow )
        {
          v138 = buffer->m_nInBufWord;
          v139 = (v138 & CBitBuffer::s_nMaskTable[v136]) << buffer->m_nBitsAvail;
          buffer->m_nBitsAvail = 32 - v136;
          v131 = v138 >> v136;
          v129 = v139 | v135;
          goto LABEL_191;
        }
        v129 = 0;
        goto LABEL_192;
      }
      buffer->m_nInBufWord = *v137;
    }
    buffer->m_pDataIn = v137 + 1;
    goto LABEL_188;
  }
  v128 = buffer->m_nInBufWord;
  v129 = v128;
  v130 = v127 - 8;
  buffer->m_nBitsAvail = v130;
  if ( v130 != 0 )
  {
    v131 = v128 >> 8;
LABEL_191:
    buffer->m_nInBufWord = v131;
    goto LABEL_192;
  }
  v132 = buffer->m_pDataIn;
  v133 = buffer->m_pBufferEnd;
  buffer->m_nBitsAvail = 32;
  if ( v132 == v133 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_pDataIn = v132 + 1;
  }
  else
  {
    if ( v132 <= v133 )
    {
      v131 = *v132;
      buffer->m_pDataIn = v132 + 1;
      goto LABEL_191;
    }
    buffer->m_bOverflow = true;
    buffer->m_nInBufWord = 0;
  }
LABEL_192:
  this->m_cOS = v129;
  CBitRead::ReadString(this: buffer, pStr, maxLen: 260, bLine: false, pOutNumChars: nullptr);
  CBitRead::ReadString(this: buffer, pStr: m_szMapNameBuffer, maxLen: 260, bLine: false, pOutNumChars: nullptr);
  CBitRead::ReadString(this: buffer, pStr: m_szSkyNameBuffer, maxLen: 260, bLine: false, pOutNumChars: nullptr);
  CBitRead::ReadString(this: buffer, pStr: v141, maxLen: 260, bLine: false, pOutNumChars: nullptr);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BBD70
// Name: public: virtual char const __near * SVC_ServerInfo::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_ServerInfo::ToString(SVC_ServerInfo *this)
{
  const char *v1; // eax
  const char *v3; // [esp-Ch] [ebp-Ch]
  const char *v4; // [esp-8h] [ebp-8h]
  int v5; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_ServerInfo *, const char *, const char *, int))this->GetName)(
                       a1: this,
                       a2: this->m_szGameDir,
                       a3: this->m_szMapName,
                       a4: this->m_nMaxClients);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: game \"%s\", map \"%s\", max %i", v1, v3, v4, v5);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BBDB0
// Name: public: virtual char const __near * NET_SignonState::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall NET_SignonState::ToString(NET_SignonState *this)
{
  const char *v1; // eax
  int v3; // [esp-8h] [ebp-8h]
  int v4; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(NET_SignonState *, int, int))this->GetName)(
                       a1: this,
                       a2: this->m_nSignonState,
                       a3: this->m_nSpawnCount);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: state %i, count %i", v1, v3, v4);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BBDE0
// Name: public: virtual bool SVC_BSPDecal::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_BSPDecal::ReadFromBuffer(SVC_BSPDecal *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // edi
  unsigned int v5; // edx
  const unsigned int *v6; // eax
  const unsigned int *v7; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v10; // eax
  const unsigned int *m_pDataIn; // ecx
  int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // ebx
  SVC_BSPDecal *v15; // edi
  unsigned int v16; // eax
  int v17; // ecx
  bool v18; // zf
  const unsigned int *v19; // eax
  const unsigned int *v20; // edx
  int v21; // ecx
  unsigned int v22; // eax
  int v23; // edx
  int v24; // ecx
  int v25; // eax
  const unsigned int *v26; // eax
  const unsigned int *v27; // ecx
  unsigned int v28; // ecx
  const unsigned int *v29; // edx
  unsigned int v30; // edi
  int v31; // eax
  const unsigned int *v32; // ecx
  unsigned int v33; // edx
  unsigned int v34; // ebx
  unsigned int v35; // edx
  int v36; // ecx
  unsigned int v37; // eax
  int v38; // edi
  int v39; // ecx
  const unsigned int *v40; // eax
  const unsigned int *v41; // ecx
  SVC_BSPDecal *v42; // edx
  const unsigned int *v43; // edx
  unsigned int v44; // edi
  int v45; // eax
  const unsigned int *v46; // ecx
  SVC_BSPDecal *v47; // edx
  unsigned int v48; // edx
  unsigned int v49; // ebx
  unsigned int v50; // eax
  int v51; // ecx
  const unsigned int *v52; // eax
  const unsigned int *v53; // edx

  CBitRead::ReadBitVec3Coord(this: buffer, fa: &this->m_Pos);
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 9 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v10 = 9 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_15:
        if ( buffer->m_bOverflow )
        {
          v12 = 0;
          goto LABEL_20;
        }
        v13 = buffer->m_nInBufWord;
        v14 = (v13 & CBitBuffer::s_nMaskTable[v10]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v10;
        v4 = v14 | m_nInBufWord;
        v5 = v13 >> v10;
        goto LABEL_18;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v3 = buffer->m_nInBufWord;
  v4 = v3 & 0x1FF;
  buffer->m_nBitsAvail = m_nBitsAvail - 9;
  if ( m_nBitsAvail == 9 )
  {
    v6 = buffer->m_pDataIn;
    v7 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v6 == v7 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v6 + 1;
    }
    else if ( v6 <= v7 )
    {
      buffer->m_nInBufWord = *v6;
      buffer->m_pDataIn = v6 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
    goto LABEL_19;
  }
  v5 = v3 >> 9;
LABEL_18:
  buffer->m_nInBufWord = v5;
LABEL_19:
  v12 = v4;
LABEL_20:
  v15 = this;
  this->m_nDecalTextureIndex = v12;
  v16 = buffer->m_nInBufWord;
  v17 = v16 & 1;
  v18 = buffer->m_nBitsAvail-- == 1;
  if ( v18 )
  {
    v19 = buffer->m_pDataIn;
    v20 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v19 == v20 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v19 + 1;
    }
    else if ( v19 <= v20 )
    {
      buffer->m_nInBufWord = *v19;
      buffer->m_pDataIn = v19 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v16 >> 1;
  }
  if ( v17 == 0 )
  {
    this->m_nEntityIndex = 0;
    this->m_nModelIndex = 0;
    goto LABEL_67;
  }
  v21 = buffer->m_nBitsAvail;
  if ( v21 >= 11 )
  {
    v22 = buffer->m_nInBufWord;
    v23 = v22 & 0x7FF;
    v24 = v21 - 11;
    buffer->m_nBitsAvail = v24;
    if ( v24 != 0 )
    {
      buffer->m_nInBufWord = v22 >> 11;
      v25 = v22 & 0x7FF;
    }
    else
    {
      v26 = buffer->m_pDataIn;
      v27 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v26 == v27 )
      {
        buffer->m_pDataIn = v26 + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        v25 = v23;
      }
      else
      {
        if ( v26 <= v27 )
        {
          v28 = *v26;
          buffer->m_pDataIn = v26 + 1;
          buffer->m_nInBufWord = v28;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v25 = v23;
      }
    }
    goto LABEL_47;
  }
  v29 = buffer->m_pBufferEnd;
  v30 = buffer->m_nInBufWord;
  v31 = 11 - v21;
  v32 = buffer->m_pDataIn;
  if ( v32 == v29 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_42:
    buffer->m_pDataIn = v32 + 1;
    goto LABEL_43;
  }
  if ( v32 <= v29 )
  {
    buffer->m_nInBufWord = *v32;
    goto LABEL_42;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_43:
  if ( buffer->m_bOverflow )
  {
    v25 = 0;
  }
  else
  {
    v33 = buffer->m_nInBufWord;
    v34 = (v33 & CBitBuffer::s_nMaskTable[v31]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v31;
    v35 = v33 >> v31;
    v25 = v34 | v30;
    buffer->m_nInBufWord = v35;
  }
  v15 = this;
LABEL_47:
  v15->m_nEntityIndex = v25;
  v36 = buffer->m_nBitsAvail;
  if ( v36 >= 11 )
  {
    v37 = buffer->m_nInBufWord;
    v38 = v37 & 0x7FF;
    v39 = v36 - 11;
    buffer->m_nBitsAvail = v39;
    if ( v39 != 0 )
    {
      buffer->m_nInBufWord = v37 >> 11;
      this->m_nModelIndex = v38;
      v15 = this;
    }
    else
    {
      v40 = buffer->m_pDataIn;
      v41 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v40 == v41 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v40 + 1;
        this->m_nModelIndex = v38;
        v15 = this;
      }
      else
      {
        if ( v40 <= v41 )
        {
          buffer->m_nInBufWord = *v40;
          v42 = this;
          buffer->m_pDataIn = v40 + 1;
        }
        else
        {
          v42 = this;
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v42->m_nModelIndex = v38;
        v15 = v42;
      }
    }
    goto LABEL_67;
  }
  v43 = buffer->m_pBufferEnd;
  v44 = buffer->m_nInBufWord;
  v45 = 11 - v36;
  v46 = buffer->m_pDataIn;
  if ( v46 == v43 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_61:
    buffer->m_pDataIn = v46 + 1;
    goto LABEL_62;
  }
  if ( v46 <= v43 )
  {
    buffer->m_nInBufWord = *v46;
    goto LABEL_61;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_62:
  if ( buffer->m_bOverflow )
  {
    v47 = this;
    this->m_nModelIndex = 0;
  }
  else
  {
    v48 = buffer->m_nInBufWord;
    v49 = (v48 & CBitBuffer::s_nMaskTable[v45]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v45;
    buffer->m_nInBufWord = v48 >> v45;
    v47 = this;
    this->m_nModelIndex = v49 | v44;
  }
  v15 = v47;
LABEL_67:
  v50 = buffer->m_nInBufWord;
  v51 = v50 & 1;
  v18 = buffer->m_nBitsAvail-- == 1;
  if ( v18 )
  {
    v52 = buffer->m_pDataIn;
    v53 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v52 == v53 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v52 + 1;
    }
    else if ( v52 <= v53 )
    {
      buffer->m_nInBufWord = *v52;
      buffer->m_pDataIn = v52 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v50 >> 1;
  }
  v15->m_bLowPriority = v51 != 0;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BC180
// Name: public: virtual char const __near * SVC_BSPDecal::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_BSPDecal::ToString(SVC_BSPDecal *this)
{
  const char *v1; // eax
  int v3; // [esp-10h] [ebp-10h]
  int v4; // [esp-Ch] [ebp-Ch]
  int v5; // [esp-8h] [ebp-8h]
  int v6; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_BSPDecal *, int, int, int, bool))this->GetName)(
                       a1: this,
                       a2: this->m_nDecalTextureIndex,
                       a3: this->m_nEntityIndex,
                       a4: this->m_nModelIndex,
                       a5: this->m_bLowPriority);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: tex %i, ent %i, mod %i lowpriority %i", v1, v3, v4, v5, v6);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BC1C0
// Name: public: virtual bool SVC_SetView::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_SetView::WriteToBuffer(SVC_SetView *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nEntityIndex, numbits: 11, bCheckRange: true);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BC200
// Name: public: virtual bool SVC_SetView::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_SetView::ReadFromBuffer(SVC_SetView *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // ecx
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  unsigned int v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 11 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v12 = 11 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_16;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( buffer->m_bOverflow )
    {
      v6 = 0;
    }
    else
    {
      v14 = buffer->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v12;
      v6 = v15 | m_nInBufWord;
      buffer->m_nInBufWord = v14 >> v12;
    }
    goto LABEL_19;
  }
  v3 = buffer->m_nInBufWord;
  v4 = v3 & 0x7FF;
  v5 = m_nBitsAvail - 11;
  buffer->m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    buffer->m_nInBufWord = v3 >> 11;
    v6 = v3 & 0x7FF;
  }
  else
  {
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      buffer->m_pDataIn = v7 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v6 = v4;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v9 = *v7;
        buffer->m_pDataIn = v7 + 1;
        buffer->m_nInBufWord = v9;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v6 = v4;
    }
  }
LABEL_19:
  this->m_nEntityIndex = v6;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BC310
// Name: public: virtual char const __near * SVC_SetView::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_SetView::ToString(SVC_SetView *this)
{
  const char *v1; // eax
  int v3; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_SetView *, int))this->GetName)(a1: this, a2: this->m_nEntityIndex);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: view entity %i", v1, v3);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BC340
// Name: public: virtual bool SVC_FixAngle::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_FixAngle::ReadFromBuffer(SVC_FixAngle *this, bf_read *buffer)
{
  unsigned int m_nInBufWord; // eax
  int v4; // ecx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // edx

  m_nInBufWord = buffer->m_nInBufWord;
  v4 = m_nInBufWord & 1;
  if ( buffer->m_nBitsAvail-- == 1 )
  {
    m_pDataIn = buffer->m_pDataIn;
    m_pBufferEnd = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      buffer->m_nInBufWord = *m_pDataIn;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = m_nInBufWord >> 1;
  }
  this->m_bRelative = v4 != 0;
  this->m_Angle.x = CBitRead::ReadBitAngle(this: buffer, numbits: 16);
  this->m_Angle.y = CBitRead::ReadBitAngle(this: buffer, numbits: 16);
  this->m_Angle.z = CBitRead::ReadBitAngle(this: buffer, numbits: 16);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BC3E0
// Name: public: virtual char const __near * SVC_FixAngle::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_FixAngle::ToString(SVC_FixAngle *this)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v4; // [esp-1Ch] [ebp-1Ch]
  double v5; // [esp-18h] [ebp-18h]
  double v6; // [esp-10h] [ebp-10h]
  double v7; // [esp-8h] [ebp-8h]

  v1 = "relative";
  if ( !this->m_bRelative )
    v1 = "absolute";
  v2 = (const char *)((int (__thiscall *)(SVC_FixAngle *, const char *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->GetName)(
                       a1: this,
                       a2: v1,
                       a3: COERCE_UNSIGNED_INT64(this->m_Angle.x),
                       a4: HIDWORD(COERCE_UNSIGNED_INT64(this->m_Angle.x)),
                       a5: COERCE_UNSIGNED_INT64(this->m_Angle.y),
                       a6: HIDWORD(COERCE_UNSIGNED_INT64(this->m_Angle.y)),
                       a7: COERCE_UNSIGNED_INT64(this->m_Angle.z),
                       a8: HIDWORD(COERCE_UNSIGNED_INT64(this->m_Angle.z)));
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: %s %.1f %.1f %.1f ", v2, v4, v5, v6, v7);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BC430
// Name: public: virtual bool SVC_CrosshairAngle::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_CrosshairAngle::WriteToBuffer(SVC_CrosshairAngle *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteBitAngle(this: buffer, fAngle: this->m_Angle.x, numbits: 16);
  bf_write::WriteBitAngle(this: buffer, fAngle: this->m_Angle.y, numbits: 16);
  bf_write::WriteBitAngle(this: buffer, fAngle: this->m_Angle.z, numbits: 16);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BC490
// Name: public: virtual bool SVC_CrosshairAngle::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_CrosshairAngle::ReadFromBuffer(SVC_CrosshairAngle *this, bf_read *buffer)
{
  this->m_Angle.x = CBitRead::ReadBitAngle(this: buffer, numbits: 16);
  this->m_Angle.y = CBitRead::ReadBitAngle(this: buffer, numbits: 16);
  this->m_Angle.z = CBitRead::ReadBitAngle(this: buffer, numbits: 16);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BC4D0
// Name: public: virtual char const __near * SVC_CrosshairAngle::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_CrosshairAngle::ToString(SVC_CrosshairAngle *this)
{
  const char *v1; // eax
  double v3; // [esp+0h] [ebp-18h]
  double v4; // [esp+8h] [ebp-10h]
  double v5; // [esp+10h] [ebp-8h]

  v1 = (const char *)((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->GetName)(
                       a1: COERCE_UNSIGNED_INT64(this->m_Angle.x),
                       a2: HIDWORD(COERCE_UNSIGNED_INT64(this->m_Angle.x)),
                       a3: COERCE_UNSIGNED_INT64(this->m_Angle.y),
                       a4: HIDWORD(COERCE_UNSIGNED_INT64(this->m_Angle.y)),
                       a5: COERCE_UNSIGNED_INT64(this->m_Angle.z),
                       a6: HIDWORD(COERCE_UNSIGNED_INT64(this->m_Angle.z)));
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: (%.1f %.1f %.1f)", v1, v3, v4, v5);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BC510
// Name: public: virtual bool SVC_VoiceInit::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_VoiceInit::WriteToBuffer(SVC_VoiceInit *this, bf_write *buffer)
{
  unsigned int v3; // eax
  const char *m_szVoiceCodec; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_szVoiceCodec = this->m_szVoiceCodec;
  if ( m_szVoiceCodec == nullptr )
    m_szVoiceCodec = "svc_voiceinit NULL";
  bf_write::WriteString(this: buffer, pStr: m_szVoiceCodec);
  bf_write::WriteByte(this: buffer, val: this->m_nQuality);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BC560
// Name: public: virtual bool SVC_VoiceInit::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_VoiceInit::ReadFromBuffer(SVC_VoiceInit *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v5; // edx
  int v6; // ecx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  unsigned int v10; // ecx
  const unsigned int *v11; // edx
  unsigned int v12; // edi
  int v13; // eax
  const unsigned int *v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ebx

  this->m_szVoiceCodec = this->m_szVoiceCodecBuffer;
  CBitRead::ReadString(this: buffer, pStr: this->m_szVoiceCodecBuffer, maxLen: 260, bLine: false, pOutNumChars: nullptr);
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 8 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v5 = (unsigned __int8)m_nInBufWord;
    v6 = m_nBitsAvail - 8;
    buffer->m_nBitsAvail = v6;
    if ( v6 != 0 )
    {
      buffer->m_nInBufWord = m_nInBufWord >> 8;
      this->m_nQuality = (unsigned __int8)m_nInBufWord;
      return !buffer->m_bOverflow;
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_pDataIn = m_pDataIn + 1;
        buffer->m_nInBufWord = 0;
        buffer->m_nBitsAvail = 1;
        this->m_nQuality = v5;
        return !buffer->m_bOverflow;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v10 = *m_pDataIn;
          buffer->m_pDataIn = m_pDataIn + 1;
          buffer->m_nInBufWord = v10;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        this->m_nQuality = v5;
        return !buffer->m_bOverflow;
      }
    }
  }
  v11 = buffer->m_pBufferEnd;
  v12 = buffer->m_nInBufWord;
  v13 = 8 - m_nBitsAvail;
  v14 = buffer->m_pDataIn;
  if ( v14 == v11 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_15:
    buffer->m_pDataIn = v14 + 1;
    goto LABEL_16;
  }
  if ( v14 <= v11 )
  {
    buffer->m_nInBufWord = *v14;
    goto LABEL_15;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_16:
  if ( buffer->m_bOverflow )
  {
    this->m_nQuality = 0;
  }
  else
  {
    v15 = buffer->m_nInBufWord;
    v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v13;
    buffer->m_nInBufWord = v15 >> v13;
    this->m_nQuality = v16 | v12;
  }
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BC6E0
// Name: public: virtual char const __near * SVC_VoiceInit::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_VoiceInit::ToString(SVC_VoiceInit *this)
{
  const char *v1; // eax
  const char *v3; // [esp-8h] [ebp-8h]
  int v4; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_VoiceInit *, const char *, int))this->GetName)(
                       a1: this,
                       a2: this->m_szVoiceCodec,
                       a3: this->m_nQuality);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: codec \"%s\", qualitty %i", v1, v3, v4);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BC710
// Name: public: virtual bool SVC_VoiceData::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_VoiceData::WriteToBuffer(SVC_VoiceData *this, bf_write *buffer)
{
  unsigned int v3; // eax
  int m_nDataBits; // ecx
  int v6; // edx
  int v7; // ecx
  int m_iCurBit; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // eax
  unsigned int buffera; // [esp+20h] [ebp+8h]
  unsigned int bufferb; // [esp+20h] [ebp+8h]

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteByte(this: buffer, val: this->m_nFromClient);
  bf_write::WriteByte(this: buffer, val: this->m_bProximity);
  bf_write::WriteWord(this: buffer, val: this->m_nLength);
  m_nDataBits = buffer->m_nDataBits;
  buffera = this->m_bAudible[0];
  if ( buffer->m_iCurBit + 1 <= m_nDataBits )
  {
    v6 = buffer->m_iCurBit >> 5;
    v7 = 32 - (buffer->m_iCurBit & 0x1F);
    *(_DWORD *)&buffer->m_pData[4 * v6] = (buffera << (buffer->m_iCurBit & 0x1F))
                                        | *(_DWORD *)&buffer->m_pData[4 * v6]
                                        & dword_106C73CC[33 * (buffer->m_iCurBit & 0x1F)];
    if ( v7 < 1 )
      *(_DWORD *)&buffer->m_pData[4 * v6 + 4] = (buffera >> v7)
                                              | *(_DWORD *)&buffer->m_pData[4 * v6 + 4] & dword_106C73CC[-v7];
    ++buffer->m_iCurBit;
  }
  else
  {
    buffer->m_iCurBit = m_nDataBits;
    buffer->m_bOverflow = true;
  }
  m_iCurBit = buffer->m_iCurBit;
  bufferb = this->m_bAudible[1];
  v9 = buffer->m_nDataBits;
  if ( m_iCurBit + 1 <= v9 )
  {
    v10 = m_iCurBit >> 5;
    *(_DWORD *)&buffer->m_pData[4 * (buffer->m_iCurBit >> 5)] = (bufferb << (buffer->m_iCurBit & 0x1F))
                                                              | *(_DWORD *)&buffer->m_pData[4 * (buffer->m_iCurBit >> 5)]
                                                              & dword_106C73CC[33 * (buffer->m_iCurBit & 0x1F)];
    v11 = 32 - (m_iCurBit & 0x1F);
    if ( v11 < 1 )
      *(_DWORD *)&buffer->m_pData[4 * v10 + 4] = (bufferb >> v11)
                                               | *(_DWORD *)&buffer->m_pData[4 * v10 + 4] & dword_106C73CC[-v11];
    ++buffer->m_iCurBit;
  }
  else
  {
    buffer->m_iCurBit = v9;
    buffer->m_bOverflow = true;
  }
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BC870
// Name: public: virtual char const __near * SVC_VoiceData::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_VoiceData::ToString(SVC_VoiceData *this)
{
  const char *v1; // eax
  int v3; // [esp-8h] [ebp-8h]
  int v4; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_VoiceData *, int, int))this->GetName)(
                       a1: this,
                       a2: this->m_nFromClient,
                       a3: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: client %i, bytes %i", v1, v3, v4);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BC8B0
// Name: public: virtual bool NET_Tick::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NET_Tick::ReadFromBuffer(NET_Tick *this, bf_read *buffer)
{
  int m_nBitsAvail; // esi
  int m_nInBufWord; // ecx
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // esi
  const unsigned int *v6; // ecx
  unsigned int v7; // edi
  int v8; // edx
  const unsigned int *v9; // esi
  unsigned int v10; // esi
  unsigned int v11; // ebx
  int v12; // ecx
  unsigned int v13; // edx
  int v14; // esi
  int v15; // ecx
  int v16; // ecx
  const unsigned int *v17; // ecx
  const unsigned int *v18; // edx
  unsigned int v19; // edx
  const unsigned int *v20; // esi
  unsigned int v21; // edi
  int v22; // edx
  const unsigned int *v23; // ecx
  unsigned int v24; // esi
  unsigned int v25; // ebx
  int v26; // ecx
  unsigned int v27; // edx
  int v28; // esi
  int v29; // ecx
  int v30; // ecx
  const unsigned int *v31; // ecx
  const unsigned int *v32; // edx
  unsigned int v33; // edx
  const unsigned int *v34; // esi
  unsigned int v35; // edi
  int v36; // edx
  const unsigned int *v37; // ecx
  unsigned int v38; // esi
  unsigned int v39; // ebx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 32 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    buffer->m_nBitsAvail = m_nBitsAvail - 32;
    if ( m_nBitsAvail == 32 )
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        buffer->m_nInBufWord = *m_pDataIn;
        buffer->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
    }
    else
    {
      buffer->m_nInBufWord = 0;
    }
    goto LABEL_18;
  }
  v6 = buffer->m_pDataIn;
  v7 = buffer->m_nInBufWord;
  v8 = 32 - m_nBitsAvail;
  v9 = buffer->m_pBufferEnd;
  if ( v6 == v9 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v6 > v9 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_15;
    }
    buffer->m_nInBufWord = *v6;
  }
  buffer->m_pDataIn = v6 + 1;
LABEL_15:
  if ( buffer->m_bOverflow )
  {
    m_nInBufWord = 0;
  }
  else
  {
    v10 = buffer->m_nInBufWord;
    v11 = (v10 & CBitBuffer::s_nMaskTable[v8]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v8;
    m_nInBufWord = v11 | v7;
    buffer->m_nInBufWord = v10 >> v8;
  }
LABEL_18:
  this->m_nTick = m_nInBufWord;
  v12 = buffer->m_nBitsAvail;
  if ( v12 < 16 )
  {
    v20 = buffer->m_pBufferEnd;
    v21 = buffer->m_nInBufWord;
    v22 = 16 - v12;
    v23 = buffer->m_pDataIn;
    if ( v23 == v20 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v23 > v20 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_33;
      }
      buffer->m_nInBufWord = *v23;
    }
    buffer->m_pDataIn = v23 + 1;
LABEL_33:
    if ( buffer->m_bOverflow )
    {
      v16 = 0;
    }
    else
    {
      v24 = buffer->m_nInBufWord;
      v25 = (v24 & CBitBuffer::s_nMaskTable[v22]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v22;
      v16 = v25 | v21;
      buffer->m_nInBufWord = v24 >> v22;
    }
    goto LABEL_36;
  }
  v13 = buffer->m_nInBufWord;
  v14 = (unsigned __int16)v13;
  v15 = v12 - 16;
  buffer->m_nBitsAvail = v15;
  if ( v15 != 0 )
  {
    buffer->m_nInBufWord = HIWORD(v13);
    v16 = (unsigned __int16)v13;
  }
  else
  {
    v17 = buffer->m_pDataIn;
    v18 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v17 == v18 )
    {
      buffer->m_pDataIn = v17 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v16 = v14;
    }
    else
    {
      if ( v17 <= v18 )
      {
        v19 = *v17;
        buffer->m_pDataIn = v17 + 1;
        buffer->m_nInBufWord = v19;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v16 = v14;
    }
  }
LABEL_36:
  this->m_flHostFrameTime = (double)(unsigned int)v16 * 0.0000099999997;
  v26 = buffer->m_nBitsAvail;
  if ( v26 < 16 )
  {
    v34 = buffer->m_pBufferEnd;
    v35 = buffer->m_nInBufWord;
    v36 = 16 - v26;
    v37 = buffer->m_pDataIn;
    if ( v37 == v34 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v37 > v34 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_51;
      }
      buffer->m_nInBufWord = *v37;
    }
    buffer->m_pDataIn = v37 + 1;
LABEL_51:
    if ( buffer->m_bOverflow )
    {
      v30 = 0;
    }
    else
    {
      v38 = buffer->m_nInBufWord;
      v39 = (v38 & CBitBuffer::s_nMaskTable[v36]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v36;
      v30 = v39 | v35;
      buffer->m_nInBufWord = v38 >> v36;
    }
    goto LABEL_54;
  }
  v27 = buffer->m_nInBufWord;
  v28 = (unsigned __int16)v27;
  v29 = v26 - 16;
  buffer->m_nBitsAvail = v29;
  if ( v29 != 0 )
  {
    buffer->m_nInBufWord = HIWORD(v27);
    v30 = (unsigned __int16)v27;
  }
  else
  {
    v31 = buffer->m_pDataIn;
    v32 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v31 == v32 )
    {
      buffer->m_pDataIn = v31 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v30 = v28;
    }
    else
    {
      if ( v31 <= v32 )
      {
        v33 = *v31;
        buffer->m_pDataIn = v31 + 1;
        buffer->m_nInBufWord = v33;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v30 = v28;
    }
  }
LABEL_54:
  this->m_flHostFrameTimeStdDeviation = 0.0000099999997 * (double)(unsigned int)v30;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BCB90
// Name: public: virtual char const __near * CLC_BaselineAck::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLC_BaselineAck::ToString(NET_Tick *this)
{
  const char *v1; // eax
  int v3; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(NET_Tick *, int))this->GetName)(a1: this, a2: this->m_nTick);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: tick %i", v1, v3);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BCBC0
// Name: public: virtual bool NET_SplitScreenUser::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall NET_SplitScreenUser::WriteToBuffer(NET_SplitScreenUser *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nSlot, numbits: 1, bCheckRange: true);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BCC00
// Name: public: virtual bool NET_SplitScreenUser::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NET_SplitScreenUser::ReadFromBuffer(NET_SplitScreenUser *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // ecx
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  unsigned int v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 1 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v12 = 1 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_16;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( buffer->m_bOverflow )
    {
      v6 = 0;
    }
    else
    {
      v14 = buffer->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v12;
      v6 = v15 | m_nInBufWord;
      buffer->m_nInBufWord = v14 >> v12;
    }
    goto LABEL_19;
  }
  v3 = buffer->m_nInBufWord;
  v4 = v3 & 1;
  v5 = m_nBitsAvail - 1;
  buffer->m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    buffer->m_nInBufWord = v3 >> 1;
    v6 = v3 & 1;
  }
  else
  {
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      buffer->m_pDataIn = v7 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v6 = v4;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v9 = *v7;
        buffer->m_pDataIn = v7 + 1;
        buffer->m_nInBufWord = v9;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v6 = v4;
    }
  }
LABEL_19:
  this->m_nSlot = v6;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BCD00
// Name: public: virtual char const __near * NET_SplitScreenUser::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall NET_SplitScreenUser::ToString(NET_SplitScreenUser *this)
{
  const char *v1; // eax
  int v3; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(NET_SplitScreenUser *, int))this->GetName)(a1: this, a2: this->m_nSlot);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: slot %d", v1, v3);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BCD30
// Name: public: virtual bool SVC_UserMessage::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_UserMessage::WriteToBuffer(SVC_UserMessage *this, bf_write *buffer)
{
  unsigned int v3; // eax
  unsigned int m_nMsgType; // [esp-4h] [ebp-Ch]

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_nMsgType = this->m_nMsgType;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  bf_write::WriteByte(this: buffer, val: m_nMsgType);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 12, bCheckRange: true);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BCD90
// Name: public: virtual char const __near * SVC_UserMessage::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_UserMessage::ToString(SVC_UserMessage *this)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v5; // [esp-8h] [ebp-Ch]
  int v6; // [esp-4h] [ebp-8h]

  v2 = CUtlString::operator char const *(this: &this->m_sDebugName);
  v3 = (const char *)((int (__thiscall *)(SVC_UserMessage *, const char *, int))this->GetName)(
                       a1: this,
                       a2: v2,
                       a3: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s(%s): bytes %i", v3, v5, v6);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BCDD0
// Name: public: virtual bool SVC_SetPause::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_SetPause::ReadFromBuffer(SVC_SetPause *this, bf_read *buffer)
{
  unsigned int m_nInBufWord; // edx
  int v3; // esi
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // edi

  m_nInBufWord = buffer->m_nInBufWord;
  v3 = m_nInBufWord & 1;
  if ( buffer->m_nBitsAvail-- == 1 )
  {
    m_pDataIn = buffer->m_pDataIn;
    m_pBufferEnd = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      buffer->m_nInBufWord = *m_pDataIn;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = m_nInBufWord >> 1;
  }
  this->m_bPaused = v3 != 0;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BCE50
// Name: public: virtual char const __near * SVC_SetPause::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_SetPause::ToString(SVC_SetPause *this)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v4; // [esp-4h] [ebp-4h]

  v1 = "paused";
  if ( !this->m_bPaused )
    v1 = "unpaused";
  v2 = (const char *)((int (__thiscall *)(SVC_SetPause *, const char *))this->GetName)(a1: this, a2: v1);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: %s", v2, v4);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BCE90
// Name: public: virtual char const __near * SVC_UpdateStringTable::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_UpdateStringTable::ToString(SVC_UpdateStringTable *this)
{
  const char *v1; // eax
  int v3; // [esp-Ch] [ebp-Ch]
  int v4; // [esp-8h] [ebp-8h]
  int v5; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_UpdateStringTable *, int, int, int))this->GetName)(
                       a1: this,
                       a2: this->m_nTableID,
                       a3: this->m_nChangedEntries,
                       a4: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: table %i, changed %i, bytes %i", v1, v3, v4, v5);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BCED0
// Name: public: virtual char const __near * SVC_CreateStringTable::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_CreateStringTable::ToString(SVC_CreateStringTable *this)
{
  const char *v1; // eax
  const char *v3; // [esp-14h] [ebp-14h]
  int v4; // [esp-10h] [ebp-10h]
  int v5; // [esp-Ch] [ebp-Ch]
  int v6; // [esp-8h] [ebp-8h]
  int v7; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_CreateStringTable *, const char *, int, int, int, int))this->GetName)(
                       a1: this,
                       a2: this->m_szTableName,
                       a3: this->m_nNumEntries,
                       a4: (this->m_nLength + 7) >> 3,
                       a5: this->m_nUserDataSize,
                       a6: this->m_nUserDataSizeBits);
  V_snprintf(
    pDest: s_text,
    maxLen: 1024,
    pFormat: "%s: table %s, entries %i, bytes %i userdatasize %i userdatabits %i",
    v1,
    v3,
    v4,
    v5,
    v6,
    v7);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BCF10
// Name: public: virtual char const __near * SVC_Sounds::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_Sounds::ToString(SVC_Sounds *this)
{
  const char *v1; // eax
  const char *v2; // eax
  int v4; // [esp-Ch] [ebp-Ch]
  const char *v5; // [esp-8h] [ebp-8h]
  int v6; // [esp-4h] [ebp-4h]

  v1 = " reliable,";
  if ( !this->m_bReliableSound )
    v1 = defaultValue;
  v2 = (const char *)((int (__thiscall *)(SVC_Sounds *, int, const char *, int))this->GetName)(
                       a1: this,
                       a2: this->m_nNumSounds,
                       a3: v1,
                       a4: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: number %i,%s bytes %i", v2, v4, v5, v6);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BCF60
// Name: public: virtual bool SVC_Prefetch::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_Prefetch::WriteToBuffer(SVC_Prefetch *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nSoundIndex, numbits: 13, bCheckRange: true);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BCFA0
// Name: public: virtual bool SVC_Prefetch::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_Prefetch::ReadFromBuffer(SVC_Prefetch *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  unsigned __int16 v4; // si
  int v5; // ecx
  unsigned __int16 v6; // cx
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  unsigned int v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx

  this->m_fType = 0;
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 13 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v12 = 13 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_16;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( buffer->m_bOverflow )
    {
      v6 = 0;
    }
    else
    {
      v14 = buffer->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v12;
      v6 = v15 | m_nInBufWord;
      buffer->m_nInBufWord = v14 >> v12;
    }
    goto LABEL_19;
  }
  v3 = buffer->m_nInBufWord;
  v4 = v3 & 0x1FFF;
  v5 = m_nBitsAvail - 13;
  buffer->m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    buffer->m_nInBufWord = v3 >> 13;
    v6 = v3 & 0x1FFF;
  }
  else
  {
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      buffer->m_pDataIn = v7 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v6 = v4;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v9 = *v7;
        buffer->m_pDataIn = v7 + 1;
        buffer->m_nInBufWord = v9;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v6 = v4;
    }
  }
LABEL_19:
  this->m_nSoundIndex = v6;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BD0B0
// Name: public: virtual char const __near * SVC_Prefetch::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_Prefetch::ToString(SVC_Prefetch *this)
{
  const char *v1; // eax
  int v3; // [esp-8h] [ebp-8h]
  int v4; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_Prefetch *, _DWORD, _DWORD))this->GetName)(
                       a1: this,
                       a2: this->m_fType,
                       a3: this->m_nSoundIndex);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: type %i index %i", v1, v3, v4);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD0E0
// Name: public: virtual bool SVC_TempEntities::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_TempEntities::WriteToBuffer(SVC_TempEntities *this, bf_write *buffer)
{
  SVC_TempEntities_vtbl *v3; // edx
  unsigned int v4; // eax

  v3 = this->__vftable;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  v4 = ((int (*)(void))v3->GetType)();
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nNumEntries, numbits: 8, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 17, bCheckRange: true);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BD140
// Name: public: virtual char const __near * SVC_TempEntities::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_TempEntities::ToString(SVC_GameEventList *this)
{
  const char *v1; // eax
  int v3; // [esp-8h] [ebp-8h]
  int v4; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_GameEventList *, int, int))this->GetName)(
                       a1: this,
                       a2: this->m_nNumEvents,
                       a3: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: number %i, bytes %i", v1, v3, v4);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD180
// Name: public: virtual char const __near * SVC_ClassInfo::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_ClassInfo::ToString(SVC_ClassInfo *this)
{
  const char *v1; // eax
  const char *v2; // eax
  int v4; // [esp-8h] [ebp-8h]
  const char *v5; // [esp-4h] [ebp-4h]

  v1 = "use client classes";
  if ( !this->m_bCreateOnClient )
    v1 = "full update";
  v2 = (const char *)((int (__thiscall *)(SVC_ClassInfo *, int, const char *))this->GetName)(
                       a1: this,
                       a2: this->m_nNumServerClasses,
                       a3: v1);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: num %i, %s", v2, v4, v5);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD1C0
// Name: public: virtual bool SVC_GameEvent::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_GameEvent::WriteToBuffer(SVC_GameEvent *this, bf_write *buffer)
{
  SVC_GameEvent_vtbl *v3; // edx
  unsigned int v4; // eax

  v3 = this->__vftable;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  v4 = ((int (*)(void))v3->GetType)();
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 11, bCheckRange: true);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BD210
// Name: public: virtual char const __near * SVC_SendTable::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_SendTable::ToString(SVC_SendTable *this)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v4; // [esp-8h] [ebp-8h]
  int v5; // [esp-4h] [ebp-4h]

  v1 = "yes";
  if ( !this->m_bNeedsDecoder )
    v1 = "no";
  v2 = (const char *)((int (__thiscall *)(SVC_SendTable *, const char *, int))this->GetName)(
                       a1: this,
                       a2: v1,
                       a3: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: needs Decoder %s,bytes %i", v2, v4, v5);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD250
// Name: public: virtual bool SVC_EntityMessage::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_EntityMessage::WriteToBuffer(SVC_EntityMessage *this, bf_write *buffer)
{
  SVC_EntityMessage_vtbl *v3; // edx
  unsigned int v4; // eax

  v3 = this->__vftable;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  v4 = ((int (*)(void))v3->GetType)();
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nEntityIndex, numbits: 11, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nClassID, numbits: 9, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 11, bCheckRange: true);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BD2C0
// Name: public: virtual char const __near * SVC_EntityMessage::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_EntityMessage::ToString(SVC_EntityMessage *this)
{
  const char *v1; // eax
  int v3; // [esp-Ch] [ebp-Ch]
  int v4; // [esp-8h] [ebp-8h]
  int v5; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_EntityMessage *, int, int, int))this->GetName)(
                       a1: this,
                       a2: this->m_nEntityIndex,
                       a3: this->m_nClassID,
                       a4: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: entity %i, class %i, bytes %i", v1, v3, v4, v5);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD300
// Name: public: virtual char const __near * SVC_PacketEntities::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_PacketEntities::ToString(SVC_PacketEntities *this)
{
  const char *v1; // eax
  const char *v2; // eax
  int v4; // [esp-14h] [ebp-14h]
  int v5; // [esp-10h] [ebp-10h]
  int v6; // [esp-Ch] [ebp-Ch]
  const char *v7; // [esp-8h] [ebp-8h]
  int v8; // [esp-4h] [ebp-4h]

  v1 = " BL update,";
  if ( !this->m_bUpdateBaseline )
    v1 = defaultValue;
  v2 = (const char *)((int (__thiscall *)(SVC_PacketEntities *, int, int, int, const char *, int))this->GetName)(
                       a1: this,
                       a2: this->m_nDeltaFrom,
                       a3: this->m_nMaxEntries,
                       a4: this->m_nUpdatedEntries,
                       a5: v1,
                       a6: (this->m_nLength + 7) >> 3);
  V_snprintf(
    pDest: s_text,
    maxLen: 1024,
    pFormat: "%s: delta %i, max %i, changed %i,%s bytes %i",
    v2,
    v4,
    v5,
    v6,
    v7,
    v8);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD350
// Name: public: virtual SVC_Menu::~SVC_Menu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SVC_Menu::~SVC_Menu(SVC_Menu *this)
{
  KeyValues *m_MenuKeyValues; // ecx

  m_MenuKeyValues = this->m_MenuKeyValues;
  this->__vftable = (SVC_Menu_vtbl *)&SVC_Menu::`vftable';
  if ( m_MenuKeyValues != nullptr )
    KeyValues::deleteThis(this: m_MenuKeyValues);
  this->__vftable = (SVC_Menu_vtbl *)&INetMessage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x101BD370
// Name: public: virtual char const __near * SVC_Menu::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_Menu::ToString(SVC_Menu *this)
{
  KeyValues *m_MenuKeyValues; // ecx
  const char *Name; // eax
  const char *v4; // eax
  int v6; // [esp-Ch] [ebp-10h]
  const char *v7; // [esp-8h] [ebp-Ch]
  int v8; // [esp-4h] [ebp-8h]

  m_MenuKeyValues = this->m_MenuKeyValues;
  if ( m_MenuKeyValues != nullptr )
    Name = KeyValues::GetName(this: m_MenuKeyValues);
  else
    Name = "No KeyValues";
  v4 = (const char *)((int (__thiscall *)(SVC_Menu *, DIALOG_TYPE, const char *, int))this->GetName)(
                       a1: this,
                       a2: this->m_Type,
                       a3: Name,
                       a4: this->m_iLength);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: %i \"%s\" (len:%i)", v4, v6, v7, v8);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD3C0
// Name: public: virtual bool SVC_GameEventList::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_GameEventList::WriteToBuffer(SVC_GameEventList *this, bf_write *buffer)
{
  SVC_GameEventList_vtbl *v3; // edx
  unsigned int v4; // eax

  v3 = this->__vftable;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  v4 = ((int (*)(void))v3->GetType)();
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nNumEvents, numbits: 9, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 20, bCheckRange: true);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BD420
// Name: public: virtual bool SVC_SplitScreen::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_SplitScreen::WriteToBuffer(SVC_SplitScreen *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_Type, numbits: 1, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nSlot, numbits: 1, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nPlayerIndex, numbits: 11, bCheckRange: true);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BD480
// Name: public: virtual bool SVC_SplitScreen::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_SplitScreen::ReadFromBuffer(SVC_SplitScreen *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // esi
  int v5; // ecx
  SVC_SplitScreen::ESplitScreenMessageType v6; // ecx
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  unsigned int v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx
  int v16; // ecx
  unsigned int v17; // edx
  int v18; // esi
  int v19; // ecx
  int v20; // ecx
  const unsigned int *v21; // ecx
  const unsigned int *v22; // edx
  unsigned int v23; // edx
  const unsigned int *v24; // esi
  unsigned int v25; // edi
  int v26; // edx
  const unsigned int *v27; // ecx
  unsigned int v28; // esi
  unsigned int v29; // ebx
  int v30; // ecx
  unsigned int v31; // edx
  int v32; // esi
  int v33; // ecx
  int v34; // ecx
  const unsigned int *v35; // ecx
  const unsigned int *v36; // edx
  unsigned int v37; // edx
  const unsigned int *v38; // esi
  unsigned int v39; // edi
  int v40; // edx
  const unsigned int *v41; // ecx
  unsigned int v42; // esi
  unsigned int v43; // ebx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 1 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v12 = 1 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_16;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( buffer->m_bOverflow )
    {
      v6 = MSG_ADDUSER;
    }
    else
    {
      v14 = buffer->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v12;
      v6 = v15 | m_nInBufWord;
      buffer->m_nInBufWord = v14 >> v12;
    }
    goto LABEL_19;
  }
  v3 = buffer->m_nInBufWord;
  v4 = v3 & 1;
  v5 = m_nBitsAvail - 1;
  buffer->m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    buffer->m_nInBufWord = v3 >> 1;
    v6 = v3 & 1;
  }
  else
  {
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      buffer->m_pDataIn = v7 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v6 = v4;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v9 = *v7;
        buffer->m_pDataIn = v7 + 1;
        buffer->m_nInBufWord = v9;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v6 = v4;
    }
  }
LABEL_19:
  this->m_Type = v6;
  v16 = buffer->m_nBitsAvail;
  if ( v16 < 1 )
  {
    v24 = buffer->m_pBufferEnd;
    v25 = buffer->m_nInBufWord;
    v26 = 1 - v16;
    v27 = buffer->m_pDataIn;
    if ( v27 == v24 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v27 > v24 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_34;
      }
      buffer->m_nInBufWord = *v27;
    }
    buffer->m_pDataIn = v27 + 1;
LABEL_34:
    if ( buffer->m_bOverflow )
    {
      v20 = 0;
    }
    else
    {
      v28 = buffer->m_nInBufWord;
      v29 = (v28 & CBitBuffer::s_nMaskTable[v26]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v26;
      v20 = v29 | v25;
      buffer->m_nInBufWord = v28 >> v26;
    }
    goto LABEL_37;
  }
  v17 = buffer->m_nInBufWord;
  v18 = v17 & 1;
  v19 = v16 - 1;
  buffer->m_nBitsAvail = v19;
  if ( v19 != 0 )
  {
    buffer->m_nInBufWord = v17 >> 1;
    v20 = v17 & 1;
  }
  else
  {
    v21 = buffer->m_pDataIn;
    v22 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v21 == v22 )
    {
      buffer->m_pDataIn = v21 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v20 = v18;
    }
    else
    {
      if ( v21 <= v22 )
      {
        v23 = *v21;
        buffer->m_pDataIn = v21 + 1;
        buffer->m_nInBufWord = v23;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v20 = v18;
    }
  }
LABEL_37:
  this->m_nSlot = v20;
  v30 = buffer->m_nBitsAvail;
  if ( v30 < 11 )
  {
    v38 = buffer->m_pBufferEnd;
    v39 = buffer->m_nInBufWord;
    v40 = 11 - v30;
    v41 = buffer->m_pDataIn;
    if ( v41 == v38 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v41 > v38 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_52;
      }
      buffer->m_nInBufWord = *v41;
    }
    buffer->m_pDataIn = v41 + 1;
LABEL_52:
    if ( buffer->m_bOverflow )
    {
      v34 = 0;
    }
    else
    {
      v42 = buffer->m_nInBufWord;
      v43 = (v42 & CBitBuffer::s_nMaskTable[v40]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v40;
      v34 = v43 | v39;
      buffer->m_nInBufWord = v42 >> v40;
    }
    goto LABEL_55;
  }
  v31 = buffer->m_nInBufWord;
  v32 = v31 & 0x7FF;
  v33 = v30 - 11;
  buffer->m_nBitsAvail = v33;
  if ( v33 != 0 )
  {
    buffer->m_nInBufWord = v31 >> 11;
    v34 = v31 & 0x7FF;
  }
  else
  {
    v35 = buffer->m_pDataIn;
    v36 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v35 == v36 )
    {
      buffer->m_pDataIn = v35 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v34 = v32;
    }
    else
    {
      if ( v35 <= v36 )
      {
        v37 = *v35;
        buffer->m_pDataIn = v35 + 1;
        buffer->m_nInBufWord = v37;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v34 = v32;
    }
  }
LABEL_55:
  this->m_nPlayerIndex = v34;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BD740
// Name: public: virtual char const __near * SVC_SplitScreen::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_SplitScreen::ToString(SVC_SplitScreen *this)
{
  SVC_SplitScreen::ESplitScreenMessageType m_Type; // eax
  const char *v2; // edx
  const char *v3; // eax
  const char *v5; // [esp-Ch] [ebp-Ch]
  int v6; // [esp-8h] [ebp-8h]
  int v7; // [esp-4h] [ebp-4h]

  m_Type = this->m_Type;
  v2 = "adduser";
  if ( m_Type != MSG_ADDUSER )
  {
    if ( m_Type == MSG_REMOVEUSER )
      v2 = "removeuser";
  }
  else
  {
    v2 = "adduser";
  }
  v3 = (const char *)((int (__thiscall *)(SVC_SplitScreen *, const char *, int, int))this->GetName)(
                       a1: this,
                       a2: v2,
                       a3: this->m_nSlot,
                       a4: this->m_nPlayerIndex);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: %s slot %d [%d]", v3, v5, v6, v7);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD790
// Name: public: virtual bool SVC_GetCvarValue::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_GetCvarValue::WriteToBuffer(SVC_GetCvarValue *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteSBitLong(this: buffer, data: this->m_iCookie, numbits: 32);
  bf_write::WriteString(this: buffer, pStr: this->m_szCvarName);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BD7E0
// Name: public: virtual bool SVC_GetCvarValue::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_GetCvarValue::ReadFromBuffer(SVC_GetCvarValue *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  int m_nInBufWord; // eax
  int v4; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  const unsigned int *v7; // edx
  unsigned int v8; // edi
  int v9; // eax
  const unsigned int *v10; // ecx
  unsigned int v11; // edx
  unsigned int v12; // ebx
  unsigned int v13; // edx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 32 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v4 = m_nBitsAvail - 32;
    buffer->m_nBitsAvail = v4;
    if ( v4 == 0 )
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = m_pDataIn + 1;
        goto LABEL_18;
      }
      if ( m_pDataIn <= m_pBufferEnd )
      {
        buffer->m_nInBufWord = *m_pDataIn;
        buffer->m_pDataIn = m_pDataIn + 1;
        goto LABEL_18;
      }
      buffer->m_bOverflow = true;
    }
    buffer->m_nInBufWord = 0;
    goto LABEL_18;
  }
  v7 = buffer->m_pBufferEnd;
  v8 = buffer->m_nInBufWord;
  v9 = 32 - m_nBitsAvail;
  v10 = buffer->m_pDataIn;
  if ( v10 == v7 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v10 > v7 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_15;
    }
    buffer->m_nInBufWord = *v10;
  }
  buffer->m_pDataIn = v10 + 1;
LABEL_15:
  if ( buffer->m_bOverflow )
  {
    m_nInBufWord = 0;
  }
  else
  {
    v11 = buffer->m_nInBufWord;
    v12 = (v11 & CBitBuffer::s_nMaskTable[v9]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v9;
    v13 = v11 >> v9;
    m_nInBufWord = v12 | v8;
    buffer->m_nInBufWord = v13;
  }
LABEL_18:
  this->m_iCookie = m_nInBufWord;
  CBitRead::ReadString(this: buffer, pStr: this->m_szCvarNameBuffer, maxLen: 256, bLine: false, pOutNumChars: nullptr);
  this->m_szCvarName = this->m_szCvarNameBuffer;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BD8F0
// Name: public: virtual char const __near * SVC_GetCvarValue::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_GetCvarValue::ToString(SVC_GetCvarValue *this)
{
  const char *v1; // eax
  const char *v3; // [esp-8h] [ebp-8h]
  int v4; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_GetCvarValue *, const char *, int))this->GetName)(
                       a1: this,
                       a2: this->m_szCvarName,
                       a3: this->m_iCookie);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: cvar: %s, cookie: %d", v1, v3, v4);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD920
// Name: public: virtual bool SVC_PaintmapData::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_PaintmapData::WriteToBuffer(SVC_PaintmapData *this, bf_write *buffer)
{
  SVC_PaintmapData_vtbl *v3; // edx
  unsigned int v4; // eax

  v3 = this->__vftable;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  v4 = ((int (*)(void))v3->GetType)();
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 6, bCheckRange: true);
  bf_write::WriteLong(this: buffer, val: this->m_nLength);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BD970
// Name: public: virtual char const __near * SVC_PaintmapData::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_PaintmapData::ToString(SVC_PaintmapData *this)
{
  const char *v1; // eax
  int v3; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_PaintmapData *, int))this->GetName)(
                       a1: this,
                       a2: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: bytes %i", v1, v3);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD9A0
// Name: public: virtual bool CLC_VoiceData::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_VoiceData::ReadFromBuffer(CLC_VoiceData *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  unsigned int v5; // edx
  int v6; // ecx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  unsigned int v9; // ecx
  const unsigned int *v10; // edx
  unsigned int v11; // esi
  int v12; // eax
  const unsigned int *v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // edi
  int v16; // esi
  unsigned int v17; // edx
  int LongLong; // eax
  int v19; // edx
  int m_nLength; // edx
  const unsigned int *m_pData; // eax
  int m_nDataBits; // eax
  CLC_VoiceData *v24; // [esp+Ch] [ebp-4h]

  m_nBitsAvail = buffer->m_nBitsAvail;
  v24 = this;
  if ( m_nBitsAvail >= 16 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v5 = (unsigned __int16)m_nInBufWord;
    v6 = m_nBitsAvail - 16;
    buffer->m_nBitsAvail = v6;
    if ( v6 != 0 )
    {
      buffer->m_nInBufWord = HIWORD(m_nInBufWord);
      m_nInBufWord = (unsigned __int16)m_nInBufWord;
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_pDataIn = m_pDataIn + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        m_nInBufWord = v5;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v9 = *m_pDataIn;
          buffer->m_pDataIn = m_pDataIn + 1;
          buffer->m_nInBufWord = v9;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        m_nInBufWord = v5;
      }
    }
    goto LABEL_19;
  }
  v10 = buffer->m_pBufferEnd;
  v11 = buffer->m_nInBufWord;
  v12 = 16 - m_nBitsAvail;
  v13 = buffer->m_pDataIn;
  if ( v13 == v10 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v13 > v10 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_16;
    }
    buffer->m_nInBufWord = *v13;
  }
  buffer->m_pDataIn = v13 + 1;
LABEL_16:
  if ( buffer->m_bOverflow )
  {
    m_nInBufWord = 0;
  }
  else
  {
    v14 = buffer->m_nInBufWord;
    v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v12;
    v16 = v15 | v11;
    this = v24;
    v17 = v14 >> v12;
    m_nInBufWord = v16;
    buffer->m_nInBufWord = v17;
  }
LABEL_19:
  this->m_nLength = m_nInBufWord;
  LongLong = CBitRead::ReadLongLong(this: buffer);
  HIDWORD(this->m_xuid) = v19;
  m_nLength = v24->m_nLength;
  LODWORD(this->m_xuid) = LongLong;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: m_nLength);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: m_nDataBits + m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BDB10
// Name: public: virtual bool CLC_Move::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_Move::ReadFromBuffer(CLC_Move *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // ebx
  int v7; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v10; // edx
  const unsigned int *v11; // esi
  unsigned int v12; // edi
  int v13; // edx
  const unsigned int *v14; // ecx
  unsigned int v15; // esi
  unsigned int v16; // ebx
  int v17; // ecx
  unsigned int v18; // edx
  int v19; // esi
  int v20; // ecx
  int v21; // ecx
  const unsigned int *v22; // ecx
  const unsigned int *v23; // edx
  unsigned int v24; // edx
  const unsigned int *v25; // esi
  unsigned int v26; // edi
  int v27; // edx
  const unsigned int *v28; // ecx
  unsigned int v29; // esi
  unsigned int v30; // ebx
  int v31; // ecx
  unsigned int v32; // edx
  int v33; // esi
  int v34; // ecx
  const unsigned int *v35; // ecx
  const unsigned int *v36; // edx
  unsigned int v37; // edx
  const unsigned int *v38; // esi
  unsigned int v39; // edi
  int v40; // edx
  const unsigned int *v41; // ecx
  unsigned int v42; // esi
  unsigned int v43; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 4 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v4 = m_nInBufWord & 0xF;
    v5 = m_nBitsAvail - 4;
    v6 = 0;
    buffer->m_nBitsAvail = v5;
    if ( v5 != 0 )
    {
      buffer->m_nInBufWord = m_nInBufWord >> 4;
      v7 = m_nInBufWord & 0xF;
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_pDataIn = m_pDataIn + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        v7 = v4;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v10 = *m_pDataIn;
          buffer->m_pDataIn = m_pDataIn + 1;
          buffer->m_nInBufWord = v10;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v7 = v4;
      }
    }
    goto LABEL_20;
  }
  v11 = buffer->m_pBufferEnd;
  v12 = buffer->m_nInBufWord;
  v13 = 4 - m_nBitsAvail;
  v14 = buffer->m_pDataIn;
  if ( v14 == v11 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_15:
    buffer->m_pDataIn = v14 + 1;
    goto LABEL_16;
  }
  if ( v14 <= v11 )
  {
    buffer->m_nInBufWord = *v14;
    goto LABEL_15;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_16:
  if ( buffer->m_bOverflow )
  {
    v7 = 0;
  }
  else
  {
    v15 = buffer->m_nInBufWord;
    v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v13;
    v7 = v16 | v12;
    buffer->m_nInBufWord = v15 >> v13;
  }
  v6 = 0;
LABEL_20:
  this->m_nNewCommands = v7;
  v17 = buffer->m_nBitsAvail;
  if ( v17 < 3 )
  {
    v25 = buffer->m_pBufferEnd;
    v26 = buffer->m_nInBufWord;
    v27 = 3 - v17;
    v28 = buffer->m_pDataIn;
    if ( v28 == v25 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v28 > v25 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_35;
      }
      buffer->m_nInBufWord = *v28;
    }
    buffer->m_pDataIn = v28 + 1;
LABEL_35:
    if ( buffer->m_bOverflow )
    {
      v21 = 0;
    }
    else
    {
      v29 = buffer->m_nInBufWord;
      v30 = (v29 & CBitBuffer::s_nMaskTable[v27]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v27;
      v21 = v30 | v26;
      v6 = 0;
      buffer->m_nInBufWord = v29 >> v27;
    }
    goto LABEL_38;
  }
  v18 = buffer->m_nInBufWord;
  v19 = v18 & 7;
  v20 = v17 - 3;
  buffer->m_nBitsAvail = v20;
  if ( v20 != 0 )
  {
    buffer->m_nInBufWord = v18 >> 3;
    v21 = v18 & 7;
  }
  else
  {
    v22 = buffer->m_pDataIn;
    v23 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v22 == v23 )
    {
      buffer->m_pDataIn = v22 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v21 = v19;
    }
    else
    {
      if ( v22 <= v23 )
      {
        v24 = *v22;
        buffer->m_pDataIn = v22 + 1;
        buffer->m_nInBufWord = v24;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v21 = v19;
    }
  }
LABEL_38:
  this->m_nBackupCommands = v21;
  v31 = buffer->m_nBitsAvail;
  if ( v31 >= 16 )
  {
    v32 = buffer->m_nInBufWord;
    v33 = (unsigned __int16)v32;
    v34 = v31 - 16;
    buffer->m_nBitsAvail = v34;
    if ( v34 != 0 )
    {
      buffer->m_nInBufWord = HIWORD(v32);
      v6 = (unsigned __int16)v32;
    }
    else
    {
      v35 = buffer->m_pDataIn;
      v36 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v35 == v36 )
      {
        buffer->m_nInBufWord = 0;
        buffer->m_nBitsAvail = 1;
        buffer->m_pDataIn = v35 + 1;
        v6 = v33;
      }
      else
      {
        if ( v35 <= v36 )
        {
          v37 = *v35;
          buffer->m_pDataIn = v35 + 1;
          buffer->m_nInBufWord = v37;
        }
        else
        {
          buffer->m_nInBufWord = 0;
          buffer->m_bOverflow = true;
        }
        v6 = v33;
      }
    }
    goto LABEL_55;
  }
  v38 = buffer->m_pBufferEnd;
  v39 = buffer->m_nInBufWord;
  v40 = 16 - v31;
  v41 = buffer->m_pDataIn;
  if ( v41 == v38 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v41 > v38 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_53;
    }
    buffer->m_nInBufWord = *v41;
  }
  buffer->m_pDataIn = v41 + 1;
LABEL_53:
  if ( !buffer->m_bOverflow )
  {
    v42 = buffer->m_nInBufWord;
    v43 = (v42 & CBitBuffer::s_nMaskTable[v40]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v40;
    v6 = v39 | v43;
    buffer->m_nInBufWord = v42 >> v40;
  }
LABEL_55:
  this->m_nLength = v6;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v6);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v6 + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101BDE20
// Name: public: virtual bool CLC_ClientInfo::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLC_ClientInfo::WriteToBuffer(CLC_ClientInfo *this, bf_write *buffer)
{
  unsigned int v3; // eax
  int m_iCurBit; // ecx
  BOOL m_bIsHLTV; // eax
  unsigned int *m_nCustomFiles; // edi
  int v8; // ecx
  int v9; // edx
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // eax
  int buffera; // [esp+14h] [ebp+8h]

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteLong(this: buffer, val: this->m_nServerCount);
  bf_write::WriteLong(this: buffer, val: this->m_nSendTableCRC);
  m_iCurBit = buffer->m_iCurBit;
  m_bIsHLTV = this->m_bIsHLTV;
  if ( m_iCurBit + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bIsHLTV )
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
    else
      buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++buffer->m_iCurBit;
  }
  bf_write::WriteLong(this: buffer, val: this->m_nFriendsID);
  bf_write::WriteString(this: buffer, pStr: this->m_FriendsName);
  m_nCustomFiles = this->m_nCustomFiles;
  for ( buffera = 4; buffera != 0; --buffera )
  {
    v8 = buffer->m_iCurBit;
    v9 = v8 + 1;
    if ( *m_nCustomFiles != 0 )
    {
      if ( v9 <= buffer->m_nDataBits )
      {
        if ( !buffer->m_bOverflow )
        {
          v10 = &buffer->m_pData[buffer->m_iCurBit >> 3];
          *v10 |= 1 << (v8 & 7);
          ++buffer->m_iCurBit;
        }
        bf_write::WriteUBitLong(this: buffer, curData: *m_nCustomFiles, numbits: 32, bCheckRange: true);
      }
      else
      {
        buffer->m_bOverflow = true;
        bf_write::WriteUBitLong(this: buffer, curData: *m_nCustomFiles, numbits: 32, bCheckRange: true);
      }
    }
    else if ( v9 <= buffer->m_nDataBits )
    {
      if ( !buffer->m_bOverflow )
      {
        v11 = &buffer->m_pData[buffer->m_iCurBit >> 3];
        *v11 &= ~(1 << (v8 & 7));
        ++buffer->m_iCurBit;
      }
    }
    else
    {
      buffer->m_bOverflow = true;
    }
    ++m_nCustomFiles;
  }
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BDF50
// Name: public: virtual bool CLC_FileCRCCheck::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLC_FileCRCCheck::WriteToBuffer(CLC_FileCRCCheck *this, bf_write *buffer)
{
  unsigned int v3; // eax
  int m_iCurBit; // ecx
  int v5; // edi
  char *m_szPathID; // ebx
  int CommonPrefix; // eax
  int v8; // edi
  const char *v10; // [esp-4h] [ebp-14h]

  v3 = ((int (__fastcall *)(CLC_FileCRCCheck *))this->GetType)(a1: this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_iCurBit = buffer->m_iCurBit;
  if ( m_iCurBit + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++buffer->m_iCurBit;
  }
  v5 = 0;
  m_szPathID = this->m_szPathID;
  while ( _V_stricmp(s1: m_szPathID, s2: g_MostCommonPathIDs[v5]) != 0 )
  {
    if ( (unsigned int)++v5 >= 2 )
    {
      bf_write::WriteUBitLong(this: buffer, curData: 0, numbits: 2, bCheckRange: true);
      bf_write::WriteString(this: buffer, pStr: m_szPathID);
      goto LABEL_10;
    }
  }
  bf_write::WriteUBitLong(this: buffer, curData: v5 + 1, numbits: 2, bCheckRange: true);
LABEL_10:
  CommonPrefix = FindCommonPrefix(pStr: this->m_szFilename);
  v8 = CommonPrefix;
  if ( CommonPrefix == -1 )
  {
    bf_write::WriteUBitLong(this: buffer, curData: 0, numbits: 3, bCheckRange: true);
    bf_write::WriteString(this: buffer, pStr: this->m_szFilename);
  }
  else
  {
    bf_write::WriteUBitLong(this: buffer, curData: CommonPrefix + 1, numbits: 3, bCheckRange: true);
    v10 = &this->m_szFilename[_V_strlen(str: g_MostCommonPrefixes[v8]) + 1];
    bf_write::WriteString(this: buffer, pStr: v10);
  }
  bf_write::WriteUBitLong(this: buffer, curData: this->m_CRC, numbits: 32, bCheckRange: true);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BE070
// Name: public: virtual char const __near * CLC_SplitPlayerConnect::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLC_SplitPlayerConnect::ToString(CLC_SplitPlayerConnect *this)
{
  const char *v1; // eax
  int v3; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(CLC_SplitPlayerConnect *, int))this->GetName)(
                       a1: this,
                       a2: this->m_UserInfo.m_Size);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: %i userinfo vars", v1, v3);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BE0A0
// Name: public: CLC_CmdKeyValues::CLC_CmdKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CLC_CmdKeyValues *__thiscall CLC_CmdKeyValues::CLC_CmdKeyValues(CLC_CmdKeyValues *this, KeyValues *pKeyValues)
{
  this->m_bReliable = true;
  this->m_NetChannel = nullptr;
  this->m_pKeyValues = pKeyValues;
  this->__vftable = (CLC_CmdKeyValues_vtbl *)&CLC_CmdKeyValues::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101BE0C0
// Name: public: virtual char const __near * CLC_CmdKeyValues::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLC_CmdKeyValues::GetName(CLC_CmdKeyValues *this)
{
  return "clc_CmdKeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x101BE0D0
// Name: public: virtual bool CLC_CmdKeyValues::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_CmdKeyValues::Process(CLC_CmdKeyValues *this)
{
  return this->m_pMessageHandler->ProcessCmdKeyValues(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x101BE0E0
// Name: public: SVC_CmdKeyValues::SVC_CmdKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
SVC_CmdKeyValues *__thiscall SVC_CmdKeyValues::SVC_CmdKeyValues(SVC_CmdKeyValues *this, KeyValues *pKeyValues)
{
  this->m_bReliable = true;
  this->m_NetChannel = nullptr;
  this->m_pKeyValues = pKeyValues;
  this->__vftable = (SVC_CmdKeyValues_vtbl *)&SVC_CmdKeyValues::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101BE100
// Name: public: virtual char const __near * SVC_CmdKeyValues::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_CmdKeyValues::GetName(SVC_CmdKeyValues *this)
{
  return "svc_CmdKeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x101BE110
// Name: public: virtual bool SVC_CmdKeyValues::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_CmdKeyValues::Process(SVC_CmdKeyValues *this)
{
  return this->m_pMessageHandler->ProcessCmdKeyValues(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x101BE160
// Name: public: virtual bool SVC_ServerInfo::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_ServerInfo::WriteToBuffer(SVC_ServerInfo *this, bf_write *buffer)
{
  unsigned int v3; // eax
  int m_iCurBit; // ecx
  BOOL m_bIsHLTV; // eax
  int v6; // ecx
  BOOL m_bIsDedicated; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteShort(this: buffer, val: this->m_nProtocol);
  bf_write::WriteLong(this: buffer, val: this->m_nServerCount);
  m_iCurBit = buffer->m_iCurBit;
  m_bIsHLTV = this->m_bIsHLTV;
  if ( m_iCurBit + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bIsHLTV )
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
    else
      buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++buffer->m_iCurBit;
  }
  v6 = buffer->m_iCurBit;
  m_bIsDedicated = this->m_bIsDedicated;
  if ( v6 + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bIsDedicated )
      buffer->m_pData[v6 >> 3] |= 1 << (v6 & 7);
    else
      buffer->m_pData[v6 >> 3] &= ~(1 << (v6 & 7));
    ++buffer->m_iCurBit;
  }
  bf_write::WriteLong(this: buffer, val: this->m_nClientCRC);
  bf_write::WriteLong(this: buffer, val: this->m_nStringTableCRC);
  bf_write::WriteWord(this: buffer, val: this->m_nMaxClasses);
  bf_write::WriteLong(this: buffer, val: this->m_nMapCRC);
  bf_write::WriteByte(this: buffer, val: this->m_nPlayerSlot);
  bf_write::WriteByte(this: buffer, val: this->m_nMaxClients);
  bf_write::WriteFloat(this: buffer, val: this->m_fTickInterval);
  bf_write::WriteChar(this: buffer, val: this->m_cOS);
  bf_write::WriteString(this: buffer, pStr: this->m_szGameDir);
  bf_write::WriteString(this: buffer, pStr: this->m_szMapName);
  bf_write::WriteString(this: buffer, pStr: this->m_szSkyName);
  bf_write::WriteString(this: buffer, pStr: this->m_szHostName);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BE2C0
// Name: public: virtual bool SVC_BSPDecal::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_BSPDecal::WriteToBuffer(SVC_BSPDecal *this, bf_write *buffer)
{
  unsigned int v3; // eax
  int m_iCurBit; // ecx
  int v5; // edx
  int v6; // ecx
  BOOL m_bLowPriority; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteBitVec3Coord(this: buffer, fa: &this->m_Pos);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nDecalTextureIndex, numbits: 9, bCheckRange: true);
  m_iCurBit = buffer->m_iCurBit;
  v5 = m_iCurBit + 1;
  if ( this->m_nEntityIndex != 0 )
  {
    if ( v5 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++buffer->m_iCurBit;
    }
    bf_write::WriteUBitLong(this: buffer, curData: this->m_nEntityIndex, numbits: 11, bCheckRange: true);
    bf_write::WriteUBitLong(this: buffer, curData: this->m_nModelIndex, numbits: 11, bCheckRange: true);
  }
  else
  {
    if ( v5 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++buffer->m_iCurBit;
    }
  }
  v6 = buffer->m_iCurBit;
  m_bLowPriority = this->m_bLowPriority;
  if ( v6 + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bLowPriority )
    {
      buffer->m_pData[v6 >> 3] |= 1 << (v6 & 7);
      ++buffer->m_iCurBit;
      return !buffer->m_bOverflow;
    }
    buffer->m_pData[v6 >> 3] &= ~(1 << (v6 & 7));
    ++buffer->m_iCurBit;
  }
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BE3D0
// Name: public: virtual bool SVC_FixAngle::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_FixAngle::WriteToBuffer(SVC_FixAngle *this, bf_write *buffer)
{
  unsigned int v3; // eax
  int m_iCurBit; // ecx
  BOOL m_bRelative; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_iCurBit = buffer->m_iCurBit;
  m_bRelative = this->m_bRelative;
  if ( m_iCurBit + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bRelative )
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
    else
      buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++buffer->m_iCurBit;
  }
  bf_write::WriteBitAngle(this: buffer, fAngle: this->m_Angle.x, numbits: 16);
  bf_write::WriteBitAngle(this: buffer, fAngle: this->m_Angle.y, numbits: 16);
  bf_write::WriteBitAngle(this: buffer, fAngle: this->m_Angle.z, numbits: 16);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BE470
// Name: public: virtual bool SVC_VoiceData::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_VoiceData::ReadFromBuffer(SVC_VoiceData *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v5; // esi
  int v6; // ecx
  int v7; // ebx
  int v8; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v11; // edx
  const unsigned int *v12; // esi
  unsigned int v13; // edi
  int v14; // edx
  const unsigned int *v15; // ecx
  unsigned int v16; // esi
  unsigned int v17; // ebx
  int v18; // ecx
  unsigned int v19; // edx
  int v20; // esi
  int v21; // ecx
  int v22; // ecx
  const unsigned int *v23; // ecx
  const unsigned int *v24; // edx
  unsigned int v25; // edx
  const unsigned int *v26; // esi
  unsigned int v27; // edi
  int v28; // edx
  const unsigned int *v29; // ecx
  unsigned int v30; // esi
  unsigned int v31; // ebx
  int v32; // ecx
  unsigned int v33; // edx
  int v34; // esi
  int v35; // ecx
  int v36; // ecx
  const unsigned int *v37; // ecx
  const unsigned int *v38; // edx
  unsigned int v39; // edx
  const unsigned int *v40; // esi
  unsigned int v41; // edi
  int v42; // edx
  const unsigned int *v43; // ecx
  unsigned int v44; // esi
  unsigned int v45; // ebx
  int v46; // ecx
  unsigned int v47; // edx
  int v48; // esi
  int v49; // ecx
  int v50; // ecx
  const unsigned int *v51; // ecx
  const unsigned int *v52; // edx
  unsigned int v53; // edx
  const unsigned int *v54; // esi
  unsigned int v55; // edi
  int v56; // edx
  const unsigned int *v57; // ecx
  unsigned int v58; // esi
  unsigned int v59; // ebx
  int v60; // edi
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx
  int i; // [esp+18h] [ebp+8h]

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 8 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v5 = (unsigned __int8)m_nInBufWord;
    v6 = m_nBitsAvail - 8;
    v7 = 0;
    buffer->m_nBitsAvail = v6;
    if ( v6 != 0 )
    {
      buffer->m_nInBufWord = m_nInBufWord >> 8;
      v8 = (unsigned __int8)m_nInBufWord;
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_pDataIn = m_pDataIn + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        v8 = v5;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v11 = *m_pDataIn;
          buffer->m_pDataIn = m_pDataIn + 1;
          buffer->m_nInBufWord = v11;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v8 = v5;
      }
    }
    goto LABEL_20;
  }
  v12 = buffer->m_pBufferEnd;
  v13 = buffer->m_nInBufWord;
  v14 = 8 - m_nBitsAvail;
  v15 = buffer->m_pDataIn;
  if ( v15 == v12 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_15:
    buffer->m_pDataIn = v15 + 1;
    goto LABEL_16;
  }
  if ( v15 <= v12 )
  {
    buffer->m_nInBufWord = *v15;
    goto LABEL_15;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_16:
  if ( buffer->m_bOverflow )
  {
    v8 = 0;
  }
  else
  {
    v16 = buffer->m_nInBufWord;
    v17 = (v16 & CBitBuffer::s_nMaskTable[v14]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v14;
    v8 = v17 | v13;
    buffer->m_nInBufWord = v16 >> v14;
  }
  v7 = 0;
LABEL_20:
  this->m_nFromClient = v8;
  v18 = buffer->m_nBitsAvail;
  if ( v18 < 8 )
  {
    v26 = buffer->m_pBufferEnd;
    v27 = buffer->m_nInBufWord;
    v28 = 8 - v18;
    v29 = buffer->m_pDataIn;
    if ( v29 == v26 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v29 > v26 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_35;
      }
      buffer->m_nInBufWord = *v29;
    }
    buffer->m_pDataIn = v29 + 1;
LABEL_35:
    if ( buffer->m_bOverflow )
    {
      v22 = 0;
    }
    else
    {
      v30 = buffer->m_nInBufWord;
      v31 = (v30 & CBitBuffer::s_nMaskTable[v28]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v28;
      v22 = v31 | v27;
      v7 = 0;
      buffer->m_nInBufWord = v30 >> v28;
    }
    goto LABEL_38;
  }
  v19 = buffer->m_nInBufWord;
  v20 = (unsigned __int8)v19;
  v21 = v18 - 8;
  buffer->m_nBitsAvail = v21;
  if ( v21 != 0 )
  {
    buffer->m_nInBufWord = v19 >> 8;
    v22 = (unsigned __int8)v19;
  }
  else
  {
    v23 = buffer->m_pDataIn;
    v24 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v23 == v24 )
    {
      buffer->m_pDataIn = v23 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v22 = v20;
    }
    else
    {
      if ( v23 <= v24 )
      {
        v25 = *v23;
        buffer->m_pDataIn = v23 + 1;
        buffer->m_nInBufWord = v25;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v22 = v20;
    }
  }
LABEL_38:
  this->m_bProximity = v22 != 0;
  v32 = buffer->m_nBitsAvail;
  if ( v32 >= 16 )
  {
    v33 = buffer->m_nInBufWord;
    v34 = (unsigned __int16)v33;
    v35 = v32 - 16;
    buffer->m_nBitsAvail = v35;
    if ( v35 != 0 )
    {
      buffer->m_nInBufWord = HIWORD(v33);
      v36 = (unsigned __int16)v33;
    }
    else
    {
      v37 = buffer->m_pDataIn;
      v38 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v37 == v38 )
      {
        buffer->m_pDataIn = v37 + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        v36 = v34;
      }
      else
      {
        if ( v37 <= v38 )
        {
          v39 = *v37;
          buffer->m_pDataIn = v37 + 1;
          buffer->m_nInBufWord = v39;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v36 = v34;
      }
    }
    goto LABEL_56;
  }
  v40 = buffer->m_pBufferEnd;
  v41 = buffer->m_nInBufWord;
  v42 = 16 - v32;
  v43 = buffer->m_pDataIn;
  if ( v43 == v40 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v43 > v40 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_53;
    }
    buffer->m_nInBufWord = *v43;
  }
  buffer->m_pDataIn = v43 + 1;
LABEL_53:
  if ( buffer->m_bOverflow )
  {
    v36 = 0;
  }
  else
  {
    v44 = buffer->m_nInBufWord;
    v45 = (v44 & CBitBuffer::s_nMaskTable[v42]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v42;
    v36 = v45 | v41;
    v7 = 0;
    buffer->m_nInBufWord = v44 >> v42;
  }
LABEL_56:
  this->m_nLength = v36;
  i = 0;
  do
  {
    v46 = buffer->m_nBitsAvail;
    if ( v46 < 1 )
    {
      v54 = buffer->m_pBufferEnd;
      v55 = buffer->m_nInBufWord;
      v56 = 1 - v46;
      v57 = buffer->m_pDataIn;
      if ( v57 == v54 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_bOverflow = true;
      }
      else
      {
        if ( v57 > v54 )
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
          goto LABEL_72;
        }
        buffer->m_nInBufWord = *v57;
      }
      buffer->m_pDataIn = v57 + 1;
LABEL_72:
      if ( buffer->m_bOverflow )
      {
        v50 = 0;
      }
      else
      {
        v58 = buffer->m_nInBufWord;
        v59 = (v58 & CBitBuffer::s_nMaskTable[v56]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v56;
        v60 = v59 | v55;
        v7 = i;
        v50 = v60;
        buffer->m_nInBufWord = v58 >> v56;
      }
      goto LABEL_75;
    }
    v47 = buffer->m_nInBufWord;
    v48 = v47 & 1;
    v49 = v46 - 1;
    buffer->m_nBitsAvail = v49;
    if ( v49 != 0 )
    {
      buffer->m_nInBufWord = v47 >> 1;
      v50 = v47 & 1;
    }
    else
    {
      v51 = buffer->m_pDataIn;
      v52 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v51 == v52 )
      {
        buffer->m_pDataIn = v51 + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        v50 = v48;
      }
      else
      {
        if ( v51 <= v52 )
        {
          v53 = *v51;
          buffer->m_pDataIn = v51 + 1;
          buffer->m_nInBufWord = v53;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v50 = v48;
      }
    }
LABEL_75:
    this->m_bAudible[v7++] = v50 != 0;
    i = v7;
  }
  while ( v7 < 2 );
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: this->m_nLength);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: this->m_nLength + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101BE8A0
// Name: public: virtual bool NET_Tick::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall NET_Tick::WriteToBuffer(NET_Tick *this, bf_write *buffer)
{
  unsigned int v3; // eax
  signed int v4; // eax
  signed int v5; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteLong(this: buffer, val: this->m_nTick);
  v4 = (int)(float)(this->m_flHostFrameTime * 100000.0);
  if ( v4 >= 0 )
  {
    if ( v4 > 0xFFFF )
      v4 = 0xFFFF;
  }
  else
  {
    v4 = 0;
  }
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 16, bCheckRange: true);
  v5 = (int)(float)(this->m_flHostFrameTimeStdDeviation * 100000.0);
  if ( v5 >= 0 )
  {
    if ( v5 > 0xFFFF )
      v5 = 0xFFFF;
  }
  else
  {
    v5 = 0;
  }
  bf_write::WriteUBitLong(this: buffer, curData: v5, numbits: 16, bCheckRange: true);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BE940
// Name: public: NET_SplitScreenUser::NET_SplitScreenUser(void)
// Source: json
//------------------------------------------------------------------------------
NET_SplitScreenUser *__thiscall NET_SplitScreenUser::NET_SplitScreenUser(NET_SplitScreenUser *this)
{
  this->m_bReliable = true;
  this->m_NetChannel = nullptr;
  this->__vftable = (NET_SplitScreenUser_vtbl *)&NET_SplitScreenUser::`vftable';
  this->m_nSlot = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101BE960
// Name: public: virtual char const __near * NET_SplitScreenUser::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall NET_SplitScreenUser::GetName(NET_SplitScreenUser *this)
{
  return "net_SplitScreenUser";
}

//------------------------------------------------------------------------------
// Address: 0x101BE970
// Name: public: virtual bool NET_SplitScreenUser::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NET_SplitScreenUser::Process(NET_SplitScreenUser *this)
{
  return this->m_pMessageHandler->ProcessSplitScreenUser(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x101BE980
// Name: public: NET_SplitScreenUser::NET_SplitScreenUser(int)
// Source: json
//------------------------------------------------------------------------------
NET_SplitScreenUser *__thiscall NET_SplitScreenUser::NET_SplitScreenUser(NET_SplitScreenUser *this, int slot)
{
  this->m_bReliable = true;
  this->m_NetChannel = nullptr;
  this->__vftable = (NET_SplitScreenUser_vtbl *)&NET_SplitScreenUser::`vftable';
  this->m_nSlot = slot;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101BE9A0
// Name: public: virtual bool SVC_UserMessage::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_UserMessage::ReadFromBuffer(SVC_UserMessage *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // ecx
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  unsigned int v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx
  int v16; // ecx
  unsigned int v17; // edx
  int v18; // esi
  int v19; // ecx
  int v20; // ebx
  const unsigned int *v21; // ecx
  const unsigned int *v22; // edx
  unsigned int v23; // edx
  const unsigned int *v24; // esi
  unsigned int v25; // edi
  int v26; // edx
  const unsigned int *v27; // ecx
  unsigned int v28; // esi
  unsigned int v29; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v12 = 8 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_16;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( buffer->m_bOverflow )
    {
      v6 = 0;
    }
    else
    {
      v14 = buffer->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v12;
      v6 = v15 | m_nInBufWord;
      buffer->m_nInBufWord = v14 >> v12;
    }
    goto LABEL_19;
  }
  v3 = buffer->m_nInBufWord;
  v4 = (unsigned __int8)v3;
  v5 = m_nBitsAvail - 8;
  buffer->m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    buffer->m_nInBufWord = v3 >> 8;
    v6 = (unsigned __int8)v3;
  }
  else
  {
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      buffer->m_pDataIn = v7 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v6 = v4;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v9 = *v7;
        buffer->m_pDataIn = v7 + 1;
        buffer->m_nInBufWord = v9;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v6 = v4;
    }
  }
LABEL_19:
  this->m_nMsgType = v6;
  v16 = buffer->m_nBitsAvail;
  if ( v16 >= 12 )
  {
    v17 = buffer->m_nInBufWord;
    v18 = v17 & 0xFFF;
    v19 = v16 - 12;
    buffer->m_nBitsAvail = v19;
    if ( v19 != 0 )
    {
      buffer->m_nInBufWord = v17 >> 12;
      v20 = v17 & 0xFFF;
    }
    else
    {
      v21 = buffer->m_pDataIn;
      v22 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v21 == v22 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v21 + 1;
        v20 = v18;
      }
      else
      {
        if ( v21 <= v22 )
        {
          v23 = *v21;
          buffer->m_pDataIn = v21 + 1;
          buffer->m_nInBufWord = v23;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v20 = v18;
      }
    }
    goto LABEL_37;
  }
  v24 = buffer->m_pBufferEnd;
  v25 = buffer->m_nInBufWord;
  v26 = 12 - v16;
  v27 = buffer->m_pDataIn;
  if ( v27 == v24 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v27 > v24 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_34;
    }
    buffer->m_nInBufWord = *v27;
  }
  buffer->m_pDataIn = v27 + 1;
LABEL_34:
  if ( buffer->m_bOverflow )
  {
    v20 = 0;
  }
  else
  {
    v28 = buffer->m_nInBufWord;
    v29 = (v28 & CBitBuffer::s_nMaskTable[v26]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v26;
    v20 = v25 | v29;
    buffer->m_nInBufWord = v28 >> v26;
  }
LABEL_37:
  this->m_nLength = v20;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v20);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v20 + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101BEBD0
// Name: public: virtual bool SVC_SetPause::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_SetPause::WriteToBuffer(SVC_SetPause *this, bf_write *buffer)
{
  unsigned int v3; // eax
  int m_iCurBit; // ecx
  BOOL m_bPaused; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_iCurBit = buffer->m_iCurBit;
  m_bPaused = this->m_bPaused;
  if ( m_iCurBit + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bPaused )
    {
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++buffer->m_iCurBit;
      return !buffer->m_bOverflow;
    }
    buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++buffer->m_iCurBit;
  }
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BEC50
// Name: public: virtual bool SVC_UpdateStringTable::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_UpdateStringTable::WriteToBuffer(SVC_UpdateStringTable *this, bf_write *buffer)
{
  unsigned int v3; // eax
  int v4; // eax
  int m_iCurBit; // ecx

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  this->m_nLength = this->m_DataOut.m_iCurBit;
  v4 = Q_log2(val: 0x20u);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nTableID, numbits: v4, bCheckRange: true);
  m_iCurBit = buffer->m_iCurBit;
  if ( this->m_nChangedEntries == 1 )
  {
    if ( m_iCurBit + 1 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++buffer->m_iCurBit;
    }
  }
  else
  {
    if ( m_iCurBit + 1 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++buffer->m_iCurBit;
    }
    bf_write::WriteWord(this: buffer, val: this->m_nChangedEntries);
  }
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 20, bCheckRange: true);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BED20
// Name: public: virtual bool SVC_UpdateStringTable::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_UpdateStringTable::ReadFromBuffer(SVC_UpdateStringTable *this, bf_read *buffer)
{
  signed int v2; // eax
  int m_nBitsAvail; // ecx
  unsigned int v4; // esi
  unsigned int v5; // edi
  int v6; // ecx
  const unsigned int *v7; // eax
  const unsigned int *v8; // ecx
  int v9; // ebx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  const unsigned int *m_pDataIn; // ecx
  unsigned int v13; // eax
  int v14; // ecx
  const unsigned int *v16; // eax
  const unsigned int *v17; // esi
  int v18; // ecx
  unsigned int v19; // eax
  int v20; // edi
  int v21; // ecx
  const unsigned int *v22; // eax
  const unsigned int *v23; // ecx
  SVC_UpdateStringTable *v24; // eax
  unsigned int v25; // ecx
  const unsigned int *v26; // esi
  unsigned int v27; // edi
  int v28; // eax
  const unsigned int *v29; // ecx
  unsigned int v30; // esi
  unsigned int v31; // ebx
  int v32; // edi
  int v33; // ecx
  unsigned int v34; // eax
  int v35; // esi
  int v36; // ecx
  const unsigned int *v37; // eax
  const unsigned int *v38; // ecx
  const unsigned int *v39; // esi
  unsigned int v40; // edi
  int v41; // eax
  const unsigned int *v42; // ecx
  unsigned int v43; // esi
  unsigned int v44; // ebx
  const unsigned int *m_pData; // eax
  int m_nDataBits; // eax

  v2 = Q_log2(val: 0x20u);
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < v2 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v2 -= m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_14:
        if ( buffer->m_bOverflow )
        {
          v5 = 0;
          goto LABEL_18;
        }
        v4 = buffer->m_nInBufWord;
        v5 = ((v4 & CBitBuffer::s_nMaskTable[v2]) << buffer->m_nBitsAvail) | m_nInBufWord;
        buffer->m_nBitsAvail = 32 - v2;
LABEL_17:
        buffer->m_nInBufWord = v4 >> v2;
        goto LABEL_18;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
    goto LABEL_14;
  }
  v4 = buffer->m_nInBufWord;
  v5 = v4 & CBitBuffer::s_nMaskTable[v2];
  v6 = m_nBitsAvail - v2;
  buffer->m_nBitsAvail = v6;
  if ( v6 != 0 )
    goto LABEL_17;
  v7 = buffer->m_pDataIn;
  v8 = buffer->m_pBufferEnd;
  buffer->m_nBitsAvail = 32;
  if ( v7 == v8 )
  {
    v9 = 0;
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_pDataIn = v7 + 1;
    goto LABEL_19;
  }
  if ( v7 <= v8 )
  {
    buffer->m_nInBufWord = *v7;
    buffer->m_pDataIn = v7 + 1;
  }
  else
  {
    buffer->m_bOverflow = true;
    buffer->m_nInBufWord = 0;
  }
LABEL_18:
  v9 = 0;
LABEL_19:
  this->m_nTableID = v5;
  v13 = buffer->m_nInBufWord;
  v14 = v13 & 1;
  if ( buffer->m_nBitsAvail-- == 1 )
  {
    v16 = buffer->m_pDataIn;
    v17 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v16 == v17 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v16 + 1;
    }
    else if ( v16 <= v17 )
    {
      buffer->m_nInBufWord = *v16;
      buffer->m_pDataIn = v16 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v13 >> 1;
  }
  if ( v14 == 0 )
  {
    this->m_nChangedEntries = 1;
    goto LABEL_46;
  }
  v18 = buffer->m_nBitsAvail;
  if ( v18 < 16 )
  {
    v26 = buffer->m_pBufferEnd;
    v27 = buffer->m_nInBufWord;
    v28 = 16 - v18;
    v29 = buffer->m_pDataIn;
    if ( v29 == v26 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v29 > v26 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_42;
      }
      buffer->m_nInBufWord = *v29;
    }
    buffer->m_pDataIn = v29 + 1;
LABEL_42:
    if ( buffer->m_bOverflow )
    {
      this->m_nChangedEntries = 0;
    }
    else
    {
      v30 = buffer->m_nInBufWord;
      v31 = (v30 & CBitBuffer::s_nMaskTable[v28]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v28;
      v32 = v31 | v27;
      v9 = 0;
      buffer->m_nInBufWord = v30 >> v28;
      this->m_nChangedEntries = v32;
    }
    goto LABEL_46;
  }
  v19 = buffer->m_nInBufWord;
  v20 = (unsigned __int16)v19;
  v21 = v18 - 16;
  buffer->m_nBitsAvail = v21;
  if ( v21 != 0 )
  {
    buffer->m_nInBufWord = HIWORD(v19);
    this->m_nChangedEntries = (unsigned __int16)v19;
  }
  else
  {
    v22 = buffer->m_pDataIn;
    v23 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v22 == v23 )
    {
      buffer->m_pDataIn = v22 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      this->m_nChangedEntries = v20;
    }
    else
    {
      if ( v22 <= v23 )
      {
        v25 = *v22;
        buffer->m_pDataIn = v22 + 1;
        v24 = this;
        buffer->m_nInBufWord = v25;
      }
      else
      {
        v24 = this;
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v24->m_nChangedEntries = v20;
    }
  }
LABEL_46:
  v33 = buffer->m_nBitsAvail;
  if ( v33 >= 20 )
  {
    v34 = buffer->m_nInBufWord;
    v35 = v34 & 0xFFFFF;
    v36 = v33 - 20;
    buffer->m_nBitsAvail = v36;
    if ( v36 != 0 )
    {
      buffer->m_nInBufWord = v34 >> 20;
      v9 = v34 & 0xFFFFF;
    }
    else
    {
      v37 = buffer->m_pDataIn;
      v38 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v37 == v38 )
      {
        buffer->m_nInBufWord = 0;
        buffer->m_nBitsAvail = 1;
        buffer->m_pDataIn = v37 + 1;
        v9 = v35;
      }
      else
      {
        if ( v37 <= v38 )
        {
          buffer->m_nInBufWord = *v37;
          buffer->m_pDataIn = v37 + 1;
        }
        else
        {
          buffer->m_nInBufWord = 0;
          buffer->m_bOverflow = true;
        }
        v9 = v35;
      }
    }
    goto LABEL_63;
  }
  v39 = buffer->m_pBufferEnd;
  v40 = buffer->m_nInBufWord;
  v41 = 20 - v33;
  v42 = buffer->m_pDataIn;
  if ( v42 == v39 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v42 > v39 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_61;
    }
    buffer->m_nInBufWord = *v42;
  }
  buffer->m_pDataIn = v42 + 1;
LABEL_61:
  if ( !buffer->m_bOverflow )
  {
    v43 = buffer->m_nInBufWord;
    v44 = (v43 & CBitBuffer::s_nMaskTable[v41]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v41;
    v9 = v40 | v44;
    buffer->m_nInBufWord = v43 >> v41;
  }
LABEL_63:
  this->m_nLength = v9;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v9);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v9 + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101BF0A0
// Name: public: SVC_CreateStringTable::SVC_CreateStringTable(void)
// Source: json
//------------------------------------------------------------------------------
SVC_CreateStringTable *__thiscall SVC_CreateStringTable::SVC_CreateStringTable(SVC_CreateStringTable *this)
{
  this->m_bReliable = true;
  this->m_NetChannel = nullptr;
  this->__vftable = (SVC_CreateStringTable_vtbl *)&SVC_CreateStringTable::`vftable';
  this->m_DataIn.m_bOverflow = false;
  this->m_DataIn.m_pDebugName = nullptr;
  this->m_DataIn.m_nDataBits = -1;
  this->m_DataIn.m_nDataBytes = 0;
  bf_write::bf_write(this: &this->m_DataOut);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101BF0D0
// Name: public: virtual char const __near * SVC_CreateStringTable::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_CreateStringTable::GetName(SVC_CreateStringTable *this)
{
  return "svc_CreateStringTable";
}

//------------------------------------------------------------------------------
// Address: 0x101BF0E0
// Name: public: virtual unsigned int SVC_CreateStringTable::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SVC_CreateStringTable::GetSize(SVC_CreateStringTable *this)
{
  return 368;
}

//------------------------------------------------------------------------------
// Address: 0x101BF0F0
// Name: public: virtual bool SVC_CreateStringTable::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_CreateStringTable::Process(CLC_RespondCvarValue *this)
{
  return this->m_pMessageHandler->ProcessRespondCvarValue(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x101BF100
// Name: public: virtual bool SVC_CreateStringTable::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_CreateStringTable::WriteToBuffer(SVC_CreateStringTable *this, bf_write *buffer)
{
  unsigned int v3; // eax
  unsigned int v4; // eax
  int m_iCurBit; // ecx
  BOOL m_bUserDataFixedSize; // eax
  int v7; // ecx
  BOOL m_bDataCompressed; // eax
  const char *m_szTableName; // [esp-4h] [ebp-10h]

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_szTableName = this->m_szTableName;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  bf_write::WriteString(this: buffer, pStr: m_szTableName);
  bf_write::WriteWord(this: buffer, val: this->m_nMaxEntries);
  v4 = Q_log2(val: this->m_nMaxEntries);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nNumEntries, numbits: v4 + 1, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 20, bCheckRange: true);
  m_iCurBit = buffer->m_iCurBit;
  m_bUserDataFixedSize = this->m_bUserDataFixedSize;
  if ( m_iCurBit + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bUserDataFixedSize )
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
    else
      buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++buffer->m_iCurBit;
  }
  if ( this->m_bUserDataFixedSize )
  {
    bf_write::WriteUBitLong(this: buffer, curData: this->m_nUserDataSize, numbits: 12, bCheckRange: true);
    bf_write::WriteUBitLong(this: buffer, curData: this->m_nUserDataSizeBits, numbits: 4, bCheckRange: true);
  }
  v7 = buffer->m_iCurBit;
  m_bDataCompressed = this->m_bDataCompressed;
  if ( v7 + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bDataCompressed )
      buffer->m_pData[v7 >> 3] |= 1 << (v7 & 7);
    else
      buffer->m_pData[v7 >> 3] &= ~(1 << (v7 & 7));
    ++buffer->m_iCurBit;
  }
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nFlags, numbits: 1, bCheckRange: true);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BF240
// Name: public: virtual bool SVC_CreateStringTable::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_CreateStringTable::ReadFromBuffer(SVC_CreateStringTable *this, bf_read *buffer)
{
  SVC_CreateStringTable *v2; // esi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  unsigned int v5; // eax
  int v6; // ecx
  unsigned int v7; // edx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  const unsigned int *v10; // edx
  unsigned int v11; // esi
  int v12; // eax
  const unsigned int *v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // edi
  unsigned int v16; // eax
  int v17; // ecx
  int v18; // eax
  unsigned int v19; // edx
  unsigned int v20; // esi
  int v21; // ecx
  unsigned int v22; // edx
  const unsigned int *v23; // eax
  const unsigned int *v24; // ecx
  const unsigned int *v25; // edx
  unsigned int v26; // esi
  int v27; // eax
  const unsigned int *v28; // ecx
  int v29; // eax
  unsigned int v30; // edx
  unsigned int v31; // edi
  int v32; // ecx
  unsigned int v33; // eax
  int v34; // edx
  int v35; // ecx
  int v36; // eax
  const unsigned int *v37; // eax
  const unsigned int *v38; // ecx
  unsigned int v39; // ecx
  const unsigned int *v40; // edx
  unsigned int v41; // esi
  int v42; // eax
  const unsigned int *v43; // ecx
  unsigned int v44; // edx
  unsigned int v45; // edi
  unsigned int v46; // edx
  SVC_CreateStringTable *v47; // esi
  unsigned int v48; // eax
  int v49; // ecx
  bool v50; // zf
  const unsigned int *v51; // eax
  const unsigned int *v52; // edx
  int v53; // ecx
  unsigned int v54; // eax
  int v55; // edx
  int v56; // ecx
  int v57; // eax
  const unsigned int *v58; // eax
  const unsigned int *v59; // ecx
  unsigned int v60; // ecx
  const unsigned int *v61; // edx
  unsigned int v62; // esi
  int v63; // eax
  const unsigned int *v64; // ecx
  unsigned int v65; // edx
  unsigned int v66; // edi
  unsigned int v67; // edx
  int v68; // ecx
  unsigned int v69; // eax
  int v70; // esi
  int v71; // ecx
  const unsigned int *v72; // eax
  const unsigned int *v73; // ecx
  SVC_CreateStringTable *v74; // edx
  const unsigned int *v75; // edx
  unsigned int v76; // esi
  int v77; // eax
  const unsigned int *v78; // ecx
  unsigned int v79; // edx
  unsigned int v80; // edi
  unsigned int v81; // eax
  int v82; // ecx
  const unsigned int *v83; // eax
  const unsigned int *v84; // edx
  int v85; // ecx
  unsigned int v86; // eax
  int v87; // edx
  int v88; // ecx
  int v89; // ecx
  const unsigned int *v90; // eax
  const unsigned int *v91; // ecx
  const unsigned int *v92; // edx
  unsigned int v93; // esi
  int v94; // eax
  const unsigned int *v95; // ecx
  unsigned int v96; // edx
  unsigned int v97; // edi
  int m_nLength; // edx
  const unsigned int *m_pData; // eax

  v2 = this;
  this->m_szTableName = this->m_szTableNameBuffer;
  CBitRead::ReadString(this: buffer, pStr: this->m_szTableNameBuffer, maxLen: 256, bLine: false, pOutNumChars: nullptr);
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 16 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v5 = (unsigned __int16)m_nInBufWord;
    v6 = m_nBitsAvail - 16;
    buffer->m_nBitsAvail = v6;
    if ( v6 != 0 )
    {
      v7 = HIWORD(m_nInBufWord);
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = m_pDataIn + 1;
        goto LABEL_19;
      }
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_19;
      }
      v7 = *m_pDataIn;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    goto LABEL_18;
  }
  v10 = buffer->m_pBufferEnd;
  v11 = buffer->m_nInBufWord;
  v12 = 16 - m_nBitsAvail;
  v13 = buffer->m_pDataIn;
  if ( v13 == v10 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_14:
    buffer->m_pDataIn = v13 + 1;
    goto LABEL_15;
  }
  if ( v13 <= v10 )
  {
    buffer->m_nInBufWord = *v13;
    goto LABEL_14;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_15:
  if ( buffer->m_bOverflow )
  {
    v2 = this;
    v5 = 0;
    goto LABEL_19;
  }
  v14 = buffer->m_nInBufWord;
  v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
  buffer->m_nBitsAvail = 32 - v12;
  v7 = v14 >> v12;
  v5 = v15 | v11;
  v2 = this;
LABEL_18:
  buffer->m_nInBufWord = v7;
LABEL_19:
  v2->m_nMaxEntries = v5;
  v16 = Q_log2(val: v5);
  v17 = buffer->m_nBitsAvail;
  v18 = v16 + 1;
  if ( v17 < v18 )
  {
    v25 = buffer->m_pBufferEnd;
    v26 = buffer->m_nInBufWord;
    v27 = v18 - v17;
    v28 = buffer->m_pDataIn;
    if ( v28 == v25 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v28 > v25 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_33:
        if ( buffer->m_bOverflow )
        {
          v29 = 0;
          goto LABEL_38;
        }
        v30 = buffer->m_nInBufWord;
        v31 = (v30 & CBitBuffer::s_nMaskTable[v27]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v27;
        v20 = v31 | v26;
        v22 = v30 >> v27;
        goto LABEL_36;
      }
      buffer->m_nInBufWord = *v28;
    }
    buffer->m_pDataIn = v28 + 1;
    goto LABEL_33;
  }
  v19 = buffer->m_nInBufWord;
  v20 = v19 & CBitBuffer::s_nMaskTable[v18];
  v21 = v17 - v18;
  buffer->m_nBitsAvail = v21;
  if ( v21 != 0 )
  {
    v22 = v19 >> v18;
LABEL_36:
    buffer->m_nInBufWord = v22;
    goto LABEL_37;
  }
  v23 = buffer->m_pDataIn;
  v24 = buffer->m_pBufferEnd;
  buffer->m_nBitsAvail = 32;
  if ( v23 == v24 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_pDataIn = v23 + 1;
  }
  else
  {
    if ( v23 <= v24 )
    {
      v22 = *v23;
      buffer->m_pDataIn = v23 + 1;
      goto LABEL_36;
    }
    buffer->m_bOverflow = true;
    buffer->m_nInBufWord = 0;
  }
LABEL_37:
  v29 = v20;
LABEL_38:
  this->m_nNumEntries = v29;
  v32 = buffer->m_nBitsAvail;
  if ( v32 < 20 )
  {
    v40 = buffer->m_pBufferEnd;
    v41 = buffer->m_nInBufWord;
    v42 = 20 - v32;
    v43 = buffer->m_pDataIn;
    if ( v43 == v40 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v43 > v40 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_53;
      }
      buffer->m_nInBufWord = *v43;
    }
    buffer->m_pDataIn = v43 + 1;
LABEL_53:
    if ( buffer->m_bOverflow )
    {
      v36 = 0;
    }
    else
    {
      v44 = buffer->m_nInBufWord;
      v45 = (v44 & CBitBuffer::s_nMaskTable[v42]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v42;
      v46 = v44 >> v42;
      v36 = v45 | v41;
      buffer->m_nInBufWord = v46;
    }
    goto LABEL_56;
  }
  v33 = buffer->m_nInBufWord;
  v34 = v33 & 0xFFFFF;
  v35 = v32 - 20;
  buffer->m_nBitsAvail = v35;
  if ( v35 != 0 )
  {
    buffer->m_nInBufWord = v33 >> 20;
    v36 = v33 & 0xFFFFF;
  }
  else
  {
    v37 = buffer->m_pDataIn;
    v38 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v37 == v38 )
    {
      buffer->m_pDataIn = v37 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v36 = v34;
    }
    else
    {
      if ( v37 <= v38 )
      {
        v39 = *v37;
        buffer->m_pDataIn = v37 + 1;
        buffer->m_nInBufWord = v39;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v36 = v34;
    }
  }
LABEL_56:
  v47 = this;
  this->m_nLength = v36;
  v48 = buffer->m_nInBufWord;
  v49 = v48 & 1;
  v50 = buffer->m_nBitsAvail-- == 1;
  if ( v50 )
  {
    v51 = buffer->m_pDataIn;
    v52 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v51 == v52 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v51 + 1;
    }
    else if ( v51 <= v52 )
    {
      buffer->m_nInBufWord = *v51;
      buffer->m_pDataIn = v51 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v48 >> 1;
  }
  this->m_bUserDataFixedSize = v49 != 0;
  if ( v49 == 0 )
  {
    this->m_nUserDataSize = 0;
    this->m_nUserDataSizeBits = 0;
    goto LABEL_102;
  }
  v53 = buffer->m_nBitsAvail;
  if ( v53 >= 12 )
  {
    v54 = buffer->m_nInBufWord;
    v55 = v54 & 0xFFF;
    v56 = v53 - 12;
    buffer->m_nBitsAvail = v56;
    if ( v56 != 0 )
    {
      buffer->m_nInBufWord = v54 >> 12;
      v57 = v54 & 0xFFF;
    }
    else
    {
      v58 = buffer->m_pDataIn;
      v59 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v58 == v59 )
      {
        buffer->m_pDataIn = v58 + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        v57 = v55;
      }
      else
      {
        if ( v58 <= v59 )
        {
          v60 = *v58;
          buffer->m_pDataIn = v58 + 1;
          buffer->m_nInBufWord = v60;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v57 = v55;
      }
    }
    goto LABEL_83;
  }
  v61 = buffer->m_pBufferEnd;
  v62 = buffer->m_nInBufWord;
  v63 = 12 - v53;
  v64 = buffer->m_pDataIn;
  if ( v64 == v61 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_78:
    buffer->m_pDataIn = v64 + 1;
    goto LABEL_79;
  }
  if ( v64 <= v61 )
  {
    buffer->m_nInBufWord = *v64;
    goto LABEL_78;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_79:
  if ( buffer->m_bOverflow )
  {
    v57 = 0;
  }
  else
  {
    v65 = buffer->m_nInBufWord;
    v66 = (v65 & CBitBuffer::s_nMaskTable[v63]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v63;
    v67 = v65 >> v63;
    v57 = v66 | v62;
    buffer->m_nInBufWord = v67;
  }
  v47 = this;
LABEL_83:
  v47->m_nUserDataSize = v57;
  v68 = buffer->m_nBitsAvail;
  if ( v68 < 4 )
  {
    v75 = buffer->m_pBufferEnd;
    v76 = buffer->m_nInBufWord;
    v77 = 4 - v68;
    v78 = buffer->m_pDataIn;
    if ( v78 == v75 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v78 > v75 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_98;
      }
      buffer->m_nInBufWord = *v78;
    }
    buffer->m_pDataIn = v78 + 1;
LABEL_98:
    if ( buffer->m_bOverflow )
    {
      this->m_nUserDataSizeBits = 0;
    }
    else
    {
      v79 = buffer->m_nInBufWord;
      v80 = (v79 & CBitBuffer::s_nMaskTable[v77]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v77;
      buffer->m_nInBufWord = v79 >> v77;
      this->m_nUserDataSizeBits = v80 | v76;
    }
    goto LABEL_102;
  }
  v69 = buffer->m_nInBufWord;
  v70 = v69 & 0xF;
  v71 = v68 - 4;
  buffer->m_nBitsAvail = v71;
  if ( v71 != 0 )
  {
    buffer->m_nInBufWord = v69 >> 4;
    this->m_nUserDataSizeBits = v70;
  }
  else
  {
    v72 = buffer->m_pDataIn;
    v73 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v72 == v73 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v72 + 1;
      this->m_nUserDataSizeBits = v70;
    }
    else
    {
      if ( v72 <= v73 )
      {
        buffer->m_nInBufWord = *v72;
        v74 = this;
        buffer->m_pDataIn = v72 + 1;
      }
      else
      {
        v74 = this;
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v74->m_nUserDataSizeBits = v70;
    }
  }
LABEL_102:
  v81 = buffer->m_nInBufWord;
  v82 = v81 & 1;
  v50 = buffer->m_nBitsAvail-- == 1;
  if ( v50 )
  {
    v83 = buffer->m_pDataIn;
    v84 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v83 == v84 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v83 + 1;
    }
    else if ( v83 <= v84 )
    {
      buffer->m_nInBufWord = *v83;
      buffer->m_pDataIn = v83 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v81 >> 1;
  }
  this->m_bDataCompressed = v82 != 0;
  v85 = buffer->m_nBitsAvail;
  if ( v85 >= 1 )
  {
    v86 = buffer->m_nInBufWord;
    v87 = v86 & 1;
    v88 = v85 - 1;
    buffer->m_nBitsAvail = v88;
    if ( v88 != 0 )
    {
      buffer->m_nInBufWord = v86 >> 1;
      v89 = v86 & 1;
    }
    else
    {
      v90 = buffer->m_pDataIn;
      v91 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v90 == v91 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v90 + 1;
        v89 = v87;
      }
      else
      {
        if ( v90 <= v91 )
        {
          buffer->m_nInBufWord = *v90;
          buffer->m_pDataIn = v90 + 1;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v89 = v87;
      }
    }
    goto LABEL_127;
  }
  v92 = buffer->m_pBufferEnd;
  v93 = buffer->m_nInBufWord;
  v94 = 1 - v85;
  v95 = buffer->m_pDataIn;
  if ( v95 == v92 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v95 > v92 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_124;
    }
    buffer->m_nInBufWord = *v95;
  }
  buffer->m_pDataIn = v95 + 1;
LABEL_124:
  if ( buffer->m_bOverflow )
  {
    v89 = 0;
  }
  else
  {
    v96 = buffer->m_nInBufWord;
    v97 = (v96 & CBitBuffer::s_nMaskTable[v94]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v94;
    v89 = v97 | v93;
    buffer->m_nInBufWord = v96 >> v94;
  }
LABEL_127:
  m_nLength = this->m_nLength;
  this->m_nFlags = v89;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData != nullptr )
  {
    m_pData = (const unsigned int *)(32 * (buffer->m_pDataIn - m_pData)
                                   - buffer->m_nBitsAvail
                                   + 8 * (buffer->m_nDataBytes & 3));
    if ( (int)m_pData >= buffer->m_nDataBits )
      m_pData = (const unsigned int *)buffer->m_nDataBits;
  }
  return CBitRead::Seek(this: buffer, nPosition: (int)m_pData + m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BF8B0
// Name: public: virtual bool SVC_Sounds::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_Sounds::WriteToBuffer(SVC_Sounds *this, bf_write *buffer)
{
  SVC_Sounds_vtbl *v3; // edx
  unsigned int v4; // eax
  int m_iCurBit; // ecx
  int v6; // edx

  v3 = this->__vftable;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  v4 = ((int (*)(void))v3->GetType)();
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 6, bCheckRange: true);
  m_iCurBit = buffer->m_iCurBit;
  v6 = m_iCurBit + 1;
  if ( this->m_bReliableSound )
  {
    if ( v6 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++buffer->m_iCurBit;
    }
    bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 8, bCheckRange: true);
  }
  else
  {
    if ( v6 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++buffer->m_iCurBit;
    }
    bf_write::WriteUBitLong(this: buffer, curData: this->m_nNumSounds, numbits: 8, bCheckRange: true);
    bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 16, bCheckRange: true);
  }
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BF970
// Name: public: virtual bool SVC_Sounds::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_Sounds::ReadFromBuffer(SVC_Sounds *this, bf_read *buffer)
{
  unsigned int m_nInBufWord; // ecx
  int v4; // edx
  bool v5; // zf
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // esi
  int m_nBitsAvail; // ecx
  unsigned int v9; // edx
  int v10; // edi
  int v11; // ecx
  unsigned int v12; // esi
  const unsigned int *v13; // ecx
  const unsigned int *v14; // edx
  int v15; // edx
  int v16; // ecx
  unsigned int v17; // edx
  int v18; // esi
  int v19; // ecx
  const unsigned int *v20; // ecx
  const unsigned int *v21; // edx
  unsigned int v22; // edx
  const unsigned int *v23; // esi
  unsigned int v24; // edi
  int v25; // edx
  const unsigned int *v26; // ecx
  unsigned int v27; // esi
  unsigned int v28; // ebx
  unsigned int v29; // edx
  int v30; // ecx
  unsigned int v31; // edx
  const unsigned int *v32; // esi
  unsigned int v33; // edi
  int v34; // edx
  const unsigned int *v35; // ecx
  unsigned int v36; // esi
  unsigned int v37; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx
  SVC_Sounds *v41; // [esp+Ch] [ebp-4h]

  m_nInBufWord = buffer->m_nInBufWord;
  v4 = m_nInBufWord & 1;
  v5 = buffer->m_nBitsAvail-- == 1;
  v41 = this;
  if ( v5 )
  {
    m_pDataIn = buffer->m_pDataIn;
    m_pBufferEnd = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      buffer->m_nInBufWord = *m_pDataIn;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = m_nInBufWord >> 1;
  }
  this->m_bReliableSound = v4 != 0;
  if ( v4 != 0 )
  {
    this->m_nNumSounds = 1;
    m_nBitsAvail = buffer->m_nBitsAvail;
    if ( m_nBitsAvail >= 8 )
    {
      v9 = buffer->m_nInBufWord;
      v10 = (unsigned __int8)v9;
      v11 = m_nBitsAvail - 8;
      v12 = 0;
      buffer->m_nBitsAvail = v11;
      if ( v11 != 0 )
      {
        buffer->m_nInBufWord = v9 >> 8;
        goto LABEL_51;
      }
      goto LABEL_12;
    }
    v15 = 8;
    goto LABEL_41;
  }
  v16 = buffer->m_nBitsAvail;
  if ( v16 < 8 )
  {
    v23 = buffer->m_pBufferEnd;
    v24 = buffer->m_nInBufWord;
    v25 = 8 - v16;
    v26 = buffer->m_pDataIn;
    if ( v26 == v23 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v26 > v23 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_32:
        if ( buffer->m_bOverflow )
        {
          v19 = 0;
        }
        else
        {
          v27 = buffer->m_nInBufWord;
          v28 = (v27 & CBitBuffer::s_nMaskTable[v25]) << buffer->m_nBitsAvail;
          buffer->m_nBitsAvail = 32 - v25;
          v19 = v28 | v24;
          buffer->m_nInBufWord = v27 >> v25;
        }
        this = v41;
        goto LABEL_36;
      }
      buffer->m_nInBufWord = *v26;
    }
    buffer->m_pDataIn = v26 + 1;
    goto LABEL_32;
  }
  v17 = buffer->m_nInBufWord;
  v18 = (unsigned __int8)v17;
  buffer->m_nBitsAvail = v16 - 8;
  if ( v16 == 8 )
  {
    v20 = buffer->m_pDataIn;
    v21 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v20 == v21 )
    {
      buffer->m_pDataIn = v20 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v19 = v18;
    }
    else
    {
      if ( v20 <= v21 )
      {
        v22 = *v20;
        buffer->m_pDataIn = v20 + 1;
        buffer->m_nInBufWord = v22;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v19 = v18;
    }
  }
  else
  {
    buffer->m_nInBufWord = v17 >> 8;
    v19 = (unsigned __int8)v17;
  }
LABEL_36:
  this->m_nNumSounds = v19;
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 16 )
  {
    v29 = buffer->m_nInBufWord;
    v10 = (unsigned __int16)v29;
    v30 = m_nBitsAvail - 16;
    v12 = 0;
    buffer->m_nBitsAvail = v30;
    if ( v30 != 0 )
    {
      buffer->m_nInBufWord = HIWORD(v29);
      goto LABEL_51;
    }
LABEL_12:
    v13 = buffer->m_pDataIn;
    v14 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v13 == v14 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_pDataIn = v13 + 1;
    }
    else
    {
      if ( v13 <= v14 )
      {
        v31 = *v13;
        buffer->m_pDataIn = v13 + 1;
        buffer->m_nInBufWord = v31;
        goto LABEL_51;
      }
      buffer->m_bOverflow = true;
    }
    goto LABEL_50;
  }
  v15 = 16;
LABEL_41:
  v32 = buffer->m_pBufferEnd;
  v33 = buffer->m_nInBufWord;
  v34 = v15 - m_nBitsAvail;
  v35 = buffer->m_pDataIn;
  if ( v35 == v32 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_46:
    buffer->m_pDataIn = v35 + 1;
    goto LABEL_47;
  }
  if ( v35 <= v32 )
  {
    buffer->m_nInBufWord = *v35;
    goto LABEL_46;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_47:
  if ( buffer->m_bOverflow )
  {
    v10 = 0;
    goto LABEL_51;
  }
  v36 = buffer->m_nInBufWord;
  v37 = (v36 & CBitBuffer::s_nMaskTable[v34]) << buffer->m_nBitsAvail;
  buffer->m_nBitsAvail = 32 - v34;
  v10 = v37 | v33;
  v12 = v36 >> v34;
LABEL_50:
  buffer->m_nInBufWord = v12;
LABEL_51:
  v41->m_nLength = v10;
  qmemcpy(&v41->m_DataIn, buffer, sizeof(v41->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v41->m_nLength);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v41->m_nLength + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101BFC40
// Name: public: virtual bool SVC_TempEntities::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_TempEntities::ReadFromBuffer(SVC_TempEntities *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // ecx
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  unsigned int v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx
  int v16; // ecx
  unsigned int v17; // edx
  int v18; // esi
  int v19; // ecx
  int v20; // ebx
  const unsigned int *v21; // ecx
  const unsigned int *v22; // edx
  unsigned int v23; // edx
  const unsigned int *v24; // esi
  unsigned int v25; // edi
  int v26; // edx
  const unsigned int *v27; // ecx
  unsigned int v28; // esi
  unsigned int v29; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v12 = 8 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_16;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( buffer->m_bOverflow )
    {
      v6 = 0;
    }
    else
    {
      v14 = buffer->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v12;
      v6 = v15 | m_nInBufWord;
      buffer->m_nInBufWord = v14 >> v12;
    }
    goto LABEL_19;
  }
  v3 = buffer->m_nInBufWord;
  v4 = (unsigned __int8)v3;
  v5 = m_nBitsAvail - 8;
  buffer->m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    buffer->m_nInBufWord = v3 >> 8;
    v6 = (unsigned __int8)v3;
  }
  else
  {
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      buffer->m_pDataIn = v7 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v6 = v4;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v9 = *v7;
        buffer->m_pDataIn = v7 + 1;
        buffer->m_nInBufWord = v9;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v6 = v4;
    }
  }
LABEL_19:
  this->m_nNumEntries = v6;
  v16 = buffer->m_nBitsAvail;
  if ( v16 >= 17 )
  {
    v17 = buffer->m_nInBufWord;
    v18 = v17 & 0x1FFFF;
    v19 = v16 - 17;
    buffer->m_nBitsAvail = v19;
    if ( v19 != 0 )
    {
      buffer->m_nInBufWord = v17 >> 17;
      v20 = v17 & 0x1FFFF;
    }
    else
    {
      v21 = buffer->m_pDataIn;
      v22 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v21 == v22 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v21 + 1;
        v20 = v18;
      }
      else
      {
        if ( v21 <= v22 )
        {
          v23 = *v21;
          buffer->m_pDataIn = v21 + 1;
          buffer->m_nInBufWord = v23;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v20 = v18;
      }
    }
    goto LABEL_37;
  }
  v24 = buffer->m_pBufferEnd;
  v25 = buffer->m_nInBufWord;
  v26 = 17 - v16;
  v27 = buffer->m_pDataIn;
  if ( v27 == v24 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v27 > v24 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_34;
    }
    buffer->m_nInBufWord = *v27;
  }
  buffer->m_pDataIn = v27 + 1;
LABEL_34:
  if ( buffer->m_bOverflow )
  {
    v20 = 0;
  }
  else
  {
    v28 = buffer->m_nInBufWord;
    v29 = (v28 & CBitBuffer::s_nMaskTable[v26]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v26;
    v20 = v25 | v29;
    buffer->m_nInBufWord = v28 >> v26;
  }
LABEL_37:
  this->m_nLength = v20;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v20);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v20 + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101BFE70
// Name: public: virtual bool SVC_GameEvent::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_GameEvent::ReadFromBuffer(SVC_GameEvent *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // ebx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v9; // edx
  const unsigned int *v10; // esi
  unsigned int v11; // edi
  int v12; // edx
  const unsigned int *v13; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 11 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v4 = m_nInBufWord & 0x7FF;
    v5 = m_nBitsAvail - 11;
    buffer->m_nBitsAvail = v5;
    if ( v5 != 0 )
    {
      buffer->m_nInBufWord = m_nInBufWord >> 11;
      v6 = m_nInBufWord & 0x7FF;
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = m_pDataIn + 1;
        v6 = v4;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v9 = *m_pDataIn;
          buffer->m_pDataIn = m_pDataIn + 1;
          buffer->m_nInBufWord = v9;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v6 = v4;
      }
    }
    goto LABEL_19;
  }
  v10 = buffer->m_pBufferEnd;
  v11 = buffer->m_nInBufWord;
  v12 = 11 - m_nBitsAvail;
  v13 = buffer->m_pDataIn;
  if ( v13 == v10 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v13 > v10 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_16;
    }
    buffer->m_nInBufWord = *v13;
  }
  buffer->m_pDataIn = v13 + 1;
LABEL_16:
  if ( buffer->m_bOverflow )
  {
    v6 = 0;
  }
  else
  {
    v14 = buffer->m_nInBufWord;
    v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v12;
    v6 = v11 | v15;
    buffer->m_nInBufWord = v14 >> v12;
  }
LABEL_19:
  this->m_nLength = v6;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v6);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v6 + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101BFFD0
// Name: public: virtual bool SVC_SendTable::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_SendTable::WriteToBuffer(SVC_SendTable *this, bf_write *buffer)
{
  SVC_SendTable_vtbl *v3; // edx
  unsigned int v4; // eax
  int m_iCurBit; // ecx
  BOOL m_bNeedsDecoder; // eax

  v3 = this->__vftable;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  v4 = ((int (*)(void))v3->GetType)();
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 6, bCheckRange: true);
  m_iCurBit = buffer->m_iCurBit;
  m_bNeedsDecoder = this->m_bNeedsDecoder;
  if ( m_iCurBit + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bNeedsDecoder )
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
    else
      buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++buffer->m_iCurBit;
  }
  bf_write::WriteShort(this: buffer, val: this->m_nLength);
  bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101C0060
// Name: public: virtual bool SVC_SendTable::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_SendTable::ReadFromBuffer(SVC_SendTable *this, bf_read *buffer)
{
  unsigned int m_nInBufWord; // ecx
  int v4; // edx
  bool v5; // zf
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // esi
  int m_nBitsAvail; // ecx
  unsigned int v9; // edx
  __int16 v10; // si
  int v11; // ecx
  __int16 v12; // cx
  const unsigned int *v13; // ecx
  const unsigned int *v14; // edx
  unsigned int v15; // edx
  const unsigned int *v16; // esi
  unsigned int v17; // edi
  int v18; // edx
  const unsigned int *v19; // ecx
  unsigned int v20; // esi
  unsigned int v21; // ebx
  int v22; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx
  SVC_SendTable *v26; // [esp+Ch] [ebp-4h]

  m_nInBufWord = buffer->m_nInBufWord;
  v4 = m_nInBufWord & 1;
  v5 = buffer->m_nBitsAvail-- == 1;
  v26 = this;
  if ( v5 )
  {
    m_pDataIn = buffer->m_pDataIn;
    m_pBufferEnd = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      buffer->m_nInBufWord = *m_pDataIn;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = m_nInBufWord >> 1;
  }
  this->m_bNeedsDecoder = v4 != 0;
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 16 )
  {
    v9 = buffer->m_nInBufWord;
    v10 = v9;
    v11 = m_nBitsAvail - 16;
    buffer->m_nBitsAvail = v11;
    if ( v11 != 0 )
    {
      buffer->m_nInBufWord = HIWORD(v9);
      v12 = v9;
    }
    else
    {
      v13 = buffer->m_pDataIn;
      v14 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v13 == v14 )
      {
        buffer->m_pDataIn = v13 + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        v12 = v10;
      }
      else
      {
        if ( v13 <= v14 )
        {
          v15 = *v13;
          buffer->m_pDataIn = v13 + 1;
          buffer->m_nInBufWord = v15;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v12 = v10;
      }
    }
    goto LABEL_26;
  }
  v16 = buffer->m_pBufferEnd;
  v17 = buffer->m_nInBufWord;
  v18 = 16 - m_nBitsAvail;
  v19 = buffer->m_pDataIn;
  if ( v19 == v16 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v19 > v16 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_23;
    }
    buffer->m_nInBufWord = *v19;
  }
  buffer->m_pDataIn = v19 + 1;
LABEL_23:
  if ( buffer->m_bOverflow )
  {
    v12 = 0;
  }
  else
  {
    v20 = buffer->m_nInBufWord;
    v21 = (v20 & CBitBuffer::s_nMaskTable[v18]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v18;
    v12 = v21 | v17;
    buffer->m_nInBufWord = v20 >> v18;
  }
LABEL_26:
  v22 = v12;
  v26->m_nLength = v12;
  qmemcpy(&v26->m_DataIn, buffer, sizeof(v26->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v22);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: m_nDataBits + v22);
}

//------------------------------------------------------------------------------
// Address: 0x101C0210
// Name: public: virtual bool SVC_EntityMessage::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_EntityMessage::ReadFromBuffer(SVC_EntityMessage *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // ebx
  int v7; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v10; // edx
  const unsigned int *v11; // esi
  unsigned int v12; // edi
  int v13; // edx
  const unsigned int *v14; // ecx
  unsigned int v15; // esi
  unsigned int v16; // ebx
  int v17; // ecx
  unsigned int v18; // edx
  int v19; // esi
  int v20; // ecx
  int v21; // ecx
  const unsigned int *v22; // ecx
  const unsigned int *v23; // edx
  unsigned int v24; // edx
  const unsigned int *v25; // esi
  unsigned int v26; // edi
  int v27; // edx
  const unsigned int *v28; // ecx
  unsigned int v29; // esi
  unsigned int v30; // ebx
  int v31; // ecx
  unsigned int v32; // edx
  int v33; // esi
  int v34; // ecx
  const unsigned int *v35; // ecx
  const unsigned int *v36; // edx
  unsigned int v37; // edx
  const unsigned int *v38; // esi
  unsigned int v39; // edi
  int v40; // edx
  const unsigned int *v41; // ecx
  unsigned int v42; // esi
  unsigned int v43; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 11 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v4 = m_nInBufWord & 0x7FF;
    v5 = m_nBitsAvail - 11;
    v6 = 0;
    buffer->m_nBitsAvail = v5;
    if ( v5 != 0 )
    {
      buffer->m_nInBufWord = m_nInBufWord >> 11;
      v7 = m_nInBufWord & 0x7FF;
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_pDataIn = m_pDataIn + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        v7 = v4;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v10 = *m_pDataIn;
          buffer->m_pDataIn = m_pDataIn + 1;
          buffer->m_nInBufWord = v10;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v7 = v4;
      }
    }
    goto LABEL_20;
  }
  v11 = buffer->m_pBufferEnd;
  v12 = buffer->m_nInBufWord;
  v13 = 11 - m_nBitsAvail;
  v14 = buffer->m_pDataIn;
  if ( v14 == v11 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_15:
    buffer->m_pDataIn = v14 + 1;
    goto LABEL_16;
  }
  if ( v14 <= v11 )
  {
    buffer->m_nInBufWord = *v14;
    goto LABEL_15;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_16:
  if ( buffer->m_bOverflow )
  {
    v7 = 0;
  }
  else
  {
    v15 = buffer->m_nInBufWord;
    v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v13;
    v7 = v16 | v12;
    buffer->m_nInBufWord = v15 >> v13;
  }
  v6 = 0;
LABEL_20:
  this->m_nEntityIndex = v7;
  v17 = buffer->m_nBitsAvail;
  if ( v17 < 9 )
  {
    v25 = buffer->m_pBufferEnd;
    v26 = buffer->m_nInBufWord;
    v27 = 9 - v17;
    v28 = buffer->m_pDataIn;
    if ( v28 == v25 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v28 > v25 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_35;
      }
      buffer->m_nInBufWord = *v28;
    }
    buffer->m_pDataIn = v28 + 1;
LABEL_35:
    if ( buffer->m_bOverflow )
    {
      v21 = 0;
    }
    else
    {
      v29 = buffer->m_nInBufWord;
      v30 = (v29 & CBitBuffer::s_nMaskTable[v27]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v27;
      v21 = v30 | v26;
      v6 = 0;
      buffer->m_nInBufWord = v29 >> v27;
    }
    goto LABEL_38;
  }
  v18 = buffer->m_nInBufWord;
  v19 = v18 & 0x1FF;
  v20 = v17 - 9;
  buffer->m_nBitsAvail = v20;
  if ( v20 != 0 )
  {
    buffer->m_nInBufWord = v18 >> 9;
    v21 = v18 & 0x1FF;
  }
  else
  {
    v22 = buffer->m_pDataIn;
    v23 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v22 == v23 )
    {
      buffer->m_pDataIn = v22 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v21 = v19;
    }
    else
    {
      if ( v22 <= v23 )
      {
        v24 = *v22;
        buffer->m_pDataIn = v22 + 1;
        buffer->m_nInBufWord = v24;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v21 = v19;
    }
  }
LABEL_38:
  this->m_nClassID = v21;
  v31 = buffer->m_nBitsAvail;
  if ( v31 >= 11 )
  {
    v32 = buffer->m_nInBufWord;
    v33 = v32 & 0x7FF;
    v34 = v31 - 11;
    buffer->m_nBitsAvail = v34;
    if ( v34 != 0 )
    {
      buffer->m_nInBufWord = v32 >> 11;
      v6 = v32 & 0x7FF;
    }
    else
    {
      v35 = buffer->m_pDataIn;
      v36 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v35 == v36 )
      {
        buffer->m_nInBufWord = 0;
        buffer->m_nBitsAvail = 1;
        buffer->m_pDataIn = v35 + 1;
        v6 = v33;
      }
      else
      {
        if ( v35 <= v36 )
        {
          v37 = *v35;
          buffer->m_pDataIn = v35 + 1;
          buffer->m_nInBufWord = v37;
        }
        else
        {
          buffer->m_nInBufWord = 0;
          buffer->m_bOverflow = true;
        }
        v6 = v33;
      }
    }
    goto LABEL_55;
  }
  v38 = buffer->m_pBufferEnd;
  v39 = buffer->m_nInBufWord;
  v40 = 11 - v31;
  v41 = buffer->m_pDataIn;
  if ( v41 == v38 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v41 > v38 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_53;
    }
    buffer->m_nInBufWord = *v41;
  }
  buffer->m_pDataIn = v41 + 1;
LABEL_53:
  if ( !buffer->m_bOverflow )
  {
    v42 = buffer->m_nInBufWord;
    v43 = (v42 & CBitBuffer::s_nMaskTable[v40]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v40;
    v6 = v39 | v43;
    buffer->m_nInBufWord = v42 >> v40;
  }
LABEL_55:
  this->m_nLength = v6;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v6);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v6 + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101C0520
// Name: public: virtual bool SVC_PacketEntities::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_PacketEntities::WriteToBuffer(SVC_PacketEntities *this, bf_write *buffer)
{
  unsigned int v3; // eax
  int m_iCurBit; // ecx
  BOOL m_bIsDelta; // eax
  int v6; // ecx
  BOOL m_bUpdateBaseline; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nMaxEntries, numbits: 11, bCheckRange: true);
  m_iCurBit = buffer->m_iCurBit;
  m_bIsDelta = this->m_bIsDelta;
  if ( m_iCurBit + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bIsDelta )
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
    else
      buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++buffer->m_iCurBit;
  }
  if ( this->m_bIsDelta )
    bf_write::WriteLong(this: buffer, val: this->m_nDeltaFrom);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nBaseline, numbits: 1, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nUpdatedEntries, numbits: 11, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 20, bCheckRange: true);
  v6 = buffer->m_iCurBit;
  m_bUpdateBaseline = this->m_bUpdateBaseline;
  if ( v6 + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bUpdateBaseline )
      buffer->m_pData[v6 >> 3] |= 1 << (v6 & 7);
    else
      buffer->m_pData[v6 >> 3] &= ~(1 << (v6 & 7));
    ++buffer->m_iCurBit;
  }
  bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101C0630
// Name: public: virtual bool SVC_PacketEntities::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_PacketEntities::ReadFromBuffer(SVC_PacketEntities *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v5; // esi
  int v6; // ecx
  int v7; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v10; // edx
  const unsigned int *v11; // esi
  unsigned int v12; // edi
  int v13; // edx
  const unsigned int *v14; // ecx
  unsigned int v15; // esi
  unsigned int v16; // ebx
  unsigned int v17; // ecx
  int v18; // edx
  bool v19; // zf
  const unsigned int *v20; // ecx
  const unsigned int *v21; // esi
  int v22; // esi
  unsigned int v23; // ecx
  const unsigned int *v24; // edx
  const unsigned int *v25; // esi
  SVC_PacketEntities *v26; // edx
  unsigned int v27; // esi
  const unsigned int *v28; // ecx
  unsigned int v29; // edi
  int v30; // edx
  const unsigned int *v31; // esi
  unsigned int v32; // esi
  unsigned int v33; // ebx
  int v34; // ecx
  unsigned int v35; // edx
  int v36; // esi
  int v37; // ecx
  int v38; // ecx
  const unsigned int *v39; // ecx
  const unsigned int *v40; // edx
  unsigned int v41; // edx
  const unsigned int *v42; // esi
  unsigned int v43; // edi
  int v44; // edx
  const unsigned int *v45; // ecx
  unsigned int v46; // esi
  unsigned int v47; // ebx
  int v48; // ecx
  unsigned int v49; // edx
  int v50; // esi
  int v51; // ecx
  int v52; // ecx
  const unsigned int *v53; // ecx
  const unsigned int *v54; // edx
  unsigned int v55; // edx
  const unsigned int *v56; // esi
  unsigned int v57; // edi
  int v58; // edx
  const unsigned int *v59; // ecx
  unsigned int v60; // esi
  unsigned int v61; // ebx
  int v62; // ecx
  unsigned int v63; // edx
  int v64; // esi
  int v65; // ecx
  int v66; // ecx
  const unsigned int *v67; // ecx
  const unsigned int *v68; // edx
  unsigned int v69; // edx
  const unsigned int *v70; // esi
  unsigned int v71; // edi
  int v72; // edx
  const unsigned int *v73; // ecx
  unsigned int v74; // esi
  unsigned int v75; // ebx
  unsigned int v76; // ecx
  int v77; // edx
  const unsigned int *v78; // ecx
  const unsigned int *v79; // esi
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx
  SVC_PacketEntities *v83; // [esp+Ch] [ebp-4h]

  m_nBitsAvail = buffer->m_nBitsAvail;
  v83 = this;
  if ( m_nBitsAvail >= 11 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v5 = m_nInBufWord & 0x7FF;
    v6 = m_nBitsAvail - 11;
    buffer->m_nBitsAvail = v6;
    if ( v6 != 0 )
    {
      buffer->m_nInBufWord = m_nInBufWord >> 11;
      v7 = m_nInBufWord & 0x7FF;
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_pDataIn = m_pDataIn + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        v7 = v5;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v10 = *m_pDataIn;
          buffer->m_pDataIn = m_pDataIn + 1;
          buffer->m_nInBufWord = v10;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v7 = v5;
      }
    }
    goto LABEL_20;
  }
  v11 = buffer->m_pBufferEnd;
  v12 = buffer->m_nInBufWord;
  v13 = 11 - m_nBitsAvail;
  v14 = buffer->m_pDataIn;
  if ( v14 == v11 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_15:
    buffer->m_pDataIn = v14 + 1;
    goto LABEL_16;
  }
  if ( v14 <= v11 )
  {
    buffer->m_nInBufWord = *v14;
    goto LABEL_15;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_16:
  if ( buffer->m_bOverflow )
  {
    v7 = 0;
  }
  else
  {
    v15 = buffer->m_nInBufWord;
    v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v13;
    v7 = v16 | v12;
    buffer->m_nInBufWord = v15 >> v13;
  }
  this = v83;
LABEL_20:
  this->m_nMaxEntries = v7;
  v17 = buffer->m_nInBufWord;
  v18 = v17 & 1;
  v19 = buffer->m_nBitsAvail-- == 1;
  if ( v19 )
  {
    v20 = buffer->m_pDataIn;
    v21 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v20 == v21 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v20 + 1;
    }
    else if ( v20 <= v21 )
    {
      buffer->m_nInBufWord = *v20;
      buffer->m_pDataIn = v20 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v17 >> 1;
  }
  this->m_bIsDelta = v18 != 0;
  if ( v18 == 0 )
  {
    this->m_nDeltaFrom = -1;
    goto LABEL_47;
  }
  v22 = buffer->m_nBitsAvail;
  if ( v22 < 32 )
  {
    v28 = buffer->m_pDataIn;
    v29 = buffer->m_nInBufWord;
    v30 = 32 - v22;
    v31 = buffer->m_pBufferEnd;
    if ( v28 == v31 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v28 > v31 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_43;
      }
      buffer->m_nInBufWord = *v28;
    }
    buffer->m_pDataIn = v28 + 1;
LABEL_43:
    if ( buffer->m_bOverflow )
    {
      v83->m_nDeltaFrom = 0;
    }
    else
    {
      v32 = buffer->m_nInBufWord;
      v33 = (v32 & CBitBuffer::s_nMaskTable[v30]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v30;
      buffer->m_nInBufWord = v32 >> v30;
      v83->m_nDeltaFrom = v33 | v29;
    }
    goto LABEL_47;
  }
  v23 = buffer->m_nInBufWord;
  buffer->m_nBitsAvail = v22 - 32;
  if ( v22 == 32 )
  {
    v24 = buffer->m_pDataIn;
    v25 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v24 == v25 )
    {
      buffer->m_pDataIn = v24 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v83->m_nDeltaFrom = v23;
    }
    else
    {
      if ( v24 <= v25 )
      {
        v27 = *v24;
        buffer->m_pDataIn = v24 + 1;
        v26 = v83;
        buffer->m_nInBufWord = v27;
      }
      else
      {
        v26 = v83;
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v26->m_nDeltaFrom = v23;
    }
  }
  else
  {
    buffer->m_nInBufWord = 0;
    v83->m_nDeltaFrom = v23;
  }
LABEL_47:
  v34 = buffer->m_nBitsAvail;
  if ( v34 < 1 )
  {
    v42 = buffer->m_pBufferEnd;
    v43 = buffer->m_nInBufWord;
    v44 = 1 - v34;
    v45 = buffer->m_pDataIn;
    if ( v45 == v42 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v45 > v42 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_62;
      }
      buffer->m_nInBufWord = *v45;
    }
    buffer->m_pDataIn = v45 + 1;
LABEL_62:
    if ( buffer->m_bOverflow )
    {
      v38 = 0;
    }
    else
    {
      v46 = buffer->m_nInBufWord;
      v47 = (v46 & CBitBuffer::s_nMaskTable[v44]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v44;
      v38 = v47 | v43;
      buffer->m_nInBufWord = v46 >> v44;
    }
    goto LABEL_65;
  }
  v35 = buffer->m_nInBufWord;
  v36 = v35 & 1;
  v37 = v34 - 1;
  buffer->m_nBitsAvail = v37;
  if ( v37 != 0 )
  {
    buffer->m_nInBufWord = v35 >> 1;
    v38 = v35 & 1;
  }
  else
  {
    v39 = buffer->m_pDataIn;
    v40 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v39 == v40 )
    {
      buffer->m_pDataIn = v39 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v38 = v36;
    }
    else
    {
      if ( v39 <= v40 )
      {
        v41 = *v39;
        buffer->m_pDataIn = v39 + 1;
        buffer->m_nInBufWord = v41;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v38 = v36;
    }
  }
LABEL_65:
  v83->m_nBaseline = v38;
  v48 = buffer->m_nBitsAvail;
  if ( v48 < 11 )
  {
    v56 = buffer->m_pBufferEnd;
    v57 = buffer->m_nInBufWord;
    v58 = 11 - v48;
    v59 = buffer->m_pDataIn;
    if ( v59 == v56 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v59 > v56 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_80;
      }
      buffer->m_nInBufWord = *v59;
    }
    buffer->m_pDataIn = v59 + 1;
LABEL_80:
    if ( buffer->m_bOverflow )
    {
      v52 = 0;
    }
    else
    {
      v60 = buffer->m_nInBufWord;
      v61 = (v60 & CBitBuffer::s_nMaskTable[v58]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v58;
      v52 = v61 | v57;
      buffer->m_nInBufWord = v60 >> v58;
    }
    goto LABEL_83;
  }
  v49 = buffer->m_nInBufWord;
  v50 = v49 & 0x7FF;
  v51 = v48 - 11;
  buffer->m_nBitsAvail = v51;
  if ( v51 != 0 )
  {
    buffer->m_nInBufWord = v49 >> 11;
    v52 = v49 & 0x7FF;
  }
  else
  {
    v53 = buffer->m_pDataIn;
    v54 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v53 == v54 )
    {
      buffer->m_pDataIn = v53 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v52 = v50;
    }
    else
    {
      if ( v53 <= v54 )
      {
        v55 = *v53;
        buffer->m_pDataIn = v53 + 1;
        buffer->m_nInBufWord = v55;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v52 = v50;
    }
  }
LABEL_83:
  v83->m_nUpdatedEntries = v52;
  v62 = buffer->m_nBitsAvail;
  if ( v62 < 20 )
  {
    v70 = buffer->m_pBufferEnd;
    v71 = buffer->m_nInBufWord;
    v72 = 20 - v62;
    v73 = buffer->m_pDataIn;
    if ( v73 == v70 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v73 > v70 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_98;
      }
      buffer->m_nInBufWord = *v73;
    }
    buffer->m_pDataIn = v73 + 1;
LABEL_98:
    if ( buffer->m_bOverflow )
    {
      v66 = 0;
    }
    else
    {
      v74 = buffer->m_nInBufWord;
      v75 = (v74 & CBitBuffer::s_nMaskTable[v72]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v72;
      v66 = v75 | v71;
      buffer->m_nInBufWord = v74 >> v72;
    }
    goto LABEL_101;
  }
  v63 = buffer->m_nInBufWord;
  v64 = v63 & 0xFFFFF;
  v65 = v62 - 20;
  buffer->m_nBitsAvail = v65;
  if ( v65 != 0 )
  {
    buffer->m_nInBufWord = v63 >> 20;
    v66 = v63 & 0xFFFFF;
  }
  else
  {
    v67 = buffer->m_pDataIn;
    v68 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v67 == v68 )
    {
      buffer->m_pDataIn = v67 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v66 = v64;
    }
    else
    {
      if ( v67 <= v68 )
      {
        v69 = *v67;
        buffer->m_pDataIn = v67 + 1;
        buffer->m_nInBufWord = v69;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v66 = v64;
    }
  }
LABEL_101:
  v83->m_nLength = v66;
  v76 = buffer->m_nInBufWord;
  v77 = v76 & 1;
  v19 = buffer->m_nBitsAvail-- == 1;
  if ( v19 )
  {
    v78 = buffer->m_pDataIn;
    v79 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v78 == v79 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v78 + 1;
    }
    else if ( v78 <= v79 )
    {
      buffer->m_nInBufWord = *v78;
      buffer->m_pDataIn = v78 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v76 >> 1;
  }
  v83->m_bUpdateBaseline = v77 != 0;
  qmemcpy(&v83->m_DataIn, buffer, sizeof(v83->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v83->m_nLength);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v83->m_nLength + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101C0BE0
// Name: public: SVC_Menu::SVC_Menu(enum DIALOG_TYPE,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
SVC_Menu *__thiscall SVC_Menu::SVC_Menu(SVC_Menu *this, DIALOG_TYPE type, KeyValues *data)
{
  this->m_NetChannel = nullptr;
  this->__vftable = (SVC_Menu_vtbl *)&SVC_Menu::`vftable';
  this->m_bReliable = true;
  this->m_Type = type;
  this->m_MenuKeyValues = KeyValues::MakeCopy(this: data);
  this->m_iLength = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C0C20
// Name: public: virtual bool SVC_GameEventList::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_GameEventList::ReadFromBuffer(SVC_GameEventList *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // ecx
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  unsigned int v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx
  int v16; // ecx
  unsigned int v17; // edx
  int v18; // esi
  int v19; // ecx
  int v20; // ebx
  const unsigned int *v21; // ecx
  const unsigned int *v22; // edx
  unsigned int v23; // edx
  const unsigned int *v24; // esi
  unsigned int v25; // edi
  int v26; // edx
  const unsigned int *v27; // ecx
  unsigned int v28; // esi
  unsigned int v29; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 9 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v12 = 9 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_16;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( buffer->m_bOverflow )
    {
      v6 = 0;
    }
    else
    {
      v14 = buffer->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v12;
      v6 = v15 | m_nInBufWord;
      buffer->m_nInBufWord = v14 >> v12;
    }
    goto LABEL_19;
  }
  v3 = buffer->m_nInBufWord;
  v4 = v3 & 0x1FF;
  v5 = m_nBitsAvail - 9;
  buffer->m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    buffer->m_nInBufWord = v3 >> 9;
    v6 = v3 & 0x1FF;
  }
  else
  {
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      buffer->m_pDataIn = v7 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v6 = v4;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v9 = *v7;
        buffer->m_pDataIn = v7 + 1;
        buffer->m_nInBufWord = v9;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v6 = v4;
    }
  }
LABEL_19:
  this->m_nNumEvents = v6;
  v16 = buffer->m_nBitsAvail;
  if ( v16 >= 20 )
  {
    v17 = buffer->m_nInBufWord;
    v18 = v17 & 0xFFFFF;
    v19 = v16 - 20;
    buffer->m_nBitsAvail = v19;
    if ( v19 != 0 )
    {
      buffer->m_nInBufWord = v17 >> 20;
      v20 = v17 & 0xFFFFF;
    }
    else
    {
      v21 = buffer->m_pDataIn;
      v22 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v21 == v22 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v21 + 1;
        v20 = v18;
      }
      else
      {
        if ( v21 <= v22 )
        {
          v23 = *v21;
          buffer->m_pDataIn = v21 + 1;
          buffer->m_nInBufWord = v23;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v20 = v18;
      }
    }
    goto LABEL_37;
  }
  v24 = buffer->m_pBufferEnd;
  v25 = buffer->m_nInBufWord;
  v26 = 20 - v16;
  v27 = buffer->m_pDataIn;
  if ( v27 == v24 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v27 > v24 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_34;
    }
    buffer->m_nInBufWord = *v27;
  }
  buffer->m_pDataIn = v27 + 1;
LABEL_34:
  if ( buffer->m_bOverflow )
  {
    v20 = 0;
  }
  else
  {
    v28 = buffer->m_nInBufWord;
    v29 = (v28 & CBitBuffer::s_nMaskTable[v26]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v26;
    v20 = v25 | v29;
    buffer->m_nInBufWord = v28 >> v26;
  }
LABEL_37:
  this->m_nLength = v20;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v20);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v20 + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101C0E50
// Name: public: virtual bool SVC_PaintmapData::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_PaintmapData::ReadFromBuffer(SVC_PaintmapData *this, bf_read *buffer)
{
  int m_nBitsAvail; // esi
  unsigned int m_nInBufWord; // ecx
  int v4; // ebx
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // esi
  const unsigned int *v7; // ecx
  unsigned int v8; // edi
  int v9; // edx
  const unsigned int *v10; // esi
  unsigned int v11; // esi
  unsigned int v12; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 32 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    buffer->m_nBitsAvail = m_nBitsAvail - 32;
    if ( m_nBitsAvail == 32 )
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = m_pDataIn + 1;
        v4 = m_nInBufWord;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          buffer->m_nInBufWord = *m_pDataIn;
          buffer->m_pDataIn = m_pDataIn + 1;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v4 = m_nInBufWord;
      }
    }
    else
    {
      buffer->m_nInBufWord = 0;
      v4 = m_nInBufWord;
    }
    goto LABEL_19;
  }
  v7 = buffer->m_pDataIn;
  v8 = buffer->m_nInBufWord;
  v9 = 32 - m_nBitsAvail;
  v10 = buffer->m_pBufferEnd;
  if ( v7 == v10 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v7 > v10 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_16;
    }
    buffer->m_nInBufWord = *v7;
  }
  buffer->m_pDataIn = v7 + 1;
LABEL_16:
  if ( buffer->m_bOverflow )
  {
    v4 = 0;
  }
  else
  {
    v11 = buffer->m_nInBufWord;
    v12 = (v11 & CBitBuffer::s_nMaskTable[v9]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v9;
    v4 = v8 | v12;
    buffer->m_nInBufWord = v11 >> v9;
  }
LABEL_19:
  this->m_nLength = v4;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v4);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v4 + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101C0FA0
// Name: public: virtual bool CLC_ListenEvents::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLC_ListenEvents::WriteToBuffer(CLC_ListenEvents *this, bf_write *buffer)
{
  unsigned int v3; // eax
  unsigned int *v4; // edi
  int m_iCurBit; // eax
  int m_nDataBits; // ecx
  unsigned int v7; // edi
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  int v14; // eax
  int v15; // ecx
  int v16; // edx
  int v17; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // edx
  int v21; // eax
  bool v22; // zf
  int v24; // [esp+Ch] [ebp-Ch]
  unsigned int *v25; // [esp+10h] [ebp-8h]
  unsigned int v26; // [esp+14h] [ebp-4h]
  unsigned int v27; // [esp+14h] [ebp-4h]
  unsigned int v28; // [esp+14h] [ebp-4h]

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  v4 = &this->m_EventArray.m_Ints[1];
  v25 = v4;
  v24 = 4;
  do
  {
    m_iCurBit = buffer->m_iCurBit;
    m_nDataBits = buffer->m_nDataBits;
    v7 = *(v4 - 1);
    if ( m_iCurBit + 32 <= m_nDataBits )
    {
      v8 = m_iCurBit >> 5;
      *(_DWORD *)&buffer->m_pData[4 * (buffer->m_iCurBit >> 5)] = (v7 << (buffer->m_iCurBit & 0x1F))
                                                                | *(_DWORD *)&buffer->m_pData[4
                                                                                            * (buffer->m_iCurBit >> 5)]
                                                                & dword_106C7448[33 * (buffer->m_iCurBit & 0x1F)];
      v9 = 32 - (m_iCurBit & 0x1F);
      if ( v9 < 32 )
        *(_DWORD *)&buffer->m_pData[4 * v8 + 4] = (v7 >> v9)
                                                | *(_DWORD *)&buffer->m_pData[4 * v8 + 4] & dword_106C7448[-v9];
      buffer->m_iCurBit += 32;
    }
    else
    {
      buffer->m_iCurBit = m_nDataBits;
      buffer->m_bOverflow = true;
    }
    v10 = buffer->m_iCurBit;
    v11 = buffer->m_nDataBits;
    v26 = *v25;
    if ( v10 + 32 <= v11 )
    {
      v12 = v10 >> 5;
      *(_DWORD *)&buffer->m_pData[4 * (buffer->m_iCurBit >> 5)] = (*v25 << (buffer->m_iCurBit & 0x1F))
                                                                | *(_DWORD *)&buffer->m_pData[4
                                                                                            * (buffer->m_iCurBit >> 5)]
                                                                & dword_106C7448[33 * (buffer->m_iCurBit & 0x1F)];
      v13 = 32 - (v10 & 0x1F);
      if ( v13 < 32 )
        *(_DWORD *)&buffer->m_pData[4 * v12 + 4] = (v26 >> v13)
                                                 | *(_DWORD *)&buffer->m_pData[4 * v12 + 4] & dword_106C7448[-v13];
      buffer->m_iCurBit += 32;
    }
    else
    {
      buffer->m_iCurBit = v11;
      buffer->m_bOverflow = true;
    }
    v14 = buffer->m_iCurBit;
    v15 = buffer->m_nDataBits;
    v27 = v25[1];
    if ( v14 + 32 <= v15 )
    {
      v16 = v14 >> 5;
      *(_DWORD *)&buffer->m_pData[4 * (buffer->m_iCurBit >> 5)] = (v25[1] << (buffer->m_iCurBit & 0x1F))
                                                                | *(_DWORD *)&buffer->m_pData[4
                                                                                            * (buffer->m_iCurBit >> 5)]
                                                                & dword_106C7448[33 * (buffer->m_iCurBit & 0x1F)];
      v17 = 32 - (v14 & 0x1F);
      if ( v17 < 32 )
        *(_DWORD *)&buffer->m_pData[4 * v16 + 4] = (v27 >> v17)
                                                 | *(_DWORD *)&buffer->m_pData[4 * v16 + 4] & dword_106C7448[-v17];
      buffer->m_iCurBit += 32;
    }
    else
    {
      buffer->m_iCurBit = v15;
      buffer->m_bOverflow = true;
    }
    v18 = buffer->m_iCurBit;
    v19 = buffer->m_nDataBits;
    v28 = v25[2];
    if ( v18 + 32 <= v19 )
    {
      v20 = v18 >> 5;
      *(_DWORD *)&buffer->m_pData[4 * (buffer->m_iCurBit >> 5)] = (v25[2] << (buffer->m_iCurBit & 0x1F))
                                                                | *(_DWORD *)&buffer->m_pData[4
                                                                                            * (buffer->m_iCurBit >> 5)]
                                                                & dword_106C7448[33 * (buffer->m_iCurBit & 0x1F)];
      v21 = 32 - (v18 & 0x1F);
      if ( v21 < 32 )
        *(_DWORD *)&buffer->m_pData[4 * v20 + 4] = (v28 >> v21)
                                                 | *(_DWORD *)&buffer->m_pData[4 * v20 + 4] & dword_106C7448[-v21];
      buffer->m_iCurBit += 32;
    }
    else
    {
      buffer->m_iCurBit = v19;
      buffer->m_bOverflow = true;
    }
    v4 = v25 + 4;
    v22 = v24-- == 1;
    v25 += 4;
  }
  while ( !v22 );
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101C11F0
// Name: public: virtual bool CLC_ListenEvents::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_ListenEvents::ReadFromBuffer(CLC_ListenEvents *this, bf_read *buffer)
{
  int m_nBitsAvail; // esi
  unsigned int m_nInBufWord; // ecx
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // esi
  const unsigned int *v7; // ecx
  unsigned int v8; // edi
  int v9; // edx
  const unsigned int *v10; // esi
  unsigned int v11; // esi
  unsigned int v12; // ebx
  bool v13; // zf
  int v15; // [esp+Ch] [ebp-4h]
  bf_read *buffera; // [esp+18h] [ebp+8h]

  buffera = (bf_read *)&this->m_EventArray;
  v15 = 16;
  do
  {
    m_nBitsAvail = buffer->m_nBitsAvail;
    if ( m_nBitsAvail >= 32 )
    {
      m_nInBufWord = buffer->m_nInBufWord;
      buffer->m_nBitsAvail = m_nBitsAvail - 32;
      if ( m_nBitsAvail == 32 )
      {
        m_pDataIn = buffer->m_pDataIn;
        m_pBufferEnd = buffer->m_pBufferEnd;
        buffer->m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          buffer->m_nBitsAvail = 1;
          buffer->m_nInBufWord = 0;
          buffer->m_pDataIn = m_pDataIn + 1;
        }
        else if ( m_pDataIn <= m_pBufferEnd )
        {
          buffer->m_nInBufWord = *m_pDataIn;
          buffer->m_pDataIn = m_pDataIn + 1;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
      }
      else
      {
        buffer->m_nInBufWord = 0;
      }
      goto LABEL_19;
    }
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_nInBufWord;
    v9 = 32 - m_nBitsAvail;
    v10 = buffer->m_pBufferEnd;
    if ( v7 == v10 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v7 > v10 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_16;
      }
      buffer->m_nInBufWord = *v7;
    }
    buffer->m_pDataIn = v7 + 1;
LABEL_16:
    if ( buffer->m_bOverflow )
    {
      m_nInBufWord = 0;
    }
    else
    {
      v11 = buffer->m_nInBufWord;
      v12 = (v11 & CBitBuffer::s_nMaskTable[v9]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v9;
      m_nInBufWord = v12 | v8;
      buffer->m_nInBufWord = v11 >> v9;
    }
LABEL_19:
    buffera->m_pDebugName = (const char *)m_nInBufWord;
    v13 = v15-- == 1;
    buffera = (bf_read *)((char *)buffera + 4);
  }
  while ( !v13 );
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101C1310
// Name: public: virtual char const __near * CLC_ListenEvents::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLC_ListenEvents::ToString(CLC_ListenEvents *this)
{
  int v1; // esi
  int v2; // eax
  unsigned int v3; // edx
  int i; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  const char *v8; // eax
  int v10; // [esp-4h] [ebp-10h]

  v1 = 0;
  v2 = 1;
  v3 = 2;
  for ( i = 128; i != 0; --i )
  {
    if ( (v2 & this->m_EventArray.m_Ints[(v3 - 2) >> 5]) != 0 )
      ++v1;
    v5 = __ROL4__(v2, 1);
    if ( (v5 & this->m_EventArray.m_Ints[(v3 - 1) >> 5]) != 0 )
      ++v1;
    v6 = __ROL4__(v5, 1);
    if ( (v6 & this->m_EventArray.m_Ints[v3 >> 5]) != 0 )
      ++v1;
    v7 = __ROL4__(v6, 1);
    if ( (v7 & this->m_EventArray.m_Ints[(v3 + 1) >> 5]) != 0 )
      ++v1;
    v2 = __ROL4__(v7, 1);
    v3 += 4;
  }
  v8 = (const char *)((int (__thiscall *)(CLC_ListenEvents *, int))this->GetName)(a1: this, a2: v1);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: registered events %i", v8, v10);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101C1390
// Name: public: virtual bool NET_SignonState::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall NET_SignonState::WriteToBuffer(NET_SignonState *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteByte(this: buffer, val: this->m_nSignonState);
  bf_write::WriteLong(this: buffer, val: this->m_nSpawnCount);
  bf_write::WriteLong(this: buffer, val: this->m_numServerPlayers);
  bf_write::WriteLong(this: buffer, val: this->m_PlayersNetworkIds.m_Size);
  if ( this->m_PlayersNetworkIds.m_Size > 0 )
    bf_write::WriteBytes(
      this: buffer,
      pBuf: this->m_PlayersNetworkIds.m_Memory.m_pMemory,
      nBytes: this->m_PlayersNetworkIds.m_Size);
  bf_write::WriteLong(this: buffer, val: this->m_Mapname.m_Size);
  if ( this->m_Mapname.m_Size > 0 )
    bf_write::WriteBytes(this: buffer, pBuf: this->m_Mapname.m_Memory.m_pMemory, nBytes: this->m_Mapname.m_Size);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101C1420
// Name: public: virtual bool NET_SetConVar::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall NET_SetConVar::WriteToBuffer(NET_SetConVar *this, bf_write *buffer)
{
  NET_SetConVar *v2; // esi
  unsigned int v3; // eax
  signed int m_Size; // ebx
  int v6; // ebx
  const char *name; // esi
  int numvars; // [esp+18h] [ebp+8h]

  v2 = this;
  v3 = ((int (__fastcall *)(NET_SetConVar *))this->GetType)(a1: this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_Size = v2->m_ConVars.m_Size;
  numvars = m_Size;
  bf_write::WriteByte(this: buffer, val: m_Size);
  if ( m_Size > 0 )
  {
    v6 = 0;
    while ( 1 )
    {
      name = v2->m_ConVars.m_Memory.m_pMemory[v6].name;
      bf_write::WriteString(this: buffer, pStr: name);
      bf_write::WriteString(this: buffer, pStr: name + 260);
      ++v6;
      if ( --numvars == 0 )
        break;
      v2 = this;
    }
  }
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101C14A0
// Name: public: virtual char const __near * NET_SetConVar::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall NET_SetConVar::ToString(NET_SetConVar *this)
{
  const char *v1; // eax
  int v3; // [esp-Ch] [ebp-10h]
  const char *v4; // [esp-8h] [ebp-Ch]
  const char *v5; // [esp-4h] [ebp-8h]

  v1 = (const char *)((int (__thiscall *)(NET_SetConVar *, int, NetMessageCvar_t *, char *))this->GetName)(
                       a1: this,
                       a2: this->m_ConVars.m_Size,
                       a3: this->m_ConVars.m_Memory.m_pMemory,
                       a4: this->m_ConVars.m_Memory.m_pMemory->value);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: %i cvars, \"%s\"=\"%s\"", v1, v3, v4, v5);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101C14E0
// Name: public: virtual bool SVC_ClassInfo::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_ClassInfo::WriteToBuffer(SVC_ClassInfo *this, bf_write *buffer)
{
  unsigned int v3; // eax
  unsigned int v5; // eax
  int m_iCurBit; // ecx
  int v7; // eax
  BOOL m_bCreateOnClient; // edx
  unsigned __int8 *m_pData; // esi
  SVC_ClassInfo::class_s *v10; // esi
  int serverClassBits; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]
  bf_write *buffera; // [esp+1Ch] [ebp+8h]

  if ( !this->m_bCreateOnClient )
    this->m_nNumServerClasses = this->m_Classes.m_Size;
  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteShort(this: buffer, val: this->m_nNumServerClasses);
  v5 = Q_log2(val: this->m_nNumServerClasses);
  m_iCurBit = buffer->m_iCurBit;
  v7 = v5 + 1;
  m_bCreateOnClient = this->m_bCreateOnClient;
  serverClassBits = v7;
  if ( m_iCurBit + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    m_pData = buffer->m_pData;
    if ( m_bCreateOnClient )
      m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
    else
      m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++buffer->m_iCurBit;
  }
  if ( !this->m_bCreateOnClient )
  {
    i = 0;
    if ( this->m_nNumServerClasses > 0 )
    {
      buffera = nullptr;
      while ( 1 )
      {
        v10 = (SVC_ClassInfo::class_s *)((char *)buffera + (unsigned int)this->m_Classes.m_Memory.m_pMemory);
        bf_write::WriteUBitLong(this: buffer, curData: v10->classID, numbits: v7, bCheckRange: true);
        bf_write::WriteString(this: buffer, pStr: v10->classname);
        bf_write::WriteString(this: buffer, pStr: v10->datatablename);
        buffera = (bf_write *)((char *)buffera + 516);
        if ( ++i >= this->m_nNumServerClasses )
          break;
        v7 = serverClassBits;
      }
    }
  }
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101C15E0
// Name: public: virtual bool Base_CmdKeyValues::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Base_CmdKeyValues::ReadFromBuffer(Base_CmdKeyValues *this, bf_read *buffer)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  int m_nBitsAvail; // ecx
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // edi
  const unsigned int *v9; // ecx
  const unsigned int *v10; // edx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v13; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ebx
  void *v17; // esp
  bool v19; // bl
  _BYTE v20[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer bufRead; // [esp+Ch] [ebp-34h] BYREF
  Base_CmdKeyValues *v22; // [esp+3Ch] [ebp-4h]

  v22 = this;
  if ( this->m_pKeyValues == nullptr )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: defaultValue);
    else
      v4 = nullptr;
    this->m_pKeyValues = v4;
  }
  KeyValues::Clear(this: this->m_pKeyValues);
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 32 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v13 = 32 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_21;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
LABEL_21:
    if ( buffer->m_bOverflow )
    {
      v8 = 0;
    }
    else
    {
      v15 = buffer->m_nInBufWord;
      v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v13;
      v8 = v16 | m_nInBufWord;
      buffer->m_nInBufWord = v15 >> v13;
    }
    goto LABEL_24;
  }
  v6 = buffer->m_nInBufWord;
  v7 = m_nBitsAvail - 32;
  buffer->m_nBitsAvail = v7;
  if ( v7 != 0 )
  {
    buffer->m_nInBufWord = 0;
    v8 = v6;
  }
  else
  {
    v9 = buffer->m_pDataIn;
    v10 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v9 == v10 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v9 + 1;
      v8 = v6;
    }
    else
    {
      if ( v9 <= v10 )
      {
        buffer->m_nInBufWord = *v9;
        buffer->m_pDataIn = v9 + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v8 = v6;
    }
  }
LABEL_24:
  v17 = alloca(v8);
  CBitRead::ReadBits(this: buffer, pOutData: v20, nBits: 8 * v8);
  CUtlBuffer::CUtlBuffer(this: &bufRead, pBuffer: v20, nSize: v8, nFlags: 8);
  CUtlBuffer::ActivateByteSwapping(this: &bufRead, bActivate: true);
  if ( KeyValues::ReadAsBinary(this: v22->m_pKeyValues, buffer: &bufRead) )
  {
    v19 = !buffer->m_bOverflow;
    if ( bufRead.m_Memory.m_nGrowSize >= 0 && bufRead.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufRead.m_Memory.m_pMemory);
    return v19;
  }
  else
  {
    if ( bufRead.m_Memory.m_nGrowSize >= 0 && bufRead.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufRead.m_Memory.m_pMemory);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C17A0
// Name: public: virtual bool SVC_CmdKeyValues::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_CmdKeyValues::ReadFromBuffer(SVC_CmdKeyValues *this, bf_read *buffer)
{
  return Base_CmdKeyValues::ReadFromBuffer(this, buffer);
}

//------------------------------------------------------------------------------
// Address: 0x101C17B0
// Name: public: virtual bool SVC_Menu::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_Menu::WriteToBuffer(SVC_Menu *this, bf_write *buffer)
{
  unsigned int v4; // eax
  bool v5; // bl
  CUtlBuffer buf; // [esp+4h] [ebp-30h] BYREF

  if ( this->m_MenuKeyValues == nullptr )
    return false;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  KeyValues::WriteAsBinary(this: this->m_MenuKeyValues, buffer: &buf);
  if ( buf.m_Put > 4096 )
  {
    _Msg(a1: "Too much menu data (4096 bytes max)\n");
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return false;
  }
  v4 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 6, bCheckRange: true);
  bf_write::WriteShort(this: buffer, val: this->m_Type);
  bf_write::WriteWord(this: buffer, val: buf.m_Put);
  bf_write::WriteBytes(this: buffer, pBuf: buf.m_Memory.m_pMemory, nBytes: buf.m_Put);
  v5 = !buffer->m_bOverflow;
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101C1890
// Name: public: virtual bool SVC_Menu::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_Menu::ReadFromBuffer(SVC_Menu *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  __int16 v4; // di
  unsigned int v5; // edx
  const unsigned int *v6; // eax
  const unsigned int *v7; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v10; // eax
  const unsigned int *m_pDataIn; // ecx
  __int16 v12; // ax
  unsigned int v13; // edx
  unsigned int v14; // ebx
  SVC_Menu *v15; // edi
  int v16; // ecx
  unsigned int v17; // edx
  int v18; // eax
  unsigned int v19; // edx
  const unsigned int *v20; // ecx
  const unsigned int *v21; // edx
  const unsigned int *v22; // edx
  unsigned int v23; // edi
  int v24; // eax
  const unsigned int *v25; // ecx
  unsigned int v26; // edx
  unsigned int v27; // ebx
  char v28; // cl
  KeyValues *m_MenuKeyValues; // ecx
  KeyValues *v30; // eax
  KeyValues *v31; // eax
  bool v32; // bl
  CUtlBuffer buf; // [esp+Ch] [ebp-34h] BYREF
  SVC_Menu *v35; // [esp+3Ch] [ebp-4h]

  v35 = this;
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 16 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v10 = 16 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_15:
        if ( buffer->m_bOverflow )
        {
          v12 = 0;
          goto LABEL_20;
        }
        v13 = buffer->m_nInBufWord;
        v14 = (v13 & CBitBuffer::s_nMaskTable[v10]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v10;
        v4 = v14 | m_nInBufWord;
        v5 = v13 >> v10;
        goto LABEL_18;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v3 = buffer->m_nInBufWord;
  v4 = v3;
  buffer->m_nBitsAvail = m_nBitsAvail - 16;
  if ( m_nBitsAvail == 16 )
  {
    v6 = buffer->m_pDataIn;
    v7 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v6 == v7 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v6 + 1;
    }
    else if ( v6 <= v7 )
    {
      buffer->m_nInBufWord = *v6;
      buffer->m_pDataIn = v6 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
    goto LABEL_19;
  }
  v5 = HIWORD(v3);
LABEL_18:
  buffer->m_nInBufWord = v5;
LABEL_19:
  v12 = v4;
LABEL_20:
  v15 = v35;
  v35->m_Type = v12;
  v16 = buffer->m_nBitsAvail;
  if ( v16 >= 16 )
  {
    v17 = buffer->m_nInBufWord;
    v18 = (unsigned __int16)v17;
    buffer->m_nBitsAvail = v16 - 16;
    if ( v16 == 16 )
    {
      v20 = buffer->m_pDataIn;
      v21 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v20 == v21 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v20 + 1;
        goto LABEL_38;
      }
      if ( v20 > v21 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_38;
      }
      v19 = *v20;
      buffer->m_pDataIn = v20 + 1;
    }
    else
    {
      v19 = HIWORD(v17);
    }
    goto LABEL_37;
  }
  v22 = buffer->m_pBufferEnd;
  v23 = buffer->m_nInBufWord;
  v24 = 16 - v16;
  v25 = buffer->m_pDataIn;
  if ( v25 == v22 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_33:
    buffer->m_pDataIn = v25 + 1;
    goto LABEL_34;
  }
  if ( v25 <= v22 )
  {
    buffer->m_nInBufWord = *v25;
    goto LABEL_33;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_34:
  if ( buffer->m_bOverflow )
  {
    v15 = v35;
    v18 = 0;
    goto LABEL_38;
  }
  v26 = buffer->m_nInBufWord;
  v27 = (v26 & CBitBuffer::s_nMaskTable[v24]) << buffer->m_nBitsAvail;
  buffer->m_nBitsAvail = 32 - v24;
  v28 = v24;
  v18 = v27 | v23;
  v15 = v35;
  v19 = v26 >> v28;
LABEL_37:
  buffer->m_nInBufWord = v19;
LABEL_38:
  v15->m_iLength = v18;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: v18, nFlags: 0);
  CBitRead::ReadBytes(this: buffer, pOut: (char *)buf.m_Memory.m_pMemory, nBytes: v15->m_iLength);
  CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v15->m_iLength);
  m_MenuKeyValues = v15->m_MenuKeyValues;
  if ( m_MenuKeyValues != nullptr )
    KeyValues::deleteThis(this: m_MenuKeyValues);
  v30 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v30 != nullptr )
    v31 = KeyValues::KeyValues(this: v30, setName: "menu");
  else
    v31 = nullptr;
  v15->m_MenuKeyValues = v31;
  KeyValues::ReadAsBinary(this: v31, buffer: (int)&buf);
  v32 = !buffer->m_bOverflow;
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return v32;
}

//------------------------------------------------------------------------------
// Address: 0x101C1AF0
// Name: public: virtual bool Base_CmdKeyValues::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Base_CmdKeyValues::WriteToBuffer(Base_CmdKeyValues *this, bf_write *buffer)
{
  unsigned int v4; // eax
  int m_nMaxPut; // edi
  bool v6; // bl
  CUtlBuffer bufData; // [esp+4h] [ebp-30h] BYREF

  if ( this->m_pKeyValues == nullptr )
    return false;
  v4 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 6, bCheckRange: true);
  CUtlBuffer::CUtlBuffer(this: &bufData, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::ActivateByteSwapping(this: &bufData, bActivate: true);
  if ( KeyValues::WriteAsBinary(this: this->m_pKeyValues, buffer: &bufData) )
  {
    m_nMaxPut = bufData.m_nMaxPut;
    bf_write::WriteLong(this: buffer, val: bufData.m_nMaxPut);
    bf_write::WriteBits(this: buffer, pInData: bufData.m_Memory.m_pMemory, nBits: 8 * m_nMaxPut);
    v6 = !buffer->m_bOverflow;
    if ( bufData.m_Memory.m_nGrowSize >= 0 && bufData.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufData.m_Memory.m_pMemory);
    return v6;
  }
  else
  {
    if ( bufData.m_Memory.m_nGrowSize >= 0 && bufData.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufData.m_Memory.m_pMemory);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C1BC0
// Name: public: virtual bool SVC_CmdKeyValues::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_CmdKeyValues::WriteToBuffer(SVC_CmdKeyValues *this, bf_write *buffer)
{
  return Base_CmdKeyValues::WriteToBuffer(this, buffer);
}

//------------------------------------------------------------------------------
// Address: 0x101C1BD0
// Name: public: virtual bool NET_SetConVar::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall NET_SetConVar::ReadFromBuffer(NET_SetConVar *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v4; // edx
  int v5; // edi
  unsigned int v6; // edx
  const unsigned int *v7; // eax
  const unsigned int *v8; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v11; // eax
  const unsigned int *m_pDataIn; // ecx
  int v13; // eax
  unsigned int v14; // edx
  unsigned int v15; // esi
  CUtlMemory<NetMessageCvar_t,int> *p_m_Memory; // esi
  NetMessageCvar_t *m_pMemory; // edi
  int m_nAllocationCount; // eax
  NetMessageCvar_t *v19; // ecx
  int v20; // eax
  NetMessageCvar_t *v21; // edi
  NetMessageCvar_t cvar; // [esp+Ch] [ebp-20Ch] BYREF
  NET_SetConVar *v24; // [esp+214h] [ebp-4h]
  bf_read *buffera; // [esp+220h] [ebp+8h]

  v24 = this;
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v11 = 8 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_15:
        if ( buffer->m_bOverflow )
        {
          v13 = 0;
          goto LABEL_20;
        }
        v14 = buffer->m_nInBufWord;
        v15 = (v14 & CBitBuffer::s_nMaskTable[v11]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v11;
        v5 = v15 | m_nInBufWord;
        v6 = v14 >> v11;
        goto LABEL_18;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v4 = buffer->m_nInBufWord;
  v5 = (unsigned __int8)v4;
  buffer->m_nBitsAvail = m_nBitsAvail - 8;
  if ( m_nBitsAvail == 8 )
  {
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v7 + 1;
    }
    else if ( v7 <= v8 )
    {
      buffer->m_nInBufWord = *v7;
      buffer->m_pDataIn = v7 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
    goto LABEL_19;
  }
  v6 = v4 >> 8;
LABEL_18:
  buffer->m_nInBufWord = v6;
LABEL_19:
  v13 = v5;
LABEL_20:
  p_m_Memory = &v24->m_ConVars.m_Memory;
  v24 = (NET_SetConVar *)p_m_Memory;
  p_m_Memory[1].m_pMemory = nullptr;
  if ( v13 > 0 )
  {
    for ( buffera = (bf_read *)v13; buffera != nullptr; buffera = (bf_read *)((char *)buffera - 1) )
    {
      CBitRead::ReadString(this: buffer, pStr: cvar.name, maxLen: 260, bLine: false, pOutNumChars: nullptr);
      CBitRead::ReadString(this: buffer, pStr: cvar.value, maxLen: 260, bLine: false, pOutNumChars: nullptr);
      m_pMemory = p_m_Memory[1].m_pMemory;
      m_nAllocationCount = p_m_Memory->m_nAllocationCount;
      if ( (int)&m_pMemory->name[1] > m_nAllocationCount )
        CUtlMemory<CConPanel::CNotifyText,int>::Grow(
          this: p_m_Memory,
          num: (int)&m_pMemory->name[-m_nAllocationCount + 1]);
      ++p_m_Memory[1].m_pMemory;
      v19 = p_m_Memory->m_pMemory;
      v20 = (char *)p_m_Memory[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_Memory[1].m_nAllocationCount = (int)p_m_Memory->m_pMemory->name;
      if ( v20 > 0 )
        _V_memmove(dest: &v19[(int)m_pMemory + 1], src: &v19[(_DWORD)m_pMemory], count: 520 * v20);
      v21 = &p_m_Memory->m_pMemory[(_DWORD)m_pMemory];
      if ( v21 != nullptr )
      {
        *v21 = cvar;
        p_m_Memory = (CUtlMemory<NetMessageCvar_t,int> *)v24;
      }
    }
  }
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101C1D90
// Name: public: virtual bool NET_SignonState::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NET_SignonState::ReadFromBuffer(NET_SignonState *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  unsigned int v4; // edi
  int v5; // ebx
  unsigned int v6; // edi
  const unsigned int *v7; // eax
  const unsigned int *v8; // ecx
  const unsigned int *m_pBufferEnd; // edi
  unsigned int m_nInBufWord; // ebx
  int v11; // eax
  const unsigned int *m_pDataIn; // ecx
  int v13; // eax
  unsigned int v14; // edi
  unsigned int v15; // edx
  int v16; // ecx
  int v17; // eax
  int v18; // ecx
  const unsigned int *v19; // ecx
  const unsigned int *v20; // edi
  const unsigned int *v21; // edi
  unsigned int v22; // ebx
  int v23; // eax
  const unsigned int *v24; // ecx
  unsigned int v25; // edi
  unsigned int v26; // edx
  unsigned int v27; // edi
  int v28; // ecx
  int v29; // eax
  int v30; // ecx
  const unsigned int *v31; // ecx
  const unsigned int *v32; // edi
  const unsigned int *v33; // edi
  unsigned int v34; // ebx
  int v35; // eax
  const unsigned int *v36; // ecx
  unsigned int v37; // edi
  unsigned int v38; // edx
  unsigned int v39; // edi
  int v40; // ecx
  unsigned int v41; // eax
  int v42; // ecx
  int v43; // edi
  const unsigned int *v44; // ecx
  const unsigned int *v45; // ebx
  const unsigned int *v46; // edi
  unsigned int v47; // ebx
  int v48; // eax
  const unsigned int *v49; // ecx
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v52; // eax
  int v53; // ecx
  unsigned int v54; // eax
  int v55; // ecx
  const unsigned int *v56; // ecx
  const unsigned int *v57; // ebx
  int v58; // edi
  unsigned int v59; // edi
  unsigned int v60; // edx
  int v61; // ebx
  const unsigned int *v63; // edi
  unsigned int v64; // ebx
  int v65; // eax
  const unsigned int *v66; // ecx
  unsigned int v67; // edi
  unsigned int v68; // edx

  m_nBitsAvail = buffer->m_nBitsAvail;
  v3 = 0;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v11 = 8 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_15:
        if ( buffer->m_bOverflow )
        {
          v13 = 0;
          goto LABEL_20;
        }
        v14 = buffer->m_nInBufWord;
        v15 = (v14 & CBitBuffer::s_nMaskTable[v11]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v11;
        v5 = v15 | m_nInBufWord;
        v6 = v14 >> v11;
        v3 = 0;
        goto LABEL_18;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v4 = buffer->m_nInBufWord;
  v5 = (unsigned __int8)v4;
  buffer->m_nBitsAvail = m_nBitsAvail - 8;
  if ( m_nBitsAvail == 8 )
  {
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v7 + 1;
    }
    else if ( v7 <= v8 )
    {
      buffer->m_nInBufWord = *v7;
      buffer->m_pDataIn = v7 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
    goto LABEL_19;
  }
  v6 = v4 >> 8;
LABEL_18:
  buffer->m_nInBufWord = v6;
LABEL_19:
  v13 = v5;
LABEL_20:
  this->m_nSignonState = v13;
  v16 = buffer->m_nBitsAvail;
  if ( v16 >= 32 )
  {
    v17 = buffer->m_nInBufWord;
    v18 = v16 - 32;
    buffer->m_nBitsAvail = v18;
    if ( v18 != 0 )
    {
      buffer->m_nInBufWord = 0;
    }
    else
    {
      v19 = buffer->m_pDataIn;
      v20 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v19 == v20 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v19 + 1;
      }
      else if ( v19 <= v20 )
      {
        buffer->m_nInBufWord = *v19;
        buffer->m_pDataIn = v19 + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
    }
    goto LABEL_37;
  }
  v21 = buffer->m_pBufferEnd;
  v22 = buffer->m_nInBufWord;
  v23 = 32 - v16;
  v24 = buffer->m_pDataIn;
  if ( v24 == v21 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v24 > v21 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_34;
    }
    buffer->m_nInBufWord = *v24;
  }
  buffer->m_pDataIn = v24 + 1;
LABEL_34:
  if ( buffer->m_bOverflow )
  {
    v17 = 0;
  }
  else
  {
    v25 = buffer->m_nInBufWord;
    v26 = (v25 & CBitBuffer::s_nMaskTable[v23]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v23;
    v27 = v25 >> v23;
    v17 = v26 | v22;
    v3 = 0;
    buffer->m_nInBufWord = v27;
  }
LABEL_37:
  this->m_nSpawnCount = v17;
  v28 = buffer->m_nBitsAvail;
  if ( v28 >= 32 )
  {
    v29 = buffer->m_nInBufWord;
    v30 = v28 - 32;
    buffer->m_nBitsAvail = v30;
    if ( v30 != 0 )
    {
      buffer->m_nInBufWord = 0;
    }
    else
    {
      v31 = buffer->m_pDataIn;
      v32 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v31 == v32 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v31 + 1;
      }
      else if ( v31 <= v32 )
      {
        buffer->m_nInBufWord = *v31;
        buffer->m_pDataIn = v31 + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
    }
    goto LABEL_54;
  }
  v33 = buffer->m_pBufferEnd;
  v34 = buffer->m_nInBufWord;
  v35 = 32 - v28;
  v36 = buffer->m_pDataIn;
  if ( v36 == v33 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v36 > v33 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_51;
    }
    buffer->m_nInBufWord = *v36;
  }
  buffer->m_pDataIn = v36 + 1;
LABEL_51:
  if ( buffer->m_bOverflow )
  {
    v29 = 0;
  }
  else
  {
    v37 = buffer->m_nInBufWord;
    v38 = (v37 & CBitBuffer::s_nMaskTable[v35]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v35;
    v39 = v37 >> v35;
    v29 = v38 | v34;
    v3 = 0;
    buffer->m_nInBufWord = v39;
  }
LABEL_54:
  this->m_numServerPlayers = v29;
  v40 = buffer->m_nBitsAvail;
  if ( v40 >= 32 )
  {
    v41 = buffer->m_nInBufWord;
    v42 = v40 - 32;
    buffer->m_nBitsAvail = v42;
    if ( v42 != 0 )
    {
      buffer->m_nInBufWord = 0;
      v43 = v41;
    }
    else
    {
      v44 = buffer->m_pDataIn;
      v45 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v44 == v45 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v44 + 1;
        v43 = v41;
      }
      else
      {
        if ( v44 <= v45 )
        {
          buffer->m_nInBufWord = *v44;
          buffer->m_pDataIn = v44 + 1;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v43 = v41;
      }
    }
    goto LABEL_84;
  }
  v46 = buffer->m_pBufferEnd;
  v47 = buffer->m_nInBufWord;
  v48 = 32 - v40;
  v49 = buffer->m_pDataIn;
  if ( v49 == v46 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_68:
    buffer->m_pDataIn = v49 + 1;
    goto LABEL_69;
  }
  if ( v49 <= v46 )
  {
    buffer->m_nInBufWord = *v49;
    goto LABEL_68;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_69:
  if ( buffer->m_bOverflow )
  {
    v43 = 0;
    goto LABEL_71;
  }
  v59 = buffer->m_nInBufWord;
  v60 = (v59 & CBitBuffer::s_nMaskTable[v48]) << buffer->m_nBitsAvail;
  buffer->m_nBitsAvail = 32 - v48;
  v61 = v60 | v47;
  v3 = 0;
  buffer->m_nInBufWord = v59 >> v48;
  v43 = v61;
LABEL_84:
  if ( v43 > 4160 )
    return false;
LABEL_71:
  this->m_PlayersNetworkIds.m_Size = 0;
  if ( v43 == 0 )
    goto LABEL_79;
  m_nAllocationCount = this->m_PlayersNetworkIds.m_Memory.m_nAllocationCount;
  if ( v43 > m_nAllocationCount )
  {
    CUtlMemory<bool,int>::Grow(this: &this->m_PlayersNetworkIds.m_Memory, num: v43 - m_nAllocationCount);
    v3 = 0;
  }
  this->m_PlayersNetworkIds.m_Size += v43;
  m_pMemory = this->m_PlayersNetworkIds.m_Memory.m_pMemory;
  v52 = this->m_PlayersNetworkIds.m_Size - v43;
  this->m_PlayersNetworkIds.m_pElements = m_pMemory;
  if ( v52 > 0 )
  {
    if ( v43 <= 0 )
      goto LABEL_79;
    _V_memmove(dest: &m_pMemory[v43], src: m_pMemory, count: v52);
    v3 = 0;
  }
  if ( v43 > 0 )
  {
    CBitRead::ReadBytes(this: buffer, pOut: this->m_PlayersNetworkIds.m_Memory.m_pMemory, nBytes: v43);
    v3 = 0;
  }
LABEL_79:
  v53 = buffer->m_nBitsAvail;
  if ( v53 < 32 )
  {
    v63 = buffer->m_pBufferEnd;
    v64 = buffer->m_nInBufWord;
    v65 = 32 - v53;
    v66 = buffer->m_pDataIn;
    if ( v66 == v63 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v66 > v63 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_96:
        if ( buffer->m_bOverflow )
        {
          v58 = 0;
          goto LABEL_100;
        }
        v67 = buffer->m_nInBufWord;
        v68 = (v67 & CBitBuffer::s_nMaskTable[v65]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v65;
        buffer->m_nInBufWord = v67 >> v65;
        v58 = v68 | v64;
        goto LABEL_99;
      }
      buffer->m_nInBufWord = *v66;
    }
    buffer->m_pDataIn = v66 + 1;
    goto LABEL_96;
  }
  v54 = buffer->m_nInBufWord;
  v55 = v53 - 32;
  buffer->m_nBitsAvail = v55;
  if ( v55 == 0 )
  {
    v56 = buffer->m_pDataIn;
    v57 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v56 == v57 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_pDataIn = v56 + 1;
      buffer->m_nInBufWord = 0;
      v58 = v54;
      goto LABEL_99;
    }
    if ( v56 > v57 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      v58 = v54;
      goto LABEL_99;
    }
    v3 = *v56;
    buffer->m_pDataIn = v56 + 1;
  }
  buffer->m_nInBufWord = v3;
  v58 = v54;
LABEL_99:
  if ( v58 > 32 )
    return false;
LABEL_100:
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(this: &this->m_Mapname, count: v58);
  if ( v58 > 0 )
    CBitRead::ReadBytes(this: buffer, pOut: this->m_Mapname.m_Memory.m_pMemory, nBytes: v58);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101C2270
// Name: public: virtual bool SVC_ClassInfo::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_ClassInfo::ReadFromBuffer(SVC_ClassInfo *this, bf_read *buffer)
{
  SVC_ClassInfo *v3; // edi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  __int16 v6; // dx
  int v7; // ecx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  const unsigned int *v10; // edx
  unsigned int v11; // ebx
  int v12; // eax
  const unsigned int *v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // edi
  __int16 v16; // bx
  signed int v18; // ebx
  unsigned int v19; // eax
  int v20; // ecx
  bool v21; // zf
  const unsigned int *v22; // eax
  const unsigned int *v23; // edx
  int v24; // ecx
  unsigned int v25; // eax
  unsigned int v26; // edx
  int v27; // ecx
  int v28; // eax
  const unsigned int *v29; // eax
  const unsigned int *v30; // ecx
  unsigned int v31; // ecx
  const unsigned int *v32; // edx
  unsigned int v33; // edi
  int v34; // eax
  const unsigned int *v35; // ecx
  unsigned int v36; // edx
  unsigned int v37; // ebx
  int v38; // edi
  unsigned int v39; // edx
  SVC_ClassInfo::class_s serverclass; // [esp+Ch] [ebp-20Ch] BYREF
  int nServerClassBits; // [esp+210h] [ebp-8h]
  SVC_ClassInfo *v42; // [esp+214h] [ebp-4h]
  int i; // [esp+220h] [ebp+8h]

  v3 = this;
  this->m_Classes.m_Size = 0;
  m_nBitsAvail = buffer->m_nBitsAvail;
  v42 = v3;
  if ( m_nBitsAvail >= 16 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v6 = m_nInBufWord;
    v7 = m_nBitsAvail - 16;
    buffer->m_nBitsAvail = v7;
    if ( v7 != 0 )
    {
      buffer->m_nInBufWord = HIWORD(m_nInBufWord);
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        buffer->m_nInBufWord = *m_pDataIn;
        buffer->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
    }
    goto LABEL_18;
  }
  v10 = buffer->m_pBufferEnd;
  v11 = buffer->m_nInBufWord;
  v12 = 16 - m_nBitsAvail;
  v13 = buffer->m_pDataIn;
  if ( v13 == v10 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v13 > v10 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_15;
    }
    buffer->m_nInBufWord = *v13;
  }
  buffer->m_pDataIn = v13 + 1;
LABEL_15:
  if ( buffer->m_bOverflow )
  {
    v6 = 0;
  }
  else
  {
    v14 = buffer->m_nInBufWord;
    v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v12;
    v16 = v15 | v11;
    v3 = v42;
    buffer->m_nInBufWord = v14 >> v12;
    v6 = v16;
  }
LABEL_18:
  v3->m_nNumServerClasses = v6;
  if ( v6 <= 0 )
  {
    _Warning(a1: "SVC_ClassInfo::ReadFromBuffer:  bad numserverclasses %d\n", v6);
    return false;
  }
  v18 = Q_log2(val: v6) + 1;
  v19 = buffer->m_nInBufWord;
  v20 = v19 & 1;
  v21 = buffer->m_nBitsAvail-- == 1;
  nServerClassBits = v18;
  if ( v21 )
  {
    v22 = buffer->m_pDataIn;
    v23 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v22 == v23 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v22 + 1;
    }
    else if ( v22 <= v23 )
    {
      buffer->m_nInBufWord = *v22;
      buffer->m_pDataIn = v22 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v19 >> 1;
  }
  v3->m_bCreateOnClient = v20 != 0;
  if ( v20 == 0 )
  {
    i = 0;
    if ( v3->m_nNumServerClasses > 0 )
    {
      while ( 1 )
      {
        v24 = buffer->m_nBitsAvail;
        if ( v24 < v18 )
          break;
        v25 = buffer->m_nInBufWord;
        v26 = v25 & CBitBuffer::s_nMaskTable[v18];
        v27 = v24 - v18;
        buffer->m_nBitsAvail = v27;
        if ( v27 != 0 )
        {
          buffer->m_nInBufWord = v25 >> v18;
          v28 = v26;
        }
        else
        {
          v29 = buffer->m_pDataIn;
          v30 = buffer->m_pBufferEnd;
          buffer->m_nBitsAvail = 32;
          if ( v29 == v30 )
          {
            buffer->m_pDataIn = v29 + 1;
            buffer->m_nBitsAvail = 1;
            buffer->m_nInBufWord = 0;
            v28 = v26;
          }
          else
          {
            if ( v29 <= v30 )
            {
              v31 = *v29;
              buffer->m_pDataIn = v29 + 1;
              buffer->m_nInBufWord = v31;
            }
            else
            {
              buffer->m_bOverflow = true;
              buffer->m_nInBufWord = 0;
            }
            v28 = v26;
          }
        }
LABEL_48:
        serverclass.classID = v28;
        CBitRead::ReadString(
          this: buffer,
          pStr: serverclass.classname,
          maxLen: 256,
          bLine: false,
          pOutNumChars: nullptr);
        CBitRead::ReadString(
          this: buffer,
          pStr: serverclass.datatablename,
          maxLen: 256,
          bLine: false,
          pOutNumChars: nullptr);
        CUtlVector<SVC_ClassInfo::class_s,CUtlMemory<SVC_ClassInfo::class_s,int>>::InsertBefore(
          this: &v3->m_Classes,
          elem: v3->m_Classes.m_Size,
          src: &serverclass);
        if ( ++i >= v3->m_nNumServerClasses )
          return !buffer->m_bOverflow;
      }
      v32 = buffer->m_pBufferEnd;
      v33 = buffer->m_nInBufWord;
      v34 = v18 - v24;
      v35 = buffer->m_pDataIn;
      if ( v35 == v32 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_bOverflow = true;
      }
      else
      {
        if ( v35 > v32 )
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
LABEL_44:
          if ( buffer->m_bOverflow )
          {
            v28 = 0;
          }
          else
          {
            v36 = buffer->m_nInBufWord;
            v37 = (v36 & CBitBuffer::s_nMaskTable[v34]) << buffer->m_nBitsAvail;
            buffer->m_nBitsAvail = 32 - v34;
            v38 = v37 | v33;
            v18 = nServerClassBits;
            v39 = v36 >> v34;
            v28 = v38;
            buffer->m_nInBufWord = v39;
          }
          v3 = v42;
          goto LABEL_48;
        }
        buffer->m_nInBufWord = *v35;
      }
      buffer->m_pDataIn = v35 + 1;
      goto LABEL_44;
    }
  }
  return !buffer->m_bOverflow;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1004B500
// Name: public: virtual int SVC_CmdKeyValues::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SVC_CmdKeyValues::GetType(CSosOperatorDelta *this)
{
  return 32;
}

//------------------------------------------------------------------------------
// Address: 0x1005E2D0
// Name: public: virtual int CLC_CmdKeyValues::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLC_CmdKeyValues::GetType(SVC_SetView *this)
{
  return 18;
}

//------------------------------------------------------------------------------
// Address: 0x10061140
// Name: public: virtual bool SVC_CreateStringTable::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_CreateStringTable::Process(CLC_RespondCvarValue *this)
{
  return this->m_pMessageHandler->ProcessRespondCvarValue(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x101BA680
// Name: public: virtual char const __near * CLC_VoiceData::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLC_VoiceData::ToString(CLC_VoiceData *this)
{
  const char *v1; // eax
  int v3; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(CLC_VoiceData *, int))this->GetName)(a1: this, a2: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: %i bytes", v1, v3);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BA6B0
// Name: public: virtual bool CLC_VoiceData::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_VoiceData::WriteToBuffer(CLC_VoiceData *this, bf_write *buffer)
{
  unsigned int v3; // eax
  int m_iCurBit; // [esp-4h] [ebp-Ch]

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_iCurBit = this->m_DataOut.m_iCurBit;
  this->m_nLength = m_iCurBit;
  bf_write::WriteWord(this: buffer, val: m_iCurBit);
  bf_write::WriteLongLong(this: buffer, val: this->m_xuid);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BA700
// Name: public: virtual char const __near * CLC_Move::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLC_Move::ToString(CLC_Move *this)
{
  const char *v1; // eax
  int v3; // [esp-Ch] [ebp-Ch]
  int v4; // [esp-8h] [ebp-8h]
  int v5; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(CLC_Move *, int, int, int))this->GetName)(
                       a1: this,
                       a2: this->m_nBackupCommands,
                       a3: this->m_nNewCommands,
                       a4: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: backup %i, new %i, bytes %i", v1, v3, v4, v5);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BA740
// Name: public: virtual bool CLC_Move::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_Move::WriteToBuffer(CLC_Move *this, bf_write *buffer)
{
  unsigned int v3; // eax
  unsigned int m_nNewCommands; // [esp-Ch] [ebp-14h]

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_nNewCommands = this->m_nNewCommands;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  bf_write::WriteUBitLong(this: buffer, curData: m_nNewCommands, numbits: 4, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nBackupCommands, numbits: 3, bCheckRange: true);
  bf_write::WriteWord(this: buffer, val: this->m_nLength);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BA7B0
// Name: public: virtual char const __near * CLC_ClientInfo::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLC_ClientInfo::ToString(CLC_ClientInfo *this)
{
  const char *v1; // eax
  int v3; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(CLC_ClientInfo *, unsigned int))this->GetName)(
                       a1: this,
                       a2: this->m_nSendTableCRC);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: SendTableCRC %lu", v1, v3);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BAC70
// Name: public: virtual char const __near * CLC_LoadingProgress::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLC_LoadingProgress::ToString(CLC_LoadingProgress *this)
{
  const char *v1; // eax
  int v3; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(CLC_LoadingProgress *, int))this->GetName)(a1: this, a2: this->m_nProgress);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: LoadingProgress %i", v1, v3);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BACA0
// Name: public: virtual bool CLC_LoadingProgress::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLC_LoadingProgress::WriteToBuffer(CLC_LoadingProgress *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteByte(this: buffer, val: this->m_nProgress);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BACE0
// Name: public: virtual bool CLC_LoadingProgress::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_LoadingProgress::ReadFromBuffer(CLC_LoadingProgress *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // ecx
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  unsigned int v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v12 = 8 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_16;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( buffer->m_bOverflow )
    {
      v6 = 0;
    }
    else
    {
      v14 = buffer->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v12;
      v6 = v15 | m_nInBufWord;
      buffer->m_nInBufWord = v14 >> v12;
    }
    goto LABEL_19;
  }
  v3 = buffer->m_nInBufWord;
  v4 = (unsigned __int8)v3;
  v5 = m_nBitsAvail - 8;
  buffer->m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    buffer->m_nInBufWord = v3 >> 8;
    v6 = (unsigned __int8)v3;
  }
  else
  {
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      buffer->m_pDataIn = v7 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v6 = v4;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v9 = *v7;
        buffer->m_pDataIn = v7 + 1;
        buffer->m_nInBufWord = v9;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v6 = v4;
    }
  }
LABEL_19:
  this->m_nProgress = v6;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BADF0
// Name: public: virtual bool CLC_BaselineAck::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLC_BaselineAck::WriteToBuffer(CLC_BaselineAck *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteLong(this: buffer, val: this->m_nBaselineTick);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nBaselineNr, numbits: 1, bCheckRange: true);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BB020
// Name: public: virtual char const __near * CLC_BaselineAck::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLC_BaselineAck::ToString(NET_Tick *this)
{
  const char *v1; // eax
  int v3; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(NET_Tick *, int))this->GetName)(a1: this, a2: this->m_nTick);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: tick %i", v1, v3);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BB050
// Name: public: virtual bool CLC_RespondCvarValue::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLC_RespondCvarValue::WriteToBuffer(CLC_RespondCvarValue *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteSBitLong(this: buffer, data: this->m_iCookie, numbits: 32);
  bf_write::WriteSBitLong(this: buffer, data: this->m_eStatusCode, numbits: 4);
  bf_write::WriteString(this: buffer, pStr: this->m_szCvarName);
  bf_write::WriteString(this: buffer, pStr: this->m_szCvarValue);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BB0B0
// Name: public: virtual bool CLC_RespondCvarValue::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLC_RespondCvarValue::ReadFromBuffer(CLC_RespondCvarValue *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v5; // ecx
  unsigned int v6; // edi
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  const unsigned int *v9; // edx
  unsigned int v10; // edi
  int v11; // eax
  const unsigned int *v12; // ecx
  unsigned int v13; // edx
  unsigned int v14; // ebx
  int v15; // edi
  unsigned int v16; // edx
  int v17; // ecx
  unsigned int v18; // edx
  int v19; // eax
  int v20; // ecx
  const unsigned int *v21; // ecx
  const unsigned int *v22; // edx
  unsigned int v23; // edx
  const unsigned int *v24; // edi
  unsigned int v25; // eax
  int v26; // edx
  const unsigned int *v27; // ecx
  unsigned int v28; // edi
  unsigned int v29; // ebx
  CLC_RespondCvarValue *v31; // [esp+Ch] [ebp-4h]

  m_nBitsAvail = buffer->m_nBitsAvail;
  v31 = this;
  if ( m_nBitsAvail >= 32 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v5 = m_nBitsAvail - 32;
    v6 = 0;
    buffer->m_nBitsAvail = v5;
    if ( v5 != 0 )
    {
      buffer->m_nInBufWord = 0;
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        buffer->m_nInBufWord = *m_pDataIn;
        buffer->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
    }
    goto LABEL_19;
  }
  v9 = buffer->m_pBufferEnd;
  v10 = buffer->m_nInBufWord;
  v11 = 32 - m_nBitsAvail;
  v12 = buffer->m_pDataIn;
  if ( v12 == v9 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_14:
    buffer->m_pDataIn = v12 + 1;
    goto LABEL_15;
  }
  if ( v12 <= v9 )
  {
    buffer->m_nInBufWord = *v12;
    goto LABEL_14;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_15:
  if ( buffer->m_bOverflow )
  {
    m_nInBufWord = 0;
  }
  else
  {
    v13 = buffer->m_nInBufWord;
    v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v11;
    v15 = v14 | v10;
    this = v31;
    v16 = v13 >> v11;
    m_nInBufWord = v15;
    buffer->m_nInBufWord = v16;
  }
  v6 = 0;
LABEL_19:
  this->m_iCookie = m_nInBufWord;
  v17 = buffer->m_nBitsAvail;
  if ( v17 < 4 )
  {
    v24 = buffer->m_pBufferEnd;
    v25 = buffer->m_nInBufWord;
    v26 = 4 - v17;
    v27 = buffer->m_pDataIn;
    if ( v27 == v24 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v27 > v24 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_33:
        if ( buffer->m_bOverflow )
        {
          v19 = 0;
          goto LABEL_37;
        }
        v28 = buffer->m_nInBufWord;
        v29 = (v28 & CBitBuffer::s_nMaskTable[v26]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v26;
        v19 = v29 | v25;
        this = v31;
        v6 = v28 >> v26;
        goto LABEL_36;
      }
      buffer->m_nInBufWord = *v27;
    }
    buffer->m_pDataIn = v27 + 1;
    goto LABEL_33;
  }
  v18 = buffer->m_nInBufWord;
  v19 = v18 & 0xF;
  v20 = v17 - 4;
  buffer->m_nBitsAvail = v20;
  if ( v20 == 0 )
  {
    v21 = buffer->m_pDataIn;
    v22 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v21 == v22 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_pDataIn = v21 + 1;
    }
    else
    {
      if ( v21 <= v22 )
      {
        v23 = *v21;
        buffer->m_pDataIn = v21 + 1;
        buffer->m_nInBufWord = v23;
        goto LABEL_37;
      }
      buffer->m_bOverflow = true;
    }
LABEL_36:
    buffer->m_nInBufWord = v6;
    goto LABEL_37;
  }
  buffer->m_nInBufWord = v18 >> 4;
LABEL_37:
  this->m_eStatusCode = v19 << 28 >> 28;
  CBitRead::ReadString(this: buffer, pStr: this->m_szCvarNameBuffer, maxLen: 256, bLine: false, pOutNumChars: nullptr);
  this->m_szCvarName = this->m_szCvarNameBuffer;
  CBitRead::ReadString(this: buffer, pStr: this->m_szCvarValueBuffer, maxLen: 256, bLine: false, pOutNumChars: nullptr);
  this->m_szCvarValue = this->m_szCvarValueBuffer;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BB6E0
// Name: public: virtual char const __near * CLC_FileCRCCheck::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLC_FileCRCCheck::ToString(CLC_FileCRCCheck *this)
{
  const char *v1; // eax
  const char *v3; // [esp-8h] [ebp-8h]
  const char *v4; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(CLC_FileCRCCheck *, char *, char *))this->GetName)(
                       a1: this,
                       a2: this->m_szPathID,
                       a3: this->m_szFilename);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: path: %s, file: %s", v1, v3, v4);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BB710
// Name: protected: virtual Base_CmdKeyValues::~Base_CmdKeyValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Base_CmdKeyValues::~Base_CmdKeyValues(Base_CmdKeyValues *this)
{
  KeyValues *m_pKeyValues; // ecx

  m_pKeyValues = this->m_pKeyValues;
  this->__vftable = (Base_CmdKeyValues_vtbl *)&Base_CmdKeyValues::`vftable';
  if ( m_pKeyValues != nullptr )
    KeyValues::deleteThis(this: m_pKeyValues);
  this->__vftable = (Base_CmdKeyValues_vtbl *)&INetMessage::`vftable';
  this->m_pKeyValues = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101BB740
// Name: public: virtual char const __near * SVC_CmdKeyValues::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_CmdKeyValues::ToString(SVC_CmdKeyValues *this)
{
  KeyValues *m_pKeyValues; // ecx
  const char *Name; // eax
  const char *v4; // eax
  const char *v6; // [esp-4h] [ebp-8h]

  m_pKeyValues = this->m_pKeyValues;
  if ( m_pKeyValues != nullptr )
    Name = KeyValues::GetName(this: m_pKeyValues);
  else
    Name = "<<null>>";
  v4 = (const char *)((int (__thiscall *)(SVC_CmdKeyValues *, const char *))this->GetName)(a1: this, a2: Name);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: %s", v4, v6);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BB780
// Name: public: virtual bool SVC_Print::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_Print::WriteToBuffer(SVC_Print *this, bf_write *buffer)
{
  unsigned int v3; // eax
  const char *m_szText; // esi

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_szText = this->m_szText;
  if ( m_szText == nullptr )
    m_szText = " svc_print NULL";
  return bf_write::WriteString(this: buffer, pStr: m_szText);
}

//------------------------------------------------------------------------------
// Address: 0x101BB7C0
// Name: public: virtual bool SVC_Print::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_Print::ReadFromBuffer(SVC_Print *this, bf_read *buffer)
{
  this->m_szText = this->m_szTextBuffer;
  return CBitRead::ReadString(
           this: buffer,
           pStr: this->m_szTextBuffer,
           maxLen: 2048,
           bLine: false,
           pOutNumChars: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101BB7E0
// Name: public: virtual char const __near * SVC_Print::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_Print::ToString(NET_StringCmd *this)
{
  const char *v1; // eax
  const char *v3; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(NET_StringCmd *, const char *))this->GetName)(a1: this, a2: this->m_szCommand);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: \"%s\"", v1, v3);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BB810
// Name: public: virtual bool NET_StringCmd::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NET_StringCmd::WriteToBuffer(NET_StringCmd *this, bf_write *buffer)
{
  unsigned int v3; // eax
  const char *m_szCommand; // esi

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_szCommand = this->m_szCommand;
  if ( m_szCommand == nullptr )
    m_szCommand = " NET_StringCmd NULL";
  return bf_write::WriteString(this: buffer, pStr: m_szCommand);
}

//------------------------------------------------------------------------------
// Address: 0x101BB850
// Name: public: virtual bool NET_StringCmd::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NET_StringCmd::ReadFromBuffer(NET_StringCmd *this, bf_read *buffer)
{
  this->m_szCommand = this->m_szCommandBuffer;
  return CBitRead::ReadString(
           this: buffer,
           pStr: this->m_szCommandBuffer,
           maxLen: 1024,
           bLine: false,
           pOutNumChars: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101BB870
// Name: public: virtual bool SVC_ServerInfo::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_ServerInfo::ReadFromBuffer(SVC_ServerInfo *this, bf_read *buffer)
{
  char *m_szHostNameBuffer; // eax
  int m_nBitsAvail; // ecx
  unsigned int v5; // edx
  __int16 v6; // di
  unsigned int v7; // edx
  const unsigned int *v8; // eax
  const unsigned int *v9; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v12; // eax
  const unsigned int *m_pDataIn; // ecx
  __int16 v14; // ax
  unsigned int v15; // edx
  unsigned int v16; // ebx
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  const unsigned int *v20; // ecx
  const unsigned int *v21; // edx
  const unsigned int *v22; // edx
  unsigned int v23; // edi
  int v24; // eax
  const unsigned int *v25; // ecx
  unsigned int v26; // edx
  unsigned int v27; // ebx
  unsigned int v28; // edx
  unsigned int v29; // ecx
  int v30; // eax
  bool v31; // zf
  const unsigned int *v32; // ecx
  const unsigned int *v33; // edx
  unsigned int v34; // eax
  int v35; // ecx
  const unsigned int *v36; // eax
  const unsigned int *v37; // edx
  int v38; // ecx
  unsigned int v39; // eax
  int v40; // ecx
  const unsigned int *v41; // ecx
  const unsigned int *v42; // edx
  const unsigned int *v43; // edx
  unsigned int v44; // edi
  int v45; // eax
  const unsigned int *v46; // ecx
  unsigned int v47; // edx
  unsigned int v48; // ebx
  unsigned int v49; // edx
  int v50; // ecx
  unsigned int v51; // eax
  int v52; // ecx
  const unsigned int *v53; // ecx
  const unsigned int *v54; // edx
  const unsigned int *v55; // edx
  unsigned int v56; // edi
  int v57; // eax
  const unsigned int *v58; // ecx
  unsigned int v59; // edx
  unsigned int v60; // ebx
  unsigned int v61; // edx
  int v62; // ecx
  unsigned int v63; // eax
  unsigned int v64; // edx
  int v65; // ecx
  const unsigned int *v66; // eax
  const unsigned int *v67; // ecx
  unsigned int v68; // ecx
  const unsigned int *v69; // edx
  unsigned int v70; // edi
  int v71; // eax
  const unsigned int *v72; // ecx
  unsigned int v73; // edx
  unsigned int v74; // ebx
  unsigned int v75; // edx
  int v76; // ecx
  unsigned int v77; // eax
  int v78; // ecx
  const unsigned int *v79; // ecx
  const unsigned int *v80; // edx
  const unsigned int *v81; // edx
  unsigned int v82; // edi
  int v83; // eax
  const unsigned int *v84; // ecx
  unsigned int v85; // edx
  unsigned int v86; // ebx
  unsigned int v87; // edx
  int v88; // ecx
  unsigned int v89; // eax
  unsigned int v90; // edx
  int v91; // ecx
  const unsigned int *v92; // eax
  const unsigned int *v93; // ecx
  unsigned int v94; // ecx
  const unsigned int *v95; // edx
  unsigned int v96; // edi
  int v97; // eax
  const unsigned int *v98; // ecx
  unsigned int v99; // edx
  unsigned int v100; // ebx
  unsigned int v101; // edx
  int v102; // ecx
  unsigned int v103; // eax
  unsigned int v104; // edx
  int v105; // ecx
  const unsigned int *v106; // eax
  const unsigned int *v107; // ecx
  unsigned int v108; // ecx
  const unsigned int *v109; // edx
  unsigned int v110; // edi
  int v111; // eax
  const unsigned int *v112; // ecx
  unsigned int v113; // edx
  unsigned int v114; // ebx
  unsigned int v115; // edx
  int v116; // ecx
  unsigned int v117; // eax
  int v118; // ecx
  const unsigned int *v119; // ecx
  const unsigned int *v120; // edx
  const unsigned int *v121; // edx
  unsigned int v122; // edi
  int v123; // eax
  const unsigned int *v124; // ecx
  unsigned int v125; // edx
  unsigned int v126; // ebx
  int v127; // ecx
  unsigned int v128; // edx
  char v129; // al
  int v130; // ecx
  unsigned int v131; // edx
  const unsigned int *v132; // ecx
  const unsigned int *v133; // edx
  const unsigned int *v134; // edx
  unsigned int v135; // edi
  int v136; // eax
  const unsigned int *v137; // ecx
  unsigned int v138; // edx
  unsigned int v139; // ebx
  char *v141; // [esp+Ch] [ebp-14h]
  char *m_szSkyNameBuffer; // [esp+10h] [ebp-10h]
  char *m_szMapNameBuffer; // [esp+14h] [ebp-Ch]
  char *pStr; // [esp+18h] [ebp-8h]
  bf_read *buffera; // [esp+28h] [ebp+8h]

  this->m_szGameDir = this->m_szGameDirBuffer;
  pStr = this->m_szGameDirBuffer;
  this->m_szMapName = this->m_szMapNameBuffer;
  m_szMapNameBuffer = this->m_szMapNameBuffer;
  this->m_szSkyName = this->m_szSkyNameBuffer;
  m_szSkyNameBuffer = this->m_szSkyNameBuffer;
  m_szHostNameBuffer = this->m_szHostNameBuffer;
  this->m_szHostName = this->m_szHostNameBuffer;
  m_nBitsAvail = buffer->m_nBitsAvail;
  v141 = m_szHostNameBuffer;
  if ( m_nBitsAvail < 16 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v12 = 16 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_15:
        if ( buffer->m_bOverflow )
        {
          v14 = 0;
          goto LABEL_20;
        }
        v15 = buffer->m_nInBufWord;
        v16 = (v15 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v12;
        v6 = v16 | m_nInBufWord;
        v7 = v15 >> v12;
        goto LABEL_18;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v5 = buffer->m_nInBufWord;
  v6 = v5;
  buffer->m_nBitsAvail = m_nBitsAvail - 16;
  if ( m_nBitsAvail == 16 )
  {
    v8 = buffer->m_pDataIn;
    v9 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v8 + 1;
    }
    else if ( v8 <= v9 )
    {
      buffer->m_nInBufWord = *v8;
      buffer->m_pDataIn = v8 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
    goto LABEL_19;
  }
  v7 = HIWORD(v5);
LABEL_18:
  buffer->m_nInBufWord = v7;
LABEL_19:
  v14 = v6;
LABEL_20:
  this->m_nProtocol = v14;
  v17 = buffer->m_nBitsAvail;
  if ( v17 < 32 )
  {
    v22 = buffer->m_pBufferEnd;
    v23 = buffer->m_nInBufWord;
    v24 = 32 - v17;
    v25 = buffer->m_pDataIn;
    if ( v25 == v22 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v25 > v22 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_34;
      }
      buffer->m_nInBufWord = *v25;
    }
    buffer->m_pDataIn = v25 + 1;
LABEL_34:
    if ( buffer->m_bOverflow )
    {
      v18 = 0;
    }
    else
    {
      v26 = buffer->m_nInBufWord;
      v27 = (v26 & CBitBuffer::s_nMaskTable[v24]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v24;
      v28 = v26 >> v24;
      v18 = v27 | v23;
      buffer->m_nInBufWord = v28;
    }
    goto LABEL_37;
  }
  v18 = buffer->m_nInBufWord;
  v19 = v17 - 32;
  buffer->m_nBitsAvail = v19;
  if ( v19 != 0 )
  {
    buffer->m_nInBufWord = 0;
  }
  else
  {
    v20 = buffer->m_pDataIn;
    v21 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v20 == v21 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v20 + 1;
    }
    else if ( v20 <= v21 )
    {
      buffer->m_nInBufWord = *v20;
      buffer->m_pDataIn = v20 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
LABEL_37:
  this->m_nServerCount = v18;
  v29 = buffer->m_nInBufWord;
  v30 = v29 & 1;
  v31 = buffer->m_nBitsAvail-- == 1;
  if ( v31 )
  {
    v32 = buffer->m_pDataIn;
    v33 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v32 == v33 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v32 + 1;
    }
    else if ( v32 <= v33 )
    {
      buffer->m_nInBufWord = *v32;
      buffer->m_pDataIn = v32 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v29 >> 1;
  }
  this->m_bIsHLTV = v30 != 0;
  v34 = buffer->m_nInBufWord;
  v35 = v34 & 1;
  v31 = buffer->m_nBitsAvail-- == 1;
  if ( v31 )
  {
    v36 = buffer->m_pDataIn;
    v37 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v36 == v37 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v36 + 1;
    }
    else if ( v36 <= v37 )
    {
      buffer->m_nInBufWord = *v36;
      buffer->m_pDataIn = v36 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v34 >> 1;
  }
  this->m_bIsDedicated = v35 != 0;
  v38 = buffer->m_nBitsAvail;
  if ( v38 >= 32 )
  {
    v39 = buffer->m_nInBufWord;
    v40 = v38 - 32;
    buffer->m_nBitsAvail = v40;
    if ( v40 != 0 )
    {
      buffer->m_nInBufWord = 0;
    }
    else
    {
      v41 = buffer->m_pDataIn;
      v42 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v41 == v42 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v41 + 1;
      }
      else if ( v41 <= v42 )
      {
        buffer->m_nInBufWord = *v41;
        buffer->m_pDataIn = v41 + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
    }
    goto LABEL_68;
  }
  v43 = buffer->m_pBufferEnd;
  v44 = buffer->m_nInBufWord;
  v45 = 32 - v38;
  v46 = buffer->m_pDataIn;
  if ( v46 == v43 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v46 > v43 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_65;
    }
    buffer->m_nInBufWord = *v46;
  }
  buffer->m_pDataIn = v46 + 1;
LABEL_65:
  if ( buffer->m_bOverflow )
  {
    v39 = 0;
  }
  else
  {
    v47 = buffer->m_nInBufWord;
    v48 = (v47 & CBitBuffer::s_nMaskTable[v45]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v45;
    v49 = v47 >> v45;
    v39 = v48 | v44;
    buffer->m_nInBufWord = v49;
  }
LABEL_68:
  this->m_nClientCRC = v39;
  v50 = buffer->m_nBitsAvail;
  if ( v50 >= 32 )
  {
    v51 = buffer->m_nInBufWord;
    v52 = v50 - 32;
    buffer->m_nBitsAvail = v52;
    if ( v52 != 0 )
    {
      buffer->m_nInBufWord = 0;
    }
    else
    {
      v53 = buffer->m_pDataIn;
      v54 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v53 == v54 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v53 + 1;
      }
      else if ( v53 <= v54 )
      {
        buffer->m_nInBufWord = *v53;
        buffer->m_pDataIn = v53 + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
    }
    goto LABEL_85;
  }
  v55 = buffer->m_pBufferEnd;
  v56 = buffer->m_nInBufWord;
  v57 = 32 - v50;
  v58 = buffer->m_pDataIn;
  if ( v58 == v55 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v58 > v55 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_82;
    }
    buffer->m_nInBufWord = *v58;
  }
  buffer->m_pDataIn = v58 + 1;
LABEL_82:
  if ( buffer->m_bOverflow )
  {
    v51 = 0;
  }
  else
  {
    v59 = buffer->m_nInBufWord;
    v60 = (v59 & CBitBuffer::s_nMaskTable[v57]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v57;
    v61 = v59 >> v57;
    v51 = v60 | v56;
    buffer->m_nInBufWord = v61;
  }
LABEL_85:
  this->m_nStringTableCRC = v51;
  v62 = buffer->m_nBitsAvail;
  if ( v62 < 16 )
  {
    v69 = buffer->m_pBufferEnd;
    v70 = buffer->m_nInBufWord;
    v71 = 16 - v62;
    v72 = buffer->m_pDataIn;
    if ( v72 == v69 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v72 > v69 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_100;
      }
      buffer->m_nInBufWord = *v72;
    }
    buffer->m_pDataIn = v72 + 1;
LABEL_100:
    if ( buffer->m_bOverflow )
    {
      v63 = 0;
    }
    else
    {
      v73 = buffer->m_nInBufWord;
      v74 = (v73 & CBitBuffer::s_nMaskTable[v71]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v71;
      v75 = v73 >> v71;
      v63 = v74 | v70;
      buffer->m_nInBufWord = v75;
    }
    goto LABEL_103;
  }
  v63 = buffer->m_nInBufWord;
  v64 = (unsigned __int16)v63;
  v65 = v62 - 16;
  buffer->m_nBitsAvail = v65;
  if ( v65 != 0 )
  {
    buffer->m_nInBufWord = HIWORD(v63);
    v63 = (unsigned __int16)v63;
  }
  else
  {
    v66 = buffer->m_pDataIn;
    v67 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v66 == v67 )
    {
      buffer->m_pDataIn = v66 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v63 = v64;
    }
    else
    {
      if ( v66 <= v67 )
      {
        v68 = *v66;
        buffer->m_pDataIn = v66 + 1;
        buffer->m_nInBufWord = v68;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v63 = v64;
    }
  }
LABEL_103:
  this->m_nMaxClasses = v63;
  v76 = buffer->m_nBitsAvail;
  if ( v76 >= 32 )
  {
    v77 = buffer->m_nInBufWord;
    v78 = v76 - 32;
    buffer->m_nBitsAvail = v78;
    if ( v78 != 0 )
    {
      buffer->m_nInBufWord = 0;
    }
    else
    {
      v79 = buffer->m_pDataIn;
      v80 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v79 == v80 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v79 + 1;
      }
      else if ( v79 <= v80 )
      {
        buffer->m_nInBufWord = *v79;
        buffer->m_pDataIn = v79 + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
    }
    goto LABEL_120;
  }
  v81 = buffer->m_pBufferEnd;
  v82 = buffer->m_nInBufWord;
  v83 = 32 - v76;
  v84 = buffer->m_pDataIn;
  if ( v84 == v81 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v84 > v81 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_117;
    }
    buffer->m_nInBufWord = *v84;
  }
  buffer->m_pDataIn = v84 + 1;
LABEL_117:
  if ( buffer->m_bOverflow )
  {
    v77 = 0;
  }
  else
  {
    v85 = buffer->m_nInBufWord;
    v86 = (v85 & CBitBuffer::s_nMaskTable[v83]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v83;
    v87 = v85 >> v83;
    v77 = v86 | v82;
    buffer->m_nInBufWord = v87;
  }
LABEL_120:
  this->m_nMapCRC = v77;
  v88 = buffer->m_nBitsAvail;
  if ( v88 < 8 )
  {
    v95 = buffer->m_pBufferEnd;
    v96 = buffer->m_nInBufWord;
    v97 = 8 - v88;
    v98 = buffer->m_pDataIn;
    if ( v98 == v95 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v98 > v95 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_135;
      }
      buffer->m_nInBufWord = *v98;
    }
    buffer->m_pDataIn = v98 + 1;
LABEL_135:
    if ( buffer->m_bOverflow )
    {
      v89 = 0;
    }
    else
    {
      v99 = buffer->m_nInBufWord;
      v100 = (v99 & CBitBuffer::s_nMaskTable[v97]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v97;
      v101 = v99 >> v97;
      v89 = v100 | v96;
      buffer->m_nInBufWord = v101;
    }
    goto LABEL_138;
  }
  v89 = buffer->m_nInBufWord;
  v90 = (unsigned __int8)v89;
  v91 = v88 - 8;
  buffer->m_nBitsAvail = v91;
  if ( v91 != 0 )
  {
    buffer->m_nInBufWord = v89 >> 8;
    v89 = (unsigned __int8)v89;
  }
  else
  {
    v92 = buffer->m_pDataIn;
    v93 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v92 == v93 )
    {
      buffer->m_pDataIn = v92 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v89 = v90;
    }
    else
    {
      if ( v92 <= v93 )
      {
        v94 = *v92;
        buffer->m_pDataIn = v92 + 1;
        buffer->m_nInBufWord = v94;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v89 = v90;
    }
  }
LABEL_138:
  this->m_nPlayerSlot = v89;
  v102 = buffer->m_nBitsAvail;
  if ( v102 < 8 )
  {
    v109 = buffer->m_pBufferEnd;
    v110 = buffer->m_nInBufWord;
    v111 = 8 - v102;
    v112 = buffer->m_pDataIn;
    if ( v112 == v109 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v112 > v109 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_153;
      }
      buffer->m_nInBufWord = *v112;
    }
    buffer->m_pDataIn = v112 + 1;
LABEL_153:
    if ( buffer->m_bOverflow )
    {
      v103 = 0;
    }
    else
    {
      v113 = buffer->m_nInBufWord;
      v114 = (v113 & CBitBuffer::s_nMaskTable[v111]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v111;
      v115 = v113 >> v111;
      v103 = v114 | v110;
      buffer->m_nInBufWord = v115;
    }
    goto LABEL_156;
  }
  v103 = buffer->m_nInBufWord;
  v104 = (unsigned __int8)v103;
  v105 = v102 - 8;
  buffer->m_nBitsAvail = v105;
  if ( v105 != 0 )
  {
    buffer->m_nInBufWord = v103 >> 8;
    v103 = (unsigned __int8)v103;
  }
  else
  {
    v106 = buffer->m_pDataIn;
    v107 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v106 == v107 )
    {
      buffer->m_pDataIn = v106 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v103 = v104;
    }
    else
    {
      if ( v106 <= v107 )
      {
        v108 = *v106;
        buffer->m_pDataIn = v106 + 1;
        buffer->m_nInBufWord = v108;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v103 = v104;
    }
  }
LABEL_156:
  this->m_nMaxClients = v103;
  v116 = buffer->m_nBitsAvail;
  if ( v116 < 32 )
  {
    v121 = buffer->m_pBufferEnd;
    v122 = buffer->m_nInBufWord;
    v123 = 32 - v116;
    v124 = buffer->m_pDataIn;
    if ( v124 == v121 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v124 > v121 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_171;
      }
      buffer->m_nInBufWord = *v124;
    }
    buffer->m_pDataIn = v124 + 1;
LABEL_171:
    if ( buffer->m_bOverflow )
    {
      buffera = nullptr;
    }
    else
    {
      v125 = buffer->m_nInBufWord;
      v126 = (v125 & CBitBuffer::s_nMaskTable[v123]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v123;
      buffera = (bf_read *)(v126 | v122);
      buffer->m_nInBufWord = v125 >> v123;
    }
    goto LABEL_174;
  }
  v117 = buffer->m_nInBufWord;
  v118 = v116 - 32;
  buffer->m_nBitsAvail = v118;
  if ( v118 != 0 )
  {
    buffer->m_nInBufWord = 0;
    buffera = (bf_read *)v117;
  }
  else
  {
    v119 = buffer->m_pDataIn;
    v120 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v119 == v120 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v119 + 1;
      buffera = (bf_read *)v117;
    }
    else
    {
      if ( v119 <= v120 )
      {
        buffer->m_nInBufWord = *v119;
        buffer->m_pDataIn = v119 + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      buffera = (bf_read *)v117;
    }
  }
LABEL_174:
  LODWORD(this->m_fTickInterval) = buffera;
  v127 = buffer->m_nBitsAvail;
  if ( v127 < 8 )
  {
    v134 = buffer->m_pBufferEnd;
    v135 = buffer->m_nInBufWord;
    v136 = 8 - v127;
    v137 = buffer->m_pDataIn;
    if ( v137 == v134 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v137 > v134 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_188:
        if ( !buffer->m_bOverflow )
        {
          v138 = buffer->m_nInBufWord;
          v139 = (v138 & CBitBuffer::s_nMaskTable[v136]) << buffer->m_nBitsAvail;
          buffer->m_nBitsAvail = 32 - v136;
          v131 = v138 >> v136;
          v129 = v139 | v135;
          goto LABEL_191;
        }
        v129 = 0;
        goto LABEL_192;
      }
      buffer->m_nInBufWord = *v137;
    }
    buffer->m_pDataIn = v137 + 1;
    goto LABEL_188;
  }
  v128 = buffer->m_nInBufWord;
  v129 = v128;
  v130 = v127 - 8;
  buffer->m_nBitsAvail = v130;
  if ( v130 != 0 )
  {
    v131 = v128 >> 8;
LABEL_191:
    buffer->m_nInBufWord = v131;
    goto LABEL_192;
  }
  v132 = buffer->m_pDataIn;
  v133 = buffer->m_pBufferEnd;
  buffer->m_nBitsAvail = 32;
  if ( v132 == v133 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_pDataIn = v132 + 1;
  }
  else
  {
    if ( v132 <= v133 )
    {
      v131 = *v132;
      buffer->m_pDataIn = v132 + 1;
      goto LABEL_191;
    }
    buffer->m_bOverflow = true;
    buffer->m_nInBufWord = 0;
  }
LABEL_192:
  this->m_cOS = v129;
  CBitRead::ReadString(this: buffer, pStr, maxLen: 260, bLine: false, pOutNumChars: nullptr);
  CBitRead::ReadString(this: buffer, pStr: m_szMapNameBuffer, maxLen: 260, bLine: false, pOutNumChars: nullptr);
  CBitRead::ReadString(this: buffer, pStr: m_szSkyNameBuffer, maxLen: 260, bLine: false, pOutNumChars: nullptr);
  CBitRead::ReadString(this: buffer, pStr: v141, maxLen: 260, bLine: false, pOutNumChars: nullptr);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BC230
// Name: public: virtual char const __near * SVC_ServerInfo::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_ServerInfo::ToString(SVC_ServerInfo *this)
{
  const char *v1; // eax
  const char *v3; // [esp-Ch] [ebp-Ch]
  const char *v4; // [esp-8h] [ebp-8h]
  int v5; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_ServerInfo *, const char *, const char *, int))this->GetName)(
                       a1: this,
                       a2: this->m_szGameDir,
                       a3: this->m_szMapName,
                       a4: this->m_nMaxClients);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: game \"%s\", map \"%s\", max %i", v1, v3, v4, v5);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BC270
// Name: public: virtual char const __near * NET_SignonState::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall NET_SignonState::ToString(NET_SignonState *this)
{
  const char *v1; // eax
  int v3; // [esp-8h] [ebp-8h]
  int v4; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(NET_SignonState *, int, int))this->GetName)(
                       a1: this,
                       a2: this->m_nSignonState,
                       a3: this->m_nSpawnCount);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: state %i, count %i", v1, v3, v4);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BC2A0
// Name: public: virtual bool SVC_BSPDecal::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_BSPDecal::ReadFromBuffer(SVC_BSPDecal *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // edi
  unsigned int v5; // edx
  const unsigned int *v6; // eax
  const unsigned int *v7; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v10; // eax
  const unsigned int *m_pDataIn; // ecx
  int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // ebx
  SVC_BSPDecal *v15; // edi
  unsigned int v16; // eax
  int v17; // ecx
  bool v18; // zf
  const unsigned int *v19; // eax
  const unsigned int *v20; // edx
  int v21; // ecx
  unsigned int v22; // eax
  int v23; // edx
  int v24; // ecx
  int v25; // eax
  const unsigned int *v26; // eax
  const unsigned int *v27; // ecx
  unsigned int v28; // ecx
  const unsigned int *v29; // edx
  unsigned int v30; // edi
  int v31; // eax
  const unsigned int *v32; // ecx
  unsigned int v33; // edx
  unsigned int v34; // ebx
  unsigned int v35; // edx
  int v36; // ecx
  unsigned int v37; // eax
  int v38; // edi
  int v39; // ecx
  const unsigned int *v40; // eax
  const unsigned int *v41; // ecx
  SVC_BSPDecal *v42; // edx
  const unsigned int *v43; // edx
  unsigned int v44; // edi
  int v45; // eax
  const unsigned int *v46; // ecx
  SVC_BSPDecal *v47; // edx
  unsigned int v48; // edx
  unsigned int v49; // ebx
  unsigned int v50; // eax
  int v51; // ecx
  const unsigned int *v52; // eax
  const unsigned int *v53; // edx

  CBitRead::ReadBitVec3Coord(this: buffer, fa: &this->m_Pos);
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 9 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v10 = 9 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_15:
        if ( buffer->m_bOverflow )
        {
          v12 = 0;
          goto LABEL_20;
        }
        v13 = buffer->m_nInBufWord;
        v14 = (v13 & CBitBuffer::s_nMaskTable[v10]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v10;
        v4 = v14 | m_nInBufWord;
        v5 = v13 >> v10;
        goto LABEL_18;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v3 = buffer->m_nInBufWord;
  v4 = v3 & 0x1FF;
  buffer->m_nBitsAvail = m_nBitsAvail - 9;
  if ( m_nBitsAvail == 9 )
  {
    v6 = buffer->m_pDataIn;
    v7 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v6 == v7 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v6 + 1;
    }
    else if ( v6 <= v7 )
    {
      buffer->m_nInBufWord = *v6;
      buffer->m_pDataIn = v6 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
    goto LABEL_19;
  }
  v5 = v3 >> 9;
LABEL_18:
  buffer->m_nInBufWord = v5;
LABEL_19:
  v12 = v4;
LABEL_20:
  v15 = this;
  this->m_nDecalTextureIndex = v12;
  v16 = buffer->m_nInBufWord;
  v17 = v16 & 1;
  v18 = buffer->m_nBitsAvail-- == 1;
  if ( v18 )
  {
    v19 = buffer->m_pDataIn;
    v20 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v19 == v20 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v19 + 1;
    }
    else if ( v19 <= v20 )
    {
      buffer->m_nInBufWord = *v19;
      buffer->m_pDataIn = v19 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v16 >> 1;
  }
  if ( v17 == 0 )
  {
    this->m_nEntityIndex = 0;
    this->m_nModelIndex = 0;
    goto LABEL_67;
  }
  v21 = buffer->m_nBitsAvail;
  if ( v21 >= 11 )
  {
    v22 = buffer->m_nInBufWord;
    v23 = v22 & 0x7FF;
    v24 = v21 - 11;
    buffer->m_nBitsAvail = v24;
    if ( v24 != 0 )
    {
      buffer->m_nInBufWord = v22 >> 11;
      v25 = v22 & 0x7FF;
    }
    else
    {
      v26 = buffer->m_pDataIn;
      v27 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v26 == v27 )
      {
        buffer->m_pDataIn = v26 + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        v25 = v23;
      }
      else
      {
        if ( v26 <= v27 )
        {
          v28 = *v26;
          buffer->m_pDataIn = v26 + 1;
          buffer->m_nInBufWord = v28;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v25 = v23;
      }
    }
    goto LABEL_47;
  }
  v29 = buffer->m_pBufferEnd;
  v30 = buffer->m_nInBufWord;
  v31 = 11 - v21;
  v32 = buffer->m_pDataIn;
  if ( v32 == v29 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_42:
    buffer->m_pDataIn = v32 + 1;
    goto LABEL_43;
  }
  if ( v32 <= v29 )
  {
    buffer->m_nInBufWord = *v32;
    goto LABEL_42;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_43:
  if ( buffer->m_bOverflow )
  {
    v25 = 0;
  }
  else
  {
    v33 = buffer->m_nInBufWord;
    v34 = (v33 & CBitBuffer::s_nMaskTable[v31]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v31;
    v35 = v33 >> v31;
    v25 = v34 | v30;
    buffer->m_nInBufWord = v35;
  }
  v15 = this;
LABEL_47:
  v15->m_nEntityIndex = v25;
  v36 = buffer->m_nBitsAvail;
  if ( v36 >= 11 )
  {
    v37 = buffer->m_nInBufWord;
    v38 = v37 & 0x7FF;
    v39 = v36 - 11;
    buffer->m_nBitsAvail = v39;
    if ( v39 != 0 )
    {
      buffer->m_nInBufWord = v37 >> 11;
      this->m_nModelIndex = v38;
      v15 = this;
    }
    else
    {
      v40 = buffer->m_pDataIn;
      v41 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v40 == v41 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v40 + 1;
        this->m_nModelIndex = v38;
        v15 = this;
      }
      else
      {
        if ( v40 <= v41 )
        {
          buffer->m_nInBufWord = *v40;
          v42 = this;
          buffer->m_pDataIn = v40 + 1;
        }
        else
        {
          v42 = this;
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v42->m_nModelIndex = v38;
        v15 = v42;
      }
    }
    goto LABEL_67;
  }
  v43 = buffer->m_pBufferEnd;
  v44 = buffer->m_nInBufWord;
  v45 = 11 - v36;
  v46 = buffer->m_pDataIn;
  if ( v46 == v43 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_61:
    buffer->m_pDataIn = v46 + 1;
    goto LABEL_62;
  }
  if ( v46 <= v43 )
  {
    buffer->m_nInBufWord = *v46;
    goto LABEL_61;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_62:
  if ( buffer->m_bOverflow )
  {
    v47 = this;
    this->m_nModelIndex = 0;
  }
  else
  {
    v48 = buffer->m_nInBufWord;
    v49 = (v48 & CBitBuffer::s_nMaskTable[v45]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v45;
    buffer->m_nInBufWord = v48 >> v45;
    v47 = this;
    this->m_nModelIndex = v49 | v44;
  }
  v15 = v47;
LABEL_67:
  v50 = buffer->m_nInBufWord;
  v51 = v50 & 1;
  v18 = buffer->m_nBitsAvail-- == 1;
  if ( v18 )
  {
    v52 = buffer->m_pDataIn;
    v53 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v52 == v53 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v52 + 1;
    }
    else if ( v52 <= v53 )
    {
      buffer->m_nInBufWord = *v52;
      buffer->m_pDataIn = v52 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v50 >> 1;
  }
  v15->m_bLowPriority = v51 != 0;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BC640
// Name: public: virtual char const __near * SVC_BSPDecal::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_BSPDecal::ToString(SVC_BSPDecal *this)
{
  const char *v1; // eax
  int v3; // [esp-10h] [ebp-10h]
  int v4; // [esp-Ch] [ebp-Ch]
  int v5; // [esp-8h] [ebp-8h]
  int v6; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_BSPDecal *, int, int, int, bool))this->GetName)(
                       a1: this,
                       a2: this->m_nDecalTextureIndex,
                       a3: this->m_nEntityIndex,
                       a4: this->m_nModelIndex,
                       a5: this->m_bLowPriority);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: tex %i, ent %i, mod %i lowpriority %i", v1, v3, v4, v5, v6);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BC680
// Name: public: virtual bool SVC_SetView::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_SetView::WriteToBuffer(SVC_SetView *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nEntityIndex, numbits: 11, bCheckRange: true);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BC6C0
// Name: public: virtual bool SVC_SetView::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_SetView::ReadFromBuffer(SVC_SetView *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // ecx
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  unsigned int v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 11 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v12 = 11 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_16;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( buffer->m_bOverflow )
    {
      v6 = 0;
    }
    else
    {
      v14 = buffer->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v12;
      v6 = v15 | m_nInBufWord;
      buffer->m_nInBufWord = v14 >> v12;
    }
    goto LABEL_19;
  }
  v3 = buffer->m_nInBufWord;
  v4 = v3 & 0x7FF;
  v5 = m_nBitsAvail - 11;
  buffer->m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    buffer->m_nInBufWord = v3 >> 11;
    v6 = v3 & 0x7FF;
  }
  else
  {
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      buffer->m_pDataIn = v7 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v6 = v4;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v9 = *v7;
        buffer->m_pDataIn = v7 + 1;
        buffer->m_nInBufWord = v9;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v6 = v4;
    }
  }
LABEL_19:
  this->m_nEntityIndex = v6;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BC7D0
// Name: public: virtual char const __near * SVC_SetView::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_SetView::ToString(SVC_SetView *this)
{
  const char *v1; // eax
  int v3; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_SetView *, int))this->GetName)(a1: this, a2: this->m_nEntityIndex);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: view entity %i", v1, v3);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BC800
// Name: public: virtual bool SVC_FixAngle::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_FixAngle::ReadFromBuffer(SVC_FixAngle *this, bf_read *buffer)
{
  unsigned int m_nInBufWord; // eax
  int v4; // ecx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // edx

  m_nInBufWord = buffer->m_nInBufWord;
  v4 = m_nInBufWord & 1;
  if ( buffer->m_nBitsAvail-- == 1 )
  {
    m_pDataIn = buffer->m_pDataIn;
    m_pBufferEnd = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      buffer->m_nInBufWord = *m_pDataIn;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = m_nInBufWord >> 1;
  }
  this->m_bRelative = v4 != 0;
  this->m_Angle.x = CBitRead::ReadBitAngle(this: buffer, numbits: 16);
  this->m_Angle.y = CBitRead::ReadBitAngle(this: buffer, numbits: 16);
  this->m_Angle.z = CBitRead::ReadBitAngle(this: buffer, numbits: 16);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BC8A0
// Name: public: virtual char const __near * SVC_FixAngle::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_FixAngle::ToString(SVC_FixAngle *this)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v4; // [esp-4h] [ebp-1Ch]
  double v5; // [esp+0h] [ebp-18h]
  double v6; // [esp+8h] [ebp-10h]
  double v7; // [esp+10h] [ebp-8h]

  v1 = "relative";
  if ( !this->m_bRelative )
    v1 = "absolute";
  v2 = (const char *)((int (__thiscall *)(SVC_FixAngle *, const char *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->GetName)(
                       a1: this,
                       a2: v1,
                       a3: COERCE_UNSIGNED_INT64(this->m_Angle.x),
                       a4: HIDWORD(COERCE_UNSIGNED_INT64(this->m_Angle.x)),
                       a5: COERCE_UNSIGNED_INT64(this->m_Angle.y),
                       a6: HIDWORD(COERCE_UNSIGNED_INT64(this->m_Angle.y)),
                       a7: COERCE_UNSIGNED_INT64(this->m_Angle.z),
                       a8: HIDWORD(COERCE_UNSIGNED_INT64(this->m_Angle.z)));
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: %s %.1f %.1f %.1f ", v2, v4, v5, v6, v7);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BC8F0
// Name: public: virtual bool SVC_CrosshairAngle::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_CrosshairAngle::WriteToBuffer(SVC_CrosshairAngle *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteBitAngle(this: buffer, fAngle: this->m_Angle.x, numbits: 16);
  bf_write::WriteBitAngle(this: buffer, fAngle: this->m_Angle.y, numbits: 16);
  bf_write::WriteBitAngle(this: buffer, fAngle: this->m_Angle.z, numbits: 16);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BC950
// Name: public: virtual bool SVC_CrosshairAngle::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_CrosshairAngle::ReadFromBuffer(SVC_CrosshairAngle *this, bf_read *buffer)
{
  this->m_Angle.x = CBitRead::ReadBitAngle(this: buffer, numbits: 16);
  this->m_Angle.y = CBitRead::ReadBitAngle(this: buffer, numbits: 16);
  this->m_Angle.z = CBitRead::ReadBitAngle(this: buffer, numbits: 16);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BC990
// Name: public: virtual char const __near * SVC_CrosshairAngle::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_CrosshairAngle::ToString(SVC_CrosshairAngle *this)
{
  const char *v1; // eax
  double v3; // [esp+0h] [ebp-18h]
  double v4; // [esp+8h] [ebp-10h]
  double v5; // [esp+10h] [ebp-8h]

  v1 = (const char *)((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->GetName)(
                       a1: COERCE_UNSIGNED_INT64(this->m_Angle.x),
                       a2: HIDWORD(COERCE_UNSIGNED_INT64(this->m_Angle.x)),
                       a3: COERCE_UNSIGNED_INT64(this->m_Angle.y),
                       a4: HIDWORD(COERCE_UNSIGNED_INT64(this->m_Angle.y)),
                       a5: COERCE_UNSIGNED_INT64(this->m_Angle.z),
                       a6: HIDWORD(COERCE_UNSIGNED_INT64(this->m_Angle.z)));
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: (%.1f %.1f %.1f)", v1, v3, v4, v5);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BC9D0
// Name: public: virtual bool SVC_VoiceInit::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_VoiceInit::WriteToBuffer(SVC_VoiceInit *this, bf_write *buffer)
{
  unsigned int v3; // eax
  const char *m_szVoiceCodec; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_szVoiceCodec = this->m_szVoiceCodec;
  if ( m_szVoiceCodec == nullptr )
    m_szVoiceCodec = "svc_voiceinit NULL";
  bf_write::WriteString(this: buffer, pStr: m_szVoiceCodec);
  bf_write::WriteByte(this: buffer, val: this->m_nQuality);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BCA20
// Name: public: virtual bool SVC_VoiceInit::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_VoiceInit::ReadFromBuffer(SVC_VoiceInit *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v5; // edx
  int v6; // ecx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  unsigned int v10; // ecx
  const unsigned int *v11; // edx
  unsigned int v12; // edi
  int v13; // eax
  const unsigned int *v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ebx

  this->m_szVoiceCodec = this->m_szVoiceCodecBuffer;
  CBitRead::ReadString(this: buffer, pStr: this->m_szVoiceCodecBuffer, maxLen: 260, bLine: false, pOutNumChars: nullptr);
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 8 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v5 = (unsigned __int8)m_nInBufWord;
    v6 = m_nBitsAvail - 8;
    buffer->m_nBitsAvail = v6;
    if ( v6 != 0 )
    {
      buffer->m_nInBufWord = m_nInBufWord >> 8;
      this->m_nQuality = (unsigned __int8)m_nInBufWord;
      return !buffer->m_bOverflow;
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_pDataIn = m_pDataIn + 1;
        buffer->m_nInBufWord = 0;
        buffer->m_nBitsAvail = 1;
        this->m_nQuality = v5;
        return !buffer->m_bOverflow;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v10 = *m_pDataIn;
          buffer->m_pDataIn = m_pDataIn + 1;
          buffer->m_nInBufWord = v10;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        this->m_nQuality = v5;
        return !buffer->m_bOverflow;
      }
    }
  }
  v11 = buffer->m_pBufferEnd;
  v12 = buffer->m_nInBufWord;
  v13 = 8 - m_nBitsAvail;
  v14 = buffer->m_pDataIn;
  if ( v14 == v11 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_15:
    buffer->m_pDataIn = v14 + 1;
    goto LABEL_16;
  }
  if ( v14 <= v11 )
  {
    buffer->m_nInBufWord = *v14;
    goto LABEL_15;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_16:
  if ( buffer->m_bOverflow )
  {
    this->m_nQuality = 0;
  }
  else
  {
    v15 = buffer->m_nInBufWord;
    v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v13;
    buffer->m_nInBufWord = v15 >> v13;
    this->m_nQuality = v16 | v12;
  }
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BCBA0
// Name: public: virtual char const __near * SVC_VoiceInit::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_VoiceInit::ToString(SVC_VoiceInit *this)
{
  const char *v1; // eax
  const char *v3; // [esp-8h] [ebp-8h]
  int v4; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_VoiceInit *, const char *, int))this->GetName)(
                       a1: this,
                       a2: this->m_szVoiceCodec,
                       a3: this->m_nQuality);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: codec \"%s\", qualitty %i", v1, v3, v4);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BCBD0
// Name: public: virtual bool SVC_VoiceData::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_VoiceData::WriteToBuffer(SVC_VoiceData *this, bf_write *buffer)
{
  SVC_VoiceData *v2; // edi
  unsigned int v3; // eax
  int m_nDataBits; // ecx
  int v5; // eax
  int v6; // edx
  int m_iCurBit; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // eax
  unsigned int v13; // [esp+10h] [ebp-4h]
  unsigned int v14; // [esp+10h] [ebp-4h]

  v2 = this;
  v3 = ((int (__fastcall *)(SVC_VoiceData *))this->GetType)(a1: this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteByte(this: buffer, val: v2->m_nFromClient);
  bf_write::WriteByte(this: buffer, val: v2->m_bProximity);
  bf_write::WriteWord(this: buffer, val: v2->m_nLength);
  if ( NET_IsDedicatedForXbox() )
    bf_write::WriteLongLong(this: buffer, val: v2->m_xuid);
  m_nDataBits = buffer->m_nDataBits;
  v13 = v2->m_bAudible[0];
  if ( buffer->m_iCurBit + 1 <= m_nDataBits )
  {
    v5 = buffer->m_iCurBit & 0x1F;
    v6 = buffer->m_iCurBit >> 5;
    *(_DWORD *)&buffer->m_pData[4 * v6] = (v2->m_bAudible[0] << v5)
                                        | *(_DWORD *)&buffer->m_pData[4 * v6] & dword_106C73CC[33 * v5];
    if ( 32 - v5 - 1 < 0 )
      *(_DWORD *)&buffer->m_pData[4 * v6 + 4] = (v13 >> (32 - v5))
                                              | *(_DWORD *)&buffer->m_pData[4 * v6 + 4] & dword_106C73CC[-(32 - v5)];
    ++buffer->m_iCurBit;
    v2 = this;
  }
  else
  {
    buffer->m_iCurBit = m_nDataBits;
    buffer->m_bOverflow = true;
  }
  m_iCurBit = buffer->m_iCurBit;
  v8 = buffer->m_nDataBits;
  v14 = v2->m_bAudible[1];
  if ( m_iCurBit + 1 <= v8 )
  {
    v9 = m_iCurBit >> 5;
    *(_DWORD *)&buffer->m_pData[4 * (buffer->m_iCurBit >> 5)] = (v2->m_bAudible[1] << (buffer->m_iCurBit & 0x1F))
                                                              | *(_DWORD *)&buffer->m_pData[4 * (buffer->m_iCurBit >> 5)]
                                                              & dword_106C73CC[33 * (buffer->m_iCurBit & 0x1F)];
    v10 = 32 - (m_iCurBit & 0x1F);
    if ( v10 < 1 )
      *(_DWORD *)&buffer->m_pData[4 * v9 + 4] = (v14 >> v10)
                                              | *(_DWORD *)&buffer->m_pData[4 * v9 + 4] & dword_106C73CC[-v10];
    ++buffer->m_iCurBit;
    v2 = this;
  }
  else
  {
    buffer->m_iCurBit = v8;
    buffer->m_bOverflow = true;
  }
  return bf_write::WriteBits(this: buffer, pInData: v2->m_DataOut, nBits: v2->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BCD40
// Name: public: virtual char const __near * SVC_VoiceData::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_VoiceData::ToString(SVC_VoiceData *this)
{
  const char *v1; // eax
  int v3; // [esp-8h] [ebp-8h]
  int v4; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_VoiceData *, int, int))this->GetName)(
                       a1: this,
                       a2: this->m_nFromClient,
                       a3: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: client %i, bytes %i", v1, v3, v4);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BCD80
// Name: public: virtual bool NET_Tick::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NET_Tick::ReadFromBuffer(NET_Tick *this, bf_read *buffer)
{
  int m_nBitsAvail; // esi
  int m_nInBufWord; // ecx
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // esi
  const unsigned int *v6; // ecx
  unsigned int v7; // edi
  int v8; // edx
  const unsigned int *v9; // esi
  unsigned int v10; // esi
  unsigned int v11; // ebx
  int v12; // ecx
  unsigned int v13; // edx
  int v14; // esi
  int v15; // ecx
  int v16; // ecx
  const unsigned int *v17; // ecx
  const unsigned int *v18; // edx
  unsigned int v19; // edx
  const unsigned int *v20; // esi
  unsigned int v21; // edi
  int v22; // edx
  const unsigned int *v23; // ecx
  unsigned int v24; // esi
  unsigned int v25; // ebx
  int v26; // ecx
  unsigned int v27; // edx
  int v28; // esi
  int v29; // ecx
  int v30; // ecx
  const unsigned int *v31; // ecx
  const unsigned int *v32; // edx
  unsigned int v33; // edx
  const unsigned int *v34; // esi
  unsigned int v35; // edi
  int v36; // edx
  const unsigned int *v37; // ecx
  unsigned int v38; // esi
  unsigned int v39; // ebx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 32 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    buffer->m_nBitsAvail = m_nBitsAvail - 32;
    if ( m_nBitsAvail == 32 )
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        buffer->m_nInBufWord = *m_pDataIn;
        buffer->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
    }
    else
    {
      buffer->m_nInBufWord = 0;
    }
    goto LABEL_18;
  }
  v6 = buffer->m_pDataIn;
  v7 = buffer->m_nInBufWord;
  v8 = 32 - m_nBitsAvail;
  v9 = buffer->m_pBufferEnd;
  if ( v6 == v9 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v6 > v9 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_15;
    }
    buffer->m_nInBufWord = *v6;
  }
  buffer->m_pDataIn = v6 + 1;
LABEL_15:
  if ( buffer->m_bOverflow )
  {
    m_nInBufWord = 0;
  }
  else
  {
    v10 = buffer->m_nInBufWord;
    v11 = (v10 & CBitBuffer::s_nMaskTable[v8]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v8;
    m_nInBufWord = v11 | v7;
    buffer->m_nInBufWord = v10 >> v8;
  }
LABEL_18:
  this->m_nTick = m_nInBufWord;
  v12 = buffer->m_nBitsAvail;
  if ( v12 < 16 )
  {
    v20 = buffer->m_pBufferEnd;
    v21 = buffer->m_nInBufWord;
    v22 = 16 - v12;
    v23 = buffer->m_pDataIn;
    if ( v23 == v20 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v23 > v20 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_33;
      }
      buffer->m_nInBufWord = *v23;
    }
    buffer->m_pDataIn = v23 + 1;
LABEL_33:
    if ( buffer->m_bOverflow )
    {
      v16 = 0;
    }
    else
    {
      v24 = buffer->m_nInBufWord;
      v25 = (v24 & CBitBuffer::s_nMaskTable[v22]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v22;
      v16 = v25 | v21;
      buffer->m_nInBufWord = v24 >> v22;
    }
    goto LABEL_36;
  }
  v13 = buffer->m_nInBufWord;
  v14 = (unsigned __int16)v13;
  v15 = v12 - 16;
  buffer->m_nBitsAvail = v15;
  if ( v15 != 0 )
  {
    buffer->m_nInBufWord = HIWORD(v13);
    v16 = (unsigned __int16)v13;
  }
  else
  {
    v17 = buffer->m_pDataIn;
    v18 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v17 == v18 )
    {
      buffer->m_pDataIn = v17 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v16 = v14;
    }
    else
    {
      if ( v17 <= v18 )
      {
        v19 = *v17;
        buffer->m_pDataIn = v17 + 1;
        buffer->m_nInBufWord = v19;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v16 = v14;
    }
  }
LABEL_36:
  this->m_flHostFrameTime = (double)(unsigned int)v16 * 0.0000099999997;
  v26 = buffer->m_nBitsAvail;
  if ( v26 < 16 )
  {
    v34 = buffer->m_pBufferEnd;
    v35 = buffer->m_nInBufWord;
    v36 = 16 - v26;
    v37 = buffer->m_pDataIn;
    if ( v37 == v34 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v37 > v34 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_51;
      }
      buffer->m_nInBufWord = *v37;
    }
    buffer->m_pDataIn = v37 + 1;
LABEL_51:
    if ( buffer->m_bOverflow )
    {
      v30 = 0;
    }
    else
    {
      v38 = buffer->m_nInBufWord;
      v39 = (v38 & CBitBuffer::s_nMaskTable[v36]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v36;
      v30 = v39 | v35;
      buffer->m_nInBufWord = v38 >> v36;
    }
    goto LABEL_54;
  }
  v27 = buffer->m_nInBufWord;
  v28 = (unsigned __int16)v27;
  v29 = v26 - 16;
  buffer->m_nBitsAvail = v29;
  if ( v29 != 0 )
  {
    buffer->m_nInBufWord = HIWORD(v27);
    v30 = (unsigned __int16)v27;
  }
  else
  {
    v31 = buffer->m_pDataIn;
    v32 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v31 == v32 )
    {
      buffer->m_pDataIn = v31 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v30 = v28;
    }
    else
    {
      if ( v31 <= v32 )
      {
        v33 = *v31;
        buffer->m_pDataIn = v31 + 1;
        buffer->m_nInBufWord = v33;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v30 = v28;
    }
  }
LABEL_54:
  this->m_flHostFrameTimeStdDeviation = 0.0000099999997 * (double)(unsigned int)v30;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BD060
// Name: public: virtual bool NET_SplitScreenUser::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall NET_SplitScreenUser::WriteToBuffer(NET_SplitScreenUser *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nSlot, numbits: 1, bCheckRange: true);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BD0A0
// Name: public: virtual bool NET_SplitScreenUser::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NET_SplitScreenUser::ReadFromBuffer(NET_SplitScreenUser *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // ecx
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  unsigned int v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 1 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v12 = 1 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_16;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( buffer->m_bOverflow )
    {
      v6 = 0;
    }
    else
    {
      v14 = buffer->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v12;
      v6 = v15 | m_nInBufWord;
      buffer->m_nInBufWord = v14 >> v12;
    }
    goto LABEL_19;
  }
  v3 = buffer->m_nInBufWord;
  v4 = v3 & 1;
  v5 = m_nBitsAvail - 1;
  buffer->m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    buffer->m_nInBufWord = v3 >> 1;
    v6 = v3 & 1;
  }
  else
  {
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      buffer->m_pDataIn = v7 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v6 = v4;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v9 = *v7;
        buffer->m_pDataIn = v7 + 1;
        buffer->m_nInBufWord = v9;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v6 = v4;
    }
  }
LABEL_19:
  this->m_nSlot = v6;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BD1A0
// Name: public: virtual char const __near * NET_SplitScreenUser::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall NET_SplitScreenUser::ToString(NET_SplitScreenUser *this)
{
  const char *v1; // eax
  int v3; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(NET_SplitScreenUser *, int))this->GetName)(a1: this, a2: this->m_nSlot);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: slot %d", v1, v3);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD1D0
// Name: public: virtual bool SVC_UserMessage::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_UserMessage::WriteToBuffer(SVC_UserMessage *this, bf_write *buffer)
{
  unsigned int v3; // eax
  unsigned int m_nMsgType; // [esp-4h] [ebp-Ch]

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_nMsgType = this->m_nMsgType;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  bf_write::WriteByte(this: buffer, val: m_nMsgType);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 12, bCheckRange: true);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BD230
// Name: public: virtual char const __near * SVC_UserMessage::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_UserMessage::ToString(SVC_UserMessage *this)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v5; // [esp-8h] [ebp-Ch]
  int v6; // [esp-4h] [ebp-8h]

  v2 = CUtlString::operator char const *(this: &this->m_sDebugName);
  v3 = (const char *)((int (__thiscall *)(SVC_UserMessage *, const char *, int))this->GetName)(
                       a1: this,
                       a2: v2,
                       a3: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s(%s): bytes %i", v3, v5, v6);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD270
// Name: public: virtual bool SVC_SetPause::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_SetPause::ReadFromBuffer(SVC_SetPause *this, bf_read *buffer)
{
  unsigned int m_nInBufWord; // edx
  int v3; // esi
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // edi

  m_nInBufWord = buffer->m_nInBufWord;
  v3 = m_nInBufWord & 1;
  if ( buffer->m_nBitsAvail-- == 1 )
  {
    m_pDataIn = buffer->m_pDataIn;
    m_pBufferEnd = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      buffer->m_nInBufWord = *m_pDataIn;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = m_nInBufWord >> 1;
  }
  this->m_bPaused = v3 != 0;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BD2F0
// Name: public: virtual char const __near * SVC_SetPause::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_SetPause::ToString(SVC_SetPause *this)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v4; // [esp-4h] [ebp-4h]

  v1 = "paused";
  if ( !this->m_bPaused )
    v1 = "unpaused";
  v2 = (const char *)((int (__thiscall *)(SVC_SetPause *, const char *))this->GetName)(a1: this, a2: v1);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: %s", v2, v4);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD330
// Name: public: virtual char const __near * SVC_UpdateStringTable::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_UpdateStringTable::ToString(SVC_UpdateStringTable *this)
{
  const char *v1; // eax
  int v3; // [esp-Ch] [ebp-Ch]
  int v4; // [esp-8h] [ebp-8h]
  int v5; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_UpdateStringTable *, int, int, int))this->GetName)(
                       a1: this,
                       a2: this->m_nTableID,
                       a3: this->m_nChangedEntries,
                       a4: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: table %i, changed %i, bytes %i", v1, v3, v4, v5);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD3B0
// Name: public: virtual char const __near * SVC_Sounds::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_Sounds::ToString(SVC_Sounds *this)
{
  const char *v1; // eax
  const char *v2; // eax
  int v4; // [esp-Ch] [ebp-Ch]
  const char *v5; // [esp-8h] [ebp-8h]
  int v6; // [esp-4h] [ebp-4h]

  v1 = " reliable,";
  if ( !this->m_bReliableSound )
    v1 = defaultValue;
  v2 = (const char *)((int (__thiscall *)(SVC_Sounds *, int, const char *, int))this->GetName)(
                       a1: this,
                       a2: this->m_nNumSounds,
                       a3: v1,
                       a4: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: number %i,%s bytes %i", v2, v4, v5, v6);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD400
// Name: public: virtual bool SVC_Prefetch::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_Prefetch::WriteToBuffer(SVC_Prefetch *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nSoundIndex, numbits: 13, bCheckRange: true);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BD440
// Name: public: virtual bool SVC_Prefetch::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_Prefetch::ReadFromBuffer(SVC_Prefetch *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  unsigned __int16 v4; // si
  int v5; // ecx
  unsigned __int16 v6; // cx
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  unsigned int v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx

  this->m_fType = 0;
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 13 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v12 = 13 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_16;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( buffer->m_bOverflow )
    {
      v6 = 0;
    }
    else
    {
      v14 = buffer->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v12;
      v6 = v15 | m_nInBufWord;
      buffer->m_nInBufWord = v14 >> v12;
    }
    goto LABEL_19;
  }
  v3 = buffer->m_nInBufWord;
  v4 = v3 & 0x1FFF;
  v5 = m_nBitsAvail - 13;
  buffer->m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    buffer->m_nInBufWord = v3 >> 13;
    v6 = v3 & 0x1FFF;
  }
  else
  {
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      buffer->m_pDataIn = v7 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v6 = v4;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v9 = *v7;
        buffer->m_pDataIn = v7 + 1;
        buffer->m_nInBufWord = v9;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v6 = v4;
    }
  }
LABEL_19:
  this->m_nSoundIndex = v6;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BD550
// Name: public: virtual char const __near * SVC_Prefetch::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_Prefetch::ToString(SVC_Prefetch *this)
{
  const char *v1; // eax
  int v3; // [esp-8h] [ebp-8h]
  int v4; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_Prefetch *, _DWORD, _DWORD))this->GetName)(
                       a1: this,
                       a2: this->m_fType,
                       a3: this->m_nSoundIndex);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: type %i index %i", v1, v3, v4);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD580
// Name: public: virtual bool SVC_TempEntities::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_TempEntities::WriteToBuffer(SVC_TempEntities *this, bf_write *buffer)
{
  SVC_TempEntities_vtbl *v3; // edx
  unsigned int v4; // eax

  v3 = this->__vftable;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  v4 = ((int (*)(void))v3->GetType)();
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nNumEntries, numbits: 8, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 17, bCheckRange: true);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BD5E0
// Name: public: virtual char const __near * SVC_ClassInfo::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_ClassInfo::ToString(SVC_ClassInfo *this)
{
  const char *v1; // eax
  const char *v2; // eax
  int v4; // [esp-8h] [ebp-8h]
  const char *v5; // [esp-4h] [ebp-4h]

  v1 = "use client classes";
  if ( !this->m_bCreateOnClient )
    v1 = "full update";
  v2 = (const char *)((int (__thiscall *)(SVC_ClassInfo *, int, const char *))this->GetName)(
                       a1: this,
                       a2: this->m_nNumServerClasses,
                       a3: v1);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: num %i, %s", v2, v4, v5);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD620
// Name: public: virtual bool SVC_GameEvent::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_GameEvent::WriteToBuffer(SVC_GameEvent *this, bf_write *buffer)
{
  SVC_GameEvent_vtbl *v3; // edx
  unsigned int v4; // eax

  v3 = this->__vftable;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  v4 = ((int (*)(void))v3->GetType)();
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 11, bCheckRange: true);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BD670
// Name: public: virtual char const __near * SVC_SendTable::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_SendTable::ToString(SVC_SendTable *this)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v4; // [esp-8h] [ebp-8h]
  int v5; // [esp-4h] [ebp-4h]

  v1 = "yes";
  if ( !this->m_bNeedsDecoder )
    v1 = "no";
  v2 = (const char *)((int (__thiscall *)(SVC_SendTable *, const char *, int))this->GetName)(
                       a1: this,
                       a2: v1,
                       a3: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: needs Decoder %s,bytes %i", v2, v4, v5);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD6B0
// Name: public: virtual bool SVC_EntityMessage::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_EntityMessage::WriteToBuffer(SVC_EntityMessage *this, bf_write *buffer)
{
  SVC_EntityMessage_vtbl *v3; // edx
  unsigned int v4; // eax

  v3 = this->__vftable;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  v4 = ((int (*)(void))v3->GetType)();
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nEntityIndex, numbits: 11, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nClassID, numbits: 9, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 11, bCheckRange: true);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BD720
// Name: public: virtual char const __near * SVC_EntityMessage::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_EntityMessage::ToString(SVC_EntityMessage *this)
{
  const char *v1; // eax
  int v3; // [esp-Ch] [ebp-Ch]
  int v4; // [esp-8h] [ebp-8h]
  int v5; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_EntityMessage *, int, int, int))this->GetName)(
                       a1: this,
                       a2: this->m_nEntityIndex,
                       a3: this->m_nClassID,
                       a4: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: entity %i, class %i, bytes %i", v1, v3, v4, v5);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD760
// Name: public: virtual char const __near * SVC_PacketEntities::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_PacketEntities::ToString(SVC_PacketEntities *this)
{
  const char *v1; // eax
  const char *v2; // eax
  int v4; // [esp-14h] [ebp-14h]
  int v5; // [esp-10h] [ebp-10h]
  int v6; // [esp-Ch] [ebp-Ch]
  const char *v7; // [esp-8h] [ebp-8h]
  int v8; // [esp-4h] [ebp-4h]

  v1 = " BL update,";
  if ( !this->m_bUpdateBaseline )
    v1 = defaultValue;
  v2 = (const char *)((int (__thiscall *)(SVC_PacketEntities *, int, int, int, const char *, int))this->GetName)(
                       a1: this,
                       a2: this->m_nDeltaFrom,
                       a3: this->m_nMaxEntries,
                       a4: this->m_nUpdatedEntries,
                       a5: v1,
                       a6: (this->m_nLength + 7) >> 3);
  V_snprintf(
    pDest: s_text,
    maxLen: 1024,
    pFormat: "%s: delta %i, max %i, changed %i,%s bytes %i",
    v2,
    v4,
    v5,
    v6,
    v7,
    v8);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD7B0
// Name: public: virtual SVC_Menu::~SVC_Menu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SVC_Menu::~SVC_Menu(SVC_Menu *this)
{
  KeyValues *m_MenuKeyValues; // ecx

  m_MenuKeyValues = this->m_MenuKeyValues;
  this->__vftable = (SVC_Menu_vtbl *)&SVC_Menu::`vftable';
  if ( m_MenuKeyValues != nullptr )
    KeyValues::deleteThis(this: m_MenuKeyValues);
  this->__vftable = (SVC_Menu_vtbl *)&INetMessage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x101BD7D0
// Name: public: virtual char const __near * SVC_Menu::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_Menu::ToString(SVC_Menu *this)
{
  KeyValues *m_MenuKeyValues; // ecx
  const char *Name; // eax
  const char *v4; // eax
  int v6; // [esp-Ch] [ebp-10h]
  const char *v7; // [esp-8h] [ebp-Ch]
  int v8; // [esp-4h] [ebp-8h]

  m_MenuKeyValues = this->m_MenuKeyValues;
  if ( m_MenuKeyValues != nullptr )
    Name = KeyValues::GetName(this: m_MenuKeyValues);
  else
    Name = "No KeyValues";
  v4 = (const char *)((int (__thiscall *)(SVC_Menu *, DIALOG_TYPE, const char *, int))this->GetName)(
                       a1: this,
                       a2: this->m_Type,
                       a3: Name,
                       a4: this->m_iLength);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: %i \"%s\" (len:%i)", v4, v6, v7, v8);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD820
// Name: public: virtual bool SVC_GameEventList::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_GameEventList::WriteToBuffer(SVC_GameEventList *this, bf_write *buffer)
{
  SVC_GameEventList_vtbl *v3; // edx
  unsigned int v4; // eax

  v3 = this->__vftable;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  v4 = ((int (*)(void))v3->GetType)();
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nNumEvents, numbits: 9, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 20, bCheckRange: true);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BD880
// Name: public: virtual char const __near * SVC_TempEntities::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_TempEntities::ToString(SVC_GameEventList *this)
{
  const char *v1; // eax
  int v3; // [esp-8h] [ebp-8h]
  int v4; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_GameEventList *, int, int))this->GetName)(
                       a1: this,
                       a2: this->m_nNumEvents,
                       a3: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: number %i, bytes %i", v1, v3, v4);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BD8C0
// Name: public: virtual bool SVC_SplitScreen::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_SplitScreen::WriteToBuffer(SVC_SplitScreen *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_Type, numbits: 1, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nSlot, numbits: 1, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nPlayerIndex, numbits: 11, bCheckRange: true);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BDBE0
// Name: public: virtual char const __near * SVC_SplitScreen::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_SplitScreen::ToString(SVC_SplitScreen *this)
{
  SVC_SplitScreen::ESplitScreenMessageType m_Type; // eax
  const char *v2; // edx
  const char *v3; // eax
  const char *v5; // [esp-Ch] [ebp-Ch]
  int v6; // [esp-8h] [ebp-8h]
  int v7; // [esp-4h] [ebp-4h]

  m_Type = this->m_Type;
  v2 = "adduser";
  if ( m_Type != MSG_ADDUSER )
  {
    if ( m_Type == MSG_REMOVEUSER )
      v2 = "removeuser";
  }
  else
  {
    v2 = "adduser";
  }
  v3 = (const char *)((int (__thiscall *)(SVC_SplitScreen *, const char *, int, int))this->GetName)(
                       a1: this,
                       a2: v2,
                       a3: this->m_nSlot,
                       a4: this->m_nPlayerIndex);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: %s slot %d [%d]", v3, v5, v6, v7);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BDC30
// Name: public: virtual bool SVC_GetCvarValue::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_GetCvarValue::WriteToBuffer(SVC_GetCvarValue *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteSBitLong(this: buffer, data: this->m_iCookie, numbits: 32);
  bf_write::WriteString(this: buffer, pStr: this->m_szCvarName);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BDC80
// Name: public: virtual bool SVC_GetCvarValue::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_GetCvarValue::ReadFromBuffer(SVC_GetCvarValue *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  int m_nInBufWord; // eax
  int v4; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  const unsigned int *v7; // edx
  unsigned int v8; // edi
  int v9; // eax
  const unsigned int *v10; // ecx
  unsigned int v11; // edx
  unsigned int v12; // ebx
  unsigned int v13; // edx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 32 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v4 = m_nBitsAvail - 32;
    buffer->m_nBitsAvail = v4;
    if ( v4 == 0 )
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = m_pDataIn + 1;
        goto LABEL_18;
      }
      if ( m_pDataIn <= m_pBufferEnd )
      {
        buffer->m_nInBufWord = *m_pDataIn;
        buffer->m_pDataIn = m_pDataIn + 1;
        goto LABEL_18;
      }
      buffer->m_bOverflow = true;
    }
    buffer->m_nInBufWord = 0;
    goto LABEL_18;
  }
  v7 = buffer->m_pBufferEnd;
  v8 = buffer->m_nInBufWord;
  v9 = 32 - m_nBitsAvail;
  v10 = buffer->m_pDataIn;
  if ( v10 == v7 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v10 > v7 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_15;
    }
    buffer->m_nInBufWord = *v10;
  }
  buffer->m_pDataIn = v10 + 1;
LABEL_15:
  if ( buffer->m_bOverflow )
  {
    m_nInBufWord = 0;
  }
  else
  {
    v11 = buffer->m_nInBufWord;
    v12 = (v11 & CBitBuffer::s_nMaskTable[v9]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v9;
    v13 = v11 >> v9;
    m_nInBufWord = v12 | v8;
    buffer->m_nInBufWord = v13;
  }
LABEL_18:
  this->m_iCookie = m_nInBufWord;
  CBitRead::ReadString(this: buffer, pStr: this->m_szCvarNameBuffer, maxLen: 256, bLine: false, pOutNumChars: nullptr);
  this->m_szCvarName = this->m_szCvarNameBuffer;
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BDD90
// Name: public: virtual char const __near * SVC_GetCvarValue::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_GetCvarValue::ToString(SVC_GetCvarValue *this)
{
  const char *v1; // eax
  const char *v3; // [esp-8h] [ebp-8h]
  int v4; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_GetCvarValue *, const char *, int))this->GetName)(
                       a1: this,
                       a2: this->m_szCvarName,
                       a3: this->m_iCookie);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: cvar: %s, cookie: %d", v1, v3, v4);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BDDC0
// Name: public: virtual bool SVC_PaintmapData::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_PaintmapData::WriteToBuffer(SVC_PaintmapData *this, bf_write *buffer)
{
  SVC_PaintmapData_vtbl *v3; // edx
  unsigned int v4; // eax

  v3 = this->__vftable;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  v4 = ((int (*)(void))v3->GetType)();
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 6, bCheckRange: true);
  bf_write::WriteLong(this: buffer, val: this->m_nLength);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BDE10
// Name: public: virtual char const __near * SVC_PaintmapData::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SVC_PaintmapData::ToString(SVC_PaintmapData *this)
{
  const char *v1; // eax
  int v3; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(SVC_PaintmapData *, int))this->GetName)(
                       a1: this,
                       a2: (this->m_nLength + 7) >> 3);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: bytes %i", v1, v3);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BDE40
// Name: public: virtual bool CLC_VoiceData::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_VoiceData::ReadFromBuffer(CLC_VoiceData *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  unsigned int v5; // edx
  int v6; // ecx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  unsigned int v9; // ecx
  const unsigned int *v10; // edx
  unsigned int v11; // esi
  int v12; // eax
  const unsigned int *v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // edi
  int v16; // esi
  unsigned int v17; // edx
  __int64 LongLong; // rax
  int m_nLength; // edx
  const unsigned int *m_pData; // eax
  int m_nDataBits; // eax
  CLC_VoiceData *v23; // [esp+Ch] [ebp-4h]

  m_nBitsAvail = buffer->m_nBitsAvail;
  v23 = this;
  if ( m_nBitsAvail >= 16 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v5 = (unsigned __int16)m_nInBufWord;
    v6 = m_nBitsAvail - 16;
    buffer->m_nBitsAvail = v6;
    if ( v6 != 0 )
    {
      buffer->m_nInBufWord = HIWORD(m_nInBufWord);
      m_nInBufWord = (unsigned __int16)m_nInBufWord;
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_pDataIn = m_pDataIn + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        m_nInBufWord = v5;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v9 = *m_pDataIn;
          buffer->m_pDataIn = m_pDataIn + 1;
          buffer->m_nInBufWord = v9;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        m_nInBufWord = v5;
      }
    }
    goto LABEL_19;
  }
  v10 = buffer->m_pBufferEnd;
  v11 = buffer->m_nInBufWord;
  v12 = 16 - m_nBitsAvail;
  v13 = buffer->m_pDataIn;
  if ( v13 == v10 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v13 > v10 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_16;
    }
    buffer->m_nInBufWord = *v13;
  }
  buffer->m_pDataIn = v13 + 1;
LABEL_16:
  if ( buffer->m_bOverflow )
  {
    m_nInBufWord = 0;
  }
  else
  {
    v14 = buffer->m_nInBufWord;
    v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v12;
    v16 = v15 | v11;
    this = v23;
    v17 = v14 >> v12;
    m_nInBufWord = v16;
    buffer->m_nInBufWord = v17;
  }
LABEL_19:
  this->m_nLength = m_nInBufWord;
  LongLong = CBitRead::ReadLongLong(this: buffer);
  HIDWORD(this->m_xuid) = HIDWORD(LongLong);
  m_nLength = v23->m_nLength;
  LODWORD(this->m_xuid) = LongLong;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: m_nLength);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: m_nDataBits + m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BDFB0
// Name: public: virtual bool CLC_Move::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_Move::ReadFromBuffer(CLC_Move *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // ebx
  int v7; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v10; // edx
  const unsigned int *v11; // esi
  unsigned int v12; // edi
  int v13; // edx
  const unsigned int *v14; // ecx
  unsigned int v15; // esi
  unsigned int v16; // ebx
  int v17; // ecx
  unsigned int v18; // edx
  int v19; // esi
  int v20; // ecx
  int v21; // ecx
  const unsigned int *v22; // ecx
  const unsigned int *v23; // edx
  unsigned int v24; // edx
  const unsigned int *v25; // esi
  unsigned int v26; // edi
  int v27; // edx
  const unsigned int *v28; // ecx
  unsigned int v29; // esi
  unsigned int v30; // ebx
  int v31; // ecx
  unsigned int v32; // edx
  int v33; // esi
  int v34; // ecx
  const unsigned int *v35; // ecx
  const unsigned int *v36; // edx
  unsigned int v37; // edx
  const unsigned int *v38; // esi
  unsigned int v39; // edi
  int v40; // edx
  const unsigned int *v41; // ecx
  unsigned int v42; // esi
  unsigned int v43; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 4 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v4 = m_nInBufWord & 0xF;
    v5 = m_nBitsAvail - 4;
    v6 = 0;
    buffer->m_nBitsAvail = v5;
    if ( v5 != 0 )
    {
      buffer->m_nInBufWord = m_nInBufWord >> 4;
      v7 = m_nInBufWord & 0xF;
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_pDataIn = m_pDataIn + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        v7 = v4;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v10 = *m_pDataIn;
          buffer->m_pDataIn = m_pDataIn + 1;
          buffer->m_nInBufWord = v10;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v7 = v4;
      }
    }
    goto LABEL_20;
  }
  v11 = buffer->m_pBufferEnd;
  v12 = buffer->m_nInBufWord;
  v13 = 4 - m_nBitsAvail;
  v14 = buffer->m_pDataIn;
  if ( v14 == v11 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_15:
    buffer->m_pDataIn = v14 + 1;
    goto LABEL_16;
  }
  if ( v14 <= v11 )
  {
    buffer->m_nInBufWord = *v14;
    goto LABEL_15;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_16:
  if ( buffer->m_bOverflow )
  {
    v7 = 0;
  }
  else
  {
    v15 = buffer->m_nInBufWord;
    v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v13;
    v7 = v16 | v12;
    buffer->m_nInBufWord = v15 >> v13;
  }
  v6 = 0;
LABEL_20:
  this->m_nNewCommands = v7;
  v17 = buffer->m_nBitsAvail;
  if ( v17 < 3 )
  {
    v25 = buffer->m_pBufferEnd;
    v26 = buffer->m_nInBufWord;
    v27 = 3 - v17;
    v28 = buffer->m_pDataIn;
    if ( v28 == v25 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v28 > v25 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_35;
      }
      buffer->m_nInBufWord = *v28;
    }
    buffer->m_pDataIn = v28 + 1;
LABEL_35:
    if ( buffer->m_bOverflow )
    {
      v21 = 0;
    }
    else
    {
      v29 = buffer->m_nInBufWord;
      v30 = (v29 & CBitBuffer::s_nMaskTable[v27]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v27;
      v21 = v30 | v26;
      v6 = 0;
      buffer->m_nInBufWord = v29 >> v27;
    }
    goto LABEL_38;
  }
  v18 = buffer->m_nInBufWord;
  v19 = v18 & 7;
  v20 = v17 - 3;
  buffer->m_nBitsAvail = v20;
  if ( v20 != 0 )
  {
    buffer->m_nInBufWord = v18 >> 3;
    v21 = v18 & 7;
  }
  else
  {
    v22 = buffer->m_pDataIn;
    v23 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v22 == v23 )
    {
      buffer->m_pDataIn = v22 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v21 = v19;
    }
    else
    {
      if ( v22 <= v23 )
      {
        v24 = *v22;
        buffer->m_pDataIn = v22 + 1;
        buffer->m_nInBufWord = v24;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v21 = v19;
    }
  }
LABEL_38:
  this->m_nBackupCommands = v21;
  v31 = buffer->m_nBitsAvail;
  if ( v31 >= 16 )
  {
    v32 = buffer->m_nInBufWord;
    v33 = (unsigned __int16)v32;
    v34 = v31 - 16;
    buffer->m_nBitsAvail = v34;
    if ( v34 != 0 )
    {
      buffer->m_nInBufWord = HIWORD(v32);
      v6 = (unsigned __int16)v32;
    }
    else
    {
      v35 = buffer->m_pDataIn;
      v36 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v35 == v36 )
      {
        buffer->m_nInBufWord = 0;
        buffer->m_nBitsAvail = 1;
        buffer->m_pDataIn = v35 + 1;
        v6 = v33;
      }
      else
      {
        if ( v35 <= v36 )
        {
          v37 = *v35;
          buffer->m_pDataIn = v35 + 1;
          buffer->m_nInBufWord = v37;
        }
        else
        {
          buffer->m_nInBufWord = 0;
          buffer->m_bOverflow = true;
        }
        v6 = v33;
      }
    }
    goto LABEL_55;
  }
  v38 = buffer->m_pBufferEnd;
  v39 = buffer->m_nInBufWord;
  v40 = 16 - v31;
  v41 = buffer->m_pDataIn;
  if ( v41 == v38 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v41 > v38 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_53;
    }
    buffer->m_nInBufWord = *v41;
  }
  buffer->m_pDataIn = v41 + 1;
LABEL_53:
  if ( !buffer->m_bOverflow )
  {
    v42 = buffer->m_nInBufWord;
    v43 = (v42 & CBitBuffer::s_nMaskTable[v40]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v40;
    v6 = v39 | v43;
    buffer->m_nInBufWord = v42 >> v40;
  }
LABEL_55:
  this->m_nLength = v6;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v6);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v6 + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101BE3F0
// Name: public: virtual bool CLC_FileCRCCheck::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLC_FileCRCCheck::WriteToBuffer(CLC_FileCRCCheck *this, bf_write *buffer)
{
  unsigned int v3; // eax
  int m_iCurBit; // ecx
  int v5; // edi
  char *m_szPathID; // ebx
  int CommonPrefix; // eax
  int v8; // edi
  const char *v10; // [esp-4h] [ebp-14h]

  v3 = ((int (__fastcall *)(CLC_FileCRCCheck *))this->GetType)(a1: this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_iCurBit = buffer->m_iCurBit;
  if ( m_iCurBit + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++buffer->m_iCurBit;
  }
  v5 = 0;
  m_szPathID = this->m_szPathID;
  while ( _V_stricmp(s1: m_szPathID, s2: g_MostCommonPathIDs[v5]) != 0 )
  {
    if ( (unsigned int)++v5 >= 2 )
    {
      bf_write::WriteUBitLong(this: buffer, curData: 0, numbits: 2, bCheckRange: true);
      bf_write::WriteString(this: buffer, pStr: m_szPathID);
      goto LABEL_10;
    }
  }
  bf_write::WriteUBitLong(this: buffer, curData: v5 + 1, numbits: 2, bCheckRange: true);
LABEL_10:
  CommonPrefix = FindCommonPrefix(pStr: this->m_szFilename);
  v8 = CommonPrefix;
  if ( CommonPrefix == -1 )
  {
    bf_write::WriteUBitLong(this: buffer, curData: 0, numbits: 3, bCheckRange: true);
    bf_write::WriteString(this: buffer, pStr: this->m_szFilename);
  }
  else
  {
    bf_write::WriteUBitLong(this: buffer, curData: CommonPrefix + 1, numbits: 3, bCheckRange: true);
    v10 = &this->m_szFilename[_V_strlen(str: g_MostCommonPrefixes[v8]) + 1];
    bf_write::WriteString(this: buffer, pStr: v10);
  }
  bf_write::WriteUBitLong(this: buffer, curData: this->m_CRC, numbits: 32, bCheckRange: true);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BE510
// Name: public: virtual char const __near * CLC_SplitPlayerConnect::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLC_SplitPlayerConnect::ToString(CLC_SplitPlayerConnect *this)
{
  const char *v1; // eax
  int v3; // [esp-4h] [ebp-4h]

  v1 = (const char *)((int (__thiscall *)(CLC_SplitPlayerConnect *, int))this->GetName)(
                       a1: this,
                       a2: this->m_UserInfo.m_Size);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: %i userinfo vars", v1, v3);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101BE580
// Name: public: CLC_CmdKeyValues::CLC_CmdKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CLC_CmdKeyValues *__thiscall CLC_CmdKeyValues::CLC_CmdKeyValues(CLC_CmdKeyValues *this, KeyValues *pKeyValues)
{
  this->m_bReliable = true;
  this->m_NetChannel = nullptr;
  this->m_pKeyValues = pKeyValues;
  this->__vftable = (CLC_CmdKeyValues_vtbl *)&CLC_CmdKeyValues::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101BE5A0
// Name: public: virtual char const __near * CLC_CmdKeyValues::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLC_CmdKeyValues::GetName(CLC_CmdKeyValues *this)
{
  return "clc_CmdKeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x101BE5B0
// Name: public: virtual bool CLC_CmdKeyValues::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_CmdKeyValues::Process(CLC_CmdKeyValues *this)
{
  return this->m_pMessageHandler->ProcessCmdKeyValues(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x101BE5C0
// Name: public: SVC_CmdKeyValues::SVC_CmdKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
SVC_CmdKeyValues *__thiscall SVC_CmdKeyValues::SVC_CmdKeyValues(SVC_CmdKeyValues *this, KeyValues *pKeyValues)
{
  this->m_bReliable = true;
  this->m_NetChannel = nullptr;
  this->m_pKeyValues = pKeyValues;
  this->__vftable = (SVC_CmdKeyValues_vtbl *)&SVC_CmdKeyValues::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101BE5E0
// Name: public: virtual char const __near * SVC_CmdKeyValues::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_CmdKeyValues::GetName(SVC_CmdKeyValues *this)
{
  return "svc_CmdKeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x101BE5F0
// Name: public: virtual bool SVC_CmdKeyValues::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_CmdKeyValues::Process(SVC_CmdKeyValues *this)
{
  return this->m_pMessageHandler->ProcessCmdKeyValues(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x101BE600
// Name: public: virtual bool SVC_ServerInfo::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_ServerInfo::WriteToBuffer(SVC_ServerInfo *this, bf_write *buffer)
{
  unsigned int v3; // eax
  int m_iCurBit; // ecx
  BOOL m_bIsHLTV; // eax
  int v6; // ecx
  BOOL m_bIsDedicated; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteShort(this: buffer, val: this->m_nProtocol);
  bf_write::WriteLong(this: buffer, val: this->m_nServerCount);
  m_iCurBit = buffer->m_iCurBit;
  m_bIsHLTV = this->m_bIsHLTV;
  if ( m_iCurBit + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bIsHLTV )
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
    else
      buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++buffer->m_iCurBit;
  }
  v6 = buffer->m_iCurBit;
  m_bIsDedicated = this->m_bIsDedicated;
  if ( v6 + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bIsDedicated )
      buffer->m_pData[v6 >> 3] |= 1 << (v6 & 7);
    else
      buffer->m_pData[v6 >> 3] &= ~(1 << (v6 & 7));
    ++buffer->m_iCurBit;
  }
  bf_write::WriteLong(this: buffer, val: this->m_nClientCRC);
  bf_write::WriteLong(this: buffer, val: this->m_nStringTableCRC);
  bf_write::WriteWord(this: buffer, val: this->m_nMaxClasses);
  bf_write::WriteLong(this: buffer, val: this->m_nMapCRC);
  bf_write::WriteByte(this: buffer, val: this->m_nPlayerSlot);
  bf_write::WriteByte(this: buffer, val: this->m_nMaxClients);
  bf_write::WriteFloat(this: buffer, val: this->m_fTickInterval);
  bf_write::WriteChar(this: buffer, val: this->m_cOS);
  bf_write::WriteString(this: buffer, pStr: this->m_szGameDir);
  bf_write::WriteString(this: buffer, pStr: this->m_szMapName);
  bf_write::WriteString(this: buffer, pStr: this->m_szSkyName);
  bf_write::WriteString(this: buffer, pStr: this->m_szHostName);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BE760
// Name: public: virtual bool SVC_BSPDecal::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_BSPDecal::WriteToBuffer(SVC_BSPDecal *this, bf_write *buffer)
{
  unsigned int v3; // eax
  int m_iCurBit; // ecx
  int v5; // edx
  int v6; // ecx
  BOOL m_bLowPriority; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteBitVec3Coord(this: buffer, fa: &this->m_Pos);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nDecalTextureIndex, numbits: 9, bCheckRange: true);
  m_iCurBit = buffer->m_iCurBit;
  v5 = m_iCurBit + 1;
  if ( this->m_nEntityIndex != 0 )
  {
    if ( v5 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++buffer->m_iCurBit;
    }
    bf_write::WriteUBitLong(this: buffer, curData: this->m_nEntityIndex, numbits: 11, bCheckRange: true);
    bf_write::WriteUBitLong(this: buffer, curData: this->m_nModelIndex, numbits: 11, bCheckRange: true);
  }
  else
  {
    if ( v5 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++buffer->m_iCurBit;
    }
  }
  v6 = buffer->m_iCurBit;
  m_bLowPriority = this->m_bLowPriority;
  if ( v6 + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bLowPriority )
    {
      buffer->m_pData[v6 >> 3] |= 1 << (v6 & 7);
      ++buffer->m_iCurBit;
      return !buffer->m_bOverflow;
    }
    buffer->m_pData[v6 >> 3] &= ~(1 << (v6 & 7));
    ++buffer->m_iCurBit;
  }
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BE870
// Name: public: virtual bool SVC_FixAngle::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_FixAngle::WriteToBuffer(SVC_FixAngle *this, bf_write *buffer)
{
  unsigned int v3; // eax
  int m_iCurBit; // ecx
  BOOL m_bRelative; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_iCurBit = buffer->m_iCurBit;
  m_bRelative = this->m_bRelative;
  if ( m_iCurBit + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bRelative )
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
    else
      buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++buffer->m_iCurBit;
  }
  bf_write::WriteBitAngle(this: buffer, fAngle: this->m_Angle.x, numbits: 16);
  bf_write::WriteBitAngle(this: buffer, fAngle: this->m_Angle.y, numbits: 16);
  bf_write::WriteBitAngle(this: buffer, fAngle: this->m_Angle.z, numbits: 16);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BE910
// Name: public: virtual bool SVC_VoiceData::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_VoiceData::ReadFromBuffer(SVC_VoiceData *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  unsigned int v5; // edx
  int v6; // ecx
  int v7; // edi
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  unsigned int v10; // ecx
  const unsigned int *v11; // edx
  unsigned int v12; // esi
  int v13; // eax
  const unsigned int *v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // edi
  unsigned int v17; // edx
  int v18; // ecx
  unsigned int v19; // eax
  unsigned int v20; // edx
  int v21; // ecx
  const unsigned int *v22; // eax
  const unsigned int *v23; // ecx
  unsigned int v24; // ecx
  const unsigned int *v25; // edx
  unsigned int v26; // esi
  int v27; // eax
  const unsigned int *v28; // ecx
  unsigned int v29; // edx
  unsigned int v30; // edi
  unsigned int v31; // edx
  int v32; // ecx
  unsigned int v33; // eax
  int v34; // esi
  int v35; // ecx
  const unsigned int *v36; // eax
  const unsigned int *v37; // ecx
  const unsigned int *v38; // edx
  unsigned int v39; // esi
  int v40; // eax
  const unsigned int *v41; // ecx
  unsigned int v42; // edx
  unsigned int v43; // edi
  int v44; // ecx
  unsigned int v45; // eax
  int v46; // edx
  int v47; // ecx
  int v48; // eax
  const unsigned int *v49; // eax
  const unsigned int *v50; // ecx
  unsigned int v51; // ecx
  const unsigned int *v52; // edx
  unsigned int v53; // esi
  int v54; // eax
  const unsigned int *v55; // ecx
  unsigned int v56; // edx
  unsigned int v57; // edi
  int v58; // esi
  unsigned int v59; // edx
  const unsigned int *m_pData; // eax
  int m_nDataBits; // eax
  int i; // [esp+18h] [ebp+8h]

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 8 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v5 = (unsigned __int8)m_nInBufWord;
    v6 = m_nBitsAvail - 8;
    v7 = 0;
    buffer->m_nBitsAvail = v6;
    if ( v6 != 0 )
    {
      buffer->m_nInBufWord = m_nInBufWord >> 8;
      m_nInBufWord = (unsigned __int8)m_nInBufWord;
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_pDataIn = m_pDataIn + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        m_nInBufWord = v5;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v10 = *m_pDataIn;
          buffer->m_pDataIn = m_pDataIn + 1;
          buffer->m_nInBufWord = v10;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        m_nInBufWord = v5;
      }
    }
    goto LABEL_20;
  }
  v11 = buffer->m_pBufferEnd;
  v12 = buffer->m_nInBufWord;
  v13 = 8 - m_nBitsAvail;
  v14 = buffer->m_pDataIn;
  if ( v14 == v11 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_15:
    buffer->m_pDataIn = v14 + 1;
    goto LABEL_16;
  }
  if ( v14 <= v11 )
  {
    buffer->m_nInBufWord = *v14;
    goto LABEL_15;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_16:
  if ( buffer->m_bOverflow )
  {
    m_nInBufWord = 0;
  }
  else
  {
    v15 = buffer->m_nInBufWord;
    v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v13;
    v17 = v15 >> v13;
    m_nInBufWord = v16 | v12;
    buffer->m_nInBufWord = v17;
  }
  v7 = 0;
LABEL_20:
  this->m_nFromClient = m_nInBufWord;
  v18 = buffer->m_nBitsAvail;
  if ( v18 < 8 )
  {
    v25 = buffer->m_pBufferEnd;
    v26 = buffer->m_nInBufWord;
    v27 = 8 - v18;
    v28 = buffer->m_pDataIn;
    if ( v28 == v25 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v28 > v25 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_35;
      }
      buffer->m_nInBufWord = *v28;
    }
    buffer->m_pDataIn = v28 + 1;
LABEL_35:
    if ( buffer->m_bOverflow )
    {
      v19 = 0;
    }
    else
    {
      v29 = buffer->m_nInBufWord;
      v30 = (v29 & CBitBuffer::s_nMaskTable[v27]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v27;
      v31 = v29 >> v27;
      v19 = v30 | v26;
      v7 = 0;
      buffer->m_nInBufWord = v31;
    }
    goto LABEL_38;
  }
  v19 = buffer->m_nInBufWord;
  v20 = (unsigned __int8)v19;
  v21 = v18 - 8;
  buffer->m_nBitsAvail = v21;
  if ( v21 != 0 )
  {
    buffer->m_nInBufWord = v19 >> 8;
    v19 = (unsigned __int8)v19;
  }
  else
  {
    v22 = buffer->m_pDataIn;
    v23 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v22 == v23 )
    {
      buffer->m_pDataIn = v22 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v19 = v20;
    }
    else
    {
      if ( v22 <= v23 )
      {
        v24 = *v22;
        buffer->m_pDataIn = v22 + 1;
        buffer->m_nInBufWord = v24;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v19 = v20;
    }
  }
LABEL_38:
  this->m_bProximity = v19 != 0;
  v32 = buffer->m_nBitsAvail;
  if ( v32 < 16 )
  {
    v38 = buffer->m_pBufferEnd;
    v39 = buffer->m_nInBufWord;
    v40 = 16 - v32;
    v41 = buffer->m_pDataIn;
    if ( v41 == v38 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v41 > v38 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_52;
      }
      buffer->m_nInBufWord = *v41;
    }
    buffer->m_pDataIn = v41 + 1;
LABEL_52:
    if ( buffer->m_bOverflow )
    {
      v34 = 0;
    }
    else
    {
      v42 = buffer->m_nInBufWord;
      v43 = (v42 & CBitBuffer::s_nMaskTable[v40]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v40;
      v34 = v43 | v39;
      v7 = 0;
      buffer->m_nInBufWord = v42 >> v40;
    }
    goto LABEL_55;
  }
  v33 = buffer->m_nInBufWord;
  v34 = (unsigned __int16)v33;
  v35 = v32 - 16;
  buffer->m_nBitsAvail = v35;
  if ( v35 != 0 )
  {
    buffer->m_nInBufWord = HIWORD(v33);
  }
  else
  {
    v36 = buffer->m_pDataIn;
    v37 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v36 == v37 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v36 + 1;
    }
    else if ( v36 <= v37 )
    {
      buffer->m_nInBufWord = *v36;
      buffer->m_pDataIn = v36 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
LABEL_55:
  this->m_nLength = v34;
  if ( NET_IsDedicatedForXbox() )
    this->m_xuid = CBitRead::ReadLongLong(this: buffer);
  i = 0;
  do
  {
    v44 = buffer->m_nBitsAvail;
    if ( v44 < 1 )
    {
      v52 = buffer->m_pBufferEnd;
      v53 = buffer->m_nInBufWord;
      v54 = 1 - v44;
      v55 = buffer->m_pDataIn;
      if ( v55 == v52 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_bOverflow = true;
      }
      else
      {
        if ( v55 > v52 )
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
          goto LABEL_73;
        }
        buffer->m_nInBufWord = *v55;
      }
      buffer->m_pDataIn = v55 + 1;
LABEL_73:
      if ( buffer->m_bOverflow )
      {
        v48 = 0;
      }
      else
      {
        v56 = buffer->m_nInBufWord;
        v57 = (v56 & CBitBuffer::s_nMaskTable[v54]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v54;
        v58 = v57 | v53;
        v7 = i;
        v59 = v56 >> v54;
        v48 = v58;
        buffer->m_nInBufWord = v59;
      }
      goto LABEL_76;
    }
    v45 = buffer->m_nInBufWord;
    v46 = v45 & 1;
    v47 = v44 - 1;
    buffer->m_nBitsAvail = v47;
    if ( v47 != 0 )
    {
      buffer->m_nInBufWord = v45 >> 1;
      v48 = v45 & 1;
    }
    else
    {
      v49 = buffer->m_pDataIn;
      v50 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v49 == v50 )
      {
        buffer->m_pDataIn = v49 + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        v48 = v46;
      }
      else
      {
        if ( v49 <= v50 )
        {
          v51 = *v49;
          buffer->m_pDataIn = v49 + 1;
          buffer->m_nInBufWord = v51;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v48 = v46;
      }
    }
LABEL_76:
    this->m_bAudible[v7++] = v48 != 0;
    i = v7;
  }
  while ( v7 < 2 );
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: this->m_nLength);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: this->m_nLength + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101BED50
// Name: public: virtual bool NET_Tick::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall NET_Tick::WriteToBuffer(NET_Tick *this, bf_write *buffer)
{
  unsigned int v3; // eax
  signed int v4; // eax
  signed int v5; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteLong(this: buffer, val: this->m_nTick);
  v4 = (int)(float)(this->m_flHostFrameTime * 100000.0);
  if ( v4 >= 0 )
  {
    if ( v4 > 0xFFFF )
      v4 = 0xFFFF;
  }
  else
  {
    v4 = 0;
  }
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 16, bCheckRange: true);
  v5 = (int)(float)(this->m_flHostFrameTimeStdDeviation * 100000.0);
  if ( v5 >= 0 )
  {
    if ( v5 > 0xFFFF )
      v5 = 0xFFFF;
  }
  else
  {
    v5 = 0;
  }
  bf_write::WriteUBitLong(this: buffer, curData: v5, numbits: 16, bCheckRange: true);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BEDF0
// Name: public: NET_SplitScreenUser::NET_SplitScreenUser(void)
// Source: json
//------------------------------------------------------------------------------
NET_SplitScreenUser *__thiscall NET_SplitScreenUser::NET_SplitScreenUser(NET_SplitScreenUser *this)
{
  this->m_bReliable = true;
  this->m_NetChannel = nullptr;
  this->__vftable = (NET_SplitScreenUser_vtbl *)&NET_SplitScreenUser::`vftable';
  this->m_nSlot = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101BEE10
// Name: public: virtual char const __near * NET_SplitScreenUser::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall NET_SplitScreenUser::GetName(NET_SplitScreenUser *this)
{
  return "net_SplitScreenUser";
}

//------------------------------------------------------------------------------
// Address: 0x101BEE20
// Name: public: virtual bool NET_SplitScreenUser::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NET_SplitScreenUser::Process(NET_SplitScreenUser *this)
{
  return this->m_pMessageHandler->ProcessSplitScreenUser(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x101BEE30
// Name: public: NET_SplitScreenUser::NET_SplitScreenUser(int)
// Source: json
//------------------------------------------------------------------------------
NET_SplitScreenUser *__thiscall NET_SplitScreenUser::NET_SplitScreenUser(NET_SplitScreenUser *this, int slot)
{
  this->m_bReliable = true;
  this->m_NetChannel = nullptr;
  this->__vftable = (NET_SplitScreenUser_vtbl *)&NET_SplitScreenUser::`vftable';
  this->m_nSlot = slot;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101BEE60
// Name: public: virtual bool SVC_UserMessage::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_UserMessage::ReadFromBuffer(SVC_UserMessage *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // ecx
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  unsigned int v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx
  int v16; // ecx
  unsigned int v17; // edx
  int v18; // esi
  int v19; // ecx
  int v20; // ebx
  const unsigned int *v21; // ecx
  const unsigned int *v22; // edx
  unsigned int v23; // edx
  const unsigned int *v24; // esi
  unsigned int v25; // edi
  int v26; // edx
  const unsigned int *v27; // ecx
  unsigned int v28; // esi
  unsigned int v29; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v12 = 8 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_16;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( buffer->m_bOverflow )
    {
      v6 = 0;
    }
    else
    {
      v14 = buffer->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v12;
      v6 = v15 | m_nInBufWord;
      buffer->m_nInBufWord = v14 >> v12;
    }
    goto LABEL_19;
  }
  v3 = buffer->m_nInBufWord;
  v4 = (unsigned __int8)v3;
  v5 = m_nBitsAvail - 8;
  buffer->m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    buffer->m_nInBufWord = v3 >> 8;
    v6 = (unsigned __int8)v3;
  }
  else
  {
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      buffer->m_pDataIn = v7 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v6 = v4;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v9 = *v7;
        buffer->m_pDataIn = v7 + 1;
        buffer->m_nInBufWord = v9;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v6 = v4;
    }
  }
LABEL_19:
  this->m_nMsgType = v6;
  v16 = buffer->m_nBitsAvail;
  if ( v16 >= 12 )
  {
    v17 = buffer->m_nInBufWord;
    v18 = v17 & 0xFFF;
    v19 = v16 - 12;
    buffer->m_nBitsAvail = v19;
    if ( v19 != 0 )
    {
      buffer->m_nInBufWord = v17 >> 12;
      v20 = v17 & 0xFFF;
    }
    else
    {
      v21 = buffer->m_pDataIn;
      v22 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v21 == v22 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v21 + 1;
        v20 = v18;
      }
      else
      {
        if ( v21 <= v22 )
        {
          v23 = *v21;
          buffer->m_pDataIn = v21 + 1;
          buffer->m_nInBufWord = v23;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v20 = v18;
      }
    }
    goto LABEL_37;
  }
  v24 = buffer->m_pBufferEnd;
  v25 = buffer->m_nInBufWord;
  v26 = 12 - v16;
  v27 = buffer->m_pDataIn;
  if ( v27 == v24 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v27 > v24 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_34;
    }
    buffer->m_nInBufWord = *v27;
  }
  buffer->m_pDataIn = v27 + 1;
LABEL_34:
  if ( buffer->m_bOverflow )
  {
    v20 = 0;
  }
  else
  {
    v28 = buffer->m_nInBufWord;
    v29 = (v28 & CBitBuffer::s_nMaskTable[v26]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v26;
    v20 = v25 | v29;
    buffer->m_nInBufWord = v28 >> v26;
  }
LABEL_37:
  this->m_nLength = v20;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v20);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v20 + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101BF090
// Name: public: virtual bool SVC_SetPause::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_SetPause::WriteToBuffer(SVC_SetPause *this, bf_write *buffer)
{
  unsigned int v3; // eax
  int m_iCurBit; // ecx
  BOOL m_bPaused; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_iCurBit = buffer->m_iCurBit;
  m_bPaused = this->m_bPaused;
  if ( m_iCurBit + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bPaused )
    {
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++buffer->m_iCurBit;
      return !buffer->m_bOverflow;
    }
    buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++buffer->m_iCurBit;
  }
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101BF110
// Name: public: virtual bool SVC_UpdateStringTable::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_UpdateStringTable::WriteToBuffer(SVC_UpdateStringTable *this, bf_write *buffer)
{
  unsigned int v3; // eax
  int v4; // eax
  int m_iCurBit; // ecx

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  this->m_nLength = this->m_DataOut.m_iCurBit;
  v4 = Q_log2(val: 0x20u);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nTableID, numbits: v4, bCheckRange: true);
  m_iCurBit = buffer->m_iCurBit;
  if ( this->m_nChangedEntries == 1 )
  {
    if ( m_iCurBit + 1 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++buffer->m_iCurBit;
    }
  }
  else
  {
    if ( m_iCurBit + 1 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++buffer->m_iCurBit;
    }
    bf_write::WriteWord(this: buffer, val: this->m_nChangedEntries);
  }
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 20, bCheckRange: true);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BF1E0
// Name: public: virtual bool SVC_UpdateStringTable::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_UpdateStringTable::ReadFromBuffer(SVC_UpdateStringTable *this, bf_read *buffer)
{
  signed int v2; // eax
  int m_nBitsAvail; // ecx
  unsigned int v4; // esi
  unsigned int v5; // edi
  int v6; // ecx
  const unsigned int *v7; // eax
  const unsigned int *v8; // ecx
  int v9; // ebx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  const unsigned int *m_pDataIn; // ecx
  unsigned int v13; // eax
  int v14; // ecx
  const unsigned int *v16; // eax
  const unsigned int *v17; // esi
  int v18; // ecx
  unsigned int v19; // eax
  int v20; // edi
  int v21; // ecx
  const unsigned int *v22; // eax
  const unsigned int *v23; // ecx
  SVC_UpdateStringTable *v24; // eax
  unsigned int v25; // ecx
  const unsigned int *v26; // esi
  unsigned int v27; // edi
  int v28; // eax
  const unsigned int *v29; // ecx
  unsigned int v30; // esi
  unsigned int v31; // ebx
  int v32; // edi
  int v33; // ecx
  unsigned int v34; // eax
  int v35; // esi
  int v36; // ecx
  const unsigned int *v37; // eax
  const unsigned int *v38; // ecx
  const unsigned int *v39; // esi
  unsigned int v40; // edi
  int v41; // eax
  const unsigned int *v42; // ecx
  unsigned int v43; // esi
  unsigned int v44; // ebx
  const unsigned int *m_pData; // eax
  int m_nDataBits; // eax

  v2 = Q_log2(val: 0x20u);
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < v2 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v2 -= m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_14:
        if ( buffer->m_bOverflow )
        {
          v5 = 0;
          goto LABEL_18;
        }
        v4 = buffer->m_nInBufWord;
        v5 = ((v4 & CBitBuffer::s_nMaskTable[v2]) << buffer->m_nBitsAvail) | m_nInBufWord;
        buffer->m_nBitsAvail = 32 - v2;
LABEL_17:
        buffer->m_nInBufWord = v4 >> v2;
        goto LABEL_18;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
    goto LABEL_14;
  }
  v4 = buffer->m_nInBufWord;
  v5 = v4 & CBitBuffer::s_nMaskTable[v2];
  v6 = m_nBitsAvail - v2;
  buffer->m_nBitsAvail = v6;
  if ( v6 != 0 )
    goto LABEL_17;
  v7 = buffer->m_pDataIn;
  v8 = buffer->m_pBufferEnd;
  buffer->m_nBitsAvail = 32;
  if ( v7 == v8 )
  {
    v9 = 0;
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_pDataIn = v7 + 1;
    goto LABEL_19;
  }
  if ( v7 <= v8 )
  {
    buffer->m_nInBufWord = *v7;
    buffer->m_pDataIn = v7 + 1;
  }
  else
  {
    buffer->m_bOverflow = true;
    buffer->m_nInBufWord = 0;
  }
LABEL_18:
  v9 = 0;
LABEL_19:
  this->m_nTableID = v5;
  v13 = buffer->m_nInBufWord;
  v14 = v13 & 1;
  if ( buffer->m_nBitsAvail-- == 1 )
  {
    v16 = buffer->m_pDataIn;
    v17 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v16 == v17 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v16 + 1;
    }
    else if ( v16 <= v17 )
    {
      buffer->m_nInBufWord = *v16;
      buffer->m_pDataIn = v16 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v13 >> 1;
  }
  if ( v14 == 0 )
  {
    this->m_nChangedEntries = 1;
    goto LABEL_46;
  }
  v18 = buffer->m_nBitsAvail;
  if ( v18 < 16 )
  {
    v26 = buffer->m_pBufferEnd;
    v27 = buffer->m_nInBufWord;
    v28 = 16 - v18;
    v29 = buffer->m_pDataIn;
    if ( v29 == v26 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v29 > v26 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_42;
      }
      buffer->m_nInBufWord = *v29;
    }
    buffer->m_pDataIn = v29 + 1;
LABEL_42:
    if ( buffer->m_bOverflow )
    {
      this->m_nChangedEntries = 0;
    }
    else
    {
      v30 = buffer->m_nInBufWord;
      v31 = (v30 & CBitBuffer::s_nMaskTable[v28]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v28;
      v32 = v31 | v27;
      v9 = 0;
      buffer->m_nInBufWord = v30 >> v28;
      this->m_nChangedEntries = v32;
    }
    goto LABEL_46;
  }
  v19 = buffer->m_nInBufWord;
  v20 = (unsigned __int16)v19;
  v21 = v18 - 16;
  buffer->m_nBitsAvail = v21;
  if ( v21 != 0 )
  {
    buffer->m_nInBufWord = HIWORD(v19);
    this->m_nChangedEntries = (unsigned __int16)v19;
  }
  else
  {
    v22 = buffer->m_pDataIn;
    v23 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v22 == v23 )
    {
      buffer->m_pDataIn = v22 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      this->m_nChangedEntries = v20;
    }
    else
    {
      if ( v22 <= v23 )
      {
        v25 = *v22;
        buffer->m_pDataIn = v22 + 1;
        v24 = this;
        buffer->m_nInBufWord = v25;
      }
      else
      {
        v24 = this;
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v24->m_nChangedEntries = v20;
    }
  }
LABEL_46:
  v33 = buffer->m_nBitsAvail;
  if ( v33 >= 20 )
  {
    v34 = buffer->m_nInBufWord;
    v35 = v34 & 0xFFFFF;
    v36 = v33 - 20;
    buffer->m_nBitsAvail = v36;
    if ( v36 != 0 )
    {
      buffer->m_nInBufWord = v34 >> 20;
      v9 = v34 & 0xFFFFF;
    }
    else
    {
      v37 = buffer->m_pDataIn;
      v38 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v37 == v38 )
      {
        buffer->m_nInBufWord = 0;
        buffer->m_nBitsAvail = 1;
        buffer->m_pDataIn = v37 + 1;
        v9 = v35;
      }
      else
      {
        if ( v37 <= v38 )
        {
          buffer->m_nInBufWord = *v37;
          buffer->m_pDataIn = v37 + 1;
        }
        else
        {
          buffer->m_nInBufWord = 0;
          buffer->m_bOverflow = true;
        }
        v9 = v35;
      }
    }
    goto LABEL_63;
  }
  v39 = buffer->m_pBufferEnd;
  v40 = buffer->m_nInBufWord;
  v41 = 20 - v33;
  v42 = buffer->m_pDataIn;
  if ( v42 == v39 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v42 > v39 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_61;
    }
    buffer->m_nInBufWord = *v42;
  }
  buffer->m_pDataIn = v42 + 1;
LABEL_61:
  if ( !buffer->m_bOverflow )
  {
    v43 = buffer->m_nInBufWord;
    v44 = (v43 & CBitBuffer::s_nMaskTable[v41]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v41;
    v9 = v40 | v44;
    buffer->m_nInBufWord = v43 >> v41;
  }
LABEL_63:
  this->m_nLength = v9;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v9);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v9 + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101BF560
// Name: public: SVC_CreateStringTable::SVC_CreateStringTable(void)
// Source: json
//------------------------------------------------------------------------------
SVC_CreateStringTable *__thiscall SVC_CreateStringTable::SVC_CreateStringTable(SVC_CreateStringTable *this)
{
  this->m_bReliable = true;
  this->m_NetChannel = nullptr;
  this->__vftable = (SVC_CreateStringTable_vtbl *)&SVC_CreateStringTable::`vftable';
  this->m_DataIn.m_bOverflow = false;
  this->m_DataIn.m_pDebugName = nullptr;
  this->m_DataIn.m_nDataBits = -1;
  this->m_DataIn.m_nDataBytes = 0;
  bf_write::bf_write(this: &this->m_DataOut);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101BF590
// Name: public: virtual char const __near * SVC_CreateStringTable::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_CreateStringTable::GetName(SVC_CreateStringTable *this)
{
  return "svc_CreateStringTable";
}

//------------------------------------------------------------------------------
// Address: 0x101BF5A0
// Name: public: virtual unsigned int SVC_CreateStringTable::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SVC_CreateStringTable::GetSize(SVC_CreateStringTable *this)
{
  return 368;
}

//------------------------------------------------------------------------------
// Address: 0x101BF5B0
// Name: public: virtual bool SVC_CreateStringTable::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_CreateStringTable::WriteToBuffer(SVC_CreateStringTable *this, bf_write *buffer)
{
  unsigned int v3; // eax
  unsigned int v4; // eax
  int m_iCurBit; // ecx
  BOOL m_bUserDataFixedSize; // eax
  int v7; // ecx
  BOOL m_bDataCompressed; // eax
  const char *m_szTableName; // [esp-4h] [ebp-10h]

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_szTableName = this->m_szTableName;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  bf_write::WriteString(this: buffer, pStr: m_szTableName);
  bf_write::WriteWord(this: buffer, val: this->m_nMaxEntries);
  v4 = Q_log2(val: this->m_nMaxEntries);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nNumEntries, numbits: v4 + 1, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 20, bCheckRange: true);
  m_iCurBit = buffer->m_iCurBit;
  m_bUserDataFixedSize = this->m_bUserDataFixedSize;
  if ( m_iCurBit + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bUserDataFixedSize )
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
    else
      buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++buffer->m_iCurBit;
  }
  if ( this->m_bUserDataFixedSize )
  {
    bf_write::WriteUBitLong(this: buffer, curData: this->m_nUserDataSize, numbits: 12, bCheckRange: true);
    bf_write::WriteUBitLong(this: buffer, curData: this->m_nUserDataSizeBits, numbits: 4, bCheckRange: true);
  }
  v7 = buffer->m_iCurBit;
  m_bDataCompressed = this->m_bDataCompressed;
  if ( v7 + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bDataCompressed )
      buffer->m_pData[v7 >> 3] |= 1 << (v7 & 7);
    else
      buffer->m_pData[v7 >> 3] &= ~(1 << (v7 & 7));
    ++buffer->m_iCurBit;
  }
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nFlags, numbits: 1, bCheckRange: true);
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BF6F0
// Name: public: virtual bool SVC_CreateStringTable::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_CreateStringTable::ReadFromBuffer(SVC_CreateStringTable *this, bf_read *buffer)
{
  SVC_CreateStringTable *v2; // esi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  unsigned int v5; // eax
  int v6; // ecx
  unsigned int v7; // edx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  const unsigned int *v10; // edx
  unsigned int v11; // esi
  int v12; // eax
  const unsigned int *v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // edi
  unsigned int v16; // eax
  int v17; // ecx
  int v18; // eax
  unsigned int v19; // edx
  unsigned int v20; // esi
  int v21; // ecx
  unsigned int v22; // edx
  const unsigned int *v23; // eax
  const unsigned int *v24; // ecx
  const unsigned int *v25; // edx
  unsigned int v26; // esi
  int v27; // eax
  const unsigned int *v28; // ecx
  int v29; // eax
  unsigned int v30; // edx
  unsigned int v31; // edi
  int v32; // ecx
  unsigned int v33; // eax
  int v34; // edx
  int v35; // ecx
  int v36; // eax
  const unsigned int *v37; // eax
  const unsigned int *v38; // ecx
  unsigned int v39; // ecx
  const unsigned int *v40; // edx
  unsigned int v41; // esi
  int v42; // eax
  const unsigned int *v43; // ecx
  unsigned int v44; // edx
  unsigned int v45; // edi
  unsigned int v46; // edx
  SVC_CreateStringTable *v47; // esi
  unsigned int v48; // eax
  int v49; // ecx
  bool v50; // zf
  const unsigned int *v51; // eax
  const unsigned int *v52; // edx
  int v53; // ecx
  unsigned int v54; // eax
  int v55; // edx
  int v56; // ecx
  int v57; // eax
  const unsigned int *v58; // eax
  const unsigned int *v59; // ecx
  unsigned int v60; // ecx
  const unsigned int *v61; // edx
  unsigned int v62; // esi
  int v63; // eax
  const unsigned int *v64; // ecx
  unsigned int v65; // edx
  unsigned int v66; // edi
  unsigned int v67; // edx
  int v68; // ecx
  unsigned int v69; // eax
  int v70; // esi
  int v71; // ecx
  const unsigned int *v72; // eax
  const unsigned int *v73; // ecx
  SVC_CreateStringTable *v74; // edx
  const unsigned int *v75; // edx
  unsigned int v76; // esi
  int v77; // eax
  const unsigned int *v78; // ecx
  unsigned int v79; // edx
  unsigned int v80; // edi
  unsigned int v81; // eax
  int v82; // ecx
  const unsigned int *v83; // eax
  const unsigned int *v84; // edx
  int v85; // ecx
  unsigned int v86; // eax
  int v87; // edx
  int v88; // ecx
  int v89; // ecx
  const unsigned int *v90; // eax
  const unsigned int *v91; // ecx
  const unsigned int *v92; // edx
  unsigned int v93; // esi
  int v94; // eax
  const unsigned int *v95; // ecx
  unsigned int v96; // edx
  unsigned int v97; // edi
  int m_nLength; // edx
  const unsigned int *m_pData; // eax

  v2 = this;
  this->m_szTableName = this->m_szTableNameBuffer;
  CBitRead::ReadString(this: buffer, pStr: this->m_szTableNameBuffer, maxLen: 256, bLine: false, pOutNumChars: nullptr);
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 16 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v5 = (unsigned __int16)m_nInBufWord;
    v6 = m_nBitsAvail - 16;
    buffer->m_nBitsAvail = v6;
    if ( v6 != 0 )
    {
      v7 = HIWORD(m_nInBufWord);
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = m_pDataIn + 1;
        goto LABEL_19;
      }
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_19;
      }
      v7 = *m_pDataIn;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    goto LABEL_18;
  }
  v10 = buffer->m_pBufferEnd;
  v11 = buffer->m_nInBufWord;
  v12 = 16 - m_nBitsAvail;
  v13 = buffer->m_pDataIn;
  if ( v13 == v10 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_14:
    buffer->m_pDataIn = v13 + 1;
    goto LABEL_15;
  }
  if ( v13 <= v10 )
  {
    buffer->m_nInBufWord = *v13;
    goto LABEL_14;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_15:
  if ( buffer->m_bOverflow )
  {
    v2 = this;
    v5 = 0;
    goto LABEL_19;
  }
  v14 = buffer->m_nInBufWord;
  v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
  buffer->m_nBitsAvail = 32 - v12;
  v7 = v14 >> v12;
  v5 = v15 | v11;
  v2 = this;
LABEL_18:
  buffer->m_nInBufWord = v7;
LABEL_19:
  v2->m_nMaxEntries = v5;
  v16 = Q_log2(val: v5);
  v17 = buffer->m_nBitsAvail;
  v18 = v16 + 1;
  if ( v17 < v18 )
  {
    v25 = buffer->m_pBufferEnd;
    v26 = buffer->m_nInBufWord;
    v27 = v18 - v17;
    v28 = buffer->m_pDataIn;
    if ( v28 == v25 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v28 > v25 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_33:
        if ( buffer->m_bOverflow )
        {
          v29 = 0;
          goto LABEL_38;
        }
        v30 = buffer->m_nInBufWord;
        v31 = (v30 & CBitBuffer::s_nMaskTable[v27]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v27;
        v20 = v31 | v26;
        v22 = v30 >> v27;
        goto LABEL_36;
      }
      buffer->m_nInBufWord = *v28;
    }
    buffer->m_pDataIn = v28 + 1;
    goto LABEL_33;
  }
  v19 = buffer->m_nInBufWord;
  v20 = v19 & CBitBuffer::s_nMaskTable[v18];
  v21 = v17 - v18;
  buffer->m_nBitsAvail = v21;
  if ( v21 != 0 )
  {
    v22 = v19 >> v18;
LABEL_36:
    buffer->m_nInBufWord = v22;
    goto LABEL_37;
  }
  v23 = buffer->m_pDataIn;
  v24 = buffer->m_pBufferEnd;
  buffer->m_nBitsAvail = 32;
  if ( v23 == v24 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_pDataIn = v23 + 1;
  }
  else
  {
    if ( v23 <= v24 )
    {
      v22 = *v23;
      buffer->m_pDataIn = v23 + 1;
      goto LABEL_36;
    }
    buffer->m_bOverflow = true;
    buffer->m_nInBufWord = 0;
  }
LABEL_37:
  v29 = v20;
LABEL_38:
  this->m_nNumEntries = v29;
  v32 = buffer->m_nBitsAvail;
  if ( v32 < 20 )
  {
    v40 = buffer->m_pBufferEnd;
    v41 = buffer->m_nInBufWord;
    v42 = 20 - v32;
    v43 = buffer->m_pDataIn;
    if ( v43 == v40 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v43 > v40 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_53;
      }
      buffer->m_nInBufWord = *v43;
    }
    buffer->m_pDataIn = v43 + 1;
LABEL_53:
    if ( buffer->m_bOverflow )
    {
      v36 = 0;
    }
    else
    {
      v44 = buffer->m_nInBufWord;
      v45 = (v44 & CBitBuffer::s_nMaskTable[v42]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v42;
      v46 = v44 >> v42;
      v36 = v45 | v41;
      buffer->m_nInBufWord = v46;
    }
    goto LABEL_56;
  }
  v33 = buffer->m_nInBufWord;
  v34 = v33 & 0xFFFFF;
  v35 = v32 - 20;
  buffer->m_nBitsAvail = v35;
  if ( v35 != 0 )
  {
    buffer->m_nInBufWord = v33 >> 20;
    v36 = v33 & 0xFFFFF;
  }
  else
  {
    v37 = buffer->m_pDataIn;
    v38 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v37 == v38 )
    {
      buffer->m_pDataIn = v37 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v36 = v34;
    }
    else
    {
      if ( v37 <= v38 )
      {
        v39 = *v37;
        buffer->m_pDataIn = v37 + 1;
        buffer->m_nInBufWord = v39;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v36 = v34;
    }
  }
LABEL_56:
  v47 = this;
  this->m_nLength = v36;
  v48 = buffer->m_nInBufWord;
  v49 = v48 & 1;
  v50 = buffer->m_nBitsAvail-- == 1;
  if ( v50 )
  {
    v51 = buffer->m_pDataIn;
    v52 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v51 == v52 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v51 + 1;
    }
    else if ( v51 <= v52 )
    {
      buffer->m_nInBufWord = *v51;
      buffer->m_pDataIn = v51 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v48 >> 1;
  }
  this->m_bUserDataFixedSize = v49 != 0;
  if ( v49 == 0 )
  {
    this->m_nUserDataSize = 0;
    this->m_nUserDataSizeBits = 0;
    goto LABEL_102;
  }
  v53 = buffer->m_nBitsAvail;
  if ( v53 >= 12 )
  {
    v54 = buffer->m_nInBufWord;
    v55 = v54 & 0xFFF;
    v56 = v53 - 12;
    buffer->m_nBitsAvail = v56;
    if ( v56 != 0 )
    {
      buffer->m_nInBufWord = v54 >> 12;
      v57 = v54 & 0xFFF;
    }
    else
    {
      v58 = buffer->m_pDataIn;
      v59 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v58 == v59 )
      {
        buffer->m_pDataIn = v58 + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        v57 = v55;
      }
      else
      {
        if ( v58 <= v59 )
        {
          v60 = *v58;
          buffer->m_pDataIn = v58 + 1;
          buffer->m_nInBufWord = v60;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v57 = v55;
      }
    }
    goto LABEL_83;
  }
  v61 = buffer->m_pBufferEnd;
  v62 = buffer->m_nInBufWord;
  v63 = 12 - v53;
  v64 = buffer->m_pDataIn;
  if ( v64 == v61 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_78:
    buffer->m_pDataIn = v64 + 1;
    goto LABEL_79;
  }
  if ( v64 <= v61 )
  {
    buffer->m_nInBufWord = *v64;
    goto LABEL_78;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_79:
  if ( buffer->m_bOverflow )
  {
    v57 = 0;
  }
  else
  {
    v65 = buffer->m_nInBufWord;
    v66 = (v65 & CBitBuffer::s_nMaskTable[v63]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v63;
    v67 = v65 >> v63;
    v57 = v66 | v62;
    buffer->m_nInBufWord = v67;
  }
  v47 = this;
LABEL_83:
  v47->m_nUserDataSize = v57;
  v68 = buffer->m_nBitsAvail;
  if ( v68 < 4 )
  {
    v75 = buffer->m_pBufferEnd;
    v76 = buffer->m_nInBufWord;
    v77 = 4 - v68;
    v78 = buffer->m_pDataIn;
    if ( v78 == v75 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v78 > v75 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_98;
      }
      buffer->m_nInBufWord = *v78;
    }
    buffer->m_pDataIn = v78 + 1;
LABEL_98:
    if ( buffer->m_bOverflow )
    {
      this->m_nUserDataSizeBits = 0;
    }
    else
    {
      v79 = buffer->m_nInBufWord;
      v80 = (v79 & CBitBuffer::s_nMaskTable[v77]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v77;
      buffer->m_nInBufWord = v79 >> v77;
      this->m_nUserDataSizeBits = v80 | v76;
    }
    goto LABEL_102;
  }
  v69 = buffer->m_nInBufWord;
  v70 = v69 & 0xF;
  v71 = v68 - 4;
  buffer->m_nBitsAvail = v71;
  if ( v71 != 0 )
  {
    buffer->m_nInBufWord = v69 >> 4;
    this->m_nUserDataSizeBits = v70;
  }
  else
  {
    v72 = buffer->m_pDataIn;
    v73 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v72 == v73 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v72 + 1;
      this->m_nUserDataSizeBits = v70;
    }
    else
    {
      if ( v72 <= v73 )
      {
        buffer->m_nInBufWord = *v72;
        v74 = this;
        buffer->m_pDataIn = v72 + 1;
      }
      else
      {
        v74 = this;
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v74->m_nUserDataSizeBits = v70;
    }
  }
LABEL_102:
  v81 = buffer->m_nInBufWord;
  v82 = v81 & 1;
  v50 = buffer->m_nBitsAvail-- == 1;
  if ( v50 )
  {
    v83 = buffer->m_pDataIn;
    v84 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v83 == v84 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v83 + 1;
    }
    else if ( v83 <= v84 )
    {
      buffer->m_nInBufWord = *v83;
      buffer->m_pDataIn = v83 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v81 >> 1;
  }
  this->m_bDataCompressed = v82 != 0;
  v85 = buffer->m_nBitsAvail;
  if ( v85 >= 1 )
  {
    v86 = buffer->m_nInBufWord;
    v87 = v86 & 1;
    v88 = v85 - 1;
    buffer->m_nBitsAvail = v88;
    if ( v88 != 0 )
    {
      buffer->m_nInBufWord = v86 >> 1;
      v89 = v86 & 1;
    }
    else
    {
      v90 = buffer->m_pDataIn;
      v91 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v90 == v91 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v90 + 1;
        v89 = v87;
      }
      else
      {
        if ( v90 <= v91 )
        {
          buffer->m_nInBufWord = *v90;
          buffer->m_pDataIn = v90 + 1;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v89 = v87;
      }
    }
    goto LABEL_127;
  }
  v92 = buffer->m_pBufferEnd;
  v93 = buffer->m_nInBufWord;
  v94 = 1 - v85;
  v95 = buffer->m_pDataIn;
  if ( v95 == v92 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v95 > v92 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_124;
    }
    buffer->m_nInBufWord = *v95;
  }
  buffer->m_pDataIn = v95 + 1;
LABEL_124:
  if ( buffer->m_bOverflow )
  {
    v89 = 0;
  }
  else
  {
    v96 = buffer->m_nInBufWord;
    v97 = (v96 & CBitBuffer::s_nMaskTable[v94]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v94;
    v89 = v97 | v93;
    buffer->m_nInBufWord = v96 >> v94;
  }
LABEL_127:
  m_nLength = this->m_nLength;
  this->m_nFlags = v89;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData != nullptr )
  {
    m_pData = (const unsigned int *)(32 * (buffer->m_pDataIn - m_pData)
                                   - buffer->m_nBitsAvail
                                   + 8 * (buffer->m_nDataBytes & 3));
    if ( (int)m_pData >= buffer->m_nDataBits )
      m_pData = (const unsigned int *)buffer->m_nDataBits;
  }
  return CBitRead::Seek(this: buffer, nPosition: (int)m_pData + m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BFD60
// Name: public: virtual bool SVC_Sounds::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_Sounds::WriteToBuffer(SVC_Sounds *this, bf_write *buffer)
{
  SVC_Sounds_vtbl *v3; // edx
  unsigned int v4; // eax
  int m_iCurBit; // ecx
  int v6; // edx

  v3 = this->__vftable;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  v4 = ((int (*)(void))v3->GetType)();
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 6, bCheckRange: true);
  m_iCurBit = buffer->m_iCurBit;
  v6 = m_iCurBit + 1;
  if ( this->m_bReliableSound )
  {
    if ( v6 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++buffer->m_iCurBit;
    }
    bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 8, bCheckRange: true);
  }
  else
  {
    if ( v6 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++buffer->m_iCurBit;
    }
    bf_write::WriteUBitLong(this: buffer, curData: this->m_nNumSounds, numbits: 8, bCheckRange: true);
    bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 16, bCheckRange: true);
  }
  return bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
}

//------------------------------------------------------------------------------
// Address: 0x101BFE20
// Name: public: virtual bool SVC_Sounds::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_Sounds::ReadFromBuffer(SVC_Sounds *this, bf_read *buffer)
{
  unsigned int m_nInBufWord; // ecx
  int v4; // edx
  bool v5; // zf
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // esi
  int m_nBitsAvail; // ecx
  unsigned int v9; // edx
  int v10; // edi
  int v11; // ecx
  unsigned int v12; // esi
  const unsigned int *v13; // ecx
  const unsigned int *v14; // edx
  int v15; // edx
  int v16; // ecx
  unsigned int v17; // edx
  int v18; // esi
  int v19; // ecx
  const unsigned int *v20; // ecx
  const unsigned int *v21; // edx
  unsigned int v22; // edx
  const unsigned int *v23; // esi
  unsigned int v24; // edi
  int v25; // edx
  const unsigned int *v26; // ecx
  unsigned int v27; // esi
  unsigned int v28; // ebx
  unsigned int v29; // edx
  int v30; // ecx
  unsigned int v31; // edx
  const unsigned int *v32; // esi
  unsigned int v33; // edi
  int v34; // edx
  const unsigned int *v35; // ecx
  unsigned int v36; // esi
  unsigned int v37; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx
  SVC_Sounds *v41; // [esp+Ch] [ebp-4h]

  m_nInBufWord = buffer->m_nInBufWord;
  v4 = m_nInBufWord & 1;
  v5 = buffer->m_nBitsAvail-- == 1;
  v41 = this;
  if ( v5 )
  {
    m_pDataIn = buffer->m_pDataIn;
    m_pBufferEnd = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      buffer->m_nInBufWord = *m_pDataIn;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = m_nInBufWord >> 1;
  }
  this->m_bReliableSound = v4 != 0;
  if ( v4 != 0 )
  {
    this->m_nNumSounds = 1;
    m_nBitsAvail = buffer->m_nBitsAvail;
    if ( m_nBitsAvail >= 8 )
    {
      v9 = buffer->m_nInBufWord;
      v10 = (unsigned __int8)v9;
      v11 = m_nBitsAvail - 8;
      v12 = 0;
      buffer->m_nBitsAvail = v11;
      if ( v11 != 0 )
      {
        buffer->m_nInBufWord = v9 >> 8;
        goto LABEL_51;
      }
      goto LABEL_12;
    }
    v15 = 8;
    goto LABEL_41;
  }
  v16 = buffer->m_nBitsAvail;
  if ( v16 < 8 )
  {
    v23 = buffer->m_pBufferEnd;
    v24 = buffer->m_nInBufWord;
    v25 = 8 - v16;
    v26 = buffer->m_pDataIn;
    if ( v26 == v23 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v26 > v23 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_32:
        if ( buffer->m_bOverflow )
        {
          v19 = 0;
        }
        else
        {
          v27 = buffer->m_nInBufWord;
          v28 = (v27 & CBitBuffer::s_nMaskTable[v25]) << buffer->m_nBitsAvail;
          buffer->m_nBitsAvail = 32 - v25;
          v19 = v28 | v24;
          buffer->m_nInBufWord = v27 >> v25;
        }
        this = v41;
        goto LABEL_36;
      }
      buffer->m_nInBufWord = *v26;
    }
    buffer->m_pDataIn = v26 + 1;
    goto LABEL_32;
  }
  v17 = buffer->m_nInBufWord;
  v18 = (unsigned __int8)v17;
  buffer->m_nBitsAvail = v16 - 8;
  if ( v16 == 8 )
  {
    v20 = buffer->m_pDataIn;
    v21 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v20 == v21 )
    {
      buffer->m_pDataIn = v20 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v19 = v18;
    }
    else
    {
      if ( v20 <= v21 )
      {
        v22 = *v20;
        buffer->m_pDataIn = v20 + 1;
        buffer->m_nInBufWord = v22;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v19 = v18;
    }
  }
  else
  {
    buffer->m_nInBufWord = v17 >> 8;
    v19 = (unsigned __int8)v17;
  }
LABEL_36:
  this->m_nNumSounds = v19;
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 16 )
  {
    v29 = buffer->m_nInBufWord;
    v10 = (unsigned __int16)v29;
    v30 = m_nBitsAvail - 16;
    v12 = 0;
    buffer->m_nBitsAvail = v30;
    if ( v30 != 0 )
    {
      buffer->m_nInBufWord = HIWORD(v29);
      goto LABEL_51;
    }
LABEL_12:
    v13 = buffer->m_pDataIn;
    v14 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v13 == v14 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_pDataIn = v13 + 1;
    }
    else
    {
      if ( v13 <= v14 )
      {
        v31 = *v13;
        buffer->m_pDataIn = v13 + 1;
        buffer->m_nInBufWord = v31;
        goto LABEL_51;
      }
      buffer->m_bOverflow = true;
    }
    goto LABEL_50;
  }
  v15 = 16;
LABEL_41:
  v32 = buffer->m_pBufferEnd;
  v33 = buffer->m_nInBufWord;
  v34 = v15 - m_nBitsAvail;
  v35 = buffer->m_pDataIn;
  if ( v35 == v32 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_46:
    buffer->m_pDataIn = v35 + 1;
    goto LABEL_47;
  }
  if ( v35 <= v32 )
  {
    buffer->m_nInBufWord = *v35;
    goto LABEL_46;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_47:
  if ( buffer->m_bOverflow )
  {
    v10 = 0;
    goto LABEL_51;
  }
  v36 = buffer->m_nInBufWord;
  v37 = (v36 & CBitBuffer::s_nMaskTable[v34]) << buffer->m_nBitsAvail;
  buffer->m_nBitsAvail = 32 - v34;
  v10 = v37 | v33;
  v12 = v36 >> v34;
LABEL_50:
  buffer->m_nInBufWord = v12;
LABEL_51:
  v41->m_nLength = v10;
  qmemcpy(&v41->m_DataIn, buffer, sizeof(v41->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v41->m_nLength);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v41->m_nLength + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101C00F0
// Name: public: virtual bool SVC_TempEntities::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_TempEntities::ReadFromBuffer(SVC_TempEntities *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // ecx
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  unsigned int v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx
  int v16; // ecx
  unsigned int v17; // edx
  int v18; // esi
  int v19; // ecx
  int v20; // ebx
  const unsigned int *v21; // ecx
  const unsigned int *v22; // edx
  unsigned int v23; // edx
  const unsigned int *v24; // esi
  unsigned int v25; // edi
  int v26; // edx
  const unsigned int *v27; // ecx
  unsigned int v28; // esi
  unsigned int v29; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v12 = 8 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_16;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( buffer->m_bOverflow )
    {
      v6 = 0;
    }
    else
    {
      v14 = buffer->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v12;
      v6 = v15 | m_nInBufWord;
      buffer->m_nInBufWord = v14 >> v12;
    }
    goto LABEL_19;
  }
  v3 = buffer->m_nInBufWord;
  v4 = (unsigned __int8)v3;
  v5 = m_nBitsAvail - 8;
  buffer->m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    buffer->m_nInBufWord = v3 >> 8;
    v6 = (unsigned __int8)v3;
  }
  else
  {
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      buffer->m_pDataIn = v7 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v6 = v4;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v9 = *v7;
        buffer->m_pDataIn = v7 + 1;
        buffer->m_nInBufWord = v9;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v6 = v4;
    }
  }
LABEL_19:
  this->m_nNumEntries = v6;
  v16 = buffer->m_nBitsAvail;
  if ( v16 >= 17 )
  {
    v17 = buffer->m_nInBufWord;
    v18 = v17 & 0x1FFFF;
    v19 = v16 - 17;
    buffer->m_nBitsAvail = v19;
    if ( v19 != 0 )
    {
      buffer->m_nInBufWord = v17 >> 17;
      v20 = v17 & 0x1FFFF;
    }
    else
    {
      v21 = buffer->m_pDataIn;
      v22 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v21 == v22 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v21 + 1;
        v20 = v18;
      }
      else
      {
        if ( v21 <= v22 )
        {
          v23 = *v21;
          buffer->m_pDataIn = v21 + 1;
          buffer->m_nInBufWord = v23;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v20 = v18;
      }
    }
    goto LABEL_37;
  }
  v24 = buffer->m_pBufferEnd;
  v25 = buffer->m_nInBufWord;
  v26 = 17 - v16;
  v27 = buffer->m_pDataIn;
  if ( v27 == v24 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v27 > v24 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_34;
    }
    buffer->m_nInBufWord = *v27;
  }
  buffer->m_pDataIn = v27 + 1;
LABEL_34:
  if ( buffer->m_bOverflow )
  {
    v20 = 0;
  }
  else
  {
    v28 = buffer->m_nInBufWord;
    v29 = (v28 & CBitBuffer::s_nMaskTable[v26]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v26;
    v20 = v25 | v29;
    buffer->m_nInBufWord = v28 >> v26;
  }
LABEL_37:
  this->m_nLength = v20;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v20);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v20 + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101C0320
// Name: public: virtual bool SVC_GameEvent::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_GameEvent::ReadFromBuffer(SVC_GameEvent *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // ebx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v9; // edx
  const unsigned int *v10; // esi
  unsigned int v11; // edi
  int v12; // edx
  const unsigned int *v13; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 11 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v4 = m_nInBufWord & 0x7FF;
    v5 = m_nBitsAvail - 11;
    buffer->m_nBitsAvail = v5;
    if ( v5 != 0 )
    {
      buffer->m_nInBufWord = m_nInBufWord >> 11;
      v6 = m_nInBufWord & 0x7FF;
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = m_pDataIn + 1;
        v6 = v4;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v9 = *m_pDataIn;
          buffer->m_pDataIn = m_pDataIn + 1;
          buffer->m_nInBufWord = v9;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v6 = v4;
      }
    }
    goto LABEL_19;
  }
  v10 = buffer->m_pBufferEnd;
  v11 = buffer->m_nInBufWord;
  v12 = 11 - m_nBitsAvail;
  v13 = buffer->m_pDataIn;
  if ( v13 == v10 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v13 > v10 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_16;
    }
    buffer->m_nInBufWord = *v13;
  }
  buffer->m_pDataIn = v13 + 1;
LABEL_16:
  if ( buffer->m_bOverflow )
  {
    v6 = 0;
  }
  else
  {
    v14 = buffer->m_nInBufWord;
    v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v12;
    v6 = v11 | v15;
    buffer->m_nInBufWord = v14 >> v12;
  }
LABEL_19:
  this->m_nLength = v6;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v6);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v6 + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101C0480
// Name: public: virtual bool SVC_SendTable::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_SendTable::WriteToBuffer(SVC_SendTable *this, bf_write *buffer)
{
  SVC_SendTable_vtbl *v3; // edx
  unsigned int v4; // eax
  int m_iCurBit; // ecx
  BOOL m_bNeedsDecoder; // eax

  v3 = this->__vftable;
  this->m_nLength = this->m_DataOut.m_iCurBit;
  v4 = ((int (*)(void))v3->GetType)();
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 6, bCheckRange: true);
  m_iCurBit = buffer->m_iCurBit;
  m_bNeedsDecoder = this->m_bNeedsDecoder;
  if ( m_iCurBit + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bNeedsDecoder )
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
    else
      buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++buffer->m_iCurBit;
  }
  bf_write::WriteShort(this: buffer, val: this->m_nLength);
  bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101C0510
// Name: public: virtual bool SVC_SendTable::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_SendTable::ReadFromBuffer(SVC_SendTable *this, bf_read *buffer)
{
  unsigned int m_nInBufWord; // ecx
  int v4; // edx
  bool v5; // zf
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // esi
  int m_nBitsAvail; // ecx
  unsigned int v9; // edx
  __int16 v10; // si
  int v11; // ecx
  __int16 v12; // cx
  const unsigned int *v13; // ecx
  const unsigned int *v14; // edx
  unsigned int v15; // edx
  const unsigned int *v16; // esi
  unsigned int v17; // edi
  int v18; // edx
  const unsigned int *v19; // ecx
  unsigned int v20; // esi
  unsigned int v21; // ebx
  int v22; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx
  SVC_SendTable *v26; // [esp+Ch] [ebp-4h]

  m_nInBufWord = buffer->m_nInBufWord;
  v4 = m_nInBufWord & 1;
  v5 = buffer->m_nBitsAvail-- == 1;
  v26 = this;
  if ( v5 )
  {
    m_pDataIn = buffer->m_pDataIn;
    m_pBufferEnd = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      buffer->m_nInBufWord = *m_pDataIn;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = m_nInBufWord >> 1;
  }
  this->m_bNeedsDecoder = v4 != 0;
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 16 )
  {
    v9 = buffer->m_nInBufWord;
    v10 = v9;
    v11 = m_nBitsAvail - 16;
    buffer->m_nBitsAvail = v11;
    if ( v11 != 0 )
    {
      buffer->m_nInBufWord = HIWORD(v9);
      v12 = v9;
    }
    else
    {
      v13 = buffer->m_pDataIn;
      v14 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v13 == v14 )
      {
        buffer->m_pDataIn = v13 + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        v12 = v10;
      }
      else
      {
        if ( v13 <= v14 )
        {
          v15 = *v13;
          buffer->m_pDataIn = v13 + 1;
          buffer->m_nInBufWord = v15;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v12 = v10;
      }
    }
    goto LABEL_26;
  }
  v16 = buffer->m_pBufferEnd;
  v17 = buffer->m_nInBufWord;
  v18 = 16 - m_nBitsAvail;
  v19 = buffer->m_pDataIn;
  if ( v19 == v16 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v19 > v16 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_23;
    }
    buffer->m_nInBufWord = *v19;
  }
  buffer->m_pDataIn = v19 + 1;
LABEL_23:
  if ( buffer->m_bOverflow )
  {
    v12 = 0;
  }
  else
  {
    v20 = buffer->m_nInBufWord;
    v21 = (v20 & CBitBuffer::s_nMaskTable[v18]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v18;
    v12 = v21 | v17;
    buffer->m_nInBufWord = v20 >> v18;
  }
LABEL_26:
  v22 = v12;
  v26->m_nLength = v12;
  qmemcpy(&v26->m_DataIn, buffer, sizeof(v26->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v22);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: m_nDataBits + v22);
}

//------------------------------------------------------------------------------
// Address: 0x101C06C0
// Name: public: virtual bool SVC_EntityMessage::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_EntityMessage::ReadFromBuffer(SVC_EntityMessage *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // ebx
  int v7; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v10; // edx
  const unsigned int *v11; // esi
  unsigned int v12; // edi
  int v13; // edx
  const unsigned int *v14; // ecx
  unsigned int v15; // esi
  unsigned int v16; // ebx
  int v17; // ecx
  unsigned int v18; // edx
  int v19; // esi
  int v20; // ecx
  int v21; // ecx
  const unsigned int *v22; // ecx
  const unsigned int *v23; // edx
  unsigned int v24; // edx
  const unsigned int *v25; // esi
  unsigned int v26; // edi
  int v27; // edx
  const unsigned int *v28; // ecx
  unsigned int v29; // esi
  unsigned int v30; // ebx
  int v31; // ecx
  unsigned int v32; // edx
  int v33; // esi
  int v34; // ecx
  const unsigned int *v35; // ecx
  const unsigned int *v36; // edx
  unsigned int v37; // edx
  const unsigned int *v38; // esi
  unsigned int v39; // edi
  int v40; // edx
  const unsigned int *v41; // ecx
  unsigned int v42; // esi
  unsigned int v43; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 11 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v4 = m_nInBufWord & 0x7FF;
    v5 = m_nBitsAvail - 11;
    v6 = 0;
    buffer->m_nBitsAvail = v5;
    if ( v5 != 0 )
    {
      buffer->m_nInBufWord = m_nInBufWord >> 11;
      v7 = m_nInBufWord & 0x7FF;
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_pDataIn = m_pDataIn + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        v7 = v4;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v10 = *m_pDataIn;
          buffer->m_pDataIn = m_pDataIn + 1;
          buffer->m_nInBufWord = v10;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v7 = v4;
      }
    }
    goto LABEL_20;
  }
  v11 = buffer->m_pBufferEnd;
  v12 = buffer->m_nInBufWord;
  v13 = 11 - m_nBitsAvail;
  v14 = buffer->m_pDataIn;
  if ( v14 == v11 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_15:
    buffer->m_pDataIn = v14 + 1;
    goto LABEL_16;
  }
  if ( v14 <= v11 )
  {
    buffer->m_nInBufWord = *v14;
    goto LABEL_15;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_16:
  if ( buffer->m_bOverflow )
  {
    v7 = 0;
  }
  else
  {
    v15 = buffer->m_nInBufWord;
    v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v13;
    v7 = v16 | v12;
    buffer->m_nInBufWord = v15 >> v13;
  }
  v6 = 0;
LABEL_20:
  this->m_nEntityIndex = v7;
  v17 = buffer->m_nBitsAvail;
  if ( v17 < 9 )
  {
    v25 = buffer->m_pBufferEnd;
    v26 = buffer->m_nInBufWord;
    v27 = 9 - v17;
    v28 = buffer->m_pDataIn;
    if ( v28 == v25 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v28 > v25 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_35;
      }
      buffer->m_nInBufWord = *v28;
    }
    buffer->m_pDataIn = v28 + 1;
LABEL_35:
    if ( buffer->m_bOverflow )
    {
      v21 = 0;
    }
    else
    {
      v29 = buffer->m_nInBufWord;
      v30 = (v29 & CBitBuffer::s_nMaskTable[v27]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v27;
      v21 = v30 | v26;
      v6 = 0;
      buffer->m_nInBufWord = v29 >> v27;
    }
    goto LABEL_38;
  }
  v18 = buffer->m_nInBufWord;
  v19 = v18 & 0x1FF;
  v20 = v17 - 9;
  buffer->m_nBitsAvail = v20;
  if ( v20 != 0 )
  {
    buffer->m_nInBufWord = v18 >> 9;
    v21 = v18 & 0x1FF;
  }
  else
  {
    v22 = buffer->m_pDataIn;
    v23 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v22 == v23 )
    {
      buffer->m_pDataIn = v22 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v21 = v19;
    }
    else
    {
      if ( v22 <= v23 )
      {
        v24 = *v22;
        buffer->m_pDataIn = v22 + 1;
        buffer->m_nInBufWord = v24;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v21 = v19;
    }
  }
LABEL_38:
  this->m_nClassID = v21;
  v31 = buffer->m_nBitsAvail;
  if ( v31 >= 11 )
  {
    v32 = buffer->m_nInBufWord;
    v33 = v32 & 0x7FF;
    v34 = v31 - 11;
    buffer->m_nBitsAvail = v34;
    if ( v34 != 0 )
    {
      buffer->m_nInBufWord = v32 >> 11;
      v6 = v32 & 0x7FF;
    }
    else
    {
      v35 = buffer->m_pDataIn;
      v36 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v35 == v36 )
      {
        buffer->m_nInBufWord = 0;
        buffer->m_nBitsAvail = 1;
        buffer->m_pDataIn = v35 + 1;
        v6 = v33;
      }
      else
      {
        if ( v35 <= v36 )
        {
          v37 = *v35;
          buffer->m_pDataIn = v35 + 1;
          buffer->m_nInBufWord = v37;
        }
        else
        {
          buffer->m_nInBufWord = 0;
          buffer->m_bOverflow = true;
        }
        v6 = v33;
      }
    }
    goto LABEL_55;
  }
  v38 = buffer->m_pBufferEnd;
  v39 = buffer->m_nInBufWord;
  v40 = 11 - v31;
  v41 = buffer->m_pDataIn;
  if ( v41 == v38 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v41 > v38 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_53;
    }
    buffer->m_nInBufWord = *v41;
  }
  buffer->m_pDataIn = v41 + 1;
LABEL_53:
  if ( !buffer->m_bOverflow )
  {
    v42 = buffer->m_nInBufWord;
    v43 = (v42 & CBitBuffer::s_nMaskTable[v40]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v40;
    v6 = v39 | v43;
    buffer->m_nInBufWord = v42 >> v40;
  }
LABEL_55:
  this->m_nLength = v6;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v6);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v6 + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101C09D0
// Name: public: virtual bool SVC_PacketEntities::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_PacketEntities::WriteToBuffer(SVC_PacketEntities *this, bf_write *buffer)
{
  unsigned int v3; // eax
  int m_iCurBit; // ecx
  BOOL m_bIsDelta; // eax
  int v6; // ecx
  BOOL m_bUpdateBaseline; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nMaxEntries, numbits: 11, bCheckRange: true);
  m_iCurBit = buffer->m_iCurBit;
  m_bIsDelta = this->m_bIsDelta;
  if ( m_iCurBit + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bIsDelta )
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
    else
      buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++buffer->m_iCurBit;
  }
  if ( this->m_bIsDelta )
    bf_write::WriteLong(this: buffer, val: this->m_nDeltaFrom);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nBaseline, numbits: 1, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nUpdatedEntries, numbits: 11, bCheckRange: true);
  bf_write::WriteUBitLong(this: buffer, curData: this->m_nLength, numbits: 20, bCheckRange: true);
  v6 = buffer->m_iCurBit;
  m_bUpdateBaseline = this->m_bUpdateBaseline;
  if ( v6 + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    if ( m_bUpdateBaseline )
      buffer->m_pData[v6 >> 3] |= 1 << (v6 & 7);
    else
      buffer->m_pData[v6 >> 3] &= ~(1 << (v6 & 7));
    ++buffer->m_iCurBit;
  }
  bf_write::WriteBits(this: buffer, pInData: this->m_DataOut.m_pData, nBits: this->m_nLength);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101C0AE0
// Name: public: virtual bool SVC_PacketEntities::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_PacketEntities::ReadFromBuffer(SVC_PacketEntities *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v5; // esi
  int v6; // ecx
  int v7; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v10; // edx
  const unsigned int *v11; // esi
  unsigned int v12; // edi
  int v13; // edx
  const unsigned int *v14; // ecx
  unsigned int v15; // esi
  unsigned int v16; // ebx
  unsigned int v17; // ecx
  int v18; // edx
  bool v19; // zf
  const unsigned int *v20; // ecx
  const unsigned int *v21; // esi
  int v22; // esi
  unsigned int v23; // ecx
  const unsigned int *v24; // edx
  const unsigned int *v25; // esi
  SVC_PacketEntities *v26; // edx
  unsigned int v27; // esi
  const unsigned int *v28; // ecx
  unsigned int v29; // edi
  int v30; // edx
  const unsigned int *v31; // esi
  unsigned int v32; // esi
  unsigned int v33; // ebx
  int v34; // ecx
  unsigned int v35; // edx
  int v36; // esi
  int v37; // ecx
  int v38; // ecx
  const unsigned int *v39; // ecx
  const unsigned int *v40; // edx
  unsigned int v41; // edx
  const unsigned int *v42; // esi
  unsigned int v43; // edi
  int v44; // edx
  const unsigned int *v45; // ecx
  unsigned int v46; // esi
  unsigned int v47; // ebx
  int v48; // ecx
  unsigned int v49; // edx
  int v50; // esi
  int v51; // ecx
  int v52; // ecx
  const unsigned int *v53; // ecx
  const unsigned int *v54; // edx
  unsigned int v55; // edx
  const unsigned int *v56; // esi
  unsigned int v57; // edi
  int v58; // edx
  const unsigned int *v59; // ecx
  unsigned int v60; // esi
  unsigned int v61; // ebx
  int v62; // ecx
  unsigned int v63; // edx
  int v64; // esi
  int v65; // ecx
  int v66; // ecx
  const unsigned int *v67; // ecx
  const unsigned int *v68; // edx
  unsigned int v69; // edx
  const unsigned int *v70; // esi
  unsigned int v71; // edi
  int v72; // edx
  const unsigned int *v73; // ecx
  unsigned int v74; // esi
  unsigned int v75; // ebx
  unsigned int v76; // ecx
  int v77; // edx
  const unsigned int *v78; // ecx
  const unsigned int *v79; // esi
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx
  SVC_PacketEntities *v83; // [esp+Ch] [ebp-4h]

  m_nBitsAvail = buffer->m_nBitsAvail;
  v83 = this;
  if ( m_nBitsAvail >= 11 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v5 = m_nInBufWord & 0x7FF;
    v6 = m_nBitsAvail - 11;
    buffer->m_nBitsAvail = v6;
    if ( v6 != 0 )
    {
      buffer->m_nInBufWord = m_nInBufWord >> 11;
      v7 = m_nInBufWord & 0x7FF;
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_pDataIn = m_pDataIn + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        v7 = v5;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v10 = *m_pDataIn;
          buffer->m_pDataIn = m_pDataIn + 1;
          buffer->m_nInBufWord = v10;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v7 = v5;
      }
    }
    goto LABEL_20;
  }
  v11 = buffer->m_pBufferEnd;
  v12 = buffer->m_nInBufWord;
  v13 = 11 - m_nBitsAvail;
  v14 = buffer->m_pDataIn;
  if ( v14 == v11 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_15:
    buffer->m_pDataIn = v14 + 1;
    goto LABEL_16;
  }
  if ( v14 <= v11 )
  {
    buffer->m_nInBufWord = *v14;
    goto LABEL_15;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_16:
  if ( buffer->m_bOverflow )
  {
    v7 = 0;
  }
  else
  {
    v15 = buffer->m_nInBufWord;
    v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v13;
    v7 = v16 | v12;
    buffer->m_nInBufWord = v15 >> v13;
  }
  this = v83;
LABEL_20:
  this->m_nMaxEntries = v7;
  v17 = buffer->m_nInBufWord;
  v18 = v17 & 1;
  v19 = buffer->m_nBitsAvail-- == 1;
  if ( v19 )
  {
    v20 = buffer->m_pDataIn;
    v21 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v20 == v21 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v20 + 1;
    }
    else if ( v20 <= v21 )
    {
      buffer->m_nInBufWord = *v20;
      buffer->m_pDataIn = v20 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v17 >> 1;
  }
  this->m_bIsDelta = v18 != 0;
  if ( v18 == 0 )
  {
    this->m_nDeltaFrom = -1;
    goto LABEL_47;
  }
  v22 = buffer->m_nBitsAvail;
  if ( v22 < 32 )
  {
    v28 = buffer->m_pDataIn;
    v29 = buffer->m_nInBufWord;
    v30 = 32 - v22;
    v31 = buffer->m_pBufferEnd;
    if ( v28 == v31 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v28 > v31 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_43;
      }
      buffer->m_nInBufWord = *v28;
    }
    buffer->m_pDataIn = v28 + 1;
LABEL_43:
    if ( buffer->m_bOverflow )
    {
      v83->m_nDeltaFrom = 0;
    }
    else
    {
      v32 = buffer->m_nInBufWord;
      v33 = (v32 & CBitBuffer::s_nMaskTable[v30]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v30;
      buffer->m_nInBufWord = v32 >> v30;
      v83->m_nDeltaFrom = v33 | v29;
    }
    goto LABEL_47;
  }
  v23 = buffer->m_nInBufWord;
  buffer->m_nBitsAvail = v22 - 32;
  if ( v22 == 32 )
  {
    v24 = buffer->m_pDataIn;
    v25 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v24 == v25 )
    {
      buffer->m_pDataIn = v24 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v83->m_nDeltaFrom = v23;
    }
    else
    {
      if ( v24 <= v25 )
      {
        v27 = *v24;
        buffer->m_pDataIn = v24 + 1;
        v26 = v83;
        buffer->m_nInBufWord = v27;
      }
      else
      {
        v26 = v83;
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v26->m_nDeltaFrom = v23;
    }
  }
  else
  {
    buffer->m_nInBufWord = 0;
    v83->m_nDeltaFrom = v23;
  }
LABEL_47:
  v34 = buffer->m_nBitsAvail;
  if ( v34 < 1 )
  {
    v42 = buffer->m_pBufferEnd;
    v43 = buffer->m_nInBufWord;
    v44 = 1 - v34;
    v45 = buffer->m_pDataIn;
    if ( v45 == v42 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v45 > v42 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_62;
      }
      buffer->m_nInBufWord = *v45;
    }
    buffer->m_pDataIn = v45 + 1;
LABEL_62:
    if ( buffer->m_bOverflow )
    {
      v38 = 0;
    }
    else
    {
      v46 = buffer->m_nInBufWord;
      v47 = (v46 & CBitBuffer::s_nMaskTable[v44]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v44;
      v38 = v47 | v43;
      buffer->m_nInBufWord = v46 >> v44;
    }
    goto LABEL_65;
  }
  v35 = buffer->m_nInBufWord;
  v36 = v35 & 1;
  v37 = v34 - 1;
  buffer->m_nBitsAvail = v37;
  if ( v37 != 0 )
  {
    buffer->m_nInBufWord = v35 >> 1;
    v38 = v35 & 1;
  }
  else
  {
    v39 = buffer->m_pDataIn;
    v40 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v39 == v40 )
    {
      buffer->m_pDataIn = v39 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v38 = v36;
    }
    else
    {
      if ( v39 <= v40 )
      {
        v41 = *v39;
        buffer->m_pDataIn = v39 + 1;
        buffer->m_nInBufWord = v41;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v38 = v36;
    }
  }
LABEL_65:
  v83->m_nBaseline = v38;
  v48 = buffer->m_nBitsAvail;
  if ( v48 < 11 )
  {
    v56 = buffer->m_pBufferEnd;
    v57 = buffer->m_nInBufWord;
    v58 = 11 - v48;
    v59 = buffer->m_pDataIn;
    if ( v59 == v56 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v59 > v56 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_80;
      }
      buffer->m_nInBufWord = *v59;
    }
    buffer->m_pDataIn = v59 + 1;
LABEL_80:
    if ( buffer->m_bOverflow )
    {
      v52 = 0;
    }
    else
    {
      v60 = buffer->m_nInBufWord;
      v61 = (v60 & CBitBuffer::s_nMaskTable[v58]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v58;
      v52 = v61 | v57;
      buffer->m_nInBufWord = v60 >> v58;
    }
    goto LABEL_83;
  }
  v49 = buffer->m_nInBufWord;
  v50 = v49 & 0x7FF;
  v51 = v48 - 11;
  buffer->m_nBitsAvail = v51;
  if ( v51 != 0 )
  {
    buffer->m_nInBufWord = v49 >> 11;
    v52 = v49 & 0x7FF;
  }
  else
  {
    v53 = buffer->m_pDataIn;
    v54 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v53 == v54 )
    {
      buffer->m_pDataIn = v53 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v52 = v50;
    }
    else
    {
      if ( v53 <= v54 )
      {
        v55 = *v53;
        buffer->m_pDataIn = v53 + 1;
        buffer->m_nInBufWord = v55;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v52 = v50;
    }
  }
LABEL_83:
  v83->m_nUpdatedEntries = v52;
  v62 = buffer->m_nBitsAvail;
  if ( v62 < 20 )
  {
    v70 = buffer->m_pBufferEnd;
    v71 = buffer->m_nInBufWord;
    v72 = 20 - v62;
    v73 = buffer->m_pDataIn;
    if ( v73 == v70 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v73 > v70 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_98;
      }
      buffer->m_nInBufWord = *v73;
    }
    buffer->m_pDataIn = v73 + 1;
LABEL_98:
    if ( buffer->m_bOverflow )
    {
      v66 = 0;
    }
    else
    {
      v74 = buffer->m_nInBufWord;
      v75 = (v74 & CBitBuffer::s_nMaskTable[v72]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v72;
      v66 = v75 | v71;
      buffer->m_nInBufWord = v74 >> v72;
    }
    goto LABEL_101;
  }
  v63 = buffer->m_nInBufWord;
  v64 = v63 & 0xFFFFF;
  v65 = v62 - 20;
  buffer->m_nBitsAvail = v65;
  if ( v65 != 0 )
  {
    buffer->m_nInBufWord = v63 >> 20;
    v66 = v63 & 0xFFFFF;
  }
  else
  {
    v67 = buffer->m_pDataIn;
    v68 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v67 == v68 )
    {
      buffer->m_pDataIn = v67 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v66 = v64;
    }
    else
    {
      if ( v67 <= v68 )
      {
        v69 = *v67;
        buffer->m_pDataIn = v67 + 1;
        buffer->m_nInBufWord = v69;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v66 = v64;
    }
  }
LABEL_101:
  v83->m_nLength = v66;
  v76 = buffer->m_nInBufWord;
  v77 = v76 & 1;
  v19 = buffer->m_nBitsAvail-- == 1;
  if ( v19 )
  {
    v78 = buffer->m_pDataIn;
    v79 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v78 == v79 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v78 + 1;
    }
    else if ( v78 <= v79 )
    {
      buffer->m_nInBufWord = *v78;
      buffer->m_pDataIn = v78 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v76 >> 1;
  }
  v83->m_bUpdateBaseline = v77 != 0;
  qmemcpy(&v83->m_DataIn, buffer, sizeof(v83->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v83->m_nLength);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v83->m_nLength + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101C1090
// Name: public: SVC_Menu::SVC_Menu(enum DIALOG_TYPE,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
SVC_Menu *__thiscall SVC_Menu::SVC_Menu(SVC_Menu *this, DIALOG_TYPE type, KeyValues *data)
{
  this->m_NetChannel = nullptr;
  this->__vftable = (SVC_Menu_vtbl *)&SVC_Menu::`vftable';
  this->m_bReliable = true;
  this->m_Type = type;
  this->m_MenuKeyValues = KeyValues::MakeCopy(this: data);
  this->m_iLength = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C10D0
// Name: public: virtual bool SVC_GameEventList::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_GameEventList::ReadFromBuffer(SVC_GameEventList *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // ecx
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  unsigned int v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx
  int v16; // ecx
  unsigned int v17; // edx
  int v18; // esi
  int v19; // ecx
  int v20; // ebx
  const unsigned int *v21; // ecx
  const unsigned int *v22; // edx
  unsigned int v23; // edx
  const unsigned int *v24; // esi
  unsigned int v25; // edi
  int v26; // edx
  const unsigned int *v27; // ecx
  unsigned int v28; // esi
  unsigned int v29; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 9 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v12 = 9 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_16;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( buffer->m_bOverflow )
    {
      v6 = 0;
    }
    else
    {
      v14 = buffer->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v12;
      v6 = v15 | m_nInBufWord;
      buffer->m_nInBufWord = v14 >> v12;
    }
    goto LABEL_19;
  }
  v3 = buffer->m_nInBufWord;
  v4 = v3 & 0x1FF;
  v5 = m_nBitsAvail - 9;
  buffer->m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    buffer->m_nInBufWord = v3 >> 9;
    v6 = v3 & 0x1FF;
  }
  else
  {
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      buffer->m_pDataIn = v7 + 1;
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      v6 = v4;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v9 = *v7;
        buffer->m_pDataIn = v7 + 1;
        buffer->m_nInBufWord = v9;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v6 = v4;
    }
  }
LABEL_19:
  this->m_nNumEvents = v6;
  v16 = buffer->m_nBitsAvail;
  if ( v16 >= 20 )
  {
    v17 = buffer->m_nInBufWord;
    v18 = v17 & 0xFFFFF;
    v19 = v16 - 20;
    buffer->m_nBitsAvail = v19;
    if ( v19 != 0 )
    {
      buffer->m_nInBufWord = v17 >> 20;
      v20 = v17 & 0xFFFFF;
    }
    else
    {
      v21 = buffer->m_pDataIn;
      v22 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v21 == v22 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v21 + 1;
        v20 = v18;
      }
      else
      {
        if ( v21 <= v22 )
        {
          v23 = *v21;
          buffer->m_pDataIn = v21 + 1;
          buffer->m_nInBufWord = v23;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v20 = v18;
      }
    }
    goto LABEL_37;
  }
  v24 = buffer->m_pBufferEnd;
  v25 = buffer->m_nInBufWord;
  v26 = 20 - v16;
  v27 = buffer->m_pDataIn;
  if ( v27 == v24 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v27 > v24 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_34;
    }
    buffer->m_nInBufWord = *v27;
  }
  buffer->m_pDataIn = v27 + 1;
LABEL_34:
  if ( buffer->m_bOverflow )
  {
    v20 = 0;
  }
  else
  {
    v28 = buffer->m_nInBufWord;
    v29 = (v28 & CBitBuffer::s_nMaskTable[v26]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v26;
    v20 = v25 | v29;
    buffer->m_nInBufWord = v28 >> v26;
  }
LABEL_37:
  this->m_nLength = v20;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v20);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v20 + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101C1300
// Name: public: virtual bool SVC_PaintmapData::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_PaintmapData::ReadFromBuffer(SVC_PaintmapData *this, bf_read *buffer)
{
  int m_nBitsAvail; // esi
  unsigned int m_nInBufWord; // ecx
  int v4; // ebx
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // esi
  const unsigned int *v7; // ecx
  unsigned int v8; // edi
  int v9; // edx
  const unsigned int *v10; // esi
  unsigned int v11; // esi
  unsigned int v12; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx

  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail >= 32 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    buffer->m_nBitsAvail = m_nBitsAvail - 32;
    if ( m_nBitsAvail == 32 )
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = m_pDataIn + 1;
        v4 = m_nInBufWord;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          buffer->m_nInBufWord = *m_pDataIn;
          buffer->m_pDataIn = m_pDataIn + 1;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v4 = m_nInBufWord;
      }
    }
    else
    {
      buffer->m_nInBufWord = 0;
      v4 = m_nInBufWord;
    }
    goto LABEL_19;
  }
  v7 = buffer->m_pDataIn;
  v8 = buffer->m_nInBufWord;
  v9 = 32 - m_nBitsAvail;
  v10 = buffer->m_pBufferEnd;
  if ( v7 == v10 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v7 > v10 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_16;
    }
    buffer->m_nInBufWord = *v7;
  }
  buffer->m_pDataIn = v7 + 1;
LABEL_16:
  if ( buffer->m_bOverflow )
  {
    v4 = 0;
  }
  else
  {
    v11 = buffer->m_nInBufWord;
    v12 = (v11 & CBitBuffer::s_nMaskTable[v9]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v9;
    v4 = v8 | v12;
    buffer->m_nInBufWord = v11 >> v9;
  }
LABEL_19:
  this->m_nLength = v4;
  qmemcpy(&this->m_DataIn, buffer, sizeof(this->m_DataIn));
  m_pData = buffer->m_pData;
  if ( m_pData == nullptr )
    return CBitRead::Seek(this: buffer, nPosition: v4);
  m_nDataBits = 32 * (buffer->m_pDataIn - m_pData) - buffer->m_nBitsAvail + 8 * (buffer->m_nDataBytes & 3);
  if ( m_nDataBits >= buffer->m_nDataBits )
    m_nDataBits = buffer->m_nDataBits;
  return CBitRead::Seek(this: buffer, nPosition: v4 + m_nDataBits);
}

//------------------------------------------------------------------------------
// Address: 0x101C1450
// Name: public: virtual bool CLC_ListenEvents::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLC_ListenEvents::WriteToBuffer(CLC_ListenEvents *this, bf_write *buffer)
{
  unsigned int v3; // eax
  unsigned int *v4; // edi
  int m_iCurBit; // eax
  int m_nDataBits; // ecx
  unsigned int v7; // edi
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  int v14; // eax
  int v15; // ecx
  int v16; // edx
  int v17; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // edx
  int v21; // eax
  bool v22; // zf
  int v24; // [esp+Ch] [ebp-Ch]
  unsigned int *v25; // [esp+10h] [ebp-8h]
  unsigned int v26; // [esp+14h] [ebp-4h]
  unsigned int v27; // [esp+14h] [ebp-4h]
  unsigned int v28; // [esp+14h] [ebp-4h]

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  v4 = &this->m_EventArray.m_Ints[1];
  v25 = v4;
  v24 = 4;
  do
  {
    m_iCurBit = buffer->m_iCurBit;
    m_nDataBits = buffer->m_nDataBits;
    v7 = *(v4 - 1);
    if ( m_iCurBit + 32 <= m_nDataBits )
    {
      v8 = m_iCurBit >> 5;
      *(_DWORD *)&buffer->m_pData[4 * (buffer->m_iCurBit >> 5)] = (v7 << (buffer->m_iCurBit & 0x1F))
                                                                | *(_DWORD *)&buffer->m_pData[4
                                                                                            * (buffer->m_iCurBit >> 5)]
                                                                & dword_106C7448[33 * (buffer->m_iCurBit & 0x1F)];
      v9 = 32 - (m_iCurBit & 0x1F);
      if ( v9 < 32 )
        *(_DWORD *)&buffer->m_pData[4 * v8 + 4] = (v7 >> v9)
                                                | *(_DWORD *)&buffer->m_pData[4 * v8 + 4] & dword_106C7448[-v9];
      buffer->m_iCurBit += 32;
    }
    else
    {
      buffer->m_iCurBit = m_nDataBits;
      buffer->m_bOverflow = true;
    }
    v10 = buffer->m_iCurBit;
    v11 = buffer->m_nDataBits;
    v26 = *v25;
    if ( v10 + 32 <= v11 )
    {
      v12 = v10 >> 5;
      *(_DWORD *)&buffer->m_pData[4 * (buffer->m_iCurBit >> 5)] = (*v25 << (buffer->m_iCurBit & 0x1F))
                                                                | *(_DWORD *)&buffer->m_pData[4
                                                                                            * (buffer->m_iCurBit >> 5)]
                                                                & dword_106C7448[33 * (buffer->m_iCurBit & 0x1F)];
      v13 = 32 - (v10 & 0x1F);
      if ( v13 < 32 )
        *(_DWORD *)&buffer->m_pData[4 * v12 + 4] = (v26 >> v13)
                                                 | *(_DWORD *)&buffer->m_pData[4 * v12 + 4] & dword_106C7448[-v13];
      buffer->m_iCurBit += 32;
    }
    else
    {
      buffer->m_iCurBit = v11;
      buffer->m_bOverflow = true;
    }
    v14 = buffer->m_iCurBit;
    v15 = buffer->m_nDataBits;
    v27 = v25[1];
    if ( v14 + 32 <= v15 )
    {
      v16 = v14 >> 5;
      *(_DWORD *)&buffer->m_pData[4 * (buffer->m_iCurBit >> 5)] = (v25[1] << (buffer->m_iCurBit & 0x1F))
                                                                | *(_DWORD *)&buffer->m_pData[4
                                                                                            * (buffer->m_iCurBit >> 5)]
                                                                & dword_106C7448[33 * (buffer->m_iCurBit & 0x1F)];
      v17 = 32 - (v14 & 0x1F);
      if ( v17 < 32 )
        *(_DWORD *)&buffer->m_pData[4 * v16 + 4] = (v27 >> v17)
                                                 | *(_DWORD *)&buffer->m_pData[4 * v16 + 4] & dword_106C7448[-v17];
      buffer->m_iCurBit += 32;
    }
    else
    {
      buffer->m_iCurBit = v15;
      buffer->m_bOverflow = true;
    }
    v18 = buffer->m_iCurBit;
    v19 = buffer->m_nDataBits;
    v28 = v25[2];
    if ( v18 + 32 <= v19 )
    {
      v20 = v18 >> 5;
      *(_DWORD *)&buffer->m_pData[4 * (buffer->m_iCurBit >> 5)] = (v25[2] << (buffer->m_iCurBit & 0x1F))
                                                                | *(_DWORD *)&buffer->m_pData[4
                                                                                            * (buffer->m_iCurBit >> 5)]
                                                                & dword_106C7448[33 * (buffer->m_iCurBit & 0x1F)];
      v21 = 32 - (v18 & 0x1F);
      if ( v21 < 32 )
        *(_DWORD *)&buffer->m_pData[4 * v20 + 4] = (v28 >> v21)
                                                 | *(_DWORD *)&buffer->m_pData[4 * v20 + 4] & dword_106C7448[-v21];
      buffer->m_iCurBit += 32;
    }
    else
    {
      buffer->m_iCurBit = v19;
      buffer->m_bOverflow = true;
    }
    v4 = v25 + 4;
    v22 = v24-- == 1;
    v25 += 4;
  }
  while ( !v22 );
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101C16A0
// Name: public: virtual bool CLC_ListenEvents::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_ListenEvents::ReadFromBuffer(CLC_ListenEvents *this, bf_read *buffer)
{
  int m_nBitsAvail; // esi
  unsigned int m_nInBufWord; // ecx
  const unsigned int *m_pDataIn; // edx
  const unsigned int *m_pBufferEnd; // esi
  const unsigned int *v7; // ecx
  unsigned int v8; // edi
  int v9; // edx
  const unsigned int *v10; // esi
  unsigned int v11; // esi
  unsigned int v12; // ebx
  bool v13; // zf
  int v15; // [esp+Ch] [ebp-4h]
  bf_read *buffera; // [esp+18h] [ebp+8h]

  buffera = (bf_read *)&this->m_EventArray;
  v15 = 16;
  do
  {
    m_nBitsAvail = buffer->m_nBitsAvail;
    if ( m_nBitsAvail >= 32 )
    {
      m_nInBufWord = buffer->m_nInBufWord;
      buffer->m_nBitsAvail = m_nBitsAvail - 32;
      if ( m_nBitsAvail == 32 )
      {
        m_pDataIn = buffer->m_pDataIn;
        m_pBufferEnd = buffer->m_pBufferEnd;
        buffer->m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          buffer->m_nBitsAvail = 1;
          buffer->m_nInBufWord = 0;
          buffer->m_pDataIn = m_pDataIn + 1;
        }
        else if ( m_pDataIn <= m_pBufferEnd )
        {
          buffer->m_nInBufWord = *m_pDataIn;
          buffer->m_pDataIn = m_pDataIn + 1;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
      }
      else
      {
        buffer->m_nInBufWord = 0;
      }
      goto LABEL_19;
    }
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_nInBufWord;
    v9 = 32 - m_nBitsAvail;
    v10 = buffer->m_pBufferEnd;
    if ( v7 == v10 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v7 > v10 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_16;
      }
      buffer->m_nInBufWord = *v7;
    }
    buffer->m_pDataIn = v7 + 1;
LABEL_16:
    if ( buffer->m_bOverflow )
    {
      m_nInBufWord = 0;
    }
    else
    {
      v11 = buffer->m_nInBufWord;
      v12 = (v11 & CBitBuffer::s_nMaskTable[v9]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v9;
      m_nInBufWord = v12 | v8;
      buffer->m_nInBufWord = v11 >> v9;
    }
LABEL_19:
    buffera->m_pDebugName = (const char *)m_nInBufWord;
    v13 = v15-- == 1;
    buffera = (bf_read *)((char *)buffera + 4);
  }
  while ( !v13 );
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101C17C0
// Name: public: virtual char const __near * CLC_ListenEvents::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLC_ListenEvents::ToString(CLC_ListenEvents *this)
{
  int v1; // esi
  int v2; // eax
  unsigned int v3; // edx
  int i; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  const char *v8; // eax
  int v10; // [esp-4h] [ebp-10h]

  v1 = 0;
  v2 = 1;
  v3 = 2;
  for ( i = 128; i != 0; --i )
  {
    if ( (v2 & this->m_EventArray.m_Ints[(v3 - 2) >> 5]) != 0 )
      ++v1;
    v5 = __ROL4__(v2, 1);
    if ( (v5 & this->m_EventArray.m_Ints[(v3 - 1) >> 5]) != 0 )
      ++v1;
    v6 = __ROL4__(v5, 1);
    if ( (v6 & this->m_EventArray.m_Ints[v3 >> 5]) != 0 )
      ++v1;
    v7 = __ROL4__(v6, 1);
    if ( (v7 & this->m_EventArray.m_Ints[(v3 + 1) >> 5]) != 0 )
      ++v1;
    v2 = __ROL4__(v7, 1);
    v3 += 4;
  }
  v8 = (const char *)((int (__thiscall *)(CLC_ListenEvents *, int))this->GetName)(a1: this, a2: v1);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: registered events %i", v8, v10);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101C1840
// Name: public: virtual bool NET_SetConVar::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall NET_SetConVar::WriteToBuffer(NET_SetConVar *this, bf_write *buffer)
{
  NET_SetConVar *v2; // esi
  unsigned int v3; // eax
  signed int m_Size; // ebx
  int v6; // ebx
  const char *name; // esi
  int numvars; // [esp+18h] [ebp+8h]

  v2 = this;
  v3 = ((int (__fastcall *)(NET_SetConVar *))this->GetType)(a1: this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  m_Size = v2->m_ConVars.m_Size;
  numvars = m_Size;
  bf_write::WriteByte(this: buffer, val: m_Size);
  if ( m_Size > 0 )
  {
    v6 = 0;
    while ( 1 )
    {
      name = v2->m_ConVars.m_Memory.m_pMemory[v6].name;
      bf_write::WriteString(this: buffer, pStr: name);
      bf_write::WriteString(this: buffer, pStr: name + 260);
      ++v6;
      if ( --numvars == 0 )
        break;
      v2 = this;
    }
  }
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101C18C0
// Name: public: virtual bool NET_SignonState::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall NET_SignonState::WriteToBuffer(NET_SignonState *this, bf_write *buffer)
{
  unsigned int v3; // eax

  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteByte(this: buffer, val: this->m_nSignonState);
  bf_write::WriteLong(this: buffer, val: this->m_nSpawnCount);
  bf_write::WriteLong(this: buffer, val: this->m_numServerPlayers);
  bf_write::WriteLong(this: buffer, val: this->m_PlayersNetworkIds.m_Size);
  if ( this->m_PlayersNetworkIds.m_Size > 0 )
    bf_write::WriteBytes(
      this: buffer,
      pBuf: this->m_PlayersNetworkIds.m_Memory.m_pMemory,
      nBytes: this->m_PlayersNetworkIds.m_Size);
  bf_write::WriteLong(this: buffer, val: this->m_Mapname.m_Size);
  if ( this->m_Mapname.m_Size > 0 )
    bf_write::WriteBytes(this: buffer, pBuf: this->m_Mapname.m_Memory.m_pMemory, nBytes: this->m_Mapname.m_Size);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101C1950
// Name: public: virtual char const __near * NET_SetConVar::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall NET_SetConVar::ToString(NET_SetConVar *this)
{
  const char *v1; // eax
  int v3; // [esp-Ch] [ebp-10h]
  const char *v4; // [esp-8h] [ebp-Ch]
  const char *v5; // [esp-4h] [ebp-8h]

  v1 = (const char *)((int (__thiscall *)(NET_SetConVar *, int, NetMessageCvar_t *, char *))this->GetName)(
                       a1: this,
                       a2: this->m_ConVars.m_Size,
                       a3: this->m_ConVars.m_Memory.m_pMemory,
                       a4: this->m_ConVars.m_Memory.m_pMemory->value);
  V_snprintf(pDest: s_text, maxLen: 1024, pFormat: "%s: %i cvars, \"%s\"=\"%s\"", v1, v3, v4, v5);
  return s_text;
}

//------------------------------------------------------------------------------
// Address: 0x101C1990
// Name: public: virtual bool SVC_ClassInfo::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SVC_ClassInfo::WriteToBuffer(SVC_ClassInfo *this, bf_write *buffer)
{
  unsigned int v3; // eax
  unsigned int v5; // eax
  int m_iCurBit; // ecx
  int v7; // eax
  BOOL m_bCreateOnClient; // edx
  unsigned __int8 *m_pData; // esi
  SVC_ClassInfo::class_s *v10; // esi
  int serverClassBits; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]
  bf_write *buffera; // [esp+1Ch] [ebp+8h]

  if ( !this->m_bCreateOnClient )
    this->m_nNumServerClasses = this->m_Classes.m_Size;
  v3 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v3, numbits: 6, bCheckRange: true);
  bf_write::WriteShort(this: buffer, val: this->m_nNumServerClasses);
  v5 = Q_log2(val: this->m_nNumServerClasses);
  m_iCurBit = buffer->m_iCurBit;
  v7 = v5 + 1;
  m_bCreateOnClient = this->m_bCreateOnClient;
  serverClassBits = v7;
  if ( m_iCurBit + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    m_pData = buffer->m_pData;
    if ( m_bCreateOnClient )
      m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
    else
      m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++buffer->m_iCurBit;
  }
  if ( !this->m_bCreateOnClient )
  {
    i = 0;
    if ( this->m_nNumServerClasses > 0 )
    {
      buffera = nullptr;
      while ( 1 )
      {
        v10 = (SVC_ClassInfo::class_s *)((char *)buffera + (unsigned int)this->m_Classes.m_Memory.m_pMemory);
        bf_write::WriteUBitLong(this: buffer, curData: v10->classID, numbits: v7, bCheckRange: true);
        bf_write::WriteString(this: buffer, pStr: v10->classname);
        bf_write::WriteString(this: buffer, pStr: v10->datatablename);
        buffera = (bf_write *)((char *)buffera + 516);
        if ( ++i >= this->m_nNumServerClasses )
          break;
        v7 = serverClassBits;
      }
    }
  }
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101C1A90
// Name: public: virtual bool Base_CmdKeyValues::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Base_CmdKeyValues::ReadFromBuffer(Base_CmdKeyValues *this, bf_read *buffer)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  int m_nBitsAvail; // ecx
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // edi
  const unsigned int *v9; // ecx
  const unsigned int *v10; // edx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v13; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v15; // edx
  unsigned int v16; // ebx
  void *v17; // esp
  bool v19; // bl
  _BYTE v20[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer bufRead; // [esp+Ch] [ebp-34h] BYREF
  Base_CmdKeyValues *v22; // [esp+3Ch] [ebp-4h]

  v22 = this;
  if ( this->m_pKeyValues == nullptr )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: defaultValue);
    else
      v4 = nullptr;
    this->m_pKeyValues = v4;
  }
  KeyValues::Clear(this: this->m_pKeyValues);
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 32 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v13 = 32 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_21;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
LABEL_21:
    if ( buffer->m_bOverflow )
    {
      v8 = 0;
    }
    else
    {
      v15 = buffer->m_nInBufWord;
      v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v13;
      v8 = v16 | m_nInBufWord;
      buffer->m_nInBufWord = v15 >> v13;
    }
    goto LABEL_24;
  }
  v6 = buffer->m_nInBufWord;
  v7 = m_nBitsAvail - 32;
  buffer->m_nBitsAvail = v7;
  if ( v7 != 0 )
  {
    buffer->m_nInBufWord = 0;
    v8 = v6;
  }
  else
  {
    v9 = buffer->m_pDataIn;
    v10 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v9 == v10 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v9 + 1;
      v8 = v6;
    }
    else
    {
      if ( v9 <= v10 )
      {
        buffer->m_nInBufWord = *v9;
        buffer->m_pDataIn = v9 + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v8 = v6;
    }
  }
LABEL_24:
  v17 = alloca(v8);
  CBitRead::ReadBits(this: buffer, pOutData: v20, nBits: 8 * v8);
  CUtlBuffer::CUtlBuffer(this: &bufRead, pBuffer: v20, nSize: v8, nFlags: 8);
  CUtlBuffer::ActivateByteSwapping(this: &bufRead, bActivate: true);
  if ( KeyValues::ReadAsBinary(this: v22->m_pKeyValues, buffer: &bufRead) )
  {
    v19 = !buffer->m_bOverflow;
    if ( bufRead.m_Memory.m_nGrowSize >= 0 && bufRead.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufRead.m_Memory.m_pMemory);
    return v19;
  }
  else
  {
    if ( bufRead.m_Memory.m_nGrowSize >= 0 && bufRead.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufRead.m_Memory.m_pMemory);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C1C50
// Name: public: virtual bool SVC_CmdKeyValues::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_CmdKeyValues::ReadFromBuffer(SVC_CmdKeyValues *this, bf_read *buffer)
{
  return Base_CmdKeyValues::ReadFromBuffer(this, buffer);
}

//------------------------------------------------------------------------------
// Address: 0x101C1C60
// Name: public: virtual bool SVC_Menu::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_Menu::WriteToBuffer(SVC_Menu *this, bf_write *buffer)
{
  unsigned int v4; // eax
  bool v5; // bl
  CUtlBuffer buf; // [esp+4h] [ebp-30h] BYREF

  if ( this->m_MenuKeyValues == nullptr )
    return false;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  KeyValues::WriteAsBinary(this: this->m_MenuKeyValues, buffer: &buf);
  if ( buf.m_Put > 4096 )
  {
    _Msg(a1: "Too much menu data (4096 bytes max)\n");
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return false;
  }
  v4 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 6, bCheckRange: true);
  bf_write::WriteShort(this: buffer, val: this->m_Type);
  bf_write::WriteWord(this: buffer, val: buf.m_Put);
  bf_write::WriteBytes(this: buffer, pBuf: buf.m_Memory.m_pMemory, nBytes: buf.m_Put);
  v5 = !buffer->m_bOverflow;
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101C1D40
// Name: public: virtual bool SVC_Menu::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_Menu::ReadFromBuffer(SVC_Menu *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  __int16 v4; // di
  unsigned int v5; // edx
  const unsigned int *v6; // eax
  const unsigned int *v7; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v10; // eax
  const unsigned int *m_pDataIn; // ecx
  __int16 v12; // ax
  unsigned int v13; // edx
  unsigned int v14; // ebx
  SVC_Menu *v15; // edi
  int v16; // ecx
  unsigned int v17; // edx
  int v18; // eax
  unsigned int v19; // edx
  const unsigned int *v20; // ecx
  const unsigned int *v21; // edx
  const unsigned int *v22; // edx
  unsigned int v23; // edi
  int v24; // eax
  const unsigned int *v25; // ecx
  unsigned int v26; // edx
  unsigned int v27; // ebx
  char v28; // cl
  KeyValues *m_MenuKeyValues; // ecx
  KeyValues *v30; // eax
  KeyValues *v31; // eax
  bool v32; // bl
  CUtlBuffer buf; // [esp+Ch] [ebp-34h] BYREF
  SVC_Menu *v35; // [esp+3Ch] [ebp-4h]

  v35 = this;
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 16 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v10 = 16 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_15:
        if ( buffer->m_bOverflow )
        {
          v12 = 0;
          goto LABEL_20;
        }
        v13 = buffer->m_nInBufWord;
        v14 = (v13 & CBitBuffer::s_nMaskTable[v10]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v10;
        v4 = v14 | m_nInBufWord;
        v5 = v13 >> v10;
        goto LABEL_18;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v3 = buffer->m_nInBufWord;
  v4 = v3;
  buffer->m_nBitsAvail = m_nBitsAvail - 16;
  if ( m_nBitsAvail == 16 )
  {
    v6 = buffer->m_pDataIn;
    v7 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v6 == v7 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v6 + 1;
    }
    else if ( v6 <= v7 )
    {
      buffer->m_nInBufWord = *v6;
      buffer->m_pDataIn = v6 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
    goto LABEL_19;
  }
  v5 = HIWORD(v3);
LABEL_18:
  buffer->m_nInBufWord = v5;
LABEL_19:
  v12 = v4;
LABEL_20:
  v15 = v35;
  v35->m_Type = v12;
  v16 = buffer->m_nBitsAvail;
  if ( v16 >= 16 )
  {
    v17 = buffer->m_nInBufWord;
    v18 = (unsigned __int16)v17;
    buffer->m_nBitsAvail = v16 - 16;
    if ( v16 == 16 )
    {
      v20 = buffer->m_pDataIn;
      v21 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v20 == v21 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v20 + 1;
        goto LABEL_38;
      }
      if ( v20 > v21 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_38;
      }
      v19 = *v20;
      buffer->m_pDataIn = v20 + 1;
    }
    else
    {
      v19 = HIWORD(v17);
    }
    goto LABEL_37;
  }
  v22 = buffer->m_pBufferEnd;
  v23 = buffer->m_nInBufWord;
  v24 = 16 - v16;
  v25 = buffer->m_pDataIn;
  if ( v25 == v22 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_33:
    buffer->m_pDataIn = v25 + 1;
    goto LABEL_34;
  }
  if ( v25 <= v22 )
  {
    buffer->m_nInBufWord = *v25;
    goto LABEL_33;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_34:
  if ( buffer->m_bOverflow )
  {
    v15 = v35;
    v18 = 0;
    goto LABEL_38;
  }
  v26 = buffer->m_nInBufWord;
  v27 = (v26 & CBitBuffer::s_nMaskTable[v24]) << buffer->m_nBitsAvail;
  buffer->m_nBitsAvail = 32 - v24;
  v28 = v24;
  v18 = v27 | v23;
  v15 = v35;
  v19 = v26 >> v28;
LABEL_37:
  buffer->m_nInBufWord = v19;
LABEL_38:
  v15->m_iLength = v18;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: v18, nFlags: 0);
  CBitRead::ReadBytes(this: buffer, pOut: buf.m_Memory.m_pMemory, nBytes: v15->m_iLength);
  CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v15->m_iLength);
  m_MenuKeyValues = v15->m_MenuKeyValues;
  if ( m_MenuKeyValues != nullptr )
    KeyValues::deleteThis(this: m_MenuKeyValues);
  v30 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v30 != nullptr )
    v31 = KeyValues::KeyValues(this: v30, setName: "menu");
  else
    v31 = nullptr;
  v15->m_MenuKeyValues = v31;
  KeyValues::ReadAsBinary(this: v31, buffer: &buf);
  v32 = !buffer->m_bOverflow;
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return v32;
}

//------------------------------------------------------------------------------
// Address: 0x101C1FA0
// Name: public: virtual bool Base_CmdKeyValues::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Base_CmdKeyValues::WriteToBuffer(Base_CmdKeyValues *this, bf_write *buffer)
{
  unsigned int v4; // eax
  int m_nMaxPut; // edi
  bool v6; // bl
  CUtlBuffer bufData; // [esp+4h] [ebp-30h] BYREF

  if ( this->m_pKeyValues == nullptr )
    return false;
  v4 = this->GetType(this);
  bf_write::WriteUBitLong(this: buffer, curData: v4, numbits: 6, bCheckRange: true);
  CUtlBuffer::CUtlBuffer(this: &bufData, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::ActivateByteSwapping(this: &bufData, bActivate: true);
  if ( KeyValues::WriteAsBinary(this: this->m_pKeyValues, buffer: &bufData) )
  {
    m_nMaxPut = bufData.m_nMaxPut;
    bf_write::WriteLong(this: buffer, val: bufData.m_nMaxPut);
    bf_write::WriteBits(this: buffer, pInData: bufData.m_Memory.m_pMemory, nBits: 8 * m_nMaxPut);
    v6 = !buffer->m_bOverflow;
    if ( bufData.m_Memory.m_nGrowSize >= 0 && bufData.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufData.m_Memory.m_pMemory);
    return v6;
  }
  else
  {
    if ( bufData.m_Memory.m_nGrowSize >= 0 && bufData.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufData.m_Memory.m_pMemory);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C2070
// Name: public: virtual bool SVC_CmdKeyValues::WriteToBuffer(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_CmdKeyValues::WriteToBuffer(SVC_CmdKeyValues *this, bf_write *buffer)
{
  return Base_CmdKeyValues::WriteToBuffer(this, buffer);
}

//------------------------------------------------------------------------------
// Address: 0x101C2080
// Name: public: virtual bool NET_SetConVar::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall NET_SetConVar::ReadFromBuffer(NET_SetConVar *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v4; // edx
  int v5; // edi
  unsigned int v6; // edx
  const unsigned int *v7; // eax
  const unsigned int *v8; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v11; // eax
  const unsigned int *m_pDataIn; // ecx
  int v13; // eax
  unsigned int v14; // edx
  unsigned int v15; // esi
  CUtlMemory<NetMessageCvar_t,int> *p_m_Memory; // esi
  NetMessageCvar_t *m_pMemory; // edi
  int m_nAllocationCount; // eax
  NetMessageCvar_t *v19; // ecx
  int v20; // eax
  NetMessageCvar_t *v21; // edi
  NetMessageCvar_t cvar; // [esp+Ch] [ebp-20Ch] BYREF
  NET_SetConVar *v24; // [esp+214h] [ebp-4h]
  bf_read *buffera; // [esp+220h] [ebp+8h]

  v24 = this;
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v11 = 8 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_15:
        if ( buffer->m_bOverflow )
        {
          v13 = 0;
          goto LABEL_20;
        }
        v14 = buffer->m_nInBufWord;
        v15 = (v14 & CBitBuffer::s_nMaskTable[v11]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v11;
        v5 = v15 | m_nInBufWord;
        v6 = v14 >> v11;
        goto LABEL_18;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v4 = buffer->m_nInBufWord;
  v5 = (unsigned __int8)v4;
  buffer->m_nBitsAvail = m_nBitsAvail - 8;
  if ( m_nBitsAvail == 8 )
  {
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v7 + 1;
    }
    else if ( v7 <= v8 )
    {
      buffer->m_nInBufWord = *v7;
      buffer->m_pDataIn = v7 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
    goto LABEL_19;
  }
  v6 = v4 >> 8;
LABEL_18:
  buffer->m_nInBufWord = v6;
LABEL_19:
  v13 = v5;
LABEL_20:
  p_m_Memory = &v24->m_ConVars.m_Memory;
  v24 = (NET_SetConVar *)p_m_Memory;
  p_m_Memory[1].m_pMemory = nullptr;
  if ( v13 > 0 )
  {
    for ( buffera = (bf_read *)v13; buffera != nullptr; buffera = (bf_read *)((char *)buffera - 1) )
    {
      CBitRead::ReadString(this: buffer, pStr: cvar.name, maxLen: 260, bLine: false, pOutNumChars: nullptr);
      CBitRead::ReadString(this: buffer, pStr: cvar.value, maxLen: 260, bLine: false, pOutNumChars: nullptr);
      m_pMemory = p_m_Memory[1].m_pMemory;
      m_nAllocationCount = p_m_Memory->m_nAllocationCount;
      if ( (int)&m_pMemory->name[1] > m_nAllocationCount )
        CUtlMemory<CConPanel::CNotifyText,int>::Grow(
          this: p_m_Memory,
          num: (int)&m_pMemory->name[-m_nAllocationCount + 1]);
      ++p_m_Memory[1].m_pMemory;
      v19 = p_m_Memory->m_pMemory;
      v20 = (char *)p_m_Memory[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_Memory[1].m_nAllocationCount = (int)p_m_Memory->m_pMemory->name;
      if ( v20 > 0 )
        _V_memmove(dest: &v19[(int)m_pMemory + 1], src: &v19[(_DWORD)m_pMemory], count: 520 * v20);
      v21 = &p_m_Memory->m_pMemory[(_DWORD)m_pMemory];
      if ( v21 != nullptr )
      {
        *v21 = cvar;
        p_m_Memory = (CUtlMemory<NetMessageCvar_t,int> *)v24;
      }
    }
  }
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101C2240
// Name: public: virtual bool NET_SignonState::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NET_SignonState::ReadFromBuffer(NET_SignonState *this, bf_read *buffer)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  unsigned int v4; // edi
  int v5; // ebx
  unsigned int v6; // edi
  const unsigned int *v7; // eax
  const unsigned int *v8; // ecx
  const unsigned int *m_pBufferEnd; // edi
  unsigned int m_nInBufWord; // ebx
  int v11; // eax
  const unsigned int *m_pDataIn; // ecx
  int v13; // eax
  unsigned int v14; // edi
  unsigned int v15; // edx
  int v16; // ecx
  int v17; // eax
  int v18; // ecx
  const unsigned int *v19; // ecx
  const unsigned int *v20; // edi
  const unsigned int *v21; // edi
  unsigned int v22; // ebx
  int v23; // eax
  const unsigned int *v24; // ecx
  unsigned int v25; // edi
  unsigned int v26; // edx
  unsigned int v27; // edi
  int v28; // ecx
  int v29; // eax
  int v30; // ecx
  const unsigned int *v31; // ecx
  const unsigned int *v32; // edi
  const unsigned int *v33; // edi
  unsigned int v34; // ebx
  int v35; // eax
  const unsigned int *v36; // ecx
  unsigned int v37; // edi
  unsigned int v38; // edx
  unsigned int v39; // edi
  int v40; // ecx
  unsigned int v41; // eax
  int v42; // ecx
  int v43; // edi
  const unsigned int *v44; // ecx
  const unsigned int *v45; // ebx
  const unsigned int *v46; // edi
  unsigned int v47; // ebx
  int v48; // eax
  const unsigned int *v49; // ecx
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v52; // eax
  int v53; // ecx
  unsigned int v54; // eax
  int v55; // ecx
  const unsigned int *v56; // ecx
  const unsigned int *v57; // ebx
  int v58; // edi
  unsigned int v59; // edi
  unsigned int v60; // edx
  int v61; // ebx
  const unsigned int *v63; // edi
  unsigned int v64; // ebx
  int v65; // eax
  const unsigned int *v66; // ecx
  unsigned int v67; // edi
  unsigned int v68; // edx

  m_nBitsAvail = buffer->m_nBitsAvail;
  v3 = 0;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = buffer->m_pBufferEnd;
    m_nInBufWord = buffer->m_nInBufWord;
    v11 = 8 - m_nBitsAvail;
    m_pDataIn = buffer->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_15:
        if ( buffer->m_bOverflow )
        {
          v13 = 0;
          goto LABEL_20;
        }
        v14 = buffer->m_nInBufWord;
        v15 = (v14 & CBitBuffer::s_nMaskTable[v11]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v11;
        v5 = v15 | m_nInBufWord;
        v6 = v14 >> v11;
        v3 = 0;
        goto LABEL_18;
      }
      buffer->m_nInBufWord = *m_pDataIn;
    }
    buffer->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v4 = buffer->m_nInBufWord;
  v5 = (unsigned __int8)v4;
  buffer->m_nBitsAvail = m_nBitsAvail - 8;
  if ( m_nBitsAvail == 8 )
  {
    v7 = buffer->m_pDataIn;
    v8 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v7 + 1;
    }
    else if ( v7 <= v8 )
    {
      buffer->m_nInBufWord = *v7;
      buffer->m_pDataIn = v7 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
    goto LABEL_19;
  }
  v6 = v4 >> 8;
LABEL_18:
  buffer->m_nInBufWord = v6;
LABEL_19:
  v13 = v5;
LABEL_20:
  this->m_nSignonState = v13;
  v16 = buffer->m_nBitsAvail;
  if ( v16 >= 32 )
  {
    v17 = buffer->m_nInBufWord;
    v18 = v16 - 32;
    buffer->m_nBitsAvail = v18;
    if ( v18 != 0 )
    {
      buffer->m_nInBufWord = 0;
    }
    else
    {
      v19 = buffer->m_pDataIn;
      v20 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v19 == v20 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v19 + 1;
      }
      else if ( v19 <= v20 )
      {
        buffer->m_nInBufWord = *v19;
        buffer->m_pDataIn = v19 + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
    }
    goto LABEL_37;
  }
  v21 = buffer->m_pBufferEnd;
  v22 = buffer->m_nInBufWord;
  v23 = 32 - v16;
  v24 = buffer->m_pDataIn;
  if ( v24 == v21 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v24 > v21 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_34;
    }
    buffer->m_nInBufWord = *v24;
  }
  buffer->m_pDataIn = v24 + 1;
LABEL_34:
  if ( buffer->m_bOverflow )
  {
    v17 = 0;
  }
  else
  {
    v25 = buffer->m_nInBufWord;
    v26 = (v25 & CBitBuffer::s_nMaskTable[v23]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v23;
    v27 = v25 >> v23;
    v17 = v26 | v22;
    v3 = 0;
    buffer->m_nInBufWord = v27;
  }
LABEL_37:
  this->m_nSpawnCount = v17;
  v28 = buffer->m_nBitsAvail;
  if ( v28 >= 32 )
  {
    v29 = buffer->m_nInBufWord;
    v30 = v28 - 32;
    buffer->m_nBitsAvail = v30;
    if ( v30 != 0 )
    {
      buffer->m_nInBufWord = 0;
    }
    else
    {
      v31 = buffer->m_pDataIn;
      v32 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v31 == v32 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v31 + 1;
      }
      else if ( v31 <= v32 )
      {
        buffer->m_nInBufWord = *v31;
        buffer->m_pDataIn = v31 + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
    }
    goto LABEL_54;
  }
  v33 = buffer->m_pBufferEnd;
  v34 = buffer->m_nInBufWord;
  v35 = 32 - v28;
  v36 = buffer->m_pDataIn;
  if ( v36 == v33 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v36 > v33 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_51;
    }
    buffer->m_nInBufWord = *v36;
  }
  buffer->m_pDataIn = v36 + 1;
LABEL_51:
  if ( buffer->m_bOverflow )
  {
    v29 = 0;
  }
  else
  {
    v37 = buffer->m_nInBufWord;
    v38 = (v37 & CBitBuffer::s_nMaskTable[v35]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v35;
    v39 = v37 >> v35;
    v29 = v38 | v34;
    v3 = 0;
    buffer->m_nInBufWord = v39;
  }
LABEL_54:
  this->m_numServerPlayers = v29;
  v40 = buffer->m_nBitsAvail;
  if ( v40 >= 32 )
  {
    v41 = buffer->m_nInBufWord;
    v42 = v40 - 32;
    buffer->m_nBitsAvail = v42;
    if ( v42 != 0 )
    {
      buffer->m_nInBufWord = 0;
      v43 = v41;
    }
    else
    {
      v44 = buffer->m_pDataIn;
      v45 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v44 == v45 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v44 + 1;
        v43 = v41;
      }
      else
      {
        if ( v44 <= v45 )
        {
          buffer->m_nInBufWord = *v44;
          buffer->m_pDataIn = v44 + 1;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        v43 = v41;
      }
    }
    goto LABEL_84;
  }
  v46 = buffer->m_pBufferEnd;
  v47 = buffer->m_nInBufWord;
  v48 = 32 - v40;
  v49 = buffer->m_pDataIn;
  if ( v49 == v46 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_68:
    buffer->m_pDataIn = v49 + 1;
    goto LABEL_69;
  }
  if ( v49 <= v46 )
  {
    buffer->m_nInBufWord = *v49;
    goto LABEL_68;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_69:
  if ( buffer->m_bOverflow )
  {
    v43 = 0;
    goto LABEL_71;
  }
  v59 = buffer->m_nInBufWord;
  v60 = (v59 & CBitBuffer::s_nMaskTable[v48]) << buffer->m_nBitsAvail;
  buffer->m_nBitsAvail = 32 - v48;
  v61 = v60 | v47;
  v3 = 0;
  buffer->m_nInBufWord = v59 >> v48;
  v43 = v61;
LABEL_84:
  if ( v43 > 4160 )
    return false;
LABEL_71:
  this->m_PlayersNetworkIds.m_Size = 0;
  if ( v43 == 0 )
    goto LABEL_79;
  m_nAllocationCount = this->m_PlayersNetworkIds.m_Memory.m_nAllocationCount;
  if ( v43 > m_nAllocationCount )
  {
    CUtlMemory<bool,int>::Grow(this: &this->m_PlayersNetworkIds.m_Memory, num: v43 - m_nAllocationCount);
    v3 = 0;
  }
  this->m_PlayersNetworkIds.m_Size += v43;
  m_pMemory = this->m_PlayersNetworkIds.m_Memory.m_pMemory;
  v52 = this->m_PlayersNetworkIds.m_Size - v43;
  this->m_PlayersNetworkIds.m_pElements = m_pMemory;
  if ( v52 > 0 )
  {
    if ( v43 <= 0 )
      goto LABEL_79;
    _V_memmove(dest: &m_pMemory[v43], src: m_pMemory, count: v52);
    v3 = 0;
  }
  if ( v43 > 0 )
  {
    CBitRead::ReadBytes(this: buffer, pOut: this->m_PlayersNetworkIds.m_Memory.m_pMemory, nBytes: v43);
    v3 = 0;
  }
LABEL_79:
  v53 = buffer->m_nBitsAvail;
  if ( v53 < 32 )
  {
    v63 = buffer->m_pBufferEnd;
    v64 = buffer->m_nInBufWord;
    v65 = 32 - v53;
    v66 = buffer->m_pDataIn;
    if ( v66 == v63 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v66 > v63 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
LABEL_96:
        if ( buffer->m_bOverflow )
        {
          v58 = 0;
          goto LABEL_100;
        }
        v67 = buffer->m_nInBufWord;
        v68 = (v67 & CBitBuffer::s_nMaskTable[v65]) << buffer->m_nBitsAvail;
        buffer->m_nBitsAvail = 32 - v65;
        buffer->m_nInBufWord = v67 >> v65;
        v58 = v68 | v64;
        goto LABEL_99;
      }
      buffer->m_nInBufWord = *v66;
    }
    buffer->m_pDataIn = v66 + 1;
    goto LABEL_96;
  }
  v54 = buffer->m_nInBufWord;
  v55 = v53 - 32;
  buffer->m_nBitsAvail = v55;
  if ( v55 == 0 )
  {
    v56 = buffer->m_pDataIn;
    v57 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v56 == v57 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_pDataIn = v56 + 1;
      buffer->m_nInBufWord = 0;
      v58 = v54;
      goto LABEL_99;
    }
    if ( v56 > v57 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      v58 = v54;
      goto LABEL_99;
    }
    v3 = *v56;
    buffer->m_pDataIn = v56 + 1;
  }
  buffer->m_nInBufWord = v3;
  v58 = v54;
LABEL_99:
  if ( v58 > 32 )
    return false;
LABEL_100:
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(this: &this->m_Mapname, count: v58);
  if ( v58 > 0 )
    CBitRead::ReadBytes(this: buffer, pOut: this->m_Mapname.m_Memory.m_pMemory, nBytes: v58);
  return !buffer->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x101C2720
// Name: public: virtual bool SVC_ClassInfo::ReadFromBuffer(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_ClassInfo::ReadFromBuffer(SVC_ClassInfo *this, bf_read *buffer)
{
  SVC_ClassInfo *v3; // edi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  __int16 v6; // dx
  int v7; // ecx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  const unsigned int *v10; // edx
  unsigned int v11; // ebx
  int v12; // eax
  const unsigned int *v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // edi
  __int16 v16; // bx
  signed int v18; // ebx
  unsigned int v19; // eax
  int v20; // ecx
  bool v21; // zf
  const unsigned int *v22; // eax
  const unsigned int *v23; // edx
  int v24; // ecx
  unsigned int v25; // eax
  unsigned int v26; // edx
  int v27; // ecx
  int v28; // eax
  const unsigned int *v29; // eax
  const unsigned int *v30; // ecx
  unsigned int v31; // ecx
  const unsigned int *v32; // edx
  unsigned int v33; // edi
  int v34; // eax
  const unsigned int *v35; // ecx
  unsigned int v36; // edx
  unsigned int v37; // ebx
  int v38; // edi
  unsigned int v39; // edx
  SVC_ClassInfo::class_s serverclass; // [esp+Ch] [ebp-20Ch] BYREF
  int nServerClassBits; // [esp+210h] [ebp-8h]
  SVC_ClassInfo *v42; // [esp+214h] [ebp-4h]
  int i; // [esp+220h] [ebp+8h]

  v3 = this;
  this->m_Classes.m_Size = 0;
  m_nBitsAvail = buffer->m_nBitsAvail;
  v42 = v3;
  if ( m_nBitsAvail >= 16 )
  {
    m_nInBufWord = buffer->m_nInBufWord;
    v6 = m_nInBufWord;
    v7 = m_nBitsAvail - 16;
    buffer->m_nBitsAvail = v7;
    if ( v7 != 0 )
    {
      buffer->m_nInBufWord = HIWORD(m_nInBufWord);
    }
    else
    {
      m_pDataIn = buffer->m_pDataIn;
      m_pBufferEnd = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        buffer->m_nInBufWord = *m_pDataIn;
        buffer->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
    }
    goto LABEL_18;
  }
  v10 = buffer->m_pBufferEnd;
  v11 = buffer->m_nInBufWord;
  v12 = 16 - m_nBitsAvail;
  v13 = buffer->m_pDataIn;
  if ( v13 == v10 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
  }
  else
  {
    if ( v13 > v10 )
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
      goto LABEL_15;
    }
    buffer->m_nInBufWord = *v13;
  }
  buffer->m_pDataIn = v13 + 1;
LABEL_15:
  if ( buffer->m_bOverflow )
  {
    v6 = 0;
  }
  else
  {
    v14 = buffer->m_nInBufWord;
    v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v12;
    v16 = v15 | v11;
    v3 = v42;
    buffer->m_nInBufWord = v14 >> v12;
    v6 = v16;
  }
LABEL_18:
  v3->m_nNumServerClasses = v6;
  if ( v6 <= 0 )
  {
    _Warning(a1: "SVC_ClassInfo::ReadFromBuffer:  bad numserverclasses %d\n", v6);
    return false;
  }
  v18 = Q_log2(val: v6) + 1;
  v19 = buffer->m_nInBufWord;
  v20 = v19 & 1;
  v21 = buffer->m_nBitsAvail-- == 1;
  nServerClassBits = v18;
  if ( v21 )
  {
    v22 = buffer->m_pDataIn;
    v23 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v22 == v23 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v22 + 1;
    }
    else if ( v22 <= v23 )
    {
      buffer->m_nInBufWord = *v22;
      buffer->m_pDataIn = v22 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v19 >> 1;
  }
  v3->m_bCreateOnClient = v20 != 0;
  if ( v20 == 0 )
  {
    i = 0;
    if ( v3->m_nNumServerClasses > 0 )
    {
      while ( 1 )
      {
        v24 = buffer->m_nBitsAvail;
        if ( v24 < v18 )
          break;
        v25 = buffer->m_nInBufWord;
        v26 = v25 & CBitBuffer::s_nMaskTable[v18];
        v27 = v24 - v18;
        buffer->m_nBitsAvail = v27;
        if ( v27 != 0 )
        {
          buffer->m_nInBufWord = v25 >> v18;
          v28 = v26;
        }
        else
        {
          v29 = buffer->m_pDataIn;
          v30 = buffer->m_pBufferEnd;
          buffer->m_nBitsAvail = 32;
          if ( v29 == v30 )
          {
            buffer->m_pDataIn = v29 + 1;
            buffer->m_nBitsAvail = 1;
            buffer->m_nInBufWord = 0;
            v28 = v26;
          }
          else
          {
            if ( v29 <= v30 )
            {
              v31 = *v29;
              buffer->m_pDataIn = v29 + 1;
              buffer->m_nInBufWord = v31;
            }
            else
            {
              buffer->m_bOverflow = true;
              buffer->m_nInBufWord = 0;
            }
            v28 = v26;
          }
        }
LABEL_48:
        serverclass.classID = v28;
        CBitRead::ReadString(
          this: buffer,
          pStr: serverclass.classname,
          maxLen: 256,
          bLine: false,
          pOutNumChars: nullptr);
        CBitRead::ReadString(
          this: buffer,
          pStr: serverclass.datatablename,
          maxLen: 256,
          bLine: false,
          pOutNumChars: nullptr);
        CUtlVector<SVC_ClassInfo::class_s,CUtlMemory<SVC_ClassInfo::class_s,int>>::InsertBefore(
          this: &v3->m_Classes,
          elem: v3->m_Classes.m_Size,
          src: &serverclass);
        if ( ++i >= v3->m_nNumServerClasses )
          return !buffer->m_bOverflow;
      }
      v32 = buffer->m_pBufferEnd;
      v33 = buffer->m_nInBufWord;
      v34 = v18 - v24;
      v35 = buffer->m_pDataIn;
      if ( v35 == v32 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_bOverflow = true;
      }
      else
      {
        if ( v35 > v32 )
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
LABEL_44:
          if ( buffer->m_bOverflow )
          {
            v28 = 0;
          }
          else
          {
            v36 = buffer->m_nInBufWord;
            v37 = (v36 & CBitBuffer::s_nMaskTable[v34]) << buffer->m_nBitsAvail;
            buffer->m_nBitsAvail = 32 - v34;
            v38 = v37 | v33;
            v18 = nServerClassBits;
            v39 = v36 >> v34;
            v28 = v38;
            buffer->m_nInBufWord = v39;
          }
          v3 = v42;
          goto LABEL_48;
        }
        buffer->m_nInBufWord = *v35;
      }
      buffer->m_pDataIn = v35 + 1;
      goto LABEL_44;
    }
  }
  return !buffer->m_bOverflow;
}

} // namespace engine_xlsp
