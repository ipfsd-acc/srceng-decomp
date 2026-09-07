// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/squirrel/sqdbg/sqrdbg.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10050D00
// Name: _sq_rdbg_init
// Source: json
//------------------------------------------------------------------------------
SQDbgServer *__usercall sq_rdbg_init@<eax>(SQVM *v@<eax>)
{
  void *v2; // eax
  SQDbgServer *v3; // ecx
  SQDbgServer *v4; // esi
  SQDbgServer *v5; // ecx
  SQDbgServer *v7; // ecx
  WSAData wsadata; // [esp+8h] [ebp-1A0h] BYREF
  sockaddr_in bindaddr; // [esp+198h] [ebp-10h] BYREF

  if ( WSAStartup(wVersionRequested: 0x101u, lpWSAData: &wsadata) != 0 )
    return nullptr;
  v2 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 2672);
  if ( v2 != nullptr )
    v4 = SQDbgServer::SQDbgServer(this: v3, a2: (int)v2, v);
  else
    v4 = nullptr;
  v4->_autoupdate = true;
  v4->_accept = socket(af: 2, type: 1, protocol: 0);
  bindaddr.sin_family = 2;
  bindaddr.sin_port = htons(hostshort: 0x4D2u);
  bindaddr.sin_addr.S_un.S_addr = htonl(hostlong: 0);
  if ( bind(s: v4->_accept, name: (const struct sockaddr *)&bindaddr, namelen: 16) == -1 )
  {
    SQDbgServer::~SQDbgServer(this: v5, thisa: v4);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
    sq_throwerror(v, err: "failed to bind the socket");
    return nullptr;
  }
  if ( SQDbgServer::Init(this: v5, thisa: v4) != 0 )
    return v4;
  SQDbgServer::~SQDbgServer(this: v7, thisa: v4);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
  sq_throwerror(v, err: "failed to initialize the debugger");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10050E10
