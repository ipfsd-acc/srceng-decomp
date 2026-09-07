// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/lzma/c/7zip/compress/lz/lzinwindow.cpp
// Functions: 6
// ============================================================

#include "utils\lzma\c\7zip\compress\lz\lzinwindow.h"

//------------------------------------------------------------------------------
// Address: 0x1001DF80
// Name: protected: void CLZInWindow::Free(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLZInWindow::Free(CLZInWindow *this)
{
  MidFree(address: this->_bufferBase);
  this->_bufferBase = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001DFA0
// Name: public: bool CLZInWindow::Create(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLZInWindow::Create(
        CLZInWindow *this,
        unsigned int keepSizeBefore,
        unsigned int keepSizeAfter,
        unsigned int keepSizeReserv)
{
  unsigned __int8 *bufferBase; // eax
  unsigned int v6; // edi
  unsigned int blockSize; // eax
  unsigned __int8 *v8; // ecx

  bufferBase = this->_bufferBase;
  this->_keepSizeBefore = keepSizeBefore;
  v6 = keepSizeReserv + keepSizeAfter + keepSizeBefore;
  this->_keepSizeAfter = keepSizeAfter;
  if ( bufferBase == nullptr || this->_blockSize != v6 )
  {
    MidFree(address: bufferBase);
    this->_bufferBase = nullptr;
    this->_blockSize = v6;
    if ( v6 != 0 )
      this->_bufferBase = (unsigned __int8 *)BigAlloc(size: v6);
  }
  blockSize = this->_blockSize;
  v8 = this->_bufferBase;
  this->_pointerToLastSafePosition = &v8[blockSize - keepSizeAfter];
  return blockSize == 0 || v8 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001E010
// Name: public: void CLZInWindow::SetStream(struct ISequentialInStream __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLZInWindow::SetStream(CLZInWindow *this, ISequentialInStream *stream)
{
  this->_stream = stream;
}

//------------------------------------------------------------------------------
// Address: 0x1001E020
// Name: protected: long CLZInWindow::ReadBlock(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZInWindow::ReadBlock(CLZInWindow *this)
{
  unsigned int result; // eax
  unsigned int keepSizeAfter; // edx
  unsigned int v4; // eax
  unsigned int streamPos; // ecx
  unsigned __int8 *buffer; // edx
  const unsigned __int8 *pointerToLastSafePosition; // eax
  unsigned int numReadBytes; // [esp+4h] [ebp-4h] BYREF

  if ( this->_streamEndWasReached )
    return 0;
  result = this->_blockSize + this->_bufferBase - this->_buffer - this->_streamPos;
  if ( result == 0 )
    return 0;
  do
  {
    result = this->_stream->Read(
               this: this->_stream,
               a2: &this->_buffer[this->_streamPos],
               a3: result,
               a4: &numReadBytes);
    if ( result != 0 )
      break;
    if ( numReadBytes == 0 )
    {
      streamPos = this->_streamPos;
      buffer = this->_buffer;
      pointerToLastSafePosition = this->_pointerToLastSafePosition;
      this->_posLimit = streamPos;
      if ( &buffer[streamPos] > pointerToLastSafePosition )
        this->_posLimit = pointerToLastSafePosition - buffer;
      this->_streamEndWasReached = true;
      return 0;
    }
    keepSizeAfter = this->_keepSizeAfter;
    this->_streamPos += numReadBytes;
    v4 = this->_streamPos;
    if ( v4 >= this->_pos + keepSizeAfter )
    {
      this->_posLimit = v4 - this->_keepSizeAfter;
      return 0;
    }
    result = this->_blockSize + this->_bufferBase - this->_buffer - this->_streamPos;
  }
  while ( result != 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001E0C0
// Name: protected: void CLZInWindow::MoveBlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLZInWindow::MoveBlock(CLZInWindow *this)
{
  unsigned int v2; // esi
  unsigned __int8 *bufferBase; // eax
  unsigned __int8 *buffer; // ecx
  unsigned int v5; // esi

  v2 = this->_pos - this->_keepSizeBefore;
  bufferBase = this->_bufferBase;
  buffer = this->_buffer;
  v5 = (unsigned int)&buffer[v2 - (_DWORD)bufferBase];
  if ( v5 != 0 )
    --v5;
  memmove(
    dst: bufferBase,
    src: &bufferBase[v5],
    count: (unsigned int)&buffer[this->_streamPos - (_DWORD)bufferBase - v5]);
  this->_buffer -= v5;
}

//------------------------------------------------------------------------------
// Address: 0x1001E100
// Name: public: long CLZInWindow::Init(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZInWindow::Init(CLZInWindow *this)
{
  this->_buffer = this->_bufferBase;
  this->_pos = 0;
  this->_streamPos = 0;
  this->_streamEndWasReached = false;
  return CLZInWindow::ReadBlock(this);
}

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x004BCAF0
// Name: protected: void CLZInWindow::Free(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLZInWindow::Free(CLZInWindow *this)
{
  MidFree(address: this->_bufferBase);
  this->_bufferBase = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004BCB10
// Name: public: bool CLZInWindow::Create(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLZInWindow::Create(
        CLZInWindow *this,
        unsigned int keepSizeBefore,
        unsigned int keepSizeAfter,
        unsigned int keepSizeReserv)
{
  unsigned __int8 *bufferBase; // eax
  unsigned int v6; // edi
  unsigned int blockSize; // eax
  unsigned __int8 *v8; // ecx

  bufferBase = this->_bufferBase;
  this->_keepSizeBefore = keepSizeBefore;
  v6 = keepSizeReserv + keepSizeAfter + keepSizeBefore;
  this->_keepSizeAfter = keepSizeAfter;
  if ( bufferBase == nullptr || this->_blockSize != v6 )
  {
    MidFree(address: bufferBase);
    this->_bufferBase = nullptr;
    this->_blockSize = v6;
    if ( v6 != 0 )
      this->_bufferBase = (unsigned __int8 *)BigAlloc(size: v6);
  }
  blockSize = this->_blockSize;
  v8 = this->_bufferBase;
  this->_pointerToLastSafePosition = &v8[blockSize - keepSizeAfter];
  return blockSize == 0 || v8 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004BCB80
// Name: public: void CLZInWindow::SetStream(struct ISequentialInStream __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLZInWindow::SetStream(CLZInWindow *this, ISequentialInStream *stream)
{
  this->_stream = stream;
}

//------------------------------------------------------------------------------
// Address: 0x004BCB90
// Name: protected: long CLZInWindow::ReadBlock(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZInWindow::ReadBlock(CLZInWindow *this)
{
  unsigned int result; // eax
  unsigned int keepSizeAfter; // edx
  unsigned int v4; // eax
  unsigned int streamPos; // ecx
  unsigned __int8 *buffer; // edx
  const unsigned __int8 *pointerToLastSafePosition; // eax
  unsigned int numReadBytes; // [esp+4h] [ebp-4h] BYREF

  if ( this->_streamEndWasReached )
    return 0;
  result = this->_blockSize + this->_bufferBase - this->_buffer - this->_streamPos;
  if ( result == 0 )
    return 0;
  do
  {
    result = this->_stream->Read(
               this: this->_stream,
               a2: &this->_buffer[this->_streamPos],
               a3: result,
               a4: &numReadBytes);
    if ( result != 0 )
      break;
    if ( numReadBytes == 0 )
    {
      streamPos = this->_streamPos;
      buffer = this->_buffer;
      pointerToLastSafePosition = this->_pointerToLastSafePosition;
      this->_posLimit = streamPos;
      if ( &buffer[streamPos] > pointerToLastSafePosition )
        this->_posLimit = pointerToLastSafePosition - buffer;
      this->_streamEndWasReached = true;
      return 0;
    }
    keepSizeAfter = this->_keepSizeAfter;
    this->_streamPos += numReadBytes;
    v4 = this->_streamPos;
    if ( v4 >= this->_pos + keepSizeAfter )
    {
      this->_posLimit = v4 - this->_keepSizeAfter;
      return 0;
    }
    result = this->_blockSize + this->_bufferBase - this->_buffer - this->_streamPos;
  }
  while ( result != 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BCC30
// Name: protected: void CLZInWindow::MoveBlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLZInWindow::MoveBlock(CLZInWindow *this)
{
  unsigned int v2; // esi
  unsigned __int8 *bufferBase; // eax
  unsigned __int8 *buffer; // ecx
  unsigned int v5; // esi

  v2 = this->_pos - this->_keepSizeBefore;
  bufferBase = this->_bufferBase;
  buffer = this->_buffer;
  v5 = (unsigned int)&buffer[v2 - (_DWORD)bufferBase];
  if ( v5 != 0 )
    --v5;
  memmove(
    dst: bufferBase,
    src: &bufferBase[v5],
    count: (unsigned int)&buffer[this->_streamPos - (_DWORD)bufferBase - v5]);
  this->_buffer -= v5;
}

//------------------------------------------------------------------------------
// Address: 0x004BCC70
// Name: public: long CLZInWindow::Init(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZInWindow::Init(CLZInWindow *this)
{
  this->_buffer = this->_bufferBase;
  this->_pos = 0;
  this->_streamPos = 0;
  this->_streamEndWasReached = false;
  return CLZInWindow::ReadBlock(this);
}

} // namespace hlfaceposer

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00526660
// Name: protected: void CLZInWindow::Free(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLZInWindow::Free(CLZInWindow *this)
{
  MidFree(address: this->_bufferBase);
  this->_bufferBase = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00526680
// Name: public: bool CLZInWindow::Create(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLZInWindow::Create(
        CLZInWindow *this,
        unsigned int keepSizeBefore,
        unsigned int keepSizeAfter,
        unsigned int keepSizeReserv)
{
  unsigned __int8 *bufferBase; // eax
  unsigned int v6; // edi
  unsigned int blockSize; // eax
  unsigned __int8 *v8; // ecx

  bufferBase = this->_bufferBase;
  this->_keepSizeBefore = keepSizeBefore;
  v6 = keepSizeReserv + keepSizeAfter + keepSizeBefore;
  this->_keepSizeAfter = keepSizeAfter;
  if ( bufferBase == nullptr || this->_blockSize != v6 )
  {
    MidFree(address: bufferBase);
    this->_bufferBase = nullptr;
    this->_blockSize = v6;
    if ( v6 != 0 )
      this->_bufferBase = (unsigned __int8 *)BigAlloc(size: v6);
  }
  blockSize = this->_blockSize;
  v8 = this->_bufferBase;
  this->_pointerToLastSafePosition = &v8[blockSize - keepSizeAfter];
  return blockSize == 0 || v8 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005266F0
// Name: public: void CLZInWindow::SetStream(struct ISequentialInStream __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLZInWindow::SetStream(CLZInWindow *this, ISequentialInStream *stream)
{
  this->_stream = stream;
}

//------------------------------------------------------------------------------
// Address: 0x00526700
// Name: protected: long CLZInWindow::ReadBlock(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZInWindow::ReadBlock(CLZInWindow *this)
{
  unsigned int result; // eax
  unsigned int keepSizeAfter; // edx
  unsigned int v4; // eax
  unsigned int streamPos; // ecx
  unsigned __int8 *buffer; // edx
  const unsigned __int8 *pointerToLastSafePosition; // eax
  unsigned int numReadBytes; // [esp+4h] [ebp-4h] BYREF

  if ( this->_streamEndWasReached )
    return 0;
  result = this->_blockSize + this->_bufferBase - this->_buffer - this->_streamPos;
  if ( result == 0 )
    return 0;
  do
  {
    result = this->_stream->Read(
               this: this->_stream,
               a2: &this->_buffer[this->_streamPos],
               a3: result,
               a4: &numReadBytes);
    if ( result != 0 )
      break;
    if ( numReadBytes == 0 )
    {
      streamPos = this->_streamPos;
      buffer = this->_buffer;
      pointerToLastSafePosition = this->_pointerToLastSafePosition;
      this->_posLimit = streamPos;
      if ( &buffer[streamPos] > pointerToLastSafePosition )
        this->_posLimit = pointerToLastSafePosition - buffer;
      this->_streamEndWasReached = true;
      return 0;
    }
    keepSizeAfter = this->_keepSizeAfter;
    this->_streamPos += numReadBytes;
    v4 = this->_streamPos;
    if ( v4 >= this->_pos + keepSizeAfter )
    {
      this->_posLimit = v4 - this->_keepSizeAfter;
      return 0;
    }
    result = this->_blockSize + this->_bufferBase - this->_buffer - this->_streamPos;
  }
  while ( result != 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005267A0
// Name: protected: void CLZInWindow::MoveBlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLZInWindow::MoveBlock(CLZInWindow *this)
{
  unsigned int v2; // esi
  unsigned __int8 *bufferBase; // eax
  unsigned __int8 *buffer; // ecx
  unsigned int v5; // esi

  v2 = this->_pos - this->_keepSizeBefore;
  bufferBase = this->_bufferBase;
  buffer = this->_buffer;
  v5 = (unsigned int)&buffer[v2 - (_DWORD)bufferBase];
  if ( v5 != 0 )
    --v5;
  memmove(
    dst: bufferBase,
    src: &bufferBase[v5],
    count: (unsigned int)&buffer[this->_streamPos - (_DWORD)bufferBase - v5]);
  this->_buffer -= v5;
}

//------------------------------------------------------------------------------
// Address: 0x005267E0
// Name: public: long CLZInWindow::Init(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZInWindow::Init(CLZInWindow *this)
{
  this->_buffer = this->_bufferBase;
  this->_pos = 0;
  this->_streamPos = 0;
  this->_streamEndWasReached = false;
  return CLZInWindow::ReadBlock(this);
}

} // namespace makegamedata

// ============================================================
// Overlay from shadercompile_dll (Missing functions)
// ============================================================
namespace shadercompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10017B90
// Name: protected: void CLZInWindow::Free(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLZInWindow::Free(CLZInWindow *this)
{
  MidFree(address: this->_bufferBase);
  this->_bufferBase = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10017BB0
// Name: public: bool CLZInWindow::Create(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLZInWindow::Create(
        CLZInWindow *this,
        unsigned int keepSizeBefore,
        unsigned int keepSizeAfter,
        unsigned int keepSizeReserv)
{
  unsigned __int8 *bufferBase; // eax
  unsigned int v6; // edi
  unsigned int blockSize; // eax
  unsigned __int8 *v8; // ecx

  bufferBase = this->_bufferBase;
  this->_keepSizeBefore = keepSizeBefore;
  v6 = keepSizeReserv + keepSizeAfter + keepSizeBefore;
  this->_keepSizeAfter = keepSizeAfter;
  if ( bufferBase == nullptr || this->_blockSize != v6 )
  {
    MidFree(address: bufferBase);
    this->_bufferBase = nullptr;
    this->_blockSize = v6;
    if ( v6 != 0 )
      this->_bufferBase = (unsigned __int8 *)BigAlloc(size: v6);
  }
  blockSize = this->_blockSize;
  v8 = this->_bufferBase;
  this->_pointerToLastSafePosition = &v8[blockSize - keepSizeAfter];
  return blockSize == 0 || v8 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10017C20
// Name: protected: long CLZInWindow::ReadBlock(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZInWindow::ReadBlock(CLZInWindow *this)
{
  unsigned int result; // eax
  unsigned int keepSizeAfter; // edx
  unsigned int v4; // eax
  unsigned int streamPos; // ecx
  unsigned __int8 *buffer; // edx
  const unsigned __int8 *pointerToLastSafePosition; // eax
  unsigned int numReadBytes; // [esp+4h] [ebp-4h] BYREF

  if ( this->_streamEndWasReached )
    return 0;
  result = this->_blockSize + this->_bufferBase - this->_buffer - this->_streamPos;
  if ( result == 0 )
    return 0;
  do
  {
    result = this->_stream->Read(
               this: this->_stream,
               a2: &this->_buffer[this->_streamPos],
               a3: result,
               a4: &numReadBytes);
    if ( result != 0 )
      break;
    if ( numReadBytes == 0 )
    {
      streamPos = this->_streamPos;
      buffer = this->_buffer;
      pointerToLastSafePosition = this->_pointerToLastSafePosition;
      this->_posLimit = streamPos;
      if ( &buffer[streamPos] > pointerToLastSafePosition )
        this->_posLimit = pointerToLastSafePosition - buffer;
      this->_streamEndWasReached = true;
      return 0;
    }
    keepSizeAfter = this->_keepSizeAfter;
    this->_streamPos += numReadBytes;
    v4 = this->_streamPos;
    if ( v4 >= this->_pos + keepSizeAfter )
    {
      this->_posLimit = v4 - this->_keepSizeAfter;
      return 0;
    }
    result = this->_blockSize + this->_bufferBase - this->_buffer - this->_streamPos;
  }
  while ( result != 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017CC0
// Name: protected: void CLZInWindow::MoveBlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLZInWindow::MoveBlock(CLZInWindow *this)
{
  unsigned int v2; // esi
  unsigned __int8 *bufferBase; // eax
  unsigned __int8 *buffer; // ecx
  unsigned int v5; // esi

  v2 = this->_pos - this->_keepSizeBefore;
  bufferBase = this->_bufferBase;
  buffer = this->_buffer;
  v5 = (unsigned int)&buffer[v2 - (_DWORD)bufferBase];
  if ( v5 != 0 )
    --v5;
  memmove(
    dst: bufferBase,
    src: &bufferBase[v5],
    count: (unsigned int)&buffer[this->_streamPos - (_DWORD)bufferBase - v5]);
  this->_buffer -= v5;
}

//------------------------------------------------------------------------------
// Address: 0x10017D00
// Name: public: long CLZInWindow::Init(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLZInWindow::Init(CLZInWindow *this)
{
  this->_buffer = this->_bufferBase;
  this->_pos = 0;
  this->_streamPos = 0;
  this->_streamEndWasReached = false;
  return CLZInWindow::ReadBlock(this);
}

//------------------------------------------------------------------------------
// Address: 0x10022800
// Name: public: void CLZInWindow::SetStream(struct ISequentialInStream __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLZInWindow::SetStream(
        CInternalFileSystemPassThru<IFileSystem> *this,
        IBaseFileSystem *pBaseFileSystemPassThru)
{
  this->m_pBaseFileSystemPassThru = pBaseFileSystemPassThru;
}

} // namespace shadercompile_dll
