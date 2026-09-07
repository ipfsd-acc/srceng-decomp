// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vfont/vfont_decompiler.cpp
// Functions: 5
// ============================================================

#include "utils\vfont\vfont_decompiler.h"

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
// Name: bool ValveFont::DecodeFont(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ValveFont::DecodeFont(CUtlBuffer *buffer)
{
  int m_Put; // edi
  unsigned __int8 *m_pMemory; // eax
  unsigned int v4; // ecx
  const char *v5; // edx
  unsigned __int8 *v6; // esi
  unsigned __int8 v7; // cl
  int v8; // edi
  char v9; // cl
  char v10; // bl
  unsigned __int8 *i; // esi
  int j; // esi
  unsigned __int8 v13; // dl

  m_Put = buffer->m_Put;
  if ( m_Put <= 6 )
    return 0;
  m_pMemory = buffer->m_Memory.m_pMemory;
  v4 = 6;
  v5 = "VFONT1";
  v6 = &buffer->m_Memory.m_pMemory[m_Put - 6];
  do
  {
    if ( *(_DWORD *)v6 != *(_DWORD *)v5 )
      return 0;
    v4 -= 4;
    v5 += 4;
    v6 += 4;
  }
  while ( v4 >= 4 );
  if ( v4 != 0 && (*v5 != *v6 || v4 > 1 && (v5[1] != v6[1] || v4 > 2 && v5[2] != v6[2])) )
    return 0;
  v7 = m_pMemory[m_Put - 7];
  v8 = m_Put - 6 - v7;
  v9 = v7 - 1;
  v10 = -89;
  for ( i = &m_pMemory[v8]; v9 != 0; ++i )
  {
    --v9;
    v10 ^= *i - 89;
  }
  for ( j = v8; j > 0; ++m_pMemory )
  {
    v13 = v10 ^ *m_pMemory;
    --j;
    v10 = *m_pMemory - 89;
    *m_pMemory = v13;
  }
  CUtlBuffer::SeekPut(this: buffer, type: SEEK_HEAD, offset: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401250
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
// Address: 0x00401280
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
// Address: 0x00401380
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v4; // esi
  int v6; // eax
  int v7; // esi
  const char *v8; // edi
  const char *v9; // eax
  int v10; // edx
  char v11; // cl
  char *v12; // eax
  char *v13; // esi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  char *v17; // eax
  char *v18; // edx
  char v19; // cl
  _iobuf *v20; // eax
  _iobuf *v21; // esi
  int v22; // edi
  _iobuf *v23; // esi
  const char *v24; // eax
  char szOutput[512]; // [esp+8h] [ebp-238h] BYREF
  CUtlBuffer buf; // [esp+208h] [ebp-38h] BYREF
  int numBytes; // [esp+238h] [ebp-8h]
  const char *szInput; // [esp+23Ch] [ebp-4h]
  bool bDecompiler_3; // [esp+24Bh] [ebp+Bh]

  printf(format: "Valve Software - vfont.exe (Jul 15 2011)\n");
  v4 = 1;
  if ( argc <= 1 )
  {
    printf(format: "Usage:   vfont inputfont.ttf [outputfont.vfont]\n");
    return -1;
  }
  v6 = _V_stricmp(s1: argv[1], s2: "-d");
  bDecompiler_3 = v6 == 0;
  if ( v6 == 0 )
    v4 = 2;
  if ( v4 >= argc )
  {
    printf(format: "Usage:   vfont inputfont.ttf [outputfont.vfont]\n");
    return -1;
  }
  szInput = argv[v4];
  v7 = v4 + 1;
  memset(szOutput, 0, sizeof(szOutput));
  if ( v7 < argc )
  {
    v17 = (char *)argv[v7];
    v18 = (char *)(szOutput - v17);
    do
    {
      v19 = *v17;
      v17[(_DWORD)v18] = *v17;
      ++v17;
    }
    while ( v19 != 0 );
    v8 = szInput;
  }
  else
  {
    v8 = szInput;
    numBytes = strlen(szInput);
    v9 = szInput;
    v10 = szOutput - szInput;
    do
    {
      v11 = *v9;
      v9[v10] = *v9;
      ++v9;
    }
    while ( v11 != 0 );
    strrchr(string: (unsigned __int8 *)szOutput, chr: 0x2Eu);
    v13 = v12;
    strrchr(string: (unsigned __int8 *)szOutput, chr: 0x2Fu);
    v15 = v14;
    strrchr(string: (unsigned __int8 *)szOutput, chr: 0x5Cu);
    if ( v13 == nullptr || (unsigned int)v13 < v15 || (unsigned int)v13 < v16 )
      v13 = &szOutput[numBytes];
    sprintf(string: v13, format: ".vfont");
  }
  v20 = fopen(file: v8, mode: "rb");
  v21 = v20;
  if ( v20 == nullptr )
  {
    printf(format: "Error: cannot open input file '%s'!\n", v8);
    return -2;
  }
  fseek(stream: v20, offset: 0, whence: 2);
  v22 = ftell(stream: v21);
  fseek(stream: v21, offset: 0, whence: 0);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::EnsureCapacity(this: &buf, num: v22);
  fread(buffer: buf.m_Memory.m_pMemory, elementSize: 1u, count: v22, stream: v21);
  CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v22);
  fclose(stream: v21);
  if ( bDecompiler_3 )
  {
    if ( ValveFont::DecodeFont(buffer: &buf) == 0 )
    {
      printf(format: "Error: cannot decompile input file '%s'!\n", szInput);
      CUtlBuffer::~CUtlBuffer(this: &buf);
      return 1;
    }
  }
  else
  {
    ValveFont::EncodeFont(buffer: &buf);
  }
  v23 = fopen(file: szOutput, mode: "wb");
  if ( v23 != nullptr )
  {
    fwrite(buffer: buf.m_Memory.m_pMemory, size: 1u, count: buf.m_Put, stream: v23);
    fclose(stream: v23);
    v24 = "de";
    if ( !bDecompiler_3 )
      v24 = (const char *)&unk_40F1ED;
    printf(format: "vfont successfully %scompiled '%s' as '%s'.\n", v24, szInput, szOutput);
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
