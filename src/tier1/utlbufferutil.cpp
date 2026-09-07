// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/utlbufferutil.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10278CF0
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x10278D00
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x10278D10
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pDest[8]; // [esp+0h] [ebp-100h] BYREF

  v2 = V_snprintf(pDest, maxLen: 0x100u, pFormat: "%.10f", a1);
  if ( v2 > 0 )
  {
    while ( pDest[v2 - 1] == 48 )
    {
      pDest[--v2] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pDest[v2 - 1] == 46;
    v4 = &pDest[v2 - 1];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: pDest);
}

//------------------------------------------------------------------------------
// Address: 0x10278EA0
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10279600
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

// ============================================================
// Overlay from dmxconvert (Missing functions)
// ============================================================
namespace dmxconvert {

//------------------------------------------------------------------------------
// Address: 0x00464670
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x00464680
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x00464690
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pTemp[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = V_snprintf(pDest: pTemp, maxLen: 0x100u, pFormat: "%.10f", a1);
  if ( v2 > 0 )
  {
    while ( pTemp[v2 - 1] == 48 )
    {
      pTemp[--v2] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pTemp[v2 - 1] == 46;
    v4 = &pTemp[v2 - 1];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: pTemp);
}

//------------------------------------------------------------------------------
// Address: 0x00464820
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00464F80
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace dmxconvert

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x005718B0
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x005718C0
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x005718D0
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pTemp[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = V_snprintf(pDest: pTemp, maxLen: 0x100u, pFormat: "%.10f", a1);
  if ( v2 > 0 )
  {
    while ( pTemp[v2 - 1] == 48 )
    {
      pTemp[--v2] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pTemp[v2 - 1] == 46;
    v4 = &pTemp[v2 - 1];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: pTemp);
}

//------------------------------------------------------------------------------
// Address: 0x00571A60
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005721C0
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005D45B0
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x005D45C0
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x005D45D0
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pTemp[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = V_snprintf(pDest: pTemp, maxLen: 0x100u, pFormat: "%.10f", a1);
  if ( v2 > 0 )
  {
    while ( pTemp[v2 - 1] == 48 )
    {
      pTemp[--v2] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pTemp[v2 - 1] == 46;
    v4 = &pTemp[v2 - 1];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: pTemp);
}

//------------------------------------------------------------------------------
// Address: 0x005D4760
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D4EC0
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10278E20
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x10278E30
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x10278E40
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pDest[8]; // [esp+0h] [ebp-100h] BYREF

  v2 = V_snprintf(pDest, maxLen: 256, pFormat: "%.10f", a1);
  if ( v2 > 0 )
  {
    while ( pDest[v2 - 1] == 48 )
    {
      pDest[--v2] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pDest[v2 - 1] == 46;
    v4 = &pDest[v2 - 1];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: pDest);
}

//------------------------------------------------------------------------------
// Address: 0x10278FD0
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10279730
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102B4EB0
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x102B4EC0
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x102B4ED0
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pDest[8]; // [esp+0h] [ebp-100h] BYREF

  v2 = V_snprintf(pDest, maxLen: 0x100u, pFormat: "%.10f", a1);
  if ( v2 > 0 )
  {
    while ( pDest[v2 - 1] == 48 )
    {
      pDest[--v2] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pDest[v2 - 1] == 46;
    v4 = &pDest[v2 - 1];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: pDest);
}

//------------------------------------------------------------------------------
// Address: 0x102B5060
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B57C0
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00579200
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x00579210
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x00579220
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pTemp[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = V_snprintf(pDest: pTemp, maxLen: 0x100u, pFormat: "%.10f", a1);
  if ( v2 > 0 )
  {
    while ( pTemp[v2 - 1] == 48 )
    {
      pTemp[--v2] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pTemp[v2 - 1] == 46;
    v4 = &pTemp[v2 - 1];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: pTemp);
}

//------------------------------------------------------------------------------
// Address: 0x005793B0
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00579B10
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00531BD0
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x00531BE0
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x00531BF0
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pTemp[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = V_snprintf(pDest: pTemp, maxLen: 0x100u, pFormat: "%.10f", a1);
  if ( v2 > 0 )
  {
    while ( pTemp[v2 - 1] == 48 )
    {
      pTemp[--v2] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pTemp[v2 - 1] == 46;
    v4 = &pTemp[v2 - 1];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: pTemp);
}

//------------------------------------------------------------------------------
// Address: 0x00531D80
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005324E0
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005C5F50
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x005C5F60
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x005C5F70
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pTemp[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = V_snprintf(pDest: pTemp, maxLen: 0x100u, pFormat: "%.10f", a1);
  if ( v2 > 0 )
  {
    while ( pTemp[v2 - 1] == 48 )
    {
      pTemp[--v2] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pTemp[v2 - 1] == 46;
    v4 = &pTemp[v2 - 1];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: pTemp);
}

//------------------------------------------------------------------------------
// Address: 0x005C6100
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C6860
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x00497050
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x00497060
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x00497070
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pTemp[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = V_snprintf(pDest: pTemp, maxLen: 0x100u, pFormat: "%.10f", a1);
  if ( v2 > 0 )
  {
    while ( pTemp[v2 - 1] == 48 )
    {
      pTemp[--v2] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pTemp[v2 - 1] == 46;
    v4 = &pTemp[v2 - 1];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: pTemp);
}

//------------------------------------------------------------------------------
// Address: 0x00497200
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00497960
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace mksheet

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x004B6020
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x004B6460
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace modelbrowser

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x005389E0
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x005389F0
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x00538A00
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pTemp[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = V_snprintf(pDest: pTemp, maxLen: 0x100u, pFormat: "%.10f", a1);
  if ( v2 > 0 )
  {
    while ( pTemp[v2 - 1] == 48 )
    {
      pTemp[--v2] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pTemp[v2 - 1] == 46;
    v4 = &pTemp[v2 - 1];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: pTemp);
}

//------------------------------------------------------------------------------
// Address: 0x00538BC0
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00539320
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x00447150
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x00447160
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x00447170
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __cdecl SerializeFloat(CUtlBuffer *buf, float f)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pTemp[260]; // [esp+4h] [ebp-104h] BYREF

  v2 = V_snprintf(pDest: &pTemp[4], maxLen: 0x100u, pFormat: "%.10f", f);
  if ( v2 > 0 )
  {
    while ( pTemp[v2 + 3] == 48 )
    {
      pTemp[--v2 + 4] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pTemp[v2 + 3] == 46;
    v4 = &pTemp[v2 + 3];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: &pTemp[4]);
}

//------------------------------------------------------------------------------
// Address: 0x004472F0
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(buf, f: pFloats[i]);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447D10
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int *v2; // ebp
  int i; // edi
  int m_Get; // eax
  char v5; // bl
  int v6; // eax
  char v7; // cl
  bool v8; // dl
  bool v9; // bl
  bool v10; // al
  int nStartGet; // [esp+8h] [ebp-8h] BYREF
  int offset; // [esp+Ch] [ebp-4h]

  v2 = pEndGet;
  offset = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *v2 = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( (buf->m_Flags & 1) != 0 )
    {
      LOBYTE(pEndGet) = 0;
      CUtlBuffer::Scanf(this: buf, pFmt: "%c", &pEndGet);
      v5 = (char)pEndGet;
    }
    else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      m_Get = buf->m_Get;
      v5 = buf->m_Memory.m_pMemory[m_Get - buf->m_nOffset];
      LOBYTE(pEndGet) = v5;
      buf->m_Get = m_Get + 1;
    }
    else
    {
      v5 = 0;
      LOBYTE(pEndGet) = 0;
    }
    if ( (buf->m_Flags & 1) != 0 )
    {
      BYTE2(nStartGet) = 0;
      CUtlBuffer::Scanf(this: buf, pFmt: "%c", (char *)&nStartGet + 2);
      v7 = BYTE2(nStartGet);
    }
    else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v6 = buf->m_Get;
      v7 = buf->m_Memory.m_pMemory[v6 - buf->m_nOffset];
      BYTE2(nStartGet) = v7;
      buf->m_Get = v6 + 1;
    }
    else
    {
      v7 = 0;
      BYTE2(nStartGet) = 0;
    }
    if ( v5 < 48 || (HIBYTE(nStartGet) = 1, v5 > 57) )
      HIBYTE(nStartGet) = 0;
    v8 = v7 >= 48 && v7 <= 57;
    v9 = v5 >= 65 && v5 <= 70 || v5 >= 97 && v5 <= 102;
    v10 = v7 >= 65 && v7 <= 70 || v7 >= 97 && v7 <= 102;
    if ( HIBYTE(nStartGet) == 0 && !v9 )
      break;
    if ( !v8 && !v10 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *v2 = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset);
  return i;
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x004669F0
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x00466A00
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x00466A10
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pTemp[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = V_snprintf(pDest: pTemp, maxLen: 0x100u, pFormat: "%.10f", a1);
  if ( v2 > 0 )
  {
    while ( pTemp[v2 - 1] == 48 )
    {
      pTemp[--v2] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pTemp[v2 - 1] == 46;
    v4 = &pTemp[v2 - 1];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: pTemp);
}

//------------------------------------------------------------------------------
// Address: 0x00466BA0
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467300
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0054CF90
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x0054CFA0
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x0054CFB0
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pTemp[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = V_snprintf(pDest: pTemp, maxLen: 0x100u, pFormat: "%.10f", a1);
  if ( v2 > 0 )
  {
    while ( pTemp[v2 - 1] == 48 )
    {
      pTemp[--v2] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pTemp[v2 - 1] == 46;
    v4 = &pTemp[v2 - 1];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: pTemp);
}

//------------------------------------------------------------------------------
// Address: 0x0054D140
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054D8A0
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00600F50
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x00600F60
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x00600F70
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pTemp[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = V_snprintf(pDest: pTemp, maxLen: 0x100u, pFormat: "%.10f", a1);
  if ( v2 > 0 )
  {
    while ( pTemp[v2 - 1] == 48 )
    {
      pTemp[--v2] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pTemp[v2 - 1] == 46;
    v4 = &pTemp[v2 - 1];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: pTemp);
}

//------------------------------------------------------------------------------
// Address: 0x00601100
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00601860
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0054ED20
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x0054ED30
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x0054ED40
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pTemp[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = V_snprintf(pDest: pTemp, maxLen: 0x100u, pFormat: "%.10f", a1);
  if ( v2 > 0 )
  {
    while ( pTemp[v2 - 1] == 48 )
    {
      pTemp[--v2] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pTemp[v2 - 1] == 46;
    v4 = &pTemp[v2 - 1];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: pTemp);
}

//------------------------------------------------------------------------------
// Address: 0x0054EED0
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054F630
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005BEE00
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x005BEE10
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x005BEE20
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pTemp[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = V_snprintf(pDest: pTemp, maxLen: 0x100u, pFormat: "%.10f", a1);
  if ( v2 > 0 )
  {
    while ( pTemp[v2 - 1] == 48 )
    {
      pTemp[--v2] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pTemp[v2 - 1] == 46;
    v4 = &pTemp[v2 - 1];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: pTemp);
}

//------------------------------------------------------------------------------
// Address: 0x005BEFB0
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005BF710
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00545440
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x00545450
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x00545460
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pTemp[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = V_snprintf(pDest: pTemp, maxLen: 0x100u, pFormat: "%.10f", a1);
  if ( v2 > 0 )
  {
    while ( pTemp[v2 - 1] == 48 )
    {
      pTemp[--v2] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pTemp[v2 - 1] == 46;
    v4 = &pTemp[v2 - 1];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: pTemp);
}

//------------------------------------------------------------------------------
// Address: 0x005455F0
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00545D50
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace uvlightmap

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00531060
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x00531070
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x00531080
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  _BYTE *v4; // eax
  _BYTE v5[9]; // [esp+0h] [ebp-108h] OVERLAPPED BYREF

  *(double *)v5 = a1;
  v2 = V_snprintf(pDest: &v5[8], maxLen: 0x100u, pFormat: "%.10f", *(double *)v5);
  if ( v2 > 0 )
  {
    while ( v5[v2 + 7] == 48 )
    {
      v5[--v2 + 8] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = v5[v2 + 7] == 46;
    v4 = &v5[v2 + 7];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: &v5[8]);
}

//------------------------------------------------------------------------------
// Address: 0x00531230
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005319C0
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v4; // bl
  char v5; // cl
  bool v6; // dl
  bool v7; // bl
  bool v8; // al
  int offset; // [esp+8h] [ebp-4h]
  char bIsNum1; // [esp+10h] [ebp+4h]

  offset = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v5 = 0;
    }
    if ( v4 < 48 || (bIsNum1 = 1, v4 > 57) )
      bIsNum1 = 0;
    v6 = v5 >= 48 && v5 <= 57;
    v7 = v4 >= 65 && v4 <= 70 || v4 >= 97 && v4 <= 102;
    v8 = v5 >= 65 && v5 <= 70 || v5 >= 97 && v5 <= 102;
    if ( bIsNum1 == 0 && !v7 )
      break;
    if ( !v6 && !v8 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset);
  return i;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0064C720
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x0064C730
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x0064C740
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pTemp[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = V_snprintf(pDest: pTemp, maxLen: 0x100u, pFormat: "%.10f", a1);
  if ( v2 > 0 )
  {
    while ( pTemp[v2 - 1] == 48 )
    {
      pTemp[--v2] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pTemp[v2 - 1] == 46;
    v4 = &pTemp[v2 - 1];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: pTemp);
}

//------------------------------------------------------------------------------
// Address: 0x0064C8D0
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0064D030
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x1009F440
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x1009F450
// Name: void SetSerializationArrayDelimiter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationArrayDelimiter(const char *pDelimiter)
{
  s_pUtlBufferUtilArrayDelim = pDelimiter;
}

//------------------------------------------------------------------------------
// Address: 0x1009F460
// Name: SerializeFloat
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloat(float a1@<xmm0>, CUtlBuffer *buf)
{
  int v2; // eax
  bool v3; // zf
  char *v4; // eax
  char pTemp[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = V_snprintf(pDest: pTemp, maxLen: 0x100u, pFormat: "%.10f", a1);
  if ( v2 > 0 )
  {
    while ( pTemp[v2 - 1] == 48 )
    {
      pTemp[--v2] = 0;
      if ( v2 <= 0 )
        goto LABEL_7;
    }
    v3 = pTemp[v2 - 1] == 46;
    v4 = &pTemp[v2 - 1];
    if ( v3 )
      *v4 = 0;
  }
LABEL_7:
  CUtlBuffer::PutString(this: buf, pString: pTemp);
}

//------------------------------------------------------------------------------
// Address: 0x1009F5F0
// Name: SerializeFloats
// Source: json
//------------------------------------------------------------------------------
void __usercall SerializeFloats(CUtlBuffer *buf@<esi>, int nCount, const float *pFloats)
{
  int i; // edi
  int m_Put; // eax

  for ( i = 0; i < nCount; ++i )
  {
    SerializeFloat(a1: pFloats[i], buf);
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 32;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009FD50
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace vtex_dll

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1040E6A0
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x1040EAE0
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103F9500
// Name: void SetSerializationDelimiter(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetSerializationDelimiter(CUtlCharConversion *pConv)
{
  s_pConv = pConv;
}

//------------------------------------------------------------------------------
// Address: 0x103F9940
// Name: CountBinaryBytes
// Source: json
//------------------------------------------------------------------------------
int __usercall CountBinaryBytes@<eax>(CUtlBuffer *buf@<esi>, int *pEndGet)
{
  int i; // edi
  char v3; // bl
  char v4; // al
  bool v5; // cl
  bool v6; // al
  int nStartGet; // [esp+4h] [ebp-8h]
  bool bIsNum2; // [esp+Bh] [ebp-1h]

  nStartGet = buf->m_Get;
  CUtlBuffer::EatWhiteSpace(this: buf);
  *pEndGet = buf->m_Get;
  for ( i = 0; buf->m_Error == 0; ++i )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v3 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v3 = 0;
    }
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
    {
      v4 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      ++buf->m_Get;
    }
    else
    {
      v4 = 0;
    }
    bIsNum2 = (unsigned __int8)(v4 - 48) <= 9u;
    v5 = v3 >= 65 && v3 <= 70 || (unsigned __int8)(v3 - 97) <= 5u;
    v6 = v4 >= 65 && v4 <= 70 || (unsigned __int8)(v4 - 97) <= 5u;
    if ( (unsigned __int8)(v3 - 48) > 9u && !v5 )
      break;
    if ( !bIsNum2 && !v6 )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    *pEndGet = buf->m_Get;
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: nStartGet);
  return i;
}

} // namespace server
