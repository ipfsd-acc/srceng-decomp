// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/squirrel/sqdbg/sqdbgserver.cpp
// Functions: 48
// ============================================================

#include "vscript\languages\squirrel\sqdbg\sqdbgserver.h"

//------------------------------------------------------------------------------
// Address: 0x10044A70
// Name: bool dbg_less(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __usercall dbg_less@<al>(const char *y@<eax>, const char *x)
{
  const char *v2; // esi
  int v3; // ebx
  char v4; // al
  unsigned int v5; // edi
  unsigned int v6; // eax
  signed int v7; // edi

  v2 = y;
  v3 = x - y;
  while ( 1 )
  {
    v4 = v2[v3];
    v5 = v4 == 92 ? 47 : tolower(c: v4);
    v6 = *v2 == 92 ? 47 : tolower(c: *v2);
    v7 = v5 - v6;
    if ( v7 != 0 )
      break;
    ++v2;
    if ( v2[v3] == 0 || *v2 == 0 )
      return false;
  }
  return v7 > 0;
}

//------------------------------------------------------------------------------
// Address: 0x10044AE0
// Name: int beginelement(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl beginelement(SQVM *v)
{
  const char *v1; // ebx
  SQVM *v2; // ecx
  SQString *v3; // esi
  const char *v4; // eax
  void *up; // [esp+Ch] [ebp-4h] BYREF

  sq_getuserpointer((const tagSQObject *)v, idx: &up);
  v1 = (const char *)up;
  sq_getuserpointer((const tagSQObject *)v, idx: &up);
  if ( v->_stack._vals[v->_stackbase + 1]._type != OT_STRING )
  {
    v3 = SQVM::PrintObjVal(this: v2, o: (const tagSQObject *)v);
    ++v3->_uiRef;
    v4 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v4, v3->_val);
    if ( --v3->_uiRef <= 0 )
      v3->Release(this: v3);
  }
  SQDbgServer::BeginElement(this: (SQDbgServer *)v2, name: v1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10044B90
// Name: int endelement(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl endelement(SQVM *v)
{
  SQDbgServer *v1; // ecx
  int stackbase; // edx
  SQString *v3; // esi
  const char *v4; // eax
  SQDbgServer *v5; // ecx
  void *up; // [esp+Ch] [ebp-4h] BYREF

  sq_getuserpointer((const tagSQObject *)v, idx: &up);
  sq_getuserpointer((const tagSQObject *)v, idx: &up);
  stackbase = v->_stackbase;
  if ( v->_stack._vals[stackbase + 1]._type == OT_STRING )
  {
    SQDbgServer::EndElement(this: v1, name: (const char *)(v->_stack._vals[stackbase + 1]._unVal.nInteger + 28));
    return 0;
  }
  else
  {
    v3 = SQVM::PrintObjVal(this: (SQVM *)v1, o: (const tagSQObject *)v);
    ++v3->_uiRef;
    v4 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v4, v3->_val);
    if ( --v3->_uiRef <= 0 )
      v3->Release(this: v3);
    SQDbgServer::EndElement(this: v5, name: (const char *)up);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044C40
// Name: int attribute(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl attribute(SQVM *v)
{
  SQObjectPtr *vals; // ecx
  SQString *v2; // esi
  const char *v3; // eax
  int stackbase; // eax
  SQObjectPtr *v5; // ecx
  bool v6; // zf
  int v7; // eax
  SQString *v8; // esi
  const char *v9; // eax
  const char *v10; // eax
  const char *value; // [esp+8h] [ebp-8h] BYREF
  SQDbgServer *self; // [esp+Ch] [ebp-4h]

  sq_getuserpointer((const tagSQObject *)v, idx: (void **)&value);
  self = (SQDbgServer *)value;
  sq_getuserpointer((const tagSQObject *)v, idx: (void **)&value);
  vals = v->_stack._vals;
  if ( vals[v->_stackbase + 1]._type == OT_STRING )
  {
    value = (const char *)(vals[v->_stackbase + 1]._unVal.nInteger + 28);
  }
  else
  {
    v2 = SQVM::PrintObjVal(this: (SQVM *)vals, o: (const tagSQObject *)v);
    ++v2->_uiRef;
    v3 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v3, v2->_val);
    if ( --v2->_uiRef <= 0 )
      v2->Release(this: v2);
  }
  stackbase = v->_stackbase;
  v5 = v->_stack._vals;
  v6 = v5[stackbase + 2]._type == OT_STRING;
  v7 = (int)&v5[stackbase + 2];
  if ( v6 )
  {
    v10 = (const char *)(*(_DWORD *)(v7 + 4) + 28);
  }
  else
  {
    v8 = SQVM::PrintObjVal(this: (SQVM *)v5, o: (const tagSQObject *)v);
    ++v8->_uiRef;
    v9 = IdType2Name(type: OT_STRING);
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84, s: v9, v8->_val);
    if ( --v8->_uiRef <= 0 )
      v8->Release(this: v8);
    v10 = value;
  }
  SQDbgServer::Attribute(this: self, name: value, value: v10);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10044D40
// Name: public: SQDbgServer::SQDbgServer(struct SQVM __near *)
// Source: json
//------------------------------------------------------------------------------
SQDbgServer *__userpurge SQDbgServer::SQDbgServer@<eax>(SQDbgServer *this@<ecx>, int a2@<esi>, SQVM *v)
{
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  SQVM *v5; // eax
  std::exception pExceptionObject; // [esp+4h] [ebp-Ch] BYREF

  *(_DWORD *)(a2 + 2608) = 0;
  v3 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 48);
  if ( v3 == nullptr )
  {
    v = nullptr;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&v);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  *(_DWORD *)(a2 + 2604) = v3;
  *v3 = v3;
  *(_DWORD *)(*(_DWORD *)(a2 + 2604) + 4) = *(_DWORD *)(a2 + 2604);
  *(_DWORD *)(*(_DWORD *)(a2 + 2604) + 8) = *(_DWORD *)(a2 + 2604);
  *(_BYTE *)(*(_DWORD *)(a2 + 2604) + 44) = 1;
  *(_BYTE *)(*(_DWORD *)(a2 + 2604) + 45) = 1;
  *(_DWORD *)(a2 + 2624) = 0;
  v4 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 48);
  if ( v4 == nullptr )
  {
    v = nullptr;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&v);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  *(_DWORD *)(a2 + 2620) = v4;
  *v4 = v4;
  *(_DWORD *)(*(_DWORD *)(a2 + 2620) + 4) = *(_DWORD *)(a2 + 2620);
  *(_DWORD *)(*(_DWORD *)(a2 + 2620) + 8) = *(_DWORD *)(a2 + 2620);
  v5 = v;
  *(_BYTE *)(*(_DWORD *)(a2 + 2620) + 44) = 1;
  *(_BYTE *)(*(_DWORD *)(a2 + 2620) + 45) = 1;
  *(_DWORD *)(a2 + 2656) = 0;
  *(_DWORD *)(a2 + 2660) = 0;
  *(_DWORD *)(a2 + 2664) = 0;
  *(_DWORD *)(a2 + 2576) = v5;
  *(_DWORD *)(a2 + 2592) = -1;
  *(_DWORD *)(a2 + 2596) = -1;
  *(_DWORD *)(a2 + 2640) = 0;
  *(_WORD *)(a2 + 2644) = 0;
  *(_DWORD *)(a2 + 2588) = 0;
  *(_DWORD *)(a2 + 2636) = 10;
  *(_DWORD *)(a2 + 2584) = 0;
  *(_DWORD *)(a2 + 2580) = 16777217;
  *(_DWORD *)(a2 + 2652) = 0;
  *(_DWORD *)(a2 + 2648) = 16777217;
  return (SQDbgServer *)a2;
}

//------------------------------------------------------------------------------
// Address: 0x10044EA0
// Name: public: SQDbgServer::~SQDbgServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQDbgServer::~SQDbgServer(SQDbgServer *this, SQDbgServer *thisa)
{
  SQVM *v; // eax
  int top; // ecx
  SQObjectPtr *vals; // eax
  tagSQObjectType type; // edx
  tagSQObjectType *p_type; // eax
  _DWORD *v7; // ecx
  tagSQObjectType v8; // esi
  SQVM *v9; // eax
  int v10; // ecx
  SQObjectPtr *v11; // eax
  tagSQObjectType v12; // edx
  tagSQObjectType *v13; // eax
  _DWORD *v14; // ecx
  tagSQObjectType v15; // esi
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > v16; // [esp+0h] [ebp-10h]
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > v17; // [esp+0h] [ebp-10h]

  v = thisa->_v;
  top = v->_top;
  v->_top = top + 1;
  vals = v->_stack._vals;
  type = vals[top]._type;
  p_type = &vals[top]._type;
  v7 = *((_DWORD **)p_type + 1);
  p_type[1] = (tagSQObjectType)_null_._unVal.pTable;
  v8 = _null_._type;
  *p_type = _null_._type;
  if ( (v8 & 0x8000000) != 0 )
    ++*(_DWORD *)(*((_DWORD *)p_type + 1) + 4);
  if ( (type & 0x8000000) != 0 && (int)--v7[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v7 + 8))(a1: v7);
  sq_setdebughook(v: thisa->_v);
  v9 = thisa->_v;
  v10 = v9->_top;
  v9->_top = v10 + 1;
  v11 = v9->_stack._vals;
  v12 = v11[v10]._type;
  v13 = &v11[v10]._type;
  v14 = *((_DWORD **)v13 + 1);
  v13[1] = (tagSQObjectType)_null_._unVal.pTable;
  v15 = _null_._type;
  *v13 = _null_._type;
  if ( (v15 & 0x8000000) != 0 )
    ++*(_DWORD *)(*((_DWORD *)v13 + 1) + 4);
  if ( (v12 & 0x8000000) != 0 && (int)--v14[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v14 + 8))(a1: v14);
  sq_seterrorhandler(v: thisa->_v);
  if ( (thisa->_debugroot._type & 0x8000000) != 0 )
    RefTable::Release(this: (RefTable *)thisa->_v, obj: &thisa->_debugroot);
  if ( thisa->_accept != -1 )
    closesocket(s: thisa->_accept);
  if ( thisa->_endpoint != -1 )
    closesocket(s: thisa->_endpoint);
  if ( thisa->_scratchstring._Myfirst != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: thisa->_scratchstring._Myfirst);
  thisa->_scratchstring._Myfirst = nullptr;
  thisa->_scratchstring._Mylast = nullptr;
  thisa->_scratchstring._Myend = nullptr;
  std::_Tree<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::erase(
    this: (std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)thisa->_watches._Myhead->_Left,
    result: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *)thisa->_watches._Myhead->_Left,
    _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > >)thisa->_watches._Myhead,
    _Last: v16);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: thisa->_watches._Myhead);
  std::_Tree<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::erase(
    this: (std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)thisa->_breakpoints._Myhead->_Left,
    result: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *)thisa->_breakpoints._Myhead->_Left,
    _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > >)thisa->_breakpoints._Myhead,
    _Last: v17);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: thisa->_breakpoints._Myhead);
}

