// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/demobuffer.cpp
// Functions: 18
// ============================================================

#include "engine\demobuffer.h"

//------------------------------------------------------------------------------
// Address: 0x100B8190
// Name: public: virtual bool CDiskDemoBuffer::Init(struct DemoBufferInitParams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDiskDemoBuffer::Init(CDiskDemoBuffer *this, const DemoBufferInitParams_t *params)
{
  void *v3; // edi
  CUtlStreamBuffer *v4; // eax
  CUtlStreamBuffer *v5; // eax

  v3 = __RTDynamicCast(
         inptr: (void *)params,
         VfDelta: 0,
         SrcType: (void *)&DemoBufferInitParams_t `RTTI Type Descriptor',
         TargetType: &StreamDemoBufferInitParams_t `RTTI Type Descriptor',
         isReference: 0);
  v4 = (CUtlStreamBuffer *)MemAlloc_Alloc(nSize: 0x40u);
  if ( v4 != nullptr )
    v5 = CUtlStreamBuffer::CUtlStreamBuffer(this: v4);
  else
    v5 = nullptr;
  this->m_pBuffer = v5;
  if ( v5 == nullptr )
    return false;
  CUtlBuffer::SetBigEndian(this: v5, bigEndian: false);
  CUtlStreamBuffer::Open(
    this: this->m_pBuffer,
    pFileName: *((const char **)v3 + 1),
    pPath: *((const char **)v3 + 2),
    nFlags: *((_DWORD *)v3 + 3),
    nOpenFileFlags: 0);
  return this->IsInitialized(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B8210
// Name: public: virtual void CDiskDemoBuffer::WriteHeader(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiskDemoBuffer::WriteHeader(CDiskDemoBuffer *this, const void *pData, int nSize)
{
  this->SeekPut(this, a2: true, a3: 0);
  this->Put(this, a2: pData, a3: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x100B8240
// Name: public: virtual void CDiskDemoBuffer::Get(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiskDemoBuffer::Get(CDiskDemoBuffer *this, void *pMem, int size)
{
  CUtlBuffer::Get(this: this->m_pBuffer, pMem, size);
}

//------------------------------------------------------------------------------
// Address: 0x100B8250
// Name: public: virtual void CDiskDemoBuffer::Put(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiskDemoBuffer::Put(CDiskDemoBuffer *this, const void *pMem, int size)
{
  CUtlBuffer::Put(this: this->m_pBuffer, pMem, size);
}

//------------------------------------------------------------------------------
// Address: 0x100B8260
// Name: public: virtual bool CDiskDemoBuffer::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDiskDemoBuffer::IsValid(CDiskDemoBuffer *this)
{
  CUtlStreamBuffer *m_pBuffer; // eax

  m_pBuffer = this->m_pBuffer;
  return m_pBuffer != nullptr && m_pBuffer->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B8280
// Name: public: virtual bool CDiskDemoBuffer::IsInitialized(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDiskDemoBuffer::IsInitialized(CDiskDemoBuffer *this)
{
  return this->IsValid(this) && CUtlStreamBuffer::IsOpen(this: this->m_pBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x100B82B0
// Name: public: virtual void CDiskDemoBuffer::SeekPut(bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiskDemoBuffer::SeekPut(CDiskDemoBuffer *this, bool bAbsolute, int offset)
{
  CUtlBuffer::SeekPut(this: this->m_pBuffer, type: (CUtlBuffer::SeekType_t)!bAbsolute, offset);
}

//------------------------------------------------------------------------------
// Address: 0x100B82D0
// Name: public: virtual void CDiskDemoBuffer::SeekGet(bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiskDemoBuffer::SeekGet(CDiskDemoBuffer *this, bool bAbsolute, int offset)
{
  CUtlBuffer::SeekGet(this: this->m_pBuffer, type: (CUtlBuffer::SeekType_t)!bAbsolute, offset);
}

//------------------------------------------------------------------------------
// Address: 0x100B82F0
// Name: public: virtual int CDiskDemoBuffer::TellPut(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDiskDemoBuffer::TellPut(CDiskDemoBuffer *this)
{
  return this->m_pBuffer->m_Put;
}

//------------------------------------------------------------------------------
// Address: 0x100B8300
// Name: public: virtual int CDiskDemoBuffer::TellMaxPut(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDiskDemoBuffer::TellMaxPut(CDiskDemoBuffer *this)
{
  return this->m_pBuffer->m_nMaxPut;
}

//------------------------------------------------------------------------------
// Address: 0x100B8360
// Name: class IDemoBuffer __near * CreateDemoBuffer(bool,struct DemoBufferInitParams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
IDemoBuffer *__cdecl CreateDemoBuffer(bool bMemoryBuffer, const DemoBufferInitParams_t *params)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi

  v2 = MemAlloc_Alloc(nSize: 8u);
  v3 = nullptr;
  if ( v2 != nullptr )
  {
    v2[1] = 0;
    *v2 = &CDiskDemoBuffer::`vftable';
    v3 = v2;
  }
  if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, const DemoBufferInitParams_t *))(*v3 + 4))(a1: v3, a2: params) != 0 )
    return (IDemoBuffer *)v3;
  (*(void (__thiscall **)(_DWORD *, int))*v3)(a1: v3, a2: 1);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100B83B0
// Name: public: virtual void CDiskDemoBuffer::PutChar(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiskDemoBuffer::PutChar(CDiskDemoBuffer *this, char c)
{
  CUtlStreamBuffer *m_pBuffer; // esi
  int m_Put; // eax

  m_pBuffer = this->m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
  {
    m_Put = m_pBuffer->m_Put;
    if ( m_Put != 0 && m_pBuffer->m_Memory.m_pMemory[m_Put - m_pBuffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: m_pBuffer);
  }
  if ( CUtlBuffer::CheckPut(this: m_pBuffer, nSize: 1) )
  {
    m_pBuffer->m_Memory.m_pMemory[m_pBuffer->m_Put++ - m_pBuffer->m_nOffset] = c;
    CUtlBuffer::AddNullTermination(this: m_pBuffer, nPut: m_pBuffer->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8410
// Name: public: virtual char CDiskDemoBuffer::GetChar(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CDiskDemoBuffer::GetChar(CDiskDemoBuffer *this)
{
  CUtlStreamBuffer *m_pBuffer; // esi

  m_pBuffer = this->m_pBuffer;
  if ( !CUtlBuffer::CheckGet(this: m_pBuffer, nSize: 1) )
    return 0;
  return m_pBuffer->m_Memory.m_pMemory[m_pBuffer->m_Get++ - m_pBuffer->m_nOffset];
}

//------------------------------------------------------------------------------
// Address: 0x100B8440
// Name: public: virtual void CDiskDemoBuffer::WriteTick(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiskDemoBuffer::WriteTick(CDiskDemoBuffer *this, int nTick)
{
  CUtlStreamBuffer *m_pBuffer; // ecx

  m_pBuffer = this->m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: m_pBuffer, pFmt: "%d", nTick);
  else
    CUtlBuffer::PutTypeBin<int>(this: m_pBuffer, src: nTick);
}

//------------------------------------------------------------------------------
// Address: 0x100B8470
// Name: public: virtual int CDiskDemoBuffer::GetInt(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDiskDemoBuffer::GetInt(CDiskDemoBuffer *this)
{
  return CUtlBuffer::GetInt(this: this->m_pBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x100B8480
// Name: public: void CUtlBuffer::PutUnsignedChar(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutUnsignedChar(CUtlBuffer *this, unsigned __int8 c)
{
  if ( (this->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this, pFmt: "%hu", c);
  }
  else if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = c;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B84D0
// Name: public: virtual void CDiskDemoBuffer::PutUnsignedChar(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiskDemoBuffer::PutUnsignedChar(CDiskDemoBuffer *this, unsigned __int8 uc)
{
  CUtlStreamBuffer *m_pBuffer; // esi

  m_pBuffer = this->m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: m_pBuffer, pFmt: "%hu", uc);
  }
  else if ( CUtlBuffer::CheckPut(this: m_pBuffer, nSize: 1) )
  {
    m_pBuffer->m_Memory.m_pMemory[m_pBuffer->m_Put - m_pBuffer->m_nOffset] = uc;
    CUtlBuffer::AddNullTermination(this: m_pBuffer, nPut: ++m_pBuffer->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8530
// Name: public: virtual unsigned char CDiskDemoBuffer::GetUnsignedChar(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CDiskDemoBuffer::GetUnsignedChar(CDiskDemoBuffer *this)
{
  CUtlStreamBuffer *v1; // esi
  CUtlStreamBuffer *m_pBuffer; // ecx

  m_pBuffer = this->m_pBuffer;
  v1 = m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
    return CUtlBuffer::GetUnsignedShort(this: m_pBuffer);
  if ( !CUtlBuffer::CheckGet(this: m_pBuffer, nSize: 1) )
    return 0;
  return v1->m_Memory.m_pMemory[v1->m_Get++ - v1->m_nOffset];
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100B7E30
// Name: public: virtual bool CDiskDemoBuffer::Init(struct DemoBufferInitParams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDiskDemoBuffer::Init(CDiskDemoBuffer *this, const DemoBufferInitParams_t *params)
{
  void *v3; // edi
  CUtlStreamBuffer *v4; // eax
  CUtlStreamBuffer *v5; // eax

  v3 = __RTDynamicCast(
         inptr: (void *)params,
         VfDelta: 0,
         SrcType: (void *)&DemoBufferInitParams_t `RTTI Type Descriptor',
         TargetType: &StreamDemoBufferInitParams_t `RTTI Type Descriptor',
         isReference: 0);
  v4 = (CUtlStreamBuffer *)MemAlloc_Alloc(nSize: 0x40u);
  if ( v4 != nullptr )
    v5 = CUtlStreamBuffer::CUtlStreamBuffer(this: v4);
  else
    v5 = nullptr;
  this->m_pBuffer = v5;
  if ( v5 == nullptr )
    return false;
  CUtlBuffer::SetBigEndian(this: v5, bigEndian: false);
  CUtlStreamBuffer::Open(
    this: this->m_pBuffer,
    pFileName: *((const char **)v3 + 1),
    pPath: *((const char **)v3 + 2),
    nFlags: *((_DWORD *)v3 + 3),
    nOpenFileFlags: 0);
  return this->IsInitialized(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B7EB0
// Name: public: virtual void CDiskDemoBuffer::WriteHeader(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiskDemoBuffer::WriteHeader(CDiskDemoBuffer *this, const void *pData, int nSize)
{
  this->SeekPut(this, a2: true, a3: 0);
  this->Put(this, a2: pData, a3: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x100B7EE0
// Name: public: virtual void CDiskDemoBuffer::Get(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiskDemoBuffer::Get(CDiskDemoBuffer *this, void *pMem, int size)
{
  CUtlBuffer::Get(this: this->m_pBuffer, pMem, size);
}

//------------------------------------------------------------------------------
// Address: 0x100B7EF0
// Name: public: virtual void CDiskDemoBuffer::Put(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiskDemoBuffer::Put(CDiskDemoBuffer *this, const void *pMem, int size)
{
  CUtlBuffer::Put(this: this->m_pBuffer, pMem, size);
}

//------------------------------------------------------------------------------
// Address: 0x100B7F00
// Name: public: virtual bool CDiskDemoBuffer::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDiskDemoBuffer::IsValid(CDiskDemoBuffer *this)
{
  CUtlStreamBuffer *m_pBuffer; // eax

  m_pBuffer = this->m_pBuffer;
  return m_pBuffer != nullptr && m_pBuffer->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B7F20
// Name: public: virtual bool CDiskDemoBuffer::IsInitialized(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDiskDemoBuffer::IsInitialized(CDiskDemoBuffer *this)
{
  return this->IsValid(this) && CUtlStreamBuffer::IsOpen(this: this->m_pBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x100B7F50
// Name: public: virtual void CDiskDemoBuffer::SeekPut(bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiskDemoBuffer::SeekPut(CDiskDemoBuffer *this, bool bAbsolute, int offset)
{
  CUtlBuffer::SeekPut(this: this->m_pBuffer, type: (CUtlBuffer::SeekType_t)!bAbsolute, offset);
}

//------------------------------------------------------------------------------
// Address: 0x100B7F70
// Name: public: virtual void CDiskDemoBuffer::SeekGet(bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiskDemoBuffer::SeekGet(CDiskDemoBuffer *this, bool bAbsolute, int offset)
{
  CUtlBuffer::SeekGet(this: this->m_pBuffer, type: (CUtlBuffer::SeekType_t)!bAbsolute, offset);
}

//------------------------------------------------------------------------------
// Address: 0x100B7F90
// Name: public: virtual int CDiskDemoBuffer::TellPut(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDiskDemoBuffer::TellPut(CDiskDemoBuffer *this)
{
  return this->m_pBuffer->m_Put;
}

//------------------------------------------------------------------------------
// Address: 0x100B7FB0
// Name: public: virtual int CDiskDemoBuffer::TellMaxPut(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDiskDemoBuffer::TellMaxPut(CDiskDemoBuffer *this)
{
  return this->m_pBuffer->m_nMaxPut;
}

//------------------------------------------------------------------------------
// Address: 0x100B8010
// Name: class IDemoBuffer __near * CreateDemoBuffer(bool,struct DemoBufferInitParams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
IDemoBuffer *__cdecl CreateDemoBuffer(bool bMemoryBuffer, const DemoBufferInitParams_t *params)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi

  v2 = MemAlloc_Alloc(nSize: 8u);
  v3 = nullptr;
  if ( v2 != nullptr )
  {
    v2[1] = 0;
    *v2 = &CDiskDemoBuffer::`vftable';
    v3 = v2;
  }
  if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, const DemoBufferInitParams_t *))(*v3 + 4))(a1: v3, a2: params) != 0 )
    return (IDemoBuffer *)v3;
  (*(void (__thiscall **)(_DWORD *, int))*v3)(a1: v3, a2: 1);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100B8060
// Name: public: virtual void CDiskDemoBuffer::PutChar(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiskDemoBuffer::PutChar(CDiskDemoBuffer *this, char c)
{
  CUtlStreamBuffer *m_pBuffer; // esi
  int m_Put; // eax

  m_pBuffer = this->m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
  {
    m_Put = m_pBuffer->m_Put;
    if ( m_Put != 0 && m_pBuffer->m_Memory.m_pMemory[m_Put - m_pBuffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: m_pBuffer);
  }
  if ( CUtlBuffer::CheckPut(this: m_pBuffer, nSize: 1) )
  {
    m_pBuffer->m_Memory.m_pMemory[m_pBuffer->m_Put++ - m_pBuffer->m_nOffset] = c;
    CUtlBuffer::AddNullTermination(this: m_pBuffer, nPut: m_pBuffer->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B80C0
// Name: public: virtual char CDiskDemoBuffer::GetChar(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CDiskDemoBuffer::GetChar(CDiskDemoBuffer *this)
{
  CUtlStreamBuffer *m_pBuffer; // esi

  m_pBuffer = this->m_pBuffer;
  if ( !CUtlBuffer::CheckGet(this: m_pBuffer, nSize: 1) )
    return 0;
  return m_pBuffer->m_Memory.m_pMemory[m_pBuffer->m_Get++ - m_pBuffer->m_nOffset];
}

//------------------------------------------------------------------------------
// Address: 0x100B80F0
// Name: public: virtual void CDiskDemoBuffer::WriteTick(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiskDemoBuffer::WriteTick(CDiskDemoBuffer *this, int nTick)
{
  CUtlStreamBuffer *m_pBuffer; // ecx

  m_pBuffer = this->m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: m_pBuffer, pFmt: "%d", nTick);
  else
    CUtlBuffer::PutTypeBin<int>(this: m_pBuffer, src: nTick);
}

//------------------------------------------------------------------------------
// Address: 0x100B8120
// Name: public: virtual int CDiskDemoBuffer::GetInt(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDiskDemoBuffer::GetInt(CDiskDemoBuffer *this)
{
  return CUtlBuffer::GetInt(this: this->m_pBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x100B8130
// Name: public: void CUtlBuffer::PutUnsignedChar(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutUnsignedChar(CUtlBuffer *this, unsigned __int8 c)
{
  if ( (this->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this, pFmt: "%hu", c);
  }
  else if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = c;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8180
// Name: public: virtual void CDiskDemoBuffer::PutUnsignedChar(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiskDemoBuffer::PutUnsignedChar(CDiskDemoBuffer *this, unsigned __int8 uc)
{
  CUtlStreamBuffer *m_pBuffer; // esi

  m_pBuffer = this->m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: m_pBuffer, pFmt: "%hu", uc);
  }
  else if ( CUtlBuffer::CheckPut(this: m_pBuffer, nSize: 1) )
  {
    m_pBuffer->m_Memory.m_pMemory[m_pBuffer->m_Put - m_pBuffer->m_nOffset] = uc;
    CUtlBuffer::AddNullTermination(this: m_pBuffer, nPut: ++m_pBuffer->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B81E0
// Name: public: virtual unsigned char CDiskDemoBuffer::GetUnsignedChar(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CDiskDemoBuffer::GetUnsignedChar(CDiskDemoBuffer *this)
{
  CUtlStreamBuffer *v1; // esi
  CUtlStreamBuffer *m_pBuffer; // ecx

  m_pBuffer = this->m_pBuffer;
  v1 = m_pBuffer;
  if ( (m_pBuffer->m_Flags & 1) != 0 )
    return CUtlBuffer::GetUnsignedShort(this: m_pBuffer);
  if ( !CUtlBuffer::CheckGet(this: m_pBuffer, nSize: 1) )
    return 0;
  return v1->m_Memory.m_pMemory[v1->m_Get++ - v1->m_nOffset];
}

//------------------------------------------------------------------------------
// Address: 0x10312C30
// Name: _dynamic_initializer_for__demo_recordcommands__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_recordcommands__()
{
  ConVar::ConVar(
    this: &demo_recordcommands,
    pName: "demo_recordcommands",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Record commands typed at console into .dem files.");
  return atexit(func: dynamic_atexit_destructor_for__demo_recordcommands__);
}

//------------------------------------------------------------------------------
// Address: 0x10312C60
// Name: _dynamic_initializer_for__demo_quitafterplayback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_quitafterplayback__()
{
  ConVar::ConVar(
    this: &demo_quitafterplayback,
    pName: "demo_quitafterplayback",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Quits game after demo playback.");
  return atexit(func: dynamic_atexit_destructor_for__demo_quitafterplayback__);
}

//------------------------------------------------------------------------------
// Address: 0x10312C90
// Name: _dynamic_initializer_for__demo_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_debug__()
{
  ConVar::ConVar(this: &demo_debug, pName: "demo_debug", pDefaultValue: "0", flags: 0, pHelpString: "Demo debug info.");
  return atexit(func: dynamic_atexit_destructor_for__demo_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x10312CC0
// Name: _dynamic_initializer_for__demo_interpolateview__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_interpolateview__()
{
  ConVar::ConVar(
    this: &demo_interpolateview,
    pName: "demo_interpolateview",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Do view interpolation during dem playback.");
  return atexit(func: dynamic_atexit_destructor_for__demo_interpolateview__);
}

//------------------------------------------------------------------------------
// Address: 0x10312CF0
// Name: _dynamic_initializer_for__demo_pauseatservertick__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_pauseatservertick__()
{
  ConVar::ConVar(
    this: &demo_pauseatservertick,
    pName: "demo_pauseatservertick",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Pauses demo playback at server tick");
  return atexit(func: dynamic_atexit_destructor_for__demo_pauseatservertick__);
}

//------------------------------------------------------------------------------
// Address: 0x10312D20
// Name: _dynamic_initializer_for__demo_enabledemos__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_enabledemos__()
{
  ConVar::ConVar(
    this: &demo_enabledemos,
    pName: "demo_enabledemos",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable recording demos (must be set true before loading a map)");
  return atexit(func: dynamic_atexit_destructor_for__demo_enabledemos__);
}

//------------------------------------------------------------------------------
// Address: 0x10312DC0
// Name: _dynamic_initializer_for__demo_interplimit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_interplimit__()
{
  ConVar::ConVar(
    this: &demo_interplimit,
    pName: "demo_interplimit",
    pDefaultValue: "4000",
    flags: 0,
    pHelpString: "How much origin velocity before it's considered to have 'teleported' causing interpolation to reset.");
  return atexit(func: dynamic_atexit_destructor_for__demo_interplimit__);
}

//------------------------------------------------------------------------------
// Address: 0x10312DF0
// Name: _dynamic_initializer_for__demo_avellimit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_avellimit__()
{
  ConVar::ConVar(
    this: &demo_avellimit,
    pName: "demo_avellimit",
    pDefaultValue: "2000",
    flags: 0,
    pHelpString: "Angular velocity limit before eyes considered snapped for demo playback.");
  return atexit(func: dynamic_atexit_destructor_for__demo_avellimit__);
}

//------------------------------------------------------------------------------
// Address: 0x10312E20
// Name: _dynamic_initializer_for__demo_fastforwardstartspeed__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_fastforwardstartspeed__()
{
  ConVar::ConVar(
    this: &demo_fastforwardstartspeed,
    pName: "demo_fastforwardstartspeed",
    pDefaultValue: "2",
    flags: 0,
    pHelpString: "Go this fast when starting to hold FF button.");
  return atexit(func: dynamic_atexit_destructor_for__demo_fastforwardstartspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x10312E50
// Name: _dynamic_initializer_for__demo_fastforwardfinalspeed__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_fastforwardfinalspeed__()
{
  ConVar::ConVar(
    this: &demo_fastforwardfinalspeed,
    pName: "demo_fastforwardfinalspeed",
    pDefaultValue: "20",
    flags: 0,
    pHelpString: "Go this fast when starting to hold FF button.");
  return atexit(func: dynamic_atexit_destructor_for__demo_fastforwardfinalspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x10312E80
// Name: _dynamic_initializer_for__demo_fastforwardramptime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_fastforwardramptime__()
{
  ConVar::ConVar(
    this: &demo_fastforwardramptime,
    pName: "demo_fastforwardramptime",
    pDefaultValue: "5",
    flags: 0,
    pHelpString: "How many seconds it takes to get to full FF speed.");
  return atexit(func: dynamic_atexit_destructor_for__demo_fastforwardramptime__);
}

//------------------------------------------------------------------------------
// Address: 0x10312EF0
// Name: _dynamic_initializer_for__demo_legacy_rollback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_legacy_rollback__()
{
  ConVar::ConVar(
    this: &demo_legacy_rollback,
    pName: "demo_legacy_rollback",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Use legacy view interpolation rollback amount in demo playback.");
  return atexit(func: dynamic_atexit_destructor_for__demo_legacy_rollback__);
}

//------------------------------------------------------------------------------
// Address: 0x10313100
// Name: _dynamic_initializer_for__demo_pause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_pause_command__()
{
  ConCommand::ConCommand(
    this: &demo_pause_command,
    pName: "demo_pause",
    callback: demo_pause,
    pHelpString: "Pauses demo playback.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demo_pause_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313130
// Name: _dynamic_initializer_for__demo_resume_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_resume_command__()
{
  ConCommand::ConCommand(
    this: &demo_resume_command,
    pName: "demo_resume",
    callback: (void (__cdecl *)(const CCommand *))demo_resume,
    pHelpString: "Resumes demo playback.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demo_resume_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313160
// Name: _dynamic_initializer_for__demo_togglepause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_togglepause_command__()
{
  ConCommand::ConCommand(
    this: &demo_togglepause_command,
    pName: "demo_togglepause",
    callback: (void (__cdecl *)(const CCommand *))demo_togglepause,
    pHelpString: "Toggles demo playback.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demo_togglepause_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313190
// Name: _dynamic_initializer_for__demo_gototick_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_gototick_command__()
{
  ConCommand::ConCommand(
    this: &demo_gototick_command,
    pName: "demo_gototick",
    callback: demo_gototick,
    pHelpString: "Skips to a tick in demo.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demo_gototick_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103131C0
// Name: _dynamic_initializer_for__demo_timescale_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__demo_timescale_command__()
{
  ConCommand::ConCommand(
    this: &demo_timescale_command,
    pName: "demo_timescale",
    callback: demo_timescale,
    pHelpString: "Sets demo replay speed.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__demo_timescale_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10322510
// Name: _dynamic_atexit_destructor_for__demo_recordcommands__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_recordcommands__()
{
  ConVar::~ConVar(this: &demo_recordcommands);
}

//------------------------------------------------------------------------------
// Address: 0x10322520
// Name: _dynamic_atexit_destructor_for__demo_quitafterplayback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_quitafterplayback__()
{
  ConVar::~ConVar(this: &demo_quitafterplayback);
}

//------------------------------------------------------------------------------
// Address: 0x10322530
// Name: _dynamic_atexit_destructor_for__demo_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_debug__()
{
  ConVar::~ConVar(this: &demo_debug);
}

//------------------------------------------------------------------------------
// Address: 0x10322540
// Name: _dynamic_atexit_destructor_for__demo_interpolateview__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_interpolateview__()
{
  ConVar::~ConVar(this: &demo_interpolateview);
}

//------------------------------------------------------------------------------
// Address: 0x10322550
// Name: _dynamic_atexit_destructor_for__demo_pauseatservertick__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_pauseatservertick__()
{
  ConVar::~ConVar(this: &demo_pauseatservertick);
}

//------------------------------------------------------------------------------
// Address: 0x10322560
// Name: _dynamic_atexit_destructor_for__demo_enabledemos__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_enabledemos__()
{
  ConVar::~ConVar(this: &demo_enabledemos);
}

//------------------------------------------------------------------------------
// Address: 0x10322570
// Name: _dynamic_atexit_destructor_for__demo_interplimit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_interplimit__()
{
  ConVar::~ConVar(this: &demo_interplimit);
}

//------------------------------------------------------------------------------
// Address: 0x10322580
// Name: _dynamic_atexit_destructor_for__demo_avellimit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_avellimit__()
{
  ConVar::~ConVar(this: &demo_avellimit);
}

//------------------------------------------------------------------------------
// Address: 0x10322590
// Name: _dynamic_atexit_destructor_for__demo_fastforwardstartspeed__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_fastforwardstartspeed__()
{
  ConVar::~ConVar(this: &demo_fastforwardstartspeed);
}

//------------------------------------------------------------------------------
// Address: 0x103225A0
// Name: _dynamic_atexit_destructor_for__demo_fastforwardfinalspeed__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_fastforwardfinalspeed__()
{
  ConVar::~ConVar(this: &demo_fastforwardfinalspeed);
}

//------------------------------------------------------------------------------
// Address: 0x103225B0
// Name: _dynamic_atexit_destructor_for__demo_fastforwardramptime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_fastforwardramptime__()
{
  ConVar::~ConVar(this: &demo_fastforwardramptime);
}

//------------------------------------------------------------------------------
// Address: 0x103225D0
// Name: _dynamic_atexit_destructor_for__demo_legacy_rollback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_legacy_rollback__()
{
  ConVar::~ConVar(this: &demo_legacy_rollback);
}

//------------------------------------------------------------------------------
// Address: 0x10322680
// Name: _dynamic_atexit_destructor_for__demo_pause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_pause_command__()
{
  ConCommand::~ConCommand(this: &demo_pause_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322690
// Name: _dynamic_atexit_destructor_for__demo_resume_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_resume_command__()
{
  ConCommand::~ConCommand(this: &demo_resume_command);
}

//------------------------------------------------------------------------------
// Address: 0x103226A0
// Name: _dynamic_atexit_destructor_for__demo_togglepause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_togglepause_command__()
{
  ConCommand::~ConCommand(this: &demo_togglepause_command);
}

//------------------------------------------------------------------------------
// Address: 0x103226B0
// Name: _dynamic_atexit_destructor_for__demo_gototick_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_gototick_command__()
{
  ConCommand::~ConCommand(this: &demo_gototick_command);
}

//------------------------------------------------------------------------------
// Address: 0x103226C0
// Name: _dynamic_atexit_destructor_for__demo_timescale_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__demo_timescale_command__()
{
  ConCommand::~ConCommand(this: &demo_timescale_command);
}

//------------------------------------------------------------------------------
// Address: 0x103131F0
// Name: _dynamic_initializer_for__g_FactoryCDemoActionSkipAhead__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionSkipAhead__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_SKIPAHEAD, func: FnCreateCDemoActionSkipAhead);
}

//------------------------------------------------------------------------------
// Address: 0x10313200
// Name: _dynamic_initializer_for__g_FactoryCDemoActionStopPlayback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionStopPlayback__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_STOPPLAYBACK, func: FnCreateCDemoActionStopPlayback);
}

//------------------------------------------------------------------------------
// Address: 0x10313210
// Name: _dynamic_initializer_for__g_FactoryCDemoActionPlayCommands__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionPlayCommands__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_PLAYCOMMANDS, func: FnCreateCDemoActionPlayCommands);
}

//------------------------------------------------------------------------------
// Address: 0x10313220
// Name: _dynamic_initializer_for__g_FactoryCDemoActionScreenFadeStart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionScreenFadeStart__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_SCREENFADE_START, func: FnCreateCDemoActionScreenFadeStart);
}

//------------------------------------------------------------------------------
// Address: 0x10313230
// Name: _dynamic_initializer_for__g_FactoryCDemoActionTextMessageStart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionTextMessageStart__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_TEXTMESSAGE_START, func: FnCreateCDemoActionTextMessageStart);
}

//------------------------------------------------------------------------------
// Address: 0x10313240
// Name: _dynamic_initializer_for__g_FactoryCDemoActionCDTrackStart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionCDTrackStart__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_PLAYCDTRACK_START, func: FnCreateCDemoActionCDTrackStart);
}

//------------------------------------------------------------------------------
// Address: 0x10313250
// Name: _dynamic_initializer_for__g_FactoryCDemoActionCDTrackStop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionCDTrackStop__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_PLAYCDTRACK_STOP, func: FnCreateCDemoActionCDTrackStop);
}

//------------------------------------------------------------------------------
// Address: 0x10313260
// Name: _dynamic_initializer_for__g_FactoryCDemoActionPlaySoundStart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionPlaySoundStart__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_PLAYSOUND_START, func: FnCreateCDemoActionPlaySoundStart);
}

//------------------------------------------------------------------------------
// Address: 0x10313270
// Name: _dynamic_initializer_for__g_FactoryCDemoActionChangePlaybackRate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionChangePlaybackRate__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_CHANGEPLAYBACKRATE, func: FnCreateCDemoActionChangePlaybackRate);
}

//------------------------------------------------------------------------------
// Address: 0x10313280
// Name: _dynamic_initializer_for__g_FactoryCDemoActionPausePlayback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionPausePlayback__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_PAUSE, func: FnCreateCDemoActionPausePlayback);
}

//------------------------------------------------------------------------------
// Address: 0x10313290
// Name: _dynamic_initializer_for__g_FactoryCDemoActionZoom__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryCDemoActionZoom__()
{
  CBaseDemoAction::AddFactory(actionType: DEMO_ACTION_ZOOM, func: FnCreateCDemoActionZoom);
}

//------------------------------------------------------------------------------
// Address: 0x103132A0
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionSkipAheadDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionSkipAheadDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_SKIPAHEAD,
    func: (CBaseActionEditDialog *(__cdecl *)(CDemoEditorPanel *, CBaseDemoAction *, bool))FnCreateEditorCBaseActionSkipAheadDialog);
}

//------------------------------------------------------------------------------
// Address: 0x103132B0
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionStopPlaybackDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionStopPlaybackDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_STOPPLAYBACK,
    func: (CBaseActionEditDialog *(__cdecl *)(CDemoEditorPanel *, CBaseDemoAction *, bool))FnCreateEditorCBaseActionStopPlaybackDialog);
}

//------------------------------------------------------------------------------
// Address: 0x103132C0
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionScreenFadeStartDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionScreenFadeStartDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_SCREENFADE_START,
    func: (CBaseActionEditDialog *(__cdecl *)(CDemoEditorPanel *, CBaseDemoAction *, bool))FnCreateEditorCBaseActionScreenFadeStartDialog);
}

//------------------------------------------------------------------------------
// Address: 0x103132D0
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionTextMessageStartDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionTextMessageStartDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_TEXTMESSAGE_START,
    func: (CBaseActionEditDialog *(__cdecl *)(CDemoEditorPanel *, CBaseDemoAction *, bool))FnCreateEditorCBaseActionTextMessageStartDialog);
}

//------------------------------------------------------------------------------
// Address: 0x103132E0
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionPlayCommandsDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionPlayCommandsDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_PLAYCOMMANDS,
    func: (CBaseActionEditDialog *(__cdecl *)(CDemoEditorPanel *, CBaseDemoAction *, bool))FnCreateEditorCBaseActionPlayCommandsDialog);
}

//------------------------------------------------------------------------------
// Address: 0x103132F0
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionCDTrackStartDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionCDTrackStartDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_PLAYCDTRACK_START,
    func: (CBaseActionEditDialog *(__cdecl *)(CDemoEditorPanel *, CBaseDemoAction *, bool))FnCreateEditorCBaseActionCDTrackStartDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10313300
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionPlaySoundStartDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionPlaySoundStartDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_PLAYSOUND_START,
    func: FnCreateEditorCBaseActionPlaySoundStartDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10313310
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionChangePlaybackRateDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionChangePlaybackRateDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_CHANGEPLAYBACKRATE,
    func: FnCreateEditorCBaseActionChangePlaybackRateDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10313320
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionPauseDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionPauseDialog__()
{
  CBaseDemoAction::AddEditorFactory(actionType: DEMO_ACTION_PAUSE, func: FnCreateEditorCBaseActionPauseDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10313330
// Name: _dynamic_initializer_for__g_FactoryEditorCBaseActionZoomDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_FactoryEditorCBaseActionZoomDialog__()
{
  CBaseDemoAction::AddEditorFactory(
    actionType: DEMO_ACTION_ZOOM,
    func: (CBaseActionEditDialog *(__cdecl *)(CDemoEditorPanel *, CBaseDemoAction *, bool))FnCreateEditorCBaseActionZoomDialog);
}

//------------------------------------------------------------------------------
// Address: 0x10313340
// Name: _dynamic_initializer_for__g_DemoActionManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DemoActionManager__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DemoActionManager__);
}

//------------------------------------------------------------------------------
// Address: 0x103226D0
// Name: _dynamic_atexit_destructor_for__g_DemoOverlay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DemoOverlay__()
{
  ;
}

} // namespace engine_xlsp
