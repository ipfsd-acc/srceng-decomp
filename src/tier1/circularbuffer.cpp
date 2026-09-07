// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/circularbuffer.cpp
// Functions: 6
// ============================================================

#include "tier1\circularbuffer.h"

//------------------------------------------------------------------------------
// Address: 0x10272090
// Name: public: void CCircularBuffer::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCircularBuffer::Flush(CCircularBuffer *this)
{
  this->m_nRead = 0;
  this->m_nWrite = 0;
  this->m_nCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102720A0
// Name: public: int CCircularBuffer::Peek(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCircularBuffer::Peek(CCircularBuffer *this, char *pchDest, int nCount)
{
  int result; // eax
  int m_nRead; // ecx
  unsigned int v6; // ebx
  int m_nSize; // eax
  int v8; // edi

  result = this->m_nCount;
  if ( this->m_nCount != 0 )
  {
    m_nRead = this->m_nRead;
    v6 = nCount;
    if ( result < nCount )
      v6 = result;
    m_nSize = this->m_nSize;
    if ( (int)(m_nRead + v6) <= m_nSize )
    {
      memcpy(dst: (unsigned __int8 *)pchDest, src: (unsigned __int8 *)&this->m_chData[m_nRead], count: v6);
    }
    else
    {
      v8 = m_nSize - m_nRead;
      memcpy(
        dst: (unsigned __int8 *)pchDest,
        src: (unsigned __int8 *)&this->m_chData[m_nRead],
        count: m_nSize - m_nRead);
      memcpy(dst: (unsigned __int8 *)&pchDest[v8], src: (unsigned __int8 *)this->m_chData, count: v6 - v8);
    }
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10272120
// Name: public: int CCircularBuffer::Read(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCircularBuffer::Read(CCircularBuffer *this, char *pchDestIn, int nCount)
{
  int v4; // eax
  int m_nCount; // edi
  int v7; // edx
  bool v8; // zf

  v4 = CCircularBuffer::Peek(this, pchDest: pchDestIn, nCount);
  if ( v4 == 0 )
    return 0;
  m_nCount = v4;
  if ( this->m_nCount == 0 )
    return 0;
  if ( this->m_nCount < v4 )
    m_nCount = this->m_nCount;
  v7 = (m_nCount + this->m_nRead) % this->m_nSize;
  v8 = this->m_nCount == m_nCount;
  this->m_nCount -= m_nCount;
  this->m_nRead = v7;
  if ( v8 )
  {
    this->m_nRead = 0;
    this->m_nWrite = 0;
  }
  return m_nCount;
}

//------------------------------------------------------------------------------
// Address: 0x10272180
// Name: public: int CCircularBuffer::Write(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCircularBuffer::Write(CCircularBuffer *this, unsigned __int8 *pData, int nBytesRequested)
{
  int result; // eax
  int m_nSize; // ecx
  int m_nWrite; // esi
  int v7; // ebx
  int v8; // esi
  bool v9; // zf
  int nBytesToWrite; // [esp+Ch] [ebp-4h]

  result = nBytesRequested;
  nBytesToWrite = nBytesRequested;
  if ( nBytesRequested != 0 )
  {
    m_nSize = this->m_nSize;
    do
    {
      m_nWrite = this->m_nWrite;
      v7 = m_nWrite + nBytesToWrite;
      if ( m_nWrite + nBytesToWrite >= m_nSize )
        v7 = m_nSize;
      memcpy(dst: (unsigned __int8 *)&this->m_chData[m_nWrite], src: pData, count: v7 - m_nWrite);
      pData += v7 - m_nWrite;
      m_nSize = this->m_nSize;
      v8 = m_nWrite - v7;
      v9 = v8 + nBytesToWrite == 0;
      nBytesToWrite += v8;
      this->m_nWrite = v7 % m_nSize;
    }
    while ( !v9 );
    result = nBytesRequested;
  }
  if ( result <= this->m_nSize - this->m_nCount )
  {
    this->m_nCount += result;
  }
  else
  {
    this->m_nCount = this->m_nSize;
    this->m_nRead = this->m_nWrite;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10272210
// Name: public: CCircularBuffer::CCircularBuffer(int)
// Source: json
//------------------------------------------------------------------------------
CCircularBuffer *__thiscall CCircularBuffer::CCircularBuffer(CCircularBuffer *this, int size)
{
  this->m_nSize = size;
  this->m_nRead = 0;
  this->m_nWrite = 0;
  this->m_nCount = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10273400
// Name: public: int CCircularBuffer::GetReadAvailable(void)
// Source: json
//------------------------------------------------------------------------------
netadrtype_t __thiscall CCircularBuffer::GetReadAvailable(netadr_s *this)
{
  return this->type;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100E7EA0
// Name: public: int CCircularBuffer::GetReadAvailable(void)
// Source: json
//------------------------------------------------------------------------------
netadrtype_t __thiscall CCircularBuffer::GetReadAvailable(netadr_s *this)
{
  return this->type;
}

//------------------------------------------------------------------------------
// Address: 0x10272130
// Name: public: int CCircularBuffer::Peek(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCircularBuffer::Peek(CCircularBuffer *this, char *pchDest, int nCount)
{
  int result; // eax
  int m_nRead; // ecx
  unsigned int v6; // ebx
  int m_nSize; // eax
  int v8; // edi

  result = this->m_nCount;
  if ( this->m_nCount != 0 )
  {
    m_nRead = this->m_nRead;
    v6 = nCount;
    if ( result < nCount )
      v6 = result;
    m_nSize = this->m_nSize;
    if ( (int)(m_nRead + v6) <= m_nSize )
    {
      memcpy(dst: (unsigned __int8 *)pchDest, src: (unsigned __int8 *)&this->m_chData[m_nRead], count: v6);
    }
    else
    {
      v8 = m_nSize - m_nRead;
      memcpy(
        dst: (unsigned __int8 *)pchDest,
        src: (unsigned __int8 *)&this->m_chData[m_nRead],
        count: m_nSize - m_nRead);
      memcpy(dst: (unsigned __int8 *)&pchDest[v8], src: (unsigned __int8 *)this->m_chData, count: v6 - v8);
    }
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102721B0
// Name: public: int CCircularBuffer::Read(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCircularBuffer::Read(CCircularBuffer *this, char *pchDestIn, int nCount)
{
  int v4; // eax
  int m_nCount; // edi
  int v7; // edx
  bool v8; // zf

  v4 = CCircularBuffer::Peek(this, pchDest: pchDestIn, nCount);
  if ( v4 == 0 )
    return 0;
  m_nCount = v4;
  if ( this->m_nCount == 0 )
    return 0;
  if ( this->m_nCount < v4 )
    m_nCount = this->m_nCount;
  v7 = (m_nCount + this->m_nRead) % this->m_nSize;
  v8 = this->m_nCount == m_nCount;
  this->m_nCount -= m_nCount;
  this->m_nRead = v7;
  if ( v8 )
  {
    this->m_nRead = 0;
    this->m_nWrite = 0;
  }
  return m_nCount;
}

//------------------------------------------------------------------------------
// Address: 0x102722A0
// Name: public: CCircularBuffer::CCircularBuffer(int)
// Source: json
//------------------------------------------------------------------------------
CCircularBuffer *__thiscall CCircularBuffer::CCircularBuffer(CCircularBuffer *this, int size)
{
  this->m_nSize = size;
  this->m_nRead = 0;
  this->m_nWrite = 0;
  this->m_nCount = 0;
  return this;
}

} // namespace engine_xlsp