//------------------------------------------------------------------------------
// Address: 0x10045040
// Name: public: bool SQDbgServer::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SQDbgServer::Init(SQDbgServer *this, SQDbgServer *thisa)
{
  SQDbgServer *v2; // ebx
  _DWORD *v3; // ecx
  int v4; // edx
  int v5; // esi
  tagSQObjectType v6; // edi
  RefTable::RefNode *v7; // eax
  SQVM *v; // eax
  int top; // ecx
  SQObjectPtr *vals; // eax
  tagSQObjectType type; // edx
  tagSQObjectType *p_type; // eax
  _DWORD *v13; // ecx
  tagSQObjectType v14; // esi
  SQVM *v15; // edi
  int v16; // eax
  SQVM *v17; // ecx
  int v18; // esi
  SQVM *v19; // eax
  int v20; // ecx
  SQObjectPtr *v21; // eax
  tagSQObjectType v22; // edx
  SQObjectPtr *v23; // eax
  _DWORD *v24; // ecx
  SQVM *v25; // edi
  int v26; // eax
  SQVM *v27; // ecx
  int v28; // esi
  SQVM *v29; // eax
  int v30; // ecx
  SQObjectPtr *v31; // eax
  tagSQObjectType v32; // edx
  SQObjectPtr *v33; // eax
  _DWORD *v34; // ecx
  SQVM *v35; // edi
  int v36; // eax
  SQVM *v37; // ecx
  int v38; // esi
  SQVM *v39; // eax
  int v40; // ecx
  SQObjectPtr *v41; // eax
  tagSQObjectType v42; // edx
  SQObjectPtr *v43; // eax
  _DWORD *v44; // ecx
  SQVM *v45; // edi
  int v46; // eax
  SQVM *v47; // ecx
  int v48; // esi
  _DWORD *v49; // eax
  int v50; // ecx
  int v51; // edx
  int v52; // eax
  int v53; // edi
  int v54; // esi
  _DWORD *v55; // eax
  _DWORD *v56; // ecx
  int v57; // edx
  SQVM *v58; // eax
  int v59; // ecx
  SQObjectPtr *v60; // eax
  tagSQObjectType v61; // edx
  SQObjectPtr *v62; // eax
  _DWORD *v63; // ecx
  SQVM *v64; // edi
  int v65; // eax
  SQVM *v66; // ecx
  int v67; // esi
  SQVM *v68; // eax
  int v69; // ecx
  SQObjectPtr *v70; // eax
  tagSQObjectType v71; // edx
  SQObjectPtr *v72; // eax
  _DWORD *v73; // ecx
  SQVM *v74; // edi
  int v75; // eax
  SQVM *v76; // ecx
  int v77; // esi
  SQDbgServer *v78; // ecx
  const char *v80; // [esp+0h] [ebp-14h]
  unsigned int mainpos; // [esp+10h] [ebp-4h] BYREF

  v2 = thisa;
  sq_newtable(v: thisa->_v);
  v3 = &v2->_v->__vftable;
  v4 = v3[8];
  v5 = v3[14];
  v6 = *(_DWORD *)(v4 + 8 * v5 - 8);
  v2->_debugroot._type = v6;
  v2->_debugroot._unVal.nInteger = *(_DWORD *)(v4 + 8 * v5 - 4);
  if ( (v6 & 0x8000000) != 0 )
  {
    v7 = RefTable::Get(
           this: (RefTable *)(v3[37] + 24),
           obj: &v2->_debugroot,
           &mainpos,
           prev: (RefTable::RefNode **)&thisa,
           add: true);
    ++v7->refs;
  }
  sq_pushstring(v: v2->_v, s: "watches", len: -1);
  v = v2->_v;
  top = v->_top;
  v->_top = top + 1;
  vals = v->_stack._vals;
  type = vals[top]._type;
  p_type = &vals[top]._type;
  v13 = *((_DWORD **)p_type + 1);
  p_type[1] = (tagSQObjectType)_null_._unVal.pTable;
  v14 = _null_._type;
  *p_type = _null_._type;
  if ( (v14 & 0x8000000) != 0 )
    ++*(_DWORD *)(*((_DWORD *)p_type + 1) + 4);
  if ( (type & 0x8000000) != 0 && (int)--v13[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v13 + 8))(a1: v13);
  v15 = v2->_v;
  v16 = v15->_top;
  if ( v16 - v15->_stackbase >= 3 )
  {
    v17 = (SQVM *)v15->_stack._vals;
    v18 = *((_DWORD *)v17 + 2 * v16 - 6);
    if ( v18 == 167772192 || v18 == 134234112 )
    {
      if ( *((_DWORD *)v17 + 2 * v16 - 4) == 16777217 )
      {
        sq_throwerror(v: v15, err: "null is not a valid key");
      }
      else
      {
        SQVM::NewSlot(
          this: v17,
          self: (const SQObjectPtr *)v17 + v16 - 3,
          key: (const SQObjectPtr *)v17 + v16 - 2,
          val: (const SQObjectPtr *)v17 + v16 - 1,
          bstatic: false);
        SQVM::Pop(this: v15, n: 2);
      }
    }
  }
  else
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v80);
  }
  sq_pushstring(v: v2->_v, s: "beginelement", len: -1);
  v19 = v2->_v;
  v20 = v19->_top;
  v19->_top = v20 + 1;
  v21 = v19->_stack._vals;
  v22 = v21[v20]._type;
  v23 = &v21[v20];
  v24 = &v23->_unVal.pTable->__vftable;
  v23->_unVal.nInteger = (int)v2;
  v23->_type = OT_USERPOINTER;
  if ( (v22 & 0x8000000) != 0 && (int)--v24[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v24 + 8))(a1: v24);
  sq_newclosure(v: v2->_v, func: beginelement, nfreevars: 1u);
  sq_setparamscheck(v: v2->_v, typemask: ".s", nparamscheck: 2);
  v25 = v2->_v;
  v26 = v25->_top;
  if ( v26 - v25->_stackbase >= 3 )
  {
    v27 = (SQVM *)v25->_stack._vals;
    v28 = *((_DWORD *)v27 + 2 * v26 - 6);
    if ( v28 == 167772192 || v28 == 134234112 )
    {
      if ( *((_DWORD *)v27 + 2 * v26 - 4) == 16777217 )
      {
        sq_throwerror(v: v25, err: "null is not a valid key");
      }
      else
      {
        SQVM::NewSlot(
          this: v27,
          self: (const SQObjectPtr *)v27 + v26 - 3,
          key: (const SQObjectPtr *)v27 + v26 - 2,
          val: (const SQObjectPtr *)v27 + v26 - 1,
          bstatic: false);
        SQVM::Pop(this: v25, n: 2);
      }
    }
  }
  else
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v80);
  }
  sq_pushstring(v: v2->_v, s: "endelement", len: -1);
  v29 = v2->_v;
  v30 = v29->_top;
  v29->_top = v30 + 1;
  v31 = v29->_stack._vals;
  v32 = v31[v30]._type;
  v33 = &v31[v30];
  v34 = &v33->_unVal.pTable->__vftable;
  v33->_unVal.nInteger = (int)v2;
  v33->_type = OT_USERPOINTER;
  if ( (v32 & 0x8000000) != 0 && (int)--v34[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v34 + 8))(a1: v34);
  sq_newclosure(v: v2->_v, func: endelement, nfreevars: 1u);
  sq_setparamscheck(v: v2->_v, typemask: ".s", nparamscheck: 2);
  v35 = v2->_v;
  v36 = v35->_top;
  if ( v36 - v35->_stackbase >= 3 )
  {
    v37 = (SQVM *)v35->_stack._vals;
    v38 = *((_DWORD *)v37 + 2 * v36 - 6);
    if ( v38 == 167772192 || v38 == 134234112 )
    {
      if ( *((_DWORD *)v37 + 2 * v36 - 4) == 16777217 )
      {
        sq_throwerror(v: v35, err: "null is not a valid key");
      }
      else
      {
        SQVM::NewSlot(
          this: v37,
          self: (const SQObjectPtr *)v37 + v36 - 3,
          key: (const SQObjectPtr *)v37 + v36 - 2,
          val: (const SQObjectPtr *)v37 + v36 - 1,
          bstatic: false);
        SQVM::Pop(this: v35, n: 2);
      }
    }
  }
  else
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v80);
  }
  sq_pushstring(v: v2->_v, s: "attribute", len: -1);
  v39 = v2->_v;
  v40 = v39->_top;
  v39->_top = v40 + 1;
  v41 = v39->_stack._vals;
  v42 = v41[v40]._type;
  v43 = &v41[v40];
  v44 = &v43->_unVal.pTable->__vftable;
  v43->_unVal.nInteger = (int)v2;
  v43->_type = OT_USERPOINTER;
  if ( (v42 & 0x8000000) != 0 && (int)--v44[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v44 + 8))(a1: v44);
  sq_newclosure(v: v2->_v, func: attribute, nfreevars: 1u);
  sq_setparamscheck(v: v2->_v, typemask: ".ss", nparamscheck: 3);
  v45 = v2->_v;
  v46 = v45->_top;
  if ( v46 - v45->_stackbase >= 3 )
  {
    v47 = (SQVM *)v45->_stack._vals;
    v48 = *((_DWORD *)v47 + 2 * v46 - 6);
    if ( v48 == 167772192 || v48 == 134234112 )
    {
      if ( *((_DWORD *)v47 + 2 * v46 - 4) == 16777217 )
      {
        sq_throwerror(v: v45, err: "null is not a valid key");
      }
      else
      {
        SQVM::NewSlot(
          this: v47,
          self: (const SQObjectPtr *)v47 + v46 - 3,
          key: (const SQObjectPtr *)v47 + v46 - 2,
          val: (const SQObjectPtr *)v47 + v46 - 1,
          bstatic: false);
        SQVM::Pop(this: v45, n: 2);
      }
    }
  }
  else
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v80);
  }
  SQVM::Pop(this: v2->_v, n: 1);
  v49 = &v2->_v->__vftable;
  v50 = v49[14];
  v51 = v49[37];
  v49[14] = v50 + 1;
  v52 = v49[8];
  v53 = *(_DWORD *)(v51 + 48);
  v54 = *(_DWORD *)(v52 + 8 * v50);
  v55 = (_DWORD *)(v52 + 8 * v50);
  v56 = (_DWORD *)v55[1];
  v55[1] = v53;
  v57 = *(_DWORD *)(v51 + 44);
  *v55 = v57;
  if ( (v57 & 0x8000000) != 0 )
    ++*(_DWORD *)(v53 + 4);
  if ( (v54 & 0x8000000) != 0 && (int)--v56[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v56 + 8))(a1: v56);
  sq_pushstring(v: v2->_v, s: "_sqdbg_debug_hook_", len: -1);
  v58 = v2->_v;
  v59 = v58->_top;
  v58->_top = v59 + 1;
  v60 = v58->_stack._vals;
  v61 = v60[v59]._type;
  v62 = &v60[v59];
  v63 = &v62->_unVal.pTable->__vftable;
  v62->_unVal.nInteger = (int)v2;
  v62->_type = OT_USERPOINTER;
  if ( (v61 & 0x8000000) != 0 && (int)--v63[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v63 + 8))(a1: v63);
  sq_newclosure(v: v2->_v, func: debug_hook, nfreevars: 1u);
  v64 = v2->_v;
  v65 = v64->_top;
  if ( v65 - v64->_stackbase >= 3 )
  {
    v66 = (SQVM *)v64->_stack._vals;
    v67 = *((_DWORD *)v66 + 2 * v65 - 6);
    if ( v67 == 167772192 || v67 == 134234112 )
    {
      if ( *((_DWORD *)v66 + 2 * v65 - 4) == 16777217 )
      {
        sq_throwerror(v: v64, err: "null is not a valid key");
      }
      else
      {
        SQVM::NewSlot(
          this: v66,
          self: (const SQObjectPtr *)v66 + v65 - 3,
          key: (const SQObjectPtr *)v66 + v65 - 2,
          val: (const SQObjectPtr *)v66 + v65 - 1,
          bstatic: false);
        SQVM::Pop(this: v64, n: 2);
      }
    }
  }
  else
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v80);
  }
  sq_pushstring(v: v2->_v, s: "_sqdbg_error_handler_", len: -1);
  v68 = v2->_v;
  v69 = v68->_top;
  v68->_top = v69 + 1;
  v70 = v68->_stack._vals;
  v71 = v70[v69]._type;
  v72 = &v70[v69];
  v73 = &v72->_unVal.pTable->__vftable;
  v72->_unVal.nInteger = (int)v2;
  v72->_type = OT_USERPOINTER;
  if ( (v71 & 0x8000000) != 0 && (int)--v73[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v73 + 8))(a1: v73);
  sq_newclosure(v: v2->_v, func: error_handler, nfreevars: 1u);
  v74 = v2->_v;
  v75 = v74->_top;
  if ( v75 - v74->_stackbase >= 3 )
  {
    v76 = (SQVM *)v74->_stack._vals;
    v77 = *((_DWORD *)v76 + 2 * v75 - 6);
    if ( v77 == 167772192 || v77 == 134234112 )
    {
      if ( *((_DWORD *)v76 + 2 * v75 - 4) == 16777217 )
      {
        sq_throwerror(v: v74, err: "null is not a valid key");
      }
      else
      {
        SQVM::NewSlot(
          this: v76,
          self: (const SQObjectPtr *)v76 + v75 - 3,
          key: (const SQObjectPtr *)v76 + v75 - 2,
          val: (const SQObjectPtr *)v76 + v75 - 1,
          bstatic: false);
        SQVM::Pop(this: v74, n: 2);
      }
    }
  }
  else
  {
    SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v80);
  }
  SQVM::Pop(this: v2->_v, n: 1);
  SQDbgServer::SetErrorHandlers(this: v78);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10045680
