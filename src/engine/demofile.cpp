// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/demofile.cpp
// Functions: 32
// ============================================================

#include "engine\demofile.h"

//------------------------------------------------------------------------------
// Address: 0x100B85A0
// Name: public: CDbgPrint::CDbgPrint(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDbgPrint *__thiscall CDbgPrint::CDbgPrint(CDbgPrint *this, const char *pMsg)
{
  int v3; // eax
  int v4; // esi

  v3 = ++CDbgPrint::s_nIndent;
  if ( dbg_demofile.m_pParent != nullptr && dbg_demofile.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = 0;
    if ( 3 * v3 > 0 )
    {
      do
      {
        DevMsg(a1: " ");
        ++v4;
      }
      while ( v4 < 3 * CDbgPrint::s_nIndent );
    }
    DevMsg(a1: pMsg);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B8600
// Name: public: CDemoFile::CDemoFile(void)
// Source: json
//------------------------------------------------------------------------------
CDemoFile *__thiscall CDemoFile::CDemoFile(CDemoFile *this)
{
  this->m_pBuffer = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B8610
// Name: public: void CDemoFile::WriteSequenceInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteSequenceInfo(CDemoFile *this, int nSeqNrIn, int nSeqNrOut)
{
  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&nSeqNrIn + 3, pMsg: "WriteSequenceInfo()\n");
  this->m_pBuffer->PutInt(this: this->m_pBuffer, a2: nSeqNrIn);
  this->m_pBuffer->PutInt(this: this->m_pBuffer, a2: nSeqNrOut);
  --CDbgPrint::s_nIndent;
}

//------------------------------------------------------------------------------
// Address: 0x100B8650
// Name: public: void CDemoFile::ReadSequenceInfo(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::ReadSequenceInfo(CDemoFile *this, int *nSeqNrIn, int *nSeqNrOut)
{
  *nSeqNrIn = this->m_pBuffer->GetInt(this: this->m_pBuffer);
  *nSeqNrOut = this->m_pBuffer->GetInt(this: this->m_pBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x100B8680
// Name: public: void CDemoFile::WriteCmdInfo(struct democmdinfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteCmdInfo(CDemoFile *this, democmdinfo_t *info)
{
  democmdinfo_t littleEndianInfo; // [esp+Ch] [ebp-98h] BYREF

  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&info + 3, pMsg: "WriteCmdInfo()\n");
  littleEndianInfo = *info;
  this->m_pBuffer->Put(this: this->m_pBuffer, a2: &littleEndianInfo, a3: 152);
  --CDbgPrint::s_nIndent;
}

//------------------------------------------------------------------------------
// Address: 0x100B86E0
// Name: public: void CDemoFile::ReadCmdInfo(struct democmdinfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::ReadCmdInfo(CDemoFile *this, democmdinfo_t *info)
{
  this->m_pBuffer->Get(this: this->m_pBuffer, a2: info, a3: 152);
}

//------------------------------------------------------------------------------
// Address: 0x100B8700
// Name: public: void CDemoFile::WriteCmdHeader(unsigned char,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteCmdHeader(CDemoFile *this, int cmd, int tick, int nPlayerSlot)
{
  int v5; // edi
  char *cmdname[10]; // [esp+Ch] [ebp-28h]

  if ( dbg_demofile.m_pParent != nullptr && dbg_demofile.m_pParent->m_Value.m_nValue != 0 )
    DevMsg(a1: "----------------------------------------\n");
  this->m_pBuffer->PutUnsignedChar(this: this->m_pBuffer, a2: cmd);
  v5 = tick;
  this->m_pBuffer->WriteTick(this: this->m_pBuffer, a2: tick);
  this->m_pBuffer->PutChar(this: this->m_pBuffer, a2: nPlayerSlot);
  cmdname[0] = "dem_unknown";
  cmdname[1] = "dem_signon";
  cmdname[2] = "dem_packet";
  cmdname[3] = "dem_synctick";
  cmdname[4] = "dem_consolecmd";
  cmdname[5] = "dem_usercmd";
  cmdname[6] = "dem_datatables";
  cmdname[7] = "dem_stop";
  cmdname[8] = "dem_customdata";
  cmdname[9] = "dem_stringtables";
  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&cmd + 3, pMsg: "WriteCmdHeader()...");
  if ( dbg_demofile.m_pParent != nullptr && dbg_demofile.m_pParent->m_Value.m_nValue != 0 )
    DevMsg(a1: "tick %i, cmd %s \n", v5, cmdname[(unsigned __int8)cmd]);
  --CDbgPrint::s_nIndent;
}

//------------------------------------------------------------------------------
// Address: 0x100B87F0
// Name: public: void CDemoFile::ReadCmdHeader(unsigned char __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::ReadCmdHeader(CDemoFile *this, unsigned __int8 *cmd, int *tick, int *nPlayerSlot)
{
  unsigned __int8 v5; // al

  *cmd = this->m_pBuffer->GetUnsignedChar(this: this->m_pBuffer);
  if ( this->m_pBuffer != nullptr && this->m_pBuffer->IsValid(this: this->m_pBuffer) )
  {
    v5 = *cmd;
    if ( *cmd != 0 && v5 <= 9u )
    {
      *tick = this->m_pBuffer->GetInt(this: this->m_pBuffer);
      *nPlayerSlot = this->m_pBuffer->GetChar(this: this->m_pBuffer);
    }
    else
    {
      _ConDMsg(a1: "Unexepcted command token [%d] in .demo file\n", v5);
      *cmd = 7;
    }
  }
  else
  {
    _ConDMsg(a1: "Missing end tag in demo file.\n");
    *cmd = 7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8890
// Name: public: unsigned int CDemoFile::GetCurPos(bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDemoFile::GetCurPos(CDemoFile *this, bool bRead)
{
  IDemoBuffer_vtbl *v3; // eax

  if ( this->m_pBuffer == nullptr || !this->m_pBuffer->IsInitialized(this: this->m_pBuffer) )
    return 0;
  v3 = this->m_pBuffer->__vftable;
  if ( bRead )
    return ((unsigned int (*)(void))v3->TellGet)();
  else
    return ((unsigned int (*)(void))v3->TellPut)();
}

//------------------------------------------------------------------------------
// Address: 0x100B88E0
// Name: public: void CDemoFile::WriteCustomData(int,void const __near *,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteCustomData(
        CDemoFile *this,
        int iCallbackIndex,
        const void *pData,
        unsigned int iDataSize,
        int tick)
{
  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&tick + 3, pMsg: "WriteCustomData()\n");
  if ( this->m_pBuffer != nullptr && this->m_pBuffer->IsInitialized(this: this->m_pBuffer) )
  {
    CDemoFile::WriteCmdHeader(this, cmd: 8, tick, nPlayerSlot: 0);
    this->m_pBuffer->PutInt(this: this->m_pBuffer, a2: iCallbackIndex);
    this->m_pBuffer->PutInt(this: this->m_pBuffer, a2: iDataSize);
    this->m_pBuffer->Put(this: this->m_pBuffer, a2: pData, a3: iDataSize);
  }
  --CDbgPrint::s_nIndent;
}

//------------------------------------------------------------------------------
// Address: 0x100B8960
// Name: public: void CDemoFile::SeekTo(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::SeekTo(CDemoFile *this, int position, bool bRead)
{
  IDemoBuffer *m_pBuffer; // ecx

  m_pBuffer = this->m_pBuffer;
  if ( bRead )
    m_pBuffer->SeekGet(this: m_pBuffer, a2: true, a3: position);
  else
    m_pBuffer->SeekPut(this: m_pBuffer, a2: true, a3: position);
}

//------------------------------------------------------------------------------
// Address: 0x100B89A0
// Name: public: int CDemoFile::ReadRawData(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoFile::ReadRawData(CDemoFile *this, char *buffer, int length)
{
  int v4; // edi

  v4 = this->m_pBuffer->GetInt(this: this->m_pBuffer);
  if ( buffer == nullptr )
  {
    this->m_pBuffer->SeekGet(this: this->m_pBuffer, a2: false, a3: v4);
    return v4;
  }
  if ( length < v4 )
  {
    DevMsg(a1: "CDemoFile::ReadRawData: buffe overflow (%i).\n", v4);
    return -1;
  }
  this->m_pBuffer->Get(this: this->m_pBuffer, a2: buffer, a3: v4);
  if ( this->m_pBuffer != nullptr && this->m_pBuffer->IsValid(this: this->m_pBuffer) )
    return v4;
  Host_EndGame(bShowMainMenu: true, message: "Error reading demo message data.\n");
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100B8A40
// Name: public: void CDemoFile::WriteRawData(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteRawData(CDemoFile *this, const char *buffer, int length)
{
  int v4; // edi

  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&length + 3, pMsg: "WriteRawData()\n");
  v4 = length;
  this->m_pBuffer->PutInt(this: this->m_pBuffer, a2: length);
  this->m_pBuffer->Put(this: this->m_pBuffer, a2: buffer, a3: v4);
  --CDbgPrint::s_nIndent;
}

//------------------------------------------------------------------------------
// Address: 0x100B8A90
// Name: public: void CDemoFile::WriteDemoHeader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteDemoHeader(CDemoFile *this)
{
  int HostVersion; // eax
  int networkprotocol; // [esp+4h] [ebp-14h]
  CDbgPrint v4; // [esp+17h] [ebp-1h] BYREF

  CDbgPrint::CDbgPrint(this: &v4, pMsg: "WriteDemoHeader()\n");
  DevMsg(a1: "\n");
  DevMsg(a1: "     demofilestamp: %s\n", this->m_DemoHeader.demofilestamp);
  DevMsg(a1: "     demoprotocol (should be %i): %i\n", 4, this->m_DemoHeader.demoprotocol);
  networkprotocol = this->m_DemoHeader.networkprotocol;
  HostVersion = GetHostVersion();
  DevMsg(a1: "     networkprotocol (should be %i): %i\n", HostVersion, networkprotocol);
  DevMsg(a1: "     servername: %s\n", this->m_DemoHeader.servername);
  DevMsg(a1: "     clientname: %s\n", this->m_DemoHeader.clientname);
  DevMsg(a1: "     mapname: %s\n", this->m_DemoHeader.mapname);
  DevMsg(a1: "     gamedirectory: %s\n", this->m_DemoHeader.gamedirectory);
  DevMsg(a1: "     playback_time: %f\n", this->m_DemoHeader.playback_time);
  DevMsg(a1: "     playback_ticks: %i\n", this->m_DemoHeader.playback_ticks);
  DevMsg(a1: "     playback_frames: %i\n", this->m_DemoHeader.playback_frames);
  DevMsg(a1: "     signonlength: %i\n", this->m_DemoHeader.signonlength);
  DevMsg(a1: "\n");
  this->m_pBuffer->WriteHeader(this: this->m_pBuffer, a2: &this->m_DemoHeader, a3: 1072);
  --CDbgPrint::s_nIndent;
}

//------------------------------------------------------------------------------
// Address: 0x100B8B90
// Name: public: struct demoheader_t __near * CDemoFile::ReadDemoHeader(void)
// Source: json
//------------------------------------------------------------------------------
demoheader_t *__thiscall CDemoFile::ReadDemoHeader(CDemoFile *this)
{
  demoheader_t *p_m_DemoHeader; // edi
  int HostVersion; // eax
  int demoprotocol; // esi

  p_m_DemoHeader = &this->m_DemoHeader;
  _V_memset(dest: &this->m_DemoHeader, fill: 0, count: 1072);
  if ( this->m_pBuffer != nullptr && this->m_pBuffer->IsInitialized(this: this->m_pBuffer) )
  {
    this->m_pBuffer->SeekGet(this: this->m_pBuffer, a2: true, a3: 0);
    this->m_pBuffer->Get(this: this->m_pBuffer, a2: p_m_DemoHeader, a3: 1072);
    if ( this->m_pBuffer->IsValid(this: this->m_pBuffer) )
    {
      if ( _V_strcmp(s1: p_m_DemoHeader->demofilestamp, s2: "HL2DEMO") != 0 )
      {
        ConMsg(a1: "%s has invalid demo header ID.\n", this->m_szFileName);
        return nullptr;
      }
      if ( this->m_DemoHeader.networkprotocol != GetHostVersion() )
      {
        HostVersion = GetHostVersion();
        ConMsg(
          a1: "ERROR: demo network protocol %i outdated, engine version is %i \n",
          this->m_DemoHeader.networkprotocol,
          HostVersion);
        return nullptr;
      }
      demoprotocol = this->m_DemoHeader.demoprotocol;
      if ( demoprotocol <= 4 && demoprotocol >= 2 )
        return p_m_DemoHeader;
      ConMsg(a1: "ERROR: demo file protocol %i outdated, engine vnoteersion is %i \n", demoprotocol, 4);
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100B8C80
// Name: public: void CDemoFile::WriteFileBytes(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteFileBytes(CDemoFile *this, void *fh, int length)
{
  int v4; // esi
  unsigned int v5; // esi
  char copybuf[1024]; // [esp+Ch] [ebp-400h] BYREF

  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&length + 3, pMsg: "WriteFileBytes()\n");
  v4 = length;
  if ( length > 1024 )
  {
    v5 = ((unsigned int)(length - 1025) >> 10) + 1;
    length -= v5 << 10;
    do
    {
      g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: copybuf, a3: 1024, a4: fh);
      this->m_pBuffer->Put(this: this->m_pBuffer, a2: copybuf, a3: 1024);
      --v5;
    }
    while ( v5 != 0 );
    v4 = length;
  }
  g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: copybuf, a3: v4, a4: fh);
  this->m_pBuffer->Put(this: this->m_pBuffer, a2: copybuf, a3: v4);
  g_pFileSystem->Flush(this: &g_pFileSystem->IBaseFileSystem, a2: fh);
  --CDbgPrint::s_nIndent;
}

//------------------------------------------------------------------------------
// Address: 0x100B8D50
// Name: public: bool CDemoFile::IsOpen(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDemoFile::IsOpen(CDemoFile *this)
{
  return this->m_pBuffer != nullptr && this->m_pBuffer->IsInitialized(this: this->m_pBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x100B8D80
// Name: public: void CDemoFile::Close(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::Close(CDemoFile *this)
{
  IDemoBuffer *m_pBuffer; // ecx

  m_pBuffer = this->m_pBuffer;
  if ( m_pBuffer != nullptr )
    ((void (__thiscall *)(IDemoBuffer *, int))m_pBuffer->dtr_IBaseInterface)(a1: m_pBuffer, a2: 1);
  this->m_pBuffer = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100B8DB0
// Name: public: int CDemoFile::GetSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoFile::GetSize(CDemoFile *this)
{
  return this->m_pBuffer->TellMaxPut(this: this->m_pBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x100B8DC0
// Name: public: CDemoFile::~CDemoFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::~CDemoFile(CDemoFile *this)
{
  IDemoBuffer *m_pBuffer; // ecx
  IDemoBuffer *v3; // ecx

  m_pBuffer = this->m_pBuffer;
  if ( m_pBuffer != nullptr && m_pBuffer->IsInitialized(this: m_pBuffer) )
  {
    v3 = this->m_pBuffer;
    if ( v3 != nullptr )
      ((void (__thiscall *)(IDemoBuffer *, int))v3->dtr_IBaseInterface)(a1: v3, a2: 1);
    this->m_pBuffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8E00
// Name: public: void CDemoFile::WriteConsoleCommand(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteConsoleCommand(CDemoFile *this, const char *cmdstring, int tick, int nPlayerSlot)
{
  const char *v5; // ebx
  int v6; // esi

  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&cmdstring + 3, pMsg: "WriteConsoleCommand()\n");
  v5 = cmdstring;
  if ( cmdstring != nullptr
    && *cmdstring != 0
    && this->m_pBuffer != nullptr
    && this->m_pBuffer->IsInitialized(this: this->m_pBuffer) )
  {
    v6 = _V_strlen(str: v5) + 1;
    if ( v6 >= 1024 )
    {
      DevMsg(a1: "CDemoFile::WriteConsoleCommand: command too long (>1024).\n");
      --CDbgPrint::s_nIndent;
      return;
    }
    CDemoFile::WriteCmdHeader(this, cmd: 4, tick, nPlayerSlot);
    CDemoFile::WriteRawData(this, buffer: v5, length: v6);
  }
  --CDbgPrint::s_nIndent;
}

//------------------------------------------------------------------------------
// Address: 0x100B8EA0
// Name: public: char const __near * CDemoFile::ReadConsoleCommand(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CDemoFile::ReadConsoleCommand(CDemoFile *this)
{
  CDemoFile::ReadRawData(this, buffer: cmdstring, length: 1024);
  return cmdstring;
}

//------------------------------------------------------------------------------
// Address: 0x100B8EC0
// Name: public: void CDemoFile::WriteNetworkDataTables(class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteNetworkDataTables(CDemoFile *this, bf_write *buf, int tick)
{
  unsigned __int8 *m_pData; // ebx
  int v5; // esi

  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&tick + 3, pMsg: "WriteNetworkDataTables()\n");
  if ( this->m_pBuffer != nullptr && this->m_pBuffer->IsInitialized(this: this->m_pBuffer) )
  {
    CDemoFile::WriteCmdHeader(this, cmd: 6, tick, nPlayerSlot: 0);
    m_pData = buf->m_pData;
    v5 = (buf->m_iCurBit + 7) >> 3;
    CDbgPrint::CDbgPrint(this: (CDbgPrint *)&tick + 3, pMsg: "WriteRawData()\n");
    this->m_pBuffer->PutInt(this: this->m_pBuffer, a2: v5);
    this->m_pBuffer->Put(this: this->m_pBuffer, a2: m_pData, a3: v5);
    CDbgPrint::s_nIndent -= 2;
  }
  else
  {
    DevMsg(a1: "CDemoFile::WriteNetworkDataTables: Haven't opened file yet!\n");
    --CDbgPrint::s_nIndent;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8F60
// Name: public: int CDemoFile::ReadStringTables(class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoFile::ReadStringTables(CDemoFile *this, bf_read *buf)
{
  char *m_pData; // esi
  int m_nDataBits; // ecx
  int v6; // esi

  if ( buf != nullptr )
  {
    m_pData = (char *)buf->m_pData;
    if ( m_pData != nullptr )
    {
      m_nDataBits = 32 * (((char *)buf->m_pDataIn - m_pData) >> 2) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3);
      if ( m_nDataBits >= buf->m_nDataBits )
        m_nDataBits = buf->m_nDataBits;
    }
    else
    {
      m_nDataBits = 0;
    }
    return CDemoFile::ReadRawData(this, buffer: m_pData, length: (buf->m_nDataBits - m_nDataBits) >> 3);
  }
  else
  {
    v6 = this->m_pBuffer->GetInt(this: this->m_pBuffer);
    this->m_pBuffer->SeekGet(this: this->m_pBuffer, a2: false, a3: v6);
    return v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8FE0
// Name: public: void CDemoFile::WriteStringTables(class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteStringTables(CDemoFile *this, bf_write *buf, int tick)
{
  unsigned __int8 *m_pData; // ebx
  int v5; // esi

  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&tick + 3, pMsg: "WriteStringTables()\n");
  if ( this->m_pBuffer != nullptr && this->m_pBuffer->IsInitialized(this: this->m_pBuffer) )
  {
    CDemoFile::WriteCmdHeader(this, cmd: 9, tick, nPlayerSlot: 0);
    m_pData = buf->m_pData;
    v5 = (buf->m_iCurBit + 7) >> 3;
    CDbgPrint::CDbgPrint(this: (CDbgPrint *)&tick + 3, pMsg: "WriteRawData()\n");
    this->m_pBuffer->PutInt(this: this->m_pBuffer, a2: v5);
    this->m_pBuffer->Put(this: this->m_pBuffer, a2: m_pData, a3: v5);
    CDbgPrint::s_nIndent -= 2;
  }
  else
  {
    DevMsg(a1: "CDemoFile::WriteStringTables: Haven't opened file yet!\n");
    --CDbgPrint::s_nIndent;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9080
// Name: public: void CDemoFile::WriteUserCmd(int,char const __near *,unsigned char,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteUserCmd(
        CDemoFile *this,
        int cmdnumber,
        const char *buffer,
        int bytes,
        int tick,
        int nPlayerSlot)
{
  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&bytes + 3, pMsg: "WriteUserCmd()\n");
  if ( this->m_pBuffer != nullptr && this->m_pBuffer->IsInitialized(this: this->m_pBuffer) )
  {
    CDemoFile::WriteCmdHeader(this, cmd: 5, tick, nPlayerSlot);
    this->m_pBuffer->PutInt(this: this->m_pBuffer, a2: cmdnumber);
    CDbgPrint::CDbgPrint(this: (CDbgPrint *)&bytes + 3, pMsg: "WriteRawData()\n");
    this->m_pBuffer->PutInt(this: this->m_pBuffer, a2: (unsigned __int8)bytes);
    this->m_pBuffer->Put(this: this->m_pBuffer, a2: buffer, a3: (unsigned __int8)bytes);
    CDbgPrint::s_nIndent -= 2;
  }
  else
  {
    --CDbgPrint::s_nIndent;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9120
// Name: public: int CDemoFile::ReadUserCmd(char __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoFile::ReadUserCmd(CDemoFile *this, char *buffer, int *size)
{
  int v4; // edi

  v4 = this->m_pBuffer->GetInt(this: this->m_pBuffer);
  *size = CDemoFile::ReadRawData(this, buffer, length: *size);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100B9160
// Name: public: bool CDemoFile::Open(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoFile::Open(CDemoFile *this, const char *name, bool bReadOnly, bool bMemoryBuffer)
{
  IDemoBuffer *m_pBuffer; // ecx
  IDemoBuffer *v7; // eax
  const char *v8; // eax
  IDemoBuffer *v9; // ecx
  DemoBufferInitParams_t v10; // [esp+4h] [ebp-1Ch] BYREF
  const char *v11; // [esp+8h] [ebp-18h]
  int v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  MemoryDemoBufferInitParams_t params; // [esp+18h] [ebp-8h] BYREF

  m_pBuffer = this->m_pBuffer;
  if ( m_pBuffer != nullptr && m_pBuffer->IsInitialized(this: m_pBuffer) )
  {
    ConMsg(a1: "CDemoFile::Open: file already open.\n");
    return 0;
  }
  else
  {
    this->m_szFileName[0] = 0;
    _V_memset(dest: &this->m_DemoHeader, fill: 0, count: 1072);
    if ( bMemoryBuffer )
    {
      params.__vftable = (MemoryDemoBufferInitParams_t_vtbl *)&MemoryDemoBufferInitParams_t::`vftable';
      params.nMaxSize = 0x1000000;
      v7 = CreateDemoBuffer(bMemoryBuffer: true, &params);
    }
    else
    {
      v10.__vftable = (DemoBufferInitParams_t_vtbl *)&StreamDemoBufferInitParams_t::`vftable';
      v11 = name;
      v12 = 0;
      v13 = bReadOnly ? 8 : 0;
      v14 = 0;
      v7 = CreateDemoBuffer(bMemoryBuffer: false, params: &v10);
    }
    this->m_pBuffer = v7;
    if ( v7 != nullptr && v7->IsInitialized(this: v7) )
    {
      V_strncpy(pDest: this->m_szFileName, pSrc: name, maxLen: 260);
      return 1;
    }
    else
    {
      v8 = "reading";
      if ( !bReadOnly )
        v8 = "writing";
      ConMsg(a1: "CDemoFile::Open: couldn't open file %s for %s.\n", name, v8);
      v9 = this->m_pBuffer;
      if ( v9 != nullptr )
        ((void (__thiscall *)(IDemoBuffer *, int))v9->dtr_IBaseInterface)(a1: v9, a2: 1);
      this->m_pBuffer = nullptr;
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9280
// Name: public: int CDemoFile::ReadCustomData(int __near *,unsigned char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoFile::ReadCustomData(CDemoFile *this, int *pCallbackIndex, unsigned __int8 **ppDataChunk)
{
  int v4; // ebx
  int v5; // eax
  int v6; // edi

  if ( (_S2_4 & 1) == 0 )
  {
    _S2_4 |= 1u;
    s_TempMemoryBuffer.m_Memory.m_pMemory = nullptr;
    s_TempMemoryBuffer.m_Memory.m_nAllocationCount = 0;
    s_TempMemoryBuffer.m_Memory.m_nGrowSize = 0;
    s_TempMemoryBuffer.m_Size = 0;
    s_TempMemoryBuffer.m_pElements = nullptr;
    atexit(func: CDemoFile::ReadCustomData_::_2_::_dynamic_atexit_destructor_for__s_TempMemoryBuffer__);
  }
  v4 = this->m_pBuffer->GetInt(this: this->m_pBuffer);
  v5 = this->m_pBuffer->GetInt(this: this->m_pBuffer);
  v6 = v5;
  if ( pCallbackIndex != nullptr && ppDataChunk != nullptr )
  {
    CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
      this: (CUtlVector<char,CUtlMemory<char,int> > *)&s_TempMemoryBuffer,
      count: v5);
    *ppDataChunk = s_TempMemoryBuffer.m_Memory.m_pMemory;
    *pCallbackIndex = v4;
    this->m_pBuffer->Get(this: this->m_pBuffer, a2: s_TempMemoryBuffer.m_Memory.m_pMemory, a3: v6);
    if ( this->m_pBuffer != nullptr && this->m_pBuffer->IsValid(this: this->m_pBuffer) )
    {
      return v6;
    }
    else
    {
      Host_EndGame(bShowMainMenu: true, message: "Error reading demo message data.\n");
      return -1;
    }
  }
  else
  {
    this->m_pBuffer->SeekGet(this: this->m_pBuffer, a2: false, a3: v5);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10322D30
// Name: _CDemoFile::ReadCustomData_::_2_::_dynamic_atexit_destructor_for__s_TempMemoryBuffer__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDemoFile::ReadCustomData_::_2_::_dynamic_atexit_destructor_for__s_TempMemoryBuffer__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_TempMemoryBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x10322D40
// Name: _dynamic_atexit_destructor_for__devshots_nextmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__devshots_nextmap__()
{
  ConCommand::~ConCommand(this: &devshots_nextmap);
}

//------------------------------------------------------------------------------
// Address: 0x10322D50
// Name: _dynamic_atexit_destructor_for__g_DevShotGenerator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DevShotGenerator__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_DevShotGenerator.m_Maps);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100B8250
// Name: public: CDbgPrint::CDbgPrint(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDbgPrint *__thiscall CDbgPrint::CDbgPrint(CDbgPrint *this, const char *pMsg)
{
  int v3; // eax
  int v4; // esi

  v3 = ++CDbgPrint::s_nIndent;
  if ( dbg_demofile.m_pParent != nullptr && dbg_demofile.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = 0;
    if ( 3 * v3 > 0 )
    {
      do
      {
        DevMsg(a1: " ");
        ++v4;
      }
      while ( v4 < 3 * CDbgPrint::s_nIndent );
    }
    DevMsg(a1: pMsg);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B82B0
// Name: public: CDemoFile::CDemoFile(void)
// Source: json
//------------------------------------------------------------------------------
CDemoFile *__thiscall CDemoFile::CDemoFile(CDemoFile *this)
{
  this->m_pBuffer = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B82C0
// Name: public: void CDemoFile::WriteSequenceInfo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteSequenceInfo(CDemoFile *this, int nSeqNrIn, int nSeqNrOut)
{
  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&nSeqNrIn + 3, pMsg: "WriteSequenceInfo()\n");
  this->m_pBuffer->PutInt(this: this->m_pBuffer, a2: nSeqNrIn);
  this->m_pBuffer->PutInt(this: this->m_pBuffer, a2: nSeqNrOut);
  --CDbgPrint::s_nIndent;
}

//------------------------------------------------------------------------------
// Address: 0x100B8300
// Name: public: void CDemoFile::ReadSequenceInfo(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::ReadSequenceInfo(CDemoFile *this, int *nSeqNrIn, int *nSeqNrOut)
{
  *nSeqNrIn = this->m_pBuffer->GetInt(this: this->m_pBuffer);
  *nSeqNrOut = this->m_pBuffer->GetInt(this: this->m_pBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x100B8330
// Name: public: void CDemoFile::WriteCmdInfo(struct democmdinfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteCmdInfo(CDemoFile *this, democmdinfo_t *info)
{
  democmdinfo_t littleEndianInfo; // [esp+Ch] [ebp-98h] BYREF

  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&info + 3, pMsg: "WriteCmdInfo()\n");
  littleEndianInfo = *info;
  this->m_pBuffer->Put(this: this->m_pBuffer, a2: &littleEndianInfo, a3: 152);
  --CDbgPrint::s_nIndent;
}

//------------------------------------------------------------------------------
// Address: 0x100B8390
// Name: public: void CDemoFile::ReadCmdInfo(struct democmdinfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::ReadCmdInfo(CDemoFile *this, democmdinfo_t *info)
{
  this->m_pBuffer->Get(this: this->m_pBuffer, a2: info, a3: 152);
}

//------------------------------------------------------------------------------
// Address: 0x100B83B0
// Name: public: void CDemoFile::WriteCmdHeader(unsigned char,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteCmdHeader(CDemoFile *this, int cmd, int tick, int nPlayerSlot)
{
  int v5; // edi
  char *cmdname[10]; // [esp+Ch] [ebp-28h]

  if ( dbg_demofile.m_pParent != nullptr && dbg_demofile.m_pParent->m_Value.m_nValue != 0 )
    DevMsg(a1: "----------------------------------------\n");
  this->m_pBuffer->PutUnsignedChar(this: this->m_pBuffer, a2: cmd);
  v5 = tick;
  this->m_pBuffer->WriteTick(this: this->m_pBuffer, a2: tick);
  this->m_pBuffer->PutChar(this: this->m_pBuffer, a2: nPlayerSlot);
  cmdname[0] = "dem_unknown";
  cmdname[1] = "dem_signon";
  cmdname[2] = "dem_packet";
  cmdname[3] = "dem_synctick";
  cmdname[4] = "dem_consolecmd";
  cmdname[5] = "dem_usercmd";
  cmdname[6] = "dem_datatables";
  cmdname[7] = "dem_stop";
  cmdname[8] = "dem_customdata";
  cmdname[9] = "dem_stringtables";
  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&cmd + 3, pMsg: "WriteCmdHeader()...");
  if ( dbg_demofile.m_pParent != nullptr && dbg_demofile.m_pParent->m_Value.m_nValue != 0 )
    DevMsg(a1: "tick %i, cmd %s \n", v5, cmdname[(unsigned __int8)cmd]);
  --CDbgPrint::s_nIndent;
}

//------------------------------------------------------------------------------
// Address: 0x100B84A0
// Name: public: void CDemoFile::ReadCmdHeader(unsigned char __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::ReadCmdHeader(CDemoFile *this, unsigned __int8 *cmd, int *tick, int *nPlayerSlot)
{
  unsigned __int8 v5; // al

  *cmd = this->m_pBuffer->GetUnsignedChar(this: this->m_pBuffer);
  if ( this->m_pBuffer != nullptr && this->m_pBuffer->IsValid(this: this->m_pBuffer) )
  {
    v5 = *cmd;
    if ( *cmd != 0 && v5 <= 9u )
    {
      *tick = this->m_pBuffer->GetInt(this: this->m_pBuffer);
      *nPlayerSlot = this->m_pBuffer->GetChar(this: this->m_pBuffer);
    }
    else
    {
      _ConDMsg(a1: "Unexepcted command token [%d] in .demo file\n", v5);
      *cmd = 7;
    }
  }
  else
  {
    _ConDMsg(a1: "Missing end tag in demo file.\n");
    *cmd = 7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8540
// Name: public: unsigned int CDemoFile::GetCurPos(bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDemoFile::GetCurPos(CDemoFile *this, bool bRead)
{
  IDemoBuffer_vtbl *v3; // eax

  if ( this->m_pBuffer == nullptr || !this->m_pBuffer->IsInitialized(this: this->m_pBuffer) )
    return 0;
  v3 = this->m_pBuffer->__vftable;
  if ( bRead )
    return ((unsigned int (*)(void))v3->TellGet)();
  else
    return ((unsigned int (*)(void))v3->TellPut)();
}

//------------------------------------------------------------------------------
// Address: 0x100B8590
// Name: public: void CDemoFile::WriteCustomData(int,void const __near *,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteCustomData(
        CDemoFile *this,
        int iCallbackIndex,
        const void *pData,
        unsigned int iDataSize,
        int tick)
{
  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&tick + 3, pMsg: "WriteCustomData()\n");
  if ( this->m_pBuffer != nullptr && this->m_pBuffer->IsInitialized(this: this->m_pBuffer) )
  {
    CDemoFile::WriteCmdHeader(this, cmd: 8, tick, nPlayerSlot: 0);
    this->m_pBuffer->PutInt(this: this->m_pBuffer, a2: iCallbackIndex);
    this->m_pBuffer->PutInt(this: this->m_pBuffer, a2: iDataSize);
    this->m_pBuffer->Put(this: this->m_pBuffer, a2: pData, a3: iDataSize);
  }
  --CDbgPrint::s_nIndent;
}

//------------------------------------------------------------------------------
// Address: 0x100B86F0
// Name: public: void CDemoFile::WriteRawData(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteRawData(CDemoFile *this, const char *buffer, int length)
{
  int v4; // edi

  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&length + 3, pMsg: "WriteRawData()\n");
  v4 = length;
  this->m_pBuffer->PutInt(this: this->m_pBuffer, a2: length);
  this->m_pBuffer->Put(this: this->m_pBuffer, a2: buffer, a3: v4);
  --CDbgPrint::s_nIndent;
}

//------------------------------------------------------------------------------
// Address: 0x100B8740
// Name: public: void CDemoFile::WriteDemoHeader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteDemoHeader(CDemoFile *this)
{
  int HostVersion; // eax
  int networkprotocol; // [esp+4h] [ebp-14h]
  CDbgPrint printer; // [esp+17h] [ebp-1h] BYREF

  CDbgPrint::CDbgPrint(this: &printer, pMsg: "WriteDemoHeader()\n");
  DevMsg(a1: "\n");
  DevMsg(a1: "     demofilestamp: %s\n", this->m_DemoHeader.demofilestamp);
  DevMsg(a1: "     demoprotocol (should be %i): %i\n", 4, this->m_DemoHeader.demoprotocol);
  networkprotocol = this->m_DemoHeader.networkprotocol;
  HostVersion = GetHostVersion();
  DevMsg(a1: "     networkprotocol (should be %i): %i\n", HostVersion, networkprotocol);
  DevMsg(a1: "     servername: %s\n", this->m_DemoHeader.servername);
  DevMsg(a1: "     clientname: %s\n", this->m_DemoHeader.clientname);
  DevMsg(a1: "     mapname: %s\n", this->m_DemoHeader.mapname);
  DevMsg(a1: "     gamedirectory: %s\n", this->m_DemoHeader.gamedirectory);
  DevMsg(a1: "     playback_time: %f\n", this->m_DemoHeader.playback_time);
  DevMsg(a1: "     playback_ticks: %i\n", this->m_DemoHeader.playback_ticks);
  DevMsg(a1: "     playback_frames: %i\n", this->m_DemoHeader.playback_frames);
  DevMsg(a1: "     signonlength: %i\n", this->m_DemoHeader.signonlength);
  DevMsg(a1: "\n");
  this->m_pBuffer->WriteHeader(this: this->m_pBuffer, a2: &this->m_DemoHeader, a3: 1072);
  --CDbgPrint::s_nIndent;
}

//------------------------------------------------------------------------------
// Address: 0x100B8840
// Name: public: struct demoheader_t __near * CDemoFile::ReadDemoHeader(void)
// Source: json
//------------------------------------------------------------------------------
demoheader_t *__thiscall CDemoFile::ReadDemoHeader(CDemoFile *this)
{
  demoheader_t *p_m_DemoHeader; // edi
  int HostVersion; // eax
  int demoprotocol; // esi

  p_m_DemoHeader = &this->m_DemoHeader;
  _V_memset(dest: &this->m_DemoHeader, fill: 0, count: 1072);
  if ( this->m_pBuffer != nullptr && this->m_pBuffer->IsInitialized(this: this->m_pBuffer) )
  {
    this->m_pBuffer->SeekGet(this: this->m_pBuffer, a2: true, a3: 0);
    this->m_pBuffer->Get(this: this->m_pBuffer, a2: p_m_DemoHeader, a3: 1072);
    if ( this->m_pBuffer->IsValid(this: this->m_pBuffer) )
    {
      if ( _V_strcmp(s1: p_m_DemoHeader->demofilestamp, s2: "HL2DEMO") != 0 )
      {
        ConMsg(a1: "%s has invalid demo header ID.\n", this->m_szFileName);
        return nullptr;
      }
      if ( this->m_DemoHeader.networkprotocol != GetHostVersion() )
      {
        HostVersion = GetHostVersion();
        ConMsg(
          a1: "ERROR: demo network protocol %i outdated, engine version is %i \n",
          this->m_DemoHeader.networkprotocol,
          HostVersion);
        return nullptr;
      }
      demoprotocol = this->m_DemoHeader.demoprotocol;
      if ( demoprotocol <= 4 && demoprotocol >= 2 )
        return p_m_DemoHeader;
      ConMsg(a1: "ERROR: demo file protocol %i outdated, engine vnoteersion is %i \n", demoprotocol, 4);
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100B8930
// Name: public: void CDemoFile::WriteFileBytes(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteFileBytes(CDemoFile *this, void *fh, int length)
{
  int v4; // esi
  unsigned int v5; // esi
  char copybuf[1024]; // [esp+Ch] [ebp-400h] BYREF

  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&length + 3, pMsg: "WriteFileBytes()\n");
  v4 = length;
  if ( length > 1024 )
  {
    v5 = ((unsigned int)(length - 1025) >> 10) + 1;
    length -= v5 << 10;
    do
    {
      g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: copybuf, a3: 1024, a4: fh);
      this->m_pBuffer->Put(this: this->m_pBuffer, a2: copybuf, a3: 1024);
      --v5;
    }
    while ( v5 != 0 );
    v4 = length;
  }
  g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: copybuf, a3: v4, a4: fh);
  this->m_pBuffer->Put(this: this->m_pBuffer, a2: copybuf, a3: v4);
  g_pFileSystem->Flush(this: &g_pFileSystem->IBaseFileSystem, a2: fh);
  --CDbgPrint::s_nIndent;
}

//------------------------------------------------------------------------------
// Address: 0x100B8A00
// Name: public: bool CDemoFile::IsOpen(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDemoFile::IsOpen(CDemoFile *this)
{
  return this->m_pBuffer != nullptr && this->m_pBuffer->IsInitialized(this: this->m_pBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x100B8A30
// Name: public: void CDemoFile::Close(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::Close(CDemoFile *this)
{
  IDemoBuffer *m_pBuffer; // ecx

  m_pBuffer = this->m_pBuffer;
  if ( m_pBuffer != nullptr )
    ((void (__thiscall *)(IDemoBuffer *, int))m_pBuffer->dtr_IBaseInterface)(a1: m_pBuffer, a2: 1);
  this->m_pBuffer = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100B8A60
// Name: public: int CDemoFile::GetSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoFile::GetSize(CDemoFile *this)
{
  return this->m_pBuffer->TellMaxPut(this: this->m_pBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x100B8A70
// Name: public: CDemoFile::~CDemoFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::~CDemoFile(CDemoFile *this)
{
  IDemoBuffer *m_pBuffer; // ecx
  IDemoBuffer *v3; // ecx

  m_pBuffer = this->m_pBuffer;
  if ( m_pBuffer != nullptr && m_pBuffer->IsInitialized(this: m_pBuffer) )
  {
    v3 = this->m_pBuffer;
    if ( v3 != nullptr )
      ((void (__thiscall *)(IDemoBuffer *, int))v3->dtr_IBaseInterface)(a1: v3, a2: 1);
    this->m_pBuffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8AB0
// Name: public: void CDemoFile::WriteConsoleCommand(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteConsoleCommand(CDemoFile *this, const char *cmdstring, int tick, int nPlayerSlot)
{
  const char *v5; // ebx
  int v6; // esi

  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&cmdstring + 3, pMsg: "WriteConsoleCommand()\n");
  v5 = cmdstring;
  if ( cmdstring != nullptr
    && *cmdstring != 0
    && this->m_pBuffer != nullptr
    && this->m_pBuffer->IsInitialized(this: this->m_pBuffer) )
  {
    v6 = _V_strlen(str: v5) + 1;
    if ( v6 >= 1024 )
    {
      DevMsg(a1: "CDemoFile::WriteConsoleCommand: command too long (>1024).\n");
      --CDbgPrint::s_nIndent;
      return;
    }
    CDemoFile::WriteCmdHeader(this, cmd: 4, tick, nPlayerSlot);
    CDemoFile::WriteRawData(this, buffer: v5, length: v6);
  }
  --CDbgPrint::s_nIndent;
}

//------------------------------------------------------------------------------
// Address: 0x100B8B50
// Name: public: char const __near * CDemoFile::ReadConsoleCommand(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CDemoFile::ReadConsoleCommand(CDemoFile *this)
{
  CDemoFile::ReadRawData(this, buffer: cmdstring, length: 1024);
  return cmdstring;
}

//------------------------------------------------------------------------------
// Address: 0x100B8B70
// Name: public: void CDemoFile::WriteNetworkDataTables(class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteNetworkDataTables(CDemoFile *this, bf_write *buf, int tick)
{
  unsigned __int8 *m_pData; // ebx
  int v5; // esi

  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&tick + 3, pMsg: "WriteNetworkDataTables()\n");
  if ( this->m_pBuffer != nullptr && this->m_pBuffer->IsInitialized(this: this->m_pBuffer) )
  {
    CDemoFile::WriteCmdHeader(this, cmd: 6, tick, nPlayerSlot: 0);
    m_pData = buf->m_pData;
    v5 = (buf->m_iCurBit + 7) >> 3;
    CDbgPrint::CDbgPrint(this: (CDbgPrint *)&tick + 3, pMsg: "WriteRawData()\n");
    this->m_pBuffer->PutInt(this: this->m_pBuffer, a2: v5);
    this->m_pBuffer->Put(this: this->m_pBuffer, a2: m_pData, a3: v5);
    CDbgPrint::s_nIndent -= 2;
  }
  else
  {
    DevMsg(a1: "CDemoFile::WriteNetworkDataTables: Haven't opened file yet!\n");
    --CDbgPrint::s_nIndent;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8C10
// Name: public: void CDemoFile::WriteStringTables(class bf_write __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteStringTables(CDemoFile *this, bf_write *buf, int tick)
{
  unsigned __int8 *m_pData; // ebx
  int v5; // esi

  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&tick + 3, pMsg: "WriteStringTables()\n");
  if ( this->m_pBuffer != nullptr && this->m_pBuffer->IsInitialized(this: this->m_pBuffer) )
  {
    CDemoFile::WriteCmdHeader(this, cmd: 9, tick, nPlayerSlot: 0);
    m_pData = buf->m_pData;
    v5 = (buf->m_iCurBit + 7) >> 3;
    CDbgPrint::CDbgPrint(this: (CDbgPrint *)&tick + 3, pMsg: "WriteRawData()\n");
    this->m_pBuffer->PutInt(this: this->m_pBuffer, a2: v5);
    this->m_pBuffer->Put(this: this->m_pBuffer, a2: m_pData, a3: v5);
    CDbgPrint::s_nIndent -= 2;
  }
  else
  {
    DevMsg(a1: "CDemoFile::WriteStringTables: Haven't opened file yet!\n");
    --CDbgPrint::s_nIndent;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8CB0
// Name: public: int CDemoFile::ReadStringTables(class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoFile::ReadStringTables(CDemoFile *this, bf_read *buf)
{
  char *m_pData; // esi
  int m_nDataBits; // ecx
  int v6; // esi

  if ( buf != nullptr )
  {
    m_pData = (char *)buf->m_pData;
    if ( m_pData != nullptr )
    {
      m_nDataBits = 32 * (((char *)buf->m_pDataIn - m_pData) >> 2) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3);
      if ( m_nDataBits >= buf->m_nDataBits )
        m_nDataBits = buf->m_nDataBits;
    }
    else
    {
      m_nDataBits = 0;
    }
    return CDemoFile::ReadRawData(this, buffer: m_pData, length: (buf->m_nDataBits - m_nDataBits) >> 3);
  }
  else
  {
    v6 = this->m_pBuffer->GetInt(this: this->m_pBuffer);
    this->m_pBuffer->SeekGet(this: this->m_pBuffer, a2: false, a3: v6);
    return v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8D30
// Name: public: void CDemoFile::WriteUserCmd(int,char const __near *,unsigned char,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoFile::WriteUserCmd(
        CDemoFile *this,
        int cmdnumber,
        const char *buffer,
        int bytes,
        int tick,
        int nPlayerSlot)
{
  CDbgPrint::CDbgPrint(this: (CDbgPrint *)&bytes + 3, pMsg: "WriteUserCmd()\n");
  if ( this->m_pBuffer != nullptr && this->m_pBuffer->IsInitialized(this: this->m_pBuffer) )
  {
    CDemoFile::WriteCmdHeader(this, cmd: 5, tick, nPlayerSlot);
    this->m_pBuffer->PutInt(this: this->m_pBuffer, a2: cmdnumber);
    CDbgPrint::CDbgPrint(this: (CDbgPrint *)&bytes + 3, pMsg: "WriteRawData()\n");
    this->m_pBuffer->PutInt(this: this->m_pBuffer, a2: (unsigned __int8)bytes);
    this->m_pBuffer->Put(this: this->m_pBuffer, a2: buffer, a3: (unsigned __int8)bytes);
    CDbgPrint::s_nIndent -= 2;
  }
  else
  {
    --CDbgPrint::s_nIndent;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8DD0
// Name: public: int CDemoFile::ReadUserCmd(char __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoFile::ReadUserCmd(CDemoFile *this, char *buffer, int *size)
{
  int v4; // edi

  v4 = this->m_pBuffer->GetInt(this: this->m_pBuffer);
  *size = CDemoFile::ReadRawData(this, buffer, length: *size);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100B8E10
// Name: public: bool CDemoFile::Open(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDemoFile::Open(CDemoFile *this, const char *name, bool bReadOnly, bool bMemoryBuffer)
{
  IDemoBuffer *m_pBuffer; // ecx
  IDemoBuffer *v7; // eax
  const char *v8; // eax
  IDemoBuffer *v9; // ecx
  DemoBufferInitParams_t v10; // [esp+4h] [ebp-1Ch] BYREF
  const char *v11; // [esp+8h] [ebp-18h]
  int v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  MemoryDemoBufferInitParams_t params; // [esp+18h] [ebp-8h] BYREF

  m_pBuffer = this->m_pBuffer;
  if ( m_pBuffer != nullptr && m_pBuffer->IsInitialized(this: m_pBuffer) )
  {
    ConMsg(a1: "CDemoFile::Open: file already open.\n");
    return 0;
  }
  else
  {
    this->m_szFileName[0] = 0;
    _V_memset(dest: &this->m_DemoHeader, fill: 0, count: 1072);
    if ( bMemoryBuffer )
    {
      params.__vftable = (MemoryDemoBufferInitParams_t_vtbl *)&MemoryDemoBufferInitParams_t::`vftable';
      params.nMaxSize = 0x1000000;
      v7 = CreateDemoBuffer(bMemoryBuffer: true, &params);
    }
    else
    {
      v10.__vftable = (DemoBufferInitParams_t_vtbl *)&StreamDemoBufferInitParams_t::`vftable';
      v11 = name;
      v12 = 0;
      v13 = bReadOnly ? 8 : 0;
      v14 = 0;
      v7 = CreateDemoBuffer(bMemoryBuffer: false, params: &v10);
    }
    this->m_pBuffer = v7;
    if ( v7 != nullptr && v7->IsInitialized(this: v7) )
    {
      V_strncpy(pDest: this->m_szFileName, pSrc: name, maxLen: 260);
      return 1;
    }
    else
    {
      v8 = "reading";
      if ( !bReadOnly )
        v8 = "writing";
      ConMsg(a1: "CDemoFile::Open: couldn't open file %s for %s.\n", name, v8);
      v9 = this->m_pBuffer;
      if ( v9 != nullptr )
        ((void (__thiscall *)(IDemoBuffer *, int))v9->dtr_IBaseInterface)(a1: v9, a2: 1);
      this->m_pBuffer = nullptr;
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8F30
// Name: public: int CDemoFile::ReadCustomData(int __near *,unsigned char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDemoFile::ReadCustomData(CDemoFile *this, int *pCallbackIndex, unsigned __int8 **ppDataChunk)
{
  int v4; // ebx
  int v5; // eax
  int v6; // edi

  if ( (_S2_4 & 1) == 0 )
  {
    _S2_4 |= 1u;
    s_TempMemoryBuffer.m_Memory.m_pMemory = nullptr;
    s_TempMemoryBuffer.m_Memory.m_nAllocationCount = 0;
    s_TempMemoryBuffer.m_Memory.m_nGrowSize = 0;
    s_TempMemoryBuffer.m_Size = 0;
    s_TempMemoryBuffer.m_pElements = nullptr;
    atexit(func: CDemoFile::ReadCustomData_::_2_::_dynamic_atexit_destructor_for__s_TempMemoryBuffer__);
  }
  v4 = this->m_pBuffer->GetInt(this: this->m_pBuffer);
  v5 = this->m_pBuffer->GetInt(this: this->m_pBuffer);
  v6 = v5;
  if ( pCallbackIndex != nullptr && ppDataChunk != nullptr )
  {
    CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
      this: (CUtlVector<char,CUtlMemory<char,int> > *)&s_TempMemoryBuffer,
      count: v5);
    *ppDataChunk = s_TempMemoryBuffer.m_Memory.m_pMemory;
    *pCallbackIndex = v4;
    this->m_pBuffer->Get(this: this->m_pBuffer, a2: s_TempMemoryBuffer.m_Memory.m_pMemory, a3: v6);
    if ( this->m_pBuffer != nullptr && this->m_pBuffer->IsValid(this: this->m_pBuffer) )
    {
      return v6;
    }
    else
    {
      Host_EndGame(bShowMainMenu: true, message: "Error reading demo message data.\n");
      return -1;
    }
  }
  else
  {
    this->m_pBuffer->SeekGet(this: this->m_pBuffer, a2: false, a3: v5);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10322F00
// Name: _CDemoFile::ReadCustomData_::_2_::_dynamic_atexit_destructor_for__s_TempMemoryBuffer__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDemoFile::ReadCustomData_::_2_::_dynamic_atexit_destructor_for__s_TempMemoryBuffer__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_TempMemoryBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x10322F10
// Name: _dynamic_atexit_destructor_for__devshots_nextmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__devshots_nextmap__()
{
  ConCommand::~ConCommand(this: &devshots_nextmap);
}

//------------------------------------------------------------------------------
// Address: 0x10322F20
// Name: _dynamic_atexit_destructor_for__g_DevShotGenerator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DevShotGenerator__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_DevShotGenerator.m_Maps);
}

} // namespace engine_xlsp
