// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/squirrel/squirrel/sqcompiler.cpp
// Functions: 49
// ============================================================

#include "vscript\languages\squirrel\squirrel\sqcompiler.h"

//------------------------------------------------------------------------------
// Address: 0x1003DDD0
// Name: public: SQCompiler::SQCompiler(struct SQVM __near *,int (*)(void __near *),void __near *,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
SQCompiler *__userpurge SQCompiler::SQCompiler@<eax>(
        SQCompiler *this@<esi>,
        int (__cdecl *up)(void *)@<eax>,
        SQVM *v,
        int (__cdecl *rg)(void *),
        const char *sourcename,
        bool raiseerror,
        bool lineinfo)
{
  SQString *v7; // edi
  tagSQObjectType type; // eax
  _DWORD *v9; // ecx
  void *v11; // [esp+0h] [ebp-8h]
  void (__cdecl *v12)(void *, const char *); // [esp+4h] [ebp-4h]
  SQSharedState *va; // [esp+10h] [ebp+8h]

  this->_sourcename._type = OT_NULL;
  this->_sourcename._unVal.nInteger = 0;
  this->_lex._longstr._vals = nullptr;
  this->_lex._longstr._size = 0;
  this->_lex._longstr._allocated = 0;
  this->_expstates._vals = nullptr;
  this->_expstates._size = 0;
  this->_expstates._allocated = 0;
  this->_vm = v;
  SQLexer::Init(this: &this->_lex, ss: v->_sharedstate, rg: up, up: v11, efunc: v12, ed: this);
  va = v->_sharedstate;
  v7 = StringTable::Add(this: va->_stringtable, news: (const char *)rg, len: -1);
  v7->_sharedstate = va;
  ++v7->_uiRef;
  type = this->_sourcename._type;
  v9 = &this->_sourcename._unVal.pTable->__vftable;
  this->_sourcename._unVal.nInteger = (int)v7;
  this->_sourcename._type = OT_STRING;
  ++v7->_uiRef;
  if ( (type & 0x8000000) != 0 && (int)--v9[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
  if ( --v7->_uiRef <= 0 )
    v7->Release(this: v7);
  this->compilererror = nullptr;
  this->_lineinfo = raiseerror;
  this->_raiseerror = (char)sourcename;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003DE90
// Name: public: static void SQCompiler::ThrowError(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn SQCompiler::ThrowError(void *ud, SQCompiler *s)
{
  const char *savedregs; // [esp+0h] [ebp+0h]

  SQCompiler::Error(this: s, s: savedregs);
}

//------------------------------------------------------------------------------
// Address: 0x1003DEA0
// Name: public: void SQCompiler::Error(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void __usercall __noreturn SQCompiler::Error(int a1@<eax>, SQCompiler *this, const char *s, ...)
{
  vsprintf(string: `SQCompiler::Error'::`2'::temp, format: (const char *)this, ap: (char *)&s);
  *(_DWORD *)(a1 + 112) = `SQCompiler::Error'::`2'::temp;
  longjmp(Buf: (int *)(a1 + 116), Value: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1003DED0
// Name: public: bool SQCompiler::IsEndOfStatement(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall SQCompiler::IsEndOfStatement@<eax>(SQCompiler *this@<ecx>, int *a2@<eax>)
{
  int v2; // eax
  BOOL result; // eax

  result = true;
  if ( a2[6] != 10 )
  {
    v2 = *a2;
    if ( v2 != 0 && v2 != 125 && v2 != 59 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003DEF0
// Name: public: bool SQCompiler::Compile(struct SQObjectPtr __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SQCompiler::Compile(SQCompiler *this, SQCompiler *o, SQObjectPtr *oa)
{
  tagSQObjectValue v3; // eax
  SQSharedState *sharedstate; // edi
  SQString *v5; // esi
  tagSQObjectType type; // eax
  _DWORD *v7; // ecx
  const tagSQObject *v8; // esi
  sqvector<SQObjectPtr> *v9; // ecx
  _DWORD *v10; // edi
  tagSQObjectValue v11; // eax
  int v12; // esi
  _DWORD *v13; // ecx
  tagSQObjectType v14; // edx
  SQLexer *v15; // ecx
  tagSQObjectType v16; // eax
  SQLexer *prevtoken; // ecx
  tagSQObjectType token; // eax
  SQFuncState *v20; // ecx
  SQFuncState *v21; // esi
  SQFuncState *v22; // ecx
  SQFunctionProto *v23; // esi
  tagSQObjectType v24; // edx
  _DWORD *v25; // ecx
  tagSQObjectValue v27; // ecx
  void (__cdecl *v28)(tagSQObjectValue, char *, const char *, int, int); // edx
  const char *v29; // eax
  SQSharedState *v30; // edi
  SQString *v31; // esi
  _DWORD *v32; // eax
  int v33; // edx
  _DWORD *v34; // ecx
  _EXCEPTION_REGISTRATION_RECORD *v35; // [esp+0h] [ebp-128h]
  const char *v36; // [esp+0h] [ebp-128h]
  int v37; // [esp+4h] [ebp-124h]
  SQFuncState funcstate; // [esp+10h] [ebp-118h] BYREF
  int len; // [esp+108h] [ebp-20h] BYREF
  SQObjectPtr val; // [esp+110h] [ebp-18h] BYREF
  SQFuncState *fs; // [esp+118h] [ebp-10h]
  SQInstruction i; // [esp+11Ch] [ebp-Ch] BYREF
  int stacksize; // [esp+124h] [ebp-4h]
  int savedregs; // [esp+128h] [ebp+0h] BYREF

  v3.pTable = (SQTable *)o->_vm;
  o->_debugline = 1;
  o->_debugop = 0;
  SQFuncState::SQFuncState(
    this: *(SQFuncState **)(v3.nInteger + 148),
    ss: *(SQSharedState **)(v3.nInteger + 148),
    parent: nullptr,
    efunc: (void (__cdecl *)(void *, const char *))SQCompiler::ThrowError,
    ed: o);
  sharedstate = o->_vm->_sharedstate;
  v5 = StringTable::Add(this: sharedstate->_stringtable, news: "main", len: -1);
  v5->_sharedstate = sharedstate;
  ++v5->_uiRef;
  type = funcstate._name._type;
  v7 = &funcstate._name._unVal.pTable->__vftable;
  funcstate._name._unVal.nInteger = (int)v5;
  funcstate._name._type = OT_STRING;
  ++v5->_uiRef;
  if ( (type & 0x8000000) != 0 && (int)--v7[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
  if ( --v5->_uiRef <= 0 )
    v5->Release(this: v5);
  o->_fs = &funcstate;
  v8 = (const tagSQObject *)SQFuncState::CreateString(
                              this: &funcstate,
                              s: (const char *)&stru_1009C274._lex._longstr,
                              (int)&len)._type;
  fs = o->_fs;
  SQFuncState::PushLocalVariable(this: fs, name: v8);
  v10 = &v8->_unVal.pTable->__vftable;
  val._type = v8->_type;
  val._unVal.nInteger = (int)v10;
  stacksize = val._type & 0x8000000;
  if ( (val._type & 0x8000000) != 0 )
    ++v10[1];
  sqvector<SQObjectPtr>::push_back(this: v9, a2: (int)&fs->_parameters, &val);
  if ( stacksize != 0 && (int)--v10[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10);
  v11.pTable = (SQTable *)o->_fs;
  v12 = *(_DWORD *)(v11.nInteger + 144);
  v13 = *(_DWORD **)(v11.nInteger + 148);
  *(_DWORD *)(v11.nInteger + 148) = o->_sourcename._unVal.pTable;
  v14 = o->_sourcename._type;
  *(_DWORD *)(v11.nInteger + 144) = v14;
  if ( (v14 & 0x8000000) != 0 )
    ++*(_DWORD *)(*(_DWORD *)(v11.nInteger + 148) + 4);
  if ( (v12 & 0x8000000) != 0 && (int)--v13[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v13 + 8))(a1: v13);
  stacksize = o->_fs->_vlocals._size;
  if ( _setjmp3(
         a1: (int)o->_errorjmp,
         a2: (int)&savedregs,
         a3: (int)v10,
         a4: v12,
         a5: o->_errorjmp,
         a6: 0,
         a7: v35,
         a8: v37) != 0 )
  {
    if ( o->_raiseerror )
    {
      v27.pTable = (SQTable *)o->_vm;
      v28 = *(void (__cdecl **)(tagSQObjectValue, char *, const char *, int, int))(*(_DWORD *)(v27.nInteger + 148) + 160);
      if ( v28 != nullptr )
      {
        if ( o->_sourcename._type == OT_STRING )
          v29 = (const char *)(o->_sourcename._unVal.nInteger + 28);
        else
          v29 = "unknown";
        ((void (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v28)(
          a1: (tagSQObjectValue)v27.nInteger,
          a2: o->compilererror,
          a3: v29,
          a4: o->_lex._currentline,
          a5: o->_lex._currentcolumn);
      }
    }
    v30 = o->_vm->_sharedstate;
    v31 = StringTable::Add(this: v30->_stringtable, news: o->compilererror, len: -1);
    v31->_sharedstate = v30;
    ++v31->_uiRef;
    v32 = &o->_vm->__vftable;
    v33 = v32[18];
    v34 = (_DWORD *)v32[19];
    v32 += 18;
    v32[1] = v31;
    *v32 = 134217744;
    ++v31->_uiRef;
    if ( (v33 & 0x8000000) != 0 && (int)--v34[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v34 + 8))(a1: v34);
    if ( --v31->_uiRef <= 0 )
      v31->Release(this: v31);
    SQFuncState::~SQFuncState(this: &funcstate);
    return 0;
  }
  else
  {
    v16 = SQLexer::Lex(this: v15);
    o->_token = v16;
    while ( o->_token > 0 )
    {
      SQCompiler::Statement(this: o);
      prevtoken = (SQLexer *)o->_lex._prevtoken;
      if ( prevtoken != (SQLexer *)125 )
      {
        token = o->_token;
        if ( o->_token == 59 )
        {
          o->_token = SQLexer::Lex(this: prevtoken);
        }
        else if ( prevtoken != (SQLexer *)10 && token != 0 && token != 125 )
        {
          SQCompiler::Error(a1: (int)o, this: (SQCompiler *)&stru_1009C274._lex._lasttokenline, s: v36);
        }
      }
    }
    v20 = (SQFuncState *)stacksize;
    if ( o->_fs->_vlocals._size != stacksize )
      SQFuncState::SetStackSize(this: (SQFuncState *)stacksize, n: (int)v36);
    SQFuncState::AddLineInfos(this: v20, line: o->_lex._currentline, lineop: o->_lineinfo, force: true);
    v21 = o->_fs;
    i._arg1 = 0;
    *(_DWORD *)&i.op = 65299;
    SQFuncState::AddInstruction(this: v21, &i);
    SQFuncState::SetStackSize(this: nullptr, n: (int)v36);
    v23 = SQFuncState::BuildProto(this: v22);
    ++v23->_uiRef;
    v24 = oa->_type;
    v25 = &oa->_unVal.pTable->__vftable;
    oa->_unVal.nInteger = (int)v23;
    oa->_type = OT_FUNCPROTO;
    ++v23->_uiRef;
    if ( (v24 & 0x8000000) != 0 && (int)--v25[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v25 + 8))(a1: v25);
    if ( --v23->_uiRef <= 0 )
      v23->Release(this: v23);
    SQFuncState::~SQFuncState(this: &funcstate);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E250
// Name: public: void SQCompiler::Statements(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQCompiler::Statements(SQCompiler *this@<ecx>, SQCompiler *a2@<esi>)
{
  SQLexer *prevtoken; // ecx
  int token; // eax

  while ( a2->_token != 125 )
  {
    if ( a2->_token == 301 || a2->_token == 300 )
      break;
    SQCompiler::Statement(this: a2);
    prevtoken = (SQLexer *)a2->_lex._prevtoken;
    if ( prevtoken != (SQLexer *)125 && prevtoken != (SQLexer *)59 )
    {
      token = a2->_token;
      if ( a2->_token == 59 )
      {
        a2->_token = SQLexer::Lex(this: prevtoken);
      }
      else if ( prevtoken != (SQLexer *)10 && token != 0 && token != 125 )
      {
        SQCompiler::Error(a1: (int)a2, this: (SQCompiler *)&stru_1009C274._lex._lasttokenline, s: (const char *)this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E2B0
// Name: public: void SQCompiler::Statement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::Statement(SQCompiler *this)
{
  __int32 currentline; // edx
  bool lineinfo; // al
  SQFuncState *fs; // esi
  unsigned int size; // eax
  int v6; // edi
  SQLineInfo *v7; // eax
  unsigned int v8; // ecx
  SQLineInfo *v9; // eax
  tagSQObjectValue v10; // ecx
  SQLexer *token; // ecx
  int v12; // eax
  SQFuncState *v13; // eax
  SQCompiler *v14; // ecx
  SQFuncState *v15; // esi
  int v16; // eax
  SQFuncState *v17; // ecx
  unsigned __int8 v18; // dl
  SQFuncState *v19; // esi
  int traps; // eax
  unsigned __int8 v21; // cl
  SQFuncState *v22; // esi
  SQFuncState *v23; // esi
  unsigned int v24; // edx
  int *vals; // eax
  unsigned __int8 v26; // al
  SQFuncState *v27; // esi
  SQLexer *v28; // ecx
  SQFuncState *v29; // esi
  unsigned int v30; // eax
  int *v31; // ecx
  unsigned __int8 v32; // cl
  SQFuncState *v33; // esi
  SQLexer *v34; // ecx
  SQCompiler *v35; // ecx
  SQLexer *v36; // ecx
  int v37; // eax
  SQFuncState *v38; // ecx
  SQFuncState *v39; // ecx
  unsigned __int8 v40; // al
  SQFuncState *v41; // esi
  SQFuncState *v42; // ecx
  int v43; // eax
  const char *svalue; // eax
  SQFuncState *v45; // edi
  const SQObjectPtr *type; // eax
  SQLexer *v47; // ecx
  int v48; // eax
  SQLexer *v49; // ecx
  _DWORD *v50; // edi
  SQLexer *v51; // ecx
  int v52; // eax
  SQTable *pTable; // ecx
  tagSQObjectValue v54; // eax
  tagSQObjectType v55; // eax
  _DWORD *v56; // ecx
  tagSQObjectValue v57; // eax
  const char *v58; // [esp+0h] [ebp-38h]
  SQObjectPtr strongid; // [esp+10h] [ebp-28h] BYREF
  int stacksize; // [esp+18h] [ebp-20h] BYREF
  int v61; // [esp+1Ch] [ebp-1Ch]
  SQInstruction i; // [esp+20h] [ebp-18h] BYREF
  SQObjectPtr v63; // [esp+28h] [ebp-10h] BYREF
  tagSQObject val; // [esp+30h] [ebp-8h] BYREF

  currentline = this->_lex._currentline;
  lineinfo = this->_lineinfo;
  fs = this->_fs;
  strongid._type = currentline;
  if ( fs->_lastline != currentline )
  {
    val._unVal.nInteger = fs->_instructions._size;
    if ( lineinfo )
    {
      stacksize = currentline;
      v61 = 0;
      SQFuncState::AddInstruction(this: fs, i: (SQInstruction *)&stacksize);
      currentline = strongid._type;
    }
    size = fs->_lineinfos._size;
    if ( fs->_lineinfos._allocated <= size )
    {
      v6 = 2 * size;
      if ( 2 * size == 0 )
        v6 = 4;
      v7 = (SQLineInfo *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: fs->_lineinfos._vals, a3: 8 * v6);
      currentline = strongid._type;
      fs->_lineinfos._vals = v7;
      fs->_lineinfos._allocated = v6;
    }
    v8 = fs->_lineinfos._size;
    v9 = &fs->_lineinfos._vals[v8];
    fs->_lineinfos._size = v8 + 1;
    if ( v9 != nullptr )
    {
      v10.pTable = (SQTable *)val._unVal;
      v9->_line = currentline;
      v9->_op = v10.nInteger;
    }
    fs->_lastline = currentline;
  }
  token = (SQLexer *)this->_token;
  v12 = this->_token;
  if ( this->_token > 323 )
  {
    if ( v12 == 324 )
    {
      v43 = SQLexer::Lex(this: token);
      this->_token = v43;
      if ( v43 != 258 && v43 != 310 )
        SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C274, s: "IDENTIFIER");
      svalue = this->_lex._svalue;
      *(_DWORD *)&i.op = 0;
      v45 = this->_fs;
      i._arg1 = 16777217;
      type = (const SQObjectPtr *)SQFuncState::CreateString(this: v45, s: svalue, len: (int)&val)._type;
      SQObjectPtr::operator=(this: (SQObjectPtr *)&i, obj: type);
      v48 = SQLexer::Lex(this: v47);
      v50 = *(_DWORD **)&i.op;
      this->_token = v48;
      stacksize = i._arg1 & 0x8000000;
      if ( (i._arg1 & 0x8000000) != 0 && (int)--v50[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v50 + 8))(a1: v50);
      if ( this->_token != 61 )
        SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x3D);
      this->_token = SQLexer::Lex(this: v49);
      SQCompiler::ExpectScalar(this: (SQCompiler *)&val);
      v52 = this->_token;
      if ( this->_token == 59 )
      {
        this->_token = SQLexer::Lex(this: v51);
      }
      else if ( this->_lex._prevtoken != 10 && v52 != 0 && v52 != 125 )
      {
        SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C274._lex._lasttokenline, s: v58);
      }
      pTable = this->_vm->_sharedstate->_consts._unVal.pTable;
      strongid._type = i._arg1;
      strongid._unVal.nInteger = (int)v50;
      if ( stacksize != 0 )
        ++v50[1];
      v63 = (SQObjectPtr)val;
      if ( (val._type & 0x8000000) != 0 )
        ++*(_DWORD *)(val._unVal.nInteger + 4);
      SQTable::NewSlot(this: pTable, key: &strongid, val: &v63);
      if ( (v63._type & 0x8000000) != 0 )
      {
        v54.pTable = (SQTable *)v63._unVal;
        --*(_DWORD *)(v63._unVal.nInteger + 4);
        if ( *(int *)(v54.nInteger + 4) <= 0 )
          v63._unVal.pTable->Release(this: (struct SQTable *)v63._unVal.nInteger);
      }
      v55 = strongid._type;
      v56 = &strongid._unVal.pTable->__vftable;
      strongid._type = OT_NULL;
      strongid._unVal.nInteger = 0;
      if ( (v55 & 0x8000000) != 0 && (int)--v56[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v56 + 8))(a1: v56);
      if ( (strongid._type & 0x8000000) != 0 )
      {
        v57.pTable = (SQTable *)strongid._unVal;
        --*(_DWORD *)(strongid._unVal.nInteger + 4);
        if ( *(int *)(v57.nInteger + 4) <= 0 )
          strongid._unVal.pTable->Release(this: (struct SQTable *)strongid._unVal.nInteger);
      }
      this->_fs->_optimization = false;
    }
    else
    {
LABEL_54:
      SQCompiler::CommaExpr(this);
      SQFuncState::PopTarget(this: v42);
      this->_fs->_optimization = false;
    }
  }
  else if ( this->_token == 323 )
  {
    SQCompiler::EnumStatement(this: (SQCompiler *)token);
    this->_fs->_optimization = false;
  }
  else
  {
    switch ( v12 )
    {
      case 59:
        this->_token = SQLexer::Lex(this: token);
        this->_fs->_optimization = false;
        break;
      case 123:
        stacksize = this->_fs->_vlocals._size;
        this->_token = SQLexer::Lex(this: token);
        SQCompiler::Statements(this: v35, a2: this);
        if ( this->_token != 125 )
          SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x7D);
        v37 = SQLexer::Lex(this: v36);
        v38 = (SQFuncState *)stacksize;
        this->_token = v37;
        SQFuncState::SetStackSize(this: v38, n: (int)v58);
        this->_fs->_optimization = false;
        break;
      case 268:
        SQCompiler::SwitchStatement(this: (SQCompiler *)token);
        this->_fs->_optimization = false;
        break;
      case 272:
        SQCompiler::IfStatement(this: (SQCompiler *)token);
        this->_fs->_optimization = false;
        break;
      case 274:
        SQCompiler::WhileStatement(this: (SQCompiler *)token);
        this->_fs->_optimization = false;
        break;
      case 275:
        v23 = this->_fs;
        if ( v23->_breaktargets._size == 0 )
          SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C274._lex._longstr._allocated, s: v58);
        v24 = v23->_breaktargets._size;
        vals = v23->_breaktargets._vals;
        if ( vals[v24 - 1] > 0 )
        {
          v26 = vals[v24 - 1];
          i._arg1 = 0;
          i.op = 57;
          i._arg0 = v26;
          *(_WORD *)&i._arg2 = 0;
          SQFuncState::AddInstruction(this: v23, &i);
        }
        v27 = this->_fs;
        i._arg1 = -1234;
        *(_DWORD *)&i.op = 24;
        SQFuncState::AddInstruction(this: v27, &i);
        stacksize = this->_fs->_instructions._size - 1;
        sqvector<int>::push_back(this: (sqvector<int> *)stacksize, val: &stacksize);
        this->_token = SQLexer::Lex(this: v28);
        this->_fs->_optimization = false;
        break;
      case 276:
        SQCompiler::ForStatement(this: (SQCompiler *)token);
        this->_fs->_optimization = false;
        break;
      case 277:
        SQCompiler::DoWhileStatement(this: (SQCompiler *)token);
        this->_fs->_optimization = false;
        break;
      case 279:
        SQCompiler::ForEachStatement(this: (SQCompiler *)token);
        this->_fs->_optimization = false;
        break;
      case 283:
        SQCompiler::LocalDeclStatement(this: (SQCompiler *)token);
        this->_fs->_optimization = false;
        break;
      case 285:
        SQCompiler::FunctionStatement(this: (SQCompiler *)token);
        this->_fs->_optimization = false;
        break;
      case 286:
      case 292:
        if ( token == (SQLexer *)286 )
        {
          strongid._type = 19;
        }
        else
        {
          v13 = this->_fs;
          strongid._type = 49;
          v13->_bgenerator = true;
        }
        this->_token = SQLexer::Lex(this: token);
        if ( SQCompiler::IsEndOfStatement(this: v14, a2: &this->_token) )
        {
          if ( strongid._type == 19 )
          {
            v19 = this->_fs;
            traps = v19->_traps;
            if ( traps > 0 )
            {
              i._arg1 = 0;
              i.op = 57;
              i._arg0 = traps;
              *(_WORD *)&i._arg2 = 0;
              SQFuncState::AddInstruction(this: v19, &i);
            }
          }
          v21 = strongid._type;
          this->_fs->_returnexp = -1;
          i.op = v21;
          i._arg1 = 0;
          *(_WORD *)&i._arg0 = 255;
        }
        else
        {
          stacksize = this->_fs->_instructions._size;
          SQCompiler::CommaExpr(this);
          if ( strongid._type == 19 )
          {
            v15 = this->_fs;
            v16 = v15->_traps;
            if ( v16 > 0 )
            {
              i._arg1 = 0;
              i.op = 57;
              i._arg0 = v16;
              *(_WORD *)&i._arg2 = 0;
              SQFuncState::AddInstruction(this: v15, &i);
            }
          }
          v17 = (SQFuncState *)stacksize;
          v18 = strongid._type;
          this->_fs->_returnexp = stacksize;
          i.op = v18;
          i._arg1 = SQFuncState::PopTarget(this: v17);
          *(_WORD *)&i._arg0 = 1;
        }
        v22 = this->_fs;
        i._arg3 = 0;
        SQFuncState::AddInstruction(this: v22, &i);
        this->_fs->_optimization = false;
        break;
      case 291:
        v29 = this->_fs;
        if ( v29->_continuetargets._size == 0 )
          SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C274.compilererror, s: v58);
        v30 = v29->_continuetargets._size;
        v31 = v29->_continuetargets._vals;
        if ( v31[v30 - 1] > 0 )
        {
          v32 = v31[v30 - 1];
          i._arg1 = 0;
          i.op = 57;
          i._arg0 = v32;
          *(_WORD *)&i._arg2 = 0;
          SQFuncState::AddInstruction(this: v29, &i);
        }
        v33 = this->_fs;
        i._arg1 = -1234;
        *(_DWORD *)&i.op = 24;
        SQFuncState::AddInstruction(this: v33, &i);
        stacksize = this->_fs->_instructions._size - 1;
        sqvector<int>::push_back(this: (sqvector<int> *)&stacksize, val: &stacksize);
        this->_token = SQLexer::Lex(this: v34);
        this->_fs->_optimization = false;
        break;
      case 293:
        SQCompiler::TryCatchStatement(this: (SQCompiler *)token);
        this->_fs->_optimization = false;
        break;
      case 295:
        this->_token = SQLexer::Lex(this: token);
        SQCompiler::CommaExpr(this);
        i.op = 58;
        v40 = SQFuncState::PopTarget(this: v39);
        v41 = this->_fs;
        i._arg1 = 0;
        i._arg0 = v40;
        *(_WORD *)&i._arg2 = 0;
        SQFuncState::AddInstruction(this: v41, &i);
        this->_fs->_optimization = false;
        break;
      case 307:
        SQCompiler::ClassStatement(this: (SQCompiler *)token);
        this->_fs->_optimization = false;
        break;
      default:
        goto LABEL_54;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003EAB0
// Name: public: void SQCompiler::EmitDerefOp(enum SQOpcode)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::EmitDerefOp(SQCompiler *this, int op, unsigned __int8 opa)
{
  SQFuncState *v4; // ecx
  SQFuncState *v5; // ecx
  int v6; // esi
  SQFuncState *v7; // ecx
  unsigned __int8 v8; // al
  SQFuncState *v9; // esi
  SQInstruction i; // [esp+Ch] [ebp-Ch] BYREF
  int val; // [esp+14h] [ebp-4h]
  unsigned __int8 key; // [esp+20h] [ebp+8h]

  val = SQFuncState::PopTarget((SQFuncState *)this);
  key = SQFuncState::PopTarget(this: v4);
  v6 = SQFuncState::PopTarget(this: v5);
  i.op = opa;
  v8 = SQFuncState::PushTarget(this: v7, n: -1);
  i._arg1 = v6;
  v9 = *(SQFuncState **)(op + 4);
  i._arg0 = v8;
  i._arg2 = key;
  i._arg3 = val;
  SQFuncState::AddInstruction(this: v9, &i);
}

//------------------------------------------------------------------------------
// Address: 0x1003EB20
// Name: public: void SQCompiler::Emit2ArgsOP(enum SQOpcode,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::Emit2ArgsOP(SQCompiler *this, int op, unsigned __int8 p3, unsigned __int8 p3a)
{
  SQFuncState *v5; // ecx
  int v6; // esi
  SQFuncState *v7; // ecx
  unsigned __int8 v8; // al
  SQFuncState *v9; // esi
  SQInstruction i; // [esp+10h] [ebp-Ch] BYREF
  unsigned __int8 p2; // [esp+24h] [ebp+8h]

  p2 = SQFuncState::PopTarget((SQFuncState *)this);
  v6 = SQFuncState::PopTarget(this: v5);
  i.op = p3;
  v8 = SQFuncState::PushTarget(this: v7, n: -1);
  i._arg1 = v6;
  v9 = *(SQFuncState **)(op + 4);
  i._arg0 = v8;
  i._arg2 = p2;
  i._arg3 = p3a;
  SQFuncState::AddInstruction(this: v9, &i);
}

//------------------------------------------------------------------------------
// Address: 0x1003EB80
// Name: public: void SQCompiler::EmitCompoundArith(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQCompiler::EmitCompoundArith(int tok@<eax>, SQFuncState *a2@<ecx>, SQCompiler *this, bool deref)
{
  int v5; // eax
  SQFuncState *v6; // ecx
  bool v7; // zf
  SQFuncState *v8; // ecx
  SQFuncState *v9; // ecx
  int v10; // esi
  SQFuncState *v11; // ecx
  SQInstruction i; // [esp+Ch] [ebp-Ch] BYREF
  int key; // [esp+14h] [ebp-4h]
  unsigned __int8 oper; // [esp+20h] [ebp+8h]
  int val; // [esp+24h] [ebp+Ch]

  switch ( tok )
  {
    case 289:
      oper = 43;
      break;
    case 290:
      oper = 45;
      break;
    case 317:
      oper = 42;
      break;
    case 318:
      oper = 47;
      break;
    case 319:
      oper = 37;
      break;
    default:
      oper = 0;
      break;
  }
  v5 = SQFuncState::PopTarget(this: a2);
  v7 = !deref;
  val = v5;
  if ( v7 )
  {
    v10 = SQFuncState::PopTarget(this: v6);
    i.op = 35;
    i._arg0 = SQFuncState::PushTarget(this: v11, n: -1);
    i._arg2 = val;
  }
  else
  {
    key = SQFuncState::PopTarget(this: v6);
    i.op = 34;
    v10 = val | (SQFuncState::PopTarget(this: v8) << 16);
    i._arg0 = SQFuncState::PushTarget(this: v9, n: -1);
    i._arg2 = key;
  }
  i._arg3 = oper;
  i._arg1 = v10;
  SQFuncState::AddInstruction(this: this->_fs, &i);
}

//------------------------------------------------------------------------------
// Address: 0x1003ECA0
// Name: public: void SQCompiler::CommaExpr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::CommaExpr(SQCompiler *this)
{
  SQCompiler *v1; // esi
  SQFuncState *fs; // esi
  int *vals; // edx
  SQLexer *v4; // ecx
  _DWORD *v5; // edi
  int v6; // eax
  int v7; // ebx
  SQLocalVarInfo *v8; // ecx
  bool v9; // zf
  SQTable *keywords; // eax
  ExpState result; // [esp+10h] [ebp-8h] BYREF

  v1 = this;
  SQCompiler::Expression(this, &result, funcarg: false);
  if ( v1->_token == 44 )
  {
    do
    {
      fs = v1->_fs;
      vals = fs->_targetstack._vals;
      v4 = (SQLexer *)fs->_vlocals._vals;
      v5 = *((_DWORD **)&v4->_keywords + 5 * vals[fs->_targetstack._size - 1]);
      v6 = *(&v4->_curtoken + 5 * vals[fs->_targetstack._size - 1]);
      v7 = v6 & 0x8000000;
      if ( (v6 & 0x8000000) != 0 )
        ++v5[1];
      if ( v6 == 16777217 )
      {
        --fs->_vlocals._size;
        v8 = fs->_vlocals._vals;
        v9 = (v8[fs->_vlocals._size]._name._type & 0x8000000) == 0;
        v4 = (SQLexer *)&v8[fs->_vlocals._size];
        if ( !v9 )
        {
          keywords = v4->_keywords;
          if ( --keywords->_uiRef <= 0 )
            v4->_keywords->Release(this: v4->_keywords);
        }
      }
      --fs->_targetstack._size;
      if ( v7 != 0 && (int)--v5[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v5 + 8))(a1: v5);
      v1 = this;
      this->_token = SQLexer::Lex(this: v4);
      SQCompiler::CommaExpr(this);
    }
    while ( this->_token == 44 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003ED70
// Name: public: struct ExpState SQCompiler::Expression(bool)
// Source: json
//------------------------------------------------------------------------------
ExpState *__thiscall SQCompiler::Expression(SQCompiler *this, ExpState *result, bool funcarg)
{
  unsigned int size; // eax
  unsigned int v5; // esi
  unsigned int v6; // eax
  ExpState *v7; // ecx
  SQLexer *v8; // ecx
  int token; // esi
  int v10; // eax
  int v11; // eax
  SQFuncState *v12; // ecx
  char v13; // al
  SQFuncState *fs; // esi
  SQFuncState *v15; // ecx
  SQFuncState *v16; // ecx
  int v17; // eax
  SQFuncState *v18; // esi
  SQFuncState *v19; // esi
  SQLexer *v20; // ecx
  unsigned int v21; // edi
  SQFuncState *v22; // ecx
  int v23; // eax
  SQFuncState *v24; // esi
  unsigned int v25; // ecx
  ExpState *vals; // edx
  int deref; // edi
  SQCompiler *v28; // ecx
  int v29; // eax
  SQFuncState *v30; // esi
  char v31; // dl
  ExpState *v32; // ecx
  unsigned int v33; // edx
  int v34; // esi
  int v36; // edx
  const char *v37; // [esp+0h] [ebp-48h]
  bool freevar; // [esp+Fh] [ebp-39h]
  int trg; // [esp+10h] [ebp-38h] BYREF
  char v40; // [esp+14h] [ebp-34h]
  char v41; // [esp+15h] [ebp-33h]
  __int16 v42; // [esp+16h] [ebp-32h]
  int jmppos; // [esp+18h] [ebp-30h] BYREF
  int v44; // [esp+1Ch] [ebp-2Ch]
  int endfirstexp; // [esp+20h] [ebp-28h] BYREF
  char v46; // [esp+24h] [ebp-24h]
  char v47; // [esp+25h] [ebp-23h]
  __int16 v48; // [esp+26h] [ebp-22h]
  int jzpos; // [esp+28h] [ebp-20h] BYREF
  char v50; // [esp+2Ch] [ebp-1Ch]
  char v51; // [esp+2Dh] [ebp-1Bh]
  __int16 v52; // [esp+2Eh] [ebp-1Ah]
  ExpState v53; // [esp+30h] [ebp-18h] BYREF
  ExpState v54; // [esp+38h] [ebp-10h] BYREF
  ExpState v55; // [esp+40h] [ebp-8h] BYREF

  size = this->_expstates._size;
  BYTE2(jzpos) = 0;
  LOWORD(jzpos) = 0;
  if ( this->_expstates._allocated <= size )
  {
    v5 = 2 * size;
    if ( 2 * size == 0 )
      v5 = 4;
    this->_expstates._vals = (ExpState *)_g_pMemAlloc->Realloc_2(
                                           this: _g_pMemAlloc,
                                           a2: this->_expstates._vals,
                                           a3: 8 * v5);
    this->_expstates._allocated = v5;
  }
  v6 = this->_expstates._size;
  v7 = &this->_expstates._vals[v6];
  this->_expstates._size = v6 + 1;
  if ( v7 != nullptr )
  {
    *(_DWORD *)&v7->_class_or_delete = jzpos;
    v7->_deref = -1;
  }
  this->_expstates._vals[this->_expstates._size - 1]._class_or_delete = false;
  this->_expstates._vals[this->_expstates._size - 1]._funcarg = funcarg;
  SQCompiler::LogicalOrExp(this);
  token = this->_token;
  v10 = this->_token;
  if ( this->_token <= 281 )
  {
    if ( this->_token != 281 )
    {
      v11 = v10 - 61;
      if ( v11 != 0 )
      {
        if ( v11 == 2 )
        {
          this->_token = SQLexer::Lex(this: v8);
          v50 = 26;
          v13 = SQFuncState::PopTarget(this: v12);
          fs = this->_fs;
          v51 = v13;
          jzpos = 0;
          v52 = 0;
          SQFuncState::AddInstruction(this: fs, i: (SQInstruction *)&jzpos);
          jzpos = this->_fs->_instructions._size - 1;
          trg = SQFuncState::PushTarget(this: v15, n: -1);
          SQCompiler::Expression(this, result: &v53, funcarg: false);
          v17 = SQFuncState::PopTarget(this: v16);
          if ( trg != v17 )
          {
            v18 = this->_fs;
            v46 = 10;
            v47 = trg;
            endfirstexp = v17;
            v48 = 0;
            SQFuncState::AddInstruction(this: v18, i: (SQInstruction *)&endfirstexp);
          }
          v19 = this->_fs;
          endfirstexp = v19->_instructions._size - 1;
          jmppos = 0;
          v44 = 24;
          SQFuncState::AddInstruction(this: v19, i: (SQInstruction *)&jmppos);
          if ( this->_token != 58 )
            SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x3A);
          this->_token = SQLexer::Lex(this: v20);
          v21 = this->_fs->_instructions._size - 1;
          jmppos = v21;
          SQCompiler::Expression(this, result: &v54, funcarg: false);
          v23 = SQFuncState::PopTarget(this: v22);
          if ( trg != v23 )
          {
            v24 = this->_fs;
            v40 = 10;
            v41 = trg;
            trg = v23;
            v42 = 0;
            SQFuncState::AddInstruction(this: v24, i: (SQInstruction *)&trg);
            v21 = jmppos;
          }
          this->_fs->_instructions._vals[v21]._arg1 = this->_fs->_instructions._size - v21 - 1;
          this->_fs->_instructions._vals[jzpos]._arg1 = endfirstexp - jzpos + 1;
          this->_fs->_optimization = false;
        }
        goto LABEL_38;
      }
    }
$LN16_11:
    v25 = this->_expstates._size;
    vals = this->_expstates._vals;
    deref = vals[v25 - 1]._deref;
    freevar = vals[v25 - 1]._freevar;
    if ( deref == -1 )
      SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C274._errorjmp[9], s: v37);
    this->_token = SQLexer::Lex(this: (SQLexer *)v25);
    SQCompiler::Expression(this, result: &v55, funcarg: false);
    if ( token > 290 )
    {
      if ( token < 317 || token > 319 )
        goto LABEL_38;
    }
    else if ( token < 289 )
    {
      if ( token == 61 )
      {
        if ( freevar )
          SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C274._errorjmp[15], s: v37);
        if ( deref == -2 )
        {
          SQCompiler::EmitDerefOp(this: v28, op: (int)this, opa: 0xDu);
        }
        else
        {
          v29 = SQFuncState::PopTarget(this: (SQFuncState *)v28);
          v30 = this->_fs;
          v31 = v30->_targetstack._vals[v30->_targetstack._size - 1];
          v50 = 10;
          v51 = v31;
          jzpos = v29;
          v52 = 0;
          SQFuncState::AddInstruction(this: v30, i: (SQInstruction *)&jzpos);
        }
      }
      else if ( token == 281 )
      {
        if ( freevar )
          SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C274._errorjmp[15], s: v37);
        if ( deref != -2 )
          SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C348, s: v37);
        SQCompiler::EmitDerefOp(this: v28, op: (int)this, opa: 0xBu);
      }
      goto LABEL_38;
    }
    SQCompiler::EmitCompoundArith(tok: token, a2: (SQFuncState *)(deref == -2), this, deref: deref == -2);
    goto LABEL_38;
  }
  switch ( v10 )
  {
    case 289:
    case 290:
    case 317:
    case 318:
    case 319:
      goto $LN16_11;
    default:
      break;
  }
LABEL_38:
  v32 = this->_expstates._vals;
  v33 = this->_expstates._size;
  v34 = *(_DWORD *)&v32[v33 - 1]._class_or_delete;
  v36 = v32[v33 - 1]._deref;
  --this->_expstates._size;
  *(_DWORD *)&result->_class_or_delete = v34;
  result->_deref = v36;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003F0E0
// Name: public: void SQCompiler::LogicalOrExp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::LogicalOrExp(SQCompiler *this)
{
  SQFuncState *v2; // ecx
  SQFuncState *v3; // ecx
  int v4; // eax
  SQFuncState *fs; // esi
  SQFuncState *v6; // esi
  SQLexer *v7; // ecx
  int v8; // eax
  int v9; // edi
  SQFuncState *v10; // ecx
  int v11; // eax
  unsigned __int8 op; // cl
  SQFuncState *v13; // esi
  SQInstruction i; // [esp+10h] [ebp-18h] BYREF
  SQInstruction v15; // [esp+18h] [ebp-10h] BYREF
  SQInstruction v16; // [esp+20h] [ebp-8h] BYREF

  SQCompiler::LogicalAndExp(this);
  if ( this->_token == 271 )
  {
    *(_DWORD *)&v16.op = SQFuncState::PopTarget(this: v2);
    v4 = SQFuncState::PushTarget(this: v3, n: -1);
    fs = this->_fs;
    *(_DWORD *)&v15.op = v4;
    i._arg0 = v4;
    i.op = 44;
    i._arg1 = 0;
    i._arg2 = v16.op;
    i._arg3 = 0;
    SQFuncState::AddInstruction(this: fs, &i);
    v6 = this->_fs;
    v7 = *(SQLexer **)&v15.op;
    v8 = *(_DWORD *)&v16.op;
    v9 = v6->_instructions._size - 1;
    *(_DWORD *)&i.op = v9;
    if ( *(_DWORD *)&v15.op != *(_DWORD *)&v16.op )
    {
      v16.op = 10;
      v16._arg0 = v15.op;
      v16._arg1 = v8;
      *(_WORD *)&v16._arg2 = 0;
      SQFuncState::AddInstruction(this: v6, i: &v16);
      v9 = *(_DWORD *)&i.op;
    }
    this->_token = SQLexer::Lex(this: v7);
    SQCompiler::LogicalOrExp(this);
    v10 = this->_fs;
    v10->_optimization = false;
    v11 = SQFuncState::PopTarget(this: v10);
    op = v15.op;
    if ( *(_DWORD *)&v15.op != v11 )
    {
      v13 = this->_fs;
      v15.op = 10;
      v15._arg0 = op;
      v15._arg1 = v11;
      *(_WORD *)&v15._arg2 = 0;
      SQFuncState::AddInstruction(this: v13, i: &v15);
      v9 = *(_DWORD *)&i.op;
    }
    this->_fs->_optimization = false;
    this->_fs->_instructions._vals[v9]._arg1 = this->_fs->_instructions._size - v9 - 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F1D0
// Name: public: void SQCompiler::LogicalAndExp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::LogicalAndExp(SQCompiler *this)
{
  SQLexer *v2; // ecx
  SQFuncState *v3; // edi
  int *v4; // ecx
  int v5; // edx
  SQLocalVarInfo *v6; // eax
  _DWORD *v7; // esi
  tagSQObjectType v8; // eax
  int v9; // edx
  SQLocalVarInfo *v10; // ecx
  tagSQObjectValue v11; // eax
  SQFuncState *v12; // edi
  SQFuncState *v13; // ecx
  SQLocalVarInfo *v14; // esi
  int v15; // eax
  int v16; // edx
  SQLocalVarInfo *v17; // ecx
  bool v18; // zf
  SQLocalVarInfo *v19; // eax
  unsigned __int8 v20; // al
  SQFuncState *v21; // esi
  SQFuncState *v22; // edi
  int *v23; // ecx
  int v24; // edx
  SQLocalVarInfo *v25; // eax
  _DWORD *v26; // esi
  tagSQObjectType v27; // eax
  int v28; // edx
  SQLocalVarInfo *v29; // ecx
  tagSQObjectValue v30; // eax
  SQFuncState *v31; // edi
  SQFuncState *v32; // ecx
  SQLocalVarInfo *v33; // esi
  int v34; // eax
  int v35; // edx
  SQLocalVarInfo *v36; // ecx
  SQLocalVarInfo *v37; // eax
  unsigned __int8 v38; // al
  SQFuncState *v39; // esi
  SQFuncState *fs; // esi
  SQFuncState *vals; // ecx
  int v42; // edx
  SQLocalVarInfo *v43; // eax
  _DWORD *v44; // edi
  tagSQObjectType type; // eax
  int v46; // edx
  SQLocalVarInfo *v47; // eax
  int v48; // eax
  SQFuncState *v49; // esi
  SQFuncState *v50; // esi
  SQLexer *v51; // ecx
  SQFuncState *v52; // esi
  int v53; // edi
  SQLocalVarInfo *v54; // eax
  _DWORD *v55; // ecx
  tagSQObjectType v56; // eax
  SQLocalVarInfo *v57; // edx
  tagSQObjectValue v58; // eax
  SQFuncState *v59; // esi
  int v60; // edx
  SQFuncState *v61; // ecx
  unsigned int size; // eax
  _DWORD *v63; // [esp+10h] [ebp-48h]
  SQInstruction v64; // [esp+20h] [ebp-38h] BYREF
  SQInstruction v65; // [esp+28h] [ebp-30h] BYREF
  SQInstruction v66; // [esp+30h] [ebp-28h] BYREF
  SQInstruction v67; // [esp+38h] [ebp-20h] BYREF
  SQInstruction i; // [esp+40h] [ebp-18h] BYREF
  int jpos; // [esp+48h] [ebp-10h]
  int v70; // [esp+4Ch] [ebp-Ch]
  int trg; // [esp+50h] [ebp-8h]
  int v72; // [esp+54h] [ebp-4h]

  SQCompiler::BitwiseOrExp(this);
  while ( 1 )
  {
    while ( 1 )
    {
      while ( this->_token == 270 )
      {
        fs = this->_fs;
        vals = (SQFuncState *)fs->_targetstack._vals;
        v42 = *((_DWORD *)vals + fs->_targetstack._size - 1);
        v72 = *((_DWORD *)vals + fs->_targetstack._size - 1);
        v43 = fs->_vlocals._vals;
        v44 = &v43[v42]._name._unVal.pTable->__vftable;
        type = v43[v42]._name._type;
        v46 = type & 0x8000000;
        v70 = type & 0x8000000;
        if ( (type & 0x8000000) != 0 )
          ++v44[1];
        if ( type == OT_NULL )
        {
          vals = (SQFuncState *)&fs->_vlocals._vals[--fs->_vlocals._size];
          if ( (vals->_returnexp & 0x8000000) != 0 )
          {
            v47 = vals->_vlocals._vals;
            if ( --v47->_name._unVal.nInteger <= 0 )
            {
              (*(void (__thiscall **)(SQLocalVarInfo *))(vals->_vlocals._vals->_name._type + 8))(a1: vals->_vlocals._vals);
              v46 = v70;
            }
          }
        }
        --fs->_targetstack._size;
        if ( v46 != 0 && (int)--v44[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v44 + 8))(a1: v44);
        v48 = SQFuncState::PushTarget(this: vals, n: -1);
        v49 = this->_fs;
        trg = v48;
        v66.op = 43;
        v66._arg0 = v48;
        v66._arg1 = 0;
        v66._arg2 = v72;
        v66._arg3 = 0;
        SQFuncState::AddInstruction(this: v49, i: &v66);
        v50 = this->_fs;
        v51 = (SQLexer *)v72;
        jpos = v50->_instructions._size - 1;
        if ( trg != v72 )
        {
          v65.op = 10;
          v65._arg0 = trg;
          v65._arg1 = v72;
          *(_WORD *)&v65._arg2 = 0;
          SQFuncState::AddInstruction(this: v50, i: &v65);
        }
        this->_token = SQLexer::Lex(this: v51);
        SQCompiler::LogicalAndExp(this);
        this->_fs->_optimization = false;
        v52 = this->_fs;
        v53 = v52->_targetstack._vals[v52->_targetstack._size - 1];
        v54 = v52->_vlocals._vals;
        v55 = &v54[v53]._name._unVal.pTable->__vftable;
        v56 = v54[v53]._name._type;
        v63 = v55;
        v70 = v56 & 0x8000000;
        if ( (v56 & 0x8000000) != 0 )
          ++v55[1];
        if ( v56 == OT_NULL )
        {
          v57 = &v52->_vlocals._vals[--v52->_vlocals._size];
          if ( (v57->_name._type & 0x8000000) != 0 )
          {
            v58.pTable = (SQTable *)v57->_name._unVal;
            if ( (int)--*(_DWORD *)(v58.nInteger + 4) <= 0 )
            {
              v57->_name._unVal.pTable->Release(this: (struct SQTable *)v57->_name._unVal.nInteger);
              v55 = v63;
            }
          }
        }
        --v52->_targetstack._size;
        if ( v70 != 0 && (int)--v55[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v55 + 8))(a1: v55);
        if ( trg != v53 )
        {
          v59 = this->_fs;
          v64._arg1 = v53;
          v64.op = 10;
          v64._arg0 = trg;
          *(_WORD *)&v64._arg2 = 0;
          SQFuncState::AddInstruction(this: v59, i: &v64);
        }
        v60 = jpos;
        this->_fs->_optimization = false;
        v61 = this->_fs;
        size = v61->_instructions._size;
        v2 = (SQLexer *)v61->_instructions._vals;
        *(&v2->_curtoken + 2 * v60) = size - v60 - 1;
      }
      if ( this->_token != 280 )
        break;
      this->_token = SQLexer::Lex(this: v2);
      SQCompiler::BitwiseOrExp(this);
      v22 = this->_fs;
      v23 = v22->_targetstack._vals;
      v24 = v23[v22->_targetstack._size - 1];
      trg = v23[v22->_targetstack._size - 1];
      v25 = v22->_vlocals._vals;
      v26 = &v25[v24]._name._unVal.pTable->__vftable;
      v27 = v25[v24]._name._type;
      v28 = v27 & 0x8000000;
      v70 = v27 & 0x8000000;
      if ( (v27 & 0x8000000) != 0 )
        ++v26[1];
      if ( v27 == OT_NULL )
      {
        v29 = &v22->_vlocals._vals[--v22->_vlocals._size];
        if ( (v29->_name._type & 0x8000000) != 0 )
        {
          v30.pTable = (SQTable *)v29->_name._unVal;
          if ( (int)--*(_DWORD *)(v30.nInteger + 4) <= 0 )
          {
            v29->_name._unVal.pTable->Release(this: (struct SQTable *)v29->_name._unVal.nInteger);
            v28 = v70;
          }
        }
      }
      --v22->_targetstack._size;
      if ( v28 != 0 && (int)--v26[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v26 + 8))(a1: v26);
      v31 = this->_fs;
      v32 = (SQFuncState *)v31->_vlocals._vals;
      v72 = v31->_targetstack._vals[v31->_targetstack._size - 1];
      v33 = (&v32->_vlocals._vals)[5 * v72];
      v34 = *(&v32->_returnexp + 5 * v72);
      v35 = v34 & 0x8000000;
      v70 = v34 & 0x8000000;
      if ( (v34 & 0x8000000) != 0 )
        ++v33->_name._unVal.nInteger;
      if ( v34 == 16777217 )
      {
        --v31->_vlocals._size;
        v36 = v31->_vlocals._vals;
        v18 = (v36[v31->_vlocals._size]._name._type & 0x8000000) == 0;
        v32 = (SQFuncState *)&v36[v31->_vlocals._size];
        if ( !v18 )
        {
          v37 = v32->_vlocals._vals;
          if ( --v37->_name._unVal.nInteger <= 0 )
          {
            (*(void (__thiscall **)(SQLocalVarInfo *))(v32->_vlocals._vals->_name._type + 8))(a1: v32->_vlocals._vals);
            v35 = v70;
          }
        }
      }
      --v31->_targetstack._size;
      if ( v35 != 0 && --v33->_name._unVal.nInteger <= 0 )
        (*(void (__thiscall **)(SQLocalVarInfo *))(v33->_name._type + 8))(a1: v33);
      v67.op = 41;
      v38 = SQFuncState::PushTarget(this: v32, n: -1);
      v39 = this->_fs;
      v67._arg0 = v38;
      v67._arg1 = trg;
      v67._arg2 = v72;
      v67._arg3 = 0;
      SQFuncState::AddInstruction(this: v39, i: &v67);
    }
    if ( this->_token != 311 )
      break;
    this->_token = SQLexer::Lex(this: v2);
    SQCompiler::BitwiseOrExp(this);
    v3 = this->_fs;
    v4 = v3->_targetstack._vals;
    v5 = v4[v3->_targetstack._size - 1];
    v72 = v4[v3->_targetstack._size - 1];
    v6 = v3->_vlocals._vals;
    v7 = &v6[v5]._name._unVal.pTable->__vftable;
    v8 = v6[v5]._name._type;
    v9 = v8 & 0x8000000;
    trg = v8 & 0x8000000;
    if ( (v8 & 0x8000000) != 0 )
      ++v7[1];
    if ( v8 == OT_NULL )
    {
      v10 = &v3->_vlocals._vals[--v3->_vlocals._size];
      if ( (v10->_name._type & 0x8000000) != 0 )
      {
        v11.pTable = (SQTable *)v10->_name._unVal;
        if ( (int)--*(_DWORD *)(v11.nInteger + 4) <= 0 )
        {
          v10->_name._unVal.pTable->Release(this: (struct SQTable *)v10->_name._unVal.nInteger);
          v9 = trg;
        }
      }
    }
    --v3->_targetstack._size;
    if ( v9 != 0 && (int)--v7[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
    v12 = this->_fs;
    v13 = (SQFuncState *)v12->_vlocals._vals;
    v70 = v12->_targetstack._vals[v12->_targetstack._size - 1];
    v14 = (&v13->_vlocals._vals)[5 * v70];
    v15 = *(&v13->_returnexp + 5 * v70);
    v16 = v15 & 0x8000000;
    trg = v15 & 0x8000000;
    if ( (v15 & 0x8000000) != 0 )
      ++v14->_name._unVal.nInteger;
    if ( v15 == 16777217 )
    {
      --v12->_vlocals._size;
      v17 = v12->_vlocals._vals;
      v18 = (v17[v12->_vlocals._size]._name._type & 0x8000000) == 0;
      v13 = (SQFuncState *)&v17[v12->_vlocals._size];
      if ( !v18 )
      {
        v19 = v13->_vlocals._vals;
        if ( --v19->_name._unVal.nInteger <= 0 )
        {
          (*(void (__thiscall **)(SQLocalVarInfo *))(v13->_vlocals._vals->_name._type + 8))(a1: v13->_vlocals._vals);
          v16 = trg;
        }
      }
    }
    --v12->_targetstack._size;
    if ( v16 != 0 && --v14->_name._unVal.nInteger <= 0 )
      (*(void (__thiscall **)(SQLocalVarInfo *))(v14->_name._type + 8))(a1: v14);
    i.op = 42;
    v20 = SQFuncState::PushTarget(this: v13, n: -1);
    v21 = this->_fs;
    i._arg0 = v20;
    i._arg1 = v72;
    i._arg2 = v70;
    i._arg3 = 0;
    SQFuncState::AddInstruction(this: v21, &i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F660
// Name: public: void SQCompiler::BitwiseOrExp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::BitwiseOrExp(SQCompiler *this)
{
  SQLexer *v2; // ecx
  SQFuncState *fs; // esi
  int *vals; // ecx
  int v5; // edx
  SQLocalVarInfo *v6; // eax
  _DWORD *v7; // edi
  tagSQObjectType type; // eax
  sqvector<SQLocalVarInfo> *v9; // edx
  SQLocalVarInfo *v10; // ecx
  tagSQObjectValue v11; // eax
  SQFuncState *v12; // esi
  SQLocalVarInfo *v13; // ecx
  _DWORD *v14; // edi
  tagSQObjectType v15; // eax
  sqvector<SQLocalVarInfo> *v16; // edx
  SQLocalVarInfo *v17; // ecx
  bool v18; // zf
  SQLocalVarInfo *v19; // ecx
  tagSQObjectValue v20; // eax
  SQFuncState *v21; // edi
  int stacksize; // eax
  unsigned int v23; // eax
  int v24; // esi
  unsigned int v25; // eax
  int *v26; // ecx
  SQFuncState *v27; // esi
  SQLocalVarInfo val; // [esp+10h] [ebp-28h] BYREF
  SQInstruction i; // [esp+24h] [ebp-14h] BYREF
  int v30; // [esp+2Ch] [ebp-Ch]
  int v31; // [esp+30h] [ebp-8h]
  sqvector<SQLocalVarInfo> *size; // [esp+34h] [ebp-4h]

  SQCompiler::BitwiseXorExp(this);
  if ( this->_token == 124 )
  {
    i.op = 18;
    i._arg3 = 2;
    do
    {
      this->_token = SQLexer::Lex(this: v2);
      SQCompiler::BitwiseXorExp(this);
      fs = this->_fs;
      vals = fs->_targetstack._vals;
      v5 = vals[fs->_targetstack._size - 1];
      v31 = vals[fs->_targetstack._size - 1];
      v6 = fs->_vlocals._vals;
      v7 = &v6[v5]._name._unVal.pTable->__vftable;
      type = v6[v5]._name._type;
      v9 = (sqvector<SQLocalVarInfo> *)(type & 0x8000000);
      size = (sqvector<SQLocalVarInfo> *)(type & 0x8000000);
      if ( (type & 0x8000000) != 0 )
        ++v7[1];
      if ( type == OT_NULL )
      {
        v10 = &fs->_vlocals._vals[--fs->_vlocals._size];
        if ( (v10->_name._type & 0x8000000) != 0 )
        {
          v11.pTable = (SQTable *)v10->_name._unVal;
          if ( (int)--*(_DWORD *)(v11.nInteger + 4) <= 0 )
          {
            v10->_name._unVal.pTable->Release(this: (struct SQTable *)v10->_name._unVal.nInteger);
            v9 = size;
          }
        }
      }
      --fs->_targetstack._size;
      if ( v9 != nullptr && (int)--v7[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
      v12 = this->_fs;
      v13 = v12->_vlocals._vals;
      v30 = v12->_targetstack._vals[v12->_targetstack._size - 1];
      v14 = &v13[v30]._name._unVal.pTable->__vftable;
      v15 = v13[v30]._name._type;
      v16 = (sqvector<SQLocalVarInfo> *)(v15 & 0x8000000);
      size = (sqvector<SQLocalVarInfo> *)(v15 & 0x8000000);
      if ( (v15 & 0x8000000) != 0 )
        ++v14[1];
      if ( v15 == OT_NULL )
      {
        --v12->_vlocals._size;
        v17 = v12->_vlocals._vals;
        v18 = (v17[v12->_vlocals._size]._name._type & 0x8000000) == 0;
        v19 = &v17[v12->_vlocals._size];
        if ( !v18 )
        {
          v20.pTable = (SQTable *)v19->_name._unVal;
          if ( (int)--*(_DWORD *)(v20.nInteger + 4) <= 0 )
          {
            v19->_name._unVal.pTable->Release(this: (struct SQTable *)v19->_name._unVal.nInteger);
            v16 = size;
          }
        }
      }
      --v12->_targetstack._size;
      if ( v16 != nullptr && (int)--v14[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
      v21 = this->_fs;
      size = (sqvector<SQLocalVarInfo> *)v21->_vlocals._size;
      val._name._type = OT_NULL;
      memset(&val._name._unVal, 0, 12);
      sqvector<SQLocalVarInfo>::push_back(this: size, a2: (int)&v21->_vlocals, &val);
      stacksize = v21->_stacksize;
      if ( v21->_vlocals._size > stacksize )
      {
        if ( stacksize > 255 )
          v21->_errfunc(a1: v21->_errtarget, a2: "internal compiler error: too many locals");
        v21->_stacksize = v21->_vlocals._size;
      }
      v23 = v21->_targetstack._size;
      if ( v21->_targetstack._allocated <= v23 )
      {
        v24 = 2 * v23;
        if ( 2 * v23 == 0 )
          v24 = 4;
        v21->_targetstack._vals = (int *)_g_pMemAlloc->Realloc_2(
                                           this: _g_pMemAlloc,
                                           a2: v21->_targetstack._vals,
                                           a3: 4 * v24);
        v21->_targetstack._allocated = v24;
      }
      v25 = v21->_targetstack._size;
      v26 = &v21->_targetstack._vals[v25];
      v21->_targetstack._size = v25 + 1;
      if ( v26 != nullptr )
        *v26 = (int)size;
      v27 = this->_fs;
      i._arg0 = (unsigned __int8)size;
      i._arg1 = v31;
      i._arg2 = v30;
      SQFuncState::AddInstruction(this: v27, &i);
    }
    while ( this->_token == 124 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F870
// Name: public: void SQCompiler::BitwiseXorExp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::BitwiseXorExp(SQCompiler *this)
{
  SQLexer *v2; // ecx
  SQFuncState *fs; // esi
  int *vals; // ecx
  int v5; // edx
  SQLocalVarInfo *v6; // eax
  _DWORD *v7; // edi
  tagSQObjectType type; // eax
  sqvector<SQLocalVarInfo> *v9; // edx
  SQLocalVarInfo *v10; // ecx
  tagSQObjectValue v11; // eax
  SQFuncState *v12; // esi
  SQLocalVarInfo *v13; // ecx
  _DWORD *v14; // edi
  tagSQObjectType v15; // eax
  sqvector<SQLocalVarInfo> *v16; // edx
  SQLocalVarInfo *v17; // ecx
  bool v18; // zf
  SQLocalVarInfo *v19; // ecx
  tagSQObjectValue v20; // eax
  SQFuncState *v21; // edi
  int stacksize; // eax
  unsigned int v23; // eax
  int v24; // esi
  unsigned int v25; // eax
  int *v26; // ecx
  SQFuncState *v27; // esi
  SQLocalVarInfo val; // [esp+10h] [ebp-28h] BYREF
  SQInstruction i; // [esp+24h] [ebp-14h] BYREF
  int v30; // [esp+2Ch] [ebp-Ch]
  int v31; // [esp+30h] [ebp-8h]
  sqvector<SQLocalVarInfo> *size; // [esp+34h] [ebp-4h]

  SQCompiler::BitwiseAndExp(this);
  if ( this->_token == 94 )
  {
    i.op = 18;
    i._arg3 = 3;
    do
    {
      this->_token = SQLexer::Lex(this: v2);
      SQCompiler::BitwiseAndExp(this);
      fs = this->_fs;
      vals = fs->_targetstack._vals;
      v5 = vals[fs->_targetstack._size - 1];
      v31 = vals[fs->_targetstack._size - 1];
      v6 = fs->_vlocals._vals;
      v7 = &v6[v5]._name._unVal.pTable->__vftable;
      type = v6[v5]._name._type;
      v9 = (sqvector<SQLocalVarInfo> *)(type & 0x8000000);
      size = (sqvector<SQLocalVarInfo> *)(type & 0x8000000);
      if ( (type & 0x8000000) != 0 )
        ++v7[1];
      if ( type == OT_NULL )
      {
        v10 = &fs->_vlocals._vals[--fs->_vlocals._size];
        if ( (v10->_name._type & 0x8000000) != 0 )
        {
          v11.pTable = (SQTable *)v10->_name._unVal;
          if ( (int)--*(_DWORD *)(v11.nInteger + 4) <= 0 )
          {
            v10->_name._unVal.pTable->Release(this: (struct SQTable *)v10->_name._unVal.nInteger);
            v9 = size;
          }
        }
      }
      --fs->_targetstack._size;
      if ( v9 != nullptr && (int)--v7[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
      v12 = this->_fs;
      v13 = v12->_vlocals._vals;
      v30 = v12->_targetstack._vals[v12->_targetstack._size - 1];
      v14 = &v13[v30]._name._unVal.pTable->__vftable;
      v15 = v13[v30]._name._type;
      v16 = (sqvector<SQLocalVarInfo> *)(v15 & 0x8000000);
      size = (sqvector<SQLocalVarInfo> *)(v15 & 0x8000000);
      if ( (v15 & 0x8000000) != 0 )
        ++v14[1];
      if ( v15 == OT_NULL )
      {
        --v12->_vlocals._size;
        v17 = v12->_vlocals._vals;
        v18 = (v17[v12->_vlocals._size]._name._type & 0x8000000) == 0;
        v19 = &v17[v12->_vlocals._size];
        if ( !v18 )
        {
          v20.pTable = (SQTable *)v19->_name._unVal;
          if ( (int)--*(_DWORD *)(v20.nInteger + 4) <= 0 )
          {
            v19->_name._unVal.pTable->Release(this: (struct SQTable *)v19->_name._unVal.nInteger);
            v16 = size;
          }
        }
      }
      --v12->_targetstack._size;
      if ( v16 != nullptr && (int)--v14[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
      v21 = this->_fs;
      size = (sqvector<SQLocalVarInfo> *)v21->_vlocals._size;
      val._name._type = OT_NULL;
      memset(&val._name._unVal, 0, 12);
      sqvector<SQLocalVarInfo>::push_back(this: size, a2: (int)&v21->_vlocals, &val);
      stacksize = v21->_stacksize;
      if ( v21->_vlocals._size > stacksize )
      {
        if ( stacksize > 255 )
          v21->_errfunc(a1: v21->_errtarget, a2: "internal compiler error: too many locals");
        v21->_stacksize = v21->_vlocals._size;
      }
      v23 = v21->_targetstack._size;
      if ( v21->_targetstack._allocated <= v23 )
      {
        v24 = 2 * v23;
        if ( 2 * v23 == 0 )
          v24 = 4;
        v21->_targetstack._vals = (int *)_g_pMemAlloc->Realloc_2(
                                           this: _g_pMemAlloc,
                                           a2: v21->_targetstack._vals,
                                           a3: 4 * v24);
        v21->_targetstack._allocated = v24;
      }
      v25 = v21->_targetstack._size;
      v26 = &v21->_targetstack._vals[v25];
      v21->_targetstack._size = v25 + 1;
      if ( v26 != nullptr )
        *v26 = (int)size;
      v27 = this->_fs;
      i._arg0 = (unsigned __int8)size;
      i._arg1 = v31;
      i._arg2 = v30;
      SQFuncState::AddInstruction(this: v27, &i);
    }
    while ( this->_token == 94 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003FA80
// Name: public: void SQCompiler::BitwiseAndExp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::BitwiseAndExp(SQCompiler *this)
{
  SQLexer *v2; // ecx
  SQFuncState *fs; // esi
  int *vals; // ecx
  int v5; // edx
  SQLocalVarInfo *v6; // eax
  _DWORD *v7; // edi
  tagSQObjectType type; // eax
  sqvector<SQLocalVarInfo> *v9; // edx
  SQLocalVarInfo *v10; // ecx
  tagSQObjectValue v11; // eax
  SQFuncState *v12; // esi
  SQLocalVarInfo *v13; // ecx
  _DWORD *v14; // edi
  tagSQObjectType v15; // eax
  sqvector<SQLocalVarInfo> *v16; // edx
  SQLocalVarInfo *v17; // ecx
  bool v18; // zf
  SQLocalVarInfo *v19; // ecx
  tagSQObjectValue v20; // eax
  SQFuncState *v21; // edi
  int stacksize; // eax
  unsigned int v23; // eax
  int v24; // esi
  unsigned int v25; // eax
  int *v26; // ecx
  SQFuncState *v27; // esi
  SQLocalVarInfo val; // [esp+10h] [ebp-28h] BYREF
  SQInstruction i; // [esp+24h] [ebp-14h] BYREF
  int v30; // [esp+2Ch] [ebp-Ch]
  int v31; // [esp+30h] [ebp-8h]
  sqvector<SQLocalVarInfo> *size; // [esp+34h] [ebp-4h]

  SQCompiler::CompExp(this);
  if ( this->_token == 38 )
  {
    i.op = 18;
    i._arg3 = 0;
    do
    {
      this->_token = SQLexer::Lex(this: v2);
      SQCompiler::CompExp(this);
      fs = this->_fs;
      vals = fs->_targetstack._vals;
      v5 = vals[fs->_targetstack._size - 1];
      v31 = vals[fs->_targetstack._size - 1];
      v6 = fs->_vlocals._vals;
      v7 = &v6[v5]._name._unVal.pTable->__vftable;
      type = v6[v5]._name._type;
      v9 = (sqvector<SQLocalVarInfo> *)(type & 0x8000000);
      size = (sqvector<SQLocalVarInfo> *)(type & 0x8000000);
      if ( (type & 0x8000000) != 0 )
        ++v7[1];
      if ( type == OT_NULL )
      {
        v10 = &fs->_vlocals._vals[--fs->_vlocals._size];
        if ( (v10->_name._type & 0x8000000) != 0 )
        {
          v11.pTable = (SQTable *)v10->_name._unVal;
          if ( (int)--*(_DWORD *)(v11.nInteger + 4) <= 0 )
          {
            v10->_name._unVal.pTable->Release(this: (struct SQTable *)v10->_name._unVal.nInteger);
            v9 = size;
          }
        }
      }
      --fs->_targetstack._size;
      if ( v9 != nullptr && (int)--v7[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
      v12 = this->_fs;
      v13 = v12->_vlocals._vals;
      v30 = v12->_targetstack._vals[v12->_targetstack._size - 1];
      v14 = &v13[v30]._name._unVal.pTable->__vftable;
      v15 = v13[v30]._name._type;
      v16 = (sqvector<SQLocalVarInfo> *)(v15 & 0x8000000);
      size = (sqvector<SQLocalVarInfo> *)(v15 & 0x8000000);
      if ( (v15 & 0x8000000) != 0 )
        ++v14[1];
      if ( v15 == OT_NULL )
      {
        --v12->_vlocals._size;
        v17 = v12->_vlocals._vals;
        v18 = (v17[v12->_vlocals._size]._name._type & 0x8000000) == 0;
        v19 = &v17[v12->_vlocals._size];
        if ( !v18 )
        {
          v20.pTable = (SQTable *)v19->_name._unVal;
          if ( (int)--*(_DWORD *)(v20.nInteger + 4) <= 0 )
          {
            v19->_name._unVal.pTable->Release(this: (struct SQTable *)v19->_name._unVal.nInteger);
            v16 = size;
          }
        }
      }
      --v12->_targetstack._size;
      if ( v16 != nullptr && (int)--v14[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
      v21 = this->_fs;
      size = (sqvector<SQLocalVarInfo> *)v21->_vlocals._size;
      val._name._type = OT_NULL;
      memset(&val._name._unVal, 0, 12);
      sqvector<SQLocalVarInfo>::push_back(this: size, a2: (int)&v21->_vlocals, &val);
      stacksize = v21->_stacksize;
      if ( v21->_vlocals._size > stacksize )
      {
        if ( stacksize > 255 )
          v21->_errfunc(a1: v21->_errtarget, a2: "internal compiler error: too many locals");
        v21->_stacksize = v21->_vlocals._size;
      }
      v23 = v21->_targetstack._size;
      if ( v21->_targetstack._allocated <= v23 )
      {
        v24 = 2 * v23;
        if ( 2 * v23 == 0 )
          v24 = 4;
        v21->_targetstack._vals = (int *)_g_pMemAlloc->Realloc_2(
                                           this: _g_pMemAlloc,
                                           a2: v21->_targetstack._vals,
                                           a3: 4 * v24);
        v21->_targetstack._allocated = v24;
      }
      v25 = v21->_targetstack._size;
      v26 = &v21->_targetstack._vals[v25];
      v21->_targetstack._size = v25 + 1;
      if ( v26 != nullptr )
        *v26 = (int)size;
      v27 = this->_fs;
      i._arg0 = (unsigned __int8)size;
      i._arg1 = v31;
      i._arg2 = v30;
      SQFuncState::AddInstruction(this: v27, &i);
    }
    while ( this->_token == 38 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003FC90
// Name: public: void SQCompiler::CompExp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::CompExp(SQCompiler *this)
{
  SQLexer *v2; // ecx
  unsigned int v3; // eax
  SQFuncState *v4; // ecx
  SQFuncState *v5; // ecx
  SQFuncState *v6; // ecx
  SQInstruction *p_i; // edi
  SQFuncState *v8; // ecx
  SQFuncState *v9; // ecx
  SQFuncState *v10; // ecx
  SQFuncState *v11; // ecx
  SQFuncState *v12; // ecx
  SQFuncState *v13; // ecx
  SQFuncState *v14; // ecx
  SQFuncState *v15; // ecx
  SQFuncState *v16; // ecx
  SQFuncState *v17; // ecx
  SQFuncState *v18; // ecx
  SQFuncState *v19; // ecx
  SQFuncState *v20; // ecx
  SQFuncState *v21; // ecx
  SQFuncState *v22; // ecx
  SQInstruction i; // [esp+10h] [ebp-38h] BYREF
  int v24; // [esp+18h] [ebp-30h] BYREF
  char v25; // [esp+1Ch] [ebp-2Ch]
  char v26; // [esp+1Dh] [ebp-2Bh]
  char v27; // [esp+1Eh] [ebp-2Ah]
  char v28; // [esp+1Fh] [ebp-29h]
  int v29; // [esp+20h] [ebp-28h] BYREF
  char v30; // [esp+24h] [ebp-24h]
  char v31; // [esp+25h] [ebp-23h]
  char v32; // [esp+26h] [ebp-22h]
  char v33; // [esp+27h] [ebp-21h]
  int v34; // [esp+28h] [ebp-20h] BYREF
  char v35; // [esp+2Ch] [ebp-1Ch]
  char v36; // [esp+2Dh] [ebp-1Bh]
  char v37; // [esp+2Eh] [ebp-1Ah]
  char v38; // [esp+2Fh] [ebp-19h]
  int v39; // [esp+30h] [ebp-18h] BYREF
  char v40; // [esp+34h] [ebp-14h]
  char v41; // [esp+35h] [ebp-13h]
  char v42; // [esp+36h] [ebp-12h]
  char v43; // [esp+37h] [ebp-11h]
  int v44; // [esp+38h] [ebp-10h] BYREF
  char v45; // [esp+3Ch] [ebp-Ch]
  char v46; // [esp+3Dh] [ebp-Bh]
  char v47; // [esp+3Eh] [ebp-Ah]
  char v48; // [esp+3Fh] [ebp-9h]
  int v49; // [esp+40h] [ebp-8h]
  int v50; // [esp+44h] [ebp-4h]

  SQCompiler::ShiftExp(this);
  v3 = this->_token - 60;
  while ( 2 )
  {
    switch ( v3 )
    {
      case 0u:
        this->_token = SQLexer::Lex(this: v2);
        SQCompiler::ShiftExp(this);
        v49 = SQFuncState::PopTarget(this: v11);
        v50 = SQFuncState::PopTarget(this: v12);
        v35 = 40;
        v36 = SQFuncState::PushTarget(this: v13, n: -1);
        v34 = v49;
        v37 = v50;
        v38 = 3;
        p_i = (SQInstruction *)&v34;
        goto LABEL_9;
      case 2u:
        this->_token = SQLexer::Lex(this: v2);
        SQCompiler::ShiftExp(this);
        v49 = SQFuncState::PopTarget(this: v8);
        v50 = SQFuncState::PopTarget(this: v9);
        v40 = 40;
        v41 = SQFuncState::PushTarget(this: v10, n: -1);
        v39 = v49;
        v42 = v50;
        v43 = 0;
        p_i = (SQInstruction *)&v39;
        goto LABEL_9;
      case 0xCCu:
        this->_token = SQLexer::Lex(this: v2);
        SQCompiler::ShiftExp(this);
        v50 = SQFuncState::PopTarget(this: v4);
        v49 = SQFuncState::PopTarget(this: v5);
        v45 = 15;
        v46 = SQFuncState::PushTarget(this: v6, n: -1);
        v44 = v50;
        v47 = v49;
        v48 = 0;
        p_i = (SQInstruction *)&v44;
        goto LABEL_9;
      case 0xCDu:
        this->_token = SQLexer::Lex(this: v2);
        SQCompiler::ShiftExp(this);
        v49 = SQFuncState::PopTarget(this: v20);
        v50 = SQFuncState::PopTarget(this: v21);
        i.op = 16;
        i._arg0 = SQFuncState::PushTarget(this: v22, n: -1);
        i._arg1 = v49;
        i._arg2 = v50;
        i._arg3 = 0;
        p_i = &i;
        goto LABEL_9;
      case 0xCEu:
        this->_token = SQLexer::Lex(this: v2);
        SQCompiler::ShiftExp(this);
        v49 = SQFuncState::PopTarget(this: v17);
        v50 = SQFuncState::PopTarget(this: v18);
        v25 = 40;
        v26 = SQFuncState::PushTarget(this: v19, n: -1);
        v24 = v49;
        v27 = v50;
        v28 = 4;
        p_i = (SQInstruction *)&v24;
        goto LABEL_9;
      case 0xCFu:
        this->_token = SQLexer::Lex(this: v2);
        SQCompiler::ShiftExp(this);
        v49 = SQFuncState::PopTarget(this: v14);
        v50 = SQFuncState::PopTarget(this: v15);
        v30 = 40;
        v31 = SQFuncState::PushTarget(this: v16, n: -1);
        v29 = v49;
        v32 = v50;
        v33 = 2;
        p_i = (SQInstruction *)&v29;
LABEL_9:
        SQFuncState::AddInstruction(this: this->_fs, i: p_i);
        v3 = this->_token - 60;
        if ( v3 > 0xCF )
          return;
        continue;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003FFB0
// Name: public: void SQCompiler::ShiftExp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::ShiftExp(SQCompiler *this)
{
  SQLexer *v2; // ecx
  SQFuncState *v3; // edi
  int *v4; // ecx
  int v5; // edx
  SQLocalVarInfo *v6; // eax
  _DWORD *v7; // esi
  tagSQObjectType v8; // eax
  int v9; // edx
  SQLocalVarInfo *v10; // ecx
  tagSQObjectValue v11; // eax
  SQFuncState *v12; // edi
  SQFuncState *v13; // ecx
  SQLocalVarInfo *v14; // esi
  int v15; // eax
  int v16; // edx
  SQLocalVarInfo *v17; // ecx
  bool v18; // zf
  SQLocalVarInfo *v19; // eax
  unsigned __int8 v20; // al
  SQFuncState *v21; // esi
  SQFuncState *v22; // edi
  int *v23; // ecx
  int v24; // edx
  SQLocalVarInfo *v25; // eax
  _DWORD *v26; // esi
  tagSQObjectType v27; // eax
  int v28; // edx
  SQLocalVarInfo *v29; // ecx
  tagSQObjectValue v30; // eax
  SQFuncState *v31; // edi
  SQFuncState *v32; // ecx
  SQLocalVarInfo *v33; // esi
  int v34; // eax
  int v35; // edx
  SQLocalVarInfo *v36; // ecx
  SQLocalVarInfo *v37; // eax
  unsigned __int8 v38; // al
  SQFuncState *v39; // esi
  SQFuncState *fs; // edi
  int *vals; // ecx
  int v42; // edx
  SQLocalVarInfo *v43; // eax
  _DWORD *v44; // esi
  tagSQObjectType type; // eax
  int v46; // edx
  SQLocalVarInfo *v47; // ecx
  tagSQObjectValue v48; // eax
  SQFuncState *v49; // edi
  SQFuncState *v50; // ecx
  SQLocalVarInfo *v51; // esi
  int v52; // eax
  int v53; // edx
  SQLocalVarInfo *v54; // ecx
  SQLocalVarInfo *v55; // eax
  unsigned __int8 v56; // al
  SQFuncState *v57; // esi
  SQInstruction v58; // [esp+Ch] [ebp-24h] BYREF
  SQInstruction v59; // [esp+14h] [ebp-1Ch] BYREF
  SQInstruction i; // [esp+1Ch] [ebp-14h] BYREF
  int v61; // [esp+24h] [ebp-Ch]
  int v62; // [esp+28h] [ebp-8h]
  int v63; // [esp+2Ch] [ebp-4h]

  SQCompiler::PlusExp(this);
  while ( 1 )
  {
    while ( 1 )
    {
      while ( this->_token == 296 )
      {
        this->_token = SQLexer::Lex(this: v2);
        SQCompiler::PlusExp(this);
        fs = this->_fs;
        vals = fs->_targetstack._vals;
        v42 = vals[fs->_targetstack._size - 1];
        v62 = vals[fs->_targetstack._size - 1];
        v43 = fs->_vlocals._vals;
        v44 = &v43[v42]._name._unVal.pTable->__vftable;
        type = v43[v42]._name._type;
        v46 = type & 0x8000000;
        v61 = type & 0x8000000;
        if ( (type & 0x8000000) != 0 )
          ++v44[1];
        if ( type == OT_NULL )
        {
          v47 = &fs->_vlocals._vals[--fs->_vlocals._size];
          if ( (v47->_name._type & 0x8000000) != 0 )
          {
            v48.pTable = (SQTable *)v47->_name._unVal;
            if ( (int)--*(_DWORD *)(v48.nInteger + 4) <= 0 )
            {
              v47->_name._unVal.pTable->Release(this: (struct SQTable *)v47->_name._unVal.nInteger);
              v46 = v61;
            }
          }
        }
        --fs->_targetstack._size;
        if ( v46 != 0 && (int)--v44[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v44 + 8))(a1: v44);
        v49 = this->_fs;
        v50 = (SQFuncState *)v49->_vlocals._vals;
        v63 = v49->_targetstack._vals[v49->_targetstack._size - 1];
        v51 = (&v50->_vlocals._vals)[5 * v63];
        v52 = *(&v50->_returnexp + 5 * v63);
        v53 = v52 & 0x8000000;
        v61 = v52 & 0x8000000;
        if ( (v52 & 0x8000000) != 0 )
          ++v51->_name._unVal.nInteger;
        if ( v52 == 16777217 )
        {
          --v49->_vlocals._size;
          v54 = v49->_vlocals._vals;
          v18 = (v54[v49->_vlocals._size]._name._type & 0x8000000) == 0;
          v50 = (SQFuncState *)&v54[v49->_vlocals._size];
          if ( !v18 )
          {
            v55 = v50->_vlocals._vals;
            if ( --v55->_name._unVal.nInteger <= 0 )
            {
              (*(void (__thiscall **)(SQLocalVarInfo *))(v50->_vlocals._vals->_name._type + 8))(a1: v50->_vlocals._vals);
              v53 = v61;
            }
          }
        }
        --v49->_targetstack._size;
        if ( v53 != 0 && --v51->_name._unVal.nInteger <= 0 )
          (*(void (__thiscall **)(SQLocalVarInfo *))(v51->_name._type + 8))(a1: v51);
        v58.op = 18;
        v56 = SQFuncState::PushTarget(this: v50, n: -1);
        v57 = this->_fs;
        v58._arg0 = v56;
        v58._arg1 = v62;
        v58._arg2 = v63;
        v58._arg3 = 4;
        SQFuncState::AddInstruction(this: v57, i: &v58);
      }
      if ( this->_token != 297 )
        break;
      this->_token = SQLexer::Lex(this: v2);
      SQCompiler::PlusExp(this);
      v22 = this->_fs;
      v23 = v22->_targetstack._vals;
      v24 = v23[v22->_targetstack._size - 1];
      v62 = v23[v22->_targetstack._size - 1];
      v25 = v22->_vlocals._vals;
      v26 = &v25[v24]._name._unVal.pTable->__vftable;
      v27 = v25[v24]._name._type;
      v28 = v27 & 0x8000000;
      v61 = v27 & 0x8000000;
      if ( (v27 & 0x8000000) != 0 )
        ++v26[1];
      if ( v27 == OT_NULL )
      {
        v29 = &v22->_vlocals._vals[--v22->_vlocals._size];
        if ( (v29->_name._type & 0x8000000) != 0 )
        {
          v30.pTable = (SQTable *)v29->_name._unVal;
          if ( (int)--*(_DWORD *)(v30.nInteger + 4) <= 0 )
          {
            v29->_name._unVal.pTable->Release(this: (struct SQTable *)v29->_name._unVal.nInteger);
            v28 = v61;
          }
        }
      }
      --v22->_targetstack._size;
      if ( v28 != 0 && (int)--v26[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v26 + 8))(a1: v26);
      v31 = this->_fs;
      v32 = (SQFuncState *)v31->_vlocals._vals;
      v63 = v31->_targetstack._vals[v31->_targetstack._size - 1];
      v33 = (&v32->_vlocals._vals)[5 * v63];
      v34 = *(&v32->_returnexp + 5 * v63);
      v35 = v34 & 0x8000000;
      v61 = v34 & 0x8000000;
      if ( (v34 & 0x8000000) != 0 )
        ++v33->_name._unVal.nInteger;
      if ( v34 == 16777217 )
      {
        --v31->_vlocals._size;
        v36 = v31->_vlocals._vals;
        v18 = (v36[v31->_vlocals._size]._name._type & 0x8000000) == 0;
        v32 = (SQFuncState *)&v36[v31->_vlocals._size];
        if ( !v18 )
        {
          v37 = v32->_vlocals._vals;
          if ( --v37->_name._unVal.nInteger <= 0 )
          {
            (*(void (__thiscall **)(SQLocalVarInfo *))(v32->_vlocals._vals->_name._type + 8))(a1: v32->_vlocals._vals);
            v35 = v61;
          }
        }
      }
      --v31->_targetstack._size;
      if ( v35 != 0 && --v33->_name._unVal.nInteger <= 0 )
        (*(void (__thiscall **)(SQLocalVarInfo *))(v33->_name._type + 8))(a1: v33);
      v59.op = 18;
      v38 = SQFuncState::PushTarget(this: v32, n: -1);
      v39 = this->_fs;
      v59._arg0 = v38;
      v59._arg1 = v62;
      v59._arg2 = v63;
      v59._arg3 = 5;
      SQFuncState::AddInstruction(this: v39, i: &v59);
    }
    if ( this->_token != 306 )
      break;
    this->_token = SQLexer::Lex(this: v2);
    SQCompiler::PlusExp(this);
    v3 = this->_fs;
    v4 = v3->_targetstack._vals;
    v5 = v4[v3->_targetstack._size - 1];
    v62 = v4[v3->_targetstack._size - 1];
    v6 = v3->_vlocals._vals;
    v7 = &v6[v5]._name._unVal.pTable->__vftable;
    v8 = v6[v5]._name._type;
    v9 = v8 & 0x8000000;
    v63 = v8 & 0x8000000;
    if ( (v8 & 0x8000000) != 0 )
      ++v7[1];
    if ( v8 == OT_NULL )
    {
      v10 = &v3->_vlocals._vals[--v3->_vlocals._size];
      if ( (v10->_name._type & 0x8000000) != 0 )
      {
        v11.pTable = (SQTable *)v10->_name._unVal;
        if ( (int)--*(_DWORD *)(v11.nInteger + 4) <= 0 )
        {
          v10->_name._unVal.pTable->Release(this: (struct SQTable *)v10->_name._unVal.nInteger);
          v9 = v63;
        }
      }
    }
    --v3->_targetstack._size;
    if ( v9 != 0 && (int)--v7[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
    v12 = this->_fs;
    v13 = (SQFuncState *)v12->_vlocals._vals;
    v61 = v12->_targetstack._vals[v12->_targetstack._size - 1];
    v14 = (&v13->_vlocals._vals)[5 * v61];
    v15 = *(&v13->_returnexp + 5 * v61);
    v16 = v15 & 0x8000000;
    v63 = v15 & 0x8000000;
    if ( (v15 & 0x8000000) != 0 )
      ++v14->_name._unVal.nInteger;
    if ( v15 == 16777217 )
    {
      --v12->_vlocals._size;
      v17 = v12->_vlocals._vals;
      v18 = (v17[v12->_vlocals._size]._name._type & 0x8000000) == 0;
      v13 = (SQFuncState *)&v17[v12->_vlocals._size];
      if ( !v18 )
      {
        v19 = v13->_vlocals._vals;
        if ( --v19->_name._unVal.nInteger <= 0 )
        {
          (*(void (__thiscall **)(SQLocalVarInfo *))(v13->_vlocals._vals->_name._type + 8))(a1: v13->_vlocals._vals);
          v16 = v63;
        }
      }
    }
    --v12->_targetstack._size;
    if ( v16 != 0 && --v14->_name._unVal.nInteger <= 0 )
      (*(void (__thiscall **)(SQLocalVarInfo *))(v14->_name._type + 8))(a1: v14);
    i.op = 18;
    v20 = SQFuncState::PushTarget(this: v13, n: -1);
    v21 = this->_fs;
    i._arg0 = v20;
    i._arg1 = v62;
    i._arg2 = v61;
    i._arg3 = 6;
    SQFuncState::AddInstruction(this: v21, &i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100403C0
// Name: public: void SQCompiler::PlusExp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::PlusExp(SQCompiler *this)
{
  SQLexer *v2; // ecx
  SQFuncState *fs; // esi
  int *vals; // ecx
  int v5; // edx
  SQLocalVarInfo *v6; // eax
  _DWORD *v7; // edi
  tagSQObjectType type; // eax
  sqvector<SQLocalVarInfo> *v9; // edx
  SQLocalVarInfo *v10; // ecx
  tagSQObjectValue v11; // eax
  SQFuncState *v12; // esi
  SQLocalVarInfo *v13; // ecx
  _DWORD *v14; // edi
  tagSQObjectType v15; // eax
  sqvector<SQLocalVarInfo> *v16; // edx
  SQLocalVarInfo *v17; // ecx
  bool v18; // zf
  SQLocalVarInfo *v19; // ecx
  tagSQObjectValue v20; // eax
  SQFuncState *v21; // edi
  int stacksize; // eax
  unsigned int v23; // eax
  int v24; // esi
  unsigned int v25; // eax
  int *v26; // ecx
  SQFuncState *v27; // esi
  SQLocalVarInfo val; // [esp+Ch] [ebp-2Ch] BYREF
  SQInstruction i; // [esp+20h] [ebp-18h] BYREF
  int token; // [esp+28h] [ebp-10h]
  int v31; // [esp+2Ch] [ebp-Ch]
  int v32; // [esp+30h] [ebp-8h]
  sqvector<SQLocalVarInfo> *size; // [esp+34h] [ebp-4h]

  SQCompiler::MultExp(this);
  while ( 1 )
  {
    token = this->_token;
    if ( token != 43 && token != 45 )
      break;
    this->_token = SQLexer::Lex(this: v2);
    SQCompiler::MultExp(this);
    fs = this->_fs;
    vals = fs->_targetstack._vals;
    v5 = vals[fs->_targetstack._size - 1];
    v32 = vals[fs->_targetstack._size - 1];
    v6 = fs->_vlocals._vals;
    v7 = &v6[v5]._name._unVal.pTable->__vftable;
    type = v6[v5]._name._type;
    v9 = (sqvector<SQLocalVarInfo> *)(type & 0x8000000);
    size = (sqvector<SQLocalVarInfo> *)(type & 0x8000000);
    if ( (type & 0x8000000) != 0 )
      ++v7[1];
    if ( type == OT_NULL )
    {
      v10 = &fs->_vlocals._vals[--fs->_vlocals._size];
      if ( (v10->_name._type & 0x8000000) != 0 )
      {
        v11.pTable = (SQTable *)v10->_name._unVal;
        if ( (int)--*(_DWORD *)(v11.nInteger + 4) <= 0 )
        {
          v10->_name._unVal.pTable->Release(this: (struct SQTable *)v10->_name._unVal.nInteger);
          v9 = size;
        }
      }
    }
    --fs->_targetstack._size;
    if ( v9 != nullptr && (int)--v7[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
    v12 = this->_fs;
    v13 = v12->_vlocals._vals;
    v31 = v12->_targetstack._vals[v12->_targetstack._size - 1];
    v14 = &v13[v31]._name._unVal.pTable->__vftable;
    v15 = v13[v31]._name._type;
    v16 = (sqvector<SQLocalVarInfo> *)(v15 & 0x8000000);
    size = (sqvector<SQLocalVarInfo> *)(v15 & 0x8000000);
    if ( (v15 & 0x8000000) != 0 )
      ++v14[1];
    if ( v15 == OT_NULL )
    {
      --v12->_vlocals._size;
      v17 = v12->_vlocals._vals;
      v18 = (v17[v12->_vlocals._size]._name._type & 0x8000000) == 0;
      v19 = &v17[v12->_vlocals._size];
      if ( !v18 )
      {
        v20.pTable = (SQTable *)v19->_name._unVal;
        if ( (int)--*(_DWORD *)(v20.nInteger + 4) <= 0 )
        {
          v19->_name._unVal.pTable->Release(this: (struct SQTable *)v19->_name._unVal.nInteger);
          v16 = size;
        }
      }
    }
    --v12->_targetstack._size;
    if ( v16 != nullptr && (int)--v14[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
    v21 = this->_fs;
    size = (sqvector<SQLocalVarInfo> *)v21->_vlocals._size;
    val._name._type = OT_NULL;
    memset(&val._name._unVal, 0, 12);
    sqvector<SQLocalVarInfo>::push_back(this: size, a2: (int)&v21->_vlocals, &val);
    stacksize = v21->_stacksize;
    if ( v21->_vlocals._size > stacksize )
    {
      if ( stacksize > 255 )
        v21->_errfunc(a1: v21->_errtarget, a2: "internal compiler error: too many locals");
      v21->_stacksize = v21->_vlocals._size;
    }
    v23 = v21->_targetstack._size;
    if ( v21->_targetstack._allocated <= v23 )
    {
      v24 = 2 * v23;
      if ( 2 * v23 == 0 )
        v24 = 4;
      v21->_targetstack._vals = (int *)_g_pMemAlloc->Realloc_2(
                                         this: _g_pMemAlloc,
                                         a2: v21->_targetstack._vals,
                                         a3: 4 * v24);
      v21->_targetstack._allocated = v24;
    }
    v25 = v21->_targetstack._size;
    v26 = &v21->_targetstack._vals[v25];
    v21->_targetstack._size = v25 + 1;
    if ( v26 != nullptr )
      *v26 = (int)size;
    v27 = this->_fs;
    i._arg0 = (unsigned __int8)size;
    i.op = 17;
    i._arg1 = v32;
    i._arg2 = v31;
    i._arg3 = token;
    SQFuncState::AddInstruction(this: v27, &i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100405D0
// Name: public: void SQCompiler::MultExp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::MultExp(SQCompiler *this)
{
  SQLexer *v2; // ecx
  int token; // eax
  SQFuncState *fs; // esi
  int *vals; // ecx
  int v6; // edx
  SQLocalVarInfo *v7; // eax
  _DWORD *v8; // edi
  tagSQObjectType type; // eax
  sqvector<SQLocalVarInfo> *v10; // edx
  SQLocalVarInfo *v11; // ecx
  tagSQObjectValue v12; // eax
  SQFuncState *v13; // esi
  SQLocalVarInfo *v14; // ecx
  _DWORD *v15; // edi
  tagSQObjectType v16; // eax
  sqvector<SQLocalVarInfo> *v17; // edx
  SQLocalVarInfo *v18; // ecx
  bool v19; // zf
  SQLocalVarInfo *v20; // ecx
  tagSQObjectValue v21; // eax
  SQFuncState *v22; // edi
  int stacksize; // eax
  unsigned int v24; // eax
  int v25; // esi
  unsigned int v26; // eax
  int *v27; // ecx
  SQFuncState *v28; // esi
  SQLocalVarInfo val; // [esp+Ch] [ebp-2Ch] BYREF
  SQInstruction i; // [esp+20h] [ebp-18h] BYREF
  int v31; // [esp+28h] [ebp-10h]
  int v32; // [esp+2Ch] [ebp-Ch]
  int v33; // [esp+30h] [ebp-8h]
  sqvector<SQLocalVarInfo> *size; // [esp+34h] [ebp-4h]

  SQCompiler::PrefixedExpr(this);
  while ( 1 )
  {
    token = this->_token;
    v31 = token;
    if ( token != 37 && token != 42 && token != 47 )
      break;
    this->_token = SQLexer::Lex(this: v2);
    SQCompiler::PrefixedExpr(this);
    fs = this->_fs;
    vals = fs->_targetstack._vals;
    v6 = vals[fs->_targetstack._size - 1];
    v33 = vals[fs->_targetstack._size - 1];
    v7 = fs->_vlocals._vals;
    v8 = &v7[v6]._name._unVal.pTable->__vftable;
    type = v7[v6]._name._type;
    v10 = (sqvector<SQLocalVarInfo> *)(type & 0x8000000);
    size = (sqvector<SQLocalVarInfo> *)(type & 0x8000000);
    if ( (type & 0x8000000) != 0 )
      ++v8[1];
    if ( type == OT_NULL )
    {
      v11 = &fs->_vlocals._vals[--fs->_vlocals._size];
      if ( (v11->_name._type & 0x8000000) != 0 )
      {
        v12.pTable = (SQTable *)v11->_name._unVal;
        if ( (int)--*(_DWORD *)(v12.nInteger + 4) <= 0 )
        {
          v11->_name._unVal.pTable->Release(this: (struct SQTable *)v11->_name._unVal.nInteger);
          v10 = size;
        }
      }
    }
    --fs->_targetstack._size;
    if ( v10 != nullptr && (int)--v8[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
    v13 = this->_fs;
    v14 = v13->_vlocals._vals;
    v32 = v13->_targetstack._vals[v13->_targetstack._size - 1];
    v15 = &v14[v32]._name._unVal.pTable->__vftable;
    v16 = v14[v32]._name._type;
    v17 = (sqvector<SQLocalVarInfo> *)(v16 & 0x8000000);
    size = (sqvector<SQLocalVarInfo> *)(v16 & 0x8000000);
    if ( (v16 & 0x8000000) != 0 )
      ++v15[1];
    if ( v16 == OT_NULL )
    {
      --v13->_vlocals._size;
      v18 = v13->_vlocals._vals;
      v19 = (v18[v13->_vlocals._size]._name._type & 0x8000000) == 0;
      v20 = &v18[v13->_vlocals._size];
      if ( !v19 )
      {
        v21.pTable = (SQTable *)v20->_name._unVal;
        if ( (int)--*(_DWORD *)(v21.nInteger + 4) <= 0 )
        {
          v20->_name._unVal.pTable->Release(this: (struct SQTable *)v20->_name._unVal.nInteger);
          v17 = size;
        }
      }
    }
    --v13->_targetstack._size;
    if ( v17 != nullptr && (int)--v15[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v15 + 8))(a1: v15);
    v22 = this->_fs;
    size = (sqvector<SQLocalVarInfo> *)v22->_vlocals._size;
    val._name._type = OT_NULL;
    memset(&val._name._unVal, 0, 12);
    sqvector<SQLocalVarInfo>::push_back(this: size, a2: (int)&v22->_vlocals, &val);
    stacksize = v22->_stacksize;
    if ( v22->_vlocals._size > stacksize )
    {
      if ( stacksize > 255 )
        v22->_errfunc(a1: v22->_errtarget, a2: "internal compiler error: too many locals");
      v22->_stacksize = v22->_vlocals._size;
    }
    v24 = v22->_targetstack._size;
    if ( v22->_targetstack._allocated <= v24 )
    {
      v25 = 2 * v24;
      if ( 2 * v24 == 0 )
        v25 = 4;
      v22->_targetstack._vals = (int *)_g_pMemAlloc->Realloc_2(
                                         this: _g_pMemAlloc,
                                         a2: v22->_targetstack._vals,
                                         a3: 4 * v25);
      v22->_targetstack._allocated = v25;
    }
    v26 = v22->_targetstack._size;
    v27 = &v22->_targetstack._vals[v26];
    v22->_targetstack._size = v26 + 1;
    if ( v27 != nullptr )
      *v27 = (int)size;
    v28 = this->_fs;
    i._arg0 = (unsigned __int8)size;
    i.op = 17;
    i._arg1 = v33;
    i._arg2 = v32;
    i._arg3 = v31;
    SQFuncState::AddInstruction(this: v28, &i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100407F0
// Name: public: void SQCompiler::PrefixedExpr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::PrefixedExpr(SQCompiler *this)
{
  SQLexer *vals; // ecx
  int token; // eax
  bool j; // zf
  int v5; // eax
  SQLexer *v6; // ecx
  SQFuncState *v7; // ecx
  int v8; // esi
  SQFuncState *v9; // ecx
  SQInstruction *v10; // edi
  SQFuncState *v11; // edi
  const char *svalue; // eax
  const SQObjectPtr *type; // eax
  SQLexer *v14; // ecx
  int v15; // eax
  _DWORD *v16; // ecx
  int Constant; // esi
  SQFuncState *v18; // ecx
  unsigned __int8 v19; // al
  SQFuncState *v20; // esi
  SQFuncState *v21; // ecx
  SQFuncState *v22; // ecx
  int v23; // esi
  SQFuncState *v24; // ecx
  SQFuncState *v25; // ecx
  SQFuncState *v26; // ecx
  SQFuncState *v27; // ecx
  char v28; // al
  SQInstruction *v29; // edi
  char v30; // al
  SQLexer *v31; // ecx
  SQCompiler *v32; // ecx
  SQLexer *v33; // ecx
  SQFuncState *v34; // ecx
  SQFuncState *v35; // ecx
  int v36; // esi
  SQFuncState *v37; // ecx
  unsigned __int8 v38; // al
  SQFuncState *fs; // esi
  SQCompiler *size; // ecx
  SQLexer *v41; // ecx
  int v42; // esi
  SQFuncState *v43; // ecx
  int v44; // esi
  SQFuncState *v45; // ecx
  unsigned __int8 v46; // al
  SQFuncState *v47; // esi
  const char *v48; // [esp+0h] [ebp-78h]
  int pos; // [esp+10h] [ebp-68h]
  unsigned __int8 closure; // [esp+14h] [ebp-64h]
  char closurea; // [esp+14h] [ebp-64h]
  int key; // [esp+18h] [ebp-60h]
  char tablea; // [esp+1Ch] [ebp-5Ch]
  unsigned __int8 tableb; // [esp+1Ch] [ebp-5Ch]
  int table; // [esp+1Ch] [ebp-5Ch]
  int v56; // [esp+20h] [ebp-58h] BYREF
  char v57; // [esp+24h] [ebp-54h]
  char v58; // [esp+25h] [ebp-53h]
  __int16 v59; // [esp+26h] [ebp-52h]
  SQInstruction i; // [esp+28h] [ebp-50h] BYREF
  SQInstruction v61; // [esp+30h] [ebp-48h] BYREF
  int v62; // [esp+38h] [ebp-40h] BYREF
  char v63; // [esp+3Ch] [ebp-3Ch]
  char v64; // [esp+3Dh] [ebp-3Bh]
  char v65; // [esp+3Eh] [ebp-3Ah]
  char v66; // [esp+3Fh] [ebp-39h]
  int v67; // [esp+40h] [ebp-38h] BYREF
  char v68; // [esp+44h] [ebp-34h]
  char v69; // [esp+45h] [ebp-33h]
  __int16 v70; // [esp+46h] [ebp-32h]
  SQInstruction v71; // [esp+48h] [ebp-30h] BYREF
  SQInstruction v72; // [esp+50h] [ebp-28h] BYREF
  SQObjectPtr v73; // [esp+58h] [ebp-20h] BYREF
  _DWORD v74[2]; // [esp+60h] [ebp-18h] BYREF
  int len; // [esp+68h] [ebp-10h] BYREF
  ExpState result; // [esp+70h] [ebp-8h] BYREF

  pos = SQCompiler::Factor(this);
  token = this->_token;
  for ( j = this->_token == 91; this->_token <= 91; j = this->_token == 91 )
  {
    if ( j )
    {
      if ( this->_lex._prevtoken == 10 )
        SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C348._lex._up, s: v48);
      this->_token = SQLexer::Lex(this: vals);
      SQCompiler::Expression(this, &result, funcarg: false);
      if ( this->_token != 93 )
        SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x5D);
      this->_token = SQLexer::Lex(this: v33);
      pos = -1;
      if ( SQCompiler::NeedGet(this) )
      {
        tableb = SQFuncState::PopTarget(this: v34);
        v36 = SQFuncState::PopTarget(this: v35);
        v72.op = 14;
        v38 = SQFuncState::PushTarget(this: v37, n: -1);
        v72._arg1 = v36;
        fs = this->_fs;
        v72._arg0 = v38;
        v72._arg2 = tableb;
        v72._arg3 = 0;
        SQFuncState::AddInstruction(this: fs, i: &v72);
      }
      vals = (SQLexer *)this->_expstates._vals;
      *((_DWORD *)vals + 2 * this->_expstates._size - 1) = -2;
      this->_expstates._vals[this->_expstates._size - 1]._freevar = false;
      goto LABEL_28;
    }
    if ( token == 40 )
    {
      if ( this->_expstates._vals[this->_expstates._size - 1]._deref == -1 )
      {
        v71.op = 10;
        v71._arg0 = SQFuncState::PushTarget(this: (SQFuncState *)vals, n: -1);
        v71._arg1 = 0;
        *(_WORD *)&v71._arg2 = 0;
        v29 = &v71;
      }
      else if ( pos >= 0 )
      {
        v30 = SQFuncState::PushTarget(this: (SQFuncState *)vals, n: -1);
        v68 = 10;
        v69 = v30;
        v67 = 0;
        v70 = 0;
        v29 = (SQInstruction *)&v67;
      }
      else
      {
        key = SQFuncState::PopTarget(this: (SQFuncState *)vals);
        tablea = SQFuncState::PopTarget(this: v25);
        closurea = SQFuncState::PushTarget(this: v26, n: -1);
        v28 = SQFuncState::PushTarget(this: v27, n: -1);
        v64 = closurea;
        v63 = 7;
        v62 = key;
        v65 = tablea;
        v66 = v28;
        v29 = (SQInstruction *)&v62;
      }
      SQFuncState::AddInstruction(this: this->_fs, i: v29);
      this->_expstates._vals[this->_expstates._size - 1]._deref = -1;
      this->_token = SQLexer::Lex(this: v31);
      SQCompiler::FunctionCallArgs(this: v32);
      goto LABEL_28;
    }
    if ( token != 46 )
      return;
    pos = -1;
    v5 = SQLexer::Lex(this: vals);
    this->_token = v5;
    if ( v5 == 305 )
    {
      this->_token = SQLexer::Lex(this: v6);
      if ( !SQCompiler::NeedGet(this) )
        SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C348._lex._currentline, s: v48);
      v8 = SQFuncState::PopTarget(this: v7);
      v57 = 33;
      v58 = SQFuncState::PushTarget(this: v9, n: -1);
      v56 = v8;
      v59 = 0;
      v10 = (SQInstruction *)&v56;
    }
    else
    {
      if ( v5 != 258 && v5 != 310 )
        SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C274, s: "IDENTIFIER");
      v11 = this->_fs;
      svalue = this->_lex._svalue;
      v73._type = OT_NULL;
      v73._unVal.nInteger = 0;
      type = (const SQObjectPtr *)SQFuncState::CreateString(this: v11, s: svalue, (int)&len)._type;
      SQObjectPtr::operator=(this: &v73, obj: type);
      v15 = SQLexer::Lex(this: v14);
      v16 = &v73._unVal.pTable->__vftable;
      this->_token = v15;
      v74[0] = v73._type;
      v74[1] = v16;
      if ( (v73._type & 0x8000000) != 0 && (int)--v16[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v16 + 8))(a1: v16);
      Constant = SQFuncState::GetConstant(this: (SQFuncState *)v74, cons: (const tagSQObject *)this->_fs);
      i.op = 1;
      v19 = SQFuncState::PushTarget(this: v18, n: -1);
      i._arg1 = Constant;
      v20 = this->_fs;
      i._arg0 = v19;
      *(_WORD *)&i._arg2 = 0;
      SQFuncState::AddInstruction(this: v20, &i);
      if ( !SQCompiler::NeedGet(this) )
        goto LABEL_16;
      closure = SQFuncState::PopTarget(this: v21);
      v23 = SQFuncState::PopTarget(this: v22);
      v61._arg0 = SQFuncState::PushTarget(this: v24, n: -1);
      v61.op = 14;
      v61._arg1 = v23;
      v61._arg2 = closure;
      v61._arg3 = 0;
      v10 = &v61;
    }
    SQFuncState::AddInstruction(this: this->_fs, i: v10);
LABEL_16:
    this->_expstates._vals[this->_expstates._size - 1]._deref = -2;
    vals = (SQLexer *)this->_expstates._vals;
    *((_BYTE *)vals + 8 * this->_expstates._size - 6) = 0;
LABEL_28:
    token = this->_token;
  }
  if ( (unsigned int)(token - 303) <= 1 )
  {
    size = (SQCompiler *)this->_expstates._size;
    if ( this->_expstates._vals[(int)size - 1]._deref != -1
      && !SQCompiler::IsEndOfStatement(this: size, a2: &this->_token) )
    {
      v42 = this->_token;
      table = this->_token;
      this->_token = SQLexer::Lex(this: v41);
      if ( pos >= 0 )
      {
        v44 = SQFuncState::PopTarget(this: v43);
        v72.op = 39;
        v46 = SQFuncState::PushTarget(this: v45, n: -1);
        v72._arg1 = v44;
        v47 = this->_fs;
        v72._arg0 = v46;
        v72._arg2 = 0;
        v72._arg3 = table != 304 ? 1 : -1;
        SQFuncState::AddInstruction(this: v47, i: &v72);
      }
      else
      {
        SQCompiler::Emit2ArgsOP(this: (SQCompiler *)v43, op: (int)this, p3: 0x26u, p3a: 2 * (v42 != 304) - 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040C40
// Name: public: int SQCompiler::Factor(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall SQCompiler::Factor(SQCompiler *this, SQOpcode key)
{
  SQFuncState *v3; // ecx
  SQFuncState *v4; // eax
  SQFuncState *v5; // ecx
  tagSQObjectType v6; // esi
  SQObjectPtr *p_constval; // edi
  SQLexer *v8; // ecx
  int v10; // esi
  tagSQObjectType v11; // esi
  SQFuncState *v12; // ecx
  char v13; // al
  char v14; // al
  SQFuncState *v15; // esi
  int v16; // esi
  SQLexer *v17; // ecx
  int v18; // eax
  SQLexer *v19; // ecx
  tagSQObjectType v20; // eax
  SQFuncState *v21; // esi
  char v22; // al
  SQFuncState *v23; // esi
  SQLexer *v24; // ecx
  SQFuncState *v25; // ecx
  char v26; // al
  SQFuncState *v27; // esi
  int v28; // eax
  SQLexer *v29; // ecx
  SQLexer *v30; // ecx
  SQFuncState *v31; // ecx
  tagSQObjectType v32; // esi
  SQFuncState *v33; // ecx
  int v34; // ecx
  int *type; // eax
  int v36; // edx
  int v37; // eax
  SQFuncState *v38; // edi
  int LocalVariable; // eax
  SQFuncState *v40; // ecx
  int v41; // esi
  SQFuncState *v42; // ecx
  int v43; // esi
  char v44; // dl
  SQFuncState *v45; // esi
  SQFuncState *v46; // ecx
  int v47; // eax
  const char *v48; // eax
  SQFuncState *v49; // edi
  const SQObjectPtr *v50; // eax
  SQLexer *v51; // ecx
  int v52; // eax
  bool v53; // zf
  int v54; // esi
  _DWORD *v55; // edi
  SQObjectPtr *v56; // ecx
  SQFuncState *v57; // ecx
  int v58; // esi
  tagSQObjectValue v59; // eax
  char v60; // cl
  SQFuncState *v61; // ecx
  int v62; // esi
  SQFuncState *v63; // esi
  int v64; // esi
  SQFuncState *v65; // ecx
  char v66; // al
  SQFuncState *v67; // esi
  SQCompiler *v68; // ecx
  SQFuncState *v69; // ecx
  char v70; // al
  SQFuncState *v71; // esi
  char v72; // al
  SQFuncState *v73; // esi
  BOOL v74; // esi
  SQCompiler *v75; // ecx
  const tagSQObject *v76; // [esp-8h] [ebp-74h]
  const char *v77; // [esp+0h] [ebp-6Ch]
  int v78; // [esp+10h] [ebp-5Ch] BYREF
  int v79; // [esp+18h] [ebp-54h] BYREF
  _BYTE v80[8]; // [esp+20h] [ebp-4Ch] BYREF
  _BYTE v81[8]; // [esp+28h] [ebp-44h] BYREF
  ExpState v82; // [esp+30h] [ebp-3Ch] BYREF
  ExpState v83; // [esp+38h] [ebp-34h] BYREF
  int len; // [esp+40h] [ebp-2Ch] BYREF
  tagSQObject constant; // [esp+48h] [ebp-24h] BYREF
  tagSQObjectValue v86; // [esp+50h] [ebp-1Ch] BYREF
  _DWORD *v87; // [esp+54h] [ebp-18h]
  SQObjectPtr constval; // [esp+58h] [ebp-14h] BYREF
  int apos; // [esp+60h] [ebp-Ch] BYREF
  int v90; // [esp+64h] [ebp-8h]
  int keya; // [esp+74h] [ebp+8h]
  tagSQObjectType keyb; // [esp+74h] [ebp+8h]
  bool key_3; // [esp+77h] [ebp+Bh]

  v3 = *(SQFuncState **)key;
  v4 = *(SQFuncState **)key;
  if ( *(int *)key > 298 )
  {
    switch ( (unsigned int)v4 )
    {
      case 0x12Bu:
        LOBYTE(v87) = 21;
        v72 = SQFuncState::PushTarget(this: v3, n: -1);
        v73 = *(SQFuncState **)(key + 4);
        BYTE1(v87) = v72;
        v86.nInteger = 0;
        HIWORD(v87) = 0;
        SQFuncState::AddInstruction(this: v73, i: (SQInstruction *)&v86);
        *(_DWORD *)(*(_DWORD *)(key + 100) + 8 * *(_DWORD *)(key + 104) - 4) = -2;
        *(_DWORD *)key = 46;
        return -1;
      case 0x12Eu:
      case 0x136u:
$LN48:
        v34 = *(_DWORD *)(key + 104);
        *(_BYTE *)(*(_DWORD *)(key + 100) + 8 * v34 - 6) = 0;
        switch ( *(_DWORD *)key )
        {
          case 0x102:
            type = (int *)SQFuncState::CreateString(
                            this: (SQFuncState *)*(_DWORD *)(key + 4),
                            s: (const char *)*(_DWORD *)(key + 40),
                            len: (int)&v79)._type;
            break;
          case 0x12E:
            type = (int *)SQFuncState::CreateString(
                            this: (SQFuncState *)*(_DWORD *)(key + 4),
                            s: (const char *)&stru_1009C274._lex._longstr,
                            len: (int)v80)._type;
            break;
          case 0x136:
            type = (int *)SQFuncState::CreateString(
                            this: (SQFuncState *)*(_DWORD *)(key + 4),
                            s: "constructor",
                            len: (int)v81)._type;
            break;
          default:
            goto LABEL_44;
        }
        v34 = *type;
        v36 = type[1];
        apos = *type;
        v90 = v36;
LABEL_44:
        v37 = SQLexer::Lex(this: (SQLexer *)v34);
        v38 = *(SQFuncState **)(key + 4);
        *(_DWORD *)key = v37;
        LocalVariable = SQFuncState::GetLocalVariable(this: v38, name: (const tagSQObject *)&apos);
        v41 = LocalVariable;
        if ( LocalVariable != -1 )
        {
          SQFuncState::PushTarget(this: v40, n: LocalVariable);
          *(_DWORD *)(*(_DWORD *)(key + 100) + 8 * *(_DWORD *)(key + 104) - 4) = v41;
          return *(_DWORD *)(*(_DWORD *)(key + 100) + 8 * *(_DWORD *)(key + 104) - 4);
        }
        keyb = SQFuncState::GetOuterVariable(this: v38, name: (const tagSQObject *)&apos);
        if ( keyb != -1 )
        {
          v42 = *(SQFuncState **)(key + 104);
          v43 = *(_DWORD *)(key + 100) + 8 * (_DWORD)v42 - 8;
          *(_DWORD *)(v43 + 4) = SQFuncState::PushTarget(this: v42, n: -1);
          v44 = *(_BYTE *)(*(_DWORD *)(key + 100) + 8 * *(_DWORD *)(key + 104) - 4);
          v45 = *(SQFuncState **)(key + 4);
          LOBYTE(constval._unVal.fFloat) = 27;
          BYTE1(constval._unVal.pTable) = v44;
          constval._type = keyb;
          HIWORD(constval._unVal.pArray) = 0;
          SQFuncState::AddInstruction(this: v45, i: (SQInstruction *)&constval);
          *(_BYTE *)(*(_DWORD *)(key + 100) + 8 * *(_DWORD *)(key + 104) - 6) = 1;
          return *(_DWORD *)(*(_DWORD *)(key + 100) + 8 * *(_DWORD *)(key + 104) - 4);
        }
        if ( !SQFuncState::IsConstant(this: v38, name: (const tagSQObject *)&apos, e: &constant) )
        {
          SQFuncState::PushTarget(this: v46, n: 0);
          v64 = SQFuncState::GetConstant(this: (SQFuncState *)&apos, cons: *(const tagSQObject **)(key + 4));
          LOBYTE(v87) = 1;
          v66 = SQFuncState::PushTarget(this: v65, n: -1);
          v86.nInteger = v64;
          v67 = *(SQFuncState **)(key + 4);
          BYTE1(v87) = v66;
          HIWORD(v87) = 0;
          SQFuncState::AddInstruction(this: v67, i: (SQInstruction *)&v86);
          if ( SQCompiler::NeedGet(this: (SQCompiler *)key) )
            SQCompiler::Emit2ArgsOP(this: v68, op: key, p3: 0xEu, p3a: 0);
          *(_DWORD *)(*(_DWORD *)(key + 100) + 8 * *(_DWORD *)(key + 104) - 4) = -2;
          return *(_DWORD *)(*(_DWORD *)(key + 100) + 8 * *(_DWORD *)(key + 104) - 4);
        }
        constval._type = OT_NULL;
        constval._unVal.nInteger = 0;
        if ( constant._type == OT_TABLE )
        {
          if ( *(_DWORD *)key != 46 )
            SQCompiler::Error(a1: key, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x2E);
          v47 = SQLexer::Lex(this: (SQLexer *)v46);
          *(_DWORD *)key = v47;
          if ( v47 != 258 && v47 != 310 )
            SQCompiler::Error(a1: key, this: (SQCompiler *)&stru_1009C274, s: "IDENTIFIER");
          v48 = *(const char **)(key + 40);
          v86.nInteger = 16777217;
          v49 = *(SQFuncState **)(key + 4);
          v87 = nullptr;
          v50 = (const SQObjectPtr *)SQFuncState::CreateString(this: v49, s: v48, len: (int)&v78)._type;
          SQObjectPtr::operator=(this: (SQObjectPtr *)&v86, obj: v50);
          v52 = SQLexer::Lex(this: v51);
          v54 = v86.nInteger & 0x8000000;
          v53 = (v86.nInteger & 0x8000000) == 0;
          v55 = v87;
          *(_DWORD *)key = v52;
          if ( !v53 && (int)--v55[1] <= 0 )
            (*(void (__thiscall **)(_DWORD *))(*v55 + 8))(a1: v55);
          v87 = v55;
          if ( v54 != 0 )
            ++v55[1];
          key_3 = !SQTable::Get(this: constant._unVal.pTable, key: (const SQObjectPtr *)&v86, val: &constval);
          SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&v86);
          if ( key_3 )
          {
            SQObjectPtr::Null(this: v56, a2: (int *)&constval);
            SQCompiler::Error(
              a1: key,
              this: (SQCompiler *)&stru_1009C348._errorjmp[2],
              s: (const char *)(v90 + 28),
              v55 + 7);
          }
        }
        else
        {
          SQObjectPtr::operator=(this: &constval, obj: (const SQObjectPtr *)&constant);
        }
        v57 = *(SQFuncState **)(key + 104);
        v58 = *(_DWORD *)(key + 100) + 8 * (_DWORD)v57 - 8;
        *(_DWORD *)(v58 + 4) = SQFuncState::PushTarget(this: v57, n: -1);
        if ( constval._type == OT_INTEGER )
        {
          v59.pTable = (SQTable *)constval._unVal;
          if ( constval._unVal.nInteger >= 0 )
          {
            v60 = *(_BYTE *)(*(_DWORD *)(key + 100) + 8 * *(_DWORD *)(key + 104) - 4);
            LOBYTE(v87) = 2;
LABEL_68:
            v86.pTable = v59.pTable;
            goto LABEL_69;
          }
        }
        else if ( constval._type == OT_FLOAT )
        {
          v60 = *(_BYTE *)(*(_DWORD *)(key + 100) + 8 * *(_DWORD *)(key + 104) - 4);
          LOBYTE(v87) = 3;
          v86.pTable = (SQTable *)constval._unVal;
LABEL_69:
          v63 = *(SQFuncState **)(key + 4);
          BYTE1(v87) = v60;
          HIWORD(v87) = 0;
          SQFuncState::AddInstruction(this: v63, i: (SQInstruction *)&v86);
          *(_BYTE *)(*(_DWORD *)(key + 100) + 8 * *(_DWORD *)(key + 104) - 6) = 1;
          SQObjectPtr::~SQObjectPtr(this: (SQLocalVarInfo *)&constval);
          return *(_DWORD *)(*(_DWORD *)(key + 100) + 8 * *(_DWORD *)(key + 104) - 4);
        }
        v61 = *(SQFuncState **)(key + 100);
        v62 = (int)v61 + 8 * *(_DWORD *)(key + 104) - 8;
        v59.nInteger = SQFuncState::GetConstant(this: v61, cons: *(const tagSQObject **)(key + 4));
        v60 = *(_BYTE *)(v62 + 4);
        LOBYTE(v87) = 1;
        goto LABEL_68;
      case 0x12Fu:
      case 0x130u:
        SQCompiler::PrefixIncDec(this: (SQCompiler *)v3, token: key);
        return -1;
      case 0x131u:
        *(_DWORD *)key = SQLexer::Lex(this: (SQLexer *)v3);
        v70 = SQFuncState::PushTarget(this: v69, n: -1);
        v71 = *(SQFuncState **)(key + 4);
        LOBYTE(v87) = 33;
        BYTE1(v87) = v70;
        v86.nInteger = 0;
        HIWORD(v87) = 0;
        SQFuncState::AddInstruction(this: v71, i: (SQInstruction *)&v86);
        return -1;
      case 0x133u:
        *(_DWORD *)key = SQLexer::Lex(this: (SQLexer *)v3);
        SQCompiler::ClassExp(this: v75);
        return -1;
      case 0x139u:
        *(_DWORD *)key = SQLexer::Lex(this: (SQLexer *)v3);
        LOBYTE(constval._unVal.fFloat) = 28;
        v26 = SQFuncState::PushTarget(this: v25, n: -1);
        constval._type = 0;
        goto LABEL_31;
      case 0x13Au:
        v28 = SQLexer::Lex(this: (SQLexer *)v3);
        *(_DWORD *)key = v28;
        if ( v28 != 91 )
          SQCompiler::Error(a1: key, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x5B);
        *(_DWORD *)key = SQLexer::Lex(this: v29);
        SQCompiler::Expression(this: (SQCompiler *)key, result: &v82, funcarg: false);
        if ( *(_DWORD *)key != 93 )
          SQCompiler::Error(a1: key, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x5D);
        *(_DWORD *)key = SQLexer::Lex(this: v30);
        v32 = SQFuncState::PopTarget(this: v31);
        v26 = SQFuncState::PushTarget(this: v33, n: -1);
        LOBYTE(constval._unVal.fFloat) = 29;
        constval._type = v32;
LABEL_31:
        v27 = *(SQFuncState **)(key + 4);
        BYTE1(constval._unVal.pTable) = v26;
        HIWORD(constval._unVal.pArray) = 0;
        SQFuncState::AddInstruction(this: v27, i: (SQInstruction *)&constval);
        return -1;
      case 0x13Bu:
      case 0x13Cu:
        LOBYTE(v87) = 22;
        v74 = v3 == (SQFuncState *)315;
        BYTE1(v87) = SQFuncState::PushTarget(this: v3, n: -1);
        v86.nInteger = v74;
        HIWORD(v87) = 0;
        p_constval = (SQObjectPtr *)&v86;
LABEL_7:
        SQFuncState::AddInstruction(this: *(SQFuncState **)(key + 4), i: (SQInstruction *)p_constval);
LABEL_8:
        *(_DWORD *)key = SQLexer::Lex(this: v8);
        return -1;
      default:
LABEL_79:
        SQCompiler::Error(a1: key, this: (SQCompiler *)&stru_1009C348._errorjmp[9], s: v77);
    }
  }
  if ( *(_DWORD *)key != 298 )
  {
    switch ( (unsigned int)v4 )
    {
      case 0x21u:
      case 0x2Du:
      case 0x7Eu:
      case 0x11Cu:
      case 0x11Fu:
        break;
      case 0x28u:
        *(_DWORD *)key = SQLexer::Lex(this: (SQLexer *)v3);
        SQCompiler::CommaExpr(this: (SQCompiler *)key);
        if ( *(_DWORD *)key != 41 )
          SQCompiler::Error(a1: key, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x29);
        goto LABEL_8;
      case 0x5Bu:
        LOBYTE(constval._unVal.fFloat) = 31;
        v14 = SQFuncState::PushTarget(this: v3, n: -1);
        v15 = *(SQFuncState **)(key + 4);
        BYTE1(constval._unVal.pTable) = v14;
        constval._type = 0;
        HIWORD(constval._unVal.pArray) = 0;
        SQFuncState::AddInstruction(this: v15, i: (SQInstruction *)&constval);
        v16 = *(_DWORD *)(*(_DWORD *)(key + 4) + 100) - 1;
        v90 = v16;
        keya = 0;
        v18 = SQLexer::Lex(this: v17);
        *(_DWORD *)key = v18;
        if ( v18 != 93 )
        {
          LOBYTE(constval._unVal.fFloat) = 32;
          HIWORD(constval._unVal.pArray) = 0;
          do
          {
            SQCompiler::Expression(this: (SQCompiler *)key, result: &v83, funcarg: false);
            if ( *(_DWORD *)key == 44 )
              *(_DWORD *)key = SQLexer::Lex(this: v19);
            v20 = SQFuncState::PopTarget(this: (SQFuncState *)v19);
            v21 = *(SQFuncState **)(key + 4);
            BYTE1(constval._unVal.pTable) = v21->_targetstack._vals[v21->_targetstack._size - 1];
            constval._type = v20;
            SQFuncState::AddInstruction(this: v21, i: (SQInstruction *)&constval);
            ++keya;
          }
          while ( *(_DWORD *)key != 93 );
          v16 = v90;
        }
        *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(key + 4) + 96) + 8 * v16) = keya;
        goto LABEL_8;
      case 0x7Bu:
        v22 = SQFuncState::PushTarget(this: v3, n: -1);
        v23 = *(SQFuncState **)(key + 4);
        LOBYTE(constval._unVal.fFloat) = 30;
        BYTE1(constval._unVal.pTable) = v22;
        constval._type = 0;
        HIWORD(constval._unVal.pArray) = 0;
        SQFuncState::AddInstruction(this: v23, i: (SQInstruction *)&constval);
        *(_DWORD *)key = SQLexer::Lex(this: v24);
        SQCompiler::ParseTableOrClass(this: (SQCompiler *)key, separator: 44, terminator: 125);
        return -1;
      case 0x102u:
        goto $LN48;
      case 0x103u:
        SQFuncState::CreateString(this: *(SQFuncState **)(key + 4), s: *(const char **)(key + 40), (int)&len);
        v6 = SQFuncState::GetConstant(this: v5, cons: *(const tagSQObject **)(key + 4));
        LOBYTE(constval._unVal.fFloat) = 1;
        goto LABEL_5;
      case 0x104u:
        v10 = *(_DWORD *)(key + 44);
        if ( v10 < 0 )
        {
          v76 = *(const tagSQObject **)(key + 4);
          constant._type = OT_INTEGER;
          constant._unVal.nInteger = v10;
          v11 = SQFuncState::GetConstant(this: (SQFuncState *)&constant, cons: v76);
          v13 = SQFuncState::PushTarget(this: v12, n: -1);
          LOBYTE(constval._unVal.fFloat) = 1;
          constval._type = v11;
          BYTE1(constval._unVal.pTable) = v13;
        }
        else
        {
          LOBYTE(constval._unVal.fFloat) = 2;
          constval._type = v10;
          BYTE1(constval._unVal.pTable) = SQFuncState::PushTarget(this: v3, n: -1);
        }
        goto LABEL_6;
      case 0x105u:
        v6 = *(_DWORD *)(key + 48);
        LOBYTE(constval._unVal.fFloat) = 3;
LABEL_5:
        BYTE1(constval._unVal.pTable) = SQFuncState::PushTarget(this: v3, n: -1);
        constval._type = v6;
        goto LABEL_6;
      case 0x106u:
        SQCompiler::DelegateExpr(this: (SQCompiler *)v3);
        return -1;
      case 0x107u:
        SQCompiler::DeleteExpr(this: (SQCompiler *)v3);
        return -1;
      case 0x116u:
        LOBYTE(constval._unVal.fFloat) = 20;
        BYTE1(constval._unVal.pTable) = SQFuncState::PushTarget(this: v3, n: -1);
        constval._type = 1;
LABEL_6:
        p_constval = &constval;
        HIWORD(constval._unVal.pArray) = 0;
        goto LABEL_7;
      case 0x11Du:
        SQCompiler::FunctionExp(this: (SQCompiler *)v3, ftype: *(_DWORD *)key);
        return -1;
      default:
        goto LABEL_79;
    }
  }
  SQCompiler::UnaryOP(this: (SQCompiler *)v3, op: key);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100415A0
// Name: public: void SQCompiler::UnaryOP(enum SQOpcode)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::UnaryOP(SQCompiler *this, SQCompiler *op, unsigned __int8 opa)
{
  SQFuncState *v3; // ecx
  int v4; // esi
  SQFuncState *v5; // ecx
  unsigned __int8 v6; // al
  SQFuncState *fs; // esi
  SQInstruction i; // [esp+10h] [ebp-8h] BYREF

  op->_token = SQLexer::Lex((SQLexer *)this);
  SQCompiler::PrefixedExpr(this: op);
  v4 = SQFuncState::PopTarget(this: v3);
  i.op = opa;
  v6 = SQFuncState::PushTarget(this: v5, n: -1);
  i._arg1 = v4;
  fs = op->_fs;
  i._arg0 = v6;
  *(_WORD *)&i._arg2 = 0;
  SQFuncState::AddInstruction(this: fs, &i);
}

//------------------------------------------------------------------------------
// Address: 0x10041600
// Name: public: bool SQCompiler::NeedGet(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SQCompiler::NeedGet(SQCompiler *this)
{
  int token; // edx
  int v2; // eax

  token = this->_token;
  v2 = this->_token;
  if ( this->_token > 290 )
  {
    switch ( v2 )
    {
      case 303:
      case 304:
      case 317:
      case 318:
      case 319:
        return false;
      default:
        return !this->_expstates._vals[this->_expstates._size - 1]._class_or_delete || token == 46 || token == 91;
    }
  }
  if ( v2 >= 289 || v2 == 40 || v2 == 61 || v2 == 281 )
    return false;
  return !this->_expstates._vals[this->_expstates._size - 1]._class_or_delete || token == 46 || token == 91;
}

//------------------------------------------------------------------------------
// Address: 0x10041680
// Name: public: void SQCompiler::FunctionCallArgs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::FunctionCallArgs(SQCompiler *this, SQCompiler *nargs)
{
  bool v3; // zf
  SQFuncState *fs; // esi
  unsigned int v5; // eax
  int v6; // eax
  SQLocalVarInfo *vals; // edx
  SQFuncState *v8; // ecx
  _DWORD *v9; // edi
  tagSQObjectType type; // eax
  int v11; // edx
  SQLocalVarInfo *v12; // ecx
  SQLocalVarInfo *v13; // eax
  unsigned __int8 v14; // al
  SQFuncState *v15; // esi
  int v16; // eax
  SQFuncState *v17; // esi
  SQLocalVarInfo *v18; // edx
  _DWORD *v19; // edi
  tagSQObjectType v20; // eax
  int v21; // edx
  SQLocalVarInfo *v22; // ecx
  SQLocalVarInfo *v23; // ecx
  tagSQObjectValue v24; // eax
  SQFuncState *v25; // esi
  SQLocalVarInfo *v26; // ecx
  _DWORD *v27; // edi
  tagSQObjectType v28; // eax
  int v29; // edx
  SQLocalVarInfo *v30; // ecx
  SQLocalVarInfo *v31; // ecx
  tagSQObjectValue v32; // eax
  SQFuncState *v33; // esi
  SQFuncState *v34; // ecx
  SQLocalVarInfo *v35; // edi
  int v36; // eax
  int v37; // edx
  SQLocalVarInfo *v38; // ecx
  SQLocalVarInfo *v39; // eax
  unsigned __int8 v40; // al
  SQFuncState *v41; // esi
  const char *v42; // [esp+0h] [ebp-2Ch]
  ExpState result; // [esp+Ch] [ebp-20h] BYREF
  SQInstruction i; // [esp+14h] [ebp-18h] BYREF
  SQInstruction v45; // [esp+1Ch] [ebp-10h] BYREF
  int v46; // [esp+24h] [ebp-8h]
  int nargsa; // [esp+34h] [ebp+8h]

  v3 = nargs->_token == 41;
  nargsa = 1;
  if ( !v3 )
  {
    do
    {
      SQCompiler::Expression(this: nargs, &result, funcarg: true);
      fs = nargs->_fs;
      this = (SQCompiler *)fs->_targetstack._size;
      v5 = fs->_targetstack._vals[(_DWORD)this - 1];
      if ( v5 < fs->_vlocals._size )
      {
        this = (SQCompiler *)fs->_vlocals._vals;
        if ( *(&this->_token + 5 * v5) != 16777217 )
        {
          v6 = fs->_targetstack._vals[fs->_targetstack._size - 1];
          vals = fs->_vlocals._vals;
          v8 = (SQFuncState *)(5 * v6);
          v9 = &vals[v6]._name._unVal.pTable->__vftable;
          *(_DWORD *)&v45.op = v6;
          type = vals[v6]._name._type;
          v11 = type & 0x8000000;
          v46 = type & 0x8000000;
          if ( (type & 0x8000000) != 0 )
            ++v9[1];
          if ( type == OT_NULL )
          {
            --fs->_vlocals._size;
            v12 = fs->_vlocals._vals;
            v3 = (v12[fs->_vlocals._size]._name._type & 0x8000000) == 0;
            v8 = (SQFuncState *)&v12[fs->_vlocals._size];
            if ( !v3 )
            {
              v13 = v8->_vlocals._vals;
              if ( --v13->_name._unVal.nInteger <= 0 )
              {
                (*(void (__thiscall **)(SQLocalVarInfo *))(v8->_vlocals._vals->_name._type + 8))(a1: v8->_vlocals._vals);
                v11 = v46;
              }
            }
          }
          --fs->_targetstack._size;
          if ( v11 != 0 && (int)--v9[1] <= 0 )
            (*(void (__thiscall **)(_DWORD *))(*v9 + 8))(a1: v9);
          i.op = 10;
          v14 = SQFuncState::PushTarget(this: v8, n: -1);
          v15 = nargs->_fs;
          i._arg0 = v14;
          i._arg1 = *(_DWORD *)&v45.op;
          *(_WORD *)&i._arg2 = 0;
          SQFuncState::AddInstruction(this: v15, &i);
        }
      }
      ++nargsa;
      if ( nargs->_token == 44 )
      {
        v16 = SQLexer::Lex((SQLexer *)this);
        nargs->_token = v16;
        if ( v16 == 41 )
          SQCompiler::Error(a1: (int)nargs, this: (SQCompiler *)&stru_1009C348._errorjmp[14], s: v42);
      }
    }
    while ( nargs->_token != 41 );
  }
  nargs->_token = SQLexer::Lex((SQLexer *)this);
  if ( nargsa - 1 > 0 )
  {
    v46 = nargsa - 1;
    do
    {
      v17 = nargs->_fs;
      v18 = v17->_vlocals._vals;
      v19 = &v18[v17->_targetstack._vals[v17->_targetstack._size - 1]]._name._unVal.pTable->__vftable;
      v20 = v18[v17->_targetstack._vals[v17->_targetstack._size - 1]]._name._type;
      v21 = v20 & 0x8000000;
      *(_DWORD *)&v45.op = v20 & 0x8000000;
      if ( (v20 & 0x8000000) != 0 )
        ++v19[1];
      if ( v20 == OT_NULL )
      {
        --v17->_vlocals._size;
        v22 = v17->_vlocals._vals;
        v3 = (v22[v17->_vlocals._size]._name._type & 0x8000000) == 0;
        v23 = &v22[v17->_vlocals._size];
        if ( !v3 )
        {
          v24.pTable = (SQTable *)v23->_name._unVal;
          if ( (int)--*(_DWORD *)(v24.nInteger + 4) <= 0 )
          {
            v23->_name._unVal.pTable->Release(this: (struct SQTable *)v23->_name._unVal.nInteger);
            v21 = *(_DWORD *)&v45.op;
          }
        }
      }
      --v17->_targetstack._size;
      if ( v21 != 0 && (int)--v19[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v19 + 8))(a1: v19);
      --v46;
    }
    while ( v46 != 0 );
  }
  v25 = nargs->_fs;
  v26 = v25->_vlocals._vals;
  *(_DWORD *)&i.op = v25->_targetstack._vals[v25->_targetstack._size - 1];
  v27 = &v26[*(_DWORD *)&i.op]._name._unVal.pTable->__vftable;
  v28 = v26[*(_DWORD *)&i.op]._name._type;
  v29 = v28 & 0x8000000;
  *(_DWORD *)&v45.op = v28 & 0x8000000;
  if ( (v28 & 0x8000000) != 0 )
    ++v27[1];
  if ( v28 == OT_NULL )
  {
    --v25->_vlocals._size;
    v30 = v25->_vlocals._vals;
    v3 = (v30[v25->_vlocals._size]._name._type & 0x8000000) == 0;
    v31 = &v30[v25->_vlocals._size];
    if ( !v3 )
    {
      v32.pTable = (SQTable *)v31->_name._unVal;
      if ( (int)--*(_DWORD *)(v32.nInteger + 4) <= 0 )
      {
        v31->_name._unVal.pTable->Release(this: (struct SQTable *)v31->_name._unVal.nInteger);
        v29 = *(_DWORD *)&v45.op;
      }
    }
  }
  --v25->_targetstack._size;
  if ( v29 != 0 && (int)--v27[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v27 + 8))(a1: v27);
  v33 = nargs->_fs;
  v34 = (SQFuncState *)v33->_vlocals._vals;
  v46 = v33->_targetstack._vals[v33->_targetstack._size - 1];
  v35 = (&v34->_vlocals._vals)[5 * v46];
  v36 = *(&v34->_returnexp + 5 * v46);
  v37 = v36 & 0x8000000;
  *(_DWORD *)&v45.op = v36 & 0x8000000;
  if ( (v36 & 0x8000000) != 0 )
    ++v35->_name._unVal.nInteger;
  if ( v36 == 16777217 )
  {
    --v33->_vlocals._size;
    v38 = v33->_vlocals._vals;
    v3 = (v38[v33->_vlocals._size]._name._type & 0x8000000) == 0;
    v34 = (SQFuncState *)&v38[v33->_vlocals._size];
    if ( !v3 )
    {
      v39 = v34->_vlocals._vals;
      if ( --v39->_name._unVal.nInteger <= 0 )
      {
        (*(void (__thiscall **)(SQLocalVarInfo *))(v34->_vlocals._vals->_name._type + 8))(a1: v34->_vlocals._vals);
        v37 = *(_DWORD *)&v45.op;
      }
    }
  }
  --v33->_targetstack._size;
  if ( v37 != 0 && --v35->_name._unVal.nInteger <= 0 )
    (*(void (__thiscall **)(SQLocalVarInfo *))(v35->_name._type + 8))(a1: v35);
  v45.op = 6;
  v40 = SQFuncState::PushTarget(this: v34, n: -1);
  v41 = nargs->_fs;
  v45._arg0 = v40;
  v45._arg1 = v46;
  v45._arg2 = i.op;
  v45._arg3 = nargsa;
  SQFuncState::AddInstruction(this: v41, i: &v45);
}

//------------------------------------------------------------------------------
// Address: 0x100419A0
// Name: public: void SQCompiler::ParseTableOrClass(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::ParseTableOrClass(SQCompiler *this, SQLexer *separator, SQFuncState *terminator)
{
  unsigned int size; // eax
  SQFuncState *v5; // ecx
  int v6; // eax
  unsigned __int8 v7; // al
  SQFuncState *fs; // esi
  SQLexer *v9; // ecx
  int token; // esi
  int *v11; // eax
  SQLexer *v12; // ecx
  int v13; // esi
  _DWORD *v14; // edi
  int v15; // eax
  bool v16; // zf
  int v17; // esi
  SQFuncState *v18; // ecx
  unsigned __int8 v19; // al
  SQFuncState *v20; // esi
  SQLexer *v21; // ecx
  int v22; // eax
  int *type; // eax
  SQLexer *v24; // ecx
  int v25; // esi
  _DWORD *v26; // edi
  int v27; // eax
  SQLexer *v28; // ecx
  tagSQObjectType *v29; // eax
  tagSQObjectType v30; // edx
  tagSQObjectValue v31; // eax
  int v32; // eax
  int Constant; // esi
  SQFuncState *v34; // ecx
  unsigned __int8 v35; // al
  SQFuncState *v36; // esi
  unsigned int v37; // esi
  SQFuncState *v38; // ecx
  unsigned __int8 v39; // al
  SQFuncState *v40; // esi
  SQLexer *v41; // ecx
  int v42; // eax
  SQLexer *v43; // ecx
  SQFuncState *v44; // edi
  int v45; // ecx
  SQLocalVarInfo *vals; // edx
  _DWORD *v47; // esi
  int v48; // eax
  int v49; // ecx
  SQLocalVarInfo *v50; // edx
  SQLocalVarInfo *v51; // edx
  tagSQObjectValue v52; // eax
  SQFuncState *v53; // edi
  SQLocalVarInfo *v54; // eax
  _DWORD *v55; // esi
  tagSQObjectType v56; // eax
  int v57; // edx
  SQLocalVarInfo *v58; // ecx
  tagSQObjectValue v59; // eax
  SQFuncState *v60; // edi
  SQLocalVarInfo *v61; // eax
  _DWORD *v62; // esi
  tagSQObjectType v63; // eax
  int v64; // edx
  SQLocalVarInfo *v65; // ecx
  tagSQObjectValue v66; // eax
  SQFuncState *v67; // esi
  unsigned int v68; // edx
  int v69; // ecx
  SQFuncState *v70; // [esp-8h] [ebp-98h]
  ExpState result; // [esp+10h] [ebp-80h] BYREF
  int len; // [esp+18h] [ebp-78h] BYREF
  int v73; // [esp+20h] [ebp-70h] BYREF
  int v74; // [esp+28h] [ebp-68h] BYREF
  ExpState v75; // [esp+30h] [ebp-60h] BYREF
  int v76; // [esp+38h] [ebp-58h]
  _DWORD *v77; // [esp+3Ch] [ebp-54h]
  _DWORD v78[2]; // [esp+40h] [ebp-50h] BYREF
  int v79; // [esp+48h] [ebp-48h]
  int tpos; // [esp+4Ch] [ebp-44h]
  int v81; // [esp+50h] [ebp-40h]
  tagSQObject id; // [esp+54h] [ebp-3Ch] BYREF
  SQInstruction v83; // [esp+5Ch] [ebp-34h] BYREF
  SQInstruction v84; // [esp+64h] [ebp-2Ch] BYREF
  SQInstruction v85; // [esp+6Ch] [ebp-24h] BYREF
  SQInstruction i; // [esp+74h] [ebp-1Ch] BYREF
  SQInstruction v87; // [esp+7Ch] [ebp-14h] BYREF
  int nkeys; // [esp+84h] [ebp-Ch]
  int v89; // [esp+88h] [ebp-8h]
  bool isstatic; // [esp+8Eh] [ebp-2h]
  bool hasattrs; // [esp+8Fh] [ebp-1h]

  size = this->_fs->_instructions._size;
  v5 = terminator;
  v6 = size - 1;
  tpos = v6;
  nkeys = 0;
  if ( (SQFuncState *)this->_token != terminator )
  {
    do
    {
      hasattrs = false;
      isstatic = false;
      if ( separator == (SQLexer *)59 )
      {
        if ( this->_token == 320 )
        {
          i.op = 30;
          v7 = SQFuncState::PushTarget(this: v5, n: -1);
          fs = this->_fs;
          i._arg0 = v7;
          i._arg1 = 0;
          *(_WORD *)&i._arg2 = 0;
          SQFuncState::AddInstruction(this: fs, &i);
          this->_token = SQLexer::Lex(this: v9);
          SQCompiler::ParseTableOrClass(this, separator: 44, terminator: 321);
          hasattrs = true;
        }
        if ( this->_token == 322 )
        {
          isstatic = true;
          this->_token = SQLexer::Lex(this: (SQLexer *)v5);
        }
      }
      token = this->_token;
      if ( this->_token == 91 )
      {
        this->_token = SQLexer::Lex(this: (SQLexer *)v5);
        SQCompiler::CommaExpr(this);
        if ( this->_token != 93 )
          SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x5D);
        v42 = SQLexer::Lex(this: v41);
        this->_token = v42;
        if ( v42 != 61 )
          goto $LN529;
        this->_token = SQLexer::Lex(this: v43);
        SQCompiler::Expression(this, &result, funcarg: false);
      }
      else if ( this->_token == 285 || this->_token == 310 )
      {
        v22 = SQLexer::Lex(this: (SQLexer *)v5);
        this->_token = v22;
        if ( token == 285 )
        {
          if ( v22 != 258 && v22 != 310 )
LABEL_69:
            SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C274, s: "IDENTIFIER");
          type = (int *)SQFuncState::CreateString(this: this->_fs, s: this->_lex._svalue, len: (int)&v74)._type;
          v25 = *type;
          v26 = (_DWORD *)type[1];
          v89 = *type & 0x8000000;
          if ( v89 != 0 )
            ++v26[1];
          v27 = SQLexer::Lex(this: v24);
          v16 = v89 == 0;
          this->_token = v27;
          v78[0] = v25;
          v78[1] = v26;
          if ( !v16 && (int)--v26[1] <= 0 )
            (*(void (__thiscall **)(_DWORD *))(*v26 + 8))(a1: v26);
          v29 = (tagSQObjectType *)v78;
        }
        else
        {
          v29 = (tagSQObjectType *)SQFuncState::CreateString(this: this->_fs, s: "constructor", len: (int)&v73)._type;
        }
        v16 = this->_token == 40;
        v30 = *v29;
        v31.pTable = (SQTable *)v29[1];
        id._type = v30;
        id._unVal = v31;
        if ( !v16 )
          SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x28);
        v32 = SQLexer::Lex(this: v28);
        v70 = this->_fs;
        this->_token = v32;
        Constant = SQFuncState::GetConstant(this: (SQFuncState *)&id, cons: (const tagSQObject *)v70);
        v87.op = 1;
        v35 = SQFuncState::PushTarget(this: v34, n: -1);
        v87._arg1 = Constant;
        v36 = this->_fs;
        v87._arg0 = v35;
        *(_WORD *)&v87._arg2 = 0;
        SQFuncState::AddInstruction(this: v36, i: &v87);
        SQCompiler::CreateFunction(this, name: &id);
        v37 = this->_fs->_functions._size;
        v83.op = 48;
        v39 = SQFuncState::PushTarget(this: v38, n: -1);
        v83._arg1 = v37 - 1;
        v40 = this->_fs;
        v83._arg0 = v39;
        *(_WORD *)&v83._arg2 = 0;
        SQFuncState::AddInstruction(this: v40, i: &v83);
      }
      else
      {
        if ( token != 258 && token != 310 )
          goto LABEL_69;
        v11 = (int *)SQFuncState::CreateString(this: this->_fs, s: this->_lex._svalue, (int)&len)._type;
        v13 = *v11;
        v14 = (_DWORD *)v11[1];
        v89 = *v11 & 0x8000000;
        if ( v89 != 0 )
          ++v14[1];
        v15 = SQLexer::Lex(this: v12);
        v16 = v89 == 0;
        this->_token = v15;
        v76 = v13;
        v77 = v14;
        if ( !v16 && (int)--v14[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
        v17 = SQFuncState::GetConstant(this: this->_fs, cons: (const tagSQObject *)this->_fs);
        v85.op = 1;
        v19 = SQFuncState::PushTarget(this: v18, n: -1);
        v85._arg1 = v17;
        v20 = this->_fs;
        v85._arg0 = v19;
        *(_WORD *)&v85._arg2 = 0;
        SQFuncState::AddInstruction(this: v20, i: &v85);
        if ( this->_token != 61 )
$LN529:
          SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x3D);
        this->_token = SQLexer::Lex(this: v21);
        SQCompiler::Expression(this, result: &v75, funcarg: false);
      }
      if ( (SQLexer *)this->_token == separator )
        this->_token = SQLexer::Lex(this: separator);
      v44 = this->_fs;
      v45 = v44->_targetstack._vals[v44->_targetstack._size - 1];
      vals = v44->_vlocals._vals;
      ++nkeys;
      v79 = v45;
      v45 *= 5;
      v47 = *((_DWORD **)&vals->_name._unVal.pTable + v45);
      v48 = *((_DWORD *)&vals->_name._type + v45);
      v49 = v48 & 0x8000000;
      v89 = v48 & 0x8000000;
      if ( (v48 & 0x8000000) != 0 )
        ++v47[1];
      if ( v48 == 16777217 )
      {
        --v44->_vlocals._size;
        v50 = v44->_vlocals._vals;
        v16 = (v50[v44->_vlocals._size]._name._type & 0x8000000) == 0;
        v51 = &v50[v44->_vlocals._size];
        if ( !v16 )
        {
          v52.pTable = (SQTable *)v51->_name._unVal;
          if ( (int)--*(_DWORD *)(v52.nInteger + 4) <= 0 )
          {
            v51->_name._unVal.pTable->Release(this: (struct SQTable *)v51->_name._unVal.nInteger);
            v49 = v89;
          }
        }
      }
      --v44->_targetstack._size;
      if ( v49 != 0 && (int)--v47[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v47 + 8))(a1: v47);
      v53 = this->_fs;
      v81 = v53->_targetstack._vals[v53->_targetstack._size - 1];
      v54 = v53->_vlocals._vals;
      v55 = &v54[v81]._name._unVal.pTable->__vftable;
      v56 = v54[v81]._name._type;
      v57 = v56 & 0x8000000;
      v89 = v56 & 0x8000000;
      if ( (v56 & 0x8000000) != 0 )
        ++v55[1];
      if ( v56 == OT_NULL )
      {
        v58 = &v53->_vlocals._vals[--v53->_vlocals._size];
        if ( (v58->_name._type & 0x8000000) != 0 )
        {
          v59.pTable = (SQTable *)v58->_name._unVal;
          if ( (int)--*(_DWORD *)(v59.nInteger + 4) <= 0 )
          {
            v58->_name._unVal.pTable->Release(this: (struct SQTable *)v58->_name._unVal.nInteger);
            v57 = v89;
          }
        }
      }
      --v53->_targetstack._size;
      if ( v57 != 0 && (int)--v55[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v55 + 8))(a1: v55);
      if ( hasattrs )
      {
        v60 = this->_fs;
        v61 = v60->_vlocals._vals;
        v62 = &v61[v60->_targetstack._vals[v60->_targetstack._size - 1]]._name._unVal.pTable->__vftable;
        v63 = v61[v60->_targetstack._vals[v60->_targetstack._size - 1]]._name._type;
        v64 = v63 & 0x8000000;
        v89 = v63 & 0x8000000;
        if ( (v63 & 0x8000000) != 0 )
          ++v62[1];
        if ( v63 == OT_NULL )
        {
          v65 = &v60->_vlocals._vals[--v60->_vlocals._size];
          if ( (v65->_name._type & 0x8000000) != 0 )
          {
            v66.pTable = (SQTable *)v65->_name._unVal;
            if ( (int)--*(_DWORD *)(v66.nInteger + 4) <= 0 )
            {
              v65->_name._unVal.pTable->Release(this: (struct SQTable *)v65->_name._unVal.nInteger);
              v64 = v89;
            }
          }
        }
        --v60->_targetstack._size;
        if ( v64 != 0 && (int)--v62[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v62 + 8))(a1: v62);
      }
      v67 = this->_fs;
      v68 = v67->_targetstack._size;
      v84._arg0 = hasattrs | (isstatic ? 2 : 0);
      v69 = v67->_targetstack._vals[v68 - 1];
      v84.op = 60;
      v84._arg1 = v69;
      v84._arg2 = v81;
      v84._arg3 = v79;
      SQFuncState::AddInstruction(this: v67, i: &v84);
      v5 = terminator;
    }
    while ( (SQFuncState *)this->_token != terminator );
    v6 = tpos;
  }
  if ( separator == (SQLexer *)44 )
  {
    v5 = (SQFuncState *)nkeys;
    this->_fs->_instructions._vals[v6]._arg1 = nkeys;
  }
  this->_token = SQLexer::Lex(this: (SQLexer *)v5);
}

//------------------------------------------------------------------------------
// Address: 0x10041EC0
// Name: public: void SQCompiler::LocalDeclStatement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::LocalDeclStatement(SQCompiler *this, SQCompiler *thisa)
{
  int v3; // eax
  tagSQObjectType type; // eax
  SQLexer *v5; // ecx
  _DWORD *v6; // edi
  tagSQObjectType v7; // eax
  int v8; // esi
  SQFuncState *v9; // ecx
  SQFuncState *fs; // esi
  int v11; // eax
  SQLocalVarInfo *vals; // edx
  SQFuncState *v13; // ecx
  _DWORD *v14; // edi
  tagSQObjectType v15; // eax
  int v16; // edx
  SQLocalVarInfo *v17; // ecx
  bool v18; // zf
  SQLocalVarInfo *v19; // eax
  int v20; // eax
  SQInstruction *p_i; // edi
  SQFuncState *v22; // esi
  SQLocalVarInfo *v23; // ecx
  _DWORD *v24; // edi
  tagSQObjectType v25; // eax
  int v26; // edx
  SQLocalVarInfo *v27; // ecx
  SQLocalVarInfo *v28; // ecx
  tagSQObjectValue v29; // eax
  SQFuncState *v30; // edi
  unsigned int size; // eax
  unsigned int v32; // eax
  SQLocalVarInfo val; // [esp+Ch] [ebp-48h] BYREF
  ExpState result; // [esp+20h] [ebp-34h] BYREF
  int len; // [esp+28h] [ebp-2Ch] BYREF
  SQObjectPtr v36; // [esp+30h] [ebp-24h]
  SQInstruction i; // [esp+38h] [ebp-1Ch] BYREF
  int v38; // [esp+40h] [ebp-14h] BYREF
  char v39; // [esp+44h] [ebp-10h]
  char v40; // [esp+45h] [ebp-Fh]
  __int16 v41; // [esp+46h] [ebp-Eh]
  int v42; // [esp+48h] [ebp-Ch]
  int v43; // [esp+4Ch] [ebp-8h]
  SQCompiler *thisb; // [esp+5Ch] [ebp+8h]

  do
  {
    v3 = SQLexer::Lex((SQLexer *)this);
    thisa->_token = v3;
    if ( v3 != 258 && v3 != 310 )
      SQCompiler::Error(a1: (int)thisa, this: (SQCompiler *)&stru_1009C274, s: "IDENTIFIER");
    type = SQFuncState::CreateString(this: thisa->_fs, s: thisa->_lex._svalue, (int)&len)._type;
    v6 = *(_DWORD **)(type + 4);
    v7 = *(_DWORD *)type;
    v8 = v7 & 0x8000000;
    v36._unVal.nInteger = (int)v6;
    v36._type = v7;
    thisb = (SQCompiler *)(v7 & 0x8000000);
    if ( (v7 & 0x8000000) != 0 )
      ++v6[1];
    thisa->_token = SQLexer::Lex(this: v5);
    if ( v8 != 0 && (int)--v6[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v6 + 8))(a1: v6);
    if ( thisa->_token != 61 )
    {
      i.op = 20;
      i._arg0 = SQFuncState::PushTarget(this: v9, n: -1);
      i._arg1 = 1;
      *(_WORD *)&i._arg2 = 0;
      p_i = &i;
      goto LABEL_21;
    }
    thisa->_token = SQLexer::Lex(this: (SQLexer *)v9);
    SQCompiler::Expression(this: thisa, &result, funcarg: false);
    fs = thisa->_fs;
    v11 = fs->_targetstack._vals[fs->_targetstack._size - 1];
    vals = fs->_vlocals._vals;
    v13 = (SQFuncState *)(5 * v11);
    v14 = &vals[v11]._name._unVal.pTable->__vftable;
    v42 = v11;
    v15 = vals[v11]._name._type;
    v16 = v15 & 0x8000000;
    v43 = v15 & 0x8000000;
    if ( (v15 & 0x8000000) != 0 )
      ++v14[1];
    if ( v15 == OT_NULL )
    {
      --fs->_vlocals._size;
      v17 = fs->_vlocals._vals;
      v18 = (v17[fs->_vlocals._size]._name._type & 0x8000000) == 0;
      v13 = (SQFuncState *)&v17[fs->_vlocals._size];
      if ( !v18 )
      {
        v19 = v13->_vlocals._vals;
        if ( --v19->_name._unVal.nInteger <= 0 )
        {
          (*(void (__thiscall **)(SQLocalVarInfo *))(v13->_vlocals._vals->_name._type + 8))(a1: v13->_vlocals._vals);
          v16 = v43;
        }
      }
    }
    --fs->_targetstack._size;
    if ( v16 != 0 && (int)--v14[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
    v20 = SQFuncState::PushTarget(this: v13, n: -1);
    if ( v20 != v42 )
    {
      v39 = 10;
      v40 = v20;
      v38 = v42;
      v41 = 0;
      p_i = (SQInstruction *)&v38;
LABEL_21:
      SQFuncState::AddInstruction(this: thisa->_fs, i: p_i);
    }
    v22 = thisa->_fs;
    v23 = v22->_vlocals._vals;
    v24 = &v23[v22->_targetstack._vals[v22->_targetstack._size - 1]]._name._unVal.pTable->__vftable;
    v25 = v23[v22->_targetstack._vals[v22->_targetstack._size - 1]]._name._type;
    v26 = v25 & 0x8000000;
    v42 = v25 & 0x8000000;
    if ( (v25 & 0x8000000) != 0 )
      ++v24[1];
    if ( v25 == OT_NULL )
    {
      --v22->_vlocals._size;
      v27 = v22->_vlocals._vals;
      v18 = (v27[v22->_vlocals._size]._name._type & 0x8000000) == 0;
      v28 = &v27[v22->_vlocals._size];
      if ( !v18 )
      {
        v29.pTable = (SQTable *)v28->_name._unVal;
        if ( (int)--*(_DWORD *)(v29.nInteger + 4) <= 0 )
        {
          v28->_name._unVal.pTable->Release(this: (struct SQTable *)v28->_name._unVal.nInteger);
          v26 = v42;
        }
      }
    }
    --v22->_targetstack._size;
    if ( v26 != 0 && (int)--v24[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v24 + 8))(a1: v24);
    v30 = thisa->_fs;
    val._end_op = 0;
    val._name = v36;
    if ( thisb != nullptr )
      ++*(_DWORD *)(v36._unVal.nInteger + 4);
    size = v30->_vlocals._size;
    val._start_op = v30->_instructions._size;
    val._pos = size;
    sqvector<SQLocalVarInfo>::push_back(this: (sqvector<SQLocalVarInfo> *)&val, a2: (int)&v30->_vlocals, &val);
    v32 = v30->_vlocals._size;
    if ( v32 > v30->_stacksize )
      v30->_stacksize = v32;
    if ( thisb != nullptr )
    {
      this = (SQCompiler *)v36._unVal.pTable;
      --*(_DWORD *)(v36._unVal.nInteger + 4);
      if ( (int)this->_fs <= 0 )
        (*(void (__thiscall **)(SQCompiler *))(this->_token + 8))(a1: this);
    }
  }
  while ( thisa->_token == 44 );
}

//------------------------------------------------------------------------------
// Address: 0x10042130
// Name: public: void SQCompiler::IfStatement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::IfStatement(SQCompiler *this, SQCompiler *haselse)
{
  int v3; // eax
  SQLexer *v4; // ecx
  SQLexer *v5; // ecx
  SQFuncState *v6; // ecx
  unsigned __int8 v7; // al
  SQFuncState *fs; // esi
  SQFuncState *v9; // eax
  SQFuncState *size; // edi
  int v11; // esi
  SQLexer *v12; // ecx
  int token; // eax
  SQFuncState *v14; // eax
  int v15; // ecx
  bool v16; // zf
  SQLexer *v17; // ecx
  int v18; // esi
  SQLexer *v19; // ecx
  int v20; // eax
  const char *v21; // [esp+0h] [ebp-2Ch]
  SQInstruction v22; // [esp+10h] [ebp-1Ch] BYREF
  SQInstruction i; // [esp+18h] [ebp-14h] BYREF
  int jnepos; // [esp+20h] [ebp-Ch]
  int stacksize; // [esp+24h] [ebp-8h]
  char haselse_3; // [esp+37h] [ebp+Bh]

  haselse_3 = 0;
  v3 = SQLexer::Lex((SQLexer *)this);
  haselse->_token = v3;
  if ( v3 != 40 )
    SQCompiler::Error(a1: (int)haselse, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x28);
  haselse->_token = SQLexer::Lex(this: v4);
  SQCompiler::CommaExpr(this: haselse);
  if ( haselse->_token != 41 )
    SQCompiler::Error(a1: (int)haselse, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x29);
  haselse->_token = SQLexer::Lex(this: v5);
  i.op = 26;
  v7 = SQFuncState::PopTarget(this: v6);
  fs = haselse->_fs;
  i._arg0 = v7;
  i._arg1 = 0;
  *(_WORD *)&i._arg2 = 0;
  SQFuncState::AddInstruction(this: fs, &i);
  v9 = haselse->_fs;
  size = (SQFuncState *)v9->_vlocals._size;
  v11 = v9->_instructions._size - 1;
  jnepos = v11;
  SQCompiler::Statement(this: haselse);
  token = haselse->_token;
  if ( haselse->_token != 125 && token != 273 )
  {
    if ( token == 59 )
    {
      haselse->_token = SQLexer::Lex(this: v12);
    }
    else if ( haselse->_lex._prevtoken != 10 && token != 0 )
    {
      SQCompiler::Error(a1: (int)haselse, this: (SQCompiler *)&stru_1009C274._lex._lasttokenline, s: v21);
    }
  }
  if ( (SQFuncState *)haselse->_fs->_vlocals._size != size )
    SQFuncState::SetStackSize(this: size, n: (int)v21);
  v14 = haselse->_fs;
  v15 = v14->_instructions._size - 1;
  v16 = haselse->_token == 273;
  *(_DWORD *)&i.op = v15;
  if ( v16 )
  {
    haselse_3 = 1;
    stacksize = v14->_vlocals._size;
    v22._arg1 = 0;
    *(_DWORD *)&v22.op = 24;
    SQFuncState::AddInstruction(this: v14, i: &v22);
    v18 = haselse->_fs->_instructions._size - 1;
    haselse->_token = SQLexer::Lex(this: v17);
    SQCompiler::Statement(this: haselse);
    v20 = haselse->_token;
    if ( haselse->_token == 59 )
    {
      haselse->_token = SQLexer::Lex(this: v19);
    }
    else if ( haselse->_lex._prevtoken != 10 && v20 != 0 && v20 != 125 )
    {
      SQCompiler::Error(a1: (int)haselse, this: (SQCompiler *)&stru_1009C274._lex._lasttokenline, s: v21);
    }
    if ( haselse->_fs->_vlocals._size != stacksize )
      SQFuncState::SetStackSize(this: (SQFuncState *)stacksize, n: (int)v21);
    haselse->_fs->_instructions._vals[v18]._arg1 = haselse->_fs->_instructions._size - v18 - 1;
    v11 = jnepos;
    v15 = *(_DWORD *)&i.op;
  }
  haselse->_fs->_instructions._vals[v11]._arg1 = v15 + (haselse_3 != 0) - v11;
}

//------------------------------------------------------------------------------
// Address: 0x100422E0
// Name: public: void SQCompiler::WhileStatement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::WhileStatement(SQCompiler *this, SQCompiler *jmppos)
{
  int v3; // eax
  SQLexer *v4; // ecx
  SQLexer *v5; // ecx
  int v6; // eax
  SQFuncState *fs; // esi
  unsigned int size; // eax
  int v9; // edx
  int v10; // edi
  unsigned int v11; // eax
  int *v12; // ecx
  SQFuncState *v13; // esi
  unsigned int v14; // eax
  int v15; // edi
  unsigned int v16; // eax
  SQFuncState *v17; // ecx
  unsigned __int8 v18; // al
  SQFuncState *v19; // esi
  SQFuncState *v20; // eax
  SQFuncState *v21; // esi
  SQFuncState *v22; // esi
  SQFuncState *v23; // eax
  int v24; // esi
  SQCompiler *v25; // [esp+0h] [ebp-2Ch]
  SQInstruction v26; // [esp+10h] [ebp-1Ch] BYREF
  int __ncontinues__; // [esp+18h] [ebp-14h]
  int __nbreaks__; // [esp+1Ch] [ebp-10h]
  SQInstruction i; // [esp+20h] [ebp-Ch] BYREF
  SQCompiler *jmpposa; // [esp+34h] [ebp+8h]

  jmpposa = (SQCompiler *)(jmppos->_fs->_instructions._size - 1);
  v3 = SQLexer::Lex((SQLexer *)this);
  jmppos->_token = v3;
  if ( v3 != 40 )
    SQCompiler::Error(a1: (int)jmppos, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x28);
  jmppos->_token = SQLexer::Lex(this: v4);
  SQCompiler::CommaExpr(this: jmppos);
  if ( jmppos->_token != 41 )
    SQCompiler::Error(a1: (int)jmppos, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x29);
  v6 = SQLexer::Lex(this: v5);
  fs = jmppos->_fs;
  jmppos->_token = v6;
  size = fs->_breaktargets._size;
  v9 = fs->_unresolvedcontinues._size;
  __nbreaks__ = fs->_unresolvedbreaks._size;
  __ncontinues__ = v9;
  if ( fs->_breaktargets._allocated <= size )
  {
    v10 = 2 * size;
    if ( 2 * size == 0 )
      v10 = 4;
    fs->_breaktargets._vals = (int *)_g_pMemAlloc->Realloc_2(
                                       this: _g_pMemAlloc,
                                       a2: fs->_breaktargets._vals,
                                       a3: 4 * v10);
    fs->_breaktargets._allocated = v10;
  }
  v11 = fs->_breaktargets._size;
  v12 = &fs->_breaktargets._vals[v11];
  fs->_breaktargets._size = v11 + 1;
  if ( v12 != nullptr )
    *v12 = 0;
  v13 = jmppos->_fs;
  v14 = v13->_continuetargets._size;
  if ( v13->_continuetargets._allocated <= v14 )
  {
    v15 = 2 * v14;
    if ( 2 * v14 == 0 )
      v15 = 4;
    v13->_continuetargets._vals = (int *)_g_pMemAlloc->Realloc_2(
                                           this: _g_pMemAlloc,
                                           a2: v13->_continuetargets._vals,
                                           a3: 4 * v15);
    v13->_continuetargets._allocated = v15;
  }
  v16 = v13->_continuetargets._size;
  v17 = (SQFuncState *)&v13->_continuetargets._vals[v16];
  v13->_continuetargets._size = v16 + 1;
  if ( v17 != nullptr )
    v17->_returnexp = 0;
  i.op = 26;
  v18 = SQFuncState::PopTarget(this: v17);
  v19 = jmppos->_fs;
  i._arg0 = v18;
  i._arg1 = 0;
  *(_WORD *)&i._arg2 = 0;
  SQFuncState::AddInstruction(this: v19, &i);
  v20 = jmppos->_fs;
  v21 = (SQFuncState *)v20->_vlocals._size;
  *(_DWORD *)&i.op = v20->_instructions._size - 1;
  SQCompiler::Statement(this: jmppos);
  if ( (SQFuncState *)jmppos->_fs->_vlocals._size != v21 )
    SQFuncState::SetStackSize(this: v21, n: (int)v25);
  v22 = jmppos->_fs;
  v26._arg1 = (int)jmpposa - v22->_instructions._size;
  *(_DWORD *)&v26.op = 24;
  SQFuncState::AddInstruction(this: v22, i: &v26);
  jmppos->_fs->_instructions._vals[*(_DWORD *)&i.op]._arg1 = jmppos->_fs->_instructions._size - *(_DWORD *)&i.op - 1;
  v23 = jmppos->_fs;
  v24 = v23->_unresolvedbreaks._size - __nbreaks__;
  if ( (signed int)(v23->_unresolvedcontinues._size - __ncontinues__) > 0 )
    SQCompiler::ResolveContinues(
      this: jmpposa,
      funcstate: v23,
      ntoresolve: v23->_unresolvedcontinues._size - __ncontinues__,
      targetpos: (int)v25);
  if ( v24 > 0 )
    SQCompiler::ResolveBreaks(this: v25, funcstate: jmppos->_fs, ntoresolve: v24);
  --jmppos->_fs->_breaktargets._size;
  --jmppos->_fs->_continuetargets._size;
}

//------------------------------------------------------------------------------
// Address: 0x100424E0
// Name: public: void SQCompiler::DoWhileStatement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::DoWhileStatement(SQCompiler *this, SQCompiler *continuetrg)
{
  int p_lex; // esi
  int v4; // eax
  SQFuncState *fs; // edi
  int size; // ecx
  int v7; // edx
  unsigned int v8; // eax
  bool v9; // zf
  int v10; // eax
  unsigned int v11; // eax
  int *v12; // ecx
  SQFuncState *v13; // edi
  unsigned int v14; // eax
  int v15; // eax
  unsigned int v16; // eax
  int *v17; // ecx
  SQLexer *v18; // ecx
  const char *v19; // eax
  int v20; // eax
  SQFuncState *v21; // edx
  SQLexer *v22; // ecx
  int v23; // eax
  SQFuncState *v24; // esi
  unsigned int v25; // edi
  SQFuncState *v26; // ecx
  unsigned __int8 v27; // al
  SQFuncState *v28; // esi
  SQFuncState *v29; // eax
  int v30; // esi
  SQCompiler *v31; // [esp+0h] [ebp-24h]
  int __ncontinues__; // [esp+Ch] [ebp-18h]
  int __nbreaks__; // [esp+10h] [ebp-14h]
  int jzpos; // [esp+14h] [ebp-10h]
  SQInstruction i; // [esp+18h] [ebp-Ch] BYREF
  int continuetrga; // [esp+2Ch] [ebp+8h]
  int continuetrgb; // [esp+2Ch] [ebp+8h]
  SQCompiler *continuetrgc; // [esp+2Ch] [ebp+8h]

  p_lex = (int)&continuetrg->_lex;
  v4 = SQLexer::Lex((SQLexer *)this);
  fs = continuetrg->_fs;
  continuetrg->_token = v4;
  size = fs->_unresolvedbreaks._size;
  v7 = fs->_unresolvedcontinues._size;
  jzpos = fs->_instructions._size - 1;
  *(_DWORD *)&i.op = fs->_vlocals._size;
  v8 = fs->_breaktargets._size;
  __nbreaks__ = size;
  __ncontinues__ = v7;
  if ( fs->_breaktargets._allocated <= v8 )
  {
    v9 = 2 * v8 == 0;
    v10 = 2 * v8;
    continuetrga = v10;
    if ( v9 )
    {
      continuetrga = 4;
      v10 = 4;
    }
    fs->_breaktargets._vals = (int *)_g_pMemAlloc->Realloc_2(
                                       this: _g_pMemAlloc,
                                       a2: fs->_breaktargets._vals,
                                       a3: 4 * v10);
    fs->_breaktargets._allocated = continuetrga;
  }
  v11 = fs->_breaktargets._size;
  v12 = &fs->_breaktargets._vals[v11];
  fs->_breaktargets._size = v11 + 1;
  if ( v12 != nullptr )
    *v12 = 0;
  v13 = continuetrg->_fs;
  v14 = v13->_continuetargets._size;
  if ( v13->_continuetargets._allocated <= v14 )
  {
    v9 = 2 * v14 == 0;
    v15 = 2 * v14;
    continuetrgb = v15;
    if ( v9 )
    {
      continuetrgb = 4;
      v15 = 4;
    }
    v13->_continuetargets._vals = (int *)_g_pMemAlloc->Realloc_2(
                                           this: _g_pMemAlloc,
                                           a2: v13->_continuetargets._vals,
                                           a3: 4 * v15);
    v13->_continuetargets._allocated = continuetrgb;
  }
  v16 = v13->_continuetargets._size;
  v17 = &v13->_continuetargets._vals[v16];
  v13->_continuetargets._size = v16 + 1;
  if ( v17 != nullptr )
    *v17 = 0;
  SQCompiler::Statement(this: continuetrg);
  v18 = *(SQLexer **)&i.op;
  if ( continuetrg->_fs->_vlocals._size != *(_DWORD *)&i.op )
    SQFuncState::SetStackSize(this: *(SQFuncState **)&i.op, n: (int)v31);
  if ( continuetrg->_token != 274 )
  {
    v19 = SQLexer::Tok2Str(this: v18, tok: p_lex);
    SQCompiler::Error(a1: (int)continuetrg, this: (SQCompiler *)&stru_1009C274, s: v19);
  }
  v20 = SQLexer::Lex(this: v18);
  v21 = continuetrg->_fs;
  continuetrg->_token = v20;
  continuetrgc = (SQCompiler *)(v21->_instructions._size - 1);
  if ( v20 != 40 )
    SQCompiler::Error(a1: (int)continuetrg, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x28);
  continuetrg->_token = SQLexer::Lex(this: (SQLexer *)(v21->_instructions._size - 1));
  SQCompiler::CommaExpr(this: continuetrg);
  if ( continuetrg->_token != 41 )
    SQCompiler::Error(a1: (int)continuetrg, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x29);
  v23 = SQLexer::Lex(this: v22);
  v24 = continuetrg->_fs;
  continuetrg->_token = v23;
  v25 = v24->_instructions._size;
  i.op = 25;
  v27 = SQFuncState::PopTarget(this: v26);
  v28 = continuetrg->_fs;
  i._arg0 = v27;
  i._arg1 = jzpos - v25;
  *(_WORD *)&i._arg2 = 0;
  SQFuncState::AddInstruction(this: v28, &i);
  v29 = continuetrg->_fs;
  v30 = v29->_unresolvedbreaks._size - __nbreaks__;
  if ( (signed int)(v29->_unresolvedcontinues._size - __ncontinues__) > 0 )
    SQCompiler::ResolveContinues(
      this: continuetrgc,
      funcstate: v29,
      ntoresolve: v29->_unresolvedcontinues._size - __ncontinues__,
      targetpos: (int)v31);
  if ( v30 > 0 )
    SQCompiler::ResolveBreaks(this: v31, funcstate: continuetrg->_fs, ntoresolve: v30);
  --continuetrg->_fs->_breaktargets._size;
  --continuetrg->_fs->_continuetargets._size;
}

//------------------------------------------------------------------------------
// Address: 0x100426F0
// Name: public: void SQCompiler::ForStatement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::ForStatement(SQCompiler *this, SQCompiler *__nbreaks__)
{
  int v3; // eax
  SQLexer *fs; // ecx
  int v5; // eax
  SQCompiler *v6; // ecx
  SQFuncState *v7; // ecx
  SQLexer *v8; // ecx
  bool v9; // zf
  SQFuncState *v10; // ecx
  unsigned __int8 v11; // al
  SQFuncState *v12; // esi
  SQLexer *v13; // ecx
  SQFuncState *v14; // ecx
  int v15; // esi
  unsigned int v16; // edi
  SQInstruction *v17; // eax
  int v18; // esi
  SQInstruction *v19; // ecx
  SQFuncState *v20; // eax
  unsigned int size; // ecx
  SQFuncState *v22; // esi
  unsigned int v23; // eax
  int v24; // edi
  unsigned int v25; // eax
  int *v26; // ecx
  SQFuncState *v27; // esi
  unsigned int v28; // eax
  int v29; // edi
  unsigned int v30; // eax
  int *v31; // ecx
  SQInstruction *v32; // edi
  SQFuncState *v33; // esi
  SQFuncState *v34; // eax
  int v35; // esi
  int j; // edx
  int v37; // ecx
  SQFuncState *v38; // eax
  int v39; // ecx
  unsigned int v40; // edx
  int v41; // [esp+0h] [ebp-3Ch]
  SQInstruction *exp; // [esp+Ch] [ebp-30h]
  unsigned int exp_8; // [esp+14h] [ebp-28h]
  SQFuncState *stacksize; // [esp+18h] [ebp-24h]
  int jmppos; // [esp+1Ch] [ebp-20h]
  SQInstruction i; // [esp+20h] [ebp-1Ch] BYREF
  int jzpos; // [esp+28h] [ebp-14h]
  SQInstruction v48; // [esp+2Ch] [ebp-10h] BYREF
  int continuetrg; // [esp+34h] [ebp-8h]
  int __nbreaks__a; // [esp+44h] [ebp+8h]
  int __nbreaks__b; // [esp+44h] [ebp+8h]
  int __nbreaks__c; // [esp+44h] [ebp+8h]

  v3 = SQLexer::Lex((SQLexer *)this);
  fs = (SQLexer *)__nbreaks__->_fs;
  __nbreaks__->_token = v3;
  stacksize = (SQFuncState *)fs->_prevtoken;
  if ( v3 != 40 )
    SQCompiler::Error(a1: (int)__nbreaks__, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x28);
  v5 = SQLexer::Lex(this: fs);
  __nbreaks__->_token = v5;
  if ( v5 == 283 )
  {
    SQCompiler::LocalDeclStatement(this: v6, thisa: __nbreaks__);
  }
  else
  {
    if ( v5 == 59 )
      goto $LN372;
    SQCompiler::CommaExpr(this: __nbreaks__);
    SQFuncState::PopTarget(this: v7);
  }
  if ( __nbreaks__->_token != 59 )
    SQCompiler::Error(a1: (int)__nbreaks__, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x3B);
$LN372:
  __nbreaks__->_token = SQLexer::Lex(this: (SQLexer *)v6);
  __nbreaks__->_fs->_optimization = false;
  v8 = (SQLexer *)__nbreaks__->_fs;
  v9 = __nbreaks__->_token == 59;
  jmppos = v8[1]._nvalue - 1;
  jzpos = -1;
  if ( !v9 )
  {
    SQCompiler::CommaExpr(this: __nbreaks__);
    i.op = 26;
    v11 = SQFuncState::PopTarget(this: v10);
    v12 = __nbreaks__->_fs;
    i._arg0 = v11;
    i._arg1 = 0;
    *(_WORD *)&i._arg2 = 0;
    SQFuncState::AddInstruction(this: v12, &i);
    v9 = __nbreaks__->_token == 59;
    jzpos = __nbreaks__->_fs->_instructions._size - 1;
    if ( !v9 )
      SQCompiler::Error(a1: (int)__nbreaks__, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x3B);
  }
  __nbreaks__->_token = SQLexer::Lex(this: v8);
  __nbreaks__->_fs->_optimization = false;
  v13 = (SQLexer *)__nbreaks__->_fs;
  __nbreaks__a = v13[1]._nvalue;
  if ( __nbreaks__->_token != 41 )
  {
    SQCompiler::CommaExpr(this: __nbreaks__);
    SQFuncState::PopTarget(this: v14);
    if ( __nbreaks__->_token != 41 )
      SQCompiler::Error(a1: (int)__nbreaks__, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x29);
  }
  __nbreaks__->_token = SQLexer::Lex(this: v13);
  __nbreaks__->_fs->_optimization = false;
  v15 = __nbreaks__->_fs->_instructions._size - __nbreaks__a;
  v16 = 0;
  *(_DWORD *)&v48.op = v15;
  exp = nullptr;
  exp_8 = 0;
  if ( v15 > 0 )
  {
    __nbreaks__b = __nbreaks__a;
    for ( continuetrg = v15; continuetrg != 0; --continuetrg )
    {
      v17 = &__nbreaks__->_fs->_instructions._vals[__nbreaks__b];
      *(_DWORD *)&i.op = v17;
      if ( exp_8 <= v16 )
      {
        v18 = 2 * v16;
        if ( 2 * v16 == 0 )
          v18 = 4;
        exp = (SQInstruction *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: exp, a3: 8 * v18);
        v17 = *(SQInstruction **)&i.op;
        exp_8 = v18;
        v15 = *(_DWORD *)&v48.op;
      }
      v19 = &exp[v16++];
      if ( v19 != nullptr )
      {
        v19->_arg1 = v17->_arg1;
        *(_DWORD *)&v19->op = *(_DWORD *)&v17->op;
      }
      ++__nbreaks__b;
    }
    v20 = __nbreaks__->_fs;
    if ( v15 > 0 )
    {
      size = v20->_instructions._size;
      do
      {
        --size;
        --v15;
      }
      while ( v15 != 0 );
      v20->_instructions._size = size;
    }
  }
  v22 = __nbreaks__->_fs;
  v23 = v22->_breaktargets._size;
  __nbreaks__c = v22->_unresolvedbreaks._size;
  *(_DWORD *)&i.op = v22->_unresolvedcontinues._size;
  if ( v22->_breaktargets._allocated <= v23 )
  {
    v24 = 2 * v23;
    if ( 2 * v23 == 0 )
      v24 = 4;
    v22->_breaktargets._vals = (int *)_g_pMemAlloc->Realloc_2(
                                        this: _g_pMemAlloc,
                                        a2: v22->_breaktargets._vals,
                                        a3: 4 * v24);
    v22->_breaktargets._allocated = v24;
  }
  v25 = v22->_breaktargets._size;
  v26 = &v22->_breaktargets._vals[v25];
  v22->_breaktargets._size = v25 + 1;
  if ( v26 != nullptr )
    *v26 = 0;
  v27 = __nbreaks__->_fs;
  v28 = v27->_continuetargets._size;
  if ( v27->_continuetargets._allocated <= v28 )
  {
    v29 = 2 * v28;
    if ( 2 * v28 == 0 )
      v29 = 4;
    v27->_continuetargets._vals = (int *)_g_pMemAlloc->Realloc_2(
                                           this: _g_pMemAlloc,
                                           a2: v27->_continuetargets._vals,
                                           a3: 4 * v29);
    v27->_continuetargets._allocated = v29;
  }
  v30 = v27->_continuetargets._size;
  v31 = &v27->_continuetargets._vals[v30];
  v27->_continuetargets._size = v30 + 1;
  if ( v31 != nullptr )
    *v31 = 0;
  SQCompiler::Statement(this: __nbreaks__);
  continuetrg = __nbreaks__->_fs->_instructions._size - 1;
  if ( *(int *)&v48.op > 0 )
  {
    v32 = exp;
    do
    {
      SQFuncState::AddInstruction(this: __nbreaks__->_fs, i: v32++);
      --*(_DWORD *)&v48.op;
    }
    while ( *(_DWORD *)&v48.op != 0 );
  }
  v33 = __nbreaks__->_fs;
  v48._arg1 = jmppos - v33->_instructions._size;
  *(_DWORD *)&v48.op = 24;
  SQFuncState::AddInstruction(this: v33, i: &v48);
  if ( jzpos > 0 )
    __nbreaks__->_fs->_instructions._vals[jzpos]._arg1 = __nbreaks__->_fs->_instructions._size - jzpos - 1;
  if ( (SQFuncState *)__nbreaks__->_fs->_vlocals._size != stacksize )
    SQFuncState::SetStackSize(this: stacksize, n: v41);
  v34 = __nbreaks__->_fs;
  v35 = v34->_unresolvedbreaks._size - __nbreaks__c;
  for ( j = v34->_unresolvedcontinues._size - *(_DWORD *)&i.op; j > 0; v34->_instructions._vals[v37]._arg3 = 0 )
  {
    v37 = v34->_unresolvedcontinues._vals[--v34->_unresolvedcontinues._size];
    v34->_instructions._vals[v37]._arg0 = 0;
    v34->_instructions._vals[v37]._arg1 = continuetrg - v37;
    v34->_instructions._vals[v37]._arg2 = 0;
    --j;
  }
  if ( v35 > 0 )
  {
    v38 = __nbreaks__->_fs;
    do
    {
      v39 = v38->_unresolvedbreaks._vals[--v38->_unresolvedbreaks._size];
      v40 = v38->_instructions._size;
      v38->_instructions._vals[v39]._arg0 = 0;
      v38->_instructions._vals[v39]._arg1 = v40 - v39 - 1;
      v38->_instructions._vals[v39]._arg2 = 0;
      --v35;
      v38->_instructions._vals[v39]._arg3 = 0;
    }
    while ( v35 > 0 );
  }
  --__nbreaks__->_fs->_breaktargets._size;
  --__nbreaks__->_fs->_continuetargets._size;
  if ( exp_8 != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: exp);
}

//------------------------------------------------------------------------------
// Address: 0x10042AF0
// Name: public: void SQCompiler::ForEachStatement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::ForEachStatement(SQCompiler *this, SQCompiler *__nbreaks__)
{
  int v3; // eax
  SQLexer *v4; // ecx
  int v5; // eax
  SQFuncState *fs; // edi
  const char *svalue; // eax
  const SQObjectPtr *type; // eax
  SQLexer *v9; // ecx
  int v10; // eax
  SQLexer *v11; // ecx
  tagSQObjectType v12; // edi
  _DWORD *v13; // esi
  bool v14; // zf
  int v15; // eax
  const char *v16; // eax
  SQFuncState *v17; // edi
  const SQObjectPtr *v18; // eax
  SQLexer *v19; // ecx
  int v20; // eax
  SQLexer *v21; // ecx
  tagSQObjectType v22; // edi
  _DWORD *v23; // esi
  int *v24; // eax
  int v25; // edx
  int v26; // eax
  const char *v27; // eax
  int v28; // eax
  SQFuncState *v29; // ecx
  SQLexer *v30; // ecx
  int v31; // eax
  SQFuncState *v32; // esi
  char v33; // al
  SQFuncState *v34; // esi
  const tagSQObject *v35; // eax
  char v36; // al
  SQFuncState *v37; // esi
  SQFuncState *v38; // esi
  SQFuncState *v39; // esi
  SQFuncState *v40; // esi
  unsigned int size; // eax
  int v42; // edi
  unsigned int v43; // eax
  int *v44; // ecx
  SQFuncState *v45; // esi
  unsigned int v46; // eax
  int v47; // edi
  unsigned int v48; // eax
  int *v49; // ecx
  SQFuncState *v50; // esi
  int v51; // esi
  SQFuncState *v52; // eax
  int v53; // edi
  SQCompiler *v54; // [esp+0h] [ebp-34h]
  SQObjectPtr v55; // [esp+Ch] [ebp-28h] BYREF
  int len; // [esp+14h] [ebp-20h] BYREF
  int stacksize; // [esp+18h] [ebp-1Ch]
  int foreachpos; // [esp+1Ch] [ebp-18h] BYREF
  int v59; // [esp+20h] [ebp-14h]
  tagSQObject name; // [esp+24h] [ebp-10h] BYREF
  int __ncontinues__; // [esp+2Ch] [ebp-8h]
  int __nbreaks__b; // [esp+3Ch] [ebp+8h]
  int __nbreaks__a; // [esp+3Ch] [ebp+8h]

  v3 = SQLexer::Lex((SQLexer *)this);
  __nbreaks__->_token = v3;
  if ( v3 != 40 )
    SQCompiler::Error(a1: (int)__nbreaks__, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x28);
  v5 = SQLexer::Lex(this: v4);
  __nbreaks__->_token = v5;
  if ( v5 != 258 && v5 != 310 )
    SQCompiler::Error(a1: (int)__nbreaks__, this: (SQCompiler *)&stru_1009C274, s: "IDENTIFIER");
  fs = __nbreaks__->_fs;
  svalue = __nbreaks__->_lex._svalue;
  v55._type = OT_NULL;
  v55._unVal.nInteger = 0;
  type = (const SQObjectPtr *)SQFuncState::CreateString(this: fs, s: svalue, (int)&len)._type;
  SQObjectPtr::operator=(this: &v55, obj: type);
  v10 = SQLexer::Lex(this: v9);
  v12 = v55._type;
  v13 = &v55._unVal.pTable->__vftable;
  __nbreaks__->_token = v10;
  if ( (v12 & 0x8000000) != 0 && (int)--v13[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v13 + 8))(a1: v13);
  v14 = __nbreaks__->_token == 44;
  name._type = v12;
  name._unVal.nInteger = (int)v13;
  if ( v14 )
  {
    foreachpos = v12;
    v59 = (int)v13;
    v15 = SQLexer::Lex(this: v11);
    __nbreaks__->_token = v15;
    if ( v15 != 258 && v15 != 310 )
      SQCompiler::Error(a1: (int)__nbreaks__, this: (SQCompiler *)&stru_1009C274, s: "IDENTIFIER");
    v16 = __nbreaks__->_lex._svalue;
    v17 = __nbreaks__->_fs;
    v55._type = OT_NULL;
    v55._unVal.nInteger = 0;
    v18 = (const SQObjectPtr *)SQFuncState::CreateString(this: v17, s: v16, (int)&len)._type;
    SQObjectPtr::operator=(this: &v55, obj: v18);
    v20 = SQLexer::Lex(this: v19);
    v22 = v55._type;
    v23 = &v55._unVal.pTable->__vftable;
    __nbreaks__->_token = v20;
    if ( (v22 & 0x8000000) != 0 && (int)--v23[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v23 + 8))(a1: v23);
    name._type = v22;
    name._unVal.nInteger = (int)v23;
  }
  else
  {
    v24 = (int *)SQFuncState::CreateString(this: __nbreaks__->_fs, s: "@INDEX@", len: (int)&v55)._type;
    v25 = *v24;
    v26 = v24[1];
    foreachpos = v25;
    v59 = v26;
  }
  if ( __nbreaks__->_token != 280 )
  {
    v27 = SQLexer::Tok2Str(this: v21, tok: (int)&__nbreaks__->_lex);
    SQCompiler::Error(a1: (int)__nbreaks__, this: (SQCompiler *)&stru_1009C274, s: v27);
  }
  v28 = SQLexer::Lex(this: v21);
  v29 = __nbreaks__->_fs;
  __nbreaks__->_token = v28;
  stacksize = v29->_vlocals._size;
  SQCompiler::Expression(this: __nbreaks__, result: (ExpState *)&v55, funcarg: false);
  if ( __nbreaks__->_token != 41 )
    SQCompiler::Error(a1: (int)__nbreaks__, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x29);
  __nbreaks__->_token = SQLexer::Lex(this: v30);
  __nbreaks__b = __nbreaks__->_fs->_targetstack._vals[__nbreaks__->_fs->_targetstack._size - 1];
  v31 = SQFuncState::PushLocalVariable(this: __nbreaks__->_fs, name: (const tagSQObject *)&foreachpos);
  v32 = __nbreaks__->_fs;
  __ncontinues__ = v31;
  LOBYTE(v59) = 20;
  BYTE1(v59) = v31;
  foreachpos = 1;
  HIWORD(v59) = 0;
  SQFuncState::AddInstruction(this: v32, i: (SQInstruction *)&foreachpos);
  v33 = SQFuncState::PushLocalVariable(this: __nbreaks__->_fs, &name);
  v34 = __nbreaks__->_fs;
  LOBYTE(v59) = 20;
  BYTE1(v59) = v33;
  foreachpos = 1;
  HIWORD(v59) = 0;
  SQFuncState::AddInstruction(this: v34, i: (SQInstruction *)&foreachpos);
  v35 = (const tagSQObject *)SQFuncState::CreateString(this: __nbreaks__->_fs, s: "@ITERATOR@", len: (int)&v55)._type;
  v36 = SQFuncState::PushLocalVariable(this: __nbreaks__->_fs, name: v35);
  v37 = __nbreaks__->_fs;
  LOBYTE(v59) = 20;
  BYTE1(v59) = v36;
  foreachpos = 1;
  HIWORD(v59) = 0;
  SQFuncState::AddInstruction(this: v37, i: (SQInstruction *)&foreachpos);
  v38 = __nbreaks__->_fs;
  name._unVal.nInteger = v38->_instructions._size - 1;
  LOBYTE(v59) = 51;
  BYTE1(v59) = __nbreaks__b;
  foreachpos = 0;
  HIWORD(v59) = (unsigned __int8)__ncontinues__;
  SQFuncState::AddInstruction(this: v38, i: (SQInstruction *)&foreachpos);
  v39 = __nbreaks__->_fs;
  v59 = v39->_instructions._size - 1;
  LOBYTE(v55._unVal.fFloat) = 52;
  BYTE1(v55._unVal.pTable) = __nbreaks__b;
  v55._type = 0;
  HIWORD(v55._unVal.pArray) = (unsigned __int8)__ncontinues__;
  SQFuncState::AddInstruction(this: v39, i: (SQInstruction *)&v55);
  v40 = __nbreaks__->_fs;
  __nbreaks__a = v40->_unresolvedbreaks._size;
  size = v40->_breaktargets._size;
  __ncontinues__ = v40->_unresolvedcontinues._size;
  if ( v40->_breaktargets._allocated <= size )
  {
    v42 = 2 * size;
    if ( 2 * size == 0 )
      v42 = 4;
    v40->_breaktargets._vals = (int *)_g_pMemAlloc->Realloc_2(
                                        this: _g_pMemAlloc,
                                        a2: v40->_breaktargets._vals,
                                        a3: 4 * v42);
    v40->_breaktargets._allocated = v42;
  }
  v43 = v40->_breaktargets._size;
  v44 = &v40->_breaktargets._vals[v43];
  v40->_breaktargets._size = v43 + 1;
  if ( v44 != nullptr )
    *v44 = 0;
  v45 = __nbreaks__->_fs;
  v46 = v45->_continuetargets._size;
  if ( v45->_continuetargets._allocated <= v46 )
  {
    v47 = 2 * v46;
    if ( 2 * v46 == 0 )
      v47 = 4;
    v45->_continuetargets._vals = (int *)_g_pMemAlloc->Realloc_2(
                                           this: _g_pMemAlloc,
                                           a2: v45->_continuetargets._vals,
                                           a3: 4 * v47);
    v45->_continuetargets._allocated = v47;
  }
  v48 = v45->_continuetargets._size;
  v49 = &v45->_continuetargets._vals[v48];
  v45->_continuetargets._size = v48 + 1;
  if ( v49 != nullptr )
    *v49 = 0;
  SQCompiler::Statement(this: __nbreaks__);
  v50 = __nbreaks__->_fs;
  v55._type = name._unVal.nInteger - v50->_instructions._size;
  v55._unVal.nInteger = 24;
  SQFuncState::AddInstruction(this: v50, i: (SQInstruction *)&v55);
  v51 = v59;
  __nbreaks__->_fs->_instructions._vals[v59]._arg1 = __nbreaks__->_fs->_instructions._size - v59 - 1;
  __nbreaks__->_fs->_instructions._vals[v51 + 1]._arg1 = __nbreaks__->_fs->_instructions._size - v51 - 1;
  if ( __nbreaks__->_fs->_vlocals._size != stacksize )
    SQFuncState::SetStackSize(this: (SQFuncState *)stacksize, n: (int)v54);
  v52 = __nbreaks__->_fs;
  v53 = v52->_unresolvedbreaks._size - __nbreaks__a;
  if ( (signed int)(v52->_unresolvedcontinues._size - __ncontinues__) > 0 )
    SQCompiler::ResolveContinues(
      this: (SQCompiler *)(v51 - 1),
      funcstate: v52,
      ntoresolve: v52->_unresolvedcontinues._size - __ncontinues__,
      targetpos: (int)v54);
  if ( v53 > 0 )
    SQCompiler::ResolveBreaks(this: v54, funcstate: __nbreaks__->_fs, ntoresolve: v53);
  --__nbreaks__->_fs->_breaktargets._size;
  --__nbreaks__->_fs->_continuetargets._size;
}

//------------------------------------------------------------------------------
// Address: 0x10042F20
// Name: public: void SQCompiler::SwitchStatement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::SwitchStatement(SQCompiler *this, SQCompiler *bfirst)
{
  int v3; // eax
  SQLexer *v4; // ecx
  SQLexer *v5; // ecx
  int v6; // eax
  SQLexer *v7; // ecx
  int v8; // eax
  SQFuncState *fs; // esi
  int v10; // edx
  unsigned int size; // eax
  int v12; // edi
  unsigned int v13; // eax
  SQLexer *vals; // ecx
  SQFuncState *v15; // esi
  SQFuncState *v16; // ecx
  unsigned int v17; // eax
  SQLexer *v18; // ecx
  int v19; // eax
  SQFuncState *v20; // esi
  int v21; // ecx
  SQLocalVarInfo *v22; // eax
  _DWORD *v23; // edi
  tagSQObjectType type; // eax
  SQLocalVarInfo *v25; // edx
  tagSQObjectValue v26; // eax
  SQFuncState *v27; // esi
  SQFuncState *v28; // esi
  SQFuncState *v29; // eax
  SQFuncState *v30; // edi
  SQFuncState *v31; // ecx
  unsigned int v32; // eax
  int v33; // eax
  SQLexer *v34; // ecx
  int v35; // eax
  SQFuncState *v36; // edx
  SQFuncState *v37; // edi
  SQCompiler *v38; // ecx
  SQFuncState *v39; // ecx
  SQFuncState *v40; // eax
  SQCompiler *v41; // [esp+0h] [ebp-44h]
  ExpState result; // [esp+10h] [ebp-34h] BYREF
  SQInstruction v43; // [esp+18h] [ebp-2Ch] BYREF
  SQInstruction v44; // [esp+20h] [ebp-24h] BYREF
  SQInstruction i; // [esp+28h] [ebp-1Ch] BYREF
  int __nbreaks__; // [esp+30h] [ebp-14h]
  int expr; // [esp+34h] [ebp-10h]
  int skipcondjmp; // [esp+38h] [ebp-Ch]
  int tonextcondjmp; // [esp+3Ch] [ebp-8h]
  int bfirsta; // [esp+4Ch] [ebp+8h]
  char bfirst_3; // [esp+4Fh] [ebp+Bh]

  v3 = SQLexer::Lex((SQLexer *)this);
  bfirst->_token = v3;
  if ( v3 != 40 )
    SQCompiler::Error(a1: (int)bfirst, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x28);
  bfirst->_token = SQLexer::Lex(this: v4);
  SQCompiler::CommaExpr(this: bfirst);
  if ( bfirst->_token != 41 )
    SQCompiler::Error(a1: (int)bfirst, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x29);
  v6 = SQLexer::Lex(this: v5);
  bfirst->_token = v6;
  if ( v6 != 123 )
    SQCompiler::Error(a1: (int)bfirst, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x7B);
  v8 = SQLexer::Lex(this: v7);
  fs = bfirst->_fs;
  bfirst->_token = v8;
  v10 = fs->_targetstack._vals[fs->_targetstack._size - 1];
  tonextcondjmp = -1;
  skipcondjmp = -1;
  __nbreaks__ = fs->_unresolvedbreaks._size;
  size = fs->_breaktargets._size;
  expr = v10;
  bfirst_3 = 1;
  if ( fs->_breaktargets._allocated <= size )
  {
    v12 = 2 * size;
    if ( 2 * size == 0 )
      v12 = 4;
    fs->_breaktargets._vals = (int *)_g_pMemAlloc->Realloc_2(
                                       this: _g_pMemAlloc,
                                       a2: fs->_breaktargets._vals,
                                       a3: 4 * v12);
    fs->_breaktargets._allocated = v12;
  }
  v13 = fs->_breaktargets._size;
  vals = (SQLexer *)&fs->_breaktargets._vals[v13];
  fs->_breaktargets._size = v13 + 1;
  if ( vals != nullptr )
    vals->_curtoken = 0;
  if ( bfirst->_token == 300 )
  {
    do
    {
      if ( bfirst_3 == 0 )
      {
        v15 = bfirst->_fs;
        i._arg1 = 0;
        *(_DWORD *)&i.op = 24;
        SQFuncState::AddInstruction(this: v15, &i);
        v16 = bfirst->_fs;
        v17 = v16->_instructions._size;
        vals = (SQLexer *)v16->_instructions._vals;
        skipcondjmp = v17 - 1;
        *(&vals->_curtoken + 2 * tonextcondjmp) = v17 - tonextcondjmp - 1;
      }
      bfirst->_token = SQLexer::Lex(this: vals);
      SQCompiler::Expression(this: bfirst, &result, funcarg: false);
      if ( bfirst->_token != 58 )
        goto LABEL_33;
      v19 = SQLexer::Lex(this: v18);
      v20 = bfirst->_fs;
      bfirst->_token = v19;
      v21 = v20->_targetstack._vals[v20->_targetstack._size - 1];
      v22 = v20->_vlocals._vals;
      v23 = &v22[v21]._name._unVal.pTable->__vftable;
      type = v22[v21]._name._type;
      bfirsta = v21;
      tonextcondjmp = type & 0x8000000;
      if ( (type & 0x8000000) != 0 )
        ++v23[1];
      if ( type == OT_NULL )
      {
        v25 = &v20->_vlocals._vals[--v20->_vlocals._size];
        if ( (v25->_name._type & 0x8000000) != 0 )
        {
          v26.pTable = (SQTable *)v25->_name._unVal;
          if ( (int)--*(_DWORD *)(v26.nInteger + 4) <= 0 )
          {
            v25->_name._unVal.pTable->Release(this: (struct SQTable *)v25->_name._unVal.nInteger);
            v21 = bfirsta;
          }
        }
      }
      --v20->_targetstack._size;
      if ( tonextcondjmp != 0 && (int)--v23[1] <= 0 )
      {
        (*(void (__thiscall **)(_DWORD *))(*v23 + 8))(a1: v23);
        v21 = bfirsta;
      }
      v27 = bfirst->_fs;
      v44._arg0 = v21;
      v44._arg1 = v21;
      v44.op = 15;
      v44._arg2 = expr;
      v44._arg3 = 0;
      SQFuncState::AddInstruction(this: v27, i: &v44);
      v28 = bfirst->_fs;
      v43.op = 26;
      v43._arg0 = bfirsta;
      v43._arg1 = 0;
      *(_WORD *)&v43._arg2 = 0;
      SQFuncState::AddInstruction(this: v28, i: &v43);
      if ( skipcondjmp != -1 )
        bfirst->_fs->_instructions._vals[skipcondjmp]._arg1 = bfirst->_fs->_instructions._size - skipcondjmp - 1;
      v29 = bfirst->_fs;
      v30 = (SQFuncState *)v29->_vlocals._size;
      tonextcondjmp = v29->_instructions._size - 1;
      SQCompiler::Statements(this: (SQCompiler *)tonextcondjmp, a2: bfirst);
      SQFuncState::SetStackSize(this: v30, n: (int)v41);
      bfirst_3 = 0;
    }
    while ( bfirst->_token == 300 );
    if ( tonextcondjmp != -1 )
    {
      v31 = bfirst->_fs;
      v32 = v31->_instructions._size;
      vals = (SQLexer *)v31->_instructions._vals;
      *(&vals->_curtoken + 2 * tonextcondjmp) = v32 - tonextcondjmp - 1;
    }
  }
  if ( bfirst->_token == 301 )
  {
    v33 = SQLexer::Lex(this: vals);
    bfirst->_token = v33;
    if ( v33 != 58 )
LABEL_33:
      SQCompiler::Error(a1: (int)bfirst, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x3A);
    v35 = SQLexer::Lex(this: v34);
    v36 = bfirst->_fs;
    bfirst->_token = v35;
    v37 = (SQFuncState *)v36->_vlocals._size;
    SQCompiler::Statements(this: v38, a2: bfirst);
    SQFuncState::SetStackSize(this: v37, n: (int)v41);
  }
  if ( bfirst->_token != 125 )
    SQCompiler::Error(a1: (int)bfirst, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x7D);
  bfirst->_token = SQLexer::Lex(this: vals);
  SQFuncState::PopTarget(this: v39);
  v40 = bfirst->_fs;
  if ( (signed int)(v40->_unresolvedbreaks._size - __nbreaks__) > 0 )
    SQCompiler::ResolveBreaks(this: v41, funcstate: v40, ntoresolve: v40->_unresolvedbreaks._size - __nbreaks__);
  --bfirst->_fs->_breaktargets._size;
}

//------------------------------------------------------------------------------
// Address: 0x10043240
// Name: public: void SQCompiler::FunctionStatement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::FunctionStatement(SQCompiler *this, SQCompiler *thisa)
{
  int v3; // eax
  SQFuncState *fs; // edi
  const char *svalue; // eax
  const SQObjectPtr *type; // eax
  SQLexer *v7; // ecx
  int v8; // eax
  tagSQObjectType v9; // edi
  _DWORD *v10; // esi
  SQFuncState *v11; // esi
  unsigned int size; // eax
  int v13; // edi
  unsigned int v14; // eax
  SQFuncState *v15; // ecx
  int Constant; // esi
  SQFuncState *v17; // ecx
  unsigned __int8 v18; // al
  SQFuncState *v19; // esi
  SQFuncState *v20; // ecx
  SQFuncState *v21; // ecx
  int v22; // esi
  SQFuncState *v23; // ecx
  unsigned __int8 v24; // al
  SQFuncState *v25; // esi
  int v26; // eax
  int *v27; // eax
  SQLexer *v28; // ecx
  _DWORD *v29; // edi
  int v30; // eax
  int v31; // esi
  SQFuncState *v32; // edi
  SQCompiler *v33; // edx
  int stacksize; // eax
  unsigned int v35; // eax
  int v36; // esi
  unsigned int v37; // eax
  SQCompiler **v38; // ecx
  int v39; // eax
  SQFuncState *v40; // esi
  SQFuncState *v41; // edi
  int *vals; // ecx
  int v43; // edx
  SQLocalVarInfo *v44; // eax
  _DWORD *v45; // esi
  tagSQObjectType v46; // eax
  int v47; // edx
  SQLocalVarInfo *v48; // ecx
  tagSQObjectValue v49; // eax
  SQFuncState *v50; // edi
  tagSQObjectType v51; // esi
  SQLocalVarInfo *v52; // eax
  SQFuncState *pTable; // ecx
  tagSQObjectType v54; // eax
  SQLocalVarInfo *v55; // edx
  tagSQObjectValue v56; // eax
  SQFuncState *v57; // esi
  unsigned int v58; // esi
  SQFuncState *v59; // ecx
  char v60; // al
  SQFuncState *v61; // esi
  SQFuncState *v62; // ecx
  SQFuncState *v63; // ecx
  SQFuncState *v64; // ecx
  tagSQObjectType v65; // esi
  SQFuncState *v66; // ecx
  char v67; // al
  SQFuncState *v68; // esi
  SQFuncState *v69; // ecx
  const tagSQObject *v70; // [esp-8h] [ebp-74h]
  SQFuncState *v71; // [esp+14h] [ebp-58h]
  SQLocalVarInfo val; // [esp+24h] [ebp-48h] BYREF
  int v73; // [esp+38h] [ebp-34h] BYREF
  int len; // [esp+40h] [ebp-2Ch] BYREF
  SQObjectPtr v75; // [esp+48h] [ebp-24h] BYREF
  SQInstruction v76; // [esp+50h] [ebp-1Ch] BYREF
  tagSQObject id; // [esp+58h] [ebp-14h] BYREF
  SQInstruction i; // [esp+60h] [ebp-Ch] BYREF
  unsigned __int8 thise; // [esp+74h] [ebp+8h]
  SQCompiler *thisb; // [esp+74h] [ebp+8h]
  SQCompiler *thisc; // [esp+74h] [ebp+8h]
  SQCompiler *thisd; // [esp+74h] [ebp+8h]
  char thisf; // [esp+74h] [ebp+8h]

  v3 = SQLexer::Lex((SQLexer *)this);
  thisa->_token = v3;
  if ( v3 != 258 && v3 != 310 )
    goto LABEL_3;
  fs = thisa->_fs;
  svalue = thisa->_lex._svalue;
  v75._type = OT_NULL;
  v75._unVal.nInteger = 0;
  type = (const SQObjectPtr *)SQFuncState::CreateString(this: fs, s: svalue, (int)&len)._type;
  SQObjectPtr::operator=(this: &v75, obj: type);
  v8 = SQLexer::Lex(this: v7);
  v9 = v75._type;
  v10 = &v75._unVal.pTable->__vftable;
  thisa->_token = v8;
  if ( (v9 & 0x8000000) != 0 && (int)--v10[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10);
  id._unVal.nInteger = (int)v10;
  v11 = thisa->_fs;
  size = v11->_targetstack._size;
  id._type = v9;
  if ( v11->_targetstack._allocated <= size )
  {
    v13 = 2 * size;
    if ( 2 * size == 0 )
      v13 = 4;
    v11->_targetstack._vals = (int *)_g_pMemAlloc->Realloc_2(
                                       this: _g_pMemAlloc,
                                       a2: v11->_targetstack._vals,
                                       a3: 4 * v13);
    v11->_targetstack._allocated = v13;
  }
  v14 = v11->_targetstack._size;
  v15 = (SQFuncState *)&v11->_targetstack._vals[v14];
  v11->_targetstack._size = v14 + 1;
  if ( v15 != nullptr )
    v15->_returnexp = 0;
  Constant = SQFuncState::GetConstant(this: v15, cons: (const tagSQObject *)thisa->_fs);
  i.op = 1;
  v18 = SQFuncState::PushTarget(this: v17, n: -1);
  i._arg1 = Constant;
  v19 = thisa->_fs;
  i._arg0 = v18;
  *(_WORD *)&i._arg2 = 0;
  SQFuncState::AddInstruction(this: v19, &i);
  if ( thisa->_token == 299 )
  {
    thise = SQFuncState::PopTarget(this: v20);
    v22 = SQFuncState::PopTarget(this: v21);
    v24 = SQFuncState::PushTarget(this: v23, n: -1);
    i._arg1 = v22;
    v25 = thisa->_fs;
    i.op = 14;
    i._arg0 = v24;
    i._arg2 = thise;
    i._arg3 = 0;
    SQFuncState::AddInstruction(this: v25, &i);
    if ( thisa->_token == 299 )
    {
      while ( 1 )
      {
        v26 = SQLexer::Lex(this: (SQLexer *)v20);
        thisa->_token = v26;
        if ( v26 != 258 && v26 != 310 )
          break;
        v27 = (int *)SQFuncState::CreateString(this: thisa->_fs, s: thisa->_lex._svalue, len: (int)&v73)._type;
        v29 = (_DWORD *)v27[1];
        v30 = *v27;
        v31 = v30 & 0x8000000;
        len = v30;
        if ( (v30 & 0x8000000) != 0 )
          ++v29[1];
        thisa->_token = SQLexer::Lex(this: v28);
        if ( v31 != 0 && (int)--v29[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v29 + 8))(a1: v29);
        id._unVal.nInteger = (int)v29;
        v32 = thisa->_fs;
        v33 = (SQCompiler *)v32->_vlocals._size;
        memset(&val._name._unVal, 0, 12);
        id._type = len;
        thisb = v33;
        val._name._type = OT_NULL;
        sqvector<SQLocalVarInfo>::push_back(this: (sqvector<SQLocalVarInfo> *)len, a2: (int)&v32->_vlocals, &val);
        stacksize = v32->_stacksize;
        if ( v32->_vlocals._size > stacksize )
        {
          if ( stacksize > 255 )
            v32->_errfunc(a1: v32->_errtarget, a2: "internal compiler error: too many locals");
          v32->_stacksize = v32->_vlocals._size;
        }
        v35 = v32->_targetstack._size;
        if ( v32->_targetstack._allocated <= v35 )
        {
          v36 = 2 * v35;
          if ( 2 * v35 == 0 )
            v36 = 4;
          v32->_targetstack._vals = (int *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: v32->_targetstack._vals,
                                             a3: 4 * v36);
          v32->_targetstack._allocated = v36;
        }
        v37 = v32->_targetstack._size;
        v38 = (SQCompiler **)&v32->_targetstack._vals[v37];
        v32->_targetstack._size = v37 + 1;
        if ( v38 != nullptr )
          *v38 = thisb;
        v70 = (const tagSQObject *)thisa->_fs;
        v76.op = 1;
        v76._arg0 = (unsigned __int8)thisb;
        v39 = SQFuncState::GetConstant(this: (SQFuncState *)&id, cons: v70);
        v40 = thisa->_fs;
        v76._arg1 = v39;
        *(_WORD *)&v76._arg2 = 0;
        SQFuncState::AddInstruction(this: v40, i: &v76);
        if ( thisa->_token == 299 )
        {
          v41 = thisa->_fs;
          vals = v41->_targetstack._vals;
          v43 = vals[v41->_targetstack._size - 1];
          *(_DWORD *)&i.op = vals[v41->_targetstack._size - 1];
          v44 = v41->_vlocals._vals;
          v45 = &v44[v43]._name._unVal.pTable->__vftable;
          v46 = v44[v43]._name._type;
          v47 = v46 & 0x8000000;
          thisc = (SQCompiler *)(v46 & 0x8000000);
          if ( (v46 & 0x8000000) != 0 )
            ++v45[1];
          if ( v46 == OT_NULL )
          {
            v48 = &v41->_vlocals._vals[--v41->_vlocals._size];
            if ( (v48->_name._type & 0x8000000) != 0 )
            {
              v49.pTable = (SQTable *)v48->_name._unVal;
              if ( (int)--*(_DWORD *)(v49.nInteger + 4) <= 0 )
              {
                v48->_name._unVal.pTable->Release(this: (struct SQTable *)v48->_name._unVal.nInteger);
                v47 = (int)thisc;
              }
            }
          }
          --v41->_targetstack._size;
          if ( v47 != 0 && (int)--v45[1] <= 0 )
            (*(void (__thiscall **)(_DWORD *))(*v45 + 8))(a1: v45);
          v50 = thisa->_fs;
          v51 = v50->_targetstack._vals[v50->_targetstack._size - 1];
          v52 = &v50->_vlocals._vals[v51];
          pTable = (SQFuncState *)v52->_name._unVal.pTable;
          v54 = v52->_name._type;
          v71 = pTable;
          thisd = (SQCompiler *)(v54 & 0x8000000);
          if ( (v54 & 0x8000000) != 0 )
            ++pTable->_vlocals._vals;
          if ( v54 == OT_NULL )
          {
            v55 = &v50->_vlocals._vals[--v50->_vlocals._size];
            if ( (v55->_name._type & 0x8000000) != 0 )
            {
              v56.pTable = (SQTable *)v55->_name._unVal;
              if ( (int)--*(_DWORD *)(v56.nInteger + 4) <= 0 )
              {
                v55->_name._unVal.pTable->Release(this: (struct SQTable *)v55->_name._unVal.nInteger);
                pTable = v71;
              }
            }
          }
          --v50->_targetstack._size;
          if ( thisd != nullptr && (int)--pTable->_vlocals._vals <= 0 )
            (*(void (__thiscall **)(SQFuncState *))(pTable->_returnexp + 8))(a1: pTable);
          LOBYTE(v75._unVal.fFloat) = 14;
          BYTE1(v75._unVal.pTable) = SQFuncState::PushTarget(this: pTable, n: -1);
          v75._type = v51;
          v57 = thisa->_fs;
          HIWORD(v75._unVal.pArray) = i.op;
          SQFuncState::AddInstruction(this: v57, i: (SQInstruction *)&v75);
          if ( thisa->_token == 299 )
            continue;
        }
        goto LABEL_52;
      }
LABEL_3:
      SQCompiler::Error(a1: (int)thisa, this: (SQCompiler *)&stru_1009C274, s: "IDENTIFIER");
    }
  }
LABEL_52:
  if ( thisa->_token != 40 )
    SQCompiler::Error(a1: (int)thisa, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x28);
  thisa->_token = SQLexer::Lex(this: (SQLexer *)v20);
  SQCompiler::CreateFunction(this: thisa, name: &id);
  v58 = thisa->_fs->_functions._size;
  LOBYTE(v75._unVal.fFloat) = 48;
  v60 = SQFuncState::PushTarget(this: v59, n: -1);
  v75._type = v58 - 1;
  v61 = thisa->_fs;
  BYTE1(v75._unVal.pTable) = v60;
  HIWORD(v75._unVal.pArray) = 0;
  SQFuncState::AddInstruction(this: v61, i: (SQInstruction *)&v75);
  *(_DWORD *)&i.op = SQFuncState::PopTarget(this: v62);
  thisf = SQFuncState::PopTarget(this: v63);
  v65 = SQFuncState::PopTarget(this: v64);
  LOBYTE(v75._unVal.fFloat) = 11;
  v67 = SQFuncState::PushTarget(this: v66, n: -1);
  v75._type = v65;
  v68 = thisa->_fs;
  BYTE1(v75._unVal.pTable) = v67;
  BYTE2(v75._unVal.pArray) = thisf;
  HIBYTE(v75._unVal.pClosure) = i.op;
  SQFuncState::AddInstruction(this: v68, i: (SQInstruction *)&v75);
  SQFuncState::PopTarget(this: v69);
}

//------------------------------------------------------------------------------
// Address: 0x100436D0
// Name: public: void SQCompiler::ClassStatement(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQCompiler::ClassStatement(SQCompiler *this@<ecx>, SQCompiler *a2@<eax>)
{
  unsigned int size; // eax
  int v4; // edi
  unsigned int v5; // eax
  ExpState *v6; // ecx
  SQCompiler *v7; // ecx
  int deref; // eax
  SQCompiler *v9; // ecx
  SQFuncState *v10; // ecx
  const char *v11; // [esp+0h] [ebp-18h]
  int v12; // [esp+10h] [ebp-8h]

  a2->_token = SQLexer::Lex((SQLexer *)this);
  size = a2->_expstates._size;
  BYTE2(v12) = 0;
  LOWORD(v12) = 0;
  if ( a2->_expstates._allocated <= size )
  {
    v4 = 2 * size;
    if ( 2 * size == 0 )
      v4 = 4;
    a2->_expstates._vals = (ExpState *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: a2->_expstates._vals, a3: 8 * v4);
    a2->_expstates._allocated = v4;
  }
  v5 = a2->_expstates._size;
  v6 = &a2->_expstates._vals[v5];
  a2->_expstates._size = v5 + 1;
  if ( v6 != nullptr )
  {
    *(_DWORD *)&v6->_class_or_delete = v12;
    v6->_deref = -1;
  }
  a2->_expstates._vals[a2->_expstates._size - 1]._class_or_delete = true;
  a2->_expstates._vals[a2->_expstates._size - 1]._funcarg = false;
  SQCompiler::PrefixedExpr(this: a2);
  v7 = (SQCompiler *)a2->_expstates._size;
  deref = a2->_expstates._vals[(int)v7 - 1]._deref;
  a2->_expstates._size = (unsigned int)&v7[-1]._vm + 3;
  if ( deref == -1 )
    SQCompiler::Error(a1: (int)a2, this: (SQCompiler *)&stru_1009C428, s: v11);
  if ( deref != -2 )
    SQCompiler::Error(a1: (int)a2, this: (SQCompiler *)&stru_1009C428._lex._prevtoken, s: v11);
  SQCompiler::ClassExp(this: v7);
  SQCompiler::EmitDerefOp(this: v9, op: (int)a2, opa: 0xBu);
  SQFuncState::PopTarget(this: v10);
}

//------------------------------------------------------------------------------
// Address: 0x100437B0
// Name: public: struct tagSQObject SQCompiler::ExpectScalar(void)
// Source: json
//------------------------------------------------------------------------------
float *__userpurge SQCompiler::ExpectScalar@<eax>(SQCompiler *this@<ecx>, int *a2@<esi>, float *a3)
{
  SQLexer *v3; // ecx
  tagSQObjectType type; // eax
  SQLexer *v6; // ecx
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int v10; // xmm0_4
  const char *v11; // [esp+0h] [ebp-14h]
  int len[3]; // [esp+8h] [ebp-Ch] BYREF

  switch ( *a2 )
  {
    case 45:
      v8 = SQLexer::Lex((SQLexer *)this);
      *a2 = v8;
      v9 = v8 - 260;
      if ( v9 != 0 )
      {
        if ( v9 != 1 )
          SQCompiler::Error(a1: (int)a2, this: (SQCompiler *)&stru_1009C428._lineinfo, s: v11);
        v10 = a2[12] ^ _mask__NegFloat_;
        *a3 = 6.0185339e-36;
        *((_DWORD *)a3 + 1) = v10;
        *a2 = SQLexer::Lex(this: v3);
        return a3;
      }
      else
      {
        *((_DWORD *)a3 + 1) = -a2[11];
LABEL_10:
        *a3 = 6.0185325e-36;
        *a2 = SQLexer::Lex(this: v3);
        return a3;
      }
    case 259:
      type = SQFuncState::CreateString(this: (SQFuncState *)a2[1], s: (const char *)a2[10], (int)len)._type;
      v6 = *(SQLexer **)type;
      v7 = *(_DWORD *)(type + 4);
      *a3 = *(float *)type;
      *((_DWORD *)a3 + 1) = v7;
      *a2 = SQLexer::Lex(this: v6);
      return a3;
    case 260:
      v3 = (SQLexer *)a2[11];
      *((_DWORD *)a3 + 1) = v3;
      goto LABEL_10;
    case 261:
      a3[1] = *((float *)a2 + 12);
      *a3 = 6.0185339e-36;
      *a2 = SQLexer::Lex((SQLexer *)this);
      return a3;
    default:
      SQCompiler::Error(a1: (int)a2, this: (SQCompiler *)&stru_1009C428._errorjmp[1], s: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100439A0
// Name: public: void SQCompiler::EnumStatement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::EnumStatement(SQCompiler *this, SQCompiler *thisa)
{
  int v3; // eax
  SQFuncState *fs; // edi
  const char *svalue; // eax
  const SQObjectPtr *type; // eax
  SQLexer *v7; // ecx
  int v8; // eax
  SQLexer *v9; // ecx
  _DWORD *v10; // esi
  bool v11; // zf
  int *v12; // eax
  SQLexer *v13; // ecx
  _DWORD *v14; // edi
  int v15; // eax
  SQLexer *v16; // ecx
  float *v17; // eax
  tagSQObjectType v18; // ecx
  int v19; // eax
  SQLexer *v20; // ecx
  tagSQObjectValue v21; // eax
  tagSQObjectValue v22; // eax
  SQTable *pTable; // ecx
  SQLexer *v24; // ecx
  tagSQObjectValue v25; // eax
  tagSQObjectValue v26; // eax
  float v27[2]; // [esp+10h] [ebp-44h] BYREF
  int v28; // [esp+18h] [ebp-3Ch] BYREF
  int len; // [esp+20h] [ebp-34h] BYREF
  tagSQObject table; // [esp+28h] [ebp-2Ch] BYREF
  SQObjectPtr val; // [esp+30h] [ebp-24h] BYREF
  SQObjectPtr key; // [esp+38h] [ebp-1Ch] BYREF
  SQObjectPtr v33; // [esp+40h] [ebp-14h] BYREF
  int v34; // [esp+48h] [ebp-Ch]
  int nval; // [esp+4Ch] [ebp-8h]
  SQCompiler *thisb; // [esp+5Ch] [ebp+8h]

  v3 = SQLexer::Lex((SQLexer *)this);
  thisa->_token = v3;
  if ( v3 != 258 && v3 != 310 )
LABEL_3:
    SQCompiler::Error(a1: (int)thisa, this: (SQCompiler *)&stru_1009C274, s: "IDENTIFIER");
  fs = thisa->_fs;
  svalue = thisa->_lex._svalue;
  v33._type = OT_NULL;
  v33._unVal.nInteger = 0;
  type = (const SQObjectPtr *)SQFuncState::CreateString(this: fs, s: svalue, (int)&len)._type;
  SQObjectPtr::operator=(this: &v33, obj: type);
  v8 = SQLexer::Lex(this: v7);
  v10 = &v33._unVal.pTable->__vftable;
  thisa->_token = v8;
  thisb = (SQCompiler *)(v33._type & 0x8000000);
  if ( (v33._type & 0x8000000) != 0 && (int)--v10[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10);
  if ( thisa->_token != 123 )
    SQCompiler::Error(a1: (int)thisa, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x7B);
  thisa->_token = SQLexer::Lex(this: v9);
  SQFuncState::CreateTable(this: (SQFuncState *)&table);
  v11 = thisa->_token == 125;
  nval = 0;
  if ( !v11 )
  {
    do
    {
      if ( thisa->_token != 258 && thisa->_token != 310 )
        goto LABEL_3;
      v12 = (int *)SQFuncState::CreateString(this: thisa->_fs, s: thisa->_lex._svalue, len: (int)&v28)._type;
      v14 = (_DWORD *)v12[1];
      len = *v12;
      v34 = len & 0x8000000;
      if ( (len & 0x8000000) != 0 )
        ++v14[1];
      v15 = SQLexer::Lex(this: v13);
      v11 = v34 == 0;
      thisa->_token = v15;
      if ( !v11 && (int)--v14[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
      if ( thisa->_token == 61 )
      {
        thisa->_token = SQLexer::Lex(this: v16);
        v17 = SQCompiler::ExpectScalar(this: (SQCompiler *)v27, a2: &thisa->_token, a3: v27);
        v18 = *(_DWORD *)v17;
        v19 = *((_DWORD *)v17 + 1);
      }
      else
      {
        v19 = nval;
        v18 = OT_INTEGER;
        ++nval;
      }
      val._type = v18;
      val._unVal.nInteger = v19;
      if ( (v18 & 0x8000000) != 0 )
        ++*(_DWORD *)(v19 + 4);
      key._type = len;
      key._unVal.nInteger = (int)v14;
      if ( v34 != 0 )
        ++v14[1];
      SQTable::NewSlot(this: table._unVal.pTable, &key, &val);
      if ( (key._type & 0x8000000) != 0 )
      {
        v21.pTable = (SQTable *)key._unVal;
        --*(_DWORD *)(key._unVal.nInteger + 4);
        if ( *(int *)(v21.nInteger + 4) <= 0 )
          key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
      }
      if ( (val._type & 0x8000000) != 0 )
      {
        v22.pTable = (SQTable *)val._unVal;
        --*(_DWORD *)(val._unVal.nInteger + 4);
        if ( *(int *)(v22.nInteger + 4) <= 0 )
          val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
      }
      if ( thisa->_token == 44 )
        thisa->_token = SQLexer::Lex(this: v20);
    }
    while ( thisa->_token != 125 );
    v10 = &v33._unVal.pTable->__vftable;
  }
  pTable = thisa->_vm->_sharedstate->_consts._unVal.pTable;
  if ( thisb != nullptr )
    ++v10[1];
  key = (SQObjectPtr)table;
  if ( (table._type & 0x8000000) != 0 )
    ++*(_DWORD *)(table._unVal.nInteger + 4);
  val._type = v33._type;
  val._unVal.nInteger = (int)v10;
  if ( thisb != nullptr )
    ++v10[1];
  SQTable::NewSlot(this: pTable, key: &val, val: &key);
  if ( (val._type & 0x8000000) != 0 )
  {
    v25.pTable = (SQTable *)val._unVal;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( *(int *)(v25.nInteger + 4) <= 0 )
      val._unVal.pTable->Release(this: (struct SQTable *)val._unVal.nInteger);
  }
  if ( (key._type & 0x8000000) != 0 )
  {
    v26.pTable = (SQTable *)key._unVal;
    --*(_DWORD *)(key._unVal.nInteger + 4);
    if ( *(int *)(v26.nInteger + 4) <= 0 )
      key._unVal.pTable->Release(this: (struct SQTable *)key._unVal.nInteger);
  }
  if ( thisb != nullptr && (int)--v10[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10);
  thisa->_token = SQLexer::Lex(this: v24);
}

//------------------------------------------------------------------------------
// Address: 0x10043C30
// Name: public: void SQCompiler::TryCatchStatement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::TryCatchStatement(SQCompiler *this, SQCompiler *trappos)
{
  int v3; // eax
  SQFuncState *fs; // esi
  SQFuncState *v5; // eax
  SQFuncState *v6; // eax
  SQFuncState *v7; // esi
  SQFuncState *v8; // eax
  SQFuncState *v9; // eax
  SQFuncState *v10; // esi
  SQFuncState *v11; // ecx
  unsigned int size; // eax
  SQLexer *vals; // ecx
  const char *v14; // eax
  int v15; // eax
  SQLexer *v16; // ecx
  int v17; // eax
  const char *svalue; // eax
  SQFuncState *v19; // edi
  const SQObjectPtr *type; // eax
  SQLexer *v21; // ecx
  int v22; // eax
  SQLexer *v23; // ecx
  bool v24; // zf
  _DWORD *v25; // esi
  SQFuncState *v26; // esi
  SQFuncState *v27; // eax
  unsigned int v28; // ecx
  int v29; // edx
  int v30; // [esp+0h] [ebp-2Ch]
  int len; // [esp+10h] [ebp-1Ch] BYREF
  tagSQObject exid; // [esp+18h] [ebp-14h] BYREF
  SQInstruction i; // [esp+20h] [ebp-Ch] BYREF
  int trapposa; // [esp+34h] [ebp+8h]

  v3 = SQLexer::Lex((SQLexer *)this);
  fs = trappos->_fs;
  trappos->_token = v3;
  i._arg1 = 0;
  *(_DWORD *)&i.op = 56;
  SQFuncState::AddInstruction(this: fs, &i);
  ++trappos->_fs->_traps;
  v5 = trappos->_fs;
  if ( v5->_breaktargets._size != 0 )
    ++v5->_breaktargets._vals[v5->_breaktargets._size - 1];
  v6 = trappos->_fs;
  if ( v6->_continuetargets._size != 0 )
    ++v6->_continuetargets._vals[v6->_continuetargets._size - 1];
  trapposa = trappos->_fs->_instructions._size - 1;
  SQCompiler::Statement(this: trappos);
  --trappos->_fs->_traps;
  v7 = trappos->_fs;
  i._arg1 = 0;
  *(_DWORD *)&i.op = 313;
  SQFuncState::AddInstruction(this: v7, &i);
  v8 = trappos->_fs;
  if ( v8->_breaktargets._size != 0 )
    --v8->_breaktargets._vals[v8->_breaktargets._size - 1];
  v9 = trappos->_fs;
  if ( v9->_continuetargets._size != 0 )
    --v9->_continuetargets._vals[v9->_continuetargets._size - 1];
  v10 = trappos->_fs;
  i._arg1 = 0;
  *(_DWORD *)&i.op = 24;
  SQFuncState::AddInstruction(this: v10, &i);
  v11 = trappos->_fs;
  size = v11->_instructions._size;
  vals = (SQLexer *)v11->_instructions._vals;
  *(_DWORD *)&i.op = size - 1;
  *(&vals->_curtoken + 2 * trapposa) = size - trapposa - 1;
  if ( trappos->_token != 294 )
  {
    v14 = SQLexer::Tok2Str(this: vals, tok: (int)&trappos->_lex);
    SQCompiler::Error(a1: (int)trappos, this: (SQCompiler *)&stru_1009C274, s: v14);
  }
  v15 = SQLexer::Lex(this: vals);
  trappos->_token = v15;
  if ( v15 != 40 )
    SQCompiler::Error(a1: (int)trappos, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x28);
  v17 = SQLexer::Lex(this: v16);
  trappos->_token = v17;
  if ( v17 != 258 && v17 != 310 )
    SQCompiler::Error(a1: (int)trappos, this: (SQCompiler *)&stru_1009C274, s: "IDENTIFIER");
  svalue = trappos->_lex._svalue;
  v19 = trappos->_fs;
  exid._type = OT_NULL;
  exid._unVal.nInteger = 0;
  type = (const SQObjectPtr *)SQFuncState::CreateString(this: v19, s: svalue, (int)&len)._type;
  SQObjectPtr::operator=(this: (SQObjectPtr *)&exid, obj: type);
  v22 = SQLexer::Lex(this: v21);
  v24 = (exid._type & 0x8000000) == 0;
  v25 = &exid._unVal.pTable->__vftable;
  trappos->_token = v22;
  if ( !v24 && (int)--v25[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v25 + 8))(a1: v25);
  v24 = trappos->_token == 41;
  exid._unVal.nInteger = (int)v25;
  if ( !v24 )
    SQCompiler::Error(a1: (int)trappos, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x29);
  trappos->_token = SQLexer::Lex(this: v23);
  v26 = (SQFuncState *)trappos->_fs->_vlocals._size;
  trappos->_fs->_instructions._vals[trapposa]._arg0 = SQFuncState::PushLocalVariable(this: trappos->_fs, name: &exid);
  SQCompiler::Statement(this: trappos);
  v27 = trappos->_fs;
  v28 = v27->_instructions._size;
  v29 = *(_DWORD *)&i.op;
  v27->_instructions._vals[*(_DWORD *)&i.op]._arg0 = 0;
  v27->_instructions._vals[v29]._arg1 = v28 - v29 - 1;
  v27->_instructions._vals[v29]._arg2 = 0;
  v27->_instructions._vals[v29]._arg3 = 0;
  if ( (SQFuncState *)trappos->_fs->_vlocals._size != v26 )
    SQFuncState::SetStackSize(this: v26, n: v30);
}

//------------------------------------------------------------------------------
// Address: 0x10043E90
// Name: public: void SQCompiler::FunctionExp(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQCompiler::FunctionExp(SQCompiler *this@<ecx>, SQCompiler *a2@<eax>, int ftype)
{
  int v4; // eax
  SQLexer *v5; // ecx
  unsigned int size; // ebx
  SQFuncState *v7; // ecx
  unsigned __int8 v8; // al
  SQFuncState *fs; // esi
  SQInstruction i; // [esp+10h] [ebp-Ch] BYREF

  v4 = SQLexer::Lex((SQLexer *)this);
  a2->_token = v4;
  if ( v4 != 40 )
    SQCompiler::Error(a1: (int)a2, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x28);
  a2->_token = SQLexer::Lex(this: v5);
  SQCompiler::CreateFunction(this: a2, name: &_null_);
  size = a2->_fs->_functions._size;
  i.op = 48;
  v8 = SQFuncState::PushTarget(this: v7, n: -1);
  fs = a2->_fs;
  i._arg0 = v8;
  i._arg1 = size - 1;
  i._arg2 = ftype != 285;
  i._arg3 = 0;
  SQFuncState::AddInstruction(this: fs, &i);
}

//------------------------------------------------------------------------------
// Address: 0x10043F10
// Name: public: void SQCompiler::ClassExp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::ClassExp(SQCompiler *this, SQCompiler *base)
{
  bool v3; // zf
  SQFuncState *fs; // eax
  SQFuncState *v5; // ecx
  unsigned __int8 v6; // al
  SQFuncState *v7; // esi
  SQFuncState *v8; // eax
  SQFuncState *v9; // ecx
  char v10; // al
  SQFuncState *v11; // esi
  ExpState result; // [esp+10h] [ebp-14h] BYREF
  SQInstruction i; // [esp+18h] [ebp-Ch] BYREF
  int basea; // [esp+2Ch] [ebp+8h]

  v3 = base->_token == 308;
  basea = -1;
  *(_DWORD *)&i.op = -1;
  if ( v3 )
  {
    base->_token = SQLexer::Lex((SQLexer *)this);
    SQCompiler::Expression(this: base, &result, funcarg: false);
    fs = base->_fs;
    this = (SQCompiler *)fs->_targetstack._size;
    basea = fs->_targetstack._vals[(_DWORD)this - 1];
  }
  if ( base->_token == 320 )
  {
    base->_token = SQLexer::Lex((SQLexer *)this);
    v6 = SQFuncState::PushTarget(this: v5, n: -1);
    v7 = base->_fs;
    i.op = 30;
    i._arg0 = v6;
    i._arg1 = 0;
    *(_WORD *)&i._arg2 = 0;
    SQFuncState::AddInstruction(this: v7, &i);
    SQCompiler::ParseTableOrClass(this: base, separator: (SQLexer *)0x2C, terminator: (SQFuncState *)0x141);
    v8 = base->_fs;
    this = (SQCompiler *)v8->_targetstack._size;
    *(_DWORD *)&i.op = v8->_targetstack._vals[(_DWORD)this - 1];
  }
  if ( base->_token != 123 )
    SQCompiler::Error(a1: (int)base, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x7B);
  base->_token = SQLexer::Lex((SQLexer *)this);
  if ( *(_DWORD *)&i.op != -1 )
    SQFuncState::PopTarget(this: v9);
  if ( basea != -1 )
    SQFuncState::PopTarget(this: v9);
  v10 = SQFuncState::PushTarget(this: v9, n: -1);
  v11 = base->_fs;
  LOBYTE(result._deref) = 59;
  BYTE1(result._deref) = v10;
  *(_DWORD *)&result._class_or_delete = basea;
  HIWORD(result._deref) = i.op;
  SQFuncState::AddInstruction(this: v11, i: (SQInstruction *)&result);
  SQCompiler::ParseTableOrClass(this: base, separator: (SQLexer *)0x3B, terminator: (SQFuncState *)0x7D);
}

//------------------------------------------------------------------------------
// Address: 0x10044030
// Name: public: void SQCompiler::DelegateExpr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::DelegateExpr(SQCompiler *this, SQCompiler *table)
{
  SQLexer *v3; // ecx
  SQFuncState *v4; // ecx
  SQFuncState *v5; // ecx
  SQFuncState *v6; // ecx
  unsigned __int8 v7; // al
  SQFuncState *fs; // esi
  SQInstruction i; // [esp+Ch] [ebp-10h] BYREF
  int delegate; // [esp+14h] [ebp-8h]
  int tablea; // [esp+24h] [ebp+8h]

  table->_token = SQLexer::Lex((SQLexer *)this);
  SQCompiler::CommaExpr(this: table);
  if ( table->_token != 58 )
    SQCompiler::Error(a1: (int)table, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x3A);
  table->_token = SQLexer::Lex(this: v3);
  SQCompiler::CommaExpr(this: table);
  tablea = SQFuncState::PopTarget(this: v4);
  delegate = SQFuncState::PopTarget(this: v5);
  i.op = 53;
  v7 = SQFuncState::PushTarget(this: v6, n: -1);
  fs = table->_fs;
  i._arg0 = v7;
  i._arg1 = tablea;
  i._arg2 = delegate;
  i._arg3 = 0;
  SQFuncState::AddInstruction(this: fs, &i);
}

//------------------------------------------------------------------------------
// Address: 0x100440C0
// Name: public: void SQCompiler::DeleteExpr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::DeleteExpr(SQCompiler *this, SQCompiler *thisa)
{
  unsigned int size; // eax
  int v4; // esi
  unsigned int v5; // eax
  _DWORD *p_class_or_delete; // ecx
  ExpState *vals; // eax
  unsigned int v8; // ecx
  int v9; // edx
  int deref; // eax
  SQFuncState *v11; // ecx
  int v12; // esi
  SQFuncState *v13; // ecx
  SQFuncState *fs; // esi
  const char *v15; // [esp+0h] [ebp-1Ch]
  SQInstruction i; // [esp+10h] [ebp-Ch] BYREF
  unsigned __int8 thisb; // [esp+24h] [ebp+8h]

  thisa->_token = SQLexer::Lex((SQLexer *)this);
  size = thisa->_expstates._size;
  BYTE2(i._arg1) = 0;
  LOWORD(i._arg1) = 0;
  if ( thisa->_expstates._allocated <= size )
  {
    v4 = 2 * size;
    if ( 2 * size == 0 )
      v4 = 4;
    thisa->_expstates._vals = (ExpState *)_g_pMemAlloc->Realloc_2(
                                            this: _g_pMemAlloc,
                                            a2: thisa->_expstates._vals,
                                            a3: 8 * v4);
    thisa->_expstates._allocated = v4;
  }
  v5 = thisa->_expstates._size;
  p_class_or_delete = &thisa->_expstates._vals[v5]._class_or_delete;
  thisa->_expstates._size = v5 + 1;
  if ( p_class_or_delete != nullptr )
  {
    *p_class_or_delete = i._arg1;
    p_class_or_delete[1] = -1;
  }
  thisa->_expstates._vals[thisa->_expstates._size - 1]._class_or_delete = true;
  thisa->_expstates._vals[thisa->_expstates._size - 1]._funcarg = false;
  SQCompiler::PrefixedExpr(this: thisa);
  vals = thisa->_expstates._vals;
  v8 = thisa->_expstates._size;
  v9 = *(_DWORD *)&vals[v8 - 1]._class_or_delete;
  deref = vals[v8 - 1]._deref;
  thisa->_expstates._size = v8 - 1;
  i._arg1 = v9;
  if ( deref == -1 )
    SQCompiler::Error(a1: (int)thisa, this: (SQCompiler *)&stru_1009C428._errorjmp[12], s: v15);
  if ( deref != -2 )
    SQCompiler::Error(a1: (int)thisa, this: (SQCompiler *)&stru_1009C4E8, s: v15);
  thisb = SQFuncState::PopTarget(this: (SQFuncState *)v8);
  v12 = SQFuncState::PopTarget(this: v11);
  i._arg0 = SQFuncState::PushTarget(this: v13, n: -1);
  i._arg1 = v12;
  fs = thisa->_fs;
  i.op = 12;
  i._arg2 = thisb;
  i._arg3 = 0;
  SQFuncState::AddInstruction(this: fs, &i);
}

//------------------------------------------------------------------------------
// Address: 0x100441D0
// Name: public: void SQCompiler::PrefixIncDec(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQCompiler::PrefixIncDec(SQCompiler *this, SQCompiler *token, int tokena)
{
  unsigned int size; // eax
  int v5; // esi
  unsigned int v6; // eax
  _DWORD *p_class_or_delete; // ecx
  ExpState *vals; // eax
  unsigned int v9; // ecx
  int v10; // edx
  int deref; // eax
  SQFuncState *v12; // ecx
  int v13; // esi
  SQFuncState *v14; // ecx
  SQFuncState *v15; // ecx
  SQInstruction i; // [esp+10h] [ebp-8h] BYREF
  unsigned __int8 thisa; // [esp+20h] [ebp+8h]

  token->_token = SQLexer::Lex((SQLexer *)this);
  size = token->_expstates._size;
  BYTE2(i._arg1) = 0;
  LOWORD(i._arg1) = 0;
  if ( token->_expstates._allocated <= size )
  {
    v5 = 2 * size;
    if ( 2 * size == 0 )
      v5 = 4;
    token->_expstates._vals = (ExpState *)_g_pMemAlloc->Realloc_2(
                                            this: _g_pMemAlloc,
                                            a2: token->_expstates._vals,
                                            a3: 8 * v5);
    token->_expstates._allocated = v5;
  }
  v6 = token->_expstates._size;
  p_class_or_delete = &token->_expstates._vals[v6]._class_or_delete;
  token->_expstates._size = v6 + 1;
  if ( p_class_or_delete != nullptr )
  {
    *p_class_or_delete = i._arg1;
    p_class_or_delete[1] = -1;
  }
  token->_expstates._vals[token->_expstates._size - 1]._class_or_delete = true;
  token->_expstates._vals[token->_expstates._size - 1]._funcarg = false;
  SQCompiler::PrefixedExpr(this: token);
  vals = token->_expstates._vals;
  v9 = token->_expstates._size;
  v10 = *(_DWORD *)&vals[v9 - 1]._class_or_delete;
  deref = vals[v9 - 1]._deref;
  token->_expstates._size = v9 - 1;
  i._arg1 = v10;
  if ( deref == -2 )
  {
    thisa = SQFuncState::PopTarget(this: (SQFuncState *)v9);
    v13 = SQFuncState::PopTarget(this: v12);
    i._arg0 = SQFuncState::PushTarget(this: v14, n: -1);
    i.op = 36;
    i._arg2 = thisa;
  }
  else
  {
    v13 = SQFuncState::PopTarget(this: (SQFuncState *)v9);
    i.op = 37;
    i._arg0 = SQFuncState::PushTarget(this: v15, n: -1);
    i._arg2 = 0;
  }
  i._arg3 = tokena != 304 ? 1 : -1;
  i._arg1 = v13;
  SQFuncState::AddInstruction(this: token->_fs, &i);
}

//------------------------------------------------------------------------------
// Address: 0x10044300
// Name: public: void SQCompiler::CreateFunction(struct tagSQObject __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQCompiler::CreateFunction(tagSQObject *name@<eax>, SQCompiler *this)
{
  SQFuncState *v4; // eax
  _DWORD *v5; // ecx
  tagSQObjectType type; // esi
  tagSQObjectType v7; // edx
  const tagSQObject *v8; // esi
  sqvector<SQObjectPtr> *v9; // ecx
  tagSQObjectType v10; // eax
  tagSQObjectValue v11; // esi
  int *pTable; // ecx
  SQLexer *v13; // ecx
  tagSQObjectType v14; // edx
  tagSQObjectType v15; // eax
  bool v16; // zf
  int token; // eax
  tagSQObjectType v18; // eax
  SQLexer *v19; // ecx
  _DWORD *v20; // edi
  tagSQObjectType v21; // eax
  int v22; // esi
  sqvector<SQLocalVarInfo> *size; // ecx
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned int v26; // ecx
  SQObjectPtr *v27; // eax
  unsigned int v28; // eax
  int v29; // edi
  unsigned int v30; // eax
  int v31; // eax
  int v32; // eax
  SQFuncState *v33; // ecx
  int v34; // edi
  int v35; // eax
  SQLexer *v36; // ecx
  int v37; // eax
  SQLexer *v38; // ecx
  tagSQObjectType *v39; // eax
  SQLexer *v40; // ecx
  _DWORD *v41; // esi
  tagSQObjectType v42; // eax
  int v43; // edi
  SQFuncState *fs; // eax
  SQFuncState *v45; // ecx
  int lasttokenline; // eax
  SQFuncState *v47; // ecx
  SQFunctionProto *v48; // edi
  SQFuncState *v49; // esi
  unsigned int v50; // eax
  int v51; // eax
  unsigned int v52; // ecx
  SQObjectPtr *v53; // eax
  SQFuncState *v54; // ebx
  SQFuncState *v55; // edi
  const char *v56; // [esp+0h] [ebp-54h]
  SQLocalVarInfo v57; // [esp+10h] [ebp-44h] BYREF
  ExpState result; // [esp+24h] [ebp-30h] BYREF
  int len; // [esp+2Ch] [ebp-28h] BYREF
  tagSQObject paramname; // [esp+34h] [ebp-20h] BYREF
  tagSQObjectType v61; // [esp+3Ch] [ebp-18h]
  SQFuncState *currchunk; // [esp+40h] [ebp-14h]
  SQObjectPtr val; // [esp+44h] [ebp-10h] BYREF
  int defparams; // [esp+4Ch] [ebp-8h]
  SQFuncState *funcstate; // [esp+5Ch] [ebp+8h]
  int funcstatea; // [esp+5Ch] [ebp+8h]

  v4 = SQFuncState::PushChildState(this: (SQFuncState *)this->_vm->_sharedstate, ss: this->_vm->_sharedstate);
  v5 = &v4->_name._unVal.pTable->__vftable;
  type = v4->_name._type;
  v4->_name._unVal.nInteger = name->_unVal.nInteger;
  v7 = name->_type;
  funcstate = v4;
  v4->_name._type = name->_type;
  if ( (v7 & 0x8000000) != 0 )
    ++*(_DWORD *)(v4->_name._unVal.nInteger + 4);
  if ( (type & 0x8000000) != 0 && (int)--v5[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v5 + 8))(a1: v5);
  v8 = (const tagSQObject *)SQFuncState::CreateString(
                              this: this->_fs,
                              s: (const char *)&stru_1009C274._lex._longstr,
                              len: (int)&paramname)._type;
  SQFuncState::PushLocalVariable(this: funcstate, name: v8);
  v10 = v8->_type;
  v11.pTable = (SQTable *)v8->_unVal;
  val._type = v10;
  val._unVal = v11;
  currchunk = (SQFuncState *)(v10 & 0x8000000);
  if ( (v10 & 0x8000000) != 0 )
    ++*(_DWORD *)(v11.nInteger + 4);
  sqvector<SQObjectPtr>::push_back(this: v9, a2: (int)&funcstate->_parameters, &val);
  if ( currchunk != nullptr )
  {
    pTable = (int *)val._unVal.pTable;
    --*(_DWORD *)(val._unVal.nInteger + 4);
    if ( pTable[1] <= 0 )
      (*(void (__thiscall **)(int *))(*pTable + 8))(a1: pTable);
  }
  v13 = (SQLexer *)funcstate->_sourcename._unVal.pTable;
  v14 = funcstate->_sourcename._type;
  funcstate->_sourcename._unVal.nInteger = this->_sourcename._unVal.nInteger;
  v15 = this->_sourcename._type;
  funcstate->_sourcename._type = v15;
  if ( (v15 & 0x8000000) != 0 )
    ++*(_DWORD *)(funcstate->_sourcename._unVal.nInteger + 4);
  if ( (v14 & 0x8000000) != 0 && (int)--v13->_keywords <= 0 )
    (*(void (__thiscall **)(SQLexer *))(v13->_curtoken + 8))(a1: v13);
  v16 = this->_token == 41;
  defparams = 0;
  if ( !v16 )
  {
    while ( 1 )
    {
      token = this->_token;
      if ( this->_token == 312 )
      {
        if ( defparams > 0 )
          SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C4E8._lex._prevtoken, s: v56);
        funcstate->_varparams = true;
        v31 = SQLexer::Lex(this: v13);
        this->_token = v31;
        if ( v31 != 41 )
          SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C4E8._expstates, s: v56);
        goto $LN370_0;
      }
      if ( token != 258 && token != 310 )
        goto $LN367;
      v18 = SQFuncState::CreateString(this: this->_fs, s: this->_lex._svalue, (int)&len)._type;
      v20 = *(_DWORD **)(v18 + 4);
      v21 = *(_DWORD *)v18;
      v22 = v21 & 0x8000000;
      paramname._type = v21;
      val._unVal.nInteger = v21 & 0x8000000;
      if ( (v21 & 0x8000000) != 0 )
        ++v20[1];
      this->_token = SQLexer::Lex(this: v19);
      if ( v22 != 0 && (int)--v20[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v20 + 8))(a1: v20);
      v57._end_op = 0;
      v57._name._unVal.nInteger = (int)v20;
      v57._name._type = paramname._type;
      if ( v22 != 0 )
        ++v20[1];
      size = (sqvector<SQLocalVarInfo> *)funcstate->_vlocals._size;
      v57._start_op = funcstate->_instructions._size;
      v57._pos = (unsigned int)size;
      sqvector<SQLocalVarInfo>::push_back(this: size, a2: (int)&funcstate->_vlocals, val: &v57);
      v24 = funcstate->_vlocals._size;
      if ( v24 > funcstate->_stacksize )
        funcstate->_stacksize = v24;
      if ( val._unVal.nInteger != 0 )
      {
        if ( (int)--v20[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v20 + 8))(a1: v20);
        if ( val._unVal.nInteger != 0 )
          ++v20[1];
      }
      v25 = funcstate->_parameters._size;
      if ( funcstate->_parameters._allocated <= v25 )
      {
        currchunk = (SQFuncState *)(2 * v25);
        if ( 2 * v25 == 0 )
          currchunk = (SQFuncState *)4;
        funcstate->_parameters._vals = (SQObjectPtr *)_g_pMemAlloc->Realloc_2(
                                                        this: _g_pMemAlloc,
                                                        a2: funcstate->_parameters._vals,
                                                        a3: 8 * (_DWORD)currchunk);
        funcstate->_parameters._allocated = (unsigned int)currchunk;
      }
      v26 = funcstate->_parameters._size;
      v27 = &funcstate->_parameters._vals[v26];
      v13 = (SQLexer *)(v26 + 1);
      funcstate->_parameters._size = (unsigned int)v13;
      if ( v27 == nullptr )
        goto LABEL_41;
      v16 = val._unVal.nInteger == 0;
      v13 = (SQLexer *)paramname._type;
      v27->_type = paramname._type;
      v27->_unVal.nInteger = (int)v20;
      if ( !v16 )
        break;
LABEL_44:
      if ( this->_token == 61 )
      {
        this->_token = SQLexer::Lex(this: v13);
        SQCompiler::Expression(this, &result, funcarg: false);
        v28 = funcstate->_defaultparams._size;
        currchunk = (SQFuncState *)this->_fs->_targetstack._vals[this->_fs->_targetstack._size - 1];
        if ( funcstate->_defaultparams._allocated <= v28 )
        {
          v29 = 2 * v28;
          if ( 2 * v28 == 0 )
            v29 = 4;
          funcstate->_defaultparams._vals = (int *)_g_pMemAlloc->Realloc_2(
                                                     this: _g_pMemAlloc,
                                                     a2: funcstate->_defaultparams._vals,
                                                     a3: 4 * v29);
          funcstate->_defaultparams._allocated = v29;
        }
        v30 = funcstate->_defaultparams._size;
        v13 = (SQLexer *)&funcstate->_defaultparams._vals[v30];
        funcstate->_defaultparams._size = v30 + 1;
        if ( v13 != nullptr )
          v13->_curtoken = (int)currchunk;
        ++defparams;
      }
      else if ( defparams > 0 )
      {
        SQCompiler::Error(a1: (int)this, this: (SQCompiler *)stru_1009C4E8._errorjmp, s: v56);
      }
      if ( this->_token == 44 )
      {
        this->_token = SQLexer::Lex(this: v13);
      }
      else if ( this->_token != 41 )
      {
$LN369:
        SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C4E8._errorjmp[4], s: v56);
      }
      if ( this->_token == 41 )
        goto $LN370_0;
    }
    ++v20[1];
LABEL_41:
    if ( val._unVal.nInteger != 0 && (int)--v20[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v20 + 8))(a1: v20);
    goto LABEL_44;
  }
$LN370_0:
  v32 = SQLexer::Lex(this: v13);
  v34 = defparams;
  this->_token = v32;
  if ( v34 > 0 )
  {
    do
    {
      SQFuncState::PopTarget(this: v33);
      --v34;
    }
    while ( v34 != 0 );
  }
  if ( this->_token == 58 )
  {
    v35 = SQLexer::Lex(this: (SQLexer *)v33);
    this->_token = v35;
    if ( v35 != 40 )
      SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C274._lex, s: (const char *)0x28);
    v37 = SQLexer::Lex(this: v36);
    this->_token = v37;
    if ( v37 != 41 )
    {
      while ( this->_token == 258 || this->_token == 310 )
      {
        v39 = (tagSQObjectType *)SQFuncState::CreateString(this: this->_fs, s: this->_lex._svalue, len: (int)&result)._type;
        v41 = *((_DWORD **)v39 + 1);
        v42 = *v39;
        v43 = v42 & 0x8000000;
        v61 = v42;
        if ( (v42 & 0x8000000) != 0 )
          ++v41[1];
        this->_token = SQLexer::Lex(this: v40);
        if ( v43 != 0 && (int)--v41[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v41 + 8))(a1: v41);
        paramname._type = v61;
        paramname._unVal.nInteger = (int)v41;
        SQFuncState::AddOuterValue(this: funcstate, name: &paramname);
        if ( this->_token == 44 )
        {
          this->_token = SQLexer::Lex(this: v38);
        }
        else if ( this->_token != 41 )
        {
          goto $LN369;
        }
        if ( this->_token == 41 )
          goto LABEL_82;
      }
$LN367:
      SQCompiler::Error(a1: (int)this, this: (SQCompiler *)&stru_1009C274, s: "IDENTIFIER");
    }
LABEL_82:
    this->_token = SQLexer::Lex(this: v38);
  }
  fs = this->_fs;
  this->_fs = funcstate;
  currchunk = fs;
  SQCompiler::Statement(this);
  if ( this->_lex._prevtoken == 10 )
    lasttokenline = this->_lex._lasttokenline;
  else
    lasttokenline = this->_lex._currentline;
  SQFuncState::AddLineInfos(this: v45, line: lasttokenline, lineop: this->_lineinfo, force: true);
  val._type = 0;
  val._unVal.nInteger = 65299;
  SQFuncState::AddInstruction(this: funcstate, i: (SQInstruction *)&val);
  SQFuncState::SetStackSize(this: nullptr, n: (int)v56);
  v48 = SQFuncState::BuildProto(this: v47);
  this->_fs = currchunk;
  ++v48->_uiRef;
  v49 = this->_fs;
  v50 = v49->_functions._size;
  if ( v49->_functions._allocated <= v50 )
  {
    v16 = 2 * v50 == 0;
    v51 = 2 * v50;
    funcstatea = v51;
    if ( v16 )
    {
      funcstatea = 4;
      v51 = 4;
    }
    v49->_functions._vals = (SQObjectPtr *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: v49->_functions._vals,
                                             a3: 8 * v51);
    v49->_functions._allocated = funcstatea;
  }
  v52 = v49->_functions._size;
  v53 = &v49->_functions._vals[v52];
  v49->_functions._size = v52 + 1;
  if ( v53 != nullptr )
  {
    v53->_type = OT_FUNCPROTO;
    v53->_unVal.nInteger = (int)v48;
    ++v48->_uiRef;
  }
  if ( --v48->_uiRef <= 0 )
    v48->Release(this: v48);
  v54 = this->_fs;
  v55 = v54->_childstates._vals[v54->_childstates._size - 1];
  SQFuncState::~SQFuncState(this: v55);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v55);
  --v54->_childstates._size;
}

//------------------------------------------------------------------------------
// Address: 0x10044890
// Name: public: void SQCompiler::ResolveBreaks(struct SQFuncState __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQCompiler::ResolveBreaks(SQFuncState *funcstate@<eax>, int ntoresolve@<ecx>, SQCompiler *this)
{
  int i; // esi
  int v4; // ecx
  unsigned int size; // edx

  for ( i = ntoresolve; i > 0; funcstate->_instructions._vals[v4]._arg3 = 0 )
  {
    v4 = funcstate->_unresolvedbreaks._vals[--funcstate->_unresolvedbreaks._size];
    size = funcstate->_instructions._size;
    funcstate->_instructions._vals[v4]._arg0 = 0;
    funcstate->_instructions._vals[v4]._arg1 = size - v4 - 1;
    funcstate->_instructions._vals[v4]._arg2 = 0;
    --i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100448E0
// Name: public: void SQCompiler::ResolveContinues(struct SQFuncState __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQCompiler::ResolveContinues(
        SQFuncState *funcstate@<eax>,
        int ntoresolve@<edx>,
        SQCompiler *this,
        int targetpos)
{
  int v4; // ecx

  for ( ; ntoresolve > 0; funcstate->_instructions._vals[v4]._arg3 = 0 )
  {
    v4 = funcstate->_unresolvedcontinues._vals[--funcstate->_unresolvedcontinues._size];
    funcstate->_instructions._vals[v4]._arg0 = 0;
    funcstate->_instructions._vals[v4]._arg1 = (int)this - v4;
    funcstate->_instructions._vals[v4]._arg2 = 0;
    --ntoresolve;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044930
// Name: bool Compile(struct SQVM __near *,int (*)(void __near *),void __near *,char const __near *,struct SQObjectPtr __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __usercall Compile@<al>(
        const char *raiseerror@<ecx>,
        bool lineinfo@<al>,
        SQVM *vm,
        int (__cdecl *rg)(void *),
        int (__cdecl *up)(void *),
        SQObjectPtr *sourcename)
{
  char v6; // bl
  tagSQObjectValue v7; // eax
  bool v9; // [esp+0h] [ebp-C0h]
  SQCompiler p; // [esp+8h] [ebp-B8h] BYREF

  SQCompiler::SQCompiler(this: &p, up: rg, v: vm, rg: up, sourcename: raiseerror, raiseerror: lineinfo, lineinfo: v9);
  v6 = SQCompiler::Compile(this: (SQCompiler *)sourcename, o: &p, oa: sourcename);
  if ( p._expstates._allocated != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p._expstates._vals);
  p._lex._keywords->Release(this: p._lex._keywords);
  if ( p._lex._longstr._allocated != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p._lex._longstr._vals);
  if ( (p._sourcename._type & 0x8000000) != 0 )
  {
    v7.pTable = (SQTable *)p._sourcename._unVal;
    --*(_DWORD *)(p._sourcename._unVal.nInteger + 4);
    if ( *(int *)(v7.nInteger + 4) <= 0 )
      p._sourcename._unVal.pTable->Release(this: (struct SQTable *)p._sourcename._unVal.nInteger);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100449D0
// Name: public: int __near & sqvector<int>::push_back(int const __near &)
// Source: json
//------------------------------------------------------------------------------
int *__userpurge sqvector<int>::push_back@<eax>(sqvector<int> *this@<ecx>, int a2@<esi>, const int *val)
{
  unsigned int v3; // eax
  int v4; // edi
  void *v5; // eax
  int v6; // ecx
  int *result; // eax

  v3 = *(_DWORD *)(a2 + 4);
  if ( *(_DWORD *)(a2 + 8) <= v3 )
  {
    v4 = 2 * v3;
    if ( 2 * v3 == 0 )
      v4 = 4;
    v5 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: *(_DWORD *)a2, a3: 4 * v4);
    *(_DWORD *)(a2 + 8) = v4;
    *(_DWORD *)a2 = v5;
  }
  v6 = *(_DWORD *)(a2 + 4);
  result = (int *)(*(_DWORD *)a2 + 4 * v6);
  *(_DWORD *)(a2 + 4) = v6 + 1;
  if ( result == nullptr )
    return nullptr;
  *result = *val;
  return result;
}