// Name: _sq_rdbg_waitforconnections
// Source: json
//------------------------------------------------------------------------------
int __cdecl sq_rdbg_waitforconnections(int rdbg)
{
  SQDbgServer *v1; // ebx
  unsigned int v2; // kr00_4
  SQVM *v3; // ecx
  _DWORD *v4; // ecx
  int v5; // edx
  int v6; // esi
  tagSQObjectType v7; // edi
  RefTable::RefNode *v8; // eax
  SOCKET v10; // eax
  SOCKET accept; // [esp-8h] [ebp-3Ch]
  SOCKET v12; // [esp-4h] [ebp-38h]
  sockaddr_in cliaddr; // [esp+Ch] [ebp-28h] BYREF
  _DWORD v14[3]; // [esp+1Ch] [ebp-18h] BYREF
  unsigned int mainpos; // [esp+28h] [ebp-Ch] BYREF
  RefTable::RefNode *prev; // [esp+2Ch] [ebp-8h] BYREF

  v1 = (SQDbgServer *)rdbg;
  v2 = strlen(serialize_state_nut);
  v3 = *(SQVM **)(rdbg + 2576);
  v14[2] = v2;
  v14[0] = serialize_state_nut;
  v14[1] = 0;
  if ( sq_compile(v: v3, read: (int (__cdecl *)(void *))v14, p: "SERIALIZE_STATE", sourcename: nullptr) < 0 )
    sq_throwerror(v: v1->_v, err: "error compiling the serialization function");
  v4 = &v1->_v->__vftable;
  v5 = v4[8];
  v6 = v4[14];
  v7 = *(_DWORD *)(v5 + 8 * v6 - 8);
  v1->_serializefunc._type = v7;
  v1->_serializefunc._unVal.nInteger = *(_DWORD *)(v5 + 8 * v6 - 4);
  if ( (v7 & 0x8000000) != 0 )
  {
    v8 = RefTable::Get(this: (RefTable *)(v4[37] + 24), obj: &v1->_serializefunc, &mainpos, &prev, add: true);
    ++v8->refs;
  }
  SQVM::Pop(this: v1->_v, n: 1);
  accept = v1->_accept;
  rdbg = 16;
  if ( listen(s: accept, backlog: 0) == -1 )
    return sq_throwerror(v: v1->_v, err: "error on listen(socket)");
  v10 = ::accept(s: v1->_accept, addr: (struct sockaddr *)&cliaddr, addrlen: &rdbg);
  v12 = v1->_accept;
  v1->_endpoint = v10;
  closesocket(s: v12);
  v1->_accept = -1;
  if ( v1->_endpoint == -1 )
    return sq_throwerror(v: v1->_v, err: "error accept(socket)");
  while ( !v1->_ready )
    sq_rdbg_update(rdbg: v1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10050F70
// Name: _sq_rdbg_update
// Source: json
//------------------------------------------------------------------------------
int __usercall sq_rdbg_update@<eax>(SQDbgServer *rdbg@<eax>)
{
  int v1; // ebx
  unsigned int endpoint; // eax
  unsigned int fd_count; // ecx
  unsigned int v5; // eax
  int i; // eax
  SQVM *v; // edi
  SQSharedState *sharedstate; // ebx
  SQString *v10; // esi
  tagSQObjectType type; // eax
  _DWORD *v12; // ecx
  SQVM *v13; // edi
  SQSharedState *v14; // ebx
  SQString *v15; // esi
  tagSQObjectType v16; // eax
  _DWORD *v17; // ecx
  char temp[1024]; // [esp+10h] [ebp-518h] BYREF
  fd_set read_flags; // [esp+410h] [ebp-118h] BYREF
  timeval time; // [esp+51Ch] [ebp-Ch] BYREF
  char c; // [esp+527h] [ebp-1h] BYREF

  v1 = 0;
  endpoint = rdbg->_endpoint;
  time.tv_sec = 0;
  time.tv_usec = 0;
  read_flags.fd_array[0] = endpoint;
  read_flags.fd_count = 1;
  select(nfds: 0, readfds: &read_flags, writefds: nullptr, exceptfds: nullptr, timeout: &time);
  if ( __WSAFDIsSet(fd: rdbg->_endpoint, a2: &read_flags) == 0 )
    return 0;
  memset(dst: (int)temp, value: nullptr, count: sizeof(temp));
  fd_count = read_flags.fd_count;
  v5 = 0;
  if ( read_flags.fd_count != 0 )
  {
    while ( read_flags.fd_array[v5] != rdbg->_endpoint )
    {
      if ( ++v5 >= read_flags.fd_count )
        goto LABEL_9;
    }
    for ( ; v5 < read_flags.fd_count - 1; ++v5 )
    {
      read_flags.fd_array[v5] = read_flags.fd_array[v5 + 1];
      fd_count = read_flags.fd_count;
    }
    read_flags.fd_count = fd_count - 1;
  }
LABEL_9:
  for ( i = recv(s: rdbg->_endpoint, buf: &c, len: 1, flags: 0);
        i > 0;
        i = recv(s: rdbg->_endpoint, buf: &c, len: 1, flags: 0) )
  {
    if ( c == 10 )
      break;
    if ( c != 13 )
      temp[v1++] = c;
  }
  if ( i != -1 )
  {
    if ( i != 0 )
    {
      temp[v1] = 0;
      temp[v1 + 1] = 0;
      SQDbgServer::ParseMsg(this: (SQDbgServer *)temp, a2: (int)rdbg);
      return 0;
    }
    v = rdbg->_v;
    sharedstate = v->_sharedstate;
    v10 = StringTable::Add(this: sharedstate->_stringtable, news: "disconnected", len: -1);
    v10->_sharedstate = sharedstate;
    ++v10->_uiRef;
    type = v->_lasterror._type;
    v12 = &v->_lasterror._unVal.pTable->__vftable;
    v->_lasterror._unVal.nInteger = (int)v10;
    v->_lasterror._type = OT_STRING;
    ++v10->_uiRef;
    if ( (type & 0x8000000) != 0 && (int)--v12[1] <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*v12 + 8))(a1: v12);
    if ( --v10->_uiRef <= 0 )
      v10->Release(this: v10);
    return -1;
  }
  v13 = rdbg->_v;
  v14 = v13->_sharedstate;
  v15 = StringTable::Add(this: v14->_stringtable, news: "socket error", len: -1);
  v15->_sharedstate = v14;
  ++v15->_uiRef;
  v16 = v13->_lasterror._type;
  v17 = &v13->_lasterror._unVal.pTable->__vftable;
  v13->_lasterror._unVal.nInteger = (int)v15;
  v13->_lasterror._type = OT_STRING;
  ++v15->_uiRef;
  if ( (v16 & 0x8000000) != 0 && (int)--v17[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v17 + 8))(a1: v17);
  if ( --v15->_uiRef > 0 )
    return -1;
  v15->Release(this: v15);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10051190
// Name: int debug_hook(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl debug_hook(SQVM *v)
{
  int stackbase; // eax
  SQObjectPtr *vals; // ecx
  tagSQObjectType type; // edx
  int fFloat; // edx
  bool v5; // zf
  const tagSQObject *v6; // eax
  SQString *v7; // esi
  const char *v8; // eax
  int v9; // eax
  SQObjectPtr *v10; // ecx
  tagSQObjectType v11; // edx
  int nInteger; // edx
  const tagSQObject *v13; // eax
  SQString *v14; // esi
  const char *v15; // eax
  SQDbgServer *v16; // edi
  const char *v18; // [esp+0h] [ebp-20h]
  const char *v19; // [esp+4h] [ebp-1Ch]
  int line; // [esp+10h] [ebp-10h]
  SQDbgServer *event_type; // [esp+14h] [ebp-Ch]
  const char *src; // [esp+18h] [ebp-8h]
  void *up; // [esp+1Ch] [ebp-4h] BYREF

  stackbase = v->_stackbase;
  vals = v->_stack._vals;
  type = vals[stackbase + 1]._type;
  if ( (type & 0x4000000) != 0 )
  {
    if ( type == OT_FLOAT )
      fFloat = (int)vals[stackbase + 1]._unVal.fFloat;
    else
      fFloat = vals[stackbase + 1]._unVal.nInteger;
    event_type = (SQDbgServer *)fFloat;
  }
  v5 = vals[stackbase + 2]._type == OT_STRING;
  v6 = &vals[stackbase + 2];
  if ( v5 )
  {
    src = (const char *)(v6->_unVal.nInteger + 28);
  }
  else
  {
    v7 = SQVM::PrintObjVal(this: (SQVM *)vals, o: v, oa: v6);
    ++v7->_uiRef;
    v8 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(a1: v, this: (SQVM *)&stru_1009BB84, s: v8, v7->_val);
    if ( --v7->_uiRef <= 0 )
      v7->Release(this: v7);
  }
  v9 = v->_stackbase;
  v10 = v->_stack._vals;
  v11 = v10[v9 + 3]._type;
  if ( (v11 & 0x4000000) != 0 )
  {
    if ( v11 == OT_FLOAT )
      nInteger = (int)v10[v9 + 3]._unVal.fFloat;
    else
      nInteger = v10[v9 + 3]._unVal.nInteger;
    line = nInteger;
  }
  v5 = v10[v9 + 4]._type == OT_STRING;
  v13 = &v10[v9 + 4];
  if ( !v5 )
  {
    v14 = SQVM::PrintObjVal(this: (SQVM *)v10, o: v, oa: v13);
    ++v14->_uiRef;
    v15 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(a1: v, this: (SQVM *)&stru_1009BB84, s: v15, v14->_val);
    if ( --v14->_uiRef <= 0 )
      v14->Release(this: v14);
  }
  sq_getuserpointer((const tagSQObject *)v, idx: &up);
  v16 = (SQDbgServer *)up;
  SQDbgServer::Hook(this: event_type, a2: (int)up, type: line, line: src, src: v18, func: v19);
  if ( v16->_autoupdate && sq_rdbg_update(rdbg: v16) < 0 )
    return sq_throwerror(v, err: "socket failed");
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100512F0
// Name: int error_handler(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl error_handler(SQVM *v)
{
  const char *funcname; // esi
  const char *source; // ebx
  int stackbase; // eax
  int v4; // ecx
  SQObjectPtr *vals; // edx
  bool v6; // zf
  const tagSQObject *v7; // eax
  SQString *v8; // esi
  const char *v9; // eax
  SQDbgServer *v10; // ecx
  const char *v12; // esi
  void *up; // [esp+10h] [ebp-10h] BYREF
  tagSQStackInfos v14; // [esp+14h] [ebp-Ch] BYREF

  funcname = "unknown";
  source = "unknown";
  sq_getuserpointer((const tagSQObject *)v, idx: &up);
  if ( sq_stackinfos(level: 1, v, si: &v14) >= 0 )
  {
    if ( v14.funcname != nullptr )
      funcname = v14.funcname;
    if ( v14.source != nullptr )
      source = v14.source;
    DevMsg(a1: "*FUNCTION [%s] %s line [%d]\n", funcname, source, v14.line);
  }
  stackbase = v->_stackbase;
  v4 = v->_top - stackbase;
  if ( v4 >= 1 )
  {
    vals = v->_stack._vals;
    v6 = vals[stackbase + 1]._type == OT_STRING;
    v7 = &vals[stackbase + 1];
    if ( v6 )
    {
      v12 = (const char *)(v7->_unVal.nInteger + 28);
      DevMsg(a1: "\nAN ERROR HAS OCCURED [%s]\n", v12);
      SQDbgServer::Break(
        this: (SQDbgServer *)up,
        type: "error",
        a3: (SQDbgServer *)v14.line,
        line: v14.line,
        src: source,
        error: v12);
    }
    else
    {
      v8 = SQVM::PrintObjVal(this: (SQVM *)v4, o: v, oa: v7);
      ++v8->_uiRef;
      v9 = IdType2Name(type: OT_STRING);
      SQVM::Raise_Error(a1: v, this: (SQVM *)&stru_1009BB84, s: v9, v8->_val);
      if ( --v8->_uiRef <= 0 )
        v8->Release(this: v8);
      DevMsg(a1: "\nAN ERROR HAS OCCURED [unknown]\n");
      SQDbgServer::Break(this: (SQDbgServer *)up, type: "error", a3: v10, line: v14.line, src: source, error: "unknown");
    }
  }
  SQDbgServer::BreakExecution(this: (SQDbgServer *)v4, a2: up);
  return 0;
}
