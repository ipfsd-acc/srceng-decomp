// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier2/tier2_logging.cpp
// Functions: 9
// ============================================================

#include "tier2\tier2_logging.h"

//------------------------------------------------------------------------------
// Address: 0x1027F840
// Name: public: CFileLoggingListener::~CFileLoggingListener(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoggingListener::~CFileLoggingListener(CFileLoggingListener *this)
{
  CFileLoggingListener::FileInfo_t *m_OpenFiles; // esi
  int i; // edi

  this->__vftable = (CFileLoggingListener_vtbl *)&CFileLoggingListener::`vftable';
  m_OpenFiles = this->m_OpenFiles;
  for ( i = 16; i != 0; --i )
  {
    if ( m_OpenFiles->m_FileHandle != nullptr )
    {
      g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: m_OpenFiles->m_FileHandle);
      m_OpenFiles->m_FileHandle = nullptr;
    }
    ++m_OpenFiles;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F880
// Name: public: virtual void CFileLoggingListener::EndLoggingToFile(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoggingListener::EndLoggingToFile(CFileLoggingListener *this, int fileHandle)
{
  int v2; // eax
  int v4; // esi
  int *m_FileIndices; // ebx

  v2 = fileHandle;
  if ( fileHandle != -1 )
  {
    v4 = 0;
    m_FileIndices = this->m_FileIndices;
    do
    {
      if ( *m_FileIndices == v2 )
      {
        this->UnassignLogChannel(this, a2: v4);
        v2 = fileHandle;
      }
      ++v4;
      ++m_FileIndices;
    }
    while ( v4 < 256 );
  }
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: this->m_OpenFiles[v2].m_FileHandle);
  this->m_OpenFiles[fileHandle].m_FileHandle = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1027F8E0
// Name: public: virtual void CFileLoggingListener::AssignLogChannel(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoggingListener::AssignLogChannel(
        CFileLoggingListener *this,
        int channelID,
        int loggingFileHandle)
{
  this->m_FileIndices[channelID] = loggingFileHandle;
}

//------------------------------------------------------------------------------
// Address: 0x1027F900
// Name: public: virtual void CFileLoggingListener::UnassignLogChannel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoggingListener::UnassignLogChannel(CFileLoggingListener *this, int channelID)
{
  this->m_FileIndices[channelID] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1027F920
// Name: public: virtual void CFileLoggingListener::AssignAllLogChannels(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoggingListener::AssignAllLogChannels(CFileLoggingListener *this, int loggingFileHandle)
{
  memset32(this->m_FileIndices, loggingFileHandle, 0x100u);
}

//------------------------------------------------------------------------------
// Address: 0x1027F940
// Name: public: virtual void CFileLoggingListener::UnassignAllLogChannels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoggingListener::UnassignAllLogChannels(CFileLoggingListener *this)
{
  memset(this->m_FileIndices, 0xFFu, sizeof(this->m_FileIndices));
}

//------------------------------------------------------------------------------
// Address: 0x1027F950
// Name: public: virtual void CFileLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoggingListener::Log(
        CFileLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  unsigned int v4; // esi
  IBaseFileSystem_vtbl *v5; // ebx
  int v6; // eax
  void *m_FileHandle; // [esp-Ch] [ebp-10h]

  if ( (pContext->m_Flags & 1) == 0 )
  {
    v4 = this->m_FileIndices[pContext->m_ChannelID];
    if ( v4 <= 0xF )
    {
      v5 = g_pFullFileSystem->IBaseFileSystem::__vftable;
      m_FileHandle = this->m_OpenFiles[v4].m_FileHandle;
      v6 = _V_strlen(str: pMessage);
      v5->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: pMessage, a3: v6, a4: m_FileHandle);
      g_pFullFileSystem->Flush(this: &g_pFullFileSystem->IBaseFileSystem, a2: this->m_OpenFiles[v4].m_FileHandle);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F9C0
// Name: public: CFileLoggingListener::CFileLoggingListener(void)
// Source: json
//------------------------------------------------------------------------------
CFileLoggingListener *__thiscall CFileLoggingListener::CFileLoggingListener(CFileLoggingListener *this)
{
  this->__vftable = (CFileLoggingListener_vtbl *)&CFileLoggingListener::`vftable';
  *(_QWORD *)&this->m_OpenFiles[0].m_FileHandle = 0;
  *(_QWORD *)&this->m_OpenFiles[2].m_FileHandle = 0;
  *(_QWORD *)&this->m_OpenFiles[4].m_FileHandle = 0;
  *(_QWORD *)&this->m_OpenFiles[6].m_FileHandle = 0;
  *(_QWORD *)&this->m_OpenFiles[8].m_FileHandle = 0;
  *(_QWORD *)&this->m_OpenFiles[10].m_FileHandle = 0;
  *(_QWORD *)&this->m_OpenFiles[12].m_FileHandle = 0;
  *(_QWORD *)&this->m_OpenFiles[14].m_FileHandle = 0;
  memset(this->m_FileIndices, 0xFFu, sizeof(this->m_FileIndices));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1027FA10
// Name: public: virtual int CFileLoggingListener::BeginLoggingToFile(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileLoggingListener::BeginLoggingToFile(
        CFileLoggingListener *this,
        const char *pFilename,
        const char *pOptions,
        const char *pPathID)
{
  int v4; // esi
  CFileLoggingListener::FileInfo_t *i; // eax

  v4 = 0;
  for ( i = this->m_OpenFiles; i->m_FileHandle != nullptr; ++i )
  {
    if ( ++v4 >= 16 )
      return -1;
  }
  if ( v4 != -1 )
    this->m_OpenFiles[v4].m_FileHandle = g_pFullFileSystem->Open(
                                           this: &g_pFullFileSystem->IBaseFileSystem,
                                           a2: pFilename,
                                           a3: pOptions,
                                           a4: pPathID);
  return v4;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1027F980
// Name: public: CFileLoggingListener::~CFileLoggingListener(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoggingListener::~CFileLoggingListener(CFileLoggingListener *this)
{
  CFileLoggingListener::FileInfo_t *m_OpenFiles; // esi
  int i; // edi

  this->__vftable = (CFileLoggingListener_vtbl *)&CFileLoggingListener::`vftable';
  m_OpenFiles = this->m_OpenFiles;
  for ( i = 16; i != 0; --i )
  {
    if ( m_OpenFiles->m_FileHandle != nullptr )
    {
      g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: m_OpenFiles->m_FileHandle);
      m_OpenFiles->m_FileHandle = nullptr;
    }
    ++m_OpenFiles;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027FA20
// Name: public: virtual void CFileLoggingListener::AssignLogChannel(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoggingListener::AssignLogChannel(
        CFileLoggingListener *this,
        int channelID,
        int loggingFileHandle)
{
  this->m_FileIndices[channelID] = loggingFileHandle;
}

//------------------------------------------------------------------------------
// Address: 0x1027FA40
// Name: public: virtual void CFileLoggingListener::UnassignLogChannel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoggingListener::UnassignLogChannel(CFileLoggingListener *this, int channelID)
{
  this->m_FileIndices[channelID] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1027FA60
// Name: public: virtual void CFileLoggingListener::AssignAllLogChannels(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoggingListener::AssignAllLogChannels(CFileLoggingListener *this, int loggingFileHandle)
{
  memset32(this->m_FileIndices, loggingFileHandle, 0x100u);
}

//------------------------------------------------------------------------------
// Address: 0x1027FA80
// Name: public: virtual void CFileLoggingListener::UnassignAllLogChannels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoggingListener::UnassignAllLogChannels(CFileLoggingListener *this)
{
  memset(this->m_FileIndices, 0xFFu, sizeof(this->m_FileIndices));
}

//------------------------------------------------------------------------------
// Address: 0x1027FA90
// Name: public: virtual void CFileLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileLoggingListener::Log(
        CFileLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  unsigned int v4; // esi
  IBaseFileSystem_vtbl *v5; // ebx
  int v6; // eax
  void *m_FileHandle; // [esp-Ch] [ebp-10h]

  if ( (pContext->m_Flags & 1) == 0 )
  {
    v4 = this->m_FileIndices[pContext->m_ChannelID];
    if ( v4 <= 0xF )
    {
      v5 = g_pFullFileSystem->IBaseFileSystem::__vftable;
      m_FileHandle = this->m_OpenFiles[v4].m_FileHandle;
      v6 = _V_strlen(str: pMessage);
      v5->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: pMessage, a3: v6, a4: m_FileHandle);
      g_pFullFileSystem->Flush(this: &g_pFullFileSystem->IBaseFileSystem, a2: this->m_OpenFiles[v4].m_FileHandle);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027FB00
// Name: public: CFileLoggingListener::CFileLoggingListener(void)
// Source: json
//------------------------------------------------------------------------------
CFileLoggingListener *__thiscall CFileLoggingListener::CFileLoggingListener(CFileLoggingListener *this)
{
  this->__vftable = (CFileLoggingListener_vtbl *)&CFileLoggingListener::`vftable';
  *(_QWORD *)&this->m_OpenFiles[0].m_FileHandle = 0;
  *(_QWORD *)&this->m_OpenFiles[2].m_FileHandle = 0;
  *(_QWORD *)&this->m_OpenFiles[4].m_FileHandle = 0;
  *(_QWORD *)&this->m_OpenFiles[6].m_FileHandle = 0;
  *(_QWORD *)&this->m_OpenFiles[8].m_FileHandle = 0;
  *(_QWORD *)&this->m_OpenFiles[10].m_FileHandle = 0;
  *(_QWORD *)&this->m_OpenFiles[12].m_FileHandle = 0;
  *(_QWORD *)&this->m_OpenFiles[14].m_FileHandle = 0;
  memset(this->m_FileIndices, 0xFFu, sizeof(this->m_FileIndices));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1027FB50
// Name: public: virtual int CFileLoggingListener::BeginLoggingToFile(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileLoggingListener::BeginLoggingToFile(
        CFileLoggingListener *this,
        const char *pFilename,
        const char *pOptions,
        const char *pPathID)
{
  int v4; // esi
  CFileLoggingListener::FileInfo_t *i; // eax

  v4 = 0;
  for ( i = this->m_OpenFiles; i->m_FileHandle != nullptr; ++i )
  {
    if ( ++v4 >= 16 )
      return -1;
  }
  if ( v4 != -1 )
    this->m_OpenFiles[v4].m_FileHandle = g_pFullFileSystem->Open(
                                           this: &g_pFullFileSystem->IBaseFileSystem,
                                           a2: pFilename,
                                           a3: pOptions,
                                           a4: pPathID);
  return v4;
}

} // namespace engine_xlsp
