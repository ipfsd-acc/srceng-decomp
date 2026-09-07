// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_messnc.c
// Functions: 3
// ============================================================

#include "mysql-connector-c-6.0.2\mysys\my_messnc.h"

//------------------------------------------------------------------------------
// Address: 0x00420B10
// Name: _my_message_no_curses
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_message_no_curses(int a1, char *string, char a3)
{
  _iobuf *v3; // eax
  _iobuf *v4; // eax
  _iobuf *v5; // eax
  _iobuf *v6; // eax
  _iobuf *v7; // eax
  _iobuf *v8; // eax
  _iobuf *v9; // eax

  v3 = __iob_func();
  fflush(stream: v3 + 1);
  if ( (a3 & 4) != 0 )
  {
    v4 = __iob_func();
    fputc(ch: 7, str: v4 + 2);
  }
  if ( my_progname != IdleShutdown )
  {
    v5 = __iob_func();
    fputs(string: (const char *)my_progname, stream: v5 + 2);
    v6 = __iob_func();
    fputs(string: ": ", stream: v6 + 2);
  }
  v7 = __iob_func();
  fputs(string, stream: v7 + 2);
  v8 = __iob_func();
  fputc(ch: 10, str: v8 + 2);
  v9 = __iob_func();
  return fflush(stream: v9 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x00420BB0
// Name: void __near * operator new(unsigned int,struct yaSSL::new_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall operator new(const CSplitScreenAddedConVar *sz, unsigned int sza)
{
  unsigned int v2; // eax
  CSplitScreenAddedConVar *result; // eax

  v2 = sza;
  if ( sza == 0 )
    v2 = 1;
  result = (CSplitScreenAddedConVar *)operator new(nSize: v2);
  if ( result == nullptr )
    abort();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00420BE0
// Name: void __near * operator new[](unsigned int,struct TaoCrypt::new_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall operator new[](
        const CSplitScreenAddedConVar *sz,
        const CSplitScreenAddedConVar *sza)
{
  return operator new(sz: sza, (unsigned int)sza);
}