// Name: public: void SQDbgServer::Hook(int,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQDbgServer::Hook(
        SQDbgServer *this@<ecx>,
        int a2@<edi>,
        int type,
        const char *line,
        const char *src,
        const char *func)
{
  BreakPoint *v6; // ecx
  SQDbgServer *v7; // ecx
  int v8; // eax
  SQDbgServer *v9; // ecx
  BreakPoint _Keyval; // [esp+8h] [ebp-20h] BYREF

  switch ( *(_DWORD *)(a2 + 2588) )
  {
    case 0:
      if ( this == (SQDbgServer *)108 && *(_DWORD *)(a2 + 2608) != 0 )
      {
        _Keyval._line = type;
        _Keyval._src._Myres = 15;
        _Keyval._src._Mysize = 0;
        _Keyval._src._Bx._Buf[0] = 0;
        std::string::assign(this: &_Keyval._src, _Ptr: line, _Count: strlen(line));
        std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0>>::find(
          this: (std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)(a2 + 2600),
          &_Keyval);
        BreakPoint::~BreakPoint(this: v6);
        if ( line != *(const char **)(a2 + 2604) )
        {
          SQDbgServer::Break(this: (SQDbgServer *)a2, line: type, src: line, type: "breakpoint", error: nullptr);
          SQDbgServer::BreakExecution(this: v7);
        }
      }
      return;
    case 1:
      goto $LN22_12;
    case 2:
      if ( this != (SQDbgServer *)108 )
        return;
      *(_DWORD *)(a2 + 2640) = 0;
      SQDbgServer::Break(this: (SQDbgServer *)a2, line: type, src: line, type: "step", error: nullptr);
      goto LABEL_16;
    case 3:
      if ( this == (SQDbgServer *)99 )
        goto LABEL_22;
      if ( this != (SQDbgServer *)114 )
        return;
      v8 = *(_DWORD *)(a2 + 2640);
      if ( v8 != 0 )
        goto LABEL_21;
      *(_DWORD *)(a2 + 2640) = 0;
      *(_DWORD *)(a2 + 2588) = 1;
      break;
    case 4:
      *(_DWORD *)(a2 + 2640) = 0;
$LN22_12:
      if ( this == (SQDbgServer *)99 )
      {
LABEL_22:
        ++*(_DWORD *)(a2 + 2640);
      }
      else if ( this == (SQDbgServer *)108 )
      {
        if ( *(_DWORD *)(a2 + 2640) == 0 )
        {
          SQDbgServer::Break(this: (SQDbgServer *)a2, line: type, src: line, type: "step", error: nullptr);
LABEL_16:
          SQDbgServer::BreakExecution(this: v9);
        }
      }
      else if ( this == (SQDbgServer *)114 )
      {
        v8 = *(_DWORD *)(a2 + 2640);
        if ( v8 != 0 )
LABEL_21:
          *(_DWORD *)(a2 + 2640) = v8 - 1;
        else
          *(_DWORD *)(a2 + 2640) = 0;
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045810
// Name: public: BreakPoint::~BreakPoint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall BreakPoint::~BreakPoint(BreakPoint *this@<ecx>, int a2@<esi>)
{
  if ( *(_DWORD *)(a2 + 24) >= 0x10u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(a2 + 4));
  *(_DWORD *)(a2 + 24) = 15;
  *(_DWORD *)(a2 + 20) = 0;
  *(_BYTE *)(a2 + 4) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10045840
// Name: public: void SQDbgServer::ParseMsg(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQDbgServer::ParseMsg(SQDbgServer *this@<ecx>, int a2@<eax>)
{
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  SQDbgServer *v6; // ecx
  std::string *p_exp; // eax
  BreakPoint *v8; // ecx
  BreakPoint *v9; // ecx
  SQDbgServer *v10; // ecx
  std::string *v11; // eax
  BreakPoint *v12; // ecx
  SQDbgServer *v13; // ecx
  SQDbgServer *v14; // ecx
  unsigned int v15; // eax
  char *v16; // edi
  int v17; // eax
  SQDbgServer *v18; // ecx
  int v19; // ebx
  std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *v20; // esi
  std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *v21; // eax
  std::_Tree<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> > *v22; // ecx
  std::string *Ptr; // eax
  Watch *v24; // [esp+0h] [ebp-38h]
  bool v25; // [esp+0h] [ebp-38h]
  Watch w; // [esp+10h] [ebp-28h] BYREF
  char *endptr; // [esp+34h] [ebp-4h] BYREF

  v3 = *(unsigned __int16 *)this->xmlstate[0].name;
  if ( v3 > 0x6F73 )
  {
    if ( *(unsigned __int16 *)this->xmlstate[0].name > 0x7274u )
    {
      v15 = v3 - 30561;
      if ( v15 == 0 )
      {
        w._exp._Mysize = 0;
        w._exp._Bx._Buf[0] = 0;
        w._id = 0;
        w._exp._Myres = 15;
        if ( SQDbgServer::ParseWatch(this: (SQDbgServer *)&w, msg: &this->xmlstate[0].name[3], out: v24) )
        {
          v20 = (std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)(a2 + 2616);
          v21 = (std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *)std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::_Buynode<Watch &>(this: v20, _Val: (BreakPoint *)&w);
          std::_Tree<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::_Linsert(
            this: v22,
            result: (std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> > >,bool> *)v20,
            _Node: v21,
            _Leftish: v25);
          Ptr = (std::string *)w._exp._Bx._Ptr;
          if ( w._exp._Myres < 0x10 )
            Ptr = &w._exp;
          DevMsg(a1: "added watch %d %s\n", w._id, Ptr->_Bx._Buf);
        }
        else
        {
          DevMsg(a1: "error parsing add watch");
        }
        if ( w._exp._Myres >= 0x10 )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: w._exp._Bx._Ptr);
        return;
      }
      if ( v15 == 17 )
      {
        v16 = &this->xmlstate[0].name[3];
        endptr = nullptr;
        v17 = strtoul(nptr: &this->xmlstate[0].name[3], &endptr, ibase: 16);
        v19 = v17;
        if ( endptr == v16 )
        {
          DevMsg(a1: "error parsing remove watch");
        }
        else
        {
          SQDbgServer::RemoveWatch(this: v18, id: v17);
          DevMsg(a1: "added watch %d\n", v19);
        }
        return;
      }
    }
    else
    {
      switch ( v3 )
      {
        case 0x7274u:
          DevMsg(a1: "terminate from user\n");
          closesocket(s: *(_DWORD *)(a2 + 2596));
          *(_DWORD *)(a2 + 2596) = -1;
          return;
        case 0x7073u:
          if ( *(_DWORD *)(a2 + 2588) != 4 )
          {
            *(_DWORD *)(a2 + 2588) = 4;
            DevMsg(a1: "suspend\n");
          }
          return;
        case 0x7273u:
          if ( *(_DWORD *)(a2 + 2588) == 4 )
          {
            *(_DWORD *)(a2 + 2588) = 3;
            DevMsg(a1: "step return\n");
          }
          return;
        default:
          break;
      }
    }
LABEL_41:
    DevMsg(a1: "unknown packet");
    return;
  }
  if ( v3 == 28531 )
  {
    if ( *(_DWORD *)(a2 + 2588) == 4 )
      *(_DWORD *)(a2 + 2588) = 1;
    return;
  }
  if ( *(unsigned __int16 *)this->xmlstate[0].name > 0x6964u )
  {
    if ( v3 == 26995 )
    {
      if ( *(_DWORD *)(a2 + 2588) == 4 )
      {
        *(_DWORD *)(a2 + 2588) = 2;
        DevMsg(a1: "step into\n");
      }
      return;
    }
    if ( v3 == 28519 )
    {
      if ( *(_DWORD *)(a2 + 2588) != 0 )
      {
        *(_DWORD *)(a2 + 2588) = 0;
        *(_DWORD *)(a2 + 2572) = -1;
        SQDbgServer::BeginElement(this, name: (const char *)a2);
        SQDbgServer::EndElement(this: v13, name: "resumed");
        SQDbgServer::EndDocument(this: v14);
        DevMsg(a1: "go (execution resumed)\n");
      }
      return;
    }
    goto LABEL_41;
  }
  if ( v3 == 26980 )
  {
    if ( *(_DWORD *)(a2 + 2588) != 5 )
    {
      *(_DWORD *)(a2 + 2588) = 5;
      DevMsg(a1: "disabled\n");
    }
  }
  else
  {
    v4 = v3 - 25185;
    if ( v4 != 0 )
    {
      v5 = v4 - 17;
      if ( v5 != 0 )
      {
        if ( v5 == 512 )
        {
          DevMsg(a1: "ready\n");
          *(_BYTE *)(a2 + 2644) = 1;
          return;
        }
        goto LABEL_41;
      }
      w._exp._Mysize = 0;
      w._exp._Bx._Buf[0] = 0;
      w._id = 0;
      w._exp._Myres = 15;
      if ( SQDbgServer::ParseBreakpoint(
             this: (SQDbgServer *)v24,
             msg: &this->xmlstate[0].name[3],
             out: (BreakPoint *)&w) )
      {
        SQDbgServer::RemoveBreakpoint(this: v6, bp: (BreakPoint *)&w);
        p_exp = (std::string *)w._exp._Bx._Ptr;
        if ( w._exp._Myres < 0x10 )
          p_exp = &w._exp;
        DevMsg(a1: "removed bp %d %s\n", w._id, p_exp->_Bx._Buf);
        BreakPoint::~BreakPoint(this: v8, a2: (int)&w);
        return;
      }
      DevMsg(a1: "error parsing remove breakpoint");
LABEL_19:
      BreakPoint::~BreakPoint(this: v9, a2: (int)&w);
      return;
    }
    w._exp._Mysize = 0;
    w._exp._Bx._Buf[0] = 0;
    w._id = 0;
    w._exp._Myres = 15;
    if ( !SQDbgServer::ParseBreakpoint(this: (SQDbgServer *)v24, msg: &this->xmlstate[0].name[3], out: (BreakPoint *)&w) )
    {
      DevMsg(a1: "error parsing add breakpoint");
      goto LABEL_19;
    }
    SQDbgServer::AddBreakpoint(this: v10, bp: (BreakPoint *)&w);
    v11 = (std::string *)w._exp._Bx._Ptr;
    if ( w._exp._Myres < 0x10 )
      v11 = &w._exp;
    DevMsg(a1: "added bp %d %s\n", w._id, v11->_Bx._Buf);
    BreakPoint::~BreakPoint(this: v12, a2: (int)&w);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045C00
// Name: public: bool SQDbgServer::ParseBreakpoint(char const __near *,struct BreakPoint __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall SQDbgServer::ParseBreakpoint@<al>(char *msg@<eax>, BreakPoint *out@<edi>, SQDbgServer *this)
{
  int v4; // eax
  char *v5; // ecx
  char *v6; // ecx
  char v7; // al
  char *i; // edx
  const char *v9; // eax
  char *ep; // [esp+4h] [ebp-4h] BYREF

  ep = nullptr;
  v4 = strtoul(nptr: msg, endptr: &ep, ibase: 16);
  v5 = ep;
  out->_line = v4;
  if ( v5 == msg || *v5 != 58 )
    return 0;
  v6 = v5 + 1;
  ep = v6;
  v7 = *v6;
  for ( i = stemp; *v6 != 10; ++i )
  {
    if ( v7 == 0 )
      break;
    ++v6;
    *i = v7;
    ep = v6;
    v7 = *v6;
  }
  *(_WORD *)i = 0;
  if ( _V_strrchr(s: stemp, c: 47) != nullptr )
    v9 = _V_strrchr(s: stemp, c: 47) + 1;
  else
    v9 = stemp;
  std::string::assign(this: &out->_src, _Ptr: v9, _Count: strlen(v9));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10045CB0
// Name: public: bool SQDbgServer::ParseWatch(char const __near *,struct Watch __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge SQDbgServer::ParseWatch@<al>(char *msg@<eax>, SQDbgServer *this, Watch *out)
{
  char v4; // bl
  int v5; // eax
  char *v6; // esi
  unsigned int v7; // edi
  std::string *v8; // ecx
  char *v9; // eax
  char *ep; // [esp+4h] [ebp-4h] BYREF

  ep = nullptr;
  *(_DWORD *)this->xmlstate[0].name = strtoul(nptr: msg, endptr: &ep, ibase: 16);
  if ( ep == msg || *ep != 58 )
    return 0;
  v4 = *++ep;
  if ( *ep != 10 )
  {
    while ( 1 )
    {
      if ( v4 == 0 )
        return 1;
      v5 = *(_DWORD *)&this->xmlstate[0].name[20];
      v6 = &this->xmlstate[0].name[4];
      if ( v5 == -1 || v5 == -2 || (v7 = v5 + 1, v5 == -2) )
        std::_Xlength_error(_Message: "string too long");
      v8 = *(std::string **)&this->xmlstate[0].name[24];
      if ( (unsigned int)v8 >= v7 )
        break;
      std::string::_Copy(this: v8, _Newsize: (unsigned int)&this->xmlstate[0].name[4], _Oldlen: v5 + 1);
      if ( v7 != 0 )
        goto LABEL_9;
LABEL_19:
      v4 = *++ep;
      if ( *ep == 10 )
        return 1;
    }
    if ( v5 == -1 )
    {
      *(_DWORD *)&this->xmlstate[0].name[20] = 0;
      if ( (unsigned int)v8 >= 0x10 )
        v6 = *(char **)v6;
      *v6 = 0;
      goto LABEL_19;
    }
LABEL_9:
    if ( *(_DWORD *)&this->xmlstate[0].name[24] < 0x10u )
      v9 = &this->xmlstate[0].name[4];
    else
      v9 = *(char **)v6;
    v9[*(_DWORD *)&this->xmlstate[0].name[20]] = v4;
    *(_DWORD *)&this->xmlstate[0].name[20] = v7;
    if ( *(_DWORD *)&this->xmlstate[0].name[24] >= 0x10u )
      v6 = *(char **)v6;
    v6[v7] = 0;
    goto LABEL_19;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10045D90
// Name: public: void SQDbgServer::BreakExecution(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQDbgServer::BreakExecution(SQDbgServer *this@<ecx>, _DWORD *a2@<eax>)
{
  unsigned int v3; // eax
  int v4; // edi
  unsigned int fd_count; // ecx
  unsigned int v6; // eax
  int i; // eax
  _DWORD *v8; // edi
  SQSharedState *v9; // ebx
  SQString *v10; // esi
  int v11; // eax
  _DWORD *v12; // ecx
  const char *v13; // [esp-4h] [ebp-524h]
  char buf; // [esp+Fh] [ebp-511h] BYREF
  struct timeval timeout; // [esp+10h] [ebp-510h] BYREF
  fd_set readfds; // [esp+18h] [ebp-508h] BYREF
  unsigned __int8 dst[1024]; // [esp+120h] [ebp-400h] BYREF

  a2[647] = 4;
  while ( 1 )
  {
    v3 = a2[649];
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;
    readfds.fd_array[0] = v3;
    readfds.fd_count = 1;
    select(nfds: 0, &readfds, writefds: nullptr, exceptfds: nullptr, &timeout);
    if ( __WSAFDIsSet(fd: a2[649], a2: &readfds) == 0 )
      goto LABEL_18;
    v4 = 0;
    memset((int)dst, value: nullptr, count: sizeof(dst));
    fd_count = readfds.fd_count;
    v6 = 0;
    if ( readfds.fd_count != 0 )
    {
      while ( readfds.fd_array[v6] != a2[649] )
      {
        if ( ++v6 >= readfds.fd_count )
          goto LABEL_10;
      }
      for ( ; v6 < readfds.fd_count - 1; ++v6 )
      {
        readfds.fd_array[v6] = readfds.fd_array[v6 + 1];
        fd_count = readfds.fd_count;
      }
      readfds.fd_count = fd_count - 1;
    }
LABEL_10:
    for ( i = recv(s: a2[649], &buf, len: 1, flags: 0); i > 0; i = recv(s: a2[649], &buf, len: 1, flags: 0) )
    {
      if ( buf == 10 )
        break;
      if ( buf != 13 )
        dst[v4++] = buf;
    }
    if ( i == -1 )
      break;
    if ( i == 0 )
    {
      v13 = "disconnected";
      goto LABEL_22;
    }
    dst[v4] = 0;
    dst[v4 + 1] = 0;
    SQDbgServer::ParseMsg(this: (SQDbgServer *)dst, (int)a2);
LABEL_18:
    _ThreadSleep(a1: 10);
    if ( a2[647] != 4 )
      return;
  }
  v13 = "socket error";
LABEL_22:
  v8 = (_DWORD *)a2[644];
  v9 = (SQSharedState *)v8[37];
  v10 = StringTable::Add(this: v9->_stringtable, news: v13, len: -1);
  v10->_sharedstate = v9;
  ++v10->_uiRef;
  v11 = v8[18];
  v12 = (_DWORD *)v8[19];
  v8[19] = v10;
  v8[18] = 134217744;
  ++v10->_uiRef;
  if ( (v11 & 0x8000000) != 0 && (int)--v12[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v12 + 8))(a1: v12);
  if ( --v10->_uiRef <= 0 )
    v10->Release(this: v10);
  g_bSqDbgTerminateScript = true;
}

//------------------------------------------------------------------------------
// Address: 0x10045F60
// Name: public: void SQDbgServer::AddBreakpoint(struct BreakPoint __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQDbgServer::AddBreakpoint(SQDbgServer *this@<ecx>, SQDbgServer *a2@<esi>, BreakPoint *bp)
{
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v3; // edi
  SQDbgServer *v4; // ecx
  std::string *p_src; // eax
  SQDbgServer *v6; // ecx
  bool _Leftish; // [esp+8h] [ebp-Ch] BYREF

  v3 = std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::_Buynode<Watch &>(
         this: &a2->_breakpoints,
         _Val: bp);
  std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0>>::_Linsert(
    this: &a2->_breakpoints,
    _Node: v3,
    (bool)&_Leftish);
  a2->_xmlcurrentement = -1;
  SQDbgServer::BeginElement(this: v4, name: (const char *)a2);
  sprintf(string: value, format: "%d", bp->_line);
  SQDbgServer::Attribute(this: a2, name: "line", value: value);
  p_src = &bp->_src;
  if ( bp->_src._Myres >= 0x10 )
    p_src = (std::string *)p_src->_Bx._Ptr;
  SQDbgServer::Attribute(this: a2, name: "src", value: p_src->_Bx._Buf);
  SQDbgServer::EndElement(this: v6, name: "addbreakpoint");
  send(s: a2->_endpoint, buf: "\r\n", len: 2, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10046000
// Name: public: void SQDbgServer::RemoveWatch(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQDbgServer::RemoveWatch(
        SQDbgServer *this@<ecx>,
        SQDbgServer *a2@<eax>,
        std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *id)
{
  std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *v3; // ebx
  SQDbgServer *v5; // ecx
  SQDbgServer *v6; // ecx
  const Watch *v7; // [esp+0h] [ebp-34h]
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> > > result; // [esp+10h] [ebp-24h] BYREF
  std::string v9; // [esp+14h] [ebp-20h] BYREF

  v3 = id;
  v9._Myres = 15;
  v9._Mysize = 0;
  v9._Bx._Buf[0] = 0;
  result._Ptr = id;
  std::string::assign(this: &v9, _Ptr: Ptr, _Count: 0);
  std::_Tree<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::find(
    this: &a2->_watches,
    &result,
    _Keyval: v7);
  if ( v9._Myres >= 0x10 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9._Bx._Ptr);
  if ( id == a2->_watches._Myhead )
  {
    a2->_xmlcurrentement = -1;
    SQDbgServer::BeginElement(this: v5, name: (const char *)a2);
    SQDbgServer::Attribute(this: a2, name: "desc", value: "the watch does not exists");
    SQDbgServer::EndElement(this: v6, name: "error");
    send(s: a2->_endpoint, buf: "\r\n", len: 2, flags: 0);
  }
  else
  {
    std::_Tree<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::erase(
      this: (std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)&id,
      result: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *)&a2->_watches,
      _Where: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > >)&id);
    DevMsg(a1: "removed watch %d\n", v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100460E0
// Name: public: void SQDbgServer::RemoveBreakpoint(struct BreakPoint __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQDbgServer::RemoveBreakpoint(SQDbgServer *this@<ecx>, SQDbgServer *a2@<eax>, BreakPoint *bp)
{
  BreakPoint *v3; // ebx
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *p_breakpoints; // esi
  SQDbgServer *v6; // ecx
  SQDbgServer *v7; // ecx
  const char *Buf; // eax
  SQDbgServer *v9; // ecx
  std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *v10; // ecx

  v3 = bp;
  p_breakpoints = (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *)&a2->_breakpoints;
  std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0>>::find(
    this: &a2->_breakpoints,
    _Keyval: bp);
  v6 = (SQDbgServer *)bp;
  a2->_xmlcurrentement = -1;
  if ( v6 == (SQDbgServer *)a2->_breakpoints._Myhead )
  {
    SQDbgServer::BeginElement(this: v6, name: (const char *)a2);
    SQDbgServer::Attribute(this: a2, name: "desc", value: "the breakpoint doesn't exists");
    SQDbgServer::EndElement(this: v7, name: "break");
    send(s: a2->_endpoint, buf: "\r\n", len: 2, flags: 0);
  }
  else
  {
    SQDbgServer::BeginElement(this: v6, name: (const char *)a2);
    sprintf(string: value, format: "%d", v3->_line);
    SQDbgServer::Attribute(this: a2, name: "line", value: value);
    Buf = v3->_src._Bx._Buf;
    if ( v3->_src._Myres >= 0x10 )
      Buf = *(const char **)Buf;
    SQDbgServer::Attribute(this: a2, name: "src", value: Buf);
    SQDbgServer::EndElement(this: v9, name: "removebreakpoint");
    send(s: a2->_endpoint, buf: "\r\n", len: 2, flags: 0);
    std::_Tree<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::erase(
      this: v10,
      result: p_breakpoints,
      _Where: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > >)&bp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100461D0
// Name: public: void SQDbgServer::Break(int,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQDbgServer::Break(
        SQDbgServer *this@<eax>,
        const char *type@<esi>,
        SQDbgServer *a3@<ecx>,
        int line,
        const char *src,
        const char *error)
{
  SQDbgServer *v7; // ecx
  SQDbgServer *v8; // ecx

  this->_xmlcurrentement = -1;
  SQDbgServer::BeginElement(this: a3, name: (const char *)this);
  sprintf(string: value, format: "%d", line);
  SQDbgServer::Attribute(this, name: "line", value: value);
  SQDbgServer::Attribute(this, name: "src", value: src);
  SQDbgServer::Attribute(this, name: "type", value: type);
  if ( error != nullptr )
    SQDbgServer::Attribute(this, name: "error", value: error);
  SQDbgServer::SerializeState(this: v7);
  SQDbgServer::EndElement(this: v8, name: "break");
  send(s: this->_endpoint, buf: "\r\n", len: 2, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100462F0
// Name: public: void SQDbgServer::SerializeState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQDbgServer::SerializeState(SQDbgServer *this, SQDbgServer *thisa)
{
  SQDbgServer *v2; // ebx
  SQVM *v; // eax
  int top; // ecx
  SQObjectPtr *vals; // eax
  tagSQObjectType type; // edx
  tagSQObjectType *p_type; // eax
  _DWORD *v8; // ecx
  tagSQObjectType v9; // esi
  SQVM *v10; // eax
  int v11; // ecx
  SQObjectPtr *v12; // eax
  tagSQObjectType v13; // edx
  tagSQObjectType *v14; // eax
  _DWORD *v15; // ecx
  tagSQObjectType v16; // esi
  std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *Left; // edi
  SQVM *v19; // eax
  int v20; // ecx
  int id; // edx
  SQObjectPtr *v22; // eax
  tagSQObjectType v23; // esi
  SQObjectPtr *v24; // eax
  _DWORD *v25; // ecx
  const char *Buf; // eax
  SQVM *v27; // esi
  int v28; // eax
  SQObjectPtr *v29; // ecx
  SQSharedState *sharedstate; // ebx
  SQString *v31; // edi
  tagSQObjectType v32; // eax
  _DWORD *v33; // ecx
  std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *j; // eax
  std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *Parent; // eax
  SQVM *v37; // edi
  int v38; // edx
  SQObjectPtr *v39; // eax
  bool v40; // zf
  int v41; // eax
  SQString *v42; // esi
  tagSQObjectType v43; // eax
  _DWORD *v44; // ecx
  int v45; // eax
  int v46; // esi
  int v47; // eax
  SQDbgServer *v48; // ecx
  const char *v49; // [esp+0h] [ebp-14h]
  SQVM *self; // [esp+Ch] [ebp-8h]
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> > > i; // [esp+10h] [ebp-4h]
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> > > ia; // [esp+10h] [ebp-4h]
  SQDbgServer *thisb; // [esp+1Ch] [ebp+8h]

  v2 = thisa;
  v = thisa->_v;
  top = v->_top;
  v->_top = top + 1;
  vals = v->_stack._vals;
  type = vals[top]._type;
  p_type = &vals[top]._type;
  v8 = *((_DWORD **)p_type + 1);
  p_type[1] = (tagSQObjectType)_null_._unVal.pTable;
  v9 = _null_._type;
  *p_type = _null_._type;
  if ( (v9 & 0x8000000) != 0 )
    ++*(_DWORD *)(*((_DWORD *)p_type + 1) + 4);
  if ( (type & 0x8000000) != 0 && (int)--v8[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(a1: v8);
  sq_setdebughook(v: thisa->_v);
  v10 = thisa->_v;
  v11 = v10->_top;
  v10->_top = v11 + 1;
  v12 = v10->_stack._vals;
  v13 = v12[v11]._type;
  v14 = &v12[v11]._type;
  v15 = *((_DWORD **)v14 + 1);
  v14[1] = (tagSQObjectType)_null_._unVal.pTable;
  v16 = _null_._type;
  *v14 = _null_._type;
  if ( (v16 & 0x8000000) != 0 )
    ++*(_DWORD *)(*((_DWORD *)v14 + 1) + 4);
  if ( (v13 & 0x8000000) != 0 && (int)--v15[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v15 + 8))(a1: v15);
  sq_seterrorhandler(v: thisa->_v);
  sq_pushobject(obj: thisa->_serializefunc);
  sq_pushobject(obj: thisa->_debugroot);
  sq_pushstring(v: thisa->_v, s: "watches", len: -1);
  sq_newtable(v: thisa->_v);
  Myhead = thisa->_watches._Myhead;
  Left = Myhead->_Left;
  i._Ptr = Myhead->_Left;
  if ( Myhead->_Left != Myhead )
  {
    do
    {
      v19 = v2->_v;
      v20 = v19->_top;
      id = Left->_Myval._id;
      v19->_top = v20 + 1;
      v22 = v19->_stack._vals;
      v23 = v22[v20]._type;
      v24 = &v22[v20];
      v25 = &v24->_unVal.pTable->__vftable;
      v24->_unVal.nInteger = id;
      v24->_type = OT_INTEGER;
      if ( (v23 & 0x8000000) != 0 && (int)--v25[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v25 + 8))(a1: v25);
      Buf = Left->_Myval._exp._Bx._Buf;
      if ( Left->_Myval._exp._Myres >= 0x10 )
        Buf = *(const char **)Buf;
      sq_pushstring(v: v2->_v, s: Buf, len: Left->_Myval._exp._Mysize);
      v27 = v2->_v;
      v28 = v27->_top;
      if ( v28 - v27->_stackbase >= 3 )
      {
        v29 = v27->_stack._vals;
        self = (SQVM *)&v29[v28 - 3];
        if ( self->__vftable != (SQVM_vtbl *)167772192 && self->__vftable != (SQVM_vtbl *)134234112 )
          goto LABEL_29;
        if ( v29[v28 - 2]._type != OT_NULL )
        {
          SQVM::NewSlot(this: self, (const SQObjectPtr *)self, key: &v29[v28 - 2], val: &v29[v28 - 1], bstatic: false);
          SQVM::Pop(this: v27, n: 2);
          goto LABEL_29;
        }
        sharedstate = v27->_sharedstate;
        v31 = StringTable::Add(this: sharedstate->_stringtable, news: "null is not a valid key", len: -1);
        v31->_sharedstate = sharedstate;
        ++v31->_uiRef;
        v32 = v27->_lasterror._type;
        v33 = &v27->_lasterror._unVal.pTable->__vftable;
        v27->_lasterror._unVal.nInteger = (int)v31;
        v27->_lasterror._type = OT_STRING;
        ++v31->_uiRef;
        if ( (v32 & 0x8000000) != 0 && (int)--v33[1] <= 0 )
          (*(void (__thiscall **)(_DWORD *))(*v33 + 8))(a1: v33);
        if ( --v31->_uiRef <= 0 )
          v31->Release(this: v31);
        v2 = thisa;
      }
      else
      {
        SQVM::Raise_Error(this: (SQVM *)&stru_1009BB84._debughook, s: v49);
      }
      Left = i._Ptr;
LABEL_29:
      if ( Left->_Isnil == 0 )
      {
        Right = Left->_Right;
        if ( Right->_Isnil != 0 )
        {
          Parent = Left->_Parent;
          if ( Parent->_Isnil == 0 )
          {
            while ( Left == Parent->_Right )
            {
              ia._Ptr = Parent;
              Parent = Parent->_Parent;
              if ( Parent->_Isnil != 0 )
                break;
              Left = ia._Ptr;
            }
          }
          i._Ptr = Parent;
        }
        else
        {
          for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
            Right = j;
          i._Ptr = Right;
        }
        Left = i._Ptr;
      }
    }
    while ( Left != v2->_watches._Myhead );
  }
  sq_rawset(v: v2->_v);
  if ( sq_call(v: v2->_v, params: 1, retval: 1u, raiseerror: 1u) >= 0 )
  {
    v37 = v2->_v;
    v38 = v37->_top;
    v39 = v37->_stack._vals;
    v40 = v39[v38 - 1]._type == OT_INSTANCE;
    v41 = (int)&v39[v38 - 1];
    if ( v40 )
    {
      v45 = *(_DWORD *)(v41 + 4);
      v46 = *(_DWORD *)(v45 + 32);
      v47 = *(_DWORD *)(v45 + 28);
      while ( *(_DWORD *)(v47 + 76) != -2147483646 )
      {
        v47 = *(_DWORD *)(v47 + 28);
        if ( v47 == 0 )
        {
          if ( sq_throwerror(v: v37, err: "invalid type tag") < 0 )
            goto LABEL_55;
          break;
        }
      }
      send(s: v2->_endpoint, buf: *(const char **)(v46 + 16), len: strlen(*(const char **)(v46 + 16)), flags: 0);
    }
    else
    {
      thisb = (SQDbgServer *)v37->_sharedstate;
      v42 = StringTable::Add(
              this: *(StringTable **)&thisb->xmlstate[0].name[20],
              news: "the object is not a class instance",
              len: -1);
      v42->_sharedstate = (SQSharedState *)thisb;
      ++v42->_uiRef;
      v43 = v37->_lasterror._type;
      v44 = &v37->_lasterror._unVal.pTable->__vftable;
      v37->_lasterror._unVal.nInteger = (int)v42;
      v37->_lasterror._type = OT_STRING;
      ++v42->_uiRef;
      if ( (v43 & 0x8000000) != 0 && (int)--v44[1] <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*v44 + 8))(a1: v44);
      if ( --v42->_uiRef <= 0 )
        v42->Release(this: v42);
    }
  }
LABEL_55:
  SQVM::Pop(this: v2->_v, n: 2);
  SQDbgServer::SetErrorHandlers(this: v48);
}

//------------------------------------------------------------------------------
// Address: 0x100466D0
// Name: public: void SQDbgServer::SetErrorHandlers(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQDbgServer::SetErrorHandlers(SQDbgServer *this@<ecx>, int a2@<eax>)
{
  _DWORD *v3; // eax
  int v4; // ecx
  int v5; // edx
  int v6; // eax
  int v7; // ebx
  int v8; // edi
  _DWORD *v9; // eax
  _DWORD *v10; // ecx
  int v11; // edx

  v3 = *(_DWORD **)(a2 + 2576);
  v4 = v3[14];
  v5 = v3[37];
  v3[14] = v4 + 1;
  v6 = v3[8];
  v7 = *(_DWORD *)(v5 + 48);
  v8 = *(_DWORD *)(v6 + 8 * v4);
  v9 = (_DWORD *)(v6 + 8 * v4);
  v10 = (_DWORD *)v9[1];
  v9[1] = v7;
  v11 = *(_DWORD *)(v5 + 44);
  *v9 = v11;
  if ( (v11 & 0x8000000) != 0 )
    ++*(_DWORD *)(v7 + 4);
  if ( (v8 & 0x8000000) != 0 && (int)--v10[1] <= 0 )
    (*(void (__thiscall **)(_DWORD *))(*v10 + 8))(a1: v10);
  sq_pushstring(v: *(SQVM **)(a2 + 2576), s: "_sqdbg_debug_hook_", len: -1);
  sq_rawget(v: *(SQVM **)(a2 + 2576));
  sq_setdebughook(v: *(SQVM **)(a2 + 2576));
  sq_pushstring(v: *(SQVM **)(a2 + 2576), s: "_sqdbg_error_handler_", len: -1);
  sq_rawget(v: *(SQVM **)(a2 + 2576));
  sq_seterrorhandler(v: *(SQVM **)(a2 + 2576));
  SQVM::Pop(this: *(SQVM **)(a2 + 2576), n: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10046790
// Name: public: void SQDbgServer::BeginElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQDbgServer::BeginElement(SQDbgServer *this, SQDbgServer *name, const char *namea)
{
  char *v4; // esi
  int xmlcurrentement; // eax
  int v6; // eax
  const char *v7; // esi
  char *Myfirst; // edx
  unsigned int v9; // edi
  unsigned __int8 *Mylast; // eax
  unsigned __int8 *v11; // edx
  int v12; // ecx
  unsigned int v13; // eax
  SQDbgServer *thisa; // [esp+14h] [ebp+8h]

  v4 = name->xmlstate[++name->_xmlcurrentement].name;
  strcpy(v4, namea);
  v4[256] = 0;
  xmlcurrentement = name->_xmlcurrentement;
  if ( xmlcurrentement > 0 )
  {
    v6 = xmlcurrentement;
    v7 = (char *)name + v6 * 257 - 257;
    if ( !name->xmlstate[v6 - 1].haschildren )
    {
      send(s: name->_endpoint, buf: ">", len: 1, flags: 0);
      *((_BYTE *)v7 + 256) = 1;
    }
  }
  Myfirst = name->_scratchstring._Myfirst;
  v9 = strlen(namea) + 2;
  Mylast = (unsigned __int8 *)name->_scratchstring._Mylast;
  if ( Mylast - (unsigned __int8 *)Myfirst <= v9 )
  {
    if ( Mylast - (unsigned __int8 *)Myfirst < v9 )
    {
      std::vector<char>::_Reserve(this: &name->_scratchstring, _Count: v9 + Myfirst - (char *)Mylast);
      v12 = (int)name->_scratchstring._Mylast;
      v13 = (unsigned int)&name->_scratchstring._Myfirst[v9 - v12];
      if ( v13 != 0 )
        memset(dst: v12, value: nullptr, count: v13);
      name->_scratchstring._Mylast = &name->_scratchstring._Myfirst[v9];
    }
  }
  else
  {
    v11 = (unsigned __int8 *)&Myfirst[v9];
    thisa = (SQDbgServer *)v11;
    if ( v11 != Mylast )
    {
      memmove(dst: v11, src: Mylast, count: 0);
      name->_scratchstring._Mylast = (char *)thisa;
    }
  }
  sprintf(string: name->_scratchstring._Myfirst, format: "<%s", namea);
  send(s: name->_endpoint, buf: name->_scratchstring._Myfirst, len: strlen(name->_scratchstring._Myfirst), flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100468D0
// Name: public: void SQDbgServer::Attribute(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SQDbgServer::Attribute(SQDbgServer *ecx0, SQDbgServer *this, const char *name)
{
  unsigned int v4; // ecx
  unsigned int v5; // kr00_4
  char *Myfirst; // edx
  unsigned int v7; // edi
  unsigned __int8 *Mylast; // eax
  std::vector<char> *p_scratchstring; // esi
  unsigned __int8 *v10; // ebx
  char *v11; // ecx
  unsigned int v12; // eax
  const char *escval; // [esp+Ch] [ebp-4h]

  escval = SQDbgServer::escape_xml(this: ecx0, s: (const char *)this);
  v4 = strlen(name);
  v5 = strlen(escval);
  Myfirst = this->_scratchstring._Myfirst;
  v7 = v5 + v4 + 5;
  Mylast = (unsigned __int8 *)this->_scratchstring._Mylast;
  p_scratchstring = &this->_scratchstring;
  if ( Mylast - (unsigned __int8 *)Myfirst <= v7 )
  {
    if ( Mylast - (unsigned __int8 *)Myfirst < v7 )
    {
      std::vector<char>::_Reserve(this: &this->_scratchstring, _Count: v7 + Myfirst - (char *)Mylast);
      v11 = this->_scratchstring._Mylast;
      v12 = v7 + p_scratchstring->_Myfirst - v11;
      if ( v12 != 0 )
        memset(dst: (int)v11, value: nullptr, count: v12);
      this->_scratchstring._Mylast = &p_scratchstring->_Myfirst[v7];
    }
  }
  else
  {
    v10 = (unsigned __int8 *)&Myfirst[v7];
    if ( &Myfirst[v7] != (char *)Mylast )
    {
      memmove(dst: v10, src: Mylast, count: 0);
      this->_scratchstring._Mylast = (char *)v10;
    }
  }
  sprintf(string: p_scratchstring->_Myfirst, format: " %s=\"%s\"", name, escval);
  send(s: this->_endpoint, buf: p_scratchstring->_Myfirst, len: strlen(p_scratchstring->_Myfirst), flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100469C0
// Name: public: void SQDbgServer::EndElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SQDbgServer::EndElement(SQDbgServer *this@<ecx>, int a2@<edi>, const char *name)
{
  if ( *(_BYTE *)(257 * *(_DWORD *)(a2 + 2572) + a2 + 256) != 0 )
  {
    std::vector<char>::resize(this: (std::vector<char> *)(a2 + 2656), _Newsize: strlen(name) + 4);
    sprintf(string: *(char **)(a2 + 2656), format: "</%s>", name);
    send(
      s: *(_DWORD *)(a2 + 2596),
      buf: *(const char **)(a2 + 2656),
      len: strlen(*(const char **)(a2 + 2656)),
      flags: 0);
  }
  else
  {
    send(s: *(_DWORD *)(a2 + 2596), buf: "/>", len: 2, flags: 0);
  }
  --*(_DWORD *)(a2 + 2572);
}

//------------------------------------------------------------------------------
// Address: 0x10046A60
// Name: public: void SQDbgServer::EndDocument(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SQDbgServer::EndDocument(SQDbgServer *this@<ecx>, int a2@<eax>)
{
  send(s: *(_DWORD *)(a2 + 2596), buf: "\r\n", len: 2, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10046A80
// Name: public: char const __near * SQDbgServer::escape_xml(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall SQDbgServer::escape_xml(SQDbgServer *this, SQDbgServer *s, const char *sa)
{
  const char *v3; // ebx
  SQSharedState *v4; // ecx
  char *result; // eax
  char v6; // dl
  int v7; // edi
  int v8; // ecx
  char *v9; // edx
  char *v10; // esi
  char v11; // cl
  int v12; // [esp+0h] [ebp-8h]
  const char *sb; // [esp+14h] [ebp+Ch]

  v3 = sa;
  v4 = (SQSharedState *)(6 * strlen(sa) + 1);
  if ( (int)v4 <= 0 )
    result = s->_v->_sharedstate->_scratchpad;
  else
    result = SQSharedState::GetScratchPad(this: v4, size: v12);
  v6 = *sa;
  sb = result;
  if ( *v3 != 0 )
  {
    do
    {
      v7 = 0;
      if ( off_100A710C != nullptr )
      {
        v8 = 0;
        while ( v6 != g_escapes[v8].c )
        {
          v8 = ++v7;
          if ( (&off_100A710C)[2 * v7] == nullptr )
            goto LABEL_9;
        }
        v9 = (&off_100A710C)[2 * v7];
        v10 = result;
        do
        {
          v11 = *v9;
          *v10++ = *v9++;
        }
        while ( v11 != 0 );
        result += strlen((&off_100A710C)[2 * v7]);
      }
      else
      {
LABEL_9:
        *result++ = v6;
      }
      v6 = *++v3;
    }
    while ( v6 != 0 );
    *result = 0;
    return (char *)sb;
  }
  else
  {
    *result = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10046B50
// Name: public: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<struct BreakPoint,struct std::less<struct BreakPoint>,class std::allocator<struct BreakPoint>,0>>> std::_Tree<class std::_Tset_traits<struct BreakPoint,struct std::less<struct BreakPoint>,class std::allocator<struct BreakPoint>,0>>::find(struct BreakPoint const __near &)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *__userpurge std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0>>::find@<eax>(
        std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *this@<esi>,
        const BreakPoint *_Keyval@<eax>,
        std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node **_Where)
{
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v5; // eax
  int line; // edx
  std::string *p_src; // eax
  std::string *Ptr; // ecx
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > _Wherea; // [esp+14h] [ebp+8h]

  v5 = std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0>>::_Lbound(
         this,
         _Keyval);
  _Wherea._Ptr = v5;
  if ( v5 == this->_Myhead )
    goto LABEL_10;
  line = v5->_Myval._line;
  if ( _Keyval->_line < line )
    goto LABEL_10;
  if ( _Keyval->_line != line )
    goto LABEL_9;
  p_src = &v5->_Myval._src;
  if ( p_src->_Myres >= 0x10 )
    p_src = (std::string *)p_src->_Bx._Ptr;
  Ptr = &_Keyval->_src;
  if ( _Keyval->_src._Myres >= 0x10 )
    Ptr = (std::string *)Ptr->_Bx._Ptr;
  if ( dbg_less(y: p_src->_Bx._Buf, x: Ptr->_Bx._Buf) )
  {
LABEL_10:
    *_Where = this->_Myhead;
    return (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *)_Where;
  }
  else
  {
LABEL_9:
    *_Where = _Wherea._Ptr;
    return (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *)_Where;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046BD0
// Name: public: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>> std::_Tree<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *__thiscall std::_Tree<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::erase(
        std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *this,
        std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > _Where,
        std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *_Wherea)
{
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Right; // edi
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Parent; // esi
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v6; // edx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *i; // ecx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Left; // eax
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v10; // ecx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v11; // eax
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v12; // eax
  std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *v13; // ecx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Mysize; // eax
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v16; // [esp+0h] [ebp-8h]

  if ( _Wherea->_Isnil != 0 )
    std::_Xout_of_range(_Message: "invalid map/set<T> iterator");
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>,std::_Iterator_base0>::operator++((std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >,std::_Iterator_base0> *)this);
  if ( _Wherea->_Left->_Isnil != 0 )
  {
    Right = _Wherea->_Right;
  }
  else if ( _Wherea->_Right->_Isnil != 0 )
  {
    Right = _Wherea->_Left;
  }
  else
  {
    Right = _Wherea->_Right;
  }
  Parent = _Wherea->_Parent;
  if ( Right->_Isnil == 0 )
    Right->_Parent = Parent;
  v6 = (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)result;
  Myhead = result->_Myhead;
  if ( Myhead->_Parent == _Wherea )
  {
    Myhead->_Parent = Right;
  }
  else if ( Parent->_Left == _Wherea )
  {
    Parent->_Left = Right;
  }
  else
  {
    Parent->_Right = Right;
  }
  if ( result->_Myhead->_Left == _Wherea )
  {
    if ( Right->_Isnil != 0 )
    {
      i = Parent;
    }
    else
    {
      Left = Right->_Left;
      for ( i = Right; Left->_Isnil == 0; Left = Left->_Left )
        i = Left;
    }
    result->_Myhead->_Left = i;
  }
  v10 = result->_Myhead;
  v16 = v10;
  if ( v10->_Right == _Wherea )
  {
    if ( Right->_Isnil != 0 )
    {
      v10->_Right = Parent;
    }
    else
    {
      v11 = std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::_Max(_Pnode: Right);
      v6 = (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)result;
      v16->_Right = v11;
    }
  }
  v12 = _Wherea;
  if ( _Wherea->_Color == 1 )
  {
    for ( ; Right != v6->_Parent->_Parent; Parent = Parent->_Parent )
    {
      if ( Right->_Color != 1 )
        break;
      v13 = (std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)Parent->_Left;
      if ( Right == Parent->_Left )
      {
        v13 = (std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)Parent->_Right;
        if ( *(_BYTE *)&v13[2]._Alnod.std::_Allocator_base<std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node> == 0 )
        {
          v13[2]._Alnod.std::_Allocator_base<std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node> = (std::_Allocator_base<std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node>)1;
          Parent->_Color = 0;
          std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0>>::_Lrotate(
            this: (std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)Parent,
            _Wherenode: v6);
          v13 = (std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)Parent->_Right;
          v6 = (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)result;
        }
        if ( *(_BYTE *)&v13[2]._Alval.std::_Allocator_base<BreakPoint> != 0 )
          goto LABEL_43;
        if ( *(_BYTE *)(*(_DWORD *)&v13->comp.std::binary_function<BreakPoint,BreakPoint,bool> + 44) != 1
          || *(_BYTE *)(v13->_Mysize + 44) != 1 )
        {
          if ( *(_BYTE *)(v13->_Mysize + 44) == 1 )
          {
            *(_BYTE *)(*(_DWORD *)&v13->comp.std::binary_function<BreakPoint,BreakPoint,bool> + 44) = 1;
            v13[2]._Alnod.std::_Allocator_base<std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node> = 0;
            std::_Tree<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::_Rrotate(
              this: v13,
              _Wherenode: v6);
            v13 = (std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)Parent->_Right;
            v6 = (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)result;
          }
          v13[2]._Alnod.std::_Allocator_base<std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node> = (std::_Allocator_base<std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node>)Parent->_Color;
          Parent->_Color = 1;
          *(_BYTE *)(v13->_Mysize + 44) = 1;
          std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0>>::_Lrotate(
            this: (std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)Parent,
            _Wherenode: v6);
          break;
        }
      }
      else
      {
        if ( *(_BYTE *)&v13[2]._Alnod.std::_Allocator_base<std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node> == 0 )
        {
          v13[2]._Alnod.std::_Allocator_base<std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node> = (std::_Allocator_base<std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node>)1;
          Parent->_Color = 0;
          std::_Tree<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::_Rrotate(
            this: (std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)Parent,
            _Wherenode: v6);
          v13 = (std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)Parent->_Left;
          v6 = (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)result;
        }
        if ( *(_BYTE *)&v13[2]._Alval.std::_Allocator_base<BreakPoint> != 0 )
          goto LABEL_43;
        if ( *(_BYTE *)(v13->_Mysize + 44) != 1
          || *(_BYTE *)(*(_DWORD *)&v13->comp.std::binary_function<BreakPoint,BreakPoint,bool> + 44) != 1 )
        {
          if ( *(_BYTE *)(*(_DWORD *)&v13->comp.std::binary_function<BreakPoint,BreakPoint,bool> + 44) == 1 )
          {
            *(_BYTE *)(v13->_Mysize + 44) = 1;
            v13[2]._Alnod.std::_Allocator_base<std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node> = 0;
            std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0>>::_Lrotate(
              this: v13,
              _Wherenode: v6);
            v13 = (std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)Parent->_Left;
            v6 = (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)result;
          }
          v13[2]._Alnod.std::_Allocator_base<std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node> = (std::_Allocator_base<std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node>)Parent->_Color;
          Parent->_Color = 1;
          *(_BYTE *)(*(_DWORD *)&v13->comp.std::binary_function<BreakPoint,BreakPoint,bool> + 44) = 1;
          std::_Tree<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::_Rrotate(
            this: (std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)Parent,
            _Wherenode: v6);
          break;
        }
      }
      v13[2]._Alnod.std::_Allocator_base<std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node> = 0;
LABEL_43:
      Right = Parent;
    }
    v12 = _Wherea;
    Right->_Color = 1;
  }
  if ( v12->_Myval._src._Myres >= 0x10 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12->_Myval._src._Bx._Ptr);
  _Wherea->_Myval._src._Myres = 15;
  _Wherea->_Myval._src._Mysize = 0;
  _Wherea->_Myval._src._Bx._Buf[0] = 0;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: _Wherea);
  Mysize = (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)result->_Mysize;
  if ( Mysize != nullptr )
    result->_Mysize = (unsigned int)(&Mysize[-1]._Isnil + 2);
  _Where._Ptr->_Left = _Wherea;
  return _Where._Ptr;
}

//------------------------------------------------------------------------------
// Address: 0x10046E70
// Name: public: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>> std::_Tree<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>::find(struct Watch const __near &)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> > > *__userpurge std::_Tree<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::find@<eax>(
        std::_Tree<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> > *this@<ecx>,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> > > *a2@<eax>,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> > > *result,
        const Watch *_Keyval)
{
  std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *Myhead; // edx
  std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *Parent; // ecx
  std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *v7; // ecx

  Myhead = this->_Myhead;
  Parent = Myhead->_Parent;
  while ( Parent->_Isnil == 0 )
  {
    if ( Parent->_Myval._id >= (int)result->_Ptr )
    {
      Myhead = Parent;
      Parent = Parent->_Left;
    }
    else
    {
      Parent = Parent->_Right;
    }
  }
  v7 = this->_Myhead;
  if ( Myhead == v7 || (int)result->_Ptr < Myhead->_Myval._id )
    a2->_Ptr = v7;
  else
    a2->_Ptr = Myhead;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10046EE0
// Name: public: void std::vector<char,class std::allocator<char>>::resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __usercall std::vector<char>::resize(std::vector<char> *this@<esi>, unsigned int _Newsize@<eax>)
{
  char *Myfirst; // edx
  unsigned __int8 *Mylast; // eax
  unsigned int v5; // ecx
  unsigned __int8 *v6; // ebx
  char *v7; // ecx
  char *v8; // eax

  Myfirst = this->_Myfirst;
  Mylast = (unsigned __int8 *)this->_Mylast;
  v5 = Mylast - (unsigned __int8 *)this->_Myfirst;
  if ( v5 <= _Newsize )
  {
    if ( v5 < _Newsize )
    {
      std::vector<char>::_Reserve(this, _Count: _Newsize + Myfirst - (char *)Mylast);
      v7 = this->_Mylast;
      v8 = (char *)(_Newsize + this->_Myfirst - v7);
      if ( v8 != nullptr )
        memset(dst: (int)v7, value: nullptr, count: (unsigned int)v8);
      this->_Mylast = &this->_Myfirst[_Newsize];
    }
  }
  else
  {
    v6 = (unsigned __int8 *)&Myfirst[_Newsize];
    if ( &Myfirst[_Newsize] != (char *)Mylast )
    {
      memmove(dst: v6, src: Mylast, count: 0);
      this->_Mylast = (char *)v6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046F40
// Name: public: bool std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::_Grow(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall std::string::_Grow@<eax>(std::string *this@<eax>, unsigned int _Newsize@<esi>)
{
  unsigned int Myres; // ecx

  if ( _Newsize == -1 )
    std::_Xlength_error(_Message: "string too long");
  Myres = this->_Myres;
  if ( Myres >= _Newsize )
  {
    if ( _Newsize == 0 )
    {
      this->_Mysize = 0;
      if ( Myres >= 0x10 )
        this = (std::string *)this->_Bx._Ptr;
      this->_Bx._Buf[0] = 0;
    }
    return _Newsize != 0;
  }
  else
  {
    std::string::_Copy(this: (std::string *)this->_Mysize, _Newsize: (unsigned int)this, _Oldlen: _Newsize);
    return _Newsize != 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046F90
// Name: protected: void std::_Tree<class std::_Tset_traits<struct BreakPoint,struct std::less<struct BreakPoint>,class std::allocator<struct BreakPoint>,0>>::_Lrotate(struct std::_Tree_nod<class std::_Tset_traits<struct BreakPoint,struct std::less<struct BreakPoint>,class std::allocator<struct BreakPoint>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0>>::_Lrotate(
        std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *this,
        std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *_Wherenode)
{
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Mysize; // eax
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Myhead; // edx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v4; // edx

  Mysize = (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)this->_Mysize;
  this->_Mysize = (unsigned int)Mysize->_Left;
  if ( Mysize->_Left->_Isnil == 0 )
    Mysize->_Left->_Parent = (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)this;
  Mysize->_Parent = this->_Myhead;
  Myhead = _Wherenode->_Myhead;
  if ( this == (std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)Myhead->_Parent )
  {
    Myhead->_Parent = Mysize;
    Mysize->_Left = (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)this;
    this->_Myhead = Mysize;
  }
  else
  {
    v4 = this->_Myhead;
    if ( this == (std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)v4->_Left )
      v4->_Left = Mysize;
    else
      v4->_Right = Mysize;
    Mysize->_Left = (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)this;
    this->_Myhead = Mysize;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046FF0
// Name: public: static struct std::_Tree_nod<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>::_Node __near * std::_Tree_val<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>::_Max(struct std::_Tree_nod<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *__usercall std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::_Max@<eax>(
        std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *_Pnode@<eax>)
{
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *i; // ecx

  for ( i = _Pnode->_Right; i->_Isnil == 0; i = i->_Right )
    _Pnode = i;
  return _Pnode;
}

//------------------------------------------------------------------------------
// Address: 0x10047010
// Name: protected: void std::_Tree<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>::_Rrotate(struct std::_Tree_nod<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::_Rrotate(
        std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *this,
        std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *_Wherenode)
{
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v2; // eax
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Right; // edx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Myhead; // edx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v5; // edx

  v2 = *(std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node **)&this->comp.std::binary_function<BreakPoint,BreakPoint,bool>;
  *(_DWORD *)&this->comp.std::binary_function<BreakPoint,BreakPoint,bool> = *(_DWORD *)(*(_DWORD *)&this->comp.std::binary_function<BreakPoint,BreakPoint,bool>
                                                                                      + 8);
  Right = v2->_Right;
  if ( Right->_Isnil == 0 )
    Right->_Parent = (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)this;
  v2->_Parent = this->_Myhead;
  Myhead = _Wherenode->_Myhead;
  if ( this == (std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)Myhead->_Parent )
  {
    Myhead->_Parent = v2;
    v2->_Right = (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)this;
    this->_Myhead = v2;
  }
  else
  {
    v5 = this->_Myhead;
    if ( this == (std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)v5->_Right )
      v5->_Right = v2;
    else
      v5->_Left = v2;
    v2->_Right = (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)this;
    this->_Myhead = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047070
// Name: protected: void std::vector<char,class std::allocator<char>>::_Reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __fastcall std::vector<char>::_Reserve(std::vector<char> *this, unsigned int _Count)
{
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // edx

  v2 = this->_Mylast - this->_Myfirst;
  if ( -1 - _Count < v2 )
    std::_Xlength_error(_Message: "vector<T> too long");
  v3 = _Count + v2;
  v4 = this->_Myend - this->_Myfirst;
  if ( v3 > v4 )
  {
    if ( -1 - (v4 >> 1) >= v4 )
    {
      v5 = (v4 >> 1) + v4;
      if ( v5 < v3 )
        v5 = v3;
    }
    else
    {
      v5 = 0;
      if ( v3 != 0 )
        v5 = v3;
    }
    std::vector<char>::reserve(this, _Count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100470D0
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>,struct std::_Iterator_base0>::operator++(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >,std::_Iterator_base0> *__usercall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>,std::_Iterator_base0>::operator++@<eax>(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >,std::_Iterator_base0> *this@<ecx>,
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >,std::_Iterator_base0> *result@<eax>)
{
  std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *Ptr; // ecx
  std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *Right; // edx
  std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *j; // ecx
  std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *i; // ecx

  Ptr = result->_Ptr;
  if ( result->_Ptr->_Isnil == 0 )
  {
    Right = Ptr->_Right;
    if ( Right->_Isnil != 0 )
    {
      for ( i = Ptr->_Parent; i->_Isnil == 0; i = i->_Parent )
      {
        if ( result->_Ptr != i->_Right )
          break;
        result->_Ptr = i;
      }
      result->_Ptr = i;
    }
    else
    {
      for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
        Right = j;
      result->_Ptr = Right;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10047120
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::assign(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
std::string *__userpurge std::string::assign@<eax>(
        std::string *this@<edi>,
        unsigned int _Count@<ecx>,
        const std::string *_Right,
        unsigned int _Roff)
{
  unsigned int Mysize; // eax
  unsigned int v5; // esi
  const std::string *Ptr; // ecx
  std::string *v8; // eax
  bool v9; // cf

  Mysize = _Right->_Mysize;
  if ( Mysize < _Roff )
    std::_Xout_of_range(_Message: "invalid string position");
  v5 = Mysize - _Roff;
  if ( _Count < Mysize - _Roff )
    v5 = _Count;
  if ( this == _Right )
  {
    std::string::erase(this, _Off: v5 + _Roff, _Count: 0xFFFFFFFF);
    std::string::erase(this, _Off: 0, _Count: _Roff);
    return this;
  }
  if ( std::string::_Grow(this, _Newsize: v5) )
  {
    Ptr = _Right;
    if ( _Right->_Myres >= 0x10 )
      Ptr = (const std::string *)_Right->_Bx._Ptr;
    if ( this->_Myres < 0x10 )
      v8 = this;
    else
      v8 = (std::string *)this->_Bx._Ptr;
    memcpy(dst: (unsigned __int8 *)v8, src: (unsigned __int8 *)&Ptr->_Bx._Buf[_Roff], count: v5);
    v9 = this->_Myres < 0x10;
    this->_Mysize = v5;
    if ( !v9 )
    {
      this->_Bx._Ptr[v5] = 0;
      return this;
    }
    this->_Bx._Buf[v5] = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100471C0
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::assign(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
std::string *__userpurge std::string::assign@<eax>(
        std::string *this@<eax>,
        unsigned int _Count@<esi>,
        std::string *Myres@<ecx>,
        char *_Ptr)
{
  std::string *v4; // edi
  std::string *v5; // eax
  unsigned int v7; // eax
  unsigned __int8 *Ptr; // eax
  bool v9; // cf

  v4 = this;
  if ( _Ptr != nullptr )
  {
    Myres = (std::string *)this->_Myres;
    if ( (unsigned int)Myres >= 0x10 )
      this = (std::string *)this->_Bx._Ptr;
    if ( _Ptr >= (char *)this )
    {
      v5 = (unsigned int)Myres < 0x10 ? v4 : (std::string *)v4->_Bx._Ptr;
      if ( (char *)v5 + v4->_Mysize > _Ptr )
      {
        if ( (unsigned int)Myres < 0x10 )
          return std::string::assign(this: v4, _Count, _Right: v4, _Roff: _Ptr - (char *)v4);
        else
          return std::string::assign(this: v4, _Count, _Right: v4, _Roff: _Ptr - v4->_Bx._Ptr);
      }
    }
  }
  if ( _Count == -1 )
    std::_Xlength_error(_Message: "string too long");
  v7 = v4->_Myres;
  if ( v7 < _Count )
  {
    std::string::_Copy(this: Myres, _Newsize: (unsigned int)v4, _Oldlen: _Count);
    if ( _Count == 0 )
      return v4;
LABEL_16:
    if ( v4->_Myres < 0x10 )
      Ptr = (unsigned __int8 *)v4;
    else
      Ptr = (unsigned __int8 *)v4->_Bx._Ptr;
    memcpy(dst: Ptr, src: (unsigned __int8 *)_Ptr, count: _Count);
    v9 = v4->_Myres < 0x10;
    v4->_Mysize = _Count;
    if ( !v9 )
    {
      v4->_Bx._Ptr[_Count] = 0;
      return v4;
    }
    v4->_Bx._Buf[_Count] = 0;
    return v4;
  }
  if ( _Count != 0 )
    goto LABEL_16;
  v4->_Mysize = 0;
  if ( v7 < 0x10 )
    v4->_Bx._Buf[0] = 0;
  else
    *v4->_Bx._Ptr = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100472A0
// Name: public: void std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::_Copy(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::string::_Copy(
        std::string *this,
        std::string *_Newsize,
        unsigned int _Oldlen,
        unsigned int _Oldlena)
{
  std::string *v4; // edi
  unsigned int v5; // esi
  unsigned int Myres; // ebx
  unsigned int v7; // ecx
  char *v8; // ebx
  unsigned int v9; // ecx
  unsigned __int8 *Ptr; // eax
  std::allocator<char> *v11; // [esp+0h] [ebp-20h] BYREF
  char *_Ptr; // [esp+Ch] [ebp-14h]
  std::allocator<char> **v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+1Ch] [ebp-4h]

  v13 = &v11;
  v4 = _Newsize;
  v5 = _Oldlen | 0xF;
  if ( (_Oldlen | 0xF) == 0xFFFFFFFF )
  {
    v5 = _Oldlen;
  }
  else
  {
    Myres = _Newsize->_Myres;
    v7 = Myres >> 1;
    if ( Myres >> 1 > v5 / 3 )
    {
      v5 = v7 + Myres;
      if ( Myres > -2 - v7 )
        v5 = -2;
    }
  }
  v14 = 0;
  v8 = std::allocator<char>::allocate(this: v11, _Count: v5 + 1);
  _Ptr = v8;
  v14 = -1;
  v9 = _Oldlena;
  if ( _Oldlena != 0 )
  {
    if ( _Newsize->_Myres < 0x10 )
      Ptr = (unsigned __int8 *)_Newsize;
    else
      Ptr = (unsigned __int8 *)_Newsize->_Bx._Ptr;
    memcpy(dst: (unsigned __int8 *)v8, src: Ptr, count: _Oldlena);
    v9 = _Oldlena;
  }
  if ( _Newsize->_Myres >= 0x10 )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: _Newsize->_Bx._Ptr);
    v9 = _Oldlena;
  }
  _Newsize->_Bx._Buf[0] = 0;
  _Newsize->_Bx._Ptr = v8;
  _Newsize->_Myres = v5;
  _Newsize->_Mysize = v9;
  if ( v5 >= 0x10 )
    v4 = (std::string *)v8;
  v4->_Bx._Buf[v9] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100473F0
// Name: protected: struct std::_Tree_nod<class std::_Tset_traits<struct BreakPoint,struct std::less<struct BreakPoint>,class std::allocator<struct BreakPoint>,0>>::_Node __near * std::_Tree<class std::_Tset_traits<struct BreakPoint,struct std::less<struct BreakPoint>,class std::allocator<struct BreakPoint>,0>>::_Lbound(struct BreakPoint const __near &)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *__usercall std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0>>::_Lbound@<eax>(
        std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *this@<eax>,
        const BreakPoint *_Keyval@<edi>)
{
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Parent; // esi
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v4; // ebx
  int line; // eax
  std::string *p_src; // eax
  const char *Buf; // ecx

  result = this->_Myhead;
  Parent = result->_Parent;
  v4 = result;
  if ( Parent->_Isnil == 0 )
  {
    do
    {
      line = Parent->_Myval._line;
      if ( line < _Keyval->_line )
        goto LABEL_9;
      if ( line != _Keyval->_line )
        goto LABEL_10;
      p_src = &_Keyval->_src;
      if ( _Keyval->_src._Myres >= 0x10 )
        p_src = (std::string *)p_src->_Bx._Ptr;
      Buf = Parent->_Myval._src._Bx._Buf;
      if ( Parent->_Myval._src._Myres >= 0x10 )
        Buf = *(const char **)Buf;
      if ( dbg_less(y: p_src->_Bx._Buf, x: Buf) )
      {
LABEL_9:
        Parent = Parent->_Right;
      }
      else
      {
LABEL_10:
        v4 = Parent;
        Parent = Parent->_Left;
      }
    }
    while ( Parent->_Isnil == 0 );
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10047450
// Name: public: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>> std::_Tree<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>>,class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > **__userpurge std::_Tree<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::erase@<eax>(
        std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *this@<ecx>,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > **a2@<edi>,
        std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *a3@<esi>,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > _First,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > _Last)
{
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Myhead; // eax
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *v7; // ecx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v8; // ecx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v10; // edx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Ptr; // eax
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > v12; // eax
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *i; // eax
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > _Where; // [esp+0h] [ebp-4h] BYREF

  _Where._Ptr = (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)this;
  Myhead = a3->_Myhead;
  v7 = result;
  if ( result == (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *)Myhead->_Left
    && _First._Ptr == Myhead )
  {
    std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0>>::_Erase(
      this: a3,
      _Rootnode: Myhead->_Parent);
    a3->_Myhead->_Parent = a3->_Myhead;
    a3->_Myhead->_Left = a3->_Myhead;
    a3->_Myhead->_Right = a3->_Myhead;
    v8 = a3->_Myhead;
    a3->_Mysize = 0;
    *a2 = (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *)v8->_Left;
    return a2;
  }
  else
  {
    for ( ;
          result != (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *)_First._Ptr;
          v7 = result )
    {
      v10 = (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)v7;
      if ( BYTE1(v7[11]._Ptr) == 0 )
      {
        Ptr = v7[2]._Ptr;
        if ( Ptr->_Isnil != 0 )
        {
          for ( i = v7[1]._Ptr; i->_Isnil == 0; i = i->_Parent )
          {
            if ( v7 != (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *)i->_Right )
              break;
            v7 = (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *)i;
          }
          result = (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *)i;
        }
        else
        {
          v7 = (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *)v7[2]._Ptr;
          for ( v12._Ptr = Ptr->_Left; v12._Ptr->_Isnil == 0; v12._Ptr = v12._Ptr->_Left )
            v7 = (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *)v12._Ptr;
          result = v7;
        }
      }
      std::_Tree<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::erase(
        this: (std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *)v7,
        result: a3,
        (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > >)&_Where,
        _Wherea: v10);
    }
    *a2 = v7;
    return a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047510
// Name: public: void std::vector<char,class std::allocator<char>>::reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<char>::reserve(std::vector<char> *this, unsigned int _Count)
{
  char *v3; // ebx
  int v4; // edi
  std::allocator<char> *v5; // [esp+0h] [ebp-20h] BYREF
  char *_Ptr; // [esp+Ch] [ebp-14h]
  std::allocator<char> **v7; // [esp+10h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-4h]

  v7 = &v5;
  if ( this->_Myend - this->_Myfirst < _Count )
  {
    v3 = std::allocator<char>::allocate(this: v5, _Count);
    _Ptr = v3;
    v8 = 0;
    memmove(dst: (unsigned __int8 *)v3, src: (unsigned __int8 *)this->_Myfirst, count: this->_Mylast - this->_Myfirst);
    v8 = -1;
    v4 = this->_Mylast - this->_Myfirst;
    if ( this->_Myfirst != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->_Myfirst);
    this->_Myend = &v3[_Count];
    this->_Mylast = &v3[v4];
    this->_Myfirst = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100475E0
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::erase(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
std::string *__usercall std::string::erase@<eax>(
        std::string *this@<esi>,
        unsigned int _Off@<ecx>,
        unsigned int _Count@<eax>)
{
  unsigned int Mysize; // eax
  unsigned int v5; // eax
  unsigned int Myres; // edx
  std::string *Ptr; // ebx
  std::string *v8; // edx
  unsigned int v9; // eax
  bool v10; // cf

  Mysize = this->_Mysize;
  if ( Mysize < _Off )
    std::_Xout_of_range(_Message: "invalid string position");
  v5 = Mysize - _Off;
  if ( v5 < _Count )
    _Count = v5;
  if ( _Count != 0 )
  {
    Myres = this->_Myres;
    if ( Myres < 0x10 )
      Ptr = this;
    else
      Ptr = (std::string *)this->_Bx._Ptr;
    if ( Myres < 0x10 )
      v8 = this;
    else
      v8 = (std::string *)this->_Bx._Ptr;
    memmove(
      dst: (unsigned __int8 *)&v8->_Bx._Buf[_Off],
      src: (unsigned __int8 *)&Ptr->_Bx._Buf[_Off + _Count],
      count: v5 - _Count);
    v9 = this->_Mysize - _Count;
    v10 = this->_Myres < 0x10;
    this->_Mysize = v9;
    if ( !v10 )
    {
      this->_Bx._Ptr[v9] = 0;
      return this;
    }
    this->_Bx._Buf[v9] = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10047650
// Name: public: char __near * std::allocator<char>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__usercall std::allocator<char>::allocate@<eax>(unsigned int _Count@<edx>, std::allocator<char> *this)
{
  char *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-10h] BYREF
  char *_What; // [esp+Ch] [ebp-4h] BYREF

  result = nullptr;
  if ( _Count != 0 )
  {
    result = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: _Count);
    if ( result == nullptr )
    {
      _What = nullptr;
      std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
      pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100476A0
// Name: protected: void std::_Tree<class std::_Tset_traits<struct BreakPoint,struct std::less<struct BreakPoint>,class std::allocator<struct BreakPoint>,0>>::_Erase(struct std::_Tree_nod<class std::_Tset_traits<struct BreakPoint,struct std::less<struct BreakPoint>,class std::allocator<struct BreakPoint>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0>>::_Erase(
        std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *this,
        std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *_Rootnode)
{
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v2; // esi
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *i; // edi

  v2 = _Rootnode;
  for ( i = _Rootnode; i->_Isnil == 0; v2 = i )
  {
    std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0>>::_Erase(
      this,
      _Rootnode: i->_Right);
    i = i->_Left;
    if ( v2->_Myval._src._Myres >= 0x10 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2->_Myval._src._Bx._Ptr);
    v2->_Myval._src._Myres = 15;
    v2->_Myval._src._Mysize = 0;
    v2->_Myval._src._Bx._Buf[0] = 0;
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047730
// Name: public: struct std::pair<class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<struct BreakPoint,struct std::less<struct BreakPoint>,class std::allocator<struct BreakPoint>,0>>>,bool> std::_Tree<class std::_Tset_traits<struct BreakPoint,struct std::less<struct BreakPoint>,class std::allocator<struct BreakPoint>,0>>::_Linsert(struct std::_Tree_nod<class std::_Tset_traits<struct BreakPoint,struct std::less<struct BreakPoint>,class std::allocator<struct BreakPoint>,0>>::_Node __near *,bool)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *__userpurge std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0>>::_Linsert@<eax>(
        std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *_Node@<edi>,
        std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *this,
        std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *_Leftish)
{
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v3; // ebx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Parent; // esi
  bool v5; // zf
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Myhead; // edx
  bool v7; // al
  int line; // eax
  int v9; // ecx
  const char *Buf; // eax
  std::string *p_src; // ecx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Ptr; // esi
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *v13; // eax
  int v15; // eax
  int v16; // ecx
  std::string *v17; // eax
  const char *v18; // ecx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *_Addleft; // [esp+8h] [ebp-8h]
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > _Where; // [esp+Ch] [ebp-4h]

  v3 = _Leftish;
  Parent = this->_Myhead->_Parent;
  v5 = Parent->_Isnil == 0;
  Myhead = this->_Myhead;
  v7 = true;
  _Leftish = Myhead;
  LOBYTE(_Addleft) = 1;
  if ( v5 )
  {
    do
    {
      line = _Node->_Myval._line;
      v9 = Parent->_Myval._line;
      _Leftish = Parent;
      if ( line >= v9 )
      {
        if ( line == v9 )
        {
          Buf = Parent->_Myval._src._Bx._Buf;
          if ( Parent->_Myval._src._Myres >= 0x10 )
            Buf = *(const char **)Buf;
          p_src = &_Node->_Myval._src;
          if ( _Node->_Myval._src._Myres >= 0x10 )
            p_src = (std::string *)p_src->_Bx._Ptr;
          v7 = dbg_less(y: Buf, x: p_src->_Bx._Buf);
        }
        else
        {
          v7 = false;
        }
      }
      else
      {
        v7 = true;
      }
      LOBYTE(_Addleft) = v7;
      if ( v7 )
        Parent = Parent->_Left;
      else
        Parent = Parent->_Right;
    }
    while ( Parent->_Isnil == 0 );
    Myhead = _Leftish;
  }
  Ptr = Myhead;
  _Where._Ptr = Myhead;
  if ( v7 )
  {
    if ( Myhead == this->_Myhead->_Left )
    {
      v13 = std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0>>::_Insert(
              this,
              _Addleft: (bool)&this,
              _Wherenode: Myhead,
              _Newnode: (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)1);
LABEL_19:
      v3->_Left = v13->_Ptr;
      LOBYTE(v3->_Parent) = 1;
      return v3;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>,std::_Iterator_base0>::operator--((std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >,std::_Iterator_base0> *)this);
    Ptr = _Where._Ptr;
    Myhead = _Leftish;
  }
  v15 = Ptr->_Myval._line;
  v16 = _Node->_Myval._line;
  if ( v15 < v16 )
  {
LABEL_29:
    v13 = std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0>>::_Insert(
            this,
            _Addleft: (bool)&this,
            _Wherenode: Myhead,
            _Newnode: _Addleft);
    goto LABEL_19;
  }
  if ( v15 == v16 )
  {
    v17 = &_Node->_Myval._src;
    if ( _Node->_Myval._src._Myres >= 0x10 )
      v17 = (std::string *)v17->_Bx._Ptr;
    v18 = Ptr->_Myval._src._Bx._Buf;
    if ( Ptr->_Myval._src._Myres >= 0x10 )
      v18 = *(const char **)v18;
    if ( dbg_less(y: v17->_Bx._Buf, x: v18) )
    {
      Myhead = _Leftish;
      goto LABEL_29;
    }
  }
  if ( _Node->_Myval._src._Myres >= 0x10 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: _Node->_Myval._src._Bx._Ptr);
  _Node->_Myval._src._Myres = 15;
  _Node->_Myval._src._Mysize = 0;
  _Node->_Myval._src._Bx._Buf[0] = 0;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: _Node);
  v3->_Left = Ptr;
  LOBYTE(v3->_Parent) = 0;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10047870
// Name: public: struct std::pair<class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>>,bool> std::_Tree<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>::_Linsert(struct std::_Tree_nod<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>::_Node __near *,bool)
// Source: json
//------------------------------------------------------------------------------
std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> > >,bool> *__userpurge std::_Tree<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::_Linsert@<eax>(
        std::_Tree<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> > *this@<ecx>,
        int a2@<esi>,
        std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *result,
        std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *_Node,
        bool _Leftish)
{
  std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *v5; // edx
  std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *v6; // ebx
  std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *Myhead; // edi
  std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *Parent; // eax
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *v9; // eax
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *_Addleft; // [esp+8h] [ebp-4h]

  v5 = result;
  v6 = _Node;
  Myhead = (std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *)result->_Myhead;
  Parent = Myhead->_Parent;
  LOBYTE(this) = 1;
  LOBYTE(_Addleft) = 1;
  while ( Parent->_Isnil == 0 )
  {
    this = (std::_Tree<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> > *)_Node->_Myval._id;
    Myhead = Parent;
    LOBYTE(this) = (int)this < Parent->_Myval._id;
    LOBYTE(_Addleft) = (_BYTE)this;
    if ( (_BYTE)this != 0 )
      Parent = Parent->_Left;
    else
      Parent = Parent->_Right;
  }
  _Node = Myhead;
  if ( (_BYTE)this != 0 )
  {
    if ( Myhead == (std::_Tree_nod<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> >::_Node *)result->_Myhead->_Left )
    {
      v9 = std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0>>::_Insert(
             this: result,
             _Addleft: (bool)&result,
             _Wherenode: (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)Myhead,
             _Newnode: (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)1);
LABEL_9:
      *(std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *)a2 = (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > >)v9->_Ptr;
      *(_BYTE *)(a2 + 4) = 1;
      return (std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> > >,bool> *)a2;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>,std::_Iterator_base0>::operator--((std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >,std::_Iterator_base0> *)this);
    v5 = result;
  }
  if ( _Node->_Myval._id < v6->_Myval._id )
  {
    v9 = std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0>>::_Insert(
           this: v5,
           _Addleft: (bool)&result,
           _Wherenode: (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)Myhead,
           _Newnode: _Addleft);
    goto LABEL_9;
  }
  if ( v6->_Myval._exp._Myres >= 0x10 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6->_Myval._exp._Bx._Ptr);
  v6->_Myval._exp._Myres = 15;
  v6->_Myval._exp._Mysize = 0;
  v6->_Myval._exp._Bx._Buf[0] = 0;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
  *(_DWORD *)a2 = _Node;
  *(_BYTE *)(a2 + 4) = 0;
  return (std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0> > >,bool> *)a2;
}

//------------------------------------------------------------------------------
// Address: 0x10047950
// Name: protected: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<struct BreakPoint,struct std::less<struct BreakPoint>,class std::allocator<struct BreakPoint>,0>>> std::_Tree<class std::_Tset_traits<struct BreakPoint,struct std::less<struct BreakPoint>,class std::allocator<struct BreakPoint>,0>>::_Insert(bool,struct std::_Tree_nod<class std::_Tset_traits<struct BreakPoint,struct std::less<struct BreakPoint>,class std::allocator<struct BreakPoint>,0>>::_Node __near *,struct std::_Tree_nod<class std::_Tset_traits<struct BreakPoint,struct std::less<struct BreakPoint>,class std::allocator<struct BreakPoint>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *__userpurge std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0>>::_Insert@<eax>(
        std::_Tree<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *this@<eax>,
        std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *_Wherenode@<ecx>,
        std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node **_Addleft,
        std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *_Newnode,
        std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *_Newnodea)
{
  unsigned int Mysize; // edx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v6; // edi
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Myhead; // edx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v8; // edx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v9; // edx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v10; // ecx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Parent; // edx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v12; // esi
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v14; // edx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v15; // esi
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v16; // esi
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v17; // edx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Left; // esi
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v19; // edi
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v20; // edi
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v21; // edi
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v22; // esi
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v23; // edx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v24; // esi
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v25; // esi
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v26; // esi
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v27; // edi
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v28; // edi
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *v29; // ecx

  Mysize = this->_Mysize;
  if ( Mysize >= 0x7FFFFFE )
  {
    if ( _Newnodea->_Myval._src._Myres >= 0x10 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: _Newnodea->_Myval._src._Bx._Ptr);
    _Newnodea->_Myval._src._Myres = 15;
    _Newnodea->_Myval._src._Mysize = 0;
    _Newnodea->_Myval._src._Bx._Buf[0] = 0;
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: _Newnodea);
    std::_Xlength_error(_Message: "map/set<T> too long");
  }
  v6 = _Newnodea;
  this->_Mysize = Mysize + 1;
  _Newnodea->_Parent = _Wherenode;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead )
  {
    Myhead->_Parent = _Newnodea;
    this->_Myhead->_Left = _Newnodea;
    v8 = this->_Myhead;
LABEL_11:
    v8->_Right = _Newnodea;
    goto LABEL_12;
  }
  if ( (_BYTE)_Newnode == 0 )
  {
    _Wherenode->_Right = _Newnodea;
    v8 = this->_Myhead;
    if ( _Wherenode != v8->_Right )
      goto LABEL_12;
    goto LABEL_11;
  }
  _Wherenode->_Left = _Newnodea;
  v9 = this->_Myhead;
  if ( _Wherenode == v9->_Left )
    v9->_Left = _Newnodea;
LABEL_12:
  v10 = _Newnodea;
  while ( v10->_Parent->_Color == 0 )
  {
    Parent = v10->_Parent;
    v12 = Parent->_Parent;
    if ( Parent == v12->_Left )
    {
      Right = v12->_Right;
      if ( Right->_Color != 0 )
      {
        if ( v10 == Parent->_Right )
        {
          v10 = v10->_Parent;
          v14 = Parent->_Right;
          v10->_Right = v14->_Left;
          if ( v14->_Left->_Isnil == 0 )
            v14->_Left->_Parent = v10;
          v14->_Parent = v10->_Parent;
          v15 = this->_Myhead;
          if ( v10 == v15->_Parent )
          {
            v15->_Parent = v14;
          }
          else
          {
            v16 = v10->_Parent;
            if ( v10 == v16->_Left )
              v16->_Left = v14;
            else
              v16->_Right = v14;
          }
          v14->_Left = v10;
          v10->_Parent = v14;
        }
        v10->_Parent->_Color = 1;
        v10->_Parent->_Parent->_Color = 0;
        v17 = v10->_Parent->_Parent;
        Left = v17->_Left;
        v17->_Left = v17->_Left->_Right;
        v19 = Left->_Right;
        if ( v19->_Isnil == 0 )
          v19->_Parent = v17;
        Left->_Parent = v17->_Parent;
        v20 = this->_Myhead;
        if ( v17 == v20->_Parent )
        {
          v20->_Parent = Left;
          Left->_Right = v17;
        }
        else
        {
          v21 = v17->_Parent;
          if ( v17 == v21->_Right )
            v21->_Right = Left;
          else
            v21->_Left = Left;
          Left->_Right = v17;
        }
LABEL_52:
        v6 = _Newnodea;
        v17->_Parent = Left;
        continue;
      }
      Parent->_Color = 1;
      Right->_Color = 1;
      v10->_Parent->_Parent->_Color = 0;
      v10 = v10->_Parent->_Parent;
    }
    else
    {
      v22 = v12->_Left;
      if ( v22->_Color != 0 )
      {
        if ( v10 == Parent->_Left )
        {
          v10 = v10->_Parent;
          v23 = Parent->_Left;
          v10->_Left = v23->_Right;
          v24 = v23->_Right;
          if ( v24->_Isnil == 0 )
            v24->_Parent = v10;
          v23->_Parent = v10->_Parent;
          v25 = this->_Myhead;
          if ( v10 == v25->_Parent )
          {
            v25->_Parent = v23;
          }
          else
          {
            v26 = v10->_Parent;
            if ( v10 == v26->_Right )
              v26->_Right = v23;
            else
              v26->_Left = v23;
          }
          v23->_Right = v10;
          v10->_Parent = v23;
        }
        v10->_Parent->_Color = 1;
        v10->_Parent->_Parent->_Color = 0;
        v17 = v10->_Parent->_Parent;
        Left = v17->_Right;
        v17->_Right = Left->_Left;
        if ( Left->_Left->_Isnil == 0 )
          Left->_Left->_Parent = v17;
        Left->_Parent = v17->_Parent;
        v27 = this->_Myhead;
        if ( v17 == v27->_Parent )
        {
          v27->_Parent = Left;
        }
        else
        {
          v28 = v17->_Parent;
          if ( v17 == v28->_Left )
            v28->_Left = Left;
          else
            v28->_Right = Left;
        }
        Left->_Left = v17;
        goto LABEL_52;
      }
      Parent->_Color = 1;
      v22->_Color = 1;
      v10->_Parent->_Parent->_Color = 0;
      v10 = v10->_Parent->_Parent;
    }
  }
  v29 = this->_Myhead->_Parent;
  *_Addleft = v6;
  v29->_Color = 1;
  return (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > > *)_Addleft;
}

//------------------------------------------------------------------------------
// Address: 0x10047BA0
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>,struct std::_Iterator_base0>::operator--(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >,std::_Iterator_base0> *__usercall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>,std::_Iterator_base0>::operator--@<eax>(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >,std::_Iterator_base0> *this@<ecx>,
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >,std::_Iterator_base0> *result@<eax>)
{
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Ptr; // ecx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *Left; // edx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *j; // ecx
  std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *i; // ecx

  Ptr = result->_Ptr;
  if ( result->_Ptr->_Isnil != 0 )
  {
    result->_Ptr = Ptr->_Right;
  }
  else
  {
    Left = Ptr->_Left;
    if ( Ptr->_Left->_Isnil != 0 )
    {
      for ( i = Ptr->_Parent; i->_Isnil == 0; i = i->_Parent )
      {
        if ( result->_Ptr != i->_Left )
          break;
        result->_Ptr = i;
      }
      if ( result->_Ptr->_Isnil == 0 )
        result->_Ptr = i;
    }
    else
    {
      for ( j = Left->_Right; j->_Isnil == 0; j = j->_Right )
        Left = j;
      result->_Ptr = Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10047C00
// Name: public: struct std::_Tree_nod<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>::_Node __near * std::_Tree_val<class std::_Tset_traits<struct Watch,struct std::less<struct Watch>,class std::allocator<struct Watch>,0>>::_Buynode<struct Watch __near &>(struct Watch __near &)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *__thiscall std::_Tree_val<std::_Tset_traits<Watch,std::less<Watch>,std::allocator<Watch>,0>>::_Buynode<Watch &>(
        std::_Tree_val<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> > *this,
        BreakPoint *_Val)
{
  BreakPoint *v2; // ebx
  char *v4; // eax
  char *v5; // esi
  int *v6; // eax
  std::string *v7; // edi
  char *Ptr; // ecx
  int v10; // [esp+0h] [ebp-28h] BYREF
  std::exception pExceptionObject; // [esp+Ch] [ebp-1Ch] BYREF
  int *v12; // [esp+18h] [ebp-10h]
  int v13; // [esp+24h] [ebp-4h]

  v12 = &v10;
  v2 = _Val;
  v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 48);
  v5 = v4;
  _Val = (BreakPoint *)v4;
  if ( v4 == nullptr )
  {
    _Val = nullptr;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Val);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  *(_DWORD *)v4 = this->_Myhead;
  *((_DWORD *)v4 + 1) = this->_Myhead;
  *((_DWORD *)v4 + 2) = this->_Myhead;
  *((_WORD *)v4 + 22) = 0;
  v13 = 0;
  v6 = (int *)(v4 + 12);
  if ( v5 != (char *)-12 )
  {
    v7 = (std::string *)(v5 + 16);
    *((_DWORD *)v5 + 9) = 15;
    *((_DWORD *)v5 + 8) = 0;
    if ( *((_DWORD *)v5 + 9) < 0x10u )
      Ptr = (char *)(v6 + 1);
    else
      Ptr = v7->_Bx._Ptr;
    *Ptr = 0;
    *v6 = v2->_line;
    std::string::assign(this: v7, _Count: 0xFFFFFFFF, _Right: &v2->_src, _Roff: 0);
  }
  v13 = -1;
  return (std::_Tree_nod<std::_Tset_traits<BreakPoint,std::less<BreakPoint>,std::allocator<BreakPoint>,0> >::_Node *)v5;
}
