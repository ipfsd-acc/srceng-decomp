// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/ltm.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1001F7F0
// Name: _luaT_init
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaT_init(lua_State *L)
{
  const char *const *v1; // eax
  char *v2; // edx
  unsigned int v3; // edi
  unsigned int v4; // esi
  unsigned int v5; // ecx
  char *v6; // ebx
  unsigned __int8 v7; // al
  GCObject *v8; // ebx
  unsigned int v9; // eax
  lua_TValue *upvalue; // ecx
  char *v11; // esi
  TString *v12; // eax
  unsigned int v13; // [esp+10h] [ebp-18h]
  unsigned int k; // [esp+14h] [ebp-14h]
  int v15; // [esp+18h] [ebp-10h]
  char *v16; // [esp+1Ch] [ebp-Ch]
  int v17; // [esp+24h] [ebp-4h]

  v1 = &luaT_eventname[-47];
  v15 = 47;
  while ( 2 )
  {
    v2 = (char *)v1[v15];
    v16 = v2;
    v3 = strlen(v2);
    v4 = (v3 >> 5) + 1;
    v5 = v3;
    v13 = v3;
    k = v3;
    if ( v3 >= v4 )
    {
      v6 = &v2[v3 - 1];
      v17 = 1 - (_DWORD)v2;
      do
      {
        v13 ^= (unsigned __int8)*v6 + (v5 >> 2) + 32 * v5;
        v7 = tolower(c: *v6);
        v5 = v13;
        k ^= (k >> 2) + 32 * k + v7;
        v6 -= v4;
      }
      while ( (unsigned int)&v6[v17] >= v4 );
      v2 = v16;
    }
    v8 = L->l_G->strt.hash[v5 & (L->l_G->strt.size - 1)];
    if ( v8 == nullptr )
    {
LABEL_20:
      v12 = newlstr(l: v3, L, str: v2, h: v5, k);
      goto LABEL_21;
    }
    while ( v8->ts.tsv.len != v3 )
    {
LABEL_19:
      v8 = (GCObject *)v8->ts.dummy.l;
      if ( v8 == nullptr )
        goto LABEL_20;
    }
    v9 = v3;
    upvalue = v8->cl.c.upvalue;
    v11 = v2;
    if ( v3 >= 4 )
    {
      while ( *(_DWORD *)v11 == upvalue->value.b )
      {
        v9 -= 4;
        upvalue = (lua_TValue *)((char *)upvalue + 4);
        v11 += 4;
        if ( v9 < 4 )
          goto LABEL_12;
      }
      goto LABEL_18;
    }
LABEL_12:
    if ( v9 != 0
      && (LOBYTE(upvalue->value.n) != *v11
       || v9 > 1 && (BYTE1(upvalue->value.gc) != v11[1] || v9 > 2 && BYTE2(upvalue->value.p) != v11[2])) )
    {
LABEL_18:
      v2 = v16;
      v5 = v13;
      goto LABEL_19;
    }
    if ( ((unsigned __int8)~L->l_G->currentwhite & v8->gch.marked & 3) != 0 )
      v8->gch.marked ^= 3u;
    v12 = (TString *)v8;
LABEL_21:
    *(GCObject ***)((char *)&L->l_G->strt.hash + v15 * 4) = (GCObject **)v12;
    (*(_BYTE **)((char *)&L->l_G->strt.hash + v15 * 4))[5] |= 0x20u;
    if ( ++v15 < 64 )
    {
      v1 = &luaT_eventname[-47];
      continue;
    }
    break;
  }
}
