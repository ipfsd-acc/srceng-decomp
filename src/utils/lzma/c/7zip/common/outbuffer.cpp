// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/lzma/c/7zip/common/outbuffer.cpp
// Functions: 8
// ============================================================

#include "utils\lzma\c\7zip\common\outbuffer.h"

//------------------------------------------------------------------------------
// Address: 0x1001DC50
// Name: public: void COutBuffer::Free(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COutBuffer::Free(COutBuffer *this)
{
  MidFree(address: this->_buffer);
  this->_buffer = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001DC70
// Name: public: void COutBuffer::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COutBuffer::Init(COutBuffer *this)
{
  unsigned int bufferSize; // edx

  bufferSize = this->_bufferSize;
  this->_streamPos = 0;
  this->_limitPos = bufferSize;
  this->_pos = 0;
  this->_processedSize = 0;
  this->_overDict = false;
  this->ErrorCode = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001DC90
// Name: public: unsigned __int64 COutBuffer::GetProcessedSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall COutBuffer::GetProcessedSize(COutBuffer *this)
{
  unsigned int streamPos; // esi
  unsigned int pos; // edi
  unsigned __int64 result; // rax

  streamPos = this->_streamPos;
  pos = this->_pos;
  result = pos + this->_processedSize - streamPos;
  if ( streamPos > pos )
    result += this->_bufferSize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001DCC0
// Name: public: bool COutBuffer::Create(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall COutBuffer::Create(COutBuffer *this, unsigned int bufferSize)
{
  unsigned int v2; // edi
  unsigned __int8 *v5; // eax

  v2 = bufferSize;
  if ( bufferSize == 0 )
    v2 = 1;
  if ( this->_buffer != nullptr && this->_bufferSize == v2 )
    return true;
  MidFree(address: this->_buffer);
  this->_buffer = nullptr;
  this->_bufferSize = v2;
  v5 = (unsigned __int8 *)MidAlloc(size: v2);
  this->_buffer = v5;
  return v5 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001DD10
// Name: public: void COutBuffer::SetStream(struct ISequentialOutStream __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COutBuffer::SetStream(COutBuffer *this, ISequentialOutStream *stream)
{
  ISequentialOutStream *p; // eax

  if ( stream != nullptr )
    stream->AddRef(this: stream);
  p = this->_stream._p;
  if ( p != nullptr )
    p->Release(this: this->_stream._p);
  this->_stream._p = stream;
}

//------------------------------------------------------------------------------
// Address: 0x1001DD40
// Name: protected: long COutBuffer::FlushPart(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall COutBuffer::FlushPart(COutBuffer *this)
{
  unsigned int streamPos; // eax
  unsigned int pos; // edi
  HRESULT ErrorCode; // ebx
  unsigned int v5; // edi
  unsigned __int8 *buffer2; // eax
  ISequentialOutStream *p; // eax
  unsigned __int8 *v8; // ecx
  int v9; // eax
  unsigned int bufferSize; // eax
  bool v11; // cf
  unsigned int processedSize; // [esp+Ch] [ebp-4h] BYREF

  streamPos = this->_streamPos;
  pos = this->_pos;
  if ( streamPos >= pos )
    pos = this->_bufferSize;
  ErrorCode = this->ErrorCode;
  v5 = pos - streamPos;
  buffer2 = this->_buffer2;
  if ( buffer2 != nullptr )
  {
    memmove(dst: buffer2, src: &this->_buffer[this->_streamPos], count: v5);
    this->_buffer2 += v5;
  }
  p = this->_stream._p;
  if ( p != nullptr && this->ErrorCode == 0 )
  {
    v8 = &this->_buffer[this->_streamPos];
    processedSize = 0;
    v9 = p->Write(this: p, a2: v8, a3: v5, a4: &processedSize);
    v5 = processedSize;
    ErrorCode = v9;
  }
  bufferSize = this->_bufferSize;
  this->_streamPos += v5;
  if ( this->_streamPos == bufferSize )
    this->_streamPos = 0;
  if ( this->_pos == bufferSize )
  {
    this->_overDict = true;
    this->_pos = 0;
  }
  if ( this->_streamPos > this->_pos )
    bufferSize = this->_streamPos;
  v11 = __CFADD__(v5, this->_processedSize);
  LODWORD(this->_processedSize) += v5;
  this->_limitPos = bufferSize;
  HIDWORD(this->_processedSize) += v11;
  return ErrorCode;
}

//------------------------------------------------------------------------------
// Address: 0x1001DDE0
// Name: public: long COutBuffer::Flush(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall COutBuffer::Flush(COutBuffer *this)
{
  HRESULT result; // eax
  unsigned int streamPos; // eax
  unsigned int pos; // ecx
  bool v5; // cf
  unsigned int v6; // edi
  unsigned __int8 *buffer2; // eax
  HRESULT ErrorCode; // ebx
  ISequentialOutStream *p; // eax
  unsigned __int8 *v10; // ecx
  int v11; // eax
  unsigned int bufferSize; // edx
  unsigned int v13; // [esp+4h] [ebp-4h] BYREF

  result = this->ErrorCode;
  if ( result == 0 )
  {
    streamPos = this->_streamPos;
    pos = this->_pos;
    v5 = streamPos < pos;
    if ( streamPos == pos )
    {
      return 0;
    }
    else
    {
      while ( 1 )
      {
        if ( v5 )
          v6 = pos - streamPos;
        else
          v6 = this->_bufferSize - streamPos;
        buffer2 = this->_buffer2;
        ErrorCode = this->ErrorCode;
        if ( buffer2 != nullptr )
        {
          memmove(dst: buffer2, src: &this->_buffer[this->_streamPos], count: v6);
          this->_buffer2 += v6;
        }
        p = this->_stream._p;
        if ( p != nullptr && this->ErrorCode == 0 )
        {
          v10 = &this->_buffer[this->_streamPos];
          v13 = 0;
          v11 = p->Write(this: p, a2: v10, a3: v6, a4: &v13);
          v6 = v13;
          ErrorCode = v11;
        }
        bufferSize = this->_bufferSize;
        this->_streamPos += v6;
        if ( this->_streamPos == bufferSize )
          this->_streamPos = 0;
        if ( this->_pos == bufferSize )
        {
          this->_overDict = true;
          this->_pos = 0;
        }
        streamPos = this->_streamPos;
        pos = this->_pos;
        if ( streamPos > pos )
          bufferSize = this->_streamPos;
        v5 = __CFADD__(v6, this->_processedSize);
        LODWORD(this->_processedSize) += v6;
        this->_limitPos = bufferSize;
        HIDWORD(this->_processedSize) += v5;
        if ( ErrorCode != 0 )
          break;
        v5 = streamPos < pos;
        if ( streamPos == pos )
          return 0;
      }
      return ErrorCode;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001DEB0
// Name: protected: void COutBuffer::FlushWithCheck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COutBuffer::FlushWithCheck(COutBuffer *this)
{
  this->ErrorCode = COutBuffer::FlushPart(this);
}

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x004BC7C0
// Name: public: void COutBuffer::Free(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COutBuffer::Free(COutBuffer *this)
{
  MidFree(address: this->_buffer);
  this->_buffer = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004BC7E0
// Name: public: void COutBuffer::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COutBuffer::Init(COutBuffer *this)
{
  unsigned int bufferSize; // edx

  bufferSize = this->_bufferSize;
  this->_streamPos = 0;
  this->_limitPos = bufferSize;
  this->_pos = 0;
  this->_processedSize = 0;
  this->_overDict = false;
  this->ErrorCode = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004BC800
// Name: public: unsigned __int64 COutBuffer::GetProcessedSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall COutBuffer::GetProcessedSize(COutBuffer *this)
{
  unsigned int streamPos; // esi
  unsigned int pos; // edi
  unsigned __int64 result; // rax

  streamPos = this->_streamPos;
  pos = this->_pos;
  result = pos + this->_processedSize - streamPos;
  if ( streamPos > pos )
    result += this->_bufferSize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BC830
// Name: public: bool COutBuffer::Create(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall COutBuffer::Create(COutBuffer *this, unsigned int bufferSize)
{
  unsigned int v2; // edi
  unsigned __int8 *v5; // eax

  v2 = bufferSize;
  if ( bufferSize == 0 )
    v2 = 1;
  if ( this->_buffer != nullptr && this->_bufferSize == v2 )
    return true;
  MidFree(address: this->_buffer);
  this->_buffer = nullptr;
  this->_bufferSize = v2;
  v5 = (unsigned __int8 *)MidAlloc(size: v2);
  this->_buffer = v5;
  return v5 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004BC880
// Name: public: void COutBuffer::SetStream(struct ISequentialOutStream __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COutBuffer::SetStream(COutBuffer *this, ISequentialOutStream *stream)
{
  ISequentialOutStream *p; // eax

  if ( stream != nullptr )
    stream->AddRef(this: stream);
  p = this->_stream._p;
  if ( p != nullptr )
    p->Release(this: this->_stream._p);
  this->_stream._p = stream;
}

//------------------------------------------------------------------------------
// Address: 0x004BC8B0
// Name: protected: long COutBuffer::FlushPart(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall COutBuffer::FlushPart(COutBuffer *this)
{
  unsigned int streamPos; // eax
  unsigned int pos; // edi
  HRESULT ErrorCode; // ebx
  unsigned int v5; // edi
  unsigned __int8 *buffer2; // eax
  ISequentialOutStream *p; // eax
  unsigned __int8 *v8; // ecx
  int v9; // eax
  unsigned int bufferSize; // eax
  bool v11; // cf
  unsigned int processedSize; // [esp+Ch] [ebp-4h] BYREF

  streamPos = this->_streamPos;
  pos = this->_pos;
  if ( streamPos >= pos )
    pos = this->_bufferSize;
  ErrorCode = this->ErrorCode;
  v5 = pos - streamPos;
  buffer2 = this->_buffer2;
  if ( buffer2 != nullptr )
  {
    memmove(dst: buffer2, src: &this->_buffer[this->_streamPos], count: v5);
    this->_buffer2 += v5;
  }
  p = this->_stream._p;
  if ( p != nullptr && this->ErrorCode == 0 )
  {
    v8 = &this->_buffer[this->_streamPos];
    processedSize = 0;
    v9 = p->Write(this: p, a2: v8, a3: v5, a4: &processedSize);
    v5 = processedSize;
    ErrorCode = v9;
  }
  bufferSize = this->_bufferSize;
  this->_streamPos += v5;
  if ( this->_streamPos == bufferSize )
    this->_streamPos = 0;
  if ( this->_pos == bufferSize )
  {
    this->_overDict = true;
    this->_pos = 0;
  }
  if ( this->_streamPos > this->_pos )
    bufferSize = this->_streamPos;
  v11 = __CFADD__(v5, this->_processedSize);
  LODWORD(this->_processedSize) += v5;
  this->_limitPos = bufferSize;
  HIDWORD(this->_processedSize) += v11;
  return ErrorCode;
}

//------------------------------------------------------------------------------
// Address: 0x004BC950
// Name: public: long COutBuffer::Flush(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall COutBuffer::Flush(COutBuffer *this)
{
  HRESULT result; // eax
  unsigned int streamPos; // eax
  unsigned int pos; // ecx
  bool v5; // cf
  unsigned int v6; // edi
  unsigned __int8 *buffer2; // eax
  HRESULT ErrorCode; // ebx
  ISequentialOutStream *p; // eax
  unsigned __int8 *v10; // ecx
  int v11; // eax
  unsigned int bufferSize; // edx
  unsigned int v13; // [esp+4h] [ebp-4h] BYREF

  result = this->ErrorCode;
  if ( result == 0 )
  {
    streamPos = this->_streamPos;
    pos = this->_pos;
    v5 = streamPos < pos;
    if ( streamPos == pos )
    {
      return 0;
    }
    else
    {
      while ( 1 )
      {
        if ( v5 )
          v6 = pos - streamPos;
        else
          v6 = this->_bufferSize - streamPos;
        buffer2 = this->_buffer2;
        ErrorCode = this->ErrorCode;
        if ( buffer2 != nullptr )
        {
          memmove(dst: buffer2, src: &this->_buffer[this->_streamPos], count: v6);
          this->_buffer2 += v6;
        }
        p = this->_stream._p;
        if ( p != nullptr && this->ErrorCode == 0 )
        {
          v10 = &this->_buffer[this->_streamPos];
          v13 = 0;
          v11 = p->Write(this: p, a2: v10, a3: v6, a4: &v13);
          v6 = v13;
          ErrorCode = v11;
        }
        bufferSize = this->_bufferSize;
        this->_streamPos += v6;
        if ( this->_streamPos == bufferSize )
          this->_streamPos = 0;
        if ( this->_pos == bufferSize )
        {
          this->_overDict = true;
          this->_pos = 0;
        }
        streamPos = this->_streamPos;
        pos = this->_pos;
        if ( streamPos > pos )
          bufferSize = this->_streamPos;
        v5 = __CFADD__(v6, this->_processedSize);
        LODWORD(this->_processedSize) += v6;
        this->_limitPos = bufferSize;
        HIDWORD(this->_processedSize) += v5;
        if ( ErrorCode != 0 )
          break;
        v5 = streamPos < pos;
        if ( streamPos == pos )
          return 0;
      }
      return ErrorCode;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BCA20
// Name: protected: void COutBuffer::FlushWithCheck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COutBuffer::FlushWithCheck(COutBuffer *this)
{
  this->ErrorCode = COutBuffer::FlushPart(this);
}

} // namespace hlfaceposer

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00526330
// Name: public: void COutBuffer::Free(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COutBuffer::Free(COutBuffer *this)
{
  MidFree(address: this->_buffer);
  this->_buffer = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00526350
// Name: public: void COutBuffer::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COutBuffer::Init(COutBuffer *this)
{
  unsigned int bufferSize; // edx

  bufferSize = this->_bufferSize;
  this->_streamPos = 0;
  this->_limitPos = bufferSize;
  this->_pos = 0;
  this->_processedSize = 0;
  this->_overDict = false;
  this->ErrorCode = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00526370
// Name: public: unsigned __int64 COutBuffer::GetProcessedSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall COutBuffer::GetProcessedSize(COutBuffer *this)
{
  unsigned int streamPos; // esi
  unsigned int pos; // edi
  unsigned __int64 result; // rax

  streamPos = this->_streamPos;
  pos = this->_pos;
  result = pos + this->_processedSize - streamPos;
  if ( streamPos > pos )
    result += this->_bufferSize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005263A0
// Name: public: bool COutBuffer::Create(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall COutBuffer::Create(COutBuffer *this, unsigned int bufferSize)
{
  unsigned int v2; // edi
  unsigned __int8 *v5; // eax

  v2 = bufferSize;
  if ( bufferSize == 0 )
    v2 = 1;
  if ( this->_buffer != nullptr && this->_bufferSize == v2 )
    return true;
  MidFree(address: this->_buffer);
  this->_buffer = nullptr;
  this->_bufferSize = v2;
  v5 = (unsigned __int8 *)MidAlloc(size: v2);
  this->_buffer = v5;
  return v5 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005263F0
// Name: public: void COutBuffer::SetStream(struct ISequentialOutStream __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COutBuffer::SetStream(COutBuffer *this, ISequentialOutStream *stream)
{
  ISequentialOutStream *p; // eax

  if ( stream != nullptr )
    stream->AddRef(a1: stream);
  p = this->_stream._p;
  if ( p != nullptr )
    p->Release(a1: this->_stream._p);
  this->_stream._p = stream;
}

//------------------------------------------------------------------------------
// Address: 0x00526420
// Name: protected: long COutBuffer::FlushPart(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall COutBuffer::FlushPart(COutBuffer *this)
{
  unsigned int streamPos; // eax
  unsigned int pos; // edi
  HRESULT ErrorCode; // ebx
  unsigned int v5; // edi
  unsigned __int8 *buffer2; // eax
  ISequentialOutStream *p; // eax
  unsigned __int8 *v8; // ecx
  int v9; // eax
  unsigned int bufferSize; // eax
  bool v11; // cf
  unsigned int processedSize; // [esp+Ch] [ebp-4h] BYREF

  streamPos = this->_streamPos;
  pos = this->_pos;
  if ( streamPos >= pos )
    pos = this->_bufferSize;
  ErrorCode = this->ErrorCode;
  v5 = pos - streamPos;
  buffer2 = this->_buffer2;
  if ( buffer2 != nullptr )
  {
    memmove(dst: buffer2, src: &this->_buffer[this->_streamPos], count: v5);
    this->_buffer2 += v5;
  }
  p = this->_stream._p;
  if ( p != nullptr && this->ErrorCode == 0 )
  {
    v8 = &this->_buffer[this->_streamPos];
    processedSize = 0;
    v9 = p->Write(this: p, a2: v8, a3: v5, a4: &processedSize);
    v5 = processedSize;
    ErrorCode = v9;
  }
  bufferSize = this->_bufferSize;
  this->_streamPos += v5;
  if ( this->_streamPos == bufferSize )
    this->_streamPos = 0;
  if ( this->_pos == bufferSize )
  {
    this->_overDict = true;
    this->_pos = 0;
  }
  if ( this->_streamPos > this->_pos )
    bufferSize = this->_streamPos;
  v11 = __CFADD__(v5, this->_processedSize);
  LODWORD(this->_processedSize) += v5;
  this->_limitPos = bufferSize;
  HIDWORD(this->_processedSize) += v11;
  return ErrorCode;
}

//------------------------------------------------------------------------------
// Address: 0x005264C0
// Name: public: long COutBuffer::Flush(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall COutBuffer::Flush(COutBuffer *this)
{
  HRESULT result; // eax
  unsigned int streamPos; // eax
  unsigned int pos; // ecx
  bool v5; // cf
  unsigned int v6; // edi
  unsigned __int8 *buffer2; // eax
  HRESULT ErrorCode; // ebx
  ISequentialOutStream *p; // eax
  unsigned __int8 *v10; // ecx
  int v11; // eax
  unsigned int bufferSize; // edx
  unsigned int v13; // [esp+4h] [ebp-4h] BYREF

  result = this->ErrorCode;
  if ( result == 0 )
  {
    streamPos = this->_streamPos;
    pos = this->_pos;
    v5 = streamPos < pos;
    if ( streamPos == pos )
    {
      return 0;
    }
    else
    {
      while ( 1 )
      {
        if ( v5 )
          v6 = pos - streamPos;
        else
          v6 = this->_bufferSize - streamPos;
        buffer2 = this->_buffer2;
        ErrorCode = this->ErrorCode;
        if ( buffer2 != nullptr )
        {
          memmove(dst: buffer2, src: &this->_buffer[this->_streamPos], count: v6);
          this->_buffer2 += v6;
        }
        p = this->_stream._p;
        if ( p != nullptr && this->ErrorCode == 0 )
        {
          v10 = &this->_buffer[this->_streamPos];
          v13 = 0;
          v11 = p->Write(this: p, a2: v10, a3: v6, a4: &v13);
          v6 = v13;
          ErrorCode = v11;
        }
        bufferSize = this->_bufferSize;
        this->_streamPos += v6;
        if ( this->_streamPos == bufferSize )
          this->_streamPos = 0;
        if ( this->_pos == bufferSize )
        {
          this->_overDict = true;
          this->_pos = 0;
        }
        streamPos = this->_streamPos;
        pos = this->_pos;
        if ( streamPos > pos )
          bufferSize = this->_streamPos;
        v5 = __CFADD__(v6, this->_processedSize);
        LODWORD(this->_processedSize) += v6;
        this->_limitPos = bufferSize;
        HIDWORD(this->_processedSize) += v5;
        if ( ErrorCode != 0 )
          break;
        v5 = streamPos < pos;
        if ( streamPos == pos )
          return 0;
      }
      return ErrorCode;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00526590
// Name: protected: void COutBuffer::FlushWithCheck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COutBuffer::FlushWithCheck(COutBuffer *this)
{
  this->ErrorCode = COutBuffer::FlushPart(this);
}

} // namespace makegamedata

// ============================================================
// Overlay from shadercompile_dll (Missing functions)
// ============================================================
namespace shadercompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10017860
// Name: public: void COutBuffer::Free(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COutBuffer::Free(COutBuffer *this)
{
  MidFree(address: this->_buffer);
  this->_buffer = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10017880
// Name: public: void COutBuffer::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COutBuffer::Init(COutBuffer *this)
{
  unsigned int bufferSize; // edx

  bufferSize = this->_bufferSize;
  this->_streamPos = 0;
  this->_limitPos = bufferSize;
  this->_pos = 0;
  this->_processedSize = 0;
  this->_overDict = false;
  this->ErrorCode = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100178A0
// Name: public: unsigned __int64 COutBuffer::GetProcessedSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall COutBuffer::GetProcessedSize(COutBuffer *this)
{
  unsigned int streamPos; // esi
  unsigned int pos; // edi
  unsigned __int64 result; // rax

  streamPos = this->_streamPos;
  pos = this->_pos;
  result = pos + this->_processedSize - streamPos;
  if ( streamPos > pos )
    result += this->_bufferSize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100178D0
// Name: public: bool COutBuffer::Create(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall COutBuffer::Create(COutBuffer *this, unsigned int bufferSize)
{
  unsigned int v2; // edi
  unsigned __int8 *v5; // eax

  v2 = bufferSize;
  if ( bufferSize == 0 )
    v2 = 1;
  if ( this->_buffer != nullptr && this->_bufferSize == v2 )
    return true;
  MidFree(address: this->_buffer);
  this->_buffer = nullptr;
  this->_bufferSize = v2;
  v5 = (unsigned __int8 *)MidAlloc(size: v2);
  this->_buffer = v5;
  return v5 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10017920
// Name: public: void COutBuffer::SetStream(struct ISequentialOutStream __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COutBuffer::SetStream(COutBuffer *this, ISequentialOutStream *stream)
{
  ISequentialOutStream *p; // eax

  if ( stream != nullptr )
    stream->AddRef(this: stream);
  p = this->_stream._p;
  if ( p != nullptr )
    p->Release(this: this->_stream._p);
  this->_stream._p = stream;
}

//------------------------------------------------------------------------------
// Address: 0x10017950
// Name: protected: long COutBuffer::FlushPart(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall COutBuffer::FlushPart(COutBuffer *this)
{
  unsigned int streamPos; // eax
  unsigned int pos; // edi
  HRESULT ErrorCode; // ebx
  unsigned int v5; // edi
  unsigned __int8 *buffer2; // eax
  ISequentialOutStream *p; // eax
  unsigned __int8 *v8; // ecx
  int v9; // eax
  unsigned int bufferSize; // eax
  bool v11; // cf
  unsigned int processedSize; // [esp+Ch] [ebp-4h] BYREF

  streamPos = this->_streamPos;
  pos = this->_pos;
  if ( streamPos >= pos )
    pos = this->_bufferSize;
  ErrorCode = this->ErrorCode;
  v5 = pos - streamPos;
  buffer2 = this->_buffer2;
  if ( buffer2 != nullptr )
  {
    memmove(dst: buffer2, src: &this->_buffer[this->_streamPos], count: v5);
    this->_buffer2 += v5;
  }
  p = this->_stream._p;
  if ( p != nullptr && this->ErrorCode == 0 )
  {
    v8 = &this->_buffer[this->_streamPos];
    processedSize = 0;
    v9 = p->Write(this: p, a2: v8, a3: v5, a4: &processedSize);
    v5 = processedSize;
    ErrorCode = v9;
  }
  bufferSize = this->_bufferSize;
  this->_streamPos += v5;
  if ( this->_streamPos == bufferSize )
    this->_streamPos = 0;
  if ( this->_pos == bufferSize )
  {
    this->_overDict = true;
    this->_pos = 0;
  }
  if ( this->_streamPos > this->_pos )
    bufferSize = this->_streamPos;
  v11 = __CFADD__(v5, this->_processedSize);
  LODWORD(this->_processedSize) += v5;
  this->_limitPos = bufferSize;
  HIDWORD(this->_processedSize) += v11;
  return ErrorCode;
}

//------------------------------------------------------------------------------
// Address: 0x100179F0
// Name: public: long COutBuffer::Flush(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall COutBuffer::Flush(COutBuffer *this)
{
  HRESULT result; // eax
  unsigned int streamPos; // eax
  unsigned int pos; // ecx
  bool v5; // cf
  unsigned int v6; // edi
  unsigned __int8 *buffer2; // eax
  HRESULT ErrorCode; // ebx
  ISequentialOutStream *p; // eax
  unsigned __int8 *v10; // ecx
  int v11; // eax
  unsigned int bufferSize; // edx
  unsigned int v13; // [esp+4h] [ebp-4h] BYREF

  result = this->ErrorCode;
  if ( result == 0 )
  {
    streamPos = this->_streamPos;
    pos = this->_pos;
    v5 = streamPos < pos;
    if ( streamPos == pos )
    {
      return 0;
    }
    else
    {
      while ( 1 )
      {
        if ( v5 )
          v6 = pos - streamPos;
        else
          v6 = this->_bufferSize - streamPos;
        buffer2 = this->_buffer2;
        ErrorCode = this->ErrorCode;
        if ( buffer2 != nullptr )
        {
          memmove(dst: buffer2, src: &this->_buffer[this->_streamPos], count: v6);
          this->_buffer2 += v6;
        }
        p = this->_stream._p;
        if ( p != nullptr && this->ErrorCode == 0 )
        {
          v10 = &this->_buffer[this->_streamPos];
          v13 = 0;
          v11 = p->Write(this: p, a2: v10, a3: v6, a4: &v13);
          v6 = v13;
          ErrorCode = v11;
        }
        bufferSize = this->_bufferSize;
        this->_streamPos += v6;
        if ( this->_streamPos == bufferSize )
          this->_streamPos = 0;
        if ( this->_pos == bufferSize )
        {
          this->_overDict = true;
          this->_pos = 0;
        }
        streamPos = this->_streamPos;
        pos = this->_pos;
        if ( streamPos > pos )
          bufferSize = this->_streamPos;
        v5 = __CFADD__(v6, this->_processedSize);
        LODWORD(this->_processedSize) += v6;
        this->_limitPos = bufferSize;
        HIDWORD(this->_processedSize) += v5;
        if ( ErrorCode != 0 )
          break;
        v5 = streamPos < pos;
        if ( streamPos == pos )
          return 0;
      }
      return ErrorCode;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017AC0
// Name: protected: void COutBuffer::FlushWithCheck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COutBuffer::FlushWithCheck(COutBuffer *this)
{
  this->ErrorCode = COutBuffer::FlushPart(this);
}

} // namespace shadercompile_dll
