// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/vlua/vlua.cpp
// Functions: 43
// ============================================================

#include "vscript\languages\lua\vlua\vlua.h"

//------------------------------------------------------------------------------
// Address: 0x10023800
// Name: public: static int CLuaVM::PrintFunc(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CLuaVM::PrintFunc(GCObject *pState)
{
  lua_TValue *v1; // ecx
  lua_TValue *v2; // eax
  void (__cdecl **b)(const char *); // eax
  GCObject *v4; // eax
  int i; // ebx
  lua_TValue *v6; // esi
  const char *v7; // esi
  const char *v8; // eax
  lua_TValue *k; // [esp-4h] [ebp-3Ch]
  lua_TValue *v11; // [esp-4h] [ebp-3Ch]
  int n; // [esp+10h] [ebp-28h]
  void (__cdecl *m_OutputFunc)(const char *); // [esp+14h] [ebp-24h]
  CUtlString Output; // [esp+18h] [ebp-20h] BYREF
  lua_TValue key; // [esp+28h] [ebp-10h] BYREF

  v1 = *(lua_TValue **)&pState->cl.l.upvals[0]->tt;
  if ( *(_BYTE *)(v1->value.b + 7) != 0 )
    v2 = (lua_TValue *)(v1->value.b + 24);
  else
    v2 = &luaO_nilobject_;
  if ( v2->tt == 2 )
  {
    b = (void (__cdecl **)(const char *))v2->value.b;
  }
  else if ( v2->tt == 7 )
  {
    b = (void (__cdecl **)(const char *))(v2->value.b + 24);
  }
  else
  {
    b = nullptr;
  }
  m_OutputFunc = *b;
  CUtlString::CUtlString(this: &Output);
  n = (signed int)(pState->ts.tsv.hash - pState->ts.tsv.keyhash) >> 4;
  key.value.b = (int)luaS_newlstr(L: (lua_State *)pState, str: "towstring", l: 9u);
  k = pState->p.k;
  key.tt = 4;
  luaV_gettable(L: (lua_State *)pState, t: (Node *)&pState->th.l_gt, &key, val: k);
  pState->ts.tsv.hash += 16;
  v4 = luaS_newlstr(L: (lua_State *)pState, str: "tostring", l: 8u);
  v11 = pState->p.k;
  key.value.b = (int)v4;
  key.tt = 4;
  luaV_gettable(L: (lua_State *)pState, t: (Node *)&pState->th.l_gt, &key, val: v11);
  pState->ts.tsv.hash += 16;
  for ( i = 1; i <= n; ++i )
  {
    *pState->p.k = *(lua_TValue *)(pState->ts.tsv.hash - 16);
    pState->ts.tsv.hash += 16;
    *pState->p.k = *index2adr(L: (lua_State *)pState, idx: i);
    pState->ts.tsv.hash += 16;
    luaD_call(L: (lua_State *)pState, func: (lua_TValue *)(pState->ts.tsv.hash - 32), nResults: 1);
    v6 = (lua_TValue *)(pState->ts.tsv.hash - 16);
    if ( v6->tt != 4 )
    {
      if ( luaV_tostring(obj: v6, L: (lua_State *)pState) == 0 )
        goto LABEL_21;
      if ( *(_DWORD *)(pState->ts.tsv.len + 68) >= *(_DWORD *)(pState->ts.tsv.len + 64) )
        luaC_step(L: pState);
      v6 = (lua_TValue *)(pState->ts.tsv.hash - 16);
    }
    v7 = (const char *)(v6->value.b + 24);
    if ( v7 == nullptr )
LABEL_21:
      luaL_error(L: (lua_State *)pState, fmt: "'tostring' must return a string to 'print'");
    if ( i > 1 )
      CUtlString::operator+=(this: &Output, rhs: "\t");
    CUtlString::operator+=(this: &Output, rhs: v7);
    pState->ts.tsv.hash -= 16;
  }
  if ( m_OutputFunc != nullptr )
  {
    v8 = CUtlString::operator char const *(this: &Output);
    m_OutputFunc(a1: v8);
  }
  else
  {
    _Msg(a1: "%s\n", (const char *)Output.m_Storage.m_Memory.m_pMemory);
  }
  Output.m_Storage.m_nActualLength = 0;
  if ( Output.m_Storage.m_Memory.m_nGrowSize >= 0 && Output.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: Output.m_Storage.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10023A40
// Name: public: static int CLuaVM::FatalErrorHandler(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn CLuaVM::FatalErrorHandler(GCObject *pState)
{
  lua_TValue *array; // esi
  int v2; // esi
  int pExceptionObject; // [esp+8h] [ebp-4h] BYREF

  array = pState->h.array;
  if ( (unsigned int)array >= pState->ts.tsv.hash )
    array = &luaO_nilobject_;
  if ( array->tt != 4 )
  {
    if ( luaV_tostring(obj: array, L: (lua_State *)pState) == 0 )
    {
      v2 = 0;
      goto LABEL_11;
    }
    if ( *(_DWORD *)(pState->ts.tsv.len + 68) >= *(_DWORD *)(pState->ts.tsv.len + 64) )
      luaC_step(L: pState);
    array = pState->h.array;
    if ( (unsigned int)array >= pState->ts.tsv.hash )
      array = &luaO_nilobject_;
  }
  v2 = array->value.b + 24;
LABEL_11:
  pExceptionObject = v2;
  _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2CPAD);
}

//------------------------------------------------------------------------------
// Address: 0x10023AB0
// Name: public: static void CLuaVM::PushVariant(struct lua_State __near *,struct ScriptVariant_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall CLuaVM::PushVariant(GCObject *pState@<ecx>, const ScriptVariant_t *value@<eax>)
{
  lua_TValue *k; // ecx
  const char *v4; // eax
  lua_TValue *m_int; // edi
  lua_TValue *v6; // ecx
  lua_TValue *v7; // ecx
  bool v8; // zf
  int v9; // eax
  char sz[4]; // [esp+Ch] [ebp-4h] BYREF

  switch ( value->m_type )
  {
    case 0:
      goto $LN10_17;
    case 1:
      k = pState->p.k;
      k->value.n = value->m_float;
      k->tt = 3;
      pState->ts.tsv.hash += 16;
      break;
    case 3:
      m_int = (lua_TValue *)value->m_int;
      *lua_allocvec3(pState) = *m_int;
      break;
    case 5:
      v6 = pState->p.k;
      v6->value.n = (double)value->m_int;
      v6->tt = 3;
      pState->ts.tsv.hash += 16;
      break;
    case 6:
      v7 = pState->p.k;
      v8 = value->m_char == 0;
      v7->tt = 1;
      v7->value.b = !v8;
      pState->ts.tsv.hash += 16;
      break;
    case 8:
      sz[0] = value->m_char;
      sz[1] = 0;
      lua_pushlstring(L: (lua_State *)pState, s: sz, len: 1u);
      break;
    case 0x20:
      v4 = (const char *)value->m_int;
      if ( v4 == nullptr )
        v4 = Ptr;
      lua_pushstring(L: (lua_State *)pState, s: v4);
      break;
    case 0x21:
      v9 = value->m_int;
      if ( v9 != 0 )
      {
        lua_rawgeti(L: (lua_State *)pState, idx: -10000, n: v9);
      }
      else
      {
$LN10_17:
        *(_DWORD *)(pState->ts.tsv.hash + 8) = 0;
        pState->ts.tsv.hash += 16;
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023C10
// Name: public: static bool CLuaVM::ConvertToVariant(int,struct lua_State __near *,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CLuaVM::ConvertToVariant@<al>(GCObject *pState@<edi>, int nStackIndex, ScriptVariant_t *pReturn)
{
  int v3; // esi
  lua_TValue *v4; // eax
  bool result; // al
  float v6; // xmm0_4
  lua_TValue *v7; // eax
  int tt; // ecx
  BOOL v9; // eax
  lua_TValue *v10; // eax
  const char *v11; // eax
  unsigned int v12; // kr00_4
  lua_TValue *v13; // eax
  unsigned __int8 *v14; // eax

  v3 = nStackIndex;
  v4 = index2adr(L: (lua_State *)pState, idx: nStackIndex);
  if ( v4 == &luaO_nilobject_ )
  {
LABEL_25:
    pReturn->m_type = 33;
    pReturn->m_int = luaL_ref(L: (lua_State *)pState);
    return true;
  }
  else
  {
    switch ( v4->tt )
    {
      case 0:
        pReturn->m_type = 0;
        return true;
      case 1:
        v7 = index2adr(L: (lua_State *)pState, idx: nStackIndex);
        tt = v7->tt;
        v9 = tt != 0 && (tt != 1 || v7->value.b != 0);
        pReturn->m_char = v9;
        pReturn->m_type = 6;
        return true;
      case 3:
        v6 = COERCE_DOUBLE(lua_tonumber(L: (lua_State *)pState, idx: nStackIndex));
        pReturn->m_type = 1;
        pReturn->m_float = v6;
        return true;
      case 4:
        v10 = index2adr(L: (lua_State *)pState, idx: nStackIndex);
        if ( v10->tt == 4 )
          goto LABEL_17;
        v11 = (const char *)luaV_tostring(obj: v10, L: (lua_State *)pState);
        if ( v11 != nullptr )
        {
          if ( *(_DWORD *)(pState->ts.tsv.len + 68) >= *(_DWORD *)(pState->ts.tsv.len + 64) )
            luaC_step(L: pState);
          v10 = index2adr(L: (lua_State *)pState, idx: nStackIndex);
          v3 = nStackIndex;
LABEL_17:
          v11 = (const char *)(v10->value.b + 24);
        }
        else
        {
          v3 = nStackIndex;
        }
        v12 = strlen(v11);
        pReturn->m_type = 32;
        pReturn->m_int = (int)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v12 + 1);
        v13 = index2adr(L: (lua_State *)pState, idx: v3);
        if ( v13->tt == 4 )
          goto LABEL_23;
        v14 = (unsigned __int8 *)luaV_tostring(obj: v13, L: (lua_State *)pState);
        if ( v14 != nullptr )
        {
          if ( *(_DWORD *)(pState->ts.tsv.len + 68) >= *(_DWORD *)(pState->ts.tsv.len + 64) )
            luaC_step(L: pState);
          v13 = index2adr(L: (lua_State *)pState, idx: nStackIndex);
LABEL_23:
          v14 = (unsigned __int8 *)(v13->value.b + 24);
        }
        memcpy(dst: (unsigned __int8 *)pReturn->m_int, src: v14, count: v12 + 1);
        pReturn->m_flags |= 1u;
        result = true;
        break;
      default:
        goto LABEL_25;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10023DC0
// Name: public: static void CLuaVM::ReleaseVariant(struct lua_State __near *,struct ScriptVariant_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall CLuaVM::ReleaseVariant(ScriptVariant_t *value@<esi>, lua_State *pState)
{
  __int16 m_type; // ax

  m_type = value->m_type;
  if ( m_type == 33 )
  {
    luaL_unref(ref: value->m_int, L: pState);
    value->m_type = 0;
  }
  else if ( (value->m_flags & 1) != 0 )
  {
    if ( m_type == 3 || m_type == 32 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)value->m_int);
      value->m_type = 0;
    }
    else
    {
      value->m_type = 0;
    }
  }
  else
  {
    value->m_type = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023E30
// Name: public: virtual bool CLuaVM::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLuaVM::Init(CLuaVM *this)
{
  GCObject *v2; // eax

  v2 = (GCObject *)lua_newstate();
  if ( v2 != nullptr )
    *(_DWORD *)(v2->ts.tsv.len + 88) = panic;
  this->m_LuaState = (lua_State *)v2;
  luaL_openlibs(L: v2);
  luaopen_vec3(pState: this->m_LuaState);
  this->m_LuaState->l_G->panic = (int (__cdecl *)(lua_State *))CLuaVM::FatalErrorHandler;
  this->SetOutputCallback(this, a2: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10023E80
// Name: public: virtual void CLuaVM::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLuaVM::Shutdown(CLuaVM *this)
{
  lua_State *m_LuaState; // eax

  m_LuaState = this->m_LuaState;
  if ( m_LuaState != nullptr )
  {
    lua_close(L: m_LuaState);
    this->m_LuaState = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023EB0
// Name: public: virtual enum ScriptLanguage_t CLuaVM::GetLanguage(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLuaVM::GetLanguage(CLuaVM *this)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x10023EC0
// Name: public: virtual char const __near * CLuaVM::GetLanguageName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLuaVM::GetLanguageName(CLuaVM *this)
{
  return "Lua";
}

//------------------------------------------------------------------------------
// Address: 0x10023ED0
// Name: public: virtual void CLuaVM::AddSearchPath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLuaVM::AddSearchPath(CLuaVM *this, const char *pszSearchPath)
{
  lua_State *m_LuaState; // esi
  lua_State *v4; // esi
  lua_TValue *v5; // eax
  Node *v6; // ebx
  GCObject *v7; // eax
  lua_State *v8; // ecx
  lua_TValue *v9; // eax
  int tt; // eax
  GCObject *v11; // ebx
  lua_TValue *v12; // esi
  const char *v13; // esi
  const char *v14; // eax
  lua_State *v15; // esi
  Node *v16; // ebx
  lua_TValue *top; // [esp-4h] [ebp-34h]
  lua_TValue *v18; // [esp-4h] [ebp-34h]
  lua_TValue *v19; // [esp-4h] [ebp-34h]
  CUtlString szNewPath; // [esp+10h] [ebp-20h] BYREF
  lua_TValue key; // [esp+20h] [ebp-10h] BYREF

  m_LuaState = this->m_LuaState;
  key.value.b = (int)luaS_newlstr(L: m_LuaState, str: "package", l: 7u);
  top = m_LuaState->top;
  key.tt = 4;
  luaV_gettable(L: m_LuaState, t: (Node *)&m_LuaState->l_gt, &key, val: top);
  ++m_LuaState->top;
  v4 = this->m_LuaState;
  v5 = v4->top - 1;
  if ( v5 == &luaO_nilobject_ || v5->tt != 5 )
  {
    --v4->top;
    return;
  }
  v6 = (Node *)&v4->top[-1];
  v7 = luaS_newlstr(L: v4, str: "path", l: 4u);
  v18 = v4->top;
  key.value.b = (int)v7;
  key.tt = 4;
  luaV_gettable(L: v4, t: v6, &key, val: v18);
  ++v4->top;
  v8 = this->m_LuaState;
  v9 = v8->top - 1;
  if ( v9 == &luaO_nilobject_ || (tt = v9->tt) != 4 && tt != 3 )
  {
    --v8->top;
    return;
  }
  CUtlString::CUtlString(this: &szNewPath);
  v11 = (GCObject *)this->m_LuaState;
  v12 = (lua_TValue *)(v11->ts.tsv.hash - 16);
  if ( v12->tt != 4 )
  {
    if ( luaV_tostring(obj: v12, L: this->m_LuaState) == 0 )
    {
      v13 = nullptr;
      goto LABEL_15;
    }
    if ( *(_DWORD *)(v11->ts.tsv.len + 68) >= *(_DWORD *)(v11->ts.tsv.len + 64) )
      luaC_step(L: v11);
    v12 = (lua_TValue *)(v11->ts.tsv.hash - 16);
  }
  v13 = (const char *)(v12->value.b + 24);
LABEL_15:
  CUtlString::operator=(this: &szNewPath, src: v13);
  CUtlString::operator+=(this: &szNewPath, rhs: ";");
  CUtlString::operator+=(this: &szNewPath, rhs: pszSearchPath);
  CUtlString::operator+=(this: &szNewPath, rhs: "\\?.lua");
  v14 = CUtlString::operator char const *(this: &szNewPath);
  lua_pushstring(L: this->m_LuaState, s: v14);
  v15 = this->m_LuaState;
  v16 = (Node *)&v15->top[-3];
  key.value.b = (int)luaS_newlstr(L: v15, str: "path", l: 4u);
  v19 = v15->top - 1;
  key.tt = 4;
  luaV_settable(L: v15, t: v16, &key, val: v19);
  --v15->top;
  this->m_LuaState->top -= 2;
  szNewPath.m_Storage.m_nActualLength = 0;
  if ( szNewPath.m_Storage.m_Memory.m_nGrowSize >= 0 && szNewPath.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: szNewPath.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100240B0
// Name: public: virtual bool CLuaVM::Frame(float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLuaVM::Frame(CLuaVM *this, float simTime)
{
  if ( this->m_LuaState != nullptr )
  {
    _Msg(a1: "Garbage Collecting...\n");
    lua_gc(data: 0, g: (int)this->m_LuaState->l_G, a3: 2, L: this->m_LuaState, res: 0);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100240F0
// Name: public: virtual enum ScriptStatus_t CLuaVM::Run(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLuaVM::Run(CLuaVM *this, const char *pszScript, bool bWait)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10024100
// Name: public: virtual struct HSCRIPT__ __near * CLuaVM::CompileScript(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLuaVM::CompileScript(CLuaVM *this, const char *pszScript, const char *pszId)
{
  unsigned int v4; // kr00_4
  lua_State *m_LuaState; // ecx
  GCObject *v7; // edi
  lua_TValue *v8; // esi
  const char *v9; // esi
  bool (__cdecl *m_ErrorFunc)(ScriptErrorLevel_t, const char *); // eax
  _DWORD data[2]; // [esp+10h] [ebp-8h] BYREF

  v4 = strlen(pszScript);
  m_LuaState = this->m_LuaState;
  data[1] = v4;
  data[0] = pszScript;
  if ( lua_load(
         reader: (const char *(__cdecl *)(lua_State *, void *, unsigned int *))getS,
         chunkname: pszId,
         L: m_LuaState,
         data) == 0 )
    return luaL_ref(L: this->m_LuaState);
  v7 = (GCObject *)this->m_LuaState;
  v8 = (lua_TValue *)(v7->ts.tsv.hash - 16);
  if ( v8->tt == 4 )
    goto LABEL_9;
  if ( luaV_tostring(obj: v8, L: (lua_State *)v7) != 0 )
  {
    if ( *(_DWORD *)(v7->ts.tsv.len + 68) >= *(_DWORD *)(v7->ts.tsv.len + 64) )
      luaC_step(L: v7);
    v8 = (lua_TValue *)(v7->ts.tsv.hash - 16);
LABEL_9:
    v9 = (const char *)(v8->value.b + 24);
    goto LABEL_10;
  }
  v9 = nullptr;
LABEL_10:
  m_ErrorFunc = this->m_ErrorFunc;
  if ( m_ErrorFunc != nullptr )
    m_ErrorFunc(a1: SCRIPT_LEVEL_WARNING, a2: v9);
  else
    _Msg(a1: v9);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100241D0
// Name: public: virtual void CLuaVM::ReleaseFunction(struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLuaVM::ReleaseFunction(CLuaVM *this, HSCRIPT__ *hScript)
{
  luaL_unref(ref: (int)hScript, L: this->m_LuaState);
}

//------------------------------------------------------------------------------
// Address: 0x100241F0
// Name: public: virtual enum ScriptStatus_t CLuaVM::Run(struct HSCRIPT__ __near *,struct HSCRIPT__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLuaVM::Run(CLuaVM *this, HSCRIPT__ *hScript, HSCRIPT__ *hScope, bool bWait)
{
  lua_State *m_LuaState; // edi
  lua_State *v6; // esi
  int v7; // eax
  CallInfo *ci; // ecx
  lua_TValue *top; // esi
  int v10; // eax
  int v11; // eax
  GCObject *v13; // edi
  lua_TValue *v14; // esi
  int v15; // esi
  bool (__cdecl *m_ErrorFunc)(ScriptErrorLevel_t, const char *); // ebx
  GCObject *v17; // edi
  lua_TValue *v18; // esi
  int v19; // esi
  GCObject *v20; // edi
  lua_TValue *v21; // esi
  int v22; // esi
  int v23; // [esp-4h] [ebp-1Ch]
  const char *v24; // [esp-4h] [ebp-1Ch]
  _DWORD u[2]; // [esp+10h] [ebp-8h] BYREF

  m_LuaState = this->m_LuaState;
  *m_LuaState->top++ = luaH_getnum(t: (Table *)m_LuaState->l_G->l_registry.value.gc, key: (int)hScript)->i_val;
  v6 = this->m_LuaState;
  u[0] = v6->top - 1;
  v23 = u[0] - (unsigned int)v6->stack;
  u[1] = -1;
  v7 = luaD_pcall(L: v6, ef: 0, func: f_call, u, old_top: v23);
  ci = v6->ci;
  top = v6->top;
  if ( top >= ci->top )
    ci->top = top;
  v10 = v7 - 2;
  if ( v10 != 0 )
  {
    v11 = v10 - 2;
    if ( v11 != 0 )
    {
      if ( v11 != 1 )
        return 0;
      v13 = (GCObject *)this->m_LuaState;
      v14 = (lua_TValue *)(v13->ts.tsv.hash - 16);
      if ( v14->tt != 4 )
      {
        if ( luaV_tostring(obj: v14, L: (lua_State *)v13) == 0 )
        {
          v15 = 0;
          goto LABEL_14;
        }
        if ( *(_DWORD *)(v13->ts.tsv.len + 68) >= *(_DWORD *)(v13->ts.tsv.len + 64) )
          luaC_step(L: v13);
        v14 = (lua_TValue *)(v13->ts.tsv.hash - 16);
      }
      v15 = v14->value.b + 24;
LABEL_14:
      m_ErrorFunc = this->m_ErrorFunc;
      v24 = (const char *)v15;
      if ( m_ErrorFunc != nullptr )
        goto LABEL_33;
      goto LABEL_34;
    }
    v17 = (GCObject *)this->m_LuaState;
    v18 = (lua_TValue *)(v17->ts.tsv.hash - 16);
    if ( v18->tt != 4 )
    {
      if ( luaV_tostring(obj: v18, L: (lua_State *)v17) == 0 )
      {
        v19 = 0;
        goto LABEL_23;
      }
      if ( *(_DWORD *)(v17->ts.tsv.len + 68) >= *(_DWORD *)(v17->ts.tsv.len + 64) )
        luaC_step(L: v17);
      v18 = (lua_TValue *)(v17->ts.tsv.hash - 16);
    }
    v19 = v18->value.b + 24;
LABEL_23:
    m_ErrorFunc = this->m_ErrorFunc;
    v24 = (const char *)v19;
    if ( m_ErrorFunc != nullptr )
      goto LABEL_33;
    goto LABEL_34;
  }
  v20 = (GCObject *)this->m_LuaState;
  v21 = (lua_TValue *)(v20->ts.tsv.hash - 16);
  if ( v21->tt != 4 )
  {
    if ( luaV_tostring(obj: v21, L: (lua_State *)v20) == 0 )
    {
      v22 = 0;
      goto LABEL_32;
    }
    if ( *(_DWORD *)(v20->ts.tsv.len + 68) >= *(_DWORD *)(v20->ts.tsv.len + 64) )
      luaC_step(L: v20);
    v21 = (lua_TValue *)(v20->ts.tsv.hash - 16);
  }
  v22 = v21->value.b + 24;
LABEL_32:
  m_ErrorFunc = this->m_ErrorFunc;
  v24 = (const char *)v22;
  if ( m_ErrorFunc != nullptr )
  {
LABEL_33:
    m_ErrorFunc(a1: SCRIPT_LEVEL_WARNING, a2: v24);
    return -1;
  }
LABEL_34:
  _Msg(a1: v24);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100243B0
// Name: public: virtual struct HSCRIPT__ __near * CLuaVM::LookupFunction(char const __near *,struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CLuaVM::LookupFunction(CLuaVM *this, char *pszFunction, HSCRIPT__ *hScope)
{
  lua_State *m_LuaState; // edi
  lua_State *v5; // esi
  lua_TValue *v6; // eax
  HSCRIPT__ *result; // eax
  Node *v8; // edi
  lua_State *v9; // ecx
  lua_TValue *v10; // eax
  int v11; // eax
  lua_State *v12; // esi
  lua_State *v13; // ebx
  lua_TValue *v14; // eax
  int v15; // eax
  lua_TValue *top; // [esp-4h] [ebp-24h]
  lua_TValue *v17; // [esp-4h] [ebp-24h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  if ( hScope != nullptr )
  {
    m_LuaState = this->m_LuaState;
    *m_LuaState->top++ = luaH_getnum(t: (Table *)m_LuaState->l_G->l_registry.value.gc, key: (int)hScope)->i_val;
    v5 = this->m_LuaState;
    v6 = v5->top - 1;
    if ( v6 == &luaO_nilobject_ || v6->tt != 0 )
    {
      v8 = (Node *)&v5->top[-1];
      key.value.b = (int)luaS_newlstr(L: v5, str: pszFunction, l: strlen(pszFunction));
      top = v5->top;
      key.tt = 4;
      luaV_gettable(L: v5, t: v8, &key, val: top);
      ++v5->top;
      v9 = this->m_LuaState;
      v10 = v9->top - 1;
      if ( (v10 == &luaO_nilobject_ || v10->tt != 0)
        && (lua_TValue *)(v11 = (int)&v9->top[-1]) != &luaO_nilobject_
        && *(_DWORD *)(v11 + 8) == 6 )
      {
        result = (HSCRIPT__ *)luaL_ref(L: this->m_LuaState);
        --this->m_LuaState->top;
      }
      else
      {
        v9->top -= 2;
        return nullptr;
      }
    }
    else
    {
      --v5->top;
      return nullptr;
    }
  }
  else
  {
    v12 = this->m_LuaState;
    key.value.b = (int)luaS_newlstr(L: v12, str: pszFunction, l: strlen(pszFunction));
    v17 = v12->top;
    key.tt = 4;
    luaV_gettable(L: v12, t: (Node *)&v12->l_gt, &key, val: v17);
    ++v12->top;
    v13 = this->m_LuaState;
    v14 = v13->top - 1;
    if ( (v14 == &luaO_nilobject_ || v14->tt != 0)
      && (lua_TValue *)(v15 = (int)&v13->top[-1]) != &luaO_nilobject_
      && *(_DWORD *)(v15 + 8) == 6 )
    {
      return (HSCRIPT__ *)luaL_ref(L: v13);
    }
    else
    {
      --v13->top;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10024550
// Name: public: virtual enum ScriptStatus_t CLuaVM::ExecuteFunction(struct HSCRIPT__ __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *,struct HSCRIPT__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLuaVM::ExecuteFunction(
        CLuaVM *this,
        HSCRIPT__ *hFunction,
        ScriptVariant_t *pArgs,
        int nArgs,
        ScriptVariant_t *pReturn,
        HSCRIPT__ *hScope,
        bool bWait)
{
  lua_State *m_LuaState; // edi
  unsigned int v10; // ebx
  lua_State *v11; // edi
  int v12; // esi
  int j; // edi
  int v14; // [esp+0h] [ebp-28h] BYREF
  int i; // [esp+10h] [ebp-18h]
  CLuaVM *v16; // [esp+14h] [ebp-14h]
  int *v17; // [esp+18h] [ebp-10h]
  int v18; // [esp+24h] [ebp-4h]

  v17 = &v14;
  v16 = this;
  if ( hScope == (HSCRIPT__ *)-1 )
  {
    DevWarning(a1: "ExecuteFunction: Invalid scope handed to script VM\n");
    return -1;
  }
  else
  {
    v18 = 0;
    if ( hFunction != nullptr )
    {
      m_LuaState = this->m_LuaState;
      v10 = (unsigned int)((char *)m_LuaState->stack_last - (char *)m_LuaState->top) >> 4;
      lua_rawgeti(L: m_LuaState, idx: -10000, n: (int)hFunction);
      v11 = this->m_LuaState;
      v12 = v11->top - v11->base;
      if ( hScope != nullptr )
        lua_rawgeti(L: v11, idx: -10000, n: (int)hScope);
      for ( j = 0; ; ++j )
      {
        i = j;
        if ( j >= nArgs )
          break;
        CLuaVM::PushVariant(pState: (GCObject *)v16->m_LuaState, value: &pArgs[j]);
      }
      lua_call(
        L: v16->m_LuaState,
        nargs: v16->m_LuaState->top - v16->m_LuaState->base - v12,
        nresults: pReturn != nullptr);
      if ( pReturn != nullptr )
        CLuaVM::ConvertToVariant(pState: (GCObject *)v16->m_LuaState, nStackIndex: -1, pReturn);
      lua_settop(
        L: v16->m_LuaState,
        idx: ((unsigned int)((char *)v16->m_LuaState->stack_last - (char *)v16->m_LuaState->top) >> 4) - v10 - 1);
      return 0;
    }
    else
    {
      if ( pReturn != nullptr )
        pReturn->m_type = 0;
      return -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100246D0
// Name: public: static int CLuaVM::TranslateCall(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CLuaVM::TranslateCall(GCObject *pState)
{
  GCObject *v1; // eax
  lua_TValue *upvalue; // ecx
  int v3; // edi
  int m_Size; // eax
  int v5; // ecx
  lua_TValue *v6; // eax
  void **b; // eax
  int (__thiscall ****v8)(_DWORD, void *); // ecx
  void *v9; // edx
  int v11; // eax
  int v12; // edi
  int v13; // esi
  float v14; // xmm0_4
  lua_TValue *v15; // eax
  Vector *v16; // eax
  __int16 v17; // cx
  lua_TValue *v18; // eax
  int tt; // ecx
  BOOL v20; // eax
  lua_TValue *v21; // eax
  char v22; // al
  char v23; // al
  ScriptFunctionBinding_t *v24; // esi
  char *v25; // esi
  __int16 v26; // ax
  int v27; // edi
  Table **v28; // eax
  lua_TValue *v29; // eax
  lua_TValue *k; // esi
  lua_TValue *v31; // eax
  GCObject *v32; // eax
  global_State *l_G; // ecx
  lua_TValue *v34; // eax
  lua_TValue *v35; // eax
  lua_TValue *v36; // esi
  lua_TValue *v37; // eax
  GCObject *v38; // eax
  global_State *v39; // ecx
  bool bCallFree; // [esp+13h] [ebp-95h]
  void *pObject; // [esp+14h] [ebp-94h]
  lua_TValue *pObjecta; // [esp+14h] [ebp-94h]
  lua_TValue *pObjectb; // [esp+14h] [ebp-94h]
  int i; // [esp+18h] [ebp-90h]
  int ia; // [esp+18h] [ebp-90h]
  int ib; // [esp+18h] [ebp-90h]
  int idx; // [esp+1Ch] [ebp-8Ch]
  int *pCurParamType; // [esp+20h] [ebp-88h]
  int *pCurParamTypea; // [esp+20h] [ebp-88h]
  ScriptFunctionBinding_t *pVMScriptFunction; // [esp+24h] [ebp-84h]
  ScriptVariant_t returnValue; // [esp+28h] [ebp-80h] BYREF
  CUtlVectorFixed<ScriptVariant_t,14> params; // [esp+30h] [ebp-78h] BYREF

  v1 = **(GCObject ***)&pState->cl.l.upvals[0]->tt;
  upvalue = v1->cl.c.upvalue;
  v3 = (signed int)(pState->ts.tsv.hash - pState->ts.tsv.keyhash) >> 4;
  if ( v1->cl.c.nupvalues == 0 )
    upvalue = &luaO_nilobject_;
  if ( upvalue->tt == 2 )
  {
    pVMScriptFunction = (ScriptFunctionBinding_t *)upvalue->value.b;
  }
  else if ( upvalue->tt == 7 )
  {
    pVMScriptFunction = (ScriptFunctionBinding_t *)(upvalue->value.b + 24);
  }
  else
  {
    pVMScriptFunction = nullptr;
  }
  m_Size = pVMScriptFunction->m_desc.m_Parameters.m_Size;
  params.m_pElements = (ScriptVariant_t *)&params;
  i = m_Size;
  *(_DWORD *)&returnValue.m_type = 0;
  returnValue.m_int = 0;
  bCallFree = false;
  params.m_Size = 0;
  CUtlVector<ScriptVariant_t,CUtlMemoryFixed<ScriptVariant_t,14,0>>::InsertMultipleBefore(
    this: &params,
    elem: 0,
    num: m_Size);
  pObject = nullptr;
  if ( v3 != 0 )
  {
    v5 = 1;
    if ( (pVMScriptFunction->m_flags & 1) != 0 )
    {
      v6 = index2adr(L: (lua_State *)pState, idx: 1);
      if ( v6->tt == 2 )
      {
        b = (void **)v6->value.b;
      }
      else if ( v6->tt == 7 )
      {
        b = (void **)(v6->value.b + 24);
      }
      else
      {
        b = nullptr;
      }
      v8 = (int (__thiscall ****)(_DWORD, void *))b[1];
      v9 = *b;
      pObject = *b;
      if ( v8[11] != nullptr )
      {
        pObject = (void *)(**v8[11])(a1: v8[11], a2: v9);
        v9 = pObject;
      }
      if ( v9 == nullptr )
        return -1;
      v5 = 2;
      --v3;
    }
    v11 = i;
    ia = v3;
    if ( v3 >= v11 )
      ia = v11;
    v12 = 0;
    pCurParamType = pVMScriptFunction->m_desc.m_Parameters.m_Memory.m_pMemory;
    if ( ia > 0 )
    {
      v13 = v5;
      idx = v5;
      do
      {
        switch ( *pCurParamType )
        {
          case 1:
            v14 = COERCE_DOUBLE(lua_tonumber(L: (lua_State *)pState, idx: v13));
            *(_WORD *)&params.m_Memory.m_Memory[8 * v12 + 4] = 1;
            *(float *)&params.m_Memory.m_Memory[8 * v12] = v14;
            break;
          case 3:
            v16 = lua_getvec3((lua_State *)pState, i: v13);
            v17 = 3;
            goto LABEL_49;
          case 5:
            v16 = (Vector *)(int)COERCE_DOUBLE(lua_tonumber(L: (lua_State *)pState, idx: v13));
            *(_WORD *)&params.m_Memory.m_Memory[8 * v12 + 4] = 5;
            goto LABEL_50;
          case 6:
            v18 = index2adr(L: (lua_State *)pState, idx: v13);
            tt = v18->tt;
            v20 = tt != 0 && (tt != 1 || v18->value.b != 0);
            *(_WORD *)&params.m_Memory.m_Memory[8 * v12 + 4] = 6;
            params.m_Memory.m_Memory[8 * v12] = v20;
            break;
          case 8:
            v21 = index2adr(L: (lua_State *)pState, idx: v13);
            if ( v21->tt == 4 )
              goto LABEL_47;
            if ( luaV_tostring(obj: v21, L: (lua_State *)pState) != 0 )
            {
              if ( *(_DWORD *)(pState->ts.tsv.len + 68) >= *(_DWORD *)(pState->ts.tsv.len + 64) )
                luaC_step(L: pState);
              v21 = index2adr(L: (lua_State *)pState, idx);
              v13 = idx;
LABEL_47:
              v23 = *(_BYTE *)(v21->value.b + 24);
              *(_WORD *)&params.m_Memory.m_Memory[8 * v12 + 4] = 8;
              params.m_Memory.m_Memory[8 * v12] = v23;
            }
            else
            {
              v22 = MEMORY[0];
              v13 = idx;
              *(_WORD *)&params.m_Memory.m_Memory[8 * v12 + 4] = 8;
              params.m_Memory.m_Memory[8 * v12] = v22;
            }
            break;
          case 32:
            v15 = index2adr(L: (lua_State *)pState, idx: v13);
            if ( v15->tt == 4 )
              goto LABEL_32;
            v16 = (Vector *)luaV_tostring(obj: v15, L: (lua_State *)pState);
            if ( v16 != nullptr )
            {
              if ( *(_DWORD *)(pState->ts.tsv.len + 68) >= *(_DWORD *)(pState->ts.tsv.len + 64) )
                luaC_step(L: pState);
              v15 = index2adr(L: (lua_State *)pState, idx);
              v13 = idx;
LABEL_32:
              v16 = (Vector *)(v15->value.b + 24);
              *(_WORD *)&params.m_Memory.m_Memory[8 * v12 + 4] = 32;
            }
            else
            {
              v13 = idx;
              *(_WORD *)&params.m_Memory.m_Memory[8 * v12 + 4] = 32;
            }
LABEL_50:
            *(_DWORD *)&params.m_Memory.m_Memory[8 * v12] = v16;
            break;
          case 33:
            *pState->p.k = *index2adr(L: (lua_State *)pState, idx: v13);
            pState->ts.tsv.hash += 16;
            v16 = (Vector *)luaL_ref(L: (lua_State *)pState);
            v17 = 33;
            bCallFree = true;
LABEL_49:
            *(_WORD *)&params.m_Memory.m_Memory[8 * v12 + 4] = v17;
            goto LABEL_50;
          default:
            break;
        }
        ++pCurParamType;
        ++v12;
        idx = ++v13;
      }
      while ( v12 < ia );
    }
  }
  v24 = pVMScriptFunction;
  pVMScriptFunction->m_pfnBinding(
    a1: pVMScriptFunction->m_pFunction,
    a2: pObject,
    a3: (ScriptVariant_t *)&params,
    a4: params.m_Size,
    a5: pVMScriptFunction->m_desc.m_ReturnType != 0 ? &returnValue : nullptr);
  if ( pVMScriptFunction->m_desc.m_ReturnType != 0 )
    CLuaVM::PushVariant(pState, value: &returnValue);
  if ( bCallFree )
  {
    ib = 0;
    if ( params.m_Size > 0 )
    {
      v25 = &params.m_Memory.m_Memory[4];
      pCurParamTypea = (int *)&params.m_Memory.m_Memory[4];
      do
      {
        v26 = *(_WORD *)v25;
        if ( *(_WORD *)v25 == 33 )
        {
          v27 = *((_DWORD *)v25 - 1);
          if ( v27 >= 0 )
          {
            v28 = (Table **)index2adr(L: (lua_State *)pState, idx: -10000);
            *pState->p.k = luaH_getnum(t: *v28, key: 0)->i_val;
            pState->ts.tsv.hash += 16;
            v29 = index2adr(L: (lua_State *)pState, idx: -10000);
            k = pState->p.k;
            pObjecta = v29;
            luaH_setnum(t: v29->value.gc, key: v27, L: (lua_State *)pState)->i_val = k[-1];
            v31 = pState->p.k;
            if ( v31[-1].tt >= 4 && (*(_BYTE *)(v31[-1].value.b + 5) & 3) != 0 )
            {
              v32 = (GCObject *)pObjecta->value.b;
              if ( (*(_BYTE *)(pObjecta->value.b + 5) & 4) != 0 )
              {
                l_G = pState->th.l_G;
                v32->gch.marked &= ~4u;
                v32->cl.c.upvalue[0].value.b = (int)l_G->grayagain;
                l_G->grayagain = v32;
              }
            }
            pState->ts.tsv.hash -= 16;
            v34 = pState->p.k;
            v34->tt = 3;
            v34->value.n = (double)v27;
            pState->ts.tsv.hash += 16;
            v35 = index2adr(L: (lua_State *)pState, idx: -10000);
            v36 = pState->p.k;
            pObjectb = v35;
            luaH_setnum(t: v35->value.gc, key: 0, L: (lua_State *)pState)->i_val = v36[-1];
            v37 = pState->p.k;
            if ( v37[-1].tt >= 4 && (*(_BYTE *)(v37[-1].value.b + 5) & 3) != 0 )
            {
              v38 = (GCObject *)pObjectb->value.b;
              if ( (*(_BYTE *)(pObjectb->value.b + 5) & 4) != 0 )
              {
                v39 = pState->th.l_G;
                v38->gch.marked &= ~4u;
                v38->cl.c.upvalue[0].value.b = (int)v39->grayagain;
                v39->grayagain = v38;
              }
            }
            pState->ts.tsv.hash -= 16;
            v25 = (char *)pCurParamTypea;
          }
        }
        else if ( (v25[2] & 1) != 0 && (v26 == 3 || v26 == 32) )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v25 - 1));
        }
        *(_WORD *)v25 = 0;
        v25 += 8;
        ++ib;
        pCurParamTypea = (int *)v25;
      }
      while ( ib < params.m_Size );
      v24 = pVMScriptFunction;
    }
  }
  return v24->m_desc.m_ReturnType != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10024C10
// Name: public: void CLuaVM::RegisterFunctionGuts(struct ScriptFunctionBinding_t __near *,struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLuaVM::RegisterFunctionGuts(
        CLuaVM *this,
        CLuaVM *pScriptFunction,
        ScriptFunctionBinding_t *pOwningClass,
        HSCRIPT__ *pOwningClassa)
{
  int m_Size; // eax
  char *v5; // ebx
  int *m_pMemory; // ecx
  int v7; // edx
  const char *m_LuaState; // edi
  Node *v9; // eax
  Value *v10; // ecx
  ScriptFunctionBinding_t *v11; // edi
  const char *v12; // ecx
  lua_TValue *v13; // eax
  char *m_pszScriptName; // eax
  GCObject *m_pszFunction; // esi
  _DWORD *hash; // ebx
  const char *v17; // eax
  ScriptFunctionBinding_t **v18; // ecx
  lua_State *v19; // esi
  int v20; // ebx
  Node *v21; // eax
  char szTypeMask[64]; // [esp+0h] [ebp-48h] BYREF
  char *str; // [esp+40h] [ebp-8h]
  int nStackIndex; // [esp+44h] [ebp-4h]
  CLuaVM *thisa; // [esp+50h] [ebp+8h]

  m_Size = pOwningClass->m_desc.m_Parameters.m_Size;
  if ( (unsigned int)m_Size <= 0x3F )
  {
    v5 = &szTypeMask[1];
    if ( m_Size > 0 )
    {
      m_pMemory = pOwningClass->m_desc.m_Parameters.m_Memory.m_pMemory;
      v7 = pOwningClass->m_desc.m_Parameters.m_Size;
      do
      {
        switch ( *m_pMemory )
        {
          case 1:
          case 5:
            *v5 = 110;
            break;
          case 3:
            *v5 = 120;
            break;
          case 6:
            *v5 = 98;
            break;
          case 32:
            *v5 = 115;
            break;
          case 33:
            *v5 = 46;
            break;
          default:
            *v5 = 0;
            break;
        }
        ++m_pMemory;
        ++v5;
        --v7;
      }
      while ( v7 != 0 );
    }
    nStackIndex = -10002;
    if ( pOwningClassa != nullptr )
    {
      m_LuaState = (const char *)pScriptFunction->m_LuaState;
      v9 = luaH_getnum(t: *(Table **)(*((_DWORD *)m_LuaState + 4) + 96), key: (int)pOwningClassa);
      v10 = *((Value **)m_LuaState + 2);
      *v10 = v9->i_val.value;
      v10[1].b = v9->i_val.tt;
      *((_DWORD *)m_LuaState + 2) += 16;
      v11 = (ScriptFunctionBinding_t *)pScriptFunction;
      v12 = (const char *)pScriptFunction->m_LuaState;
      v13 = (lua_TValue *)(*((_DWORD *)v12 + 2) - 16);
      if ( v13 == &luaO_nilobject_ || v13->tt != 0 )
        nStackIndex = (*((_DWORD *)v12 + 2) - *((_DWORD *)v12 + 3)) >> 4;
    }
    else
    {
      v11 = (ScriptFunctionBinding_t *)pScriptFunction;
    }
    m_pszScriptName = (char *)pOwningClass->m_desc.m_pszScriptName;
    m_pszFunction = (GCObject *)v11->m_desc.m_pszFunction;
    *v5 = 0;
    str = m_pszScriptName;
    if ( m_pszScriptName != nullptr )
    {
      thisa = (CLuaVM *)strlen(m_pszScriptName);
      if ( *(_DWORD *)(m_pszFunction->ts.tsv.len + 68) >= *(_DWORD *)(m_pszFunction->ts.tsv.len + 64) )
        luaC_step(L: m_pszFunction);
      hash = (_DWORD *)m_pszFunction->ts.tsv.hash;
      *hash = luaS_newlstr(L: (lua_State *)m_pszFunction, str, l: (unsigned int)thisa);
      hash[2] = 4;
    }
    else
    {
      *(_DWORD *)(m_pszFunction->ts.tsv.hash + 8) = 0;
    }
    m_pszFunction->ts.tsv.hash += 16;
    v17 = v11->m_desc.m_pszFunction;
    v18 = *((ScriptFunctionBinding_t ***)v17 + 2);
    *v18 = pOwningClass;
    v18[2] = (ScriptFunctionBinding_t *)2;
    *((_DWORD *)v17 + 2) += 16;
    lua_pushcclosure(
      L: (lua_State *)v11->m_desc.m_pszFunction,
      fn: (int (__cdecl *)(lua_State *))CLuaVM::TranslateCall,
      n: 1);
    v19 = (lua_State *)v11->m_desc.m_pszFunction;
    v20 = nStackIndex;
    v21 = (Node *)index2adr(L: v19, idx: nStackIndex);
    luaV_settable(L: v19, t: v21, key: v19->top - 2, val: v19->top - 1);
    v19->top -= 2;
    if ( pOwningClassa != nullptr )
      *((_DWORD *)v11->m_desc.m_pszFunction + 2) -= 16;
    if ( v20 == -10002 )
      _Msg(a1: "VLua: Registered GLOBAL function %s\n", pOwningClass->m_desc.m_pszScriptName);
    else
      _Msg(a1: "VLua: Registered TABLE function %s\n", pOwningClass->m_desc.m_pszScriptName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024E10
// Name: public: virtual void CLuaVM::RegisterFunction(struct ScriptFunctionBinding_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLuaVM::RegisterFunction(CLuaVM *this, ScriptFunctionBinding_t *pScriptFunction)
{
  CLuaVM::RegisterFunctionGuts(this, pScriptFunction: this, pOwningClass: pScriptFunction, pOwningClassa: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10024E30
// Name: public: static int CLuaVM::custom_index(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CLuaVM::custom_index(GCObject *pState)
{
  lua_TValue *array; // edx
  lua_TValue *k; // edi
  lua_TValue *v3; // eax
  int b; // eax
  lua_TValue *v5; // esi
  int v6; // esi
  lua_TValue *v7; // eax
  int v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  Node *v11; // edi
  GCObject *v12; // eax
  lua_TValue *v13; // ecx
  unsigned int v14; // esi
  lua_TValue *v15; // edi
  lua_TValue *v16; // ecx
  lua_TValue *v18; // [esp-4h] [ebp-2Ch]
  ScriptClassDesc_t *pVMScriptFunction; // [esp+10h] [ebp-18h]
  char *str; // [esp+14h] [ebp-14h]
  lua_TValue key; // [esp+18h] [ebp-10h] BYREF

  array = pState->h.array;
  k = pState->p.k;
  v3 = &luaO_nilobject_;
  if ( array < k )
    v3 = pState->h.array;
  if ( v3->tt == 2 )
  {
    b = v3->value.b;
  }
  else if ( v3->tt == 7 )
  {
    b = v3->value.b + 24;
  }
  else
  {
    b = 0;
  }
  v5 = array + 1;
  pVMScriptFunction = *(ScriptClassDesc_t **)(b + 4);
  if ( &array[1] >= k )
    v5 = &luaO_nilobject_;
  if ( v5->tt != 4 )
  {
    if ( luaV_tostring(obj: v5, L: (lua_State *)pState) == 0 )
    {
LABEL_17:
      v7 = (lua_TValue *)(pState->ts.tsv.keyhash + 16);
      if ( (unsigned int)v7 >= pState->ts.tsv.hash
        || v7 == &luaO_nilobject_
        || (v8 = *(_DWORD *)(pState->ts.tsv.keyhash + 24)) == -1 )
      {
        v9 = "no value";
      }
      else
      {
        v9 = luaT_typenames[v8];
      }
      v10 = lua_pushfstring(L: (lua_State *)pState, fmt: "%s expected, got %s", "string", v9);
      luaL_argerror(L: (lua_State *)pState, extramsg: v10, narg: 2);
    }
    if ( *(_DWORD *)(pState->ts.tsv.len + 68) >= *(_DWORD *)(pState->ts.tsv.len + 64) )
      luaC_step(L: pState);
    v5 = (lua_TValue *)(pState->ts.tsv.keyhash + 16);
    if ( (unsigned int)v5 >= pState->ts.tsv.hash )
      v5 = &luaO_nilobject_;
  }
  v6 = v5->value.b;
  str = (char *)(v6 + 24);
  if ( v6 == -24 )
    goto LABEL_17;
  for ( ; pVMScriptFunction != nullptr; pVMScriptFunction = pVMScriptFunction->m_pBaseDesc )
  {
    v11 = (Node *)(pState->ts.tsv.len + 96);
    v12 = luaS_newlstr(
            L: (lua_State *)pState,
            str: (char *)pVMScriptFunction->m_pszClassname,
            l: strlen(pVMScriptFunction->m_pszClassname));
    v18 = pState->p.k;
    key.value.b = (int)v12;
    key.tt = 4;
    luaV_gettable(L: (lua_State *)pState, t: v11, &key, val: v18);
    pState->ts.tsv.hash += 16;
    v13 = pState->p.k;
    if ( &v13[-1] != &luaO_nilobject_ && v13[-1].tt == 0 )
      break;
    if ( str != nullptr )
    {
      v14 = strlen(str);
      if ( *(_DWORD *)(pState->ts.tsv.len + 68) >= *(_DWORD *)(pState->ts.tsv.len + 64) )
        luaC_step(L: pState);
      v15 = pState->p.k;
      v15->value.b = (int)luaS_newlstr(L: (lua_State *)pState, str, l: v14);
      v15->tt = 4;
      pState->ts.tsv.hash += 16;
    }
    else
    {
      v13->tt = 0;
      pState->ts.tsv.hash += 16;
    }
    *(lua_TValue *)(pState->ts.tsv.hash - 16) = luaH_get(
                                                  t: *(Table **)(pState->ts.tsv.hash - 32),
                                                  key: (const lua_TValue *)(pState->ts.tsv.hash - 16))->i_val;
    v16 = pState->p.k;
    if ( &v16[-1] == &luaO_nilobject_ )
      break;
    if ( v16[-1].tt != 0 )
      break;
    pState->ts.tsv.hash = (unsigned int)&v16[-2];
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025030
// Name: public: virtual bool CLuaVM::RegisterClass(struct ScriptClassDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLuaVM::RegisterClass(CLuaVM *this, ScriptClassDesc_t *pClassDesc)
{
  lua_State *m_LuaState; // esi
  Node *v5; // edi
  GCObject *v6; // eax
  int v7; // esi
  HSCRIPT__ *v8; // edi
  lua_State *v9; // ebx
  Table **v10; // eax
  Node *v11; // eax
  Value *p_value; // ecx
  lua_TValue *v13; // eax
  lua_TValue *top; // esi
  Node *v15; // eax
  lua_TValue *v16; // eax
  GCObject *b; // eax
  global_State *l_G; // ecx
  lua_TValue *v19; // eax
  lua_TValue *v20; // eax
  lua_TValue *v21; // esi
  Node *v22; // eax
  lua_TValue *v23; // eax
  GCObject *v24; // eax
  global_State *v25; // ecx
  lua_TValue *v26; // [esp-18h] [ebp-38h]
  int v27; // [esp+Ch] [ebp-14h]
  lua_TValue *v28; // [esp+Ch] [ebp-14h]
  lua_TValue *v29; // [esp+Ch] [ebp-14h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  if ( luaL_newmetatable(L: this->m_LuaState, tname: pClassDesc->m_pszScriptName) != 0 )
  {
    lua_pushcclosure(L: this->m_LuaState, fn: (int (__cdecl *)(lua_State *))CLuaVM::custom_index, n: 0);
    m_LuaState = this->m_LuaState;
    v5 = (Node *)&m_LuaState->top[-2];
    v6 = luaS_newlstr(L: m_LuaState, str: "__index", l: 7u);
    v26 = m_LuaState->top - 1;
    key.value.b = (int)v6;
    key.tt = 4;
    luaV_settable(L: m_LuaState, t: v5, &key, val: v26);
    --m_LuaState->top;
    v7 = 0;
    v8 = (HSCRIPT__ *)luaL_ref(L: this->m_LuaState);
    if ( pClassDesc->m_FunctionBindings.m_Size > 0 )
    {
      v27 = 0;
      do
      {
        CLuaVM::RegisterFunctionGuts(
          this: (CLuaVM *)&pClassDesc->m_FunctionBindings.m_Memory.m_pMemory[v27],
          pScriptFunction: this,
          pOwningClass: &pClassDesc->m_FunctionBindings.m_Memory.m_pMemory[v27],
          pOwningClassa: v8);
        ++v27;
        ++v7;
      }
      while ( v7 < pClassDesc->m_FunctionBindings.m_Size );
    }
    if ( pClassDesc->m_pBaseDesc != nullptr )
      this->RegisterClass(this, a2: pClassDesc->m_pBaseDesc);
    v9 = this->m_LuaState;
    if ( (int)v8 >= 0 )
    {
      v10 = (Table **)index2adr(L: v9, idx: -10000);
      v11 = luaH_getnum(t: *v10, key: 0);
      p_value = &v9->top->value;
      *p_value = v11->i_val.value;
      p_value[1].b = v11->i_val.tt;
      ++v9->top;
      v13 = index2adr(L: v9, idx: -10000);
      top = v9->top;
      v28 = v13;
      v15 = luaH_setnum(t: v13->value.gc, key: (int)v8, L: v9);
      v15->i_val.value = top[-1].value;
      v15->i_val.tt = top[-1].tt;
      v16 = v9->top;
      if ( v16[-1].tt >= 4 && (*(_BYTE *)(v16[-1].value.b + 5) & 3) != 0 )
      {
        b = (GCObject *)v28->value.b;
        if ( (*(_BYTE *)(v28->value.b + 5) & 4) != 0 )
        {
          l_G = v9->l_G;
          b->gch.marked &= ~4u;
          b->cl.c.upvalue[0].value.b = (int)l_G->grayagain;
          l_G->grayagain = b;
        }
      }
      v19 = --v9->top;
      v19->tt = 3;
      v19->value.n = (double)(int)v8;
      ++v9->top;
      v20 = index2adr(L: v9, idx: -10000);
      v21 = v9->top;
      v29 = v20;
      v22 = luaH_setnum(t: v20->value.gc, key: 0, L: v9);
      v22->i_val.value = v21[-1].value;
      v22->i_val.tt = v21[-1].tt;
      v23 = v9->top;
      if ( v23[-1].tt >= 4 && (*(_BYTE *)(v23[-1].value.b + 5) & 3) != 0 )
      {
        v24 = (GCObject *)v29->value.b;
        if ( (*(_BYTE *)(v29->value.b + 5) & 4) != 0 )
        {
          v25 = v9->l_G;
          v24->gch.marked &= ~4u;
          v24->cl.c.upvalue[0].value.b = (int)v25->grayagain;
          v25->grayagain = v24;
        }
      }
      --v9->top;
    }
    return 1;
  }
  else
  {
    --this->m_LuaState->top;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025220
// Name: public: virtual struct HSCRIPT__ __near * CLuaVM::RegisterInstance(struct ScriptClassDesc_t __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CLuaVM::RegisterInstance(CLuaVM *this, ScriptClassDesc_t *pClassDesc, void *pInstance)
{
  lua_State *m_LuaState; // esi
  CallInfo *ci; // eax
  GCObject *gc; // edx
  global_State *l_G; // edi
  int v9; // eax
  int *top; // ecx
  lua_State *v11; // esi
  Node *p_l_registry; // edi
  lua_TValue *v13; // [esp-10h] [ebp-30h]
  GCObject *v14; // [esp+Ch] [ebp-14h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  if ( !this->RegisterClass(this, a2: pClassDesc) )
    return nullptr;
  m_LuaState = this->m_LuaState;
  if ( m_LuaState->l_G->totalbytes >= m_LuaState->l_G->GCthreshold )
    luaC_step(L: (GCObject *)this->m_LuaState);
  ci = m_LuaState->ci;
  if ( ci == m_LuaState->base_ci )
    gc = m_LuaState->l_gt.value.gc;
  else
    gc = (GCObject *)ci->func->value.gc->ts.tsv.keyhash;
  l_G = m_LuaState->l_G;
  v14 = gc;
  v9 = (int)l_G->frealloc(a1: l_G->ud, a2: nullptr, a3: 0, a4: 96u);
  if ( v9 == 0 )
    luaD_throw(L: m_LuaState, errcode: 4);
  l_G->totalbytes += 96;
  *(_BYTE *)(v9 + 5) = m_LuaState->l_G->currentwhite & 3;
  *(_DWORD *)(v9 + 12) = v14;
  *(_DWORD *)(v9 + 16) = 72;
  *(_DWORD *)(v9 + 8) = 0;
  *(_BYTE *)(v9 + 4) = 7;
  *(_DWORD *)v9 = m_LuaState->l_G->mainthread->next;
  m_LuaState->l_G->mainthread->next = (GCObject *)v9;
  top = (int *)m_LuaState->top;
  top[2] = 7;
  *top = v9;
  ++m_LuaState->top;
  *(_DWORD *)(v9 + 24) = pInstance;
  *(_DWORD *)(v9 + 28) = pClassDesc;
  v11 = this->m_LuaState;
  p_l_registry = (Node *)&v11->l_G->l_registry;
  key.value.b = (int)luaS_newlstr(
                       L: v11,
                       str: (char *)pClassDesc->m_pszScriptName,
                       l: strlen(pClassDesc->m_pszScriptName));
  v13 = v11->top;
  key.tt = 4;
  luaV_gettable(L: v11, t: p_l_registry, &key, val: v13);
  ++v11->top;
  lua_setmetatable(L: this->m_LuaState, objindex: -2);
  return (HSCRIPT__ *)luaL_ref(L: this->m_LuaState);
}

//------------------------------------------------------------------------------
// Address: 0x10025360
// Name: public: virtual void CLuaVM::SetInstanceUniqeId(struct HSCRIPT__ __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLuaVM::SetInstanceUniqeId(CLuaVM *this, HSCRIPT__ *hInstance, HSCRIPT__ *pszId)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10025380
// Name: public: virtual struct HSCRIPT__ __near * CLuaVM::CreateScope(char const __near *,struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__thiscall CLuaVM::CreateScope(CLuaVM *this, const char *pszScope, HSCRIPT__ *hParent)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10025390
// Name: public: virtual bool CLuaVM::GenerateUniqueKey(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLuaVM::GenerateUniqueKey(CLuaVM *this, const char *pszRoot, char *pBuf, int nBufSize)
{
  unsigned int m_iUniqueIdSerialNumber_high; // edx
  unsigned int m_iUniqueIdSerialNumber; // esi
  int v6; // eax
  unsigned __int64 v8; // [esp-Ch] [ebp-14h]

  m_iUniqueIdSerialNumber_high = HIDWORD(this->m_iUniqueIdSerialNumber);
  m_iUniqueIdSerialNumber = this->m_iUniqueIdSerialNumber;
  LODWORD(this->m_iUniqueIdSerialNumber) = m_iUniqueIdSerialNumber + 1;
  v8 = __PAIR64__(m_iUniqueIdSerialNumber_high, m_iUniqueIdSerialNumber);
  HIDWORD(this->m_iUniqueIdSerialNumber) = __CFADD__(m_iUniqueIdSerialNumber, 1) + m_iUniqueIdSerialNumber_high;
  v6 = _RandomInt(a1: 0, a2: 4095);
  V_snprintf(pDest: pBuf, maxLen: nBufSize, pFormat: "_%x%I64x_%s", v6, v8, pszRoot);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100253E0
// Name: public: virtual bool CLuaVM::ValueExists(struct HSCRIPT__ __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLuaVM::ValueExists(CLuaVM *this, HSCRIPT__ *hScope, char *pszKey)
{
  lua_State *m_LuaState; // esi
  lua_State *v5; // ecx
  lua_TValue *v6; // eax
  int tt; // eax
  lua_TValue *top; // [esp-10h] [ebp-30h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  m_LuaState = this->m_LuaState;
  key.value.b = (int)luaS_newlstr(L: m_LuaState, str: pszKey, l: strlen(pszKey));
  top = m_LuaState->top;
  key.tt = 4;
  luaV_gettable(L: m_LuaState, t: (Node *)&m_LuaState->l_gt, &key, val: top);
  ++m_LuaState->top;
  v5 = this->m_LuaState;
  v6 = v5->top - 1;
  if ( v6 == &luaO_nilobject_ )
  {
    --v5->top;
    return true;
  }
  else
  {
    tt = v6->tt;
    --v5->top;
    return tt != 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025470
// Name: public: virtual bool CLuaVM::SetValue(struct HSCRIPT__ __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLuaVM::SetValue(CLuaVM *this, HSCRIPT__ *hScope, HSCRIPT__ *pszKey, const char *pszValue)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10025480
// Name: public: virtual bool CLuaVM::SetValue(struct HSCRIPT__ __near *,char const __near *,struct ScriptVariant_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLuaVM::SetValue(CLuaVM *this, HSCRIPT__ *hScope, const char *pszKey, const ScriptVariant_t *value)
{
  lua_State *m_LuaState; // ebx
  lua_State *v6; // esi
  lua_State *v8; // edi

  if ( hScope != nullptr )
  {
    m_LuaState = this->m_LuaState;
    *m_LuaState->top++ = luaH_getnum(t: (Table *)m_LuaState->l_G->l_registry.value.gc, key: (int)hScope)->i_val;
    lua_pushstring(L: this->m_LuaState, s: pszKey);
    CLuaVM::PushVariant(pState: (GCObject *)this->m_LuaState, value);
    v6 = this->m_LuaState;
    luaV_settable(L: v6, t: (Node *)&v6->top[-3], key: v6->top - 2, val: v6->top - 1);
    v6->top -= 2;
    --this->m_LuaState->top;
  }
  else
  {
    lua_pushstring(L: this->m_LuaState, s: pszKey);
    CLuaVM::PushVariant(pState: (GCObject *)this->m_LuaState, value);
    v8 = this->m_LuaState;
    luaV_settable(L: v8, t: (Node *)&v8->l_gt, key: v8->top - 2, val: v8->top - 1);
    v8->top -= 2;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025550
// Name: public: virtual bool CLuaVM::SetValue(struct HSCRIPT__ __near *,int,struct ScriptVariant_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLuaVM::SetValue(CLuaVM *this, HSCRIPT__ *hScope, int nIndex, const ScriptVariant_t *value)
{
  lua_State *m_LuaState; // ebx
  lua_State *v6; // eax
  lua_TValue *top; // ecx
  lua_State *v8; // edi

  m_LuaState = this->m_LuaState;
  *m_LuaState->top++ = luaH_getnum(t: (Table *)m_LuaState->l_G->l_registry.value.gc, key: (int)hScope)->i_val;
  v6 = this->m_LuaState;
  top = v6->top;
  top->value.n = (double)nIndex;
  top->tt = 3;
  ++v6->top;
  CLuaVM::PushVariant(pState: (GCObject *)this->m_LuaState, value);
  v8 = this->m_LuaState;
  luaV_settable(L: v8, t: (Node *)&v8->top[-3], key: v8->top - 2, val: v8->top - 1);
  v8->top -= 2;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100255E0
// Name: public: virtual void CLuaVM::CreateTable(struct ScriptVariant_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLuaVM::CreateTable(CLuaVM *this, ScriptVariant_t *Result)
{
  lua_createtable(L: this->m_LuaState, narray: 0);
  CLuaVM::ConvertToVariant(pState: (GCObject *)this->m_LuaState, nStackIndex: -1, pReturn: Result);
}

//------------------------------------------------------------------------------
// Address: 0x10025610
// Name: public: virtual int CLuaVM::GetNumTableEntries(struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLuaVM::GetNumTableEntries(CLuaVM *this, HSCRIPT__ *hScope)
{
  CLuaVM *v3; // ebx
  lua_State *m_LuaState; // edi
  lua_State *v6; // eax
  lua_State *v7; // ebx
  int nCount; // [esp+10h] [ebp+8h]

  v3 = this;
  if ( hScope == (HSCRIPT__ *)-1 )
    return 0;
  m_LuaState = this->m_LuaState;
  nCount = 0;
  *m_LuaState->top++ = luaH_getnum(t: (Table *)m_LuaState->l_G->l_registry.value.gc, key: (int)hScope)->i_val;
  v6 = v3->m_LuaState;
  v6->top->tt = 0;
  ++v6->top;
  while ( 1 )
  {
    v7 = v3->m_LuaState;
    if ( luaH_next(L: v7, t: (Table *)v7->top[-2].value.gc, key: (TKey *)&v7->top[-1]) == 0 )
      break;
    ++v7->top;
    ++nCount;
    --this->m_LuaState->top;
    v3 = this;
  }
  --v7->top;
  --this->m_LuaState->top;
  return nCount;
}

//------------------------------------------------------------------------------
// Address: 0x100256C0
// Name: public: virtual int CLuaVM::GetKeyValue(struct HSCRIPT__ __near *,int,struct ScriptVariant_t __near *,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLuaVM::GetKeyValue(
        CLuaVM *this,
        HSCRIPT__ *hScope,
        int nIterator,
        ScriptVariant_t *pKey,
        ScriptVariant_t *pValue)
{
  lua_State *m_LuaState; // edi
  lua_State *v7; // eax
  unsigned int nStackSize; // [esp+Ch] [ebp-8h]
  int nCount; // [esp+10h] [ebp-4h]
  lua_State *hScopea; // [esp+1Ch] [ebp+8h]

  m_LuaState = this->m_LuaState;
  nStackSize = (unsigned int)((char *)m_LuaState->stack_last - (char *)m_LuaState->top) >> 4;
  nCount = 0;
  *m_LuaState->top++ = luaH_getnum(t: (Table *)m_LuaState->l_G->l_registry.value.gc, key: (int)hScope)->i_val;
  v7 = this->m_LuaState;
  v7->top->tt = 0;
  ++v7->top;
  while ( 1 )
  {
    hScopea = this->m_LuaState;
    if ( luaH_next(L: hScopea, t: (Table *)hScopea->top[-2].value.gc, key: (TKey *)&hScopea->top[-1]) == 0 )
      break;
    ++hScopea->top;
    if ( nCount >= nIterator )
      goto LABEL_6;
    ++nCount;
    --this->m_LuaState->top;
  }
  --hScopea->top;
LABEL_6:
  CLuaVM::ConvertToVariant(pState: (GCObject *)this->m_LuaState, nStackIndex: -2, pReturn: pKey);
  CLuaVM::ConvertToVariant(pState: (GCObject *)this->m_LuaState, nStackIndex: -1, pReturn: pValue);
  this->m_LuaState->top -= 3;
  lua_settop(
    L: this->m_LuaState,
    idx: ((unsigned int)((char *)this->m_LuaState->stack_last - (char *)this->m_LuaState->top) >> 4) - nStackSize - 1);
  return nCount + 1;
}

//------------------------------------------------------------------------------
// Address: 0x100257B0
// Name: public: virtual bool CLuaVM::GetValue(struct HSCRIPT__ __near *,char const __near *,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLuaVM::GetValue(CLuaVM *this, HSCRIPT__ *hScope, char *pszKey, ScriptVariant_t *pValue)
{
  unsigned int v5; // edi
  lua_State *m_LuaState; // edi
  lua_State *v7; // esi
  Node *v8; // edi
  GCObject *v9; // ecx
  lua_TValue *v10; // eax
  lua_State *v12; // esi
  lua_TValue *v13; // eax
  lua_TValue *top; // [esp-4h] [ebp-2Ch]
  lua_TValue *v15; // [esp-4h] [ebp-2Ch]
  int nStackSize; // [esp+10h] [ebp-18h]
  lua_TValue key; // [esp+18h] [ebp-10h] BYREF

  v5 = (unsigned int)((char *)this->m_LuaState->stack_last - (char *)this->m_LuaState->top) >> 4;
  nStackSize = v5;
  if ( hScope != nullptr )
  {
    m_LuaState = this->m_LuaState;
    *m_LuaState->top++ = luaH_getnum(t: (Table *)m_LuaState->l_G->l_registry.value.gc, key: (int)hScope)->i_val;
    v7 = this->m_LuaState;
    v8 = (Node *)&v7->top[-1];
    key.value.b = (int)luaS_newlstr(L: v7, str: pszKey, l: strlen(pszKey));
    top = v7->top;
    key.tt = 4;
    luaV_gettable(L: v7, t: v8, &key, val: top);
    ++v7->top;
    v9 = (GCObject *)this->m_LuaState;
    v10 = (lua_TValue *)(v9->ts.tsv.hash - 16);
    if ( v10 != &luaO_nilobject_ && v10->tt == 0 )
    {
      lua_settop(L: (lua_State *)v9, idx: ((v9->h.sizearray - v9->ts.tsv.hash) >> 4) - nStackSize - 1);
      return 0;
    }
  }
  else
  {
    v12 = this->m_LuaState;
    key.value.b = (int)luaS_newlstr(L: v12, str: pszKey, l: strlen(pszKey));
    v15 = v12->top;
    key.tt = 4;
    luaV_gettable(L: v12, t: (Node *)&v12->l_gt, &key, val: v15);
    ++v12->top;
    v9 = (GCObject *)this->m_LuaState;
    v13 = (lua_TValue *)(v9->ts.tsv.hash - 16);
    if ( v13 != &luaO_nilobject_ && v13->tt == 0 )
    {
      lua_settop(L: (lua_State *)v9, idx: ((v9->h.sizearray - v9->ts.tsv.hash) >> 4) - v5 - 1);
      return 0;
    }
  }
  CLuaVM::ConvertToVariant(pState: v9, nStackIndex: -1, pReturn: pValue);
  lua_settop(
    L: this->m_LuaState,
    idx: ((unsigned int)((char *)this->m_LuaState->stack_last - (char *)this->m_LuaState->top) >> 4) - nStackSize - 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025950
// Name: public: virtual bool CLuaVM::GetValue(struct HSCRIPT__ __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLuaVM::GetValue(CLuaVM *this, HSCRIPT__ *hScope, int nIndex, ScriptVariant_t *pValue)
{
  lua_State *m_LuaState; // edi
  unsigned int v5; // ebx
  lua_TValue *top; // edi
  Node *v7; // eax
  GCObject *v8; // edi
  lua_TValue *v9; // eax
  lua_State *hScopea; // [esp+Ch] [ebp+8h]

  if ( hScope == nullptr )
    return 0;
  m_LuaState = this->m_LuaState;
  v5 = (unsigned int)((char *)m_LuaState->stack_last - (char *)m_LuaState->top) >> 4;
  *m_LuaState->top++ = luaH_getnum(t: (Table *)m_LuaState->l_G->l_registry.value.gc, key: (int)hScope)->i_val;
  top = this->m_LuaState->top;
  hScopea = this->m_LuaState;
  v7 = luaH_getnum(t: (Table *)top[-1].value.gc, key: nIndex);
  top->value = v7->i_val.value;
  top->tt = v7->i_val.tt;
  ++hScopea->top;
  v8 = (GCObject *)this->m_LuaState;
  v9 = (lua_TValue *)(v8->ts.tsv.hash - 16);
  if ( v9 == &luaO_nilobject_ || v9->tt != 0 )
  {
    CLuaVM::ConvertToVariant(pState: v8, nStackIndex: -1, pReturn: pValue);
    lua_settop(
      L: this->m_LuaState,
      idx: ((unsigned int)((char *)this->m_LuaState->stack_last - (char *)this->m_LuaState->top) >> 4) - v5 - 1);
    return 1;
  }
  else
  {
    lua_settop(L: this->m_LuaState, idx: ((v8->h.sizearray - v8->ts.tsv.hash) >> 4) - v5 - 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025A30
// Name: public: virtual void CLuaVM::ReleaseValue(struct ScriptVariant_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLuaVM::ReleaseValue(CLuaVM *this, ScriptVariant_t *value)
{
  CLuaVM::ReleaseVariant(value, pState: this->m_LuaState);
}

//------------------------------------------------------------------------------
// Address: 0x10025A50
// Name: public: virtual bool CLuaVM::ClearValue(struct HSCRIPT__ __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLuaVM::ClearValue(CLuaVM *this, HSCRIPT__ *hScope, HSCRIPT__ *pszKey)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10025A60
// Name: public: virtual bool CLuaVM::RaiseException(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLuaVM::RaiseException(CLuaVM *this, const char *pszExceptionText)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025A70
// Name: public: virtual void CLuaVM::SetOutputCallback(void (*)(char const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLuaVM::SetOutputCallback(CLuaVM *this, void (__cdecl *pFunc)(const char *))
{
  GCObject *m_LuaState; // esi
  _DWORD *hash; // ebx
  lua_State *v5; // esi
  CallInfo *ci; // eax
  GCObject *gc; // eax
  global_State *l_G; // ebx
  int v9; // eax
  unsigned __int8 currentwhite; // dl
  int *top; // ecx
  lua_State *v12; // esi
  GCObject *v13; // [esp+Ch] [ebp-4h]

  m_LuaState = (GCObject *)this->m_LuaState;
  this->m_OutputFunc = pFunc;
  if ( *(_DWORD *)(m_LuaState->ts.tsv.len + 68) >= *(_DWORD *)(m_LuaState->ts.tsv.len + 64) )
    luaC_step(L: m_LuaState);
  hash = (_DWORD *)m_LuaState->ts.tsv.hash;
  *hash = luaS_newlstr(L: (lua_State *)m_LuaState, str: "print", l: 5u);
  hash[2] = 4;
  m_LuaState->ts.tsv.hash += 16;
  v5 = this->m_LuaState;
  if ( v5->l_G->totalbytes >= v5->l_G->GCthreshold )
    luaC_step(L: (GCObject *)this->m_LuaState);
  ci = v5->ci;
  if ( ci == v5->base_ci )
    gc = v5->l_gt.value.gc;
  else
    gc = (GCObject *)ci->func->value.gc->ts.tsv.keyhash;
  l_G = v5->l_G;
  v13 = gc;
  v9 = (int)l_G->frealloc(a1: l_G->ud, a2: nullptr, a3: 0, a4: 28u);
  if ( v9 == 0 )
    luaD_throw(L: v5, errcode: 4);
  l_G->totalbytes += 28;
  currentwhite = v5->l_G->currentwhite;
  *(_DWORD *)(v9 + 16) = 4;
  *(_DWORD *)(v9 + 8) = 0;
  *(_DWORD *)(v9 + 12) = v13;
  *(_BYTE *)(v9 + 5) = currentwhite & 3;
  *(_BYTE *)(v9 + 4) = 7;
  *(_DWORD *)v9 = v5->l_G->mainthread->next;
  v5->l_G->mainthread->next = (GCObject *)v9;
  top = (int *)v5->top;
  *top = v9;
  top[2] = 7;
  ++v5->top;
  *(_DWORD *)(v9 + 24) = this->m_OutputFunc;
  lua_pushcclosure(L: this->m_LuaState, fn: (int (__cdecl *)(lua_State *))CLuaVM::PrintFunc, n: 1);
  v12 = this->m_LuaState;
  luaV_settable(L: v12, t: (Node *)&v12->l_gt, key: v12->top - 2, val: v12->top - 1);
  v12->top -= 2;
}

//------------------------------------------------------------------------------
// Address: 0x10025BA0
// Name: public: virtual void CLuaVM::SetErrorCallback(bool (*)(enum ScriptErrorLevel_t,char const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLuaVM::SetErrorCallback(CLuaVM *this, bool (__cdecl *pFunc)(ScriptErrorLevel_t, const char *))
{
  this->m_ErrorFunc = pFunc;
}

//------------------------------------------------------------------------------
// Address: 0x10025BB0
// Name: public: int CUtlVector<struct ScriptVariant_t,class CUtlMemoryFixed<struct ScriptVariant_t,14,0>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CUtlVector<ScriptVariant_t,CUtlMemoryFixed<ScriptVariant_t,14,0>>::InsertMultipleBefore@<eax>(
        CUtlVector<ScriptVariant_t,CUtlMemoryFixed<ScriptVariant_t,14,0> > *this@<esi>,
        int num@<eax>,
        int elem)
{
  int v3; // edi
  int v4; // eax
  char *v5; // eax

  v3 = num;
  if ( num != 0 )
  {
    this->m_Size += num;
    v4 = this->m_Size - elem - num;
    this->m_pElements = (ScriptVariant_t *)this;
    if ( v4 > 0 )
    {
      if ( v3 <= 0 )
        return elem;
      _V_memmove(dest: (char *)this + 8 * elem + 8 * v3, src: (char *)this + 8 * elem, count: 8 * v4);
    }
    if ( v3 > 0 )
    {
      v5 = &this->m_Memory.m_Memory[8 * elem];
      do
      {
        if ( v5 != nullptr )
        {
          *((_DWORD *)v5 + 1) = 0;
          *(_DWORD *)v5 = 0;
        }
        v5 += 8;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10025EF0
// Name: public: CUtlVector<int,class CUtlMemory<int,int>>::~CUtlVector<int,class CUtlMemory<int,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlVector<int,CUtlMemory<int,int>>::~CUtlVector<int,CUtlMemory<int,int>>(
        CUtlVector<int,CUtlMemory<int,int> > *this@<ecx>,
        int a2@<esi>)
{
  bool v2; // sf
  void *v3; // eax

  v2 = *(int *)(a2 + 8) < 0;
  *(_DWORD *)(a2 + 12) = 0;
  if ( !v2 )
  {
    if ( *(_DWORD *)a2 != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)a2);
      *(_DWORD *)a2 = 0;
    }
    *(_DWORD *)(a2 + 4) = 0;
  }
  v2 = *(int *)(a2 + 8) < 0;
  v3 = *(void **)a2;
  *(_DWORD *)(a2 + 16) = *(_DWORD *)a2;
  if ( !v2 )
  {
    if ( v3 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
      *(_DWORD *)a2 = 0;
    }
    *(_DWORD *)(a2 + 4) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005CF90
// Name: public: CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::~CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(
        CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *this)
{
  bool v2; // sf
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}
