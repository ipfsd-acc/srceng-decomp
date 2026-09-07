// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/newdat/newdat.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004010C0
// Name: bool MD5_Hash_File(unsigned char __near * const,char __near *,bool,bool,unsigned int __near * const)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MD5_Hash_File(unsigned __int8 *digest, char *pszFileName, bool bUsefopen, bool bSeed, unsigned int *seed)
{
  _iobuf *v5; // esi
  signed int v6; // edi
  signed int v7; // eax
  _iobuf *v8; // eax
  int v10; // eax
  _iobuf *v11; // [esp-4h] [ebp-464h]
  unsigned __int8 chunk[1024]; // [esp+8h] [ebp-458h] BYREF
  MD5Context_t ctx; // [esp+408h] [ebp-58h] BYREF

  if ( bUsefopen )
  {
    v8 = fopen(file: pszFileName, mode: "rb");
    v5 = v8;
    if ( v8 != nullptr )
    {
      fseek(stream: v8, offset: 0, whence: 2);
      v6 = ftell(stream: v5);
      fseek(stream: v5, offset: 0, whence: 0);
      if ( v6 > 0 )
        goto LABEL_4;
LABEL_10:
      fclose(stream: v5);
    }
    return 0;
  }
  v5 = fopen(file: pszFileName, mode: "rb");
  if ( v5 == nullptr )
    return 0;
  v6 = 1;
LABEL_4:
  memset(dst: (unsigned __int8 *)&ctx, value: 0, count: sizeof(ctx));
  MD5Init(&ctx);
  if ( bSeed )
    MD5Update(&ctx, buf: (const unsigned __int8 *)seed, len: 0x10u);
  while ( 1 )
  {
    v7 = v6 <= 1024
       ? fread(buffer: chunk, elementSize: 1u, count: v6, stream: v5)
       : fread(buffer: chunk, elementSize: 1u, count: 0x400u, stream: v5);
    if ( v7 > 0 )
    {
      v6 -= v7;
      MD5Update(&ctx, buf: chunk, len: v7);
    }
    v10 = feof(stream: v5);
    v11 = v5;
    if ( v10 != 0 )
      break;
    if ( ferror(stream: v5) != 0 )
      goto LABEL_10;
    if ( v6 <= 0 )
    {
      v11 = v5;
      break;
    }
  }
  fclose(stream: v11);
  MD5Final(digest, &ctx);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401210
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  _iobuf *v4; // eax
  _iobuf *v5; // esi
  char out[512]; // [esp+0h] [ebp-410h] BYREF
  char datFile[512]; // [esp+200h] [ebp-210h] BYREF
  unsigned __int8 digest[16]; // [esp+400h] [ebp-10h] BYREF

  if ( argc >= 2 )
  {
    V_StripExtension(in: argv[1], out, outSize: 512);
    sprintf(string: datFile, format: "%s.dat", out);
    MD5_Hash_File(digest, pszFileName: (char *)argv[1], bUsefopen: true, bSeed: false, seed: nullptr);
    v4 = fopen(file: datFile, mode: "wb");
    v5 = v4;
    if ( v4 != nullptr )
    {
      fwrite(buffer: digest, size: 4u, count: 1u, stream: v4);
      fclose(stream: v5);
      printf(format: "Wrote %s\n", datFile);
      return 0;
    }
    else
    {
      printf(format: "Can't open %s\n", datFile);
      return 1;
    }
  }
  else
  {
    printf(format: "USAGE: newdat <filename>\n");
    return 1;
  }
}
