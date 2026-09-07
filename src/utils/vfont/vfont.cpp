// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vfont/vfont.cpp
// Functions: 4
// ============================================================

#include "utils\vfont\vfont.h"

//------------------------------------------------------------------------------
// Address: 0x004010C0
// Name: void SimpleCodec::EncodeBuffer(unsigned char __near *,int,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SimpleCodec::EncodeBuffer(unsigned __int8 *pvBuffer, int numBytes, unsigned __int8 numSultBytes)
{
  int v3; // ecx
  unsigned __int8 *v4; // esi
  char v5; // bl
  unsigned __int8 *v6; // edi
  int v7; // eax
  unsigned __int8 v8; // dl
  unsigned __int8 xx; // [esp+Fh] [ebp-1h]

  v3 = numBytes;
  v4 = pvBuffer;
  pvBuffer[numSultBytes - 1 + numBytes] = numSultBytes;
  v5 = numSultBytes - 1;
  xx = -89;
  v6 = &pvBuffer[numBytes];
  if ( numSultBytes != 1 )
  {
    do
    {
      --v5;
      v7 = rand() % 256;
      *v6 = v7;
      xx ^= (_BYTE)v7 - 89;
      ++v6;
    }
    while ( v5 != 0 );
    v3 = numBytes;
  }
  for ( ; v3 > 0; xx = v8 )
  {
    --v3;
    v8 = (xx ^ *v4) - 89;
    *v4++ ^= xx;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401160
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401190
// Name: void ValveFont::EncodeFont(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ValveFont::EncodeFont(CUtlBuffer *buffer)
{
  unsigned int v1; // eax
  int v3; // edi
  int i; // ebx
  unsigned __int8 v5; // bl
  int numBytes; // [esp+Ch] [ebp-4h]
  int k; // [esp+18h] [ebp+8h]

  v1 = _time64(timeptr: nullptr);
  srand(seed: v1);
  numBytes = buffer->m_Put;
  v3 = rand() % 16 + 16;
  for ( i = 0; i < v3; ++i )
  {
    if ( (buffer->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: buffer, pFmt: "%hu", (unsigned __int8)i);
    }
    else if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
    {
      buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = i;
      CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
    }
  }
  for ( k = 0; k < 6; ++k )
  {
    v5 = aVfont1[k];
    if ( (buffer->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: buffer, pFmt: "%hu", v5);
    }
    else if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
    {
      buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = v5;
      CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
    }
  }
  SimpleCodec::EncodeBuffer(pvBuffer: buffer->m_Memory.m_pMemory, numBytes, numSultBytes: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00401290
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  const char *v4; // ebx
  char *v5; // eax
  char *v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // eax
  char *v10; // eax
  char *v11; // edx
  char v12; // cl
  _iobuf *v13; // eax
  _iobuf *v14; // esi
  int v15; // edi
  _iobuf *v16; // esi
  char szOutput[512]; // [esp+4h] [ebp-230h] BYREF
  CUtlBuffer buf; // [esp+204h] [ebp-30h] BYREF
  int numBytes; // [esp+23Ch] [ebp+8h]

  printf(format: "Valve Software - vfont.exe (Jul 15 2011)\n");
  if ( argc > 1 )
  {
    v4 = argv[1];
    memset(szOutput, 0, sizeof(szOutput));
    if ( argc > 2 )
    {
      v10 = (char *)argv[2];
      v11 = (char *)(szOutput - v10);
      do
      {
        v12 = *v10;
        v10[(_DWORD)v11] = *v10;
        ++v10;
      }
      while ( v12 != 0 );
    }
    else
    {
      numBytes = strlen(v4);
      strcpy(szOutput, v4);
      strrchr(string: (unsigned __int8 *)szOutput, chr: 0x2Eu);
      v6 = v5;
      strrchr(string: (unsigned __int8 *)szOutput, chr: 0x2Fu);
      v8 = v7;
      strrchr(string: (unsigned __int8 *)szOutput, chr: 0x5Cu);
      if ( v6 == nullptr || (unsigned int)v6 < v8 || (unsigned int)v6 < v9 )
        v6 = &szOutput[numBytes];
      sprintf(string: v6, format: ".vfont");
    }
    v13 = fopen(file: v4, mode: "rb");
    v14 = v13;
    if ( v13 != nullptr )
    {
      fseek(stream: v13, offset: 0, whence: 2);
      v15 = ftell(stream: v14);
      fseek(stream: v14, offset: 0, whence: 0);
      CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
      CUtlBuffer::EnsureCapacity(this: &buf, num: v15);
      fread(buffer: buf.m_Memory.m_pMemory, elementSize: 1u, count: v15, stream: v14);
      CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v15);
      fclose(stream: v14);
      ValveFont::EncodeFont(buffer: &buf);
      v16 = fopen(file: szOutput, mode: "wb");
      if ( v16 != nullptr )
      {
        fwrite(buffer: buf.m_Memory.m_pMemory, size: 1u, count: buf.m_Put, stream: v16);
        fclose(stream: v16);
        printf(format: "vfont successfully %scompiled '%s' as '%s'.\n", byte_40F1E1, v4, szOutput);
        CUtlBuffer::~CUtlBuffer(this: &buf);
        return 0;
      }
      else
      {
        printf(format: "Error: cannot open output file '%s'!\n", szOutput);
        CUtlBuffer::~CUtlBuffer(this: &buf);
        return -3;
      }
    }
    else
    {
      printf(format: "Error: cannot open input file '%s'!\n", v4);
      return -2;
    }
  }
  else
  {
    printf(format: "Usage:   vfont inputfont.ttf [outputfont.vfont]\n");
    return -1;
  }
}
