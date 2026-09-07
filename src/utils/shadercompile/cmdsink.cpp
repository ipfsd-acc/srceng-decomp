// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/shadercompile/cmdsink.cpp
// Functions: 9
// ============================================================

#include "utils\shadercompile\cmdsink.h"

//------------------------------------------------------------------------------
// Address: 0x10008150
// Name: public: virtual void CmdSink::IResponse::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CmdSink::IResponse::Release(CmdSink::IResponse *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CmdSink::IResponse *, int))this->dtr_IResponse)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10008160
// Name: public: virtual bool CmdSink::CResponseFiles::Succeeded(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CmdSink::CResponseFiles::Succeeded(CmdSink::CResponseFiles *this)
{
  if ( this->m_fResult == nullptr )
    this->m_fResult = fopen(file: (_iobuf *)this->m_szFileResult, mode: "rb");
  return this->m_fResult != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10008190
// Name: protected: void CmdSink::CResponseFiles::ReadResultFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CmdSink::CResponseFiles::ReadResultFile(CmdSink::CResponseFiles *this)
{
  _iobuf *m_fResult; // eax
  int v3; // eax

  if ( this->m_dataResult == nullptr )
  {
    if ( this->m_fResult == nullptr )
      this->m_fResult = fopen(file: (_iobuf *)this->m_szFileResult, mode: "rb");
    m_fResult = this->m_fResult;
    if ( m_fResult != nullptr )
    {
      fseek(stream: m_fResult, offset: 0, whence: 2u);
      v3 = ftell(stream: this->m_fResult);
      this->m_lenResult = v3;
      if ( v3 != -1 )
      {
        CUtlBuffer::EnsureCapacity(this: &this->m_bufResult, num: v3);
        fseek(stream: this->m_fResult, offset: 0, whence: 0);
        fread(
          buffer: (char *)this->m_bufResult.m_Memory.m_pMemory,
          elementSize: 1u,
          count: this->m_lenResult,
          stream: this->m_fResult);
        this->m_dataResult = this->m_bufResult.m_Memory.m_pMemory;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008240
// Name: protected: void CmdSink::CResponseFiles::ReadListingFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CmdSink::CResponseFiles::ReadListingFile(CmdSink::CResponseFiles *this)
{
  _iobuf *m_fListing; // eax
  int v3; // eax
  unsigned int v4; // ebx

  if ( this->m_dataListing == nullptr )
  {
    if ( this->m_fListing == nullptr )
      this->m_fListing = fopen(file: (_iobuf *)this->m_szFileListing, mode: "rb");
    m_fListing = this->m_fListing;
    if ( m_fListing != nullptr )
    {
      fseek(stream: m_fListing, offset: 0, whence: 2u);
      v3 = ftell(stream: this->m_fListing);
      v4 = v3;
      if ( v3 != -1 )
      {
        CUtlBuffer::EnsureCapacity(this: &this->m_bufListing, num: v3);
        fseek(stream: this->m_fListing, offset: 0, whence: 0);
        fread(
          buffer: (char *)this->m_bufListing.m_Memory.m_pMemory,
          elementSize: 1u,
          count: v4,
          stream: this->m_fListing);
        this->m_dataListing = (const char *)this->m_bufListing.m_Memory.m_pMemory;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100082F0
// Name: public: virtual unsigned int CmdSink::CResponseFiles::GetResultBufferLen(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CmdSink::CResponseFiles::GetResultBufferLen(CmdSink::CResponseFiles *this)
{
  CmdSink::CResponseFiles::ReadResultFile(this);
  return this->m_lenResult;
}

//------------------------------------------------------------------------------
// Address: 0x10008300
// Name: public: virtual void const __near * CmdSink::CResponseFiles::GetResultBuffer(void)
// Source: json
//------------------------------------------------------------------------------
const void *__thiscall CmdSink::CResponseFiles::GetResultBuffer(CmdSink::CResponseFiles *this)
{
  CmdSink::CResponseFiles::ReadResultFile(this);
  return this->m_dataResult;
}

//------------------------------------------------------------------------------
// Address: 0x10008310
// Name: public: virtual char const __near * CmdSink::CResponseFiles::GetListing(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CmdSink::CResponseFiles::GetListing(CmdSink::CResponseFiles *this)
{
  const char *result; // eax

  CmdSink::CResponseFiles::ReadListingFile(this);
  result = this->m_dataListing;
  if ( result == nullptr || *result == 0 )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008330
// Name: public: virtual CmdSink::CResponseFiles::~CResponseFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CmdSink::CResponseFiles::~CResponseFiles(CmdSink::CResponseFiles *this)
{
  _iobuf *m_fResult; // eax

  m_fResult = this->m_fResult;
  this->__vftable = (CmdSink::CResponseFiles_vtbl *)&CmdSink::CResponseFiles::`vftable';
  if ( m_fResult != nullptr )
    fclose(stream: m_fResult);
  if ( this->m_fListing != nullptr )
    fclose(stream: this->m_fListing);
  if ( this->m_bufListing.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_bufListing.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_bufListing.m_Memory.m_pMemory);
      this->m_bufListing.m_Memory.m_pMemory = nullptr;
    }
    this->m_bufListing.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_bufResult.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_bufResult.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_bufResult.m_Memory.m_pMemory);
      this->m_bufResult.m_Memory.m_pMemory = nullptr;
    }
    this->m_bufResult.m_Memory.m_nAllocationCount = 0;
  }
  this->__vftable = (CmdSink::CResponseFiles_vtbl *)&CmdSink::IResponse::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100083D0
// Name: public: CmdSink::CResponseFiles::CResponseFiles(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CmdSink::CResponseFiles *__thiscall CmdSink::CResponseFiles::CResponseFiles(
        CmdSink::CResponseFiles *this,
        const char *szFileResult,
        const char *szFileListing)
{
  this->__vftable = (CmdSink::CResponseFiles_vtbl *)&CmdSink::CResponseFiles::`vftable';
  this->m_fResult = nullptr;
  this->m_fListing = nullptr;
  CUtlBuffer::CUtlBuffer(this: &this->m_bufResult, growSize: 0, initSize: 0, nFlags: 0);
  this->m_lenResult = 0;
  this->m_dataResult = nullptr;
  CUtlBuffer::CUtlBuffer(this: &this->m_bufListing, growSize: 0, initSize: 0, nFlags: 0);
  this->m_dataListing = nullptr;
  sprintf(string: this->m_szFileResult, format: szFileResult);
  sprintf(string: this->m_szFileListing, format: szFileListing);
  return this;
}
