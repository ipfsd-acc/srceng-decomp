// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/mem_fgets.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101A4520
// Name: char __near * memfgets(unsigned char __near *,int,int __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl memfgets(unsigned __int8 *pMemFile, int fileSize, int *pFilePos, char *pBuffer, int bufferSize)
{
  int v5; // eax
  int v7; // edx
  int v8; // edi
  BOOL v9; // ecx
  int v10; // esi

  v5 = *pFilePos;
  if ( pMemFile == nullptr || pBuffer == nullptr || v5 >= fileSize )
    return nullptr;
  v7 = fileSize;
  v8 = *pFilePos;
  if ( fileSize - v5 > bufferSize - 1 )
    v7 = v5 + bufferSize - 1;
  v9 = false;
  if ( v5 >= v7 )
    return nullptr;
  do
  {
    if ( v9 )
      break;
    v9 = pMemFile[v8++] == 10;
  }
  while ( v8 < v7 );
  if ( v8 == v5 )
    return nullptr;
  v10 = v8 - v5;
  memcpy(dst: (unsigned __int8 *)pBuffer, src: &pMemFile[v5], count: v8 - v5);
  if ( v10 < bufferSize )
    pBuffer[v10] = 0;
  *pFilePos = v8;
  return pBuffer;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101A4930
// Name: char __near * memfgets(unsigned char __near *,int,int __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl memfgets(unsigned __int8 *pMemFile, int fileSize, int *pFilePos, char *pBuffer, int bufferSize)
{
  int v5; // eax
  int v7; // edx
  int v8; // edi
  BOOL v9; // ecx
  int v10; // esi

  v5 = *pFilePos;
  if ( pMemFile == nullptr || pBuffer == nullptr || v5 >= fileSize )
    return nullptr;
  v7 = fileSize;
  v8 = *pFilePos;
  if ( fileSize - v5 > bufferSize - 1 )
    v7 = v5 + bufferSize - 1;
  v9 = false;
  if ( v5 >= v7 )
    return nullptr;
  do
  {
    if ( v9 )
      break;
    v9 = pMemFile[v8++] == 10;
  }
  while ( v8 < v7 );
  if ( v8 == v5 )
    return nullptr;
  v10 = v8 - v5;
  memcpy(dst: (unsigned __int8 *)pBuffer, src: &pMemFile[v5], count: v8 - v5);
  if ( v10 < bufferSize )
    pBuffer[v10] = 0;
  *pFilePos = v8;
  return pBuffer;
}

//------------------------------------------------------------------------------
// Address: 0x101A49C0
// Name: __realloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _realloc_crt(void *ptr, unsigned int size)
{
  return _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size);
}

} // namespace engine_xlsp
