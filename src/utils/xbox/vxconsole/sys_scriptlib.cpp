// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/sys_scriptlib.cpp
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00426E70
// Name: void Sys_FreeScriptFile(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_FreeScriptFile()
{
  if ( g_sys_scriptbuff != nullptr )
  {
    Sys_Free(ptr: g_sys_scriptbuff);
    g_sys_scriptbuff = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426FF0
// Name: void Sys_SkipRestOfLine(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_SkipRestOfLine()
{
  char *v0; // eax

  v0 = g_sys_scriptptr;
  if ( *g_sys_scriptptr == 10 )
  {
LABEL_4:
    g_sys_scriptptr = v0 + 1;
  }
  else
  {
    while ( 1 )
    {
      g_sys_scriptptr = ++v0;
      if ( v0 >= g_sys_scriptendptr )
        break;
      if ( *v0 == 10 )
        goto LABEL_4;
    }
  }
  ++g_sys_scriptline;
  g_sys_tokenready = false;
}

//------------------------------------------------------------------------------
// Address: 0x00427030
// Name: void Sys_SaveParser(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_SaveParser()
{
  g_sys_oldscriptline = g_sys_scriptline;
  g_sys_oldscriptptr = g_sys_scriptptr;
}

//------------------------------------------------------------------------------
// Address: 0x00427050
// Name: void Sys_RestoreParser(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_RestoreParser()
{
  g_sys_scriptline = g_sys_oldscriptline;
  g_sys_scriptptr = g_sys_oldscriptptr;
  g_sys_tokenready = false;
}

//------------------------------------------------------------------------------
// Address: 0x00427070
// Name: void Sys_StripQuotesFromToken(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_StripQuotesFromToken(char *pToken)
{
  int v1; // esi

  v1 = strlen(pToken);
  if ( v1 >= 2 && *pToken == 34 )
  {
    memcpy(dst: (unsigned __int8 *)pToken, src: (unsigned __int8 *)pToken + 1, count: v1 - 1);
    pToken[v1 - 2] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004270B0
// Name: void Sys_LoadScriptFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_LoadScriptFile(const char *filename)
{
  unsigned int File; // eax

  File = Sys_LoadFile(filename, bufferptr: (void **)&g_sys_scriptbuff, bText: false);
  g_sys_scriptptr = g_sys_scriptbuff;
  g_sys_scriptsize = File;
  g_sys_scriptendptr = &g_sys_scriptbuff[File];
  g_sys_scriptline = 1;
  g_sys_endofscript = false;
  g_sys_tokenready = false;
}

//------------------------------------------------------------------------------
// Address: 0x00427100
// Name: void Sys_SetScriptData(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_SetScriptData(char *data, int length)
{
  g_sys_scriptbuff = data;
  g_sys_scriptptr = data;
  g_sys_scriptendptr = &data[length];
  g_sys_scriptsize = length;
  g_sys_scriptline = 1;
  g_sys_endofscript = false;
  g_sys_tokenready = false;
}
